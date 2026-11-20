# Ders 8 Çalışma Özeti

## Genel Konular

- Bilgi nedir, bilmenin seviyeleri
  - "Bilinen her şey" tanımı kendine referans veren (özyinelemeli) bir tanımdır ve pek bir şey söylemez. Herkesin kabul edeceği bir bilgi tanımı bulmak zordur, ama bilmenin farklı seviyeleri tanımlanabilir.
  - Slayttaki göstergeler: farkında olma, anımsama / çağrıştırma / hatırlama, tanıma, yorumlama, açıklayabilir olma, kanıtlayabilir olma, hakkında konuşabilme, yerine getirebilir / yapabilir olma (ekrandan, 00:10:00). Liste yukarıdan aşağı artan ya da azalan bir sıra değildir.
  - $E = mc^2$ örneği: denklemi anlamını bilmeden tanımak düşük seviyeli bir bilmedir; parçalarını söylemek (E enerji, m kütle, c ışık hızı), enerji ile kütlenin birbirine dönüşebildiğini yorumlamak ve denklemi kanıtlayabilmek giderek daha üst seviyelerdir.
- Veriden bilgiye
  - Slayttaki üçgen: altta veri, üstte bilgi; dikey eksen soyutluk derecesi (düşük-yüksek), yatay eksen miktar. Yukarı çıktıkça işleme / yorumlama miktarı ve kişiye özel oluş artar (ekrandan, 00:15:00).
  - Veri: herkesin bir şeye baktığında ortak gördüğü kısımdır (ör. bir resmin pikselleri). Bilgi: verinin işlenip yorumlanmasıyla kişiye özel hale gelmiş, hacimce küçük kısımdır.
  - Piksel → bölgesel etiketler → tek bir etiket. Örnek 1: "yaşlı bir kadın, fakir bir kadın, bir çorba tenceresi tutuyor, gülümsüyor" → "mutluluk, şükran, ?". Örnek 2: "iki kilit, bir anahtar, bir eğik çizgi" → "gülen bir yüz" (ekrandan, 00:20:00).
  - Kişiden kişiye farklılık bölgesel etiketler seviyesinde başlar. İkinci örnekte parçaların toplamı bütünü tahmin ettirmez; bütün, parçaların toplamından fazladır. Bu durum, parçaları tanıyarak ilerleyen bugünkü görüntü işleme sistemleri için de zordur.
- Bilginin özellikleri (meta bilgi) (ekrandan, 00:25:00)
  - Alan (özel - genel), doğruluk (doğru - yanlış), kesinlik (kesin - belirsiz), doğrulanabilirlik / yanlışlanabilirlik (bilimsel bilgi - metafizik), güncellik (güncel - eski), tamlık (tam - eksik), ekonomiklik (elde edilmesi ondan beklenenden pahalı - değersiz), yaygınlık (çokça bilinen - hiç bilinmeyen).
  - Kesinlik: bilginin kaynağına bağlıdır. Robotta sensörler bilgi kaynağıdır; düşük ışıkta kamera görüntüsü daha belirsizdir, nem ve toz lazer sensörünü bozar, ses sensörü lazerden daha düşük kesinliklidir.
  - Bilimsel bilgi laboratuvarda kontrollü deneyle doğrulanabilir ya da yanlışlanabilir (bugün değilse bile ileride). Test edilemeyen bilgiye metafizik denir (ör. inanç konuları). Bu, bilginin doğru ya da yanlış olduğu hakkında değil, test edilebilir olmadığı hakkında bir ifadedir.
  - Ekonomiklik: "Türkiye'de bugün kaç Fenerbahçeli var?" sorusunun tam cevabı çok pahalıdır; yaklaşık cevap (ör. 12-13 milyon) çoğu amaç için yeterlidir ve örneklem (ör. 100 kişi) ile ucuza elde edilir. Örneklem büyüdükçe tahmin iyileşir, maliyet artar; örneklemin nerede seçildiği sonucu saptırabilir.
  - Yaygınlık: herkesin bildiği "hayat bilgisi" (insanların uykuya ihtiyacı vardır, kuşlar uçar) ile yalnız bir kişinin bildiği bilgi (ör. kimseye anlatılmamış bir rüya, yeni bulunmuş bilimsel bir sonuç).
- Bilgi gösterim türleri: kurallar, anlamsal ağlar, yüklem mantığı, çerçeveler, sahneler, yapay sinir ağları (ekrandan, 00:35:00 sol panel).
- Kurallar ve kurallarla çıkarım
  - Kurallar `if-then` yapısıdır; ilişkileri, tavsiyeleri ve direktifleri ifade edebilir.
  - Çıkarım: eldeki bilgileri kullanarak elde olmayan bir bilgiye ulaşma (bilgi üretme) sürecidir.
  - Slayt örneği: `if A and C then E`, `if D and C then F`, `if B and E then F`, `if B then C`, `if F then G`; gerçekler `A`, `B` (ekrandan, 00:35:00).
  - Geriye doğru zincirleme bir şeyin doğru olup olmadığını sorar ("G doğru mudur?"); ileriye doğru zincirleme doğru olan her şeyi üretir ("Ne doğrudur?").
- İleriye doğru zincirleme (forward chaining)
  - Database (şu an doğru bilinenler): A, B, C, D, E. Knowledge base: $Y \land D \to Z$, $X \land B \land E \to Y$, $A \to X$, $C \to L$, $L \land M \to N$.
  - Sol tarafı doğru olan kurallar ateşlenir (fire): önce $A \to X$ ve $C \to L$ (X, L), sonra $X \land B \land E \to Y$ (Y), sonra $Y \land D \to Z$ (Z). $L \land M \to N$ M bilinmediği için hiç ateşlenmez. Üretilen yeni bilgiler: X, L, Y, Z (python ile doğrulandı).
- Geriye doğru zincirleme (backward chaining) (ekrandan, 00:40:00 ve 00:45:00)
  - Hedef güdümlü akıl yürütmedir (goal-driven reasoning). Hedef alt hedeflere bölünür; tüm alt hedefler kanıtlanınca hedef kanıtlanmış olur.
  - Aynı kurallarla "Z doğru mu?": Z için Y ve D gerekir, D bilinir, alt hedef Y; Y için X, B, E gerekir, alt hedef X; X için A gerekir, A bilinir. Sonra X, Y, Z sırayla eklenir.
  - Slayt örneğinde "G doğru mu?": G ← F; F ← (D ve C) ya da (B ve E). D bilinmediği için B ve E yoluna gidilir; E ← A ve C; C ← B. Sonuç: C, E, F, G doğrudur, yani G doğrudur (python ile doğrulandı).
- İki doktor örneği
  - Doktor A şikayetleri dinleyip hipotez üretir (ileriye doğru), sonra bunu tahlille doğrular (geriye doğru); hipotez tutmazsa yeni hipotez üretir. Doktor B hiçbir şey sormadan bütün tahlilleri yaptırır ve sonuçlardan ileriye doğru çıkarım yapar.
  - A daha hızlı ve toplamda daha ucuzdur (arama uzayını küçültür). B, henüz belirtisi olmayan bir hastalığı da yakalayabilir (bir tür check-up).
  - Uzman önce bilgi toplayıp olası sonuçları arıyorsa ileriye doğru, önce hipotez kurup doğrulamaya çalışıyorsa geriye doğru zincirleme kullanılır.
- Anlaşmazlık kümesi ve anlaşmazlığın çözümü
  - Aynı anda birden fazla kuralın uygulanabildiği durum. Örnek: trafik ışığı kırmızıysa bir kural "dur", başka biri "geç" diyorsa hangisi ateşlenecek?
  - Database'deki bilgilere göre ateşlenebilecek kuralların kümesine çatışma / anlaşmazlık kümesi, bu kümeden ateşlenecek kuralın seçimine anlaşmazlığın çözümü denir.
  - Yöntemler (ekrandan, 01:05:00): sıralama (önem sırasına göre, en yukarıdaki), durumla eşleşme (duruma en çok uyan; A ve B doğruyken `if A or B or C then X` ile `if A then Y` arasında slaytta X seçilir), güncellik (en son eklenen; tersine en eski ve çok kullanılmış kural da güvenilirlik için seçilebilir), meta kurallar (kuralın kaynağının uzmanlık derecesi, insan hayatıyla ilgili kuralların önceliği).
- Anlamsal ağlar (semantic nets)
  - Düğümlerin farklı tipte bağlarla (instance, is-a, has-part, hometown vb.) bağlandığı yönlü graftır; grafik göstermeye çok uygundur.
  - Hiyerarşik yapı çıkarıma uygundur: ANIMAL (can breathe, has skin, can move), BIRD (can fly, has wings, has feathers), CANARY (can sing, is yellow), OSTRICH (cannot fly, is tall), FISH (ekrandan, 01:10:00). Özellikler en genel düğümde bir kez tutulur, alt düğümler için çıkarımla elde edilir.
  - Ezber ile çıkarım dengesi: çok sık kullanılan bilgi (çarpım tablosu) hız için ezberlenir; seyrek kullanılan bilgi gerektiğinde çıkarımla üretilir. İnsan bilgisinin de kabaca böyle hiyerarşik tutulduğu varsayılır (kaplumbağanın sol ön bacağındaki hücrenin ribozomu örneği).
- Yüklem mantığı: Prolog yapısıyla önceki dönemde görüldüğü için ayrıntıya girilmedi.
- Çerçeveler (frames)
  - Nesneye yönelik programlamanın yapay zekaya uyarlaması gibidir. Anlamsal ağlardan farkı, her kavramın (çerçevenin) içinde özniteliklerin (slot) bulunmasıdır (ör. ayak sayısı, uçabilir mi).
  - Bir özniteliğin çeşitli yuvaları (facets) olabilir: değer, varsayılan değer, değer aralığı, değer türü, ekleme / silme sırasında çalışacak prosedür, önem katsayısı, başka bir çerçevenin ID'si (ekrandan, 01:15:00).
- Sahneler (scripts)
  - Belli bir durumdaki basmakalıp olay dizisidir (lokantada yemek yemek, otobüse binmek, sınava girmek). Roger Schank'a göre insanlar bu senaryoları öğrenir ve bir olayın bilinmeyen parçalarını bunlarla doldurur ("Ali lokantaya gitti, çıkışta bahşiş verdi" → Ali büyük ihtimalle yemek yemiştir).
  - Bileşenler: sahne ismi, başlama şartları, roller, nesneler, alt sahneler, sonuçlar. Lokanta sahnesi 5 alt sahneden oluşur: giriş, sipariş, yiyeceğin hazırlanması, yemeğin yenmesi, lokantadan ayrılma (ekrandan, 01:20:00).
  - Yaklaşım çok başarılı olamadı: olayların insandan insana ve olaydan olaya varyasyonu çok fazladır; hayat sanıldığı kadar basmakalıp değildir.
- Kapalı dünya (closed world) ve açık dünya (open world)
  - Kapalı dünyada sistemde olmayan bilgi yanlış kabul edilir; açık dünyada eksik ya da yanlış olabilir. "Alex'in iki çocuğu girilmişse" kapalı dünya "tam iki çocuğu var", açık dünya "en az iki çocuğu var" der.
  - Kapalı dünyada çıkarım çok daha kolaydır; ama insanlar açık dünyada yaşar (kapalı dünyaya örnek olarak oyunlar düşünülebilir).
- Yapay sinir ağlarında bilgi temsili (ekrandan, 01:25:00)
  - Tüm bilgi ağda saklanır: ağın yapısı ve ağırlıkları bilgiyi depolar. Tek / çok katmanlı ağlar, özyinelemeli ağlar (önceki girişlere göre de işlem yapar).
  - Konuşmayı metne çeviren bir sistemde açık kurallar yoktur; eşleme bilgisi ağırlıklardadır. İnsan beyninde de bilginin ağ yapısında ve ağırlıklarda tutulduğu düşünülür.
  - TensorFlow Playground gösterimi: iki boyutlu girişli, iki sınıflı (sarı / mavi) problem. Eğitim, ağırlıkların girişleri doğru çıkışlara eşleyecek şekilde güncellenmesidir. Daire veri kümesi 2 gizli katmanla (4 ve 2 nöron, tanh) kolay öğrenildi (ekrandan, 01:30:00); spiral veri kümesi zor oldu, ReLU, 4 gizli katman ve $X_1^2, X_2^2, X_1X_2, \sin X_1, \sin X_2$ girişleri eklenince çözülebildi (ekrandan, 01:35:00).
- Doğal dil işlemede bilgi gösterimi (ekrandan, 01:40:00 ve 01:45:00)
  - Kelimeler string olarak yalnız şekilsel (sentaktik) karşılaştırılabilir; "Galatasaray yendi" ile "Cimbom kazandı" karakterce ortak değildir ama anlamca aynıdır. Çözüm: anlamca yakın kelimelerin vektörleri birbirine yakın olacak şekilde kelimeleri vektörle temsil etmek.
  - Word2vec (2013, Mikolov ve ark.), fastText (2017, Bojanowski ve ark.): tek gizli katmanlı yapay sinir ağı. $C=2$ için bağlam $(w_{t-2}, w_{t-1}, w_t, w_{t+1}, w_{t+2})$. Skip-gram: giriş $w_t$, çıkış bağlamdaki kelimelerin her biri. CBOW: giriş bağlamdaki kelimelerin her biri, çıkış $w_t$.
  - Giriş 1-hot vektörü $1 \times |V|$, projeksiyon (gömme) $1 \times d$, çıkış $1 \times |V|$; $W$ matrisi $|V| \times d$, $C$ matrisi $d \times |V|$. Kelime vektörleri ağın ağırlıklarından oluşur. Sözlük genelde 10-20 bin kelimeye indirilir.
  - Metin temsili: içerdiği kelimelerin vektörlerinin ortalaması ya da encoder-decoder (seq2seq) mimarileri (LSTM encoder "How are you <EOL>" → W → LSTM decoder "I am fine <EOL>").
- Görüntü işlemede bilgi gösterimi: CNN'lerde alt katmanlar her resim için geçerli basit özellikleri (açılı çizgiler, siyah-beyaz) öğrenir; üst katmanlarda kaş, göz, burun gibi parçalar, en üstte yüzler oluşur. Bu hiyerarşi veriden bilgiye geçişe benzer.
- Çıkarım türleri (ekrandan, 02:05:00)
  - Tümdengelim (deduction): sebeplerden sonuca. "Bu kutudaki tüm toplar siyahtır; bu toplar bu kutudandır → bu toplar siyahtır." $A \Rightarrow B$, $A \vdash B$. Kesindir.
  - Abduction: sonuçtan olası sebebe. "Bu kutudaki tüm toplar siyahtır; bu toplar siyah → bu toplar bu kutudandır." $A \Rightarrow B$, $B \vdash$ possibly $A$. Kesin değildir, bir olgu (fact) üretir.
  - Tümevarım (induction): örneklerden olası kurala. "Bu toplar bu kutudandır; bu toplar siyah → bu kutudaki tüm toplar siyahtır." Kesin değildir, bir kural üretir.
  - İleriye ve geriye doğru zincirlemede yapılan çıkarımların hepsi tümdengelimdi; olasılık içeren çıkarımlar için başka mekanizmalar gerekir.
- Çıkarım örnekleri (ekrandan, 02:10:00) ve belirsizlik
  - Kesin olanlar: kediler memelidir + memeliler hayvandır → kediler hayvandır; yaşamak için havaya ihtiyacın var + uzayda hava yok → uzayda yaşayamazsın; kapıyı itmek kapıyı açar + Ali kapıyı itti → Ali kapıyı açtı (öncüller doğru kabul edildiğinde).
  - Kesin olmayanlar: Ali araba kullanıyor → ehliyeti / arabası var; X'in A, B, C'si, Y'nin B, C'si var → Y'nin A'sı olabilir; gördüğüm A'ların B'si var → tüm A'ların B'si var; Ali 1971'de attan düştü → 1972'de düşmedi.
  - "Ali 1971'de öldü → 1972'de attan düşmedi" ise anlam devreye girdiği için büyük ihtimalle söylenebilir.
  - Belirsizlik kaynakları: girişlerin eksik olması, bir sebebin çok sayıda sonucu, bir sonucun çok sayıda sebebi olması, olasılıkla ortaya çıkma, tümevarım ve abduction kullanma, rasyonel davranış.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çıkarımın tanımı
  - Hoca tanımı iki kez tekrarladı: elinizdeki bilgileri kullanarak elinizde olmayan bir bilgiyi üretme süreci.
- İleri ve geri zincirlemenin sorduğu soru farklıdır
  - Geriye doğru zincirleme tek odaklıdır ("G doğru mu?"); ileriye doğru zincirlemenin odağı yoktur ("Ne doğrudur?"). İki doktor örneği iki mekanizmanın birlikte nasıl kullanıldığını gösterir.
- Hiyerarşik bilgi tutmanın kazancı
  - Çıkarımla elde edilebilecek bilgiyi her alt kavram için ayrı ayrı tutmak bilgi tabanını hantallaştırır. Sık kullanılanı ezberlemek, seyrek kullanılanı çıkarımla üretmek mantıklıdır.
- Yapay sinir ağlarında bilgi kurallarda değil ağırlıklardadır
  - Playground'daki ağın yapısı aynı kalırken yalnız ağırlıklar değişir; sınıfları ayıran bütün bilgi ağın mimarisinde ve ağırlıklarında saklıdır. Her problemin zorluğu aynı değildir.
- Kesinlik yalnız tümdengelimdedir
  - Tümevarım ve abduction olasılık içerir; tümevarım kural, abduction olgu üretir. Gerçek hayattaki kesin bilgiler çok azdır.

## Kısa Tekrar Notları

- Bilmenin seviyeleri: tanıma, yorumlama, açıklama, kanıtlama, hakkında konuşma, yapabilme.
- Veri herkes için ortak, bilgi işlenmiş ve kişiye özeldir; yukarı çıktıkça soyutluk artar, miktar azalır.
- Meta bilgi: alan, doğruluk, kesinlik, doğrulanabilirlik, güncellik, tamlık, ekonomiklik, yaygınlık.
- Bilimsel bilgi test edilebilir; test edilemeyen bilgi metafiziktir.
- Bilgi gösterim türleri: kurallar, anlamsal ağlar, yüklem mantığı, çerçeveler, sahneler, YSA'lar.
- İleri zincirleme: veri güdümlü, doğru olan her şeyi üretir. Geri zincirleme: hedef güdümlü, hedefi alt hedeflere böler.
- Anlaşmazlığın çözümü: sıralama, durumla eşleşme, güncellik, meta kurallar.
- Anlamsal ağ: yönlü graf, is-a yolunda has ilişkileri miras alınır.
- Çerçeve: kavram + öznitelikler (slot) + yuvalar (facet).
- Sahne: basmakalıp olay dizisi; varyasyon çokluğu yüzünden başarısız kaldı.
- Kapalı dünya: olmayan bilgi yanlıştır. Açık dünya: olmayan bilgi bilinmiyordur.
- YSA'da bilgi yapı ve ağırlıklardadır; Word2vec skip-gram ve CBOW, $W$: $|V| \times d$.
- Tümdengelim kesin; abduction sonuçtan olası sebebe; tümevarım örneklerden olası kurala.

## Detaylı Açıklamalar

- Ders, bilginin ne olduğu sorusuyla başladı. Hoca, bilgiyi doğrudan tanımlamak yerine bilmenin seviyelerini $E = mc^2$ üzerinden anlattı: denklemi bir tişörtte görüp tanımak, sembollerin ne anlama geldiğini söylemek, enerji ile kütlenin birbirine dönüşebildiğini yorumlamak ve denklemi kanıtlamak farklı bilme seviyeleridir. Ardından veri-bilgi üçgeni geldi: aynı resme bakan herkes aynı pikselleri görür, ama "yaşlı bir kadın gülümsüyor" gibi bölgesel etiketlerde ve "mutluluk, şükran" gibi tek bir etikette kişiden kişiye farklılık başlar. Kilit-anahtar-çizgi örneğinde parçaların toplamı bütünü (gülen yüz) tahmin ettirmez; bu hem insanlar hem de parçaları tanıyarak ilerleyen görüntü işleme sistemleri için zordur.
- Bilginin özellikleri meta bilgidir. En çok üzerinde durulan ekonomiklik örneğinde, bir bilginin tam değerini (Türkiye'deki Fenerbahçeli sayısı) bulmak milyonlarca dolara mal olabilirken yaklaşık değer küçük bir örneklemle elde edilebilir. Örneklem büyüdükçe tahmin iyileşir ama maliyet artar; anketin hangi sokakta yapıldığı da sonucu saptırabilir.
- Kurallarla çıkarımda iki mekanizma vardır. İleriye doğru zincirlemede database'deki gerçeklere bakılarak sol tarafı sağlanan kurallar ateşlenir ve her ateşleme database'e yeni bir gerçek ekler; yeni gerçekler başka kuralları uygulanabilir hale getirir. Hiçbir kural uygulanamaz olunca süreç biter. Geriye doğru zincirlemede ise hedeften başlanır: hedefi sonuç olarak veren kuralın sol tarafındaki bilinmeyenler alt hedef olur ve bilinen gerçeklere ulaşınca zincir geri sarılır.

```text
İleriye doğru zincirleme (database: A B C D E)
Döngü 1: A -> X, C -> L ateşlenir      => X, L eklenir
Döngü 2: X & B & E -> Y ateşlenir      => Y eklenir
Döngü 3: Y & D -> Z ateşlenir          => Z eklenir
L & M -> N: M yok, ateşlenmez. Üretilen: X, L, Y, Z

Geriye doğru zincirleme (hedef Z)
Z <- Y & D   (D bilinir, alt hedef Y)
Y <- X & B & E (B, E bilinir, alt hedef X)
X <- A       (A bilinir)
Sonra X, Y, Z sırayla eklenir.
```

- Anlaşmazlık kümesi, ileriye doğru zincirlemede aynı anda birden fazla kuralın ateşlenebilmesinden doğar. Seçim stratejisi tamamen tasarımcının tercihidir. Güncellik ölçütü iki yönlü düşünülebilir: tıbbi bir bilgi sisteminde en son eklenen kural en güncel bilgiyi taşır, ama uzun süredir tabanda duran ve defalarca sorunsuz kullanılmış eski kural da daha güvenilir sayılabilir. Meta kurallarda kuralı yazan uzmanın deneyimi (bir yıllık ya da on yıllık doktor) önceliği belirleyebilir.
- Anlamsal ağ, çerçeve ve sahne birbirine benzeyen ama farklı vurgulara sahip temsillerdir. Anlamsal ağda kavramlar ilişkilerle bağlıdır; çerçevede ek olarak her kavramın içinde öznitelikler ve onların yuvaları vardır; sahnede ise bir durumun sıralı alt olayları tutulur. Hoca, sahnelerin bine yakın örnekle denendiğini ama varyasyonlar yüzünden başarılı olamadığını söyledi.
- Yapay sinir ağlarında ise açık sembolik yapı yoktur: konuşmayı metne çeviren ağda, nesne tanıyan ağda (ör. bin sınıflı) ya da Word2vec'te bütün bilgi ağırlıklardadır. Word2vec'te bir kelime girişte verilip çevresindeki kelimeler (skip-gram) ya da çevresi verilip ortadaki kelime (CBOW) tahmin edilir; sınıf sayısı sözlük boyutudur ve öğrenilen $W$ matrisinin satırları kelime vektörleridir.
- Çıkarım slaytında üç tür karşılaştırıldı. Tümdengelim, öncüller doğruysa kesin sonuç verir; abduction ($A \Rightarrow B$ biliniyor, $B$ görülüyor, büyük ihtimalle $A$) ve tümevarım (hep siyah top çıkıyor, büyük ihtimalle kutudaki tüm toplar siyah) olasılıklıdır. Bir öğrencinin sorusu üzerine hoca farkı yağmur örneğiyle açtı: yerler ıslak görülünce "yağmur yağmış" demek abduction'dır (olgu üretir); yağmur her yağdığında yerlerin ıslandığını görüp "yağmur yağınca yerler ıslanır" demek tümevarımdır (kural üretir).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
