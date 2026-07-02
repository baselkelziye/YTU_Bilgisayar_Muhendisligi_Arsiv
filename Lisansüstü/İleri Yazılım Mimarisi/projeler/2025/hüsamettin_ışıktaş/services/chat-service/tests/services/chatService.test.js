const chatService = require('../../src/services/chatService');
const Chat = require('../../src/models/Chat');
const userServiceClient = require('../../src/services/userServiceClient');
const redis = require('../../src/config/redis');
const amqp = require('amqplib');

// Mock dependencies
jest.mock('../../src/models/Chat');
jest.mock('../../src/services/userServiceClient');
jest.mock('../../src/config/redis', () => ({
  get: jest.fn(),
  setEx: jest.fn(),
  del: jest.fn(),
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

describe('ChatService', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  describe('createDirectChat', () => {
    const userId1 = 'user1';
    const userId2 = 'user2';

    it('should return existing chat if it already exists', async () => {
      // Arrange
      const existingChat = { _id: 'chat1', type: 'DIRECT', participants: [] };
      Chat.findOne.mockResolvedValue(existingChat);

      // Act
      const result = await chatService.createDirectChat(userId1, userId2);

      // Assert
      expect(Chat.findOne).toHaveBeenCalled();
      expect(result).toEqual(existingChat);
    });

    it('should create new chat if not exists and users verify', async () => {
      // Arrange
      Chat.findOne.mockResolvedValue(null);
      userServiceClient.verifyUsers.mockResolvedValue(true);
      const savedChat = { _id: 'newChat', type: 'DIRECT' };
      
      // Mock mongoose model constructor and save
      const mockSave = jest.fn().mockResolvedValue(savedChat);
      Chat.mockImplementation(() => ({ save: mockSave }));

      // Act
      const result = await chatService.createDirectChat(userId1, userId2);

      // Assert
      expect(userServiceClient.verifyUsers).toHaveBeenCalledWith([userId1, userId2]);
      expect(mockSave).toHaveBeenCalled();
      expect(redis.del).toHaveBeenCalledTimes(2); // 2 kullanıcı için cache temizlendi
      expect(result).toEqual(savedChat);
    });

    it('should throw error if users do not exist', async () => {
      // Arrange
      Chat.findOne.mockResolvedValue(null);
      userServiceClient.verifyUsers.mockResolvedValue(false);

      // Act & Assert
      await expect(chatService.createDirectChat(userId1, userId2))
        .rejects
        .toThrow('One or more users not found');
    });
  });

  describe('getUserChats', () => {
    const userId = 'user1';

    it('should return cached chats if available', async () => {
      // Arrange
      const cachedChats = [{ _id: 'chat1' }];
      redis.get.mockResolvedValue(JSON.stringify(cachedChats));

      // Act
      const result = await chatService.getUserChats(userId);

      // Assert
      expect(redis.get).toHaveBeenCalled();
      expect(Chat.find).not.toHaveBeenCalled();
      expect(result).toEqual(cachedChats);
    });

    it('should fetch from db and cache if not in cache', async () => {
      // Arrange
      redis.get.mockResolvedValue(null);
      const dbChats = [{ _id: 'chat1' }];
      
      // Mock mongoose find chain
      const mockSort = jest.fn().mockResolvedValue(dbChats);
      Chat.find.mockReturnValue({ sort: mockSort });

      // Act
      const result = await chatService.getUserChats(userId);

      // Assert
      expect(Chat.find).toHaveBeenCalledWith({ 'participants.userId': userId });
      expect(mockSort).toHaveBeenCalledWith({ updatedAt: -1 });
      expect(redis.setEx).toHaveBeenCalled();
      expect(result).toEqual(dbChats);
    });
  });
});

