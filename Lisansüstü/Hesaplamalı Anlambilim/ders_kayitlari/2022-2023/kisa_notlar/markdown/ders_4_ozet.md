# Ders 4 Çalışma Özeti

## Genel Konular

- Geçen dersten kalan soru: 20 kelimelik kelime torbasından cümle kurmak
  - Elimizde $k$ değerini seçebildiğimiz istatistiksel bir dil modeli ve karıştırılmış 20 kelime var. Üç kelime için $3!$ sıralamanın hepsi puanlanabiliyordu; $20!$ sıralamanın hepsini puanlamak pratikte mümkün değildir.
  - Öğrencilerin önerileri: cümle başında en sık geçen kelimeyle başlayıp her adımda bir öncekinden sonra en sık gelen kelimeyi eklemek (bu, Markov varsayımında $k=1$ kullanmaktır); cümle başı sembolünden başlayıp en olası ilk 100 bigram içinde eldeki kelimelerden biri geçene kadar listeyi genişletmek ve kelimeler tükenene kadar ilerlemek; kelimeleri önce isim, sıfat, fiil diye ayırmak; uzun cümleyi bağlaçlardan ("ve", "veya") küçük cümlelere bölmek.
  - Hocanın özeti: önerilerin çoğu, probleme uygun varsayımlarla arama uzayını daraltmaya dayanır ("şu kelimeler başta olur, şunlar sonda olur" ya da ikili ve üçlüleri birleştirip büyütmek gibi). Varsayım probleme ne kadar uygunsa hızlanma ve doğru sonuca ulaşma olasılığı o kadar yüksektir.
- Dil modellerini değerlendirmek (ekrandan, 00:30:00)
  - Elimizde iki dil modeli (A ve B) olsun; hangisi daha iyi? Bu yöntemler istatistiksel dil modelleri için de, sinirsel dil modelleri için de kullanılır.
  - Harici yöntem: iki model de farklı görevlerde (makine çevirisi, yazım düzeltme, konuşmadan metne) bir temsil olarak kullanılır; o görevlerdeki performanslarına göre karşılaştırılır.
  - Dahili yöntem: derlem eğitim ve test kümesi olarak ayrılır, A ve B eğitim kümesinden oluşturulur. Test kümesindeki gerçek cümlelere hangisi daha yüksek olasılık veriyorsa ya da bir cümlenin başı verildiğinde sonunu hangisi doğru tahmin ediyorsa o daha iyidir. Elle karıştırılmış, sahte cümlelere düşük olasılık vermesi de beklenir.
  - Hoca, sinirsel modellerde bu ölçünün karşılığı olarak perplexity'yi andı.
- Test kümesi seçmenin zorluğu
  - Webden toplanmış çok büyük bir derlemden rastgele bir parçayı test kümesi seçmek iyi sonuç vermeyebilir: webde tekrarlı veri çoktur (aynı haber 30 sitede aynen ya da kırpılmış olarak geçer, aynı ürün metni birçok satıcıda tekrarlanır). Test cümleleri eğitim kümesinde de varsa model "kopya çeker" ve sonuçlar gerçek dışı derecede iyi çıkar.
  - Metin verisinde 1 GB'lık bir derlemi 10'a bölüp 10 kez eğitmek (çapraz geçerleme) çok uzun sürdüğü için pratikte kolay değildir.
- İstatistiksel dil modelleriyle dizi üretmek
  - Bir ilk kelime seçilir, sonraki kelime modelle tahmin edilir, tahmin girdiye eklenir ve devam edilir (A, sonra AB, sonra ABC; hoca buna "otoregresif" dedi).
  - $k=0$ ile her seferinde en olası kelime seçilirse hep aynı kelime tekrar eder; $k=1$ ile de bir kelimeden sonra hep aynı kelime gelir.
  - Çözüm 1: en olası $t$ kelimeden birini rastgele seçmek. Çözüm 2: sonraki kelime için bulunan olasılıklar toplamı 1 olan bir dağılım olduğundan seçimi doğrudan bu olasılıklarla yapmak (ekrandan, 00:37:50; 100 kelimelik sözlükte $W_1$: 0.001, $W_2$: 0.002, $w_3$: 0.001, …, $w_{99}$: 0.02, $W_{100}$: 0.00003).
  - Durma koşulu: istenen sayıda kelime ya da cümle üretilmesi veya cümle sonu belirtecine ulaşılması.
- Üretim örnekleri (1000 ekonomi haberinden kurulmuş derlem)
  - Bigram ($k=1$), $t=5$ (ekrandan, 00:40:00): ardışık ikililer anlamlıdır ama üçlüler değildir: "yüzde 10" ve "10 yılda" anlamlı, "yüzde 10 yılda" değil; "yer aldığı" ve "aldığı bilgiye" anlamlı, "yer aldığı bilgiye" değil. $t$ küçüldükçe metinlerden kopya çekme (aynı diziyi üretme) olasılığı artar, büyüdükçe anlamlı dizi üretme olasılığı azalır.
  - Trigram ($k=2$), $t=5$ (ekrandan, 00:42:15): ardışık üçlüler daha anlamlıdır ("ucuz bilet satıyoruz"), ama ortada bir cümle yoktur. Cümle, bütün parçaları birbirine bağlı bir birlikteliktir. 1000 magazin haberiyle aynı mekanizma magazin havasında metin üretir; yalnızca derlem değişmiştir.
  - Ardışık geçme yerine aynı dokümanda geçme kullanılırsa (ekrandan, 00:44:50): frekansı çok yüksek kelimeler (stop word) atılmalıdır, yoksa her kelimeye en benzer kelimeler onlar olur. $k=1$, $t=15$ ile üretilen dizi cümleye benzemez, anahtar kelime çıkarımı gibi görünür. "faiz"e en benzeyen kelimeler: "merkez", "kredi", "bankası", "oranı", "cari". Bu fikir benzer anlamlı kelimeleri bulmak için kullanılacaktır.
- Kelime benzerliği
  - Karakter benzerliği: edit distance, bir kelimeyi diğerine dönüştürmek için gereken işlem sayısıdır. Silme, ekleme ve değiştirmeye farklı ağırlıklar verilebilir.
  - Anlam benzerliği: "Cimbom" ile "Galatasaray" arasında karakter benzerliği yoktur ama anlamca ilişkilidirler. İstatistiksel dil modelleri ardışıklık üzerinden çalıştığı için kelime benzerliği hakkında pek bir şey söylemez.
- Saklı Anlam İndeksleme (Latent Semantic Indexing, LSI)
  - Amaç: kelimelerin ardındaki saklı kavramları ortaya çıkarıp dokümanları bu kavramlar uzayında temsil etmek (ekrandan, 01:20:00).
  - Terim-doküman matrisi (ekrandan, 01:10:00): $i,j$ hücresi $i$. terimin $j$. dokümanda geçip geçmediğini (0/1) ya da kaç kez geçtiğini gösterir. Örnek: D1: W1 w3 w5 w4; D2: W2 w4 w5; D3: W6 w8 w3; D4: w7 w3 w4. Gerçek derlemlerde sözlük on binlerce kelimeye çıkar, bir doküman ise birkaç yüz tekil kelime içerir; matris çok seyrektir (sparse).
  - Kelimeler doküman sayısı boyutlu bir uzayda, dokümanlar (transpozda) sözlük boyutlu bir uzayda noktadır. İki boyut da çok büyük ve seyrektir.
  - LSI, matematikteki tekil değer ayrıştırmasının (Singular Value Decomposition, SVD) NLP'ye uygulanmasıdır: $A_{m\times n}=U_{m\times r}\,\Sigma_{r\times r}\,V^T_{r\times n}$. SVD kare olmayan matrislere de uygulanabilir. $\Sigma$ köşegenindeki değerler büyükten küçüğe sıralıdır; yalnız ilk $k$ değer tutularak ($U_k, \Sigma_k, V_k^T$) terimler ve dokümanlar çok daha küçük boyutlu bir uzayda temsil edilir.
  - NLP yorumu: $U$ kelime-kavram, $\Sigma$ tekil değerler, $V$ doküman-kavram matrisidir. Matematiksel olarak PCA'ya benzer bir işlemdir ve gözetimsizdir (sınıf bilgisi kullanmaz).
  - Kedi/köpek örneği (ekrandan, 01:18:15): 9 kelimelik (kedi, miyav, süt, fare, köpek, havla, kemik, hayvan, tüy) 8 dokümanlık matris transpoz edilip SVD'ye verilir. 9 boyuttan 5 boyuta indirgenince dokümanlar arası uzaklıklarda 1-2-3-4 (kedi) ve 5-6-7-8 (köpek) grupları, sınıf bilgisi verilmeden daha belirgin ayrılır.
  - Büyük ölçekte haber metinleriyle LSI: kelimelerin ilk iki koordinatında magazin kelimeleri (başrol, intikam, duygu) ile ekonomi kelimeleri (enerji, gaz, şirket) farklı bölgelerde toplanır.
- Latent Dirichlet Allocation (LDA), konu modelleme (ekrandan, 01:25:15)
  - Konular kelimelerin karışımıdır, dokümanlar konuların karışımıdır. Hoca bunu SVD'nin iç içe geçmiş üçlü hâli gibi düşünmeyi önerdi: kelimeler konuları, konular dokümanları oluşturur; bir kelime birden fazla konuya ait olabilir.
  - Çalıştırıldığında her konuyu en iyi temsil eden kelimeler görülür (magazin, ekonomi, otomobil gibi konular). Bir dönem çok popüler olmuş, sonra o kadar iyi gitmemiştir.
- Kavramsal ağaçlarla anlamsal benzerlik
  - Kavramsal ağaç: bütün kavramların "bir tür" (IS-A) ilişkisiyle bağlandığı dev bir hiyerarşi. İki yaklaşım vardır: yalnız ağacı kullanmak; ağaçla birlikte bir derlem kullanmak.
  - WordNet: bilgisayarca kolay işlenebilen bir sözlük. Kavramlar eş anlamlı kümeler (synset, synonym set) içinde tutulur; ilişkiler synset'ler arasında kurulur. Bir kelime birden çok anlamı varsa birden çok synset'te bulunur.
  - Leacock & Chodorow (1998) (ekrandan, 01:30:00): $sim_{LC}(c_1,c_2)=-\log\dfrac{len(c_1,c_2)}{2L}$. $len$ iki synset arasındaki en kısa yolun uzunluğu (benzerlikle ters orantılı), $L$ taksonominin derinliğidir. Slaytta kesrin paydası araç çubuğunun altında kaldı; $2L$ büyük olasılıkla doğrudur (yöntemin bilinen tanımı).
  - Wu & Palmer (1994) (ekrandan, 01:33:00): $sim_{WP}(c_1,c_2)=\dfrac{2N_3}{N_1+N_2+2N_3}$. $N_1, N_2$: $c_1$ ve $c_2$'nin en yakın ortak üst synset'e ($lcs(c_1,c_2)$) uzaklıkları; $N_3$: $lcs$'nin köke uzaklığı. $lcs$ kökten ne kadar uzaksa ortak kavram o kadar spesifiktir, benzerlik o kadar yüksektir.
  - Jiang-Conrath (1997) ve Lin (1998) (ekrandan, 01:40:00): ağaçla birlikte derlem kullanır. $p(c)=\dfrac{freq(c)}{freq(root)}$; $freq(c)$ kavramın kendisinin ve altındaki bütün alt synset'lerin derlemdeki frekanslarının toplamıdır, $freq(root)$ bütün ağacın toplamıdır. Genel kavramın olasılığı yüksektir. $A=2\log p(lcs(c_1,c_2))$, $B=\log p(c_1)+\log p(c_2)$ olmak üzere Jiang-Conrath $A-B$, Lin $A/B$ kullanır.
  - Karşılaştırma (ekrandan, 01:40:30): yöntemler İngilizce 38 kelime çiftine uygulanmış, insan yargılarıyla korelasyonlarına bakılmış. Jiang & Conrath 0.83; Lin, Leacock & Chodorow ve Li 0.82; Resnik ve Lord 0.79; Wu & Palmer 0.74; Tversky 0.73; Rodriguez 0.71; Adapted Lesk 0.37.
- Birbiri yerine kullanılan kelimeler (ekrandan, 01:42:45)
  - "W1 W2 X1 W3 W4" ve "W1 W2 X2 W3 W4": X1 ile X2 aynı bağlamda (önceki iki ve sonraki iki kelime aynı) kullanılmıştır. Ne kadar çok farklı bağlamda birbirinin yerine kullanılırlarsa aralarındaki bağ o kadar güçlüdür.
  - Örnekler (kaç farklı bağlamda): dolar-ytl 939, bulun-olmak 619, avro-euro 459, kanun-yasa 350, avro-dolar 344, oyna-yap 309, dolar-lira 251, dolar-euro 249, milyar-milyon 241, meclis-tbmm 219, belir-kaydet 194, futbol-oyun 189, art-azal 187, avro-ytl 182, alan-saha 177, gerek-iste 176, lira-ytl 173, haziran-nisan 161.
  - Bulunan ilişkilerin türü aynı değildir: dolar-ytl kardeş kavramlar, kanun-yasa eş anlamlı, art-azal zıt anlamlıdır. Aynı durum word2vec'te de görülür.
- Anlamsal uzay ve birlikte geçme matrisleri
  - Anlamsal uzay: kavramların anlamsal yakınlıklarına göre yer aldıkları bir koordinat sistemi; uzayda yakın olanlar anlamca da yakın olmalıdır. Koordinat bulma yolları: LSI, LDA, birlikte geçme matrisleri ve (ölçeklenebilir çözüm olarak) sinirsel dil modelleri.
  - Harris: birlikte kullanılan kavramlar birbirine anlamsal olarak benzer. "Birlikte" aynı cümle, paragraf, doküman ya da sabit boyutlu bir kelime penceresi olabilir.
  - Örnek çalışma (2006) (ekrandan, 02:00:00): iki kelimenin İnternet'te kaç sayfada birlikte geçtiği, arama motoruna "kelime1 kelime2" sorgusu gönderilip sonuç sayısı alınarak bulunur. 30 kelimelik bir veri kümesi için 30×30'luk bir birlikte geçme (benzerlik) matrisi çıkar.
  - Benzerlik matrisi uzaklığa çevrilip (bir ekleyip tersini alarak) Multidimensional Scaling'e (MDS) verilir. MDS, nesneler arası uzaklık matrisine uyan koordinatları döndürür (PCA'ya benzer; döndürmeye karşı tek bir sonuç vermez).
  - Sonuç (ekrandan, 02:05:00): sınıf bilgisi verilmeden hayvanlar, yerler ve taşıtlar ayrı bölgelerde toplanır. "ahır" bizon ve ata, "bakkal" büfeye, "limuzin" trene yakın düşer (metinlerde birlikte geçtikleri için). Başka bir kümede "bit" ile "divan" yakın çıkar.
  - 967 terimde her çift için Google'a sorgu göndermek (yaklaşık 500 bin sorgu) mümkün olmadığından 15 bin web sitesinden kendi derlemleri oluşturulmuştur. Sonuçta tıp, edebiyat, zooloji, ekonomi, tarih, spor, sosyoloji, psikoloji, müzik ve kimya terimleri, sınıf bilgisi verilmeden epey ayrışır (ekrandan, 02:10:00). Bunun bir nedeni, terimlerin teknik olmasıdır: sosyoloji ile zooloji terimleri nadiren birlikte geçer.
  - Metin sınıflandırma (ekrandan, 02:13:40): bir metnin koordinatı, içerdiği kelimelerin koordinatlarının ortalamasıdır; böylece metinler kelimelerle aynı boyutlu olur. Beş haber sınıfında (ekonomi, magazin, sağlık, politika, spor) ilk iki boyutta bile ayrışma görülür. Yöntem dilden bağımsızdır.
  - Sorun: bu yöntemler (ve word2vec, FastText) her kelimeye sabit bir koordinat verir. Çok anlamlı (eş sesli) kelimelerin koordinatı anlamlarının ortasına düşer. Çözüm ileride bağlam farkında modellerle görülecektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Test kümesinin eğitim kümesinde de bulunması
  - Webden toplanan derlemlerde tekrarlı içerik çok fazladır. Test kümesi eğitimde de varsa sonuçlar şüphe uyandıracak kadar iyi çıkar. Hoca bunun kendi ekiplerinin başına daha önce çok geldiğini söyledi; derlem ve test kümesi oluştururken buna çok dikkat edilmelidir.
- Bigram ve trigram ile üretilen metinler cümle değildir
  - Ardışık ikili ya da üçlüler anlamlı olabilir, ama cümle bütün parçalarının birbirine bağlı olduğu bir birlikteliktir. Üretilmiş bir metne bakıp hangi ardışık grupların anlamlı olduğunu inceleyerek modelin $k$ değeri tahmin edilebilir.
- Yöntemlerin tarihsel akışı
  - Hoca, bugünkü yöntemlere gelinceye kadar hangi problemin nasıl çözülmeye çalışıldığını, neyin kapatılıp neyin kapatılamadığını anlamanın önemli olduğunu vurguladı; yeni yöntemler öncekilerin eksiklikleri üzerine kurulur.
- Sınıf bilgisi kullanılmadan ayrışma
  - LSI, MDS ve metin koordinatları örneklerinde renkler ve işaretler koordinatlar bulunduktan sonra eklenmiştir. Sistem hiçbir sınıf bilgisi almadığı hâlde kavramlar ve metinler sınıflarına göre ayrışır.
- Anlamsal yakınlığın türü
  - Birlikte geçme ya da yer değiştirme ile bulunan çiftler anlamca yakındır, ama aralarındaki ilişki (eş anlam, zıt anlam, kardeş kavram) aynı değildir.

## Kısa Tekrar Notları

- 20 kelimeden cümle kurmak: $20!$ sıralama denenemez; probleme uygun varsayımlarla arama uzayı daraltılır.
- Dil modeli değerlendirme: harici (başka görevlerdeki performans) ve dahili (test cümlelerine verilen olasılık, cümle sonu tahmini).
- Test kümesi eğitimde de varsa model kopya çeker; webde tekrarlı veri çoktur.
- Metin üretimi: önceki tahmin girdiye eklenir. Hep en olasıyı seçmek tekrar üretir; en olası $t$ taneden rastgele ya da olasılıklara göre örnekleme yapılır.
- $t$ küçükse kopya, $t$ büyükse anlamsızlık artar.
- Bigram: ikililer anlamlı, üçlüler değil. Trigram: üçlüler anlamlı, cümle yok.
- Aynı dokümanda geçme: stop word'ler atılmalı; sonuç anahtar kelimelere ve anlamca benzer kelimelere benzer.
- Edit distance karakter benzerliğidir; "Cimbom-Galatasaray" anlam benzerliğini yakalayamaz.
- LSI = terim-doküman matrisine SVD: $A=U\Sigma V^T$, ilk $k$ tekil değerle boyut indirgeme; gözetimsiz.
- LDA: konular kelimelerin, dokümanlar konuların karışımı.
- WordNet: synset'ler arası ilişkiler. Leacock & Chodorow: en kısa yol; Wu & Palmer: $2N_3/(N_1+N_2+2N_3)$.
- Jiang-Conrath ve Lin: $p(c)=freq(c)/freq(root)$; $A=2\log p(lcs)$, $B=\log p(c_1)+\log p(c_2)$; JC $A-B$, Lin $A/B$.
- Birbiri yerine kullanılan kelimeler aynı bağlamda geçer; ilişki türleri farklıdır.
- Harris: birlikte kullanılan kavramlar anlamca benzerdir. Birlikte geçme matrisi + MDS ile kelime koordinatları.
- Metin koordinatı = kelime koordinatlarının ortalaması.
- Sabit koordinatlı yöntemler çok anlamlı kelimelerde sorun yaşar.

## Detaylı Açıklamalar

- Dersin başında geçen haftanın sorusu tartışıldı: karıştırılmış 20 kelimeden bir dil modeliyle anlamlı cümle nasıl kurulur? Üç kelimede bütün $3!$ sıralamayı log olasılığıyla puanlamak mümkündü, ama $20!$ sıralamada bu yapılamaz. Öğrencilerin önerileri ortak bir fikre dayanıyordu: arama uzayını daraltmak. Cümle başında en sık geçen kelimeyle başlayıp her adımda en olası devamı seçmek $k=1$'lik bir açgözlü aramadır. Cümle başı sembolünden sonra en olası 100 bigram içinde eldeki kelimelerden birini aramak ve bulunamazsa listeyi genişletmek de benzer bir aramadır. Kelime türlerine ya da bağlaçlara göre önce yapı kurmak da bir varsayımdır. Hoca, varsayımların probleme uygunluğu ölçüsünde hem hızlandırdığını hem de doğru sonuca ulaşma olasılığını artırdığını, ama doğru varsayımları bulmanın kafa yormayı gerektirdiğini söyledi.
- İki dil modelini karşılaştırmanın iki yolu vardır. Harici yöntemde dil modeli bir temsil olarak başka bir uygulamada (makine çevirisi, yazım düzeltme, konuşmadan metne) kullanılır ve o uygulamadaki başarıya bakılır. Dahili yöntemde ise derlem eğitim ve test kümesine ayrılır. Dil modeli temelde bir cümlenin olasılığını bulduğu için, test kümesindeki gerçek cümlelere daha yüksek olasılık veren model daha iyidir. Gerçek olmayan, örneğin iki cümlenin başı ve sonu birleştirilerek üretilmiş cümlelere de düşük olasılık vermesi gerekir. Cümle sonunu tahmin etmek de aynı mekanizmayla çalışır: bir diziden sonra gelecek kelime, sözlük boyutunda bir olasılık dağılımıdır (40 bin kelimelik sözlükte 40 bin olasılık).
- Büyük ve webden toplanmış bir derlemde iyi bir test kümesi seçmek zordur. Rastgele bir parça seçmek, aynı içeriğin eğitim kümesinde de bulunması riskini taşır, çünkü web tekrarlarla doludur. Klasik 10 katlı çapraz geçerleme ise büyük metin derlemlerinde her eğitim çok uzun sürdüğü için pratik değildir.
- İstatistiksel dil modeliyle metin üretiminde model kendi tahminini girdisine ekleyerek ilerler. Her adımda en yüksek olasılıklı kelimeyi seçmek $k=0$'da hep aynı kelimeyi, $k=1$'de bir kelimeden sonra hep aynı kelimeyi üretir. Bu yüzden ya en olası $t$ kelimeden biri rastgele seçilir ya da bütün sözlük üzerinden olasılıklarla orantılı seçim yapılır. Ders sitesindeki kodla 1000 ekonomi haberinden kurulan bigram modeli, ardışık ikilileri anlamlı ama üçlüleri anlamsız metinler üretti; trigram modeli üçlüleri anlamlı ama cümle bütünlüğü olmayan metinler üretti. Ardışıklık yerine aynı dokümanda birlikte geçme kullanılınca üretilen dizi cümleden çok bir anahtar kelime listesine benzedi; buna karşılık "faiz"e en benzer kelimeler (merkez, kredi, bankası, oranı, cari) anlamca makuldü. Bu gözlem, kelime benzerliği konusuna geçişi sağladı.
- LSI'da terim-doküman matrisi SVD ile üç çarpana ayrılır ve yalnız en büyük $k$ tekil değer tutulur. Böylece kelimeler ve dokümanlar on binlerce boyutlu seyrek bir uzaydan birkaç on boyutlu yoğun bir uzaya taşınır. Kedi/köpek örneğinde 9 kelime ve 8 doküman vardı; 5 boyuta indirgeme sonrası kedi dokümanları (1-4) ile köpek dokümanları (5-8) sınıf bilgisi verilmeden ayrıştı. LDA ise doküman-konu-kelime şeklinde üç katmanlı bir yapı kurar.
- Kavramsal ağaç (WordNet) tabanlı yöntemler iki kavram arasındaki yolu ve en yakın ortak üst kavramın derinliğini kullanır. Jiang-Conrath ve Lin, bunlara derlemden hesaplanan kavram olasılıklarını ekler; bir kavramın frekansına alt kavramlarının frekansları da dahildir. Küçük bir veri kümesinde (38 İngilizce kelime çifti) insan yargılarıyla korelasyonları birbirine yakın, 0.7-0.83 arasındadır.
- Birlikte geçme matrisi yaklaşımında arama motoru sonuç sayıları ya da kendi derlemimizdeki ortak doküman sayıları bir benzerlik matrisi verir. Bu matris uzaklığa çevrilip MDS'e verilince kelimelerin koordinatları elde edilir. Metinlerin koordinatı, kelimelerinin koordinatlarının ortalaması alınarak bulunur ve metin sınıflandırmada kullanılabilir. Bütün bu yöntemler (ve word2vec, FastText) bir kelimeye tek bir koordinat verdiğinden çok anlamlı kelimelerde sorun çıkar; bu sorun bağlam farkında modellerle çözülecektir.

<!-- BELİRSİZ: 02:11:49 civarında haber sınıflandırma çalışmasının sayıları ("5 haber sınıfında 230'lar tane terim", "4500 kavram", "ilk 100 boyut ve ilk 10 boyut") altyazıda bozuk; hedefli karede yalnız grafik okundu. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
