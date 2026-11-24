# Ders 1 Çalışma Özeti

## Genel Konular

- Veri madenciliğinin tanımı ve amacı
  - Veri madenciliği, büyük miktardaki veriden anlamlı ve hedefe yönelik bilgi çıkarma (keşfetme) işidir.
  - Önce veri iyi analiz edilir, sonra amaca uygun bilgi çıkarma yöntemleri ve algoritmaları uygulanır.
  - Literatürde eş anlamlı kullanılan adlar: knowledge mining from databases, knowledge extraction, data/pattern analysis, data archeology; en bilinen adı "Knowledge Discovery from Databases (KDD)" (ekrandan, 00:10:00).
  - İşletme ve endüstri mühendisliği gibi bölümlerde aynı yöntemler "business intelligence" ya da "karar destek sistemleri" gibi ders adlarıyla okutulur; algoritmalar aynıdır, uygulama alanı değişir.
- Dersin kapsadığı konular (akademik çerçeve)
  - Veri ön işleme: veri azaltma (data reduction), ayrıklaştırma (discretization), normalizasyon.
  - Eğiticili yöntemler: karar ağaçları ve karar kuralları, istatistiksel sınıflandırma (Naive Bayes).
  - Eğiticisiz yöntemler: K-means, hiyerarşik kümeleme, öz düzenleyici haritalar (SOM).
  - Birliktelik kuralları, market sepeti analizi (Apriori), öneri sistemleri ve işbirlikçi filtreleme (ekrandan, 00:15:00).
  - Yöntemlerin matematiği öğrenilir: örneğin küçük bir veriyle karar ağacı kurarken neyin, nasıl hesaplandığı.
- Kullanılan araçlar
  - Kodlama ağırlıklı olarak Python ile yapılır.
  - WEKA: Yeni Zelanda'da Waikato Üniversitesi'nde geliştirilmiş, Java ile yazılmış açık kaynaklı bir veri madenciliği araç kutusu; kodlama bilmeyenler için hızlı sonuç almada yararlı.
- Neden veri madenciliği?
  - Veri patlaması: veri terabaytlardan petabaytlara çıkmıştır (ekrandan, 00:30:00).
  - Veri kaynakları: iş dünyası (web, e-ticaret, işlemler, borsa), bilim (uzaktan algılama, biyoinformatik, bilimsel simülasyon, hava tahmini), toplum (haberler, sosyal medya, dijital kameralar).
  - Sağlıktan örnekler: ulusal sağlık kayıt sistemindeki klinik verinin yaklaşık 5 petabayt olduğu (radyolojik görüntüler hariç); dijital patolojide 20 kat büyütülerek taranmış sıkıştırılmamış tek bir cam görüntüsünün yaklaşık 40 GB tuttuğu.
  - "We are drowning in data, but starving for knowledge": veride boğuluyoruz ama bilgiye açız (ekrandan, 00:30:00).
  - Veri tabanı teknolojilerinin (ilişkisel veri tabanları) gelişmesi veri madenciliğinin temelini oluşturur.
- Potansiyel uygulama alanları (ekrandan, 00:35:00)
  - Veri analizi ve karar destek: pazar analizi ve yönetimi (hedef pazarlama, CRM, market sepeti analizi, çapraz satış, pazar segmentasyonu), risk analizi ve yönetimi (tahmin, müşteriyi elde tutma, kalite kontrol, rekabet analizi), dolandırıcılık tespiti ve olağandışı örüntülerin (aykırı değerlerin) bulunması.
  - Diğer: metin ve web madenciliği, akış verisi madenciliği, biyoinformatik.
- Dolandırıcılık tespiti (fraud detection) (ekrandan, 00:40:00)
  - Yaklaşımlar: kümeleme, dolandırıcılık için model kurma, aykırı değer analizi.
  - Alanlar: oto sigortası, kara para aklama, sağlık sigortası (başkasının yerine ilaç yazdırma gibi), telekomünikasyon, perakende.
  - Kredi kartı: her kullanıcının bir harcama düzeni vardır; bir aylık harcamanın bir günde tek mağazada yapılması gibi düzen dışı durumlar alarm üretir, ancak bu gerçek bir müşteri davranışı da olabilir.
  - Çalıntı kartlarla ilgili yakalanmış bir örüntü: önce akaryakıt istasyonunda küçük bir alım, hemen ardından limit kadar elektronik ya da pahalı ürün alımı.
- Veri madenciliği stratejileri
  - Eğiticisiz kümeleme (unsupervised clustering).
  - Eğiticili öğrenme (supervised learning): sınıflandırma (classification), kestirim (estimation), öngörü (prediction).
  - Market sepeti analizi / birliktelik kuralları ve öneri sistemleri.
- Eğiticili öğrenme (ekrandan, 00:50:00)
  - Sınıfı bilinen örneklerle öğrenen bir model kurulur; model, sınıfı bilinmeyen yeni örneklerin sonucunu belirlemek için kullanılır.
  - Örnek: 10 hastalık varsayımsal teşhis verisi ve ondan kurulan karar ağacı (ekrandan, 00:45:00).
- Eğiticisiz kümeleme
  - Sınıf etiketi yoktur; örnekler birbirine benzerliklerine göre gruplanır.
  - Etiketleme uzman zamanı gerektirdiği için pahalıdır; bu yüzden çoğunlukla etiketsiz veriyle çalışılır.
  - Örnek: Acme yatırımcı veri seti üzerinde müşteri segmentasyonu (ekrandan, 00:55:00); kümeleme aykırı değer tespitinde de kullanılır.
- Sınıflandırma, kestirim ve öngörü farkı
  - Sınıflandırma: eğiticili, bağımlı değişken kategorik, sınıflar iyi tanımlı, gelecek değil mevcut durum (ekrandan, 01:00:00).
  - Kestirim: bağımlı değişken sayısal, yine mevcut durum (örnek: aracın o anki hızına ve teknik özelliklerine göre anlık yakıt tüketimi).
  - Öngörü: geleceğe dönük tahmin; çıktı kategorik ya da sayısal olabilir (ekrandan, 01:05:00). Örnek: yarının en düşük/en yüksek sıcaklığı (sayısal) ya da yağmurlu/güneşli (kategorik).
- Market sepeti analizi
  - Birlikte satılan ürünlerin tespiti; bira ve bebek bezi örneği.
  - Algoritmalar: Apriori ve FP-Growth.
- Üretim kuralları (production rules), kural doğruluğu ve kapsayıcılığı
  - Kredi kartı promosyonu veri seti (15 örnek) üzerinde iki kural incelendi (ekrandan, 01:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Veri madenciliği stratejileri ağacı
  - Hoca bu şemayı en sevdiği slayt olarak tanıttı ve dönem boyunca her konunun bu ağaçta nereye oturduğunu hatırlatacağını söyledi.
- Yöntemlerin matematiğini bilmek
  - Bir yöntemin altındaki hesabı bilen kişi, hangi veride hangi yöntemin kullanılabileceğine önceden karar verebilir ve yeni yöntemleri temel algoritmaların üzerine kolayca ekleyebilir.
- Eğitim verisinde etiket şarttır
  - Eğitim veri setinde mutlaka bir çıktı değişkeni (sınıf etiketi) bulunmalıdır; etiket alan uzmanı tarafından konur.
- Estimation ile prediction ayrımı
  - Türkçede ikisi de "tahmin" diye çevrildiği için fark kaybolur; ayırt edici nokta geleceğe dönük olup olmamasıdır.
- Etiketsiz veriyle eğiticili yöntem
  - Etiketsiz bir veri setinde sütunlardan biri çıktı değişkeni seçilip diğerleri girdi kabul edilerek sınıflandırma da yapılabilir (örnek: "online yatırımcının genel profili nedir?").
- Kural kapsayıcılığı düşükse
  - Tek kural sınıfın tamamını kapsamıyorsa, kalan örnekleri kapsayacak başka kurallar yazılır; grup bir kural kümesiyle tahmin edilir.

## Kısa Tekrar Notları

- Veri madenciliği = büyük veriden anlamlı bilgi keşfi; diğer adı KDD.
- Üç strateji: eğiticisiz kümeleme, eğiticili öğrenme (sınıflandırma, kestirim, öngörü), market sepeti analizi.
- Eğiticili: bilinen örnekle model kur, bilinmeyen örneğe uygula.
- Eğiticisiz: etiket yok, benzerliğe göre grupla.
- Sınıflandırma: kategorik çıktı, mevcut durum.
- Kestirim: sayısal çıktı, mevcut durum.
- Öngörü: gelecek, çıktı kategorik ya da sayısal.
- Öz nitelik (feature) = istatistikte değişken (variable); çıktı değişkeni = bağımlı değişken = sınıf etiketi.
- Kural doğruluğu = IF kısmına uyanlardan THEN kısmı da doğru olanların oranı.
- Kural kapsayıcılığı = THEN sınıfındaki tüm örneklerden kuralın doğru yakaladıklarının oranı.
- Market sepeti: Apriori, FP-Growth.

## Detaylı Açıklamalar

### Karar ağacı örneği

Varsayımsal teşhis verisinde 10 hasta ve beş evet/hayır öz niteliği vardır: Sore Throat (boğaz ağrısı), Fever (ateş), Swollen Glands (şiş bezeler), Congestion (tıkanıklık), Headache (baş ağrısı). Diagnosis (teşhis) sütunu bir kulak burun boğaz uzmanınca doldurulmuştur ve üç sınıf içerir: Strep throat (boğaz enfeksiyonu), Allergy (alerji), Cold (soğuk algınlığı) (ekrandan, 00:45:00).

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

Bu veriden kurulan ağaç:

```text
Swollen Glands?
├── Yes -> Strep throat
└── No  -> Fever?
           ├── Yes -> Cold
           └── No  -> Allergy
```

Ağaç eğitim verisindeki 10 hastanın hepsini doğru sınıflar (python ile kontrol edildi). Yeni gelen 11, 12 ve 13 numaralı hastalar artık uzmana değil modele sorulur: şiş bezeleri olan hasta Strep throat, bezeleri şiş olmayıp ateşi olan hasta Cold, ikisi de olmayan hasta Allergy olarak sınıflanır.
<!-- BELİRSİZ: 11-13 numaralı hastaların öz nitelik tablosu karelerde görünmüyor; sonuçlar altyazıdan alındı. -->

### Üretim kuralları: doğruluk ve kapsayıcılık

Kredi kartı promosyonu veri setinde 15 kart sahibi vardır; sütunlar: gelir aralığı, dergi promosyonu, saat promosyonu, hayat sigortası promosyonu, kredi kartı sigortası, cinsiyet ve yaş (ekrandan, 01:10:00). Deneyimli bir bankacı ya da mağaza müdürünün kafadan söyleyebileceği türden kurallar "IF ... THEN ..." biçiminde yazılır ve iki ölçütle değerlendirilir.

- Kural 1: IF cinsiyet = kadın ve yaş 19-43 THEN hayat sigortası promosyonu = evet.
  - 7 kadından 6'sı yaş koşulunu sağlar (55 yaşındaki kapsam dışı). Bu 6 kişinin 6'sı da evet demiştir: doğruluk $6/6 = \%100$.
  - Veri setinde hayat sigortası promosyonuna evet diyen 9 kişi vardır; kural bunların 6'sını yakalar: kapsayıcılık $6/9 \approx \%66{,}7$.
- Kural 2: IF cinsiyet = erkek ve gelir aralığı = 40-50K THEN hayat sigortası promosyonu = hayır (ekrandan, 01:20:00).
  - 8 erkekten gelir aralığı 40-50K olan 3 kişi vardır (45, 42 ve 55 yaş); üçü de hayır demiştir: doğruluk $3/3 = \%100$.
  - Hayır diyen toplam 6 kişi vardır; kural 3'ünü kapsar: kapsayıcılık $3/6 = \%50$.

Hesaplar python ile tablo üzerinden doğrulandı.

> **Ders sonrası not:** Altyazıda ikinci kural çözülürken bazı satırlar için "30-40 bin" geçiyor ve doğruluk için "3 bölü 8" deniyor. Tabloya göre kuralın IF kısmına uyan satırlar 40-50K gelirli üç erkektir; doğruluğun paydası tüm erkekler (8) değil, IF kısmına uyan bu 3 kişidir. Sonuç (%100 doğruluk, %50 kapsayıcılık) slaytla aynıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
