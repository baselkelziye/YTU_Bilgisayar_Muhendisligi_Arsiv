# Ders 3 Genişletilmiş Notu: Moore Makinesi ile Sayıcı Tasarımı, Asenkron Sayıcılar, Yazmaçlar ve Yüklemeli Senkron Sayıcı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Hatırlatması: Mealy Makinesi ve Ters Tanım Bağıntısı
- 2. Moore Makinesi Örneği: 1, 2, 3, 4 Sayan Senkron Devre
- 3. Durum Kodlamasının Devreye Etkisi
- 4. JK Flip-Flop'un İleri ve Ters Tanım Tabloları
- 5. Durum Tablosu, Karnaugh Haritaları ve Şematik
- 6. Asenkron Set ve Reset ile İlk Durum Oluşturma
- 7. Kullanılmayan Durumlar ve Kendi Kendini Düzeltme
- 8. Asenkron (Ripple) Sayıcılar
- 9. Senkron Ardışıl Devre Blokları: Yazmaç
- 10. Ötelemeli Yazmaç (Shift Register)
- 11. Paralel Yüklemeli Ötelemeli Yazmaç
- 12. Yükleme Ucu Olan Senkron Yukarı Sayıcı
- 13. Örnek Sorular

## 1. Önceki Dersin Hatırlatması: Mealy Makinesi ve Ters Tanım Bağıntısı

Hoca derse önceki haftada başlanan senkron ardışıl devre tasarımını hatırlatarak başladı. Önceki derste bir seri toplayıcı tasarlanmıştı. Bunun için önce kullanılacak flip-flop'un ileri yönlü ve geri yönlü (ters) tanım bağıntıları çıkarılmıştı.

İleri yönlü tanım bağıntısı, flip-flop'un mevcut durumu ($q$) ve girişleri verildiğinde bir sonraki durumun ($Q$) ne olacağını veren tablodur. Tasarım sırasında ise elimizde tersi vardır. Sözel olarak tanımlanan problem bir durum diyagramına indirgendiğinde, her mevcut durum ve giriş için sonraki durumun ne olacağı bellidir, yani $q \to Q$ geçişi bellidir. Aranan, bu geçişi sağlamak için flip-flop'un giriş uçlarına hangi değerlerin verilmesi gerektiğidir. Bunu ters tanım bağıntısı verir. Bu değerler 0, 1 ya da don't care olabilir.

Böylece tasarım problemi şuna dönüşür: girdiler, giriş değişkenleri ve şimdiki durumlardır; çıktılar, flip-flop giriş uçlarına bağlanacak lojik fonksiyonlardır.

Seri toplayıcıda çıkış (toplam biti) hem mevcut duruma (elde var ya da yok) hem de girişlere ($x_i$, $y_i$) bağlıydı. Örneğin elde yokken 1-1 girişiyle 1-0 girişi farklı çıkış verir. Çıkışın hem duruma hem girişe bağlı olduğu senkron ardışıl devrelere **Mealy makinesi** denir. O tasarımda iki durum (elde var, elde yok) olduğu için tek flip-flop yetmişti. $n$ durum olsaydı $\lceil \log_2 n \rceil$ flip-flop gerekecek ve hepsinin saat girişine ortak bir işaret bağlanacaktı. Senkron demek, durum geçişlerinin bütün flip-flop'larda aynı anda olması demektir. Tek flip-flop olsa da önceki örnek teknik olarak senkron bir ardışıl devre ve bir Mealy makinesiydi.

## 2. Moore Makinesi Örneği: 1, 2, 3, 4 Sayan Senkron Devre

Bu derste bir **Moore makinesi** örneğiyle devam edildi. Hoca soruyu önce şöyle yazdı: 1, 2, 3, 4, 5, 1, 2, ... şeklinde sayan senkron ardışıl devreyi JK flip-flop'lar kullanarak tasarlayınız.

### 2.1 Girişi var mı?

Hoca önce bu problemde bir giriş değişkeni olup olmadığını sordu. Seri toplayıcıda iki sayının $i$ numaralı bitleri ($x_i$, $y_i$) girişti; elde bilgisini tutan flip-flop da şimdiki durumdu. Sayıcıda ise dışarıdan bir giriş yoktur.

**Soru:** Giriş yoksa bir durumdan diğerine geçiş nasıl sağlanacak? **Cevap:** Bir öğrenci saat darbeleriyle geçileceğini söyledi. Hoca bunu tamamladı: geçişi tetikleyen saat işaretidir ama 1'den 2'ye geçişle 4'ten 5'e geçişi birbirinden ayıran şey saat değildir; bunu mevcut durumlar belirler. Yani geçişleri, saat işaretinin tetiklediği durum değişiklikleri sağlar.

### 2.2 Flip-flop sayısı

Gereken flip-flop sayısı

$$\lceil \log_2 (\text{durum sayısı}) \rceil$$

ile bulunur. 1-5 sayıcıda 5 durum vardır, $\lceil \log_2 5 \rceil = 3$ flip-flop gerekir. Hoca örneği uzatmamak için 5'i sildi ve soruyu 1, 2, 3, 4, 1, 2, ... sayan devreye indirdi. 4 durum için 2 flip-flop yeterlidir (ekrandan, 00:15:00).

### 2.3 Durum diyagramı

Durum diyagramında "1 saydıran", "2 saydıran", "3 saydıran" ve "4 saydıran" dört durum vardır ve sırayla birbirine geçer. Giriş olmadığı için okların üzerine bir şey yazılmaz. Moore makinesinde çıkış yalnız duruma bağlı olduğundan çıkış (ya da durum kodu) durumun altına yazılabilir.

Hoca durum kodlarını ilk olarak sıralı (00, 01, 10, 11) yazmayı düşündü, sonra şöyle değiştirdi: 1 → 00, 2 → 01, 3 → 11, 4 → 10 (ekrandan, 00:15:00). Bu kodlamada her durum değişiminde yalnız bir bit değişir, tıpkı Karnaugh haritasındaki sıralama gibi. Bunun avantajı, Karnaugh haritasında daha fazla ortak paranteze alma şansı doğmasıdır. Hoca bunun durumdan duruma değişebileceğini ve analiz edilmesi gerektiğini de ekledi.

## 3. Durum Kodlamasının Devreye Etkisi

Hoca burada ayrı bir kutu açarak (ekrandan, 00:15:00) bir düşünce sorusu sordu: JK flip-flop'larla senkron bir tasarım yapılmış olsun. Durum kodlarındaki bitlerin değerleri değiştirilirse, devreyi yeniden tasarlamadan JK uçlarına bağlı değerler için ne söylenebilir?

### 3.1 Bitlerin yerini değiştirmek

Birinci kodlama 00, 01, 10, 11; ikinci kodlama aynı durumlar için 00, 10, 01, 11 olsun (bitlerin yeri değişmiş). Birinci tasarımda 1 numaralı flip-flop'un çıkışı $Q_1$, 2 numaralının çıkışı $Q_2$ diye adlandırılmıştı. Bir öğrenci J ve K bağlantılarının yerinin değiştirilmesini önerdi. Hoca daha basit bir gözlem yaptı: 1 numaralı flip-flop'tan çıkan değişken $Q_2$, 2 numaralıdan çıkan $Q_1$ diye adlandırılırsa ve girişler değiştirilmezse ikinci tasarım elde edilir. Yani kodlamada bitlerin yerini değiştirmek, flip-flop'ların sırasını, yani çıkışlarının adlarını değiştirmekle eşdeğerdir. Yapısal bir değişiklik olmaz.

### 3.2 Kodların tümleyenini almak

Bu sefer kodlar 00, 01, 10, 11 yerine aynı sırayla 11, 10, 01, 00 olsun. Bir öğrenci her flip-flop'un kendi J ve K bağlantılarının yer değiştirmesini önerdi. Hoca şu soruyu sordu: J ve K bağlantıları aynen kalsa, $Q_1$ ve $Q_2$ flip-flop'ların $\bar{Q}$ uçlarından alınsa olmaz mı? Bir öğrenci de aynı cevabı verdi ("bir ve iki, ikinin değili"). Bu durumda devrenin ana yapısı hiç değişmeden ikinci kodlamayla aynı devre elde edilir. Demek ki bu değişiklik de yapısal bir değişikliğe yol açmaz.

<!-- BELİRSİZ: Öğrencinin J ile K bağlantılarını yer değiştirme önerisine hoca açıkça "doğru" ya da "yanlış" demedi, doğrudan Q-üstü çözümüne geçti. -->

### 3.3 Sonuç

Bazı kodlamalar senkron ardışıl devrenin yapısını değiştirmez (bit yer değiştirme, tümleyen alma). Yapısal değişikliğe yol açabilen şey kodların sırasıdır; örneğin Karnaugh mantığıyla ardışık durumlar arasında tek bit değişecek biçimde sıralamak. Hoca bunun için sezgisel (heuristic) bir yaklaşım önerdi: ardışık durumların kodlarında tek bit değişimini yakalamaya çalışmak. Bu konu "durum kodlama optimizasyonu" adıyla ayrıca incelenir.

## 4. JK Flip-Flop'un İleri ve Ters Tanım Tabloları

İki JK flip-flop kullanılacağı için JK'nın ileri ve ters tanım tabloları gereklidir. İşlemler yükselen kenarda tanımlıdır. Diğer zamanlarda flip-flop girişler ne olursa olsun durumunu korur.

JK ileri yönlü tanım tablosu (ekrandan, 00:40:00):

| CLK | J K | Q |
|---|---|---|
| ↑ | 0 0 | $q$ (durumu korur) |
| ↑ | 0 1 | 0 (reset) |
| ↑ | 1 0 | 1 (set) |
| ↑ | 1 1 | $\bar{q}$ (tümler) |
| diğer | x x | $q$ |

Tasarımda gereken, $q \to Q$ geçişinin hangi JK girişlerinde gerçekleştiğidir. Hoca tabloyu satır satır tersine okudu:

- **$0 \to 0$:** Mevcut durum 0 ve sonraki durum 0. Bu, 00 satırında (durumu koruma) ve 01 satırında (reset) olur. İkisinde de $J=0$, K'nın önemi yok: $J=0$, $K=x$.
- **$0 \to 1$:** Bu, 11 satırında (tümleme) ve 10 satırında (set) olur. $J=1$ yeterli, K'nın önemi yok: $J=1$, $K=x$.
- **$1 \to 0$:** Bu, 11 satırında (tümleme) ve 01 satırında (reset) olur. $K=1$, J önemsiz: $J=x$, $K=1$.
- **$1 \to 1$:** Bu, 00 satırında (koruma) ve 10 satırında (set) olur. $J=x$, $K=0$.

JK ters tanım tablosu (ekrandan, 00:25:00):

| $q$ $Q$ | J | K |
|---|---|---|
| 0 0 | 0 | x |
| 0 1 | 1 | x |
| 1 0 | x | 1 |
| 1 1 | x | 0 |

## 5. Durum Tablosu, Karnaugh Haritaları ve Şematik

### 5.1 Durum tablosu

Olası bütün şimdiki durum kodları 00, 01, 10, 11'dir. Sonraki durumlar durum diyagramından okunur: 00 → 01, 01 → 11, 10 → 00, 11 → 10.

Çıkış için hoca önce 2 bitlik bir $Z$ düşündü, sonra 4'ü ikili gösterebilmek için 3 bit gerektiğini fark etti ve $Z_1Z_2Z_3$ olmak üzere üç çıkış tanımladı. Bunlardan birinin belki sabit bağlanabileceğini de söyledi. 00 durumunda 1 (001), 01 durumunda 2 (010), 11 durumunda 3 (011), 10 durumunda 4 (100) gösterilecektir.

Tamamlanmış durum tablosu (ekrandan, 00:30:00):

| $q_1q_2$ | $Q_1Q_2$ | $J_1K_1$ | $J_2K_2$ | $Z_1Z_2Z_3$ |
|---|---|---|---|---|
| 00 | 01 | 0x | 1x | 001 |
| 01 | 11 | 1x | x0 | 010 |
| 10 | 00 | x1 | 0x | 100 |
| 11 | 10 | x0 | x1 | 011 |

Örneğin ilk satırda $q_1: 0 \to 0$ olduğu için $J_1K_1 = 0x$, $q_2: 0 \to 1$ olduğu için $J_2K_2=1x$ yazılır. Diğer satırlar ters tanım tablosundan aynı şekilde doldurulur.

Elde edilmek istenen yedi fonksiyon şunlardır (ekrandan, 00:30:00): $J_1=f_1(q_1,q_2)$, $K_1=f_2(q_1,q_2)$, $J_2=f_3(q_1,q_2)$, $K_2=f_4(q_1,q_2)$, $Z_1=f_5(q_1,q_2)$, $Z_2=f_6(q_1,q_2)$, $Z_3=f_7(q_1,q_2)$. Giriş olmadığı için hepsi yalnız şimdiki durumlara bağlıdır.

Hoca, Moore makinesinde durum kodlarının normalde durumun altına yazıldığını, burada ise çıkışlar 1'den 4'e kadar sayıldığı için karışmasın diye çıkışları ayrı tabloya yazdığını belirtti.

### 5.2 Karnaugh haritaları

İki değişkenli haritalarda satır $q_1$, sütun $q_2$'dir (ekrandan, 00:35:00).

- **$J_1$:** $q_1=0$ satırında 0, 1; $q_1=1$ satırında x, x. Sağ sütun ($q_2=1$) gruplanır, $q_1$ düşer: $J_1 = q_2$.
- **$K_1$:** Değerler x, x, 1, 0. Sol sütun gruplanır: $K_1 = \bar{q}_2$.
- **$J_2$:** Değerler 1, x, 0, x. Üst satır ($q_1=0$) gruplanır: $J_2 = \bar{q}_1$.
- **$K_2$:** Değerler x, 0, x, 1. Alt satır gruplanır: $K_2 = q_1$.
- **$Z_1$:** Yalnız 10 satırında 1: $Z_1 = q_1 \bar{q}_2$.
- **$Z_2$:** Değerler 0, 1, 0, 1. Sağ sütun: $Z_2 = q_2$.
- **$Z_3$:** Değerler 1, 0, 0, 1:

$$Z_3 = \bar{q}_1\bar{q}_2 + q_1 q_2 = q_1 \odot q_2 = \overline{q_1 \oplus q_2}$$

Yani $Z_3$, $q_1$ ile $q_2$'nin XNOR'udur.

### 5.3 Şematik

Yükselen kenar tetiklemeli iki JK flip-flop çizilir. 1 numaralının çıkışı $q_1$, 2 numaralının çıkışı $q_2$'dir (ekrandan, 00:35:00). Bağlantılar:

- $J_1 \leftarrow q_2$, $K_1 \leftarrow \bar{q}_2$
- $J_2 \leftarrow \bar{q}_1$, $K_2 \leftarrow q_1$
- İki flip-flop'un saat girişleri ortak bir saat işaretine bağlanır, çünkü durum değişimleri aynı anda olmalıdır.
- $Z_1$: $q_1$ ve $\bar{q}_2$ bir VE kapısına girer. $Z_2$: doğrudan $q_2$. $Z_3$: $q_1$ ve $q_2$ bir XNOR kapısına girer.

Bu devre uygun ilk koşul verilirse istenen sayımı yapar. 1'den saymaya başlaması için 00 ilk durumu sağlanmalıdır. Sonra 01, 11, 10 ve tekrar 00'a gider. İlk durum 11 verilse de döngü bozulmaz; çıkış 3, 4, 1, 2, 3, ... diye sürer. Sürekli çalışan bir devrede bu fark anlaşılmayabilir ama belirli bir ilk durumu oluşturmak için özel bir şey yapmak gerekir: set ve reset uçları.

Tasarım python ile simüle edildi: 00'dan başlayınca çıkış dizisi 1, 2, 3, 4, 1, 2 olarak çıktı.

## 6. Asenkron Set ve Reset ile İlk Durum Oluşturma

JK flip-flop'larda ek olarak iki uç daha vardır: set ve reset. Bunlar aktif sıfır uçlardır, bu yüzden $\bar{S}$ ve $\bar{R}$ diye gösterilir (ekrandan, 00:40:00).

- $\bar{S}\bar{R}=11$ iken flip-flop normal çalışır.
- Tahtadaki sıra: $\bar{S}\bar{R}=00$, sonra $01$, sonra $11$ uygulanırsa ilk koşul olarak 1 oluşur.
- $\bar{S}\bar{R}=00$, sonra $10$, sonra $11$ uygulanırsa reset aktif olur ve ilk değer 0 olur.

> **Ders sonrası not:** Aktif sıfır set ve reset uçlarının ikisini birden 0 yapmak ($\bar{S}\bar{R}=00$) çoğu flip-flop'ta yasak ya da tanımsız durum olarak geçer. Q'yu 1 yapmak için büyük olasılıkla yalnız $\bar{S}\bar{R}=01$ verip sonra $11$'e dönmek yeterlidir; 0 yapmak için de $10$ verip $11$'e dönmek yeterlidir.

**Senkron ve asenkron durum değişimi farkı:** Devre çalışırken JK girişleri 00'dan 10'a değiştirilirse etkisi Q'da hemen görülmez. Saat işaretinin yükselen kenarında görülür. Saat işaretini bekleyerek yapılan durum değişimleri senkrondur. Set ve reset uçlarına yukarıdaki dizilerden biri uygulanırsa, saat işareti gelmemiş olsa bile Q istenen değere gider. Bu, asenkron olarak ilk durum oluşturmaktır.

Hoca izlenen adımları şöyle özetledi:

- Durum diyagramı çizildi.
- Analiz yapılıp kaç flip-flop gerektiğine karar verildi.
- Kullanılacak flip-flop'un ters tanım tablosu elde edildi.
- $q$'dan $Q$'ya geçişler için JK uçlarına bağlanacak değerler çıkarıldı.
- Çıkış ve durumlar için kodlama yapıldı.
- JK uçları ve çıkışlar için durumlara bağlı fonksiyonlar Karnaugh haritasıyla bulundu ve şematik çizildi.
- İlk koşul oluşturma gerçeklendi.

## 7. Kullanılmayan Durumlar ve Kendi Kendini Düzeltme

Hoca özel bir durum olarak 0, 1, 2, 3, 4, 5, 0, 1, ... sayan bir sayıcıyı sordu ve 1-2-3-4 sayıcıyla farkını tartışmaya açtı.

**Soru:** 0-5 sayıcının 1-4 sayıcıdan farkı nedir? **Cevap:** Bir öğrenci bir durum fazla olduğunu ve 3 flip-flop gerektiğini söyledi. Hoca ek bir farkı vurguladı: 2 flip-flop'la oluşturulabilecek 4 durumun hepsi 1-4 sayıcıda kullanılır. 3 flip-flop'la oluşturulabilecek 8 durumun ise yalnız 6'sı 0-5 sayıcıda kullanılır. Dolayısıyla 6 ve 7 olmak üzere iki don't care durum vardır (ekrandan, 00:45:00).

Tasarımda bu don't care'lere Karnaugh haritalarında 1 ya da 0 değeri verilir. Bunun sonucu incelenmelidir. Sayıcı 0'dan başlatılırsa düzgün sayar. Ama yanlışlıkla 6 ya da 7 durumundan başlarsa ne olur? Don't care seçimine göre devre 6 → 7 → 6 diye bu iki durum arasında sıkışıp kalabilir ve istenen aralığa hiç geçmeyebilir (ekrandan, 00:45:00). Böyle bir devre **kendi kendini düzeltmeyen** (self-correcting olmayan) bir devredir.

Don't care'ler, 6 durumundan asıl sayma döngüsündeki bir duruma dönülecek biçimde düzenlenebilir. Benzer şekilde 7 durumundan da asıl döngüye dönülecek bir düzenleme yapılabilir. Bu durumda sistem **kendi kendini düzeltir** (self-correcting).

**Soru:** "Yanlışlıkla" başlamak ne demek? **Cevap:** Set/reset uçlarıyla 000 ilk durumu oluşturulacakken yanlışlıkla 111 oluşturulmuş olabilir. Ya da sisteme elektromanyetik girişim olur ve flip-flop'ların durumu bozulur, ya da elektrik gidip gelir ve o sırada yanlış bir ilk durum oluşur. Bunlar arıza durumlarıdır.

**Soru:** Başta durumları farklı kodlamak (3'ü 11 ile göstermek) şemada gözle görülür bir değişiklik yaptı mı? **Cevap:** Hoca'ya göre bu kodlamada don't care'ler Karnaugh haritasında çoğunlukla alt alta geldi. Kodlama sıralı (00, 01, 10, 11) yapılsaydı çoğu çapraz gelecek ve daha karmaşık kapılar gerekecekti. Hoca bunun ayrıntılı bir analiz gerektirdiğini, durum kodlama optimizasyonunun ders kapsamında olmadığını, ama ardışık durumları tek bit farkla kodlamanın daha büyük Karnaugh grupları kurma şansını artırdığını söyledi.

> **Ders sonrası not:** Bu örnek özelinde sıralı kodlama (1 → 00, 2 → 01, 3 → 10, 4 → 11) da basit sonuç verir: ters tanım tablosundan $J_1=K_1=q_2$ ve $J_2=K_2=1$ çıkar; çıkışlar $Z_1=q_1q_2$, $Z_2=q_1\oplus q_2$, $Z_3=\bar{q}_2$ olur. Tek bit farkla kodlamanın avantajı her örnekte geçerli olmayabilir; hocanın da söylediği gibi bu sezgisel bir kuraldır.

## 8. Asenkron (Ripple) Sayıcılar

### 8.1 Senkron ve asenkron tasarım farkı

Şimdiye kadar hep senkron tasarım yapıldı. Senkron tasarımda bütün flip-flop'ların saat işareti ortak bir kaynaktan gelir. Asenkron tasarımda ise bir flip-flop saatini başka flip-flop'lardan ya da başka kaynaklardan alabilir. Asenkron sayıcıların temel fikri, bir katın çıkışının sonraki kattaki flip-flop'un saat işaretini oluşturmasıdır. Bunlara **ripple counter** denir. Kenar tetiklemenin yükselen ya da düşen kenar olmasına ve çıkışın $Q$'dan ya da $\bar{Q}$'dan alınmasına göre farklı davranışlar elde edilir.

### 8.2 Basamakların frekansı

0'dan 7'ye ikili sayma tablosu (ekrandan, 00:50:00): 000, 001, 010, 011, 100, 101, 110, 111. Saniyede bir sayıldığı düşünülsün. En düşük basamak her sayımda değişir. İkinci basamak onun yarı hızında, üçüncü basamak dörtte biri hızında değişir; 15'e kadar sayılsaydı dördüncü basamak sekizde biri hızında değişirdi. Hoca tahtaya önce "1 Hz, 2 Hz, 4 Hz, 8 Hz" yazdı, sonra bunları $1/2$, $1/4$, $1/8$ diye düzeltti (ekrandan, 01:05:00). Her basamak bir alttakinin yarı frekansıyla değiştiği için en düşük basamağın çıkışı bir sonraki basamağın saatine, onunki bir sonrakine bağlanarak sayıcı kurulabilir.

> **Ders sonrası not:** Saniyede bir sayım yapılırsa en düşük basamak her saniye durum değiştirir; bu, periyodu 2 saniye olan, yani büyük olasılıkla 0,5 Hz'lik bir kare dalgadır. Sonraki basamaklar 0,25 Hz ve 0,125 Hz olur. Önemli olan oran: her basamak bir alttakinin yarı frekansındadır.

### 8.3 Toggle eden tek kat: D flip-flop

Her katın kendi içinde 0, 1, 0, 1 diye sayması, yani her saat darbesinde durum değiştirmesi gerekir. Hoca bunu bir senkron ardışıl devre tasarım sorusu olarak sordu: 0, 1, 0, 1 şeklinde sayan senkron ardışıl devreyi D flip-flop ile tasarlayınız (ekrandan, 00:55:00). Her kat kendi içinde senkron olacak, katların kaskat bağlı hali asenkron olacaktır.

**Soru:** Saat işaretini D'ye versek? **Cevap:** Hoca bunu inceledi: saat işaretinin yükselen kenarıyla D'ye bağlı aynı işaret, küçük bir gecikme yüzünden hep 1 iken örneklenir. Bu, D'ye sürekli 1 bağlamak gibidir; çıkışta hep 1 görülür.

**Soru:** $\bar{Q}$'yu D girişine versek? **Cevap:** Bu tam istenen çözümdür. İlk değer $q=0$ olsun; $\bar{Q}=1$ D'ye gelir, yükselen kenarda içeri kopyalanır ve $q=1$ olur. Şimdi D'de 0 vardır; sonraki yükselen kenarda $q=0$ olur. Böylece 0, 1, 0, 1 elde edilir.

Aynı sonuç tasarım yöntemiyle de bulunur. İki durum vardır (0 ve 1). Hoca önce dört satırlı bir tablo yazıp bir şeyin eksik olduğunu fark etti; tablo yalnız iki satırlı olmalıdır, çünkü her durumun tek bir sonraki durumu vardır (ekrandan, 01:05:00):

| $q$ | $Q$ | D |
|---|---|---|
| 0 | 1 | 1 |
| 1 | 0 | 0 |

D flip-flop'ta D'deki değer bir sonraki durum olur, bu yüzden D sütunu $Q$ sütununun aynısıdır. Buradan $D=f(q)=\bar{q}$ bulunur.

### 8.4 T ve JK flip-flop ile toggle

T flip-flop'ta $T=0$ iken $Q=q$, $T=1$ iken $Q=\bar{q}$ olur (ekrandan, 01:00:00).

**Soru:** 0, 1, 0, 1 sayan devreyi T flip-flop ile gerçekleyiniz. T'ye $q$ verilse olur mu? **Cevap:** İlk değer 0 ise T'ye 0 gelir, durum hiç değişmez, hep 0 kalır. Bir öğrencinin belirttiği gibi T=1'de flip-flop tümler, bu yüzden T'ye sabit 1 bağlanmalıdır. Tasarım tablosunda da $0 \to 1$ ve $1 \to 0$ geçişlerinin ikisi için $T=1$ çıkar, yani $T=1$ (ekrandan, 01:00:00).

**Soru:** Aynı devreyi JK flip-flop ile gerçekleyiniz. **Cevap:** Bir öğrenci J ve K'ya 1 bağlanacağını söyledi. Bu, ileri tanım tablosundaki 11 satırıdır. Ters tanım tablosundan da $0 \to 1$ için $J=1, K=x$; $1 \to 0$ için $J=x, K=1$ gelir. Don't care'ler 1 alınırsa $J=1$, $K=1$ bulunur (ekrandan, 01:00:00).

### 8.5 Frekans bölme

$D=\bar{q}$ bağlı D flip-flop'un saatine bir kare dalga uygulanırsa çıkış yalnız yükselen kenarlarda değişir ve bir sonraki yükselen kenara kadar sabit kalır. Sonuçta çıkışın frekansı saat frekansının yarısı olur (ekrandan, 01:05:00). Yani 0-1 sayıcı frekansı ikiye böler.

Bu çıkış bir sonraki katın saati olarak kullanılır. İkinci kat da $D=\bar{q}$ bağlıdır ve saatini birinci katın $Q$ çıkışından alır. Örneğin saat 16 Hz ise birinci katın çıkışı 8 Hz, ikincininki 4 Hz olur. Üç bitlik sayıcı için üçüncü kat da aynı şekilde eklenir. En düşük frekanslı çıkış en anlamlı bittir; çıkışlar $(Z_3, Z_2, Z_1)$ olarak okunur, $Z_3$ en anlamlıdır (ekrandan, 01:10:00).

### 8.6 Zaman diyagramı: geri sayıcı

Hoca yükselen kenar tetiklemeli bu devrenin zaman diyagramını çizdi (ekrandan, 01:10:00). Başlangıçta $q_1=q_2=q_3=0$'dır.

- $q_1$, saatin her yükselen kenarında durum değiştirir.
- $q_2$, $q_1$'in yükselen kenarlarında durum değiştirir.
- $q_3$, $q_2$'nin yükselen kenarlarında durum değiştirir.

İlk saat kenarında $q_1$ 0'dan 1'e çıkar, bu $q_2$'yi tetikler, o da 1'e çıkar ve $q_3$'ü tetikler. Böylece 000'dan sonra gelen aralıklarda $q_3q_2q_1$ değerleri şöyle okunur:

$$111,\ 110,\ 101,\ 100,\ 011,\ 010,\ 001,\ 000$$

Yani 7, 6, 5, 4, ... Bu bir **geri sayıcıdır** (down counter). Bu sonuç python ile simüle edildi ve doğrulandı. Hoca ilk durumun bu sonucu değiştirmediğini de gösterdi: herhangi bir durumdan başlanırsa da 010, 001, 000, 111 ... diye geri sayılır.

**Soru:** Sayıcıyı ileri saydırmak için ne yapılabilir? **Cevap:** Bir öğrenci çıkışların terslerinin alınmasını önerdi. Çıkışları $\bar{Q}$ uçlarından almak doğru bir çözümdür: durum 111 iken çıkış 000, durum 110 iken çıkış 001 olur.

**Soru:** Saati ters alsak, yani düşen kenarda tetiklesek olur muydu? **Cevap:** Hoca bunu ayrı bir zaman diyagramıyla inceledi. Düşen kenar tetiklemede $q_1$ saatin düşen kenarlarında, $q_2$ $q_1$'in düşen kenarlarında, $q_3$ $q_2$'nin düşen kenarlarında değişir. Durumlar 000, 001, 010, 011, 100, 101, 110, 111 sırasıyla gelir.

Sonuç:

- Yükselen kenar tetikleme: çıkışlar $Q$'dan alınırsa geri sayıcı, $\bar{Q}$'dan alınırsa ileri sayıcı.
- Düşen kenar tetikleme: çıkışlar $Q$'dan alınırsa ileri sayıcı, $\bar{Q}$'dan alınırsa geri sayıcı.

Bu dört durum python simülasyonuyla doğrulandı (yükselen kenarda $Q$ çıkışı 7, 6, 5, ...; düşen kenarda 1, 2, 3, ...).

## 9. Senkron Ardışıl Devre Blokları: Yazmaç

Aradan sonra hoca, yapılan tasarım örnekleriyle senkron ardışıl devre bloklarının iç yapısının kabaca ortaya çıktığını söyledi. Kombinasyonel devrelerde küçük bloklardan büyük bloklar kurulduğu gibi, şimdi de senkron ardışıl devre bloklarına geçildi.

Tek bir flip-flop bir bitlik veri saklama elemanıdır. Sistemlerdeki sayısal değerler ise 8, 16 ya da günümüzde 64 bit gibi $n$ bitle ifade edilir. Bu yüzden $n$ bitlik saklama birimlerine ihtiyaç vardır.

Slayttaki yapı dört D flip-flop'tan oluşan bir saklama birimidir: **yazmaç** (register) (ekrandan, 01:35:00). Slaytta yazmaç, bir veri yolunu (bus) tutmak için kullanılan flip-flop'lar topluluğu olarak tanımlanır. Bağlantıya bakılırsa bu bir senkron ardışıl devredir: dışarıdan verilen girişler saatin yükselen kenarında eş zamanlı olarak içeri kopyalanır ve $Q$ çıkışlarından dışarı sunulur. D girişleri değişse de Q çıkışları önceki değerlerini korur. Yükselen kenar geldiği anda girişler çıkışa geçer, sonra girişler ne kadar değişirse değişsin çıkış en son kopyalanan değerde kalır. Bu yapı **n bitlik paralel yüklemeli yazmaçtır**.

Blok gösteriminde bloğun içinde $D_0, D_1, \dots, D_{n-1}$ girişleri, $Q_0, Q_1, \dots, Q_{n-1}$ çıkışları ve bir saat girişi vardır. Fonksiyon tablosu (ekrandan, 01:35:00):

| CLK | Q |
|---|---|
| ↑ | D |
| diğer | $q$ |

> **Hocanın vurgusu:** Bir bloğun içine yazılan etiketler bloğun kendi iç yapısındaki fonksiyonu gösterir. Dışarıya, uca yazılan değerler ise fiziksel olarak dış dünyadan o entegreye bağlanan değeri gösterir. Hoca bu notasyona uyulmasını istedi.

Paralel yüklemeli yazmacın kullanım yeri: örneğin bir CPU tasarlanırken ALU'da işleme giren değerler ve çıkan $n$ bitlik sonuç yazmaçlarda saklanır. Girdiler yazmaçta tutulur, ALU'da işlenir, sonuç yine bir yazmaca yazılır. $n$ bitlik işlemler için $n$ bitlik paralel yükleme yapan yazmaç gerekir.

## 10. Ötelemeli Yazmaç (Shift Register)

### 10.1 Yapı ve çalışma

Shift register da bir senkron ardışıl devredir. Seri olarak aktarılan verinin paralelleştirilmesinde kullanılır. Dış dünyadan bit bit gelen $n$ bitlik veri shift register'da adım adım biriktirilirse, $n$ adım sonunda yazmaçta $n$ bitlik veri elde edilir ve $Q$ çıkışlarından paralel olarak kullanılabilir.

Slayttaki yapıda (ekrandan, 01:40:00) blok olarak Clk ve $S_{in}$ (seri giriş) girişleri ve bir Q çıkışı vardır. İç yapıda dört D flip-flop kaskat bağlıdır: $S_{in}$ birinci flip-flop'un D'sine, $Q_1$ ikincinin D'sine, $Q_2$ üçüncünün, $Q_3$ dördüncünün D'sine gider. Saat işaretleri ortaktır, yani devre senkrondur.

Yükselen kenar geldiği anda, o anda dördüncü flip-flop'un girişindeki telde $Q_3$ vardır ve bu değer içeri kopyalanır; dördüncü flip-flop'un çıkışı artık önceki flip-flop'un değeri olur. Aynı anda üçüncü flip-flop $Q_2$'yi, ikinci $Q_1$'i, birinci de $S_{in}$'i alır. Böylece her şey bir adım kayar.

$n$ bitlik bir sayıyı sisteme girmek için $n$ yükselen kenar gerekir. Bit dizisi LSB'den başlayarak seri girişe geliyorsa $n$ adım sonra LSB sondaki flip-flop'ta, MSB ise ilk flip-flop'ta olur (ekrandan, 01:40:00). Çıkışta ilk flip-flop'un Q'su en anlamlı, sondakinin Q'su en düşük anlamlı bit olarak okunur.

### 10.2 Slayttaki örnek dizi

Başlangıçta bütün Q'lar 0'dır. $S_{in}$'e sırayla 1, 0, 1, 1, 1, 0, 0, 0 verilir. Her yükselen kenarda içerideki veri bir bit sağa kayar ve seri giriş en baştaki flip-flop'a girer (ekrandan, 01:40:00):

| t | $S_{in}$ | $Q_1$ | $Q_2$ | $Q_3$ | $Q_4=Q$ |
|---|---|---|---|---|---|
| $t_0$ | 1 | 0 | 0 | 0 | 0 |
| $t_1$ | 0 | 1 | 0 | 0 | 0 |
| $t_2$ | 1 | 0 | 1 | 0 | 0 |
| $t_3$ | 1 | 1 | 0 | 1 | 0 |
| $t_4$ | 1 | 1 | 1 | 0 | 1 |
| $t_5$ | 0 | 1 | 1 | 1 | 0 |
| $t_6$ | 0 | 0 | 1 | 1 | 1 |
| $t_7$ | 0 | 0 | 0 | 1 | 1 |

Tablo python simülasyonuyla doğrulandı.

### 10.3 Kaskat bağlama

Shift register'ın dışarı verilen Q çıkışı, bir sonraki yükselen kenardan önce dördüncü flip-flop'ta bulunan değerdir. Bunun amacı kaskat bağlamadır. Örneğin elde 8 bitlik shift register varken 16 bitlik veri saklanmak isteniyor olsun. İki yazmacın saat girişleri ortaklanır ve dış saate bağlanır. 16 bitlik seri veri birinci yazmacın seri girişine verilir, birincinin Q çıkışı ikincinin seri girişine bağlanır. Sonuçta birinci yazmaçta 16 bitlik verinin yüksek anlamlı byte'ı, ikincide düşük anlamlı byte'ı saklanır (ekrandan, 01:45:00).

### 10.4 Sağa ve sola öteleme

Fonksiyon tablosu, çıkış $Q_1Q_2Q_3Q_4$ anlam sırasıyla okunursa (ekrandan, 01:45:00):

| CLK | $S_{in}$ | Q |
|---|---|---|
| ↑ | 0 | $0\,q_1q_2q_3$ |
| ↑ | 1 | $1\,q_1q_2q_3$ |
| diğer | x | $q_1q_2q_3q_4$ |

Bu **sağa öteleme**dir. Aynı yapı, çıkış $Q_4Q_3Q_2Q_1$ anlam sırasıyla okunursa:

| CLK | $S_{in}$ | Q |
|---|---|---|
| ↑ | 0 | $q_3q_2q_1\,0$ |
| ↑ | 1 | $q_3q_2q_1\,1$ |
| diğer | x | $q_4q_3q_2q_1$ |

Bu da **sola öteleme**dir. Yani anlam sırasını farklı kabul ederek aynı devreyle tek başına sağa ya da sola öteleme elde edilir.

## 11. Paralel Yüklemeli Ötelemeli Yazmaç

### 11.1 Fonksiyon

Paralel yükleme ile öteleme işlemini birleştiren yapıya **paralel yüklemeli ötelemeli yazmaç** (parallel access / parallel load shift register) denir. Hoca bunu iki şekilde inceledi: lojik kapılarla (slayttaki yapı) ve MUX'larla.

Blok girişleri: clock, serial_in, 4 bitlik parallel_in ($D_3, D_2, D_1, D_0$) ve $\overline{\text{Shift}}/\text{Load}$ kontrol ucu; çıkış 4 bitliktir (ekrandan, 01:50:00). Kontrol ucunda 0 varsa öteleme (shift), 1 varsa paralel yükleme (load) yapılır. $Q_3$ en anlamlı alınırsa seri giriş $Q_3$'e, $Q_3$ $Q_2$'ye, $Q_2$ $Q_1$'e, $Q_1$ $Q_0$'a beslenir; yani $\overline{S}/L=0$ sağa ötelemeye karşılık gelir.

Fonksiyon tablosu (ekrandan, 01:50:00):

| CLK | $\overline{S}/L$ | $D_3D_2D_1D_0$ | $S_{in}$ | Q |
|---|---|---|---|---|
| ↑ | 0 | xxxx | 0 | $0\,q_3q_2q_1$ |
| ↑ | 0 | xxxx | 1 | $1\,q_3q_2q_1$ |
| ↑ | 1 | abcd | x | abcd |
| diğer | x | xxxx | x | $q_3q_2q_1q_0$ |

Paralel ve seri yükleme saatin yükselen kenarında, senkron olarak yapılır. Diğer zamanlarda girişlere bakılmaksızın önceki durum korunur.

### 11.2 Kapı seviyesinde analiz

Slayttaki devrede her flip-flop'un önünde iki VE kapısı ve bir VEYA kapısı vardır (ekrandan, 01:50:00). VE kapılarından biri seri tarafı (en üst katta seri giriş, diğerlerinde bir önceki katın Q'su), diğeri paralel girişi ($D_i$) geçirir. $\overline{S}/L$ bir kapıya doğrudan, diğerine bir tümleyici üzerinden gider.

- $\overline{S}/L=0$ iken paralel girişleri geçiren VE kapılarına 0 gelir, seri tarafı geçiren kapılara 1 gelir. Flip-flop'ların D uçlarına sırayla $S_{in}$, $Q_3$, $Q_2$, $Q_1$ gelir ve yükselen kenarda içeri kopyalanır. Öteleme gerçekleşir.
- $\overline{S}/L=1$ iken seri taraf 0 ile VE'lenir, paralel taraf 1 ile. VEYA kapılarının çıkışında $0+D_3=D_3$, $0+D_2=D_2$ vb. oluşur ve yükselen kenarda paralel değer yüklenir.

### 11.3 Tek katın tasarımı

Bir kat için girişler: kontrol ucu $C$ ($\overline{S}/L$), paralel giriş $D_i$ ve seri giriş $S_i$ (en üst katta dış seri giriş, diğerlerinde bir önceki katın $q_{i+1}$ çıkışı). Tablo (ekrandan, 01:55:00):

| $C$ | $D_i$ | $S_i$ | D |
|---|---|---|---|
| 0 | x | kullanılır | $S_i$ |
| 1 | kullanılır | x | $D_i$ |

Buradan flip-flop girişine bağlanacak fonksiyon:

$$D = \bar{C}\, S_i + C\, D_i$$

Kontrol ucunun kendisi ve tümleyeni ilgili girişlerle VE'lenip sonuçlar VEYA'lanır; slayttaki kapı yapısı tam olarak budur.

### 11.4 MUX ile tasarım

Hoca soruyu tahtaya şöyle yazdı: 4 bitlik paralel yüklemeli ötelemeli yazmacı D flip-flop ve MUX ile tasarlayınız (ekrandan, 02:00:00).

4 bit olduğu için 4 D flip-flop gerekir. Senkron olması için saatleri ortak bağlanır ve dış saat ucundan beslenir.

**Soru:** İki fonksiyon (paralel yükleme ve öteleme) varken kaça kaçlık MUX kullanılmalı? **Cevap:** 2'ye 1 MUX. Hoca, yazmacın dört fonksiyonu olsaydı (örneğin bütün çıkışları sıfırlama, bütün çıkışları tümleme, sağa kaydırma, sola kaydırma) iki kontrol ucu (00, 01, 10, 11) ve 4'e 1 MUX gerekeceğini söyledi.

Hoca MUX'ları önce iki seçim ucuyla ($S_1, S_0$) çizdi, sonra tek seçim ucu gerektiğini düzeltti (bir öğrenci sohbetten bu hatayı bildirmişti). Bütün MUX'ların seçim uçları ortak bağlanır, çünkü bütün flip-flop'lar aynı anda aynı işlemi yapmalıdır, ve dışarıya $\overline{S}/L$ kontrol ucu olarak çıkarılır. Bağlantılar (ekrandan, 02:05:00):

- Her MUX'un çıkışı ilgili D flip-flop'un D girişine gider.
- MUX'ların 1 girişlerine paralel girişler bağlanır: $D_3$, $D_2$, $D_1$, $D_0$.
- En üst MUX'un 0 girişine $S_{in}$, ikincisininkine $Q_3$, üçüncüsününkine $Q_2$, dördüncüsününkine $Q_1$ bağlanır.

Öteleme davranışını bu son bağlantılar sağlar. İki bitlik öteleme tanımlansaydı $Q_3$ hemen sonraki MUX'a değil, iki sonrakine bağlanırdı.

### 11.5 MUX yapısıyla başka fonksiyonlar

**Soru:** Kontrol ucu 1 iken Q'lara $\bar{q}_3\bar{q}_2\bar{q}_1\bar{q}_0$ yüklenmesi isteniyor (C = 0 iken öteleme sürsün). Ne yapılır? Bir öğrenci MUX kullanmadan dört T flip-flop'la yapılabileceğini söyledi. Hoca bunun mümkün olduğunu ama amacın küçük bloklardan büyük bloklar inşa etmek olduğunu, bu yüzden MUX'lu yapıyla çözülmesini istediğini belirtti. Bir başka öğrenci VE kapısıyla yapılmasını önerdi; hoca daha pratik bir yol olduğunu söyledi. **Cevap:** Her flip-flop'un $\bar{Q}$ çıkışı, kendi hizasındaki MUX'un 1 girişine bağlanır (ekrandan, 02:05:00). Örneğin yazmaçta 1111 varken kontrol 1 yapılırsa yükselen kenarda 0000 olur.

**Soru:** Kontrol 1 iken Q'larda 0 oluşturulmak isteniyor. **Cevap:** İlgili MUX girişlerine sabit 0 bağlanır. Yükselen kenarda D uçlarına 0 gelir ve içeri kopyalanır.

Hoca ayrıca öteleme yerine döndürme (rotate) yapılabileceğini söyledi. Öteleme yapıldığında en düşük anlamlı bitin çıkışı kaybolur. En düşük anlamlı bitin çıkışı döndürülüp en yüksek anlamlı katta $S_{in}$ yerine bağlanırsa döndürme olur.

Sonuç olarak değer yükleme, sıfırlama, sağa ve sola öteleme, döndürme, tümleyen alma ve bazı aritmetik işlemler MUX yapısıyla, MUX girişlerine uygun anlam sırasında uygun bağlantılar yapılarak gerçeklenebilir. Karmaşık bir devre mantığına gerek kalmaz. Bu yapı genelleştirilebilir bir yapıdır.

Hoca son olarak zorunlu olmayan bir alıştırma bıraktı: yazmacın bir sonraki değeri $Q = -q$ olabilir mi? Burada $-q$, $q$'nun ikiye tümleyenidir. Bu, T, JK ya da D flip-flop'la denenebilir (bkz. Örnek Sorular).

## 12. Yükleme Ucu Olan Senkron Yukarı Sayıcı

### 12.1 Blok yapı

Sayıcıların iç yapısı ders boyunca hem senkron hem asenkron olarak tasarlandı; asenkron tarafta kenar tetiklemeye ve çıkışın alındığı yere göre ileri ya da geri sayıcı elde edildi, keyfi sayma dizileri de yapılabildi. En genel blok halinde sunulan yapı **senkron yukarı sayıcıdır** (ekrandan, 02:15:00).

Slayttaki 4 bitlik sayıcı 0'dan 15'e kadar sayar ve tekrar 0'a döner (16 değer). Girişleri enable, load, $D_0$-$D_3$ ve clock; çıkışları carry ve $Q_0$-$Q_3$'tür. Slayttaki açıklamalar (ekrandan, 02:15:00):

- Enable (senkron): 1 iken sayıcı çalışır, 0 iken değerini korur.
- Load (senkron): load = 1 iken istenen değer sayıcıya yüklenir.
- Carry çıkışı: sayıcının başa döndüğünü (rolls over) gösterir; entegreler kaskat bağlanırken bir sonrakini tetiklemek için kullanılır.
- $D_3 \dots D_0$ ve $Q_3 \dots Q_0$, MSB'den LSB'ye doğru okunur.

Enable = 1, Load = 0 iken her yükselen kenarda içerideki 4 bitlik değer bir artar: 0, 1, 2, ..., 14, 15, 0, 1, ... Enable = 1, Load = 1 iken sonraki yükselen kenarda Q çıkışları D girişlerine eşit olur. Bu sayıcı yukarı sayıcıdır (up counter), çünkü değer yukarı doğru gider. Üst değerden alt değere sayan aşağı sayıcılar (down counter) da vardır.

### 12.2 0-10 arası sayıcı

**Soru:** 4 bit yukarı sayıcı kullanarak 0-10 arası sayan bir sayıcı gerçekleyiniz (ekrandan, 02:15:00).

Bir öğrenci reset ucu olup olmadığını sordu. Hoca reset ucu olmadığını, ama load ucunun kullanılabileceğini söyledi: load, girişlerdeki değeri çıkışa yükler. Bir öğrenci girişlere 0 verip çıkış 11 olunca load'u 1 yapmayı önerdi. Hoca 11'de yükleme yapılırsa sayıcının 0-11 arasında sayacağını (11 görüleceği için) belirtti; doğrusu çıkış 10 iken load'u 1 yapmaktır, böylece 10'dan sonraki yükselen kenarda 0 yüklenir.

Çıkışta 10 olduğunu anlamak için $q_3q_2q_1q_0 = 1010$ değerinde yalnız ve yalnız load = 1, diğer bütün değerlerde load = 0 üretilmelidir. Tek bir minterm vardır (ekrandan, 02:20:00):

$$L = \bar{q}_0\, q_1\, \bar{q}_2\, q_3$$

$D_3D_2D_1D_0 = 0000$ bağlanır. Sayıcı 0, 1, ..., 9 sayarken $L=0$'dır; 10'da $L=1$ olur ve sonraki yükselen kenarda 0 yüklenir. Sayıcı 0-10 arasında döner. Bu dizi python simülasyonuyla doğrulandı.

### 12.3 0-12 arası sayıcı

**Soru:** Sayıcıyı en uygun şekilde 0-12 arasında saydırmak için L ne olmalı? **Cevap:** Bir öğrenci $L = q_2 q_3$ cevabını verdi ve hoca doğruladı (ekrandan, 02:20:00). 0'dan sayılırken $q_2$ ve $q_3$ ilk kez 12'de (1100) birlikte 1 olur. Hoca doğal olarak $L=\bar{q}_0\bar{q}_1q_2q_3$ yazılmasını beklediğini, ama buna gerek olmadığını söyledi: sayıcı 13, 14 ve 15'e asla ulaşmayacağı için bunlar don't care'dir ve Karnaugh haritasında geriye $q_2q_3$ kalır. Hoca aynı basitleştirmenin 0-10 sayıcı için de yapılabileceğini, ama orada yapmadıklarını söyledi.

> **Ek bilgi (derste anlatılmadı):** 0-10 sayıcıda 11-15 değerlerine hiç ulaşılmaz. Bunlar don't care alınırsa 1010 minterm'i 1011, 1110 ve 1111 ile birlikte gruplanabilir ve $L = q_1 q_3$ elde edilir. Bu sadeleştirme python simülasyonuyla denendi, sayıcı yine 0-10 arasında döndü.

### 12.4 5-12 arası sayıcı

**Soru:** Sayıcıyı 5-12 arasında saydırmak için ne yapılır? **Cevap:** Bir öğrenci paralel girişe 0 yerine 5 verilmesini önerdi. Anlam sırasına göre $D_3D_2D_1D_0 = 0101$ yazılır, en düşük anlamlı bit $D_0$'dır. 12 geldiğinde yükleme için yine $L=q_2q_3$ kullanılır (ekrandan, 02:20:00).

Sistem başta sıfırlanırsa 0'dan başlar ve ilk turda 0, 1, 2, 3, 4 gibi istenmeyen değerleri de sayar. Sonra 5, ..., 12 sayar, 12'den sonra 5 yüklenir ve artık kendini düzeltmiş olarak 5-12 arasında döner. Bu davranış python simülasyonuyla doğrulandı (0, 1, ..., 12, 5, 6, ...).

### 12.5 Kullanım alanları

Bu yapı bir soyutlama seviyesi sağlar; bu seviyeden hareketle daha büyük bloklar kullanılabilir. Keyfi sayıcılar, belirli bir akışta gelmesi gereken kontrol işaretlerini üretmek için, yani algoritmik işlemlerin yürütülmesinde kullanılabilir. Sayıcılar sayma işinde de kullanılır. Yazmaçlar ise seri veriyi biriktirmek ya da işlem sonuçlarını paralel olarak saklamak için kullanılır. Bunlar ders boyunca kullanılacak senkron ardışıl devre bloklarıdır.

**Soru:** Load ucu 1-0 olduğunda ne yapıyordu? **Cevap:** Load aktif 1 çalışan bir uçtur. Load = 1 iken sonraki yükselen kenarda D uçlarındaki değerler içerideki flip-flop'lara kopyalanır; sayıcı paralel yüklemeli yazmaç gibi davranır. Load = 0 iken dış değerler alınmaz, içerideki değer her yükselen kenarda bir artar. Aralık ayarlamada load'a 1 vermenin amacı sıfırlamak değil, istenen değere ulaşıldığında istenen dış değeri içeri yüklemektir.

## 13. Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): 1, 2, 3, 4, 1, 2, 3, ... şeklinde sayan senkron ardışıl devreyi JK flip-flop kullanarak tasarlayınız.

> **Çözüm (derste verildi):** $\lceil\log_2 4\rceil = 2$ flip-flop. Kodlar 1 → 00, 2 → 01, 3 → 11, 4 → 10; çıkış 3 bit. Bölüm 5'teki tablodan $J_1=q_2$, $K_1=\bar{q}_2$, $J_2=\bar{q}_1$, $K_2=q_1$, $Z_1=q_1\bar{q}_2$, $Z_2=q_2$, $Z_3=\overline{q_1\oplus q_2}$. Saatler ortak; ilk durum 00 set/reset uçlarıyla verilir.

**Soru 2** (ekrandan, 00:15:00): JK flip-flop'larla yapılmış bir senkron tasarımda durum kodları 00, 01, 10, 11 yerine 00, 10, 01, 11 yapılırsa devreyi yeniden tasarlamadan nasıl bir değişiklik yapılır?

> **Çözüm (derste verildi):** Flip-flop çıkışlarının adları yer değiştirir ($q_1$ ile $q_2$); yapı değişmez.

**Soru 3** (derste sözlü, 00:16:27): Kodlar aynı sırayla 11, 10, 01, 00 yapılırsa ne değişir?

> **Çözüm (derste verildi):** J ve K bağlantıları aynen kalır; durum değişkenleri flip-flop'ların $\bar{Q}$ çıkışlarından alınır. Yapı değişmez.

**Soru 4** (derste sözlü, 00:42:02): 0, 1, 2, 3, 4, 5 sayan sayıcıyla 1, 2, 3, 4 sayan sayıcı arasındaki fark nedir?

> **Çözüm (derste verildi):** 0-5 sayıcı 3 flip-flop ister ve 8 durumdan yalnız 6'sını kullanır; 6 ve 7 don't care'dir. Don't care seçimine göre devre 6 ile 7 arasında sıkışabilir (kendi kendini düzeltmeyen devre). Don't care'ler 6 ve 7'den asıl döngüye dönülecek biçimde seçilirse devre kendi kendini düzeltir.

**Soru 5** (ekrandan, 00:55:00): 0, 1, 0, 1 şeklinde sayan senkron ardışıl devreyi D flip-flop ile tasarlayınız.

> **Çözüm (derste verildi):** $q=0 \to Q=1$ için $D=1$, $q=1 \to Q=0$ için $D=0$; $D=\bar{q}$, yani $\bar{Q}$ çıkışı D girişine bağlanır.

**Soru 6** (ekrandan, 01:00:00): Aynı devreyi T flip-flop ile ve JK flip-flop ile gerçekleyiniz.

> **Çözüm (derste verildi):** T flip-flop'ta her iki geçiş için $T=1$, yani T'ye sabit 1 bağlanır. JK flip-flop'ta $J=1, K=x$ ve $J=x, K=1$ satırlarından $J=K=1$ alınır.

**Soru 7** (ekrandan, 01:10:00): Yükselen kenar tetiklemeli, $D=\bar{q}$ bağlı üç D flip-flop'un her biri saatini bir öncekinin $Q$ çıkışından alıyor ve çıkışlar $Q$'lardan alınıyor. Sayıcı nasıl sayar? İleri saydırmak için ne yapılabilir?

> **Çözüm (derste verildi):** 000'dan sonra 111, 110, 101, 100, 011, 010, 001, 000 sayar; geri sayıcıdır. İleri saydırmak için çıkışlar $\bar{Q}$'lardan alınır ya da düşen kenar tetiklemeli flip-flop kullanılıp çıkışlar $Q$'lardan alınır.

**Soru 8** (derste sözlü, 01:58:13): Paralel yükleme ve öteleme olmak üzere iki fonksiyonu olan yazmaç MUX ile tasarlanacaksa kaça kaçlık MUX kullanılmalıdır?

> **Çözüm (derste verildi):** İki fonksiyon tek kontrol ucuyla seçilir, 2'ye 1 MUX yeterlidir. Dört fonksiyon olsaydı iki kontrol ucu ve 4'e 1 MUX gerekirdi.

**Soru 9** (ekrandan, 02:00:00): 4 bitlik paralel yüklemeli ötelemeli yazmacı D flip-flop ve MUX ile tasarlayınız.

> **Çözüm (derste verildi):** Her D flip-flop'un önüne bir 2'ye 1 MUX konur; seçim uçları ortak bağlanıp $\overline{S}/L$ olur. 1 girişlerine $D_3..D_0$, 0 girişlerine sırayla $S_{in}$, $Q_3$, $Q_2$, $Q_1$ bağlanır. Saatler ortaktır.

**Soru 10** (derste sözlü, 02:03:57): Aynı yapıda kontrol ucu 1 iken yazmaca $\bar{q}_3\bar{q}_2\bar{q}_1\bar{q}_0$ yüklenmesi isteniyorsa ne yapılır? Kontrol 1 iken 0 yüklenmesi isteniyorsa ne yapılır?

> **Çözüm (derste verildi):** Her flip-flop'un $\bar{Q}$ çıkışı kendi hizasındaki MUX'un 1 girişine bağlanır. 0 yüklemek için ilgili MUX girişlerine sabit 0 bağlanır.

**Soru 11** (derste sözlü, 02:06:35): 4 bitlik yazmacın bir sonraki değeri $Q = -q$ (ikiye tümleyen) olacak biçimde bir devre tasarlanabilir mi? T, JK ya da D flip-flop ile deneyiniz.

> **Çözüm (derste verilmedi):** İkiye tümleyende, en düşük anlamlı bitten başlanarak ilk 1'e kadar (o 1 dahil) bitler aynı kalır, ondan sonraki bitler tümlenir. Bit $i$'nin tümlenmesi, kendisinden düşük anlamlı bitlerden en az biri 1 ise gerekir. T flip-flop ile: $T_0 = 0$, $T_1 = q_0$, $T_2 = q_0 + q_1$, $T_3 = q_0 + q_1 + q_2$. D flip-flop ile aynı fonksiyon $D_i = q_i \oplus T_i$ olur. Bu bağlantılar 0-15 arasındaki 16 değerin hepsi için python ile denendi; her değerde sonraki durum $(-q) \bmod 16$ çıktı.

**Soru 12** (ekrandan, 02:15:00): Enable, load ve carry uçları olan 4 bit yukarı sayıcı kullanarak 0-10 arası sayan bir sayıcı gerçekleyiniz.

> **Çözüm (derste verildi):** Enable = 1, $D_3D_2D_1D_0=0000$, $L = \bar{q}_0 q_1 \bar{q}_2 q_3$. Çıkış 10 iken $L=1$ olur, sonraki yükselen kenarda 0 yüklenir.

**Soru 13** (ekrandan, 02:20:00): Aynı sayıcıyı en uygun şekilde 0-12 arasında, sonra 5-12 arasında saydırınız.

> **Çözüm (derste verildi):** 0-12: $D=0000$, $L=q_2q_3$ (13, 14, 15 don't care). 5-12: $D_3D_2D_1D_0=0101$, $L=q_2q_3$. Sayıcı 0'dan başlarsa ilk turda 0-4 de görülür, sonra 5-12 arasında döner.

## Dersin Toparlaması

Bu derste senkron ardışıl devre tasarımı bir Moore makinesiyle tamamlandı. 1-2-3-4 sayıcı örneğinde durum diyagramı, flip-flop sayısının belirlenmesi, JK ters tanım tablosu, durum tablosu, Karnaugh haritaları ve şematik adım adım kuruldu. Durum kodlamasının yapıya etkisi tartışıldı: bit yer değiştirme ve tümleyen alma yapıyı değiştirmez, sıralama ise değiştirebilir. Asenkron set ve reset uçlarıyla ilk durumun nasıl verildiği ve kullanılmayan durumlar yüzünden ortaya çıkan kendi kendini düzeltme sorunu ele alındı. Ardından D, T ve JK flip-flop'larla toggle devresi kurulup frekans bölme gösterildi, bu katlar kaskat bağlanarak asenkron sayıcılar elde edildi ve kenar tetiklemeye ve çıkışın alındığı uca göre ileri ve geri sayma incelendi.

İkinci bölümde senkron ardışıl devre blokları tanıtıldı: paralel yüklemeli yazmaç, ötelemeli yazmaç (sağa ve sola öteleme, kaskat bağlama), kapı ve MUX seviyesinde paralel yüklemeli ötelemeli yazmaç ve yükleme ucu olan 4 bit senkron yukarı sayıcı. Load ucu ve uygun bir lojik fonksiyonla sayıcının istenen aralıkta saydırılması gösterildi. Hoca bir sonraki konunun bellek elemanlarından önce PAL, PLD ve PLA yapıları olacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
