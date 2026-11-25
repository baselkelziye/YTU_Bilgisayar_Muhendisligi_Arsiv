# Ders 13 Çalışma Özeti

## Genel Konular

- Fazör uzayına geçişin tekrarı ve doğrusallık
  - Süperpozisyon, devrenin doğrusallığına dayanır. Fazör uzayında kaynak karmaşık bir sayı olur; devre doğrusal kaldığı için reel ve sanal kısımların etkisi ayrı ayrı izlenebilir. Bu yüzden devre karmaşık kaynakla çözülüp sonucun yalnız reel kısmı alınarak zaman boyutuna dönülebilir.
  - $V_m\cos(\omega t+\theta) = \mathrm{Re}\{V_m e^{j(\omega t+\theta)}\} = \mathrm{Re}\{V_m e^{j\omega t}e^{j\theta}\}$; $e^{j\omega t}$ bütün elemanlarda ortaktır, kenara not edilir. Geriye kalan $V_m e^{j\theta} = V_m\angle\theta$ fazördür (ekrandan, 00:10:00).
  - Sinüslü bir kaynak önce kosinüse çevrilir: $\sin\alpha = \cos(90^\circ-\alpha) = \cos(\alpha-90^\circ)$. Faz açısı $-180^\circ$ ile $+180^\circ$ arasında tutulur. İkinci yol: sinüs için sanal kısım alınır; o zaman dönüşte de sanal kısım alınır.
- Eleman bağıntılarının fazör karşılıkları
  - Direnç: $v = Ri$ olduğundan $\mathbf{V} = R\mathbf{I}$; faz kayması yoktur.
  - Kapasite: $v(t) = V_m\cos(\omega t+\theta)$ için $i(t) = C\,dv/dt = -\omega C V_m\sin(\omega t+\theta) = \omega C V_m\cos(\omega t+\theta+90^\circ)$, yani $\mathbf{I} = \omega C V_m\angle(\theta+90^\circ)$ (ekrandan, 00:25:00). Buradan $Z_C = \mathbf{V}/\mathbf{I} = \dfrac{1}{j\omega C} = -\dfrac{j}{\omega C}$. Akım gerilimden $90^\circ$ öndedir.
  - Endüktans: $v = L\,di/dt$, $i(t) = I_m\cos(\omega t+\theta)$ için $\mathbf{V} = \omega L I_m\angle(\theta+90^\circ)$, dolayısıyla $Z_L = j\omega L$. Gerilim akımdan $90^\circ$ öndedir.
  - Dönüşümde kullanılan özdeşlikler: $\sin(180^\circ+\alpha) = -\sin\alpha$, $\cos\beta = \cos(-\beta)$, $\sin\alpha = \cos(90^\circ-\alpha) = \cos(\alpha-90^\circ)$ (birim çember ve dik üçgen üzerinden).
- Empedans ve admitans
  - Empedans, fazör uzayında Ohm yasasından gelen orandır: $Z = \mathbf{V}/\mathbf{I}$. Zaman boyutundaki direncin karşılığıdır (ekrandan, 00:45:00).
  - Kartezyen ve polar biçimler: $Z_R = R = R\angle0^\circ$, $Z_C = -j/(\omega C) = \frac{1}{\omega C}\angle-90^\circ$, $Z_L = j\omega L = \omega L\angle90^\circ$.
  - Tek eleman için empedans ya saf reel (direnç) ya saf sanaldır (kapasite, endüktans). Seri/paralel bağlı elemanların eşdeğer empedansı ise genel bir karmaşık sayıdır: $Z = R + jX$.
  - Admitans, iletkenliğin karşılığıdır: $Y = 1/Z = \mathbf{I}/\mathbf{V}$. $Y_R = 1/R$, $Y_C = j\omega C$, $Y_L = -j/(\omega L)$.
  - $Y = G + jB$ için $G = \dfrac{R}{R^2+X^2}$, $B = \dfrac{-X}{R^2+X^2}$; $|Y| = \sqrt{G^2+B^2}$, $\gamma = \tan^{-1}(B/G)$ (ekrandan, 00:55:00).
  - Sınır davranışı ile sağlama: $\omega\to0$ iken $Z_L\to0$ (kısa devre), $Z_C\to\infty$ (açık devre); $\omega\to\infty$ iken tersi. Ezberden yazılan empedans bu yolla kontrol edilebilir.
- Seri ve paralel bağlama
  - Seri: aynı akım akar, $Z_{\text{eş}} = Z_1 + Z_2 + \dots$
  - Paralel: aynı gerilim düşer, $\dfrac{1}{Z_{\text{eş}}} = \dfrac{1}{Z_1} + \dfrac{1}{Z_2} + \dots$, yani admitanslar toplanır.
  - Özet kural: empedanslar seride, admitanslar paralelde toplanır.
- Sürekli sinüzoidal hal
  - Fazör çözümü geçici hali (transient) değil, devre uzun süre çalıştıktan sonraki sürekli hali verir. Tek kaynak ya da aynı frekanslı kaynaklar varsa devre doğrudan fazörle çözülür; farklı frekanslı kaynaklarda süperpozisyonla her kaynak ayrı çözülür.
  - Kaynak $\sin(2\pi f t)$ biçiminde verilirse $\omega = 2\pi f$ hesaplanmalıdır.
- Thevenin ve Norton eşdeğerleri fazör uzayında
  - Yöntem zaman boyutundakiyle aynıdır, yalnız karmaşık sayılarla çalışılır. $Z_{th}$, bağımsız kaynaklar sıfırlanarak (gerilim kaynağı kısa devre, akım kaynağı açık devre) bulunur; $\mathbf{V}_{th}$ açık devre gerilimidir. $\mathbf{V}_{th} = \mathbf{I}_n Z_n$, $\mathbf{I}_n = \mathbf{V}_{th}/Z_{th}$ (ekrandan, 01:45:00).
  - Bağımlı kaynak varsa açık devre gerilimi ve kısa devre akımı bulunur, $Z_{th} = \mathbf{V}_{oc}/\mathbf{I}_{sc}$.
  - Kaynak dönüşümleri (akım kaynağı + paralel empedans $\leftrightarrow$ gerilim kaynağı + seri empedans) adım adım kullanılabilir.
- Gerilim ve akım bölücü
  - Seri empedanslar gerilimi empedanslarıyla orantılı, paralel empedanslar akımı empedanslarıyla ters orantılı paylaşır; direnç devrelerindekinin aynısıdır.
- Hesap aracı (Octave)
  - `abs(z)` genliği, `angle(z)` açıyı radyan olarak verir; `rad2deg` ile dereceye çevrilir. `exp(j*x)` içine verilen açı radyan olmalıdır, derece verilecekse `deg2rad` kullanılır (ekrandan, 02:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Fazör uzayında diferansiyel denklemler doğrusal (cebirsel) denklemlere dönüşür
  - Her elemanın $\mathbf{V}/\mathbf{I}$ oranı belirli bir $\omega$ için sabittir. Bu yüzden direnç devrelerindeki bütün teknikler (seri/paralel, düğüm, çevre, Thevenin/Norton, bölücüler) karmaşık sayılarla aynen kullanılır.
- $\omega$ not edilmeli
  - Bütün elemanlar kaynak frekansında salınır. Fazör hesabında $\omega$ kenara yazılır, sonuç zaman boyutuna çevrilirken geri eklenir. Reel kısım alınarak gidildiyse sonuç kosinüsle yazılır.
- Sağlama
  - Empedans formülü $\omega\to0$ ve $\omega\to\infty$ sınırlarında elemanın bilinen davranışıyla (açık/kısa devre) kontrol edilmelidir.
- Toplama kartezyende, çarpma/bölme polar biçimde kolaydır
  - Eşdeğer empedans bulunurken kartezyen, bölme yapılırken polar biçim kullanılır.
- Açı birimi
  - Hesap aracına açı verirken radyan/derece karışıklığı sonucu bozar.

## Kısa Tekrar Notları

- $Z_R = R$, $Z_C = 1/(j\omega C) = -j/(\omega C)$, $Z_L = j\omega L$.
- Kapasitede akım $90^\circ$ önde, endüktansta gerilim $90^\circ$ önde.
- $Y = 1/Z$; $Y_C = j\omega C$, $Y_L = -j/(\omega L)$.
- Seri: $Z$'ler toplanır. Paralel: $Y$'ler toplanır.
- Sinüs kaynak: $\sin\alpha = \cos(\alpha-90^\circ)$; eksi işareti: $-\cos\alpha = \cos(\alpha\pm180^\circ)$.
- Seri RL örneği: $12\sin(100t+30^\circ)$ V, $10\ \Omega$, $10$ mH $\Rightarrow$ $i(t) = 1.19\cos(100t-65.71^\circ)$ A.
- Paralel RLC örneği: $4\cos(300t-10^\circ)$ A, $1\ \Omega$, $1$ mF, $1$ H $\Rightarrow$ $v(t) \approx 3.84\cos(300t-26.5^\circ)$ V.
- Paralel bağlı $j100$ ve $-j100$ empedanslarının eşdeğeri sonsuzdur (açık devre).
- Thevenin: $Z_{th}$ kaynaklar sıfırlanarak, $\mathbf{V}_{th}$ açık devre gerilimiyle; bağımlı kaynakta $Z_{th} = \mathbf{V}_{oc}/\mathbf{I}_{sc}$.
- Octave'da `angle` radyan döndürür; `exp(j*θ)` içine radyan verilir.

## Detaylı Açıklamalar

- Ders, fazör kavramının tekrarıyla başladı. Sinüzoidal bir kaynak, Euler formülüyle karmaşık bir üstelin reel kısmı olarak yazılır. Devre bu karmaşık kaynakla çözülür, her iki tarafın reel kısmı alınır ve "reel kısmı alma" işlemi içeri dağıtılabildiği için sonuç doğrudan zaman boyutuna döner. Bütün elemanlar aynı $e^{j\omega t}$ çarpanını taşıdığından bu çarpan paranteze alınır; geriye genlik ve açıdan oluşan fazör kalır. Fazör, karmaşık düzlemde orijine uzaklık (genlik) ve reel eksenle yapılan açı ile gösterilen sayıdır.
- Kapasite için türetme ekranda adım adım yapıldı (ekrandan, 00:25:00): $q(t) = Cv(t)$, $i(t) = C\,dv/dt$. $v(t) = V_m\cos(\omega t+\theta)$ ise $i(t) = -CV_m\omega\sin(\omega t+\theta)$. Eksi işareti $180^\circ$ eklenerek atılır: $CV_m\omega\sin(\omega t+\theta+180^\circ)$. Sinüs kosinüse çevrilir: $CV_m\omega\cos(90^\circ-(\omega t+\theta+180^\circ)) = CV_m\omega\cos(\omega t+\theta+180^\circ-90^\circ) = CV_m\omega\cos(\omega t+\theta+90^\circ)$. Fazör: $CV_m\omega\angle(\theta+90^\circ)$. Gerilim fazörü $V_m\angle\theta$ ile oranlandığında $Z_C = \dfrac{1}{\omega C}\cdot\dfrac{1}{1\angle90^\circ} = \dfrac{1}{j\omega C}$ bulunur. Pay ve payda $j$ ile genişletilirse $j^2 = -1$ olduğundan $Z_C = -j/(\omega C)$ olur.
- Endüktans için aynı işlem yapıldı: $\phi = Li$, $v = L\,di/dt$. $i(t) = I_m\cos(\omega t+\theta)$ için $v(t) = -LI_m\omega\sin(\omega t+\theta) = LI_m\omega\cos(\omega t+\theta+90^\circ)$, dolayısıyla $Z_L = \omega L\angle90^\circ = j\omega L$.
- Sağlama örneği olarak bir kaynak, seri direnç ve ölçülen bir kapasite/endüktans düşünüldü. Kapasitede $\omega\to0$ iken $1/(j\omega C)\to\infty$ (açık devre, kaynak gerilimi aynen görülür), $\omega\to\infty$ iken $0$ (kısa devre, sıfır görülür). Endüktansta $\omega = 0$ için $Z_L = 0$ (DC'de kısa devre) çıkar.
- Seri RL örneği (ekrandan, 01:20:00 ve 01:30:00): $v_1 = 12\sin(100t+30^\circ)$ V, $L_1 = 10$ mH, $R_1 = 10\ \Omega$. $\omega = 100$ rad/s. Kaynak: $12\cos(100t+30^\circ-90^\circ) = 12\cos(100t-60^\circ)$, yani $\mathbf{V}_1 = 12\angle-60^\circ$. $Z_L = j(100)(10\cdot10^{-3}) = j\ \Omega$, $Z_{\text{eş}} = 10 + j = 10.05\angle5.71^\circ\ \Omega$. $\mathbf{I} = 12\angle-60^\circ / 10.05\angle5.71^\circ = 1.19\angle-65.71^\circ$ A, $i(t) = 1.19\cos(100t-65.71^\circ)$ A. $\mathbf{V}_L = \mathbf{I}\cdot1\angle90^\circ = 1.19\angle24.29^\circ$ V, $v_L(t) = 1.19\cos(100t+24.29^\circ)$ V. $\mathbf{V}_R = 10\,\mathbf{I} = 11.9\angle-65.71^\circ$ V, $v_R(t) = 11.9\cos(100t-65.71^\circ)$ V. Sonuçlar python ile doğrulandı.
- Paralel RLC örneği (ekrandan, 01:35:00 ve 01:40:00): akım kaynağı $4\cos(300t-10^\circ)$ A, $R = 1\ \Omega$, $C = 1$ mF, $L = 1$ H, hepsi aynı iki düğüm arasında. $Z_R = 1$, $Z_C = 1/(j\cdot300\cdot10^{-3}) = -j3.33 = 3.33\angle-90^\circ$, $Z_L = j300 = 300\angle90^\circ$. Düğüm denklemi: $4\angle-10^\circ = \mathbf{V}\left(1 + j0.3 - j0.00333\right)$.
  - Ders sonrası not: Hoca parantezi $1 + 0.27j$ diye yazdı ve $\mathbf{V} = 3.88\angle-25.11^\circ$ V buldu; doğrusu $1 + 0.2967j = 1.043\angle16.52^\circ$ olduğundan $\mathbf{V} = 3.84\angle-26.52^\circ$ V'tur. Slayttaki sonuç ($3.84\angle-26.5^\circ$) bununla uyuşur; hoca da farkı fark etti ve yuvarlamaya bağladı. Doğru değerlerle (python): $v(t) = i_R(t) = 3.84\cos(300t-26.52^\circ)$, $i_C(t) = 1.15\cos(300t+63.48^\circ)$ A, $i_L(t) = 12.8\cos(300t-116.52^\circ)$ mA.
- Thevenin örneği (ekrandan, 01:50:00): $i_1 = 5\sin(400t+50^\circ)$ mA, $C_1 = 1\ \mu$F, $R_1 = 3$ k$\Omega$, $L_1 = 0.3$ H, $L_2 = 2$ H, $R_2 = 5$ k$\Omega$, yük $C_2 = 0.7\ \mu$F. $\mathbf{I}_1 = 5\angle-40^\circ$ mA. Empedanslar: $Z_{C1} = -j2500$, $Z_{L1} = j120$, $Z_{L2} = j800$, $Z_{C2} = -j3571\ \Omega$. Kaynak sıfırlanınca $Z_{th} = \big[((Z_{C1}+Z_{R1})\parallel Z_{L1}) + Z_{L2}\big]\parallel Z_{R2} = 906\angle79.4^\circ\ \Omega$.
  - Ders sonrası not: Slayttaki kaynak dönüşümünde $\mathbf{I}_1 Z_{C1}$ çarpımı $7.5\angle-130^\circ$ V yazılmıştı; derste bir öğrencinin uyarısıyla doğrusunun $12.5\angle-130^\circ$ V olduğu görüldü. Slayttaki sonraki sonuçlar bu yüzden hatalıdır. Python ile doğru değerler: $\mathbf{V}_{th} = 0.385\angle-12.0^\circ$ V, $\mathbf{I}_n = 0.425\angle-91.4^\circ$ mA, $\mathbf{I}_{C2} = 143\angle74.4^\circ\ \mu$A, $\mathbf{V}_{C2} = 0.512\angle-15.6^\circ$ V.
- Norton örneği (ekrandan, 02:15:00): $v_1 = \sin(1000t)$ V, seri $L_1 = 0.1$ H, ardından paralel $C_1 = 10\ \mu$F ve yük $R_1 = 1$ k$\Omega$. $Z_L = j100$, $Z_C = -j100$. Kaynak sıfırlanınca $j100 \parallel -j100$: $1/Z_{th} = 1/(j100) - 1/(j100) = 0$, yani $Z_{th}\to\infty$; Norton eşdeğeri yalnız bir akım kaynağıdır. Kaynak dönüşümüyle $\mathbf{I}_n = 1\angle-90^\circ/100\angle90^\circ = 0.01\angle-180^\circ$ A.
  - Ders sonrası not: Hoca önce $Z_{th} = 0$ dedi, bir öğrencinin uyarısıyla sonsuz olduğunu düzeltti. Ayrıca $0.01\angle-180^\circ$ A, zaman boyutunda $-10\cos(1000t)$ mA'dir; slayttaki "$10$ mA $\sin(1000t)$" ifadesine ekrandaki trigonometrik dönüşümle varılamaz, büyük olasılıkla slayttaki ifade faz bakımından hatalıdır.
- Bağımlı kaynaklı iki kaynaklı örnek (ekrandan, 02:30:00): $\omega = 250$; $20\angle0^\circ$ V kaynak, seri $8\ \Omega$ ve $36$ mH ($j9$), düğüm $a$'da $0.25$ mF ($-j16$) ve $1.2\angle45^\circ$ A akım kaynağı, $80$ mH ($j20$) üzerinden $4\mathbf{V}_a$ bağımlı gerilim kaynağı. Düğüm denklemi: $\dfrac{\mathbf{V}_a-20}{8+j9} + \dfrac{\mathbf{V}_a}{-j16} - 1.2\angle45^\circ + \dfrac{\mathbf{V}_a-4\mathbf{V}_a}{j20} = 0$.
  - Ders sonrası not: Hocanın Octave ile bulduğu sonuç doğru değildir: $45^\circ$ açı radyan olarak girildi (sağ taraf $1.734 - j0.220$ çıktı; doğrusu $1.952 - j0.393$) ve çıktıdaki `angle` değeri (0.7253 rad) genlik gibi okundu. Python ile doğru çözüm: $\mathbf{V}_a = 12.43\angle-81.24^\circ$ V, $v_a(t) = 12.43\cos(250t-81.24^\circ)$ V.
- Bağımlı kaynaklı Thevenin örneği (ekrandan, 02:45:00): $10\angle30^\circ$ V kaynak, $30\ \Omega$, $5\mathbf{I}_a$ bağımlı gerilim kaynağı, $-j25$ kapasite, $50\ \Omega$ çıkış. Açık devrede $50\ \Omega$'dan akım geçmez: $30\mathbf{I}_a - 5\mathbf{I}_a - j25\mathbf{I}_a = 10\angle30^\circ$, $\mathbf{I}_a = 10\angle30^\circ/(25-j25) = 0.2828\angle75^\circ$ A, $\mathbf{V}_{oc} = -j25\,\mathbf{I}_a = 7.071\angle-15^\circ$ V. Kısa devrede iki çevre denklemi kurulur ($\mathbf{I}_a = \mathbf{I}_1 - \mathbf{I}_{sc}$), $Z_{th} = \mathbf{V}_{oc}/\mathbf{I}_{sc}$. Derste sayısal olarak bitirilmedi; python ile $\mathbf{I}_{sc} = 0.106\angle-2.0^\circ$ A, $Z_{th} = 65 - j15 = 66.7\angle-13.0^\circ\ \Omega$ bulundu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
