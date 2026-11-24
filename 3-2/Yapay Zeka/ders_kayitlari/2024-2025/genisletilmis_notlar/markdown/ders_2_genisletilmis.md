# Ders 2 Genişletilmiş Notu: Kör Arama Algoritmaları ve Sezgisel Aramaya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Arama Problemi: Tanımların Tekrarı
- 2. Arama Neden Zor Olabilir?
- 3. Arama Stratejileri ve Değerlendirme Ölçütleri
- 4. Enlemesine Arama (Breadth-First Search)
- 5. Derinlemesine Arama (Depth-First Search)
- 6. Düşük Maliyetli Arama (Uniform Cost Search)
- 7. Sınırlı Derinlikte Arama ve Artan Derinlikli Arama
- 8. İki Yönlü Arama, Genel Ağaç Arama ve Algoritmaların Karşılaştırılması
- 9. Tekrarlayan Durumlar
- 10. Algoritmaların MATLAB ile Karşılaştırılması
- 11. Olası Dünyalar ve Yapay Zekanın Bakış Açısı
- 12. Sezgisel Arama ve En İyi İlk Arama
- Örnek Sorular

## 1. Arama Problemi: Tanımların Tekrarı

Hoca derse önceki haftanın konusunu hatırlatarak başladı. Bidon problemi ya da bir yerden bir yere geçiş problemi gibi problemleri, başlangıç durumundan bitiş durumuna giden ve durumları birbirine bağlayan bir ağaç (genel olarak graf) yapısına dönüştürmüştük. Bu derste bu tanımların üzerine çözüm algoritmaları kurulacak. Bugünkü algoritmaların ortak özelliği **kör arama** algoritmaları olmalarıdır: problemin tanımında olan bilgi dışında hiçbir ek bilgi kullanmazlar. Ek bilgi kullanılırsa bunlar **bilgili (sezgisel) arama** algoritmaları olur.

Slayttaki tanımlar şunlardır (ekrandan, 00:10:00):

- **Durum uzayı** (arama uzayı, arama ağacı, state space, search space, search tree): durumları, aralarındaki geçişleri, geçiş parametrelerini ve kısıtları gösteren graf ya da ağaç.
- **Operatörler:** durumlar arası geçişleri sağlar.
- **Başlangıç durumu** $S_0$: aramanın başladığı durum. Kök düğüm gibi düşünülür.
- **Hedef durumu** $\{G\}$: aramanın bittiği durum.
- **Maliyet (cost):** operatörü uygulamanın maliyeti.
- **Çözüm yolu (solution path):** başlangıç durumundan hedef duruma giden yol.

Hoca ağaçları tahtada genelde iki ya da üç dallı çizdiğimizi, bunun bir yanılsama yarattığını söyledi: gerçekte her düğümden otuz farklı duruma gidilebilir. Başlangıçtan hedefe birçok yol olabilir ve bu yolların toplam maliyetleri farklıdır. En düşük maliyetli yol **optimal yol**dur.

Ekranda gösterilen 8-bulmaca (8-puzzle) örneğinde başlangıç ve hedef durumları şöyledir (ekrandan, 00:05:00):

```text
S0:          G:
4 3 6        1 2 3
2 1 8        4 5 6
7 _ 5        7 8 _
```

Slaytta karmaşıklığı azaltmak için taş hareketlerinin boş karenin hareketleri olarak temsil edilebileceği yazar; operatörler boş kareyi sola, sağa, yukarı ve aşağı kaydırmaktır.

## 2. Arama Neden Zor Olabilir?

Slaytta şu varsayımlar vardır (ekrandan, 00:15:00): bir durumdan gidilebilecek durum sayısı, yani **dallanma sayısı (branching factor)** $b=10$; saniyede işlenen durum sayısı 1000 (her işlem 1 milisaniye); bir durum için tutulan bellek 100 bayt.

Hoca tahtada şöyle anlattı: bir düğümdesiniz ve 10 farklı çıkışınız var; o düğümlerin her birinden de 10, onlardan da 10 çıkış var. Bu üssel bir büyümedir. Çözümün derinliği 2 ise kökte $10^0$, birinci seviyede $10^1$, ikinci seviyede $10^2$ düğüm vardır ve toplam $1+10+100=111$ durum işlenir. Derinlik 4 olursa $10^4+10^3+10^2+10^1+10^0 = 11.111$ durum işlenir.

| Çözümün derinliği | İşlenen durum sayısı | Zaman | Bellek |
|---|---|---|---|
| 0 | 1 | 1 milisaniye | 100 bytes |
| 2 | 111 | 0.1 saniye | 11 kbytes |
| 4 | 11,111 | 11 saniye | 1 megabyte |
| 8 | $10^8$ | 31 saat | 11 gigabytes |
| 12 | $10^{12}$ | 35 yıl | 111 terabytes |

(ekrandan, 00:15:00; değerler python ile $\sum_{i=0}^{d}10^i$ üzerinden doğrulandı.)

Hoca, derinlik 2'den 4'e iki katına çıktığında durum sayısının neredeyse 100 katına çıktığını, sürenin 0,1 saniyeden 11 saniyeye yükseldiğini; derinlik 2'den 12'ye çıktığında saniyelerden yıllara geçildiğini vurguladı. Bellek tarafında da durum aynıdır: megabayttan gigabayta, oradan terabayta gidilir.

Sonra şu soruyu sordu: saniyedeki işlem sayısını bin yerine bir trilyona çıkarsak, yani $10^9$ kat hızlansak (günümüz işlemcileri gigahertz düzeyinde çalışıyor), sorun çözülür mü? Cevap hayırdır. 35 yıl belki saniyelere iner, ama $b=10$ sabitken derinliği 12 yerine 48 yaparsak süre yine yıllar düzeyine çıkar. Üstelik çizilen şey yalnız bir ağaçtır; graf olduğunda döngü (cycle) ihtimali ve başka durumlar da işin içine girer. Bu yüzden bazı problemler bu tür algoritmalarla çözülemez ve ileride yaklaşık algoritmalara ihtiyaç duyulacaktır.

## 3. Arama Stratejileri ve Değerlendirme Ölçütleri

Slayttaki tanıma göre arama stratejileri, bir durumdan diğerine giderken gidilecek durumun olası durumlar arasından nasıl seçildiğini belirler (ekrandan, 00:20:00). Bir noktadayken üç komşudan hangisine gideceğimize kenarlardaki maliyete, maliyetlerin eşit olup olmamasına ya da "önce aşağıya mı, önce yana mı" kuralına göre karar verebiliriz.

Stratejiler dört boyutta değerlendirilir:

- **Tamlık (completeness):** çözüm varsa mutlaka bulması. Ne zaman bulduğu ya da ne kadar bellek harcadığı önemli değildir. Hoca bunu, 100 seviyeli ve her seviyede 8'e dallanan bir ağacın 88. seviyesindeki çözümü, gerekirse kaba kuvvet (brute force) mantığıyla tek tek bakarak da olsa bulmak diye örnekledi.
- **Zaman karmaşıklığı (time complexity):** aramanın alacağı süre; veri miktarına göre çalışma süresinin nasıl büyüdüğünü gösteren fonksiyon.
- **Hafıza karmaşıklığı (space complexity):** arama için gereken hafıza miktarı.
- **Optimumluk (optimality):** ilk bulunan çözümün en düşük maliyetli çözüm olması.

> **Hocanın vurgusu:** Hafıza karmaşıklığı, orijinal veriyi ya da problemi tanımlamak için tutulan veri değildir. Problemi çözmek için algoritmanın ihtiyaç duyduğu ek bellektir. Örneğin 10 elemanlı bir diziyi sıralamak için algoritma 10 elemanlık bir yere daha ihtiyaç duyuyorsa hafıza karmaşıklığı $n$'dir.

Hoca ayrıca "optimallik" ölçütünün, ilk bölümdeki "optimal yol" tanımıyla karıştırılmaması gerektiğini söyledi: optimal yol en düşük maliyetli yoldur; optimallik ölçütü ise ilk bulunan çözümün bu yol olup olmadığıdır.

Zaman ve hafıza karmaşıklığında kullanılan kavramlar:

- $b$: maksimum dallanma sayısı (bir düğümden çıkan maksimum düğüm sayısı).
- $d$: en az maliyetli çözümün derinliği.
- $m$: arama uzayının maksimum derinliği, yani yaprak düğümlerin en derin olduğu yer (bazen $\infty$).

Zaman ve hafıza karmaşıklıkları bu üç parametreye bağlı fonksiyonlar olarak ifade edilir.

Kör arama algoritmalarına bilgisiz, mekanik, kör (blind) ya da uninformed arama da denir. BFS ve DFS önceki derslerden bilinir; diğer algoritmalar bunların üzerinde yapılan küçük değişikliklerle, dört ölçütten bazılarını iyileştirip bazılarını kötüleştirerek elde edilmiştir.

## 4. Enlemesine Arama (Breadth-First Search)

### 4.1 Çalışma şekli

Hoca, veri yapıları ya da algoritma analizi derslerindeki BFS'den bir farkı vurguladı: orada bütün graf baştan verilir ve üzerinde arama yapılır. Burada ise bir başlangıç durumundasınız; arama ilerledikçe ağaç kendiliğinden açılır. Benzetme olarak, oyunlarda karanlık bir alana doğru ilerledikçe haritanın açılmasını verdi. Slaytta da "Ağaç / durumlar en başta elimizde yok, zaman içinde oluşuyor" yazar (ekrandan, 00:25:00).

BFS kuyruk (ilk giren ilk çıkar) kullanır. Ekrandaki örnekte ağaç şöyledir: 1'in çocukları 2 ve 3; 2'nin çocukları 4 ve 5; 3'ün çocukları 6 ve 7; 4'ün çocukları 8 ve 9; 5'in çocukları 10 ve 11. Aranan çözüm 6'dır. Tahtadaki kuyruk adımları (ekrandan, 00:35:00):

```text
K = (1)                 -> 1 çekilir, hedef değil; 2 ve 3 eklenir
    (2 3)               -> 2 çekilir; 4 ve 5 eklenir
    (3 4 5)             -> 3 çekilir; 6 ve 7 eklenir
    (4 5 6 7)           -> 4 çekilir; 8 ve 9 eklenir
    (5 6 7 8 9)         -> 5 çekilir; 10 ve 11 eklenir
    (6 7 8 9 10 11)     -> 6 çekilir: hedef bulundu
```

Hoca anlatırken önce 2'nin çocuklarını eklemeyi unuttu, sonra düzeltti. Durum açma sırası 1, 2, 3, 4, 5, 6'dır; çözüm yolu ise 1, 3, 6'dır. Slaytta da "Çözüm bir durum sırası, durum açma sırası da, ama bunlar birbirinden farklı şeyler" yazar. 6'nın daha aşağıda başka kopyaları da olabilirdi; BFS ilk karşılaştığında durur.

Hoca kuyruğun bir düğümle başlayıp problem açıldıkça devasa şekilde büyüdüğüne dikkat çekti. Kitap slaytındaki A, B, C, ... harfli ağaçta da aynı şey olur: önce A, sonra B ve C eklenir, B'nin çocukları kuyruğun sonuna eklenir, sonra C açılır vb.

Hoca bir de iki boyutlu ızgara (matris) üzerinde dört komşulukla arama örneği çizdi: BFS, bulunduğu noktanın önce yakın çevresine bakar, sonra daireyi biraz genişletir, sonra biraz daha; yani etrafa "yayıla yayıla" arar.

### 4.2 Özellikleri

**Tamlık:** BFS tamdır; çözüm ağacın ne kadar derininde olursa olsun, makine 300 yıl sonra cevap verecek olsa bile bulur. Slayttaki şart: $b$ sonlu olmalıdır (ekrandan, 00:30:00). Dallanma sonsuz olursa makine cevap veremez.

**Zaman:** Hoca ikili ağaç üzerinden açıkladı: üçüncü seviyeye kadar $2^3+2^2+2^1+2^0$ düğüme bakılır. Bunu genellersek $b^d$ mertebesi çıkar. Ancak kitap $b^{d+1}$ der, çünkü çözümün bulunduğu seviyedeki düğümler açılırken çocukları da kuyruğa eklenir; yani bir alt seviye de işin içine girer.

**Bellek:** Her düğüm bellekte tutulduğu için bellek de $O(b^{d+1})$'dir.

**Optimallik:** BFS önce köke yakın seviyelere baktığı için, aşağıda bir çözüm varsa ondan önce daha sığ bir çözümü bulma ihtimali vardır. Ancak bu ancak bütün geçişlerin maliyeti aynıysa optimaldir. Aşağı inen bir yolun toplam maliyeti daha küçükse BFS yanılır.

> **Hocanın vurgusu:** BFS'nin bilgisayar açısından en büyük sıkıntısı belleğin üssel büyümesidir. Her şeyi tutmak zorundasınız. $d$. derinlikte belleğiniz yetti diyelim; bir adım daha inmek $b^d$ kadar yeni düğümü belleğe almak demektir. Her daldan 5 düğüm açılan bir ağaçta dört seviye inmek $5^4$ yeni düğüm getirir. Bu yüzden belleği çok kötü kullanan bir algoritmadır; hafıza zamandan çok daha büyük sorundur.

Hoca $b^{d+1}$ ile $b^d$'nin asimptotik olarak "üç aşağı beş yukarı" aynı olduğunu da ekledi.

## 5. Derinlemesine Arama (Depth-First Search)

### 5.1 Çalışma şekli

DFS'de aynı ağaç üzerinde bu kez liste yığın (stack, son giren ilk çıkar) gibi kullanılır: elemanlar listenin sonuna eklenir ve sondan çekilir. Böylece arama her adımda bir sonraki derinliğe gider. Derste anlatılan sıra şöyledir (hedef yine 6):

```text
L = (1)          -> 1 çekilir; 3 ve 2 eklenir
    (3 2)        -> 2 çekilir; 4 ve 5 eklenir
    (3 4 5)      -> 5 çekilir; 10 ve 11 eklenir
    (3 4 10 11)  -> 11 çekilir (çocuğu yok), sonra 10 çekilir
    (3 4)        -> 4 çekilir; 8 ve 9 eklenir
    (3 8 9)      -> 9, sonra 8 çekilir
    (3)          -> 3 çekilir; 6 ve 7 eklenir
    (6 7)        -> 7 çekilir, sonra 6 çekilir: hedef bulundu
```

<!-- BELİRSİZ: Hoca listeyi sözlü kurarken ekleme sırasını tutarlı söylemedi (ilk adımda 3 ve 2'yi bu sırayla ekledi, sonraki adımlarda çocukları soldan sağa ekledi). Ziyaret sırası anlatımdan 1, 2, 5, 11, 10, 4, 9, 8, 3, 7, 6 olarak kuruldu. -->

Ziyaret sırası 1, 2, 5, 11, 10, 4, 9, 8, 3, 7, 6 olur. Hoca, BFS'de liste çok genişlerken burada ağacın derinine gidildiği için listenin sınırlı kaldığını vurguladı. Kitap slaytındaki harfli ağaçta sıra A, B, D, H, I, E, J, K, ... biçimindedir.

Izgara örneğinde DFS bir yöne doğru gider, duvara gelince sıradaki yöne geçer. Her adımda yalnız bir önceki duruma dair bilgi ve sıradaki adaylar tutulduğu için bellek az kullanılır. BFS'de ise bir noktanın altındaki bütün seviye ($b^d$ kadar) belleğe alınmalıdır.

### 5.2 Özellikleri

Slayttaki özellikler (ekrandan, 00:45:00):

- **Complete?** No: fails in infinite-depth spaces, spaces with loops. Modify to avoid repeated states along path $\Rightarrow$ complete in finite spaces.
- **Time?** $O(b^m)$: terrible if $m$ is much larger than $d$, but if solutions are dense, may be much faster than breadth-first.
- **Space?** $O(bm)$, i.e., linear space!
- **Optimal?** No.

**Tamlık:** Sonlu derinlikte DFS tamdır. Ama ağaç sonsuz derinlikteyse ya da içinde döngüler varsa, gidebildiğiniz kadar derine dalarsınız ve oradan hiç geri çıkamayabilirsiniz. Uzay sonlu ve döngüsüzse tam diyebiliriz.

**Zaman:** Çözüm $d$ derinliğinde olsa bile DFS maksimum derinlik $m$'ye kadar inebilir. $m$, $d$'den çok büyükse bu çok kötüdür, $O(b^m)$. Fakat çözümler yoğunsa (dense, seyrek değil), yani ağacın birçok yerinde çözüm varsa DFS, BFS'den çok daha hızlı sonuç verebilir. Hoca özellikle harita problemlerinde bunun görüldüğünü söyledi.

**Bellek:** Bir düğüme gidildiğinde altındaki bütün seviye açılmaz, yalnız o düğümün çocuklarına bakılır. Bir düğümün en fazla $b$ çocuğu vardır ve en fazla $m$ derinliğe inilir. En kötü durumda her seviyede $b$ çocuk listeye girer, toplam $b \cdot m$: doğrusal bellek. Hoca bunun tam olarak $bm$ olmayabileceğini, ama Big-O'da $5n$ gibi ifadeleri $n$'ye yuvarladığımız gibi $O(bm)$ dendiğini ekledi.

**Optimallik:** DFS optimal değildir. Derinlere inip bir çözüm bulduğunuzu düşünün; bütün adım maliyetleri eşit olsa bile, uğramadığınız daha sığ bir yerde daha az maliyetli bir çözüm olabilir. İlk bulunan çözüm en ucuz çözüm olmaz.

## 6. Düşük Maliyetli Arama (Uniform Cost Search)

### 6.1 Fikir

UCS listeden eleman çekerken kuyruk ya da yığın mantığıyla baştan ya da sondan almak yerine, **o ana kadar harcanan toplam maliyeti** (kökten itibaren) en küçük olanı çeker. İşin içine maliyet bilgisi girer. Bu bir öncelikli kuyruk (priority queue) mantığıdır; gerçekleştirmede yığın (heap) kullanılır. Hoca bunu bir en kısa yol algoritmasına benzetti. Slayttaki algoritma (ekrandan, 01:20:00):

```text
kuyruk = [kök durum]
bulundu = FALSE
While (kuyruk <> boş) and (bulundu = FALSE)
  - Kuyruktan ilk durumu (N) çek
  - Eğer N hedef durumsa, bulundu = TRUE
  - N'den gidilebilecek tüm durumları kuyruğun sonuna ekle
  - Kuyruktaki durumları kökten maliyetlere göre küçükten büyüğe sırala
```

### 6.2 Örnek: A'dan F'ye

Durum geçiş uzayı (ekrandan, 00:50:00): A-B 1, A-C 4, A-D 15, B-F 10, C-E 5, E-F 1, D-F 1. Hoca slayttaki iki maliyetin hatalı olduğunu, A-C kenarının 4, C-E kenarının 5 olması gerektiğini söyleyip tahtada düzeltti. Hedef F'dir.

1. A açılır; listeye B (1), C (4), D (15) eklenir. min(1, 4, 15) = 1 → B çekilir. B hedef değil.
2. B'den yalnız F'ye gidilir; F'nin kökten maliyeti $10+1=11$. Liste F, C, D: min(11, 4, 15) = 4 → C çekilir.
3. C'den E'ye gidilir; E'nin maliyeti $4+5=9$. Liste F, E, D: min(11, 9, 15) = 9 → E çekilir.
4. E'den F'ye gidilir; bu F'nin maliyeti $4+5+1=10$. F listeye ikinci kez girer (hoca bunlara "F üzeri bir, F üzeri iki" gibi ad verilebileceğini söyledi). Liste F, F, D: min(11, 10, 15) = 10 → maliyeti 10 olan F çekilir. F hedeftir.

Bulunan yol A-C-E-F, maliyeti 10'dur. Her adımda en küçük maliyetli eleman çekildiği için ilk bulunan F aynı zamanda en ucuz F'dir (adımlar python ile doğrulandı).

### 6.3 Özellikleri

**Tamlık:** Arada atlanan ve çözüme ulaşmayı engelleyen bir durum yoktur; örnekteki gibi yönlü ve döngüsüz bir grafta tamdır.

**Zaman ve bellek:** Her noktadan ne kadar dallandığımıza bağlıdır; yaklaşık $b^d$ mertebesindedir. Kitap slaytında bu, adım maliyetlerine bağlı bir $C$ parametresiyle ifade edilir; hoca bunun da sonuçta yaklaşık $b^d$'ye denk geldiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Ders kitabında UCS'nin zaman ve bellek karmaşıklığı büyük olasılıkla $O\!\left(b^{\lceil C^*/\epsilon \rceil}\right)$ biçiminde verilir. Burada $C^*$ optimal çözümün maliyeti, $\epsilon$ en küçük adım maliyetidir. Bütün adım maliyetleri eşitse bu ifade $b^d$'ye iner.

**Optimallik:** Bütün maliyetler pozitifse (kilometre, süre, para gibi) UCS optimaldir: ilk bulduğu çözüm en az maliyetli çözümdür. Ancak bazı problemlerde (hoca "transmission problemleri" örneğini verdi) maliyet negatife dönebilir; örneğin bir yerde harcadığınız enerji size geri dönüyorsa bu negatif bir kenar gibi düşünülür. O zaman UCS optimal sonucu vermeyebilir.

## 7. Sınırlı Derinlikte Arama ve Artan Derinlikli Arama

Hoca, o ana kadarki algoritmalar içinde belleği en iyi olanın DFS ($b \cdot m$) olduğunu, BFS'nin ise optimal olabilme özelliğiyle DFS'den iyi olduğunu hatırlattı; çünkü BFS köke yakın noktalardan başlayıp sonra derinleşir. Zaman ikisinde de üsseldir. "Bu ikisini birleştirirsek bir iyileştirme olur mu?" sorusu aşağıdaki iki algoritmayı doğurmuştur.

### 7.1 Sınırlı derinlikte arama (depth-limited search)

Slayttaki tanım: "derinlemesine aramanın derinlik sınırlanmış ($l$) hali; $l$ derinliğinde olan node'ların genişlemesine izin verme" (ekrandan, 01:00:00). DFS aşağıya iner ama bu iniş sonsuz ($m$) değil, en fazla $l$ seviyeye kadardır (örneğin $l=5$).

- **Tamlık:** Yok. Çözüm $l+1$ ya da daha aşağıdaysa bulunamaz.
- **Zaman:** $O(b^l)$. Örneğin $l=5$ ise $b^5$.
- **Bellek:** $O(bl)$ (tahtada $b \cdot l$ yazıldı).
- **Optimallik:** Yok.

Faydası şudur: çözüm köke yakın bir yerdeyse, sınırsız DFS bir dalda sonsuza kadar inip sonra geri dönüp öbür dala geçerken çok uzun sürebilir. Derinlik sınırıyla köke yakın bir çözüme daha kısa sürede ulaşma ihtimali olur.

### 7.2 Artan derinlikli arama (iterative deepening search)

Slaytta: "for derinlik limiti ($l$) = 0 to X: Sınırlı derinlikte arama ($l$)" (ekrandan, 01:00:00). Derinlik sınırı sıfırdan başlatılır, çözüm bulunamadıkça bir artırılır ve her seferinde arama baştan başlatılır. Yani aslında art arda sınırlı derinlikli aramalar yapılır. Hoca, "kaldığım yerden devam etsem" fikrinin güzel olduğunu ama mümkün olmadığını, bu yüzden her seferinde baştan başlandığını söyledi.

**Ek maliyet hesabı.** $d$ derinliğe kadar bir sınırlı derinlikli arama $b^d + b^{d-1} + \dots + b^0$ düğüme bakar. Artan derinlikte ise kök ($b^0$) $d+1$ kez, birinci seviye $d$ kez, ikinci seviye $d-1$ kez, ..., son seviye bir kez gezilir:

$$N_{IDS} = (d+1)\,b^0 + d\,b^1 + (d-1)\,b^2 + \dots + 1\cdot b^d$$

$b=10$, $d=5$ için (ara adım eklendi):

$$N_{DLS} = 1+10+100+1000+10000+100000 = 111.111$$

$$N_{IDS} = 6+50+400+3000+20000+100000 = 123.456$$

Fark yaklaşık %11'dir (python ile doğrulandı). Hoca bu kadar küçük bir fazlalıkla optimallik kazanıldığını vurguladı.

Özellikleri:

- **Tamlık:** Bütün düğümler eninde sonunda gezildiği için tamdır.
- **Optimallik:** Önce köke yakın yerlere bakıldığı için, adım maliyetleri eşitse optimaldir.
- **Zaman:** Ağaç önce 1, sonra $b^1$, $b^2$, ..., $b^d$ seviyesine kadar açılır. Big-O'da en büyük terim alınır ve diğerleri ihmal edilir: $O(b^d)$.
- **Bellek:** Derinlemesine gidildiği için DFS'nin bellek özelliği korunur: $O(bd)$. Bir düğüm açılırken listeye en fazla $b$ çocuk eklenir; $d$ derinliğe inildiğinde yan dallardakiler listeden çıkmış olacağından en fazla $b \cdot d$ eleman tutulur.

Hoca, $b$ ve $d$'nin farklı değerleri için (örneğin $b$'yi $d$'ye yaklaştırmak ya da ikisini de çok büyük almak) bu %11'lik farkın nasıl değiştiğinin incelenmesini önerdi.

> **Ek bilgi (derste anlatılmadı):** $N_{IDS}/N_{DLS}$ oranı $b$ büyüdükçe 1'e yaklaşır, $b$ küçüldükçe büyür. Örneğin $b=2$ için artan derinlikli arama sınırlı derinlikli aramanın yaklaşık iki katı düğüme bakar. Bu yüzden ek maliyet büyük olasılıkla en çok küçük dallanma sayılarında hissedilir.

## 8. İki Yönlü Arama, Genel Ağaç Arama ve Algoritmaların Karşılaştırılması

### 8.1 Algoritmaların özeti

Aradan önce hoca, A düğümündeyken B, C, D, E'den hangisine gidileceğine kimin nasıl karar verdiğini özetledi: kuyruğun başından mı sonundan mı çekildiği (BFS ya da DFS) ya da kenar maliyetlerinin kuyruğa eklenip maliyete göre öncelik verilmesi (UCS). Hepsi bilgisizdir, yalnız stratejileri farklıdır.

### 8.2 İki yönlü arama (bidirectional search)

Arama hem başlangıçtan hedefe hem hedeften başlangıca doğru yapılır; iki taraf ortada buluşacak şekilde bir o tarafa bir bu tarafa dallanılır. Tam olabilir, zaman ve bellek $O(b^{d/2})$ olur, maliyetler eşitse optimal olabilir. Hoca bunun çok sık karşılaşılan ya da kullanılan bir algoritma olmadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** İki yönlü aramanın kazancı $b^{d/2} + b^{d/2}$'nin $b^d$'den çok küçük olmasından gelir. Uygulanabilmesi için hedef durumun açıkça bilinmesi ve operatörlerin tersinin (bir durumun öncüllerinin) hesaplanabilmesi gerekir.

### 8.3 BFS ile DFS arasındaki küçük fark

Hoca slayttaki BFS algoritmasını gösterip şunu sordu: BFS'den DFS'ye nasıl geçilir? Sadece ekleme ve çekme yerini değiştirmek yeterlidir; küçük bir algoritmik değişikliktir. Bu geçiş bize ne kazandırdı? Yalnız belleği iyileştirdi. Optimallik açısından ise zarar verdi. Zaman karmaşıklığında bir değişiklik olmadı. Artan derinlikli arama ise DFS'yi biraz BFS'ye benzetir: belleği ve arama sayısını biraz fazla kullanarak, çözüm köke yakınsa optimal çözümü bulma imkanı verir.

UCS ise o ana kadar "en çok veriyle iş yapan" algoritmadır: listeden rastgele değil, kökten en az maliyetli olan düğüm çekilir. Hoca bunu "bilgi" yerine "veri" demeyi tercih ettiğini söyleyerek ifade etti.

### 8.4 Genel ağaç arama

Kitap slaytındaki genel yapı (ekrandan, 01:10:00):

```text
function Tree-Search(problem, fringe) returns a solution, or failure
  fringe <- Insert(Make-Node(Initial-State[problem]), fringe)
  loop do
    if fringe is empty then return failure
    node <- Remove-Front(fringe)
    if Goal-Test[problem] applied to State(node) succeeds return node
    fringe <- InsertAll(Expand(node, problem), fringe)
```

Slaytta "A strategy is defined by picking the order of node expansion" yazar: strateji, düğümlerin açılma sırasıyla belirlenir.

### 8.5 Karşılaştırma

Derste söylenen özellikler bir araya getirildiğinde (ara adım eklendi, değerler derste geçen ifadelerden derlendi):

| Algoritma | Tam mı? | Zaman | Bellek | Optimal mi? |
|---|---|---|---|---|
| BFS | Evet ($b$ sonluysa) | $O(b^{d+1})$ | $O(b^{d+1})$ | Adım maliyetleri eşitse |
| UCS | Evet | yaklaşık $O(b^d)$ | yaklaşık $O(b^d)$ | Maliyetler pozitifse |
| DFS | Hayır (sonlu, döngüsüz uzayda evet) | $O(b^m)$ | $O(bm)$ | Hayır |
| Sınırlı derinlik | Hayır | $O(b^l)$ | $O(bl)$ | Hayır |
| Artan derinlik | Evet | $O(b^d)$ | $O(bd)$ | Adım maliyetleri eşitse |
| İki yönlü | Evet | $O(b^{d/2})$ | $O(b^{d/2})$ | Adım maliyetleri eşitse |

Hoca DFS'yi ve BFS'yi şöyle karşılaştırdı: DFS bellek açısından doğrusal ve çok iyidir ama döngüde sonsuza gidebilir ve optimal çözümü garanti etmez. BFS döngülere takılmaz ve optimal çözümü bulabilir ama bellek açısından üssel büyür. Çok büyük haritalarda, örneğin bin düğümlü bir haritada BFS'yi kendi bilgisayarınızda deneyebileceğinizi söyledi. Türkiye haritasında bir ilin etrafında 7-8 il olabilir (hoca ortada olduğu için Konya'yı örnek verdi); İstanbul gibi kenardaki illerde ise 4-5 komşu vardır. Her noktadan 8'e dallanmak arama uzayını çok büyütür. 8-bulmaca slaytında da ortalama adım sayısının 22, ortalama dallanma sayısının 2,67 olduğu ve bunun tekil olmayan yaklaşık 2,7 milyar duruma karşılık geldiği yazar (ekrandan, 01:25:00).

## 9. Tekrarlayan Durumlar

Bir durumdan diğerine birden fazla yoldan gidilebilir; graflarda aynı duruma tekrar tekrar ulaşılabilir. Bunlara **tekrarlayan durumlar (repeated states)** denir. Kitap slaytındaki örnekte A, B, C, D arasında ikişer kenar bulunan bir zincir, ağaç olarak açıldığında her seviyede düğüm sayısı ikiye katlanır. Slaytın cümlesi: "Failure to detect repeated states can turn a linear problem into an exponential one!" (ekrandan, 01:05:00).

Derste ayrıca şu örnek anlatıldı: A'dan D'ye, D'den E'ye, E'den A'ya ve F'ye geçiş var; başlangıç A, hedef F. Derinlemesine aramada:

1. A'dan yalnız D'ye gidilebilir; D listeye eklenir.
2. D çekilir; D'den E'ye gidilebilir, E eklenir.
3. E çekilir; E'den A'ya ve F'ye gidilebilir. A tekrar eklenirse ve önce A açılırsa A-D-E-A döngüsüne girilir ve hedefe hiç ulaşılamaz.

Çözüm: bir düğüme uğrandıysa onu işaretlemek (visited bilgisi tutmak) ya da yeni durumu listeye eklemeden önce daha önce görülüp görülmediğini kontrol etmek. Kontrol yapılmazsa algoritma tam olmayabilir; çözüm bulunamıyorsa da optimallikten söz edilemez, çünkü optimallik ancak bir çözüm varsa anlamlıdır.

Hoca son olarak şu soruyu sordu: artan derinlikli aramada, sınırlı derinlikli arama (DFS) yerine sınırlı genişlikte arama (BFS) kullansak iyi mi olur? Cevap aşağıda Örnek Sorular bölümündedir.

## 10. Algoritmaların MATLAB ile Karşılaştırılması

Dersin notlarıyla birlikte paylaşılan bir MATLAB kodu, arama algoritmalarını benzetim yoluyla karşılaştırır. Hoca MATLAB'ı kurmadan, tarayıcıda MATLAB Online ile kullanmanın mümkün olduğunu gösterdi: dosyalar, çalışma alanı (workspace) ve komut penceresi masaüstü sürümle aynıdır. Yardım (help) ve dokümantasyon bölümü, örneğin `plot` fonksiyonu için parametreleri ve örnekleri ayrıntılı anlatır. Hoca MATLAB'ın Python'a benzediğini, ufak tefek farklar dışında dramatik farklılıklar olmadığını; simülasyon, çizim ve kullanıcı arayüzü işlemlerinin kolay olduğunu söyledi.

Kod, verilen maksimum sayıya göre (bu çalıştırmada 18) rastgele noktalar (şehirler) üretir ve aralarında rastgele yollar oluşturur; her şehirden her şehre yol yoktur. Kenarlardaki sayılar (örneğin bir kenarda 33) kilometre, dakika ya da saat olabilir, maliyet anlayışına bağlıdır. Sonra algoritmalar çalıştırılır, buldukları yollar, maliyetleri ve adım sayıları yazdırılır.

Gösterilen çalıştırmada başlangıç 12, hedef 1 idi. Hoca, yol sayısı fazla olduğu için problemin gözle çözülmesinin bile zor olduğunu söyledi. BFS 12'den 4'e, oradan 2'ye, 5'e ve 1'e gitti. DFS ise 12'den 11'e, 9'a, 15'e ve 18'e gidip hedefe yaklaşırken birden 17'ye geri saptı; hoca bunu derinlemesine aramanın optimallikten uzaklaştığının kanıtı olarak gösterdi.

<!-- BELİRSİZ: Benzetimde BFS ve DFS için söylenen maliyet ve adım sayıları (314, 128, 37 adım gibi) altyazıda karışık geçiyor ve karede okunmuyor; bu yüzden nota alınmadı. -->

İkinci grafik, adım numarasına göre liste (kuyruk) boyutunu gösterir (ekrandan, 01:35:00). Gözlemler:

- UCS en çok adımı kontrol eder ve listeye en çok elemanı ekler, ama optimal sonucu verir. Listeden en az maliyetliyi çektiği için rotanın tamamı grafikte görünmez.
- DFS'nin liste boyutu bir yere kadar artar, sonra yatay kalır: bu, $O(bm)$ doğrusal belleğin görünümüdür.
- BFS'nin listesi $b^d$'ye yakın bir büyüme gösterir.
- A* ve en iyi ilk arama (bestfs) çok küçük listelerle çalışır; bunlar sonraki derste ele alınacaktır.

Kod her çalıştırıldığında farklı harita üretir ve grafikler değişir. Ancak yüz kez çalıştırılıp ortalama alınsa yine benzer bir tablo çıkar, çünkü derste asimptotik olarak söylenen karmaşıklıklar kodun analizinden elde edilmiştir ve bunu değiştirecek uç bir durum yoktur.

## 11. Olası Dünyalar ve Yapay Zekanın Bakış Açısı

Notlardaki bir slayt durum uzayının büyüklüğünü günlük hayattan anlatır (ekrandan, 01:40:00):

- Her gün iki seçeneği olan bir karar verdiğimizi düşünelim. Bu durumda kararımızın etkisine göre iki olası dünyadan birinde yaşarız.
- 32 gün sonra $2^{32}$ = yaklaşık 4,3 milyar olası dünyadan sadece birinde yaşıyor oluruz ($2^{32} = 4.294.967.296$).
- Başka faktörler: doğduğumuzdan beri geçen zaman, başkalarının kararlarının bizim dünyamıza etkisi, ikiden fazla seçeneği olan durumlar.

Hoca yapay zekanın bu konuyla başlamasının nedenini şöyle açıkladı: klasik polinom zamanlı algoritmalar (DFS vb.) kesin ya da optimal çözümü verme noktasında sıkıntı yaşar. Çözümü verebilirler ama ya makul sürede veremezler, ya bellek yetmez, ya da optimal çözüme hiç ulaşamayacak bir duruma düşülür. O zaman yapılacak şey, optimale gidemiyorsak bildiğimiz en iyi çözümü bulup uygulamak, ileride daha iyisini bulursak onu kullanmaktır. Makine öğrenmesi de tahmin ve sınıflandırma yaparken bunu yapar: teker teker bir örüntü aramak belki yüz yıl sürer; şimdilik %80 başarıyla yetinilir, ileride yeni yöntemler çıkar.

Hoca bunu tıbba benzetti: hekim, bir hastalığı mevcut bilgisiyle bir prosedüre göre tedavi eder; birkaç yıl sonra yeni bir ilaç ya da tedavi çıkarsa onu uygular. Bilimin doğası "gerçeğe yaklaşma"dır (approximation to the truth): tek bir gerçek ya da optimal çözüm vardır, biz körlemesine ya da biraz bilinçli argümanlarla ona yaklaşmaya çalışırız.

## 12. Sezgisel Arama ve En İyi İlk Arama

### 12.1 Sezgisellik

Şimdiye kadarki algoritmalarda durum uzayı ağacındaki veriler dışında bir bilgi verilmiyordu. Problemimiz bir noktadan diğerine en kısa yol olsun (harita problemi). Slayttaki alıntılar (ekrandan, 01:45:00):

- **G. W. Leibniz:** "Özel buluşlara çok değer vermiyorum ve en çok arzu ettiğim şey, icat etme sanatını mükemmelleştirmek ve problemin çözümlerini bulmaktan ziyade çözüm yöntemlerini bulmaktır; çünkü tek bir yöntem, sayısız çözümleri kapsar."
- **Feigenbaum ve Feldman** (slaytta "Fagenbaum ve Fieldman" diye yazılmış): "Sezgisellik (sezgisel kurallar, sezgisel yöntem) problemin durum uzayı çok büyük olduğunda, çözümün aranmasını kesin biçimde sınırlayan herhangi bir kural, strateji, hile, sadeleştirme ve diğer etmenler kullanımıdır."

Hoca bunu şöyle yorumladı: çözüm uzayı çok büyükse, bizi çözüme hızlıca götürecek ek bir yardımcı var mı? Bu bir hile, kural, strateji, veri ya da bir manipülasyon olabilir. Arama algoritmalarında sezgi, hedefe ne kadar yakın olunduğuna dair bir tahmindir.

Hoca iki benzetme yaptı:

- Kırk yıl önce telefonun, aracın olmadığı bir köyde bir yere gitmek istiyorsunuz: birine sorarsınız, söylediğine güvenirsiniz; doğruysa ve şansınız varsa oraya varırsınız.
- Gece bir çölün ortasındasınız ve gideceğiniz yerin doğuda olduğunu biliyorsunuz: sabah güneşin doğduğu yöne gitmek sizi doğru yere götürür, ters yöne gitmek götürmez.

UCS bir sonraki düğümü seçerken başlangıçtan o ana kadar harcanan maliyete, yani **geçmişe** bakıyordu. Geleceğe dair, yani gidilecek noktalar hakkında geçmişten bilgi edinemeyiz. Bize ayrıca geleceğe yönelik bir tahmin bilgisi verilirse ve bunu kullanırsak sezgisel algoritmaların temeli oluşur. En kısa yol probleminde bu bilgi **kuş uçuşu uzaklık** olabilir: önceden bir liste olarak verilir ve yeni bir noktaya geçerken hedefe kuş uçuşu en yakın görünen noktaya önce gidilir.

Bu fikrin ilk sürümü en iyi ilk aramadır. Çözüme götürebilir, hatta hızlı götürebilir, ama optimal olmayabilir. Optimal olan sürümü A*'dır ve sonraki konudur.

### 12.2 En iyi ilk arama (best-first search)

Kitap slaytındaki tanım (ekrandan, 02:00:00):

- Fikir: her düğüm için bir **değerlendirme fonksiyonu** (evaluation function) kullan; bu, "istenebilirlik" (desirability) tahminidir.
- Açılmamış düğümler içinden en istenebilir olanı aç.
- Gerçekleştirme: fringe, istenebilirliğe göre azalan sırada sıralanmış bir kuyruktur.
- Özel durumları: açgözlü arama (greedy search) ve A* araması.

Ders notlarındaki algoritma, UCS ile aynı iskelete sahiptir; tek fark son adımdır (ekrandan, 01:50:00): "Kuyruktaki durumlara değerlendirme fonksiyonuna göre bir puan ver ve durumları bu puanlara göre küçükten büyüğe sırala." Yani listeden eleman çekerken geçmişte hesaplanan maliyet değil, kuş uçuşu maliyet ya da belirlenen başka bir değerlendirme fonksiyonu kullanılır. Bu bir kazanç da olabilir (o zaman en büyük alınır) ya da maliyet (en küçük alınır).

Hoca neden sıralama yapıldığını şöyle açıkladı: en iyi görünen düğüm çekilir; bu hamle çözüme götürmezse, döngüye girilirse ya da çıkmaz sokağa (dead end) gelinirse sıranın ikincisinden devam etmek gerekir. Bu, UCS ile DFS'nin birlikte kullanılması gibidir: DFS'de çıkmaza gelince geri dönülür, burada da sıralama bunu sağlar.

Açgözlü en iyi ilk aramada değerlendirme fonksiyonu:

$$f(n) = h(n)$$

$h(n)$, mevcut durumun hedefe tahmini uzaklığıdır. Örneğin $h_{SLD}$ (straight-line distance), iki nokta arasındaki Öklid uzaklığı gibi düşünülebilir; koordinat ya da küresel koordinat bilgisinden kolayca hesaplanır. Her adımda hedefe en yakın görünen duruma ilerlenir. UCS'nin kullandığı "o ana kadarki toplam maliyet" bilgisi tamamen bir kenara atılır. A*'da hem o maliyet hem de sezgisel maliyet birlikte kullanılacaktır.

### 12.3 Romanya haritası örneği

Kitaptaki Romanya haritasında Arad'dan Bükreş'e gidilmek isteniyor. Kenarlarda gerçek yol uzunlukları vardır; örneğin Arad-Sibiu 140 (km ya da dakika). Ayrıca her şehrin Bükreş'e kuş uçuşu uzaklığını veren bir liste verilir (ekrandan, 01:55:00):

| Şehir | Kuş uçuşu uzaklık | Şehir | Kuş uçuşu uzaklık |
|---|---|---|---|
| Arad | 366 | Mehadia | 241 |
| Bucharest | 0 | Neamt | 234 |
| Craiova | 160 | Oradea | 380 |
| Dobreta | 242 | Pitesti | 10 |
| Eforie | 161 | Rimnicu Vilcea | 193 |
| Fagaras | 176 | Sibiu | 253 |
| Giurgiu | 77 | Timisoara | 329 |
| Hirsova | 151 | Urziceni | 80 |
| Iasi | 226 | Vaslui | 199 |
| Lugoj | 244 | Zerind | 374 |

Hoca önce UCS'nin bu haritada ne yapacağını hatırlattı: Arad'dan Zerind, Sibiu ve Timisoara eklenir, en küçük maliyetli olan (75) açılır, onun komşusu (71) eklenir vb. UCS sonunda bulur ama yaklaşık 20 noktalı, her noktadan 3-4 seçenekli bu haritada epey iş yapar.

Açgözlü en iyi ilk arama ise geçmiş maliyete hiç bakmaz:

1. Başlangıç Arad ($h=366$). Komşular: Sibiu ($h=253$), Timisoara ($h=329$), Zerind ($h=374$). En küçük $h$ Sibiu'dur, Sibiu seçilir.
2. Sibiu'nun komşuları: Arad, Fagaras, Oradea, Rimnicu Vilcea. Bunların içinde en küçük $h$ Fagaras'tır (176). Hoca, Arad'ın geri dönüş olduğu için alınmayacağını söyledi. Ayrıca şunu ekledi: Fagaras'ın değeri 176 değil de çok büyük (örneğin 576 ya da 593) olsaydı, bu yolun kötü olduğu anlaşılır ve sıralamadaki bir sonraki seçeneğe geri dönülürdü.
3. Fagaras'ın komşuları Sibiu ve Bükreş'tir. Bükreş'in $h$ değeri 0'dır, hedefe ulaşılır.

Bulunan yol: Arad - Sibiu - Fagaras - Bükreş.

Bu çözüm optimal değildir, çünkü geçmiş maliyet hesaba katılmamıştır. Bu bir **açgözlü (greedy)** yaklaşımdır ve açgözlü yaklaşımlar her zaman optimal çözümü vermez. Hocanın gösterdiği optimal çözümün maliyeti $140+80+97+101 = 418$'dir; açgözlü aramanın bulduğu yolun maliyeti ise $140+99+\dots$ biçimindedir ve daha büyüktür. UCS yapılsaydı optimal yol bulunurdu.

> **Ders sonrası not:** Hoca açgözlü aramanın bulduğu yolun maliyetini "140 artı 99 artı 213" diye okudu. Ders kitabının Romanya haritasında Fagaras-Bükreş uzaklığı büyük olasılıkla 211'dir; bu durumda toplam $140+99+211 = 450$ olur. Her iki durumda da maliyet optimal yolun 418'inden büyüktür. 418'lik yol da büyük olasılıkla Arad - Sibiu - Rimnicu Vilcea - Pitesti - Bükreş yoludur.

### 12.4 Özellikleri

- **Tamlık:** Tam değildir. Döngüye takılma ihtimali vardır: Arad'dan Sibiu'ya, Sibiu'dan tekrar Arad'a gidilebilir. Tekrar kontrolü yapılmazsa döngüye girilir ve çözüm hiç bulunamayabilir.
- **Zaman:** $O(b^m)$. Her düğümden ortalama $b$ dallanma olur ve arama $m$ derinliğe kadar inebilir.
- **Bellek:** $O(b^m)$. Bütün durumlar hafızada tutulmalıdır. Hoca bunu şöyle özetledi: aramanın kendisi DFS gibidir ama bellek karmaşıklığı BFS gibidir.
- **Optimallik:** Değildir.

Hoca bunların, değerlendirme fonksiyonuyla çalışan ağaç arama algoritmaları olduğunu söyledi. Ekstra bir bilgi kullanırlar ve bu onları kör (blind, uninformed) algoritmalardan ayırır. Bu bilgi bir sezgidir, mutlak bilgi değildir; kuş uçuşu uzaklık gibi başka sezgiler de olabilir. Kitap slaytında açgözlü aramanın, örneğin Iasi'den Fagaras'a giderken Neamt'ta takılıp kalabileceği gösterilir. Bir sonraki adım, hem geçmiş maliyeti hem sezgisel tahmini kullanan A* algoritmasıdır.

> **Ek bilgi (derste anlatılmadı):** A* algoritmasında değerlendirme fonksiyonu büyük olasılıkla $f(n) = g(n) + h(n)$ biçiminde tanımlanacaktır. Burada $g(n)$ başlangıçtan $n$'ye kadar harcanan gerçek maliyet (UCS'nin kullandığı bilgi), $h(n)$ ise $n$'den hedefe tahmini maliyettir (açgözlü aramanın kullandığı bilgi).

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00). Dallanma sayısı $b=10$, saniyede 1000 durum işleniyor ve durum başına 100 bayt bellek tutuluyor. Çözüm derinliği 2, 4, 8 ve 12 iken işlenen durum sayısı, süre ve bellek ne olur?

> **Çözüm:** İşlenen durum sayısı $\sum_{i=0}^{d} 10^i$'dir. $d=2$: 111 durum, 0,111 s, 11,1 KB. $d=4$: 11.111 durum, 11,1 s, 1,1 MB. $d=8$: 111.111.111 durum, 111.111 s ≈ 31 saat, ≈ 11 GB. $d=12$: ≈ $1{,}11\times10^{12}$ durum, ≈ $1{,}11\times10^{9}$ s ≈ 35 yıl, ≈ 111 TB (python ile doğrulandı).

**Soru 2** (derste sözlü, 00:14:25). İşlem kapasitesini $10^9$ kat artırsak arama zorluğu çözülür mü?

> **Çözüm:** Hayır. Süreler kısalır ama derinlik biraz artınca (örneğin 12 yerine 48) durum sayısı yine üssel büyür ve süre tekrar yıllara çıkar. Graflarda döngüler sorunu daha da ağırlaştırır.

**Soru 3** (ekrandan, 00:35:00). 1'in çocukları 2, 3; 2'nin 4, 5; 3'ün 6, 7; 4'ün 8, 9; 5'in 10, 11 olan ağaçta hedef 6 iken enlemesine aramada kuyruğun durumlarını, durum açma sırasını ve çözüm yolunu yazınız.

> **Çözüm:** Kuyruk: (1), (2 3), (3 4 5), (4 5 6 7), (5 6 7 8 9), (6 7 8 9 10 11). Açma sırası 1, 2, 3, 4, 5, 6; çözüm yolu 1, 3, 6.

**Soru 4** (derste sözlü, 00:27:26 ve 00:30:08). Enlemesine arama tam mıdır, optimal midir?

> **Çözüm:** $b$ sonluysa tamdır; çözüm ne kadar derinde olursa olsun bulunur. Yalnız bütün adım maliyetleri eşitse optimaldir; daha derindeki bir çözümün toplam maliyeti daha küçükse BFS'nin ilk bulduğu çözüm optimal olmaz.

**Soru 5** (derste sözlü, 00:44:02). Derinlemesine arama optimal midir? Neden?

> **Çözüm:** Değildir. DFS derine inip ilk bulduğu çözümde durur; adım maliyetleri eşit olsa bile, henüz uğramadığı daha sığ bir dalda daha az maliyetli bir çözüm olabilir.

**Soru 6** (ekrandan, 00:50:00). A-B 1, A-C 4, A-D 15, B-F 10, C-E 5, E-F 1, D-F 1 maliyetli grafta A'dan F'ye düşük maliyetli arama (UCS) adımlarını yazınız.

> **Çözüm:** min(1, 4, 15) = 1 → B; min(11, 4, 15) = 4 → C; min(11, 9, 15) = 9 → E; min(11, 10, 15) = 10 → F. Yol A-C-E-F, maliyet 10.

**Soru 7** (derste sözlü, 01:02:15). Artan derinlikli aramada sınırlı derinlikli aramaya göre ek gezinti oranı $b=10$, $d=5$ için yaklaşık %11'dir. $b$ ve $d$ değiştikçe bu oran nasıl değişir?

> **Çözüm (derste verilmedi):** Oran $N_{IDS}/N_{DLS} - 1$'dir. Python ile: $b=10,d=5$ için yaklaşık %11,1; $b=2,d=5$ için 120/63 ≈ 1,90, yani yaklaşık %90; $b=100,d=5$ için yaklaşık %1. Oran $d$'den çok $b$'ye bağlıdır ve $d$ büyüdükçe $1/(b-1)$ değerine yaklaşır ($b=10$ için %11,1, $b=2$ için %100); $b$ büyüdükçe ek maliyet önemsizleşir.

**Soru 8** (derste sözlü, 01:26:05). Artan derinlikli aramada sınırlı derinlikli arama (DFS) yerine sınırlı genişlikte arama (BFS) kullansak iyi mi olur?

> **Çözüm:** Kötü olur. BFS bir düğüme gidince altındaki bütün seviyeyi belleğe alır, yani bellek kötüleşir. Zaman karmaşıklığında BFS ile DFS arasında kazanç yoktur. Optimallikte de fark yoktur, çünkü artan derinlikli arama zaten optimaldir. Tamlıkta ikisi de tamdır. Sonuçta bellekte kaybedip başka hiçbir şey kazanmayan, tamamen kötü bir algoritma elde edilir.

**Soru 9** (ekrandan, 01:55:00). Romanya haritasında Arad'dan Bükreş'e kuş uçuşu uzaklıkla açgözlü en iyi ilk arama hangi yolu bulur? Bu yol optimal midir?

> **Çözüm:** Arad (366) → Sibiu (253; Timisoara 329, Zerind 374'ten küçük) → Fagaras (176) → Bükreş (0). Yol optimal değildir; hocanın gösterdiği optimal yolun maliyeti $140+80+97+101=418$'dir, bulunan yolunki ise büyük olasılıkla $140+99+211=450$'dir.

## Dersin Toparlaması

Bu derste arama problemlerinin tanımları üzerine kör (bilgisiz) arama algoritmaları kuruldu. Önce durum sayısının derinlikle üssel büyüdüğü ve bunun hem zaman hem bellek açısından aramayı zorlaştırdığı sayısal bir tabloyla gösterildi. Sonra algoritmalar tamlık, zaman karmaşıklığı, hafıza karmaşıklığı ve optimallik ölçütleriyle değerlendirildi: BFS tam ve eşit maliyette optimal ama bellek açısından üsseldir; DFS doğrusal bellek kullanır ama tam ve optimal değildir; UCS pozitif maliyetlerde optimaldir; artan derinlikli arama, küçük bir tekrar maliyetiyle DFS'nin belleğini BFS'nin tamlık ve optimalliğiyle birleştirir. Tekrarlayan durumların kontrol edilmemesinin algoritmayı döngüye sokabileceği ve MATLAB benzetiminde liste boyutlarının bu teorik karmaşıklıklarla uyumlu davrandığı görüldü.

Dersin son bölümünde sezgisel aramaya geçildi. UCS'nin geçmiş maliyete bakmasına karşılık, sezgisel algoritmalar hedefe olan uzaklığa dair bir tahmin (örneğin kuş uçuşu uzaklık) kullanır. Açgözlü en iyi ilk arama, Romanya haritasında hızlıca bir yol bulsa da optimal yolu kaçırdı. Bir sonraki adım, hem geçmiş maliyeti hem sezgisel tahmini birlikte kullanan A* algoritmasıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
