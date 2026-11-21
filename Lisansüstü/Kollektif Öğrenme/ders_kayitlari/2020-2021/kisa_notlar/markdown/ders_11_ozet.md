# Ders 11 Çalışma Özeti

## Genel Konular

- Önceki dersin kısa hatırlatması: yapay sinir ağlarında kollektif öğrenme
  - Snapshot ensemble'lar ve bağımsız eğitimlerle erişilen lokal minimumların birbirine bağlı olduğuna dair deneysel bulgular hatırlatıldı.
  - Kararları değil ağırlıkları birleştiren SWA (Stochastic Weight Averaging) yöntemi: farklı noktaların ortalaması, iyi bölge ile kötü bölge arasındaki sınırlarda kalan noktalara göre etrafı daha geniş ve daha güvenli bir çözüm verir. Bu noktaları üretmek için döngüsel öğrenme oranı (learning rate) yaklaşımları kullanılır.
  - Hocanın Digits veri kümesindeki denemesi (ekrandan, 00:10:00): iki bağımsız eğitilmiş ağın 4., 7. ve 15. epoch sonundaki ağırlıkları arasına çizgi çekilip çizgi üzerindeki her nokta (yeni bir parametre vektörü) test edildiğinde, iki uç arasındaki vadinin epoch ilerledikçe derinleştiği görülür.
  - Aynı ağın ardışık epoch'larda eriştiği iki nokta arasındaki çizgi ileriye doğru uzatıldığında başarının bir süre daha artabildiği görülmüştü. Bu ilerleme gradyan hesabı gerektirmez. Son epoch'tan sonra bu artış görülmemişti.
- Öğretmen-öğrenci modeller, bilgi saflaştırma (knowledge distillation) (ekrandan, 00:15:00)
  - Amaç: büyük bir modelin performansına yakın performanslı ama daha küçük bir model elde etmek. Küçük model çalışma zamanında (test, ürün) daha hızlıdır ve daha az bellek kullanır.
  - Üç yaklaşım: öğretmen büyük bir model, öğrenci onu taklit eden küçük bir model; çok öğretmen, bir öğrenci (çok modeli tek bir modelle taklit etmek); eş kapasiteli öğretmen ve öğrenci.
  - İlk ikisinin amacı öğretmenden daha iyi olmak değil, ona yakın başarıda daha küçük bir model üretmektir. Eş kapasiteli durumda model küçülmez; amaç öğretmenden daha başarılı (daha iyi genelleştiren) bir öğrenci elde etmektir.
- Born Again Trees (1996) (ekrandan, 00:20:00)
  - Amaç: birçok karar ağacını (bir ensemble'ı) taklit eden tek bir ağaç üretmek.
  - Önce karar ağaçları orijinal veriyle eğitilip ensemble oluşturulur. Sonra yapay veri üretilir (smearing yöntemi), ama en başta değil.
  - Bir T düğümü bölünmeden önce veriler üretilir ve o ana kadar üretilmiş ağaca verilir. T düğümüne düşen üretilmiş verilerle bölünme hesaplanır. Üretim, T düğümüne önceden tanımlı NS adet yeni örnek düşene kadar sürer.
  - Üretilen örneklerin etiketleri ensemble ile hesaplanır. Üretilen ağaç budanır. Yeni ağaç, orijinal veriyle eğitilmiş tek ağaçtan daha büyük ve daha başarılıdır, ama ensemble'ın kendisinden daha başarılı değildir.
- Model Compression (2006) (ekrandan, 00:25:00)
  - Yapay sinir ağlarından oluşan bir ensemble'ı iyi taklit eden tek bir küçük ağ elde edilmek istenir.
  - Eldeki eğitim kümesinden çok daha büyük bir yapay eğitim kümesi üretilir (RAND, NBE, MUNGE yöntemleri). Yapay örneklerin sınıfları ensemble ile belirlenir, küçük model yeni örnek ve etiketlerle eğitilir.
  - Sonuç grafiği: yalnız 4K orijinal veriyle eğitilen ağa göre, 4K orijinal + 396K yapay veriyle (MUNGE) eğitilen ağın RMSE'si belirgin biçimde düşer. Rastgele üretim (RAND) neredeyse hiç kazanç sağlamaz. Saklı katmandaki nöron sayısı arttıkça hata düşer.
- Distilling the Knowledge in a Neural Network (2015) (ekrandan, 00:30:00)
  - $z_i$ (logit): softmax katmanının girişleri; $q_i$: softmax çıkışları; $T$: sıcaklık.
  - $q_i = \dfrac{\exp(z_i/T)}{\sum_j \exp(z_j/T)}$. Yüksek $T$ daha yumuşak (düz) bir dağılım verir.
  - Büyük model orijinal eğitim kümesiyle eğitilir; çıkışlar 1-hot encoding'dir (hard targets).
  - Transfer kümesi: girdiler orijinal eğitim örnekleri, çıkışlar büyük modelin yüksek $T$'li $q_i$'leri (soft targets). Küçük model yüksek $T$ ile transfer kümesinde eğitilir; test sürecinde $T=1$.
  - Alternatif kayıp: $w_1 \cdot$ cross_entropi(küçük model soft, büyük model soft) $+ \, w_2 \cdot$ cross_entropi(küçük model soft, hard targets).
  - Yayında 10 model, aynı büyüklükteki tek bir modele benzer performansla indirgenebilmiş.
- DistilBERT (2019) (ekrandan, 00:35:00)
  - BERT'in katman sayısı azaltılmış; parametre sayısı %40 düşmüş, hız %60 artmış, başarı orijinalin %97'si.
  - Üçlü kayıp: $L_{ce}$ (distillation loss), $L_{cos}$ (cosine embedding loss), $L_{mlm}$ (masked language modeling loss). Öğrencinin ağırlıklarının ilk değerleri öğretmenden alınmış. Ablasyon tablosunda $L_{mlm}$ en etkisiz bileşen çıkmış.
- Born-Again Neural Networks (2018) (ekrandan, 00:40:00)
  - Öğretmen ile eş kapasiteli öğrenciler ardışık eğitilir: öğretmen $T$ orijinal etiketlerle eğitilir, $S_1$ hem $Y$ hem $T$'nin soft çıkışlarıyla, $S_2$ $S_1$'in çıkışlarıyla eğitilir ve bu böyle sürer. Sonunda $S_1 \dots S_k$ birleştirilerek ensemble kurulur.
  - Bazı veri kümelerinde öğretmenden daha başarılı öğrenciler ve öğrencilerden daha başarılı bir öğrenci topluluğu elde edilmiş.
  - AdaBoost'a ardışık yapı bakımından benzer, ama her öğrenci aynı girdilerle eğitilir; örnek ağırlıklandırma yoktur.
- Çekişmeli üretici modeller (GAN) (ekrandan, 00:45:00)
  - Üretici sistem, verilen örneklere benzeyen yeni örnekler üretir (yüz, ayakkabı, manzara vb.).
  - Temel sorun: üretilen bir örneğin iyi mi kötü mü olduğunu anlamak. İnsan yargısı pahalı ve ölçeklenemez.
  - Çözüm: ikinci bir model (ayırıcı, discriminator) gerçek ve üretilmiş örnekleri ayırmaya çalışır; iki sınıflı bir sınıflandırmadır ve etiketler otomatik olarak bilinir. Ayırıcı ayıramamaya başladığında üretici yeterince iyi örnekler üretiyordur.
  - Üreticinin gerçek örnekleri kopyalamasını engellemek için girdisi yalnızca rastgele bir vektördür (gürültü).
  - Üretici, rastgele vektörü verinin bulunduğu manifoldun üzerine eşlemeye çalışır.
- Manifold kavramı (kâğıt örneği)
  - Üç boyutlu uzaydaki noktaların bir kâğıdın üzerinde olduğu düşünülür. Kâğıt büküldüğünde noktalar hâlâ üç boyutlu uzaydadır, ama manifold üzerindeki uzaklık ile üç boyutlu uzaydaki uzaklık artık aynı değildir.
  - 50x50'lik yüz resimleri 2500 boyutlu bir uzaydadır, ama bu uzaya düzgün dağılmazlar; bir manifoldun üzerinde bulunurlar ve dağılımları Gauss değildir.
- Proje konuları (akademik içerik)
  - Soft etiketli ağaçlar, Improved Space'in Python'da gerçeklenmesi, yapay örnek üretimi (SMOTE, SMOTE-IPF), online ağaçlarla ensemble, YSA çözümlerini birleştirmek, MCMC ile YSA hata-parametre yüzeyleri, YSA distill yöntemlerinin karşılaştırılması, karar/regresyon ağaçlarının hata-parametre yüzeyleri, ensemble yörüngeleri (ekrandan, 01:15:00–01:35:00).
- Üçüncü ödev sunumları (YSA hata-parametre yüzeyleri)
  - Öğrenciler başlangıç ve bitiş ağırlıklarını birleştiren çizgi, t-SNE ile ağırlık yörüngeleri ve farklı başlangıçlardan eğitilmiş modellerin son noktalarını birleştiren çizgiler üzerinde analizlerini sundu. Hocanın yorumları akademik noktalarıyla aşağıda özetlenmiştir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Karar ağacında derinlere inildikçe karar daha az örnekle verilir
  - Kök düğümün kararı bütün örneklerle verilir; bir alt seviyede ortalama yarısı, yapraklara yakın düğümlerde belki 5-6 örnek kalır. Verinin boyutu ise azalmaz: bin boyutlu uzayda 3-5 örnekle karar vermek varyansı çok yüksek bir iştir. Born Again Trees'in yapay veriyi "en başta değil", her düğümde üretmesinin nedeni budur.
  - Yapay sinir ağlarında böyle bir sorun olmadığı için Model Compression'da yapay veri en baştan üretilebilir.
- Saflaştırmada büyük modelin tek işi soft target üretmektir
  - Büyük modelin ağırlıkları küçük modele aktarılmaz (2015 yayınında). Küçük model orijinal etiketleri değil, büyük modelin davranışını taklit etmeye çalışır.
- GAN'ın asıl "hilesi" değerlendirmeyi başka bir modele yaptırmasıdır
  - Ayırıcının veri kümesi ve etiketleri otomatik oluşur; insan müdahalesi gerekmez. Ayırıcı da süreç boyunca eğitilmeye devam eder.
  - GAN eğitimi kararsızdır; ayırıcı yalnız "gerçek/sahte" gibi kaba bir geri bildirim verir.
- Gerçek eğitim yolu ile düz çizgi arasındaki fark (ödev sunumunda)
  - $V_0$'dan son noktaya giderken gerçekte izlenen yol üzerinde başarı dalgalanır ve bazen kötüleşir; oysa $V_0$ ile son noktayı birleştiren düz çizgi üzerinde böyle dalgalanma görülmez.
- Başlangıç noktası öğrenme oranını değiştirmez
  - Öğrenme oranı sabit tutulur; başlangıç noktası, oradaki gradyanın büyüklüğüne bağlı olarak atılan adımın büyüklüğünü değiştirir.
- Eğitilmemiş ağın başarısı şansa eşittir
  - Rastgele başlatılmış ($V_0$) bir ağın başarısı 10 sınıflı problemde yaklaşık %10, iki sınıflı dengeli problemde yaklaşık %50 olmalıdır. Çok yüksek bir başlangıç başarısı, grafiğin aslında 1. epoch sonundan ($V_1$) başladığını gösterir.
- İki boyuta indirgeme yanıltıcı olabilir
  - t-SNE/PCA ile iki boyutta yakın görünen noktalar gerçekte uzak olabilir; üç boyuttan ikiye inerken bile bakış açısına göre yakınlık değişir.

## Kısa Tekrar Notları

- Knowledge distillation: büyük model (öğretmen) → küçük model (öğrenci); amaç hız ve bellek.
- Üç tür: büyük öğretmen-küçük öğrenci, çok öğretmen-tek öğrenci, eş kapasiteli öğretmen-öğrenci (amaç öğretmeni geçmek).
- Born Again Trees (1996): ensemble'ı taklit eden tek ağaç; yapay veri (smearing) her düğümde, etiketler ensemble'dan; ağaç budanır.
- Model Compression (2006): büyük yapay küme (MUNGE en iyi, RAND işe yaramaz), etiketler ensemble'dan; 4K + 396K.
- Hinton ve arkadaşları (2015): $q_i = \exp(z_i/T) / \sum_j \exp(z_j/T)$; yüksek $T$ = yumuşak; öğrenci yüksek $T$ ile eğitilir, testte $T=1$.
- DistilBERT: %40 daha az parametre, %60 daha hızlı, %97 başarı; $L_{ce}+L_{cos}+L_{mlm}$.
- Born-Again Neural Networks (2018): eş kapasiteli ardışık öğrenciler ve onların ensemble'ı.
- GAN: üretici (girdi rastgele vektör) + ayırıcı (gerçek/sahte ikili sınıflandırma); ayırıcı ayıramayınca üretici iyidir.
- Manifold: veriler yüksek boyutlu uzayda düzgün dağılmaz, bükülmüş bir yüzey üzerinde durur; yerel uzaklık global uzaklıktan farklıdır.

## Detaylı Açıklamalar

- Bilgi saflaştırmanın motivasyonu
  - Elimizde 100 katmanlı bir model, bir de 10 katmanlı bir model olsun. Orijinal veriyle eğitilen 10 katmanlı model 100 katmanlıdan daha düşük başarı verir. Soru şudur: 100 katmanlı modeli de kullanarak, orijinal verinin yanına ek bilgi koyup 10 katmanlıyı ona yakın başarıya getirebilir miyiz? Saflaştırma yöntemleri bu soruya yanıt arar.
  - Hard target, bir örneğin tek bir sınıfa ait olduğunu söyler (one-hot: bir indis 1, diğerleri 0). Soft target ise "en olası A, sonra B, ..." gibi bütün sınıflara olasılık dağıtır. Öğrenci aynı girdilerle ama soft target'larla eğitildiğinde büyük modele yakın başarı gösterebilmiştir.
  - Soft target'lar başka bir yolla üretilebilseydi büyük modeli eğitmeye gerek kalmazdı; pratikte bunu sağlayan büyük modeldir.
  - Ders sonrası not: Hoca $q_i$'yi "$z$'lerin toplamına bölünmesi" diye özetledi; slayttaki formüle göre doğrusu, $\exp(z_i/T)$'nin bütün $\exp(z_j/T)$ değerlerinin toplamına bölünmesidir.
- Büyük dil modellerinin sıkıştırılması
  - BERT gibi modeller ve onlardan çok daha büyük yeni modeller küçük cihazlarda çalıştırılamaz; bu nedenle buluta bağımlı kalınır. Benzer performansta küçük modeller elde etmek son yıllarda çok aktif bir araştırma konusudur.
  - Masked language modeling: cümleden rastgele bir kelime kapatılır, model onu tahmin eder. BERT'in temel eğitimi budur; yanında cümlelerin ardışık olup olmadığı gibi tahminler de yaptırılabilir.
  - Öğrencinin ağırlıkları sıfırdan da başlatılabilir; DistilBERT'te ise BERT'in eğitilmiş ağırlıklarından (bazı katmanlar silinerek) başlatılmıştır. Ablasyon tablosuna göre (ekrandan, 00:35:00) GLUE makro skorundaki değişimler: $L_{ce}$ çıkarıldığında −2.96, $L_{cos}$ çıkarıldığında −1.46, $L_{mlm}$ çıkarıldığında −0.31, üçlü kayıp + rastgele ağırlık başlatma −3.69.
- GAN eğitimi
  - Sınıflandırmada model tahmini ile gerçek değer karşılaştırılır ve araya insan girmez. Üretimde ise üretilen resmin iyi olup olmadığına kimin karar vereceği sorunu vardır; bu işi ayırıcı model üstlenir.
  - Başlarda üretici iyi örnek üretemediği için ayırıcı çok başarılıdır. Zamanla ayırıcı gerçeklerle üretilmişleri ayırt edemez hale gelirse model "çalışmıştır" denir.
  - Bir öğrencinin gözlemi: ayırıcı yalnız "gerçek/sahte" dediği için üretilen örneğin hangi kısmının kötü olduğunu söylemez; neredeyse iyi bir örnek de tümden reddedilmiş olur. Bu durum genetik algoritmalardaki gibi rastgeleliğe güvenen bir arayışa benzer. Hoca bu gözleme katıldı ve GAN eğitiminin bu yüzden kararsız ve parametre ayarının zor olduğunu, yeni mimarilerin de bunu tam çözemediğini söyledi (kendisinin GAN uzmanı olmadığını belirterek).
- Proje konularının akademik özeti
  - Soft etiketli ağaçlar: eğitilmiş bir ağacın ya da ensemble'ın çıktılarıyla soft etiket üretilir, sonra bu etiketlerle ağaç ya da ensemble eğitilir; süreç iteratif sürebilir. Ensemble çıktısı zaten soft olduğu için etiket üretmek için ağacı değiştirmek gerekmez; ama soft etiketlerle eğitilebilen bir ağaç için bölme ölçütünün (information gain vb.) değiştirilmesi gerekir. Basit yazılmış bir karar ağacı kodunu değiştirmek önerildi.
  - Improved Space: Python'da gerçeklenip scikit-learn'deki RF, XGBoost gibi algoritmalarla karşılaştırılır; bir meta algoritma olduğu için imp_xgboost, imp_rf sürümleri de üretilir.
  - Yapay örnek üretimi: SMOTE, SMOTE-IPF ve benzerleriyle üretilen yapay örneklerin sayısının ve türünün YSA'lar üzerindeki etkisi; az sayıda yapay örnek iyileştirip bir noktadan sonra kötüleştirebilir.
  - Online ağaçlarla ensemble: örnekler tek tek gelir. Yeni örnek ağaçta doğru yaprağa düşerse değişiklik gerekmez; yanlış yaprağa düşerse en basit çözüm o yaprağı bir karar düğümüne çevirip eski örnekler ile yeni örneği ayırmaktır. Örnekler farklı sıralarla verilince farklı ağaçlar oluşur, bunlardan ensemble kurulup klasik ensemble'larla karşılaştırılır.
  - YSA çözümlerini birleştirmek: farklı ilk değerlerle eğitilmiş ağlar arasında test başarısını düşürmeden yollar bulunur; yollar üzerindeki noktalardan kurulan ensemble, yalnız son noktalardan kurulanla karşılaştırılır (en az 5 model; CIFAR-10/100 önerildi).
  - MCMC ile YSA hata-parametre yüzeyleri: eğitilmiş başarılı bir ağdan başlanır, MCMC ile benzer performanslı parametrelerin dağılımı keşfedilir ve PCA/t-SNE ile görselleştirilir. Bu dağılımın Gauss olması beklenmez; MCMC herhangi bir dağılımı keşfedebilir. Rastgele bir noktadan başlamak büyük olasılıkla başarılı bölgeye erişemez (genetik algoritmayla eğitmeye benzer).
  - Karar/regresyon ağaçlarının hata-parametre yüzeyleri: düğüm sayısı farklı ağaçlar aynı parametre uzayında gösterilemez, bu yüzden yapı sabitlenir; özellik/eşik değerleri $[0:0.1:1]$, sınıf sayısı 2. Bütün olası özellik-eşik-etiket bileşimleri için test başarısı t-SNE ile 2 boyutta görselleştirilir (en az 5 yapay veri kümesi). Uzay sürekli değil ayrık olduğu için dışbükey yüzeyler beklenmez.
  - Ensemble yörüngeleri: bir eksen kappa, diğeri ortalama tekil öğrenici hatası. 1) Tam ağaçlarla ensemble büyüklüğü arttıkça, 2) sabit ensemble büyüklüğünde tekil öğrenicilere verilen minimum derinlik/düğüm sayısı arttıkça oluşan yörüngeler incelenir.
- Ödev sunumlarından çıkan akademik noktalar
  - Başlangıç ve bitiş ağırlıklarını birleştiren çizgide başarı genelde düzgün değişir; ileri uzatılınca başarı düşer.
  - Bir sunumda Waveform veri kümesinde başlangıç ve bitiş hataları neredeyse aynı çıktı; hoca bunun ağın aslında eğitilmediği anlamına geldiğini, sorunun veri kümesinin zorluğundan kaynaklanabileceğini söyledi.
  - CIFAR-10'da son noktaların birleştirildiği bir sunumda bütün modellerin test başarısı %25-35 civarında kaldı. Hoca, modeller henüz öğrenmediği için aralarında ilişki kurmanın güç olduğunu ve bunun büyük olasılıkla epoch sayısıyla değil mimariyle ilgili olduğunu söyledi.
  - Başka bir sunumda CIFAR-10'da iki farklı son nokta arasındaki düz çizgi üzerinde de hata çok düşük çıktı; hoca bunu beklenenden farklı ve yorumlaması güç buldu.
  - t-SNE ile çizilen yörüngelerde başlangıçların sıfır çevresinde rastgele küçük değerler olduğu için birbirine yakın olması beklenir; bu durumda yörüngeler birbirinden uzaklaşıyor gibi yorumlanmalıdır.
  - Farklı başlangıçlı modellerin son noktaları arasında lokal minimum ve maksimumların daha sık, aynı modelin noktaları arasında daha seyrek görüldüğü gözlendi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
