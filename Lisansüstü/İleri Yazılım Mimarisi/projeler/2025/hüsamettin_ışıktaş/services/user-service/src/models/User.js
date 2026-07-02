const pool = require('../config/database');
const bcrypt = require('bcrypt');

class User {
  static async create(userData) {
    const { email, username, password, firstName, lastName } = userData;
    
    // Şifreyi hash'le
    const saltRounds = 10;
    const passwordHash = await bcrypt.hash(password, saltRounds);
    
    const query = `
      INSERT INTO users (email, username, password_hash, first_name, last_name, created_at, updated_at)
      VALUES ($1, $2, $3, $4, $5, NOW(), NOW())
      RETURNING id, email, username, first_name, last_name, profile_picture, status_message, created_at, updated_at
    `;
    
    const result = await pool.query(query, [email, username, passwordHash, firstName, lastName]);
    return result.rows[0];
  }

  static async findByEmail(email) {
    const query = 'SELECT * FROM users WHERE email = $1';
    const result = await pool.query(query, [email]);
    return result.rows[0];
  }

  static async findByUsername(username) {
    const query = 'SELECT * FROM users WHERE username = $1';
    const result = await pool.query(query, [username]);
    return result.rows[0];
  }

  static async findById(id) {
    const query = 'SELECT id, email, username, first_name, last_name, profile_picture, status_message, created_at, updated_at FROM users WHERE id = $1';
    const result = await pool.query(query, [id]);
    return result.rows[0];
  }

  static async search(searchTerm, excludeUserId = null) {
    let query = `
      SELECT id, email, username, first_name, last_name, profile_picture, status_message 
      FROM users 
      WHERE (username ILIKE $1 OR email ILIKE $1 OR first_name ILIKE $1 OR last_name ILIKE $1)
    `;
    const params = [`%${searchTerm}%`];
    
    // Kullanıcının kendisini sonuçlardan çıkar
    if (excludeUserId) {
      query += ` AND id != $2`;
      params.push(excludeUserId);
    }
    
    query += ` LIMIT 20`;
    
    const result = await pool.query(query, params);
    return result.rows;
  }

  static async update(id, updateData) {
    const { firstName, lastName, profilePicture, statusMessage } = updateData;
    const fields = [];
    const values = [];
    let paramCount = 1;

    if (firstName !== undefined) {
      fields.push(`first_name = $${paramCount++}`);
      values.push(firstName);
    }
    if (lastName !== undefined) {
      fields.push(`last_name = $${paramCount++}`);
      values.push(lastName);
    }
    if (profilePicture !== undefined) {
      fields.push(`profile_picture = $${paramCount++}`);
      values.push(profilePicture);
    }
    if (statusMessage !== undefined) {
      fields.push(`status_message = $${paramCount++}`);
      values.push(statusMessage);
    }

    if (fields.length === 0) {
      return await this.findById(id);
    }

    fields.push(`updated_at = NOW()`);
    values.push(id);

    const query = `
      UPDATE users 
      SET ${fields.join(', ')}
      WHERE id = $${paramCount}
      RETURNING id, email, username, first_name, last_name, profile_picture, status_message, created_at, updated_at
    `;

    const result = await pool.query(query, values);
    return result.rows[0];
  }

  static async verifyPassword(plainPassword, hashedPassword) {
    return await bcrypt.compare(plainPassword, hashedPassword);
  }
}

module.exports = User;

