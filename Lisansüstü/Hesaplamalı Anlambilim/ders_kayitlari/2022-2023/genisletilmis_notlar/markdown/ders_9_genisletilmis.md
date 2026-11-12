# Ders 9 Genişletilmiş Notu: Uygulamalar: Metin Sınıflandırma, Duygu Durum Analizi, Varlık İsmi Tanıma ve Sıfır Çekimli Prompt Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bölüm 6'ya Giriş: Uygulamalar
- 2. Metin Sınıflandırma
- 3. Eğitim Kümesi Büyüdükçe Test Başarısı Neden Artar?
- 4. Duygu Durum Analizi
- 5. CNN ile Duygu Durum Analizi
- 6. Karşılaştırma Sonuçları ve Harici Bilgi
- 7. Duygu Durum Analizi Zordur
- 8. Varlık İsmi Tanıma
- 9. Varlık İsmi Tanıma ile Makine Çevirisinin Karşılaştırılması
- 10. Sıfır Çekimli Sınıflandırmada Prompt Analizi: Öğrenci Sunumları
- Örnek Sorular
- Dersin Toparlaması

## 1. Bölüm 6'ya Giriş: Uygulamalar

Önceki derste Bölüm 5'te bağlam farkında sinirsel dil modelleri (RNN, LSTM, GRU, dikkat mekanizması, Transformer, ELMo, GPT, BERT ailesi ve Byte Pair Encoding) anlatılmıştı. Bu derste ders notlarının "Uygulamalar" başlıklı Bölüm 6'sına başlandı. Ekranda açık olan sunumun içerik slaytı şu başlıkları sıralar (ekrandan, 00:10:00):

- Metin sınıflandırma
- Duygu durum analizi
- Varlık ismi tanıma
- Paragraf anlama
- Soru cevaplama
- Metinlerde çıkarım
- CNN ve RNN hakkında
- Metin / haber / hikâye / şiir üretimi
- Sohbet ve sanal asistan uygulamaları

Hoca bu derste bunlardan ilk üçünü kısa kısa anlatacağını, devamına sonraki derste geçileceğini söyledi. Dersin ikinci ve çok daha uzun kısmı, öğrencilerin sıfır çekimli (zero-shot) sınıflandırmada prompt'ların etkisini inceleyen çalışmalarının sunumlarına ayrıldı (Bölüm 10).

## 2. Metin Sınıflandırma

### 2.1 Tanım ve uygulama alanları

Metin sınıflandırma, elimizdeki bir metni daha önceden tanımlanmış kategorilerden birine dahil etme problemidir. Hoca bu konunun öğrencilerin zaten aşina olduğu bir konu olduğunu, ödevlerde de yapıldığını hatırlattı. Uygulama alanı çok geniştir: bir e-postanın spam olup olmadığına karar vermekten, haber sitelerindeki son dakika gelişmelerinin hangi kategoriye konacağına kadar birçok yerde kullanılır.

### 2.2 Çok etiketli (multi-label) sınıflandırma

Bazı problemlerde bir metin, etiket kümesindeki tek bir kategoriye değil, birden fazlasına karşılık gelebilir. Örneğin 10 etiket varsa bir metin bunlardan ikisini içeriyor olabilir; bir haber hem siyasete hem ekonomiye dair olabilir. Hoca bunun için çok temel iki yaklaşım anlattı.

Birinci yaklaşım tek bir sınıflandırıcı ve bir eşik kullanır. Sınıflandırıcı çıkışında her sınıfa ait olma olasılığını verir. Bir eşik değeri belirlenir; örneğin %30'un üstündeki bütün sınıflar metnin etiketi kabul edilir. Bu durumda eğitim kümesi oluşturulurken hedef one-hot kodlanmaz: bir örnek birden fazla sınıfa aitse, ait olduğu sınıfların hepsi 1, diğerleri 0 yapılır.

İkinci yaklaşımda her kategori için ayrı bir sınıflandırıcı eğitilir. 10 kategori varsa 10 sınıflandırıcı olur ve her biri ikili (binary) sınıflandırma yapar. Örneğin ekonomi, siyaset ve spor kategorileri için "ekonomi haberi midir, değil midir?", "siyaset haberi midir, değil midir?", "spor haberi midir, değil midir?" diyen üç model kurulur. Bir metin bu modellerin birden fazlasından olumlu cevap alabilir.

### 2.3 LSI ile haber sınıflandırma deneyi

Slayttaki örnek bir haber sınıflandırma problemidir (ekrandan, 00:10:00):

- Kod: `text_classify_lsi.m`
- 13 sınıflı haber metinlerini sınıflandıralım.
- Metinleri LSI ile $13 \cdot 5$ boyutta ifade edelim.
- Test örnekleri sabit; her sınıf için 250 tane.
- Eğitim örneklerinin sayısı arttıkça ...
- Metinleri tf, binary, tf-idf, kelime n-gram olarak temsil edelim. Kod: `text_classify_tfidf.m`

Metinler önce sözlük boyutlu bir uzayda temsil edilmiş, sonra LSA/LSI uygulanarak $13 \cdot 5 = 65$ boyuta indirgenmiştir. Hoca önce "beş boyut" dedi, hemen ardından 65 boyut diye düzeltti. Veri kümesi ve kodlar dersin web sayfasındadır.

Slayttaki grafikte yatay eksen eğitim örnek sayısı (sınıf başına, 0-250), dikey eksen test başarısıdır (ekrandan, 00:10:00). Hoca grafiği şöyle okudu: sınıf başına 10 eğitim örneği varken, yani toplam $13 \cdot 10 = 130$ eğitim örneğiyle başarı düşüktür (grafikte %20'nin biraz altı). Sınıf başına 50 örnekte başarı belirgin biçimde artar (grafikte yaklaşık %39) ve 250 örnekte %50 civarına çıkar. Eğitim kümesindeki örnek sayısı arttıkça test başarısı doğal olarak artmaktadır. LSI yerine daha temel temsillerle (tf, tf-idf vb.) yapılan deneyde de aynı eğilim görülür.

## 3. Eğitim Kümesi Büyüdükçe Test Başarısı Neden Artar?

Hoca grafiği gösterdikten sonra sınıfa şunu sordu: test örneklerine dokunmuyoruz, yalnız eğitim örneklerinin sayısını arttırıyoruz; test başarısı neden artıyor?

**Soru (hocanın sınıfa sorusu):** Eğitim örnekleri artınca model neden test kümesinde daha iyi oluyor? **Cevap (öğrencilerden):** Çok örnek olduğu için daha iyi öğreniyor; eğitim örneklerinin çeşitliliği artıyor, model daha fazla özellik öğreniyor. Hoca "çeşitlilik neyi sağlıyor, eğitim kümesi neye benziyor?" diye sorarak cevabı şu noktaya getirdi: eğitim kümesi test kümesine daha çok benzemeye başlıyor.

Hocanın açıklaması şöyledir. Bir sınıflandırıcının başarısını test kümesi üzerinden ölçeriz. Test kümesinin kendisiyle eğitim yapsaydık test üzerindeki performans çok iyi olurdu; bazı sınıflandırıcılarla %100 bile çıkabilirdi. Demek ki test kümesine yakın bir eğitim kümeniz varsa performansınız iyi olur. Test kümesine yakın bir dağılım elde etmenin bir yolu da eğitim kümesini büyütmektir. Veri miktarı arttıkça test kümesindeki örneklere benzeyen örneklerin eğitim kümesinde bulunma ihtimali artar, dolayısıyla test performansı da artar.

> **Hocanın vurgusu:** Kaliteli ve güvenilir şekilde etiketlenmiş verinin miktarını arttırmak, test performansına pozitif katkı sağlamanın bilinen en garantili yollarından biridir. "Modelimizin performansını nasıl iyileştirelim?" sorusunun en garantili cevabı eğitim kümesini büyütmektir. Eğitim kümesi büyütülemiyorsa başka modellere, gürültüye karşı yöntemlere vb. geçilebilir; ama bunlar bu genel kuralı bozmaz.

## 4. Duygu Durum Analizi

### 4.1 Tanım ve kullanım

Duygu durum analizi, bir firma, kişi, parti, kurum ya da olay hakkında kamuoyu algısını ölçmektir; yani "bu, kamuoyunda nasıl algılandı?" sorusunun cevabını aramaktır. Slayttaki maddeler şöyledir (ekrandan, 00:30:00, sol paneldeki küçük resim; anlatım 00:20:39):

- Bir firma, kişi, parti, kurum, olay vb. hakkında kamuoyu algısını ölçmek.
- Algı operatörü botlara dikkat (tahminen %20).
- Eğitim kümesi genelde eskir.
- Metin temsilinde klasik yaklaşımlar: kelime, kelime kökü, n-gram; yeni yaklaşımlar: semantik uzaylar, LSTM, CNN.

Bu ölçüm için sosyal medya çok sık kullanılır, çünkü oldukça ucuzdur. Bir anket yaptırmak çok daha pahalıdır; insanların attığı tweet'leri kullanmak çok daha uygundur. Güvenilirlik açısından iki tarafın da olumlu ve olumsuz yanları vardır. Örneğin anketlerde insanlar bir görüşle ilişkilendirilmek istemeyebilir; Twitter'da anonim hesaplar bu yüzden kullanılabilir. Burada da eğitim kümesi büyüklüğüyle ilgili kural geçerlidir: örneklem ne kadar büyükse, "X firmasının yeni ürünü beğenildi ya da beğenilmedi" gibi bir sonuca güvenme ihtimali o kadar artar.

### 4.2 Algı operatörü botlar

Sosyal ortamlar toplum algısını etkilediği için bu algıyı yönetmek amacıyla da kullanılır. Slayta göre bu tür botların oranı tahminen %20 civarındadır; yani görülen her 5 kişiden biri, ortalama olarak. Hoca bu rakamın 2020 civarına ait olduğunu, sonrasında ne olduğunu çok bilmediklerini söyledi. Yapay zekâ ve NLP araçlarının çok gelişmesi nedeniyle bu oran değişmiş, botların fark edilip bertaraf edilmesi de zorlaşmış olabilir.

Hoca bir kişinin on bin botu yönetebileceğini örnek verdi: "X konusunda olumlu bir şey yazacağız" denince hepsine birden yazdırılır; Y konusunda olumsuz bir şey için de aynısı yapılır. Böylece toplu görünen hareketler yaratmak oldukça sıradan bir iştir. Sıradan bir kullanıcı Twitter'a girdiğinde bunu pek algılayamaz; şu kadar beğeni almış der, ama ne kadarının gerçek insan, ne kadarının yönetilen bir sistem olduğunun farkında olmayabilir. Botlar etkili olmasaydı bu kadar kullanılmazdı. Hocaya göre bunların varlığından haberdar olarak hareket etmek iyi bir fikirdir.

### 4.3 Eğitim kümesinin eskimesi

Duygu durum analizinin bir başka özelliği eğitim kümesinin eskimesidir. Olumlu/olumsuz gibi bir sınıflandırma yapılırken zaman içinde yeni jargonlar ortaya çıkar, bir süre kullanıldıktan sonra da kaybolur. Hoca daha önceki çalışmalarda gördükleri bir durumu anlattı: 2015 yılına ait verilerle bir eğitim kümesi oluşturuluyor; model 2015 test kümesinde çalışıyor, 2016'da da çalışıyor. Ama 2017-2018'e gidildikçe, yani eğitim kümesi ile test kümesi arasındaki zaman farkı arttıkça, bazı konularda ve bazı modellerde performans düşmeye başlıyor.

Bunu engellemenin en basit yolu eğitim kümesini güncellemektir. "Bir kere yapalım, bir daha hiç dokunmayalım" pek mümkün değildir. Aynı durum spam dedektörleri ve birçok başka uygulama için de geçerlidir. Hoca bunu Bölüm 3'teki açıklamaya bağladı: test kümesi zaman içinde değişirken eğitim kümesi sabit kalırsa, eğitim kümesi test kümesinden giderek uzaklaşır.

### 4.4 Temel yaklaşımlar

Klasik yaklaşımlar kelime, kelime kökü ve n-gram temsilleridir. Yeni yaklaşımlar semantik uzaylar, LSTM'ler ve CNN'lerdir; son dönemde Transformer'lar da eklenmiştir. Hoca, birazdan göstereceği çalışmanın yapıldığı zaman Transformer'ların henüz olmadığını, daha sonra aynı veri kümesini Transformer'larla kullanan çalışmalar olduğunu söyledi.

## 5. CNN ile Duygu Durum Analizi

### 5.1 Veri kümesi

Slaytın başlığı "Duygudurum Analizi Deneme"dir ve kaynak olarak "Amasyalı ve ark. 2018, ASYU, Duygudurum Analizinde Kelimeler, Anlamlar, Karakterler" gösterilir (ekrandan, 00:30:00). Veri kümesi, bir GSM operatörü hakkında kullanıcıların attığı tweet'lerin insanlar tarafından elle etiketlenmesiyle oluşturulmuştur. Sınıf dağılımı slayttaki tabloda şöyledir (ekrandan, 00:30:00):

| | Olumlu | Olumsuz | Nötr | Toplam |
|---|---|---|---|---|
| Eğitim | 3663 | 5511 | 4658 | 13832 |
| Test | 916 | 1377 | 1164 | 3457 |
| Toplam | 4579 | 6887 | 5822 | 17289 |

> **Ders sonrası not:** Tablodaki olumsuz sütununun toplamı slaytta 6887 yazar; $5511 + 1377 = 6888$'dir. Satır toplamları ($13832 + 3457 = 17289$) tutarlıdır (python ile hesaplandı).

### 5.2 Metni matrise çevirmek

CNN'ler temelde görüntü işlemede, resim üzerinde $3 \times 3$, $5 \times 5$ gibi bir matrisin evrişim (convolution) işlemiyle gezdirilmesiyle kullanılır. Hoca, buna benzer bir şeyin metinler için de mümkün olduğunu söyledi ve slayttaki yapıyı anlattı. Slayttaki tarif şöyledir (ekrandan, 00:30:00):

- M matrisi: metin ($n_m$ satır, $d_m$ sütun).
- $d_m$: kelimelerin temsil edildiği vektörlerin boyutu.
- Metnin her bir kelimesine karşılık gelen vektörler metindeki sıralarıyla bu matrisin bir satırına yazılır.
- $n_m$: maksimum metin uzunluğu. Eğer bir metin bu değerden kısa ise matrisin geri kalan alt kısmı 0'larla doldurulur (padding).
- M matrisinin üzerinde $t$ adet $k_m \cdot d_m$'lik filtre gezdirilir ve evrişim sonuçları F'de tutulur. F'nin her bir sütunu bir filtrenin sonuçlarını göstermektedir.
- Her bir sütunun maksimum değeri bulunup B vektörüne yazılmaktadır.
- B vektörü ile S çıkış vektörü arasında ise tam bağlı bir katman bulunmaktadır.

Slayttaki şekil bu akışı soldan sağa M, F, B ve S olarak çizer: M matrisinin üzerinde mavi bir çerçeve (filtre) vardır; F evrişim sonuçlarını, B sütun maksimumlarını, S çıkışı gösterir.

### 5.3 Filtreler neden yalnız aşağı kayar?

Resim bir matristir ve üzerinde filtre gezdirilebilir. Metni de matrise çevirdik; ama burada her satır, örneğin 300 boyutlu uzun bir kelime vektörüdür. Böyle bir satırın üzerinde $3 \times 3$ ya da $5 \times 5$ filtre gezdirmek çok mantıklı değildir. Onun yerine filtrenin genişliği tokenların temsil edildiği uzayın boyutu kadar alınır: her kelime 300 boyutluysa $2 \times 300$'lük filtreler gezdirilir. Resimlerden tek farkı, filtrenin hem satırda hem sütunda değil, yalnız satırlar boyunca (aşağı doğru) kaydırılmasıdır; sütun sabittir.

Bu durumda iki satırlık bir filtre aslında kelime ikililerini ifade eder; filtre, belirli kelime ikililerinin ya da onların temsillerine benzeyen ikililerin metinde olup olmadığını gösterir. Filtre üç satırlık yapılırsa kelime üçlüleri üzerinden çalışır. Ardından pooling işlemleri gelir.

### 5.4 Kelime tabanlı ve karakter tabanlı M matrisi

Token kelime olarak alınabilir. Slayttaki örnek (ekrandan, 00:40:00 sol panelde küçük resim; anlatım 00:32:58) şöyledir: "Allah cezanı versin XXX tüm müşterilerini kaybedersin inşallah." için M matrisleri; sol kelime vektörü tabanlı, sağ karakter tabanlı.

Kelime tabanlı matriste 100 boyutlu kelime vektörleri (word2vec vb.) kullanılmıştır. İlk satırdaki vektör ilk kelimeyi, ikinci satırdaki ikinci kelimeyi gösterir. Hoca, matrisin üst kısmında 9 dolu satır görüldüğünü, geri kalan kısmın sıfırlardan oluştuğunu söyledi.

Aynı iş karakter tabanlı da yapılabilir. Bu kez tokenlar karakterdir: ilk satır ilk karakteri ("A"), ikinci satır "L"yi gösterir; ikinci ve üçüncü satır aynıdır ("LL"). Ardından "A", "H", boşluk (onun da bir kodu vardır), "C", "E" vb. gelir. Bütün yorumlarda 80 küsur karakter bulunduğu için (hoca daha sonra 84 boyut dedi) her karakter bu boyutta one-hot bir vektörle temsil edilir. Karakter tabanlı matriste evrişim yapılınca filtreler kelime ikilileri yerine karakter n-gramlarına (örneğin karakter ikililerine) karşılık gelir. Hoca, bu durumda daha fazlasını yakalayabilmek için biraz daha büyük filtreler kullanmanın daha makul olabileceğini söyledi.

## 6. Karşılaştırma Sonuçları ve Harici Bilgi

### 6.1 Sonuç tablosu

Slayttaki "Karşılaştırma Sonuçları" tablosu şöyledir (ekrandan, 00:36:00):

| Yöntem | Elde edilen en yüksek başarı % |
|---|---|
| Kelime torbası | 66.28 |
| Karakter 3gram torbası | 66.92 |
| Kelime vektörü ortalamaları | 66.33 |
| Kelime bazlı Uzun kısa süreli bellek ağları | 65.35 |
| Kelime bazlı evrişimsel sinir ağları | 67.14 |
| Karakter bazlı evrişimsel sinir ağları | 69.25 |

Slaytın altında "Son 3 yaklaşımın çok fazla hiper parametresi var." yazar. Hoca tabloyu şöyle yorumladı: standart kelime torbası (tf-idf vb.) yaklaşık %66 verir. Karakter 3-gram torbası (CNN olmadan) ve kelime vektörlerinin ortalaması (fastText vb.) da %66 civarındadır. LSTM burada çok işe yaramamıştır. Kelime bazlı ve karakter bazlı evrişimsel ağlar daha başarılıdır; karakter bazlı olan bir tık daha iyidir.

### 6.2 Ön eğitimli modeller ve harici bilgi

Hocaya göre bu veri kümesinde alınan en iyi sonuçlar, Transformer modelleriyle yapılan sonraki araştırmalardan gelir; hocanın "herhalde" diyerek verdiği tahmine göre BERTurk gibi Türkçe bir model kullanıldığında %75 civarına erişilebilmektedir. Ancak hoca bunun yalnız Transformer mimarisinin kullanılmasından kaynaklanmadığını vurguladı: BERTurk eğitilirken arka tarafta kocaman bir ön derlem kullanılır ve model oradan elde edilen bilgiyi taşır.

Tablodaki yapılarda ise, özellikle karakter tabanlı CNN'de, hiçbir harici bilgi kaynağı yoktur; elde yalnız veri kümesi vardır. Ön eğitimli modelleri kullanmak aslında harici bilgi kullanmak demektir. Daha fazla bilgi kullanmak da doğal olarak daha yüksek performans getirir.

## 7. Duygu Durum Analizi Zordur

Slaytın başlığı "Duygudurum analizi zordur ☺"dur ve şu üç cümleyi gösterir (ekrandan, 00:40:00):

- Yemeğimi 5 dakikada getirdiniz çok teşekkürler.
- Yemeğimi 55 dakikada getirdiniz çok teşekkürler
- 2500 tl lik fatura için çok teşekkürler

İlk iki cümle arasında tek bir karakter farkı vardır. Buna rağmen ilki olumlu bir şey söylerken ikincisi olumsuzdur: müşteri memnun değildir, "55 dakikada yemek mi getirilir" diye yazmak yerine iğnelemeli bir teşekkür etmektedir. "2500 TL'lik fatura için çok teşekkürler" de benzer bir iğnelemedir.

Hocaya göre bunları karakter bazlı yapılarla ya da yalnız sözdizimine (sentaktik olarak) bakarak anlamak mümkün değildir, çünkü iki cümle arasında tek bir karakter farkı vardır ve birine olumlu, diğerine olumsuz denmesi gerekir. Sistemin, bir yemek getirme işinin normalde ne kadar sürdüğü gibi bir bilgiye ihtiyacı vardır ve bunu yorumlayarak karar vermesi gerekir.

Hoca ardından ChatGPT'nin bu ayrımı Türkçe olarak yapıp yapamayacağını sordu ve öğrencilerden önce tahmin etmelerini, sonra denemelerini istedi (bkz. Örnek Sorular). Benzer örneklerin de denenebileceğini söyledi.

## 8. Varlık İsmi Tanıma

### 8.1 Tanım

Varlık ismi tanıma (Named Entity Recognition, NER), bir metnin içindeki önceden tanımlanmış varlıkları ve türlerini bulmaktır. Slayttaki maddeler şöyledir (ekrandan, 00:40:00 sol paneldeki küçük resim; anlatım 00:41:29):

- Bir metnin içindeki önceden tanımlanmış varlıkları ve türlerini bulmak.
- Sekans2sekans mimariler.
- Klasik yaklaşım CRF.
- Burada karakter tabanlı LSTM.
- Giriş: karakter one-hot vektörleri.
- Çıkış: karakterin sınıfı.

Hocanın okuduğu örnek metin şudur: "Akbank 8. Caz Festivali 8-21 Ekim tarihleri arasında İstanbul, Ankara ve Adana'da caz ustaları ile müzikseverleri buluşturacak; festivalin İstanbul'daki açılışını vokal ve piyano virtüözü Brezilyalı sanatçı Tania Maria yapacak." Bu metnin içindeki kurum isimleri (Akbank), yer isimleri (İstanbul, Ankara, Adana), kişi isimleri ve tarihler bulunmak istenir. Hangi varlıkların bulunacağı sizin tanımınıza kalmıştır; tanımladığınız varlıklar eğitim kümesine dahil edilir. Kısacası soru şudur: bu metnin içinde ne tür varlıklar var ve bunlar neredeler?

<!-- BELİRSİZ: Örnek metin altyazıdan kurulmuştur ("asistörünü", "oluşturarak" gibi bozuk kelimeler "açılışını", "buluşturacak" diye okunmuştur); slayttaki tam metin karede okunamadı. -->

### 8.2 Giriş ve çıkışın kodlanması

Elimizde bir metin vardır ve bu metinden aslında yeni bir metin (bir sekans) üretilmesi istenir: bir cümle girer, dışarıya bir cümle çıkar. Giriş tarafı kolaydır, metnin kendisidir. Çıkış olarak ise her token için, bir varlık ismiyse onun sınıfını ifade eden bir etiket kullanılır. Örneğin "Akbank" geldiğinde çıkış kurumu (ORG) göstermelidir. "8. Caz Festivali" geldiğinde ise modelin bir şey yapmamasını isteriz; ama yine de dışarıya bir etiket vermemiz gerekir. Bu yüzden "hiçbir sınıfa dahil değil" anlamına gelen bir etiket de olmalıdır (O, no, null vb.; adı size kalmıştır).

Dersin web sayfasındaki kodlarda bu mimari kurulurken girişe karakterler, çıkışa da her karakterin sınıfı verilmiştir. "Akbank" tek seferde değil, "A", "K", "B", "A", "N", "K" diye karakter karakter verilir; sonra boşluk, "8", nokta, boşluk vb. gelir. Her girişe karşılık çıkışta, "Akbank" kelimesi boyunca bunun ORG sınıfından olduğunu gösteren one-hot bir vektör bulunur. Girişteki karakterler de one-hot kodlanmıştır; bu, kelime tabanlı değil karakter tabanlı bir yaklaşımdır ve boyutu Bölüm 5'teki gibi eğitim kümesindeki karakter sayısı kadardır (84 boyut). Model olarak karakter tabanlı LSTM kullanılmıştır. Hoca CRF'lerin de bu işte başarıyla kullanıldığını söyledi, ama ayrıntısına girmedi.

### 8.3 Sonuçlar

Bu yapılar üç sınıflı ve yedi sınıflı iki NER problemi üzerinde çalıştırılmıştır. Üç sınıflı problemde sınıflar kurum (organization), yer (location) ve kişidir. Yedi sınıflı problemde bunlara tarih (date), yüzde (percentage), para (money) ve zaman (time) eklenir. Hoca performansların fena olmadığını söyledi: varlık olmayan kısımlar zaten çok yüksek olasılıkla doğru bulunur; varlık olan kısımlarda da performans iyidir, ama bütün sınıflarda eşit değildir.

## 9. Varlık İsmi Tanıma ile Makine Çevirisinin Karşılaştırılması

Varlık ismi tanıma, çok temel olarak sekanstan sekans üretilmesi gereken bir problemdir; makine çevirisi gibi düşünülebilir. Hoca sınıfa ikisi arasındaki farkı sordu ve kendisi cevapladı.

Birinci fark uzunluktur. Varlık ismi tanımada girişteki token sayısı ile çıkıştaki token sayısı eşittir; metindeki her tokena "varlık değildir" ya da "şu tür bir varlıktır" demek gerekir. Makine çevirisi de sekanstan sekansa bir iştir, ama orada giriş sekansının boyu ile çıkış sekansının boyu aynı olmak zorunda değildir.

İkinci fark sınıf sayısıdır. Varlık ismi tanımada çıkışta kabaca 3-5 (ya da 7) sınıf vardır. Makine çevirisinde ise sınıf sayısı hedef dilde kullanılan sözlüğün boyutu kadardır: çıkış softmax'tan geçirilip kelime dağılımına çevrildiğinde, hedef dilde 32 bin token varsa 32 bin sınıflı bir problem çözülüyor demektir.

> **Hocanın vurgusu:** Sekanstan sekansa yaklaşımlarda çok daha enteresan bir problem çözülmez; yine bir sınıflandırma problemi çözülür. Elde bir vektör vardır ve bu vektör 32 bin (ya da 64 bin) sınıftan hangisine denk geliyor sorusu cevaplanır. Sınıf sayısı sözlük boyutu kadardır, ama yaklaşım olarak farklı bir şey yoktur.

Hoca paragraf anlama kısmına bu derste girmedi; bunun soru cevaplamayla çok yakından ilişkili olduğunu ve sonraki derste konuşulacağını söyledi.

## 10. Sıfır Çekimli Sınıflandırmada Prompt Analizi: Öğrenci Sunumları

Aradan sonra öğrenciler, sıfır çekimli (zero-shot) sınıflandırmada prompt'ların etkisini inceledikleri çalışmaları sundu. Bu bölüm sunumlardaki akademik içeriği ve hocanın yorumlarını toplar; sunanlar "bir öğrenci" diye anılır. Bazı sunumların İngilizce kısımları altyazıda büyük ölçüde bozuktur; bu kısımlardan yalnız okunabilen ya da ekranda görülen içerik alındı.

<!-- BELİRSİZ: 01:06-01:16, 01:40-01:48, 01:49-01:58 ve 03:43-03:53 arasındaki İngilizce sunumların altyazısı tekrar eden halüsinasyon satırlarıyla doludur; bu sunumların sayısal sonuçlarının çoğu okunamadı. -->

### 10.1 Ortak yöntem

Sunumların çoğunda düzen şuydu: her sınıf için birkaç (çoğunlukla beş) prompt yazılır. Prompt'lar ve test metinleri bir dil modelinden geçirilerek vektörlere çevrilir. Her test metni, temsili en benzer prompt'un (ya da prompt grubunun) sınıfına atanır. Benzerlik ölçüsü çoğunlukla kosinüs benzerliğidir; bir öğrenci Öklid uzaklığını, bir başkası Öklid, Manhattan ve kosinüsü birlikte denedi ve en başarılı olan kosinüsle devam etti. Model hiç eğitilmez; başarı, sınıflandırma doğruluğu (accuracy) ya da F1 ile ölçülür.

Kullanılan veri kümeleri iki gruptandır. Konu sınıflandırma için BBC News (5 sınıf: tech, business, sport, entertainment, politics; toplam 2225 satır), AG News (4 sınıf: World, Sports, Business, Sci/Tech), 20 Newsgroups'tan seçilmiş 5 konu, 7 ve 10 sınıflı Türkçe ve İngilizce haber kümeleri ve Interpress Türkçe haber kümesi kullanıldı. Duygu analizi için IMDB, Rotten Tomatoes, Yelp, restoran yorumları, TripAdvisor otel yorumları, Türkçe tweet'ler, beş duygulu (anger, fear, joy, love, sadness) bir küme ve EMO2019 kullanıldı.

Kullanılan modeller arasında BERT, RoBERTa, ALBERT, ELECTRA, XLNet, GPT-2, Sentence Transformers hub'ında yayımlanmış ve cümle benzerliği için kontrastif amaçla ince ayarlanmış MPNet tabanlı modeller, T5 tabanlı bir cümle modeli, fastText, word2vec ve NLI modelleri (BART, DeBERTa, Türkçe BERT tabanlı bir NLI modeli, çok dilli mDeBERTa) vardı.

### 10.2 Prompt üretme yöntemleri

Sunumlarda denenen prompt üretme yolları şunlardır:

- Yalnız sınıf adı (temel karşılaştırma için).
- Sınıf adına önek eklemek: "text is about ...", "this article is about ..." gibi.
- Sınıfın sözlük tanımı (bir öğrenci dictionary.cambridge.org'daki tanımları kullandı; ekrandan, 01:10:00).
- Bir anahtar kelime API'sinden (wordsapiv1) sınıfa ait anahtar kelimeleri almak (ekrandan, 01:10:00).
- Terim frekansı ve TF-IDF ile sınıfa özgü kelimeleri seçmek.
- POS etiketiyle yalnız isim, sıfat ve fiilleri tutmak.
- word2vec ile sınıf adına en benzer kelimeleri almak.
- WordCloud ile her sınıfın en sık kelimelerini çıkarmak.
- Kelime n-gram'larını (2, 3, 4, 5 ve karışık uzunlukta) prompt olarak kullanmak.
- Elle, doğal dilde anlamlı cümleler yazmak.
- Diğer yöntemlerin en iyi kelimelerini GPT'ye verip cümle ürettirmek.
- Genetik algoritmayla prompt optimizasyonu.

Bir öğrencinin ekranındaki örnek, bütün sınıflarda ortak en sık 50 kelime çıkarıldıktan sonra kalan TF-IDF kelimeleridir (ekrandan, 01:20:00):

```text
AG News Prompts
  World (0):     minister killed palestinian election iraqi
  Sports (1):    team season night cup victory
  Business (2):  profit sale percent share corp
  Sci/Tech (3):  software internet search computer space
Rotten Tomatoes Prompts
  Positive (1):  still documentary entertaining great heart
  Negative (0):  long script better every action
```

Aynı öğrenci önce terim frekanslarıyla başladığını, temizlemeye rağmen istenmeyen kelimelerin öne çıktığını (örneğin bir haber ajansının adının iki sınıfta geçmesi) ve bu yüzden TF-IDF'e geçip sınıflar arasında ortak geçen 50 kelimeyi elediğini anlattı. Duygu analizinde word2vec ile seçilen kelimelerin tamamen olumlu ya da tamamen olumsuz kelimelerden oluştuğunu, bunun da kötü bir yanı olabileceğini söyledi.

Genetik algoritma denemesi şöyle kurulmuştu (ekrandan, 01:30:00): TF-IDF'te en yüksek skoru alan ilk 100 kelime arasından rastgele seçilen kelimelerle (birey başına 8 terim) başlangıç popülasyonu oluşturulur; uygunluk (fitness), bir örneklem üzerindeki sınıflandırma başarısıyla ölçülür; en iyi bireyler bir sonraki neslin ebeveynleri olur; çaprazlama ve mutasyonla yeni prompt nesilleri üretilir. Slayta göre algoritma yeterince hızlı yakınsamadığı için sonuçlar ana analize eklenmemiştir.

### 10.3 Öne çıkan bulgular

**Cümle modelleri ham BERT'ten iyi.** Bir öğrencinin deneyinde yalnız sınıf adı kullanıldığında BERT'in başarısı çok düşüktü; "text is about" öneki eklenince yaklaşık %10'dan %28'e çıktı; konu tanımı ve anahtar kelimelerle daha da arttı. Cümle benzerliği görevlerinde ince ayarlanmış cümle modelleri (MPNet, T5 tabanlı model) ince ayarsız BERT'ten daha iyi sonuç verdi. Hoca iki veri kümesindeki ortak noktayı şöyle özetledi: kontrastif öğrenmeyle ön eğitilmiş cümle (sentence) modelleri daha iyi sonuç vermiştir. Ayrıca bazı prompt'ların bazı sınıflar için, başka prompt'ların başka sınıflar için daha iyi çalıştığı gözlendi.

**Veri kümesine özgü kelimeler.** Bir öğrenci, BBC'nin İngiliz kaynaklı bir haber kuruluşu olduğundan, spor sınıfı için genel kelimeler (basketbol, futbol, tenis) yerine İngiliz futboluna özgü adlar (Alex Ferguson, Chelsea, Arsène Wenger) kullanınca başarının arttığını gördü. Üç kelimelik genel prompt'larla genel başarı %42 iken, oraya özgü kelimelerle %53,8'e çıktı. Kelime sayısı açısından en yüksek başarı 4-5 kelimelik prompt'larda geldi (BERT'te %65,8; ELECTRA'da 4 kelimede %42,4); öğrenci bunu anlamlı bir cümle için gereken en az kelime sayısına bağladı. Ancak Türkçe tweet'lerden oluşan duygu kümesinde (tweet'lerin çoğu turizmle ilgiliydi) konuya özgü prompt'lar başarıyı düşürdü; genel olumlu, olumsuz ve nötr cümleler daha iyi çalıştı. Öğrencinin açıklaması: haber sınıflarında sınıflara özgü kelimeler farklıdır, ama duygu analizinde olumlu ve olumsuz cümleler aynı konudan bahseder.

**Kelime yığını ve anlamlı cümle.** Bir öğrenci prompt olarak cümle yerine kelime listeleri verdi (kelimeleri yan yana koyup temsil almak, aslında vektörlerin ortalamasını almaya benzer). Yöntemleri şöyleydi: sınıf adı (BERT %17, GPT-2 %15), word2vec ile benzer kelimeler (BERT %18), TF-IDF (BERT %25, GPT-2 %16), Count Vectorizer (BERT %19, GPT-2 %18) ve WordCloud. WordCloud sonuçları ekranda şöyledir (ekrandan, 02:20:00): 7 sınıflı haber kümesinde BERT 0.1902, GPT-2 0.2006; iki sınıflı duygu kümesinde BERT 0.536, GPT-2 0.527. Öğrenci word2vec'in zayıf kalmasını, veri kümesine bakmadan yalnız sınıf adına en yakın kelimeleri bulmasına bağladı; TF-IDF, Count ve WordCloud ise veri kümesinin kendisine bakar. Duygu analizinde başarıyı %50'nin üzerine çıkarmakta zorlandı.

Hoca bu sonucu şöyle yorumladı: anlamlı bir birliktelik oluşturmayan kelime kümeleri bu tür dil modelleriyle çok iyi temsil edilemiyor gibi görünüyor. Modeller eğitimde böyle girdilerle pek karşılaşmamıştır; bu yüzden onlar için iyi temsiller oluşturamıyor olabilirler.

Başka bir öğrenci de restoran yorumlarında yemek ve servisten bahseden prompt'ları denedi. BERT'te "bu görüş pozitiftir/negatiftir" ile %87 aldı; en iyi sonucu "bu restoranı sevdim/sevmedim" prompt'u verdi. GPT'de en iyi sonuç "bu restoran güzel yemek yapar/kötü yemek yapar" prompt'undan geldi. Haber kümesinde sınıf etiketinin adını içeren prompt'ların daha iyi çalıştığını gözledi.

**NLI tabanlı sıfır çekimli sınıflandırma.** Bir öğrenci NLI (doğal dil çıkarımı) için eğitilmiş BART ve DeBERTa modellerini kullandı. Bu modellere girdi olarak bir öncül (premise) ve bir hipotez verilir; çıktı üç sınıftır: çelişki (contradiction), gerektirme (entailment) ve nötr. Öncül veri kümesindeki metin, hipotez ise prompt'tur (örneğin "Text is written by a happy person."). Öğrenci yalnız gerektirme olasılığına bakıp 0.80 eşiğini geçeni doğru kabul etti. EMO2019 kümesinin "Happy" sınıfı için sonuçlar şöyledir (ekrandan, 02:30:00):

| Prompt | BART | DEBERTA |
|---|---|---|
| Text is written by a happy person. | %70 | %9 |
| I feel delighted, contented, cheerful and pleased. | %54 | %4 |
| I see the joy in your eyes and smile in your face. | %28 | %24 |
| I laughed a lot, best day of my life. | %16 | %42 |
| I am very excited and have positive feelings about this. | %66 | %1 |

Öğrencinin gözlemi: BART basit ve sıralı cümlelerde daha iyi sonuç verdi; DeBERTa'da kelime sırasının pek önemi olmadığını, daha karmaşık ve uzun cümlelerde daha başarılı olduğunu fark etti. Hoca, eşik yerine en yüksek gerektirme skorunu veren prompt'un sınıfının seçilebileceğini söyledi (bkz. Örnek Sorular). Öğrenci prompt'larda bagging ve boosting ile iki modelden farklı şekillerde yararlanılabileceğini düşündüğünü söyleyince hoca, birbirini tamamlayan yapıları olan modellerin bir topluluk (ensemble) içinde kullanılmasının daha iyi sonuç verebileceğini tahmin ettiğini belirtti.

Başka bir öğrenci de Türkçe haber kümesinde (Interpress, 10 kategori, tabakalı örneklemle 5000 örnek) bir makaledeki çalışmayı Türkçe BERT tabanlı bir NLI modeliyle tekrarladı; Türkçe duygu tweet'lerinde (kızgın, korku, mutlu, sürpriz, üzgün) çok dilli mDeBERTa'yı kullandı. Haber kümesinde en iyi prompt'ta kültür-sanat ve eğitim sınıflarının F1 skoru çok düşük, sağlık sınıfınınki yaklaşık %83 oldu.

**Maskeli dil modeli ile sınıflandırma.** Bir öğrenci üç yöntem denedi. Birincisinde BERT'in CLS çıktısına eğitilmemiş bir sınıflandırıcı katmanı ekledi; bu katman eğitilmediği için duygu analizinde %50 civarı sonuç verdi, haber kümesinde hep aynı sınıfı önerdi. İkincisinde prompt'taki sınıf kelimesini [MASK] ile değiştirdi; model maske yerine sözlük boyutunda (yaklaşık 32 bin) bir skor vektörü verir. Ekrandaki şekil BERT maskeli dil modelini gösterir (ekrandan, 02:50:00):

```text
Input : [CLS] how are [MASK] today doing [SEP]
          |    |   |    |      |     |     |
        +--- BERT masked language model ---+
          |    |   |    |      |     |     |
Output: [CLS] how are  ???   today doing [SEP]
        "you has the highest probability: you, they, your, ..."
```

Her sınıf için önceden seçilmiş kelimelerin skorları toplanır; örneğin film yorumlarında good ve positive skorları toplanıp bad ve negative skorlarının toplamıyla karşılaştırılır, büyük olan sınıf seçilir. Bu yöntem %70 civarı bir sonuç verdi, ama 32 bin boyutlu çıktı içinde seçim yapıldığı için çok yavaştı. Üçüncü yöntemde BERT'in sonraki cümle tahmini (NSP) başlığını eğitmeden kullandı: hem olumlu hem olumsuz prompt'la %97 civarı "ardışık" çıktısı aldı; yani model yalnız "bu cümle öncekinden sonra gelebilir" diye yorumluyordu ve sınıflar ayrışmadı. Hoca, cümle benzerliği yöntemini kullanmanın daha sağlıklı olacağını belirtti.

**N-gram prompt'lar.** Bir öğrenci her sınıfta en sık geçen n-gram'ları prompt olarak seçti; sık kelimeler (am, is, are, was, were, and, the) ve belirli kısaltmalarla başlayan ya da biten öbekleri dışarıda bıraktı, bir prompt'un diğerini içermesini engelledi ve kökleme (stemming) de denedi. Üçlü n-gram'larla (3,3) sonuçlar şöyledir (ekrandan, 03:40:00): haber kümesinde ALBERT 0.4228, BERT 0.3684; duygu kümesinde ALBERT 0.3645, BERT 0.3719. Ekrandaki notta, kelime sayısı arttıkça başarının yükselip yükselmediğine bakmak için üçlü n-gram'ların seçildiği, ama ikili n-gram'lara göre genel olarak bir düşüş gözlendiği yazar. Üçlülerde "world" kelimesi dört haber sınıfında da geçtiği için ayırt edici olmadığı fark edilip "world" ile başlayan prompt'lar sonraki denemelerde dışlandı.

**Prompt sayısı ve ince ayar.** Bir başka öğrenci (BERT ve XLNet), birden fazla prompt'un bir arada kullanılmasının tek bir prompt'a güvenmekten daha iyi çalıştığını ve modellerin bu tür görevlerde ince ayarla (fine-tuning) daha iyi sonuç verebileceğini sonuç olarak verdi; XLNet'in skorları genel olarak 0.45-0.5'in altında kaldı.

### 10.4 Hocanın değerlendirme üzerine uyarıları

Birkaç sunumda hoca sonuçların nasıl sunulduğunu sorguladı. Bu uyarılar sıfır çekimli değerlendirmenin nasıl yapılacağına dair akademik noktalardır.

Bir öğrenci fastText ve BERT ile her duygu sınıfındaki bütün örneklerin prompt'a kosinüs benzerliklerinin ortalamasını raporlamıştı; fastText'te bütün değerler 0,99'un üstünde ve birbirine çok yakındı. Hoca, sonuçların hepsinin bu kadar benzer olmasının gürültüyü aşacak bir sinyal olmadığını, büyük olasılıkla hesaplamada bir yerde bir problem bulunduğunu söyledi. Ayrıca ortalama benzerliğin bir sınıflandırma başarısı olmadığını vurguladı: sıfır çekimde bir metin verilir, model eğitim olmadan sınıfını tahmin eder ve doğru mu yanlış mı bildiğine bakılır. Sonuç, örneğin "1000 örneğin şu kadarı doğru sınıflandırıldı" biçiminde, her prompt ya da en iyi prompt için sınıflandırma skoru olarak verilmelidir.

Bir başka öğrenci beş prompt'un temsillerinin ortalamasını o sınıfın temsili gibi kullandı. Hoca bunun prompt'ları birbiriyle karşılaştırmayı engellediğini sordu. Aynı öğrencinin dengeli iki sınıflı bir otel yorumu kümesinde %32 başarı alması üzerine hoca, rastgele tahminin bile %50 vereceğini ve tahminlerin tersi söylenirse başarının %68 olacağını belirtti (bkz. Örnek Sorular). Bir başka sunumda da iki sınıflı bir kümede %11-17 civarı "başarı" raporlanınca hoca aynı noktayı sordu ve öğrenci bir hata yaptığını fark etti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:15:22): Test örnekleri sabitken eğitim örneklerinin sayısını arttırınca test kümesi üzerindeki başarı neden artar?

> **Cevap (derste verildi):** Eğitim kümesi büyüdükçe test kümesindeki örneklere benzeyen örneklerin eğitim kümesinde bulunma ihtimali artar; eğitim dağılımı test dağılımına yaklaşır. Uç örnek olarak test kümesinin kendisiyle eğitim yapılsaydı test başarısı %100'e yaklaşırdı. Bu yüzden kaliteli veriyle eğitim kümesini büyütmek performansı arttırmanın en garantili yoludur.

**Soru 2** (ekrandan, 00:40:00; derste sözlü, 00:40:00): "Yemeğimi 5 dakikada getirdiniz çok teşekkürler." ve "Yemeğimi 55 dakikada getirdiniz çok teşekkürler" cümlelerinden birincisine olumlu, ikincisine olumsuz diyebilmek için bir sistemin neye ihtiyacı vardır? ChatGPT bunu Türkçe olarak ayırt edebilir mi?

> **Cevap (derste verildi, ilk kısım):** İki cümle arasında tek karakter farkı vardır; yalnız sözdizimine ya da karakterlere bakarak ayırt edilemez. Sistemin bir yemek getirme işinin normalde ne kadar sürdüğünü bilmesi ve bunu yorumlaması gerekir. ChatGPT kısmı derste cevaplanmadı; hoca öğrencilerden önce tahmin etmelerini, sonra kendilerinin denemelerini istedi.

**Soru 3** (derste sözlü, 00:47:09): Varlık ismi tanıma ile makine çevirisi, ikisi de sekanstan sekansa problem olduğu halde, nasıl farklıdır?

> **Cevap (derste verildi):** Varlık ismi tanımada giriş ve çıkıştaki token sayıları eşittir, her tokena bir etiket verilir; makine çevirisinde uzunluklar farklı olabilir. Varlık ismi tanımada çıkışta 3-5 (ya da 7) sınıf vardır; makine çevirisinde sınıf sayısı hedef dilin sözlük boyutu kadardır (örneğin 32 bin). Yine de ikisinde de her adımda bir vektör bir sınıfa atanır, yani ikisi de sınıflandırmadır.

**Soru 4** (derste sözlü, 02:31:21): NLI tabanlı sıfır çekimli sınıflandırmada gerektirme olasılığı için 0.80 eşiği kullanılıyorsa ve hiçbir prompt bu eşiği geçmezse ne olur? Daha iyi bir karar kuralı nedir?

> **Cevap (derste verildi):** Eşik kuralında böyle bir örnek yanlış sayılır. Hocanın önerisi, eşik yerine bütün sınıfların prompt'ları için gerektirme skorlarına bakıp en yüksek skoru veren prompt'un sınıfını seçmektir; böylece her örnek bir sınıfa atanır.

**Soru 5** (derste sözlü, 03:24:34): Sınıf dağılımı yaklaşık %50'ye %50 olan iki sınıflı bir veri kümesinde sıfır çekimli bir yöntem %32 doğruluk veriyorsa bu ne anlama gelir?

> **Cevap (derste verildi):** Rastgele tahmin bile yaklaşık %50 verir; bir sınıfın tamamını yanlış yapan bir model de %50 alır. %50'nin belirgin altında bir doğruluk, yöntemde bir hata olduğunu gösterir. Tahminler ters çevrilirse doğruluk $100 - 32 = 68$, yani %68 olur.

**Soru 6** (derste sözlü, 03:02:38): Sıfır çekimli sınıflandırmada prompt'ların başarısı nasıl ölçülmelidir? Bir sınıfın bütün örneklerinin prompt'a ortalama kosinüs benzerliği yeterli bir ölçüt müdür?

> **Cevap (derste verildi):** Yeterli değildir. Sıfır çekimde her metin, eğitim olmadan bir sınıfa atanır ve doğru mu yanlış mı sınıflandırıldığına bakılır. Sonuç, örneğin her prompt ya da en başarılı prompt için doğru sınıflandırılan örneklerin oranı (doğruluk) ya da sınıf bazında F1 olarak verilmelidir.

## Dersin Toparlaması

Bu derste Bölüm 6'ya, yani doğal dil işlemenin uygulamalarına başlandı. Metin sınıflandırmada çok etiketli problemler için iki temel yaklaşım (tek model ve eşik, sınıf başına ikili model) ve eğitim kümesi büyüdükçe test başarısının neden arttığı tartışıldı. Duygu durum analizinde kamuoyu algısını ölçmenin ucuz ama bot gibi algı operatörlerine açık bir yol olduğu, eğitim kümesinin zamanla eskidiği ve güncellenmesi gerektiği anlatıldı. Metnin bir matris olarak temsil edilip üzerinde yalnız satır boyunca kayan filtrelerle CNN uygulanması, kelime ve karakter tabanlı temsillerin karşılaştırması ve ön eğitimli modellerin harici bilgi taşıdığı için daha yüksek başarı verdiği gösterildi. "5 dakika / 55 dakika" örneğiyle duygu analizinin dünya bilgisi gerektirdiği vurgulandı. Varlık ismi tanıma, her tokena bir etiket veren sekanstan sekansa bir sınıflandırma problemi olarak tanıtıldı ve makine çevirisiyle karşılaştırıldı.

Sunumlarda, önceki derslerde anlatılan sıfır çekimli öğrenme ve kontrastif öğrenmenin uygulaması görüldü: cümle benzerliği için kontrastif öğrenmeyle ince ayarlanmış modeller, anlamlı cümle biçimindeki prompt'lar ve veri kümesinden (TF-IDF gibi) türetilen kelimeler genelde daha iyi sonuç verdi; değerlendirmenin ise ortalama benzerlikle değil sınıflandırma başarısıyla yapılması gerektiği vurgulandı. Paragraf anlama ve soru cevaplama sonraki derse bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
