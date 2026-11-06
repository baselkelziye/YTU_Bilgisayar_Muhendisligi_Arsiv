# Ders 12 Çalışma Özeti

## Genel Konular

- Eğitmensiz öğrenmeye (unsupervised learning) kısa tekrar: etiketsiz örnekleri benzerliklerine göre gruplamak.
- Rekabetçi öğrenme (competitive learning) ve "kazanan her şeyi alır" (winner takes all) mantığı.
- Öz düzenleyici haritalar (Self-Organizing Map, SOM): yapı, ağırlık güncelleme, sert ve yumuşak öğrenme (hard / soft learning), Gauss komşuluk fonksiyonu.
- SOM için sayısal örnek: 4 özellikli 4 örnek, 2 küme.
- Kararlılık-esneklik ikilemi (stability-plasticity dilemma).
- Gauss karışım modeli (Gaussian Mixture Model, GMM) ve beklenti-en büyükleme (Expectation-Maximization, EM) için kısa bilgi.
- Pekiştirmeli öğrenme (reinforcement learning): ödül-ceza mantığı, uygulama örnekleri.
- Markov karar süreci (Markov Decision Process, MDP).
- Q-öğrenme (Q-Learning): ödül matrisi (R), Q matrisi, oda örneği.

## Hocanın Özellikle Vurguladığı Kısımlar

- Son yıllarda eğitmensiz öğrenmenin önemi arttı. Büyük veride etiketleme çok zaman alıyor, bazen herkes aynı şekilde etiketleyemiyor.
- Yaygın kullanım: önce etiketsiz veriyi benzerliğe göre grupla, sonra grubun özelliklerine bakıp etiketine karar ver.
- SOM'da öğrenme, perceptron'daki gibi ağırlıkların güncellenmesiyle olur. Fark şu: ağırlıklar girişe benzeyecek şekilde değiştirilir.
- Giriş örnekleri SOM'dan önce mutlaka normalize edilmeli (min-max ya da 0-1 aralığı). Yoksa büyük değerli özellik (ör. boy 183) küçük değerli özelliği (ör. yaş 22) bastırır.
- Başlangıçta ağırlıklar rastgele ve girişlerden uzak. Bu yüzden komşuluk geniş, öğrenme oranı büyük başlatılır. Zamanla ikisi de küçültülür.
- Öğrenme bittikten sonra yeni örnek gelince ağırlıklar güncellenir mi? Amaca bağlı. Yalnız benzerlik bulmak istiyorsanız güncellemezsiniz. Öğrenmeye devam edecekseniz kararlılık-esneklik ikilemine dikkat edin.
- GMM eskiden özellikle görüntüde çok kullanılıyordu. Artık genelde k-means ya da derin öğrenmede otokodlayıcı (autoencoder) tercih ediliyor. Hoca GMM'yi dönem sonunda vakit kalırsa anlatacağını söyledi.
- Pekiştirmeli öğrenme gerçek insan öğrenmesine en çok benzeyen yaklaşım. Bu yüzden önemi artıyor.
- Q-öğrenmenin Q'su "quality" (kalite) sözcüğünden gelir.
- Ödül ve cezanın ne olacağına ve büyüklüğüne tasarımcı karar verir. Bu deneyimle belirlenir.
- Q-öğrenme derin öğrenmede de kullanılan, kolay ve en çok kullanılan pekiştirmeli öğrenme yöntemidir.

## Kısa Tekrar Notları

- **Rekabetçi öğrenme iki türlü:**
  - Sert öğrenme (hard learning): yalnız en çok benzeyen (kazanan) nöron güncellenir.
  - Yumuşak öğrenme (soft learning): kazanan nöronla birlikte komşuları da güncellenir. İnsan beynindeki bağlantılı nöronlar gibi.
- **SOM yapısı:** her giriş özelliğinden her çıkış nöronuna bağlantı var. Çıkış nöronu sayısı = istenen küme sayısı. Çıkış kafesi (output lattice) tek boyutlu ya da iki boyutlu (ör. 3×3 = 9 küme) olabilir.
- **Mesafe:** giriş $x$ ile $j$. çıkış nöronunun ağırlık vektörü $w_j$ arasında Öklid mesafesi: $d_j = \lVert x - w_j \rVert$.
- **Kazanan:** $j^* = \arg\min_j d_j$.
- **Güncelleme (sert):** $w_{j^*}(t+1) = w_{j^*}(t) + \eta \, (x - w_{j^*}(t))$.
- **Güncelleme (yumuşak):** $w_j(t+1) = w_j(t) + \eta(t)\, h_{j^*j}(t)\, (x - w_j(t))$.
- **Gauss komşuluğu:** $h_{j^*j} = \exp\left(-\dfrac{d_{j^*j}^2}{2\sigma^2}\right)$. Sert öğrenmede $h$ yalnız kazananda 1, diğerlerinde 0.
- **Komşuluğu daraltma:** $\sigma(t) = \sigma_0 \exp(-t / T_1)$. Öğrenme oranı da aynı mantıkla azaltılabilir.
- **SOM adımları:** ilklendirme (initialization), örnekleme (sampling), rekabet (competition), güncelleme (updating), uyum (adaptation). Ağırlıklar artık değişmeyene (yakınsama, convergence) kadar 2. adımdan devam.
- **Pekiştirmeli öğrenme bileşenleri:** durum (state), eylem (action), ödül (reward). Eylem yeni bir duruma götürür, yeni duruma göre ödül ya da ceza gelir.
- **MDP dörtlüsü:** $S$ durumlar, $A$ eylemler, $T$ durum geçiş fonksiyonu, $R$ anlık ödül fonksiyonu. Markov varsayımı: $s_{t+1}$ yalnız $s_t$ (ve $a_t$) ile belirlenir.
- **Q-öğrenme güncellemesi (derste kullanılan basit hâl):** $Q(s,a) = R(s,a) + \gamma \max_{a'} Q(s',a')$.

## Detaylı Açıklamalar

### Eğitmensiz Öğrenmeye Kısa Tekrar

- Elimizde yalnız giriş bilgileri var, çıkışlar (etiketler) yok.
- Örnekler benzerliklerine göre gruplanır. Grubun adını bilmek gerekmez.
- İki kullanım:
  - Yalnız gruplamak yeterlidir. Ör. müşterileri harcama alışkanlıklarına göre gruplamak, sonra gruplarla işlem yapmak.
  - Önce grupla, sonra grubun özelliklerine bakıp etiket ver. Bugün en çok kullanılan durum bu.

### Rekabetçi Öğrenme ve SOM

- SOM, eğitmensiz öğrenmede en bilinen ve en çok tercih edilen yöntemlerden biri.
- Etiketsiz çıkış nöronları, giriş örneklerine benzetilerek gruplama yapılır.
- Kazanan nöron, girişe en çok benzeyen çıkış nöronudur. Ağırlıkları girişe daha da benzeyecek şekilde değiştirilir.
- Yumuşak öğrenmede kazananın komşuları da etkilenir. Tek bir nöron değil, ona bağlı nöronlar da aktif olur.
- Komşuluğu nasıl değerlendireceğinize ağı tasarlarken siz karar verirsiniz.

**Öğrenme adımları (hocanın sözlü anlatımı):**

1. Giriş örneklerini normalize et.
2. Etiketsiz örneklerden birini rastgele seç.
3. Bu örneğin her çıkış nöronunun ağırlık vektörüne Öklid mesafesini hesapla.
4. En küçük mesafeli nöron kazanır (winner takes all).
5. Kazananın (ve yumuşak öğrenmede komşularının) ağırlıklarını girişe yaklaştır.
6. Ağırlıklar artık değişmeyene kadar yeni örneklerle 2. adımdan devam et.

**Komşuluk fonksiyonu:**

- Sert öğrenmede komşuluk 1/0 şeklindedir: kazanan 1, diğerleri 0.
- Yumuşak öğrenmede komşuluk Gauss fonksiyonuyla yumuşakça azalır.
- Başlangıçta geniş $\sigma$ seçilir, çünkü rastgele ağırlıklar girişten uzaktır.
- Zamanla $\sigma$ küçültülür. Sonunda yalnız çok yakın komşular güncellenir.

**Öğrenme oranı:**

- Backpropagation'daki öğrenme oranından farkı yok.
- 1'e yakınsa ağırlık hızlı değişir.
- Başta büyük tutulur, çünkü ağırlık girişten uzaktır. Sonra küçültülür ki ağırlık hedefi geçip gitmesin.

### SOM Sayısal Örneği

- 4 özellikli 4 eğitim örneği, 2 küme (2 çıkış nöronu).
- Komşuluk 0 (sert öğrenme), öğrenme oranı ilk adımlarda $\eta = 0{,}6$, sonra azaltılıyor.

**Eğitim örnekleri:**

| Örnek | Özellikler |
| :---: | :---: |
| $i_1$ | (1, 1, 0, 0) |
| $i_2$ | (0, 0, 0, 1) |
| $i_3$ | (1, 0, 0, 0) |
| $i_4$ | (0, 0, 1, 1) |

**Başlangıç ağırlıkları (rastgele):**

- Unit 1: $w_1 = (0{,}2;\ 0{,}6;\ 0{,}5;\ 0{,}9)$
- Unit 2: $w_2 = (0{,}8;\ 0{,}4;\ 0{,}7;\ 0{,}3)$

**Örnek 1: $i_1 = (1, 1, 0, 0)$ gösteriliyor.**

1. Unit 1'e mesafe (karesi): $(0{,}2-1)^2 + (0{,}6-1)^2 + (0{,}5-0)^2 + (0{,}9-0)^2 = 0{,}64 + 0{,}16 + 0{,}25 + 0{,}81 = 1{,}86$.
2. Unit 2'ye mesafe (karesi): $(0{,}8-1)^2 + (0{,}4-1)^2 + (0{,}7-0)^2 + (0{,}3-0)^2 = 0{,}04 + 0{,}36 + 0{,}49 + 0{,}09 = 0{,}98$.
3. Kazanan Unit 2.
4. Güncelleme: $w_2 \leftarrow w_2 + 0{,}6\,(i_1 - w_2)$.
   - $0{,}8 + 0{,}6 \cdot 0{,}2 = 0{,}92$
   - $0{,}4 + 0{,}6 \cdot 0{,}6 = 0{,}76$
   - $0{,}7 + 0{,}6 \cdot (-0{,}7) = 0{,}28$
   - $0{,}3 + 0{,}6 \cdot (-0{,}3) = 0{,}12$
5. Yeni $w_2 = (0{,}92;\ 0{,}76;\ 0{,}28;\ 0{,}12)$. İlk iki değer $i_1$'deki 1'lere, son iki değer 0'lara yaklaştı. Ağırlık örneğe benzemeye başladı.

**Uzun iterasyonlardan sonra:**

- Unit 1: $(0;\ 0;\ 0{,}5;\ 1{,}0)$
- Unit 2: $(1{,}0;\ 0{,}5;\ 0;\ 0)$
- $i_1$ ve $i_3$ Unit 2'ye, $i_2$ ve $i_4$ Unit 1'e yakın. Kümeleme tamamlandı.

**Örnek 2: yeni örnek $i_5 = (1, 1, 1, 0)$.**

1. Unit 1'e mesafe (karesi): $(0-1)^2 + (0-1)^2 + (0{,}5-1)^2 + (1-0)^2 = 1 + 1 + 0{,}25 + 1 = 3{,}25$.
2. Unit 2'ye mesafe (karesi): $(1-1)^2 + (0{,}5-1)^2 + (0-1)^2 + (0-0)^2 = 0 + 0{,}25 + 1 + 0 = 1{,}25$.
3. $i_5$ Unit 2 kümesine daha çok benziyor.

### Kararlılık-Esneklik İkilemi

- Bir öğrenci sordu: bilinmeyen örnek gelince ağırlıkları güncelliyor muyuz?
- Hocanın cevabı: amaca bağlı.
  - Öğrenme tamamlandıysa ve yalnız yeni örneğin hangi kümeye benzediğini bulmak istiyorsanız güncellemezsiniz.
  - Öğrenmeye devam etmek istiyorsanız güncellersiniz. Ama dikkat: sistem hem kararlı kalmalı (öğrendiğinden kopmamalı) hem esnek olmalı (yeniyi öğrenip genelleşebilmeli).

### Gauss Karışım Modeli (Kısa Bilgi)

- Dışarıdan etiketsiz, karışık bir dağılım görürüz. Aslında veri, örneğin iki Gauss dağılımından gelen iki kümenin karışımıdır.
- GMM bu kümeleri bulmaya çalışır. k-means'e benzer bir yaklaşımla, beklenti-en büyükleme (EM) adımlarıyla çalışır.
- k-means'ten farkı: k-means örneği kesin olarak bir kümeye atar. GMM örneğin hangi kümeye ne kadar yakın olduğunu (olasılığını) da hesaba katar.
- Hocaya göre GMM k-means'ten daha başarılı kümeleme yapar. Pek çok çalışmada önce k-means ile kümeler bulunur, sonra GMM ile sonuç iyileştirilir.

### Pekiştirmeli Öğrenme

- Gözetimli öğrenmede (supervised) girişler ve çıkışlar verilir. Eğitmensiz öğrenmede yalnız girişler verilir.
- Pekiştirmeli öğrenmede etiket yoktur. Yapılan eylemlere karşılık ödül ya da ceza gelir.
- Türkçede önce "ödül-ceza ile öğrenme" deniyordu. Bugün "pekiştirmeli öğrenme" en çok kullanılan karşılık.
- **Köpek örneği:** sopayı geri getirirse kemik (ödül) alır. Böylece sopa atılınca getirmesi gerektiğini öğrenir.
- **Robotik:** önce robotik çalışmalarda kullanıldı. Robota "şu taşı getirirsen ödül, duvara çarparsan ceza" denir.
- **E-posta/promosyon örneği:** firma çok mesaj gönderir. Kullanıcılar abonelikten çıkmaya (unsubscribe) başlarsa bu bir cezadır. Firma mesaj sıklığını azaltmayı öğrenir.
- **Dijital reklam örneği:**
  - Reklam yerleri için reklamverenler açık artırmaya girer. Kim daha çok öderse reklamı görünür.
  - Ör. bir spor markası belirli bir hedef kitleye reklam veriyor ama satış olmuyor. Bu bir ceza.
  - Strateji değiştirilmeli: açık artırmadan çekil, teklifi düşür ya da hedef kitleyi değiştir. Satış çok iyiyse teklifi artır.
  - Bu tür zamana göre değişen kararları gözetimli öğrenmeyle izlemek zordur.
  - Hoca bunun Adobe ya da Alibaba'nın bir uygulaması olduğunu hatırladığını söyledi, emin değildi.
- Oyunlarda kullanılabildiği için son yıllarda çok popüler oldu.

**Döngü:**

```
durum (s_t) --> eylem (a_t) --> yeni durum (s_t+1) --> ödül/ceza (r)
     ^                                                        |
     +--------------------- öğrenme ---------------------------+
```

- Öğrenme yinelemelidir (iterative). Ödül ve cezaya göre öğrenilir ve öğrenme tamamlanana kadar sürer.
- Öğrenme bitince sistem hangi durumda ne yapacağını bilir.

### Markov Karar Süreci

- Bir kararı geçmişteki pek çok olay etkiler. Hepsini hesaba katmak olasılık hesabını çok büyütür.
- Markov varsayımı: $1$'den $t$'ye kadarki geçmiş yalnız $s_t$ ile temsil edilir. $s_{t+1}$ yalnız $s_t$'ye bağlıdır.
- Parametreler: durumlar ($S$), eylemler ($A$), durum geçiş fonksiyonu ($T$), anlık ödül fonksiyonu ($R$).
- Anlık ödül (immediate reward): $t$ anında eylem yapılır, $t+1$ anında ödül ya da ceza hemen alınır.

### Q-Öğrenme

- Amaç: bir durumdayken yapılabilecek eylemlerden en yüksek getirili olanı seçmek.
- Q matrisi, bir durumdan bir eyleme gitmenin gerçek (uzun vadeli) ödül/ceza değerini tutar. Deneyimden öğrenileni güncel olarak saklar.

**Oda örneği:**

- 5 oda (A, B, C, D, E) ve dışarısı (F). Robot dışarı (F) çıkmaya çalışıyor.
- Durum = bulunulan oda. Eylem = bir odadan diğerine geçmek.
- Doğrudan F'ye açılan kapıların ödülü 100, diğer bağlantıların 0. Bağlantı yoksa geçiş tanımsız (null).
- Bağlantılar (çizge): A–E, B–D, B–F, C–D, D–E, E–F, ayrıca F–F (hedefte kalmak).

**Ödül matrisi R (satır: durum, sütun: eylem; "–" = bağlantı yok):**

| | A | B | C | D | E | F |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| A | – | – | – | – | 0 | – |
| B | – | – | – | 0 | – | 100 |
| C | – | – | – | 0 | – | – |
| D | – | 0 | 0 | – | 0 | – |
| E | 0 | – | – | 0 | – | 100 |
| F | – | 0 | – | – | 0 | 100 |

**Algoritma:**

1. Parametreyi ($\gamma$) ve R matrisini belirle. Q matrisini sıfırla ilklendir.
2. Her bölümde (episode) rastgele bir başlangıç durumu seç.
3. Hedefe ulaşana kadar: o durumdan gidilebilecek eylemlerden birini rastgele seç.
4. $Q(s,a) = R(s,a) + \gamma \max_{a'} Q(s',a')$ ile güncelle.
5. Q matrisi artık değişmeyene (yakınsayana) kadar bölümlere devam et.

**Örnek adımlar ($\gamma = 0{,}8$):**

1. Bölüm 1: başlangıç B, rastgele eylem F'ye gitmek.
   - $Q(B,F) = R(B,F) + 0{,}8 \cdot \max\{Q(F,B), Q(F,E), Q(F,F)\} = 100 + 0{,}8 \cdot 0 = 100$.
   - F'ye ulaşıldı, bölüm bitti.
2. Bölüm 2: başlangıç D. Gidilebilecek yerler B, C, E. Rastgele B seçildi.
   - $Q(D,B) = R(D,B) + 0{,}8 \cdot \max\{Q(B,D), Q(B,F)\} = 0 + 0{,}8 \cdot 100 = 80$.
   - B'den yine rastgele F seçildi. $Q(B,F) = 100 + 0{,}8 \cdot 0 = 100$, değişmedi.

**Yakınsamış ve normalize edilmiş Q matrisi (en büyük değer 100'e çekilmiş):**

| | A | B | C | D | E | F |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| A | 0 | 0 | 0 | 0 | 80 | 0 |
| B | 0 | 0 | 0 | 64 | 0 | 100 |
| C | 0 | 0 | 0 | 64 | 0 | 0 |
| D | 0 | 80 | 51 | 0 | 80 | 0 |
| E | 64 | 0 | 0 | 64 | 0 | 100 |
| F | 0 | 80 | 0 | 0 | 80 | 100 |

- Elle hesaplarsanız değerler 100'ü geçer. Tablodaki matris min-max ile normalize edilmiş hâlidir.
- D'den C'ye gitmenin değeri 51: C çıkmaz oda, o yöne gitmenin anlamı yok.
- A'dan E'ye gitmek 80, E'den A'ya gitmek 64: A'ya gidince sıkışılır.

**Öğrenilmiş Q ile yol bulma (robot C'de):**

1. C'den yalnız D'ye gidilebilir (64).
2. D'den B (80) ya da E (80). İkisi eşit, biri seçilir. C (51) seçilmez.
3. B seçildiyse: B'den D (64) ya da F (100). F seçilir.
4. Yol: C → D → B → F. Her durumda en yüksek değerli eylem seçilir, böylece en kısa yol bulunur.

### Ders sonrası notlar

- **SOM mesafeleri:** hoca formülü karekök içinde yazdı. Ama 1,86 ve 0,98 değerleri karekök alınmadan bulunan kare mesafelerdir. Karekök alınırsa yaklaşık 1,36 ve 0,99 çıkar. Kazanan yine Unit 2'dir, sonuç değişmez.
- **"Goals / GOS fonksiyonu":** altyazıdaki bu ifade Gauss (Gaussian) fonksiyonudur. "N-Brut / Neybrut" komşuluk (neighborhood), "Gözlümünün mixture" Gauss karışım modelidir.
- **Q-öğrenmedeki 0,8:** hoca bu değere "öğrenme oranı / öğrenme parametresi" dedi. Bu formülde 0,8 aslında indirim katsayısıdır (discount factor, $\gamma$). Gelecekteki ödülün bugünkü değerini belirler. Genel Q-öğrenme formülünde ayrıca bir öğrenme oranı $\alpha$ vardır: $Q(s,a) \leftarrow Q(s,a) + \alpha\,[r + \gamma \max_{a'} Q(s',a') - Q(s,a)]$. Derste kullanılan basit hâl $\alpha = 1$ durumudur.
- **İlk adım hatası:** hoca önce $Q(B,F)$ için 80 yazdı, sonra düzeltti. Doğrusu 100 ($100 + 0{,}8 \cdot 0$).
- **Hedef oda:** hoca bir yerde "esas ulaşılmak istenilen D" dedi. Hedef F'dir (dışarısı).
- **Yol örneği:** hoca "C'den B'ye gitti" dedi. C'den B'ye doğrudan bağlantı yok. Doğru yol C → D → B → F.
- **MDP geçiş fonksiyonu:** genel tanımda $s_{t+1}$ hem $s_t$'ye hem $a_t$'ye bağlıdır: $T(s_t, a_t, s_{t+1})$. Hoca yalnız "T anındaki duruma bağlı" diye özetledi.
- **Teknik aksaklıklar:** hocanın tablet kaleminin ve bilgisayarının şarjı bitti. Ders yaklaşık 15 dakika geç başladı. 00:33-00:51 ve 02:04-02:12 arasında kesinti oldu. 02:22-02:24 arası yeniden kesildi; Q-öğrenme özeti sözlü tamamlandı. Bazı formüller tahtaya yazılamadı, sözle anlatıldı.
- **Ders yapılmayan gün:** hoca derse "Geçen hafta ders yapamadık, direktörlükte toplantı vardı" diyerek başladı ve telafi edeceğini söyledi. Bu, 15 Aralık 2020'deki ders 11'in yapılmadığını gösteriyor.
- **Sonraki ders:** hoca Q-öğrenmenin üzerinden bir sonraki dersin başında tekrar geçeceğini söyledi.

Gemini Notebook gibi bir araca altyazı dosyasını yükleyerek bu ders hakkında daha ayrıntılı soru-cevap yapabilirsiniz.
