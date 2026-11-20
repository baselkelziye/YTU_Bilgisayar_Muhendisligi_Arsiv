# Ders 3 Genişletilmiş Notu: Kör (Bilgisiz) Arama Stratejileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Arama Algoritmalarını Karşılaştırma Kriterleri
- 2. Kör Arama Stratejileri
- 3. Enlemesine Arama: Adım Adım Bir Örnek
- 4. Kuyruğun Başına Eklemek: Derinlemesine Arama
- 5. Zaman ve Hafıza Karşılaştırması
- 6. Enlemesine Aramanın Analizi
- 7. Düşük Maliyetli Arama
- 8. Derinlemesine Aramanın Analizi
- 9. Sınırlı Derinlikte Arama
- 10. Artan Derinlikli Arama
- 11. Çift Yönlü Arama
- 12. Tekrarlayan Durumlar
- 13. Karşılaştırma ve Özet Tablo
- 14. Uygulama: my_search.m
- Örnek Sorular

## 1. Arama Algoritmalarını Karşılaştırma Kriterleri

Bir önceki derste enlemesine aramanın nasıl çalıştığına ve arama stratejilerinin değerlendirme kriterlerine bakılmıştı. Hoca konuya biraz geriden, bu kriterlerin tekrarıyla başladı. Arama algoritmalarını birbirleriyle karşılaştırmak için dört kriter kullanılır.

- **Tamlık (completeness):** Elimizdeki problemin, tanımladığımız kurallar içinde bir çözümü varsa algoritma onu mutlaka buluyorsa algoritma tamdır. Bulamadığı bir durum varsa tam değildir.
- **Zaman karmaşıklığı:** Aramanın ne kadar sürdüğü.
- **Hafıza (uzay) karmaşıklığı:** Aramayı yapabilmek için ne kadar belleğe (RAM'de ne kadar alana) ihtiyaç duyulduğu.
- **Optimumluk:** Bir problemin birden fazla çözümü ve bu çözümlerin farklı maliyetleri olabilir. Algoritmanın bulduğu **ilk** çözüm en düşük maliyetli çözüm ise algoritma optimaldir. En düşük maliyetli çözüm tek olmak zorunda değildir; ilk bulunan çözümün bunlardan biri olması yeterlidir. Algoritmanın optimum çözümü daha sonra bulması bizi ilgilendirmez.

Analizlerde şu semboller kullanılır: $b$ dallanma sayısı (branching factor), $d$ en az maliyetli (en sığ) çözümün derinliği, $m$ arama uzayının maksimum derinliği. Arama uzayının maksimum derinliği bazen sonsuz olabilir.

## 2. Kör Arama Stratejileri

Arama algoritmalarının ilk sınıfı kör arama algoritmalarıdır; ikinci sınıf (sezgisel arama) sonraki derslerde görülecektir. Kör arama stratejilerinin farklı adları vardır: kör, mekanik, bilgisiz, blind ya da uninformed arama. Bu derste altı algoritma ve bunların birbirine göre avantaj ve dezavantajları incelendi (ekrandan, 00:15:00):

- Enlemesine Arama (Breadth-first search)
- Düşük Maliyetli Arama (Uniform cost search)
- Derinlemesine Arama (Depth-first search)
- Sınırlı Derinlikte Arama (Depth-limited search)
- Artan Derinlikli Arama (Iterative deepening search)
- Çift Yönlü Arama (Bidirectional search)

## 3. Enlemesine Arama: Adım Adım Bir Örnek

Enlemesine arama önceki derste anlatılmıştı, ama hoca bu derste onu bir örnek üzerinde adım adım çalıştırdı. Slayttaki enlemesine arama sayfasında ağacın ve durumların en başta elimizde olmadığı, zaman içinde oluştuğu; çözümün bir durum sırası, durum açma sırasının da ayrı bir sıra olduğu ve bu ikisinin farklı şeyler olduğu yazıyordu. Enlemesine aramayı gerçekleştirmek için kuyruk (ilk giren ilk çıkar) kullanılır (ekrandan, 00:40:00).

### 3.1 Problem

Problem şöyle tanımlandı (ekrandan, 00:20:00):

```text
Baş: A
Hedef: 7

A -> B,C
B -> D,E
C -> H,G
D -> 1,2
E -> 3,4
H -> 5,6
G -> 7,8
```

Hoca, bu geçiş listesi elimizde olduğu için ağacın çizimini görmeye bile gerek olmadığını, hangi durumdan hangi duruma gidilebileceğinin kısıtlarının burada yazılı olduğunu belirtti. Hedef önce H olarak yazılmıştı, sonra 7 olarak değiştirildi.

### 3.2 Algoritma

Enlemesine arama algoritması slayttaki sözde kodla şöyledir (slayt küçük resminden, ekrandan, 00:20:00):

```text
kuyruk = [kök durum]
bulundu = FALSE
While (kuyruk <> boş) and (bulundu = FALSE)
    Kuyruktan ilk durumu (N) çek
    Eğer N hedef durumsa, bulundu = TRUE
    N'den gidilebilecek tüm durumları kuyruğun sonuna ekle
```

Döngünün iki koşulu vardır: kuyruğun boş olmaması ve `bulundu` değişkeninin hâlâ `FALSE` olması. İkisi de sağlandığı sürece döngü döner.

### 3.3 Çalıştırma

İlk adımda kuyruğa A atılır. A çekilir; kuyruk boşalır. A hedef değildir. A'dan gidilebilecek durumlar B ve C'dir; bunlar kuyruğun sonuna eklenir. İkinci adımda kuyruk boş değildir ve `bulundu` hâlâ `FALSE`'tur, döngüye tekrar girilir. Baştaki B çekilir, içeride C kalır; B'den gidilebilecek D ve E sona eklenir.

> **Not:** Hoca tahtada bu adımda B'nin çocuklarını eklemeyi atlayıp C'ye geçmişti; bir öğrenci "B'den gidilebilecekleri eklememiştik" diye uyardı ve hoca düzeltti. Aşağıdaki tablo düzeltilmiş hâlidir.

Ekrandaki "hafıza" sütunu her adımda kuyruğun içeriğini ve çekilen durumu gösteriyordu (ekrandan, 00:25:00):

| Adım | Kuyruk (çekmeden önce) | Çekilen | Sona eklenen |
|---|---|---|---|
| 1 | A | A | B, C |
| 2 | B C | B | D, E |
| 3 | C D E | C | H, G |
| 4 | D E H G | D | 1, 2 |
| 5 | E H G 1 2 | E | 3, 4 |
| 6 | H G 1 2 3 4 | H | 5, 6 |
| 7 | G 1 2 3 4 5 6 | G | 7, 8 |
| 8 | 1 2 3 4 5 6 7 8 | 1 | (yok) |
| 9 | 2 3 4 5 6 7 8 | 2 | (yok) |
| 10 | 3 4 5 6 7 8 | 3 | (yok) |
| 11 | 4 5 6 7 8 | 4 | (yok) |
| 12 | 5 6 7 8 | 5 | (yok) |
| 13 | 6 7 8 | 6 | (yok) |
| 14 | 7 8 | 7 | hedef bulundu |

1, 2, 3 gibi yaprak durumlardan gidilebilecek bir yer olmadığı için bu adımlarda kuyruğa ekleme yapılmaz. 7 çekildiğinde hedef olduğu görülür, `bulundu = TRUE` yapılır; ondan gidilebilecek bir şey olsa eklense de fark etmez, çünkü döngü sona erer. Çekilme sırası A, B, C, D, E, H, G, 1, 2, 3, 4, 5, 6, 7'dir: arama ağacı seviye seviye, enlemesine taranır.

## 4. Kuyruğun Başına Eklemek: Derinlemesine Arama

Hoca ardından aynı problemde algoritmada tek bir değişiklik yaptı: Bir durumdan gidilebilecek durumları kuyruğun sonuna değil **başına** eklersek ne olur?

Bu kez A çekilir, B ve C başa eklenir. B çekilir, içeride C kalır; B'nin çocukları D ve E başa eklenir, kuyruk D E C olur. D çekilir, 1 ve 2 başa eklenir. 1 çekilir; 1'den gidilecek yer yoktur. 2 çekilir; yine ekleme yoktur. E çekilir, 3 ve 4 başa eklenir; ardından 3 ve 4 çekilir. Kuyrukta tek başına C kalır. C çekilir, H ve G eklenir. H çekilir, 5 ve 6 başa eklenir; 5 ve 6 çekilir. G çekilir, 7 ve 8 eklenir. 7 çekildiğinde hedef bulunur (ekrandan, 00:30:00).

| Adım | Kuyruk (çekmeden önce) | Çekilen |
|---|---|---|
| 1 | A | A |
| 2 | B C | B |
| 3 | D E C | D |
| 4 | 1 2 E C | 1 |
| 5 | 2 E C | 2 |
| 6 | E C | E |
| 7 | 3 4 C | 3 |
| 8 | 4 C | 4 |
| 9 | C | C |
| 10 | H G | H |
| 11 | 5 6 G | 5 |
| 12 | 6 G | 6 |
| 13 | G | G |
| 14 | 7 8 | 7 |

Çekilme sırası A, B, D, 1, 2, E, 3, 4, C, H, 5, 6, G, 7'dir. Arama önce bir dalın en dibine iner, sonra yavaş yavaş yukarı çıkıp diğer dala geçer. Öğrenciler bunun derinlemesine arama olduğunu söyledi.

> **Hocanın vurgusu:** Enlemesine arama algoritmasında "kuyruğun sonuna ekle" yerine "kuyruğun başına ekle" dendiğinde algoritma derinlemesine aramaya dönüşür. Bu kadar basit.

Derinlemesine aramayı gerçekleştirmek için yığın (stack, son giren ilk çıkar) kullanılır (ekrandan, 01:00:00). Slayttaki derinlemesine arama algoritması da yalnız bu noktada farklıdır: `stack = [kök durum]`, döngüde "Stack'ten ilk durumu (N) çek" ve "N'den gidilebilecek tüm durumları stack'in başına ekle" (slayt küçük resminden, ekrandan, 01:20:00).

## 5. Zaman ve Hafıza Karşılaştırması

Hoca iki aramanın süresini sordu. Süre burada toplam çekilen eleman sayısıdır. İki aramada da hedefe 14 adımda ulaşıldı; zaman bakımından bir fark yoktur. Bir öğrenci farkın kuyruğun doluluk oranında olduğunu söyledi; hoca bunu onayladı: fark aramayı yapmak için tutulması gereken hafıza miktarındadır. Örnekte enlemesine aramanın kuyruğu en çok 8 elemana (1 2 3 4 5 6 7 8), derinlemesine aramanınki en çok 4 elemana (1 2 E C) çıktı (tablolardan, ara adım eklendi).

Enlemesine aramada bir seviyenin sonuna varıldığında, örneğin G çekildiğinde, o seviyedeki her düğüm kendi çocuklarını eklemiş olduğundan bir alt seviyedeki her şey algoritma gereği hafızadadır. Derinlemesine aramada ise böyle bir şey yoktur: bir düğüm seçilir, onun $b$ çocuğu eklenir, sonra bunlardan biri seçilir ve onun $b$ çocuğu eklenir. Ne kadar derine gidildiyse, o derinlik çarpı $b$ kadar eleman yeterlidir. Maksimum gereksinim hesaplandığı için derinlik olarak ağacın maksimum derinliği $m$ alınır; derinlemesine aramanın hafızası $b \cdot m$ olarak değerlendirilir.

> **Ders sonrası not:** Hoca 00:31:17 civarında bu ifadeyi söylerken "enlemesine aramada B çarpı M" dedi; bağlamdan ve slayttan anlaşıldığı üzere $b \cdot m$ derinlemesine aramanın hafızasıdır, enlemesine aramanınki $O(b^d)$'dir.

## 6. Enlemesine Aramanın Analizi

Slayttaki analiz şöyleydi (ekrandan, 00:35:00):

- **Complete?** Eğer $b$ sonlu ise evet.
- **Time?** $1 + b + b^2 + b^3 + \dots + b^d = O(b^d)$
- **Space?** $O(b^d)$ (her düğüm hafızada)
- **Optimal?** Her adımın maliyeti eşitse evet.
- **Hafıza** zamandan daha büyük problemdir.

### 6.1 Tamlık

Algoritma önce birinci seviyeye, sonra ikinciye, sonra üçüncüye bakarak sürekli seviye seviye ilerler. Bir algoritmanın çözüme erişememesi nasıl olur? Hoca bunu tekrarlayan durumlarla açıkladı: Örneğin 2. durumdan 1'e, 1'den 3'e, 3'ten tekrar 2'ye, sonra 1'e, sonra 3'e geçilebiliyorsa, ağaç bu döngü yüzünden aşağıya doğru sonsuza kadar uzayabilir; yani $m$ sonsuz olabilir. Maksimum derinlik sonsuz olsa bile enlemesine arama bu sonsuz dala takılmaz, çünkü önce üstteki seviyeleri bitirip öyle aşağı iner. Aşağıda bir yerde çözüm varsa ona mutlaka erişir. Bu yüzden enlemesine arama tamdır.

### 6.2 Optimallik

Hoca, örnek ağaçta hem 5'in hem 3'ün çözüm olduğunu ve tüm operatörlerin maliyetinin eşit olduğunu düşünmemizi istedi. 5'e ulaşmak için iki operatör (2 maliyet), 3'e ulaşmak için bir operatör (1 maliyet) uygulanmış olsun. Enlemesine arama hep köke en yakın olanları önce açtığı için 5'i hiçbir zaman 3'ten önce seçmez. Derinlemesine arama ise önce 5'e ulaşır; bulduğu çözüm 2 maliyetlidir, oysa 1 maliyetli daha iyi bir çözüm vardır. Bu yüzden enlemesine arama tüm maliyetler eşitken optimaldir; derinlemesine arama tüm maliyetler eşitken bile optimal değildir.

<!-- BELİRSİZ: Hocanın bu örnekte kullandığı 5 ve 3 düğümleri yeni bir küçük ağaçtan geliyor olabilir; altyazıda "1 maliyetli/2 maliyetli" ifadeleri karışık geçiyor. Ana fikir (köke yakın çözüm daha ucuzdur ve BFS onu önce açar) nettir. -->

## 7. Düşük Maliyetli Arama

### 7.1 Fikir

Düşük maliyetli arama (uniform cost search) enlemesine aramaya benzer. Farkı şudur: enlemesine arama yalnızca her adımın maliyeti eşitse optimaldir; düşük maliyetli arama ise maliyetler eşit değilse de, tümü pozitif olduğu sürece optimal çözümü bulur. Negatif maliyetler zaten sorunludur ve ele alınmaz. Algoritma kökten itibaren toplam maliyeti en az olan düğümü seçip genişletir. Tüm maliyetler birbirine eşitse enlemesine aramanın aynısı olur.

Hoca bunu şöyle açıkladı: Enlemesine arama aslında farkında olmadan maliyete göre seçim yapmaktadır. Yeni eklenen düğümler daha aşağıdaki, yani kökten daha yüksek maliyetli düğümlerdir ve enlemesine arama bunları hep kuyruğun sonuna atar; böylece hep düşük maliyetlileri çektirir. Derinlemesine arama ise yeni gelen, daha yüksek maliyetli düğümleri başa atar ve bunları çektirir. Sona atmak, bütün maliyetler eşitse optimallik sağlar; maliyetler farklıysa sağlamaz.

> **Ders sonrası not:** Hoca 00:38:42-00:39:25 arasında bu açıklamayı yaparken iki yerde "enlemesine" ile "derinlemesine"yi karıştırdı. Doğrusu yukarıdaki gibidir: yüksek maliyetlileri sona atan enlemesine arama, başa atan derinlemesine aramadır.

### 7.2 Maliyetler farklıysa uzun yol daha ucuz olabilir

Maliyetler eşitse köke yakın olan 3 kesin daha iyi bir çözümdür. Ama maliyetler farklıysa 5 daha iyi olabilir. Hocanın örneği: Bir çözüme tek adımda gitmek 100 dolar, öteki çözüme giden yolun ilk adımı 10 dolar, ikinci adımı 20 dolar olsun. Bu durumda iki adımlı çözüm 30 dolar, tek adımlı çözüm 100 dolardır.

<!-- BELİRSİZ: Hoca bu örnekte düğüm numaralarını (1, 2, 3, 5) karışık söyledi; maliyet değerleri (100, 10, 20, toplam 30) nettir. --> Yani daha fazla operatör içeren, daha uzun bir çözüm daha iyi olabilir. Bu yüzden maliyetler birbirinden farklıysa enlemesine arama optimal çözümü vermez; düşük maliyetli arama verir.

### 7.3 Algoritma

Slayttaki düşük maliyetli arama algoritması enlemesine aramanın aynısıdır, yalnız bir satır eklenmiştir (slayt küçük resminden, ekrandan, 00:20:00):

```text
kuyruk = [kök durum]
bulundu = FALSE
While (kuyruk <> boş) and (bulundu = FALSE)
    Kuyruktan ilk durumu (N) çek
    Eğer N hedef durumsa, bulundu = TRUE
    N'den gidilebilecek tüm durumları kuyruğun sonuna ekle
    Kuyruktaki durumları kökten maliyetlere göre küçükten büyüğe sırala
```

Kuyruk her adımda sıralandığı için en düşük maliyetli durum hep baştadır ve baştan çekmek sorun olmaz. Hoca, "baştakini çek" yerine doğrudan "en düşük maliyetliyi çek" de yazılabileceğini, tek farkın bu olduğunu söyledi.

### 7.4 Örnek

Durum/geçiş uzayı şöyledir (ekrandan, 00:45:00): A, B, C, D, E, F durumları; A'dan B'ye 1, A'dan C'ye, A'dan D'ye 15, B'den F'ye 10, C'den E'ye, E'den F'ye 1, D'den F'ye 1 maliyetli geçişler. Başlangıç A, hedef F'dir.

A'dan F'ye birçok yol vardır. Öğrenciler en ucuz yolu A-C-E-F olarak buldu: maliyeti 10'dur. Hocanın vurguladığı gibi bu yolda üç geçiş vardır (biri 5, biri 4, biri 1); diğer yollarda iki geçiş vardır ama bunlar daha pahalıdır (A-B-F 11, A-D-F 16). Daha fazla operatör içermesine rağmen maliyeti daha az olan bu yolu, düşük maliyetli arama optimal ise ilk çözüm olarak bulmalıdır.

<!-- BELİRSİZ: Slayttaki üst grafta A-C kenarı 5, C-E kenarı 4 yazıyor; altındaki arama ağaçlarında A-C 4, C-E 5 olarak yazılmış. Hoca konuşurken A-C için 5 dedi, ağaçlardaki min ifadelerinde C'nin maliyeti 4 görünüyor. İki durumda da E'nin maliyeti 9, A-C-E-F yolu 10'dur; aşağıdaki çözüm ağaçtaki değerlerle yazıldı. -->

Ekrandaki adımlar (ekrandan, 00:45:00):

- A açılır; kuyruğa B, C, D eklenir. $\min(1, 4, 15) = 1$, B çekilir.
- B'den F eklenir (A-B-F). Kuyruk F, C, D: $\min(10+1, 4, 15) = 4$, C çekilir. C ve D'nin maliyetleri değişmez.
- C'den E eklenir (A-C-E). Kuyruk F, E, D: $\min(10+1, 4+5, 15) = 9$, E çekilir.
- E'den F eklenir (A-C-E-F). Kuyruk F, F, D: $\min(10+1, 4+5+1, 15) = 10$, ikinci F çekilir.

Kuyrukta iki tane F vardır, ama bunlar farklı durumlardır: ilki A'dan B'ye, B'den F'ye gitmenin F'si (11), ikincisi A'dan C'ye, C'den E'ye, E'den F'ye gitmenin F'sidir (10). D hiç açılmamıştır. 10 maliyetli F çekildiği anda hedef bulunur ve arama sonlanır; algoritma gerçekten en düşük maliyetli çözümü bulmuştur. (Bu adımlar python ile her iki kenar ağırlığı seçeneği için ayrıca denendi; sonuç aynıdır.)

### 7.5 Analiz

Düşük maliyetli aramanın enlemesine aramadan tek farkı sıralama satırıdır. Zaman açısından bir iyileşme sağlamaz; hafıza hâlâ sorunludur. Değişen tek kısım optimalliktir. Slayttaki analiz küçük resimden okunduğu kadarıyla: Complete? $b$ sonlu ve maliyet $> 0$ ise evet; Time? $O(b^d)$; Space? $O(b^d)$; Optimal? Tüm maliyetler pozitifse evet; hafıza zamandan daha büyük problemdir (slayt küçük resminden, ekrandan, 00:35:00).

## 8. Derinlemesine Aramanın Analizi

Derinlemesine arama daha önce örnek üzerinde görülmüştü; hoca analizini şöyle verdi:

- **Complete?** Sonsuz derinlikli ya da döngü içeren arama uzayları için hayır. Algoritma değiştirilirse (örneğin tekrarlar engellenirse) olabilir.
- **Time?** $O(b^m)$. $m$, $d$'den çok büyükse kötüdür; ama çözümler uzayın içinde yoğunsa enlemesine aramadan daha hızlı bile olabilir.
- **Space?** $O(bm)$, yani doğrusal. Bu, algoritmanın iyi tarafıdır.
- **Optimal?** Hayır. Bulduğu çözümden daha iyisi olabilir.

Hoca özetle derinlemesine aramanın tamlık ve optimallik bakımından kötü, hafıza bakımından çok iyi olduğunu söyledi ve iki algoritmanın güzel taraflarını birleştiren bir algoritmaya doğru gidileceğini ekledi.

**Soru:** Derinlemesine arama çözümü bulma garantisi vermiyor dediniz; ama en alta gidip sonra yukarı çıkıyor, tekrar iniyor, sonunda her yeri gezmiş olmuyor mu? **Cevap:** Çok doğru, ama bu yalnızca arama ağacının derinliği sonsuz değilse geçerlidir. Derinlik sonsuzsa derinlemesine arama aşağı doğru dalıp gider ve geri dönmez. Enlemesine arama ise derinlik sonsuz olsa bile hep yukarıdan aşağı seviye seviye ilerlediği için çözüme erişebilir.

## 9. Sınırlı Derinlikte Arama

Sınırlı derinlikte arama (depth-limited search), derinlemesine aramanın derinliği sınırlandırılmış hâlidir. Derinlemesine arama uygulanır, ama bir sınır konur; örneğin "5 derinliğe kadar ara" denir ve 5. seviyenin altına hiçbir zaman inilmez.

**Tam mı?** Bir öğrenci tam olduğunu söyledi; hoca soruyu netleştirdi: Çözüm seçilen sınırın içindeyse ve varsa, sınırlı derinlikte arama onu kesinlikle bulur. Ağaç sonsuza kadar büyüyor olabilir, tekrarları yakalayan bir mekanizma da olmayabilir; bunlar önemli değildir. Daha aşağı inmesi engellendiği için arama bu kez yanlara doğru gitmeye başlar ve sınır içindeki çözümü mutlaka bulur. Çözüm sınırın altındaysa (örneğin sınır 5 iken çözüm 6. seviyede) oraya erişim olmadığından bulamaz.

> **Hocanın vurgusu:** Çözüm sınırın içindeyse sınırlı derinlikte arama onu mutlaka bulur; en kritik nokta budur.

**Optimal mi?** Hayır. Örneğin 5. seviyede bir çözüm, 3. seviyede daha iyi bir çözüm olabilir. İçeride derinlemesine arama uygulandığı için önce 5. seviyedeki çözüm açılabilir.

## 10. Artan Derinlikli Arama

### 10.1 Fikir

Artan derinlikli aramada (iterative deepening search) derinlik limiti sıfırdan başlatılır ve giderek artırılır; her artırmada o limitle sınırlı derinlikte arama yapılır. Yani sınırlı derinlikte arama bir `for` döngüsünün içine konur (slayt küçük resminde: "for derinlik limiti ($l$) = 0 to X", ekrandan, 01:00:00).

- Limit 0 ise yalnız kök kontrol edilir.
- Limit 1 ise kök, sonra birinci seviyedeki iki düğüm kontrol edilir.
- Limit 2 ise kök, B, B'nin çocukları, C, C'nin çocukları sırasıyla derinlemesine açılır.
- Limit 3 ise aynı işlem 3. seviyeye kadar derinlemesine yapılır (ekrandan, 01:05:00).

Hoca, limit 3'e kadar kökün kaç kez açıldığını sordu: limit 0, 1, 2 ve 3'te olmak üzere dört kez. Birinci seviyedekiler (B ve C) limit 0'da açılmaz, sonraki üç turda açılır; yani üç kez. İkinci seviyedekiler iki kez açılır. Aynı düğümler defalarca açılır, çünkü her turda arama sıfırlanıp baştan başlar.

Hoca, döngüdeki "X" üst sınırının aslında çözüm bulunana kadar dönecek bir koşul olarak tasarlanması gerektiğini belirtti.

### 10.2 Analiz

Slayttaki analiz (slayt küçük resminden, ekrandan, 01:05:00):

- **Complete?** Evet. Bir öğrencinin dediği gibi, çözüm varsa derinlik artırıla artırıla mutlaka bulunur.
- **Time?** $(d+1)b^0 + d\,b^1 + (d-1)b^2 + \dots + b^d = O(b^d)$. Aynı düğüm defalarca açıldığı için zaman biraz sıkıntılıdır, ama toplamın en büyük terimi $b^d$ olduğu için asimptotik olarak hâlâ $O(b^d)$'dir.
- **Space?** $O(bd)$. İçeride hâlâ derinlemesine arama çalıştığı için hafıza doğrusaldır. Dikkat: $b \cdot m$ değil $b \cdot d$; çözüm bulununca durulduğu için çözümün derinliğine kadar inilir.
- **Optimal?** Tüm maliyetler eşitse evet.

**Soru:** (Hoca sordu) Artan derinlikli arama optimal midir? Bir öğrenci, aynı düğümü defalarca açtığı için hiç optimal olmadığını söyledi. **Cevap:** Hoca bunun yanlış yere takılmak olduğunu belirtti. Optimalliğin tanımı ilk bulunan çözümün en iyi çözüm olmasıdır; daha uzun sürmek, daha fazla hafıza gerektirmek optimallikle ilgili değildir. Limit sıfırdan başlayıp birer birer arttığı için yukarıdaki bir çözüm mutlaka aşağıdakinden önce bulunur. Bu yüzden algoritma, tüm maliyetler eşitse optimaldir; enlemesine aramanın optimalliği gibi bir optimalliktir.

> **Hocanın vurgusu:** Optimal demek, daha hızlı ya da daha az hafızalı olmak demek değildir; bulunan ilk çözümün en düşük maliyetli olması demektir.

### 10.3 Fazlalığın bedeli

Bu özellikler bir fazlalık pahasına kazanılır. En son seviyedekiler bir kez açılır; onun bir üstündekiler hem kendi turunda hem bir önceki turda açıldığı için iki kez; iki üsttekiler üç kez; kök ise $d+1$ kez açılır. Burada $d$, çözümün bulunduğu derinliktir. Derinlik arttıkça fazlalık artar ve en çok baştaki düğümler tekrar açılır.

Slayttaki karşılaştırma (ekrandan, 01:10:00):

$$N_{DLS} = b^0 + b^1 + b^2 + \dots + b^{d-2} + b^{d-1} + b^d$$

$$N_{IDS} = (d+1)b^0 + d\,b^1 + (d-1)b^2 + \dots + 3b^{d-2} + 2b^{d-1} + 1\,b^d$$

$b = 10$, $d = 5$ için:

- $N_{DLS} = 1 + 10 + 100 + 1.000 + 10.000 + 100.000 = 111.111$
- $N_{IDS} = 6 + 50 + 400 + 3.000 + 20.000 + 100.000 = 123.456$
- Fazlalık oranı $= (123.456 - 111.111) / 111.111 \approx \%11$

Bu değerler python ile doğrulandı. Slayttaki son madde: bu fazlalıkla optimumluk elde ediliyor. Hoca, $b$ ve $d$ değiştikçe bu oranın nasıl değiştiğini ve bir üst sınırı olup olmadığını düşünmeyi öğrencilere bıraktı. İpucu olarak, en büyük terim olan en son seviyenin yalnız bir kez açıldığını, büyük fazlalıkların ise küçük terimlerin bulunduğu başlarda olduğunu, bu yüzden korkunç büyük fazlalıklar oluşmayacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** $b > 1$ için $N_{IDS}/N_{DLS}$ oranı büyük $d$'lerde büyük olasılıkla $b/(b-1)$ değerine yaklaşır; $b = 10$ için bu yaklaşık 1,11'dir ve fazlalık en fazla %11 civarında kalır. $b = 2$ gibi küçük dallanmalarda oran 2'ye yaklaşır.

### 10.4 İçeride enlemesine arama yapılırsa?

Hoca bir soru sordu: Artan derinlikli aramada her turda derinlemesine arama yerine enlemesine arama yapılırsa ne olur?

**Soru:** (Bir öğrenci) Zaten enlemesine arama yapmıyor muyuz; önce bir birim gidiyor, sonra iki birim? **Cevap:** Hayır; her turda çalışan algoritma derinlemesine aramadır, yalnız limitlenmiştir. Örneğin limit 3 iken sanki o kadarlık bir ağaç varmış gibi o ağaçta derinlemesine arama yapılır. Limit altına inilmez; o seviyede çözüm bulunmazsa limit bir artırılıp arama baştan yapılır, çözüm bulunana kadar.

Soru hakkında öğrenciler, tamlığın korunacağını ve zamanın aynı fazlalığa sahip olacağını söyledi; bir öğrenci ise kuyruğun çok dolacağına dikkat çekti. Hoca cevabı şöyle bağladı: Her turda kuyruk sıfırlanıp baştan başlansa da enlemesine arama kuyruğu çok doldurduğu için hafıza $O(b^d)$ olur ve $O(bd)$ hafıza kazancı kaybedilir. Optimallik korunur, ama bu hâl zaten enlemesine aramanın aynısıdır. Artan derinlikli aramanın derinlemesine aramaya göre getirdiği kazanç tam olarak hafıza kısmıdır; o da kaybedilince enlemesine aramayı boşu boşuna tekrar etmiş oluruz.

> **Hocanın vurgusu:** Artan derinlikli aramada içeride derinlemesine arama yapmazsanız enlemesine aramayı boşuna tekrar etmiş olursunuz; o zaman doğrudan enlemesine arama yapın.

## 11. Çift Yönlü Arama

Çift yönlü aramada (bidirectional search) başlangıçtan çözüme doğru ilerlemek yerine aynı anda hem başlangıçtan hem hedeften başlayarak iki yönden arama yapılır. İki arama ortada bir yerde kesiştiğinde arama sonlandırılır. Her adımda iki sürecin içindeki durumlar karşılaştırılır; herhangi bir durum birbiriyle eşleştiği anda iki yol birleştirilir.

Bu yöntem karmaşıklığı $b^d$'den $b^{d/2}$'ye indirir. $d$ derinlikli tek bir arama yerine iki tane $d/2$ derinlikli arama yapılır: $2\,b^{d/2}$, $b^d$'den çok çok daha küçüktür. İki yönde de enlemesine arama ya da düşük maliyetli arama, hatta artan derinlikli arama kullanılabilir; derinlemesine arama burada makul olmaz. Önemli olan derinliği yarıya indirebilmesidir.

Hocanın verdiği sayısal karşılaştırma: Çözüm 6 derinlikteyse çift yönlü aramada oluşturulan düğüm sayısı 2.222, doğrudan enlemesine aramada ise 1.111.111'dir. Bu sayılar $b$ ve $d$'ye bağlıdır.

<!-- BELİRSİZ: Slayt 34 karede yalnız küçük resim olarak göründü, değerler okunamadı. Sayılar $b = 10$ ile tutarlıdır: $2(1 + 10 + 100 + 1.000) = 2.222$ ve $1 + 10 + \dots + 10^6 = 1.111.111$ (python ile denendi). -->

Çift yönlü arama özellikle zaman ve hafıza noktasında iyileşme sağlar.

> **Ek bilgi (derste anlatılmadı):** Çift yönlü arama için hedef durumun açıkça bilinmesi ve geçişlerin geriye doğru da hesaplanabilmesi (bir durumun öncüllerinin bulunabilmesi) gerekir; bu her problemde mümkün olmayabilir.

## 12. Tekrarlayan Durumlar

Hoca, arama ağacının nasıl sonsuz derinlikli olabileceğini bir örnekle gösterdi (ekrandan, 01:20:00):

```text
A -> D
D -> E
E -> A, F
Başlangıç: A, Hedef: F
```

A'dan başlayıp derinlemesine arama yapılırsa, yığının içeriği (yol gösterimiyle) şöyle ilerler. Burada `E(ADE)` ifadesi E'ye A-D-E yolunu izleyerek varmak demektir:

```text
A
D(AD)
E(ADE)
A(ADEA) F(ADEF)
D(ADEAD) F(ADEF)
E(ADEADE) F(ADEF)
A(ADEADEA) F(ADEADEF) F(ADEF)
D(ADEADEAD) F(ADEADEF) F(ADEF)
E(ADEADEADE) F(ADEADEF) F(ADEF)
A(ADEADEADEA) F(ADEADEADEF) F(ADEADEF) F(ADEF)
...
```

E'den A ve F'ye gidilebildiği için ikisi de başa eklenir; derinlemesine arama önce A'yı seçer ve döngü baştan başlar. F hep yığının altında birikir ve hiç açılamaz; algoritma sonsuza kadar döner. Bu kadar basit bir problemde bile arama uzayının derinliği $m$ sonsuz hâle gelebilir. Üç beş düğümlü bir problemde bunu elle görmek kolaydır, ama yüzlerce düğüm ve geçiş olduğunda döngü olup olmadığını elle analiz etmek oldukça güçtür.

İki A durumu arasındaki farka dikkat: `A(ADEA)`'daki A, A-D-E-A yolunu izleyerek A'ya varmak demektir; başlangıçtaki A ise yalnız A'dır.

**Çözüm:** Yeni durumları eklemeden önce kontrol yapmak; durum yolda zaten varsa eklememek (ekrandan, 01:20:00). Örneğin `E(ADE)`'den A'ya ve F'ye gidilebilir; A yolda zaten vardır, bu yüzden A-D-E-A diye yeni ve daha büyük bir durum oluşturmanın anlamı yoktur. F yolda yoktur, eklenir; A-D-E-F oluşturulur. Bu tür kontrollerle döngüler engellenebilir ve hafızadaki düğüm sayısı da sınırlanır. Algoritmadaki "N'den gidilebilecek tüm durumları başa ekle" satırı, "N'den gidilebilecek durumlardan yolda zaten olmayanları başa ekle" biçimine dönüşür.

Enlemesine arama ve artan derinlikli arama ise böyle bir kontrol olmadan da bu örnekte F'ye doğrudan erişir. Bu kontrol özellikle derinlemesine arama için önerilir.

## 13. Karşılaştırma ve Özet Tablo

Hoca üç temel algoritmayı şöyle karşılaştırdı:

- **Derinlemesine arama:** Hafıza gereksinimi doğrusal (iyi). Döngü içeren arama uzaylarında sonsuza kadar çalışabilir (kötü). Optimum çözümü bulmayı garantilemez (kötü).
- **Enlemesine arama:** Optimum çözümü bulur (iyi). Döngülerden kurtulabilir (iyi). Hafıza gereksinimi derinlikle üstel olarak büyür (kötü).
- **Artan derinlikli arama:** Doğrusal hafıza gereksinimi, döngülerden kurtulabilme ve optimal çözümü garantileme. Derinlemesine ve enlemesine aramanın iyi taraflarını alıp kötü taraflarından kurtulan bir algoritmadır.

Kör arama stratejilerinin analiz tablosu (ekrandan, 01:25:00):

| Kriter | Breadth First | Uniform Cost | Depth-First | Depth-Limited | Iterative Deepening | Bidirectional |
|---|---|---|---|---|---|---|
| Time | $b^d$ | $b^d$ | $b^m$ | $b^l$ | $b^d$ | $b^{d/2}$ |
| Space | $b^d$ | $b^d$ | $bm$ | $bl$ | $bd$ | $b^{d/2}$ |
| Optimal | Yes | Yes | No | No | Yes | Yes |
| Complete | Yes | Yes | No | Yes, if $l \ge d$ | Yes | Yes |

$b$: dallanma sayısı, $d$: en sığ çözümün derinliği, $m$: ağacın maksimum derinliği, $l$: derinlik limiti. Hoca tabloda artan derinlikli aramanın optimallik satırındaki güzel kısmını ve çift yönlü aramanın $d/2$'li değerlerini işaret etti.

## 14. Uygulama: my_search.m

Bu algoritmaların MATLAB kodu my_search.m dosyasındadır. Hoca kodun bir çıktısını gösterdi (ekrandan, 01:30:00). Rastgele üretilmiş bir haritada kırmızı numaralı noktalar şehirleri, aralarındaki çizgiler yolları, çizgilerin üstündeki sayılar yol uzunluklarını (km) gösterir. Örneğin 11. şehir ile 9. şehir arasında 27 km, 6. şehir ile 15. şehir arasında 42 km'lik yol vardır. Amaç 12 numaralı şehirden 1 numaralı şehre giden bir yol bulmaktır.

Ekrandaki sonuçlar (ekrandan, 01:30:00):

```text
maliyetler:   dfs=314 bfs=128 ucs=110 bsfs=110 as=110
adimsayilari: dfs=24  bfs=37  ucs=79  bsfs=5   as=6

breadth first yol = 12 4 2 5 1
uniform cost yol  = 12 9 15 7 1
depth first yol   = 12 11 9 15 18 17 13 10 7 14 8 5 1
astar yol         = 12 9 15 7 1   (sonraki derste)
best first yol    = 12 9 15 18 1
```

Bulunan her yol geçerli bir yoldur. Derinlemesine aramanın yolu 314 km'dir ve 12'den 11, 9, 15, 18, 17, 13, 10, 7, 14, 8, 5 üzerinden 1'e giden saçma bir yoldur. Enlemesine aramanın yolu (12-4-2-5-1) 128 km'dir. Düşük maliyetli aramanın yolu (12-9-15-7-1) 110 km ile en iyisidir.

> **Ders sonrası not:** Hoca 01:27:05'te önce "Breadth first search'ün bulduğu yol 314 km" dedi, ardından düzeltti; 314 km derinlemesine aramanın yoludur. 01:27:45'te derinlemesine arama için "312 km" dedi; ekrandaki değer 314'tür.

Burada maliyetler yolların uzunluklarıdır ve birbirine eşit değildir. Bu yüzden enlemesine aramanın optimum çözüm vermesi beklenmez; bütün yollar eşit uzunlukta olsaydı verirdi. Maliyetler farklı olduğunda optimal çözümü veren düşük maliyetli aramadır ve 110 km'lik yolu bulmuştur.

### 14.1 Liste boyutu grafiği

Sağdaki grafik, çözüm sürecindeki her adımda (her çekme-ekleme işleminde) listenin boyutunu, yani arka tarafta tutulan hafıza gereksinimini gösterir. Beklenti, derinlemesine aramanın gereksiniminin az, enlemesine ve düşük maliyetli aramanınkinin yüksek olmasıdır. Grafikte derinlemesine aramanın eğrisi yana doğru ilerler, üstel biçimde yükselmez; enlemesine ve düşük maliyetli aramanın eğrileri adım sayısı büyüdükçe yukarı doğru gider.

Adım sayıları: derinlemesine arama 24, enlemesine arama 37, düşük maliyetli arama 79. Derinlemesine arama en az adımı atmış, ama bulduğu çözüm berbattır. Düşük maliyetli arama en çok adımı atmış, ama optimal çözümü bulmuştur.

### 14.2 Kör aramanın neye kör olduğu

Hoca derinlemesine aramanın yolundaki hareketleri inceledi: 12'den 11'e, 9'a, 15'e, 18'e gitmesi mantıklıdır; 18'den 1'e gitse iş bitecektir. Ama 17'ye, 13'e, 10'a, 7'ye, sonra tekrar 14'e, 8'e, 5'e gider ve en son 1'e varır. Bu mantıksız hareketlerin ortak özelliği, öğrencilerin de söylediği gibi, hedeften uzaklaşan hareketler olmalarıdır.

Kör arama algoritmaları "hedefe yakın mıyım, hedeften uzak mıyım" bilgisini hiçbir şekilde kullanmaz; bu bilgi onlara verilmez. Ya mekanik olarak başa ya da sona ekleme yaparlar ya da kökten itibaren o ana kadarki maliyete bakarlar. Sezgisel arama algoritmaları ise hedefe yakınlık bilgisini kullanır ve hâlâ optimal çözüme erişirken çok daha az adım atar: düşük maliyetli arama 110 km'lik optimal yolu 79 adımda bulurken A* aynı yolu 6 adımda bulmuştur. Best-first arama ve A* bir sonraki derste anlatılacaktır.

<!-- BELİRSİZ: Ekranda best first yolu 12-9-15-18-1, maliyeti 110 olarak verilmiş; bu yol UCS ve A* yolundan (12-9-15-7-1) farklı ama aynı maliyette görünüyor. Haritadaki kenar etiketleri karede tam okunamadığı için doğrulanamadı. -->

Hoca kodun MATLAB'ın standart fonksiyonlarıyla çalıştığını, ek paket gerektirmediğini; haritanın rastgele üretildiği için yeni haritalarla denenebileceğini söyledi. Octave'da da çalışıyor olabileceğini, ama bunu denemediğini ekledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): Baş durum A, hedef 7 ve geçişler $A \to B,C$; $B \to D,E$; $C \to H,G$; $D \to 1,2$; $E \to 3,4$; $H \to 5,6$; $G \to 7,8$ olsun. Enlemesine aramada her adımda kuyruğun içeriğini ve çekilen durumu yazın.

> **Çözüm (derste verildi):** Kuyruk: A; BC; CDE; DEHG; EHG12; HG1234; G123456; 12345678; 2345678; 345678; 45678; 5678; 678; 78. Çekilme sırası A, B, C, D, E, H, G, 1, 2, 3, 4, 5, 6, 7; hedefe 14 adımda ulaşılır (ekrandan, 00:25:00).

**Soru 2** (derste sözlü, 00:23:02): Aynı problemde algoritmadaki "kuyruğun sonuna ekle" satırı "kuyruğun başına ekle" yapılırsa arama nasıl ilerler? Bu hangi aramadır?

> **Çözüm (derste verildi):** Kuyruk: A; BC; DEC; 12EC; 2EC; EC; 34C; 4C; C; HG; 56G; 6G; G; 78. Çekilme sırası A, B, D, 1, 2, E, 3, 4, C, H, 5, 6, G, 7 (14 adım). Bu derinlemesine aramadır (ekrandan, 00:30:00).

**Soru 3** (derste sözlü, 00:28:48): Bu iki aramanın süreleri farklı mı? Aralarında başka ne fark var?

> **Çözüm (derste verildi):** İkisi de 14 durum çeker, süre aynıdır. Fark hafızadadır: enlemesine aramada kuyruk en çok 8 elemana, derinlemesine aramada en çok 4 elemana çıkar. Genel olarak enlemesine arama $O(b^d)$, derinlemesine arama $O(bm)$ hafıza gerektirir.

**Soru 4** (ekrandan, 00:45:00): A'dan B'ye 1, A'dan C'ye 4, A'dan D'ye 15, B'den F'ye 10, C'den E'ye 5, E'den F'ye 1, D'den F'ye 1 maliyetli geçişler veriliyor (ağaçlardaki değerler). Başlangıç A, hedef F'dir. En düşük maliyetli yol hangisidir ve düşük maliyetli arama onu nasıl bulur?

> **Çözüm (derste verildi):** En ucuz yol A-C-E-F, maliyet 10. Seçimler: $\min(1, 4, 15) \to$ B; $\min(11, 4, 15) \to$ C; $\min(11, 9, 15) \to$ E; $\min(11, 10, 15) \to$ F (A-C-E-F). İlk bulunan çözüm en ucuz çözümdür.

**Soru 5** (derste sözlü, 01:00:01): Derinlemesine arama 5 derinlikle sınırlandırılırsa (sınırlı derinlikte arama) tam mıdır? Optimal midir?

> **Çözüm (derste verildi):** Çözüm sınırın içindeyse kesinlikle bulunur; sınırın altındaysa bulunamaz ($l \ge d$ ise tam). Optimal değildir: 3. seviyede daha iyi bir çözüm varken önce 5. seviyedeki çözüm açılabilir.

**Soru 6** (derste sözlü, 01:06:32): Artan derinlikli arama optimal midir?

> **Çözüm (derste verildi):** Tüm maliyetler eşitse evet. Limit sıfırdan başlayıp birer artırıldığı için yukarıdaki bir çözüm aşağıdakinden önce bulunur. Aynı düğümün defalarca açılması optimallikle ilgili değildir, yalnız zamanı etkiler.

**Soru 7** (ekrandan, 01:10:00): $b = 10$, $d = 5$ için sınırlı derinlikte arama ve artan derinlikli aramada üretilen düğüm sayılarını ve fazlalık oranını hesaplayın.

> **Çözüm (derste verildi):** $N_{DLS} = 1 + 10 + 100 + 1.000 + 10.000 + 100.000 = 111.111$; $N_{IDS} = 6 + 50 + 400 + 3.000 + 20.000 + 100.000 = 123.456$; fazlalık $= (123.456 - 111.111)/111.111 \approx \%11$.

**Soru 8** (ekrandan, 01:05:00): Artan derinlikli aramada içeride derinlemesine arama yerine enlemesine arama yapılırsa ne olur?

> **Çözüm (derste verildi):** Tamlık ve optimallik korunur, zaman aynı fazlalığa sahip olur; ancak hafıza $O(bd)$'den $O(b^d)$'ye çıkar. Artan derinlikli aramanın kazancı hafızada olduğundan bu, enlemesine aramayı boşuna tekrar etmek olur.

**Soru 9** (ekrandan, 01:20:00): $A \to D$, $D \to E$, $E \to A,F$ geçişleri veriliyor; F hedeftir. A'dan başlayıp derinlemesine arama yaparsak ne olur? Nasıl çözülür?

> **Çözüm (derste verildi):** Yığın A; D(AD); E(ADE); A(ADEA) F(ADEF); D(ADEAD) F(ADEF); ... biçiminde ilerler, algoritma A-D-E döngüsünde sonsuza kadar döner ve F'yi hiç açamaz. Çözüm: yeni durumları eklemeden önce kontrol etmek, yolda varsa eklememek; E(ADE)'den A eklenmez, F eklenir ve ADEF bulunur.

**Soru 10** (ekrandan, 01:30:00): my_search.m çıktısında derinlemesine aramanın 12'den 1'e bulduğu yoldaki mantıksız hareketlerin ortak özelliği nedir?

> **Çözüm (derste verildi):** Hedeften uzaklaşan hareketlerdir. Kör arama algoritmaları hedefe yakınlık bilgisini kullanmaz; sezgisel algoritmalar bu bilgiyi kullanarak optimal çözümü çok daha az adımda (A* 6 adım, UCS 79 adım) bulur.

## Dersin Toparlaması

Bu derste kör (bilgisiz) arama stratejilerinin altısı ele alındı. Enlemesine arama kuyruğun sonuna ekleyerek seviye seviye ilerler; tamdır ve eşit maliyetlerde optimaldir, ama hafızası $O(b^d)$'dir. Aynı algoritmada başa ekleme yapmak derinlemesine aramayı verir; hafızası doğrusaldır, ama döngülere ve sonsuz derinliğe karşı savunmasızdır ve optimal değildir. Düşük maliyetli arama kuyruğu kökten maliyete göre sıralayarak pozitif maliyetlerde optimal çözümü bulur. Sınırlı derinlikte arama derinlemesine aramaya bir sınır koyar; artan derinlikli arama bu sınırı sıfırdan artırarak, yaklaşık %11'lik bir zaman fazlalığıyla doğrusal hafıza, tamlık ve eşit maliyetlerde optimallik sağlar. Çift yönlü arama iki yönden ilerleyerek maliyeti $b^{d/2}$'ye indirir. Tekrarlayan durumlar, yeni durum eklenmeden önce yolda olup olmadığı kontrol edilerek engellenebilir.

my_search.m örneğinde kör algoritmaların hedefe yakınlık bilgisini kullanmadığı, bu yüzden derinlemesine aramanın hedeften uzaklaşan saçma bir yol bulduğu, düşük maliyetli aramanın ise optimal yolu ancak çok sayıda adımla bulduğu görüldü. Bir sonraki derste bu bilgiyi kullanan sezgisel arama algoritmaları, best-first arama ve A*, ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
