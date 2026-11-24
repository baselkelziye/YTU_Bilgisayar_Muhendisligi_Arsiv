# Ders 8 Çalışma Özeti

## Genel Konular

- Kaynak ve konu
  - Ders, MMDS kitabının (Mining of Massive Datasets) 6. bölümü olan sık öğe kümeleri (frequent itemsets) konusunu işler (ekrandan, 00:05:00).
  - Ana başlıklar: pazar sepeti modeli (market-basket model), birliktelik kuralları (association rules), A-Priori algoritması ve büyük veri için iyileştirmeleri (PCY, çok aşamalı, çok karmalı).
  - Hoca, A-Priori'yi veri madenciliği gibi derslerden bilenler için bu derste algoritmanın büyük veri üzerinde nasıl uygulanacağına odaklanacağını söyler.
- Pazar sepeti modeli
  - Büyük bir öğe (item) kümesi vardır; örneğin süpermarkette satılan ürünler.
  - Büyük bir sepet (basket) kümesi vardır; her sepet öğelerin küçük bir alt kümesidir, örneğin bir müşterinin bir günde aldıkları (ekrandan, 00:10:00).
  - Kasada birlikte ödenen ürünler tek bir işlem (transaction) oluşturur. Amaç, birlikte sık satılan öğe kümelerini bulmaktır.
- Destek (support) ve sık öğe kümesi
  - Bir öğe kümesinin desteği, o kümenin tüm öğelerini içeren sepet sayısıdır.
  - Destek bir eşiğin (support threshold) üzerindeyse küme sıktır. Eşik sepet sayısı olarak (örneğin 3 ya da 100) ya da yüzde olarak (örneğin %90) verilebilir.
  - Tek öğe sıksa "sık öğe", iki öğe birlikte sıksa "sık ikili öğe kümesi" denir.
  - Örnek: öğeler {milk, coke, pepsi, beer, juice}, destek = 3 sepet, 8 sepet; sık kümeler {m}, {c}, {b}, {j}, {m,b}, {b,c}, {c,j} (ekrandan, 00:15:00).
- Uygulamalar
  - Ürünler öğe, sepetler ürün kümesi: bebek bezi ve birayı birlikte alanlar örneği; pazarlama ve fiyatlama kararı için kullanılır.
  - Sepetler cümle, öğeler o cümleleri içeren belgeler: birlikte çok sık görülen belgeler kopya (replica) ya da intihal (plagiarism) olabilir. Öğelerin sepetin "içinde" olması gerekmez (ekrandan, 00:20:00).
  - Sepetler kısa belgeler (örneğin tweet), öğeler kelimeler: birçok tweet'te birlikte geçen kelimeler önemli bir haberi gösterebilir.
- Problemin ölçeği
  - Fiziksel bir mağaza yaklaşık 100.000 ürün satar ve milyarlarca sepet saklayabilir; web'de milyarlarca kelime ve sayfa vardır (ekrandan, 00:25:00).
  - E-ticarette ürün sayısı milyarlar, işlem sayısı çok daha büyüktür; problem web ortamında çok büyür.
- Birliktelik kuralları ve güven (confidence)
  - Kural biçimi: $\{i_1, i_2, \ldots, i_k\} \to j$. Sol taraftaki öğeleri alan kişi büyük olasılıkla $j$'yi de alır.
  - Güven, sol taraftaki öğeleri içeren sepetlerden kaçının $j$'yi de içerdiğini gösterir: $\text{conf}(I \to j) = \dfrac{\text{support}(I \cup \{j\})}{\text{support}(I)}$.
  - Örnek: $\{m, b\} \to c$ kuralının güveni $2/4 = \%50$ (ekrandan, 00:30:00).
- Birliktelik kurallarını bulma adımları (ekrandan, 00:35:00)
  - 1. Desteği en az $cs$ olan bütün kümeleri bul.
  - 2. Desteği en az $s$ olan bütün kümeleri bul.
  - 3. $\{i_1, \ldots, i_k, j\}$ kümesinin desteği en az $cs$ ise, bir öğesi eksik olan hangi alt kümelerin desteğinin en az $s$ olduğuna bak; eksik öğe $j$ olsun.
  - 4. $\{i_1, \ldots, i_k\}$ desteği $s_1 \ge s$, $\{i_1, \ldots, i_k, j\}$ desteği $s_2 \ge cs$ ve $s_2/s_1 \ge c$ ise $\{i_1, \ldots, i_k\} \to j$ kabul edilebilir bir kuraldır.
  - $k+1$ öğeli bir sık kümeden, sağ tarafa her seferinde bir öğe konarak $k+1$ farklı kural denenebilir.
- Verinin diskte saklanması ve maliyet
  - Veri dosyada sepet sepet saklanır; örnekte öğeler pozitif tam sayılar, sepet sınırları $-1$'dir (ekrandan, 00:45:00).
  - Algoritmanın maliyeti disk G/Ç (disk I/O) erişimi, yani veri üzerinden yapılan geçiş (pass) sayısıyla ölçülür. Bellekteki hesaplama süresi disk erişimine göre çok küçüktür.
  - Asıl darboğaz ana bellektir: sayılacak her şeyin sayacı bellekte tutulmalıdır.
- Neden çiftler?
  - Tek öğeleri saymak kolaydır; ama $n$ öğeden $\binom{n}{2} = \frac{n(n-1)}{2}$ çift çıkar ve bunların sayaçları belleğe sığmayabilir.
  - Uygulamada destek eşikleri yüksek (%80, %90) seçildiği için üçlü ve dörtlü sık kümeler nadirdir. Bu yüzden problem sık çiftleri bulmaya indirgenir.
- Saf (naive) algoritma
  - Dosya bir kez okunur, her çiftin sayısı bellekte tutulur; $n$ öğeli bir sepetten iki iç içe döngüyle $n(n-1)/2$ çift üretilir (ekrandan, 00:50:00).
  - $(\#\text{öğe})^2$ ana belleği aşarsa başarısız olur. Öğe sayısı Wal-Mart için 100K, web sayfaları için 100B olabilir.
- Çiftleri bellekte sayma yöntemleri
  - Üçgen matris (triangular matrix): olası her çift için 4 bayt; çift veride hiç geçmese de yer ayrılır (ekrandan, 00:55:00).
  - Öğeler 1, 2, ... diye numaralanır, $\{i, j\}$ yalnız $i < j$ ise sayılır, çiftler $\{1,2\}, \{1,3\}, \ldots, \{1,n\}, \{2,3\}, \ldots, \{n-1,n\}$ sırasıyla tek boyutlu bir dizide tutulur (ekrandan, 01:00:00).
  - Tablo yöntemi (tabular method): her satır $[i, j, \text{sayı}]$ üçlüsüdür, yalnız veride geçen çiftler için 12 bayt tutulur. Toplam yaklaşık $12p$ bayt, $p$ gerçekten görülen çift sayısı (ekrandan, 01:05:00).
  - Görülen çiftler olası çiftlerin en fazla 1/3'ü ise tablo yöntemi, daha fazlaysa üçgen matris daha az bellek kullanır.
- A-Priori algoritması
  - Monotonluk (monotonicity): bir öğe kümesi sıksa bütün alt kümeleri de sıktır. Tersinden: bir öğe sık değilse onu içeren hiçbir çift sık değildir.
  - Geçiş 1: tek öğeler sayılır, sık öğeler belirlenir.
  - Geçiş 2: yalnız iki öğesi de sık olan çiftler sayılır (ekrandan, 01:20:00).
  - Genel akış: $C_1 \to$ Filtre (sayma) $\to L_1 \to$ Oluştur $\to C_2 \to$ Filtre $\to L_2 \to$ Oluştur $\to C_3 \ldots$; her aday küme için bir geçiş gerekir (ekrandan, 01:25:00).
  - Sorun: sık öğe sayısı büyükse aday çiftler de çok olur ve belleğe sığmayabilir.
- PCY (Park-Chen-Yu) algoritması
  - Geçiş 1'de öğeler sayılırken belleğin boş kalan kısmında bir hash tablosu tutulur; her sepetteki her çift bir kovaya (bucket) eşlenir ve kovanın sayacı bir artırılır.
  - Geçiş 1 sonunda kova sayacı destek eşiğinin altındaysa o kovaya düşen hiçbir çift sık olamaz. Kovalar bit eşleme (bitmap) ile özetlenir: sık kova 1, değilse 0 (ekrandan, 01:30:00).
  - Geçiş 2'de $\{i, j\}$ çifti yalnız $i$ ve $j$ sık öğeyse ve çiftin kovasının bitmap değeri 1 ise sayılır.
  - Sorun: sık olmayan çiftler aynı kovaya düşüp kovanın sayacını eşiğin üstüne çıkarabilir, ya da sık bir çiftle aynı kovaya düşebilir. Bu durumda sık olmayan çiftler yine sayılır.
- Çok aşamalı (multistage) algoritma
  - Üç geçiş yapar. Geçiş 1, PCY gibidir.
  - Geçiş 2'de sık öğeler ve Bitmap 1 hesaplanır; iki öğesi de sık ve Bitmap 1 değeri 1 olan çiftler, farklı bir hash fonksiyonuyla ikinci hash tablosuna eşlenir.
  - Geçiş 3'te Bitmap 2 oluşturulur; çift, iki öğesi sıksa ve iki bitmap'te de 1 ise sayılır (ekrandan, 01:40:00).
  - Dezavantaj: daha az bellekle çalışır ama veri üç kez okunur, yani disk G/Ç ve süre artar.
- Çok karmalı (multihash) algoritma
  - İki geçişte, birden çok bağımsız hash fonksiyonu kullanır. Geçiş 1'de tek öğeler sayılır ve çiftler iki ayrı hash tablosuna eşlenir.
  - Geçiş 2'de sık öğeler ve her tablo için bir bitmap hesaplanır; çift üç koşulu sağlarsa sayılır: iki öğe sık, Bitmap 1 değeri 1, Bitmap 2 değeri 1 (ekrandan, 01:45:00).
  - Hash tablosu sayısı arttıkça gereksiz sayılan aday çift sayısı azalır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu algoritmaların maliyeti disk G/Ç (geçiş) sayısıyla ölçülür
  - Bellekteki hesaplama, diske erişime göre ihmal edilecek kadar ucuzdur; iyi algoritma az geçiş yapan algoritmadır.
- Zor olan, sık öğe kümelerini bulmaktır
  - Sık kümeler bulunduktan sonra kural çıkarmak ve güveni hesaplamak kolaydır. Zor kısım, sepet sayısı çok büyük olduğu için sayaçların belleğe sığmamasıdır.
- Problem sık çiftlere indirgenir
  - Eşikler çok yüksek seçildiği için büyük sık kümeler nadirdir; asıl bellek sorunu çiftlerin sayımındadır.
- İyileştirmelerin ortak amacı
  - Sık olmayacağı önceden bilinen çiftler için bellekte sayaç ayırmamak. PCY bunu bir hash tablosuyla, multistage ek bir geçişle, multihash birden çok hash tablosuyla yapar.
- Takas
  - Multistage daha az bellek kullanır ama bir geçiş fazladır; multihash iki geçişte kalıp birden çok hash tablosu kullanır.

## Kısa Tekrar Notları

- Destek: bir kümeyi içeren sepet sayısı. Destek eşiği karşılanırsa küme sıktır.
- Güven: $\text{conf}(I \to j) = \text{support}(I \cup \{j\}) / \text{support}(I)$.
- Örnek: $\{m,b\} \to c$ için güven $2/4 = \%50$.
- Saf algoritma: tek geçiş, $n(n-1)/2$ çift sayacı; $n^2$ belleği aşınca çalışmaz.
- Üçgen matris: çift başına 4 bayt, bütün olası çiftler. Tablo: görülen çift başına 12 bayt.
- Görülen çiftler olası çiftlerin 1/3'ünden azsa tablo yöntemi daha iyidir.
- A-Priori: monotonluk; 2 geçiş; ikinci geçişte yalnız sık öğelerden oluşan çiftler sayılır.
- PCY: geçiş 1'de çiftler hash kovalarına sayılır; bitmap; geçiş 2'de çift, iki öğesi sık ve kovası sıksa sayılır.
- Multistage: 3 geçiş, iki hash tablosu ve iki bitmap; az bellek, fazla disk G/Ç.
- Multihash: 2 geçiş, ilk geçişte birden çok bağımsız hash tablosu; aday çift sayısı azalır.

## Detaylı Açıklamalar

- Sık öğe kümesi örneğinin çözümü (ekrandan, 00:15:00)
  - Sepetler: $B_1=\{m,c,b\}$, $B_2=\{m,p,j\}$, $B_3=\{m,b\}$, $B_4=\{c,j\}$, $B_5=\{m,p,b\}$, $B_6=\{m,c,b,j\}$, $B_7=\{c,b,j\}$, $B_8=\{b,c\}$; destek eşiği 3 sepet.
  - Tek öğe sayıları: $m$: 5, $c$: 5, $b$: 6, $j$: 4, $p$: 2. Sık öğeler $\{m\}, \{c\}, \{b\}, \{j\}$.
  - Çift sayıları: $\{m,b\}$: 4 ($B_1, B_3, B_5, B_6$), $\{b,c\}$: 4, $\{c,j\}$: 3. Diğer çiftler en fazla 2. Sık çiftler $\{m,b\}, \{b,c\}, \{c,j\}$.
  - Ders sonrası not: Hoca $c$ için $B_1, B_4, B_6, B_8$ sayıp 4 dedi; $B_7=\{c,b,j\}$ de $c$'yi içerdiği için doğrusu 5'tir. Hoca eşik için "üçten fazla" dedi; slayttaki sonuçta $\{c,j\}$ tam 3 sepette geçip sık sayıldığına göre ölçüt "en az 3"tür.
- Güven örneğinin çözümü (ekrandan, 00:30:00)
  - $\{m,b\}$ içeren sepetler $B_1, B_3, B_5, B_6$: 4 sepet (payda).
  - Bunlardan $c$'yi de içerenler $B_1, B_6$: 2 sepet (pay).
  - $\text{conf}(\{m,b\} \to c) = 2/4 = \%50$.
- Saf algoritmanın bellek ihtiyacı
  - Her çift sayacı 4 baytlık tamsayı ise bellek ihtiyacı $4 \cdot \frac{n(n-1)}{2} \approx 2n^2$ bayttır.
  - $n = 100.000$ için $\frac{n(n-1)}{2} = 4.999.950.000$ çift ve yaklaşık 20 GB eder (ara adım eklendi).
  - Ders sonrası not: Hoca 100.000 öğenin ikilileri için "1 milyar çift" dedi; doğrusu yaklaşık 5 milyar çifttir.
- Üçgen matrisi tek boyutlu dizide tutma
  - Çiftler $\{1,2\}, \{1,3\}, \ldots, \{1,n\}, \{2,3\}, \ldots, \{n-1,n\}$ sırasıyla 1'den başlayarak numaralanır ve tek boyutlu bir dizide tutulur.
  - Verilen $(i, j)$ için dizideki konumu bir formülle bulunur ve o hücrenin sayacı artırılır. <!-- BELİRSİZ: formül slaytta gösterildi ama karelerde yok; hoca formülü sesli okumadı. MMDS kitabındaki formül büyük olasılıkla k = (i-1)(n - i/2) + j - i. -->
- A-Priori'de bellekten kazanmak için yeniden numaralama
  - İkinci geçişte yalnız sık öğelerden oluşan çiftler sayılacağı için üçgen matris daha küçük kurulur.
  - Hoca, eski tek boyutlu dizideki konum ile yeni (yalnız sık öğeler için kurulan) dizideki konumu eşleyen bir tablo tutulduğunu anlattı; örneğin eski 1. konum yeni 1. konuma, eski 3. konum yeni 2. konuma karşılık gelir. Böylece aynı formül kullanılıp yeni dizideki sayaca ulaşılır.
- PCY'nin zayıflıkları
  - Sık olmayan birçok çift aynı kovaya düşerse kova sayacı eşiği geçer; bu çiftlerin hiçbiri sık olmasa da ikinci geçişte sayılır.
  - Sık bir çiftle aynı kovaya düşen sık olmayan çiftler de kovanın bitmap değeri 1 olduğu için sayılır.
  - Sonuç: PCY A-Priori'ye göre bellek kazandırır ama hâlâ yanlış pozitif (false positive) aday çiftler için yer ayrılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
