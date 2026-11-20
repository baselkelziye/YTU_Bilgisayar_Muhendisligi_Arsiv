# Ders 3 Çalışma Özeti

## Genel Konular

- NumPy ile temel imge işlemleri (ödev çözümleri üzerinden)
  - İmgeyi yukarıdan aşağıya ters çevirme hazır `flip` fonksiyonu olmadan, NumPy indeksleme ile yapılabilir: `img[::-1]` (ekrandan, 02:35:00).
  - Alt örnekleme (subsampling) satır ve sütunları atlayarak seçmektir. Yarıya indirmek için `img[::2, ::2]`, üçte bire indirmek için `img[::3, ::3, :]` yazılır (ekrandan, 02:35:00). Buradaki 2 ya da 3 adım miktarıdır.
  - Yeniden boyutlandırma (resizing) daha genel bir işlemdir. Yeni piksellerin değeri filtreleme ya da enterpolasyonla hesaplanır. Alt örnekleme bunun yalnız bir parçasıdır.
  - İmgeyi 10 renge indirmek için bir kümeleme algoritması (k-means) kullanılabilir. OpenCV'de `cv2.kmeans` vardır.
  - Renkli imgeyi gri seviyeye indirmenin farklı yolları vardır. Hocaya göre HSV gibi parlaklığı ayrı tutan bir renk uzayına geçip parlaklığı almak daha doğrudur.
  - `np.linspace` ve `np.meshgrid` iki boyutlu koordinat ızgarası kurar. Böylece $\sin(x-y)$ gibi bir fonksiyon döngü yazmadan bütün ızgarada hesaplanır ve çapraz çizgili bir sinüs imgesi elde edilir.
  - NumPy dilimleme (slicing) kopya değil görünüm (view) döndürür. Dilimde yapılan değişiklik orijinal diziyi de değiştirir. Bağımsız bir dizi için `.copy()` gerekir.
- İmge filtreleme (image filtering)
  - Filtre (kernel) küçük bir matristir. İmgenin üzerinde gezdirilir. Her konumda karşılık gelen pikseller çarpılır, toplanır ve sonuç filtrenin merkezine karşılık gelen piksele yazılır.
  - Formül (ekrandan, 01:05:00): $h[m,n]=\sum_{k,l} g[k,l]\,f[m+k,n+l]$. Burada $g$ filtre, $f$ orijinal imge, $h$ yeni imgedir. Filtrenin indeksleri merkez 0 olacak biçimde $-1,0,1$ diye numaralanır.
  - Kenar sorunu: $3\times3$ filtreyle $10\times10$ imgeden $8\times8$ imge çıkar. Boyutu korumak için sıfırla doldurma, sarma (wrap around), kenarı kopyalama (copy edge) ya da kenardan yansıtma (reflect across edge) kullanılır.
- Örnek doğrusal filtreler
  - Kutu filtresi (box filter): bütün elemanları $1/9$ olan $3\times3$ filtre. Komşuluk ortalamasını alır, yumuşatır, alçak geçiren (low-pass) bir filtredir.
  - Birim filtre: yalnız ortası 1 olan filtre imgeyi değiştirmez.
  - Kaydırma filtresi: 1 merkezde değil de yanda olursa imge bir piksel kayar.
  - Keskinleştirme (sharpening) filtresi: $2\cdot\delta - \frac{1}{9}\mathbf{1}$, yani ortası $17/9$, diğerleri $-1/9$ olan filtre. Yerel ortalamadan farkı büyütür.
  - Türev filtresi ve Sobel filtresi: komşu piksellerin farkı yatay türevi verir, kenarları bulur. Sobel bir yönde türev, diğer yönde yumuşatma yapar.
- Filtreleme ve konvolüsyon
  - Konvolüsyonda filtre hem yatay hem dikey ters çevrilir (flip), sonra filtreleme yapılır: $h[m,n]=\sum_{k,l} f[k,l]\,I[m-k,n-l]$ (ekrandan, 01:40:00).
  - Simetrik filtrelerde ikisi aynı sonucu verir.
- Doğrusal filtrelerin özellikleri
  - Doğrusallık, kayma değişmezliği (shift invariance), değişme, birleşme, toplama üzerine dağılma, skalerin dışarı çıkması, birim eleman.
  - Doğrusal ve kayma değişmez her işlem bir konvolüsyonla gösterilebilir (ekrandan, 01:45:00).
- Gauss filtresi
  - Formül (ekrandan, 02:00:00): $G_\sigma=\frac{1}{2\pi\sigma^2}e^{-\frac{x^2+y^2}{2\sigma^2}}$.
  - Kutu filtresinin oluşturduğu yapay desenleri oluşturmaz, yumuşatmada tercih edilir.
  - İki Gauss filtresinin konvolüsyonu yine Gauss'tur, varyanslar toplanır.
  - Ayrılabilir (separable) bir filtredir: 2B Gauss, $x$ ve $y$ yönündeki iki 1B Gauss'un çarpımıdır.
  - Filtre boyutu için pratik kural: yarı genişlik yaklaşık $3\sigma$.

## Hocanın Özellikle Vurguladığı Kısımlar

- İmge filtreleme çok temel bir işlemdir
  - İyileştirme ve gürültü giderme gibi birçok işte kullanılır.
- Filtrenin elemanları toplamı 1 olmalıdır
  - Toplam 2 olursa her filtrelemede imgenin toplam parlaklığı artar. Normalde bu istenmez.
- Gauss filtrelerinde varyanslar toplanır
  - Hoca bunu not almayı önerdi. Ardışık iki Gauss filtrelemesi, varyansı iki varyansın toplamı olan tek bir Gauss filtrelemesine eşittir. Böylece küçük filtrelerle büyük varyanslı yumuşatma elde edilir.
- Ayrılabilir filtreler hız kazandırır
  - $5\times5$ filtrede piksel başına 25 çarpma yerine $5+5=10$ çarpma yapılır.
- Pratikte filtreler genelde simetriktir
  - Bu yüzden filtreleme ile konvolüsyon çoğu zaman aynı sonucu verir.
- NumPy'ı alt seviyede, indeksleme ile kullanmayı öğrenmek
  - `flip` ya da hazır fonksiyon yerine dilimleme kullanılması istendi.
  - Döngü yerine NumPy dizi işlemleri kullanmak kodu çok hızlandırır.

## Kısa Tekrar Notları

- $h[m,n]=\sum_{k,l} g[k,l]\,f[m+k,n+l]$: filtreleme (korelasyon). Konvolüsyonda $f[m-k,n-l]$, yani ters çevrilmiş filtre.
- Kutu filtresi = yerel ortalama = yumuşatma = alçak geçiren.
- Birim filtre imgeyi değiştirmez. Merkez dışındaki tek 1 imgeyi kaydırır.
- Keskinleştirme = $2\times$ birim $-$ kutu filtresi; merkez $17/9$, diğerleri $-1/9$, toplam 1.
- Türev filtresi kenarları bulur. Sobel: bir yönde türev, diğer yönde $[1,2,1]$ ile yumuşatma. Transpozu diğer yönde kenar bulur.
- Kenar işleme: sıfır doldurma, wrap around, copy edge, reflect across edge.
- Doğrusal + kayma değişmez işlem = konvolüsyon.
- Gauss: $\sigma$ şekli belirler, $\sigma^2$ varyanstır. Ardışık iki Gauss'ta varyanslar toplanır; $\sigma$ ile iki kez konvolüsyon = $\sigma\sqrt2$ ile bir kez (ekrandan, 02:05:00).
- Gauss ayrılabilir: önce yatay 1B, sonra dikey 1B filtre aynı sonucu verir.
- Filtre yarı genişliği yaklaşık $3\sigma$.
- NumPy: `img[::-1]` ters çevirir, `img[::2, ::2]` yarıya alt örnekler; dilim bir görünümdür, gerekiyorsa `.copy()`.

## Detaylı Açıklamalar

Dersin ilk bölümünde önceki ödevin çözümleri üzerinden NumPy ile imge işleme konuşuldu. Hocanın istediği, hazır fonksiyonlar yerine NumPy indekslemesini öğrenmekti. İmgeyi yukarıdan aşağıya ters çevirmek için `img[::-1]` yeterlidir; renkli imgede de çalışır, çünkü yalnız ilk eksen ters çevrilir. Alt örnekleme ile yeniden boyutlandırma farklıdır. Alt örneklemede satır ve sütunlar atlanarak seçilir (`img[::2, ::2]`). Yalnız bunu yapmak imgede yapay desenlere yol açar, bu yüzden genelde üzerine alçak geçiren bir filtre uygulanarak yumuşatılır. Yeniden boyutlandırma ise yeni piksellerin değerini filtreleme ya da enterpolasyonla hesaplayan, farklı algoritmaları olan daha geniş bir işlemdir; hoca bugün yapay zekâ tabanlı yöntemlerin de kullanıldığını söyledi. Bir imgeyi on renge indirmek için k-means gibi bir kümeleme algoritması kullanmak iyi bir çözümdür. Ekranda gösterilen bir çözümde pikseller `reshape((-1,3))` ile üç sütunlu bir listeye çevrilmiş, `cv2.kmeans` ile $K=10$ küme merkezi bulunmuş ve her piksel kendi küme merkezinin rengine boyanmıştır (ekrandan, 00:35:00). Çapraz çizgili sinüs imgesi için iki çözüm görüldü: biri 1B sinüs dizisini her satırda `np.roll` ile bir piksel daha kaydırıyor (ekrandan, 02:40:00), diğeri `np.meshgrid` ile kurulan ızgarada $\sin(x-y)$ hesaplıyor (ekrandan, 02:45:00).

İmge filtrelemede bir filtre (kernel) imgenin üzerinde kaydırılır. Her konumda filtre elemanları altlarındaki piksellerle çarpılıp toplanır ve sonuç yeni imgede filtre merkezinin denk geldiği piksele yazılır. Derste $10\times10$ boyutlu, 0 ve 90 değerli bir imge kutu filtresiyle filtrelendi (ekrandan, 01:05:00). Üç tane 90 içeren bir pencerede sonuç $3\cdot 90/9=30$, tamamı 90 olan pencerede 90 çıkar. Sonuç imge $8\times8$ olur, çünkü filtre kenar piksellerinde imgenin dışına taşar. Kutu filtresi komşuluk ortalaması aldığı için yumuşatır. Keskinleştirme filtresi ise orijinal imgenin iki katından yerel ortalamayı çıkarır; yerel ortalamadan farklı pikselleri daha da farklı yapar. Türev filtresi, türevin $\lim_{h\to0}\frac{f(x+h)-f(x)}{h}$ tanımının ayrık hâlidir. Dijital imgede $h$ en az 1 olabilir; simetriyi korumak için bir sağdaki pikselden bir soldaki çıkarılır. Türev, değişimin büyük olduğu yerlerde, yani kenarlarda büyüktür. Sobel filtresi bir yönde türev alırken diğer yönde yumuşattığı için gereksiz ayrıntıları azaltır.

Gauss filtresi normal dağılımın iki boyutlu hâlidir ve şeklini standart sapma $\sigma$ belirler. Kutu filtresinin aksine yapay desen oluşturmaz. İki Gauss filtresinin ardışık uygulanması, varyansı ikisinin toplamı olan tek bir Gauss filtresine eşittir; bu özellik ölçek uzayı (scale space) ve piramitlerin temelidir. Gauss ayrılabilir de olduğu için $K\times K$ filtre yerine iki tane 1B filtre uygulanarak piksel başına $K^2$ yerine $2K$ işlem yapılır.

> **Ders sonrası not:** Hoca 02:10'da yatay filtrenin varyansı $\sigma_1$, dikey filtreninki $\sigma_2$ ise sonucun varyansının ikisinin toplamı olacağını söyledi. Doğrusu: varyanslar yalnız aynı yönde art arda yapılan Gauss filtrelemelerinde toplanır. Yatay 1B ve dikey 1B Gauss'un birleşimi, $x$ yönünde $\sigma_1^2$, $y$ yönünde $\sigma_2^2$ varyanslı 2B Gauss verir (python ile doğrulandı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
