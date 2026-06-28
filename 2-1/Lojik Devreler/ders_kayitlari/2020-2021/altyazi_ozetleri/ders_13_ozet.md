# Ders 13 Çalışma Özeti

## Genel Konular

- Register yapıları
  - Register, birden fazla flip-flop kullanarak çok bitli veri saklayan devredir.
  - Paralel yükleme, kaydırma ve temizleme gibi kontrol girişleri bulunabilir.
- Kaydırmalı registerlar
  - Veri seri veya paralel biçimde girip çıkabilir.
  - Sağa/sola kaydırma işlemleri bitlerin konumunu saat darbeleriyle değiştirir.
- Sayaç ve register ilişkisi
  - Flip-flop tabanlı yapılar hem sayma hem saklama amacıyla kullanılabilir.
- Senkron/asenkron kontrol girişleri
  - Clear, preset, load gibi girişlerin saatle ilişkisi devre davranışını belirler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Registerlarda her bit bir flip-flop ile saklanır.
  - Çok bitli veri için flip-floplar birlikte çalışır.
- Kaydırma işlemi veri aktarım yönüne göre yorumlanmalıdır.
  - Seri giriş ve seri çıkış yapıları bit akışını zamana yayar.
- Kontrol girişlerinin önceliği ve senkron/asenkron oluşu tasarımda önemlidir.

## Kısa Tekrar Notları

- Register = çok bitli saklama elemanı.
- Shift register bitleri saat darbeleriyle kaydırır.
- Paralel yükleme tüm bitleri aynı anda alır.
- Seri giriş/çıkış veri aktarımını bit bit yapar.
- Clear/preset/load girişleri davranışı değiştirir.

## Detaylı Açıklamalar

- Registerlar dijital sistemlerde geçici veri saklamak için kullanılır. Her flip-flop bir biti tutar; dört bitlik register için dört flip-flop gerekir. Saat işaretiyle veri saklanır veya güncellenir.
- Kaydırmalı registerlar, saklanan bitleri her saat darbesinde bir konum sağa veya sola taşır. Bu yapı seri-paralel dönüşüm, veri geciktirme ve basit aritmetik kaydırma işlemlerinde kullanılabilir.
- Paralel yüklemeli registerlarda tüm bitler aynı anda register içine alınır. Seri girişli yapılarda ise veri bit bit alınır ve istenen konuma kaydırılır.
- Kontrol girişlerinin senkron veya asenkron olması önemlidir. Asenkron clear gibi girişler saat beklemeden register içeriğini değiştirebilirken, senkron load saat kenarında etkili olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
