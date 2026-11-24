# Ders 6 Çalışma Özeti

## Genel Konular

- Naive Bayes'te normalizasyon gerekli mi?
  - Naive Bayes istatistiksel (olasılığa dayalı) bir yöntemdir, uzaklık tabanlı değildir. Bu yüzden normalizasyon şart değildir.
  - k-en yakın komşu (k-NN) ve k-means gibi uzaklık tabanlı yöntemlerde ise normalizasyon olmazsa olmazdır.
  - Sayısal öz nitelikler için olasılık normal dağılımla hesaplanır. Kategorik bir değeri temsil eden sayısal kodu sayısal öz nitelik gibi işlemek yanlış bir modelleme olur; kategorik öz nitelikler sayarak (frekansla) değerlendirilmelidir.
- Sınıflandırma modeli kurmanın genel yaklaşımı
  - Etiketli bir eğitim kümesinden öğrenme algoritmasıyla model öğrenilir (tümevarım, induction).
  - Öğrenilen model, sınıfı bilinmeyen test kümesine uygulanır (tümdengelim, deduction) (ekrandan, 00:30:00).
  - Test kümesinin gerçek sınıf etiketleri (ground truth) bilindiği için modelin başarısı ölçülebilir.
- Karar ağacının yapısı
  - Karar ağacı gözetimli (supervised) bir sınıflandırma algoritmasıdır, sınıf etiketli eğitim örneklerine ihtiyaç duyar.
  - Akış şemasına benzer: iç düğümler öz nitelik testleridir, dallar testin sonuçlarıdır, yaprak düğümler sınıf etiketleridir.
  - En üstteki düğüme kök düğüm (root node) denir.
- Kısmi karar ağacı örnekleri (kredi kartı promosyon veri seti)
  - Çıktı değişkeni "Life Insurance Promotion" (hayat sigortası promosyonu), diğer sütunlar girdi öz nitelikleridir (ekrandan, 00:35:00).
  - Kök "Income Range" seçilince dallar: 20-30K (2 Yes, 2 No), 30-40K (4 Yes, 1 No), 40-50K (1 Yes, 3 No), 50-60K (2 Yes).
  - Kök "Credit Card Insurance" seçilince "No" dalında örneklerin yarısı Yes, yarısı No olur; çoğunluk olmadığı için sınıf etiketi seçmek zordur.
  - Kök "Age" ve bölme noktası 43 seçilince: $\le 43$ dalında 9 Yes, 3 No; $> 43$ dalında 0 Yes, 3 No (ekrandan, 00:50:00).
  - Yaprağa çoğunluk sınıfının etiketi konur; azınlıktaki örnekler yanlış sınıflanmış olur. Amaç saflığı (purity) yüksek alt kümeler elde etmektir.
- Bölme senaryoları (ekrandan, 00:55:00)
  - Ayrık değerli öz nitelik: her farklı değer için bir dal (örneğin beş renk varsa beş dal).
  - Sürekli değerli öz nitelik: bir bölme noktası seçilir, iki dal oluşur ($A \le$ split_point solda, $A >$ split_point sağda).
  - Ayrık değerli ve ikili ağaç isteniyorsa: $A \in S_A$ testiyle "evet/hayır" iki dal.
- Karar ağacı algoritmaları ve genel akış
  - İlk algoritma ID3'tür; ardından C4.5 gelir. C4.5 yeni gözetimli öğrenme algoritmaları için karşılaştırma ölçütü (benchmark) olarak kullanılır. <!-- BELİRSİZ: ID3/C4.5 tarihçesi ve diğer algoritmalar slaytta anlatılmış, altyazı bu bölümde bozuk, slayt karesi yok. -->
  - Adımlar: örnekleri en iyi ayıran öz nitelik seçilir, kök/test düğümü yapılır, veri bu öz niteliğin değerlerine göre alt kümelere bölünür, her alt küme için işlem özyinelemeli tekrarlanır. Kullanılacak öz nitelik kalmayınca ya da alt küme saf olunca durulur. <!-- BELİRSİZ: algoritma adımlarının slayttaki tam metni karelerde yok; adımlar altyazıdan kuruldu. -->
- Entropi, bilgi kazancı (ekrandan, 01:00:00)
  - $p_i = |C_{i,D}| / |D|$
  - $Info(D) = -\sum_{i=1}^{m} p_i \log_2 p_i$
  - $Info_A(D) = \sum_{j=1}^{v} \dfrac{|D_j|}{|D|} \times I(D_j)$
  - $Gain(A) = Info(D) - Info_A(D)$; en büyük kazancı veren öz nitelik kök düğüm olur.
- Çözümlü örnek: bilgisayar satın alma (buys_computer) veri seti
  - 14 örnek, 4 kategorik öz nitelik (age, income, student, credit_rating); 9 pozitif (Yes), 5 negatif (No).
  - $Info(D) = I(9,5) = 0.940$, $Info_{age}(D) = 0.694$, $Gain(age) = 0.246$, $Gain(income) = 0.029$.
  - Kök: age. 31-40 dalı tamamen pozitif; $\le 30$ dalında student, $> 40$ dalında credit_rating öz niteliği sınıfları tam ayırır.
- Pozitif sınıf seçimi
  - İlgilenilen ve incelenmek istenen grup pozitif sınıf yapılır: bilgisayar alan müşteriler, churn analizinde şirketi terk eden müşteriler, hastalık tanısında hasta olanlar.
- İkiden fazla sınıf: hafta sonu örneği
  - 10 hafta sonu, öz nitelikler hava (weather), ebeveyn (parents), para (money); sınıflar sinema, tenis, evde kalma, alışveriş.
  - Veri setinin entropisi 1.571 bit; dört sınıfta en büyük entropi 2 bittir.
  - Kazançlar: weather 0.70, parents 0.61, money 0.2816; kök weather olur (ekrandan, 02:30:00).
- Sayısal öz nitelik için bölme noktası seçimi (ekrandan, 02:35:00)
  - Değerler sıralanır, sınıf etiketleri yanına yazılır; en büyük değer dışındaki farklı değerler aday bölme noktasıdır.
  - Bölme noktası 80 için $Info_{A2}(T) = 0.837$, $Gain(A2) = 0.103$ bit.
  - Her aday için kazanç hesaplanır, en büyüğü seçilir.
- Model aşırı öğrenmesi (overfitting)
  - Eğitim hatası, test hatası ve genelleme hatası kavramları.
  - İki boyutlu iki sınıflı örnek veride düğüm sayısı arttıkça eğitim hatası sürekli düşer, test hatası belli bir noktadan sonra artar.
  - Yetersiz öğrenme (underfitting): model çok basit, eğitim ve test hataları büyük. Aşırı öğrenme (overfitting): model çok karmaşık, eğitim hatası küçük ama test hatası büyük (ekrandan, 03:00:00).
  - Çözümler: daha basit model seçmek, eğitim verisini artırmak, doğrulama (validation) kümesi kullanmak, model karmaşıklığını cezalandıran genelleme hatası kestirimi.
  - Kötümser hata kestirimi: $err_{gen}(T) = err(T) + \Omega \times \dfrac{k}{N_{train}}$ (ekrandan, 03:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Normalizasyon uzaklık tabanlı yöntemlerde zorunludur
  - k-NN ve k-means'te mutlaka yapılmalıdır; Naive Bayes'te gerekmez çünkü yöntem uzaklığa değil olasılığa dayanır.
- Sürekli öz nitelikte "küçük eşit" sol dala gider
  - Standart kullanım: bölme değerine eşit ve küçük olanlar sol tarafa, büyük olanlar sağ tarafa yazılır.
- Eşit dağılımlı iki sınıfın entropisi 1'dir
  - Örnekler sınıflara eşit dağılmışsa bu "düzensiz (disordered) konfigürasyon"dur ve entropi en büyük değerini alır: iki sınıfta 1 bit.
  - Dört sınıfta en büyük entropi 2 bittir. Hesapta bundan büyük bir değer çıkarsa hesap hatası vardır.
- Sınavda her aday bölme noktası için kazanç hesaplanamaz
  - Sıralı veriye bakıp saf alt kümeler üreten mantıklı bir aday seçilmelidir. Örneğin 65'ten bölmek solda tek örnek bırakır, 70'ten bölmek sağda büyük bir karışıklık bırakır; bu iyi seçimler değildir. Karar verilemiyorsa her aday için kazanç hesaplanır.
- Pozitif sınıf gelişigüzel seçilmez
  - İlgi alanınız ve incelemek istediğiniz grup hangisiyse pozitif sınıf o olmalıdır.
- Genelleme hatasının nasıl hesaplandığını öğrenin
  - Hoca dersin sonunda bunun öğrenilmesini özellikle istedi.

## Kısa Tekrar Notları

- Karar ağacı: iç düğüm = öz nitelik testi, dal = test sonucu, yaprak = sınıf etiketi, en üstteki düğüm = kök.
- Yaprak etiketi çoğunluk sınıfıdır; azınlık örnekleri yanlış sınıflanmış sayılır.
- İki sınıf için $Info = -(p_+ \log_2 p_+ + p_- \log_2 p_-)$; birim bit.
- $Gain(A) = Info(D) - Info_A(D)$, en büyük kazanç kök olur.
- buys_computer: $Info(D)=0.940$, $Gain(age)=0.246$, $Gain(income)=0.029$; kök age.
- Saf alt kümede ($I(4,0)$) entropi 0, eşit dağılımda ($I(2,2)$) entropi 1.
- Sürekli öz nitelik: sırala, aday bölme noktalarını dene, en büyük kazancı veren noktayı seç.
- $m$ sınıf için entropi en çok $\log_2 m$ (4 sınıf için 2 bit).
- Aşırı öğrenme: karmaşık model, küçük eğitim hatası, büyük test hatası. Yetersiz öğrenme: her iki hata da büyük.
- Aşırı öğrenmeye karşı: basit model, daha çok eğitim verisi, doğrulama kümesi, karmaşıklık cezası.
- $err_{gen}(T) = err(T) + \Omega \cdot k / N_{train}$; $k$ yaprak sayısı, $\Omega$ yaprak eklemenin göreli maliyeti.

## Detaylı Açıklamalar

- **Sınıflandırma modelinin kurulması.** Gözetimli sınıflandırmada veri eğitim ve test kümelerine ayrılır. Eğitim kümesindeki etiketli örneklerden bir öğrenme algoritması modeli öğrenir; bu tümevarımsal (induction) adımdır. Sonra model test kümesine uygulanarak sınıflar tahmin edilir; bu da tümdengelimsel (deduction) adımdır. Test kümesinde de gerçek sınıf etiketleri bulunduğundan tahminler bunlarla karşılaştırılıp modelin başarısı ölçülür.

- **Kök düğüm seçiminin sezgisi.** Kredi kartı promosyonu veri setinde gelir aralığı kök yapıldığında 20-30K dalında 2 Yes, 2 No vardır; bu dalda çoğunluk yoktur. 30-40K dalında 4 Yes, 1 No vardır; yaprak "Yes" olursa bir örnek yanlış sınıflanır. 40-50K dalında 1 Yes, 3 No vardır; yaprak "No" olur. 50-60K dalındaki iki örneğin ikisi de Yes'tir, hata yoktur. Yaş öz niteliği 43'ten bölündüğünde sol dalda 9 Yes, 3 No, sağ dalda yalnız 3 No vardır; sağ dal tamamen saftır. Hangi öz niteliğin daha iyi ayırdığını sayısal olarak ölçmek için entropi kullanılır.

- **Bilgi kazancının hesaplanması.** Önce bütün veri setinin entropisi $Info(D)$ hesaplanır. Sonra her öz nitelik $A$ için veri $A$'nın $v$ farklı değerine göre $D_1, \dots, D_v$ alt kümelerine bölünür. Her alt kümenin ağırlığı $|D_j|/|D|$, yani o dala düşme olasılığıdır; bu ağırlık alt kümenin entropisi $I(D_j)$ ile çarpılır ve dallar boyunca toplanır. Sonuç $Info_A(D)$'dir. Kazanç, bölmeden önceki ve sonraki entropinin farkıdır. İşlem her öz nitelik için tekrarlanır ve en büyük kazancı veren öz nitelik köke yerleştirilir. Ardından her dalın alt kümesi için aynı işlem kalan öz niteliklerle yürütülür.

- **buys_computer örneği.** 14 örneğin 9'u pozitif, 5'i negatiftir:
  $Info(D) = -\left(\frac{9}{14}\log_2\frac{9}{14} + \frac{5}{14}\log_2\frac{5}{14}\right) = 0.940$ (ekrandan, 02:05:00).
  Yaş dalları: $\le 30$ (2 Yes, 3 No), 31-40 (4 Yes, 0 No), $>40$ (3 Yes, 2 No) (ekrandan, 01:30:00).
  $Info_{age}(D) = \frac{5}{14} I(2,3) + \frac{4}{14} I(4,0) + \frac{5}{14} I(3,2) = 0.694$, $Gain(age) = 0.940 - 0.694 = 0.246$ (ekrandan, 02:20:00).
  Gelir dalları: low (3 Yes, 1 No), medium (4 Yes, 2 No), high (2 Yes, 2 No) (ekrandan, 01:45:00). $Info_{income}(D) = \frac{4}{14}I(3,1) + \frac{6}{14}I(4,2) + \frac{4}{14}I(2,2)$ ve $Gain(income) = 0.029$.
  En büyük kazanç yaşta olduğu için kök yaştır. 31-40 dalı tamamen pozitiftir ve yaprak olur. $\le 30$ dalında öğrenci olanların hepsi Yes, olmayanların hepsi No'dur; bu dala "student" testi gelir. $>40$ dalında kredi notu "fair" olanlar Yes, "excellent" olanlar No'dur; bu dala "credit_rating" testi gelir (ekrandan, 02:00:00). Hoca ağacın dallarına o daldaki örnek sayısının da yazılmasını önerdi (örneğin credit_rating = fair dalında 3 örnek).

- **İkiden fazla sınıf.** Hafta sonu örneğinde dört sınıf vardır. Entropi formülü aynıdır, yalnız toplam dört terimden oluşur. Bilgi kuramı açısından dört sınıfı sabit uzunluklu kodla göstermek için 2 bit gerekir; bu yüzden en büyük entropi 2'dir. Örnekte veri setinin entropisi 1.571 bittir. Kazançlar weather için 0.70, parents için 0.61, money için 0.2816'dır; kök weather olur ve sunny dalında sonraki test düğümü parents olur.

- **Sayısal öz nitelik.** Örnekte 14 örnek (9 C1, 5 C2), iki kategorik öz nitelik (A1 ve A3) ve bir sayısal öz nitelik (A2, yaş) vardır. A1'in kazancı 0.246, A3'ün kazancı 0.048'dir. A2'nin değerleri sıralanır: 65, 70, 70, 70, 75, 78, 80, 80, 80, 85, 90, 90, 95, 96. En büyük değer (96) bölme noktası olamaz, çünkü sağ dal boş kalır. Adaylar {65, 70, 75, 78, 80, 85, 90, 95}'tir. Bölme noktası 80 için sol dalda 9 örnek (7 C1, 2 C2), sağ dalda 5 örnek (2 C1, 3 C2) vardır; $Info_{A2}(T) = 0.837$ ve $Gain(A2) = 0.940 - 0.837 = 0.103$ bit bulunur (ekrandan, 02:35:00). Bu kazanç diğer öz niteliklerinkiyle karşılaştırılınca en büyük kazanç A1'de olduğu için kök A1 olur.

- **Aşırı öğrenme.** Örnekte "+" sınıfının 5200 örneğinden 5000'i (10,10) merkezli Gauss dağılımından üretilmiş, 200 gürültülü örnek eklenmiştir; "o" sınıfının 5200 örneği 0-20 aralığında düzgün dağılımdan üretilmiştir. Verinin %10'u eğitim, %90'ı test için kullanılır (ekrandan, 02:50:00). Düğüm sayısı arttıkça eğitim hatası önce hızla, sonra yavaşça düşer. 4 düğümlü ağaç merkezdeki "+" bölgesini dikdörtgen sınırlarla ayırır (ekrandan, 02:55:00). Düğüm sayısı çok artırılınca ağaç gürültülü örnekler için de küçük bölgeler oluşturur; eğitim hatası sıfıra yaklaşır ama test hatası yükselir. Bu aşırı öğrenmedir. Eğitim verisi iki katına çıkarıldığında eğitim ve test hataları birbirine yaklaşır.

- **Genelleme hatasının kestirimi.** Veri eğitim, doğrulama ve test olarak üçe ayrılabilir; doğrulama kümesi genelleme hatasını kestirmek için kullanılır. Sakıncası, az veri varken eğitime daha az veri kalmasıdır. Diğer yol karmaşıklık cezasıdır: $err_{gen}(T) = err(T) + \Omega \times k/N_{train}$. Örnekte $T_L$ 7 yapraklı ve 4 hatalı, $T_R$ 4 yapraklı ve 6 hatalıdır, $N_{train} = 24$, $\Omega = 1$: $e_{gen}(T_L) = 4/24 + 7/24 = 11/24 = 0.458$, $e_{gen}(T_R) = 6/24 + 4/24 = 10/24 = 0.417$ (ekrandan, 03:10:00). Eğitim hatası daha büyük olmasına rağmen genelleme hatası küçük olan, daha basit $T_R$ tercih edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
