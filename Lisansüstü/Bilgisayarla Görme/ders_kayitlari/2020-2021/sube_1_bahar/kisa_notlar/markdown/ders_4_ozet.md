# Ders 4 Çalışma Özeti

## Genel Konular

- Görüntü keskinleştirmenin (sharpening) temel fikri
  - Keskinleştirmenin amacı parlaklıktaki geçişleri (kenarları) vurgulamaktır. Bulanıklaştırma komşuluktaki piksellerin ortalamasıyla, yani integrale benzeyen bir işlemle yapılır; bu yüzden keskinleştirme bunun tersi olan uzamsal türevle (fark alma) yapılır (ekrandan, 00:20:00).
- Bir boyutlu işarette birinci ve ikinci türev
  - Örnek tarama satırı (scan line): `6 6 6 6 5 4 3 2 1 1 1 1 1 1 6 6 6 6 6`. Önce sabit parlaklık, sonra 6'dan 1'e inen bir rampa, sonra sabit bölge, sonra 1'den 6'ya keskin bir basamak (step) vardır (ekrandan, 00:25:00).
  - Birinci türev sağdaki pikselden soldakini çıkararak bulunur: $f(x+1) - f(x)$. Sonuç: `0 0 -1 -1 -1 -1 -1 0 0 0 0 0 5 0 0 0 0`.
  - İkinci türev aynı fark işleminin birinci türev üzerinde tekrarıdır: $f(x+1) + f(x-1) - 2f(x)$. Sonuç: `0 0 -1 0 0 0 0 1 0 0 0 0 5 -5 0 0 0`.
  - Birinci türev: sabit bölgede sıfırdır, rampa ya da basamağın başında sıfırdan farklıdır, rampa boyunca da sıfırdan farklıdır.
  - İkinci türev: sabit bölgede sıfırdır, rampa ya da basamağın başında ve sonunda sıfırdan farklıdır, sabit eğimli rampa boyunca sıfırdır.
  - Sayısal görüntülerdeki kenarlar çoğunlukla rampa biçimindedir. Birinci türev kalın kenar üretir; ikinci türev sıfırlarla ayrılmış çift kenar (double edge) üretir. Bu yüzden keskinleştirmede ikinci türev daha elverişlidir.
- Laplace (Laplacian) operatörü ve maskeleri
  - Birinci türev operatörüne gradyan, ikinci türev operatörüne Laplace operatörü denir. Laplace operatörü izotropiktir (dönmeden bağımsızdır).
  - $\nabla^2 f = \dfrac{\partial^2 f}{\partial x^2} + \dfrac{\partial^2 f}{\partial y^2}$, ayrık biçimi $\nabla^2 f(x,y) = f(x+1,y) + f(x-1,y) + f(x,y+1) + f(x,y-1) - 4f(x,y)$ (ekrandan, 00:35:00).
  - Bu ifadeden merkezi $-4$, dört ana komşusu $1$, köşeleri $0$ olan $3\times 3$ maske çıkar. Çapraz komşular da katılınca merkez $-8$, bütün komşular $1$ olur. Bu iki maskenin işaretleri ters çevrilmiş biçimleri (merkez $4$ ve $8$) de kullanılır (ekrandan, 00:45:00).
  - Türev maskelerinin katsayıları toplamı sıfırdır; sabit parlaklıklı bölgede çıktı sıfır olur.
- Laplace ile keskinleştirme
  - $g(x,y) = f(x,y) + c\,[\nabla^2 f(x,y)]$. Maske merkezi negatifse $c=-1$, pozitifse $c=1$ alınır (ekrandan, 00:50:00).
  - Laplace çıktısı yalnız kenar geçişlerini içerir; özgün görüntüye eklenince kenarlar kuvvetlenir. Ayın kuzey kutbunun bulanık görüntüsünde merkezi $-8$ olan maske, merkezi $-4$ olana göre yüzeydeki çukurları daha belirgin yaptı.
- Keskinsizleştirme maskesi (unsharp masking) ve yüksek artırımlı süzgeç (highboost filtering)
  - Adımlar: görüntüyü bulanıklaştır, bulanık görüntüyü özgün görüntüden çıkararak maskeyi bul, maskeyi bir $k$ katsayısıyla çarpıp özgün görüntüye ekle.
  - $g_{mask}(x,y) = f(x,y) - \bar f(x,y)$, $g(x,y) = f(x,y) + k\,g_{mask}(x,y)$.
  - $k=1$: keskinsizleştirme maskesi; $k>1$: yüksek artırımlı süzgeç; $k<1$: maskenin katkısı azaltılır (de-emphasize).
  - Bir boyutlu işaret çiziminde maske kenarın iki yanında küçük bir çukur ve tepe verir; keskinleştirilmiş işarette kenar geçişinde önce aşağı, sonra yukarı bir taşma oluşur (ekrandan, 00:55:00).
- Gradyan operatörü
  - $\nabla f = \begin{bmatrix} g_x \\ g_y \end{bmatrix} = \begin{bmatrix} \partial f/\partial x \\ \partial f/\partial y \end{bmatrix}$ (ekrandan, 01:15:00).
  - Büyüklük: $M(x,y) = \sqrt{g_x^2 + g_y^2}$. Yön: $\alpha(x,y) = \tan^{-1}(g_y / g_x)$.
- Roberts, Prewitt ve Sobel maskeleri
  - Roberts çapraz fark alan $2\times 2$ maskelerdir; merkezi olmadığı için pek tercih edilmez.
  - Prewitt: $\begin{bmatrix} -1 & -1 & -1 \\ 0 & 0 & 0 \\ 1 & 1 & 1 \end{bmatrix}$ ve $\begin{bmatrix} -1 & 0 & 1 \\ -1 & 0 & 1 \\ -1 & 0 & 1 \end{bmatrix}$ (ekrandan, 01:25:00).
  - Sobel: $\begin{bmatrix} -1 & -2 & -1 \\ 0 & 0 & 0 \\ 1 & 2 & 1 \end{bmatrix}$ ve $\begin{bmatrix} -1 & 0 & 1 \\ -2 & 0 & 2 \\ -1 & 0 & 1 \end{bmatrix}$. Ana yönlerdeki komşular $2$ ile ağırlıklandırılır (ekrandan, 01:25:00).
  - Bütün maske katsayılarının toplamı sıfırdır.
- Python uygulaması
  - `skimage.io.imread` ile okunan bina görüntüsüne yatay ve dikey Prewitt çekirdekleri `scipy.ndimage.convolve` ile uygulandı. Biri yatay, öbürü dikey çizgileri (pencere kenarları, tuğla çizgileri) öne çıkardı (ekrandan, 01:30:00).
  - Gradyan büyüklüğü iki yöndeki çıktının karelerinin toplamının karekökü alınarak hesaplandı; kenarlar beyaz, sabit bölgeler siyah göründü.
  - `filters.gaussian(image, sigma)` ile yumuşatıp `filters.sobel` uygulamak gürültünün kenar sanılmasını azaltır (ekrandan, 02:05:00).
- LoG (Laplacian of Gaussian) süzgeci, Marr-Hildreth kenar bulucu
  - Parlaklık değişimleri görüntü ölçeğinden bağımsız değildir; farklı boyutta operatör gerekir. Ani bir değişim birinci türevde tepe, ikinci türevde sıfır geçişi (zero crossing) üretir (ekrandan, 01:35:00).
  - Önce Gauss ile yumuşatıp sonra türev almak yerine Gauss fonksiyonunun ikinci türevi alınır ve tek bir maskeyle tek konvolüsyon yapılır.
  - $G(x,y) = e^{-\frac{x^2+y^2}{2\sigma^2}}$, $\nabla^2 G(x,y) = \left(\dfrac{x^2+y^2-2\sigma^2}{\sigma^4}\right) e^{-\frac{x^2+y^2}{2\sigma^2}}$.
  - Şekli "Meksika şapkası"dır. $5\times 5$ örnek maskenin merkezi $16$, en küçük değerleri $-2$'dir (ekrandan, 01:40:00).
  - Kenarlar, LoG çıktısının sıfır geçiş noktalarında aranır.
- Canny kenar bulucu, sigma ve çekirdek boyutu
  - Canny sürekli kenarlar ürettiği için en çok tercih edilen kenar bulucudur. Gürültülü sentetik kare görüntüsünde $\sigma=1$ arka planda küçük sahte kenarlar bıraktı, $\sigma=3$ gürültüyü temizledi (ekrandan, 02:10:00).
  - Kenar bulmada kullanılan başka süzgeçler: LoG ve DoG (Difference of Gaussian).
  - Prewitt ve Sobel hep $3\times 3$'tür. Gauss süzgecinde ise $\sigma$ büyüdükçe fonksiyonu iyi örneklemek için çekirdek de büyümelidir (en az $\pm 2\sigma$); büyük çekirdek daha geniş alanda ortalama alır, bulanıklık artar, gürültü daha iyi bastırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Türev operatörlerinin arkasındaki matematik
  - Özellikle doktora ve yüksek lisans öğrencilerinin filtreleri ezbere değil, nereden ve nasıl türetildiğini bilerek kullanması gerekir. Hazır Python fonksiyonlarını arka arkaya eklemek yetmez.
- Laplace maskesinin türetilmesi
  - İkinci türevin ayrık ifadesi tahtada adım adım çıkarıldı. Maskenin katsayıları bu ifadeden gelir.
- Gradyan büyüklüğü ve yönü
  - Türev operatörünün büyüklüğünün ve gradyan vektörünün açısının nasıl hesaplandığının bilinmesi beklenir.
- Prewitt ve Sobel maskeleri
  - Bu dersi alan birinin bu maskeleri ezbere yazabilmesi, kenar geçişinde ve sabit bölgede nasıl çıktı verdiklerini açıklayabilmesi gerekir.
- Konvolüsyonun elle yapılışı
  - Kodda `convolve` yazmak sonuç verir, ama yazılı sınavda konvolüsyonun kâğıt üzerinde yapılabilmesi gerekir.
- LoG katsayılarının formülden üretilmesi
  - Laplacian of Gaussian ifadesinden `meshgrid` ile Meksika şapkası şeklinin çizdirilmesi istendi.

## Kısa Tekrar Notları

- Birinci türev: $f(x+1)-f(x)$; ikinci türev: $f(x+1)+f(x-1)-2f(x)$.
- Sabit bölgede iki türev de sıfırdır. Rampa boyunca birinci türev sıfırdan farklı, ikinci türev sıfırdır.
- İkinci türev değişimin başında ve sonunda sıfırdan farklıdır; kenarda çift kenar ve sıfır geçişi verir.
- Laplace maskeleri: merkez $-4$ (dört komşu) ya da $-8$ (sekiz komşu); işaretleri ters biçimleri de vardır.
- Laplace ile keskinleştirme: $g = f + c\,\nabla^2 f$; merkez negatifse $c=-1$.
- Keskinsizleştirme maskesi: $g = f + k(f - \bar f)$; $k=1$ keskinsizleştirme, $k>1$ yüksek artırım.
- Gradyan büyüklüğü $\sqrt{g_x^2+g_y^2}$, yönü $\tan^{-1}(g_y/g_x)$.
- Roberts $2\times 2$ çapraz fark; Prewitt $3\times 3$ ve katsayıları $\pm 1$; Sobel ana yönlerde $\pm 2$.
- Türev maskelerinin katsayıları toplamı sıfırdır.
- Kenar bulmadan önce Gauss ile yumuşatma gürültünün kenar sanılmasını önler.
- LoG $= \nabla^2 G$; Meksika şapkası; kenar sıfır geçişlerindedir.
- Canny en başarılı kenar bulucudur; $\sigma$ büyüdükçe gürültü daha iyi bastırılır.
- Gauss çekirdeğinin boyutu $\sigma$ ile birlikte büyümelidir.

## Detaylı Açıklamalar

- Türevlerin bir boyutlu işaretteki davranışı
  - Ders, bir tarama satırındaki parlaklık değerleri üzerinden türevlerin anlamını kurdu. Satırda dört piksel boyunca sabit 6 değeri, sonra 5, 4, 3, 2, 1 diye yavaşça inen bir rampa, sonra sabit 1 değerleri ve en sonda 1'den 6'ya tek adımda çıkan keskin bir basamak vardır. Birinci türev her piksel için sağdaki değerden kendi değerini çıkarır: sabit bölgede sonuç 0, rampa boyunca $-1$, basamakta $5$ olur. İkinci türev birinci türev dizisine aynı fark işlemini uygular: rampa başında $-1$, rampa sonunda $1$, basamakta önce $5$ sonra $-5$ verir; rampa boyunca ise eğim sabit olduğu için $0$ verir. Hoca 0-7 aralığında kodlanmış bir görüntüde 6'nın beyaza yakın, 1'in siyaha yakın olduğunu, yani rampanın beyazdan siyaha kademeli bir geçiş, yani bir kenar olduğunu söyledi.
  - Sonuç olarak birinci türev değişimin sürdüğü bütün aralıkta tepki verir ve kalın kenar üretir. İkinci türev ise değişimin yalnız başladığı ve bittiği yerde tepki verir; aralarında sıfırlar olan çift kenar üretir. Basamakta $5$'ten $-5$'e işaret değiştirmesi sıfır geçişidir. İnce ayrıntıları vurgulamak için ikinci türev daha uygundur.
- Laplace maskesinin türetilmesi
  - $f(x-1)$, $f(x)$, $f(x+1)$ arka arkaya üç piksel olsun. Birinci türev için iki fark yazılır: $f(x)-f(x-1)$ ve $f(x+1)-f(x)$. İkinci türev bu iki farkın farkıdır: $[f(x+1)-f(x)] - [f(x)-f(x-1)] = f(x+1) + f(x-1) - 2f(x)$. Aynı işlem $x$ sabit tutularak $y$ doğrultusunda yapılır. İki kısmi türev toplanınca merkezde $-4f(x,y)$, dört ana komşuda $+1$ katsayısı olan ifade çıkar. Bu ifade doğrudan bir $3\times 3$ filtre maskesidir.
  - Ara yönler (kuzeydoğu, güneybatı gibi) de hesaba katılınca köşeler $1$, merkez $-8$ olur. Merkez değerin seçimi katsayıların toplamını sıfır yapacak biçimdedir; böylece sabit bölgelerde çıktı sıfır olur. İşaretleri ters çevrilmiş maskeler de aynı işi görür; yalnız keskinleştirmede $c$ işareti buna göre seçilmelidir.
- Laplace ile keskinleştirme ve ölçekleme
  - Laplace çıktısı yalnız kenar bölgelerini taşıdığı için karanlık, özelliksiz bir arka plan üzerinde gri kenar çizgileri gibi görünür. Bu çıktı özgün görüntüye eklenince özgün görüntünün tonları korunur, kenarlar kuvvetlenir. Ay görüntüsü örneğinde Laplace çıktısı ölçeklenmeden ve ölçeklenerek gösterildi; ölçeklemenin, çıktının bir katsayıyla çarpılarak görünür hale getirilmesi olduğu belirtildi.
- Keskinsizleştirme maskesi
  - Hoca bunun işaret işleme açısından çok güzel bir açıklaması olduğunu vurguladı. Özgün işaret bir ortalama süzgeciyle bulanıklaştırılır; keskin geçişler yumuşar. Özgün işaretten bulanık işaret çıkarılınca geriye yalnız geçişlerdeki farklar kalır; bu farka keskinsizleştirme maskesi denir. Maske $k$ ile çarpılıp özgün işarete eklenince kenarda bir taşma (önce aşağı, sonra yukarı sıçrama) oluşur, sonra işaret normale döner. Keskinleştirme, kenardaki vurguyu bu biçimde artırmaktır.
- Gradyan ve kenar maskeleri
  - İki boyutlu görüntüde $x$ ve $y$ doğrultusunda kısmi türevler $g_x$ ve $g_y$ alınır. Bu ikisi bir vektör oluşturur; büyüklüğü kenarın gücünü, açısı değişimin yönünü verir. Bazı uygulamalarda açı da gerekir.
  - Tahtada gösterilen örnekte, üst bölgesi siyah (0), alt bölgesi beyaz (255) olan bir görüntüde Prewitt'in $[-1,-1,-1; 0,0,0; 1,1,1]$ maskesi siyah-beyaz geçişine oturtulunca sonuç $3\times 255 = 765$ olur. Tamamen beyaz bir bölgede $-1$'ler ile $+1$'ler birbirini götürür ve çıktı $0$ olur. Bu büyük farkın bir eşik değeriyle ayrılması maskeyi bir kenar bulucuya dönüştürür (ekrandan, 01:20:00).
  - Sobel, Prewitt'ten tek bir farkla ayrılır: merkeze daha yakın olan ana yöndeki komşuların katsayısı $2$ yapılır. Bu küçük değişiklik daha başarılı sonuç verdiği için günümüzde Sobel daha çok bilinir.
- Gauss yumuşatma, LoG ve Canny
  - Gürültü de bir parlaklık değişimi olduğu için türev operatörleri onu kenar sanar. Önce Gauss ile yumuşatmak, sonra türev almak daha doğrudur. LoG bu iki işlemi tek bir maskede birleştirir: Gauss fonksiyonunun $x$ ve $y$'ye göre ikinci kısmi türevleri alınıp toplanır, çarpımın türevi kuralıyla $\nabla^2 G$ ifadesi bulunur. Bu fonksiyondan üretilen katsayılarla görüntüye tek bir konvolüsyon uygulanır ve sıfır geçişlerinden kenarlar bulunur.
  - Canny kenar bulucuda Gauss genişliği ($\sigma$) gürültüye göre seçilir. $\sigma$ küçükken pencere dar kalır ve arka plandaki gürültü noktaları kenar olarak kalır; $\sigma$ büyüyünce bunlar kaybolur.

> **Ders sonrası not:** Hoca Canny kenar bulucunun içinde LoG süzgeci kullandığını söyledi. Ekrandaki açıklamaya göre Canny, Gauss'un türevine dayanan bir süzgeçle gradyan büyüklüğünü hesaplar, en büyük olmayan pikselleri bastırarak kenarları inceltir ve histerezis eşiklemesi uygular; yani LoG değil, Gauss'un birinci türevini kullanır (ekrandan, 02:10:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
