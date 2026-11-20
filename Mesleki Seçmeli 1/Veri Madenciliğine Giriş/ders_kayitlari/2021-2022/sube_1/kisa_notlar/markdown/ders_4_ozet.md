# Ders 4 Çalışma Özeti

## Genel Konular

- Önceki dersin kısa tekrarı
  - Veri nesneleri (data object, satır, tuple) ve öznitelikler (attribute, feature, sütun) tanımlanmıştı.
  - Öznitelik tipleri: kategorik (nominal, ordinal) ve sayısal (aralık, oran). Ordinal değerler küçük/büyük gibi sıralanabilir.
  - Veriyi tanımak için ortalama, medyan, çeyreklikler gibi temel istatistikler kullanılır.
- Veri ön işlemenin (data preprocessing) başlıkları (ekrandan, 00:05:00)
  - Veri kalitesi ve ön işlemenin ana görevleri, veri temizleme (data cleaning), veri bütünleştirme (data integration), veri dönüştürme ve ayrıklaştırma (data transformation and discretization), veri azaltma (data reduction).
- Veri kalitesi
  - Gerçek veritabanları hatalı, gürültülü, eksik ya da tutarsız veri içerebilir. Örneğin tablo tanımında `NULL` değere izin verilirse ya da değerleri denetleyen bir kural (trigger vb.) yazılmazsa hatalı değerler girebilir.
  - Kalitesi düşük (low quality) veriden madencilikle doğru bilgi çıkarmak mümkün değildir. Ön işlemenin amacı veriyi daha kaliteli hale getirmektir.
  - Kalite problemleri: gürültü (noise), aykırı değerler (outlier), eksik veri (missing value), tekrarlayan veri (duplicate).
  - Kalitenin diğer boyutları: doğruluk, tamlık, güncellik (ör. yalnız yaş tutulan üç yıllık veride yaşların güncellenmesi gerekir), güvenilirlik (sensör verisi tamamen bozuk olabilir) ve anlaşılabilirlik (her özniteliğin nereden geldiği, birimi, nasıl ölçüldüğü bilinmelidir).
- Eksik veri ve tekrarlayan veri (ekrandan, 00:10:00)
  - Eksik verinin nedenleri: bilgi toplanmamıştır (insanlar yaş, kilo vermek istemeyebilir) ya da öznitelik her duruma uygulanamaz (çocukların yıllık geliri olmaz).
  - Slaytta eksik değerle başa çıkma yolları: nesneyi silmek, eksik değeri tahmin etmek, analizde yok saymak, olası bütün değerlerle (olasılıklarına göre ağırlıklandırarak) değiştirmek.
  - Tekrarlayan veri: aynı kişi farklı e-posta adresleriyle tekrar kayıt olabilir, farklı şubelerde ayrı müşteri kaydı açılabilir. Özellikle farklı kaynaklardan gelen veri birleştirilirken büyük sorun olur; temizlenmesi gerekir.
- Ön işlemenin ana görevleri (ekrandan, 00:15:00)
  - Veri temizleme: eksik değerleri doldurmak, gürültülü veriyi yumuşatmak, aykırı değerleri bulmak ya da çıkarmak, tutarsızlıkları gidermek.
  - Veri bütünleştirme: birden çok veritabanını, veri küpünü ya da dosyayı tutarlı bir veri deposunda (ör. veri ambarı) birleştirmek.
  - Veri azaltma: boyut azaltma (dimensionality reduction), sayıca azaltma (numerosity reduction), veri sıkıştırma.
  - Veri dönüştürme ve ayrıklaştırma: normalizasyon, kavram hiyerarşisi üretimi.
- Hatalı ve eksik verinin kaynakları (ekrandan, 00:20:00)
  - İnsan hatası, bilerek yanlış girilen bilgi (ör. doğum tarihini doğru vermemek), cihaz ya da sensör hatası, formlarda yalnız zorunlu alanların doldurulması, yazılım hatası, yanlış anlama (ör. Amerikan tarih biçiminde ayın önce yazılması nedeniyle `07-02`'de Şubat ile Temmuz'un karışması).
  - Tutarsız değer örnekleri: maaşın `-10` girilmesi, yaşı 42 olan birinin doğum yılının 2010 görünmesi, posta kodu ile ilin tutmaması, herkesin doğum tarihini 1 Ocak işaretlemesi.
  - Slayttaki nedenler: donanım arızası, diğer kayıtlarla tutarsız olduğu için silinmiş veri, yanlış anlama, giriş anında önemsiz görülen veri, verinin geçmişinin ya da değişikliklerinin kaydedilmemesi.
- Eksik veriyle başa çıkma (ekrandan, 00:25:00)
  - Satırı (tuple) yok saymak: en kolay yoldur. Eksik oran küçükse (yaklaşık %10 eşiği söylenir) uygulanır; eksikler farklı sütunlarda farklı satırlara dağılmışsa veri çok azalır.
  - Elle doldurmak: zahmetlidir ama veri önemliyse uzman tekrar bakıp düzeltebilir (ör. radyoloji görüntülerinde teşhisin doktorca yeniden okunması).
  - Otomatik doldurmak: global sabit (ör. "unknown", yalnız kategorik öznitelikte yeni bir sınıf), özniteliğin ortalaması, aynı sınıftaki örneklerin ortalaması ya da en olası değer (Bayes formülü veya karar ağacı ile çıkarım).
  - Eksik olan sınıf etiketiyse ortalama gibi doldurma yöntemleri kullanılmaz.
  - Eksik çok fazlaysa (ör. bir sütunun yarısı) ortalama koymak iyi çözüm değildir; sentetik veri üretimi gibi farklı yöntemlere gidilir.
- Gürültülü veri ve yumuşatma (ekrandan, 00:30:00)
  - Gürültü: ölçülen bir değişkendeki rastgele hata ya da varyans (ör. sesteki cızırtı). Aykırı değerler de gürültü olabilir.
  - Yumuşatma (smoothing): zikzaklı veriyi daha düz hale getirmek. Gürültü elenir ama hassas değerler de kaybolur.
  - Yöntemler: kutulama (binning), regresyon, kümeleme (clustering), bilgisayar ve insan denetiminin birlikte kullanılması (human inspection).
- Kutulama ile yumuşatma örneği (ekrandan, 00:40:00)
  - Veri sıralanır, eşit frekanslı kutulara bölünür, sonra her değer kutu ortalaması, kutu medyanı ya da en yakın kutu sınırı ile değiştirilir.
- Yumuşatma ve veri azaltma (ekrandan, 00:45:00)
  - Kutulama bir öznitelikteki farklı değer sayısını azaltır; bu, karar ağacı gibi sıralı veride sürekli karşılaştırma yapan yöntemler için bir veri azaltmadır.
  - Kavram hiyerarşileri de bir ayrıklaştırmadır (ör. fiyatın ucuz, orta, pahalı olarak eşlenmesi).

## Hocanın Özellikle Vurguladığı Kısımlar

- Veri kalitesi düşükse madencilik sonucu da doğru olmaz
  - Bu yüzden ön işleme sürecin ilk ve zorunlu adımıdır.
- En büyük sorun her zaman eksik değerlerdir
  - Bazı yöntemler eksik veriyle hiç çalışmaz.
- Eksik değerlerin dağılımı önemlidir
  - Toplam oran %10 gibi görünse de her sütunun eksikleri farklı satırlardaysa satır silmek veriyi çok azaltır.
- Sınıf etiketi eksikse ortalama ile doldurma yapılmaz
  - Sınıflandırmada etiket bilgisi çok önemlidir.
- Aykırı değer bulunduktan sonra hemen silinmez
  - Özellikle verinin az ve önemli olduğu alanlarda (tıbbi veri, kredi kartı dolandırıcılığı) uzmana sorulur. Gerçek bir değişim (ör. önemli bir basınç artışı) aykırı değer diye silinmemelidir.
- Çok fazla yöntem vardır
  - Kütüphanelerde hazır bulunurlar; önemli olan hangi yöntemin ne zaman kullanılacağını bilmektir.
- Kutulama her öznitelik için ayrı yapılır ve test verisine de aynı şekilde uygulanır
  - Eğitim verisinde bir aralık 9'a eşlendiyse test verisinde o aralıktaki değer de 9 olarak verilmelidir; yoksa ciddi hata olur.

## Kısa Tekrar Notları

- Ön işleme: temizleme, bütünleştirme, azaltma, dönüştürme/ayrıklaştırma.
- Kalite problemleri: gürültü, aykırı değer, eksik değer, tekrarlayan veri.
- Eksik veri: sil (az ise), elle doldur, global sabit (kategorik), ortalama, sınıf ortalaması, en olası değer (Bayes, karar ağacı).
- Sınıf etiketi eksikse doldurma yapılmaz.
- Gürültü: rastgele hata ya da varyans; yumuşatma hassas değerleri de kaybettirir.
- Yumuşatma: kutulama, regresyon, kümeleme, insan denetimi.
- Kutulama örneği (ekrandan, 00:40:00): veri `4, 8, 15, 21, 21, 24, 25, 28, 34`; kutular `{4, 8, 15}`, `{21, 21, 24}`, `{25, 28, 34}`.
  - Ortalama ile: `9, 9, 9`; `22, 22, 22`; `29, 29, 29`.
  - Medyan ile: `8, 8, 8`; `21, 21, 21`; `28, 28, 28`.
  - Sınır ile: `4, 4, 15`; `21, 21, 24`; `25, 25, 34`.
- Kutulama farklı değer sayısını azaltır, sayısal değeri kategoriye yaklaştırır.

## Detaylı Açıklamalar

- Neden ön işleme?
  - Veri formlardan, sensörlerden, farklı şubelerden ve farklı veritabanlarından gelir. İnsan hatası, bilerek yanlış bilgi verme, cihaz ve yazılım hataları, yanlış anlama gibi nedenlerle eksik, gürültülü ve tutarsız olur. Hoca bir projede yazılım hatası yüzünden bir sütunun haftalarca hep sıfır toplandığını örnek verdi; test edilmeyen bir hata veriyi bozabilir.
  - Sonuç bilgisinin anlaşılabilir olması için öznitelikler açık tanımlanmalıdır. Örneğin bir karar ağacı "şu değer şundan büyükse" diye bir kural üretirse, o değerin hangi birimle ve nasıl ölçüldüğü bilinmelidir.
- Eksik değer doldurma yöntemleri
  - Global sabit: bazı araçlar boş hücreye doğrudan `NULL` yazar. Kategorik öznitelikte "bilinmiyor" diye yeni bir kategori açılabilir; sayısal öznitelikte bu yapılmaz.
  - Ortalama: özniteliğin genel ortalaması konur. Zaman sıralı veride bütün verinin ortalaması yerine eksik değerin hemen önceki ve sonraki değerlerinin ortalaması da konabilir.
  - Sınıf ortalaması: sınıflandırmada A ve B sınıfları varsa, A sınıfındaki eksik uzunluk değerine A sınıfının uzunluk ortalaması, B'dekine B'ninki konur.
  - En olası değer: Bayes çıkarımı ya da karar ağacı ile, o satıra benzeyen satırlara bakılarak her eksik değer ayrı ayrı tahmin edilir. Her eksik değere aynı sayıyı koymadığı için daha akıllıcadır; slayta göre eldeki veriden en çok bilgiyi kullanan, yaygın bir stratejidir. Hoca bunu, film öneri sistemlerinin izlenmemiş bir film için kullanıcının vereceği puanı tahmin etmesine benzetti.
- Gürültüyü yumuşatma
  - Sinyal ve görüntüde gürültü için hazır filtreler vardır (ör. görüntüde medyan filtresi, tuz-biber gürültüsü için filtre). Kaynağı iyi bilinmeyen, özellikle kullanıcı girdisi olan sayısal veride veri yumuşatılır.
  - Regresyon: veriye bir doğru (doğrusal regresyon) ya da eğri uydurulur, her noktanın değeri doğru üzerindeki karşılığıyla değiştirilir. Regresyondan sonra noktaların doğruya ortalama uzaklığı bulunur; bunun örneğin bir buçuk katından daha uzak noktalar atılabilir.
  - Kümeleme: benzer veriler kümelenir; kümelerin dışında kalan ya da çok az elemanlı kümelerdeki noktalar aykırı değer kabul edilip silinebilir.
  - İnsan denetimi: sistem şüpheli değerleri bulur, insan bunların aykırı mı gerçek mi olduğuna karar verir. Hoca bir firmayla yürüttükleri projede yaklaşık %80 doğrulukla çalışan modelin yeni veriyi işleyip yalnız emin olmadığı örnekleri insana göstereceğini anlattı. Kitle kaynaklı işaretlemede (crowdsourcing, ör. Amazon Mechanical Turk) kötü işaretleyenler aykırı değer üretebilir; bunlar da aynı yöntemlerle bulunup yeniden işaretlenir.
- Kutulama (binning)
  - Kutu sayısını kullanıcı seçer. Ortalama ile yumuşatmada ilk kutu $\frac{4+8+15}{3}=9$ olur; medyan ile 8 olur; sınır ile yumuşatmada her değer kutunun alt ya da üst sınırından hangisine yakınsa ona eşlenir: 8, 4'e daha yakın olduğu için 4 olur. Kutuda 13 olsaydı 15'e eşlenirdi.
  - Faydası: ondalıklı birçok kilo değeri (55.8, 60, 62.3 gibi) 20 kutuya ayrılırsa elde yalnız 20 farklı değer kalır. Çok nadir görülen büyük değerler de diğerlerine yaklaştırılır. Bedeli gerçek değerdeki hassasiyetin kaybıdır.
  - İşlem her öznitelik için ayrı yapılır. Farklı kişiler aynı kutuya düşerek uzayda aynı noktaya gelebilir; amaç sınıflandırma ya da kümeleme olduğu için bu istenen bir sonuçtur.
- Ders sonrası not: hoca kutulamada "dört tane kural" olduğunu söyledi ama ortalama, medyan ve sınır olmak üzere üç yöntem saydı. Slaytta da bu üçü ve "etc." vardır (ekrandan, 00:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
