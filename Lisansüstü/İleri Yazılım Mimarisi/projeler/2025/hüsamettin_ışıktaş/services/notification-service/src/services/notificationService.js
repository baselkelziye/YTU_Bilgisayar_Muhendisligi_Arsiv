const Notification = require('../models/Notification');
const redis = require('../config/redis');
const axios = require('axios');

const WEBSOCKET_GATEWAY_URL = process.env.WEBSOCKET_GATEWAY_URL || 'http://localhost:3006';

class NotificationService {
  async sendNotification(userId, type, title, body, data = {}) {
    console.log(`📨 Creating notification for user ${userId}, type: ${type}`);
    
    // Bildirim oluştur
    const notification = new Notification({
      userId,
      type,
      title,
      body,
      data,
      read: false,
    });

    const savedNotification = await notification.save();
    console.log(`✅ Notification saved with ID: ${savedNotification._id}`);

    // Kullanıcı çevrimiçi mi kontrol et
    const isOnline = await this.isUserOnline(userId);
    console.log(`👤 User ${userId} online status: ${isOnline}`);
    
    if (isOnline) {
      // Gerçek zamanlı bildirim gönder
      console.log(`🔄 Sending realtime notification to online user ${userId}`);
      await this.sendRealtimeNotification(userId, savedNotification);
    } else {
      console.log(`⏸️ User ${userId} is offline, notification saved to database`);
      // Çevrimdışı kullanıcı için bildirim zaten veritabanında saklanmış
      // Kullanıcı çevrimiçi olduğunda bildirimler gönderilir
    }

    return savedNotification;
  }

  async sendRealtimeNotification(userId, notification) {
    try {
      const wsUrl = `${WEBSOCKET_GATEWAY_URL}/api/notifications/send`;
      const payload = {
        userId,
        notification: {
          id: notification._id.toString(),
          type: notification.type,
          title: notification.title,
          body: notification.body,
          data: notification.data,
          createdAt: notification.createdAt,
        },
      };
      
      console.log(`📤 Sending realtime notification to WebSocket Gateway for user ${userId}:`, JSON.stringify(payload, null, 2));
      
      const response = await axios.post(wsUrl, payload);
      console.log(`✅ Realtime notification sent successfully:`, response.data);
    } catch (error) {
      console.error(`❌ Error sending realtime notification to user ${userId}:`, error.message);
      if (error.response) {
        console.error('Response status:', error.response.status);
        console.error('Response data:', error.response.data);
      }
      // WebSocket Gateway'e ulaşılamazsa bildirim veritabanında kalır
    }
  }

  async isUserOnline(userId) {
    try {
      const connectionStatus = await redis.get(`connection:${userId}`);
      const socketId = await redis.get(`socket:${userId}`);
      console.log(`🔍 Checking online status for user ${userId}: connection=${connectionStatus}, socket=${socketId}`);
      return connectionStatus === 'online';
    } catch (error) {
      console.error('❌ Error checking user online status:', error);
      return false;
    }
  }

  async getNotifications(userId, limit = 50) {
    const notifications = await Notification.find({
      userId,
    })
      .sort({ createdAt: -1 })
      .limit(limit)
      .lean();

    return notifications;
  }

  async markAsRead(notificationId, userId) {
    const notification = await Notification.findOne({
      _id: notificationId,
      userId,
    });

    if (!notification) {
      throw new Error('Notification not found');
    }

    notification.read = true;
    await notification.save();

    return notification;
  }

  async markAllAsRead(userId) {
    const result = await Notification.updateMany(
      { userId, read: false },
      { read: true }
    );

    return result;
  }
}

module.exports = new NotificationService();

