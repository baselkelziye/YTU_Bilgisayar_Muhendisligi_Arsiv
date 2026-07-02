const redis = require('../config/redis');

class ConnectionManager {
  constructor() {
    this.connections = new Map(); // userId -> socketId mapping
  }

  async addConnection(userId, socketId) {
    this.connections.set(userId, socketId);
    // Redis'e de kaydet (birden fazla instance için)
    await redis.set(`connection:${userId}`, 'online');
    await redis.set(`socket:${userId}`, socketId);
  }

  async removeConnection(userId) {
    this.connections.delete(userId);
    await redis.del(`connection:${userId}`);
    await redis.del(`socket:${userId}`);
  }

  getSocketId(userId) {
    return this.connections.get(userId);
  }

  async isUserOnline(userId) {
    const status = await redis.get(`connection:${userId}`);
    return status === 'online';
  }
}

module.exports = new ConnectionManager();

