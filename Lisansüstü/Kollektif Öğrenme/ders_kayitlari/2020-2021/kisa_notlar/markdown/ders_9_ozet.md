# Ders 9 Çalışma Özeti

## Genel Konular

- Önceki konunun kısa hatırlatması: regresyon ve kümelemede kollektif öğrenme
  - Regresyonda kollektif öğrenme sınıflandırmadan çok farklı değildir.
  - Kümelemede temel öğreniciler aynı kümeleri bulsa bile küme etiketleri farklı olabilir. Çözüm olarak örneklerin kaç çözümde birlikte aynı kümede bulunduğu sayılır, bu sayılardan bir benzerlik matrisi kurulur ve bu matris üzerinde hiyerarşik kümeleme ile sonuç kümeleme bulunur.
- AdaBoost algoritmasının orijinal yayındaki hâli (ekrandan, 00:10:00 ve 00:15:00)
  - Kaynak, AdaBoost'un önerildiği 1997 tarihli makaledir (Freund ve Schapire). Derste bu makaledeki Teorem 6'nın ispatı incelendi.
  - Girdi: $N$ etiketli örnek $\langle (x_1,y_1),\dots,(x_N,y_N)\rangle$, örnekler üzerinde bir $D$ dağılımı, zayıf öğrenme algoritması **WeakLearn** ve iterasyon sayısı $T$.
  - Başlangıç: $w_i^1 = D(i)$, $i=1,\dots,N$. $D$ genelde tekdüze (uniform) seçilir, yani her örnek için $1/N$.
  - $t = 1,\dots,T$ için:
    - 1. $\mathbf{p}^t = \mathbf{w}^t / \sum_{i=1}^N w_i^t$ (olasılıkların toplamı 1 olur).
    - 2. WeakLearn $\mathbf{p}^t$ dağılımıyla çağrılır, bir hipotez $h_t: X \to [0,1]$ döner.
    - 3. Hata: $\varepsilon_t = \sum_{i=1}^N p_i^t \, |h_t(x_i) - y_i|$, yani hatalı örneklerin seçilme olasılıklarının toplamı.
    - 4. $\beta_t = \varepsilon_t / (1-\varepsilon_t)$.
    - 5. Ağırlık güncellemesi: $w_i^{t+1} = w_i^t \, \beta_t^{\,1-|h_t(x_i)-y_i|}$.
  - Çıktı (ekrandan, 00:40:00): $h_f(x) = 1$, eğer $\sum_{t=1}^T (\log 1/\beta_t)\, h_t(x) \ge \frac{1}{2}\sum_{t=1}^T \log 1/\beta_t$; aksi hâlde $0$.
- Teorem 6 (ekrandan, 00:20:00)
  - WeakLearn, AdaBoost tarafından $T$ kez çağrılsın ve hataları $\varepsilon_1,\dots,\varepsilon_T$ olan hipotezler üretsin. Sonuç hipotezin hatası $\varepsilon = \sum_{i=1}^N D(i)\, 1\{h_f(x_i)\ne y_i\}$ olmak üzere:
  - $$\varepsilon \le 2^T \prod_{t=1}^T \sqrt{\varepsilon_t (1-\varepsilon_t)}$$
- Lemma 1 (ekrandan, 00:25:00): $\alpha \ge 0$ ve $r\in[0,1]$ için $\alpha^r \le 1-(1-\alpha)r$. İspatı derste verilmedi.
- İspatın ana adımları
  - Ağırlıkların toplamı için üst sınır: güncelleme kuralı ve Lemma 1 ile $\sum_i w_i^{t+1} \le (1-(1-\beta_t)(1-\varepsilon_t))\sum_i w_i^t$; bu adım $t=1$'e kadar açılınca $\sum_i w_i^{T+1} \le \prod_{t=1}^T (1-(1-\beta_t)(1-\varepsilon_t))$ (Eşitlik 10) elde edilir.
  - Hata durumu: iki hata türü ($y_i=0, h_f=1$ ve $y_i=1, h_f=0$) için de aynı eşitsizlik çıkar: $\prod_{t=1}^T \beta_t^{-|h_t(x_i)-y_i|} \ge \left(\prod_{t=1}^T \beta_t\right)^{-1/2}$ (Eşitlik 13 ve 15).
  - Ağırlıkların toplamı için alt sınır: $w_i^{T+1} = D(i)\prod_t \beta_t^{1-|h_t(x_i)-y_i|}$ ve bütün ağırlıkların toplamı yalnız hatalı örneklerin ağırlık toplamından büyük olduğu için $\sum_i w_i^{T+1} \ge \varepsilon \left(\prod_t \beta_t\right)^{1/2}$ (Eşitlik 17).
  - İki sınır birleşince: $\varepsilon \le \prod_{t=1}^T \dfrac{1-(1-\beta_t)(1-\varepsilon_t)}{\sqrt{\beta_t}}$ (Eşitlik 18).
  - Üst sınırı en küçük yapan $\beta_t$, türev alıp sıfıra eşitleyerek $\beta_t = \varepsilon_t/(1-\varepsilon_t)$ bulunur (ekrandan, 01:15:00). Bu değer yerine konunca teoremdeki sınır (Eşitlik 20) çıkar (ekrandan, 01:20:00).
- Teoremin yorumu
  - Son hata bütün tekil öğrenicilerin hatalarına bağlıdır. Topluluğa yeni bir öğrenici eklenince üst sınır $2\sqrt{\varepsilon_t(1-\varepsilon_t)}$ ile çarpılır.
  - Bütün $\varepsilon_t = 1/2$ ise üst sınır $1$ olur; algoritma hiçbir şey öğrenmez. $\varepsilon_t < 1/2$ olmalıdır.
  - Bireysel hatalar $1/2$'den küçükse üst sınır temel öğrenici sayısıyla üstel biçimde düşer.
- Teori ve deney ilişkisi üzerine yorum
  - AdaBoost'ta $\beta_t$ seçimi keyfi değildir; teorik analizden çıkmıştır. Teori algoritmaya yol göstermiştir.
  - Deneyden önce bir beklenti ve onun açıklaması olmalıdır; deneme yanılma (kör arama) sonuçlarından ipucu çıkmaz.

## Hocanın Özellikle Vurguladığı Kısımlar

- Teoremdeki hata eğitim kümesi üzerindeki hatadır
  - Etiketler biliniyor, yani söz konusu olan eğitim kümesidir. Teorem test başarısı hakkında değil, eğitim hatasının ne kadar hızlı düştüğü (yakınsama hızı) hakkındadır.
  - Başka bir algoritma için daha küçük bir üst sınır gösterilirse, o algoritmanın eğitim hatasını daha hızlı düşürdüğü teorik olarak ispatlanmış olur; test kümesinde daha başarılı olduğu ispatlanmış olmaz.
- $\beta_t = \varepsilon_t/(1-\varepsilon_t)$ seçimi analizden gelir
  - Üst sınırı minimum yapan $\beta_t$ ile algoritmadaki 4. adım aynıdır. Algoritma ve teori birlikte geliştirilmiştir.
- $\varepsilon_t \ge 1/2$ durumu
  - Hata $0.6$ olan iki sınıflı bir sınıflandırıcının kararları ters çevrilirse hata $0.4$ olur. Uygulamada $\varepsilon_t$ $1/2$'ye ulaşınca o adımın öğrenicisi topluluğa eklenmez ve algoritma durur.
- Eğitim kümesinde öğrenici eklemek zarar vermez
  - Teori elde olduğu için "öğrenici eklersem ne olur?" sorusunun cevabı deney yapmadan verilebilir: eğitim kümesindeki başarı kötüleşmez.
- Deney yapmadan önce beklentiyi ve nedenini yazmak
  - Beklenti doğru çıkarsa doğru yolda olunduğu, yanlış çıkarsa neyin yanlış düşünüldüğü öğrenilir. Büyük veri ve büyük mimarilerde deneyler pahalı olduğu için bu daha da önemlidir.

## Kısa Tekrar Notları

- AdaBoost: $w_i^1 = D(i)$, $\mathbf{p}^t = \mathbf{w}^t/\sum_i w_i^t$, $\varepsilon_t = \sum_i p_i^t|h_t(x_i)-y_i|$, $\beta_t = \varepsilon_t/(1-\varepsilon_t)$, $w_i^{t+1} = w_i^t \beta_t^{1-|h_t(x_i)-y_i|}$.
- Doğru sınıflanan örneğin ağırlığı $\beta_t<1$ ile çarpılıp küçülür; yanlış sınıflananınki aynı kalır (normalize edilince göreli olarak artar).
- Teorem 6: $\varepsilon \le 2^T\prod_t\sqrt{\varepsilon_t(1-\varepsilon_t)}$.
- Lemma 1: $\alpha^r \le 1-(1-\alpha)r$, $\alpha\ge0$, $r\in[0,1]$.
- İspat iskeleti: ağırlık toplamına üst sınır (Eş. 10), hatalı örnekler için eşitsizlik (Eş. 13/15), ağırlık toplamına alt sınır (Eş. 17), birleştir (Eş. 18), $\beta_t$'ye göre minimize et.
- $\varepsilon_t = 1/2$ için sınır $1$; $\varepsilon_t = 1/3$ için adım başına çarpan $\approx 0.943$, $\varepsilon_t = 1/4$ için $\approx 0.866$.
- Teorem eğitim hatasının yakınsama hızını anlatır, test başarısını değil.
- Bagging, Random Forest ve Random Subspace paralelleştirilebilir; boosting'de her öğrenici bir öncekinin sonucunu beklediği için doğrudan paralelleştirilemez.
- Normalizasyon gereksinimi algoritmaya bağlıdır: SVM ve YSA'da gerekir, karar ağacı ve 1-NN'de gerekmez. Çıkış normalize edildiyse tahmin geri dönüştürülür (denormalizasyon).
- MSE oransal bir başarı değildir; hataların karelerinin ortalamasıdır.

## Detaylı Açıklamalar

- **Algoritmanın işleyişi.** AdaBoost her adımda örnekler üzerindeki bir olasılık dağılımına göre zayıf bir öğrenici eğitir. $\mathbf{w}^t$ ağırlık vektörü normalize edilerek $\mathbf{p}^t$ seçilme olasılıkları elde edilir. $h_t$ hipotezi (bir karar ağacı ya da başka bir model) $[0,1]$ aralığında değer üretir. Hata $\varepsilon_t$, $h_t$'nin yanlış yaptığı örneklerin seçilme olasılıklarının toplamıdır; çünkü $h_t(x_i)$ ve $y_i$ ikisi de 0 ya da 1 iken $|h_t(x_i)-y_i|$ doğru tahminde 0, yanlış tahminde 1 olur. 5. adımda üs $1-|h_t(x_i)-y_i|$ doğru tahminde 1 olur ve ağırlık $\beta_t\in(0,1)$ ile çarpılarak küçülür; yanlış tahminde üs 0 olur, $\beta_t^0=1$ ve ağırlık değişmez. Böylece sonraki öğrenici, önceki öğrenicilerin zorlandığı örneklere daha çok odaklanır.
- **Hatanın tanımı ve $D$.** Teoremdeki $\varepsilon$, $h_f$'nin yanlış yaptığı örneklerin $D(i)$ değerlerinin toplamıdır. $D$ tekdüze ise ($1/N$) bu, yanlış sınıflanan örneklerin oranıdır ve $[0,1]$ aralığındadır. $D$ tekdüze olmak zorunda değildir: örneğin etiketlerin bir kısmı konuyu çok iyi bilen, bir kısmı daha az bilen kişilerce verildiyse, güvenilen örneklerin başlangıç ağırlığı daha büyük tutulabilir. Teorem değişmez; sonuç hata başlangıçta atanan $D$'ye göre tanımlanır.
- **Ağırlık toplamına üst sınır.** Eşitlik 1 bütün örnekler için toplanır (Eş. 2). Lemma 1'de $\alpha=\beta_t$, $r = 1-|h_t(x_i)-y_i|$ alınır; $r$ ya 0 ya 1 olduğundan lemma uygulanabilir ve $\sum_i w_i^t\beta_t^{1-|h_t(x_i)-y_i|} \le \sum_i w_i^t(1-(1-\beta_t)(1-|h_t(x_i)-y_i|))$ (Eş. 3) çıkar. $|h_t(x_i)-y_i|$ terimi ağırlıklarla toplanınca $\varepsilon_t$'yi verir ve Eş. 4 elde edilir: $\sum_i w_i^{t+1} \le (1-(1-\beta_t)(1-\varepsilon_t))\sum_i w_i^t$ (ekrandan, 00:35:00). Bu eşitsizlik son adım ($T$), sondan bir önceki adım ($T-1$) için yazılıp birbirinin içine konur (Eş. 5-7); büyük olan ifade yerine konduğu için eşitsizlik bozulmaz. $t=1$'e kadar devam edilince ve $\sum_i w_i^1 = 1$ kullanılınca Eş. 10 çıkar.
- **Hatalı örnekler için eşitsizlik.** $y_i=0$ ve $h_f(x_i)=1$ ise çıktı kuralından $-\sum_t \log(\beta_t)h_t(x_i) \ge -\frac12\sum_t\log\beta_t$ (Eş. 11) yazılır. $y_i=0$ olduğundan $|h_t(x_i)-y_i| = h_t(x_i)$ olur ve $\prod_t\beta_t^{-h_t(x_i)} = e^{-\sum_t\log(\beta_t)h_t(x_i)}$ (Eş. 12). Üstel fonksiyon artan olduğu için Eş. 11'den $\prod_t \beta_t^{-|h_t(x_i)-y_i|} \ge (\prod_t\beta_t)^{-1/2}$ (Eş. 13) elde edilir (ekrandan, 00:45:00). $y_i=1$, $h_f(x_i)=0$ durumunda eşitsizlik ters yönde kurulur, $|h_t(x_i)-1| = 1-h_t(x_i)$ kullanılır ve aynı sonuç (Eş. 15) çıkar (ekrandan, 00:50:00). Yani hatanın türü ne olursa olsun bu eşitsizlik geçerlidir.
- **Ağırlık toplamına alt sınır.** Güncelleme kuralı sona kadar açılınca $w_i^{T+1} = D(i)\prod_t\beta_t^{1-|h_t(x_i)-y_i|}$ (Eş. 16). Ağırlıklar negatif olmadığından tüm ağırlıkların toplamı, yalnız $h_f$'nin hata yaptığı örneklerin ağırlık toplamından büyüktür. Bu örnekler için $\prod_t\beta_t^{1-|\cdot|} = \prod_t\beta_t \cdot \prod_t\beta_t^{-|\cdot|}$ yazılır ve Eş. 13/15 kullanılınca $\sum_i w_i^{T+1} \ge \varepsilon(\prod_t\beta_t)^{1/2}$ (Eş. 17) bulunur (ekrandan, 01:10:00).
- **Birleştirme ve $\beta_t$ seçimi.** Eş. 17 $(\prod_t\beta_t)^{1/2}$'ye bölünür, Eş. 10 yerine konur: $\varepsilon \le \prod_t \frac{1-(1-\beta_t)(1-\varepsilon_t)}{\sqrt{\beta_t}}$ (Eş. 18). $\varepsilon_t$ veriden gelir, $\beta_t$ ise seçilebilir. Çarpanların hepsi pozitif ve birbirinden bağımsız olduğu için her çarpan ayrı ayrı minimize edilir. Çarpım kuralıyla türev alınıp sıfıra eşitlenir: $\beta_t^{-1/2}(1-\varepsilon_t) = \frac12\beta_t^{-3/2}(1-(1-\beta_t)(1-\varepsilon_t))$; sadeleştirince $\beta_t(1-\varepsilon_t) = \varepsilon_t$, yani $\beta_t = \varepsilon_t/(1-\varepsilon_t)$ (ekrandan, 01:15:00). Bu değer konunca pay $2\varepsilon_t$ olur, payda $\sqrt{\varepsilon_t/(1-\varepsilon_t)}$ olur ve her çarpan $2\sqrt{\varepsilon_t(1-\varepsilon_t)}$'ye iner: $\varepsilon \le 2^T\prod_t\sqrt{(1-\varepsilon_t)\varepsilon_t}$ (Eş. 20, ekrandan, 01:20:00).
- **Sınırın davranışı.** $2^T$ çok büyük görünür (örneğin $T=100$ için $2^{100}$), ama yanındaki çarpım çok küçüktür. Bütün $\varepsilon_t=1/2$ ise $\sqrt{1/4} = 1/2$ olur, $(1/2)^T\cdot 2^T = 1$ çıkar: sınır her şeyi yanlış yapmaya izin verir. $\varepsilon_t$ $1/2$'ye yaklaştıkça sınır büyür, sıfıra yaklaştıkça küçülür. Ekrandaki grafikte (Şekil 1) üst sınır temel öğrenici sayısına göre çizilmiş; bireysel hatalar $1/3$ ve $1/4$ iken eğrilerin üstel olarak düştüğü görülür (ekrandan, 01:25:00). <!-- BELİRSİZ: grafikteki üçüncü eğrinin hangi hata değerine ait olduğu altyazıdan ve kareden net okunamadı. -->
- **Hız ve çalışma süresi farkı.** Bir öğrencinin sorusu üzerine hoca, "hızlı yakınsama"nın çalışma süresi anlamına gelmediğini açıkladı: 100 öğrenicili bir topluluk 10 öğreniciliden elbette daha uzun sürede eğitilir; hızlı olan, öğrenici sayısına göre hata üst sınırının doğrusal değil üstel düşmesidir.
- **Açık bırakılan sorular.** Ağırlık güncellemesi gradyan inişindeki gibi toplamsal ($w^{t+1} = w^t - \eta\, d(\text{loss})$) yapılabilir miydi ve etkisi ne olurdu? Belli bir hataya ulaşmak için gereken $T$ bulunabilir mi? AdaBoost dışında boosting algoritmaları var mı?

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
