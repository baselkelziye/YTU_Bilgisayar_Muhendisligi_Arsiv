# Ders 7 Genişletilmiş Notu: Proje Sunumları: Diferansiyel Denklemler için ELM ve Uygulamalı Derin Öğrenme Projeleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu ders, dönem projelerinin sunulduğu bir oturumdur. Her bölüm bir öğrenci sunumunu ve hocanın sunum üzerine yaptığı teknik yorumları anlatır. Sunanların adları nota alınmamıştır.

## İçindekiler

- 1. Diferansiyel Denklemlerin Sinir Ağlarıyla Çözümü: PINN, DGM ve ELM
- 2. Hibrit CNN-LSTM ile İnsan Aktivitesi Tanıma
- 3. EEG ile Alzheimer ve Frontotemporal Demans Sınıflandırması
- 4. Güneş Işınımı (GHI) Tahmini
- 5. VGG16 ile Melanom Sınıflandırması
- 6. URL Tabanlı Oltalama Tespiti
- 7. Web Sitesi Metin Sınıflandırması
- 8. Kardiyovasküler Hastalık Tahmini: Makine Öğrenmesi ile LSTM/GRU Karşılaştırması
- 9. Walmart Haftalık Satış Tahmini
- 10. Sperm Morfolojisi Sınıflandırması
- 11. MobileNetV2 ile Meyve Tazelik Sınıflandırması
- 12. Ötegezegen Sistemlerinin Uzaklık Tahmini
- Örnek Sorular
- Dersin Toparlaması

## 1. Diferansiyel Denklemlerin Sinir Ağlarıyla Çözümü: PINN, DGM ve ELM

### 1.1 Çıkış noktası: Evrensel yaklaşım teoremi

Sunum, sinir ağı tabanlı diferansiyel denklem çözücülerinin dayandığı teoremle başladı. Slayttaki ifadeye göre en az bir gizli katmanı olan bir sinir ağı, yeterli sayıda nöron ve uygun bir aktivasyon fonksiyonu verildiğinde, herhangi bir sürekli fonksiyona istenen doğrulukta yaklaşabilir (ekrandan, 00:05:00). Bu alandaki bütün çalışmalar bu teoremin üzerine kurulur: Çözüm bir fonksiyon olduğuna göre, o fonksiyonu bir sinir ağıyla temsil etmek mümkündür.

Diferansiyel denklemler mühendislik ve fen bilimlerinde bağımsız değişkenlere göre türevlerin birbiriyle ilişkisini tanımlar. Analitik çözümü olan denklem sayısı azdır. Analitik çözümü olmayanlar için sayısal yöntemler kullanılır, ama bu yöntemlerin de kararlılık (stability), doğruluk (accuracy) ve hesap maliyeti (computational cost) açısından sorunları vardır. Derin öğrenme tabanlı yöntemlere bu yüzden başvurulur; kullanımları 2010'ların ortalarından itibaren yaygınlaşmıştır.

### 1.2 PINN ve Deep Galerkin yöntemi

Physics-Informed Neural Network (PINN) ile Deep Galerkin Method (DGM) yapı olarak birbirine yakındır. Ağın girdisi bağımsız değişkenlerdir ($x$, ya da $x$ ve $t$), çıktısı çözüm fonksiyonunun kendisidir ($u$). Yani ağ doğrudan çözümü modeller.

Eğitim şöyle işler:

- Bağımsız değişkenler ağa verilir, ağ bir $u$ tahmini üretir.
- Bu çıktının denklemde geçen türevleri alınır ve denklemin sol tarafı hesaplanır.
- Sol taraf sağ tarafa (sıfır ya da kaynak terimi) eşit olmalıdır. Eşit olmadığı kadar bir hata oluşur; bu artık (residual) kayıp fonksiyonu olarak kullanılır.
- Ağırlıklar geri yayılımla güncellenir ve epoklar boyunca artık küçültülür.

Eğitim sonunda ağırlıklarıyla birlikte ağın kendisi çözüm olur. Adi diferansiyel denklemlerde (ODE) bağımsız değişken tek olduğundan girdi tektir; kısmi diferansiyel denklemlerde (PDE) girdi sayısı iki ya da üç olabilir. Girdi sayısı iki yöntem için de denklemin yapısına bağlıdır.

PINN ile DGM arasındaki fark şudur: DGM yalnız bu sinir ağını kullanır. PINN ise denklemin fiziğini de modele verir: denklemin yapısını etkileyen parametreler, sınır koşulları ve başlangıç koşulları da ağa girer. Örneğin denklemde $\varepsilon$ gibi bir parametre varsa ve bu parametre değiştikçe çözümün eğimi değişiyorsa, $\varepsilon$ de ağa ek girdi olarak verilir. Böylece farklı parametre değerleri için genel bir çözüm öğrenilir. "Fizikle bilgilendirilmiş" ifadesi buradan gelir.

**Soru:** Bu ekstra girdi, türevin alındığı değişkenden bağımsız olan, ama denklemin çözümünü etkileyen sabitler mi? **Cevap:** Evet. Bu parametre türevi doğrudan etkilemez, ama denklemin yapısını ve çözümünü etkiler. Modele katıldığında daha iyi sonuç alınıyor.

### 1.3 Extreme Learning Machine (ELM)

ELM'nin amacı aynıdır, yapısı farklıdır. PINN ve DGM'de birden çok gizli katman ve geri yayılımla öğrenme vardır. ELM'de genellikle tek gizli katman bulunur; iki ya da üç kullanan da olur, ama daha fazlası kullanılmaz. Hoca, ELM'nin yeni bir teknik olmadığını, CNN'ler yaygınlaşmadan önce yoğun çalışılan eski bir yöntem olduğunu belirtti. Sunucuya göre diferansiyel denklem çözümünde kullanılması 2020'lerden sonra başlamıştır.

ELM'nin işleyişi:

- Girişten gizli katmana giden ağırlıklar ve gizli katmandaki yanlılıklar belli bir aralıkta rastgele seçilir ve sabit tutulur.
- Gizli katman çıktıları $V_1, V_2, \dots$ hesaplanır.
- Çözüm, bu çıktıların çıkış ağırlıklarıyla doğrusal birleşimidir. Öğrenilen tek parametre çıkış ağırlıklarıdır.

Slayttaki ifade (ekrandan, 00:15:00):

$$\text{ODE için:}\quad u(x)=\sum_{i=1}^{M} V_i(x_m)\,w_i,\qquad x\in\Omega$$

$$\text{PDE için:}\quad u(x,t)=\sum_{i=1}^{M} V_j(x_m,t_n)\,w_i,\qquad x,t\in\Omega$$

Burada $V_j(x,t)$ son gizli katmanın çıktısı, $w_j$ çıkış ağırlıklarıdır (eğitim parametreleri). Çözümün türevleri alınıp denklemin yapısına uygun biçimde yerine konur ve sağ taraftaki kaynak terimine eşitlenir. Toplama noktalarının her biri için bir denklem yazılınca, bilinmeyenleri $w$ olan çok sayıda doğrusal denklem elde edilir. Bu sistem en küçük kareler yöntemiyle bir kez çözülür ve eğitim tamamlanır. Sınır koşulları da sisteme eklenmelidir; sınır koşulu olmadan bir çözüm ailesi oluşur, sınır koşulu çözümü belirli hâle getirir.

En küçük kareler yöntemi sunumda şöyle özetlendi: Denklem sayısı bilinmeyen sayısından fazla olan bir cebirsel sistemde bütün denklemleri aynı anda tam sağlayan tek bir çözüm yoktur. Bütün denklemlere birlikte en çok yaklaşan $x$ aranır. ELM'de de bütün toplama noktalarındaki denklemlere en yakın çözümü veren ağırlık seti bulunur. Yalnız çıkış ağırlıkları optimize edildiği için hesap maliyeti düşüktür.

> **Ek bilgi (derste anlatılmadı):** $Hw\approx b$ biçimindeki aşırı belirli bir sistemin en küçük kareler çözümü $w=(H^\top H)^{-1}H^\top b$, yani $H$'nin Moore-Penrose sözde tersiyle $w=H^{+}b$ biçimindedir. ELM literatüründe çıkış ağırlıkları genellikle bu sözde tersle hesaplanır. $H$ matrisinin sütun sayısı gizli nöron sayısıdır; nöron sayısı çok artınca matris kötü koşullu hâle gelebilir.

**Soru:** ELM'de geri yayılım yok, değil mi? **Cevap:** Evet, yok. Hoca, ELM'nin derin öğrenmeden en büyük farkının geri yayılımla yinelemeli bir öğrenme sürecinin olmaması olduğunu vurguladı.

> **Ders sonrası not:** Hoca soru sırasında ELM'de ağın farklı $x$'lerle tekrar tekrar beslenip ağırlıkların ileri beslemeli olarak değiştiğini söyledi. Sunumda anlatılan yöntemde çıkış ağırlıkları yinelemeli güncellenmez; en küçük kareler ile tek adımda hesaplanır.

### 1.4 Sonuçlar: Tekil pertürbe ODE

Birinci test problemi tekil pertürbe (singularly perturbed) bir konveksiyon-difüzyon-reaksiyon denklemidir (ekrandan, 00:10:00):

$$-\varepsilon u''(x)+u'(x)+u(x)=g(x),\qquad u(0)=u(1)=0,\qquad \Omega=[0,1]$$

$g$, gerçek çözüm aşağıdaki gibi olacak şekilde seçilmiştir:

$$u(x)=\sin(x)\left(1-e^{-(1-x)/\varepsilon}\right)$$

"Tekil pertürbe" ifadesi, parametrelerden en az birinin çok küçük olmasına rağmen denklemin yapısını güçlü biçimde etkilemesi anlamına gelir. $\varepsilon$ küçüldükçe çözüm $x=1$ yakınında dikleşir. Eğim arttıkça sayısal yöntemler için de, ELM için de problem zorlaşır.

> **Ders sonrası not:** Slaytta üs $e^{-(1-x)\varepsilon}$ diye yazılmış (ekrandan, 00:10:00). Ekrandaki grafiğe uyan ifade $e^{-(1-x)/\varepsilon}$'dir. Python ile kontrol edildi: Bölme biçiminde tepe değerleri $\varepsilon=1$ için yaklaşık 0.19 ($x\approx0.54$), $\varepsilon=0.2$ için 0.50 ($x\approx0.68$), $\varepsilon=0.03$ için 0.76 ($x\approx0.89$) çıkar ve grafikteki üç eğriyle örtüşür. Çarpım biçiminde küçük $\varepsilon$ için çözüm neredeyse sıfır olurdu.

Hata değerleri (ekrandan, 00:20:00):

| $\varepsilon$ | Hata |
|---|---|
| 1 | $7.5274\times10^{-17}$ |
| 0.2 | $2.3182\times10^{-14}$ |
| 0.03 | $2.2023\times10^{-6}$ |

Grafikte gerçek çözüm (yeşil) ile ELM çözümü (mavi kesikli) üç $\varepsilon$ değeri için üst üste çakışıyor. $\varepsilon=0.03$ için $10^{-6}$ mertebesindeki hata bu denklem için iyi bir sonuçtur.

**Soru:** Tablodaki değerler doğruluk mu? **Cevap:** Hayır, hata değerleridir. Her noktadaki ELM çıktısı ile gerçek çözüm arasındaki farktır. $10^{-17}$ çok küçük bir hata demektir.

**Soru:** Tabloya göre $\varepsilon$ küçüldükçe mi problem zorlaşıyor? **Cevap:** Evet. Denklemde $\varepsilon$'un önünde eksi işareti vardır; en küçük $\varepsilon$ en dik çözümü verir ve en zor problemdir. $\varepsilon=1$ iken çözüm pürüzsüzdür ve $10^{-17}$'ye varan hatalar elde edilir.

Farklı $\varepsilon$ ve gizli nöron sayılarıyla bir tablo da gösterildi. Küçük $\varepsilon$'da az nöron yetmiyor. Nöron sayısı belli bir değeri aşınca hata artık düşmüyor, sabitleniyor. Sunucunun açıklaması: Nöron sayısı arttıkça en küçük kareler yönteminde çözülen matrisin boyutu büyüyor, çözüm zorlaşıyor ve hata bazen yükseliyor. Yani bir optimum nöron sayısı vardır.

### 1.5 Sonuçlar: Advection-diffusion ve Poisson denklemleri

İkinci problem klasik advection-diffusion (taşınım-yayılım) PDE'sidir. Bu denklem bir akışkanda ya da ısı probleminde bir büyüklüğün taşınmasını ve yayılmasını modeller. $V$ katsayısı taşınımın, $D$ katsayısı yayılımın ne kadar hızlı olduğunu gösterir. Taşınım hızı sabit tutulup farklı $D$ değerleriyle çözüm üretildi. İki boyutlu olduğu için 200 ile 500 arası nöron istenen hata düzeyine yetmedi; hata $10^{-5}$, $10^{-6}$ mertebesine kadar indi. Sunucuya göre bu, sayısal yöntemlerle karşılaştırınca iyi bir seviyedir.

Üçüncü problem, zamandan bağımsız ve iki boyutlu düzlemde tanımlı Poisson denklemidir. Salınımlı ve tepeli çözümleri yakalamak sayısal yöntemler için zordur. Bu örnekte ek olarak rastgele seçilen giriş ağırlıklarının hangi aralıktan ve hangi dağılımdan (uniform ya da normal) çekildiği incelendi. Aralığın çok küçük ya da çok büyük olması iyi sonuç vermedi; bir optimum aralık var. İki dağılımda da iyi sonuç alındı, uygun aralıkta hata $10^{-10}$ mertebesine kadar indi.

### 1.6 Tartışma: Veri seti olmadan eğitim

Bir öğrenci modelin hangi veri setiyle eğitildiğini sordu. Sunucu, bir veri seti olmadığını açıkladı: $x$ ve $t$ ile bir ağ (mesh) oluşturuluyor, bu noktalar modele veriliyor ve her nokta için bir $u$ üretiliyor. Etiket, denklemin sağ tarafındaki sıfırdır (ya da kaynak terimidir); model, denklemin artığını sıfıra eşitlemeye çalışarak eğitiliyor. Gerçek çözüm yalnız sonucu karşılaştırmak için kullanıldı, eğitime girmedi. ELM'de ise $u$, $V$'lerin $w$ ile doğrusal birleşimidir; türevler alınıp sıfıra eşitlenince bilinmeyen olarak yalnız $w$ kalır, bu da en küçük kareler ile bulunur. Ağırlıklar bulunduktan sonra herhangi bir $x$ verildiğinde çözüm doğrudan hesaplanır.

Hoca, derin öğrenmede ağırlıkların bir etikete göre hesaplanan hatayı küçültecek şekilde güncellendiğini, bu senaryoda o etiketin ne olduğunun tam oturmadığını söyledi ve konunun ayrıntılı okunması gerektiğini belirtti. Başka bir öğrenci de yapıyı, hata sinyaline göre ağırlıkların güncellendiği uyarlamalı (adaptif) kontrol sistemlerine benzetti.

> **Ders sonrası not:** Tartışmada "derin öğrenme gözetimli öğrenmedir, çıktının etiketi olmalı" denildi. PINN ve benzeri yöntemlerde kayıp büyük olasılıkla denklemin artığından ve sınır koşullarından kurulur; çözümün etiketli örneklerine gerek yoktur. Bu yüzden bu yöntemlere bazen "etiketsiz" ya da "fizik denetimli" öğrenme de denir.

## 2. Hibrit CNN-LSTM ile İnsan Aktivitesi Tanıma

### 2.1 Problem ve veri seti

İnsan aktivitesi tanıma (Human Activity Recognition, HAR) sistemlerinde veri ya görüntüden (kamera) ya da giyilebilir sensörlerden alınır. Sensör verisinde belli zaman aralıklarında yapılan aktivite etiketlenir ve makine öğrenmesi ya da derin öğrenme modeli "yürüyor, merdiven çıkıyor, merdiven iniyor" gibi bir sınıflandırma yapar.

Kullanılan veri setinde (yaklaşık 2021 tarihli) 22 katılımcıdan serbest yaşam ortamında yaklaşık 2 saat boyunca veri toplanmıştır. Sağ uyluğa ve arkaya iki adet üç eksenli ivmeölçer yerleştirilmiş, etiketleme için göğse takılan kameranın görüntüleri kullanılmıştır. Veri setinde yürüme, koşma, merdiven çıkma, merdiven inme, ayakta durma, oturma, uzanma gibi yaklaşık 12 aktivite vardır. Sunumda inaktif olarak işaretlenenler çıkarılıp 10 sınıf kullanıldı.

Çalışmanın motivasyonu: Güncel bir veri setinde daha önce denenmemiş bir ağı test etmek; Adam ve RMSprop optimizasyon algoritmalarını, farklı aktivasyon fonksiyonlarını ve farklı örneklem (pencere) boyutlarının etkisini karşılaştırmak.

### 2.2 Benzer çalışmalar

Slayttaki özet (ekrandan, 00:40:00):

- Elle ve otomatik öznitelik çıkarımının karşılaştırıldığı bir çalışmada elle öznitelik çıkarımı daha başarılı bulunmuş.
- İvmeölçer ve jiroskop verileri spektrogram görüntülerine dönüştürülüp önceden eğitilmiş modellerle (VGG, ResNet, MobileNet) öznitelik çıkarılmış; bu veri setinde %88 doğruluk.
- Sensör yönelimi (sensor orientation) HAR'da önemli bir zorluktur. Bunu aşmak için önerilen ön işlemeyle sınıflandırma performansı ortalama 0.30 artmış.
- Büyük ölçekli HUNT4 veri setiyle öz-denetimli (self-supervised) ön eğitim yapılıp 7 veri setine transfer öğrenme uygulanmış; başarı yaklaşık %74.

### 2.3 Öznitelik mühendisliği ve ön işleme

Veri setinde 6 temel öznitelik vardı: iki sensörün her birinden $x$, $y$, $z$ eksenleri. Bunlara yeni öznitelikler eklendi: iki sensör arasındaki eksen bazlı mesafe, özniteliklerin ortalaması, en büyük ile en küçük değer farkı. Ardından min-max ölçekleme yapıldı.

**Soru:** Zaman damgası (timestamp) kullanıldı mı? **Cevap:** Hayır. Hoca bunun anlamsız bir öznitelik olacağını onayladı.

Hoca iki sensör arasındaki mesafenin mantıklı bir öznitelik olduğunu söyledi. Biri uylukta, biri arkada olduğundan aradaki mesafenin kısalması oturmayı ya da çömelmeyi gösterebilir. HAR çalışmalarında yürüme ile merdiven çıkma/inme en çok karışan sınıflardır; oturma ve yatmada genellikle sorun olmaz. Bu mesafe özniteliği tam da karışan sınıfları ayırmaya katkı verebilir. Sunucu, bu öznitelikleri ekleyince veri boyutuna göre yaklaşık %3, %5, %10 iyileşme gördüğünü belirtti.

Veride yaklaşık 6 milyon örnek vardı. Hem işlem yükünü azaltmak hem de sınıfları dengelemek için 15 saniye, 30 saniye, 60 saniye ve 5 dakikalık pencerelerle dört ayrı veri seti oluşturuldu. Veri setinde katılımcı kimliği tutulmadığı için kişi bazlı ayırma yapılamadı; veriler yalnız sınıf bazında ayrılmıştı.

### 2.4 Model

Önerilen model (ekrandan, 00:50:00):

```text
Girdi
 -> Conv1D (128 filtre, kernel boyutu 2)
 -> MaxPooling
 -> Conv1D
 -> LSTM (64 birim)
 -> Dropout (0.1)
 -> LSTM
 -> Dense (64) -> Dense (32)
 -> Çıkış Dense (10, softmax)
```

CNN tercih edilme nedeni, az sayıdaki öznitelikten yeni öznitelik haritaları çıkarabilmesidir. LSTM ise sıralı ve birbirine bağımlı sensör verisinde zamansal ilişkileri iyi modeller. Sıralı verilerde aşırı öğrenme olasılığı yüksek olduğu için dropout eklendi. Diğer ayarlar: en çok 80 epok (100'de aşırı öğrenme artıyordu), early stopping (izlenen değer doğrulama kaybı, patience 5), kayıp fonksiyonu categorical cross entropy. Katman sayıları denemelerle belirlendi; örneğin konvolüsyon katmanı 3'ten 2'ye indirildi.

### 2.5 Sonuçlar

Her pencere boyutu için Adam/RMSprop ve tanh/ReLU kombinasyonları denendi. Aktivasyon fonksiyonu bir denemede bütün katmanlarda aynı tutuldu. 30 saniyelik veri seti için tablo (ekrandan, 00:55:00):

| Aktivasyon | Adam | RMSprop |
|---|---|---|
| tanh | Doğruluk 0.66, kayıp 0.94 | Doğruluk 0.64, kayıp 0.96 |
| ReLU | Doğruluk 0.64, kayıp 0.98 | Doğruluk 0.09, kayıp 2.30 |

Bütün veri setlerinde en iyi yapılandırma Adam + tanh oldu. Doğruluk 15 saniyede 0.62 (kayıp 0.97), 30 saniyede 0.66 (kayıp 0.94), 60 saniyede 0.72 (kayıp 0.77), 5 dakikada 0.73 oldu. Pencere büyüdükçe öğrenme bir miktar iyileşti. Eğitim ve doğrulama eğrileri bir noktaya kadar birlikte ilerledi; sonlara doğru ayrılmaya başladılar. Hoca, yayında bu veri seti için yaklaşık %76 raporlandığını hatırlattı.

### 2.6 Hocanın önerileri

**Early stopping ve checkpoint.** Hoca, early stopping'i eğitimi kesmek yerine checkpoint için kullanmayı önerdi: Eğitim tam epok sayısına (örneğin 80 ya da 150) kadar sürdürülür, en iyi doğrulama değerinin görüldüğü epokta model kaydedilir ve son tahminde bu kaydedilen model kullanılır. Böylece hem eğrinin tamamı görülür hem de en iyi model elde tutulur.

**Öğrenme oranı.** RMSprop genelde çok düşük öğrenme oranlarında daha etkili, Adam ise biraz daha yüksek oranlarda iyi çalışır. Öğrenme oranını düşürmek doğruluğu artırabilir ama yakınsama uzayacağından epok sayısını artırmak gerekebilir. Derste anlatılan öğrenme oranı zamanlaması (scheduling) da önerildi: Belli sayıda epokta bir öğrenme oranı $\gamma$ katsayısıyla (örneğin $\gamma=10^{-1}$) çarpılarak küçültülür. Aktivite tanıma gibi problemlerde bu genellikle öğrenmeyi iyileştirir.

> **Ders sonrası not:** Hoca "öğrenme oranını 10 ile çarpıp düşürmek" dedi. Kastedilen, öğrenme oranını $\gamma=0.1$ ile çarpmak, yani 10'a bölmektir.

**Kişi bazlı bilgi.** Farklı insanların koşma biçimleri farklı olabilir. Veri setinde katılımcı kimliği olsaydı kişiye özgü durumlar dikkate alınarak daha iyi sonuç alınabilirdi.

## 3. EEG ile Alzheimer ve Frontotemporal Demans Sınıflandırması

### 3.1 Veri seti

Veri seti 88 katılımcıdan oluşur: 36 Alzheimer (AD), 23 frontotemporal demans (FTD) ve 29 sağlıklı birey (CN). Veri setinde bir de MMSE skoru (hastalara uygulanan bilişsel değerlendirme testi) vardır. Kayıt özellikleri (ekrandan, 01:05:00):

- 10-20 uluslararası sistemine göre 19 kafa derisi elektrodu (Fp1, Fp2, F7, F3, Fz, F4, F8, T3, C3, Cz, C4, T4, T5, P3, Pz, P4, T6, O1, O2) ve mastoidlerde 2 referans elektrot (A1, A2).
- Katılımcılar oturur pozisyonda ve gözleri kapalı.
- Örnekleme hızı 500 Hz.
- Kayıt süreleri AD için ortalama 13.5 dakika (en az 5.1, en çok 21.3), FTD için 12 dakika (7.9–16.9), CN için 13.8 dakika (12.5–16.5). Toplam 485.5 dakika AD, 276.5 dakika FTD, 402 dakika CN.

Gözlerin kapalı olması EEG'de göz kaynaklı artefaktları azaltır. Veri setinin artefaktları temizlenmiş ve 0.5–45 Hz Butterworth filtreden geçirilmiş bir sürümü de vardır; sunumda bu sürüm kullanıldı.

**Soru:** MMSE skorunun yüksek olması normal, düşük olması Alzheimer anlamına mı geliyor? **Cevap:** Evet. Hoca bunun kullanılmamasının doğru olduğunu söyledi; tanıyı doğrudan belli eden bir öznitelik olurdu. Yaş da kullanılmadı, çünkü grupların yaş ortalamaları birbirine yakındı.

Hoca, katılımcılara kayıt sırasında bilişsel bir görev yaptırılmadığını, yalnız dinlenme durumunda kayıt alındığını not etti. Koku tanıma gibi bir uyaran verilirse (Alzheimer nörodejeneratif bir hastalık olduğundan koku algısı da etkilenir), uyaran sırasındaki EEG örüntüsünün daha ayırt edici olabileceğini anlattı.

### 3.2 Literatürdeki yaklaşımlar

İncelenen yayınlarda:

- Güç spektral yoğunluğu (PSD) ile sinyal delta, teta, alfa, beta, gama bantlarına ayrılmış ve bant güçleri öznitelik olarak kullanılmış.
- Bir çalışmada spektrum, karmaşıklık (complexity) ve senkronizasyon ölçülerine göre üç ayrı öznitelik çıkarımı yapılmış; Karar Ağacı, Random Forest ve SVM karşılaştırılmış.
- Sonuçlar doğruluk, duyarlılık (sensitivity) ve özgüllük (specificity) ile verilmiş.

Hoca, sunucunun bu üç ölçüyü öznitelik çıkarım yöntemi gibi anlatmasını düzeltti: Doğruluk, duyarlılık ve özgüllük modelin performans ölçüleridir.

### 3.3 Sunumdaki yaklaşım ve sorunlar

Amaç, PSD gibi el yapımı sinyal işleme adımları yerine 19 kanalın ham verisini doğrudan derin ağa verip ağın bu dönüşümü kendisinin öğrenip öğrenemeyeceğini görmekti.

- Kayıt uzunlukları iki yolla eşitlendi: kısa kayıtların sonuna sıfır eklemek ve kaydı kendi kendini tekrar ederek uzatmak. Sıfır ekleme daha iyi sonuç verdi.
- En uzun kayıt 640.860 örnek; 88 kayıt bu uzunluğa getirilince yaklaşık 56 milyon × 19 boyutlu bir matris oluştu.
- DNN: 3 gizli katman, 64 nöron, ReLU, öğrenme oranı 0.001, Adam, cross entropy kaybı (ekrandan, 01:15:00). Test doğruluğu yaklaşık %50'de kaldı, uzun eğitimlerde aşırı öğrenme görüldü.
- LSTM (gizli boyut 16, 3 katman) de anlamlı sonuç vermedi.
- PCA ile 19 kanal 5'e indirildi; yayındaki PSD öznitelikleri DNN'e verildi (%52, %47, %33); en sonda Random Forest ile yaklaşık %73 elde edildi.

**Soru:** Karmaşıklık matrisinde neden yalnız 0 etiketli gerçek satır dolu, 1 ve 2 etiketli satırlar boş? **Cevap:** Sunucu hatırlayamadı ve kodu kontrol etmesi gerektiğini söyledi. Hoca, tahmin sütunlarının boş olmasının "model çalışmadı" diye açıklanabileceğini, ama gerçek etiket satırlarının boş olmasının verinin modele yanlış verildiğini gösterdiğini belirtti. Grafikte doğrulama kaybının sıfırda sabit kalması da bunu destekliyordu (ekrandan, 01:15:00). Sunucu, her zaman adımına ayrı etiket verme ile her kayda tek etiket verme arasında karışıklık yaşadığını açıkladı.

**PCA ile frekans bantları.** Sunucu PCA ile alfa, beta, gama gibi bantlara ulaşmayı denediğini söyledi. Hoca bunu düzeltti: PCA, 19 kanaldan alınan veriyi daha az boyutlu bir uzaya taşır. Elde edilen 5 bileşen PCA'nın kendi uzayındaki eksenlerdir; alfa, beta, gama bantları değildir. Ham EEG'den belli frekans aralığındaki bileşeni çıkarmak PCA'nın işi değildir.

> **Ek bilgi (derste anlatılmadı):** PCA, verinin kovaryans matrisinin öz vektörlerini bulur ve veriyi en çok varyansı taşıyan bu yönlere izdüşürür; işlem zaman ekseninde frekansla ilgilenmez. EEG bantları ise Fourier ya da Welch yöntemiyle hesaplanan PSD'nin belli frekans aralıklarında toplanmasıyla elde edilir.

Veri setinin MATLAB'a özgü bir dosya biçiminde gelmesi nedeniyle birleştirme işleri MATLAB'da yapıldı; incelenen üç çalışmanın Python'da yapıldığı belirtildi.

## 4. Güneş Işınımı (GHI) Tahmini

### 4.1 Motivasyon ve veri

Güneş panellerinin üreteceği enerji, panele ulaşan güneş ışınımıyla doğru orantılı bir formülle hesaplanır. Bu yüzden belirli bir bölgeye günlük ne kadar ışınım geleceğini önceden tahmin etmek önemlidir. Güneş ışınlarının bir kısmı atmosferden geri yansır, bir kısmı bulutlara takılıp saçılır, bir kısmı yerden yansır, bir kısmı da doğrudan yüzeye ulaşır.

Veri, uydu görüntülerinden türetilmiş bir ulusal güneş radyasyonu veri tabanından API ile alındı; veri sağlayıcısı Afrika ve Avrupa'yı kapsayan Meteosat Prime Meridian (ekrandan, 01:30:00). Veri tabanı hava durumu ile birleştirilmiş sayısal kolonlar ve uydu görüntüleri olarak iki tür veri sunar; sunumda sayısal veri kullanıldı. Kod ortamı Python 3.11, Pandas 1.5.2, Keras 3.3.3, Scikit-learn 1.4.2 (ekrandan, 01:30:00). Veride boş kayıt yoktu.

Önemli öznitelikler:

- DNI: Doğrudan normal ışınım.
- DHI: Bulut ve atmosferden saçılarak gelen dağınık (yayılı) ışınım.
- GHI: Toplam yatay ışınım. Sunucuya göre DNI ve DHI'dan, açının kosinüsüyle çarpım ve toplam alınarak hesaplanır.

> **Ek bilgi (derste anlatılmadı):** Standart ilişki $\mathrm{GHI}=\mathrm{DNI}\cdot\cos\theta_z+\mathrm{DHI}$'dır; $\theta_z$ güneşin başucu (zenith) açısıdır. Bu yüzden DNI ve DHI hedefle birlikte girdide tutulursa model hedefi neredeyse doğrudan hesaplayabilir; bunları çıkarmak doğru bir tercihtir.

DNI, DHI ve yıl çıkarıldı; "clear sky" (bulutsuz gökyüzü) değişkenleri de tanımları anlaşılamadığı için çıkarıldı. Hedef GHI seçildi. Kalan öznitelikler arasında güneş başucu açısı (korelasyonu negatif ve güçlü), yüzey albedosu (yerden yansıma), bulut tipi (kategorik), çiğ noktası, bağıl nem, basınç, sıcaklık, rüzgâr yönü ve hızı, yağışa dönüşebilecek su miktarı (precipitable water) vardı. Sonuçta 14 öznitelik kullanıldı.

**Soru:** Bulutsuz gökyüzünde buluttan saçılan ışınım nasıl ölçülüyor? **Cevap:** Sunucu, değerlerin görüntü işleme ve güneşin o anki konumuna göre yapılan hesaplarla üretildiğini, bulutlu ve bulutsuz değerlerin farkını tam çözemediği için bu kolonları çıkardığını söyledi.

### 4.2 Gün, ay, saat öznitelikleri

**Soru:** Günün öznitelik olarak ne anlamı var? **Cevap:** Sunucu etkisini görmek için bıraktığını söyledi. Hoca, saatin belki anlamlı olabileceğini ama zaman serisinde zaman bilgisinin zaten sıranın içinde olduğunu açıkladı. Veri dakikalık alındıysa saat kolonu 60 satır boyunca, gün kolonu $60\cdot24$ satır boyunca aynı değeri taşır; bu kolonlar anlamsızdır ve modelde yapay bir etki (artefakt) oluşturur. Diğer öznitelikler (bulut tipi, çiğ noktası vb.) anlamlıdır.

### 4.3 Model ve sonuçlar

Model (ekrandan, 01:40:00):

```text
14 girdi
 -> Gizli katman (32 nöron, ReLU, L2 düzenlileştirme)
 -> Gizli katman (32 nöron, ReLU, L2 düzenlileştirme)
 -> 1 çıkış
Kayıp: MSE, Optimizer: Adadelta, Epok: 50
```

Adadelta, başlangıçta öğrenme oranı verilmeden çalışabildiği için seçildi. MSE ile birlikte MAE de izlendi. L1 düzenlileştirme ve daha az nöronlu (8 ve 4) varyasyonlar denendi; belirgin fark çıkmadı. Ölçeklenmemiş hedefle çıkışa sigmoid koymanın işe yaramayacağı da gösterildi; sigmoid çıktıyı 0–1 aralığına sıkıştırır, bu ancak hedef de 0–1 aralığına ölçeklenirse anlamlı olur.

> **Ders sonrası not:** Sunucu L2 düzenlileştirmenin aykırı değerlere fazla güç verdiğini söyledi. Aykırı değerlere duyarlılık büyük olasılıkla kayıp fonksiyonunun (MSE) özelliğidir; L2 düzenlileştirme ise büyük ağırlıkları cezalandırır.

Sunucu bir "doğruluk" değeri (0.77) raporladı. Hoca, hedef sayısal olduğu için bunun bir regresyon olduğunu ve hata ölçülerinin verilmesi gerektiğini teyit etti.

### 4.4 Hocanın önerisi: İki aşamalı model

Hedefin dağılımında sıfırda yaklaşık 80 bin örnekli büyük bir tepe vardı; bunlar gece saatleridir. Hoca bunun büyük bir veri dengesizliği olduğunu söyledi ve şunu önerdi:

- Önce ikili sınıflandırma: Işınım sıfır mı, değil mi?
- Sonra yalnız sıfır olmayan örneklerde regresyon.

Sıfır değerli örneklerin regresyona girmesi anlamsız sonuçlar doğurur.

## 5. VGG16 ile Melanom Sınıflandırması

### 5.1 Problem ve kayıp fonksiyonu

Melanom, cilde bronz ya da kahverengi rengi veren hücrelerin kontrolsüz büyümesiyle oluşan bir deri kanseri türüdür. Literatürdeki çalışmalarda genellikle CNN, özel CNN mimarileri ve ResNet kullanılmış; en yüksek doğruluk ResNet ile alınmış. Sunumun referans aldığı makalede, kullanıcıların mobil uygulamayla cilt lekelerinin fotoğrafını çekip risk tespiti yapması amaçlanmış; doğruluk yaklaşık %84, precision 72, recall 40, F1 51.

Kayıp fonksiyonu, gerçek değerle tahmin arasındaki farkı ölçer (ekrandan, 01:50:00). İkili sınıflandırmada binary cross entropy kullanıldı:

$$L=-\frac{1}{N}\sum_{i=1}^{N}\left[y_i\log p(y_i)+(1-y_i)\log\left(1-p(y_i)\right)\right]$$

Burada $N$ örnek (batch) sayısı, $y_i$ gerçek değer, $p(y_i)$ modelin tahminidir.

### 5.2 Model

VGG16 önceden eğitilmiş model olarak kullanıldı. VGG16'da 13 konvolüsyon ve 3 tam bağlantılı katman olmak üzere 16 katman vardır. 3×3 filtreler kullanılır, filtre sayısı katmanlar ilerledikçe 64, 128, 256, 512 diye artar; aralarda max pooling vardır. Hoca bu kısmı derste anlattığı için hızlı geçilmesini istedi.

> **Ders sonrası not:** Sunucu VGG16'nın ImageNet'te "%97 küsür" başarı elde ettiğini söyledi. VGG16'nın ImageNet'teki top-5 doğruluğu büyük olasılıkla yaklaşık %92.7'dir.

VGG16'nın üzerine max pooling, flatten, dense, batch normalization ve dropout katmanları eklendi. Early stopping, model checkpoint ve ReduceLROnPlateau kullanıldı: Kayıp 3 adım boyunca iyileşmezse öğrenme oranı 0.1 ile çarpıldı; yaklaşık 6. ve 13. epoklarda öğrenme oranı düştü. Optimizer Adam. Veri setinde yaklaşık 10.600 eğitim ve 3.561 test görüntüsü vardı. 15 epokta test doğruluğu 0.8480, test kaybı 0.3489 (ekrandan, 01:55:00). F1, precision ve recall ise %51 civarındaydı.

### 5.3 Hocanın eleştirisi: Test kümesine augmentation

Kullanılan Kaggle veri seti, yayının yazarlarınca artırılmış (augmented) bir sürümdü. Hoca yayını inceleyip şu sorunları belirtti:

- Yazarlar veri artırmayı bütün veriye, test kümesi dahil, uygulamış. Bu yanlış bir süreçtir.

> **Hocanın vurgusu:** Metriklerin ölçüldüğü test kümesine hiçbir şekilde augmentation yapılmaz. Doğrulama kümesine yapmak bile soru işaretidir. Artırma yalnız ve yalnız eğitim kümesine yapılır.

- Artırma öncesindeki karmaşıklık matrisi toplamı yaklaşık 400 örnek ederken metinde çok daha büyük bir örnek sayısı verilmiş; yayın kendi içinde tutarsız.

**Soru:** %84 doğruluk ile %51 precision/recall nasıl birlikte çıkıyor? **Cevap:** Hoca, bu değerlerin birbiriyle uyumlu görünmediğini, karmaşıklık matrisinin yarı yarıya dağılmış göründüğünü, ekranda doğruluğun 0.71 yazdığını ve %84'ün eğitim ya da doğrulama doğruluğu olabileceğini söyledi. Sunucunun raporda bunu düzeltmesi gerekiyor.

> **Ders sonrası not:** Dengesiz ikili veride yüksek doğruluk ile düşük precision/recall birlikte görülebilir. Python ile hesaplandı: Pozitif sınıf verinin yaklaşık %15'i ise precision ve recall %51 iken doğruluk yaklaşık %85 olur. Yayındaki 84/72/40 üçlüsü de pozitif oranı %15 olan bir veride tutarlıdır (doğruluk yaklaşık %89). Bu nedenle tutarlılık her zaman karmaşıklık matrisinin kendisinden kontrol edilmelidir.

## 6. URL Tabanlı Oltalama Tespiti

### 6.1 Veri seti

İki açık veri seti birleştirildi. Her URL için uzunluk ve özel karakter sayıları (nokta, tire, alt çizgi, eğik çizgi, soru işareti, eşittir, @, &, ünlem, boşluk, tilde, virgül, artı, yıldız, diyez, dolar, yüzde, yönlendirme) öznitelik olarak verilmiş; hedef phishing (1) ya da değil (0). Veri tam dengeli değildir (yaklaşık %60–%40). Hoca, URL'de diyez işaretinin sayfa içi bağlantı için normal olabileceğini sordu; sunucu bir tanesinin sorun olmadığını, sayının 3–4'e çıkmasının oltalamaya işaret ettiğini söyledi.

### 6.2 Korelasyon matrisi

Korelasyon matrisinden (ekrandan, 02:05:00):

- `n_equal` ile `n_and` arasında 0.89 gibi yüksek bir korelasyon var.
- `url_length` ile `n_equal` 0.64, `n_and` 0.57 korelasyonlu.
- Hedefle (phishing) en yüksek korelasyon `n_slash` (0.61) ve `url_length` (0.43); ardından `n_equal` (0.26).

Hoca, asıl bakılması gerekenin özniteliklerin hedefle ilişkisi olduğunu vurguladı. Öznitelikler arası ilişkilerden de anlam çıkar: URL uzadıkça nokta ve alt çizgi sayısı artar.

### 6.3 Model ve sonuç

19 girdili, 3 gizli katmanlı (128 nöron) bir ağ kuruldu. Literatürdeki 256 nöronlu model ile 128, 64, 32'lik varyasyonlar denendi; en iyisi 128 oldu. 0.2 dropout, binary cross entropy, Adam; çıkışta sigmoid. 100 epok, veri %80 eğitim %20 test. Doğruluk yaklaşık %89, kayıp yaklaşık 0.26.

**Soru:** Raporlanan doğrulama doğruluğu mu, test doğruluğu mu? **Cevap:** Veri yalnız eğitim ve teste ayrılmış; test kümesi doğrulama olarak verilmiş.

Hoca, iki veri setiyle ayrı ayrı yapılmış çalışmaların sonuçlarının da verilmesi gerektiğini söyledi; aksi hâlde bulunan değerin iyi mi kötü mü olduğu yorumlanamaz.

## 7. Web Sitesi Metin Sınıflandırması

### 7.1 Veri ve keşif

Veri seti 1408 satır ve 3 sütundan oluşur: web sitesi URL'si, sitenin içeriğinden toplanmış kelimeler ve 16 kategoriden biri. Aynı veriyle yapılmış bir makalede Naive Bayes, Random Forest ve SVM ile yaklaşık %85 başarı alınmış. Verinin %30'u test, %70'i eğitim için ayrıldı. Bütün metinlerden ve her kategoriden ayrı ayrı kelime bulutları oluşturuldu.

### 7.2 Model

Model Keras ile kuruldu (ekrandan, 02:20:00):

| Katman | Çıktı boyutu | Parametre |
|---|---|---|
| InputLayer | (None, 1) | 0 |
| TextVectorization | (None, 1660) | 0 |
| Embedding | (None, 1660, 128) | 6,346,112 |
| GlobalAveragePooling1D | (None, 128) | 0 |
| Dense | (None, 64) | 8,256 |
| Dropout (0.4) | (None, 64) | 0 |
| Dense | (None, 16) | 1,040 |

Parametre sayıları python ile doğrulandı: Dense(64) için $128\cdot64+64=8256$, Dense(16) için $64\cdot16+16=1040$. Embedding'in parametre sayısı sözlük boyutu × 128'dir; buradan sözlük boyutu $6{,}346{,}112/128=49{,}579$ çıkar.

Ayrıca PyTorch ile URL'ler CountVectorizer'la vektöre çevrildi, kategoriler LabelEncoder ile kodlandı, cross entropy kaybı ve Adam ile tam bağlantılı ağlar denendi. Embedding katmanlı bir varyasyon daha iyi sonuç verdi; sunucunun yorumu, metnin doğru vektörlere dönüştürülmesinin belirleyici olduğuydu.

### 7.3 Hocanın eleştirisi

Hoca, sunulan modelin Kaggle'daki hazır bir notebook'un neredeyse aynısı olduğunu belirtti. Son katmanın arkasına bir dense katman daha eklemek ya da epok sayısını artırmak sonucu değiştirebilir, ama bir yenilik ya da emek sayılmaz. Gerçek bir değişiklik için örneğin konvolüsyon kanallarını ya da mimariyi gerekçeli değiştirmek gerekir; araya katman eklemek için boyutları hesaplamak gerekir (örneğin 1660 uzunluğa göre). Hazır modelleri kullanmak sorun değildir; farklı kaynakları araştırıp birleştirmek ve üzerine bir katkı koymak beklenir.

## 8. Kardiyovasküler Hastalık Tahmini: Makine Öğrenmesi ile LSTM/GRU Karşılaştırması

### 8.1 Veri ve ön işleme

Veri setinde 70 bin örnek, 11 girdi ve 1 hedef (kardiyovasküler hastalık var/yok) vardır. ID sütunu silindi. Değer aralığı diğerlerinden çok farklı olan dört sütuna (yüksek ve düşük kan basıncı, boy, kilo) min-max normalizasyonu uygulandı. Karşılıklı bilgi (mutual information) analizine göre kilo, kolesterol ve kan basınçları en etkili öznitelikler; boy, cinsiyet, sigara gibi öznitelikler daha az etkili. Korelasyon matrisinde kolesterol ile glikoz arasında yaklaşık 0.45 ilişki görüldü.

### 8.2 Modeller ve sonuçlar

Literatürde bu veri setinde 20 farklı makine öğrenmesi yöntemi denenmiş. Sunumda:

- Doğrusal SVM yaklaşık %67; doğrusal olmayan SVM daha iyi.
- Random Forest yaklaşık %72 (%75 eğitim / %25 test ayrımıyla).
- MLP (100 gizli nöron, en çok 1000 iterasyon) yaklaşık %73.
- LSTM: İki LSTM katmanı + iki dense katman, 30 epok, batch 16, %80/%20 ayrım; en iyi yaklaşık %74.
- GRU: Aynı katman yapısı; LSTM'den genellikle yaklaşık %1 düşük.

LSTM, önceki zaman adımlarından gelen bilgiyi hücre durumu ve kapı mekanizmalarıyla taşıyarak uzun vadeli bağımlılıkları öğrenir; standart RNN'lerin kaybolan gradyan sorununu azaltır (ekrandan, 02:35:00). GRU da benzer amaçla kullanılır, ama daha basit ve daha az parametrelidir.

**Soru:** Literatür tablosunda sinir ağı yaklaşık %50 verirken sende neden yaklaşık %71? **Cevap:** Sunucu aynı varsayılan ayarları kullandığını, farkın büyük olasılıkla normalizasyondan kaynaklandığını söyledi.

## 9. Walmart Haftalık Satış Tahmini

### 9.1 Veri

Veri seti 6435 örnek ve 8 öznitelikten oluşur: mağaza (45 farklı), tarih (2010–2012, 143 hafta), haftalık satış (hedef), tatil haftası bayrağı (0/1), sıcaklık, yakıt fiyatı, tüketici fiyat endeksi (CPI) ve işsizlik oranı. Boş değer yok.

**Soru:** İşsizliğin satışla ne ilişkisi olabilir? **Cevap:** Sunucu, işsizlik oranı arttığında alışveriş davranışının değişebileceğini söyledi. Hoca, bunun ülke genelindeki işsizlik olduğunu, 45 mağaza için aynı değerin kullanıldığını belirtti.

Tarih öznitelik olarak kullanılmadı; zaman serisi analizi yapılmadı ve tatil bilgisini tatil bayrağı zaten taşıyordu. Değer aralıkları çok farklı olduğu için (haftalık satış milyonlar mertebesinde, tatil bayrağı 0–1) StandardScaler ile standartlaştırma yapıldı. Standartlaştırma dağılımın biçimini değiştirmez, değerleri yaklaşık $-3$ ile $3$ arasına taşır.

### 9.2 Model ve sonuçlar

```text
6 girdi -> 16 -> 8 -> 4 -> 1 çıkış
Kayıp: MSE, Optimizer: Adam, batch: 32, %80 eğitim / %20 test
```

Beş farklı optimizer aynı veri bölünmesiyle denendi; en iyisi Adam. Öğrenme oranı taramasında 0.025 hem daha az dalgalanma hem de daha düşük kayıp verdi. Batch 16'da eğitim yavaşladı, 64'te sonuç kötüleşti. Test kümesinde ilk 30 örneğin tahmini ve gerçek değeri gösterildi (ekrandan, 02:50:00); örneğin tahmin 948408.62, gerçek 942970.63. Tüm test kümesi (yaklaşık 1200 örnek) üzerindeki standartlaştırılmış MSE 0.14, $R^2$ yaklaşık 0.80 idi. Gizli nöron sayıları artırılınca $R^2$ yaklaşık 0.90'a çıktı. Karar ağaçları tabanlı bir gradyan artırma yöntemi olan CatBoost daha hızlı çalıştı ve daha yüksek $R^2$ verdi.

**Soru:** CatBoost bir sinir ağı mı? **Cevap:** Hayır, karar ağaçlarından oluşan bir makine öğrenmesi algoritmasıdır.

## 10. Sperm Morfolojisi Sınıflandırması

<!-- BELİRSİZ: Bu sunumun altyazısı büyük ölçüde bozuk ve tekrar halüsinasyonu içeriyor; aşağıdaki içerik ağırlıkla ekrandan ve okunabilen kısımlardan alındı. -->

Sperm hücrelerinin boyut ve biçimindeki değişimler doğurganlığı etkiler; biçimin doğru tanımlanması tanı için önemlidir. Bilgisayar destekli semen analizi (CASA) sistemleri maliyet ve karmaşıklık nedeniyle birçok laboratuvarda sınırlı kullanılmaktadır.

Veri seti üç alt veri setinden (Boya1, Boya2, Boya3) oluşur; 18 sınıflı ve dengesizdir (AmorfHead, AsymmetricNeck, CurlyTail, DoubleHead, ... VacuolatedHead). Çalışma veri artırma yapılmadan orijinal veriyle yürütüldü. AlexNet, ShuffleNet, ResNet ve DenseNet ile üç senaryo denendi: softmax ile sınıflandırma, CNN öznitelikleri + SVM, CNN öznitelikleri + PCA + SVM. 5 katlı çapraz doğrulama, 50 epok ve 0.0001 öğrenme oranı kullanıldı.

Boya1 ve Boya2 için tablo (ekrandan, 03:05:00):

| Veri | Yöntem | AlexNet | ShuffleNet | ResNet | DenseNet |
|---|---|---|---|---|---|
| Boya1 | SVM | 0.23 | 0.20 | 0.16 | 0.19 |
| Boya1 | SVM+PCA | 0.30 | 0.28 | 0.19 | 0.19 |
| Boya1 | Softmax | 0.32 | 0.30 | 0.35 | 0.37 |
| Boya2 | SVM | 0.33 | 0.25 | 0.21 | 0.18 |
| Boya2 | SVM+PCA | 0.40 | 0.26 | 0.23 | 0.19 |
| Boya2 | Softmax | 0.46 | 0.43 | 0.49 | 0.54 |

En yüksek değer Boya2'de DenseNet + softmax ile 0.54'tür. Hoca, birinci senaryonun (CNN ile öznitelik çıkarımı + SVM sınıflandırma) çıktısını başka bir senaryonun girdisi olarak bağlamanın bir faydası olmadığını, yöntemler arasında karışıklık yarattığını söyledi.

## 11. MobileNetV2 ile Meyve Tazelik Sınıflandırması

### 11.1 Veri ve transfer öğrenme

Veri setinde üç meyvenin taze ve çürük hâlleri olmak üzere 6 sınıf, 1655 eğitim ve 456 test görüntüsü vardır. Görüntüler beyaz arka planlı ve 300×300 boyutundadır.

Transfer öğrenme, büyük veri setlerinde (ImageNet gibi) önceden eğitilmiş bir ağın ağırlıklarını kendi görsellerimizde kullanmaktır. VGG, ResNet, Inception gibi mimariler bu amaçla kullanılır; sunumda MobileNetV2 seçildi.

### 11.2 MobileNetV2 mimarisi

MobileNetV2'de standart konvolüsyon, depthwise konvolüsyon ve pointwise (1×1) konvolüsyon katmanlarından oluşan bloklar vardır. İki temel kavram:

- **Inverted residual:** Geleneksel residual bloklarda giriş ve çıkış geniş, ara katman dardır. MobileNetV2'de tersi geçerlidir: Dar bir girişten geniş bir ara öznitelik haritasına geçilir, sonra tekrar daraltılır. Bu parametre verimliliği sağlar.
- **Linear bottleneck:** Dar katmanlardan geçerken doğrusal olmayan aktivasyon yerine doğrusal dönüşüm kullanılır.

Bottleneck residual bloğu üç katmandan oluşur: expansion layer (kanal sayısını artırır), depthwise convolution ve projection layer (kanalları tekrar azaltır). Hoca bu kısmın hızlı geçilmesini istedi.

### 11.3 Sonuçlar

Veri artırma uygulanıp MobileNetV2 10 epok eğitildi. Eğitim ve doğrulama eğrileri düzgün ilerledi; doğrulama doğruluğu yaklaşık 0.97'ye, doğrulama kaybı yaklaşık 0.1'e ulaştı (ekrandan, 03:15:00).

Sıfırdan kurulan CNN: Ardışık konvolüsyon ve max pooling katmanları, flatten, iki dense katman. Öğrenme oranı 0.001, çok sınıflı olduğu için categorical cross entropy, early stopping, 20 epok, batch 32. Eğitim eğrileri çok dalgalı çıktı; az veri nedeniyle aşırı öğrenme görüldü.

**Soru:** %82 test doğruluğu ile bu karmaşıklık matrisi nasıl bir arada? **Cevap:** Sunucu da tutarsızlığı fark ettiğini söyledi. Hoca, karmaşıklık matrisinin %82'lik bir sonuca karşılık gelmediğini, raporda düzeltilmesini ve MobileNet için de karmaşıklık matrisinin verilmesini istedi.

## 12. Ötegezegen Sistemlerinin Uzaklık Tahmini

### 12.1 Veri ve öznitelikler

Veri seti yaklaşık 35.800 ötegezegen kaydı ve 92 öznitelik içerir (yaklaşık 25 MB): bağlı oldukları yıldız, yarıçap, kütle vb. Amaç, sistemin görünür parlaklığı (`sy_vmag`) ve yıldız yarıçapı (`st_rad`) kullanılarak sistemin Dünya'ya uzaklığını (`sy_dist`) tahmin etmekti. Korelasyon matrisi (ekrandan, 03:25:00):

| | sy_vmag | st_rad | sy_dist |
|---|---|---|---|
| sy_vmag | 1.00 | −0.29 | 0.54 |
| st_rad | −0.29 | 1.00 | 0.00 |
| sy_dist | 0.54 | 0.00 | 1.00 |

**Soru:** Bu iki büyüklükten uzaklığı veren matematiksel bir formül var mı? **Cevap:** Sunucu, ilişkinin doğrusal olmadığını ve doğrudan bir formül olmadığını söyledi. Hoca, parlaklığın Dünya'dan ölçüldüğü için uzaklıkla ilişkili olduğunu (yakın sistem daha parlak görünebilir) ve modelin bu ilişkiyi öğrenmeye çalıştığını özetledi.

> **Ek bilgi (derste anlatılmadı):** Astronomide görünür parlaklık $m$, mutlak parlaklık $M$ ve parsek cinsinden uzaklık $d$ arasında $m-M=5\log_{10}(d/10)$ ilişkisi vardır. $M$ yıldızın ışıma gücüne, bu da yarıçapın yanında sıcaklığa bağlıdır. Bu yüzden yalnız görünür parlaklık ve yarıçapla uzaklık tam belirlenemez; sıcaklık gibi bir öznitelik eklemek büyük olasılıkla sonucu iyileştirirdi.

Ötegezegen yarıçapı ile kütlesi arasında ön inceleme olarak doğrusal regresyon da yapıldı; hata yüksekti.

### 12.2 Model ve hiperparametre seçimi

2 girdi ve 1 çıkışlı bir ağ, MSE ile değerlendirildi. Hiperparametreler sırayla, birini sabitleyip diğerini deneyerek seçildi: önce tek katmanlı ve Adam'lı bir temel model üzerinde katman sayısı (en iyisi 4), sonra nöron sayısı (32–256 arasında, en iyisi 128), sonra optimizer (Adam, Nadam, RMSprop vb.; en iyisi Nadam; SGD kötü sonuç verdi), sonra aktivasyon (ReLU, sigmoid, tanh; en iyisi ReLU), sonra batch boyutu (en iyisi 64). Öğrenme oranı 0.001 sabit tutuldu.

**Soru:** Öğrenme oranıyla ilgili bir çalışma yapmadın mı? **Cevap:** Hayır, literatürde yaygın olduğu için 0.001 kullanıldı. SGD'nin kötü sonucu büyük olasılıkla öğrenme oranından kaynaklanıyor.

Sonuçta MSE çok yüksek çıktı. Tek katmanlı temel modelin kaybı slaytta 4.900 yazıyordu; hoca grafikte yaklaşık 50.000 göründüğünü belirtti ve sunucu değerin büyük olasılıkla 49.850 olduğunu kabul etti. Sonuç grafiği yerel ağırlıklı saçılım düzleştirme (LOWESS) ile çizildi. Hoca, düzleştirme sonrası aralık bazında hata hesaplanıp ortalamasının alınabileceğini söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:08:29): PINN ile Deep Galerkin yöntemi arasındaki fark yalnız girdi sayısı mı?

> **Cevap:** Hayır. Girdi sayısı iki yöntemde de denklemin bağımsız değişken sayısına bağlıdır. DGM yalnız sinir ağını kullanır; PINN ise denklemin parametrelerini, sınır ve başlangıç koşullarını da modele vererek genel bir çözüm üretir.

**Soru 2** (derste sözlü, 00:13:36): ELM'de geri yayılım var mı? ELM'yi derin öğrenmeden ayıran temel fark nedir?

> **Cevap:** Geri yayılım yoktur. Giriş ağırlıkları rastgele seçilip sabit tutulur; yalnız çıkış ağırlıkları en küçük kareler ile tek adımda hesaplanır. Yinelemeli bir öğrenme süreci yoktur.

**Soru 3** (ekrandan, 00:10:00 ve 00:20:00): $-\varepsilon u''+u'+u=g$, $u(0)=u(1)=0$ problemi için hata $\varepsilon=1$'de $7.5\times10^{-17}$, $\varepsilon=0.03$'te $2.2\times10^{-6}$ çıkmıştır. Hangi $\varepsilon$ daha zor problemdir, neden?

> **Cevap:** $\varepsilon=0.03$. $\varepsilon$ küçüldükçe çözüm $u=\sin x\,(1-e^{-(1-x)/\varepsilon})$ $x=1$ yakınında çok dikleşir (sınır tabakası); dik geçişi yakalamak zorlaşır ve hata büyür.

**Soru 4** (derste sözlü, 00:44:00): Sensör verisinde zaman damgası öznitelik olarak kullanılmalı mı?

> **Cevap:** Hayır. Zaman damgası aktiviteyle ilgili bir bilgi taşımaz ve anlamsız bir öznitelik olur.

**Soru 5** (derste sözlü, 01:15:09): Üç sınıflı bir problemde karmaşıklık matrisinde yalnız bir gerçek sınıfın satırı dolu, diğer gerçek satırlar boşsa ne düşünülmelidir?

> **Cevap:** Tahmin sütunlarının boş olması modelin bazı sınıfları hiç tahmin etmemesiyle açıklanabilir, ama gerçek satırların boş olması değerlendirme verisinde o sınıfların hiç bulunmadığını, yani verinin ya da etiketlerin modele yanlış verildiğini gösterir.

**Soru 6** (derste sözlü, 01:19:33): PCA ile EEG'nin alfa, beta, gama bantlarına ulaşılabilir mi?

> **Cevap:** Hayır. PCA kanalları daha az boyutlu bir uzaya taşır; elde edilen bileşenler frekans bantları değildir. Bantlar PSD gibi spektral analizle elde edilir.

**Soru 7** (derste sözlü, 01:44:43): GHI regresyonunda hedef dağılımında sıfırda büyük bir tepe var (gece verileri). Model nasıl kurulmalı?

> **Cevap:** Önce ikili sınıflandırmayla sıfır olan ve olmayan örnekler ayrılır, sonra yalnız sıfır olmayanlar regresyon modeline verilir.

**Soru 8** (derste sözlü, 01:58:20): Veri artırma hangi kümelere uygulanır?

> **Cevap:** Yalnız eğitim kümesine. Test kümesine hiçbir şekilde uygulanmaz; doğrulama kümesine uygulamak da tartışmalıdır.

**Soru 9** (derste sözlü, 00:54:38): Early stopping kullanırken en iyi model nasıl elde tutulur?

> **Cevap:** Eğitim sürdürülür, en iyi doğrulama değerinin görüldüğü epokta model kaydedilir (checkpoint) ve son tahminde bu model kullanılır.

**Soru 10** (ekrandan, 02:20:00): Girdisi 128 boyutlu olan Dense(64) katmanının ve ardından gelen Dense(16) katmanının parametre sayıları nedir?

> **Çözüm:** Dense katmanında parametre sayısı (girdi × çıktı) + çıktı (yanlılık) kadardır: $128\cdot64+64=8256$ ve $64\cdot16+16=1040$. Ekrandaki değerlerle aynıdır (python ile doğrulandı).

## Dersin Toparlaması

Bu oturumda dönem projeleri sunuldu. İlk sunum, sinir ağlarının diferansiyel denklem çözümünde nasıl kullanıldığını gösterdi: PINN ve DGM, ağın çıktısının türevlerini denkleme koyup artığı geri yayılımla küçültürken, ELM rastgele ve sabit gizli katmanla yalnız çıkış ağırlıklarını en küçük kareler ile tek adımda bulur. Tekil pertürbe bir ODE'de $\varepsilon$ küçüldükçe problemin zorlaştığı, nöron sayısının ve rastgele ağırlık aralığının bir optimumu olduğu görüldü. Diğer sunumlar zaman serisi (aktivite tanıma, EEG, güneş ışınımı, satış), görüntü (melanom, sperm morfolojisi, meyve) ve tablo/metin (oltalama, web sitesi, kardiyovasküler hastalık, ötegezegen) verileri üzerinde CNN, LSTM, GRU, transfer öğrenme ve tam bağlantılı ağları uyguladı.

Hocanın yorumlarından çıkan genel dersler şunlardır: Test kümesine augmentation yapılmaz; doğruluk, precision/recall ve karmaşıklık matrisi birbiriyle tutarlı olmalıdır; tanıyı doğrudan veren ya da zaman damgası gibi anlamsız öznitelikler kullanılmaz; zaman serisinde gün/ay/yıl kolonları gereksizdir; çok sayıda sıfır içeren hedefte sınıflandırma + regresyon gibi iki aşamalı bir model düşünülmelidir; early stopping en iyi modeli kaydetmek için kullanılmalıdır; regresyonda doğruluk değil hata ölçüleri raporlanır; hazır bir kodu küçük değişikliklerle çalıştırmak katkı sayılmaz.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
