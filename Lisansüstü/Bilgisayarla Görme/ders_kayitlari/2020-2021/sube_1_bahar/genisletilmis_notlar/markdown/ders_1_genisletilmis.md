# Ders 1 Genişletilmiş Notu: Bilgisayarla Görmeye Giriş, Dijital Görüntü ve Uygulama Alanları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Konu Akışı ve Çalışma Ortamı
- 2. Bilgisayarla Görme Sisteminin Bileşenleri
- 3. Dijital Görüntü: Örnekleme ve Nicemleme
- 4. Görüntü İşlemenin Adımları
- 5. Parlaklık Dönüşümü: Negatif Görüntü ve Gamma Düzeltmesi
- 6. Kontrast ve Histogram
- 7. Bilgisayarla Görmenin Uygulama Alanları
- 8. Nesne Tanımanın Tarihçesi: SIFT, HOG, Pascal VOC ve ImageNet
- 9. Görüntü Altyazılama ve Evrişimli Sinir Ağları
- 10. Derste Paylaşılan Uygulama Örnekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Konu Akışı ve Çalışma Ortamı

Dersin ilk bölümünde hoca dönem boyunca işlenecek konuları ders tanıtım belgesindeki haftalık plan üzerinden anlattı (ekrandan, 00:50:00). Dersin yaklaşık yarısı klasik görüntü işleme ve nesne tanıma yöntemlerine, yarısı derin öğrenme yöntemlerine ayrılmıştır. Uygulamaların hepsi Python ile yapılır.

Haftalık plandaki konular şöyledir:

- Bilgisayarla görmeye giriş: bilgisayarla görme nedir, hangi alanlara çözüm sunar.
- Python ve NumPy'a hızlı bir giriş; temel değişken yapıları ve NumPy'ın sağladığı kolaylıklar. Görüntü oluşumu ve görüntü dosyası biçimleri; Python ile bu dosyaların açılması, piksellere erişim ve işlenmesi.
- Görüntüyü anlama, parlaklık dönüşümü (intensity transformation), uzamsal filtreleme ve gürültü azaltma. Aydınlatma problemi olan ya da düşük/yüksek kontrastlı görüntüler parlaklık dönüşümüyle iyileştirilir; gürültü azaltmada ortalama filtresinin yanında medyan filtresi gibi filtreler kullanılır.
- Uzamsal filtrelerle keskinleştirme (image sharpening). Filtre ile görüntü arasındaki konvolüsyon işlemi, görüntünün birinci türevi (gradyan) ve ikinci türevi (Laplace operatörü); bu türevler pikseller arasında hesaplanır.
- Global eşikleme, bağlantılı bileşen etiketleme, matematiksel morfoloji, Hough dönüşümü (doğru ve çember bulma) ve integro-diferansiyel operatör.
- 2B dönüşümler, sınır takibi ve bölge özellikleri.
- İlgi noktası bulma: Harris köşe dedektörü, HOG öznitelikleri.
- Evrişimli sinir ağları (CNN), derin sinir ağları, max pooling.
- Aktivasyon fonksiyonları, tam bağlantılı katmanlar ve softmax.
- Derin öğrenmede optimizasyon, düzenlileştirme, dropout, veri artırma ve transfer öğrenme.

Bazı konular için hoca kısa açıklamalar yaptı:

- **Eşikleme (thresholding):** Gri seviyeli ya da renkli bir görüntü ikili (binary) görüntüye çevrilir. Bir kırılma noktası (eşik) seçilir; bu değerin altında kalan parlaklıklar 0'a, üstündekiler 1'e çekilir. Böylece yalnız siyah ve beyazdan oluşan bir görüntü elde edilir. Bu işlemde en önemli konu eşik değerinin nasıl seçileceğidir.
- **Bağlantılı bileşen etiketleme:** Birbiriyle bağlantılı pikselleri aynı etiketle işaretleme işlemidir ve görüntü işlemenin temel işlemlerindendir; morfolojik işlemlerde de kullanılır.
- **Hough dönüşümü:** Görüntüde doğru, çember gibi belirli biçimdeki şekilleri bulmak için kullanılır.
- **Integro-diferansiyel operatör:** Özellikle iris tanımada kullanılır. Göz bebeği ve iris bölgesi bir çemberle bulunabilir; bu operatör çember bulmanın özel bir biçimidir. İris gözün beyazından ayrılıp çemberle işaretlenir, sonra bu bilgi biyometrik tanımada kullanılır.

### 1.1 Öznitelik mühendisliğinden CNN'e

Klasik nesne tanımada bir öznitelik mühendisliği (feature engineering) aşaması vardı: nesneyi tanımak için kullanılacak öznitelikler özel algoritmalarla, yani insan tasarımıyla çıkarılır, sonra tanıma aşamasında bu öznitelikler kullanılırdı. Hoca eskiden bu yöntemlerin her birini bir haftada anlattığını, artık iki üç yöntemi bir haftada hızlıca geçeceğini söyledi. Bunun nedeni, nesne bulma ve tanıma uygulamalarında öznitelik mühendisliğini artık bizim yapmamızın gerekmemesidir.

Derin öğrenmede görüntüden öznitelik çıkarma işini evrişimli sinir ağları (CNN) yapar. Harris köşeleri ya da HOG gibi öznitelikleri üretmek gerekmez; sistem art arda onlarca konvolüsyon işlemiyle öznitelikleri otomatik üretir ve insan gözünün ya da aklının düşünemeyeceği kadar karmaşık öznitelikleri bile bulabilir.

> **Hocanın vurgusu:** CNN'lerin nesne bulmada bu kadar başarılı olmasının bir nedeni de, önceden ayrıca yapılan öznitelik çıkarma işinin artık sistemin kendi içinde yapılmasıdır.

Derin öğrenme bölümünde max pooling, aktivasyon fonksiyonlarının alternatifleri, tam bağlantılı katman ve softmax katmanının girişi, çıkışı ve nasıl düzenlenmesi gerektiği, kayıp (loss) fonksiyonunu en hızlı en aza indiren optimizasyon algoritmaları, kayıp fonksiyonundaki düzenlileştirme teriminin amacı, dropout katmanı, veri artırma ve transfer öğrenme ele alınacaktır. Veri artırma, özellikle veri sınırlıyken veriyi çeşitlendirip sistemi daha gürbüz (robust) hale getirmek için kullanılır.

### 1.2 Çalışma ortamı

Hoca derste Jupyter Notebook kullanır ve öğrencilere de bu platformu önerdi. Anaconda kurulması tavsiye edildi; Anaconda'nın Python dağıtımı altında TensorFlow ve Keras kütüphaneleri vardır ve içe aktarılarak (import) kullanılabilir.

**Soru:** Derste hangi derin öğrenme kütüphanesi kullanılacak, bir kısıtlama var mı? **Cevap:** Alternatiflerin hepsi görülecek. Hoca TensorFlow kullanıyor; pratikte Keras kullanılacak. Keras bir sarmalayıcıdır (wrapper) ve arka planda TensorFlow ya da Theano kullanır. Başka çerçeveler de denenebilir.

> **Ek bilgi (derste anlatılmadı):** Keras eskiden TensorFlow, Theano ve CNTK gibi birden fazla arka uçla çalışabilen bağımsız bir kütüphaneydi; TensorFlow 2 ile birlikte `tf.keras` olarak TensorFlow'un parçası haline geldi. Theano'nun geliştirilmesi büyük olasılıkla 2017'de durduruldu.

## 2. Bilgisayarla Görme Sisteminin Bileşenleri

Bilgisayarda bir dijital görüntü ekranda resim olarak görünse de aslında parlaklık değerleri olarak tutulur. Gri seviyeli görüntüde parlaklık 0 ile 255 arasındadır: 0 siyahı, 255 beyazı gösterir, aradaki değerler gri tonlarıdır.

Bir görüntü oluşturmak için şunlar gerekir (ekrandan, 01:20:00):

- **Aydınlatma (lighting):** Sahnenin görüntülenebilmesi için önce aydınlatılması gerekir.
- **Sahne (scene):** Görüntülenen nesneler.
- **Kamera:** Aydınlatılmış sahnenin görüntüsünü alır.
- **Bilgisayar:** Görüntüyü alır ve sahneyi yorumlar (scene interpretation).

## 3. Dijital Görüntü: Örnekleme ve Nicemleme

Oluşturulan görüntü için iki temel kavram vardır: örnekleme (sampling) ve nicemleme (quantization). Bir işaretin sayısal hale getirilmesi örneklemeyle yapılır.

### 3.1 Örnekleme ve çözünürlük

İki boyutlu bir düzlemde görüntünün örneklenmesi, bilgisayar tarafında çözünürlük (rezolüsyon) demektir: görüntünün kaç satır ve kaç sütundan oluşan bir matrisle örneklenip tutulacağı. Çözünürlük ne kadar yüksekse görüntü o kadar hassas ve ayrıntılıdır.

### 3.2 Nicemleme ve bit derinliği

Nicemleme, her pikselin kaç bitle ifade edildiğidir. Bir piksel 8 bitle ifade ediliyorsa parlaklık $2^8 = 256$ farklı seviyeyle gösterilir.

Tıbbi görüntülerde kullanılan DICOM dosyalarında (tomografi, MR gibi) bir piksel 8 yerine 16 bit gri seviyeyle tutulabilir; bu da veriyi daha yüksek hassasiyetle saklamayı sağlar ($2^{16} = 65536$ seviye). Renkli görüntüde bir piksel 3 ya da 4 bayt ile ifade edilebilir.

> **Ders sonrası not:** Hoca bitmap dosyalarında bir piksel için 4 bayt kullanıldığını söyledi. Büyük olasılıkla BMP biçiminde hem 24 bit (3 bayt) hem 32 bit (4 bayt) piksel biçimleri vardır; 4 bayt her BMP için geçerli değildir.

### 3.3 Dijital görüntünün matris gösterimi

Slayttaki tanım şöyledir (ekrandan, 01:25:00):

- Genellikle dijital (ayrık) görüntülerle çalışırız:
  - 2B uzay düzenli bir ızgara üzerinde örneklenir (sample).
  - Her örnek nicemlenir, yani en yakın tam sayıya yuvarlanır (quantize).
- Örnekler birbirinden $\Delta$ uzaklıktaysa:

$$f[i,j] = \text{Quantize}\{ f(i\Delta,\ j\Delta) \}$$

- Görüntü artık tam sayı değerlerden oluşan bir matrisle gösterilebilir.

Nicemlemede alınan değer en yakın tanımlı seviyeye yuvarlandığı için bir nicemleme hatası (quantization error) oluşur. Hoca bunun analog-dijital dönüştürücülerden (ADC) tanıdık olduğunu, elektronikçilerin bu konuya daha hâkim olduğunu söyledi.

Nicemlemenin sonunda elimizde bir $f$ görüntü matrisi olur. $f[i,j]$ gösteriminde $i$ satır numarası, $j$ sütun numarasıdır. Gri seviyeli görüntüde matrisin her gözü o pikselin parlaklık değerini, yani 0 ile 255 arasında bir değeri tutar. Slayttaki örnek matrisin ilk satırı şöyledir (ekrandan, 01:25:00):

```text
62  79  23  119  120  105  4  0
```

## 4. Görüntü İşlemenin Adımları

Slayttaki şema, görüntüyle çalışırken yapılabilecek işlemleri gösterir (ekrandan, 01:30:00). Ortada bir bilgi tabanı (knowledge base) vardır ve bütün adımlar onunla iki yönlü etkileşir. Akış şöyledir:

```text
Görüntü edinme (Image Acquisition)
  -> Görüntü iyileştirme (Image Enhancement)
  -> Renkli görüntü işleme (Color Image Processing)
  -> Görüntü onarma (Image Restoration)
  -> Görüntü sıkıştırma (Image Compression)
  -> Görüntü bölütleme (Image Segmentation)
  -> Temsil ve betimleme (Representation & Description)
  -> Sınıflandırma ve tanıma (Classification & Recognition)
Hepsi <-> Bilgi tabanı (Knowledge Base)
```

- **Görüntü edinme:** Sahneden görüntünün alınması. Örneğin yüz tanıma çalışmasında bir kişiden birden fazla açıdan ve bazen farklı ışık koşullarında yüz görüntüleri alınır; böylece tanımanın bu değişimlere karşı ne kadar başarılı olduğu ölçülür.
- **İyileştirme:** Görüntüler her zaman ideal koşullarda alınamaz. Özellikle hava fotoğraflarında sis ya da bulut gibi hava koşulları bozulmalara yol açar; bunları gidermek için görüntü iyileştirme yöntemleri kullanılır.
- **Renkli görüntü işleme:** Her piksel kırmızı, yeşil, mavi gibi üç renk kanalıyla ifade edilebilir. Bu görüntüler bazen gri seviyeye çevrilip, bazen doğrudan renkli haliyle işlenir.
- **Onarma (restoration):** İyileştirmeden farklı olarak görüntüdeki bozulmuş kısımların tamamlanmasıdır. Hoca örnek olarak bir el yazması kütüphanesinin sayısallaştırılmış belgelerini verdi: aşınma ve eskime yüzünden harflerde bozulmalar vardır ve bunların iyileştirilip tamamlanması üzerine çalışmalar yapılır.
- **Sıkıştırma:** Görüntüler diskte yer kaplar; daha az yer kaplamaları için sıkıştırma yöntemleri kullanılır. JPEG kayıplı bir sıkıştırmadır: görüntü kalitesinden belli oranda kayıp verir, ama bu kayıp gözle bakınca pek algılanmaz.
- **Bölütleme (segmentation):** Bilgisayarla görmenin ana konularından biridir; nesneyi önce ayırt etmek gerekir. Yalnız yüz görüntüsü düşünülmemelidir: belli bölgeleri arka plandan ya da başka bir dokudan ayırmak da bölütlemedir. Örneğin iris tanımada iris bölgesinin göz fotoğrafından ayrılması.
- **Temsil ve betimleme, sınıflandırma ve tanıma:** Sınıflandırma ve tanıma bu dersin ana konusudur; dönem boyunca yapılmaya çalışılacak temel işlem budur.

## 5. Parlaklık Dönüşümü: Negatif Görüntü ve Gamma Düzeltmesi

### 5.1 Negatif görüntü

Gri seviyeli bir görüntü 0-255 arasında değer alır. Görüntünün negatifi her piksel değerinin 255'ten çıkarılmasıyla elde edilir:

$$s = 255 - r$$

Buna tümlenmiş görüntü (complemented image) de denir. Hocanın gösterdiği örnekte arka plan için bu işlem uygulanmamıştı; arka plandaki siyah bölgeler siyah kalmış, yalnız beden üzerindeki piksellerin tersi alınmıştı. Negatif görüntü bazen ayrıntıları görmeyi kolaylaştırır.

### 5.2 Gamma düzeltmesi

Hoca Gonzalez'in kitabından alınmış bir hava fotoğrafını gösterdi. Görüntü çok aydınlık, "patlamış"tı; büyük olasılıkla ışığın açısından dolayı fazla ışık almıştı. Bu tür görüntüler parlaklık dönüşümüyle düzeltilebilir. Örnekte gamma düzeltmesi uygulanmış, $\gamma$ = 3, 4 ve 5 seçilerek görüntü koyulaştırılmış ve ayrıntılar algılanabilir hale gelmişti.

Gamma düzeltmesinin denklemi (ekrandan, 01:35:00):

$$s = c\,r^{\gamma}$$

Burada $r$ giriş parlaklık seviyesidir (grafikte yatay eksen, input intensity level), $s$ ise dönüşümden sonraki çıkış parlaklık seviyesidir (dikey eksen, output intensity level). Slayttaki eğrilerin hepsinde $c = 1$'dir ve eğriler gösterilen aralığa sığacak şekilde ölçeklenmiştir. Slaytta $\gamma$ = 0,04; 0,10; 0,20; 0,40; 0,67; 1; 1,5; 2,5; 5,0; 10,0 ve 25,0 eğrileri vardır. $\gamma = 1$ eğrisi doğrusaldır, yani görüntüyü değiştirmez.

Hoca $c = 1$ için örnek verdi: bir pikselin parlaklığı 10 ve $\gamma = 1{,}5$ ise çıkış $10^{1{,}5}$ olur.

- Verilen: $r = 10$, $\gamma = 1{,}5$, $c = 1$.
- İşlem: $s = 10^{1{,}5} = 10 \cdot \sqrt{10}$ (ara adım eklendi).
- Sonuç: $s \approx 31{,}6$.

> **Ders sonrası not:** Büyük olasılıkla uygulamada $r$ önce $[0,1]$ aralığına normalleştirilir ($r/(L-1)$), sonuç yeniden $L-1$ ile çarpılır; aksi halde büyük $r$ değerlerinde ve $\gamma > 1$ için çıkış 255'i aşar. Slayttaki eğrilerin "gösterilen aralığa ölçeklendiği" de bunu gösterir.

#### Eğrilerin grafikten okunması

Hoca eğrilerin ne iş yaptığını grafik üzerinden şöyle anlattı. Yatay eksende giriş parlaklıkları 0'dan $L-1$'e kadar gider (0-255 gibi düşünülebilir); eksenin orta noktası $L/2$'dir.

1. $\gamma > 1$ eğrilerine bakalım (1,5; 2,5; 5; 10; 25). $L/2$ noktasından yukarı bir dikme çizilir, $\gamma = 2{,}5$ eğrisinin kesildiği noktadan dikey eksene gidilir. Bu nokta $L/2$'nin çok altına düşer, yani değer sıfıra yaklaşır. Sıfıra yaklaşmak koyulaşmak demektir. Bu yüzden $\gamma$ = 2,5, 5 ya da 10 gibi değerler görüntüyü koyulaştırmak, daha karanlık hale getirmek için kullanılır. Çok aydınlık hava fotoğrafında $\gamma$ = 3, 4, 5 seçilmesinin nedeni budur.
2. Tersine, $\gamma = 0{,}2$ eğrisine bakalım. $L/2$'den çıkılan dikme bu eğriyi kestiğinde dikey eksende $L/2$'nin çok üstüne çıkılır, yani beyaza yaklaşılır. $\gamma < 1$ eğrileri görüntüyü aydınlatmak için kullanılır; çok karanlık bir görüntü bu şekilde aydınlatılabilir.

Normalleştirilmiş eğrilerle bu okumanın sayısal karşılığı (ara adım eklendi, python ile hesaplandı): $r = L/2$ için $\gamma = 2{,}5$'te $s = 0{,}5^{2{,}5}(L-1) \approx 0{,}18(L-1)$, $\gamma = 0{,}2$'de $s = 0{,}5^{0{,}2}(L-1) \approx 0{,}87(L-1)$.

**Soru:** Buradaki $L$ değeri tam olarak nedir? **Cevap:** $L$, giriş görüntüsünün parlaklık aralığını gösterir. Bir gri seviyeli görüntüde piksel 8 bitle kodlanmışsa 0-255 arasında değer alır; eksen 0'dan başlar ve 255'e kadar gider. Yani $L = 256$, en büyük değer $L - 1 = 255$'tir.

## 6. Kontrast ve Histogram

### 6.1 Düşük kontrastlı görüntü

Görüntüde sık karşılaşılan sorunlardan biri düşük kontrasttır. Hoca bunun teknik tanımını şöyle verdi: gösterilen görüntüde tam siyah hiç yoktur, tam beyaz da hiç yoktur. Parlaklık değerleri 0-255 aralığının içinde dar bir bölgededir ve uç noktalardaki değerler kullanılmaz. Bu tür görüntülere düşük kontrastlı görüntü denir.

Kontrast iyileştirmeden (contrast enhancement) sonra görüntüde siyah ve beyaz bölgeler ortaya çıkar, görüntü daha net ve anlaşılır olur. Slayttaki şekil (ekrandan, 01:40:00) kontrast germeyi (contrast stretching) gösterir:

- (a) Dönüşüm fonksiyonu $T(r)$: $(0,0)$, $(r_1, s_1)$, $(r_2, s_2)$ ve $(L-1, L-1)$ noktalarından geçen parçalı doğrusal bir fonksiyon. Ortadaki dik parça, dar giriş aralığını geniş bir çıkış aralığına yayar.
- (b) Düşük kontrastlı görüntü.
- (c) Kontrast germenin sonucu.
- (d) Eşiklemenin sonucu.

> **Ek bilgi (derste anlatılmadı):** Gonzalez'in kitabında $r_1 = r_2$, $s_1 = 0$ ve $s_2 = L-1$ seçildiğinde kontrast germe fonksiyonu bir eşikleme fonksiyonuna dönüşür; şekildeki (d) görüntüsü bu durumun sonucudur.

### 6.2 Histogram ile görüntüyü tanılamak

Histogram, görüntüdeki parlaklık değerlerinin kaç kez tekrarlandığını gösterir. Yatay eksen parlaklık değerleridir (0-255); her çubuk o parlaklığın görüntüde kaç kez geçtiğini gösterir. Hoca dört görüntü ve histogramlarını karşılaştırdı:

- **Karanlık görüntü (dark image):** Histogram çubukları sola, sıfıra yakın bölgeye yığılmıştır. Sıfıra yakın olmak karanlık olmak demektir. 255 bölgesinde ya hiç çubuk yoktur ya da çok azdır.
- **Aydınlık görüntü (bright image):** Beyaza yakın tonlar çoktur ama siyah yoktur; histogram sağa yığılmıştır.
- **Düşük kontrastlı görüntü:** 0-255 aralığının yalnız orta bölgesindeki dar bir aralık kullanılmıştır; ne siyah ne beyaz vardır.
- **İyileştirilmiş (ideal) görüntü:** Hem sol (siyah) tarafta hem sağ (beyaz) tarafta piksel vardır; parlaklık değerleri tüm aralığa yayılmıştır.

> **Hocanın vurgusu:** Bir görüntüye bakınca problemin ne olduğunu tarif edebilmelisiniz. Görüntünün karanlık olduğunu gözle söyleyebiliriz; ama bunu sisteme teknik olarak anlatmak için histogramını çizip ortalamasını almak gibi yollar kullanılabilir.

## 7. Bilgisayarla Görmenin Uygulama Alanları

Görüntü işleme ve bilgisayarla görmenin günlük hayata girmiş pek çok çözümü vardır ve sayıları her geçen gün artmaktadır.

### 7.1 Akıllı belge tanıma

Akıllı belge tanıma (intelligent document recognition) başlığı altında bir belgedeki harfler ve karakterler tanınır. Tanımadan sonra belge analiz edilir: hangi bölgede tarih, hangi bölgede sayı, hangi bölgede kelime olduğu belirlenir. Belgenin yapısı biliniyor ve sisteme öğretilmişse, örneğin bir tarihin sipariş tarihi (order date) olduğu anlaşılıp bu bilgi belgeden çıkarılabilir. Tarih farklı biçimlerde yazılmış olabilir; çıkarılan veri sonunda sisteme kaydedilir. Bu tür çözümler robotik süreç otomasyonunda (robotic process automation) da kullanılır.

### 7.2 Biyometrik tanıma

Biyometrik tanıma bilgisayarla görmenin en önemli uygulama alanlarındandır. Bankacılık ve e-ticaret sitelerinde her platform için bir kullanıcı adı ve şifre alırız; ama şifreler kolayca kopyalanabilir ya da kaptırılabilir. Sistemi güçlendirmek için biyometrik öznitelikler kullanılabilir: kişi sisteme kendi üzerinde taşıdığı bir bilgiyle girer. Slayttaki örnekler parmak izi, iris, ses, yüz, el şekli ve imzadır (ekrandan, 01:50:00).

Parmak iziyle yapılan çok uygulama vardır; günümüzde ise sistemlerin yüz tanımayla çalışması isteniyor, örneğin bankada hesap açarken bile yüzden tanıma. Ancak engelleyici unsurlar vardır: makyaj, sakal, bıyık, saç şekli ve gözlük gibi değişikliklerle insanlar çok çabuk değişebilir; bu da sistemlerin tanıma başarısını sınırlar ve konu hâlâ üzerinde çalışılan bir alandır.

#### Kimliklendirme (identification) ve doğrulama (authentication)

Hoca bu iki kavramı parmak izi üzerinden ayırdı. Bir biyometrik veri tabanında 1000 kişinin parmak izi olduğunu varsayalım.

- **Kimliklendirme:** Kişi parmak izini okutur ve "ben kimim?" diye sorar. Sistem bu parmak izini veri tabanındaki $N$ kullanıcının parmak iziyle karşılaştırır, hangisine uyduğunu bulur ve bir kimlik (ID) döndürür. Karşılaştırma 1'e $N$ olduğu için oldukça maliyetlidir.
- **Doğrulama:** Kişi "ben şu kişiyim, bu benim parmak izim" der. Sistem yalnız o kişinin kayıtlarını çıkarır ve o anda alınan parmak izini bu kayıtlarla karşılaştırır; 1'e 1 bir eşleştirmedir. Bir eşik konur; örneğin yüzde 80 ve üzeri benzerlik varsa kişinin beyan ettiği kişi olduğu kabul edilir. Sonuç evet ya da hayırdır.

> **Hocanın vurgusu:** Identification ve authentication iki ayrı kavramdır. Doğrulamada 1'e 1, kimliklendirmede 1'e $N$ karşılaştırma yapılır. Doğrulama daha hızlı çalışır ve tanımada ek bir güvenlik unsuru olarak kullanılır.

### 7.3 Hava fotoğraflarının yorumlanması

Hava fotoğrafları çok farklı alanlarda kullanılır: yapılaşmanın ölçülmesi, kaçak binaların tespiti, tarım arazilerinde hangi ürünün hangi tarihler arasında ekildiğinin belirlenmesi ve askeri amaçlar.

### 7.4 Trafik izleme

Akıllı ulaşım sistemlerinde trafik kameralarıyla akan araçların hızları ölçülebilir, araçların kendi şeritlerinde gidip gitmediği (şerit ihlali) otomatik olarak algılanabilir. Trafik ışıklarının bulunduğu noktalarda kırmızı ışık ihlali için kameralar kullanılır. Trafik yoğunluğunun ölçülmesinden ihlallere kadar pek çok uygulama vardır. Slaytta bir otoyol kamera görüntüsü ve araçların renkli yörüngelerle izlendiği bir örnek gösterildi (ekrandan, 01:55:00).

### 7.5 Spor ve eğlence, derinlik kamerası

Futbolda oyuncuların topu ne kadar süre ayağında tuttuğu gibi performans ölçütleri video görüntülerinden analiz edilebilir; oyuncuların saha içindeki yerleri sürekli ve otomatik olarak izlenebilir.

Microsoft Kinect bir derinlik kamerasıdır. Üzerinde kızılötesi bir ışık kaynağı vardır; bu kaynak görüntülenen sahneye ışık yayar ve nesnenin kameraya uzaklığı ölçülür, böylece derinlik bilgisi alınır. Aynı cihazda bir RGB kamera da vardır; bu yüzden RGB-D kamera denir.

### 7.6 Yüz bulma, yüz tanıma ve yüz ifadesi tanıma

Sahnedeki yüzlerin bulunması (face detection) eski bir çalışmadır; 2001'de Viola-Jones algoritması ilk kez yüz bulmada kullanıldı, sonra başka algoritmalar geliştirildi. Bugün cep telefonu kameralarında da bu yazılım vardır: sahnedeki yüzler bir çerçeveye alınır ve odaklama o yüze yapılır.

Yüz tanımada (face recognition) bulunan yüzler üzerinden kişinin kim olduğu bulunur; verilen görüntünün veri tabanındaki yüzlerden hangisi olduğu, farklı pozlar üzerinden aranır. İlk zamanlarda temel bileşen analizi (PCA) ve özyüzler (eigenfaces) kullanıldı. Yeni gelen görüntü mevcut görüntülerle karşılaştırılarak tanıma ya da kimliklendirme yapılır.

Yüz ifadesi tanıma da popüler bir konudur. Slaytta nötr dahil sekiz ifade vardır (ekrandan, 02:00:00): tiksinme (disgust), şaşkınlık (surprise), üzüntü (sad), öfke (angry), korku (fear), mutluluk (happy), küçümseme (contempt) ve nötr (neutral). Bu ifadelerin bilgisayarca anlaşılması zor bir problemdir, çünkü herkesin yüz ifadesi o anki ruh halini bu kadar belirgin göstermez. Robot-insan etkileşiminde robotun karşısındakinin ruh halini anlayıp ona uygun bir konuşma dili seçmesi gibi çalışmalar literatürde vardır.

### 7.7 El duruşu ve el hareketi tanıma (işaret dili)

İşitme engellilerin iletişim için kullandığı işaret dilinin iki biçimi vardır:

- **Parmak heceleme (finger spelling):** A'dan Z'ye her harfin bir el duruşu (posture) karşılığı vardır; slaytta Amerikan İşaret Dili gösterildi. Türk İşaret Dili'nde bazı harfler iki elle gösterilir; örneğin "ö" harfi "o" harfinin üzerine yapılan ek bir hareketle gösterilir. Parmak heceleme yalnız özel adları anlatırken kullanılır: az karşılaşılan bir şehir adı ya da bir kişinin adı harf harf gösterilir. Sabit bir duruş olduğu için harfler bu yapıya göre tanınabilir. Hoca, bölümde Türk İşaret Dili'ndeki bütün harfleri tanıyan bir sistem üzerine bir doktora tezi yapıldığını belirtti.
- **El hareketi (hand gesture):** Kelimelerin bir hareket karşılığı vardır; örneğin üşüdüğünüzde yaptığınız hareket "üşüdüm" anlamına gelir. Bunlar hareket tabanlı olduğu için tanınması daha zordur. Bugünkü durumda cümle içindeki kelimeler tek tek tanınabiliyor, ama bunları bilgisayarın bir cümleye dönüştürmesi kolay değildir.

### 7.8 İnsan aktivitesi tanıma

Slayttaki örnekte iki kişi numaralandırılmış, mavi ve kırmızı renkle gösterilmiştir (ekrandan, 02:05:00). Kişiler birbirine doğru yürür, etkileşir (bir nesne alıp verir) ve yollarına devam eder; slayttaki etiketler "periyodik hareket, nesne taşıyor/taşımıyor" ve "kişi 1 ile etkileşim" gibidir. Bunun dışında oturma, kalkma, yürüme, zıplama gibi hareketleri algılayan sistemler üzerinde de çalışılır. Örneğin havalimanında insanların normal bir akış içinde yürümesi beklenir; biri zıplıyor ya da yerde yatıyorsa bu anormal bir durum olarak işaretlenmelidir. Aktivite tanıma bu anormal durumu tespit etmek için devreye girer.

### 7.9 Tıbbi uygulamalar

Hoca bu alanda gerçekten çok eksik olduğunu söyledi. Bir radyoloji uzmanının yapacağı işin bir kısmı yazılımla yapılabilir: yazılımın oluşturduğu rapor uzman tarafından hızlıca incelenip onaylanır; belli bir süre sonra güven oluşursa bu kontrole bile gerek kalmayabilir. Slaytta cilt kanseri ve meme kanseri için kanserli dokunun işaretlenmesi ve ölçülmesi örnekleri vardı.

Akciğer tomografisinde buzlu cam (ground glass) dokusu oluşumu gözlemlenir; COVID teşhisinde ilk zamanlarda tomografiye başvurulmuştu. Tomografide akciğerde hasar olup olmadığı, buzlu cam bölgesinin oluşup oluşmadığı ve bu bölgenin hacminin tüm akciğer hacmine oranı ölçülebilir. Hastalık ilerledikçe buzlu cam dokusu bal peteği (honeycomb) biçimine dönüşür ve akciğerin o bölgesi iş göremez hale gelir; bu yüzden bu dokunun takip edilmesi ve miktarının tüm akciğer hacmiyle kıyaslanarak ölçülmesi önemlidir.

## 8. Nesne Tanımanın Tarihçesi: SIFT, HOG, Pascal VOC ve ImageNet

### 8.1 SIFT

2000'li yılların başında nesne tanımada SIFT algoritması çok kullanılıyordu. SIFT (Scale Invariant Feature Transform) ölçekten bağımsız olarak öznitelikler çıkarır ve ilk yıllarda nesne tanımaya büyük fayda sağladı.

> **Ders sonrası not:** Hoca önce açılımı "Shift Invariant" diye söyledi, sonra kendisi "Scale Invariant" diye düzeltti. Doğrusu Scale Invariant Feature Transform'dur.

### 8.2 HOG (Histogram of Oriented Gradients)

HOG, Dalal ve Triggs'in 2005'te CVPR'da yayımladığı bir öznitelik çıkarma yöntemidir (ekrandan, 02:10:00). İlk kullanım alanı yaya tespitiydi: kent güvenliği kameralarında yürüyen yayaları tek tek bulup takip etmek.

- Görüntü penceresi 8x8 piksellik hücrelere bölünür.
- Her hücredeki kenar (edge) bilgisi ve kenarın yönelim açısı (orientation) bulunur; slaytta buna baskın yön (dominant direction) denir.
- Her hücre bir yönelim histogramıyla (HOG) temsil edilir: yatay eksen yönelim, dikey eksen sıklıktır.
- İnsan kolları ve bacakları dikey kenarlar ürettiği için bu bilgiyle insan figürleri arka plandaki diğer görüntülerden ayrılabilir.

Slayttaki öznitelik vektörü boyutu (ekrandan, 02:10:00; python ile doğrulandı):

$$16 \times 8 \ (\text{döşeme, tiling}) \times 8 \ (\text{yönelim}) = 1024$$

Yöntem başka alanlarda da kullanıldı; sonra bu yöntemler yerini CNN'lere bıraktı.

### 8.3 Pascal VOC yarışması

2006-2012 yılları arasında 20 nesne kategorisinden oluşan bir görüntü veri tabanı oluşturuldu ve Pascal Visual Object Classes yarışması düzenlendi. Yarışmanın 2009-2012 sonuçlarında her sınıf için tanıma başarısı ve mavi renkle bütün sınıfların ortalaması yıllara göre gösterildi. Hoca, precision değerine bakıldığında yaklaşık yüzde 40 civarında bir başarıyla tanıyan sistemler oluşturulduğunu söyledi.

<!-- BELİRSİZ: Pascal VOC sonuç grafiğinin karesi okunmadı; "yüzde 40 civarı precision" altyazıdan alındı. -->

### 8.4 ImageNet yarışması

Daha sonra ImageNet kütüphanesi üzerinde bir yarışma düzenlendi (ekrandan, 02:15:00):

- Görüntü sınıflandırma yarışması (The Image Classification Challenge).
- 1000 nesne sınıfı.
- 1.431.167 görüntü.

Değerlendirme şöyle yapılır: Bir sahne görüntüsü verilir; görüntüde birden fazla nesne vardır, ama aranan nesne (örneğin bir bateri) bellidir. Model tahminler üretir:

- Model ilk tahmininde aranan nesneyi bulmuşsa bu doğru kabul edilir (ilk 1 doğruluğu).
- Diğer değerlendirmede modelden beş tahmin istenir; aranan nesne bu beşin içindeyse sistem yine doğru çalışmış sayılır.
- Beş tahminin hiçbirinde aranan nesne yoksa sonuç yanlış olarak etiketlenir.

Slayttaki hata oranları (%) (ekrandan, 02:15:00):

| Yıl | Yöntem | Hata (%) |
|---|---|---|
| 2010 | Lin vd. | 28,2 |
| 2011 | Sanchez ve Perronnin | 25,8 |
| 2012 | Krizhevsky vd. (AlexNet) | 16,4 |
| 2013 | Zeiler ve Fergus | 11,7 |
| 2014 | Simonyan ve Zisserman (VGG) | 7,3 |
| 2014 | Szegedy vd. (GoogLeNet) | 6,7 |
| 2015 | He vd. (ResNet) | 3,57 |
| İnsan | Russakovsky vd. | 5,1 |

2012'de ilk kez AlexNet kullanıldı ve hata yüzde 16,4'e indi. 2014'te VGG hatayı yüzde 7,3'e düşürdü. 2015'te ResNet hatayı yüzde 3,57'ye indirdi; grafikteki 5,1 insanın hatasıdır, yani 2015'te ResNet ile insan hatasından daha düşük bir hata elde edildi. Sonraki yıllarda yapılan çalışmalar, bu sistemlere yarışma verisinden çok farklı görüntüler verildiğinde zaman zaman başarısız olduklarını gösterdi; yarışma sonuçları kendi veri kümesi içinde yapılmış testlerdir.

> **Ders sonrası not:** Hoca "2014 yılında hata yüzde 7,3'e kadar düşmüş" dedi; slaytta 2014'te GoogLeNet ile 6,7 değeri de vardır. Büyük olasılıkla bu oranlar ilk 5 (top-5) hata oranlarıdır.

## 9. Görüntü Altyazılama ve Evrişimli Sinir Ağları

### 9.1 Görüntü altyazılama (image captioning)

Görüntü altyazılama yalnız nesne tanımakla kalmaz, sahneyi bir açıklama metnine dönüştürür. Slayttaki örnekte önce yerde bir kaykay ("a skateboard on the ground") bulunur; kaykayın üzerinde bir insan olduğu için "a man on a skateboard" denir. Mavi çerçeveyle işaretlenen arka planda ise bisiklete binen bir insan için "man riding a bicycle" denir. Sistem nesneleri insan figürü gibi diğer nesnelerle ilişkilendirerek olayı bir cümleye dönüştürür.

Hoca benzer bir uygulamadan bahsetti: havalimanına inen bir uçağın bir sonraki uçuşa hazırlanana kadar aldığı hizmetler (akaryakıt yüklenmesi, catering aracının gelip yükleme yapması, yolcuların merdivenden inip otobüslerle taşınması, yeni yolcuların binmesi gibi) videodan izlenir. Sınırlı sayıda eylemin gerçekleşip gerçekleşmediği ve hangi zaman diliminde gerçekleştiği belirlenir.

### 9.2 CNN yapısı

Slayttaki CNN şeması şöyledir (ekrandan, 02:20:00):

```text
Giriş (INPUT)
  -> Konvolüsyon + ReLU -> Pooling
  -> Konvolüsyon + ReLU -> Pooling -> ...        (gizli katmanlar: öznitelik çıkarma)
  -> Flatten -> Tam bağlantılı (Fully Connected) -> Softmax   (sınıflandırma)
Çıkış sınıfları: CAR, TRUCK, VAN, ..., BICYCLE
```

- Girişte görüntü doğrudan verilir; renkli görüntüde bu, renk kanallarıyla verilmiş bir matristir.
- Konvolüsyon katmanının ardından aktivasyon fonksiyonu olarak ReLU (Rectified Linear Unit) gelir.
- Pooling katmanı max pooling ile alt örnekleme (subsampling) yapar.
- Konvolüsyon, ReLU ve pooling art arda tekrarlanarak öznitelik çıkarma yapılır. Bu işlemler bitince öznitelik üretmek için ek bir iş yapmaya gerek kalmaz; sistem görüntüyle ilgili çok sayıda öznitelik üretir.
- Matrisi vektöre dönüştürme işlemine flatten (düzleştirme) denir.
- Öznitelik vektörü art arda tam bağlantılı katmanlardan (gizli katmanlardan) geçirilir; sınıflandırma tam bağlantılı katman ve softmax katmanıyla yapılır.

Bu yapı bilgisayarla görmede çığır açtı: çok sayıda görüntü ve güçlü GPU'larla bu işlemler artık çok daha yüksek başarıyla yapılabiliyor.

### 9.3 CNN bir gecede keşfedilmedi

Konvolüsyon işlemleri işaret işlemede daha önce de kullanılıyordu. Nesne tanımada da 1989-1999 yılları arasında el yazısı rakam okuma (handwritten digit reading) çalışmasında kullanıldı: giriş görüntüsü doğrudan bir matrise alınmış el yazısı bir karakterdir; art arda konvolüsyon filtreleriyle öznitelik üretilir ve tam bağlantılı katmanın sonunda giriş görüntüsünün hangi karaktere karşılık geldiği söylenir. Yani bu fikir 2012'de bulunmadı. 2012 ve sonrasında hesaplama platformlarının gelişmesi, GPU alanındaki ilerlemeler, altyapının güçlenmesi ve eğitim örneği sayısının artmasıyla daha yüksek başarımlı sistemler tasarlanabildi.

> **Ek bilgi (derste anlatılmadı):** Bu çalışma LeCun ve arkadaşlarının LeNet ağlarıdır; büyük olasılıkla en bilinen sürümü LeNet-5 (1998), posta kodu ve banka çeki rakamlarını okumak için geliştirildi.

## 10. Derste Paylaşılan Uygulama Örnekleri

Dersin sonunda hoca öğrencilerden çevrelerinde gördükleri ilginç bilgisayarla görme uygulamalarını paylaşmalarını istedi. Paylaşılan örnekler:

- Metinden görsel üreten bir model (OpenAI'nin DALL-E projesi): girilen kelimelerden, gerçekte olmayan bir görsel üretilebiliyor.
- Kameraya gösterilen Rubik küpünü robot eliyle çözen bir OpenAI projesi; çözüm kısmı pekiştirmeli öğrenmeyle (reinforcement learning) ilişkili. Hoca da bu projeyi çok beğendiğini söyledi.
- Otonom drone projeleri; kullanıcı çizerken ne çizdiğini tahmin eden oyunlar; bir oyun ortamında kendi kendine araba süren sistemler. Hoca insansız araçlar konusunun çok revaçta olduğunu ve hâlâ boşluklar bulunduğunu söyledi.
- Metinden konuşma üreten bir ses modeli (WaveNet); bir öğrenci burada CNN'den çok RNN kullanılmış gibi göründüğünü belirtti. Hoca metinden konuşmaya (text-to-speech) ve konuşmadan metne (speech-to-text) yönlü çalışmalar olduğunu söyledi.
- Gıda fabrikalarında çürük ya da bozuk ürünleri (örneğin domates) görüntü işlemeyle otomatik ayıklayan hatlar; hoca kaliteli ürünleri seçip sınıflandıran sistemlerin de olduğunu ekledi.
- Depremde yıkılan binaların içine mini dronlarla girip hasarın nereden kaynaklandığını (örneğin kolondan) görüntüleyen bir çalışma. Hoca bölümdeki bir robot çalışma grubunun paletli araçlarla benzer ortamlara girip görüntüleme yaptığını, bunun dronlarla da yapılabileceğini söyledi.

**Soru:** Kameradan hız tespiti, aracın uzaklaşmasına ve zamana bağlı olarak mı yapılıyor? Sensör olmadan hız ölçülebiliyor mu? **Cevap:** Evet. Örneğin trafik ışıklarında iki direk arasındaki uzaklık ve kameranın bu direklere uzaklığı bilinir. Bu bilgilerle aracın görüş alanına girdiği andaki yeri ve ulaştığı noktaya ne kadar sürede gittiği kullanılarak anlık hız ölçülebilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:37:30): $\gamma = 0{,}2$ eğrisi görüntüye ne yapar?

> **Çözüm (derste verildi):** $L/2$'den yukarı çıkılan dikme $\gamma = 0{,}2$ eğrisini $L/2$'nin çok üstünde keser, yani çıkış beyaza yaklaşır. $\gamma < 1$ eğrileri görüntüyü aydınlatır; çok karanlık görüntüleri düzeltmek için kullanılır. Normalleştirilmiş durumda $r = L/2$ için çıkış yaklaşık $0{,}87(L-1)$'dir (python ile hesaplandı).

**Soru 2** (derste sözlü, 01:38:45): Gamma eğrilerindeki $L$ değeri nedir?

> **Çözüm (derste verildi):** $L$, giriş görüntüsünün parlaklık seviyesi sayısıdır. 8 bitle kodlanmış gri seviyeli görüntüde değerler 0-255 arasıdır, yani $L = 256$ ve eksen $L - 1 = 255$'e kadar gider.

**Soru 3** (derste sözlü, 01:43:22): Bir görüntünün karanlık, aydınlık ya da düşük kontrastlı olduğunu sisteme teknik olarak nasıl anlatabiliriz?

> **Çözüm (derste verildi):** Histogramı çizilir. Çubuklar sola yığılmışsa görüntü karanlık, sağa yığılmışsa aydınlıktır; yalnız ortadaki dar bir aralık kullanılmışsa görüntü düşük kontrastlıdır. Histogramın ortalaması gibi ölçüler de kullanılabilir.

**Soru 4** (derste sözlü, 02:24:08): Trafik kamerasıyla, ayrı bir sensör olmadan araç hızı nasıl ölçülür?

> **Çözüm (derste verildi):** Sahnedeki sabit nesneler (örneğin iki direk) arasındaki uzaklık ve kameranın bunlara uzaklığı bilinir. Aracın görüş alanına girdiği konum ile ulaştığı konum arasındaki mesafe, bu iki konum arasında geçen süreye bölünerek hız bulunur.

## Dersin Toparlaması

Bu ilk derste bilgisayarla görmenin ne olduğu ve dönem boyunca izlenecek yol çizildi: temel görüntü işleme işlemleri (parlaklık dönüşümü, filtreleme, türev, eşikleme, morfoloji, Hough dönüşümü), elle tasarlanan öznitelikler (Harris, HOG) ve ardından CNN tabanlı derin öğrenme. Görüntünün sahne, aydınlatma, kamera ve bilgisayar bileşenleriyle nasıl oluştuğu; örnekleme (çözünürlük) ve nicemleme (bit derinliği) ile nasıl bir tam sayı matrisine dönüştüğü anlatıldı. Gamma düzeltmesi ve histogram örnekleri, sonraki haftalarda ayrıntılı işlenecek parlaklık dönüşümlerine ilk bakışı sağladı.

Uygulama alanlarında belge tanımadan biyometriye, trafik izlemeden tıbbi görüntülemeye kadar geniş bir yelpaze görüldü; kimliklendirme ile doğrulama arasındaki fark özellikle vurgulandı. Nesne tanımanın tarihçesi SIFT ve HOG'dan Pascal VOC ve ImageNet yarışmalarına, oradan AlexNet, VGG ve ResNet ile insan hatasının altına inen CNN'lere uzandı. Gelecek derste bu temellerin uygulamasına Python ve NumPy ile başlanacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
