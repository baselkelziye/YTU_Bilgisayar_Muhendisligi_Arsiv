# Ders 2 Çalışma Özeti

## Genel Konular

- Veri ön işleme konusuna giriş
  - Ders slaytlarının adı "Data Mining: Data Preprocessing"; sayfa altlarında "Data Mining: Preparing the Data" yazıyor (ekrandan, 00:23:15).
  - Bu derste işlenen başlıklar: ham verinin gösterimi ve analizi, normalizasyon teknikleri, öz nitelik dönüştürme (veri yumuşatma, farklar ve oranlar) ve eksik verinin giderilmesi.
  - Zaman serisi (time dependent data) verisinin işlenmesi ve aykırı değer tespiti (outlier detection) de konu listesindedir, ama bir sonraki derse bırakıldı.
- Ham verinin gösterimi (representation of raw data)
  - Veri seti bir matristir: satırlar örnekleri (samples), sütunlar öz nitelikleri (features) gösterir. Her hücre, ilgili örneğin ilgili öz niteliğindeki değerdir (ekrandan, 00:23:15).
  - En yaygın iki veri tipi nümerik ve kategoriktir.
  - Nümerik bir öz nitelikte iki ilişki tanımlıdır: sıralama ilişkisi (order relation) ve mesafe ilişkisi (distance relation).
  - Kategorik öz nitelik örnekleri: arabanın rengi, vatandaşlık, cinsiyet, göz rengi.
- Kategorik verinin sayısal kodlanması ve dummy değişkenler
  - İki değerli kategorik değişken 0/1 ikili değişkene çevrilebilir. N değerli bir kategorik değişken N tane ikili değişkenle kodlanabilir; bunlara istatistikte "dummy variable" denir (ekrandan, 00:25:10).
  - Slayttaki örnek: göz rengi Black = 1000, Blue = 0100, Green = 0010, Brown = 0001 (ekrandan, 00:25:10).
  - Bu sayılar yalnızca bir kategoriyi temsil eder. Sıralama ya da mesafe hesabında kullanılmamalıdır.
- Sürekli ve ayrık değişkenler
  - Sürekli (continuous) değişkenler nicel ya da metrik değişkenlerdir. Aralık ölçeği (interval scale) ya da oran ölçeği (ratio scale) ile ölçülür. İki ölçeğin farkı sıfır noktasının nasıl tanımlandığıdır (ekrandan, 00:26:40).
    - Aralık ölçeğinde sıfır keyfidir. Örnek: Fahrenheit sıcaklık; 80 °F, 40 °F'nin iki katı sıcaklık demek değildir.
    - Oran ölçeğinde mutlak sıfır vardır. Boy, uzunluk ve maaş bu ölçekle ölçülür.
  - Ayrık (discrete) değişkenler nominal ya da ordinal ölçekle ölçülür.
    - Nominal ölçek sırasızdır (orderless). Örnek: müşteri tipi A, B, C ya da 1, 2, 3 ile kodlanabilir, ama bu sayılar yalnızca temsil eder.
    - Ordinal değişken, sıralama ilişkisi tanımlı ama mesafe ilişkisi tanımlı olmayan kategorik değişkendir (ekrandan, 00:30:00).
- Ham verinin özellikleri ve sorunları (ekrandan, 00:32:25)
  - Ham veri setleri genelde büyüktür, çoğu insanla ilgilidir ve dağınık olabilir.
  - Beklenen sorunlar: eksik değerler (missing values), bozulmalar (distortions), yanlış kayıt (misrecording), yetersiz örnekleme (inadequate sampling).
  - Bu sorunların hiçbirini göstermeyen ham veri şüphe uyandırmalıdır. Verinin bu kadar temiz olmasının tek gerçek nedeni, analiste gelmeden önce temizlenip ön işlenmiş olmasıdır.
- Normalizasyon (ekrandan, 00:40:00)
  - Uzaklık hesabına dayanan yöntemler n boyutlu uzayda çalışır. Öz niteliklerin değer aralıkları çok farklıysa büyük değerli öz nitelikler mesafeye baskın olur.
  - Değerler belli bir aralığa, örneğin $[-1, 1]$ ya da $[0, 1]$ aralığına ölçeklenir.
  - Üç teknik: ondalık ölçekleme (decimal scaling), min-max normalizasyonu, standart sapma normalizasyonu (z-score).
- Veri yumuşatma (data smoothing)
  - Çok sayıda farklı değeri, belli aralıkları temsil eden daha az sayıda değerle ifade etmektir.
  - Slayttaki yöntemler: binning, regresyon, kümeleme ve bilgisayar ile insan incelemesinin birlikte kullanılması (ekrandan, 01:26:40).
- Farklar ve oranlar (differences and ratios)
  - İki öz niteliğin farkı ya da oranı alınarak yeni ve daha bilgilendirici bir öz nitelik türetilebilir (ekrandan, 01:40:00).
- Eksik veri (missing data)
  - Otomatik doldurma yöntemleri, sütun ya da satır silme, eksik veri tablosunun incelenmesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Normalizasyonun neden gerektiğini anlamak
  - Amaç, mesafe ve benzerlik hesabında bütün öz niteliklerin etkisini eşitlemektir. Hoca, formülden çok neden ihtiyaç duyulduğunu ve sonucun nasıl yorumlanacağını anlamanın önemli olduğunu söyledi.
- Standart sapma normalizasyonu
  - Hoca üç tekniğin hepsinin bilinmesini, özellikle bunun çok önemli olduğunu söyledi. Kendi çalışmalarında bu yöntemle genelde daha iyi sonuç aldıklarını belirtti.
- Ön işleme adımları alternatifli yapılır
  - Hangi normalizasyonun ya da hangi doldurma yönteminin daha iyi olduğu için kesin kural yoktur. Birden fazla yol denenip sonuçlar karşılaştırılır.
- Eksik veri doldurmada en sağlıklı yöntem
  - Sınıf etiketi varsa eksik değeri, aynı sınıftaki örneklerin o öz nitelik ortalamasıyla doldurmak en doğru yöntemdir.
- Öz nitelik silmek radikal bir karardır
  - Çok eksik olan bir öz nitelik silinebilir, ama bu karar iyi düşünülmelidir. Örnek sayısı azsa örnek silmek de çoğu zaman mümkün olmaz.
- Veri hazırlama emeğin büyük kısmını alır
  - Geçen dersteki gibi, veri madenciliği emeğinin yaklaşık %60'ının bu aşamada harcandığı tekrar hatırlatıldı. Veriyi çeken veri tabanı uzmanıyla aynı dili konuşmak gerekir.
- Yeni öz nitelik türetmek
  - Öz nitelikler ne kadar iyi kurgulanıp türetilirse sonuç o kadar başarılı olur. Örnek: boy ve kilodan beden kitle indeksi.

## Kısa Tekrar Notları

- Satır = örnek (sample), sütun = öz nitelik (feature); hücre = örneğin o öz nitelikteki değeri.
- Nümerik öz nitelik: sıralama ve mesafe ilişkisi var. Ordinal: sıralama var, mesafe yok. Nominal: ikisi de yok.
- Dummy değişken: N değerli kategorik değişken N ikili değişkenle kodlanır. Bu kodlar sıralama ve mesafe için kullanılmaz.
- Aralık ölçeğinde sıfır keyfi (Fahrenheit), oran ölçeğinde mutlak sıfır var (boy, maaş).
- Ham verinin sorunları: eksik değer, bozulma, yanlış kayıt, yetersiz örnekleme.
- Ondalık ölçekleme: $v'(i) = v(i)/10^k$, $k$ en küçük tam sayı öyle ki $\max |v'(i)| < 1$. Dezavantajı: $[-1, 1]$ aralığının küçük bir kısmı kullanılabilir.
- Min-max $[0,1]$: $v' = \dfrac{v - \min}{\max - \min}$. $[-1, 1]$ için iki noktadan geçen doğru denklemi kurulur.
- Z-score: $v' = \dfrac{v - \text{mean}}{\text{sd}}$. Örneklemde sd hesaplanırken $n-1$'e bölünür.
- Binning: veri sıralanır, kutulara bölünür (eşit genişlik ya da eşit frekans), kutu ortalaması, medyanı ya da sınırlarıyla yumuşatılır.
- Eşit genişlik: $w = (B - A)/N$. Eşit frekans: her kutuda olabildiğince eşit sayıda örnek.
- Yumuşatma orijinal değeri değiştirdiği için bir hata doğurur; bu hata ölçülebilir (ör. ortalama mutlak hata).
- Farklar ve oranlar: BMI = kilo / boy$^2$; sağ ve sol göz ölçümlerinin farkı.
- Eksik veri doldurma: global sabit, öz nitelik ortalaması, sınıf içi öz nitelik ortalaması (en sağlıklısı); kategorik öz nitelikte mod; regresyonla tahmin.
- Çok eksikli öz nitelik ya da örnek silinebilir.

## Detaylı Açıklamalar

- **Ordinal değişken ve mesafe.** Slayttaki tanıma göre ordinal ölçek, sıralı ve ayrık derecelerden (örneğin sıralamalar) oluşur. Ordinal değişken, sıralama ilişkisi tanımlı olan ama mesafe ilişkisi tanımlı olmayan kategorik bir değişkendir (ekrandan, 00:30:00). Slayttaki örnek: bir sınıftaki öğrencilerin başarı sırası ya da bir yarışmadaki altın, gümüş, bronz madalyalar. Ölçek doğrusal olmak zorunda değildir: 4. ve 5. sıradaki öğrenciler arasındaki fark, 15. ve 16. sıradakiler arasındaki farkla aynı olmayabilir. Hoca bunu bir koşu yarışıyla açıkladı: yalnızca kimin önce vardığı bilinir, varış süreleri arasındaki fark bilinmez. Geçen dersteki gelir aralığı (20-30K, 30-40K gibi) ya da low, medium, high gibi değerler de böyledir: sıralanabilir ama aralarında mesafe ölçülemez. Slayta göre ordinal değişkenler genelde nümerik bir değişkeni küçük bir aralık kümesine kodlar; örnek olarak yaş için young, middle-aged, old değerleri verilmiş (ekrandan, 00:30:00).
  - Bir öğrenci, mesafe hesaplayabilmek için iki değer arasındaki uzaklığın başka iki değer arasındaki uzaklıkla aynı birimde olması gerekip gerekmediğini sordu. Hoca evet dedi: bu örneklerde aralıklar değişken olduğu için mesafe tanımlanamıyor.
- **Ham veri ve yetersiz örnekleme.** Ham veride eksik değer, bozulma (beklenmedik, garip sayılar) ve yanlış kayıt (5 yerine 50 girilmesi gibi) olabilir. Yetersiz örnekleme için hoca, bireysel emeklilik sisteminde ayrılacak müşteriyi (churn) önceden tespit etmeye yönelik bir çalışmayı örnek verdi. Müşterinin son bir, üç ya da altı aydaki şikayet ve müşteri temsilcisine ulaşma gibi hareketlerine bakılır. Hangi sıklıkta ve ne kadar geriye bakılacağı iyi kurgulanmalıdır; çok uzak geçmişe bakmak da yanlış olabilir. Eksik verinin kaynakları arasında ölçüm alınmamış olması ve kayıt yapan kişinin bir değeri yazmayı atlaması vardır.
- **Ondalık ölçekleme.** Slayttaki formül (ekrandan, 00:41:10): $v'(i) = v(i) / 10^k$; burada $k$, $\max(|v'(i)|) < 1$ olacak şekilde seçilen en küçük sayıdır. Önce veri setindeki en büyük mutlak değer bulunur, sonra ondalık nokta bu değer 1'in altına inene kadar kaydırılır ve aynı bölen bütün değerlere uygulanır. Slayttaki örnek: en büyük değer 455, en küçük değer $-834$ ise en büyük mutlak değer 834'tür; bölen 1000'dir ($k = 3$) ve ölçeklenmiş en büyük mutlak değer 0,834 olur.
  - Ders sonrası not: Hoca 00:42:15'te "en küçük değer 455" dedi; slaytta 455 en büyük değerdir.
  - Dezavantaj (derste sözlü, 00:44:03): En büyük mutlak değer 1001 olsaydı bölen 10.000 olurdu ve değerler 0,1 civarında kalırdı. $[-1, 1]$ aralığının küçük bir bölümü kullanılır, büyük bölümü boş kalır. Min-max slaytı da aynı sorunu gösterir: 150-250 aralığındaki veri bu yöntemle 0,15-0,25 aralığına sıkışır (ekrandan, 00:45:45).
- **Min-max normalizasyonu.** Formül (ekrandan, 00:45:45): $v'(i) = \dfrac{v(i) - \min(v(i))}{\max(v(i)) - \min(v(i))}$. Bu dönüşüm değerleri $[0, 1]$ aralığına yayar. Min ve max ya veri setinden otomatik hesaplanır ya da alan uzmanınca tahmin edilir. $[-1, 1]$ aralığı için en küçük değer $-1$'e, en büyük değer $+1$'e eşlenir; bu iki noktadan geçen doğrunun denklemi dönüşüm formülüdür. Hocaya göre bir sıkıntı şudur: eğitim verisinin aralığına göre kurulan dönüşüm, test verisinde bu aralığın dışında bir değer gelirse $[0, 1]$ dışına taşan bir sonuç verir.
- **Standart sapma (z-score) normalizasyonu.** Formül (ekrandan, 00:48:20): $v'(i) = \dfrac{v(i) - \text{mean}(v)}{\text{sd}(v)}$. Slayttaki örnek: $v = \{1, 2, 3\}$ için ortalama 2, standart sapma 1, normalize değerler $\{-1, 0, 1\}$. Hoca bunu beyaz tahtada bir Gauss eğrisiyle anlattı (ekrandan, 00:50:00): ortalamayı çıkarmak dağılımı sıfır ortalamalı olacak şekilde sola kaydırır; standart sapmaya bölmek, bir değerin merkezden kaç sigma uzakta olduğunu söyler. Normal dağılımın büyük bölümü $\pm 3\sigma$ içindedir. Slayta göre bu yöntem uzaklık ölçüleriyle iyi çalışır, ama veriyi orijinalinden tanınmaz bir biçime sokar. Min-max'ın aksine, aralık dışındaki bir değer burada açıkça aykırı değer olarak görünür.
- **Normalizasyon örneği (ekrandan, 01:14:10).** $x = \{3, 1, 0, 2, 7, 6, 4, -2, 10, 12\}$ için min $= -2$, max $= 12$.
  - $[0,1]$: $v' = (v+2)/14$. $v=0 \Rightarrow 0{,}143$; $v=6 \Rightarrow 0{,}571$.
  - $[-1,1]$: $v' = (v-5)/7$ (ekrandan, 01:20:55). $v=0 \Rightarrow -0{,}714$; $v=6 \Rightarrow 0{,}143$.
  - Z-score: $m = 4{,}3$, $s = 4{,}44$ (ekrandan, 01:23:25), $v' = (v-m)/s$. $v=0 \Rightarrow -0{,}968$; $v=6 \Rightarrow 0{,}383$.
  - $v = 0$ ve $v = 6$ için sayısal sonuçlar derste hesaplanmadı; yukarıdaki değerler python ile hesaplandı. Ortalama, standart sapma ($n-1$ ile) ve iki formül de python ile doğrulandı.
- **Binning ile yumuşatma.** Önce veri sıralanır, sonra kutulara (bin) bölünür, sonra her kutu bir temsilci değerle ifade edilir. Eşit genişlikli bölmede (equal width) en küçük değer $A$ ve en büyük değer $B$ ise kutu genişliği $w = (B-A)/N$ olur. Eşit frekanslı (equal depth) bölmede her kutuya olabildiğince eşit sayıda örnek düşer. Slayttaki örnek (ekrandan, 01:30:00): sıralı fiyatlar 4, 8, 9, 15, 21, 21, 24, 25, 26, 28, 29, 34; üç eşit frekanslı kutu: [4, 8, 9, 15], [21, 21, 24, 25], [26, 28, 29, 34].
  - Kutu ortalamasıyla: 9, 9, 9, 9 / 23, 23, 23, 23 / 29, 29, 29, 29.
  - Kutu sınırlarıyla: 4, 4, 4, 15 / 21, 21, 25, 25 / 26, 26, 26, 34. Her değer hangi sınıra daha yakınsa o sınırla değiştirilir; örneğin 8'in sol sınıra uzaklığı 4, sağ sınıra 7 olduğu için 4 olur.
  - Ders sonrası not: Kutu ortalamaları tam olarak 9; 22,75; 29,25'tir (python ile doğrulandı). Slayt bunları tam sayıya yuvarlamıştır. Hoca 01:31:46'da üçüncü kutuyu "26, 28, 29, 30, 40" diye okudu; slaytta 26, 28, 29, 34 yazıyor.
  - Bir öğrencinin sorusu üzerine (01:35:10) aynı veri eşit genişlikle üçe bölündü: $w = (34-4)/3 = 10$, aralıklar 4-14, 14-24, 24-34.
- **Eksik veri doldurma.** Slayttaki otomatik doldurma yöntemleri (ekrandan, 01:41:45): bütün eksik değerleri tek bir global sabitle doldurmak (sabitin seçimi uygulamaya bağlıdır; hocaya göre pek kullanışlı değildir), eksik değeri öz niteliğin ortalamasıyla doldurmak, eksik değeri aynı sınıftaki örneklerin öz nitelik ortalamasıyla doldurmak (yalnız sınıf etiketi olan veride mümkündür). Hoca örnek olarak hasta ve sağlıklı gruplarda bir kan değerinin her grup içinde ayrı ortalamasının kullanılmasını verdi. Derste konuşulan diğer yollar: kategorik öz nitelikte en sık değer (mod), diğer öz niteliklerden regresyonla tahmin ve çok eksikli örnek ya da öz niteliğin silinmesi. Bazı algoritmalar eksik değerle çalışabilir, bazıları tam veri ister; bu yüzden eksiklerin baştan giderilmesi önemlidir.
- **Eksik veri tablosu (ekrandan, 01:50:00).** 20 örnek ve 5 nümerik öz nitelikten ($V_1$-$V_5$) oluşan tabloda her satır ve her sütun için eksik sayısı ve yüzdesi verilmiştir. Toplam 23 eksik değer vardır (%23). En çok eksik 13. örnekte (4 eksik, %80) ve $V_3$ öz niteliğindedir (11 eksik, %55). 3. ve 15. örneklerde %60 eksik vardır. Tabloda 12. satırın yüzdesi 9 yazılmıştır; hoca bunun yazım hatası olduğunu, 0 olması gerektiğini söyledi.
  - Derste yapılan düzenleme: $V_3$ silindi; 13., 3. ve 15. örnekler silindi; kalan %7,4'lük boşluk hesaplama yöntemleriyle doldurulacak. Kalan 17 örnek ve 4 öz nitelikte 68 hücreden 5'i eksiktir: $5/68 \approx \%7{,}4$ (python ile doğrulandı).
  - Hoca bireysel emeklilik çalışmasında beyana dayalı eğitim durumu sütununun yalnızca %20-30 dolu olduğunu, bu yüzden bu öz niteliği veri setinden çıkarmak zorunda kaldıklarını anlattı.
- **Farklar ve oranlar.** Slayta göre öz niteliklerdeki küçük değişiklikler bile veri madenciliği başarımını belirgin biçimde artırabilir; fark ve oran dönüşümleri özellikle çıkış öz niteliklerine uygulandığında hedef tanımını iyileştirebilir (ekrandan, 01:40:00). Boy ya da kilo tek başına çok şey söylemeyebilir, ama kilonun boyun karesine oranı olan beden kitle indeksi (BMI) kişinin kilolu olup olmadığı hakkında belirgin bir ipucu verir. Hoca ayrıca göz ile ilgili bir tıbbi veri setinde sağ ve sol göz ölçümlerinin farkından öz nitelik türetildiğini anlattı. Bir öğrenci evin metrekare fiyatını benzer bir örnek olarak önerdi; hoca bunun da oran kullanımı olduğunu onayladı.
  - Ders sonrası not: Hoca BMI sınırlarını "18'den ya da 24'ten küçükse normal, 25'in üstündeyse kilolu, 28'in üstündeyse obez" diye söyledi. Dünya Sağlık Örgütünün yetişkin sınıflandırması büyük olasılıkla şöyledir: 18,5'in altı zayıf, 18,5-24,9 normal, 25-29,9 fazla kilolu, 30 ve üstü obez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
