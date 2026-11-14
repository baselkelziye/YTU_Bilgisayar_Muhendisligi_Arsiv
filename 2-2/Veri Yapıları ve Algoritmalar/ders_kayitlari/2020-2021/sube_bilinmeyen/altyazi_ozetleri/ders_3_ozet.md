# Ders 3 Çalışma Özeti

## Genel Konular

- Diziler
  - Aynı türden verilerin ardışık bellek alanlarında tutulduğu, indis yoluyla erişildiği ve rastgele erişimin güçlü olduğu açıklanır.
  - Araya eleman ekleme veya ortadan silme durumlarında kaydırma maliyetinin oluştuğu belirtilir.
- Bağlı listeler
  - Her düğümün veri alanı ve bir sonraki düğümü gösteren bağlantı alanından oluştuğu anlatılır.
  - Listenin başlangıcını tutan `head` işaretçisinin yapının tamamına erişim için kritik olduğu vurgulanır.
- Sıralı listeye ekleme ve silme
  - Yeni elemanın doğru konuma yerleşmesi için önceki ve sonraki düğümlerin takip edilmesi gerekir.
  - Silme işleminde silinecek düğümün bağlantıları atlanarak liste bütünlüğü korunur.
- Çift bağlı liste
  - `next` yanında `previous` bağlantısının da tutulmasıyla iki yönlü gezinmenin mümkün olduğu açıklanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dizi ve bağlı liste aynı problemi farklı maliyetlerle çözer.
  - Dizide erişim hızlıdır; bağlı listede ekleme ve silme belirli durumlarda daha esnek olabilir.
- İşaretçi güncelleme sırası önemlidir.
  - Yanlış sırayla yapılan bağlantı değişiklikleri listenin bir kısmının kaybolmasına yol açabilir.
- `head` kaybedilirse listeye erişim kaybedilir.
  - Bu nedenle başlangıç işaretçisinin korunması temel güvenlik noktasıdır.

## Kısa Tekrar Notları

- Dizi ardışık bellek düzenidir.
- Bağlı liste düğümler ve bağlantılardan oluşur.
- Ekleme ve silmede önceki/sonraki düğüm ilişkisi doğru güncellenmelidir.
- Çift bağlı listede hem ileri hem geri bağlantı vardır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Derste diziler ve bağlı listeler karşılaştırmalı biçimde ele alınır. Dizilerde bir elemana indisle doğrudan erişmek kolaydır; fakat araya eleman eklemek veya ortadan eleman silmek, kalan elemanların kaydırılmasını gerektirebilir. Bağlı listelerde ise elemanlar bellekte ardışık olmak zorunda değildir; bağlantılar yapının mantıksal sırasını belirler. Sıralı bir bağlı listeye ekleme yapılırken uygun konum bulunur, yeni düğümün bağlantısı ayarlanır ve önceki düğüm yeni düğümü gösterecek şekilde güncellenir. Silmede ise hedef düğüm liste dışına alınır ve bellek güvenliği için serbest bırakılır.
