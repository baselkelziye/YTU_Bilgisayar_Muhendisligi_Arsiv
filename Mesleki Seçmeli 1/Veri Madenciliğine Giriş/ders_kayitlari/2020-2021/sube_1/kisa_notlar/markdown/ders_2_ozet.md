# Ders 2 Çalışma Özeti

## Genel Konular

- Ham verinin yapısı ve veri türleri
  - Veri seti bir tablo (matris) olarak düşünülür: satırlar örnekleri (sample, case, tuple), sütunlar öz nitelikleri (feature, attribute, variable) gösterir; her hücre o örneğin o öz nitelikteki değeridir.
  - En yaygın iki veri türü sayısal (numeric) ve kategorik (categorical) veridir (ekrandan, 00:15:00).
  - Sayısal veride iki ilişki vardır: sıra ilişkisi (değerler sıralanabilir) ve uzaklık ilişkisi (iki değer arasındaki uzaklık ölçülebilir).
  - Kategorik veride (göz rengi, cinsiyet, vatandaşlık ülkesi, düşük/orta/yüksek gelir aralığı) yalnız eşitlik ilişkisi kullanılabilir: iki değer ya eşittir ya değildir.
  - Kategorik değerler bazı veri setlerinde sahte (dummy) ikili değişkenlerle kodlanır; örneğin bir arabanın renk öz niteliği birkaç ikili sütunla gösterilir.
- Sürekli ve ayrık değişkenler
  - Sürekli (nicel, metrik) değişkenler aralık (interval) ya da oran (ratio) ölçeğiyle ölçülür.
  - Ayrık (nitel) değişkenler metrik olmayan iki ölçekten biriyle ölçülür: nominal ya da ordinal (ekrandan, 00:20:00).
  - Nominal ölçek sırasızdır: müşteri tipi (residential, commercial, industrial) A/B/C ya da 1/2/3 diye kodlansa da bu sayıların metrik anlamı yoktur; posta kodu da nominaldir.
  - Ordinal ölçek sıralı ayrık kademelerden oluşur: sınıftaki sıralama, altın/gümüş/bronz madalya. Sıra bilinir ama iki sıra arasındaki uzaklık ölçülemez.
- Ham verinin özellikleri
  - Ham veri genelde büyüktür, çoğu insanla ilgilidir ve dağınık (messy) olabilir (ekrandan, 00:25:00).
  - Eksik değer, bozulma (distortion), yanlış kayıt (misrecording) ve yetersiz örnekleme (inadequate sampling) baştan beklenmelidir.
  - Hiçbir sorun göstermeyen ham veri şüphe uyandırmalıdır; büyük olasılıkla daha önce temizlenmiş ve ön işlenmiştir.
  - Yetersiz örnekleme örneği: yarının sıcaklığını tahmin etmek için bugün sabah, öğle ve akşam alınan üç ölçüm yetmeyebilir; örnekleme sıklığı problem için yeterli olmalıdır.
- Normalizasyon (ilk dönüşüm adımı)
  - Amaç, her sayısal öz niteliği $[0,1]$ ya da $[-1,1]$ gibi sabit bir aralığa taşımaktır (ekrandan, 00:30:00).
  - Uzaklık temelli yöntemler normalizasyon olmadan büyük ölçekli öz niteliklere fazla ağırlık verir.
  - Üç yöntem: ondalık ölçekleme (decimal scaling), min-max normalizasyonu ve standart sapma normalizasyonu (z-score).
- Veri yumuşatma (data smoothing)
  - Birbirine çok yakın değerleri tek bir temsilci değerle göstermek; yuvarlama en basit yumuşatmadır.
  - Yöntemler: kovalama (binning), regresyon, kümeleme, bilgisayar ve insan incelemesinin birlikte kullanılması.
  - Kovalamada veri sıralanır, kovalara bölünür (eşit genişlik ya da eşit derinlik), sonra her kova ortalamayla ya da kova sınırlarıyla yumuşatılır.
- Farklar ve oranlar (differences and ratios)
  - Var olan öz niteliklerin farkı ya da oranı ile yeni bir öz nitelik üretilir; bu bir öz nitelik çıkarımıdır (feature extraction).
  - Örnek: boy ve kilodan vücut kitle indeksi (BMI).
- Eksik veri (missing data)
  - Eksik değerleri sabitlerle otomatik doldurma: tek bir global sabit, öz niteliğin ortalaması, öz niteliğin sınıf içi ortalaması.
  - Örnek tabloda eksik veri hem örnek (case) bazında hem değişken bazında yüzde olarak incelenir; çok eksik olan öz nitelik ve örnekler veri setinden çıkarılabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Standart sapmanın hesabı
  - Her değerden ortalama çıkarılır, farkların kareleri toplanır, örneklem (sample) üzerinde çalışılıyorsa $n-1$'e bölünerek varyans, karekökü alınarak standart sapma bulunur.
  - Hoca, standart sapma ve varyansın ne işe yaradığının ve nasıl hesaplandığının her mühendisin bilmesi gereken bir konu ve bir mülakat sorusu olduğunu söyledi.
- Ondalık ölçeklemenin zayıflığı
  - Değerler $[-1,1]$ aralığının yalnız küçük bir bölümüne sıkışır, ayırt edicilik azalır; tek bir aykırı değer (örneğin 1050) bölen sayıyı 10000'e çıkarıp aralığı daha da daraltır.
- Z-score normalizasyonunun adı
  - Standart sapma normalizasyonu literatürde daha çok "z-score normalization" adıyla geçer; hoca bunu not almalarını istedi ve üç yöntem içinde en iyi sonucu verenin bu olduğunu söyledi.
- Min-max dönüşümü bir doğru denklemidir
  - İki nokta (min → alt sınır, max → üst sınır) bilindiği için doğru denklemi yazılarak her aralık için dönüşüm bulunabilir.

## Kısa Tekrar Notları

- Satır = örnek, sütun = öz nitelik.
- Sayısal veri: sıra + uzaklık ilişkisi; kategorik veri: yalnız eşitlik ilişkisi.
- Nominal: sırasız (müşteri tipi, posta kodu); ordinal: sıralı ama uzaklık yok (madalya sırası).
- Ondalık ölçekleme: $v'(i) = v(i)/10^k$, $k$ en küçük ve $\max |v'(i)| < 1$ olacak şekilde.
- Min-max $[0,1]$: $v'(i) = \dfrac{v(i)-\min}{\max-\min}$.
- Min-max $[-1,1]$: $(\min,-1)$ ve $(\max,1)$ noktalarından geçen doğru.
- Z-score: $v' = \dfrac{v - \text{ortalama}}{\text{std}}$; dağılım orijine kayar, değer ortalamadan kaç standart sapma uzakta olduğunu söyler.
- Eşit genişlik: $W = (B-A)/N$; eşit derinlik: her kovada yaklaşık aynı sayıda örnek.
- Kova sınırlarıyla yumuşatmada her değer en yakın sınıra taşınır; uzaklık eşitse iki sınırdan biri seçilebilir.
- Eksik değer doldurma: global sabit < öz nitelik ortalaması < sınıf içi ortalama (sınıf etiketi varsa).

## Detaylı Açıklamalar

- Normalizasyon neden gerekir?
  - Bir bankanın müşteri verisinde yaş küçük bir aralıkta, yıllık gelir çok büyük bir aralıkta değişir. Müşteriler arası uzaklık hesaplanırken büyük ölçekli gelir öz niteliği uzaklığı belirler, yaşın etkisi neredeyse kaybolur. Bu yüzden her sütun aynı sabit aralığa getirilir.
  - Bir öğrenci aralık $[-1,1]$ yerine $[-10,10]$ olsa ne olacağını sordu. Hoca, bütün öz nitelikler aynı aralığa getirildiği sürece aralığın genişliğinin önemli olmadığını, ondalıklı sayıların hassasiyetiyle aynı uzaklıkların ölçülebileceğini söyledi.
- Ondalık ölçekleme örneği (ekrandan, 00:35:00 ve 00:40:00)
  - Veri setindeki en büyük değer 455, en küçük değer −834 ise en büyük mutlak değer 834'tür; $\max|v'| < 1$ için 1000'e bölünür, $k = 3$. Sonuç: $-834 \to -0.834$, $455 \to 0.455$.
  - En büyük değer 1050 olsaydı 10000'e bölmek gerekirdi ($k=4$): $-834 \to -0.0834$, $455 \to 0.0455$. Değerler aralığın çok dar bir bölümüne sıkışır. Bir öğrenci ayrıca bu yöntemin dağılımı değiştirmediğini ve aykırı değerleri ortadan kaldırmadığını ekledi; hoca onayladı.
  - Slayttaki ikinci örnek: 150 ile 250 arasındaki bir öz nitelik ondalık ölçeklemeyle 0.15–0.25 arasına düşer (ekrandan, 00:45:00).
- Min-max normalizasyonu
  - Formül $v'(i) = \dfrac{v(i) - \min(v(i))}{\max(v(i)) - \min(v(i))}$. Min ve max veri setinden otomatik hesaplanabilir ya da alanın uzmanı tarafından tahmin edilebilir (ekrandan, 00:45:00).
  - Dönüşüm doğrusaldır: x ekseni girdi değeri, y ekseni normalize değerdir. $(x_1,y_1)=(\min,0)$ ve $(x_2,y_2)=(\max,1)$ noktalarından geçen doğru dönüşümün kendisidir. $[-1,1]$ için ilk nokta $(\min,-1)$ olur.
- Standart sapma (z-score) normalizasyonu (ekrandan, 01:10:00)
  - Ortalama çıkarılınca dağılım orijine kayar; standart sapmaya bölününce değer, ortalamadan kaç standart sapma ($s$, $2s$, $3s$) uzakta olduğunu gösterir. Dağılımın büyük kısmı yaklaşık $-3s$ ile $+3s$ arasındadır.
- Derste çözülen örnek (ekrandan, 01:15:00, 01:30:00)
  - $X = \{3,1,0,2,7,6,4,-2,10,12\}$; $v=0$ ve $v=6$ normalize edilecek. Min $=-2$, max $=12$.
  - $[0,1]$: $v' = (v+2)/14$ → $0 \to 2/14 = 1/7 \approx 0.143$, $6 \to 8/14 = 4/7 \approx 0.571$ (sonuçlar python ile hesaplandı).
  - $[-1,1]$: doğru denklemi $\dfrac{x-x_1}{x_1-x_2} = \dfrac{y-y_1}{y_1-y_2}$, noktalar $(-2,-1)$ ve $(12,1)$ → $y = (x-5)/7$; $0 \to -5/7$, $6 \to 1/7$.
  - Z-score: ortalama $4.3$, standart sapma yaklaşık $4.44$ ($n-1$ ile, python: $4.448$). $0 \to (0-4.3)/4.448 \approx -0.967$, $6 \to (6-4.3)/4.448 \approx 0.382$ (sonuçlar derste söylenmedi, python ile hesaplandı).
- Veri yumuşatma (ekrandan, 01:35:00)
  - Slayt örneği: $F = \{0.93, 1.01, 1.001, 3.02, 2.99, 5.03, 5.01, 4.98\}$ yuvarlanarak $\{1.0,1.0,1.0,3.0,3.0,5.0,5.0,5.0\}$ olur; farklı değer sayısı üçe iner. Ama her yumuşatma yuvarlamayla yapılamaz, ek yöntemler gerekir.
  - Kovalama (binning, Türkçede "sepet" gibi düşünülebilir) iki adımdır: veriyi sırala ve kovalara böl; her kovayı bir temsilci değerle yumuşat.
  - Eşit genişlik (equal-width): $N$ aralık, $W = (B-A)/N$; en basit yöntemdir ama aykırı değerler baskın olabilir, çarpık veri iyi işlenmez (ekrandan, 01:40:00).
  - Eşit derinlik (equal-depth, equal-frequency): her kovada yaklaşık aynı sayıda örnek olur; iyi ölçekleme sağlar, kategorik öz niteliklerde zor olabilir.
- Kovalama örneği (ekrandan, 01:45:00)
  - Sıralı fiyat verisi: 4, 8, 9, 15, 21, 21, 24, 25, 26, 28, 29, 34 (12 örnek, 3 kova → kova başına 4).
  - Kovalar: {4, 8, 9, 15}, {21, 21, 24, 25}, {26, 28, 29, 34}.
  - Ortalamalarla: {9,9,9,9}, {23,23,23,23}, {29,29,29,29}.
  - Sınırlarla: {4,4,4,15}, {21,21,25,25}, {26,26,26,34}. Örneğin 8'in sol sınıra uzaklığı 4, sağ sınıra 7 olduğu için 4'e; 9'un uzaklıkları 5 ve 6 olduğu için 4'e taşınır.
  - Yumuşatma bir hata üretir; bu hata ortalama mutlak hata (mean absolute error) ile ölçülür: farkların mutlak değerleri toplanır, eleman sayısına bölünür.
  - Ders sonrası not: 2. ve 3. kovaların gerçek ortalamaları 22.75 ve 29.25'tir; slayttaki 23 ve 29 değerleri yuvarlanmıştır.
- Farklar ve oranlar (ekrandan, 01:55:00, 02:15:00)
  - Küçük öz nitelik dönüşümleri veri madenciliği başarısını önemli ölçüde artırabilir; fark ve oran dönüşümleri özellikle çıktı öz niteliklerinde, ama girdilerde de işe yarar.
  - Bir öz niteliğin zaman içindeki değişimi ya da farklı girdi öz niteliklerinin birleşimi olarak kullanılabilirler.
  - Boy ve kilo ayrı ayrı yerine ikisinden üretilen BMI daha fazla bilgi verir. Hoca, göz ile ilgili bir tıbbi veri setinde sol ve sağ göz ölçümlerinden benzer şekilde yeni öz nitelikler üretildiğini de örnek verdi. Alan uzmanı fark ve oranlarla ek öz nitelikler üretmeye karar verebilir.
- Eksik veri (ekrandan, 02:20:00)
  - Tek bir global sabitle doldurma en basit ama iyi olmayan çözümdür; sabitin seçimi uygulamaya çok bağlıdır.
  - Öz nitelik ortalamasıyla doldurma daha iyidir.
  - Sınıf etiketli (eğitim) veride, eksik değer o örneğin sınıfındaki ortalamayla doldurulabilir.
- Eksik veri tablosu örneği (ekrandan, 02:25:00)
  - 20 örnek, 5 sayısal öz nitelik ($V_1$–$V_5$), sınıf etiketi yok. Toplam 23 eksik değer (%23). Değişken bazında eksik sayısı: $V_1$: 2 (%10), $V_2$: 2 (%10), $V_3$: 11 (%55), $V_4$: 6 (%30), $V_5$: 2 (%10).
  - $V_3$'ün yarıdan fazlası eksik olduğu için öz nitelik olarak çıkarılabilir; 13. örnekte (%80 eksik) ve 15. örnekte (%60 eksik) çok değer eksik olduğu için bu örnekler de çıkarılabilir. <!-- BELİRSİZ: 02:34 civarında 3. örneğin de çıkarıldığı ve bir yüzde değerinin söylendiği anlaşılıyor; altyazı bozuk. -->
  - Gerçek bir veri setinde 200'den fazla öz nitelik içinde zorunlu olmayan "eğitim düzeyi" alanının yaklaşık %70'inin boş olduğu bir örnek verildi; böyle bir öz niteliği çıkarmak zor ama gerekebilecek bir karardır.
  - 18. örneğin $V_4$ değeri eksiktir: sınıf etiketi yoksa $V_4$ sütununun ortalamasıyla doldurulur; ilk 10 örnek "sağlıklı", 11–20 "sağlıksız" sınıfındaysa 11–20 arasındaki örneklerin $V_4$ ortalamasıyla doldurulur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
