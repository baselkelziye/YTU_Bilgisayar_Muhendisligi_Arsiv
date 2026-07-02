const axios = require('axios');

const USER_SERVICE_URL = process.env.USER_SERVICE_URL || 'http://localhost:3001';
const SERVICE_TOKEN = process.env.SERVICE_TOKEN || 'dev-service-token-change-in-production';

class UserServiceClient {
  async getUser(userId) {
    try {
      const response = await axios.get(`${USER_SERVICE_URL}/api/users/${userId}`, {
        headers: {
          'X-Service-Token': SERVICE_TOKEN,
        },
      });
      return response.data.data;
    } catch (error) {
      if (error.response && error.response.status === 404) {
        throw new Error('User not found');
      }
      throw new Error('Failed to fetch user from User Service');
    }
  }

  async verifyUsers(userIds) {
    try {
      // Tüm kullanıcıların var olup olmadığını kontrol et
      const promises = userIds.map(userId => this.getUser(userId));
      await Promise.all(promises);
      return true;
    } catch (error) {
      return false;
    }
  }
}

module.exports = new UserServiceClient();
