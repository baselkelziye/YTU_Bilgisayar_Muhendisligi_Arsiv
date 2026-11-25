# Ders 3 Çalışma Özeti

## Genel Konular

- Tek çevrimli (single-loop) devreler
  - Tek gözlü devrede bütün elemanlardan aynı akım geçer. Çözüm için önce bilinmeyen akımın referans yönü, sonra her direncin gerilim referansı seçilir, ardından tek kapalı yola Kirchhoff gerilimler kanunu (KVL) uygulanır.
  - Örnek (ekrandan, 00:25:00): $-v_{s1} + v_{R1} + v_{s2} + v_{R2} = 0$, $v_{R1}=R_1 i$, $v_{R2}=R_2 i$ ise $i = \dfrac{v_{s1}-v_{s2}}{R_1+R_2}$.
  - Cebirsel çözümde akım negatif çıkarsa akım seçilen yönün tersine akıyordur; yön değiştirmeden negatif değer kullanılır.
  - Kapalı bir sistemde üretilen ve tüketilen güçlerin toplamı sıfırdır; bu, bilinmeyen bir elemanın gücünü bulmak için kullanılabilir.
- Bağımlı kaynaklı tek çevrim örneği (ekrandan, 00:35:00)
  - 120 V kaynak, 30 Ω, gerilim kontrollü gerilim kaynağı $2v_A$ ve 15 Ω seri. KVL: $-120 + v_{30} + 2v_A - v_A = 0$, $v_{30}=30i$, $v_A=-15i$, buradan $i = 8$ A.
  - Güçler: $p_{120V}=-960$ W, $p_{30\Omega}=1920$ W, $p_{dep}=-1920$ W, $p_{15\Omega}=960$ W; toplam sıfır.
- Tek düğüm çiftli (single-node-pair) devreler
  - Bir kablo boyunca bir sonraki elemana kadar olan her nokta aynı düğümdür. Düğümlerden biri referans (0 V) seçilir; genelde en büyük kaynağın eksi ucu tercih edilir.
  - Bütün elemanlar aynı iki düğümü paylaştığı için gerilimleri eşittir; Kirchhoff akımlar kanunu (KCL) ile tek bilinmeyen $v$ bulunur.
  - Örnek (ekrandan, 00:45:00): 120 A, $\tfrac{1}{30}\,\Omega$, 30 A, $\tfrac{1}{15}\,\Omega$ paralel. $-120 + 30v + 30 + 15v = 0 \Rightarrow v = 2$ V, $i_1=60$ A, $i_2=30$ A. 120 A kaynak $-240$ W (güç veriyor), 30 A kaynak $+60$ W (güç çekiyor).
  - Bağımlı kaynaklı örnek (ekrandan, 00:50:00): $5.6 - \tfrac{v_x}{18} + 0.1v_x - \tfrac{v_x}{9} - 2 = 0 \Rightarrow v_x = 54$ V; $i_A=3$ A, $i_B=-5.4$ A, $i_C=6$ A.
- Seri ve paralel bağlantı
  - Seri: aynı akımı taşıyan, yalnız ikisinin paylaştığı ortak bir düğümü olan elemanlar. Düğüm üçüncü bir elemanla paylaşılıyorsa serilik yoktur.
  - Paralel: aynı gerilimi taşıyan, her iki ucu da ortak iki düğüme bağlı elemanlar. Gösterim: $R_1 \parallel R_2$.
  - Bir alt devre bloğu tek bir iki uçlu eleman gibi düşünülerek (A, B, C grupları) karmaşık devrelerin seri-paralel yapısı adım adım yazılır.
  - Kısa devre ile uçları birleştirilen direnç üzerinde gerilim ve akım yoktur; devreden çıkarılmış gibi düşünülür. Hiçbir yere bağlı olmayan kablo uzantısı topolojiyi değiştirmez.
  - Yalnız iki eleman kaldığında "seri" ve "paralel" ifadesi bakılan uçlara göre değişir.
- Kaynakların birleştirilmesi
  - Seri gerilim kaynakları referans yönlerine göre cebirsel toplanarak tek kaynağa indirgenir. Tek çevrimde kaynakların yeri değiştirilebilir; ana kol akımı değişmez.
  - Örnek (ekrandan, 01:30:00): 9 V, 3 V, 5 V, 1 V kaynaklı, 100 Ω ve 220 Ω'luk tek çevrim; eşdeğer kaynak 16 V, $i = 16/320 = 50$ mA.
  - Farklı değerli ideal gerilim kaynakları paralel bağlanamaz; gerçek kaynaklarda iç dirençler üzerinden dolaşan bir akım oluşur.
  - Paralel akım kaynakları yönlerine göre cebirsel toplanır. Örnek (ekrandan, 01:35:00): 2.5 A yukarı, 2.5 A aşağı, 3 A aşağı ve iki 5 Ω; eşdeğer yukarı yönlü $-3$ A ya da aşağı yönlü 3 A, $v = -7.5$ V.
  - Seri piller: dört 1.5 V AAA pil seri bağlanınca 6 V elde edilir; maksimum akım aynı kalır, kullanılabilir güç 4 katına çıkar (ekrandan, 01:25:00).
- Seri ve paralel dirençler
  - Seri: $R_{eq} = \sum_{i=1}^{N} R_i$ (KVL ile türetildi). Paralel: $\dfrac{1}{R_{eq}} = \sum_{i=1}^{N} \dfrac{1}{R_i}$ (KCL ile türetildi).
  - Eşdeğer direnç bakılan uç çiftine bağlıdır: aynı devre farklı uçlardan farklı $R_{eq}$ verir.
  - Direnç renk kodu (4 bantlı): ilk iki bant iki basamaklı sayıyı, üçüncü bant $10^n$ çarpanını, dördüncü bant toleransı verir. Kahverengi-kırmızı-yeşil $= 12 \times 10^5 = 1.2$ MΩ; 1 kΩ = kahverengi-siyah-kırmızı; 10 kΩ = kahverengi-siyah-turuncu.
  - Direnç yönsüzdür; ohmmetre probları ters bağlansa da 10 Ω + 30 Ω + 100 Ω seri dizi 140 Ω okunur (ekrandan, 01:45:00).
  - Ohmmetre canlı (enerjili) devreye bağlanmaz; örnek: 1 kΩ, 2.2 kΩ ve 1.2 kΩ paralel $R_T = 437.1$ Ω (ekrandan, 02:00:00).
  - Güç dağılımı: seride $P = I^2R$, büyük direnç daha çok güç harcar; paralelde $P = V^2/R$, küçük direnç daha çok güç harcar. Kaynağın verdiği güç dirençlerde harcanan güçlerin toplamıdır.
- İletkenlik ve dualite
  - $G = 1/R$. Seri iletkenlikler: $\dfrac{1}{G_{eq}} = \sum \dfrac{1}{G_i}$; paralel iletkenlikler: $G_{eq} = \sum G_i$. Paralel dirençle seri iletkenlik, seri dirençle paralel iletkenlik aynı biçimdedir (dualite). Güç $P = V^2 G$ biçiminde de yazılabilir.
- Gerilim bölücü
  - Seri dirençler gerilimi direnç değerleriyle doğru orantılı paylaşır: $V_k = \dfrac{R_k}{\sum R} V$.
  - Ölçüm örneği (ekrandan, 02:30:00): 8.4 V kaynak, 10 Ω, 30 Ω, 100 Ω; okunan 0.6 V, 1.8 V ve ters bağlı voltmetrede $-6$ V. $V_3 = 6$ V, toplam 8.4 V; her $V/R = 0.06$ A ana kol akımıdır.
  - AC kaynakta da geçerlidir (ekrandan, 02:35:00): $20\sin(377t)$ V, 3 kΩ ve 4 kΩ; $V_1 = 8.57\sin(377t)$ V, $V_2 = 11.4\sin(377t)$ V.
- Akım bölücü
  - Paralel kollarda akım dirençle ters orantılı paylaşılır; iki direnç için $I_1 = \dfrac{R_{eq}}{R_1+R_{eq}} I_{in}$ (ekrandan, 02:40:00).
  - Örnek (ekrandan, 02:45:00): 12 V, 1 kΩ ∥ 3 kΩ $= 750$ Ω, ana kol 16 mA, kol akımları 12 mA ve 4 mA. Ampermetre kola seri bağlanır, ideal ampermetre kısa devre gibidir.
- Y-Δ (T-π) dönüşümü ve köprü devresi
  - Üç uçlu Y ve Δ yapılar, her uç çifti arasından (üçüncü uç boşta) görülen dirençler eşitse eşdeğerdir; üç denklem, üç bilinmeyen.
  - Formüller (ekrandan, 02:55:00): $R_1=\dfrac{R_bR_c}{R_a+R_b+R_c}$, $R_2=\dfrac{R_aR_c}{R_a+R_b+R_c}$, $R_3=\dfrac{R_aR_b}{R_a+R_b+R_c}$; $R_a=\dfrac{R_1R_2+R_2R_3+R_3R_1}{R_1}$ vb. Eşit dirençlerde $R_\Delta = 3R_Y$.
  - Y bağlantısı üç fazlı AC motor beslemesinde kullanılır; dengeli 120° fazlı beslemede yıldız noktası sanal sıfır olur, dördüncü kabloya gerek kalmaz.
  - Köprü devresi, sırt sırta iki Δ (ya da iki Y) olarak görülebilir; çapraz dirençler ortam koşullarından aynı biçimde etkilendiği için hassas ölçüm ve sensör yapılarında kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Referans yönleri bir kez sabitlenir, sonra cebirsel çözüm yapılır
  - Çıkan değer negatifse yön değiştirilmez; "verilen yönde negatif akım" olarak yorumlanır.
- Güç işareti ile kontrol
  - Direncin gücü her zaman pozitif çıkmalıdır; $I^2R$ ile hesap yön hatasını engeller. Akım kaynağı da güç çekebilir (30 A kaynak +60 W).
- Bağımlı akım kaynağının kol akımı
  - Koldaki akım yalnız bağımlı kaynak tarafından belirlenir; tanımlanan kol akımı kaynağın okuna ters yöndeyse $i_B = -0.1v_x$ yazılır.
- Eşdeğerlik bakılan uçlara bağlıdır
  - Aynı devrede farklı uç çifti seçmek kimin kime seri/paralel olduğunu ve $R_{eq}$'yu değiştirir.
- Ölçümde işaretler
  - Voltmetre ya da ampermetre referans yönüne ters bağlanırsa aynı büyüklük eksi işaretle okunur.
  - Ohmmetre enerjili devreye bağlanmaz; kaynak bağlıysa iç direnci de ölçüme girer.

## Kısa Tekrar Notları

- Tek çevrim: tek akım, KVL. Tek düğüm çifti: tek gerilim, KCL.
- Seri: yalnız iki elemanca paylaşılan ortak düğüm, aynı akım. Paralel: iki ortak düğüm, aynı gerilim.
- Seri gerilim kaynakları ve paralel akım kaynakları yönlerine göre toplanır.
- $R_{seri} = \sum R_i$, $1/R_{paralel} = \sum 1/R_i$; iki eşit direnç paralelse $R/2$.
- Aynı değerli dirençler: seride sayı arttıkça $R_{eq}$ artar, paralelde azalır.
- Gerilim bölücü: $V_k = V\,R_k/R_{top}$. Akım bölücü: akım dirençle ters orantılı.
- 4 bant renk kodu: iki basamak + $10^n$ çarpan + tolerans.
- Y-Δ: eşit dirençte $R_\Delta = 3R_Y$.

## Detaylı Açıklamalar

- Tek çevrimli devrede bilinmeyen sayısı ilk bakışta fazla görünür ($v_{R1}$, $v_{R2}$, $i$), ama Ohm yasası her direnç gerilimini aynı $i$ cinsinden yazdırır ve tek denklem tek bilinmeyene iner. Bağımlı kaynaklı örnekte de $v_{30}=30i$ ve $v_A=-15i$ yazılarak $-120+30i-30i+15i=0$, yani $i=8$ A bulunur. $v_A$'nın eksi işaretli olması, 15 Ω'luk direncin gerilim referansının akım yönüne ters tanımlanmasından gelir.
- Tek düğüm çiftli devrede bir direncin akımı $v/R$, iletkenlikle $Gv$'dir. $\tfrac{1}{30}\,\Omega$ dirençte akım $30v$, $\tfrac{1}{15}\,\Omega$ dirençte $15v$ olur. Sağlama için kaynak akımı kol akımlarının toplamına eşitlenir: $5.6 = 3 - 5.4 + 6 + 2$.
- Seri/paralel analizinde bir grup tek bir "fasulye elemanı" gibi düşünülür. Örneğin 60 V kaynak ile 8 Ω seri ise bu ikili tek bir eleman olur ve bu eleman 10 Ω ile iki ortak düğüm paylaşıyorsa ona paraleldir. <!-- BELİRSİZ: 00:55-00:59 arasındaki iki devrenin (60 V, 8 Ω, 10 Ω, 2 Ω, i_x kaynağı; 40 Ω, 20 Ω, 50 Ω, 125 Ω, 120 mA) tam şeması karelerde yok. -->
- Kısa devreli örnekte (ekrandan, 01:00:00) 2 Ω'luk direncin iki ucu bir kabloyla birleştirildiği için orta düğümler tek düğüm olur. Sol taraftaki 2 A kaynak ile 1.5 Ω seri kol 4 Ω'a paraleldir; sağdaki 5 A kaynak ile 5 Ω seri kol diğer 4 Ω'a paraleldir. Kısa devre yüzünden iki grup da aynı iki düğümü paylaşır ve birbirine paralel olur.
- Kaynak birleştirmede örnek (a) için KVL $-3-9+100i-5+1+220i=0$ (ekrandan, 01:30:00); kaynaklar toplanınca $-16+320i=0$, $i=50$ mA. Eşdeğer kaynak yalnız ana kol akımı ve direnç güçleri için geçerlidir; her kaynağın tek tek gücü için orijinal devreye dönülür.
- Paralel dirençlerde güç direnç değeriyle ters orantılıdır, çünkü akım düşük dirençli kolu tercih eder.
- Gerilim bölücü ölçüm örneğinde ters bağlı voltmetre $-6$ V okur; KVL $-8.4+0.6+1.8+6=0$ ile sağlanır.
- Y-Δ eşdeğerliğinde AB uçlarından bakılırken C boştadır; Y'de $R_1+R_2$, Δ'da $R_c \parallel (R_a+R_b)$ görülür. Diğer iki uç çifti için de benzer denklemler yazılarak dönüşüm formülleri elde edilir.
- Ders sonrası not: Hoca seri devrede direnç gücünün "direncin karesiyle orantılı" arttığını söyledi; doğrusu, akım ortak olduğu için $P = I^2R$ direnç değeriyle doğru (doğrusal) orantılıdır.
- Ders sonrası not: Hoca seri iletkenliklerin ve paralel dirençlerin eşdeğerinin "geometrik ortalama" ile bulunduğunu söyledi; doğrusu terslerin toplamıdır: $1/G_{eq} = \sum 1/G_i$, $1/R_{eq} = \sum 1/R_i$.
- Ders sonrası not: AC gerilim bölücü örneğinde hoca dirençleri bir yerde "4K ve 7K" diye andı; slayttaki dirençler 3 kΩ ve 4 kΩ, toplam 7 kΩ'dur.
- Ders sonrası not: Y-Δ slaytındaki çizimde $R_c$ A-B, $R_a$ A-C, $R_b$ B-C arasındadır. Bu etiketlemeyle (python ile kontrol edildi) $R_1 = R_aR_c/\Sigma$ ve $R_2 = R_bR_c/\Sigma$ çıkar; formül slaytında $R_1$ ile $R_2$ yer değiştirmiş görünür. Formül slaytı büyük olasılıkla $R_a$'nın A ucunun karşısında olduğu bir etiketlemeye göredir. Kural: Y direnci, o uca bitişik iki Δ direncinin çarpımı bölü toplamdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
