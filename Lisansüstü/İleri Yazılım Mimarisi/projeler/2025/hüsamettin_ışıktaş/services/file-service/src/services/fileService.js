const File = require('../models/File');
const storageService = require('./storageService');

class FileService {
  async uploadFile(file, userId) {
    // Dosya bilgilerini al
    const fileInfo = await storageService.saveFile(file);
    
    // Güvenli URL oluştur
    // Önce dosyayı veritabanına kaydet, sonra URL'i oluştur
    const fileData = {
      originalName: fileInfo.originalName,
      storedName: fileInfo.storedName,
      mimeType: fileInfo.mimeType,
      size: fileInfo.size,
      url: '', // Önce boş, sonra güncellenecek
      uploadedBy: userId,
    };

    const savedFile = await File.create(fileData);
    
    // URL'i oluştur
    const secureUrl = storageService.generateSecureUrl(savedFile.id);

    return {
      ...savedFile,
      url: secureUrl,
    };
  }

  async getFile(fileId) {
    const file = await File.findById(fileId);
    if (!file) {
      throw new Error('File not found');
    }

    const filePath = await storageService.getFile(file.stored_name);
    return {
      file,
      filePath,
    };
  }

  async deleteFile(fileId, userId) {
    const file = await File.findById(fileId);
    if (!file) {
      throw new Error('File not found');
    }

    // Sadece dosya sahibi silebilir
    if (file.uploaded_by !== userId) {
      throw new Error('You can only delete your own files');
    }

    // Fiziksel dosyayı sil
    await storageService.deleteFile(file.stored_name);

    // Veritabanından sil
    await File.delete(fileId);

    return file;
  }

  async getUserFiles(userId) {
    return await File.findByUploadedBy(userId);
  }
}

module.exports = new FileService();

