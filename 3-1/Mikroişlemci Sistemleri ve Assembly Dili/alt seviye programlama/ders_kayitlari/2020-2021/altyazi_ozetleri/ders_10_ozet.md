# Ders 10 Çalışma Özeti

## Genel Konular

- Alt programlar (Procedures) ve modüler programlama
  - PROC, CALL ve RET komutları ile alt program yapısı ve programın parçalara ayrılması ele alınır.
- Makro (MACRO) tanımı ve kullanımı
  - Makro tanımlama kuralları ve parametrik makro yapısı anlatılır.
- Alt program ve makro arasındaki temel farklar
  - Kod boyutu, çalışma süresi, stack kullanımı ve derleyici seviyesindeki açılımlar üzerinden karşılaştırma yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Alt program çağrılarında geri dönüş adresinin stack'e kaydedilmesi
  - CALL komutunun sonraki talimat adresini stack'e atıp RET komutunun bu adresi stack'ten geri yüklemesi süreci.
- Makroların derleme aşamasında kod açılımı yapması
  - Makronun koda doğrudan kopyalanarak çalışma zamanında dallanma maliyeti getirmemesi, buna karşılık program boyutunu büyütmesi (Macro Expansion).

## Kısa Tekrar Notları

- Yordamlar PROC ile başlar, RET ile biter.
- CALL yordamı çağırır ve dönüş adresini stack'e atar.
- Makrolar koda doğrudan kopyalanır, yordam çağrısı gibi dallanma yapmaz.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Alt programlar (Procedures) ve makrolar, kodun modülerliğini ve tekrar kullanılabilirliğini sağlar. Yordamlar PROC direktifi ile tanımlanır, CALL komutuyla çağrılır ve RET komutuyla sonlandırılır. CALL komutu, bir sonraki talimatın adresini (IP veya CS:IP) stack'e kaydeder ve yordamın başlangıç adresine dallanır; RET ise bu adresi stack'ten çekip IP'ye geri yazar. Makrolar ise MACRO direktifi ile tanımlanır. Derleyici, makro çağrılarını gördüğü her yerde makro içeriğini doğrudan kodun içine yapıştırır (Macro Expansion). Makrolar çalışma zamanında (runtime) alt program çağırma maliyeti (stack ve dallanma süresi) getirmez ancak kod boyutunu büyütür. Yordamlar ise bellek tasarrufu sağlar fakat stack yönetimi ve dallanma maliyeti barındırır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
