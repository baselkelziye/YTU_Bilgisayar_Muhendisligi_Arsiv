const multer = require('multer');
const path = require('path');
const fs = require('fs-extra');
const { v4: uuidv4 } = require('uuid');

const UPLOAD_DIR = process.env.UPLOAD_DIR || './uploads';
const MAX_FILE_SIZE = parseInt(process.env.MAX_FILE_SIZE) || 50 * 1024 * 1024; // 50MB

// Upload klasörünü oluştur
fs.ensureDirSync(UPLOAD_DIR);

// Desteklenen dosya türleri
const ALLOWED_MIME_TYPES = {
  image: ['image/jpeg', 'image/png', 'image/gif'],
  video: ['video/mp4', 'video/avi'],
  document: ['application/pdf', 'application/msword', 'application/vnd.openxmlformats-officedocument.wordprocessingml.document'],
};

const getAllowedMimeTypes = () => {
  return Object.values(ALLOWED_MIME_TYPES).flat();
};

// Multer configuration
const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    cb(null, UPLOAD_DIR);
  },
  filename: (req, file, cb) => {
    const ext = path.extname(file.originalname);
    const storedName = `${uuidv4()}${ext}`;
    cb(null, storedName);
  },
});

const fileFilter = (req, file, cb) => {
  const allowedTypes = getAllowedMimeTypes();
  if (allowedTypes.includes(file.mimetype)) {
    cb(null, true);
  } else {
    cb(new Error('Invalid file type. Allowed types: images (JPEG, PNG, GIF), videos (MP4, AVI), documents (PDF, DOC, DOCX)'));
  }
};

const upload = multer({
  storage,
  fileFilter,
  limits: {
    fileSize: MAX_FILE_SIZE,
  },
});

class StorageService {
  getMulterMiddleware() {
    return upload.single('file');
  }

  async saveFile(file) {
    // Dosya zaten multer tarafından kaydedilmiş
    // Burada sadece bilgileri döndürüyoruz
    return {
      originalName: file.originalname,
      storedName: file.filename,
      mimeType: file.mimetype,
      size: file.size,
      path: file.path,
    };
  }

  async getFile(storedName) {
    const filePath = path.join(UPLOAD_DIR, storedName);
    const exists = await fs.pathExists(filePath);
    
    if (!exists) {
      throw new Error('File not found');
    }

    return filePath;
  }

  async deleteFile(storedName) {
    const filePath = path.join(UPLOAD_DIR, storedName);
    const exists = await fs.pathExists(filePath);
    
    if (exists) {
      await fs.remove(filePath);
      return true;
    }

    return false;
  }

  generateSecureUrl(fileId) {
    // Basit bir yaklaşım: fileId ile URL oluştur
    // Production'da token tabanlı URL'ler kullanılabilir
    const baseUrl = process.env.BASE_URL || 'http://localhost:3005';
    return `${baseUrl}/api/files/${fileId}/download`;
  }

  validateFileType(mimeType) {
    const allowedTypes = getAllowedMimeTypes();
    return allowedTypes.includes(mimeType);
  }

  validateFileSize(size) {
    return size <= MAX_FILE_SIZE;
  }
}

module.exports = new StorageService();
module.exports.upload = upload;

