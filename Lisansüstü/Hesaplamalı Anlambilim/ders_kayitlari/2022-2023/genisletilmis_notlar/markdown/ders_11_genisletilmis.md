# Ders 11 Genişletilmiş Notu: Uygulamalar: Varlık İsmi Tanıma, Paragraf Anlama, Soru Cevaplama ve Memory Networks

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersten: Duygu Analizinde İma ve Bağlam
- 2. Varlık İsmi Tanıma
- 3. Paragraf Anlama
- 4. Soru Cevaplama
- 5. Başka Soru Cevaplama Veri Kümeleri
- 6. Çok Basit Hikâyelerde Çıkarım: bAbI
- 7. Memory Networks
- 8. End-to-End Memory Networks
- 9. İtiraz: Kısa Yol Öğrenme
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersten: Duygu Analizinde İma ve Bağlam

Bu ders, ders notlarının "Uygulamalar" başlıklı Bölüm 6'sının devamıdır. Önceki derste metin sınıflandırma, duygu durum analizi ve varlık ismi tanımaya giriş yapılmış, duygu analizinin zorluğu "Yemeğimi 5 dakikada getirdiniz çok teşekkürler" (olumlu) ile "Yemeğimi 55 dakikada getirdiniz çok teşekkürler" (iğnelemeli, olumsuz) cümleleriyle gösterilmişti. Hoca, öğrencilerden bu iki cümlenin imasını bir modelin anlayıp anlayamadığını denemelerini istemişti.

Dersin başında bu deneyin sonuçları konuşuldu (00:11:15). Öğrencilerin denediği modeller "55 dakika" cümlesini de olumlu olarak sınıflandırmıştı; bir öğrenci benzer başka bir cümleyi de denediğini, imanın yine yakalanamadığını söyledi. Denemeler İngilizce çeviriyle de yapılmış, sonuç değişmemişti. Hoca "demek ki daha yeterince iyi değil" diyerek bu konunun zor bir iş olduğunu tekrar etti. <!-- BELİRSİZ: Denenen modelin adı altyazıda anlaşılmıyor ("Abin dedi"). -->

Hoca buna sosyal medyaya özgü bir zorluk ekledi (00:12:56). Sosyal medya içerikleri düz metinlerden daha "dertlidir". Burada kastedilen kirlilik ya da yazım hataları değildir. Normal bir web sitesinde anlatmak istediğinizi anlatmak için geniş bir alan vardır; Twitter gibi uzun yazamadığınız ortamlarda ise dil oyunu, zekâ oyunu ve dolaylı göndermeler daha revaçtadır. Bu yüzden sosyal medya verisinden anlam çıkarmak daha güçtür. Birbirinin aynısı olan binlerce mesajdan değil, özgün içeriklerden söz edildiğini de belirtti.

İkinci zorluk bağlamdır. Aynı cümle farklı zamanlarda farklı anlama gelebilir. Ülkenin ya da kişinin çalıştığı alanın gündeminde herkesin konuştuğu bir konunun varlığı ya da yokluğu, atılan bir mesajın anlamını etkileyebilir, değiştirebilir. Mesajların içinde doğrudan görünmeyen birçok gönderme vardır. Bu yüzden bazı mesajları yalnız kendisine bakarak anlamak çok güçtür.

## 2. Varlık İsmi Tanıma

### 2.1 Tanım

Varlık ismi tanıma (Named Entity Recognition, NER), bir metnin içindeki önceden tanımlanmış varlıkları ve türlerini bulmaktır (ekrandan, 00:20:00). Hoca "detection" ile "recognition" kelimelerinin biraz farklı şeyler ifade ettiğini söyledi: NER, recognition'ı ifade eder; yani isimlendirilmiş varlıkları bulmayı ve bunların hangi türden olduğunu söylemeyi. Bu da bir sınıflandırma işidir.

Slayttaki örnek metin ENAMEX biçiminde işaretlenmiştir (ekrandan, 00:20:00):

```text
<b_enamex TYPE="ORGANIZATION">AKBANK<e_enamex> 8. Caz Festivali, 8 - 21 Ekim tarihleri arasında,
<b_enamex TYPE="LOCATION">İstanbul<e_enamex>, <b_enamex TYPE="LOCATION">Ankara<e_enamex> ve
<b_enamex TYPE="LOCATION">Adana<e_enamex>'da caz ustaları ile müzikseverleri buluşturacak Festival 'in
<b_enamex TYPE="LOCATION">İstanbul<e_enamex>'daki açılış konserini vokal ve piyano virtüözü Brezilyalı sanatçı
<b_enamex TYPE="PERSON">Tania Maria<e_enamex> yapacak
```

Etiketleri çıkardığınızda geriye düz metin kalır. Amaç bu düz metni yukarıdaki işaretli hale dönüştürmektir: Akbank'ın bir kurum, İstanbul, Ankara ve Adana'nın birer yer, Tania Maria'nın bir kişi olduğunu söylemek.

### 2.2 Yaklaşımlar: CRF ve derin öğrenme

Bu iş için temelde sekanstan sekansa (seq2seq) mimariler kullanılır. En klasik yaklaşım CRF'dir (Conditional Random Fields). Derin öğrenme öncesinden gelen, oldukça başarılı bir yöntemdir. Ancak çok sayıda özellik kullanır ve problemi çözmek için hangi özelliklerin kullanılacağını sizin söylemeniz gerekir; buna özellik mühendisliği (feature engineering) denir.

Derste kullanılan yaklaşım derin öğrenme tabanlıdır. En büyük avantajı özellik mühendisliğine takılmamasıdır. Yaklaşım çok basit olabilir: slayttaki gibi karakter tabanlı bir LSTM. Giriş karakterlerin one-hot vektörleridir; hiçbir şekilde kelime kullanılmaz. Hoca bunu önceki dersteki duygu analizi CNN deneyinin karakter tabanlı versiyonuna benzetti. Çıkış ise her karakterin sınıfıdır: kurum, yer, kişi ve bunların hiçbirine girmeyenler için bir "hiçbiri" sınıfı. "Tarihleri arasında" gibi kelimelerin her karakteri bu sınıfa girer; en çok elemanı olan sınıf da büyük olasılıkla budur.

> **Hocanın vurgusu:** NER problemlerinin karakteristik özelliklerinden biri, sınıfların dağılımlarının genelde hiç eşit olmamasıdır. A sınıfındaki örnek sayısı ile B sınıfındaki örnek sayısı birbirine pek yakın olmaz.

### 2.3 Deney ve sonuçlar

Slayttaki deney, hiçbir ek bilgi (örneğin isim listesi) kullanılmadan yapılmıştır (ekrandan, 00:22:00). Kodlar `seq2seq_ner_3class.m`, `seq2seq_ner_7class.m`, `leftPad.m`; veri dosyaları `Train7.MUClabeled`, `WFS7.MUClabeled`, `NEtrain.txt`.

3 sınıflı veri kümesi (NEtrain.txt): 27563 cümle; yarısı eğitim, yarısı test. Test başarıları 0.8457, 0.8182, 0.7803; varlık olmayan 0.9852. Etiket sayıları:

| Sınıf | Etiket sayısı |
|---|---|
| PERSON | 16291 |
| ORGANIZATION | 9183 |
| LOCATION | 11715 |
| Toplam | 37189 |

7 sınıflı veri kümesi: 24819 cümle eğitim (Train7.MUClabeled), 1572 cümle test (WFS7.MUClabeled). Test başarıları 0.8693, 0.7810, 0.8458, 0.8214, 0.8889, 0.8049, 1.0000; varlık olmayan 0.9922.

| Sınıf | Eğitim | Test |
|---|---|---|
| PERSON | 14693 | 658 |
| ORGANIZATION | 9160 | 410 |
| LOCATION | 9767 | 637 |
| DATE | 1366 | 119 |
| PERCENTAGE | 648 | 62 |
| MONEY | 597 | 41 |
| TIME | 148 | 19 |
| TOPLAM | 36379 | 1946 |

Tablolardaki toplamlar python ile doğrulandı. Hoca birkaç noktaya dikkat çekti. Etiket tablolarında "hiçbiri" sınıfının sayıları yoktur, ama en kalabalık sınıf odur. "3 sınıflı" problem bu ek sınıfla aslında 4 sınıflı, "7 sınıflı" problem de aslında 8 sınıflıdır. Sınıf başarılarının büyük olasılıkla F1 skorları olduğunu söyledi. Hiçbir sınıfa girmeyenlerin başarısı diğerlerine göre epey yüksektir. <!-- BELİRSİZ: Test başarılarının hangi sınıfa ait olduğu slaytta yazmıyor; büyük olasılıkla tablolardaki sınıf sırasıyla verilmiştir. -->

Genel olarak bir sınıfın örnek sayısı arttıkça o sınıfın performansı artar. Ayrıca bir sınıf diğer sınıflardan ne kadar ayrık yapılar içeriyorsa, yani sınıflar arası uzaklık ne kadar büyükse, o sınıf o kadar iyi ayırt edilir. Hocaya göre sonuçlar çok yüksek değildir, ama karakter karakter çalışan bir modelle bile bu işin oldukça başarılı yapılabildiği görülmektedir.

### 2.4 Son işlem ve kurallar

Model her karaktere ayrı bir sınıf atadığı için test zamanında tutarsız çıktılar oluşabilir. Örneğin bir kelimenin içinde arka arkaya dört LOCATION, sonra bir ORGANIZATION, sonra yine dört LOCATION gelebilir. Bir kelimenin yarısının bir sınıftan, yarısının başka sınıftan olması makul değildir. Bu yüzden çıkışları belirli makul kurallara göre dönüştüren bir son işlem (post-processing) yapmak mantıklıdır.

NER'de kurallar da yaygın olarak kullanılmıştır. Örneğin büyük harfle yazılmış birkaç kelimeden sonra "A.Ş." (anonim şirket) geliyorsa, bunların hepsine birden kurum denebilir. Bu tür kurallar eğitim kümesi yetersizken oldukça başarılıdır. Yeterli eğitim kümesi varsa kural tanımlamadan da oldukça başarılı sonuçlar elde edilebilir.

## 3. Paragraf Anlama

### 3.1 Bir sistemin metni anladığını nasıl anlarız?

Hoca konuya üniversite sınavlarındaki paragraf sorularıyla girdi (ekrandan, 00:28:50). Bu sorular okuduğunu anlama kabiliyetini ölçer. Birinin bir şeyi anlayıp anlamadığını ölçmek için normalde ona soru sorarız; sınavda da öğrenciye bir paragraf verilir ve onunla ilgili sorular sorulur. O zaman bir sistemin bir metni anlayıp anlamadığını da benzer bir yaklaşımla ölçebiliriz: metne ait soruları cevaplayabiliyorsa metni anlamıştır.

Slayttaki soru tipleri (ekrandan, 00:28:50):

- Bu paragrafın ana fikri aşağıdakilerden hangisidir?
- Bu paragraftan aşağıdakilerden hangisi çıkarılabilir / çıkarılamaz?
- Bu parçada anlatımın akışını bozan cümle aşağıdakilerden hangisidir?
- Bu sözleri söyleyen kişi için aşağıdakilerden hangisi söylenemez?
- Bu sözler aşağıdaki sorulardan hangisine karşılık olarak söylenmiş olabilir?

Üniversite sınavı olduğu için sorular çoktan seçmelidir; açık uçlu bir problem yoktur, dört-beş şık vardır.

### 3.2 Türkçe veri kümesi ve yöntem

Hoca öğrencilerle birlikte bir veri kümesi topladıklarını anlattı (ekrandan, 00:30:00): uni_paragraf, 500'er soruluk 3 farklı veri kümesi. Her soru türüne özel bir şey yapılmadı; en yaygın soru türü olan "bu paragraftan aşağıdakilerden hangisi çıkarılabilir / çıkarılamaz" (ve "ilgili" gibi benzerleri ile tersleri) hedeflendi.

Hiçbir eğitim yapılmadı. Önce paragraf ve şıkların bir temsili elde edildi: karakter 3-gramlarının TF vektörleri; kelime hiç kullanılmadı. Soru olumluysa ("çıkarılabilir") paragrafa en yakın şık, olumsuzsa ("çıkarılamaz") en uzak şık seçildi. Benzerlik ölçüsü kosinüs benzerliğidir.

Sonuç yaklaşık %35 başarıdır. Hoca "Bu iyi mi?" diye sordu: fena değil, çünkü beş şık olduğu için şans başarısı %20'dir. Yapılan tek şey, olumlularda soru ile metin arasındaki ortak karakter üçlülerine bakmaktır. Ancak bu sistemin çözebildiği bir soru çok küçük bir değişiklikle çözülemez hale getirilebilir; örneğin bir kelimenin eş anlamlısı yazıldığında bu naif yaklaşım büyük olasılıkla çöker. Temsiller için bambaşka yaklaşımlar da kullanılabilir (slaytta "Başka ???").

> **Hocanın vurgusu:** Paragraf anlama hiç de kolay bir görev değildir. Twitter'daki metinleri anlamak kadar zor olmasa da oldukça zordur.

## 4. Soru Cevaplama

### 4.1 Cevap nerede, cevap ne?

Bir şeyi anlamayı soru cevaplamayla ölçmek insanlarda kabul gören bir yaklaşımdır; bu yüzden makineler için de yapılmaya başlanmıştır. Sorular çoktan seçmeli olmak zorunda değildir. Elinizde bir paragraf, bir web sayfası ya da bir derlem olabilir ve sorduğunuz sorunun cevabının nerede olduğunu bulmak istersiniz. Hoca iki işi ayırdı: cevabın nerede olduğunu (hangi paragraf, hangi cümle) bulmak bir iştir; cevabın tam olarak ne olduğunu, yani hangi ifade olduğunu bulmak başka bir iştir.

### 4.2 Değerlendirmenin zorluğu

Sistemin bulduğu cevabın doğru kabul edilip edilmeyeceği sıkıntılı olabilir. Hocanın örneği: "Yedinci Osmanlı padişahı", "Fatih Sultan Mehmet" ve "İstanbul'u fetheden Osmanlı padişahı" ifadelerinin hepsi aynı kişiden bahseder ama farklı yazılmıştır. Veri kümesinde tanımlı cevap biri, sistemin verdiği cevap diğeriyse, sisteme "yanlış yaptın" dememek gerekir. Adil bir değerlendirme için bunların eşdeğer olduğunu otomatik olarak değerlendiren bir sistem gerekir. <!-- BELİRSİZ: Altyazıda "Başsultan Mehmet" geçiyor; büyük olasılıkla "Fatih Sultan Mehmet". -->

Aynı sorun cevabın hangi paragrafta olduğunu bulmada da vardır: istenen cevabı içeren birden fazla paragraf olabilir; hepsinin işaretlenmiş ya da kontrol edilebilir olması gerekir. Bağlam (context) küçükse her şey kontrollü yürür. Ancak bağlam bir kitap kadar büyükse, sistemin verdiği cevabın doğru olup olmadığını ölçmek ölçeklenebilir bir iş değildir.

### 4.3 Türkçe "cevap nerede" veri kümesi

Yine öğrencilerle oluşturulmuş basit bir veri kümesi (ekrandan, 00:40:00):

- cevap_nerede: 500'er soruluk 2 veri kümesi.
- Paragraflar hikâyedir ve internetten toplanmıştır; uzunlukları 20-30 cümle civarındadır.
- Her paragraf için çok sayıda "soru, cevabın olduğu cümle" ikilisi vardır. Soruların bir kısmı internetten alınmış, bir kısmı elle üretilmiştir.
- Sistemden beklenen, cevabın geçtiği cümleyi göstermesidir.
- Yöntem: soruya en benzeyen cümleyi seç (eğitim yok).
- Şans: 1 / ortalama cümle sayısı, yaklaşık %10.
- Karakter 3-gramlarıyla yaklaşık %70 başarı.

%10'a göre %70 çok iyidir. Ancak hoca bunun soruların basitliğinden geldiğini söyledi: sorudaki kelimeler ile cevabın geçtiği cümledeki kelimeler birbirine çok benzer, fazla çıkarım gerekmez. Farklı kelimelerin aynı anlama geldiğini algılamak gereken sorularda karakter n-gramları yüksek başarı veremez.

> **Hocanın vurgusu:** Karakter 3-gramları bir veri kümesinde iyi sonuç veriyorsa, o veri kümesinin basit olduğunu rahatlıkla söyleyebilirsiniz. Cümlelerin parafrazları yazılırsa başarı çok aşağı çekilir, çünkü karakter 3-gramları anlamsal benzerliği doğrudan kurmaz. Bazı anlamsal ilişkileri yakalayabilirler, ama belli sınırları vardır.

### 4.4 SQuAD

Cevabın hangi cümlede olduğunu değil de paragrafın tam olarak neresinde olduğunu, yani hangi karakterden başlayıp hangi karakterde bittiğini bulmak daha ince bir iştir. Bu formatta büyük ölçekli bir veri kümesi SQuAD'dır (Stanford Question Answering Dataset) (ekrandan, 00:40:50):

- Makale, soru ve cevabın makalenin neresinde başlayıp bittiği.
- 130 bin eğitim, 9 bin test sorusu.
- Orijinal SQuAD'da cevaplanamayan soru yoktu: her sorunun cevabı paragrafta mutlaka vardı. SQuAD 2.0'da sistemin "bu paragrafta bu sorunun cevabı yok" diyebilmesi gereken sorular da eklendi.
- Derin öğrenme yöntemleriyle tam cevap (exact match) başarısı yaklaşık %70.

Önceki deneylerdeki kosinüs benzerliği yöntemlerinin hiçbir eğitim süreci yoktu; bu yöntemlerde ise eğitim vardır.

> **Ders sonrası not:** Hoca SQuAD için 2018 dedi. Slayttaki arXiv bağlantısı (1806.03822) SQuAD 2.0'a aittir ve 2018 tarihlidir; ilk SQuAD büyük olasılıkla 2016'da yayımlanmıştır.

## 5. Başka Soru Cevaplama Veri Kümeleri

### 5.1 Bilim soruları

Allen AI'ın yayımladığı veri kümelerinden biri gerçek sınav sorularından oluşur (ekrandan, 00:55:50; bağlantılar data.allenai.org/ai2-science-questions ve data.allenai.org/arc). Hoca soruların yanılmıyorsa ortaokul seviyesinde ve çoktan seçmeli olduğunu, hiç de kolay bir veri kümesi olmadığını söyledi. Slayttaki besin zinciri sorusunu cevaplamak için şekli algılamak gerekir: soru aynı kalıp şekil değişirse verilmesi gereken cevap da değişebilir. Hocaya göre bu tür sorular bugün bile güçtür.

### 5.2 Açıklamalı çözümler ve matematik

Bir sonraki veri kümesinde soru, şıklar ve doğru şıkkın yanında bir açıklama (explanation) kısmı vardır. Bu kısım cevaba ulaşmak için gereken akıl yürütme (reasoning) sürecini anlatır. Açıklamayı yazmak gerektiği için böyle bir veri kümesini hazırlamak daha zordur.

Bir başka veri kümesi matematik sorularından oluşur (ekrandan, 00:58:10): açıklamalı çözümler, 100 bin soru, arXiv:1705.04146. Bunlar, hem soruyu çözen hem de nasıl çözdüğünü anlatan mimariler için kullanılır. Hoca bu tür veri kümelerine epeydir uğraşıldığını, tek problemin bunların büyük ölçekte oluşturulması olduğunu söyledi: bu tamamen insan emeğine, dolayısıyla paraya bağlıdır.

### 5.3 SWAG: videolarda bir sonraki olayın tahmini

SWAG (arXiv:1808.05326, 2018, BERT'in çıktığı dönem) metin tabanlı bir soru cevaplama veri kümesidir, ama oluşturulmasında videoların altyazıları (caption) kullanılmıştır (ekrandan, 01:00:00). Örneğin bir yemek tarifi videosunun altyazılarında olaylar birbirini takip eder. Soruda bir bağlam verilir ("On stage, a woman takes a seat at the piano. She ...") ve metnin en mantıklı nasıl devam edeceği sorulur.

Devamını bulma sorularında problem çok kolay hale getirilebilir: doğru cevabı şıklardan birine koyup diğerlerini rastgele üretirseniz problem aşırı kolaylaşır. Bu yüzden şıkları üretmek için bir mekanizma kurulmuştur; slayttaki şemaya göre yanlış devamlar çekişmeli olarak seçilir (adversarially select generations) ve insan işaretleyiciler sonları süzer. Yine de iş çok fazla zorlaştırılamamış: hocanın hatırladığına göre SWAG yayımlandıktan birkaç ay sonra BERT bu veri kümesinde ilk çalıştırıldığında %80'in üzerinde bir başarı elde etmişti. "Uzun süre idare edecek iyi bir benchmark bulduk" düşüncesi BERT ile hızla sona erdi.

> **Ders sonrası not:** BERT makalesinde SWAG için bildirilen doğruluk büyük olasılıkla %86 civarındadır (BERT-Large); hocanın "%80 küsur" demesiyle uyumludur.

## 6. Çok Basit Hikâyelerde Çıkarım: bAbI

Hoca bundan sonra cevabı bulmak için, insanlar olarak bizim de çıkarım yapma ihtiyacı duyduğumuz veri kümelerine geçti (ekrandan, 01:03:00). Slayttaki İngilizce örnek:

```text
Joe went to the kitchen. Fred went to the kitchen. Joe picked up the milk.
Joe travelled to the office. Joe left the milk. Joe went to the bathroom.
Where is the milk now? A: office
Where is Joe? A: bathroom
Where was Joe before the office? A: kitchen
```

Veri kümesinin özellikleri:

- Otomatik üretilmiş (eğitim 3000, test 1000 soru).
- Sözlük boyutu çok küçük (yüz küsur kelime), çok basit bir gramer: özne, belki bir iki kelime, sonra fiil. Özel isimler belli olduğu için Türkçeye çevirmek çok kolaydır.

Eğitim verisinden bir örneğin Türkçe çevirisi:

```text
1 Mary banyoya gitti.
2 Sandra bahçeye gitti.
3 Daniel bahçeye gitti.
4 Daniel ofise gitti.
5 Sandra oradaki sütü aldı.
6 Sandra sütü oraya bıraktı.
7 Süt nerede?      bahçe      6 2
```

Hoca akıl yürütmeyi şöyle kurdu: Sandra oradaki sütü aldı; Sandra bahçeye gittiğine göre sütü bahçede aldı; sonra sütü oraya bıraktı. Peki süt nerede? Cevap "bahçe"dir. Eğitim kümesinde cevabın yanında, cevabı yakalamak için gerekli olan cümlelerin indisleri de (6 ve 2) verilmiştir.

> **Ders sonrası not:** Hoca bir yerde "sistemin vermesi gereken cevap 6" dedi; hemen ardından düzelttiği gibi cevap "bahçe"dir, 6 ve 2 cevapla ilgili cümlelerin indisleridir (ekrandan, 01:03:00).

## 7. Memory Networks

### 7.1 Yapı

Bu veri kümesini üretenlerin (hocanın hatırladığına göre o zaman Facebook'taydılar) önerdiği mimari Memory Networks'tür (arXiv:1410.3916, 2014) (ekrandan, 01:10:00). Bir yapay sinir ağının dışında bir bellek mimarisinin bulunduğu bir yapıdır. Bu bellek yalnız yazılır ve okunur; "bunu böyle sanıyordum, şöyleymiş" diye okudukça güncelleme gibi bir manipülasyon yoktur. Hoca yılın 2014 olduğunu, Transformer'ların henüz bulunmadığını hatırlattı.

Slayttaki gösterimler:

- $m$: hikâyenin tutulduğu bellek. Hikâye cümlelerden oluşur; her cümle bir şekilde temsil edilip belleğe konur. Örnekte altı cümlenin temsili belleğe atılır.
- $m_{o_1}$ ve $m_{o_2}$: belleğin cevabı üretecek parçaları; örnekte 6 ve 2. Eğitim kümesinde bunlar bilinir.
- $x$: soru.
- $r$: tek kelimelik cevap. Sözlük yüz kelime civarında olduğu için problem, soruya bu kelimelerden birini cevap olarak vermektir.
- $s_O$ ve $s_R$'nin $U$'ları farklıdır.
- Eğitim verisinden bu $U$ matrisleri öğrenilir; $U$, $n \times d$'lik bir matristir.
- $\Theta$ (slayttaki $\Phi$) fonksiyonu bir stringi $d \times 1$ boyutlu gösterime, kelime torbasına (BoW) çevirir.

Benzerlik fonksiyonu (ekrandan, 01:10:00):

$$s(x, y) = \Phi_x(x)^T U^T U \Phi_y(y)$$

Hoca bunu, $x$ ve $y$ vektörleri arasında bir benzerlik sayısı olarak, bir tür kosinüs benzerliği gibi düşünmeyi önerdi. Özel olan, araya öğrenilen bir $U$ matrisinin girmesidir. Sistemin öğrendiği tek şey bu $U$ matrisleridir.

### 7.2 İki adımlı çıkarım

Slayttaki denklemler (ekrandan, 01:10:00):

$$o_1 = O_1(x, \mathbf{m}) = \arg\max_{i=1,\dots,N} s_O(x, \mathbf{m}_i)$$

$$o_2 = O_2(x, \mathbf{m}) = \arg\max_{i=1,\dots,N} s_O([x, \mathbf{m}_{o_1}], \mathbf{m}_i)$$

$$r = \arg\max_{w \in W} s_R([x, \mathbf{m}_{o_1}, \mathbf{m}_{o_2}], w)$$

Adımlar örnek üzerinde:

1. arg max, "maksimum yapan argüman" demektir. $i$ birden $N$'e (bellekteki cümle sayısına) kadar değişir. Her cümlenin soruyla ("Süt nerede?") benzerliği hesaplanır ve en benzeyen cümlenin numarası $o_1$ olur. Bu örnekte 1 ile 6 arasında bir sayıdır; sistem 6'yı ("Sandra sütü oraya bıraktı") bulur.
2. Soru ile bu cümle birleştirilip yeni bir metin elde edilir ($[x, \mathbf{m}_{o_1}]$). Bu birleşime en yakın cümle aranır; bu da $o_2$'dir (örnekte 2, "Sandra bahçeye gitti").
3. Elde artık soru ve iki cümle vardır. Son adımda bu üçlüye en yakın sözlük kelimesi bulunur. Sözlük $W$ ile gösterilir; arg max bütün sözlük kelimeleri içinden birini seçer ve $r$ cevabı verir.

Bu iki adımlı bir çıkarımdır. Tek bir destekleyici cümlenin yettiği soru türleri de vardır; o zaman yalnız $o_1$ kullanılır, $o_2$ adımı kaldırılır.

### 7.3 Kayıp fonksiyonu

$U$'lar güncellenerek şu fonksiyon minimize edilir (ekrandan, 01:12:30). Slayttaki temel mantık: "içinde şu kelimeler varsa içinde şu kelimeler olan text'i seç".

$$\sum_{\bar{f} \neq \mathbf{m}_{o_1}} \max(0, \gamma - s_O(x, \mathbf{m}_{o_1}) + s_O(x, \bar{f})) + \sum_{\bar{f}' \neq \mathbf{m}_{o_2}} \max(0, \gamma - s_O([x, \mathbf{m}_{o_1}], \mathbf{m}_{o_2}) + s_O([x, \mathbf{m}_{o_1}], \bar{f}'))$$

$$+ \sum_{\bar{r} \neq r} \max(0, \gamma - s_R([x, \mathbf{m}_{o_1}, \mathbf{m}_{o_2}], r) + s_R([x, \mathbf{m}_{o_1}, \mathbf{m}_{o_2}], \bar{r}))$$

Burada $\bar{f}$, $\bar{f}'$ ve $\bar{r}$, eğitimdeki gerçek değerlerin dışındaki bütün haller demektir. Hocanın açıklaması: birinci terim, $x$ ile doğru cümleyi (6) birbirine en yakın yapacak, 6'nın dışındaki bütün bellek bloklarından da uzaklaştıracak $U$'yu arar. İkinci terim aynı şeyi ikinci cümle (2) için, üçüncü terim de gerçek cevap ile diğer bütün kelimeler için yapar. $O$ ve $R$'de iki farklı $U$ vardır ve ikisi birlikte optimize edilir.

> **Ek bilgi (derste anlatılmadı):** $\max(0, \gamma - s^{+} + s^{-})$ biçimindeki terimlere hinge ya da marj sıralama (margin ranking) kaybı denir. Doğru seçeneğin skoru yanlış seçeneğinkinden en az $\gamma$ kadar büyükse terim sıfır olur; değilse aradaki farkla orantılı bir ceza verir.

### 7.4 Yorum: bu bir çıkarım mı?

Bu yöntem fena çalışmaz ve yapay sinir ağlarında çıkarım yapma üzerine elle tutulur bir şey bulunduğu düşünülmüştür. Sanki model bir şeye bakıyor, onu neyle etkileşime sokması gerektiğine karar veriyor, bir şey seçip ikisini birlikte alıyor ve oradan başka bir yere gidiyor; yani birkaç adımlı bir çıkarım görüyor gibisiniz. Hocaya göre buna ne kadar çıkarım denebileceği ayrı bir konudur; yaptığı şey temelde benzerlik hesaplamaktır, yepyeni bir şey üretmez.

> **Hocanın vurgusu:** Bunu çok da küçümsememek lazım. Bugün her şey sonraki token tahmini (next token prediction) gibi basit bir şeyden türüyorsa, benzerleri bulmak da küçümsenecek bir mekanizma değildir.

### 7.5 Eksik: destekleyici cümlelerin işaretlenmesi

Memory Networks'ün bir gereksinimi vardır: eğitim kümesinde 6 ve 2'yi, yani "bu cevabı bulmak için şu cümleleri kullanmalısın" bilgisini vermeniz gerekir. Testte tabii böyle bir şey yoktur, ama eğitimde gereklidir. Bu fazlalık görüldü ve Memory Networks'ten End-to-End Memory Networks'e geçildi.

## 8. End-to-End Memory Networks

### 8.1 Yumuşak seçim

End-to-End Memory Networks (arXiv:1503.08895, hocanın hatırladığına göre aynı ekipten, 2015), eğitim setinde cevapla ilişkili cümlelerin ($m_{o_1}$, $m_{o_2}$) işaretlenmesi gerekliliğini ortadan kaldırır (ekrandan, 01:16:50):

$$p_i = \mathrm{Softmax}(u^T m_i), \qquad \mathrm{Softmax}(z_i) = e^{z_i} / \sum_j e^{z_j}$$

- $m_i$: bellek slotları (cümlelerin gömmeleri).
- $u$: sorunun gömmesi.
- $p$: bellek slotlarının soruyla ilişkili olma olasılıkları; $p_i$, $i$. slottaki metnin soruyla ilişkili olma olasılığıdır.

Memory Networks arg max ile en çok benzeyeni buluyordu. Burada sorunun gömmesiyle bellek slotları çarpılır; bu çarpım yine bir benzerlik ifadesidir. Softmax'a verilince her slotun soruyla ilişkili olma olasılığı elde edilir.

### 8.2 Tek adımlı mimari

Slayttaki denklemler ve şema (ekrandan, 01:20:00):

$$o = \sum_i p_i c_i, \qquad \hat{a} = \mathrm{Softmax}(W(o + u))$$

Eğitim sürecinde A, B, C, W gömme matrisleri öğrenilir. Şemanın akışı:

```text
Soru q --(Embedding B)--> u
Cümleler {x_i} --(Embedding A)--> m_i   (girdi belleği)
Cümleler {x_i} --(Embedding C)--> c_i   (çıktı belleği)
p_i = Softmax(u . m_i)                  (iç çarpım + softmax)
o   = Σ p_i c_i                         (ağırlıklı toplam)
â   = Softmax(W (o + u))                (tahmin edilen cevap)
```

Hoca adımları şöyle anlattı. Soru B ile bir gömmeye çevrilir. Bellekteki cümlelerin A matrisiyle bir gömmesi, C matrisiyle başka bir gömmesi elde edilir; yani aynı cümlelerin iki farklı temsili vardır. Sorunun gömmesi A temsilleriyle iç çarpıma (inner product) girer; iç çarpım benzerliktir, yani soru bellekteki cümlelerle karşılaştırılır. Sonra $p_i$'ler hesaplanır: "bu soruya şu cümle çok benziyor, şu az benziyor" gibi olasılıklar. Bu olasılıklar C temsilleriyle çarpılıp toplanır (weighted sum) ve $o$ vektörü elde edilir.

Ağırlıklı toplamın sezgisi: diyelim ki 5. cümle çok benziyor, diğerleri hiç benzemiyor; o zaman $o$ yalnız 5. cümlenin C gömmesinden oluşur. Diyelim ki soru %50 birinci, %50 dördüncü cümleye benziyor; o zaman yalnız bu ikisinin değerleri katılır, diğerleri sıfır olur, $o$ birinci ve dördüncü cümlenin gömmelerinin ağırlıklı toplamı olur. Ağırlıklar alttaki A temsillerinden gelir. Son olarak $o$ ile soru gömmesi toplanır, W matrisiyle çarpılır ve cevap üretilir.

### 8.3 Dikkat mekanizmasıyla benzerlik

Hoca bu yapıyı Transformer'daki dikkat (attention) mekanizmasına benzetti. Self-attention, cümlenin içindeki her elemanın diğerleriyle benzerliğini hesaplıyordu. Burada ise self-attention değil, cross-attention vardır: sorunun her cümleye ne kadar dikkat etmesi gerektiği hesaplanır. Transformer'da her tokenın query, key ve value gibi farklı temsilleri vardı; burada da Embedding A ve Embedding C aynı şeyin farklı temsilleridir. Ağırlıklı toplam doğrudan $m_i$'ler üzerinden de alınabilirdi; kullanılamaz diye bir şey yoktur, ama ayrı bir temsil kullanmanın daha başarılı olduğu sonucuna varılmıştır.

"End-to-end" ifadesi, dışarıdan iç sürece müdahale edilmeyen demektir. Memory Networks'te "bu adımda şunu seçmelisin" diye söylemek gerekiyordu ve seçimler katı (ayrık) idi: şunu seç ve ekle, bunu seç ve ekle. Burada katı bir seçim yoktur, süreç tamamen yumuşak (smooth) ilerler. Belleğin içindeki bütün bileşenler işe katılır, ama farklı ağırlıklarla; bu da aynen dikkat mekanizmasıdır.

### 8.4 Çok adımlı mimari

Aynı işlem arka arkaya üç kez yapılabilir (ekrandan, 01:20:00, şemanın b kısmı). Hoca bunu çok katmanlı bir Transformer gibi düşünmeyi önerdi. Her adımın kendi matrisleri vardır: $A^1, C^1, A^2, C^2, A^3, C^3$; hepsi öğrenilir. Bir adımın çıkışı ile o adımın soru temsili toplanıp bir sonraki adıma girer. Her katman bir ağırlıklı toplam yapar, ama her katmanın temsilleri farklıdır.

Adım sayısı mimaride belirlenir: tek adımlı, üç adımlı ya da $X$ adımlı akıl yürütme (reasoning) yapılabilir, ama dört adımlı yapmak için mimariyi değiştirmek gerekir. Öte yandan üç adımlı bir mimari, tek adım gerektiren bir soruyu da çözebilir: ilk adımda iyi bir $p$ oluştuktan sonra sonraki adımlarda aynı $p$ çıkıp sonuç değişmeden devam edebilir.

### 8.5 Konum gömmeleri

Hocanın günümüze yansıyan bir yaklaşım olarak öne çıkardığı kısım konum gömmeleridir (position embeddings, PE) (ekrandan, 01:30:00). Gömmede klasik bir kelime torbası yaklaşımı vardır: A, $d \times V$'lik bir gömme matrisidir ve cümlenin gömmesi kelimelerin gömmelerinin toplamıdır. Ancak kelimelerin sırasının bu toplamda hiçbir etkisi yoktur. Kelime gömmelerini toplayarak da çarparak da bir cümle gömmesi elde etseniz, toplama ve çarpma yer değiştirebilen (değişme özelliği olan) işlemler olduğu için kelimenin cümlenin başında, ortasında ya da sonunda olması hiçbir şeyi değiştirmez.

Slayttaki çözüm:

$$m_i = \sum_j l_j \cdot A x_{ij}$$

Buradaki "$\cdot$" eleman bazlı çarpmadır.

$$l_{kj} = (1 - j/J) - (k/d)(1 - 2j/J)$$

Slayttaki ısı haritası $d = 128$, $J = 25$ için $L$ matrisini gösterir: yatay eksen kaçıncı kelime olduğu, dikey eksen gömme boyutunun indisi. $L$'nin her sütunu farklı bir konumu ifade eder; böylece aynı kelimenin cümleye etkisi farklı konumlarda farklı olur.

Hoca önemli noktanın şu olduğunu söyledi: birbirine yakın konumdaki kelimeler benzer vektörlerle, birbirinden uzak konumdaki kelimeler farklı vektörlerle çarpılır. 17. ile 18. konumun, 30. ile 31. konumun vektörleri birbirine benzer; birinci ile sonuncu konumunki ise çok farklıdır. Yine çarpıp toplanır, yani yine ağırlıklı toplam alınır; ama konum bilgisi işe katıldığı için aynı kelimenin farklı konumlarda farklı etkisi olabilir.

Formülün uç değerleri python ile kontrol edildi ($d = 128$, $J = 25$, ara adım eklendi): $l_{1,1} \approx 0{,}953$, $l_{128,1} = 0{,}04$, $l_{1,25} \approx 0{,}008$, $l_{128,25} = 1$. Yani ilk konumun vektörü boyut indisi arttıkça yaklaşık 1'den 0'a, son konumun vektörü 0'dan 1'e gider; iki uç konum birbirinin tersi gibi davranır.

> **Hocanın vurgusu:** Konum gömmeleri 2015'te bu çalışmayla görülmeye başlanmıştır ve End-to-End mimarilerden günümüze yansıyan yaklaşımlardan biridir.

### 8.6 Görevler ve sonuçlar

bAbI'de otomatik üretilmiş 20 görev vardır. Her görevde bir hikâye ve onunla ilgili bir soru verilir. Sonuç şekillerinde hop 1, hop 2, hop 3 sütunlarındaki mavi tonları, her adımdaki $p$ değerlerini, yani bellek slotlarından hangisinin daha etkili olduğunu gösterir. Bir örnekte model birinci adımda iki cümlenin önemli olduğunu düşünmüş, sonraki adımlarda başka cümlelerle devam etmiştir. Başka bir örnekte ilk adımda bulunan cümle yeterli olmuş ve sonraki adımlarda hiçbir şey değişmemiştir.

Görev türleri arasında tek destekleyici bilgi (one supporting fact), üç destekleyici bilgi (three supporting facts) ve evet/hayır soruları vardır. Sözlük gerçek dildeki gibi on binlerce token değil, birkaç yüz tokendan oluşur. İlginç bir görev yol bulmadır: "Yatak odası mutfağın kuzeyinde, hol mutfağın güneyinde, banyo yatak odasının güneyinde" gibi bilgiler verilir ve "mutfaktan yatak odasına nasıl gidilir?" diye sorulur. Burada cevap tek bir kelime değil, arka arkaya gelen birkaç yön kelimesidir. <!-- BELİRSİZ: Yol bulma örneğinin tam metni ve cevabı altyazıdan net çıkmıyor; ilgili slaytın karesi alınmadı. -->

Sonuçlar LSTM ve Memory Networks gibi temel yöntemlere (baseline) göre iyidir. Ayrıca destekleyici cümlelerin işaretlendiği güçlü denetime (strong supervision) çok ihtiyaç duymadan da bu işin yapılabileceği gösterilmiştir. Hocaya göre bu sistemler bir akıl yürütme yapabiliyor gibi görünmektedir, "ama hikâyenin devamı var".

## 9. İtiraz: Kısa Yol Öğrenme

### 9.1 Deney

Memory Networks'ün akıl yürütme yaptığı iddialarına karşı bir itiraz çıkmıştır (arXiv:1808.04926) (ekrandan, 02:00:00):

- Genel yapı (metin, soru, cevap) üçlüleridir.
- 5 veri kümesi üzerinde 3 modelin performansı ölçülmüştür.
- Veri kümelerinin orijinal halleri, yalnız metin kısımları ve yalnız soru kısımları kullanılmıştır. Bazı veri kümelerinde (özellikle "harika sonuçlar" dediğimiz yerlerde) bu eksik hallerle orijinal veri kümesine yakın sonuçlar alınmıştır.
- Bunun anlamı, bazı veri kümeleri için sistemin yalnız metne ya da yalnız soruya bakıp cevabı tahmin edebilmesidir.

Hoca deneyi şöyle açıkladı. Orijinal test konfigürasyonunda metni ve soruyu verip cevabı bulmaya çalışırsınız. İkinci konfigürasyonda metni verip soruyu boş bırakırsınız; üçüncüsünde yalnız soruyu verip metni boş bırakırsınız. Eğitim zamanında üçü de (metin, soru, cevap) vardır; sorun eğitimde değil, testtedir.

### 9.2 Derste tartışma

Hoca "Böyle bir deney sonucu bize ne söyler?" diye sorup sınıfa yorum yaptırdı.

**Soru:** Orijinal hallerin, metin kısımlarının ve soru kısımlarının kullanıldığı söyleniyor; geriye kalan neler kullanılmamış, tüm metin zaten kullanılmış olmuyor mu?
**Cevap:** Cevabı bulmak için normalde metne ve soruya ihtiyaç vardır; ikisi verilince sistem cevaplar. Örneğin 20 görevden başarılı birini seçelim: test kümesinde başarı çok yüksek. Sonra test kümesini değiştiriyorsunuz: yalnız metni veriyor, soruyu boş bırakıyorsunuz ve model yine cevabı doğru tahmin edebiliyor.

**Soru:** Bu bir aşırı öğrenme (overfitting) olabilir mi, model test kümesini ezberlemiş olabilir mi?
**Cevap:** Hayır. Aşırı öğrenme, eğitim kümesinde çok başarılı olup test kümesinde başarılı olmamaktır. Burada test kümesinde de başarılıdır; buna aşırı öğrenme denemez.

**Soru:** Cevap kullanılmadığı için mi etiket olmadan başarılı oluyor?
**Cevap:** Cevap zaten kullanılmıyor; cevabı biz tahmin etmeye çalışıyoruz. Cevabı bulurken bir sistemin normalde metni ve soruyu birlikte kullanması gerekir. Metni ve soruyu kullandığında çok doğru cevap veren sistem, soruyu kullanmadan, yalnız metni kullanarak da doğru tahmin edebiliyor.

**Soru:** Soru olmadığı için bir özet mi çıkarıyor?
**Cevap:** Hayır.

Hocanın cevabı: bu, her şeyden önce veri kümesinin doğru oluşturulmadığını gösterir.

### 9.3 Makine öğrenmesine "nasıl"ı söyleyemeyiz

Hoca bunu açıklamak için makine öğrenmesini ne zaman kullandığımızı sordu. Girdiden çıktının nasıl üretildiğini net tanımlayamadığımızda kullanırız. 3 ile 5'i toplamak ya da bir diziyi sıralamak için makine öğrenmesi kullanmayız, çünkü gerekli algoritmayı biliriz. Ama bir resimdeki nesnenin ne olduğunu söylemek, İngilizce bir metni Türkçeye çevirmek ya da bir resimdeki insan yüzlerini bulmak gibi problemlerde algoritmayı yazamayız. Ne yapılması gerektiğini biliriz ("şöyle bir girdi verirsen şöyle bir çıktı istiyorum"), ama aradaki geçişin nasıl olduğunu bilmeyiz. Makine öğrenmesi algoritmalarının ortak özelliği budur.

Hocanın örneği (önceki bir başka derste de anlattığını söyledi): tankların içine yerleştirilen kameralarla düşman ve dost tankları ayırt eden bir program yapılmak istenir. Düşman ve dost tank resimlerinden bir veri kümesi oluşturulur, eğitim, doğrulama ve test kümelerine bölünür; test kümesinde %90'ın üzerinde başarılı bir model elde edilir. Saha testlerinde ise tahminler korkunç kötüdür. Sonradan fark edilir ki dost tankların resimleri çekilirken hava açık, düşmanlarınki çekilirken hava kapalıdır. Model aslında havanın açık mı kapalı mı olduğunu öğrenmiştir: hava açıksa dost, kapalıysa düşman. İstenen şeyle ilişkisi olmayan ama onunla çok güçlü biçimde bağlantılı bir özellik vardır ve model bunu yakalar.

> **Ek bilgi (derste anlatılmadı):** Tank hikâyesi yapay zekâ literatüründe sıkça anlatılır, ama kaynağı belirsizdir ve büyük olasılıkla gerçek bir olaydan çok öğretici bir anekdottur. Anlattığı olgu ise gerçektir ve bugün "kısa yol öğrenme" ya da "sahte korelasyon" (spurious correlation) adıyla incelenir.

> **Hocanın vurgusu:** Makine öğrenmesi modellerine ne yapmaları gerektiğini söyleyebilirsiniz, ama nasıl yapmaları gerektiğini söyleyemezsiniz; onlar da kendi bildikleri gibi yaparlar. Bu anormal bir durum değildir, çünkü nasıl yapıldığını bilseydiniz makine öğrenmesi kullanmazdınız. Ama bunun farkında olmanız gerekir.

### 9.4 Soru cevaplamada kısa yollar

Soru cevaplamaya dönersek, modeller veri kümesindeki bazı yapay izleri (artifact) kullanabilir. Örneğin "metinde 'kedi' kelimesi geçiyorsa cevap şudur" ya da "soruda şu kelime varsa cevap şu türden bir kelimedir" gibi. Metni ve soruyu birbirine referans vermeden kullanıp cevabı üreten bu kısa yollara shortcut denir; bu tür sistemler bunları öğrenebilir. Buna kısa yol öğrenme (shortcut learning) denir.

Kısa yolların sebebi veri kümesinin çok iyi olmamasıdır. İyi bir veri kümesinde aynı metin için sorulan farklı soruların cevapları birbirinden farklı olmalı; aynı sorunun farklı metinlerdeki cevapları da birbirinden farklı olmalıdır. Metindeki ya da sorudaki alakasız bir ipucunu kullanarak eşleme yapma ihtimali varsa, model büyük olasılıkla onu yakalar. Aslında model veri kümesine göre doğru bir şey öğrenir, ama istediğiniz o değildir; bu durum daha iyi bir test kümesi kullandığınızda ya da sahada ortaya çıkar.

> **Hocanın vurgusu:** Her kısa yol zararlı değildir. Bazı kısa yollar sizin fark etmediğiniz ama gerçekten istediğiniz şekilde eşleme yapan ilişkiler olabilir; model aklınıza gelmeyen bir şeyi görüp ona göre sınıflandırabilir. Bu iyi bir şeydir ve problemi anlayışınıza da katkı sağlar. Ama bazı kısa yollar yalnız eşlemeye yarar, problemin gerçek çözümüne hiçbir katkı sağlamaz.

### 9.5 Sonuç tablosu

Slayttaki tablo bAbI'nin 20 görevi için orijinal (true dataset), yalnız soru (question only) ve yalnız metin (passage only) başarılarını verir (ekrandan, 02:08:40). Hocanın tartıştığı görevler:

| Görev | Orijinal | Yalnız soru | Yalnız metin | Hocanın yorumu |
|---|---|---|---|---|
| 1 | %100 | %18 | %53 | Ciddi düşüş var, iyi bir görev |
| 3 | %39 | %22 | %60 | Yalnız metinle orijinalden iyi; hiç iyi kurulmamış bir görev |
| 13 | %94 | %18 | ~%94 | Soruya hiç bağlı değil; %94'ün anlamı yok |

Hocaya göre bazı görevlerde yalnız soru ya da yalnız metin verildiğinde hiç fark yokken bazılarında büyük düşüşler olur; büyük düşüş olması o problemin iyi bir problem olduğunu gösterir. Aynı slaytta SQuAD üzerinde QANet için de sonuç vardır: tam eşleşme (EM) orijinalde %70,7, yalnız soruyla %0,6, yalnız metinle %10,9; F1 sırasıyla %79,1, %4,0 ve %14,8. Yani SQuAD'da eksik hallerle başarı çok düşer.

> **Ders sonrası not:** Hoca görev 1 için "sadece soruyu verdiğimizde %118" dedi; slayttaki değer %18'dir (ekrandan, 02:08:40). Görev 13'ün yalnız metin değeri karede imleçle kısmen örtülüdür; hocanın söylediği %94 kullanıldı.

## Örnek Sorular

**1. Duygu analizinde ima** (derste sözlü, 00:11:15)

Önceki dersin ödev niteliğindeki sorusu: "Yemeğimi 5 dakikada getirdiniz çok teşekkürler." ve "Yemeğimi 55 dakikada getirdiniz çok teşekkürler." cümlelerini bir dil modeline verin. Model ikinci cümledeki imayı anlayabiliyor mu?

> **Çözüm (derste verilen):** Öğrencilerin denemelerinde modeller iki cümleyi de olumlu olarak sınıflandırdı; İngilizce çeviride de sonuç değişmedi. Hocanın yorumu: modeller bu konuda henüz yeterince iyi değil. İkinci cümleyi olumsuz bulmak için yemek getirme süresinin normalde ne kadar olduğu gibi dünya bilgisi gerekir.

**2. Paragraf anlama başarısı** (ekrandan, 00:30:00)

5 şıklı paragraf sorularında eğitimsiz, karakter 3-gram TF vektörleri ve kosinüs benzerliğiyle %35 başarı elde ediliyor. Bu iyi bir sonuç mudur?

> **Çözüm (derste verilen):** Fena değildir, çünkü 5 şıkta şans başarısı $1/5 = \%20$'dir. Ancak yöntem yalnız ortak karakter üçlülerine bakar; bir kelimenin eş anlamlısı yazılınca çöker.

**3. Bilim sorusu** (ekrandan, 00:55:50)

"The Sun appears to move across the sky each day, rising in the east and setting in the west. What causes this apparent motion? (A) the rotation of Earth on its axis (B) the revolution of the Sun around Earth (C) the Earth's distance from the Sun (D) the properties of Earth's atmosphere"

> **Çözüm (derste verilmedi):** (A). Güneşin gökyüzündeki günlük görünür hareketi Dünya'nın kendi ekseni etrafında dönmesinden kaynaklanır.

**4. Şekle bağlı bilim sorusu** (ekrandan, 00:55:50)

Şekilde Güneş → bitkiler → tırtıllar → kurbağalar → yılanlar besin zinciri vardır. "Which organisms in this food chain are needed for all the other organisms to survive? A caterpillars B frogs C plants D snakes"

> **Çözüm (derste verilmedi):** (C) plants. Bitkiler zincirin başındaki üreticilerdir; diğer bütün canlılar doğrudan ya da dolaylı olarak onlarla beslenir. Hocanın vurgusu: soru metni aynı kalıp şekil değişirse cevap da değişebilir, bu yüzden şekli algılamak gerekir.

**5. Açıklamalı matematik sorusu: trenler** (ekrandan, 00:58:10)

"Two trains running in opposite directions cross a man standing on the platform in 27 seconds and 17 seconds respectively and they cross each other in 23 seconds. The ratio of their speeds is: A) 3/7 B) 3/2 C) 3/88 D) 3/8 E) 2/2"

> **Çözüm (slayttaki açıklama, derste ayrıca çözülmedi):** Hızlar $x$ ve $y$ m/s olsun. Birinci trenin uzunluğu $27x$, ikincisinin $17y$ metredir. Karşılıklı geçişte $(27x + 17y)/(x + y) = 23$, yani $27x + 17y = 23x + 23y$, $4x = 6y$, $x/y = 3/2$. Doğru şık B (python ile doğrulandı).

**6. Açıklamalı matematik sorusu: iki papaz** (ekrandan, 00:58:10)

"From a pack of 52 cards, two cards are drawn together at random. What is the probability of both the cards being kings? A) 2/1223 B) 1/122 C) 1/221 D) 3/1253 E) 2/153"

> **Çözüm (slayttaki açıklama, derste ayrıca çözülmedi):** $n(S) = \binom{52}{2} = 1326$, $n(E) = \binom{4}{2} = 6$, $P(E) = 6/1326 = 1/221$. Doğru şık C (python ile doğrulandı).

**7. bAbI sorusu** (ekrandan, 01:03:00)

"1 Mary banyoya gitti. 2 Sandra bahçeye gitti. 3 Daniel bahçeye gitti. 4 Daniel ofise gitti. 5 Sandra oradaki sütü aldı. 6 Sandra sütü oraya bıraktı. 7 Süt nerede?" Cevap nedir, hangi cümleler gereklidir? Memory Networks bunu nasıl bulur?

> **Çözüm (derste verilen):** Cevap "bahçe"; gerekli cümleler 6 ve 2. Memory Networks önce soruya en benzeyen cümleyi (6) seçer, sonra soru ile 6'nın birleşimine en benzeyen cümleyi (2) seçer, son adımda üçünün birleşimine en benzeyen sözlük kelimesini ("bahçe") cevap olarak verir.

**8. Yalnız metinle yüksek başarı ne anlama gelir?** (derste sözlü, 01:52:29)

Bir soru cevaplama modeli test kümesinde metin ve soru verildiğinde çok başarılı. Testte soru çıkarılıp yalnız metin verildiğinde de (ya da metin çıkarılıp yalnız soru verildiğinde de) doğru cevabı tahmin edebiliyor. Bu deney sonucu bize ne söyler?

> **Çözüm (derste verilen):** Bu bir aşırı öğrenme değildir, çünkü test başarısı da yüksektir. Veri kümesi doğru oluşturulmamıştır: model metni ve soruyu birlikte kullanmak yerine birindeki alakasız bir ipucundan cevabı üreten kısa yollar (shortcut) öğrenmiştir. İyi bir veri kümesinde aynı metin için farklı cevaplı farklı sorular, aynı soru için farklı cevaplı farklı metinler bulunmalıdır.

**9. Ödev: üç kelimeden cümle üretme** (derste sözlü, 02:10:10)

Verilen üç kelimeden bir cümle üretmek için en az iki yöntem geliştirin. Yöntemleri en az 50 kelime üçlüsü için ürettikleri cümleler üzerinden, mutlaka insan yargısı da kullanarak karşılaştırın (otomatik ölçütler de eklenebilir). Örnek giriş: "çocuk, inek, hava"; örnek çıkış: "Hava açınca dışarı çıkan çocuk inek gördü." Üç kelimeyi de içeren bir cümleyi büyük bir derlemden bulup getirmek çözüm olarak kabul edilmez. Eğitim kümesinin nasıl oluşturulacağı ve hangi mimarinin kullanılacağı ödevin araştırma sorusudur.

## Dersin Toparlaması

Bu derste Bölüm 6'nın uygulamalarına devam edildi. Varlık ismi tanıma, karakter tabanlı bir LSTM ile her karaktere bir varlık sınıfı atayan bir sekanstan sekansa problem olarak ele alındı. Sınıf dengesizliği, "hiçbiri" sınıfı, son işlem ve kuralların rolü konuşuldu. Ardından bir sistemin metni anlayıp anlamadığını soru cevaplamayla ölçme fikri üzerinden paragraf anlama ve soru cevaplama veri kümeleri incelendi: Türkçe uni_paragraf ve cevap_nerede, SQuAD, Allen AI bilim soruları, açıklamalı matematik soruları ve SWAG. Karakter 3-gramları gibi çok basit, eğitimsiz yöntemlerin şansın çok üstüne çıkmasının veri kümesinin basitliğini gösterdiği vurgulandı.

Dersin ikinci yarısı bAbI üzerinde çıkarım yapan mimarilere ayrıldı. Memory Networks, $U$ matrisleriyle öğrenilen bir benzerlik ve arg max ile katı seçimlerle iki adımlı bir çıkarım yapar, ama destekleyici cümlelerin eğitimde işaretlenmesini ister. End-to-End Memory Networks bu gerekliliği softmax tabanlı yumuşak seçim, yani dikkat mekanizmasına benzeyen bir ağırlıklı toplamla kaldırır; çok adımlı akıl yürütmeye ve konum gömmelerine olanak verir. Son olarak bu modellerin akıl yürütme yaptığı iddiasına karşı itiraz incelendi: bazı görevlerde yalnız metin ya da yalnız soru ile de yüksek başarı alınması, modellerin veri kümesindeki kısa yolları öğrendiğini gösterir. Hoca bir sonraki derste bu konudan devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
