# Ders 3 Çalışma Özeti

## Genel Konular

- Hayat bilgisi veri tabanlarının uygulama alanları (ekrandan, 00:05:40)
  - Slayttaki liste: sorgu zenginleştirme, metin sınıflandırma, soru cevaplama, metin anlama, otomatik çıkarım (Textual Entailment), uzman sistemler.
  - Sorgu zenginleştirme: kullanıcının tek sorgusundan hayat bilgisi veri tabanındaki bilgilerle birçok sorgu üretilir, hepsi ayrı ayrı gönderilir ve sonuçları birleştirilir.
  - Metin sınıflandırmada veri zenginleştirme (data augmentation): eğitim kümesi $X$ ise her örnekten yeni örnekler ($Y$) üretilir; yeni eğitim kümesi $X+Y$ olur. Yeni örnek, metindeki bilgiyle veri tabanındaki bilgi birlikte kullanılarak metnin başka bir hâle getirilmesiyle elde edilir.
  - Soru cevaplamada aynı fikir kaynak tarafına uygulanır: soru $S$, cevabın arandığı kaynak $K$ ise $K$ zenginleştirilebilir.
  - Metin anlama (reasoning / rationalize): ERASER veri kümesinde metnin sınıf etiketinin yanında, metnin o sınıfa girmesine sebep olan parça da işaretlenmiştir. Slayttaki örnek: "X in kalitesi iyi ama ücretleri çok fazla (-)" (ekrandan, 00:20:00). Burada "ücretleri çok fazla" olumsuz, "kalitesi iyi" olumlu parçadır.
  - Eğitim kümesinde geçen bir ifadenin test kümesinde eş anlamlısı geçebilir. Bu parçalar veri tabanı bilgisiyle genişletilerek eğitim kümesi büyütülebilir.
- Otomatik çıkarım: Textual Entailment (ekrandan, 00:20:00)
  - Örnek veri kümesi SNLI. Girişte 2 metin vardır; çıkış 3 sınıftan biridir: gerektirmek, mümkün değil, ilgisiz.
  - Gerektirmek: X doğru ise Y kesinlikle doğrudur. Mümkün değil: X doğru ise Y kesinlikle yanlıştır. İlgisiz: X ile Y bağımsızdır.
  - Metinler: A: "Bahçede top oynayan çocuklar var.", B: "Bahçede top oynayan insanlar var.", C: "Bahçede kimse yok.", D: "Hava çok güzel."
  - A-B gerektirmedir; B-C ve A-C mümkün değildir; A-D, B-D, C-D ilgisizdir.
  - Gerektirme simetrik değildir (A doğruysa B doğrudur, ama B doğruysa A kesin doğru değildir). Mümkün değil ve ilgisiz ilişkileri simetriktir.
  - A-B gerektirmesini görmek için "çocuklar insandır" hayat bilgisi gerekir; veri tabanı burada işe yarar.
- Bilgi çıkarımı (Information Extraction)
  - Önceden tanımlanmış ya da sistemin kendi bulduğu şablonlara uyan bilgileri metinden bulmaktır. Şablon kullanmak zorunlu değildir, başka yollarla da yapılabilir.
  - Slayttaki örnek: "21 yaşındaki inşaat işçisi Kazım Yaprak, evine dönerken para meselesi yüzünden tartıştığı arkadaşı Hilmi Bakır tarafından bıçaklanarak öldürüldü." metninden katil, kurban, sebep (para) ve suç aleti (bıçak) çıkarılır (ekrandan, 00:05:40, slayt önizlemesi).
  - Kazancı: metin yapılandırılmış (structured) hâle gelir; veri tabanında tutulabilir, sorgulanabilir, filtrelenebilir. Örneğin aynı kişinin işlediği olaylar ya da bir şehirdeki olayların sebepleri raporlanabilir.
- Otomatik bilgi çıkarımının temel metotları
  - Düzenli ifadeler (regex) kullanmak.
  - Yazım dilindeki şablonları kullanmak.
  - Öğelerine ayrılmış metinleri kullanmak.
  - Dinamik web sayfalarındaki tekrarlanan HTML etiketlerini kullanmak.
  - Morfolojik çözümlemelerdeki şablonları kullanmak.
- Düzenli ifadeler (ekrandan, 00:25:30)
  - Kullanıcının, insanların bir şeyi nasıl yazdığına dair uzman bilgisiyle kural yazmasıdır. Telefon numarası ve e-posta gibi standart biçimler için kolaydır.
  - Ev ilanlarında insanlar ilan ücreti yüzünden kısaltma kullanır ve okuyan anlasın diye standart kısaltmalara yönelir; bu kalıplar regex ile yakalanabilir.
  - Slayttaki örnek: belge "Capitol Hill- 1 br twnhme. D/W W/D. Pkg incl $675. 3BR upper flr no gar. $995." → çıkarılan veri `<Bedrooms: 1, Price: 675>`, `<Bedrooms: 3, Price: 995>`.
  - Kural: `* (<Digit>) 'BR' * '$' (<Nmb>)`, çıktı: `Rental {Bedrooms @1} {Price @2}`; `Bedroom ::= ( br || brs || bdrm || bedrooms || bedroom )`.
- Yazım dilindeki şablonlar (ekrandan, 00:30:00)
  - Amaç: istenen ilişki türü için şablonlar bulup büyük metinlerde bu şablonlara uyan çiftleri çıkarmak.
  - "X ve diğer Y'ler" şablonu "Tüm X'ler Y'dir" (IsA) ilişkisine karşılık gelir.
  - Arama sonuçlarından örnekler: ses kayıtları ve diğer multimedya içeriği, spor ve diğer aktiviteler, dergiler ve diğer periyodikler, sözleşmeler ve diğer hukuki belgeler doğrudur.
  - Hatalı sonuçlar: "çevre, gıda ve diğer mühendislikler"de kısaltma yüzünden "gıda bir mühendisliktir" çıkar; "güzel sanatlar ve diğer konular"da "güzel sanatlar" iki kelimedir; "Canon ve diğer lazer kartuşlar"dan "Canon bir lazer kartuşudur" gibi yanlış bir sonuç çıkar.
- Öğelerine ayrılmış metinler (ekrandan, 00:31:00)
  - Cümleler özne, yüklem, nesne, dolaylı tümleç, zarf tümleci gibi öğelere ayrılabiliyorsa, yüklemi "ye" olan cümlelerin nesneleri yenilebilir, "iç" olanlarınki içilebilir diye sınıflanabilir.
  - "Nerede yapılır" sorusu için ilgili fiilin dolaylı tümleçleri kullanılabilir.
  - Slayttaki arama sonuçlarında "yerken" kalıbıyla "döner yerken", "kraker yerken", "zeytin yerken", "mantar yerken" bulunmuştur. "Yerken" bir soyadı olarak da geçer; öğelere ayırma yapılınca bu fiil olarak çıkmayacağı için sorun olmaz.
  - "İçerken" ile su, zemzem, çay, kahve, sigara içerken gibi sonuçlar gelmiştir.
- Şablonların iki kriteri
  - Üretkenlik: şablonla üretilen bilgi miktarı.
  - Güvenilirlik: üretilen bilgilerin doğruluk oranı.
  - İkisi birbiriyle çelişir: çok bilgi üreten şablonun doğruluk oranı genelde düşüktür.
- Dinamik web sayfalarındaki HTML şablonları
  - Arkada veri tabanı kullanan sayfaların HTML kodu modülerdir; aynı yapılar sürekli tekrar eder (örneğin bir kitap listesi sayfası).
  - Belli etiketlerden sonra kitap adı, yazar, liste fiyatı, gerçek fiyat gelir. Bu, web crawling ve RPA tarzı işlerin temelidir.
  - Alışveriş ve haber toplama robotlarının adımları: her kaynak için bir bilgi çıkarım mekanizması kurulur; kullanıcı sorgusu alınır; her siteye sorgu gönderilip sonuç sayfası alınır ve o sitenin mekanizmasıyla işlenir; sonuçlar kaydedilir ya da sıralanır; HTML'e çevrilip kullanıcıya gösterilir.
  - Bu iş, veri tabanının içeriğini çıktılarına bakarak çıkarmak, yani bir tür tersine mühendisliktir. Firmalar iş birliği yaparsa HTML ayrıştırmak yerine API kullanılır. Çıkar çatışması varsa site, belli sürede eşikten fazla sorgu gelen IP'yi engelleme ya da sayfa yapısını değiştirme gibi önlemler alabilir.
- Morfolojik çözümlemelerdeki şablonlar: hocanın "Tüm X'ler Y'dir" çalışması (Amasyalı, 2005)
  - Adımlar: ilişki türü belirlenir; bilinen X, Y ikilileri (seed, 50-60 tane) Google'da aratılır; X ile Y arasındaki şablonlar ve frekansları çıkarılır; en yüksek frekanslı şablonlar ilişkinin şablonları olur.
  - "Tüm X'ler Y'dir" için bulunan şablonlar (ekrandan, 00:39:30): ve diğer, ler ve diğer, ve benzeri, veya diğer, türü olan, ları ve diğer, lar ve diğer, ve her türlü, lerden biri olan, leri ve diğer, larından biri olan, lerinden biri olan, lardan biri olan, adı olan, ve her tür.
  - "X'in yeri Y'dir" için bulunan şablonlar (ekrandan, 00:40:00): y deki x, y de bulunan x, y de x, x y de, x y ili sınırları içerisindedir, y ili sınırlarında kalan x, x/y, x-y, x, y, x(y) vb.
  - Sonra şablonlar aratılır, sonuç sayfalarında şablonun sağındaki ve solundaki kelimeler alınır. Bulunan ikililer (ekrandan, 00:42:10): kontrolör-personel, teçhizat-malzeme, kemer-teçhizat, protein-gıda, komünizm-ideoloji doğru; delta-Gediz, kurum-Kocaelispor, fotoğrafçı-Robert gibi hatalılar da var.
  - Bulunan ikililer elle "uyar / uymaz" diye etiketlenir. Ek türleri ve şablon türü özellik olarak alınıp her örnek 107 boyutlu bir uzaya çevrilir ve sınıflandırıcı eğitilir. Örnek çözümleme (ekrandan, 00:43:40): "adamlarından biri olan OZAN" → adam: `Noun+A3pl+P3sg+Abl`, OZAN: `Noun+A3sg+Pnon+Nom`; "dualar ve her türlü ibadet" → dua: `Noun+A3pl+Pnon+Nom`, ibadet: `Noun+A3sg+Pnon+Nom`.
  - Frekans kullanımı: sınıflandırma başarısı %100 olmadığından frekans gereklidir. Bir ikilinin kaç kez ve kaç farklı şablondan bulunduğu güvenilirlik ölçüsüdür.
  - Zayıf yönler: birden fazla kelimelik gruplar arasındaki ilişkiler bu yöntemle bulunamaz ("ses kayıtları", "güzel sanatlar", "hukuki belgeler" bütün olarak alınmalı). Her ilişki türüne uygulanamaz; zıt anlamlılık, eş anlamlılık, sebep-sonuç gibi ilişkilerin şablonlarını bulmak zordur.
- Güncel yönler
  - Allen Institute for AI (AI2) Alexandria girişimi (2018): hayat bilgisini metnin yanında görüntüden de toplamaya çalışır.
  - Soru cevaplama ve reasoning yapan derin öğrenme modelleri ConceptNet gibi veri tabanlarından gerekli bilgiyi çekip (retrieve) kullanmaya çalışır. Gerekli bilgiyi doğru çekmek kritik bir adımdır.
- İstatistiksel dil modelleri: kullanım alanları (ekrandan, 01:10:00)
  - Bir cümlenin, kelime dizisinin ya da tek kelimenin olasılığını bulmak için kullanılır.
  - Makine çevirisi: P(taze balık aldım) > P(yeni balık aldım).
  - Yazım düzeltimi: "Ali soan yedi" için P(ali soğan yedi) > P(ali sokan yedi). İki aday da geçerli kelimedir ve düzeltme uzaklıkları aynıdır; seçimi olasılık yapar.
  - Konuşmadan metne: P(soğan yedim) > P(sol an yedim).
- Dil modelinin iki amacı ve zincir kuralı (ekrandan, 01:20:00)
  - Amaç 1: cümle olasılığı $P(W)=P(w_1,w_2,\dots,w_n)$. Amaç 2: bir diziden sonraki kelimenin olasılığı, ör. $P(w_5 \mid w_1,w_2,w_3,w_4)$.
  - Zincir kuralı: $P(w_1,\dots,w_n)=P(w_1)P(w_2\mid w_1)P(w_3\mid w_1,w_2)\cdots P(w_n\mid w_1,\dots,w_{n-1})$.
  - Örnek: P(ali, okuldan, buraya, geldi) = P(ali) · P(okuldan|ali) · P(buraya|ali, okuldan) · P(geldi|ali, okuldan, buraya).
  - Bir olasılık: $P(\text{geldi}\mid\text{ali okuldan buraya})=\dfrac{fr(\text{ali okuldan buraya geldi})}{fr(\text{ali okuldan buraya})}$. Pay hiçbir zaman paydadan büyük olamaz, sonuç 0 ile 1 arasındadır.
  - Sorun: güvenilir değerler için yeterli büyüklükte derlem olmaz. Dil, ayrık uzayda çok seyrek olduğundan çoğu frekans 0 çıkar.
- Markov varsayımı (ekrandan, 01:16:50)
  - Her olasılık kendinden önceki $k$ bileşene bağlıdır.
  - $k=0$: her olasılık bağımsızdır. $P(w_1,w_2,w_3,w_4)=P(w_1)P(w_2)P(w_3)P(w_4)$; P(geldi|ali, okuldan, buraya) = P(geldi).
  - $k=1$: her olasılık yalnız bir öncekine bağlıdır. P(geldi|ali, okuldan, buraya) = P(geldi|buraya).
  - $k=2$: bir ve iki öncekine bağlıdır. P(geldi|ali, okuldan, buraya) = P(geldi|okuldan, buraya).
  - Avantaj: daha az işlem, daha az seyrek veri. Dezavantaj: dil uzun bağımlılıklar içerir; $k$'dan uzaktaki bağımlılıklar hesaba katılamaz.
  - Uzun bağımlılık örneği: "Çin'e yaptığım ziyarette ... çok uğraştım ama bir türlü Çinceyi öğrenemedim." "Çinceyi" kelimesi çok önceki "Çin'e" kelimesine bağlıdır.
  - $k=0$ iyi bir seçim değildir: $P(A,B,C,D)=P(B,A,C,D)$ olur, yani sıra hiç önemsenmez.
- Bigram örneği: 1000 ekonomi haberi (ekrandan, 01:35:00)
  - 5'ten az geçen kelimeler silinince yaklaşık 8K × 8K'lık bir "A'dan sonra B kaç kez geçti" matrisi oluşur. 64 milyon hücreden yalnız yaklaşık 140 bini sıfır değildir; yalnız ikililerde bile veri çok seyrektir.
  - En sık takipçiler: "ekonomi"den sonra bakanı, ve, ligi, bakanlığı, bankası; "para"dan sonra politikası, cezası, ve, birimlerinin; "çok"tan sonra önemli, daha, büyük, sayıda, iyi.
  - Bigram modelinde cümle olasılığı (ekrandan, 01:37:40): P(fuar otomotiv sektörüne önemli bir hareket getirdi) = P(otomotiv|fuar) · P(sektörüne|otomotiv) · P(önemli|sektörüne) · P(bir|önemli) · P(hareket|bir) · P(getirdi|hareket); $P(w_i\mid w_{i-1})=fr(w_{i-1},w_i)/fr(w_{i-1})$. Log olasılık −21.2067.
  - Log alınınca çarpma toplamaya döner ve çok küçük sayılarla uğraşılmaz.
- Sıfırlarla başa çıkmak: smoothing (ekrandan, 01:40:00)
  - "fuar otomotiv sektörüne önemli iki hareket getirdi" için log olasılık −INF çıkar, çünkü bir ikilinin frekansı 0'dır.
  - Add-one estimation = Laplace smoothing: $P_{LS}(w_i\mid w_{i-1})=\dfrac{fr(w_{i-1},w_i)+1}{fr(w_{i-1})+V}$, $V$ sözlükteki kelime sayısıdır.
  - Smoothing ile "bir hareket" cümlesi −44, "iki hareket" cümlesi −49 olur; ilki daha olasıdır.
- En olası dizilişi bulmak (ekrandan, 01:41:20)
  - Kelimeler önemli, hareket, bir; 6 diziliş vardır. En olası: P_LS(önemli bir hareket) = −11.8570.
  - $n$ kelime için $n!$ diziliş vardır; 20 kelimede hepsini denemek pratikte imkânsızdır. Kelime kelime, ikili ikili, üçlü üçlü değerlendirip olasılığı düşük adayları eleyerek ilerlemek optimum olmasa da yeterince iyi bir çözümdür.
- Dil modellerini değerlendirmek (ekrandan, 01:50:00)
  - Harici yöntem: iki modeli makine çevirisi, yazım düzeltimi, konuşmadan metne gibi görevlerde kullanıp performansla karşılaştırmak.
  - Dahili yöntem: derlemi eğitim ve test kümesine ayır, modelleri eğitimde oluştur. Test cümlelerine daha yüksek olasılık veren, ya da cümle başı verildiğinde sonunu daha doğru tahmin eden model daha iyidir. Saçma cümlelere düşük olasılık vermesi beklenir.
  - Eğitim ve test kümeleri ayrık olmalıdır. Sosyal medya derlemlerinde aynı cümle çok tekrarlandığı için rastgele bölme yanıltıcı olabilir.
- Dil modeliyle metin üretimi (ekrandan, 02:00:00)
  - Bir başlangıç kelimesi verilir, model sonraki kelimeyi üretir, üretilen eklenir ve süreç tekrarlanır. Cümle sonu belirteci ya da istenen uzunluk durma koşuludur.
  - Her zaman en olası kelime seçilirse bir kelimeden sonra hep aynı kelime gelir. Çözüm: en yüksek olasılıklı $t$ taneden birini rastgele seçmek ya da bütün kelimeler arasından olasılığa göre seçmek (Shannon Game).
  - Bigram (K=1), t=5 ile 1000 ekonomi haberinden üretilen metinlerde ardışık ikililer anlamlı, ardışık üçlüler anlamsızdır ("yer aldığı bilgiye", "yüzde 10 yılda").
  - Trigram (K=2), t=5 ile ardışık üçlüler daha anlamlı olur (ekrandan, 02:00:30).

## Hocanın Özellikle Vurguladığı Kısımlar

- Şablonlarda üretkenlik ile güvenilirlik ters orantılıdır
  - "x-y" gibi genel bir şablon "y'de bulunan x"ten çok daha fazla sonuç getirir, ama gelenlerin ilişkiye uyma oranı düşer.
- Bilgi çıkarımı metni yapılandırılmış hâle getirir
  - Kazanç, metnin veri tabanında sorgulanabilir ve filtrelenebilir olmasıdır.
- Markov varsayımında $k$ seçimi bir ikilemdir
  - Küçük $k$: az işlem, az seyreklik, ama uzun bağımlılıklar kaçar. Büyük $k$: bağlam artar, ama veri seyrekleşir.
  - $k=0$ sırayı yok saydığı için değerlendirmede ve üretimde kötü sonuç verir.
- Tek bir sıfır olasılık bütün çarpımı sıfırlar
  - Bu yüzden smoothing gerekir; add-one (Laplace) en basit yoldur.
- Değerlendirmede eğitim ve test kümeleri ayrık olmalıdır
  - Hoca bunu, sınav sorularını önceden veren öğretmen benzetmesiyle anlattı: herkes 100 alsa da öğrencilerin konuyu anladığı söylenemez, ezberlemiş olabilirler. 1-en yakın komşu algoritması eğitimdeki örneklerle test edilirse %100 başarı verir, ama bu gerçek dünyadaki başarıyı göstermez.
- Mühendislik, yeterince iyi çözümler geliştirme sanatıdır
  - 20 kelimeyi sıraya dizmek gibi problemlerde optimum çözüm yerine eleme ile yeterince iyi çözüm aranır.
- Fikir üretmek önemlidir, ama fikri gerçekleyip sonuçla göstermek gerekir.

## Kısa Tekrar Notları

- Hayat bilgisi uygulamaları: sorgu zenginleştirme, veri zenginleştirme ($X+Y$), soru cevaplama, metin anlama (ERASER), textual entailment (SNLI), uzman sistemler.
- Textual entailment sınıfları: gerektirmek (simetrik değil), mümkün değil (simetrik), ilgisiz (simetrik).
- Bilgi çıkarımı yöntemleri: regex, yazım dili şablonları, öğelere ayırma, HTML şablonları, morfolojik şablonlar.
- "X ve diğer Y'ler" → "Tüm X'ler Y'dir".
- Şablon kriterleri: üretkenlik ve güvenilirlik, ters ilişkili.
- Seed ikililer → şablon bulma → şablonla yeni ikililer → elle etiketleme → morfolojik özelliklerle (107 boyut) sınıflandırma → frekans.
- Zincir kuralı: $P(w_1..w_n)=\prod_i P(w_i\mid w_1..w_{i-1})$.
- Markov: her olasılık önceki $k$ bileşene bağlı; $k=1$ bigram, $k=2$ trigram.
- 8K × 8K bigram matrisinde 64M hücreden ~140K'si sıfır değil.
- Laplace: $(fr(w_{i-1},w_i)+1)/(fr(w_{i-1})+V)$.
- $n$ kelimenin $n!$ dizilişi var.
- Değerlendirme: harici (görev performansı) ve dahili (test olasılığı).
- Metin üretimi: en olası $t$ taneden rastgele seçim ya da olasılıkla seçim (Shannon Game).

## Detaylı Açıklamalar

### Textual entailment ve hayat bilgisi

Textual entailment, iki metin arasındaki ilişkiyi üç sınıftan birine atama görevidir. SNLI gibi veri kümelerinde her örnek iki metin ve bir etiketten oluşur. "Bahçede top oynayan çocuklar var" doğruysa "Bahçede top oynayan insanlar var" kesinlikle doğrudur; bu gerektirmedir. Tersi geçerli değildir, çünkü top oynayan insanlar çocuk olmayabilir. "Bahçede kimse yok" ise ilk iki metinle aynı anda doğru olamaz; bu "mümkün değil" sınıfıdır. "Hava çok güzel" diğerlerinden bağımsızdır. Gerektirmeyi tanımak için "çocuk bir insandır" gibi bir hayat bilgisine ihtiyaç vardır; hayat bilgisi veri tabanları bu tür bilgiyi sağlar.

Ders sonrası not: Slaytta "Mümkün değil" satırında örnek olarak "(A-B, B-C)" yazıyor (ekrandan, 00:20:00). A-B gerektirme örneğidir; hoca ve bir öğrenci mümkün değil için B-C ve A-C'yi verdi. Slayttaki "A-B" büyük olasılıkla yazım hatasıdır.

### Şablon tabanlı bilgi çıkarımı

Yazım dilindeki şablonlarda asıl zorluk iyi şablonu bulmaktır. "Ve diğer" akla gelir, ama her ilişki türü için ayrı şablonlar gerekir. Hocanın çalışmasında bu iş otomatikleştirilmiştir: bilinen 50-60 ikili (seed) aratılır, ikililerin arasında en sık geçen ifadeler şablon olarak seçilir. Sonra bu şablonlar aratılarak seed'de olmayan yeni ikililer bulunur.

Şablonun üretkenliği arttıkça güvenilirliği düşer. "Y'de bulunan x" dar ama güvenilir bir şablondur; "x-y" ya da "x, y" çok sonuç getirir ama gelenlerin çoğu ilişkiye uymaz. Bulunan ikililer elle etiketlenip morfolojik çözümleme özellikleriyle bir sınıflandırıcı eğitilmiştir. Sınıflandırıcı hatasız olmadığından ikililerin kaç kez ve kaç farklı şablonla bulunduğu da kullanılır; çok sayfa işlenip çok kez bulunan ikililer daha güvenilirdir.

### İstatistiksel dil modelleri ve Markov varsayımı

Zincir kuralıyla bir cümlenin olasılığı, her kelimenin kendinden önceki bütün kelimelere koşullu olasılıklarının çarpımıdır. Bu koşullu olasılıklar frekans oranlarıyla bulunur, ama uzun diziler derlemde neredeyse hiç geçmez; pay da payda da sıfır olabilir. Markov varsayımı her kelimenin yalnız önceki $k$ kelimeye bağlı olduğunu kabul ederek dizileri kısaltır. Böylece arama yapılan diziler en fazla $k+1$ uzunluğunda olur, işlem azalır ve seyreklik düşer. Bedeli, $k$'dan uzaktaki bağımlılıkların kaybolmasıdır.

Bir öğrenci, son $k$ kelime yerine cümlenin başından, ortasından ve sonundan belli aralıklarla kelime almayı önerdi. Hoca, bu durumda arada kalan yakın kelimelerin (örneğin hemen önceki kelimenin) etkisinin kaybolacağını söyledi. Ardından şu biçimi önerdi: hedefe yakın kelimelerden sık, uzaktakilerden seyrek örnek almak, yani uzaklığa bağlı örnekleme. Hoca böyle bir yönteme rastlamadığını, denenebileceğini söyledi. Ayrıca dil modelinin olasılıkları önceden hesaplanıp tablolarda tutulduğu için $k$'nın cümleden cümleye değişemeyeceğini belirtti.

### Smoothing

Bigram modelinde test cümlesindeki tek bir ikili derlemde hiç geçmemişse olasılık 0, log olasılık −INF olur. Add-one (Laplace) smoothing her ikili frekansına 1 ekler, paydaya da sözlük boyutu $V$'yi ekler. Böylece hiçbir olasılık 0 olmaz ve cümleler karşılaştırılabilir hâle gelir: "önemli bir hareket" (−44) cümlesi "önemli iki hareket" (−49) cümlesinden daha olasıdır.

Ders sonrası not: Slayttaki tablodaki değerlerle (1/18, 4/78, 1/35, 162/560, 4/3940, 1/42) doğal logaritma toplamı yaklaşık −21.29 çıkar (python ile hesaplandı). Slaytta −21.2067 yazıyor. Fark büyük olasılıkla tablodaki bir frekansın yuvarlanmasından ya da tablonun kodun çıktısından elle aktarılmasından gelir. Logaritma tabanı doğal logaritmadır (10 tabanında toplam yaklaşık −9.24 olurdu). Bu yüzden hocanın "log almadan değer $10^{-21}$ civarı" sözü büyük olasılıkla yanlıştır; değer $e^{-21.2}\approx 6\times10^{-10}$ civarındadır.

Ders sonrası not: Bigram cümle olasılığında slayt ilk terim $P(\text{fuar})$'ı yazmıyor. Hoca bunu, cümle başı olasılığının eklenebileceğini ama burada eklenmediğini söyleyerek açıkladı. Benzer biçimde $k=1$ slaytında $P(w_1,w_2,w_3,w_4)=P(w_2\mid w_1)P(w_3\mid w_2)P(w_4\mid w_3)$ yazıyor (ekrandan, 01:16:50); tam ifade başta $P(w_1)$ çarpanını da içerir.

### En olası dizilişi bulmak ve metin üretimi

Dil modeli verilen kelimelerden cümle kurmak için de kullanılabilir: bütün dizilişlerin olasılığı hesaplanır, en yükseği seçilir. 3 kelimede 6 diziliş kolayca denenir, ama 20 kelimede $20!\approx 2.4\times10^{18}$ diziliş vardır. Derste öneriler konuşuldu: fiili sona sabitlemek, kelimeleri öğe türlerine göre gruplamak, ve Markov varsayımından yararlanıp önce tek kelimeleri, sonra ikilileri, sonra üçlüleri değerlendirerek düşük olasılıklı adayları elemek. Sonuncusu optimum değildir, ama yeterince iyi bir çözümdür.

Metin üretiminde model her adımda sonraki kelimeyi tahmin eder ve tahmin metne eklenir. Hep en olası kelime seçilirse aynı kalıplar döngüye girer. Bu yüzden en olası $t$ kelimeden biri rastgele seçilir; $t$ küçüldükçe derlemden kopya çekme olasılığı artar. $k$ büyüdükçe ardışık kelimeler daha anlamlı olur. <!-- BELİRSİZ: Hoca 02:00:57 civarında k artırıldığında üretimin nasıl etkileneceğini anlatırken ("en yüksek olasılıklı şeyler çok aşırı derecede nadirleşecekler... tekrarlı yapıları çok fazla görmeye başlayacaksınız") cümle altyazıda bozuk; tam iddia net değil. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
