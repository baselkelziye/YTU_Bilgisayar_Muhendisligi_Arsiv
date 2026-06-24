# Ders 5 Lab Çalışma Özeti

## Genel Konular

- Algoritmik karmaşıklık tekrarı
  - Önceki haftalarda işlenen karmaşıklık hesaplarının uygulama soruları için nasıl kullanılacağı konuşulur.
- Stack ve queue uygulama hazırlığı
  - Yığın ve kuyruk yapılarının kodlama ödevlerinde kullanılabilecek temel işlemleri hatırlatılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kodlama yaparken veri yapısının temel kuralı korunmalıdır.
  - Stack için LIFO, queue için FIFO davranışı bozulursa çözüm doğru veri yapısını kullanmış sayılmaz.
- Karmaşıklık analizi uygulama kodundan kopuk düşünülmemelidir.
  - Yazılan her döngü ve veri yapısı işlemi maliyete etki eder.

## Kısa Tekrar Notları

- Stack ve queue işlemleri sabit zamanda tasarlanabilir.
- Karmaşıklık hesabı kodun döngü ve işlem yapısına göre yapılır.
- Veri yapısı davranışı test senaryolarıyla kontrol edilmelidir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Bu uygulama kaydı, stack ve queue konularının kodlama tarafına hazırlık niteliğindedir. Akademik olarak öne çıkan nokta, veri yapısının soyut davranışı ile implementasyon ayrıntılarının birlikte düşünülmesidir. Bir yığın diziyle de bağlı listeyle de kurulabilir; ancak dışarıdan görülen davranışın son giren ilk çıkar olması gerekir. Benzer şekilde kuyrukta ekleme ve çıkarma uçlarının ayrılması FIFO düzenini korur.
