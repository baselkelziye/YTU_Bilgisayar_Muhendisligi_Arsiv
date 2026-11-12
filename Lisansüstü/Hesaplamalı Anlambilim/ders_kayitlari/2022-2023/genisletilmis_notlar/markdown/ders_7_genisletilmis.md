# Ders 7 Genişletilmiş Notu: İnsan-Makine İşbirliği, Sıfır Çekimli Öğrenme, Veri Zenginleştirme ve Yeni Öğrenme Yaklaşımları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kaldığımız Yer ve İnsan-Makine İşbirliği
- 2. İnsan-Makine İşbirliği Örnekleri
- 3. İnsan Geri Bildirimiyle Pekiştirmeli Öğrenme (RLHF)
- 4. Az Sayıda Örnekle Eğitim
- 5. Sıfır Çekimli Makine Çevirisi
- 6. Sıfır Çekimli Sınıflandırma
- 7. Veri Zenginleştirme
- 8. Gürültü ile Düzenlileştirme
- 9. Temsilde Noktadan Dağılıma
- 10. Makine Öğrenmesi Algoritmalarını Kandırmak
- 11. Planlı Öğrenme (Curriculum Learning)
- 12. Hayat Boyu Öğrenme
- 13. Kendi Kendine Öğrenme (Self-Supervised Learning)
- 14. Karşıtsal Öğrenme (Contrastive Learning)
- 15. Bağlam İçi Öğrenme (In-Context Learning)
- Örnek Sorular
- Dersin Toparlaması

## 1. Kaldığımız Yer ve İnsan-Makine İşbirliği

Bu derste Bölüm 4'e, yani hocanın "makine öğrenmesi versiyon 2" dediği, makine öğrenmesindeki yeni problem ve yaklaşım türlerini anlatan kısma devam edildi ve bölüm tamamlandı. Önceki derste aktif öğrenme, yarı eğiticili öğrenme, öğrenmenin transferi, çok görevli eğitim, hiperparametre optimizasyonu ve aktif örnekleme anlatılmıştı. Aktif örneklemede, aktif öğrenmeden farklı olarak, modelin hangi bölgeden yeni örnek istediğini kendisinin söylemesinden bahsedilmişti. Bu ders oradan, insan-makine işbirliğiyle başladı.

İnsanların ve makinelerin farklı kabiliyetleri vardır. İnsan-makine işbirliği bu kabiliyetleri bir süreçte birleştirip ikisinden de faydalanmaktır. Literatürde farklı adlarla geçer. Slayttaki tanım şöyledir (ekrandan, 00:08:45):

- İnsan ve makine zekasının birleşimi (the combination of human and machine intelligence), döngüde insan (human in the loop), zayıf denetim (weak supervision).
- İnsanlar (yavaş, doğru):
  - Veri etiketleyebilir.
  - Tahminleri düzeltebilir.
  - Tahminler arasından seçim yapabilir; örneğin 100 sınıftan en olası 5'inden doğru olanı seçebilir.
  - Örneklerin ortak bir özelliği için kural verebilir: "İçinde şu ifade geçenler negatiftir", "Kedilerin kuyruğu vardır".
- Makineler (hızlı, çok sayıda bilgiyle başa çıkabilirler, az doğru):
  - Tahmin üretebilirler.

Hoca makinelerin belli modeller kurulduğunda tahmin üretebildiğini, bu tahminlerin doğru da yanlış da olabileceğini, ama her durumda hızla çok sayıda tahmin üretebildiklerini vurguladı.

## 2. İnsan-Makine İşbirliği Örnekleri

### 2.1 Video etiketleme

Videolardaki belli nesneleri, örneğin insanları ya da araçları etiketlemek istediğimizi düşünelim. Resim etiketlemeyle video etiketleme arasında önemli bir fark vardır: video çok sayıda resimden (kareden) oluşur ve her karede ayrı etiketleme yapmak çok zahmetlidir. Bir dakikalık bir videoyu bile kare kare etiketlemek epey zor bir iştir.

Hoca tahtaya şöyle bir örnek çizdi: sahnede yavaş yavaş sağ üste doğru yürüyen bir insan var. Siz bu insanı yalnız birkaç anahtar karede işaretliyorsunuz ("burada bir insan var"). Aradaki kareleri ise makine tahmin eder: verilen ana noktalar arasındaki yörüngenin nasıl olduğunu interpolasyonla bulmaya çalışır. Böylece insanın birkaç etiketi ve makinenin tahmini birlikte, örneğin dört etiketle yaklaşık otuz karenin etiketlenmesini mümkün kılar.

<!-- BELİRSİZ: Hocanın tahtaya çizdiği kare numaraları altyazıda karışık geçiyor (1, 10, 15, 20, 30, 100); kesin numaralar nota alınmadı. -->

Slaytta bu konuyla ilgili iki video bağlantısı vardı; hoca bunlara daha sonra bakılabileceğini söyledi (ekrandan, 00:10:00).

### 2.2 Otomatik çeviri ve insan düzeltmesi

Günümüzde çeviride genelde önce bir makine çevirisi alınır, sonra insan bunun üzerinde düzenleme yapar. Bu da insan-makine işbirliğinin bir örneğidir.

### 2.3 Zayıf denetim (weak supervision)

Twitter'da duygu analizi (sentiment analysis) yapacağınızı düşünün. Bunun için etiketli bir veri kümesi gerekir. En sağlam yol, her tweeti okuyup tek tek etiketlemektir. Bunun yerine şöyle kurallar tanımlayabilirsiniz: "İçinde şu şu ifadeler geçiyorsa bunun sınıfı şudur", "İçinde şu ifadeler geçmiyorsa sınıfı bu değildir". Resimler için de benzer üst seviye kurallar verilebilir: "Kuyruğu olanlar hayvandır", "Yüzü olanlar insandır", "Gözlüğü olanlar insandır".

Burada örnek bazında etiketleme yapılmaz; bir örnekler topluluğu için genel bir şey söylenir.

- **Avantaj:** Az miktarda bilgi vererek çok sayıda örnek etiketlenir. "Şu kelimelerden herhangi biri geçenin sınıfı şudur" diyen bir kural, verinin en azından bir kısmını hızla etiketleyebilir.
- **Dezavantaj:** Söylenen kural her zaman doğru olmayabilir; örneklerin yalnız bir kısmı için doğrudur.

Zayıf denetimde bir sürü kural birlikte kullanılır. Her kural zayıf bir etiket üretir, bu yüzden bir örnek için birden fazla zayıf etiket oluşur. Bunlar çelişebilir de: bir kural bir sınıfı, başka bir kural başka bir sınıfı söyleyebilir. Ardından bu zayıf etiketleri birleştirip güçlü (en azından daha güçlü) etiketlere dönüştüren bir model kurulur. Bu iş için Snorkel adlı bir çerçeve (framework) vardır (ekrandan, 00:10:00).

## 3. İnsan Geri Bildirimiyle Pekiştirmeli Öğrenme (RLHF)

Hocaya göre insan-makine işbirliğinin şu anda en yaygın ve popüler olduğu nokta, ChatGPT ve onun öncesi ile sonrasındaki modellerde kullanılan, insan geri bildirimiyle pekiştirmeli öğrenmedir (reinforcement learning from human feedback, RLHF).

### 3.1 Denetimli öğrenme ile pekiştirmeli öğrenmenin farkı

Denetimli öğrenmede (supervised learning) sisteme "Sana şu girdiyi vereceğim, bunun çıktısı şu olmalı" denir; çıktının ne olması gerektiği açıkça söylenir.

Pekiştirmeli öğrenmede (reinforcement learning) ise çıktının ne olması gerektiği verilmez. Sistem bir çıktı üretir ve ona "Bu çıktın iyi ya da şu ölçüde iyi, kötü ya da şu ölçüde kötü" denir. Yani bir ödül (reward) ya da ceza verilir. Ne olması gerektiği söylenmeden, belki ne olması gerektiğine benzerliğine göre bir değerlendirme yapılır.

Peki neden doğrudan doğru cevap söylenmiyor? Çünkü etiketleyen insan da doğru cevabı tam olarak bilmeyebilir. Bir durumda tam olarak ne yapılması gerektiğini bilmeyebilir; ama sistem bir şey ürettiğinde bunun hedefe yakın mı uzak mı olduğu hakkında bir fikri olabilir. Bu, denetimli öğrenmedeki etiketlemeye göre daha kolaydır. Denetimli öğrenmede etiketlemek için tam uzman olmak, çıktının ne olması gerektiğini kesin olarak ifade edebilmek gerekir.

### 3.2 İnsan geri bildirimi neden pahalı?

Pekiştirmeli öğrenmenin ünlü olduğu klasik uygulamalarda (hoca AlphaZero'yu örnek verdi) geri bildirim bir insandan gelmez. Ortamdan (çevreden) ya da kendi kendine oynamaktan (self-play) elde edilir. Örneğin iki strateji birbiriyle maç yapar; kazanana pozitif, kaybedene negatif geri bildirim verilir. Bu insan müdahalesi gerektirmez, dolayısıyla milyarlarca kez yapılabilir ve çok ölçeklenebilirdir.

İnsan kabiliyetlerini tahmin etmeye, onların simülasyonunu yapmaya çalışıyorsak insandan geri bildirim almak iyi bir şeydir. Ama pahalıdır. Süreç milyarlarca adım içerecekse her adımda insandan ödül istemek hem zaman hem para açısından ölçeklenemez.

### 3.3 Ödül modeli fikri

Hocaya göre burada (OpenAI'ın yaklaşımında) yapılan asıl kritik iş, ölçeklenebilir biçimde insan geri bildirimi almanın bir yolunu tanımlamaktır. İnsanların bir sistem çıktısı hakkında vereceği ödülü ya da cezayı tahmin eden bir model eğitilir. Yani "İnsan olsaydı bu girdiye karşılık bu çıktıya ne derdi? Aferin, iyi bir çıktı mı derdi, yoksa çok kötü mü derdi?" sorusunu cevaplayan bir model kurulur. Bu modele ödül modeli (reward model) denir.

### 3.4 InstructGPT'nin üç adımı

Hoca slayttaki şeklin ChatGPT'nin değil, InstructGPT'nin mimarisi olduğunu belirtti; burada diyalog yapısı yoktur. InstructGPT bir talimat takip eden (instruction following) modeldir: kullanıcının metinle ifade edebildiği çok geniş bir istek kümesine karşılık verebilen bir model. ChatGPT bunu bir diyalog arayüzü üzerinden gerçekleştirir.

Slayttaki üç adım şöyledir (ekrandan, 00:20:00 ve 00:30:00):

```text
Adım 1: Gösterim verisi topla, denetimli bir politika eğit.
  - İstem veri kümesinden bir istem (prompt) seçilir.
  - Bir etiketleyici istenen çıktı davranışını gösterir (yazar).
  - Bu veri GPT-3'ü denetimli öğrenmeyle ince ayarlamak için kullanılır (SFT).

Adım 2: Karşılaştırma verisi topla, ödül modeli eğit.
  - Bir istem ve birkaç model çıktısı örneklenir (A, B, C, D).
  - Bir etiketleyici çıktıları en iyiden en kötüye sıralar.
  - Bu veri ödül modelini (RM) eğitmek için kullanılır.

Adım 3: Ödül modeline karşı politikayı pekiştirmeli öğrenmeyle optimize et.
  - Veri kümesinden yeni bir istem seçilir.
  - Politika bir çıktı üretir.
  - Ödül modeli çıktı için bir ödül hesaplar.
  - Ödül, politikayı PPO ile güncellemek için kullanılır.
```

**Politika (policy) nedir?** Pekiştirmeli öğrenmede politika, hangi durumda ne yapılacağını tanımlayan şeydir, bir hareket politikasıdır; gözlem uzayından (observation space) eylem uzayına (action space) bir eşleme yapan fonksiyondur. Bu mimaride politika bir derin öğrenme mimarisiyle, yani üretici bir dil modeliyle gerçekleştirilir: belli bir girdiye karşılık bir çıktı üretir.

**Adım 1** aslında pekiştirmeli öğrenme değildir; denetimli bir politikadır. İstemler (talimatlar) bir yerden çekilir, insanlar bunlara karşı sistemin ne yapması gerektiğini yazar. Elde "Böyle bir girdiye karşı böyle bir çıktı üretmelisin" diyen veri olur. Bu veriyle GPT-3 ince ayarlanır. Burada insan işin içine girer. Hoca bu adımın ölçeklenebilir olmadığını vurguladı: her girdi için insana çıktı yazdırmak, milyarlarca farklı görevde milyarlarca insana yazdırmak mümkün değildir.

**Adım 2**'de ince ayarlanmış model bir girdiye karşı farklı farklı çıktılar üretir.

**Soru (hoca sordu):** Bir tane girdiye karşı nasıl birden fazla çıktı üretilebilir?
**Cevap:** Bu modeller üretici modeller olduğu için içlerinde dropout, rastgelelik ya da sıcaklık (temperature) gibi üretim sürecini farklılaştırabilen mekanizmalar vardır. Bu yüzden aynı isteğe karşı farklı çıktılar üretebilirler.

Ardından bir insan bu tahminlere bakar ve onları iyiden kötüye sıralar. Hocanın örneğinde etiketleyici "En iyisi D olurdu, ondan sonra şu gelir, en kötüsü B" der. Hoca illa böyle olmak zorunda olmadığını, ama insanın burada pekiştirmeli öğrenme için bir geri bildirim verdiğini söyledi. Bu girdiler, onlara karşı üretilen çıktılar ve etiketleyicilerin verdiği sıralamalar kullanılarak ödül modeli eğitilir.

Ödül modeli, çıktıları üreten modelden (üretici, generatif model) **farklı** bir modeldir. Görevi, üretici modele geri bildirim vermektir ve insan geri bildiriminden beslenir: üretici modelin ürettiği çıktılara karşı hangi ödüllerin verileceğini gösteren, insan sıralamalarından elde edilmiş bir tür denetimli veri kümesiyle eğitilir. Yani üstteki iki süreci (çıktı üretme ve insanın değerlendirmesi) modelleyen bir yapıdır.

**Adım 3**'te artık elde iki model vardır: üretici model ve ödül modeli. Ödül modeli, üretici modelin ürettiği çıktıların iyi mi kötü mü olduğunu söyler. Böylece elde ölçeklenebilir bir pekiştirmeli öğrenme sistemi olur, çünkü ödülleri artık insan değil makine sağlar. Üretici modele bir girdi verilir, mevcut model bir çıktı üretir, ödül modeli bu çıktının iyi mi kötü mü olduğunu söyler, üretici model buna göre güncellenir (ince ayarlanır). Hoca güncelleme adımı sayısı olarak en büyük kısmın bu son adımda olduğunu, ama rakamları tam hatırlamadığını belirtti.

> **Hocanın vurgusu:** Buradaki asıl hile ödül modelini oluşturmaktır. Standart biçimde insan geri bildirimiyle pekiştirmeli öğrenme ölçeklenebilir değildir; ödül modeli sayesinde ölçeklenebilir bir yapıya kavuşturulmuştur. Bu, insan-makine işbirliğinin en güzel örneklerinden biridir.

Hoca bu mekanizmanın ChatGPT'de de kullanıldığının ifade edildiğini, ama tamamen aynısı mı olduğunu bilmediğimizi söyledi: InstructGPT'nin makalesi vardır, ChatGPT için ise blog yazısında bu yöntemi kullandıklarını belirtmişlerdir. Yalnız bu mu var, başka şeyler de mi var, çok fazla bilinmiyor; hoca bu noktada "OpenAI o kadar da open değil" dedi.

> **Ek bilgi (derste anlatılmadı):** Slayttaki PPO (proximal policy optimization), politika gradyanı ailesinden bir pekiştirmeli öğrenme algoritmasıdır. Her güncellemede politikanın bir önceki politikadan çok uzaklaşmasını sınırlayarak eğitimi kararlı tutmayı amaçlar. InstructGPT'de büyük olasılıkla, modelin ödül modelini "kandıracak" tuhaf metinlere kaymasını önlemek için SFT modelinden uzaklaşmaya bir ceza terimi de eklenmiştir.

## 4. Az Sayıda Örnekle Eğitim

### 4.1 Chollet'nin sözü: örüntü tanıma ve zeka

Slaytta François Chollet'nin bir ifadesi vardır (ekrandan, 00:40:00):

> "Any problem can be treated as a pattern recognition problem if your training data covers a sufficiently dense sampling of the problem space. What's interesting is what happens when your training data is a sparse sampling of the space -- to extrapolate, you will need intelligence."

Yani veri çok fazlaysa ve problem uzayını yoğun biçimde kapsıyorsa elinizdeki modelin bir örüntü tanıyıcı olması yeter. Asıl önemli olan, eğitim verisi çok fazla olmadığında, uzayın tamamını kapsayan örnekler yokken de performanslı bir model elde edebilmektir. Bunun için modelin ekstrapolasyon yapabilmesi gerekir.

### 4.2 İnterpolasyon ve ekstrapolasyon

Hoca tahtada iki boyutlu bir uzayda (bir giriş $x$, bir çıkış $y$) birkaç kırmızı örnek noktası çizdi.

- **İnterpolasyon:** Örneklerin bulunduğu bölgenin içinde tahmin yapmaktır. Örneğin "Bu noktaların şöyle bir modelden geldiğini varsayıyorum" deyip bölge içindeki bir noktanın değerini tahmin etmek.
- **Ekstrapolasyon:** Bu bölgenin dışında, yani verinin olmadığı yerlerde (aralığın öncesinde ve sonrasında) davranışı tahmin etmektir. Eğrinin dışarıda "şöyle devam ediyor", "böyle devam ediyor" ya da "buradan sonra düz gidecek" demek, bunların her biri birer ekstrapolasyondur.

Chollet'ye göre interpolasyon bir örüntü tanıma işi olarak tanımlanabilir; yeterince veri varsa iş daha kolaydır. Verinin olmadığı yerlerde anlamlı tahminlerde bulunabilmek, yani ekstrapolasyon için ise zeka gerekir.

### 4.3 Tek çekimli ve sıfır çekimli öğrenme

**Tek çekimli öğrenme (one-shot learning)**, eğitim kümesinde her sınıfın tek bir örneğinin olduğu problemlerdir. Slayttaki örnek bir zürafa resmidir (ekrandan, 00:40:00): bir resimde zürafa olup olmadığını bulacak bir modelin eğitim kümesinde zürafaya dair envai çeşit resim olmasıyla yalnız bir tane resim olması arasında büyük fark vardır. Zürafanın farklı açılardan, farklı durumlarda, farklı ortamlarda nasıl göründüğünü tek bir resimden öğrenmek çok daha zordur. Hoca "tek örnek" derken aslında "az örnek" durumunu da kastettiğini, tek örneğin işi daha da zorlaştırdığını söyledi.

**Sıfır çekimli öğrenme (zero-shot learning)** bunun daha zor halidir: o sınıfa ya da o probleme ait elimizde hiç örnek yoktur. Hoca bunun önemli olduğunu, çünkü ödevin de bu konuda olduğunu belirtti.

## 5. Sıfır Çekimli Makine Çevirisi

İlk örnek Google'ın sıfır çekimli makine çevirisidir (ekrandan, 00:44:30). Slayttaki maddeler:

- Her olası dil ikilisi için ayrı birer model eğitmek yerine (100 dilden 100 dile)
- A→B, B→C var, A→C yok
- Girişler ortak bir katmana
- Çıkışlar ortak katmandan

Elinizde İngilizce-Türkçe paralel bir derlem varsa, yani "Şu İngilizce metnin Türkçe karşılığı şudur" diyen denetimli bir veriniz varsa, İngilizceden Türkçeye bir model eğitebilirsiniz. Ama Google'ın istediği, 100 dilden 100 dile çeviri yapabilmektir. Her ikili için ayrı model kurmaya kalkılırsa yaklaşık 10.000 model gerekir. Bunları tek tek eğitmek hem zahmetlidir, hem de her ikili için yeterli eğitim verisi yoktur. İngilizceyle hemen her dilin paralel derlemi muhtemelen vardır, ama her dilin her dille paralel derlemi yoktur.

> **Ders sonrası not:** Hoca 100 dilden 100 dile durum için "10 bin model" dedi. Bu yuvarlak bir sayıdır; bir dilden kendisine çeviri gerekmediği için yönlü dil ikilisi sayısı $100 \cdot 99 = 9900$'dür.

Çözüm, bütün girişleri ortak bir temsile (aynı uzaya) dönüştürmek ve çıkışları bu ortak katmandan üretmektir. Girdiler farklı dillerden olsa da hangi dilde oldukları bilinerek tek bir uzayda tutulur. Çıktıyı üreten kısımlar ise hedef dili bir "mod" olarak alıp üretimi gerçekleştirir. Böylece hangi dilden olursa olsun metin tek bir temsil uzayına çevrilir ve bu uzaydan istenen hedef dilde cümle üretilebilir. Örneğin Türkçe ile Vietnamca arasında paralel derlem olmasa bile, Türkçe-İngilizce ve İngilizce-Vietnamca derlemler varsa sistem Türkçeden Vietnamcaya çeviri yapabilir.

Bunun için gereken koşul, **aynı cümlenin farklı dillerdeki temsillerinin birbirine benzer olduğu bir anlamsal uzaydır**. Slayttaki görselde (ekrandan, 00:44:30) Japonca, Korece ve İngilizce cümlelerin temsilleri gösterilir; "aynı anlamlı farklı kaynak dillerdeki cümlelerin temsilleri" bir arada kümelenir. Hoca aynı renkle işaretlenmiş cümlelerin birbirine anlamsal olarak yakın olduğunu, renklerin ise dilleri gösterdiğini anlattı.

<!-- BELİRSİZ: Hoca renkleri anlatırken (00:47:55) önce her rengin bir anlam grubu olduğunu, sonra her rengin bir dil olduğunu söylüyor; hangi rengin hangi dile karşılık geldiği altyazıdan kesin çıkmıyor. -->

## 6. Sıfır Çekimli Sınıflandırma

### 6.1 Problem

Etiketli veri yoktur. Etiketli veri olmadan, dil modellerini ya da sinirsel dil modellerini kullanarak bir metnin sınıfını belirleyebilir miyiz? Sınıflara ait örnekler önümüzde yoktur, ama hangi sınıflara ayırmak istediğimizi biliyoruz. Örneğin X konusu hakkındaki tweetleri, o konuyu ifade eden anahtar kelimelerle indirmişsiniz ve olumlu ya da olumsuz diye ayırmak istiyorsunuz; ama bunları tek tek etiketlemeye gücünüz yok. Hoca bunun yalnız dil modelleriyle sınırlı olmadığını, resimler için de pekala mümkün olduğunu söyledi.

Slayttaki iki yöntem şöyledir (ekrandan, 00:50:00).

### 6.2 Yöntem 1: Temsil uzayında en yakın sınıf

```text
Yöntem 1:
  Sınıfları belirle.
  Sınıfları temsil eden örnekleri ve temsillerini bul (X_i, i = 1:N).
  Yeni gelen örneğin temsilini bul (K).
  K, X_i'lerin hangisine en yakınsa sınıfı odur.
```

Burada $N$ sınıf sayısıdır. Önce sınıflar belirlenir; problem neyse onu tanımlamadan zaten olmaz. Sonra sınıfları temsil ettiğine inandığımız örnekler (ya da temsiller) bulunur. Yeni gelen örneğin temsili $K$ hesaplanır ve $K$'nın $X_i$'lerden hangisine yakın olduğuna bakılır. Yakınlık örneğin kosinüs uzaklığı gibi bir ölçüyle bulunur. Bunun için $K$ ile sınıfları ifade ettiğini düşündüğünüz metinlerin aynı uzayda temsil edilmesi gerekir.

Örneğin iki sınıf olsun: olumlu ve olumsuz. Tweetin olumluyu ifade eden temsile uzaklığına ve olumsuzu ifade eden temsile uzaklığına bakılır; hangisine daha yakınsa sınıfı odur.

Temsillerin ne olacağı tercihe ve gereksinime bağlıdır: word2vec gibi temsiller olabileceği gibi BERT gibi daha karmaşık ya da çok daha karmaşık yapılar da olabilir.

### 6.3 Doğal dil çıkarımı (NLI) veri kümesi

Yöntem 2'yi anlamak için önce NLI (natural language inference) veri kümesini bilmek gerekir. Hoca bu veri kümesinin sorunlarından ileriki haftalarda bahsedeceklerini söyledi. NLI veri kümesi iki cümleden oluşan örneklerden ve bu iki cümle arasındaki ilişkiyi gösteren üç sınıftan oluşur:

- **Gerektirme (entailment):** Birinci cümle doğruysa ikinci cümle de doğrudur.
- **Çelişki (contradiction):** Birinci cümle doğruysa ikinci cümle yanlıştır.
- **Nötr (neutral):** Birincinin doğru olması, ikincinin doğru ya da yanlış olmasını gerektirmez, onun hakkında bir şey söylemez.

BERT bu veri kümesiyle ince ayarlandığında şunu yapabilir hale gelir: ona iki cümle verirsiniz, size iki cümle arasındaki ilişkinin ne olduğunu, daha doğrusu üç sınıfın her birine ait olma olasılığını söyler. Örneğin gerektirme %90, çelişki %5, nötr %5.

### 6.4 Yöntem 2: NLI ile eğitilmiş modelde gerektirme olasılığı

```text
Yöntem 2:
  BERT vb. bir dil modelini NLI vb. bir veri kümesi ile eğit (modelX).
  Sınıfları belirle.
  Sınıfları temsil eden örnekleri bul (X_i, i = 1:N).
  Yeni gelen örnek: K
  "X_i [sep] K" örneklerini modelX'e ver.
  Bunların içinde entailment olasılığı en yüksek olan K'nın sınıfıdır.

  Bu metnin konusu {sağlık, spor vb.}
  Bu tweet bana {neşeli, hüzünlü vb.} hissettiriyor.
```

Yöntem 1'e çok benzer, ama burada karşılaştırma doğrudan temsil uzayında yapılmaz. [SEP] (separator), iki metni birbirinden ayırmak için kullanılan ayraçtır. $X_i$ her bir sınıfı ifade eden kalıptır, örneğin "Bu metnin konusu sağlık". $K$ ise sınıflandırılacak haber metnidir. İkisinin sırası çok önemli değildir. Bu ikili modelX'e verildiğinde model, $X_i$ ile $K$ arasındaki ilişkinin üç sınıfa ait olma olasılıklarını verir. Bunlardan gerektirme olasılığı alınır. Her sınıf kalıbı için gerektirme olasılığına bakılır; en yüksek gerektirme olasılığına sahip kalıbın sınıfı, metnin sınıfıdır. Örneğin metin "Bu metnin konusu sağlık" kalıbıyla değil de "Bu metnin konusu spor" kalıbıyla verildiğinde en yüksek gerektirme olasılığını alıyorsa sınıfı spordur.

Hoca ödevde Yöntem 1'e benzer bir şey yapılacağını belirtti: yeni gelen örneğin ve sınıf kalıplarının temsilleri doğrudan (BERT ya da başka bir modelden) alınacak ve o temsil uzayında uzaklık hesabı yapılacaktır. Ödevde NLI ile model eğitmek yoktur.

## 7. Veri Zenginleştirme

### 7.1 Amaç

Veri zenginleştirme (data augmentation), yeni eğitim verileri üretmektir. Slayttaki başlıklar: yeni eğitim verileri üretmek, görüntüler için, metin verileri için, genel veriler için (ekrandan, 01:10:00). Verinin tipine bağlı yöntemler olduğu gibi genel veriler için yöntemler de vardır.

Amaç, elimizdeki veri miktarını anlamlı bir şekilde artırmaktır. Bunun bir yolu yeni veri toplamaktır. İkinci yol, var olan veriler üzerinde çeşitli değişiklikler yaparak veri miktarını artırmaktır. Örneğin bir nesne tanıma veri kümesindeki resimleri $\pm 30$ derece döndürmek resimdeki nesnenin sınıfını değiştirmez. Sınıfı değiştirmeyen bu tür dönüşümlerle etiketli veri miktarı artırılmış olur. Ayrıca model bu dönüşümlere karşı daha güçlü, daha dayanıklı hale gelir; test örneklerinde de bu tür değişiklikler varsa model hala istediğimiz şeyi yapabilir.

> **Hocanın vurgusu:** Veri zenginleştirme etiketli veri miktarını her ne pahasına olursa olsun artırmak değildir; model performansını iyileştirecek şekilde artırmaktır.

### 7.2 Görüntüler için

Görüntüler için birçok teknik vardır: döndürme, elastik deformasyon, rastgele kırpma, ayna yansıması, renk bilgilerinde değişim (ekrandan, 01:13:00). Slayttaki örneklerde bir kedi resminden 224x224 boyutlu rastgele kırpmalar alınır; bir kelebek resmine ise doku kaldırma (de-texturized), renksizleştirme (de-colorized), kenar güçlendirme (edge enhanced), belirgin kenar haritası (salient edge map) ve çevirme/döndürme (flip/rotate) uygulanır.

Hoca önemli bir noktaya dikkat çekti: model bir eğitim örneğinin kendisini belki de hiçbir zaman olduğu gibi görmez. Örneğin bir kedi resminin üzerine her epokta rastgele bir işlem uygulanır: bazen kırpma, bazen hem kırpma hem renk değişimi, bazen ayna yansıması. Hoca ayna yansımasının bazı durumlarda iyi bir şey olmadığını da ekledi. Sistem orijinal örneği hiç görmeden, onun üzerine farklı işlemler uygulanmış örnekleri göre göre test kümesindeki varyasyonlara karşı daha güçlü hale gelir. Bunları yapmak için birçok araç vardır ve bu yaklaşımlar görüntü işlemede artık oldukça standarttır.

> **Hocanın vurgusu:** Veri zenginleştirmede alan (domain) bilgisi önemlidir. Örneğin MNIST veri kümesinde resimden rastgele parçalar kırpmak makul olmayabilir. Bir radyoloji veri kümesinde bazı filtreleri uygulamak da uygun olmayabilir. Alana göre hareket etmek çok daha iyi bir yaklaşımdır.

### 7.3 Üretici çekişmeli ağlar (GAN)

Veri zenginleştirmede kullanılabilecek yaklaşımlardan biri üretici çekişmeli ağlardır (generative adversarial networks, GAN). Slayttaki maddeler (ekrandan, 01:20:00):

- GAN'lar iki ağdan oluşmaktadır.
- Üretici ağ: rastgele bir gürültüden eğitim kümesine benzer örnekler üretmeye çalışır.
- Ayırt edici ağ: gerçek eğitim örnekleriyle yapay örnekleri birbirinden ayırmayı öğrenir.
- Bu iki ağ birbiriyle çekişme halindedir. Eğer üretici ağ çok başarılı olursa ayırt edici ağ doğal olarak başarısız olmaktadır.
- Bu yaklaşım özellikle görüntü veri kümeleri için çok gerçekçi yapay örneklerin üretimini sağlamaktadır.

Slayttaki yüz resimlerinde ilk sıra üretilen yüzleri, sonraki beş sıra her birine en benzer eğitim örneklerini gösterir.

Hoca bunu RLHF ile karşılaştırdı: orada bir üretici model ve bir ödül modeli vardı; burada da bir üretici (generatif) model ve bir ayırt edici (diskriminatif) model vardır. İkisi birbirine karşıdır; bu yüzden bu yaklaşıma çekişmeli (adversarial) ağlar denir. Üretici yeni örnekler üretir; ayırt edici bu örneğin gerçek mi, makinenin ürettiği mi olduğunu ayırt etmeye çalışır.

**Soru (hoca sordu):** Ayırt edici modelin çok başarılı olmasının anlamı neden üretici modelin çok başarısız olmasıdır?
Bir öğrenci önce aşırı uyum (overfitting) olabileceğini söyledi; hoca burada bir test kümesi olmadığını belirtti. Başka bir öğrenci üretici modelin yeterince gerçekçi sonuç üretmiyor olabileceğini söyledi.
**Cevap:** Ayırt edici model bir resmin üretici model tarafından mı üretildiğini, yoksa gerçek bir resim mi olduğunu çok iyi ayırt edebiliyorsa, gerçek resimlerle üretilen resimler arasında çok bariz bir fark var demektir. Bunu çok kolay söyleyebiliyorsa üretici model aşırı derecede başarısızdır.

Ayırt edici model aslında iki sınıflı bir problem çözer: gelen resim üretilmiş mi, gerçekten çekilmiş mi? Başlangıçta üretici model zayıftır, ayırt edici başarılıdır. Zaman içinde üretici iyileşir ve ayırt edici giderek başarısız hale gelir. Hedeflenen nokta, ayırt edicinin gerçek resimlerle üretilen resimleri birbirinden ayırt edemediği noktadır. İki modelin performansları birbirinin zıttıdır: biri iyileşirken öteki kötüleşir. Bu sayede belli bir sınıftan, belli bir yapıdan yepyeni örnekler üretmek mümkündür.

> **Ders sonrası not:** Hoca 01:20:43'te "üretici model iyileştikçe üretici model kötüleşecektir" dedi; bir önceki cümleden açıkça anlaşıldığı gibi doğrusu "üretici model iyileştikçe ayırt edici model kötüleşecektir"dir.

### 7.4 Metin verileri için

Slayttaki örnekler (ekrandan, 01:21:00):

- Eşanlamlı kelime / deyişler:
  - "Bizim oğlan komşu kızına abayı yakmış" → "Bizim oğlan komşu kızına aşık olmuş"
  - "Bir gün bana yaptıklarının acısını senden çıkaracağım" → "Senden intikamımı elbet alacağım"
- Çeviri:
  - Orijinal örnek → başka bir dildeki karşılığı → yeni örnek
  - "Sinema salonunda kırmızı ayakkabıları olan bir kadın gördüm" → "Sinema salonunda kırmızı ayakkabılı bir kadın gördüm."

Hoca bir cümleyi bambaşka kelimelerle ifade edebilecek hale getirebilen bir yapının çok iyi olacağını söyledi. Geri çeviri (back-translation) ile yeniden ifade (parafraz) üretilir: orijinal örnek önce otomatik olarak başka bir dile çevrilir, sonra tekrar geri çevrilir. Geri çevrilen cümle orijinalden biraz farklı ama anlamca aynı olur. Hoca her zaman bu kadar iyi sonuç elde edilemeyebileceğini, ama yöntemin fena olmadığını belirtti.

### 7.5 Genel amaçlı (sayısal) veriler için: SMOTE

Görüntülerde ve metinlerde etiketi değiştirmeyen dönüşümler kullanılır. Sayısal veriler için ilk karşımıza çıkan yöntem SMOTE'dir. SMOTE yeni örnek üretir, ama amacı **sınıf dengesizliğini** çözmektir: sınıflar arasında dengesizlik varsa az örneği olan sınıfa yeni örnekler ekler.

Slayttaki şekilde (ekrandan, 01:23:20) taralı kareler çoğunluk sınıfı (majority class), siyah noktalar azınlık sınıfı (minority class), kırmızı noktalar sentetik örneklerdir. $x_1$ azınlık sınıfından bir örnektir; $x_2, \dots, x_6$ aynı sınıftan komşularıdır. Yöntem çok basittir: örneğin $x_1$ ile $x_6$ arasında bir nokta seçilir ve oradan yeni veri üretilir; $x_1$ ile $x_5$ arasında bir nokta seçilir ve oradan yeni veri üretilir. Hoca bunun için iki örnek değil, üç beş ya da daha fazla örnek de kullanılabileceğini söyledi.

Yeni örnekler üretildiğinde uzay daha fazla kapsanır. Hoca yeni örneklerin kendilerinin önemli olduğunu, ama belki çok daha önemli olanın bu örneklerin etiketinin ne olacağını iyi belirleyebilmek olduğunu vurguladı.

Aynı slaytta SMOTE'nin bir uzantısı yazılıdır (ekrandan, 01:23:20); hoca bunu ayrıca anlatmadı:

```text
SMOTE-IPF: SMOTE özellikle karar sınırına yakın yerlerde yapay örnek
ürettiği zaman sert sınıf geçişlerini zorlamaktadır. Bunu önlemek için
SMOTE-IPF geliştirilmiştir.
  Önce SMOTE ile örnekler üretilir.
  Sonra hem orijinal hem de yeni üretilmiş örneklerden bazıları elenir.
  Elemede veri kümesi k adet eşit parçaya bölünür.
  Her bir parça kullanılarak bir model eğitilir.
  Ardından tüm modeller tüm veri kümesi üzerinde tahmin yürütür.
  Her veri için k adet tahmin üretilir.
  Bu tahminlerin tutarsız olduğu örnekler veri kümesinden çıkarılır.
  Bu eleme ile karar sınırlarının daha yumuşak modellenebilir hale
  gelmesi amaçlanmaktadır.
```

Hoca bu noktada ders notlarını (Bölüm 4'ü) arada güncellediğini, dönem başındaki halinden farklı olabileceğini, en güncel halinin alınması gerektiğini de söyledi.

## 8. Gürültü ile Düzenlileştirme

### 8.1 Az veri, karmaşık model, yüksek varyans

Hoca yapay veri üretimiyle ilgili bir uygulama gösterdi (ekrandan, 01:27:10). Tek bir giriş boyutu ($x$) ve bir çıkış ($y$) vardır. Gerçek ilişki doğrusaldır.

```text
Gürültü ile Düzenlileştirme (Regularization by adding noise)

Sol grafik (az örnek):
  Gerçek lineer bir model.
  Maviler eğitim örnekleri.
  Kırmızı: 1. dereceden model
  Sarı: 36. dereceden model

Sağ grafik (çok örnek):
  * Eğitim örnek sayısı artınca, gerçeğe göre yüksek dereceden model de
    iyi sonuçlar üretebiliyor, domain içinde.
  * Ama yüksek boyutlu uzaylarda yeterince çok örneğimiz olmaz.
```

Mavi noktalar eğitim örnekleridir ve gerçekte kırmızı doğrusal modelden üretilmişlerdir. Kırmızı, bu verilere oturtulmuş 1. dereceden modeldir. Sarı ise aynı mavi noktalara oturtulmuş 36. dereceden bir modeldir.

**Soru (hoca sordu):** Sol taraftaki grafikteki problem nedir?
**Cevap (öğrenci, hoca onayladı):** Aşırı uyum (overfit) olmuş. Model eğitim örneklerinin üzerine olduğu gibi çökmüştür; test örnekleri alınsa sarı modelin performansı çok kötü olur.

Sağ tarafta eğitim örneklerinin sayısı arttığında 36. dereceden model de alan (domain) içinde daha iyi sonuç verir: alan içindeyken kırmızı ve sarı modeller arasında büyük fark yoktur. Ama verinin olmadığı yerlere, alanın uçlarına doğru gidildikçe çok daha büyük sapmalar görülür.

Örnek sayısının çok olması, modelin varyansını azaltan bir etkendir. Ama her zaman o kadar çok veri olmaz; özellikle çok büyük boyutlu uzaylarda istediğimiz kadar veriye sahip olamayız. Soru şudur: karmaşık bir model kullanıp yine de düşük varyanslı bir sonuç elde edebilir miyiz?

### 8.2 Girişe gürültü ekleyerek yeni örnek üretmek

Bunun cevabı gürültü eklemektir. Slayttaki deney (kod noise_regularization.m, ekrandan, 01:30:00):

```text
Az örnek varken, örnekleri genişletelim
  Gerçek: lineer bir model.
  Mavi: eğitim örnekleri.
  Kırmızı: Gauss gürültülü eğitim örnekleri
  Sarı: 1. dereceden model
  Yeşil: 36. dereceden model (sadece eğitim örnekleri - 20 örnek)
  Mor: 36. dereceden model (gürültü eklenmiş eğitim örnekleri - 120 örnek)

  Yeni örnek üretimi:
    Girişe Gauss gürültü ekle
    Çıkışı aynı bırak

  Test örnekleri üzerindeki hatalar:
    1. dereceden:                         0.1908
    36. dereceden (gürültülü eğitim):     0.2404
    36. dereceden (sadece eğitim):        5.5473e+03

  Kompleks modellerin eğitiminde, örneklere gürültü eklemek /
  örnekleri genişletmek modelin varyansını düşürüyor.
```

Bu grafikte renkler bir önceki slayttan farklıdır: burada sarı 1. dereceden, yeşil 36. dereceden modeldir. Her mavi eğitim örneğinin girişine (x değerine) küçük bir Gauss gürültüsü eklenir, çıkışı (y değeri) hiç değiştirilmez. Her örnekten 5'er yeni örnek üretilir. Grafikteki kırmızı noktaların her mavi noktanın etrafında yatay bir çizgi oluşturması bundandır: x'ler oynar, y'ler aynı kalır. Örnek sayısı:

$$20 + 20 \cdot 5 = 120$$

Önemli olan yeşil ile morun karşılaştırmasıdır. İkisi de 36. dereceden modeldir. Yeşil yalnız 20 eğitim örneğiyle eğitilmiştir ve test hatası $5.5473 \times 10^{3}$'tür. Mor, aynı eğitim örneklerine gürültü eklenerek elde edilen 120 örnekle eğitilmiştir ve test hatası $0.2404$'e düşmüştür; bu, gerçeğe uygun 1. dereceden modelin hatasına ($0.1908$) çok yakındır. Burada yapay bir etiketleme yoktur; yalnız eğitim örneklerine gürültü eklenmiştir ve bu, modelin varyansını büyük ölçüde düşürmüştür.

Hoca bunun tek boyutlu bir örnek olduğunu, daha fazla boyutta ya da başka alanlarda gürültü eklemenin bambaşka biçimlerde tasarlanabileceğini, bunun hayal gücüne kaldığını söyledi.

> **Hocanın vurgusu:** Derin öğrenme mimarilerinde parametre sayısının çok yüksek olması, çok karmaşık yapılar olmaları demektir. Bu, doğrusal bir veriye 36. dereceden bir model oturtmaya çalışmaya benzer: veri azken varyans çok yüksek olur, model ezberler. Bunu engellemenin çok etkili bir yolu gürültü eklemektir.

### 8.3 Çevrimdışı ve çevrim içi gürültü ekleme

- **Çevrimdışı (offline):** Elimdeki her örnek için örneğin 10 tane yapay örnek üretilir, hepsi eğitim kümesine katılır ve eğitim onunla yapılır.
- **Çevrim içi (online):** Her epokta, her örneğin her boyutuna yeniden belli bir gürültü eklenir. Bu, CNN'lerde her epokta resimlere rastgele dönüşümler uygulamaya benzer.

## 9. Temsilde Noktadan Dağılıma

### 9.1 Örneği bir dağılım olarak temsil etmek

Gürültüyü çevrim içi eklediğimizde aslında bir örneği tek bir nokta olarak değil, bir nokta bulutu olarak tanımlamış oluruz: orijinal örnek ortadadır, etrafında da o örneği temsil ettiğini düşündüğümüz noktalar vardır. Tek boyutta bu bir çizgi parçası gibidir; $x$ iki boyutluysa bir yüzey üzerinde gürültü oluşturmak gerekir.

Slayttaki ifade (ekrandan, 01:37:30):

- Bu süreci online olarak yapmak (gürültülü örnekleri tek seferde üretip eğitim kümesine katmak yerine her epoch'ta yeni örnekler üretmek), örnekleri tekil bir nokta değil de bir dağılım olarak temsil etmeye eş.
- Bunu kullanan ve genişleten yöntemler var: VAE (örneklerin saklı uzaydaki temsillerinin hem ortalamalarını hem de varyanslarını öğreniyor).

Böylece bir resim, metin ya da herhangi bir örnek, saklı uzayda (latent space) tek bir nokta olarak değil, ortalaması olan ve her yönde belli standart sapmaları olan bir dağılım olarak temsil edilir. Bütün boyutlardaki varyanslar sıfıra indirildiğinde dağılım zaten bir noktaya çöker. Buradaki amaç, temsili tek bir noktaya çökertmeden devam ettirebilmektir.

### 9.2 Varyasyonel otomatik kodlayıcı (VAE)

Slayttaki şekil, cümlelerin VAE ile temsilidir (ekrandan, 01:37:30):

```text
"RNNs"  -> [Encoding LSTM Cell] -> [Encoding LSTM Cell] <- "work"
                                          |
                                +---------+---------+
                                |                   |
                            [linear] -> mu      [linear] -> sigma
                                |                   |
                                +------> ( z ) <----+
                                           |
<EOS> -> [Decoding LSTM Cell] -> [Decoding LSTM Cell] -> [Decoding LSTM Cell]
             |                        |                        |
           "RNNs"                   "work"                   <EOS>
```

<!-- BELİRSİZ: Hoca 01:36:04'te VAE örneğinin "RSM için yapılmış" olduğunu söylüyor; bu büyük olasılıkla slayttaki LSTM hücrelerine işaret ediyor, ama altyazıdan kesin çıkmıyor. -->

Kodlayıcının ürettiği vektörün ilk kısmı ortalamalar ($\mu$), ikinci kısmı varyanslar ($\sigma$) gibi alınır. Burada saklı uzayın boyutlarının birbiriyle ilişkisiz olduğu varsayılır. Hoca bunu şöyle açıkladı: çok değişkenli bir dağılım üretirken her değişkenin diğerleriyle ilişkisini kovaryans matrisi belirler. Burada kovaryans matrisi köşegendir (diagonal): yalnız köşegende değerler vardır, köşegen dışındaki değerler sıfırdır. Bu, dağılımı oluşturan değişkenler arasında korelasyon olmadığı varsayımıdır. Bu ortalama ve standart sapmaya sahip dağılımdan bir örnek ($z$) üretilir ve kod çözücüyle (decoder) çözülür. Otomatik kodlayıcı (autoencoder) olduğu için çıkışta girdinin aynısının üretilmesi beklenir.

Kodlayıcı (encoder), ham veriyi (resim, ses, metin) saklı uzaydaki bir temsile dönüştürür. Kod çözücü, saklı uzaydaki bir noktayı (ya da dağılımdan alınan örneği) gerçek bir resme, cümleye vb. dönüştürür. VAE'yi VAE yapan, ortadaki bu dağılım tutan kısımdır; kodlayıcı ve kod çözücü yerine LSTM, transformer gibi farklı yapılar kullanılabilir.

**Neden dağılım?** Çünkü dağılımdan istenildiği kadar örnek üretilebilir; gürültüden veri üretilebilir. Eğitimden sonra saklı uzaydan örnekler alınıp kod çözücüye verilerek yeni veriler elde edilir.

**Soru (hoca kendi sordu):** Bunu dağılım kullanmadan, kodlayıcının ürettiği durumu tek bir vektör kabul edip doğrudan kod çözücüye vererek yapamaz mıyız?
**Cevap:** Yapılabilir; o durumda temsil noktasal olur. Ama o zaman yeni örnekler üretmek o kadar kolay olmaz; hem tutarlı hem de yeterince farklılaşmış örnekler bulmak zorlaşabilir.

### 9.3 Temsiller arasında interpolasyon

Temsil dağılım olunca temsiller arasında interpolasyon yapılabilir (ekrandan, 01:40:00):

- **Rakamlar arası:** 1→9 ve 6→9. 1'i temsil eden nokta ile 9'u temsil eden nokta arasına bir doğru çekilip bu doğru üzerinden noktalar alındığında, kod çözücü 1'den başlayıp yavaş yavaş 9'a dönüşen rakamlar üretir.
- **Resimler arası:** $\alpha = 0$'dan $\alpha = 1$'e bir yüzden başka bir yüze yumuşak geçiş; son satırda iki uç da $z \sim \mathcal{N}(0, 1)$'den örneklenmiştir.
- **Cümleler arası:** "the company said it will be n with the exception of the company" cümlesinden "but in a statement that they were n't paid by the end of the past few weeks" cümlesine aradaki noktalardan üretilen cümleler.

Hoca bunu tahtada iki boyutlu bir saklı uzayla gösterdi: iki nokta arasına bir çizgi çekip çizgi üzerinden örnekler alınır, bu örnekler kod çözücüye verilir. Başlangıç noktası ilk resme, bitiş noktası son resme, aradaki noktalar da aradaki resimlere karşılık gelir. Bu yöntem interpolasyon için kullanılabildiği gibi ekstrapolasyon için de kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** VAE'de $z$, büyük olasılıkla "yeniden parametrelendirme hilesi" (reparameterization trick) ile $z = \mu + \sigma \odot \epsilon$, $\epsilon \sim \mathcal{N}(0, I)$ biçiminde örneklenir; böylece örnekleme adımından geriye yayılım yapılabilir. Kayıp fonksiyonu, yeniden üretim hatası ile öğrenilen dağılımın standart normal dağılıma olan KL ıraksamasının toplamıdır. KL terimi saklı uzayın düzgün ve sürekli olmasını sağlar; interpolasyonun anlamlı sonuç vermesi bu sayededir.

## 10. Makine Öğrenmesi Algoritmalarını Kandırmak

Hoca kandırma konusunun önemli olduğunu söyledi: kararlarımızı giderek daha çok makinelere bırakırsak ve bu makineleri birileri kandırabilirse bu iyi sonuçlara yol açmaz. Kararların makinelere bağlı olduğu süreçlere adım adım geçildikçe ve bu işler ticarileştikçe, makineleri kandırmaya çalışan sistemler de ortaya çıkmaya başlıyor. Bu yalnız derin öğrenme mimarilerine özgü değildir; çok basit doğrusal bir modeli bile kandırabilirsiniz. Ama doğrusal modeli kandırmak, varyansı yüksek olan derin öğrenme mimarilerini kandırmaya göre daha zordur.

Slayttaki maddeler (ekrandan, 01:45:45):

- Kararlar makinelere bırakıldığı anda onları kandırma çalışmaları da başlar.
  - İstenmeyen e-postalar
- Derin öğrenme mimarilerinin başarılarının ardından ...
- En solda orijinal papağan. Inception v3'e göre %97 olasılıkla "papağan". Bu resmin üzerine özel olarak hazırlanmış sağdaki gürültü eklenerek ortadaki resim oluşturulmuştur. Aynı Inception mimarisine göre %99 olasılıkla "kitaplık".
- Daha önce gördüğümüz GAN'lar bu tür ataklara karşı dayanıklı mimariler üretmek için geliştirilmiştir.

Ortadaki resim insan gözüne orijinalden pek farklı görünmez. Hoca, modelin buna "kitaplık" diyebilmesinin bu sistemlerin, en azından bildiğimiz kadarıyla, bizim gibi çalışmadığını gösterdiğini söyledi. Modelin kitaplık demesinin sebebi, resmin özel olarak üzerinde çalışılmış olmasıdır.

> **Ders sonrası not:** Hoca konuşurken modelin değiştirilmiş resme "yüzde doksan" olasılıkla kitaplık dediğini söyledi; slayttaki değer %99'dur. Ayrıca slayttaki "GAN'lar bu tür ataklara karşı dayanıklı mimariler üretmek için geliştirilmiştir" ifadesi büyük olasılıkla tam doğru değildir: GAN'lar ilk olarak (Goodfellow ve ark. 2014) gerçekçi örnek üreten üretici modeller olarak önerilmiştir; çekişmeli örneklere karşı dayanıklılık için daha çok çekişmeli eğitim (adversarial training) kullanılır, GAN tabanlı savunmalar sonradan geliştirilmiştir.

Bu atakları engellemek için çalışılıyor. Ama hocaya göre, nasıl istenmeyen e-posta üretimi hiçbir zaman bitmediyse, makinelerin kararlarını etkilemeye çalışan insanlar ya da başka makineler de olacaktır; ileride görünen süreç buna benziyor. Slaytta konuyla ilgili birkaç dış kaynak vardı.

## 11. Planlı Öğrenme (Curriculum Learning)

İnsanların eğitiminde belli bir sıra takip edilir: önce şunlar, sonra şunlar öğretilir. Bir dersin içinde bile böyledir. Fikir şudur: makine öğrenmesi algoritmalarına da örnekleri anlamlı bir sırayla (örneğin kolaydan zora) versek eğitim iyileşir mi?

Bununla ilgili birkaç yaklaşım vardır. Bazı problemlerin daha kolay, bazılarının daha zor olduğu kabul edilir ve önce kolayların çözülüp sonra zorlara geçilmesinin daha iyi olduğu sonuçları çıkar. Ama insandaki kolaylık ve zorluk ile makinedeki kolaylık ve zorluk birbiriyle çok ilişkili olmayabilir.

Slaytta örneklerin zorluklarının topluluk modellerle (ensemble) belirlenmesi gösterilir; bu topluluklar doğrusal sınıflandırıcılar ya da daha karmaşık sınıflandırıcılar için denenmiştir. Araştırma soruları şunlardır: başta zorları mı vermeli, kolayları mı? Zorluk ve kolaylık neye göre belirlenmeli?

Slayttaki "Sürpriz" başlıklı tablo (ekrandan, 01:50:00; Mermer ve ark. 2017, Scalable Curriculum Learning for Artificial Neural Networks) yöntemleri ikili olarak karşılaştırır. Hücreler X(win)/tie/Y(win) biçimindedir; X sütundaki, Y satırdaki yöntemdir.

| Y \ X | Classical | Classical (2n) | Curriculum (n) | Curriculum (2n) | Anti-curriculum (n) | Anti-curriculum (2n) |
|---|---|---|---|---|---|---|
| Classical | - | 1/33/2 | 5/30/1 | 10/26/0 | 4/32/0 | 14/22/0 |
| Classical (2n) | 2/33/1 | - | 6/29/1 | 11/25/0 | 6/30/0 | 14/22/0 |
| Curriculum (n) | 1/30/5 | 1/29/6 | - | 8/28/0 | 4/31/1 | 11/25/0 |
| Curriculum (2n) | 0/26/10 | 0/25/11 | 0/28/8 | - | 0/32/4 | 2/33/1 |
| Anti-curriculum (n) | 0/32/4 | 0/30/6 | 1/31/4 | 4/32/0 | - | 4/32/0 |
| Anti-curriculum (2n) | 0/22/14 | 0/22/14 | 0/25/11 | 1/33/2 | 0/32/4 | - |

Hoca tablonun ayrıntısına girmedi. Literatürde bir "curriculum" bir de "anti-curriculum" olmasının sebebinin, bazı çalışmaların önce kolayları, bazılarının önce zorları vermenin daha iyi olduğunu söylemesi olduğunu belirtti. Kendilerinin de bununla ilgili farklı şeyler yaptıklarını, ayrıntısının ilgilenenlerle daha sonra konuşulabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Tablonun her hücresindeki üç sayının toplamı 36'dır ve tablo simetriktir (örneğin Classical satırı / Curriculum (n) sütunu 5/30/1, Curriculum (n) satırı / Classical sütunu 1/30/5). Her satırda en sağdaki Anti-curriculum (2n) sütunu en çok galibiyeti alır (örneğin Classical'a karşı 14 galibiyet, 22 beraberlik, 0 yenilgi). Bu, slayttaki "sürpriz"in büyük olasılıkla zordan kolaya sıralamanın, sezgiye aykırı biçimde, en iyi sonucu vermesi olduğunu düşündürür.

## 12. Hayat Boyu Öğrenme

Slayttaki maddeler (ekrandan, 01:50:00):

- Öğrenme sürecinin bitmediği
- Tüm eğitim verilerinin elde olmadığı / zaman içinde erişildiği
- Test örneklerinin sadece eğitim örneklerinin sınıflarından gelmediği (Open World)
- Önceki öğrenilenler nelerin / nasıl öğrenileceğine etken
- Endüstride daha yaygın

Hoca bunu endüstriden bir örnekle anlattı. Firmanız hakkındaki kamuoyu algısını öğrenmek için bir duygu analizi modeli kurdunuz. Model çalışmaya başladı ve size her gün rapor veriyor: "Bugün müşterilerinizin sizin hakkınızdaki algısı %80 pozitif; kırılımlarında da şunlar var." Bu sistem, kurulduğu andan itibaren eskimeye başlar. Dil ve iş dünyası sabit değildir, durmadan değişir: yeni ihtiyaçlar ortaya çıkar, yeni bir dil kullanılmaya başlanır, jargon değişir, reklamlarınızda kullandığınız kelimeler kullanıcılarınızın kelimelerini değiştirir. Dolayısıyla "İşi teslim ettik, beş yıl boyunca bu sistemle kamuoyu algısını kontrol ederiz" denemez. Süreçte bir insanın döngüde olması (human in the loop) da faydalıdır. Hayat boyu öğrenme akademide değil, özellikle endüstride ve gerçek dünyada çok daha yaygındır.

## 13. Kendi Kendine Öğrenme (Self-Supervised Learning)

Denetimli öğrenmede bir resim için "bu resimde kedi var", "bu resimde biri kayak yapıyor" denir, resimlere açıklama (caption) yazılır ya da bir metindeki kişi adları işaretlenir. Bunların hepsi insan etiketlemesi gerektirir.

Hocaya göre derin öğrenmenin şu anda en sağlam faydalandığı nokta kendi kendine öğrenmedir, çünkü kullanıcıların etiketleme yapmasına gerek yoktur. Slayttaki maddeler (ekrandan, 01:53:30):

- Input-output ikililerinin insan etiketlemesi gerektirmeden hazırlanması
- Bu sayede çok büyük miktarda eğitim örneği
- Tahminler:
  - Bir sonraki kelime
  - Maskelenmiş kelime / resim parçası
  - 2 cümle ardışık mı
  - Bu cümlede değiştirilmiş kelime var mı?
  - Bu kelimelerin doğru sıralaması nedir?
- Büyük derlemler üzerinde bu gibi görevlerle eğitilen pre-trained / ön-eğitimli modeller, yeni bir eşiğin aşılmasını sağladı.

Hoca görevleri modellerle eşleştirdi: bir sonraki kelimeyi tahmin etmek GPT'de, maskelenmiş kelimeyi tahmin etmek ve iki cümlenin ardışık olup olmadığını bulmak BERT'te, cümlede değiştirilmiş kelime olup olmadığını bulmak ELECTRA'da yapılır. Kelimelerin doğru sıralamasını bulma görevinin "herhalde T5'te" olduğunu söyledi.

Örneğin bir sonraki kelimeyi tahmin etmek için veri kümesi hazırlarken insan etiketlemesine ihtiyaç yoktur; elinizde bir derlem olması yeter. Girdi derlemdeki metindir, çıktı zaten bir sonraki kelimedir. Maskelenmiş kelimede de kapattığınız kelimenin ne olduğunu derlemden bilirsiniz; sistem bir tahmin yapar ve tahmini iyileştirmeye çalışırsınız. Bu görevlerin hepsinin ortak özelliği insan eliyle etiketleme gerektirmemesidir; insanlara sormadan etiket üretebildiğiniz için süreç çok ölçeklenebilir hale gelir ve çok büyük miktarda veriyle çalışılabilir. Bu görevlerle eğitilen önceden eğitilmiş modeller yalnız NLP alanında değil, bütün yapay zeka alanında bir eşiği aştı.

## 14. Karşıtsal Öğrenme (Contrastive Learning)

Karşıtsal öğrenmede "şu girdiye karşı şu çıktı olsun" gibi bir yapı yoktur. Buradaki yapı şudur: "Şu iki girdi birbirine yakın olsun, şu iki girdi birbirine uzak olsun." Bu da bir tür kendi kendine öğrenmedir: sınıf bulmak yerine örnek ikililerinin temsillerini birbirine yakın ya da uzak yapmak öğrenilir. Örneğin aynı resmin farklı parçalarının temsillerinin birbirine yakın, farklı resimlerin parçalarının temsillerinin birbirinden uzak olması istenebilir. Temsillerinin yakın olması istenen örneklere **pozitif örnekler**, uzak olması gereken örneklere **negatif örnekler** denir.

> **Hocanın vurgusu:** Karşıtsal öğrenmenin ilk örneklerinden biri word2vec makalesidir. Makalede "contrastive learning" ifadesi geçmese bile tamamen karşıtsal bir öğrenmedir: şunlar birbirine yakın, şunlar birbirine uzak olsun. Oradaki negatif örneklemeyi (negative sampling) hatırlayın; tamamen bunun üzerine kuruludur.

Slayttaki şekil (ekrandan, 02:00:00) iki parçadan oluşur. Solda bir köpek resmi ve bir sandalye resmi vardır. Her resimden veri zenginleştirmeyle (kırpma, filtre vb.) iki farklı görünüm üretilir. Bu görünümler CNN'lerden ve ardından MLP'lerden geçirilir. Aynı resmin görünümlerinin temsilleri birbirine çekilir (attract), farklı resimlerin görünümlerinin temsilleri birbirinden itilir (repel).

Sağdaki çerçeve şöyledir:

```text
                 Maximize agreement
        z_i  <------------------------>  z_j
         ^                                ^
       g(.)                             g(.)
         |                                |
        h_i  <---- Representation ---->  h_j
         ^                                ^
       f(.)                             f(.)
         |                                |
       x~_i                             x~_j
           \                            /
         t ~ T                     t' ~ T
              \                      /
                         x
```

Slayttaki açıklama (Figure 2): aynı dönüşüm ailesinden iki ayrı veri zenginleştirme operatörü örneklenir ($t \sim \mathcal{T}$ ve $t' \sim \mathcal{T}$) ve her veri örneğine uygulanarak birbiriyle ilişkili iki görünüm elde edilir. Bir temel kodlayıcı ağ $f(\cdot)$ ve bir izdüşüm başlığı (projection head) $g(\cdot)$, karşıtsal bir kayıpla uyumu en büyüklemek üzere eğitilir. Eğitim tamamlandıktan sonra izdüşüm başlığı $g(\cdot)$ atılır; kodlayıcı $f(\cdot)$ ve temsil $h$ alt görevler (downstream tasks) için kullanılır.

Hoca bunu şöyle anlattı: büyük $\mathcal{T}$ veri zenginleştirme tiplerinin kümesidir. Buradan bir zenginleştirme seçilip $x$ üzerine uygulanır, başka bir zenginleştirme seçilip yine $x$ üzerine uygulanır; bunlar kırpma, kırpma artı başka bir şey vb. olabilir. Elde edilen görünümler CNN'den geçirilip temsilleri ($h_i$, $h_j$) elde edilir. Bunun üstüne bir MLP (basit bir çok katmanlı algılayıcı) eklenir. Hoca MLP kısmının teorik olarak şart olmadığını, ama uygulamada daha iyi sonuç verdiğinin görüldüğünü söyledi. MLP, temsillere bir dönüşüm daha uygulayıp onları $z$ uzayına taşır; yakınlık-uzaklık bilgisi $h$ uzayında değil, bu $z$ uzayında kullanılarak eğitim yapılır.

Bu işlem bittiğinde elde bir omurga (backbone), yani önceden eğitilmiş bir model olur. Bu model daha sonra alt görevler ya da kullanıcıya yönelik görevler için rahatlıkla kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** Slayttaki çerçeve, bağlantısı verilen makaleye (arXiv 2002.05709) bakılırsa büyük olasılıkla SimCLR'dir. SimCLR'de bir mini yığındaki (batch) her örneğin iki görünümü birbirinin pozitifi, aynı yığındaki diğer bütün görünümler ise negatif örnekler olarak kullanılır; kayıp olarak sıcaklık parametreli, kosinüs benzerliğine dayalı bir karşıtsal kayıp (NT-Xent) kullanılır.

## 15. Bağlam İçi Öğrenme (In-Context Learning)

Hoca bunu "gizemli" bir konu olarak tanıttı; Bölüm 4'ün son slaytıdır. Bağlam içi öğrenme, büyük dil modellerinin belli bir kabiliyeti olarak ortaya konmuştur. Slayttaki maddeler (ekrandan, 02:00:40):

```text
Bağlam içi öğrenme (In context learning)
  Büyük dil modellerinde klasik ML yaklaşımı yerine bir alternatif.
  Model seçimi / eğitimi / hiperparametre opt. yok.
  Prompt'ta:
    input1 – output1
    input2 – output2
    input3 – output3
    input4 – tahmin et
```

Model seçimi, eğitimi, hiperparametre optimizasyonu yoktur; yalnız istem (prompt) vardır. İsteme bir girdi-çıktı ikilisi, sonra başka bir ikili, sonra başka bir ikili verilir; bunların aynı biçimde yazılması şart değildir. En sonda yalnız girdi verilir ve model bunun çıktısını tahmin eder. Örneğin bir tweet verip "olumlu", başka bir tweet verip "olumsuz", başka bir tweet verip "olumsuz" dersiniz; son olarak bir tweet verip sınıfını sorarsınız. Ortada eğitim yoktur; yalnız çıkarım (inference) zamanında olur.

Hocaya göre bu her durumda mükemmel çalışmaz, ama bazı durumlarda bile çalışıyor olması oldukça ilginçtir ve herkesin merak ettiği bir konudur. Bu özellik ancak çok büyük verilerle eğitilmiş çok büyük mimarilerde görülür; basit mimarilerde henüz böyle bir davranış gözlemlenmemiştir, ama gözlemlenmesi için çalışmalar yapılabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:16:28): Örnekleri tek tek etiketlemek yerine örnek toplulukları için kural vermenin (zayıf denetim) avantajı ve dezavantajı nedir?

> **Cevap (derste verildi):** Avantajı, az miktarda bilgi vererek çok sayıda örneği hızla etiketlemektir; "şu kelimelerden biri geçenin sınıfı şudur" gibi bir kural verinin büyük bir kısmını etiketleyebilir. Dezavantajı, kuralın her zaman doğru olmamasıdır; örneklerin yalnız bir kısmı için doğrudur. Bu yüzden bir örneğe birden fazla, bazen çelişen zayıf etiket gelir ve bunları güçlü etiketlere çeviren ayrı bir model kurulur.

**Soru 2** (derste sözlü, 00:31:52): RLHF'nin ikinci adımında tek bir girdiye karşı nasıl birden fazla çıktı üretilebilir?

> **Cevap (derste verildi):** Üretici dil modellerinde dropout, rastgelelik ya da sıcaklık (temperature) gibi üretim sürecini farklılaştıran mekanizmalar vardır. Bu yüzden aynı isteğe karşı farklı çıktılar üretilir ve insan bunları sıralar.

**Soru 3** (derste sözlü, 00:39:48): İnterpolasyon ile ekstrapolasyon arasındaki fark nedir?

> **Cevap (derste verildi):** İnterpolasyon, örneklerin bulunduğu bölgenin içinde tahmin yapmaktır. Ekstrapolasyon, verinin olmadığı bölgelerde (aralığın öncesinde ya da sonrasında) davranışı tahmin etmektir. Chollet'ye göre veri yoğunsa interpolasyon bir örüntü tanıma işidir; ekstrapolasyon için zeka gerekir.

**Soru 4** (derste sözlü, 01:17:45): GAN'da ayırt edici modelin çok başarılı olması neden üretici modelin çok başarısız olduğu anlamına gelir?

> **Cevap (derste verildi):** Ayırt edici model gerçek resimlerle üretilen resimleri çok kolay ayırt edebiliyorsa, ikisi arasında bariz bir fark var demektir; yani üretici gerçekçi örnekler üretemiyordur. İki modelin performansı zıttır: üretici iyileştikçe ayırt edici kötüleşir. Eğitimde hedef, ayırt edicinin gerçek ve üretilmiş örnekleri ayıramadığı noktadır. (Derste bir öğrencinin önerdiği "aşırı uyum" cevabı hoca tarafından kabul edilmedi, çünkü burada bir test kümesi söz konusu değildir.)

**Soru 5** (ekrandan, 01:27:10; derste sözlü, 01:27:15): Gerçek ilişkinin doğrusal olduğu az sayıda örneğe 36. dereceden bir polinom oturtulmuştur. Grafikteki problem nedir ve nasıl giderilebilir?

> **Cevap (derste verildi):** Model aşırı uyum (overfit) yapmıştır; eğitim örneklerinin üzerine çöker ve test örneklerinde çok kötü sonuç verir. Çözümlerden biri daha çok örnek toplamaktır, ama yüksek boyutlu uzaylarda bu her zaman mümkün değildir. Diğer çözüm, girişe Gauss gürültüsü ekleyip çıkışı aynı bırakarak örnekleri genişletmektir. Slayttaki deneyde (ekrandan, 01:30:00) 20 örneğin her birinden 5'er gürültülü örnek üretilerek $20 + 20 \cdot 5 = 120$ örnek elde edilmiş, 36. dereceden modelin test hatası $5.5473 \times 10^{3}$'ten $0.2404$'e düşmüştür; 1. dereceden modelin hatası $0.1908$'dir.

**Soru 6** (derste sözlü, 01:43:19): VAE'de dağılım yerine kodlayıcının çıktısını tek bir vektör olarak alıp doğrudan kod çözücüye versek ne olur?

> **Cevap (derste verildi):** Bu da mümkündür ve çalışır; ama temsil noktasal olur. Bu durumda yeni örnekler üretmek kolay olmaz, hem tutarlı hem de yeterince farklılaşmış örnekler bulmak zorlaşabilir.

**Soru 7** (ekrandan, 02:03:30): Ödev 2, "Sıfır Çekimli Öğrenmede Sufle Analizi (Prompt Analysis in Zero Shot Learning)". Ödevin akademik metni şöyledir:

```text
Sıfır çekimli öğrenmeyi en az 2 sinirsel dil modeli (biri BERT tabanlı)
üzerinde uygulayınız. Biri haber sınıflandırma, diğeri duygudurum analizi
toplamda en az 2 veri kümesi kullanınız.

Sıfır çekimli öğrenmede her bir sınıfı temsil eden en az 5 farklı
prompt'u karşılaştırınız.

Örneklerin sınıfını ders notlarındaki (ML v2, 35. slayt) Yöntem 1 ile
tahmin ediniz. Örneğin temsili, sınıfların prompt'larının temsillerinden
hangisine yakınsa o sınıftandır.

Ödevin amacı sıfır çekimli öğrenmede prompt'ların etkisini görmek ve iyi
prompt bulma için yöntem(ler) geliştirmektir.

Her bir veri kümesinde her bir sınıf için en az 5'er prompt belirleyiniz.
Prompt bir sınıfın ismi olabileceği gibi, bir sınıfta çok diğerlerinde az
geçen kelimeleri içerebilir. Başlarda denediğiniz prompt'ların
başarılarına bakarak daha iyi prompt'lar öneriniz. İyi prompt bulma
sürecini nasıl gerçekleştirdiğinizi anlatınız.

Örnek prompt'lar:
  X sınıfı için:
    Bu metnin konusu X
    Bu haber X hakkında
    Bugün X duygular içindeyim

Sınıfın ismi örneğin "ekonomi" ise X'in illa "ekonomi" olması gerekmez.
Mesela sınıfı daha iyi ifade eden enflasyon, faiz vb. olabilir.
Sınıfın ismi örneğin "negatif" ise X'in illa "negatif" olması gerekmez.
Mesela sınıfı daha iyi ifade eden üzüntülü, üzgün vb. olabilir.
X'in tek bir kelimeden oluşması da gerekmez.

Burada eğitim test kümesi ayrımı olmadığından başarıyı tüm veri kümesi
üzerinde ölçünüz.
```

> **Derste verilen açıklamalar:** Veri kümesi İngilizce olabilir. Modellerden biri BERT tabanlı olmalıdır (BERT yerine RoBERTa gibi BERT tabanlı bir model de olur); diğeri word2vec gibi başka bir sinirsel dil modeli olabilir. Programlama dili serbesttir; hoca bu tür çalışmalar için en geniş kütüphanelerin Python'da olduğunu belirtti. Başarı, veri kümesinin bir alt kümesinde değil tamamında ölçülür: örneğin 5000 örnekli bir haber veri kümesinde bir prompt kümesiyle %80, daha iyi prompt'larla %85, daha da iyileriyle %90 başarıya çıkılabilir. Prompt'ları iyileştirmek için neler yapılabileceğini araştırmak, sıfır çekimli öğrenmenin özüdür.

> **Çözüm (derste verilmedi):** Bu bir uygulama ödevidir; tek bir doğru cevabı yoktur. Yöntem 1'in adımları şunlardır: her sınıf için prompt cümlelerinin temsilleri seçilen modelle (örneğin BERT tabanlı bir cümle temsili ve word2vec ortalaması) hesaplanır; her metnin temsili aynı modelle hesaplanır; metin, kosinüs benzerliği en yüksek prompt temsilinin sınıfına atanır; tahminler gerçek etiketlerle karşılaştırılarak doğruluk (ya da F1) hesaplanır ve farklı prompt kümeleri bu ölçüyle karşılaştırılır.

## Dersin Toparlaması

Bu derste Bölüm 4 ("makine öğrenmesi versiyon 2") tamamlandı. İnsan-makine işbirliğiyle başlandı: insan yavaş ama doğru, makine hızlı ama daha az doğrudur. Video etiketleme, makine çevirisinin insanca düzeltilmesi ve kurallarla zayıf etiket üretme (zayıf denetim) bu işbirliğinin örnekleridir. En güncel ve en etkili örnek RLHF'dir: InstructGPT'de insanın çıktı sıralamalarından bir ödül modeli eğitilir ve bu model, insanın yerine geçerek pekiştirmeli öğrenmeyi ölçeklenebilir hale getirir. Ardından az sayıda örnekle eğitim ele alındı: interpolasyon ile ekstrapolasyonun farkı, tek çekimli ve sıfır çekimli öğrenme, Google'ın ortak temsil uzayına dayanan sıfır çekimli çevirisi ve ödevle doğrudan ilgili iki sıfır çekimli sınıflandırma yöntemi (temsil uzayında en yakın sınıf kalıbı ve NLI ile eğitilmiş modelde en yüksek gerektirme olasılığı).

Dersin ikinci yarısında veri zenginleştirme (görüntüler, metinler, sayısal veriler için SMOTE ve GAN'lar), girişe gürültü ekleyerek karmaşık modellerin varyansını düşürme, bu fikrin örneği bir dağılım olarak temsil eden VAE'ye uzanması ve saklı uzayda interpolasyon anlatıldı. Son olarak makine öğrenmesi modellerini kandırma (adversarial attacks), planlı öğrenme (kolaydan zora mı, zordan kolaya mı), hayat boyu öğrenme, kendi kendine öğrenme, word2vec'i de kapsayan karşıtsal öğrenme ve büyük dil modellerinde bağlam içi öğrenme kısaca tanıtıldı. Bu konuların ortak noktası, etiketli veri azken ya da hiç yokken öğrenmeyi mümkün kılmaktır; ödevde sıfır çekimli sınıflandırmada prompt seçiminin etkisi deneysel olarak incelenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
