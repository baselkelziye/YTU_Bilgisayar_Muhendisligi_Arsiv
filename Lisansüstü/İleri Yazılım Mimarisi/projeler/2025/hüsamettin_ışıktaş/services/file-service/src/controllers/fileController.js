const fileService = require('../services/fileService');

class FileController {
  async uploadFile(req, res) {
    try {
      if (!req.file) {
        return res.status(400).json({
          success: false,
          message: 'No file uploaded',
        });
      }

      const userId = req.user.userId;
      const file = await fileService.uploadFile(req.file, userId);

      res.status(201).json({
        success: true,
        message: 'File uploaded successfully',
        data: {
          id: file.id,
          originalName: file.original_name,
          mimeType: file.mime_type,
          size: file.size,
          url: file.url,
          uploadedAt: file.created_at,
        },
      });
    } catch (error) {
      res.status(400).json({
        success: false,
        message: error.message,
      });
    }
  }

  async downloadFile(req, res) {
    try {
      const { fileId } = req.params;
      const { file, filePath } = await fileService.getFile(fileId);

      res.download(filePath, file.original_name, (err) => {
        if (err) {
          console.error('Error downloading file:', err);
          res.status(500).json({
            success: false,
            message: 'Error downloading file',
          });
        }
      });
    } catch (error) {
      res.status(404).json({
        success: false,
        message: error.message,
      });
    }
  }

  async deleteFile(req, res) {
    try {
      const { fileId } = req.params;
      const userId = req.user.userId;

      await fileService.deleteFile(fileId, userId);

      res.json({
        success: true,
        message: 'File deleted successfully',
      });
    } catch (error) {
      const statusCode = error.message === 'File not found' ? 404 : 403;
      res.status(statusCode).json({
        success: false,
        message: error.message,
      });
    }
  }

  async getUserFiles(req, res) {
    try {
      const userId = req.user.userId;
      const files = await fileService.getUserFiles(userId);

      res.json({
        success: true,
        data: files,
      });
    } catch (error) {
      res.status(500).json({
        success: false,
        message: error.message,
      });
    }
  }
}

module.exports = new FileController();

