const messageService = require('../services/messageService');

class MessageController {
  async sendMessage(req, res) {
    try {
      const { chatId, content, messageType, fileUrl } = req.body;
      const senderId = req.user.userId;

      const message = await messageService.sendMessage(
        chatId,
        senderId,
        content,
        messageType || 'TEXT',
        fileUrl
      );

      res.status(201).json({
        success: true,
        message: 'Message sent successfully',
        data: message,
      });
    } catch (error) {
      res.status(400).json({
        success: false,
        message: error.message,
      });
    }
  }

  async getMessages(req, res) {
    try {
      const { chatId } = req.params;
      const page = parseInt(req.query.page) || 1;
      const limit = parseInt(req.query.limit) || 50;

      const messages = await messageService.getMessages(chatId, page, limit);

      res.json({
        success: true,
        data: messages,
        pagination: {
          page,
          limit,
          total: messages.length,
        },
      });
    } catch (error) {
      res.status(500).json({
        success: false,
        message: error.message,
      });
    }
  }

  async updateMessage(req, res) {
    try {
      const { messageId } = req.params;
      const { content } = req.body;
      const userId = req.user.userId;

      if (!content) {
        return res.status(400).json({
          success: false,
          message: 'Content is required',
        });
      }

      const message = await messageService.updateMessage(messageId, userId, content);

      res.json({
        success: true,
        message: 'Message updated successfully',
        data: message,
      });
    } catch (error) {
      const statusCode = error.message === 'Message not found' ? 404 : 400;
      res.status(statusCode).json({
        success: false,
        message: error.message,
      });
    }
  }

  async deleteMessage(req, res) {
    try {
      const { messageId } = req.params;
      const userId = req.user.userId;

      const message = await messageService.deleteMessage(messageId, userId);

      res.json({
        success: true,
        message: 'Message deleted successfully',
        data: message,
      });
    } catch (error) {
      const statusCode = error.message === 'Message not found' || error.message.includes('only delete') ? 404 : 400;
      res.status(statusCode).json({
        success: false,
        message: error.message,
      });
    }
  }

  async updateStatus(req, res) {
    try {
      const { messageId } = req.params;
      const { status } = req.body;

      if (!['SENT', 'DELIVERED', 'READ'].includes(status)) {
        return res.status(400).json({
          success: false,
          message: 'Invalid status',
        });
      }

      const message = await messageService.updateMessageStatus(messageId, status);

      res.json({
        success: true,
        message: 'Message status updated successfully',
        data: message,
      });
    } catch (error) {
      res.status(400).json({
        success: false,
        message: error.message,
      });
    }
  }
}

module.exports = new MessageController();

