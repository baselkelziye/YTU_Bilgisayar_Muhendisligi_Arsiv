const express = require('express');
const router = express.Router();
const messageController = require('../controllers/messageController');
const { authenticate } = require('../middleware/auth');
const { validateSendMessage } = require('../middleware/validation');

// Tüm route'lar authentication gerektirir
router.use(authenticate);

router.post('/', validateSendMessage, messageController.sendMessage);
router.get('/chat/:chatId', messageController.getMessages);
router.put('/:messageId', messageController.updateMessage);
router.delete('/:messageId', messageController.deleteMessage);
router.put('/:messageId/status', messageController.updateStatus);

module.exports = router;

