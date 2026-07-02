const amqp = require('amqplib');
const notificationService = require('./notificationService');
const axios = require('axios');

const CHAT_SERVICE_URL = process.env.CHAT_SERVICE_URL || 'http://chat-service:3002';
const USER_SERVICE_URL = process.env.USER_SERVICE_URL || 'http://user-service:3001';
const WEBSOCKET_GATEWAY_URL = process.env.WEBSOCKET_GATEWAY_URL || 'http://localhost:3006';
const SERVICE_TOKEN = process.env.SERVICE_TOKEN || 'dev-service-token-change-in-production';

class EventConsumer {
  async start() {
    try {
      const connection = await amqp.connect(process.env.RABBITMQ_URL || 'amqp://localhost:5672');
      const channel = await connection.createChannel();

      // Exchange'leri oluştur
      await channel.assertExchange('message.exchange', 'topic', { durable: true });
      await channel.assertExchange('chat.exchange', 'topic', { durable: true });

      // Queue'ları oluştur
      const messageQueue = await channel.assertQueue('message.created.queue', { durable: true });
      const chatCreatedQueue = await channel.assertQueue('chat.created.queue', { durable: true });
      const chatDeletedQueue = await channel.assertQueue('chat.deleted.queue', { durable: true });
      const chatLeftQueue = await channel.assertQueue('chat.left.queue', { durable: true });

      // Binding'leri yap
      await channel.bindQueue(messageQueue.queue, 'message.exchange', 'message.created');
      await channel.bindQueue(chatCreatedQueue.queue, 'chat.exchange', 'chat.created');
      await channel.bindQueue(chatDeletedQueue.queue, 'chat.exchange', 'chat.deleted');
      await channel.bindQueue(chatLeftQueue.queue, 'chat.exchange', 'chat.left');

      // Mesaj consumer
      channel.consume(messageQueue.queue, async (msg) => {
        if (msg) {
          try {
            const eventData = JSON.parse(msg.content.toString());
            console.log('📨 Message created event received:', JSON.stringify(eventData, null, 2));
            await this.handleMessageCreatedEvent(eventData);
            channel.ack(msg);
          } catch (error) {
            console.error('Error processing message created event:', error);
            channel.nack(msg, false, false); // Dead letter queue'ya gönder
          }
        }
      });

      // Chat created consumer
      channel.consume(chatCreatedQueue.queue, async (msg) => {
        if (msg) {
          try {
            const eventData = JSON.parse(msg.content.toString());
            await this.handleChatCreatedEvent(eventData);
            channel.ack(msg);
          } catch (error) {
            console.error('Error processing chat created event:', error);
            channel.nack(msg, false, false);
          }
        }
      });

      // Chat deleted consumer
      channel.consume(chatDeletedQueue.queue, async (msg) => {
        if (msg) {
          try {
            const eventData = JSON.parse(msg.content.toString());
            await this.handleChatDeletedEvent(eventData);
            channel.ack(msg);
          } catch (error) {
            console.error('Error processing chat deleted event:', error);
            channel.nack(msg, false, false);
          }
        }
      });

      // Chat left consumer
      channel.consume(chatLeftQueue.queue, async (msg) => {
        if (msg) {
          try {
            const eventData = JSON.parse(msg.content.toString());
            await this.handleChatLeftEvent(eventData);
            channel.ack(msg);
          } catch (error) {
            console.error('Error processing chat left event:', error);
            channel.nack(msg, false, false);
          }
        }
      });

      console.log('✅ Event consumers started successfully');
      console.log('📡 Listening for events on:');
      console.log('  - Exchange: message.exchange, Routing Key: message.created');
      console.log('  - Exchange: chat.exchange, Routing Key: chat.created');
    } catch (error) {
      console.error('❌ Error starting event consumers:', error);
      console.error('Error stack:', error.stack);
      // Retry logic burada eklenebilir
    }
  }

  async handleMessageCreatedEvent(eventData) {
    const { data } = eventData;
    const { messageId, chatId, senderId, content, messageType, fileUrl, status, createdAt } = data;

    console.log(`🔔 Handling message created event for chat ${chatId}, sender ${senderId}`);

    // Sohbet katılımcılarını al
    try {
      // Chat Service'e internal call - service token ile
      const SERVICE_TOKEN = process.env.SERVICE_TOKEN || 'dev-service-token-change-in-production';
      const chatResponse = await axios.get(`${CHAT_SERVICE_URL}/api/chats/${chatId}`, {
        headers: {
          'X-Service-Token': SERVICE_TOKEN,
        },
      });

      if (!chatResponse.data.success) {
        console.error('Chat service returned error:', chatResponse.data.message);
        return;
      }

      const chat = chatResponse.data.data;
      if (!chat || !chat.participants) {
        console.error('Invalid chat data received:', chat);
        return;
      }

      const participants = chat.participants.map(p => String(p.userId)).filter(id => String(id) !== String(senderId));

      console.log(`📤 Sending notifications to ${participants.length} participants:`, participants);

      // Sender bilgisini al
      let sender = null;
      try {
        const senderResponse = await axios.get(`${USER_SERVICE_URL}/api/users/${senderId}`, {
          headers: {
            'X-Service-Token': SERVICE_TOKEN,
          },
        });
        if (senderResponse.data.success) {
          sender = senderResponse.data.data.user;
        }
      } catch (senderError) {
        console.error('Failed to fetch sender info:', senderError.message);
      }

      // Mesaj verisi için tam obje
      const messageData = {
        _id: messageId,
        chatId,
        senderId,
        content,
        messageType,
        fileUrl,
        status,
        createdAt: createdAt || new Date().toISOString(),
        updatedAt: createdAt || new Date().toISOString(),
        sender: sender || null,
      };

      // WebSocket üzerinden tüm katılımcılara mesaj event'i gönder (sender dahil)
      const allParticipants = [String(senderId), ...participants];
      try {
        await axios.post(`${WEBSOCKET_GATEWAY_URL}/api/messages/broadcast`, {
          userIds: allParticipants,
          event: 'message.created',
          data: {
            message: messageData,
            chatId,
          },
        });
        console.log(`✅ Message event broadcasted to ${allParticipants.length} users`);
      } catch (wsError) {
        console.error('❌ Failed to broadcast message event:', wsError.message);
      }

      // Her katılımcıya bildirim gönder - mesajın tam verisiyle
      for (const participantId of participants) {
        try {
          const notificationData = {
            messageId,
            chatId,
            senderId,
            messageType,
            content,
            fileUrl,
            status,
            createdAt,
            message: messageData,
          };
          
          console.log(`📨 Sending notification to user ${participantId}:`, JSON.stringify(notificationData, null, 2));
          
          await notificationService.sendNotification(
            participantId,
            'MESSAGE',
            'New Message',
            content ? content.substring(0, 100) : 'You have a new message',
            notificationData
          );
          console.log(`✅ Notification sent to user ${participantId} for message ${messageId}`);
        } catch (notifError) {
          console.error(`❌ Failed to send notification to user ${participantId}:`, notifError);
        }
      }
    } catch (error) {
      console.error('Error handling message created event:', error);
      if (error.response) {
        console.error('Response status:', error.response.status);
        console.error('Response data:', error.response.data);
      }
    }
  }

  async handleChatCreatedEvent(eventData) {
    const { data } = eventData;
    const { chatId, createdBy, participantIds, name, type } = data;

    console.log(`🔔 Handling chat created event for chat ${chatId}, created by ${createdBy}`);

    // Tüm katılımcılara chat event'i gönder (oluşturucu dahil)
    const allParticipants = [createdBy, ...participantIds].map(String);

    // WebSocket üzerinden tüm katılımcılara chat event'i gönder
    try {
      await axios.post(`${WEBSOCKET_GATEWAY_URL}/api/chats/broadcast`, {
        userIds: allParticipants,
        event: 'chat.created',
        data: {
          chatId,
          createdBy,
          name,
          type,
          participantIds,
        },
      });
      console.log(`✅ Chat event broadcasted to ${allParticipants.length} users`);
    } catch (wsError) {
      console.error('❌ Failed to broadcast chat event:', wsError.message);
    }

    // Katılımcılara bildirim gönder (oluşturucu hariç)
    const recipients = participantIds.filter(id => String(id) !== String(createdBy));

    for (const participantId of recipients) {
      try {
        await notificationService.sendNotification(
          participantId,
          'CHAT_INVITE',
          'Chat Invitation',
          `You have been added to ${name || 'a chat'}`,
          {
            chatId,
            createdBy,
          }
        );
        console.log(`✅ Chat invite notification sent to user ${participantId}`);
      } catch (notifError) {
        console.error(`❌ Failed to send chat invite notification to user ${participantId}:`, notifError);
      }
    }
  }

  async handleChatDeletedEvent(eventData) {
    const { data } = eventData;
    const { chatId, participantIds, type, name } = data;

    console.log(`🔔 Handling chat deleted event for chat ${chatId}`);

    // WebSocket üzerinden tüm katılımcılara chat deleted event'i gönder
    try {
      await axios.post(`${WEBSOCKET_GATEWAY_URL}/api/chats/broadcast`, {
        userIds: participantIds.map(String),
        event: 'chat.deleted',
        data: {
          chatId,
          type,
          name,
        },
      });
      console.log(`✅ Chat deleted event broadcasted to ${participantIds.length} users`);
    } catch (wsError) {
      console.error('❌ Failed to broadcast chat deleted event:', wsError.message);
    }
  }

  async handleChatLeftEvent(eventData) {
    const { data } = eventData;
    const { chatId, leftUserId, remainingParticipantIds, type } = data;

    console.log(`🔔 Handling chat left event for chat ${chatId}, user ${leftUserId} left`);

    // WebSocket üzerinden kalan katılımcılara chat updated event'i gönder
    const allParticipants = [String(leftUserId), ...remainingParticipantIds.map(String)];
    try {
      await axios.post(`${WEBSOCKET_GATEWAY_URL}/api/chats/broadcast`, {
        userIds: allParticipants,
        event: 'chat.left',
        data: {
          chatId,
          leftUserId,
          type,
        },
      });
      console.log(`✅ Chat left event broadcasted to ${allParticipants.length} users`);
    } catch (wsError) {
      console.error('❌ Failed to broadcast chat left event:', wsError.message);
    }
  }
}

module.exports = new EventConsumer();

