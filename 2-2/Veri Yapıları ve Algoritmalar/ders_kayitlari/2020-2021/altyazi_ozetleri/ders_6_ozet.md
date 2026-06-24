# Ders 6 Çalışma Özeti

## Genel Konular

- Ağaç veri yapısı
  - Düğüm, kenar, kök, çocuk, ebeveyn, yaprak, seviye ve yükseklik kavramları açıklanır.
  - Kapalı çevrim içermeyen hiyerarşik yapıların ağaç olarak modellenebileceği belirtilir.
- İkili ağaçlar
  - Her düğümün en fazla iki çocuğa sahip olduğu ağaç türü tanıtılır.
  - Diziyle gösterimde sol çocuk için `2i + 1`, sağ çocuk için `2i + 2` ilişkisi kullanılır.
- İkili arama ağacı
  - Sol alt ağaçta daha küçük, sağ alt ağaçta daha büyük değerlerin tutulduğu sıralı ağaç yapısı anlatılır.
  - Arama, ekleme ve silme işlemlerinin ağacın şekline bağlı olarak değişen maliyetlere sahip olduğu vurgulanır.
- Ağaç gezintileri
  - Preorder, inorder ve postorder gibi gezinti mantıkları rekürsif yapı üzerinden ele alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ağaçlar hiyerarşik ilişkileri temsil eder.
  - Graf yapısından farkı çevrim içermemesi ve kökten dallanan bir düzen sunmasıdır.
- İkili arama ağacında sıralama kuralı korunmalıdır.
  - Yanlış yerleştirilen bir düğüm arama işleminin doğru çalışmasını bozar.
- Rekürsif düşünme ağaç işlemleri için doğaldır.
  - Alt ağaçlar da aynı veri yapısının daha küçük örnekleridir.

## Kısa Tekrar Notları

- Ağaç çevrimsiz hiyerarşik yapıdır.
- İkili ağaçta en fazla iki çocuk bulunur.
- BST kuralı: küçükler sol, büyükler sağ.
- Inorder gezinti BST'de sıralı çıktı verir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Derste ağaçlar, bağlı yapılardan hiyerarşik yapılara geçiş olarak ele alınır. Bir ağacın kökü başlangıç noktasıdır; yapraklar çocuğu olmayan düğümlerdir. İkili ağaçların diziyle gösterimi, heap gibi yapılara temel hazırlar. İkili arama ağacında her düğüm yerleştirilirken mevcut düğümle karşılaştırılır; küçükse sola, büyükse sağa ilerlenir. Bu özellik korunduğunda arama işlemi de aynı karşılaştırma mantığıyla yapılır. Ancak ağaç dengesiz büyürse performans bağlı listeye yaklaşabilir.
