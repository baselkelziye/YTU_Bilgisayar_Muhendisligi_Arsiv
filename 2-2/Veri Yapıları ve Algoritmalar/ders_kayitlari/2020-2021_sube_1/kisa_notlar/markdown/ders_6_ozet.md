# Ders 6 Çalışma Özeti

## Genel Konular

- Bu kayıt kısa bir oturumdur.
- Akademik içerik olarak yalnızca yer karmaşıklığı (space complexity) kavramına kısa bir hatırlatma yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir algoritma tasarlandıktan sonra hem işlem (zaman) karmaşıklığı hem de yer karmaşıklığı hesaplanmalıdır.
- Yer kullanımı da zaman kullanımı gibi olabildiğince verimli olmalıdır.

## Kısa Tekrar Notları

- Yer karmaşıklığı, işlem karmaşıklığıyla aynı mantıkla hesaplanır.
- Ölçü, giriş boyutu $n$'ye bağlı olarak algoritmanın ne kadar yer kullandığıdır.
- $n$ elemanlı bir girişte bir dizilik ($n$ gözlü) yer kullanılıyorsa yer karmaşıklığı $n$ mertebesindedir.

## Detaylı Açıklamalar

### Yer karmaşıklığı (space complexity)

- Yer karmaşıklığında, $n$ giriş için algoritma sonunda ne kadar yer kullanıldığı hesaplanır. Hoca bunun işlem karmaşıklığından farklı olmadığını söyler.
- Hocanın örneği:
  - $n$ elemanlı bir giriş için bir dizilik yer kullanılıyorsa yer karmaşıklığı $n$'dir. Hoca bu açıdan iki hesap arasında "çok büyük bir fark" olmadığını söyler.
- Bir çözümde hem zamanın hem de yerin verimli kullanılması önemlidir.

### Ders sonrası notlar

- Hoca "n" ifadesini kullanır; $O(n)$ gösterimi bu nota eklenmiştir. Yer karmaşıklığı genellikle girişin kendisi dışında kullanılan ek bellek (auxiliary space) için verilir. Girişi saklayan dizi de sayılırsa, her algoritma en az $n$ mertebesinde yer kullanmış olur. Hangi tanımın kullanıldığı soruda belirtilmelidir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
