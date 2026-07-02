const Chat = require('../models/Chat');
const userServiceClient = require('./userServiceClient');
const redis = require('../config/redis');
const amqp = require('amqplib');

class ChatService {
  async createDirectChat(userId1, userId2) {
    // Aynı iki kullanıcı arasında mevcut sohbet var mı kontrol et
    const existingChat = await Chat.findOne({
      type: 'DIRECT',
      participants: {
        $all: [
          { $elemMatch: { userId: userId1 } },
          { $elemMatch: { userId: userId2 } }
        ]
      }
    });

    if (existingChat) {
      return existingChat;
    }

    // Kullanıcıların var olup olmadığını kontrol et
    const usersExist = await userServiceClient.verifyUsers([userId1, userId2]);
    if (!usersExist) {
      throw new Error('One or more users not found');
    }

    // Yeni sohbet oluştur
    const chat = new Chat({
      type: 'DIRECT',
      createdBy: userId1,
      participants: [
        { userId: userId1, role: 'MEMBER' },
        { userId: userId2, role: 'MEMBER' },
      ],
    });

    const savedChat = await chat.save();
    
    // Cache'i temizle
    await redis.del(`chats:user:${userId1}`);
    await redis.del(`chats:user:${userId2}`);

    // RabbitMQ'ya bildirim gönder
    await this.publishChatCreatedEvent(savedChat, [String(userId1), String(userId2)]);

    return savedChat;
  }

  async createGroupChat(name, creatorId, participantIds) {
    // Kullanıcıların var olup olmadığını kontrol et
    const allUserIds = [creatorId, ...participantIds];
    const usersExist = await userServiceClient.verifyUsers(allUserIds);
    if (!usersExist) {
      throw new Error('One or more users not found');
    }

    // Tüm katılımcıları ekle
    const participants = [
      { userId: creatorId, role: 'ADMIN' },
      ...participantIds.map(userId => ({ userId, role: 'MEMBER' })),
    ];

    const chat = new Chat({
      type: 'GROUP',
      name,
      createdBy: creatorId,
      participants,
    });

    const savedChat = await chat.save();
    
    // Cache'i temizle
    await this.clearChatCacheForUsers(allUserIds);

    // RabbitMQ'ya bildirim gönder
    await this.publishChatCreatedEvent(savedChat, participantIds);

    return savedChat;
  }

  async getUserChats(userId) {
    // Cache'den kontrol et
    const cacheKey = `chats:user:${userId}`;
    const cached = await redis.get(cacheKey);
    if (cached) {
      return JSON.parse(cached);
    }

    // Veritabanından al
    const chats = await Chat.find({
      'participants.userId': userId,
    }).sort({ updatedAt: -1 });

    // Chatleri kullanıcı bilgileriyle zenginleştir
    const enrichedChats = await Promise.all(chats.map(async (chat) => {
      const chatObj = chat.toObject();
      
      // Katılımcı bilgilerini çek
      const participantsWithDetails = await Promise.all(chatObj.participants.map(async (p) => {
        try {
          // Kendi servisimizden kullanıcıyı çekiyoruz
          // Not: Performans için ilerde toplu çekme (batch) eklenebilir
          const user = await userServiceClient.getUser(p.userId);
          return { ...p, user };
        } catch (e) {
          console.error(`Failed to fetch user details for ${p.userId}`, e);
          return { ...p, user: { username: 'Unknown User' } };
        }
      }));
      
      chatObj.participants = participantsWithDetails;
      
      // Eğer DIRECT chat ise, sohbetin ismini "karşı tarafın ismi" yap
      if (chatObj.type === 'DIRECT') {
        const otherParticipant = participantsWithDetails.find(p => p.userId !== userId);
        if (otherParticipant && otherParticipant.user) {
           // Öncelik: İsim Soyisim > Username > Unknown
           const displayName = (otherParticipant.user.first_name && otherParticipant.user.last_name) 
              ? `${otherParticipant.user.first_name} ${otherParticipant.user.last_name}`
              : (otherParticipant.user.username || 'Unknown User');
              
           chatObj.name = displayName;
           
           // Frontend'in avatar gösterebilmesi için avatar bilgisini de chat objesine ekleyebiliriz
           chatObj.avatar = otherParticipant.user.profile_picture;
        }
      }

      return chatObj;
    }));

    // Cache'le (5 dakika - kullanıcı bilgileri değişebileceği için süreyi kısalttık)
    await redis.setEx(cacheKey, 300, JSON.stringify(enrichedChats));

    return enrichedChats;
  }

  async getChatById(chatId, userId, skipAuthCheck = false) {
    const chat = await Chat.findById(chatId);
    if (!chat) {
      throw new Error('Chat not found');
    }

    // Service call ise auth kontrolü yapma
    if (!skipAuthCheck && userId) {
      // Kullanıcının sohbette olup olmadığını kontrol et
      const isParticipant = chat.participants.some(p => p.userId === userId);
      if (!isParticipant) {
        throw new Error('User is not a participant of this chat');
      }
    }

    return chat;
  }

  async addParticipant(chatId, userId, addedBy) {
    const chat = await Chat.findById(chatId);
    if (!chat) {
      throw new Error('Chat not found');
    }

    // Sadece grup sohbetlerine katılımcı eklenebilir
    if (chat.type !== 'GROUP') {
      throw new Error('Can only add participants to group chats');
    }

    // Kullanıcının var olup olmadığını kontrol et
    const userExists = await userServiceClient.verifyUsers([userId]);
    if (!userExists) {
      throw new Error('User not found');
    }

    // Katılımcı zaten ekli mi kontrol et
    const isAlreadyParticipant = chat.participants.some(p => p.userId === userId);
    if (isAlreadyParticipant) {
      return chat;
    }

    chat.participants.push({ userId, role: 'MEMBER' });
    const savedChat = await chat.save();

    // Cache'i temizle
    await this.clearChatCacheForUsers([userId, ...chat.participants.map(p => p.userId)]);

    return savedChat;
  }

  async removeParticipant(chatId, userId, removedBy) {
    const chat = await Chat.findById(chatId);
    if (!chat) {
      throw new Error('Chat not found');
    }

    // Sadece grup sohbetlerinden katılımcı çıkarılabilir
    if (chat.type !== 'GROUP') {
      throw new Error('Can only remove participants from group chats');
    }

    // Sadece ADMIN katılımcı silebilir
    const isAdmin = chat.participants.some(
      (p) => String(p.userId) === String(removedBy) && p.role === 'ADMIN'
    );
    if (!isAdmin) {
      throw new Error('Only admins can remove participants');
    }

    // Katılımcıyı çıkar
    chat.participants = chat.participants.filter(p => String(p.userId) !== String(userId));
    
    // Eğer katılımcı kalmadıysa sohbeti sil
    if (chat.participants.length === 0) {
      await Chat.findByIdAndDelete(chatId);
      return null;
    }

    const savedChat = await chat.save();

    // Cache'i temizle
    await this.clearChatCacheForUsers([String(userId), ...chat.participants.map(p => String(p.userId))]);

    return savedChat;
  }

  async leaveGroupChat(chatId, userId) {
    const chat = await Chat.findById(chatId);
    if (!chat) {
      throw new Error('Chat not found');
    }

    if (chat.type !== 'GROUP') {
      throw new Error('Can only leave group chats');
    }

    const isParticipant = chat.participants.some(p => String(p.userId) === String(userId));
    if (!isParticipant) {
      throw new Error('You are not a participant of this chat');
    }

    const allParticipantIdsBefore = chat.participants.map(p => String(p.userId));
    const chatType = chat.type;

    chat.participants = chat.participants.filter(p => String(p.userId) !== String(userId));

    // Eğer katılımcı kalmadıysa sohbeti sil
    if (chat.participants.length === 0) {
      await Chat.findByIdAndDelete(chatId);
      await this.clearChatCacheForUsers(allParticipantIdsBefore);
      await this.publishChatDeletedEvent(chatId, allParticipantIdsBefore, chatType, chat.name);
      return { deleted: true };
    }

    await chat.save();
    const remainingIds = chat.participants.map(p => String(p.userId));
    await this.clearChatCacheForUsers([String(userId), ...remainingIds]);
    await this.publishChatLeftEvent(chatId, String(userId), remainingIds, chatType);
    return { deleted: false };
  }

  async deleteChat(chatId, userId) {
    const chat = await Chat.findById(chatId);
    if (!chat) {
      throw new Error('Chat not found');
    }

    // Kullanıcının sohbette olup olmadığını kontrol et (string karşılaştırması)
    const isParticipant = chat.participants.some(p => String(p.userId) === String(userId));
    if (!isParticipant) {
      throw new Error('You are not a participant of this chat');
    }

    // Tüm katılımcıların ID'lerini sakla (cache temizleme ve event için)
    const allParticipantIds = chat.participants.map(p => String(p.userId));
    const chatType = chat.type;
    const chatName = chat.name;

    // DIRECT chat: Kullanıcıyı participants'tan çıkar, eğer tek kişi kalırsa chat'i sil
    let chatDeleted = false;
    if (chat.type === 'DIRECT') {
      chat.participants = chat.participants.filter(p => String(p.userId) !== String(userId));
      
      // Eğer katılımcı kalmadıysa sohbeti sil
      if (chat.participants.length === 0) {
        await Chat.findByIdAndDelete(chatId);
        chatDeleted = true;
      } else {
        await chat.save();
      }
    } else {
      // GROUP chat: Sadece admin silebilir veya creator silebilir
      const isAdmin = chat.participants.some(p => String(p.userId) === String(userId) && p.role === 'ADMIN');
      const isCreator = String(chat.createdBy) === String(userId);
      
      if (!isAdmin && !isCreator) {
        throw new Error('Only admins or creator can delete group chats');
      }

      // GROUP chat'i tamamen sil
      await Chat.findByIdAndDelete(chatId);
      chatDeleted = true;
    }

    // Cache'i temizle (tüm katılımcılar için)
    await this.clearChatCacheForUsers(allParticipantIds);

    // RabbitMQ'ya chat deleted event'i publish et
    if (chatDeleted) {
      await this.publishChatDeletedEvent(chatId, allParticipantIds, chatType, chatName);
    } else {
      // DIRECT chat'ten çıkıldı ama chat silinmedi (diğer kullanıcı hala var)
      await this.publishChatLeftEvent(chatId, String(userId), allParticipantIds.filter(id => id !== String(userId)), chatType);
    }

    return true;
  }

  async clearChatCacheForUsers(userIds) {
    const promises = userIds.map(userId => redis.del(`chats:user:${userId}`));
    await Promise.all(promises);
  }

  async publishChatCreatedEvent(chat, participantIds) {
    try {
      const connection = await amqp.connect(process.env.RABBITMQ_URL || 'amqp://localhost:5672');
      const channel = await connection.createChannel();
      
      const exchange = 'chat.exchange';
      await channel.assertExchange(exchange, 'topic', { durable: true });

      const message = {
        event: 'chat.created',
        timestamp: new Date().toISOString(),
        data: {
          chatId: chat._id.toString(),
          type: chat.type,
          name: chat.name,
          createdBy: chat.createdBy,
          participantIds,
        },
      };

      channel.publish(exchange, 'chat.created', Buffer.from(JSON.stringify(message)), {
        persistent: true,
      });

      await channel.close();
      await connection.close();
    } catch (error) {
      console.error('Error publishing chat created event:', error);
      // Event publishing hatası kritik değil, log'la devam et
    }
  }

  async publishChatDeletedEvent(chatId, participantIds, chatType, chatName) {
    try {
      const connection = await amqp.connect(process.env.RABBITMQ_URL || 'amqp://localhost:5672');
      const channel = await connection.createChannel();
      
      const exchange = 'chat.exchange';
      await channel.assertExchange(exchange, 'topic', { durable: true });

      const message = {
        event: 'chat.deleted',
        timestamp: new Date().toISOString(),
        data: {
          chatId: chatId.toString(),
          type: chatType,
          name: chatName,
          participantIds,
        },
      };

      channel.publish(exchange, 'chat.deleted', Buffer.from(JSON.stringify(message)), {
        persistent: true,
      });

      await channel.close();
      await connection.close();
    } catch (error) {
      console.error('Error publishing chat deleted event:', error);
    }
  }

  async publishChatLeftEvent(chatId, leftUserId, remainingParticipantIds, chatType) {
    try {
      const connection = await amqp.connect(process.env.RABBITMQ_URL || 'amqp://localhost:5672');
      const channel = await connection.createChannel();
      
      const exchange = 'chat.exchange';
      await channel.assertExchange(exchange, 'topic', { durable: true });

      const message = {
        event: 'chat.left',
        timestamp: new Date().toISOString(),
        data: {
          chatId: chatId.toString(),
          type: chatType,
          leftUserId,
          remainingParticipantIds,
        },
      };

      channel.publish(exchange, 'chat.left', Buffer.from(JSON.stringify(message)), {
        persistent: true,
      });

      await channel.close();
      await connection.close();
    } catch (error) {
      console.error('Error publishing chat left event:', error);
    }
  }
}

module.exports = new ChatService();

