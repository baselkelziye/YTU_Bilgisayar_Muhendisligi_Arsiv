# Ders 9 Çalışma Özeti

## Genel Konular

- Döngü yapıları ve LOOP komutu
  - LOOP komutunun CX register'ını otomatik olarak bir azaltarak sıfır olana kadar dallanma yapması anlatılır.
- Koşullu döngüler
  - Zero Flag (ZF) durumuna da bakan LOOPE/LOOPZ ve LOOPNE/LOOPNZ komutları tanıtılır.
- Yığın işlemlerinin döngülerle birleşimi
  - İç içe döngülerde veya döngü içinde register durumlarını korumak için stack kullanımı gösterilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- LOOP komutunun CX register'ına bağımlılığı
  - Döngü sayacının otomatik olarak CX üzerinden yönetildiği ve CX'in manuel değiştirilmesinin döngü akışını etkileyeceği.
- Büyük döngülerde veya iç içe döngülerde register çakışmalarını önlemek
  - İç içe döngülerde dış döngünün CX değerini bozmamak için yığına (stack) PUSH edilip iç döngü çıkışında POP edilmesinin kritik önemi.

## Kısa Tekrar Notları

- LOOP döngüsü CX register'ına bağlı çalışır.
- Her adımda CX azalır ve sıfır değilse hedef adrese dallanır.
- İç içe döngülerde dış döngünün CX değeri stack'te saklanır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Assembly'de döngüler LOOP komutu ile kurulur. LOOP Hedef komutu çalıştırıldığında, CX register'ının değeri otomatik olarak 1 azaltılır. Eğer CX sıfır değilse, belirtilen hedef etikete kısa dallanma (short jump -128 ile +127 byte sınırlarında) yapılır. Koşullu döngüler olan LOOPE/LOOPZ (Zero Flag 1 ve CX sıfır değilse döngüye devam et) ve LOOPNE/LOOPNZ (Zero Flag 0 ve CX sıfır değilse döngüye devam et) daha karmaşık arama ve karşılaştırma döngülerinde kullanılır. Döngülerin içinde register çakışmalarını (özellikle CX'in iç içe döngülerde bozulmasını) engellemek için dış döngünün sayacı stack'e push edilir, iç döngü bittiğinde pop edilerek geri yüklenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
