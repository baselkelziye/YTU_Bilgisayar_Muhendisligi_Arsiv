const Message = require('../models/Message');
const redis = require('../config/redis');
const amqp = require('amqplib');
const axios = require('axios');
const userServiceClient = require('./userServiceClient');

const NOTIFICATION_SERVICE_URL = process.env.NOTIFICATION_SERVICE_URL || 'http://localhost:3004';

class MessageService {
  async sendMessage(chatId, senderId, content, messageType = 'TEXT', fileUrl = null) {
    console.log(`📨 Creating message for chat ${chatId}, sender ${senderId}`);
    
    // Mesaj oluştur
    const message = new Message({
      chatId,
      senderId,
      content,
      messageType,
      fileUrl,
      status: 'SENT',
    });

    const savedMessage = await message.save();
    console.log(`✅ Message saved with ID: ${savedMessage._id}`);

    // Sender bilgisini ekle
    let sender = null;
    try {
      sender = await userServiceClient.getUser(senderId);
    } catch (error) {
      console.error(`Failed to fetch sender for ${senderId}:`, error.message);
    }

    const messageObj = savedMessage.toObject();
    if (sender) {
      messageObj.sender = sender;
    }

    // Cache'i temizle
    await this.clearMessageCacheForChat(chatId);

    // RabbitMQ'ya event publish et
    console.log(`📤 Publishing message created event for message ${savedMessage._id}`);
    await this.publishMessageCreatedEvent(savedMessage);
    console.log(`✅ Event published successfully`);

    return messageObj;
  }

  async getMessages(chatId, page = 1, limit = 50) {
    const cacheKey = `messages:chat:${chatId}:page:${page}:limit:${limit}`;
    
    // Cache'den kontrol et
    const cached = await redis.get(cacheKey);
    if (cached) {
      return JSON.parse(cached);
    }

    // Veritabanından al
    const skip = (page - 1) * limit;
    const messages = await Message.find({
      chatId,
      deleted: false,
    })
      .sort({ createdAt: -1 })
      .skip(skip)
      .limit(limit)
      .lean();

    // Tarih sırasına göre ters çevir (en eskiden yeniye)
    messages.reverse();

    // Sender bilgilerini populate et
    // Performans için: benzersiz senderId'leri topla ve batch fetch yapabiliriz
    // Şimdilik basit yaklaşım: her mesaj için ayrı fetch (ileride optimize edilebilir)
    const enrichedMessages = await Promise.all(messages.map(async (msg) => {
      try {
        const sender = await userServiceClient.getUser(msg.senderId);
        return { ...msg, sender };
      } catch (error) {
        console.error(`Failed to fetch sender for ${msg.senderId}:`, error.message);
        return { ...msg, sender: null };
      }
    }));

    // Cache'le (15 dakika) - sender bilgileri de cache'leniyor
    await redis.setEx(cacheKey, 900, JSON.stringify(enrichedMessages));

    return enrichedMessages;
  }

  async deleteMessage(messageId, userId) {
    const message = await Message.findById(messageId);
    if (!message) {
      throw new Error('Message not found');
    }

    // Sadece mesaj gönderen silebilir
    if (message.senderId !== userId) {
      throw new Error('You can only delete your own messages');
    }

    // Soft delete
    message.deleted = true;
    message.status = 'DELETED';
    await message.save();

    // Sender bilgisini ekle
    let sender = null;
    try {
      sender = await userServiceClient.getUser(message.senderId);
    } catch (error) {
      console.error(`Failed to fetch sender for ${message.senderId}:`, error.message);
    }

    const messageObj = message.toObject();
    if (sender) {
      messageObj.sender = sender;
    }

    // Cache'i temizle
    await redis.del(`messages:chat:${message.chatId}`);
    await this.clearMessageCacheForChat(message.chatId);

    return messageObj;
  }

  async updateMessageStatus(messageId, status) {
    const message = await Message.findById(messageId);
    if (!message) {
      throw new Error('Message not found');
    }

    message.status = status;
    await message.save();

    return message;
  }

  async updateMessage(messageId, userId, content) {
    const message = await Message.findById(messageId);
    if (!message) {
      throw new Error('Message not found');
    }

    if (message.senderId !== userId) {
      throw new Error('You can only edit your own messages');
    }

    if (message.deleted) {
      throw new Error('Cannot edit a deleted message');
    }

    message.content = content;
    await message.save();

    // Sender bilgisini ekle
    let sender = null;
    try {
      sender = await userServiceClient.getUser(message.senderId);
    } catch (error) {
      console.error(`Failed to fetch sender for ${message.senderId}:`, error.message);
    }

    const messageObj = message.toObject();
    if (sender) {
      messageObj.sender = sender;
    }

    // Cache'i temizle
    await redis.del(`messages:chat:${message.chatId}`);
    await this.clearMessageCacheForChat(message.chatId);

    return messageObj;
  }

  async clearMessageCacheForChat(chatId) {
    // Tüm sayfa cache'lerini temizle (basit yaklaşım)
    const keys = await redis.keys(`messages:chat:${chatId}:*`);
    if (keys.length > 0) {
      await redis.del(keys);
    }
  }

  async publishMessageCreatedEvent(message) {
    try {
      const rabbitmqUrl = process.env.RABBITMQ_URL || 'amqp://localhost:5672';
      console.log(`🔗 Connecting to RabbitMQ at ${rabbitmqUrl}`);
      
      const connection = await amqp.connect(rabbitmqUrl);
      const channel = await connection.createChannel();
      
      const exchange = 'message.exchange';
      await channel.assertExchange(exchange, 'topic', { durable: true });
      console.log(`✅ Exchange '${exchange}' asserted`);

      const eventMessage = {
        event: 'message.created',
        timestamp: new Date().toISOString(),
        data: {
          messageId: message._id.toString(),
          chatId: message.chatId,
          senderId: message.senderId,
          content: message.content,
          messageType: message.messageType,
          fileUrl: message.fileUrl,
          status: message.status,
          createdAt: message.createdAt ? message.createdAt.toISOString() : new Date().toISOString(),
          updatedAt: message.updatedAt ? message.updatedAt.toISOString() : new Date().toISOString(),
        },
      };

      console.log(`📤 Publishing event:`, JSON.stringify(eventMessage, null, 2));
      
      const published = channel.publish(exchange, 'message.created', Buffer.from(JSON.stringify(eventMessage)), {
        persistent: true,
      });
      
      console.log(`📨 Event published: ${published}`);

      await channel.close();
      await connection.close();
      console.log(`✅ RabbitMQ connection closed`);
    } catch (error) {
      console.error('❌ Error publishing message created event:', error);
      console.error('Error stack:', error.stack);
      // Event publishing hatası kritik değil, log'la devam et
    }
  }
}

module.exports = new MessageService();

