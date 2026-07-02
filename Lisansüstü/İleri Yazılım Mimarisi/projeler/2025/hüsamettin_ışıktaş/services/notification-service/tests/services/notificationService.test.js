const notificationService = require('../../src/services/notificationService');
const Notification = require('../../src/models/Notification');
const redis = require('../../src/config/redis');
const axios = require('axios');

// Mock dependencies
jest.mock('../../src/models/Notification');
jest.mock('../../src/config/redis', () => ({
  get: jest.fn(),
  setEx: jest.fn(),
}));
jest.mock('axios');

describe('NotificationService', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  describe('sendNotification', () => {
    const userId = 'user1';
    const type = 'MESSAGE';
    const title = 'New Message';
    const body = 'Hello';
    
    it('should create notification and send realtime if user is online', async () => {
      // Arrange
      const savedNotification = { 
        _id: 'notif1', 
        userId, 
        type, 
        title,
        createdAt: new Date()
      };
      
      const mockSave = jest.fn().mockResolvedValue(savedNotification);
      Notification.mockImplementation(() => ({ save: mockSave }));
      
      // Mock user online status
      redis.get.mockResolvedValue('online');
      
      // Mock axios for realtime
      axios.post.mockResolvedValue({});

      // Act
      const result = await notificationService.sendNotification(userId, type, title, body);

      // Assert
      expect(mockSave).toHaveBeenCalled();
      expect(redis.get).toHaveBeenCalledWith(`connection:${userId}`);
      expect(axios.post).toHaveBeenCalled(); // Realtime bildirim gönderilmeli
      expect(result).toEqual(savedNotification);
    });

    it('should create notification but not send realtime if user is offline', async () => {
      // Arrange
      const savedNotification = { _id: 'notif1', userId, type };
      
      const mockSave = jest.fn().mockResolvedValue(savedNotification);
      Notification.mockImplementation(() => ({ save: mockSave }));
      
      // Mock user offline
      redis.get.mockResolvedValue(null);

      // Act
      await notificationService.sendNotification(userId, type, title, body);

      // Assert
      expect(mockSave).toHaveBeenCalled();
      expect(axios.post).not.toHaveBeenCalled(); // Realtime bildirim gönderilmemeli
    });
  });

  describe('markAsRead', () => {
    it('should mark notification as read', async () => {
      // Arrange
      const mockNotification = { 
        _id: 'notif1', 
        userId: 'user1', 
        read: false,
        save: jest.fn().mockResolvedValue(true)
      };
      Notification.findOne.mockResolvedValue(mockNotification);

      // Act
      await notificationService.markAsRead('notif1', 'user1');

      // Assert
      expect(mockNotification.read).toBe(true);
      expect(mockNotification.save).toHaveBeenCalled();
    });

    it('should throw error if notification not found', async () => {
      // Arrange
      Notification.findOne.mockResolvedValue(null);

      // Act & Assert
      await expect(notificationService.markAsRead('notif1', 'user1'))
        .rejects
        .toThrow('Notification not found');
    });
  });
});

