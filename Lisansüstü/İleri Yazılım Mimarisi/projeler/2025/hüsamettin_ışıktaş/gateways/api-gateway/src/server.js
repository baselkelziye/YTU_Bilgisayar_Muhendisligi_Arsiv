require('dotenv').config();
const express = require('express');
const cors = require('cors');
const rateLimit = require('express-rate-limit');
const swaggerUi = require('swagger-ui-express');
const swaggerSpec = require('./config/swagger');
const routes = require('./routes');
const logger = require('../lib/logger');
const requestLogger = require('../middleware/requestLogger');
const errorLogger = require('../middleware/errorLogger');

const app = express();
const PORT = process.env.PORT || 3000;

// Rate limiting
const limiter = rateLimit({
  windowMs: 1 * 60 * 1000, // 1 dakika
  max: 60, // maksimum 60 istek
  message: {
    success: false,
    message: 'Too many requests from this IP, please try again later.',
  },
});

// Middleware
app.use(cors());
// Body parser middleware'lerini kaldırıyoruz çünkü http-proxy-middleware ile çakışıyor.
// Proxy body'yi kendisi handle eder.
// app.use(express.json());
// app.use(express.urlencoded({ extended: true }));
app.use(limiter);

// Request logging middleware (before routes)
app.use(requestLogger);

// Health check
app.get('/health', (req, res) => {
  res.json({ status: 'OK', service: 'api-gateway' });
});

// Swagger Documentation
app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerSpec));

// Routes
app.use('/', routes);

// Error logging middleware (before error handler)
app.use(errorLogger);

// Error handling middleware
app.use((err, req, res, next) => {
  res.status(500).json({
    success: false,
    message: 'Internal server error',
  });
});

// 404 handler
app.use((req, res) => {
  res.status(404).json({
    success: false,
    message: 'Route not found',
  });
});

// Start server
app.listen(PORT, () => {
  logger.info(`API Gateway is running on port ${PORT}`);
});

module.exports = app;

