# Ders 1 Genişletilmiş Notu: Yayın Temelli İleri İşletim Sistemleri ve Bilimsel Makale İnceleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yaklaşımı: Ders Kitabı Yerine Özgün Yayınlar
- 2. Dersin Kapsadığı Konu Alanları
- 3. Bir Yayını İnceleme Çerçevesi
- 4. Bilimsel Makale Okuma Yöntemi
- 5. Bilimsel Üslupla Değerlendirme Yazmak
- 6. Tartışma Temelli Ders ve Teknoloji ile Akademinin Etkileşimi

## 1. Dersin Yaklaşımı: Ders Kitabı Yerine Özgün Yayınlar

Bu ilk ders, dersin içeriğini ve işleyişini tanıtan kısa bir giriş oturumudur. Kayıt boyunca ekranda slayt, tahta ya da kod yoktur; yalnız hocanın Zoom ad kutucuğu görünür. Bu nedenle notun tamamı hocanın sözlü anlatımına dayanır.

Hoca, dersin hem yüksek lisans hem doktora düzeyinde alındığını ve bu yüzden lisans dersine göre öğrenciye düşen sorumluluğun çok daha fazla olduğunu belirterek başladı. Dersin adı ileri işletim sistemleridir, ama ders klasik bir konu anlatımı biçiminde işlenmez. İşletim sistemi kavramının ortaya atıldığı zamandan günümüze kadar, işletim sistemleri açısından önemli dönüm noktalarını belgeleyen ya da anlatan yayınlar üzerinden gidilir.

Dersin özel bir ders kitabı yoktur. Hocanın gerekçesi, işlenecek konuların yelpazesinin tek bir kitaba sığmayacak kadar geniş olmasıdır. Bunun yerine, kavramların ortaya atıldığı dönemde o çalışmaları yapan araştırmacıların kendi yayınları okunur. Hoca bu amaçla yaklaşık 40-43 yayın derlediğini, bunların uzunluğunun 10 sayfa civarından 20 sayfaya yakın olana kadar değiştiğini söyledi.

Bu yaklaşımın amacı şudur: bugün modern işletim sistemi dediğimiz sistemlerde, masaüstü bilgisayarımızda, dizüstü bilgisayarımızda ve hatta cep telefonumuzda alışageldiğimiz özelliklerin nasıl ortaya çıktığını, nasıl araştırıldığını ve nasıl şekillendirildiğini kaynağından görmek.

## 2. Dersin Kapsadığı Konu Alanları

Hoca, dersin ne kadar geniş bir alana yayıldığını göstermek için bazı örnek konular saydı:

- Erişim hakları (access rights).
- Donanımın daha iyi kullanılması.
- Sanallaştırma.
- Prosesler arası haberleşme. Bu da kendi içinde farklı biçimler alır:
  - Aynı donanım içinde yapılan haberleşme.
  - Farklı donanımlar arasında yapılan haberleşme.
  - Araya ağ (network) katmanı sokularak yapılan haberleşme.
- Proseslerin ya da iş parçacıklarının (thread) bir sistemden başka bir sisteme göç ettirilmesi (migration).

Hoca listeyi "aklınıza gelebilecek" her türlü konu diye bitirdi; yani bu liste kapsamı göstermek içindir, eksiksiz bir konu listesi değildir.

> **Ek bilgi (derste anlatılmadı):** Proses göçü (process migration), çalışmakta olan bir prosesin durumunun (bellek içeriği, yazmaçlar, açık dosyalar gibi) bir makineden alınıp başka bir makinede kaldığı yerden sürdürülmesidir. Yük dengeleme, bakım için makine boşaltma ve veriye yakın çalışma gibi amaçlarla dağıtık sistemlerde araştırılmıştır.

## 3. Bir Yayını İnceleme Çerçevesi

Dersin merkezindeki beceri, bir araştırma yayınını sistemli biçimde incelemektir. Hoca her yayın için şu soruların cevaplanmasını istedi.

### 3.1 Temel katkı

İlk soru, yayının temel katkısının ne olduğudur. Hoca bunun İngilizcede "contribution" diye anıldığını belirtti. Bir yayını okuyup ondan tek bir şey çıkarılacaksa, çıkarılması gereken budur.

### 3.2 Hipotez

Hoca bir yayını bir tez gibi düşünmeyi önerdi: katkının sağlanabilmesi için ortaya bir hipotez atılmış olması gerekir. Bu hipotezin ne olduğu, neyin ispatlanmaya ya da gösterilmeye çalışıldığı belirlenir.

### 3.3 Yöntem

Sonra bunun hangi yöntemlerle yapıldığına bakılır: nasıl bir teorik ya da pratik akış izlenerek gerçekleştirildiği.

### 3.4 Sonuçlar ve karşılaştırma

Elde edilen sonuçlar ve bu sonuçların mevcut durumla başarı açısından nasıl karşılaştırıldığı incelenir. Yöntem iyi mi, kötü mü; durumu nasıl iyileştiriyor?

### 3.5 Ödünleşim

Hoca burada özel bir uyarı yaptı: bir şeyi iyileştirirken başka bir taraftan taviz vermek gerekebilir, hatta başka bir taraf daha kötüleşebilir. Bir yayını değerlendirirken yalnız kazanılanlara değil, bu kazanç için verilen bedele de bakmak gerekir.

> **Ek bilgi (derste anlatılmadı):** İşletim sistemleri araştırmalarında tipik ödünleşimler arasında başarım ile güvenlik ya da yalıtım, gecikme ile verim (throughput), bellek kullanımı ile hız ve genellik ile basitlik sayılabilir. Bir yayının değerlendirme bölümünde bu bedelin ölçülüp ölçülmediğine bakmak, incelemenin kalitesini artırır.

### 3.6 Açık noktalar ve gelecek çalışmalar

Son olarak, sonuçlar elde edilmesine rağmen hâlâ açık kalan noktaların olup olmadığına ve yazarların ileride yapılabilecekler (future work) olarak neleri listelediğine bakılır.

Bu altı başlık birlikte bir yayının tam bir resmini verir: ne iddia edildi, neden, nasıl gösterildi, ne kadar başarılı oldu, bedeli neydi ve geriye ne kaldı.

## 4. Bilimsel Makale Okuma Yöntemi

Hoca, 10-20 sayfalık yayınları okumanın da bir yolu olduğunu söyledi ve şu sırayı önerdi:

- Önce özet (abstract) hızlıca okunur.
- Sonra sonuç (conclusion) bölümünde neler olduğuna, neler olmadığına bakılır.
- Ardından giriş (introduction) ve literatür taraması okunur.
- Sonra kullanılan yöntemlere geçilerek yavaş yavaş derine inilir.

Bu süreç boyunca notlar alınır ve okunanlar "öyle midir, böyle midir" diye sorgulanır. Hoca kendi kanaatine göre bir yayının bu şekilde incelenmesinin bir buçuk ile iki saat sürdüğünü, inceleme doğru yapılıp kafada fikir oluştuktan sonra bir buçuk iki sayfalık bir yazının yarım saat ile kırk dakika içinde toparlanabileceğini, ardından yazım hataları ve paragraf düzeni için bir kez daha üzerinden geçilmesi gerektiğini söyledi.

Hoca okumayı tek bir yayınla sınırlamamayı da vurguladı. Derlenen yayınların bazıları bugün referans yayın olmasına rağmen kendileri de çok değerli başka yayınlara atıfta bulunur. Bu yüzden yayınlarda ortaya konan kavramları daha iyi anlayabilmek ve daha iyi tartışabilmek için onların referanslarına da bakmak gerekir.

> **Ek bilgi (derste anlatılmadı):** Bu okuma sırası literatürde "üç geçişli okuma" (three-pass approach) olarak bilinen yönteme benzer: ilk geçişte başlık, özet, bölüm başlıkları ve sonuç okunarak makalenin genel resmi çıkarılır; ikinci geçişte şekiller ve ana argüman izlenir; üçüncü geçişte ayrıntılar ve varsayımlar sorgulanır.

## 5. Bilimsel Üslupla Değerlendirme Yazmak

### 5.1 Yayın biçimi

Okunan yayının değerlendirmesi kendi başına bir yayın biçiminde kurgulanır:

- Özet (abstract).
- Giriş (introduction).
- Neyin nasıl yapıldığını, Bölüm 3'teki başlıkları ele alan gövde.
- Sonuç (conclusion).

Değerlendirme, okunanların başlıklar halinde kopyalanması değildir; okunup anlaşılanların kendi fikirlerle yorumlanarak kendi cümlelerle yazılmasıdır.

### 5.2 Üslup

Hoca istenen ve istenmeyen üslubu karşılaştırarak anlattı. İstenmeyen, günlük kıvamındaki anlatımdır: "Burada yazarlar şunu yapmışlar, işte ben şunu gördüm, anladığım kadarıyla..." İstenen ise bilimsel raporlama dilidir:

```text
Bu çalışmada şu konu üzerine çalışılmıştır. Ortaya atılan fikir budur.
Mevcut durumda yaşanan problemler şu şekilde verilmiştir. Şu referanslara
bakıldığında bu problemlerin şunlar olduğu anlaşılmıştır. Buna çözüm olarak
şu alternatifler sunulmuştur. Bunlar da şu şekilde incelenmiştir.
```

**Soru:** Değerlendirmeler yayın biçiminde olacaksa, tercih edilen belirli bir dergi biçimi var mı?

**Cevap:** Hoca IEEE'nin iki kolonlu biçimini örnek verdi: yazının sanki yayına gidecekmiş gibi bir disiplinle, o cümle yapısıyla ve raporlama diliyle, referanslara ve atıflara dikkat edilerek yazılmasını istedi.

### 5.3 Atıf ve özgünlük

Okunup anlaşılan ve buna bağlı olarak kafada oluşan fikirler kâğıda dökülmelidir. Hazır kaynaklar kopyala-yapıştır yöntemiyle kullanılmamalıdır. Herhangi bir kaynak kullanıldığında bu mutlaka atıfla belirtilmelidir ve kaynaktan esinlenme, fikir almanın ötesine geçmemelidir. Hoca benzer bir iki cümlenin olabileceğini, ama benzer cümlelerin bir paragrafın tamamı kadar olmaması gerektiğini söyledi.

Dil konusunda hoca esnek davrandı: değerlendirmeler Türkçe yazılabilir ve terimler için İngilizce karşılıklar kullanılabilir. Amaç, bir terimin Türkçe karşılığının ne olduğu konusunda zorlanmadan içeriğe odaklanmaktır.

### 5.4 Bilimsel yazım üzerine bir yayın

Hoca derlediği yayınlar arasında bilimsel bir makalenin nasıl yazılması ve bir fikrin nasıl ifade edilmesi gerektiğini anlatan bir yayın da bulunduğunu söyledi ve önce onun okunmasını önerdi. Yayın biçimini, başlıkları ve kullanılan dili öğrenmenin en iyi yolunun, uluslararası düzeyde belirli seviyedeki dergilerde kabul edilmiş olan bu yayınları okumak olduğunu belirtti.

## 6. Tartışma Temelli Ders ve Teknoloji ile Akademinin Etkileşimi

Ders bir seminer gibi işler. Yayınlar üzerine aklınıza takılan, sormak ya da tartışmak istediğiniz noktalar hep birlikte tartışılır. Tartışmayı öğrenciler başlatır ("şurada şöyle vardı, burada böyle vardı"); hoca bir moderatör olarak yer alır ve karar verilemeyen, çelişkili noktalarda "bu aslında şu şekildedir" diyerek son noktayı koyar. Hoca konuyu açmak için, yayınları okuyup referanslarına bakan birinin cevaplayabilmesi gereken bir iki soru ortaya atabileceğini, her yayın için 10-15 dakikalık bir tartışmanın kaliteli bir yorum ortamı oluşturacağını söyledi.

Hocanın dersin sonunda vurguladığı genel fikir, işletim sistemi tarihinin aynı zamanda teknoloji ile akademinin karşılıklı etkileşiminin tarihi olduğudur. Dünyanın teknolojik gelişimi ve akademik dünyanın teknolojiye katkısı birbirini etkiler ve itici bir güç gibi bugünkü hale gelir; bir taraftaki teknolojik gelişim başka bir tarafta farklı şeyleri ortaya çıkarır. Okunacak yayınlardaki bazı fikirler bugün zaten bilinen ve günlük hayatın parçası olan özelliklerdir; ama bunların nereden ve nasıl çıktığını, o dönemde hangi seçeneklerin bulunduğunu anlamak gerekir.

> **Hocanın vurgusu:** Bu yaklaşımla klasik lisans düzeyindeki işletim sistemleri bilgisinden daha farklı, daha derin ve hocanın deyişiyle daha eğlenceli bir bilgi birikimi kazanılır.

## Dersin Toparlaması

Bu giriş dersinde teknik bir konu işlenmedi; dersin nasıl bir bakışla işleneceği ortaya kondu. İleri işletim sistemleri, bir ders kitabından değil, erişim hakları, donanımın verimli kullanımı, sanallaştırma, yerel ve ağ üzerinden prosesler arası haberleşme ve proses/thread göçü gibi konularda dönüm noktası olmuş özgün yayınlardan öğrenilecektir. Her yayın katkı, hipotez, yöntem, sonuç ve karşılaştırma, ödünleşim ve açık noktalar başlıklarıyla incelenir.

Bu incelemenin aracı da iki beceridir: makaleyi doğru sırayla okumak (abstract, conclusion, introduction ve literatür, yöntem; notlar ve referanslarla) ve okunanı bilimsel bir raporlama diliyle, atıflarla ve kendi cümlelerle yazmak. Hoca bu becerilere başlamak için bilimsel makalenin nasıl yazılacağını anlatan yayının ilk okunmasını önerdi; sonraki dersler yayınların tartışılmasıyla ilerleyecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
