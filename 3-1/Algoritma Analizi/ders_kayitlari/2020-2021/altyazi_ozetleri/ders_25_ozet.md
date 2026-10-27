# Ders 25 Çalışma Özeti

## Genel Konular

- Dersin tarihi 30 Aralık 2020 Çarşamba. Ders Zoom üzerinden yapıldı. Dönemin son konu anlatımı.
  - İlk 18 dakika duyurular ve dersle ilgili anketle geçer. Konu anlatımı yaklaşık 00:22'de başlar.
  - 00:52 ile 01:03 arasında 10 dakikalık ara var.
  - Kaydın son yarım saati (01:37'den sonra) önümüzdeki haftanın planı, dönem projesi ve anket sonuçları üzerine konuşmalardır.
- Duyurular
  - 4. ödevin son teslim tarihi 3 Ocak 2021 Pazar 23:59. Sistemde tarih yanlışlıkla 12 Aralık 2021 görünüyor.
  - Vize sonuçları en geç önümüzdeki derse kadar açıklanacak.
- Dal ve sınır ile 0-1 sırt çantası problemi (knapsack)
- Gezgin satıcı problemi (Traveling Salesman Problem, TSP) ve Hamilton devresi (Hamiltonian circuit)
- Hesaplama karmaşıklığı sınıfları
  - Polinom zamanda çözülebilen (tractable) ve çözülemeyen (intractable) problemler
  - Karar problemleri (decision problems), karar verilebilir (decidable) ve karar verilemez (undecidable) problemler
  - Durma problemi (halting problem)
  - Deterministik olmayan algoritma, P, NP, polinom indirgeme, NP-tam (NP-complete) ve NP-zor (NP-hard)

## Hocanın Özellikle Vurguladığı Kısımlar

- Sırt çantası probleminde dal ve sınıra başlamadan önce eşyalar birim ağırlık başına değere ($v_i / w_i$) göre büyükten küçüğe sıralanmalıdır.
- En iyi öncelikli dal ve sınırda her adımda o an sınırı en iyi olan düğümden devam edilir.
  - Bir yaprakta bulunan değer, başka bir düğümün sınırından iyiyse o düğüm elenir.
- NP konusunda en önemli soru doğrulama aşamasıdır (verification stage): Verilen bir aday çözüm polinom zamanda doğrulanabiliyor mu?
- Problemleri karar problemi olarak ifade etmek konuyu anlamayı kolaylaştırır.
  - Örnek: "Bu çizge en az kaç renkle boyanır?" bir optimizasyon sorusu. "Bu çizge 3 renkle boyanabilir mi?" ise evet/hayır cevaplı bir karar sorusu.
- Büyük şirketlerin (Google, Apple, Microsoft vb.) işe alımlarında veri yapıları ve algoritma analizi mülakatları belirleyicidir. Algoritma yaklaşımlarını farklı problemler üzerinde çalışın.
- Macar algoritması (Hungarian algorithm) gibi bir önceki haftanın atama problemini polinom zamanda çözen algoritmalara genel kültür olarak bakın.

## Kısa Tekrar Notları

- **0-1 sırt çantası, dal ve sınır:**
  - Düğümde tutulanlar: o ana kadarki ağırlık $w$, değer $v$ ve üst sınır $ub$.
  - $ub = v + (W - w) \cdot (v_{i+1} / w_{i+1})$. Burada $i+1$, sıradaki eşyadır.
  - Ağırlık kapasiteyi aşarsa düğüm uygun değildir (not feasible).
- **Tractable:** Polinom zamanda çözülebilir. **Intractable:** Polinom zamanda çözülemez.
- **Deterministik olmayan algoritma:** İki aşama:
  - Tahmin aşaması (guessing): Rastgele bir aday çözüm $S$ üretilir.
  - Doğrulama aşaması (verification): $S$'nin $I$ girdisi için çözüm olup olmadığı deterministik olarak kontrol edilir.
- **NP:** Deterministik olmayan polinom algoritmayla çözülebilen karar problemleri. Yani aday çözümü polinom zamanda doğrulanabilen problemler. $P \subseteq NP$.
- **Polinom indirgeme ($D_1 \le_p D_2$):** $D_1$'in her örneğini $D_2$'nin bir örneğine çeviren, polinom zamanda hesaplanan bir $t$ fonksiyonu. Evet örnekleri evet örneklerine, hayır örnekleri hayır örneklerine gider.
- **NP-tam:** Problem NP'dedir ve NP'deki her problem ona polinom zamanda indirgenebilir.
- **NP-zor:** NP'deki her problem ona polinom zamanda indirgenebilir. NP'de olması gerekmez.
- **Durma problemi:** Karar verilemez. Alan Turing.

## Detaylı Açıklamalar

### Duyurular ve anket

- Hoca derse katılanlara kısa bir anket doldurttu. Anketten çıkan iki konu üzerinde durdu:
  - Etkileşimli ders anlatımı bazı öğrencileri mutsuz etmiş. Hoca amacının kimseyi zor durumda bırakmak değil, katılımı artırmak olduğunu söyledi.
  - Dersi açıp takip etmemek onu en çok üzen konu.
- 4. ödevin son teslim tarihi 3 Ocak 2021 Pazar 23:59. Sistemde yanlış tarih girildiği için 12 Aralık 2021 görünüyor; geçerli tarih 3 Ocak.
- Vize sonuçları en geç bir sonraki derse kadar açıklanacak.

### Dal ve sınır ile 0-1 sırt çantası

- Daha önce dinamik programlamayla çözülen problem bu kez dal ve sınırla çözüldü.
- Örnek (kapasite $W = 10$):

| Eşya | Ağırlık $w_i$ | Değer $v_i$ | $v_i / w_i$ |
| :---: | :---: | :---: | :---: |
| 1 | 4 | 40 | 10 |
| 2 | 7 | 42 | 6 |
| 3 | 5 | 25 | 5 |
| 4 | 3 | 12 | 4 |

- Eşyalar zaten $v_i / w_i$ sırasına göre verilmiş.
- Durum uzayı ağacı (kareden doğrulandı):
  - **Kök (0):** $w=0$, $v=0$, $ub = 0 + 10 \cdot 10 = 100$.
  - **Düğüm 1 (1 alındı):** $w=4$, $v=40$, $ub = 40 + 6 \cdot 6 = 76$.
  - **Düğüm 2 (1 alınmadı):** $w=0$, $v=0$, $ub = 0 + 10 \cdot 6 = 60$.
  - **Düğüm 3 (1 ve 2 alındı):** $w = 11 > 10$. Uygun değil.
  - **Düğüm 4 (1 alındı, 2 alınmadı):** $w=4$, $v=40$, $ub = 40 + 6 \cdot 5 = 70$.
  - **Düğüm 5 (3 alındı):** $w=9$, $v=65$, $ub = 65 + 1 \cdot 4 = 69$.
  - **Düğüm 6 (3 alınmadı):** $w=4$, $v=40$, $ub = 40 + 6 \cdot 4 = 64$.
  - **Düğüm 7 (4 alındı):** $w = 12 > 10$. Uygun değil.
  - **Düğüm 8 (4 alınmadı):** $w=9$, $v=65$. Bu bir yapraktır, değeri 65.
- **Sonuç:** Eşya 1 ve 3 alınır, toplam değer 65.
  - Düğüm 2'nin sınırı (60) ve düğüm 6'nın sınırı (64), 65'ten küçük olduğu için elenir.
  - Bir öğrencinin dediği gibi: Düğüm 5'te $v = 65$ görülünce, sınırı 60 olan düğüm 2'nin elendiği düğüm 7 ve 8'e bakmadan anlaşılabilir.
- Python ile bütün alt kümeler denendi: En büyük değer 65, eşyalar $\{1, 3\}$.
- Kaba kuvvetle $2^4 - 1 = 15$ alt küme denenir. Burada en fazla 9 düğüm oluşturuldu. Eşya sayısı arttıkça fark büyür ($2^5 - 1 = 31$, $2^6 - 1 = 63$, ...).

### Gezgin satıcı ve Hamilton devresi

- **Hamilton devresi:** Bir çizgede bir noktadan başlayıp her noktaya bir kez uğrayarak başlangıca dönen bir devre var mı?
- **Gezgin satıcı:** Bu devrelerden en kısa olanı hangisi?
- TSP de dal ve sınırla çözülebilir. Alt sınır için her şehrin en yakın iki komşusuna olan uzaklıkları toplanır ve toplam ikiye bölünür.
- Navigasyon gibi binlerce noktalı problemlerde bütün olasılıkları denemek mümkün değildir.

### Polinom ve polinom olmayan zaman

- Polinom zamanlı karmaşıklıklar: $O(n)$, $O(\log n)$, $O(n \log n)$, $O(n^2)$, $O(n^3)$. Pratikte $n^4$'ün üstüne ve çok büyük katsayılara pek rastlanmaz.
- Polinom olmayanlar: $2^n$, $a^n$, $n!$, $n^n$. $n$ büyüyünce çok güçlü bir bilgisayar bile yıllarca çalışması gerekebilir.
- **Tanım 1:** Polinom zamanda çözülebilen problemler tractable, çözülemeyenler intractable olarak adlandırılır.
- **Tanım 2 (P):** Deterministik algoritmalarla polinom zamanda çözülebilen karar problemleri sınıfı.

### Karar verilemez problemler ve durma problemi

- Bir karar problemi ya karar verilebilir (decidable) ya da karar verilemez (undecidable).
- **Durma problemi:** Bir $P$ programı ve $I$ girdisi veriliyor. $P$, $I$ ile çalıştırıldığında durur mu, yoksa sonsuza kadar mı çalışır?
- Hoca ispatı tahtada yazdı. Altyazıda ispatın adımları bozuk geçiyor. Standart ispat şöyledir:
  - Bu problemi çözen bir $A$ algoritması olsun: $A(P, I) = 1$, eğer $P$ programı $I$ girdisiyle durursa; $A(P, I) = 0$, durmazsa.
  - Yeni bir $Q$ programı tanımlanır. $Q$, girdi olarak bir $P$ programı alır:
    - $A(P, P) = 0$ ise $Q$ durur.
    - $A(P, P) = 1$ ise $Q$ sonsuz döngüye girer.
  - $Q$, kendisi girdi olarak verilerek çalıştırılır:
    - $Q$ durursa, tanımına göre $A(Q, Q) = 0$ olmalıdır. Bu da "$Q$, $Q$ girdisiyle durmaz" demektir.
    - $Q$ durmazsa, $A(Q, Q) = 1$ olmalıdır. Bu da "$Q$, $Q$ girdisiyle durur" demektir.
  - İki durumda da çelişki çıkar. Demek ki böyle bir $A$ algoritması yoktur. Durma problemi karar verilemezdir (Alan Turing, 1936).

### Polinom zamanda çözülemeyen ama karar verilebilir problemler

- **Hamilton devresi:** Verilen çizgede Hamilton devresi var mı?
- **Gezgin satıcı (karar biçimi):** Uzunluğu verilen bir sayıyı aşmayan bir tur var mı?
- **Sırt çantası (karar biçimi)**
- **Bölüntü problemi (partition):** Pozitif tam sayılardan oluşan bir küme, toplamları eşit iki ayrık alt kümeye bölünebilir mi?
- **Çizge boyama:** Çizge $m$ renkle boyanabilir mi?
- **Tam sayılı doğrusal programlama (integer linear programming)**
- Bu problemler için polinom zamanlı algoritma bilinmiyor. Küçük girdilerde dal ve sınır veya dinamik programlamayla çözülebilirler.

### Deterministik olmayan algoritmalar ve NP

- **Tanım 3:** Deterministik olmayan bir algoritma, bir karar probleminin $I$ örneğini alır ve iki aşamada çalışır:
  - **Tahmin aşaması (nondeterministic / guessing):** Rastgele bir $S$ dizgisi üretilir. $S$, aday bir çözüm olarak düşünülür. Doğru da olabilir, tamamen anlamsız da.
  - **Doğrulama aşaması (deterministic / verification):** Deterministik bir algoritma $I$ ve $S$'yi alır. $S$, $I$'nın çözümüyse "evet" der. Değilse "hayır" der ya da hiç durmayabilir.
- Doğrulama aşaması polinom zamanlıysa algoritmaya deterministik olmayan polinom (nondeterministic polynomial) algoritma denir.
- **Tanım 4 (NP):** Deterministik olmayan polinom algoritmalarla çözülebilen karar problemleri sınıfı.
- $P \subseteq NP$. $P = NP$ olup olmadığı ise henüz kanıtlanmamıştır.
- Bölüntü problemi örneği (bir öğrenciyle tartışıldı):
  - Bütün bölünmeleri denemek $2^n$ işlem ister.
  - Ama verilen bir bölünmenin uygun olup olmadığını kontrol etmek kolaydır: İki kümenin toplamı alınır ve karşılaştırılır. Bu polinom zamanlıdır. Bu yüzden problem NP'dedir.
- Bir öğrencinin sorusu üzerine: Matris çarpımı $O(n^3)$'tür, dizinin en büyüğünü bulmak $O(n)$'dir. İkisi de P'dedir.

### Polinom indirgeme, NP-tam ve NP-zor

- **Tanım 5 (polinom indirgeme):** $D_1$ karar problemi $D_2$'ye polinom zamanda indirgenebilir. Bunun için $D_1$'in örneklerini $D_2$'nin örneklerine çeviren bir $t$ fonksiyonu bulunmalı ve şu iki şart sağlanmalıdır:
  - $t$, $D_1$'in bütün evet örneklerini $D_2$'nin evet örneklerine, bütün hayır örneklerini $D_2$'nin hayır örneklerine götürür.
  - $t$, polinom zamanlı bir algoritmayla hesaplanabilir.
- **Tanım 6 (NP-tam):** Bir $D$ karar problemi şu iki şartı sağlıyorsa NP-tamdır:
  - $D$, NP sınıfındadır.
  - NP'deki her problem $D$'ye polinom zamanda indirgenebilir.
- **NP-zor:** NP'deki her problem ona indirgenebilir, ama problemin kendisinin NP'de olması gerekmez. Her NP-tam problem NP-zordur. Tersi her zaman doğru değildir.
- Yaygın kullanılan şekil ($P \neq NP$ varsayımıyla): P, NP'nin içindedir. NP-tam problemler, NP ile NP-zorun kesişimidir.

### Önümüzdeki hafta ve dönem projesi

- Önümüzdeki hafta (6 Ocak 2021) ders saatinde 4. ödevin çözümü olacak. Ardından rastgele seçilen öğrencilere ödevleriyle ilgili sorular sorulacak.
- Dönem projesi hafta sonuna kadar verilecek. Teslim süresi en az iki hafta olacak, toplamda üç hafta sonu bulunacak. Proje, düzenli çalışılırsa 2-3 günde yapılabilecek büyüklükte olacak.
- Bir öğrenci projenin ağırlığının %20 yerine %15, ödevlerin %25 olmasını önerdi. Hoca öneriyi makul buldu ve diğer grubun hocasıyla görüşeceğini söyledi. (Sonraki derste karar açıklandı.)
- Final için hoca "her zamanki finaller gibi, muhtemelen iki bölümden oluşur" dedi. Süre konusunda daha dikkatli olunacak.
- Sınavın ilk 10 dakikasında anlaşılmayan sorular e-postayla sorulabilecek; gerekirse herkese toplu cevap gönderilecek.

### Ders sonrası notlar

- **NP-zor tanımı:** Hoca NP-zoru "yeterince güçlü bir cihaz ve zaman olsa da çözülemeyen" ve "doğrulaması da polinom zamanda yapılamayan" problemler diye anlattı. Bu tanım yanlıştır. Doğrusu: NP'deki her problem kendisine polinom zamanda indirgenebilen problemler NP-zordur. NP-zor bir problem karar verilebilir de olabilir. Örneğin TSP'nin optimizasyon biçimi NP-zordur ve sonlu sürede çözülebilir. Durma problemi hem karar verilemez hem de NP-zordur, ama NP-zor olmak karar verilemez olmak demek değildir.
- **İndirgeme yönü:** Hoca "TSP'yi Hamilton devresi problemine indirgeyebiliyoruz, o yüzden NP-tamdır" dedi. Yön ters. Hamilton devresi problemi TSP'nin karar biçimine indirgenir: Kenarlara 1, kenar olmayan çiftlere 2 ağırlık verilir. Uzunluğu $n$ olan bir tur ancak ve ancak Hamilton devresi varsa vardır. Bilinen bir NP-tam problem ($HC$) TSP'ye indirgendiği ve TSP de NP'de olduğu için TSP'nin karar biçimi NP-tamdır.
- **"TSP, Hamilton devresinin bir alt problemidir":** Daha doğrusu TSP, Hamilton devresinin bir genellemesidir. Hamilton devresi var mı sorusuna, en kısa Hamilton devresi sorusu eklenir.
- **TSP sınırı:** Hoca en yakın iki komşu yönteminin verdiği değere önce "alt sınır", sonra "üst sınır" dedi. Doğrusu alt sınırdır (lower bound), çünkü TSP bir minimizasyon problemidir.
- **"Dal ve sınır maksimizasyon problemleri için":** Dal ve sınır genel olarak optimizasyon problemleri içindir. Bir önceki dersteki atama problemi bir minimizasyon problemiydi, bu dersteki sırt çantası bir maksimizasyon problemi.
- **Sırt çantası ve bölüntü problemleri:** İkisi de NP-tamdır. Ama ikisinin de $O(nW)$ veya $O(n \cdot \text{toplam})$ süreli dinamik programlama çözümü vardır. Bu süre girdinin sayısal değerine bağlıdır (sözde polinom, pseudo-polynomial), girdinin bit uzunluğuna göre polinom değildir.
- **"NP problemleri polinom zamanda çözülemez" ifadesi:** Bu kanıtlanmış bir sonuç değil. Kanıtlanmış olan, bu problemler için bugüne kadar polinom zamanlı algoritma bulunamamış olmasıdır.
- **Macar algoritması:** Atama problemini $O(n^3)$ sürede çözer.
- **Altyazı hataları:** "Napsack/nebsek" knapsack, "maintaining circuit" Hamiltonian circuit, "interactive" intractable, "Bradford/Debford Search" breadth-first / depth-first search demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
