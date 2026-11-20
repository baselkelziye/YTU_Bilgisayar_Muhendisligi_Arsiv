# Ders 10 Genişletilmiş Notu: Evrişimli Sinir Ağları (CNN)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersten Hatırlatma
- 2. Tam Bağlı Katmandan Evrişimli Katmana
- 3. Evrişimli Katmanın İşleyişi
- 4. Havuzlama Katmanı
- 5. Alıcı Alan, Stride, Padding ve Dilation
- 6. Yerel Kontrast Normalizasyonu
- 7. Tipik Aşama, Tipik Mimari ve SIFT ile Benzerlik
- 8. Evrişimli Ağların Eğitimi
- 9. ImageNet ve Sınıflandırma Mimarisi
- 10. Optimizasyon ve Genelleme
- Örnek Sorular

## 1. Önceki Dersten Hatırlatma

Önceki derslerde bilgisayarla görmede derin ağlara giriş yapılmış, temel sinir ağı mantığı ve bir ağın katmanlarında geri yayılım (backward propagation) formüllerinin nasıl bulunduğu görülmüştü. Hoca bu formüllerin pratikte pek elle bulunmadığını hatırlattı. PyTorch ve TensorFlow gibi çerçeveler, kullanıcının bu türevleri kendisinin çıkarmasını gerektirmeyecek biçimde kurulmuştur: hazır katmanlar ve yapılar kullanıldığında her katman kendi türev bilgisiyle gelir ve sistem türevi kendisi alır. Bu yüzden pratik kullanım teoriye göre daha az matematik ister.

Bu dersin konusu evrişimli sinir ağlarıdır (convolutional neural networks, CNN). Hoca CNN'lerin çok yeni olmadığını, Yann LeCun ve arkadaşlarının derin öğrenme ortaya çıkmadan önce de bu ağlar üzerinde çalıştığını anlattı. Derin ağların eğitilebildiği anlaşılınca araştırmacılar farklı sinir ağlarını derin hale getirmeye başlamış, CNN de bunlardan biri olmuştur. Bugün en popüler ve en çok kullanılan ağlardan biridir.

## 2. Tam Bağlı Katmandan Evrişimli Katmana

### 2.1 Tam bağlı katman

Şimdiye kadar görülen standart sinir ağında imge bir vektöre çevrilir. Slayttaki örnekte 200×200'lük küçük, gri seviye bir imge vardır (ekrandan, 00:10:00). Bu imge 40.000 piksel, yani 40.000 giriş verir; renkli olmadığı için her pikselden tek bir değer gelir. Her giriş, bağlı olduğu katmandaki her üniteyle ayrı bir ağırlıkla (weight) çarpılır. Slaytta 40K gizli ünite için yaklaşık 2 milyar parametre (~2B parameters) yazıyordu.

- Verilen: 40.000 giriş, 40.000 gizli ünite.
- İşlem: her giriş her üniteye bağlı, bağlantı başına bir ağırlık.
- Sonuç: $40.000\times40.000=1{,}6\times10^{9}$, yani yaklaşık 2 milyar parametre (ara adım eklendi; çarpım ajan tarafından python ile kontrol edildi).

Bu kadar parametre çok fazla çarpım ve hesaplama demektir. Geri yayılım da düşünülünce, pratikte çok fazla veri ya da verinin tekrar tekrar verilmesi gerekir. Bu tür katmana tam bağlı katman (fully connected layer) denir, çünkü bütün giriş üniteleri bütün çıkış ünitelerine bağlıdır. Slaytta ayrıca şu iki madde vardı: uzamsal ilişki yereldir (spatial correlation is local) ve tam bağlantı kaynak israfıdır, üstelik zaten yeterli eğitim örneği yoktur. Hoca ilk maddeyle ne kastedildiğini tam anlamadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** "Uzamsal ilişki yereldir" ifadesi büyük olasılıkla bir pikselin en çok yakın komşularıyla ilişkili olduğunu, uzak piksellerle ilişkisinin zayıf olduğunu anlatır. Bu yüzden her üniteyi bütün imgeye bağlamak gereksizdir; yerel bağlantı fikri buradan doğar.

### 2.2 Yerel bağlı katman

Buna karşı geliştirilen fikir yerel bağlı katmandır (locally connected layer). Belirli bir bölgedeki girişler, o bölgeyle ilişkili tek bir çıkış ünitesine bağlanır; başka bir bölgedeki girişler başka bir çıkış ünitesine bağlanır. Bu bağlantılara yerel bağlantı (local connections) denir. Bağlantı tam olmadığı için sayısı çok daha azdır.

Slayttaki örnek (ekrandan, 00:15:00): 200×200 imge, 40K gizli ünite, filtre boyutu 10×10, sonuç 4M parametre.

- İşlem: her gizli ünite yalnız 10×10 = 100 girişe bağlı.
- Sonuç: $40.000\times100=4.000.000$ parametre (ajan tarafından kontrol edildi).

Slayttaki nota göre bu parametreleme, girdi imgeleri hizalı (registered) olduğunda iyi çalışır; örneğin yüz tanımada başarılıdır.

### 2.3 Evrişimli katman

Bir sonraki aşama evrişimli katmandır (convolutional layer). Burada çıkış ünitesi hem şu bölgeye, hem bu bölgeye, hem de bir başka bölgeye yerel olarak bağlanır; yani aynı yerel bağlantı imgenin tamamı üzerinde gezer. Bu, evrişim ile yapılır. Öğrenilen şey filtre, yani çekirdeğin (kernel) parametreleridir. Tek bir evrişim filtresi bütün imge üzerinde çalıştığı için imgenin bütün pikselleri aynı parametrelere cevap verir; başka bir deyişle parametreler imgedeki bütün pikseller tarafından paylaşılır.

## 3. Evrişimli Katmanın İşleyişi

### 3.1 Evrişim ile filtreleme

Evrişimli katman pratikte bildiğimiz evrişime çok benzer çalışır. Elimizde 3×3'lük bir evrişim çekirdeği vardır. Çekirdek girdi imgesi üzerinde gezdirilir; pencere her kaydığında evrişim sonucu çıktı imgesinde pencerenin tam merkezine karşılık gelen piksele yazılır. Böylece bütün imge evrişime sokulur. Bu esasen bir filtreleme işlemidir.

Slayttaki örnek çekirdek (ekrandan, 00:20:00):

$$
w=\begin{bmatrix}-1&0&1\\-1&0&1\\-1&0&1\end{bmatrix}
$$

Bu çekirdek her satırda türev aldığı için bir kenar bulma (edge detection) filtresidir. Sonuçta imgede yatay yönde büyük renk değişimi olan noktalar, yani yataydaki türev ve kenarlar ortaya çıkar. Slayttaki orman yolu imgesinde çıktı, ağaç gövdelerinin kenarlarını gösteriyordu.

Evrişimli katmanda tek değil, birçok filtre öğrenilir. Fikir şudur: bir filtre yataydaki kenarları, bir başkası dikeydeki kenarları, bir diğeri başka bir özelliği ortaya çıkarabilir.

### 3.2 Parametre sayısı

Hoca burada bir hesap sordu: her biri 10×10'luk filtrelerin parametre sayısı ne olur? Evrişimli katmanda parametreler tamamen filtrelerin katsayılarıdır.

- Verilen: 100 filtre, her biri 10×10. <!-- BELİRSİZ: Filtre sayısı altyazıda düşmüş; 100 değeri hocanın "100 çarpı 100" hesabından çıkarıldı, slayt karede görülmedi. -->
- İşlem: bir filtrede $10\times10=100$ katsayı; 100 filtrede $100\times100$.
- Sonuç: bu katmandan öğrenilmesi gereken 10.000 parametre.

Tam bağlı katmandaki milyarlarla, yerel bağlı katmandaki milyonlarla karşılaştırınca fark çok büyüktür.

### 3.3 Özellik haritaları ve evrişimli katman formülü

Girdi imgesine bazen girdi özellik haritası (input feature map) denir. Hoca bunu şöyle açıkladı: evrişimli ağların özellikle ilk katmanları özellik çıkarır. Derste daha önce Harris köşe bulucuda Gauss ile ağırlıklandırılmış türevler kullanılmış, Harris noktaları bulunmuş, ardından DoG bölgeleri ve bu bölgelerden SIFT öznitelikleri çıkarılmıştı. Bunların hepsi bir özellik kümesidir, yani bir özellik haritasıdır. Evrişimli katman da bir özellik grubunu alıp başka bir özellik grubu üretir.

Slayttaki formül (ekrandan, 00:25:00):

$$
h_j^{n}=\max\left(0,\ \sum_{k=1}^{K} h_k^{n-1} * w_{kj}^{n}\right)
$$

- $h_k^{n-1}$: $n-1$. katmandaki $k$. girdi özellik haritası.
- $w_{kj}^{n}$: $k$. girdiden $j$. çıktıya giden çekirdek.
- $*$: evrişim.
- $h_j^{n}$: $n$. katmandaki $j$. çıktı özellik haritası.
- $\max(0,\cdot)$: önceki derste görülen ReLU.

Önce evrişim yapılır, sonuç ReLU gibi bir doğrusalsızlıktan geçirilir; böylece sonuç doğrusallıktan çıkar. Giriş imgeleri çekirdeklerle evrişime sokularak yeni çıkış imgelerine dönüşür. Slayttaki şekilde üç girdi haritası ($h_1^{n-1},h_2^{n-1},h_3^{n-1}$) evrişimli katmandan geçip iki çıktı haritası ($h_1^{n},h_2^{n}$) veriyordu.

### 3.4 Çok kanallı evrişim

Her katmandaki imge sayısı farklı olabilir. Bu sayıyı filtre sayısı belirler. Ayrıca evrişim yalnız iki boyutlu değil, "üç boyutlu" gibi de yapılabilir. Hoca, ilk katmandan sonra aradaki çıktılara imge yerine özellik haritası demeyi önerdi. Birden fazla girdi haritası yan yana dizilmiş gibi düşünülürse, filtre bunların hepsi üzerinde aynı anda gezdirilir; her konumda bütün haritalardaki çarpımlar toplanır ve tek bir değer elde edilir. Böylece birden fazla özellik haritası tek bir haritaya ya da daha az sayıda haritaya eşlenebilir. Hoca bunun katman sayısını azaltmaya da yardım ettiğini söyledi.

### 3.5 Ana fikirler

"Key Ideas" slaytı şöyleydi (ekrandan, 00:30:00):

- İmgelere uygulanan standart sinir ağı:
  - girdi boyutuyla karesel (quadratic) büyür,
  - durağanlıktan (stationarity) yararlanmaz.
- Çözüm:
  - her gizli üniteyi girdinin küçük bir yamasına (patch) bağlamak,
  - ağırlıkları uzayda paylaşmak.
- Buna evrişimli katman, evrişimli katmanları olan ağa evrişimli ağ (convolutional network) denir.
- Kaynak: LeCun ve ark., "Gradient-based learning applied to document recognition", IEEE 1998.

## 4. Havuzlama Katmanı

### 4.1 Neden havuzlama?

Evrişim ve doğrusalsızlıktan (ReLU vb., arada başka işlemler de olabilir) sonra genelde bir havuzlama katmanı (pooling layer) gelir. Hoca bunu bir göz bulucu örneğiyle açıkladı. 3×3'lük bir filtre göz şekline cevap veriyor olsun: bir pikselin etrafında göz varsa filtre o pikselde büyük değer döndürür. Ancak resimler gürültülüdür ve sayısallaştırma sonucu elde edilir. Bu yüzden özelliğin yeri biraz rastgele olabilir: bu piksel, yan piksel, öbür piksel. Özelliğin tam yeri belli olmadığı için işlemin konuma biraz gürbüz (robust) olması istenir. Hoca bunu Hough dönüşümünde oyların yandaki biriktirici hücrelere de atılmasına benzetti.

Çözüm, filtre sonuçlarını havuzlamaktır (pool): küçük bir penceredeki sonuçlar istatistiksel olarak özetlenir ve böylece küçük değişikliklerden kurtulunur. Slayttaki ifade: "pooling" ile (örneğin max alarak) farklı konumlardaki filtre cevapları birleştirilince özelliklerin tam uzamsal konumuna karşı gürbüzlük kazanılır (ekrandan, 00:45:00).

### 4.2 Max havuzlama ve değişmezlik

Max havuzlama bir bölgedeki en büyük pikseli alır. Çıkış katmanındaki her değer, girdideki bir bölgenin sonucudur. Örneğin 3×3'lük bir komşulukta birçok piksel göze benzer cevap vermiş olsun; max havuzlama bunlardan göze en çok cevap vereni seçer. Böylece sisteme bir değişmezlik (invariance) eklenir: gözün yeri biraz değişse bile göz o bölgenin içinde kaldıkça bölgeden yine en büyük değer gelir, yani "burada göz var" bilgisi korunur.

Havuzlama x ve y yönünde değişmezlik sağlar, ama dönmeye karşı değişmezlik sağlamayabilir. Dönmeye değişmezlik için eğitim imgeleri döndürülerek verilebilir; bu aynı zamanda daha fazla veri elde etmek demektir.

### 4.3 Sinirbilimle bağlantı

Hoca CNN'lerin sinirbilimden en çok etkilenen ağlar arasında olduğunu anlattı. Beyin hücreleri üzerinde çalışan bilim insanları, ilk aşamada kenar bulucular gibi çalışan, Gabor filtrelerinin cevaplarına benzer cevap veren hücreler bulmuştur; bu bölgeye V1 alanı denir. Katman katman ilerledikçe bir noktada bazı hücrelerin değişmez (invariant) olduğu görülür: aynı şekli dönmüş halde de tanıyabilirler. Hocanın örneği: "çikolata" kavramına odaklanmış bir hücre, çikolatayı yazıda okuyunca da, duyunca da, resmini görünce de uyarılır. Bu hücre kavramın nasıl temsil edildiğine değişmezdir. Havuzlama katmanı da ağa bu tür bir değişmezlik katmayı sağlar.

### 4.4 Havuzlama türleri

Havuzlama, bir bölgeden bazı istatistiklerin çıkarılmasıdır ve farklı yöntemleri vardır. Slayttaki formüller (ekrandan, 00:50:00):

Max havuzlama:

$$
h_j^{n}(x,y)=\max_{\bar{x}\in N(x),\ \bar{y}\in N(y)} h_j^{n-1}(\bar{x},\bar{y})
$$

Ortalama havuzlama (average pooling):

$$
h_j^{n}(x,y)=\frac{1}{K}\sum_{\bar{x}\in N(x),\ \bar{y}\in N(y)} h_j^{n-1}(\bar{x},\bar{y})
$$

L2 havuzlama:

$$
h_j^{n}(x,y)=\sqrt{\sum_{\bar{x}\in N(x),\ \bar{y}\in N(y)} h_j^{n-1}(\bar{x},\bar{y})^{2}}
$$

Özellikler üzerinde L2 havuzlama (L2-pooling over features):

$$
h_j^{n}(x,y)=\sqrt{\sum_{k\in N(j)} h_k^{n-1}(x,y)^{2}}
$$

Max havuzlamada $(x,y)$'nin komşuluğundaki bütün $(\bar{x},\bar{y})$ noktalarının parlaklıklarının en büyüğü alınır. Ortalama havuzlamada örneğin 3×3'lük bölgedeki değerler toplanıp $K$'ya bölünür; hoca slaytta $1/K$ ile çarpımın güzel gösterilmediğini belirtti. L2 havuzlamada bölgedeki piksel değerlerinin kareleri toplanır ve karekök alınır.

Hoca son iki türün farkını sordu. Özellikler üzerinde havuzlama, özellik uzayında yapılır. Örneğin orijinal imge 8 filtreyle süzülmüş olsun; elde 8 cevap, yani 8 özellik haritası vardır. Özellikler üzerinde havuzlamada aynı piksel konumu sabit tutulur ve farklı özellik haritalarındaki değerler üzerinde L2 normu alınır. Hoca bu değerler üzerinde max havuzlama da yapılabileceğini ekledi.

### 4.5 Katman terimi

Hoca "katman" (layer) sözünün evrişimli ağlarda farklı anlamlarda kullanıldığını vurguladı. Kimi yazar evrişim, aktivasyon ve havuzlamayı birlikte tek bir katman sayar ya da bunlara aşama (stage) der; kimi de her birini ayrı katman sayar. Gösterilen slaytta $h^{n-1}$'den evrişimli katmanla $h^{n}$, ondan havuzlama katmanıyla $h^{n+1}$ elde ediliyordu.

Havuzlamanın bir sonucu özellik haritalarının boyutunun düşmesidir. Hoca 2×2'lik bir havuzlama filtresinde dört değerin bire indirildiğini, yani imgenin boyutunun yaklaşık yarıya indiğini söyledi.

> **Ders sonrası not:** Örtüşmeyen 2×2 havuzlama genişliği ve yüksekliği ayrı ayrı yarıya indirir, piksel sayısı dörtte bire düşer. Dersin ilerleyen kısmında 4×4 max havuzlama için de "imge yarıya düşer" dendi; bu yalnız pencereler adım 2 ile örtüşerek kaydırılırsa doğrudur, adım 4 ile örtüşmeyen 4×4 havuzlama her boyutu dörtte bire indirir.

## 5. Alıcı Alan, Stride, Padding ve Dilation

### 5.1 Alıcı alan

Slaytta havuzlama katmanındaki her ünitenin girdide ne kadar büyük bir alana bağlı olduğu hesaplanıyordu (ekrandan, 00:55:00):

> Evrişim filtreleri K×K boyutunda ve adımı (stride) 1 ise, havuzlama katmanının havuz boyutu P×P ise, havuzlama katmanındaki her ünite (önceki evrişim katmanının girdisinde) $(P+K-1)\times(P+K-1)$ boyutunda bir yamaya bağlıdır.

Yani hesap havuzlamadan evrişime, oradan da girdiye doğru geriye gider ve havuzlama katmanındaki bir sonucun ne kadar büyük bir alandan geldiğini bulur.

> **Ek bilgi (derste anlatılmadı):** Formül şöyle okunabilir: P×P havuz penceresi evrişim çıktısında P×P komşu ünite kapsar; adım 1 olduğundan bu ünitelerin her biri girdide bir öncekinden bir piksel kaymış K×K'lık bir pencereye bakar. Kapsanan alan bu yüzden her boyutta $P+(K-1)$ olur. Örneğin 2×2 havuz ve 3×3 filtre için 4×4'lük bir alan (hesap ajan tarafından yapıldı).

### 5.2 Stride

Hoca öğrencilere stride'ın ne olduğunu sordu. Bir öğrenci filtreyi yana doğru birer birer kaydırarak bakmak olduğunu söyledi. Hoca örnekle açıkladı: filtre önce bir konumdan değer alıyor; bir sonraki değeri hemen yandaki pikselden değil de üç sonraki pikselden alıyorsa stride 3 olur. Hoca bu sırada tablet üzerinde bir ızgara çizip "stride = 3" ve "padding" yazdı (ekrandan, 01:05:00).

### 5.3 Padding

Evrişimde dolgu (padding) yapılmazsa imge boyutu her evrişimde küçülür. Hocanın örneğinde küçük bir imge üzerinde 5×5'lik bir filtre gezdiriliyordu. 5×5 filtrenin cevabı yalnız filtrenin imgeye tamamen sığdığı merkez konumlarda verilebilir; kenarlarda cevap yoktur. Bu yüzden imge her boyutta 4 piksel küçülür (her kenardan 2 piksel). Derin ağlarda yüzlerce katman olabildiği için yüzlerce küçülme sonunda girdi imgesi çok küçülebilir, hatta yok olabilir. Bunu önlemek için evrişimden önce imgenin kenarları sıfırlarla doldurulur; buna padding denir.

### 5.4 Dilation

Hoca bir yerde gördüğü bir yapıyı da anlattı: 3×3'lük bir filtre, imgede bitişik pikselleri değil, birer piksel atlayarak seçilmiş pikselleri alır ve sonucu çıktı imgesine yazar. Filtre sanki şişirilmiş ya da genişletilmiş gibi uygulanır. Aslında bu 3×3'lük filtre, araları sıfır olan 5×5'lik bir filtre gibi davranır. Hoca bu piksel aralığının adını hatırlayamadı; bir öğrenci sohbetten "atrous" ya da "dilation" dendiğini yazdı, hoca da dilation olabileceğini kabul etti. Hocaya göre çok sık karşılaşılan bir yapı değildir.

## 6. Yerel Kontrast Normalizasyonu

Slayttaki bir başka işlem yerel kontrast normalizasyonuydu (local contrast normalization, LCN). Formül (ekrandan, 01:00:00):

$$
h^{i+1}(x,y)=\frac{h^{i}(x,y)-m^{i}(N(x,y))}{\sigma^{i}(N(x,y))}
$$

Bu işlem bir tür standartlaştırmadır. $(x,y)$ pikselinin çevresinde örneğin 3×3'lük bir komşuluk $N(x,y)$ düşünülür. Bu komşuluktaki değerlerin ortalaması ($m$) ve standart sapması ($\sigma$) alınır. Pikselin değerinden ortalama çıkarılır ve sonuç standart sapmaya bölünür. Böylece o bölge içinde bir normalizasyon yapılmış olur.

Hocanın yorumuna göre amaç değerlerin büyüklüklerini standartlaştırmak, benzer renk değişimlerinin benzer sonuç vermesini sağlamaktır. Slayta göre bu işlem özellikler üzerinde de yapılabilir; yani komşuluk özellik uzayındaki bir komşuluk olabilir ve daha üst katmanlarda kullanılır. Slaytta LCN'nin değişmezliği, optimizasyonu ve seyrekliği (sparsity) iyileştirdiği yazıyordu. Hoca konunun "local contrast normalization" adıyla araştırılabileceğini söyledi.

## 7. Tipik Aşama, Tipik Mimari ve SIFT ile Benzerlik

### 7.1 Bir aşama

"ConvNets: Typical Stage" slaytında bir aşama şöyleydi (ekrandan, 01:10:00): evrişim (Convol.) → LCN → havuzlama (Pooling). Hoca terminolojinin yazara göre değiştiğini yineledi. Bu yazar evrişimden sonra LCN'yi araya koymuş, ardından havuzlama yapmıştır. ReLU da vardır: şekilde "Rectification + Contrast Normalization" adıyla doğrultma (ReLU) ve kontrast normalizasyonu tek bir blok olarak gösterilmişti.

Şekildeki akış şöyleydi: tek bir girdi imgesi ya da girdi katmanı ile başlanır. Filtre bankası (filter bank) imgeye uygulanır. Eğitim, bu filtrelerin katsayılarını bulmaktır. Eğitimden sonra filtrelere bir resim olarak bakıldığında filtrenin neye "heyecanlandığı", hangi girdide uyarıldığı görülebilir; hoca bunun ilginç bir çalışma olduğunu söyledi. Örneğin 200 filtre varsa her biri bir sonuç verir. Sonuçlar ReLU'dan ve LCN'den geçirilir, ardından havuzlama yapılır; örneğin 4×4'lük max havuzlama 4×4'lük alanlardan en büyük değerleri getirir ve imge boyutu küçülür.

### 7.2 SIFT ve DoG ile benzerlik

Hoca bu yapıyı daha önce görülen SIFT'e benzetti (HOG da SIFT benzeri bir bölge tanımlayıcıdır). DoG (Difference of Gaussian) yönteminde orijinal imge farklı sigma değerli Gauss filtreleriyle art arda süzülerek farklı ölçeklerde görüntüler elde ediliyordu. Sonra imge yarıya indiriliyor (alt örnekleme, subsampling), yine birkaç filtreleme yapılıyor, yine yarıya indiriliyordu; bu grupların her birine oktav deniyordu. Bu yapıda hem x-y uzayında hem ölçek uzayında özellik aranıyordu.

CNN'de de buna çok benzer bir şey olur: havuzlama bu yarıya indirme işine, evrişim katmanları da katman katman filtrelemeye karşılık gelir. En büyük fark şudur: SIFT'te filtreler insanlar tarafından tasarlanır (Gauss, Gauss ile türev filtresi vb.); CNN ise filtreleri eğitim setine göre kendisi tasarlar.

> **Ders sonrası not:** Hoca DoG anlatımında bir yerde "filtreyi yarıya indiriyorduk" dedi, sonra "filtrenin boyutunu, imge boyutunu" diye düzeltti. Oktavlar arasında yarıya indirilen imgenin boyutudur.

### 7.3 Bütün sistem

Belirli sayıda evrişimli aşamadan sonra sınıf etiketlerini elde etmek için genellikle en sona tam bağlı katmanlar, yani normal bir sinir ağı eklenir (ekrandan, 01:15:00): girdi imgesi → 1. aşama → 2. aşama → 3. aşama → tam bağlı katmanlar → sınıf etiketleri. Böylece aşamalara kadar olan kısım özellik çıkarma, sonrası MLP gibi standart bir yapay sinir ağı olur. Hoca bu son kısımda SVM gibi başka algoritmaların da kullanılabileceğini, ama pratikte bütün yapı türevlenebilir bir sinir ağı olduğu için mimarinin sinir ağıyla sürdürüldüğünü söyledi. Karşılaştırma için slaytta, bir dönem sunulan SIFT tabanlı bir yöntem gösterildi: önce SIFT öznitelikleri çıkarılıyor, sonra K-means, sonra piramit, sonra SVM uygulanıyordu.

## 8. Evrişimli Ağların Eğitimi

Evrişimli ağların eğitiminde tam bağlı ağlara göre bir fark yoktur, çünkü bütün işlemler yine türevlenebilir. Bu yüzden standart geri yayılım algoritması kullanılabilir; geri yayılımla türevler bulunur ve gradyan inişi ya da stokastik gradyan inişi uygulanır.

Eğitim genelde mini batch'lerle yapılır: ne bütün veriyle, ne de örnekler tek tek verilerek. Bir mini batch ile ileri yayılım (forward propagation) yapılır, geri yayılımla türevler bulunur, türevlerden yararlanarak stokastik gradyan inişi ya da başka bir yöntemle parametreler güncellenir.

## 9. ImageNet ve Sınıflandırma Mimarisi

### 9.1 ImageNet

Hoca slaytlardaki başarılı ağ sonuçlarının (2012 vb.) artık geride kaldığını, ama ImageNet'in önemli olduğunu söyledi. ImageNet büyük bir veri tabanıdır ve onu kullanan, yıllardır süren bir yarışma vardır; bu yarışmayı genelde CNN'ler kazanır. Slayttaki örnek hiyerarşi (ekrandan, 01:20:00): mammal → placental → carnivore → canine → dog → working dog → husky. Altında husky için WordNet benzeri bir sınıf ağacı (husky, working dog, dog, canine, carnivore, placental, mammal, vertebrate, ..., entity) vardı. Kaynak: Deng ve ark., "Imagenet: a large scale hierarchical image database", CVPR 2009.

### 9.2 Krizhevsky ve arkadaşlarının ağı

Hocaya göre CNN'leri popüler eden makale büyük olasılıkla 2012'de ImageNet yarışmasında büyük başarı kazanan Krizhevsky ve arkadaşlarının çalışmasıdır. Hoca hatayı bir yıl içinde %25'lerden %16'lar civarına düşürdüklerini, yani bir önceki yıla göre hatada büyük bir atlama yaptıklarını söyledi.

> **Ders sonrası not:** Hoca rakamları "sanırım" diyerek verdi. Büyük olasılıkla doğru değerler ILSVRC 2012'de ilk 5 (top-5) hatası için ikinci sıradaki yaklaşık %26'ya karşı yaklaşık %15,3'tür.

Mimari slaytı (ekrandan, 01:25:00), girdiden çıktıya doğru:

| Katman | Parametre | Flop |
|---|---|---|
| CONV | 35K | 105M |
| LOCAL CONTRAST NORM | | |
| MAX POOLING | | |
| CONV | 307K | 223M |
| LOCAL CONTRAST NORM | | |
| MAX POOLING | | |
| CONV | 884K | 149M |
| CONV | 1.3M | 224M |
| CONV | 442K | 74M |
| MAX POOLING | | |
| FULLY CONNECTED | 37M | 37M |
| FULLY CONNECTED | 16M | 16M |
| LINEAR | 4M | 4M |
| Toplam | 60M | 832M |

Kaynak: Krizhevsky ve ark., "ImageNet Classification with deep CNNs", NIPS 2012.

Hoca yapıyı aşamalara ayırdı: evrişim, LCN, max havuzlama (1. aşama); aynısı bir kez daha (2. aşama); sonra üç evrişim ve bir max havuzlama (bu aşamada LCN yok); en sonda tam bağlı katmanlar. "Linear" katmanında artık iki boyutlu özellik haritaları yerine tek boyutlu bir vektör düşünülür. Bu vektörün boyutu kategori sayısına göre ayarlanırsa kategori tahmini yapılabilir.

### 9.3 Parametre sayıları üzerine

Slayttaki değerler, evrişim katmanlarının parametre sayısının tam bağlı katmanlara göre çok daha az olduğunu gösterir.

- Evrişim katmanları: $35\text{K}+307\text{K}+884\text{K}+1{,}3\text{M}+442\text{K}\approx2{,}97\text{M}$.
- Tam bağlı ve doğrusal katmanlar: $37\text{M}+16\text{M}+4\text{M}=57\text{M}$.
- Toplam: yaklaşık 60M (slayttaki değer).
- Flop: $105+223+149+224+74+37+16+4=832$M (slayttaki toplamla tutuyor; toplamlar ajan tarafından python ile kontrol edildi).

> **Ders sonrası not:** Hoca tam bağlı kısım için "41 milyon, 45 milyon" dedi; slayttaki değerlerin toplamı 57 milyondur. Evrişim kısmı için söylediği "3 milyon civarı" doğrudur.

**Soru:** Bu parametreler ağırlıklar mı oluyor? **Cevap:** Hoca, tam bağlı katmanlarda girdinin ağırlıkla çarpılıp bir yanlılık (bias) ile toplandığını hatırlattı. Evrişimli katmanlarda da yanlılık olabilir; anladığı kadarıyla bazen bütün filtreler için tek bir yanlılık, bazen her filtre için ayrı bir yanlılık kullanılır. Mimari çok çeşitli olduğu için ayrıntıyı bilmediğini ekledi. Ağırlıklar, yanlılıklar ve filtrelerin bileşenleri (katsayıları) eğitilmesi gereken parametrelerdir.

> **Hocanın vurgusu:** Hız istiyorsanız mümkünse tam bağlı katmanlardan kaçınmaya çalışmak gerekir; parametrelerin büyük kısmı oradadır.

Flop sayısının nasıl hesaplandığını hoca bilmediğini söyledi; veri sayısı çarpı parametre sayısı ya da bir parametre hesabı için gereken işlem sayısı (türev alma, çarpma vb.) düşünülmüş olabilir. Slayta göre toplam 832 milyon flop vardır.

## 10. Optimizasyon ve Genelleme

### 10.1 Momentumlu SGD

Optimizasyon slaytındaki değerler (ekrandan, 01:35:00):

- SGD with momentum:
  - Learning rate = 0.01
  - Momentum = 0.9
- Improving generalization by:
  - Weight sharing (convolution)
  - Input distortions
  - Dropout = 0.5
  - Weight decay = 0.0005

Hoca öğrenme oranını gradyan inişi güncellemesi üzerinde gösterdi ve tablete şunu yazdı, momentum terimi için yanına boş bir yer bıraktı:

$$
x^{(t+1)}=x^{(t)}-\eta\,\nabla f\!\left(x^{(t)}\right)+\ \ldots
$$

Burada $\eta$ öğrenme oranıdır. Hoca momentumun denkleme nasıl girdiğini o an hatırlayamadı, internette kısaca aradı (ekrandan, 01:30:00) ve sonra fikri sezgisel olarak anlattı. Bir parçacığın hareket ettiğini düşünün: bir yerden başlayıp global minimuma ya da bulunduğu yerin yerel minimumuna gidecektir. Gidişini içinde bulunduğu çukurun şekli etkiler. Momentum, parçacığın mevcut hızını da bu gidişe eklemektir. Faydası şudur: yol üzerinde küçük yerel minimumlar varsa parçacık bu hızla, momentumla onları aşabilir. Momentum, hızın güncelleme ya da optimizasyon denklemine eklenmesidir.

> **Ek bilgi (derste anlatılmadı):** Momentumlu SGD'nin yaygın bir biçimi şudur: $v^{(t+1)}=\mu\,v^{(t)}-\eta\,\nabla f(x^{(t)})$, $x^{(t+1)}=x^{(t)}+v^{(t+1)}$. Burada $v$ hız, $\mu$ momentum katsayısıdır (slayttaki 0.9). Hocanın denklemdeki boş bıraktığı terim büyük olasılıkla $\mu\,v^{(t)}$ terimine karşılık gelir.

### 10.2 Genelleme yöntemleri

Ağırlık paylaşımı (evrişim), girdi bozulmaları (input distortions), dropout ve weight decay genellemeyi iyileştiren yöntemler olarak listelenmişti. Hoca dropout'u, ünitelerin bir kısmının bir iterasyonda, bir kısmının başka bir iterasyonda kullanılması diye açıkladı. Weight decay için optimizasyon denklemine sabit bir terim eklendiğini, bunun ağırlıkların daha küçük kalmasını sağladığını, yani parametrelerin çok büyümesini engellediğini söyledi; tam denklemi hatırlamadığını ekledi.

> **Ek bilgi (derste anlatılmadı):** Weight decay genellikle kayıp fonksiyonuna $\frac{\lambda}{2}\lVert w\rVert^2$ terimi eklenerek yapılır; güncellemede bu, her adımda ağırlığın $\eta\lambda w$ kadar sıfıra çekilmesi demektir. Slayttaki 0.0005 büyük olasılıkla bu $\lambda$ katsayısıdır.

### 10.3 Değerlendirme ve uygulamalar

Yarışmada her sınıflandırıcı her resim için en olası beş sınıfı döndürür; doğru sınıf bu beşin içindeyse sonuç doğru kabul edilir. Örnek sonuçlarda "mite" (akar) imgesi için tahminler arasında black widow, cockroach, tick, starfish gibi sınıflar vardı; bir başka örnekte doğru etiket cherry iken tahminler arasında dalmaçyalı da yer alıyordu. <!-- BELİRSİZ: Bu örnek sonuç slaytı karede görülmedi; sınıf adları altyazıdan alındı. --> Son slaytlarda CNN'lerin nesne bulma ile yüz doğrulama ve yüz tanıma (face verification and identification) için kullanımına örnekler gösterildi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:21:48): Bir evrişimli katmanda her biri 10×10 boyutunda filtreler öğreniliyorsa bu katmanın parametre sayısı nedir? <!-- BELİRSİZ: Filtre sayısı altyazıda düşmüş; hocanın hesabından 100 filtre olduğu anlaşılıyor. -->

> **Çözüm:** Parametreler yalnız filtre katsayılarıdır. Bir filtrede $10\times10=100$ katsayı, 100 filtrede $100\times100=10.000$ parametre vardır (yanlılık sayılmadan).

**Soru 2** (derste sözlü, 00:50:48): L2 havuzlama ile özellikler üzerinde L2 havuzlamanın farkı nedir?

> **Çözüm:** L2 havuzlamada tek bir özellik haritasında $(x,y)$'nin uzamsal komşuluğundaki değerlerin karelerinin toplamının karekökü alınır. Özellikler üzerinde L2 havuzlamada konum $(x,y)$ sabittir; aynı konumun komşu özellik haritalarındaki ($k\in N(j)$) değerleri üzerinde L2 normu alınır.

**Soru 3** (derste sözlü, 00:55:22): Stride nedir?

> **Çözüm:** Filtrenin imge üzerinde bir konumdan sonrakine geçerken atladığı piksel sayısıdır. Filtre bir sonraki değeri üç piksel ötedeki konumdan alıyorsa stride 3'tür.

**Soru 4** (derste sözlü, 01:04:10): 3×3'lük bir filtre bitişik pikseller yerine aralarında boşluk bırakılmış piksellere uygulanıyorsa (filtre genişletilmiş gibi), bu yapıya ne denir?

> **Çözüm:** Dilation (genişletilmiş ya da atrous evrişim). Birer piksel atlanarak uygulanan 3×3 filtre, araları sıfır olan 5×5'lik bir filtre gibi davranır.

**Soru 5** (ekrandan, 00:55:00): K×K boyutlu, adımı 1 olan evrişim filtrelerinin ardından P×P'lik havuzlama geliyorsa, havuzlama katmanındaki bir ünite evrişimin girdisinde ne kadarlık bir yamaya bağlıdır?

> **Çözüm:** $(P+K-1)\times(P+K-1)$. Örneğin $K=3$, $P=2$ için 4×4 (sayısal örnek derste verilmedi, ajan tarafından hesaplandı).

**Soru 6** (derste sözlü, 01:30:33): Momentum, gradyan inişi güncelleme denklemine nasıl girer?

> **Çözüm (derste verilmedi):** Hoca yalnız sezgisini anlattı: parçacığın mevcut hızı güncellemeye eklenir, böylece küçük yerel minimumlar aşılabilir. Yaygın biçim: $v^{(t+1)}=\mu\,v^{(t)}-\eta\,\nabla f(x^{(t)})$, $x^{(t+1)}=x^{(t)}+v^{(t+1)}$; slayttaki değerlerle $\eta=0.01$, $\mu=0.9$.

## Dersin Toparlaması

Bu derste tam bağlı katmandan başlayıp yerel bağlı katmana ve oradan evrişimli katmana gidilerek CNN'lerin neden imgelere uygun olduğu görüldü: yerel bağlantı ve ağırlık paylaşımı parametre sayısını milyarlardan binlere indirir. Evrişimli katmanın formülü, çok kanallı evrişim, havuzlama türleri ve havuzlamanın sağladığı ötelemeye değişmezlik, alıcı alan hesabı, stride, padding, dilation ve yerel kontrast normalizasyonu ele alındı. Bir aşamanın evrişim, ReLU ile LCN ve havuzlamadan oluştuğu, birkaç aşamadan sonra tam bağlı katmanlarla sınıflandırma yapıldığı anlatıldı; bu yapı SIFT/DoG ölçek uzayına benzetildi, farkın filtrelerin veriden öğrenilmesi olduğu vurgulandı.

Son kısımda eğitimde geri yayılım ve mini batch SGD'nin aynen kullanıldığı, ImageNet veri tabanı ve 2012 ImageNet mimarisinin parametre ve flop dağılımı, momentumlu SGD ile dropout ve weight decay gibi genelleme yöntemleri görüldü.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
