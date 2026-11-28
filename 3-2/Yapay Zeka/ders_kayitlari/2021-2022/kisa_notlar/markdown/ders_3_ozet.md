# Ders 3 Çalışma Özeti

## Genel Konular

- Makine öğrenmesinin tanımı
  - Çok büyük miktardaki verinin elle işlenmesi ve analizi mümkün değildir; makine öğrenmesi metotları bu tür problemlere çözüm bulmak için geliştirilmiştir (ekrandan, 00:10:00).
  - Metotlar geçmişteki verileri kullanarak veriye en uygun modeli bulmaya çalışır, yeni gelen verileri de bu modele göre analiz edip sonuç üretir.
  - Tasarımcı bir model ailesi (algoritma) seçer; algoritma bu aile içinde veriye en uygun modeli, yani parametreleri bulur.
- Sınıflandırma
  - Elimizde özellikleri ($x_1, x_2, \dots$) ve sınıfı bilinen örnekler vardır; sınıfı bilinmeyen yeni bir örneğin sınıfı tahmin edilir (ekrandan, 00:15:00).
  - Banka kredisi örneği: $x_1$ maaş, $x_2$ aynı işte çalışma süresi; sınıflar krediyi ödeyen ve ödemeyen müşteriler.
  - Model olarak iki sınıfı ayıran bir doğru (lineer sınıflandırıcı), eksenlere paralel iki çizgi (karar ağacı benzeri) ya da bir parabol seçilebilir.
  - Veriye tam uyan sonsuz sayıda ayırıcı doğru çizilebilir; makine öğrenmesi problemlerinin çoğunda çözüm tek değildir.
  - Sınıflandırmayı belirleyen girdilerin tipi değil, çıktının tipidir: çıktı kategoriktir, sınıflar arasında büyüklük-küçüklük ilişkisi yoktur.
- Regresyon
  - Çıktı sayısaldır, çıktılar arasında büyüklük-küçüklük ilişkisi vardır (örnek: motor gücünden maksimum hızı tahmin etmek).
  - Lineer model: $\text{maksimum hız} = w_1 \cdot \text{motor gücü} + w_0$; iki girdi olunca model bir doğru değil bir düzlem olur.
  - Model doğrusal olmak zorunda değildir (eğri de uydurulabilir).
- Kümeleme
  - Girdiler vardır ama çıktı (etiket) yoktur; amaç örnekleri gruplara ayırmaktır. Küme sayısı verilebilir ya da verilmeyebilir.
  - Renk indirgeme örneği: 256 renkli bir resmi 16 renge indirmek (ekrandan, 00:35:00).
  - GSM operatörünün abonelerini kampanya için gruplaması; özellik olarak indirilen veri miktarı, yaş, cinsiyet, telefon markası, fatura, uygulama kullanımı önerildi.
- Pekiştirmeli öğrenme
  - Modele doğru çıktının ne olduğu söylenmez; yalnız yaptığının doğru ya da yanlış olduğu bildirilir (ikili geri bildirim). Genelde oyunlarda kullanılır.
- Birliktelik kurallarının keşfi (sepet analizi)
  - Girdi sepet içerikleridir; çıktı hangi ürünlerin birlikte bulunduğuna dair kurallardır.
- Günlük hayattaki uygulamalar
  - Dolar kuru tahmini (pencereli regresyon, zaman sırasına uygun eğitim/test), el yazısı ve kitap yazısı tanıma (HCR/OCR), kredi değerlendirme, e-ticarette kitap kümeleme ve öneri, gen mikrodizilimleri, iris, yüz, parmak izi, ses ve imza tanıma, spam filtreleri, güvenlik kamerası analizi, işaret dili tanıma, sürücüsüz araçlar (ALVINN), beyin aktiviteleri.
- Uygulamalardaki boyut ve örnek sayıları; verilerin sayısallaştırılması; örnek bir sınıflandırma uygulaması ile eğitim ve test kümesi kavramı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınıflandırma ile regresyonun farkı çıktının tipidir
  - Girdiler sayısal ya da kategorik olabilir; problemi sınıflandırma yapan şey çıktının kategorik olmasıdır. Sınıflar "1" ve "2" diye yazılsa bile aralarında sayısal ilişki yoksa problem sınıflandırmadır.
- Çözüm tek değildir
  - Aynı veriye mükemmel uyan sonsuz model olabilir; hangi modelin daha iyi olduğu ayrı bir konudur (örneğin SVM ile perseptron farklı doğrular bulabilir).
- Sınıflar arası fark büyük, sınıf içi fark (varyans) küçük olmalı
  - Sınıf merkezleri birbirinden uzaklaştıkça ve sınıflar daha dar bir alana toplandıkça problem kolaylaşır. El yazısında sınıf içi varyans büyük olduğu için problem kitap yazısına göre daha zordur.
- Hatalar simetrik değildir
  - Spam örneğinde istenen postanın spam'e düşmesi, istenmeyen postanın gelen kutusuna düşmesinden daha kötüdür; hastalık örneğinde hastaya "sağlam" demek, sağlama "hasta" demekten daha kötüdür. Kayıp fonksiyonu buna göre ayarlanabilir, ama bir hata türü azaltılınca diğeri artabilir.
- Modelin başarısı daha önce görmediği örneklerde ölçülür
  - Eğitim verisindeki başarı ezberi gösterebilir. Hoca, derste çözülen soruların aynısını sınavda sormanın öğrencinin bilip bilmediğini göstermeyeceği benzetmesini yapar.
- Zaman serisi verilerinde eğitim ve test rastgele bölünmemeli
  - Geçmiş veriyle eğitip sonraki dönemle test etmek gerçeğe daha yakın sonuç verir; rastgele bölmek iyimser sonuç üretir.

## Kısa Tekrar Notları

- Makine öğrenmesi: geçmiş veriden model (parametreler) öğrenip yeni veride tahmin yapma.
- Sınıflandırma: çıktı kategorik. Regresyon: çıktı sayısal. Kümeleme: çıktı yok, gruplama. Pekiştirmeli öğrenme: yalnız doğru/yanlış geri bildirimi. Birliktelik kuralları: birlikte bulunan öğeler.
- Kategorik girdiler 0/1 ya da one-hot encoding ile sayıya çevrilebilir; kategorileri 1, 2, 3, 4, 5 diye numaralandırmak uygun değildir.
- Karar ağaçları kategorik ve sayısal girdilerle çalışabilir; SVM yalnız sayısal girdi ister.
- $n$ bit ile $2^n$ farklı değer tutulur: 256 renk 8 bit, 16 renk 4 bit ister; bellek yarıya iner ama resim kalitesi düşer.
- Dolar kuru örneğinde pencere uzunluğu 3: son üç günün değerinden bugünün değeri tahmin edilir (regresyon).
- Ocak verisiyle eğit, şubat verisiyle test et; tersi gerçekçi değildir.
- Az örnek ve çok boyutlu uzayda güvenilir model kurmak zordur (örnek: biyoinformatik).
- 10x6'lık rakam resimleri 60 boyutlu vektörlerdir; 10 rakam x 10 font = 100 örnek, 100x60 matris. Rastgele 50 örnek eğitim, kalan 50 test kümesi olur.

## Detaylı Açıklamalar

- Makine öğrenmesinde tasarımcı bir model ailesi seçer, örneğin "iki sınıfı bir doğruyla ayır". Bu bir algoritma seçimidir: lineer regresyon, SVM ya da perseptron gibi yöntemlerin hepsi bir doğru bulmaya çalışır. Algoritma, verilen veriye göre bu ailedeki en uygun modeli bulur. Yeni bir örnek geldiğinde modelin hangi tarafında kaldığına bakılarak sınıfı tahmin edilir. Slayttaki örnekte iki boyutlu mavi ve siyah noktalar ile sınıfı bilinmeyen kırmızı bir nokta vardır (ekrandan, 00:15:00). Hoca, kırmızı noktanın sınıfının seçilen modele göre değişebileceğini gösterir. Bir doğruya göre "krediyi ver" sonucu çıkarken başka bir doğruya göre "verme" sonucu çıkabilir.
- Slayttaki tablo, beş örneğin beş özelliğini ($x_1 \dots x_5$) ve sınıfını gösterir (ekrandan, 00:15:00):

| x1 | x2 | x3 | x4 | x5 | Sınıf |
|---|---|---|---|---|---|
| 1.2 | 3.4 | 2.3 | 6.7 | 7.8 | A |
| 1 | 2 | 2 | 4 | 5 | A |
| 9 | 8 | 6 | 5 | 3 | B |
| 6 | 7 | 8 | 9 | 1 | B |
| 8 | 8 | 9 | 9 | 9 | B |

  Hoca sonra $x_2$ sütununu "Evet/Hayır" değerleriyle, sınıf sütununu "bir" ve "2" etiketleriyle değiştirir (ekrandan, 00:25:00). Böylece girdilerin kategorik olabileceğini ve sınıf adlarının yalnız isim olduğunu, aralarında sayısal ilişki bulunmadığını gösterir.
- Regresyon örneğinde girdi motor gücü, çıktı maksimum hızdır. Model $w_1 \cdot \text{motor gücü} + w_0$ biçiminde bir doğrudur; $w_0$ doğrunun sıfırdan geçme zorunluluğunu kaldırır. Motor torku gibi ikinci bir girdi $w_2$ ile eklenirse model üç boyutlu uzayda bir düzlem olur. Regresyonda hiçbir doğru bütün noktalardan geçmeyebilir; her örnek için gerçek değer ile modelin değeri arasındaki fark hatadır. <!-- BELİRSİZ: regresyon slaytındaki örnek değerler karelerde görünmüyor; 210, 230, 280 değerleri altyazıdan alındı. -->
- Kümelemede etiket olmadığı için veri daha kolay ve daha büyük hacimde toplanabilir. Sınıflandırmada ise her girdinin çıktısını insanların belirlemesi gerekir. Kümeleme çıktısındaki "A kümesi, B kümesi" adlarını algoritma kendisi koyar, kullanıcı tanımlamaz. 256 renkten 16 renge indirgemede her piksel bir RGB üçlüsüdür. Benzer üçlüler aynı kümeye toplanır ve her küme tek bir renkle temsil edilir.
- Varyans örneğinde iki sınıfın örnekleri iki daire içinden gelir (ekrandan, 01:15:00). Daireler birbirine yaklaşıp kesiştikçe problem zorlaşır. Merkezler arası uzaklık aynı kalıp daireler küçültülürse problem kolaylaşır. Sınıflar arası fark sınıf ortalamaları arasındaki farktır, sınıf içi fark ise varyanstır.
- Spam filtresinde istenen ve istenmeyen e-postalar ile tahmin edilen ve gerçek sınıflar bir tabloyla karşılaştırılır (ekrandan, 01:30:00). Köşegendeki doğru tahminlerin yüksek, köşegen dışındaki hataların düşük olması istenir. Hoca, spam filtrelerini kararın uzun süredir makinelere bırakıldığı bir alan olarak gösterir. Kararlar makinelere bırakılınca onları kandırmaya çalışan sistemler de ortaya çıkar: hem spamciler hem anti-spamciler makine öğrenmesi kullanır (ekrandan, 01:35:00).
- Örnek sınıflandırma uygulamasında bir kitap fotokopisindeki yazılar metne çevrilir. Önce satırlar, sonra harfler bulunur. Her harf için etiketli örneklerden bir veri tabanı kurulur. 10x6 piksellik bir rakam resmi 60 boyutlu bir vektördür. Veri eğitim ve test kümelerine bölünür, model eğitim kümesiyle kurulur ve başarısı test kümesindeki tahminlerin gerçek sınıflarla örtüşme oranıyla ölçülür (ekrandan, 02:15:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
