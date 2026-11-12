# Ders 5 Çalışma Özeti

## Genel Konular

- Kelime koordinatlarından metin koordinatına: ortalama alma
  - Birlikte geçme matrisi ve Multidimensional Scaling (MDS) ile her kelimeye bir koordinat atandıktan sonra, bir cümlenin ya da dokümanın koordinatı en basit yolla içindeki kelimelerin koordinatlarının boyut boyut ortalaması alınarak bulunur.
  - Örnek (ekrandan, 00:10:00): Ali $=[0.7,\ -0.2,\ \dots,\ 0.8]$, Yemek $=[0.5,\ 0.9,\ \dots,\ 0.7]$ (ikisi de 300 boyutlu) ise "Ali yemek" $=[0.6,\ 0.35,\ \dots,\ 0.75]$ olur.
  - Ortalama sıralamaya bakmaz: "yemek Ali" de aynı vektörü verir. Karışık sıradaki kelimeler bile metnin neden bahsettiğine dair kaba bir bilgi taşır.
  - Avantajı: farklı sayıda kelime içeren metinler de kelimelerle aynı boyutlu (örneğin 300 boyutlu) aynı uzaya düşer.
- Anlamsal uzayların metin sınıflandırmada kullanımı (ekrandan, 00:12:45)
  - Beş haber sınıfında, 4500 kelimelik sözlükle bulunan koordinatlar ortalanarak haberler 100 ve 10 boyutta temsil edilmiş. 100 boyutta lineer regresyonla sınıflandırma %93.25, rastgele orman (100 ağaç) %90.75, destek vektör makineleri %90 başarı vermiş; 10 boyutta bile %89 civarında sonuç alınmış.
  - Karşılaştırma: 4500 boyutlu seyrek terim-doküman temsilinde (tf) Naive Bayes %87.25, destek vektör makineleri %87 civarındadır. 10 boyutlu temsil çok daha yoğundur ve fazla bilgi kaybetmez.
  - Dezavantajlar: sözlük boyutu × sözlük boyutu (4500×4500) bir birlikte geçme matrisi gerekir; bu matrisi oluşturmak da üzerinde MDS gibi çarpanlara ayırma işlemleri yapmak da ölçeklenebilir değildir. Yöntem dilden bağımsızdır.
- Çok anlamlı (eş sesli) kelime sorunu
  - "Jaguar" hem araba markaları (Ferrari, Lamborghini) hem hayvanlar (çita, kaplan) ile birlikte geçer. Tek vektörle temsil edilince ikisine birden benzemeye çalışır ve hiç birlikte geçmeyen bu iki grubu da birbirine yaklaştırır (ikinci dereceden birlikte geçme).
  - Kelimeye birden fazla vektör vermek bir çözümdür, ama hangi vektörün hangi anlamda kullanıldığını bulmak ek iş gerektirir ve kolay ölçeklenmez.
- Kelime yörüngeleri (hocanın grubunun eski bir çalışması)
  - Fikir: metin, kelime koordinatlarının sırayla ziyaret edildiği yönlü bir yol (yörünge) olarak düşünülür. Örnek cümleler (ekrandan, 00:26:55): "Bugün yolda kedi gördüm. Arkasından gittim. Hızlı koşuyordu. Yakalayamadım." ve "Hızlı araba kullanmak tehlikelidir. Kediler arabaların altında kalabilirler. Bugün neredeyse eziliyordu bir kedi."
  - Varsayım: kelimelerin koordinatlarından bağımsız yörünge özellikleri (ardışık kavramlar arası mesafe, kavramlar arası açı) yazan kişiye dair ipucu verir. Aynı kişinin farklı konulardaki yazılarının yörüngeleri benzer olmalıdır. Ardışık kavramlar arası mesafenin büyük olması bağlamdan bağlama "zıplama"yı gösterebilir.
  - Farklı uzunluktaki metinleri aynı boyuta getirmek için histogram kullanılır (ekrandan, 00:30:00): $d$ uzunluğundaki yörüngede $d-1$ adet $(n,n+1)$ mesafesi ölçülür, bunların 10 parçalık histogramının 10 değeri ve frekansları 20 özellik verir. Aynı işlem $(n,n+2)$, $(n,n+3)$ mesafelerine ve $(n,n+1,n+2)$, $(n,n+2,n+3)$ açılarına uygulanınca $5\times 20=100$ özellik elde edilir.
  - Yazar tanıma sonuçları (ekrandan, 00:32:40): 2 yazar, 35'er yazı, 10'lu çapraz geçerleme: C4.5 %97.15, Naive Bayes %97.15, en yakın komşu %95.71, destek vektör makineleri %98.57. 3, 4 ve 8 yazarda en iyi sonuçlar sırasıyla %95.24 (Naive Bayes), %92.14 (Naive Bayes) ve %68.57'dir (destek vektör makineleri); Zero Rule 33.33, 25 ve 12.5'tir.
  - Olası kullanım alanları: psikolojik hastalıkların tespiti, cinsiyet, yaş ve eğitim farklılıklarının düşünce süreçlerine etkisi. Çalışmada kadın ve erkek yazarların yörüngeleri birbirinden ayrılamamıştır; kişiye özel farklar bulunabilmiş, cinsiyete dayalı fark bulunamamıştır.
- Sinirsel dil modelleri: word2vec (ekrandan, 00:53:10)
  - Mikolov ve ark. (2013). Tek gizli katmanlı bir yapay sinir ağıdır: giriş $1\times|V|$ one-hot vektör, gizli (projection) katman $1\times d$, çıkış $1\times|V|$. Ağırlıklar $W_{|V|\times d}$ ve $C_{d\times|V|}$'dir. $|V|$ sözlük boyutu, $d$ kelimelerin temsil edileceği boyuttur (örneğin 100, 300).
  - $C=2$ için bağlam $(w_{t-2},w_{t-1},w_t,w_{t+1},w_{t+2})$'dir. Skip-gram: giriş $w_t$, çıkış bağlam kelimelerinin her biri. C-bow (CBOW): giriş bağlam kelimelerinin her biri, çıkış $w_t$.
  - Eğitim kümesi (ekrandan, 01:10:00): "w1 w2 w3 w4 w5 w6 w7 …" metninde, $C=2$ ile skip-gram için benzer olması istenen ikililer $(w_3,w_1),(w_3,w_2),(w_3,w_4),(w_3,w_5)$; farklı olması istenen ikililer $(w_3,t_1),\dots,(w_3,t_K)$'dır ($t_1\dots t_K$ $p(w_i)$'ye göre rastgele seçilir). Sonra $w_4$ ile devam edilir. C-bow için ikililer ters çevrilir.
  - Eğitim, aynı kelimenin çevresindeki kelimeleri ve kelimenin kendisini birbirine yaklaştırır. Eğitim bitince $W$ matrisinin her satırı bir kelimenin $d$ boyutlu koordinatıdır; başka işlem gerekmez.
  - En büyük avantajı: hiçbir yerde $V\times V$ boyutlu bir yapı yoktur, yalnız $V\times d$ ve $d\times V$ matrisler vardır. Sözlükler 32 bin ve üstüne çıkabildiği için bu, birlikte geçme matrisi yöntemlerine göre büyük bir kazançtır.
- Hata fonksiyonu ve negatif örnekleme
  - İki vektör benzerse iç çarpımları yüksektir. Hata fonksiyonunun ilk terimi kelime $w$ ile bağlam kelimesi $c$'nin iç çarpımının sigmoidden geçmiş halinin logudur; bunların yakın olması istenir.
  - Yalnız pozitif ("şunlar benzesin") geri bildirim verilirse temsil uzayı bir noktaya çöker; herkes herkese benzer. Bu yüzden negatif örnekler gerekir: her kelime için $P(w)$ dağılımına göre $k$ kelime seçilir ve bunlarla uzak olması istenir. $P(w)$ kelimenin derlemdeki sıklığına bağlıdır; sık kelimeler daha çok seçilir. Mikolov $k=5$ ile iyi sonuç almıştır ($C=2$ iken 4 pozitif, 5 negatif örnek).
  <!-- BELİRSİZ: Hata fonksiyonu slaytı (slayt 62) karede yakalanamadı; formül altyazıdan ve yöntemin bilinen tanımından yazıldı. -->
- FastText (ekrandan, 01:10:40)
  - Bojanowski ve ark. (2017, yazarlar arasında Mikolov da var). Birlikte bulunmaya ek olarak kelime içi n-gram benzerliklerini (sub-word similarity) de dikkate alır; kelimeleri n-gramlara parçalar ve her n-gram için vektör bulur.
  - Sözlükte olmayan kelimelerin vektörünü de bulabilir. Türkçe gibi eklemeli dillerde aynı kelimenin farklı ekler almış halleri ("geliyorum", "geliyorsun") ve yanlış yazılmış halleri yakın koordinatlara düşer. Dezavantajı: daha yavaştır.
  - Hazır vektörler yayımlanabilir ve kolayca paylaşılır: FastText yüz küsur dil için vektör yayımlamıştır, Türkçe vektörler 416 bin kelime içerir (ekrandan, 01:20:00).
- Hazır FastText vektörleri ile kendi eğitilen vektörlerin karşılaştırması
  - Hazır FastText (n-gram benzerliği var, ekrandan, 01:20:00): "terlik"e en yakınlar arasında "terliksi", "terlikler" gibi faydalı sonuçların yanında "noterlik", "kasiyerlik", "yeterlik" gibi anlamca ilgisiz ama karakterce benzeyen kelimeler çıkar. "virüs" için "virüsün", "virüslü", "virüsle" gibi ekli halleri yakın çıkar; bu istenen bir durumdur. "cimbom" için "cimbombom", "galatasaray", "#beşiktaş" gibi spor kelimeleri gelir.
  - 42 bin haber metniyle eğitilen vektörler (n-gram benzerliği yok, sözlük 19 bin kelime, ekrandan, 01:21:10): "virüs"e en yakınlar "virüsü", "virüsün", "bulaşan", "hiv", "hastalık", "grip", "aşı" ile "zararlı", "yazılımı", "bilgisayar" gibi bilgisayar virüsü kelimeleridir; bu da eş sesli kelime sorununu gösterir. "ölmek"e en yakın kelimelerden biri zıt anlamlısı "yaşamak"tır.
- Kelime vektörlerinin başarısını ölçmek
  - Dahili yöntemler: insanların verdiği benzerlik ve analoji cevaplarıyla korelasyon. Harici yöntemler: vektörleri duygu analizi, metin sınıflandırma gibi başka uygulamalarda kullanıp performansa bakmak.
- Cümle ve metin vektörleri (ekrandan, 01:25:20)
  - En basit yol içindeki kelimelerin ortalamasıdır. Universal Sentence Encoder örneğinde "How old are you?" ile "What is your age?" ve "My phone is good." ile "Your cellphone looks great." çiftleri birbirine benzer, çiftler arası benzerlik düşüktür.
- Kelime öbekleri
  - İyi bir kelime öbeği, parçaları birleşince parçalarından farklı bir anlam taşır ("Fatih Sultan Mehmet"). Öbek olarak alınmazsa "Fatih Sultan Mehmet" ile "Fatih Terim" "Fatih" üzerinden ortak görünür.
  - Yöntem: kelime n-gramları (karakter n-gramından farklı olarak art arda gelen kelimeler) çıkarılır, frekansı yüksek olanlar tek kelimeye çevrilip sözlüğe katılır. 41.992 haberlik derlemde (ekrandan, 01:40:00) en sık tekliler "ve", "bir", "bu", "da", "de", "için"; ikililer "diye konuştu", "ya da"; üçlüler "spor toto süper", "şöyle devam etti" gibidir.
  - 8 milyon n-gramdan yalnız 36 bini 50'den fazla geçer; bunlarla ilerlenince tekil kelime sayısı 20 bin olur. Örnek dönüşümler (ekrandan, 01:41:20): "yer alırken" → "yeralırken", "kız kardeşi" → "kızkardeşi", "cep telefonundan" → "ceptelefonundan", "700 milyon" → "700milyon".
- Bölüm 4: "ML v2" (makine öğrenmesinde güncel teknikler)
  - Hoca bu bölümü doğrudan hesaplamalı anlambilime özel değil, makine öğrenmesindeki güncel ve araştırmaya açık tekniklere dair vizyon vermek için anlattığını söyledi.
- Aktif öğrenme
  - Tanım: eğitim örneklerinin etiketleri başta belli değildir; algoritma etiketini istediği örnekleri seçer. Amaç, para ile yapılan etiketleme sürecinin maliyetini optimize etmektir: rastgele 500 örnek yerine akıllıca seçilmiş 500 örneği etiketletmek.
  - Adımlar (ekrandan, 01:50:00): A) küçük bir eğitim setiyle ($E$) başla; B) model üret ve etiketsiz eğitim örneklerine ($EE$) dair tahminleri üret; C) tahmin varyasyonuna göre bunların bir kısmını seç, etiketlerini iste, $EE$'den çıkar, $E$'ye ekle; B ve C'yi tekrar et.
  - Tablo (ekrandan, 02:00:00): etiketli/etiketsiz 0/1000 → 100 (M1)/900 → 200 (M1)/800 → … → 1000/0.
  - Hangi örnek seçilir: Örnek 1 A: 0.51, B: 0.49; Örnek 2 A: 0.95, B: 0.05 ise modelin emin olmadığı Örnek 1'in etiketini öğrenmek daha makuldür. Bu tür örnekler sınıfların sınır bölgelerindedir.
  - Açık sorular: başlangıç setinin nasıl seçileceği (rastgele mi, kümeleme ile mi), sınıflandırma ve regresyonda tahmin varyasyonunun nasıl hesaplanacağı, ne zaman durulacağı (bütçeye bağlı), her adımda kaç örnek ekleneceği (hiperparametre).
  - Deneyler (6 veri kümesi: segment, vehicle, autos, iris, hillValley, audiology; 20 adım; ekrandan, 02:02:40): önce kolay örnekleri eklemek rastgele seçimden genelde daha kötüdür. Önce zor örnekleri eklemenin yararlı olduğu veri kümeleri vardır; bazılarında verinin yarısıyla bütününe yakın başarıya ulaşılır.
  - Bulgular (ekrandan, 02:09:05): önce kolay örnekleri eklemek iyileştirmiyor; önce zor örnekleri eklemenin yararlı olduğu veri kümeleri var; bazı veri kümelerinde tüm eğitim örnekleri yerine daha az örnekle daha yüksek test başarısına erişilebiliyor (bu, veri kümesinde gürültülü örnekler olabileceğini gösterir).
- Yarı eğiticili öğrenme (semi-supervised learning, ekrandan, 02:10:00)
  - Modelin oluşturulmasında etiketli verilerin yanında etiketsiz verilerin de kullanıldığı problemlerdir. Temel fikir: belirli bir test seti üzerinde, yalnız etiketli verileri kullanmak yerine etiketsizleri de kullanmak daha iyi olur. Aktif öğrenmeden farkı: etiket satın alma imkânı yoktur.
  - Yöntem: etiketli verilerle model kurulur, etiketsizlerin sınıfı tahmin edilir, tahmin edilen etiketlerle model yeniden eğitilir. Regresyonda tahmin güvenini ölçmek için farklı yaklaşımlar gerekir.
  - Tek adım mı, iteratif mi: tek adımda bütün etiketsizler etiketlenirse karar sınırı değişmez. İteratif yapıda her adımda en güvenilen örnekler etiketlenir ve süreç daha dinamik olur. Ancak her adım bir öncekine bağlı olduğundan hatalar birikir ve zamanla daha az güvenilen tahminler yapılır; etiketsizlerin hepsini kullanmak iyi olmayabilir.
  - Deneyler (ekrandan, 02:20:00): supervised (yalnız etiketli veri), batch ve iterative semi-supervised 6 veri kümesinde karşılaştırılmış. Grafiklere göre segment, vehicle ve iris'te yalnız etiketli veri ile kurulan modelin başarısı aşılamamış; autos ve audiology'de aşılmış, hillValley'de yalnız ilk iterasyonlarda aşılmıştır. İteratif yöntemin başarısı iterasyonlar boyunca çok dalgalanır; erken durmak daha iyi olabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ortalama almak sıralamaya bakmaz
  - "Ali yemek" ile "yemek Ali" aynı vektörü verir. Buna rağmen ortalama metnin konusu hakkında kaba bir bilgi taşır ve farklı uzunluktaki metinleri aynı uzaya taşır.
- Ölçeklenebilirlik
  - Birlikte geçme matrisi yöntemleri $V\times V$ yapı gerektirir. word2vec'in asıl güzelliği hiçbir yerde $V\times V$ matris olmamasıdır.
- Yalnız pozitif geri bildirimle eğitim çöker
  - Sadece "şunlar benzesin" denip "şunlar benzemesin" denmezse temsil uzayı tek noktaya çöker ve sistem hiçbir şey öğrenmez. Negatif örnekleme bu yüzden gereklidir.
- FastText'in n-gram benzerliğinin iki yüzü
  - "terlik" ile "noterlik"in yakın çıkması zararlıdır, "virüs" ile "virüsün"ün yakın çıkması faydalıdır. Duruma göre n-gram benzerliği kullanılır ya da kullanılmaz.
- Sonuçları birden fazla veri kümesinde denemek
  - Küçük veri kümelerinde oynaklık çok yüksektir; tek bir veri kümesine bakarak karar vermek doğru olmayabilir. Birkaç veri kümesinde denemek sonuçları daha rahat eleştirmeyi sağlar. Sonuçlarınızı eleştirmek iyidir.
- Aktif öğrenmede asıl önemli olan sınır bölgeleri
  - Sınıfların iç içe geçtiği yerlerden etiket istemek gerekir; etiketi zaten belli olan örnekler için para harcamaya gerek yoktur.

## Kısa Tekrar Notları

- Metin koordinatı = kelime koordinatlarının boyut boyut ortalaması; sıra bilgisi kaybolur, boyut sabit kalır.
- 4500 boyutlu seyrek temsil yerine 100 ya da 10 boyutlu yoğun temsil, konu sınıflandırmada %90 civarı başarı verir.
- Birlikte geçme matrisi + MDS ölçeklenmez; tek vektörlü temsil çok anlamlı kelimelerde sorunludur (Jaguar).
- Kelime yörüngeleri: mesafe ve açı histogramlarından 100 özellik; yazar tanımada 2 yazarda %98.57, 8 yazarda %68.57.
- word2vec: tek gizli katman, $W_{|V|\times d}$ satırları kelime vektörleridir. Skip-gram: ortadaki kelimeden bağlamı tahmin; C-bow: bağlamdan ortadakini tahmin.
- Negatif örnekleme: $P(w)$'ye göre $k$ (genelde 5) kelime seçilip uzaklaştırılır; yoksa uzay çöker.
- FastText: kelime içi n-gram benzerliği; eklemeli dillerde ve yanlış yazımda avantajlı, sözlük dışı kelimelere de vektör bulur, daha yavaştır.
- Kelime vektörleri dahili (insan benzerlik/analoji yargıları) ve harici (başka görevlerde başarı) yöntemlerle değerlendirilir.
- Kelime öbekleri: sık geçen kelime n-gramları tek kelime yapılıp sözlüğe katılır.
- Aktif öğrenme: modelin en emin olmadığı örneklerin etiketini iste; önce kolay örnekler eklemek işe yaramaz.
- Yarı eğiticili öğrenme: etiketsizlerin tahmini etiketlerini de kullan; iteratif yaklaşımda hatalar birikebilir, bütün etiketsizleri kullanmak her zaman iyi değildir.

## Detaylı Açıklamalar

- Önceki derste birlikte geçme sayılarından bir benzerlik matrisi kurulmuş, MDS ile kelimelere koordinat verilmişti. Bu ders, bu koordinatların cümle ve doküman gibi daha büyük birimlere nasıl taşınacağıyla başladı. Tüm kelimeler aynı uzayda olduğu için (birinci boyut her kelimede aynı şeyi ifade eder) boyut boyut ortalama almak anlamlıdır. "Ali yemek" örneğinde $(0.7+0.5)/2=0.6$, $(-0.2+0.9)/2=0.35$, $(0.8+0.7)/2=0.75$ bulunur (ekrandan, 00:10:00). Haber sınıflandırma deneyinde bu basit yöntem 4500 boyutlu terim-doküman temsilinden daha iyi sonuç vermiştir. Ancak $V\times V$ birlikte geçme matrisinin oluşturulması ve çarpanlara ayrılması ölçeklenmez; bu yüzden internette arama motoru sorgularıyla değil kendi derlemleriyle çalışılmıştır.
- Çok anlamlı kelimeler tek vektörle temsil edilince, kelimenin farklı anlamlarındaki komşu grupları da birbirine yaklaşır. Hoca bunu "ikinci dereceden birlikte geçme" olarak açıkladı ve çözümün ileride bağlam farkında modellerle geleceğini belirtti.
- Kelime yörüngeleri çalışmasında içerikten (kelime koordinatlarından) bağımsız özellikler kullanıldığı için yazar, konu değişse bile tanınabilir. Ardışık kelime koordinatları arasındaki fark vektörünün kendisinin de anlamsal bir karşılığı olabileceğini hoca bir olasılık olarak andı. Sonuçlar 2 yazarda neredeyse kusursuz, yazar sayısı arttıkça düşer; yine de 8 yazarda %68.57, %12.5'lik Zero Rule'un çok üstündedir.
- word2vec'te giriş bir kelimenin one-hot vektörüdür (sözlükteki indisi 1, diğerleri 0). Eğitim kümesi metin üzerinde kayan bir pencereyle (giriş, çıkış) ikilileri üretilerek kurulur. Ortadaki kelime verildiğinde çevresindeki kelimelerden herhangi birinin çıkması istendiği için bu çevre kelimelerin temsilleri birbirine ve ortadaki kelimeye yaklaşır. Pencere kaydıkça birbirine yakın geçen kelimeler hep yaklaştırılır. Hata fonksiyonu iki parçalıdır: pozitif ikililerin iç çarpımları büyütülür, $P(w)$'den seçilen $k$ negatif kelimeyle iç çarpım küçültülür.
- Bir öğrenci, $P(w)$'den seçilen negatif kelimenin bağlam kelimelerinden biri olup olamayacağını sordu. Hoca bunun mümkün olduğunu, iyi bir şey olmadığını ama sık kelimelerin zaten çok anlamlı olup koordinatlarının güvenilir bulunamadığını söyledi.
- FastText'te iki kelime yalnız birlikte geçtikleri için değil, ortak karakter n-gramları olduğu için de yakınlaşır. Bu, "geliyorum" ve "geliyorsun" gibi birbiriyle pek birlikte geçmeyen ama aynı kökten gelen kelimeleri yakınlaştırır; ama "terlik" ve "noterlik" gibi ilgisiz kelimeleri de yaklaştırır. Kendi eğittikleri n-gramsız vektörlerde (19 bin kelime) sonuçlar yalnız birlikte geçmeye dayanır ve yine makuldür; ancak "virüsler" gibi ekli halleri "virüs"ten uzak kalabilir.
- Aktif öğrenmede amaç, bütün veriyi etiketletmeden (örneğin 200'lük bütçeyle) yeterince iyi bir model kurmaktır. Örnek seçimi modelin belirsiz olduğu yerlere yoğunlaşır; bir gösterimde üç sınıflı veride seçilen örnekler kırmızı ve sarı sınıfların sınır bölgesinde toplanmış, uzaktaki mavi sınıfa hiç dokunulmamıştır. Deneylerde aktif öğrenmenin son adımı ile rastgele seçimin son adımı aynıdır, çünkü ikisi de sonunda bütün veriyi kullanır; asıl fark ara adımlardadır.
- Yarı eğiticili öğrenmede iki etiketli noktadan çekilen düz bir karar sınırı, etiketsiz noktaların dağılımı dikkate alınınca veri kümeleri arasındaki boşluktan geçen eğri bir sınıra dönüşebilir (ekrandan, 02:10:00). Bunun için etiketsizlerin sınıfları tahmin edilir. Tek adımda bütün tahminler eklenirse model kendi kararını tekrar eder; iteratif yöntemde önce çekirdeğe yakın, güvenilen örnekler etiketlenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
