# Ders 14.1 Çalışma Özeti

## Genel Konular

- Harici modüller (External Modules) ve Linking
  - Ayrı `.asm` dosyalarında yazılan assembly kodlarının derlenip C/C++ projelerine bağlanması (linking) süreci anlatılır.
- Assembly fonksiyonlarının C tarafından çağrılması
  - C tarafında `extern` anahtar kelimesiyle fonksiyon bildirimi ve linker aşaması ele alınır.
- Çağırma konvansiyonları (Calling Conventions)
  - Cdecl, Stdcall ve Fastcall kuralları, parametrelerin stack'e yerleştirilme sırası ve stack temizliği karşılaştırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çağırma kurallarının (Calling Conventions) hayati önemi
  - Çağıran ve çağrılan taraflar arasında stack temizliği ve parametre sırası uyumsuzluğunun program çökmesine yol açacağı.
- Harici fonksiyon isimlerindeki alt çizgi (_) kuralı
  - Derleyicinin fonksiyon adlarının başına otomatik alt çizgi eklemesi nedeniyle assembly tarafında isimlerin bu kurala uygun tanımlanması ve `PUBLIC` yapılması zorunluluğu.

## Kısa Tekrar Notları

- Assembly kodları ayrı .asm dosyasında yazılıp derlenerek C projesine eklenebilir.
- Fonksiyon bildirimleri C tarafında extern ile yapılır.
- Çağırma kurallarına (stack yönetimi vb.) dikkat edilmelidir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Harici modül kullanımı, assembly kodunun ayrı bir .asm dosyasında yazılıp derlenerek C/C++ projesine bağlanması (linking) yöntemidir. Bu yöntemde çağırma kuralları (Calling Conventions: Cdecl, Stdcall, Fastcall) hayati önem taşır. Cdecl kuralında parametreler sağdan sola stack'e push edilir ve stack temizliği çağıran (caller) fonksiyon tarafından yapılır; Stdcall'da ise stack temizliği çağrılan (callee) fonksiyon tarafından RET X ile yapılır. C derleyicisinin harici fonksiyon isimlerinin başına alt çizgi (_) ekleme alışkanlığı nedeniyle assembly tarafındaki fonksiyon adları bu kurala uygun tanımlanmalı ve PUBLIC direktifiyle dışa aktarılmalıdır. C tarafında ise bu fonksiyonlar extern anahtar kelimesiyle bildirilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
