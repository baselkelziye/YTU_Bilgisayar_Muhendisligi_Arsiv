const messageService = require('../../src/services/messageService');
const Message = require('../../src/models/Message');
const redis = require('../../src/config/redis');
const amqp = require('amqplib');

// Mock dependencies
jest.mock('../../src/models/Message');
jest.mock('../../src/config/redis', () => ({
  get: jest.fn(),
  setEx: jest.fn(),
  del: jest.fn(),
  keys: jest.fn(),
}));
jest.mock('amqplib', () => ({
  connect: jest.fn().mockResolvedValue({
    createChannel: jest.fn().mockResolvedValue({
      assertExchange: jest.fn(),
      publish: jest.fn(),
      close: jest.fn(),
    }),
    close: jest.fn(),
  }),
}));

describe('MessageService', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  describe('sendMessage', () => {
    it('should create and save message', async () => {
      // Arrange
      const mockMessage = {
        chatId: 'chat1',
        senderId: 'user1',
        content: 'Hello',
        messageType: 'TEXT',
      };
      const savedMessage = { ...mockMessage, _id: 'msg1', status: 'SENT' };
      
      const mockSave = jest.fn().mockResolvedValue(savedMessage);
      Message.mockImplementation(() => ({ save: mockSave }));

      // Act
      const result = await messageService.sendMessage(
        mockMessage.chatId,
        mockMessage.senderId,
        mockMessage.content
      );

      // Assert
      expect(mockSave).toHaveBeenCalled();
      expect(redis.del).toHaveBeenCalled(); // Cache temizlenmeli
      expect(amqp.connect).toHaveBeenCalled(); // Event publish edilmeli
      expect(result).toEqual(savedMessage);
    });
  });

  describe('getMessages', () => {
    it('should return cached messages if available', async () => {
      // Arrange
      const cachedMessages = [{ _id: 'msg1', content: 'Cached' }];
      redis.get.mockResolvedValue(JSON.stringify(cachedMessages));

      // Act
      const result = await messageService.getMessages('chat1');

      // Assert
      expect(redis.get).toHaveBeenCalled();
      expect(Message.find).not.toHaveBeenCalled();
      expect(result).toEqual(cachedMessages);
    });

    it('should fetch from db if not in cache', async () => {
      // Arrange
      redis.get.mockResolvedValue(null);
      const dbMessages = [{ _id: 'msg1', content: 'DB' }];
      
      // Mock mongoose chain
      const mockSkip = jest.fn().mockReturnValue({ limit: jest.fn().mockReturnValue({ lean: jest.fn().mockResolvedValue(dbMessages) }) });
      const mockSort = jest.fn().mockReturnValue({ skip: mockSkip });
      Message.find.mockReturnValue({ sort: mockSort });

      // Act
      const result = await messageService.getMessages('chat1');

      // Assert
      expect(Message.find).toHaveBeenCalled();
      expect(redis.setEx).toHaveBeenCalled(); // Cache'lenmeli
      expect(result).toEqual(dbMessages); // reverse() çağrıldığı için array mutasyona uğrayabilir, mock sonucu basit tuttum
    });
  });

  describe('deleteMessage', () => {
    it('should delete message if sender is owner', async () => {
      // Arrange
      const mockMessage = { 
        _id: 'msg1', 
        senderId: 'user1', 
        chatId: 'chat1',
        save: jest.fn().mockResolvedValue(true)
      };
      Message.findById.mockResolvedValue(mockMessage);
      redis.keys.mockResolvedValue([]);

      // Act
      await messageService.deleteMessage('msg1', 'user1');

      // Assert
      expect(mockMessage.save).toHaveBeenCalled();
      expect(mockMessage.deleted).toBe(true);
      expect(redis.del).toHaveBeenCalled();
    });

    it('should throw error if sender is not owner', async () => {
      // Arrange
      const mockMessage = { 
        _id: 'msg1', 
        senderId: 'user2', // Farklı kullanıcı
        chatId: 'chat1' 
      };
      Message.findById.mockResolvedValue(mockMessage);

      // Act & Assert
      await expect(messageService.deleteMessage('msg1', 'user1'))
        .rejects
        .toThrow('You can only delete your own messages');
    });
  });
});

