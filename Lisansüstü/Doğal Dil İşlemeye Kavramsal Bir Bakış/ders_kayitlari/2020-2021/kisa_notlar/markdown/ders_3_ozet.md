# Ders 3 Çalışma Özeti

## Genel Konular

- Dilbiliminin esasları (hızlı tekrar): sözlük (lexicon), gram kavramı, dil analizinin altı seviyesi.
- NLP'de kullanılan model türleri.
- Ses bilimi (phonology), fonetik diller ve fonetik alfabe.
- Biçim bilim (morphology): çekim ve yapım ekleri, kök ve gövde (lemma), biçimbirim (morpheme) ve biçimcik (allomorph), biçimbirim türleri.
- Biçimbilimsel analizde belirsizlik ve bağlılık analizi (dependency parsing) ihtiyacı.
- Dağılıma bakarak biçimbirim bulma: Svahili örneği.
- "ki"nin üç türü, ünlü uyumu ve kural dışı durumlar, fiil çatıları.
- Gramer ve diller: gramerin dörtlü tanımı, Chomsky hiyerarşisi (Tür 0 - Tür 3).
- Türetme (derivation), yukarıdan aşağı (top-down) ve aşağıdan yukarı (bottom-up) ayrıştırma.
- Gerçek dil örnekleri üzerinde ayrıştırma ve genişletilmiş geçiş ağları (Augmented Transition Network, ATN).

## Hocanın Özellikle Vurguladığı Kısımlar

- Doğal dille çalışmak için iki şey şarttır: kelimeler (sözlük, yani leksikon) ve dile özgü kurallar (gramer).
- "Gram" ağırlık birimi değildir. Dilde bölünebilen en küçük parça demektir. Dil modellerinde gram kelime de olabilir karakter de: kelime tabanlı ve karakter tabanlı n-gram.
- Biçimbilimsel analiz araçları bir kelimenin bütün olası çözümlerini verir ama cümlede hangisinin doğru olduğunu söylemez. Doğru çözümü seçmek için bağlılık analizi gerekir.
  - Yalnızca kökün kaç kez geçtiğini saymak yetiyorsa ilk çözümü almak yeterlidir.
  - Cümlenin söz dizimsel yapısı kullanılacaksa doğru çözüm bilinmelidir.
- Bir kelime sözlükte varsa onun gövdesi (lemma) alınmalı, köküne kadar inilmemeli. "gözlük" kelimesini "göz" diye işlemek uygulamaya göre hataya yol açabilir.
- Türkçe NLP çalışmaları geç başladı ve herkes bağımsız çalıştı. Herkes kendi veri setini baştan oluşturuyor; çalışmalar bir araya getirilmiyor.
- Chomsky hiyerarşisinde dıştan içe gidildikçe kurallar ve kısıtlar artar. En dıştaki Tür 0 kuralsızdır, en içteki Tür 3 (düzenli diller) en katıdır.
- Yukarıdan aşağı ayrıştırma her zaman daha kolaydır. Zor olan aşağıdan yukarı gitmektir.
- Bir kelime belirsizse (ambiguous) ayrıştırma her türüyle denenmelidir. İlk denemede tıkanıp durulursa yanlış söz dizim analizi yapılmış olur.
- Ayrıştırmada etiketler dünyada standarttır (NP, VP, DET, AUX...). Kendi uydurduğunuz etiketleri kullanmayın.

## Kısa Tekrar Notları

- Türk kültüründeki ilk sözlük: Divânu Lugâti't-Türk (Türkçeden Arapçaya).
- Dil analizinin seviyeleri: fonoloji, morfoloji, sentaks, semantik, söylem (discourse), edim (pragmatics).
- NLP'de kullanılan modeller:
  - Sonlu durum makineleri (finite state machine): klasik biçimbilimsel analizde hep vardır.
  - Kural tabanlı sistemler.
  - Mantık (logic) kullanan sistemler.
  - Olasılık teorisi kullanan sistemler: dil modelleri tamamen buna dayanır.
  - Makine öğrenmesi: az veriyle de başarılı sonuç verir.
  - Derin öğrenme: çok veri ve donanım ister.
- Fonetik dil: yazıldığı gibi okunan dil; her sese bir sembol karşılık gelir. Örnekler: Türkçe, Japonca, Fince.
- Fonetik alfabe: harf harf söylerken her harf için kullanılan kelimeler (NATO alfabesi, Türkiye'de kullanılan alfabe).
- Çekim ekleri kelimenin anlamını değiştirmez, yapım ekleri değiştirir.
- Biçimbirim (morpheme): anlamı olan en küçük birim. Süslü parantezle gösterilir: {AcAk}.
- Biçimcik (allomorph): biçimbirimin gerçekleşen biçimi. Köşeli parantezle gösterilir: [acak], [ecek].
- Gramer dörtlüsü: $G = \langle V_N, V_T, P, S \rangle$.
- Chomsky hiyerarşisi:

| Tür | Adı | Kural kısıtı |
|---|---|---|
| Tür 0 | Özyinelemeli sayılabilir (recursively enumerable), kısıtlamasız | $\alpha \rightarrow \beta$, $\alpha \in V^+$, $\beta \in V^*$ |
| Tür 1 | Bağlama bağımlı (context-sensitive) | Ek olarak $\lvert\alpha\rvert \le \lvert\beta\rvert$ |
| Tür 2 | Bağlamdan bağımsız (context-free) | Sol tarafta tek bir söz dizimsel değişken |
| Tür 3 | Düzenli (regular) | Sağ taraf: boş, bir uç değişken veya uç değişken + söz dizimsel değişken |

- Programlama dilleri bağlamdan bağımsızdır. Düzenli ifadeler (regular expression, regex) düzenli dillere karşılık gelir.

## Detaylı Açıklamalar

### Dersin Başı ve Duyurular

- 15 Ekim 2020 haftasında ders yapılmadı. Hoca bu derse "geçen hafta sempozyuma katılan oldu mu?" diye başladı. Sempozyuma katılan bir öğrenciye bonus verdi.
- Gelecek ders düzenli ifadeler anlatılacak ve onlarla ilgili küçük bir ödev verilecek.
  - Sisteme ödev yükleme modülü eklenirse ödevler oradan yüklenecek, eklenmezse e-postayla gönderilecek.
- Slaytlar hocanın AVESİS sayfasında "Duyurular / Paylaşımlar" kısmında. Yalnızca anlatılmış slaytları indirin; diğerleri güncellenebilir.

### Sözlük, Gram ve Dil Analizinin Seviyeleri

- Leksikon: sözlük. İhtiyaca göre yalnızca isimlerden, yalnızca fiillerden veya yalnızca eklerden oluşan leksikonlar kullanılır.
- Gram: Arapçadaki "sarf ve nahiv" ilmiyle ilişkili, Batı dillerinde "gram". Bir dokümanın en küçük birimi kelimedir; kelime de karakterlerden oluşur. Bu yüzden gram ya kelime ya karakter olarak alınır.
- Seviyeler (tekrar):
  - Fonoloji: dilin ses özellikleri. Her karakterin bir frekansı vardır; konuşmadan metne çevirme bu frekanslardan karakteri bulur. Derste pek girilmeyecek.
  - Morfoloji: kelimenin kökü ve eklenebilecek ekler. Zemberek gibi araçlar bu bilgiyi verir.
  - Sentaks: tümcenin o dile ait olup olmadığı. "Kitap kuş petrol araba." Kelimeler Türkçe ama tümce değil.
  - Semantik: tümcenin anlamı. Kim, ne, nerede, neden sorularının cevabı alınabilmeli. Birlikte kullanılan söz öbekleri de yakalanmalı: "Yıldız Teknik Üniversitesi" ayrı ayrı "yıldız", "teknik", "üniversite" olarak değerlendirilirse anlam bozulur.
  - Söylem: bağlam. "Eşyalarını, paralarını sakladı." tek başına cimriliği anlatır gibi görünür. Metnin bütününde savaş anında eşyaların gasp edilmesin diye saklandığı anlaşılabilir.
  - Edim: metin dışı bilgi. Ev sahibi-kiracı örneğinde evcil hayvanın hoş karşılanmaması metinde olmayan, dışarıdan verilmesi gereken bir bilgidir. Kira artış oranı da ev sahibine göre normal, kiracıya göre olumsuz olabilir.
- Bütün bu seviyeleri bir arada kullanan eksiksiz bir NLP çalışması henüz yok. Söylem ve edim üzerinde yeni yeni çalışılıyor.

### NLP'de Kullanılan Modeller

- Sonlu durum makineleri: klasik biçimbilimsel analizde kullanılır. Son zamanlarda yerine derin öğrenme modelleri de denenmeye başlandı.
- Kural tabanlı sistemler: kurallar önceden çıkarılır, sırayla "bu kurala uydu mu" diye kontrol edilir.
- Makine öğrenmesi ve derin öğrenme farkı:
  - Makine öğrenmesi az veriyle de başarılı sonuç verir.
  - Derin öğrenmede aynı veriyle aynı sonuç alınamayabilir; çok veri ve çok parametre gerekir.
  - Bireysel donanım yetersiz kaldığı için gizli katman (hidden layer) sayısı ve veri miktarı artırılamaz, başarı düşük kalabilir.

### Ses Bilimi ve Fonetik

- Ses birimine fon denir. Girişe akustik bir işaret verilir, alfabedeki karakter karşılığı alınır.
- Bazı dillerde iki karakter yan yana gelince farklı okunur. Bu diller fonetik değildir.
- Fonetik alfabe: telefonda veya şive yüzünden anlaşılmayan kelimeyi harf harf söylerken kullanılır. Hoca "Ü için Ünye" gibi seçimleri garip buluyor; "üzüm" daha anlamlı olurdu.
- Bir öğrencinin sorusu (iş yerindeki konuşma tanıma projesi): Türkçeye giren yabancı kelimelerin ("transfer", "profesyonel") ve "geliyorum / gelecem" gibi söyleyişlerin fonem varyasyonları nasıl otomatik çıkarılır?
  - Öğrenci SAMPA adlı fonetik gösterimi ve kural tabanlı bir yöntem kullanıyor.
  - Hocanın önerileri:
    - Dil bilimcilerle çalışın. İstanbul Üniversitesi'nin dil bilimi bölümünden bir araştırma görevlisiyle iletişime geçilebilir.
    - Türkçede ekler ayrıldıktan sonra gövdede iki sessiz harfin yan yana geldiği kelime azdır. Bunlar çıkarılıp bunlara özel kurallar yazılabilir. Türkçe heceleme 8-9 kurala dayanır; "profesyonel" gibi kelimeler için ek kural gerekir.
    - İstatistiksel yaklaşım: büyük bir derlemden kelime ve karakter n-gram istatistikleri çıkarılır, saklı Markov modelleri (Hidden Markov Model) kullanılır. Kelime başında "pr" gelme olasılığı Türkçede çok düşüktür; olasılığı düşük bir geçiş sorun olduğunu gösterir.
    - Dil modeli bağlama bakarak "Ben yarın okula ..." cümlesinde hangi kelimenin gelebileceğini söyler, yanlış kelimeyi düzeltmeye yardım eder.

### Biçim Bilim (Morphology)

- Ortografik kelimeler: aynı anlam farklı yazımlarla verilebilir. "Ayşe gelmişti" ve "Ayşe gelmiş idi", "arabayla" ve "araba ile".
- Türkçe bitişken (agglutinative) bir dildir. Slayttaki zorlanarak üretilmiş bir kelimede 11 ek var. Günlük hayatta bir kelimede en fazla 4-5 ek kullanılır.
- İngilizcede ekleri ayırmak kolaydır ("-s", "-ing", "-ed"). Sondan eklemeli dillerde çok daha zordur.
- Birleşik kelimeler de çözülmesi gereken bir problemdir.

#### Ekler

- Çekim ekleri (anlamı değiştirmez):
  - İsim çekim ekleri:
    - Çoğul eki: kitaplar, çocuklar.
    - Hal ekleri: kalemi verdik, duvara bak.
    - İyelik ekleri (sahiplik): kitabım, kitabın, kitabımız.
    - İlgi (tamlama) ekleri "-ın, -in, -un, -ün": kapının kolu.
    - Ek eylem: isim soylu kelimeyi yüklem yapar. "Nasılsın?" "İyiyim."
  - Fiil çekim ekleri:
    - Zaman ekleri: gelmiş, okudu.
    - Dilek (kip) ekleri: şart "gidersem", gereklilik "gitmeliyim".
    - Şahıs ekleri: geliyorum, geliyorsun.
- Yapım ekleri (anlamı değiştirir):
  - İsimden isim: kömür + lük = kömürlük.
  - İsimden fiil: su + la = sula.
  - Fiilden isim: düşün + ce = düşünce.
  - Fiilden fiil: gül + dür = güldür.
- Bu ekler neden önemli? Biçimbilimsel analiz kökü ve ekleri etiketleriyle verir ("-lar" çoğul, "-dı" geçmiş zaman). Anlamsal analizde "bu olay geçmişte olmuş", "kol, kapının bir özelliği" gibi çıkarımlar bu etiketlerle yapılır.

#### Belirsizlik ve Bağlılık Analizi

- Üç cümle:
  - "Bunlar Ahmet'in kitapları."
  - "Kardeşimin kitaplarını kaplamalıyım."
  - "Ahmet kitapları okudu."
- Kök hep "kitap" ama çözümleme cümleye göre değişir: çoğul + 3. tekil iyelik; çoğul + iyelik "-ını"; çoğul + belirtme hâli.
- Araç "kitapları" kelimesi için bütün çözümleri verir ve dilde en sık görüleni (milyonlarca cümleden çıkarılmış istatistiğe göre) ilk sıraya koyar.
- Bağlılık analizi kullandığımız araçlarda yok. ODTÜ'de ve Boğaziçi'nde akademik çalışmalar var; Boğaziçi'ndeki hocalardan istenince verilebiliyor.
- İTÜ'deki boru hattı biçimbilimsel analiz, söz dizim analizi, varlık ismi çıkarımı ve bağlılık analizini yapar. Yalnızca web üzerinden ve akademik kullanım izniyle açılır; yavaş olduğu için pek tercih edilmez.
- Geçen haftaki sempozyumda, bir firmada çalışan mezunlar bir Türkçe ağaç bankası (treebank) sunmuş:
  - Binlerce Türkçe cümlenin bağlılık ilişkileri elle etiketlenmiş ("Bunlar Ahmet'in kitapları": "bunlar" kitapları gösterir, kitaplar Ahmet'indir).
  - Çift kör etiketleme yapılmış: birinin etiketlediğini diğeri kontrol ediyor.
  - Açık olarak paylaşılıyor; sistem eğitmek için çok faydalı bir girdi.
- Bir başka belirsizlik: "gider".
  - "Bu gider tablosu çok detaylı hazırlanmıştır." Burada isim; "gider tablosu" bir birleşik isim (söz öbeği).
  - "Ayşe her gün okula gider." Burada zaman eki almış fiil.
  - Konum ipucu: cümle başında ve isimden önce geliyorsa fiil olamaz; cümle sonunda yüklemse fiildir.
- Çalışmaların çoğu ilk çözümü alır. Herkes aynı şeyi yaptığı için aynı veri setinde sonuçlar kıyaslanabilir.

#### Kök, Gövde ve Ölü Kökler

- Kök (root) ve gövde (lemma). Gövdeye indirgemeye lemmatization denir.
- "gözlük" kökü "göz" olsa da sözlükte "gözlük" ayrı bir kelimedir (göze takılan araç). Gövde hâli alınmalı.
- "kayak" örneği: "kaya" da, "kay" da, "ka" da bir anlam taşıyabilir. Nereye kadar inileceği belirsizdir. Sözlükte "kayak" varsa "kayak" alınır.
- Ölü kökler: kullanılmadığı için unutulmuş kökler.
  - "çalış" eskiden "çal" fiilinden gelir: kerpiç evlerde çamuru duvara atma işine "çalma" denirmiş (Nasreddin Hoca'nın göle maya çalması gibi).
  - "öğre" (öğrenmek, öğrenci) ve "nite" (nitel, nitelik) kökleri de bugün kullanılmıyor.

#### Sözcük Birim ve Sözcük Biçim

- Sözcük birim (lexeme): kelimenin kendisi. Sözcük biçim (word form): ek almış hâli.
- Türkçede "ev" kelimesinin bütün biçimlerinde evden türediği kolayca anlaşılır.
- İngilizcede "go, goes, going, gone" kolay anlaşılır ama "went" go'dan türediği görülmeyen bir biçimdir. Bu yüzden İngilizce çalışmalarda düzenli ve düzensiz fiiller ayrı leksikonlarda tutulur.
- Yanlış yazılan kelimeler dil modelleriyle düzeltilebilir. Arama motorlarının "Bunu mu demek istediniz?" önerisi arkada n-gram dil modellerini kullanır.
- OCR örneği: Kağıt kalitesi yüzünden "gelecek" kelimesi "getecek" olarak çıktı. Türkçede "getecek" diye bir kelime yok.
  - Kelime tabanlı model: önceki ve sonraki kelimelere bakarak doğru kelimeyi önerir.
  - Karakter tabanlı model: önceki ve sonraki harflere bakarak "t" yerine "l" gelmesi gerektiğini söyler.

#### Dağılıma Bakarak Biçimbirim Bulma: Svahili Örneği

- Svahili (Doğu Afrika dili) hiç bilinmese de birkaç örnek cümleye bakarak biçimbirimler çıkarılabilir:

| Svahili | Türkçe |
|---|---|
| nilipata | aldım |
| ulipata | aldın |
| valipata | aldılar |
| nilikipata | onu aldım |
| nitakipata | onu alacağım |
| ulikipata | onu aldın |
| nitakupata | seni alacağım |

- Çıkarılan biçimbirimler: "pata" = almak, "ni" = ben, "u" = sen, "va" = onlar, "ki" = onu, "ku" = seni, "ta" = gelecek zaman eki, "li" = geçmiş zaman eki.
- İnsan bu kuralları hiçbir model kullanmadan mantıkla çıkarabilir. Bir derin öğrenme veya makine öğrenmesi modeli de bu örneklerle eğitilirse aynı kuralları öğrenir.
- Basit, kelimesi az dillerde cümle yapıları da kısıtlıdır.

#### Biçimbirim Gösterimi ve Ünlü Uyumu

- Ekler ünlü uyumuna göre biçim değiştirir: "bilecek", "bulacak". Kalın ünlüden sonra kalın, inceden sonra ince ünlü gelir.
- "-ken" eki hiç değişmez.
- İngilizcede "il-, im-, in-, ir-" ön eklerinin hangisinin geleceğine dair kural yoktur. Bu yüzden her biri için ayrı leksikon tutulur.
- Gösterim kuralı: süslü parantezdeki büyük harfler değişkendir. A = a/e, I = ı/i/u/ü, Ç = ç/c, T = t/d.

| Biçimbirim | Biçimcikler |
|---|---|
| {AcAk} | [acak], [ecek] |
| {ÇI} | [çı], [çi], [çu], [çü], [cı], [ci], [cu], [cü] |
| {lIk} | [lık], [lik], [luk], [lük] |
| {TA} | [ta], [te], [da], [de] |
| {ken} | [ken] |

- Örnek: "git" kelimesi ek alınca "gid-" olur ("gidecek"). Gösterimde sondaki ses "T" ile yazılır; tek başına "t", ek alınca "d" olabilir.

#### Biçimbirim Türleri

- Bağımlı ve bağımsız biçimbirimler (bound / free morpheme):
  - Ekler her zaman bağımlıdır, tek başına kullanılamaz.
  - Tek başına görünmeyen kökler de bağımlıdır ("öğre", "nite").
- Sıfır biçimcik: hiç ek almadan tek başına kullanılabilen biçim.
- Portmanto biçimbirim: bir ek birden fazla anlamı birlikte taşır (askıya birden fazla kıyafet asılması gibi).
  - "geliyorsunuz": hem "siz" kişisini hem çoğulu anlatır.
  - "geldik": hem "biz" kişisini hem geçmiş zamanı anlatır.
  - İngilizcede "-s": hem geniş zaman hem 3. tekil kişi.
- Tekcil biçimbirim: yalnızca tek bir kökle kullanılan biçimbirim.
  - "yağmur": "-mur" eki Türkçede yalnızca "yağ" köküne gelir. ("hamur" kelimesinin kökü "ha" değildir.)
  - İngilizcede "cranberry" kelimesindeki "cran" yalnızca "berry" ile kullanılır.

#### Biçimbilimsel Analizin Görevleri ve Yöntemleri

- Görevleri:
  - Kelimenin türünü tespit etmek: isim, sıfat, fiil, edat.
  - Kökü ve ekleri (biçimbirimleri) bulmak.
  - Eklerin türünü belirlemek: "armudu yedim" (belirtme hâli) ile "Ali'nin armudu" (tamlanan eki) farklıdır.
- Yöntemler:
  - Bildirimsel (declarative) yöntem: kelimeler biçimbilimsel bilgileriyle birlikte sözlükte tutulur; analizde kelime aranır, sonuç doğrudan alınır. En basit yöntem ama sözlüğün hazırlanması çok zahmetlidir.
  - Yordamsal (procedural) yöntem: sözlükte yalnızca kökler tutulur. Ekler biçimbilimsel kurallarla bulunur, kalan kök sözlükte varsa kabul edilir.

#### "ki"nin Üç Türü

- Bağlaç olan "ki": ayrı yazılır. Çıkarıldığında cümlenin anlamı bozulmuyorsa bağlaçtır. "Bir yemek yapmış ki yeme de yanında yat."
- Sıfat yapan "-ki": ismin "-de" hâlinden sonra gelir. "karşıdaki"
- Zamir yapan "-ki": bir ismin yerini tutar. "Benim çantamın rengi siyah. Seninki ne renk?"
- Hoca bir dönem metindeki "ki"leri bulmayı ödev olarak vermişti.

#### Ünlü Uyumu Dışındaki Durumlar ve Fiil Çatıları

- Büyük ve küçük ünlü uyumuna uymayan durumlar çok:
  - Birleşik sözcükler.
  - Bazı ekler: "-daş" (meslektaş), "-ken", "-ki", "-imtırak", "-yor".
  - Bazı kelimeler: anne, dahi, elma, kardeş, şişman. Bunların birçoğu başka dillerden girmiştir.
- Fiil çatıları biçimbilimsel analizde araç tarafından verilir; derste ayrıntısına girilmedi.
  - Geçişli fiil: "neyi, kimi" sorusuna veya başına "onu" getirildiğinde cevap verir. "Seni duyuyorum." "Kimi duyuyorsun?" "Seni." Geçişlidir.
  - Geçişsiz fiil: "Lütfen otur." "Neyi otur?" Cevap yok. Geçişsizdir.
  - Etken: "Evi güzelce temizledi." "Kim temizledi?" sorusunun cevabı var.
  - Edilgen: "Ev temizlendi." Öznenin cevabı yok.

### Gramer ve Diller

- Amaç: bir dilin grameri, cümle yapıları ve sözlüğü verildiğinde tümcesel yapıların (sentential form) nasıl oluşturulduğunu ve dilin nasıl modellendiğini göstermek.
- Gerçek dil yerine önce sembolik örnekler kullanılır: alfabe olarak Türkçenin 29 harfi yerine {a, b, c} veya {0, 1}.
- İki tür değişken:
  - Söz dizimsel değişken (nonterminal): büyük harfle gösterilir. İsim öbeği, fiil öbeği, dolaylı tümleç gibi yapılar.
  - Uç değişken (terminal): küçük harfle gösterilir. Kelimeler, yani sözlükteki elemanlar.
- $\alpha \rightarrow \beta$: "β'yı al, α'nın yerine koy". Örneğin cümle → isim öbeği + fiil öbeği.
- Türetme soldan sağa veya sağdan sola yapılabilir. Okuma alışkanlığımıza yatkın olduğu için kitaplarda genelde soldan sağa anlatılır. Ama yazılan kod tutarlı olmalı: ya hep soldan ya hep sağdan.
- Ayrıştırma ağaçları:
  - Yukarıdan aşağı (top-down): "Banu okula gitti." cümlesinden başlanır. Özne "Banu", fiil öbeği "okula gitti"; "okul + a" (yönelme eki), "git + ti" (geçmiş zaman eki) diye ayrılır.
  - Aşağıdan yukarı (bottom-up): "git + ti" birleşir, "okul + a" birleşir, "okula gitti" fiil öbeği olur, özneyle birleşip cümleye ulaşılır.

#### Gramerin Tanımı

- $G = \langle V_N, V_T, P, S \rangle$
  - $V_N$: söz dizimsel değişkenler kümesi (sonlu).
  - $V_T$: uç değişkenler kümesi (sonlu), yani sözlük.
  - $V_N \cap V_T = \emptyset$
  - $P$: yeniden yazma ve türetme kuralları, $\alpha \rightarrow \beta$.
  - $S$: başlangıç değişkeni, $S \in V_N$. İşleme cümleden başlanır.
- $V = V_N \cup V_T$. Genel biçimde $\alpha \in V^+$ ve $\beta \in V^*$.
- Kleene operatörleri:
  - $a^+$: en az bir kez. a, aa, aaa, ...
  - $a^*$: hiç veya istenildiği kadar. λ (boş), a, aa, ...
  - Sol taraf $V^+$ olduğu için hiçbir zaman boş olamaz; boşluğa bir şey atanamaz. Sağ taraf boş olabilir.
- Dil: $L(G) = \{ w \mid w \in V_T^*, S \Rightarrow^* w \}$. Yani başlangıç değişkeninden türetilebilen ve tamamı uç değişkenlerden oluşan bütün dizgeler.
- Tamamı uç değişkenlerden oluşan bir ifadeye ulaşınca türetme biter.
- Örnek $G_1$: $V_N = \{S\}$, $V_T = \{0, 1\}$, $P: S \rightarrow 0S1 \mid 01$
  - $S \Rightarrow 01$
  - $S \Rightarrow 0S1 \Rightarrow 0011$
  - $S \Rightarrow 0S1 \Rightarrow 00S11 \Rightarrow 000111$
  - Genelleme: $L(G_1) = \{0^n 1^n \mid n \ge 1\}$
- Gerçek dünyada $V_T$ Türkçenin sözlüğü, $V_N$ isim öbeği, fiil öbeği, zarf tümleci gibi yapılar, $P$ de bir cümlenin olabilme kuralları olur.

#### Tür 0: Kısıtlamasız Gramer

- Yalnızca $\alpha \rightarrow \beta$ ($\alpha \in V^+$, $\beta \in V^*$) şartı var. Başka hiçbir kural yok.
- Örnek $G_2$ (slayttan):
  - $V_N = \{S, L, R, A, B, C\}$, $V_T = \{a\}$
  - $P$: $S \rightarrow LAaR$, $Aa \rightarrow aaA$, $AR \rightarrow BR \mid C$, $aB \rightarrow Ba$, $LB \rightarrow LA$, $aC \rightarrow Ca$, $LC \rightarrow \lambda$
- Türetme soldan başlanarak yapılır. Her adımda önce ikili, sonra (varsa) üçlü eşleşmelere bakılır, kural yoksa bir kaydırılır.

```text
S => LAaR => LaaAR => LaaC => LaCa => LCaa => aa

S => LAaR => LaaAR => LaaBR => LaBaR => LBaaR => LAaaR
  => LaaAaR => LaaaaAR => LaaaaC => ... => LCaaaa => aaaa
```

- Genelleme: $L(G_2) = \{ a^i \mid i = 2^n, n \ge 1 \}$. Yani 2, 4, 8, 16, ... tane "a".
- "aba" bu dile ait değildir. (Zaten $V_T$ içinde "b" yok; örnek olsun diye verildi.)

#### Tür 1: Bağlama Bağımlı Gramer

- Ek kısıt: sol taraftaki eleman sayısı sağ taraftakinden küçük veya ona eşit olmalı, $\lvert\alpha\rvert \le \lvert\beta\rvert$.
  - $A \rightarrow b$ yazılabilir (1 ≤ 1).
  - $Aa \rightarrow b$ yazılamaz (2 > 1).
  - $A \rightarrow ba$ yazılabilir (1 ≤ 2).
- Örnek $G_3$ (slayttan):
  - $V_N = \{S, A, B\}$, $V_T = \{a, b, c\}$
  - $P$: $S \rightarrow aSAB$, $S \rightarrow aAB$, $BA \rightarrow AB$, $aA \rightarrow ab$, $bA \rightarrow bb$, $bB \rightarrow bc$, $cB \rightarrow cc$

```text
S => aAB => abB => abc

S => aSAB => aaABAB => aabBAB => aabABB => aabbBB => aabbcB => aabbcc
```

- Genelleme: $L(G_3) = \{ a^n b^n c^n \mid n \ge 1 \}$
- Yanlış bir tümcesel yapıda uç değişkenlere ulaşılamaz; bir yerde tıkanılır. "Gökyüzü çöp tenekesi deniz araba." örneğindeki gibi kelimeler dile ait olsa da cümle oluşmaz.
- "abbcc" bu dile ait mi? Ya S'den başlanıp aşağı inilerek bu kelimeler yapraklarda oluşturulmaya çalışılır, ya da kelimeler birleştirilerek S'ye ulaşılmaya çalışılır. Ulaşılamıyorsa dile ait değildir.

#### Tür 2: Bağlamdan Bağımsız Gramer

- Kural: sol tarafta her zaman tek bir söz dizimsel değişken bulunur.
- Programlama dilleri böyledir: "a + b = 5" yazılamaz; atamanın solunda her zaman tek bir değişken vardır.
- Örnek: $V_N = \{S\}$, $V_T = \{v, c, +, -, *, /, (, )\}$ (v: değişken, c: sabit)
  - $P: S \rightarrow S+S \mid S*S \mid S-S \mid S/S \mid (S) \mid v \mid c$
- Sağdan türetme örneği:

```text
S => S*S => S*(S) => S*(S-S) => S*(S-v) => S*(c-v) => v*(c-v)
```

- Sonuç, bizim yazdığımız aritmetik ifadelerden farksızdır. Aynı ifade soldan da türetilebilir.

#### Tür 3: Düzenli Gramer

- Kural: sol tarafta tek bir söz dizimsel değişken. Sağ taraf boş, tek bir uç değişken veya bir uç değişkeni takip eden bir söz dizimsel değişkendir.
- Düzenli ifadeler (regex) bu dillere karşılık gelir.
- Örnek $G_5$ (slayttan):
  - $V_N = \{S, A, B\}$, $V_T = \{0, 1\}$
  - $P$: $S \rightarrow 0S \mid 0A \mid 0 \mid \lambda$, $A \rightarrow 0B$, $B \rightarrow 1S$

```text
S => 0S => 00
S => 0A => 00B => 001S => 001
S => 0S => 00A => 000B => 0001S => 00010A => 000100B => 0001001S => 00010010
```

- Dil: her 1'den önce en az iki tane 0 bulunan dizgeler.
- Slayttaki iki düzenli ifade:
  - `(0)*(001(0)*)^n(0)*`, $n \ge 0$ (hocanın ilk yazdığı)
  - `((00)+1)*0*` (hocanın daha "optimize" diye yazdığı)
- Derste ikinci ifadenin üçüncü dizgeyi (00010010) üretip üretmediği tartışıldı:
  - Bir öğrenci üretmeyeceğini söyledi, çünkü `(00)+` sıfırları hep çift sayıda verir, dizgenin başında ise 3 tane 0 var.
  - Başka bir öğrenci üretebileceğini savundu.
  - Hoca, döngüye tekrar dönülebilmesi için parantezin dışındaki yıldızın gerektiğini anlattı. (Doğru cevap için "Ders sonrası notlar" kısmına bakın.)
- Sağ doğrusal (right-linear) okumada yerleştirmeye sağdan, sol doğrusal (left-linear) okumada soldan başlanır. Slaytlarda aynı iki tümcesel yapının soldan ve sağdan türetilmesi var; ikisi de aynı sonucu verir.

#### Yukarıdan Aşağı ve Aşağıdan Yukarı Ayrıştırma

- Bir dizgenin dile ait olup olmadığını anlamak için türetme ağacı kurulur. Ağaçta ilerleyerek dizge oluşturulabiliyorsa dizge dile aittir.
- Yukarıdan aşağı: S alınır, verilen kurallardan biri yerine konur, uç değişkenlere inilene kadar devam edilir. Bazı dallar kural gereği ilerleyemez ve durur.
- Aşağıdan yukarı örnek (slaytta "aababbaba" dizgesi):
  - Dizge üzerinde ikili parçalara bakılır. Bir kuralın sağ tarafına uyan her parça için o kuralın sol tarafı yazılarak yeni bir aday ifade oluşturulur.
  - Örnekte ilk adımda 6 aday çıkar.
  - Her adayın kurallarla en fazla kaç sembolde örtüştüğüne (maksimum çakışma) bakılır. En büyük çakışmayı veren aday önce denenir. İlk adımda bir aday 3, diğerleri 2 çakışma verdi.
  - Eşitlikte seçim kodlayana kalmış. Hoca hep en son bulunanla devam ediyor.
  - Bir yol tıkanırsa ("SB" diye bir kural yok, çözüm yok) geri dönülüp sıradaki aday denenir (geri izleme, backtracking).
  - Sonunda "aS → S" ile cümleye (S) ulaşıldı. Dizge dile aittir ve ağaçta hangi aşamalardan geçildiği görülür.
- Kural sayısı arttıkça olasılıklar da artar. Kod ne kadar iyi optimize edilirse cevap o kadar hızlı gelir. Söz dizim analizi arka planda bunu yapar.

#### Gerçek Dil Örnekleri

- Gramer (slayttan, İngilizce için basit bir bağlamdan bağımsız gramer):

```text
S       -> NP VP | Aux NP VP | VP
NP      -> Det Nominal | ProperNoun
Nominal -> Noun
VP      -> Verb | Verb NP

Det  : the, a, that, this ...
Noun : book, flight, meal ...
Verb : book, include ...
Aux  : does, is, are, do ...
```

- Yukarıdan aşağı, soldan sağa, derinlik öncelikli (depth-first) ayrıştırma: "Does this flight include a meal?"
  - S → NP VP denenir. "Does" belirleyici (determiner) sözlüğünde yok, özel isim sözlüğünde de yok. Bu kuralla devam edilemez.
  - S → Aux NP VP denenir. "Does" Aux sözlüğünde var.
  - NP → Det Nominal: "this" Det, "flight" Noun.
  - VP → Verb: "include" fiil ama arkasından "a" geliyor, VP sadece fiille bitemez.
  - VP → Verb NP: "include" fiil; NP → Det Nominal: "a" Det, "meal" Noun.
  - Bütün kelimeler yapraklara oturdu, cümle İngilizcedir.
- Bir kelime sözlükte yoksa cümle reddedilir. Dile yeni giren kelimeler (örneğin "COVID") sözlüğe eklenmezse "Ayşe COVID'e yakalandı" cümlesi Türkçe değil diye işaretlenir.
- Aşağıdan yukarı ayrıştırma: "Book that flight"
  - "book" hem Noun hem Verb sözlüğünde var.
  - Noun olarak alınırsa: "that flight" NP olur ama "Nominal NP" diye bir kural yok, S'ye ulaşılamaz.
  - Verb olarak alınırsa: Verb + NP → VP, VP → S. Cümleye ulaşıldı.
- Hoca Türkçe için hazırlanmış bir slayttaki "İG, FG" gibi etiketlerin literatüre aykırı olduğunu, kimsenin bilmediğini söyledi. Herkesin kullandığı standart etiketlerle okunmalı.

#### Genişletilmiş Geçiş Ağları (ATN)

- Söz dizim yapısı ağaç yerine durumlardan (state) oluşan bir ağla da gösterilebilir.
  - Bir başlangıç (start) durumu ve bir bitiş (final) durumu vardır. Bitiş durumu çift halkayla gösterilir.
  - Girdi, bitiş durumuna gelmeden bitemez. Bitiş durumuna gelinip girdi bitmemişse de kabul edilmez.
  - Epsilon (ε) geçişi: hiçbir girdi okumadan durum değiştirme.
  - Okların yönünde hareket edilir; döngüler olabilir.
- Slayttaki küçük otomat örneğinde "b" ve "abba" tanınır. "b" ile başlayıp devamı olan "baab" gibi bir girdi tanınmaz, çünkü bitiş durumundan geri dönüş yoktur.
- Türkçe örnek: "Ali camı kırdı."
  - Biçimbilimsel analiz: Ali (özel isim), cam (isim) + ı (ek), kır (fiil; aynı zamanda isim) + dı (geçmiş zaman eki).
  - Ağ: cümle = özne + yüklem veya özne + nesne + yüklem.
    - Özne: isim sözlüğünde olmalı.
    - Nesne: isim + nesne eki.
    - Yüklem: fiil + zaman eki.
  - "Ali" isim sözlüğünde var, özne tamamlandı.
  - "cam" önce yüklem olarak denenir: fiil sözlüğünde yok, geri dönülür. Nesne olarak denenir: "cam" isim, "-ı" nesne eki; nesne tamamlandı.
  - "kır" fiil sözlüğünde, "-dı" zaman eki sözlüğünde var. Yüklem tamamlandı, girdi bitti, cümle doğrudur.
- Akademik kaynaklarda ağ gösterimi daha az yer kapladığı için tercih edilebilir.
- Döngü örneği: "yırtık, kırmızı, büyük, ağır, ekose desenli top". Bir ismin önüne kaç sıfat geleceği bilinmez. Sıfat geldikçe aynı durumda döngü yapılır; sıfat sözlüğünde olmayan "top" gelince isim durumuna geçilir.

### Dersin Sonu

- 29 Ekim 2020 resmî tatil (Cumhuriyet Bayramı) olduğu için gelecek hafta ders olmayacak. Hoca kesin bilgiyi mesajla iletecek.
- Bu sürede proje konularını inceleyin.
- Hoca seminer için kısa ve rahat okunabilen makaleler arayacak. Öğrenciler de makale önerisiyle gelebilir.

### Ders sonrası notlar

- Hoca biçimbilimsel analiz yöntemlerini anlatırken önce bildirimsel ve yordamsal yöntemleri karıştırdı, sonra düzeltti. Doğrusu: bildirimsel yöntemde kelimeler biçimbilimsel bilgileriyle sözlükte tutulur; yordamsal yöntemde yalnızca kökler tutulur, ekler kurallarla bulunur.
- `((00)+1)*0*` ifadesi "00010010" dizgesini üretmez. `(00)+` yalnızca çift sayıda 0 üretir; dizgede ilk 1'den önce 3 tane 0 var. Bütün ifadeye dıştan yıldız eklemek bunu çözer: `(((00)+1)*0*)*` bu dizgeyi üretir. "Her 1'den önce en az iki 0" dilini veren doğru ifadeler: slayttaki ilk ifade `(0)*(001(0)*)^n(0)*` ve daha kısa olarak `(0*001)*0*`.
- Hoca "determiner" için bir yerde "bağlaç" dedi. Bağlaç "conjunction"dır. "Determiner" belirleyici (belirteç) demektir; hoca da sonra "DET, belirteç" dedi.
- Hoca Tür 0 diller için "ön yinelemeli sayılabilir" dedi. Doğru terim: özyinelemeli sayılabilir (recursively enumerable).
- Hoca NLTK'yi yine Stanford Üniversitesi'nin aracı olarak andı. NLTK Pennsylvania Üniversitesi'nde geliştirildi; Stanford'un aracı Stanford CoreNLP'dir.
- Altyazıda sözcük birim için "LSTM olarak da geçer" yazıyor. Bu büyük ihtimalle "lexeme" kelimesinin yanlış yazımıdır. LSTM bir sinir ağı modelidir.
- Altyazıda dil bilimcinin adı "Narmu Shomsky" olarak geçiyor. Doğrusu Noam Chomsky.

İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
