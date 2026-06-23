# Ders 5 Çalışma Özeti

## Genel Konular

- Öteleme (Shift) ve döndürme (Rotate) komutları
  - SHL, SHR, SAR, SAL, ROL, ROR, RCL, RCR komutlarının çalışması incelenir.
- Mantıksal ve aritmetik öteleme farkları
  - Mantıksal ötelemede boşalan bitlere sıfır doldurulurken, aritmetik ötelemede işaret bitinin (MSB) korunması farkı ele alınır.
- Öteleme komutlarının hızlı çarpma ve bölme işlemlerinde kullanımı
  - 2'nin kuvvetleriyle çarpmada sola, bölmede sağa öteleme yapmanın hızı anlatılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Aritmetik sağa ötelemede (SAR) işaret bitinin (MSB) korunması
  - İşaretli sayılarda bölme yapılırken sayısal değerin işaretinin korunması için bu komutun şart olduğu.
- Döndürme komutlarında elde (carry) bitinin rolü
  - ROL/ROR ile RCL/RCR arasındaki farkın carry bayrağının (CF) döngüye dahil edilmesiyle oluştuğu.
- Performans kritik uygulamalarda çarpma/bölme yerine öteleme kullanımı
  - Öteleme komutlarının işlemci saat çevrimi (T-states) açısından MUL/DIV komutlarına kıyasla katbekat daha hızlı çalışması.

## Kısa Tekrar Notları

- SHL/SHR mantıksal, SAL/SAR aritmetik ötelemedir.
- SAR işaret bitini korur, dolayısıyla işaretli sayılarda bölme için kullanılır.
- Öteleme komutları 2'nin kuvvetleriyle çarpmayı/bölmeyi hızlandırır. ROL/ROR döndürme, RCL/RCR carry ile döndürmedir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Öteleme (Shift) ve döndürme (Rotate) komutları, bit seviyesinde veri işleme, maskeleme ve hızlı matematiksel işlemler için kullanılır. SHL (Shift Left) ve SHR (Shift Right) mantıksal öteleme yaparken dışarıdan sıfır biti besler. SAL (Shift Arithmetic Left) mantıksal sola ötelemeyle aynı çalışırken, SAR (Shift Arithmetic Right) en anlamlı biti (işaret bitini - MSB) koruyarak sağa öteleme yapar. Bu durum, işaretli sayıları 2'ye bölmek için kritiktir. Döndürme komutlarında ROL (Rotate Left) ve ROR (Rotate Right) bitleri dairesel olarak kaydırır. RCL (Rotate through Carry Left) ve RCR (Rotate through Carry Right) komutları ise Carry Flag (CF) bitini de döngüye dahil eder. Öteleme komutları, çarpma (MUL) ve bölme (DIV) komutlarına kıyasla çok daha az saat çevrimi (T-states) harcadığı için 2'nin kuvvetleriyle yapılan işlemlerde optimizasyon amaçlı tercih edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
