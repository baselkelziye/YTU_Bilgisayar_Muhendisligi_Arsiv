const logger = require('../lib/logger');
const { v4: uuidv4 } = require('uuid');

const requestLogger = (req, res, next) => {
  const requestId = req.headers['x-request-id'] || uuidv4();
  req.requestId = requestId;
  res.setHeader('X-Request-ID', requestId);
  
  const start = Date.now();
  
  logger.info('HTTP Request Started', {
    requestId,
    method: req.method,
    url: req.url,
    path: req.path,
    query: req.query,
    userId: req.user?.userId,
    ip: req.ip || req.connection.remoteAddress,
    userAgent: req.get('user-agent')
  });
  
  res.on('finish', () => {
    const duration = Date.now() - start;
    const logData = {
      requestId,
      method: req.method,
      url: req.url,
      path: req.path,
      statusCode: res.statusCode,
      duration: `${duration}ms`,
      userId: req.user?.userId,
      ip: req.ip || req.connection.remoteAddress
    };
    
    if (res.statusCode >= 400) {
      logger.warn('HTTP Request Completed', logData);
    } else {
      logger.info('HTTP Request Completed', logData);
    }
  });
  
  next();
};

module.exports = requestLogger;
