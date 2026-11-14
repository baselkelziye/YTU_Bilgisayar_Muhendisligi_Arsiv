# Ders 7 Genişletilmiş Notu: Bipolar Kodlama, PCM, Sayısal-Örneksel Modülasyon ve QAM

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tekrar: Manchester ve Diferansiyel Manchester
- 2. Bipolar Kodlama ve AMI
- 3. B8ZS: Sekiz Sıfırı Bozmak
- 4. HDB3: Dört Sıfırı Bozmak
- 5. Dört Kodlama Türü ve Bizim İçin Önemi
- 6. Örneksel İşaretin Temel Özelliği
- 7. Örneksel-Sayısal Kodlama: PAM
- 8. PCM: Örnekleri Sayıya Çevirmek
- 9. Örnekleme Teoremi (Nyquist)
- 10. Sayısal-Örneksel Kodlama: Dial-Up ve DSL
- 11. Taşıyıcı İşaret, Modülasyon ve Bağlantı Kapasitesi
- 12. Bit Hızı ve Baud Hızı
- 13. ASK: Genlik Kaydırmalı Kipleme
- 14. FSK: Frekans Kaydırmalı Kipleme
- 15. PSK: Faz Kaydırmalı Kipleme
- 16. QAM: Genlik ve Fazı Birlikte Kullanmak
- 17. Örneksel-Örneksel Kodlama: AM, FM, PM

## 1. Tekrar: Manchester ve Diferansiyel Manchester

Hoca derse, geçen hafta unipolar kodlamayı bitirip en son diferansiyel Manchester'da kaldıklarını hatırlatarak başladı. Bugün de kodlamaları konuşmaya devam edeceklerdi, bu yüzden ilk slayt bir hatırlatma oldu.

Manchester kodlamasında (Manchester coding) her bit, bit süresinin ortasındaki bir geçişle ifade edilir:

- **1:** negatiften pozitife geçiş. Sinyal eksi değerden başlar, artı değere çıkar.
- **0:** pozitiften negatife geçiş. Sinyal artı değerden başlar, eksi değere iner.

Slayttaki örnekte arka arkaya iki 1 geldiğinde her ikisinde de yine eksiden artıya bir geçiş görülüyordu. Yani aynı bit, her seferinde aynı biçimde kodlanır.

Diferansiyel Manchester'da (differential Manchester) ise mantık değişimi ifade etmeye dayanır. Değişimi 0 ile, sürekliliği 1 ile ifade ederiz. Hocanın slayttaki örneğinde dizi doğrudan 1 ile başladığı için ilk bit Manchester'daki gibi negatiften pozitife çıkıyordu. Ardından gelen 0 sürekliliği bozuyordu. Sinyal eksiden artıya çıkmıştı. Devam etseydi artıdan eksiye inmesini beklerdik. Bunun yerine süreklilik bozulup sinyal tekrar negatiften pozitife doğru çıktı.

1'ler ise sürekliliği korumak üzere kurulmuştur. Hoca bunu şöyle gösterdi: Arka arkaya gelen 1'lerin her biri neredeyse farklı görünür. İlk 1 eksiden artıya, ikinci 1 artıdan eksiye, üçüncü 1 yine eksiden artıyadır. Sinyal kesilmez, devamlılığı sağlanır. Manchester ile diferansiyel Manchester arasındaki fark budur.

## 2. Bipolar Kodlama ve AMI

Manchester dışında bir de bipolar kodlama (bipolar encoding) vardır. Polariteden hatırlarsınız, unipolar kodlama vardı. Bipolar adından da anlaşılacağı gibi iki polaritenin de kullanıldığı kodlamadır. Fakat burada üç ayrı gerilim seviyesi vardır: artı, eksi ve sıfır. Hoca bunun geçen haftaki RZ (Return to Zero) kodlamasına benzer bir görüntü verdiğini söyledi.

Bipolar kodlamaların iki örneği AMI (Alternate Mark Inversion) ve B8ZS'dir (Bipolar with 8-Zero Substitution). İkisinde de temel fikir aşağı yukarı aynıdır:

- 1'ler dönüşümlü olarak artı ve eksi polariteyle ifade edilir.
- 0, sıfır volt seviyesiyle ifade edilir.

AMI'de adı üstünde "alternate" yani dönüşümlü olarak işaret her 1'de ters çevrilir. Slayttaki örnekte dizi pozitif polariteyle başlıyordu. Bir 0 geldiğinde sıfır gerilim seviyesi kullanılıyordu. Bir daha 1 geldiğinde işaret ters çevrilip artıdan eksiye geçiliyordu. Bir sonraki 1'de tekrar artıya dönülüyordu. Araya giren 0'ların bir önemi yoktur. Çünkü sıfır volt seviyesi polaritenin ifadesinde kullanılmaz, yalnızca 0 bitini ifade etmek için kullanılır. Polarite yalnızca 1'lerin ifadesinde, dönüşümlü olarak değişecek biçimde kullanılır.

### 2.1 DC Bileşenden Kurtulmak

Hoca "Bu sayede ne sağlıyoruz? Uzun vadede baktığınızda ortalamada ne olacak?" diye sordu. 1'ler hem pozitif hem negatif tarafta gösterildiği için hat üzerinde uzun vadede ortalama gerilim değeri sıfır olur. Yani DC bileşenden kurtuluruz.

> **Hocanın vurgusu:** Bipolar kodlamanın kazancı, 1'lerin dönüşümlü polaritesi sayesinde ortalama gerilimin sıfır olması, yani DC bileşenin ortadan kalkmasıdır.

### 2.2 AMI'nin Sorunu: Uzun Sıfır Dizileri

AMI'de hâlâ bir problem vardır. Slayttaki örnek veride sıfır sayısı azdı, art arda gelen sıfır sayısı da azdı. Fakat sıfırlar artarsa sinyal üzerindeki değişim azalır. Hat uzun süre sıfır voltta kalır. Dolayısıyla karşı tarafın bizi anlaması, yani sinyali anlamlandırması pek mümkün olmaz. Hoca bunu uyumluluk (senkron) problemi olarak andı.

> **Ek bilgi (derste anlatılmadı):** Alıcı, bit sınırlarını yakalamak için büyük olasılıkla saatini gelen işaretteki seviye geçişlerine göre ayarlar. Uzun süre hiç geçiş olmazsa alıcının saati göndericininkinden kayar ve kaç tane 0 geldiğini doğru sayamaz. B8ZS ve HDB3'teki bilerek yapılan ihlaller, sıfır dizilerinin içine yapay geçişler koyarak bu senkronu korur.

## 3. B8ZS: Sekiz Sıfırı Bozmak

Uzun sıfır dizisi sorununa karşı bipolar kodlamalarda B8ZS (Bipolar with 8-Zero Substitution) yöntemi vardır. Mantığı şudur: Peş peşe gelen sıfırların senkron noktasında problem çıkarmasını engellemek için oluşturacağımız sinyali bilerek bozarız. Yani o noktaya belli bir deseni (pattern) gömeriz.

Kural, 8 sıfırdan önceki son darbenin polaritesine göre belirlenir:

- **Önceki işaret pozitifse:** İlk 3 sıfır aynen tutulur. Sonra bir polarite değişimi yapılır: artı, eksi. Sonraki sıfır tutulur. Sonra tekrar eksi, artı yapılır. Desen: $0\,0\,0\,+\,-\,0\,-\,+$.
- **Önceki işaret negatifse:** Aynı desenin tam tersi, yani ters çevrilmiş (invert edilmiş) hali kullanılır: $0\,0\,0\,-\,+\,0\,+\,-$.

Hoca iki desenin simetrisine dikkat çekti. Biri artıyla başlıyor, diğeri eksiyle başlıyor. İlk üçlü bloğu kapattığınız yer, önceki darbe artıysa artıyla, eksiyse eksiyle bitiyor. Sonrasında sinyali terse çevirip bir sıfır bırakıyorsunuz, sonra tekrar terse çevirip bitiriyorsunuz.

Böyle kodladığınızda otomatik olarak oluşabilecek bir kombinasyonu ortadan kaldırmış olursunuz. Yani normal AMI kurallarıyla asla oluşamayacak bir desen elde edersiniz. Slaytta, 8 tane sıfır geldiğinde elde edilecek örnek bir çıkış gösterildi.

Desenler python ile kontrol edildi. AMI kuralına göre her 1 bir önceki darbenin tersidir. Önceki darbe $+$ iken desendeki dördüncü konumda yine $+$ gelir. Bu, AMI'de olamayacak bir ihlaldir (bipolar violation). Yedinci konumdaki $-$ de bir önceki $-$ ile aynı polaritededir, ikinci ihlal budur. Alıcı bu iki ihlali birlikte görünce deseni tanır ve yerine 8 tane 0 koyar (ara adım eklendi).

## 4. HDB3: Dört Sıfırı Bozmak

Bir diğer alternatif HDB3'tür (High Density Bipolar 3). Hocaya göre bu ayrım tamamen bölgesel uygulamadan kaynaklanır. B8ZS Kuzey Amerika'da kullanılır. Benzer bir yapı Avrupa ve Japonya'da farklı biçimde uygulanmıştır, bu da HDB3'tür.

HDB3'te hedef 8 değil, 4 tane sıfırın art arda gelmesidir. 4 sıfır art arda geldiğinde yine yapay olarak bozulur:

- 4 sıfırın öncesinde pozitif bir polarite varsa, 4 sıfırın sonuncusuna pozitif polarite eklenir.
- Öncesinde negatif bir polarite varsa, sonuncu sıfır negatif polariteyle bozulur.

Bunu yaparken bir de son değiştirmeden (substitution) bu yana aktarılan 1'lerin sayısına bakılır. İki durum vardır:

- **1'lerin sayısı tekse** (örneğin 1 ya da 3 tane): Yukarıdaki dönüşüm kullanılır. Desen $0\,0\,0\,V$ olur. $V$, önceki darbeyle aynı polaritede bir ihlal darbesidir.
- **1'lerin sayısı çiftse** (örneğin 2, 4, 6 tane): Başka bir yapay bozma kullanılır. Desen $B\,0\,0\,V$ olur. İlk sıfırın yerine kurala uygun bir darbe ($B$) konur, sonuncuya da ona eşit polaritede ihlal darbesi ($V$) konur.

<!-- BELİRSİZ: Çift sayıdaki 1 durumu için hoca deseni yalnızca "bu şekilde bir kodlama" diye slayttan gösterdi; B00V yapısı slayttan okunmadı, kısa not ve standart tanımla yazıldı. -->

> **Ek bilgi (derste anlatılmadı):** Tek/çift kuralının amacı büyük olasılıkla art arda gelen ihlal darbelerinin ($V$) de kendi aralarında dönüşümlü polaritede olmasını sağlamaktır. Böylece değiştirme desenleri de uzun vadede DC bileşen oluşturmaz. B8ZS'de bu sorun yoktur, çünkü desenin içinde bir artı bir eksi ihlal birlikte bulunur.

### 4.1 Slayttaki HDB3 Örneği

Hoca slaytta bir giriş dizisi için üretilen çıkışı gösterdi. Sıfırları sayarak ilerledi: "1, 2, 4, 6, 8, 9 tane 0 var." Ardından dizi "bir sıfır bir sıfır" diye devam ediyordu. Hocanın yorumu "Oldukça bozuyoruz sinyali yani" oldu.

<!-- BELİRSİZ: Slayttaki giriş dizisinin tamamı altyazıdan net çıkmıyor. "1, 1, 2, 4, 6, 8, 9 tane 0 var" ifadesinden dizinin iki 1 ile başlayıp 9 sıfırla devam ettiği, ardından 1 0 1 0 geldiği varsayıldı. Başlangıç polaritesi ve önceki 1 sayısı da varsayımdır. -->

Giriş $1\,1\,0\,0\,0\,0\,0\,0\,0\,0\,0\,1\,0\,1\,0$ kabul edilirse ve ilk 1 pozitif başlarsa kodlama şöyle kurulur (ara adım eklendi, python ile doğrulandı):

- İlk iki 1: $+\,-$. Son değiştirmeden bu yana 2 tane 1 geldi, yani çift.
- İlk 4 sıfır: çift durum, $B\,0\,0\,V$. Önceki darbe $-$ olduğu için $B=+$, $V=+$. Çıkış: $+\,0\,0\,+$. Sayaç sıfırlanır.
- Sonraki 4 sıfır: bu arada hiç 1 gelmedi, 0 tane yani çift. Yine $B\,0\,0\,V$. Önceki darbe $+$ olduğu için $B=-$, $V=-$. Çıkış: $-\,0\,0\,-$.
- Kalan tek sıfır 4'lü blok oluşturmadığı için 0 kalır.
- Sonra $1\,0\,1\,0$: $+\,0\,-\,0$.

Sonuç: $+\,-\,+\,0\,0\,+\,-\,0\,0\,-\,0\,+\,0\,-\,0$. Darbelerin toplamı sıfırdır, yani DC bileşen oluşmaz.

## 5. Dört Kodlama Türü ve Bizim İçin Önemi

Hoca sayısal-sayısal kodlama tekniklerinin burada bittiğini söyledi. Bundan sonra diğer türlere bakılacaktı: örneksel-sayısal, sayısal-örneksel ve örneksel-örneksel.

Bilgisayarda veri aktarımını konuştuğumuz için çoğunlukla bir ucun sayısal olmasını bekleriz. Bu yüzden:

- **Sayısal-sayısal:** Elimizdeki dijital bilgiyi dijital aktarım yapabildiğimiz bir ortam üzerinden göndermek için kullanılır. Bizim için önemlidir.
- **Örneksel-sayısal:** Örneksel bir verimiz varsa onu örnekleyip sayısala çeviririz.
- **Sayısal-örneksel:** Sayısal bir bilgiyi zaman zaman örneksel bir hattan yollamamız ya da örneksele çevirmemiz gerekir.
- **Örneksel-örneksel:** Bizim için o kadar önemli değildir, hızlı geçilecektir.

## 6. Örneksel İşaretin Temel Özelliği

Hoca "Örneksel sinyal dediğimizde teknik olarak nasıl bir sinyalden bahsediyoruz?" diye sordu.

**Soru:** Analog mu hocam?

**Cevap:** Hoca cevabın kesinlikle doğru olduğunu, ama eksik kaldığını söyledi. Bunu "real time operating system nedir?" sorusuna "gerçek zamanlı işletim sistemi" demeye benzetti. Yani sorunun kendisini tekrar etmek gibi. Hoca örneksel işaretin bir özelliğini istiyordu.

Sohbet yazışmasında farklı cevaplar geldi. Hoca örneksel işaretin özelliğini sorduğunda "örnekleme" cevabı vermenin biraz tuhaf olduğunu söyledi. Aradığı cevabı bir öğrenci yazdı: süreklilik. Elimizde devam eden, kesintisiz bir sinyal vardır. Bunu daha önce sinyal ve işaret türlerini konuşurken, ayrık (discrete) ve sürekli (continuous) olmayı tartışırken görmüştük.

> **Hocanın vurgusu:** Örneksel işaretin temel özelliği sürekliliktir. "Analog" doğru ama sorunun tekrarıdır.

## 7. Örneksel-Sayısal Kodlama: PAM

Derdimiz örneksel-sayısal kodlama yapmak, yani örneksel bir veriyi sayısal olarak ifade edebilmektir. Bunun için o sinyali örneklememiz (sampling) gerekir. Ölçütümüz şudur: Örnekleri mümkün olduğu kadar fazla, mümkün olduğu kadar yüksek frekansla almalıyız ki sinyaldeki değişimleri, farklılaşmaları yakalayabilelim.

PAM (Pulse Amplitude Modulation, darbe genlik kiplemesi) tam da bu iş için kullanılan tekniktir. Örneksel işaretten belli aralıklarla örnekler alınır. Örnekler ne kadar sık olursa sinyal o kadar iyi anlaşılır.

Hoca "Sinyali daha iyi anlamak bize ne kazandırır?" diye sordu. Örnekselden sayısala çevirdiğimiz bilgiyi büyük ihtimalle daha sonra tekrar örneksele çevireceğiz. Bu yüzden örnekleme frekansı ne kadar yüksek olursa geri elde edeceğimiz sonuç o kadar düzgün olur.

### 7.1 Slayttaki Örnek ve Örnek Sayısı

Slaytın sol tarafında örneksel işaret, sağ tarafında PAM ile alınan örnek değerleri vardı. Hoca örnekleri saydı:

- İlk soldaki küçük dalgada 4 örnek.
- Negatif tarafa bakan kısımda 7 örnek.
- Üst taraftaki kısımda 6 örnek.
- Sonda 2 örnek.

Toplam: $4 + 7 + 6 + 2 = 19$ örnek. Bu örneklerin hangi sayılara karşılık geldiği şu an önemli değildi. Önemli olan, bu 19 örneğe bakarak soldaki sinyali neredeyse aynen yeniden oluşturmanın mümkün olmasıydı.

Hoca karşı durumları da anlattı:

- Örnek sayısı 19 değil de 6 olsaydı, sinyali yeniden oluşturmaya kalktığınızda birden fazla ihtimal olurdu.
- Bu aralıkta topu topu iki örnek alsaydınız, biri ilk tepe noktasından, biri ikinci tepe noktasından, sinyalin aşağı dönüşünü hiç takip edemezdiniz.

Buradan örnekselden sayısala dönüştürmede iki önemli kural çıkar:

- Örnek alma arasındaki zaman aralıkları eşit olmalıdır.
- Örnek alma sıklığı, örneklenen işaretin karakterini anlamaya imkan verecek kadar yüksek olmalıdır.

Hoca ne kadar sık örnekleneceğinin Nyquist teoremiyle belirlendiğini söyledi. Örneksel işaretin özelliği sorulduğunda bir öğrencinin "ADC" (Analog-Digital Converter, analog-sayısal dönüştürücü) cevabını da bu bağlamda değerlendirdi; öğrencinin büyük ihtimalle örneklemeyi düşünerek söylediğini belirtti.

### 7.2 "En Az İki Katı" ve Sıkıştırmalı Algılama

Bir öğrenci örnekleme hızının en az iki katı olması gerektiğini yazdı. Hoca bunu doğruladı ve önemli bir şart ekledi: Bu, işi kayıpsız yapmak istiyorsanız geçerlidir. Veride bir şeyleri kaybetmek sizin için büyük problem değilse örneklemeyi daha düşük de yapabilirsiniz. Ama veri aktarımından bahsettiğimiz için derste hep en az iki katı üzerinde durulacaktır.

ADC ve örnekleme konusu açılmışken hoca sıkıştırmalı algılama (compressed sensing) kavramından bahsetti. Bu yaklaşım, belli açılardan az örnek alarak (undersampling) da bilginin geri çıkarılabileceğini söyler. Ama hangi bilginin? Hocaya göre kayıplı olması sizi zora sokmayacak olan verinin, örneğin ses bilgisinin. Merak edenlerin compressed sensing konusunu açıp bakmasını, teoride ilginç şeyler göreceklerini söyledi.

> **Ders sonrası not:** Sıkıştırmalı algılamanın temel şartı büyük olasılıkla kayıp toleransı değil, işaretin uygun bir tabanda seyrek (sparse) olmasıdır. Bu şart sağlanırsa Nyquist hızının altında alınan örneklerden işaret yüksek doğrulukla geri çıkarılabilir.

## 8. PCM: Örnekleri Sayıya Çevirmek

PAM ile elde ettiğimiz şey, yalnızca örneklediğimiz anlarda sinyale ait gerilim değerleridir. Bunları sayısal bir değere çevirmemiz gerekir. Bunu PCM (Pulse Code Modulation, darbe kod kiplemesi) yapar. Hoca slayttaki eksenin V (volt) gibi göründüğünü, ama artık tam olarak volt denemeyeceğini söyledi.

Slayttaki değerler 0 ile 255 arasında değildir. Eksi 127 ile artı 127 arasındadır. Ama yine 255'lik bir alandır, yani 8 bitlik bir örnekleme söz konusudur. 8 bitin bir biti işaret (sign), geri kalan 7 biti sayı değeridir. 7 bitle en büyük değer $2^7 - 1 = 127$ olur. İşaret biti eklenince $-127$ ile $+127$ arası $2\cdot 127 + 1 = 255$ farklı değer elde edilir (ara adım eklendi, python ile doğrulandı).

> **Ek bilgi (derste anlatılmadı):** 8 bitle $2^8 = 256$ farklı kod yazılabilir. İşaret-büyüklük gösteriminde "$+0$" ve "$-0$" ayrı kodlardır ama büyük olasılıkla aynı değeri gösterir. Bu yüzden 256 kod, 255 farklı değere karşılık gelir.

Hoca PCM'in ders slaytlarında ve başka kaynaklarda 8 bit olarak geçtiğini, ama 8 bitle sınırlı olmadığını vurguladı. Telefon haberleşmesinde 8 bit kullanılır. Yüksek kaliteli bir şey aktarmak istediğinizde 16 bit, hatta 24 bit sürümleri de vardır.

PAM ile örnekledik, örnekleri 8 bitlik sayılara çevirdik. Elde ettiğimiz şey slayttaki gibi bir dizidir: $16, 48, 50, 18, -16, \ldots$ Bundan sonrası bu dizinin üzerinde yapılacak kodlamadır. Bu kodlama, diziyi bir yere kaydetmek ya da tekrar aktarmak için yapılır.

Hoca örnek olarak sesi verdi. Bir öğrenci örneksel sinyal deyince aklına ses geldiğini yazmıştı. Ses de sürekli (continuous) bir işarettir. Bu işaret üzerinde PAM ile örnekleme, sonra PCM yapılır. Elinizde sayısal bir bilgi olur. Bu bilgi ikili sayı düzenine çevrilip aktarılır. Bunun için daha önce konuştuğumuz sayısal-sayısal kodlama tekniklerinden biri kullanılır. Hangisinin seçileceği, bilgiyi nereden, hangi ortam üzerinden, ne şekilde aktardığımıza bağlıdır.

## 9. Örnekleme Teoremi (Nyquist)

PAM ile belli aralıklarla örnekler alıp işareti genlik değerlerinden oluşan bir dizi halinde ifade ediyorduk. Alınması gereken örnek sayısı için Nyquist teoremi kullanılır. Teorem şunu söyler: İşaretin içindeki en yüksek sıklık bileşeninin, yani en yüksek frekansın en az iki katı kadar örnek alınması gerekir:

$$f_s \geq 2 f_{max}$$

Hocanın örneği sesti. Kaynaklar sesi farklı aralıklarda gösterir: bazıları 300 ile 3400 Hz arasında, bazıları 1000 ile 4000 Hz arasında. Buradaki en yüksek değer 4 kHz alınırsa:

$$f_s = 2 \times 4000 \text{ Hz} = 8000 \text{ örnek/s}$$

Yani 4 kHz'i düzgün örnekleyebilmek için saniyede 8000 örnek almanız gerekir.

> **Ders sonrası not:** Teoremin kesin ifadesi $f_s > 2 f_{max}$ biçimindedir; tam iki katında örnekleme bazı durumlarda yetmez. Telefon ses bandı büyük olasılıkla 300-3400 Hz'dir; 4 kHz, koruma payıyla alınan kanal genişliğidir. Telefon PCM'inde $8000 \times 8 = 64\,000$ bit/s, yani 64 kbps elde edilir (python ile doğrulandı). Bu, büyük olasılıkla sayısal telefon şebekesinin temel kanal hızıdır (DS0).

Örneksel-sayısal kodlamanın adımları sırasıyla şöyle toparlandı:

1. PAM ile örnekler alınır.
2. PCM ile kodlanıp bir sayı dizisi haline getirilir.
3. Dizi ikili sisteme çevrilir. Sayısal sistemde hep ikilik düzen kullanıldığı için bu normaldir.
4. İkili dizi sayısal-sayısal bir kodlamayla hatta gönderilecek bir sinyale çevrilir.

Hoca slayttaki son çizimin biraz yamuk, kötü göründüğünü de ekledi.

## 10. Sayısal-Örneksel Kodlama: Dial-Up ve DSL

Sayısal-örneksel kodlamaya geçerken hoca, en çok bilinen örneğin internetin ilk yaygınlaştığı dönemdeki bağlantı olduğunu söyledi. O dönemde internet bağlantısı telefon hattı üzerinden sağlanıyordu.

"Ben de DSL abonesiyim, benim bağlantım da telefon hattı üzerinden" diye düşünebilirsiniz. Hocaya göre tam olarak öyle değil:

- **Eski sistem (POTS, Plain Old Telephone System):** Telefon hattında sesi taşımak için ayrılmış olan frekans aralığında, elinizdeki dijital bilgi örneksel yapıya çevrilip gönderiliyordu. Bilginiz aktarılırken telefonu kaldırıp dinleseniz cızırtılı sesler duyardınız. Çünkü iş duyulabilir bir frekans aralığında yapılıyordu.
- **DSL:** Yine aynı kabloyu kullanırsınız. Yıllar geçtiği ve kablolama değiştiği için kalite daha iyi olabilir. Fakat kablonun bir ucu doğrudan analog cihaza değil, DSLAM denen bir cihaza bağlıdır. Bu sayede ses frekans aralığının dışında, çok daha yüksek frekanslarda çalışılır. Bu yüzden çok daha yüksek hızlarda haberleşilebilir.

> **Ders sonrası not:** Hoca DSLAM'ı "Digital Subscriber Line Access Modem" diye açtı. Doğrusu büyük olasılıkla Digital Subscriber Line Access Multiplexer'dır. Bu cihaz santralde birçok abone hattını bir araya getirir.

## 11. Taşıyıcı İşaret, Modülasyon ve Bağlantı Kapasitesi

Hoca örneksel işaretlerin üç temel özelliğini hatırlattı:

- **Genlik (amplitude):** Sinyalin gücü, tepe noktası olarak düşünülebilir.
- **Sıklık (frequency):** Sinyalin ne kadar sık tekrar ettiği.
- **Faz (phase):** Periyodik bir sinyalde, başlangıç konumuna göre sinyalin kaç derecede olduğu.

Sayısal bilgiyi örneksel olarak kodlarken bu üç özellikten birini değiştiririz (modüle ederiz). Buna göre üç temel yöntem ve bir de iki tekniği birleştiren hibrit dördüncü yöntem vardır:

- **ASK (Amplitude Shift Keying):** Sinyalin genliğiyle oynanır.
- **FSK (Frequency Shift Keying):** Sinyalin sıklığıyla oynanır.
- **PSK (Phase Shift Keying):** Sinyalin fazıyla oynanır.
- **QAM (Quadrature Amplitude Modulation):** Genlik ve faz ile aynı anda oynanır. Daha karmaşık bir kipleme (keying) elde edilir.

### 11.1 Taşıyıcı İşaret ve Saat Kayması

Bilgiyi aktarmak için bir sinyalin özelliklerini değiştiriyoruz. Dolayısıyla ortada değiştirilecek bir sinyal olması gerekir. Buna taşıyıcı işaret (carrier signal) denir. Normal şartlarda bu sinyalin yüksek sıklıkta bir işaret olması beklenir.

Çoğu zaman alıcı ile gönderici taşıyıcı frekansı konusunda karşılıklı olarak anlaşmalıdır (auto-negotiation). Bunu da otomatik olarak yapmaları gerekir. Hoca bu ihtiyacın sebebini şöyle açıkladı: Belli bir çalışma frekansındasınız, ama bu frekansı bir saatten (clock) elde ediyorsunuz. Bu sistemler dağıtık sistemlerdir, birbirinden bağımsızdır, saatleri de birbirinden bağımsızdır. Hedefleri örneğin 29 MHz'de ya da 800 MHz'de çalışmak olabilir. Fakat saatleri aynı anda sıfırdan bire, birden sıfıra geçmez. Aralarında kaymalar (drift) olur. Bu yüzden ana frekansın biraz altında ya da üstünde bir yerde kendi aralarında anlaşmaları gerekir.

### 11.2 Modülasyon ve Kapasite

Genlik, sıklık ve fazla ilgili yapılan değişikliklerin hepsine, hangisi olursa olsun, modülasyon (modulation, kipleme) ya da keying denir.

Taşıyıcı sinyal üzerinden yapılan haberleşmenin kapasitesi üç şeye bağlıdır:

- Hattın taşıma kapasitesi.
- Cihazların uyguladığı modülasyon tekniği.
- Taşıyıcı sinyalin sıklığı.

Düşük sıklıktaki bir sinyalle çok yüksek veri aktarmak mümkün değildir. Taşıyıcı ne kadar yüksek frekanslı olursa aktarma kapasitesi o kadar artar.

## 12. Bit Hızı ve Baud Hızı

Konuşulması gereken bir şey daha vardır: bit hızı (bit rate) ve baud hızı (baud rate).

- **Bit hızı:** Bir saniyede gönderilen bit sayısıdır, bit/s (bits per second) ile ifade edilir.
- **Baud hızı:** Bir saniyede gönderilen sinyal birimi (sembol) sayısıdır, baud/s ile ifade edilir.

Bir baud ile kaç bit ifade edebildiğinize bağlı olarak bu iki değer birbirinden farklı olur. Bir baud ile bir bit ifade ediyorsanız eşittirler. Bir baud ile iki bit ifade ediyorsanız bit hızınız daha yüksek olur. Genel ilişki:

$$\text{bit hızı} = \text{baud hızı} \times \text{(baud başına bit sayısı)}$$

> **Hocanın vurgusu:** Bit hızı her zaman baud hızına eşit ya da ondan büyüktür.

Hoca bunun ASK, PSK örnekleri üzerinden geçerken daha rahat kavranacağını söyledi.

## 13. ASK: Genlik Kaydırmalı Kipleme

ASK'de (Amplitude Shift Keying) adından da anlaşılacağı gibi genlikle oynanır. Bunu yaparken frekans ve faz bozulmaz. Slayttaki sinyalde her bit için frekansta hiçbir değişiklik yoktu, yalnızca genlik değişiyordu. Pozitif ve negatif tepe noktaları bazı aralıklarda daha açılmış, daha yukarı ya da daha aşağı inmiş durumdaydı.

Hoca "Bunlardan hangisi sıfır, hangisi bir?" diye sordu. Bir öğrencinin cevabı doğruydu: Biri 0 ise diğeri 1, biri 1 ise diğeri 0 olmalıdır. Ama hoca asıl buna kimin karar verdiğini soruyordu. Cevap: uygulayana kalmış. Genliği düşürdüğünüzde mi 0 ifade edeceksiniz, yükselttiğinizde mi? Bu, ASK'yi kullanan kişinin o sistem içinde vermesi gereken bir karardır.

> **Hocanın vurgusu:** ASK'de hangi genliğin 0, hangisinin 1 olduğu bir standart değil, uygulayanın tasarım kararıdır.

### 13.1 ASK'nin Sorunu: Gürültü

Hoca "ASK'nin problemi ne?" diye sordu. Bilgi bir ortam üzerinden aktarılır. Bu ortam hava, kablo ya da başka bir şey olabilir. Ortam dışarıdan gelebilecek elektromanyetik sinyale, gürültüye, ısıya açıktır. Böyle bir dış etki en başta genliği değiştirebilir. Genlikte istemediğimiz her değişimde gönderilen bilgi 0 yerine 1, 1 yerine 0 olarak algılanabilir.

Slayttaki ASK örneğinde her periyotta, yani her baud'da bir bit gönderiliyordu. Gösterilen aralıkta 5 baud vardı. Dolayısıyla:

$$\text{baud hızı} = 5, \quad \text{bit hızı} = 5 \times 1 = 5$$

## 14. FSK: Frekans Kaydırmalı Kipleme

FSK'de (Frequency Shift Keying) genlik ve faz sabit tutulur, sıklık bitin 0 ya da 1 olmasına göre değiştirilir. Frekansla oynadığımız için dışarıdaki elektromanyetik alanlardan doğrudan etkilenmesi daha zor bir yapıdan bahsediyoruz.

Slayttaki örnekte kalın çizgiye kadar olan kısımda 5 zaman aralığı vardı. Her birinde bir baud, her baud'da bir bit vardı. Bit 0 ya da 1 olmasına göre frekans sıklaşıyor ya da seyreliyordu. Yine:

$$\text{baud hızı} = 5, \quad \text{bit hızı} = 5$$

FSK dış etkenlerden daha az etkilenir. Bu yüzden ASK'ye göre daha dayanıklı (robust) bir yapısı vardır.

FSK'nin sıkıntılı tarafı şudur: Bir taşıyıcı işarete ihtiyacımız var. Taşıyıcının frekansı ne kadar yüksek olursa taşıma kapasitemiz de o kadar yüksek olur. FSK'de sinyalin frekansıyla oynadığımız için taşıyıcı sinyalin ne olduğu, hangi sınırlarda olduğu yöntemin etkinliği açısından önemlidir. Hoca bunu unutmamamızı istedi.

> **Ders sonrası not:** Hoca bu cümlede "PSK'nın efektifliği açısından önemli" dedi. Konu FSK olduğu için kastedilen FSK'dir.

## 15. PSK: Faz Kaydırmalı Kipleme

Üçüncü alternatif PSK'dir (Phase Shift Keying), yani fazı değiştirmek. Hoca daha önce 90 derece örneği üzerinden faz kaymasını konuştuklarını hatırlattı. Bu kez 180 derece üzerinden anlattı.

0 derecedeki sinyal orijinal sinyaldir. Bir aralıkta yukarı çıkar, aşağı iner, tekrar çıkar, tekrar iner. Bunu 180 derece çevirdiğinizde sinyal bu kez alttan başlar. Sonra tepe noktası, tekrar çıkış ve bitiş gelir. Sonraki bitte ifade değişir, sinyal tekrar sıfır dereceden başlatılır.

Burada yalnızca iki faz kullanıldı: 0° ve 180°. Ama 0°, 90°, 180°, 270° gibi faz sayısı artırılabilir. Fazın ne kadar kaydırılacağı da bize kalmıştır; 45'er derece de kaydırılabilir. Yalnız iki fazın olduğu durumda baud hızı ile bit hızı aynıdır.

### 15.1 Dört Fazlı PSK

Faz kiplemesini farklı şekilde yapabiliriz. Dört ayrı faz kullanarak kodlama yapalım: 0°, 90°, 180° ve 270°. Hocanın atadığı değerler:

| Faz | Bit çifti |
|---|---|
| 0° | 00 |
| 90° | 01 |
| 180° | 10 |
| 270° | 11 |

Slayttaki sinyalde 00, zaten 0 derecedeki sinyalin kendisiydi. 01 için sinyal 90 derece, 10 için 180 derece, 11 için 270 derece kaydırılmıştı. Her seferinde faz biraz daha ileri gidiyordu.

Bu durumda her baud'da iki bit aktarmaya başladık. Slayttaki örnekte 5 baud vardı:

$$\text{bit hızı} = 5 \times 2 = 10, \quad \text{baud hızı} = 5$$

Dört faz $\log_2 4 = 2$ bit eder (python ile doğrulandı).

## 16. QAM: Genlik ve Fazı Birlikte Kullanmak

Üç temel yöntemden ikisini karıştırma şansımız vardır: PSK ile ASK'yi, yani fazı ve genliği bir arada kullanmak. Bunu yaptığımızda bir baud'da ifade edebileceğimiz bit sayısı artar.

Hoca önce 4 fazlı PSK'yi hatırlattı. 0°, 90°, 180°, 270° kullanıyorduk ve her baud'da 2 bit ifade ediyorduk. Aynı şeyi 4 faz ve 1 genlik kullanan bir QAM'de yapsak sonuç aynı olur. Buna 4-QAM denebilir. Tek genlik ve 4 faz vardır, her faz 2 bit ifade eder. Baud ve bit açısından 4-PSK ile aynı şeyi görürüz.

Asıl fark, hem genlikte hem fazda birden fazla seviye kullanmaya başladığımızda ortaya çıkar. Örneğin faz sayısını 4, genlik sayısını 2 yaparsak. Genliği daha da artırırsak bit sayısı daha da artar.

### 16.1 8-QAM

4 faz ve 2 genlik kullanınca 8-QAM elde edilir. Slayttaki yıldız diyagramında (constellation) iki farklı genlik seviyesi olduğu için iç içe iki kare görülüyordu. Faz olarak 4 farklı faz vardı. Toplamda:

$$2 \text{ genlik} \times 4 \text{ faz} = 8 \text{ durum}, \quad \log_2 8 = 3 \text{ bit}$$

Slayttaki örnek sinyalde bir saniyelik alanda 5 baud vardı. Her baud'da 3 bit ifade edildiği için:

$$\text{bit hızı} = 5 \times 3 = 15$$

Hesap python ile doğrulandı.

### 16.2 Gerçekte Kullanılan ve 16-QAM

Hoca, gerçek veri aktarımında kullanılan sistemlerin buna yakın olduğunu söyledi. Doğrudan ASK, FSK kullanılmaz, çoğu zaman QAM kullanılır.

> **Hocanın vurgusu:** Gerçek veri iletiminde çoğunlukla QAM kullanılır, saf ASK ya da FSK pek kullanılmaz.

QAM'de baud hızı ile bit hızı arasındaki ilişki QAM'in yapısına bağlıdır ve slaytta tablo halinde verilmişti. Örneğin 16-QAM kullandığınızda 16 değer oluşturabilmek için 4 bite ihtiyacınız vardır ($\log_2 16 = 4$). Her baud'da 4 bit aktarırsınız. Baud hızınız ne ise bit hızınız onun 4 katıdır. Genel kural: $M$ durumlu bir QAM'de her sembol $\log_2 M$ bit taşır.

Bir baud'a sığdırılan bit grubuna farklı isimler verilir:

- 3 bit: tribit.
- 4 bit: quadbit.
- 5 bit: pentabit.

<!-- BELİRSİZ: Altyazıda 3 bitlik birimin adı "3 bit" diye bozuk geçiyor; "tribit" olduğu varsayıldı. 2 bitlik birimin adı (dibit) derste söylenmedi. -->

## 17. Örneksel-Örneksel Kodlama: AM, FM, PM

Hoca kısa bir aradan sonra, daha az kullanacağımız tek kodlama türüne geçti: örnekselden örneksele. Sebebi, bilgisayar haberleşmesinde işin bir ucunda mutlaka sayısal bir şey olmasıdır. Yine de buraya kadar konuşmuşken üzerinden geçilmesi gerekiyordu.

Örneksel-örneksel kodlamanın günlük hayatta en çok içinde olduğumuz örneği radyo iletişimidir. Bazı modülasyon tekniklerini adıyla zaten biliriz:

- **AM (Amplitude Modulation):** Taşıyıcı sinyalin genliği, aktarmak istediğimiz örneksel işaretle kiplenir. Hoca bunu "bir şekilde kılıf gibi giydiriyoruz" diye anlattı.
- **FM (Frequency Modulation):** Bu kez taşıyıcı sinyalin sıklığıyla oynanır.
- **PM (Phase Modulation):** Adı üstünde, faz üzerinden kipleme yapılır. Benzer şekilde iki örneksel sinyal arasında faz üzerinden bir geçiş yapılır.

Hoca bu kısmın slaytı olduğunu sonradan fark ettiğini, yok sandığı için konuyu sözlü anlattığını söyledi.

### 17.1 AM Neden Uzağa Gider?

Hoca "Radyolarda uzun dalga AM, kısa dalga FM; uzun dalga AM denmesinin nedeni ne?" diye sordu. Bir öğrenciden doğru cevap geldi. Hoca, daha uzak ya da daha kısa mesafelere gidebilmenin temelinin dalga boyu ile iletim menzili ilişkisi olduğunu söyledi. Doğru bir anteniniz varsa Amerika'da AM frekansında yayın yapan bir radyoyu, biraz gecikmeli de olsa, burada dinleme ihtimaliniz vardır. FM'de bu iş çok daha zordur.

> **Ders sonrası not:** "Uzun dalga AM, kısa dalga FM" ifadesi yanıltıcıdır. AM yayınları büyük olasılıkla orta dalga (yaklaşık 530-1700 kHz) ve uzun dalga bantlarındadır; dalga boyları yüzlerce metredir. FM yayınları büyük olasılıkla 88-108 MHz'te, VHF bandındadır; dalga boyu yaklaşık 3 metredir. "Kısa dalga" (shortwave, 3-30 MHz) ayrı bir bant adıdır ve çoğunlukla AM yayını içerir. AM'nin uzağa gitmesi düşük frekanslı dalgaların yer dalgası olarak yayılması ve geceleri iyonosferden yansımasıyla açıklanır; VHF'deki FM ise çoğunlukla görüş hattıyla sınırlıdır.

## Örnek Sorular

**1. (derste sözlü, 00:09:25)** AMI'de 1'ler dönüşümlü olarak artı ve eksi polariteyle kodlanırsa, hat üzerinde uzun vadede ortalama gerilim ne olur?

> **Çözüm (derste verildi):** 1'ler hem pozitif hem negatif tarafta gösterildiği için ortalama gerilim sıfır olur. DC bileşenden kurtulunur.

**2. (derste sözlü, 00:09:53)** AMI'de art arda gelen sıfırların sayısı artarsa nasıl bir problem çıkar?

> **Çözüm (derste verildi):** Sinyaldeki değişim azalır. Karşı taraf sinyali anlamlandıramaz, senkron bozulur. Çözüm olarak B8ZS ya da HDB3 ile sıfır dizileri bilerek bozulur.

**3. (derste sözlü, 00:16:29)** Teknik olarak örneksel (analog) bir sinyal nasıl bir sinyaldir? Temel özelliği nedir?

> **Çözüm (derste verildi):** Temel özelliği sürekliliktir. Örneksel işaret kesintisiz, devam eden bir işarettir. "Analog" cevabı doğru ama sorunun tekrarı olduğu için eksiktir.

**4. (derste sözlü, 00:20:09)** PAM'de örneklerin sık alınması, yani sinyali daha iyi anlamak bize ne kazandırır?

> **Çözüm (derste verildi):** Sayısala çevrilen bilgi büyük ihtimalle daha sonra tekrar örneksele çevrilecektir. Örnekleme ne kadar sık olursa geri elde edilen işaret o kadar düzgün olur.

**5. (derste sözlü, 00:38:56)** ASK'de genliğin yüksek olduğu ve düşük olduğu iki sinyal parçasından hangisi 0, hangisi 1'dir? Buna kim karar verir?

> **Çözüm (derste verildi):** Biri 0 ise diğeri 1'dir. Hangisinin 0 olacağı bir standart değildir; ASK'yi uygulayan kişinin sistem içinde verdiği bir karardır.

**6. (derste sözlü, 00:40:49)** ASK'nin temel problemi nedir?

> **Çözüm (derste verildi):** İletim ortamı elektromanyetik sinyale, gürültüye ve ısıya açıktır. Bu dış etkiler önce genliği değiştirir. Genlikteki istenmeyen bir değişim 0'ın 1, 1'in 0 olarak algılanmasına yol açabilir. FSK bu açıdan daha dayanıklıdır.

**7. (derste sözlü, 00:55:00)** Radyoda AM yayınları neden FM yayınlarına göre çok daha uzak mesafelere ulaşabilir?

> **Çözüm (derste verildi):** Hocaya göre temel sebep dalga boyu ile iletim menzili ilişkisidir. AM'de uygun bir antenle çok uzak ülkelerdeki yayınlar bile dinlenebilir, FM'de bu çok daha zordur. Bant adlarıyla ilgili düzeltme için 17.1'deki ders sonrası nota bakın.

<!-- BELİRSİZ: 00:55:11'deki öğrenci cevabı altyazıda yalnızca "Niye efendim kısa dalga?" diye geçiyor; öğrencinin tam cevabı okunmuyor. -->

## Dersin Toparlaması

Bu derste sayısal-sayısal kodlamanın son parçası olan bipolar kodlama tamamlandı. AMI, 1'leri dönüşümlü polariteyle kodlayarak DC bileşeni ortadan kaldırır, ama uzun sıfır dizilerinde senkron sorunu bırakır. B8ZS (Kuzey Amerika) 8 sıfırı, HDB3 (Avrupa ve Japonya) 4 sıfırı, AMI'de oluşamayacak ihlal desenleriyle bilerek bozarak bu sorunu çözer. Ardından örneksel-sayısal kodlamaya geçildi. Sürekli bir işaret PAM ile eşit aralıklarla ve Nyquist teoremine göre en yüksek frekansın en az iki katı hızda örneklenir. PCM ile örnekler 8 bitlik (telefonda) sayılara çevrilir, ikili diziye dönüştürülür ve bir sayısal-sayısal kodlamayla gönderilir.

Sayısal-örneksel kodlamada bir taşıyıcı işaretin genliği (ASK), frekansı (FSK) ya da fazı (PSK) değiştirilir. ASK gürültüye hassastır, FSK daha dayanıklıdır. Bir baud'da birden fazla bit taşındığında bit hızı baud hızını aşar: 4-PSK'de 2, 8-QAM'de 3, 16-QAM'de 4 bit. Gerçek veri iletiminde çoğunlukla genlik ve fazı birlikte kullanan QAM tercih edilir. Son olarak örneksel-örneksel kodlamanın radyodaki örnekleri AM, FM ve PM kısaca anlatıldı. Hoca, bu grubun diğer gruplardan önde olduğunu söyleyerek dersi erken bitirdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
