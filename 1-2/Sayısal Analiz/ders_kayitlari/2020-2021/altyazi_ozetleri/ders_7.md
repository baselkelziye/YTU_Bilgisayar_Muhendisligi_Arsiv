# Ders 7 Çalışma Özeti

## Genel Konular

- Cholesky yöntemi
  - Simetrik pozitif tanımlı matrisler için LU ayrıştırmasının özel bir durumudur.
  - Matris A, L × Lᵀ şeklinde ayrıştırılır; burada L alt üçgen, Lᵀ üst üçgen matristir.
  - Normal LU ayrıştırmasına göre daha verimlidir çünkü sadece alt üçgen matrisin hesaplanması yeterlidir.
- Cholesky öncesi tekrar: LU ayrıştırması
  - Gauss eliminasyonu ile matrisin üst üçgen forma getirilmesi.
  -LU ayrıştırmasında matris A = L × U biçiminde ifade edilir.
  - Crout yöntemi: L matrisinin köşegen elemanları 1 olarak sabitlenir.
- Sınav hazırlığı
  - Gelecek hafta sınav yapılacaktır.
  - Sınav klasik usulde, 4-5 soru ile yapılacaktır.
  - Çözümlerin okunabilir olması ve PDF olarak taranması zorunludur.
  - Online sistem dışında mail ile gönderilen dosyalar kabul edilmeyecektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Cholesky yönteminin hangi durumlarda tercih edildiği vurgulandı: simetrik ve pozitif tanımlı matrisler için.
- Sınavda PDF formatı zorunlu; resim dosyası olarak gönderilenler eksik değerlendirilecektir.
- Sistemde dosya yükleme işlemleri için yeterli süre ayrılmalı; son dakika yüklemesi risklidir.
- Sınav sonrası yükleme listesi ilan edilecek; listede adı olmayanlar kanıtla birlikte mail atmalıdır.

## Kısa Tekrar Notları

- Cholesky: A = L × Lᵀ (simetrik pozitif tanımlı matrisler için).
- LU ayrıştırması: A = L × U; Gauss eliminasyonu ile elde edilir.
- Crout yöntemi: L'nin köşegen elemanları 1'dir.
- Sınav: klasik, 4-5 soru, PDF zorunlu, okunabilirlik önemli.

## Detaylı Açıklamalar

Bu derste Cholesky yöntemi ele alındı. Cholesky, LU ayrıştırmasının özel bir durumu olup sadece simetrik ve pozitif tanımlı matrisler için uygulanabilir. Bu yöntemde matris A, L × Lᵀ biçiminde ayrıştırılır; burada L alt üçgen matristir ve Lᵀ onun transpozudur. Normal LU ayrıştırmasına göre daha verimlidir çünkü sadece alt üçgen matrisin hesaplanması yeterlidir.

Cholesky öncesinde LU ayrıştırması tekrar edildi. Gauss eliminasyonu kullanılarak matris üst üçgen forma getirilir ve ardından L ve U matrisleri elde edilir. Crout yönteminde L matrisinin köşegen elemanları 1 olarak sabitlenir.

Sınav hazırlığı konusunda detaylı bilgi verildi. Sınav klasik usulde, 4-5 soru ile yapılacaktır. Çözümlerin okunabilir olması ve PDF olarak taranması zorunludur. Online sistem dışında mail ile gönderilen dosyalar kabul edilmeyecektir. Sınav sonrası yükleme listesi ilan edilecek; listede adı olmayanlar kanıtla birlikte mail atmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
