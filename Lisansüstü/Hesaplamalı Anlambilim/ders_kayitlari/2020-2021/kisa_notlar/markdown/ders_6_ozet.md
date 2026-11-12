# Ders 6 Çalışma Özeti

## Genel Konular

- Ödev sunumları: farklı derlemlerle eğitilen kelime vektörlerinin bir uygulamada karşılaştırılması
  - Sunumların çoğu Türkçe duygu analizi (e-ticaret yorumları, Twitter, film yorumları) üzerineydi; biri metin üretimi (text generation), biri de kelime benzerliği tabanlı bir öneri sistemi denemesiydi. Kullanılan yöntemler word2vec, FastText, GloVe, Doc2Vec ve BERT'ti.
  - Ödevin asıl sorusu (hocanın açıklaması): etiketsiz büyük derlemle vektörleri sıfırdan eğitmek, sonra küçük etiketli veri kümesiyle uygulamayı kurmak ve farklı derlem seçiminin sonuca etkisini görmek. Hazır (önceden eğitilmiş) vektörleri ya da hazır BERT modellerini kullanmak bu sorunun cevabını vermez.
  - Bir grubun sonuç tablosu (ekrandan, 00:13:26): BERT %90 / %91, FastText %89 / %93, word2vec + karar ağacı %86 / %82, word2vec + Naive Bayes %14 / %80 (Dataset1 / Dataset2). Grup, düşük Naive Bayes sonucunun büyük olasılıkla bir hatadan kaynaklandığını söyledi.
  - Bir başka çalışmada (ekrandan, 00:44:38) cümle vektörü kelime vektörlerinin aritmetik ortalaması alınarak 3 katmanlı bir yapay sinir ağına verildi. 42 bin haber derlemiyle: FastText %71.5, word2vec %66.4, GloVe %65.4; yorum (comments) derlemiyle: FastText %70.4, GloVe %66.3, word2vec %64.8 (vektör boyutu 100). Büyük ve konu dışı haber derlemi, küçük ve konuyla ilgili yorum derleminden biraz daha iyi sonuç verdi. FastText'in üstünlüğü sözlük dışı kelime (OOV) sorununu alt parçalarla çözmesine bağlandı.
  - Bir başka grubun tablosu (ekrandan, 01:09:15): Comments veri kümesinde FastText %90, word2vec %62, Word Embedding Layer %48 doğruluk; Movie Comments'te sırasıyla %78, %79, %74.
  - Hiperparametre denemelerinde genel gözlemler: pencere (window) ve vektör boyutu arttıkça word2vec/Doc2Vec başarısı çoğunlukla arttı; FastText'te karakter n-gram aralığı (minn, maxn) de etkiliydi; FastText eğitimi uzun sürdü ama kazanç birkaç puanla sınırlı kaldı.
  - Metin üretimi çalışmasında (ekrandan, 01:20:00) FastText'in yakın kelimeleri "Yunanistan" için Macaristan, Özbekistan, Ermenistan gibi "-istan" ile biten kelimelerdi; alt parça benzerliğinin etkisi görüldü.
- Hocanın sunumlar sırasında yaptığı kavramsal düzeltmeler
  - Derlem ile veri kümesi farklıdır. Derlem genelde etiketsizdir; sistem önce derlemle önceden eğitilir (pretrain), sonra etiketli veri kümesiyle ince ayar (fine-tune) yapılır.
  - Derlemdeki yanlış etiketli örnekleri silmeye ya da derlemi dengelemek için küçültmeye gerek yoktur; derlemde etiket zaten kullanılmaz.
  - Test kümesindeki örnekler, etiketsiz bile olsa, derleme konmamalıdır. Gerçekte test zamanında derlemde hiç görülmemiş kelimeler (unknown) gelir.
  - CountVectorizer ve TF-IDF temsilleri anlamsal uzay değildir.
  - Her temsil için tek bir "en iyi" sınıflandırıcı değil, denenen bütün sınıflandırıcıların sonuçları raporlanmalıdır; aksi hâlde sonuç yorumlanamaz.
  - Önceden öğrenilmiş kelime vektörleri, bir Embedding katmanına başlangıç (initial) değeri olarak verilebilir.
  - Hangi modelin daha iyi olduğu ancak sayısal bir değerlendirmeyle söylenebilir; yalnız yakın kelimelere gözle bakmak yetmez.
- Makine öğrenmesinde yeni problemler (slayt "İçerik", ekrandan, 01:31:50)
  - Konu listesi: aktif öğrenme, yarı eğiticili öğrenme, öğrenmenin transferi, çok görevli eğitim, aktif örnekleme, insan ve makine işbirliği (human in loop), az sayıda örnekle eğitim (zero/one shot), veri zenginleştirme, ML algoritmalarını kandırmak (adversarial attacks), planlı öğrenme (curriculum), hayat boyu öğrenme. Bu derste ilk üçü işlendi.
- Aktif öğrenme (Active Learning) (ekrandan, 01:32:05)
  - Tanım: eğitim örneklerinin etiketleri başta belli değildir; algoritma etiketini istediği örnekleri kendisi seçer. Amaç veri etiketleme maliyetini azaltmaktır.
  - Yöntem: tüm eğitim seti yerine bir kısmını kullanarak, belirli bir test seti üzerinde tümünü kullanmaya göre benzer, kabul edilebilir derecede düşük ya da daha yüksek başarı elde etmek.
  - Etiketleme maliyeti örneği: duygu analizinde etiketleme ucuzdur; ilaç ya da aşı tasarımında bir molekülün insanda yan etki oluşturup oluşturmadığını öğrenmek tek bir örnek için binlerce dolara mal olabilir.
  - Adımlar (ekrandan, 01:40:00): A: küçük bir eğitim setiyle (E) başla. B: bir model üret, etiketsiz eğitim örneklerine (EE) dair tahminler üret. C: tahmin varyasyonuna göre bir kısmını seç, etiketlerini iste (EE'den çıkar, E'ye ekle). B ve C'yi tekrar et.
  - Örnek akış: 1000 etiketsiz örnekten rastgele 10'u etiketlenir, model eğitilir, kalan 990'ı tahmin edilir, en belirsiz 10 tanesi seçilip etiketlenir; 20 örnekle yeni model, 980 tahmin, böyle devam.
  - Sınıflandırmada tahmin varyasyonu softmax çıkışındaki sınıf olasılıklarından ölçülür (varyasyon, entropi vb.). Karar ağacında örneğin düştüğü yapraktaki eğitim örneklerinin sınıf dağılımı kullanılabilir. Regresyonda aynı örnek için birden çok tahmin üretilir (farklı epoch, başlangıç, mimari ya da algoritma) ve varyansına bakılır.
  - Varyasyonu çok olan, yani tahmin edilmesi zor örnekler seçilmelidir. Durma: önceden belirlenen etiketli örnek sayısına (bütçeye) ulaşınca.
  - `active_learning.m` deneyleri (ekrandan, 01:50:00 ve 01:51:05): segment, vehicle, autos, iris, hillValley, audiology veri kümelerinde 20 adım. "Önce kolay örnekler" seçimi rastgeleden iyi değildi (segment'te açıkça kötü). "Önce zor örnekler" bazı veri kümelerinde (segment, audiology) rastgeleden hızlı yükseldi; iris'te verinin yaklaşık %30'u tüm verinin başarısına yetti, ama rastgele seçim de aynı yere ulaştı. audiology'de önce zor seçimi ara adımlarda tüm verinin başarısını da geçti.
- Yarı eğiticili öğrenme (Semi-supervised Learning) (ekrandan, 02:00:00)
  - Modelin oluşturulmasında etiketli verilerin yanında etiketsiz veriler de kullanılır. Örn. 1000 etiketli, 100.000 etiketsiz örnek: etiketsizler test başarısını artırabilir mi?
  - Slayttaki şekil: yalnız iki etiketli noktayla düz bir ayırıcı çizilir; etiketsiz (gri) noktalar da hesaba katılınca ayırıcı, veri yığınlarının arasından kıvrılarak geçer.
  - Etiketsiz örneklere tahmini sınıf atanır (ör. k-NN; ama 1-NN tek seferde uygulanırsa ayırıcı düz çizgiden farksız kalır). Tahminler tek seferde (batch) ya da iteratif yapılabilir; iteratifte önce etiketli noktalara en yakınlar etiketlenir, sonra onlara yakın olanlar.
  - `semi_supervised_learning.m` deneyleri (ekrandan, 02:04:30 ve 02:10:00): supervised (hocanın tarifiyle verilerin hepsi etiketliymiş gibi eğitilen model), batch ve iteratif yarı eğiticili çizgileri karşılaştırıldı. autos ve audiology'de iteratif yöntem supervised'ı geçti; segment ve iris'te iterasyonlar ilerledikçe başarı düştü. Tahminlerden tahmin üretmek hataları biriktirir; tek tek iterasyonlar arasında büyük salınımlar vardır.
  - Sonuç: genel bir kural söylemek zor. Çok iterasyona gitmemek, emin olunan tahminleri kullanmak ve sonuçlardan emin olmak için çok sayıda model eğitmek gerekir.
- Öğrenmenin transferi (Transfer Learning) (ekrandan, 02:12:40)
  - Bir problemi çözdükten sonra benzer başka bir problemi sıfırdan çözmek yerine önceki verileri, modelleri, parametreleri (gerekiyorsa dönüştürerek) kullanmak. Amaç daha az maliyetli ya da daha iyi çözüm.
  - Transfer edilebilenler: veriler, eğitilmiş modelin tamamı, metinler için kelime vektörleri, resimler için CNN filtreleri.
  - Kendi kendine eğiticili (self-supervised) önceden eğitim: girdi ve çıktılar insan etiketlemesi olmadan veriden üretilir. Örnekler: metinde sonraki kelimeyi tahmin etmek, cümlede kapatılan kelimeleri tahmin etmek, resimde kapatılan bölgeyi tahmin etmek, 16 parçaya bölünüp karıştırılan resmi düzeltmek. Büyük görüntü ve metin önceden eğitilmiş modelleri bu yolla eğitilir.
  - Ne zaman işe yarar (ekrandan, 02:17:10): yeni problem için yeterli veri yoksa ve eski ile yeni problem ilgiliyse. Kedi/köpek sınıflandırıcısını kadın/erkek tanımaya aktarmak pek anlamlı değildir; görevden bağımsız self-supervised ağırlıklar ise geneldir ve ilgisiz NLP uygulamalarında da başarılıdır.
  - Slayttaki grafik (ekrandan, 02:17:10): x ekseni görev ilgisi (task relatedness), y ekseni transfer başarısı. "Aggressive" (çok fazla bilgi transferi) çizgisi ilgi arttıkça daha çok kazandırır, ilgi düşükse sıfırın altına iner; "safe" çizgisi daha az eğimlidir. Slayta göre benzer bir karakteristik yarı eğiticili öğrenme için de söylenebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Derlem ile veri kümesi ayrımı
  - Derlem etiketsiz, büyük metin topluluğudur ve önceden eğitimde kullanılır; etiketli veri kümesi ince ayar ve test içindir. Ödevde amaç hazır vektör kullanmak değil, farklı derlemlerle vektör eğitmenin etkisini ölçmekti.
- Test örnekleri derleme girmemeli
  - Etiketsiz bile olsa test örnekleri derlemde olursa sistem gerçekte karşılaşacağı bilinmeyen kelime sorununu yaşamaz, sonuç iyimser çıkar.
- Aktif öğrenmede seçim ölçütü
  - Tahmin edilmesi zor (sınıf olasılıkları birbirine yakın, tahmin varyansı yüksek) örneklerin etiketi istenir. Aktif yöntem rastgele seçimden daha hızlı yükselmiyorsa bir anlamı yoktur; rastgele seçim kabaca doğrusal yükselir.
- Gerçek dünyada tüm veriyle ulaşılacak başarı bilinmez
  - Akademik deneylerde tüm eğitim kümesi bilindiği için bu üst sınır görülebilir; gerçek uygulamada bütçe biter ya da başarı yeterli görülünce durulur.
- Yarı eğiticili öğrenmede tahminlerden tahmin üretmenin riski
  - Çok iterasyon tahmin hatalarını biriktirir; sonuçlar kararsızdır, tek bir denemeye bakarak karar vermek yanıltıcı olabilir.
- Self-supervised önceden eğitimin önemi
  - Görevden bağımsız olduğu için transferin "ilgili problem" koşuluna takılmaz ve günümüzün önceden eğitilmiş modellerinin temelidir.

## Kısa Tekrar Notları

- Derlem etiketsizdir: önce pretrain, sonra etiketli veriyle fine-tune.
- Test örneklerini derleme koyma; derlemde etiket temizliği ya da dengeleme gerekmez.
- CountVectorizer ve TF-IDF anlamsal uzay değildir.
- Ödev sunumlarında FastText genelde en iyi sonuçlardan birini verdi; nedeni alt parça (n-gram) ile OOV sorununu çözmesi.
- Aktif öğrenme: algoritma etiketini istediği örneği seçer; amaç etiketleme maliyetini düşürmek.
- Adımlar: küçük E ile başla, model üret, EE'yi tahmin et, varyasyonu yüksekleri etiketlet, tekrarla.
- Softmax örneği: (0.6, 0.3, 0.1), (0.05, 0.9, 0.05), (0.3, 0.3, 0.4); etiketi istenecek olan (0.3, 0.3, 0.4).
- Regresyonda belirsizlik: aynı örneğe birden çok model tahmini, varyans.
- Önce kolay örnek seçmek işe yaramadı; önce zor seçmek bazı veri kümelerinde rastgeleden hızlı yükseldi.
- Yarı eğiticili öğrenme: etiketsizlere tahmini etiket ver, batch ya da iteratif; iteratif dalgalanır, çok iterasyon zararlı olabilir.
- Transfer: veri, model, kelime vektörü, CNN filtresi taşınabilir; yeterli veri yoksa ve problemler ilgiliyse işe yarar.
- Self-supervised: sonraki kelime, maskeli kelime, kapatılan resim bölgesi, karıştırılmış resim parçaları.

## Detaylı Açıklamalar

- Ödev sunumlarından çıkan dersler
  - Ödevin kurgusu şuydu: elde etiketsiz büyük bir derlem (ör. 1 milyon yorum) ve küçük bir etiketli veri kümesi (ör. 10 bin pozitif, 10 bin negatif) vardır. Kelime vektörleri derlemle sıfırdan eğitilir, sonra etiketli kümeyle sınıflandırıcı kurulup test başarısı ölçülür. Derlem değiştirildiğinde (ör. duygu analizi için yorum yerine haber metinleri) sonucun nasıl değiştiği görülür. Hoca, duygu analizi için yorum derleminin haber derleminden büyük olasılıkla daha iyi olacağını bekliyordu; ancak bir çalışmada büyük ve konu dışı haber derlemi biraz daha iyi çıktı.
  - BERT'in boş hâli yalnız bir mimaridir; büyük derlemlerle eğitilip her dil için yayımlanır (Türkçe için BERTurk gibi). Hazır bir BERT'i alıp etiketli veriyle ince ayar yapmak ödevin istediği "derlemle eğitme" adımını atlamak demektir. FastText için de 150 kadar dil için hazır vektörler vardır; ödev bunları kullanmak değil, kendi derlemle eğitmekti.
  - FastText kütüphanesinin denetimli (supervised) modu etiketli dosyayla doğrudan sınıflandırıcı eğitir; bir öğrenci, bu modun kelime vektörlerinin ortalamasını alarak sınıf seçtiğini aktardı. Hoca, sınıflandırıcının ne yaptığını bilmenin ve her yöntemin bütün sınıflandırıcı sonuçlarını raporlamanın önemini vurguladı.
  - Metin üretimi çalışmasında eğitim verisi, metni sabit uzunlukta parçalara bölüp son kelimeyi etiket, öncekileri girdi yaparak kuruldu. Parça uzunluğu 10 seçilince üretilen cümleler ilgisiz çıktı; hoca, daha kısa (ör. 3) pencerenin çok daha fazla eğitim örneği üreteceğini belirtti.
- Aktif öğrenmede tahmin varyasyonu
  - Softmax çıkışı bir örneğin her sınıfa ait olma olasılıklarını verir. (0.05, 0.9, 0.05) gibi bir örneğin etiketini model zaten iyi tahmin ediyor sayılır; (0.3, 0.3, 0.4) gibi sınıfların neredeyse eş olasılıklı olduğu örnek sınır bölgesindedir ve etiketini öğrenmek modele en çok bilgiyi katar. Örnekler bu belirsizliğe göre sıralanır ve en belirsiz olanlar seçilir.
  - Regresyonda çıkış tek bir sayıdır (ör. 3.42), olasılık dağılımı yoktur. Bir öğrencinin "önceki tahminlerin ortalamasından uzaklık" önerisine hoca, bunun bütün örnekler üzerinden değil aynı örnek için üretilen tahminler üzerinden yapılması gerektiğini söyledi: aynı örneğe farklı epoch, başlangıç ağırlığı, mimari ya da algoritmayla birden çok tahmin üretilir; tahminler çok farklıysa örnek belirsizdir.
  - Deneylerde x ekseni B ve C adımlarının tekrar sayısı (etiketli örnek sayısının artışı), son nokta (20) bütün verinin etiketli olduğu durumdur. İstenen, tüm verinin başarısına rastgele seçimden daha hızlı ulaşmaktır. Bir öğrencinin "önce zor seçildiğinde sonda eklenen kolay örnekler başarıyı neden düşürdü" sorusuna hoca, zorluk ölçüsünün o anki küçük veriyle eğitilmiş modelin tahminlerine dayandığını ve bu tahminlerin kötü olabileceğini söyledi.
- Yarı eğiticili öğrenmede batch ve iteratif tahmin
  - Batch yöntemde etiketsiz örneklerin hepsi bir kerede tahmin edilip eğitime katılır; supervised ve batch sonuçları bu yüzden grafikte düz birer çizgidir. İteratif yöntemde her adımda bir grup etiketsiz örnek tahmin edilip eklenir; sağa gidildikçe eğitim kümesindeki gerçek olmayan (tahmini) etiketlerin oranı artar. Yukarıdan başlayıp aşağı inen eğri, ilk tahminlerin faydalı, sonraki "tahminlerden tahmin"lerin zararlı olduğunu gösterir.
  - Örnek şekilde (ekrandan, 02:04:30) üç sınıflı veride yalnız 10 etiketli örnek (yıldızlar) vardı; batch tahmin bir bölgedeki sınıf sınırını kaydırırken iteratif tahmin bazı noktaları doğru sınıfta tuttu.
- Öğrenmenin transferi ve self-supervised öğrenme
  - Self-supervised yaklaşımlarda insan etiketlemesi gerekmez, ama girdi-çıktı çiftleri veriden üretildiği için eğitim denetimli gibi yürür. Bu sayede çok büyük etiketsiz veriyle önceden eğitim mümkün olur.
  - Sınıflandırma modelini başka bir sınıflandırma problemine aktarmak, iki problem ilgiliyse anlamlıdır. Self-supervised modeller belli bir sınıflandırma görevine bağlı olmadıkları için geneldir ve ilgisiz uygulamalarda da başarılı sonuç verir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
