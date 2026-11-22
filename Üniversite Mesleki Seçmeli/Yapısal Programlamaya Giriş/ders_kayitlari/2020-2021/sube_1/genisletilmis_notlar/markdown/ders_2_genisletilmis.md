# Ders 2 Genişletilmiş Notu: Algoritma Nedir? İyi Algoritma Nedir?

> Kayıt iki parçadır; arşivde parçalar ters sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı
- 2. Algoritma Nedir?
- 3. Tarifler Birer Algoritmadır: Omlet ve Pizza Hamuru
- 4. Gündelik Dil ve Programlama Yapıları
- 5. Robota Ev Çizdirmek: Neden Programlama Dili?
- 6. Algoritma Değil, İyi Algoritma
- 7. Ödünleşim (Trade-off)
- 8. İyi Algoritma Geliştirmek: İteratif Bir Süreç
- 9. Gauss Toplamı: N İşlemden 3 İşleme
- 10. Karmaşıklığı Azaltmanın Etkisi
- 11. Google ve PageRank: İyi Bir Algoritmanın Sonuçları
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kapsamı

Bu kayıt dönemin ilk dersidir. Dersin ilk bölümünde öğrencilerin tanışması için bir etkinlik yapıldı: herkes iyi yaptığı bir şeyi söyledi. Hoca bu cevapların bir kısmını (omlet, pizza, kahve yapmak gibi) dersin ikinci bölümünde algoritma örneği olarak kullandı.

Hoca haftalık içerik belgesini ekranda paylaştı. Ders C programlama dili üzerinden yürütülür. Ekrandaki konu listesi şöyledir (ekrandan, 01:16:31):

- Algoritma nedir? İyi algoritma nedir?
- Yaklaşık değer bulma: $\pi$, $e^x$, $\cos(x)$
- Tempsiz swap, palindrom sayılar
- Binary arama, $A(B(i))$, seçim sistemleri, sıralama
- Rekürsif olmayan algoritmaların analizi
- Rastgele değer üretimi
- Fonksiyonlar, rekürsif fonksiyonlar
- Rekürsif algoritmaların analizi
- Stringler
- Uygulamalar, NP türü algoritmalar

Teorik derslerin yanında uygulama ve laboratuvar oturumları yapılır. Uygulamalarda asistanlar konu anlatır. Laboratuvarlarda öğrencilere problemler verilir ve öğrenciler bu problemleri çözer.

## 2. Algoritma Nedir?

Hoca, öğrencilerin önceki dönem Bilgisayar Bilimlerine Giriş dersinde algoritmanın tanımını gördüğünü hatırlattı ve tanımı sordu. Bir öğrencinin "bir problemi çözmek için oluşturulan yol" cevabını şöyle tamamladı: algoritma, bir problemi çözmek için atılması planlanan **tanımlı, sonlu adımlar dizisidir**.

Algoritma yalnız bilgisayar problemleri için gereken bir şey değildir. Günlük hayatta yaptığımız birçok işin, örneğin yemek yapmanın da bir algoritması vardır.

## 3. Tarifler Birer Algoritmadır: Omlet ve Pizza Hamuru

### 3.1 Omlet tarifi

Tanışma bölümünde iyi omlet yaptığını söyleyen bir öğrenciden tarifini anlatması istendi. Öğrencinin anlattığı adımlar ve hocanın sorularıyla netleşen yerler şöyledir:

- Tava ısıtılır, üzerine zeytinyağı konur. Hoca "önce tava mı, önce yağ mı?" diye sordu. Öğrenci tavayı çok kızdırmadan ısıttığını, sonra yağı eklediğini söyledi.
- Yağ bir süre bekletilir. Hoca "biraz beklerim" ifadesinin ne demek olduğunu sordu. Cevap: küçük baloncuklar çıkmaya başlayana kadar beklenir.
- Yumurta çırpılır, baharat eklenir. Hoca ne kadar çırpıldığını sordu. Cevap: çatalla 2-3 dakika.
- Yumurta tavaya dökülür, çatalla şekil verilir.
- Hoca pişmenin nasıl anlaşıldığını sordu. Öğrenci bunun kişisel tercih olduğunu, kendisi için sertleşmesi gerektiğini söyledi. Omlet ters çevrilmiyor, tek tarafı pişiriliyor.

### 3.2 Pizza hamuru tarifi

İyi pizza yaptığını söyleyen bir öğrenci de pizza hamurunun tarifini verdi:

- Bir kaba bir bardak süt konur, üzerine bir paket maya eklenir (dört kişilik için marketten alınan bir maya yeter).
- Bir kaşık yoğurt ve bir kaşık şeker eklenir.
- Un eklenmeye başlanır. Unun bir kısmı (örneğin 2 bardak) eklenip karıştırılır, sonra bir yumurta eklenir ve un eklenmeye devam edilir. Toplam 6 bardak un, sürekli karıştırılarak parça parça eklenir.
- Hamur yoğrulur. Unlu taraf kalmadığında kabın ağzı poşet ya da bezle kapatılır.
- Hamur şişene kadar beklenir. Hoca "ne kadar şişmesini beklersin?" diye sordu. Cevap: 1,5-2 katına çıkana kadar. Sonra pizzanın yapımına geçilir.

### 3.3 Bu sorular neden soruldu?

Hoca tariflerin her birinin bir algoritma olduğunu söyledi. Anlatım sırasında araya girip sorular sormasının nedeni, net olmayan noktaları açıklığa kavuşturmaktı: "bunu nasıl yaparsın", "bunu nasıl anlarsın", "ne zamana kadar yaparsın". Bir algoritmanın, anlatıldığı kişi tarafından anlaşılabilecek kadar net olması gerekir.

## 4. Gündelik Dil ve Programlama Yapıları

Yemek tariflerinde "10 dakika ısıt", "pembeleşinceye kadar ısıt", "1,5 katına çıkana kadar bekle" gibi ifadeler geçer. Hoca bu ifadelerin bilgisayar tarafındaki karşılıklarını sordu:

| Gündelik ifade | Programlama karşılığı |
|---|---|
| 10 dakika ısıt (süre belli, başka bir şeye bağlı değil) | `for` |
| Soğanlar pembeleşinceye kadar ısıt | `while` |
| Evde kekik yoksa nane koy | `if-then-else` |
| Makarnayı süzgeçten tencereye aktar | atama |

Aynı karşılıklar yol tariflerinde de görülür. "Buradan 500 metre git, sonra sola dön" ne kadar gidileceğini baştan söylediği için `for` döngüsüne karşılık gelir. "X'i görünceye kadar düz git, sonra dön" ise bir koşul gerçekleşene kadar devam etmeyi anlatır ve `while` döngüsüne karşılık gelir.

Yani gündelik dilde kullandığımız kalıplar, bilgisayar algoritmalarının ve programlama dillerinin temel yapılarına karşılık gelir.

> **Ek bilgi (derste anlatılmadı):** C'de `for` döngüsü genellikle tekrar sayısı önceden belli olduğunda (`for (i = 0; i < 10; i++)`), `while` döngüsü ise tekrar sayısı bir koşula bağlı olduğunda (`while (!pembelesti)`) kullanılır. İki döngü birbirine dönüştürülebilir; seçim okunabilirliğe göre yapılır.

## 5. Robota Ev Çizdirmek: Neden Programlama Dili?

### 5.1 Deney

Hoca ekranda boş bir beyaz sayfa açtı ve kendisinin bir robot olduğunu söyledi. Bir öğrenciden, robotu sözlü komutlarla yönlendirip ilkokulda çizilen türden bir ev çizdirmesini istedi: kare bir gövde, üçgen çatı, kapı ve pencereler. Robot anladığı komutu uygulayacak, anlamadığını "anlamadım" diye geri çevirecekti.

Öğrenci "biraz daha aşağı inin", "sağa doğru düz bir çizgi çekin", "durun", "yukarıya doğru çizgi çekin" gibi komutlarla önce bir dikdörtgen çizdirdi (ekrandan, 01:36:31). Sonra çatı için "soldaki çizginin üstünden 60 derecelik bir çizgi çekin" gibi komutlar verdi. Komutlar farklı yorumlandığı için çizgiler birkaç kez silinip yeniden çizildi. Sonunda ortaya çatısı yamuk, tuhaf bir ev çıktı (ekrandan, 01:41:31). Hoca öğrenciyi yine de başarılı buldu.

### 5.2 Deneyden çıkan dersler

Hoca öğrencilere bu deneyin neyi gösterdiğini sordu. Gelen cevaplar ve hocanın tamamlamaları:

- **Komutlar kesin ve anlaşılır olmalıdır.** Bilgisayarın ya da makinenin ne anlayacağından emin olacak şekilde ifade edilmelidir.
- **Önce plan yapılmalıdır.** Komut verirken o anda düşünmek zordur. Deneyde robotun neyi anlayıp neyi anlamadığı baştan bilinmiyordu. Bir programlama dilinde ise dilin neyi anladığı önceden bellidir. Bu yüzden önce bir plan yapılır; bu plana algoritma oluşturma denir. Algoritma sonra koda dönüştürülür. Algoritma, koda kolay dönüştürülebilecek biçimde kurulmalıdır.

### 5.3 İnsan dili neden programlama dili olamaz?

Hoca "neden günlük dilimizi kullanarak program yazamıyoruz?" diye sordu. Günlük konuşmanın net olmayan bir yanı vardır. Bir insanla konuşurken her şeyi söylemeyiz, karşımızdakinin birçok şeyi bildiğini varsayarız. İnsan dili insanlar için bile zaman zaman muğlaktır, bilgisayarlar için ise aşırı muğlaktır. Bilgisayara bir işi kesin olarak yaptırmak için insan dili kullanılamaz. Bilgisayarla iletişim kurabilmek için programlama dillerine ihtiyaç vardır. Küçük robot deneyi bu ihtiyacı göstermiştir.

## 6. Algoritma Değil, İyi Algoritma

> **Hocanın vurgusu:** Bu dersteki amaç algoritma geliştirmek değil, iyi algoritma geliştirmektir. Bir şeyi yapmanın birçok yolu vardır ve herkes bir şekilde çözüm bulabilir. Bilgisayar mühendisi olarak sizin iyi çözümler geliştirmeniz gerekir.

Algoritma bir işin yapılma yoludur, iyi algoritma ise iyi bir yapılma yoludur. Peki "iyi"nin içeriği nedir? Hoca "bir algoritma başka bir algoritmadan daha ne olabilir?" diye sordu ve öğrencilerin cevaplarını ekrana yazdı (ekrandan, 01:46:31):

- **Hızlı:** Daha az kontrolle, daha az işlemle aynı işi yapar.
- **Az donanım/enerji:** Daha az kaynak kullanır.
- **Anlaşılabilir:** Daha kolay anlaşılır.
- **Doğru:** Daha az hata yapar. Hoca iki örnek verdi. Hava tahmininde sensör verilerinden tahmin üreten bir algoritma, başka bir algoritmadan daha doğru tahmin üretebilir. Video sitelerinin öneri algoritmaları sürekli değiştirilip geliştirilir. Bir algoritma, kullanıcının izleyeceği şeyleri başka bir algoritmadan daha iyi tahmin edebilir.
- **Modüler:** Bir öğrenci "pizza algoritması pide algoritmasına çevrilebilir" örneğiyle daha kapsamlı ya da çok yönlü bir algoritmayı önerdi. Hoca bunu "modüler" diye adlandırdı. Her işte kullanılabilen bir algoritma olmaz, ama parçaları iyi tasarlanmış bir algoritma olabilir. Hoca modülerliğin biraz da yazılımın kendisiyle ilgili bir özellik olduğunu ekledi.

## 7. Ödünleşim (Trade-off)

Hoca bu ölçütlerin hiçbirinin tek başına her zaman diğerlerinden önemli olmadığını söyledi. Bazı durumlarda hız, bazı durumlarda az donanım ve enerji, bazı durumlarda anlaşılabilirlik ya da doğruluk öne çıkar. Ayrıca genelde bir taraftan kazanırken diğer taraftan kaybedilir. Buna İngilizcede trade-off, Türkçede **ödünleşim** denir. Hocanın ekrana yazdığı örnekler (ekrandan, 01:51:31):

- Daha fazla bellek kullanarak daha hızlı bir algoritma geliştirilebilir.
- Daha fazla enerji (GPU) kullanarak daha hızlı bir algoritma geliştirilebilir.
- Daha yavaş bir algoritma kullanarak daha doğru bir algoritma elde edilebilir.

Hem daha az bellek kullanan hem daha hızlı bir algoritma geliştirmek oldukça zordur. Bütün ölçütlerde birden kazanmak çok nadir görülür.

### 7.1 Durum örnekleri

- **Küçük işlemci:** Çok küçük bir RAM alanında çalışması gereken bir algoritma için az donanım isteyen bir algoritma tasarlanmalıdır. Bu algoritma daha yavaş olacaktır, ama orada ancak o çalışabilir.
- **Video öneri sistemi:** Elinizde çok doğru çalışan ama bir kişi için öneriyi 5-10 saniyede üretebilen bir algoritma olsun. Kullanıcı videoyu bitirmeden önerilerin hazır olması gerekir. Bu yüzden biraz daha az doğru ama çok daha hızlı çalışan bir algoritma tercih edilir.

> **Hocanın vurgusu:** Trade-off'u aklınızdan çıkarmayın. Daha doğru, daha hızlı ya da daha az bellek kullanan bir şey yapmak arasındaki seçim; algoritmanın nerede çalışacağına, hangi amaçla kullanılacağına ve ortamın şartlarına göre değişir. Bu durum birçok yerde karşınıza çıkacak.

## 8. İyi Algoritma Geliştirmek: İteratif Bir Süreç

İyi algoritma genelde tek seferde geliştirilmez. En başta mükemmel bir algoritma geliştirmek gibi bir derdiniz olmasın. Önce bir algoritma geliştirilir. Sonra parçaları incelenir: nereleri yavaş, nereleri çok bellek tüketiyor? Ardından "şurayı şöyle yaparsam daha az bellek kullanır" ya da "şurayı değiştirirsem iki saniyede çalışır" gibi iyileştirmeler yapılır. Bu döngü tekrar eder.

### 8.1 Algoritma geliştirmek nasıl öğrenilir?

> **Hocanın vurgusu:** Algoritma geliştirmek, algoritma geliştirerek öğrenilir. Algoritma geliştirmenin bir algoritması yoktur. Bir problemi nasıl çözeceğinizin bir algoritması olsaydı bilgisayar mühendislerine ihtiyaç kalmazdı.

Hoca kimsenin bunu birine doğrudan öğretemeyeceğini, ancak yardımcı olabileceğini söyledi. Bu beceri zaman içinde, herkesin kendine özgü biçimde oluşur.

Önceki dönemki derste algoritmaları anlamakta ya da yeni bir soruyu algoritmaya dönüştürmekte zorlananlar için **code.org** sitesini önerdi (ekrandan, 01:56:31). Site çocuklar için hazırlanmış gibi görünse de algoritmik düşünceyi ve programlamayı adım adım iyi anlatır. Seviyeler ilerledikçe fonksiyonlar ve parametre gönderme gibi konulara geçer. Görsel, sürükle-bırak bir arayüzü vardır, kod yazarak da çalışılabilir. Hoca sitedeki bütün seviyelerin bitirilmesini önerdi. Bu problemleri çözebilecek hale gelmek, bu dersin altyapısını da sağlar.

## 9. Gauss Toplamı: N İşlemden 3 İşleme

### 9.1 Hikaye

Gauss, yaşamış en iyi matematikçilerden biri kabul edilir. İlkokuldayken öğretmeninin yapması gereken bir iş varmış ve bu sırada sınıfın sessiz oturması gerekiyormuş. Öğretmen öğrencilerden 1'den 100'e kadar sayıların toplamını bulmalarını istemiş. Gauss sayıları kağıda yazmış ve şunu fark etmiş:

- Baştaki ile sondakinin toplamı: $1 + 100 = 101$
- Baştan ikinci ile sondan ikincinin toplamı: $2 + 99 = 101$
- Bu şekilde 50 tane çift, yani 50 tane 101 vardır.

Sonuç (ekrandan, 01:56:31):

$$1 + 2 + 3 + \dots + 100 = 50 \cdot 101 = 5050$$

### 9.2 Genel formül

Aynı düşünce $N$ için genellenir (ekrandan, 01:56:31):

$$1 + 2 + \dots + N = \frac{N}{2} \cdot (N + 1)$$

Hoca formülü önce sözlü olarak "n çarpı n artı 1 bölü 2" diye kurdu, ekranda yazarken işlem önceliği için parantezleri düzeltti. Bir öğrenci $N \cdot (N+1)$ kısmının paranteze alınmasını önerdi. Hoca formülü yukarıdaki $50 \cdot 101$ yapısına uygun olarak $(N/2)\cdot(N+1)$ biçiminde bıraktı.

### 9.3 İki algoritmanın karşılaştırılması

Burada aynı problemi çözen iki algoritma vardır (ekrandan, 02:01:31):

| Algoritma | İşlem sayısı |
|---|---|
| $1 + 2 + \dots + N$ (döngüyle tek tek topla) | $N$ işlem |
| $(N/2) \cdot (N+1)$ | 3 işlem |

Birinci yol bir `for` döngüsüyle yapılır ve $N$ tane toplama ister. İkinci yolda $N$'e bağlı bir şey yoktur: bir toplama, bir bölme ve bir çarpma, toplam 3 işlem. Birinci yoldaki işlemlerin hepsi toplamadır, ikincide birbirinden farklı üç işlem vardır.

İkisi de doğru sonucu veren birer algoritmadır, ama ikincisi açıkça daha iyidir.

### 9.4 "Bilgisayarlar zaten hızlı" yanılgısı

Bilgisayarlar çok hızlı olduğu için hangisini yazdığımızın fark etmeyeceği düşünülebilir. Gerçekten de 1'den 100'e ya da 1 milyona kadar toplamayı bilgisayar çok hızlı yapar. Ama birinci algoritma $N$ işlem aldığı için $N$ büyüdükçe kötüleşir. İkinci algoritmanın süresi ise $N$ ne kadar büyürse büyüsün artmaz.

Eleman sayısına bağlı bir işlemi sabit sayıda işleme dönüştürmek mükemmel bir iyileştirmedir. Hoca bu tür bir indirgemeye pek sık rastlanmadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** C'de `int` bölmesi tam sayı bölmesidir. $N$ tek olduğunda `(N/2)*(N+1)` ifadesi küsuratı atar ve yanlış sonuç verir. Örneğin $N = 7$ için doğru toplam 28'dir, ama `(7/2)*(7+1)` $= 3 \cdot 8 = 24$ olur. Formül C'de `N*(N+1)/2` sırasıyla yazılmalıdır. $N(N+1)$ her zaman çift olduğu için bölme tam çıkar.

Aşağıdaki program derste yazılmadı. Ek bilgideki farkı göstermek için hazırlandı ve `gcc -Wall` ile uyarısız derlendi. Girdi 100 iken üç satır da 5050, girdi 7 iken döngü 28, `(N/2)*(N+1)` 24, `N*(N+1)/2` 28 verdi.

```c
#include <stdio.h>

int main(void)
{
    int n, i;
    long toplam = 0;

    if (scanf("%d", &n) != 1)
        return 1;

    for (i = 1; i <= n; i++)      /* n islem */
        toplam += i;

    printf("dongu: %ld\n", toplam);
    printf("formul (N/2)*(N+1): %ld\n", (long)(n / 2) * (n + 1));
    printf("formul N*(N+1)/2: %ld\n", (long)n * (n + 1) / 2);
    return 0;
}
```

## 10. Karmaşıklığı Azaltmanın Etkisi

### 10.1 Farklı iyileştirme düzeyleri

Bir algoritmanın bu kadar mükemmel olması gerekmez. $N$'den 3'e inmek her zaman mümkün değildir. Hocanın ekrana yazdığı başka iyileştirme türleri (ekrandan, 02:06:31):

- $N \to N/2$: İş yarıya iner. Hiç fena değildir.
- $N \cdot N \to N$: Bayağı iyi bir iyileştirmedir. $N$'nin bir milyar olduğunu düşünün.
- $N \to \log_2 N$: Çok büyük bir iyileşmedir.

### 10.2 Logaritmik iyileşmenin sayısal örneği

Hoca 2 tabanında logaritmanın değerlerini öğrencilere sordu ve ekrana yazdı (ekrandan, 02:11:31):

| $N$ | $\log_2 N$ (yaklaşık) |
|---|---|
| 1000 | 10 |
| 1 000 000 | 20 |
| 1 000 000 000 | 30 |

Hesap ($2^{10} = 1024 \approx 1000$ olduğundan, ara adım eklendi):

- $\log_2 1000 \approx 10$
- $1\,000\,000 = 1000 \cdot 1000$ olduğu için $\log_2 10^6 \approx 10 + 10 = 20$
- $\log_2 10^9 \approx 10 + 10 + 10 = 30$

Python ile kontrol: $\log_2 1000 \approx 9{,}97$, $\log_2 10^6 \approx 19{,}93$, $\log_2 10^9 \approx 29{,}90$. Tablodaki yaklaşık değerler doğrudur.

Yani 1000 elemanlı bir dizi üzerinde $N$ adımda yapılan bir iş 1000 adım sürer, $\log_2 N$ adımda yapılırsa 10 adım sürer. Girdi 1000 katına çıktığında $N$'lik algoritmanın adım sayısı da 1000 katına çıkar, $\log_2 N$'lik algoritmanınki ise yalnız 10 artar (10'dan 20'ye). 1 milyon adım yerine 20, 1 milyar adım yerine 30 adım atılır. Formüllü Gauss çözümünde ise $N$ bin de olsa, milyon da olsa, milyar da olsa işlem sayısı 3'tür.

Dönem boyunca genelde $N \to N/2$, $N^2 \to N$, $N \to \log_2 N$ gibi hızlandırma yöntemleri üzerinde çalışılacaktır.

### 10.3 Neden hâlâ iyi algoritmaya ihtiyaç var?

Bilgisayarlar ne kadar hızlanırsa hızlansın, mühendislerin işlediği veri miktarı da büyür. Hoca, bir bilgisayar mühendisinin muhatap olduğu veri büyüklüklerinin bilgisayarların hızından çok daha hızlı arttığını söyledi. Bu yüzden iyi algoritmaya olan ihtiyaç artmaktadır.

Hoca "zaten bütün algoritmalar yazılmış, biz onları kullanacağız" düşüncesine de karşı çıktı. Mühendis, üzerinde çalıştığı algoritmaların yapısını, avantajlarını, dezavantajlarını ve hangi durumlarda çalışıp hangilerinde çalışmadığını bilmelidir. Hazır kütüphane kullanmak işin bir parçasıdır, ama tek işiniz bu değildir. İşe özel kendi kütüphanelerini yazmak ya da başkalarının yazdıklarını iyileştirmek de mühendisin işidir.

> **Hocanın vurgusu:** Algoritmayı herkes geliştirecek, ama sizler iyi algoritmalar geliştireceksiniz.

## 11. Google ve PageRank: İyi Bir Algoritmanın Sonuçları

### 11.1 Arama motorlarının durumu

Hoca, uç bir örnek olarak arama motorlarının tarihini anlattı. Bir dönem Yahoo ve AltaVista gibi arama motorları vardı. Sorgu gönderildiğinde web sayfalarını döndürüyorlardı ve iyi çalıştıkları düşünülüyordu. Kimse daha iyi bir arama motorunun ne olabileceğini sorgulamıyordu.

Sonra Google çıktı. Hoca tarihi tam hatırlamadığını, 1997 ya da 1999 civarı olduğunu söyledi. Google'ı bir iki gün kullanan herkes diğer arama motorlarını bıraktı. Birkaç ay içinde diğerlerinin kullanımı çok hızlı düştü, Google'ınki çok hızlı arttı.

> **Ders sonrası not:** Hoca tarihi "97'ler ya da 99" diye belirsiz verdi. Google büyük olasılıkla 1998'de kurulmuştur.

### 11.2 Google'ı farklı kılan ne?

Yöneticilerin vizyonu gibi başka etkenler de vardı, ama çok önemli bir parça algoritmaydı. Google, kullanıcının aramasıyla bir web sayfası arasındaki benzerliği, **web sayfasının güvenilirliğiyle** birleştirdi. Güvenilirlik, sayfada yazanların doğru ve anlamlı olmasıdır.

Güvenilirliği hesaplamak için **PageRank** algoritması kullanılır. Yayımlandığı haliyle bilinen mantığı şudur: bir siteye diğer sitelerden ne kadar çok link veriliyorsa o site o kadar güvenilirdir. İnsanlar bir siteye ne kadar çok referans veriyorsa oradaki bilgiler o kadar güvenilirdir. Hoca algoritmanın bugünkü halinin çok fazla bilinmediğini ekledi.

### 11.3 Ölçeklenebilirlik

PageRank, sayfaların güvenilirliğini hesaplama işini ölçeklenebilir hale getirdi. Ölçeklenebilirlik, önceki bölümde konuşulan iyileştirmelere benzer: önceden $N^2$ olan bir işi $N$ haline getirmek o işi çok daha ölçeklenebilir yapar.

Önceki arama motorlarında web sayfalarının kategorilere ayrılması elle yapılıyordu. Binlerce çalışan yeni çıkan sayfaların içeriğine bakıp onları kategorilere ayırıyordu. Web sayfası sayısı üstel bir şekilde artmaya başladığında bu yöntem sürdürülemedi, çünkü çalışan sayısının da üstel artması gerekirdi. Google bu işi otomatik ve ölçeklenebilir bir modelle yapan bir algoritma geliştirdi. Kullanıcıların hızla Google'a geçmesini sağlayan parça büyük ölçüde bu algoritmaydı.

### 11.4 İyileştirmeyi bekleyen problemler

Hoca iyi haberin şu olduğunu söyledi: yapılmış çok şey var, ama iyileştirilmeyi ve çözülmeyi bekleyen daha çok problem var. Google çıktığında kimse daha iyi bir arama motoru beklemiyordu. Bugün de Google'dan daha iyi bir arama motoru çıkabilir. Şirketlerin ömrü artık çok uzun değildir. 2000'li yıllarda cep telefonu pazarına hakim olan Nokia ve Ericsson'un bu konumu kaybedeceğini kimse düşünemezdi. "Zaten yapılmış, daha iyisi olur mu?" diye düşünmenin anlamı yoktur. Bu problemleri çözmek için gereken teknikler ders boyunca görülecektir.

> **Ek bilgi (derste anlatılmadı):** PageRank'te bir sayfanın puanı, ona link veren sayfaların puanlarından hesaplanır. Önemli sayfalardan gelen bir link, önemsiz sayfalardan gelen linkten daha değerlidir. Hesap, puanlar değişmeyi bırakana kadar tekrarlanan iteratif bir yöntemle yapılır.

### 11.5 Ders sonundaki soru

**Soru:** Ekranda yazdığımız örneklerde işlemleri tek tek saydığımız için karşılaştırma kolaydı. İçinde çok sayıda döngü olan algoritmaların işlem sayısını nasıl hesaplayacağız? **Cevap:** Bunların hepsi dönem içinde görülecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:21:28): Algoritma ne demektir?

> **Cevap (derste verildi):** Bir problemi çözmek için atılması planlanan tanımlı, sonlu adımlar dizisidir.

**Soru 2** (derste sözlü, 01:29:40): Yemek tariflerindeki şu ifadeler programlamada neye karşılık gelir? (a) "10 dakika ısıt", (b) "Soğanlar pembeleşinceye kadar ısıt", (c) "Evde kekik yoksa nane koy", (d) "Makarnayı süzgeçten tencereye aktar".

> **Cevap (derste verildi):** (a) `for`, (b) `while`, (c) `if-then-else`, (d) atama.

**Soru 3** (derste sözlü, 01:40:03): Neden günlük hayatta kullandığımız dili kullanarak program yazamıyoruz?

> **Cevap (derste verildi):** İnsan dili bilgisayarlar için çok muğlaktır. Konuşurken birçok şeyi söylemeyiz ve karşı tarafın bildiğini varsayarız. Bilgisayara bir işi kesin olarak yaptırmak için kuralları belli programlama dilleri gerekir.

**Soru 4** (ekrandan, 01:46:31): Bir algoritma başka bir algoritmadan "daha" ne olabilir? İyi algoritmanın ölçütleri nelerdir?

> **Cevap (derste verildi):** Daha hızlı, daha az donanım/enerji kullanan, daha anlaşılabilir, daha doğru, daha modüler. Bu ölçütler arasında genelde ödünleşim (trade-off) vardır.

**Soru 5** (ekrandan, 01:56:31): $1 + 2 + 3 + \dots + 100 = ?$ Genel olarak $1 + 2 + \dots + N$ nasıl hesaplanır ve iki yöntem kaç işlem ister?

> **Cevap (derste verildi):** $50 \cdot 101 = 5050$. Genel halde $(N/2)\cdot(N+1)$. Döngüyle toplama $N$ işlem, formül 3 işlem ister (ekrandan, 02:01:31). Python ile kontrol edildi: toplam 5050'dir.

**Soru 6** (derste sözlü, 01:59:48): Bir algoritmanın karmaşıklığını $N \cdot N$'den $N$'e indirmek iyi bir şey midir? Neden?

> **Cevap (derste verildi):** Bayağı iyidir. $N$ milyar mertebesinde olduğunda $N^2$ ile $N$ arasındaki fark çok büyüktür.

**Soru 7** (ekrandan, 02:06:31): $N \to \log_2 N$ iyileştirmesinde $N = 1000$, $N = 1\,000\,000$ ve $N = 1\,000\,000\,000$ için adım sayısı yaklaşık kaça iner?

> **Cevap (derste verildi):** Yaklaşık 10, 20 ve 30 (ekrandan, 02:11:31). Girdi 1000 katına çıktığında adım sayısı yalnız 10 artar. Python ile kontrol: 9,97; 19,93; 29,90.

## Dersin Toparlaması

Bu derste algoritmanın bir problemi çözmek için tanımlı, sonlu adımlar dizisi olduğu ve günlük hayattaki tariflerin de birer algoritma olduğu görüldü. Omlet ve pizza tarifleri algoritmanın net olması gerektiğini gösterdi. "Süresi belli tekrar", "koşul oluşana kadar tekrar", "seçim" ve "aktarma" gibi gündelik kalıpların `for`, `while`, `if-else` ve atamaya karşılık geldiği anlatıldı. Robota ev çizdirme deneyi, belirsiz komutların sorun çıkardığını, önce plan yapmanın gerektiğini ve insan dilinin muğlaklığı yüzünden programlama dillerine ihtiyaç duyulduğunu gösterdi.

Dersin ikinci yarısında amacın algoritma değil iyi algoritma geliştirmek olduğu vurgulandı. İyi algoritmanın ölçütleri (hız, az donanım/enerji, anlaşılabilirlik, doğruluk, modülerlik) ve bunlar arasındaki ödünleşim incelendi. Gauss toplamı, $N$ işlemlik bir çözümün 3 işleme indirilebileceğini gösterdi. $\log_2$ örneği karmaşıklığı azaltmanın büyük veride ne kadar önemli olduğunu sayılarla ortaya koydu. Google ve PageRank örneği iyi bir algoritmanın sonuçlarını gösterdi. Döngü içeren algoritmaların işlem sayısının nasıl hesaplanacağı ve hızlandırma teknikleri dönemin ilerleyen derslerinde ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
