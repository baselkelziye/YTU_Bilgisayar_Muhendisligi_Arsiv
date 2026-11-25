# Ders 3 Genişletilmiş Notu: Flip-Flop Tekrarı, Ardışıl Devre Tasarımı, Sayıcılar, Yazmaçlar ve Programlanabilir Lojik

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hafıza Elemanları: Latch ve Flip-Flop
- 2. Saatli SR Latch ve D Latch'in İç Yapısı
- 3. Flip-Flop Tanım Tabloları
- 4. Senkron Ardışıl Devre Tasarımının Adımları
- 5. Mealy ve Moore Makineleri
- 6. Ters Dönüşüm Tabloları
- 7. Örnek: İki Durumlu Mealy Makinesinin T, D ve JK ile Gerçeklenmesi
- 8. 3 Bitlik Senkron Yukarı Sayıcı
- 9. Asenkron (Ripple) Sayıcılar
- 10. Yazmaçlar
- 11. Yükleme Uçlu Senkron Sayıcı
- 12. Programlanabilir Lojik Cihazlar
- 13. ROM
- 14. PLA
- 15. PAL
- 16. Örnek Sorular

## 1. Hafıza Elemanları: Latch ve Flip-Flop

Bazı lojik tasarımlarda önceki durumların hafızada tutulması gerekir; devre bir önceki adımda ne olduğuna göre davranır. Tek bir durum bilgisi tutulacaksa tek hafıza elemanı yeter. Örneğin 8 farklı durum tutulacaksa bunlar 3 bitle kodlanabilir, dolayısıyla 3 hafıza elemanı yeterlidir. Slaytta ardışıl lojik şöyle özetlendi: çıkış hem şimdiki hem geçmiş girişlere bağlıdır, devre "hafıza" özelliğine sahiptir; ardışıl devre bir kombinasyonel devre ile bir geri besleme devresinden oluşur ve geçmiş girişler bir durum değişkenleri kümesine kodlanır (ekrandan, 00:05:00).

Hafıza elemanlarında iki temel yapı vardır: latch ve flip-flop.

### 1.1 Latch: seviye tetikleme

Hoca latch'i bir kara kutu olarak çizdi: bir giriş ucu, bir enable ucu ve bir çıkış. Enable lojik 1'de kaldığı sürece girişte ne kadar ve ne yönde değişiklik olursa olsun aynısı çıkışta görülür. Enable 0'a düştükten sonra girişte ne yapılırsa yapılsın son değer çıkışta kalır. Bu davranışa seviye tetikleme denir. Enable 1 iken giriş çıkışa doğrudan yansıdığı için bu tür latch'lere "transparent latch" de denir.

### 1.2 Flip-flop: kenar tetikleme

Flip-flop'ta enable yerine saat (CLK) işareti vardır. Sembolde saat girişindeki üçgen yükselen kenarda tetiklemeyi, üçgenin önüne konan yuvarlak ise düşen kenarda tetiklemeyi gösterir (yuvarlak her zaman "aktif sıfır" anlamında kullanılır). Saat 0'da beklerken de, 1'de beklerken de çıkış değişmez. Değişim yalnız tetikleyen kenarda olur: o anda girişte hangi değer varsa çıkışta o değer oluşur ve bir sonraki tetikleyen kenara kadar sabit kalır.

Flip-flop'un avantajı, çıkıştaki durum değişimini sonsuz küçük bir kenar anına sıkıştırmasıdır. Çalışma mantığı şudur: istenen giriş değerleri hazırlanır, sonra saatin yükselen kenarı "vurulur".

### 1.3 Geri besleme

Kombinasyonel devrede bir kapının çıkışı başka bir kapıya giriş olabilir ama hiçbir zaman bir kapının ya da kapı grubunun çıkışı kendi girişine geri beslenmez. Hafıza elemanlarının içinde ise geri besleme vardır. Geri beslemeli yapılarda kararsız durumlar oluşabilir (çıkış sürekli 0-1 arasında değişir, birbirini kovalar). Ama kararlı durumlar da vardır: bir değer oluştuktan sonra denetim uçlarındaki işaretler değişse bile sabit kalabilir. Hafıza bu kararlı durumlardan yararlanır.

## 2. Saatli SR Latch ve D Latch'in İç Yapısı

Slayttaki saatli SR latch iki kısımdan oluşur (ekrandan, 00:10:00): çapraz bağlı iki NOR kapısından oluşan geri besleme kısmı ve önlerindeki iki AND kapısından oluşan denetim kısmı. AND kapıları $R' = R \cdot Clk$ ve $S' = S \cdot Clk$ üretir. Hoca burada $R'$ ve $S'$'nün tümleyen değil, yalnızca farklı bir isimlendirme olduğunu açıkladı.

### 2.1 Geri besleme kısmı

NOR kapısında girişlerden biri 1 ise çıkış, diğer girişe bakmadan 0 olur. Hoca kararlı durumları şöyle izledi:

- $R'=1$, $S'=0$ ise üstteki NOR'un çıkışı $Q=0$ olur. Alttaki NOR'un iki girişi de 0 olduğundan $\bar{Q}=1$ olur; bu 1 üstteki NOR'a geri döner ve $Q=0$'ı destekler. Kararlı bir sıfırlama durumu oluşur.
- Bu durumda $R'$ 0'a çekilirse üstteki NOR'a alttan 1 geri beslendiği için $Q$ yine 0 kalır. Yani $R'S'$: $10 \to 00$ geçişinde durum değişmez.
- Simetrik olarak $R'S' = 01$ iken $Q=1$ kararlı olur ve $00$'a geçişte $Q=1$ korunur.

Buradan $R'S' = 00$'ın "önceki durum korunur" anlamına geldiği çıkar. $R'S' = 11$ olduğunda ise iki NOR'un da bir girişi 1 olduğu için iki çıkış da 0 olur. Bütün flip-flop'larda $Q$ ile $\bar{Q}$'nun birbirinin tümleyeni olması beklenir; bu şart sağlanmadığı için $11$ girişi izin verilmeyen durumdur.

### 2.2 Denetim kısmı

Saat 1 iken $R' = R$ ve $S' = S$ olur. Saat 0'a düşünce iki AND kapısı da 0 verir; $R'S' = 00$ durum değişimi olmayan senaryodur. Yani AND katmanı latch'in enable'ını kapatır; geri besleme yapısına seviye tetikleme denetimi bu katmanla eklenir.

Saatli SR latch karakteristik tablosu (ekrandan, 00:10:00):

```text
Clk S R | Q(t+1)
 0  x x | Q(t)  (değişim yok)
 1  0 0 | Q(t)  (değişim yok)
 1  0 1 | 0
 1  1 0 | 1
 1  1 1 | x     (izin verilmez)
```

### 2.3 D latch

D latch'te $D$ girişi doğrudan $S$'ye, $D$'nin tümleyeni (bir NOT kapısıyla) $R$'ye bağlanır (ekrandan, 00:10:00). Böylece SR tablosunun yalnız $S$ ile $R$'nin birbirinin tümleyeni olduğu iki satırı kalır ve izin verilmeyen durum hiç oluşmaz. Karakteristik tablo: $Clk=0$ iken $Q(t)$; $Clk=1$, $D=0$ iken 0; $Clk=1$, $D=1$ iken 1.

D latch'te enable 1 iken $D$'deki her değişiklik (biraz yayılma gecikmesiyle) çıkışa geçer. D flip-flop ise yalnız saatin yükselen kenarında $D$'yi örnekler ve bir sonraki yükselen kenara kadar bu değeri tutar. Slayttaki zamanlama diyagramında $t_1$, $t_2$, $t_3$, $t_4$ yükselen kenarlarında $Q$'nun o anki $D$ değerini aldığı görülür (ekrandan, 00:10:00).

### 2.4 Asenkron ve senkron preset/clear

Preset ve reset (clear) uçları asenkron çalışır: saatin yükselen kenarını beklemeden $Q$'yu 1 ya da 0 yapar. Bunun yanında senkron clear ya da preset de kurulabilir: clear denetimi $D$ ucuna bağlanırsa $D$ ancak yükselen kenarda çıkışa aktarıldığı için temizleme işlemi saat kenarında, yani senkron olarak gerçekleşir.

Senkron ardışıl devre tasarımında sistemdeki bütün hafıza elemanları aynı saat işaretiyle çalışmalıdır. Farklı saat kaynakları kullanılan yapılara asenkron ardışıl devre denir.

### 2.5 Neden latch değil flip-flop?

Seviye tetiklemede devrelerin geçtiği kapı sayısı kadar, her alt modülün gecikmesi farklıdır. Ardışıl devrede hafıza elemanı olarak latch kullanılırsa enable açık kaldığı süre boyunca yanlış ara çıkışlar oluşur; geri besleme olduğu için bu çıkışlar başka girişleri etkiler ve istenmeyen sonuçlar doğar. Flip-flop'ta ise saat kenarı gelmeden önce bütün girişler hazırdır; kenar anında etki çıkışlara aktarılır, değişen çıkışlar girişlere geri dönene kadar kenar geçmiş olduğu için devrede bozucu bir etki oluşmaz.

> **Hocanın vurguları:** Ardışıl devre tasarımında latch'ten ziyade flip-flop kullanılmasının nedeni bu gecikme farklarıdır.

## 3. Flip-Flop Tanım Tabloları

Hoca tablolarda şu gösterimi kullandı: küçük $q$ mevcut (önceki) durumu, büyük $Q$ saat kenarından sonraki durumu gösterir. Bütün flip-flop'lar yükselen kenarda tetiklenir; kenar dışındaki her durumda önceki durum korunur (ekrandan, 00:30:00).

```text
SR flip-flop        JK flip-flop       D flip-flop     T flip-flop
S R | Q             J K | Q            D | Q           T | Q
0 0 | q             0 0 | q            0 | 0           0 | q
0 1 | 0             0 1 | 0            1 | 1           1 | q'
1 0 | 1             1 0 | 1
1 1 | x (yasak)     1 1 | q'
diğer | q
```

- SR: $00$ durumu korur, $01$ sıfırlar, $10$ birler, $11$ izin verilmez.
- JK: SR gibi çalışır; fark olarak $11$ girişinde önceki durumun tümleyenini çıkışta oluşturur.
- D: iç yapısı D latch'teki gibidir ($S=D$, $R=\bar{D}$); $D$'deki değer çıkışa aktarılır. Sıfırlama ve birleme yeteneği vardır.
- T: tek girişlidir; $T=0$ iken durum korunur, $T=1$ iken her tetikleyen kenarda tümlenir (toggle).

## 4. Senkron Ardışıl Devre Tasarımının Adımları

Bir ardışıl devre tasarım problemi genelde sözel olarak verilir. Adımlar şunlardır:

- Senaryodan kaç durum olduğu ve dolayısıyla kaç hafıza elemanı gerektiği belirlenir.
- Durum diyagramı çizilir; girişlere ve çıkışlara göre geçişler tanımlanır.
- Durum diyagramı bir doğruluk tablosuna geçirilir.
- Bilinmeyen tek şey kalır: kullanılacak $n$ hafıza elemanının giriş uçlarına ne bağlanacağı. Çıkış fonksiyonu da bilinmiyorsa o da tasarlanır.

Hafıza elemanlarının girişlerine bağlanacak fonksiyonlar ve çıkış fonksiyonları, giriş değerlerine ve bütün hafıza elemanlarının önceki durumlarına (küçük $q$'lara) bağlı olabilir. Bu yüzden doğruluk tablosunda girdiler önceki durumlar ve girişlerdir; çıktılar flip-flop uçlarına bağlanacak fonksiyonlar ve devre çıkışlarıdır.

Hoca $q$ ile $Q$ arasındaki farkı tasarım anı üzerinden açıkladı: devre kurulduğunda üzerinde uzun süredir bulunan değerler küçük $q$'lardır. Büyük $Q$, saat işareti geldikten sonra flip-flop çıkışında oluşacak ama henüz oluşmamış değerdir.

## 5. Mealy ve Moore Makineleri

### 5.1 Mealy makinesi

Örnek bir durum diyagramında iki durum vardır: A ve B (ekrandan, 00:35:00 ve 00:40:00). A'da 0 gelince kendi üzerine döner, 1 gelince B'ye geçer; B'de 0 gelince kendi üzerine döner, 1 gelince A'ya geçer. Geçiş oklarının üstüne "giriş/çıkış" yazılır: $0/0$, $1/1$, $0/1$, $1/0$.

Bu gösterimde çıkış hem bulunulan duruma hem de o andaki girişe bağlıdır. Örneğin A durumunda beklerken giriş 0 ise çıkış 0'dır; giriş 1'e değişince, henüz saat kenarı gelip durum değişmeden çıkış 1 olabilir. Yani $Z = f(q_i, x)$. Bu tür durum makinelerine **Mealy makinesi** denir. Mealy makinesinde çıkış değişimleri yalnız durum değişimiyle ilişkili değildir; bir durumda beklerken girişteki değişiklik çıkışı değiştirebilir. Bu yüzden bir sonraki saat kenarına kadar arada hatalı ya da istenmeyen çıkışlar görülebilir.

### 5.2 Moore makinesi

Aynı geçiş yapısı çıkışlar yalnız duruma bağlı olacak şekilde de çizilebilir: A'da beklerken giriş 0'dan 1'e çekilse bile çıkış değişmez. Bu durumda çıkış değeri okların üstüne değil, durumun içine (dairenin alt yarısına) yazılır (ekrandan, 00:35:00). Çıkış yalnız durum değişkenlerine, yani küçük $q$'lara bağlıdır: $Z = f(q_i)$. Bu yapılara **Moore makinesi** denir.

### 5.3 Durum kodlama

İki durum olduğu için tek hafıza elemanı yeter. A ve B'ye 0-1 ya da 1-0 kodu verilebilir. Hangi kodlamanın seçildiğine göre durum geçiş fonksiyonları ve dolayısıyla devre değişebilir; ardışıl devre tasarımında farklı durum kodlarının devreye etkisi bu yüzden önemlidir.

### 5.4 Mealy'den Moore'a

Prensip olarak Mealy mantığıyla kurulan herhangi bir akış Moore mantığıyla da kurulabilir. Ama büyük ihtimalle daha fazla durum gerekir: Mealy makinesinde örneğin 0 durumundayken 0 geldiğinde ve 1 geldiğinde farklı çıkış veriliyorsa Moore'da bunlar ayrı durumlar olarak tanımlanmalıdır.

## 6. Ters Dönüşüm Tabloları

Tasarımda $q \to Q$ geçişi durum diyagramından bellidir; aranan, bu geçişi sağlamak için flip-flop girişine ne verilmesi gerektiğidir. Bunu veren tabloya **ters dönüşüm tablosu** denir (ekrandan, 00:50:00 ve 00:55:00).

### 6.1 D flip-flop

D'de ne varsa kenardan sonra Q'da o oluşur. Dolayısıyla $Q$'da ne oluşması isteniyorsa $D$'ye o verilir: $00 \to 0$, $01 \to 1$, $10 \to 0$, $11 \to 1$. Derste hoca soruyu öğrencilere sordu ve cevaplar bu şekilde geldi.

### 6.2 T flip-flop

$0 \to 0$ geçişi: $q$ değişmeden kalmalı, bu $T=0$ ile olur. $0 \to 1$ ve $1 \to 0$ geçişleri tümleme ister, bu ancak $T=1$ ile olur. $1 \to 1$ geçişinde durum değişmez, $T=0$ gerekir. Kısaca: durum değişiyorsa $T=1$, değişmiyorsa $T=0$.

### 6.3 JK flip-flop

- $0 \to 0$: ya durum korunur ($JK=00$) ya da sıfırlanır ($JK=01$). İki satırda da $J=0$; $K$ don't care. Sonuç $0x$.
- $0 \to 1$: ya tümlenir ($JK=11$) ya da birlenir ($JK=10$). İki satırda da $J=1$; sonuç $1x$.
- $1 \to 0$: ya tümlenir ($11$) ya da sıfırlanır ($01$). $K=1$ şart, $J$ don't care; sonuç $x1$.
- $1 \to 1$: ya korunur ($00$) ya da birlenir ($10$). $K=0$, $J$ don't care; sonuç $x0$.

## 7. Örnek: İki Durumlu Mealy Makinesinin T, D ve JK ile Gerçeklenmesi

Bölüm 5.1'deki Mealy diyagramı aynı devrenin üç farklı tasarımı olarak T, D ve JK flip-flop'larla gerçeklendi (ekrandan, 00:40:00). A'ya 0, B'ye 1 kodu verildi. Bulunması gerekenler (ekrandan, 00:50:00):

- T ile: $T = f_1(q, x)$ ve $Z = g_1(q, x)$.
- D ile: $D = f_2(q, x)$ ve $Z = g_2(q, x)$.
- JK ile: $J = f_3(q, x)$, $K = g_3(q, x)$ ve $Z = h_3(q, x)$.

### 7.1 Doğruluk tablosu

Önce her $x$ ve $q$ için sonraki durum yazılır: 0 durumunda 0 gelirse 0'da kalınır; 1 durumunda 0 gelirse 1'de kalınır; 0 durumunda 1 gelirse 1'e geçilir; 1 durumunda 1 gelirse 0'a geçilir. Sonra flip-flop sütunları ters dönüşüm tablolarından, $Z$ sütunu ise durum diyagramından doldurulur (ekrandan, 00:55:00):

```text
x q | Q | T | D | J K | Z
0 0 | 0 | 0 | 0 | 0 x | 0
0 1 | 1 | 0 | 1 | x 0 | 1
1 0 | 1 | 1 | 1 | 1 x | 1
1 1 | 0 | 1 | 0 | x 1 | 0
```

> **Hocanın vurgusu:** $Z$ sütunu durum diyagramındaki çıkışlara göre doldurulur, bunu karıştırmamak önemlidir.

T sütunu doldurulurken hoca önce bir satıra yanlış değer yazdı; bir öğrenci uyardı ve tablo "durum değişimi varsa 1, yoksa 0" kuralına göre düzeltildi.

### 7.2 Fonksiyonlar

İki değişken olduğu için Karnaugh haritasına gerek kalmadı. Değişken sayısı ikiden fazla olsaydı Karnaugh haritasıyla bakmak daha pratik olurdu.

- $Z$: girişler farklıyken 1, aynıyken 0 olduğu için $Z = x \oplus q$. Bunu derste bir öğrenci söyledi.
- $T$: sütun $x$ ile aynıdır, $T = x$.
- $D$: yine XOR çıkar, $D = x \oplus q$.
- $J$: don't care'ler 1 kabul edilirse $J = x$ olur.
- $K$: benzer şekilde don't care'ler uygun seçilince $K = x$ olur.

Python ile tablo üzerinden dört fonksiyonun da her satırı sağladığı kontrol edildi.

### 7.3 Devreler

Gerçeklemeler (ekrandan, 01:00:00):

- D ile: $x$ ile flip-flop çıkışı $q$ bir XOR'a girer. XOR çıkışı hem $Z$ çıkışıdır hem de bir sonraki durumu belirlediği için $D$ girişine bağlanır. Hoca $\bar{Q}$ çıkışı kullanılırsa XNOR gerekeceğini, bunun da aynı karmaşıklıkta olduğunu söyledi.
- T ile: $T$ ucuna doğrudan $x$ bağlanır; $Z$ yine $x \oplus q$ veren bir XOR'dan alınır.
- JK ile: $J$ ve $K$ uçlarının ikisine de $x$ bağlanır; $Z$ aynı XOR'dan alınır.

Bu tasarım senkron ardışıl devredir. Daha fazla durum gerektiren bir problemde, örneğin ikinci bir JK flip-flop eklenseydi, iki flip-flop'un saatleri ortaklanıp ortak bir saat işaretiyle beslenmeliydi; çünkü durum tablosundaki geçişler aynı anda olacak şekilde tanımlanmıştır.

> **Hocanın vurgusu:** Senkron ardışıl devre tasarımının en önemli özelliği saat işaretlerinin ortak kaynaklı olmasıdır.

### 7.4 Aynı devrenin Moore versiyonu

Durum geçişleri aynı kalır, yalnız $Z$ fonksiyonu $q$'ya bağlı olur. A'ya 0, B'ye 1 dendiği ve çıkış duruma eşit olduğu için $Z = q$. JK ile kurulduğunda $J = K = x$ bağlantısı aynen kalır, $Z$ doğrudan flip-flop'un $Q$ çıkışından alınır. Böylece çıkışı yalnız bulunulan duruma bağlı bir Moore makinesi elde edilir.

**Soru:** JK flip-flop'u tasarımlarda neden tercih edebiliriz? **Cevap:** <!-- BELİRSİZ: hoca soruyu sordu, öğrenci cevabı altyazıda anlaşılmıyor. -->

> **Ek bilgi (derste anlatılmadı):** JK flip-flop'un ters dönüşüm tablosunda her satırda bir don't care bulunur. Bu don't care'ler Karnaugh haritasında daha büyük gruplar kurmayı sağladığı için JK ile elde edilen giriş fonksiyonları genelde daha basit olur; bu örnekte de $J$ ve $K$ don't care'ler sayesinde tek değişkene ($x$) indi.

## 8. 3 Bitlik Senkron Yukarı Sayıcı

Aradan sonra Moore makinesi örneği bir sayıcıyla sürdürüldü: 3 bitlik senkron yukarı sayıcıyı T flip-flop'larla tasarlayınız (ekrandan, 01:20:00).

### 8.1 Giriş var mı?

3 bitlik sayıcı 0'dan 7'ye sayar ve 7'den sonra 0'a döner; durum diyagramında 0'dan 7'ye sekiz durum bir halka oluşturur. Hoca burada girişin ne olduğunu sordu. Dışarıdan bir giriş yoktur: durum geçişi saat işaretinin gelmesiyle sağlanır ve dışarıdan bir girişe bakılarak karar verilmez. Her durumdan tek bir ok çıkması da girişin olmadığını gösterir. Örneğin 0 durumundayken saat gelince kesinlikle 1'e gidilir.

Moore mantığında çalıştırılacağı için durumlar kendi değerleriyle kodlanır: mevcut durum $q_2q_1q_0$ ($q_2$ en yüksek anlamlı), sonraki durum $Q_2Q_1Q_0$. Çıkış durumun kendisidir ($Z = q_2q_1q_0$); belirli bir durumdayken sayıcı çıkışında o değer görülür.

### 8.2 Tablo ve fonksiyonlar

T ters dönüşüm tablosu (ekrandan, 01:20:00): $00 \to 0$, $01 \to 1$, $10 \to 1$, $11 \to 0$. Üç hafıza elemanı gerekir: $T_2$, $T_1$, $T_0$.

```text
q2 q1 q0 | Q2 Q1 Q0 | T2 T1 T0
 0  0  0 |  0  0  1 |  0  0  1
 0  0  1 |  0  1  0 |  0  1  1
 0  1  0 |  0  1  1 |  0  0  1
 0  1  1 |  1  0  0 |  1  1  1
 1  0  0 |  1  0  1 |  0  0  1
 1  0  1 |  1  1  0 |  0  1  1
 1  1  0 |  1  1  1 |  0  0  1
 1  1  1 |  0  0  0 |  1  1  1
```

(ekrandan, 01:25:00)

- $T_0$: $q$ ne olursa olsun 1'dir, $T_0 = 1$.
- $T_1$: tablodan doğrudan $q_0$ ile aynı olduğu görülür, $T_1 = q_0$.
- $T_2$: iki minterm vardır: $T_2 = q_2q_1q_0 + \bar{q}_2q_1q_0$. $q_1q_0$ parantezine alınınca $q_2 + \bar{q}_2 = 1$ gider ve $T_2 = q_1q_0$ olur.

Python ile 8 durumun hepsi için bu üç denklem doğrulandı.

### 8.3 Devre

Üç T flip-flop kullanılır (ekrandan, 01:25:00): $T_0$'a doğrudan 1, $T_1$'e $q_0$ çıkışı, $T_2$'ye $q_1$ ve $q_0$'ın AND'i bağlanır. Senkron tasarım olduğu için üç flip-flop'un saat girişleri birleştirilip ortak bir saat darbesiyle beslenir. $Z$ çıkışı 3 bitten oluşur: $Z_2$, $Z_1$, $Z_0$ doğrudan $q_2$, $q_1$, $q_0$'dır.

**Soru:** Bu devre aşağı yönlü sayıcı yapılmak istense ne değişir? **Cevap:** Sonraki durumlar, yani büyük $Q$'lar değişir. Bunlara karşılık gelen $T$ uçlarının fonksiyonları da değişeceği için yeniden hesaplanıp devre yeniden kurulmalıdır.

## 9. Asenkron (Ripple) Sayıcılar

### 9.1 Her bit bir öncekinin iki katı periyotta değişir

Sayıcı tablosunda $q_0$'a bakılırsa her saat darbesinde (her durum geçişinde) değiştiği görülür: 0, 1, 0, 1, ... Hoca bunun tek bir flip-flop'la nasıl yapılacağını sordu.

**Soru:** T flip-flop ile her saat darbesinde toggle eden bir devre nasıl kurulur? **Cevap:** Bir öğrenci $T$ ucuna 1 bağlanabileceğini söyledi. Hoca doğruladı: T flip-flop'un tanımına göre $T=1$ iken her yükselen kenarda çıkış tümlenir. Bu çıkış, 3 bitlik sayıcının $q_0$'ıdır ve saat işaretinin iki katı periyoda sahiptir.

$q_1$'e bakılırsa iki kez 0, iki kez 1 olur; yani $q_0$'ın iki katı periyotta değişir. $q_0$ saat işaretinin iki katı periyotta toggle eden bir işaret olduğuna göre, $q_1$ de $q_0$'ı saat gibi kullanan ve $T=1$ ile toggle eden bir flip-flop'tan elde edilebilir.

**Soru:** Buradan çıkan sonuç ne? **Cevap:** Bir öğrenci ikinci flip-flop'un saatine $q_0$'ın bağlanacağını söyledi; hoca doğruladı.

$q_2$ dört saat boyunca bir değerde, dört saat boyunca diğer değerde kalır; yani $q_1$'in iki katı periyotta değişir. Üçüncü T flip-flop'un da $T$ ucuna 1, saatine $q_1$ bağlanır. Üç çıkış birlikte 3 bitlik sayma değerini verir.

Bu yapıda her flip-flop'un saati farklı bir kaynaktan gelir: ilki dış saatten, diğerleri kendinden önceki flip-flop'un çıkışından. Bu yüzden devre asenkron ardışıl devredir.

### 9.2 Yükselen kenarda sayma yönü

Hoca dalga şemasını ızgaralı arka planda çizdi (ekrandan, 01:35:00). Bütün flip-flop'lar 0'dan başlatıldı. Saatin ilk yükselen kenarında $q_0$ 1'e çıkar; bu $q_0$ için bir yükselen kenardır, $q_1$ de 1'e çıkar; bu da $q_2$'yi 1'e çıkarır. Okunan değerler (ekrandan, 01:40:00): 111, 110, 101, 100, 011, 010, 001 ve sonra 000. Sayıcı 7'den başlayıp geriye doğru saymaktadır.

**Soru:** Bir öğrenci, sonraki kata $q_0$ yerine onun tersinin bağlanması gerekmez mi diye sordu. **Cevap:** Hoca önce dalga şemasına bakmayı önerdi; şema, $Q$ bağlantısıyla ve yükselen kenarla devrenin geri sayan bir asenkron sayıcı olduğunu gösterdi. Öğrencinin önerisi aşağıdaki üçüncü yoldur.

### 9.3 İleri sayıcı yapmanın yolları

- **Düşen kenarda tetikleme:** Aynı bağlantı düşen kenarlı flip-flop'larla kurulursa $q_0$ saatin düşen kenarlarında, $q_1$ $q_0$'ın düşen kenarlarında, $q_2$ $q_1$'in düşen kenarlarında değişir. Okunan değerler 000, 001, 010, 011, 100, 101, 110, 111 olur; devre yukarı sayıcıdır (ekrandan, 01:40:00).
- **$\bar{Q}$ bağlantısı:** Yükselen kenarlı flip-flop'larda sonraki katın saatine önceki katın $\bar{Q}$ çıkışı bağlanır. $\bar{Q}$'nun yükselen kenarı $Q$'nun düşen kenarıdır; sonuç yine yukarı sayıcıdır (ekrandan, 01:40:00).

Böylece asenkron sayıcı üç farklı yaklaşımla kurulabilir. Python ile yapılan benzetimde yükselen kenar + $Q$ için 7, 6, ..., 0; düşen kenar + $Q$ ve yükselen kenar + $\bar{Q}$ için 0, 1, ..., 7 dizisi elde edildi.

## 10. Yazmaçlar

Kombinasyonel devrelerde olduğu gibi ardışıl devrelerde de daha büyük bloklar kurulur. Flip-flop bir bit saklar; oysa işlemcide tek bit yerine bit gruplarıyla işlem yapılır. Bu yüzden $n$ bitlik bir değeri saklayabilen yazmaçlara ihtiyaç vardır. Yazmaçlar işlem sonuçlarını saklamak ve aritmetik/lojik işlemlere girdi sağlamak için mikroişlemcinin içinde bulunan yüksek hızlı hafıza elemanlarıdır; genişliği mimariye göre 8, 16 bit vb. olur.

### 10.1 Paralel yüklemeli yazmaç

Blok olarak 8 bitlik girişi ve 8 bitlik çıkışı olan, saatin yükselen kenarında girişteki değeri içeri kopyalayan bir yapıdır. İçeride 8 adet D flip-flop bulunur; aynı anda yükleme için saatleri ortaklanır. Her flip-flop'un $D$ ucu ilgili giriş bitine, $Q$ çıkışı ilgili çıkış bitine bağlanır. Fonksiyon tablosu: yükselen kenarda $Q = D$, diğer durumlarda $q$ korunur.

### 10.2 Ötelemeli yazmaç (shift register)

Bazen saklanan değerin sağa ya da sola ötelenmesi ya da döndürülmesi (rotate) gerekir; bunlar işlemcinin shift left, shift right, rotate gibi işlemlerinde kullanılır. Ötelemeli yazmacın bloğunda bir saat, bir bitlik seri giriş ($S_{in}$) ve bir bitlik çıkış vardır.

Hoca bir kullanım örneği verdi: seri toplayıcı. İki $n$ bitlik sayı iki yazmaçta (A ve B) saklıdır. En düşük anlamlıdan başlayarak sıradaki bitler seri toplayıcıya verilir; çıkan toplam biti yazmaçlardan birine biriktirilir, elde ise ardışıl devrenin içinde tutulur. Bunun için her adımda A ve B yazmaçları bir adım sağa ötelenmelidir. Hoca seri toplayıcının senkron ardışıl devre olarak tasarlanmasını zorunlu olmayan bir alıştırma olarak önerdi.

4 bitlik ötelemeli yazmaç dört D flip-flop'un seri bağlanmasıyla kurulur (ekrandan, 01:45:00): $S_{in}$ birinci flip-flop'un $D$'sine, her flip-flop'un $Q$'su bir sonrakinin $D$'sine bağlanır, saatler ortaktır, çıkış $Q_4$'ten alınır. Her yükselen kenarda 3'teki bit 4'e, 2'deki 3'e, 1'deki 2'ye kayar; $S_{in}$ 1 numaralı yeri doldurur. Hoca okuma kolaylığı için $Q_4$'ün en düşük anlamlı, $Q_1$'in en yüksek anlamlı bit olarak düşünülebileceğini söyledi.

Slayttaki örnek dizi (ekrandan, 01:45:00):

```text
     Sin Q1 Q2 Q3 Q4=Q
t0    1   0  0  0  0
t1    0   1  0  0  0
t2    1   0  1  0  0
t3    1   1  0  1  0
t4    1   1  1  0  1
t5    0   1  1  1  0
t6    0   0  1  1  1
t7    0   0  0  1  1
```

Tablo Python ile satır satır üretilerek doğrulandı.

### 10.3 Paralel erişimli (paralel yüklemeli ve ötelemeli) yazmaç

İki işlevin birleşimi istenebilir. 4 bitlik bu yazmaçta saat, seri giriş, 4 bitlik paralel giriş ve $\overline{\text{Shift}}/\text{Load}$ denetim ucu vardır (ekrandan, 01:50:00). Denetim ucuna 1 verilince paralel yükleme, 0 verilince öteleme yapılır. İçeride 4 flip-flop ve her bit diliminde (bit slice) iki AND ve bir OR'dan oluşan bir denetim devresi bulunur.

Hoca 3 numaralı bit dilimi için $Q_3$'ü buldu. Denetim ucuna $X$ denirse:

- $X=0$ (öteleme): paralel girişte ne olursa olsun $S_{in}$ 0 ise $Q_3=0$, 1 ise $Q_3=1$; yani seri giriş $Q_3$'e aktarılır.
- $X=1$ (yükleme): seri girişte ne olursa olsun paralel giriş $P_i$ 0 ise 0, 1 ise 1 çıkar.

Don't care'ler genişletilip 8 satırlı tablo Karnaugh haritasına konursa da aynı sonuç çıkar:

$$Q_3 = \bar{X}\,S_{in} + X\,P_i$$

Bu ifade D flip-flop'un $D$ ucuna bağlanacak fonksiyondur. Devrede ilk AND $\bar{X}$ ile seri girişi, ikinci AND $X$ ile paralel girişi alır, OR toplamı $D$'ye bağlanır. Diğer bit dilimlerinde seri giriş yerine bir üst sıradaki flip-flop'un çıkışı gelir (örneğin $Q_2$ dilimine $Q_3$).

## 11. Yükleme Uçlu Senkron Sayıcı

Derste kurulan sayıcıların entegre olarak sunulan versiyonları da vardır (ekrandan, 01:55:00):

- Enable (senkron): 1 iken sayıcı her saat darbesinde bir artarak sayar; 0 iken değerini tutar.
- Load (senkron): 1 iken $D$ uçlarındaki değer saatin yükselen kenarında başlangıç değeri olarak içeri yüklenir.
- Carry çıkışı: sayıcının başa döndüğünü gösterir.
- $D_3 \ldots D_0$ ve $Q_3 \ldots Q_0$'da 3 numaralı bitler en yüksek anlamlıdır.

### 11.1 8 ile 12 arasında sayan sayıcı

Hoca bu entegreyle 8-12 arasında sayan bir sayıcının nasıl kurulacağını sordu. Sayıcı 12'ye (1100) ulaştığında load ucuna 1 gelmeli ve yüklenecek değer 1000 olmalıdır. Sayılan değerler 1000, 1001, 1010, 1011, 1100'dür. Basitleştirilmiş mantık şöyledir: $q_2$ çıkışı load'a bağlanır, enable'a 1 verilir, $D$ uçlarına 8'in ikili karşılığı (1000) bağlanır (ekrandan, 01:55:00).

- 8-11 arasında $q_2 = 0$ olduğu için sayıcı normal artar.
- 12'de $q_2 = 1$ olduğu için bir sonraki kenarda 8 yüklenir.
- Sayıcı sıfırdan başlarsa 4'e (0100) geldiğinde de $q_2 = 1$ olur ve 8 yüklenir. Bu, başlangıçtaki tek hatalı saymadır; sonrasında hep 8-12 arasında sayan bir yukarı sayıcı olarak çalışır.

Python benzetimi: 0, 1, 2, 3, 4, 8, 9, 10, 11, 12, 8, 9, ...

### 11.2 Sayıcının önemi

Sayıcı işlemcide program sayıcı (program counter) yazmacı olarak karşımıza çıkacaktır. Ardışık komutlar yürütülürken bu yazmaç bir artırılır; dallanma gibi özel durumlarda bir toplama devresiyle birlikte kullanılır. Bu yüzden bu blok mikroişlemcinin iç yapısı açısından önemlidir.

## 12. Programlanabilir Lojik Cihazlar

Bir problemin gerektirdiği lojik fonksiyonlar ya ayrık kapılarla ya da programlanabilir devre elemanları ve entegrelerle gerçeklenebilir. Bu bölümde ROM, PLA ve PAL ele alındı.

FPGA ve CPLD daha büyük ve kapasiteli fonksiyonlar için kullanılır. Örneğin bir CPU tasarımı FPGA üzerinde hızlıca prototiplenebilir, ama FPGA üretim için uygun değildir: testler ve iyileştirmeler yapıldıktan sonra kapı seviyesinde optimize edilip ASIC olarak, yani entegre seviyesinde üretilir. FPGA yeniden programlanabilir olduğu için farklı donanımlarda tekrar kullanılabilir. Her işlem bloğunda belirli sayıda flip-flop ve genel amaçlı programlanabilir kombinasyonel lojik bulunur; bu bloklarla büyük hafıza yapıları, lookup table'lar, kombinasyonel ve ardışıl devreler kurulabilir. Hoca FPGA'in bu dersin kapsamında olmadığını belirtti.

### 12.1 AND katı ve OR katı

Bir fonksiyon doğru mintermlerin toplamı olarak yazıldığında birinci katmanda AND kapıları, ikinci katmanda bunların çıkışlarını birleştiren çok girişli bir OR kapısı vardır. ROM, PAL ve PLA'nın üçü de bir AND katı ve bir OR katından oluşur; farkları hangi katın programlanabildiğidir (ekrandan, 02:15:00):

```text
ROM (PROM): sabit AND katı (dekoder)  -> programlanabilir bağlantılar -> programlanabilir OR katı
PAL       : programlanabilir AND katı -> sabit OR katı
PLA       : programlanabilir AND katı -> programlanabilir OR katı
```

"Programlanabilir" şu anlama gelir: OR katı programlanabiliyorsa hangi terimlerin toplama gireceği seçilebilir; AND katı programlanabiliyorsa çarpım terimine hangi girişlerin gireceği seçilebilir.

## 13. ROM

### 13.1 Yapı ve kapasite

ROM'un $n$ adres ucu, $m$ veri ucu, bir okuma denetim (output enable) ucu ve bir enable ucu vardır. $n$ adres ucu $2^n$ hafıza gözü demektir ve her göz $m$ bittir; kapasite $2^n \times m$ bittir. Slaytta aynı yapı $k$ giriş (adres) ve $n$ çıkışla "$2^k \times n$ ROM" diye gösterilir (ekrandan, 02:20:00).

### 13.2 İç yapı

ROM'un içinde bir dekoder vardır: $n$ adres ucuna karşılık $2^n$ hafıza gözünden birini seçer. Dekoder çıkışları mintermlere karşılık gelir; yani $k$ girişli bir fonksiyonun bütün mintermleri dekoder çıkışında hazırdır. Her veri biti için bir OR kapısı vardır ve bütün dekoder çıkışlarından her OR kapısına birer bağlantı bulunur. Slayttaki örnekte 5'e 32 dekoder ve 8 OR kapısı ($A_7 \ldots A_0$) vardır (ekrandan, 02:20:00).

ROM'u programlamak, OR katındaki bu bağlantılardan istenenleri korumak, diğerlerini yakmaktır. Bağlantılar sigorta gibi düşünülebilir: belirli bir akıma kadar dayanırlar, yüksek akım verilirse kopar. Şemalarda bu bağlantılar özet olarak tek bir dikey çizgi üzerinde çarpı işaretleriyle gösterilir.

ROM bir lookup table olarak da düşünülebilir: adres değeri verilir, o adresteki gözde fonksiyonun o giriş için istenen değerleri yazılıdır.

### 13.3 ROM ile fonksiyon gerçekleme örneği

Slayttaki örnekte $A$, $B$, $C$ girişleri ($A$ en yüksek anlamlı) 3'e 8 dekodere girer; $D_0 \ldots D_7$ mintermlerdir. Dört OR kapısı $F_3$, $F_2$, $F_1$, $F_0$'ı üretir. Çarpı işaretleri ilgili mintermin o sütundaki OR kapısına bağlı olduğunu gösterir (ekrandan, 02:25:00):

- $F_3 = m_2 + m_5 + m_7 = \bar{A}B\bar{C} + A\bar{B}C + ABC$
- $F_2 = m_0 + m_7 = \bar{A}\bar{B}\bar{C} + ABC$
- $F_1 = m_1 + m_4 = \bar{A}\bar{B}C + A\bar{B}\bar{C}$
- $F_0 = m_1 + m_5 + m_7 = \bar{A}\bar{B}C + A\bar{B}C + ABC$

> **Ders sonrası not:** Hoca $F_1$'i okurken birinci ve dördüncü mintermlerden sonra 7 numaralı mintermin de bağlı olduğunu söyledi; ekrandaki şemada ve hocanın kendi kırmızı notunda $F_1 = \bar{A}\bar{B}C + A\bar{B}\bar{C}$'dir, $m_7$ büyük olasılıkla $F_2$'ye aittir ($F_2 = \bar{A}\bar{B}\bar{C} + ABC$).

Okuma örneği (ekrandan, 02:25:00): adres uçlarına $A_2A_1A_0 = 001$ verilsin. Yalnız $D_1$ aktif olur. $D_1$'in $F_3$ ve $F_2$ sütunlarında bağlantısı yoktur, bu çıkışlar 0 okunur; $F_1$ ve $F_0$'da bağlantı vardır, bir OR girişinin 1 olması sonucu 1 yapmaya yeter. Çıkış $F_3F_2F_1F_0 = 0011$ olur. Python ile dört fonksiyondan aynı değer elde edildi.

OR katı ve dekoder ROM'un içinde gömülü olduğu için ROM programlandığında hiçbir ek kapı kullanmadan, veri yolu genişliği kadar lojik fonksiyon aynı anda gerçeklenir. ROM kullanmanın avantajı budur.

**Soru:** Şemada ROM için "AND katı sabit" deniyor. AND katı nerede ve neden sabit? **Cevap:** Bir öğrenci AND kapılarının dekoderin içinde olduğunu söyledi. Hoca doğruladı: dekoder, girişine uygulanan ikili sayının onluk karşılığı olan çıkışı aktif eder; her çıkış girişlerin çarpımı olan bir mintermdir. Yani dekoderin içinde her çıkışın önünde 3 terimi AND'leyen bir katman vardır ve bu katman programlanamaz.

### 13.4 Bütün mintermlere ihtiyaç var mı?

Hoca üç girişli kaç farklı lojik fonksiyon yazılabileceğini sordu. 3 girişli doğruluk tablosunun $2^3 = 8$ satırı vardır ve her satırın çıkışı 0 ya da 1 olabilir. Dolayısıyla fonksiyon sayısı $2^{2^3}$'tür. Bunlardan ikisi sabittir ($F=0$ ve $F=1$); $F=1$ yerine doğrudan lojik 1 bağlamak aynı sonucu verir, bu yüzden bunlar anlamsızdır. Ayrıca bazı fonksiyonlar başka fonksiyonların tümleyenidir; çıkışa bir NOT kapısı eklenirse fonksiyonların yarısını gerçekleyebilen bir donanım hepsini üretebilir.

> **Ders sonrası not:** Hoca $2^{2^3}$'ü 64 olarak hesapladı ve sabitler çıkınca 62, tümleyenlerle 31 fonksiyon dedi. Doğrusu $2^{2^3} = 2^8 = 256$'dır; sabitler çıkınca 254, tümleyen çiftleri birleştirilince 127 fonksiyon kalır. Hocanın vardığı nitel sonuç (NOT kapısıyla donanım yarıya iner) değişmez.

PLA ve PAL, gerçeklenecek fonksiyonlarda bütün mintermlere gerek olmayacağı ve bazı terimlerin birbirinin tümleyeni olarak kullanılabileceği varsayımından hareket eder; daha az terimle, daha düşük karmaşıklıkta entegrelerdir.

## 14. PLA

### 14.1 Yapı

PLA (Programmable Logic Array) hem AND hem OR katı programlanabilen yapıdır. Girişlerin hem kendisi hem tümleyeni içeride hazırdır; bir $A$ girişi verildiyse $\bar{A}$ da kullanılabilir. Slayttaki örnekte 3 giriş ve 4 AND kapısı vardır (ekrandan, 02:35:00). Bu, en fazla 4 çarpım terimi üretilebileceği anlamına gelir; 3 giriş için 8 minterm mümkündür ama yarısı kadar üretilir. Her AND kapısına hangi girişlerin gireceği seçilebilir.

Çarpım terimleri ROM'daki gibi programlanabilir bir OR katında toplanır. Toplam son olarak bir XOR katından geçer: XOR'un bir girişi çarpımlar toplamı, diğeri programlanabilir 0 ya da 1'dir. 0 seçilirse fonksiyon aynen çıkar; 1 seçilirse bir değişkenin 1 ile XOR'u tümleyenini verdiği için fonksiyonun tümleyeni çıkar.

PLA'nın slayttaki avantaj ve dezavantajları (ekrandan, 02:30:00): ROM'a göre çok girişli fonksiyonlarda pratiktir, her çarpım terimi her çıkışa bağlanabilir, bazı PLA'larda çıkış tümlenebilir. Buna karşılık çarpım terimi sayısı uygulamayı sınırlar ve terim sayısını azaltmak için iki seviyeli çok çıkışlı optimizasyon gerekir.

### 14.2 Analiz örneği

Slayttaki PLA (ekrandan, 02:35:00):

- 1. AND: $A$ ve $\bar{B}$ bağlı, çıkış $A\bar{B}$.
- 2. AND: $A$ ve $C$, çıkış $AC$.
- 3. AND: $B$ ve $C$, çıkış $BC$.
- 4. AND: $\bar{A}$, $B$, $\bar{C}$, çıkış $\bar{A}B\bar{C}$.

$F_1$'e giden OR kapısında $A\bar{B}$, $AC$ ve $\bar{A}B\bar{C}$ bağlıdır; XOR'un diğer girişi 0'dır:

$$F_1 = A\bar{B} + AC + \bar{A}B\bar{C}$$

$F_2$'ye giden OR kapısında $AC$ ve $BC$ bağlıdır; XOR'un diğer girişi 1'dir:

$$F_2 = \overline{AC + BC} = (\bar{A} + \bar{C})(\bar{B} + \bar{C}) = \bar{A}\bar{B} + \bar{A}\bar{C} + \bar{B}\bar{C} + \bar{C}$$

Hoca bu açılımın daha da sadeleşebileceğini ama böyle yazılsaydı çok sayıda çarpım terimi gerekeceğini söyledi; tasarımda diğer fonksiyondan gelebilecek ortak terimler kullanılmıştır.

> **Ders sonrası not:** Açılım $\bar{A}\bar{B} + \bar{C}$'ye sadeleşir ($\bar{A}\bar{C}$ ve $\bar{B}\bar{C}$, $\bar{C}$ tarafından yutulur). Python ile 8 giriş için doğrulandı.

### 14.3 Çarpım terimi sınırını aşmak

**Soru:** İki fonksiyon aynı anda gerçeklenecek. Karnaugh haritasıyla sadeleştirildiğinde birinci fonksiyon 3, ikincisi birincide olmayan 2 farklı çarpım teriminden oluşuyor; toplam 5 terim gerekiyor ama PLA 4 terim üretebiliyor. Ne yapılmalı? **Cevap:** Bir öğrenci maxterm cinsinden yazmayı önerdi; hoca bunun benzer bir mantık olduğunu söyledi. Hoca tam toplayıcıda toplam ve elde için ortak kapı arandığını hatırlattı: orada fonksiyonlardan biri en sade haliyle değil, bir iki seviye önceki haliyle yazılmış ve toplam 4 farklı çarpım terimiyle sonuç elde edilmişti. PLA'da da çıkıştaki XOR sayesinde her fonksiyonun ya kendisi ya da tümleyeni yazılabilir; amaç ortak çarpım terimleri bulmaktır.

### 14.4 Tasarım örneği: Mano Örnek 6-3

Verilen fonksiyonlar (ekrandan, 02:40:00):

$$F_1(A,B,C) = \Sigma m(3,5,6,7), \qquad F_2(A,B,C) = \Sigma m(1,2,3,7)$$

Karnaugh haritalarına yerleştirme: $F_1$ için $m_3 = 011$, $m_5 = 101$, $m_6 = 110$, $m_7 = 111$; $F_2$ için $m_1 = 001$, $m_2 = 010$, $m_3 = 011$, $m_7 = 111$.

Fonksiyonun tümleyeni de alınabildiği için bir haritadaki 1'ler, diğer haritadaki 0'larla (yani tümleyenle) eşleştirilmeye çalışılır. Böylece her fonksiyonun hem kendisi (1'ler gruplanarak) hem tümleyeni (0'lar gruplanarak) yazılır (ekrandan, 02:40:00):

- $F_1 = AB + AC + BC$
- $\bar{F}_1 = \bar{A}\bar{B}C + \bar{A}B\bar{C} + \bar{B}\bar{C}$
- $F_2 = \bar{A}B + \bar{A}C + BC$
- $F_2 = \bar{A}\bar{B}C + \bar{A}B\bar{C} + BC$ (ortak kapı oluşturacak biçimde, 3'lü terimler korunarak)

Hoca $\bar{F}_1$'de yalnız $F_1$'e özel terimi ($\bar{B}\bar{C}$), $F_2$'de yalnız $F_2$'ye özel terimi ($BC$) gösterdi. $F_1$'in 1'lerinden yazılan bazı terimlerin tümleyeni karşı tarafta oluşmadığı için onlar için ayrı çarpım terimi gerekeceğini belirtti.

Sonra dört eşleştirmeye bakılır: $F_1$ ile $F_2$, $\bar{F}_1$ ile $\bar{F}_2$, $F_1$ ile $\bar{F}_2$ ve $\bar{F}_1$ ile $F_2$. En fazla ortak terim $\bar{F}_1$ ile $F_2$ eşleştirmesindedir (ekrandan, 02:45:00):

$$F_1 = \overline{\bar{A}\bar{B}C + \bar{A}B\bar{C} + \bar{B}\bar{C}}, \qquad F_2 = \bar{A}\bar{B}C + \bar{A}B\bar{C} + BC$$

Ortak terimler $\bar{A}\bar{B}C$ ve $\bar{A}B\bar{C}$'dir; bunlara $F_1$'e özel $\bar{B}\bar{C}$ ve $F_2$'ye özel $BC$ eklenince toplam 4 farklı çarpım terimi yeter. $F_1$ çıkışındaki XOR'a 1, $F_2$'ninkine 0 verilir. Böylece 4 çarpım terimli bir PLA ile iki fonksiyon aynı anda gerçeklenir. Python ile her iki ifadenin verilen minterm listelerini ürettiği doğrulandı.

## 15. PAL

PAL'da AND katı programlanabilir, OR katı sabittir. Bu yüzden her çıkışta kaç çarpım teriminin toplanacağı sabittir; slayttaki PAL'da her OR 3 çarpım terimi toplayabilir. Tasarım 4 çarpım teriminin toplamını gerektirirse bu doğrudan yapılamaz. Bunu mümkün kılmak için PAL entegrelerinde bir OR çıkışı AND katına giriş olarak geri verilir.

Örnekte dört eşanlı fonksiyon (W, X, Y, Z) minterm toplamlarıyla verilmiş ve sadeleştirilmiştir. Z dört çarpım teriminin toplamı çıktığı için verilen PAL'da normalde gerçeklenemez. Diğer fonksiyonların Z'nin içinde olup olmadığına bakılır: Z'nin ilk iki terimi W'ye eşittir. W çıkışı AND katına verilir; o AND satırında yalnız W bağlanır, diğer girişler katılmaz, böylece o AND'in çıkışı W olur. Z, W artı diğer iki terim olarak 3 terime iner. <!-- BELİRSİZ: W, X, Y, Z'nin minterm listeleri ve sadeleşmiş ifadeleri ekranda gösterildi ama bu ana ait kare yok; altyazıdan okunamıyor. -->

**Soru:** W'ye indirgeyip sonra kullanma yöntemi PLA'da da yapılabilir mi? **Cevap:** Hoca PLA'da OR katında böyle bir indirgemenin bir yöntem olabileceğini, ama PLA'daki asıl darboğazın çarpım terimi sayısı olduğunu söyledi. Bu yüzden PLA'da ortak çarpım terimleri bulmak daha pratik ve optimum olur. PAL'da ise yapı zaten bir toplam terimini diğer fonksiyonlara bağladığı için toplam terimlerini diğer fonksiyonların içinde aramak daha pratik sonuç verir.

> **Hocanın vurgusu:** PLA'da ortak çarpım terimleri, PAL'da diğer fonksiyonların içinde yer alan toplam terimleri aranır.

## 16. Örnek Sorular

### Soru 1 (ekrandan, 00:40:00)

Durumları A (kod 0) ve B (kod 1) olan Mealy makinesi veriliyor: A'da $0/0$ ile kendine döner, $1/1$ ile B'ye geçer; B'de $0/1$ ile kendine döner, $1/0$ ile A'ya geçer. Devreyi T, D ve JK flip-flop'larla ayrı ayrı gerçekleyiniz.

> **Çözüm (derste verildi, ekrandan 00:55:00):** Doğruluk tablosu Bölüm 7.1'dedir. $Z = x \oplus q$; T ile $T = x$; D ile $D = x \oplus q$; JK ile $J = K = x$. Moore versiyonunda $Z = q$.

### Soru 2 (ekrandan, 01:20:00)

3 bitlik senkron yukarı sayıcıyı T flip-flop'larla tasarlayınız.

> **Çözüm (derste verildi):** $T_0 = 1$, $T_1 = q_0$, $T_2 = q_1q_0$; üç flip-flop'un saati ortaktır, çıkış $q_2q_1q_0$'dır.

### Soru 3 (derste sözlü, 01:23:29)

Aynı sayıcı aşağı sayıcı yapılmak istense ne değişir?

> **Cevap (derste verildi):** Sonraki durumlar ($Q$'lar) değişir; dolayısıyla $T$ fonksiyonları yeniden hesaplanır.

> **Çözüm (derste verilmedi):** Aşağı sayıcıda $q_0$ yine her adımda değişir, $q_1$ ancak $q_0 = 0$ iken, $q_2$ ancak $q_1 = q_0 = 0$ iken değişir: $T_0 = 1$, $T_1 = \bar{q}_0$, $T_2 = \bar{q}_1\bar{q}_0$. Python ile 8 durum için doğrulandı.

### Soru 4 (derste sözlü, 01:26:42)

T flip-flop ile her saat darbesinde toggle eden bir devre nasıl kurulur?

> **Cevap (derste verildi):** $T$ ucuna 1 bağlanır.

### Soru 5 (ekrandan, 01:35:00)

$T=1$ bağlı, yükselen kenar tetiklemeli üç T flip-flop'ta her katın saatine önceki katın $Q$ çıkışı bağlanıyor. Bütün çıkışlar 0'dan başlarsa sayıcı hangi yönde sayar? İleri sayıcı yapmak için ne yapılabilir?

> **Çözüm (derste verildi, ekrandan 01:40:00):** İlk kenarda 111 olur, sonra 110, 101, 100, 011, 010, 001, 000 diye geri sayar. İleri saymak için ya flip-flop'lar düşen kenarda tetiklenir ya da sonraki katın saatine önceki katın $\bar{Q}$ çıkışı bağlanır.

### Soru 6 (ekrandan, 01:50:00)

4 bitlik paralel erişimli ötelemeli yazmaçta $\overline{\text{Shift}}/\text{Load} = 0$ iken öteleme, 1 iken paralel yükleme yapılıyor. En yüksek anlamlı bit diliminde $D$ ucuna bağlanacak fonksiyonu bulunuz.

> **Çözüm (derste verildi):** Denetim ucu $X$ ile $Q_3 = \bar{X}\,S_{in} + X\,P_i$.

### Soru 7 (ekrandan, 01:55:00)

Enable ve load uçlu 4 bitlik senkron yukarı sayıcıyla 8 ile 12 arasında sayan bir devre kurunuz.

> **Çözüm (derste verildi):** Enable = 1, Load = $q_2$, $D_3D_2D_1D_0 = 1000$. Sayıcı 8, 9, 10, 11, 12, 8, ... diye sayar; sıfırdan başlatılırsa ilk turda 4'ten sonra 8 yüklenir.

### Soru 8 (ekrandan, 02:25:00)

Şemadaki $8 \times 4$ ROM için $F_3$, $F_2$, $F_1$, $F_0$ fonksiyonlarını $A$, $B$, $C$ cinsinden yazınız. Adres 001 için çıkış nedir?

> **Çözüm (derste verildi, ekrandan):** $F_3 = \bar{A}B\bar{C} + A\bar{B}C + ABC$, $F_2 = \bar{A}\bar{B}\bar{C} + ABC$, $F_1 = \bar{A}\bar{B}C + A\bar{B}\bar{C}$, $F_0 = \bar{A}\bar{B}C + A\bar{B}C + ABC$. Adres 001 için $F_3F_2F_1F_0 = 0011$.

### Soru 9 (derste sözlü, 02:25:59)

ROM'da AND katının sabit olduğu nereden anlaşılır?

> **Cevap (derste verildi):** AND kapıları dekoderin içindedir; her dekoder çıkışı bir mintermdir ve bu katman programlanamaz.

### Soru 10 (derste sözlü, 02:27:38)

Üç girişli kaç farklı lojik fonksiyon yazılabilir?

> **Çözüm:** $2^{2^3} = 256$. Derste bu sayı 64 olarak söylendi; doğru değer 256'dır (bkz. Bölüm 13.4).

### Soru 11 (ekrandan, 02:35:00)

Şemadaki PLA'nın gerçeklediği $F_1$ ve $F_2$ fonksiyonlarını bulunuz.

> **Çözüm (derste verildi):** $F_1 = A\bar{B} + AC + \bar{A}B\bar{C}$, $F_2 = \overline{AC + BC}$. Açılım derste $\bar{A}\bar{B} + \bar{A}\bar{C} + \bar{B}\bar{C} + \bar{C}$ diye yazıldı; bu ifade $\bar{A}\bar{B} + \bar{C}$'ye sadeleşir.

### Soru 12 (ekrandan, 02:40:00)

$F_1(A,B,C) = \Sigma m(3,5,6,7)$ ve $F_2(A,B,C) = \Sigma m(1,2,3,7)$ fonksiyonlarını 3 girişli, 4 çarpım terimli ve 2 çıkışlı bir PLA ile gerçekleyiniz.

> **Çözüm (derste verildi, ekrandan 02:45:00):** $F_1 = \overline{\bar{A}\bar{B}C + \bar{A}B\bar{C} + \bar{B}\bar{C}}$ (XOR'a 1), $F_2 = \bar{A}\bar{B}C + \bar{A}B\bar{C} + BC$ (XOR'a 0). Kullanılan çarpım terimleri: $\bar{A}\bar{B}C$, $\bar{A}B\bar{C}$, $\bar{B}\bar{C}$, $BC$.

## Dersin Toparlaması

Ders, hafıza elemanlarının tekrarıyla başladı: latch seviye, flip-flop kenar tetiklemelidir ve ardışıl devrelerde gecikme farklarının bozucu etkisinden kaçınmak için flip-flop kullanılır. Saatli SR latch'in NOR geri beslemesi ve AND denetim katmanı incelendi; SR, JK, D ve T flip-flop'ların tanım ve ters dönüşüm tabloları çıkarıldı. Bu tablolarla iki durumlu bir Mealy makinesi T, D ve JK ile, 3 bitlik bir senkron yukarı sayıcı T ile tasarlandı; Mealy ve Moore makinelerinin farkı ve senkron tasarımda ortak saat şartı vurgulandı. Asenkron sayıcıda bir katın çıkışının sonraki katın saati olduğu, sayma yönünün tetikleme kenarına ve $Q$/$\bar{Q}$ seçimine bağlı olduğu gösterildi.

Ardından ardışıl bloklara geçildi: paralel yüklemeli yazmaç, ötelemeli yazmaç, paralel erişimli ötelemeli yazmaç ve yükleme uçlu senkron sayıcı. Sayıcının ileride işlemcinin program sayıcısı olarak kullanılacağı belirtildi. Son bölümde programlanabilir lojik cihazlar ele alındı: ROM'da sabit dekoder (AND) ve programlanabilir OR katı, PLA'da iki katın da programlanabilmesi ve çıkıştaki XOR ile ortak çarpım terimi arama, PAL'da sabit OR katı ve OR çıkışının AND katına geri verilmesi. Bellek elemanlarıyla ilgili slaytların sonraki haftalarda ele alınacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
