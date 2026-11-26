# Ders 9 Genişletilmiş Notu: Diferansiyel Denklemlerle Sistem Modelleme ve Fourier Serilerine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri: Zaman Düzleminden Dönüşüm Düzlemlerine
- 2. Konvolüsyonun Zorluğu
- 3. Sistem Modelleme ve Diferansiyel Denklemler
- 4. Basit Devre Örneği: İki Bilgisayar Arasındaki Kablo
- 5. Diferansiyel Denklemlerin Sınıflandırılması ve Çözümü
- 6. Dönüşümlerin Getirdiği Kolaylık
- 7. Fourier İşlemlerine Genel Bakış
- 8. Euler Bağıntısı ve Karmaşık Sinüzoidler
- 9. Sürekli Zaman Fourier Serisi (CTFS)
- 10. Fourier Dönüşümüne Kısa Giriş
- 11. Temel Frekans ve Fourier Serisinin Biçimleri
- 12. Uygulama: Periyodik Gürültünün Giderilmesi
- 13. Fourier Katsayılarının Analitik Bulunması
- Örnek Sorular

## 1. Dersin Yeri: Zaman Düzleminden Dönüşüm Düzlemlerine

Ders, önceki derslerde gelinen noktanın özetiyle başladı. Şimdiye kadar yapılan işlemler zaman düzlemindeydi: sürekli zamanda $t$ düzleminde, ayrık zamanda $n$ düzleminde. Sinyallerin özellikleri (öteleme, ters çevirme vb.), sistemlerin özellikleri ve özellikle doğrusal, zamanla değişmez (LTI) sistemler incelendi; bir girişe karşılık çıkış konvolüsyonla hesaplandı.

Hoca dersin akışını iki kola ayırdı: sürekli zaman ve ayrık zaman. Sürekli zaman tarafında MATLAB'in Simulink arayüzü gibi araçlar, ayrık zaman tarafında kod yazma ön plandadır; ders ikisini de deneyimletmeyi amaçlar. Giriş kısmı (zaman düzleminde sinyal ve sistem özellikleri) bitmiştir. Bundan sonra zaman düzleminde yapması zor olan işlemlerin farklı düzlemlerde, yani frekans düzleminde, $z$ düzleminde ve $s$ düzleminde yapılıp yapılamayacağı incelenecektir.

Hoca derste kullanılacak slaytların sırasına da değindi: örnekleme (sampling) konusu, Fourier konuları görülmeden anlamlı olmadığından sonraya bırakıldı. Bu derste Fourier konusuna geçiş yapıldı ve M. J. Roberts'ın slaytlarından da yararlanıldı. Hoca bu teorinin ileride makine öğrenmesi gibi alanlarda da karşılarına çıkacağını belirtti.

## 2. Konvolüsyonun Zorluğu

Sürekli zamanda konvolüsyon integralinin içinde iki fonksiyonun çarpımı vardır. Hoca bu iki fonksiyon karmaşık olduğunda integrali almanın "başlı başına bir zulüm" olduğunu söyledi.

Ardından öğrencilere integral sınırlarının neye göre değiştiğini sordu. Cevap gelmeyince hatırlattı: iki dikdörtgen darbenin konvolüsyonunda biri ters çevrilip kaydırılırken iki sinyalin belli bir miktar örtüştüğü görülmüştü. Bu örtüşme miktarını, sinyallerin **kritik noktaları** (süreksizlik noktaları, başlangıç ve bitiş noktaları) belirler. Sürekli zamandaki bir sinyal $-\infty$'dan $+\infty$'a uzandığı için "başlangıç-bitiş" demek tam doğru değildir; "kritik nokta" demek daha doğrudur. Bu noktalar yüzünden integral parçalara ayrılır ve her parça ayrı çözülür.

Hocanın sorusu şuydu: Bu dertten kurtulup işlemi daha kısa yoldan yapmak mümkün mü? Sinyaller ve Sistemler'de bu mümkündür ve dersin bundan sonraki kısmı bununla ilgilidir.

## 3. Sistem Modelleme ve Diferansiyel Denklemler

### 3.1 Matematik Modelin Gerekliliği

Mühendislik tasarımı yapabilmek için bir devrenin ya da başka bir sistemin davranışını sayısal olarak doğru öngörebilmek gerekir. Bunun için matematik modeller kullanılır. Slaytta bu fikir iki alan üzerinden gösterildi (ekrandan, 00:10:00):

| Alan | Eleman kuralları | Sistem kuralları | Sonuç |
|---|---|---|---|
| Devreler | $R$: $v(t)=Ri(t)$; $L$: $v(t)=L\,\frac{di(t)}{dt}$; $C$: $\frac{dv(t)}{dt}=\frac{1}{C}i(t)$ | KVL, KCL, gerilim bölücü vb. | Diferansiyel denklem |
| Mekanik | Kütle: $M\frac{d^2p(t)}{dt^2}$; Yay: $k_s\,p(t)$; Sönümleme: $k_d\frac{dp(t)}{dt}$ | Kuvvetlerin toplamı vb. | Diferansiyel denklem |

Hidrolik ve kimyasal sistemler için de benzer fikirler geçerlidir. Slaytın vurgusu: "differential equations rule the world" (diferansiyel denklemler dünyayı yönetir).

> **Ders sonrası not:** Slaytta bobin kuralı $v(t)=L\,(di(t)/di)$ diye yazılmış; doğrusu $v(t)=L\,\frac{di(t)}{dt}$'dir. Tabloya doğru biçim yazıldı.

Hoca direnç örneğini açtı: direnç üzerindeki gerilim, zamana bağlı akım ile direncin çarpımıdır. Bu da bir sistemdir: $i$ ve $R$'yi alır, $v(t)$'yi verir. Bobin ve kondansatörde türev bulunduğu için diferansiyel denklemler ortaya çıkar. Gerçek hayatta çoğu şey zamanla değiştiğinden giriş de çıkış da zamanla değişir; bu yüzden sürekli zamanda diferansiyel denklemlerle, ayrık zamanda fark denklemleriyle karşılaşılır.

### 3.2 Diferansiyel Denklem Ne Demektir?

**Soru:** Diferansiyel denklemi türev ile integral arasında nereye koymalıyız? **Cevap:** Hoca önce cebirsel bir denklem sistemi yazdı: $x+y=5$, $2x-3y=-10$ (ekrandan, 00:15:00). Bu tür denklemler taraf tarafa toplama ve çıkarma gibi yıllardır bilinen tekniklerle çözülür. Sonra uydurma bir örnek yazdı: $y'+\int_{x=1}^{8}\left(x^2+y'\right)dx=0$ (ekrandan, 00:15:00). Burada bilinmeyenin türevi ve integrali birlikte yer alır; bu tür denklemleri çözmek birinci ya da ikinci dereceden cebirsel denklemleri çözmek kadar kolay değildir ve kendine özgü teknikleri vardır.

> **Ek bilgi (derste anlatılmadı):** Cebirsel sistemin çözümü $x=1$, $y=4$'tür. Hocanın yazdığı, hem türev hem integral içeren denklemlere genellikle integro-diferansiyel denklem denir; yalnız türev içeren denklemler diferansiyel denklemdir.

**Soru:** İntegral türevin tersi değil mi? **Cevap:** Tersidir, ama burada bağımlı ve bağımsız değişken ayrımı vardır: bir fonksiyonun türevi, başka bir değişkene bağlı terimlerle birlikte integrale girer. Bu yüzden çözüm basit bir ters işlemle bulunmaz.

Hoca, bu denklemlerin MATLAB gibi araçlarla çözüm tekniklerini bilmeden de sembolik olarak çözülebildiğini söyledi; tıpkı programlama dillerinde $x+y=5$, $2x-3y=-10$ sistemini "çöz" deyip $x$ ve $y$'yi bir vektör olarak almak gibi. Bilgisayar mühendisi için diferansiyel denklem bir araçtır; asıl önemli olan, ne yapılması gerektiğini ve bunun ne kadar gerektiğini anlamaktır.

## 4. Basit Devre Örneği: İki Bilgisayar Arasındaki Kablo

### 4.1 Fiziksel Sistem

Slaytta iki bilgisayar arasında kabloyla bilgi gönderilmesi ele alındı (ekrandan, 00:15:00). Yalıtkanla ayrılmış iki iletken bir kapasitans oluşturur. İki pratik kablo örneği verildi:

- Yalıtılmış tellerden oluşan burgulu çift (twisted pair): tipik değerler $100\ \Omega/\text{km}$ ve $50\ \text{nF/km}$.
- Koaksiyel kablo: iletkenler bir yalıtkanla ayrılmıştır.

Ayrıca direncin kablo uzunluğuyla arttığı hatırlatıldı. Hoca, bir bilgisayardan ötekine veri aktarılırken mutlaka kayıp olacağını, bu kaybın modellenmesinin ya da kaybı en aza indiren kablonun tasarlanmasının ayrı bir problem olduğunu söyledi: parametreler, girişler ve çıkışlar belirlenip bir model kurulur.

Hoca burada Thevenin eşdeğerini ve devre teorisinden bilinen **maksimum güç aktarımı teoremini** hatırlattı: bir devreye bağlanacak yükün direnci, kaynak devrenin direncine eşit olduğunda en yüksek güç elde edilir.

### 4.2 Model ve Denklem

Bu kablonun davranışı bir RC devresiyle modellenir ve giriş-çıkış ilişkisi bir diferansiyel denklemle ifade edilir. Denklem sürekli zamanda olduğu için diferansiyel denklemdir; $n$ düzleminde olsaydı $y[n]$ gibi terimlerle kurulan bir fark denklemi olurdu. Bu denklem çözülürse sistemin davranışı ortaya çıkar: girişe ne verilirse çıkışın ne olacağı doğru biçimde tahmin edilir.

Hocanın vurguladığı süreç şöyledir:

```text
1. Fiziksel sistemi belirle (iki bilgisayar arasındaki kablo).
2. Davranışı veren devreyi kur (RC devresi).
3. Giriş-çıkış ilişkisini veren denklemi yaz (diferansiyel denklem).
4. Denklemi çöz: y(t)'yi türevsiz ve integralsiz olarak x(t) cinsinden bul.
5. İstenen x(t) girişini yerine koyup çıkışı hesapla, sistemi test et.
```

Denklemi kurmak daha çok kontrol mühendislerinin ve diğer alanlarda çalışanların işidir; denklem bulunduktan sonra iş onu çözmeye kalır. Çözüm bulunduktan sonra kodlamak, "giriş buysa çıkış budur" diyen bir fonksiyon yazmaktan farksızdır. Otomobil fren sistemi örneğinde de durum aynıdır: Newton yasalarından gelen daha yüksek mertebeden bir denklem çözüldükten sonra sistem ortaya konmuş olur.

### 4.3 Basit Model: Bit Dizisinin Yumuşaması

Slaytta kabloya verilen bir bit dizisinin çıkışı gösterildi (ekrandan, 00:20:00):

- Giriş $x(t)$: 0 ve 5 V seviyeleri arasında değişen bir dikdörtgen dalga; bit dizisi $0\ 0\ 1\ 1\ 0\ 1\ 0\ 1\ \dots$
- Çıkış bileşenleri: her geçiş anında başlayan $+5$ V ya da $-5$ V'luk basamaklar ve bunların kesikli çizgiyle gösterilen üstel olarak yükselen ya da düşen cevapları.
- Çıkış: bu bileşenlerin toplamıdır. Çıkış girişin "yumuşatılmış" bir hâlidir; "1"leri ve "0"ları ayırt etmek zorlaşır, sinyale gürültü eklenirse daha da zorlaşır.

Bu, doğrusallık ve süperpozisyonun pratik bir kullanımıdır: girişi basamaklara ayırıp her basamağın cevabını toplamak.

## 5. Diferansiyel Denklemlerin Sınıflandırılması ve Çözümü

### 5.1 Sınıflandırma

Diferansiyel denklemler, sistemlerde olduğu gibi çeşitli ölçütlerle sınıflandırılır:

- **Derece (mertebe):** Denklemdeki en yüksek türevin mertebesidir. Örneğin en yüksek türev üçüncü türevse denklem üçüncü mertebedendir.
- **Katsayılar:** Türevlerin önündeki $a_n$ katsayıları sabitse sistem zamanla değişmezdir (sabit katsayılı denklem).
- **Doğrusallık:** Doğrusal ve doğrusal olmayan denklemler.
- **Homojenlik:** Homojen ve homojen olmayan denklemler.
- **Adi ve kısmi:** Yalnız bir bağımsız değişkene göre türevler içeren denklem adi diferansiyel denklemdir (ordinary differential equation); birden fazla bağımsız değişkene göre kısmi türevler içeren denklem kısmi diferansiyel denklemdir.

Bağımsız değişken ($x$ ya da $t$) ve bağımlı değişken ($y$) ayrımı yapılır; türev içeren her denkleme diferansiyel denklem denir. Hoca, ayrık matematik dersinde aynı fikrin fark denklemleri olarak "recursion" (özyineleme) başlığı altında görüldüğünü hatırlattı.

> **Hocanın vurgusu:** Bu sınıflandırma ve çözüm ayrıntıları yalnız tanıtım amaçlıdır; bunlardan soru sorulmayacağını söyledi.

### 5.2 İkinci Mertebeden Bir Örnek

Çözüm yapılırken karmaşık sayılar ve trigonometri gerekir. Birinci mertebeden ve daha yüksek mertebeden denklemler için farklı teknikler vardır. Hoca, slayttaki ikinci mertebeden örneği en basitlerden biri olarak gösterdi (ekrandan, 00:25:00):

$$\frac{d^2y(t)}{dt^2}+3\frac{dy(t)}{dt}+2y(t)=\frac{df(t)}{dt},\qquad D^2y(t)+3Dy(t)+2y(t)=Df(t)$$

Başlangıç koşulları $y(0)=0$, $y'(0)=-5$'tir. Sıfır giriş (homojen) biçimi:

$$\frac{d^2y(t)}{dt^2}+3\frac{dy(t)}{dt}+2y(t)=0$$

Karakteristik denklem:

$$\lambda^2+3\lambda+2=0\ \Rightarrow\ (\lambda+1)(\lambda+2)=0$$

Hoca, karakteristik köklere göre çözümün yazıldığını, başlangıç değerleri verilmişse $C_1$ ve $C_2$'nin yerine konarak çözümün bulunduğunu söyledi. Sayısal çözüm Örnek Sorular bölümündedir.

## 6. Dönüşümlerin Getirdiği Kolaylık

### 6.1 Büyük Resim

Hoca büyük resmi şöyle özetledi: Giriş ile çıkış arasındaki ilişkiyi gösteren sistem modeli (denklemi) biliniyorsa, denklem çözülüp giriş-çıkış ilişkisi kodlanabilir ya da devre olarak tasarlanabilir. Diferansiyel denklem doğrudan çözülemiyorsa **dönüşümlerden** yararlanılır. Sinyaller ve Sistemler'de bu dönüşümler frekans düzlemine ya da başka bir düzleme geçişle yapılır. Dönüşümlerde de integral alınır, ama bunlar bilinen, basit integrallerdir; örneğin $e$ üzerinde bir ifadenin integralini almak kolaydır.

### 6.2 Konvolüsyonun Kodlanması

**Soru:** Konvolüsyonu kodlarken kaç iç içe döngü kullandınız? **Cevap:** İki. Çünkü tanım gereği iki farklı değişken vardır. Hoca bunu ekrana yazdı (ekrandan, 00:30:00):

$$\int f(t)\,x(t)\,dt\ \Rightarrow\ \sum f(t)\cdot x(t)$$

Birinci döngü $f$'in zaman indisiyle, ikinci döngü $x$'in zaman indisiyle ilgilenir. Bu algoritmik olarak zordur. Ama $f$ ve $x$'in frekans karşılıkları $F(\omega)$ ve $X(\omega)$ biliniyorsa ya da kolayca elde edilebiliyorsa, ikisi doğrudan eleman eleman çarpılır (ekrandan, 01:05:00):

$$Z(\omega)=F(\omega)\cdot X(\omega)$$

Böylece iki fonksiyonun çarpımının integralinden kurtulunur; tek bir fonksiyonun integraliyle uğraşılır, algoritmik karmaşıklık azalır ve işlem bilinen fonksiyonlar türünden yapılır. $Z(\omega)$'ya ters Fourier dönüşümü uygulanınca iki sinyalin konvolüsyonu zaman düzleminde elde edilir. Ters Fourier de basit bir integraldir.

**Soru (ödev bağlamında):** Konvolüsyonu MATLAB'in hazır `conv` komutuyla mı yapmalıyız, yoksa algoritmayı kendimiz mi yazmalıyız? **Cevap:** Konvolüsyon algoritması kendiniz tarafından yazılmalı ve sonucu hazır komutun sonucuyla kıyaslanmalıdır.

### 6.3 Dönüşümlerin Diğer Faydaları

Frekans düzlemine geçiş şu işlerde de kolaylık sağlar:

- Sistemlerin kararlılığının ya da zamanla değişip değişmediğinin kontrolü.
- Örüntü eşleme (pattern matching): bir yüz görüntüsünde belli bir bölgeyi ya da bir ses kaydında belli bir bölümü arama.
- Gürültü giderme: örneğin görüntüde gürültü giderme.

## 7. Fourier İşlemlerine Genel Bakış

### 7.1 Zaman ve Frekans Düzlemi

Bir sinyalin zaman düzlemindeki gösterimi yanında frekans düzleminde de bir karşılığı vardır. Bu düzleme geçiş Fourier serileri ya da Fourier dönüşümüyle yapılır. Hoca Fourier dönüşümünün genel denklemini yazdı (ekrandan, 01:05:00 ve 01:25:00):

$$X(\omega)=\int_{-\infty}^{+\infty}x(t)\,e^{-j\omega_0 t}\,dt$$

Burada $\omega_0$ yerine $2\pi f_0$ yazılabilir; $e^{-j\omega_0 t}$ yerine de Euler bağıntısıyla $\cos\omega_0 t - j\sin\omega_0 t$ ya da $\cos 2\pi f_0 t - j\sin 2\pi f_0 t$ yazılabilir. Böylece aynı ifade dört farklı biçimde görülebilir. Sonuç $X(f)$ ya da $X(\omega)$ biçimindedir ve sinyalin frekans düzlemindeki karşılığıdır.

Hoca, bir müzik tanıma uygulamasını anlatan bir web sayfasında zaman düzlemindeki bir sinyali ve onun frekans düzlemindeki eşdeğerini gösterdi (ekrandan, 00:35:00). Sayfadaki animasyonda 1 Hz'lik bir kare dalganın sinüzoidal bileşenlerden yaklaşık olarak üretildiği, üstte zaman düzleminde, altta frekans düzleminde (1, 3, 5, 7, ... Hz'de azalan tepeler) görülüyordu.

**Soru:** Frekans düzlemine geçince ne kazanacağız? **Cevap:** Konvolüsyonu kolay yapacağız; ayrıca bu verileri başka yerlerde özellik (feature) olarak kullanıp daha farklı anlamlar çıkaracağız. Örneğin zaman düzleminde bir dalganın frekansını hesaplamak zorken frekans düzleminde kolaydır. Ya da ideal bir kare dalgayı yüzde 90 doğrulukla bilinen sinyaller cinsinden nasıl yazacağımızı bulabiliriz.

Bilinen sinyaller doğal sinyallerdir: $\cos\omega_0 t$ gibi. Kosinüsün nasıl çalıştığı bilinir ve hemen her programlama dilinde $t$ yerine bir değer verip sonucunu almak mümkündür.

### 7.2 Seri mi, Dönüşüm mü?

Sinyaller frekans düzleminde incelenirken iki durum ortaya çıkar:

```text
Fourier işlemleri
├── Fourier serisi (Fourier series)
│   └── Sinyal periyodikse. Bir periyodu incelemek yeterlidir; hesap daha kolaydır.
└── Fourier dönüşümü (Fourier transform)
    └── Sinyal periyodik değilse (aperiyodik). -sonsuz ile +sonsuz arasında incelenir.

Her biri giriş sinyalinin türüne göre ikiye ayrılır:
    sürekli zaman (continuous time)  -> CTFS / CTFT
    ayrık zaman  (discrete time)     -> DTFS / DTFT
```

Kare dalga gibi periyodik bir sinyalde analitik çözümü $-\infty$'dan $+\infty$'a yapmaya gerek yoktur; bir periyodu incelemek bütün periyotları incelemiş olmak demektir.

### 7.3 Konvolüsyon Üzerinden Örnek

Hoca, iki sinyalin (örneğin $x(t)$ ve $e^{j\omega t}$) konvolüsyonu istendiğinde şu yolun izlendiğini anlattı: ikisinin ayrı ayrı Fourier dönüşümleri alınır, bu dönüşümler çarpılır, yeni bir $Z(\omega)$ bulunur ve ters Fourier dönüşümüyle zaman düzlemine geçilince konvolüsyon sonucu elde edilir. Zor integralleri kolay hâle getirmek dönüşümlerin en önemli faydasıdır.

## 8. Euler Bağıntısı ve Karmaşık Sinüzoidler

### 8.1 Doğal Sinyallerden Bilgi Okuma

Hoca, doğal sinyaller cinsinden yazılmış bir sinyalden frekans, genlik ve faz bilgisinin doğrudan okunabildiğini bir örnekle gösterdi (ekrandan, 01:05:00): $1\cdot\cos(500t+90^\circ)$. Burada genlik 1, faz $90^\circ$'dir ve $2\pi f t=500t$'den frekans bulunur. Kosinüsün zaman ekseninde $90^\circ$ kaydırılmış hâli sinüse karşılık gelir.

> **Ders sonrası not:** Hoca ve ekrandaki yazı $f=250$ Hz dedi. $2\pi f=500$ ise doğrusu $f=\frac{500}{2\pi}\approx 79.6$ Hz'dir; 250 Hz, $\pi$ unutulup $2f=500$ alınınca çıkar (python ile kontrol edildi).

### 8.2 Kosinüs ve Sinüsün Üstel İfadeleri

Ekranda şu eşitlikler yazıldı (ekrandan, 01:05:00):

$$e^{j\omega_0 t}=\cos\omega_0 t+j\sin\omega_0 t,\qquad e^{-j2\pi f_0 t}=\cos 2\pi f_0 t-j\sin 2\pi f_0 t$$

Bu iki eşitlik taraf tarafa toplanırsa sinüsler birbirini götürür ve $2\cos\omega_0 t$ kalır:

$$\cos\omega_0 t=\frac{e^{j\omega_0 t}+e^{-j\omega_0 t}}{2}$$

Birinciden ikincisi çıkarılırsa sinüslü taraf bulunur; paydada $2j$ olur ve aradaki işaret değişir:

$$\sin\omega_0 t=\frac{e^{j\omega_0 t}-e^{-j\omega_0 t}}{2j}$$

Slaytta bu ilişki, karmaşık düzlemde dönen iki sarmalın ($e^{j2\pi t}$ ve $e^{-j2\pi t}$) toplanıp çıkarılmasıyla gerçel kosinüs ve sinüs dalgalarının oluşması olarak gösterildi (ekrandan, 00:40:00).

> **Hocanın vurgusu:** Yalnız $e^{j\omega_0 t}=\cos\omega_0 t+j\sin\omega_0 t$ eşitliğini bilmek yeterlidir; işaret değiştirilip taraf tarafa toplanarak diğerleri türetilir.

Bilinen sinyaller cinsinden bir ayrıştırma (decomposition) yapmak, verilen bir giriş sinyalinin analizini kolaylaştırır.

## 9. Sürekli Zaman Fourier Serisi (CTFS)

### 9.1 Süperpozisyon ve Ayrıştırma Fikri

Bir sistemin çıkışını bulmak için konvolüsyon gerekir; konvolüsyon zor olduğu için Fourier dönüşümlerinden ve onların bir alt kümesi olan Fourier serilerinden yararlanılır. Fourier serisi, bir sinyali bilinen kosinüs ve sinüsler cinsinden ayrıştırmayı sağlar. Sonuçta sinyalin yüzde 99-100'üne yakın kısmını oluşturan küçük sinyaller elde edilir ve bunların toplamı orijinal sinyali verir.

Mantık süperpozisyon özelliğine dayanır: $x(t)$ girişi doğrusal bir sisteme tek seferde verilmek yerine parçalara ayrılıp her parça ayrı verilirse, çıkışların toplamı yine aynı $y(t)$'yi verir. Bu yüzden sinyal olabildiğince küçük ve bilinen parçalara ayrılır, her parça sisteme ayrı ayrı tanıtılır. Bu, doğrusallık kontrolünde konuşulan özelliğin kendisidir. Ayrıca sinyaller her zaman yalnız gerçel sayılardan oluşmaz; karmaşık sayılar da içerebilir.

### 9.2 Sinüzoidlerle Yaklaşma

Slaytlarda sinyalin "sinüzoidlerin toplamı" olarak temsil edildiği gösterildi. Kesikli çizgiyle verilen bir sinyale (örneğin bir üçgen dalgaya) tek bir sinüzoidle yaklaşıldığında bir miktar hata kalır. Bir sinüzoid daha eklenince hata azalır, bir tane daha eklenince daha da azalır; sonunda istenen sinyale çok yakın bir sonuç elde edilir. Bu hem sürekli hem ayrık zamanda yapılabilir ve buna **sinyalin harmoniklerinin bulunması** denir.

### 9.3 CTFS Tanımı

Slaytta Fourier serisinin tanımı verildi (ekrandan, 00:45:00): $t_0<t<t_0+T$ aralığında bir $x(t)$ sinyalinin Fourier serisi gösterimi

$$x(t)=\sum_{k=-\infty}^{\infty}c_x[k]\,e^{j2\pi kt/T}$$

biçimindedir. Burada $c_x[k]$ **harmonik fonksiyon**, $k$ ise **harmonik numarasıdır**. Harmonik fonksiyon, sinyalden **ortogonallik** ilkesiyle bulunur.

Hoca, sürekli zamanda olmasına rağmen burada bir toplam sembolü bulunduğuna dikkat çekti: sonuçta bir seri elde edilir. $c$ dizisi harmoniklerin bilgisini içerir; sinyal $e^{j2\pi kt/T}$ ile, yani sinüzoidlerle çarpılır ve bu çarpımlar sinyalin içindeki sinüzoidlerin bilgisini verir.

### 9.4 Benzerlik ve Ortogonallik

Hoca, önceki derste konvolüsyon animasyonunda sonucun en çok benzeşme olan yerde (iki sinyalin yüzde yüz örtüştüğü noktada) tepe verdiğini hatırlattı. Fourier katsayısının hesabı da benzer bir çarpma ve toplama (integral) işlemidir; tek farkı, ikinci fonksiyonun özel bir kosinüs (ya da karmaşık üstel) sinyali olmasıdır. Sonuç, giriş sinyalinin içinde hangi kosinüs ve sinüslere benzeyen bileşenler bulunduğunu gösterir.

Bu bir **dönüşüm değil seridir**, çünkü sinyal $-\infty$ ile $+\infty$ arasında değil, belli bir periyotta incelenir. Ortogonallik gereği $t_0$'dan $t_0+T$'ye kadar olan bölüm incelenirse tekrar eden diğer bölümleri incelemeye gerek kalmaz.

> **Ders sonrası not:** Hoca katsayı hesabını "bir anlamda konvolüsyon" diye anlattı. Matematiksel olarak $c_x[k]$ hesabı, sinyalin $e^{j2\pi kt/T}$ ile iç çarpımıdır (ilintiye benzer); konvolüsyondaki gibi bir sinyalin katlanıp kaydırılması yoktur.

Slaytlarda orthogonallik ispatı da vardı (Euler bağıntılarıyla). Hoca bunların ayrıntısına girmenin gerekmediğini, isteyenin slaytlara bakabileceğini söyledi.

### 9.5 Tanımın Özeti

Özetleyen slayt (ekrandan, 01:10:00):

$$x(t)=\sum_{k=-\infty}^{\infty}c_x[k]\,e^{j2\pi kt/T}\qquad\text{ve}\qquad c_x[k]=\frac{1}{T}\int_{t_0}^{t_0+T}x(t)\,e^{-j2\pi kt/T}\,dt$$

Sinyal ve harmonik fonksiyonu bir **Fourier serisi çifti** oluşturur: $x(t)\overset{\mathcal{FS}}{\underset{T}{\longleftrightarrow}}c_x[k]$. Burada $T$ temsil süresidir ve CTFS gösteriminin temel periyodudur. $T$ aynı zamanda $x(t)$'nin bir periyoduysa CTFS gösterimi her zaman için geçerlidir; mühendislik uygulamalarında en yaygın kullanım budur. $T$, $x(t)$'nin periyodu değilse gösterim genellikle yalnız $t_0\le t<t_0+T$ aralığında geçerlidir.

Hoca bu işlemi, $t$ düzleminden $k$ düzlemine geçmek olarak özetledi. Bu düzlemde bulunan katsayılar sinyalin genliğini, frekansını ve faz bilgisini içeren bir vektördür.

### 9.6 Gerçel Fonksiyonların CTFS'si

Giriş sinyali gerçel değerli ya da karmaşık değerli olabilir; derste öncelikle gerçel fonksiyonlarla ilgilenilir. Slayttaki özellik (ekrandan, 00:50:00): herhangi bir gerçel değerli $x(t)$ fonksiyonunun CTFS harmonik fonksiyonu

$$c_x[k]=c_x^*[-k]$$

özelliğini taşır. Bunun bir sonucu, gerçel değerli fonksiyonlarda harmonik fonksiyonun **genliğinin çift**, **fazının tek** fonksiyon olmasıdır. Hoca, tek ve çift fonksiyonlarda integralin farklı biçimlerde kolaylaştığını, bu özelliklere daha sonra bakılacağını söyledi.

### 9.7 Hesaplama Mantığı ve Kare Dalga

Aradan sonra hoca, işlemin özünü yeniden anlattı: $x(t)$ sinyali, içinde sinüs ve kosinüsler bulunan bir sinyalle çarpılıp integrali alınır. Bu, periyodik sinyallere uygulanır. Bu yüzden önce sinyalin periyodu bulunur, sonra bu periyoda göre kosinüs bileşeni oluşturulur. Ekrana yazılan ifade (ekrandan, 01:20:00):

$$e^{-j2\pi k t/T}=\cos\!\left(\frac{2\pi kt}{T}\right)-j\sin\!\left(\frac{2\pi kt}{T}\right)$$

Bazı kaynaklarda integrallerde üstel biçim, bazılarında kosinüslü-sinüslü biçim görülür; hangisi işe gelirse o kullanılır. İncelenen sinyal $2t$, $3t$ gibi doğrusal bir fonksiyonsa işler biraz karışır; sinyal $e^{j\dots}$ biçimindeyse doğrudan üstel biçimde daha hızlı integral alınır; kosinüslü bir sinyal ise trigonometrik dönüşümlerle çalışmak kolaydır.

En basit örnek kare dalgadır. Hocanın çizdiği kare dalga (ekrandan, 01:20:00):

| Aralık | $x(t)$ |
|---|---|
| $0\le t<2$ | 1 |
| $2\le t<3$ | 0 |
| $3\le t<5$ | 1 |
| $5\le t<6$ | 0 |

Periyot $T=3$'tür. Bir periyotta sinyal yalnız $0$–$2$ aralığında 1'dir; integral çok basit bir hâl alır. Hoca, soruyu soranın "merhamet duygusuna" göre bunun yerine $0$–$T$ aralığında $t$, sonra $-t$ gibi doğrusal ya da kuadratik parçalardan oluşan daha zor sinyaller de sorulabileceğini, ama mantığın aynı olduğunu söyledi. Notasyon kaynaktan kaynağa değişir; bu normaldir.

### 9.8 Trigonometrik CTFS

Bir sinyal kosinüslü ve sinüslü biçimde yazılırsa katsayılar ayrışır, çünkü kosinüs çift, sinüs tek fonksiyondur. Kosinüsler için $a_k$, sinüsler için $b_k$ katsayısı gelir; ayrıca kosinüsten bağımsız, DC bileşeni içeren $a_0$ katsayısı vardır. Slayttaki biçim (ekrandan, 00:55:00):

$$x(t)=a_x[0]+\sum_{k=1}^{\infty}\left\{a_x[k]\cos\!\left(\frac{2\pi kt}{T}\right)+b_x[k]\sin\!\left(\frac{2\pi kt}{T}\right)\right\}$$

$$a_x[k]=\frac{2}{T}\int_{t_0}^{t_0+T}x(t)\cos\!\left(\frac{2\pi kt}{T}\right)dt,\qquad b_x[k]=\frac{2}{T}\int_{t_0}^{t_0+T}x(t)\sin\!\left(\frac{2\pi kt}{T}\right)dt$$

Yani $c_x[k]$ üç parçaya ayrılır: DC bileşen, kosinüs bileşenleri ve sinüs bileşenleri. Hoca önündeki $\frac{2}{T}$'yi bir normalizasyon olarak açıkladı. Bulunan bütün sinüzoidal bileşenler toplandığında orijinal sinyal elde edilir.

### 9.9 Katsayı Hesabında Sezgi

Slayttaki ilk örnek $x(t)=2\cos(400\pi t)$, periyot $5$ ms; istenen $a_k$ ve $b_k$ katsayılarıdır. Hoca, burada bir kosinüsün başka bir kosinüsle çarpılacağını, iki dalga en çok benzediğinde çarpımın en büyük olacağını söyledi. Kosinüs-kosinüs çarpımının bir periyot boyunca integrali sürekli artar; sinüs tarafında ise bir artış bir azalış görülür. Yapılacak iş $x(t)$'yi integralde yerine yazıp integrali çözmektir.

İkinci örnek $x(t)=\frac{1}{2}-\frac{3}{4}\cos(20\pi t)+\frac{1}{2}\sin(30\pi t)$ idi. Bu sinyalde bir DC bileşen, bir kosinüs ve bir sinüs bileşeni vardır. Arama sırasında $\cos 20\pi t$'ye benzeyen yerde ve $\sin 30\pi t$'ye benzeyen yerde tepe görülür. Bu iki örneğin çözümü Örnek Sorular bölümündedir.

Hoca ayrıca bir dikdörtgen sinyal ile birim darbe fonksiyonundan oluşan bir örneğin analitik çözümünü sonraki derse bıraktı.

### 9.10 CTFS'nin Doğrusallığı

Slayttaki özellik (ekrandan, 01:15:00):

$$x(t)=x_1(t)+x_2(t)+\cdots,\qquad x_1(t)\overset{\mathcal{FS}}{\underset{T}{\longleftrightarrow}}c_{x1}[k],\ \ x_2(t)\overset{\mathcal{FS}}{\underset{T}{\longleftrightarrow}}c_{x2}[k]\ \Rightarrow\ c_x[k]=c_{x1}[k]+c_{x2}[k]+\cdots$$

Bu ilişkiler yalnız bütün bileşen fonksiyonların harmonik fonksiyonları aynı temsil süresi $T$'ye göre hesaplandığında geçerlidir. Yani bir sinyal toplam hâlindeyse parçalara ayrılıp her parçanın katsayıları ayrı bulunabilir.

### 9.11 Ses Örneği

Hoca, bir sesin (İngilizcedeki "but" kelimesinin) içindeki sinüs ve kosinüs bileşenlerinin bulunup bunlardan sinyaller oluşturulduğu, bu sinyaller toplandığında yine aynı sesin duyulduğu bir örneği anlattı. Fourier serisine açılmış bu sesin görselleştirmesinde tepe görülen her yer, sinyalin içinde o frekansta bir kosinüs dalgası bulunduğu anlamına gelir. Nihai amaç, $t$ düzlemindeki $x(t)$ sinyalini harmonikler cinsinden, yani $k$ (frekans) düzleminde yeni bir vektör sinyal olarak yazmaktır.

## 10. Fourier Dönüşümüne Kısa Giriş

### 10.1 Genel Fourier Serisi Toplamı

Hoca, her sinyalin şu toplam biçiminde yazılabileceğini ekrana yazdı (ekrandan, 01:20:00):

$$x(t)=\sum_{i=-\infty}^{+\infty}A_i\cos\left(2\pi f_i t+\phi_i\right)$$

Her sinüzoidin kendine ait bir genliği ($A_i$), frekansı ($f_i$) ve fazı ($\phi_i$) vardır. Bunlar bilinirse toplam alınarak orijinal sinyal elde edilir. Amaç bu üç bilgiyi bulmaktır; bunun yolu Fourier serilerinden geçer.

### 10.2 Periyodik Olmayan Sinyaller

Günlük hayatta çoğu sinyal periyodik değildir. Bu durumda Fourier dönüşümü kullanılır (ekrandan, 01:25:00):

$$x(t)\longleftrightarrow X(f),\qquad X(\omega)=\int_{-\infty}^{+\infty}x(t)\,e^{-j\omega_0 t}\,dt$$

Hocaya göre bir şeyin dönüşüm (transform) olması için geri döndürülebilir olması gerekir: $x(t)$'den $X(f)$'ye gidilip yeniden $x(t)$ kurulabilmelidir. Laplace ve z dönüşümleri de bu geri dönüşü sağlar. Hoca, Fourier serisinde yeniden kurulumun her zaman yüzde 100 olmadığını, büyük ölçüde benzer bir sinyal elde edilse de bir hata payı kaldığını söyledi.

> **Ders sonrası not:** Sonlu sayıda terim alındığında ve süreksizlik noktalarında Fourier serisiyle kurulan sinyalde hata kalır (süreksizlik yakınındaki salınımlara Gibbs olayı denir). Ancak sonsuz terimli Fourier serisi, sinyalin sürekli olduğu noktalarda periyodik sinyali tam olarak verir; Fourier serisi de tersine çevrilebilir bir gösterimdir.

### 10.3 Ana Fonksiyon (Mother Function)

Fourier dönüşümünde sinyal $e^{-j\omega_0 t}$ ile çarpılıp toplanır. Bu $e^{-j\omega_0 t}$ terimine **ana fonksiyon** (mother function) denir. **Soru:** Bunun yerine başka bir fonksiyon kullansak ne olur? **Cevap:** O zaman dönüşüm daha genel bir hâle gelir; örneğin dalgacık dönüşümü (wavelet transform). Hoca ekrana ana fonksiyon olarak $t^2$ ve dalgacık benzeri bir şekil çizdi (ekrandan, 01:25:00).

Hoca, aynı fikrin konvolüsyon ödevinde de denenebileceğini söyledi: $x=[1\ 2\ 3]$ ve $y=[3\ 4\ 8]$ gibi iki dizi yerine bir diziyi kendisiyle ($[1\ 2\ 3]$ ile $[1\ 2\ 3]$) işleme sokmak, tam ortada tek bir tepe veren, birebir benzerliği gösteren bir sonuç verir (ekrandan, 01:25:00). Bu, bir fonksiyonun başka bir fonksiyona ne kadar benzediğini görmektir; iki boyutta yapılırsa bir görüntüde göz gibi bir bölgeyi arama uygulamalarında kullanılır.

### 10.4 Süreksizlikler

Fourier dönüşümü sinüs ve kosinüs üzerine kuruludur. Sinyalde sinüs ve kosinüse aykırı bir durum, örneğin ani bir süreksizlik ya da sivri bir köşe varsa, bu noktada sağdan ve soldan türevler farklı olduğu için sinüslerle modellemek zorlaşır. Çok sayıda sinüzoid toplamak gerekir, o bile yetmeyebilir ve sinyal yeniden kurulduğunda orijinali tam bulunamaz. Düzgün parçalı bölgelerde ise dönüşüm başarılıdır.

## 11. Temel Frekans ve Fourier Serisinin Biçimleri

### 11.1 Harmonik İlişkili Sinüzoidler

Slayttaki soru: "Bunların hepsinin periyodu neden 1 saniye?" (ekrandan, 01:30:00)

$$x(t)=A_1\cos(2\pi t+\phi_1)+A_2\cos(2\times 2\pi t+\phi_2)+A_3\cos(3\times 2\pi t+\phi_3)$$

Birinci terim her 1 saniyede, ikinci terim her 1/2 saniyede (dolayısıyla her 1 saniyede de), üçüncü terim her 1/3 saniyede (dolayısıyla her 1 saniyede de) tekrar eder. Genel ifade: frekansları en düşük bir temel frekans $\omega_0$'ın tamsayı katları olan sinüzoidlerin toplamı, periyodu $T=2\pi/\omega_0$ saniye olan periyodik bir sinyal verir. Buna göre istenen sayıda, hatta sonsuz sayıda harmonik ilişkili sinüzoid toplanabilir:

$$x(t)=\sum_{k=1}^{\infty}A_k\cos(k\omega_0 t+\phi_k),\qquad -\infty<t<\infty$$

Bütün frekanslar temel frekans $\omega_0$'ın tamsayı katlarıdır.

### 11.2 Temel Frekansın Bulunması

Bir sinyal ayrıştırıldığında (hem Fourier serisinde hem Fourier dönüşümünde) frekanslar temel frekansın katları biçiminde yazılır. Bulunan $\omega_1,\omega_2,\omega_3,\dots$ frekanslarından temel frekans, bu frekansların **en büyük ortak böleni (EBOB)** ile bulunur.

Örnek: Frekanslar 10, 15 ve 20 Hz ise $f_0=\text{EBOB}(10,15,20)=5$ Hz'dir. $k=1$ için 5 Hz, $k=2$ için 10 Hz, $k=3$ için 15 Hz, $k=4$ için 20 Hz bileşenleri yazılır.

> **Hocanın vurgusu:** Temel frekansı bulurken EBOB'u kullanmak önemlidir.

Temel frekans dairesel (açısal) frekans olarak da verilebilir. Slayttaki örnekte $\omega_0=2\pi$ rad/s için $k=1,2,3$ bileşenlerinin frekansları $2\pi$, $4\pi$, $6\pi$ rad/s'dir. Genlikler $A_1=1$, $A_2=0.5$, $A_3=0.5$ alındığında bir sinyal oluşur; fazlar ($t=0$ anındaki değerler) aynı bırakılıp genlikler değiştirildiğinde sinyalin biçimi değişir, genlikler sabit bırakılıp fazlar değiştirildiğinde bileşenler kayar ve sinyal başka bir biçim alır. Kosinüse $90^\circ$ eklenirse sinüs elde edilir.

Temel frekans biliniyorsa temel periyot da bulunur:

$$T_0=\frac{2\pi}{\omega_0}$$

### 11.3 DC Bileşen

$k=0$ verildiğinde frekansı sıfır olan bileşen elde edilir; buna **DC bileşen** denir ve özel bir hâldir. $\cos 0=1$ olduğu için doğrudan bir sabit $A_0$ gelir. $A_0$ sabit terim ya da DC terimidir.

### 11.4 Üç Biçim

Fourier serisinin üç eşdeğer biçimi vardır: genlik-faz biçimi, karmaşık üstel biçim ve sinüs-kosinüs biçimi. Hoca hepsinin aynı bilgiyi taşıdığını belirtti. Biçimler arası geçiş şu bağıntılarla yapılır (ekrandan, 01:40:00):

$$c_0=A_0,\qquad c_k=\tfrac{1}{2}A_k e^{j\theta_k},\qquad c_{-k}=\tfrac{1}{2}A_k e^{-j\theta_k}$$

$$a_0=c_0,\qquad a_k=A_k\cos\theta_k,\qquad b_k=-A_k\sin\theta_k$$

### 11.5 Örnek: Üç Biçim Arasında Geçiş

Slayttaki örnek (ekrandan, 01:40:00):

$$x(t)=\cos(t)+0.5\cos(4t+\pi/3)+0.25\cos(8t+\pi/2)$$

Bu sinyal zaten genlik-faz biçimindedir ve $\omega_0=1$'dir.

**Genlik-faz biçimi.** Her terimin genliği ve fazı doğrudan okunur:

| Terim | Genlik | Faz | Frekans |
|---|---|---|---|
| $\cos t$ | $A_1=1$ | $\theta_1=0$ | $1\cdot\omega_0$ |
| $0.5\cos(4t+\pi/3)$ | $A_4=0.5$ | $\theta_4=\pi/3$ | $4\cdot\omega_0$ |
| $0.25\cos(8t+\pi/2)$ | $A_8=0.25$ | $\theta_8=\pi/2$ | $8\cdot\omega_0$ |

Diğer bütün $A_k$ katsayıları ($A_2$, $A_3$, $A_5$, $A_6$, $A_7$, ...) sıfırdır. Hoca bunu, o frekansların "bastırılmış", hükümsüz frekanslar olduğu diye yorumladı. Bu bilginin uygulamadaki karşılığı bir sonraki bölümdeki periyodik gürültü örneğidir.

**Karmaşık üstel biçim.** $c_0=A_0$; burada DC bileşen yoktur. Her genlik iki eşit parçaya bölünür: biri pozitif, biri negatif frekansa:

$$c_{\pm1}=0.5,\qquad c_{\pm4}=0.25\,e^{\pm j\pi/3},\qquad c_{\pm8}=0.125\,e^{\pm j\pi/2}$$

Diğer bütün $c_k$ sıfırdır. Örneğin $A_4=0.5$ genliği $0.25+0.25$ olarak ikiye bölünür; bu ikisi toplanınca yine tek bir gerçel sinyal elde edilir. Böylece

$$x(t)=\left[0.5e^{jt}+0.5e^{-jt}\right]+\left[0.25e^{j\pi/3}e^{j4t}+0.25e^{-j\pi/3}e^{-j4t}\right]+\left[0.125e^{j\pi/2}e^{j8t}+0.125e^{-j\pi/2}e^{-j8t}\right]$$

Bu ifadede $e^{jkt}$ terimi frekans bilgisini (temel frekans 1 olduğundan $4t$ temel frekansın 4 katı, $8t$ 8 katı), $e^{j\theta}$ terimi faz bilgisini, öndeki sayı genlik bilgisini taşır.

**Sinüs-kosinüs biçimi.** $a_k=A_k\cos\theta_k$, $b_k=-A_k\sin\theta_k$ bağıntılarıyla (python ile kontrol edildi):

| $k$ | $a_k$ | $b_k$ |
|---|---|---|
| 1 | $1$ | $0$ |
| 4 | $0.5\cos(\pi/3)=0.25$ | $-0.5\sin(\pi/3)\approx-0.433$ |
| 8 | $0.25\cos(\pi/2)=0$ | $-0.25\sin(\pi/2)=-0.25$ |

$$x(t)=\cos t+0.25\cos 4t-0.433\sin 4t-0.25\sin 8t$$

Hoca $0.43$ değerinin $\sqrt{3}/4\approx0.433$'ün yuvarlanmasından geldiğini belirtti.

> **Ders sonrası not:** Slaytta $b_4=0.43$, $b_8=0.25$ ve son satırda $+0.25\sin(8t)$ yazıyordu; hoca da "artı 0.25 sin 8t" diye okudu. Slayttaki $b_k=-A_k\sin\theta_k$ bağıntısına göre doğrusu $b_4\approx-0.433$ ve $b_8=-0.25$'tir. Çünkü $0.25\cos(8t+\pi/2)=-0.25\sin(8t)$'dir. Son satırdaki $-0.43\sin(4t)$ terimi doğrudur.

Katsayılar bulunduktan sonra $A_k=\sqrt{a_k^2+b_k^2}$ ile genlik geri bulunur; hoca bunu kabaca "genlik, $|c_k|$'nın iki katıdır" diye özetledi ($0.25+0.25=0.5$). Faz açısı istenirse $\tan\theta_k=-b_k/a_k$ bağıntısından elde edilir.

## 12. Uygulama: Periyodik Gürültünün Giderilmesi

Bazı $a_k$ katsayılarının sıfır olması bilgisinin bir uygulaması **periyodik gürültüdür**. Hoca bir sayısal görüntü işleme ders notunu açtı (ekrandan, 01:35:00). Slayttaki bilgiler:

- Gürültünün kaynağı: görüntü alınırken oluşan elektriksel ya da elektromekanik girişim.
- Uzaysal koordinatlardan bağımsız değildir.
- Frekans düzleminde süzgeçleme (filtreleme) ile önemli ölçüde azaltılabilir.

Slayttaki şekilde sinüzoidal gürültüyle bozulmuş bir görüntü ve onun spektrumu vardı. Spektrumun ortasındaki parlak bölge görüntünün temel (düşük) frekans içeriğidir. Çevresinde simetrik küçük noktalar görülür; her eşlenik dürtü çifti bir sinüs dalgasına karşılık gelir ve bunlar periyodik gürültüdür.

Gürültüyü gidermek için bu noktaların bulunduğu yerlere değeri sıfır (siyah) olan küçük daireler konur ve spektrum bu maskeyle çarpılır. Böylece o frekansların katsayıları sıfırlanmış, yani o frekanslar bastırılmış olur. Ters dönüşüm yapıldığında görüntüdeki çizgili gürültü kaybolur. Burada temizlenebilmesinin nedeni gürültünün periyodik olması, yani görüntüye belli bir frekans bileşeninin eklenmiş olmasıdır.

Hoca aynı şeyin seste de denenebileceğini söyledi: bir ses kaydına 10 Hz'lik başka bir sinyal eklenirse dinlerken kayıttan bağımsız bir gürültü duyulur. Bu frekansın katsayısı sıfırlanıp ters dönüşümle sinyal yeniden kurulursa gürültü kaybolur.

## 13. Fourier Katsayılarının Analitik Bulunması

### 13.1 DC Bileşen: Bir Periyotluk Alan

Analitik yöntemde temel denklem şudur: bir periyot boyunca integral alınır, sonra periyoda bölünerek normalize edilir. Bu aslında sinyalin bir periyotluk alanını hesaplamaktır:

$$a_0=\frac{1}{T}\int_{t_0}^{t_0+T}x(t)\,dt$$

Hocanın çizdiği kare dalgada ($T=3$) integral sınırları değişkenlik gösterdiği için integral parçalara ayrılır: $0$–$2$ aralığında $x(t)=1$, $2$–$3$ aralığında $x(t)=0$. Birinci parçanın integrali $2-0=2$, ikinci parçanınki 0'dır. Bu alan periyoda bölünür:

$$a_0=\frac{1}{3}\left[\int_0^2 1\,dt+\int_2^3 0\,dt\right]=\frac{1}{3}\cdot 2=\frac{2}{3}\quad\text{(ara adım eklendi)}$$

DC bileşen, herhangi bir frekans bilgisi kullanılmadan bulunur. Buna DC ofset ya da bir periyotluk zaman ortalaması da denir.

### 13.2 Kosinüs ve Sinüs Bileşenleri

Diğer katsayılar için önde $\frac{2}{T}$ bulunur; $t_0$'dan $t_0+T$'ye kadar kosinüsle çarpılarak $a_k$, sinüsle çarpılarak $b_k$ bulunur. $k$ tamsayı değerleri, temel frekanstan diğer frekansları üretmeyi sağlar. Katsayılar bulunduktan sonra genlik $A_k=\sqrt{a_k^2+b_k^2}$ ve faz açısı fazör gösterimiyle hesaplanır.

### 13.3 Dikdörtgen Darbe Dizisi (Slayttan)

Hoca dersin sonunda bir sonraki derste yapılacak örneği gösterdi: dikdörtgen darbe dizisinin Fourier serisi (ekrandan, 01:45:00). Çözüm Örnek Sorular bölümündedir. Hoca ayrıca $e^{-t}$ içeren periyodik bir sinyal örneğinin Fourier serisine açılmasının daha zor olacağını, sonuçta zaman ve frekans analizi olarak frekans bileşenlerinin bulunacağını söyledi.

Slaytların devamında çift ve tek fonksiyonlar için kolaylıklar, sayısal hesap örnekleri, zamanda kaydırmanın yalnız bir faz farkı oluşturduğu (yeniden integral almaya gerek bırakmadığı) özelliği ve sürekli zaman Fourier dönüşümüne (CTFT) geçiş vardı. Hoca bu slaytların çok ayrıntılı olduğunu, çalışmak için tavsiye ettiğini, ama ayrıntılarının sorulmayacağını söyledi. CTFT özelliklerinden biri olarak bir sinyalin integralinin frekans düzleminde $j2\pi f$'ye bölmeye karşılık geldiği şekil üzerinde gösterildi (ekrandan, 01:50:00).

## Örnek Sorular

### Soru 1: İkinci mertebeden diferansiyel denklemin sıfır giriş cevabı

(ekrandan, 00:25:00)

$\frac{d^2y(t)}{dt^2}+3\frac{dy(t)}{dt}+2y(t)=\frac{df(t)}{dt}$ denkleminin sıfır giriş cevabını (homojen çözümünü) $y(0)=0$, $y'(0)=-5$ başlangıç koşullarıyla bulun.

Slaytta verilen kısım: sıfır giriş biçimi $\frac{d^2y}{dt^2}+3\frac{dy}{dt}+2y=0$, karakteristik denklem $\lambda^2+3\lambda+2=0\Rightarrow(\lambda+1)(\lambda+2)=0$.

> **Çözüm (derste verilmedi):** Kökler $\lambda_1=-1$, $\lambda_2=-2$. Çözüm $y(t)=C_1e^{-t}+C_2e^{-2t}$. $y(0)=C_1+C_2=0$; $y'(0)=-C_1-2C_2=-5$. Buradan $C_2=5$, $C_1=-5$: $y(t)=-5e^{-t}+5e^{-2t}$, $t\ge0$ (python ile kontrol edildi).

### Soru 2: Bir kosinüsün CTFS katsayıları

(derste sözlü, 01:11:19; slayt karesi yok)

$x(t)=2\cos(400\pi t)$ ve sinyalin periyodu $T=5$ ms olsun. Sinyalin $a_k$ ve $b_k$ katsayılarını bulun.

> **Çözüm (derste verilmedi):** $400\pi=2\pi\cdot 200$, yani $f=200$ Hz ve $1/T=200$ Hz'dir; sinyal tam olarak birinci harmoniktir. $a_0=0$, $a_1=\frac{2}{T}\int_0^T 2\cos^2(400\pi t)\,dt=2$, diğer bütün $a_k=0$ ve bütün $b_k=0$ (python ile kontrol edildi).

### Soru 3: DC, kosinüs ve sinüs bileşenli sinyal

(derste sözlü, 01:13:42; slayt karesi yok)

$x(t)=\frac{1}{2}-\frac{3}{4}\cos(20\pi t)+\frac{1}{2}\sin(30\pi t)$ sinyalinin $a_0$, $a_k$ ve $b_k$ katsayılarını bulun.

> **Çözüm (derste verilmedi):** Frekanslar 10 Hz ve 15 Hz; temel frekans $f_0=\text{EBOB}(10,15)=5$ Hz, $T=0.2$ s. Bu temsil süresiyle $a_0=\frac{1}{2}$; $20\pi t=2\pi\cdot2\cdot5\,t$ olduğundan $a_2=-\frac{3}{4}$; $30\pi t=2\pi\cdot3\cdot5\,t$ olduğundan $b_3=\frac{1}{2}$; diğer bütün katsayılar sıfırdır (python ile kontrol edildi).

### Soru 4: Temel frekans

(derste sözlü, 01:27:11)

Bir sinyalin bileşen frekansları 10, 15 ve 20 Hz ise temel frekans nedir?

**Çözüm (derste verildi):** $f_0=\text{EBOB}(10,15,20)=5$ Hz. Bileşenler $k=2,3,4$ harmonikleridir.

### Soru 5: Genlik-faz biçiminden diğer biçimlere

(ekrandan, 01:40:00)

$x(t)=\cos(t)+0.5\cos(4t+\pi/3)+0.25\cos(8t+\pi/2)$ sinyalini karmaşık üstel ve sinüs-kosinüs biçiminde yazın.

**Çözüm (derste verildi, işaret düzeltmesiyle):** $c_{\pm1}=0.5$, $c_{\pm4}=0.25e^{\pm j\pi/3}$, $c_{\pm8}=0.125e^{\pm j\pi/2}$; $a_1=1$, $a_4=0.25$, $b_4\approx-0.433$, $b_8=-0.25$. Sonuç $x(t)=\cos t+0.25\cos4t-0.433\sin4t-0.25\sin8t$. Ayrıntı 11.5 bölümündedir.

### Soru 6: Dikdörtgen darbe dizisinin Fourier serisi

(ekrandan, 01:45:00)

$x(t)$, periyodu $T=2$ olan, $0<t<1$ aralığında 1, $1<t<2$ aralığında 0 değerini alan dikdörtgen darbe dizisidir. $\omega_0=\frac{2\pi}{2}=\pi$ rad/s. Karmaşık üstel Fourier katsayılarını bulun.

**Çözüm (slaytta verildi, hoca sonraki derse bıraktı):** $t_0=0$ seçilerek

$$c_k=\frac{1}{2}\int_0^2 x(t)e^{-jk\pi t}dt=\frac{1}{2}\left[\int_0^1 1\cdot e^{-jk\pi t}dt+\int_1^2 0\cdot e^{-jk\pi t}dt\right]=\frac{1}{2}\left[\frac{1}{-jk\pi}e^{-jk\pi t}\right]_0^1=\frac{j}{2k\pi}\left[e^{-jk\pi}-1\right]$$

$e^{-jk\pi}$, $k$ çiftse 1, tekse $-1$'dir. Buradan

$$c_k=\begin{cases}0, & k\ \text{çift},\ k\neq0\\[2pt] \dfrac{-j}{k\pi}, & k\ \text{tek}\end{cases}$$

Bu ifade $k=0$ için geçerli değildir; ayrı hesaplanır: $c_0=\frac{1}{2}\int_0^1 1\,dt=\frac{1}{2}$. Bu değer DC seviyesi (DC ofset) olarak adlandırılır (python ile kontrol edildi).

### Soru 7: Uzunluğu 4 olan süzgecin çıkışı

(ekrandan, 01:55:00)

Hoca, başka bir kaynaktaki örnek soru dosyasını göstererek bunun gibi soruları çalışmayı önerdi. Katsayıları $\{b_k\}=\{3,-1,2,1\}$ olan uzunluğu 4 olan süzgecin çıkışı $y[n]$'yi hesaplayın. Giriş ve kısmen verilen çıkış tablosu:

| $n$ | $n<0$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | $n>8$ |
|---|---|---|---|---|---|---|---|---|---|---|---|
| $x[n]$ | 0 | 2 | 4 | 6 | 4 | 2 | 0 | 0 | 0 | 0 | 0 |
| $y[n]$ | 0 | 6 | 10 | 18 | ? | ? | ? | 8 | 2 | 0 | 0 |

Tablodaki verilen değerlerin doğru olduğunu doğrulayın ve eksik değerleri bulun.

**Çözüm (ekrandaki cevap anahtarında kısmen verildi):** $y[n]=3x[n]-x[n-1]+2x[n-2]+x[n-3]$.

- $y[2]=3(6)-4+2(2)+0=18$ (doğrulandı)
- $y[3]=3(4)-6+2(4)+2=16$
- $y[4]=3(2)-4+2(6)+4=18$
- $y[5]=3(0)-2+2(4)+6=12$
- $y[6]=0-0+2(2)+4=8$, $y[7]=0+0+0+2=2$ (doğrulandı)

Sonuç: $y[3]=16$, $y[4]=18$, $y[5]=12$ (python `numpy.convolve` ile kontrol edildi).

### Soru 8: Temel frekans, temel periyot ve katsayılar

(derste sözlü, 01:55:49)

Bileşen frekansları 20 Hz, 30 Hz ve 60 Hz olan bir sinyalin temel frekansını, temel periyodunu ve $a_k$ katsayılarını bulun.

<!-- BELİRSİZ: Sinyalin tam ifadesi (genlikler ve fazlar) ekranda gösterildi ama o ana ait kare yok; altyazıda yalnız frekanslar geçiyor. -->

**Çözüm (derste kısmen verildi):** Hoca önce yanlışlıkla EKOK dedi, sonra EBOB olarak düzeltti: $f_0=\text{EBOB}(20,30,60)=10$ Hz. Buradan $\omega_0=2\pi\cdot10=20\pi$ rad/s ve $T_0=1/f_0=0.1$ s bulunur. Bileşenler sırasıyla $k=2$, $k=3$ ve $k=6$ harmonikleridir. Genlik ve fazlar sinyalin ifadesinden okunur.

## Dersin Toparlaması

Bu derste zaman düzleminden frekans düzlemine geçişin gerekçesi kuruldu. Gerçek sistemler (elektrik devreleri, mekanik sistemler, iki bilgisayar arasındaki kablo) diferansiyel denklemlerle modellenir. Bu denklemleri ya da konvolüsyon integrallerini zaman düzleminde çözmek zordur. Sinyali bilinen sinüzoidlerin toplamına ayırmak, süperpozisyon sayesinde her bileşeni ayrı işleyip sonuçları toplamaya izin verir. Konvolüsyon da frekans düzleminde basit bir çarpıma dönüşür.

Periyodik sinyaller için sürekli zaman Fourier serisi tanımlandı: $c_x[k]=\frac{1}{T}\int_T x(t)e^{-j2\pi kt/T}dt$ ve trigonometrik karşılığı olan $a_0$, $a_k$, $b_k$ katsayıları. Gerçel sinyallerde genlik spektrumunun çift, faz spektrumunun tek olduğu; temel frekansın bileşen frekanslarının EBOB'u olduğu; genlik-faz, karmaşık üstel ve sinüs-kosinüs biçimleri arasında nasıl geçileceği gösterildi. Periyodik gürültünün frekans düzleminde katsayılar sıfırlanarak giderilmesi bu fikrin bir uygulaması olarak sunuldu. Sonraki derste Fourier serisi katsayılarının analitik çözümü (kare dalga ve dikdörtgen darbe dizisi örnekleri), ardından Fourier dönüşümü, özellikleri ve konvolüsyon için kullanımı işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
