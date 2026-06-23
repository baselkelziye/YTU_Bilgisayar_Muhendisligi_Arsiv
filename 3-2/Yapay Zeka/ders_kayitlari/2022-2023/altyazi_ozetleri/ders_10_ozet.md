# Ders 10 Çalışma Özeti

## Genel Konular

- Makine öğrenmesine giriş
  - Makine öğrenmesinin veriden örüntü çıkarma ve bu örüntülerle yeni örnekler hakkında karar verme süreci olduğu anlatılır.
- Öğrenme problem türleri
  - Sınıflandırma, regresyon ve kümeleme gibi temel problem türleri tanıtılır.
- Denetimli öğrenme
  - Girdi-çıktı eşleşmelerinin bulunduğu veriyle model eğitme fikri açıklanır.
- Sınıflandırma ve regresyon ayrımı
  - Kategorik sonuçların sınıflandırma, sayısal/sürekli sonuçların regresyon problemi olarak ele alınabileceği belirtilir.
- Kümeleme fikri
  - Etiketlenmemiş verilerde benzer örnekleri gruplama yaklaşımı tanıtılır.
- Eğitim verisi ve model ilişkisi
  - Modelin geçmiş örneklerden öğrendiği, ancak amacın yalnızca eğitim verisini ezberlemek değil yeni örneklerde iyi genelleme yapmak olduğu vurgulanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Problem türünü doğru belirlemek gerekir.
  - Aynı veri farklı biçimde ele alınabilir; çıktı değişkeninin yapısı sınıflandırma mı regresyon mu yapılacağını belirler.
- Makine öğrenmesi ezberleme değildir.
  - Modelin asıl başarısı görmediği verilerde doğru genelleme yapabilmesidir.
- Veri temsili model başarısını etkiler.
  - Özelliklerin nasıl seçildiği ve ifade edildiği, öğrenme algoritmasının performansını doğrudan belirler.
- Sınıflandırma, regresyon ve kümeleme birbirine karıştırılmamalıdır.
  - Her biri farklı çıktı yapısı ve farklı değerlendirme mantığı gerektirir.

## Kısa Tekrar Notları

- Makine öğrenmesi veriden örüntü öğrenir.
- Sınıflandırma kategorik çıktı üretir.
- Regresyon sayısal/sürekli çıktı üretir.
- Kümeleme etiketsiz verileri benzerliklerine göre gruplar.
- Başarılı model, eğitim verisinin ötesinde genelleme yapabilen modeldir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Makine öğrenmesi, açık kurallar yazmak yerine verilerden örüntüler (patterns) ve ilişkiler öğrenen algoritmaların tasarımıyla ilgilenir. Temel olarak denetimli öğrenme (supervised learning), denetimsiz öğrenme (unsupervised learning) ve pekiştirmeli öğrenme (reinforcement learning) olmak üzere üç sınıfa ayrılır. Denetimli öğrenmede model, girdilerin ve bunlara karşılık gelen hedef etiketlerin (labels) bulunduğu bir veri kümesiyle eğitilir. Çıktı değişkeni sürekli/sayısal bir değer ise problem bir regresyon (regression), kategorik/sınıfsal bir değer ise bir sınıflandırma (classification) problemidir. Modelin başarısı, eğitim verisine aşırı uyum sağlamadan (overfitting) yeni ve görülmemiş verilere genelleme (generalization) yapabilme yeteneğiyle ölçülür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
