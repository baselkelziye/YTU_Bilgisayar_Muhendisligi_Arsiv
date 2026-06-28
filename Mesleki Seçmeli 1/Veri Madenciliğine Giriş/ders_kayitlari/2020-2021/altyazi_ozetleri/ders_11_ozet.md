# Ders 11 Çalışma Özeti

## Genel Konular

- Eğiticisiz öğrenme ve kümeleme
  - Kümeleme, sınıf etiketi olmayan verileri benzerliklerine göre gruplama işlemidir.
  - Etiketleme maliyetli olduğu için kümeleme büyük ve etiketsiz veri kümelerinde önemlidir.
- Uzaklık ve benzerlik ölçütleri
  - Öklid, Manhattan, Minkowski, Mahalanobis, kosinüs benzerliği ve Hamming gibi ölçütler ele alınır.
  - Nümerik ve ikili öz nitelikler için farklı metrikler uygun olabilir.
- Binary özelliklerde benzerlik
  - Simple Matching Coefficient, sıfır-sıfır ve bir-bir eşleşmelerini birlikte dikkate alır.
  - Jaccard benzerliği özellikle bir-bir eşleşmelerini önemser ve sıfır-sıfır eşleşmesini hesaba katmaz.
- K-means kümeleme
  - K-means, n örneği önceden seçilen K adet kümeye ayırır.
  - Amaç, örneklerin kendi küme merkezlerine olan uzaklıklarının kareleri toplamını minimize etmektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- K-means'in temel yöntem oluşu
  - K-means anlaşılırsa fuzzy c-means, self organizing map ve benzeri yöntemleri anlamak kolaylaşır.
- Başlangıç küme merkezlerinin etkisi
  - İlk centroid seçimi sonucu etkileyebilir; yöntem iteratif olarak merkezleri günceller.
- Jaccard formülünde sıfır-sıfır eşleşmesinin dışarıda bırakılması
  - Asimetrik binary değişkenlerde iki örneğin aynı anda sıfır olması benzerlik anlamına gelmeyebilir.

## Kısa Tekrar Notları

- Kümeleme etiketsiz veriyle çalışır.
- Uzaklık ölçüsü seçimi algoritma sonucunu etkiler.
- K-means: K seç, centroid başlat, örnekleri en yakın merkeze ata, merkezleri güncelle, yakınsayana kadar tekrarla.
- Jaccard = bir-bir eşleşmesi / sıfır-bir + bir-sıfır + bir-bir eşleşmeleri.

## Detaylı Açıklamalar

- Derste kümeleme, veri madenciliğinin eğiticisiz öğrenme kolu olarak anlatılır. Kullanım örnekleri arasında e-postaları gruplama, müşteri segmentasyonu ve görüntüde bölge belirleme bulunur. Bu problemlerde sınıf etiketi olmadan doğal gruplar aranır.
- K-means'te önce K değeri belirlenir. Ardından K adet başlangıç merkezi seçilir. Her örnek en yakın merkezin kümesine atanır. Kümeler oluştuktan sonra her kümenin yeni merkezi hesaplanır. Örneklerin küme üyelikleri değişmeyene veya belirlenen durma koşulu sağlanana kadar işlem tekrarlanır.
- Mesafe ölçüsü seçimi kritik önemdedir. Nümerik verilerde Öklid veya Manhattan mesafesi kullanılabilirken, ölçek ve korelasyon etkilerini dikkate almak için Mahalanobis mesafesi tercih edilebilir. Metin veya vektör yönelimi önemli olduğunda kosinüs benzerliği anlamlıdır.
- Binary özelliklerde tüm eşleşmeler aynı öneme sahip olmayabilir. Simple matching tüm eşleşmeleri dikkate alırken, Jaccard yalnızca bir-bir eşleşmelerine odaklanır. Bu nedenle değişkenlerin anlamına göre doğru benzerlik ölçütü seçilmelidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
