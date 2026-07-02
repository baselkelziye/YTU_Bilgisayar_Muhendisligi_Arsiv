const fileService = require('../../src/services/fileService');
const File = require('../../src/models/File');
const storageService = require('../../src/services/storageService');

// Mock dependencies
jest.mock('../../src/models/File');
jest.mock('../../src/services/storageService');

describe('FileService', () => {
  beforeEach(() => {
    jest.clearAllMocks();
  });

  describe('uploadFile', () => {
    it('should save file info to db and return secure url', async () => {
      // Arrange
      const mockFile = {
        originalname: 'test.jpg',
        filename: 'stored.jpg',
        mimetype: 'image/jpeg',
        size: 1024,
      };
      
      const fileInfo = {
        originalName: 'test.jpg',
        storedName: 'stored.jpg',
        mimeType: 'image/jpeg',
        size: 1024,
      };
      
      const savedFile = { 
        id: 'file1', 
        ...fileInfo,
        url: '' 
      };

      storageService.saveFile.mockResolvedValue(fileInfo);
      File.create.mockResolvedValue(savedFile);
      storageService.generateSecureUrl.mockReturnValue('http://secure-url/file1');

      // Act
      const result = await fileService.uploadFile(mockFile, 'user1');

      // Assert
      expect(storageService.saveFile).toHaveBeenCalledWith(mockFile);
      expect(File.create).toHaveBeenCalled();
      expect(storageService.generateSecureUrl).toHaveBeenCalledWith('file1');
      expect(result.url).toBe('http://secure-url/file1');
    });
  });

  describe('getFile', () => {
    it('should return file metadata and path', async () => {
      // Arrange
      const mockFile = { 
        id: 'file1', 
        stored_name: 'stored.jpg' 
      };
      File.findById.mockResolvedValue(mockFile);
      storageService.getFile.mockResolvedValue('/path/to/stored.jpg');

      // Act
      const result = await fileService.getFile('file1');

      // Assert
      expect(File.findById).toHaveBeenCalledWith('file1');
      expect(storageService.getFile).toHaveBeenCalledWith('stored.jpg');
      expect(result).toEqual({ file: mockFile, filePath: '/path/to/stored.jpg' });
    });

    it('should throw error if file not found', async () => {
      // Arrange
      File.findById.mockResolvedValue(null);

      // Act & Assert
      await expect(fileService.getFile('file1'))
        .rejects
        .toThrow('File not found');
    });
  });

  describe('deleteFile', () => {
    it('should delete file from storage and db if owner', async () => {
      // Arrange
      const mockFile = { 
        id: 'file1', 
        stored_name: 'stored.jpg',
        uploaded_by: 'user1'
      };
      File.findById.mockResolvedValue(mockFile);

      // Act
      await fileService.deleteFile('file1', 'user1');

      // Assert
      expect(storageService.deleteFile).toHaveBeenCalledWith('stored.jpg');
      expect(File.delete).toHaveBeenCalledWith('file1');
    });

    it('should throw error if not owner', async () => {
      // Arrange
      const mockFile = { 
        id: 'file1', 
        stored_name: 'stored.jpg',
        uploaded_by: 'otherUser'
      };
      File.findById.mockResolvedValue(mockFile);

      // Act & Assert
      await expect(fileService.deleteFile('file1', 'user1'))
        .rejects
        .toThrow('You can only delete your own files');
    });
  });
});

