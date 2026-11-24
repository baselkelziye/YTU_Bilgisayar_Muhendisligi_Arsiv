# Ders 5 Genişletilmiş Notu: Eşikleme, Bağlantılı Bileşen Etiketleme ve Matematiksel Morfoloji

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Güncel Bir Araştırma Örneği: Kişi Yeniden Kimliklendirme
- 2. Temel Görüntü İşleme Konularına Dönüş
- 3. Eşikleme ve Bölütleme
- 4. Eşik Değerinin Seçimi
- 5. Gonzalez ve Woods Küresel Eşikleme Algoritması
- 6. Hazır Eşikleme Yöntemleri
- 7. Bağlantılı Bileşen Etiketleme
- 8. Özyinelemeli Etiketleme Algoritması
- 9. Matematiksel Morfoloji ve Yapılandırma Elemanları
- 10. Aşındırma (Erosion)
- 11. Yayma (Dilation)
- 12. Açma ve Kapama
- 13. Morfolojinin Uygulamaları
- 14. Python ile Morfolojik İşlemler
- 15. Yapılandırma Elemanı Nasıl Seçilir?

## 1. Güncel Bir Araştırma Örneği: Kişi Yeniden Kimliklendirme

Dersin başında bilgisayarla görme alanının en büyük konferanslarından CVPR'ın 2020 bildiri listesi açıldı (ekrandan, 00:15:00). Bu listede yüz bölütleme (face segmentation), görüntü sentezi (image synthesis), çok görüşlü stereo, optik akış gibi çok farklı konularda güncel çalışmalar bulunur. Bu tür bildirileri okumak hem güncel yöntemler hem de alanda kullanılan veri kümeleri (nerede ne var, nasıl erişilir) hakkında fikir verir.

Örnek olarak kişi yeniden kimliklendirme (person re-identification) üzerine, kıyafet değiştiren kişilerden oluşan büyük ölçekli bir veri kümesi tanıtan bir bildiri gösterildi. Problemi şöyle düşünebiliriz: bir kampüste yüzlerce kamera vardır. Bir kişinin sabah kampüs girişindeki kameradan alınan görüntüsüyle gün içinde başka kameralarda görünen kişinin aynı kişi olup olmadığına karar vermek gerekir. Klasik çalışmalar kişiyi büyük ölçüde üzerindeki kıyafetten yakalar. Veri kümesinde kişilerin kıyafet değiştirmesi bu ipucunu ortadan kaldırdığı için problemi zorlaştırır.

Bildiriyi anlamak için yalnız okumakla yetinmemek gerekir: kullanılan veri kümesi incelenebilir, paylaşılmış kod varsa ve dizüstü bilgisayarda çalışacak durumdaysa denenip sonuçları gözlemlenebilir. Makale konuyu yeterince açıklamıyorsa, referans verilen diğer kaynaklara gidip ilgili bölümleri oradan okumak gerekir. Bir bildirinin değerlendirmesinde yapılan iş, kullanılan yöntemler, veri kümesi ve sonuçların klasik algoritmalara göre ne kadar başarılı olduğu üzerinde durulur.

## 2. Temel Görüntü İşleme Konularına Dönüş

Önceki derste görüntü iyileştirme (image enhancement) ve keskinleştirme (image sharpening) konuşulmuştu. Bu derste temel görüntü işleme yöntemlerine üç başlıkla devam edildi: eşikleme (thresholding), bağlantılı bileşen etiketleme (connected component labeling) ve matematiksel morfoloji. Sunum Jupyter Notebook üzerinden yapıldı; notebook'un adı "Thresholding and Mathematical Morphology" idi (ekrandan, 00:25:00).

> **Hocanın vurgusu:** Bilgisayarla görme üzerinde çalışan öğrencilerin zaman zaman çok temel görüntü işleme yöntemlerini bile bilmediği görülüyor. Görüntüyü analiz etmeyi ve üzerinde temel pratik işlemlerin nasıl yapıldığını bilmek ayrı bir yetenek kazandırır.

## 3. Eşikleme ve Bölütleme

Eşiklemede amaç, elimizdeki gri seviyeli görüntüyü siyah-beyaz (ikili, binary) bir görüntüye dönüştürmektir. Arka plandaki pikseller ön plandaki nesnelerden parlaklıkça ayrılabiliyorsa eşikleme aynı zamanda bir bölütleme (segmentation) işlemi olur. Ekrandaki notta eşikleme "en basit bölütleme işlemi" olarak geçer ve şu özellikler sayılır (ekrandan, 00:25:00):

- Gri seviye eşikleme en basit bölütleme işlemidir.
- Birçok nesne ya da görüntü bölgesi, yüzeylerinin sabit yansıtıcılığı ya da ışık soğurması ile karakterize edilir.
- Eşikleme hesaplama açısından ucuz ve hızlıdır.
- Özel donanımla gerçek zamanda kolayca yapılabilir.

Basit sahnelerde eşikleme tek başına tam bir bölütleme sağlayabilir. Görüntü $S$ tane bölgeye ayrılır ve bölgeler birbiriyle kesişmez (ekrandan, 00:25:00):

$$R = \bigcup_{i=1}^{S} R_i, \qquad R_i \cap R_j = \emptyset, \quad i \neq j$$

Görüntü iki bölgeye de, ikiden fazla bölgeye de ayrılabilir; ama genel uygulama iki bölgeye ayırmaktır. Bunun için bir $T$ eşik değeri gerekir. Giriş görüntüsü $f$, çıkış görüntüsü $g$ olmak üzere (ekrandan, 00:25:00):

$$g(i,j) = \begin{cases} 1, & f(i,j) \geq T \\ 0, & f(i,j) < T \end{cases}$$

Yani $T$'den büyük ya da eşit parlaklıktaki pikseller 1 (beyaz), küçük olanlar 0 (siyah) olur ve sıfır-birlerden oluşan bir ikili görüntü elde edilir.

> **Hocanın vurgusu:** Bu kural yalnız arka planı siyah, ön planı beyaz olan görüntüler için geçerlidir. Bazı uygulamalarda arka plan beyaz, nesneler siyahtır; o zaman kural ters çevrilir. Ezbere gitmemek, her problemi kendi durumuna göre değerlendirmek gerekir.

## 4. Eşik Değerinin Seçimi

Derste koyu gri bir zemin üzerinde duran ahşap nesneler görüntüsü kullanıldı. Ön plan ile arka plan arasında belirgin bir parlaklık farkı vardır, ama bazı nesneler daha koyudur ve ahşap yüzeylerde açık-koyu bölgeler bulunur.

- $T = 95$ seçildiğinde 95 ve üstündeki pikseller beyaz, altındakiler siyah oldu. Soldaki görüntüde koyu gri olan arka plan sağda tamamen siyaha döndü. Hiçbir ön plan nesnesi kaybolmadığı için bu değer iyi bir seçimdir. Yine de bir nesnenin gölgeli yan yüzü kısmen arka plana karıştı ve bazı nesnelerin köşeleri yuvarlanmış göründü; bunlar eşiklemenin sıkıntılı yanlarını gösterir.
- $T = 25$ seçildiğinde 25'ten büyük bütün değerler beyaz olduğu için arka planın çok büyük bir kısmı da beyaza döndü. Ekranda bu sonuç "Over Segmentation (25)" diye adlandırılmıştı (ekrandan, 00:30:00).
- $T = 225$ seçildiğinde 225'ten küçük bütün pikseller siyah oldu; ön plan olarak işaretlenmesi gereken alanlar arka plan sayıldı ve nesneler büyük ölçüde kayboldu. Ekranda "Under Segmentation (225)" yazıyordu (ekrandan, 00:30:00).

Peki eşik nasıl seçilmeli? Bir sonraki bölümdeki algoritma bu soruya basit bir cevap verir.

## 5. Gonzalez ve Woods Küresel Eşikleme Algoritması

Gonzalez ve Woods'un kitabında yer alan bu algoritma basit ve kullanışlıdır. Ekrandaki metin şöyledir (ekrandan, 00:35:00):

1. $T$ için bir başlangıç tahmini seç. Önerilen başlangıç, görüntüdeki en küçük ve en büyük parlaklık değerlerinin orta noktasıdır.
2. Görüntüyü $T$ ile böl. Bu iki piksel grubu verir: $G_1$, parlaklığı $\geq T$ olan bütün pikseller; $G_2$, parlaklığı $< T$ olan pikseller.
3. $G_1$ ve $G_2$ bölgelerindeki piksellerin ortalama parlaklıkları $\mu_1$ ve $\mu_2$'yi hesapla.
4. Yeni eşik değerini hesapla:

$$T = \frac{\mu_1 + \mu_2}{2}$$

5. Ardışık iterasyonlardaki $T$ farkı önceden belirlenmiş bir $T_0$ parametresinden küçük olana dek 2-4 adımlarını tekrarla.

Algoritma iteratiftir: yeni bulunan $T$ ile bir önceki $T$ arasındaki fark belli bir seviyenin altına inince sonuca yakınsadığı kabul edilip durulur; fark büyükse 2-4 adımları tekrarlanır. Hocaya göre genelde üçüncü, dördüncü iterasyonda fark oldukça küçülür.

### 5.1 Elle çözülen örnek

Bu algoritma için hazırlanmış, daha önce sınav sorusu olarak sorulmuş bir örnek çözüldü. Soruda 5 satır ve 5 sütundan oluşan, 0-255 aralığında değer alan gri seviyeli bir $f(x,y)$ görüntüsü verilir ve iki şey istenir: algoritmanın akış diyagramı ya da sözde kodu, ve birinci iterasyonun sonundaki küresel eşik değeri.

<!-- BELİRSİZ: 5×5 matrisin bütün değerleri karelerde görünmüyor. Altyazıda yalnız bir kısmı okunuyor (76, 90, 82, 80, 101, 113, 103, 120, 203 gibi). Aşağıdaki ara sonuçlar derste söylenen değerlerdir. -->

- Verilen: 5×5 gri seviye matris.
- 1. adım: Matristeki en küçük parlaklık 76, en büyük parlaklık 203 bulundu. Başlangıç eşiği:

$$T_0 = \frac{76 + 203}{2} = 139{,}5$$

- 2. adım: 139,5'ten büyük ya da eşit pikseller $G_1$'e, küçük pikseller $G_2$'ye alındı. (Derste gruplar önce ters yazıldı, sonra düzeltildi: küçük değerler $G_2$, büyük değerler $G_1$ olur.)
- 3. adım: Her grubun ortalama parlaklığı hesaplandı. Derste öğrenciler $\mu_1 \approx 188{,}1$ ve $\mu_2 \approx 92{,}8$ buldu.
- 4. adım: Yeni eşik:

$$T_1 = \frac{\mu_1 + \mu_2}{2} = \frac{188{,}1 + 92{,}8}{2} = 140{,}45$$

- Sonuç: Birinci iterasyon sonundaki eşik değeri 140,45'tir. Soru yalnız bunu istediği için cevap budur. Hocaya göre 140 civarındaki yeni eşik grupları değiştirmediği için algoritma ikinci iterasyonda sonlanırdı; ikinci iterasyon gerekseydi aynı adımlar tekrarlanırdı.

> **Ders sonrası not:** Başlangıç eşiği derste "139" diye söylendi; $(76+203)/2$'nin tam değeri 139,5'tir. 140,45 sonucu python ile doğrulandı.

> **Hocanın vurgusu:** Bu dersin yazılı sınav kısmında küçük örnek görüntü parçaları üzerinde bu işlemlerin elle nasıl yapıldığı sorulacak.

## 6. Hazır Eşikleme Yöntemleri

### 6.1 Bütün yöntemleri birlikte denemek

scikit-image kütüphanesinde hazır eşikleme yöntemleri vardır. Ekrandaki kod şuydu (ekrandan, 00:35:00 ve 00:50:00):

```python
import matplotlib
import matplotlib.pyplot as plt

from skimage import data
from skimage.filters import try_all_threshold

img = data.page()

fig, ax = try_all_threshold(img, figsize=(10, 8), verbose=False)
plt.show()
```

`try_all_threshold` mevcut eşikleme algoritmalarını ayrı ayrı uygulayıp sonuçları yan yana gösterir: Original, Isodata, Li, Mean, Minimum, Otsu, Triangle ve Yen (ekrandan, 00:45:00 ve 00:50:00). Kullanılan görüntü, bir belgenin taranmış sayfasıdır. Sorun şudur: sayfanın sol tarafı daha gölgeli, sağ tarafı daha aydınlıktır. Bir yöntem karanlık kalan bölgeyi siyaha çevirirse o bölgedeki yazı okunmaz hale gelir. Bu durumu olabildiğince azaltan yöntem tercih edilmelidir. Sonuçlar birbirinden çok farklı değildir.

<!-- BELİRSİZ: Hoca bu noktada "region-based segmentation biraz daha başarılı olmuş" dedi. "Region-based segmentation" ekrandaki belgenin başlık metnidir, bir yöntem adı değildir. Ekranda gölgeli bölgeyi en az siyaha çeviren çıktı büyük olasılıkla Yen yönteminin çıktısıdır. -->

### 6.2 Ortalama (mean) eşiği

Bir eşikleme yönteminin tek başına nasıl uygulandığını göstermek için ortalama yöntemi kullanıldı. Ekrandaki açıklamaya göre bu örnek piksel parlaklıklarının ortalamasını eşik olarak kullanır; bu basit ve "saf" (naive) bir eşik değeridir ve bazen bir başlangıç tahmini olarak kullanılır (ekrandan, 00:45:00). Yöntem kameraman görüntüsüne uygulanarak arka plan ile ön plan ayrıldı.

### 6.3 İki tepeli histogram ve minimum yöntemi

İki tepeli (bimodal) histograma sahip görüntüler için daha özel algoritmalar kullanılabilir. Örneğin minimum algoritması görüntünün histogramını alır ve histogramda yalnız iki tepe kalana kadar onu tekrar tekrar düzleştirir (smoothing). Sonra eşik bu iki tepe arasında uygun bir değer olarak seçilir.

### 6.4 Otsu yöntemi

Mevcut algoritmalar içinde başarılı olanlardan biri Otsu eşiklemesidir. Hoca, Otsu'nun en büyük avantajının daha hızlı sonuca ulaşması (daha az işlemle sonuca götürmesi) olduğunu, bulduğu eşik değeri açısından diğerlerinden çok büyük bir farkı olmadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Otsu yöntemi eşiği, histogramdan hesaplanan sınıflar arası varyansı (between-class variance) en büyük yapan değer olarak seçer. Bunun için iteratif bir tahmin yerine histogramdaki bütün olası eşikler tek geçişte denenebilir; bu yüzden hızlıdır.

> **Hocanın vurgusu:** Eşikleme işleminin ne olduğunu tarif edebilmelisiniz.

### 6.5 Soru-cevap

**Soru:** Taranmış belge örneğinde, keskinleştirme (image sharpening) ile harflerin kenarlarını belirginleştirerek eşiklemeyi kolaylaştırabilir miydik?
**Cevap:** Denenebilir, mümkündür; ama bu gerçekten zor bir örnektir.

Dersin sonunda aynı öğrenci, sohbete yazdığı denemeyi açıkladı: belgedeki yazıyı eşikleme dışında, dikey yöndeki gradyan (vertical gradient) ile kenarları alarak çıkarmaya çalışmış ama başarılı olamamıştı. Hoca sorunun, tarayıcıdan geçirilmiş görüntüdeki gölge problemiyle ilgili olduğunu belirtti.

## 7. Bağlantılı Bileşen Etiketleme

Bağlantılı bileşen etiketleme görüntü işlemenin temel adımlarından biridir. Yine bir ikili görüntü üzerinde çalıştığımızı varsayalım. Bir piksel, kendisiyle aynı değere sahip komşularıyla bir bölge oluşturur. Bu pikseller birbirine bağlantılı oldukları için aynı etiketi almalıdır.

Derste 8 satır ve 8 sütundan oluşan şu ikili görüntü kullanıldı; 1'ler (beyaz) ön planı, 0'lar (siyah) arka planı gösterir (ekrandan, 01:10:00):

```text
a) İkili görüntü            b) Bağlantılı bileşen etiketleri
1 1 0 1 1 1 0 1             1 1 0 1 1 1 0 2
1 1 0 1 0 1 0 1             1 1 0 1 0 1 0 2
1 1 1 1 0 0 0 1             1 1 1 1 0 0 0 2
0 0 0 0 0 0 0 1             0 0 0 0 0 0 0 2
1 1 1 1 0 1 0 1             3 3 3 3 0 4 0 2
0 0 0 1 0 1 0 1             0 0 0 3 0 4 0 2
1 1 0 1 0 0 0 1             5 5 0 3 0 0 0 2
1 1 0 1 0 1 1 1             5 5 0 3 0 2 2 2
```

Sol üstteki 1'lerden oluşan bölge kendi içinde bağlantılıdır ve sağa doğru da kıvrılır; bu bölgedeki bütün pikseller 1 etiketini alır. Sağdaki sütundan aşağı inip alt satırda sola dönen beyaz bölge 2, ortadaki bölge 3, onun sağındaki küçük dikey parça 4, sol alttaki 2×2 blok 5 etiketini alır. Böylece görüntüde birbiriyle bağlantılı beş ön plan bölgesi vardır ve her biri ayrı etiket taşır.

Etiketler sayı olarak tutulabileceği gibi farklı renklere de boyanabilir. Ekrandaki genişletilmiş gösterimde her etiket farklı bir gri tonla boyanmıştı (ekrandan, 01:10:00). Genel kullanım etiket atamaktır, ama renkle görselleştirmek de mümkündür.

> **Ders sonrası not:** Ekrandaki etiketler, aşağıdaki özyinelemeli algoritma python ile yazılıp bu görüntüye uygulanarak doğrulandı. Bu görüntüde 4'lü ve 8'li komşuluk aynı beş bölgeyi verir.

## 8. Özyinelemeli Etiketleme Algoritması

Bağlantılı bileşen etiketleme için özyinelemeli (recursive) bir algoritma vardır. Ekrandaki yordam şöyleydi (ekrandan, 01:15:00): B özgün ikili görüntü, LB etiketlenmiş bağlantılı bileşen görüntüsüdür.

```text
procedure recursive_connected_components(B, LB);
{
  LB := negate(B);
  label := 0;
  find_components(LB, label);
  print(LB);
}

procedure find_components(LB, label);
{
  for L := 0 to MaxRow
    for P := 0 to MaxCol
      if LB[L,P] == -1 then
        {
          label := label + 1;
          search(LB, label, L, P);
        }
}

procedure search(LB, label, L, P);
{
  LB[L,P] := label;
  Nset := neighbors(L,P);
  for each [L',P'] in Nset
    {
      if LB[L',P'] == -1
      then search(LB, label, L', P');
    }
}
```

Adım adım çalışma şöyledir:

- `recursive_connected_components` önce $B$'nin negatifini alır ve etiket matrisi $LB$'yi oluşturur. $B$'de 0'lar ve 1'ler vardır; negatifte 0'lar aynı kalır, 1 olan gözler $-1$ olur. Hoca bunu ekranda $B = [0\ 1\ 1\ 0 \ldots]$ ve $LB = [0\ {-1}\ {-1}\ 0 \ldots]$ diye gösterdi (ekrandan, 01:15:00). $-1$ "henüz etiketlenmemiş ön plan" anlamına gelir. Sonra `label` sıfırlanır ve `find_components` çağrılır.
- `find_components`, $L = 0$'dan `MaxRow`'a kadar bütün satırları ve $P = 0$'dan `MaxCol`'a kadar bütün sütunları tarar. Bir gözde $-1$ bulursa etiketi bir artırır ve `search` yordamını $LB$, `label` ve o gözün satır-sütun numaraları $L, P$ ile çağırır.
- `search`, $LB[L,P]$ gözüne o anki etiketi yazar. Sonra komşuların indekslerini (satır ve sütun numaralarını) `Nset` kümesine koyar. 4'lü komşulukta bunlar kuzey, güney, doğu ve batı komşularıdır; 8'li komşulukta çaprazdaki ara yönler de katılır (ekrandan, 01:20:00).
- `Nset` içindeki her $[L', P']$ komşusu için $LB[L', P'] = -1$ mi diye bakılır. Öyleyse `search` aynı etiketle bu kez $L', P'$ için kendini çağırır. Böylece etiket, bağlantılı bölgenin bütün $-1$ gözlerine yayılır; bölge bitince tarama kaldığı yerden devam eder ve bir sonraki $-1$ yeni bir etiket başlatır.

Algoritma özyinelemeli olduğu için biraz bellek ister, ama hızlı çalışır. Önce 4'lü komşuluk için yazılıp denenebilir, sonra komşuluk tipi parametre yapılarak 8'li komşuluk için de çalıştırılabilir.

**Soru:** Pekiştirmeli öğrenmede (reinforcement learning) de yol bulma, haritalama gibi buna benzer bir şey var; bu algoritma o tür alanlarda mı kullanılıyor?
**Cevap:** Pekiştirmeli öğrenmede daha çok bir ödül mekanizması kullanılır ve çalışma mantığı farklıdır. Benzerlikler olabilir.

**Soru:** Arama kısmında kenar gözlerde sorun olacak gibi görünüyor. Örneğin ilk satırda üst komşuya bakmak için bir önceki satıra gidilecek, ama öyle bir satır yok.
**Cevap:** Doğru. Sınır değerleri için bu durumlar ayrıca değerlendirilmelidir. Bu kontroller `Nset` kümesi oluşturulurken eklenirse sorun olmaz.

### 8.1 Hazır fonksiyon: `measure.label`

scikit-image'de bu iş için geliştirilmiş `skimage.measure.label` fonksiyonu vardır. Derste siyah arka plan üzerinde beyaz nesneler içeren bir görüntüye uygulandı ve sonuç "all labels" ve "blobs labels" diye iki ayrı gösterimle renklendirildi: sarı, yeşil, mavi, mor, kırmızı gibi renklerle her bileşen ayrı renkte gösterildi. Birbirine bağlı parçalar aynı etiketi aldı; birbirine yakın görünen ama bağlı olmayan parçalar farklı renklerde göründü.

## 9. Matematiksel Morfoloji ve Yapılandırma Elemanları

Matematiksel morfoloji, hiç beklenmedik yerlerde işe yarayabilen bir yöntemler topluluğudur. Ekrandaki tanıma göre bu alan, küme teorisinden birkaç basit kavrama dayanan geniş bir operatör yelpazesi sunar. Operatörler özellikle ikili görüntülerin analizinde kullanışlıdır; kenar bulma, gürültü giderme, görüntü iyileştirme ve bölütleme yaygın kullanımlarıdır. En temel iki işlem aşındırma (erosion) ve yaymadır (dilation) (ekrandan, 01:25:00).

Derste ikili morfoloji anlatıldı: giriş görüntüsü ikilidir. Gri seviyeli morfoloji de vardır ve uygulamaları bulunur.

### 9.1 Yapılandırma elemanı

İkili morfoloji işlemlerinin girdileri bir ikili görüntü $B$ ve bir yapılandırma elemanı $S$'dir (structuring element). $S$ genelde daha küçük bir ikili görüntüdür ve daire, kare gibi herhangi bir şekilde olabilir. $S$ ikili görüntüyü yoklayan bir sonda (probe) gibi davranır. $S$'nin bir pikseli merkez (origin) olarak belirlenir (ekrandan, 01:25:00).

Ekrandaki örnek elemanlar şunlardı (ekrandan, 01:25:00):

```text
Box(3,5)        Disk(5)          Ring(5)
1 1 1 1 1       . 1 1 1 .        . 1 1 1 .
1 1 1 1 1       1 1 1 1 1        1 . . . 1
1 1 1 1 1       1 1 1 1 1        1 . . . 1
                1 1 1 1 1        1 . . . 1
                . 1 1 1 .        . 1 1 1 .
```

Boş bırakılan gözler 0'dır; gözü yormamak için işaretlenmemişlerdir, yalnız 1 olan gözler gösterilir. Eleman dikdörtgen, 3×3 kare, disk ya da halka biçiminde olabilir. Slaytta ayrıca 3×3 artı biçimli bir eleman (merkezi ve dört komşusu 1, köşeleri 0) ve elmas (diamond) biçimli bir eleman da gösterildi.

Her yapılandırma elemanının bir merkez noktası olmalıdır. Bu yüzden, filtrelerde olduğu gibi, 3×3, 5×5 gibi tek sayılı boyutlar kullanılır. Slaytlarda merkez noktası siyah bir noktayla işaretlenir.

## 10. Aşındırma (Erosion)

Aşındırma bir küçültme ya da inceltme işlemidir (ekrandan, 01:30:00). Sembolü $\ominus$'dir: $A$ giriş görüntüsü, $B$ yapılandırma elemanı olmak üzere aşındırma $A \ominus B$ diye yazılır.

İşlem şöyle yapılır: yapılandırma elemanının merkez noktası görüntünün 1 olan bir pikseliyle çakıştırılır. Elemanın kapladığı bütün gözler görüntüde de 1 ise merkez pikselin değeri çıkışa aynen aktarılır, yani piksel aşınmaz. Elemanın kapladığı gözlerden en az biri 0 ise merkez piksel aşındırılır ve çıkışta arka plan (0) olur.

### 10.1 Halter şekli örneği

Ekrandaki örnekte $A$ bir halter (dumbbell) şekli, $B$ ise merkezi işaretli artı biçimli bir yapılandırma elemanıdır (ekrandan, 01:30:00). Görüntü, kenarlarda işlem yapılabilmesi için arka plan gözleriyle çevrelenmiştir. Hoca tahtada şu durumları gösterdi:

- Şeklin köşesindeki bir piksele artının merkezi konduğunda, artının kapladığı gözlerden bazıları (örneğin üst ve sol komşu) 0'dır. Bu yüzden merkez piksel aşınır ve sağdaki sonuçta arka plan olur.
- Şeklin içindeki bir piksele konduğunda kuzey, güney, doğu ve batı komşularının hepsi 1'dir; piksel korunur ve çıkışa 1 olarak aktarılır.

Sonuçta halter şekli incelir: ortadaki çubuk bir piksel kalınlığına, iki uçtaki bloklar da daha ince bir hale gelir.

<!-- BELİRSİZ: Hoca blok yüksekliğinin özgün ve aşınmış hallerini "3 piksel" ve "2, 4, 5 piksel" diye saydı; karede ızgara sayılamadığı için kesin piksel sayıları yazılmadı. -->

### 10.2 Kare görüntüyü aşındırma

Ekrandaki ikinci örnek (ekrandan, 01:35:00):

- $A$, $d \times d$ boyutunda, içi 1'lerle dolu bir karedir.
- $B$, $d/4 \times d/4$ boyutunda kare bir yapılandırma elemanıdır.
- Sonuç: $A \ominus B$, her kenardan $d/8$ aşınmış, $3d/4 \times 3d/4$ boyutunda bir karedir.

Neden $d/8$? Elemanın merkezi şeklin kenarına yaklaştıkça elemanın yarısı ($d/8$) şeklin dışına taşar. Merkez, kenara $d/8$'den yakın olduğu sürece elemanın kapladığı gözlerin bir kısmı 0 olur ve piksel aşınır. Bu yüzden dört kenarın her birinden elemanın yarı boyu kadar alan kaybedilir: $d - 2 \cdot d/8 = 3d/4$.

İkinci durumda yapılandırma elemanı $d$ yüksekliğinde ve $d/4$ genişliğindedir. Bu soru derste öğrencilere yorumlatıldı (bkz. Örnek Sorular). Sonuç ortada yatay bir çizgidir: yatayda iki yandan $d/8$ aşınma olur ve genişlik $3d/4$ kalır; dikeyde eleman şekil kadar yüksek olduğu için yukarıdan ve aşağıdan $d/2$ aşınma olur ve yalnız tam ortadaki, bir piksel kalınlığında satır kalır.

### 10.3 Baskılı devre kartı örneği

Bir baskılı devre kartının (PCB) arka yüzündeki bakır bağlantı yollarını gösteren ikili görüntüye 11×11, 15×15 ve 45×45 boyutlarında kare yapılandırma elemanlarıyla aşındırma uygulandı. Eleman büyüdükçe ince yollar kayboldu. 45×45 oldukça radikal bir seçimdir: yalnız ortadaki büyük beyaz bölgenin aşınmış hali kalır, diğer bütün bileşenler yok olur.

## 11. Yayma (Dilation)

Yayma, görüntüdeki nesneyi kalınlaştırır ya da büyütür. Sembolü $\oplus$'dir (lojikteki XOR işaretine benzer). Yapılandırma elemanının merkezi görüntüdeki 1 olan bir pikselle çakıştırılır ve elemanın kapladığı bütün gözler 1 ile doldurulur. Sonra merkez bir sonraki 1 pikseline kaydırılır ve işlem tekrarlanır.

### 11.1 Kare görüntüyü yayma

- $A$, $d \times d$ boyutunda bir kare; $B$, $d/4 \times d/4$ boyutunda kare bir eleman olsun. Yayma sonunda kare soldan ve sağdan $d/8$, yukarıdan ve aşağıdan da $d/8$ genişler.
- Eleman $d$ yüksekliğinde ve $d/4$ genişliğinde ise sonuç yukarıdan $d/2$, aşağıdan $d/2$ genişler; sağ ve sol taraflarda ise genişliğin yarısı kadar, yani $d/8$ genişleme olur.

### 11.2 Kopuk harfleri birleştirme

Ekrandaki örnekte düşük çözünürlüklü, harfleri kırık bir metin görüntüsü vardır. Şu artı biçimli 3×3 yapılandırma elemanıyla yayma uygulanınca kopuk parçalar birleşir (ekrandan, 01:40:00):

```text
0 1 0
1 1 1
0 1 0
```

### 11.3 Adım adım yayma

Tahtada küçük bir ikili görüntü üzerinde 3×3 kare elemanla yayma gösterildi. Elemanın merkezi ilk 1 pikseline konur ve bu pikselin sekiz komşusu 1 ile doldurulur. Sonra merkez bir sonraki 1 pikseline kaydırılır ve onun boş komşuları da doldurulur. Bütün 1 pikselleri için bu yapıldığında şekil her yönde bir piksel genişlemiş olur.

> **Hocanın vurgusu:** Bu işin kağıt üzerinde sınav kısmı da olacak. Verilen bir ikili görüntüye bir yapılandırma elemanıyla arka arkaya aşındırma ya da yayma uygulandığında ne sonuç alınacağını adım adım oluşturabilmelisiniz.

## 12. Açma ve Kapama

İki işlem daha vardır: açma (opening) ve kapama (closing).

- **Açma:** Önce aşındırma, sonra aşındırmanın çıktısına aynı yapılandırma elemanıyla yayma uygulanır: $B \circ S = (B \ominus S) \oplus S$ (ekrandan, 01:45:00). Ekrandaki tanıma göre açma, nesnenin sınırlarını yumuşatır, dar boyunları (isthmus) koparır ve ince çıkıntıları yok eder. Yani küçük çıkıntıları temizlemek ve dar bağlantıları koparmak için kullanılır.
- **Kapama:** Önce yayma, sonra yaymanın çıktısına aynı elemanla aşındırma uygulanır: $B \bullet S = (B \oplus S) \ominus S$ (ekrandan, 01:45:00). Kapama dar kopuklukları birleştirir, yani dar boşlukları ve kopukları kapatmak için kullanılır.

İkisinin kullanım amacı bu şekilde ayrılır. Ekrandaki örnek "Örnek Sorular" bölümünde adım adım verilmiştir.

## 13. Morfolojinin Uygulamaları

### 13.1 Dişli çarklarda kırık diş tespiti

Bir fabrikada üretilen dişli çarkların bazılarında dişler kırık gelebilir. Bant üzerindeki parçalar kamerayla görüntülenir ve kırık dişler arka arkaya uygulanan morfolojik işlemlerle bulunur. Slaytta her adım verilmiştir:

- Önce dişlilerin içindeki vida deliklerinin bulunduğu bölgeler tespit edilir ve delikleri kaplayan bir maske (hole mask, hole ring) ile kapatılır. Bu iki adımın amacı dişlinin içindeki siyah bölgeleri yok etmektir; çünkü yalnız dış çevre hedeflenir.
- $B7$, dişlerin bulunduğu bölgeyi kapsayan halkadır (ekrandan, 01:55:00).
- $B8 = B \text{ AND } B7$: giriş görüntüsüyle halka arasında mantıksal VE işlemi yapılır. Sonuç, dişlerin aralıklı beyaz-siyah noktalar halinde göründüğü çevredir.
- $B9 = B8 \oplus \text{tip\_spacing}$: dişler arası boşluk kadar bir elemanla yayma yapılır; sağlam dişler birleşip kesintisiz bir halka olur, kırık dişin olduğu yerde boşluk kalır.
- $\text{RESULT} = ((B7 - B9) \oplus \text{defect\_cue}) \text{ OR } B9$: halkadan $B9$ çıkarılınca yalnız eksik bölge kalır; bu bölge büyütülüp $B9$ ile birleştirilir ve kırık diş yerinde belirgin bir işaret görünür.

Hoca bu örneği, adım adım hangi işlemlerin yapıldığını göstermesi nedeniyle beğendiğini söyledi: elinizde giriş görüntüsü vardır, ne aradığınızı bilirsiniz ve "neyi temizlersem ne kalır, sonuca nasıl giderim" diye hedef odaklı düşünürsünüz.

### 13.2 Tıbbi görüntü

Bir tıbbi görüntüye önce eşikleme, sonra morfolojik işlem uygulanarak organların daha belirgin biçimde ortaya çıkması sağlandı.

### 13.3 Sınır çıkarma

İkili morfolojik işlemler sınır çıkarma (boundary extraction) için de kullanılabilir: bir nesnenin çevre piksellerini, yani onu çevreleyen pikselleri bulmak. Bunun için hangi morfolojik işlemlerin arka arkaya uygulanacağı öğrencilere soru olarak bırakıldı (bkz. Örnek Sorular).

## 14. Python ile Morfolojik İşlemler

scikit-image'in `morphology` modülü altında `binary_dilation`, `binary_erosion` ve bunların onlarca farklı çeşidi bulunur.

Örnekte önce `bright_square` adlı sentetik bir görüntü oluşturuldu: 5 satır ve 5 sütundan oluşur, ortasında 3×3 boyutunda bir kare (1'ler) vardır. 3×3 kare yapılandırma elemanı (`square(3)`) ile `binary_erosion` uygulandı ve sonuç `imgErosion` olarak yazdırıldı. Ekrandaki çıktı şuydu (ekrandan, 01:50:00):

```text
[[1 1 1]
 [1 1 1]
 [1 1 1]]
[[False False False False False]
 [False False False False False]
 [False False  True False False]
 [False False False False False]
 [False False False False False]]
```

İlk matris yapılandırma elemanı, ikincisi aşındırmanın sonucudur. 3×3 eleman merkez pikselle çakıştırıldığında elemanın kapladığı bütün gözler 1 olduğu için yalnız merkez korunur. Karenin çevre pikselleri için elemanın bir kısmı 0'lara denk geldiğinden bunlar aşınır ve 0 olur. Görüntüler `plt.imshow(..., cmap='gray')` ile yan yana büyütülmüş olarak da gösterildi. Bu sonuç python ile de doğrulandı.

Yayma, açma ve kapama için notebook'ta öğrencilerin kendi kodlarını yazacağı alanlar bırakıldı; açma ve kapama için test görüntüsü öğrenci tarafından oluşturulabilir.

## 15. Yapılandırma Elemanı Nasıl Seçilir?

**Soru:** Dikey, kare gibi farklı yapılandırma elemanları gösterildi. Hangisi hangi durumda tercih edilir?
**Cevap:** Yapılandırma elemanı, uğraşılan nesnenin şekliyle ilişkilendirilmelidir. Dişli örneğinde boşlukları (vida deliklerini) bulmak için bir halka (hole ring) ve delik maskesi kullanıldı. Görüntüde bir disk yakalanmak isteniyorsa disk biçimli bir eleman kullanılır. Elemanın şeklinin görüntüde aranan bölgenin şekline uyması önemlidir. Bir şekli görüntüden kaldırmak isteniyorsa da onunla örtüşecek yapıda bir eleman seçilir. Bunlar basit işlemlerdir ama gerçek çalışmalarda iş görür.

## Örnek Sorular

### Soru 1: Küresel eşik değeri

(derste sözlü ve ekranda, 00:36:05)

Gonzalez ve Woods'un tanımladığı otomatik küresel eşikleme yöntemini verilen 5×5 gri seviyeli $f$ görüntüsüne uygulamak için bir akış diyagramı ya da sözde kod verin. Birinci iterasyonun sonunda küresel eşik değeri nedir?

<!-- BELİRSİZ: Matrisin tamamı karelerde görünmüyor; aşağıda derste bulunan değerler kullanıldı. -->

> **Çözüm (derste verilen):** Sözde kod Bölüm 5'teki beş adımdır. Matristeki en küçük değer 76, en büyük değer 203'tür; $T_0 = (76+203)/2 = 139{,}5$. $T_0$'a göre ayrılan gruplarda $\mu_1 \approx 188{,}1$ ve $\mu_2 \approx 92{,}8$ bulunur. Birinci iterasyon sonundaki eşik $T_1 = (188{,}1 + 92{,}8)/2 = 140{,}45$'tir.

### Soru 2: Kare elemanla aşındırma

(ekrandan, 01:35:00; derste sözlü, 01:32:37)

$d \times d$ boyutunda içi dolu bir kare $A$, $d/4 \times d/4$ boyutunda kare bir yapılandırma elemanı $B$ ile aşındırılıyor. Sonuçta karenin kenarlarından ne kadar alan aşınır ve neden?

> **Çözüm (derste verilen):** Her kenardan $d/8$ aşınır, çünkü yapılandırma elemanının yarısı $d/8$'dir; merkez kenara bundan yakınken eleman şeklin dışına taşar. Geriye $3d/4 \times 3d/4$ boyutunda bir kare kalır.

### Soru 3: Uzun elemanla aşındırma

(ekrandan, 01:35:00; derste sözlü, 01:34:12)

Aynı $d \times d$ kare, bu kez $d$ yüksekliğinde ve $d/4$ genişliğinde bir yapılandırma elemanıyla aşındırılıyor. Sonuç ne olur ve neden?

> **Çözüm (derste bir öğrenci verdi, hoca onayladı):** Genişlik yönünde elemanın yarısı kadar, yani iki yandan $d/8$'er aşınma olur ve genişlik $3d/4$ kalır. Yükseklik yönünde eleman şekil kadar yüksek olduğu için yukarıdan ve aşağıdan $d/2$'şer aşınma olur. Sonuçta ortada, bir piksel kalınlığında yatay bir çizgi kalır.

### Soru 4: Aşındırma, kapama ve açma

(ekrandan, 01:45:00; derste sözlü, 01:45:09)

Aşağıdaki 8×8 ikili görüntüye ($B$) 3×3 kare yapılandırma elemanı $S$ ile aşındırma ($B \ominus S$), kapama ($B \bullet S = (B \oplus S) \ominus S$) ve açma ($B \circ S = (B \ominus S) \oplus S$) uygulayın. Sonuçları kağıt üzerinde bulun.

```text
Özgün görüntü B
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
0 0 0 1 1 1 1 0
0 0 0 1 1 1 1 0
0 0 1 1 1 1 1 0
0 0 0 1 1 1 1 0
0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0
```

> **Çözüm (slaytta verilen):** Sonuçlar slayttaki gibidir (ekrandan, 01:45:00). Görüntü dışındaki gözler 0 kabul edilmiştir.

```text
Aşındırma B ⊖ S      Kapama B • S         Açma B ∘ S
0 0 0 0 0 0 0 0      0 0 0 0 0 0 0 0      0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0      0 1 1 1 1 1 1 0      0 0 0 1 1 1 1 0
0 0 0 0 1 1 0 0      0 0 1 1 1 1 1 0      0 0 0 1 1 1 1 0
0 0 0 0 1 1 0 0      0 0 1 1 1 1 1 0      0 0 0 1 1 1 1 0
0 0 0 0 1 1 0 0      0 0 1 1 1 1 1 0      0 0 0 1 1 1 1 0
0 0 0 0 0 0 0 0      0 0 1 1 1 1 1 0      0 0 0 1 1 1 1 0
0 0 0 0 0 0 0 0      0 0 1 1 0 0 0 0      0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0      0 0 0 0 0 0 0 0      0 0 0 0 0 0 0 0
```

> **Ders sonrası not:** Üç sonuç, görüntü dışı 0 kabul edilerek python ile hesaplandı ve slayttaki sonuçlarla aynı çıktı. Açma, üstteki tek piksel kalınlığındaki satırı ve alttaki küçük çıkıntıyı temizledi; kapama ise sol taraftaki girintileri doldurdu. Kapamada birinci satırın en soldaki pikselinin kaybolması, görüntü dışının 0 kabul edilmesinden kaynaklanır.

### Soru 5: Morfoloji ile sınır çıkarma

(derste sözlü, 01:51:17)

Bir ikili görüntüde nesnenin sınır piksellerini (çevresini) elde etmek için hangi morfolojik işlemleri arka arkaya uygulamak gerekir?

> **Çözüm (derste verilmedi):** Nesne $A$, küçük bir yapılandırma elemanı $B$ (örneğin 3×3 kare) ile aşındırılır ve aşınmış görüntü özgün görüntüden çıkarılır: $\beta(A) = A - (A \ominus B)$. Aşındırma nesnenin dış katmanını sildiği için fark yalnız bu dış katmanı, yani sınırı bırakır. Bu, Gonzalez ve Woods'taki standart tanımdır.

## Dersin Toparlaması

Bu derste temel görüntü işleme yöntemlerinin üç başlığı işlendi. Eşikleme, gri seviyeli bir görüntüyü bir $T$ eşiğiyle ikili görüntüye çeviren en basit bölütleme yöntemidir; eşik çok düşük seçilirse arka plan ön plana karışır, çok yüksek seçilirse nesneler kaybolur. Gonzalez ve Woods'un iteratif küresel eşikleme algoritması eşiği iki grubun ortalamalarının orta noktası olarak günceller; scikit-image'de ise Otsu, Isodata, Li, Mean, Minimum, Triangle ve Yen gibi hazır yöntemler vardır. Gölgeli taranmış belge gibi örnekler tek bir küresel eşiğin sınırlarını gösterir.

Bağlantılı bileşen etiketleme, ikili görüntüde birbirine komşu ön plan piksellerini aynı etiketle gruplar; özyinelemeli algoritma negatif alınmış görüntüyü tarayıp her yeni bölgede etiketi artırarak komşulara yayılır. Matematiksel morfolojide ise bir yapılandırma elemanıyla aşındırma nesneyi inceltir, yayma kalınlaştırır; bunların sırayla uygulanmasıyla açma çıkıntıları temizler, kapama boşlukları kapatır. Dişli çark ve sınır çıkarma örnekleri, yapılandırma elemanını aranan şekle göre seçip işlemleri hedef odaklı arka arkaya uygulamanın gücünü gösterir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
