const jwt = require('jsonwebtoken');
const User = require('../models/User');
const redis = require('../config/redis');

const JWT_SECRET = process.env.JWT_SECRET || 'your-super-secret-jwt-key-change-in-production';
const JWT_EXPIRES_IN = process.env.JWT_EXPIRES_IN || '24h';

class AuthService {
  static async register(userData) {
    // Email ve username benzersizlik kontrolü
    const existingEmail = await User.findByEmail(userData.email);
    if (existingEmail) {
      throw new Error('Email already exists');
    }

    const existingUsername = await User.findByUsername(userData.username);
    if (existingUsername) {
      throw new Error('Username already exists');
    }

    // Kullanıcı oluştur
    const user = await User.create(userData);
    
    // JWT token oluştur
    const token = jwt.sign(
      { userId: user.id, email: user.email },
      JWT_SECRET,
      { expiresIn: JWT_EXPIRES_IN }
    );

    // Kullanıcı bilgilerini cache'le (1 saat)
    const userCache = {
      id: user.id,
      email: user.email,
      username: user.username,
      first_name: user.first_name,
      last_name: user.last_name,
    };
    await redis.setEx(`user:${user.id}`, 3600, JSON.stringify(userCache));
    
    return {
      token,
      user: {
        id: user.id,
        email: user.email,
        username: user.username,
        first_name: user.first_name,
        last_name: user.last_name,
        profile_picture: user.profile_picture,
        status_message: user.status_message,
      },
    };
  }

  static async login(email, password) {
    // Kullanıcıyı bul
    const user = await User.findByEmail(email);
    if (!user) {
      throw new Error('Invalid credentials');
    }

    // Şifreyi doğrula
    const isValidPassword = await User.verifyPassword(password, user.password_hash);
    if (!isValidPassword) {
      throw new Error('Invalid credentials');
    }

    // JWT token oluştur
    const token = jwt.sign(
      { userId: user.id, email: user.email },
      JWT_SECRET,
      { expiresIn: JWT_EXPIRES_IN }
    );

    // Kullanıcı bilgilerini cache'le (1 saat)
    const userCache = {
      id: user.id,
      email: user.email,
      username: user.username,
      first_name: user.first_name,
      last_name: user.last_name,
    };
    await redis.setEx(`user:${user.id}`, 3600, JSON.stringify(userCache));

    return {
      token,
      user: {
        id: user.id,
        email: user.email,
        username: user.username,
        first_name: user.first_name,
        last_name: user.last_name,
        profile_picture: user.profile_picture,
        status_message: user.status_message,
      },
    };
  }

  static async verifyToken(token) {
    try {
      const decoded = jwt.verify(token, JWT_SECRET);
      
      // Cache'den kontrol et
      const cached = await redis.get(`user:${decoded.userId}`);
      if (cached) {
        return JSON.parse(cached);
      }

      // Cache'de yoksa veritabanından al
      const user = await User.findById(decoded.userId);
      if (!user) {
        throw new Error('User not found');
      }

      return {
        id: user.id,
        email: user.email,
        username: user.username,
        first_name: user.first_name,
        last_name: user.last_name,
      };
    } catch (error) {
      throw new Error('Invalid token');
    }
  }
}

module.exports = AuthService;

