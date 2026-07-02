require('dotenv').config();
const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const cors = require('cors');
const jwt = require('jsonwebtoken');
const connectionManager = require('./services/connectionManager');
const redis = require('./config/redis');
const logger = require('../lib/logger');
const requestLogger = require('../middleware/requestLogger');
const errorLogger = require('../middleware/errorLogger');

const app = express();
const server = http.createServer(app);
const io = new Server(server, {
  cors: {
    origin: '*',
    methods: ['GET', 'POST'],
  },
});

const PORT = process.env.PORT || 3006;
const JWT_SECRET = process.env.JWT_SECRET || 'your-super-secret-jwt-key-change-in-production';

// Middleware
app.use(cors());
app.use(express.json());

// Request logging middleware (before routes)
app.use(requestLogger);

// Health check
app.get('/health', (req, res) => {
  res.json({ status: 'OK', service: 'websocket-gateway' });
});

// API endpoint for sending notifications (Notification Service'den çağrılacak)
app.post('/api/notifications/send', async (req, res) => {
  try {
    const { userId, notification } = req.body;

    logger.info('Notification request received', { userId, notification });

    if (!userId || !notification) {
      return res.status(400).json({
        success: false,
        message: 'UserId and notification are required',
      });
    }

    // Kullanıcının socket ID'sini al
    const socketId = await redis.get(`socket:${userId}`);
    logger.debug('Socket ID lookup', { userId, socketId });
    
    if (socketId) {
      // Socket.io instance'ına erişim için global io kullanıyoruz
      const socketExists = io.sockets.sockets.has(socketId);
      logger.debug('Socket existence check', { socketId, socketExists });
      
      if (socketExists) {
        io.to(socketId).emit('notification', notification);
        logger.info('Notification emitted to socket', { userId, socketId });
      } else {
        logger.warn('Socket not found, user might have disconnected', { userId, socketId });
        // Socket yoksa redis'ten temizle
        await redis.del(`socket:${userId}`);
        await redis.del(`connection:${userId}`);
      }
    } else {
      logger.warn('No socket ID found, user might be offline', { userId });
    }

    res.json({
      success: true,
      message: 'Notification sent',
      socketFound: !!socketId,
    });
  } catch (error) {
    logger.error('Error sending notification', { 
      error: error.message, 
      stack: error.stack,
      userId: req.body?.userId 
    });
    res.status(500).json({
      success: false,
      message: 'Error sending notification',
    });
  }
});

// API endpoint for sending chat events (Chat Service'den çağrılacak)
app.post('/api/chats/broadcast', async (req, res) => {
  try {
    const { userIds, event, data } = req.body;

    if (!userIds || !Array.isArray(userIds) || !event || !data) {
      return res.status(400).json({
        success: false,
        message: 'UserIds (array), event, and data are required',
      });
    }

    logger.info('Chat broadcast request received', { userIds, event });

    const results = [];
    for (const userId of userIds) {
      const socketId = await redis.get(`socket:${userId}`);
      if (socketId && io.sockets.sockets.has(socketId)) {
        io.to(socketId).emit(event, data);
        results.push({ userId, sent: true });
        logger.info(`Chat event ${event} emitted to user ${userId}`);
      } else {
        results.push({ userId, sent: false });
      }
    }

    res.json({
      success: true,
      message: 'Chat event broadcasted',
      results,
    });
  } catch (error) {
    logger.error('Error broadcasting chat event', { error: error.message });
    res.status(500).json({
      success: false,
      message: 'Error broadcasting chat event',
    });
  }
});

// API endpoint for sending message events (Message Service'den çağrılacak)
app.post('/api/messages/broadcast', async (req, res) => {
  try {
    const { userIds, event, data } = req.body;

    if (!userIds || !Array.isArray(userIds) || !event || !data) {
      return res.status(400).json({
        success: false,
        message: 'UserIds (array), event, and data are required',
      });
    }

    logger.info('Message broadcast request received', { userIds, event });

    const results = [];
    for (const userId of userIds) {
      const socketId = await redis.get(`socket:${userId}`);
      if (socketId && io.sockets.sockets.has(socketId)) {
        io.to(socketId).emit(event, data);
        results.push({ userId, sent: true });
        logger.info(`Message event ${event} emitted to user ${userId}`);
      } else {
        results.push({ userId, sent: false });
      }
    }

    res.json({
      success: true,
      message: 'Message event broadcasted',
      results,
    });
  } catch (error) {
    logger.error('Error broadcasting message event', { error: error.message });
    res.status(500).json({
      success: false,
      message: 'Error broadcasting message event',
    });
  }
});

// Socket.io connection handling
io.use((socket, next) => {
  try {
    const token = socket.handshake.auth.token;
    if (!token) {
      return next(new Error('Authentication token required'));
    }

    const decoded = jwt.verify(token, JWT_SECRET);
    socket.userId = decoded.userId;
    next();
  } catch (error) {
    next(new Error('Invalid token'));
  }
});

io.on('connection', async (socket) => {
  const userId = socket.userId;
  logger.info('User connected', { userId, socketId: socket.id });

  // Bağlantıyı yönet
  await connectionManager.addConnection(userId, socket.id);
  logger.info('Connection stored', { userId, socketId: socket.id });

  // Kullanıcıya bağlantı başarılı mesajı gönder
  socket.emit('connected', {
    message: 'Connected to WebSocket',
    userId,
  });

  // Disconnect
  socket.on('disconnect', async () => {
    logger.info('User disconnected', { userId, socketId: socket.id });
    await connectionManager.removeConnection(userId);
  });

  // Heartbeat (bağlantının canlı kalması için)
  socket.on('ping', () => {
    socket.emit('pong');
  });
});

// Error logging middleware (before error handler)
app.use(errorLogger);

// Start server
server.listen(PORT, () => {
  logger.info(`WebSocket Gateway is running on port ${PORT}`);
});

module.exports = { app, server, io };

