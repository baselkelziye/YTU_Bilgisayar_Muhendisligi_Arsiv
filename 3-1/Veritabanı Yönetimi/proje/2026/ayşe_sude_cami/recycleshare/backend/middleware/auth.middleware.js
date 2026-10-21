const { verifyToken } = require('../utils/jwt.utils');
const { query } = require('../config/database');

// Authenticate user middleware
const authenticate = async (req, res, next) => {
  try {
    const authHeader = req.headers.authorization;
    
    if (!authHeader || !authHeader.startsWith('Bearer ')) {
      return res.status(401).json({
        success: false,
        message: 'Access denied. No token provided.'
      });
    }

    const token = authHeader.split(' ')[1];
    const decoded = verifyToken(token);

    // Fetch user from database
    const result = await query(
      'SELECT user_id, email, first_name, last_name, role, is_verified, is_active FROM users WHERE user_id = $1',
      [decoded.userId]
    );

    if (result.rows.length === 0) {
      return res.status(401).json({
        success: false,
        message: 'User not found'
      });
    }

    const user = result.rows[0];

    if (!user.is_active) {
      return res.status(403).json({
        success: false,
        message: 'Account has been deactivated'
      });
    }

    req.user = user;
    next();
  } catch (error) {
    return res.status(401).json({
      success: false,
      message: 'Invalid or expired token'
    });
  }
};

// Check if user is verified
const requireVerification = (req, res, next) => {
  if (!req.user.is_verified) {
    return res.status(403).json({
      success: false,
      message: 'Please verify your email to access this resource'
    });
  }
  next();
};

// Role-based authorization
const authorize = (...roles) => {
  return (req, res, next) => {
    if (!roles.includes(req.user.role)) {
      return res.status(403).json({
        success: false,
        message: 'You do not have permission to perform this action'
      });
    }
    next();
  };
};

// Require specific role
const requireRole = (role) => {
  return (req, res, next) => {
    if (req.user.role !== role) {
      return res.status(403).json({
        success: false,
        message: `Bu işlem için '${role}' yetkisi gerekli`
      });
    }
    next();
  };
};

// Alias for authenticate (for consistency)
const authenticateToken = authenticate;

module.exports = {
  authenticate,
  authenticateToken,
  requireVerification,
  authorize,
  requireRole
};
