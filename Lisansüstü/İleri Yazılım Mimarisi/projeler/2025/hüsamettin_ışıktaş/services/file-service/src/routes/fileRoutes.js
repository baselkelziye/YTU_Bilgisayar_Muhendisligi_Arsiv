const express = require('express');
const router = express.Router();
const fileController = require('../controllers/fileController');
const { authenticate } = require('../middleware/auth');
const storageService = require('../services/storageService');

// Tüm route'lar authentication gerektirir
router.use(authenticate);

router.post('/upload', storageService.getMulterMiddleware(), fileController.uploadFile);
router.get('/:fileId/download', fileController.downloadFile);
router.delete('/:fileId', fileController.deleteFile);
router.get('/user/:userId', fileController.getUserFiles);

module.exports = router;

