const logger = require('../lib/logger');

const errorLogger = (err, req, res, next) => {
  logger.error('Request Error', {
    requestId: req.requestId,
    error: {
      message: err.message,
      stack: err.stack,
      name: err.name
    },
    method: req.method,
    url: req.url,
    path: req.path,
    query: req.query,
    body: req.body,
    ip: req.ip || req.connection.remoteAddress
  });
  
  next(err);
};

module.exports = errorLogger;
