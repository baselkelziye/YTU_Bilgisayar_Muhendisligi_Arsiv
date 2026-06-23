# Ders 3 Çalışma Özeti

## Genel Konular

- Dallanma ve Karşılaştırma komutları
  - Koşulsuz dallanma (JMP) ve koşullu dallanma (JE, JNE, JZ, JNZ, JG, JL vb.) komutları tanıtılır.
- Matematiksel ve mantıksal işlemler
  - ADD, SUB, MUL, DIV, AND, OR, XOR, NOT gibi temel ALU komutları ele alınır.
- Karşılaştırma (CMP) komutu ve Flags register'ının rolü
  - CMP komutunun çıkarma işlemi yapıp sonucu kaydetmeden sadece durum bayraklarını (ZF, SF, OF vb.) güncellemesi anlatılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Koşullu dallanmaların Flags register'ı üzerindeki bit durumlarına bağlılığı
  - Akış kontrolünün tamamen durum bayraklarındaki bitlerin (0 veya 1) durumuna göre yönlendirildiği.
- Çarpma (MUL) ve bölme (DIV) işlemlerinde örtük register kullanımı
  - 8-bit veya 16-bit işlemlerine göre AX, DX:AX gibi registerların otomatik olarak seçilmesi ve oluşabilecek taşma durumları.
- Kod okunabilirliği ve akışı
  - Dallanma bloklarının karmaşıklığı önleyecek şekilde düzenli yapılandırılması gerektiği.

## Kısa Tekrar Notları

- JMP koşulsuz, JE/JZ vb. koşullu dallanmadır.
- Çarpma ve bölmede AX (veya DX:AX) varsayılan olarak kullanılır.
- Karşılaştırma için CMP komutu kullanılır, bu komut arka planda çıkarma yapar ancak sonucu kaydetmez, sadece Flags register'ı etkiler.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Assembly'de akış kontrolü dallanma (Branching) komutları ile sağlanır. Koşulsuz dallanma için JMP komutu kullanılırler, koşullu dallanmalar (JE, JNE, JZ, JNZ, JG, JL, JGE, JLE) Flags register'ındaki durum bitlerini (Zero Flag - ZF, Sign Flag - SF, Overflow Flag - OF vb.) kontrol eder. Karşılaştırma işlemi CMP Hedef, Kaynak komutuyla yapılır. Bu komut, hedef değerden kaynak değeri çıkararak Flags register'ını günceller ancak sonucu kaydetmez. Matematiksel işlemlerden ADD ve SUB toplama ve çıkarma yaparken, MUL (işaretsiz çarpma) ve DIV (işaretsiz bölme) komutları örtük register kullanımı gerektirir. Örneğin, 8-bitlik çarpmada çarpan AL ile çarpılır, sonuç AX'e yazılır; 16-bitlik çarpmada AX ile çarpılır, sonuç DX:AX yazmaç ikilisinde tutulur. Bölme işleminde ise tam tersi bir bölünen yerleşimi mevcuttur ve sıfıra bölme hatası (Divide Overflow) donanımsal bir kesme tetikler.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
