module.exports = {
  USER_SERVICE: process.env.USER_SERVICE_URL || 'http://localhost:3001',
  CHAT_SERVICE: process.env.CHAT_SERVICE_URL || 'http://localhost:3002',
  MESSAGE_SERVICE: process.env.MESSAGE_SERVICE_URL || 'http://localhost:3003',
  NOTIFICATION_SERVICE: process.env.NOTIFICATION_SERVICE_URL || 'http://localhost:3004',
  FILE_SERVICE: process.env.FILE_SERVICE_URL || 'http://localhost:3005',
};

