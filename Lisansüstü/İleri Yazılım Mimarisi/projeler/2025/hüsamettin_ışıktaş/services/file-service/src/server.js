require('dotenv').config();
const express = require('express');
const cors = require('cors');
const pool = require('./config/database');
const fileRoutes = require('./routes/fileRoutes');
const logger = require('../lib/logger');
const requestLogger = require('../middleware/requestLogger');
const errorLogger = require('../middleware/errorLogger');

const app = express();
const PORT = process.env.PORT || 3005;

// Middleware
app.use(cors());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// Request logging middleware (before routes)
app.use(requestLogger);

// Health check
app.get('/health', (req, res) => {
  res.json({ status: 'OK', service: 'file-service' });
});

// Routes
app.use('/api/files', fileRoutes);

// Error logging middleware (before error handler)
app.use(errorLogger);

// Error handling middleware
app.use((err, req, res, next) => {
  if (err.code === 'LIMIT_FILE_SIZE') {
    return res.status(400).json({
      success: false,
      message: 'File too large',
    });
  }

  res.status(500).json({
    success: false,
    message: err.message || 'Internal server error',
  });
});

// Initialize database
async function initializeDatabase() {
  try {
    await pool.query(`
      CREATE TABLE IF NOT EXISTS files (
        id VARCHAR(255) PRIMARY KEY,
        original_name VARCHAR(500) NOT NULL,
        stored_name VARCHAR(500) NOT NULL,
        mime_type VARCHAR(100) NOT NULL,
        size BIGINT NOT NULL,
        url VARCHAR(1000),
        uploaded_by VARCHAR(255) NOT NULL,
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
      )
    `);
    logger.info('Database initialized successfully');
  } catch (error) {
    logger.error('Database initialization error', { error: error.message, stack: error.stack });
    throw error;
  }
}

// Start server
async function startServer() {
  try {
    await initializeDatabase();
    
    app.listen(PORT, () => {
      logger.info(`File Service is running on port ${PORT}`);
    });
  } catch (error) {
    logger.error('Failed to start server', { error: error.message, stack: error.stack });
    process.exit(1);
  }
}

startServer();

module.exports = app;

