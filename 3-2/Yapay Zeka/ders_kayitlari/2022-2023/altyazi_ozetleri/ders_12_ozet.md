# Ders 12 Çalışma Özeti

## Genel Konular

- Sınıflandırma algoritmalarının devamı
  - Karar sınırı, sınıflandırma başarısı ve farklı sınıflandırma algoritmalarının davranışları üzerinde durulur.
- Doğrusal ve doğrusal olmayan karar sınırları
  - Bazı problemlerin düz bir karar sınırıyla ayrılabileceği, bazı problemlerde ise daha karmaşık sınırlara ihtiyaç duyulacağı anlatılır.
- Yapay sinir ağları
  - Sınıflandırma ve regresyon problemlerinde kullanılabilen, özellikle karmaşık örüntülerde esnek karar sınırları öğrenebilen modeller olarak ele alınır.
- Kümeleme algoritmaları
  - Etiketsiz verilerde benzer örnekleri gruplama fikri anlatılır.
- Kümeleme türleri
  - Hiyerarşik, merkez tabanlı ve yoğunluk tabanlı kümeleme yaklaşımlarının farklı mantıklara dayandığı açıklanır.
- Regresyon algoritmaları
  - Sürekli değer tahmini yapan modeller; basit lineer regresyon, KNN regresyon ve regresyon ağaçları gibi örnekler üzerinden tartışılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Her problem doğrusal karar sınırıyla çözülemez.
  - Veri yapısı karmaşıksa daha esnek modeller gerekebilir.
- Yapay sinir ağları güçlüdür ama her durumda tek doğru seçenek değildir.
  - Veri miktarı, problem yapısı ve yorumlanabilirlik ihtiyacı model seçimini etkiler.
- Kümeleme ile sınıflandırma aynı şey değildir.
  - Sınıflandırmada etiketler vardır; kümelemede amaç etiketsiz örnekleri benzerliklerine göre ayırmaktır.
- Kümeleme başarısını değerlendirmek sınıflandırmadan daha zordur.
  - Çünkü çoğu zaman elde hazır doğru etiketler yoktur.
- Regresyon ağaçları ve karar ağaçları benzer yapıyı farklı çıktı türleri için kullanır.
  - Sınıflandırmada yapraklar sınıf, regresyonda ise sayısal tahmin üretebilir.

## Kısa Tekrar Notları

- Doğrusal karar sınırı her veri dağılımı için yeterli değildir.
- Yapay sinir ağları karmaşık örüntüler öğrenebilir.
- Kümeleme etiketsiz verilerde benzerlik arar.
- Hiyerarşik, merkez tabanlı ve yoğunluk tabanlı kümeleme farklı yaklaşımlardır.
- Regresyon sürekli değer tahmini yapar.
- KNN ve karar ağacı mantığı regresyon problemlerine de uyarlanabilir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Veri noktalarını sınıflarına göre ayıran geometrik çizgilere veya hiper-düzlemlere karar sınırları (decision boundaries) denir. Bazı problemler (örneğin AND/OR mantıksal kapıları) tek bir doğruyla ayrılabilirken (doğrusal karar sınırı), XOR gibi problemler doğrusal olmayan (non-linear) karar sınırları gerektirir. Yapay Sinir Ağları (YSA), doğrusal olmayan bu karmaşık fonksiyonları öğrenmek için tasarlanmış, biyolojik beyin hücrelerinden esinlenen modellerdir. Çok katmanlı algılayıcılar (MLP) aktivasyon fonksiyonları (Sigmoid, ReLU, Tanh) kullanarak doğrusal olmayan ilişkileri başarıyla modeller. Denetimsiz öğrenmede ise etiketlenmemiş verileri benzerliklerine göre gruplamak için K-Ortalamalar (K-Means) ve hiyerarşik kümeleme gibi Kümeleme (Clustering) algoritmaları kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
