# Ders 2 Genişletilmiş Notu: Yapay Zekaya Giriş: Turing Testi, Karşı Görüşler ve Tarihçe

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Hatırlatması
- 2. Turing Testi
- 3. ELIZA
- 4. Searle'ün Çin Odası
- 5. İki Öğrenci: Süreç mi, Sonuç mu?
- 6. Ned Block'un Soru-Cevap Ağacı ve Arnheim'ın Yöntem Sorunu
- 7. Yapay Zekayı Gerçekleştirmede İki Yaklaşım
- 8. YZ Karşıtları: Searle, Gödel ve Lucas
- 9. Organik Süreç Ölçütü Üzerine Bir Soru
- 10. Yapay Zekanın Kısa Tarihi
- 11. Günümüz
- 12. Kimine Kolay, Kimine Zor
- 13. Dünya Bilgisi
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Hatırlatması

Bu derste yapay zekaya giriş slaytları tamamlandı. Hoca önce geçen haftayı özetledi. Zekanın ve yapay zekanın tanımı yapılmaya çalışılmış, yapay zekaya ulaşmak için dört okul olduğundan bahsedilmişti. Yapay zekanın temel hedefleri olarak makineleri daha akıllı ve işimize yarar hale getirmek ile kendi zekamızın nasıl çalıştığını anlamak sayılmıştı. Geçen dersin sonunda bir düşünce deneyi yapılmıştı: Bin yıl öncesinin insanlarına bir dizüstü bilgisayar götürüp yaptıklarını göstermek; ardından bir süre ders anlatan birinin sonunda bir Android robot olduğunu açıklaması ve "bana hâlâ zeki der misiniz?" sorusu. Yapay zekanın ilgili disiplinlerinin çok geniş bir kapsama yayıldığı da konuşulmuştu. Turing testine henüz geçilmemişti.

## 2. Turing Testi

Bir sisteme "zeki" sıfatını ne zaman verebiliriz? Bu soru üzerine çalışan çok sayıda insan vardır. Şu an elimizde bu sıfatı vermek için önerilmiş bir test bulunur: adını önerenden alan Turing testi.

Turing bu testi 1950'de yazdığı "Makineler düşünebilir mi?" makalesinde tanımlamıştır. Derste gösterilen hali makaledekinin birebir aynısı değildir, ama fikir olarak aynıdır.

Düzen şöyledir (ekrandan, 00:10:00):

- Bir duvarla birbirinden ayrılmış iki oda vardır.
- Bir tarafta bir insan sorgulayıcı (human interrogator) oturur.
- Diğer tarafta ya bir insan ya da bir yapay zeka sistemi bulunur.
- Sorgulayıcı karşı odayla yalnızca yazışarak iletişim kurar: bir şey yazar, karşı taraf görür ve cevap yazar.

Sorgulayıcının görevi karşı odadakinin insan mı makine mi olduğuna karar vermektir. Turing'in önerisi şudur: Bir sistem sorgulayıcıya yanlış karar verdirebiliyorsa ya da onu karar veremez hale getirebiliyorsa ve karşıdaki sistem gerçekten bir makineyse, ona zeki, zeka sahibi ya da düşünce sahibi demeliyiz.

Başka bir deyişle sorgulayıcı çeşitli sorular sorar. Makine bu sorulara, dışarıdan ölçebildiğimiz her açıdan insandan ayırt edilemeyecek şekilde cevap verebiliyorsa sorgulayıcı karar veremeyecektir.

Turing'in bu görüşünün dayanağı şudur: Diğer bütün insanlara bu sıfatı verme şeklimiz de aynıdır. Başkalarının davranışlarına sıfat yakıştırırken yalnızca dışarıdan ölçebildiğimiz şeylere bakarız. Davranışın arka tarafta nasıl üretildiğine dair bilgimiz yoktur.

Turing testi önerildiğinde ortada bugünkü anlamıyla dijital bilgisayarlar yoktu, daha çok analog cihazlar vardı. Bir süre sonra bu testi geçebilecek sistemler için yarışmalar düzenlenmeye başlandı. Slaytta adı geçen Loebner Yarışması bunlardan biridir ve uzun yıllar sürmüştür (ekrandan, 00:10:00). Turing testini geçmek uzun süre yapay zeka araştırmacılarının gündemini meşgul etmiştir. Hocanın bildiği kadarıyla günümüzde Turing testini gerçekten geçmiş bir makine yoktur.

## 3. ELIZA

Turing testinden sonra programlanabilen dijital bilgisayarlar ortaya çıktı. Bilinen ilk sohbet robotlarından biri olan ELIZA, 1965'te Joseph Weizenbaum tarafından geliştirildi ve bir terapisti simüle eder (ekrandan, 00:15:00).

Slaytta bir diyalog vardı. Satırların bir kısmı kırmızı, bir kısmı siyah (büyük harfle) yazılmıştı:

```text
Men are all alike.
IN WHAT WAY?
They're always bugging us about something or other.
CAN YOU THINK OF A SPECIFIC EXAMPLE?
Well, my boyfriend made me come here.
YOUR BOYFRIEND MADE YOU COME HERE?
He says I'm depressed much of the time.
I AM SORRY TO HEAR THAT YOU ARE DEPRESSED.
It's true that I am unhappy.
DO YOU THINK COMING HERE WILL HELP YOU NOT TO BE UNHAPPY?
I need some help, that much seems certain.
TELL ME MORE ABOUT YOUR FAMILY.
My mother takes care of me.
WHO ELSE IN YOUR FAMILY TAKES CARE OF YOU?
My father.
YOUR FATHER
```

Hoca sınıfa hangi tarafın insan, hangisinin makine olduğunu sordu. Sınıf siyah satırların makine olduğunu söyledi ve bu doğruydu. Öğrencilerin gösterdiği ipuçları şunlardı:

- Siyah taraf terapist rolündedir ve karşısındakinin söylediğine bir soru ile karşılık verir.
- Son satırlara doğru konuşma bozulur: "bana ailenden bahset" denir, insan annesinin ona baktığını söyler, makine "ailende sana başka kim bakıyor" diye sorar, insan "babam" deyince makine yalnızca "senin baban" diye karşılık verir. Bir devamlılık yoktur.
- Makine bağlamı yakalayamaz, yalnızca bir önceki cümleye bağlı kalır; anlık bir refleks gibi cevap üretir.

### 3.1 ELIZA nasıl çalışır?

Çalışma mekanizması görüldüğünde ELIZA'nın etkileyiciliği büyük ölçüde kaybolur. ELIZA şablon tabanlı çalışır. Kullanıcının cümlesi soldaki şablonlardan hangisine uyuyorsa sağdaki karşılık kalıbıyla cümle dönüştürülür ve kullanıcıya soru olarak geri verilir. Hocanın verdiği örnekler: Kullanıcı "I remember X" derse "Why do you remember X just now?" diye sorar; "My family member is Y" biçiminde bir cümleye de benzer şekilde aile üyesini içeren bir soru döndürür. Hiçbir şablon uymuyorsa genel amaçlı cevaplardan birini verir.

1965'te bazı insanlar bu sistemle konuşturuldu ve sonra konuştukları şeyin bir makine olduğu söylendi. Bazılarını buna ikna etmek güç oldu. Hoca bunun nedenini sordu.

**Soru:** Bazı insanlar neden konuştukları şeyin makine olduğuna inanmakta zorlandı? **Cevap:** Sınıftan gelen bir cevap, kişinin desteğe en çok ihtiyaç duyduğu bir anda konuşmuş olabileceğiydi; en küçük destek bile o an etkili olur. Hoca bunu doğru buldu ve bir neden daha ekledi: 1965'teki ortalama insan büyük olasılıkla bilgisayarla ilk kez karşılaşıyordu.

Sonuç olarak ELIZA Turing testini geçemez. Hoca derste aslında küçük bir Turing testi yaptırmış oldu: Sınıf hangi tarafın makine olduğuna karar verebildi. Karar veremeseydik bu örnek için Turing testini geçen bir durum var diyebilirdik. Yine de az da olsa kandırabildiği insanlar olmuştur.

### 3.2 Neden terapist?

ELIZA'nın taklit ettiği terapi yönteminin özel bir adı vardır: Rogers tipi (Rogerian) psikoterapi. Bu teknikte terapist danışanın söylediklerini aynen, uygun biçimde biraz değiştirerek ona geri söyler; bir ayna vazifesi görür. Bunun tek başına terapi sağlayacağına dair bir görüş vardır. Görüşün doğru ya da yanlış olması ayrı bir konudur, ama programlama açısından çok basittir: Karşı tarafın söylediğini uygun bir şekilde değiştirip geri söylemek yeterlidir. Bu yüzden otomatikleştirmeye çok uygun bir psikoterapi tekniğidir.

## 4. Searle'ün Çin Odası

Turing testini geçen bir sisteme zeki deriz görüşüne karşı birkaç görüş arka arkaya görüldü. Bunların ilki John Searle'ün Çin Odası düşünce deneyidir (ekrandan, 00:20:00).

Bir oda düşünelim. Odanın içinde bir koltukta bir insan oturur. Elinde bir kural kitabı (rule ledger) vardır. Odanın bir giriş ekranı (input), şekillerin bulunduğu veri çekmeceleri (data) ve bir çıkış yuvası (output) vardır. Ekranda bazı şekiller belirir. İnsan kural kitabını açar; kitap o girişe karşılık hangi çekmecenin kaçıncı sırasındaki kağıdı alıp çıkışa atması gerektiğini söyler. Slayttaki kural örneği: "Şöyle bir şekil geldiyse çıkışa x. çekmecedeki şekli koy."

Bu odanın bir Çinli insanla hiçbir sorun yaşamadan konuşabildiğini varsayalım. Yani oda Turing testine göre testi geçiyor, Çinli bir insanı simüle edebiliyor olsun. Slaytta üç soru vardı:

- İçerideki insan Çince biliyor mu?
- Oda Çince biliyor mu?
- Biliyor gözükmesi yetmez mi?

İçerideki insan Çince bilmez; ne yaptığından haberi bile yoktur, yalnızca şekillere bakıp kural kitabını uygular.

Hoca benzetmeyi sınıfa sordu. Bir öğrenci önce insanın algoritmayı ya da kodu temsil ettiğini söyledi; hoca bunun yanlış olduğunu belirtti. Doğru eşleştirme şudur:

- İçerideki insan: işlemci.
- Kural kitabı: kod, program.
- Çekmecelerdeki veri: veri (bellek).

**Soru:** Oda Çince biliyor mu sorusuna Turing'in cevabı ne olur? **Cevap:** Evet, biliyor olur. Dışarıdan bakıldığında odanın Çinli bir insandan farkı yoktur. Bir insana "Çince biliyor" sıfatını nasıl veriyorsak, dışarıdan ondan farkı olmayan bu sisteme de aynı sıfatı vermeliyiz.

### 4.1 Searle'ün itirazı

Hoca, Searle'ün nereye takıldığını sordu. Bir öğrenci, sistemin karar ağaçlarına benzediğini ve kural kitabında olmayan bir çıktıyı üretemeyeceğini söyledi. Hoca bu noktaya takılmamak gerektiğini vurguladı: Varsayım gereği oda dışarıdan bakıldığında ölçülebilen hiçbir açıdan insandan farklı değildir. Kural kitabında eksik olması gibi bir durum söz konusu değildir; oda bir insanın yapabildiği her şeyi yapabilmektedir. Searle'ün söylediği, buna rağmen odaya zeki diyemeyeceğimizdir.

Başka bir öğrencinin cevabı doğruydu: Searle sonuca değil, sonuca nasıl varıldığına, arkada neyin gerçekleştiğine bakar. İçeriden bakıldığında sistem korkunç derecede basittir: bir giriş gelir, "şöyle bir giriş gelirse şunu yap" kuralları uygulanır. Bir programı, bir algoritmayı izleyen böyle bir şeye ne yaptığına ve dışarıdan nasıl göründüğüne bakmaksızın zeki demek mantıklı değildir. Aksi halde hesap makinelerine ya da bir termostata da zeki dememiz gerekirdi.

**Soru:** Bir şeye zeki deyip diyememeyi neden bu kadar tartışıyoruz, bunun önemi ne? **Cevap:** Muhtemelen bir süre sonra kendisinin zeki olduğunu iddia eden makineler karşımıza çıkacak ve onları argüman düzeyinde yenmemiz pek mümkün olmayacak. O gün geldiğinde bu sistemlere belli haklar verilip verilmeyeceği gibi sorular ön plana çıkacak.

## 5. İki Öğrenci: Süreç mi, Sonuç mu?

Hoca konuyu bir hikayeyle sürdürdü. Tarihin en önemli matematikçilerinden biri olan Gauss'un çocukluğuna dair bir hikaye anlatılır. Hikayenin doğruluğu tartışmalıdır ama ders açısından iyi bir örnektir.

Gauss ilkokuldadır. Öğretmenin sınıftan ayrılmadan yapması gereken bir işi vardır ve öğrencilerin sessiz kalması gerekir. Öğretmen onları oyalamak için 1'den 100'e kadar sayıları toplamalarını ister. Öğrenciler toplamaya başlar; bu uzun ve sıkıcı bir iştir. Gauss sayıları gözünün önüne getirip daha kısa bir yol arar. Baştaki ile sondakinin toplamının 101 olduğunu, birini bir artırıp diğerini bir azaltınca toplamın yine 101 kaldığını görür. 50 tane 101 olduğuna göre bunları çarparak sonucu bulur.

Slaytta gösterilen (ekrandan, 00:35:00):

```text
1+2+3+4+...+97+98+99+100
50*101=5005
(N/2)*(N+1)
İlki çook hızlı olsa daha zeki mi olur?
```

Genel formül:

$$1+2+\dots+N = \frac{N}{2}(N+1)$$

$N=100$ için adım adım:

- Çiftler: $1+100 = 2+99 = \dots = 50+51 = 101$.
- Çift sayısı: $100/2 = 50$.
- Toplam: $50 \times 101 = 5050$.

> **Ders sonrası not:** Slayttaki "50*101=5005" bilerek yazılmış bir hatadır. Hoca, Gauss'un da bir insan olarak çarpmada hata yapabileceğini, örneğin 5050 yerine 5005 diyebileceğini göstermek için slaydı ders sırasında bu şekilde değiştirdi. Doğru sonuç $50 \times 101 = 5050$'dir (python ile kontrol edildi).

Hikayenin değiştirilmiş versiyonunda Gauss'un bir sınıf arkadaşı vardır. Bu arkadaş korkunç derecede hızlı ve hatasız toplama yapabilir. Gauss formülü keşfedip hesaplarken geçen sürenin onda biri kadar bir sürede toplamı bitirip doğru cevabı öğretmene söyler. Karşımızda iki öğrenci vardır:

- Birinci öğrenci çok hızlı ve hatasız işlem yapar, ama yeni bir yöntem bulmaz.
- İkinci öğrenci Gauss'tur: daha yavaştır, sonucu da yanlış olabilir, ama yeni bir yöntem keşfeder.

**Soru:** Turing'e hangi öğrencinin daha zeki olduğunu sorsak ne der? **Cevap:** Sınıftan gelen cevap birinci öğrenciydi. Sonuca odaklanırsak birinci öğrenci hem daha hızlı hem daha doğrudur; Gauss iki açıdan da başarısızdır. Birinci öğrenci aslında bir makineyi temsil eder.

Peki Gauss yerine bu öğrenciyi seçmek içimize siner mi? Sadece sonuca odaklanırsak yeni bir yöntemin keşfedilmesi gibi şeyleri göremeyebiliriz. Yalnız sonuca odaklanmak bakış açımızı çok daraltır.

### 5.1 Süreç ve sonuç tartışmasının önemi

Hocaya göre tartışmanın bir boyutu "süreç mi, sonuç mu?" sorusudur ve bu soru hayatımızı çok etkiler: insan ilişkileri, insanları değerlendirmemiz, çalışanların performans değerlendirmesi gibi. İkisi de önemlidir. Ancak sürecin bir sıkıntısı vardır: Çok sayıda kişi için süreci objektif olarak değerlendiremezsiniz. Bu yüzden pratikte sonuçlara bakılır. Süreci değerlendirmek, sonucu değerlendirmekten çok daha zordur. Yine de yalnız sonuca odaklanmak doğru değildir. Öğretmen sürece hiç bakmadan, "bunu nasıl yaptın?" diye sormadan değerlendirirse iki öğrenci arasında istemediğimiz bir sıralama oluşabilir.

Bu sırada bir öğrenci 1960'lardaki yapay zekanın bugün yalnızca isim değiştirdiğini, yapay sinir ağlarının yapay zeka diye yeniden sunulduğunu ileri sürdü. Hoca buna katılmadı: Bugünkü sistemlerin 1960'lardakilerle aynı olduğunu ya da yalnızca isim değişikliği olduğunu söylemek doğru değildir. Yapay sinir ağlarıyla beyni simüle etme çalışmaları bilgisayarlardan bile öncesine, 1943'e uzanır ve bunlar hâlâ yapay sinir ağları diye anılır.

## 6. Ned Block'un Soru-Cevap Ağacı ve Arnheim'ın Yöntem Sorunu

### 6.1 Ned Block'un soru-cevap ağacı

Bir diyalog ağacı düşünelim. Bu ağaç "şunu derse şunu de" gibi bire bir kurallardan oluşmaz; birkaç adımlık derinliği hesaba katar: "Önce şunu, sonra şunu, sonra şunu dedikten sonra şunu derse sen de şunu de." Çok karmaşık bir yapıdır ama sonuçta bir ağaçtır.

İki insan arasında geçebilecek bütün olası söyleşilerin bu ağaçta yer aldığını varsayalım. Böyle bir ağaç gerçekte depolanabilecek büyüklükte değildir, ama oluşturulduğunu varsayalım. Bu ağaç Turing testini geçer. Buna rağmen yapı çok basittir, yalnızca bir "if" yapısıdır ve ona zeki dememizi gerektirecek bir şey yoktur.

Ned Block'un söylediği şudur: Zeka yalnızca soruları zeki bir insandan ayırt edilemeyecek biçimde yanıtlama yeteneği değildir. Bir davranışı zeki diye adlandırmak, bu davranışın nasıl üretildiği hakkında bir önermede bulunmaktır. Yani sıfatı çıktıya değil, sürece veririz.

### 6.2 Rudolf Arnheim: Yöntem sorunu

Slaytta (ekrandan, 00:45:00):

- Zekanın çözebildiği her problemin sadece zeka ile çözüleceğini söyleyemeyiz.
- Zihinsel süreçler çıktıları aracılığıyla tanımlanmadıkça ya da zekanın işleyişine dair görüşümüz mekanist bir niteliğe kavuşmadıkça bilgisayarların kullandığı yönteme zekice denemez.

Birinci cümlenin anlamı şudur: İnsan bir problemi zekasını kullanarak çözüyor diye, o problemi çözen başka bir sisteme de zeka sahibi demek yanlıştır. Aynı problem zeka kullanmadan, başka yollardan da çözülebilir.

İkinci cümle iki durumda zeki denebileceğini söyler. Birincisi Turing gibi düşünmek, yani zihni yalnızca çıktılarıyla değerlendirmektir. İkincisi, günün birinde insan zekasının işleyişine dair bir algoritma bulunmasıdır. O durumda "zeka" ve "yapay zeka" diye iki ayrı kavram zaten kalmaz.

**Soru:** Bu tartışma IQ ve EQ ayrımına benziyor mu; yapay zekadaki zeka genelde mantıktır, duygusal zeka eksik kalmıyor mu? **Cevap:** Turing'in bakış açısıyla bu ayrımın önemi yoktur. İnsan gerektiğinde farklı zeka türlerini kullanıyor olabilir, ama arka tarafta ne olduğu Turing'i ilgilendirmez. Turing için önemli olan, sistemin dışarıdan bakıldığında insandan ayırt edilemeyecek kadar o işi yapabilmesidir.

## 7. Yapay Zekayı Gerçekleştirmede İki Yaklaşım

Yapay zekayı gerçekleştirme konusunda donanım ve yazılım eksenli iki görüş vardır. Burada "aşağı" donanımı, "yukarı" yazılımı ifade eder.

- **Aşağıdan yukarıcılar:** İnsan zekidir ve insanı zeki yapan beynidir. O halde beynin donanımını, yani sinir ağlarını model almalıyız. Ancak sinir ağları üzerinde çalışarak yapay zekaya ulaşabiliriz.
- **Yukarıdan aşağıcılar:** Uçaklar kanat çırparak uçmaz. Aynı şekilde yapay zekayı gerçekleştirmek için doğanın bulduğu çözümleri kullanmak şart değildir; yapay sinir ağlarına bağlı kalmak gerekmez. Amaç işin kendisini yapmaktır, donanıma odaklanılmamalıdır.

## 8. YZ Karşıtları: Searle, Gödel ve Lucas

Slaytta (ekrandan, 00:50:00):

- **John Searle:** Tek başına sentaks, ne miktarda olursa olsun, semantiği ortaya çıkarmaz. Bilgisayarlar işledikleri simgelerin anlamlarına dair hiçbir anlayışa sahip değildir. Anlam yoksa zeka da yoktur.
- **Gödel Teoremi:** İnsanların doğruluğunu bildiği ama makinelerin bunu ispatlayamadığı doğrular vardır.
- **John Lucas:** Böyle doğrular olduğuna göre insan zihni makinelerin kapasitesinin üzerindedir.

Sentaks burada şekilsel olanı, yani programı ve algoritmayı ifade eder; semantik ise anlamdır. "Anlam"ın tam olarak ne olduğu da soru işaretlidir. Searle'e göre bir programı takip eden şeye zeki denemez. Bilgisayarların tek yapabildiği program takip etmekse, bilgisayarlar hiçbir zaman zeki olamaz.

Gödel teoremi bir fikir değil, ispatlanmış bir sonuçtur. Gödel, bir sistemin içinde doğru olduğu halde o sistem içinde ispatlanamayan doğrular olduğunu gösteren eksiklik teoremini kanıtlamıştır. Bu sonuç yalnızca yapay zekayı değil, matematiği mantıksal temellere oturtma çabalarının hepsini sarsmıştır. Lucas bu teoremi şöyle yorumlar: Mantığın ispatlayamadığı ama insanın doğruluğunu bildiği doğrular varsa, insan zihni makinenin kapasitesinin üzerinde kalacaktır.

> **Ek bilgi (derste anlatılmadı):** Lucas'ın bu argümanı felsefede "Lucas-Penrose argümanı" olarak da bilinir ve tartışmalıdır. Karşı görüşe göre insanların da kendi tutarlılıklarını kanıtlayamadıkları için Gödel sınırlamasından muaf oldukları gösterilmiş değildir.

### 8.1 Turing ile Searle

Slaytta (ekrandan, 00:55:00):

- Turing: "Makineler düşünebilir mi?" sorusu felsefi bir yaklaşımdan ziyade deneysel bir yaklaşımla ele alınmalı. Çünkü ilki sonuç vermiyor.
- Searle: Deneysel bir yaklaşım olamaz. Çünkü bir programı takip eden şey asla düşünemez.
- ?: İnsanlar da bir programı takip ediyor olabilirler mi?

Son soru tartışmayı kökünden etkiler: İnsanlar da bir program izliyorsa bu tartışmanın bir anlamı kalmaz. Hocaya göre insanlar çok farklı kültürlerde de olsalar benzer durumlarda benzer davranabilirler; biyolojik yapıdan gelen bazı refleksler ve belli gelişim evreleri vardır. Ama bütün düşünce süreçlerinin belli bir algoritmayı izlediğini söylemek çok yanlış olur. Sorunun cevabı henüz bilinmemektedir. İnsanların çeşitliliğine ve dünyanın çok da tahmin edilebilir bir yer olmamasına bakarak bir program izlenmediği çıkarımı yapılabilir.

## 9. Organik Süreç Ölçütü Üzerine Bir Soru

Aradan önce bir öğrenci sohbet penceresinden bir soru yazmıştı; hoca bu soruyu aradan sonra ele aldı.

**Soru:** Bir varlık organik tabanlı süreçler dışında bir yanıt oluşturuyorsa zeki değildir desek sorun çözülmüş olmaz mı? **Cevap:** Pek olmaz, çünkü insanları değerlendirme ölçütümüz böyle değildir. Biriyle uzun süre yalnızca yazıştığınızı, onu hiç görmeden arkadaş olduğunuzu düşünün. O kişinin cevaplarını organik bir süreçle ürettiğinden emin olamazsınız; bir makine de olabilir. Dışarıdan ölçebildiğiniz hiçbir şey organikliğe dair bilgi vermez. Bu yüzden organikliği tek ölçüt olarak kullanmak mümkün görünmez.

Hoca bir filmi de örnek verdi: Bir insanın aşık olduğu şeyin daha sonra bir program olduğunu öğrendiği "Her" adlı film. Ayrıca kendisini örnek verdi: Sınıfta ders anlatan biri dışarıdan bakıldığında insandan ayırt edilemiyorsa, beyninin içinde ne olup bittiğini bilmeseniz de ona insana verdiğiniz sıfatı verirsiniz.

Hoca bu bölümü şöyle bağladı: Geçen ders ve bu derste konuşulan konuların hiçbiri "doğru cevap şudur" denebilecek konular değildir; hepsi "şöyle olsa" diye ilerleyen spekülasyonlardır. Amaç bu konudaki fikirleri ve dayanaklarını göstermektir. Önümüzdeki yıllarda makinelerle daha çok karşılaşacağımız için bu konular hayatımıza girecektir.

## 10. Yapay Zekanın Kısa Tarihi

Tarihçe 1943'ten başlar, ama fikir olarak çok daha eskiye gider. Slaytta (ekrandan, 01:10:00):

- 1943: McCulloch ve Pitts, ilk yapay nöron tasarımı.
- 1949: Hebbian öğrenme kuralı (iki nöron aynı anda aktif olurlarsa aralarındaki bağ güçlenir).
- 1950: Turing'in makalesi.
- 1951: İlk yapay sinir ağı bilgisayarı (Minsky ve Edmonds).

### 10.1 İlk yapay nöron

McCulloch ve Pitts'in yaptığı, AND ve OR gibi mantık işlemlerinin ve bunların birbirine bağlanmasıyla oluşan kararların bir nöron tarafından temsil edilebildiğini göstermektir. Nöronlarla AND kapısı ve OR kapısı yapılabilir. AND ve OR gibi yapılar mantıksal düşünce süreçlerimizin temel yapı taşlarıysa, nöronlar da bunları gerçekleyebilir.

> **Ek bilgi (derste anlatılmadı):** McCulloch-Pitts nöronu girişlerin toplamını bir eşik değerle karşılaştırır. Örneğin iki ikili girişte eşik 2 seçilirse nöron AND, eşik 1 seçilirse OR gibi davranır.

### 10.2 Hebb kuralı ve Pavlov'un köpekleri

Hebb kuralı öğrenmenin fiziksel altyapısını açıklar: Öğrenme, beyindeki hücrelerin birbirleriyle bağlantılarındaki değişimdir. Kural şudur: İki nöron aynı anda ya da çok kısa aralıklarla aktif olurlarsa aralarındaki bağ güçlenir.

Hoca bunu Pavlov'un şartlı refleks deneyiyle açıkladı. Pavlov zil çaldıktan sonra köpeğe yemek verir ve bunu defalarca tekrarlar. Bir süre sonra yalnızca zil çalar; köpeğin ağzı yemeğe hazırlanır, salya akar. Beyinde olan şöyledir:

- Bir tarafta zil sesi duyulduğunda uyarılan nöronlar vardır.
- Diğer tarafta salya akıtma emrini veren motor nöronlar vardır.
- Başlangıçta bu iki nöron grubu arasında bir ilişki yoktur; deney yapılmadan zil çalınırsa ağız sulanmaz.
- İki olay defalarca art arda gelince aralarında bir bağ oluşur ya da var olan zayıf bağlar güçlenir.
- Artık zil sesi duyulunca bağlı nöronlar da aktive olur ve salya akar.

Yapay sinir ağlarının terminolojisiyle söylersek öğrenme ağırlık güncellemesidir.

### 10.3 Büyük beklentiler dönemi

İlk yapay nörondan 8 yıl sonra, 1951'de birçok nörondan oluşan ilk yapay sinir ağı bilgisayarı yapıldı ve biraz daha karmaşık problemler çözülebildi. Bu ilk kıvılcımlardan sonra büyük beklentiler dönemi başladı:

- Turing aynı makalesinde 50 yıl içinde sıradan sorgulayıcıların belli bir süre yazıştıktan sonra karşısındakinin insan mı makine mi olduğuna doğru karar veremeyeceğini öngördü. <!-- BELİRSİZ: Altyazıda "en az %35'lik bir diyalog" geçiyor; slayt küçük resminde oran ve süre okunamıyor. Turing'in makalesindeki öngörü büyük olasılıkla "5 dakikalık sorgudan sonra doğru tanıma şansının %70'i geçmemesi"dir. -->
- 1957'de Newell ve Simon 10 yıl içinde dünya satranç şampiyonunun bir bilgisayar olacağını söyledi.
- 1950-60 arasında otomatik dil çevirisinin çok yakın olduğu düşünüldü.

Bunların hiçbiri söylenen sürede gerçekleşmedi. Turing testi hâlâ geçilmiş değil. Satranç hedefi 10 değil 40 yıl sonra, 1997'de gerçekleşti. Otomatik çeviride ise bugün biraz düzeltme ile işimizi görecek sistemler var.

### 10.4 Neden gerçekleşmediler?

Slaytta (ekrandan, 01:15:00):

- Dünya / sağduyu (commonsense) bilgisinin büyük etkisi. Bu, dersin sonunda yeniden ele alındı ve henüz tam çözülmüş bir problem değil.
- Problemlerin karmaşıklığının üstel olması. Satrancın 40 yılda çözülmesinin nedeni algoritmalardaki büyük gelişmeler değil, hesaplama kabiliyetlerindeki büyük gelişmelerdir.
- Kısıtlı dünyaların (microworlds) gerçek dünyaya model olamaması. Çok gerçekçi bir dünya simülasyonu yapılamaz; oyunlarda ya da simülasyonda çalışan algoritmalar gerçek hayatta çalışmayabilir.

### 10.5 1966-1973: Zor dönem

Bu dönemde fonlar durdu ve araştırmacıların ilgisi azaldı. <!-- BELİRSİZ: Altyazıda bu slaydın başı kayıp (yaklaşık 01:14:40-01:16:35 arası bozuk); Minsky ve Papert'in hangi problemi gösterdiği altyazıda geçmiyor, slayt küçük resmi okunamıyor. --> Altyazıdan anlaşılan şudur: Minsky ve Papert'in yapay sinir ağlarının çözemeyeceğini söylediği problemlerin, aynı yıl (1969) çok katmanlı yapay sinir ağlarıyla çözülebildiği gösterildi. Bugün bu çok katmanlı ağlara derin yapay sinir ağları diyoruz. <!-- BELİRSİZ: Altyazıda "Bryson ve Hall"; büyük olasılıkla Bryson ve Ho. --> Sıkıntı şuydu: O zamanlar ağırlıkları insanlar elle buluyordu. Bugün geri yayılım (backpropagation) diye bildiğimiz eğitim algoritmaları 80'lerin başında ortaya çıktı. O zamana kadar bir yapay sinir ağının bir problemi çözmesi için uygun ağırlıkların insanlarca atanması ve ince ayarlanması gerekiyordu. Mimari vardı ama nasıl eğitileceği bilinmiyordu.

Bunun etkisi uzun sürdü: Yapay sinir ağlarına ilgi 2012'ye kadar diğer makine öğrenmesi algoritmalarına göre daha azdı. 2012'deki başarılardan sonra çok sayıda araştırmacıyı kendi tarafına çekti.

> **Ek bilgi (derste anlatılmadı):** Minsky ve Papert'in 1969 tarihli "Perceptrons" kitabının en bilinen sonucu, tek katmanlı algılayıcının XOR gibi doğrusal olarak ayrılamayan problemleri çözemeyeceğidir. Bu sonuç büyük olasılıkla burada kastedilen problemdir.

Otomatik çeviri sistemlerinde de bu dönemde oldukça kötü sonuçlar alındı.

### 10.6 1979-1990: Güzel zamanlar

Slaytta (ekrandan, 01:20:00):

- Uzman sistemlerin ortaya çıkışı: kural tabanlı, sonuçları insanlarca kolaylıkla anlaşılabilen, kısıtlı alanlarda uzmanlık görevi gören sistemler (örnek: MYCIN, kan enfeksiyonlarının analizi).
- 1981-1991: Japonya, Prolog temelli çalışan zeki makineler üretmek için "Fifth Generation" adlı projesini duyurdu.
- Amerika ve Avrupa geride kalmamak için YZ projelerine büyük paralar yatırdı.
- Yazılımda yeni klişe: "now with AI!" (tanıdık geliyor mu?).
- YZ firmalarının sayısında büyük artış.

Uzman sistemler genel bir alanda değil, dar bir alanda uzmandır: genel bir "doktor" uzman sistemi değil, belirli bir hastalığın uzman sistemi gibi.

**Soru:** Kural tabanlı sistemlerin yapay sinir ağlarına göre avantajı ne olabilir? **Cevap:** Açıklanabilir olmaları, yani kararlarını neden öyle verdiklerini net biçimde söyleyebilmeleri.

**Soru:** Bu sonuç açısından mı, süreç açısından mı önemli? **Cevap:** Bir öğrenci süreç açısından önemli olduğunu söyledi. Hoca sonuç açısından da önemli olabileceğini bir hukuk örneğiyle açıkladı. Hukuk sisteminde karar veren bir uzman sistem kurarsanız yalnızca kararı değil gerekçesini de istersiniz. "Sana şu cezayı veriyorum" demek yeterli olmaz; insanlar doğal olarak "neden?" diye sorar. Mahkemelerde de önce karar açıklanır, sonra gerekçeli karar yazılır. İnsanın "neden" sorusuna bir zaafı vardır; bir kararın neden alındığı bizim için önemlidir.

Ama açıklanabilirlik tek ölçüt değildir. Hocanın sorusu: Bir sistemin kararlarının başarısı %90 ama kararlarını açıklayamıyor; başka bir sistemin başarısı %70 ama kararlarını çok iyi açıklıyor. Hangisini kullanmak mantıklı? Açıklanabilirliğin çok önemli olduğu noktalar vardır ve bu konuda çok sayıda çalışma sürmektedir. Kural tabanlı sistemler bu açıklanabilir kararları sayesinde vaktiyle oldukça popüler olmuştur.

Japonya'nın Fifth Generation projesinin arkasında teknolojik minyatürleştirmedeki büyük başarısını sürdürme isteği vardı. Ardından tersi oldu: Fifth Generation durdu, Prolog temelli mimarilerin beklenen sonuçlara erişemediği görüldü. Yapay zeka daha mütevazı hedeflere döndü: bilinen problemlere uygulanmak, belli konularda işe yarar şeyler yapmak. Hocaya göre günümüzde bu yine değişmiş görünüyor; genel yapay zeka üzerine çok çalışma var ve etkileyici sonuçlar alınmaya başlandı.

## 11. Günümüz

Slaytta (ekrandan, 01:25:00):

- Deep Blue Garry Kasparov'u 1997'de yendi.
- 2018: Go, StarCraft ile yenilgilerimiz devam ediyor.
- Sürücüsüz arabalar (Darpa yarışması, 132 mil).
- Mars'ta otonom bir robot.
- Konuşmayı yazıya çeviren programlar (Google Speech to text).
- Hava tahmin sistemleri artık daha ileriki tarihlerde ve daha küçük zaman aralıklarında çalışıyorlar.

### 11.1 Oyunlar

Deep Blue ile satranç karmaşıklığındaki bir oyunda bilgisayarlar insanları yendi. Ancak Go ve StarCraft satrançtan çok daha karmaşıktır ve bu yüzden insanlar 2018'e kadar dayanabildi. Bu karmaşıklığın ne anlama geldiği dersin ilerleyen haftalarında oyun slaytlarında görülecek.

### 11.2 Sürücüsüz arabalar

Sürücüsüz arabalar uzun zamandır geliştiriliyor, ama hiç bu kadar olabilirliğe yakın olmamıştı. Hoca sınıfa sürücüsüz bir arabaya binip binmeyeceklerini sordu. Birkaç öğrenci bineceğini söyledi; bir öğrenci müdahale edebilmek için sürücü koltuğuna oturmayı tercih edeceğini, bir başkası hız limiti varsa bineceğini söyledi. Bulunulan yerin ve yolun (örneğin otoban) önemli olduğu da konuşuldu.

Hocaya göre bu araçların insanların kullandığı araçlarla aynı ortamda bulunmasının sıkıntıları olabilir, ama vaat ettikleri faydalar çok büyük. Arabaların büyük bir kısmı zamanının çoğunu bekleyerek geçirir. İnsanlar koordineli hareket edemez: tahmin edilemez, umursamaz ya da yalnız kendini düşünen yönleri vardır. Makineler arasında bu sorun olmayacağı için bütün araçlar birlikte optimize edilerek trafikte mükemmel sonuçlar alınabilir.

### 11.3 Mars'ta otonom robot

Mars'taki bir robotun neden otonom olması gerekir? Robotu kamerasından gelen görüntüye bakarak kumandayla yönetmeye kalktığınızı düşünün. Ekranda robotun derin bir kratere yaklaştığını gördüğünüz anda robot aslında çoktan kraterin dibine düşmüştür, çünkü arada gecikme vardır. Gecikmeli kontrol mümkündür ama verimli değildir. Mars görece durağan bir ortam olduğu halde sorun çıkabiliyorsa, daha dinamik ortamlarda uzaktan kontrol hiç mümkün olmaz. Bu yüzden bu tür robotların belli bir düzeyde otonom olması gerekir.

### 11.4 Hava tahmini

Hava tahmin sistemleri artık çok daha yüksek çözünürlüklü tahminler verebiliyor: "Yarın saat 13'te yağmur başlayacak, 14.30'a kadar sürecek" gibi. Ama bir ay sonrasının hava durumunu iyi tahmin edebilen bir sistem hâlâ yok; alan gelişmeye açıktır.

### 11.5 ChatGPT

Kasım 2022'de ChatGPT çıktı. Hocaya göre komik hatalar yapsa da mevcut halinden çok potansiyeline bakmak gerekir. Halka açılması sayesinde belki daha önce hiç toplanmamış büyüklükte bir veri toplandı; kullanıcı sayısındaki artış Facebook'un artışını bile geçti. Bu yeni veriyle yeniden eğitildikçe sonraki sürümlerin çok daha iyi olması beklenir. "Zeki midir, değil midir" tartışmasının burada çok anlamı yoktur; etkileyici bir sistem olduğu söylenebilir.

Hoca bu kadar iyi bir sistemin bu kadar kısa sürede ortaya çıkmasının kendisini şaşırttığını, insanların bu kadar tahmin edilebilir olmasının biraz canını sıktığını söyledi: İnsanların yaptığı işler ve bulduğu çözümler çok geniş bir dağılım göstermiyor gibi görünüyor. Bu, insanların yaptığı işlerin büyük kısmının makinelerce yapılabileceği argümanını destekliyor. Yazılım açısından işler hızlanacak; beş kişinin işini bir kişi yapabilecek. Özellikle sürekli aynı yolu izleyen rutin işler (bir müşteri için yapılan web sayfasının başka müşteriler için küçük değişikliklerle uyarlanması, bir sektördeki bir firma için hazırlanan reklamın aynı sektördeki başka bir firmaya uyarlanması gibi) makinelere devredilebilir görünüyor.

## 12. Kimine Kolay, Kimine Zor

Makineler için kolay, insanlar için zor görevler nelerdir? Satranç oynamak, ders programı ya da haftalık program gibi planlamalar yapmak, bilgisayar oyunları, büyük sayıları çarpmak insan için zordur. Bunlar formal tanımlarla bütün durumlarına erişilebilen sistemler ve simülasyon dünyalarıdır; makineler bunlarda insanlardan çok iyidir.

Peki tersi? Slaytta (ekrandan, 01:40:00):

- İnsanlar için kolay, makineler için zor görevler:
  - 1 4 9 61 ?
  - Bongard problemleri
  - Dil anlama
  - Resim anlama
  - Dünya bilgisi (Ör: Balıkların kaç ayağı var?)
  - Değişkenliğin yüksek olduğu, olası tüm durumların kapsanamadığı problemler

### 12.1 Sayı dizisi

Hoca "1 4 9 61 ?" dizisinde soru işaretinin yerine ne geleceğini sordu ve insanların bunu çözebildiğini belirtti. Makineler için neden zordur? Yeni bir durumla karşılaştığınızda, o duruma çok benzeyen durumları daha önce gördüyseniz karar vermek çok kolaylaşır. Bir kedi resmine kedi demeniz, daha önce ona ne kadar benzeyen şeyler gördüğünüzle ilgilidir. Kediler birbirine benzer, ama "dizide sonraki sayıyı bul" problemleri birbirine benzemez. İyi bir problem öncekilere en az benzeyendir.

Makineler örnekler arasında benzerliğin çok olduğu, benzerlerini gördükleri problemlerde iyidir. ChatGPT'ye bu diziyi sorsanız cevabı söyler, çünkü cevap internette her yerde vardır. Önemli olan internette olmayan, sizin uydurduğunuz yepyeni bir problemdir; makine onu çözemez.

### 12.2 Bongard problemleri

Bongard insanlar için bir dizi problem hazırlamıştır. Derste 62 numaralı problem gösterildi (BP#62, ekrandan, 01:45:00). Bir defter sırtıyla ayrılmış iki grup vardır: solda altı şekil, sağda altı şekil. Soru, soldaki altı şekli sağdaki altı şekilden neyin ayırdığıdır.

- Soldaki şekiller: dalgalı ve kıvrımlı eğriler, S biçimli eğriler, düz bir çizgi ve bir spiral; hepsi tek çizgiyle çizilmiş açık eğrilerdir.
- Sağdaki şekiller: fasulye biçimli, damla biçimli, papyon benzeri ya da kendi üstüne kıvrılan şekiller; bunlar da tek çizgiyle çizilmiş eğrilerdir.

Bir öğrenci sağdaki şekillerde çizginin başlangıç ve bitişinin yakın, soldakilerde uzak olduğunu söyledi; hoca da bu problemde ayırt edici ölçütün başlangıç ve bitiş noktaları arasındaki uzaklık olduğunu belirtti.

Başka bir öğrenci şaka yollu iki grubu "defterin tellerinin" ayırdığını, bunu bir makinenin söyleyemeyeceğini söyledi. Hoca, internette biri buna böyle bir cevap yazdıysa makinenin de söyleyebileceğini belirtti; makinelerin internetteki bilgiyi kullanması burada kritik bir noktadır. Bir öğrenci ayrıca şekillerin makineye bizim gördüğümüz biçimde mi yoksa her resim ayrı ayrı mı verildiğinin de önemli olduğunu ekledi; telleri vermezseniz makine teller hakkında bir şey söyleyemez. Hoca buna katıldı.

Bu problemler makineler için zordur, çünkü her problemin ayırt edici ölçütü farklıdır. Makine bu problemi çözmeyi öğrense ve sonra şekilleri farklı ama ölçütü yine "başlangıç-bitiş uzaklığı" olan bir problem verilse muhtemelen çözer. Ama başka bir problemde ayırt edici olan şey bambaşkadır. İnsanların adaptasyon kabiliyeti daha iyidir.

## 13. Dünya Bilgisi

Hoca bir fotoğraf gösterdi ve ne olduğunu sordu (ekrandan, 01:50:00). Fotoğrafta bir koridorda takım elbiseli bir grup insan var; biri bir tartıda tartılırken arkasından biri ayağını tartıya basıp ağırlığını artırıyor, diğerleri gülüyor.

Öğrenciler tartılan kişiye şaka yapıldığını, arkadakinin ayağını tartıya koyarak ağırlığını artırdığını söyledi. Bir öğrenci evde tartılırken bunun çoğu insanın başına geldiğini ekledi.

Hocanın vurgusu şudur: Bu olayı anlamak için tartı aletinin nasıl çalıştığını, temel mekanizmasını bilmek gerekir. Ayağını tartıya bastırınca gösterilen ağırlığın artacağını bilmeden buradaki espriyi anlamak mümkün değildir. Dünya bilgisi, dünyanın nasıl işlediği ve nasıl bir yer olduğu hakkındaki bilgidir.

Gelişmiş görüntü işleme araçları bu resimdeki kişilerin kim olduklarını yüzlerinden tanıyabilir; vücut pozisyonlarını, birbirlerine göre konumlarını, etraftaki dolapları, aynaları ve tartıyı belirleyebilir, hatta kimin güldüğünü söyleyebilir. Ama resmin bütününün anlattığı şey, parçaların toplamından daha büyüktür; güldüren şeyi anlamak için dünya bilgisine ihtiyaç vardır.

Bu resmi anlayabilen programlar yazılabilir mi? Evet; 62 numaralı Bongard problemini çözen bir program da yazılabilir. Asıl soru, yepyeni bir şaka geldiğinde makinelerin onu anlayabilip anlayamayacağıdır. Hocaya göre bu konuda çok büyük laflar etmemek gerekir. İyi espri yapan insanlara genelde zeki deriz; şaka yapabilmek ve şakaları anlayabilmek zeka ile ilişkili görünür. Dünyadaki yüz bin şakayı ve açıklamalarını bir sisteme verdikten sonra yepyeni şakaları anlayacak düzeye gelip gelmeyeceği kesin değildir; belki o yüz bin şaka insanların şaka üretme varyasyonlarının hepsini içerebilir. Bir öğrencinin kara mizah üretip üretemeyeceği sorusuna da hoca, insanların ürettiği milyonlarca örnekten yepyeni bir şey üretip üretemeyeceğine "hayır" demenin kolay olmadığını söyledi. Slayttaki "kimine kolay, kimine zor" listesi zaman içinde giderek kısalabilir.

### 13.1 ChatGPT ve mantıksal çıkarım

Hoca bir soru hatırlattı: "Bir yarışmada ikinciyi geçersen kaçıncı olursun?" ChatGPT bu soruya "üçüncü" ya da "birinci" gibi yanlış cevaplar veriyordu ve doğru cevaba ikna etmek de zordu. Ancak insanların bir kısmı da bu soruya "birinci" diye yanlış cevap verir.

Hocaya göre bunun nedeni büyük olasılıkla şudur: Sistem internetten topladığı bilgiler üzerinden ilerler; arkada mantıksal bir çıkarım mekanizması çalışmaz. İnternette o konuda en sık yazılan şey neyse kabaca onu verir. Bu yüzden herkesin yanlış bildiği bir şeyin doğrusunu söyleme ihtimali yoktur.

## Örnek Sorular

### Soru 1

(ekrandan, 00:15:00) Slayttaki ELIZA diyaloğunda kırmızı ve siyah satırlardan hangisi insan, hangisi makinedir? Nereden anlaşılır?

> **Çözüm (derste verildi):** Siyah (büyük harfli) satırlar makinedir. İpuçları: makine terapist rolündedir, karşısındakinin cümlesini dönüştürüp soru olarak geri verir; bağlamı tutamaz, yalnızca son cümleye bağlı kalır ("My father." cümlesine "YOUR FATHER" diye karşılık vermesi).

### Soru 2

(ekrandan, 00:20:00) Searle'ün Çin odasında: İçerideki insan Çince biliyor mu? Oda Çince biliyor mu? Biliyor gözükmesi yetmez mi?

> **Çözüm (derste verildi):** İçerideki insan Çince bilmez. Turing'e göre oda Çince biliyordur, çünkü dışarıdan Çinli bir insandan ayırt edilemez. Searle'e göre biliyor gözükmesi yetmez; içeride yalnızca bir programı izleyen basit bir mekanizma vardır ve sentaks semantik üretmez.

### Soru 3

(derste sözlü, 00:22:05) Çin odası benzetmesinde içerideki insan, kural kitabı ve çekmecelerdeki veri neyi temsil eder?

> **Çözüm (derste verildi):** İnsan işlemciyi, kural kitabı programı (kodu), çekmecelerdeki kağıtlar veriyi temsil eder.

### Soru 4

(ekrandan, 00:35:00) $1+2+3+\dots+100$ toplamını bir öğrenci çok hızlı ve hatasız toplayarak, Gauss ise $(N/2)(N+1)$ formülünü keşfederek ama daha yavaş ve belki hatalı hesaplıyor. İlki çok hızlı olsa daha zeki mi olur?

> **Çözüm (derste verildi):** Doğru toplam $\frac{100}{2}\cdot 101 = 50 \times 101 = 5050$'dir (slayttaki 5005 kasıtlı hatadır). Yalnız sonuca bakan Turing tarzı bir değerlendirme hızlı ve hatasız öğrenciyi, yani makineyi, daha zeki sayar. Ama bu bakış Gauss'un yeni bir yöntem keşfetmesini göremez. Hocanın vardığı sonuç: Süreç ve sonuç ikisi de önemlidir; yalnız sonuca odaklanmak bakış açısını daraltır.

### Soru 5

(derste sözlü, 01:05:10) Bir varlık organik tabanlı süreçler dışında bir yanıt oluşturuyorsa zeki değildir desek sorun çözülmüş olmaz mı?

> **Çözüm (derste verildi):** Hayır. Yalnızca yazıştığımız birinin cevaplarını organik bir süreçle üretip üretmediğini dışarıdan ölçemeyiz. Organiklik dışarıdan gözlenebilen bir özellik olmadığı için tek ölçüt olarak kullanılamaz.

### Soru 6

(derste sözlü, 01:19:06) Kural tabanlı sistemlerin yapay sinir ağlarına göre avantajı nedir? Bir sistem %90 başarılı ama kararlarını açıklayamıyor, diğeri %70 başarılı ama kararlarını çok iyi açıklıyor; hangisini kullanmak mantıklıdır?

> **Çözüm (derste verildi):** Avantaj açıklanabilirliktir. İkinci soruya derste tek bir cevap verilmedi: Hoca açıklanabilirliğin tek ölçüt olmadığını, ama hukuk gibi gerekçenin şart olduğu alanlarda çok önemli olduğunu vurguladı.

### Soru 7

(ekrandan, 01:40:00) "1 4 9 61 ?" dizisinde soru işaretinin yerine ne gelir?

> **Çözüm (derste verilmedi):** Dizi $1^2, 2^2, 3^2, 4^2, \dots$ kare sayılarının basamakları ters çevrilerek yazılmış halidir: $1, 4, 9, 16 \to 61$. Sonraki terim $5^2 = 25$ sayısının tersi olan **52**'dir. (Sonraki terimler 63, 94; python ile kontrol edildi.)

### Soru 8

(ekrandan, 01:45:00) Bongard problemi 62: Soldaki altı şekli sağdaki altı şekilden ne ayırır?

> **Çözüm (derste verildi):** Bir öğrencinin cevabı ve hocanın onayıyla: Sağdaki şekillerde çizginin başlangıç ve bitiş noktaları birbirine yakındır, soldakilerde uzaktır.

### Soru 9

(ekrandan, 01:40:00) Dünya bilgisi örneği: Balıkların kaç ayağı var?

> **Çözüm (derste verilmedi):** Balıkların ayağı yoktur. Bu soru, cevabı için dünyanın nasıl bir yer olduğuna dair sağduyu bilgisi gerektiren bir soru örneğidir.

### Soru 10

(ekrandan, 01:50:00) Fotoğrafta ne oluyor? Bunu nasıl anladınız?

> **Çözüm (derste verildi):** Tartılan birine şaka yapılıyor: Arkadaki kişi ayağını tartıya basarak gösterilen ağırlığı artırıyor. Bunu anlamak için tartının nasıl çalıştığını bilmek, yani dünya bilgisi gerekir.

### Soru 11

(derste sözlü, 01:53:04) Bir yarışmada ikinciyi geçersen kaçıncı olursun?

> **Çözüm (derste verilmedi):** İkinci olursun; ikinciyi geçen onun yerini alır, birinci hâlâ öndedir. Derste bu sorunun ChatGPT'ye sorulduğunda "üçüncü" ya da "birinci" gibi yanlış cevaplar alındığı ve insanların bir kısmının da "birinci" dediği anlatıldı.

## Dersin Toparlaması

Bu derste yapay zekaya giriş tamamlandı. Turing testi, bir sisteme zeki demek için yalnız dışarıdan ölçülebilen davranışa bakan bir ölçüt olarak tanıtıldı. ELIZA, şablon tabanlı basit bir programın bile bazı insanları kandırabildiğini ama testi geçemediğini gösterdi. Searle'ün Çin odası, Ned Block'un soru-cevap ağacı ve Arnheim'ın yöntem sorunu, davranışın nasıl üretildiğinin de önemli olduğunu savunan karşı görüşlerdir. Gauss ve hızlı toplayan sınıf arkadaşı örneği bu süreç-sonuç tartışmasını somutlaştırdı. Gödel teoremi ve Lucas'ın yorumu ise insan zihninin makinelerin üzerinde kalacağı görüşünü destekleyen argümanlar olarak sunuldu.

İkinci yarıda 1943'teki ilk yapay nörondan günümüze yapay zekanın tarihi izlendi: büyük beklentiler dönemi, bu beklentilerin sağduyu bilgisi, üstel karmaşıklık ve kısıtlı dünyalar yüzünden tutmaması, uzman sistemlerin yükselişi ve Fifth Generation projesi, Deep Blue'dan ChatGPT'ye uzanan günümüz başarıları. Son olarak insanlara kolay ama makinelere zor görevler (dizi tamamlama, Bongard problemleri, dil ve resim anlama, dünya bilgisi) tartışıldı. Oyunların karmaşıklığı dersin ilerleyen haftalarındaki oyun konusunda yeniden ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
