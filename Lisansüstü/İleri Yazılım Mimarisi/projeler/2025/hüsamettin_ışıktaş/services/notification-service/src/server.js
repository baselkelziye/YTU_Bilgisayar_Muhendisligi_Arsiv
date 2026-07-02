require('dotenv').config();
const express = require('express');
const cors = require('cors');
const connectDB = require('./config/database');
const notificationRoutes = require('./routes/notificationRoutes');
const eventConsumer = require('./services/eventConsumer');
const logger = require('../lib/logger');
const requestLogger = require('../middleware/requestLogger');
const errorLogger = require('../middleware/errorLogger');

const app = express();
const PORT = process.env.PORT || 3004;

// Middleware
app.use(cors());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// Request logging middleware (before routes)
app.use(requestLogger);

// Health check
app.get('/health', (req, res) => {
  res.json({ status: 'OK', service: 'notification-service' });
});

// Routes
app.use('/api/notifications', notificationRoutes);

// Error logging middleware (before error handler)
app.use(errorLogger);

// Error handling middleware
app.use((err, req, res, next) => {
  res.status(500).json({
    success: false,
    message: 'Internal server error',
  });
});

// Start server
async function startServer() {
  try {
    await connectDB();
    
    // Event consumer'ı başlat
    await eventConsumer.start();
    
    app.listen(PORT, () => {
      logger.info(`Notification Service is running on port ${PORT}`);
    });
  } catch (error) {
    logger.error('Failed to start server', { error: error.message, stack: error.stack });
    process.exit(1);
  }
}

startServer();

module.exports = app;

