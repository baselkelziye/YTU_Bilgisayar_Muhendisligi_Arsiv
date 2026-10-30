# Ders 6 Çalışma Özeti

## Genel Konular

- Bu kayıt kısa bir uygulama saatidir. Kaydın büyük bölümü uygulama organizasyonuyla ilgilidir.
- Akademik içerik olarak yalnızca yer karmaşıklığı (space complexity) kavramına kısa bir hatırlatma yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir algoritma tasarlandıktan sonra hem işlem (zaman) karmaşıklığı hem de yer karmaşıklığı hesaplanmalıdır.
- Yer kullanımı da zaman kullanımı gibi olabildiğince verimli olmalıdır.
- Problem önce kendi başına, algoritmik düşünülerek çözülmelidir.

## Kısa Tekrar Notları

- Yer karmaşıklığı, işlem karmaşıklığıyla aynı mantıkla hesaplanır.
- Ölçü, giriş boyutu $n$'ye bağlı olarak algoritmanın ne kadar ek yer kullandığıdır.
- $n$ elemanlı bir girişte bir dizilik ($n$ gözlü) ek yer kullanılıyorsa yer karmaşıklığı $O(n)$ olur.

## Detaylı Açıklamalar

### Yer karmaşıklığı (space complexity)

- İşlem karmaşıklığında, $n$ giriş için kaç adım yapıldığı sayılır.
- Yer karmaşıklığında, $n$ giriş için algoritma sonunda ne kadar yer kullanıldığı hesaplanır.
- Hocanın örneği:
  - $n$ elemanlı bir giriş için bir dizilik yer kullanılıyorsa yer karmaşıklığı $O(n)$'dir.
  - Bu açıdan iki hesap arasında "çok büyük bir fark yoktur": ikisi de $n$'ye bağlı büyüme hızını ifade eder.
- Bir çözümün değerlendirilmesinde hem zamanın hem de yerin ne kadar verimli kullanıldığı önemlidir.

### Ders sonrası notlar

- Yer karmaşıklığı genellikle girişin kendisi dışında kullanılan ek bellek (auxiliary space) için verilir. Girişi saklayan dizi de sayılırsa, her algoritma en az $O(n)$ yer kullanmış olur. Hangi tanımın kullanıldığı soruda belirtilmelidir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
