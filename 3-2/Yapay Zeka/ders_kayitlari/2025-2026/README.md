# Yapay Zeka Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Yapay Zeka (BLM3510)
* **Hoca:** Dr. Ahmet Elbir
* **Dönem:** Bahar
* **Akademik Yıl:** 2025-2026
* **Şube:** BLM3510 - 2

Bu dizin, ilgili ders kayıtlarının altyazılarını, kısa notlarını ve genişletilmiş notlarını içermektedir.

* **Kısa not:** Tekrar için. Dersin konuları, hocanın vurguları ve kısa tekrar maddeleri.
* **Genişletilmiş not:** Dersi izlemeden öğrenmek için. Dersin anlatım akışını baştan sona, örnekleri ve soru-cevaplarıyla anlatır.
* `altyazilar/`: ders kayıtlarının altyazıları (.srt). Notların PDF'leri `kisa_notlar/` ve `genisletilmis_notlar/` klasörlerinde, markdown kaynakları bu klasörlerin içindeki `markdown/` klasöründedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu ile kısa ve genişletilmiş notlarının markdown ve PDF halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kısa Not | Genişletilmiş Not |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Sezgisel Arama: En İyi İlk Arama ve A* Algoritması | [Markdown](kisa_notlar/markdown/ders_1_ozet.md) · [PDF](kisa_notlar/ders_1_ozet.pdf) | [Markdown](genisletilmis_notlar/markdown/ders_1_genisletilmis.md) · [PDF](genisletilmis_notlar/ders_1_genisletilmis.pdf) |
| **Ders 2** | Öz Denetimli Öğrenme, Üretici Modeller ve RAG | [Markdown](kisa_notlar/markdown/ders_2_ozet.md) · [PDF](kisa_notlar/ders_2_ozet.pdf) | [Markdown](genisletilmis_notlar/markdown/ders_2_genisletilmis.md) · [PDF](genisletilmis_notlar/ders_2_genisletilmis.pdf) |
| **Ders 3** | Yapay Zeka, Etik ve Hukuk | [Markdown](kisa_notlar/markdown/ders_3_ozet.md) · [PDF](kisa_notlar/ders_3_ozet.pdf) | [Markdown](genisletilmis_notlar/markdown/ders_3_genisletilmis.md) · [PDF](genisletilmis_notlar/ders_3_genisletilmis.pdf) |

> [!NOTE]
> Dersler yüz yüze yapıldığından arşivde yalnızca üç online ders kaydı bulunmaktadır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Sezgisel Arama: En İyi İlk Arama ve A* Algoritması
* **Genel Konular:**
  - Kör (bilgisiz, uninformed) arama algoritmalarının kısa tekrarı: BFS, DFS, düşük maliyetli arama (uniform cost search, UCS).
  - Kör aramanın sınırları: Rastgele oluşturulmuş bir yol haritasında algoritmaların adım sayısı ve yol maliyeti karşılaştırması (Python uygulaması).
  - Sezgisel arama (heuristic search) fikri ve sezgisel fonksiyon $h(n)$.
  - En iyi ilk arama (best-first search, açgözlü arama / greedy search): $f(n)=h(n)$.
  - A* araması: $f(n)=g(n)+h(n)$.
  - Romanya haritası örneği: Arad'dan Bükreş'e (Bucharest) gitmek.
  - Izgara (grid) üzerinde Manhattan uzaklığıyla best-first ve A* karşılaştırması.
* **Hocanın Vurgusu:**
  - Kör algoritmalar hedefe çok yaklaşıp sonra uzaklaşabilir.
    - Çünkü hiçbir bilgiye bakmadan, yalnız verilen direktife göre düğüm seçerler.
  - BFS yalnız her adımın maliyeti eşitse optimal çözümü bulur.
    - Maliyetler farklıysa bulamayabilir.
  - UCS optimal çözümü bulur ama çok fazla düğüm açar.
    - Arama uzayı büyüdükçe yönetilemez hâle gelir. Yapısı Dijkstra algoritmasına benzer.
  - Sezgisel bilgi "hedefe ne kadar kaldı?" sorusunun tahminidir.
    - Tahmin iyimser olmalı, yani gerçek maliyeti aşmamalı.
  - Best-first search hızlı bir çözüm bulur ama yerel minimuma takılabilir.
    - Bulduğu çözüm optimal olmayabilir.

### 🔹 Ders 2: Öz Denetimli Öğrenme, Üretici Modeller ve RAG
* **Genel Konular:**
  - Eğiticili öğrenmenin (supervised learning) açmazı: yeterli etiketli veri bulmak.
  - Öz denetimli öğrenme (self-supervised learning):
    - Otokodlayıcılar (autoencoder) ve gizli uzay (latent space).
  - Uygulama: MNIST verisini otokodlayıcıyla 32 boyuta indirip KNN, SVM ve MLP ile sınıflandırma (Google Colab).
  - Üretici modeller (generative models): dağılımdan örnekleme, VAE, GAN, difüzyon, koşullu üretim.
  - Transformer mimarisi ve öz dikkat (self-attention).
  - Büyük dil modelleri (LLM): ölçek, zero-shot / one-shot / few-shot öğrenme, InstructGPT.
  - Halüsinasyon, ince ayar (fine-tuning) ve bilgi getirmeyle güçlendirilmiş üretim (Retrieval-Augmented Generation, RAG).
* **Hocanın Vurgusu:**
  - Makine öğrenmesinde en büyük darboğaz insandır.
    - Yeterli etiketli veri sağlanamazsa makine öğrenemez.
  - Öz denetimli öğrenmede cevap verinin kendisinde vardır.
    - Verinin bir parçası maskelenir, silinir veya bozulur. Model bu parçayı tahmin eder.
  - Bu yöntemle hem ucuz hem hızlı biçimde çok büyük miktarda eğitim örneği üretilebilir.
    - İnsan hatalarından bağımsızlık sağlanır.
  - Otokodlayıcının amacı veriyi özünü kaybetmeden sıkıştırmaktır.
    - Girdi $x$ ile yeniden oluşturulan $\hat{x}$ arasındaki fark en aza indirilir.
  - Klasik otokodlayıcı veriyi gizli uzayda tek bir noktaya eşler.
    - VAE ise bir bölgeye (dağılıma) eşler. Bu yüzden VAE yeni veri üretebilir.

### 🔹 Ders 3: Yapay Zeka, Etik ve Hukuk
* **Genel Konular:**
  - Etik (ahlak) ve hukuk kavramları, aralarındaki fark.
  - Yapay zekanın karar veren sistem olarak özel durumu: ölçek, kara kutu, önyargı, kültürel bağımlılık.
  - Verilerdeki önyargı (bias) ve türleri. Önyargıyı azaltma yöntemleri.
  - Korelasyon ile nedensellik (causality) karışıklığı.
  - Sorumluluk: Yapay zekanın yanlış kararında suçlu kim?
  - Açıklanabilirlik (explainability), kara kutu sorunu ve GDPR.
  - Yapay zeka ve işsizlik: karamsar ve iyimser senaryolar, meslek risk haritası.
* **Hocanın Vurgusu:**
  - Hukuki olan her şey etik değildir.
    - Yapay zekanın kararları hukuk ve etik açısından ayrı ayrı değerlendirilmelidir.
  - Etik kurallar zamandan ve kültürden bağımsız değildir.
    - Kölelik bir zamanlar hukukiydi.
  - Bir insanın önyargısı tek bir şirketle sınırlı kalır.
    - Aynı önyargı yapay zekaya öğretilirse milyonlarca karara yayılır.
  - Model, verideki önyargıyı da öğrenir.
    - Önyargılı veriyle eğitilen yapay zeka önyargılı karar verir.
  - Birlikte değişen şeyler her zaman neden-sonuç ilişkisi içinde değildir.
    - Korelasyonu nedensellik sanmak yapay zekayı yanıltır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
