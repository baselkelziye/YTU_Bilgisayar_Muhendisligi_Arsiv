const pool = require('../config/database');
const { v4: uuidv4 } = require('uuid');

class File {
  static async create(fileData) {
    const { originalName, storedName, mimeType, size, url, uploadedBy } = fileData;
    
    const query = `
      INSERT INTO files (id, original_name, stored_name, mime_type, size, url, uploaded_by, created_at, updated_at)
      VALUES ($1, $2, $3, $4, $5, $6, $7, NOW(), NOW())
      RETURNING *
    `;
    
    const id = uuidv4();
    const result = await pool.query(query, [id, originalName, storedName, mimeType, size, url, uploadedBy]);
    return result.rows[0];
  }

  static async findById(id) {
    const query = 'SELECT * FROM files WHERE id = $1';
    const result = await pool.query(query, [id]);
    return result.rows[0];
  }

  static async findByUploadedBy(uploadedBy) {
    const query = 'SELECT * FROM files WHERE uploaded_by = $1 ORDER BY created_at DESC';
    const result = await pool.query(query, [uploadedBy]);
    return result.rows;
  }

  static async delete(id) {
    const query = 'DELETE FROM files WHERE id = $1 RETURNING *';
    const result = await pool.query(query, [id]);
    return result.rows[0];
  }
}

module.exports = File;

