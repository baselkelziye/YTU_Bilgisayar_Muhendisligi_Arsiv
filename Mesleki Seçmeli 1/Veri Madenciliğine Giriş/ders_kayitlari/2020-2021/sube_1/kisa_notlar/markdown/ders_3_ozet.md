# Ders 3 Çalışma Özeti

## Genel Konular

- Önceki dersin kısa tekrarı
  - Veri ön işleme konusunda veri tipleri (sayısal ve kategorik), ham verinin dönüşümü, normalizasyon ve veri düzleştirme (smoothing) işlemleri hatırlatıldı.
  - Ham verinin özellikleri slaytı: veri madenciliği için hazırlanan ham veri genelde büyüktür ve dağınık olabilir; eksik değer, bozulma, hatalı kayıt ve yetersiz örnekleme beklenmelidir. Hiç sorun göstermeyen ham veri şüphe uyandırmalıdır, çünkü büyük olasılıkla önceden temizlenmiştir (ekrandan, 00:15:00).
- Zamana bağlı veri (time-dependent data, zaman serisi)
  - Tek bir öz niteliğin sabit zaman aralıklarıyla ölçülmesiyle oluşur: saatlik/günlük hava sıcaklığı, günlük borsa fiyatları gibi.
  - Seri $X = \{t(1), t(2), \dots, t(n)\}$ biçimindedir; $t(n)$ en güncel değerdir. Amaç, önceki değerlerden $t(n+1)$ değerini tahmin etmektir.
  - Seri, kayan bir pencere (window) ile standart tablo biçimine dönüştürülür. Pencere boyutu 5 ise ilk beş değer girdi, sonraki değer çıktı (next value) olur; pencere birer kaydırılarak yeni örnekler üretilir (ekrandan, 00:20:00).
  - 11 ölçümlü seriden ($t(0)\dots t(10)$) pencere boyutu 5 ile 6 eğitim örneği çıkar. Eğitimden sonra $t(6)\dots t(10)$ girdi verilerek $t(11)$ tahmin edilir.
  - Daha uzak geleceği tahmin etmek için çıktı $t(n+j)$ seçilebilir (örneğin $t(n+3)$: ilk beş değer girdi, çıktı yedinci değer).
  - Çıktı sayısal olduğu için bu bir tahmin (prediction) problemidir ve regresyon yöntemleri kullanılır.
  - Gelecek uzaklaştıkça tahmin zorlaşır ve güvenilirliği azalır. Hedef, sayısal tahmin yerine sınıflandırmaya çevrilebilir: $t(i+1) \ge$ eşik ise T, değilse F (ekrandan, 00:25:00).
- Aykırı değer analizi (outlier analysis)
  - Yanlış ölçüm, ölçüm hatası, yazım hatası ya da verinin doğal değişkenliği nedeniyle verinin genelinden belirgin biçimde farklı ya da tutarsız örnekler oluşabilir; bunlara aykırı değer denir.
  - Aykırı değerler veri setinden otomatik yöntemlerle bulunup çıkarılmalıdır. Öte yandan bankalardaki sahte kredi kartı işlemlerinin tespiti gibi uygulamalarda aranan şey aykırı değerin kendisidir.
  - Çok boyutlu veride aykırı değer bulmak zordur. Tek değişkenli (univariate) yöntemler her öz niteliği ayrı ayrı inceler.
  - Bir, iki ya da üç boyutlu veride görselleştirme ile aykırı değerler gözle seçilebilir. Slayttaki 7 örnekli iki boyutlu veride $s_3$ ve $s_5$ verinin genel dağılımından uzaktadır (ekrandan, 00:30:00).
  - Derste üç çözüm işlendi: kutu grafiği (box plot), uzaklık tabanlı yöntem ve ortalama $\pm$ 2 standart sapma yöntemi.
- Kutu grafiği (box plot) analizi
  - $Q_1$ 25. yüzdelik, $Q_3$ 75. yüzdelik, $IQR = Q_3 - Q_1$ (ekrandan, 00:40:00).
  - Beş sayı özeti: min, $Q_1$, medyan ($M$), $Q_3$, max.
  - Kural: $Q_3$'ün en az $1.5 \times IQR$ üstünde ya da $Q_1$'in en az $1.5 \times IQR$ altında kalan değerler aykırı kabul edilir.
  - Yaş örneği: 27 örnek, min 13, max 70, medyan 25, $Q_1 = 20$, $Q_3 = 35$, $IQR = 15$, eşik $22.5$; normal aralık $-2.5$ ile $57.5$ arası; 70 aykırı değerdir (ekrandan, 00:55:00).
- Uzaklık tabanlı (distance-based, çok değişkenli) çözüm
  - Bir örnek, örneklerin en az $p$ tanesi kendisine $d$'den daha uzaktaysa aykırı değerdir (ekrandan, 01:15:00).
  - Örnek: $X = \{(2,4),(3,2),(1,1),(4,3),(1,6),(5,3),(4,2)\}$, $d \ge 3$, $p \ge 4$. Öklid uzaklık matrisi (7x7, simetrik, köşegeni sıfır) kurulur; $s_3$ ve $s_5$ aykırı değer çıkar (ekrandan, 01:40:00).
- Ortalama ve standart sapma ile çözüm
  - Her öz nitelik için $m - 2s$ ile $m + 2s$ arası normal bölge kabul edilir, dışı aykırıdır.
  - Aynı örnekte $x_1$ için yaklaşık $[-0.29,\ 5.99]$, $x_2$ için yaklaşık $[-0.26,\ 6.26]$; aykırı değer yoktur (ekrandan, 01:55:00).
- Veri indirgeme (data reduction)
  - Üç boyutta yapılır: öz nitelik (feature), örnek (sample) ve değer (value) indirgeme (ekrandan, 02:30:00).
  - Öz nitelik indirgeme: öz nitelik seçimi (feature selection; denetimli ve denetimsiz) ve öz nitelik birleştirme (feature composition; örneğin PCA).
  - Değer indirgemede ayrıklaştırma için ChiMerge tekniği, denetimsiz sıralamada entropi tabanlı teknik ve PCA ileride işlenecek konular olarak anıldı.
- Ortalama ve varyans ile öz nitelik seçimi (denetimli)
  - Test: $\dfrac{|\bar{x}_A - \bar{x}_B|}{\sqrt{\mathrm{var}_A/n_1 + \mathrm{var}_B/n_2}}$; sonuç büyükse öz nitelik ayırt edicidir.
  - Örnekte $X$ için test yaklaşık 0.07 (slayttaki değer) ve eşik 0.5'in altında, $Y$ için yaklaşık 2.67 ve eşiğin üstünde; $X$ indirgeme adayıdır, $Y$ tutulur (ekrandan, 02:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Aykırı değer analizi veri ön işlemenin en önemli parçasıdır.
  - Yanlış ölçüm ya da yazım hataları sonuçları bozar; bu örneklerin otomatik yöntemlerle bulunup çıkarılması gerekir.
- Kutu grafiğinin uçları
  - Sınırın dışında değer yoksa kutu grafiğinin bıyığı en küçük/en büyük gerçek değerde "kapatılır". Sınırın dışında değer varsa uç kapatılmaz, aykırı değer ayrı işaretlenir.
  - Kutu grafiği bitirme tezi, proje ve makalelerde veriyi anlatmak için önerilen bir grafiktir; verinin iyi analiz edildiğini gösterir.
- Katsayılar sabit değildir
  - Derste kural olarak $1.5 \times IQR$ ve $\pm 2s$ kullanılır. Çok fazla aykırı değer çıkıyorsa katsayı artırılır (2 IQR, 3s, 3.5s), çok az çıkıyorsa azaltılabilir.
  - Normal bir veri setinde aykırı değer oranı genelde yaklaşık %5'tir; verinin %20-25'ini aykırı diye atmak fazla acımasız olur.
- Tek değişkenli yöntemin zayıflığı
  - Tek bir öz nitelikte aykırı çıkan örnek, diğer öz nitelikleri normal olsa bile bütünüyle veri setinden silinir.
  - Hocaya göre daha anlamlı çözüm, veriye bütün olarak bakan uzaklık tabanlı yaklaşımlardır (örneğin tüm verinin merkezine en uzak örnekleri bulmak). Uzaklık tabanlı yöntemde $p$ ve $d$ eşiklerini seçmek ise zordur.
- Öz nitelik seçiminde eşik yerine sıralama
  - Eşik değerini sonuçları görmeden seçmek zordur. Test skorlarını büyükten küçüğe sıralayıp skorun ani düştüğü yerden kesmek önerildi.
  - Bu test sınıf etiketi gerektirdiği için denetimli (supervised) bir tekniktir.
- Öz nitelik birleştirmenin dezavantajı
  - Yeni öz nitelik uzayındaki eksenler eski öz niteliklerin karmasıdır; yaş ya da gelir gibi anlamlı adlar kaybolur.
- Örnekleri kâğıt üzerinde siz de çözün; not almak dikkati toplar.

## Kısa Tekrar Notları

- Zaman serisi: kayan pencere ile girdi (pencere) ve çıktı (sonraki değer) tablosu kurulur; çıktı sayısal olduğundan regresyon problemidir.
- Pencere 5, 11 ölçüm: 6 eğitim örneği.
- $t(n+j)$ ile uzak gelecek tahmini; ne kadar uzaksa o kadar güvenilmez.
- Aykırı değer: verinin genelinden belirgin farklı örnek; yöntemler: kutu grafiği, uzaklık tabanlı, $m \pm 2s$.
- $IQR = Q_3 - Q_1$; sınırlar $Q_1 - 1.5\,IQR$ ve $Q_3 + 1.5\,IQR$.
- Yaş örneği: $Q_1 = 20$, $M = 25$, $Q_3 = 35$, $IQR = 15$, sınırlar $-2.5$ ve $57.5$, aykırı: 70.
- Uzaklık tabanlı: her örnek için $d$'den uzak örnek sayısı ($p$) bulunur; $p \ge 4$ ise aykırı. Örnekte $s_3$ ve $s_5$.
- $m \pm 2s$ tek değişkenlidir; bir öz nitelikte aykırı çıkan örnek tamamen silinir.
- Katsayılar uygulamaya göre değişir; aykırı oranı tipik olarak ~%5.
- Veri indirgeme: öz nitelik, örnek, değer. Avantajlar: hesaplama süresi, tahmin/betimleme doğruluğu, sade gösterim.
- Öz nitelik seçimi: alt küme seçilir, adlar korunur. Öz nitelik birleştirme: dönüşüm yapılır, tüm öz nitelikler değişir.
- Ortalama-varyans testi: ortalamalar arası fark büyük, varyanslar küçük olmalı; sınıf etiketli veri gerekir.

## Detaylı Açıklamalar

- **Zamana bağlı verinin hazırlanması.** Zaman serisinde tek bir öz nitelik zaman içinde ölçülür. Veri madenciliği algoritmaları satır-sütun biçimli tablo beklediği için seri bir pencereyle yeniden düzenlenir. Slayttaki tabloda (pencere = 5) sütunlar M1-M5 girdi ve "Next Value" çıktıdır: 1. satır $t(0)\dots t(4) \rightarrow t(5)$, 2. satır $t(1)\dots t(5) \rightarrow t(6)$, ..., 6. satır $t(5)\dots t(9) \rightarrow t(10)$ (ekrandan, 00:20:00). Çıktıları bilinen bu 6 örnek eğitim verisidir; model kurulduktan sonra $t(6)\dots t(10)$ girdi olarak verilir ve $t(11)$ tahmin edilir. Hava sıcaklığında üç gün sonrasını tahmin etmek gibi durumlarda çıktı $t(n+3)$ seçilir; bu durumda ilk beş değerin karşısına $t(7)$ yazılır. Etiketli bir veri elde edilir ama çıktı sayısal olduğundan bu sınıflandırma değil tahmin problemidir.
  - **Ders sonrası not:** Slayttaki tablonun 4. satırında çıktı $t(7)$ yazılmıştır; pencerenin kayma düzenine göre doğrusu $t(8)$ olmalıdır (ekrandan, 00:20:00).
- **Aykırı değerin sezgisi.** Hoca 7 örnekli iki boyutlu grafiği gösterip aykırı değerlerin matematiksel olarak nasıl bulunabileceğini sordu. Öğrencilerden gelen öneriler: tüm örneklerin ortalaması alınarak verinin merkezi bulunur, her örneğin bu merkeze uzaklığı hesaplanır ve en uzakta kalanlar aykırı işaretlenir. Sınıf etiketli veride aynı fikir sınıf bazında uygulanır: her sınıfın kendi ortalaması bulunur ve örneklerin sınıf merkezine uzaklığına bakılır. Bu çözüm bütün öz nitelikleri birlikte kullandığı için çok boyutludur.
- **Kutu grafiği çizimi.** Veri sıralanır; medyan veriyi iki yarıya böler; alt yarının medyanı $Q_1$, üst yarının medyanı $Q_3$'tür. 27 örnekli yaş verisinde medyan 14. sıradaki değerdir (25). Medyanın iki yanında 13'er örnek kalır; bunların ortası 7. sıradır: $Q_1 = 20$, $Q_3 = 35$. $IQR = 15$, eşik $1.5 \times 15 = 22.5$. Alt sınır $20 - 22.5 = -2.5$; verideki en küçük değer 13 bu sınırın içinde olduğu için alt bıyık 13'te kapatılır. Üst sınır $35 + 22.5 = 57.5$; 70 bu sınırın dışında olduğu için aykırıdır, üst bıyık kapatılmaz ve 70 ayrı işaretlenir (ekrandan, 00:55:00). 60 ya da 65 gibi değerler olsaydı onlar da aykırı olurdu.
- **Uzaklık tabanlı çözüm.** $d \ge 3$ olan örnekler "komşu olmayan" (non-neighbor) sayılır. Öklid uzaklık matrisi (değerler karekök içinde):

  ```text
         s1    s2    s3    s4    s5    s6    s7
  s1     0    √5   √10    √5    √5   √10    √8
  s2           0    √5    √2   √20    √5     1
  s3                 0   √13     5   √20   √10
  s4                       0   √18     1     1
  s5                             0     5     5
  s6                                   0    √2
  s7                                         0
  ```

  Komşu olmayan sayıları: $s_1$: 2, $s_2$: 1, $s_3$: 5, $s_4$: 2, $s_5$: 5, $s_6$: 3, $s_7$: 2. $p \ge 4$ koşulunu yalnız $s_3$ ve $s_5$ sağlar, ikisi aykırıdır (ekrandan, 01:45:00). Bu sonuç, grafikte gözle seçilen örneklerle aynıdır.
- **Ortalama $\pm$ 2 standart sapma.** Normal dağılımda ortalamanın iki yanında $2s$ uzaklıktaki sınırların dışı aykırı bölgedir. Aynı veri için $m(x_1) \approx 2.85$, $s(x_1) \approx 1.57$, $m(x_2) = 3$, $s(x_2) \approx 1.63$. $x_1$ için sınırlar $-0.29$ ve $5.99$, $x_2$ için $-0.26$ ve $6.26$'dır; hiçbir değer bu sınırların dışında olmadığı için bu yöntemle aykırı değer bulunmaz (ekrandan, 01:55:00).
  - **Ders sonrası not:** Tahtada $x_2$ üst sınırı 6.29 yazıldı; $3 + 2 \times 1.63 = 6.26$ olmalıdır. Sonuç değişmez. Hesaplanan $s$ değerleri örneklem standart sapmasıdır ($n-1$ ile; python ile doğrulandı).
  - Aynı veride uzaklık tabanlı yöntem $s_3$ ve $s_5$'i aykırı bulurken bu tek değişkenli yöntem hiçbir aykırı değer bulmaz; yöntemin seçimi sonucu değiştirir.
- **Veri indirgeme.** Bazı uygulamalarda yüzlerce öz nitelik olur; bu yüksek boyutluluk bazı algoritmaları uygulanamaz kılar ve sonuca ulaşma süresini uzatır. Boy ve kilodan beden kitle indeksi üretilirse iki öz nitelik yerine daha değerli tek bir öz nitelik kullanılabilir. Doğru yapılan indirgeme sonuç kalitesini düşürmez, bazen gereksiz öz nitelikler çıktığı için sonucu iyileştirir. Avantajlar: daha kısa hesaplama süresi, daha yüksek tahmin ve betimleme doğruluğu, daha sade gösterim. Slayta göre bunların hepsine aynı anda ulaşmak idealdir, ama genelde birinde kazanılıp diğerinde kaybedilir ve uygulamaya göre denge kurulur (ekrandan, 02:35:00).
- **Öz nitelik seçimi ile birleştirme farkı.** Seçimde öz nitelikler ayırt edicilik gücüne göre sıralanır, ilk birkaçı alınır, kalanlar silinir; kalan öz niteliklerin adı ve anlamı korunur. Birleştirmede veri yeni bir öz nitelik uzayına dönüştürülür; her yeni eksen eski öz niteliklerin ağırlıklı bir karmasıdır (örneğin %60 yaş, %40 gelir). Bu durumda tüm öz nitelikler değişir ve eski adlarıyla anılamaz.
- **Ortalama-varyans testi ile öz nitelik seçimi.** Veri: $X = (0.3, 0.2, 0.6, 0.5, 0.7, 0.4)$, $Y = (0.7, 0.9, 0.6, 0.5, 0.7, 0.9)$, sınıflar $(A, B, A, A, B, B)$; eşik 0.5 (ekrandan, 02:40:00). A sınıfı: $X_A = \{0.3, 0.6, 0.5\}$, $Y_A = \{0.7, 0.6, 0.5\}$; B sınıfı: $X_B = \{0.2, 0.7, 0.4\}$, $Y_B = \{0.9, 0.7, 0.9\}$. $X$'te iki sınıfın dağılımları iç içe geçer, $Y$'de ayrıktır. Slayttaki sonuçlar: $|0.4667 - 0.4333| / 0.4678 = 0.0735 < 0.5$ ve $|0.6 - 0.8333| / 0.0875 = 2.6667 > 0.5$ (ekrandan, 02:55:00). $X$ indirgeme adayıdır, $Y$ ayırt edici olduğu için tutulur.
  - **Ders sonrası not:** Slaytta $\mathrm{var}(X_B) = 0.6333$ yazılmıştır; $\{0.2, 0.7, 0.4\}$ için örneklem varyansı $0.0633$'tür. Doğru değerle $SE \approx 0.170$ ve $X$ testi $\approx 0.196$ olur; yine 0.5'in altındadır, karar değişmez. $Y$ için kesin hesap $SE \approx 0.0882$, test $\approx 2.65$'tir (python ile doğrulandı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
