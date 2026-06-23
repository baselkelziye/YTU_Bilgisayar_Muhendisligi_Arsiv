# Ders 7 Çalışma Özeti

## Genel Konular

- Data Segment ve Stack Segment yapısı
  - Program şablonundaki bellek alanlarının işlevleri anlatılır.
- Stack (Yığın) mimarisi ve işlemleri
  - LIFO (Last In First Out) mantığı ile çalışan yığında PUSH ve POP komutlarının kullanımı açıklanır.
- Değişkenlerin hafızadaki yerleşimi
  - Başlangıç değeri verilmeyen değişkenler için '?' kullanımı ve bellek hizalaması (alignment) ele alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Stack segmentinin çalışma mantığı
  - Yığının yukarıdan aşağıya (düşük adreslere doğru) büyümesi ve SP (Stack Pointer) register'ının bu doğrultuda yönetimi.
- SP register'ının yönetimi
  - Her PUSH işleminde SP'nin 2 azalması, her POP işleminde ise 2 artması kuralı.
- Başlangıç değeri atanmamış değişkenlerin bellek yerleşimi
  - Program boyutunu küçültmek amacıyla veri alanında sadece yer ayırma prensibi.

## Kısa Tekrar Notları

- Stack Last-In-First-Out (LIFO) çalışır.
- PUSH veriyi yığına yazar, SP azalır. POP veriyi yığından alır, SP artar.
- Başlangıç değeri atanmayan değişkenler '?' ile tanımlanır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Hafıza segmentleri, kod ve verinin mantıksal olarak ayrılmasını sağlar. Program şablonunda .CODE, .DATA ve .STACK direktifleri ile bu bölümler tanımlanır. Başlangıç değeri atanmayan değişkenler için ? sembolü kullanılarak sadece yer ayrılması sağlanır. Yığın (Stack) belleği, LIFO (Last In First Out - Son Giren İlk Çıkar) prensibiyle çalışan geçici bir depolama alanıdır. Stack işlemleri PUSH ve POP komutları ile yürütülür. PUSH komutu SP'yi (Stack Pointer) 2 azaltarak veriyi yığına yazar; POP komutu ise yığından veriyi okuyup SP'yi 2 artırır. Yığın, fonksiyon çağrılarında geri dönüş adreslerini saklamak, register durumlarını korumak ve lokal değişkenler oluşturmak için donanım tarafından otomatik olarak da kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
