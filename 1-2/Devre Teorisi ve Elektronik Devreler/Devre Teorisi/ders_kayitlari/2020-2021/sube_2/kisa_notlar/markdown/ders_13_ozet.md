# Ders 13 Çalışma Özeti

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## Genel Konular

- Kaynaksız RC devreleri: örnek çözümleri
  - Yöntem: önce kondansatörün başlangıç gerilimi $v_C(0)$ bulunur, sonra kondansatör uçlarından görülen eşdeğer direnç $R_{eq}$ hesaplanır, $\tau = R_{eq}C$ ve $v_C(t) = v_C(0)\,e^{-t/\tau}$ yazılır.
  - Örnek: $5\,\Omega$, $0.1\,\text{F}$, $8\,\Omega$ ve $12\,\Omega$ içeren devrede $v_C(0)=15\,\text{V}$ verilmiş. $R_{eq} = \frac{20\cdot 5}{20+5} = 4\,\Omega$, $\tau = 0.4\,\text{s}$, $v_C = 15e^{-2.5t}\,\text{V}$ (ekrandan, 00:13:57). Gerilim bölücüyle $v_x = 9e^{-2.5t}\,\text{V}$, $i_x = 0.75e^{-2.5t}\,\text{A}$.
  - Örnek: $12\,\Omega$, $6\,\Omega$, $8\,\Omega$, $\tfrac13\,\text{F}$ ve $v_C(0)=60\,\text{V}$. $12\parallel 6 = 4$, $4+8=12\,\Omega$, $\tau = 4\,\text{s}$. Sonuç $v_C = 60e^{-0.25t}\,\text{V}$, $v_x = 20e^{-0.25t}\,\text{V}$, $i_o = -5e^{-0.25t}\,\text{A}$ (ekrandan, 00:18:57).
  - Başlangıç gerilimi verilmediğinde $t<0$ için kondansatör açık devre sayılır; kondansatör kaynak gerilimine değil, paralel olduğu direncin gerilimine şarj olur. Örnek: 20 V kaynak, $3\,\Omega$ ve $9\,\Omega$ ile $v(0) = 15\,\text{V}$; anahtar açılınca $R_{eq}=10\,\Omega$, $C = 20\,\text{mF}$, $\tau=0.2\,\text{s}$, $v = 15e^{-5t}\,\text{V}$, $w_C(0) = \tfrac12 C v^2 = 2.25\,\text{J}$.
    <!-- BELİRSİZ: Bu örneğin karesi yok; değerler altyazıdan ve sonuçların tutarlılığından alındı, devre topolojisi doğrulanamadı. -->
  - Örnek: 24 V, $6\,\Omega$, anahtar, $\tfrac16\,\text{F}$, $12\,\Omega$, $4\,\Omega$. $v(0) = 24\cdot\frac{3}{9} = 8\,\text{V}$, $R_{eq}=3\,\Omega$, $\tau = 0.5\,\text{s}$, $v(t) = 8e^{-2t}\,\text{V}$, $w_C(0) = 5.333\,\text{J}$ (ekrandan, 00:28:57).
- Kaynaksız RL devreleri ve bağımlı kaynak
  - RL devresinde $\tau = L/R_{eq}$, $i(t) = i(0)\,e^{-t/\tau}$. $t<0$ için DC'de bobin kısa devre sayılır.
  - Bağımlı kaynak varsa $R_{eq}$ normal seri/paralel indirgemeyle bulunamaz. İki yol vardır:
    - Yöntem 1: bobin yerine $v_o = 1\,\text{V}$ test kaynağı konur, çevre (mesh) denklemleriyle akım bulunur, $R_{eq} = v_o/i_o$.
    - Yöntem 2: bobin gerilimi $L\,di/dt$ doğrudan KVL denklemine yazılır, çıkan birinci dereceden diferansiyel denklem integral alınarak çözülür.
  - Örnek ($0.5\,\text{H}$, $2\,\Omega$, $4\,\Omega$, bağımlı kaynak $3i$, $i(0)=10\,\text{A}$): $i_1=-3\,\text{A}$, $i_o=3\,\text{A}$, $R_{eq}=\tfrac13\,\Omega$, $\tau = 1.5\,\text{s}$, $i(t) = 10e^{-2t/3}\,\text{A}$ (ekrandan, 00:33:57 ve 00:38:57).
  - Örnek ($2\,\text{H}$, $1\,\Omega$, $2\,\Omega$, $6\,\Omega$, bağımlı kaynak $2v_x$, $i(0)=12\,\text{A}$): $i = 12e^{-2t}\,\text{A}$, $v_x = -12e^{-2t}\,\text{V}$ (ekrandan, 00:43:57).
  - Örnek (40 V, $2\,\Omega$, $4\,\Omega$, $12\,\Omega$, $16\,\Omega$, $2\,\text{H}$): $i(0)=6\,\text{A}$, $R_{eq} = 16\parallel 16 = 8\,\Omega$, $i(t) = 6e^{-4t}\,\text{A}$ (ekrandan, 00:53:57).
  - Örnek (15 A, $24\,\Omega$, $12\,\Omega$, $8\,\Omega$, $5\,\Omega$, $2\,\text{H}$): $i(0) = 5\,\text{A}$, $R_{eq} = 20\parallel 5 = 4\,\Omega$, $i(t) = 5e^{-2t}\,\text{A}$ (ekrandan, 00:58:57).
  - Örnek (10 V, anahtar $t=0$'da kapanıyor, $2\,\text{H}$, $3\,\Omega$, $6\,\Omega$): $i(0)=2\,\text{A}$, $R_{eq}=3\parallel 6=2\,\Omega$, $\tau=1\,\text{s}$, $i = 2e^{-t}\,\text{A}$, $v_o = 4e^{-t}\,\text{V}$, $i_o = -\tfrac23 e^{-t}\,\text{A}$ (ekrandan, 01:08:57).
- Tekillik (singularity) fonksiyonlarıyla sinyal ifade etme
  - Birim basamak $u(t)$, rampa $r(t)$ ve darbe (impulse) $\delta(t)$ üst üste bindirilerek parçalı sinyaller yazılır.
  - 2 ile 5 saniye arasında 10 birimlik darbe: $10u(t-2) - 10u(t-5)$; türevi $t=2$ ve $t=5$'te darbelerdir.
  - Akım darbesi $10[u(t) - 2u(t-2) + u(t-4)]$, integrali $10[r(t) - 2r(t-2) + r(t-4)]$, tepe değeri $t=2$'de 20 (ekrandan, 01:13:57).
  - Testere dişi (sawtooth): $5r(t) - 5r(t-2) - 10u(t-2)$.
  - $i(t) = 2u(t) - 2r(t) + 4r(t-2) - 2r(t-3)\,\text{A}$ (ekrandan, 01:18:57).
- Fazörlerle AC devre çözümü
  - $j\omega L$ ve $-j/(\omega C)$ ile elemanlar empedansa çevrilir, kaynaklar fazöre geçirilir; sonra KCL/KVL, düğüm ve çevre yöntemleri aynen uygulanır.
  - Örnek ($\omega=250$): $36\,\text{mH} \to j9$, $0.25\,\text{mF} \to -j16$, $80\,\text{mH} \to j20$. Düğüm denkleminden $\mathbf{V}_a = 12.43\angle -81.2^\circ\,\text{V}$, $v_a(t) = 12.43\cos(250t - 81.2^\circ)\,\text{V}$ (ekrandan, 01:43:57 ve 01:48:57).
  - Örnek ($\omega=10$, akım kontrollü bağımlı kaynak $10\mathbf{I}$): $\mathbf{Z}_1 = 5-j5$, $\mathbf{Z}_2 = 5+j5$; $\mathbf{V}_1 = 4.4721\angle 63.4^\circ\,\text{V}$, $\mathbf{I} = 0.89443\angle -26.6^\circ\,\text{A}$ (ekrandan, 01:53:57).
  - Op-amp örneği ($\omega = 500$): $\mathbf{V}_a = 0.075\angle -38.1^\circ\,\text{V}$, $v_o(t) = 174\cos(500t - 69.79^\circ)\,\text{mV}$ (ekrandan, 01:58:57).
  - Norton eşdeğeri: $\mathbf{Z}_t = \mathbf{V}_{oc}/\mathbf{I}_{sc} = 7.071\angle-15^\circ / 0.1060\angle-2^\circ = 66.71\angle -13^\circ\,\Omega$, Norton akımı $106\angle -2^\circ\,\text{mA}$ (ekrandan, 02:03:57).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kondansatör kaynak gerilimine şarj olmaz
  - $t<0$ durumunda kondansatör açık devre yapılır ve paralel olduğu elemanın gerilimi bulunur. Hoca "20 V var, o zaman 20 V'a şarj olur" demenin sık yapılan bir hata olduğunu söyledi.
- $R_{eq}$ enerji depolayan elemanın uçlarından bulunur
  - Devredeki ilk direnç değil, kondansatör ya da bobin uçlarından anahtar konumu değiştikten sonraki devrede görülen eşdeğer direnç kullanılır.
- Bağımlı kaynakta Thevenin direnci
  - Bağımlı kaynak varsa eşdeğer direnç normal yolla bulunamaz; test kaynağı yöntemi ya da doğrudan diferansiyel denklem kullanılır.
- Rampa ile basamağın rolü
  - Basamak, rampanın başlangıç seviyesini (baseline) kaydırır. Rampayı durdurmak için aynı eğimde ters rampa eklenir. Hoca bu noktada sık hata yapıldığını söyledi.
- Final için
  - Sunumlardaki çözümlü soruları çözüme bakmadan kendi başına çözmek gerekir; sınav soruları bunların benzeridir.
  - RLC devrelerinde $\alpha$ ve $\omega_0$ karşılaştırmasıyla aşırı, kritik ve az sönümlü cevaplar önemli olabilir.

## Kısa Tekrar Notları

- RC: $\tau = R_{eq}C$; RL: $\tau = L/R_{eq}$. Yaklaşık $5\tau$ sonra geçiş biter.
- $t<0$ DC kararlı halde: kondansatör açık devre, bobin kısa devre.
- Kısa devre edilen bir yolun yanındaki paralel direnç devre dışı kalır (akım kısa devreden geçer).
- Kondansatör enerjisi $w = \tfrac12 C v^2$.
- Bağımlı kaynak: $R_{eq} = v_{test}/i_{test}$.
- Yöntem 2: $\frac{di}{dt} + \frac{1}{\tau} i = 0 \Rightarrow i(t) = i(0)e^{-t/\tau}$.
- Akım ve gerilim bölücüyle diğer kol büyüklükleri aynı üstel çarpanla yazılır.
- $u(t-a)$ basamak, $r(t-a)$ rampa; parçalı sinyal bunların toplamıdır.
- Fazörde: bobin $j\omega L$ (akım gerilimden $90^\circ$ geride), kondansatör $-j/(\omega C)$ (akım $90^\circ$ önde).
- Toplama/çıkarma dikdörtgen (karmaşık) biçimde, çarpma/bölme kutupsal biçimde kolaydır.
- Bütün kaynaklar aynı frekansta olmalıdır; fazörde frekans bilgisi empedanslara gömülür.

## Detaylı Açıklamalar

- **Birinci dereceden devrelerde genel yol.** Son derste yeni konuya geçilmedi; dönemin sınavlarına hazırlık için bol örnek çözüldü. RC ve RL devrelerinde, kaynak çıkarıldığında depolanan enerji dirençler üzerinden sönümlenir ve son değer sıfırdır. Bu yüzden yalnız iki şey bulunur: başlangıç değeri ve zaman sabiti. Başlangıç değeri $t<0$ kararlı halde, kondansatör açık devre ve bobin kısa devre yapılarak bulunur. Zaman sabiti, anahtar konumu değiştikten sonraki devrede enerji depolayan elemanın uçlarından görülen eşdeğer dirençle hesaplanır. RLC devrelerinde ise iki depolayıcı eleman birbiriyle etkileştiği için $5\tau$ yaklaşımı doğrudan uygulanmaz; $\alpha$ ve $\omega_0$ karşılaştırması gerekir.
- **İlk RC örneği.** $v_C(0)=15\,\text{V}$ olan devrede $8\,\Omega$ ile $12\,\Omega$ seridir ($20\,\Omega$) ve bu kol $5\,\Omega$ ile paraleldir: $R_{eq} = 4\,\Omega$. $\tau = 4\cdot 0.1 = 0.4\,\text{s}$, $v_C = 15e^{-2.5t}\,\text{V}$. $12\,\Omega$ üzerindeki gerilim $\frac{12}{20}$ oranıyla $v_x = 9e^{-2.5t}\,\text{V}$, akım $i_x = v_x/12 = 0.75e^{-2.5t}\,\text{A}$ olur. Hoca grafiği $t=0$'da 15 V'tan başlayıp $5\tau = 2\,\text{s}$ civarında sıfıra yaklaşan bir eğri olarak çizdi.
- **Başlangıç değerinin bulunması.** Kaynaklı bir devrede anahtar $t=0$'da açıldığında kondansatör açık devre sayılır; seri $3\,\Omega$ ve $9\,\Omega$ üzerinde 20 V, $\frac{9}{12}$ oranında paylaşılır ve kondansatör 15 V'a şarj olur. Anahtar açıldıktan sonra kondansatör yalnız seri dirençler ($10\,\Omega$) üzerinden boşalır.
- **Bağımlı kaynaklı RL örneği.** Yöntem 1'de bobin yerine 1 V'luk test kaynağı konur. Çevre denklemleri $2i_1 - 2i_2 + 1 = 0$ ve $6i_2 - 2i_1 - 3i_1 = 0$'dır; buradan $i_2 = \tfrac56 i_1$, $i_1 = -3\,\text{A}$ ve $i_o = -i_1 = 3\,\text{A}$ çıkar. $R_{eq} = 1/3\,\Omega$, $\tau = L/R_{eq} = 0.5\cdot 3 = 1.5\,\text{s}$, $i(t) = 10e^{-2t/3}\,\text{A}$. Yöntem 2'de $\frac12\frac{di_1}{dt} + 2(i_1 - i_2) = 0$ ve $6i_2 - 2i_1 - 3i_1 = 0$ birleşince $\frac{di_1}{dt} + \frac23 i_1 = 0$ elde edilir; değişkenler ayrılıp $0$'dan $t$'ye integral alınır, $\ln$ kaldırılınca aynı sonuç gelir (ekrandan, 00:38:57).
  - **Ders sonrası not:** Hoca $i_x$'i akım bölücüyle $\frac46\cdot 10e^{-2t/3}$ diye verdi. Bağımlı kaynak yüzünden basit akım bölücü geçerli değildir. $2\,\Omega$ bobine paralel olduğu için $v = L\,di/dt = -\tfrac{10}{3}e^{-2t/3}\,\text{V}$ ve $i_x = v/2 = -\tfrac53 e^{-2t/3}\,\text{A}$ olur (python ile doğrulandı).
- **Tekillik fonksiyonları.** Bir basamağı sıfırlamak için aynı genlikte ters basamak eklenir; $-10$'a inen bir sinyal için iki kat ($-20$) basamak gerekir. Rampanın eğimi $r(t)$'nin katsayısıdır. Rampayı yatay yapmak için aynı eğimde ters rampa, aşağı döndürmek için iki kat eğimde ters rampa eklenir. Basamak fonksiyonu rampanın başlangıç seviyesini kaydırır. Türev alındığında basamaklar darbeye, integral alındığında basamaklar rampaya dönüşür.
- **Fazör analizi.** Direnç, bobin ve kondansatör birlikteyken tek bir eşdeğer dirençten söz edilemez; empedans kullanılır. Fazörde $\omega$ empedansların içine gömülür ve zaman değişkeninden kurtulunur. Kosinüsle verilen kaynak doğrudan fazöre yazılır ($20\cos 250t \to 20\angle 0^\circ$); sinüs olsaydı önce kosinüse çevrilirdi. İlk örnekte kondansatörün üst düğümünde KCL yazılır: $\mathbf{I}_1 + 1.2\angle 45^\circ = \mathbf{I}_2 + \mathbf{I}_3$, $\mathbf{I}_3 = (\mathbf{V}_a - 4\mathbf{V}_a)/j20$. Sonuç $12.43\angle -81.2^\circ\,\text{V}$; çıkış girişten $81.2^\circ$ geridedir.
  - **Ders sonrası not:** Slaytta seri kolun empedansı $8 - j9$ yazılmış. Hoca bunun hatalı olduğunu ve $8 + j9$ olması gerektiğini söyledi. Python ile $8 + j9$ alındığında slayttaki $12.43\angle -81.2^\circ$ sonucu çıkıyor; yani yalnız yazım hatası var.
- **Bağımlı kaynaklı fazör örneği.** $\mathbf{I} = (\mathbf{V}_s - \mathbf{V}_1)/R_1$, $10\mathbf{I} = \mathbf{V}_2 - \mathbf{V}_1$ ve süper düğüm KCL'si üç denklem verir; matrisle çözülür. $\mathbf{V}_1$, $\mathbf{I}$'dan $63.4^\circ + 26.6^\circ = 90^\circ$ öndedir.
- **Op-amp ve Norton örnekleri.** Op-amp'ta ideal kural $\mathbf{V}_a = \mathbf{V}_b$ fazör devresinde de geçerlidir; evirmeyen ve eviren düğümlerde KCL yazılır. Norton eşdeğerinde açık devre gerilimi ve kısa devre akımı bulunur; oranları eşdeğer empedansı verir. AC'de Thevenin/Norton direnci yerine eşdeğer empedans söz konusudur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
