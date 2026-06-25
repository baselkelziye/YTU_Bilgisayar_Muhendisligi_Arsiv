# Ders 4 Çalışma Özeti

## Genel Konular

- Sınav sorularının çözümü ve hata analizi
  - Kesme hatası sorusunda mutlak hata formülünün doğru kullanımı tartışıldı.
  - Normalize edilmiş kayan nokta gösterimi ile ilgili örnekler çözüldü.
  - Hassasiyet karşılaştırması: farklı ölçüm araçlarıyla yapılan ölçümlerin bağ hatası üzerinden değerlendirilmesi.
- Taylor serisi açılımı
  - Taylor serisi, bir fonksiyonun belirli bir noktadaki türevleri kullanarak yaklaşık olarak ifade edilmesidir.
  - Seri açılımında n. terim: f⁽ⁿ⁾(x₀) / n! × (x - x₀)ⁿ formülüyle hesaplanır.
  - Türevlerin alınmasıyla seri katsayıları belirlenir; 4. türevde 4! katsayısı, 5. türevde 5! katsayısı bulunur.
- Fonksiyonun türev türetimi
  - f(x) = (x-1)ⁿ formülü için türevler alındığında f⁽ⁿ⁾(x) = n! × (x-1)⁰ = n! sonucuna ulaşılır.
  - Bu sonuç, Taylor serisinin genel formunda kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınav sorularında Banu Hoca'nın slide'daki formülünün farklı bir biçimi kullanılmış; her ikisi de doğrudur ancak hangisinin kullanılacağı soruda belirtilmelidir.
- Quizlerin amacı: dersin canlılığını artırmak, pratik yapmak; zorlayıcı olmaktan ziyade dersteki konuların tekrarı niteliğindedir.
- Hesap makinesi yerine bilgisayardaki scientific mod yeterlidir.

## Kısa Tekrar Notları

- Mutlak hata formülü: |gerçek değer - elde edilen değer|
- Bağl hatası: |gerçek değer - elde edilen değer| / |gerçek değer|
- Taylor serisi: f(x) = Σ f⁽ⁿ⁾(x₀) / n! × (x - x₀)ⁿ
- Normalize kayan nokta: birgülden sonra bir anlamlı basamak gelecek şekilde ifade.

## Detaylı Açıklamalar

Bu derste önceki haftanın sınav sorularının çözümleri ele alındı. Hata analizinde Banu Hoca'nın slide'larında verilen mutlak hata formülünün farklı bir biçimi kullanıldığı tartışıldı; her iki formül de literatürde mevcut olup soruda hangisinin kullanılacağı belirtilmelidir.

Taylor serisi açılımı, sayısal analizin temel araçlarından biridir. Bir fonksiyonun belirli bir noktadaki tüm türevlerinin bilinmesi durumunda fonksiyonun tam olarak yeniden oluşturulabileceği, ancak pratikte belirli bir terimde kesilerek yaklaşık bir ifade elde edildiği vurgulandı. Bu yaklaşık ifadeden kaynaklanan hata, kesme hatası olarak adlandırılır.

Hassasiyet karşılaştırması örneğinde, farklı ölçüm araçlarıyla yapılan ölçümlerin bağ hatası üzerinden değerlendirilmesi gösterildi. Örneğin 100 kg ile tartımda 100 kg hata ve 0.01 gram ile tartımda 5 gram hata, her ikisi de %0.2 bağ hatası vermektedir; bu da her iki ölçümün de aynı hassasiyete sahip olduğunu gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
