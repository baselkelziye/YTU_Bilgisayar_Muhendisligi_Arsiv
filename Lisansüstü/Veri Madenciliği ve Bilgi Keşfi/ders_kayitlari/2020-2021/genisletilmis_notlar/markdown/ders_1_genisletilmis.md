# Ders 1 Genişletilmiş Notu: Veri Madenciliğine Giriş, Stratejiler ve KDD Süreci

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yaklaşımı ve Kapsamı
- 2. Veri Madenciliği Nedir, Neden Gerekir?
- 3. Veri Kaynakları ve Veri Madenciliğinin Diğer Adları
- 4. Uygulama Alanları
- 5. Veri Madenciliği Stratejileri
- 6. Eğiticili Öğrenme: Karar Ağacı Örneği
- 7. Eğiticisiz Kümeleme: Yatırımcı Veri Seti
- 8. Sınıflandırma, Kestirim ve Öngörü
- 9. Market Sepeti Analizi
- 10. Üretim Kuralları: Kural Doğruluğu ve Kural Kapsaması
- 11. Bilgi Keşfi (KDD) Süreci
- 12. Veri Madenciliği ve İş Zekası
- 13. Çok Disiplinli Bir Alan
- Örnek Sorular

## 1. Dersin Yaklaşımı ve Kapsamı

Ders slaytları İngilizcedir (kapak: "Data Mining: Concepts and Techniques"; ekrandan, 00:30:00), ama anlatım Türkçe yapılır. Hoca yer yer Türkçe karşılıkları kullanacağını, fakat İngilizce kavramların da mutlaka birlikte öğrenilmesi gerektiğini söyledi.

Dersin ana fikri, veriyi tanımak ve bu veriden anlamlı bilgi üretmek için neler yapılabileceğidir. Hocaya göre dersin en önemli noktası, veri madenciliği süreçlerine girmeden önce veriyi çok iyi analiz etmek, tanımak ve gerekli düzenlemeleri yapmaktır.

Dönem boyunca işlenecek konular hocanın anlattığı sırayla şöyledir:

- İlk haftalar verinin analiz edilmesi ve düzenlenmesi: veri ayrıklaştırma (data discretization), veri temizleme (data cleaning), aykırı değer (outlier) analizi, eksik verinin (missing data) giderilmesi, veri indirgeme ve dönüştürme.
- Eğiticili öğrenme (supervised learning): ilk sınıflandırma algoritması olarak karar ağacı (decision tree), ardından Naive Bayes sınıflandırıcı ve K en yakın komşu (k-NN) gibi temel sınıflandırıcılar.
- Eğiticisiz öğrenme (unsupervised learning): K-means ve hiyerarşik kümeleme.
- Market sepeti analizi ve birliktelik kuralları (association rules).
- Öneri sistemleri (recommendation systems) ve web madenciliği.

Hoca, lisans ve lisansüstü derslerinin içeriğinin büyük ölçüde örtüştüğünü, lisansüstü derste öneri sistemleri ve web madenciliğine daha geniş yer verdiğini belirtti. Bir öğrencinin makine öğrenmesi dersiyle karşılaştırması üzerine, bu dersi ayıran kısmın ilk haftalardaki veri hazırlama teknikleri (aykırı değer analizi, eksik veri, veri temizleme) olduğunu söyledi.

Lisansüstü dersin akademik çalışma biçimi bir makale çalışmasıdır: öğrenci ilgi alanına giren bir makaleyi seçer; kullanılan veri setini, amacı, yöntemleri, sonuçları ve başarı ölçütlerinin nasıl tanımlandığını inceler. Veri seti herkese açıksa (public) indirilip üzerinde denemeler yapılması ve sonuçların makaleyle karşılaştırılması beklenir.

## 2. Veri Madenciliği Nedir, Neden Gerekir?

Slayttaki tanıma göre veri madenciliği (veriden bilgi keşfi, knowledge discovery from data), büyük miktardaki veriden **ilginç** örüntülerin ya da bilginin çıkarılmasıdır. Buradaki "ilginç" sözcüğü slaytta dört nitelikle açılmıştır: önemsiz olmayan (non-trivial), örtük (implicit), önceden bilinmeyen (previously unknown) ve potansiyel olarak yararlı (potentially useful) (ekrandan, 00:35:20). Hoca derse girerken "interesting pattern" kavramının veri madenciliğinde sıkça kullanıldığını ve dönem içinde ayrıntılı konuşulacağını söyledi. Slaytta ayrıca "Data mining: a misnomer?" (veri madenciliği yanlış bir ad mı?) sorusu yer alıyor.

> **Ek bilgi (derste anlatılmadı):** "Misnomer" tartışması büyük olasılıkla şuna dayanır: madencilikte kayadan altın çıkarılır ve işin adı "altın madenciliği" olur, "kaya madenciliği" olmaz. Bu mantıkla, veriden bilgi çıkaran işin adı da "bilgi madenciliği" (knowledge mining) olmalıydı.

Neden veri madenciliğine ihtiyaç var? Toplanan veri internet ortamında her gün artıyor. Kullandığımız uygulamalar, bağlandığımız saatler, ilgilendiğimiz sayfalar gibi bilgilerin hepsi bir yerlerde loglanıyor. Bu biriken verinin anlamlı bilgiye dönüştürülmesi gerekir. Veri madenciliği geliştirdiği karar destek sistemlerini hep veriden öğrendiği için, birikmiş verinin bu amaçla kullanılması işletmelere çok büyük avantaj sağlar.

Hocaya göre en büyük sıkıntı şudur: Geçmişten bugüne çok büyük miktarda veri birikmiştir, ama firmaların çoğu bu veriyi nasıl kullanacağını bilmiyor. Son yıllarda büyük firmalar bu veriyle müşterilerine öneri sistemleri sunmaya başladı; işletmeler veriden nasıl yararlanacaklarını yavaş yavaş görüyor.

<!-- BELİRSİZ: 00:33:46'da altyazıda "çoğu firma bunları nasıl kullanacağını biliyor" yazıyor; bağlam ("En büyük sıkıntı") olumsuz anlamı ("bilmiyor") gösteriyor. -->

Veri tabanlarındaki gelişmeler de önemli bir avantajdır. Verinin bir veri tabanı yönetim sistemi üzerinde düzenli ve yapısal biçimde toplanmış olması veri işleme işini kolaylaştırır.

## 3. Veri Kaynakları ve Veri Madenciliğinin Diğer Adları

### 3.1 Veri kaynakları

Hoca veri kaynaklarını üç gruba ayırdı:

- **İşletme ve ticari veriler:** e-ticaret verileri, bir bankanın ya da bireysel emeklilik sisteminin verileri, borsada yapılan bütün işlemler. Borsa endeksinin tahmini ve kazançların önceden tahmin edilmesi bu alanda sık görülen çalışmalardır.
- **Bilimsel alanda toplanmış veriler.**
- **Sosyal platformlarda oluşan veriler.**

Bu alanların hepsinde çok büyük miktarda veri oluşur. Her kullanıcının sistem üzerindeki hareketleri bir işaret taşır; bu hareketler incelenerek bilgiye ulaşılabilir.

### 3.2 Diğer adlar

Veri madenciliği sektörde farklı adlarla da karşımıza çıkar. Bu alanda çalışmalar ilk başladığında, örneğin işletme tarafı bu yöntemleri "iş zekası" (business intelligence) başlığı altında toplamıştı. Slayttaki liste (ekrandan, 00:35:20): veri tabanlarında bilgi keşfi (knowledge discovery in databases, KDD), bilgi çıkarımı (knowledge extraction), veri/örüntü analizi (data/pattern analysis), veri arkeolojisi (data archeology), data dredging, bilgi hasadı (information harvesting), iş zekası (business intelligence). Hoca "information harvesting" adını ilginç bulduğunu söyledi. Bu adlarla sunulan çalışmaların hepsi aslında veri madenciliğidir.

Aynı slaytta bir uyarı da var: Her şey "veri madenciliği" değildir. Basit arama ve sorgu işleme (simple search and query processing) ile (tümdengelimli) uzman sistemler ((deductive) expert systems) veri madenciliği sayılmaz (ekrandan, 00:35:20).

## 4. Uygulama Alanları

Hoca uygulama alanları konusunda derste öğrencilere söz vermek istediğini, çünkü günlük hayatta kullandığımız pek çok uygulamanın arkasında veri madenciliği süreçlerinin bulunduğunu söyledi. Slayttaki sınıflama şöyledir (ekrandan, 00:40:00):

- Veri analizi ve karar destek (data analysis and decision support)
  - Pazar analizi ve yönetimi: hedefli pazarlama, müşteri ilişkileri yönetimi (CRM), market sepeti analizi, çapraz satış (cross selling), pazar segmentasyonu.
  - Risk analizi ve yönetimi: tahmin (forecasting), müşteriyi elde tutma (customer retention), improved underwriting, kalite kontrol, rekabet analizi.
  - Sahtecilik tespiti ve olağandışı örüntülerin (aykırı değerlerin) tespiti.
- Diğer uygulamalar
  - Metin madenciliği (haber grupları, e-posta, belgeler) ve web madenciliği.
  - Akan veri madenciliği (stream data mining).
  - Biyoinformatik ve biyolojik veri analizi.

### 4.1 Pazar analizi ve risk analizi

Pazar analizinde müşteri ilişkileri yönetim sistemlerinden elde edilen veriler kullanılır. Market sepeti analizi ve çapraz satış da toplanan bu veriye dayanır. Segmentasyonda müşteriler farklı segmentlere ayrılır.

Risk analizi tarafında özellikle sigortacılıkta çalışmalar vardır: sağlık sigortası, kasko gibi sigortaların hesaplanması.

### 4.2 Sahtecilik tespiti

Sahtecilik tespitinde bazı sistemler kural tabanlıdır. Örneğin banka, işlem yapan kişinin gerçekten kart sahibi olup olmadığına karar verirken birtakım kurallar tanımlar. İstanbul'da yaşayan biri başka bir ülkede harcama yaptığında sistem "bu gerçekten bu kullanıcı mı?" diye sorgulayabilir.

Hoca burada kendi deneyimini anlattı: Yurt dışında bir harcamadan sonra teyit alınmadan kartı bloke edilmiş, bunu düzeltmek için yurt dışından bankayı aramak zorunda kalmıştı. Hocaya göre bu durumda sahtecilik tespit algoritması yanlış çalışmıştır. Sahteciliği önlemek önemlidir, ama gerçek müşteriyi mağdur etmemek de aynı ölçüde önemlidir. Bu sistemlerin doğru tasarlanması bu yüzden kritiktir.

Sahtecilik tespitinde bir başka zorluk, elimizdeki sahte işlem sayısının çok az olmasıdır. Bu kadar az örnekten ortak bir örüntü yakalamak kolay değildir; bu yüzden dünyada bu konuda pek çok çalışma vardır. Hoca bu çalışmalardan birindeki ilginç bir tespiti aktardı: Kredi kartı bilgileri ele geçirildiğinde ilk işlem çoğu zaman bir akaryakıt istasyonundan benzin almak oluyor. Kart orada sorunsuz çalışırsa, ardından mücevher gibi çok değerli ve büyük bir alışveriş yapılıyor ve kart bir daha kullanılmıyor. Bu ardışık işlem kalıbını gösteren işlemler sahtecilik şüphesi taşır.

Derste öğrencilerden gelen örnekler:

- Sigorta sektöründe sahte kazalarla yüklü tazminat alınmasına karşı örüntü tespiti yapılıyor.
- Konut sigortasında dere yatakları gibi riskli bölgelerin konum bilgisine göre hasar riski hesaplanıp primler ayarlanıyor (improved underwriting). Bir öğrenci bu çalışmaların sigortacılıkta veri madenciliği yerine daha çok "iş zekası" (BI) adıyla geçtiğini söyledi; hoca da bu firmaların daha çok tahmin (estimation) algoritmaları geliştirdiğini ekledi.
- Serbest metin olarak yazılmış adres bilgisinin, metnin içindeki anahtar kelimeler analiz edilerek yapısal (structured) veriye dönüştürülmesi. Amaç, tebligat ve fatura gibi gönderilerin doğru adrese gittiğinin teyit edilmesi.
- Bankaların borç tahsilatında karşı tarafın ekonomik gücünü (alım gücünü) tahmin edip ödeme teklifini buna göre sunması.

### 4.3 Müşteri kaybı (churn) analizi

Hoca churn analizini örnek verdi: Özellikle GSM operatörleri, ayrılma eğilimindeki müşterileri önceden tahmin edip onları kararlarından vazgeçirmek için öneride bulunmak ister. Churn analizi sigorta ve bireysel emeklilik gibi sektörlerde de kullanılır. Örneğin müşteri temsilcisini sık arayan ve şikâyetlerini dile getiren bir müşteri ayrılma eğilimindeyse ve değerli bir müşteriyse, firma onu elde tutmak için önceden tedbir alır. Bir öğrenci, gelecek dönemdeki churn oranını, yani ne kadar müşteri kaybedilip kazanılacağını tahmin eden analizlerin de yapıldığını ekledi.

### 4.4 Metin, web ve biyolojik veri

Metin madenciliği ve web madenciliği çok önemli alanlardır. E-postaların ya da haber gruplarındaki haberlerin içindeki kelimelere göre kategorize edilmesi bunun örneğidir: Bu e-posta kimi ilgilendiriyor, hangi birime gönderilmeli? Bu haber sağlık haberi mi, ekonomi mi, spor mu? Bu tür otomatik sınıflandırmalar doğal dil işleme tarafında yapılır. Sağlık tarafında biyoinformatik, biyolojik veri analizi ve gen çalışmaları önemli başlıklardır.

## 5. Veri Madenciliği Stratejileri

Slayttaki hiyerarşiye göre (ekrandan, 01:17:30) veri madenciliği stratejileri üçe ayrılır:

```text
                 Veri Madenciliği Stratejileri
                /             |               \
  Eğiticisiz Kümeleme   Eğiticili Öğrenme   Market Sepeti Analizi
                       /      |      \
            Sınıflandırma  Kestirim  Öngörü
```

Eğiticili öğrenmenin (supervised learning) altında üç işlem yer alır: sınıflandırma (classification), kestirim (estimation) ve öngörü (prediction). Diğer iki strateji eğiticisiz kümeleme (unsupervised clustering) ve market sepeti analizidir (market basket analysis).

## 6. Eğiticili Öğrenme: Karar Ağacı Örneği

### 6.1 İki aşamalı süreç

Eğiticili öğrenme slaytında iki madde var (ekrandan, 01:20:00):

- Kaynağı bilinen (known origin) veri örnekleriyle bir öğrenen model kur.
- Modeli, kaynağı bilinmeyen (unknown origin) yeni örneklerin sonucunu belirlemek için kullan.

Yani iki aşamalı bir işlem vardır. Birinci aşamada alan uzmanı tarafından etiketlenmiş veriyle bir model eğitilir; bu veriye eğitim verisi (training dataset) denir. İkinci aşamada eğitilen modeli test etmek için test verisi (test dataset) kullanılır.

Hoca burada bir inceliğe dikkat çekti: Slayt yeni örneklerin "kaynağı bilinmeyen" örnekler olduğunu söylüyor, ama aslında test örneklerinin de bir yerde sınıf bilgisi vardır. Model bu bilgiyi kullanmadan test örneklerinin hangi sınıfa ait olduğuna karar verir. Sonra bildiğimiz gerçek etiketlerle modelin sonuçları karşılaştırılır ve modelin ne kadar başarılı olduğu ölçülür. Eğiticili öğrenmenin amacı budur.

### 6.2 Eğitim verisi: hastalık teşhisi

Örnekte hastalara beş soru sorulmuştur: boğazda ağrı (sore throat), ateş (fever), bezlerde şişme (swollen glands), burun tıkanıklığı (congestion) ve baş ağrısı (headache). "Diagnosis" sütununda ise alan uzmanının (bir kulak-burun-boğaz doktoru) koyduğu etiketler vardır: boğaz enfeksiyonu (strep throat), alerji (allergy) ve soğuk algınlığı (cold). Tablo (ekrandan, 01:21:45):

| Hasta | Sore Throat | Fever | Swollen Glands | Congestion | Headache | Diagnosis |
|---|---|---|---|---|---|---|
| 1 | Yes | Yes | Yes | Yes | Yes | Strep throat |
| 2 | No | No | No | Yes | Yes | Allergy |
| 3 | Yes | Yes | No | Yes | No | Cold |
| 4 | Yes | No | Yes | No | No | Strep throat |
| 5 | No | Yes | No | Yes | No | Cold |
| 6 | No | No | No | Yes | No | Allergy |
| 7 | No | No | Yes | No | No | Strep throat |
| 8 | Yes | No | No | Yes | Yes | Allergy |
| 9 | No | Yes | No | Yes | Yes | Cold |
| 10 | Yes | Yes | No | Yes | Yes | Cold |

Bu tablo, sınıf etiketi (class label) olan örneklerden oluştuğu için bir eğitim verisidir. Bu örneklerle öğrenebilen bir model geliştirilir; öğrenme bitince model, 11. hastanın cevaplarına bakarak kendisi bir teşhis üretebilir.

Hoca kavramları oturtmak için şu adlandırmaları yaptı:

- Her satır bir örnektir (sample). Burada 10 örnek vardır.
- Hastaya sorulan her soru (sore throat, fever, ...) bir öz niteliktir. İngilizcesi "feature", bazı kaynaklarda "attribute".
- Teşhis sütunu çıkış değişkeni, yani sınıf etiketidir.

### 6.3 Karar ağacı modeli

Bu 10 örnekle kurulmuş karar ağacı şöyledir (ekrandan, 01:24:15):

```text
Swollen Glands?
├── Yes -> Diagnosis = Strep Throat
└── No  -> Fever?
           ├── No  -> Diagnosis = Allergy
           └── Yes -> Diagnosis = Cold
```

Slayttaki tanım: iç (terminal olmayan) düğümlerin bir ya da birkaç öz nitelik üzerindeki testleri, yaprak (terminal) düğümlerin karar sonuçlarını gösterdiği bir ağaç yapısı (ekrandan, 01:24:15).

Hoca karar ağacının nasıl oluşturulduğunun ileride anlatılacağını, şimdilik yalnızca eğiticili öğrenmeyle kurulmuş bir model örneği gösterdiğini söyledi.

**Soru:** Tabloda her hastaya beş soru sorulmuş, ama ağaçta yalnızca ikisine bakılarak karar veriliyor. Neden?

**Cevap:** Çünkü mevcut tabloda üç sınıfı birbirinden ayırt etmek için bu iki soru yeterlidir. Bu 10 örneğin dışında daha fazla örnek ve daha fazla sınıf olsaydı modelin geliştirilmesi ve belki diğer öz niteliklerin de kullanılması gerekecekti.

### 6.4 Model eğitim verisinde ve test verisinde nasıl çalışıyor?

Hoca önce modelin eğitim örneklerinin hepsi için doğru çalışıp çalışmadığını sordu ve satır satır kontrol etti: 1. satırda bez şişmesi "Yes", dolayısıyla model "strep throat" der, doğru. 2. satırda bez şişmesi yok, ateş de yok, model "allergy" der, doğru. 3. satırda bez şişmesi yok, ateş var, model "cold" der, doğru. Bu şekilde 10 örneğin hepsi doğru sınıflandırılır (python ile doğrulandı).

Ardından modele hiç görmediği test örnekleri verildi. Bu örneklerde teşhis bilinmiyor ("?") ve modelin söylemesi bekleniyor (ekrandan, 01:30:00). Çözüm aşağıdaki "Örnek Sorular" bölümünde adım adım verilmiştir. Hoca sonunda bunun bir eğiticili öğrenme sistemi ve bir sınıflandırma (classification) problemi olduğunu vurguladı.

## 7. Eğiticisiz Kümeleme: Yatırımcı Veri Seti

### 7.1 Kümeleme

İkinci strateji eğiticisiz kümelemedir (unsupervised clustering). Eğiticisiz kümelemede elimizdeki verinin önceden tanımlı sınıf etiketleri yoktur; yöntemin "unsupervised" adını almasının sebebi budur.

> **Hocanın vurgusu:** Eğiticisiz yapılan işlem kümelemedir. Buna asla "unsupervised classification" dememeliyiz; kavramları yanlış kullanmamaya dikkat etmeliyiz.

### 7.2 Acme yatırımcı veri seti

Örnek veri seti (ekrandan, 01:33:00):

| Customer ID | Account Type | Margin Account | Transaction Method | Trades/Month | Sex | Age | Favorite Recreation | Annual Income |
|---|---|---|---|---|---|---|---|---|
| 1005 | Joint | No | Online | 12.5 | F | 30-39 | Tennis | 40-59K |
| 1013 | Custodial | No | Broker | 0.5 | F | 50-59 | Skiing | 80-99K |
| 1245 | Joint | No | Online | 3.6 | M | 20-29 | Golf | 20-39K |
| 2110 | Individual | Yes | Broker | 22.3 | M | 30-39 | Fishing | 40-59K |
| 1001 | Individual | Yes | Online | 5.0 | M | 40-49 | Golf | 60-79K |

Veri setinde müşteri numarası, hesap türü, işlem yöntemi (işlemlerini online kendisi mi yapıyor, yoksa bir aracı/broker yardımıyla mı), cinsiyet, yaş aralığı ve yıllık gelir gibi bilgiler vardır. Bu bir borsa yatırımcısının ya da banka müşterisinin verisi olarak düşünülebilir.

Sınıf etiketi olmadığı için bu veriyle yapılabilecek ilk iş müşterileri gruplamaktır: birbirine benzeyen müşterilerden oluşan kümeler kurmak. Bunun için kümeleme algoritmaları kullanılır. Hoca bir benzetme yaptı: Kredi kartı şirketleri kullanıcılarını "premium", "gold" gibi kategorilere ayırır; müşteriler bu şekilde belli sayıda gruba ayrılabilir.

<!-- BELİRSİZ: 01:36:05-01:36:35 arasında hoca kredi kartı kategorilerinin "baştan tanımlı sınıflar" olduğunu da söylüyor; bu örneğin kümelemeye mi, sınıflandırmaya mı bağlandığı altyazıdan net çıkmıyor. -->

> **Ders sonrası not:** Hoca 01:35:46'da müşterileri benzer özelliklerine göre gruplama işlemi için "supervised tarafta" dedi. Bağlamdan anlaşıldığı gibi doğrusu eğiticisiz (unsupervised) taraftır.

### 7.3 Aynı veriyle eğiticili öğrenme

**Soru (hocanın sorusu):** Bu yatırımcı veri setiyle eğiticili öğrenme yapmak istesek ne yapabiliriz?

**Cevap:** Veri setindeki öz niteliklerden birini çıkış değişkeni (output variable) olarak tanımlarsak veri bir eğitim verisine dönüşür. Örneğin işlem yöntemi (transaction method) çıkış değişkeni seçilirse bu bir sınıf etiketi olur: Bu müşteri online işlem mi yapar, yoksa bir aracı üzerinden mi? Hoca, yaşı ilerlemiş kişilerin online işlem kullanamadığı için telefonla birinin yardımıyla işlem yapıyor olabileceği örneğini verdi. Bu şekilde online işlem yapan yatırımcıların genel profili çıkarılabilir. Benzer biçimde margin hesabı öz niteliği çıkış seçilirse, yeni bir müşterinin margin hesabı açıp açmayacağı belirlenmeye çalışılabilir.

## 8. Sınıflandırma, Kestirim ve Öngörü

Hoca bu üç kavramı düzgün ayırt etmenin sonraki çalışmalarda hangi yöntemin kullanılacağına karar vermeyi kolaylaştıracağını söyledi ve not alınmasını tavsiye etti.

### 8.1 Sınıflandırma (classification)

Slayttaki maddeler (ekrandan, 01:40:00):

- Öğrenme eğiticilidir (learning is supervised): yöntemin eğiticili olması için elimizde etiketli veri olmalıdır.
- Bağımlı değişken kategoriktir (the dependent variable is categorical). Bağımlı değişken çıkış değişkenidir; hasta örneğinde alan uzmanının koyduğu teşhis sütunudur.
- Sınıflar iyi tanımlıdır (well-defined classes): hasta örneğindeki boğaz enfeksiyonu, soğuk algınlığı ve alerji gibi.
- Gelecekteki değil mevcut davranış esas alınır (current rather than future behavior).

### 8.2 Kestirim (estimation)

Altyazıya göre kestirim slaytındaki maddeler: öğrenme eğiticilidir, bağımlı değişken sayısaldır (numeric), yapı iyi tanımlıdır, gelecekteki değil mevcut davranış esas alınır. Sınıflandırmayla arasındaki fark çıkış değişkeninin sayısal olmasıdır.

<!-- BELİRSİZ: Kestirim slaytı için kare çıkarılmadı; maddeler altyazıdan (01:40:30-01:41:18) alındı. "Well-defined classes" maddesinin kestirimdeki karşılığı altyazıda net değil. -->

**Soru:** Kestirim dediğimiz kısım regresyon mu?

**Cevap:** Evet, aynen öyle.

### 8.3 Öngörü (prediction)

Slayttaki maddeler (ekrandan, 01:41:45):

- Vurgu, mevcut sonuçlardan çok gelecekteki sonuçları tahmin etmektir (the emphasis is on predicting future rather than current outcomes).
- Çıkış öz niteliği kategorik ya da sayısal olabilir (the output attribute may be categorical or numeric).

Özetle ayrım iki soruya dayanır:

| Strateji | Çıkış değişkeni | Zaman |
|---|---|---|
| Sınıflandırma | Kategorik | Mevcut |
| Kestirim | Sayısal | Mevcut |
| Öngörü | Kategorik ya da sayısal | Gelecek |

### 8.4 Derste tartışılan örnekler

Hoca bir örnek verip öğrencilerden yenilerini istedi. Örneklerin her biri "Örnek Sorular" bölümünde ayrıca soru olarak yer alıyor; burada tartışmanın akışı özetleniyor.

- **İMKB 100 endeksi:** Geçmiş kapanış değerlerinden endeksin yarınki ya da bir hafta sonraki değerini bulmak. Çıkış sayısal ve gelecekle ilgili olduğu için öngörüdür.
- **Kalp atışı verileri ve borsa/fiyat tahminleri:** Bir öğrenci bunların genelde regresyona girdiğini söyledi.
- **Ev fiyatı:** Oda ve salon sayısı, kat, konum, otopark gibi özelliklerden evin fiyatını tahmin etmek. Mevcut fiyat ve sayısal çıkış: kestirim.
- **EKG ile kalp krizi tahmini:** Bir öğrenci, ABD'de yapılan bir çalışmada EKG sonuçlarına göre bir kişinin ileride kalp krizi geçirip geçirmeyeceğinin tahmin edildiğini anlattı. Kategorik ve gelecekle ilgili: kategorik öngörü (sınıflandırma türünde bir öngörü).
- **ABD seçimleri:** Hangi partinin kazanacağını söylüyorsa kategorik; her birinin kazanma olasılığını söylüyorsa sayısal. Gelecekle ilgili olduğu için öngörüye girer.
- **Borsa robotları:** Hisse ya da endeks için "al" veya "sat" kararı veren robotlar kategorik çıkış üretir. Bir öğrenci destek ve direnç seviyelerini sayısal olarak tahmin eden algoritmaların da olduğunu, ama robotların çoğunlukla al/sat şeklinde çalıştığını ekledi.
- **Reklam gösterimi:** Bir öğrenci, YouTube'un kullanıcının geçmiş hareketlerine bakarak hangi kategoriden reklam izleyeceğine karar verdiğini ve bunun sınıflandırmaya girdiğini söyledi. Hoca orada daha çok öneri (recommendation) probleminin çözümlerinin kullanıldığını, bunların da diğer kullanıcıların ve o kullanıcının geçmiş verisine dayandığını belirtti.

<!-- BELİRSİZ: 01:46:05'te EKG çalışmasının doğruluk oranı altyazıda "185 doğrulukta" olarak geçiyor; büyük olasılıkla "%85" kastedildi, sesten kesinleştirilemedi. -->

## 9. Market Sepeti Analizi

Slayttaki maddeler (ekrandan, 01:50:00):

- Perakende ürünler arasında ilginç ilişkiler bulmak (find interesting relationships among retail products).
- Birliktelik kuralı algoritmalarını kullanır (uses association rule algorithms).

Alışveriş listeleri üzerinden sık satılan ve birlikte satılan ürünleri ve bunlar arasındaki ilginç ilişkileri yakalamak amaçtır. Kullanıcılar arasında sık satın alınan ikili, üçlü ürün grupları belirlenerek belli ürünlerin satışı artırılmaya çalışılır; bu bir pazarlama stratejisidir.

Hoca bu işlemi bir eğiticisiz kümeleme gibi düşünebileceğimizi söyledi.

> **Ders sonrası not:** Market sepeti analizi, sınıf etiketi kullanmadığı için eğiticisiz bir yöntemdir. Ama strateji hiyerarşisinde (ekrandan, 01:17:30) kümelemeden ayrı, üçüncü bir dal olarak gösterilir. Büyük olasılıkla hoca "etiketsiz çalışması bakımından kümelemeye benzer" demek istedi; birliktelik kuralı çıkarmak kümeleme yapmak demek değildir.

Günümüzde online satışlarda hangi kullanıcının hangi ürünleri birlikte aldığı da kaydediliyor. Bu yüzden bu sistemler toplumun geneline öneri sunmak yerine kişiye özel öneri sunan sistemlere, yani kişiselleştirilmiş öneri sistemlerine (personalized recommendation systems) dönüşüyor. Bu sistemler ve kullanılan yöntemler ilerleyen haftalarda işlenecek.

## 10. Üretim Kuralları: Kural Doğruluğu ve Kural Kapsaması

### 10.1 Kredi kartı promosyonu veri seti

Hoca kavramları basit örnekler üzerinden anlatmaya çalıştığını söyleyerek yeni bir veri seti gösterdi (ekrandan, 02:20:00). Bu veri setinde kart kullanıcılarının gelir aralığı, kendilerine sunulan dört promosyona (dergi, saat, hayat sigortası, kredi kartı sigortası) verdikleri cevaplar, cinsiyetleri ve yaşları vardır.

| # | Income Range | Magazine Promotion | Watch Promotion | Life Insurance Promotion | Credit Card Insurance | Sex | Age |
|---|---|---|---|---|---|---|---|
| 1 | 40-50K | Yes | No | No | No | Male | 45 |
| 2 | 30-40K | Yes | Yes | Yes | No | Female | 40 |
| 3 | 40-50K | No | No | No | No | Male | 42 |
| 4 | 30-40K | Yes | Yes | Yes | Yes | Male | 43 |
| 5 | 50-60K | Yes | No | Yes | No | Female | 38 |
| 6 | 20-30K | No | No | No | No | Female | 55 |
| 7 | 30-40K | Yes | No | Yes | Yes | Male | 35 |
| 8 | 20-30K | No | Yes | No | No | Male | 27 |
| 9 | 30-40K | Yes | No | No | No | Male | 43 |
| 10 | 30-40K | Yes | Yes | Yes | No | Female | 41 |
| 11 | 40-50K | No | Yes | Yes | No | Female | 43 |
| 12 | 20-30K | No | Yes | Yes | No | Male | 29 |
| 13 | 50-60K | Yes | Yes | Yes | No | Female | 39 |
| 14 | 40-50K | No | Yes | No | No | Male | 55 |
| 15 | 20-30K | No | No | Yes | Yes | Female | 19 |

(Satır numaraları nota eklendi; slaytta yoktur.)

Bu veri setinde özel bir sınıf etiketi alanı tanımlanmamıştır; bu yüzden etiketsiz bir veri gibi düşünülebilir. Hoca kavramların ne kadar akılda kaldığını görmek için örnek sayısını, öz nitelik sayısını ve sayısal öz nitelikleri sordu (cevaplar "Örnek Sorular" bölümünde).

**Soru:** Yaş da kategorik alınabilir mi? Değerlerin en küçüğüyle en büyüğü arasındaki fark çok değil.

**Cevap:** Yaşı kategorik alabilmek için gelir alanındaki gibi yaş aralıklarına bölmek gerekir; öyle yapılmadıkça yaş sayısal bir veridir. Aralıklara bölmek mümkündür, ama avantajları kadar dezavantajları da vardır. Kategorik alındığında uzaklık (distance) ölçülemez, yani kişilerin yaşlarının birbirine ne kadar yakın olduğu bilgisi çıkarılamaz. Bu yüzden bu karar verilirken iyi düşünmek gerekir. Veri türleri ve veri yapıları bir sonraki derste işlenecek.

### 10.2 Üretim kuralı

Kurallar, karar ağaçlarından rahatlıkla yazılabilir. Örnekteki amaç, hayat sigortası promosyonuna "evet" diyen grubun profilini tarif eden bir kural yazmaktır. Slayttaki kural (ekrandan, 02:17:30):

$$\text{IF } Sex = Female \;\&\; 19 \le Age \le 43 \text{ THEN } Life\ Insurance\ Promotion = Yes$$

Kuralın bu veri setinde ne kadar iyi olduğunu göstermek için iki ölçü tanımlanır:

- **Kural doğruluğu (rule accuracy):** Kural koşulunu sağlayan örneklerin ne kadarında sonucun da doğru olduğu. Hoca bunu "koşulu sağlayan ve kurala uyanların oranı" diye açıkladı: Koşulu sağlayıp kurala uymayan tek bir örnek bile olsaydı doğruluk %100 olmazdı.
- **Kural kapsaması (rule coverage):** Hedef sınıftaki (burada hayat sigortasına "Yes" diyen) örneklerin kaçta kaçının kural tarafından tarif edildiği, yani bu kümenin içine alınabildiği.

Slayta göre kural doğruluğu sınıflar arası (between-class), kural kapsaması sınıf içi (within-class) bir ölçüdür (ekrandan, 02:17:30).

Formül olarak (ara adım eklendi; hocanın sözlü tanımından kuruldu):

$$\text{Rule Accuracy} = \frac{\text{Koşulu ve sonucu birlikte sağlayan örnek sayısı}}{\text{Koşulu sağlayan örnek sayısı}}$$

$$\text{Rule Coverage} = \frac{\text{Koşulu ve sonucu birlikte sağlayan örnek sayısı}}{\text{Sonuç sınıfındaki toplam örnek sayısı}}$$

> **Ek bilgi (derste anlatılmadı):** "Sınıflar arası" ifadesi büyük olasılıkla şunu anlatır: doğruluk, koşulu sağlayan örneklerin hangi sınıflara dağıldığına bakar; yanlış sınıftaki örnekler doğruluğu düşürür. "Sınıf içi" ise kapsamanın yalnız hedef sınıfın içine bakması, o sınıfın ne kadarının yakalandığını ölçmesidir.

### 10.3 Kural 1'in hesabı

Hesap "Örnek Sorular" bölümünde adım adım verilmiştir. Sonuç: doğruluk %100, kapsama %66,67 (ekrandan, 02:17:30; python ile doğrulandı). Kural, "Yes" diyen 9 kişiden 6'sını tarif eder; dışarıda henüz tanımlanamamış 3 kişi kalır.

> **Ders sonrası not:** Hoca tabloyu sayarken önce koşulu sağlayan 5 kişi ve hayat sigortasına "Yes" diyen 4 kişi dedi. Öğrencilerin uyarısıyla sayılar 6 ve 9 olarak düzeltildi. Doğru sayılar 6 ve 9'dur. Hoca kapsamayı "%66" diye söyledi; tam değer $6/9 = \%66{,}67$'dir.

### 10.4 Kural 2

Hoca ikinci bir kural verip öğrencilerden hesaplamalarını istedi:

$$\text{IF } Sex = Male \;\&\; Income\ Range = 40\text{-}50K \text{ THEN } Life\ Insurance\ Promotion = No$$

Hoca kuralı önce "Yes" diye okudu, sonra "No" olarak düzeltti. Hesap "Örnek Sorular" bölümündedir. Sonuç: doğruluk %100, kapsama %50.

**Soru:** Kapsamayı "No" diyenlere göre mi, erkeklere göre mi belirleyeceğiz?

**Cevap:** "No" diyenlere göre. Hayat sigortası promosyonuna "No" diyenlerin sayısına bakılır ve kuralın bunların kaçını tarif ettiği hesaplanır.

**Soru:** İkinci kuralın doğruluğunu bir daha açıklayabilir misiniz?

**Cevap:** Koşul "erkek ve gelir aralığı 40-50K"dir. Bu koşulu sağlayan 3 kişi var ve üçü de hayat sigortasına "No" demiş. Doğruluk, koşulu sağlayanlar içinde kurala uyanların oranıdır: $3/3 = \%100$. Bu üç kişiden biri "No" dememiş olsaydı doğruluk $2/3$ olacaktı, yani üç kişiden ikisi doğru tahmin edilmiş olacaktı.

## 11. Bilgi Keşfi (KDD) Süreci

### 11.1 Süreç şeması

Slayttaki şemaya göre (ekrandan, 02:30:00) veri madenciliği, bilgi keşfi sürecinin çekirdeğidir (data mining: core of knowledge discovery process). Akış şöyledir:

```text
Veri tabanları
  -> Veri temizleme (Data Cleaning) + Veri bütünleştirme (Data Integration)
  -> Veri ambarı (Data Warehouse)
  -> Seçim (Selection)
  -> Göreve uygun veri (Task-relevant Data)
  -> Veri madenciliği (Data Mining)
  -> Örüntü değerlendirme (Pattern Evaluation)
  -> Bilgi (Knowledge)

Geri besleme: Örüntü değerlendirmeden seçim, veri madenciliği
ve veri bütünleştirme adımlarına geri dönen oklar.
```

Hoca adımları şöyle anlattı: Önce veri, veri tabanından alınır, bütünleştirilir ve temizlenir. Veri temizlemenin ne kadar kapsamlı bir iş olduğu ilerleyen haftalarda görülecek. Sonra amaca yönelik bir hedef veri oluşturulur. Örneğin amaç şirketi terk edecek müşterileri tespit etmekse, bunun göstergesi olabilecek öz niteliklere karar vermek gerekir. Hepsi akla gelmeyebilir, ama sonucu etkileyeceği düşünülen her öz nitelik veri setine dahil edilir. Ardından seçim (selection) adımında sistem test edilir: Bu öz niteliklerden hangisi bu iş için gerçekten gerekli? Buna öz nitelik seçimi (feature selection) denir. Öz nitelik seçme algoritmaları öz nitelik sayısını azaltır; çok daha büyük bir veriyle uğraşmak yerine yalnız amaca hizmet eden parametreler belirlenir.

Bundan sonra veri madenciliği süreçleri başlar: Elimizdeki veriyle eğiticili öğrenme mi, eğiticisiz kümeleme mi yapacağız, bu çatı altındaki hangi yöntemleri deneyebiliriz? Birden fazla algoritma denenir ve sonuçları birbiriyle karşılaştırılır.

> **Hocanın vurgusu:** Şemadaki geri beslemelere dikkat. Beklenen verim elde edilemiyorsa ok aşağı iner ve aynı süreç tekrarlanır. Örneğin öz nitelik seçimi adımı tekrarlanabilir: Seçilen öz nitelikler bu iş için yeterli olmayabilir; öz nitelik sayısını artırmak ya da seçilen öz nitelikleri değiştirmek gerekebilir.

### 11.2 Anahtar adımlar

Slayttaki adımlar (ekrandan, 02:35:10):

1. Uygulama alanını öğrenmek: ilgili ön bilgi ve uygulamanın amaçları (learning the application domain).
2. Hedef veri setini oluşturmak: veri seçimi (creating a target data set: data selection).
3. Veri temizleme ve ön işleme (data cleaning and preprocessing): emeğin %60'ını alabilir.
4. Veri indirgeme ve dönüştürme (data reduction and transformation): yararlı öz nitelikleri bulmak, boyut/değişken azaltma, değişmez gösterim (invariant representation).
5. Veri madenciliği işlevlerini seçmek: özetleme, sınıflandırma, regresyon, birliktelik, kümeleme.
6. Madencilik algoritmasını (algoritmalarını) seçmek.
7. Veri madenciliği: ilginç örüntüleri aramak (search for patterns of interest).
8. Örüntü değerlendirme ve bilgi sunumu: görselleştirme, dönüştürme, gereksiz örüntüleri ayıklama vb.
9. Keşfedilen bilginin kullanılması.

Hoca adımları şöyle açıkladı: Veri tabanındaki her türlü veriyi geliştirilen sistemde kullanmak mümkün değildir; amaca hizmet eden bir veri seti oluşturulmalıdır.

> **Hocanın vurgusu:** Veri temizleme ve ön işleme adımının yanındaki "emeğin %60'ını alabilir" notuna dikkat. Gerçekten böyledir: İşin son adımına geldiğiniz gün bile hâlâ o veriyle uğraşıyor olacaksınız. Verinin hazırlanması ve temizlenmesi çok fazla vakit alan işlemlerdir.

Veri indirgeme ve dönüştürme (öz nitelik seçme algoritmaları ve dönüştürme işlemleri) dersin dördüncü haftası civarında işlenecek. Uygun yöntemin seçilmesinde amaç belirleyicidir: sınıflandırma mı, regresyon mu, kümeleme mi yapılacak? Buna karar verildikten sonra uygun algoritmalar seçilip veriye uygulanır.

Elde edilen sonucun doğruluğunu ölçmek için değerlendirme parametreleri vardır. Yalnızca doğruluğa (accuracy) bakılmaz; precision gibi başka değerler de kullanılır. Geliştirilen yöntemin ne kadar başarılı olduğu ve kullanılan algoritmalardan hangisinin bu veri setinde daha başarılı olduğu bu ölçütlerle belirlenir.

<!-- BELİRSİZ: 02:37:17'de altyazıda "Precision, default gibi değerlerimiz var" yazıyor; "default" büyük olasılıkla "recall" ya da "F-measure" sözcüğünün yanlış tanınmasıdır. -->

## 12. Veri Madenciliği ve İş Zekası

Slayttaki piramit, iş zekası için katmanları aşağıdan yukarıya şöyle sıralar (ekrandan, 02:38:00):

| Katman (aşağıdan yukarıya) | Açıklama | Sorumlu |
|---|---|---|
| Data Sources | Kâğıt, dosyalar, web belgeleri, bilimsel deneyler, veri tabanı sistemleri | |
| Data Preprocessing/Integration, Data Warehouses | Veri ön işleme, bütünleştirme, veri ambarları | DBA |
| Data Exploration | İstatistiksel özet, sorgulama ve raporlama | |
| Data Mining | Bilgi keşfi (information discovery) | Data Analyst |
| Data Presentation | Görselleştirme teknikleri | Business Analyst |
| Decision Making | Karar verme | End User |

Piramitte yukarı çıktıkça iş kararlarını destekleme potansiyeli artar (increasing potential to support business decisions).

Hoca katmanları şöyle yorumladı: En altta veri kaynakları vardır; verinin hangi alanlardan toplanabileceğine karar verilir. İkinci basamaktaki ön işleme, bütünleştirme ve veri ambarı işleri veri tabanı yöneticisinin (database administrator) yapacağı işlerdir. Veri analisti, veri tabanı yöneticisine bu iş için hangi alanlara ihtiyaç olduğunu bildirir; o da veri tabanından her müşteri için istenen veriyi oluşturur. Veri keşfi (data exploration) kısmı veriyi analiz etmek ve tanımak için gereklidir. Veri analisti asıl olarak veri madenciliği süreçlerinde devreye girer; arkasından veri sunumu ve karar verme aşamaları gelir.

## 13. Çok Disiplinli Bir Alan

Slayta göre veri madenciliği birçok disiplinin kesişimindedir: veri tabanı teknolojisi, istatistik, makine öğrenmesi, örüntü tanıma, algoritma, görselleştirme ve diğer disiplinler (ekrandan, 02:40:00).

Veri madenciliğiyle uğraşan kişinin istatistiği iyi bilmesi, algoritmaları bilmesi, veri tabanı teknolojilerini bilmesi, veriyi nasıl görselleştireceğini bilmesi ve makine öğrenmesi yöntemlerini bilmesi gerekir.

> **Hocanın vurgusu:** Bu derste algoritmaların yalnız adı verilip geçilmeyecek; adımları ve nasıl çalıştıkları, kodlanabilecek düzeyde anlatılacak. Hazır araçlarla (tool) da veri madenciliği yapılabilir, ama bizim bu algoritmaları geliştiren ve iyileştiren tarafta olmamız gerekir. Bu yüzden yöntemlere algoritma düzeyinde hâkim olmak ve iyi algoritma kodlayabilmek önemlidir.

Hoca derse kapanırken öğrencilerden, yaptıkları her işte "veri madenciliği burada ne işe yarar, ne yapabilirim?" diye düşünmeye devam etmelerini istedi.

## Örnek Sorular

**Soru 1** (ekrandan, 01:30:00): Karar ağacı modeli (bez şişmesi evet ise strep throat; hayır ise ateş yoksa allergy, ateş varsa cold) aşağıdaki test hastalarına hangi teşhisi koyar?

| Hasta | Sore Throat | Fever | Swollen Glands | Congestion | Headache | Diagnosis |
|---|---|---|---|---|---|---|
| 11 | No | No | Yes | Yes | Yes | ? |
| 12 | Yes | Yes | No | No | Yes | ? |
| 13 | No | No | No | No | Yes | ? |

Çözüm (derste verildi; python ile doğrulandı):

- Hasta 11: Bez şişmesi "Yes", ağaç ilk soruda durur. Teşhis: **Strep throat**.
- Hasta 12: Bez şişmesi "No", ateş sorulur; ateş "Yes". Teşhis: **Cold**.
- Hasta 13: Bez şişmesi "No", ateş "No". Teşhis: **Allergy**.

**Soru 2** (derste sözlü, 01:28:07): Bu karar ağacı modeli eğitim verisindeki 10 örneğin hepsi için doğru çalışıyor mu?

Çözüm (derste verildi): Evet. Bez şişmesi "Yes" olan 1, 4 ve 7. hastaların hepsi strep throat; bez şişmesi "No" olanlardan ateşi olmayan 2, 6 ve 8. hastalar allergy, ateşi olan 3, 5, 9 ve 10. hastalar cold. Modelin çıktısı 10 örneğin hepsinde uzman etiketiyle aynıdır (python ile doğrulandı).

**Soru 3** (derste sözlü, 02:12:42): Kredi kartı promosyonu veri setinde kaç örnek, kaç öz nitelik var? Bunlardan hangisi sayısaldır?

Çözüm (derste verildi): 15 örnek ve 7 öz nitelik (gelir aralığı, dergi promosyonu, saat promosyonu, hayat sigortası promosyonu, kredi kartı sigortası, cinsiyet, yaş). Sınıf etiketi tanımlanmadığı için hepsi öz nitelik sayılır. Sayısal olan yalnızca yaştır; gelir aralığı aralıklara bölündüğü için kategoriktir.

**Soru 4** (ekrandan, 02:17:30): "IF Sex = Female & $19 \le Age \le 43$ THEN Life Insurance Promotion = Yes" kuralının doğruluğunu ve kapsamasını hesaplayın.

Çözüm (derste verildi; python ile doğrulandı):

- Kadın kullanıcılar 7 kişidir: 2, 5, 6, 10, 11, 13 ve 15. satırlar.
- Bunlardan yaşı 19-43 aralığında olanlar: 2 (40), 5 (38), 10 (41), 11 (43), 13 (39), 15 (19). 6. satır (55 yaş) dışarıda kalır. Koşulu sağlayan 6 kişi vardır.
- Bu 6 kişinin hepsi hayat sigortası promosyonuna "Yes" demiştir. Doğruluk: $6/6 = \%100$.
- Hayat sigortası promosyonuna "Yes" diyen toplam kişi sayısı 9'dur: 2, 4, 5, 7, 10, 11, 12, 13 ve 15. satırlar.
- Kapsama: $6/9 = \%66{,}67$. Kural "Yes" grubunun 6'sını tarif eder; 4, 7 ve 12. satırlardaki 3 erkek dışarıda kalır.

**Soru 5** (derste sözlü, 02:22:53): "IF Sex = Male & Income Range = 40-50K THEN Life Insurance Promotion = No" kuralının doğruluğunu ve kapsamasını hesaplayın.

Çözüm (derste verildi; python ile doğrulandı):

- Erkek ve gelir aralığı 40-50K olanlar: 1 (45 yaş), 3 (42 yaş) ve 14 (55 yaş). Koşulu sağlayan 3 kişi vardır.
- Üçü de hayat sigortası promosyonuna "No" demiştir. Doğruluk: $3/3 = \%100$.
- "No" diyen toplam kişi sayısı 6'dır: 1, 3, 6, 8, 9 ve 14. satırlar.
- Kapsama: $3/6 = \%50$.

**Soru 6** (derste sözlü, 01:42:50): İMKB 100 endeksinin geçmiş bütün kapanış değerleri biliniyor. Endeksin yarınki ya da bir hafta sonraki değerini bulmaya çalışan bir yöntem hangi strateji altında yer alır?

Çözüm (derste verildi): Öngörü (prediction). Çıkış sayısaldır (kapanış değeri) ve gelecekle ilgilidir.

**Soru 7** (derste sözlü, 01:45:18): Oda ve salon sayısı, kat, konum, otopark gibi özelliklerden bir evin fiyatını tahmin etmek hangi problemdir?

Çözüm (derste verildi): Kestirim (estimation). Çıkış sayısaldır ve evin bugünkü (mevcut) fiyatı tahmin edilir. Regresyonla çözülür.

**Soru 8** (derste sözlü, 01:46:18): EKG sonuçlarına göre bir kişinin ileride kalp krizi geçirip geçirmeyeceğini tahmin etmek hangi problemdir?

Çözüm (derste verildi): Çıkış kategoriktir (geçirir/geçirmez) ve gelecekle ilgilidir; kategorik bir öngörüdür. Hoca bunu "sınıflandırma ya da öngörü" olarak niteledi ve aslında geleceğe dönük bir tahmin yapıldığını vurguladı.

**Soru 9** (derste sözlü, 01:46:49): Yaklaşan bir seçimin sonucunu tahmin etmek hangi problem altında değerlendirilir?

Çözüm (derste verildi): Gelecekle ilgili olduğu için öngörüdür. Hangi partinin kazanacağını söylüyorsa çıkış kategorik, her birinin kazanma olasılığını söylüyorsa sayısaldır.

**Soru 10** (derste sözlü, 01:33:52): Sınıf etiketi olmayan Acme yatırımcı veri setiyle eğiticisiz ve eğiticili olarak ne yapılabilir?

Çözüm (derste verildi): Eğiticisiz olarak birbirine benzeyen müşteriler kümelere ayrılabilir. Eğiticili öğrenme için bir öz nitelik (ör. işlem yöntemi ya da margin hesabı) çıkış değişkeni seçilir; böylece online yatırımcının genel profili çıkarılabilir ya da yeni bir müşterinin margin hesabı açıp açmayacağı tahmin edilebilir.

## Dersin Toparlaması

Bu giriş dersinde veri madenciliğinin ne olduğu, neden gerektiği ve hangi başlıklar altında çalışılacağı konuşuldu. Veri madenciliği, büyük veriden önemsiz olmayan, örtük, önceden bilinmeyen ve yararlı örüntüler çıkarmaktır. Pazar analizi, risk analizi, sahtecilik tespiti, churn analizi, metin ve web madenciliği gibi pek çok alanda kullanılır. Stratejiler üç dala ayrılır: eğiticili öğrenme (sınıflandırma, kestirim, öngörü), eğiticisiz kümeleme ve market sepeti analizi. Hasta teşhisi örneğinde bir karar ağacının etiketli veriden nasıl bir model ürettiği ve test örneklerine nasıl uygulandığı görüldü. Kredi kartı promosyonu veri setinde ise üretim kurallarının doğruluk ve kapsama ölçüleriyle nasıl değerlendirildiği hesaplandı.

Son bölümde bilgi keşfi (KDD) sürecinin adımları ve geri besleme döngüsü, iş zekası piramidi ve alanın çok disiplinli yapısı anlatıldı. Hoca veri temizleme ve ön işlemenin emeğin büyük kısmını aldığını vurguladı. Bir sonraki ders veri türleri ve veri yapılarıyla devam edecek; ilk haftalar veri hazırlama tekniklerine ayrılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
