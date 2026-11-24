# Ders 8 Çalışma Özeti

## Genel Konular

- Bilgi nedir, bilmenin seviyeleri (ekrandan, 00:10:00)
  - Bilgiyi tanımlamak kolay değildir; slaytta bilgi "bilinen her şey" diye yarı şaka tanımlanır ve "Bir şeyi bildiğimizi nasıl biliriz?" sorusu sorulur.
  - Bilmenin farklı seviyelerdeki göstergeleri: anımsama / çağrıştırma / hatırlama / tanıma, yorumlama, açıklayabilir olma, kanıtlayabilir olma, hakkında konuşabilme. Ayrıca yerine getirebilir / yapabilir olma (bisiklet sürmek, yüzmek gibi daha bedensel bir bilme). Bu maddeler kesin bir sıralama değildir.
  - Örnek: $E = mc^2$. Formülü yalnız görüp tanımak bir seviyedir; $E$'nin enerji, $m$'nin kütle, $c$'nin ışık hızı olduğunu bilmek daha ileri bir seviyedir; "enerji ve kütle birbirine dönüşebilir" diye yorumlamak bir sonraki seviyedir; formülü kanıtlamak ise çok farklı bir bilme seviyesi ister.
- Veriden bilgiye (ekrandan, 00:15:00)
  - Veri çok miktarda bulunur ve herkes için aynıdır. Veri işlendikçe (yorumlandıkça) bilgiye dönüşür.
  - İşleme / yorumlama miktarı arttıkça bilginin soyutluk derecesi ve kişiye özel oluşu da artar. Slayttaki piramitte veri altta, bilgi üstte durur.
  - Görüntü örneği: pikseller → bölgesel etiketler → tek bir etiket. Bir "2" rakamının pikselleri çizgilere, çizgiler de "2" ya da "A" gibi bir etikete dönüşür. Bilinmeyen bir alfabenin şekli kolay etiketlenemez.
  - Çorba tenceresi tutan yaşlı kadın resmi: bölgesel etiketler "yaşlı bir kadın, fakir bir kadın, bir çorba tenceresi tutuyor, gülümsüyor"; tek etiket "mutluluk, şükran, ?". Yorum kişinin kendi bilgisine göre değişir.
  - İki kilit, bir anahtar ve bir eğik çizgiden oluşan resim tek etiketle "gülen bir yüz" olur. Burada bütün, parçaların toplamından büyüktür: parçalar özel bir düzenle bir araya gelmiştir. Bu yüzden böyle resimleri yorumlamak hem insan hem makine için daha zordur.
- Bilginin özellikleri, meta bilgi (ekrandan, 00:20:00)
  - Alan (özel - genel), doğruluk (doğru - yanlış), kesinlik (kesin - belirsiz).
  - Doğrulanabilirlik / yanlışlanabilirlik (bilimsel bilgi - metafizik): Deneyle test edilebilen bilgi bilimseldir. Ne doğrulanabilen ne yanlışlanabilen bilgiler (büyü, inanç gibi) metafizik alanına girer. Bilimsel bir teori hangi durumda yanlış olacağını söyleyebilmelidir; her duruma, birbirine zıt durumlara bile açıklaması olan bir teori bilimsel değildir.
  - Güncellik (güncel - eski), tamlık (tam - eksik).
  - Ekonomiklik (elde edilmesi, ondan beklenenden pahalı - değersiz): Bir bilgi ne kadar kesin istenirse o kadar pahalı olur. Seçim anketleri yaklaşık sonuç verir; örneklemin topluluğu temsil etmesi gerekir, tek bir semtte yapılan anket yanıltır.
  - Yaygınlık (çokça bilinen - hiç bilinmeyen): Yalnız sizin bildiğiniz (dün gece gördüğünüz rüya), şu an kimsenin bilmediği ama ileride bilinecek ve hiç bilinmeyecek bilgiler vardır. Bilim insanları şu an bilinmeyen ama işe yarayacak bilgileri ortaya çıkarmaya çalışır.
- Bilgi gösterim türleri (ekrandan, 00:25:00)
  - Kurallar (rules), anlamsal ağlar (semantic nets), yüklem mantığı (predicate logic), çerçeveler (frames), sahneler (scripts), YSA'lar.
- Kurallar (ekrandan, 00:25:00)
  - Genel format: `IF condition THEN conclusion (action)`. Genelde sonlu sayıda çok kural olur: `IF condition is Ai THEN conclusion is Bi`.
  - Kurallar çok değişkenli olabilir: `IF condition1 and condition2 or ... and conditionn THEN conclusion`.
  - Bilgisayarda bilgi gösteriminde en sık kullanılan yaklaşımdır, çünkü kurallarla yapılan çıkarım kolayca açıklanabilir.
- Kurallarla çıkarım: ileri ve geri zincirleme (ekrandan, 00:30:00)
  - Çıkarım: elimizdeki verilerden elimizde olmayan verileri üretme sürecidir. İki yöntem de kesin sonuç verir.
  - İleri doğru zincirleme (veri güdümlü) "neler doğrudur?" sorusunu, geri doğru zincirleme (hedef güdümlü) "G doğru mudur?" sorusunu cevaplar.
  - Örnek: veri tabanı A, B, C, D, E; bilgi tabanı `Y & D → Z`, `X & B & E → Y`, `A → X`, `C → L`, `L & M → N`.
  - İleri zincirleme: önce `A → X` ve `C → L`, sonra `X & B & E → Y`, sonra `Y & D → Z` ateşlenir. Sonuç: A–E'ye ek olarak X, L, Y, Z doğrudur. M bilinmediği için `L & M → N` hiç ateşlenmez.
  - Geri zincirleme: hedef Z → alt hedef Y → alt hedef X; X, A'dan kanıtlanır, sonra Y ve Z kanıtlanır.
  - Doktor benzetmesi: soru sorup tahmin yürüten ve yalnız gereken tahlilleri isteyen doktor geri zincirleme, hiçbir şey sormadan bütün tahlilleri isteyen doktor ileri zincirlemedir.
- Anlaşmazlık (çatışma) çözümü
  - Veri tabanındaki bilgilere göre aynı anda ateşlenebilecek kuralların kümesine çatışma / anlaşmazlık kümesi, içinden uygulanacak kuralın seçilmesine çatışma çözümü denir.
  - Örnek: "ışık yeşilse git", "ışık kırmızıysa dur", "ışık kırmızıysa git" kuralları; ışık kırmızıyken iki kural uygulanabilir.
  - Yöntemler: sıralama, durumla eşleşme (en çok kanıtı ya da en yüksek oranda tutan kural), güncellik (en yeni ya da en eski kural), meta kurallar (kuralın kaynağının uzmanlığı, insan güvenliği).
- Anlamsal ağlar (ekrandan, 00:40:00; 00:45:00)
  - Bilgi, birbirine farklı tipte bağlarla bağlanmış düğümler kümesidir. Düğümler kavramları, yönlü bağlar ilişkileri gösterir ("instance of", "is a", "has a", "part of").
  - Hiyerarşik ağ örneği: hayvan nefes alır, derisi vardır, hareket eder; kuş bir hayvandır, uçar, kanadı ve tüyü vardır; kanarya bir kuştur, öter, sarıdır; deve kuşu bir kuştur ama uçamaz, uzundur.
  - "is a" yollarındaki "has" ilişkileri kalıtılır, bu da çıkarıma uygundur. Kanaryanın nefes aldığını ayrıca yazmak gerekmez: bilgi ekonomisi.
- Çerçeveler (ekrandan, 01:00:00)
  - Nesneye yönelik programlamanın yapay zekâdaki kullanımıdır. Jargon: çerçeve, öznitelik (slot), yuva (facet).
  - Örnek bilgi tabanı: Animals (Alive: T, Flies: F); Birds ve Mammals Animals'ın alt kümesi; Penguins, Cats, Bats alt kümeler; Opus, Bill, Pat üyeler; bir slotun değeri başka bir çerçeve olabilir (Opus ve Bill birbirinin arkadaşı).
  - Çerçeveler değer ekleme / silme sırasında çalışan prosedürler içerebilir.
- Sahneler (scripts) (ekrandan, 01:05:00)
  - Günlük hayattaki olaylar basmakalıp dizilimleri izler. Sahneler, söylenmeyen olayların da tahmin edilmesini sağlar (sağduyu bilgisi).
  - Bileşenler: sahne ismi, başlama şartları, roller, nesneler, alt sahneler, sonuç.
  - Lokanta sahnesi: giriş, sipariş, yiyeceğin hazırlanması, yemeğin yenmesi, lokantadan ayrılma alt sahneleri.
  - Elle yazılan sahnelerin varyasyonları bitirilemedi; dallanma faktörü çok yüksek olduğu için elle yazmak ölçeklenmedi.
- Closed world ve open world sistemler
  - Closed world: sistemde olmayan bilgi yanlış kabul edilir. "Alex'in Bob ve Jane adlı çocukları var" bilgisinden "Alex'in iki çocuğu vardır" sonucuna varılır.
  - Open world: sistemde olmayan bilgi eksik ya da yanlış olabilir; bu sonuca varılamaz.
- Yapay sinir ağlarında bilgi gösterimi (ekrandan, 01:10:00; 01:15:00)
  - Eğitim kümesindeki bütün bilgi eğitimle ağın ağırlıklarına dönüşür; eğitimden sonra eğitim kümesine gerek kalmaz. Ağın yapısı (tek / çok katmanlı, özyinelemeli) bilginin tutulma biçimini etkiler.
  - Doğal dilde Word2vec ve fastText: tek gizli katmanlı ağ; kelimeler sayısal bir uzayda vektör olur. Skip-gram ve CBOW modelleri.
  - Metin temsili ve kodlayıcı-çözücü (encoder-decoder) mimarileri ile çeviri; LSTM yerine bugün daha çok transformer blokları kullanılır.
  - Görüntüde katmanlar önce basit, sonra karmaşık örüntüleri temsil eder.

## Hocanın Özellikle Vurguladığı Kısımlar

- Veri ile bilgi aynı şey değildir
  - Günlük Türkçede birbirinin yerine kullanılsalar da burada veri işlenmemiş ve herkes için aynı olan şeydir; bilgi işlenmiş, daha soyut ve kişiye özel olandır.
- Bilimsel bilginin yanlışlanabilir olması
  - Bir teori hangi durumda yanlış olacağını söyleyebilmelidir; her durumu açıklayan teori bilimsel değildir.
- İleri ve geri zincirlemenin farkı
  - İleri zincirleme "neler doğru?", geri zincirleme "şu doğru mu?" sorusunu cevaplar. İleri zincirleme pahalıdır ama beklenmeyen sonuçları da bulur (check-up gibi).
- Çatışan kurallar gerçekten oluşur
  - Kurallar farklı kişilerden toplandığında ya da hatayla çatışan kurallar oluşabilir; bu yüzden çatışma çözümü mutlaka gerekir.
- Hiyerarşik yapı ve bilgi ekonomisi
  - İnsanlar da bilgiyi hiyerarşik tutar; "bir kedinin arka bacağındaki hücrede mitokondri var mı?" sorusu daha önce hiç düşünülmemiş olsa da bu yüzden kolayca cevaplanır.
  - Sık kullanılan sonuçlar ise çıkarım yerine ezberden çekilir: $7 \times 8$ ezberdedir, $249 \times 165$ gerektiğinde hesaplanır (önbellek benzetmesi).
- Sinir ağlarında bilgi ağırlıklardadır
  - Günümüzde "kedinin bıyığı, kuyruğu vardır" gibi bilgiler elle yazılmaz; örnekler verilir ve bilgi ağırlıklarda saklanır.

## Kısa Tekrar Notları

- Bilmenin seviyeleri: tanıma, yorumlama, açıklama, kanıtlama, hakkında konuşabilme, yapabilme.
- Veri → işleme → bilgi; işledikçe soyutluk ve kişiye özel oluş artar.
- Bütün, parçaların toplamından büyük olabilir (kilit, anahtar → gülen yüz).
- Meta bilgi: alan, doğruluk, kesinlik, doğrulanabilirlik, güncellik, tamlık, ekonomiklik, yaygınlık.
- Bilgi gösterimi: kurallar, anlamsal ağlar, yüklem mantığı, çerçeveler, sahneler, YSA.
- Kural: `IF condition THEN conclusion`.
- İleri zincirleme: veri güdümlü, "neler doğru?". Geri zincirleme: hedef güdümlü, "G doğru mu?".
- Örnek KB ve DB'den ileri zincirleme X, L, Y, Z üretir; N üretilemez.
- Çatışma kümesi ve çatışma çözümü: sıralama, durumla eşleşme, güncellik, meta kurallar.
- Anlamsal ağ: düğüm = kavram, yönlü bağ = ilişki; "is a" ile kalıtım, bilgi ekonomisi.
- Çerçeve: sınıf / nesne; slot ve facet.
- Sahne: isim, başlama şartı, roller, nesneler, alt sahneler, sonuç.
- Closed world: yok = yanlış. Open world: yok = bilinmiyor.
- YSA: bilgi ağırlıklarda; Word2vec skip-gram / CBOW; görüntüde katmanlı örüntüler.

## Detaylı Açıklamalar

- Bilgi ve veri: Ders bilginin kolay tanımlanamayacağını kabul ederek başlar ve bilmenin farklı seviyelerini $E = mc^2$ örneğiyle ayırır. Ardından veri ile bilgi ayrılır: veri çok miktarda ve herkes için aynıdır (resimdeki pikseller gibi); yorumlandıkça bölgesel etiketlere ve sonunda tek bir etikete dönüşür. Bu dönüşüm her zaman kolay değildir: bilinmeyen bir alfabenin şeklini etiketleyemeyiz, bir resme bakan herkes de aynı tek etiketi vermez. Kilit ve anahtardan oluşan gülen yüz örneğinde parçalardan bütünü tahmin etmek çok zordur, çünkü anlam parçaların düzenlenişinden doğar.
- Meta bilgi: Bilgi doğru / yanlış olabileceği gibi belirsiz de olabilir. Doğrulanabilirlik ölçütü bilimsel bilgiyi metafizikten ayırır: "dünya yüzeyinde bırakılan top şu sürede düşer" bilgisi deneyle test edilebilir; büyü, inanç gibi konular ise deneyle doğrulanamaz ya da yanlışlanamaz. Ekonomiklik örneğinde Türkiye'deki bir takımın taraftar sayısını tam olarak bilmek çok pahalıdır ve çoğu zaman yaklaşık değer yeterlidir; yaklaşık bilgi için de örneklemin topluluğu temsil etmesi gerekir.
- İleri zincirleme örneği (ekrandan, 00:30:00): Veri tabanında A, B, C, D, E vardır. Her turda koşulu sağlanan ve henüz ateşlenmemiş kurallar ateşlenir. 1. tur: `A → X` ve `C → L` (X ve L eklenir). 2. tur: `X & B & E → Y` (Y eklenir). 3. tur: `Y & D → Z` (Z eklenir). Ateşlenebilecek kural kalmayınca durulur. M bilinmediği için `L & M → N` ateşlenmez. Sonuç python ile kontrol edildi.
- Geri zincirleme örneği (ekrandan, 00:30:00): Soru "Z doğru mu?". Z için `Y & D → Z` gerekir; D bilinir, Y bilinmez, alt hedef Y olur. Y için `X & B & E → Y` gerekir; B ve E bilinir, alt hedef X olur. X için `A → X` gerekir; A bilinir, X doğrulanır. Geri dönerek Y ve Z doğrulanır, cevap "evet".
- Doktor benzetmesi: Doktor A şikâyetleri dinleyip bir hastalık tahmin eder, yalnız o tahmini doğrulayacak tahlilleri ister (geri zincirleme). Doktor B hiçbir şey sormadan bütün tahlilleri ister, sonuçlara bakıp neler olduğunu söyler (ileri zincirleme). B daha pahalıdır ama belirti vermeyen bir hastalığı da bulabilir; check-up'a benzer.
- Çatışma çözümü: Kurallar sıralanıp üstteki önce uygulanabilir. Durumla eşleşmede, A ve B biliniyorken `A → X` ile `A ve B ve C → Y` gibi iki kuraldan daha çok kanıtla eşleşen ya da tam tutan seçilebilir. Güncellikte en yeni kural seçilebilir ya da tam tersine en eski kural, uzun süre silinmeden çalıştığı için daha güvenilir sayılabilir. Meta kurallarda kuralın kaynağının uzmanlığı (iki yıllık ve yirmi yıllık doktor) ya da insan güvenliği (kırmızı ışıkta durmak gitmekten daha az risklidir) belirleyici olur.
- Anlamsal ağlar ve bilgi ekonomisi: Bilgi bir yönlü graf gibi tutulur. Hiyerarşik ağda kanaryanın nefes aldığı, derisinin olduğu, uçabildiği gibi bilgiler ayrıca yazılmaz; "is a" bağları üzerinden erişilir. Benzer biçimde ileri zincirleme örneğinde yalnız A–E'yi ve kuralları tutmak yeterlidir; X, L, Y, Z istenince üretilebilir. Yine de sık gereken sonuçlar ezberlenir ($7 \times 8$ gibi).
- Çerçeveler, sahneler ve YSA: Çerçeveler nesneye yönelik programlamanın sınıf / nesne yapısına benzer ve yapay zekâya özgü bir gösterim değildir. Sahneler 1980'lerin fikridir; lokanta gibi basit bir olayda bile çok sayıda varyasyon çıktığı için elle yazmak ölçeklenmemiştir. YSA'larda bilgi ağırlıklardadır; "Beşiktaş kazandı" ve "Kara Kartal yendi" cümlelerinin aynı anlama geldiğini anlamak için "Beşiktaş" ile "Kara Kartal", "kazandı" ile "yendi" ifadelerinin vektör uzayında yakın olması gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
