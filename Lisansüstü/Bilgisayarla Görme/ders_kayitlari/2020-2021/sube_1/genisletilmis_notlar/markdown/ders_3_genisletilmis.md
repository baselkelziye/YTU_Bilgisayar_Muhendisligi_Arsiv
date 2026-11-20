# Ders 3 Genişletilmiş Notu: İmge Filtreleme, Konvolüsyon ve Gauss Filtresi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ödev Çözümleri Üzerinden NumPy ile İmge İşleme
- 2. İmge Filtrelemenin Temeli
- 3. Doğrusal Filtrelerle Alıştırma
- 4. Türev Filtresi ve Sobel Kenar Bulucu
- 5. Filtreleme ve Konvolüsyon
- 6. Doğrusal Filtrelerin Temel Özellikleri
- 7. Gauss Filtresi
- 8. Kenarlarda Ne Yapılır?
- 9. Sinüs İmgesi: linspace, meshgrid ve roll
- Örnek Sorular

## 1. Ödev Çözümleri Üzerinden NumPy ile İmge İşleme

Dersin ilk bölümünde önceki ödevin çözümlerine bakıldı. Hoca ödevin asıl amacının NumPy'ı iyi kullanmayı öğrenmek olduğunu söyledi. Çözümleri gezerken Jupyter defterinin (`.ipynb`) avantajını da gösterdi: açıklama, kod ve kodun çıktısı aynı yerde, alt alta görülür. Colab'e özgü paketler (ör. `google.colab.patches`) yerel bilgisayarda çalışmaz. İmge göstermek için `cv2.imshow` yerine Matplotlib kullanmak defterle daha uyumludur.

### 1.1 İmgeyi ters çevirme: flip yerine indeksleme

Çözümlerin çoğu `cv2.flip` ya da `np.flip` kullanmıştı. Hoca bunun yerine NumPy indekslemesiyle ters çevirmeyi istediğini belirtti. Ekranda gösterilen bir çözümde imge yukarıdan aşağıya şöyle ters çevriliyordu (ekrandan, 02:35:00):

```python
resim_ters = original[::-1]
```

Burada `::-1` ilk ekseni (satırları) sondan başa doğru okur. Renkli imgede de çalışır, çünkü yalnız satır sırası değişir, üç renk kanalı yerinde kalır.

### 1.2 Alt örnekleme ile yeniden boyutlandırmanın farkı

Hoca, alt örnekleme (subsampling) ile yeniden boyutlandırmanın (resizing) farkını sordu. Bir öğrenci yeniden boyutlandırmada atılan satır ve sütunların ortalaması alınarak yeni piksel değeri oluşturulduğunu söyledi. Hoca bunu doğruladı ve şöyle toparladı:

- **Alt örnekleme:** Satır ve sütunları atlayarak seçmektir. Yarıya alt örneklemede her ikinci satır ve sütun alınır, boyut düşer. Yalnız bu yapılırsa görüntü "kesik kesik" olur, yapay desenler ortaya çıkar. Bu yüzden genelde üzerine alçak geçiren (low-pass) bir filtre gezdirilerek imge yumuşatılır.
- **Yeniden boyutlandırma:** Daha genel bir işlemdir; alt örnekleme onun yalnız bir alt aracıdır. Yeni hücrelerin değeri filtreleme ya da enterpolasyonla hesaplanır. Farklı algoritmaları vardır; hoca günümüzde yapay zekâ tabanlı yöntemlerin de kullanıldığını söyledi.

Hoca, yarıya alt örneklemeyi NumPy indekslemesiyle yazmayı sordu: imge baştan sona, ama ikişer ikişer alınacak; aradaki 2 adım miktarıdır. Ekrandaki bir çözümde üçte bire alt örnekleme şöyle yazılmıştı (ekrandan, 02:35:00):

```python
resim_3te1 = original[::3, ::3, :]
```

Yarıya alt örnekleme aynı biçimde `image[::2, ::2]` olur. <!-- BELİRSİZ: hocanın 00:37-00:39 arasında yazdığı satırın tam biçimi karede yok; altyazıya göre başlangıç ve bitiş boş bırakılıp adım 2 verilmiş. --> Bir öğrenci `np.delete` ile satır ve sütun silmeyi önerdi; hoca bunun da kullanılabileceğini, ama indekslemeyle seçmenin yeterli olduğunu söyledi.

### 1.3 Dilim (view) ve kopya

Bir öğrenci, dilimlenmiş yeni dizi değiştirilince orijinal dizinin de değiştiğini sordu. Hoca önce `half_image = image[::2, ::2]` sonrası `half_image` değişirse `image`'ın değişmeyeceğini söyledi. Aradan sonra öğrencinin gönderdiği örneğe baktı ve kendini düzeltti: NumPy dilimleri nesnedir ve aynı belleği gösterir, bu yüzden dilimdeki değişiklik orijinale yansır. Bağımsız bir dizi isteniyorsa kopya alınmalıdır (`.copy()`).

> **Ek bilgi (derste anlatılmadı):** Adımlı dilimleme (`a[::2]`) NumPy'da temel indekslemedir ve görünüm (view) döndürür. Buna karşılık bir liste ya da mantıksal dizi ile yapılan "gelişmiş indeksleme" (`a[[0,2,4]]`) her zaman kopya döndürür.

### 1.4 İmgeyi 10 renge indirme

Onlarca bin farklı renk içeren bir imgeyi yalnız 10 renkle göstermek için seçenekler konuşuldu. Hocaya göre iyi bir çözüm, renkleri bir kümeleme algoritmasıyla 10 kümeye ayırmaktır; rastgele 10 renk seçmek de bir yoldur, ama k-means daha iyidir. Ekranda gösterilen çözüm şuydu (ekrandan, 00:35:00):

```python
reshape_image = np.float32(image.reshape((-1,3)))
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.
K = 10
ret,label,center=cv2.kmeans(reshape_image,K,None,criteria,10,cv2.KMEAN
center = np.uint8(center)
res = center[label.flatten()].reshape((image.shape))
```

<!-- BELİRSİZ: ikinci ve dördüncü satırların sonu karede kesik; büyük olasılıkla "1.0)" ve "cv2.KMEANS_RANDOM_CENTERS)" ile bitiyor. -->

Pikseller önce üç sütunlu (R, G, B) bir listeye çevrilir. `cv2.kmeans` 10 küme merkezi bulur. Her piksel kendi küme merkezinin rengini alır ve liste tekrar imge boyutuna getirilir.

Bir öğrenci k-means'in her kanal için ayrı mı çalıştırılacağını sordu. Hoca, kendisi olsa önce tek kanala inip (ya da imgeyi gri seviyeye çevirip) sonra indirgemeyi yapacağını söyledi; gri seviyede üç kanal da aynı olur. Gri seviyeye çevirmenin tartışmalı bir konu olduğunu, farklı yöntemler bulunduğunu belirtti. Ona göre HSV gibi parlaklığı ve renk yoğunluğunu ayrı tutan bir renk uzayına geçip parlaklık bileşenini almak daha doğrudur.

Bir başka çözüm, değerleri 255'e bölüp $[0,1]$ aralığına getirmiş, sonra `np.around` ile bir ondalık basamağa yuvarlamıştı. Hoca debugger ile değişkenleri inceledi: ikinci argüman ondalık basamak sayısıdır, bir basamağa yuvarlayınca değerler 0.1, 0.2 gibi kademelere düşer. Bunu da bir çözüm olarak kabul etti. Renk haritası (colormap) ile göstermek de yalnız görselleştirme amacıyla bir seçenek olarak anıldı.

> **Ders sonrası not:** Bir ondalık basamağa yuvarlama her kanalda 0.0'dan 1.0'a 11 kademe üretir. Üç kanal ayrı yuvarlandığında en çok $11^3$ renk kombinasyonu oluşabilir. Yani bu yöntem tam olarak "10 renk" vermez; k-means ise tam 10 renk verir.

## 2. İmge Filtrelemenin Temeli

Kameralar ve optik konusu okuma olarak bırakıldıktan sonra imge filtrelemeye geçildi. Hoca filtrelemenin çok temel ve önemli bir işlem olduğunu, imgeleri iyileştirmede, gürültüden arındırmada (denoising) ve birçok başka işte kullanıldığını söyledi.

### 2.1 Filtre ve kutu filtresi

Filtre basit bir matristir. Slayttaki filtre $3\times3$'lük, bütün elemanları 1 olan ve önünde $\frac19$ çarpanı bulunan bir matristir (ekrandan, 01:05:00):

$$
g = \frac{1}{9}\begin{bmatrix}1&1&1\\1&1&1\\1&1&1\end{bmatrix}
$$

Öndeki $\frac19$ her elemanla çarpılır, yani her eleman $\frac19$'dur. Bu filtreye kutu filtresi (box filter) denir. $g$ filtre, $f$ orijinal imge, $h$ filtrelemenin sonucunda elde edilen yeni imgedir.

### 2.2 Adım adım filtreleme örneği

Örnek imge $10\times10$ boyutludur ve yalnız 0 (koyu gri) ile 90 (açık gri) değerleri içerir (ekrandan, 01:05:00):

```text
0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0
0  0  0 90 90 90 90 90  0  0
0  0  0 90 90 90 90 90  0  0
0  0  0 90 90 90 90 90  0  0
0  0  0 90  0 90 90 90  0  0
0  0  0 90 90 90 90 90  0  0
0  0  0  0  0  0  0  0  0  0
0  0 90  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0
```

Filtreleme şöyle yapılır:

- Filtre imgenin sol üst köşesine konur.
- Karşılık gelen pikseller çarpılır ve toplanır.
- Sonuç, yeni imgede filtrenin tam ortasına denk gelen piksele yazılır. Filtreler genelde simetrik olduğu için merkez pikselin yeni değeri hesaplanmış olur.
- Filtre bir piksel sağa kaydırılır ve aynı hesap tekrarlanır. Satır bitince bir alt satıra geçilir.

İlk konumda bütün pikseller 0 olduğu için sonuç 0'dır. Bir sağa kayınca pencereye bir tane 90 girer: $90\cdot\frac19=10$, diğer terimler 0, toplam 10. Bir sağa daha kayınca iki tane 90 girer: $10+10=20$. Hoca öğrencilere iki hücreyi sordu. Birinde pencerede beş tane 90 vardır: $5\cdot10=50$. Diğerinde pencerenin tamamı 90'dır: $9\cdot10=90$. Bütün imge gezildiğinde sonuç şudur (ekrandan, 01:10:00; python ile doğrulandı):

```text
 0 10 20 30 30 30 20 10
 0 20 40 60 60 60 40 20
 0 30 60 90 90 90 60 30
 0 30 50 80 80 90 60 30
 0 30 50 80 80 90 60 30
 0 20 30 50 50 60 40 20
10 20 30 30 30 30 20 10
10 10 10  0  0  0  0  0
```

Yeni imge $8\times8$'liktir, çünkü filtre kenar satır ve sütunlarına konduğunda imgenin dışına taşar ve oralara değer yazılamaz. Boyutu $10\times10$ tutmak için farklı yaklaşımlar vardır: yeni imgenin kenarları sıfırla doldurulabilir ya da orijinal imge önce kenar satır ve sütunları tekrarlanarak büyütülür, filtreleme bu büyütülmüş imgede yapılır. Bu konu 8. bölümde tekrar ele alındı.

### 2.3 Filtreleme formülü

Kitaplarda bu işlem şu formülle verilir (ekrandan, 01:05:00):

$$
h[m,n]=\sum_{k,l} g[k,l]\, f[m+k,\, n+l]
$$

Hoca formülü soru işaretli hücre üzerinden açıkladı. Sıfırdan saydığımızda bu hücre 4. satır, 6. sütundadır; yani $h[4,6]$ aranıyor (ekrandan, 01:15:00). Toplam, filtrenin indeksleri $k$ ve $l$ üzerinden alınır. Filtrenin indeksleri merkez 0 olacak biçimde numaralanır: $k$ dikeyde, $l$ yatayda $-1, 0, 1$ değerlerini alır.

- $k=0,\ l=0$ terimi: $g[0,0]\cdot f[4+0,\, 6+0]$, yani filtrenin merkezi ile $f[4,6]$ çarpılır.
- $k=-1,\ l=-1$ terimi: $g[-1,-1]\cdot f[3,5]$, yani filtrenin sol üst elemanı ile pencerenin sol üst pikseli çarpılır.
- Böyle toplam 9 terim vardır ve hepsi toplanır.

Bu hücrede pencerenin tamamı 90 olduğu için $h[4,6]=90$ çıkar.

### 2.4 Kutu filtresi ne yapar?

Kutu filtresi her piksele, çevresindeki $3\times3$ komşuluğun ortalamasını yazar: komşuluktaki dokuz değeri toplayıp 9'a böler. Bu bir yumuşatma etkisidir; kutu filtresi aslında alçak geçiren (low-pass) bir filtredir. Hoca sinyal işleme dersinde bu konuların daha ayrıntılı görüldüğünü söyledi. Slayttaki örnekte kutu filtresiyle yumuşatılmış imge orijinale göre bulanıklaşmıştır.

## 3. Doğrusal Filtrelerle Alıştırma

Hoca birkaç filtre gösterip her birinin imgeye ne yapacağını tahmin etmelerini istedi. Kâğıt kalemle küçük bir imge üzerinde denemenin daha iyi anlaşılacağını ekledi.

### 3.1 Birim filtre

Filtre yalnız ortasında 1, diğer yerlerde 0 olan bir matristir (ekrandan, 01:20:00):

$$
\begin{bmatrix}0&0&0\\0&1&0\\0&0&0\end{bmatrix}
$$

Öğrencilerden "daha net çıkar" ve "orijinalin aynısı çıkar" tahminleri geldi. Doğrusu ikincisidir: filtre yalnız üzerinde bulunduğu pikseli 1 ile çarpar, komşuları 0 ile çarparak görmezden gelir. Hesaplanan piksele kendi değeri yazılır; imge değişmez.

### 3.2 Kaydırma filtresi

Sonraki filtrede tek 1 merkezde değil, merkezin yanındadır. <!-- BELİRSİZ: filtrenin karesi yok; anlatıma göre 1, orta satırın sağ elemanında. --> Bu filtre her pikselin yerine yanındaki pikselin değerini yazar; diğer değerleri çöpe atar. Sonuçta imge bir piksel sola ötelenir. En sağdaki sütun için değer kalmaz, sıfırla dolar (slaytta beyaz gösterilmiş; ne konacağı önceden kararlaştırılan kenar yöntemine bağlıdır). En soldaki sütun ise kaybolur.

### 3.3 Keskinleştirme filtresi

Sonraki filtre iki filtrenin farkı olarak verildi (ekrandan, 01:25:00):

$$
\begin{bmatrix}0&0&0\\0&2&0\\0&0&0\end{bmatrix} - \frac19\begin{bmatrix}1&1&1\\1&1&1\\1&1&1\end{bmatrix}
$$

Birinci filtre orijinal imgenin iki katını alır, ikincisi yumuşatır. Fark, orijinal imgenin iki katından çevre ortalamasını çıkarmaktır. Hoca, "burada iki filtre var, neden böyle düşünebiliyoruz?" sorusunu önceden cevapladı: bu dersteki filtreler doğrusaldır. Önce birinciyle, sonra ikinciyle filtreleyip sonuçları çıkarmak, iki filtrenin farkıyla bir kez filtrelemekle aynıdır.

Fark tek bir filtre olarak yazılırsa (ara adım eklendi): kenar elemanlar $0-\frac19=-\frac19$, merkez $2-\frac19=\frac{18}{9}-\frac19=\frac{17}{9}$ olur:

$$
\frac19\begin{bmatrix}-1&-1&-1\\-1&17&-1\\-1&-1&-1\end{bmatrix}
$$

Bu filtre merkezdeki pikselin önemini artırır, komşuların değerini ortalamadan çıkarır. Adı keskinleştirme (sharpening) filtresidir. Slayttaki açıklaması "accentuates differences with local average": yerel ortalamadan farklı olan pikselleri daha da farklı yapar, farkı öne çıkarır. Yumuşatmanın tersidir; sonuç imgede yerel özellikler belirginleşir, sanki orijinal imge yeni imgenin yumuşatılmış hâliymiş gibi görünür. Hoca bunu yüksek frekansları geçiren (high-pass) bir filtre olarak niteledi.

> **Ders sonrası not:** Hoca keskinleştirme filtresini yüksek geçiren filtre olarak andı. Filtrenin elemanları toplamı 1 olduğu için düşük frekanslar (ör. sabit parlaklık) da olduğu gibi geçer. Yani bu tam bir yüksek geçiren filtre değil, orijinal imgeye yüksek frekansları ekleyerek onları güçlendiren bir filtredir; saf yüksek geçiren kısım "birim filtre eksi kutu filtresi"dir.

### 3.4 Filtre toplamı neden 1?

Slaytta "note that filter sums to 1" yazar. Toplam 1 değilse, örneğin 2 ise, filtreleme imgenin toplam parlaklığını artırır. Böyle bir filtre art arda kullanılırsa imge giderek parlaklaşır. Bu özellikle istenmiyorsa filtre toplamı 1 tutulur.

## 4. Türev Filtresi ve Sobel Kenar Bulucu

### 4.1 Türev filtresi

Sonraki filtrenin bir satırına bakılınca, filtrenin bir taraftaki pikselin değerini diğer taraftakinden çıkarıp sonucu merkeze yazdığı görülür. <!-- BELİRSİZ: filtrenin karesi yok; anlatıma göre orta satırı bir yanda 1, diğer yanda -1, merkezi 0 olan bir filtre. İşaretlerin hangi yanda olduğu karede doğrulanamadı. --> Hoca bunun türev olduğunu söyledi ve türevin tanımını hatırlattı:

$$
f'(x)=\lim_{h\to 0}\frac{f(x+h)-f(x)}{h}
$$

Tek boyutta düşünülürse, $x$ noktasından $h$ kadar ilerlenir ve değişimin $h$'ye oranı alınır; $h$ olabildiğince küçültülür. İmgede ise elimizde ayrık (diskret) bir yapı vardır: $h$'yi 0 yapamayız, çünkü o zaman pikselin kendisini alırız ve hiçbir şey hesaplanmaz. $h$ en az 1 olabilir; yani komşu pikselden pikselin kendisi çıkarılır. Bu durumda simetri kaybolur ve az önceki kaydırma örneğindeki gibi imge kayabilir. Bu yüzden merkezin bir sağındaki pikselden bir solundaki piksel çıkarılır.

Böylece her satırda yatay bir türev alınmış olur. Türev, birim yer değiştirmedeki değişim miktarıdır; değişimin büyük olduğu yerlerde büyüktür. İmgede değişim en çok kenarlarda olur. Slayttaki Einstein fotoğrafında burnun düz bölgesinde değişim olmadığı için sonuç kapkaradır; kulaktan arka plana geçişte beyazdan siyaha büyük bir değişim olduğu için orası kuvvetli çıkmıştır. Grinin bembeyaza geçtiği yerler de güzelce yakalanmıştır. Bir öğrencinin dediği gibi sonuç bir kenar belirleme (edge detection) görüntüsüdür; hocaya göre kenar belirleme zaten türev almanın sonucudur.

### 4.2 Sobel filtresi

Sonraki filtrede orta satırdaki değer 2, kenarlardaki 1'dir. <!-- BELİRSİZ: Sobel filtresinin karesi yok; anlatım "ortadaki sayı 2, kenarlarda 1" diyor. Standart biçim büyük olasılıkla [[1,0,-1],[2,0,-2],[1,0,-1]]. --> Bu filtre yatayda türev alır, dikeyde ise $[1,2,1]$ ağırlıklarıyla yumuşatma (alçak geçiren filtreleme) yapar. Yalnız tek satırlık bir türev filtresi kullanılırsa elde edilen imgede gereksiz ayrıntılar çok olur; dikeydeki yumuşatma bunları azaltır. Filtre, iki ayrı filtrenin (dikey yumuşatma ve yatay türev) birleşimi olarak görülebilir; buna ayrılabilir filtre denir ve Gauss'ta tekrar görülür.

Bu filtreyi popülerleştiren bilim insanının adıyla buna Sobel kenar bulucu (Sobel edge detector) denir. Transpozu dikeyde türev alıp yatayda yumuşatır, yani dikey yöndeki renk değişimlerini bulur. Aynı resimde transpoz filtre uygulandığında bu kez dikey yöndeki değişimlerde kuvvetli cevaplar gelmiştir.

## 5. Filtreleme ve Konvolüsyon

Filtreleme ve konvolüsyon sözleri sık sık birlikte duyulur ve birbirine çok benzer. Filtrelemede filtre (kernel) doğrudan imgenin üzerinde gezdirilir. Konvolüsyonda ise filtre önce ters çevrilir (flip): hem yukarıdan aşağıya hem sağdan sola. Hoca önce "transpoz" dedi, sonra doğru sözün "flip" olduğunu belirtti. Ters çevirdikten sonra yine filtreleme yapılır. Bu yüzden formülde artılar eksiye döner (ekrandan, 01:40:00):

$$
\text{Filtreleme:}\quad h[m,n]=\sum_{k,l} f[k,l]\, I[m+k,\, n+l]
$$

$$
\text{Konvolüsyon:}\quad h[m,n]=\sum_{k,l} f[k,l]\, I[m-k,\, n-l]
$$

Bu slaytta $f$ filtreyi, $I$ imgeyi gösterir. Slayttaki MATLAB karşılıkları `filter2(f,I)` ya da `imfilter(I,f)` (filtreleme) ve `conv2(f,I)` (konvolüsyon), Python için öneri "flip the kernel using `cv2.flip()`" biçimindedir.

Konvolüsyonun matematiksel özellikleri daha uygundur; sinyal işlemede konvolüsyon kullanılır ve aslında doğrusu odur. Pratikte ise genelde simetrik filtreler kullanılır. Hoca simetrik olmayan bir filtreyi hemen hiç kullanmadığını söyledi; simetrik filtrede ters çevirmek bir şey değiştirmediği için filtreleme ile konvolüsyon aynı sonucu verir.

OpenCV'de filtreleme için `cv2.filter2D` vardır: imge ve kernel verilir. Konvolüsyon isteniyorsa önce kernel ters çevrilir, sonra `filter2D` kullanılır. Hoca SciPy'da da doğrudan konvolüsyon yapan bir fonksiyon olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Altyazıda "Convol2D" diye geçen SciPy fonksiyonu büyük olasılıkla `scipy.signal.convolve2d`'dir. `cv2.filter2D` ise adına rağmen korelasyon (filtreleme) yapar; konvolüsyon için kernel `cv2.flip(kernel, -1)` ile iki eksende ters çevrilmelidir.

## 6. Doğrusal Filtrelerin Temel Özellikleri

Bu filtrelerin adı üstünde doğrusal (linear) filtrelerdir. Slaytta şu özellikler verildi (ekrandan, 01:45:00):

- **Doğrusallık (linearity):** `imfilter(I, f1 + f2) = imfilter(I, f1) + imfilter(I, f2)`. İki filtreyi toplayıp filtrelemek ile ayrı ayrı filtreleyip sonuçları toplamak aynıdır.
- **Kayma değişmezliği (shift invariance):** Filtrenin davranışı piksel konumuna bağlı değildir: `imfilter(I, shift(f)) = shift(imfilter(I, f))`. Önce kaydırıp sonra filtrelemek ile önce filtreleyip sonra kaydırmak aynı sonucu verir.
- **Temel sonuç:** "Any linear, shift-invariant operator can be represented as a convolution." Doğrusal ve kayma değişmez her işlem için bir filtre tasarlanabilir ve işlem imgeye konvolüsyonla uygulanabilir. Az önceki türev bunun örneğidir: türev doğrusal ve kayma değişmez bir işlem olduğu için imgeye filtrelemeyle uygulanabildi.

Diğer özellikler:

- **Değişme (commutative):** Filtrelerin sırası değiştirilebilir; önce birinci sonra ikinci filtreyi uygulamakla tersi aynıdır. Hatta imge ile filtrenin rolleri de değiştirilebilir: imgenin filtreyi filtrelediği düşünülebilir. Hoca, OpenCV gibi pratik uygulamaların bu teorik özelliği göz ardı etmiş olabileceğini, buna güvenilmemesi gerektiğini ekledi.
- **Birleşme (associative):** A imgesine art arda B1, B2, B3 filtreleri uygulanacaksa, önce filtreler kendi aralarında birleştirilip tek bir filtre elde edilebilir ve imgeye bir kez uygulanabilir. Bu hız kazandırır.
- **Toplama üzerine dağılma:** Filtreleyip sonra toplamak ile önce toplayıp sonra filtrelemek aynıdır.
- **Skaler dışarı çıkar:** Filtreyi bir sayıyla çarpıp filtrelemek ile filtreleyip sonucu o sayıyla çarpmak aynıdır.
- **Birim eleman:** Birim filtre ile filtrelemek orijinal imgeyi verir (3.1'deki örnek).

## 7. Gauss Filtresi

### 7.1 Tanım ve formül

Gauss filtresi önemli bir alçak geçiren, yani yumuşatan filtredir. Komşu piksellerin katkısını yakınlıklarına göre ağırlıklandırır. Yukarıdan bakıldığında ortası beyaz (yüksek değer), dışa doğru kararan (sıfıra inen) bir leke gibi görünür. Slaytta $5\times5$, $\sigma=1$ bir Gauss filtresinin değerleri verilmiştir (ekrandan, 02:00:00; python ile doğrulandı):

```text
0.003  0.013  0.022  0.013  0.003
0.013  0.059  0.097  0.059  0.013
0.022  0.097  0.159  0.097  0.022
0.013  0.059  0.097  0.059  0.013
0.003  0.013  0.022  0.013  0.003
```

Bu, istatistikteki normal dağılımın iki boyutlu hâlidir; üç boyutlu çizildiğinde çan biçiminde bir yüzey olur. Formülü (ekrandan, 02:00:00):

$$
G_\sigma(x,y)=\frac{1}{2\pi\sigma^2}\, e^{-\frac{x^2+y^2}{2\sigma^2}}
$$

Filtrenin şeklini $\sigma$, yani standart sapma belirler; bu örnekte $\sigma=1$'dir. Standart sapmanın karesi $\sigma^2$ varyanstır. Formül kullanılırken filtrenin koordinat sisteminin merkezi filtrenin ortası alınır: $5\times5$ filtrede satırlar ve sütunlar $-2, -1, 0, 1, 2$ diye numaralanır.

### 7.2 Neden Gauss?

Kutu filtresiyle yumuşatma yapıldığında imgede yapay (suni) yapılar görülür. Gauss filtresinde bu yapay yapılar oluşmaz. Bu yüzden yumuşatmada Gauss tercih edilir; hoca onu ideal bir alçak geçiren filtre olarak niteledi. Slayttaki ifadeyle Gauss filtresi imgeden "yüksek frekanslı" bileşenleri kaldırır, yalnız düşük frekanslı bileşenler kalır ve imge daha pürüzsüz (smooth) olur (ekrandan, 02:05:00).

### 7.3 Gauss ile Gauss'un konvolüsyonu

Bir Gauss filtresi başka bir Gauss filtresiyle konvolüsyona sokulursa yine bir Gauss filtresi elde edilir. Bu sayede Gauss filtreleri art arda kullanılarak piramitler ve ölçek uzayları (scale space) elde edilir ve bunların matematiksel özellikleri güzelce belirlenebilir.

> **Hocanın vurgusu:** Bunu not alın, önemli bir özellik: iki Gauss filtresi arka arkaya uygulandığında yeni Gauss filtresinin varyansı, önceki Gauss filtrelerinin varyanslarının toplamına eşittir.

Yani imge önce varyansı $\sigma_1^2$ olan bir filtreyle, sonra çıkan sonuç varyansı $\sigma_2^2$ olan bir filtreyle filtrelenirse, orijinal imgeyi varyansı $\sigma_1^2+\sigma_2^2$ olan tek bir Gauss filtresiyle filtrelemekle aynı sonuç elde edilir. Dolayısıyla büyük varyanslı bir filtrelemenin sonucu, küçük filtrelerle ardışık filtreleyerek elde edilebilir. Slayttaki karşılığı (ekrandan, 02:05:00): genişliği $\sigma$ olan Gauss ile iki kez konvolüsyon, genişliği $\sigma\sqrt2$ olan Gauss ile bir kez konvolüsyona eşittir; bu, $\sigma^2+\sigma^2=(\sigma\sqrt2)^2$ demektir. Hoca filtre boyutlarının çok önemli olmadığını, asıl önemli olanın varyans olduğunu ekledi.

### 7.4 Ayrılabilirlik

Filtreye kernel de denir. Gauss kernelleri ayrılabilirdir (separable): $5\times5$'lik iki boyutlu filtreyle filtrelemek yerine önce yatay bir 1B filtreyle, sonra dikey bir 1B filtreyle filtrelemek aynı sonucu verir. Matematiksel olarak (ekrandan, 02:10:00):

$$
G_\sigma(x,y)=\frac{1}{2\pi\sigma^2}\exp\!\left(-\frac{x^2+y^2}{2\sigma^2}\right)
=\left(\frac{1}{\sqrt{2\pi}\,\sigma}\exp\!\left(-\frac{x^2}{2\sigma^2}\right)\right)\left(\frac{1}{\sqrt{2\pi}\,\sigma}\exp\!\left(-\frac{y^2}{2\sigma^2}\right)\right)
$$

Tabanları aynı üslü ifadeler çarpılınca üsler toplanır; iki 1B Gauss'un çarpımı bu yüzden 2B Gauss'u verir. Slayttaki açıklama: 2B Gauss, biri yalnız $x$'in, diğeri yalnız $y$'nin fonksiyonu olan iki fonksiyonun çarpımıdır ve burada bu iki fonksiyon aynı 1B Gauss'tur.

Bunun önemi hızdır. Konvolüsyon formülünde filtrenin eleman sayısı arttıkça işlem süresi hızla artar; hoca karmaşıklığın filtre kenar uzunluğunun karesiyle arttığını söyledi. $3\times3$ filtrede piksel başına 9, $5\times5$ filtrede 25 çarpma vardır. Ayrılabilir filtrede ise $5+5=10$ çarpma yapılır; çok daha hızlı çalışır. Slayttaki örnekte filtre bir sütun ve bir satır vektörüne ayrılıyor, önce yatay, sonra dikey konvolüsyonla aynı sonuç elde ediliyor.

Hoca bu noktada yatay filtrenin varyansı $\sigma_1$, dikey filtreninki $\sigma_2$ ise elde edilen filtrenin varyansının bu ikisinin toplamı olacağını, böylece ayrılabilir filtrelerden istenen iki boyutlu Gauss'un hesaplanabileceğini söyledi.

> **Ders sonrası not:** Hoca yatay ve dikey 1B Gauss filtrelerinin varyanslarının toplanacağını söyledi; doğrusu: varyanslar yalnız aynı yönde art arda yapılan Gauss filtrelemelerinde toplanır (7.3). Yatayda varyansı $\sigma_1^2$ olan 1B Gauss ile dikeyde varyansı $\sigma_2^2$ olan 1B Gauss'un birleşimi, $x$ yönünde varyansı $\sigma_1^2$, $y$ yönünde $\sigma_2^2$ olan bir 2B Gauss verir. Örneğin iki yönde de $\sigma^2=1$ olan 1B filtreler, $\sigma^2=2$ olan değil, $\sigma^2=1$ olan 2B Gauss'a eşittir (python ile doğrulandı).

### 7.5 Filtre ne büyüklükte olmalı?

Slayttaki pratik kural: filtrenin yarı uzunluğu yaklaşık $3\sigma$ alınabilir. Kenardaki değerler sıfıra yakın olmalıdır.

> **Ek bilgi (derste anlatılmadı):** $3\sigma$ kuralıyla $\sigma=1$ için yarı genişlik 3, filtre $7\times7$ olur. Slayttaki $5\times5$, $\sigma=1$ filtrenin elemanları toplamı yaklaşık 0.982'dir; kesilen kuyruklar yüzünden toplam 1'in biraz altındadır. Pratikte filtre elemanları toplamlarına bölünerek toplam 1'e getirilir.

## 8. Kenarlarda Ne Yapılır?

Bu sorun Gauss'a değil, bütün filtrelemelere özgüdür. Örneğin $5\times5$ filtreyle filtrelendiğinde imgenin kenarındaki iki satır için ne yapılacaktır? Seçenekler:

- **Sıfır (clip filter):** Kenar bölgesi sıfır kabul edilir.
- **Sarma (wrap around):** İmgenin karşı kenarındaki satırlar buradaymış gibi kullanılır.
- **Kenarı kopyalama (copy edge):** Kenardaki satırlar olduğu gibi dışarıya kopyalanır.
- **Kenardan yansıtma (reflect across edge):** Kenardaki satırlar yukarıdan aşağıya ters çevrilerek (flip) dışarıya eklenir.

Bu yollarla orijinal imge önce büyütülür, sonra filtreleme yapılırsa sonuç orijinal boyutta olur. Slaytta her yöntemin sonucu gösterildi.

## 9. Sinüs İmgesi: linspace, meshgrid ve roll

Dersin sonunda bir öğrencinin sorusu üzerine, önceki ödevdeki çapraz çizgili sinüs imgesinin farklı çözümlerine bakıldı.

### 9.1 1B sinüsü satır satır kaydırma

Bir çözüm 1B bir sinüs dizisi oluşturup her satıra bir öncekinden bir piksel fazla kaydırarak yerleştiriyordu (ekrandan, 02:40:00):

```python
N = 256
x = np.linspace(-np.pi, np.pi, N)
sine1D = 128.0 + (127.0 * np.sin(x * 8.0))
sine1D = np.uint8(sine1D)
sine2D = np.ndarray((N,N), dtype=np.uint8)
for i in range(N):
    sine2D[i] = np.roll(sine1D, -i)   # shift the 1D sin data by -i
plt.imshow(sine2D, cmap='gray')
plt.show()
```

`np.linspace` $-\pi$ ile $\pi$ arasında 256 eşit aralıklı değer üretir; hoca şekil oluşturmak için çok faydalı olduğunu söyledi. `np.roll` diziyi kaydırır ve en sağdan taşan eleman başa döner. Her satır bir piksel daha kaydırılınca çizgiler çapraz görünür. Başka bir çözüm de çok uzun bir 1B sinüs dalgası oluşturup bunu `reshape` ile iki boyuta getirmiş; satır uzunluğu uygun seçildiği için her satır bir öncekine göre kaymış ve yine çapraz bir desen oluşmuştu.

### 9.2 meshgrid ile iki boyutlu fonksiyon

Diğer çözüm `np.meshgrid` kullanıyordu. Hoca kodu Spyder'da yeniden yazıp debugger ile inceledi (ekrandan, 02:45:00):

```python
def f(x, y):
    return np.sin(x - y)

x = np.linspace(0, 40, 500)
y = np.linspace(0, 60, 500)
X, Y = np.meshgrid(x, y)
Z = f(X, Y)

plt.contourf(X, Y, Z, 20, cmap='Greys')
```

`linspace` 0 ile 40 arasında (y için 0 ile 60 arasında) 500 eşit aralıklı değer üretir. `meshgrid` bunlardan iki boyutlu koordinat matrisleri kurar: büyük `X`'te her satır aynıdır ve $x$ koordinatlarını verir; büyük `Y`'de ise her satır sabittir, $y$ değerleri satırlara dağıtılmıştır. Böylece iki boyutlu bir koordinat sisteminde bir fonksiyonu çağırmak kolaylaşır. Hoca, aynı hesabı döngüyle yazmanın inanılmaz yavaş olacağını, NumPy'ın ise `X - Y` ve `np.sin` işlemlerini matrisin tamamına bir kerede uyguladığını vurguladı.

Öğrenci, $\sin x$'in dikey, $\sin y$'nin yatay çizgiler verdiğini, $x-y$ kullanınca çizgilerin 45 dereceye yakın bir açıyla eğildiğini, artı ile denediğinde ters yönde çıktığını anlattı. Hoca, sinüs periyodik olduğu için önemli olanın değerlerin düzenli artması olduğunu, sinüsün bunu doğal olarak düzgün periyodik bir desene çevirdiğini söyledi. Ayrıca `meshgrid`'in, ödev olarak verilen Gauss kernelinin üç boyutlu çizimi için de gerekli olacağını ekledi.

> **Ek bilgi (derste anlatılmadı):** $\sin(x-y)$ fonksiyonu $x-y=\text{sabit}$ doğruları boyunca sabittir. Bu doğrular $y=x+c$ biçimindedir, yani eşit eksen ölçeğinde 45 derece eğimlidir. Çizgilerin görünen açısı, $x$ ve $y$ aralıklarının (0-40 ve 0-60) ekrana nasıl ölçeklendiğine göre değişir.

## Örnek Sorular

**Soru 1** (ekrandan, 01:10:00; derste sözlü, 01:09:20). 2.2'deki $10\times10$ imge $\frac19$ katsayılı $3\times3$ kutu filtresiyle filtreleniyor. a) Pencerede beş tane 90 bulunan hücreye (sıfırdan sayınca $f$'nin 6. satırı, 4. sütunu merkezli pencere) hangi değer yazılır? b) Pencerenin tamamı 90 olan hücreye hangi değer yazılır? c) Sonuç imge kaça kaçlıktır?

> **Çözüm:** a) Her 90 için $90\cdot\frac19=10$, beş tane olduğu için $50$. b) $9\cdot10=90$. c) Filtre kenar satır ve sütunlarına sığmadığı için $8\times8$ (python ile doğrulandı).

**Soru 2** (ekrandan, 01:15:00). $h[m,n]=\sum_{k,l} g[k,l]\, f[m+k,n+l]$ formülünde $h[4,6]$ için $k=0,l=0$ ve $k=-1,l=-1$ terimlerini yazın. $h[4,6]$ kaçtır?

> **Çözüm:** $k=0,l=0$: $g[0,0]\,f[4,6]$. $k=-1,l=-1$: $g[-1,-1]\,f[3,5]$. Toplam 9 terim vardır. Pencerenin ($f$'nin 3-5. satırları, 5-7. sütunları) tamamı 90 olduğu için $h[4,6]=9\cdot\frac{90}{9}=90$.

**Soru 3** (ekrandan, 01:20:00). Yalnız ortası 1, diğer elemanları 0 olan $3\times3$ filtre imgeye ne yapar?

> **Çözüm:** Hiçbir şey değiştirmez. Her pikselin yerine kendi değeri yazılır; komşular 0 ile çarpılır.

**Soru 4** (derste sözlü, 01:20:17). Tek 1'i merkezde değil de merkezin yanında olan bir filtre ne yapar?

> **Çözüm:** İmgeyi bir piksel kaydırır. Hocanın anlattığı filtrede her piksele sağındaki pikselin değeri yazılır, imge bir piksel sola kayar; en sağdaki sütun boş kalır (sıfır), en soldaki sütun kaybolur.

**Soru 5** (ekrandan, 01:25:00). $\begin{bmatrix}0&0&0\\0&2&0\\0&0&0\end{bmatrix} - \frac19\begin{bmatrix}1&1&1\\1&1&1\\1&1&1\end{bmatrix}$ filtresini tek bir matris olarak yazın. Bu filtre ne yapar?

> **Çözüm:** Merkez $2-\frac19=\frac{17}{9}$, diğer elemanlar $-\frac19$. Elemanlar toplamı $\frac{17-8}{9}=1$. Bu keskinleştirme filtresidir: yerel ortalamadan farkı büyütür, yumuşatmanın tersini yapar.

**Soru 6** (derste sözlü, 01:25:55). Filtreler tasarlanırken elemanlar toplamının 1 olmasına neden dikkat edilir?

> **Çözüm:** Toplam 1'den büyükse (ör. 2) filtreleme imgenin toplam parlaklığını artırır; filtre art arda uygulandıkça imge giderek parlaklaşır. Toplam 1 olunca ortalama parlaklık korunur.

**Soru 7** (derste sözlü, 01:28:38). Bir satırda bir yandaki pikseli diğer yandakinden çıkaran filtre neyi hesaplar? İmgede $h$ neden 1'den küçük alınamaz?

> **Çözüm:** Yatay türevi hesaplar; sonuç kenarlarda büyüktür. Türevin tanımında $h\to0$ gider, ama imge ayrık olduğu için en küçük adım 1 pikseldir; $h=0$ alınırsa pikselin kendisi elde edilir. Simetriyi korumak için merkezin iki yanındaki pikseller kullanılır.

**Soru 8** (derste sözlü, 00:30:44). Alt örnekleme (subsampling) ile yeniden boyutlandırmanın (resizing) farkı nedir?

> **Çözüm:** Alt örnekleme satır ve sütunları atlayarak seçer; tek başına yapılırsa yapay desenler oluşur, bu yüzden genelde alçak geçiren filtreyle yumuşatılır. Yeniden boyutlandırma ise yeni piksel değerlerini filtreleme ya da enterpolasyonla hesaplayan, alt örneklemeyi de içerebilen daha genel bir işlemdir.

**Soru 9** (derste sözlü, 00:28:23 ve 00:35:54). `flip` kullanmadan, yalnız NumPy indekslemesiyle a) imgeyi yukarıdan aşağıya ters çevirin, b) imgeyi yarıya alt örnekleyin.

> **Çözüm:** a) `image[::-1]` (renkli imgede de çalışır). b) `image[::2, ::2]`; 2 adım miktarıdır (python ile denendi).

**Soru 10** (ödev, ekrandan, 02:20:00). NumPy ile formülden $\sigma^2=2$ olan, merkezi ortada ve boyutu tek sayı olan bir 2B Gauss kerneli oluşturun. Sonra formülden $\sigma^2=1$ olan $x$ yönünde 1B Gauss kerneli oluşturun, transpozuyla $y$ yönündeki kerneli elde edin ve imgeyi bu iki 1B kernelle art arda konvolüsyona sokun. Ortası 1, diğer pikselleri 0 olan $41\times41$ yapay bir imgeyle de deneyin. İki sonuç eşit mi, eşit olmalı mı?

> **Çözüm (derste verilmedi):** Kernel, `meshgrid` ile kurulan $x,y$ ızgarasında formül hesaplanarak oluşturulur:
>
> ```python
> r = 6                                  # yarı genişlik (yaklaşık 3*sigma)
> x = np.arange(-r, r + 1)
> X, Y = np.meshgrid(x, x)
> K2 = np.exp(-(X**2 + Y**2) / (2 * 2.0)) / (2 * np.pi * 2.0)   # sigma^2 = 2
> k1 = np.exp(-x**2 / (2 * 1.0)) / np.sqrt(2 * np.pi * 1.0)     # sigma^2 = 1
> kx, ky = k1[None, :], k1[None, :].T
> ```
>
> $41\times41$ birim impuls imgesiyle denendiğinde iki sonuç **eşit çıkmaz**: $\sigma^2=1$ olan yatay ve dikey 1B kernellerin birleşimi $\sigma^2=1$ olan 2B Gauss'tur (merkez değeri yaklaşık 0.159), $\sigma^2=2$ olan 2B kernelin merkez değeri ise yaklaşık 0.080'dir. Eşit olması da beklenmez, çünkü yatay ve dikey filtrelerin varyansları toplanmaz; her yön kendi varyansını korur. Eşitlik için 1B kernellerin de $\sigma^2=2$ ile oluşturulması gerekir. Varyans toplama özelliğini görmek için ise aynı yönde iki kez $\sigma^2=1$ ile filtrelenir: sonuç o yönde $\sigma^2=2$ olur (python ile doğrulandı; konvolüsyon NumPy ile yazıldı).

## Dersin Toparlaması

Bu derste önce NumPy indekslemesiyle temel imge işlemleri (ters çevirme, alt örnekleme, renk sayısını azaltma) ve dilimlerin görünüm olduğu konuşuldu. Ardından imge filtrelemenin mantığı adım adım bir örnekle kuruldu: filtre imgenin üzerinde kaydırılır, çarpılıp toplanır ve sonuç merkeze yazılır. Kutu, birim, kaydırma, keskinleştirme, türev ve Sobel filtreleri üzerinden farklı filtrelerin imgeye etkisi görüldü. Filtrelemenin konvolüsyondan tek farkının filtrenin ters çevrilmesi olduğu, simetrik filtrelerde ikisinin aynı kapıya çıktığı anlatıldı. Doğrusal filtrelerin doğrusallık, kayma değişmezliği, değişme ve birleşme gibi özellikleri ve "doğrusal, kayma değişmez her işlem bir konvolüsyondur" sonucu verildi.

Son bölümde Gauss filtresinin yumuşatmada neden tercih edildiği, ardışık Gauss filtrelemelerinde varyansların toplandığı ve Gauss'un ayrılabilir olduğu için iki 1B filtreyle çok daha hızlı uygulanabildiği gösterildi. Kenar işleme yöntemleriyle filtreleme konusu tamamlandı. Slaytlardaki bir sonraki konu "frekansta düşünme" (thinking in frequency) idi; Gauss filtreleme ise uygulamalı bir ödev olarak bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
