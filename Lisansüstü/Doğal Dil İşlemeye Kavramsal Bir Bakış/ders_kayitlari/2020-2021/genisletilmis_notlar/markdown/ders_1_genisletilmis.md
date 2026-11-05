# Ders 1 Genişletilmiş Notu: Doğal Dil İşlemeye Genel Bakış ve Dersin İşleyişi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yaklaşımı ve Kapsamı
- 2. Konu Listesi
- 3. Kaynaklar
- 4. Dil Nedir?
- 5. Dili Bilgisayara Aktarmak ve Dil Bilimcilerin Rolü
- 6. Doğal Dil İşleme Uygulamaları
- 7. Doğal Dil İşlemedeki Zorluklar
- 8. Alanın Gelişimi ve Diller
- 9. Bilgisayarın Gözünden Dil
- 10. Doğal Dil İşlemenin Yapay Zekadaki Yeri
- 11. Dil Analizinin Seviyeleri
- 12. Biçimbilimsel Analiz ve Zemberek
- 13. Söz Dizimi Analizi: POS Etiketleri, Eş Dizimlilik ve Ayrıştırma
- 14. Söz Dizimi Analizindeki Diğer Problemler
- 15. Anlamsal Analiz ve Kelime Anlamı Belirginleştirme
- 16. Bilgiye Erişim, Bilgi Çıkarımı ve Soru Cevaplama
- 17. Makine Çevirisi ve Paralel Derlem
- 18. Söylem (Discourse)
- 19. Edim (Pragmatics)

Bu ders, Prof. Dr. Banu Diri'nin verdiği lisansüstü "Doğal Dil İşlemeye Kavramsal Bir Bakış" dersinin ilk dersidir. Hoca dersin ilk bölümünde dersin işleyişini anlatır, ardından dersin kapsamına ve doğal dil işlemenin (Natural Language Processing, NLP) genel bir haritasına geçer. Bu ders boyunca anlatılan konuların çoğu ilerleyen haftalarda ayrı ayrı ve daha ayrıntılı işlenecektir; bu ders onların bir ön tanıtımıdır.

## 1. Dersin Yaklaşımı ve Kapsamı

### 1.1 Ders Nasıl Anlatılacak?

Ders slaytlar üzerinden anlatılır. Bazı konular ise tahtada anlatılmayı gerektirir; bunları PowerPoint'e dökmek zordur. Hoca bu konular için tahtada anlatır gibi bir video çekip derste göstermeyi planlar. Ders slaytları hocanın AVESİS sayfasında bulunur. Hoca slaytları çevrim içi derse göre her hafta güncelleyebileceği için hepsinin toplu olarak indirilmemesini ister.

Hoca terimleri hem Türkçe hem İngilizce vereceğini söyler. Literatürün dili İngilizcedir; kaynak okumaya kalkıldığında karşılaşılacak terimler İngilizcedir. Ayrıca bazı Türkçe karşılıklar pek bir şey ifade etmez.

> **Hocanın vurgusu:** "Pragmatik" kelimesinin Türkçesi "edim"dir. Hoca, kulağına kırk kere "edim" deseler bunun pragmatiğin karşılığı olduğunu bilemeyeceğini söyler. Bu yüzden terimler her zaman İngilizceleriyle birlikte verilecektir.

### 1.2 Dersin Değerlendirme Mantığı (Akademik Yönü)

Dersin idari ayrıntıları bu notun kapsamı dışındadır. Ancak dersin nasıl çalışılacağını belirleyen iki nokta akademik olarak önemlidir.

Birincisi, ders **proje ağırlıklıdır**. Dönem sonunda öğrencinin "başı ve sonu olan" bir projeyi çalışır hâlde göstermesi beklenir. Hoca bunun lisansüstü seçimlik derslerin doğası olduğunu söyler. Seminer konuları da projeye dönüşebilecek konulardan seçilecektir. Böylece seminerde okunan makale, projede işe yarar.

> **Hocanın vurgusu:** Bu ders "dipsiz bir kuyu"dur. Her konudan bir proje çıkar, ama bazı konular bir iki ayda değil, ancak bir yılda bitebilecek büyüklüktedir. Projeler bu kadar büyük seçilmemelidir.

İkincisi, konu sayısı çok fazla olduğu için vize çoktan seçmeli olacaktır. Amaç, her konu başlığının altındaki "olmazsa olmaz" kavramların akılda kalıp kalmadığını ölçmektir.

> **Hocanın vurgusu:** Hoca bir şeyi derste ne kadar çok tekrar ediyor ve vurguluyorsa, o şey o konunun temel anahtar kelimesi ve tanımıdır.

Projelerde dil kısıtı yoktur; Türkçe ya da İngilizce üzerinde çalışılabilir. Programlama dili olarak hoca Python önerir. Python'da çok sayıda doğal dil işleme kütüphanesi vardır ve onlarca satırlık bir iş tek bir komutla yapılabilir. Java da kullanılabilir. Bunların dışındaki dillerde ise pek çok şeyi sıfırdan yazmak gerekir, bu da vakit kaybıdır.

### 1.3 Dersin Adı Neden "Kavramsal Bir Bakış"?

Dersin kapsamı çok geniştir. Hoca, dersin içeriğinin anlatanın kökenine göre değişeceğini söyler. Elektronik kökenli biri sinyal işleme tarafını öne çıkarır ve dersi konuşmadan metne (speech to text) ve metinden konuşmaya (text to speech) dönüşüm üzerine kurar. Hoca bilgisayar bilimleri kökenli olduğu ve çalışma alanları bu yönde olduğu için dersi veri madenciliği ve **metin işleme (text processing)** ağırlıklı anlatır.

Yurt dışındaki üniversitelerde bu dersteki konuların birçoğu tek başına bir dönemlik derstir: bilgiye erişim (information retrieval), makine çevirisi (machine translation), makine öğrenmesi (machine learning), soru cevaplama (question answering). Bu derste ise her biri yaklaşık bir haftaya sığdırılır. Amaç, her konuda neler yapıldığını, hangi yöntemlerin kullanıldığını ve hangi çalışmaların bulunduğunu görmektir. Dersin adının "kavramsal bir bakış" olmasının sebebi budur.

### 1.4 Dersin İki Parçası

Ders iki parçadan oluşur.

- **Birinci parça:** dil biliminin ilgilendiği klasik çözümleme aşamaları (biçim bilim, söz dizimi vb.). İngilizce için bu aşamaların neredeyse hepsi hazır araçlara (tool) dönüştürülmüştür ve %95-98'in üzerinde başarılar elde edilmiştir. Bu aşamalarda "gelinebilecek noktaya gelinmiştir". Anlam bilgisi, söylem ve edim bilgisi ise bunun dışında kalır; bunlar hâlâ çözülmeye çalışılmaktadır. Türkçe için araçlar vardır ve iş görür, ama eksiktir; çünkü Türkçe üzerindeki çalışmalar son yıllarda başlamıştır.
- **İkinci parça:** "yapay zeka uygulaması" denilen kısım. Bunlar birinci parçadaki araçları kullanır ve hayatımıza daha yeni girmiş kavramlardır.

Hoca, Türkçe için bazı eksik aşamaların tamamlanmasının bir doktora çalışması niteliğinde olduğunu, bunlara da zaten başlanmış olduğunu söyler. Bu yüzden projede "tekerleği yeniden icat etmek" anlamsız olur.

## 2. Konu Listesi

Hoca slayttaki konu listesini tek tek açıklar:

- **Doğal Dil İşlemeye Genel Bakış (Course Overview):** bu dersin konusu.
- **Dilbiliminin Esasları (Linguistics Essentials):** hocanın deyişiyle "biraz sıkıcı", çok sözel bir konu.
- **Gramer ve Diller (Grammar and Languages)**.
- **Düzenli İfadeler (Regular Expressions):** bu konuyla ilgili küçük bir ödev verilecek.
- **Dil Modelleri ve N-gram (Language Models):** bu konuyla ilgili de küçük bir ödev verilecek.
- **Biçimbilimsel Analiz (Morphological Analysis)**.
- **Söz Dizimsel Analiz (Syntax Analysis)** ve **sözcük türü etiketleme (Part of Speech, POS tagging)**.
- **Anlam Bilgisi (Semantics), Söylem (Discourse) ve Edim (Pragmatics)**.
- **Eş Dizimlilik (Collocation)**.
- **Saklı Markov Modelleri (Hidden Markov Models) ve Viterbi algoritması:** slaytta italik yazılıdır. Hoca bunu anlatıp anlatmayacağını haftanın durumuna göre belirleyeceğini söyler. Kullanan zaten hazır kodu alıp kullanır.
- **Makine Öğrenmesi:** bir dönemlik ders 1-2 saatte özetlenecek, böylece projelerde kullanılabilecek.
- **Metin Sınıflandırma (Text Classification)**.
- **Bilgiye Erişim Sistemleri (Information Retrieval)**.
- **Bilgi Çıkarımı (Information Extraction)**.
- **Kelime Anlamları (Word Semantics):** eş anlam, zıt anlam, üst anlam, alt anlam, eş seslilik gibi ilişkilerin hangi ortamlarda tutulduğu anlatılacak.
- **Kelime Gömmeleri (Word Embeddings):** her dönem yeni bir model çıktığı için sürekli güncellenen bir konu. RNN, CNN, LSTM gibi modeller derinlemesine anlatılmaz; bunlar derin öğrenme dersinin konusudur. Yalnız hangi modelin neden kullanıldığı söylenecek.
- **Duygu Analizi (Sentiment Analysis)**.
- **Soru Cevaplama Sistemleri (Question Answering)**.
- **Makine Çevirisi (Machine Translation):** slaytta italik. Hoca bu konuyla hiç çalışmadığını ve "çekindiği" bir konu olduğunu söyler.
- **Projeler, araştırma ödevi, seminer**.

Hoca bu listeden iki konunun önemini ayrıca vurgular.

> **Hocanın vurgusu:** Dil modelleri "deyip geçmeyin". Dil modeli olmadan bilgisayarda dille ilgili hiçbir çalışma yapılamaz. Derin öğrenme hayatımıza girmeden önce NLP çalışmaları ya kural tabanlı ya da istatistiksel yöntemlerle yapılıyordu; onlarda da dil modelleri çok önemliydi.

> **Hocanın vurgusu:** Anlam bilgisi, söylem ve edim soyut kavramlardır ama NLP'de çözülmeleri çok önemlidir. Robotların bizimle konuşması, bizi "canlı bir insan gibi" algılaması isteniyorsa bu konularda ciddi ilerleme gerekir. Türkçe için böyle bir şey henüz söz konusu değildir; İngilizce için de tamamlanmış bir çözüm yoktur.

Hoca ayrıca POS kavramını kısaca tanıtır. "Çocuklar" kelimesinde "çocuk" bir isimdir, "-lar" bir ektir. Bunların etiketlenmesi gerekir; bu etiketlere POS etiketleri denir.

## 3. Kaynaklar

- **Daniel Jurafsky ve James H. Martin, "Speech and Language Processing":** temel ders kitabı. Hoca, dünyada bu dersin verildiği hangi üniversiteye bakılırsa bakılsın temel kaynağın bu kitap olduğunu söyler. Her yeni baskıda yaklaşık 200 sayfa eklendiği için "artık taşınamayacak" kadar büyümüştür. Kitabın ilk yarısı sinyal işleme, metinden konuşmaya ve konuşmadan metne dönüşümle ilgilidir.
- **Christopher Manning ve Hinrich Schütze, "Foundations of Statistical Natural Language Processing"**.
- **İnternet:** Hoca, yıllar önce internette bu kadar bilgi olmadığı için kitapların önemli olduğunu söyler. Bugün bu kitapların bölümleri bile internette bulunabilir. Başka üniversitelerin bu derse ait slaytları da çoğu zaman açık paylaşılır; bazıları şifreyle erişilebilir.

## 4. Dil Nedir?

Hoca bu dersi ilk verdiğinde sınıfa "Dil nedir?" diye sorduğunu anlatır. Bir öğrenci el kaldırıp "ağzımızın içindeki organ" demiştir. Bu cevap ne doğru ne yanlıştır; ama bu dersin konusu o organ değildir.

**Tanım:** Dil, sözcük ve cümle birimleri aracılığıyla düşünceyi konuşma ile ilişkilendiren **çok seviyeli** bir sistemdir. Neden "çok seviyeli" olduğu, dil analizinin seviyeleri anlatılırken görülecektir (Bölüm 11).

Hoca dil alanındaki en ünlü isimlerden birinin Noam Chomsky olduğunu, "Chomsky hiyerarşisi"nin diller konusu anlatılırken işleneceğini söyler.

Dilin ortaya çıkışını şöyle anlatır: İnsanlar önce dumanla, el kol hareketleriyle anlaştı. Bu yetmeyince sesler çıkarmaya başladılar. Bu sesler bize anlamsız görünse de her biri bir şey anlatıyordu; acı çekerken çıkarılan ses, mutluyken çıkarılan sesle aynı değildir. Sonra sesler kelimelere, kelimeler arka arkaya konarak cümlelere, cümleler paragraflara, paragraflar da dokümanlara dönüştü. Kısacası dil, insanlar arasında kullanılan bir **iletişim aracıdır**.

## 5. Dili Bilgisayara Aktarmak ve Dil Bilimcilerin Rolü

### 5.1 Dili Modellemek

Bir dili bilgisayara aktarabilmek için o dili **modellemek** gerekir. Bazı diller çok basittir ve modellenmesi kolaydır; ama çok basit bir dilin bilgisayara aktarılmasına zaten pek gerek yoktur.

### 5.2 Sondan Eklemeli Diller

Türkçe gibi diller **sondan eklemeli (agglutinative)** dillerdir ve bunlarla çalışmak gerçekten zordur. Hoca bunu "book" ve "kitap" kelimeleriyle karşılaştırır:

- İngilizcede "book" yalnızca birkaç biçim alır: "-s", "-ing" ve fiil olarak kullanılıyorsa "-ed". Bu kadar.
- Türkçede "kitap" kelimesine eklenebildiği kadar ek eklenebilir: kitabı, kitaba, kitapta, kitaptan, kitabımız, kitabıydı...

Fince ve Japonca da sondan eklemeli dillerdir. Japoncanın alfabesi farklı olsa da yapısı sondan eklemelidir.

> **Hocanın vurgusu:** Türkçe sondan eklemeli olduğu için işlenmesi zor bir dildir.

### 5.3 Dil Bilimcilerle Ortak Çalışma

İlk doğal dil işleme çalışmalarında yalnızca bilgisayar bilimcilerin olması yeterli değildi. Dilin modelini çıkarmak için dil bilimcilerle (linguists) çalışmak gerekiyordu. Hoca bunun sebebini şöyle açıklar: Türkçe konuşup yazsak da çoğu zaman yanlış cümle kurar, kelimeleri yanlış yazarız ve kelimelerin kökenini bilmeyiz. Oysa bir kelimenin kökenini bilmek, ona hangi eklerin gelebileceğini belirler.

Bu yüzden dil bilimciler dilin modelini kâğıt üzerinde çıkarıp bilgisayarcıların önüne koydu; bilgisayarcılar da bunu kodladı. Hoca bunu bir mimarın binayı çizip inşaat mühendisine vermesine benzetir. Daha sonra dil bilimciler bu çalışmaların içinden çekildi.

## 6. Doğal Dil İşleme Uygulamaları

### 6.1 Yazım Yanlışı Denetimi

Doğal dil işlemenin ilk uygulaması olarak her zaman yazım yanlışlarının düzeltilmesi söylenir. Hoca kendi lisans yıllarını anlatır: Fare (mouse) yoktu, kişisel bilgisayarlar yoktu, ana bilgisayarlar (mainframe) ve satır editörleri (line editor) kullanılıyordu. Editörde klavyedeki ok tuşlarıyla bir yere gidip yazı yazılırdı. Yanlış yazılan kelimenin altının çizilmesi ya da "bunu mu demek istediniz?" önerisi yoktu. Kelime işlemciler hayatlarına lisansın son yıllarında girdi.

Bir kelimenin altının hatalı diye çizilmesi için arkada bir uygulamanın çalışması gerekir. Örneğin "çocukler" yazıldığında editör "-ler" ekinin altını çizer. Çünkü arkadaki dil modeli "çocuk" kelimesinin "-ler" eki almayacağını bilir (ünlü uyumu gereği "-lar" almalıdır).

### 6.2 Makine Çevirisi

İnsanların en büyük ihtiyaçlarından biri bir dilden diğerine çeviridir. Çeviri sistemleri önce İngilizce ile ona yakın diller arasında başladı; bu yüzden o diller arasındaki çeviri bugün çok daha ileridedir. Bu sistemler başlangıçta **yarı otomatikti**: makine çevirir, hatalı yerleri bir insan düzeltir.

Hoca bugün de birçok öğrencinin yayın ya da tez yazarken aynısını yaptığını söyler: Türkçe metni Google Translate'e verip İngilizcesini olduğu gibi kopyalamak. Sonuç "tercüme kokar", çünkü Türkçeden çeviri o kadar başarılı değildir. Çıktının elle düzeltilmesi gerekir.

Google Translate'in son yıllardaki başarısının sebebi derin öğrenmeye geçmesidir. Kısa cümleler rahatça çevrilir, ama 3-4 satırlık uzun cümlelerde başarı düşer. Hoca bunu insanla karşılaştırır: İnsan da 3 satırlık bir cümleyi okuyup "pat diye" çeviremez. Cümleyi anlam parçalarına bölüp her birini ayrı bir cümleymiş gibi düşünür. Bunu bilgisayara yaptırmak için çok sayıda gizli katmanı (hidden layer) olan derin ağlar ve bir kelimenin önündeki ve arkasındaki kelimelerle ilişkilerini kullanan modeller gerekir. Hoca, GPU'lu bile olsa elimizdeki kişisel bilgisayarlarla bunun çok zor olduğunu, az veriyle eğitilirse de sistemin başarısız olacağını söyler.

### 6.3 Soru Cevaplama

Soru cevaplamanın üç düzeyi vardır.

**Veri tabanı tabanlı sistemler.** Örnek soru: "Bugün günlerden perşembe, saat 9'da hangi dersim var?" Elde üniversitedeki bütün bölümlerin bütün derslerinin gün ve saatleriyle yazılı olduğu bir veri tabanı olsun. Yapılacak iş, cümleden ilgili anahtar kelimeleri seçmektir: "hangi" diye sorulmuş, sorulan şey "ders". Bunlardan bir SQL sorgusu kurulur; sorgu dersler tablosuna gidip o gün ve saatle çakışan dersi getirir. Cevap: "Doğal Dil İşleme." Bu tip sistemler oldukça başarılıdır.

**Konuya odaklı (closed domain) sistemler.** Örneğin yalnızca bir bankanın müşterilerinin sorularına cevap veren bir sistem. Müşterilerin ne tür sorular sorduğu bellidir, sistem buna göre hazırlanır. Başarı yüksektir.

**Açık alan (open domain) sistemler.** "İnternette ne sorarsan sor" türü sistemlerde başarı hemen düşer.

Ayrıca bazı sorular **iç içedir**. "Türkiye'nin başkenti neresidir?" sorusunun cevabı (Ankara) kolay bulunur. Ama "Mustafa Kemal Atatürk'ün kurduğu devletin başkenti neresidir?" sorusunda önce hangi devletin kurulduğu (Türkiye) bulunmalı, sonra onun başkenti aranmalıdır. Hocanın diğer örneği: "Banu Diri bugün hangi dersi veriyor?" Önce hocanın hangi bölümde olduğu, sonra o bölümün bugünkü dersleri bulunur ve eşleştirilerek cevap verilir.

### 6.4 Diğer Uygulamalar

- **Bilgisayar destekli dil öğretimi:** hocanın deyişiyle basit bir uygulama, "fazla bir esprisi yok".
- **Çok dilli ve tek dilli sözlüklere erişim:** Aranan bilgi yalnızca Fransızca sayfalarda olsun ve kullanıcı Fransızca bilmesin. Soru Türkçe sorulur. Sorudaki ilgili kelime bulunur, Türkçe-Fransızca sözlükle çevrilir ve arama motoruna gönderilir. Gelen sayfanın içinden cevap bulunur ve tekrar kullanıcının diline çevrilir. Bu zincirde bilgiye erişim (bilgiyi getirmek), bilgi çıkarımı (bilgiyi sayfadan çıkarmak) ve soru cevaplama (olayın tamamı) iç içedir. Araya bir de sözlük girer. Sözlükte de bir kelimenin birden fazla anlamı olduğu için doğru anlamı seçmek ayrı bir problemdir (Bölüm 15).
- **Cümle ve metin üretme:** Hoca "size 6 kelime verdim, bu kelimeler geçecek şekilde anlam bütünlüğü olan cümleler kurun" türü oyunları hatırlatır. İnsanın yaptığı bu işi bilgisayara yaptırmak amaçlanır.
- **Metin özetleme:** Hoca ilkokulda her gün "şu metni 10 kere oku, anlat ve özetini çıkar" ödevi verildiğini anlatır. Bir süre sonra sınıf, metinden birinci, üçüncü, yedinci cümleyi seçip yazmaya başlamış; öğretmen bunu fark edip öğrencilere okuttuğunda ortaya "komik" özetler çıkmış. Bu anı üç özetleme türünü açıklar:
  - Metni en iyi anlatan cümleleri metnin içinden seçmek. Bu kolay bir özetleme biçimidir.
  - Aynı konuyu anlatan birden fazla metinden tek bir ortak özet çıkarmak. Burada sorun, aynı olayın farklı cümlelerle anlatılmış olabilmesidir. Aynı anlamı veren cümlelerin tespit edilip özete bir kez alınması gerekir.
  - Yorumlayarak özetleme: okuyup anladığını kendi cümleleriyle yazmak. Bu çok zordur. Derin öğrenmeyle şekillenmeye başlamıştır, çünkü derin öğrenmede çok ayrıntılı bilgiler sisteme öğretilebilir.
- **Otomatik konuşma ve komut anlama:** "Açıl", "kapan" gibi sesli komutları kişinin sesini tanıyarak yerine getiren uygulamalar.
- **Metinden bilgi çıkarma:** Hoca örnek verir: "Size bir sürü firmanın web adresini verdim. Bu sayfalardan şirketlerin telefon numaralarını ve posta adreslerini çıkarın." Bunu tek tek okuyarak yapmak yerine bir kez uygulama yazıp hepsini çıkarmak daha kolaydır.

### 6.5 Konuşmadan Metne mi, Metinden Konuşmaya mı?

Hoca sınıfa hangisinin daha zor olduğunu sorar. Bir öğrenci konuşmadan metne (speech to text, STT) dönüşümün daha zor olduğunu söyler; bir başkası metinden konuşmaya (text to speech, TTS) dönüşümü söyler. Hoca birinci cevabı doğrular.

**Metinden konuşmaya daha kolaydır.** Metin düzgün yazılmış kelimelerden oluşur. Örneğin "otomatik" kelimesi hecelerine bölünür ("o-to-ma-tik"), her hecenin sesi alınır ve birbirine eklenir. Yalnızca eklemek robot gibi bir konuşma verir. Kelimede vurguların nerede olduğu da işaretlenirse daha insan gibi bir konuşma elde edilir. Yani bu problem çözülebilir.

**Konuşmadan metne daha zordur.** Sebepleri:

- Konuşanların şivesi ve lehçesi farklı olabilir.
- Bazıları çok hızlı konuşur ve hiç duraklamaz; cümlenin nerede başlayıp bittiği belli olmaz.
- Bazıları tutuk konuşur.
- Telaffuz hatalı olabilir. Örneğin "geliyorum" yerine "celiyorum" denirse, böyle bir kelime olmadığı için sistem bunu dil modeliyle doğru kelimeye bağlamak zorundadır.

Sonuçta anlaşılmayan kelimeler çıkar, cümleler bölünemez, yanlış telaffuz edilen kelimeler yakalanamaz.

### 6.6 Hedef: Klavyesiz ve Faresiz Bilgisayar

Hoca bu alandaki uzun vadeli hedefi şöyle özetler: Bir gün klavye ve fare kullanmadan, göz hareketleri ve sesle bilgisayara iş yaptırabilmek. Buna düşünce gücü de eklenirse "iş çığırından çıkmış" demektir.

## 7. Doğal Dil İşlemedeki Zorluklar

### 7.1 Kuralsız Konuşma ve Bozuk Yazı

İnsanlar çoğu zaman kuralsız ve anlaşılmaz konuşur. Arkadaşlar arasında kullanılan argo sözler ("len" gibi), konuşmaya eşlik eden hareketler bilgisayara anlatılamaz. Kelimeler bilgisayara tanıtılabilir, ama konuşmada o kadar çok "apuk sapuk" kelime ve cümle kullanılır ki hepsini aktarmak mümkün değildir.

Kuralsız ve bozuk yazılar önce düzeltilmelidir. Slayttaki örnekte "kelebekler" kelimesi bir harfi eksik yazılmıştır. Böyle hatalar için eksik harfi ekleme (insertion) ya da yanlış harfi değiştirme (substitution) gibi işlemler gerekir.

<!-- BELİRSİZ: Slayttaki bozuk yazılmış "kelebekler" örneğinin tam hâli slaytta. Hoca önce iki harfin yer değiştirdiğini söyleyip sonra "E harfi eksik" diye düzeltiyor; hangi biçimin yazıldığı altyazıdan anlaşılmıyor. -->

### 7.2 Konuşmayı ve Metni Bölmek

Hiç durmadan konuşan birinin konuşmasında cümlenin nerede başlayıp nerede bittiği belli değildir. Hoca bunu kendi konuşmasıyla örnekler: "Mesela şimdi konuştuğum gibi ne zaman duracağımı bilmiyorsunuz." Benzer şekilde yazılı metinde de paragraf uzunluğunda cümleler olabilir ve bunların da işlenmeden önce bölünmesi gerekir.

### 7.3 Yanlış Çeviri: "Köprücüler İstanbul'da Toplanıyor"

Hoca çok sevdiği bir örneği sınıfa sorar: "Köprücüler İstanbul'da toplanıyor." Bu cümleden ne anlaşılır? Öğrencilerden gelen cevaplar:

- Köprü yapan inşaat firmaları İstanbul'da toplanıyor.
- Köprü meraklıları ya da köprü fotoğrafı çekenler bir araya geliyor (Volkswagen meraklılarının buluşması gibi).
- "Köprücü" ünlü bir ailenin soyadıdır ve aile İstanbul'da toplanıyor.

Gerçek ise şudur: Bu bir İngilizceden Türkçeye çeviridir. İngilizce haberde "bridge" kelimesi geçer. Otomatik çeviri sözlükteki ilk anlam olan "köprü"yü almış ve kimse haberin içeriğine bakmadan bunu yayımlamıştır. Oysa "bridge" aynı zamanda bir kâğıt oyunudur: briç. Doğru çeviri "Briç oyuncuları İstanbul'da toplanıyor" olmalıydı; yani bir satranç turnuvası gibi bir briç turnuvası söz konusudur.

> **Hocanın vurgusu:** Bir yanlış çeviri insanı çok büyük yanlışlara sürükler. Böyle bir cümle analiz edilirse bambaşka anlamlar çıkar. Bir yanlış diğer yanlışı getirir.

### 7.4 Söz Dizimsel Olarak Aynı, Anlamca Farklı Cümleler

Hoca iki cümle verir:

- "Banu armutları ayılara **aç** oldukları için verdi."
- "Banu armutları ayılara **tatlı** oldukları için verdi."

İki cümlede de bütün kelimeler aynıdır; yalnız "aç" ve "tatlı" farklıdır. İkisi de söz dizimi açısından doğru Türkçe cümlelerdir. Ama anlamları bambaşkadır:

- Birincisinde Banu merhametli biridir: Ayıların aç olmasına dayanamamış ve onlara armut vermiştir.
- İkincisinde Banu "biraz bencildir": Tatlı armudu sevmediği için yiyememiş, armutlar çöpe gitmesin diye ayılara vermiştir.

Bu anlam farkı kelimeler arasındaki ilişkilerden çıkar. Armut aç olamaz; o hâlde "aç" ayılarla ilişkilidir. "Tatlı" ise armutlarla ilişkilidir. Kelimeler arasındaki bu ilişkiler kurulmadan istenen anlam çıkarılamaz.

### 7.5 NLP Problemlerinin Genel Hâli

NLP problemleri çok fazla belirsizlik içerir. Hoca bunları "NP problemler" olarak niteler ve şöyle açıklar: $x$, $x^2$ ya da $x^3$ zamanda çözülen bir problemin sınırı bellidir. Ama $x^n$ gibi bir durumda hem $x$ hem $n$ bilinmiyorsa çözüm süresi ortada yoktur. Bu yüzden bu problemlerin genel hâli çözülemez. Az da olsa çözebilmek için problem **belirli, dar bir hâle** getirilir ve o özel problem çözülmeye çalışılır.

> **Ders sonrası not:** Hoca "NP" kısaltmasını "non-polynomial" olarak açıkladı. Doğrusu: NP, "nondeterministic polynomial time" (belirlenimci olmayan polinom zaman) sınıfının kısaltmasıdır; "polinom zamanda çözülemeyen" demek değildir. Bir problemin NP'de olması, önerilen bir çözümün polinom zamanda doğrulanabilmesi demektir. Hocanın asıl vurgusu ise geçerlidir: Bu problemlerin genel hâli için verimli bir çözüm bilinmez, bu yüzden problem daraltılarak çözülür.

### 7.6 Bu Zorluklar NLP ile mi Çözülüyor?

Aradan sonra bir öğrenci, bu zorlukların NLP'nin kendisiyle mi yoksa ek yardımcı algoritmalarla mı çözüldüğünü sorar.

**Soru:** Bu zorlukların çözümü NLP ile mi, yoksa ayrı yardımcı algoritmalarla mı yapılıyor?

**Cevap:** Her zorluk için ayrı bir uygulama yazılır; bazı durumlar için bunlar yazılmıştır. Ama bunları yazmak çok emek ve zaman alır ve problemi tam çözüp çözemeyeceğiniz de belli değildir. Sistemin başarısı %80 iken bu ek çalışmayla %82'ye çıkacaksa, bu %2 için o kadar emeğe değip değmeyeceğine çalışmayı yapan kendisi karar verir.

## 8. Alanın Gelişimi ve Diller

### 8.1 NLP Neden Son Yıllarda Popüler Oldu?

Hoca kendi doktorasına başladığında doğal dil işleme alanında çalışmadığını anlatır. Farklı alanlarda çalışmış, iki kez doktora konusunu değiştirmiştir. O yıllarda NLP popüler değildi; neredeyse herkes görüntü işleme üzerine çalışıyordu. Robotik ve doğal dil işleme gibi alanlar son 10 yılda önem kazanmaya başladı. Görüntü işleme çalışmaları hâlâ sürmektedir, çünkü o da yapay zekanın bir alt dalıdır; ama NLP gibi alanlar uzun süre "bakir" kalmıştır.

Bu yükselişin ardında internet vardır. Doküman sayısı **üstel (exponential)** olarak artmaktadır.

> **Hocanın vurgusu:** Yazılı bir belge işlenmediği sürece arşivde kalmaya mahkûmdur. Onu kullanmak, ona erişmek çok zordur. Önemli olan belgeleri işleyip kullanılabilir **bilgiye** dönüştürmektir.

### 8.2 Çalışmaların Dili

Yayınların büyük çoğunluğu İngilizce üzerinedir. Son yıllarda Çince için yapılan çalışmalar artmıştır; dünyadaki Çince konuşan nüfus düşünülürse bu normaldir. Bu alandaki yazılımların çoğunu Alman, İngiliz, Amerikalı, Hollandalı ve Japon araştırmacılar geliştirmiştir. Hoca, ABD'den çok sayıda yayın çıktığını ama yazarların büyük bölümünün doktora için gidip orada kalan Uzak Doğulu araştırmacılar olduğunu da ekler.

### 8.3 Doğal Diller ve Yapay Diller

Diller ikiye ayrılır:

- **Yapay diller:** kullandığımız programlama dilleri.
- **Doğal diller:** konuşma dillerimiz.

Hocanın verdiği bilgiye göre yeryüzünde 3000 ile 4000 arasında dil vardır. Aradaki fark bin kadar oynasa da sayı üç binden az değildir. Bazı diller yalnızca bir kabile tarafından konuşulur ve 10-20 kelimeyle sınırlıdır. Büyük diller üzerinde ise bütün çalışmalar yapılmaktadır.

Slayta göre UNESCO'nun belirlediği büyük diller Çince, İngilizce, İspanyolca, Rusça, Fransızca ve Arapçadır. Slaytta Türk dili ve lehçelerinin 5. sırada olduğu yazar. Hoca bu bilginin kaynağına ve yılına referans vermediğini, bilgiye bir daha erişemediğini söyler; yani bu sıralama doğrulanmış bir bilgi değildir.

Genel kültür olarak hoca ilk yapay dilin Zamenhof'un ortaya attığı **Esperanto** olduğunu söyler.

### 8.4 Aynı Aileden Diller ve Kültür Farkı

Azerice Türkiye Türkçesine çok yakın bir dildir. Ama hoca bir Azeri haber kanalını dinlediğinde hemen anlayamadığını, uyum sağlamasının zaman aldığını söyler. Bazı kelimelerin kullanımı da farklıdır. Bir Azeri spiker "Türk Hava Yolları'nın şu sefer sayılı uçağı düştü" derse Türkiye'de panik olur; oysa Azericede uçağın yere inmesi için "düşmek" fiili kullanılır, yani kastedilen "uçak indi"dir.

> **Hocanın vurgusu:** Aynı dil ailesinden gelseler bile diller arasında kültür farkı çok önemlidir. Bu fark bilinmezse olay bambaşka algılanır.

## 9. Bilgisayarın Gözünden Dil

Hoca slayta beş cümle koyar ve sınıfa bunlardan bir şey anlayan olup olmadığını sorar. Kimse bir şey anlamaz. Hoca, 3000-4000 dil olduğuna göre bunların da bir dil olabileceğini, ama o dili bilmiyorsak bize hiçbir şey ifade etmeyeceğini söyler.

<!-- BELİRSİZ: Slayttaki beş "bilinmeyen dil" cümlesi altyazıda okunmuyor. Hoca ikinci ve üçüncünün tanıdık sesli-sessiz harf düzenine benzediğini, birinde "monster" benzeri bir kelime gördüğünü, birinci, dördüncü ve beşinciden ise hiçbir şey çıkaramadığını söylüyor. -->

> **Hocanın vurgusu:** Bilgisayar bizim kullandığımız doğal dile, bizim hiç bilmediğimiz bir dile baktığımız gözle bakar. Hiçbir şey anlamaz. Bu yüzden dili ona adım adım anlatmak gerekir. Bunun için dil modelleri, dilin istatistiği ve kelimelerin birbiriyle ilişkisi ve kullanımı çok önemlidir.

Bunun ötesinde, insanların bile zorlandığı belirsizlikler vardır. Bağlam (context) elde değilse insanlar da yanlış yorum yapabilir.

### 9.1 İnsanı Bilgisayardan Ayıran Şeyler

- İnsanlar **sağduyuya (common sense)** sahiptir; bilgisayar değildir.
- İnsanlar mantıklı düşünüp **kıyaslama** yapabilir; bilgisayar yapamaz.
- İnsanların **deneyimi** vardır. Bilgisayarda deneyim ancak ona öğrettiğimiz kadar olur.

Bilgisayarın insandan üstün olduğu tek taraf, öğrendiğini **hiç unutmamasıdır**. Öğrenme onda hiyerarşik olarak katlanarak ilerleyebilir. Hoca, insanın bazen yeni bir bilgiye yer açmak için eski bir bilgiyi unutması gerektiğini, bilgisayarın ise bütün bilgiyi aynı anda verilmiş gibi kullanabildiğini söyler.

## 10. Doğal Dil İşlemenin Yapay Zekadaki Yeri

Slayttaki hiyerarşi şöyledir:

```text
Bilgisayar bilimleri
└── Yapay zeka
    ├── Robotik
    ├── Uzman sistemler
    ├── Örüntü tanıma
    ├── Görüntü tanıma
    ├── Veri madenciliği
    └── Doğal dil işleme
        ├── Dil analizi (anlam bilim, ayrıştırma / parsing)
        └── Bu dersteki diğer konu başlıkları
```

Hoca, yapay zekanın altındaki bu konuların lisansta da zorunlu dersler olarak okunduğunu hatırlatır. Dil analizinin altındaki ayrıştırma ve anlam bilim kısmı, dersin birinci parçasını oluşturur; dil bilimcilerin asıl ilgilendiği bölüm budur.

## 11. Dil Analizinin Seviyeleri

### 11.1 Konuşma Dili ve Yazı Dili

Dil, konuşma dili ve yazı dili olarak ikiye ayrılır. Konuşma dilinde pek kural yoktur; insanlar akıllarına geldiği gibi konuşur. Bir turist "Ben gitmek Sultanahmet" dese bile onu anlarız. Ama bu cümle yazı diline geçirilirse bilgisayarın bunu anlamasına imkân yoktur.

### 11.2 Seviyeler

Yazı dili kendi içinde seviyelerden oluşur. Dilin "çok seviyeli bir sistem" olarak tanımlanmasının sebebi budur:

```text
Ses bilimi (phonology)     : sesler ve onlara atanan semboller (harfler)
Biçim bilim (morphology)   : kelimenin yapısı; kök ve ekler
Söz dizimi (syntax)        : kelimelerin oluşturduğu dizi o dile ait bir cümle mi?
Anlam bilimi (semantics)   : cümlenin anlamı
Söylem (discourse)         : birden fazla cümle ve bağlam
Edim (pragmatics)          : metni anlayıp yorumlama; kullanım
```

**Ses bilimi (phonology).** "A", "e", "ı", "u" gibi sesler vardır. Bu seslere bazı semboller atanır; bu sembollere harf denir. Harflerin okunuşları da değişebilir.

**Biçim bilim (morphology).** Harfler bir araya gelip kelimeleri oluşturur. Kelimenin yapısının incelenmesine **biçimbilimsel analiz** ya da **morfolojik analiz** denir. Bir kelime kökten ve o köke bağlı eklerden oluşur; bunların bulunup ayrılması gerekir.

**Söz dizimi (syntax).** Kelimeler bir araya gelip bir cümle oluşturur. Ama bu dizinin gerçekten o dile ait bir cümle olup olmadığına karar vermek gerekir. Hocanın örneği: Elde "solucan", "deniz", "gökyüzü", "sevmek" kelimeleri olsun ve "Gökyüzü solucan deniz sevmek." yazılsın. Sona nokta konması bunu cümle yapmaz. Bütün kelimeler Türkçedir ve hepsi biçimbilimsel analizden geçer; ama bunlardan bir cümle oluşmaz. **Söz dizimi analizi**, yazılan cümlenin o dile ait bir cümle olup olmadığına karar verir.

**Anlam bilimi (semantics).** Cümlenin Türkçe bir cümle olduğuna karar verildikten sonra anlamsal analize geçilir. Bunun için cümlenin öznesi, yüklemi, nesnesi gibi öğelerinin bulunması gerekir. Hoca gazetecilikteki **5N1K** kuralını hatırlatır: kim, ne, nerede, ne zaman, nasıl, neden (niçin). Bu soruların cevabı çıkarılabiliyorsa cümle anlamsal olarak çözümlenmiş demektir. Ama burada da problemler çıkacaktır.

**Söylem ve edim** Bölüm 18 ve 19'da anlatılmıştır.

### 11.3 Araçlar

- **Zemberek:** Türkçe için biçimbilimsel analiz aracıdır. Çıktısını POS etiketleriyle verir.
- **NLTK (Natural Language Toolkit):** İngilizce çalışanların genelde kullandığı açık araç. Bazı modüllerinde Türkçe desteği vardır, ama genel olarak İngilizce için geliştirilmiştir.

Hoca araçlar ve veri kümeleri konusundaki genel durumu şöyle özetler: Bazı araçlar yalnızca bir dil için çalışır. Bazıları birçok dili destekler ama her dilde aynı başarıyı göstermez. Bazı veri kümeleri yalnızca İngilizce için hazırlanmıştır, bazıları 20-25 dil için. Uygulamaya göre bunlar alınıp biraz değiştirilerek kullanılabilir.

> **Ders sonrası not:** Hoca NLTK'nin Stanford Üniversitesi'nin geliştirdiği bir araç olduğunu söyledi. NLTK, Pennsylvania Üniversitesi'nde (Steven Bird ve Edward Loper) geliştirilmiştir. Stanford'un geliştirdiği araç Stanford CoreNLP'dir.

## 12. Biçimbilimsel Analiz ve Zemberek

### 12.1 Aynı Kelime, Farklı Çözümler

Hoca dört cümle verir; hepsinde "çocukları" kelimesi geçer:

1. "Sevgi'nin çocukları Ayşe ve Mehmet geldiler."
2. "Yeni gelen çocukları gördünüz mü?"
3. "Ayşe ile Mehmet'in çocukları Gökhan ile Sevgi'dir."
4. "Ayşe'nin çocukları Gökhan ile Sevgi'dir."

Kelime aynı olduğu hâlde biçimbilimsel çözümü cümleden cümleye değişir. Hocanın gösterdiği araç çıktısına göre:

- **1. cümle:** kök "çocuk" (isim) + çoğul "-lar" + 3. tekil kişi iyelik "-ı". Sahip Sevgi tek kişi olduğu için 3. tekil iyelik.
- **2. cümle:** kök "çocuk" (isim) + çoğul "-lar" + belirtme hâli (ismin -i hâli) "-ı".
- **3. cümle:** kök "çocuk" (isim) + 3. çoğul kişi iyelik. Ayşe ile Mehmet iki kişi olduğu için sahip çoğuldur.
- **4. cümle:** kök "çocuk" (isim) + çoğul + 3. tekil iyelik. Sahip Ayşe tek kişi, çocuklar çoğul.

<!-- BELİRSİZ: Zemberek ve diğer aracın çıktılarındaki etiket adları ve biçimi slaytta. Altyazıda yalnızca sözlü açıklama var; hoca 4. cümlenin çözümünü "tekil çünkü Ayşe, çoğul çünkü ları, iyelik" diye özetliyor. -->

### 12.2 Zemberek'in Sınırı

Zemberek "çocukları" kelimesi için bu dört çözümün hepsini verir, ama verilen cümle için hangisinin doğru olduğunu söylemez. Türkçede en sık kullanılan çözümü birinci sıraya koyar. Doğru çözümü seçebilmek için **bağlılık analizi (dependency parsing)** gerekir: yüklem kime bağlı, nesne kime bağlı, kim kimden etkilenmiş? Zemberek'in böyle bir özelliği yoktur.

Akademik çalışmalarda elde yalnızca bu açık kaynak araç olduğu için genellikle Zemberek'in verdiği **ilk çözüm** kullanılır. Hoca kendi çalışmalarında da hep ilk çözümü aldığını söyler. Bu, çalışmanın amacına göre yeterli olabilir ya da olmayabilir:

- Amaç yalnızca "çocuk" kelimesinin metinde kaç kez geçtiğini ya da metinde kaç isim olduğunu bulmaksa, kelimenin hangi çözümle açıldığının önemi yoktur. İlk çözüm zaten "çocuk" bilgisini verir.
- 5N1K gibi anlamsal bir analiz yapılacaksa, hangi çözümün doğru olduğuna karar vermek gerekir.

### 12.3 Türkiye'deki Çalışmalar

Türkiye'de bu alandaki ilk çalışmaları Kemal Oflazer yapmıştır. Hocanın aktardığına göre Oflazer Sabancı, Bilkent ve ODTÜ'de bulunmuş, şu an yurt dışındadır. Onun çalışmasında eksikler vardı; bu çalışmayı İstanbul Teknik Üniversitesi'nden Gülşen Hoca devraldı, belirli bir noktaya getirdi ve eksik parçaları doktora öğrencilerine tamamlattı.

İTÜ'nün doğal dil işleme laboratuvarı bir **boru hattı (pipeline)** sunar: metni verirsiniz; araç metni cümlelere ve kelimelere ayırır, biçimbilimsel çözümlemeyi yapar, söz dizimi analizini yapar ve bağlılık ilişkilerini çıkarıp sunar. Ancak bu araç açık kaynak değildir. Şirketlerin bunu alıp ticari ürünlerde kullanması istenmediği için yalnızca izin alınarak, akademik çalışmalarda ve web arayüzü üzerinden kullanılabilir: Cümle web uygulamasına gönderilir, arka planda işlenir, çıktı geri gelir. Binlerce doküman analiz edilecekse bu yöntem çok yavaş ve maliyetlidir. Bu yüzden insanlar bu aracı genellikle küçük örneklerde kullanır.

Hoca bu çalışmanın yavaş ama çok ilerlediğini, Türkçe çalışmalara çok şey kazandırdığını ve takdir ettiğini söyler. Çalışmayı sürdürenlerin doktora öğrencileri olduğunu belirterek sınıftaki doktora öğrencilerine de kendi işleri yanında böyle bir şeye ne kadar eğilebileceklerini düşünmelerini söyler.

## 13. Söz Dizimi Analizi: POS Etiketleri, Eş Dizimlilik ve Ayrıştırma

Biçimbilimsel analizde kelimenin kökü ve ekleri ayrılır. Ardından kelimeler bir araya gelip cümle oluşturur ve cümlenin **söz dizimi analizi (syntactic analysis)** yapılır. Hoca bunların ayrıntısının ayrı bir derste anlatılacağını, burada yalnız ön bilgi verdiğini söyler.

### 13.1 POS Etiketleri

Bir cümlenin o dile ait olup olmadığını anlayabilmek için önce kelimelerine **POS etiketi** verilmesi gerekir. Örnek cümle: "The dog ate my homework."

- "dog" bir isimdir (noun).
- "ate" bir fiildir (verb); geçmiş zaman (simple past) olduğu için ayrı bir etiket alır.
- "homework" bir isimdir. Çoğul isimler ayrı bir etiket alır.

Bu etiketler için bütün dünyada kullanılan bir standart vardır. Önceden herkes farklı etiketler kullanıyordu ve karışıklık çıkıyordu; artık çalışmalarda aynı standart kullanılır. Söz dizimi analizi bu etiketlere ihtiyaç duyar.

> **Ders sonrası not:** Hoca "ate" için etiketin "VD" olduğunu söyledi. Yaygın kullanılan Penn Treebank etiket kümesinde geçmiş zaman fiilin etiketi `VBD`, tekil ismin etiketi `NN`, çoğul ismin etiketi `NNS`'dir. Hoca ayrıca POS'u bir yerde "konuşmanın anlamlı olmayan en küçük birimi" diye tanımladı; POS (part of speech) aslında "sözcük türü" demektir (isim, fiil, sıfat gibi).

### 13.2 Eş Dizimlilik (Collocation)

Cümlede "hot dog" geçsin. Bu "sıcak köpek" midir, yoksa sosis mi? Eğer bu ifade sosis olarak işaretlenirse tek bir isim (noun) olarak alınır. İşaretlenmezse "hot" sıfat (adjective), "dog" isim olarak etiketlenir. Bu durumda söz dizimi ağacına hiçbir zaman doğru oturtulamaz; oturtulsa bile "Sıcak köpek yedin mi?" gibi bambaşka bir anlam çıkar.

Türkçe örnek: "kitap kurdu", çok okuyan kişiye verilen addır. Bu ifade ayrı bir etiket olarak işaretlenmezse "kitap" isim olarak alınır. "Kurdu" ise belirsiz kalır: Hayvan olan "kurt" mu, yoksa "kurmak" fiilinin geçmiş zaman çekimi mi?

Bu yüzden belki de işlemden önce yapılması gereken ilk şey metindeki **eş dizimlileri** çıkarmaktır. Bunun için ayrı bir uygulama yazmak gerekir ve bu da bir maliyettir. Çalışmayı yapan, bunların başarıyı çok az etkileyeceğine karar verip bu adımı atlayabilir de.

Hoca, Türkçede eş dizimlileri bulma çalışmalarının daha çok dil bilimciler tarafından ve teorik olarak yapıldığını söyler: "Şu şartlar olursa bunlar eş dizimlidir" gibi kâğıt üzerindeki tanımlar.

### 13.3 Ayrıştırma (Parsing)

Ayrıştırmada cümle bir ağacın köküdür; cümle parçalana parçalana yapraklara inilir.

**Örnek: "The dog chased the bear." (Köpek ayıyı kovaladı.)** Cümle önce özne kısmı ("the dog") ve yüklem kısmı ("chased the bear") olarak ikiye bölünür. Ardından her kısım bölünebiliyorsa kendi içinde bölünür. Örneğin özne "büyük, şirin köpek" olsaydı sıfat, sıfat, isim olarak ayrılırdı. Yüklem kısmında da yüklem, yüklemin aldığı ekler ve ayının (varsa) özellikleri ayrılır.

Bu ağaçta kullanılan iki öbek etiketi:

- **NP (noun phrase):** isim öbeği.
- **VP (verb phrase):** fiil öbeği.

**Örnek: "John loves Mary." (John Mary'i seviyor.)** Biçimbilimsel analizden "John" ve "Mary" özel isim, "love" fiil ("sevmek") ve "-s" eki olarak geçer. Ayrıştırma:

```text
S
├── NP: John
└── VP
    ├── V: loves
    └── NP: Mary
```

Cümledeki bütün kelimeler yapraklara oturabiliyorsa cümle söz dizimi analizinden geçmiş demektir; yani İngilizceye ait bir cümledir. Ayrıştırma bir yerde tıkanıp kalırsa cümle yanlış yazılmıştır.

Hoca slayttaki ağacın eksik olduğunu da belirtir: Yaprakta "loves" kelimesi "-s" ekiyle birlikte durmaktadır; aslında bunun da kök ve ek olarak ayrılması gerekir.

<!-- BELİRSİZ: Slayttaki "The dog chased the bear" ağacının tam yapısı ekranda; altyazıda yalnızca özne-yüklem bölünmesi sözlü anlatılıyor. -->

### 13.4 Kurallar Nereden Gelir?

Ayrıştırma, dilin gramer kurallarına göre yapılır. Türkçede bir cümle neden oluşur? Özne, nesne, yüklem... Ama bu kadarla kalmaz; dolaylı tümleç, farklı nesne türleri gibi öğelerle cümle giderek büyüyebilir. Bir cümlenin hangi öğelerden oluştuğu, öğelerin hangi ekleri alabileceği, bir isim ya da sıfatın hangi ekleri alacağı, neyin önüne ne gelirse ne olacağı gibi kuralları **dil bilimciler** çıkarır. Hoca, bilgisayar bilimcilerin bunları çıkarmaya kalksa eksik çıkaracağını söyler. Uygulamayı yazanlar, dil bilimcilerin çıkardığı kuralları kodlar; cümle hangi kurala uyuyorsa ağaç üzerinde o kurala göre ayrıştırılır.

### 13.5 Bilgisayar Özel İsmi Nereden Bilir?

**Soru:** "John" ve "Mary" özel isim. Bilgisayar bunların özel isim olduğunu nasıl anlıyor? Bunu ayrıca belirtmek mi gerekiyor?

**Cevap:** Bu ayrı bir problemdir. İki yol vardır: Ya metin üzerinde **varlık ismi tanıma (Named Entity Recognition, NER)** çalışması yapılır, ya da elde bütün isimlerin bulunduğu bir özel isim sözlüğü olur. Bu çalışmalarda **sözlükler çok önemlidir**. Sözlük olmazsa bilgisayar bir kelimenin isim olduğunu anlayamaz. Aynı şekilde "love" kelimesinin fiil olduğunu anlaması için ekleri alınmamış fiillerin bulunduğu bir fiil sözlüğü gerekir. İngilizce üzerinde çalışılıyorsa düzenli (regular) ve düzensiz (irregular) fiiller için ayrı sözlükler olmalıdır ki biçimbilimsel analizde gerekli kontroller yapılabilsin ve sonuç söz dizimi analizine gönderilebilsin.

**Varlık isimleri.** En önemli beş varlık türü şunlardır:

- Kişi (person)
- Yer (location; place ile aynı anlamda)
- Kurum (organization)
- Tarih (date)
- Para birimi (currency)

Bunlar kendi içinde de alt türlere ayrılır. Varlık isimlerinin bulunması başlı başına bir çalışma konusudur.

## 14. Söz Dizimi Analizindeki Diğer Problemler

### 14.1 Zamir Çözümleme (Anaphora Resolution)

Hoca önce zor bir örnekle başlar: "Banu bugün Zoom'da dersine başladı. Bir kere ara verdi. İkinci derste Ali ona soru sordu. O da cevap verdi." Cevap veren "o" kimdir? İlk akla gelen, özel isim olan Banu'dur. Ama arada Ali'den de bahsedilmiştir; belki "o" Ali'dir. Bu belirsizdir.

Zamir çözümleme, metinde kullanılan bir zamirin (İngilizcede "it" gibi) kimi gösterdiğini bulmaktır. Daha basit bir örnek:

- İngilizce: "The dog entered my room and it scared me." Beni korkutan kim? "It". "It" kim? Önceki cümledeki "dog". İngilizcede zamir açıkça yazıldığı için bu daha kolaydır.
- Türkçe: "Köpek odama girdi ve beni korkuttu." Burada zamir yazılmamıştır. Korkutanın 3. tekil şahıs olduğu "korkuttu" fiilindeki "-du" ekinden anlaşılır: ben korkuttum, sen korkuttun, **o korkuttu**. Sistem bu ekten 3. tekil şahsı çıkarıp onu köpeğe bağlamalıdır.

Türkçe için zamir çözümleme çalışmaları azdır ve yetersizdir. Yapılmış akademik çalışmalar (yüksek lisans ya da doktora) vardır, ama zamirlerin hepsini doğru çözümleyemezler.

> **Hocanın vurgusu:** Bunları sözle anlatmak çok kolay, ama çözmek gerçekten zordur.

### 14.2 Edat Bağlama (Prepositional Attachment)

Cümle: "I saw the man in the park with a telescope." Hoca sınıfa bunun ne anlama geldiğini sorar. Bir öğrenci "Parkta teleskobuyla birlikte bir adam gördüm" der. Hoca ikinci bir okuma da verir:

- **Anlam 1:** Parkta teleskobu olan bir adam gördüm.
- **Anlam 2:** Teleskobumla bakarak parkta bir adam gördüm.

Bu cümle iki farklı ayrıştırma ağacıyla da söz dizimi analizinden geçer; ikisi de İngilizcenin kurallarına uyar. Doğrusunu bulmak için **önceki cümlelerle olan ilişkiye** bakmak gerekir. Önceki cümlelerde "Evimde bir teleskop vardı, insanları teleskopla gözlemliyorum" gibi bir şey geçiyorsa teleskop konuşanındır. "Adam teleskobuyla gidiyordu, parka girdi" gibi bir şey geçiyorsa teleskop adamındır. Teleskobun kime ait olduğu buradan çıkarılabilir, ama bu zor bir problemdir.

<!-- BELİRSİZ: Slayttaki iki ayrıştırma ağacının çizimi ekranda; altyazıda yalnızca iki okuma sözlü olarak veriliyor. -->

## 15. Anlamsal Analiz ve Kelime Anlamı Belirginleştirme

Diyelim ki cümle söz dizimi analizinden geçti; yani o dile ait olduğu biliniyor. Şimdi anlamsal olarak çözümlenecek, yani 5N1K sorularına cevap verilecek. Burada da problem vardır: **kelimelerdeki belirsizlik (ambiguity)**. Bu belirsizliği gidermeye **kelime anlamı belirginleştirme (word sense disambiguation)** denir. Türkçede "kelime anlamını berraklaştırma/durulaştırma" olarak da geçer; amaç kelimenin o cümledeki anlamını tam olarak ortaya çıkarmaktır.

### 15.1 "Plant" Örneği

"Plant" kelimesine sözlükte bakıldığında iki anlam vardır: endüstriyel tesis (industrial plant) ve canlı organizma, yani bitki (living organism). Kelimenin hangi anlamda kullanıldığı bilinmezse:

- **Makine çevirisinde** hatalı çeviri yapılır.
- **Bilgiye erişimde** "plant" diye arama yapıldığında, kelimenin hangi anlamı kastedilmiş olursa olsun, farklı anlamlarıyla geçen bütün dokümanlar karşıya gelir.

### 15.2 "Fatih" Örneği

Zamir çözümleme yapılırken bazı kelimeler bazen kişi adı, bazen yer adı olarak kullanılır ve farklı zamirlerle eşleşebilir:

- "Bugün **Fatih** ile görüşeceğim." Burada Fatih bir kişidir (person).
- "Biz **Fatih**'te oturuyoruz." Burada Fatih bir yerdir (location).

İkisi de büyük harfle yazıldığı için özel isim oldukları anlaşılır, ama tamamen farklı şeyleri anlatırlar. Bunu ayırt etmek için varlık ismi tanıma çalışmasıyla kelimeleri "person" ya da "location" olarak etiketlemek gerekir. Böylece sonraki zamir çözümlemesinde hata azalır.

Hoca bu ayrıntılar dikkate alınmadan yapılan bir çalışmanın yaklaşık %70 başarı vereceğini, dikkate alınırsa başarının %70 ile %80 arasında bir değere çıkabileceğini söyler. Bunun kendi denemesi olmadığını, yapılan çalışmaların yaklaşık olarak bunu gösterdiğini belirtir.

### 15.3 "Yüz" Örneği ve Bir Çözüm Fikri

Hocanın çok sevdiği örnek: Türkçe "yüz" kelimesi İngilizceye çevrilecek. "Hundred" mı (sayı), "face" mi (surat), "swim" mi (yüzmek)? Sözlük tabanlı çeviri, sözlükte "yüz" karşısında ilk hangisi yazıyorsa onu alır ve yanlış olabilir.

Bu problem için kelime anlamı belirginleştirme algoritmaları vardır; hoca bunların arka planda aşağıdakine benzer bir şey yaptığını söyler. Derin öğrenmeyle çözmek isteyen biri şöyle ilerleyebilir:

1. "Yüz" kelimesinin "face" anlamında geçtiği bin cümle, "hundred" anlamında geçtiği bin cümle ve "swim" anlamında geçtiği bin cümle toplanır.
2. Sistem bu cümlelerle eğitilir.
3. "Yüzmek" anlamındaki cümlelerde ister istemez spor, deniz, güneş, tatil gibi kelimeler geçer. "Yüz" sayısının geçtiği cümlelerde sayı, para, banka gibi kelimeler geçer. "Surat" anlamındaki cümlelerde ise başka kelimeler kullanılır. Cümle sayısı arttıkça bir anlamın hangi kelimelerle birlikte kullanıldığı daha iyi bulunur.
4. Çevrilecek cümle geldiğinde, oradaki "yüz" kelimesinin hangi kelimelerle birlikte geçtiğine bakılır. Bu kelimeler hangi anlamın kelimeleriyle örtüşüyorsa o anlam seçilir ve İngilizcede "hundred", "swim" ya da "face" yazılır.

Hoca bunun çok güzel bir proje çalışması olabileceğini söyler. Tek sorun, o anlamlara sahip cümleleri bulmak ve birinin bunları **etiketlemesidir**; bu gerçekten çok zordur. Hoca bir fikir de önerir: Wikipedia'da "yüz" aranırsa farklı anlamlar için farklı sayfalar gelir. "Face" anlamındaki sayfadaki kelimeler, oradan verilen bağlantılar ve sayfalardaki cümleler o anlamla ilişkili cümleler olabilir. Bunlardan o anlama yakın kelimeler çıkarılabilir mi diye denenebilir. Hoca bunun uzun sürebilecek bir çalışma olduğunu da ekler.

> **Ek bilgi (derste anlatılmadı):** Bir kelimenin anlamını çevresindeki kelimelerden çıkarma fikri, dil biliminde "dağılımsal hipotez" (distributional hypothesis) olarak bilinir: Benzer bağlamlarda geçen kelimeler benzer anlamlara sahiptir. Derste ilerleyen haftalarda anlatılacak kelime gömmeleri (word embeddings) de bu fikre dayanır.

## 16. Bilgiye Erişim, Bilgi Çıkarımı ve Soru Cevaplama

### 16.1 Bilgiye Erişim (Information Retrieval)

Arama motorları bilgiye erişim sistemleridir; her gün bir arama motoruna girip bir kelime sorgulayan biri bilgiye erişim yapmaktadır. İlerleyen derslerde arama motorlarının arka planında kullanılan modeller anlatılacaktır:

- Vektör modelleri (vector models)
- Boolean modeller
- Anlamsal ilişkilerin çıkarıldığı modeller

Arama motorlarında en önemli şey **indekslemedir (indexing)**. Ne kadar çok sayfa indekslenirse ve yeni bilgiler eklendikçe sayfalar ne kadar sık yeniden indekslenirse sonuçlar o kadar başarılı olur. Bunun için çok güçlü bilgisayarlar ve hızlı algoritmalar gerekir.

### 16.2 Bilgi Çıkarımı (Information Extraction)

Bilgiye erişim sayfaları getirir. Ama aranan şeyi bulmak için sayfayı okumak gerekir. Bilgi çıkarımı, bu bilgiyi insan okumadan yazılan bir uygulamanın çıkarmasıdır. Daha önce sorulan **varlık ismi tanıma** da bilgi çıkarımının içinde bir konudur. Hoca birçok konunun böyle iç içe girdiğini, bilgi çıkarımının bir tür soru cevaplama da sayılabileceğini söyler.

**Örnek.** Slayttaki cümle: "75. karayolunda yaklaşık 8-9 kişilik bir grup var." "75. karayolu" diye bir sorgu gönderilmiş ve böyle bir cümle gelmiş olsun. Bu cümleden bazı bilgiler çıkarılmak istenir: Kaç kişi var? Hangi karayolu? Neresinde? Kim? Cümlede zaman bilgisi olsaydı "ne zaman" sorusu da sorulabilirdi.

Bunun için **kalıplar (patterns)** yazmak ve metinde bu kalıplarla arama yapmak gerekir.

Hoca ABD'de bu alanda çok sayıda yarışma düzenlendiğini anlatır. Bir konu belirlenir ve yıllarca arka arkaya yarışma yapılır. Amaç, internete giren her veriyi anında izleyip kendileriyle ya da takip ettikleri bir konuyla ilgili olanı çok hızlı bulmaktır. Bir sorgunun cevabını en hızlı ve en doğru bulana para ödülü verilir; algoritmalar her yıl biraz daha iyileşir ve olgunlaşan algoritmalar büyük kurumlarca satın alınabilir.

### 16.3 Proje Fikri: Özgeçmişten Bilgi Çıkarma

Hoca verebileceği bir proje örneğini anlatır. Elde düz metin olarak yazılmış bir özgeçmiş (CV) vardır. Bu metinden şu bilgiler çıkarılacaktır:

- Kişinin adı
- Askerlik durumu
- Mezun olduğu üniversite
- Konuştuğu diller
- Bildiği programlama dilleri
- İlgi alanları

Metin yapılandırılmış (structured) değildir; "şu satırda şu bilgi var" gibi bir düzen yoktur. Bilgi **yapılandırılmamış (unstructured)** bir metnin içinden çıkarılacaktır. İki yaklaşım olabilir:

- Bu bilgileri yakalayan bir düzenli ifade (regex) yazmak.
- İnsanların bu bilgiyi nasıl ifade ettiğine bakmak. Örneğin "Şu yılında Yıldız Teknik Üniversitesi'nden mezun oldum" ya da "Mezun olduğum okul Yıldız Teknik Üniversitesi'dir". Bir bilgiyi vermek için genellikle 3-5 farklı kalıp kullanılır. Bu kalıplar çıkarılır ve metinde aranır. Kalıp bulunursa ilgili anahtar kelime çekilir; bulunmazsa o bilgi metinde yoktur.

### 16.4 Soru Cevaplama (Tekrar)

Hoca dersin başında anlattığı noktayı tekrarlar: Soru cevaplamada çalışma alanı daraltılmışsa başarı yüksektir; alan genişse başarı düşer, yani her şey bulunamayabilir.

Çift aşamalı soru örneği: "Dünyanın en yüksek tepesi ne kadar yüksektir?" Önce dünyanın en yüksek tepesinin Everest olduğu bulunur, sonra Everest'in yüksekliği aranır.

### 16.5 Diller Arası Bilgiye Erişim (Cross-Language Information Retrieval)

Aranan bilgi Türkçe sayfalarda olmayabilir. Hocanın örnek sorusu: "İtalya'da araba kiralamak için en az kaç yaşında olmak gerekir?" Bu bilgiye Türkçe rastlanmayabilir; kişinin İtalyancası ve İngilizcesi de olmasın.

1. Soru Türkçe yazılır.
2. Sorudan çıkarılması gereken anahtar kelimeler bulunur: en az yaş, araba kiralama, İtalya.
3. Bu kelimeler İtalyancaya çevrilir ve arama motoruna gönderilir.
4. Gelen sayfada yaş ve araba kiralama kelimeleri geçiyorsa ve yanında 18-20 gibi sayısal bir değer varsa, o cümle hemen kullanıcının karşısına çıkarılır.

<!-- BELİRSİZ: Slayttaki İtalyanca anahtar kelimeler altyazıda anlaşılmıyor ("etta minima per noleggio macchina" benzeri bir ifade). -->

## 17. Makine Çevirisi ve Paralel Derlem

Makine çevirisi metinden metne (text to text) ya da konuşmadan konuşmaya (speech to speech) yapılabilir: ses dinlenip ses olarak, metin alınıp metin olarak çevrilir.

> **Hocanın vurgusu:** Makine çevirisinin başarılı olabilmesi için kesinlikle **paralel derlemlere (parallel corpora)** ihtiyaç vardır.

Paralel derlem, aynı içeriğin iki dildeki karşılıklarından oluşan veri kümesidir. Dersin başında da söylendiği gibi, iyi bir makine çevirisi için çeviri yapılacak iki dilin milyonlarca paralel örneği gerekir. Elde bir Türkçe doküman girdi olarak kullanılıyorsa, bu dokümanın İngilizcesi de bulunmalıdır; aksi hâlde sistem çalıştırılamaz. Çeviri kural tabanlı yöntemlerle de yapılabilir; günümüzde ise derin öğrenmeye geçilmiştir.

- **Kanada Parlamentosu örneği:** Kanada'da İngilizce ve Fransızca olmak üzere iki resmî dil vardır. Parlamentodaki bütün tutanaklar iki dilde tutulur. Bu, İngilizce-Fransızca çeviri için hazır duran önemli bir paralel derlemdir.
- **Wikipedia neden olmaz?** Wikipedia'da bir İngilizce sayfanın Türkçesine girildiğinde içerikler birebir aynı değildir; sayfalar birbirinin çevirisi değildir. Bu yüzden Wikipedia paralel derlem olarak kullanılamaz. Hoca, keşke birebir çeviriler olsaydı, çok güzel bir kaynak olurdu der.

## 18. Söylem (Discourse)

Hoca son iki konuya geçerken dil analizinin sırasını hatırlatır: biçimbilimsel analiz, söz dizimi analizi, anlamsal analiz, ardından söylem ve edim. Bu son ikisinin çok soyut kaldığını, insanların bile bağlamı bilmeden bunları anlamakta zorlandığını söyler; "bridge" örneğinde olduğu gibi. Bu konulardaki çalışmalar yoğunlaşarak, genellikle İngilizce üzerinde devam etmektedir.

### 18.1 Tanım

**Söylem**, kendimizi yazılı, sözlü ya da elektronik ortamda ifade etmemizdir. Bir konudaki düşünce yazıyla yazılabilir, sesle aktarılabilir ya da elektronik ortamda paylaşılabilir. Yazılı ortamın üslubu ile elektronik ortamın üslubu farklı olduğu için kitap bunları ayrı sayar.

Sözcüklerden cümleler, cümlelerden paragraflar, paragraflardan dokümanlar oluşur. Söylem, bu dokümanlar üzerinden **bağlama bakılarak** çıkarılır. Tek bir cümleden söylem çıkarmak mümkün değildir; **tümceler arasındaki ilişkiler** kullanılır. Uzun bir metni anlamlandırmak için onu, kompozisyon yazarken olduğu gibi başlık, giriş, gelişme ve sonuç kısımlarına bölmek gerekir.

### 18.2 Etkili Bir Söylemin Şartları

Hoca kitaptan aldığı şartları sıralar:

- **Dil:** Söylemin yapıldığı dile hakim olmak gerekir. Kişi ana dilinde çok iyi bir söylem verebilir, sonradan öğrendiği bir yabancı dilde genelde o kadar iyi veremez.
- **Söyleyiş biçimi:** Cümleler rahat anlaşılıyor mu? Kelimeler doğru telaffuz ediliyor mu? Şive ya da lehçe farkı var mı? Konuşma bir de vücut diliyle renklendirilirse etkisi değişir.
- **İlişki:** Karşıdaki kişiyle ilişki söylemin niteliğini değiştirir. İnsan öğrencileriyle, çok samimi bir arkadaşıyla ve bir rektör ya da dekanla farklı konuşur.
- **Etkinlik türü:** Ders anlatmak, bir kişiyle tek başına konuşmak, tanıdık bir kalabalığa ve hiç tanımadık bir kalabalığa konuşmak birbirinden farklıdır.
- **Ülkü:** Sonuca ulaşmak; yani karşıdakine vermek istenen anlamın verilebilmesi.

Hoca söyleyiş biçimiyle ilgili sosyal medyadan bir örnek verir: Birinin yazdığı bir cümleye başkası "Aşk olsun, buna çok bozuldum" diye cevap verir; yazan ise "Ben öyle demek istemedim ki" der. Bunun sebebi yazılı anlatımda vücut dilinin kullanılamamasıdır. **Emojiler** bu yüzden geliştirilmiştir: İroni yapıldığını anlatmak için gülücük, kızgınlığı anlatmak için kızgın yüz konur. Vücut dili bu şekilde tamamlanır.

### 18.3 Gerçek Bir Örnek: Garipçe Köyü Tabelası

2019 yılının Mart ayında İstanbul'daki Garipçe Köyü'nde bir ilanın fotoğrafı çekilip paylaşılmıştır. İlanda şöyle yazar: "Mayo ve bikini ile denize girmek yasaktır."

Bu ülkede yaşayan bir Türk ne denmek istendiğini az çok tahmin eder. Ama bunu okuyan bir yabancı ne anlayabilir?

- Bu köyde denize mayo ve bikiniyle girmek yasaktır; o hâlde denize **çıplak** girilir.
- Mayo giyilemiyorsa demek ki denize **elbiseyle** girilir.
- Çıplak girmeyi de, elbiseyle girmeyi de garip bulan biri: Demek ki burası plaj değil, **denize girilmez**.

> **Hocanın vurgusu:** Bilgisayarı da o yabancı gibi düşünmeliyiz. Yaşadığımız ülkeyi, kültürü, hiçbir şeyi bilmez. Böyle bir metni anlamlandırmak için mutlaka bağlamı bilmek gerekir: Bu yazı hangi ülkeden alınmış, o ülkenin kültürü nedir?

Hoca, bilgisayara bazı bilgiler verilerek bunun onun için anlamlı hâle getirilebileceğini, ama bunun gerçekten çok zor olduğunu söyler.

## 19. Edim (Pragmatics)

### 19.1 Tanım

Bir sonraki aşama **edim (pragmatics)** yaklaşımıdır; Türkçede "kullanım" olarak da geçer.

- Söz dizimi ve anlam bilimi **tek bir tümce** üzerinde çalışır.
- Söylem bilgisi **birden fazla tümce** üzerinde çalışır.
- Edim ise tümcelerin tek tek anlamlarıyla ilgilenmez; **metni anlayıp yorumlamaya** çalışır.

Bu bakımdan söyleme benzer, ama burada da bazı ek bilgilere ihtiyaç vardır.

### 19.2 Örnek 1: Metro İstasyonu

Bir yolcu yoldan geçen birine sorar: "Metro istasyonu nerede, biliyor musun?" Karşıdaki "Evet, biliyorum." der ve yoluna devam eder.

Soru sorulan kişi soruya cevap vermiştir ve cevap verdiğini bilir. Ama soranın istediği bu değildir; "Biliyorsan bana yerini de söyle" demek istemiştir. İki tarafın sorunun cevabından beklentisi farklıdır.

Bunu bir soru cevaplama sistemine anlatmak daha da zordur. Sisteme "Maslak'taki metro istasyonu nerede, biliyor musun?" diye sorulsun. Sistem "Evet, biliyorum." diyebilir. Elinde harita olsa, oranın koordinatlarını vererek cevap verebilirdi; ama vermeyebilir de.

### 19.3 Örnek 2: Ev Sahibi ve Kiracı

Ev sahibi ile kiracı adayı arasında geçen bir konuşma:

- Ev sahibi: "Çocuğunuz var mı?"
- Kiracı: "10 yaşında bir oğlum var. Bir de küçük bir köpeğim var."
- Ev sahibi: "Bu kötü."

Bağlam bilinmeden okunursa, köpek sahibi olmanın kötü bir şey olduğu anlaşılır. Ama bu ülkeyi bilen biri, böyle hikâyeleri duymuş ya da yaşamış biri bağlamı bilir: Ev sahibi için evde oturacak kişi sayısının az olması, çocukların az olması ve evcil hayvan beslenmemesi önemli kriterlerdir. "Bu kötü" aslında "Bu haber kötü, evimi sana vermem" demektir.

> **Hocanın vurgusu:** Söylem ve edim yaklaşımlarında cümleler istediğiniz kadar analiz edilsin, öğeleri çıkarılsın, hatta cümlenin anlamı bile bulunsun; yine de yanlış yorumlar ortaya çıkar. Çünkü bağlamdan uzaktayız. Bağlam bilinse bile bazen yetmez: Bir ev sahibi için evde köpek olmasının kötü olduğu bilgisinin de bilgisayara öğretilmesi gerekir. Bu bilgiler "öğret öğret bitmez"; her gün yeni bir olay çıkar. Bu tür çalışmalarda başarıyı düşüren şeyler bunlardır.

## Dersin Toparlaması

Bu derste doğal dil işlemenin genel haritası çizildi. Ders, metin işleme ağırlıklı ve proje odaklı bir yapıdadır. Konuların her biri yurt dışında bir dönemlik ders olabilecek genişliktedir; burada her birine kavramsal olarak bakılacaktır. Dersin birinci parçası dil bilimin klasik çözümleme aşamalarıdır: biçim bilim, söz dizimi ve anlam bilim. İngilizce için bunların çoğu yüksek başarılı araçlara dönüşmüştür; Türkçe için araçlar vardır ama eksiktir. İkinci parça, bu araçları kullanan yapay zeka uygulamalarıdır: bilgiye erişim, bilgi çıkarımı, soru cevaplama, makine çevirisi, duygu analizi ve diğerleri.

Dersin ana fikri, doğal dilin her seviyede belirsizlik içermesidir. Aynı kelimenin birden çok biçimbilimsel çözümü ("çocukları"), aynı cümlenin birden çok ayrıştırma ağacı ("telescope"), aynı kelimenin birden çok anlamı ("plant", "yüz", "bridge"), aynı ismin farklı varlık türleri ("Fatih") ve bağlam olmadan yorumlanamayan metinler (Garipçe tabelası, ev sahibi örneği) bu belirsizliğin örnekleridir. Bilgisayar dile, bizim hiç bilmediğimiz bir dile baktığımız gibi bakar. Bu yüzden dili ona dil modelleri, sözlükler ve kelimeler arası ilişkiler yoluyla adım adım anlatmak gerekir. Problemlerin genel hâli çözülemediği için çalışmalar belirli, dar problemlere indirgenir.

Hoca sonraki haftalarda dilbilimin esasları, gramer ve diller, düzenli ifadeler ve dil modelleriyle devam edileceğini söyler. Bir sonraki haftaki Akıllı Sistemlerde Yenilikler ve Uygulamaları Sempozyumu'ndaki (ASYU) NLP oturumlarını dinlemeyi de proje fikri bulmak için önerir.

## Ders Sonrası Notlar

> **Ders sonrası not:** Hoca "NP problem"i "non-polynomial problem" olarak açıkladı. NP, "nondeterministic polynomial time" sınıfıdır (Bölüm 7.5).

> **Ders sonrası not:** NLTK Stanford'un değil, Pennsylvania Üniversitesi'nin geliştirdiği bir araçtır. Stanford'un aracı Stanford CoreNLP'dir (Bölüm 11.3).

> **Ders sonrası not:** "Ate" için Penn Treebank etiketi `VBD`'dir (hoca "VD" dedi). POS, "sözcük türü" demektir; hocanın bir yerde verdiği "konuşmanın anlamlı olmayan en küçük birimi" ifadesi POS'un tanımı değildir (Bölüm 13.1).

> **Ders sonrası not:** Esperanto (Zamenhof, 1887) en yaygın kullanılan yapay dildir, ama ilk yapay dil değildir. Ondan önce de yapay diller önerilmiştir; örneğin Volapük (1879). Altyazıda ad "Zamenkov" olarak geçiyor; doğrusu Zamenhof.

> **Ders sonrası not:** Hocanın verdiği "3000 ile 4000 arasında dil" sayısı eski bir tahmindir. Güncel kaynaklar (ör. Ethnologue) yaşayan dil sayısını yaklaşık 7000 olarak verir.

> **Ders sonrası not:** Slayttaki altı "büyük dil" (Çince, İngilizce, İspanyolca, Rusça, Fransızca, Arapça), Birleşmiş Milletler'in altı resmî dilidir. Hoca da Türk dilinin 5. sırada olduğu bilgisinin kaynağını ve yılını belirtmediğini söyledi; bu sıralama doğrulanmış bir bilgi olarak alınmamalıdır.

> **Ders sonrası not:** Hoca Jurafsky'nin "galiba elektronik kökenli" olduğunu söyledi. Daniel Jurafsky dil bilimi ve bilgisayar bilimleri kökenlidir. Kitabın konuşma işleme bölümlerinin geniş olması, kitabın konuşma ve dil işlemeyi birlikte ele almasından kaynaklanır.

> **Ders sonrası not:** Altyazıda kitap yazarları "Jorowski" ve "Schultz" olarak geçiyor; doğrusu Jurafsky ve Schütze. Altyazıdaki diğer bozuk terimlerin doğru yazımları: "engram" = n-gram, "post" = POS, "Anafore Resolution" = anaphora resolution, "proposition attachment" = prepositional attachment, "word disembigation" = word sense disambiguation, "non-phrase" = noun phrase, "word phrase" = verb phrase, "Mention Translation" = machine translation, "sintaktik/sentaktik" = syntactic, "diskors" = discourse, "Garipçek köyü" = Garipçe Köyü, "Mastak" = Maslak.

> **Ders sonrası not:** Hoca 5N1K sorularını sayarken bir an takıldı. Altı soru şunlardır: kim, ne, nerede, ne zaman, nasıl, neden (niçin).

> **Ders sonrası not:** Hocanın İTÜ'deki çalışmaları sürdüren hoca için söylediği "Gülşen Hoca", İTÜ Doğal Dil İşleme grubunu yöneten Gülşen Eryiğit'tir. Hocanın tanıttığı boru hattı bu grubun "ITU Turkish NLP Pipeline" aracıdır.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
