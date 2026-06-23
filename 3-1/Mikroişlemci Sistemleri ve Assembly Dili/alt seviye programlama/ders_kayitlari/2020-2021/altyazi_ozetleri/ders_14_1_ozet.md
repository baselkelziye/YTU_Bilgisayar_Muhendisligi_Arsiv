# Ders 14.1 Çalışma Özeti

## Genel Konular

- Assembly yordamlarının harici modüller (external modules) olarak derlenip C/C++ projelerine bağlanması (linking)
- Arama, sıralama gibi algoritmaların assembly kütüphanesi olarak yazılması ve test edilmesi
- Dönem sonu özeti ve değerlendirmesi

## Hocanın Özellikle Vurguladığı Kısımlar

- **Harici modül kullanımında çağırma konvansiyonları (Calling Conventions:** Cdecl, Stdcall) ve stack yapısının uyumluluğu.
- Harici fonksiyon adlarının başındaki alt çizgi (_) kuralı ve linker hatalarının çözümü.

## Kısa Tekrar Notları

- Assembly kodları ayrı .asm dosyasında yazılıp derlenerek C projesine eklenebilir.
- Fonksiyon bildirimleri C tarafında extern ile yapılır.
- Çağırma kurallarına (stack yönetimi vb.) dikkat edilmelidir.
