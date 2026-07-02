const chatService = require('../services/chatService');

class ChatController {
  async createDirectChat(req, res) {
    try {
      const { targetUserId, userId1, userId2 } = req.body;
      const currentUserId = req.user.userId;

      let otherUserId;

      if (targetUserId) {
        otherUserId = targetUserId;
      } else if (userId1 && userId2) {
        if (userId1 === currentUserId) otherUserId = userId2;
        else if (userId2 === currentUserId) otherUserId = userId1;
        else {
          return res.status(403).json({
            success: false,
            message: 'You must be a participant in the chat',
          });
        }
      } else {
        return res.status(400).json({
          success: false,
          message: 'targetUserId is required',
        });
      }

      if (otherUserId === currentUserId) {
        return res.status(400).json({
          success: false,
          message: 'You cannot create a direct chat with yourself',
        });
      }

      const chat = await chatService.createDirectChat(currentUserId, otherUserId);
      res.status(201).json({
        success: true,
        message: 'Direct chat created successfully',
        data: chat,
      });
    } catch (error) {
      res.status(400).json({
        success: false,
        message: error.message,
      });
    }
  }

  async createGroupChat(req, res) {
    try {
      const { name, participantIds } = req.body;
      const creatorId = req.user.userId;

      if (!name || !participantIds || !Array.isArray(participantIds)) {
        return res.status(400).json({
          success: false,
          message: 'Name and participantIds (array) are required',
        });
      }

      const chat = await chatService.createGroupChat(name, creatorId, participantIds);
      res.status(201).json({
        success: true,
        message: 'Group chat created successfully',
        data: chat,
      });
    } catch (error) {
      res.status(400).json({
        success: false,
        message: error.message,
      });
    }
  }

  async getUserChats(req, res) {
    try {
      const userId = req.user.userId;
      const chats = await chatService.getUserChats(userId);
      res.json({
        success: true,
        data: chats,
      });
    } catch (error) {
      res.status(500).json({
        success: false,
        message: error.message,
      });
    }
  }

  async getChatById(req, res) {
    try {
      const { chatId } = req.params;
      // Service call ise userId kontrolü yapma
      const isServiceCall = req.user?.isService === true;
      const userId = isServiceCall ? null : req.user.userId;
      const chat = await chatService.getChatById(chatId, userId, isServiceCall);
      res.json({
        success: true,
        data: chat,
      });
    } catch (error) {
      const statusCode = error.message === 'Chat not found' || error.message.includes('not a participant') ? 404 : 500;
      res.status(statusCode).json({
        success: false,
        message: error.message,
      });
    }
  }

  async addParticipant(req, res) {
    try {
      const { chatId } = req.params;
      const { userId } = req.body;
      const addedBy = req.user.userId;

      if (!userId) {
        return res.status(400).json({
          success: false,
          message: 'UserId is required',
        });
      }

      const chat = await chatService.addParticipant(chatId, userId, addedBy);
      if (!chat) {
        return res.status(404).json({
          success: false,
          message: 'Chat not found or deleted',
        });
      }

      res.json({
        success: true,
        message: 'Participant added successfully',
        data: chat,
      });
    } catch (error) {
      res.status(400).json({
        success: false,
        message: error.message,
      });
    }
  }

  async removeParticipant(req, res) {
    try {
      const { chatId, userId } = req.params;
      const removedBy = req.user.userId;

      const chat = await chatService.removeParticipant(chatId, userId, removedBy);
      if (!chat) {
        return res.json({
          success: true,
          message: 'Participant removed. Chat deleted as it has no participants.',
        });
      }

      res.json({
        success: true,
        message: 'Participant removed successfully',
        data: chat,
      });
    } catch (error) {
      res.status(400).json({
        success: false,
        message: error.message,
      });
    }
  }

  async deleteChat(req, res) {
    try {
      const { chatId } = req.params;
      const userId = req.user.userId;

      await chatService.deleteChat(chatId, userId);

      res.json({
        success: true,
        message: 'Chat deleted successfully',
      });
    } catch (error) {
      const statusCode = error.message === 'Chat not found' || error.message.includes('not a participant') ? 404 : 400;
      res.status(statusCode).json({
        success: false,
        message: error.message,
      });
    }
  }

  async leaveGroupChat(req, res) {
    try {
      const { chatId } = req.params;
      const userId = req.user.userId;

      const result = await chatService.leaveGroupChat(chatId, userId);

      res.json({
        success: true,
        message: result.deleted ? 'Left group and chat deleted (no participants left)' : 'Left group successfully',
      });
    } catch (error) {
      const statusCode = error.message === 'Chat not found' || error.message.includes('not a participant') ? 404 : 400;
      res.status(statusCode).json({
        success: false,
        message: error.message,
      });
    }
  }
}

module.exports = new ChatController();

