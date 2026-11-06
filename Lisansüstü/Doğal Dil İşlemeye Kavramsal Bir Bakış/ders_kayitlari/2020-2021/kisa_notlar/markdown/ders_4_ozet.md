# Ders 4 Çalışma Özeti

## Genel Konular

- Düzenli ifadeler (regular expression, regex): düzenli dillerle ilişkisi, otomat karşılıkları, kullanım alanları.
- Temel regex komutları: `^`, `$`, `[]`, `[^]`, `.`, `?`, `*`, `+`, `\b`, `|`, sayaçlar `{n}`, `{n,m}`, `{n,}`, işlem önceliği ve özel karakterler.
- Regex ödevi: farklı biçimlerde yazılmış adresleri bulmak.
- Biçimbilimsel analiz (morphological analysis) ayrıntıları: biçimbirim (morpheme), kök ve gövde (stem), ek türleri.
- İngilizce ve Türkçe biçim bilimi farkı ("You had been in the car" ve "arabadaymışsınız").
- Biçimbilimsel analizin kullanım alanları ve bağlılık analizi (dependency parsing).
- Biçimbilimsel çözümleyicinin bileşenleri: sözlük, biçim dizimi kuralları (morphotactic rules), imla kuralları (orthographic rules).
- İngilizce için sonlu durum otomatları ve Türkçe için çekim eki otomatları.
- Kök bulma: soldan sağa ve sağdan sola yaklaşımlar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Düzenli ifadeler büyük-küçük harfe duyarlıdır (case sensitive). Bunu unutmak çok hata yaptırır.
- Yaklaşık 10 komutla regex ile yapılabilecek işlerin %80'i yapılabilir. Gerisi ihtiyaç oldukça kaynaklardan bakılır. Regex bir dil gibi ezberlenmez, ihtiyaç anında kullanılır.
- Aynı işi yapan iki regex'ten kısa ve sade olanı tercih edin. Bir yıl sonra yeni bir durumu eklemek gerektiğinde karmaşık bir ifadeyi anlamak çok zorlaşır.
- `*` ve `+` operatörleri bir döngü sayacı gibi düşünülebilir: `*` sıfırdan n'ye, `+` birden n'ye kadar sayar.
- Biçimbilimsel analiz bir kelimenin bütün olası çözümlerini verir ama cümledeki doğru çözümü söylemez. Anlamsal bilgi çıkarılacaksa doğru çözüm gerekir.
- Bağlılık analizi çok önemli. Kelimeler arasındaki bağlılıklar bilinirse 5N1K soruları çok rahat cevaplanır.
- Türkçe için otomata yapılan bir ekleme başka birçok kelimenin çözümünü bozabilir. Bu yüzden bu otomatlar dil bilimcilerle birlikte hazırlanır.
- Bir kökün kabul edilmesi için arkasından gelenlerin o köke eklenebilecek ekler olması ve otomatta bir bitiş durumuna ulaşılması gerekir.

## Kısa Tekrar Notları

- Düzenli diller birleştirilebilir (concatenation), birleşim ve kesişim işlemlerine girebilir, Kleene operatörleri uygulanabilir.
- `a*`: λ (boş), a, aa, aaa, ...
- `a+`: a, aa, aaa, ... (en az bir kez)
- Kleene operatörleri Stephen Kleene'den adını alır. Regex aslında belirlenimci olmayan sonlu otomattır (NFA); belirlenimci sonlu otomata (DFA) dönüştürülerek çalıştırılır.
- Regex kullanılan yerler: vi, Emacs, Kate gibi metin düzenleyiciler; grep, sed gibi konsol uygulamaları; Perl, Python, PHP, JavaScript; Eclipse, Visual Studio gibi geliştirme ortamları.
- Komut özeti:

| Komut | Anlamı | Örnek |
|---|---|---|
| `^` | Başlangıç | `^gül`: gül, güler; songül değil |
| `$` | Bitiş | `gül$`: gül, songül; güler değil |
| `^...$` | Tam eşleşme | `^gül$`: yalnızca gül |
| `[ ]` | Karakter sınıfı (veya) | `makin[ae]`, `[Bb]anu`, `h[1-6]` |
| `[^ ]` | Dışındakiler | `[^5-8]`, `Türkçe[^d]` |
| `.` | Herhangi bir karakter (joker) | `sıc.k`: sıcak, sıcık |
| `\.` | Nokta karakterinin kendisi | `193\.140\.4\.1` |
| `?` | Önceki karakter seçimlik | `colou?r`: color, colour |
| `*` | Sıfır veya daha çok | `ab*c`: ac, abc, abbc |
| `+` | Bir veya daha çok | `[0-9]+` |
| `\b` | Kelime sınırı | `\beli\b` |
| `\|` | Veya | `(sempozyum\|konferans)` |
| `{n}` | Tam n kez | `[0-9]{3}` |
| `{n,m}` | En az n, en çok m kez | `[0-9]{2,4}` |
| `{n,}` | En az n kez | `[0-9]{2,}` |

- İşlem önceliği (yüksekten düşüğe): parantezler; sayaçlar (`*`, `+`, `?`, `{}`); diziler ve bağlayıcılar (`^`, `$`); veya (`|`).
- Özel karakterler: `\t` sekme, `\n` yeni satır, `\?`, `\*`, `\.` karakterlerin kendisi, `\s` boşluk, `\S` boşluk olmayan, `\w` kelime karakteri, `\W` kelime karakteri olmayan, `\d` rakam, `\D` rakam olmayan.
- Biçimbirim: kelimedeki en küçük anlamlı birim. "fox" tek biçimbirim, "cats" iki biçimbirim (cat + s). "çiçekler" de iki biçimbirim.
- Ek türleri: ön ek (prefix), son ek (suffix), iç ek (infix), çevre ek (circumfix).
- Biçimbilimsel çözümleyicinin üç bileşeni: sözlük (lexicon), biçim dizimi kuralları, imla kuralları.
- Türkçe ses olayları: ünlü düşmesi (oğul → oğlu), ünlü daralması (anla + yor → anlıyor), ünsüz sertleşmesi (meslek + daş → meslektaş), ünsüz yumuşaması (ağaç + a → ağaca), ünsüz türemesi (his + i → hissi).

## Detaylı Açıklamalar

### Duyurular

- 29 Ekim 2020 haftası resmî tatil olduğu için ders yapılmadı.
- Öğrencilerin büyük çoğunluğu proje konusunu bildirdi. Bildirmeyenler önerilerini hemen yazmalı. Hoca, küçük araştırmalara şimdiden başlanmazsa projelerin yetişmeyeceği uyarısını yaptı.
- Dersi 18 kişi alıyor.
- Sistemde hâlâ ödev yükleme modülü olmadığı için hoca bir Google Drive klasörü açıp paylaşacak.

### Regex Ödevi

- Drive klasöründe bir txt dosyası var. İçinde farklı biçimlerde yazılmış adresler bulunuyor:
  - Sokak için "Sokak", "S.", "Sk.", "Sok." gibi yazımlar.
  - Daire için "Daire 5", "D:5", "D 5" gibi yazımlar.
- Görev: dosyadaki adreslerin olabildiğince çoğunu bulan tek bir regex yazmak.
- Teslim edilecek dosyada:
  - Yazılan regex komutu.
  - Bulunan adres sayısı (örneğin 50 adresten 45'i).
  - Bulunamayan adreslerin listesi.
- Dosya PDF olacak ve adı öğrenci numarası ile adından oluşacak. Drive klasörüne yüklenecek.
- Süre bir hafta, gelecek derse kadar.
- Hocaya göre bu ödevi yapan, derste gösterilen bütün komutları öyle ya da böyle kullanmak zorunda kalır ve regex konusunu bitirmiş olur.

### Düzenli Dillerin Tekrarı

- Tür 0: kısıtlamasız, türetme kurallarının iki tarafındaki eleman sayısında sınır yok.
- Tür 1: sol taraftaki eleman sayısı sağ taraftakine eşit veya ondan küçük.
- Tür 2: bağlamdan bağımsız, programlama dilleri. Kurala uymayınca sözdizimi hatası (syntax error) verilir.
- Tür 3: düzenli diller. En kısıtlı dil, ama bununla bile çok iş yapılabilir.
- Uç değişkenler dilin sözlüğündeki kelimelerdir. Söz dizimsel değişkenler dilin kalıplarıdır: özne-nesne-yüklem, özne-belirtili nesne-dolaylı tümleç-yüklem, sıfat-sıfat-sıfat-isim gibi.

### Regex ve Otomat Karşılıkları

- Bir durumdan (state) başka bir duruma geçiş: örneğin gelen kelime isimse bir sonraki duruma geçilir.
- Epsilon (ε) geçişi: hiçbir girdi olmadan durum değiştirmek.
- Boş küme: iki durum birbirine hiç bağlanamaz.
- Birleştirme (concatenation): birinci dilin çıktısı ikincinin girdisine girer. Hiçbir şart yoktur.
- Veya (`|`): başlangıçtan ε ile iki dile de gidilebilir. Biri bitiş durumuna ulaşamazsa yanlış seçim yapılmış demektir, diğeri denenir. İkisinin çıktısı ortak bitiş durumuna bağlanır.
- Kleene yıldızı (`*`):
  - Hiç çalışmama durumu: başlangıçtan ε ile doğrudan çıkışa geçilir.
  - Bir kez çalışma: içerideki dil işlenir ve bitiş durumundan çıkılır.
  - Birden çok kez çalışma: bitiş durumundan ε ile tekrar başa dönülür.

### Adım Adım Regex Örneği

- `abc` yazıldı. "bc" girdisi bu ifadeyle tanınmaz, çünkü "a" zorunlu.
- `a*bc`: "a" olmayabilir. Ama "ac" girdisi tanınmaz, "b" zorunlu.
- `a*b*c`: "abc", "bc", "ac", "aabc" tanınır.
- "acbc" girdisi tanınmaz. Çözüm: dışarıya yıldız eklemek, `(a*b*c)*`. Döngünün ilk turunda "ac", ikinci turunda "bc" alınır.
- "c" yıldızsız olduğu için her turda mutlaka gelmeli. Dışarıda `*` yerine `+` olsaydı parantezin içine en az bir kez girilmesi gerekirdi.
- Gerçek dünyada a, b, c yerine kelimeler veya ifadeler gelir. Aranan kalıplar tekrar edebilir veya etmeyebilir; probleme göre operatör seçilir.

### Regex'in Kullanım Alanları

- Arama motorları ve bilgiye erişim: Hocanın adıyla aynı adı taşıyan başka biri var. Yalnızca akademik çalışmalar bulunmak istenirse adın önünde mutlaka unvan aranır. Unvan "Dr.", "dr." veya başka bir unvan olabilir; ad yazılmayabilir, yalnızca soyadı olabilir.
- Kelime işleme (word processing): yanlış yazılmış kelimeler, büyük-küçük harf farkları, Türkçe karakter kullanılıp kullanılmaması ("küçük", "kucuk").
- Derlemde (corpus) kelime sıklığı saymak: "okul", "okula", "okulda", "okulum" gibi bütün biçimleri kök bulmaya uğraşmadan "okul ile başlayan" diye sayabilmek.
- Veri doğrulama (data validation): TC kimlik numarası, telefon numarası, e-posta adresinin doğru biçimde girilip girilmediğini kontrol etmek.
- Nasıl yazıldığı tam hatırlanmayan bir kelimeyi bulmak ("scholarships" gibi). Emin olunan karakterler verilir, diğer yerler esnek bırakılır.
- "http" ile başlayan bütün adresleri bulmak.

### Regex Komutlarının Ayrıntıları

#### `^` ve `$`

- `^Banu`: Banu, Banu'yu, Banu'da, Banu'nun gibi "Banu" ile başlayan ifadeler. Küçük "b" ile yazılanları getirmez.
- `Banu$`: "Banu" ile bitenler.
- `^Banu$`: yalnızca "Banu".
- `^$`: boş satırlar.

#### Köşeli Parantez `[ ]`

- İçindeki karakterlerden biri gelir, aralarında "veya" vardır.
- `makin[ae]`: hem "makina" hem "makine" yazımlarını bulur.
- `[ds]e[lb]i`: deli, seli, debi, sebi. Bu kalıpla başlayan "sebil", "delil" gibi kelimeler de bulunur. "Salim" bulunmaz, çünkü ikinci karakter mutlaka "e" olmalı.
- `[Bb]anu`: büyük veya küçük harfle başlayan bütün "Banu"lar.
- HTML başlıkları: `h[123456]` yerine aralık kullanılır: `h[1-6]`.
- `[0-9]`, `[a-z]`, `[A-Z]`, `[a-zA-Z]` (ASCII tablosundaki aralıklar).

#### Olumsuzlama `[^ ]`

- Köşeli parantezin içinde başta gelen `^`, kendisinden sonrakilerin dışındakiler demektir.
- `[^5-8]`: 5 ile 8 dışındaki karakterler.
- `Türkçe[^d]` örneği:
  - "Türkçemiz" bulunur ("e"den sonra "m" gelmiş).
  - "Türkçeyi" bulunur.
  - "Türkçede" bulunmaz ("e"den sonra "d" gelmiş).
  - "Türkçe " bulunur, çünkü boşluk da bir karakterdir.
  - "TürkçeD" bulunur, çünkü yalnızca küçük "d" dışlanmış.
- `[^A-Z]`: büyük harf dışındaki karakterler. `[^\.]`: nokta dışındaki karakterler.
- `^` karakterinin üç kullanımı:
  - Köşeli parantez içinde başta: olumsuzlama.
  - Köşeli parantez dışında: başlangıç.
  - Köşeli parantez içinde başta değilse: karakterin kendisi. `[e^]` = "e" veya "^".

#### Nokta `.` ve Kaçış `\`

- `.` herhangi bir karakter yerine geçen jokerdir (wildcard).
- `sıc.k`: "sıcak" ve "sıcık" bulunur. Büyük harfle başlayan "Sıcak" bulunmaz (case sensitive).
- Bazı semboller komut olduğu için kendilerini aramak gerektiğinde önlerine ters eğik çizgi konur: `\.`, `\?`.
- IP örneği: `193\.140\.4\.1.` ifadesi bu IP adresiyle başlayıp arkasından herhangi bir karakter gelen dizgeleri bulur. Son nokta jokerdir; 3, A veya boşluk olabilir.
- `.*`: herhangi bir karakter dizisi, hatta boşlukla ayrılmış birkaç kelime.
  - `YTÜ.*kulüpleri` şunların hepsini bulur: "YTÜ kulüpleri", "YTÜ öğrenci kulüpleri", "YTÜ kız öğrenci kulüpleri". Böylece dokümanlarda bütün kulüpleri tek tek aramaya gerek kalmaz.

#### Soru İşareti `?`

- Kendisinden önce gelen karakterin seçimlik olduğunu belirtir.
- `colou?r`: Amerikan İngilizcesi "color" ve İngiliz İngilizcesi "colour".
- "evler" ve "evleri" biçimleri de son harf seçimlik yapılarak birlikte bulunabilir.

#### Yıldız `*` ve Artı `+`

- `ab*c`: "a" ile başlar, "c" ile biter, arada "b" olmayabilir veya birçok kez tekrar edebilir. "abd" bulunmaz, çünkü "c" zorunlu.
- Bir öğrencinin sorusu: Bu ifade beş tane "a" ve sonra "c" gelirse bulur mu? Dizginin tamamı eşleşecekse hayır: "a" yalnızca bir kez yazılabilir; birden çok "a" için dışarıda bir döngü gerekir. Metin içinde arama yapılırsa (örn. `re.search`) sondaki "ac" parçası bulunur.
- `[0-9][0-9]*`: en az bir rakam zorunlu, sonra istenildiği kadar rakam gelebilir.
  - Bir öğrenci bunun yerine `+` kullanmanın daha pratik olduğunu söyledi. Hoca onayladı: `[0-9]+` aynı işi yapar ve daha kısadır. Örnek komutları göstermek için uzun hali verilmişti.

#### Kelime Sınırı `\b`

- `\b`, aranan ifadenin önünde ve arkasında sınırlayıcı bir karakter olması gerektiğini belirtir.
- `\beli\b`: önünde ve arkasında sınır olan "eli" ifadesini bulur.
- Hoca bu örneği ilk gördüğünde aylarca "beli" diye okuduğunu, `\b`nin ayrı bir komut olduğunu çok sonra fark ettiğini anlattı.
- `\B`: sınır olmayan durum.
- Bir öğrenci sordu: metinde `\b` dizgesinin kendisi aranırsa ters eğik çizgi iki kez mi yazılmalı?
  - Hoca hiç denemediğini, denenmesi gerektiğini söyledi.
  - Başka bir öğrenci Python'da denedi: programlama dillerindeki gibi ters eğik çizgi iki kez yazılınca çalıştı.
  - İnternetteki regex deneme sitelerinde de denenebilir; boşluk için `\s` kullanılır.

#### Veya `|`

- Bu yıl dördüncüsü yapılan bütün sempozyumları bulmak:
  - Sıra sayısı yazıyla ("Dördüncü", "dördüncü") veya rakamla ("4.") yazılabilir. Rakamdan sonraki nokta için `\.` kullanılır.
  - Arada sempozyumun adı (bir veya birkaç kelime) gelebilir: `.*`
  - Sonda "Sempozyum" veya "sempozyum".
  - Genel biçim: `([Dd]ördüncü|4\.).*[Ss]empozyum`
- Bütün sempozyumlar (1., 3., 10. ...) bulunmak istenirse sıra sayısı yerine 1-99 arası bir sayı ve nokta yazılır. Sonda da `([Ss]empozyum|[Kk]onferans)` ile konferanslar da yakalanabilir.

#### Sayaçlar

- `{n}`: kendinden önceki karakter tam n kez ardışık gelmeli.
- `{n,m}`: en az n, en çok m kez.
- `{n,}`: en az n kez, üst sınır yok.
- Örnek: "Ateşoğlu" kelimesini bulmak için regex gerekmez, Ctrl+F yeter. Ama "önünde 4 karakter, arkasından 3 rakam, sonra Ateşoğlu" gibi bir kalıp aranıyorsa sayaçlar gerekir. Rakam kısmı `[0-9]{3}` olur.
- Benzer örnek: dokümanda bölüm kodu (BLM, EHM gibi 3-4 harf), öğrenci numarası ve soyadı varsa soyadı "Yılmaz" olan bütün öğrenciler tek bir regex ile bulunabilir.
- `?` de bir sayaç gibi düşünülebilir: sıfırdan bire kadar sayar.

### Biçimbilimsel Analiz

- Kaynaklarda "biçimbilimsel" ve "biçimbirimsel" ikisi de kullanılıyor.
- Tanım: bir metindeki kelimenin bilgisayar tarafından otomatik olarak çözümlenmesi. Kelime kök ve eklerine ayrılır, her birinin görevi (türü, etiketi) belirlenir.

#### Kök, Gövde ve Ekler

- Gövde (stem): "gözlük" kelimesinin kökü "göz" olsa da sözlükte ayrı bir anlamı vardır ve bir nesneyi anlatır. Gövdesi "gözlük" olarak alınır. "göz"e kadar inilirse anlam kaybolur. Metinde gözler sayılacaksa gözlük sayılmamalı.
- Ekler (affix):
  - Ön ek (prefix): "impossible". Türkçede ön ek çok azdır, Arapça ve Farsçadan gelen kelimelerde görülür: "natamam" (eksik), "biçare" (çaresiz).
  - Son ek (suffix): "ittekiler", "yemeklerdekiler".
  - İç ek (infix): gövdenin içine eklenir; Filipince gibi dillerde sık görülür.
  - Çevre ek (circumfix): ekin bir parçası gövdenin önüne, bir parçası arkasına gelir. Almanca "sagen" (söylemek) fiilinden "gesagt": "ge-" + "sag" + "-t", geçmiş zaman ortacı (past participle).
- Birleştirme (compounding): "dog" + "house" = köpek kulübesi; "pazar" + "yer" = pazar yeri. Anlam parçalardan rahatça tahmin edilebilir.
- Çekim (inflection) ve yapım (derivation) ekleri:
  - Yapım ekleri kelimenin anlamını, hatta türünü değiştirebilir.
  - Çekim ekleri anlamı değiştirmez; kişi ve zaman bilgisi verir.
- Klitikler (cliticization): kesme işaretiyle ayrılan İngilizce "'ve" gibi yapılar, Fransızcadaki "l'", Türkçedeki ayrı yazılabilen "de", "ki", "mi".
- Ek sayısı: İngilizcede bir kelime en fazla 4-5 ek alır. Türkçe gibi bitişken dillerde daha fazla ek gelebilir.
  - Örnek: "uygarlaştıramadıklarımızdanmışsınızcasına". Günlük hayatta kullanılmaz ama biçimbilimsel analizde sorunsuz çözümlenir. İngilizcede birkaç kelimeyle, hatta bir cümleyle anlatılan şey Türkçede tek kelimeye sığar.
- İngilizce örnekler: "rewrite" kelimesinde "re-" ön ek, "-s" son ek; "unbelievable" kelimesinde "un-" ön ek, "-able" son ek.
- Analiz çıktısındaki etiketlerin hepsini ezberlemek gerekmez. Ama çıktı bir uygulamada girdi olarak kullanılacaksa hangi etiketin hangi bilgiyi verdiği bilinmeli.

#### İngilizce ile Türkçe Farkı

- İngilizcede "car" ve "cars" kelimelerinin kökü kolayca bulunur. Ek sayısı az ve ekler kökü bozmadığı için kökler bir sözlükte tutularak iş çözülür. Hocaya göre İngilizcede biçimbilimsel analiz bugün neredeyse %100 başarılı. Yine de Python'daki bazı kök bulma fonksiyonlarının garip kökler verdiği görülüyor.
- Türkçede ise:
  - Otomatlarda eksikler çıkabiliyor. Bir problemi çözmek için yapılan ekleme 10 başka kelimeyi bozabiliyor. Bu durumda o bir kelimenin yanlış çözümlenmesi kabul edilebilir.
  - Kelimenin bütün olası biçimlerini listelemek mümkün değil. Tek bir kelime aldığı eklerle birçok anlamı taşıyabiliyor.
- "You had been in the car." ve "Arabadaymışsınız.":
  - İngilizcede cümle kelimelere ayrılır, "car" kökü hemen bulunur.
  - Türkçede tek bir kelimenin kökü bulunmalı. Neden "ar" (utanma) veya "ara" değil de "araba"?
  - Çözümleyici aday kökleri dener. "ar" kök alınırsa geri kalanın ar köküne doğru sırada eklenebilecek ekler olması gerekir; değilse kök "ar" değildir. Aynısı "ara" için yapılır. "araba" kök alınınca "-dAymIşsInIz" ekleri kurallara uyar.
  - Çözümleme: araba (isim) + "-da" (bulunma hâli) + "-ymış" (ek fiil) + "-sınız" (2. çoğul kişi).
- Morfolojiyle çeviri: araba → the car, "-da" → in, "-ymış" → had been, "-sınız" → you. Basit cümlelerde işe yarar, karmaşık cümlelerde anlamsız çeviriler çıkar. Bu yüzden eskiden Türkçe-İngilizce çeviriler başarısızdı. Yüz binlerce cümle çiftiyle eğitilen derin öğrenme modelleriyle çeviriler iyileşti.

#### Çoklu Çözüm ve Anlam Belirsizliği

- "çocukları" kelimesi için Zemberek veya başka bir çözümleyici dört farklı çözüm verir. (Ders 1'deki dört cümlelik örnek.) Türkçede en sık görülen çözüm ilk sırada verilir.
- Hoca, Porter kök bulucusunun (Porter Stemmer) Türkçe için olmadığını, Türkçe için Snowball'un olabileceğini söyledi.
- "kalem" örneği:
  - Yalın hâli: pencil. "Bu kalem yazmıyor."
  - "kale" + 1. tekil iyelik "-m": benim kalem (castle). "Benim kalem yıkıldı."
  - Çözümleyici iki çözümü de verir. Hangi anlamın kullanıldığı birlikte kullanılan kelimelerden anlaşılır: kale "yazmak" fiiliyle, kalem (pencil) "yıkılmak" fiiliyle kullanılmaz.
  - Bu bir kelime anlamı belirsizliği (word sense ambiguity) problemidir.

#### Biçimbilimsel Analizin Kullanım Alanları

- İnternette arama: "Anadolu Hisarı konserleri başladı mı?" sorgusunda eskiden yalnızca sabit kalıp (fixed pattern) aranıyordu. Bugün "Anadolu Hisarı'nda", "Anadolu Hisarı'nın konserleri" gibi ekli biçimler de getiriliyor.
- Yazım denetimi: "Bunu mu demek istediniz?" önerisi basit dizge eşleştirmenin yanında morfolojiye de bakabilir.
- Bul ve değiştir (find and replace):
  - "Bütün 'oğul'ları 'kız' yap." Metinde "Benim oğlum mükemmeldir." varsa "oğlum" bulunmaz. Doğru sonuç "kızım" olmalı. "oğul" kelimesinin "oğlum" biçimine dönüştüğü bilgisini morfoloji verir.
  - "Bütün 'bina'ları 'ev' yap." "binadan" kelimesi "evdan" değil "evden" olmalı.
- Makine çevirisi.

#### Bağlılık Analizi (Dependency Parsing)

- Örnek cümle: "Bu okuldaki öğrencilerin en akıllısı şurada duran küçük kızdır."
- Biçimbilimsel analiz her kelimeyi etiketleriyle verir. Dünyada ortak kullanılan bazı etiketler:

| Etiket | Anlamı |
|---|---|
| Det | Belirleyici (determiner) |
| Noun | İsim |
| Adj | Sıfat |
| Adv | Zarf |
| Verb | Fiil |
| A3sg | 3. tekil kişi |
| A3pl | 3. çoğul kişi |
| Pnon | İyelik eki yok |
| Loc | Bulunma hâli (-de) |
| Gen | İlgi hâli, sahiplik (-in) |
| Nom | Yalın hâl |
| With | İsimden sıfat yapan "-li" |
| Zero | Ek almadan türetme |
| Pos | Olumlu |
| Pres | Şimdiki zaman |
| PresPart | Ortaç (sıfat-fiil) |

- "okuldaki": okul (isim) + "-da" + "-ki". "-ki" eki kelimeyi sıfat yapar.
- Bu bilgiler yetmez, bağlılık analizi gerekir. Bağlılıklar:
  - "bu" → "okul"u belirtir.
  - "okuldaki" → "öğrencileri" niteler.
  - "öğrencilerin" → "akıllısı" ile sahiplik ilişkisi kurar.
  - "en" → "akıllısı"nı niteler.
  - "akıllısı" → "kızdır" (özne).
  - "küçük" ve "duran" → "kız"ı niteler.
  - "şurada" → "duran"ın yerini bildirir (kalma tümleci).
- Bu bağlılıklar bilinirse 5N1K soruları rahatça cevaplanır ve anlamsal ilişkiler çıkarılır.
- Türkçe için açık kaynak bir bağlılık çözümleyicisi hocanın bildiği kadarıyla yok.
  - Boğaziçi ve İTÜ'de (belki ODTÜ'de de) akademik çalışmalar var.
  - Ticari kazanç sağlanmayacağına dair bir belge imzalanırsa akademik amaçla paylaşılıyor. Hocanın tahminine göre Türkçe üzerine çalışan firmalara satılabiliyor.
- İngilizce için Python kütüphaneleri bağlılık çözümlemesi verir, hatta ağacı çizer.

#### İngilizcede Çekim ve Yapım Ekleri

- Çekim ekleri isimlere, fiillere ve sıfatlara uygulanır.
- İsimler: çoğul ve sahiplik ekleri.
  - Düzenli (regular) isimler ve düzensiz (irregular) isimler ayrı sözlüklerde tutulur. "ox" ve "oxen" bilmeyen biri için iki ayrı kelime gibidir.
- Fiiller:
  - "walk": walks, walking, walked.
  - "try": tries ("y" düşer, kural).
  - "stop": stopping (son harf tekrarlanır). Bu tür fiiller ayrı bir sözlükte tutulur.
  - Düzensiz fiiller ("eat", "ate", "eaten") ayrı bir sözlükte olmalı. Bunların aynı kökten geldiğini dili bilmeyen bir insan da göremez.
- Yapım ekleri İngilizcede daha karışıktır, genellikle fiil ve sıfatlara uygulanır.
  - "-ation", "-ee", "-er", "-ness" ekleri fiil ve sıfatları isme dönüştürür (nominalization).
  - Bazı ekler ("-less" gibi) isim ve fiillerden sıfat yapar.

#### Biçimbilimsel Çözümleyicinin Bileşenleri

- Sözlük (lexicon):
  - İngilizcede bütün gövdeler konur.
  - Türkçede gövdeler ve ekler tutulur, ya da ekler için ayrı bir yapı kullanılır.
  - Hece düşmesi, yumuşama, sertleşme gibi özel durumlar görülen kelimelere sözlükte bir bayrak (flag) konur: "Bu kelimede şu durum oluşabilir, kontrol et."
- Biçim dizimi kuralları (morphotactic rules): eklerin hangi sırayla eklenebileceği.
  - "çocukların": önce çoğul eki, sonra "-ın" gelir. Sahiplik ekinden sonra çoğul eki gelmez ("çocukınlar" diye bir kelime yok).
- İmla kuralları (orthographic rules):
  - Ünlü uyumu kontrolü.
  - Ünlü düşmesi: oğul → oğlu.
  - Ünlü daralması: anla + yor → anlıyor ("a", "ı"ya daralır).
  - Ünsüz sertleşmesi: meslek + daş → meslektaş (d → t, g → k, c → ç).
  - Ünsüz yumuşaması: ağaç + a → ağaca (ç → c).
  - Ünsüz türemesi: his + i → hissi.
- Bayrak kullanım örneği: "oğlu"
  - Ekler atılınca "oğl" kalır. Sözlükte yok.
  - Kural: yan yana iki sessiz harf var ve arkasından "u" geliyorsa ünlü düşmesi olmuş olabilir. Sesliyi iki sessizin arasına koy: "oğul".
  - "oğul" sözlükte var ve bu kuralın bayrağı açık. Kök "oğul" kabul edilir.

#### İngilizce Sonlu Durum Otomatları

- Bu otomatlar kitaptan alınmış, yalnızca anlatmak için ve çok sınırlı sayıda kelime için çalışır.
- İsim otomatı: düzenli isim sözlüğü, düzensiz çoğul isim sözlüğü, düzensiz tekil isim sözlüğü ve çoğul eki.
  - "fox": düzensiz tekil ve düzensiz çoğul sözlüklerde yok, düzenli isim sözlüğünde var. Girdi bitti ve bitiş durumundayız. "fox" isimdir.
  - "foxing": "fox" kısmına kadar gelinir ama girdi bitmez ve "-ing" ile gidilecek bir geçiş yoktur. Ya kelime İngilizce değildir ya da otomat eksiktir. Tamamlanmış bir otomatta bu genelde yanlış yazılmış bir kelime demektir.
- Fiil otomatı: düzenli fiiller, düzensiz fiiller, düzensiz fiillerin geçmiş biçimleri ve "-ed", "-ing", "-s" ekleri.
  - "cuts": "cut" düzensiz fiil sözlüğünde bulunur, girdi bitmemiştir, "-s" ile başka bir bitiş durumuna geçilir. Çıktı: "cut" düzensiz fiil + "-s".
- Sıfat otomatı:
  - İlk otomatta "big" ve "bigger" tanınır. Ama İngilizcede olmayan "unbig" de tanınır: "un-" ön eki alınır, "big" sıfat sözlüğünde bulunur.
  - Düzeltilmiş otomatta iki sıfat sözlüğü var:
    - Sıfat kökü 1: "un-" ön ekini alabilen sıfatlar; sonuna "-er", "-est", "-ly" alabilir.
    - Sıfat kökü 2: "un-" almayan sıfatlar; sonuna "-er", "-est" alabilir.
  - "unbig" için "un-" ile sıfat kökü 1'e gidilir ama "big" orada yoktur. Bu yoldan çözüm çıkmaz, kelime reddedilir.
- Türetme otomatı: isimden fiil ("-ize"), fiilden sıfat ("-able"), fiilden isim ("-ation") gibi geçişler. Farklı ek alan kelimeler için ayrı sözlükler (fiil grubu j, fiil grubu k, isim grubu i gibi) var. Kitaplar bu otomatların tamamını paylaşmaz; bunların da eksikleri vardır.
- Zemberek gibi araçların arkasında Türkçe için çıkarılmış böyle bir otomat çalışır.
- Bir dil bilimci belgesi kodlandıktan sonra dil bilimciye ancak otomatın çözemediği yeni bir kelimeyle karşılaşınca tekrar başvurulur.

#### Kök Bulma: Soldan ve Sağdan

- Kemal Oflazer'in çözümleyicisi soldan başlar. İTÜ'deki Gülşen Hoca (Gülşen Cebiroğlu Eryiğit) Oflazer'in çalışmasını alıp iyileştirmiş; o da soldan gider.
- Soldan yaklaşım, "okulda" örneği:
  - "o": sözlükte var (zamir). Ama zamir otomatında geri kalan ekler bu köke eklenemez. Kök değil.
  - "ok": isim. Ama "-ulda" eklenemez.
  - "oku", sonra "okul": "-da" eklenebilir ve bitiş durumuna ulaşılır. Kök "okul".
- Sağdan yaklaşım: Türkçe sondan eklemeli olduğu için ekler hızla atılır.
  - Önce "-a" atılır: "okuld" diye kök yok.
  - "-da" atılır: "okul" köktür ve "-da" ona eklenebilir.
- Basit bir otomat (Vasıf Nabiyev'in Yapay Zeka kitabından):
  - İsim kökünden sonra ekler şu sırayla gelir: çoğul, iyelik, durum, "-ki". Hepsi olmak zorunda değil, ama varsa bu sırada olmalı. Fiil kökü için de benzer bir sıra var.
  - Gösterimde köşeli parantez seçenekleri ("D" = d/t, "A" = a/e), süslü parantez "olabilir de olmayabilir de" anlamında.
  - "akıllardakilerin" örneği:
    - "ak" isim sözlüğünde yok (sıfat). "akı" da yok.
    - "akıl" isim sözlüğünde var. Sonra "-lar" (çoğul), "-da" (durum), "-ki", "-ler" (çoğul), "-in" (ilgi) ile durumlar arasında ilerlenir. Girdi biter, bitiş durumuna ulaşılır. Kök "akıl".
- Kök bulmadaki zorluklar:
  - "yazıldığın": kök "yaz" mı, "yazı" mı?
  - "oğlumuz": metinde "oğul" hiç geçmez. Ünlü düşmesi kuralıyla "oğul" bulunur, sonra "-umuz" ekinin bu köke eklenip eklenemeyeceğine bakılır.
  - "bacağım": "bacağ" ile "bacak" hiç bulunamaz. Son harf "ğ" ise "k" yerine gelmiş olabilir; "k" konup sözlüğe bakılır, "bacak" bulunur.
- Türkçe çözümleyici akış şeması:
  - Kelime gelir, soldan veya sağdan bir kök adayı belirlenir.
  - Ünlü uyumu kontrol edilir. Uymazsa başka kök alınır.
  - Kök fiilse fiil çözümleyicisine, değilse isim çözümleyicisine gönderilir. Yapım ekleriyle isimden fiile, fiilden isme geçilebilir.
  - Biçimbirim-ses (morphophonemic) denetiminde eklerin sırası kontrol edilir. Hata varsa yeni kök belirlenir.
  - Hiçbir yoldan bitiş durumuna ulaşılamıyorsa kelime o dile ait değildir: ya yanlış yazılmıştır ya da başka bir şeydir.
  - Şemadaki her kutu kendi içinde bir otomattır.

#### Türkçe Ek Otomatları

- Gösterilen otomatlar Gülşen Hoca'nın Oflazer'in çalışması üzerine geliştirip uyarladığı otomatlardan alındı.
- Ekler kelimelere rastgele eklenmez; belirli kurallarla ve belirli sırayla eklenir. Dört küme:
  - İsim çekim ekleri: 19 ek. Gösterimde büyük "H" = ı/i/u/ü.
  - Ek eylem ekleri: 15 ek (isimden eylem yapar).
  - Eylem zaman ekleri: 29 ek.
  - Eylem çekim ekleri: 44 ek.
- "sandıktakilerden" örneği (isim çekim otomatı):
  - Kök "san" (sanmak) da olabilir, "sandık" da. "sandık" isim sözlüğünde bulunur.
  - Çoğul eki yok: sıfır geçişle ilerlenir. İyelik eki de yok: sıfır geçiş.
  - "-ta" durum ekiyle durum 1'e geçilir. Buradan "-ki" ile gidilecek yer yok. Yanlış yol; geri dönülür.
  - "-ta" ile durum 2'ye geçilir. Sonra "-ki" ile ilgi durumuna, "-ler" ile çoğula gidilir.
  - "-den" için doğrudan geçiş yok. Sıfır geçişle ilerlenir, "-den" ile durum 1'e geçilir. Girdi biter, çıkışa ulaşılır. Kök "sandık".
- "akıllıymışsın" (ek eylem otomatı): "akıllı" isim soylu. "-ymış" ile ek fiil durumuna, "-sın" ile kişi ekine geçilir, sıfır geçişle çıkılır. Eyleme dönüşmüş bir isimdir.
- Eylem zaman otomatı: "gör" fiil kökünden "-üyor" (zaman), "-muş" (bileşik zaman) ve "-sunuz" ile çıkışa gelinir.
- Olumsuzluk eki önemlidir: "yapmazlarsa" kelimesindeki "-ma/-maz" olumsuzluk bildirir.
- Eylem çekim otomatı, "görüşmezler": "gör" + "-üş" (işteşlik) + sıfır geçişler + "-me" (olumsuzluk) + "-z" + "-ler" ile çıkışa ulaşılır.
- Bu kadar büyük otomatları tek başına çıkarmak çok zordur. Yanlış eklenen bir dal başka kelimelerin yanlış çözümlenmesine yol açar. Dil bilimcilerle çalışılmasının sebebi budur.

### Ders sonrası notlar

- Hoca `[a^c]` için "a veya c'nin dışındaki her şey" dedi. Doğrusu: `^` köşeli parantezin başında değilse karakterin kendisidir. `[a^c]` ifadesi "a", "^" veya "c" ile eşleşir.
- Hoca köşeli parantez dışındaki `a^b` ifadesinin "a^b" kalıbını aradığını söyledi. Python dahil çoğu regex motorunda `^` köşeli parantez dışında her zaman başlangıç çapasıdır. "a^b" metnini aramak için `a\^b` yazılmalı.
- `\b` bir karakter değil, sıfır genişlikli bir konumdur: kelime karakteri ile kelime karakteri olmayan bir şey (boşluk, noktalama, satır başı/sonu) arasındaki sınır. Hocanın "sınırlayıcı yıldız olursa elinin sağında ve solunda yıldız olması gerekir" açıklaması `\b` için geçerli değil; belirli bir karakteri sınır olarak istemek için o karakter kalıba açıkça yazılmalı.
- Hoca `\w` için "alfanümerik veya boşluk karakteri" dedi. Doğrusu: `\w` harf, rakam ve alt çizgi (`_`) ile eşleşir; boşluk dahil değildir. `\W` bunların dışındaki her karakterdir (boşluk dahil).
- Hoca "Loc" etiketini anlatırken "yönelme" dedi. "Loc" (locative) bulunma hâlidir (-de). Yönelme hâli (-e) "Dat" (dative) ile gösterilir.
- Hoca "cuts" kelimesindeki "-s" için "çoğul takısı" dedi. Fiildeki "-s" geniş zamanda 3. tekil kişi ekidir.
- Hoca bir yerde "Gülşen Hoca'nın şu an İTÜ'de" olduğunu söyledi. Altyazıda adı "Gülşen ... Er Yiğit Cebiroğlu" olarak geçiyor; doğrusu Gülşen Cebiroğlu Eryiğit.
- Altyazıda kitap yazarının adı "Vasit Mabiyev" olarak geçiyor. Doğrusu Vasıf Nabiyev.

İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
