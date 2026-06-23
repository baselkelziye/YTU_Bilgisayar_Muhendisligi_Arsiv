# Ders 1 Çalışma Özeti

## Genel Konular

- Alt seviye programlama ve Assembly dillerine giriş
  - Yüksek seviyeli dillerin aksine donanım mimarisine doğrudan bağımlı olan programlama yapısı tanıtılır.
- 8086 mikroişlemci mimarisi ve yazmaçlar
  - Register (yazmaç) kavramı ve genel amaçlı yazmaçların (AX, BX, CX, DX) görevleri açıklanır.
- Segment yapısı ve hafıza organizasyonu
  - CS, DS, SS, ES segment yazmaçları ile bellek alanlarının bölümlenmesi anlatılır.
- Kod ve veri ayrımı
  - Alt seviye programlamanın en temel prensiplerinden biri olan kod ve verinin hafızada farklı bölgelerde tutulması ele alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Assembly dillerinin donanıma doğrudan erişim gücü
  - Doğrudan erişimin sağladığı hız ve esnekliğin yanında getirdiği sorumluluklar.
- Registerların kısıtlı kaynaklar olması
  - Belleğe kıyasla son derece sınırlı olan bu yazmaçların verimli şekilde yönetilmesi gerekliliği.
- Hafızaya doğrudan erişimlerin taşıdığı riskler
  - Hatalı adreslemelerin program veya sistem kararsızlığına yol açabileceği uyarısı.

## Kısa Tekrar Notları

- Assembly donanıma en yakın programlama dillerinden biridir.
- 8086 işlemcisinde 16-bit registerlar bulunur. AX genel amaçlı akümülatördür.
- Hafıza adreslemesinde segment ve offset değerleri bir arada kullanılır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Assembly dilleri, yüksek seviyeli dillerin aksine donanım mimarisine doğrudan bağımlıdır. 8086 mikroişlemcisi, 16-bitlik bir mimariye sahiptir ve x86 mimarisinin temelini oluşturur. İşlemci içinde genel amaçlı yazmaçlar (AX, BX, CX, DX) bulunur. AX (Accumulator) aritmetik işlemler, BX (Base) adresleme işlemleri, CX (Counter) döngü sayaçları, DX (Data) ise giriş/çıkış ve büyük çarpma/bölme işlemleri için özelleşmiştir. Hafıza organizasyonunda segment-offset yapısı (Segmentation) kullanılır. CS (Code Segment) kod alanını, DS (Data Segment) veri alanını, SS (Stack Segment) yığın alanını ve ES (Extra Segment) ek veri alanlarını gösterir. Kod ve veri alanlarının birbirinden fiziksel veya mantıksal olarak ayrılması, güvenlik ve program bütünlüğü açısından kritik bir alt seviye programlama prensibidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
