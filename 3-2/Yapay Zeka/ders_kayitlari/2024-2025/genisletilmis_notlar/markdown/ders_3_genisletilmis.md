# Ders 3 Genişletilmiş Notu: Pekiştirmeli Öğrenme, Q-Learning ve Kendi Kendine Öğrenme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Öğrenme türleri içinde pekiştirmeli öğrenme
- 2. Temel kavramlar
- 3. Q-Learning ve Q tablosu
- 4. Keşfetmek / kullanmak ikilemi
- 5. Q-Learning algoritması ve sayısal güncelleme
- 6. Labirentten çıkış örneği
- 7. Q-Learning'in sınırı ve Deep Q Network
- 8. On-policy, off-policy ve offline RL
- 9. Tartışma soruları ve ChatGPT bağlantısı
- 10. Kendi kendine öğrenme (self-supervised learning)
- 11. Otokodlayıcılar
- 12. Tamamlayıcılar ve parçalara odaklanan diğer yaklaşımlar
- 13. Karşıtsal öğrenme (contrastive learning)
- 14. RL'de ödülü insandan almama ve RLHF

## 1. Öğrenme türleri içinde pekiştirmeli öğrenme

Ders, makine öğrenmesi slaytlarının üçüncü bölümüyle başladı ve önce önceki öğrenme türleri hatırlatıldı. Eğiticili (supervised) öğrenmede modele girdi olarak özellikler ve bu özelliklere karşılık gelen sayısal ya da kategorik çıktılar verilir; regresyon ve sınıflandırma problemleri böyle çözülür. Eğiticisiz (unsupervised) öğrenmede yalnız verinin özellikleri vardır, hiçbir çıktı verilmez.

Pekiştirmeli öğrenmede (reinforcement learning; Türkçede destekleyici ya da takviyeli öğrenme de denir) de modele girdi olarak bir şeyler verilir ama yine çıktı verilmez. Bunun yerine, yaptığı hareketin doğru mu yanlış mı olduğuna, yani ödül mü ceza mı alması gerektiğine dair bilgi verilir ve eğitim bu yolla gerçekleşir. Hoca farkı şöyle anlattı: eğiticili öğrenmede "x'e 3, y'ye 5 girersen sonuç 8'dir" diye yapılacak şey söylenir. Pekiştirmeli öğrenmede böyle bir şey yoktur; yalnız "şunu yaparsan doğru yaptın, şu kadar ödül aldın; bunu yapmazsan şu kadar ceza aldın" denir.

Slaytta konu şu maddelerle özetlendi (ekrandan, 00:10:00):

- Ödül/ceza ile eğitim.
- Ödül genelde uzaktadır.
- Hangi durumda ($S$) hangi hareketin ($A$) yapılacağı öğrenilir.
- Ne yapması gerektiğini söylemeyiz, yalnız ödül/ceza veririz.
- Ajan, toplam ödülü maksimize etmeye çalışır.
- Ajanın hareketleri hangi verilere erişeceğini belirler.

Slayttaki şemada ajan ile ortam (environment) bir döngü oluşturur (ekrandan, 00:10:00): ajan $S_t$ durumunda ve $R_t$ ödülüyle bir $A_t$ hareketi (action) yapar; ortam bu hareket sonucunda yeni ödülü $R_{t+1}$ ve yeni durumu $S_{t+1}$ ajana geri verir. Hoca bunu labirent gibi oyunlar üzerinden anlattı: rasyonel davranan bir ajan bir başlangıç noktasından başlar, farklı durumlar (state) arasında geçiş yapar, her durumda farklı hareketleri vardır ve her hareket için ödül ya da ceza şeklinde geri bildirim alır. Ajanın hedefi, toplayacağı ödülü en büyük yapacak hareketler dizisini bulmaktır.

### 1.1 "Reinforcement" adının kökeni

Hoca, "reinforcement" kelimesinin bilinçli seçildiğini ve eğitim bilimlerinden geldiğini söyledi. İnsan eğitiminde öğrenci bir şeyi yapmaya çalışırken, öğreten kişi doğru yaptığında bunun doğru olduğunu, yanlış yaptığında yanlış olduğunu geri bildirir; böylece öğrenme mükemmele doğru ilerler. Bu, önceki öğrenme biçimlerinden biraz farklı bir mekanizmadır.

Her probleme her öğrenme türü uygulanmaz. Bazı bilgi ve beceriler bu yolla daha iyi edinilir. Hocanın benzetmesi dil öğrenimiydi: yabancı dil öğrenmek, bol soru çözülen bir matematik çalışması gibi değildir; insan sürekli tekrar ede ede belli bir eşiği aşana kadar beceriyi edinir. Pekiştirmeli öğrenmede de buna benzer bir süreç vardır.

### 1.2 Nerede kullanılır

Pekiştirmeli öğrenme, sürekli değil ayrık (discrete) bir alanda yapılır. Olası bütün durumlara erişilebilen simülasyonlarda çalışılabilir; burada simülasyondan kasıt daha çok oyunlardır. Oyunlarda kendi kendine eğitim mümkündür, çünkü öğrenen sisteme "oyunu kazandın", "kaybettin" ya da "şu kadar puan aldın" geri bildirimini simülasyon dünyası kendisi verir.

## 2. Temel kavramlar

Hoca, arama problemlerinde durum uzayı ağacı (state space tree), oyunlarda oyun ağacı (game tree) gibi veri yapılarından söz edildiğini hatırlattı; pekiştirmeli öğrenmenin de kendine göre bir veri yapısı ve dayandığı kavramlar vardır. Slayttaki tanımlar (ekrandan, 00:15:00):

- **Environment / ortam:** ajanın içinde bulunduğu ortam.
- **State / durum:** mevcut durum, yani ajanın bulunduğu konum ya da durum.
- **Reward / ödül:** ortamdan gelen geri besleme.
- **Policy / politika:** ajanın durumlarını hareketlerine eşleyen tablo. Hangi durumda hangi hareket yapılırsa hangi ödülün alınacağını toplu olarak söyler.
- **Value / gelecek ödül:** şu durumda şu hareketi yapınca alınacak gelecek (muhtemel) ödül.

## 3. Q-Learning ve Q tablosu

Pekiştirmeli öğrenme şemsiye bir kavramdır ve altında zamanla farklı algoritmalar geliştirilmiştir. Q-Learning bunların en yaygın bilinenlerinden biridir. Hoca, internette hem kod hem de adım adım basit örnekler bulunduğunu söyledi.

### 3.1 Örnek ortam

Derste kullanılan örnekte 0'dan 8'e kadar numaralı 9 durum vardır. Başlangıç 0 numaralı durum, hedef 8 numaralı durumdur. Her durumdan yukarı, aşağı, sola ve sağa olmak üzere dört hareket yapılabilir; hoca bunun aslında bir arama problemine benzediğini vurguladı. Ödül yalnız 8'e ulaştıran hareketlerde vardır; bunlar 3 ve 6 numaralı durumlardan yapılan hareketlerdir ve ödül 10'dur. 4 ve 5 numaralı durumlar çukurdur: yasaklanmış, gidildiğinde kaybedilen yerlerdir. Bu kısıtlar yüzünden 0'dan önce 1'e, 1'den 2'ye gitmek gerekir; 2'den 3'e ya da 6'ya gidilebilir.

<!-- BELİRSİZ: Izgaranın şekli (hangi hareketin hangi duruma götürdüğü) incelenen karelerde görünmüyor; hareket-durum eşleşmeleri altyazıdan ve Q tablosundaki dolu hücrelerden çıkarıldı. -->

### 3.2 Q tablosu

Q tablosunun satırları durumlar, sütunları hareketlerdir. Bu örnekte 9 satır (0-8) ve 4 sütun (UP, DOWN, LEFT, RIGHT) vardır, yani $9 \times 4$ bir matristir. Her hücre, o durumda o hareketi yapmanın ne kadar mantıklı olduğunu, yani kazandıracağı (gelecek) ödülü tutar.

Başlangıçta bütün değerler 0'dır, çünkü henüz hiç hareket yapılmadığı için ödül ya da ceza bilgisi yoktur. Tablo zamanla kendini günceller. Hoca bunu, başta haritası sisli olan ve oyuncu ilerledikçe açılan oyunlara (bomberman gibi) benzetti.

Slayttaki üç tablo (ekrandan, 00:20:00) tablonun nasıl dolduğunu gösterir. Siyah satırlar (4 ve 5) çukurları, sarı satır (8) hedefi gösterir. Yalnız sıfırdan farklı hücreler:

| Durum | Hareket | $t=0$ | $t=k$ | $t=\infty$ |
|---|---|---|---|---|
| 0 | LEFT | 0 | 0 | 0.45 |
| 1 | DOWN | 0 | 0 | 1.01 |
| 2 | DOWN | 0 | 2.25 | 2.25 |
| 2 | LEFT | 0 | 2.25 | 2.25 |
| 3 | LEFT | 0 | 5 | 5 |
| 6 | DOWN | 0 | 5 | 5 |
| 7 | LEFT | 0 | 2.25 | 2.25 |

Hoca $t=k$ tablosunu şöyle okudu: 2'den aşağı gitmek (3 ya da 6'ya) kazançlıdır; 3 numaralı durumdayken sola gitmek 8'e götürür ve ödül kazandırır; 6'dan aşağı gitmek de aynı şekilde ödül kazandırır. Tablo doldukça hangi noktaya gidilmesi gerektiği belirginleşir. Başlangıçta 0'dayken mecburen 1'e gidilir; zamanla tablo bu yolun da değerini gösterir.

### 3.3 Episod ve politika

Bir başlangıç noktasından başlayıp başarısızlıkla (çukura düşme) ya da hedefe ulaşmakla tamamlanan hareketler dizisine **bölüm** ya da **episod** denir. Politika, mevcut $s$ durumunda yapılacak hareketi seçer ve bu seçim Q tablosuna göre yapılır. Ajan iyi bir politika arar: gerekirse deneme yanılmayla, hepsi sıfır olan bir tablodan başlayıp politikayı iyileştirir.

## 4. Keşfetmek / kullanmak ikilemi

Politikayı iyileştirirken bir ikilem ortaya çıkar. Hoca bunu tepe tırmanma algoritmasıyla bağladı: bir noktadan başlayıp hep yukarı doğru gidilirse hedeflenen en iyiye ulaşılacağı düşünülür, ama bu her zaman doğru değildir. Simulated annealing'de bazen daha kötü bir duruma gitmeye izin verilir; böylece yerel en iyilerden kaçıp aramayı başka bir yerden sürdürerek daha yüksek bir tepeye ulaşmak mümkün olur.

Q-Learning'deki soru da aynıdır: tablonun "şu hareketi yaparsan şu kadar ödül alırsın" bilgisini her zaman mı kullanmalı, yoksa bazen bu bilginin dışına çıkıp başka olasılıkları da denemeli mi? Tablodaki bilgiyi doğrudan kullanmaya **exploitation (kullanmak)**, bilgiyi kullanmadan yeni keşifler yapmaya **exploration (keşfetmek)** denir. Örneğin $t=k$ anında 3'teyken sola gidip 5 puan almak en mantıklı görünür, ama daha geniş bir problemde başta 0 görünen bir yöne gidip tabloyu oradan güncellemek çok daha iyi değerler ortaya çıkarabilir.

Slayttaki örnekler (ekrandan, 00:25:00):

- Acıktınız: yeni bir yeri denemek mi, iyi bildiğiniz bir yere gitmek mi?
- Petrol arıyorsunuz: daha önce petrol çıkmış bölgede çalışmak mı, yeni bir bölgede çalışmak mı?
- Simulated annealing'i hatırlayın: rastgele bir hareket seç, iyiyse uygula, değilse azalan bir olasılıkla uygula.

Hoca, "en kestirme yol bildiğin yoldur" atasözünün kullanmaya karşılık geldiğini, yeni bir maceraya atılmanın ise bazen çok daha iyi sonuçlar getirebileceğini söyledi. Simulated annealing'de yukarı gitmek iyiyse zaten uygulanır; iyi değilse "uygulasak iyi olabilir mi" diye denenir ve bu deneme başta yüksek, sonraki süreçlerde azalan bir olasılıkla yapılır. Daha kötü bir çözümü test etmek, daha iyi bir adım olup olmadığına karar vermek için kullanılır. Q-Learning'de de benzer bir durum vardır.

## 5. Q-Learning algoritması ve sayısal güncelleme

### 5.1 Algoritma

Slayttaki algoritma (ekrandan, 00:30:00):

```text
Her bölüm için tekrar et
    Başlangıç durumuna git (s = s0)
    s bölüm sonu olmadığı sürece
        politikaya göre hareket (a) seç
        hareketi yap, ödülü (R) ve sonraki durumu (s') belirle
        Q[s, a] = Q[s, a] + α*(R + γ*max[Q(s', A)] - Q[s, a])
        s = s'
```

Güncelleme kuralı matematiksel olarak:

$$Q[s,a] \leftarrow Q[s,a] + \alpha\left(R + \gamma \max_{A} Q(s',A) - Q[s,a]\right)$$

Hoca formülü şöyle okudu: bir sonraki $s'$ durumundan yapılabilecek bütün hareketlerin değerleri arasından en büyüğü bulunur ve $\gamma$ ile çarpılır; buna mevcut ödül $R$ eklenir; bu toplamla tablodaki mevcut değer arasındaki fark alınır, $\alpha$ ile çarpılır ve mevcut değere eklenir. Örneğin 3 numaralı durumdan sonraki duruma geçildiğinde, o durumdan sağa, sola, yukarı, aşağı gitmenin her birinin tabloda bir değeri vardır; bunların en büyüğü alınır.

Slayttaki açıklamalar (ekrandan, 00:30:00):

- $\max[Q(s',A)]$: $s'$ durumunda yapılabilecek tüm hareketlerin ödüllerinin maksimumu.
- Politikaya göre hareket seçimi keşfet / kullan ikilemidir: $Q[s,:]$ değerlerinin en yükseğini seçmek **kullanmak**, rastgele birini seçmek **keşfetmek**tir.
- **Decay ε-greedy:** rastgele hareket seçme olasılığı giderek azalır, simulated annealing'deki sıcaklık gibi.
- $\alpha$: öğrenme katsayısı.
- $\gamma$: $(0,1)$ arasındadır; 0'a yakınsa yakın ödüllere, 1'e yakınsa gelecek ödüllere odaklanılır.

Hoca en yüksek Q'yu seçmenin, algoritma analizi dersinde görülen açgözlü (greedy) algoritmalara benzediğini söyledi. Rastgele seçim ise sisteme "önce hataya gider gibi yapıp" keşif yapma izni verir. Decay ε-greedy'yi şöyle örnekledi: başta rastgele seçim sayısı 10 ise sonra 7-8'e, sonra 3-5'e indirilir, sonra iyice azaltılır. $\alpha$ ve $\gamma$ önceden seçilen sabit katsayılardır.

### 5.2 Sayısal güncelleme örneği

Hoca, tablonun başlangıç hâlinde (bütün değerler 0) 3 numaralı durumdan LEFT hareketi yapıldığında ne olduğunu hesapladı. Verilenler: $\alpha = 0.5$, $\gamma = 0.9$; 3'ten LEFT ile 8'e gidilir ve ödül $R = 10$'dur; tablodaki mevcut değer $Q[3,\text{LEFT}] = 0$; 8 numaralı durumun UP, DOWN, LEFT, RIGHT değerlerinin hepsi 0'dır, yani $\max_A Q(8,A) = 0$.

$$Q[3,\text{LEFT}] = 0 + 0.5\,(10 + 0.9 \cdot 0 - 0) = 5$$

Böylece 3'ten sola gitmenin değeri 5 olarak güncellenir; yani ajan artık "3'ten LEFT yaparsam 5 birim ödül alırım" bilgisine sahiptir. Hoca, 2 numaralı durum için de benzer bir hesap olduğunu ve tablonun bu şekilde dolduğunu söyledi.

Aynı formül önceki durumlara uygulanınca tablodaki diğer değerler çıkar (ara adım eklendi). 2'den 3'e giden hareket için ödül 0, $\max_A Q(3,A) = 5$ olduğundan:

$$Q[2,\cdot] = 0 + 0.5\,(0 + 0.9 \cdot 5 - 0) = 2.25$$

Benzer şekilde $0.5 \cdot 0.9 \cdot 2.25 = 1.0125 \approx 1.01$ (1 numaralı durum) ve $0.5 \cdot 0.9 \cdot 1.01 \approx 0.45$ (0 numaralı durum) bulunur. Bu değerler slayttaki $t=\infty$ tablosuyla uyuşur ve python ile doğrulandı.

> **Ders sonrası not:** Slayttaki $t=\infty$ tablosu her hücrenin yalnız bir kez güncellendiği hâli gösteriyor gibi duruyor. Güncelleme çok sayıda bölüm boyunca tekrarlansaydı büyük olasılıkla $Q[3,\text{LEFT}]$ 10'a, ondan bir adım önceki hücreler $0.9 \cdot 10 = 9$'a, iki adım önceki hücreler $8.1$'e yaklaşırdı.

Hoca son olarak çukurlardan uzak durmanın da bir tür ödül sayılabileceğini, bunun tabloya yansıtılabileceğini ve bu tür oyun kurallarının algoritmaya kodlanabildiğini söyledi.

## 6. Labirentten çıkış örneği

İkinci örnek bir labirentten çıkıştır (ekrandan, 00:35:00). Hoca bu tür oyunlarda ödülün her zaman olduğu gibi işe yaramadığını, bazen tersinden düşünmek gerektiğini söyledi. Ayrıca üzerinde çalışılan alan baştan bütünüyle açık değildir; ajan ilerledikçe alan açılır.

Bu örnekte her adımda ödül $-1$'dir ve hedef bitiş noktasına ulaşmaktır. Her adım ceza getirdiği için en kısa yol en yüksek toplam ödülü verir. Hoca, ödül bir yerde daha büyük olsaydı ajanın yanlışlıkla oraya yönelebileceğini; ödülü adım başına $-1$ diye tersinden tanımlamanın bunu engellediğini anlattı. Her durumda yine en fazla ödülü kazandıran harekete göre politika belirlenir; value yine gelecek ödüldür.

Slayttaki iki şekil:

- **Oklar:** her $s$ durumunda en iyi value'ya (gelecek ödüle) sahip olan hareket. Hoca, bazı hücrelerde okun neden o yönü gösterdiğini (yukarı gitmenin bir yönlendirme sağlamadığı, aşağı gitmenin çıkmaza götüreceği) şekil üzerinde gösterdi.
- **Gelecek ödüller:** her hücredeki değer, o hücreden bitişe ulaşmak için toplanacak ödüldür. Bitişe komşu hücrenin değeri $-1$'dir, ondan önceki $-2$, $-3$, ... diye azalır. Başlangıç hücresinin değeri $-16$'dır; ana yoldan sapan çıkmaz kollardaki hücrelerin değerleri daha küçüktür (örneğin $-22$, $-23$, $-24$).

## 7. Q-Learning'in sınırı ve Deep Q Network

Q-Learning sınırlı bir alanda, sınırlı sayıda hamleyle çalışır. Q matrisi, durum sayısı çarpı her durumdan yapılabilecek hareket sayısı kadar, yani $|S| \times |A|$ boyutunda sabit bir yapıdır. Zamanla yeni durumlar ortaya çıkarsa (örneğin 10 durum 20 olursa) matrise yeni satırlar eklenmesi gerekir; hem yeni durumlar hem yeni hareketler eklenirse matrisin baştan aşağı büyümesi ve güncellenmesi gerekir.

Bu yüzden Q-Learning daha önce görmediği bir durumun değerini bilemez; yeni durumlara uyum sağlama yeteneği yoktur. Gerçek dünyadaki oyunlarda ise yeni durum sayısı çok fazladır.

Çözüm önerisi, yeni durumu eldekilerden birine benzetmektir. Atari oyunları için geliştirilen **Deep Q Network**'te ekranın görüntüsü girdi olarak verilir, evrişimli sinir ağları (CNN) ara işlemi yapar ve sonuçta Q değerleri, yani $Q(s,a)$ matrisi tahmin ettirilir. Bu, bir derin öğrenme ağıyla ve aslında eğiticili öğrenme yaklaşımıyla olası hareketlerin çıktı olarak belirlenmesidir. Tek bir anın görüntüsü her zaman yeterli olmayabilir; farklı zamanlardan görüntüler alınarak farklı durum ve hareketler tespit edilir.

Hoca hareket sayısını şöyle örnekledi: joystick ile sekiz yöne gitmenin 8 çıktısı, düğmeye basarak sekiz yöne gitmenin 8 çıktısı, bir de hiçbir yöne gitmeden yalnız düğmeye basma vardır; yani 16-17 çıktıdan birinin tahmin edilmesi söz konusudur. Ağ hamleyi belirledikten sonra oyun ve pekiştirmeli öğrenme devam eder.

Hoca bu çalışmanın makalesinin Nature'da yayımlandığını ve 5-6, en fazla 10 yıllık olduğunu söyledi.

> **Ders sonrası not:** Deep Q Network makalesi büyük olasılıkla 2015 yılında Nature'da yayımlanmıştır; dersin yapıldığı tarihe göre yaklaşık 10 yıl öncesidir.

## 8. On-policy, off-policy ve offline RL

Slayttaki maddeler (ekrandan, 00:40:00):

- Ajan, durumu ($s_t$) gözler, buna göre $\pi_\theta(a|s)$ politikasını kullanıp hareket ($a$) seçer. Bunun sonucunda ödül ($r$) alır ve sonraki duruma ($s_{t+1}$) geçer.
- Policy: durumu harekete dönüştüren bir fonksiyon (amaç bunu optimize etmek).
- Toplanan deneyimlerin formatı: $\langle s, a, s', r\rangle$.
- Bu deneyimlerle policy eğitilir.
- Yöntemlerin farkı, deneyimlerin üretim süreçleridir.

Hoca $\pi_\theta(a|s)$'yi, $s$ durumundayken $a$ hareketinin seçilme koşullu olasılığı olarak açıkladı. Deneyim dörtlüsü "$s$ durumunda $a$ hareketini yaparsam $s'$ durumuna geçip $r$ kadar ödül alırım" bilgisini taşır. Yöntemlerin farkını anlatırken on-policy yöntemde politikanın ürettiği yeni bir veri kümesinin (rollout data) sürekli güncellendiğini, off-policy yöntemde ise deneyimlerin bir tamponda (buffer) biriktirilip güncellemelerin bunun üzerinden yapıldığını söyledi; bunların ayrıntı olduğunu belirtti.

<!-- BELİRSİZ: On-policy / off-policy / offline RL şemalarının ayrıntısı (00:40:13-00:41:06) incelenen karelerde görünmüyor; altyazıda da "$\pi_k$", "rollout data" ve "buffer" dışında net değil. -->

> **Ders sonrası not:** Hoca kaynak makale için "2005 yılının bir çalışması" dedi; slayttaki kaynak `arxiv.org/pdf/2005.01643` bağlantısıdır (ekrandan, 00:40:00). Buradaki "2005" yıl değil, arXiv numarasının ilk kısmıdır ve büyük olasılıkla Mayıs 2020'yi gösterir.

> **Ek bilgi (derste anlatılmadı):** On-policy yöntemler yalnız o anki politikanın topladığı deneyimle eğitilir. Off-policy yöntemler başka (örneğin eski) politikaların topladığı ve tamponda saklanan deneyimleri de kullanabilir. Offline RL'de ise eğitim sırasında ortamla hiç etkileşim kurulmaz; önceden toplanmış sabit bir deneyim veri kümesiyle politika eğitilir.

## 9. Tartışma soruları ve ChatGPT bağlantısı

Hoca slaytta doğrudan cevabı olmayan, hâlâ tartışılan bazı yorum soruları olduğunu söyledi ve bunları okudu:

- A* algoritması ortamdaki oyunlarla birleştirilebilir mi? Hoca A*'ın sezgisel bilgiyle en kısa yolu daha kısa sürede bulan bir algoritma olduğunu hatırlattı.
- Hareket ve durumların ayrık ya da stokastik olması dikkate alınmalıdır.
- Şimdiye kadar tek bir ajan hareket ettirildi; ajanlar çoklu olursa ya da oyuncular birbirleriyle rekabet ederse ne olur?
- Ödülün seyrek olduğu (sparse reward) oyunlarda insan taklidi (human imitation) ve sahte ödüller (pseudo rewards), yani inverse reinforcement learning gibi farklı yaklaşımlar vardır.
- Bir oyun olarak diyalog: ChatGPT'nin temellerini oluşturan yaklaşım.

<!-- BELİRSİZ: Tartışma sorularının slayttaki tam metni incelenen karelerde yok; maddeler altyazıdan kuruldu. -->

Hoca ChatGPT'nin nasıl çalıştığını kesin olarak söylemenin bugün zor olduğunu belirtti. Eğitiminde insanların sürekli veri etiketlediği bir aşama, yani eğiticili öğrenme vardır; ama bunun dışında hangi kelimeden sonra hangi kelimenin geleceğini hareket gibi ele alan pekiştirmeli öğrenme mekanizmaları da bulunur. Bu karmaşık bir yapıdır ve bu çalışmalar ChatGPT'nin ünlü olmasından çok önce de yapılıyordu.

## 10. Kendi kendine öğrenme (self-supervised learning)

Dersin ikinci kısmında başka bir öğrenme yaklaşımına geçildi. Öğrenme türleri derece derece sıralanır: eğiticili (supervised), kendi kendine eğiticili (self-supervised), yarı eğiticili (semi-supervised) ve eğiticisiz (unsupervised). Yarı eğiticili öğrenme bu derste anlatılmadı. Bu bölümün başlıkları otokodlayıcılar, tamamlayıcılar ve karşıtsal öğrenmedir.

Kendi kendine öğrenmenin amacı, insan emeğine ek bir ihtiyaç duymadan eğitim kümesi üretmektir: giriş-çıkış ikilileri ve girişe karşılık hata, verinin kendisinden üretilir. Hoca bunun GPT gibi modellerin en önemli bileşenlerinden biri olduğunu söyledi.

Gerekçe şudur: eğiticili öğrenme etiketli veri ister ve bunu elde etmek her zaman kolay değildir. Örneğin tıbbi bir veri toplanacaksa o alanda yeterli vaka olmayabilir ya da veri toplamak riskli veya pahalı olabilir. Büyük miktarda eğitim örneği üretmek zordur. Bunun yerine daha ucuz ve hızlı bir yol aranır; insan etiketleyicilerin davranışlarına ve hatalarına bağlı kalmadan veri üretilir.

**Soru:** Otokodlayıcılar yapay hata mı üretiyor? **Cevap:** Hayır, yapay hata değil, yapay veri üretiyor; daha çok aradaki gerekli parçaları üretiyor.

## 11. Otokodlayıcılar

Otokodlayıcıda (autoencoder) girdi, olabilecek en az bilgiyle temsil edilecek şekilde kodlanır (encoder); sonra aynı mantıkla çalışan bir çözücü (decoder) ile girdi yeniden tahmin edilir. Çıktının girdiye çok benzemesi beklenir. Burada bir sinir ağı vardır ve ağırlıkları, ağa bir girdi verildiğinde yine aynı girdiyi çıktı olarak verecek şekilde ayarlanır; yani girdinin kendisi tahmin edilir. Görüntü sıkıştırma ya da sınıflandırma amacıyla kullanılır.

Slayttaki maddeler (ekrandan, 00:50:00):

- Amaç: veriyi temsil eden bir saklı uzay (latent space) bulmak.
- Örnekleri: VAE (Kingma ve Welling, 2013, "Auto-encoding variational bayes") ve difüzyon modelleri.
- VAE şeması: $x$ → olasılıksal kodlayıcı (probabilistic encoder) → $\mu$, $\sigma$ ve $\epsilon$ → $z$ → olasılıksal çözücü (probabilistic decoder) → $x'$.
- Difüzyon şeması: ileri (gürültü ekleme) sürecinde temiz örnek $x_0$ adım adım saf gürültüye $x_T \sim \mathcal{N}(0,I)$ dönüştürülür; geri (gürültü giderme) sürecinde gürültüden başlanıp veri üretilir.

Hoca varyasyonel otokodlayıcı ve difüzyon modellerinin ayrıntıları için slayttaki kaynaklara bakılmasını önerdi.

## 12. Tamamlayıcılar ve parçalara odaklanan diğer yaklaşımlar

### 12.1 Tamamlayıcılar

Tamamlayıcılar verinin içindeki parçalara odaklanır, bazı parçaların eksik olduğunu düşünüp onları tahmin etmeye çalışır; ya da bir sonraki parçayı tahmin eder. Girdinin bir parçası diğer parçasından tahmin edilir.

Hoca bunu İngilizce sınavlarındaki boşluk doldurma sorularına benzetti: cümlede bir kelime boş bırakılır ve cümlenin mantığına göre tahmin edilir. Boşluk sayısı arttıkça tahmin zorlaşır. Tamamlayıcıların bir görevi bir kısmı silip tahmin etmektir. Bir adım ötesi, bir cümlenin ya da görüntünün sonraki parçasını tahmin etmektir (GPT, Vision Transformer). Metinde ya da görüntüde birden fazla eksik parçayı tahmin etmek, ya da bir kelimenin beş adım öncesi ve sonrasındaki kelimeleri, yani çevresini tahmin etmek de (Word2Vec) bu gruptadır.

Zaman ve uzay bilgisi dikkate alınınca şu biçimler ortaya çıkar:

- Girdinin bir parçasını diğer parçasından tahmin etmek.
- Geçmişten geleceği tahmin etmek.
- Görünür olandan maskelenmiş (gizlenmiş) olanı tahmin etmek.

Slayttaki şemada görünür parçalar kırmızı (pembe), maskelenmiş parçalar yeşil (turkuaz) ile gösterilmiştir; görünenlerden maskelenmişler tahmin edilir.

<!-- BELİRSİZ: Tamamlayıcılar slaytındaki şemaların ayrıntısı (00:52:20-00:53:53) incelenen karelerde görünmüyor. -->

### 12.2 Parçalara odaklanan diğer yaklaşımlar

Slayttaki maddeler (ekrandan, 00:55:00):

- Bir parçayı değiştirip değişeni belirleme (ELMo, ELECTRA). Şemada bazı kelimeler maskelenir, küçük bir üretici (generator, tipik olarak küçük bir maskeli dil modeli) bunları doldurur; ayırt edici (discriminator, ELECTRA) her kelimenin özgün mü değiştirilmiş mi olduğunu belirler.
- Parçaların yerlerini karıştırıp düzeltme (BART). Şemada token maskeleme (A\_C.\_E.), cümle permütasyonu (DE.ABC.), belge döndürme (C.DE.AB), token silme (A.C.E.) ve metin doldurma (A\_.D\_E.) bozulmalarından özgün metin (ABC.DE.) geri elde edilir.
- Sıra tahmin etme (BERT NSP/SOP).
- Aynı cümle mi (SSP).
- Çözünürlük artırma.

Hoca bir görüntüden ya da metinden bir parçanın alınıp değiştirildiğini ve modelin değişen parçayı belirlediğini anlattı. BART'ın (BERT değil) karıştırılmış parçaları özgün sırasına geri çevirdiğini vurguladı. Çözünürlük artırmanın görüntü işlemede ya da genel olarak bir verinin çözünürlüğünü artırmada kullanıldığını söyledi.

## 13. Karşıtsal öğrenme (contrastive learning)

Karşıtsal öğrenme, zamanda ve mekânda birlikte olma ya da olmamaya göre temsilleri yakınlaştırıp uzaklaştırmaya dayanır. Aynı bütüne ait parçaların temsilleri birbirine yakın olmalıdır. Bir veri grubunun parçalarının temsil vektörlerinin birbirine yakın, farklı gruplarınkinin ise birbirinden olabildiğince uzak olması istenir; hoca bunu küme içi tutarlılığın yüksek, kümeler arası uzaklığın fazla olması durumuna benzetti.

Kelime tabanlı metinlerde pozitif ve negatif örnekler, cümle tabanlı ve eğiticili durumlarda yine pozitif ve negatif örnekler ve ayrıca zor negatif örnekler kullanılır.

Slayttaki görsel örneği hoca şöyle anlattı: bir köpek görüntüsünden iki farklı parça (örneğin ayak kısmı ve köpeğin kendisi) veri artırma (augmentation) ile elde edilir. Her parça CNN ağlarından ve çok katmanlı algılayıcıdan (MLP) geçirilir. Çıkan iki vektör birbirine benzer, birbirini çeker (attraction). Aynı şekilde bir koltuk görüntüsünden iki parça (biri gri seviyeli) alınır; bu iki vektör de birbirini çeker. Ama köpek vektörleri ile koltuk vektörleri karşılaştırıldığında birbirinden uzak oldukları, birbirini ittikleri görülür.

<!-- BELİRSİZ: Karşıtsal öğrenme slaytının şeması (00:55:44-00:58:09) incelenen karelerde görünmüyor; anlatım altyazıdan kuruldu. -->

## 14. RL'de ödülü insandan almama ve RLHF

Son başlık, pekiştirmeli öğrenmede ödülün insandan alınmadığı durumlardır:

- Kendi kendine yarış (AlphaZero).
- Ödülü ortamdan alma.
- Ödülü başka bir modelden alıp eğitimi sürdürme.

Slayttaki "Başka bir modelden alma" maddesinin altında RLHF'nin RL kısmı ve TRL'de BERT\_sentiment\_finetuned örneği yer alır (ekrandan, 01:00:00). Hoca bunun ChatGPT ile ilgili olduğunu söyledi: ödül insandan değil başka bir modelden alınır. Slayttaki üç aşama (ekrandan, 01:00:00):

1. **Demonstrasyon verisi toplanır ve eğiticili bir politika eğitilir.** Prompt veri kümesinden bir prompt örneklenir; bir etiketleyici istenen çıktı davranışını gösterir; bu veri GPT-3.5'i eğiticili öğrenmeyle ince ayarlamak (fine-tune) için kullanılır.
2. **Karşılaştırma verisi toplanır ve ödül modeli eğitilir.** Bir prompt ve birkaç model çıktısı örneklenir; etiketleyici çıktıları en iyiden en kötüye sıralar (örneğin D > C > A > B); bu veri ödül modelini eğitmek için kullanılır.
3. **Politika, PPO pekiştirmeli öğrenme algoritmasıyla ödül modeline karşı optimize edilir.** Veri kümesinden yeni bir prompt örneklenir; PPO modeli eğiticili politikadan başlatılır; politika bir çıktı üretir; ödül modeli bu çıktı için bir ödül hesaplar; ödül, politikayı PPO ile güncellemek için kullanılır.

Hoca birinci aşamayı, bir soru ve cevabından oluşan örnekler üzerinden etiketleyicinin istenen çıktıyı göstermesi olarak; ikinci aşamayı farklı model çıktılarının karşılaştırılması olarak; üçüncü aşamayı da çıktıların nasıl daha iyi olabileceğine dair bir optimizasyon olarak özetledi.

> **Hocanın vurgusu:** Bu modellerin temel mekanizmasının ayrıntısı sorulmayacak, ama genel yaklaşımlara dair soru gelebilir; bu yüzden slaytlardaki kaynakların okunması tavsiye edildi.

> **Ek bilgi (derste anlatılmadı):** RLHF, "Reinforcement Learning from Human Feedback" (insan geri bildiriminden pekiştirmeli öğrenme) kısaltmasıdır. İnsan geri bildirimi yalnız ikinci aşamada, ödül modelini eğitmek için kullanılır; üçüncü aşamadaki pekiştirmeli öğrenme döngüsünde ödül doğrudan bu modelden gelir. PPO (Proximal Policy Optimization), politikanın her güncellemede çok fazla değişmesini sınırlayan bir politika gradyanı yöntemidir.

## Örnek Sorular

### Soru 1 (ekrandan, 00:20:00 ve 00:30:00)

Q tablosunun bütün değerleri 0 iken, 3 numaralı durumdan LEFT hareketi yapılıp 10 ödüllü hedef duruma (8) ulaşılıyor. $\alpha = 0.5$, $\gamma = 0.9$ için $Q[3,\text{LEFT}]$ hangi değere güncellenir?

> **Çözüm (derste verildi):** $Q[3,\text{LEFT}] = 0 + 0.5\,(10 + 0.9 \cdot \max_A Q(8,A) - 0) = 0.5\,(10 + 0.9 \cdot 0) = 5$. Ardından 3'e götüren bir hareket için (ödül 0) $0.5\,(0 + 0.9 \cdot 5) = 2.25$ bulunur; bu değerler slayttaki $t=k$ tablosuyla uyuşur.

### Soru 2 (derste sözlü, 00:41:31)

A* algoritması ortamdaki oyunlarla (pekiştirmeli öğrenmeyle) birleştirilebilir mi? Hareket ve durumların ayrık ya da stokastik olması, çoklu ve rekabetçi ajanlar bu soruyu nasıl etkiler?

> Hoca bu soruların açık uçlu olduğunu ve hâlâ tartışıldığını söyledi; derste cevap verilmedi.

### Soru 3 (derste sözlü, 00:48:56)

Otokodlayıcılar yapay hata mı üretir?

> **Cevap (derste verildi):** Hayır; yapay hata değil, yapay veri üretir. Girdi en az bilgiyle kodlanır ve çözücü girdiyi yeniden tahmin eder.

## Dersin Toparlaması

Bu derste pekiştirmeli öğrenmenin temel fikri, yani doğru çıktının söylenmediği, yalnız ödül ya da cezanın verildiği öğrenme biçimi ele alındı. Ortam, durum, ödül, politika ve gelecek ödül kavramlarından sonra Q-Learning algoritması, Q tablosu ve güncelleme kuralı sayısal bir örnekle işlendi. Keşfet / kullan ikilemi simulated annealing ile ilişkilendirildi, labirent örneğinde ödülün tersinden (adım başına ceza) tanımlanması gösterildi. Q-Learning'in yeni durumlara uyum sağlayamaması Deep Q Network'e, deneyim toplama biçimleri de on-policy, off-policy ve offline RL ayrımına bağlandı.

Dersin ikinci kısmında etiketi verinin kendisinden üreten kendi kendine öğrenme yöntemleri anlatıldı: otokodlayıcılar (VAE, difüzyon), tamamlayıcılar (boşluk doldurma, sonraki parçayı tahmin), parçalara odaklanan diğer yaklaşımlar (ELECTRA, BART, BERT NSP/SOP) ve karşıtsal öğrenme. Son olarak ödülün insandan değil başka bir modelden alındığı RLHF'nin üç aşaması gösterildi; bu, pekiştirmeli öğrenme ile büyük dil modelleri arasındaki bağlantıyı kurdu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
