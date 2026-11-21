# Ders 2 Çalışma Özeti

## Genel Konular

- XOR probleminin tek katmanlı perseptronla çözülememesi
  - Her eğitim örneği, nöron denklemine konunca ağırlıklar ve eşik için doğrusal bir eşitsizlik üretir. Bu eşitsizliklerden ağırlıklar analitik olarak bulunabiliyorsa problem doğrusaldır.
  - AND kapısı için dört eşitsizlik $\theta > 0$, $w_2 < \theta$, $w_1 < \theta$, $w_1 + w_2 \ge \theta$ olur ve örneğin $\theta = 2$, $w_1 = w_2 = 1$ bir çözümdür (ekrandan, 00:15:00).
  - XOR için $w_2 \ge \theta$ ve $w_1 \ge \theta$ iken $w_1 + w_2 < \theta$ istenir; $\theta > 0$ olduğundan bu çelişkidir, çözüm yoktur (ekrandan, 00:20:00).
  - Sonuç: tek katmanlı perseptron yalnız doğrusal ayrılabilir problemleri çözer. Bu kısıt, yapay sinir ağlarının bir dönem gözden düşmesinin sebeplerinden biridir.
- Doğrusallık kavramı
  - Doğrusal problem, doğrusal bir denklem setiyle bilinmeyenleri çözülebilen problemdir. Grafikte eğri görünen bir parabol de bu anlamda doğrusal çözülebilir.
  - Çıktıları farklı olan örnekleri bir doğru ya da düzlemle ayıramıyorsak problem doğrusal değildir.
- Ağ topolojileri (ekrandan, 00:25:00)
  - Tek katmanlı ileri beslemeli ağ (perseptron), çok katmanlı ileri beslemeli ağ (çok katmanlı perseptron), geri beslemeli (recurrent) ağ.
  - Katman sayılırken giriş katmanı sayılmaz. Giriş, bir gizli katman ve çıkıştan oluşan ağ iki katmanlıdır.
  - İleri beslemeli ağda hesaplama girişten çıkışa tek yönde gider.
  - Recurrent ağ bir önceki örnekten kalan bilgiyi saklayıp sonraki örneğin hesabına katar; bu bir tür hafızadır. Zaman serileri (nüfus tahmini), art arda gelen görüntü kareleri ve geçmişe bağlı olay tahmini için kullanılır. LSTM yapıları ne kadar geçmişin hatırlanacağını kapı benzeri bir mekanizmayla ayarlar.
- Hebb öğrenme kuralı (1949, Donald Hebb)
  - Bağlı iki nöron birlikte aktive oluyorsa aralarındaki bağlantı güçlendirilir, biri aktifken diğeri değilse zayıflatılır.
  - Algoritma: ağırlıklar ve bias sıfırlanır; her eğitim vektörü için $x_i = s_i$, $y = t$ alınır; $w_i(\text{yeni}) = w_i(\text{eski}) + y x_i$, $b(\text{yeni}) = b(\text{eski}) + y$ (ekrandan, 00:35:00).
  - Tek geçişlidir: bütün örnekler yalnız bir kez gösterilir.
  - Zayıflığı: ağırlıklar sınırsız büyüyebilir ya da küçülebilir. Birkaç tesadüfi örnekle büyüyen ağırlık sonradan düzeltilemez.
- Perseptron öğrenme kuralı
  - İkili sınıflandırma için öğretmenli, iteratif bir algoritmadır. Giriş ve çıkış sayısında kısıt yoktur; bias her zaman kullanılmalıdır.
  - Net girdi $y\_in = b + \sum_i x_i w_i$; çıkış eşik fonksiyonu ile: $y_{in} > \theta$ ise $1$, $-\theta \le y_{in} \le \theta$ ise $0$, $y_{in} < -\theta$ ise $-1$ (ekrandan, 00:45:00).
  - Hedef tutturulamadıysa ($y \ne t$) $w_i(\text{yeni}) = w_i(\text{eski}) + \eta\, t\, x_i$ ile güncellenir; tutturulduysa değişiklik yapılmaz.
  - Durma koşulu: bir epok boyunca hiçbir ağırlık değişmemesi ya da belirlenen epok sayısı.
  - Doğrusal ayrılabilir her problemi sonlu sayıda iterasyonda çözeceği matematiksel olarak kanıtlıdır; ama bu sayı çok büyük olabilir.
- Epok kavramı
  - Bir epok, bütün eğitim örneklerinin bir kez gösterilmesidir. İterasyon sayısı örnek sayısıyla değiştiği için durma koşulunu epokla vermek daha doğrudur.
- AND kapısı perseptron örnekleri
  - Binary giriş, bipolar çıkış, $\eta = 1$, $\theta = 0.2$, başlangıç ağırlıkları sıfır: eğitim 10. epokta biter (ekrandan, 00:50:00 ve 00:55:00).
  - Bipolar giriş, bipolar çıkış, $\theta = 0$: birinci epoktan sonra sistem eğitilmiş olur; 2. epokta hiç değişim olmaz, ağırlıklar $(1, 1, -1)$ (ekrandan, 01:15:00).
  - Sonuç: mümkünse bipolar giriş ve çıkış kullanılmalıdır.
- Karakter tanıma örneği (ekrandan, 01:20:00)
  - 7 harf, 3 farklı fontla yazılmış 21 örnek. Her karakter $7 \times 9$ piksellik bir matris, yani 63 giriş birimi; çıkış birimi sayısı 7 (sınıf sayısı).
- Adaline (Widrow ve Hoff, 1960)
  - Tek çıkışlı, çok girişli, bias'lı yapı; bipolar giriş ve hedef kullanır.
  - Delta kuralı: $w_{ij}(\text{yeni}) = w_{ij}(\text{eski}) + \alpha (t_j - y_j) x_i$ (ekrandan, 01:30:00). Hedefle hesaplanan değer arasındaki farkı kullanır, ortalama karesel hatayı en aza indirmeye çalışır.
  - Öğrenme katsayısı pratikte giriş sayısı $n$ dikkate alınarak $0.1 \le n\alpha \le 1$ aralığında seçilir.
  - AND (binary giriş, bipolar hedef) için hatayı en aza indiren ağırlıklar $w_1 = w_2 = 1$, $w_0 = -3/2$; ayırma doğrusu $x_1 + x_2 - 3/2 = 0$ (ekrandan, 01:35:00). Bu ağırlıklarla dört örnek için toplam karesel hata 1'dir.
- Delta kuralının türevden elde edilmesi (ekrandan, 01:45:00)
  - $E = \sum_{j=1}^{m} (t_j - y\_in_j)^2$, $\dfrac{\partial E}{\partial w_{IJ}} = -2(t_J - y\_in_J)x_I$; buradan $\Delta w_{IJ} = \alpha (t_J - y\_in_J) x_I$.
- Madaline (Many Adaptive Linear Neurons)
  - İki gizli Adaline ($Z_1$, $Z_2$) ve bir çıkış Adaline'ından oluşur (ekrandan, 01:55:00).
  - MR1 algoritmasında çıkış ağırlıkları $v_1 = v_2 = b_3 = 0.5$ sabittir; yalnız gizli birimlerin ağırlıkları ve bias'ları Adaline gibi ayarlanır. MR2'de tüm ağırlıklar ayarlanır.
  - Bipolar XOR örneğinde iki ayrı doğru oluştuğu için artılarla eksiler ayrılabilir. Bu fikir çok katmanlı perseptrona götürür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tek katmanlı perseptron hiçbir doğrusal olmayan problemi çözemez
  - Bu sonuç, XOR'un eşitsizliklerinin çelişmesiyle matematiksel olarak gösterilir. "Perseptronla çözülemez" denmesinin sebebi, eşitsizliklerin perseptron denkleminden kurulmasıdır.
- Katman sayma notasyonu
  - Girişi katman sayarsanız çıkışı saymamalısınız. Tek giriş ve tek çıkış katmanı olan perseptron tek katmanlıdır.
- Hebb kuralının sınırsız güçlenme sorunu
  - "Her kırmızı gördüğümde elmayı hatırlamak" benzetmesi: bağlantı kontrolsüz güçlenirse alakasız durumlarda da yanlış çağrışım yapılır.
- Durma koşulu her iteratif öğrenme algoritmasında tanımlanmalıdır
  - Hedef doğruluk oranı (örneğin %90) ya da epok sayısı olabilir.
- Bipolar gösterim öğrenmeyi hızlandırır
  - Güncelleme $t x_i$ çarpımına dayanır; $x_i = 0$ olan girişlerde hedef hiç dikkate alınmaz. $-1$ ve $+1$ kullanılınca her adımda öğrenme olur.
- Delta kuralı ve karesel hata hâlâ kullanılır
  - Adaline ve Madaline bugün az kullanılsa da hedefle çıktı farkına bakan, karesel hatayı küçülten fikir çok katmanlı ağlarda ve derin öğrenmede geri yayılım (backpropagation) ile birlikte kullanılır.
- Üç kuralın karşılaştırması
  - Hebb: hesaplanan çıktı $\times$ giriş. Perseptron: hedef $\times$ giriş $\times$ öğrenme katsayısı. Delta: (hedef $-$ çıktı) $\times$ giriş $\times$ öğrenme katsayısı.

## Kısa Tekrar Notları

- XOR doğrusal ayrılabilir değildir; tek katmanlı perseptron çözemez.
- AND eşitsizlikleri çözülebilir: $\theta = 2$, $w_1 = w_2 = 1$.
- Topolojiler: tek katmanlı ileri beslemeli, çok katmanlı ileri beslemeli, recurrent.
- Recurrent ağlar geçmiş bilgiyi saklar; LSTM ne kadar geçmişin tutulacağını ayarlar.
- Hebb: $\Delta w_i = y x_i$, tek geçiş, sınırsız büyüme sorunu.
- Perseptron: $y \ne t$ ise $\Delta w_i = \eta t x_i$; doğrusal ayrılabilir problemi sonlu adımda çözer.
- Epok: bütün örneklerin bir kez gösterilmesi.
- AND, binary giriş: 10 epok; bipolar giriş: 1 epokta öğrenir.
- Adaline / delta kuralı: $\Delta w_i = \alpha (t - y\_in) x_i$; karesel hatanın türevinden çıkar.
- Öğrenme katsayısı çok büyükse yakınsama olmayabilir; $0.1 \le n\alpha \le 1$.
- Madaline (MR1): iki gizli Adaline, sabit $0.5$ çıkış ağırlıkları; XOR'u iki doğruyla ayırır.

## Detaylı Açıklamalar

- Bir perseptronun her eğitim örneği için ürettiği çıktı, $\text{out} = \text{sgn}(w_1 in_1 + w_2 in_2 - \theta)$ biçiminde bir eşitsizliğe dönüşür (ekrandan, 00:15:00). AND kapısının dört satırı yerine konduğunda $\theta > 0$, $w_2 < \theta$, $w_1 < \theta$ ve $w_1 + w_2 \ge \theta$ elde edilir. İki bilinmeyen için dört koşul vardır ve $\theta = 2$, $w_1 = w_2 = 1$ hepsini sağlar ($1 < 2$, $1 + 1 \ge 2$). $\theta = 3$ ve ağırlıklardan biri 2 gibi başka çözümler de vardır. XOR'da ise ikinci ve üçüncü eşitsizlik $w_1, w_2 \ge \theta$ isterken dördüncüsü $w_1 + w_2 < \theta$ ister. $\theta > 0$ iken iki ağırlığın toplamı en az $2\theta$ olacağından dördüncü koşul sağlanamaz. Slayttaki ifadeyle daha karmaşık ağlara, örneğin birçok basit ağı bir araya getiren ya da farklı aktivasyon fonksiyonları kullanan çözümlere ihtiyaç vardır (ekrandan, 00:20:00).
- Bir öğrencinin sorusu üzerine hoca, eşitsizliklerde $<$ ya da $\le$ seçiminin bu problemde önemli olmadığını söyledi. Ayırma doğruları çizilirken eşitsizlikler zaten eşitliğe çevrilir.
- Hebb algoritmasında güncelleme $y x_i$ çarpımıdır: ikisi de pozitifse ya da ikisi de negatifse ağırlık artar, işaretleri farklıysa azalır. Algoritma örnekleri tek bir kez gösterir ve biter. Diğer kurallar ise aynı örnekleri tekrar tekrar gösterir ve bir durma koşulu ister.
- Perseptron kuralında hesaplanan $y$ yerine hedef $t$ kullanılır ve güncelleme yalnız hata olduğunda yapılır. Bu yüzden perseptron hata tabanlı öğrenen bir algoritmadır. Öğrenme katsayısı $\eta$ 0 ile 1 arasında seçilir; 1 seçilirse kural olduğu gibi uygulanır, daha küçük seçilirse ağırlık değişimleri küçülür.
- Binary giriş ve bipolar çıkışlı AND örneğinde ilk örnek $(1, 1, 1)$ için net girdi $0$'dır; $0 \le 0.2$ olduğundan çıkış $0$, hedef $1$ olduğundan hata vardır. $\Delta W = \eta\, t\,(x_1, x_2, 1) = (1, 1, 1)$, yeni ağırlıklar $(1, 1, 1)$ olur (ekrandan, 00:50:00). İkinci örnek $(1, 0, 1)$ için net $2$, çıkış $1$, hedef $-1$; değişim $(-1, 0, -1)$, ağırlıklar $(0, 1, 0)$ olur (ekrandan, 00:55:00). Bu ağırlıklarla ayırma çizgileri $x_2 = 0.2$ ve $x_2 = -0.2$'dir (ekrandan, 01:10:00). Eğitim 10. epokta biter.
  - Ders sonrası not: 10. epok sonundaki ağırlıklar $(w_1, w_2, b) = (2, 3, -4)$ olur (python ile doğrulandı). Hoca ayırma doğrularını "$x_2 = -\tfrac{2}{3}x_1 + \tfrac{7}{5}$ ve $x_2 = -\tfrac{2}{3}x_1 + \tfrac{19}{5}$" diye okudu; $2x_1 + 3x_2 - 4 = \pm 0.2$ eşitliklerinden doğrusu $x_2 = -\tfrac{2}{3}x_1 + \tfrac{7}{5}$ ve $x_2 = -\tfrac{2}{3}x_1 + \tfrac{19}{15}$'tir.
- Bipolar giriş ve çıkışla aynı AND problemi birinci epokta öğrenilir; 2. epokta dört örneğin hiçbirinde ağırlık değişmez ve ağırlıklar $(1, 1, -1)$ kalır (ekrandan, 01:15:00). Hoca bunu sıfırın çarpmada "yutan" eleman olmasıyla açıkladı: $x_i = 0$ olan girişte hedefin değeri güncellemeye hiç yansımaz.
- Karakter tanıma örneğinde 7 harf 3 fontla yazılmıştır. Her harf $7 \times 9$ piksellik ızgarada dolu/boş piksellerle sayısallaştırılır; dolu piksel 1, boş piksel 0 (binary) ya da $-1$ (bipolar) yapılabilir. Böylece 63 girişli, 7 çıkışlı (her harfe bir çıkış) tek katmanlı ileri beslemeli bir ağ elde edilir (ekrandan, 01:20:00).
- Hebb kuralı tek geçişli olduğu için bazı doğrusal ayrılabilir problemleri çözemez. Hocanın gösterdiği üç girişli örnekte (ayırıcı bir doğru değil bir düzlemdir) perseptron problemi 26 epokta çözmüştür. <!-- BELİRSİZ: üç girişli örneğin verileri slaytta, karesi yok. -->
- Adaline delta kuralı, hedefle hesaplanan değer arasındaki farkı girişle çarpar. Öğrenme katsayısı çok büyükse aranan ağırlık değeri atlanabilir ve yakınsama olmayabilir; yavaş öğrenme yakınsamayı kolaylaştırır. AND (binary giriş, bipolar hedef) için $E = \sum_{p=1}^{4} (x_1(p) w_1 + x_2(p) w_2 + w_0 - t(p))^2$ hatasını en aza indiren ağırlıklar $w_1 = w_2 = 1$, $w_0 = -3/2$'dir (ekrandan, 01:35:00). Her örnekte fark $\pm 0.5$, karesi $0.25$ olduğundan toplam karesel hata $1$'dir (python ile doğrulandı). Hoca perseptron ağırlıklarıyla bu hatanın $10/9$ olduğunu, Adaline'ın biraz daha iyi ayırdığını söyledi. <!-- BELİRSİZ: 10/9 değerinin hangi perseptron ağırlıklarından hesaplandığı karede görülmüyor, doğrulanamadı. -->
- Adaline ve perseptron ikili sınıflandırıcıdır, doğrusal karar sınırına sahiptir, iteratiftir ve eşik aktivasyonu kullanır. Fark: perseptron güncellemede sınıf etiketlerini, Adaline ise sürekli tahmin değerlerini kullanır.
- Delta kuralı, toplam karesel hatanın her ağırlığa göre türevinden de elde edilir: $\partial E / \partial w_{IJ} = -2(t_J - y\_in_J)x_I$. Sabit 2 öğrenme katsayısının içine katılır. Böylece her ağırlık hataya katkısı oranında değiştirilir (ekrandan, 01:45:00). Genişletilmiş delta kuralı geri yayılım algoritmasında kullanılacaktır.
- Madaline MR1 ile bipolar XOR örneğinde başlangıç ağırlıkları $w_{11} = 0.05$, $w_{21} = 0.2$, $b_1 = 0.3$, $w_{12} = 0.1$, $w_{22} = 0.2$, $b_2 = 0.15$, sabit $v_1 = v_2 = b_3 = 0.5$, $\alpha = 0.5$'tir. İlk örnek $(1, 1)$, hedef $-1$ için $z\_in_1 = 0.55$, $z\_in_2 = 0.45$, $z_1 = z_2 = 1$, $y\_in = 1.5$, $y = 1$ bulunur; hata vardır (ekrandan, 02:10:00). $Z_1$ için güncelleme sonrası $b_1 = -0.475$, $w_{11} = -0.725$, $w_{21} = -0.575$ olur. Derste eğitimin dört epokta bittiği söylendi. İki gizli birimin oluşturduğu iki doğru, XOR'un çapraz duran artılarını eksilerden ayırır (ekrandan, 02:20:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
