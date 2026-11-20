# Ders 6 Genişletilmiş Notu: Skor Matrisleri, Afin Boşluk Cezası ve Hizalamanın Anlamlılığı; Çoklu Dizi Hizalamaya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dizi Hizalama Varyantlarının Hatırlatılması
- 2. Skor Matrislerine Neden İhtiyaç Var?
- 3. DNA ve Protein Skor Sistemleri
- 4. Amino Asitlerin Özellikleri
- 5. PAM Matrisleri
- 6. BLOSUM Matrisleri
- 7. Nükleik Asit Skor Şeması: Geçiş ve Çaprazlama
- 8. Log-Odds Matrisleri ve DP'de Kullanımı
- 9. Nükleotit Yer Değiştirme Modelleri
- 10. Doğrusal ve Afin Boşluk Cezası
- 11. Dinamik Programlamanın Üstünlüğü ve Sakıncaları
- 12. Hizalamanın Anlamlılığı
- 13. Bayesçi İstatistiğe Kısa Bakış
- 14. İkili Dizi Hizalama Programları
- 15. Çoklu Dizi Hizalamaya Giriş

## 1. Dizi Hizalama Varyantlarının Hatırlatılması

Hoca derse, ikili dizi hizalama için önceki derste görülen üç dinamik programlama (DP) varyantını hatırlatarak başladı. Üçü de aynı tablo doldurma mantığına dayanır; farkları başlatma (initialization) ve yineleme bağıntısındadır (ekrandan, 00:10:00).

**Global hizalama (Needleman-Wunsch algoritması).** İlk satır ve ilk sütun boşluk cezasının katlarıyla doldurulur:

$$S_{i,0} = i \cdot w, \qquad S_{0,j} = j \cdot w$$

Her hücrenin değeri üç komşudan gelen değerlerin en büyüğüdür: sol üst çapraz hücre artı iki harfin eşleşme skoru, sol hücre artı boşluk cezası ve üst hücre artı boşluk cezası.

$$S_{i,j} = \max\left[S_{i-1,j-1} + s(a_i,b_j),\ S_{i,j-1} + w,\ S_{i-1,j} + w\right]$$

**Yerel hizalama (Smith-Waterman algoritması).** İlk satır ve sütun sıfırla başlatılır, $S_{i,0} = 0$, $S_{0,j} = 0$. Yineleme bağıntısı globaldekiyle aynıdır, yalnız max içine bir de 0 eklenir:

$$S_{i,j} = \max\left[S_{i-1,j-1} + s(a_i,b_j),\ S_{i,j-1} + w,\ S_{i-1,j} + w,\ 0\right]$$

Hoca bunu "sıfıra sıfırlama" diye anlattı: bu hizalamada hücrelerin negatif olmasına izin verilmez, bir hücrenin alabileceği en küçük değer 0'dır.

**Örtüşme (overlap) hizalaması.** Global ve yerelin bir karışımıdır: "yerel gibi başlar, global gibi devam eder." İlk satır ve ilk sütun sıfırlanır, ama yineleme global hizalamadaki gibidir (0 eklenmez). Literatürde başka varyantlar da vardır.

Hoca bu hatırlatmanın sonunda şu gözlemi yaptı: İkili hizalamada en iyi (optimal) hizalamanın ne olacağı büyük ölçüde seçilen skor şemasına, yani kullanılan metriğe bağlıdır. Dersin ilk yarısı bu yüzden skor şemaları üzerinedir.

## 2. Skor Matrislerine Neden İhtiyaç Var?

İkili hizalamada üç temel parametre kullanılır: eşleşme skoru, uyuşmazlık skoru ve boşluk cezası. Skor sisteminde her sembol çiftine sayısal bir değer atanır. Boşluk için de şimdiye kadar −5, −2 gibi sabit sayılar kullanıldı; ama pratikte boşluklar için de daha iyi yaklaşımlar vardır (bölüm 10).

Slaytta iki tür skor yaklaşımı karşılaştırıldı (ekrandan, 00:15:00):

- **Eşleşme/uyuşmazlık skoru:** Benzer diziler için kötü değildir, ama uzak akraba dizileri göstermez.
- **Olabilirlik (likelihood) matrisi:** Kalıntılara, o yer değiştirmenin doğada bulunma olasılığına göre skor verir. Amino asit dizileri için daha uygundur.

Hocaya göre ikili hizalama, basit eşleşme/uyuşmazlık skorundan çok daha anlamlı skor şemaları gerektirir.

<!-- BELİRSİZ: 00:11:15-00:14:30 arası altyazı halüsinasyon tekrarlarından oluşuyor; bu aralıkta anlatılan ek ayrıntı çıkarılamadı -->

## 3. DNA ve Protein Skor Sistemleri

### 3.1 DNA skor sistemi

DNA skor sistemleri amino asit skor sistemlerinden çok daha basittir, çünkü DNA dizilerinde yalnız dört harf vardır: A, G, C, T. En basit şema ikili (binary) şemadır: kalıntılar (residue) eşleşirse skor 1, eşleşmezse 0. Yani AA = 1, GG = 1, CC = 1, TT = 1, geri kalan her çift 0'dır. Bu bir birim matristir.

### 3.2 Protein skor sistemi

Protein skor matrisinde normalde satırlarda ve sütunlarda 20 amino asidin her biri bulunur. Slaytta matrisin bir parçası ve iki dizinin hizalaması gösterildi (ekrandan, 00:20:00):

```text
Sequence 1   PTHPLASKTQILPEDLASEDLTI
Sequence 2   PTHPLAGERAIGLARLAEEDFGM

      C   S   T   P   A   G   N   D
  C   9
  S  -1   4
  T  -1   1   5
  P  -3  -1  -1   7
  A   0   1   0  -1   4
  G  -3   0  -2  -2   0   6
  N  -3   1   0  -2  -2   0   5
  D  -3   0  -1  -1  -2  -1   1   6

T:G = -2,  T:T = 5,  Score = 48
```

Slayttaki tanım: "Skor matrisi, bir kalıntı çiftinin hizalamada bulunma olasılığını betimleyen değerler tablosudur."

Hoca tablonun nasıl okunduğunu gösterdi. C ile C eşleşirse skor 9, S ile S eşleşirse 4, T ile T eşleşirse 5, P ile P eşleşirse 7'dir. Eşleşmelerin de skoru farklıdır. Uyuşmazlık için de artık sabit bir değer yoktur: örneğin hizalamada T ile G karşı karşıya gelince tablodan −2 alınır. Hizalamanın toplam skoru, her sütundaki çiftin tablodaki değerleri toplanarak bulunur.

> **Ders sonrası not:** Slayttaki matris parçası BLOSUM62 ile birebir aynıdır. Standart BLOSUM62 ile bu boşluksuz hizalamanın sütun skorları python ile toplandığında 46 çıkıyor, slaytta 48 yazıyor. Slayttaki değer büyük olasılıkla farklı bir matris sürümüyle ya da başka bir hesapla bulunmuştur.

## 4. Amino Asitlerin Özellikleri

Bu değerlerin arkasındaki mantık amino asitlerin özellikleridir. Amino asitlerin farklı biyokimyasal ve fiziksel özellikleri vardır ve bu özellikler evrimde birbirlerinin yerine geçebilmelerini etkiler (ekrandan, 00:25:00).

Amino asitler tek bir kimyasal madde grubudur, ama bu grubun içinde alt gruplar vardır. Slayttaki Venn şemasındaki gruplar:

- **Tiny (çok küçük):** Ağırlıkları diğerlerinden çok daha azdır (A, G, S, C gibi).
- **Small (küçük):** Çok küçükleri de içine alan daha geniş grup (P, T, D, N gibi ekler).
- **Aliphatic (alifatik):** I, V, L.
- **Aromatic (aromatik):** F, Y, W, H.
- **Hydrophobic (hidrofobik):** Sudan korkan, suyu sevmeyen amino asitler.
- **Hydrophilic / polar:** Suyu seven amino asitler.
- **Charged (yüklü), positive (pozitif):** K, R, H pozitif; D, E de yüklü grupta.

Benzer özellikteki amino asitlerin yer değiştirmesi daha olasıdır. Hoca bunu mutasyon sıklığı ve kimyasal benzerlikle bağladı: daha benzer amino asitlerin birbirine dönüşmesi daha olasıdır. Bu yer değiştirme sıklıkları sonra log-odds matrislerine çevrilir.

## 5. PAM Matrisleri

### 5.1 Tanım ve kuruluş

PAM, "Percent Accepted Mutations" (yüzde kabul edilmiş mutasyon) kısaltmasıdır. PAM matrisinin birkaç sürümü vardır, derste bazıları kullanılacak. Slayttaki maddeler (ekrandan, 00:30:00):

- Protein ailelerinin global hizalamalarından türetilir. Aile üyeleri en az %85 özdeşlik paylaşır (Dayhoff ve ark., 1978).
- Her protein ailesi için filogenetik ağaç ve atasal diziler kurulur.
- Her amino asit çifti için yer değiştirme sayısı hesaplanır.

Değerleri belirlemek için filogenetik ağaçlar kullanılır; filogenetik ağaçlar derste ileride ayrıca anlatılacak.

### 5.2 PAM1 ve daha büyük uzaklıklar

Sayılan yer değiştirmeler PAM1 matrisini hesaplamakta kullanılır. PAM1 matrisi, bütün amino asit konumlarının ortalama %1'inin değişmesine karşılık gelir. Daha büyük evrimsel uzaklıklar için PAM matrisleri PAM1'den çarpma yoluyla türetilir. Örneğin PAM250, 100 kalıntıda 250 mutasyon demektir.

Matristeki 0 değerleri, o çiftin hizalanma sıklığının rastgele olduğunu gösterir. Diğer değerler, gözlenen sıklığın beklenen sıklığa bölünmesinin logaritmasıdır. Farklı PAM matrisleri farklı evrimsel uzaklıklar için kullanılır.

> **Ek bilgi (derste anlatılmadı):** "Çarpma yoluyla türetme" matris çarpımıdır: PAM1 bir Markov geçiş matrisi gibi düşünülür, PAM250 = (PAM1)$^{250}$ olur.

### 5.3 Dayhoff'un çalışmasının ayrıntıları

Hoca ilerleyen kısımda PAM'ı biraz daha açtı. Bu matrisleri Margaret Dayhoff tanıttı. Matris, yakın akraba protein dizilerinin hizalamalarındaki amino asit yer değiştirmelerini temsil eder:

- 71 protein grubunda yaklaşık 1572 amino asit yer değiştirmesi sayılmıştır; gruplar %85 benzerlik gösterir.
- Kabul edilmiş mutasyonlar proteinin uygunluğunu (fitness) olumsuz etkilemeyen mutasyonlardır.
- Benzer diziler filogenetik ağaçlara yerleştirilir, evrimsel değişimler sayılır.
- Amino asitlerin göreli değişebilirliği (mutability) değerlendirilir.
- 20 farklı amino asit olduğu için 20 × 20'lik bir yer değiştirme matrisi hesaplanır.
- PAM1 matrisinde normalleştirilmiş olasılıklar 10.000 ile çarpılır.

## 6. BLOSUM Matrisleri

BLOSUM, "Blocks Substitution Matrix" (blok yer değiştirme matrisi) kısaltmasıdır. Hoca bu matrisin uzak akraba proteinlerin domainlerinin hizalamalarından türetildiğini, her bloğun her sütunundaki amino asit çiftlerinin sayıldığını anlattı. Slayttaki maddeler (ekrandan, 00:35:00):

- Bloklardaki diziler özdeşlik düzeylerine göre kümelenir.
- Kümeler tek dizi gibi sayılır.
- Farklı BLOSUM matrisleri, kümelemede kullanılan dizi özdeşliği yüzdesine göre farklılaşır.
- Matris adındaki sayı (ör. BLOSUM62'deki 62), matrisi kurmakta kullanılan dizi özdeşliği yüzdesidir.
- Büyük sayı küçük evrimsel uzaklık demektir.

> **Hocanın vurgusu:** Yakın akraba proteinleri karşılaştırırken düşük numaralı PAM, yüksek numaralı BLOSUM kullanılmalıdır. Uzak akraba proteinlerde tersi geçerlidir: yüksek PAM, düşük BLOSUM matrisleri daha iyidir.

<!-- BELİRSİZ: 00:46:18'de altyazı "yüksek BLOSUM düşük PAM'a benzer" gibi bozuk; yukarıdaki eşleştirme slayt ve 00:35:44 anlatımına göre yazıldı -->

### 6.1 BLOSUM62 tablosunun okunması

Slaytta BLOSUM62'nin tamamı gösterildi ve skor matrisinin iki özelliği yazıldı (ekrandan, 00:45:00):

- Skor matrisi, bir kalıntı çiftinin hizalamada bulunma olasılığını betimleyen değerler tablosudur.
- Değerler iki olasılığın oranının logaritmasıdır: (1) bir amino asidin rastgele bulunma olasılığı (köşegen), (2) bir kalıntı çiftinin anlamlı biçimde birlikte bulunma olasılığı.

Tablodaki işaretli örnekler:

- **Kimyasal olarak benzer yer değiştirme pozitiftir:** E ile D arası 2, E ile Q arası 2.
- **Yaygın amino asitlerin ağırlığı düşüktür:** I:I = 4.
- **Nadir amino asitlerin ağırlığı yüksektir:** W:W = 11.

Hoca bu matrisleri kurarken kullanılan özelliklerin amino asitlerin biyokimyasal ve fizikokimyasal özellikleri olduğunu söyledi. BLAST gibi araçlarda kullanılan başka matrislerin de bu temel matrislerin türevleri (interpolasyonları) olduğunu belirtti.

## 7. Nükleik Asit Skor Şeması: Geçiş ve Çaprazlama

Nükleotitlerin özellikleri de aynı değildir. DNA'da iki tür nokta mutasyonu vardır (ekrandan, 00:40:00):

- **Geçiş (transition) mutasyonu, daha yaygın:** pürin ↔ pürin (A ↔ G) ya da pirimidin ↔ pirimidin (T ↔ C).
- **Çaprazlama (transversion) mutasyonu, daha az olası:** pürin ↔ pirimidin (A, G ↔ T, C).

> **Ders sonrası not:** Altyazıda bu kısım bozuk duyuluyor ("pirimidin pirimidine... A G'ye" ve çaprazlama için "pürin pürine"). Doğrusu slayttaki gibidir: geçiş aynı sınıf içinde (A ↔ G, T ↔ C), çaprazlama sınıflar arasında olur.

Buna göre birim matristen daha iyi bir nükleotit skor şeması kurulabilir. Birim matriste A:A = 1, A:G = 0 idi. Yeni şemada her eşleşme 20 alır. Uyuşmazlıklar ise farklı skor alır: A ile G uyuşmazlığı bir geçiş mutasyonudur ve 10 alır; T ile G ya da T ile A gibi çaprazlama uyuşmazlıkları 5 alır.

| | A | G | T | C |
|---|---|---|---|---|
| A | 20 | 10 | 5 | 5 |
| G | 10 | 20 | 5 | 5 |
| T | 5 | 5 | 20 | 10 |
| C | 5 | 5 | 10 | 20 |

(ekrandan, 00:40:00)

Hoca bunu yer değiştirme matrisi (exchange matrix) kavramına bağladı: Bütün yer değiştirmeler eşit değildir; benzer fizikokimyasal özellik ve yapıya sahip olanlar daha kolay yer değiştirir ve bu durumda yer değiştirme olasılığı daha yüksektir.

## 8. Log-Odds Matrisleri ve DP'de Kullanımı

PAM matrisleri log-odds matrislerine çevrilir. Slayttaki adımlar (ekrandan, 00:50:00):

1. Her yer değiştirme için olasılık oranı (odds ratio) hesaplanır: önceki matristeki skorlar alınır ve amino asidin sıklığına bölünür.
2. Oranın $\log_{10}$'u alınır ve 10 ile çarpılır.
3. A'nın B'ye ve B'nin A'ya dönüşmesinin log-odds değerlerinin ortalaması alınır.

Sonuç simetrik bir matristir. Bu şekilde PAM250 log-odds matrisi elde edilir.

Hoca bunun DP'de nasıl kullanılacağını şöyle anlattı: İki dizinin global hizalaması için DP tablosu doldurulurken PAM250 log-odds matrisinin kullanılması istenirse, hücre değerleri bu tablodaki eşleşme ve uyuşmazlık skorlarıyla belirlenir. Örneğin C ile C eşleşmesi için 12, S ile C için 0 alınır; P'li bir çift için de tablodaki negatif değer (−2 gibi) kullanılır. Aynı şey Smith-Waterman için de geçerlidir.

<!-- BELİRSİZ: 00:51:36-00:51:47 arası hangi çift için −2 alındığı altyazıda net değil; o anın karesi yok -->

## 9. Nükleotit Yer Değiştirme Modelleri

DNA skor matrisi yaklaşımlarında geçiş ve çaprazlama türü mutasyonlar ayrı ayrı temsil edilir. Hoca Kimura modelini andı: bu modelde $\alpha$ geçişlerin hızı, $\beta$ çaprazlamaların hızıdır; $\alpha$ ve $\beta$ farklı olabilir.

Slaytta 1 PAM uzaklığına eşdeğer iki nükleotit yer değiştirme matrisi gösterildi (ekrandan, 00:55:00):

```text
A. Nükleotitler arasında düzgün (uniform) mutasyon hızı modeli
        A        G        T        C
A   0.99
G   0.00333  0.99
T   0.00333  0.00333  0.99
C   0.00333  0.00333  0.00333  0.99

B. Geçişlerin çaprazlamalardan 3 kat sık olduğu model
        A        G        T        C
A   0.99
G   0.006    0.99
T   0.002    0.002    0.99
C   0.002    0.002    0.006    0.99
```

Her iki modelde de bir nükleotidin değişmeden kalma olasılığı 0,99'dur (1 PAM = %1 değişim). Düzgün modelde kalan 0,01 üç olası değişime eşit bölünür: $0{,}01/3 \approx 0{,}00333$. 3 kat modelde geçiş (A ↔ G, T ↔ C) 0,006, iki çaprazlamanın her biri 0,002 alır; $0{,}99 + 0{,}006 + 0{,}002 + 0{,}002 = 1$ (ara adım eklendi, python ile doğrulandı).

## 10. Doğrusal ve Afin Boşluk Cezası

Kısa bir aradan sonra hoca hizalamanın üç parametresine (eşleşme skoru, uyuşmazlık skoru, boşluklar) döndü. Eşleşme ve uyuşmazlık için amino asitlerin ve nükleik asitlerin biyofiziksel özelliklerine dayanan daha iyi şemalar görüldü; bunlar daha anlamlı hizalamalar verir. Sırada boşluklar var.

### 10.1 Doğrusal boşluk cezasının sorunu

Şimdiye kadar doğrusal boşluk cezası varsayıldı: bir boşluk varsa sabit bir skor (−2, −3, −5 gibi) kullanılır ve her boşluk aynı cezayı alır. Ama slayttaki gibi (ekrandan, 01:15:00):

> Evrimsel zaman içinde bitişik bir kalıntı bloğunun belirli bir bölgede eklenmiş ya da silinmiş olması daha olasıdır. Örneğin uzunluğu k olan 1 boşluk, uzunluğu 1 olan k boşluktan daha olasıdır.

Yani bir defada birden çok boşluk (bir blok) eklenmiş olabilir. Bu durumda boşlukları temsil etmek için daha iyi bir şema kullanılabilir: ilk boşluk açılışına daha yüksek bir ceza, boşluğu uzatmaya ayrı (daha küçük) bir ceza verilir. Skor şeması çok sayıda küçük boşluğu daha fazla cezalandırmalıdır.

### 10.2 Afin boşluk cezası

Basit afin boşluk cezası şemasında:

- $W(x)$: boşluk cezası,
- $g$: boşluk açma cezası,
- $r$: boşluk uzatma cezası,
- $x$: boşluk uzunluğu.

Uygulamalarda tipik değerler $g = -12$, $r = -4$'tür.

<!-- BELİRSİZ: W(x) formülünün tam biçimi (g + r·x mı, g + r·(x−1) mi) 01:17:16 civarında söyleniyor ama o anın karesi yok -->

> **Ek bilgi (derste anlatılmadı):** Yaygın yazımlardan biri $W(x) = g + r(x-1)$ biçimidir: ilk boşluk konumu açma cezasını, her ek konum uzatma cezasını alır. Bazı kaynaklar $W(x) = g + r\,x$ yazar; iki yazım yalnız $g$'nin tanımında farklıdır.

### 10.3 Afin boşluk cezası ve dinamik programlama

Afin cezayla DP'de tek bir tablo yetmez; üç matris tutulur (ekrandan, 01:20:00):

$$M_{i,j} = \max\left\{
\begin{array}{l}
D_{i-1,j-1} + subst(A_i,B_j)\\
M_{i-1,j-1} + subst(A_i,B_j)\\
I_{i-1,j-1} + subst(A_i,B_j)
\end{array}\right.$$

$$D_{i,j} = \max\left\{D_{i,j-1} - extend,\ M_{i,j-1} - open\right\}$$

Burada M eşleşme (match) matrisi, D silme (delete) matrisi, I ekleme (insert) matrisidir. I de benzer bir formülle hesaplanır (o satır karede görünmüyor). Hoca, hesaplanacak matris sayısı arttığı için DP tablosunu hesaplama probleminin karmaşıklaştığını, bu algoritmanın üzerinde daha fazla durmayacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** D'ye simetrik olarak ekleme matrisi genellikle $I_{i,j} = \max\{I_{i-1,j} - extend,\ M_{i-1,j} - open\}$ biçiminde yazılır. Bu yapı Gotoh algoritması olarak bilinir ve afin cezayı yine $O(mn)$ zamanda çözer.

## 11. Dinamik Programlamanın Üstünlüğü ve Sakıncaları

**Soru:** Şimdiye kadar gördüğümüz dinamik programlamanın üstünlüğü nedir? **Cevap:** Verilen bir skor şeması için iki dizi arasındaki en iyi (optimal) hizalamayı vermeyi garanti eder (ekrandan, 01:25:00).

Her yaklaşımın sakıncaları da vardır. Slayta göre DP yaklaşımlarının iki ana sakıncası, hesap ve bellek yoğun olmalarıdır: şimdiye kadar görülen durumlarda en az $O(n^2)$ bellek, $O(n^2)$ ile $O(n^3)$ arası zaman gerekir. Hoca bellek ihtiyacını geri izlemeyle (traceback) açıkladı: hizalamayı belirlemek için geri izleme yapmak gerekir; eski bütün ara değerler saklanmasa bile en azından diğer hücreleri belirleyen hücre değerleri saklanmalıdır.

### 11.1 Alternatif DP yaklaşımları

Bu sakıncaların etkisini azaltmak için yaklaşımlar vardır (ekrandan, 01:30:00):

- **Doğrusal bellek (linear space) algoritmaları:** Myers-Miller.
- **Sınırlı (bounded / banded) dinamik programlama.**
- **Ewan Birney'nin Dynamite paketi:** DP kodunun otomatik üretilmesi.

Hoca doğrusal bellek yaklaşımını şöyle anlattı: Normal DP'de doldurulacak bütün matris hücreleri vardır. Bu yaklaşımda bütün hücreler hesaplanmaz; doğrusal bir alan belirlenir ve hesaplar bu alanın içinde yapılır.

**Soru:** Böyle bir yaklaşım kullanılırsa ilk maddedeki ("DP en iyi hizalamayı garanti eder") ifade nasıl değiştirilmeli? **Cevap:** "Doğrusal bellek algoritmaları kullanan DP yaklaşımları, verilen skor şeması için iki dizi arasındaki en iyi hizalamayı **verebilir**." Garanti ortadan kalkar.

> **Ders sonrası not:** Hocanın anlattığı "yalnız bir alanın içindeki hücreleri hesaplama" fikri sınırlı (banded) DP'ye uyar ve bu yaklaşım en iyi hizalamayı kaçırabilir. Myers-Miller (Hirschberg tabanlı) doğrusal bellek algoritması ise büyük olasılıkla en iyi hizalamayı yine garanti eder; yalnız belleği $O(n)$'e indirir, bunun için hesabı yaklaşık iki katına çıkarır.

## 12. Hizalamanın Anlamlılığı

Artık ikili hizalama için DP, uygun bir skor şeması ve afin boşluk cezası elimizde. Bir hizalama bulduk. Soru şu: Bulunan hizalama anlamlı (significant) mı?

**Soru:** Bir hizalamanın anlamlılığını nasıl değerlendirirsiniz? **Cevap:** İstatistiksel veri analiziyle; bazı dağılımlar kullanılır. Hizalamanın anlamlılığını değerlendirmede Gumbel uç değer dağılımı (Gumbel extreme value distribution) kullanılmıştır.

### 12.1 Problem

Slayttaki kurgu (ekrandan, 01:35:00): Hizalamanın rastgele oluşma olasılığı belirlenir. Dizi 1'in uzunluğu m, dizi 2'nin uzunluğu n'dir; diziler rastgeledir. Uzunlukları m ve n olan iki dizi bariz biçimde benzer değil ama bir hizalama gösteriyorsa, hizalamanın anlamlılığını değerlendirmek gerekir. Diziler tamamen aynı ya da çok benzerse buna gerek yoktur; ama çoğu durumda böyle değildir.

### 12.2 Gumbel dağılımı ve E-değeri

Rastgele dizilerin hizalama skorları Gumbel uç değer dağılımına uyar. Bu dağılım Gauss dağılımı gibi tam simetrik değildir. Bu dağılımla, skoru en az S olan hizalamaların beklenen sayısı (E-değeri):

$$E = K\, m\, n\, e^{-\lambda S}$$

Burada S skor, m ve n dizi uzunluklarıdır. K ve $\lambda$, skor sistemine ve arka plan kalıntı sıklıklarına bağlı istatistiksel parametrelerdir.

### 12.3 Bit skoru

Normal skor bit skoruna şöyle çevrilir:

$$S' = \frac{\lambda S - \ln K}{\ln 2}$$

Verilen bir bit skoruna karşılık gelen E-değeri çok basittir:

$$E = m\, n\, 2^{-S'}$$

Hoca, nat birimine çevirmenin de benzer olduğunu, yalnız formüllerde 2 yerine $e$ konduğunu söyledi; doğal logaritmanın tabanı $e \approx 2{,}718$'dir. (Altyazıda "2.76" duyuluyor; doğru değer 2,718'dir.)

Bulunan E'den P-değeri, yani skoru en az S olan en az bir hizalamanın bulunma olasılığı hesaplanır:

$$P = 1 - e^{-E}$$

<!-- BELİRSİZ: 01:40:32-01:41:12 arası P-değeri anlatımı altyazıda bozuk; formül, 01:53:34'teki "P = 1 − e^(−E)" ifadesine dayanıyor -->

### 12.4 Anlamlılık eşiği

Skor matrisi bit skorlarına ölçeklenmişse, bir hizalamanın anlamlı olup olmadığı doğrudan belirlenebilir. Tipik bir amino asit skor matrisi için $K \approx 0{,}1$'dir, $\lambda$ ise skor matrisinin değerlerine bağlıdır. PAM ya da BLOSUM matrisi kullanılıyorsa $\lambda$ yeniden hesaplanır. Log-odds matrisi bit birimindeyse anlamlılık eşiği

$$\log_2(m n)$$

bit olarak hesaplanır. Hoca bunu bilgi kuramıyla bağladı: $\log_2 x$ bit cinsinden, $\log_e x$ nat cinsinden bilgi verir.

<!-- BELİRSİZ: 01:41:53'te bit birimli matris için λ'nın değeri ("log e 2" olabilir) altyazıda net değil -->

### 12.5 Anlamlılık örneği

Slayttaki örnek (ekrandan, 01:45:00): PAM250 kullanılarak şu hizalama bulunmuştur.

```text
F W L E V E G N S M T A P T G
F W L D V Q G D S M T A P A G
```

**Verilen:** Dizi uzunlukları $m = n = 250$. PAM250 ile toplam skor $S = 73$.

**Adım 1, skor.** Her sütun için PAM250 tablosundan eşleşme ya da uyuşmazlık değeri alınıp toplanır; sonuç 73'tür. Python ile kontrol: sütun skorları sırasıyla 9, 17, 6, 3, 4, 2, 5, 2, 2, 6, 3, 2, 6, 1, 5; toplam 73.

**Adım 2, eşik.** Anlamlılık eşiği $\log_2(250 \cdot 250) = 16$ bit (tam değer 15,93) (ekrandan, 01:50:00).

**Adım 3, bit'e çevirme.** PAM matrisleri $10\log_{10}x$ biriminde kurulduğu için (bölüm 8) skor önce bit'e çevrilir. $S/(10\log_{10}x)$ ile $10\log_2 x$ arasındaki dönüşüm yapılınca yaklaşık $S' \approx S/3$ bulunur:

$$S' = \tfrac{1}{3} S = \tfrac{1}{3} \cdot 73 = 24{,}333 \text{ bit}$$

(ekrandan, 01:50:00). Hoca bunun basit bir yaklaştırma olduğunu söyledi. Tam dönüşüm katsayısı $\frac{1}{10\log_{10}2} \approx 0{,}332$'dir ve $24{,}25$ bit verir (ara adım eklendi, python ile hesaplandı).

**Sonuç.** Hizalama skoru (24,3 bit) anlamlılık eşiğinin (16 bit) üstünde olduğu için bu hizalama anlamlı bir yerel hizalamadır. Bit skoru 16'dan küçük olsaydı hizalama anlamlı sayılmazdı.

### 12.6 E ve P'nin kestirilmesi

Hoca örneği E ve P değerleriyle sürdürdü. PAM250 skor matrisi kullanıldığında $K \approx 0{,}09$, $\lambda \approx 0{,}229$ olarak kestirilir. Bu parametrelerle:

$$S' = \frac{\lambda S - \ln K}{\ln 2} = \frac{0{,}229 \cdot 73 - \ln 0{,}09}{\ln 2} \approx 27{,}6 \text{ bit}$$

$$E = K m n e^{-\lambda S} = 0{,}09 \cdot 250 \cdot 250 \cdot e^{-0{,}229 \cdot 73} \approx 3{,}1 \times 10^{-4}$$

$$P = 1 - e^{-E} \approx 3{,}1 \times 10^{-4}$$

Bu sayılar python ile hesaplandı.

<!-- BELİRSİZ: λ altyazıda "0.29" duyuluyor; altyazıdaki "3.1 × 10..." sonucu ancak λ = 0,229 ile tutuyor (λ = 0,29 ile E ≈ 3,6×10⁻⁶ çıkar). Bit skorunun altyazıdaki değeri ("8.09 bits") de çözülemedi. Slayt 139'un karesi yok. -->

> **Ders sonrası not:** Hoca sonucu "binde 3 civarı" diye yorumladı. Hesaplanan $3{,}1 \times 10^{-4}$ ise on binde 3'e karşılık gelir. Hoca büyük olasılıkla on binde 3'ü kastetti.

### 12.7 Boşluklu hizalamaların anlamlılığı

Slayttaki maddeler (ekrandan, 01:55:00):

- Boşluklu (gapped) hizalamalar istatistiksel anlamlılığı belirlerken boşluksuz hizalamalarla aynı istatistiği kullanır.
- Ancak boşluklu hizalamalarda $\lambda$ ve K değerleri kolay kestirilemez.

Hoca, rastgeleleştirilmiş dizilerin hizalamalarına bakılarak bazı deneysel kestirimler yapıldığını söyledi. İstatistik biyoenformatikte yaygın kullanılır.

## 13. Bayesçi İstatistiğe Kısa Bakış

İstatistik konusu derste ileride ayrıca ele alınacak, ama hoca şimdiden Bayesçi istatistiğe değindi. İstatistik derslerinden bilindiği gibi Bayesçi istatistik koşullu olasılıklara dayanır; koşullu olasılıklar iki olayın ortak olasılığını türetmekte kullanılır.

Gösterim:

- $P(B \mid A)$: A koşulu doğruyken B'nin olasılığı (koşullu olasılık).
- $P(B)$: B'nin herhangi bir koşula bağlı olmayan olasılığı.
- $P(A,B)$: A ile B'nin birlikte gerçekleşme olasılığı (ortak olasılık).

### 13.1 Örnek

A'nın iki durumu (A1, A2), B'nin iki durumu (B1, B2) olsun. $P(B1) = 0{,}3$ verilsin. B1 ve B2'nin olasılıkları toplamı 1 olmalıdır, bu yüzden $P(B2) = 1 - 0{,}3 = 0{,}7$'dir. Bunlara marjinal olasılık denir.

Bulmak istediğimiz, A1 ile B1'in birlikte gerçekleşme olasılığı $P(A1,B1)$'dir. Slaytın notu: Bu durumda A1 ve A2'nin marjinal olasılıkları eksiktir, bu yüzden marjinal olasılığı hesaplamaya yetecek bilgi yoktur. Ama A1 ve B1'in birlikte gerçekleşmesi hakkında daha fazla bilgi verilirse ortak olasılıklar Bayes kuralıyla türetilebilir (ekrandan, 02:00:00):

$$P(A1,B1) = P(B1)\,P(A1 \mid B1)$$

$$P(A1,B1) = P(A1)\,P(B1 \mid A1)$$

Örneğin devamında $P(A1 \mid B1) = 0{,}8$ verilir. A'nın yalnız iki durumu olduğu için $P(A2 \mid B1) = 1 - 0{,}8 = 0{,}2$'dir. Ayrıca $P(A2 \mid B2) = 0{,}7$ verilirse $P(A1 \mid B2) = 0{,}3$ olur, çünkü toplam 1 olmalıdır. Bunlarla Bayes kuralı kullanılarak A ve B durumlarının bütün ortak olasılıkları hesaplanabilir (hesap için Örnek Sorular bölümüne bakın).

<!-- BELİRSİZ: 02:01:49-02:02:29 arası ortak olasılıkların derste hesaplanan değerleri altyazıda okunmuyor, o anın karesi yok -->

### 13.2 Önsel ve sonsal olasılıklar

Olasılıkta bir diğer kavram sonsal (posterior) olasılıktır. Ortak olasılıkların hesaplanması sonsal olasılıkları verir: bunlar başta bilinmez ve önsel (prior) olasılıklar kullanılarak hesaplanır. Önsel olasılıklar bilinen başlangıç bilgisidir; önsel olasılıklar ve başlangıç bilgisiyle bilinmeyen sonsal olasılıklar bulunur. Bayesçi istatistik biyoenformatikte çok yaygın kullanılır.

## 14. İkili Dizi Hizalama Programları

İkili dizi hizalamaya son bir not olarak hoca bazı programları saydı ve bunların hâlâ kullanılıp kullanılmadığını yakın zamanda kontrol etmediğini, bazen programların eskiyip bırakıldığını, kontrol etmenin öğrencilere kaldığını söyledi:

- **needle:** Global hizalamayı uygular.
- **water:** Yerel (Smith-Waterman) hizalamayı uygular.
- İki dizinin BLAST ile karşılaştırılması.
- NCBI'nin web tabanlı dizi hizalama araçları.
- Genomik diziyi proteinle, ifade edilmiş dizilerle (EST) ve mRNA ile hizalayan araçlar.

<!-- BELİRSİZ: 02:05:50-02:06:08'de program adları altyazıda bozuk ("YS2 genomic to protein", "SPI-V", "RASP genomic"); 02:05:00 karesinde slayt boş, liste animasyonla gelmiş -->

> **Ek bilgi (derste anlatılmadı):** needle ve water, EMBOSS paketinin programlarıdır. Altyazıdaki bozuk adlar büyük olasılıkla GeneWise (genomik–protein), sim4 (EST/mRNA–genomik), Spidey (mRNA–genomik) ve est2genome gibi araçlardır.

## 15. Çoklu Dizi Hizalamaya Giriş

Dersin son bölümünde yeni konuya, çoklu dizi hizalamaya (multiple sequence alignment, MSA) giriş yapıldı. Slayt kapağı: "Introduction to Bioinformatics — Multiple Sequence Alignment" (ekrandan, 02:10:00).

### 15.1 Neden çoklu hizalama?

Hoca ikili dizi hizalamanın çok önemli olduğunu, artık ne olduğunu, nasıl kullanıldığını ve hangi DP varyantının (yerel, global, örtüşme ya da yarı global) ne zaman kullanılacağını bildiğimizi hatırlattı. Ama gerçekte çoğu zaman ikiden fazla dizi hizalanır: farklı dizilerin ne olduğunu, birbirleriyle nasıl ilişkili olduğunu bulmak isteriz. Bu ihtiyaç çoklu dizi hizalama kavramını doğurur.

Konunun planı: MSA kavramı, sonra MSA yöntemleri, yani ilerlemeli (progressive) global hizalama, yinelemeli (iterative) yöntemler ve yerel korunmuş desenlere dayalı hizalama. Hoca baştan şunu belirtti:

> **Hocanın vurgusu:** Bu yöntemlerin hepsi ad hoc yöntemlerdir, en iyi (optimal) yöntemler değildir. Nedeni birazdan tartışılacak.

Motivasyon:

- Benzer genler, benzer ya da aynı işlevi gören türler arasında korunabilir. Elbette burada ikiden çok tür vardır.
- Birçok gen, organizmalar arasında yüksek oranda korunmuş biçimde bulunur.
- Benzer ya da aynı işlevi olan çok sayıda diziyi aynı anda hizalayarak, evrim süresince hangi bölgelerin mutasyona uğradığı hakkında bilgi edinilir.
- Bu bilgi, genin hangi bölge ya da domainlerinin işlevi için kritik olduğunu söyler. İşlevsel genomik büyük ölçüde buna dayanır.
- Bazen dizi olarak benzer genler mutasyona uğrayıp o işlevi göremez hale gelebilir; bu dizilerin çoklu hizalamalarına bakarak dizideki hangi değişikliklerin işlevde değişikliğe yol açtığı anlaşılabilir.

Slayttaki özet (ekrandan, 02:15:00): Çoklu dizi hizalama proteinlerin yapısı ve işlevi hakkında bilgi verir; biyolojik önemi olan dizi domainlerinin ya da motiflerinin bulunmasına yardım eder. Aynı zamanda genler arasındaki evrimsel ilişkileri ortaya çıkarır.

### 15.2 Problemin tanımı ve zorluğu

Çoklu dizi hizalamada fikir, üç ya da daha fazla diziyi alıp en çok sayıda benzer karakter hizalamanın aynı sütununa gelecek şekilde uygun biçimde hizalamaktır. Zorluk, artık birçok farklı eşleşme, ekleme ve silme kombinasyonunun olmasıdır; birkaç farklı diziye bakarken bunların hepsi dikkate alınmalıdır.

**Soru:** İkili hizalamada gördüğümüz en iyi (DP) yaklaşım çoklu hizalamada neden uygulanabilir değil? **Cevap:** Derste sınıftan cevap gelmedi; hoca bunu bir sonraki aşamada tartışacağını söyledi. En iyi algoritma uygulanabilir olmadığı için çoklu dizi hizalamada yaklaşık ya da ad hoc yöntemler kullanılır; bu yüzden elde edilen hizalamalar en iyi olmayabilir.

### 15.3 MSA örneği

Slaytta AlignX programının ekran görüntüsü gösterildi: 8 immünoglobulin dizisinin çoklu hizalaması (ekrandan, 02:20:00). Diziler boşluklar (`-`) kullanılarak hizalanmıştır. İlk iki dizi:

```text
NONAME     VSLTCL-VKGFYPSD-IAVEWESNG--
NONAME#2   VTISCTGTSSNIGS--ITVNWYQQLPG
...
Consensus  VTLSCT VS F  S  V V W  Q PG
```

Pencerenin altında "positives: 59.3%", "identity: 7.4%" değerleri görülür. Hoca, immünoglobulinlerin bağışıklık sisteminin hücrelerinde bulunan bir protein sınıfı olduğunu söyledi.

Hoca örnekteki boşluklar üzerinden önceki konuyu hatırlattı: Uzunluğu 1 olan k boşluk yerine uzunluğu k olan bir boşluk yaklaşımı kullanılabilir. Afin ceza kullanılırsa bloğun ilk boşluğu açma cezası, sonrakiler uzatma cezası olarak sayılır ve hizalamanın skoru böyle belirlenir.

<!-- BELİRSİZ: 02:23:06'da sözlü okunan küçük MSA örneğindeki diziler (N-Y-L-S, N-K-Y-L-S, N-F-S gibi) altyazıda tam çıkarılamadı; o anın karesi yok -->

### 15.4 Filogenetik analizle ilişki

Çoklu dizi hizalama için filogenetik analiz çok önemlidir; ikisi arasında güçlü bir ilişki vardır ve MSA filogenetik analize dayanır. Filogenetik analiz ileride ayrıntılı anlatılacak. Slaytta "Phylogenetic Tree of Life" gösterildi: Bacteria, Archaea ve Eucarya üç ana taksondur (ekrandan, 02:25:00).

Hoca ardından MSA yöntemi seçimi için genel bir blok diyagramından söz etti: diziler uygunsa global hizalama yapılır, bulunan hizalamanın anlamlı olup olmadığı kontrol edilir, sonra dizi sayısının çok olup olmadığına bakılarak yönteme karar verilir.

<!-- BELİRSİZ: 02:25:23-02:27:32 arası blok diyagramın kutuları altyazıda kısmen okunuyor, kare yok -->

### 15.5 MSA yöntem sınıfları

Son on yılda onlarca MSA programı tanıtılmıştır, literatürde çok sayıda vardır. Derste ele alınacak genel sınıflar:

- **Kesin (exact) yöntemler:** Dinamik programlamaya dayanır.
- **İlerlemeli (progressive) hizalama.**
- **Yinelemeli (iterative) hizalama.**
- **İstatistiksel model yaklaşımları.**

Konunun bütünlüğü için bu yöntemler bir sonraki derste anlatılacak.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): Aşağıdaki iki protein dizisinin boşluksuz hizalaması için verilen skor matrisi (BLOSUM62 parçası) kullanılarak T:T, T:G değerleri ve toplam skor nedir?

```text
PTHPLASKTQILPEDLASEDLTI
PTHPLAGERAIGLARLAEEDFGM
```

Cevap (slaytta verildi): T:T = 5, T:G = −2, skor = 48.

> **Çözüm (derste verilmedi):** Standart BLOSUM62 ile sütun skorları 7, 5, 8, 7, 4, 4, 0, 1, −1, −1, 4, −4, −3, −1, −2, 4, 4, 0, 5, 6, 0, −2, 1 olur; toplam 46'dır (python ile hesaplandı). Slayttaki 48 büyük olasılıkla farklı bir matris sürümüne dayanır.

**Soru 2** (ekrandan, 00:40:00): Eşleşmeye 20, geçişe 10, çaprazlamaya 5 veren nükleotit şemasında A:G, T:C ve A:T çiftlerinin skorları nedir, neden?

Cevap (derste verildi): A:G geçiştir (pürin ↔ pürin), skoru 10. T:C geçiştir (pirimidin ↔ pirimidin), skoru 10. A:T çaprazlamadır (pürin ↔ pirimidin), skoru 5. Geçiş daha yaygın olduğu için daha yüksek skor alır.

**Soru 3** (derste sözlü, 01:21:38): Şimdiye kadar gördüğümüz dinamik programlamanın üstünlüğü nedir?

Cevap (derste verildi): Verilen skor şeması için iki dizi arasındaki en iyi hizalamayı garanti eder (ekrandan, 01:25:00). Sakıncası hesap ve bellek yoğun olmasıdır: en az $O(n^2)$ bellek, $O(n^2)$–$O(n^3)$ zaman.

**Soru 4** (derste sözlü, 01:27:17): Doğrusal bellek gibi hızlandırıcı bir yaklaşım kullanılırsa "DP en iyi hizalamayı garanti eder" ifadesi nasıl değiştirilmelidir?

Cevap (derste verildi): "... en iyi hizalamayı verebilir" denmelidir; garanti kalkar.

**Soru 5** (derste sözlü, 01:32:06): Bulunan bir ikili hizalamanın anlamlı olup olmadığını nasıl değerlendirirsiniz?

Cevap (derste verildi): İstatistiksel olarak. Rastgele dizilerin hizalama skorları Gumbel uç değer dağılımına uyar; $E = Kmne^{-\lambda S}$ ile beklenen değer, bit skoruyla da $\log_2(mn)$ eşiği karşılaştırılır.

**Soru 6** (ekrandan, 01:45:00 ve 01:50:00): PAM250 ile FWLEVEGNSMTAPTG / FWLDVQGDSMTAPAG hizalaması bulunmuş, skor 73'tür. Dizi uzunlukları 250 ise hizalama anlamlı mıdır?

Cevap (slaytta verildi): $S' = \tfrac{1}{3} \cdot 73 = 24{,}333$ bit. Eşik $\log_2(250 \cdot 250) = 16$ bit. Skor eşiğin üstünde olduğu için hizalama anlamlı bir yerel hizalamadır. (Skor 73 python ile PAM250'den doğrulandı.)

**Soru 7** (derste sözlü, 01:52:17): Aynı örnekte PAM250 için $K = 0{,}09$ ve $\lambda \approx 0{,}229$ alınırsa E ve P nedir?

> **Çözüm (derste verilmedi):** $E = 0{,}09 \cdot 250 \cdot 250 \cdot e^{-0{,}229 \cdot 73} \approx 3{,}1 \times 10^{-4}$, $P = 1 - e^{-E} \approx 3{,}1 \times 10^{-4}$, bit skoru $(\lambda S - \ln K)/\ln 2 \approx 27{,}6$ (python ile hesaplandı). Derste sonuç "3,1 × 10..." olarak söylendi; tam üs ve λ değeri altyazıda net değil.

**Soru 8** (derste sözlü, 01:57:37): A'nın iki durumu (A1, A2), B'nin iki durumu (B1, B2) var. $P(B1) = 0{,}3$, $P(A1 \mid B1) = 0{,}8$, $P(A2 \mid B2) = 0{,}7$ veriliyor. $P(B2)$, $P(A2 \mid B1)$, $P(A1 \mid B2)$ ve ortak olasılıklar nedir?

Cevap (derste verildi): $P(B2) = 0{,}7$, $P(A2 \mid B1) = 0{,}2$, $P(A1 \mid B2) = 0{,}3$.

> **Çözüm (derste verilmedi):** Bayes kuralı $P(A,B) = P(B)P(A \mid B)$ ile: $P(A1,B1) = 0{,}3 \cdot 0{,}8 = 0{,}24$; $P(A2,B1) = 0{,}3 \cdot 0{,}2 = 0{,}06$; $P(A1,B2) = 0{,}7 \cdot 0{,}3 = 0{,}21$; $P(A2,B2) = 0{,}7 \cdot 0{,}7 = 0{,}49$. Toplam 1'dir. Buradan $P(A1) = 0{,}24 + 0{,}21 = 0{,}45$ (python ile kontrol edildi).

**Soru 9** (derste sözlü, 02:16:46): İkili hizalamadaki en iyi (DP) yaklaşım çoklu dizi hizalamada neden uygulanabilir değil?

> **Çözüm (derste verilmedi):** Hoca cevabı sonraki derse bıraktı. Kısaca, k dizi için DP tablosu k boyutlu olur; her dizi uzunluğu n ise hücre sayısı $n^k$, her hücrede bakılacak komşu sayısı $2^k - 1$ olur. Zaman ve bellek dizi sayısıyla üstel büyür.

## Dersin Toparlaması

Bu derste ikili dizi hizalama konusu tamamlandı. Önce üç DP varyantı (global, yerel, örtüşme) hatırlatıldı ve en iyi hizalamanın skor şemasına bağlı olduğu vurgulandı. Basit eşleşme/uyuşmazlık skorunun yerine, amino asitlerin ve nükleotitlerin biyokimyasal özelliklerini yansıtan skor matrisleri anlatıldı. Bunlar PAM (yakın akraba ailelerin global hizalamaları ve filogenetik ağaçlar, PAM1'den çarpımla türetme) ve BLOSUM (uzak akraba proteinlerin korunmuş blokları, özdeşlik yüzdesine göre kümeleme) matrisleri, log-odds dönüşümü ve geçiş/çaprazlama ayrımına dayanan DNA şemalarıdır. Ardından boşluk bloklarını daha gerçekçi modelleyen afin boşluk cezası ve onun gerektirdiği üç matrisli DP tanıtıldı. DP'nin en iyiyi garanti etmesi, bellek ve zaman maliyeti ve bu maliyeti azaltan alternatifler tartışıldı. Hizalamanın anlamlılığı Gumbel uç değer dağılımı, E-değeri, bit skoru ve $\log_2(mn)$ eşiğiyle, PAM250 örneği üzerinden gösterildi. Bayesçi istatistiğin temel kavramlarına kısaca değinildi.

Dersin sonunda çoklu dizi hizalamaya geçildi. Bu yöntem genlerin hangi bölgelerinin korunduğunu ve işlev için kritik olduğunu göstermekte, motif bulmakta ve evrimsel ilişkileri ortaya çıkarmaktadır. Kesin çözüm pratik olmadığı için kullanılan yöntemler ad hoc yöntemlerdir. Bir sonraki derste MSA yöntem sınıfları (kesin, ilerlemeli, yinelemeli, istatistiksel model) anlatılacak; konunun filogenetik analizle bağlantısı da ileride ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
