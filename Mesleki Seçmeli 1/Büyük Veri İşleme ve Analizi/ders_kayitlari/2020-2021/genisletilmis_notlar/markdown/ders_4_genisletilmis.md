# Ders 4 Genişletilmiş Notu: Benzer Kümelerin Bulunması: Shingling, MinHashing ve Locality-Sensitive Hashing

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Problem: Büyük Veride Benzer İkilileri Bulmak
- 2. Üç Teknik ve İş Akışı
- 3. Shingling
- 4. Dokümanların Boolean Matrisle Gösterimi ve Jaccard Benzerliği
- 5. MinHashing: İmza Vektörleri
- 6. Şaşırtıcı Özellik: İmza Benzerliği ve Jaccard Benzerliği
- 7. MinHashing'in Pratik Gerçeklenmesi
- 8. Locality-Sensitive Hashing
- 9. Ders Sonu Soru-Cevap
- Örnek Sorular
- Dersin Toparlaması

## 1. Problem: Büyük Veride Benzer İkilileri Bulmak

Dersin konusu, büyük ölçekli veride birbirine benzeyen ikilileri bulmaktır (finding similar sets / finding similar items). Kaynak, dersin kitabı olan *Mining of Massive Datasets* (Leskovec, Rajaraman, Ullman) kitabının 3. bölümüdür. Bölümün slaytları dört başlıkla açılır: uygulamalar, shingling, minhashing ve locality-sensitive hashing (ekrandan, 00:10:00). Hoca dersi büyük ölçüde İngilizce anlattı, kritik yerleri Türkçe olarak da tekrar etti.

Burada sözü edilen veri, tek bir bilgisayarın belleğine ya da diskine sığmayacak kadar büyüktür. Bu yüzden HDFS gibi dağıtık bir depolama sisteminde saklanır.

### 1.1 Uygulamalar

Slayta göre birçok veri madenciliği problemi "benzer" kümeleri bulma problemi olarak ifade edilebilir (ekrandan, 00:15:00):

- **Benzer kelimeler içeren sayfalar:** Örneğin web bir ay boyunca taranıp bir milyon sayfa toplanmış olsun. Aynı konu altındaki sayfaları bulmak, sayfaları konuya göre sınıflandırmayı sağlar.
- **Netflix'te benzer zevke sahip kullanıcılar:** Netflix ya da Amazon Prime Video gibi bir film sitesinde kullanıcıların filmlere verdiği puanlar vardır. Sütunları kullanıcılar, satırları filmler olan bir matris kurulabilir. Sütun vektörleri karşılaştırılarak benzer filmleri izleyip benzer puan veren kullanıcılar bulunur. Bu, öneri sistemlerinin temelidir.
- **İkizi (dual): benzer izleyici kitlesine sahip filmler:** Aynı problem ters yönden de ele alınabilir. Bu kez satırlar karşılaştırılarak aynı kategoriye giren filmler (aksiyon filmleri, tarihî filmler vb.) bulunur. <!-- BELİRSİZ: 00:15:20-00:16:00 arasındaki anlatım altyazıda bozuk (Whisper tekrarı); bu kısım slayttan ve 00:16:05'teki cümleden kuruldu. -->
- **Varlık çözümleme (entity resolution):** Bir kişinin Facebook, Instagram, LinkedIn gibi farklı sosyal medya sitelerinde profilleri vardır. Milyonlarca kişinin profil bilgisi elimizde olsun. Benzer küme bulma yöntemleri uygulanarak birbirine benzeyen ve aslında tek bir kişiye ait olan profiller bulunur.

Bunlara ek olarak benzer dokümanlarla ilgili uygulamalar da vardır. Slayta göre amaç, örneğin web gibi bir doküman topluluğunda ortak metni çok olan doküman ikililerini bulmaktır (ekrandan, 00:20:00):

- **Ayna siteler (mirror sites) ya da yaklaşık aynalar:** Bir sayfanın içeriği başka bir URL'de, başka bir uygulama sunucusunda kopyalanmış olabilir. Arama motoru sonuçlarda ikisini birden göstermek istemez. Bu yüzden ayna siteleri önceden bulur ve sonuçta bunlardan yalnız birini gösterir.
- **İntihal (plagiarism), uzun alıntılar dahil:** Birinin başkasının çalışmasını kendi çalışmasıymış gibi yayımlamasıdır. Örneğin bir milyon makale içinde birbirine benzeyenleri bulmak için benzer küme bulan bir uygulama gerekir.
- **Birçok haber sitesindeki benzer haberler:** Bir ajansın yayımladığı haber, diğer haber siteleri tarafından hemen alınıp kendi sitelerinde yayımlanır. Bu haberleri "aynı hikâye"ye göre kümelemek de aynı problemdir.

## 2. Üç Teknik ve İş Akışı

Problemi çözmek için üç teknik öğrenilir:

1. **Shingling:** Verilen veriyi kümeler cinsinden temsil etmeye yarar.
2. **MinHashing:** Büyük kümeleri, aralarındaki benzerliği koruyarak kısa imzalara (signatures) dönüştürür.
3. **Locality-Sensitive Hashing (LSH):** Dokümanları birbiriyle hiç karşılaştırmadan, benzer olma olasılığı yüksek olan aday ikilileri bulur. Gerçek karşılaştırma yalnız bu adaylar arasında yapılır.

Bu teknikler bir iş akışı olarak arka arkaya kullanılır ("The Big Picture", ekrandan, 00:25:00):

```text
Doküman --> [Shingling] --> [Minhashing] --> [Locality-sensitive Hashing] --> Aday ikililer
                 |                |
                 v                v
   dokümanda geçen      İmzalar: kümeleri temsil eden
   k uzunluklu          ve benzerliklerini yansıtan
   dizgilerin kümesi    kısa tamsayı vektörleri

Aday ikililer: benzerliği test edilmesi gereken imza ikilileri
```

İş akışının girdisi büyük ölçekli doküman topluluğudur. İlk adımda her doküman, içinde geçen $k$ uzunluklu dizgilerin kümesine dönüştürülür; bu dizgilere shingle denir. İkinci adımda büyük shingle kümeleri yerine her doküman için kısa bir tamsayı dizisi, yani imza kullanılır. Üçüncü adımda imzalar üzerinde bir işlem yapılarak benzer olma olasılığı yüksek aday ikililer bulunur. En sonunda yalnız aday ikililerin gerçek uzaklığı (benzerliği) hesaplanır.

## 3. Shingling

### 3.1 k-shingle tanımı

Bir doküman için $k$-shingle, dokümanda art arda geçen $k$ karakterlik bir dizidir. Dokümanın ilk harfinden son harfine kadar ilerlenir ve bitişik $k$ karakter alınır.

Hocanın örneği: dokümanın beş harfi olsun ve $k = 2$ olsun. Hocanın sözlü anlatımına göre doküman `abcab` biçimindedir (ara adım eklendi: harf dizisi anlatımdan kuruldu). İlk iki harf `ab` birinci eleman, sonraki iki harf `bc` ikinci eleman, `ca` üçüncü elemandır. Dördüncü ikili yine `ab`'dir, ama kümede bir eleman yalnız bir kez bulunabildiği için tekrar yazılmaz:

$$
\text{abcab} \;\rightarrow\; \{ab,\ bc,\ ca\}
$$

Böylece doküman bir kümeyle temsil edilmiş olur. Her shingle'ın uzunluğu 2 olduğu için bu bir 2-shingle kümesidir.

Slayttaki örnekte "The dog which chased the cat" cümlesi 3-shingle'lara ayrılır: ilk harften başlanarak `The`, sonra `he_` (boşluk dahil), sonra `e_d` diye devam edilir ve `cat`'e kadar bütün bitişik üçlüler alınır.

### 3.2 Shingle'lar ve benzerlik sezgisi

Sezgi şudur: iki dokümanın $k$-shingle kümelerinde ortak eleman çoksa bu dokümanlar birbirine benzerdir. Slayttaki maddeler (ekrandan, 00:30:00):

- Sezgisel olarak benzer dokümanların birçok ortak shingle'ı olur.
- Bir kelimeyi değiştirmek yalnız o kelimeye $k$ uzaklıktaki $k$-shingle'ları etkiler.
- Paragrafların sırasını değiştirmek yalnız paragraf sınırlarını geçen $2k$ shingle'ı etkiler.

**Örnek (ekrandan, 00:30:00):** $k = 3$, "The dog which chased the cat" ile "The dog that chased the cat" karşılaştırılıyor. "which" çıkarılıp yerine "that" yazılınca birinci cümleden yalnız şu 7 shingle değişir (`_` boşluğu gösterir):

$$
\texttt{g\_w},\ \texttt{\_wh},\ \texttt{whi},\ \texttt{hic},\ \texttt{ich},\ \texttt{ch\_},\ \texttt{h\_c}
$$

Geri kalan 3-shingle'lar aynı kalır. Dolayısıyla bir kelime güncellense ya da paragraflar yeniden sıralansa bile değişmesi gereken shingle sayısı toplam shingle sayısına göre küçük kalır ve iki dokümanın benzer olduğu yine yakalanır.

> **Ek bilgi (derste anlatılmadı):** Python ile sayıldığında (boşluk `_` alınarak) birinci cümlenin 25 farklı 3-shingle'ı vardır. Birinci cümleden slayttaki 7 shingle çıkar; ikinci cümlede `g_t`, `tha`, `hat`, `at_`, `t_c` olmak üzere 5 yeni shingle oluşur (`_th` zaten "the" kelimesinden dolayı iki cümlede de vardır). İki cümlenin 18 ortak shingle'ı, birleşimde 30 shingle'ı vardır; Jaccard benzerlikleri $18/30 = 0{,}6$'dır.

### 3.3 k değerinin seçimi

$k$ küçük seçilirse (örneğin 2) iki doküman arasında eşleşen shingle sayısı çok yüksek olur. Çünkü `ab`, `bc` gibi ikililer dokümanların çoğunda geçer. Bu yüzden $k$ genellikle yeterince büyük seçilir; hoca örnek olarak 10 değerini verdi. Böylece dokümanlar arasında gereksiz yere ortak shingle sayısı artmaz. <!-- BELİRSİZ: 00:32:53'teki cümlenin başı altyazıda bozuk; "genellikle 10 gibi bir değer" anlamı bağlamdan çıkarıldı. -->

### 3.4 Sıkıştırma: token'lar

$k$ büyük seçilince shingle'lar uzar ve bellekte gereğinden fazla yer kaplar. Çözüm, her shingle'ı bir tamsayıyla temsil etmektir. Slayttaki maddeler (ekrandan, 00:35:00):

- Uzun shingle'ları sıkıştırmak için örneğin 4 bayta hash'leyebiliriz. Bunlara **token** denir.
- Doküman, token'larıyla, yani $k$-shingle'larının hash değerlerinin kümesiyle temsil edilir.
- İki doküman (nadiren) ortak shingle'ları varmış gibi görünebilir; oysa yalnız hash değerleri ortaktır.

Bir tamsayı 4 bayt, yani 32 bittir. Bu yüzden hash fonksiyonu bir shingle'ı $2^{32}$ farklı tamsayıdan birine dönüştürür. Bu yetmezse `int` yerine `long` kullanılabilir; daha çok bayt harcanır ama değer uzayı büyür. Hocaya göre 4 bayt da yeterlidir.

$2^{32}$ büyük bir sayı olduğu için shingle'lar çoğunlukla farklı tamsayılara düşer. Yine de hash fonksiyonu shingle'ları tam dağıtamazsa iki farklı shingle aynı tamsayıya düşebilir. Bu nadir olur ve **yanlış pozitif** (false positive) doğurur: yöntem iki dokümanı benzer olarak işaretler ama gerçekte benzer değildirler. Bunun tersi **yanlış negatif** (false negative) durumudur: yöntem gerçekte benzer olan bir ikiliyi bulamaz ve benzer değil der. Yöntemin parametreleri ikisini de en aza indirecek biçimde seçilir. <!-- BELİRSİZ: 00:36:31-00:36:50 arası altyazı Whisper tekrarıyla bozuk; yanlış pozitif tanımının devamı slayttan ve bağlamdan kuruldu. -->

## 4. Dokümanların Boolean Matrisle Gösterimi ve Jaccard Benzerliği

### 4.1 Doküman bir 0-1 vektörüdür

Shingling ile her doküman bir kümeye dönüştü. Bütün olası $k$-shingle'ların oluşturduğu evrensel küme düşünülürse her doküman bir vektörle de gösterilebilir. Örneğin bütün olası 3-shingle'lar sırayla yazılır; dokümanda geçen 3-shingle'ların yerine 1, geçmeyenlerin yerine 0 konur. Vektörün boyu, olası bütün 3-shingle'ların sayısıdır.

Bu vektörler yan yana konunca bir matris oluşur. Slayttaki tanım (ekrandan, 00:45:00):

- **Satırlar** evrensel kümenin elemanlarıdır (örnek: bütün $k$-shingle'ların kümesi).
- **Sütunlar** kümelerdir (dokümanlar).
- $e$ satırı ve $S$ sütununda 1 bulunur, ancak ve ancak $e$, $S$'nin elemanıysa.
- Sütun benzerliği, sütunların 1 içeren satır kümelerinin Jaccard benzerliğidir.
- Tipik matris seyrektir (sparse).

Matrisin seyrek olmasının nedeni, olası $k$-shingle'ların çoğunun bir dokümanda bulunmamasıdır. Özellikle $k = 10$ gibi büyük bir değer seçilirse matriste az sayıda 1 ve çok sayıda 0 olur.

### 4.2 Jaccard benzerliği

Kümeler arasındaki benzerlik için Jaccard benzerliği kullanılır. İki kümenin Jaccard benzerliği, kesişimlerinin büyüklüğünün birleşimlerinin büyüklüğüne oranıdır:

$$
\text{Sim}(C_1, C_2) = \frac{|C_1 \cap C_2|}{|C_1 \cup C_2|}
$$

Hocanın gösterdiği iki kümeli örnekte kesişimde 3, birleşimde 8 eleman vardı; Jaccard benzerliği $3/8$'dir. Kümeler arasında başka benzerlik ölçüleri de kullanılabilir, ama bu derste Jaccard kullanılır. <!-- BELİRSİZ: 00:43 civarındaki küme şekli karelerde görünmüyor; 3/8 sonucu altyazıdan alındı. 00:43:52 sonrası altyazı bir süre Whisper tekrarıyla bozuk. -->

Sütun vektörleri üzerinde Jaccard benzerliği kolayca hesaplanır: iki sütunun ikisinde de 1 olan satırlar kesişimdir (payda yer alır); en az birinde 1 olan satırlar birleşimdir (paydada yer alır). Hocanın gösterdiği iki sütunlu örnekte ikisinde de 1 olan 2 satır, en az birinde 1 olan 5 satır vardı:

$$
\text{Sim}(C_1, C_2) = \frac{2}{5} = 0{,}4
$$

<!-- BELİRSİZ: Bu iki sütunlu örneğin satır değerleri karelerde görünmüyor; yalnız 2/5 = 0,4 sonucu altyazıdan alındı. -->

### 4.3 Dört satır tipi

İki sütun $C_1$ ve $C_2$ verildiğinde satırlar dört tipe ayrılır (ekrandan, 00:50:00):

| Tip | $C_1$ | $C_2$ |
|---|---|---|
| a | 1 | 1 |
| b | 1 | 0 |
| c | 0 | 1 |
| d | 0 | 0 |

$a$, a tipindeki satırların sayısını gösterir; $b$, $c$, $d$ de benzer biçimdedir. Bu gösterimle:

$$
\text{Sim}(C_1, C_2) = \frac{a}{a + b + c}
$$

Bu, Jaccard benzerliğinin aynısıdır; yalnız satır tipleriyle yazılmıştır. a tipi satırlar kesişimi, a, b ve c tipi satırlar birlikte birleşimi oluşturur. d tipi (iki sütunda da 0 olan) satırlar hesaba girmez.

## 5. MinHashing: İmza Vektörleri

### 5.1 Amaç

Sütun vektörleri çok büyüktür; her doküman için milyonlarca satır olabilir. MinHashing ile yapılmak istenen, iki büyük vektör arasındaki benzerliği bozmadan bu vektörleri daha küçük boyutlu **imza vektörlerine** dönüştürmektir. İmza vektörleri arasındaki benzerlik, orijinal sütun vektörleri arasındaki benzerlikle (yaklaşık) aynı olmalıdır.

### 5.2 Minhash fonksiyonu

Slayttaki tanım (ekrandan, 01:05:00):

- Satırların rastgele permüte edildiğini düşünün.
- **Minhash fonksiyonu** $h(C)$ = (permüte sırada) $C$ sütununun 1 içerdiği ilk satırın numarası.
- Her sütun için bir imza oluşturmak üzere birkaç (örneğin 100) bağımsız hash fonksiyonu kullanın.
- İmzalar başka bir matriste gösterilebilir: **imza matrisi** (signature matrix). Sütunları kümeleri, satırları o sütunun sırasıyla minhash değerlerini gösterir.

Hash fonksiyonu büyük bir sütun vektörünü küçük bir vektöre indirdiği için minhash fonksiyonu adını alır. Fonksiyonun iki aşaması vardır:

1. Sütunun indeks numaralarını alır, bunların rastgele bir permütasyonunu (permuted order) üretir.
2. Permütasyonda 1 numaranın gösterdiği satırdan başlar; sütunda orada 1 var mı diye bakar. Yoksa 2 numaranın gösterdiği satıra geçer ve böyle devam eder. Sütunda ilk 1 görülen satırın permütasyondaki numarasını imzaya yazar.

> **Hocanın vurgusu:** Hoca bu kısmın çok önemli olduğunu söyledi ve örneği İngilizce anlattıktan sonra Türkçe olarak da baştan anlattı.

### 5.3 Örnek

Girdi matrisinin 7 satırı ve 4 sütunu (4 dokümanı) vardır. Yanında üç permütasyon verilmiştir (ekrandan, 01:10:00 ve 01:20:00). Permütasyon sütunlarındaki sayı, o satırın permüte sıradaki numarasıdır.

| Satır | Kahverengi | Sarı | Mor | $C_1$ | $C_2$ | $C_3$ | $C_4$ |
|---|---|---|---|---|---|---|---|
| 1 | 1 | 4 | 3 | 1 | 0 | 1 | 0 |
| 2 | 3 | 2 | 4 | 1 | 0 | 0 | 1 |
| 3 | 7 | 1 | 7 | 0 | 1 | 0 | 1 |
| 4 | 6 | 3 | 6 | 0 | 1 | 0 | 1 |
| 5 | 2 | 6 | 1 | 0 | 1 | 0 | 1 |
| 6 | 5 | 7 | 2 | 1 | 0 | 1 | 0 |
| 7 | 4 | 5 | 5 | 1 | 0 | 1 | 0 |

**Mor permütasyon (birinci hash fonksiyonu), adım adım:**

- $C_1$: Permütasyon numarası 1 olan satır 5. satırdır; $C_1$'de orada 0 var. Numara 2 olan satır 6. satırdır; orada 1 var. İmzaya 2 yazılır.
- $C_2$: Numara 1 olan 5. satırda 1 var. İmzaya doğrudan 1 yazılır.
- $C_3$: 5. satırda 0, 6. satırda 1 var. İmzaya 2 yazılır.
- $C_4$: 5. satırda 1 var. İmzaya 1 yazılır.

**Sarı permütasyon (ikinci hash fonksiyonu):**

- $C_1$: Numara 1 olan 3. satırda 0, numara 2 olan 2. satırda 1 var. İmza 2.
- $C_2$: 3. satırda 1 var. İmza 1.
- $C_3$: Numara 1 (3. satır), 2 (2. satır), 3 (4. satır) gösterdiği yerlerde 0 var; numara 4 olan 1. satırda 1 var. İmza 4.
- $C_4$: 3. satırda 1 var. İmza 1.

Kahverengi permütasyon için de aynı işlem yapılır. Sonuçta imza matrisi şudur (ekrandan, 01:10:00):

| Hash fonksiyonu | $C_1$ | $C_2$ | $C_3$ | $C_4$ |
|---|---|---|---|---|
| Mor | 2 | 1 | 2 | 1 |
| Sarı | 2 | 1 | 4 | 1 |
| Kahverengi | 1 | 2 | 1 | 2 |

Değerler Python ile yeniden hesaplandı ve slayttaki imza matrisiyle aynı çıktı.

Örnekte 3 hash fonksiyonu kullanıldığı için imza matrisinin 3 satırı vardır. 100 bağımsız hash fonksiyonu kullanılsaydı imza sütunlarının 100 satırı olurdu. Sütun sayısı değişmez, çünkü her sütun bir dokümanı temsil eder: girdi matrisinde 4 doküman varsa imza matrisinde de 4 doküman vardır. Değişen yalnız satır sayısıdır; satır sayısı hash fonksiyonu sayısına eşit olur. MinHashing'in nedeni de budur: milyonlarca satırlık sütun vektörleri yerine her doküman küçük bir vektörle temsil edilir.

## 6. Şaşırtıcı Özellik: İmza Benzerliği ve Jaccard Benzerliği

### 6.1 Özellik

Slayttaki ifade (ekrandan, 01:25:00):

- Satırların bütün permütasyonları üzerinden $h(C_1) = h(C_2)$ olma olasılığı $\text{Sim}(C_1, C_2)$ ile aynıdır.
- İkisi de $a/(a+b+c)$'dir.
- Neden? Permüte edilmiş $C_1$ ve $C_2$ sütunlarında 1 görene kadar aşağı inin. Bu bir a tipi satırsa $h(C_1) = h(C_2)$ olur. b ya da c tipi bir satırsa olmaz.

$$
P\big[h(C_1) = h(C_2)\big] = \text{Sim}(C_1, C_2) = \frac{a}{a+b+c}
$$

### 6.2 İmza benzerliği

İki imzanın benzerliği, imzaların aynı değeri aldığı minhash fonksiyonlarının oranıdır: aynı olan satır sayısı bölü toplam satır sayısı.

**Örnek (ekrandan, 01:20:00):**

- **Sütun 1 ve 3:** İmza matrisinde mor satırda 2 = 2, kahverengi satırda 1 = 1 aynıdır; sarı satırda 2 ≠ 4. İmza benzerliği $2/3 \approx 0{,}67$. Girdi matrisinde a tipi satır sayısı 3 (1., 6. ve 7. satırlar), a + b + c = 4 (2. satır b tipidir). Jaccard benzerliği $3/4 = 0{,}75$.
- **Sütun 2 ve 4:** İmza matrisinde üç satır da aynıdır (1 = 1, 1 = 1, 2 = 2). İmza benzerliği $3/3 = 1{,}00$. Girdi matrisinde a tipi satır 3 (3., 4. ve 5.), a + b + c = 4. Jaccard benzerliği $0{,}75$.
- **Sütun 1 ve 2:** İmza matrisinde aynı olan satır yoktur; imza benzerliği 0. Girdi matrisinde a tipi satır yoktur; Jaccard benzerliği de 0.

| | 1-3 | 2-4 | 1-2 |
|---|---|---|---|
| Sütun/Sütun (Jaccard) | 0,75 | 0,75 | 0 |
| İmza/İmza | 0,67 | 1,00 | 0 |

Bu değerler de Python ile doğrulandı. İmza benzerliği gerçek benzerliğin kendisi değildir, bir yaklaşımdır; ama gerçek benzerlikten uzak değildir. Yani büyük vektörler minhashing ile küçük vektörlere dönüştürüldüğünde, imza matrisindeki iki vektörün benzerliği girdi matrisindeki iki vektörün benzerliğine yaklaşık olarak eşit kalır. İki imzanın beklenen benzerliği, temsil ettikleri iki sütunun Jaccard benzerliğine eşittir.

## 7. MinHashing'in Pratik Gerçeklenmesi

### 7.1 Permütasyonun sorunu

Her dokümanın bir milyar satırı olduğunu düşünelim. Yukarıdaki minhash fonksiyonu iki aşamalıdır: önce permütasyon üretir, sonra permütasyonda sırayla ilerleyip dokümanda 1 olan ilk satırı bulur. Bu kadar çok satır için her minhash fonksiyonunun permütasyonunu üretmek çok bellek ister ve zaman alır. Bu yüzden hesaplaması kolay başka bir minhash fonksiyonu kullanılır; aynı fikir bu fonksiyonla da uygulanır. Permütasyon yerine satır numarasını karıştıran basit hash fonksiyonları kullanılır.

### 7.2 Örnek

Örnekte iki sütun ve iki hash fonksiyonu vardır (ekrandan, 01:30:00 ve 01:35:00):

| Satır | $C_1$ | $C_2$ |
|---|---|---|
| 1 | 1 | 0 |
| 2 | 0 | 1 |
| 3 | 1 | 1 |
| 4 | 1 | 0 |
| 5 | 0 | 1 |

$$
h(x) = x \bmod 5, \qquad g(x) = (2x+1) \bmod 5
$$

İki hash fonksiyonu olduğu için imza matrisinin 2 satırı, iki doküman olduğu için 2 sütunu olur. Algoritma başlarken imza matrisindeki bütün değerlere sonsuz ($\infty$) konur. Sonra satırlar sırayla işlenir:

- **Satır 1:** $h(1) = 1$, $g(1) = 3$ ($2 \cdot 1 + 1 = 3$, $3 \bmod 5 = 3$). $C_1$'de 1 var: $1 < \infty$ ve $3 < \infty$ olduğu için Sig1 = (1, 3). $C_2$'de 0 var; Sig2 = ($\infty$, $\infty$) kalır.
- **Satır 2:** $h(2) = 2$, $g(2) = 0$ ($2 \cdot 2 + 1 = 5$, $5 \bmod 5 = 0$). $C_1$'de 0 var, dokunulmaz. $C_2$'de 1 var: Sig2 = (2, 0).
- **Satır 3:** $h(3) = 3$, $g(3) = 2$. İki sütunda da 1 var. $C_1$ için: $3 < 1$ değil, 1 kalır; $2 < 3$, 2 yazılır. Sig1 = (1, 2). $C_2$ için: $3 > 2$ ve $2 > 0$ olduğu için değişiklik yok, Sig2 = (2, 0).
- **Satır 4:** $h(4) = 4$, $g(4) = 4$. Bu değerler imza matrisindeki bütün değerlerden büyüktür. Dördüncü satırda 1 olsa da olmasa da bir şey değişmez; küçük olan değerler yerinde kalır.
- **Satır 5:** $h(5) = 0$, $g(5) = 1$. $C_1$'de 0 var, Sig1 = (1, 2) kalır. $C_2$'de 1 var: $0 < 2$ olduğu için 0 yazılır; $1 > 0$ olduğu için 0 kalır. Sig2 = (0, 0).

Sonuç: Sig1 = (1, 2), Sig2 = (0, 0). Satır satır izleme Python ile tekrarlandı ve slayttaki değerlerle aynı çıktı.

Bu işlemde hiç permütasyon oluşturulmadı. Eski minhash fonksiyonu önce indeks numaralarının permütasyonunu ister, sonra bu permütasyonda dokümandaki ilk 1'i arardı. Bir dokümanın milyonlarca elemanı olduğunda bu bir sorundur. Burada ise daha az bellek isteyen hash fonksiyonları ve iç içe iki döngüyle, sonsuz başlangıç değerlerinden nihai imza matrisine ulaşıldı.

### 7.3 Sözde kod

Hoca, iç içe iki döngüden oluşan sözde kodu ekranda gösterdi. <!-- BELİRSİZ: Sözde kod slaytı karelerde görünmüyor; aşağıdaki yapı hocanın 01:36:44-01:39:04 arasındaki anlatımından kuruldu. -->

```text
SIG(i, c) = sonsuz          (bütün i ve c için)
her satır r için:                          # dış döngü
    her hash fonksiyonu h_i için h_i(r) hesapla
    her sütun c için:                      # iç döngü
        eğer c sütununda r satırında 1 varsa:
            her i için:
                SIG(i, c) = min(SIG(i, c), h_i(r))
```

Dış döngü satırlar üzerinde döner. Her satırda önce bütün hash fonksiyonlarının o satır numarası için değeri bulunur. İç döngü sütunlar üzerinde döner: sütunda 1 varsa her hash fonksiyonu için hash değeri ile imza matrisindeki ilgili hücrenin değeri karşılaştırılır. Hücredeki değer zaten küçükse dokunulmaz; hash değeri küçükse hücreye yazılır. Bu sözde kodla bir sütun vektörü kolayca imza vektörüne dönüştürülür.

## 8. Locality-Sensitive Hashing

### 8.1 Neden gerekir?

İki vektörün benzer olup olmadığını anlamak için aralarındaki benzerlik değeri hesaplanır; bunun için Jaccard benzerliği öğrenildi. Ama doküman sayısı milyonlar mertebesindeyse milyonun ikili kombinasyonu kadar karşılaştırma gerekir. Bu çok büyük bir sayıdır ve çok zaman alır. Bu yüzden hiçbir ikiliyi benzerlik fonksiyonuna sokmadan, benzer olma olasılığı yüksek olanları tespit eden bir yöntem aranır.

Fikir: bütün elemanların topluluğundan (burada her eleman bir imza vektörüdür), benzerliği değerlendirilmesi gereken küçük bir aday ikili listesi üretmek.

Slayttaki tanım (ekrandan, 01:50:00):

- Bir benzerlik eşiği $t$ seçilir; $t$, 1'den küçük bir orandır.
- İmza matrisi $M$'nin $c$ ve $d$ sütunlarının **aday ikili** (candidate pair) olması istenir, ancak ve ancak imzaları satırların en az $t$ oranında aynıysa.
- Yani en az $t$ oranındaki $i$ değerleri için $M(i, c) = M(i, d)$ olmalıdır.

### 8.2 Bantlar ve kovalar

Yöntem şöyledir (ekrandan, 01:45:00, "Hash Function for One Bucket"):

- İmza matrisi $M$, her biri $r$ satırdan oluşan $b$ banda (band) bölünür.
- Bir bantta her sütunun o banda düşen parçasına hoca **bileşen** (component) dedi.
- Her bantta, her sütunun bileşeni bir hash fonksiyonuna verilir. Hash fonksiyonu bu bileşeni bir tablonun hücrelerinden birine, yani bir **kovaya** (bucket) eşler. Örneğin $2^{32}$ kova varsa hash fonksiyonu bileşenin değerini $2^{32}$ farklı tamsayıdan birine eşler.
- Bu işlem bütün bantlar için yapılır.

Slayttaki şekilde bir bantta 7 sütun vardır ve her sütunun bileşeni kovalara hash'lenmiştir. Şeklin açıklamaları:

- 2. ve 6. sütunlar aynı kovaya düşmüştür: bu bantta büyük olasılıkla aynıdırlar.
- 6. ve 7. sütunlar farklı kovalara düşmüştür: bu bantta kesinlikle farklıdırlar.

İki farklı dokümanın birer bileşeni aynı kovaya düşerse bu dokümanlar birbirine benzer olabilir. Henüz bir karşılaştırma yapılmadı, benzerlik fonksiyonu çağrılmadı; ama aynı kovaya düştükleri için en azından benzerlik açısından bakılmaya değerdirler. Bileşenleri tamamen ayrı kovalara düşen dokümanlar için benzer değildir denir.

**Aday ikililer**, en az bir bantta aynı kovaya hash'lenen ikililerdir. Bütün bantların ayrı ayrı aynı kovaya düşmesi gerekmez; bir dokümandan bir, öbür dokümandan bir bileşenin tek bir bantta aynı kovaya düşmesi yeter.

> **Ders sonrası not:** Hoca anlatımda imza matrisinin "R tane banda" bölündüğünü söyledi. Slayttaki gösterimde bant sayısı $b$, her banttaki satır sayısı $r$'dir.

> **Ders sonrası not:** Hoca anlatım sırasında bir bantta bileşenin "birler ve sıfırlardan oluşan bir ikilik sayı" olduğunu söyledi. Ders sonunda bir öğrencinin sorusu üzerine bunu düzeltti: imza matrisi 0-1 değerlerinden değil, minhash ile bulunan satır numaralarından oluşur (bkz. Bölüm 9).

### 8.3 Yanlış pozitif ve yanlış negatif

Hash fonksiyonu kullanıldığı için birbirine gerçekten benzer olmayan bileşenler aynı kovaya düşebilir. Yöntem bunları karşılaştırılacaklar arasına alır ama gerçekte benzer değillerdir: bu **yanlış pozitiftir**. Tersine, birbirine benzer iki dokümanın hiçbir parçası aynı kovaya düşmeyebilir. Yöntem bunlar için "benzer değil, karşılaştırmaya gerek yok" der ama yanılır: bu **yanlış negatiftir**. $b$ ve $r$ değerleri, yanlış negatif ve yanlış pozitif oranlarını en aza indirecek biçimde seçilir. Bunun için önce bir benzerlik eşiği seçilir, sonra bant sayısı $b$ ve bant başına satır sayısı $r$ belirlenir. <!-- BELİRSİZ: 01:50:05-01:50:32 arası altyazı bozuk; eşik seçimiyle ilgili kısım slayttan kuruldu. -->

### 8.4 Sayısal örnek: 100.000 doküman

Örnek şöyledir: 100.000 sütun (doküman) var ve her dokümanın imzası 100 tamsayıdan oluşuyor. <!-- BELİRSİZ: Hoca önce "1000 sütun" dedi, sonra hesapta 100.000 sütun kullandı; bu örneğin slaytı karelerde görünmüyor. Hesap 100.000 ile tutarlıdır. -->

- Bir tamsayı 4 bayt olduğuna göre bir imza $4 \times 100 = 400$ bayttır.
- 100.000 sütun için imza matrisi $400 \times 100.000 = 40.000.000$ bayt, yani 40 MB yer kaplar. Bu küçüktür ve belleğe sığar.
- Sorun karşılaştırma sayısıdır: $\binom{100.000}{2} = 4.999.950.000 \approx 5$ milyar ikilinin Jaccard benzerliğiyle karşılaştırılması gerekir. Bu çok zaman alır.

Bu yüzden LSH ile önce benzer olma olasılığı yüksek ikililer bulunur ve Jaccard benzerliği yalnız onlar için hesaplanır.

### 8.5 b = 20, r = 5 ve %80 benzerlik

100 tamsayılık imza $b = 20$ banda bölünürse her bantta $r = 5$ tamsayı olur. Benzerlik eşiği %80 seçilsin; yani iki doküman arasındaki benzerlik 0,8 ise bunlara benzer denir. $C_1$ ve $C_2$ %80 benzer olsun (ekrandan, 02:00:00).

**Adım 1: Bir bantta aynı olma olasılığı.** İmzaların bir satırda aynı olma olasılığı 0,8'dir. Bir bandın 5 satırının hepsinin aynı olma (ve aynı kovaya düşme) olasılığı:

$$
(0{,}8)^5 = 0{,}328
$$

Bu, tek başına düşük bir olasılıktır.

**Adım 2: Hiçbir bantta aynı olmama olasılığı.** Belirli bir bantta aynı olmama olasılığı $1 - 0{,}328$'dir. 20 bant olduğuna göre hiçbir bantta aynı kovaya düşmeme olasılığı:

$$
(1 - 0{,}328)^{20} \approx 0{,}00035
$$

Yani %80 benzer kümelerin yaklaşık 3000'de 1'i yanlış negatif olur: gerçekte benzer oldukları halde yöntem onları aynı kovaya düşürmez. Geri kalan yaklaşık 3000'de 2999'u ise aynı kovaya düşer ve benzer olarak bulunur.

> **Ders sonrası not:** Hoca bu değeri sözlü olarak 0,0035 diye okudu. Slayttaki değer 0,00035'tir; Python ile $(1-0{,}328)^{20} \approx 0{,}000353$ ve $(1-0{,}8^5)^{20} \approx 0{,}000356$ bulunur. Hocanın söylediği "3000'de 1" yorumu da 0,00035 ile tutarlıdır ($1/3000 \approx 0{,}00033$).

Sonuç olarak LSH tabanlı bu yaklaşımla bütün ikilileri karşılaştırmak yerine yalnız aynı kovaya düşmüş ikililer karşılaştırılır. Seçilen değerlerle ($b = 20$, $r = 5$, eşik %80) 3000'de 1 olasılıkla gerçekte benzer olan bir ikili kaçırılır, ama çok yüksek olasılıkla benzer ikililer bulunur ve yapılacak karşılaştırma sayısı çok düşer. Jaccard benzerliği yalnız aday ikililer için hesaplanır ve gerçekten benzer olup olmadıkları ondan sonra kontrol edilir.

## 9. Ders Sonu Soru-Cevap

**Soru:** LSH anlatılırken bantlardaki değerlerin birler ve sıfırlardan oluştuğu söylendi. Ama minhashing uygularken satır numaralarını (indisleri) buluyorduk. O zaman imza matrisi birler ve sıfırlardan değil, satır numaralarından oluşmuyor mu?

**Cevap:** Evet, doğru. İmza matrisi 0 ve 1'lerden oluşmaz, satır numaralarından oluşur. Hoca bunu söylerken girdi matrisini düşündüğünü belirtti. Bantlara bölünen imza matrisinin hücrelerinde minhash ile bulunan satır numaraları vardır.

## Örnek Sorular

**1.** (ekrandan, 00:30:00) $k = 3$ için "The dog which chased the cat" ile "The dog that chased the cat" cümleleri karşılaştırılıyor. "which" yerine "that" yazılınca birinci cümlenin hangi 3-shingle'ları değişir?

> **Çözüm:** Slayta göre değişen 3-shingle'lar $\texttt{g\_w}$, $\texttt{\_wh}$, $\texttt{whi}$, $\texttt{hic}$, $\texttt{ich}$, $\texttt{ch\_}$, $\texttt{h\_c}$'dir (7 tane). Geri kalan shingle'lar aynı kalır, bu yüzden iki cümle hâlâ benzer görünür.

**2.** (ekrandan, 01:10:00 ve 01:20:00) Bölüm 5.3'teki 7 × 4 girdi matrisi ve mor (3,4,7,6,1,2,5), sarı (4,2,1,3,6,7,5), kahverengi (1,3,7,6,2,5,4) permütasyonları için imza matrisini bulun. 1-3, 2-4 ve 1-2 sütun çiftleri için Jaccard benzerliğini ve imza benzerliğini karşılaştırın.

> **Çözüm:** İmza matrisi mor satır (2, 1, 2, 1), sarı satır (2, 1, 4, 1), kahverengi satır (1, 2, 1, 2) olur. Jaccard benzerlikleri 1-3 için $3/4 = 0{,}75$, 2-4 için $3/4 = 0{,}75$, 1-2 için 0'dır. İmza benzerlikleri 1-3 için $2/3 \approx 0{,}67$, 2-4 için $3/3 = 1{,}00$, 1-2 için 0'dır. Adımlar Bölüm 5.3 ve 6.2'dedir.

**3.** (ekrandan, 01:30:00) Satırları 1-5 olan $C_1 = (1,0,1,1,0)$ ve $C_2 = (0,1,1,0,1)$ sütunları için $h(x) = x \bmod 5$ ve $g(x) = (2x+1) \bmod 5$ hash fonksiyonlarıyla imzaları hesaplayın.

> **Çözüm:** Başlangıçta bütün değerler $\infty$. Satır 1'den sonra Sig1 = (1, 3); satır 2'den sonra Sig2 = (2, 0); satır 3'ten sonra Sig1 = (1, 2); satır 4 hiçbir şeyi değiştirmez; satır 5'ten sonra Sig2 = (0, 0). Sonuç: Sig1 = (1, 2), Sig2 = (0, 0). Adımlar Bölüm 7.2'dedir.

**4.** (ekrandan, 02:00:00) İmza matrisi $b = 20$ banda, her bant $r = 5$ satıra bölünmüştür. $C_1$ ve $C_2$ %80 benzerse bir bantta aynı olma olasılıkları ve 20 bandın hiçbirinde aynı olmama olasılıkları nedir?

> **Çözüm:** Bir bantta aynı olma olasılığı $(0{,}8)^5 = 0{,}328$. Hiçbir bantta aynı olmama olasılığı $(1-0{,}328)^{20} \approx 0{,}00035$, yani %80 benzer ikililerin yaklaşık 3000'de 1'i yanlış negatif olur.

**5.** (derste sözlü, 02:02:40) LSH'de bantlara bölünen imza matrisi 0 ve 1'lerden mi oluşur?

> **Çözüm:** Hayır. İmza matrisinin hücrelerinde minhash ile bulunan satır numaraları vardır; 0-1 değerleri girdi (Boolean) matrisine aittir.

## Dersin Toparlaması

Bu derste büyük veride benzer ikilileri bulmanın üç adımlı yolu işlendi. Önce dokümanlar shingling ile $k$-shingle kümelerine dönüştürüldü; benzer dokümanların ortak shingle'larının çok olduğu, kelime değişikliği ya da paragraf sırasının yalnız az sayıda shingle'ı etkilediği görüldü. Kümeler satırları shingle'lar, sütunları dokümanlar olan seyrek bir Boolean matrisle gösterildi ve sütun benzerliği Jaccard benzerliği, yani $a/(a+b+c)$ olarak tanımlandı. MinHashing ile bu büyük sütunlar, sütun sayısı korunarak hash fonksiyonu sayısı kadar satırı olan bir imza matrisine indirildi. İki sütunun minhash değerlerinin aynı olma olasılığının Jaccard benzerliğine eşit olduğu, bu yüzden imza benzerliğinin gerçek benzerliğe yaklaştığı örnekle gösterildi. Permütasyon üretmek pahalı olduğu için uygulamada basit hash fonksiyonları ve iç içe iki döngüyle imza hesaplandı.

Son olarak LSH ile imza matrisi bantlara bölündü ve en az bir bantta aynı kovaya düşen sütunlar aday ikili sayıldı. 100.000 doküman için yaklaşık 5 milyar ikili karşılaştırma yerine yalnız adayların karşılaştırılmasıyla, $b = 20$ ve $r = 5$ seçildiğinde %80 benzer ikililerin yalnız yaklaşık 3000'de 1'inin kaçırıldığı hesaplandı. Hoca bir sonraki derste kitabın 4. bölümüyle devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
