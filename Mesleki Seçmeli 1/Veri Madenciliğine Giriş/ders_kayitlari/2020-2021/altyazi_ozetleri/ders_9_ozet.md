# Ders 9 Çalışma Özeti

## Genel Konular

- Dengesiz sınıf problemi
  - Veri setinde bir sınıf çok fazla, diğer sınıf çok az örnek içerdiğinde accuracy yanıltıcı olabilir.
  - Kredi kartı sahteciliği, saldırı tespiti ve kusurlu ürün tespiti gibi problemlerde azınlık sınıfı genellikle daha önemlidir.
- Confusion matrix ve başarı ölçütleri
  - True positive, true negative, false positive ve false negative kavramları üzerinden sınıflayıcı performansı değerlendirilir.
  - Precision, recall, F-measure, specificity, false positive rate ve false negative rate ölçütleri anlatılır.
- ROC eğrisi
  - ROC eğrisi, true positive rate ile false positive rate arasındaki ilişkiyi grafiksel olarak gösterir.
  - Olasılık üreten sınıflayıcı çıktıları ve threshold değişimi kullanılarak çizilir.
- KNN için model seçimi
  - K değeri validation verisi üzerinden seçilebilir.
  - Eğitim, doğrulama ve test ayrımı model başarısını tarafsız değerlendirmek için kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Accuracy'nin dengesiz veride yetersizliği
  - Tüm örnekleri çoğunluk sınıfına atayan bir model yüksek accuracy üretebilir ama azınlık sınıfını tamamen kaçırabilir.
- Confusion matrix yönlerinin doğru okunması
  - Actual ve predicted sınıfların hangi eksende bulunduğu karıştırılırsa tüm ölçütler yanlış hesaplanır.
- ROC için olasılık çıktısı gerekliliği
  - Sadece sınıf etiketi veren modelden ROC çizmek yeterli değildir; eşik değişimi için skor veya olasılık gerekir.

## Kısa Tekrar Notları

- Precision = pozitif denilenlerin ne kadarı gerçekten pozitif?
- Recall = gerçek pozitiflerin ne kadarı yakalandı?
- F-measure, precision ve recall'un harmonik ortalamasıdır.
- ROC eksenleri: yatayda false positive rate, dikeyde true positive rate.
- KNN'de K değeri validation set ile seçilebilir.

## Detaylı Açıklamalar

- Derste dengesiz veri probleminde accuracy'nin neden yanıltıcı olduğu örneklerle açıklanır. Eğer 1000 örneğin 990'ı negatif, 10'u pozitifse, tüm örneklere negatif diyen bir model yüzde 99 accuracy verir. Fakat pozitif sınıf asıl önemli sınıfsa model pratikte başarısızdır.
- Confusion matrix, sınıflayıcının hangi örnekleri doğru veya yanlış etiketlediğini gösterir. True positive gerçek pozitifin pozitif tahmin edilmesi, false negative gerçek pozitifin negatif tahmin edilmesi, false positive gerçek negatifin pozitif tahmin edilmesi, true negative ise gerçek negatifin negatif tahmin edilmesidir.
- Precision ve recall farklı başarı boyutlarını ölçer. Precision yanlış alarmı, recall ise kaçırılan pozitifleri anlamak için önemlidir. F-measure bu iki ölçütü tek sayıda birleştirerek model karşılaştırmayı kolaylaştırır.
- ROC eğrisi, farklı threshold değerlerinde modelin yakalama oranı ile yanlış alarm oranı arasındaki değişimi gösterir. İyi bir sınıflayıcı yüksek true positive rate ve düşük false positive rate üretmelidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
