# File Service

Dosya yükleme, depolama ve paylaşım servisi.

## Özellikler

- Dosya yükleme (resim, video, doküman)
- Dosya indirme
- Dosya silme
- Dosya listesi
- Güvenli dosya URL'leri

## Teknolojiler

- Node.js (Express)
- PostgreSQL
- Multer (file upload)
- fs-extra (file operations)

## Desteklenen Dosya Türleri

- Resimler: JPEG, PNG, GIF
- Videolar: MP4, AVI
- Dokümanlar: PDF, DOC, DOCX

## Maksimum Dosya Boyutu

50 MB (varsayılan)

## API Endpoints

- `POST /api/files/upload` - Dosya yükle
- `GET /api/files/:fileId/download` - Dosya indir
- `DELETE /api/files/:fileId` - Dosya sil
- `GET /api/files/user/:userId` - Kullanıcının dosyalarını listele
- `GET /health` - Health check

## Çalıştırma

```bash
npm install
npm start
```

## Docker

```bash
docker build -t file-service .
docker run -p 3005:3005 file-service
```

