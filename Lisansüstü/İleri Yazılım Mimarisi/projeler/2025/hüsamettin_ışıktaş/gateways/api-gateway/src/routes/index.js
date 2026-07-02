const express = require('express');
const { createProxyMiddleware } = require('http-proxy-middleware');
const { authenticate } = require('../middleware/auth');
const services = require('../config/services');

const router = express.Router();

// Public routes (authentication gerektirmez) - ÖNCE tanımlanmalı
router.use('/api/users/register', createProxyMiddleware({
  target: services.USER_SERVICE,
  changeOrigin: true,
  pathRewrite: {
    '^/api/users': '/api/users',
  },
}));

router.use('/api/users/login', createProxyMiddleware({
  target: services.USER_SERVICE,
  changeOrigin: true,
  pathRewrite: {
    '^/api/users': '/api/users',
  },
}));

// Protected routes (authentication gerektirir)
router.use('/api/users', authenticate, createProxyMiddleware({
  target: services.USER_SERVICE,
  changeOrigin: true,
  pathRewrite: {
    '^/api/users': '/api/users',
  },
}));

router.use('/api/chats', authenticate, createProxyMiddleware({
  target: services.CHAT_SERVICE,
  changeOrigin: true,
  pathRewrite: {
    '^/api/chats': '/api/chats',
  },
}));

router.use('/api/messages', authenticate, createProxyMiddleware({
  target: services.MESSAGE_SERVICE,
  changeOrigin: true,
  pathRewrite: {
    '^/api/messages': '/api/messages',
  },
}));

router.use('/api/notifications', authenticate, createProxyMiddleware({
  target: services.NOTIFICATION_SERVICE,
  changeOrigin: true,
  pathRewrite: {
    '^/api/notifications': '/api/notifications',
  },
}));

router.use('/api/files', authenticate, createProxyMiddleware({
  target: services.FILE_SERVICE,
  changeOrigin: true,
  pathRewrite: {
    '^/api/files': '/api/files',
  },
}));

module.exports = router;
