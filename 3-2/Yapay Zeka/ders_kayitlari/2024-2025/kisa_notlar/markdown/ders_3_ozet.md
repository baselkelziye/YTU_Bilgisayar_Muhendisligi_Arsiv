# Ders 3 Çalışma Özeti

## Genel Konular

- Pekiştirmeli öğrenme (reinforcement learning, destekleyici / takviyeli öğrenme)
  - Eğiticili öğrenmede veriye girdi özellikleri ve bunlara karşılık gelen sayısal ya da kategorik çıktılar verilir (regresyon, sınıflandırma). Eğiticisiz öğrenmede yalnız özellikler vardır, çıktı yoktur.
  - Pekiştirmeli öğrenmede çıktı verilmez. Ajana ne yapması gerektiği söylenmez; yalnız yaptığı hareketin sonucunda ödül ya da ceza verilir.
  - Slayttaki maddeler (ekrandan, 00:10:00): ödül/ceza ile eğitim; ödül genelde uzaktadır; hangi durumda ($S$) hangi hareketin ($A$) yapılacağı öğrenilir; ajan toplam ödülü maksimize etmeye çalışır; ajanın hareketleri hangi verilere erişeceğini belirler.
  - Ajan-ortam döngüsü (ekrandan, 00:10:00): ajan $S_t$ durumunda $A_t$ hareketini yapar; ortam ona $R_{t+1}$ ödülünü ve $S_{t+1}$ sonraki durumunu döndürür.
  - "Reinforcement" adı eğitim bilimlerinden gelir: öğrenen kişiye yaptığının doğru ya da yanlış olduğu geri bildirimi verilerek öğrenme iyileştirilir. Hoca dil öğrenimini benzetme olarak verdi: bilgi ve beceri, tekrar ede ede bir eşik aşılana kadar edinilir.
  - Ayrık (discrete) durum uzaylarında ve olası bütün durumlara erişilebilen simülasyonlarda, özellikle oyunlarda kullanılır. Oyunda kazandın/kaybettin bilgisi simülasyon dünyası tarafından geri bildirim olarak verilir; bu yüzden kendi kendine eğitim mümkündür.
- Temel kavramlar (ekrandan, 00:15:00)
  - Environment / ortam: ajanın içinde bulunduğu ortam.
  - State / durum: mevcut durum.
  - Reward / ödül: ortamdan gelen geri besleme.
  - Policy / politika: ajanın durumlarını hareketlerine eşleyen tablo.
  - Value / gelecek ödül: şu durumda şu hareketi yapınca alınacak gelecek ödül.
  - Arama problemlerinde durum uzayı ağacı, oyunlarda oyun ağacı vardı; pekiştirmeli öğrenmenin de kendine göre veri yapısı vardır.
- Q-Learning ve Q tablosu
  - Pekiştirmeli öğrenme bir şemsiye kavramdır; Q-Learning bu şemsiyenin altındaki yaygın algoritmalardan biridir.
  - Örnek: 0'dan 8'e kadar numaralı 9 durum; başlangıç 0, hedef 8. Her durumdan yukarı, aşağı, sola, sağa hareket edilebilir. 4 ve 5 numaralı durumlar çukurdur (gidilmemesi gereken yerler). Yalnız 8'e ulaştıran hareketler (3 ve 6 numaralı durumlardan) ödül verir; ödül 10'dur. <!-- BELİRSİZ: Izgara şeklinin kendisi (hangi hareketin hangi duruma götürdüğü) incelenen karelerde görünmüyor; yalnız Q tabloları görünüyor. -->
  - Q tablosu: satırlar durumlar (9 satır), sütunlar hareketler (UP, DOWN, LEFT, RIGHT; 4 sütun). Başlangıçta bütün değerler 0'dır; henüz hareket yapılmadığı için ödül ya da ceza bilgisi yoktur. Hoca bunu, ilerledikçe açılan sisli oyun haritasına benzetti.
  - Episod (bölüm): bir başlangıç noktasından başlayıp başarısızlıkla ya da hedefe ulaşmakla biten hareketler dizisi.
- Q-Learning algoritması (ekrandan, 00:30:00)
  - Her bölüm için: başlangıç durumuna git ($s=s_0$); $s$ bölüm sonu olmadığı sürece politikaya göre hareket ($a$) seç, hareketi yap, ödülü ($R$) ve sonraki durumu ($s'$) belirle, Q'yu güncelle, $s=s'$ yap.
  - Güncelleme kuralı: $Q[s,a] = Q[s,a] + \alpha\,(R + \gamma \max_{A} Q(s',A) - Q[s,a])$.
  - $\max Q(s',A)$: $s'$ durumunda yapılabilecek bütün hareketlerin değerlerinin maksimumu.
  - $\alpha$: öğrenme katsayısı. $\gamma \in (0,1)$: 0'a yakınsa yakın ödüllere, 1'e yakınsa gelecek ödüllere odaklanılır.
- Keşfetmek / kullanmak (exploration / exploitation) ikilemi
  - Kullanmak: $Q[s,:]$ değerlerinin en yükseğini seçmek (açgözlü seçim). Keşfetmek: rastgele bir hareket seçmek.
  - Slayttaki örnekler (ekrandan, 00:25:00): acıktınız, yeni bir yeri denemek mi, iyi bildiğiniz bir yere gitmek mi; petrol arıyorsunuz, daha önce petrol çıkmış bölgede mi, yeni bir bölgede mi çalışmak.
  - Tepe tırmanma ve simulated annealing ile bağlantı: simulated annealing'de rastgele hareket seçilir, iyiyse uygulanır, değilse azalan bir olasılıkla uygulanır; böylece yerel en iyilerden kaçılabilir.
  - Decay ε-greedy: rastgele hareket seçme olasılığı giderek azaltılır (simulated annealing'deki sıcaklık gibi).
- Labirentten çıkış örneği (ekrandan, 00:35:00)
  - Her adımda ödül −1'dir; amaç bitiş noktasına en kısa yoldan ulaşmaktır.
  - Oklar her durumda en iyi gelecek ödüle (value) sahip hareketi gösterir. Gelecek ödül tablosunda bitişe komşu hücrenin değeri −1, uzaklaştıkça −2, −3, ... diye azalır; başlangıç hücresinin değeri −16'dır.
- Q-Learning'in sınırı ve Deep Q Network
  - Q tablosu $|S| \times |A|$ boyutunda, sabit boyutlu bir matristir. Yeni durum ya da yeni hareket ortaya çıkarsa matrisin büyümesi ve güncellenmesi gerekir.
  - Q-Learning daha önce görmediği bir durumun değerini bilemez; yeni durumlara uyum sağlayamaz. Gerçek oyunlarda durum sayısı çok fazladır.
  - Çözüm: yeni durumu eldekilere benzetmek. Deep Q Network (Atari oyunları): ekran görüntüsü girdi olarak verilir, evrişimli sinir ağı (CNN) Q değerlerini tahmin eder. Tek kare yetmeyebilir; farklı zamanlardan görüntüler kullanılır. Atari örneğinde 8 yön, 8 yön + düğme ve yalnız düğme gibi 16-17 olası çıktıdan biri tahmin edilir.
- On-policy / off-policy / offline RL (ekrandan, 00:40:00)
  - Ajan $s_t$ durumunu gözler, $\pi_\theta(a|s)$ politikasını kullanıp hareket ($a$) seçer, ödül ($r$) alır, $s_{t+1}$ durumuna geçer.
  - Politika: durumu harekete dönüştüren, optimize edilecek fonksiyon. Toplanan deneyimlerin formatı $\langle s, a, s', r\rangle$; bu deneyimlerle politika eğitilir.
  - Yöntemlerin farkı deneyimlerin üretim sürecindedir (off-policy yöntemde deneyimler bir tamponda biriktirilir).
- Tartışma soruları
  - A* algoritması ortamdaki oyunlarla birleştirilebilir mi; hareket ve durumların ayrık ya da stokastik olması; çoklu ajanlar ve rekabetçi oyuncular; seyrek ödüllü oyunlarda insan taklidi ve sahte ödüller (inverse reinforcement learning); bir oyun olarak diyalog ve ChatGPT'nin temelleri.
- Kendi kendine öğrenme (self-supervised learning)
  - Öğrenme türleri derece derece sıralanır: eğiticili, kendi kendine eğiticili, yarı eğiticili, eğiticisiz.
  - Amaç: insan emeğine ek ihtiyaç duymadan eğitim kümesi (giriş-çıkış ikilileri) üretmek. Etiketli veri toplamak (örneğin tıbbi veride) zor, riskli ya da pahalı olabilir. GPT gibi modellerin en önemli bileşenlerindendir.
  - Başlıklar: otokodlayıcılar, tamamlayıcılar, parçalara odaklanan diğer yaklaşımlar, karşıtsal öğrenme, RL'de ödülü insandan almama.
- Otokodlayıcılar (autoencoder)
  - Girdi, olabilecek en az bilgiyle temsil edilecek şekilde kodlanır (encoder), sonra decoder ile girdi yeniden tahmin edilir. Ağırlıklar, çıktı girdiye çok benzeyecek şekilde ayarlanır.
  - Amaç: veriyi temsil eden bir saklı uzay (latent space) bulmak. Örnekleri: VAE, difüzyon modelleri (ekrandan, 00:50:00). Görüntü sıkıştırma ya da sınıflandırma amaçlı kullanılır.
- Tamamlayıcılar
  - Girdinin bir parçası diğer parçasından tahmin edilir: geçmişten gelecek, görünür olandan maskelenmiş olan.
  - Örnekler: cümledeki boşluğu doldurmak (birden fazla boşluk olunca zorlaşır), sonraki parçayı tahmin (GPT, Vision Transformer), bir kelimenin çevresini tahmin (Word2Vec).
- Parçalara odaklanan diğer yaklaşımlar (ekrandan, 00:55:00)
  - Bir parçayı değiştirip değişeni belirleme (ELMo, ELECTRA); parçaların yerlerini karıştırıp düzeltme (BART); sıra tahmin etme (BERT NSP/SOP); aynı cümle mi (SSP); çözünürlük artırma.
- Karşıtsal öğrenme (contrastive learning)
  - Zamanda ve mekânda birlikte olan parçaların temsilleri birbirine yaklaştırılır, birlikte olmayanlarınki uzaklaştırılır.
  - Örnek: bir köpek görüntüsünün iki farklı artırılmış (augment) parçası CNN ve çok katmanlı algılayıcıdan geçirilir; çıkan vektörler birbirini çeker. Bir koltuk görüntüsünün parçalarının vektörleri de birbirini çeker, ama köpek vektörleri ile koltuk vektörleri birbirini iter.
- RL'de ödülü insandan almama
  - Kendi kendine yarış (AlphaZero), ödülü ortamdan alma ya da başka bir modelden alma.
  - RLHF'nin aşamaları (ekrandan, 01:00:00): (1) demonstrasyon verisi toplanır, etiketleyici istenen çıktıyı gösterir, GPT-3.5 eğiticili öğrenmeyle ince ayarlanır; (2) karşılaştırma verisi toplanır, etiketleyici model çıktılarını iyiden kötüye sıralar, ödül modeli eğitilir; (3) PPO algoritmasıyla politika ödül modeline karşı optimize edilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Pekiştirmeli öğrenmede doğru çıktı söylenmez
  - Eğiticili öğrenmede "şu girdiye şu çıktı" denir; burada yalnız "şunu yaparsan şu kadar ödül, şunu yaparsan şu kadar ceza" bilgisi vardır.
- Keşfet / kullan ikilemi ve simulated annealing bağlantısı
  - Tablodaki bilgiyi hep kullanmak yerel en iyiye takılmaya yol açabilir. Rastgele hareketler başta sık, zamanla azalan sıklıkta yapılır.
- Q-Learning yeni durumlara uyum sağlayamaz
  - Sabit boyutlu Q tablosu gerçek oyunlardaki çok sayıda durum için yetersizdir; Deep Q Network bu yüzden ortaya çıktı.
- Kendi kendine öğrenme ve RLHF kaynakları
  - Hoca temel mekanizmanın ayrıntısının değil, genel yaklaşımların sorulabileceğini söyledi ve slayttaki kaynakların okunmasını tavsiye etti.

## Kısa Tekrar Notları

- Pekiştirmeli öğrenme: çıktı yok, ödül/ceza var; ajan toplam ödülü maksimize eder.
- Temel kavramlar: ortam, durum, ödül, politika, value (gelecek ödül).
- Q tablosu: durum × hareket matrisi, başta hepsi 0.
- Güncelleme: $Q[s,a] \leftarrow Q[s,a] + \alpha(R + \gamma \max_A Q(s',A) - Q[s,a])$.
- Örnek: $\alpha=0.5$, $\gamma=0.9$, $R=10$ ile $Q[3,\text{LEFT}] = 0 + 0.5(10 + 0.9 \cdot 0 - 0) = 5$; sonraki adımda $0.5 \cdot 0.9 \cdot 5 = 2.25$.
- $\gamma$ 0'a yakın: yakın ödül; 1'e yakın: gelecek ödül.
- Keşfet (rastgele) / kullan (en büyük Q); decay ε-greedy rastgelelik oranını azaltır.
- Labirent örneği: her adım −1 ödül, value bitişten uzaklaştıkça azalır.
- Q-Learning görmediği durumu bilemez; DQN Q değerlerini CNN ile tahmin eder.
- Deneyim formatı $\langle s,a,s',r\rangle$; on/off-policy ve offline RL'nin farkı deneyimlerin üretim sürecidir.
- Kendi kendine öğrenme: etiketi verinin kendisinden üretmek (otokodlayıcı, tamamlayıcı, karşıtsal öğrenme).
- RLHF: demonstrasyon verisi → ödül modeli → PPO ile politika optimizasyonu.

## Detaylı Açıklamalar

- Pekiştirmeli öğrenmede ajan bir ortamda durumdan duruma geçer. Her durumda yapabileceği belli hareketler vardır ve her hareketin sonunda ortamdan bir geri bildirim, yani ödül ya da ceza alır. Amaç, toplanan ödülü en büyük yapacak hareketler dizisini bulmaktır. Ödül çoğu zaman hemen değil, uzaktaki bir hedefe ulaşınca gelir; bu yüzden her hareketin "gelecekte ne kazandıracağı" (value) öğrenilmelidir.
- Q-Learning bu gelecek değeri bir tabloda tutar. Derste 9 durumlu örnekte 8 numaralı hedefe ulaştıran hareket 10 ödül verir. $\alpha=0.5$ ve $\gamma=0.9$ için tablo hepsi 0 iken 3. durumdan LEFT ile 8'e gidilince $Q[3,\text{LEFT}] = 0 + 0.5(10 + 0.9 \cdot 0 - 0) = 5$ olur (ekrandan, 00:20:00 ve 00:30:00). Bu değer daha sonra önceki durumlara yayılır: $t=k$ anındaki tabloda $Q[2,\text{DOWN}] = Q[2,\text{LEFT}] = 2.25$, $Q[3,\text{LEFT}] = 5$, $Q[6,\text{DOWN}] = 5$, $Q[7,\text{LEFT}] = 2.25$ görünür; $t=\infty$ tablosunda ek olarak $Q[1,\text{DOWN}] = 1.01$ ve $Q[0,\text{LEFT}] = 0.45$ vardır. $2.25 = 0.5 \cdot 0.9 \cdot 5$, $1.0125 \approx 1.01$ ve $0.5 \cdot 0.9 \cdot 1.01 \approx 0.45$ değerleri python ile doğrulandı.
  - Ders sonrası not: slayttaki $t=\infty$ tablosu her hücrenin yalnız bir kez güncellendiği hâli gösteriyor gibi duruyor. Güncelleme sonsuz kez tekrarlansaydı $Q[3,\text{LEFT}]$ büyük olasılıkla 10'a, önceki hücreler de $10\gamma^k$ biçimindeki değerlere yaklaşırdı.
- Keşfet / kullan ikilemi, tablodaki bilgiye ne kadar güvenileceği sorusudur. Hep en yüksek Q değerini seçmek açgözlü (greedy) bir yaklaşımdır ve daha iyi yolları hiç denememeye yol açabilir. Rastgele hareketler başta sık, sonra giderek seyrek yapılır (decay ε-greedy). Hoca bunu tepe tırmanmada yerel tepeye takılmamak için kötü adımı da azalan olasılıkla kabul eden simulated annealing'e benzetti.
- Labirent örneğinde her adım −1 ödül verdiği için en kısa yol en yüksek toplam ödülü verir. Gelecek ödül tablosu bitişten geriye doğru −1, −2, −3, ... diye dolar; oklar her hücrede value'su en yüksek komşuya yönelir. Yalnız ödül bilgisine bakıp yanlış yöne çeken hareketler, ödül tersinden (ceza olarak) tanımlanınca engellenir.
- Q-Learning tablo tabanlı olduğundan görmediği bir durum için bir şey söyleyemez. Deep Q Network ekran görüntüsünden Q değerlerini bir CNN ile tahmin eder; böylece yeni bir durum, benzediği bilinen durumlar üzerinden değerlendirilebilir. Hoca bu çalışmanın Nature'da yayımlandığını söyledi.
- Kendi kendine öğrenmenin ortak fikri, etiketi insan yerine verinin kendisinden üretmektir: bir parçayı gizleyip tahmin etmek, sırayı bozup düzeltmek, değiştirilmiş parçayı bulmak ya da aynı bütüne ait parçaların temsillerini yakınlaştırıp farklı bütünlerinkini uzaklaştırmak. Bu yöntemler GPT, BERT, BART gibi büyük dil modellerinin ön eğitiminin temelidir.
- RLHF'de ödül doğrudan insandan değil, insan sıralamalarıyla eğitilmiş bir ödül modelinden alınır; politika bu ödül modeline karşı PPO ile optimize edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
