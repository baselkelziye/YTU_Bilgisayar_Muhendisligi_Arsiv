const express = require('express');
const router = express.Router();
const chatController = require('../controllers/chatController');
const { authenticate } = require('../middleware/auth');

// Tüm route'lar authentication gerektirir
router.use(authenticate);

router.post('/direct', chatController.createDirectChat);
router.post('/group', chatController.createGroupChat);
router.get('/user/me', chatController.getUserChats);
router.get('/:chatId', chatController.getChatById);
router.post('/:chatId/participants', chatController.addParticipant);
router.delete('/:chatId/participants/:userId', chatController.removeParticipant);
router.post('/:chatId/leave', chatController.leaveGroupChat);
router.delete('/:chatId', chatController.deleteChat);

module.exports = router;

