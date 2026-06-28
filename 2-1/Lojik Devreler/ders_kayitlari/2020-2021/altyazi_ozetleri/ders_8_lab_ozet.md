# Ders 8 Lab Çalışma Özeti

## Genel Konular

- Minterm ve maksterm ifadeleri
  - Fonksiyonun `1` olduğu satırlar minterm toplamıyla, `0` olduğu satırlar maksterm çarpımıyla gösterilir.
  - İki gösterim aynı fonksiyonu farklı açıdan tanımlar.
- Karnaugh haritası kullanımı
  - `1` grupları üzerinden çarpımlar toplamı, `0` grupları üzerinden toplamlar çarpımı elde edilebilir.
- Devre gerçekleme
  - Sadeleşen fonksiyon, kapı düzeyinde veya tek tip kapılarla kurulabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Minterm ve maksterm karıştırılmamalıdır.
  - Minterm `1` satırlarını, maksterm `0` satırlarını esas alır.
- Karnaugh haritasında doğru satır/sütun yerleşimi sonuç için kritiktir.
- Devrenin doğruluk tablosu ile uyumlu olması gerekir.

## Kısa Tekrar Notları

- `Σm`: minterm toplamı.
- `ΠM`: maksterm çarpımı.
- `1`leri grupla: SOP elde edilir.
- `0`ları grupla: POS elde edilir.
- Simülasyon sonucu tabloyla karşılaştırılır.

## Detaylı Açıklamalar

- Laboratuvar içeriği, fonksiyonun iki kanonik biçimini uygulamalı olarak kullanmayı hedefler. Minterm biçimi, fonksiyonun hangi satırlarda `1` olduğunu doğrudan gösterir. Maksterm biçimi ise fonksiyonun `0` olduğu satırlar üzerinden kurulur.
- Karnaugh haritası iki biçimi de sadeleştirmek için kullanılabilir. `1`lerin gruplandırılması çarpımlar toplamı biçiminde sade terimler verirken, `0`ların gruplandırılması toplamlar çarpımı biçiminde sade çarpanlar verir.
- Devre kurulumunda seçilen sade biçime uygun kapı yapısı tercih edilir. SOP genellikle AND-OR veya NAND-NAND, POS ise OR-AND veya NOR-NOR yapısına uygundur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
