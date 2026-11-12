# Ders 5 Çalışma Özeti

## Genel Konular

- Geçen dersin tekrarı: LSI ve LDA
  - Saklı Anlam İndeksleme (LSI): doküman-kelime matrisi olduğu gibi hiyerarşik kümelemeye verildiğinde dokümanlar sınıflarına göre iyi ayrılmıyordu; SVD ile 9 boyuttan 5 boyuta indirilince ilk dört (kedi) ve son dört (köpek) doküman kendi aralarında toplandı. Sisteme sınıf bilgisi verilmedi.
  - Büyük ölçekli LSI (`lsi_modeli.m` kodu): kelimelerin koordinatları üretildiğinde yakın anlamlı kelimeler yakın koordinatlara düşer; örnek kümede gaz, metreküp, enerji, bakanlık, İran gibi gazla ilgili kelimeler bir arada çıktı.
  - Latent Dirichlet Allocation (LDA) bir konu modelleme (topic modeling) yöntemidir. Varsayımı: kelimeler konuları, konular da dokümanları belli olasılıklarla oluşturur. Bir doküman birden fazla konu içerebilir.
  - Haber metinleriyle 4 konu çıkarılan örnekte (`lda_modeli.m`, ekrandan, 00:10:00) Topic 1'de dizi, film, aşk, şarkıcı, müzik gibi magazin kelimeleri; Topic 2'de banka, faiz, aylık, sermaye gibi ekonomi kelimeleri; Topic 3'te almanya, ırak, çin, endeksi gibi dünya kelimeleri; Topic 4'te otomobil, yerli, eğitim, turizm gibi daha karışık kelimeler vardı. Aynı konudaki kelimeler birbirine daha benzerdir.
- Kavramsal ağaç (taksonomi) ile anlamsal benzerlik
  - Kavramsal ağaç, "X bir tür Y'dir" (IS-A) ilişkileriyle kurulmuş hiyerarşidir. İki temel yaklaşım: bağ sayma (yalnız taksonomi) ve ortak/müşterek bilgi (mutual information; taksonomi ve derlem birlikte).
  - Bu yöntemlerde İngilizce WordNet kullanılır. WordNet'in düğümleri synset'tir: aynı anlama gelen kelimeler kümesi. Çok anlamlı bir kelime, anlamı kadar farklı synset'te yer alır. WordNet elle, uzun emekle oluşturulmuştur; kökünde "entity/thing" benzeri tek bir kavram vardır, altında somut ve soyut diye ayrılır; yaklaşık 200 bine yakın synset içerir (hocanın aktardığı).
  - Leacock & Chodorow (1998) (ekrandan, 00:13:30): $sim_{LC}(c_1,c_2) = -\log \frac{len(c_1,c_2)}{2L}$. $len$: iki synset arasındaki en kısa yolun uzunluğu (benzerlikle ters orantılı); $L$: tüm taksonominin derinliği. Logaritma ölçekler, baştaki eksi uzaklığı benzerliğe çevirir.
  - Wu & Palmer (1994) (ekrandan, 00:20:00): $sim_{WP}(c_1,c_2) = \frac{2 N_3}{N_1 + N_2 + 2 N_3}$. $N_1$, $N_2$: $c_1$ ve $c_2$'nin en yakın ortak üst synset'ine ($lcs(c_1,c_2)$) IS-A bağlarıyla uzaklıkları (benzerlikle ters orantılı). $N_3$: $lcs$'nin köke uzaklığı (ortak üst synset'in spesifikliğini gösterir, benzerlikle doğru orantılı).
  - Jiang-Conrath (1997) ve Lin (1998) taksonomiye ek olarak derlem kullanır (ekrandan, 00:23:00). $P(concept) = freq(concept)/freq(root)$; $freq(x)$, $x$ synset'inin ve altındaki tüm synset'lerin derlemdeki frekanslarının toplamıdır (ör. $freq(x) = f(x)+f(x1)+f(x2)+f(x21)+f(x22)$). Kökün frekansı derlemdeki toplam kelime sayısına eşittir.
  - Slayttaki biçimler (ekrandan, 00:25:00): $sim_{JC}(c_1,c_2) = 2\log p(lcs(c_1,c_2)) - (\log p(c_1) + \log p(c_2))$ ve $sim_L(c_1,c_2) = \frac{2\log p(lcs(c_1,c_2))}{\log p(c_1) + \log p(c_2)}$. Biri A'dan B'yi çıkarır, öteki A'yı B'ye böler; anlamca aynı yöne giderler. A (ortak üst synset) iki kavramın beraber geçtiği doküman sayısına, B iki kavramdan herhangi birini içeren doküman sayısına benzetildi.
  - Yöntemler 38 kelime çiftinde insanların verdiği benzerlik puanlarının ortalamasıyla korelasyona bakılarak karşılaştırılmış; sonuçlar fena değil. Sorun: derlem kolay toplanır ama ağacı (taksonomiyi) her dil için kurmak çok zordur; dil yaşar, yeni kelimeler girer, frekanslar değişir, ağacın güncellenmesi gerekir ve bilinmeyen kelimeler sorun olur.
- Birbiri yerine kullanılan kelimeler (Deniz Yüret, 2009) (ekrandan, 00:30:00)
  - "W1 W2 X1 W3 W4" ve "W1 W2 X2 W3 W4" dizilerinde X1 ve X2 aynı bağlamda birbiri yerine kullanılmıştır; aralarında bir ilişki vardır. Kaç farklı bağlamda birbiri yerine kullanıldılarsa bağ o kadar güçlüdür.
  - Bir bitirme projesinde bulunan örnekler (ekrandan, 00:31:30): dolar-ytl 939, bulun-olmak 619, avro-euro 459, kanun-yasa 350, avro-dolar 344, oyna-yap 309, dolar-lira 251, dolar-euro 249, milyar-milyon 241, meclis-tbmm 219, belir-kaydet 194, futbol-oyun 189, art-azal 187, avro-ytl 182, alan-saha 177, gerek-iste 176, lira-ytl 173, haziran-nisan 161.
  - Bulunan çiftler eş anlamlı (kanun-yasa), zıt anlamlı (art-azal) ya da kardeş kavram (haziran-nisan; aynı üst kavramın altındaki kavramlar, ör. para birimlerinin altında dolar, sterlin, frank) olabilir.
- Kelime kümeleme (ekrandan, 00:40:00)
  - Kelimeler üç matrise göre kümelenebilir: terim-doküman matrisi (satırlarda terim, sütunlarda doküman), birlikte geçme matrisi (satırlarda ve sütunlarda terim), sınıflarda yer alma olasılıkları (satırlarda terim, sütunlarda sınıf). Aynı kümedeki kelimeler birbirine benzerdir.
  - Terim-doküman matrisinde her terim, doküman sayısı boyutlu uzayda bir noktadır; transpozu olan doküman-terim matrisinde her doküman, terim sayısı boyutlu uzayda bir noktadır.
  - Birlikte geçme matrisinin $(i,j)$ hücresi $i$'inci kelimenin $j$'inci kelimeyle kaç kez birlikte geçtiğidir. Birlikte geçme aynı cümlede, aynı metinde ya da sabit uzunlukta bir pencerede sayılabilir. Matris terim × terim boyutludur.
  - İlk iki matris için doküman sınıfları gerekmez; sınıflarda yer alma olasılığı için gerekir (Naive Bayes'e benzer). Her sınıfta geçen kelime pek anlamlı değildir, belli sınıflara özgü kelimeler daha değerlidir.
- Anlamsal uzay ve koordinat atama
  - Anlamsal uzay, kavramların anlamsal yakınlıklarına göre yer aldıkları uzaydır. Koordinat üretme yolları: terim-doküman matrisini ayrıştırma (LSI), konu modelleri (LDA), birlikte geçme matrisleri (MDS; slaytta GloVe da anılır), sinirsel dil modelleri (word2vec, FastText).
  - Kümeleme yalnız "aynı kümede/değil" bilgisi verir; koordinat ise bir kelimeye en yakın kelimeleri sıralamayı sağlayan daha yüksek çözünürlüklü benzerlik verir.
- Birlikte geçme matrisi ve çok boyutlu ölçekleme (MDS)
  - Harris: birlikte kullanılan kavramlar anlamca birbirine benzer.
  - Örnek çalışma (Amasyalı, 2006): arama motoruna "kelime1 kelime2" sorgusu gönderilip dönen sonuç sayısı iki kelimenin aynı web sayfasında birlikte geçme sayısı olarak alındı. 10 yer, 10 hayvan, 10 taşıt adından 30 × 30'luk benzerlik matrisi kuruldu.
  - MDS (çok boyutlu ölçekleme, ÇBÖ), aralarındaki uzaklıklar bilinen nesnelere bu uzaklıklarla en uyumlu koordinatları üretir. Örnek: şehirler arası karayolu mesafe tablosundan şehirlerin harita koordinatları. Nesne sayısı kadar boyut üretir; PCA'deki gibi ilk boyutlar en önemlileridir.
  - MDS uzaklıkla çalışır, birlikte geçme ise yakınlıktır; dönüşüm olarak uzaklık = 1/yakınlık kullanıldı.
  - Veri kümesi 1'in iki boyutlu MDS çözümünde (ekrandan, 00:50:00) hayvanlar (aslan, akrep, akbaba, arı, bit, balina), taşıtlar (cip, ambulans, traktör, limuzin, tren, otomobil, araba, taksi, otobüs) ve yerler (dershane, park, okul, hastane, kuaför, otel, bakkal, büfe, berber) ayrı bölgelerde toplandı. Veri kümesi 2'de (ev eşyaları, hayvanlar, giyecekler) "bit" ile "divan" yakın çıktı, çünkü sık birlikte geçiyorlar. Veri kümesi 3'te 6 kategoriden 6'şar, 36 terim vardı.
  - Bu koordinatlarla kelimeler SVM, C4.5, Random Forest gibi eğiticili ve EM gibi eğiticisiz yöntemlerle 2, 4 ve 10 boyutta sınıflandırıldı; sonuçlar fena değildi.
  - Teknik terim sınıflandırma: 967 teknik terimin koordinatları 15.000 web sitesinden oluşan bir külliyat üzerinden çıkarıldı. Google kullanılmadı, çünkü $967 \times 967 = 935.089$ sorgu gerekir (20.000 terim için 400 milyon). Tıp, edebiyat, zooloji, ekonomi terimleri ayrı bölgelere düştü; teknik terimler kendi alanlarındaki terimlerle birlikte geçmeye yatkın oldukları için sınıflandırılmaları kolaydır.
- Anlamsal uzayların metin sınıflandırmada kullanımı (Amasyalı, Beken, 2009)
  - 5 haber sınıfı (ekonomi, magazin, sağlık, siyasi, spor), sınıf başına 230 metin (150 eğitim, 80 test), kelime kökleri bulundu; yaklaşık 4500 farklı gövde. Yakınlık = külliyatta birlikte geçtikleri doküman sayısı, uzaklık = 1/yakınlık, MDS'de ilk 100 ve ilk 10 boyut alındı (ekrandan, 01:00:00).
  - Metin koordinatı, içindeki kelimelerin koordinatlarının boyut boyut ortalamasıdır; böylece metin ve kelime aynı boyutta olur.
  - Sonuçlar (ekrandan, 01:04:50): 100 boyutlu metinlerle Lineer Regresyonla Sınıflandırma %93.25, 10 boyutla %89; 4500 boyutlu tf temsiliyle Klasik Naive Bayes %87.25, tfidf ile Diskrit Naive Bayes %89.25. Daha yüksek başarı ve daha az bellek.
  - Yöntem dilden bağımsızdır. Zayıflıkları: sondan eklemeli dillerde terim sayısı çok büyür; çok anlamlı kelimeler (ör. İngilizce "apple": meyve ve şirket) tek, sabit bir koordinat alır ve iki anlamın ortasına düşer.
- Kelime yörüngeleri (Amasyalı, Yener, Kaplan, 2012)
  - Metin, kelime koordinatlarının ortalamasıyla değil, kelimelerin sırayla izlediği yörüngeyle (path) temsil edilir. Örnek metinler: "Bugün yolda kedi gördüm. Arkasından gittim. Hızlı koşuyordu. Yakalayamadım." ve "Hızlı araba kullanmak tehlikelidir. Kediler arabaların altında ..." (ekrandan, 01:27:00 civarı).
  - Yörüngeler farklı uzunlukta olduğu için iki özellik kullanılır: kavramlar arası mesafeler ve açılar. Ardışık 4 koordinat $(n, n+1, n+2, n+3)$ için $(n,n+1)$, $(n,n+2)$, $(n,n+3)$ arası mesafelerin ve $(n,n+1,n+2)$, $(n,n+2,n+3)$ arası açıların (PI cinsinden) 10'luk histogram değerleri ve frekansları alınır; her yörünge 100 özellikle temsil edilir (ekrandan, 01:30:00). Kelimelerin koordinatları özellik olarak kullanılmaz.
  - Yazar tanıma sonuçları (ekrandan, 01:33:30): 2 yazar için Destek Vektör Makineleri %98.57; 3, 4, 8 yazar için SVM %94.29, %85.71, %68.57; Zero Rule %33.33, %25, %12.5. Kadın-erkek yazar ayrımında fark çıkmadı. Olası kullanım: psikolojik hastalıkların tespiti.
  - Zero Rule: eğitim verisinde en sık sınıfı bütün test örneklerine vermek; dengeli veri kümesinde başarısı $1/\text{sınıf sayısı}$'dır.
- Sinirsel dil modelleri: word2vec (Mikolov ve ark., 2013)
  - MDS'deki işi (kelimelere koordinat bulma) ölçeklenebilir ve hızlı yapar: 50 bin terim için 50 bin × 50 binlik matris gerekmez.
  - Tek gizli katmanlı yapay sinir ağıdır. $C=2$ için bağlam $(w_{t-2}, w_{t-1}, w_t, w_{t+1}, w_{t+2})$ (ekrandan, 01:40:00).
  - Skip-gram: giriş $w_t$, çıkış bağlam kelimelerinin her biri. CBOW: giriş bağlam kelimelerinin her biri, çıkış $w_t$.
  - Giriş one-hot vektördür ($1 \times |V|$). $W$ ($|V| \times d$) ile çarpılınca $1 \times d$ elde edilir, $C$ ($d \times |V|$) ile çarpılınca $1 \times |V|$ çıkış olur. Eğitim bitince $W$'nin satırları kelimelerin $d$ boyutlu vektörleridir.
  - Amaç (ekrandan, 01:47:40): bir kelimenin ($w$) etrafındaki kelimelerle ($c$) benzer, diğerleriyle ($w_i$) farklı vektörlere sahip olması. Benzer vektörlerin iç çarpımı yüksektir. Negatif örneklemeli skip-gram hata fonksiyonu: $\log \sigma(c \cdot w) + \sum_{i=1}^{K} \mathbb{E}_{w_i \sim p(w)} [\log \sigma(-w_i \cdot w)]$.
  - Yalnız "etrafındakilere benzesin" amacı olsaydı bütün kelimeler aynı koordinata çökerdi. Bu yüzden negatif örnekleme gerekir: her pozitif örnek için $K$ negatif örnek (Mikolov'da yaklaşık 5, hocanın hatırladığı) frekansa göre $p(w)$'den rastgele seçilir.
  - Eğitim örnekleri (ekrandan, 01:50:00): "w1 w2 w3 w4 w5 w6 w7 ..." metninde $C=2$ için benzer olması istenen ikililer (w3,w1), (w3,w2), (w3,w4), (w3,w5); farklı olması istenenler (w3,t1) ... (w3,tK). Sonra w4 ile devam edilir. CBOW için ikililer tersine çevrilir. Yöntem dilden bağımsızdır.
- FastText (Bojanowski ve ark., 2017)
  - word2vec'e ek olarak kelime içi n-gram (subword) benzerliğini kullanır; her n-gram için vektör öğrenir. Sözlükte olmayan kelimenin vektörünü de alt parçalarından üretebilir.
  - Türkçe gibi eklemeli dillerde avantajlıdır: aynı kelimenin farklı ekli ve yanlış yazılmış hâlleri yakın koordinata düşer. Daha yavaştır (en az 2-3 kat, hocanın hatırladığı).
  - Hazır FastText vektörleri (416 bin kelime) ile en yakın 19 kelime (ekrandan, 01:54:30): "cimbom" için cimbombom, penaltılarla, beşiktaş, galatasaray; "terlik" için terliksi, terlikler, noterlik, yeterlik, dülgerlik; "virüs" için virüsün, virüsü, virüsle; "elma" için armut, şeftali, meyve, ayva, üzüm; "aslan" için aslanlar, aslanyürek; "koş" için koşa, koşun. Ekli hâlleri toplamak iyidir; "terlik-noterlik", "terlik-yeterlik" gibi yakınlıklar istenmez. word2vec'te "terlik" ve "noterlik" aynı bağlamda geçmediği için yakın çıkmaz.
  - 42 bin haber metniyle n-gram benzerliği olmadan eğitilen vektörlerde "virüs"e bulaşan, HIV, hastalık, grip, aşı ve zararlı, yazılım, bilgisayar gibi anlamca yakın kelimeler çıktı; iki anlamın (biyolojik ve yazılım virüsü) ikisine de yakın kelimeler gelmesi çok anlamlılık sorunudur.
  - Kelime koordinatlarının büyük derlemlerden üretilip her dil için hazır yayımlanması 2012 civarında başladı (hocanın aktardığı); FastText vektörleri bugün birçok dil için hazır dağıtılır. Matris boyutu $|V| \times d$'dir (ör. 416.000 × 100), $|V| \times |V|$ matris hiç kurulmaz.
- Kelime vektörlerinin başarısını ölçme (ekrandan, 02:00:00)
  - Dahili/direkt yöntemler: insanların verdiği cevaplarla korelasyon, analoji veri kümeleri.
  - Harici/dolaylı yöntemler: vektörlerin kullanıldığı NLP uygulamalarındaki başarı (metin sınıflandırma, makine çevirisi, metin özetleme, varlık ismi tanıma).
  - Cümle ve metin vektörü için en basit yol içindeki kelime vektörlerinin ortalamasıdır; Universal Sentence Encoder'a da değinildi.
- Kelime öbekleri
  - "Fatih Sultan Mehmet" gibi birlikte kullanılan 2, 3, 4 kelimelik ifadeler, içerdikleri kelimelerin her birinden ayrı bir kavram ifade eder; tek token olarak almak daha iyidir. Yalnız özel isimler değil, deyimler de ("etekleri zil çalmak") öbek olabilir.
  - Bulma yolları (ekrandan, 02:05:20): en basiti frekansı en yüksek olanlar; kelime öbeği olma olasılığı $t_i$'nin frekansı / $t_i$'nin içerdiği tekil kelimelerin frekanslarının minimumu ya da $\log_2(t_i$'nin frekansı / tekil kelimelerin frekanslarının çarpımı$)$.
  - Uygulama (`kelime_obekleri.m`, ekrandan, 02:07:10): 42 bin haber metninde 1, 2, 3 uzunluklu kelime n-gramları. Nadir kelimeler silinmezse 11 milyon n-gram. 50'den az geçen kelimeler silinince tekil kelime 356.680'den 20.661'e iner (336.019 silinir), toplam kelime 9.986.668'den 8.320.579'a; n-gram sayısı yaklaşık 8 milyon (8.141.753), bunlardan yaklaşık 36 bini 50'den fazla geçer.
  - Sık n-gramların kelimeleri birleştirilerek tek kelime yapılır ("dışişleribakanı", "ortakbasıntoplantısı", "görüşmelerinardından") (ekrandan, 02:10:00). Sistem bunları yeni kelime olarak görür ve word2vec her biri için ayrı vektör üretir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Taksonomi tabanlı yöntemlerin pratik sorunu
  - Derlem etiketsiz veridir, toplamak kolaydır; ama kavramsal ağacı her dil için kurmak ve dil değiştikçe güncellemek çok zordur. Bilinmeyen kelimeler büyük sorun olur.
- Wu & Palmer'da $N_3$'ün yönü
  - Ortak üst synset kökten ne kadar uzaksa (ağacın dibine yakınsa) kavramlar o kadar spesifiktir ve iki kavram o kadar benzerdir.
- MDS uzaklık ister
  - Birlikte geçme yakınlıktır; MDS'ye vermeden önce uzaklığa çevrilmelidir (1/yakınlık).
- Sınıf bilgisi verilmeden benzerlik ortaya çıkar
  - MDS ve LSI örneklerinde sisteme hangi kelimenin hangi gruba ait olduğu söylenmedi; yalnız birlikte geçme bilgisi kullanıldı.
- Sabit koordinat ve çok anlamlılık
  - Bir kelimeye sabit bir koordinat verildiğinde farklı anlamları ayırt edilemez; ileride görülecek bağlam farkında sinirsel modellerde kelimenin koordinatı etrafındaki kelimelere göre değişecek.
- Negatif örneklemenin gerekliliği
  - Yalnız benzerlik amacıyla eğitilen ağ bütün kelimeleri aynı noktaya çökertir; farklılık amacı negatif örneklerle sağlanır.
- Ölçeklenebilirlik
  - Birlikte geçme matrisi $|V| \times |V|$'dir (416 bin kelime için kimsenin işleyemeyeceği boyut); word2vec yalnız $|V| \times d$ ve $d \times |V|$ boyutlu iki matris öğrenir.

## Kısa Tekrar Notları

- LDA: kelimeler konuları, konular dokümanları oluşturur (konu modelleme).
- WordNet düğümü synset: aynı anlamdaki kelimeler kümesi. Çok anlamlı kelime birden fazla synset'te bulunur.
- Leacock & Chodorow: $-\log \frac{len(c_1,c_2)}{2L}$ (yalnız taksonomi).
- Wu & Palmer: $\frac{2N_3}{N_1+N_2+2N_3}$; $N_3$ büyüdükçe benzerlik artar.
- Jiang-Conrath ve Lin: taksonomi + derlem; $P(c) = freq(c)/freq(root)$; $freq(root)$ derlemdeki toplam kelime sayısı.
- Birbiri yerine kullanılan kelimeler: aynı bağlamda yer değiştiren kelimeler eş, zıt ya da kardeş anlamlı olabilir.
- Kelime kümeleme: terim-doküman, birlikte geçme, sınıflarda yer alma olasılığı matrisleri.
- MDS: uzaklık matrisinden koordinat; uzaklık = 1/yakınlık.
- Metin vektörü = kelime vektörlerinin ortalaması.
- Kelime yörüngesi: ardışık kelimeler arası mesafe ve açı histogramları (100 özellik); yazar tanımada başarılı.
- Zero Rule: en sık sınıfı her örneğe ver; dengeli veride $1/k$.
- word2vec: tek gizli katman; skip-gram ($w_t \to$ bağlam), CBOW (bağlam $\to w_t$); $W$ ($|V| \times d$) kelime vektörleri.
- Negatif örnekleme: pozitif başına $K$ negatif, $p(w)$'ye göre rastgele.
- FastText: subword n-gramları; sözlük dışı kelimeye vektör üretir; eklemeli dillerde avantaj, ilgisiz alt dizgi benzerliği dezavantaj.
- Değerlendirme: dahili (insan korelasyonu, analoji) ve harici (NLP uygulamaları).
- Kelime öbekleri: sık n-gramlar birleştirilip tek token yapılır.

## Detaylı Açıklamalar

- Ders, geçen haftanın anlamsal uzaylar bölümünü toparlayarak başladı. LSI örneğinde doküman-kelime matrisinin ham hâliyle yapılan hiyerarşik kümeleme dokümanları sınıflarına göre iyi ayırmıyordu. SVD ile 9 boyuttan 5 boyuta inilip yeni dokümanlar üretilince ilk dört ve son dört doküman kendi aralarında birleşti. Büyük ölçekli LSI kodunda kelimelerin koordinatları üretilir ve yakınlaştırılmış bölgelerde "gaz, metreküp, enerji, bakanlık, İran" gibi aynı konudaki kelimelerin yan yana düştüğü görülür. LDA ise farklı bir varsayımla çalışır: her konu kelimelerden belli olasılıklarla oluşur, her doküman da konulardan. Bu yüzden LDA, birden fazla konu içeren dokümanlarda konu bütünlüğü sağlayan parçaları bulmak için de kullanılır.
- Taksonomi tabanlı benzerliklerde ağaç WordNet'in yalnız IS-A ilişkileriyle kurulmuş hâlidir. Hayat bilgisi veri tabanında ilişkiler kavramlar arasındaydı; WordNet'te ise synset'ler arasındadır. Leacock & Chodorow iki synset arasındaki en kısa yolu taksonominin derinliğine göre ölçekler. Hocanın slayttaki ağaç üzerindeki örneğinde $c_1$ ile $c_2$ arasındaki yol 3 bağdır, ağacın derinliği 7 sayıldı ve oran "3 bölü 7 gibi" diye anlatıldı (ekrandan, 00:20:00).
  - Ders sonrası not: Formülün paydasında $2L$ olduğu için oran $3/(2 \cdot 7) = 3/14$ olur; doğal logaritmayla $sim_{LC} = -\ln(3/14) \approx 1.54$ çıkar (python ile hesaplandı).
- Wu & Palmer aynı ağaçta $N_1 = 2$ ($c_1$'den $lcs$'ye), $N_2 = 1$ ($c_2$'den $lcs$'ye) değerlerini verir; hoca $N_3$'ü sayısal olarak hesaplamadı. Bir öğrenci $N_3$ büyükse ortak üst synset'in daha dipte olduğunu, kavramların daha küçük bir alana sıkıştığını söyledi; hoca bunu doğruladı: ağacın üst kısmındaki kavramlar genel, alttakiler spesifiktir.
- Jiang-Conrath ve Lin, kavramın derlemdeki olasılığını kullanır. Bir synset'in frekansı kendisinin ve altındaki bütün synset'lerin frekanslarının toplamı olduğu için kökün frekansı, derlemdeki bütün kelimelerin sayısına eşittir. Hoca iki formülü A (ortak üst synset terimi) ve B (iki kavramın terimleri toplamı) diye iki parçaya ayırdı: A büyüdükçe benzerlik artar, B büyüdükçe azalır; biri farkla, öteki oranla aynı mantığı kurar.
  - Ders sonrası not: Logaritmalar negatif olduğu için yön yorumunda dikkat gerekir. Büyük olasılıkla Jiang-Conrath'ın özgün tanımında slayttaki ifade ($2\log p(lcs) - \log p(c_1) - \log p(c_2)$) bir uzaklıktır ve benzerlik genelde bunun tersi alınarak bulunur; Lin benzerliği ise 0 ile 1 arasındadır.
- Birbiri yerine kullanılan kelimeler yöntemi taksonomi gerektirmez; yalnız derlemde aynı bağlamda yer değiştiren kelimeleri sayar. Bu yöntemle bulunan ilişkiler tek türden değildir: kanun-yasa eş anlamlı, art-azal zıt anlamlı, haziran-nisan kardeş kavramdır.
- Terim-doküman ve birlikte geçme matrisleriyle kümeleme, MDS ile koordinat üretmeye uzanır. Arama motorundan alınan birlikte geçme sayıları MDS'ye verildiğinde aynı gruptaki kelimeler yakın düştü; "bit" ile "divan"ın yakın çıkması gibi beklenmedik ama birlikte geçmeyle açıklanabilen sonuçlar da oldu. MDS bütün boyutları üretir; şekillerde yalnız ilk iki boyut gösterilir, daha çok boyut kullanmak sonuçları iyileştirebilir.
- Metin sınıflandırma çalışmasında her metin, içindeki kelimelerin koordinatlarının ortalamasıyla temsil edildi. İlk iki boyuttaki çizimde farklı sınıfların farklı bölgelerde olması istenir. Spor ile magazin, ekonomi ile politika biraz iç içe girdi; bir öğrencinin sorusu üzerine hoca, iç içe giren sınıfların birbirine benzer olduğunun buradan da (ve karışıklık matrisinden de) yorumlanabileceğini söyledi.
- Kelime yörüngeleri yaklaşımında metnin ne söylediği değil, kelimeden kelimeye nasıl "zıpladığı" önemlidir. Bir yazar farklı konularda yazsa da bu zıplama örüntüsü yazara özgü olabilir; bu yüzden yaklaşım yazar tanımada başarılı oldu.
- word2vec'te $W$ ve $C$ matrisleri öğrenilir. Benzerlik iç çarpımla ölçülür; iki vektör arasındaki açı darsa vektörler benzerdir. Negatif örnekler bağlamda olmayan kelimeleri tek tek hesaplamak yerine derlem frekansına göre rastgele seçilir; nadir kelimeleri seçmek pek bir şey kazandırmaz.
- FastText'in alt dizgi benzerliği iki yönlüdür: "virüs, virüsün, virüsü" ya da "koş, koşa, koşun" gibi aynı kelimenin ekli hâllerini birleştirir (iyi), ama "terlik" ile "noterlik", "yeterlik", "dülgerlik" gibi yalnız sonu benzeyen kelimeleri de yaklaştırır (kötü). N-gram benzerliği olmadan eğitilen word2vec vektörlerinde ise yakın kelimeler anlamca yakındır.
- Kelime öbeklerinde bir öğrenci ikili ve üçlü kelime gruplarının frekansına bakmayı önerdi; hoca, tek tek kelimelerin frekanslarının da hesaba katılmasının iyi olacağını ekledi. Slayttaki iki ölçü bu fikri yansıtır. Derste en basit yol denendi: frekansı yüksek n-gramlar birleştirildi ve haber metni bu yeni token'larla yeniden yazıldı; word2vec bu hâliyle yeniden eğitilebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
