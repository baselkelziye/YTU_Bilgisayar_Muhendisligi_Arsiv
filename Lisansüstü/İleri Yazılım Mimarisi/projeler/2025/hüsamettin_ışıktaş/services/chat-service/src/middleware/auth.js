const jwt = require('jsonwebtoken');

const JWT_SECRET = process.env.JWT_SECRET || 'your-super-secret-jwt-key-change-in-production';
const SERVICE_TOKEN = process.env.SERVICE_TOKEN || 'dev-service-token-change-in-production';

const authenticate = (req, res, next) => {
  try {
    // Service-to-service authentication kontrolü
    const serviceToken = req.headers['x-service-token'];
    if (serviceToken === SERVICE_TOKEN) {
      // Service token geçerli, internal call olarak kabul et
      // req.user'ı null bırakabiliriz veya özel bir service user objesi oluşturabiliriz
      req.user = { userId: 'service', isService: true };
      return next();
    }

    // Normal JWT authentication
    const authHeader = req.headers.authorization;
    if (!authHeader || !authHeader.startsWith('Bearer ')) {
      return res.status(401).json({
        success: false,
        message: 'Authorization token required',
      });
    }

    const token = authHeader.substring(7);
    const decoded = jwt.verify(token, JWT_SECRET);
    req.user = decoded;
    next();
  } catch (error) {
    res.status(401).json({
      success: false,
      message: 'Invalid or expired token',
    });
  }
};

module.exports = { authenticate };

