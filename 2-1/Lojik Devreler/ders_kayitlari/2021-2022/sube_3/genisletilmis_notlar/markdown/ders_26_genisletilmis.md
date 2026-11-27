# Ders 26 Genişletilmiş Notu: Ardışıl Devreler, Durum Diyagramları ve Flip-Floplar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ardışıl devrelerin yapısı (tekrar)
- 2. Mealy ve Moore makineleri
- 3. Senkron ve asenkron ardışıl devreler
- 4. Kapı gecikmesiyle veri saklama
- 5. Çoğullayıcıda gecikme, glitch ve durum saklama
- 6. Durumlar ve durum tablosu
- 7. Durum diyagramları
- 8. Şifre (dizi tanıyıcı) örnekleri
- 9. Tutucular ve flip-floplar
- 10. Karakteristik ve uyarma tabloları
- 11. Zamanlama diyagramı örnekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Ardışıl devrelerin yapısı (tekrar)

Ders, bir önceki derste başlanan ardışıl devreler konusunun hızlı bir tekrarıyla açılır; anlatım slaytlar üzerinde, tabletle slayta elle not alınarak yapılır. Kombinezonsal devrelerden sonra ardışıl devrelere geçildiği ve ardışıl devrelerin içinde aslında yine bir kombinezonsal devre bulunduğu hatırlatılır. Fark, bir **saklama birimi** (storage element) eklenmesidir. Bu birim tutucu (latch) ya da flip-flop yapılarıyla kurulur (ekrandan, 00:05:00).

Slayttaki blok şemada kombinezonsal lojik bloğuna iki tür giriş gelir: dışarıdan gelen **girişler** (inputs) ve saklama biriminden gelen **şimdiki durum** (state, present state). Bloğun çıkışları da iki türlüdür: dışarıya giden **çıkışlar** (outputs) ve saklama birimine giden **bir sonraki durum** (next state). Bir sonraki durum saklama biriminde tutulur ve bir sonraki adımda şimdiki durum olarak kombinezonsal kısma geri döner.

Hoca bunu kombinezonsal devrelerle karşılaştırarak açıklar. $A$, $B$, $C$ girişli bir devrenin doğruluk tablosunda her satır yalnız o anki girişlere göre o anki çıkışı verir; "o satırda olan o satırda kalır". Satırlara artık bir $t$ zamanı da eklenebilir. Ardışıl devrede ise önceki durum saklanır ve önceki durumla girişler birlikte çıkışı üretir. Örneğin birden ona kadar sayan bir devre, bir sonraki sayıyı üretebilmek için o anda hangi sayıda olduğunu bilmek zorundadır. Bunun için bir saklama birimi gerekir.

## 2. Mealy ve Moore makineleri

Ardışıl devre tasarımında iki gösterim yöntemi vardır: **Mealy** ve **Moore**. Slaytta iki model şöyle verilir (ekrandan, 00:10:00):

- Mealy makinesi: $z(t) = f\big(d(t), x(t)\big)$, $d(t+1) = f\big(d(t), x(t)\big)$
- Moore makinesi: $z(t) = f\big(d(t)\big)$, $d(t+1) = f\big(d(t), x(t)\big)$

Burada $x(t)$ giriş, $d(t)$ şimdiki durum, $d(t+1)$ bir sonraki durum ve $z(t)$ çıkıştır. Bir sonraki durumu belirleyen fonksiyon iki modelde de aynıdır: şimdiki durum ve giriş. Fark çıkıştadır. Mealy'de çıkış hem duruma hem girişe bağlıdır; Moore'da yalnız duruma bağlıdır. Slayttaki blok şemada Mealy'de giriş doğrudan çıkışı üreten kombinezonsal devreye (KD) girer; Moore'da ise giriş yalnız bir sonraki durumu üreten ayrı bir KD'ye girer, çıkışı üreten KD yalnız durumu görür.

Hoca "çıkış" kavramını örneklerle somutlaştırır. Bir trafik ışığında kırmızıdan sarıya, sarıdan yeşile geçişler durumlardır. Yeşil yandıktan sonra merkeze yeşil yanma süresini bildiren bir kontrol sinyali üretmek ise bir çıkıştır. Benzer biçimde 1, 2, 3, … diye sayan bir devrede her sayı bir durumdur; tanımlanan duruma (örneğin 9'a) varıldığında bir LED'in yanması çıkıştır. Mealy'de bu LED'in yanması durum ve o anki girişe bağlı bir fonksiyonla, Moore'da yalnız duruma bakılarak belirlenir.

> **Hocanın vurgusu:** Öğrenciler Mealy gösterimini daha kolay benimser, çünkü kombinezonsal devrelerde girişleri "durum" ve "giriş" diye ayırmadan hep bu biçimde çalışılmıştır. Ama Moore gösterimini de öğrenmek elzemdir; soruda Moore istendiğinde Moore ile çözmek gerekir.

## 3. Senkron ve asenkron ardışıl devreler

Ardışıl devreler, saklama birimlerinin girişlerini hangi anlarda gözlediğine ve durumlarını hangi anlarda değiştirdiğine göre ikiye ayrılır (ekrandan, 00:15:00).

### 3.1 Senkron devreler

Senkron devrede davranış, sinyallerin **ayrık zaman anlarındaki** değerleriyle tanımlanır. Saklama birimleri girişlerini yalnız bir zamanlama işaretine, yani bir saatin ürettiği saat darbelerine (clock pulses) göre gözler ve durum değiştirir. Hoca bunu "pek çok birimin içindeki hafıza birimlerini ortak bir uçla senkron çalıştıran yapı" diye tanımlar.

Verilen örnekler:

- **İşlemci (CPU):** senkron ardışıl devredir.
- **DDR bellekler:** RAM yapıları elektrik kesilince veriyi kaybeder; içindeki verilerin korunması için belirli bir frekansta yenileme (refresh) sinyali gelir. Bellekteki çok sayıda saklama birimi bu ortak sinyalle tetiklenir.

**Soru:** Bir işlemcinin senkron olduğunu nereden anlarız? **Cevap:** Bir öğrencinin cevabıyla: işlemcinin bir saat frekansı, yani belirli bir çalışma hızı vardır. Hoca örnek olarak "Intel i5, 2,8 GHz" yazar (ekrandan, 00:15:00). Bu değer, işlemcinin saniyede yaklaşık 2,8 milyar tetikleme darbesi gönderebildiğini gösterir. Sistemdeki her cihaz bu hızda çalışmak zorunda değildir; ama bundan daha hızlı bir cihaz bütün sistemi aynı zaman düzleminde tetikleyemez.

Flip-floplar da senkron çalıştığı için, DDR bellek ya da SSD gibi yapıların içindeki en küçük saklama araçları olan flip-floplar üzerine kurulu sistemler senkron mimaridedir.

### 3.2 Asenkron devreler

Asenkron devrede dışarıdan bir saat frekansı gelmez. Davranış, girişlerin herhangi bir andaki değerlerine ve girişlerin sürekli zamanda hangi sırayla değiştiğine bağlıdır. Hoca bunu bir düğmeye basınca güncelleme yapılmasına benzetir (örneğin bir sayfayı yenilemek için tuşa basmak): belirli bir zaman aralığı ya da frekans yoktur, güncellemeyi dış bir giriş başlatır. Slaytta ayrıca "saat yalnızca başka bir giriş gibi görülürse bütün devreler asenkrondur" notu yer alır.

### 3.3 Zamanlama diyagramı

Senkron devrede belirli frekansta bir saat darbesi bulunmalıdır. Tetikleme bu darbenin yükselen kenarında, düşen kenarında ya da seviyesinde yapılabilir. Slayttaki diyagramda girişi çıkışa aktaran bir devre gösterilir: giriş değişse bile çıkış ancak bir sonraki saat tetiklemesinden sonra ve küçük bir gecikmeyle güncellenir. Asenkron devrede ise girişteki değişiklik bir saat beklemeden, farklı farklı gecikmelerle çıkışa yansır.

<!-- BELİRSİZ: Hoca senkron zamanlama diyagramında bir yerin hatalı olabileceğini ya da kendisinin bir şeyi kaçırdığını söyledi (00:16:54); bu slaytın karesi yok. Ardından "ayrık olay simülasyonu ... senkron olayları söylüyor" cümlesi (00:17:42) altyazıda net değil. -->

## 4. Kapı gecikmesiyle veri saklama

Saklama biriminin lojik kapılarla nasıl gerçeklendiği sorusuna şöyle cevap verilir: bir bitlik veriyi tutmayı mümkün kılan şey, devre yapısından kaynaklanan **gecikmelerdir**. Her lojik kapının içinde transistörlerden oluşan bir elektronik tasarım vardır; bu yüzden girişteki değişiklik çıkışa belli bir süre sonra yansır.

### 4.1 Örnek: 0,5 ns gecikmeli NAND kapısı

Slayttaki örnek (ekrandan, 00:20:00): iki girişli bir NAND kapısının çıkışı önce anlık değer $F(I)$ (instantaneous) olarak hesaplanır, sonra 0,5 ns'lik bir gecikme bloğundan geçerek gerçek çıkış $F$ olur. $A$ ve $B$ uzun süredir 1'dir. $t = 0$'da $A$ 0'a iner, $t = 0{,}8$ ns'de tekrar 1'e çıkar.

| $t$ (ns) | $A$ | $B$ | $F(I)$ | $F$ | Açıklama |
|---|---|---|---|---|---|
| $-\infty$ | 1 | 1 | 0 | 0 | $A = B = 1$ uzun süredir |
| 0 | 1 → 0 | 1 | 0 → 1 | 0 | Anlık çıkış 1 olur |
| 0,5 | 0 | 1 | 1 | 0 → 1 | Çıkış 0,5 ns gecikmeyle 1 olur |
| 0,8 | 0 → 1 | 1 | 1 → 0 | 1 | Anlık çıkış 0 olur |
| 1,3 | 1 | 1 | 0 | 1 → 0 | Çıkış 0,5 ns gecikmeyle 0 olur |

Adım adım:

- $t = 0$: $A = 0$, $B = 1$ için NAND anlık olarak 1 verir. Ama gerçek çıkış $F$ hâlâ 0'dır; yani eski 0 değeri saklanmaktadır.
- $t = 0{,}5$ ns: gecikme dolar, $F$ 1 olur. Girişteki değişiklikten sonra 0 değeri 0,5 ns boyunca tutulmuştur.
- $t = 0{,}8$ ns: $A$ tekrar 1 olur; anlık çıkış hemen 0'a döner. Gerçek çıkış ise hâlâ 1'dir.
- $t = 0{,}8 + 0{,}5 = 1{,}3$ ns: $F$ 0 olur. 1 değeri de değişiklikten sonra 0,5 ns saklanmıştır.

Sonuç: girişteki her değişiklikten sonra eski değer 0,5 ns boyunca çıkışta kalır. Bu kısa süreli saklamayı mümkün kılan, NAND kapısının gecikmesidir.

> **Ders sonrası not:** Slayttaki tablonun son satırında zaman "0.13" yazılıdır (ekrandan, 00:20:00). $0{,}8 + 0{,}5$ hesabıyla doğrusu $1{,}3$ ns'dir; slayttaki değer büyük olasılıkla yazım hatasıdır.

### 4.2 Gecikme modeli

Sonraki örneklerde kullanılan kapı gecikmeleri şöyle tanımlanır:

- DEĞİL (inverter): 0,2 ns
- VE (AND): 0,4 ns
- VEYA (OR): 0,5 ns

## 5. Çoğullayıcıda gecikme, glitch ve durum saklama

### 5.1 Devrenin tanınması

Slaytta $A$, $B$, $S$ girişli ve $Y$ çıkışlı bir devre verilir (ekrandan, 00:25:00): $A$ ile $\bar S$ bir VE kapısına (0,4), $B$ ile $S$ diğer VE kapısına (0,4) girer; iki VE'nin çıkışı bir VEYA kapısında (0,5) birleşir. $\bar S$, $S$'nin 0,2 ns gecikmeli DEĞİL kapısından geçmiş hâlidir.

**Soru:** Bu devre hangi hazır kombinezonsal tüm devre gibi davranır? **Cevap:** Bir öğrenci $S$'nin seçme ucu olduğunu söyler; devre birebir bir **2'ye 1 çoğullayıcıdır** (MUX). $S = 0$ iken $\bar S = 1$ olur, üstteki VE kapısı $A$'yı geçirir; alttaki VE'nin bir girişi 0 olduğundan çıkışı 0'dır. Yani $Y = A$. $S = 1$ iken $Y = B$ olur.

### 5.2 Zamanlama diyagramı ve glitch

Diyagramda başlangıçta $A = 0$, $B = 1$, $S = 0$'dır; çıkışta $A$ yani 0 görülür.

- **$S$ 0 → 1:** $\bar S$, 0,2 ns sonra 0'a iner. $B$ yolu $S$'den doğrudan beslendiği için $B$'nin çıkışta görülmesi $0{,}4 + 0{,}5 = 0{,}9$ ns sürer. $Y$ 0,9 ns sonra 1 olur.
- **$S$ 1 → 0:** $S$ hemen 0 olur ama $\bar S$ ancak 0,2 ns sonra 1'e çıkar. Bu aralıkta iki VE kapısının da birer girişi 0'dır; ne $A$ ne $B$ seçilir ve VEYA'nın çıkışı 0'a düşer. Çıkışta kısa bir sıfır darbesi, yani **glitch** oluşur. Ardından $\bar S$ yolundan $A$ (artık 1) gelir ve çıkış düzelir.

**Soru:** Çıkıştaki bu çentik neden oluştu? **Cevap:** Öğrenciler önce DEĞİL kapısının değişme süresine işaret eder. Hoca bunu tamamlar: $S$ 0'a inmişken $\bar S$ henüz 1'e çıkmamıştır; iki seçme ucunun aynı anda 0 olduğu kısa bir aralık oluşur ve çıkış o aralıkta 0'a düşer.

### 5.3 Durum saklama: $A$ girişi $Y$'ye bağlanırsa

Aynı devrede $A$ girişi çıkış $Y$'ye bağlanır, yani $A = Y$ yapılır (ekrandan, 00:30:00). Slayttaki fonksiyon:

- $S = 1$ için $Y = B$
- $S = 0$ için $Y(t)$, $Y(t - 0{,}9)$'a bağlıdır

$S = 0$ iken üst VE kapısı $Y$'nin kendi değerini geri alır ve VE + VEYA gecikmesi kadar sonra tekrar çıkışa yazar. Hocanın tahtaya yazdığı ifade (ekrandan, 00:35:00):

$$Y(t) = Y(t - 0{,}9)$$

Diyagramın adımları:

- Başta $S = 0$ ve $Y$'nin değeri bilinmez (slaytta taralı alan); $Y$ kendi önceki değerini tutar.
- $S$ 1 olunca $B$ seçilir; $B = 1$ olduğundan 0,9 ns sonra $Y = 1$ olur.
- $S$ tekrar 0'a inince 5.2'deki gibi kısa bir glitch oluşur. Ardından $\bar S = 1$ ile üst yol açılır ve $Y$'nin önceki değeri olan 1 yeniden yazılır. Devre böylece 1 bilgisini saklar.
- $S$ tekrar 1 yapılınca $B$ seçilir; $B$ artık 0 olduğu için 0,9 ns sonra $Y = 0$ olur.

**Soru:** Saklama kısmını tekrar anlatabilir misiniz? **Cevap:** $S = 1$ yapıldığında $B$ çıkışa aktarılır; üst yol $\bar S = 0$ olduğundan devre dışıdır. $S$ 0'a indirildiğinde üst yol seçilir ve bu yol çıkışın kendisiyle beslendiği için 0,9 ns önceki $Y$ değeri tekrar $Y$'ye yazılır. "Önceki durum" burada zaman gecikmesi kadar önceki değer anlamına gelir.

### 5.4 Geri besleme bir DEĞİL kapısıyla yapılırsa: osilasyon

Son olarak $Y$, $A$ girişine 0,2 ns gecikmeli bir DEĞİL kapısı üzerinden bağlanır. Hoca öğrencilerden bu devrenin zamanlama diyagramını düşünmelerini ister.

**Soru:** Bu devrenin çıkışına bir ölçü aleti bağlansa nasıl bir sinyal görülür? **Cevap:** Bir öğrenci sürekli 1 ve 0 arasında gidip gelen bir sinyal tarif eder; hoca bunu doğrular. $S = 1$ iken devre $B$'yi çıkışa aktarır ve sorun yoktur. $S$ 0'a indirilip üst yol seçildiğinde, $Y$'nin önceki değeri (örneğin 1) VE, VEYA ve DEĞİL gecikmelerinin toplamı kadar korunur:

$$0{,}4 + 0{,}5 + 0{,}2 = 1{,}1 \text{ ns}$$

Bu sürenin sonunda tersi alınmış değer (0) geri gelir ve çıkış 0 olur; 1,1 ns sonra yine terslenip 1 olur. Çıkış her 1,1 ns'de bir terslenir. Bu tür devrelere **osilasyon devresi** denir: kendi çıkışının tersini alarak durmadan kendini tekrarlayan, kararsız (unstable) bir devre.

## 6. Durumlar ve durum tablosu

### 6.1 Durum kavramı

Sorularda durumlar her zaman formülle verilmez; sözel sorularda durumu oluşturan adımları analiz etmek gerekir (ekrandan, 00:40:00). İki örnek gösterilir:

- **0'dan 7'ye sayma:** durumlar 0, 1, 2, …, 7 değerleridir; 7'den sonra 0'a dönülür.
- **Adres tarifi:** bulunulan noktadan (0) aranan yere (3) gidilirken geçilen ara noktalar (1, 2) durumlardır. Durumlar, yoldaki "köşe başları" gibidir.

### 6.2 Durum tablosu

Kombinezonsal devrelerde doğruluk tablosu, bir problemi sayısal tasarıma dökmek ve sadeleştirmek için kullanılır. Ardışıl devrelerde bunun yerini **durum tablosu** alır. Durum tablosunun içinde yine bir doğruluk tablosu vardır; tek farkı şimdiki ve sonraki olmak üzere iki tür durumun bulunmasıdır.

- Tablonun sol tarafı (doğruluk tablosundaki girişler gibi): şimdiki durumlar ve o anki dış girişler (bir butona basmak, bir tetikleme sinyali vermek gibi).
- Sağ tarafı (doğruluk tablosundaki $F$ gibi): bir sonraki durumlar ve çıkışlar.
- Sonraki durum $A(t+1)$ ya da kesme işaretiyle $A'$ diye gösterilir.

### 6.3 Örnek: 0'dan 7'ye sayan devre

Slayttaki soru (ekrandan, 00:45:00): "0'dan 7'ye sayan ve çıkışını tek sayılarda lojik 1 yapan bir ardışıl devrenin durum tablosunu oluşturunuz." 7'ye kadar sayıldığı için durumlar 3 bitle ($A$, $B$, $C$) gösterilir.

| $A$ | $B$ | $C$ | $A'$ | $B'$ | $C'$ | $Z$ |
|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 1 | 1 |
| 0 | 0 | 1 | 0 | 1 | 0 | 0 |
| 0 | 1 | 0 | 0 | 1 | 1 | 1 |
| 0 | 1 | 1 | 1 | 0 | 0 | 0 |
| 1 | 0 | 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 1 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 0 | 0 | 0 | 0 |

Hocanın anlatımıyla: 0'dan 1'e geçilir ve 1 tek olduğu için çıkış yanar; 1'den 2'ye geçişte yanmaz; 2'den 3'e geçişte yine yanar. Tablodaki $Z$ sütunu, gidilen sonraki durumun tek olduğu satırlarda 1'dir (python ile denetlendi).

> **Hocanın vurgusu:** Bu tabloyu oluşturmak çok önemlidir; soruyu doğru anlayıp anlamadığımız bu tabloda görülür. Devre tasarımı da tablodaki 1'lerin karşılığıdır.

Devre kurulurken $A'$ sütunundaki 1'ler için bir Karnaugh haritası, $B'$ için başka, $C'$ için başka ve $Z$ için başka bir Karnaugh haritası yapılır. Her haritadan sadeleşmiş bir Boole fonksiyonu çıkar ve devre flip-floplarla kurulur.

### 6.4 Denklemlerden durum tablosu

Bazen soru sözel değil, doğrudan Boole denklemleriyle verilir: örneğin $A(t+1)$ hem $A$'ya, hem $B$'ye, hem de dış giriş $x$'e bağlı bir fonksiyon olarak; $B(t+1)$ ve çıkış $y$ için de ayrı fonksiyonlar. Bu durumda doğruluk tablosundaki gibi her $A$, $B$, $x$ kombinasyonu için $A(t+1)$, $B(t+1)$ ve $y$ hesaplanır.

Aynı tablonun daha okunaklı bir gösterimi de vardır: dış giriş $x$ sütun başlığına taşınır ve her şimdiki durum için "$x = 0$ iken sonraki durum" ile "$x = 1$ iken sonraki durum" yan yana yazılır. Hoca bu gösterimin bazı şeyleri daha net gördürdüğünü söyler. Slayttaki örnekte, butona basılmadığında ($x = 0$) her saat darbesinde devrenin 0 durumuna kilitlendiği, butona basıldığında ise durum değiştirdiği bir davranış anlatılır.

<!-- BELİRSİZ: 00:46-00:47 arasındaki denklemli durum tablosu örneğinin ve 00:56-00:57 arasındaki denklemden çizilen 8 durumlu diyagramın karesi yok. Altyazıda geçişler kısmen "0→1→2→3→4→0, 5→1, 6→2, 7→4, çıkış 4'te" diye okunuyor ama denklemler ve tablo değerleri doğrulanamadı. -->

## 7. Durum diyagramları

### 7.1 Bileşenler

Durum tablosunun yanında problemi kavramak için **durum diyagramı** da çizilir. Slayttaki tanım (ekrandan, 00:50:00):

- Her durum için içine durum adı yazılmış bir **çember**.
- Her durum geçişi için şimdiki durumdan sonraki duruma giden **yönlü bir ok**.
- Her okun üzerinde geçişe yol açan **giriş** değeri.
- Çıkış için bir etiket: ya her çemberin üzerinde (Moore) ya da her okun üzerinde (Mealy).

Hoca tahtaya A'dan B'ye giden, üzerinde $x = 1$ yazan bir ok çizer: dış giriş 1 iken A durumundan B durumuna geçilir. Ok, $t$ anından $t+1$ anına geçişi gösterir.

### 7.2 Mealy ve Moore gösterimindeki fark

Durumlar ve geçişler iki gösterimde ortaktır; değişen, çıkışın nereye yazıldığıdır.

- **Mealy:** çıkış durum ve girişe bağlı olduğu için okun üzerine "giriş/çıkış" biçiminde yazılır. Örneğin A'dan B'ye $x = 1$ ile geçilirken çıkış 0 ise ok üzerinde $x = 1 / y = 0$ yazılır. Hoca bunu $y = f\big(x(t), d(t)\big)$ diye not eder (ekrandan, 00:50:00).
- **Moore:** çıkış yalnız duruma bağlıdır; bu yüzden çemberin içine ya da altına "durum/çıkış" biçiminde yazılır.

Slaytta aynı problemin iki gösterimi karşılaştırılır. Problem: butona basılmadığı ($x = 0$) sürece 0 durumunda kalınsın; butona basıldıkça ilerlensin ve belirli bir adımda LED yansın. Mealy gösteriminde iki durum (0 ve 1) yeterlidir; 1 durumundayken butona basılınca çıkış ok üzerinde 1 yapılır. Moore gösteriminde ise çıkış ancak bir duruma yazılabildiği için "LED yanıyor" bilgisini taşıyan üçüncü bir durum (2) gerekir.

<!-- BELİRSİZ: Mealy/Moore karşılaştırma slaytının karesi yok (00:51-00:54); ok etiketleri altyazıdan tam çıkarılamadı. -->

> **Hocanın vurgusu:** Moore gösteriminde genelde bir durum fazla oluşur. Mealy'de $x = 1$ iken $y = 1$ ve $x = 0$ iken $y = 0$ doğrudan okların üzerine yazılabilir; Moore'da çıkış durumun altına yazıldığı için ayrı bir durum gerekir.

### 7.3 Örnek 1: Hangi tür?

Slayttaki diyagram (ekrandan, 00:55:00) iki durum değişkenli ($A B$) bir makineyi gösterir. Okların etiketlerinden şu durum tablosu çıkar:

| Şimdiki $AB$ | $x = 0$: sonraki / $y$ | $x = 1$: sonraki / $y$ |
|---|---|---|
| 00 | 00 / 0 | 01 / 0 |
| 01 | 00 / 1 | 11 / 0 |
| 11 | 00 / 1 | 10 / 0 |
| 10 | 00 / 1 | 10 / 0 |

**Soru:** Bu gösterim Mealy mi, Moore mu? **Cevap:** Öğrencilerden farklı cevaplar gelir. Doğru cevap **Mealy**'dir: çıkışlar okların üzerinde "x/y" biçiminde yazılmıştır, yani çıkış hem şimdiki duruma hem girişe bağlıdır.

## 8. Şifre (dizi tanıyıcı) örnekleri

Hoca bu tür ardışıl devre sorularında genelde "şifreleme" problemlerinin sorulduğunu söyler. Bir tuş takımından (keypad) gelen 1 ve 0'lardan oluşan bir veri akışı (bit stream) düşünülür; tanımlanmış bir desen (şifre) geldiğinde sistem uyarı verir.

### 8.1 Şifre 1110

Slaytta 1110 şifresi için iki durum diyagramı vardır (ekrandan, 01:00:00): (a) başlangıç durumuna dönen ve (b) çıkışı kilitleyen. Durumlar o ana kadar doğru girilmiş bit sayısıdır.

Önce doğru yol kurulur: 0 durumundan 1 gelince 1'e, 1'den 1 gelince 2'ye, 2'den 1 gelince 3'e geçilir; 3'te 0 gelince şifre tamamlanmıştır ve çıkış 1 yapılır. Sonra ara durumlar düşünülür:

- **3'te 1 gelirse:** dört tane 1 geldi diye sıfırlamak gerekmez. Son üç bit hâlâ 111 olduğu için 3'te kalınır; ne zaman 0 gelirse şifre tamamlanır.
- **1'de ya da 2'de 0 gelirse:** dizi bozulur, 0 durumuna dönülür.
- **0'da 0 gelirse:** 1 gelene kadar 0'da beklenir.

(a) diyagramında (başlangıca dönme) geçişler:

| Durum | $x = 0$ | $x = 1$ |
|---|---|---|
| 0 | 0 / 0 | 1 / 0 |
| 1 | 0 / 0 | 2 / 0 |
| 2 | 0 / 0 | 3 / 0 |
| 3 | 0 / 1 | 3 / 0 |

Şifre bulunduktan sonra başa dönüldüğü için yeni bir 1110 geldiğinde çıkış yeniden 1 olur; burada bir döngü vardır. (b) diyagramında ise 3'te 0 gelince ayrı bir 4 durumuna gidilir; 4'te hangi giriş gelirse gelsin 4'te kalınır ve çıkış hep 1'dir ("-/1"). Bu bir **çıkış kilitleme** devresidir.

> **Ders sonrası not:** Slaytta 0 durumunun kendi üzerindeki döngüsü "1/0" diye yazılmıştır (ekrandan, 01:00:00). Hoca bunun yanlış olduğunu, doğrusunun "0/0" olduğunu söyledi: 1 gelmedikçe 0 durumunda beklenir.

**Soru:** Soldaki devrede de şifre bulununca lamba yanıyor, sağdakinde de; ikisi aynı şey değil mi? **Cevap:** Soldaki devrede lamba yandıktan sonra gelen yanlış bir giriş lambayı söndürebilir, yeniden doğru şifre girilince yine yanar; bir döngü vardır. Sağdaki devre ise şifre bir kez girildiğinde çıkışı kilitler; çıkış artık 0'a düşürülemez.

> **Hocanın vurgusu:** Doğru güzergâhı çizmek kolaydır; ara durumların nasıl davranacağını analiz etmek çok önemlidir.

### 8.2 1101 dizisini tanıyan Mealy makinesi (örtüşmeli)

Daha zor bir örnek **dizi tanıyıcıdır** (sequence recognizer). Tanınacak dizi 1101'dir. Buradaki güçlük **örtüşmedir** (overlapping): 1101101 akışında hem ilk dört bit hem de son dört bit 1101'dir ve ikisi de tanınmalıdır (ekrandan, 01:10:00).

Önce doğru yol kurulur: A'dan 1 ile B'ye, B'den 1 ile C'ye, C'den 0 ile D'ye geçilir; çıkışlar 0'dır. D'de 1 gelince dizi tamamlanır ve çıkış 1 olur. Asıl soru, D'den 1 ile nereye gidileceğidir.

**Soru:** D'den A'ya gidip oradan tekrar B'ye geçilse olur mu? **Cevap:** Hoca bunu dener. 1101 tanınır ve A'ya gidilir. Ama 1101101 akışında ikinci dizinin ilk 1'i, birinci dizinin son 1'idir. A'ya gidilirse bu 1 kaybolur ve ikinci dizi tanınmaz.

**Soru:** Doğrudan B'ye mi gitmesi gerekir? **Cevap:** Evet. D'de gelen son 1, yeni dizinin ilk 1'i sayılır ve B'ye gidilir. Hoca bunu ok üzerinde $x = 1 / y = 1$ olarak yazar. Böylece örtüşme sorunu çözülür.

Ardından ara geçişler tamamlanır (ekrandan, 01:15:00):

- **C'de 1 gelirse:** iki 1 görülmüşken üçüncü bir 1 gelmiştir. Son iki bit hâlâ 11 olduğu için C'de kalınır ($x = 1 / y = 0$). Bir öğrencinin önerdiği "B'de döngü" ya da "A'ya dön" seçenekleri denenir; A'ya dönülürse dizi ilerlemez, C'de kalmak ise 1101 1111 1101 gibi akışlarda da doğru çalışır.
- **B'de 0 gelirse:** dizinin başı iki 1 olduğu için A'ya dönülür.
- **A'da 0 gelirse:** A'da kalınır.
- **D'de 0 gelirse:** 1100 elde edilmiştir; yeni bir diziye iki 1 ile başlamak gerektiği için A'ya dönülür.

Durum tablosu (python ile rastgele dizilerde denetlendi):

| Şimdiki | $x = 0$: sonraki / $y$ | $x = 1$: sonraki / $y$ |
|---|---|---|
| A | A / 0 | B / 0 |
| B | A / 0 | C / 0 |
| C | D / 0 | C / 0 |
| D | A / 0 | B / 1 |

A, B, C, D sayısal değerler değildir; dört durum 2 bitle 00, 01, 10, 11 diye kodlanabilir. Çıkış yalnız D'de $x = 1$ iken 1'dir.

### 8.3 Aynı problemin Moore modeli

Moore modelinde çıkış durumlara yazılır. 1101 tamamlandığında LED'in yanması için ayrı bir E durumu gerekir: A'nın içine 1 yazılırsa A'nın kendi üzerindeki ($x = 0$) durumu belirtilemez. Bu yüzden fazladan bir durum oluşturulur (ekrandan, 01:20:00).

| Şimdiki | $x = 0$ | $x = 1$ | Çıkış $y$ |
|---|---|---|---|
| A | A | B | 0 |
| B | A | C | 0 |
| C | D | C | 0 |
| D | A | E | 0 |
| E | A | C | 1 |

E'den 1 ile C'ye gidilmesi kritiktir: E'ye gelinen son 1 bir 1 sayılmıştır, yeni gelen 1 ile iki 1 elde edilir ve örtüşen 1101 dizisi kaçırılmaz. E'de 0 gelince başa dönülür. Çıkış girişe bağlı olmadığından tabloda yalnız her durumun çıkışı yazılır.

### 8.4 Sıralı şifre tespiti: 011010

Slayttaki soru (ekrandan, 01:25:00): "Kendisine 011010 şeklinde bit dizisi olarak gelen şifreyi çözen ve şifre bulunduğunda çıkışını lojik 1 yapan bir girişli bir çıkışlı **sonlu durum makinesine** ait durum diyagramını çiziniz ve durum tablosunu oluşturunuz." Hoca, flip-flop ve ardışıl devre tasarımında aslında belirli durumlar içinde dönen sonlu durum makineleri geliştirildiğini belirtir.

Önce doğru yol: 0 durumundan $x = 0$ ile 1'e, $x = 1$ ile 2'ye, $x = 1$ ile 3'e, $x = 0$ ile 4'e, $x = 1$ ile 5'e, $x = 0$ ile 6'ya geçilir. 6 kilitli durumdur: hangi giriş gelirse gelsin 6'da kalınır ve çıkış 1'dir ("-/1").

Ara durumlar:

- **0'da 1 gelirse:** şifre 0 ile başladığı için 0 gelene kadar 0'da beklenir.
- **1'de 0 gelirse:** 1'de kalınır. 000011010 gibi bir akışta son 0 dizinin ilk biti olabilir; başa dönülseydi bir 0 daha beklenirdi ve dizi kaçırılırdı.
- **2'de 0 gelirse:** 010 elde edilmiştir; son 0 yeni dizinin ilk 0'ı olabileceği için 1'e gidilir.
- **3'te 1 gelirse:** 0111 diziyi tamamen bozar (dizide 0'dan sonra en fazla iki 1 vardır); 0 durumuna dönülür.
- **4'te 0 gelirse:** 01100'ın son 0'ı yeni dizinin başı olabilir; 1'e gidilir.
- **5'te 1 gelirse:** 011011'in son üç biti 011'dir, yani dizinin ilk üç bitine örtüşür; 3'e gidilir.

| Durum | $x = 0$ | $x = 1$ | Not |
|---|---|---|---|
| 0 | 1 / 0 | 0 / 0 | Başlangıç |
| 1 | 1 / 0 | 2 / 0 | "0" görüldü |
| 2 | 1 / 0 | 3 / 0 | "01" görüldü |
| 3 | 4 / 0 | 0 / 0 | "011" görüldü |
| 4 | 1 / 0 | 5 / 0 | "0110" görüldü |
| 5 | 6 / 0 | 3 / 0 | "01101" görüldü |
| 6 | 6 / 1 | 6 / 1 | Kilitli, çıkış 1 |

Bu geçişler python ile 011010 için en uzun önek-sonek eşleşmesi hesabıyla denetlendi ve slayttaki diyagramla uyuşur.

Hoca bu sorudaki ince noktaya dikkat çeker: 011010'un son 0'ı basıldığı anda LED yanmaz ($5 \to 6$ geçişi "0/0"dır). LED, 6 durumuna gelindikten sonra hangi tuşa basılırsa basılsın yanar. Son 0 basılır basılmaz yanması istenseydi bu okun çıkışı 1 yazılırdı.

Durumlar 3 bitle ($D_2 D_1 D_0$) kodlanır. Devre kurulurken $D_2'$, $D_1'$, $D_0'$ ve çıkış için ayrı ayrı, girişleri $D_2$, $D_1$, $D_0$ ve $x$ olan Karnaugh haritaları yapılır. Sonuç olarak örneğin $D_2(t+1) = D_1 + x$ gibi bir ifade çıkabilir; buradaki $D_1$ ve $x$, $t$ anındaki değerlerdir (hoca bunu yalnız biçim örneği olarak verdi, haritayı çözmedi).

> **Ders sonrası not:** Slayttaki diyagramda $3 \to 4$ geçişinin etiketi "0/1" görünür (ekrandan, 01:25:00). Hocanın anlatımına göre çıkış yalnız 6. durumda 1'dir; bu etiket büyük olasılıkla "0/0" olmalıdır.

> **Ders sonrası not:** Hoca "6 tane durumumuz var" dedi; şifrenin 6 biti için 6 durum ve başlangıç durumu birlikte sayılınca makinede 0–6 arası 7 durum vardır. 7 durum için 3 bit yine yeterlidir.

## 9. Tutucular ve flip-floplar

Aradan sonra saklama birimleri olarak flip-floplara geçilir. Bölüm kapağı "Sequential Circuits: Storage Elements and Sequential Circuit Analysis"tir (ekrandan, 01:50:00). Hoca, MUX örneğindeki geri beslemeli devrenin bir veriyi 1,1 ns gibi kısa bir süre tuttuğunu hatırlatır. Tutucu ve flip-flop devreleri de VE-DEĞİL ya da VEYA-DEĞİL kapılarının birbirini geri beslemesiyle kurulur, ama veriyi uzun süre tutabilir.

### 9.1 SR tutucusu (NAND ve NOR ile)

Set (S) çıkışı 1 yapar, reset (R) 0 yapar.

**NAND ile kurulan $\bar S \bar R$ tutucusu** sıfırda aktiftir; girişlerin üzerindeki "değil" bu yüzdendir.

| $\bar S$ | $\bar R$ | Sonuç |
|---|---|---|
| 0 | 1 | Set: $Q = 1$ |
| 1 | 0 | Reset: $Q = 0$ |
| 1 | 1 | Önceki durum korunur |
| 0 | 0 | Tanımsız (kullanılmaz) |

Örneğin set aktif edilince $Q = 1$, $\bar Q = 0$ olur; ardından 11 verilirse $Q = 1$ saklanır ve bu, girişteki 11 değişene kadar sürer. Saklama, kapı gecikmeleri örneğindeki mantıkla gerçekleşir.

**NOR ile kurulan SR tutucusu** birde aktiftir, çünkü NOR, NAND'in tümleyenidir.

| $S$ | $R$ | Sonuç |
|---|---|---|
| 1 | 0 | Set: $Q = 1$ |
| 0 | 1 | Reset: $Q = 0$ |
| 0 | 0 | Önceki durum korunur |
| 1 | 1 | Tanımsız |

Özetle: NAND'li yapıda 00, NOR'lu yapıda 11 tanımsızdır.

> **Ders sonrası not:** Hoca NAND'li tutucuyu anlatırken önce "RS 1-1 veriliyorsa bu hatalı" dedi, sonra 11'in önceki durumu sakladığını ve 00'ın çalışmayan durum olduğunu söyledi (01:52:17–01:53:09). Doğrusu ikincisidir: $\bar S \bar R$ tutucusunda 11 saklar, 00 tanımsızdır.

### 9.2 SR tutucusunun zamanlama diyagramı

NOR'lu SR tutucusunun zamanlama diyagramında (ekrandan, 01:55:00) $S$, $R$, $Q$ ve $\bar Q$ (Q_b) 0–80 ns aralığında gösterilir. $S = 1$, $R = 0$ iken $Q = 1$'dir. $S$ 0'a inip $R$ 1'e çıkınca, kısa bir gecikmeden sonra $Q$ sıfırlanır. İkisi de 0 olduğunda $Q$ önceki değerini korur. $S$ yeniden 1 yapılınca $Q$ 1 olur; sonraki 00 aralığında yine önceki değer korunur; $R = 1$ yapılınca $Q$ 0 olur. $Q$ ve $\bar Q$ değişimleri girişlere göre küçük gecikmelerle oluşur.

Bu tutucular **asenkrondur**: dışarıdan bir tetikleme sinyali olmadan çalışırlar.

### 9.3 Saatli SR tutucusu

Değişimlerin saate bağlı olması için $\bar S \bar R$ tutucusunun önüne, $S$ ve $R$'yi saat ($C$) ile birlikte alan iki NAND kapısı daha eklenir. Saatin tanımlı anında (seviye ya da kenar) SR yapısı az önceki gibi çalışır:

| $S$ | $R$ | $Q(t+1)$ |
|---|---|---|
| 0 | 0 | $Q(t)$ (değişim yok) |
| 0 | 1 | 0 |
| 1 | 0 | 1 |
| 1 | 1 | Tanımsız |

> **Ders sonrası not:** Hoca 11 durumu için "yüksek empedans göstereceğim" dedi (01:57:37). Saatli SR tutucusunda 11 girişi yüksek empedans değil, yasak/tanımsız durumdur; çıkış öngörülemez.

### 9.4 D tutucusu

SR tutucusunun R girişine D'nin tersi bir DEĞİL kapısıyla verilirse **D tutucusu** elde edilir (ekrandan, 02:00:00). D'ye "data" denir; çıkış girişteki veriyi alır:

| $Q$ | $D$ | $Q(t+1)$ | Açıklama |
|---|---|---|---|
| 0 | 0 | 0 | Değişim yok |
| 0 | 1 | 1 | Set |
| 1 | 0 | 0 | Clear (sıfırla) |
| 1 | 1 | 1 | Değişim yok |

$Q(t+1)$, önceki $Q$'ya bakmaz; yalnız $D$'ye eşittir. $D = 0$ verilince iç SR girişlerine reset, $D = 1$ verilince set gider. Tek giriş olduğu için iç SR'ye hiçbir zaman 00 verilemez; slayttaki ifadeyle "belirsiz durum yoktur". Sembolde bir D girişi, bir saat girişi $C$ ve $Q$, $\bar Q$ çıkışları vardır.

> **Ders sonrası not:** Hoca bu yapıya "D tipi flip-flop" dedi; slaytın başlığı "D Latch"tir. Saat seviyesine duyarlı bu yapı bir tutucudur; kenar tetiklemeli olanına D flip-flop denir.

Saatin önemi bir örnekle gösterilir: $Q = 1$ iken $D$ 0'a indirilse bile çıkış hemen değişmez; ancak saatin bir sonraki yükselen kenarında, küçük bir gecikmeyle $Q$ 0 olur. Saat darbesinden önce $D$'de yapılan hiçbir değişiklik çıkışa yansımaz.

Hoca bir uygulama sorununa da değinir: 1'den 9'a kadar her butona basışta sayan bir devrede butona ne kadar hızlı basılıp bırakılsa da saat, butona basma süresinden çok daha hızlıdır. Bu yüzden tek basışta birkaç durum atlanabilir (örneğin 1'den doğrudan 4'e).

### 9.5 JK flip-flopu

JK flip-flopu özel ve önemlidir. Tek farkı, SR'deki 11 tanımsızlığını ortadan kaldırmasıdır: $JK = 11$ olduğunda çıkışın tersini alır. $J$ set'e, $K$ reset'e karşılık gelir. Karakteristik tablo (ekrandan, 02:10:00):

| $J$ | $K$ | $Q(t+1)$ | İşlem |
|---|---|---|---|
| 0 | 0 | $Q(t)$ | Değişim yok |
| 0 | 1 | 0 | Reset |
| 1 | 0 | 1 | Set |
| 1 | 1 | $\bar Q(t)$ | Tümleme |

Karakteristik denklem:

$$Q(t+1) = J\bar Q + \bar K Q$$

### 9.6 T flip-flopu

T flip-flopu "toggle", yani tersine alma flip-flopudur: $T = 0$ iken değişiklik yapmaz, $T = 1$ iken çıkışı tersler.

İki gerçekleme yolu gösterilir:

- **JK ile:** $J$ ve $K$ girişleri birleştirilip $T$'ye bağlanır. $T = 0$ iken $JK = 00$ olur ve $Q$ korunur; $T = 1$ iken $JK = 11$ olur ve $Q$'nun tersi alınır.
- **D flip-flop ve XOR ile:** D flip-flopunun önüne, bir girişi $T$, diğeri çıkış $Q$ olan bir XOR kapısı konur (ekrandan, 02:05:00). Slayttaki gerekçe, D tutucusundaki "1 yakalama" (1s catching) davranışından kaçınmak için kenar tetiklemeli bir D'nin çekirdek olarak kullanılmasıdır.

XOR ile gerçeklemede: $T = 0$ ise XOR çıkışı $Q$'nun aynısıdır, yani $Q(t+1) = Q(t)$. $T = 1$ ise XOR çıkışı $Q$'nun tersidir: $Q = 0$ iken 1, $Q = 1$ iken 0 üretilir ve D bunu çıkışa aktarır. Böylece:

$$Q(t+1) = T \oplus Q(t)$$

> **Ek bilgi (derste anlatılmadı):** "1 yakalama" (1s catching), saat seviyesi aktif olduğu süre boyunca girişte kısa bir 1 darbesi oluşursa bunun çıkışa işlenmesi sorunudur. Ana-uydu (master-slave) yapılarda görülür. Kenar tetiklemeli flip-flop girişi yalnız saat kenarında örneklediği için bu sorundan etkilenmez.

## 10. Karakteristik ve uyarma tabloları

Her flip-flop iki tabloyla tanımlanır:

- **Karakteristik tablo:** girişlere göre bir sonraki durumun ne olacağını verir.
- **Uyarma (excitation) tablosu:** tersten düşünülür; şimdiki durumdan istenen sonraki duruma geçmek için girişlere ne verilmesi gerektiğini gösterir.

### 10.1 D flip-flopu

Karakteristik: $D = 0$ ise $Q(t+1) = 0$, $D = 1$ ise $Q(t+1) = 1$; yani $Q(t+1) = D$. Uyarma: $Q(t+1)$ 0 olacaksa $D = 0$, 1 olacaksa $D = 1$ verilir.

### 10.2 T flip-flopu

Karakteristik: $T = 0$ iken $Q(t+1) = Q(t)$, $T = 1$ iken $Q(t+1) = \bar Q(t)$; denklem $Q(t+1) = T \oplus Q$. Uyarma: $Q(t+1) = Q(t)$ isteniyorsa $T = 0$, $Q(t+1) = \bar Q(t)$ isteniyorsa $T = 1$ verilir.

> **Hocanın vurgusu:** Uyarma tablosu daha önemlidir. Tasarımda durum tablosundaki her sonraki durum biti ayrı bir flip-flopa bağlanır. Örneğin 000'dan 001'e geçişte en sağdaki bit 0'dan 1'e geçiyorsa ve T flip-flopu kullanılıyorsa, o flip-flopun bu satırdaki girişine 1 verilmesi gerekir. Bu tablolar ezberlenmese bile anlamları kavranmalıdır.

### 10.3 SR flip-flopu

Karakteristik: 00 önceki durumu korur, 01 sıfırlar, 10 birler, 11 tanımsızdır. Uyarma tablosu şöyle kurulur:

- **$0 \to 0$:** ya reset yapılmıştır ($SR = 01$) ya da önceki durum korunmuştur ($SR = 00$). İkisinde de $S = 0$'dır; $R$ önemsizdir. Sonuç $S = 0$, $R = X$.
- **$0 \to 1$:** kesinlikle set yapılmıştır ($S = 1$, $R = 0$); SR'de tersleme işlemi yoktur.
- **$1 \to 0$:** kesinlikle reset yapılmıştır ($S = 0$, $R = 1$).
- **$1 \to 1$:** ya önceki durum korunmuş ya da set yapılmıştır; $S = X$, $R = 0$.

| $Q(t)$ | $Q(t+1)$ | $S$ | $R$ |
|---|---|---|---|
| 0 | 0 | 0 | X |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 |
| 1 | 1 | X | 0 |

X değerleri Karnaugh haritasında **don't care** olarak kullanılır.

### 10.4 JK flip-flopu

Uyarma tablosu (ekrandan, 02:10:00):

| $Q(t)$ | $Q(t+1)$ | $J$ | $K$ | İşlem |
|---|---|---|---|---|
| 0 | 0 | 0 | X | Değişim yok |
| 0 | 1 | 1 | X | Set |
| 1 | 0 | X | 1 | Reset |
| 1 | 1 | X | 0 | Değişim yok |

Hocanın açıklaması: $0 \to 0$ geçişinde ya önceki durum korunmuştur ($JK = 00$) ya da reset yapılmıştır ($JK = 01$); bu yüzden $J = 0$, $K = X$. $0 \to 1$ geçişinde ya tersleme ($JK = 11$) ya da set ($JK = 10$) yapılmıştır; bu yüzden $J = 1$, $K = X$.

> **Hocanın vurgusu:** Bu yaklaşımı iyi anlamak gerekir, çünkü sorularda çokça kullanılacaktır.

## 11. Zamanlama diyagramı örnekleri

### 11.1 D ve T flip-flopları

Yükselen kenarda tetiklenen bir D ve bir T flip-flopuna aynı giriş verilir; çıkışlar her yükselen kenarda incelenir.

- İlk kenarda giriş 1'dir. D flip-flopunun çıkışı 1 olur. T flip-flopu $T = 1$ olduğu için önceki 0'ı tersler ve o da 1 olur.
- İkinci kenarda giriş 0'dır. D'nin çıkışı 0'a düşer. T, $T = 0$ olduğu için önceki değeri (1) korur.
- Üçüncü kenarda giriş yine 1'dir. D 1 olur, T ise önceki değerini tersler.

### 11.2 SR ve JK flip-flopları

Set $J$'ye, reset $K$'ye karşılık geldiği için iki flip-flop 00, 01 ve 10 girişlerinde aynı davranır. İlk kenarda $S = J = 1$, $R = K = 0$'dır; iki çıkış da 1 olur. Fark 11 girişinde ortaya çıkar: JK çıkışı tersler, SR için bu durum tanımsızdır. Sonraki 01 girişlerinde iki flip-flop da sıfırlanır.

<!-- BELİRSİZ: D/T ve SR/JK zamanlama diyagramı slaytlarının karesi yok (02:11-02:13); giriş dizileri altyazıdan tam çıkarılamadı. -->

Ana-uydu (master-slave) yapılar bu derste anlatılmadı; hoca konunun örneklerle tamamlanacağını ve ardından kaydedicilere geçileceğini söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:12:30): Bir işlemcinin senkron ardışıl devre olduğunu nereden anlarız?

> **Cevap (derste verildi):** İşlemcinin bir saat frekansı vardır (örneğin 2,8 GHz). Bu, saniyede yaklaşık 2,8 milyar tetikleme darbesi üretebildiğini gösterir; işlemler bu ortak saatle senkronize olur.

**Soru 2** (ekrandan, 00:20:00): 0,5 ns gecikmeli iki girişli bir NAND kapısında $A$ ve $B$ uzun süredir 1'dir. $t = 0$'da $A$ 0'a iner, $t = 0{,}8$ ns'de tekrar 1 olur. Anlık çıkış $F(I)$ ve gecikmeli çıkış $F$ nasıl değişir?

> **Cevap (derste verildi):** $F(I)$: $t = 0$'da 0 → 1, $t = 0{,}8$'de 1 → 0. $F$: $t = 0{,}5$'te 0 → 1, $t = 1{,}3$'te 1 → 0. Her değişiklikten sonra eski değer 0,5 ns saklanır (tablo Bölüm 4.1'de).

**Soru 3** (derste sözlü, 00:22:03): DEĞİL 0,2 ns, VE 0,4 ns, VEYA 0,5 ns gecikmeli; $A$ ile $\bar S$ ve $B$ ile $S$ VE'lenip VEYA'lanan devre hangi hazır tüm devredir? $S$ 1'den 0'a inerken çıkıştaki çentik neden oluşur?

> **Cevap (derste verildi):** 2'ye 1 çoğullayıcıdır ($S = 0$: $Y = A$; $S = 1$: $Y = B$). $S$ 0'a indiğinde $\bar S$ 0,2 ns geç yükselir; bu aralıkta iki VE kapısının da bir girişi 0 olduğundan çıkış kısa bir süre 0'a düşer (glitch). $S$ 0 → 1 geçişinde $B$ yolunun gecikmesi $0{,}4 + 0{,}5 = 0{,}9$ ns'dir.

**Soru 4** (derste sözlü, 00:35:37): Aynı çoğullayıcıda $Y$, $A$ girişine 0,2 ns gecikmeli bir DEĞİL kapısı üzerinden bağlanırsa çıkışta nasıl bir sinyal görülür?

> **Cevap (derste verildi):** $S = 0$ iken çıkış her $0{,}4 + 0{,}5 + 0{,}2 = 1{,}1$ ns'de bir terslenir; devre osilasyon yapan kararsız bir devre olur.

**Soru 5** (ekrandan, 00:45:00): 0'dan 7'ye sayan ve çıkışını tek sayılarda lojik 1 yapan bir ardışıl devrenin durum tablosunu oluşturunuz.

> **Cevap (derste verildi):** Bölüm 6.3'teki tablo: $ABC \to A'B'C'$ bir fazlası (111 → 000), $Z$ sonraki durumun tek olduğu satırlarda 1.

**Soru 6** (ekrandan, 00:55:00): Bölüm 7.3'teki durum diyagramı hangi türdendir?

> **Cevap (derste verildi):** Mealy. Çıkışlar okların üzerinde "x/y" biçiminde yazılıdır; yani çıkış hem duruma hem girişe bağlıdır.

**Soru 7** (ekrandan, 01:00:00): 1110 şifresi için (a) şifre bulunduğunda başlangıca dönen ve (b) çıkışı kilitleyen durum diyagramlarını çiziniz.

> **Cevap (derste verildi):** Bölüm 8.1'deki tablo. (a)'da 3 durumunda 0 gelince çıkış 1 olur ve 0 durumuna dönülür; (b)'de 3'ten 0 ile 4 durumuna gidilir ve 4'te her girişte kalınıp çıkış hep 1 tutulur. Her iki diyagramda 3'te 1 gelince 3'te kalınır; 0'da 0 gelince 0'da kalınır.

**Soru 8** (ekrandan, 01:10:00): 1101 dizisini örtüşmeli tanıyan Mealy makinesinin durum diyagramını tamamlayınız. D durumunda 1 gelince nereye gidilmelidir?

> **Cevap (derste verildi):** D'den $x = 1 / y = 1$ ile B'ye gidilir; C'de 1 gelince C'de kalınır; A, B ve D'de 0 gelince A'ya dönülür (Bölüm 8.2'deki tablo).

**Soru 9** (ekrandan, 01:20:00): Aynı 1101 tanıyıcının Moore modelinin durum tablosunu yazınız.

> **Cevap (derste verildi):** Beş durum gerekir (A–E); çıkış yalnız E'de 1'dir. E'den $x = 1$ ile C'ye, $x = 0$ ile A'ya gidilir (Bölüm 8.3'teki tablo).

**Soru 10** (ekrandan, 01:25:00): Kendisine 011010 şeklinde bit dizisi olarak gelen şifreyi çözen ve şifre bulunduğunda çıkışını lojik 1 yapan, bir girişli bir çıkışlı sonlu durum makinesine ait durum diyagramını çiziniz ve durum tablosunu oluşturunuz.

> **Cevap (derste verildi):** Bölüm 8.4'teki tablo. 7 durum (0–6), 3 bitle kodlanır; 6 kilitli durumdur ve çıkış yalnız orada 1'dir.

## Dersin Toparlaması

Bu derste ardışıl devrelerin genel yapısı tekrar edildi: kombinezonsal kısım, şimdiki durum ve dış girişlerden hem çıkışları hem de saklama birimine yazılacak sonraki durumu üretir. Çıkışın yalnız duruma mı (Moore), yoksa durum ve girişe birlikte mi (Mealy) bağlı olduğu iki gösterim arasındaki temel farktır. Senkron devrelerde güncellemeler ortak bir saatle olur; asenkron devrelerde ise girişlerin değişim sırasına bağlıdır. Kapı gecikmeleri üzerinden bir verinin kısa süre nasıl saklanabildiği, çoğullayıcıda glitch'in nasıl oluştuğu ve geri beslemenin bir saklama ya da osilasyon devresi ortaya çıkardığı adım adım gösterildi.

Durum tablosu ve durum diyagramı, ardışıl devre sorularının çözümünde temel araçlardır. Şifre ve dizi tanıyıcı örneklerinde önce doğru yolun çizilmesi, sonra her ara durumda yanlış bit geldiğinde nereye gidileceğinin ve örtüşmelerin dikkatle analiz edilmesi gerektiği vurgulandı. Son bölümde SR, D, JK ve T tutucu ve flip-flopları ile bunların karakteristik ve uyarma tabloları anlatıldı. Uyarma tabloları, durum tablosundan flip-floplu devre tasarımına geçişte kullanılacaktır. Hoca bir sonraki derste konunun örneklerle tamamlanacağını ve ardından kaydedicilere geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
