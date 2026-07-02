const AuthService = require('../../src/services/authService');
const User = require('../../src/models/User');
const redis = require('../../src/config/redis');
const jwt = require('jsonwebtoken');

// Mock dependencies
jest.mock('../../src/models/User');
jest.mock('../../src/config/redis', () => ({
  setEx: jest.fn(),
  get: jest.fn(),
}));
jest.mock('jsonwebtoken');

describe('AuthService', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  describe('register', () => {
    const mockUserData = {
      username: 'testuser',
      email: 'test@example.com',
      password: 'password123',
      firstName: 'Test',
      lastName: 'User'
    };

    it('should register a new user successfully', async () => {
      // Arrange
      User.findByEmail.mockResolvedValue(null);
      User.findByUsername.mockResolvedValue(null);
      
      const createdUser = { ...mockUserData, id: 1, password_hash: 'hashed' };
      User.create.mockResolvedValue(createdUser);

      // Act
      const result = await AuthService.register(mockUserData);

      // Assert
      expect(User.findByEmail).toHaveBeenCalledWith(mockUserData.email);
      expect(User.findByUsername).toHaveBeenCalledWith(mockUserData.username);
      expect(User.create).toHaveBeenCalledWith(mockUserData);
      expect(result).toHaveProperty('email', mockUserData.email);
      expect(result).not.toHaveProperty('password_hash'); // Şifre hash'i dönmemeli
    });

    it('should throw error if email already exists', async () => {
      // Arrange
      User.findByEmail.mockResolvedValue({ id: 1 });

      // Act & Assert
      await expect(AuthService.register(mockUserData))
        .rejects
        .toThrow('Email already exists');
    });

    it('should throw error if username already exists', async () => {
      // Arrange
      User.findByEmail.mockResolvedValue(null);
      User.findByUsername.mockResolvedValue({ id: 1 });

      // Act & Assert
      await expect(AuthService.register(mockUserData))
        .rejects
        .toThrow('Username already exists');
    });
  });

  describe('login', () => {
    const mockEmail = 'test@example.com';
    const mockPassword = 'password123';
    const mockUser = {
      id: 1,
      email: mockEmail,
      password_hash: 'hashedPassword',
      username: 'testuser',
      first_name: 'Test',
      last_name: 'User',
    };

    it('should login successfully with valid credentials', async () => {
      // Arrange
      User.findByEmail.mockResolvedValue(mockUser);
      User.verifyPassword.mockResolvedValue(true);
      jwt.sign.mockReturnValue('mockToken');

      // Act
      const result = await AuthService.login(mockEmail, mockPassword);

      // Assert
      expect(User.findByEmail).toHaveBeenCalledWith(mockEmail);
      expect(User.verifyPassword).toHaveBeenCalledWith(mockPassword, mockUser.password_hash);
      expect(jwt.sign).toHaveBeenCalled();
      expect(redis.setEx).toHaveBeenCalled(); // Cache'leme kontrolü
      expect(result).toHaveProperty('token', 'mockToken');
      expect(result.user).toHaveProperty('email', mockEmail);
    });

    it('should throw error if user not found', async () => {
      // Arrange
      User.findByEmail.mockResolvedValue(null);

      // Act & Assert
      await expect(AuthService.login(mockEmail, mockPassword))
        .rejects
        .toThrow('Invalid credentials');
    });

    it('should throw error if password is invalid', async () => {
      // Arrange
      User.findByEmail.mockResolvedValue(mockUser);
      User.verifyPassword.mockResolvedValue(false);

      // Act & Assert
      await expect(AuthService.login(mockEmail, mockPassword))
        .rejects
        .toThrow('Invalid credentials');
    });
  });
});
