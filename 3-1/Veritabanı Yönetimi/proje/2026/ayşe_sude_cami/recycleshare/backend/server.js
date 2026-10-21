require('dotenv').config();
const express = require('express');
const cors = require('cors');
const swaggerUi = require('swagger-ui-express');
const swaggerDocument = require('./swagger.json');
const authRoutes = require('./routes/auth.routes');
const wasteRoutes = require('./routes/waste.routes');
const reservationRoutes = require('./routes/reservation.routes');
const reportRoutes = require('./routes/report.routes');
const adminRoutes = require('./routes/admin.routes');
const { initializeDatabase } = require('./config/database');

const app = express();
const PORT = process.env.PORT || 5000;

// CORS - allow multiple origins (including Render/Vercel deployments)
const allowedOrigins = [
  'http://localhost:5173',
  'http://localhost:3000',
  process.env.FRONTEND_URL
].filter(Boolean);

app.use(cors({
  origin: function(origin, callback) {
    // Allow requests with no origin (mobile apps, Postman, etc.)
    if (!origin) return callback(null, true);
    if (allowedOrigins.includes(origin)) {
      return callback(null, true);
    }
    // Allow Render, Vercel, Netlify domains
    if (origin.endsWith('.onrender.com') || 
        origin.endsWith('.vercel.app') || 
        origin.endsWith('.netlify.app')) {
      return callback(null, true);
    }
    return callback(null, true); // Allow all for development
  },
  credentials: true
}));
app.use(express.json());

// Swagger API Documentation
app.use('/api/docs', swaggerUi.serve, swaggerUi.setup(swaggerDocument, {
  customCss: '.swagger-ui .topbar { display: none }',
  customSiteTitle: 'RecycleShare API Docs 🌿'
}));

// Health check
app.get('/api/health', (req, res) => {
  res.json({ status: 'ok', message: 'RecycleShare API is running 🌿' });
});

// Health check endpoint for Render
app.get('/api/auth/health', (req, res) => {
  res.json({ status: 'ok', service: 'RecycleShare Auth API', timestamp: new Date().toISOString() });
});

// Routes
app.use('/api/auth', authRoutes);
app.use('/api/waste', wasteRoutes);
app.use('/api/reservations', reservationRoutes);
app.use('/api/reports', reportRoutes);
app.use('/api/admin', adminRoutes);

// Error handling middleware
app.use((err, req, res, next) => {
  console.error('Error:', err);
  res.status(err.status || 500).json({
    success: false,
    message: err.message || 'Internal server error'
  });
});

// 404 handler
app.use((req, res) => {
  res.status(404).json({
    success: false,
    message: 'Route not found'
  });
});

// Start server
const startServer = async () => {
  try {
    await initializeDatabase();
    app.listen(PORT, () => {
      console.log(`
🌿 RecycleShare Server Running
📡 Port: ${PORT}
🌍 Environment: ${process.env.NODE_ENV || 'development'}
      `);
    });
  } catch (error) {
    console.error('Failed to start server:', error);
    process.exit(1);
  }
};

startServer();
