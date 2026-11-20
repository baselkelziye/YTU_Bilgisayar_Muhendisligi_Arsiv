# Ders 8 Çalışma Özeti

## Genel Konular

- Kural tabanlı sınıflandırma (rule-based classification)
  - Kural, "IF koşul THEN sınıf" biçiminde bir yapıdır. IF'ten sonraki kısma koşul (condition, antecedent), THEN'den sonraki kısma sonuç (consequent) denir.
  - Koşul kısmında öznitelik testleri (eşittir, küçüktür, büyüktür gibi) AND ile bağlanır; sonuç kısmında yalnız sınıf etiketi bulunur.
  - Örnekler: yaş ve öğrenci olma koşullarına bağlı bir "THEN buys_computer = yes" kuralı; "IF sıcak kanlı AND yumurtluyor THEN sınıf = kuş".
    <!-- BELİRSİZ: buys_computer kuralındaki yaş koşulunun değeri altyazıda anlaşılmıyor, bu slayt karelerde yok. -->
- Kuralın kapsaması (coverage) ve doğruluğu (accuracy) (ekrandan, 00:07:06)
  - $n_{covers}$: kuralın koşulunu sağlayan kayıt sayısı; $n_{correct}$: bunlardan sınıfı da doğru olan kayıt sayısı; $|D|$: eğitim kümesindeki kayıt sayısı.
  - $\text{coverage}(R) = n_{covers}/|D|$: verinin yüzde kaçı kuralın koşuluna uyuyor (sınıfa bakılmaz).
  - $\text{accuracy}(R) = n_{correct}/n_{covers}$: koşula uyanların yüzde kaçı doğru sınıflanıyor.
  - Bazı kaynaklarda coverage yerine support terimi kullanılır.
  - Derste sözlü örnek: 10 satırlık veride "status = single THEN class = no" kuralına 4 satır uyuyor, bunların 2'si gerçekten no. Coverage $4/10 = \%40$, accuracy $2/4 = \%50$.
  - Hayvan veri kümesinde (20 satır) "Give Birth = no AND Can Fly = yes THEN Birds" kuralına 3 satır uyuyor, üçü de kuş: coverage $3/20$, accuracy $\%100$.
- Kural tabanlı sınıflandırıcının çalışması (ekrandan, 00:12:06)
  - Bir kayıt, koşulunu sağladığı kuralı tetikler (trigger) ve o kuralın sınıfını alır.
  - Lemur yalnız R3'ü tetikler, memeli olur. Kaplumbağa hem R4'ü (sürüngen) hem R5'i (amfibi) tetikler, çatışma çıkar. Köpek balığı (dogfish shark) hiçbir kuralı tetiklemez.
- Kural kümelerinin özellikleri (ekrandan, 00:17:06)
  - Karşılıklı dışlayan (mutually exclusive) kurallar: hiçbir kayıt iki kuralı birden tetiklemez; her kayıt en fazla bir kural tarafından kapsanır.
  - Kapsayıcı (exhaustive) kurallar: öznitelik değerlerinin her birleşimi için bir kural vardır; her kayıt en az bir kural tarafından kapsanır.
- Kurallar karşılıklı dışlayan değilse iki çözüm (ekrandan, 00:22:06)
  - Sıralı kural kümesi (decision list): kurallar önceliğe göre (örneğin accuracy, coverage ya da üretilme sırası) dizilir; kayıt, kendisini kapsayan en üst sıradaki kuralla sınıflanır ve aramaya devam edilmez.
  - Sırasız kural kümesi ve oylama: kayıt tüm kurallara sorulur, tetiklenen her kuralın sonucu bir oy sayılır, en çok oyu alan sınıf seçilir. Oylar kuralın accuracy değeriyle ağırlıklandırılabilir.
- Kurallar kapsayıcı değilse: varsayılan sınıf (default class)
  - Hiçbir kural tetiklenmezse kayda varsayılan sınıf atanır. Bu genellikle eğitim kümesinde en çok bulunan sınıftır (majority class). Kullanıcıya "default" diye anlamsız bir sınıf döndürülmez.
- Kural sıralama şemaları (ekrandan, 00:27:06)
  - Kural tabanlı sıralama: her kural kendi kalitesine (accuracy, coverage) göre sıralanır.
  - Sınıf tabanlı sıralama: aynı sınıfın kuralları bir arada durur; sınıflar sıralanır. Aynı sınıfın kurallarının kendi içindeki sırası önemli değildir, ama sınıfların birbirine göre sırası sonucu değiştirebilir.
- Sınıflandırma kurallarını oluşturma (ekrandan, 00:32:06)
  - Doğrudan (direct) yöntemler: kurallar doğrudan veriden çıkarılır; örnekler RIPPER, CN2.
  - Dolaylı (indirect) yöntemler: önce başka bir model (örneğin karar ağacı) kurulur, kurallar ondan çıkarılır; örnek C4.5rules.
- Ardışık kapsama (sequential covering) algoritması (ekrandan, 00:37:06)
  - Her adımda Learn-One-Rule ile bir kural öğrenilir, bu kuralın kapsadığı kayıtlar eğitim kümesinden çıkarılır, kural listeye eklenir. Durma koşulu sağlanana kadar devam edilir.
  - Durma koşulu: veri bitmesi ya da bulunan kuralın accuracy değerinin bir eşiğin altına düşmesi olabilir.
  - Algoritma sınıf sınıf ilerler: önce bir sınıfın (örneğin +) kuralları bulunur, sonra diğerine geçilir. Kalan örnekler için varsayılan sınıf tanımlanır.
- Learn-One-Rule ve kural büyütme
  - $n$ öznitelik için olası koşul birleşimi sayısı $\binom{n}{1} + \binom{n}{2} + \dots + \binom{n}{n}$'dir; bu üstel bir arama problemidir, en iyi kuralı bulmak pratikte mümkün değildir. Bu yüzden açgözlü (greedy) arama yapılır.
  - Genelden özele (general-to-specific): boş kuraldan (`{} => Mammals`) başlanır, accuracy'yi en çok artıran koşul tek tek eklenir, iyileşme durunca durulur (ekrandan, 00:42:06).
  - Özelden genele (specific-to-general): tüm öznitelikleri içeren bir kuraldan başlanır, koşullar teker teker çıkarılarak kural genelleştirilir.
  - Açgözlü arama geri dönüş yapmadığı için yerel optimumda kalabilir; algoritmayı farklı rastgele başlangıçlarla çalıştırmak bir çaredir.
- Kural değerlendirme: FOIL bilgi kazancı (ekrandan, 00:47:06 ve 00:54:00)
  - Yalnız accuracy yetmez: 60 pozitif, 100 negatif örnekli veride R1 50 pozitif ve 5 negatif, R2 2 pozitif ve 0 negatif örnek kapsar. R2'nin accuracy değeri ($\%100$) R1'inkinden ($\%90.9$) yüksektir, ama R1 kapsaması sayesinde daha iyi bir kuraldır.
  - FOIL bilgi kazancı hem coverage'i hem accuracy'yi hesaba katar. R0 başlangıç kuralı, R1 bir koşul (B) eklenmiş kural olmak üzere:
    $$\text{FOIL\_Gain}(R_0,R_1) = p_1 \times \left(\log_2 \frac{p_1}{p_1+n_1} - \log_2 \frac{p_0}{p_0+n_0}\right)$$
  - $p_0, n_0$: R0'ın kapsadığı pozitif ve negatif örnek sayısı; $p_1, n_1$: R1'in kapsadığı pozitif ve negatif örnek sayısı.
  - Parantez içi, koşul eklenince doğruluğun artıp artmadığını ölçer; $p_1$ ile çarpmak, çok örnek kapsayan kurala katsayı gibi daha büyük ağırlık verir.
- Dolaylı yöntem: karar ağacından kural çıkarma (ekrandan, 00:59:00)
  - Kökten her yaprağa giden her yol bir kural olur; yol üzerindeki her öznitelik-değer çifti AND ile bağlanır, yaprak sınıfı verir.
  - Örnek (buys_computer ağacı): `IF age = young AND student = no THEN buys_computer = no` gibi beş kural.
  - Budanmamış ağaçtan çıkan kurallar hem karşılıklı dışlayan hem kapsayıcıdır.
- Bayes teoremi (ekrandan, 01:04:00)
  - $P(A)$: A olayının olasılığı; $P(A|B)$: B olduğu bilindiğinde A'nın olasılığı; $P(A,B)$: ortak (joint) olasılık, $P(A \cap B)$ olarak da yazılır.
  - $P(A|B) = P(A,B)/P(B)$ ve $P(B|A) = P(B,A)/P(A)$. $P(A,B) = P(B,A)$ olduğundan iki ifade eşitlenir:
    $$P(A|B) = \frac{P(B|A)\,P(A)}{P(B)}$$
  - Tablo örneği (ekrandan, 01:09:00): 7 durumda $P(A)=4/7$, $P(B)=3/7$, $P(A,B)=2/7$, $P(B|A)=2/4$, $P(A|B)=2/3$; teorem bu değerlerle doğrulanır.
  - Koşullu olasılık ile kesişim aynı şey değildir: kesişim ikisinin birlikte olmasıdır, $P(B|A)$ ise yalnız A'nın olduğu durumlar içinde B'nin oranıdır.
- Bağımsızlık (ekrandan, 01:14:00)
  - A ve B ancak $P(A,B) = P(A)P(B)$ ise bağımsızdır.
  - 3 bitlik diziler: "1 ile başlar" (A) ve "1 ile biter" (B) bağımsızdır; "1 ile başlar" (A) ve "tam iki tane 1 içerir" (C) bağımsız değildir.
- Naive Bayes sınıflandırıcı
  - Veriye uygulanırken koşul tarafında öznitelikler, aranan tarafta sınıf bulunur: $P(C|X) \propto P(X|C)\,P(C)$. Her sınıf için hesaplanır, en yüksek olasılığı veren sınıf seçilir.
  - Öznitelikler, sınıf verildiğinde birbirinden bağımsız varsayılır; böylece $P(X|C)$ her özniteliğin koşullu olasılıklarının çarpımı olur.
  - buys_computer örneği (14 satır, ekrandan, 01:19:00 ve 01:24:00): $P(yes)=9/14$, $P(no)=5/14$. Test kaydı (age ≤ 30, income = medium, student = yes, credit = fair) için $P(X|yes)P(yes) \approx 0.028$, $P(X|no)P(no) \approx 0.007$; sınıf yes.
  - Sıfır olasılık sorunu: eğitim kümesinde hiç görülmeyen bir değer (örneğin $P(age=31..40|no)=0$) tüm çarpımı sıfırlar. Çözüm: düzleştirme (smoothing), örneğin her sayıma bir eklemek.
  - Artıları: uygulanması kolay, çoğu durumda iyi sonuç verir. Eksileri: sınıf koşullu bağımsızlık varsayımı gerçekte çoğu zaman tutmaz, bu da doğruluk kaybına yol açar (ekrandan, 01:29:00). Bağımlılıklar biliniyorsa Bayes inanç ağları (belief networks) kullanılabilir.
- Weka uygulaması
  - Yeni Zelanda'da Waikato Üniversitesi'nde Java ile geliştirilmiş, açık kaynak bir veri madenciliği aracıdır. Package Manager ile ek algoritmalar yüklenebilir.
  - Explorer > Preprocess: dosya, URL ya da veri tabanından veri açılır; CSV, JSON, LibSVM ve Weka'nın kendi biçimi ARFF desteklenir. Her öznitelik için min, max, ortalama, standart sapma ve sınıfa göre renklenmiş dağılım gösterilir.
  - Filtreler denetimli/denetimsiz ve öznitelik/örnek bazında ayrılmıştır: NominalToBinary, Discretize, RemoveRange, RemoveDuplicates, RemoveWithValues gibi.
  - Classify: test seçenekleri training set, supplied test set, cross-validation (k katlı) ve percentage split'tir. Iris verisinde Naive Bayes, %80 eğitim ayrımıyla 30 test örneğinin 29'unu doğru sınıfladı ($\%96.67$, ekrandan, 02:09:00).
  - J48 (C4.5) parametreleri: batch size, binary splits, budama (unpruned) gibi.
  - Visualize sekmesi öznitelik çiftleri arasındaki ilişkiyi saçılım grafikleriyle gösterir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kural sırasının önemi
  - Sıralı kurallarda ilk uyan kuralda durulduğu için sıra sonucu değiştirir. Çok özel, az örneğe uyan bir kural en başa konursa benzer kayıtları yanlış sınıflandırabilir; accuracy ve coverage'i yüksek kurallar yukarıda olmalıdır.
  - Sınıf tabanlı sıralamada aynı sınıfın kuralları kendi içinde yer değiştirebilir, ama farklı sınıfların yeri değişirse bazı kurallar hiç tetiklenmez hale gelebilir.
- Yalnız accuracy'ye bakmak yanıltıcıdır
  - Tek bir örneği kapsayan ve onu doğru bulan kural $\%100$ accuracy alır. Böyle gidilirse her satıra bir kural yazılmış olur. Bu yüzden coverage de hesaba katılmalıdır; FOIL bilgi kazancı bunun için vardır.
- Naive Bayes'in sıfır olasılık sorunu
  - Bir sınıf için tek bir sıfır olasılık, o sınıfın seçilme ihtimalini tamamen ortadan kaldırır. Az örnekli eğitim kümelerinde smoothing şarttır.
- Bağımsızlık varsayımı
  - Naive Bayes öznitelikleri bağımsız kabul eder; gerçek dünyada öznitelikler bağımlıysa iyi çalışmaz.
  - Ders sonrası not: Hoca bu varsayımın Bayes teoreminin kesişimden çıkarılmasından geldiğini söyledi. Bayes teoremi bağımsızlık gerektirmez; her iki olay için de geçerlidir. Bağımsızlık varsayımı Naive Bayes'in kendi varsayımıdır: sınıf verildiğinde özniteliklerin birbirinden bağımsız olduğu kabul edilir (sınıf koşullu bağımsızlık).
- Çapraz doğrulama (cross-validation)
  - 3 katlı örnek: veri rastgele A, B, C parçalarına bölünür; her turda iki parça eğitim, biri test olur. Her örnek bir kez test edilir, sonuçta ortalama hata verilir. Veri az olduğunda kullanılır.
- CSV ve Türkçe Excel
  - Türkçe ayarlı Excel ondalık ayırıcı olarak virgül kullandığı için CSV'yi noktalı virgülle ayırır. CSV açılırken sorun çıkarsa sebebi büyük ihtimalle virgül, noktalı virgül ve nokta karışıklığıdır.

## Kısa Tekrar Notları

- Kural: IF koşul (AND ile bağlı öznitelik testleri) THEN sınıf.
- $\text{coverage} = n_{covers}/|D|$, $\text{accuracy} = n_{correct}/n_{covers}$.
- Mutually exclusive: her kayıt en fazla bir kural; exhaustive: her kayıt en az bir kural.
- Çakışma çözümü: sıralı kurallar (decision list) ya da (accuracy ağırlıklı) oylama.
- Hiç kural tetiklenmezse: varsayılan sınıf, genellikle çoğunluk sınıfı.
- Sıralama: kural tabanlı (kalite) ya da sınıf tabanlı.
- Doğrudan yöntemler: RIPPER, CN2 (sequential covering). Dolaylı: C4.5rules (ağaçtan kural).
- Learn-One-Rule açgözlüdür; genelden özele ya da özelden genele büyür.
- FOIL: $p_1\left(\log_2\frac{p_1}{p_1+n_1} - \log_2\frac{p_0}{p_0+n_0}\right)$.
- Ağaçtan çıkan kurallar karşılıklı dışlayan ve kapsayıcıdır.
- Bayes: $P(A|B) = P(B|A)P(A)/P(B)$. Bağımsızlık: $P(A,B)=P(A)P(B)$.
- Naive Bayes: $P(X|C)P(C)$ en büyük olan sınıf; sıfır olasılık için smoothing.
- Weka: Preprocess (filtreler), Classify (test seçenekleri), Visualize; biçim ARFF ya da CSV.

## Detaylı Açıklamalar

- Kural tabanlı sınıflandırıcı, eğitim verisinden çıkarılan "IF ... THEN ..." kurallarıyla çalışır. Bir kuralın kalitesi iki sayıyla ölçülür. Coverage, kuralın koşul kısmına uyan kayıtların tüm veriye oranıdır ve sınıfa bakmaz. Accuracy ise koşula uyanlar arasında sınıfı da doğru tahmin edilenlerin oranıdır. Derste 10 satırlık bir veri kümesinde "status = single" koşuluna dört satırın uyduğu, bunlardan ikisinin sınıfının gerçekten "no" olduğu gösterildi; kuralın coverage değeri $\%40$, accuracy değeri $\%50$'dir.

- Test zamanında kayıt kurallara sorulur. Slayttaki beş kurallık hayvan örneğinde lemur yalnız R3'e (Give Birth = yes AND Blood Type = warm) uyar ve memeli olarak sınıflanır. Kaplumbağa hem R4'e (Give Birth = no AND Can Fly = no → sürüngen) hem R5'e (Live in Water = sometimes → amfibi) uyar; bu kural kümesi karşılıklı dışlayan değildir. Köpek balığı hiçbir kurala uymaz; kural kümesi kapsayıcı da değildir. Birinci sorun sıralı kurallarla ya da oylamayla, ikinci sorun varsayılan sınıfla çözülür.

- Sıralı kurallarda kayıt yukarıdan aşağı kurallara bakılır ve ilk uyan kuralda durulur. Bu hem hızlıdır hem de doğruluğu yüksek kurallar önde olduğunda doğru sonuç verir. Derste bir öğrenci köpek balığı için özel bir kural yazıp en başa koymayı önerdi; hoca bunun benzer başka kayıtları da yanlışlıkla aynı sınıfa çekebileceğini, bu yüzden çok özel kuralların aşağıya konması gerektiğini söyledi. Sınıf tabanlı sıralamada bir sınıfın kuralları içinde sıra önemsizdir, ama örneğin "skin cover = feathers AND aerial = yes AND A = X → bird" kuralının altında "skin cover = feathers AND aerial = yes → amphibian" gibi daha genel bir kural varsa ve sınıfların yeri değiştirilirse, özel kural hiç tetiklenmez olur.

- Doğrudan yöntemlerin temeli ardışık kapsamadır. Algoritma bir sınıf için Learn-One-Rule ile bir kural bulur, kuralın kapsadığı kayıtları veriden çıkarır, kuralı listeye ekler ve yeni bir kural arar. Learn-One-Rule'un en iyi kuralı bulması üstel bir arama gerektirdiği için açgözlü yaklaşılır. Genelden özele stratejide boş kuraldan başlanıp her adımda en çok iyileştiren koşul eklenir; bu yöntem aynı koşulların farklı kurallarda tekrar etmesine yol açabileceği için sonradan kural elemesi (budamaya benzer) gerekebilir. Özelden genele stratejide ise her şeyi içeren bir kuraldan koşullar çıkarılır; kural genelleştikçe coverage artar.

- Hangi koşulun ekleneceğine karar vermek için accuracy yetmez. 60 pozitif ve 100 negatif örnekli veride R2 yalnız 2 pozitif örneği kapsayıp $\%100$ accuracy'ye ulaşır, ama R1 (50 pozitif, 5 negatif; $\%90.9$) çok daha fazla örneği doğru kapsar. FOIL bilgi kazancında parantez içindeki fark, koşul eklendikten sonra pozitif oranının ne kadar arttığını ölçer; doğruluk arttıysa fark pozitiftir. Bu fark $p_1$ ile çarpılır; böylece çok pozitif örnek kapsayan kural katsayı gibi daha büyük puan alır.

- Dolaylı yöntemde C4.5 gibi bir algoritmayla karar ağacı kurulur, kökten her yaprağa giden yol bir kural olarak yazılır (örneğin "age = young AND student = no THEN buys_computer = no"). Ağaçta her kayıt tek bir yaprağa düştüğü ve eğitim verisinin tamamından kurulduğu için bu kurallar hem karşılıklı dışlayan hem kapsayıcıdır.

- Bayes teoremi, koşullu olasılığın iki yönlü tanımındaki ortak olasılığın eşitlenmesinden çıkar: $P(A|B)P(B) = P(A,B) = P(B|A)P(A)$. Sınıflandırmaya uygulanırken A yerine sınıf, B yerine kaydın öznitelikleri (X) konur. Naive Bayes, sınıf verildiğinde özniteliklerin bağımsız olduğunu varsayarak $P(X|C)$'yi her özniteliğin koşullu olasılığının çarpımı olarak hesaplar; bu olasılıklar eğitim kümesinde sayılarak bulunur ve saklanır. Test zamanında her sınıf için $P(X|C)P(C)$ hesaplanır, en büyüğü seçilir. buys_computer örneğinde yes için yaklaşık $0.028$, no için yaklaşık $0.007$ bulunur; kayıt "yes" olarak sınıflanır.

- Weka hızlı deneme için uygun bir araçtır. Preprocess sekmesinde veri açılır, öznitelik istatistikleri görülür ve filtreler uygulanır; Discretize gibi filtrelerde öznitelik numaraları 1'den başlar. Classify sekmesinde sınıflandırıcı ve test seçeneği seçilir; "Output predictions" ile her test örneğinin tahmini görülebilir, "Preserve order" seçilirse veri karıştırılmadan ilk kısım eğitime ayrılır. ARFF dosyası `@relation`, her öznitelik için `@attribute` (sayısal öznitelikler için `real`, nominal sınıf için `{değer1, değer2, ...}`) ve `@data` altında virgülle ayrılmış satırlardan oluşur. Weka JVM üzerinde çalıştığı için büyük veride bellek hatası verebilir; parametreleri arayüzden sınırlı ölçüde değiştirilebilir. Bir sunucuda arka planda çalışacak bir uygulama için Weka'nın Java kodu indirilip programdan çağrılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
