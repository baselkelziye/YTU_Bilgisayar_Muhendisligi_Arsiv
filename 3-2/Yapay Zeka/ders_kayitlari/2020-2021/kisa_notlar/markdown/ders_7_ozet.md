# Ders 7 Çalışma Özeti

## Genel Konular

- Oyunların sınıflandırılması
  - Konu, bilgisayar oyunlarının grafik ya da oyun dinamiği açısından yapılması değil, bilgisayarın bir oyunu nasıl oynadığı, yani arkada çalışan algoritmalardır.
  - İki ölçüt vardır: oyunda şans olup olmaması (deterministik / şanslı) ve oyuncuların oyundaki bütün bilgiye sahip olup olmaması (perfect / imperfect information).
  - Slayttaki tablo (ekrandan, 00:10:00): perfect information + deterministik: satranç, dama, go, othello; perfect information + şans: tavla, monopoly; imperfect information + şans: bridge, poker, scrabble, nuclear war.
  - Imperfect information, karşı tarafın elindekini bilmemektir (okey, poker, 51 gibi kâğıt ve taş oyunları). Bu ayrım, etmen derslerindeki tam gözlenebilir / kısmen gözlenebilir ortam ayrımına karşılık gelir.
- Oyun ağacı (game tree)
  - İki oyunculu oyunda kök bizim (MAX) hamle sıramızdır; bir seviye bizim hamlelerimiz, bir alt seviye rakibin (MIN) hamleleri olarak dallanır.
  - XOX (tic-tac-toe) örneğinde ilk seviyede 9, sonra 8, sonra 7 hamle vardır. Ağacın en büyük derinliği 9'dur, ama oyun daha önce de bitebilir.
  - Oyunun bittiği düğümlere terminal düğüm denir. Terminal düğümler aynı seviyede olmak zorunda değildir.
  - Terminal düğümün değeri utility (fayda) değeridir: kazanırsa +1, kaybederse -1, beraberlikte 0 (ekrandan, 00:15:00).
- Minimax algoritması
  - Rastgele olmayan oyunlar için idealdir. Yaklaşım: en yüksek minimax değerini sağlayan hamleyi yapmak.
  - Terminal düğümün minimax değeri utility değeridir; MAX düğümünde çocukların en büyüğü, MIN düğümünde çocukların en küçüğü alınır.
  - Derinlemesine arama gibi çalışır. Kendisi için her zaman en iyisini yapan bir rakibe karşı optimaldir.
- Satrançta tam ağacın imkânsızlığı
  - Ortalama dallanma 32, ortalama oyun uzunluğu 40 hamle: $32^{40} = 2^{200} \approx 10^{60}$ düğüm (ekrandan, 00:25:00).
  - Saniyede 3 milyar durum işlense, yılda yaklaşık $10^{17}$ durum işlenir; bütün ağaç $10^{43}$ yıl sürer. Evrenin yaşı yaklaşık $10^{10}$ yıldır.
- Sınırlı derinlikte arama ve değerlendirme fonksiyonu (cutoff search)
  - Ağacın tamamı yerine belli bir derinliğe kadar ağaç üretilir. Bu derinlikte oyun çoğunlukla bitmediği için utility yerine bir değerlendirme fonksiyonu (Eval) kullanılır.
  - Değerlendirme fonksiyonu, tahtanın bizim açımızdan iyiliğini tahmin eden sezgisel bir değerdir. Gerçek sonucu bilemez.
  - Algoritma minimax ile aynıdır: "Terminal?" yerine "Cutoff?", "Utility" yerine "Eval" kullanılır (ekrandan, 01:05:00).
- Satranç için değerlendirme fonksiyonu
  - Taş değerleri: piyon 1, at ve fil 3, kale 5, vezir 9. Şahın değeri yoktur, çünkü iki tarafta da her zaman vardır.
  - Örnek tahta: siyah 5 piyon, 1 fil, 2 kale ile $5+3+10=18$; beyaz 5 piyon, 1 kale ile $5+5=10$. Siyah için $18-10=8$, beyaz için $10-18=-8$ (ekrandan, slayt küçük resmi, 00:40:00).
  - Gerçek programlarda ağırlıklı toplam kullanılır: $Eval(s) = w_1 f_1(s) + w_2 f_2(s) + \dots + w_n f_n(s)$. Örneğin $w_1 = 9$ ve $f_1(s)$ = beyaz vezir sayısı - siyah vezir sayısı.
  - Asıl iş $f$'leri ve $w$'leri belirlemektir: etrafı boş piyonlar kötüdür, şahın korumaları var mı, hareket kabiliyeti nasıl, tahtanın ortasının kontrolü kimde, oyun süresince $w$'ler değişir mi (ekrandan, 00:35:00).
- XOX için değerlendirme fonksiyonu
  - $e(n) = M(n) - O(n)$: $M(n)$ benim hâlâ kazanabileceğim çizgi sayısı, $O(n)$ rakibin hâlâ kazanabileceği çizgi sayısı.
  - Derste üç tahta için $6-5=1$, $4-6=-2$, $5-4=1$ hesaplandı.
  - İki derinlikli aramayla ilk hamle: köşeye X konursa MIN değeri $-1$, kenara konursa $-2$, merkeze konursa $1$ olur. En büyük değer 1 olduğu için X merkeze konur (ekrandan, 00:40:00).
  - Her hamleden sonra aynı iki derinlikli ağaç yeniden kurulur, yapraklar değerlendirilir, minimax ile hamle seçilir.
- Ufuk etkisi (horizon effect)
  - Seçilen derinlik kararı değiştirebilir. Örnek (ekrandan, 01:00:00): c2'deki beyaz kale a2'deki piyonu alır mı?
  - 1 derinlik: piyon kazancı olduğu için alır. 2 derinlik: siyah kale beyaz kaleyi alır, bir piyona bir kale değmez, almaz. 3 derinlik: ikinci beyaz kale geri alır, piyon + kale bir kaleye değer, alır. 4 derinlik: ikinci siyah kale de alır, piyon + kale iki kaleye değmez, almaz.
  - İdeal olan, kararın artık değişmediği kadar derine bakmaktır, ama donanım ve zaman bunu her zaman izin vermez.
- Sınırlı derinlik satrançta yeterli mi?
  - Hamle süresi 100 saniye ve hız $10^4$ düğüm/saniye ise hamle başına $10^6$ düğüm incelenir. $b^m = 10^6$ ve $b = 35$ ise $m \approx 4$ olur.
  - 4 kat ileri bakış amatör oyuncu, 8 kat master seviyesindeki insan, 12 kat Deep Blue ve Kasparov düzeyidir (ekrandan, 01:05:00).
- Alfa-beta budaması
  - Bazı düğümlerin değeri seçilecek hamleyi değiştirmez; bunlar hiç değerlendirilmeden budanır.
  - $\alpha$: bir düğümün alabileceği en küçük değer (alt sınır); $\beta$: alabileceği en büyük değer (üst sınır). Başlangıçta aralık $[-\infty, +\infty]$'dur.
  - Derinlemesine ilerlenir, yapraklar geldikçe sınırlar güncellenir. Bir MIN düğümünün üst sınırı, üstteki MAX düğümünün garantilediği alt sınırın altına inince o MIN düğümünün kalan çocukları budanır.
  - Budama sonucu değiştirmez; aynı kararı daha az maliyetle verir. Budama üst seviyelerde de olabilir; o zaman altındaki bütün alt ağaç birden atılır.
  - Karmaşıklık $O(b^{m/2})$'ye kadar iner. Aynı donanımla arama derinliği iki katına çıkar: satrançta 4 kattan 8 kata (master seviyesi).
- Satranç programlarında seviyeler
  - Programın acemi ya da uzman oynaması, ne kadar derine baktığına bağlıdır. Seviye arttıkça programın cevap süresi de uzar.
- Rastgele olmayan oyun uygulamaları ve tarihçe
  - Bilgisayarlar damada 1994'te, satrançta 1997'de üstünlüğü aldı; Othello'da daha erken. Go'da insanlar üstünlüğü ancak 2016'da kaybetti.
  - Go'nun zorluğu: 19x19 tahta, $b \approx 250$, $d \approx 150$. Mart 2016'da AlphaGo dünya şampiyonunu 4-1 yendi (ekrandan, 01:20:00).
  - 11 Mayıs 1997: Kasparov, 6 oyunluk maçta Deep Blue'ya 3.5-2.5 yenildi (2 oyun Deep Blue, 1 oyun Kasparov, 3 beraberlik) (ekrandan, 01:25:00).
  - Metotların tarihi: Shannon ve Turing minimax arama (1950), Kotok/McCarthy alfa-beta budama (1966), MacHack dönüşüm tabloları (1967), Chess 3.0+ iteratif derinleştirme (1975), Belle özel donanım (1978), Cray Blitz paralel arama (1983), Hitech paralel değerlendirme (1985), Deep Blue bunların hepsi (1997).
  - Son yıllardaki başarı algoritmadan çok donanımdaki ilerlemeden gelir. Deep Blue'da satranç değerlendirme fonksiyonlarını hızlı hesaplayan özel satranç çipleri vardı.
- Şans içeren oyunlar: Expectiminimax
  - Minimax'tan tek farkı, MAX ve MIN seviyelerinin arasına şans (chance) düğümlerinin eklenmesidir.
  - Tavlada iki zarın 21 farklı sonucu vardır: 6'sı çift (olasılığı $1/36$), 15'i farklı (olasılığı $1/18$).
  - Şans düğümünün değeri, çocukların değerlerinin olasılıklarla ağırlıklı toplamıdır: $\sum_s P(s)\cdot \text{değer}(s)$.
  - Örnek: olasılıklar 0.9 ve 0.1 iken sol şans düğümü $0.9 \cdot 2 + 0.1 \cdot 3 = 2.1$, sağ şans düğümü $0.9 \cdot 1 + 0.1 \cdot 4 = 1.3$; MAX 2.1'i, yani sol hamleyi seçer.
  - Karmaşıklık $b^m n^m$'e çıkar ($n$: şans dallanması). Tavlada $b \approx 20$, $n = 21$; ancak 3 seviye pratikte mümkündür. TD-Gammon 2 derinlikli arama ve çok iyi bir değerlendirme fonksiyonuyla dünya şampiyonu seviyesine ulaştı.
- Tahmin ve öğrenme
  - Bilgisayar rakibin hareket kayıtlarını tutup bir sonraki hareketini tahmin edebilir; böylece bütün olasılıklar yerine olası olanlar hesaba katılır ve daha derine inilebilir.
  - Virtua Fighter 4 örneği (ekrandan, 01:35:00): "Low Kick, Low Punch" sonrasında geçmişte 10 kez Uppercut (%50), 7 kez Low Punch (%35), 3 kez Low Kick (%15) gelmiş.
- Değerlendirme fonksiyonunu öğrenmek
  - Deep Blue, $f(p) = w_1 f_1(p) + \dots + w_n f_n(p)$ içindeki ağırlıkları öğrendi. $f$'ler verilmişti.
  - Grandmaster seviyesindeki oyuncuların binden fazla oyununda "şu durumda şunu yaptı" bilgisinden oluşan bir veritabanı kullanıldı. Ağırlıklar, her durumda ustanın yaptığı hamlenin seçileceği biçimde ayarlandı.
- Kendi kendine oynamak ve Monte Carlo Ağaç Araması (MCTS)
  - Bilgisayara yalnız oyunun kuralları ve bitişi kontrol eden mekanizma verilir; uzman bilgisi verilmez. Program milyonlarca maçı kendi kendine oynayarak öğrenir (self-play).
  - MCTS 2006'da Go ile popülerleşti, büyük arama uzayları için tasarlandı. Dört adım tekrarlanır (ekrandan, 02:00:00): Selection, Expansion, Simulation (oyun bitene kadar rastgele hamleler), Back propagation (sonucu köke kadar yay).
  - Her düğüm kaç oyun oynandığını ve kaçının kazanıldığını tutar. Seçim bu istatistiklere göre yapılır.
  - Seçimde ikilem vardır: az oynanmış dallar mı, yüksek oranda kazanılmış dallar mı? Başta çeşitliliğe, ilerledikçe en başarılılara ağırlık vermek mantıklıdır.
  - Oyun tahtası bir CNN'e verilip tahtanın değeri tahmin ettirilebilir.
  - Kolayca paralelleştirilebilir; özellikle simülasyonlar birbirinden bağımsızdır. Bilgisayarda taklit edilebilen dünyalardaki arama problemlerine (ör. eklemli bir robot kolunu istenen konuma getirmek) uygulanabilir.
- Deep Blue tartışması ve makinelerin sınırları
  - Bir eleştiriye göre Deep Blue yalnızca tasarımcıların fikirlerini büyük hesap gücüyle uygulayan özel bir hesap makinesidir. Drew McDermott'ın cevabı: Deep Blue'nun satrançtan anlamadığını söylemek, bir uçağın kanat çırpmadığı için uçmadığını söylemeye benzer (ekrandan, 02:10:00).
  - Deep Thought örnekleri: rakibin geçemediği bir piyon duvarı varken Deep Thought kaleyi alıp duvarı açar ve kaybeder. Çözüm olarak yeni bir $f$ eklenir, ama her yeni durum için yeni bir $f$ gerekir: "Nereye kadar?" (ekrandan, 02:15:00).
  - Bu tahtalar gerçek oyunda nadiren çıkar; satranç problemleri türündendir. Makineler görmedikleri durumlara (satranç problemleri, 16x16 tahta) insan kadar kolay uyum sağlayamaz.

## Hocanın Özellikle Vurguladığı Kısımlar

- Rakip rastgele oynamaz
  - Minimax, karşı tarafın da kazanmak için oynadığını varsayar. Altta 14 görüp o hamleyi seçmek yanlıştır, çünkü rakip bizi en kötü yaprağa götürür.
- Değerlendirme fonksiyonu bir tahmindir
  - Utility oyun sonunu bilir; Eval yalnızca tahtanın bizim açımızdan iyiliğini sezgisel olarak tahmin eder.
- Derinlik kararı değiştirebilir
  - Ufuk etkisi örneğinde karar "alır, almaz, alır, almaz" diye değişir. Mümkünse kararın sabitlendiği bir derinlik seçilmelidir.
- Alfa-beta aynı kararı daha ucuza verir
  - Budama sonucu değiştirmez. Kazanılan zaman daha derine inmek için kullanılır: 4 kattan 8 kata.
- Seviyelerin sırrı derinliktir
  - Satranç programlarındaki zorluk seviyeleri büyük ölçüde arama derinliğidir.
- Şans oyunlarında "dünya şampiyonu" farklı bir anlam taşır
  - Şans varsa zayıf oyuncunun bile her zaman bir kazanma şansı vardır; deterministik oyunlarda uzmanlık arttıkça bu şans sıfıra yaklaşır.
- MCTS'nin gücü sayıdan gelir
  - Tek bir rastgele oyun güvenilir değildir, ama milyonlarca rastgele oyunun istatistiği anlam taşır.

## Kısa Tekrar Notları

- Oyun türleri: deterministik / şanslı ve perfect / imperfect information.
- Terminal düğüm: oyunun bittiği düğüm. Utility: +1, 0, -1.
- Minimax: MAX'ta en büyük, MIN'de en küçük. Örnek: $\min(3,12,8)=3$, $\min(2,4,6)=2$, $\min(14,5,2)=2$; kök $\max(3,2,2)=3$, hamle A1.
- Satranç: $32^{40} \approx 10^{60}$ düğüm; tam minimax imkânsız.
- Cutoff search: Terminal yerine Cutoff, Utility yerine Eval.
- Eval doğrusal toplam: $\sum w_i f_i(s)$.
- XOX: $e(n) = M(n) - O(n)$; ilk hamle merkez.
- Ufuk etkisi: derinliğe göre karar değişebilir.
- $b^m = 10^6$, $b = 35 \Rightarrow m \approx 4$ (amatör).
- Alfa-beta: $\alpha$ alt sınır, $\beta$ üst sınır; karmaşıklık $O(b^{m/2})$, derinlik iki katı.
- Expectiminimax: şans düğümü = olasılık ağırlıklı ortalama; tavlada 21 zar sonucu.
- Tahmin ve öğrenme: rakibin olası hamlelerine odaklanarak dallanmayı azaltmak.
- Deep Blue: $w$'leri usta oyunlarından öğrendi.
- MCTS: Selection, Expansion, Simulation, Back propagation; kazanma istatistikleri; kolay paralelleşir.
- Günümüzde pekiştirmeli öğrenme ve MCTS popülerdir.

## Detaylı Açıklamalar

- **Minimax örneği.** Kökte üç hamle (A1, A2, A3), her birinin altında rakibin üç cevabı vardır. Yaprak değerleri sırasıyla 3, 12, 8 / 2, 4, 6 / 14, 5, 2'dir (ekrandan, 00:20:00). Bir öğrenci en büyük yaprak 14 olduğu için A3'ü seçmeyi önerdi; ama A3'ten sonra rakip A33'ü seçer ve biz 2 alırız. Bu yüzden her MIN düğümüne çocuklarının en küçüğü yazılır (3, 2, 2), kökte bunların en büyüğü (3) seçilir. A1 seçildiğinde rakip ne yaparsa yapsın en az 3 kazanılır.
- **Sınırlı derinlikte XOX.** Derinlik 2 seçilir: biz bir hamle yaparız, rakip bir hamle yapar. Simetrik durumlar elenince boş tahtadan üç farklı hamle kalır: köşe, kenar, merkez. Köşenin altındaki tahtalar $6-5=1$, $5-5=0$, $6-5=1$, $5-5=0$, $4-5=-1$ değerlerini alır ve MIN $-1$'dir. Kenarın altındakiler $5-6=-1$, $5-5=0$, $5-6=-1$, $6-6=0$, $4-6=-2$, MIN $-2$'dir. Merkezin altındakiler $5-4=1$, $6-4=2$, MIN $1$'dir. Kök en büyüğü (1) seçer; X merkeze konur (ekrandan, 00:40:00). Rakip üst kenara O koyduktan sonra aynı işlem tekrarlanır. Dört farklı X hamlesinin MIN değerleri 1, 0, 1, 0 çıkar; 1 değerli hamlelerden biri rastgele seçilir. Değerler python ile kontrol edildi.
- **Alfa-beta adım adım (00:20:00'daki ağaç).** İlk MIN düğümünde 3 gelince $\beta = 3$ olur; 12 ve 8 bunu değiştirmez ve düğüm 3 olur. Kök artık en az 3'tür ($\alpha = 3$). İkinci MIN düğümünde ilk yaprak 2 gelince bu düğüm en fazla 2 olabilir. 2 < 3 olduğu için kalan iki yaprak budanır. Üçüncü MIN düğümünde 14, 5, 2 sırayla gelir ve $\beta$ 14, 5, 2 olur; düğüm 2'dir. Kök 3'tür. 9 yapraktan 7'si değerlendirilmiş, karar değişmemiştir.
- **Alfa-beta alıştırması (slayt 28).** Daha derin bir ağaçta budama üst seviyede de olabilir. Örneğin $\alpha = 5$ garantilendikten sonra bir MIN düğümünün ilk çocuğu 4 gelirse, o MIN düğümünün kalan bütün alt ağacı atılır. Slayt 28'deki ağaçta kök 5 çıkar; H yaprağı ve T'nin bütün alt ağacı budanır, 12 yapraktan 9'u değerlendirilir (ekrandan, 01:15:00; çözüm derste adım adım verilmedi, python ile doğrulandı).
- **Neden alfa-beta derinliği iki katına çıkarır?** En iyi sıralamada incelenen düğüm sayısı $b^m$ yerine $b^{m/2}$ olur. Aynı sürede iki kat derine bakılabilir. Hoca bunu, 4 derinlikli donanım bütçesiyle 8 derinlikli ağacın kullanılabilmesi diye özetledi.
- **Expectiminimax hesabı.** MIN düğümleri: $\min(2,4)=2$, $\min(5,3)=3$; olasılıklar 0.9 ve 0.1 olduğu için şans düğümü $2(0.9)+3(0.1)=2.1$ olur. Diğer dalda MIN değerleri 1 ve $\min(6,4)=4$'tür; şans düğümü $1(0.9)+4(0.1)=1.3$ olur. Kök $\max(2.1, 1.3) = 2.1$ ile sol hamleyi seçer. Tavlada bir şans düğümündeki 21 olasılığın toplamı $6 \cdot \tfrac{1}{36} + 15 \cdot \tfrac{1}{18} = 1$ eder.
- **MCTS'nin mantığı.** Kökten başlayarak birkaç seviye istatistiklere göre seçilir. Seçilen düğümden yeni bir hamle eklenir ve oradan oyun sonuna kadar rastgele hamlelerle oynanır. Sonuç (kazandı/kaybetti) geçilen bütün düğümlere geri yayılır. Örneğin B hamlesiyle 1 milyon oyunun 600 bini kazanılmış, C hamlesiyle 900 bin oyunun 200 bini kazanılmışsa B daha iyi bir hamle sayılır. Rastgele hamleler çok hızlı üretilir; bu yüzden çok sayıda oyun oynanabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
