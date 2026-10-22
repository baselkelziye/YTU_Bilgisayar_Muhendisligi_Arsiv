# Ders 11 Çalışma Özeti

## Genel Konular

- Duyuru: kısa sınav
  - Ders günü saat 16:00-16:50 arasında kısa sınav var (50 dakika). Tek bir klasik soru: bir öncül ve ona bağlı a, b, c, d şıkları. Çoktan seçmeli değil.
  - Kapsam: sınav başlayana kadar işlenen bütün konular.
  - Çözümler A4 kağıda (veya tablete) yazılır, fotoğrafı çekilip **tek bir PDF** hâlinde sisteme yüklenir. Dosya 5 MB'ı geçmemeli. E-postayla gönderilen cevap kabul edilmez.
- Tekrar: fazör uzayı
  - Karmaşık sayılar kartezyen, polar ve üstel (eksponansiyel) biçimde yazılabilir. Polar ile üstel biçim arasındaki geçiş Euler formülüyle yapılır.
  - Kaynak fazöre çevrilirken önce kosinüs biçimine getirilir: genlik pozitif, faz açısı $-180°$ ile $+180°$ arasında olmalıdır. Fazör, genlik ve faz açısından oluşur: $V_m\cos(\omega t + \theta) \rightarrow V_m\angle\theta$.
  - Kaynağın frekansı $\omega$ bir kenara not edilir. Sinüzoidal sürekli hâlde devredeki bütün akım ve gerilimler aynı frekanstadır. Değişen yalnızca genlik ve faz açısıdır.
  - Fazör uzayından geri dönerken genlik kosinüsün önüne, not edilen $\omega$ ve fazörün açısı kosinüsün içine yazılır. Bu, karmaşık sayının reel kısmını almak demektir. Derste kosinüs ile çalışılır ve dönüşte reel kısım alınır. Sinüs ile çalışıp sanal kısım almak da mümkündür, önemli olan baştaki anlaşmaya uymaktır.
  - Fazör uzayının avantajı: diferansiyel denklemler doğrusal (cebirsel) denklemlere dönüşür.
- Pasif elemanların fazör uzayındaki tanım bağıntıları
  - Zaman domeninde doğrusal tek eleman dirençtir. Fazör uzayında ise endüktans ve kapasitans da direnç gibi davranır. Fark: değerleri karmaşık sayıdır ve frekansa bağlıdır. Bu değere **empedans** ($Z$) denir.
  - Direnç: $v = Ri$. Fazörde $\mathbf{V} = R\,\mathbf{I}$, akım ve gerilim aynı fazdadır. $Z_R = R$, frekanstan bağımsız.
  - Endüktans: $v = L\frac{di}{dt}$. $i = I_m\cos(\omega t + \theta_2)$ için $v = -\omega L I_m\sin(\omega t + \theta_2) = \omega L I_m\cos(\omega t + \theta_2 + 90°)$.
    - $\frac{\mathbf{V}}{\mathbf{I}} = \omega L\angle 90° = j\omega L$. Yani $Z_L = j\omega L$.
    - Gerilim akımdan $90°$ öndedir.
    - $\omega = 0$ (DC) için $Z_L = 0$: endüktans DC'de kısa devredir. $\omega \to \infty$ için açık devredir.
  - Kapasitans: $i = C\frac{dv}{dt}$. $v = V_m\cos(\omega t + \theta_1)$ için $i = \omega C V_m\cos(\omega t + \theta_1 + 90°)$.
    - $\frac{\mathbf{V}}{\mathbf{I}} = \frac{1}{\omega C}\angle -90° = \frac{1}{j\omega C} = -\frac{j}{\omega C}$. Yani $Z_C = \frac{1}{j\omega C}$.
    - Akım gerilimden $90°$ öndedir.
    - $\omega = 0$ için $Z_C \to \infty$: kapasitans DC'de açık devredir. $\omega \to \infty$ için kısa devredir.
  - Sinüsten kosinüse geçiş: $\sin\alpha = \cos(\alpha - 90°)$. Önündeki eksi işareti içeri almak için açıya $180°$ eklenir: $-\cos\alpha = \cos(\alpha + 180°)$. Hoca türetme sırasında bir an işareti karıştırıp düzeltti. Doğru sonuç yukarıdadır.
  - Hatırlatma ipucu: "endüktans DC'de kısa devre" bilgisinden hangi formülde $\omega = 0$'ın sıfır verdiğine bakarak $Z_L$ ile $Z_C$ karıştırılmaz.
- Fazör uzayında devre çözme adımları
  1. Kaynağı kosinüse çevir, fazörünü yaz, $\omega$'yı not et.
  2. Her pasif eleman için empedansı hesapla.
  3. Devreyi direnç devresi gibi, ama karmaşık sayılarla çöz (KAY, KGY, seri/paralel eşdeğer, Thevenin/Norton, süperpozisyon…).
  4. Bulunan fazörün reel kısmını al, yani zaman domenine dön.
  - Bu yöntem, kaynak devreyi yeterince uzun süre (pratikte 5τ) sürdükten sonra, geçici hâl bittiğinde geçerlidir: sinüzoidal sürekli hâl.
- Empedans ve admitans
  - Ohm kanunu fazör uzayında: bütün pasif elemanlar için $\frac{\mathbf{V}_x}{\mathbf{I}_x} = Z_x$ sabittir (belirli bir frekansta).
  - Admitans: $Y = \frac{1}{Z}$. $Y_R = G = \frac{1}{R}$, $Y_L = \frac{1}{j\omega L} = -\frac{j}{\omega L}$, $Y_C = j\omega C$.
  - Uç değerler: $Z_L$: $\omega = 0$'da $0$, $\omega \to \infty$'da $\infty$. $Z_C$: $\omega = 0$'da $\infty$, $\omega \to \infty$'da $0$. Direnç frekanstan bağımsızdır.
  - Polar-kartezyen dönüşüm: $Z = R + jX$ ise $|Z| = \sqrt{R^2 + X^2}$, $\varphi = \tan^{-1}\frac{X}{R}$. Tersi: $R = |Z|\cos\varphi$, $X = |Z|\sin\varphi$. Admitans için aynısı ($Y = G + jB$).
  - Toplama/çıkarma kartezyen biçimde, çarpma/bölme polar biçimde kolaydır. Sınavda hesap makinesinin polar/kartezyen dönüşüm fonksiyonu kullanılabilir.
- Filtre fikri (giriş)
  - Empedanslar frekansla değiştiği için uygun $L$ ve $C$ seçilerek alçak geçiren, yüksek geçiren, bant geçiren ve çentik (notch) filtreler yapılabilir.
  - Girişten çıkışa paralel (şönt) bağlı bir endüktans: düşük frekansta kısa devre olduğu için $V_{out} \approx 0$, yüksek frekansta açık devre olduğu için $V_{out} \approx V_{in}$. Yüksek frekansları geçirir.
  - Şönt bağlı kapasitans tersini yapar: düşük frekansları geçirir, yüksek frekansları süzer. Motor uçlarına bağlanan seramik kondansatörler yüksek frekanslı gürültüyü bu sayede bastırır.
  - Bode diyagramı konusu son haftaya kalırsa işlenecek.
- Örnek 2: paralel RLC (akım kaynaklı)
  - $i_s(t) = 8\cos(2\pi\cdot 10^6 t + 30°)$ mA. Kaynağa paralel $R = 70\ \Omega$, $L = 10\ \mu$H, $C = 2$ nF. İstenen: uçlardaki $v(t)$.
  - $\mathbf{I}_s = 8\angle 30°$ mA, $\omega = 2\pi\cdot 10^6$ rad/s.
  - $Z_L = j\omega L = j\,2\pi\cdot 10^6\cdot 10\cdot 10^{-6} = j20\pi\ \Omega$. $Z_C = \frac{1}{j\omega C} = \frac{1}{j\,2\pi\cdot 10^6\cdot 2\cdot 10^{-9}} = \frac{250}{j\pi}\ \Omega$.
  - KAY: $\mathbf{I}_s - \frac{\mathbf{V}}{R} - \frac{\mathbf{V}}{j\omega L} - j\omega C\,\mathbf{V} = 0$.
  - Toplam admitans $0.0147\angle -13°$, $\mathbf{V} = \frac{8\angle 30°}{0.0147\angle -13°} = 544\angle 43°$ mV.
  - $v(t) = 544\cos(2\pi\cdot 10^6 t + 43°)$ mV.
  - $\frac{1}{j62.8} = -\frac{j}{62.8} = -0.0159j$ gibi ara adımlarda payda pay ve paydayı $j$ ile çarparak paydadaki $j$'den kurtulunur.
- Seri ve paralel eşdeğer empedans
  - Seri: KGY ile $\mathbf{V}_s = \mathbf{I}(Z_1 + Z_2)$, yani $Z_{eş} = Z_1 + Z_2$.
  - Paralel: KAY ile $\mathbf{I}_s = \frac{\mathbf{V}}{Z_1} + \frac{\mathbf{V}}{Z_2}$, yani $\frac{1}{Z_{eş}} = \frac{1}{Z_1} + \frac{1}{Z_2}$.
  - Admitans kullanılırsa paralel elemanların admitansları toplanır. Direnç ve iletkenlikteki durumun aynısıdır.
  - Pasif elemanlarda gerilim referans yönü, akımın girdiği uç artı olacak şekilde seçilir (eleman enerji tüketir).
- Örnek 3: seri RL
  - $v_1(t) = 12\sin(100t + 30°)$ V, seri $L = 10$ mH ve $R = 10\ \Omega$. İstenen: ana kol akımı.
  - Kosinüse çevirme: $12\sin(100t + 30°) = 12\cos(100t - 60°)$, yani $\mathbf{V}_1 = 12\angle -60°$ V, $\omega = 100$ rad/s.
  - $Z_L = j\cdot 100\cdot 10^{-2} = j\ \Omega$, $Z_{eş} = 10 + j = 10.05\angle 5.71°\ \Omega$ ($\sqrt{101} = 10.05$, $\tan^{-1}0.1 = 5.71°$).
  - $\mathbf{I} = \frac{12\angle -60°}{10.05\angle 5.71°} = 1.19\angle -65.7°$ A, $i(t) = 1.19\cos(100t - 65.7°)$ A.
  - Gerilimin açısı ($-60°$) akımınkinden ($-65.7°$) daha pozitif: gerilim akımdan öndedir (endüktif devre).
- Örnek 4: paralel RCL (akım kaynaklı)
  - $i_1(t) = 4\cos(300t - 10°)$ A, kaynağa paralel $R = 1\ \Omega$, $C = 1$ mF, $L = 1$ H. İstenen: uçlardaki gerilim.
  - $\mathbf{I}_1 = 4\angle -10°$ A, $\omega = 300$ rad/s.
  - $Z_C = \frac{1}{j\cdot 300\cdot 10^{-3}} = \frac{10}{3j} = -3.33j\ \Omega$ (hoca önce $\omega = 100$ yazdı, öğrenci uyarısıyla 300'e düzeltti). $Z_L = j\cdot 300\cdot 1 = 300j\ \Omega$.
  - Slayttaki çözüm: $Y_{eş} = 1 + j0.297 = 1.04\angle 16.5°$, $Z_{eş} = 0.959\angle -16.5°\ \Omega$.
  - Hoca MATLAB ile ($abs$, $angle$, $rad2deg$ fonksiyonları) $Z_{eş} = 0.9569\angle 16.89°$ buldu ve $v = 3.8276\cos(300t + 6.89°)$ V sonucuna ulaştı. Bu sonuç yanlıştır, doğrusu için "Ders sonrası notlar"a bakın.
- Fazörün tam anlamı
  - $A\angle\varphi$ fazörü aslında $A e^{j(\omega t + \varphi)} = A\cos(\omega t + \varphi) + jA\sin(\omega t + \varphi)$ sayısının kısaltmasıdır. $e^{j\omega t}$ çarpanı bütün büyüklüklerde ortak olduğu için yazılmaz. Zaman domenine dönüş bu sayının reel kısmını almaktır.
- Gelecek ders: fazör uzayında Thevenin-Norton eşdeğerleri, gerilim bölücü (seri empedanslar, gerilim empedansla orantılı paylaşılır) ve akım bölücü (paralel empedanslar, akım empedansla ters orantılı paylaşılır), ardından frekans cevabı ve Bode diyagramı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kosinüs biçiminde çalışın, dönüşte reel kısmı alın. Kaynağın frekansını mutlaka not edin.
- $Z_R = R$, $Z_L = j\omega L$, $Z_C = \frac{1}{j\omega C}$. Endüktans DC'de kısa devre, kapasitans DC'de açık devredir.
- Fazör uzayında bütün devre teoremleri (KAY, KGY, eşdeğer, Thevenin-Norton, süperpozisyon) aynen geçerlidir. Devre direnç devresi gibi çözülür.
- Toplama için kartezyen, çarpma/bölme için polar biçim kullanın. Pratik yapın: sinüs/kosinüs ve eksi işaretli kaynakları fazöre çevirme tablosu, empedans hesabı, polar-kartezyen dönüşümleri.
- Kısa sınav cevabı tek PDF, en fazla 5 MB, sisteme yüklenecek.

## Kısa Tekrar Notları

- $Z_R = R$, $Z_L = j\omega L$ (gerilim $90°$ önde), $Z_C = \frac{1}{j\omega C} = -\frac{j}{\omega C}$ (akım $90°$ önde).
- $Y = \frac{1}{Z}$, $Y_C = j\omega C$, $Y_L = -\frac{j}{\omega L}$.
- Seri: $Z_{eş} = \sum Z_k$. Paralel: $Y_{eş} = \sum Y_k$.
- $|Z| = \sqrt{R^2 + X^2}$, $\varphi = \tan^{-1}(X/R)$.
- Örnek 3: $i(t) = 1.19\cos(100t - 65.7°)$ A. Örnek 2: $v(t) = 545\cos(2\pi 10^6 t + 43.2°)$ mV.

## Detaylı Açıklamalar

### Neden fazör uzayında direnç devresi gibi çözebiliyoruz?

- Zaman domeninde $L$ ve $C$ türev ve integral içeren bağıntılara sahip olduğu için devre denklemleri diferansiyel denklemdir. Sinüzoidal sürekli hâlde $\frac{d}{dt}$ işlemi fazörde $j\omega$ ile çarpmaya dönüşür. Böylece her eleman için $\mathbf{V} = Z\mathbf{I}$ biçiminde cebirsel bir bağıntı elde edilir. KAY ve KGY de doğrusal olduğu için bütün sistem karmaşık katsayılı doğrusal denklem takımına dönüşür.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Örnekler ders sonrasında Python ile yeniden hesaplandı. Örnek 2: $|\mathbf{V}| = 545.2$ mV, açı $43.19°$ (slayttaki MATLAB çıktısıyla aynı, slayt metninde 544'e yuvarlanmış). Örnek 3: $Z = 10.05\angle 5.71°$, $\mathbf{I} = 1.194\angle -65.71°$ A. Doğrudur.
- **Örnek 4'teki hata:** $Y_{eş} = \frac{1}{R} + j\omega C + \frac{1}{j\omega L} = 1 + j0.3 - j0.0033 = 1 + j0.2967$. Bu yüzden $Z_{eş} = 0.9587\angle -16.52°\ \Omega$'dur (slayttaki $0.959\angle -16.5°$ doğrudur). Derste MATLAB'a kapasitör terimi ters işaretle girildiği için açı $+16.89°$ çıktı. Doğru sonuç: $\mathbf{V} = \mathbf{I}_1 Z_{eş} = 4\angle -10° \cdot 0.9587\angle -16.52° = 3.835\angle -26.52°$ V, yani $v(t) = 3.835\cos(300t - 26.5°)$ V. Derste önce bölme yapılıp $-26.89°$ bulundu, sonra çarpmaya düzeltilirken açı $+6.89°$ yapıldı. Her iki ara sonuç da yanlıştır. Kapasitif bileşen baskın olduğu için ($\omega C = 0.3 \gg \frac{1}{\omega L} = 0.0033$) gerilim akımdan geride olmalıdır.
- **Admitans tablosundaki birim:** Slayttaki tabloda admitans değerleri "$\infty\ \Omega$", "$0\ \Omega$" diye yazılmış. Admitansın birimi siemens (S, $\Omega^{-1}$)'tir.
- **Mikrofon örneğindeki karışıklık:** Hoca yüksek frekansları süzmenin sesi kalınlaştıracağını söyledi, bu doğrudur (alçak geçiren filtre). Ardından "alçak geçiren filtre uygularsam bas unsurlar sönümlenir, ses ince çıkar" dedi. Bas (düşük frekans) bileşenlerini süzen filtre **yüksek geçiren** filtredir. Alçak geçiren filtre basları geçirir.
- **Şönt eleman varsayımı:** Endüktansın yüksek frekansları geçirdiği yorumu, endüktansın çıkışa paralel (şönt) bağlı olduğu devre için geçerlidir. Endüktans girişle çıkış arasına seri bağlanırsa durum tersine döner: düşük frekansları geçirir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
