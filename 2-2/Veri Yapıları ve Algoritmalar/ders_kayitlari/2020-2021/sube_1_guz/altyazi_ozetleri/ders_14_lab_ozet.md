# Ders 14 Lab Çalışma Özeti

## Genel Konular

- Graf projesi mantığı
  - Takipçi/takip edilen ilişkileri gibi verilerin düğüm ve yönlü kenarlarla graf olarak modellenebileceği açıklanır.
- En kısa yol hesaplama
  - Birden fazla düğüm çifti için shortest path hesaplama fikri tartışılır.
  - Dijkstra algoritmasının proje adımlarında kullanılabilecek temel yöntem olduğu belirtilir.
- Raporlama ve algoritma çıktısı
  - Kod çıktılarının yalnızca üretilmesi değil, hangi adımların yapıldığını açıklayan bir raporla desteklenmesi gerektiği vurgulanır.
- Akış diyagramı/kod kontrolü
  - Döngülerin ve koşulların graf üzerinde nasıl ilerlediğini açık göstermek gerektiği konuşulur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sosyal ağ verisi doğal olarak yönlü graf şeklinde modellenir.
  - Bir kullanıcının diğerini takip etmesi, ters yönde ilişkinin zorunlu olduğu anlamına gelmez.
- Shortest path hesaplarında veri yapısı tasarımı önemlidir.
  - Düğümlerin hızlı bulunması, kenarların doğru eklenmesi ve tekrarların yönetilmesi gerekir.
- Rapor, algoritmanın sonucunu ve izlenen yöntemi anlaşılır kılmalıdır.

## Kısa Tekrar Notları

- Kişiler düğüm, takip ilişkileri yönlü kenardır.
- Dijkstra belirli kaynaklardan kısa yol bulmak için kullanılabilir.
- Graf kurarken düğüm tekrarları kontrol edilmelidir.
- Kod ve rapor birlikte değerlendirilmelidir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Bu uygulama kaydı, graf konularının proje düzeyinde nasıl kullanılabileceğini gösterir. Takipçi verisi gibi ilişkisel verilerde her kullanıcı bir düğüm, takip ilişkisi yönlü bir kenar olarak temsil edilir. Bu yapı kurulduktan sonra düğümler arası en kısa yolların hesaplanması, erişilebilirlik ve bağlantı analizleri yapılabilir. Dijkstra gibi algoritmalar, kenar maliyetlerinin uygun olduğu durumlarda bu hesaplamalar için kullanılabilir.
