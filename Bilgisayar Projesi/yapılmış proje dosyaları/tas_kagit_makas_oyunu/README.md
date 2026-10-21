# Tas-Kagit-Makas-Oyunu

Günümüzde gelişen bilgisayar teknolojilerinde görüntü işleme önemli bir yer
tutmaktadır. Yüz ve vücut tanımlama ve tanıma, hareket algılama, seri üretimlerde
üretimin doğruluk kontrolü bunlardan sadece birkaç tanesini oluşturmaktadır. Oyun
piyasası da bu gelişimden etkilenerek özel kamera sistemleri ve hareket sensörleriyle
sanal bir gerçeklik yakalama çabası içindedir.

Video çerçevesi içerisinden belirli bir nesnenin görüntüsünün alınması ve
sınıflandırılması işlemi bir çok alanda kullanılmaktadır. Görüntü işleme yöntemleri
ile arkaplanın temizlenmesi ve nesnenin algılanması oldukça kolaylaştırılmış ve bir
çok sisteme entegre edilmiştir. Özellikle endüstriyel ve askeri alanlarda kullanılan
görüntü işleme yöntemleri, bu projede bir oyun geliştirmek için kullanılmaktadır. Bir
nesnenin arkaplandan ayrılması, HOG değerlerinin çıkartılması ve sınıflandırılması
işlemleri proje kapsamında kullanılan işlemler arasında yer almaktadır.


Bu projede amaç herkesin bildiği bir oyun olan taş-kağıt-makas oyununu, standart
bilgisayar kamerası ile görüntü işleme algoritmaları kullanarak bilgisayara karşı
oynamayı sağlayacak bir sistem geliştirmektir.
Projenin temel amacı bir video çerçevesi içerisinde eli algılamak, yapılan üç temel 
hareketi tanımlamak ve oluşturulan veritabanından bu hareketleri eşleştirmektir.

## Deneysel Sonuçlar

Proje belirli aralıklarda test işleminden geçmiştir. Bu test işlemleri ardından elde
sonuçlar aşagıda incelenmiştir.
HOG Description sonucunda oluşturulan vektörler eğitim kısmında veritabanına şeklin
etiketi (sınıf bilgisi) ile birlikte kaydedilmektedir. Bu aşamadan sonra oyun kısmında
kullanıcının yaptığı el şeklini, oluşturulan bu veritabanından K-NN ile en benzer 1
komşuluğa bakılarak tahmin etmeye çalışılmaktadır.
Proje kapsamında, bu veriler proje dışında bir programda test edilmiştir.
Weka
isimli bu progam ile yapılan testler sonucunda başarının ortalama %80 olduğu
gözlemlenmiştir. Proje içerisinde ise yeni gelen şeklin sınıflandırılması işlemi iki
şekilde karşılaştırılmıştır. Bunlar;

```
1) Kullanıcı eğitim yapmadan önce: Bu kısımda veritabanında kullanıcıya ait el
şekilleri bilgisi bulunmamaktadır. Başarı, eski kullanıcıların verileri üzerinden
test edilmiştir ve başarı %63-86 arasında değişim gösterdiği belirlenmiştir.
Confusion Matrix Tablo 7.1 ve Tablo 7.2’de gösterilmektedir.

Weka çıktı özetleri:

(a) Correctly Classified Instances 19 %63.3333
(b) Kappa statistic: 0.45
(c) Mean absolute error 0.2459
(d) Root mean squared error 0.4927
(e) Relative absolute error %55.3191
(f) Root relative squared error %104.5107
(g) Total Number of Instances 30


Tablo 7.1 Confusion Matrix 1
| Taş | Kağıt | Makas |           |
|:---:|:-----:|:-----:|:---------:|
|  3  |   7   |   0   |    Taş    |
|  0  |   10  |   0   |   Kağıt   |
|  0  |   4   |   6   |   Makas   |

(a) Correctly Classified Instances 26 %86.6667
(b) Kappa statistic 0.8
(c) Mean absolute error 0.0914
(d) Root mean squared error 0.2971
(e) Relative absolute error %20.5674
(f) Root relative squared error %63.0249
(g) Total Number of Instances 30

 
Tablo 7.2 Confusion Matrix 2
| Taş | Kağıt | Makas |           |
|:---:|:-----:|:-----:|:---------:|
|  9  |   1   |   0   |    Taş    |
|  0  |   10  |   0   |   Kağıt   |
|  0  |   3   |   7   |   Makas   |

``` 
```
 2. Kullanıcı eğitim yaptıktan sonra: Bu kısımda veritabanında kullanıcıya
    ait el ̧sekilleri bigisi halihazırda bulunmaktadır. Başarı, eski kullanıcıların
    verileri ve kendi verileri üzerinden test edilmi ̧stir ve ba ̧sarı %83-96 arasında
    değişim gösterdiği belirlenmiştir. Confusion Matrix Tablo 7.3 ve Tablo 7.4’de
    gösterilmektedir.
    Weka çıktı özetleri:

(a) Correctly Classified Instances 25 %83.3333
(b) Kappa statistic 0.75
(c) Mean absolute error 0.1133
(d) Root mean squared error 0.3322
(e) Relative absolute error %25.4967
(f) Root relative squared error %70.4793
(g) Total Number of Instances 30
 
 Confusion Matrix 3
| Taş | Kağıt | Makas |           |
|:---:|:-----:|:-----:|:---------:|
|  8  |   2   |   0   |    Taş    |
|  1  |   9   |   0   |   Kağıt   |
|  1  |   1   |   8   |   Makas   |
 
(a) Correctly Classified Instances 29 %96.6667
(b) Kappa statistic 0.95
(c) Mean absolute error 0.025
(d) Root mean squared error 0.1486
(e) Relative absolute error %5.6291
(f) Root relative squared error %31.5248
(g) Total Number of Instances 30

Confusion Matrix 4
| Taş | Kağıt | Makas |           |
|:---:|:-----:|:-----:|:---------:|
|  9  |   1   |   0   |    Taş    |
|  0  |   10  |   0   |   Kağıt   |
|  0  |   0   |  10   |   Makas   |
```
