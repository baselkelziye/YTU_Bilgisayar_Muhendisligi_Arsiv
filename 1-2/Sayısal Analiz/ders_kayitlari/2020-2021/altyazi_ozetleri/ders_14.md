# Ders 14 Çalışma Özeti

## Genel Konular

- Regresyon
  - Regresyon, elimizdeki veri noktalarını en iyi temsil eden bir fonksiyon üretmeyi amaçlar.
  - İnterpolasyondan farkı: interpolasyon tüm noktalardan geçerken, regresyon noktaların üzerinden geçmeyen ancak en iyi yaklaşımı sağlayan bir fonksiyon üretir.
  - Hataların karelerinin toplamını minimize ederek en iyi uyumu sağlayan fonksiyon bulunur.
- İnterpolasyon ile regresyon karşılaştırması
  - İnterpolasyon: verilen tüm noktalardan geçen bir polinom üretilir.
  - Regresyon: noktaların tümünü temsil eden, minimum hata ile bir fonksiyon üretilir.
  - İnterpolasyonda nokta sayısı polinom derecesini belirler; regresyonda ise tüm veri seti kullanılır.
- Ekstrapolasyon
  - Verilen aralığın dışında kalan değerler için tahminde bulunma.
  - İnterpolasyon aralık içinde, ekstrapolasyon aralık dışında çalışır.
- Dersin genel özeti
  - Sayısal analizin tüm konuları (hata analizi, eşitlik çözümü, integral, türev, interpolasyon, regresyon) gözden geçirildi.
  - Hangi konunun ne zaman işlendiği özetlendi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Regresyonun interpolasyondan temel farkı: noktaların üzerinden geçmek yerine en iyi yaklaşımı sağlaması.
- Büyük veri setlerinde interpolasyon yerine regresyon tercih edilir; çünkü interpolasyon çok yüksek dereceli polinomlar üretebilir.
- Regresyonda "hataların karelerinin toplamını minimize etme" prensibi vurgulandı.
- Dersin tamamı boyunca işlenen konuların bir bütün oluşturduğu belirtildi.

## Kısa Tekrar Notları

- Regresyon: minimum hata ile veri setine en iyi yaklaşımı sağlayan fonksiyon.
- İnterpolasyon: tüm noktalardan geçen polinom; regresyon: en iyi yaklaşımı sağlayan fonksiyon.
- Ekstrapolasyon: aralık dışında tahmin.
- Hataların karelerinin toplamını minimize etme prensibi.

## Detaylı Açıklamalar

Bu derste regresyon konusu ele alındı. Regresyon, elimizdeki veri noktalarını en iyi temsil eden bir fonksiyon üretmeyi amaçlar. İnterpolasyondan temel farkı, interpolasyonun verilen tüm noktalardan geçen bir polinom üretirken, regresyonun noktaların üzerinden geçmeyen ancak en iyi yaklaşımı sağlayan bir fonksiyon üretmesidir.

Regresyonda hataların karelerinin toplamını minimize etme prensibi kullanılır. Bu sayede veri setindeki gürültüye rağmen anlamlı bir fonksiyon elde edilir. Büyük veri setlerinde interpolasyon yerine regresyon tercih edilir; çünkü interpolasyon çok yüksek dereceli polinomlar üretebilir ve aşırı öğrenmeye (overfitting) neden olabilir.

Ekstrapolasyon konusu da kısaca ele alındı; verilen aralığın dışında kalan değerler için tahminde bulunmayı ifade eder. İnterpolasyon aralık içinde, ekstrapolasyon ise aralık dışında çalışır.

Dersin sonunda sayısal analizin tüm konuları (hata analizi, eşitlik çözümü, integral, türev, interpolasyon, regresyon) gözden geçirildi ve hangi konunun ne zaman işlendiği özetlendi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
