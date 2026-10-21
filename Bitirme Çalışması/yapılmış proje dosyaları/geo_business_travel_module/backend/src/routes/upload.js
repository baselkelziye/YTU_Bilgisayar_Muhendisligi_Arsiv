import express from "express";
import multer from 'multer';
import path from 'path';
import fs from 'fs';

const router = express.Router();

// Gelen dosyaların nereye kaydedileceğini belirle
const storage = multer.diskStorage({
    destination: function (req, file, cb) {
      cb(null, 'upload/');
    },
    filename: function (req, file, cb) {
      cb(null, Date.now() + path.extname(file.originalname));
    }
});
  
const upload = multer({ storage: storage });
  
  // Upload endpoint'i
router.post('/', upload.single('photo'), (req, res) => {
    //res.json({ message: 'Fotoğraf başarıyla yüklendi.' });
    // Dosyanın kaydedildiği yol
    const filePath = req.file.path;

    // İstemciye gönderilecek link oluştur
    const fileLink = `http://192.168.1.54:4000/${filePath}`;

    // İstemciye linki gönder
    res.json({ message: 'Fotoğraf başarıyla yüklendi.', fileLink: fileLink });
});

// Erişim linkini oluşturacak endpoint
router.get('/:filename', (req, res) => {
  const filename = req.params.filename;
  const filePath = path.join(__dirname, '../..', 'upload', filename);

  console.log(filePath);

  // Dosyanın var olup olmadığını kontrol et
  if (fs.existsSync(filePath)) {
      // Dosya varsa istemciye gönder
      res.sendFile(filePath);
  } else {
      // Dosya bulunamazsa 404 hatası döndür
      res.status(404).json({ error: 'Dosya bulunamadı' });
  }
});

export default router;
