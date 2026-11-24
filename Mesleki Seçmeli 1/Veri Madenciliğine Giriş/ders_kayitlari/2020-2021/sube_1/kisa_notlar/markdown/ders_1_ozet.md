# Ders 1 Çalışma Özeti

## Genel Konular

- Veri madenciliğinin amacı ve gerekliliği
  - Veri madenciliği; veriden öğrenen, model kuran ve bu modelle karar verebilen sistemler geliştirmeye yardım eder. Amaç, büyük veri yığınlarındaki veriyi anlamlı bilgiye dönüştürmektir.
  - Veri miktarı terabaytlardan petabaytlara patlarcasına büyümektedir. Otomatik veri toplama araçları, veritabanı sistemleri ve web bu verinin kaynağıdır (ekrandan, 01:05:00).
  - Başlıca veri kaynakları üç alanda toplanır (ekrandan, 01:05:00):
    - İş dünyası: web, e-ticaret, işlemler (transactions), borsa.
    - Bilim: uzaktan algılama, biyoenformatik, bilimsel simülasyon.
    - Toplum ve sosyal medya: haberler, dijital kameralar, bloglar. Sosyal medya verisinden bilgi çıkarmak için doğal dil işleme kullanılır; örneğin e-ticaret yorumlarına duygu analizi (sentiment analysis) uygulanabilir.
  - Slayttaki ana fikir: "Veride boğuluyoruz ama bilgiye açız." Veri madenciliği, büyük veri kümelerinin otomatik analizidir.
- Veritabanı teknolojisi ile ilişki
  - Veri madenciliği yapılandırılmış (structured) veriye ihtiyaç duyar; yapılandırılmış veri de veritabanı yönetim sistemleriyle elde edilir.
  - Veri madenciliği, büyük veriden ilginç örüntü (pattern) ya da bilgi çıkarmaktır. Diğer adları arasında veritabanlarında bilgi keşfi (KDD), bilgi madenciliği, bilgi çıkarımı, veri/örüntü analizi sayılır.
  - İlgili alanlar: metin madenciliği, web madenciliği, akan veri (stream data) madenciliği.
- Uygulama alanları
  - Pazar analizi ve yönetim: hedef pazarlama (target marketing).
  - Risk analizi.
  - Dolandırıcılık tespiti ve olağandışı örüntü madenciliği (ekrandan, 01:10:00):
    - Yaklaşımlar: kümeleme ve dolandırıcılık için model kurma, aykırı değer (outlier) analizi.
    - Örnekler: kredi kartı kötüye kullanımı, kara para aklama (şüpheli parasal işlemler), sağlık sigortası, telekomünikasyonda telefon dolandırıcılığı, perakende, araç sigortası, terörle mücadele.
- Veri madenciliği stratejileri
  - Üç ana strateji vardır: gözetimli öğrenme (supervised learning), gözetimsiz kümeleme (unsupervised clustering) ve pazar sepeti analizi (market basket analysis).
  - Gözetimli öğrenmenin üç türü: sınıflama (classification), kestirim (estimation), öngörü (prediction).
- Gözetimli öğrenme ve karar ağacı örneği
  - İki adım: bilinen kökenli (sınıf etiketi bilinen) örneklerle öğrenen bir model kurulur; sonra bu model kökeni bilinmeyen yeni örneklerin sonucunu belirlemek için kullanılır (ekrandan, 01:15:00).
  - Hastalık teşhisi eğitim veri kümesi: 10 hasta, 5 özellik (Sore Throat, Fever, Swollen Glands, Congestion, Headache), son sütun Diagnosis sınıf etiketidir (ekrandan, 01:20:00).
  - Elde edilen karar ağacı: kök düğüm Swollen Glands; Yes ise Strep throat, No ise Fever sorulur; Fever Yes ise Cold, No ise Allergy.
- Gözetimsiz kümeleme
  - Sınıf etiketi yoktur; örnekler birbirine benzerliklerine göre gruplanır.
  - Acme yatırımcılar veri kümesi üzerinde aynı verinin hem kümeleme hem de (bir sütun çıkış değişkeni seçilerek) gözetimli öğrenme için kullanılabileceği gösterilir (ekrandan, 01:30:00).
- Sınıflama, kestirim ve öngörü farkı
  - Sınıflama: bağımlı değişken kategorik, sınıflar iyi tanımlı, gelecekten çok mevcut durumu tanımlar (ekrandan, 01:40:00).
  - Kestirim: bağımlı değişken sayısaldır, diğer özellikler sınıflamayla aynıdır; mevcut durumu tanımlar (ekrandan, 01:45:00).
  - Öngörü: vurgu mevcut sonuçtan çok geleceği tahmin etmektir; çıkış özniteliği kategorik ya da sayısal olabilir (ekrandan, 01:50:00).
- Üretim kuralları: kural doğruluğu ve kural kapsamı
  - Kredi kartı promosyon veri kümesinde (15 kayıt) Life Insurance Promotion çıkış değişkeni, diğerleri giriş değişkenidir (ekrandan, 02:05:00).
  - Karar ağacından üretim kuralları yazılır; her kural için kural doğruluğu (rule accuracy) ve kural kapsamı (rule coverage) ölçülür.
- Bilgi keşfi (KDD) süreci ve iş zekâsı
  - KDD adımları: veritabanları, veri temizleme ve veri bütünleştirme, veri ambarı, seçim ile göreve uygun veri, veri madenciliği, örüntü değerlendirme ve bilgi (ekrandan, 02:25:00).
  - İş zekâsı piramidi: veri kaynakları, ön işleme/bütünleştirme ve veri ambarları, veri keşfi (istatistiksel özet, sorgulama, raporlama), veri madenciliği, veri sunumu (görselleştirme), karar verme (ekrandan, 02:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Veri madenciliği stratejileri slaydı
  - Hoca bu şemanın not alınmasını istedi; sonraki slaytlarda sürekli bu şemaya dönülecek.
- "Gözetimsiz sınıflama" denmez
  - Gözetimli öğrenmede eğitim veri kümesi ve sınıf etiketi vardır, sınıflama yapılır. Gözetimsiz yöntemlerde sınıf etiketi yoktur, örnekler benzerliklerine göre gruplanır; bu işleme kümeleme (clustering) denir.
  - "Supervised classification" ve "unsupervised clustering" doğru terimlerdir; "unsupervised classification" yanlıştır.
- Son sütunun üç adı
  - Veri kümesindeki son sütun sınıf etiketi (class label), çıkış değişkeni (output variable) ya da bağımlı değişken (dependent variable) diye adlandırılabilir. Sınıf etiketi özellik değildir.
- Kestirim ile öngörü arasındaki ince fark
  - İkisi de tahmin yapar; kestirim mevcut durumu, öngörü geleceği tahmin eder. Hava durumu tahmini geleceğe dönük olduğu için kestirim değil öngörü örneğidir.
- Kural doğruluğu sınıflar arası, kural kapsamı sınıf içi bir ölçüdür
  - Kapsam hesaplanırken yalnız ilgili sınıfa (ör. "Yes" diyenler) ait bütün kayıtlar sayılır.
- Ön işlemenin payı
  - Özellik çıkarma, veri temizleme ve ön işleme, veri madenciliği çalışmasındaki emeğin yaklaşık %60'ını alır.

## Kısa Tekrar Notları

- Veri madenciliği = büyük veriden ilginç örüntü/bilgi çıkarma; KDD sürecinin çekirdeği.
- Üç strateji: gözetimli öğrenme (sınıflama, kestirim, öngörü), gözetimsiz kümeleme, pazar sepeti analizi.
- Gözetimli öğrenme: önce etiketli eğitim verisiyle model, sonra etiketsiz test örneğine karar.
- Sınıflama: kategorik çıkış, mevcut durum. Kestirim: sayısal çıkış, mevcut durum. Öngörü: gelecek, çıkış kategorik ya da sayısal.
- Hastalık ağacı: Swollen Glands = Yes → Strep throat; değilse Fever = Yes → Cold, Fever = No → Allergy.
- Kural doğruluğu = kuralın koşulunu sağlayan kayıtlardan sonucu doğru olanların oranı.
- Kural kapsamı = sonuç sınıfındaki bütün kayıtlardan kuralın doğru yakaladıklarının oranı.
- Gelir aralığı (ör. 40-50K) sıralanabilir ama aralıklar arası uzaklık ölçülemez; kategoriktir.
- Kategorik çıkış → sınıflama; sayısal çıkış → regresyon; etiket yok → kümeleme.
- Analize başlamadan veri keşfi: ortalama, standart sapma, korelasyon, kovaryans.

## Detaylı Açıklamalar

- **Gözetimli öğrenme örneği.** Hastalık teşhisi tablosunda 10 hastaya beş soru sorulmuştur: boğaz ağrısı (Sore Throat), ateş (Fever), şişmiş bezeler (Swollen Glands), burun tıkanıklığı (Congestion) ve baş ağrısı (Headache). Her sütun bir özelliktir; son sütun Diagnosis (Strep throat, Allergy, Cold) sınıf etiketidir. Sınıf etiketi bulunduğu için bu bir eğitim veri kümesidir (ekrandan, 01:20:00). Karar ağacı algoritması bu veriden yalnız iki test düğümü olan bir model üretir: kökte Swollen Glands, sonra Fever. Beş özellikten yalnız ikisinin kullanılması, algoritmanın ayırt edici özellikleri seçtiğini gösterir. Model eğitim verisindeki 10 hastanın hepsini doğru sınıflar (ajan tarafından python ile kontrol edildi). İkinci adımda teşhisi bilinmeyen test hastaları (ID 11 ve sonrası) modele sorulur; derste ID 11 için Swollen Glands = No ve Fever = No olduğundan sonuç Allergy bulundu. <!-- BELİRSİZ: test hastaları tablosunun karesi yok; diğer test hastalarının değerleri ve sonuçları altyazıdan okunamadı. -->

- **Gözetimsiz kümeleme ve Acme yatırımcılar veri kümesi.** Tabloda beş müşteri vardır; öznitelikler Account Type (Joint, Custodial, Individual), Margin Account (Yes/No), Transaction Method (Online/Broker), Trades/Month, Sex, Age, Favorite Recreation ve Annual Income'dır (ekrandan, 01:30:00). Etiket olmadan bu müşteriler benzerliklerine göre gruplanabilir. Öte yandan Transaction Method çıkış değişkeni seçilirse veri etiketli hale gelir ve gözetimli yöntemle "çevrim içi yatırımcının genel profili nedir?" sorusu yanıtlanabilir; örneğin yaşlı müşterilerin aracı kurumu (broker), gençlerin çevrim içi işlemi tercih ettiği gibi bir profil çıkabilir. Hangi sütunun çıkış değişkeni olacağı, cevaplanmak istenen soruya göre belirlenir. Kümeleme yöntemleri (k-means, hiyerarşik kümeleme) ara sınavdan sonra işlenecektir. <!-- BELİRSİZ: yatırımcı veri kümesiyle ilgili ikinci slayttaki diğer sorular (yeni müşteriye margin hesabı önerme vb.) altyazıda bozuk. -->

- **Sınıflama, kestirim, öngörü örnekleri.** Sınıflama için hastalık teşhisi örneği verilir: hastanın şu anki durumunu belirler. Kestirim için bir öğrencinin önerisi ev fiyatı tahminidir: evin konumu, katı, oda sayısı ve bölgedeki diğer ev fiyatları (eğitim verisi) kullanılarak evin bugünkü fiyatı tahmin edilir. Makinenin kalan ömrü de çıkışı sayısal bir örnek olarak geçti. Hava durumu tahmini geleceğe dönük olduğu için öngörüdür: "yarın 25 derece" sayısal, "yarın güneşli/yağmurlu" kategorik çıkışlı öngörüdür. Ev fiyatının üç yıl sonraki değeri sorulsaydı bu öngörü olurdu ve bunun için geleceğe ait fiyatları içeren uygun bir veri kümesi gerekirdi.

- **Kural doğruluğu ve kural kapsamı.** Kredi kartı promosyon veri kümesinde 15 kart sahibi vardır (7 kadın, 8 erkek); sayısal olan tek öznitelik Age'dir, Income Range aralık verdiği için kategoriktir (ekrandan, 02:05:00).
  - Kural 1: `IF Sex = Female & 19 <= Age <= 43 THEN Life Insurance Promotion = Yes` (ekrandan, 02:10:00). Koşulu sağlayan 6 kadın kart sahibinin 6'sı da "Yes" der, doğruluk $6/6 = \%100$. Veri kümesinde "Yes" diyen toplam 9 kişi vardır; kural bunların 6'sını yakalar, kapsam $6/9 \approx \%66{,}67$.
  - Kural 2: `IF Sex = Male & Income Range = 40-50K THEN Life Insurance Promotion = No`. Koşulu sağlayan 3 erkeğin 3'ü de "No" der, doğruluk $\%100$. "No" diyen toplam 6 kişi vardır; kapsam $3/6 = \%50$.
  - Sonuçlar ajan tarafından python ile doğrulandı.
  - Kural doğruluğu sınıflar arası (between-class), kural kapsamı sınıf içi (within-class) bir ölçüdür (ekrandan, 02:10:00); çünkü kapsam yalnız sonuç sınıfına ait kayıtlar üzerinden hesaplanır.

- **KDD süreci ve iş zekâsı.** Süreç veritabanlarıyla başlar; veri temizleme ve bütünleştirmeyle veri ambarı oluşur, seçimle göreve uygun veri (task-relevant data) elde edilir, veri madenciliği uygulanır ve sonuçlar örüntü değerlendirmeyle bilgiye dönüşür (ekrandan, 02:25:00). Alan bilgisi göreve gerekli özellikleri seçmeyi sağlar. Görev bilinirse teknik seçilir: etiketli ve kategorik çıkış → sınıflama, sayısal çıkış → regresyon, etiket yok → kümeleme. İş zekâsı piramidinde aşağıdan yukarı: veri kaynakları (kâğıt, dosyalar, web belgeleri, bilimsel deneyler, veritabanı sistemleri; DBA), veri ön işleme/bütünleştirme ve veri ambarları, veri keşfi (istatistiksel özet, sorgulama, raporlama), veri madenciliği (bilgi keşfi; veri analisti), veri sunumu (görselleştirme; iş analisti) ve karar verme (son kullanıcı); yukarı çıktıkça iş kararlarını destekleme potansiyeli artar (ekrandan, 02:30:00). Ön işleme aşaması emeğin yaklaşık %60'ını alır, çünkü özelliklerin çıkarılması için veritabanı yöneticileriyle birlikte çalışmak gerekir.

- **Pazar sepeti analizi.** Üçüncü strateji olarak tanıtıldı; FP-Growth algoritmasının adı geçti. <!-- BELİRSİZ: pazar sepeti analizi anlatımı altyazıda büyük ölçüde bozuk ve bu anın karesi yok. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
