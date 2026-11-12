# Ders 13 Çalışma Özeti

## Genel Konular

- Görsel anlambilim: metinle birlikte resim işleyen modeller (ekrandan, 00:20:00; slaytlar "bolum7", 21 slayt)
  - Dersin bu bölümünde resim tanımı üretme (image captioning), kısaca video tanımlama, görsel soru cevaplama (VQA) ve üretici modellerin ön eğitiminde kullanılan karşıtsal öğrenme (contrastive learning) anlatıldı.
  - Eski çalışmalar resim için cümle üretmekten çok resimde neler olduğunu yakalamaya çalışır; CNN tabanlıdır ve nesnelerin birlikte bulunma bilgisini kullanır (resimde kaşık varsa yanındaki çatala benzeyen şeklin çatal olma olasılığı artar).
- Resim tanımı üretme bir çeviri problemidir (00:13:19)
  - Resim verilir, model resmin içinde ne olduğunu metin olarak üretir. Bu, bir dilden başka dile değil, bir moddan başka bir moda (resimden metne) çeviridir. Tersi (metinden resim) de mümkündür.
  - Kodlayıcı-çözücü (encoder-decoder) yapısı: kodlayıcı girdiyi insanlar için çok anlamlı olmayan bir gizli uzaya (latent space) taşır, çözücü bu vektörü istenen biçime çevirir. İngilizce-Türkçe çeviri, text-to-text, image-to-text, image-to-image yapılarının hepsi bu mantıktadır.
- Show and Tell (2014) (ekrandan, 00:13:20)
  - Resim → Vision Deep CNN → vektör → Language Generating RNN → "A group of people shopping at an outdoor market." CNN kodlayıcı, RNN çözücüdür; aradaki vektör gizli uzaydaki noktadır.
  - Uçtan uca sistem. Optimizasyon: $\theta^\star = \arg\max_\theta \sum_{(I,S)} \log p(S \mid I; \theta)$. $I$ resim, $S$ resmin doğru tanımı, $\theta$ CNN ile RNN'in birlikte bütün parametreleri.
  - $N$ uzunluğundaki bir tanımın olasılığı: $\log p(S \mid I) = \sum_{t=0}^{N} \log p(S_t \mid I, S_0, \ldots, S_{t-1})$. Bu tam bir otoregresif modeldir: o ana kadarki kelimeler verilip bir sonraki tahmin edilir (next token prediction).
  - Slaytta RNN yazıp şekilde LSTM olmasının nedeni: her LSTM ve GRU aslında bir RNN'dir.
  - Ayrıntılar (ekrandan, 00:21:00): CNN çıkışı LSTM'e giriş olur; CNN parametreleri önceden eğitilmiş (pre-trained) değerlerle başlar; $S_x$ one-hot vektördür; $W_e$ kelime gömme katmanıdır (word embedding layer); 512 LSTM hücresi vardır.
  - Kodlayıcı ve çözücü bugün Transformer bloklarına dönüşmüştür, ama kodlayıcı-çözücü yapısı değişmemiştir.
- Önceden eğitilmiş model neden kullanılır (00:21:03)
  - Derin ağlar katman katman örüntü, örüntülerin örüntüsü vb. öğrenir. Alt katmanlardaki örüntüler (köşe, kırılma noktası, parlak ve koyu bölgeler) problemden bağımsızdır (domain, dataset, task agnostic). Üst katmanlar probleme özeldir.
  - Çok büyük veriyle öğrenildikleri için alt katmanlar gürbüzdür (robust).
  - Büyük bir modeli az veriyle eğitirseniz girdideki küçük değişiklik çıktıda büyük değişikliğe yol açar; bu, modelin varyansının yüksek olması demektir. Veri arttıkça varyans azalır. Çok veri yoksa önceden eğitilmiş model kullanmak mantıklıdır.
  - Daha küçük, sığ bir mimari daha somuta yakın, daha az soyut örüntülerle çalışmak demektir.
- Tanım üretimi: örnekleme ve ışın araması (ekrandan, 00:27:10)
  - Sampling: $p_1$'e göre kelime seç, sonra $p_2$, $p_3$, ...
  - Beam search: o ana kadarki en olası 20 cümleyi tut; $S = \arg\max_{S'} p(S' \mid I)$.
  - Üretilen 20 cümleden en olası olanı seçildiğinde %80'i eğitim kümesindeki cümlelerden. Hocaya göre bu, sistemin yeni resimlere uygun cevap verme yeteneğini sorgulatır; bugün bu yetenek çok ilerlemiştir.
  - Sonuç örneklerinde kabul edilebilir hatalar vardır: üstü yapıştırmalarla dolu bir yer için "buzdolabı", süslü bir araç için "Yellow School Bus".
- Video tanımlama (ekrandan, 00:30:00)
  - Yine çeviri sistemi tabanlıdır: 2D filtrelerle resimlerden, 3D filtrelerle video küplerinden (resimlerin arkaya doğru dizili hali) özellik çıkarılır; image MIL ve video MIL modelleri, bir "Transfer Unit" ve LSTM'lerle cümle ("a boy is cleaning the floor") üretilir.
  - Video anlamak resim anlamaktan zordur: çıkış uzayı çok daha büyüktür, zaman bilgisi ve niyetleri okumak işin içine girer, daha soyut örüntüler gerekir.
- Görsel soru cevaplama (VQA) (ekrandan, 00:33:30)
  - Bir resim hakkında soru sorulur ve sistem cevap verir. Slaytta yeşil cevaplar resmi görerek, maviler resmi görmeden (aynı eğitilmiş modele boş resim verilerek) verilmiştir.
  - Mantıklı bir model için gördüğü ve görmediği durumdaki cevapların farklı olması beklenir. Bazı örneklerde öyledir, bazılarında değildir. Hoca bunu bAbI'de soruyu görmeden cevap üretmeye benzetti.
- Veri kümesi oluşturmanın zorluğu ve kısa yol öğrenme (00:34:46)
  - İnsanlara soru ve cevap ürettirmek kolaydır ama ne ürettiklerini yönetmek ve gözlemlemek zordur.
  - Bir girdi-çıktı ikilisini hangi kişinin ürettiği tanınabiliyorsa sistem problemi çözmek yerine kişiyi tanımaya odaklanabilir. Bu, istemediğimiz türden kısa yol öğrenmedir (shortcut learning); gerçek dünyadaki başarıyı düşürür ve önceden kestirmek kolay değildir.
- Eleştiriler (ekrandan, 00:40:00)
  - VQA veri kümesinde "What sport is" ile başlayan soruların %41'inin cevabı "tenis", "How many" ile başlayanların %39'unun cevabı "2"dir. "Bu resimde balık var mı?" sorusu ancak resimde balık varsa sorulur; "Bu resimde X var mı?" sorularının %81'inin cevabı "evet"tir.
  - Bunlar yanlılıktır (bias): resme bakmadan bile tutturma olasılığı yüksektir ve makineler bunu kolayca yakalar.
- Veri kümesinde güncelleme (ekrandan, 00:38:55)
  - Amaçlar: soru-cevap düzenliliklerini ortadan kaldırmak, resme bakmadan doğru cevap verebilmeyi önlemek, sistemlerin başarısının abartılmasını önlemek.
  - Çözüm: aynı sorunun farklı resimler için farklı cevaplarının olduğu bir benchmark ("Who is wearing glasses? man / woman", "How many children are in the bed? 2 / 1").
  - Slayttaki soru: "Yeterli mi? Başka ne yapılabilir?" Hoca, veri toplamanın doğası gereği tekdüze (uniform) olmadığını söyledi: insanlar rastgele resim çekmez, rastgele yazı yazmaz; karşıdakinin ilgisini çekecek şeyi gösterir.
- İnternet verisinin yanlılığı (00:40:56)
  - Örnek: arama motorunda "güldü" ve "öldürdü" için çıkan sonuç sayılarına bakılırsa insanların gülmekten çok öldürdüğü sonucu çıkar. İnternet verisi hayatın doğal akışıyla uyumlu değildir; yalnızca kolay erişilebildiği için kullanılır.
- Karşıtsal öğrenme (contrastive learning) (ekrandan, 00:42:20)
  - Önceden eğitilmiş mimari oluşturmakta kullanılan bir yaklaşımdır ve öz denetimlidir (self-supervised): insan eliyle etiketleme yapılmaz.
  - Slayt: iki girdi için benzer ya da değil diyebilmek; benzer olanlar için benzer, farklı olanlar için farklı çıktılar üretmek. Eğitim kümesini oluşturmada eğiticili ve eğiticisiz yöntemler vardır. Eğiticili örnek: farklı 2 kedi resmi benzesin, 1 kedi ve 1 balık benzemesin.
  - Etiket gerekmediği için hem etiketleme hatası önlenir hem de çok büyük veri kümesi üretilebilir (ölçeklenebilirlik).
- SimCLR (00:51:15)
  - Bir resimden rastgele kesilen parçaların (crop) birbirine benzer, farklı resimlerden kesilenlerin benzemez olduğunu öğrenmek. Modelin yaptığı, iki parçanın aynı resimden gelip gelmediğini tahmin etmektir.
  - Parçalara renk değişimi, filtre gibi dönüşümler uygulanır. Hoca makalede hangi dönüşümün anlamlı olduğunu bulmak için çok zaman harcandığını ve her dönüşümün işe yaramadığını söyledi.
  - Parçalar ağırlıkları ortak (eş, ikiz) CNN'lere verilir; çıkan vektörler iki tam bağlantılı katmandan (MLP) geçer; MLP çıktıları arasında "bu buna benzemeli, bu bundan uzak olmalı" geri beslemesiyle sistem güncellenir.
  - Sonunda elde sınıflandırıcı yoktur; CNN ve MLP sonraki görevler için önceden eğitilmiş model olarak kullanılır ve ince ayar (fine-tuning) yapılır.
  - Metinler için de benzer çalışmalar vardır (iki metin verilir).
  - Resimde tek ana nesne varsa fikir iyidir. Birden çok nesne varsa (bir yanda kedi, bir yanda köpek) kedinin kafasıyla köpeğin kuyruğu benzer sayılır; bu içerik benzerliği değil ama birlikte bulunma (co-occurrence) bilgisi olarak yine ağa aktarılır.
- Resimleri anlamanın sınırları ve mizah (00:57:41)
  - Belli resimlerde ne olduğunu makineye söyletmek mümkündür, ama yeni bir resimde (test zamanında) aynı başarının olup olmayacağı hâlâ soru işaretidir.
  - Mizah zekânın en sağlam göstergelerinden biridir. Hocanın spekülatif görüşü: yeni şeyler sabit temel öğelerin yeni birleşimlerinden ibaretse makinenin anlama ihtimali vardır, ama girdinin katman katman tek seferde işlendiği tekdüze mimarilerle değil; belli noktalarda döngüsel bir yapıya ihtiyaç olabilir.
- Öğrenci sorusu: farklı modeller benzer cevap veriyor (01:00:44)
  - Bir öğrenci aynı soruyu ChatGPT'ye ve LLaMA ağırlıklarını kullanan Vicuna'ya sorduğunda benzer cevaplar aldığını söyledi. Hoca, insanların sorabileceği soruların çeşitliliğinin mevcut veri kümeleriyle büyük ölçüde açıklanabildiğini, yepyeni durumlarda ne olacağını zamanın göstereceğini söyledi.
- Ödev 3 sunumları: üç anahtar kelimeden cümle üretimi (01:15:22 sonrası)
  - Görev: verilen üç anahtar kelimeyi içeren anlamlı bir cümle üretmek ve yöntemleri en az 50 kelime üçlüsü üzerinde insan yargısıyla karşılaştırmak (01:19:32).
  - Denenen yöntemler: FLAN-T5 ve mT5 ince ayarı (girdi anahtar kelimeler, çıktı cümle), anahtar kelimeleri bir BERT tabanlı anahtar kelime çıkarıcıyla otomatik üretme, LSTM, kelime ve n-gram tabanlı Markov zincirleri (2, 3, 5-gram; ileri ve geri yönlü matrislerin ortak kelimede birleştirilmesi), kısıtlı ışın araması (constrained beam search) ile anahtar kelimeleri zorla yerleştirme, BERT ile maske doldurma, Word2Vec yakınlığıyla token seçimi, GPT-2 ince ayarı, Keytotext kütüphanesi, kurallı (özne-nesne-yüklem) cümle türetme.
  - Genel gözlemler: Transformer tabanlı modeller (FLAN-T5, BERT maske doldurma) LSTM ve Markov'a göre daha anlamlı cümle üretti; LSTM'in başarısı eğitildiği derlemin büyüklüğüne ve cümle uzunluklarına bağlı; GPT-2 ince ayarı anahtar kelimeleri cümlenin başına koyup devam ettirdi; kısıtlı ışın aramasında zorlanan kelime çoğu zaman cümlenin sonunda kaldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kodlayıcı-çözücü yapısı bugün de en yaygın yaklaşımdır
  - Resimden metne, metinden metne, resimden resme, hepsi bir moddan başka moda çeviridir. Bloklar RNN'den Transformer'a değişti, yapı değişmedi.
- Büyük model + az veri = yüksek varyans
  - Girdideki küçük değişiklik çıktıda büyük değişikliğe yol açar. Çok veri yoksa önceden eğitilmiş model kullanmak çok makuldür.
- Modeller istediğimizi yapar ama istediğimiz yoldan mı?
  - VQA'daki yanlılıklar ve kişi tanıma gibi kısa yollar (shortcut learning) gerçek dünyada başarıyı düşürür. Bunlar çoğu zaman sistem gerçek zamanlı çalışmaya başladığında ortaya çıkar.
- Veri toplama tekdüze değildir
  - İnsanlar ilgi çekici olanı paylaşır; internet verisi hayatın doğal akışını yansıtmaz ("güldü" ve "öldürdü" örneği).
- Ödev sunumlarındaki yöntemsel uyarılar
  - Karşılaştırma birkaç örnekle değil, en az 50 kelime üçlüsü için sayısal ve insan yargısını içeren bir tabloyla yapılmalıdır (ör. "35'inde FLAN-T5, 15'inde LSTM daha iyi").
  - Word2Vec'te sözlükte olmayan kelimenin vektörü yoktur; FastText alt kelime (subword) parçalarıyla her kelimeye vektör üretebilir.
  - Küçük Türkçe veride saf kelime tabanlı model çok seyrek kalır; BERT tokenizer'ı gibi alt kelime tabanlı bir dönüşüm daha iyi sonuç verebilir.
  - Bir modeli anlatırken eğitimdeki girdi ve çıktının ne olduğu açıkça söylenmelidir.
  - İngilizce eğitilmiş T5-small'u küçük bir Türkçe veriyle ince ayarlamak büyük olasılıkla sıfırdan eğitmekten farklı olmaz.
  - BERT ile maske doldurmada eğitim süreci yoktur; önceden eğitilmiş model doğrudan kullanılır.

## Kısa Tekrar Notları

- Image captioning = resimden metne çeviri; CNN kodlayıcı + RNN/LSTM çözücü; aradaki vektör gizli uzay.
- Show and Tell: $\theta^\star = \arg\max_\theta \sum_{(I,S)} \log p(S\mid I;\theta)$, $\log p(S\mid I) = \sum_t \log p(S_t \mid I, S_0..S_{t-1})$ → otoregresif.
- CNN önceden eğitilmiş; $S$ one-hot; $W_e$ kelime gömme; 512 LSTM hücresi.
- Beam search 20 cümle tutar; en olası cümlelerin %80'i eğitim kümesinden.
- Video tanımlama: 2D filtre resim, 3D filtre video küpü; daha zor (zaman, niyet, soyutluk).
- VQA yanlılıkları: "What sport is" %41 tenis, "How many" %39 "2", "X var mı?" %81 evet.
- Düzeltme: aynı soruya farklı resimlerle farklı cevap veren dengeli veri kümesi.
- Kısa yol öğrenme: model problemi değil kolay ipucunu (kişi, soru kalıbı) öğrenebilir.
- Karşıtsal öğrenme: benzer çiftler yakın, farklılar uzak; öz denetimli, ölçeklenebilir.
- SimCLR: aynı resmin kesilmiş ve dönüştürülmüş parçaları, ağırlığı ortak CNN + 2 katmanlı MLP; sonra ince ayar.
- Ödev 3: Transformer tabanlı yöntemler LSTM/Markov'dan daha anlamlı; değerlendirme insan yargısıyla ve sayısal yapılmalı.

## Detaylı Açıklamalar

- **Resim tanımı üretmenin çeviri olarak görülmesi.** Hoca dersin bu bölümüne "görsel anlambilim" adını verdi; modellerin işlediği içerikte artık metinlerin yanında resimler de vardır. Resim tanımı üretme problemi, girdisi resim, çıktısı metin olan bir çeviri problemidir. Bir kodlayıcı girdiyi gizli uzaydaki bir vektöre çevirir; çözücü bu vektörden istenen moddaki çıktıyı üretir. Show and Tell (2014) bu yapının resimden metne ilk modern örneklerindendir: dönemin popülerliği nedeniyle kodlayıcı olarak CNN, çözücü olarak RNN (LSTM) kullanılmıştır. Eğitimde bütün (resim, tanım) ikilileri üzerinden doğru tanımın log olasılığı en büyüklenir; tanımın olasılığı kelimelerin, kendisinden önceki kelimeler ve resim verildiğindeki koşullu olasılıklarının çarpımıdır. Yani metin tek seferde değil, adım adım üretilir.

- **Önceden eğitilmiş modellerin değeri.** Alt katmanlardaki genel örüntüler çok büyük veriden öğrenildiği için gürbüzdür. Büyük bir modeli küçük bir veriyle sıfırdan eğitmek yüksek varyanslı bir model verir. Daha küçük bir model kullanmak da daha az soyut örüntülerle yetinmek demektir. Bu nedenle soyut örüntülere ihtiyaç varken veri azsa önceden eğitilmiş model çok makul bir seçimdir.

- **VQA ve yanlılık.** VQA'da modelin gerçekten resme baktığını sınamak için aynı modele resim yerine boş resim verilir. Cevaplar değişmiyorsa model resme değil soru kalıbına bakıyordur. Slayttaki istatistikler (tenis %41, "2" %39, "evet" %81) bu kalıpların ne kadar güçlü olduğunu gösterir. Önerilen düzeltme, aynı soru için farklı cevapları olan resim çiftleriyle dengeli bir veri kümesidir; hoca bunun da yeterli olmayabileceğini, çünkü insanların veri üretiminin doğası gereği yanlı olduğunu vurguladı.

- **Karşıtsal öğrenme ve SimCLR.** Etiketsiz resimlerden "aynı resimden mi geldi?" sorusuyla eğitim kümesi kendiliğinden üretilir. Aynı resimden kesilip farklı dönüşümler uygulanmış iki parça, ağırlıkları ortak iki CNN kopyasından ve iki katmanlı MLP'den geçirilir; çıktılar benzer olacak, farklı resimlerin parçalarıyla uzak olacak biçimde güncellenir. Sonuçta elde bir sınıflandırıcı değil, sonraki görevlere ince ayarla uyarlanacak bir ön eğitimli model olur.

- **Ödev 3 sunumlarından akademik içerik.** Sunumlarda üç anahtar kelimeden cümle üretimi için çok farklı yöntemler denendi (ayrıntılar genişletilmiş notta). Ortak bulgu, büyük önceden eğitilmiş Transformer modellerinin (FLAN-T5, BERT maske doldurma) küçük derlemlerle eğitilen LSTM ve Markov modellerinden daha anlamlı cümleler ürettiğidir. Örneğin bir sunumda n-gram (Markov) yöntemi 50 cümlenin 29'unda anlamlı cümle verdi (%58) (ekrandan, 02:40:00). Hoca karşılaştırmaların sayısal ve insan yargısına dayalı olmasını, Türkçede alt kelime tokenizasyonunu ve FastText'i önerdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
