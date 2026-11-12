# Ders 3 Çalışma Özeti

## Genel Konular

- Geçen dersten bağlantı: hayat bilgisi veritabanları
  - Hayat bilgisi veritabanları "şu kavramla şu kavram arasında şu türden bir ilişki vardır" biçimindeki bilgileri tutar. Bunları toplamak için gönüllülerden yararlanan yaklaşımlar ve oyunlaştırma (CSoyun) konuşulmuştu.
  - Monotonik çıkarımın veritabanına yeni bilgi eklemek için pek katkısı yoktur: öncüller doğruysa sonuç zaten doğrudur, belki kontrol için kullanılabilir. Asıl katkı monotonik olmayan çıkarımdan gelir: olası ilişkiler tahmin edilir ve doğruluğu kullanıcılara sorulur.
- Bilgi çıkarımı (information extraction) nedir?
  - Yapısal olmayan bir kaynağı (düz metin) yapısal hâle (tablo, SQL veritabanı, Excel tablosu gibi) çevirmeye çalışmaktır. Yapısal kaynakta her hücrenin ne olduğu ve aynı satırdaki diğer hücrelerle ilişkisi bellidir; düz metinde bu ilişkiler verilmemiştir.
  - Slayttaki örnek (ekrandan, 00:11:50): "21 yaşındaki inşaat işçisi Kazım Yaprak, evine dönerken para meselesi yüzünden tartıştığı arkadaşı Hilmi Baker tarafından bıçaklanarak öldürüldü." cümlesinden Katil: Hilmi Baker, Kurban: Kazım Yaprak, Sebep: Para, Suç Aleti: Bıçak tablosu çıkarılır.
  - Ne işe yarar: veri üzerinde çok daha kolay işlem yapılır, veritabanı kurulabilir, istatistik çıkarılabilir. Bir milyon paragraftan bu tür bilgi çıkarılırsa metinleri okumadan hızlı ve sağlam istatistik elde edilir.
  - Bu yaklaşım hayat bilgisi veritabanlarını oluşturmak için de, başka amaçlar için de kullanılabilir.
- Bilgi çıkarımı yöntemleri
  - Düzenli ifadeler (regex): verideki düzenlilik ve varyasyonları kesin biliniyorsa kullanılır. Telefon numarası, posta kodu, e-posta adresi için regex yazmak kolaydır; adres gibi varyasyonu yüksek yapılar için tek bir regex yazmak zordur.
  - Yazım dilindeki şablonlar (ekrandan, 00:16:20): istenen ilişki türü için şablonlar bulunur, büyük metinlerde bu şablonlara uyan çiftler çıkarılır. "ve diğer" şablonunun solundaki ve sağındaki ifadeler genelde IsA ("bir tür") ilişkisindedir: "Gıda ve diğer mühendislikler", "Ses kayıtları ve diğer multimedya içeriği", "Spor ve diğer aktiviteler", "Dergiler ve diğer periyodikler", "Sözleşmeler ve diğer hukuki belgeler". Şablon her zaman doğru sonuç vermez ("güzel sanatlar bir tür konudur" pek anlamlı değildir).
  - Öğelerine ayrılmış metinler (ekrandan, 00:19:50): cümleler özne, nesne, yüklem gibi öğelerine ayrılabiliyorsa, "ye" fiilinin nesneleri yiyecek olarak sınıflandırılabilir. Basit hâli: "yerken" kelimesinden önceki kelimeleri almak. Sonuçlar: döner, kraker, zeytin, mantar (doğru); bir soyadı arama sayfasındaki "Yerken" (yanlış).
  - Dinamik web sayfalarından bilgi çıkarımı (ekrandan, 00:26:20): ürün karşılaştırma motorları ve alışveriş/haber toplama robotları, HTML kodundaki kalıplardan bilgi çıkarır. Amazon kitap sayfası örneğinde HTML'den Title, Author, List-Price, Price alanları çıkarılır.
- Şablonların iki özelliği: üretkenlik ve güvenilirlik
  - Üretkenlik: şablonla kaç bilgi (ikili, üçlü) elde edildiği. Güvenilirlik: üretilen bilginin doğruluğu.
  - İkisi birbiriyle çelişir. "X'in yeri Y'dir" için "x y nin sınırları içerisindedir" ile "x/y" şablonları karşılaştırıldı (ekrandan, 00:22:10): "x/y" çok daha üretkendir, "sınırları içerisindedir" çok daha güvenilirdir.
- Şablonların otomatik bulunması ve sonuçların makine öğrenmesiyle süzülmesi
  - Doğru olduğu bilinen 15-20 X-Y ikilisi aratılır; aralarındaki ifadeler şablon, kaç kez geçtikleri frekans olur; en yüksek frekanslı ifadeler o ilişkinin şablonları sayılır. Örnek: "tüm X'ler Y'dir" için "ve diğer", "ve benzeri", "veya diğer" gibi şablonlar.
  - Bulunan şablonlar Google'da aratılır; sonuç sayfalarında şablonun sağındaki ve solundaki kelimeler alınır ve dosyaya kaydedilir (ekrandan, 01:02:40).
  - Bazı ikililer doğru, bazıları yanlıştır (bazıları ters yönde çıkar). Önce insanlar ikilileri elle etiketler (human in the loop), sonra morfolojik yapıdan özellikler çıkarılıp makine öğrenmesiyle sınıflandırılır. Slayttaki ortalama sınıflandırma hataları (ekrandan, 01:03:45): AdaBoost ve Backpropagation yaklaşık 0,28; CART yaklaşık 0,13; Nearest Neighbor ve SVM yaklaşık 0,21. Hoca bunu yaklaşık %15 hata, %85 başarı diye özetledi.
  - Büyük dil modellerinin hayat bilgisini içerip içermediği ve içermiyorsa veritabanının modele nasıl katılacağı hâlâ araştırılan bir konudur. Slaytta 2018 tarihli Allen Institute for AI (AI2) girişimi Alexandria anılıyor (ekrandan, 01:04:50).
- İstatistiksel dil modelleri (yeni bölüm: anlamsal uzaylar)
  - Burada sinirsel değil, görece eski istatistiksel dil modelleri anlatılır. Bunlar büyük bir derleme ihtiyaç duyar.
  - Amaç 1: bir cümlenin olasılığını bulmak, $P(W)=P(w_1,w_2,\dots,w_n)$. Amaç 2: bir kelime dizisinden sonra gelecek kelimenin olasılığını bulmak, örneğin $P(w_5 \mid w_1,w_2,w_3,w_4)$ (ekrandan, 01:16:10).
  - Kullanım alanları (ekrandan, 01:10:00): makine çevirisi, $P(\text{taze balık aldım}) > P(\text{yeni balık aldım})$; yazım düzeltme, "Ali soğan yedi" ile "Ali sokan yedi"; konuşmadan metne çevirme, "soğan yedim" ile "sol an yedim".
  - Hoca PowerPoint'in yazım denetimini gösterdi: kelime tek başına doğruysa ("akanı") cümlede yanlış kullanılsa bile işaretlenmez. Cümle düzeyinde denetim için arkada bir dil modeli gerekir.
- Bayes ve zincir kuralı
  - $P(A \mid B)=P(A,B)/P(B)$, buradan $P(A,B)=P(B)P(A \mid B)=P(A)P(B \mid A)$.
  - Zincir kuralı: $P(A,B,C,D)=P(A)\,P(B \mid A)\,P(C \mid A,B)\,P(D \mid A,B,C)$. Genel hâli: $P(w_1,\dots,w_n)=P(w_1)P(w_2 \mid w_1)\cdots P(w_n \mid w_1,\dots,w_{n-1})$ (ekrandan, 01:20:00).
  - Bir olasılık frekanslardan bulunur: $P(\text{geldi} \mid \text{ali okuldan buraya}) = \dfrac{\text{frekans(ali okuldan buraya geldi)}}{\text{frekans(ali okuldan buraya)}}$. Değer 0 ile 1 arasındadır; aynı bağlamdan sonra gelen bütün kelimelerin olasılıkları toplamı 1'dir.
  - Sorun: güvenilir değerler için yeterince büyük derlem olmaz. Çoğu frekans 0 olur, çünkü dil ayrık (diskrit) uzayda çok seyrektir.
- Markov varsayımı (ekrandan, 01:21:20)
  - Her olasılık kendinden önceki $k$ bileşene bağlıdır.
  - $k=0$: her olasılık bağımsızdır, $P(w_1,w_2,w_3,w_4)=P(w_1)P(w_2)P(w_3)P(w_4)$, $P(\text{geldi} \mid \text{ali okuldan buraya})=P(\text{geldi})$.
  - $k=1$: her olasılık yalnız bir öncekine bağlıdır, $P(w_1,w_2,w_3,w_4)=P(w_2 \mid w_1)P(w_3 \mid w_2)P(w_4 \mid w_3)$, $P(\text{geldi} \mid \text{ali okuldan buraya})=P(\text{geldi} \mid \text{buraya})$.
  - Standart istatistiksel dil modeli $k=\infty$ varsayar.
  - Avantaj: kısa diziler derlemde daha olası bulunur, sıfırlardan büyük ölçüde kurtulunur; hesaplama ve bellek tasarrufu sağlanır.
  - Dezavantaj: uzak bağımlılıklar (long dependency) yakalanamaz. Örnek (ekrandan, 01:30:00): "XXX geçirdiğim süre içinde çok denedim ama bir türlü FFF öğrenemedim." XXX = Çin'de ise FFF = Çince ya da "Fuşi yapmayı"; XXX = Fransa'da ise FFF başka bir şey olur. Belirleyici kelime uzakta (bir romanda sayfalarca önce) olabilir.
  - Çözüm daha sonra görülecek sinirsel dil modelleridir: RNN'ler bir durum (state) içinde o ana kadarki kelimelerden bilgi tutarak teoride sonsuz uzunluktaki bağımlılıkları temsil edebilir.
- Seyreklik örneği (ekrandan, 01:33:00)
  - Kod `dil_modeli.m`, 1000 ekonomi haberi. 5'ten az geçen kelimeler silinince yaklaşık 8K kelimelik sözlük ve 8K×8K'lık matris elde edilir.
  - Yaklaşık 64M hücreden yalnız yaklaşık 140K'sı sıfır değildir. Dil çok seyrektir: her kelimeden sonra her kelime gelmez.
  - İki kelimeden sonra gelen kelime için 3 boyutlu bir küp gerekir: $64\text{M} \times 8\text{K} = 512$ milyar hücre, neredeyse hepsi sıfır. $k$ arttıkça seyreklik aşırı artar.
  - Olasılıklar her sorguda derlemde aranmaz; önceden çıkarılıp seyrek bir yapıda (örneğin hash) tutulur.
- Örnek çıktılar (ekrandan, 01:40:00)
  - "ekonomi"den sonra $P(w_i \mid \text{ekonomi})$ değeri en yüksek 5 kelime: bakanı, ve, ligi, bakanlığı, bankası.
  - "para"dan sonra: politikası, cezası, ve, birimlerinin. "çok"tan sonra: önemli, daha, büyük, sayıda, iyi.
- Bigram ile cümle olasılığı (ekrandan, 01:41:50)
  - $P(w_i \mid w_{i-1}) = \dfrac{fr(w_{i-1},w_i)}{fr(w_{i-1})}$.
  - "fuar otomotiv sektörüne önemli bir hareket getirdi" cümlesinin bigram olasılığı altı koşullu olasılığın çarpımıdır. Slayttaki logaritmik sonuç: $-21.2067$.
- Sıfırlarla baş etmek: yumuşatma (smoothing)
  - "önemli bir" yerine "önemli iki" yazılınca sonuç $-\infty$ olur, çünkü "önemli iki" (ya da "iki hareket") derlemde hiç geçmez.
  - Çözüm: payın her zaman 1 artırılması, paydaya sözlük boyutunun eklenmesi. Böylece hiçbir olasılık sıfır olmaz.
  - Yumuşatmayla "...önemli bir hareket getirdi" yaklaşık $-44$, "...önemli iki hareket getirdi" yaklaşık $-49$ bulundu.
- En olası dizilişi bulmak (ekrandan, 01:47:40)
  - "önemli, hareket, bir" kelimelerinin dizilişleri: önemli bir hareket $-11.8570$; önemli hareket bir $-18.1881$; bir önemli hareket $-17.4616$; bir hareket önemli $-16.8926$; hareket önemli bir $-13.0944$; hareket bir önemli $-17.4034$. En olası diziliş "önemli bir hareket"tir.
  - Yumuşatma olmasaydı dizilişlerin çoğu $-\infty$ çıkacak ve aralarında karşılaştırma yapılamayacaktı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Üretkenlik ile güvenilirlik birbiriyle çelişir
  - Çok sonuç döndüren şablon ("x/y") çok hata yapar; az sonuç döndüren şablon ("x y nin sınırları içerisindedir") daha güvenilirdir. İkisini birlikte iyileştiren şablon bulmak kolay değildir; gelen sonuçları ayrıca doğrulamak gibi teknikler kullanılır.
- Kelimenin tek başına doğru olması ile cümle içinde doğru olması farklıdır
  - Cümle düzeyindeki hatayı yakalamak bir dil modeli gerektirir. Bu modeller büyük oldukları için her yazım denetleyicide bulunmaz.
- Markov varsayımı işi pratikte yapılabilir hâlde tutar
  - $k$ üzerine hiçbir varsayım yapılmazsa gerçekçi bir derlemde doğru olasılık hesaplanamaz. $k$ bir yerde kesilmek zorundadır; bedeli uzak bağımlılıkların kaybıdır.
- Log olasılıklardaki küçük fark aslında büyüktür
  - $-44$ ile $-49$ arasındaki 5 birimlik fark, olasılıklar arasında yüzlerce katlık bir farktır. Log kullanılmasının nedeni, gerçek değerlerin "korkunç sıfırlı" küçük sayılar olmasıdır.
- Düşünme sorusu: 20 kelimelik bir kelime torbası verilse, istatistiksel dil modeliyle bu kelimelerin hepsini kullanan anlamlı bir cümle nasıl kurulur? Ne gibi sorunlarla karşılaşılır?

## Kısa Tekrar Notları

- Bilgi çıkarımı: yapısal olmayan metni yapısal (tablo) hâle getirmek.
- Yöntemler: regex, yazım dilindeki şablonlar ("ve diğer" → IsA), öğelerine ayrılmış metinler ("yerken" öncesi → yiyecek), HTML kalıplarından çıkarım.
- Şablonun iki ölçütü: üretkenlik (kaç bilgi) ve güvenilirlik (ne kadar doğru); ikisi çelişir.
- Şablonlar tohum ikililerden otomatik bulunabilir; çıkan ikililer insan etiketi ve makine öğrenmesiyle süzülebilir (yaklaşık %85 başarı).
- İstatistiksel dil modeli: cümle olasılığı $P(w_1,\dots,w_n)$ ve sonraki kelime olasılığı $P(w_n \mid w_1,\dots,w_{n-1})$.
- Kullanım: makine çevirisi, yazım düzeltme, konuşmadan metne.
- Zincir kuralı + frekans oranı → çoğu frekans 0 (dil seyrektir).
- Markov: olasılık önceki $k$ kelimeye bağlı. $k=0$ unigram, $k=1$ bigram. Küçük $k$: az sıfır, az maliyet; uzak bağımlılık kaybı.
- 8K×8K bigram matrisinde 64M hücreden yalnız yaklaşık 140K'sı dolu; trigram küpünde 512 milyar hücre.
- Bigram: $P(w_i \mid w_{i-1}) = fr(w_{i-1},w_i)/fr(w_{i-1})$; çarpım yerine log toplamı.
- Hiç görülmemiş bigram → olasılık 0 → log $-\infty$. Yumuşatma: paya 1, paydaya sözlük boyutu.
- En olası diziliş: bütün sıralamaların log olasılıklarını karşılaştır.

## Detaylı Açıklamalar

- Bilgi çıkarımının mantığı
  - Bir SQL tablosunda ya da Excel tablosunda her hücrenin anlamı ve aynı satırdaki diğer hücrelerle ilişkisi tasarımcı tarafından tanımlanmıştır. Düz metinde ise kim, kime, ne yaptı gibi ilişkiler açıkça verilmez. Bilgi çıkarımı bu ilişkileri metinden bulup tabloya yazmaktır. Suç haberi örneğinde katil, kurban, sebep ve suç aleti alanları tek bir cümleden doldurulur. Bu işlem milyonlarca paragrafa uygulanırsa, metinleri okumadan hızlı istatistik çıkarılabilir.
- Şablonlar ve iki ölçütü
  - Regex, rakam, harf ve karakter düzenine dayanır; varyasyonların bilindiği yapılarda çok iyi çalışır. Yazım dilindeki şablonlar ise kelimelere dayanır. "ve diğer" şablonu web aramasında aratıldığında solundaki ve sağındaki ifadeler büyük ölçüde "bir tür" ilişkisi verir; hoca bu tür şablonların ürettiği bilginin belki %80'inin doğru, kalanının yanlış olabileceğini söyledi. Şablon kalitesi ilişki türüne ve yazılan şablona göre değişir.
  - "x/y" şablonunda her eğik çizginin iki yanındaki kelimeler alınır; eğik çizgi binlerce farklı amaçla kullanıldığı için çok sonuç döner ama çoğu ilişkisizdir. "x y nin sınırları içerisindedir" az geçer ama geçtiğinde neredeyse her zaman doğru bir yer ilişkisi verir. Bu, üretkenlik ile güvenilirlik arasındaki çatışmanın tipik örneğidir.
- Web sayfalarından çıkarım ve tartışma
  - Ürün karşılaştırma motorları kullanıcının sorgusunu arka planda birçok siteye sorar ve dönen HTML sayfalarından ilgili alanları ayıklar. Bunun için her sitenin yapısına özel bir çıkarım mekanizması kurmak gerekir. Bazı siteler verilerinin bu şekilde kullanılmasını istemez ve sayfa yapısını sık değiştirerek çıkarım kodunun sürekli güncellenmesini gerektirir; trafik getiriyorsa ise API gibi yollarla erişim açabilir.
  - Hoca buradan üretici (generative) modellere geçti ve bir soru tartıştırdı: Stack Overflow ya da GitHub gibi yerlerdeki gönüllü içerik, kaynak gösterilmeden tek bir arayüzden yanıt olarak sunulursa insanlar içerik üretmeye devam eder mi? Öğrencilerden hem "azalır" (emek ve görünürlük karşılığı alınamaz) hem "azalmaz" (anonim yardımlaşma sürer) görüşleri geldi. Hoca, Google'ın kaynağı kullanıcıyı sayfaya yönlendirmek için gösterdiğini, bu sistemlerde ise amacın kullanıcıyı başka yere göndermemek olduğunu belirtti. Yanıtın hangi kaynaklardan üretildiğini göstermek açıklanabilir yapay zekâ (explainable AI) açısından kritik ama zor bir sorundur, çünkü yanıt tek bir kaynaktan değil birçok kaynağın öğrenilmesinden gelir.
- İstatistiksel dil modelinin hesabı
  - Bir cümlenin olasılığı zincir kuralıyla koşullu olasılıkların çarpımına ayrılır. Her koşullu olasılık frekans oranıyla tahmin edilir. Oran 0'dır, eğer bağlamdan sonra o kelime hiç gelmemişse; 1'dir, eğer bağlamdan sonra her seferinde o kelime gelmişse. Bir bağlamdan sonra gelen kelimelerin olasılıkları bir dağılım oluşturur.
  - Uzun bağlamlar derlemde birebir neredeyse hiç geçmez. Markov varsayımı bağlamı son $k$ kelimeyle sınırlar: $P(w_i \mid w_1,\dots,w_{i-1}) \approx P(w_i \mid w_{i-k},\dots,w_{i-1})$. Bağlam "paragraf" ya da "hikâyenin başı" da olabilir; olay, bir kelimenin kendinden önceki kaç token'a bağlı sayıldığıdır.
- Bigram örneğinin sayıları (ekrandan, 01:41:50)

| $w_i$ | $fr(w_{i-1})$ | $fr(w_{i-1},w_i)$ | $P(w_i \mid w_{i-1})$ |
|---|---|---|---|
| fuar | 18 | 1 | 1/18 |
| otomotiv | 78 | 4 | 4/78 |
| sektörüne | 35 | 1 | 1/35 |
| önemli | 560 | 162 | 162/560 |
| bir | 3940 | 4 | 4/3940 |
| hareket | 42 | 1 | 1/42 |

  - Tablodaki $w_i$ sütunu aslında önceki kelimeyi gösterir: "fuar" satırı $P(\text{otomotiv} \mid \text{fuar})=1/18$, "hareket" satırı $P(\text{getirdi} \mid \text{hareket})=1/42$ demektir.
  - Çarpım çok küçük olduğu için log alınır; çarpımın logu, logların toplamına eşittir. Ders sonrası not: tablodaki altı değerle hesaplanan doğal logaritma yaklaşık $-21{,}29$ çıkar (çarpım yaklaşık $5{,}69\times10^{-10}$); slayttaki $-21.2067$ değeri buna yakındır, küçük fark büyük olasılıkla slayttaki frekansların yuvarlanmış ya da farklı bir çalıştırmadan alınmış olmasındandır.
- Yumuşatmanın etkisi
  - Hoca bu yöntemi bir ekleyerek tahmin diye anlattı: $P(w_i \mid w_{i-1}) = \dfrac{fr(w_{i-1},w_i)+1}{fr(w_{i-1})+V}$, $V$ sözlük boyutu (yaklaşık 8000). <!-- BELİRSİZ: 01:47:20'de yöntemin adı "Edvan Estimation" diye bozuk çıkmış; büyük olasılıkla "add-one estimation" (Laplace). Formül altyazıdaki anlatımdan kuruldu, yumuşatma slaydı karede görülmedi. -->
  - Ders sonrası not: Hoca $-44$ ile $-49$ arasındaki farkı $e\approx3$ alarak $3^5$ ve "270-300 kat" diye tahmin etti. Doğal logaritmada doğrusu $e^5 \approx 148$ kattır; fark yine de büyüktür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
