# Ders 27 Genişletilmiş Notu: Flip-Floplar, Ardışıl Devre Analizi ve Sentezi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ardışıl devrenin yapısı ve depolama elemanları
- 2. Temel S-R tutucular
- 3. Saatli S-R tutucu (S-R flip-flop)
- 4. D, JK ve T flip-floplar
- 5. Karakteristik ve uyarma tabloları
- 6. Zamanlama diyagramları ve tetikleme türleri
- 7. Master-slave yapısı
- 8. Ardışıl devre analizi
- 9. Analiz örnekleri
- 10. Ardışıl devre sentezi
- Örnek Sorular
- Dersin Toparlaması

## 1. Ardışıl devrenin yapısı ve depolama elemanları

Ders, önceki derslerde başlanan ardışıl devre konusunu sunumun başından tekrar alarak başlar. Ders, İngilizce başlıklı slaytlar üzerinde tablet kalemiyle not alınarak anlatılır.

Bir ardışıl devre iki parçadan oluşur (ekrandan, 00:05:00):

- **Depolama elemanları:** tutucular (latch) ya da flip-floplar.
- **Kombinezonsal lojik:** çok çıkışlı bir anahtarlama fonksiyonu gerçekler.
  - Girişler (inputs) dışarıdan gelen işaretlerdir.
  - Çıkışlar (outputs) dışarıya giden işaretlerdir.
  - Depolama elemanlarından gelen diğer girişler **durum** ya da **şimdiki durum** (state, present state) işaretleridir.
  - Kombinezonsal bloğun depolama elemanlarına giden diğer çıkışları **sonraki durum** (next state) işaretleridir.

Depolama elemanı, bildiğimiz AND, OR, NOT gibi kapılarla kurulan bir devredir. Farkı, kapı çıkışlarının girişe geri beslenmesi ve kapı gecikmelerinden yararlanılarak bir bitlik bilginin tutulmasıdır. Ardışıl devrede durumlar arası geçiş bu elemanlarla sağlanır.

Hoca senkron ve asenkron ayrımını hatırlatır. Senkron elemanlar dışarıdan gelen bir senkronizasyon (saat) işareti olmadan, girişler nasıl değişirse değişsin, çıkışta değişim göstermez. Asenkron elemanlar ise girişteki değişimi hemen çıkışa aktarır. Hocanın kurduğu çerçevede tutucular asenkron, flip-floplar senkron elemanlardır: tutucunun girişine saatle kontrol edilen kapılar eklenince flip-flop elde edilir. Tutucu ile flip-flop arasındaki en belirgin fark bu tetikleme işaretidir.

> **Ek bilgi (derste anlatılmadı):** Saat girişli (gated) tutucu da saat işaretine bağlıdır, ama saat düzeyi etkin olduğu sürece girişi çıkışa geçirir. Ders kitaplarının çoğunda "flip-flop" adı, çıkışı yalnız saat kenarında değişen elemanlar için kullanılır. Hocanın "saatli SR tutucuya SR flip-flop diyeceğiz" yaklaşımı bu ayrımı basitleştirir.

## 2. Temel S-R tutucular

### 2.1 NAND ile kurulan $\bar S$-$\bar R$ tutucu

İki NAND kapısının çıkışları birbirinin girişine çapraz bağlanır (cross-coupling). Üstteki kapının diğer girişi $S$ (set), alttakininki $R$ (reset), çıkışlar $Q$ ve $\bar Q$'dur (ekrandan, 00:10:00). Hoca, her tutucu ya da flip-flopta giriş sayısı ne olursa olsun iki çıkış bulunduğunu vurgular: normal çıkış $Q$ ve onun tümleyeni $\bar Q$.

NAND kapılarıyla kurulduğu için girişler sıfırda etkindir (aktif düşük); bu yüzden adı $\bar S$-$\bar R$ tutucudur. $S$'ye 0 verilince $Q=1$ (kurma), $R$'ye 0 verilince $Q=0$ (sıfırlama) olur. Slayttaki zaman sırası tablosu:

| Sıra | $R$ | $S$ | $Q$ | $\bar Q$ | Açıklama |
|---|---|---|---|---|---|
| 1 | 1 | 1 | ? | ? | Saklanan durum bilinmiyor |
| 2 | 1 | 0 | 1 | 0 | $Q$ 1'e kuruldu |
| 3 | 1 | 1 | 1 | 0 | $Q$ 1'i "hatırlıyor" |
| 4 | 0 | 1 | 0 | 1 | $Q$ 0'a sıfırlandı |
| 5 | 1 | 1 | 0 | 1 | $Q$ 0'ı "hatırlıyor" |
| 6 | 0 | 0 | 1 | 1 | İki çıkış da yüksek |
| 7 | 1 | 1 | ? | ? | Kararsız |

Hoca tabloda 3. ve 5. satırları işaretleyerek $11$ girişinde çıkışın bir önceki değeri tuttuğunu gösterir. NAND tutucunun istenmeyen durumu $00$ girişidir: iki çıkış da 1 olur. Ardından $11$'e dönülürse hangi değerin kalacağı bilinmez.

> **Ders sonrası not:** Hoca $00$ durumunu, iki çıkışın da 1 olmasından dolayı "yüksek empedans" olarak niteledi. Doğrusu, bu durumda iki çıkış da geçerli lojik 1 düzeyindedir; durum yasak (istenmeyen) sayılır çünkü $Q$ ile $\bar Q$ artık tümleyen değildir. Yüksek empedans, üç durumlu (tri-state) çıkışların ayrı bir durumudur.

> **Ders sonrası not:** Altyazıda bir yerde NAND tutucu için "ikisine de 1,1 verdiğimde istenmeyen durum" geçiyor. NAND tutucuda istenmeyen giriş $00$'dır; $11$ önceki durumu korur. $11$'in istenmeyen olduğu yapı NOR tutucu ve saatli SR'dir.

### 2.2 NOR ile kurulan S-R tutucu

Aynı çapraz bağlama NOR kapılarıyla yapılırsa girişler birde etkin olur (aktif yüksek). $S=1$ verilince $Q=1$, $R=1$ verilince $Q=0$ olur. $S=R=0$ verilince önceki durum hatırlanır, $S=R=1$ istenmeyen durumdur.

Hoca bu tutucunun zamanlama davranışını şöyle anlatır: $S=1, R=0$ iken $Q$ 1 olur. $S=R=0$'a geçilince $Q$ 1'i hatırlar. $R$ 1'e çıkınca $Q$ küçük bir gecikmeyle 0'a düşer ve $S=R=0$ olunca 0'ı hatırlayarak devam eder. Bu iki tutucunun gösterilme nedeni flip-flopların bunlardan türetilecek olmasıdır.

## 3. Saatli S-R tutucu (S-R flip-flop)

Tutucuyu senkron hale getirmek için önüne saatle kontrol edilen kapılar konur. Devrede sağdaki iki NAND, Bölüm 2.1'deki $\bar S$-$\bar R$ tutucudur. Bunun önüne iki NAND daha eklenir: biri $S$ ile $C$ (saat), diğeri $R$ ile $C$ girişlidir (ekrandan, 00:15:00). Hoca maliyet açısından devrelerin genellikle yalnız NAND ya da yalnız NOR kapılarıyla kurulduğunu hatırlatır.

Öndeki NAND kapılarının etkisi şöyledir:

- $C = 0$ iken öndeki iki NAND da 1 verir; tutucu $11$ görür ve önceki durumu korur. Girişlerde ne değişirse değişsin çıkış değişmez.
- $C = 1$ iken öndeki NAND'lar girişlerin tümleyenini iletir. İki NAND art arda geldiği için tümleme iki kez yapılır; sonuçta yapı aktif yüksek bir SR elemanı gibi davranır.

Böylece asenkron tutucu saatle çalışan bir flip-flopa dönüşür. Sembolde $S$, $R$, saat girişi ve $Q$, $\bar Q$ çıkışları bulunur.

Slayttaki tablo, saat geldikten sonra ($t+1$ anında) olanı $Q(t)$, $S$ ve $R$'ye göre verir (ekrandan, 00:15:00):

| $Q(t)$ | $S$ | $R$ | $Q(t+1)$ | Açıklama |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | Değişim yok |
| 0 | 0 | 1 | 0 | $Q$ temizlenir |
| 0 | 1 | 0 | 1 | $Q$ kurulur |
| 0 | 1 | 1 | ??? | Belirsiz |
| 1 | 0 | 0 | 1 | Değişim yok |
| 1 | 0 | 1 | 0 | $Q$ temizlenir |
| 1 | 1 | 0 | 1 | $Q$ kurulur |
| 1 | 1 | 1 | ??? | Belirsiz |

Hoca saatin etkisini bir örnekle açıklar: $Q(t)=0$ iken $S=1$, $R=0$ yapılırsa normalde çıkışın 1'e kurulması beklenir. Ama saat gelmedikçe öndeki NAND kapıları tutucuya etkin bir işaret göndermez ve çıkış 0 kalır. Saat geldiğinde girişteki veri çıkışı günceller. Temel NAND tutucuda $00$ girişi sorunluydu; saatli yapıda girişler tümlendiği için sorunlu giriş $11$ olur.

## 4. D, JK ve T flip-floplar

### 4.1 D flip-flop

Saatli SR'nin bir başka biçimidir. $S$ girişi doğrudan $D$'ye, $R$ girişi ise bir değil kapısı üzerinden $\bar D$'ye bağlanır; dışarıdan tek giriş kalır. $D=0$ verilirse $R$'ye 1 gider ve flip-flop sıfırlanır; $D=1$ verilirse kurulur. Bu değişim de ancak saat geldikten sonra çıkışa yansır.

Adı "data" tipinden gelir: saat geldiğinde girişteki veri doğrudan çıkışa aktarılır. Önceki duruma hiç bakılmaz: $D=0$ ise $Q(t+1)=0$, $D=1$ ise $Q(t+1)=1$.

Sembolde genellikle bir kutu çizilir; $D$ girişi, saat girişi ve $Q$, $\bar Q$ çıkışları gösterilir. Saat girişi çoğunlukla küçük bir üçgenle işaretlenir; bazı kaynaklar üçgen koymaz. Amaç saat girişini belirtmektir.

### 4.2 JK flip-flop

JK flip-flop S-R ile aynı mantıktadır: $J$ kurma ($S$), $K$ sıfırlama ($R$) girişine karşılık gelir. S-R'deki en büyük sorun $11$ durumunun tanımsız olmasıdır. JK'da bu durumda çıkış önceki durumun tümleyenine geçer:

$$J = K = 1 \;\Rightarrow\; Q(t+1) = \bar Q(t)$$

Aradaki tek fark budur.

### 4.3 T (toggle) flip-flop

T flip-flop JK'dan türetilir. "Toggle" çeviren, tersleyen anlamındadır (ekrandan, 00:20:00):

- Tek girişi vardır: $T$.
- $T = 0$ ise durum değişmez: $Q(t+1) = Q(t)$.
- $T = 1$ ise durum tersine döner: $Q(t+1) = \bar Q(t)$.

Slaytta ayrıca T flip-flopun $J=K=T$ olan bir JK ile aynı olduğu, master-slave olarak kurulduğunda JK ile aynı "1 yakalama" davranışını gösterdiği ve $T$ girişiyle bilinen bir başlangıç durumuna getirilemeyeceği, bu yüzden asenkron ya da senkron bir sıfırlama girişinin gerektiği yazar (ekrandan, 00:20:00).

Hoca T flip-flopun iki şekilde kurulabileceğini gösterir:

1. **D flip-flop + XOR:** D flip-flopun girişine $T \oplus Q$ verilir. XOR kapısı girişleri aynıysa 0, farklıysa 1 üretir. $T=0$ iken XOR çıkışı $Q$'nun aynısıdır, D flip-flop bu değeri tekrar yazar ve durum değişmez. $T=1$ iken XOR çıkışı $\bar Q$'dur: $Q=0$ ise 1, $Q=1$ ise 0 yazılır, yani durum çevrilir.
2. **JK flip-flop:** $J$ ve $K$ girişleri birleştirilip tek $T$ girişi yapılır. $T=0$ JK için $00$, yani "aynısını koru"; $T=1$ ise $11$, yani "tümleyenini al" demektir.

## 5. Karakteristik ve uyarma tabloları

Hoca bu kısmın ezberlenmesi gerektiğini söyler. Her flip-flop için üç tanımlayıcı vardır: karakteristik tablo, karakteristik denklem ve uyarma (excitation) tablosu. Hoca uyarma tablosunu "anlam çıkarma tablosu" diye adlandırır.

> **Hocanın vurgusu:** D, T, JK ve SR flip-flopların karakteristik tablolarını, karakteristik denklemlerini ve özellikle uyarma tablolarını bilmek gerekir. Set-reset mantığı oturunca bunlar zor değildir.

### 5.1 D flip-flop

- Karakteristik tablo: $D=0 \Rightarrow Q(t+1)=0$, $D=1 \Rightarrow Q(t+1)=1$.
- Karakteristik denklem: $Q(t+1) = D$. Sonraki durum yalnız $D$'ye bağlıdır.
- Uyarma tablosu tersinden bakar: sonraki durum biliniyorsa $D$ girişine ne gelmesi gerektiğini verir. $Q(t+1)=0$ ise $D=0$, $Q(t+1)=1$ ise $D=1$.

### 5.2 T flip-flop

Slayttaki tanımlayıcılar (ekrandan, 00:25:00):

| $T$ | $Q(t+1)$ | İşlem |
|---|---|---|
| 0 | $Q(t)$ | Değişim yok |
| 1 | $\bar Q(t)$ | Tümleme |

$$Q(t+1) = T \oplus Q$$

Uyarma tablosu:

| $Q(t+1)$ | $T$ | İşlem |
|---|---|---|
| $Q(t)$ | 0 | Değişim yok |
| $\bar Q(t)$ | 1 | Tümleme |

Yani sonraki durumda önceki çıkışın aynısı görülüyorsa $T=0$, tümleyeni görülüyorsa $T=1$ olmalıdır.

### 5.3 S-R flip-flop

Karakteristik davranış: $00$ önceki durumu hatırlar, $01$ sıfırlar, $10$ kurar, $11$ çalışmaz (tanımsız). D ve T'de uyarma tablosu kolaydır; S-R ve JK'da biraz daha düşünmek gerekir. Hoca her geçişi tek tek yorumlar:

- $0 \to 0$: Ya sıfırlama ($S=0, R=1$) yapılmıştır ya da değişmeme ($S=0, R=0$). Ortak olan $S=0$'dır; $R$'nin değeri önemsizdir: $S\,R = 0\,X$.
- $0 \to 1$: Tek yol kurmadır. S-R flip-flop tümleyen almaz, bu yüzden başka bir olasılık yoktur: $1\,0$.
- $1 \to 0$: Tek yol sıfırlamadır: $0\,1$.
- $1 \to 1$: Ya değişmeme ($0\,0$) ya da kurma ($1\,0$) yapılmıştır. $R$ kesinlikle 0'dır, $S$ önemsizdir: $X\,0$.

| $Q(t)$ | $Q(t+1)$ | $S$ | $R$ |
|---|---|---|---|
| 0 | 0 | 0 | X |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 |
| 1 | 1 | X | 0 |

Bu tablonun neden gerektiğini hoca şöyle açıklar: tasarımda bir S-R entegresinin önüne, $S$ ve $R$ girişlerine doğru veriyi getirecek bir kombinezonsal devre konacaktır. Bu devre, $Q(t)$ ve $Q(t+1)$'e göre yazılan $S$ ve $R$ değerlerinden Karnaugh diyagramı çıkarılarak tasarlanır. Dersin başındaki "kombinezonsal devreye eklenen depolama elemanı" şeması bu şekilde tamamlanır.

### 5.4 JK flip-flop

Karakteristik davranış: $00$ değişmez, $01$ sıfırlar, $10$ kurar, $11$ tümler. Uyarma tablosu yine tersinden çıkarılır:

- $0 \to 0$: Ya sıfırlama ($0\,1$) ya da değişmeme ($0\,0$): $0\,X$.
- $0 \to 1$: Ya kurma ($1\,0$) ya da tümleme ($1\,1$): $1\,X$. $K$'ye bakılmaz.
- $1 \to 0$: Ya sıfırlama ($0\,1$) ya da tümleme ($1\,1$): $X\,1$.
- $1 \to 1$: Ya değişmeme ($0\,0$) ya da kurma ($1\,0$): $X\,0$.

| $Q(t)$ | $Q(t+1)$ | $J$ | $K$ |
|---|---|---|---|
| 0 | 0 | 0 | X |
| 0 | 1 | 1 | X |
| 1 | 0 | X | 1 |
| 1 | 1 | X | 0 |

> **Ek bilgi (derste anlatılmadı):** S-R ve JK flip-flopların karakteristik denklemleri sırasıyla $Q(t+1) = S + \bar R Q$ ($SR=0$ koşuluyla) ve $Q(t+1) = J\bar Q + \bar K Q$ biçimindedir. Bu denklemler, karakteristik tablolar Karnaugh diyagramıyla sadeleştirilerek elde edilir.

## 6. Zamanlama diyagramları ve tetikleme türleri

### 6.1 D ve T flip-flop örneği

Slaytta bir saat işareti, D ve T flip-flopların ikisine birden uygulanan ortak bir $D,T$ giriş işareti ve iki flip-flopun çıkışları ($Q_D$, $Q_T$) çizilidir (ekrandan, 00:30:00). Flip-floplar yükselen kenarda tetiklenir ve başlangıçta iki çıkış da 0'dır.

Giriş, birinci yükselen kenardan biraz önce 1'e çıkar. Buna rağmen ilk kenara kadar çıkışlarda değişim olmaz, çünkü çıkış ancak saatle güncellenir. Kenardan sonra küçük bir gecikmeyle çıkış değişir; hoca D tipinde bu gecikmenin biraz daha fazla çizildiğine dikkat çeker. Kenarlar boyunca olanlar:

| Kenar | O anki $D,T$ | $Q_D$ | $Q_T$ |
|---|---|---|---|
| 1 | 1 | 0 → 1 | 0 → 1 (tümleme) |
| 2 | 0 | 1 → 0 | 1 (değişim yok) |
| 3 | 1 | 0 → 1 | 1 → 0 (tümleme) |
| 4 | 0 | 1 → 0 | 0 (değişim yok) |

Giriş birinci kenardan kısa bir süre sonra 0'a iner, ama çıkışlarda hemen bir değişim olmaz; $Q_D$ ancak ikinci kenarda 0'a düşer. Benzer şekilde giriş ikinci ve üçüncü kenar arasında 1'e çıkar; etkisi üçüncü kenarda görülür.

### 6.2 Tetikleme türleri

- **Yükselen kenar tetikleme:** Güncelleme yalnız saat darbesinin yükselen kenarında olur.
- **Düşen kenar tetikleme:** Güncelleme yalnız düşen kenarda olur.
- **Düzey tetikleme:** Saat düzeyi etkin olduğu sürece girişteki değişimler hemen çıkışa yansır.

Örnekteki flip-floplar yükselen kenar tetiklemelidir.

### 6.3 JK ve SR örneği

İkinci zamanlama örneğinde aynı girişler bir JK ve bir SR flip-flopa uygulanır (bu anın karesi yok, anlatım altyazıdan):

- Birinci kenarda giriş $1\,0$'dır ($S=J=1$): iki çıkış da 1 olur.
- Sonraki kenarda giriş $0\,1$'dir: ikisi de sıfırlanır.
- Sonraki kenarda giriş $1\,1$'dir: SR için bu tanımsızdır, ne olacağı bilinmez. JK ise tümler ve çıkışını 1'e çıkarır.
- Sonraki kenarda giriş $0\,1$'dir: JK de sıfırlanır.

## 7. Master-slave yapısı

Hoca bu yapıyı ayrıntılı anlatmayacağını, yalnız mantığını vereceğini söyler. Flip-flop saat darbesiyle tetiklenir ve sonuç ancak o zaman çıkışa yansır; örneğin yükselen kenar tetiklemede yalnız yükselen kenarlarda. Hoca, iki flip-flop birinin saati 1 iken diğerininki 0 olacak şekilde (tümleyen saatlerle) bağlanırsa birinin yükselen, diğerinin düşen kenarda tetikleneceğini ve güncellemenin daha sık alınarak devrenin hızlanacağını söyler.

> **Ders sonrası not:** Master-slave yapısının amacı büyük olasılıkla hızlanma değildir. Saatin bir düzeyinde ana (master) eleman girişi alır, diğer düzeyinde yardımcı (slave) eleman bunu çıkışa aktarır. Böylece çıkış saat periyodu başına yalnız bir kez değişir; düzey tetiklemeli tutucunun saydamlığından doğan, çıkışın aynı saat düzeyi içinde birden fazla kez değişmesi sorunu önlenir.

## 8. Ardışıl devre analizi

Ardışıl devrelerle ilgili sorular iki tiptir: **devre analizi** ve **devre sentezi**. Analiz sorusunda bir devre verilir ve "bu devre ne iş yapar" ya da "çalışma prensibini açıklayın" diye sorulur. Sorunun asıl istediği, devrenin durumlar arasında nasıl bir graf (durum diyagramı) çizdiğidir.

Slayttaki adımlar (ekrandan, 00:35:00):

| Adım | Yapılması gerekenler |
|---|---|
| 1 | Flip-flop (ya da durum saklama birimi) girişlerine ve devre çıkışlarına ilişkin Boole fonksiyonları devreye bakılarak yazılır. |
| 2 | Flip-flopların geçiş fonksiyonları kullanılarak sonraki durum fonksiyonları elde edilir. |
| 3 | Durum tablosu oluşturulur. |
| 4 | Durum diyagramı çizilir. |

### 8.1 Durumlar ve flip-flop sayısı

Hoca "durum" kavramını önceki derste çözülen 1010 şifre (kilit) örneğiyle hatırlatır: girilen her doğru hane bir durumdur. Birinci hanede 1 gelince ikinci haneye, sonra 0 gelince üçüncü haneye, sonra 1 gelince dördüncü haneye geçilir; son 0 gelince dizi tamamlanır ve LED yanar. Burada dört durum vardır ve bunlar iki bitle gösterilebilir: $00$ (0. durum), $01$ (1. durum), $10$ (2. durum), $11$ (3. durum).

Her flip-flop durum kodunun bir bitini tutar. Bu yüzden durum kodunun bit genişliği flip-flop sayısına eşittir. $n$ flip-flop ile en çok $2^n$ durum gösterilebilir:

- 4 durum için $2^2 = 4$, yani 2 flip-flop gerekir.
- 0'dan 7'ye sayan bir sayıcının 8 durumu için $2^3 = 8$, yani 3 flip-flop gerekir; durumlar $000$'dan $111$'e kadar kodlanır.

Tersten bakılırsa, devrede kaç flip-flop varsa onların oluşturduğu ikili sayının alabileceği değer sayısı en çok kaç durum olabileceğini verir.

## 9. Analiz örnekleri

### 9.1 Örnek 1: iki D flip-floplu, girişli devre

Devrede $x$ girişi, iki D flip-flop ($A$ ve $B$), ortak saat $CP$ ve $y$ çıkışı vardır (ekrandan, 00:40:00). Hoca flip-flopları "flip-flop A" ve "flip-flop B" diye adlandırır; $A$ ve $B$ çıkışları birlikte devrenin durumunu gösterir. İki flip-flop olduğu için en çok 4 durum vardır.

**Adım 1 ve 2.** D flip-flopta $Q(t+1) = D$ olduğundan, $D$ girişindeki Boole ifadesi doğrudan sonraki durumdur. Hoca, flip-flop D tipi olmasaydı bunu böyle doğrudan yazamayacağımızı vurgular. Devreden (ekrandan, 00:45:00):

$$A(t+1) = A(t)\,x(t) + B(t)\,x(t)$$
$$B(t+1) = \bar A(t)\,x(t)$$
$$y(t) = \bar x(t)\,\big(B(t) + A(t)\big)$$

**Adım 3.** Durum tablosu, bu denklemlere her durum ve giriş birleşimi konarak doldurulur. Hoca tabloyu iki şekilde kurabileceğimizi söyler: her durum-giriş birleşimi ayrı satırda, ya da sonraki durumları giriş değerine göre yan yana sütunlarda yazan iki boyutlu biçimde. İkinci biçim daha az satır tutar ve şimdiki durum satırları ile giriş sütunları Gray kodu sırasında yazıldığında Karnaugh diyagramıyla iyi eşleşir (ekrandan, 00:45:00):

| Şimdiki $A\,B$ | Sonraki $A\,B$ ($x=0$) | Sonraki $A\,B$ ($x=1$) | $y$ ($x=0$) | $y$ ($x=1$) |
|---|---|---|---|---|
| 0 0 | 0 0 | 0 1 | 0 | 0 |
| 0 1 | 0 0 | 1 1 | 1 | 0 |
| 1 0 | 0 0 | 1 0 | 1 | 0 |
| 1 1 | 0 0 | 1 0 | 1 | 0 |

Örneğin $00$ durumunda ve $x=0$ iken $A(t+1) = 0\cdot0 + 0\cdot0 = 0$, $B(t+1) = 1\cdot 0 = 0$, $y = 1\cdot(0+0) = 0$ olur.

**Adım 4.** Durum diyagramı tablodan okunur: $00$ durumundan $x=0$ gelince yine $00$'a gidilir ve çıkış 0'dır; $x=1$ gelince $01$'e gidilir ve çıkış 0'dır. Diğer durumlar da aynı şekilde çizilir.

Hoca bu noktada tablonun Mealy mi Moore mu gösterimi olduğunu sorar; cevap gelmez (bkz. Örnek Sorular).

> **Hocanın vurgusu:** Mealy-Moore ayrımı kesin soru olacak bir konudur; çalışılması gerekir.

### 9.2 Örnek 2: girişsiz üç D flip-floplu devre

Bu örnekte devrenin dışarıdan girişi yoktur. Elektrik verildiğinde devre bir durumdan başlar, durumlar arasında ilerler ve başa döner. Üç D flip-flop ($A$, $B$, $C$) ve bir $Z$ çıkışı vardır (bu anın karesi yok, ifadeler altyazıdan).

Altyazıya göre denklemler:

$$A(t+1) = B(t)\,C(t)$$
$$B(t+1) = \bar B(t)\,C(t) + B(t)\,\bar C(t) = B(t) \oplus C(t)$$
$$Z = B(t)\,C(t)$$

<!-- BELİRSİZ: C(t+1) denklemi altyazıda okunmuyor ve karesi yok. Hocanın anlattığı geçişler C(t+1) = A'C' ile tutarlıdır (python ile kontrol edildi), ama slayttaki ifade doğrulanamadı. -->

Hocanın okuduğu durum tablosuna göre geçişler ($ABC$ ondalık olarak):

| Şimdiki durum | Sonraki durum | $Z$ |
|---|---|---|
| 0 | 1 | 0 |
| 1 | 2 | 0 |
| 2 | 3 | 0 |
| 3 | 4 | 1 |
| 4 | 0 | 0 |
| 5 | 2 | 0 |
| 6 | 2 | 0 |
| 7 | 4 | 1 |

Durum diyagramında devre 0, 1, 2, 3, 4 durumları arasında döner; 5 ve 6 durumuna düşerse 2'ye, 7 durumuna düşerse 4'e geçerek çevrime katılır. 3 durumundan 4'e geçerken çıkış 1 olur.

### 9.3 Örnek 3: D flip-floplu devrede ayrı giriş sütunları

Bu örnekte denklemler hazır verilmiştir (ekrandan, 00:50:00):

$$D_0 = x \cdot z = x\cdot\overline{(Q_1 Q_0)}$$
$$D_1 = x + z = x + \overline{(Q_1 Q_0)}$$
$$z = \overline{(Q_1 Q_0)}$$

Hoca, D flip-flopta $Q(t+1) = D$ olduğu için şimdiye kadar flip-flop girişlerini ve sonraki durumları ayrı sütunlarda yazmadıklarını, ama bunu ayrı yazmanın daha iyi olacağını söyler. Çünkü JK, SR ve T flip-floplarda flip-flop girişi sonraki durumun kendisi değildir; sonraki durum girişlerden karakteristik tabloyla bulunur. Tablo simgesel durum adları ($d_0$–$d_3$), şimdiki durum $Q_1Q_0$, $x=0$ ve $x=1$ için flip-flop girişleri $D_1D_0$, sonraki durumlar ve çıkış $z$ sütunlarından oluşur. Slaytta doldurulmuş giriş sütunları (ekrandan, 00:50:00):

| Durum | $Q_1\,Q_0$ | $D_1D_0$ ($x=0$) | $D_1D_0$ ($x=1$) | Sonraki ($x=0$) | Sonraki ($x=1$) | $z$ |
|---|---|---|---|---|---|---|
| $d_0$ | 0 0 | 1 0 | 1 1 | $d_2$ | $d_3$ | 1 |
| $d_1$ | 0 1 | 1 0 | 1 1 | $d_2$ | $d_3$ | 1 |
| $d_2$ | 1 0 | 1 0 | 1 1 | $d_2$ | $d_3$ | 1 |
| $d_3$ | 1 1 | 0 0 | 1 0 | $d_0$ | $d_2$ | 0 |

Sonraki durum sütunları D tipinde flip-flop girişlerinin aynısıdır; hoca bunları anlatımda okur ($d_0$'dan $x=0$ iken $d_2$'ye, $x=1$ iken $d_3$'e; $x=0$ iken $d_1$ ve $d_2$ $d_2$'ye, $d_3$ $d_0$'a gider). $z$ sütunu slaytta boştur; değerler $z = \overline{Q_1Q_0}$ ifadesinden hesaplanmıştır (ara adım eklendi). Hoca, $00, 01$ gibi kodlar yerine $d_0, d_1, d_2, d_3$ adlarıyla küçük bir özet tablo yapmanın da faydalı olduğunu söyler.

Hoca ayrıca JK flip-flop kullanılsaydı giriş sütunlarının $J_1, K_1, J_0, K_0$ olacağını ve sonraki durumun bu girişlerden bulunacağını gösterir: örneğin bir flip-flopa $11$ geliyorsa o flip-flopun şimdiki değerinin tümleyeni sonraki duruma yazılır.

### 9.4 Örnek 4: JK flip-floplu devre (sınıf alıştırması)

Devrede $x$ girişi, iki JK flip-flop ($FF_0$, $FF_1$), ortak saat ve $z$ çıkışı vardır; flip-flopların sıfırlama girişleri de çizilmiştir (ekrandan, 00:55:00). Hoca, şekilde $FF_1$'in yanında görünen "K" etiketinin saat girişini değil aşağıdaki $K_1$ girişini gösterdiğini, saat girişinin ortak saat hattına bağlı olduğunu açıklar (ekrandan, 01:00:00). Devrenin denklemleri slaytta verilmiştir:

$$J_0 = \bar x + \bar Q_1, \qquad K_0 = Q_1$$
$$J_1 = Q_0, \qquad K_1 = \bar x\,\bar Q_0$$
$$z = Q_0\,\bar Q_1$$

Hoca tahtaya şimdiki durum ($Q_1Q_0$), $x=0$ ve $x=1$ için flip-flop girişleri ($J_1K_1$, $J_0K_0$), sonraki durum ve çıkış $z$ sütunlarından oluşan boş bir tablo çizer ve öğrencilerden bunu doldurmalarını ister. Sonra çözümü slayttan gösterir (ekrandan, 01:15:00):

| Durum | $Q_1\,Q_0$ | $J_1K_1$ ($x=0$) | $J_0K_0$ ($x=0$) | $J_1K_1$ ($x=1$) | $J_0K_0$ ($x=1$) | $Q_1Q_0$ sonraki ($x=0$) | $Q_1Q_0$ sonraki ($x=1$) | $z$ |
|---|---|---|---|---|---|---|---|---|
| $d_0$ | 0 0 | 0 1 | 1 0 | 0 0 | 1 0 | 0 1 | 0 1 | 0 |
| $d_1$ | 0 1 | 1 0 | 1 0 | 1 0 | 1 0 | 1 1 | 1 1 | 1 |
| $d_2$ | 1 0 | 0 1 | 1 1 | 0 0 | 0 1 | 0 1 | 1 0 | 0 |
| $d_3$ | 1 1 | 1 0 | 1 1 | 1 0 | 0 1 | 1 0 | 1 0 | 0 |

Hoca ilk satırları şöyle açıklar: $FF_1$ için $Q_1(t)=0$ iken $J_1K_1 = 01$ gelirse sıfırlama yapılır ve $Q_1(t+1) = 0$ olur. $10$ gelirse kurulur ve 1 olur. $00$ gelirse önceki değer hatırlanır. $11$ gelirse tümlenir. Örneğin $d_2$ ($Q_1=1$) için $x=0$ iken $J_1K_1=01$ olduğundan $Q_1$ 0'a iner; $J_0K_0=11$ olduğundan $Q_0$ 0'dan 1'e tümlenir; sonraki durum $01$, yani $d_1$ olur.

Tablo daha sonra simgesel durumlarla özetlenir:

| Şimdiki | Sonraki ($x=0$) | Sonraki ($x=1$) | $z$ |
|---|---|---|---|
| $d_0$ | $d_1$ | $d_1$ | 0 |
| $d_1$ | $d_3$ | $d_3$ | 1 |
| $d_2$ | $d_1$ | $d_2$ | 0 |
| $d_3$ | $d_2$ | $d_2$ | 0 |

Slayttaki durum diyagramında ($x$ / $z$ etiketleriyle) $d_0 \to d_1$ (her iki girişte), $d_1 \to d_3$ (her iki girişte), $d_3 \to d_2$ (her iki girişte), $d_2 \to d_1$ ($x=0$) ve $d_2 \to d_2$ ($x=1$) geçişleri gösterilir (ekrandan, 01:15:00). Bu tablo, Python ile JK karakteristik denklemi kullanılarak kontrol edildi ve slaytla aynı çıktı.

## 10. Ardışıl devre sentezi

Sentezde iş tersine döner: sözel olarak tanımlanan bir davranıştan devre kurulur. Hoca bunun dört aşamada yapıldığını söyler:

1. Sözel tanım dikkatle okunur ve devrenin ne yapacağı netleştirilir; buradan durum diyagramı çıkarılır.
2. Durum diyagramından durum tablosu kurulur. Durum sayısından kaç flip-flop gerektiği bulunur.
3. Flip-flopun karakteristik (uyarma) tablosuna göre her flip-flop girişi için Karnaugh diyagramı yapılır ve sadeleştirilir.
4. Elde edilen Boole ifadeleriyle devre kurulur.

### 10.1 Örnek: 1010 dizisi tanıyıcı

Soru: Girişi $x$, çıkışı $z$ olan bir ardışıl devrenin girişine 1010 bit dizisi geldiğinde çıkış lojik 1, aksi durumda lojik 0 olsun. Devreyi tasarlayınız.

<!-- BELİRSİZ: Altyazıda soru metni "1.0.1 bit dizisi" ve "T tipi flip-floplar kullanarak" diye okunuyor. Hocanın anlatımı (dört hane, 1-0-1-0) ve slayttaki tablo 1010 dizisini ve D flip-flopları gösteriyor; hoca da çözümde "D tipi dediği için" diyor. -->

**Durum diyagramı.** Girişler okların üzerine, çıkışlar da yanlarına yazılır; bu bir Mealy gösterimidir. Dört hane olduğu için dört durum tasarlanır: $d_0$, $d_1$, $d_2$, $d_3$. Doğru hane geldikçe sonraki duruma geçilir. Hoca diğer durumların da düşünülmesi gerektiğini vurgular:

- $d_0$'da 0 gelirse devre kendi üzerinde kalır, çünkü ilk beklenen hane 1'dir.
- $d_1$'de tekrar 1 gelirse yine $d_1$'de kalınır; örneğin "1 1 0 1 0" geldiğinde son dört hanenin tanınabilmesi için ilk 1 yeniden kontrol edilmemelidir.
- $d_2$'de 1 beklenir; 0 gelirse başa ($d_0$) dönülür.
- $d_3$'te 0 gelirse dizi tamamlanır, $z=1$ olur ve $d_0$'a dönülür. 1 gelirse $d_1$'e geçilir.

Slayttaki durum tablosu (ekrandan, 01:20:00):

| Şimdiki | Sonraki ($x=0$) | Sonraki ($x=1$) | $z$ ($x=0$) | $z$ ($x=1$) |
|---|---|---|---|---|
| $d_0$ | $d_0$ | $d_1$ | 0 | 0 |
| $d_1$ | $d_2$ | $d_1$ | 0 | 0 |
| $d_2$ | $d_0$ | $d_3$ | 0 | 0 |
| $d_3$ | $d_0$ | $d_1$ | 1 | 0 |

**Flip-flop sayısı.** Dört durum $2^2$ olduğu için iki flip-flop ($Q_1$, $Q_0$) yeterlidir. D flip-flop kullanıldığı için flip-flop girişleri sonraki durumun aynısıdır. Slayttaki ayrıntılı tablo (ekrandan, 01:20:00):

| Durum | $Q_1\,Q_0$ | $x$ | $Q_1^+\,Q_0^+$ | $D_1$ | $D_0$ | $z$ |
|---|---|---|---|---|---|---|
| $d_0$ | 0 0 | 0 | 0 0 | 0 | 0 | 0 |
| $d_0$ | 0 0 | 1 | 0 1 | 0 | 1 | 0 |
| $d_1$ | 0 1 | 0 | 1 0 | 1 | 0 | 0 |
| $d_1$ | 0 1 | 1 | 0 1 | 0 | 1 | 0 |
| $d_2$ | 1 0 | 0 | 0 0 | 0 | 0 | 0 |
| $d_2$ | 1 0 | 1 | 1 1 | 1 | 1 | 0 |
| $d_3$ | 1 1 | 0 | 0 0 | 0 | 0 | 1 |
| $d_3$ | 1 1 | 1 | 0 1 | 0 | 1 | 0 |

Slaytta ayrıca D flip-flopun uyarma tablosu $Q\,Q^+$ sırasına göre gösterilir: $00 \to D=0$, $01 \to 1$, $11 \to 1$, $10 \to 0$ (ekrandan, 01:20:00).

**Karnaugh ve devre.** $D_1$ ve $D_0$ için $x$, $Q_1$, $Q_0$ değişkenlerine göre ayrı ayrı Karnaugh diyagramı yapılır. Hoca, slayttaki Karnaugh diyagramında değişken adı olarak yanlışlıkla D yazıldığını, onun $x$ olması gerektiğini söyler. Karnaugh sonucunda sadeleşmiş Boole ifadeleri elde edilir; bunlar iki flip-flopun $D_1$ ve $D_0$ girişlerine, $z$ ifadesi de ayrıca çıkışa kurulur. Böylece analizde verilen türden bir devre tersinden, sentezle elde edilmiş olur. Sadeleşmiş ifadeler kayıtta okunamadı; çözüm Örnek Sorular bölümündedir.

> **Hocanın vurgusu:** D tipinde uyarma tablosu basittir; JK ile tasarımda iş zorlaşır. JK ile sentez derste örneklenmedi; bunun mutlaka çalışılması gerekir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:45:12): Örnek 1'in durum tablosu (Bölüm 9.1) Mealy gösterimi mi, Moore gösterimi mi?

> **Çözüm (derste verilmedi):** Mealy. Çıkış $y = \bar x (A + B)$ hem duruma hem de $x$ girişine bağlıdır; tabloda da aynı durum için çıkış $x=0$ ve $x=1$ sütunlarında farklıdır (örneğin $01$ durumunda $y$, $x=0$ iken 1, $x=1$ iken 0). Moore makinesinde çıkış yalnız duruma bağlı olurdu.

**Soru 2** (ekrandan, 00:55:00 ve 01:15:00): Bölüm 9.4'teki JK flip-floplu devre için $J_0 = \bar x + \bar Q_1$, $K_0 = Q_1$, $J_1 = Q_0$, $K_1 = \bar x \bar Q_0$, $z = Q_0 \bar Q_1$ olduğuna göre şimdiki durum, flip-flop girişleri ($x=0$ ve $x=1$ için), sonraki durum ve çıkış sütunlarından oluşan durum tablosunu doldurunuz ve durum diyagramını çiziniz.

> **Çözüm:** Derste slayttan gösterildi; tablo ve özet tablo Bölüm 9.4'tedir. Örneğin $d_3$ ($Q_1Q_0=11$) ve $x=1$ için $J_1K_1 = 10$ olduğundan $Q_1$ 1 kalır, $J_0K_0 = 01$ olduğundan $Q_0$ 0'a sıfırlanır; sonraki durum $10 = d_2$, çıkış $z = 1\cdot 0 = 0$.

**Soru 3** (ekrandan, 00:50:00): Bölüm 9.3'teki $D_0 = x\,\overline{Q_1Q_0}$, $D_1 = x + \overline{Q_1Q_0}$, $z = \overline{Q_1Q_0}$ denklemli devrenin durum tablosunu doldurunuz.

> **Çözüm:** Flip-flop girişleri derste slaytta dolduruldu, sonraki durumlar sözlü okundu; tablo Bölüm 9.3'tedir. $d_3$ dışındaki durumlar $x=0$ iken $d_2$'ye, $x=1$ iken $d_3$'e gider; $d_3$ $x=0$ iken $d_0$'a, $x=1$ iken $d_2$'ye gider.

**Soru 4** (ekrandan, 01:20:00): Girişi $x$, çıkışı $z$ olan bir ardışıl devrenin girişine 1010 bit dizisi geldiğinde çıkışı lojik 1, aksi durumda lojik 0 yapan ardışıl devreyi tasarlayınız. <!-- BELİRSİZ: flip-flop türü altyazıda "T tipi", slaytta D tipi; çözüm slayttaki D tipine göredir. -->

> **Çözüm (derste verilmedi):** Durum tablosu ve $D_1$, $D_0$ sütunları derste verildi (Bölüm 10.1). Sadeleştirme kayıtta görünmediği için Karnaugh sonucu burada çıkarıldı ve Python ile tüm satırlarda kontrol edildi. $D_1 = 1$ olan satırlar $Q_1Q_0x = 010$ ve $101$'dir; bunlar Karnaugh'ta komşu değildir:
> $$D_1 = \bar Q_1 Q_0 \bar x + Q_1 \bar Q_0 x$$
> $D_0$ sütunu her satırda $x$'e eşittir:
> $$D_0 = x$$
> Çıkış yalnız $d_3$'te $x=0$ iken 1'dir:
> $$z = Q_1 Q_0 \bar x$$
> Bu tasarımda $d_3$'te 0 gelince $d_0$'a dönüldüğü için örtüşen diziler sayılmaz: $x = 1,0,1,0,1,0$ için $z$ yalnız dördüncü bitte 1 olur (Python ile kontrol edildi).

## Dersin Toparlaması

Bu derste ardışıl devrelerin depolama elemanları temelden ele alındı. NAND ve NOR kapılarıyla kurulan temel S-R tutuculardan, önüne saatli kapılar eklenerek senkron çalışan S-R flip-flopa geçildi; buradan D, JK ve T flip-floplar türetildi. Her flip-flop için karakteristik tablo, karakteristik denklem ve uyarma tablosu çıkarıldı; uyarma tablosunun, istenen bir durum geçişi için flip-flop girişlerinin ne olması gerektiğini verdiği ve tasarımda Karnaugh diyagramlarının kaynağı olduğu vurgulandı. Zamanlama diyagramlarıyla kenar tetiklemenin etkisi gösterildi.

Dersin ikinci yarısında ardışıl devre soruları analiz ve sentez olarak ikiye ayrıldı. Analizde devreden Boole ifadeleri, sonraki durum denklemleri, durum tablosu ve durum diyagramı sırasıyla elde edildi; D ve JK flip-floplu örnekler çözüldü. Sentezde ise 1010 dizisini tanıyan devre, sözel tanımdan durum diyagramına, durum tablosuna ve D flip-flop girişlerine kadar kuruldu. Hoca, JK flip-floplarla sentezin derste örneklenmediğini ve ayrıca çalışılması gerektiğini, bir sonraki derste başka bir konuya geçileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
