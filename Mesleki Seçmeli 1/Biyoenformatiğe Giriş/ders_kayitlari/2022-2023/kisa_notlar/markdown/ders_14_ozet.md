# Ders 14 Çalışma Özeti

## Genel Konular

- Dönemin genel tekrarı
  - Son derste yeni konu işlenmedi; dönem boyunca anlatılan konular slaytlar üzerinden hızlıca gözden geçirildi: biyoenformatiğin temel tanımları, bilgisayar ve veri temelleri, biyoenformatik veri türleri, programlama, ikili dizi hizalama, dinamik programlama, çoklu dizi hizalama, filogenetik, istatistik ve görselleştirme.
- Temel kavramlar ve bilgisayar temelleri
  - Bilgi, veri, sistem ve bilgi sistemi kavramları; bilgi sisteminin temel elemanı olarak bilgisayar.
  - Ekrandaki örnek sayısal bilgisayar şemasında CPU (denetim birimi + veri yolu), bellek ve giriş/çıkış birimleri yer alır; girişlere klavye, fare, modem, mikrofon, çıkışlara CRT, LCD, modem, hoparlör örnek verilir (ekrandan, 00:15:00).
  - Temel veri tipleri: işaretli/işaretsiz tamsayı (integer) ve kayan noktalı sayı (float). Diğer veri tipleri bunlar kullanılarak kurulur.
- Biyoenformatik veri türleri
  - Veri genel olarak sayısal (numerik) ve sayısal olmayan (kategorik) diye ikiye ayrılır; kategorik veri de nominal ve ordinal olarak alt türlere ayrılır.
  - DNA ve amino asit dizileri harflerle temsil edildiği için kategorik veridir.
  - Kategorik veri sayısal yöntemlerle incelenecekse önce olasılık tabloları (contingency tables), oranlar ve frekanslara dönüştürülür.
- İkili dizi hizalama (pairwise sequence alignment)
  - Nitel (görsel) yöntem: nokta matrisi (dot matrix / dot plot). Nesnel yöntemler: kaba kuvvet (brute force) ve dinamik programlama.
  - Nokta matrisinde rastgele eşleşmelerin yarattığı gürültü kayan pencere (sliding window) ve eşik ile azaltılır.
  - Uzaklık ölçüleri: kategorik veri olduğu için Öklid uzaklığı yerine Hamming uzaklığı, düzenleme (edit) uzaklığı ve Levenshtein uzaklığı kullanılır. Hizalama için özel skor matrisleri vardır.
  - Boşluklar (gap) dizileri eşit uzunluğa getirir; biyolojik olarak ekleme (insertion) ve silmeyi (deletion) temsil eder.
- Dinamik programlama ile hizalama
  - Üç türü işlendi: global hizalama, yerel hizalama (Smith-Waterman) ve örtüşme (overlap) hizalaması.
  - Her birinin farkı başlangıç (ilk satır ve sütun) ve hücre doldurma (özyineleme) kuralındadır; sonunda geri izleme (traceback) ile hizalama çıkarılır.
- Çoklu dizi hizalama (MSA)
  - Dizi sayısı ikiden fazlaysa MSA problemi ortaya çıkar; global ve yerel türleri vardır.
  - Kullanılan algoritmalar sezgiseldir (heuristic), optimum sonucu garanti etmez; çoğu filogenetik ağaç (yol gösterici ağaç) kullanır.
- Filogenetik
  - Ağaç oluşturmanın ne olduğu ve hangi yöntemlerle yapıldığı tekrar edildi.
- İstatistik ve sinyal filtreleri
  - Betimsel (descriptive) ve çıkarımsal (inferential) istatistik; merkezi eğilim ölçüleri, varyans, standart sapma, yüzdelik ve çeyreklikler, histogram.
  - Ortalamanın uygulaması olarak hareketli ortalama (moving average) filtresi, tersi olarak hareketli fark (moving difference) filtresi ve hareketli medyan filtresi.
- Görselleştirme
  - Bilgisayar biliminin önemli bir konusu olarak görselleştirmenin teorik tarafı ve pratik yöntemleri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Temel tanımlar
  - Biyoenformatiğin tanımı ve gen ifadesi gibi temel kavramlar genel ama önemli tanımlardır.
- Veri türünü doğru belirlemek
  - Bir verinin numerik mi kategorik mi, kategorikse nominal mi ordinal mi olduğu bilinmelidir. DNA ve amino asit dizilerinin kategorik veri olduğu ve sayısal analiz için frekansa dönüştürülmesi gerektiği özellikle hatırlatıldı.
- İkili dizi hizalama dersin en önemli konularından biridir
  - Nokta matrisinin kurulması, kayan pencere ile gürültü azaltma ve dinamik programlamanın üç türü ayrıntılı tekrar edildi.
- Nokta grafiklerini yorumlayabilmek
  - Bir bölümün kayarak tekrar etmesi, ekleme/silme (indel) gibi durumlar nokta grafiğinde tanınabilir örüntüler oluşturur; bu örüntüleri yorumlayabilmek gerekir.
- Kod okuma
  - Programlama kısmında verilen bir kodun ne yaptığını söylemek ya da bir işi hangi kodla çözeceğini bilmek beklenir.

## Kısa Tekrar Notları

- DNA ve amino asit dizileri kategorik veridir; sayısal analiz için frekans/oran tablosuna çevrilir.
- Nokta matrisi: $M$ ve $K$ uzunluklu iki dizi için $M \times K$ matris; aynı harfli hücre işaretlenir.
- Kayan pencere: pencere içinde en az eşik kadar eşleşme varsa nokta konur. DNA için daha büyük pencere gerekir; tipik pencere 15, eşik (stringency) 10 (ekrandan, 00:35:00).
- Kategorik dizilerde uzaklık: Hamming, edit, Levenshtein.
- Gap = ekleme ya da silme; diziler eşit uzunluğa gelir.
- Global hizalama başlangıcı: $S_{i,0} = w \cdot i$, $S_{0,j} = w \cdot j$ ($w$: boşluk cezası).
- Global özyineleme: $S_{i,j} = \max\{S_{i-1,j-1} + s(a_i,b_j),\ S_{i,j-1} + w,\ S_{i-1,j} + w\}$ (ekrandan, 00:40:00).
- Yerel hizalama (Smith-Waterman): ilk satır/sütun 0; özyinelemeye 0 eklenir, negatif değer yoktur; geri izleme en büyük değerli hücreden başlar.
- Örtüşme hizalaması: yerel gibi sıfırla başlar, global gibi doldurulur (negatif değerler olabilir).
- MSA algoritmaları sezgiseldir; dinamik programlama teorik olarak optimumu verir ama hesaplama maliyeti çok yüksektir.
- Hareketli ortalama = yumuşatma (alçak geçiren); hareketli fark = keskinleştirme / trend giderme: $Dy_t = y_t - y_{t-1}$, $D^2 y_t = y_t - 2y_{t-1} + y_{t-2}$ (ekrandan, 00:55:00).
- Hareketli medyan filtresi doğrusal olmayan gürültüyü bastırmada etkilidir.

## Detaylı Açıklamalar

- **Nokta matrisi ve kayan pencere.** İki diziden biri satırlara, diğeri sütunlara yazılır ve her hücrede iki harf karşılaştırılır. Aynıysa hücre işaretlenir (elle çizimde çarpı, yazılımda koyu renk), değilse boş bırakılır. Böylece bir benzerlik örüntüsü oluşur. Diziler aynı olsa bile rastgele eşleşen harfler gürültü üretir. Kayan pencerede her hücre için tek harf yerine ardışık bir grup (örneğin üçlü) karşılaştırılır; gruptaki eşleşme sayısı eşiği geçerse (örneğin üçte en az iki) hücreye nokta konur. Uzun dizilerde örneğin 10 elemanlı pencere ve 5 eşleşme gibi farklı ölçütler kullanılabilir. Ekrandaki alıştırma `FKHMEDPLE` ve `FMDTPLNE` dizileri üzerinde bu iki adımı istiyordu (ekrandan, 00:25:00).
- **Dinamik programlamanın iki temel sorusu.** Birincisi başlangıç problemidir: ilk satır ve sütun nasıl doldurulacak? İkincisi her hücrenin skorunu belirleyen özyineleme kuralıdır. Global hizalamada ilk satır ve sütun indeks ile boşluk cezasının çarpımıdır; ceza $-1$ ise $0, -1, -2, \dots$ diye gider. Her hücre; çaprazdaki hücre + eşleşme/eşleşmeme skoru, soldaki hücre + boşluk cezası ve üstteki hücre + boşluk cezası değerlerinin en büyüğüdür. Hangi hücrenin hangisinden geldiği saklanır ve geri izlemede kullanılır.
- **Yerel ve örtüşme hizalaması.** Smith-Waterman algoritmasında ilk satır ve sütun sıfırdır ve maksimum alınırken dördüncü seçenek olarak 0 eklenir; bu yüzden matriste negatif değer olmaz. Geri izleme en yüksek değerli hücreden başlar, işaretçileri izler ve önceki hücreye işaretçi olmayan bir hücreye gelince durur (ekrandan, 00:45:00). Örtüşme hizalaması, aslında aynı dizinin parçaları olan iki diziyi birleştirmek için kullanılır; global ile yerelin karışımıdır.
- **Skor matrisleri ve anlamlılık.** Basit eşleşme/eşleşmeme skoru yerine DNA ya da amino asitlerin özelliklerinden kurulan benzerlik matrisleri kullanılabilir. Bulunan hizalamanın gerçekten anlamlı olup olmadığı istatistiksel yaklaşımlarla test edilir.
- **İstatistik ve filtreler.** Kategorik veride frekanslar ve onlardan elde edilen olasılıklar, numerik veride dağılımı görmek için histogram kullanılır. Farklı ortalamalar (ağırlıklı aritmetik ortalama, kuvvet ortalaması gibi) farklı dağılımlarda tercih edilir. Hareketli ortalama filtresi bir pencere boyunca ortalama alır; görüntüde yumuşatma, eğride trendi görme işi yapar. Hareketli fark filtresi pencere boyunca fark (türev) alır; sinyaldeki DC bileşenini (trendi) siler, hızlı değişimleri gösterir. Veri simetrik değilse ortalama yerine medyan tercih edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
