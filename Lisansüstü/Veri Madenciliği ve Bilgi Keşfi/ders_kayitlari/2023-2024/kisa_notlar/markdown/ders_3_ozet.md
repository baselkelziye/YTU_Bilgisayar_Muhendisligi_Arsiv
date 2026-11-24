# Ders 3 Çalışma Özeti

## Genel Konular

- Veri indirgeme (data reduction) ve büyük veri setlerinin üç boyutu
  - Ön işlenmiş veri seti genelde düz dosya (flat file) biçimindedir: satırlar örnekler (samples, cases), sütunlar öz nitelikler (features), hücreler de bir örneğin bir öz nitelikteki değeridir (ekrandan, 00:15:00).
  - Buna göre üç temel indirgeme işlemi vardır: sütun silmek (feature reduction), satır silmek (sample/case reduction) ve bir sütundaki farklı değer sayısını azaltmak (value reduction, öz niteliği yumuşatmak).
  - Örnek indirgeme pratikte az kullanılır; özellikle derin öğrenmede ne kadar çok örnek olursa model o kadar iyi eğitilir.
  - Doğal dil işleme gibi alanlarda öz nitelik sayısı yüzlerle binler arasında olabilir; bu, işleme yükünü artırır ve amaca uygun öz niteliklerin seçilmesini gerektirir.
- Veri indirgemenin kazançları
  - Hesaplama süresi (computing time): daha az girdiyle model daha hızlı eğitilir ve test edilir.
  - Tahmin/tanımlama başarısı (predictive/descriptive accuracy): bazen artar; örneğin boy ve kilo yerine bunlardan türetilen vücut kitle indeksi daha iyi bir göstergedir.
  - Modelin gösterimi (representation): daha az öz nitelikle kurulan model daha basit ve anlaşılır olur.
  - Üçünü birden kazanmak idealdir ama çoğu zaman birinde kazanılırken diğerinde kaybedilir; denge uygulamaya göre kurulur (ekrandan, 00:20:00).
- Konuların kavram ağacı (tahtada çizilen, ekrandan, 00:30:00)
  - Data Reduction
    - Feature Reduction
      - Feature Selection: (1) supervised, ortalama ve varyansa dayalı seçim; (2) unsupervised, öz nitelik sıralama için entropi ölçüsü
      - Feature Composition: unsupervised, PCA (temel bileşen analizi)
    - Sample Reduction
    - Value Reduction: feature discretization, ChiMerge tekniği
- Öz nitelik seçimi (feature selection) ile öz nitelik birleştirme (feature composition) farkı
  - Seçimde yeni öz nitelik üretilmez; var olanların değerli olanları seçilir, gerisi atılır (ör. 10 öz nitelikten 4'ü seçilir ya da sıralanıp bir eşikten kesilir).
  - Birleştirmede öz nitelikler bir dönüşümle yeni öz niteliklere çevrilir (ör. vücut kitle indeksi, PCA); başlangıçtaki öz nitelikler veri setinde artık yer almaz.
- Ortalama ve varyansa dayalı öz nitelik seçimi (supervised)
  - Her öz nitelik için A ve B sınıflarına ait örneklerin ortalaması ve varyansı hesaplanır; veriler yaklaşık normal dağılımlı varsayılır.
  - Test değeri: $\dfrac{|\overline{X}_A-\overline{X}_B|}{SE(X_A-X_B)}$, burada $SE(X_A-X_B)=\sqrt{\dfrac{var(X_A)}{n_1}+\dfrac{var(X_B)}{n_2}}$ (ekrandan, 00:55:00).
  - Test değeri eşiğin üstündeyse öz nitelik sınıfları ayırmada etkilidir ve tutulur; altındaysa indirgeme adayıdır.
- Entropi ölçüsüyle öz nitelik sıralama (unsupervised)
  - Sınıf etiketi gerekmez; ilgisiz ya da gereksiz bir öz niteliği çıkarmak veri setinin temel yapısını değiştirmez varsayımına dayanır (ekrandan, 01:25:00).
  - Sayısal öz niteliklerde normalize Öklid uzaklığı, kategorik öz niteliklerde eşleşen öz nitelik oranıyla benzerlik hesaplanır; benzerlik matrisinden entropi hesaplanır.
  - Her adımda entropiyi en az değiştiren öz nitelik sıralı listenin en altına konur ve kümeden çıkarılır.
- Değer indirgeme ve ChiMerge
  - Değer indirgemede bir öz niteliğin çok sayıdaki değeri aralıklara bölünür ve her aralık bir temsilci değerle gösterilir (daha önce görülen yumuşatma/binning teknikleri de burada kullanılır).
  - ChiMerge, komşu aralıkları ki-kare testiyle birleştirerek ayrıklaştırma yapan, sınıf etiketini kullanan bir yöntemdir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Test formülünü ezberlemek yerine yorumlamak
  - Kesrin üstünde (pay) ortalamalar arasındaki fark büyük, altında (payda) standart hata küçük olmalı; ikisi birlikte test değerini büyütür.
  - Standart sapması küçük dağılımlar ortalamaya toplanır, birbirinden daha kolay ayrılır. Hoca bunu sınıfa sordu, doğru cevap "küçük olması" idi.
- Formül okumayı bilmek önemlidir
  - Hoca, formüllerle barışmanın faydalı olduğunu, formüllerin çok şey anlattığını söyledi ve normalize Öklid ile entropi formüllerini indis indis okudu.
- İndirgeme kararı tek başına verilmez
  - Bütün veriyle elde edilen başarı ile indirgenmiş veriyle elde edilen başarı karşılaştırılır; fark çok büyükse indirgeme yapılmayabilir.
  - Kaç öz niteliğe inileceği (ör. 3 mü 5 mi) de denenerek, tahmin başarısındaki düşüşe bakılarak seçilir.
- Eşik seçimi
  - Test değerleri büyükten küçüğe sıralanır ve değerlerin birden düştüğü boşluktan (gap) kesilir; iki boşluk varsa ikisi de denenir.
  - ChiMerge eşiği (2,706) ki-kare tablosundan alınır ama kesin kural değildir; daha fazla birleştirme isteniyorsa büyütülebilir.
- Entropi yönteminde listenin en altına giden öz nitelik, entropisi en düşük olan değil, çıkarıldığında entropi farkı en küçük olandır.

## Kısa Tekrar Notları

- Üç indirgeme ekseni: öz nitelik (sütun), örnek (satır), değer.
- Kazançlar: süre, başarı, basit gösterim; hepsi birden nadiren sağlanır.
- Feature selection var olanı seçer; feature composition dönüştürüp yenisini üretir (PCA).
- Ortalama-varyans testi: $|\overline{X}_A-\overline{X}_B|/SE$; büyükse öz nitelik ayırt edicidir, tutulur.
- Ders örneğinde X için test değeri eşiğin (0,5) altında, Y için çok üstünde: X atılabilir, Y tutulur.
- Normalize Öklid uzaklığı: her öz nitelik farkı $(max_k-min_k)$ ile bölünür, kareler toplanır, karekök alınır.
- Uzaklıktan benzerliğe: $S_{ij}=e^{-\alpha D_{ij}}$; uzaklık azaldıkça benzerlik artar.
- Kategorik benzerlik: eşleşen öz nitelik sayısı / toplam öz nitelik sayısı; benzerlik matrisi simetrik, köşegeni 1.
- Entropi: $E=-\sum_{i=1}^{N-1}\sum_{j=i+1}^{N}\big(S_{ij}\log S_{ij}+(1-S_{ij})\log(1-S_{ij})\big)$.
- Entropi sıralaması geriye doğru (backward) çalışır, öz nitelik sayısı kadar iterasyon gerekir.
- ChiMerge: sırala, her değeri ayrı aralık yap, ki-karesi eşikten küçük komşu aralıkları birleştir.
- Ki-kare: $\chi^2=\sum_{i=1}^{2}\sum_{j=1}^{k}\frac{(A_{ij}-E_{ij})^2}{E_{ij}}$, $E_{ij}=R_iC_j/N$; serbestlik derecesi 1 için eşik 2,706.
- PCA bir sonraki derse bırakıldı.

## Detaylı Açıklamalar

- **Üç boyutlu indirgeme.** Veri tabanındaki veri bir tabloya (Excel benzeri düz dosya) yerleştirilir. Sütun azaltmak öz nitelik indirgemedir (ekrandaki altı sütunu üçe düşürmek gibi). Satır azaltmak, amaca hizmet etmeyen örnekleri silmektir; hoca kendi uygulamalarında buna hiç ihtiyaç duymadığını, çok örneğin genelde avantaj olduğunu söyledi. Değer indirgeme ise tablodaki değerlerin çeşitliliğini azaltmaktır.
- **Vücut kitle indeksi örneği.** Boy ve kilo yerine kilonun boyun karesine oranı olan tek bir öz nitelik kullanmak hem veriyi azaltır hem de daha kaliteli bir girdi sağlar. Ancak her indirgeme kaliteyi artırmaz, bazen başarıda küçük düşmeler olur. Bu durumda hesaplama süresindeki kazanç önemliyse küçük bir başarı kaybı kabul edilebilir.
- **Ortalama ve varyansa dayalı seçim örneği (ekrandan, 00:35:00 ve 00:55:00).** Veri seti iki öz nitelik (X, Y) ve sınıf etiketinden (C) oluşur:

  | X | Y | C |
  |---|---|---|
  | 0.3 | 0.7 | A |
  | 0.2 | 0.9 | B |
  | 0.6 | 0.6 | A |
  | 0.5 | 0.5 | A |
  | 0.7 | 0.7 | B |
  | 0.4 | 0.9 | B |

  Eşik 0,5'tir. Ortalamalar: $\overline{X}_A=0.4667$, $\overline{X}_B=0.4333$, $\overline{Y}_A=0.6$, $\overline{Y}_B=0.8333$. Slayttaki hesap:
  - $SE(X_A-X_B)=\sqrt{0.0233/3+0.6333/3}=0.4678$, test $=|0.4667-0.4333|/0.4678=0.0735<0.5$
  - $SE(Y_A-Y_B)=\sqrt{0.01/3+0.0133/3}=0.0875$, test $=|0.6-0.8333|/0.0875=2.6667>0.5$
  - Sonuç: X indirgeme adayıdır, Y ise iki sınıfı ayırt etme potansiyeli olduğu için tutulur.
  - **Ders sonrası not:** Slaytta $var(X_B)=0.6333$ yazıyor; 0.2, 0.7, 0.4 değerlerinin örneklem varyansı 0,0633'tür (python ile doğrulandı). Doğru değerle $SE=0.170$ ve test $\approx 0.196$ çıkar; bu da 0,5'in altında olduğu için sonuç değişmez. Y için hassas değerler $SE=0.0882$, test $\approx 2.646$'dır.
  - Hoca tahtada X ve Y için iki sınıfın dağılımlarını çizdi (ekrandan, 00:45:00): X'te iki dağılımın ortalamaları (0,43 ve 0,46) iç içe, Y'de (0,6 ve 0,83) birbirinden ayrık.
- **Çok sınıflı durum.** Bir öğrencinin sorusu üzerine hoca, üç sınıf (A, B, C) varsa testin ikili yapılması gerektiğini (A-B, A-C, B-C) söyledi; dağılımlar eksen üzerinde sıralı görünüyorsa buradan da sonuca varılabilir.
- **Normalize Öklid uzaklığı (ekrandan, 01:40:00).** Veri seti $m$ örnek ve $n$ öz nitelikten oluşan bir matris olarak düşünülür. İki örnek arasındaki uzaklık:

  $$D_{ij}=\left[\sum_{k=1}^{n}\left(\frac{x_{ik}-x_{jk}}{max_k-min_k}\right)^2\right]^{1/2}$$

  Burada $max_k$ ve $min_k$, $k$. öz niteliğin sütundaki en büyük ve en küçük değerleridir.
- **Kategorik benzerlik örneği (ekrandan, 01:45:00).** Beş örnek, üç kategorik öz nitelik: R1 = (A, X, 1), R2 = (B, Y, 2), R3 = (C, Y, 2), R4 = (B, X, 1), R5 = (C, Z, 3). $S_{1,4}$: F1'de eşleşme yok, F2 ve F3'te var, $S_{1,4}=2/3$. $S_{3,5}$: yalnız F1 eşleşir, $1/3$. Benzerlik matrisinin üst üçgeni: R1 satırı 0/3, 0/3, 2/3, 0/3; R2 satırı 2/3, 1/3, 0/3; R3 satırı 0/3, 1/3; R4 satırı 0/3 (python ile doğrulandı). Hoca bu ölçüyü Hamming uzaklığı adıyla andı.
- **Entropi sıralama algoritması (ekrandan, 01:55:00).** (1) Tüm öz nitelik kümesi F ile başla. (2) Her $f\in F$ için $f$'yi çıkar, kalan kümenin entropisini hesapla ve $E_F-E_{F-f}$ farklarını bul. (3) Farkı en küçük olan $f_k$'yı seç. (4) $F=F-\{f_k\}$ yap; $f_k$ listenin en altına gider. (5) F'de tek öz nitelik kalana kadar 2-4. adımları tekrarla. Örnekte F1 çıkarıldığında fark en küçükse F1 listenin en altına yazılır, işlemler F2 ve F3 ile sürer.
- **ChiMerge örneği (ekrandan, 02:25:00).** Sıralı F değerleri ve sınıfları: 1(1), 3(2), 7(1), 8(1), 9(1), 11(2), 23(2), 37(1), 39(2), 45(1), 46(1), 59(1).
  - [7,5-8,5] ve [8,5-10]: tablo [[1,0],[1,0]], $\chi^2=0.2<2.706$, birleştirilir: [7,5-10].
  - [0-7,5] ve [7,5-10]: tablo [[2,1],[2,0]], $\chi^2=0.834<2.706$, birleştirilir: [0-10].
  - [0-10] ve [10-42]: tablo [[4,1],[1,3]], $\chi^2=2.72>2.706$, birleştirme önerilmez.
  - Üç değer python ile doğrulandı (beklenen frekansı 0 olan hücrede küçük bir sabit (0,1) kullanıldığı varsayımıyla ilk değer 0,2 çıkar).
  - Hoca slayttaki ki-kare formülünde kare işaretinin unutulduğunu, işlemlerde farkın karesinin alındığını belirtti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
