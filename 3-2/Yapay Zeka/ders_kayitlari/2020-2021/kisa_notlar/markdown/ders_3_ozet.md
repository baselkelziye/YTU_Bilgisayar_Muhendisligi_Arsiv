# Ders 3 Çalışma Özeti

## Genel Konular

- Arama algoritmalarını karşılaştırma kriterleri
  - Tamlık (completeness): Bir çözüm varsa algoritma onu mutlaka buluyorsa tamdır.
  - Zaman karmaşıklığı: Aramanın ne kadar sürdüğü (açılan/çekilen düğüm sayısı).
  - Hafıza (uzay) karmaşıklığı: Arama sırasında bellekte tutulması gereken düğüm sayısı.
  - Optimumluk: Algoritmanın bulduğu **ilk** çözümün en düşük maliyetli çözüm (ya da en düşük maliyetli çözümlerden biri) olması. Optimal çözüm birden fazla olabilir; sonradan optimum çözümü bulmak algoritmayı optimal yapmaz.
  - Kullanılan semboller: $b$ dallanma sayısı, $d$ en az maliyetli (en sığ) çözümün derinliği, $m$ arama uzayının maksimum derinliği (sonsuz olabilir), $l$ derinlik limiti.
- Kör (mekanik, bilgisiz, uninformed) arama stratejileri
  - Derste altı algoritma ele alındı: enlemesine arama, düşük maliyetli arama, derinlemesine arama, sınırlı derinlikte arama, artan derinlikli arama, çift yönlü arama (ekrandan, 00:15:00).
- Enlemesine arama (Breadth-first search, BFS)
  - Kuyruk (ilk giren ilk çıkar) kullanır. Kuyruğa kök durum konur; döngüde kuyruğun başındaki durum çekilir, hedefse arama biter, değilse ondan gidilebilecek durumlar kuyruğun **sonuna** eklenir.
  - Derste $A \to B,C$; $B \to D,E$; $C \to H,G$; $D \to 1,2$; $E \to 3,4$; $H \to 5,6$; $G \to 7,8$ ağacında başlangıç A, hedef 7 ile adım adım çalıştırıldı. Çekilme sırası: A, B, C, D, E, H, G, 1, 2, 3, 4, 5, 6, 7 (14 adım) (ekrandan, 00:25:00).
  - Analiz: $b$ sonluysa tam; zaman $1+b+b^2+\dots+b^d = O(b^d)$; hafıza $O(b^d)$ (her düğüm hafızada); her adımın maliyeti eşitse optimal. Hafıza zamandan daha büyük problemdir (ekrandan, 00:35:00).
- Derinlemesine arama (Depth-first search, DFS)
  - Enlemesine arama algoritmasında yeni durumlar kuyruğun sonu yerine **başına** eklenirse algoritma derinlemesine aramaya dönüşür. Gerçekleştirmek için yığın (stack, son giren ilk çıkar) kullanılır (ekrandan, 01:00:00).
  - Aynı örnekte çekilme sırası: A, B, D, 1, 2, E, 3, 4, C, H, 5, 6, G, 7 (yine 14 adım) (ekrandan, 00:30:00).
  - Analiz: sonsuz derinlikli ya da döngü içeren uzaylarda tam değil; zaman $O(b^m)$ ($m \gg d$ ise kötü, çözümler yoğunsa BFS'ten hızlı olabilir); hafıza $O(bm)$ yani doğrusal; optimal değil.
- Düşük maliyetli arama (Uniform cost search, UCS)
  - Enlemesine aramaya benzer; tek fark, kuyruktaki durumların kökten itibaren toplam maliyete göre küçükten büyüğe sıralanması ve en düşük maliyetlinin çekilmesidir.
  - Maliyetler eşit olmasa da, tümü pozitif olduğu sürece optimal çözümü bulur. Tüm maliyetler eşitse enlemesine aramanın aynısıdır.
  - Derste A başlangıç, F hedef olan graf üzerinde çalıştırıldı ve en ucuz yol A-C-E-F (maliyet 10) bulundu (ekrandan, 00:45:00).
  - Analiz: zaman ve hafıza $O(b^d)$; hafıza yine asıl sorundur.
- Sınırlı derinlikte arama (Depth-limited search, DLS)
  - Derinlik sınırı $l$ konmuş derinlemesine aramadır. Çözüm sınırın içindeyse kesinlikle bulunur ($l \ge d$ ise tam); sınırın altındaysa bulunamaz. Optimal değildir.
- Artan derinlikli arama (Iterative deepening search, IDS)
  - Derinlik limiti 0'dan başlatılır ve her turda bir artırılarak sınırlı derinlikte arama tekrarlanır (sınırlı derinlikte arama bir `for` döngüsüne konur).
  - Üst seviyedeki düğümler defalarca açılır, ama fazlalık küçüktür: $b=10$, $d=5$ için $N_{DLS}=111.111$, $N_{IDS}=123.456$, fazlalık oranı yaklaşık %11 (ekrandan, 01:10:00).
  - Analiz: tam; zaman $O(b^d)$; hafıza $O(bd)$; tüm maliyetler eşitse optimal.
- Çift yönlü arama (Bidirectional search)
  - Aynı anda başlangıçtan ve hedeften arama yapılır; iki aramanın durumları bir noktada eşleşince yollar birleştirilir.
  - Zaman ve hafızayı $O(b^{d/2})$'ye indirir. Her iki yönde enlemesine ya da düşük maliyetli arama (veya artan derinlikli arama) uygundur; derinlemesine arama makul değildir.
- Tekrarlayan durumlar
  - $A \to D$, $D \to E$, $E \to A,F$ örneğinde A'dan başlayan derinlemesine arama, F hedefi hiç açamadan A-D-E-A-D-E... döngüsüne girer (ekrandan, 01:20:00).
  - Çözüm: yeni durumları eklemeden önce yolda zaten var mı diye kontrol etmek; varsa eklememek. Böylece hafızadaki düğüm sayısı da sınırlanır.
- Uygulama: my_search.m (MATLAB)
  - Rastgele üretilmiş şehir haritasında 12. şehirden 1. şehre yol arandı. Bulunan yol uzunlukları: DFS 314, BFS 128, UCS 110; adım sayıları: DFS 24, BFS 37, UCS 79 (ekrandan, 01:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Optimalliğin tanımı
  - Optimal olmak, daha hızlı ya da daha az hafızalı olmak değildir; yalnızca bulunan **ilk** çözümün en düşük maliyetli olması demektir. Bir öğrencinin "aynı düğümü defalarca açtığı için optimal değil" cevabı bu yüzden yanlış bulundu.
- BFS ile DFS arasındaki tek kod farkı
  - Yeni durumları kuyruğun sonuna eklemek BFS'i, başına eklemek DFS'i verir. İkisinin örnekteki süresi aynı (14 adım), fark hafızada.
- DFS'in tamlık sorunu sonsuz derinlikten kaynaklanır
  - Derinlik sonluysa DFS her yeri gezer; fakat döngüler yüzünden uzay sonsuz derinlikli olabilir ve DFS bir dala dalıp çıkamaz. BFS seviye seviye ilerlediği için bu tuzağa düşmez.
- Maliyetler eşit değilse BFS optimal değildir
  - Daha çok operatör içeren daha uzun bir yol daha ucuz olabilir; bu durumda optimal çözümü UCS verir.
- Artan derinlikli arama iki algoritmanın iyi yanlarını birleştirir
  - DFS'in doğrusal hafızası ile BFS'in tamlık ve (eşit maliyette) optimalliğini %11 civarında bir zaman fazlalığıyla elde eder. İçinde derinlemesine yerine enlemesine arama çalıştırmak $O(bd)$ hafıza kazancını yok eder ve anlamsızdır.
- Kör aramanın eksikliği
  - Kör algoritmalar hedefe yakın olup olmadıklarına dair hiçbir bilgi kullanmaz; DFS'in haritadaki saçma yolu bu yüzdendir. Sezgisel algoritmalar (A*, best-first) bu bilgiyi kullanarak aynı optimal çözümü çok daha az adımda bulur.

## Kısa Tekrar Notları

- Kriterler: tamlık, zaman, hafıza, optimallik. $b$ dallanma, $d$ en sığ çözüm derinliği, $m$ maksimum derinlik, $l$ limit.
- BFS: kuyruk, sona ekle; tam; $O(b^d)$ zaman ve hafıza; eşit maliyette optimal.
- DFS: yığın, başa ekle; tam değil; $O(b^m)$ zaman, $O(bm)$ hafıza; optimal değil.
- UCS: kökten maliyete göre sırala; pozitif maliyetlerde optimal; $O(b^d)$.
- DLS: limitli DFS; $l \ge d$ ise tam; optimal değil; $O(b^l)$ zaman, $O(bl)$ hafıza.
- IDS: limit 0, 1, 2, ... ile DLS; tam; $O(b^d)$ zaman, $O(bd)$ hafıza; eşit maliyette optimal; fazlalık yaklaşık %11 ($b=10$, $d=5$).
- Çift yönlü: iki yönden $O(b^{d/2})$.
- Tekrarlayan durumlar DFS'i sonsuz döngüye sokar; eklemeden önce yolda var mı kontrol et.
- my_search.m: UCS 110 km ile optimal yolu buldu; BFS 128, DFS 314.

## Detaylı Açıklamalar

Ders, arama algoritmalarını karşılaştırmak için kullanılan dört kriterin tekrarıyla başladı. Zaman ve hafıza karmaşıklığı sezgisel olarak anlaşılır: aramanın ne kadar sürdüğü ve bunun için ne kadar bellek gerektiği. Tamlık, problemin tanımlanan kurallar içinde bir çözümü varsa algoritmanın onu mutlaka bulmasıdır. Optimallik ise bulunan ilk çözümün en düşük maliyetli çözümlerden biri olmasıdır; bir problemin farklı maliyetli birden çok çözümü ve birden çok optimal çözümü olabilir.

Enlemesine arama algoritması derste şu sözde kodla verildi (slayt küçük resminden okunduğu kadarıyla, ekrandan, 00:20:00):

```text
kuyruk = [kök durum]
bulundu = FALSE
While (kuyruk <> boş) and (bulundu = FALSE)
    Kuyruktan ilk durumu (N) çek
    Eğer N hedef durumsa, bulundu = TRUE
    N'den gidilebilecek tüm durumları kuyruğun sonuna ekle
```

Başlangıcı A, hedefi 7 olan ağaçta kuyruk içeriği adım adım şöyle ilerledi (ekrandan, 00:25:00): A; BC; CDE; DEHG; EHG12; HG1234; G123456; 12345678; 2345678; ...; 78. 7 çekildiğinde hedef bulundu. Aynı algoritmada tek değişiklikle, yeni durumlar başa eklendiğinde kuyruk A; BC; DEC; 12EC; 2EC; EC; 34C; 4C; C; HG; 56G; 6G; G; 78 biçiminde ilerler ve derinlemesine arama elde edilir (ekrandan, 00:30:00). İki aramada da 14 düğüm çekildi, yani zaman bakımından fark yoktur; fark kuyruğun büyüklüğündedir. Enlemesine aramada bir seviyenin sonuna gelindiğinde bir alt seviyenin tamamı hafızadadır ($O(b^d)$), derinlemesine aramada ise gidilen derinlik çarpı $b$ kadar düğüm yeter ($O(bm)$).

Tamlık açısından enlemesine arama seviye seviye ilerlediği için çözüm nerede olursa olsun ona ulaşır. Derinlemesine arama ise önce hep en derine gider; durum uzayında tekrarlar varsa ve bunu yakalayan bir mekanizma yoksa sonsuza kadar aynı dalda döner ve diğer dalları hiç açamaz. Optimallik için hoca, 5 ve 3 düğümlerinin ikisinin de çözüm olduğu bir durumu ele aldı: maliyetler eşitse 3 (köke daha yakın) daha ucuzdur. Enlemesine arama 3'ü her zaman 5'ten önce açar, derinlemesine arama ise 5'e önce ulaşır. Bu yüzden enlemesine arama eşit maliyetlerde optimaldir, derinlemesine arama değildir.

Düşük maliyetli arama, kuyruktaki durumları kökten oraya gelmenin toplam maliyetine göre sıralayıp en ucuzu çeker. Hoca, maliyetler farklıysa uzun bir yolun daha ucuz olabileceğini şöyle örnekledi: 1'den 3'e doğrudan gitmek 100 dolar, 1'den 2'ye 10 ve 2'den 3'e 20 dolar ise iki adımlı yol 30 dolarla daha iyidir. Derste kullanılan grafta A'dan B'ye 1, B'den F'ye 10, A'dan D'ye 15, D'den F'ye 1 maliyetli geçişler vardır; A-C-E-F yolu üç geçiş içermesine rağmen toplam 10 ile en ucuzudur (ekrandan, 00:45:00). Algoritmanın seçimleri:

- Kuyruk B, C, D: $\min(1, 4, 15) = 1$, B çekilir.
- Kuyruk F, C, D: $\min(10+1, 4, 15) = 4$, C çekilir.
- Kuyruk F, E, D: $\min(11, 4+5, 15) = 9$, E çekilir.
- Kuyruk F, F, D: $\min(11, 9+1, 15) = 10$, ikinci F (A-C-E-F) çekilir ve arama biter.

<!-- BELİRSİZ: Slayttaki üst grafta A-C kenarı 5, C-E kenarı 4 yazıyor; altındaki arama ağaçlarında ise A-C 4, C-E 5 yazılmış. Her iki durumda da E'nin maliyeti 9 ve A-C-E-F yolu 10 olduğundan sonuç değişmez (python ile denendi). -->

Sınırlı derinlikte arama, derinlemesine aramaya bir derinlik sınırı koyar; sınırın altına hiç inilmediği için arama yanlara doğru yayılır. Çözüm sınır içindeyse mutlaka bulunur, ama derinlemesine arama mantığıyla ilerlediği için daha sığ bir çözümden önce derindekini bulabilir; bu yüzden optimal değildir. Artan derinlikli arama bu aramayı limit 0, 1, 2, ... değerleriyle tekrarlar. Kök $d+1$ kez, birinci seviye $d$ kez, en son seviye bir kez açılır:

$$N_{DLS} = b^0 + b^1 + \dots + b^d,\qquad N_{IDS} = (d+1)b^0 + d\,b^1 + (d-1)b^2 + \dots + 2b^{d-1} + 1\,b^d$$

$b=10$, $d=5$ için $N_{DLS} = 111.111$ ve $N_{IDS} = 123.456$ olur; fazlalık oranı $(123.456-111.111)/111.111 \approx \%11$'dir (ekrandan, 01:10:00). Bu küçük fazlalıkla tamlık, $O(bd)$ hafıza ve eşit maliyetlerde optimallik elde edilir.

Çift yönlü aramada başlangıçtan ve hedeften iki arama aynı anda yürütülür, her adımda durumlar karşılaştırılır ve bir eşleşme olduğunda iki yol birleştirilir. Her yön $d/2$ derinliğe indiği için maliyet $O(b^{d/2})$'dir. Hocanın verdiği sayılara göre, çözüm 6 derinlikteyse çift yönlü aramada üretilen düğüm sayısı 2.222, doğrudan enlemesine aramada 1.111.111'dir. <!-- BELİRSİZ: Bu sayılar slaytta görülemedi; $b=10$ alınırsa $2(1+10+100+1000)=2.222$ ve $1+10+\dots+10^6=1.111.111$ çıkar (python ile denendi). -->

Derste özetlenen karşılaştırma tablosu (ekrandan, 01:25:00):

| Kriter | Enlemesine | Düşük maliyetli | Derinlemesine | Sınırlı derinlikte | Artan derinlikli | Çift yönlü |
|---|---|---|---|---|---|---|
| Zaman | $b^d$ | $b^d$ | $b^m$ | $b^l$ | $b^d$ | $b^{d/2}$ |
| Hafıza | $b^d$ | $b^d$ | $bm$ | $bl$ | $bd$ | $b^{d/2}$ |
| Optimal | Evet | Evet | Hayır | Hayır | Evet | Evet |
| Tam | Evet | Evet | Hayır | $l \ge d$ ise evet | Evet | Evet |

Son olarak MATLAB kodu my_search.m ile rastgele üretilmiş bir haritada 12. şehirden 1. şehre yol arandı (ekrandan, 01:30:00). Bulunan yollar: BFS 12-4-2-5-1 (128), UCS 12-9-15-7-1 (110), DFS 12-11-9-15-18-17-13-10-7-14-8-5-1 (314). Adım sayısına göre liste boyutu grafiğinde BFS ve UCS'in listesi hızla büyürken DFS'inki düşük kalır. Bir sonraki derste görülecek A* aynı 110'luk yolu 6 adımda, best-first 5 adımda bulmuştur. DFS'in yolundaki mantıksız hamleler hedeften uzaklaşan hamlelerdir; kör algoritmalar hedefe yakınlık bilgisini kullanmaz, sezgisel algoritmalar ise kullanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
