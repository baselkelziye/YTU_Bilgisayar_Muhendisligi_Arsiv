# Ders 8 Çalışma Özeti

## Genel Konular

- Yarı rastgele altuzaylar (Semi-Random Subspace)
  - Klasik rastgele altuzay (Random Subspace) yönteminde $N$ örnek ve $d$ özellikli veriden her tekil öğrenici için $d/x$ özellik rastgele seçilir; her öğrenicinin eğitim kümesi $N \times d/x$ boyutundadır. Uygulamada $d/2$ yaygın ve deneysel olarak iyi çalışan bir seçimdir, ama zorunlu değildir (ekrandan, 00:10:00).
  - $x$ büyükse (az özellik) tekil öğrenici başarısı düşer, çeşitlilik (diversity) artar; $x$ küçükse tekil başarı artar, çeşitlilik azalır (ekrandan, 00:15:00). Klasik yöntemde biri kazanılırken diğeri kaybedilir.
  - Yarı rastgele yöntemde öğreniciler çiftler hâlinde üretilir: birincisi özellikleri rastgele seçer, ikincisi geri kalan özellikleri alır. Örneğin 4 özellikte "1 3" seçilirse eşi "2 4" olur; "1 2" seçilirse eşi "3 4" olur (ekrandan, 00:15:00). 9 özellik ve üçlü seçimde "1 4 6" seçildikten sonra kalan 6 özellikten rastgele 3'ü, sonra kalan 3'ü alınır (ekrandan, 00:20:00).
  - Böylece her öğrenici yine aynı sayıda özellik kullanır (tekil başarı sabit kalır), ama eş öğreniciler ortak özellik içermediği için kararları farklılaşır ve topluluğun başarısı artar.
- Karar benzerliği matrisi ve topluluk büyüklüğünün etkisi
  - Tekil öğrenicilerin kararlarının ikili benzerlikleri simetrik bir matris oluşturur; köşegen 1'dir, yalnız üst üçgen önemlidir. Topluluğun çeşitliliği bu üst üçgendeki değerlerin ortalamasıyla düşünülebilir.
  - 4 öğrenicide 6 değerin 2'si, 6 öğrenicide 15 değerin 3'ü azaltılır (ekrandan, 00:25:00 ve 00:30:00): yaklaşık %33'ten %20'ye. Topluluk büyüdükçe (ör. 100 öğrenici) azaltılan oran çok küçülür; yöntemin kazancı topluluk büyüklüğüyle ters orantılıdır.
- Teorik ve deneysel çalışma
  - Bu çıkarımlar hiç deney yapılmadan, mantıkla elde edildi; deneyde de aynı bulgular (daha başarılı topluluk, topluluk büyüdükçe azalan fark) gözlenmişti.
  - Teori deneyle uyuşmazsa: deney yanlış yapılmış olabilir, teori yanlış kurulmuş olabilir ya da teorinin varsayımları kullanılan veri kümelerine uymuyor olabilir.
  - Varsayım bir kısıttır. Varsayımları genelleştirmek teoriyi daha çok duruma uygulanabilir kılar; daraltmak ise yöntemin hangi koşullarda iyi çalıştığını açıkça tarif eder.
- Yerel modellerin birleşimi (Mixture of Experts)
  - Her öğrenici veri uzayının farklı bir bölgesinde uzmanlaşır. Çıkış $y = \sum_{j=1}^{L} w_j d_j$ biçimindedir; ağırlıkları test örneğine göre bir geçit (gating) fonksiyonu üretir. Test örneğinin gating'e de verilmesinin sebebi örneğin uzayın hangi bölgesinde olduğunu bulmaktır. Öğreniciler ve gating doğrusal ya da doğrusal olmayan olabilir (ekrandan, 00:45:00).
  - Bütün $w_j = 1/L$ ise demokrasidir; bölgesel uzmanlaşmada demokrasi anlamsızdır. Tek bir $w_j=1$ ise yalnız o uzmana bakılır (1-NN'in Voronoi bölgelerine benzer); komşu uzmanların da etkisi istenirse yumuşak ağırlıklar (3-NN benzeri) kullanılır.
- İki aşamalı öğrenme (Stacking)
  - Tekil öğrenicilerin çıkışları yeni bir veri kümesi (meta eğitim kümesi) olarak görülür. İkinci aşamada bu kararların nasıl birleştirileceği öğrenilir.
  - Meta eğitim kümesi orijinal kümeyle aynı sayıda örnek içerir; özellik sayısı (sınıflandırıcı sayısı) $\times$ (sınıf sayısı) kadardır, çünkü her sınıflandırıcı her sınıf için bir olasılık verir (ekrandan, 00:55:00). Çıkış orijinal sınıf olabilir ya da her sınıf için "a sınıfı mı?" biçiminde ayrı ikili problemler kurulabilir.
  - İkinci aşamada da bir topluluk yöntemi (ör. Random Forest) kullanılabilir.
- Sorular: paralelleştirme ve Rotasyon Ormanı (ekrandan, 01:00:00)
  - Bagging, rastgele altuzaylar, Random Forest ve Rotation Forest'ta tekil öğreniciler birbirinden bağımsızdır ve paralel eğitilebilir. Boosting'de her öğrenici bir öncekinin hatasına göre eğitildiği için paralel eğitilemez.
  - Rotasyon Ormanında KNN işe yaramaz: döndürme noktalar arası uzaklıkları değiştirmez, kararlar aynı kalır. Karar ağacı ise eksenlere dik sınırlar çizdiği için döndürmeye duyarlıdır.
- Model kararlarının birleştirilmesi kuralları (ekrandan, 01:25:00)
  - Product, Sum, Mean, Max, Median, Minimum, Weighted Average, Majority Voting, Weighted Majority Voting ve Borda Count kuralları 5 sınıflandırıcılı, 3 sınıflı bir örnekle gösterildi.
  - Olasılık tabanlı kurallar sınıflandırıcının sınıf olasılıkları vermesini gerektirir: 1-NN vermez, 10-NN komşuların sınıf dağılımıyla verir, karar ağacı yaprağın (saf ise bir üst düğümün) eğitim örneklerinin sınıf dağılımıyla verir, YSA sınıf sayısı kadar çıkış ve normalize etme (softmax) ile verir.
- Bir deney: budama ve ağırlıklandırma (ekrandan, 01:30:00 ve 01:35:00)
  - 26 UCI veri kümesi, 5x2 çapraz doğrulama, her yöntemde 100 ağaç. Validasyon kümesinde en başarısızları budamak (100'den 75, 50, 25 ağaç bırakmak) ve kararları validasyon başarısına göre ağırlıklandırmak denendi; Nemenyi testine göre anlamlı fark 4.522.
  - Bütün topluluklar tek ağaçtan (CART, 14.9231) iyidir. İyiden kötüye: Random Forest (5.6154), rastgele altuzay (6.0000), Bagging (9.1538).
  - Budama üç yöntemde de hep kötüleştirdi: ortalama tekil başarı artar ama çeşitlilik azalır.
  - Ağırlıklandırma yalnız rastgele altuzayda iyileştirdi (5.5385); Bagging'de fark çok küçük, Random Forest'ta kötüleştirdi.
- Algoritmaların karşılaştırılması (ekrandan, 01:45:00 ve 01:50:00)
  - 36 UCI veri kümesinde 11 tekil ve 12 topluluk algoritması (topluluklarda 100 temel öğrenici). En iyi ortalama sıra Rotation Forest (4.1304) ve Random Forest (5.3913); en yüksek "yenme eksi yenilme" sayısı Rotation Forest (289). Tekillerde SVM (SMO) ve LADT iyi.
  - Hız: letter verisinde J48 1.84 s, 100 ağaçlı Random Forest 25.94 s eğitim süresine sahip. Random Forest her düğümde az özelliğe baktığı için hızlıdır. Weka'daki Rotation Forest çok yavaş çıktı; hoca bunu algoritmaya değil gerçeklemeye bağladı.
  - Doğruluk birinci ölçütse Rotation Forest, doğruluk ve hız birlikte önemliyse Random Forest mantıklıdır.
- Algoritmaların ve veri kümelerinin benzerliği
  - Algoritma $\times$ veri kümesi performans matrisi satırlara göre hiyerarşik kümelenince topluluk algoritmaları bir grupta, tekil ağaçlar başka bir grupta toplanır: benzer fikirler benzer performans verir.
  - Matris çevrilip veri kümeleri kümelenince veri kümeleri kabaca sınıf sayılarına göre (iki sınıflı ve daha fazla sınıflı) gruplanır; primary-tumor ve abalone zor problemler olarak ayrı kalır (ekrandan, 01:55:00).
- Kolektif regresyon ağaçları
  - Regresyon ağacı yapraklarda düşen örneklerin ortalamasını verir; derinlik arttıkça eğitim örneklerine daha çok uyar. 1 ağaç basamaklı bir çıkış, 300 ağaçlı topluluk daha yumuşak bir eğri üretir (ekrandan, 02:00:00). Regresyonda birleştirme kolaydır: çıkışların ortalaması alınır.
- Kolektif kümeleme
  - Temel kümeleyiciler farklı algoritmalar ya da farklı özellik altkümeleriyle aynı algoritma olabilir; örnek altkümesi kullanılamaz (ekrandan, 02:05:00).
  - K-means ve yoğunluk tabanlı DBSCAN örnek olarak anıldı. DBSCAN iç içe halka gibi yapıları ayırabilir, küme sayısı doğrudan verilemez, yakınlık toleransı hiperparametresiyle dolaylı belirlenir.
  - Sorun: küme sayıları ve küme etiketleri öğreniciden öğreniciye farklıdır, etiketler arasında tutarlılık yoktur. Çözüm: iki örneğin kaç sonuçta aynı kümede bulunduğunu sayan bir benzerlik matrisi $d$ kurup üzerinde hiyerarşik kümeleme yapmak (ekrandan, 02:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Topluluğun başarısı tekil öğrenici başarısına ve çeşitliliğe bağlıdır
  - Klasik yöntemlerde biri artarken diğeri azalır. Yarı rastgele altuzay tekil başarıya dokunmadan çeşitliliği artırdığı için kazanç sağlar.
- Teorik çalışmanın değeri
  - Hocaya göre işin seyrini değiştiren çalışmalar teorik çalışmalardır; teorik çalışan insan sayısı deneysel çalışanlardan çok daha azdır, çünkü deney yapmak daha kolaydır.
- Bütün algoritmalar birer varsayımdır
  - Teori ile deney uyuşmazlığının bir sebebi varsayımların veriye uymamasıdır; bu teorinin yanlışlığı değil, kısıtlılığıdır.
- Birinci elden gözlem
  - Bir sunumda birinin söylemiş olması (ör. en başarılı ağaçları seçmenin iyi olduğu) bir şeyi doğru kabul etmeye yetmez; kendiniz deneyip görmek öğrenmenin en iyi yollarındandır.
- Budama işe yaramaz
  - Herkesin aynı şeyi söylediği ortamda aslında tek bir kişi vardır; budama çeşitliliği azalttığı için topluluğu kötüleştirir.

## Kısa Tekrar Notları

- Rastgele altuzay: her öğrenici $d/x$ özellikle eğitilir; $x$ büyük → tekil başarı düşer, çeşitlilik artar.
- Yarı rastgele altuzay: rastgele seç, eşine kalanları ver; tekil başarı aynı, çeşitlilik artar, kazanç topluluk büyüdükçe azalır.
- 4 öğrenicide 6 benzerlik değerinden 2'si, 6 öğrenicide 15 değerden 3'ü azalır.
- Uzman karışımı: $y=\sum w_j d_j$, ağırlıklar gating fonksiyonundan; demokrasi bölgesel uzmanlıkta anlamsız.
- Stacking: meta eğitim kümesi = aynı örnek sayısı, (sınıflandırıcı sayısı × sınıf sayısı) özellik.
- Boosting paralel eğitilemez; Bagging, RS, RF, RotF paralel eğitilebilir.
- Rotasyon Ormanında KNN anlamsız, karar ağacı döndürmeye duyarlı.
- Olasılık tabanlı birleştirme için sınıf olasılığı gerekir: 1-NN vermez, k-NN, karar ağacı ve softmax'lı YSA verir.
- Budama hep kötüleştirdi; ağırlıklandırma yalnız kararları en farklı olan rastgele altuzayda işe yaradı.
- Rotation Forest en doğru, Random Forest doğruluk-hız dengesinde en iyi.
- Kolektif kümelemede etiket tutarsızlığı birlikte bulunma sayısı matrisi ve hiyerarşik kümeleme ile aşılır.

## Detaylı Açıklamalar

- Yarı rastgele altuzayın mantığı
  - İki öğrenicinin kararlarının benzer olma ihtimali, özellik altkümelerindeki ortak özellik sayısıyla ilişkilidir. Rastgele seçimde iki altküme genellikle bazı özellikleri paylaşır. Yarı rastgele yöntemde eş öğrenicilerin altkümeleri ayrıktır, ortak eleman içermez; bu yüzden kararları farklılaşır.
  - Karar benzerliği matrisinde yalnız eşler arasındaki değerler (1-2, 3-4, 5-6, ...) azalır; diğer çiftler yine rastgele seçimden geldiği için değişmez. 4 öğrenicide 6 değerin 2'si, 6 öğrenicide 15 değerin 3'ü değişir. Öğrenici sayısı arttıkça değişen oran küçülür ve kazanç azalır.
  - Özellik sayısı tam bölünmüyorsa (ör. 5 özellikten 3'er seçim) geri kalan 2 özellik eşe konur, eksik kalan rastgele seçilir; yine de rastgele seçime göre çeşitlilik artar.
- Teori ve deney ilişkisi
  - Deney yapmadan, düz bir mantıkla varılan bir sonucun deneyde de gözlenmesi beklenir. Uyuşmazlık varsa önce deney tekrarlanır; sonra teorinin kendisi ya da varsayımlarının veriyle uyumu sorgulanır. Teorinin yazılı olmayan, örtük varsayımlarını ortaya çıkarıp onlardan kurtulmak da teoriyi geliştirmenin yoludur.
- Model kararlarını birleştirme kuralları (ekrandan, 01:25:00)
  - Sınıflandırıcı ağırlıkları 0.30, 0.25, 0.20, 0.10, 0.15; sınıf olasılıkları sırasıyla (0.85, 0.01, 0.14), (0.3, 0.5, 0.2), (0.2, 0.6, 0.2), (0.1, 0.7, 0.2), (0.1, 0.1, 0.8).
  - Sum: C1 1.55, C2 1.91, C3 1.54. Mean: 0.310, 0.382, 0.308. Max: 0.85, 0.7, 0.8. Median: 0.2, 0.5, 0.2. Minimum: 0.1, 0.01, 0.14. Weighted Average: 0.395, 0.333, 0.272. Majority Voting: 1, 3, 1 oy. Weighted Majority Voting: 0.3, 0.55, 0.15 (python ile doğrulandı).
  - Product kuralında slayt C1 için 0.0179 verir. Ders sonrası not: hoca da C1'i $0.85 \times 0.3 \times 0.2 \times 0.1 \times 0.1$ diye açıkladı; bu çarpım 0.00051'dir (python ile doğrulandı). Doğru değerlerle Product kuralı C3'ü (0.000896) seçer, C1'i değil.
  - Kurallar arasında birinin genel olarak çok daha iyi olduğunu söylemek kolay değildir; sonuç kurala göre değişir.
- Deney sonuçlarının yorumu
  - Bagging'in her düğümü bütün özelliklere, Random Forest'ın her düğümü az sayıda rastgele özelliğe (ağacın tamamında ise hepsine erişme ihtimali var), rastgele altuzayın her ağacı yalnız $d/2$ özelliğe erişir. Bu yüzden kararları en farklı olan topluluk rastgele altuzaydır.
  - Kararlar birbirine yakınsa ağırlıklar da birbirine yakın çıkar ve ağırlıklandırma demokrasiden farksız olur (Bagging). Kararların en farklı olduğu rastgele altuzayda ağırlıklandırma işe yaradı.
- Kolektif kümeleme örneği
  - 7 örnek ve 3 kümeleme sonucu: A = {1,2,3}{4,5}{6,7}; B = {1,2}{3,4}{5,6,7}; C = {1,2}{3,4,5}{6,7}. 1 ile 2 ve 6 ile 7 üç sonuçta da aynı kümededir; 3 ile 4 iki sonuçta aynı kümededir. Bu sayılar örnekler arası benzerlik matrisini oluşturur.
  - Hiyerarşik kümeleme örneklerin koordinatlarına değil, yalnız ikili uzaklıklarına ihtiyaç duyar. Bu yüzden benzerlik matrisi üzerinden istenen sayıda kümeye inilebilir ve farklı kümeleyicilerin sonuçları birleştirilmiş olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
