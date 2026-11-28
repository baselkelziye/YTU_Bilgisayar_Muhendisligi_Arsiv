# Ders 1 Genişletilmiş Notu: Biyoenformatiğin Alt Alanları, Bilgi Sistemlerinin Temelleri ve Moleküler Biyolojiye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- BELİRSİZ: Bu kaydın altyazısı uzun Whisper tekrarları ve anlaşılmayan Türkçe-İngilizce karışık parçalarla doludur. Not, okunabilen altyazı parçaları ve ekran karelerinden kurulmuştur. Karede görülmeyen ve altyazıda bozuk kalan bölümler (özellikle ilaç geliştirme döngüsünün devamı, ASCII özellikleri, mantık işlemleri, hücre videosu ve mRNA şeması) eksik kalmış olabilir. -->

## İçindekiler

- 1. Hesaplamalı Biyolojinin Alt Alanları
- 2. Biyoenformatik Neden Önemli?
- 3. Biyoenformatik Araçları ve Programlama
- 4. Tekrarlanabilir Araştırma
- 5. Veri, Bilgi ve Bilgi Birikimi
- 6. Sistem, Bilgi Sistemi ve Dijital Sistem
- 7. Sürekli Bilginin Ayrık Hale Getirilmesi
- 8. Sayı Sistemleri ve Sayısal Veri Türleri
- 9. Sayısal Olmayan Verinin Gösterimi
- 10. Biyomedikal Verinin Doğası ve Metaveri
- 11. Hücreler: Prokaryotlar ve Ökaryotlar
- 12. Kromozomlar ve DNA
- 13. Genetik Kod
- 14. Amino Asitler ve Proteinler
- 15. Örnek Vaka: HIV Proteazı
- 16. RNA ve mRNA İşlenmesi
- Örnek Sorular

## 1. Hesaplamalı Biyolojinin Alt Alanları

Ders, bir önceki girişin devamı olarak hesaplamalı biyolojinin alt alanlarını tek tek ele alarak başladı. Hoca, DNA ve benzeri biyolojik kavramların sonraki derslerde ayrıca anlatılacağını, ama bunların biyoloji derslerinden hatırlanması gerektiğini söyledi.

### 1.1 Genomik

"-omics" eki bir şeyin incelenmesi anlamına gelir; genomik de genomun incelenmesidir. Slayttaki tanım şöyledir (ekrandan, 00:05:00):

- Genomik, genomu inceler; genom bir organizmada bulunan genetik malzemenin ya da DNA'nın tamamıdır.
- Bir organizmadaki bütün genleri ve aralarındaki ilişkileri, organizmanın büyümesi ve gelişmesi üzerindeki ortak etkilerini belirlemek için inceler.

Hoca genomu bir insanın genetik "planı" (blueprint) olarak niteledi.

### 1.2 Proteomik

Proteomik, proteomun büyük ölçekli incelenmesidir. Proteom, bir organizmada, sistemde ya da biyolojik bağlamda üretilen proteinlerin kümesidir. Genomdan farklı olarak proteom sabit değildir: hücreden hücreye farklıdır ve zamanla değişir. Proteom bir ölçüde altta yatan transkriptomu yansıtır, ama protein etkinliği ilgili genin ifade düzeyinin yanında başka birçok etkene de bağlıdır.

Proteomik şu soruları araştırmak için kullanılır:

- proteinlerin ne zaman ve nerede ifade edildiği,
- protein üretim hızları, düzenlenmeleri ve kararlı durum miktarları,
- proteinlerin nasıl değiştirildiği (modifiye edildiği).

Proteomik birçok biyolojik problem için önemli bilgi sağlar. Hocanın örnek verdiği sorular şunlardır: belirli bir proteinle hangi proteinler etkileşir, hangi proteinler belirli bir hücre içi bölmeye yerleşir, hangi proteinler belirli bir biyolojik sürece katılır. Hoca, protein etkileşimlerini hesaplamalı olarak inceleyen çok sayıda biyoenformatik çalışması olduğunu ve biyoenformatiğe yönelen öğrencilerin bu tür çalışmalarla karşılaşabileceğini söyledi.

### 1.3 Yapısal Biyoenformatik

Yapısal biyoenformatik (yapısal genomik), protein, RNA ve DNA gibi biyolojik makromoleküllerin üç boyutlu yapısının analizi ve tahminiyle ilgilenen daldır. Makromoleküler yapı hakkında genellemeler yapar: katlanma biçimlerinin ve yerel motiflerin karşılaştırılması, moleküler katlanma ilkeleri, evrim, bağlanma etkileşimleri ve yapı-işlev ilişkileri. Hem deneysel olarak çözülmüş yapılarla hem de hesaplamalı modellerle çalışır.

### 1.4 Fonksiyonel Genomik

Fonksiyonel genomik, moleküler biyolojinin bir alanıdır ve genomik ile transkriptomik projelerin ürettiği büyük veriyi gen işlevlerini ve etkileşimlerini betimlemek için kullanmaya çalışır.

## 2. Biyoenformatik Neden Önemli?

### 2.1 Veri Büyümesi

Hoca, GenBank veritabanının büyümesini gösteren bir grafik gösterdi ve büyümenin bugün grafikte görülenden çok daha yüksek olduğunu belirtti. <!-- BELİRSİZ: Grafiğin yılları ve değerleri karede görülmedi. -->

### 2.2 Hastalıklarla Mücadele

Biyoenformatiğin temel amaçlarından biri insan hastalıklarıyla mücadeledir. Diyabet gibi genetik olarak kalıtılan hastalıklar ve COVID gibi viral hastalıklar örnek olarak anıldı.

### 2.3 İlaç Geliştirme Yaşam Döngüsü

Slaytta ilaç geliştirme yaşam döngüsü yıllara yayılan bir zaman çizelgesi olarak gösterildi (ekrandan, 00:15:00). Karede görülen ilk iki aşama şunlardır:

- Keşif (Discovery): 2-10 yıl.
- Klinik öncesi test (Preclinical Testing): laboratuvar ve hayvan testleri.

Altyazıya göre bir madde keşfedildikten sonra laboratuvarda ve hayvanlarda test edilir, ardından fazlar halinde klinik deneyler gelir ve son olarak ilgili kurum (ABD'de ilaç ajansı, Türkiye'de Sağlık Bakanlığı ya da başka ülkelerin kurumları) ilacın kullanımını onaylar. <!-- BELİRSİZ: Klinik fazların süreleri ve hasta sayıları (altyazıda "1000-5000" geçiyor) karede görülmedi. -->

> **Ek bilgi (derste anlatılmadı):** İlaç geliştirmede klinik deneyler büyük olasılıkla slayttaki gibi Faz I (az sayıda sağlıklı gönüllüde güvenlik), Faz II (sınırlı hasta grubunda etkinlik) ve Faz III (geniş hasta grubunda doğrulama) olarak sıralanır. Onaydan sonra piyasadaki kullanımın izlendiği aşamaya Faz IV denir.

### 2.4 "Killer Application": Kişiselleştirilmiş Tıp

Biyoteknoloji sektöründe her araştırmacı ve girişimci bir sonraki "killer app"i, yani sektörü dönüştürecek uygulamayı geliştirmeyi ya da keşfetmeyi umar (ekrandan, 00:20:00). Hoca bunun kişiselleştirilmiş tıp olduğunu anlattı: herkesin kendine özgü bir ilacı olması. Ancak az önce görülen yaşam döngüsü 5-15 yıl sürdüğü için kişiye özel ilaç ancak bu sürecin kısaltılmasıyla mümkün olabilir.

Slayttaki ifadeler şöyledir (ekrandan, 00:25:00):

- İlaç şirketlerinin çoğu bilgisayarlaştırmayı, kişiye özel üretime odaklanan daha küçük ölçekli ilaç üretiminin çözümü olarak görür.
- Açık hesaplama uygulamaları şunları kapsar:
  - genom analizine dayanarak ilaçların etkinliğini ve yan etkilerini tahmin etmek,
  - belirli ilaçların etkinliğini daha iyi anlamak ve tahmin etmek için protein yapılarını görselleştirmek,
  - rakip ilaçların göreli etkinliğini yaşam kalitesi ve maliyet açısından, Faz IV klinik deneyler sırasında olası sonuçların Markov benzetimine dayanarak göstermek.

Hoca, bu döngünün özellikle test süreçlerine yoğun biçimde bağlı olduğunu ve biyoenformatiğin bu döngüyü kısaltmaya katkı verdiğini vurguladı.

## 3. Biyoenformatik Araçları ve Programlama

NCBI ve EBI gibi merkezi kaynaklar, birçok genom tarayıcısı, web tabanlı uygulamalar ve kurulup kullanılan yazılım araçları vardır; bunlar ilerleyen derslerde ele alınacaktır.

Hoca iki soru sordu ve cevapladı:

- Linux işletim sistemini kullanmayı öğrenmeli miyiz? Evet, elbette.
- Python, Perl ya da R öğrenmeli miyiz? Elbette; bu derste çoğunlukla Perl kullanılacaktır.

Programlama öğrenmek için mevcut kitap ve derslerin yanında birçok web sitesi öğretici ya da kurs biçiminde çevrim içi eğitim sunar (ekrandan, 00:30:00). Slaytta gösterilen siteler şunlardır (ekrandan, 00:40:00): codeschool.com, codecademy.com, datacamp.com, software-carpentry.org, github.com. Ayrıca daha fazla bilgi için NCBI (ncbi.nlm.nih.gov), bioinformatics.org, kitaplar, dergiler ve konferanslar önerildi.

Hoca öğrenmenin kişinin kendisinin yapmasıyla kalıcı hale geldiğini, bir şeyi kendiniz yaptığınızda onun sizin olduğunu söyledi. Lisans süresince yapılan bitirme projesi gibi projelerde bu becerilerin kullanılabileceğini de ekledi. <!-- BELİRSİZ: 00:26-00:35 arasındaki anlatımın büyük kısmı altyazıda okunamıyor. -->

## 4. Tekrarlanabilir Araştırma

Slayttaki tanım şöyledir (ekrandan, 00:35:00):

- Bilim doğası gereği birikimli ve ilerleyicidir.
- Web tabanlı ya da komut satırı araçları kullanılsın, araştırma hem araştırmacının kendisi hem de başkaları tarafından tekrarlanabilecek biçimde yürütülmelidir.

Hoca bunun için şu alışkanlıkları sıraladı:

- İş akışı iyi belgelenmelidir. Bilgisayarda karmaşık komutları, URL'leri ve başka veri parçalarını kopyalayıp yapıştırabileceğiniz metin dosyaları tutulabilir.
- Bilgisayarda saklanan bilgi düzenli olmalıdır.
- Veri başkalarına açık hale getirilmelidir.
- Metaveri, verinin kendisi kadar önemlidir. Elinizde büyük bir veri dosyası olabilir; onu açıklayan metaveri yoksa ileride verinin ne olduğunu hatırlamakta sorun yaşarsınız.
- Programlara açıklama satırı yazılmalıdır; yazılmazsa birkaç ay sonra kendi programınızla bile zorlanabilirsiniz.

Hoca biyoenformatiğin araştırma alanlarını da özetledi: protein analizi ve yapı tahmini, yeni nesil dizileme teknolojileri, hesaplamalı biyoloji, sistem biyolojisi, metin madenciliği ve bilgi çıkarma. Daha fazla öğrenmek için Google araması, makale okuma, dergiler ve konferanslar önerildi. <!-- BELİRSİZ: Araştırma alanları listesi altyazıdan kırık biçimde çıkarıldı, karede görülmedi. -->

## 5. Veri, Bilgi ve Bilgi Birikimi

Girişten sonra hoca "temeller" slaytlarına geçti ve bunların çoğunun öğrenciler tarafından daha önce görüldüğünü, ama hatırlatmanın her zaman yararlı olduğunu söyledi. Enformatik (informatics) kelimesi bilgi (information) ve otomatik (automatic) sözcüklerinin birleşiminden türemiştir; bilgi işlemenin otomasyonu, bilgi bilimi anlamına gelir.

Slayttaki ilk tanım (ekrandan, 00:45:00):

- **Veri (data):** yorum ya da analiz eklenmemiş, işlenmemiş olgu ve rakamlardır. Örnek: "Ham petrolün fiyatı varil başına 80 dolardır."

Altyazıya göre:

- **Bilgi (information):** yorumlanmış ya da işlenmiş, kullanıcı için anlamı olan veridir. Veriyi işleriz ve bilgi elde ederiz.
- **Bilgi birikimi (knowledge):** zamanla elde edilen çok sayıda bilgi birikerek bilgi birikimine dönüşür.

<!-- BELİRSİZ: "Information" ve "knowledge" slaytlarındaki örnek cümleler karede görülmedi. -->

Hoca verinin bazı önemli özellikleri olduğunu ve veriye daha sonra dönüleceğini söyledi.

## 6. Sistem, Bilgi Sistemi ve Dijital Sistem

### 6.1 Sistem

Sistem, belirli amaçları gerçekleştiren bütünleşik öğeler kümesidir. Hoca bu kısa tanımı üç özelliğe ayırdı:

- Sistemin bileşenleri ya da alt öğeleri vardır.
- Bu öğeler birbiriyle ilişkilidir.
- Öğeler belirli bir amaç etrafında toplanır, ortak bir nihai hedefleri vardır.

Bu özellikler sağlanıyorsa ayrı öğeler bir sistem oluşturur.

### 6.2 Bilgi Sistemi ve Bilgi Teknolojisi

Bilgi sistemleri, kuruluşların bilgilerini şu yollarla ele almasıdır (ekrandan, 00:50:00):

- saklama (store),
- taşıma (move),
- düzenleme (organize),
- işleme (process).

Bilgi teknolojisi (IT), bilgi sistemlerini gerçekleştiren bileşenleri kapsar: donanım (yalnız bilgisayarlar değil, kağıt gibi araçlar da) ve yazılım.

### 6.3 Dijital Sistem

Dijital sistem, ayrık bir bilgi kümesini (girişler) ve ayrık iç bilgiyi (sistem durumu) alır ve ayrık bir bilgi kümesi (çıkışlar) üretir (ekrandan, 00:55:00). Slayttaki blok şema şöyledir:

```text
Ayrık girişler  --->  [ Ayrık Bilgi İşleme Sistemi ]  --->  Ayrık çıkışlar
                              |            ^
                              v            |
                          [   Sistem Durumu   ]
```

Hoca buradaki anahtar kelimenin "ayrık" (discrete) olduğunu vurguladı: girişler, iç durumlar ve çıkışlar ayrıktır.

## 7. Sürekli Bilginin Ayrık Hale Getirilmesi

Modern hesaplama sistemleri iki kısıta tabidir: sınırlı bellek ve sınırlı işlem gücü. Sürekli bilgi sonsuz miktarda bilgi demektir. Bunu işlemek için sonsuza kadar beklemek ve sonsuz büyüklükte bellek gerekir. Bu yüzden sonsuz bilgi sonlu hale getirilmelidir.

Bunun için kullanılan teknik **örnekleme**dir (sampling): sürekli bilgi örneklenerek ayrık bilgi elde edilir. Ardından örnekler **nicemlenir** (quantization) ve ikili kodlanır. Derste verilen örnekte sinyal 8 seviyeye nicemlendi; her seviye bir ikili kodla gösterildi. Gereken bit sayısı seviye sayısının iki tabanında logaritmasıdır:

$$\log_2 8 = 3 \text{ bit}$$

Yani 3 bit bu bilgiyi kodlamaya yeter. <!-- BELİRSİZ: Örnekleme grafiği ve örnek değerleri karede görülmedi. -->

Hoca iki hata kaynağını belirtti:

- Örnekler arasındaki bilgi kalıcı olarak kaybolur.
- Örnek değerleri yukarı ya da aşağı yuvarlanır; buna nicemleme hatası denir.

Bilginin çoğunu kaybetmemize rağmen elde kalan bilgi, işimizi görecek kadar yeterlidir. Analog sinyallerin dijitale çevrilmesi analog-dijital çeviricilerle yapılır.

## 8. Sayı Sistemleri ve Sayısal Veri Türleri

Hesaplama sisteminde iki ana veri türü temsil edilir: nicel (quantitative) veri, yani sayılar, ve nitel (qualitative) veri, yani renkler, müzik, metin, kodlar gibi sayı olmayan şeyler. Önce sayısal veri türlerine bakıldı.

### 8.1 Konumsal Sayı Sistemleri

Slayttaki tanım şöyledir (ekrandan, 01:05:00): pozitif tabanlı, konumsal sayı sistemlerinde taban (radix) $r$ olan bir sayı basamak dizisiyle gösterilir:

$$A_{n-1}A_{n-2}\dots A_1A_0 \, . \, A_{-1}A_{-2}\dots A_{-m+1}A_{-m}$$

Burada $0 \le A_i < r$ ve nokta taban noktasıdır (radix point). Basamak dizisi şu kuvvet serisini gösterir:

$$(\text{Sayı})_r = \left(\sum_{i=0}^{n-1} A_i \cdot r^i\right) + \left(\sum_{j=-m}^{-1} A_j \cdot r^j\right)$$

Birinci toplam tam kısmı, ikinci toplam kesir kısmını verir. Hoca, onluk sistemde $A_0$'ın birler basamağı, $A_1$'in onlar basamağı olduğunu, ağırlıkların 1, 10, 100, 1000 diye gittiğini; noktanın sağında ise 1/10, 1/100 diye devam ettiğini hatırlattı. İkilik sistemde $A_0$'ın ağırlığı $2^0$'dır.

### 8.2 İşaretsiz İkili Tamsayılar

İşaretsiz tamsayı, hesaplama sisteminde kullanılan temel veri türüdür; onluk bir sayının ikiliye çevrilmiş halidir. Slayttaki örnek (ekrandan, 01:10:00):

$$Y = \text{"abc"} = a \cdot 2^2 + b \cdot 2^1 + c \cdot 2^0$$

Burada $a$, $b$, $c$ basamakları yalnız 0 ya da 1 olabilir. $N$ bit sayısıdır. Slayttaki tablo:

| Onluk | 3 bit | 5 bit | 8 bit |
|---|---|---|---|
| 0 | 000 | 00000 | 00000000 |
| 1 | 001 | 00001 | 00000001 |
| 2 | 010 | 00010 | 00000010 |
| 3 | 011 | 00011 | 00000011 |
| 4 | 100 | 00100 | 00000100 |

Aralık $0$ ile $2^N-1$ arasıdır. Örneğin 3 bitle 0-7, 4 bitle 0-15 gösterilir.

> **Ders sonrası not:** Slaytta aralık "$0 \le i < 2^N - 1$" yazıyor; altyazıya göre hoca da büyük olasılıkla bu işarete değindi. Doğrusu $0 \le i \le 2^N - 1$'dir (3 bitte en büyük değer 7'dir).

### 8.3 İşaretli İkili Tamsayılar: İkiye Tümleyen

C'de bir değişken tanımladığınızda varsayılan olarak işaretli tamsayı kullanılır. İkiye tümleyen gösteriminde dönüşüm kuralı şöyledir (ekrandan, 01:15:00): $a$'yı $-a$'ya çevirmek için $a$'nın bütün bitleri ters çevrilir ve sonuca 1 eklenir. Slayttaki 5 bitlik tablo:

| Onluk | 5 bit |
|---|---|
| -16 | 10000 |
| ... | ... |
| -3 | 11101 |
| -2 | 11110 |
| -1 | 11111 |
| 0 | 00000 |
| +1 | 00001 |
| +2 | 00010 |
| +3 | 00011 |
| ... | ... |
| +15 | 01111 |

Aralık $-2^{N-1}$ ile $2^{N-1}-1$ arasıdır; 3 bitte $-4$ ile $+3$ arası.

> **Ders sonrası not:** Slaytta aralık "$-2^{N-1} < i < 2^{N-1} - 1$" diye kesin eşitsizlikle yazıyor. Doğrusu $-2^{N-1} \le i \le 2^{N-1} - 1$'dir; tablodaki $-16$ ve $+15$ değerleri de aralığa dahildir.

Hoca burada bir soru sordu: en anlamlı bitin 1 olması "eksi işareti" demek midir? Bu bit eksiyi gösteriyor diye düşünülürse cevap yanlış olur.

> **Hocanın vurgusu:** Doğru düşünce ağırlıklı sayı sistemidir. Biz de bilgisayar da ağırlıklı sayı sistemini kullanırız: her basamak ağırlığıyla çarpılır ve toplanır. İkiye tümleyende de kavram tamamen aynıdır; tek fark en anlamlı bitin ağırlığının negatif olmasıdır.

5 bitte ağırlıklar $-16, 8, 4, 2, 1$'dir. Derste çözülen örnekler:

- $10000$: $0 \cdot 1 + 0 \cdot 2 + 0 \cdot 4 + 0 \cdot 8 + 1 \cdot (-16) = -16$.
- $11101$: önce alt bitler, $1 \cdot 1 + 0 \cdot 2 + 1 \cdot 4 = 5$; sonra $1 \cdot 8$ eklenince $13$; son olarak $1 \cdot (-16)$ eklenince $-16 + 13 = -3$.

Hoca, işaret-büyüklük gösterimi ile ikiye tümleyen gösterimi arasındaki temel farkın bu olduğunu söyledi.

> **Hocanın vurgusu:** Bu gösterim önemlidir, çünkü modern hesaplama sistemlerindeki bütün aritmetik işlemler bu sayı sistemiyle yapılır.

### 8.4 Kayan Noktalı Sayılar (IEEE-754)

Tamsayılar yetmediğinde kesirli sayılar için IEEE-754 kayan noktalı biçimi kullanılır; C'deki float değişkeni 32 bitlik bu biçimdedir. Slayttaki örnek (ekrandan, 01:20:00):

$$25.75 \Rightarrow 00011001.110 \Rightarrow 1.1001110 \times 2^4$$

Adımlar:

- Tam kısım: $25 = 11001_2$.
- Kesir kısmı: $0.75 = 0.5 + 0.25 = 0.11_2$.
- Birleşince $25.75 = 11001.11_2$ (slaytta baştaki ve sondaki sıfırlarla $00011001.110$).
- Nokta en soldaki 1'in hemen sağına gelene kadar 4 basamak sola kaydırılır: $1.100111 \times 2^4$. Nokta 4 kez sola kaydırıldığı için $2^4$ ile çarpılmalıdır.

Hoca bu gösterimin adının buradan geldiğini söyledi: nokta "yüzer" (floating). <!-- BELİRSİZ: Sonucun 32 bitlik işaret-üs-mantis alanlarına yerleştirildiği slayt karede görülmedi. -->

> **Ek bilgi (derste anlatılmadı):** Tek duyarlıklı IEEE-754'te 1 işaret biti, 8 bit üs (127 eklenerek saklanır) ve 23 bit mantis (baştaki 1 saklanmaz) bulunur. Bu örnekte işaret 0, üs $4 + 127 = 131 = 10000011_2$, mantis $1001110\dots0$ olur; 32 bitlik karşılık onaltılık $41CE0000$'dır (python ile doğrulandı).

Bu biçim de veriyi göstermeye yetmezse çift duyarlıklı (double precision) kayan noktalı biçim kullanılır.

## 9. Sayısal Olmayan Verinin Gösterimi

Slayttaki ilkeler şöyledir (ekrandan, 01:25:00):

- Gösterim esnekliği: aşağıdaki kısıtlar içinde, veri benzersiz kodlandığı sürece herhangi bir ikili birleşim (kod sözcüğü) herhangi bir veriye atanabilir.
- Bilgi türleri:
  - Sayısal (numeric): gereken veri aralığını göstermelidir; yaygın aritmetik işlemlerin basit ve doğrudan yapılabileceği biçimde gösterilmesi çok istenir; ikili sayılarla sıkı ilişkisi vardır.
  - Sayısal olmayan (non-numeric): aritmetik işlem uygulanmadığı için daha büyük esneklik vardır.

Örnek olarak renk ele alındı. Bir görüntü piksellerden oluşan bir matristir. Yalnız siyah-beyaz varsa her piksel 1 bitle gösterilebilir (örneğin 0 siyah, 1 beyaz). 256 renk gösterilecekse her piksel için 8 bit gerekir ($2^8 = 256$).

Eşlik (parity) kodlamasında veri, içindeki 1'lerin sayısı çift ya da tek olacak biçimde düzenlenir. <!-- BELİRSİZ: Eşlik örneği karede görülmedi. -->

ASCII karakter kodları klavyedeki karakterleri kodlamayı sağlar; bunlar sayısal gösterim değil, kodlamadır. Unicode ise çok daha fazla farklı karakteri kodlamayı sağlar. "ASCII'nin bazı ilginç özellikleri" başlıklı bir slayt da gösterildi. <!-- BELİRSİZ: ASCII özellikleri slaytının maddeleri karede boş göründü, altyazıda da okunamıyor. -->

Bütün bu ikili gösterimler ve işlemler mantık devreleriyle gerçekleştirilir; temel işlemler Boole cebirindeki mantık işlemleridir. Hoca bunları öğrencilerin büyük olasılıkla zaten bildiğini, ama hatırlatmanın her zaman iyi olduğunu söyledi.

## 10. Biyomedikal Verinin Doğası ve Metaveri

Aradan sonra biyoenformatikteki verinin biyomedikal veri olarak düşünülebileceği söylendi ve bu verinin bazı yönleri ele alındı. Bu bölümün amacı moleküler biyolojinin temellerini anlamaktır.

### 10.1 Biyolojik Nesnelerin Özellikleri

Tipik biyoloji ve tıp kitaplarında fotoğraflar, diyagramlar, çizimler, kimyasal formüller ve hücreler, organlar, dokular, sıvılar, kimyasal bileşikler gibi biyolojik varlıkların nitelikleri ile bunlar arasındaki ilişkiler hakkında çok sayıda betimleme bulunur. Hoca bunların her birinin farklı bir veri türüne karşılık geldiğini söyledi.

Biyolojik nesnelerin özellikleri iki türlüdür (ekrandan, 02:00:00):

- Sayısal (nicelikler): kandaki belirli kimyasalların yoğunluğu, bir tümörün boyutu, bir hücrede ya da dokuda pH, vücut ağırlığı.
- Yalnız adlandırılabilen ama ölçülemeyen nitelikler: bir proteinin hangi genin transkripsiyonuyla üretildiği, bir organizmada bir organın var olup olmadığı, bir organın parçaları ya da durumu.

### 10.2 Metaveri

Metaveri, başka bir veriyi betimleyen ve onun hakkında bilgi veren veri kümesidir. Derste sayılan türler şunlardır:

- Betimleyici (descriptive) metaveri: bir kaynağı bulmak ya da anlamak için.
- Yönetimsel (administrative) metaveri: dosyaların çözülmesi ve görüntülenmesi için teknik bilgi.
- Koruma (preservation) metaverisi: dosyaların uzun süreli yönetimi için.
- Haklar (rights) metaverisi: içeriğe bağlı fikri mülkiyet hakları.
- Yapısal (structural) metaveri: bir nesnenin parçalarının birbiriyle ilişkisi.
- İşaretleme dilleri de metaveri sayılır; metaveriyi ve yapı ya da anlam işaretlerini içeriğin içine yerleştirir.

Metaveri, verinin bir ya da daha fazla yönü hakkında bilgi sağlayan veridir; veri hakkındaki temel bilgileri özetler ve belirli verilerle çalışmayı kolaylaştırır. Örnekler: verinin oluşturulma yolu, amacı, oluşturulma tarihi ve saati, oluşturanı ya da yazarı, verinin oluşturulduğu bilgisayar ağındaki konum, kullanılan standartlar, dosya boyutu.

## 11. Hücreler: Prokaryotlar ve Ökaryotlar

Hoca uzman olmadıklarını, ama biyoenformatikteki ana veri türü moleküler biyoloji çalışmalarından geldiği için bu kavramlarla tanışmak gerektiğini söyledi. Moleküler biyoloji, biyolojiyi moleküler düzeyde inceler. Hücre, kromozom, DNA, RNA, amino asit, protein, genom, transkriptom ve proteom kavramlarının hatırlanması gerekir. Derste hücre yapısını gösteren bir video da izletildi. <!-- BELİRSİZ: Video içeriği altyazıdan anlaşılamıyor. -->

### 11.1 Hücre

Hücreler karmaşık sistemlerdir. Bütün canlı organizmaların yapısal ve işlevsel birimine hücre denir. Canlı olarak sınıflandırılan bir organizmanın en küçük birimidir ve çoğu zaman yaşamın yapı taşı diye anılır. Tipik bir hücrenin boyutu yaklaşık 10 mikrometre (10 mikron), tipik kütlesi yaklaşık 1 nanogramdır; bunlar ortalama değerlerdir.

Hücreyle ilgili bazı veriler sayısaldır; hoca örnek olarak kandaki kırmızı ve beyaz hücrelerin sayımını (kan sayımı) verdi.

### 11.2 Prokaryotik Hücreler

Slayttaki bilgiler şöyledir (ekrandan, 02:10:00):

- Prokaryotlarda çekirdek zarfı ve hücre çekirdeği yoktur.
- Prokaryotlarda ökaryotik hücrelerde görülen hücre içi organellerin ve yapıların çoğu da yoktur.
- İki tür prokaryot vardır: bakteriler ve arkeler; hücrelerinin genel yapısı birbirine benzer.
- Mitokondri, kloroplast ve Golgi aygıtı gibi organellerin işlevlerinin çoğunu prokaryotik hücrenin plazma zarı üstlenir.
- Prokaryotik hücrelerin üç mimari bölgesi vardır; ilki flagella ve pili denen, hücre yüzeyine bağlı proteinlerden oluşan uzantılardır.

Slayttaki bakteri şemasında kapsül, hücre duvarı, plazma zarı, sitoplazma, ribozomlar, plazmit, pili, bakteri flagellumu ve nükleoid (dairesel DNA) etiketlenmiştir. Hoca, her tek hücreli organizmanın prokaryot olmadığını da belirtti.

> **Ek bilgi (derste anlatılmadı):** Prokaryotik hücrenin diğer iki mimari bölgesi büyük olasılıkla kapsül, hücre duvarı ve plazma zarından oluşan hücre zarfı ile DNA'nın ve ribozomların bulunduğu sitoplazmik bölge olarak verilir.

### 11.3 Ökaryotik Hücreler

Ökaryotik DNA, kromozom denen bir ya da daha fazla DNA molekülü halinde düzenlenir; bu moleküller histon proteinleriyle ilişkilidir. Kromozomlardaki DNA hücre çekirdeğinde saklanır ve sitoplazmadan ayrılır. Ökaryotik hücrelerde mitokondri gibi DNA içeren organeller de bulunur.

## 12. Kromozomlar ve DNA

### 12.1 Kromozomlar

Kromozomlar, hücrelerde bulunan, DNA ve proteinlerden oluşan düzenli yapılardır. Kromozom kelimesi "chroma" (renk) ve "soma" (beden) sözcüklerinden gelir; boyalarla çok güçlü boyanma özelliklerinden dolayı bu adı almıştır. Kromozomlar DNA'yı paketlemeye ve işlevlerini kontrol etmeye yarayan DNA'ya bağlı proteinler içerir. Kromozomlar farklı organizmalar arasında çok değişkendir. Bir DNA molekülü dairesel ya da doğrusal olabilir ve on kilobaz çiftinden yüzlerce megabaz çiftine kadar uzunlukta olabilir. Tipik olarak ökaryotik hücrelerde büyük doğrusal kromozomlar, prokaryotik hücrelerde daha küçük dairesel kromozomlar bulunur. Kromozomlar eşlenmiş ya da eşlenmemiş olabilir; eşlenmemiş olanlar tek zincirdir, eşlenmiş olanlar bir merkezle birleşmiş iki kopya içerir.

Slayttaki bilgiler şöyledir (ekrandan, 02:15:00):

- Ökaryotlarda çekirdek, kromozomlar halinde düzenlenmiş bir ya da birkaç çift zincirli DNA molekülü içerir.
- İnsanda 22 çift otozom ve 1 çift cinsiyet kromozomu vardır.
- Slaytta insan karyotipi (5 mikrometre ölçekli) gösterildi; karyotip, bir ökaryot türünün karakteristik kromozom takımıdır. Kromozomlar 1'den 22'ye kadar ve X, Y olarak numaralanmıştır.

Ardından bazı hayvanlardaki kromozom sayıları gösterildi; en az 8 kromozomlu bir türden başlayıp yaklaşık 100 kromozomlu japon balığına kadar uzanan değerler anıldı. <!-- BELİRSİZ: Kromozom sayıları tablosu karede görülmedi; tür adları ve sayılar altyazıda bozuk. -->

### 12.2 DNA

DNA, deoksiribonükleik asidin kısaltmasıdır. Canlıların gelişimi ve işleyişi için gereken genetik talimatları içeren bir nükleik asittir. DNA moleküllerinin ana görevi bilginin uzun süreli saklanmasıdır.

> **Hocanın vurgusu:** Burada bilgi saklama ve bilgi kavramına geri dönüyoruz. Dersin başında enformatik ve bilgi sistemlerinin temellerini konuşurken veriyi işlemenin amacının bilgi çıkarmak olduğunu söylemiştik. DNA da bilgi taşır.

DNA çoğu zaman bir tarife ya da bir koda benzetilir, çünkü hücrenin protein ve RNA molekülleri gibi diğer bileşenlerini kurmak için gereken talimatları içerir. Genetik bilgi taşıyan DNA parçalarına gen denir. Diğer DNA dizilerinin yapısal amaçları vardır ya da genetik bilginin kullanımını düzenlemeye katılırlar.

Kimyasal olarak DNA, nükleotit denen basit birimlerden oluşan uzun bir polimerdir; omurgası ester bağlarıyla birleşmiş şekerler ve fosfat gruplarından oluşur. Genetik kodla bu bilgi proteinlerdeki amino asit dizisini belirler. Kod, DNA parçalarının ilgili nükleik asit olan RNA'ya kopyalanmasıyla okunur; bu sürece transkripsiyon denir.

DNA hücrede kromozom denen yapılarda düzenlenir ve kromozomlar hücre bölünmesinden önce DNA replikasyonu süreciyle kopyalanır. Ökaryotik organizmalar DNA'yı hücre çekirdeğinde, prokaryotlar ise sitoplazmada tutar. Kromozomlarda histon gibi kromatin proteinleri DNA'yı sıkıştırır ve düzenler; bu sıkışık yapılar DNA ile diğer proteinler arasındaki etkileşimleri yönlendirir ve DNA'nın hangi kısımlarının transkripsiyona uğrayacağını kontrol etmeye yardım eder.

### 12.3 Nükleotitler

DNA'nın dört bazı adenin (A), sitozin (C), guanin (G) ve timindir (T). Nükleotitler, azotlu bir baz, bir şeker ve bir fosfat grubundan oluşan organik bileşiklerdir; RNA ve DNA'nın yapı birimleridir. Azotlu bazlar iki gruba ayrılır. Slaytta bazların kimyasal yapıları da gösterildi.

> **Ek bilgi (derste anlatılmadı):** Azotlu bazların iki grubu pürinler (A ve G, çift halkalı) ve pirimidinlerdir (C, T ve RNA'daki U, tek halkalı).

### 12.4 DNA Dizisinin Gösterimi

Slayttaki bilgiler şöyledir (ekrandan, 02:30:00):

- Çoğu veri kaynağında bir DNA molekülünün ya da dizisinin tipik gösterimi, çift sarmal DNA zincirinde bulunabilecek dört nükleotidi (baz) temsil eden G, C, A ve T harflerinden oluşan bir dizidir.
- DNA molekülü çift zincirli olsa da bazlar benzersiz biçimde eşleşir: A ile T, G ile C. Bu yüzden yalnız bir zincirin bazlarını göstermek yeterlidir.

Slayttaki örnek dizi, meme kanseriyle ilişkili BRCA geni ("BReast CAncer gene") çevresindeki bölgeden küçük bir parçadır:

```text
CACTGGCATGATCAGGACTCACTGCAGCCTTGACTCCCAGGCTCAGTAGATCCTCCTACCTCAGCCTCTC
GAGTAACTGGGACCACAGGCGAGCATCACCATGCTCAGCTAGTTTTTGTATTTGTAGAGATGAGGTTTCA
CCATATTGCCCAGGCTGGTCTTGAACTCCTGGGCTCAAGCAAGCCACCCACCTTGGCCACCCAAAGTGCT
```

Hoca bu noktada bir problem ortaya koymak istediğini söyledi: elimizde böyle bir karakter dizisi var. <!-- BELİRSİZ: Problemin devamı altyazıda okunamıyor. -->

## 13. Genetik Kod

Genetik kod, genetik malzemede (DNA ya da mRNA dizileri) kodlanmış bilginin canlı hücreler tarafından proteinlere çevrilme kurallarıdır (ekrandan, 02:25:00). Translasyonu ribozom gerçekleştirir: ribozom, haberci RNA'nın (mRNA) belirlediği sırada amino asitleri birbirine bağlar; amino asitleri taşımak ve mRNA'yı üçer nükleotit okumak için transfer RNA (tRNA) moleküllerini kullanır. Genetik kod bütün organizmalarda çok benzerdir.

Slayttaki bilgiler şöyledir (ekrandan, 02:35:00):

- 4 olası baz vardır: A, C, G, U.
- Üç nükleotidin her birleşimine kodon denir.
- $4^3 = 4 \times 4 \times 4 = 64$ olası kodon dizisi vardır.
- Her kodon bir amino aside karşılık gelmez:
  - Başlangıç kodonu: AUG.
  - Durdurma kodonları: UAA, UAG, UGA.
- 61 kodon amino asit kodlar (AUG de dahil).
  - Yalnız 20 amino asit vardır; genetik kodda fazlalık (redundancy) bulunur.
  - Amino asitlerin çoğu için aynı amino asidi gösteren birkaç kodon vardır. Örneğin lizin iki kodonla (AAA ve AAG), lösin ise altı kodondan herhangi biriyle gösterilir.

Hesap: $64 - 3 = 61$ kodon amino asit kodlar (python ile doğrulandı).

Hoca bunu bilgisayar organizasyonundaki bir benzetmeyle açıkladı: AUG bir diziyi başlatır, durdurma kodonlarından biri dizinin sonunu işaret eder. Slaytta 20 amino asidin kodonlarla eşleştiği tablo da gösterildi. <!-- BELİRSİZ: Kodon-amino asit tablosu karede görülmedi. -->

## 14. Amino Asitler ve Proteinler

### 14.1 Amino Asitler

Amino asitler proteinlerin temel yapı birimleridir. Bazı amino asitler suda çözünür, yani suyu sever (hidrofilik); bazıları suda çözünmez, sudan kaçar (hidrofobik). Bu, amino asitlerin suyla ilişkisi açısından iki gruptur.

Amino asitler peptit denen kısa polimer zincirleri ya da polipeptit veya protein denen daha uzun zincirler oluşturur. Bu oluşum bir RNA kalıbından gerçekleşir ve protein biyosentezinin bir parçası olan translasyon diye bilinir. Standart genetik kodla kodlanan 20 amino aside proteinojenik ya da standart amino asitler denir. Proteinlerde bulunan diğer amino asitler genellikle translasyon sonrası değişikliklerle, yani protein sentezinde translasyondan sonra yapılan değişikliklerle oluşur.

### 14.2 Proteinler

Proteinler hücrelerde ve dokularda birçok farklı rol üstlenir:

- Enzim olarak glikoz metabolizması gibi biyokimyasal tepkimeleri kolaylaştırırlar.
- Sinyal görevi görerek başka süreçleri düzenlerler.
- Hücre ve doku yapısının bileşenidirler.

Proteinler, komşu amino asit kalıntılarının karboksil ve amino grupları arasındaki peptit bağlarıyla bir arada tutulan, doğrusal bir zincir halinde dizilmiş amino asitlerden oluşan büyük organik bileşiklerdir. Organizmaların temel parçalarıdır ve hücredeki hemen her sürece katılırlar. Birçok protein biyokimyasal tepkimeleri hızlandıran ve metabolizma için hayati olan enzimlerdir. Hayvanlar besinlerdeki proteinleri metabolizmada kullanılacak amino asitlere parçalar.

Bir protein hakkında tutulan bilgilere onu kodlayan gen ve mutasyonlarıyla bağlantılı olabilecek hastalıklar da girer.

## 15. Örnek Vaka: HIV Proteazı

HIV virüsünün bir hücreyi nasıl enfekte ettiği temsili bir şekille anlatıldı. Slayttaki adımlar şöyledir (ekrandan, 02:45:00):

1. Maruz kalma ve enfeksiyon.
2. HIV hücreye girer.
3. Kendi hücreniz HIV'in "kodunu" okur ve HIV proteinlerini üretir.

Altyazıya göre virüs kendini hücredeki belirli bir noktaya bağlayarak hücreye girer; hücre virüsün kodunu okuyup virüs proteinini üretir. <!-- BELİRSİZ: Slayttaki 4. ve 5. adımların metni karede görülmedi. -->

Bu süreci önlemek için virüsün hücreye bağlanması engellenmelidir. Birçok ilaç, virüsün bağlanması gereken noktaya önceden bağlanır; bağlanma noktası dolu olduğu için virüs hücreye giremez. Bu durumda yanıtlanması gereken soru şudur: bu proteine hangi tür molekül bağlanır? Bu soru biyoenformatik yöntemlerle araştırılabilir. Ardından toksikoloji gelir: ilacın virüse karşı korurken hastaya da zarar vermediğinin incelenmesi gerekir.

## 16. RNA ve mRNA İşlenmesi

Hoca daha önce genomik, proteomik, yapısal biyoenformatik ve fonksiyonel genomik kavramlarına değindiği için bu tanımları atladı ve RNA'ya geçti. Bugün birçok çalışmanın RNA etrafında yoğunlaştığını belirtti.

### 16.1 RNA

RNA, ribonükleik asidin kısaltmasıdır; nükleotit birimlerinden oluşan uzun bir zincirdir. Her nükleotit azotlu bir baz, bir riboz şekeri ve bir fosfattan oluşur. RNA DNA'ya çok benzer, ama bazı önemli yapısal farkları vardır:

- Hücrede RNA genellikle tek zincirlidir, DNA ise çift zincirlidir.
- RNA nükleotitleri riboz içerir, DNA nükleotitleri ise deoksiriboz içerir (bir oksijen atomu eksik olan riboz türü).
- RNA'da DNA'daki timin yerine urasil bazı bulunur.

RNA, RNA polimeraz denen enzimlerle DNA'dan yazılır (transkripsiyon) ve genellikle başka enzimlerle işlenir. RNA protein sentezinin merkezindedir; protein üretim sürecindeki ara yapıdır. Haberci RNA (mRNA) genetik bilgiyi ribozomlara taşır. Ribozomlar proteinlerden ve ribozomal RNA'lardan oluşur; bunlar bir araya gelerek mRNA'yı okuyup bilgiyi proteinlere çeviren bir moleküler makine oluşturur. Başka rolleri olan RNA'lar da vardır.

Hoca protein sentezinin, daha önce yapılan makine benzetmesindeki bilgi akışı süreci gibi düşünülebileceğini hatırlattı: genetik bilgiyi taşıyan DNA molekülünden mRNA üretilir.

### 16.2 mRNA İşlenmesi

mRNA işlenmesi, bilgi taşımayan, yani kodlamayan bölgeler olan intronları çıkarır ve eksonları birleştirir. Birleştirme (splicing) bir araya getirmek demektir: kodlayan bölgeler olan eksonlar alınır ve birleştirilir. İşlenmiş mRNA proteine çevrilebilir.

Slaytta mRNA işlenmesinin şematik bir gösterimi verildi: eksonlar bir renkle, intronlar başka bir renkle gösterilmişti; transkripsiyon ve mRNA işlenmesi sırasında intronlar kesilip çıkarılır ve eksonlar birleştirilerek haberci RNA oluşturulur. <!-- BELİRSİZ: Şema karede görülmedi; renkler ve adımlar altyazıdan kırık biçimde çıkarıldı. -->

> **Hocanın vurgusu:** Bu biyoloji konuları biraz yorucu gelebilir, ama anlaşılmaları gerekir, çünkü ders gen ifadesi konuları etrafında dönüyor. Hesaplama kısmı daha kolay gelecektir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:26:35): Biyoenformatik için Linux işletim sistemini kullanmayı öğrenmeli miyiz? Python, Perl ya da R öğrenmeli miyiz?

> **Cevap (derste verildi):** Evet, ikisi de öğrenilmelidir. Bu derste çoğunlukla Perl kullanılacaktır.

**Soru 2** (derste sözlü, 01:12:53; ekrandan, 01:15:00): İkiye tümleyen gösteriminde en anlamlı bitin 1 olması "eksi işareti" anlamına mı gelir? 5 bitlik $11101$ sayısının değeri nedir?

> **Cevap (derste verildi):** Bu bit eksi işareti diye düşünülürse cevap yanlış olur. Ağırlıklı sayı sistemi kullanılır; en anlamlı bitin ağırlığı $-16$'dır. $11101 = 1 \cdot (-16) + 1 \cdot 8 + 1 \cdot 4 + 0 \cdot 2 + 1 \cdot 1 = -16 + 13 = -3$.

**Soru 3** (ekrandan, 01:20:00): 25.75 sayısının kayan noktalı gösterimini bulun.

> **Cevap (derste verildi):** $25.75 \Rightarrow 00011001.110 \Rightarrow 1.1001110 \times 2^4$. Tam kısım $25 = 11001_2$, kesir kısmı $0.75 = 0.11_2$; nokta 4 basamak sola kaydırılır.

**Soru 4** (derste sözlü, 02:46:58): HIV'in hücreyi enfekte etme süreci nasıl önlenebilir?

> **Cevap (derste verildi):** Virüsün hücreye bağlanması engellenmelidir. Virüsün bağlanacağı noktaya önceden bağlanan ilaç molekülleri virüsün hücreye girmesini önler. Hangi molekülün bu proteine bağlanacağı biyoenformatikle araştırılır, sonra toksikoloji çalışmaları yapılır.

## Dersin Toparlaması

Bu derste önce hesaplamalı biyolojinin alt alanları (genomik, proteomik, yapısal biyoenformatik, fonksiyonel genomik) tanıtıldı ve biyoenformatiğin ilaç geliştirme döngüsünü kısaltma ve kişiselleştirilmiş tıp gibi uygulamalardaki rolü anlatıldı. Biyoenformatikte Linux ve Perl gibi araçların, belgelenmiş ve tekrarlanabilir araştırmanın önemi vurgulandı. Ardından bilgi sistemlerinin temelleri hatırlatıldı: veri ve bilgi farkı, dijital sistem, sürekli bilginin örneklenip nicemlenmesi, konumsal sayı sistemleri, işaretsiz ve ikiye tümleyen tamsayılar, IEEE-754 kayan noktalı sayılar ve sayısal olmayan verinin kodlanması.

Aradan sonra biyomedikal verinin doğası ve metaveri türleri anlatıldı, moleküler biyolojinin temellerine geçildi: hücreler, prokaryotlar ve ökaryotlar, kromozomlar, DNA ve nükleotitler, DNA dizisinin harf dizisi olarak gösterimi, genetik kod ve kodonlar, amino asitler ve proteinler, HIV proteazı örneği, RNA ve mRNA işlenmesi. Hoca, dersin gen ifadesi konuları etrafında döndüğünü ve hesaplama kısmına bu biyolojik temelin üzerine geçileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
