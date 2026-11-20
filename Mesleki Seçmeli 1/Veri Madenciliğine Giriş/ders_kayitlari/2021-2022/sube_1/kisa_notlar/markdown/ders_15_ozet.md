# Ders 15 Çalışma Özeti

## Genel Konular

- Ders, öğrenci gruplarının veri madenciliği proje sunumlarıyla geçti. Hoca yeni konu anlatmadı; sunumlar sırasında sorular sordu ve yöntemlerle ilgili yorumlar yaptı.
  - Kayıtta ekran paylaşımı görünmüyor (kareler kamera kapalı simgesi ve siyah ekran). Bu yüzden sunumlardaki tablolar ve sonuç değerleri okunamadı; aşağıdakiler yalnız konuşmadan çıkarılabilenlerdir.
  - Altyazı sunumlar sırasında çok bozuk; yöntem adları ve sayılar bağlamdan çıkarıldı.
- Görüntü verisiyle sınıflandırma (birinci sunum)
  - Öznitelik olarak her renk aralığına düşen piksel sayısı kullanıldı.
  - Üç sınıflandırıcı karşılaştırıldı: Naive Bayes, k-en yakın komşu (k-NN) ve rastgele orman (random forest, 50 ağaç).
  - Değerlendirme 10 katlı çapraz doğrulama (10-fold cross-validation) ile yapıldı.
  - En başarılı yöntem random forest oldu; grup bunu veri setinin dengesiz olmasına bağladı (örneklerin yarıdan fazlası "others" sınıfındaydı).
  - Naive Bayes'in kötü çalışacağı baştan bekleniyordu: komşu pikseller ve renkler birbirinden bağımsız değildir, bu da Naive Bayes'in bağımsızlık ön koşulunu bozar.
- Tablo verisiyle sınıflandırma (ara sunumlar)
  - UCI veri deposundan alınmış, kadınlarda görülen bir kanser türüyle ilgili veri seti; bazı yöntemlerde yaklaşık %95 başarı söylendi.
  - Milyonlarca satırlık bir veri setinde sınıflar dengesizdi; veri karıştırılıp sınıflardan eşit sayıda örnek alınarak (alt örnekleme) yeni bir alt küme oluşturuldu, aykırı değerler önceden çıkarıldı. Karar ağaçları, kümeleme ve k-NN denendi.
  - Çok sütunlu bir veri setinde öznitelik seçiminin önemi vurgulandı; serbest metin (açıklama) sütunlarının ayrı bir metin madenciliği problemi olduğu belirtildi.
- Metin verisiyle çok etiketli sınıflandırma (soru-cevap sitesi soruları)
  - Her soruya en fazla 5 etiket eklenebildiği bir veri seti; yaklaşık 780 bin soru.
  - Ön işleme: soru metnindeki kod bölümleri çıkarıldı, soru uzunluğu sınırlandı. Her soruya tek etiket verildi: sorunun etiketlerinden en popüler etiketler arasında olanlar alındı, bunlardan en az popüler olanı seçildi ki az görülen sınıfların da örneği olsun.
  - Yöntemler: Naive Bayes, doğrusal (linear) SVM, kernel'lı SVM ve önceden eğitilmiş kelime vektörleriyle LSTM tabanlı bir model (eğitimi yaklaşık 20-25 saat sürdü).
- Son sunum: bir hastalık veri seti; dağılım grafikleri Python'da Matplotlib ile çizildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınıflandırma ile tahmin (prediction) farkı
  - Türkçede "tahmin" denince daha çok regresyon tabanlı, sürekli (continuous) değer üreten modeller anlaşılır. Kategorik bir sınıf etiketi üretiliyorsa yapılan iş sınıflandırmadır; iki farklı hedef sütunu seçmek iki ayrı sınıflandırma problemidir.
  - Lojistik regresyon gibi bir modelin çıktısı 1,24 gibi sürekli bir sayı olabilir; ama sınıf etiketi tahmin edilen bir problemde buna "tahmin" demek çok uygun değildir.
- Doğrusal SVM ve kernel
  - SVM temelde veriyi doğrusal olarak ayırır. Bazı uzaylar doğrusal olarak ayrılamadığından içine kernel fonksiyonları (polinom vb.) konur. Kernel kullanan sürüm daha yavaş çalışır ama doğrusal olmayan ayrımlarda daha iyi sonuç verebilir.
- Naive Bayes'in bağımsızlık varsayımı
  - Görüntüde komşu pikseller, metinde birlikte geçen anahtar kelimeler (ör. aynı soruda birlikte geçen teknoloji adları) birbirine bağlıdır. Bu bağımlılık Naive Bayes'in daha kötü sonuç vermesinin olağan nedenidir.
- Etiketler arasındaki hiyerarşi
  - Bazı etiketler diğerlerinin alt kümesi gibidir. Bu durumda düz sınıflandırma yerine etiketleri hiyerarşik olarak ele almak (hiyerarşik sınıflandırma/kümeleme) anlamlı bir sonuç çıkarabilir: hangi etiketin neyin altında olduğu görülebilir.
- Metin ön işlemesi
  - LSTM'e vermeden önce bağlaç gibi gereksiz kelimelerin elenmesi iyi yapılmalıdır.
- Sınıf seçimi
  - Hedef sınıfın (etiketin) dikkatli ve doğru seçilmesi sonucun anlamlı olması için çok önemlidir.

## Kısa Tekrar Notları

- Dengesiz veri setinde random forest daha dayanıklı olabilir; alt örnekleme (her sınıftan eşit sayıda örnek) dengesizliği azaltmanın bir yoludur.
- Naive Bayes öznitelikleri bağımsız varsayar; pikseller ve birlikte geçen kelimeler bu varsayımı bozar.
- Sınıflandırma kategorik etiket üretir; "tahmin" Türkçede çoğunlukla regresyon (sürekli değer) için kullanılır.
- Doğrusal SVM hızlıdır; kernel'lı SVM doğrusal ayrılamayan veride daha iyi olabilir ama yavaştır.
- Etiketler hiyerarşikse hiyerarşik yöntemler düşünülmelidir.
- Değerlendirmede çapraz doğrulama mı yoksa eğitim/test ayrımı mı yapıldığı her zaman belirtilmelidir.

## Detaylı Açıklamalar

- Birinci sunumda görüntülerden renk tabanlı öznitelikler çıkarıldı: belirli renk aralıklarına düşen piksel sayıları. Bu özniteliklerle Naive Bayes, k-NN ve 50 ağaçlı random forest eğitildi. Random forest her ağaç için farklı bir alt veri seti ve farklı öznitelikler kullanır, sonuçta en çok oy alan sınıfı seçer. Grubun açıklamasına göre veri setinin yarıdan fazlası tek bir "others" sınıfındaydı ve random forest bu dengesizlikten en az etkilenen yöntem oldu. Naive Bayes ise bilinçli olarak "kötü çalışması beklenen" yöntem diye seçilmişti: bir görüntüde kırmızı bir bölgenin yanında sarı bir bölge beklenebilir, yani renk/piksel değerleri birbirinden bağımsız değildir.
  <!-- BELİRSİZ: Sunumdaki başarı tablosu ekranda gösterildi ama kayıtta görüntü yok; değerler ve k-NN'deki k değeri altyazıdan güvenilir okunamıyor. -->
- Sınıflandırma ile tahmin arasındaki fark bir sunumda tartışma konusu oldu. Grup iki farklı hedef sütun için birine "sınıflandırma", diğerine "tahmin" demişti. Hoca ikisinin de sınıflandırma olduğunu, yalnız hedef değişkenlerin ve alt veri setlerinin farklı olduğunu söyledi. "Tahmin" kelimesi sıcaklık gibi sürekli bir değerin kestirilmesi (regresyon) için daha uygundur.
- Metin sınıflandırma sunumunda çok etiketli veri tek etiketli probleme indirgendi. Hoca doğruluk hesaplanırken yalnız seçilen tek etikete mi bakıldığını sordu; bu, çok etiketli veride değerlendirme ölçütünün dikkatle tanımlanması gerektiğini gösterir. Hoca ayrıca etiketler arasındaki alt küme ilişkileri nedeniyle hiyerarşik bir yaklaşım önerdi ve LSTM'in metin üretebildiğini hatırlatarak modelin kendi kendine soru yazması ve bu soruların insanlar tarafından puanlanması gibi bir ileri proje fikri verdi.
  <!-- BELİRSİZ: Kullanılan önceden eğitilmiş kelime vektörlerinin adı ve LSTM türü (altyazıda "Dileyle STM") net değil; büyük olasılıkla Bi-LSTM. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
