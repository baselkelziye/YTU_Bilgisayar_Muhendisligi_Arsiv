# Ders 13 Çalışma Özeti

## Genel Konular

- Pekiştirmeli öğrenme (reinforcement learning, destekleyici / takviyeli öğrenme)
  - Ajan, içini bilmediği bir ortamda hareket eder; ne yapması gerektiği açıkça söylenmez, yalnız ödül ya da ceza verilir.
  - Ödül genellikle uzaktadır; ajanın amacı bir bölüm (epizod) boyunca topladığı toplam ödülü en büyük yapmaktır.
  - Döngü: ajan durumu ($S_t$) ve ödülü ($R_t$) algılar, bir hareket ($A_t$) yapar, ortam yeni durumu ve ödülü ($S_{t+1}$, $R_{t+1}$) döndürür (ekrandan, 00:20:00).
  - Oyunlar ve simülasyon dünyaları bu yöntem için çok uygundur: ödülü ortamın kendisi üretir, insan müdahalesi olmadan çok uzun süre eğitim yapılabilir, süreç kolay ölçeklenir.
- Temel kavramlar (ekrandan, 00:25:00)
  - Environment / ortam: ajanın içinde bulunduğu ortam.
  - State / durum: mevcut durum; ayrık uzayda bir indis, sürekli uzayda daha karmaşık bir veri yapısı olabilir.
  - Reward / ödül: ortamdan gelen geri besleme; pozitif ya da negatif olabilir.
  - Policy / politika: durumları hareketlere eşleyen tablo; ayrık uzayda tablo, genelde ise bir fonksiyon (örneğin yapay sinir ağı) olabilir.
  - Value / gelecek ödül: bir durumda bir hareket yapılınca ileride alınacak ödül (o anki ödül değil).
- Q-öğrenme (Q-learning) ve 9 durumlu araba örneği
  - Araba 0 durumunda, ev 8 durumunda; 4 ve 5 çukurdur. Her durumda en çok dört hareket (Up, Down, Left, Right) vardır.
  - Yalnız 8'e giden iki hareketin (3'ten Left, 6'dan Down) ödülü 10'dur; diğer ödüller 0'dır (ekrandan, 00:30:00).
  - Q tablosu: satırlar durumlar, sütunlar hareketlerdir; başta tamamen sıfırdır.
  - Güncelleme kuralı (ekrandan, 00:40:00): $Q[s,a] \leftarrow Q[s,a] + \alpha\,(R + \gamma \max_{a'} Q[s',a'] - Q[s,a])$
  - Örnek: $\alpha = 0.5$, $\gamma = 0.9$ ile $Q[3,L] = 5$, $Q[6,D] = 5$; sonra $Q[2,L] = 2.25$, $Q[2,D] = 2.25$, $Q[7,L] = 2.25$.
- Keşfetmek / kullanmak ikilemi (exploration vs. exploitation)
  - Kullanmak: şu an en iyi görünen hareketi yapmak. Keşfetmek: şu an en iyi olmayan bir hareketi denemek; yeni ve belki daha iyi durumlara ulaştırır.
  - Q-öğrenmede epsilon-açgözlü (epsilon-greedy) seçim kullanılır: rastgele hareket seçme olasılığı zamanla azaltılır (benzetimli tavlamadaki sıcaklık gibi).
- Labirent ve adım cezası
  - Yalnız bitişte ödül varsa kısa ve uzun yollar aynı toplam ödülü alır.
  - Her adıma $-1$ ödül (ceza) verilirse ajan adım sayısını kendiliğinden en aza indirir; gelecek ödül tablosu bitişe yaklaştıkça $-24$'ten $-1$'e doğru artar (ekrandan, 00:50:00).
- Yeni durumlar ve derin Q-ağı (deep Q-network)
  - Q tablosu sabit boyutludur; görülmeyen bir durumun değerini bilemez. Video oyunlarında olası durum sayısı (renkli ekran) çok büyüktür.
  - Çözüm: ekran görüntüsünü (durumu) CNN ile işleyip Q değerlerini / hareketi doğrudan üreten ağ; Atari oyunlarında insan düzeyine yakın sonuç verdi (ekrandan, 00:55:00).
- Diğer kavramlar (ekrandan, 01:15:00)
  - Çok ajanlı iş birliği / rekabet, insan taklidi (seyrek ödüllü oyunlar), ters pekiştirmeli öğrenme (sahte ödüller), politika gradyanı yöntemleri (PPO vb.), bir oyun olarak diyalog: RLHF.
- İnsan geri bildirimiyle pekiştirmeli öğrenme (RLHF)
  - Ön hazırlık: büyük dil modeli, bir sonraki token'ı tahmin eden (öz-denetimli, self-supervised) bir sinir ağıdır.
  - Adım 1: prompt veri kümesinden örnek alınır, bir insan istenen cevabı yazar, model bu çiftlerle denetimli olarak ince ayarlanır.
  - Adım 2: aynı prompt için modelin birkaç çıktısı üretilir, insan bunları en iyiden en kötüye sıralar, bu verilerle bir ödül modeli eğitilir.
  - Adım 3: yeni prompt'lar için model çıktı üretir, ödül modeli puan verir, politika PPO ile güncellenir; insan gerekmez, ölçeklenebilir. Adım 2 ve 3 yinelenir (ekrandan, 01:20:00).
- Tartışma 2023 (ekrandan, 01:40:00)
  - Bir görüş: bu modeller bilgiyi insan beyninden daha az parametreyle daha iyi temsil ediyor.
  - Karşı görüş: plan yapamayan modeller nasıl kod yazıyor? "Yüksek teknoloji kopyacılığı" (high-tech plagiarism) eleştirisi; IBM Jeopardy sistemi için de benzer beklentiler dile getirilmişti.
- Yapay zekanın etik ve hukuk ilişkileri
  - Tanımlar: etik/ahlak iyi ve kötüyü sorgular; hukuk devlet yaptırımıyla güçlendirilmiş kurallar bütünüdür; YZ karar veren bir sistemdir (ekrandan, 02:00:00).
  - Hukuki olan her zaman etik değildir; ikisi de zamana ve kültüre bağlıdır (kölelik örneği).
  - Verilerdeki önyargı: model eğitim verisindeki ayrımcılığı öğrenir; yazılı metinlerdeki olay sıklığı gerçek dünyadakinden çok farklıdır (ekrandan, 02:05:00).
  - Eş zamanlılık sebep-sonuç demek değildir (ekrandan, 02:15:00).
  - Sorumluluk, manipülasyon ve kişisel verilerin sahipliği soruları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Pekiştirmeli öğrenmede doğru hareket söylenmez
  - Sisteme yalnız yaptığının ne kadar iyi ya da kötü olduğu (ödül/ceza) bildirilir; denetimli öğrenmeden farkı budur.
- Q tablosundaki max terimi
  - Bir hareketin o an ödülü olmasa bile, varılan durumdan alınabilecek en büyük gelecek ödül o hareketin değerine katılır; ödül böylece geriye doğru yayılır.
- $\gamma$'nın rolü
  - $\gamma$ 1'e yakınsa gelecek ödüllere, 0'a yakınsa yalnız o anki ödüle odaklanılır; örnekteki $\gamma = 0.9$ geleceğe odaklıdır.
- Amaç başlangıçtan hedefe tek bir yol bulmak değildir
  - Amaç her durumda ne yapılacağını söyleyen politikayı öğrenmektir; hedefe varınca epizod biter ve yeni epizod baştan başlar.
- Keşfetmek / kullanmak ikilemi pekiştirmeli öğrenmenin temel ikilemidir
  - Günlük hayat örneği: acıkınca bilinen bir yere gitmek (kullanmak) ya da yeni bir yeri denemek (keşfetmek).
- RLHF'nin asıl kazancı ölçeklenebilirlik
  - İnsan emeği pahalıdır; insanın yaptığı sıralama işini taklit eden ödül modeli sayesinde 3. adım insan olmadan istenildiği kadar çalıştırılabilir.
- Önyargılar
  - Önyargısız karar vermek pek mümkün değildir; önemli olan zararlı önyargıların farkına varmaktır.

## Kısa Tekrar Notları

- Pekiştirmeli öğrenme: ödül/ceza ile eğitim, amaç toplam ödülü en büyük yapmak.
- Kavramlar: ortam, durum, ödül, politika, değer (gelecek ödül).
- Q-öğrenme kuralı: $Q[s,a] \leftarrow Q[s,a] + \alpha(R + \gamma \max Q[s',\cdot] - Q[s,a])$.
- $\alpha = 0.5,\ \gamma = 0.9$: $Q[3,L] = 0.5 \cdot 10 = 5$; $Q[2,L] = 0.5 \cdot 0.9 \cdot 5 = 2.25$.
- Epizod: başlangıçtan başlayıp hedefe ya da başarısızlığa (düşme, süre bitmesi) kadar süren hareket dizisi.
- Epsilon-açgözlü: başta çok keşif, zamanla daha çok kullanma.
- Kısa yol için her adıma $-1$ ödül.
- Seyrek ödül (sparse reward): ödüle ulaşılmadıkça Q tablosu hiç güncellenmez; insan taklidi yardımcı ödül sağlar.
- Ters pekiştirmeli öğrenme: ortamın vermediği ödülü dış bir model tahmin eder (sahte ödül).
- Derin Q-ağı: Q tablosu yerine CNN; giriş ekran görüntüsü, çıkış hareket sınıfları.
- RLHF: denetimli ince ayar → insan sıralamasıyla ödül modeli → PPO ile politika güncelleme; 2. ve 3. adım yinelenir.
- Öz-denetimli öğrenme: etiketleri verinin kendisi üretir (sonraki kelime, kapatılan kelime, sonraki kare).
- Etik: hukuki olan her zaman etik değildir; verideki önyargı modele geçer; eş zamanlılık nedensellik değildir.

## Detaylı Açıklamalar

**Pekiştirmeli öğrenmenin çerçevesi.** Pekiştirmeli öğrenmede bir ajan, içinin nasıl olduğunu bilmediği bir ortamda mantıklı (rasyonel) davranmaya çalışır. Ajan bir başlangıç durumundan başlar, ortamı algılar ve hareket eder; bu döngü belli bir adım sonra biten bir bölüm (epizod) oluşturur. Ortamdan gelen ödül sayısal bir değerdir, pozitif ya da negatif olabilir; "ceza" da aslında negatif bir ödüldür. Ajana bir durumda ne yapması gerektiği açıkça söylenmez, yalnız yaptığının sonucu bildirilir. İstenen, ajanın bölüm boyunca en çok ödülü toplayacak bir hareket dizisi üretmesidir. Ödülün ortamdan otomatik geldiği oyun ve simülasyon dünyalarında bu yöntem çok iyi çalışır, çünkü eğitim insan müdahalesi olmadan uzun süre ve büyük ölçekte yürütülebilir.

**Q-öğrenme örneği.** Slayttaki dünyada 0'dan 8'e kadar dokuz durum vardır. Araba 0'da, ev 8'dedir; 4 ve 5 çukurdur (ekrandan, 00:30:00). Hocanın saydığı geçişlerden bazıları: 1'den aşağı gidilince 2'ye, 2'den sağa gidilince 4'e, 3'ten sola gidilince 8'e, 6'dan aşağı gidilince 8'e varılır. Ödül yalnız 8'e varan iki harekette (3'ten Left, 6'dan Down) vardır ve 10'dur. Q tablosu 9 satır ve 4 sütundan oluşur ve başta sıfırdır; bu, her hareketin eşit seçilme şansına sahip olması gibi düşünülebilir.

Güncelleme kuralı $Q[s,a] = Q[s,a] + \alpha(R + \gamma \max_{a'} Q[s',a'] - Q[s,a])$ biçimindedir (ekrandan, 00:40:00). Örnekte $\alpha = 0.5$, $\gamma = 0.9$ seçilmiştir:

- İlk bölümler (3 durumunda Left seçildi): $Q[3,L] = 0 + 0.5 \cdot (10 + 0.9 \cdot \max[0,0,0,0] - 0) = 5$. Benzer olarak $Q[6,D] = 5$.
- Sonraki bölümler (2 durumunda Left seçildi, 6'ya varılır): $Q[2,L] = 0 + 0.5 \cdot (0 + 0.9 \cdot \max[0,5,0,0] - 0) = 2.25$. Benzer olarak $Q[2,D] = 2.25$ ve $Q[7,L] = 2.25$.

Bu hesap, o an ödül vermeyen bir hareketin bile varılan durumdaki en iyi gelecek ödülden pay aldığını gösterir. Slayttaki son tabloda ayrıca $Q[1,D] = 1.01$ ve $Q[0,L] = 0.45$ görünür (ekrandan, 00:30:00); yani 0'da Left (1'e git), 1'de Down, 2'de Down ya da Left, 3'te Left, 6'da Down, 7'de Left yapmak en mantıklıdır. 0'dan aşağı gitmek çukura (4) düşürür.

- Ders sonrası not: Bu değerler python ile doğrulandı ($0.5 \cdot 0.9 \cdot 2.25 = 1.0125$, $0.5 \cdot 0.9 \cdot 1.0125 \approx 0.456$). Slayttaki "$t=\infty$" tablosu birkaç güncelleme sonrasını gösterir; güncellemeler sürdürülürse değerler büyük olasılıkla daha da büyür (örneğin $Q[3,L]$ 10'a yaklaşır).

**Keşfetmek ve kullanmak.** Kullanmak, o an en yüksek Q değerine sahip hareketi seçmektir; hedefe daha az maliyetle ulaşmayı sağlar. Keşfetmek, şu an en iyi görünmeyen bir hareketi denemektir; yeni durumlara ve uzun vadede daha iyi sonuçlara ulaştırabilir. Hocanın örnekleri: acıkınca bilinen bir lokantaya gitmek ya da yeni bir yeri denemek; petrol ararken daha önce petrol çıkmış bölgede ya da yeni bir bölgede çalışmak (ekrandan, 00:35:00). Q-öğrenmede bu dengeyi epsilon-açgözlü seçim kurar: başta rastgele hareket olasılığı yüksektir, zamanla azaltılır. Bu, benzetimli tavlamada kötü hareketi kabul etme olasılığının sıcaklıkla birlikte azalmasına benzer.

**Labirentte kısa yol.** Yalnız bitişte ödül varsa, dolambaçlı bir epizod ile en kısa epizod aynı toplam ödülü alır; algoritma kısa yolu öncelemez. Çözüm her adımın ödülünü $-1$ yapmaktır: ajan toplam cezayı en aza indirmek için adım sayısını kendiliğinden azaltır. Slayttaki labirentte oklar her durumda en yüksek değerli hareketi, alttaki tablo da gelecek ödülleri gösterir; bitişin yanındaki hücre $-1$, en uzak hücreler $-23$, $-24$ civarındadır (ekrandan, 00:50:00).

**Yeni durumlar ve derin Q-ağı.** Q tablosu sabit boyutludur, durum sayısının baştan bilinmesini gerektirir ve görülmemiş bir durumun değerini bilemez. Video oyunlarında durum bir ekran görüntüsüdür ve olası durum sayısı çok büyüktür. DeepMind'ın Nature'da yayımlanan çalışmasında Q tablosunun işi bir sinir ağına yaptırılmıştır: ekran görüntüsü evrişim katmanlarından ve tam bağlı katmanlardan geçer, çıkışta her hareket (sekiz yön, düğmeye basarak ya da basmadan) bir sınıf gibi ele alınır (ekrandan, 00:55:00). Model oyunların büyük kısmında, belli bir eğitimden sonra insan oyuncular kadar başarılı oynamıştır.

**Seyrek ödül ve insan taklidi.** Ödül ancak arka arkaya örneğin 100 doğru hareketten sonra geliyorsa, rastgele seçimle oraya ulaşma olasılığı her adımda 4 seçenek varsa $1/4^{100}$ gibi çok küçük bir sayıdır. Ödülle karşılaşılmadıkça Q değerleri hiç güncellenmez; durum, her yönün dümdüz olduğu bir optimizasyon yüzeyine benzer. İnsan taklidi (human imitation) yaklaşımında insanlar ortamda oynar ve onların seçtiği hareketler yardımcı ödül olarak kullanılır. Ters pekiştirmeli öğrenmede ise insanın bir durumda ne yapacağını tahmin eden harici bir model, ortamın vermediği ödülü (sahte ödül, pseudo reward) üretir. Bu fikir RLHF'nin zeminidir.

**RLHF.** Dil modeli bir sonraki token'ı tahmin etmek üzere eğitilmiş bir sinir ağıdır. Bu eğitim öz-denetimlidir: çıktının ne olması gerektiği modele yine söylenir, ama eğitim kümesi insan emeği olmadan, var olan metinlerden basit bir kodla üretilir. Aynı fikir resimlerde (bir parçayı kapatıp tahmin etmek) ve videoda (sonraki kareyi tahmin etmek) da kullanılır. RLHF üç adımdan oluşur (ekrandan, 01:20:00):

- Adım 1: Prompt veri kümesinden (GPT-3 kullanıcılarının modele istedikleri çıktıyı verdirmek için denedikleri prompt'lar) bir prompt alınır; bir insan istenen cevabı yazar; bu çiftlerle GPT-3.5 denetimli olarak ince ayarlanır.
- Adım 2: Aynı prompt için modelden rastgelelik sayesinde birkaç farklı çıktı alınır; insan bunları en iyiden en kötüye sıralar; bu verilerle bir ödül modeli eğitilir.
- Adım 3: Yeni bir prompt için politika bir çıktı üretir; ödül modeli bir ödül hesaplar; politika PPO ile güncellenir. Bu adımda insan yoktur.

Daha sonra model iyileştikçe yeniden 2. adıma dönülür; yeni çıktılar yeniden sıralanır, ödül modeli yenilenir ve 3. adım tekrarlanır. Hoca, ChatGPT'nin tam yapısına dair teknik makale olmadığını, ancak önceki InstructGPT'de bu yaklaşımın kullanıldığının bilindiğini belirtti.

**Etik ve hukuk.** YZ belli bir durumda ne yapılacağına karar veren bir sistem olarak tanımlanınca doğrudan etik ve hukukun alanına girer. Hukuki olan her zaman etik değildir; ikisi de zamana ve kültüre bağlıdır (kölelik bir zamanlar hukukiydi). Model, eğitim verisindeki önyargıyı (örneğin geçmiş işe alım kararlarındaki cinsiyet ya da yaş ayrımcılığını) öğrenir. Ayrıca yazılı metinler gerçek dünyanın frekanslarını yansıtmaz: "sarı muz" ifadesi "yeşil muz"dan daha az geçer; "öldürdü" araması "yemek yedi" aramasından çok daha fazla sonuç verir (ekrandan, 02:05:00). Benzer zamanda olan şeyler sebep-sonuç ilişkisi taşımak zorunda değildir (ekrandan, 02:15:00). Otonom aracın karıştığı ölümlü bir kazada sorumluluğun kime ait olacağı, yapay zeka sistemlerinin insanların fikirlerini değiştirmek için kullanılabilmesi (manipülasyon) ve kişisel verilerin kimlerle paylaşılacağı da önümüzdeki hukuki ve etik sorulardır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
