# Ders 12 Çalışma Özeti

## Genel Konular

- Görsel anlambilim ve çok kipli (multimodal) veri
  - Önceki derslerde anlambilim yalnız metin üzerinde görüldü. Bu derste birden fazla kipte (modalite) veri içeren kümeler ele alındı: ses, görüntü, video, metin, veri tabanındaki tablo verisi ayrı kiplerdir.
  - İnsanlar da görsel, işitsel, dokunsal ve koku gibi birçok kipten gelen bilgiyi birleştirerek karar verir. Bu alan, birden fazla kipten aynı anda yararlanmanın tek kipten daha başarılı olacağı varsayımıyla ilerler.
  - Derste "görsel" kısım yalnız resim değil, resim + metin ikilileridir. İçerik (ekrandan, 00:09:40): Resim Tanımı Üretme, Video Tanımlama, Görsel Soru Cevaplama, Karşıtsal Öğrenme.
- Resim tanımı üretme (image captioning): iki yaklaşım (ekrandan, 00:12:15)
  - Birinci yaklaşım (iki aşamalı): resimden CNN vb. dedektörlerle objeleri ve özelliklerini bul, sonra bunlardan dil modeli vb. ile cümle üret.
  - İkinci yaklaşım (uçtan uca): problemi diller arası çeviri gibi ele al. Girdi "görsel dil" (resim), çıktı metindir.
- Every Picture Tells a Story (birinci yaklaşıma örnek, ekrandan 00:13:40)
  - Resimleri ve cümleleri en benzedikleri (obje, eylem, yer) üçlüleriyle ifade eder. Resim uzayı ve cümle uzayı, bir "anlam uzayı" (meaning space) üzerinden eşleştirilir.
  - Hazır listeler üzerinde çalışır; yeni cümle üretmez, hazır cümlelerden resme en uygun olanı seçer.
  - Slayttaki üçlüler: `<bus, park, street>`, `<plane, fly, sky>`, `<ship, sail, sea>`, `<train, move, rail>`, `<bike, ride, grass>`.
  - Yalnız "biri bir yerde bir şey yapıyor" türünden cümleleri seçebildiği için kısıtlıdır, ayrıntılı tanım üretemez.
- BabyTalk (birinci yaklaşıma örnek, ekrandan 00:16:50)
  - (resim, tanım) ikililerine ihtiyaç duymaz; hazır obje, özellik ve konum (edat) listeleri üzerinde çalışır. Deep learning öncesidir: deformable part models + SVM.
  - Adımlar: 1) objeler, 2) özellikler (brown, striped, furry, wooden, feathered), 3) konum ilişkileri (near, against, beside), 4) kurulan CRF, 5) tahmin edilen etiketleme, 6) üretilen cümle.
  - Üretilen cümle (ekrandan): "This is a photograph of one person and one brown sofa and one dog. The person is against the brown sofa. And the dog is near the person, and beside the brown sofa."
  - "Ne nerede, birbirine göre konumu ne" bilgisini çıkarır ve basit gramerli cümleler kurar.
- Show and Tell (ikinci yaklaşım, uçtan uca, ekrandan 00:18:05)
  - Resim bir CNN'e verilir, resmi temsil eden bir vektör üretilir; bu vektör bir RNN'e (LSTM, GRU vb.) verilir ve cümle üretilir.
  - Optimizasyon: $\theta^\star = \arg\max_\theta \sum_{(I,S)} \log p(S \mid I;\theta)$. $I$ resim, $S$ resmin doğru tanımı, $\theta$ model parametreleridir. Hem CNN hem RNN ağırlıkları birlikte optimize edilir.
  - $N$ uzunluğundaki bir tanımın olasılığı: $\log p(S\mid I) = \sum_{t=0}^{N} \log p(S_t \mid I, S_0, \dots, S_{t-1})$.
  - Mimari (ekrandan, 00:19:10): CNN çıkışı LSTM'e girdi olur; CNN parametreleri pre-trained ile başlar (ImageNet vb. üzerinde eğitilmiş modelden transfer learning); $S_t$ one-hot vektör, $W_e$ word embedding katmanı; 512 LSTM hücresi vardır.
  - Tanım üretimi (ekrandan, 00:20:36): sampling (önce $p_1$'e göre kelime seç, sonra $p_2$, $p_3$, ...) ya da beam search (o ana kadarki en olası 20 cümleyi tut, $S = \arg\max_{S'} p(S'\mid I)$). Üretilen 20 cümleden en olası olanı seçildiğinde bunların %80'i eğitim kümesindeki cümlelerdendir.
  - Sonuçlar (ekrandan, 00:21:00) dört gruba ayrılır: tam doğru, küçük hatalı, resimle biraz ilgili, resimle ilgisiz. Başarı eğitim kümesine çok bağlıdır.
- Video tanımlama (ekrandan, 00:21:50)
  - Yine çeviri sistemi tabanlıdır. 2D filtrelerle resimlerden (karelerden), 3D filtrelerle video küplerinden (resimlerin arkaya doğru dizili hâli) özellik çıkarır. Tek resim yerine ardışık birçok resim kullanılır.
- Görsel soru cevaplama (Visual Question Answering, VQA)
  - Metin tabanlı soru cevaplamadaki paragrafın yerini resim alır: resim + soru verilir, cevap bulunur ya da seçilir. Büyük veri kümeleri ve leaderboard'lar vardır.
  - Gerekli kabiliyetler (ekrandan, 00:23:00): nesne tanıma ("How many bikes are there?"), aktivite tanıma ("Is this man crying?"), hayat bilgisi ve çıkarım ("Is this a vegetarian pizza?", "Does this person have 20/20 vision?", "Is this person expecting company?").
  - Yöntem (ekrandan, 00:24:40): en sık K=1000 cevap sınıf alınır (1000 sınıflı problem); sorular bag of words (1030), resimler VGGNet (4096) ile kodlanır; MLP ve LSTM kullanılır; girdi soru, resim ya da soru + resim. Cevap biçimleri: open-answer (üretim) ve multiple-choice (seçim); her birinde Yes/No, Number, Other türleri.
  - Baseline sonucu: resmin katkısı çok azdır. Yalnız soru ile tüm open-answer doğruluğu 48,09, soru + resim ile 52,64'tür.
- VQA veri kümesine eleştiriler ve güncelleme
  - Eleştiriler (ekrandan, 00:27:45): "What sport is" ile başlayan soruların %41'inin cevabı "tenis"; "How many" ile başlayanların %39'unun cevabı "2"; "Bu resimde balık var mı?" sorusu ancak resimde balık varsa sorulur, "Bu resimde X var mı?" sorularının %81'inin cevabı "evet".
  - Güncelleme (VQA v2, ekrandan 00:29:30): aynı sorunun farklı resimler için farklı cevaplarının olduğu bir benchmark kuruldu ("Who is wearing glasses?" man / woman; "Is the umbrella upside down?" yes / no; "How many children are in the bed?" 2 / 1; "Where is the child sitting?" fridge / arms). Amaç: soru-cevap düzenliliklerini kaldırmak, resme bakmadan doğru cevabı önlemek, başarının abartılmasını engellemek.
  - Güncellenmiş kümede sistemlerin başarısı belirgin biçimde düştü.
- Karşıtsal öğrenme (Contrastive Learning, ekrandan 00:31:30)
  - Amaç: iki girdi için "benzer" ya da "değil" diyebilmek. Çözüm: benzerler için benzer, farklılar için farklı çıktı (temsil) üretmek.
  - Eğitim kümesi eğiticili ya da eğiticisiz kurulabilir. Eğiticili: iki farklı kedi resmi benzesin, bir kedi ve bir balık benzemesin; bunun için etiket gerekir.
- SimCLR (ekrandan, 00:32:50)
  - Self-supervised, eğiticisiz; eğitim kümesi üretme yöntemi ölçeklenebilir.
  - Aynı resimden rastgele iki parça kırpılır, renk dönüşümü vb. augmentation uygulanır, CNN + MLP ile temsil çıkarılır. Aynı resmin parçaları birbirine çekilir (attract), farklı resimlerinkiler itilir (repel).
  - Eğitim sonrası pre-trained temsiller, transfer learning ile istenen görevde kullanılır.
  - Tek objeli resimlerde (ImageNet, CIFAR gibi benchmark'lar) iyi çalışır; içinde birden fazla nesne olan resimde (üstte kedi, altta köpek) iki farklı nesneyi "benzer" saymaya zorlar.
  - Resim-metin ikilileri üzerinde bir cevap: OpenAI'ın CLIP çalışması. Yalnız metin üzerinde ise henüz çok iyi sonuç yoktur; cümleler içinde birden fazla nesne olan resimlere benzer.
- Genel değerlendirme (ekrandan, 00:39:05)
  - Son 5 yılda büyük gelişim: nesne tanıyıcıların başarısının artışı, etiketli veri kümelerinin artışı, self-supervised yöntemlerdeki gelişmeler.
  - Dikkat: başarıları ve veri kümelerini iyi incelemek gerekir (arka kapılar).
  - Hâlâ uzun bir yol vardır: tartı şakası ve bomba uzmanı şakası gibi resimleri anlatmak için dünya bilgisi gerekir.
- Proje danışmanlığı: iki boyutlu kelime temsilleri
  - Bir öğrenci, kelimeleri iki boyutlu bir temsile çeviren bir katmanı skip-gram modelinin içine koyarak eğitmeyi anlattı. Hoca, sonraki görevde bu temsilin düzleştirilmeden (flatten edilmeden) CNN ile kullanılmasını önerdi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Self-supervised ile unsupervised farklıdır
  - Self-supervised yöntemde yine etiketli bir öğrenme yapılır, ama etiketleri insan değil sistem/veri kendisi üretir. BERT'te bir kelimeyi kapatıp tahmin ettirmek buna örnektir; veri kümesi kurmak kolaydır, insan etiketlemesi gerekmez.
  - İnsan eliyle etiketleme pahalı ve sorunlu olduğu için bu yaklaşımlar çok önem kazandı.
- Arka kapılar (backdoor) unutulmamalı
  - Makine öğrenmesi sistemine ne yapacağını (girdi-çıktı eşlemesini) söyleriz, nasıl yapacağını söyleyemeyiz. Sistem kısa yol bulabilir.
  - İyi bir VQA veri kümesinde yalnız soru ya da yalnız resim verildiğinde sistem iyi çalışmamalı; ancak ikisi birlikte verildiğinde doğru cevap vermeli.
- Uçtan uca sistemler eğitim kümesine çok bağlıdır
  - Eğitim kümesindeki resimlere benzeyen resimlerde iyi çalışır; ama çok şaşırtıcı, ilgisiz sonuçlar da çıkabilir.
- Karşıtsal öğrenmeyi metne uygulamak zordur
  - Bir cümlenin parçaları farklı şeyler anlatır; bir parçaya bakıp bütün hakkında bir şey söylemek, resimdekinden zordur. Fikir eskidir, uygulaması güçtür.

## Kısa Tekrar Notları

- Kip (modalite): ses, görüntü, video, metin, tablo. Multimodal = birden fazla kip.
- Resim tanımı üretmede iki yaklaşım: (1) obje/özellik bul + cümle üret, (2) uçtan uca çeviri.
- Every Picture Tells a Story: (obje, eylem, yer) üçlüleri, hazır cümle seçer, üretmez.
- BabyTalk: obje + özellik + konum + CRF, şablon cümle; DPM + SVM, deep learning öncesi.
- Show and Tell: CNN (pre-trained) → LSTM; $\theta^\star=\arg\max_\theta\sum\log p(S\mid I;\theta)$; beam search ile en olası 20 cümle.
- Video tanımlama: 2D filtre (kare) + 3D filtre (video küpü).
- VQA: resim + soru → cevap; open-answer (üretim) ve multiple-choice (seçim); nesne tanıma, aktivite tanıma, hayat bilgisi gerekir.
- VQA v1 yanlılıkları: "What sport is" → %41 tenis; "How many" → %39 "2"; "X var mı?" → %81 evet.
- VQA v2: aynı soru, farklı resim, farklı cevap; sistemlerin başarısı düştü.
- Contrastive learning: benzerlere yakın, farklılara uzak temsil.
- SimCLR: aynı resimden iki kırpıntı + augmentation → yakın; farklı resimler → uzak; self-supervised.
- CLIP: karşıtsal öğrenmenin resim-metin ikililerine uygulanması.

## Detaylı Açıklamalar

- Resim tanımı üretmede iki aşamalı ve uçtan uca yaklaşımın farkı
  - İki aşamalı yaklaşımda önce resmin içindeki nesneler, özellikleri ve konumları ayrı bir sistemle çıkarılır; sonra bu ara temsilden cümle kurulur. Every Picture Tells a Story bu ara temsili (obje, eylem, yer) üçlüsü olarak tutar ve hazır cümle havuzundan seçim yapar. BabyTalk ise obje, özellik ve edat olasılıklarını bir CRF ile birleştirir, en olası etiketlemeyi bulur ve basit bir şablonla cümle üretir (örnek etiketleme, ekrandan 00:16:50: `<<null,person_b>,against,<brown,sofa_c>>`, `<<null,dog_a>,near,<null,person_b>>`, `<<null,dog_a>,beside,<brown,sofa_c>>`).
  - Uçtan uca yaklaşımda ara adım yoktur: resim girer, cümle çıkar. Show and Tell'de resim CNN ile vektöre çevrilir, bu vektör LSTM'in ilk girdisidir. Sonra kelimeler one-hot $S_t$ olarak $W_e$ embedding katmanından geçirilip birer birer LSTM'e beslenir; her adımda bir sonraki kelimenin olasılığı $p_t(S_t)$ hesaplanır. (resim, tanım) ikilisi az olduğu için CNN sıfırdan değil, ImageNet gibi büyük bir kümede eğitilmiş ağırlıklardan başlatılır.
  - <!-- BELİRSİZ: Hoca CNN'in ResNet mi Inception mı olduğunu hatırlamadığını söyledi (00:19:07). -->
- VQA'da resmin katkısı neden azdı?
  - Baseline tablosunda (ekrandan, 00:24:40) yalnız soru ile tüm open-answer doğruluğu 48,09, soru + resim ile 52,64 (fark 4,55 puan); LSTM'de 48,76'dan 53,74'e (fark 4,98 puan) çıkıyor. Yes/No sorularında resim neredeyse hiç katkı vermiyor (75,66 → 75,55). Yalnız resim ile Number ve Other türlerinde doğruluk %1-4 düzeyinde kalıyor.
  - Bunun nedeni veri kümesindeki yanlılıklardır: insanlar crowdsourcing ile resme bakıp soru yazarken "balık var mı?" sorusunu ancak balık varsa sorar; böylece cevap sorudan tahmin edilebilir hâle gelir.
  - VQA v2 aynı soruyu, cevabı farklı olan iki resimle eşleştirerek bu kısa yolu kapatır. Yalnız soruya bakan sistem için her cevap eşit olasılıklı olur (örneğin "man" %50, "woman" %50).
- SimCLR'in mantığı ve sınırı
  - Aynı resimden kırpılan iki parçaya renk değişimi, gri tonlama gibi dönüşümler uygulanır ki model renklere takılmasın. İki parçanın temsilleri birbirine yaklaştırılır; farklı resimlerin (köpek ve sandalye) parçalarının temsilleri birbirinden uzaklaştırılır. Böylece farklı köpek resimleri etiketlenmeden, resmin kendi içindeki ilişkilerden köpeği, kediyi tanıyabilen bir pre-trained model elde edilir.
  - Sınırı: resimde birden fazla nesne varsa, iki kırpıntı farklı nesnelere düşebilir ve model kedi ile köpeğin benzer olduğunu öğrenmeye zorlanır. Cümleler de bu tür çok nesneli resimlere benzer; bu yüzden yöntemi yalnız metne uygulamak zordur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
