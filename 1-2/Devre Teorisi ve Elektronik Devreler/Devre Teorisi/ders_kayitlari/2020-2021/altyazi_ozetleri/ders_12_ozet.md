# Ders 12 Çalışma Özeti

## Genel Konular

- Kaydın ilk bölümü: laboratuvar sınavı (yaklaşık ilk 2 saat)
  - Kaydın başında dersin kendisi değil, başka bir hocanın yürüttüğü op-amp laboratuvar sınavı var. Soru Google Classroom'dan paylaşıldı.
  - Devredeki değerler öğrenci numarasından hesaplanıyor (mod 6 işlemi var). Son rakamı 0 olan öğrenciler de bu soruda 0'ı doğrudan kullanabilir.
  - En az bir eviren ve bir evirmeyen op-amp kullanılacak. Daha fazlası da kullanılabilir. Hepsi tek bir devre olarak bağlanacak.
  - Yalnızca soruda verilen direnç değerleri kullanılabilir. Bir direnç birden fazla kez kullanılabilir, hepsini kullanmak zorunlu değil.
  - Sonucun nasıl hesaplandığı kısaca (birkaç cümleyle) açıklanmalı.
- Kısa sınav 2'nin çözümü
  - Devre: soldan sağa bir $i_s$ akım kaynağı ve ona paralel $C$. Üst hatta $C$'nin üst ucundan bir $L$ endüktansı çıkıyor ($i_L$ bu yönde). $L$'nin diğer ucu ile toprak arasında $R$ var. Aynı düğümden bir anahtar üzerinden $5$ V'luk gerilim kaynağına gidiliyor. Anahtar uzun süre kapalı kaldıktan sonra $t = 0$'da açılıyor.
  - Değerler: $R = 40\ \Omega$, $C = 25$ mF, $L = 10$ H.
  - Sorular: (1) $i_s = 10u(t)$ A için a) $i_L(0^-)$, b) $i_L(t)$. (2) $i_s = e^{-3t}u(t)$ A için a) $i_L(\infty)$, b) $i_L(t)$.
  - $t = 0^-$ devresi: $C$ açık devre, $L$ kısa devre, $i_s = 0$. $5$ V kaynağı doğrudan $R$'nin uçlarında. $C$ açık devre olduğu için $L$ kolundan akım geçemez.
    - $i_L(0^-) = 0$, $V_C(0^-) = 5$ V, $V_L(0^-) = 0$, $i_C(0^-) = 0$.
  - $t > 0$ denklemleri: $i_s = i_L + i_C$, $i_C = C\frac{dV_C}{dt}$, $V_C = L\frac{di_L}{dt} + Ri_L$.
    - Birleştirince: $\frac{d^2 i_L}{dt^2} + \frac{R}{L}\frac{di_L}{dt} + \frac{1}{LC}i_L = \frac{i_s}{LC}$.
    - $\frac{R}{L} = 4$, $\frac{1}{LC} = 4$. Karakteristik denklem $s^2 + 4s + 4 = 0$, çift kök $s = -2$ (kritik sönüm).
    - İkinci başlangıç koşulu: $\frac{di_L}{dt}(0^+) = \frac{V_C(0) - Ri_L(0)}{L} = \frac{5}{10} = 0.5$ A/s.
  - Durum 1 ($i_s = 10$ A): zorlanmış çözüm sabit, $i_{L,z} = 10$ A.
    - $i_L(t) = 10 + (A + Bt)e^{-2t}$. $i_L(0) = 0 \Rightarrow A = -10$. $-2A + B = 0.5 \Rightarrow B = -19.5$.
    - $i_L(t) = 10 - 10e^{-2t} - 19.5te^{-2t}$ A, $t \geq 0$.
  - Durum 2 ($i_s = e^{-3t}$): zorlanmış çözüm $Ke^{-3t}$ biçiminde.
    - Denkleme koyunca $K(9 - 12 + 4) = 4 \Rightarrow K = 4$.
    - $i_L(t) = 4e^{-3t} + (A + Bt)e^{-2t}$. $A = -4$. $-12 - 2A + B = 0.5 \Rightarrow B = 4.5$.
    - $i_L(t) = -4e^{-2t} + 4.5te^{-2t} + 4e^{-3t}$ A. $i_L(\infty) = 0$, çünkü kaynak sıfıra gider.
  - Sık yapılan hatalar:
    - Zorlanmış çözümü katsayısız $e^{-3t}$ olarak yazmak. Doğrusu $Ke^{-3t}$ yazıp $K$'yı denklemden bulmak.
    - $\frac{di_L}{dt}(0)$ değerini bulamamak, yani ikinci başlangıç koşulunu kurmamak.
    - 1a'da sonucu net bir sayı yerine $u(t)$ içeren ifadeyle bırakmak. Buradan puan kırıldı.
  - Puanlama: her sorunun a şıkkı 10, b şıkkı 40 puan. Sonuçlar Google Classroom'da. İtirazlar değerlendirilecek.
- Fazör uzayında Thevenin-Norton eşdeğeri
  - Tekrar: sinüzoidal sürekli hâlde geçici rejim bitmiştir. Bütün akım ve gerilimler kaynak frekansında salınır. Elemanlar fazöre geçirilince devre bir direnç devresi gibi çözülür. Eşdeğer empedans, kaynak dönüşümü, Thevenin-Norton, maksimum güç hepsi geçerlidir.
  - İki devre, aynı yük empedansına her değerde aynı gerilimi ve akımı veriyorsa eşdeğerdir.
  - Yük sonsuz (açık devre) yapılırsa: Thevenin devresinde uç gerilimi $\mathbf{V}_{TH}$, Norton devresinde $\mathbf{I}_N Z_N$. Yani $\mathbf{V}_{TH} = \mathbf{I}_N Z_N$.
  - Kaynaklar sıfırlanıp uçlardan içeri bakılırsa ikisinde de aynı empedans görülür: $Z_{TH} = Z_N$.
  - Kısa devre akımı Norton akımına eşittir: $\mathbf{I}_{SC} = \mathbf{I}_N = \frac{\mathbf{V}_{TH}}{Z_{TH}}$.
- Örnek 05: merdiven devre (ardışık kaynak dönüşümü)
  - Devre: $i_1 = 5\sin(400t + 50°)$ mA akım kaynağı, ona paralel $C_1 = 1\ \mu$F. Seri $R_1 = 3$ k$\Omega$. Şönt $L_1 = 0.3$ H. Seri $L_2 = 2$ H. Şönt $R_2 = 5$ k$\Omega$. En sağda yük olarak şönt $C_2 = 0.7\ \mu$F. İstenen: $C_2$ üzerinden geçen akım.
  - Kaynak: $5\sin(400t + 50°) = 5\cos(400t - 40°)$, yani $\mathbf{I}_1 = 5\angle -40°$ mA, $\omega = 400$ rad/s.
  - Empedanslar: $Z_{C_1} = -j2500 = 2500\angle -90°\ \Omega$, $Z_{R_1} = 3000\ \Omega$, $Z_{L_1} = j120\ \Omega$, $Z_{L_2} = j800\ \Omega$, $Z_{R_2} = 5000\ \Omega$, $Z_{C_2} = -j3571\ \Omega$.
  - Adımlar (her adımda kaynak dönüşümü ve birleştirme):
    1. $I_1$ ve $C_1$ Thevenin'e: $\mathbf{V}_{TH1} = \mathbf{I}_1 Z_{C_1} = 12.5\angle -130°$ V. Slaytta $7.5$ yazıyor, hoca derste $12.5$ olarak düzeltti.
    2. Seri $Z_{C_1} + Z_{R_1} = 3000 - j2500 = 3905\angle -39.8°\ \Omega$. Norton'a dönüş: $\mathbf{I}_{N1} = \frac{\mathbf{V}_{TH1}}{3905\angle -39.8°}$.
    3. $L_1$ ile paralel birleştirme, tekrar Thevenin'e dönüş, $L_2$ ile seri toplama.
    4. Tekrar Norton'a dönüş, $R_2$ ile paralel birleştirme: $Z_{eq4} = 906\angle 79.4°\ \Omega$.
    5. Son devre: Norton kaynağı, $Z_{eq4}$ ve $Z_{C_2}$ paralel. $\mathbf{I}_{C_2}$ akım bölücüyle bulunur.
  - Slayttaki sonuç $i_{C_2}(t) = 86\cos(400t + 74.3°)\ \mu$A. Bu değer $7.5$ V'luk hatalı değerle hesaplanmış. Doğrusu için "Ders sonrası notlar"a bakın.
  - Slayt paralel elemanlarda admitansları toplayarak ilerliyor. Hoca doğrudan paralel empedans formülünü ($\frac{Z_1Z_2}{Z_1+Z_2}$) kullanmayı tercih ettiğini, ikisinin de aynı sonucu verdiğini söyledi.
  - Açı kuralı: iki karmaşık sayı toplanacaksa açıları toplanamaz. Önce kartezyen biçime geçilir, toplanır, sonra $\tan^{-1}\frac{y}{x}$ ile tekrar polar biçime dönülür.
  - Aynı devrenin Thevenin yoluyla çözümü: kaynak (akım kaynağı) sıfırlanıp açık devre yapılır. Uçlardan bakınca $(Z_{C_1} + Z_{R_1}) \parallel Z_{L_1}$, sonra $+ Z_{L_2}$, sonra $\parallel Z_{R_2}$. MATLAB ile aynı $Z_{TH} = 906\angle 79.4°\ \Omega$ bulundu.
  - $\mathbf{V}_{TH}$ ise yük çıkarılıp açık uçlardaki gerilim hesaplanarak bulunur.
  - Pratiklik devrenin şekline bağlıdır. Merdiven devre, kaynak dönüşümü pratiği için seçilmiş. Sınavda "Thevenin eşdeğerini bulun" denirse Thevenin kullanılmak zorundadır.
- Örnek: rezonanstaki LC devresinin Norton eşdeğeri
  - Devre: $v_1 = 1\sin(1000t)$ V kaynağı, seri $L_1 = 0.1$ H, uçlara paralel $C_1 = 10\ \mu$F, yük $R_1 = 1$ k$\Omega$. Slayttaki iddia: Norton eşdeğeri, $R_1$'e bağlı tek bir $10\sin(1000t)$ mA akım kaynağıdır. Ayrıca doğal frekans $\omega_0$ isteniyor.
  - Fazörler: $\mathbf{V}_1 = 1\angle -90°$ V, $Z_{L_1} = j100\ \Omega$, $Z_{C_1} = -j100\ \Omega$.
  - $Z_N$: kaynak kısa devre yapılınca $L_1$ ve $C_1$ paralel kalır. $\frac{1}{Z_N} = \frac{1}{j100} + \frac{1}{-j100} = 0$, yani $Z_N = \infty$ (açık devre). Bu yüzden Norton eşdeğerinde paralel empedans yoktur, yalnızca akım kaynağı kalır.
  - $\mathbf{I}_N$: uçlar kısa devre yapılınca $C_1$ devre dışı kalır, $\mathbf{I}_N = \frac{1\angle -90°}{100\angle 90°} = 0.01\angle -180°$ A.
  - Doğal frekans: $\omega_0 = \frac{1}{\sqrt{L_1C_1}} = 1000$ rad/s. Kaynak frekansı tam bu değerde olduğu için $Z_N$ sonsuz çıkıyor.
  - Hoca bulduğu $10\cos(1000t - 180°)$ mA sonucunu slayttaki $10\sin(1000t)$ mA ile eşleştiremedi ve doğru hâlini duyuruyla paylaşacağını söyledi. Hocanın sonucu doğrudur, slayttaki faz hatalıdır. Ayrıntı "Ders sonrası notlar"da.
  - Hoca, pratikte direnç içermeyen böyle bir devrenin olmayacağını, bu teorik durumda yük bağlıyken doğrudan yük akımını hesaplamanın da bir yol olduğunu söyledi.
- Gerilim bölücü ve akım bölücü
  - Gerilim bölücü (seri empedanslar): $\mathbf{V}_1 = \mathbf{V}_s\frac{Z_1}{Z_1 + Z_2}$, $\mathbf{V}_2 = \mathbf{V}_s\frac{Z_2}{Z_1 + Z_2}$, $\frac{\mathbf{V}_1}{\mathbf{V}_2} = \frac{Z_1}{Z_2}$. Empedansı büyük olan elemanın üzerine daha çok gerilim düşer.
  - Akım bölücü, iki paralel eleman: bir koldaki akım karşı koldaki empedansla orantılıdır. $\mathbf{I}_1 = \mathbf{I}_s\frac{Z_2}{Z_1 + Z_2}$.
  - İkiden fazla paralel eleman: bir koldaki akım kendi empedansıyla ters orantılıdır. $\mathbf{I}_k = \mathbf{I}_s\frac{1/Z_k}{\sum_i 1/Z_i} = \mathbf{I}_s\frac{Y_k}{Y_{eş}}$.
- Örnek 53: bağımlı gerilim kaynaklı devre (düğüm denklemi)
  - Devre: $v_s = 20\cos(250t)$ V kaynağından seri $8\ \Omega$ ve $36$ mH ile $a$ düğümüne gidiliyor. $a$ düğümü ile toprak arasında $0.25$ mF kapasitör ve yukarı yönlü $1.2\cos(250t + 45°)$ A akım kaynağı var. $a$ düğümünden $80$ mH üzerinden, artı ucu üstte olan $4v_a$ bağımlı gerilim kaynağına gidiliyor. İstenen: $v_a(t)$.
  - Fazörler: $\omega = 250$ rad/s, $\mathbf{V}_s = 20\angle 0°$, $\mathbf{I}_s = 1.2\angle 45°$ A. $Z_{36mH} = j9$, $Z_C = -j16$, $Z_{80mH} = j20\ \Omega$.
  - $a$ düğümünde KAY: $\mathbf{I}_1 + 1.2\angle 45° = \mathbf{I}_2 + \mathbf{I}_3$.
    - $\frac{20\angle 0° - \mathbf{V}_a}{8 + j9} + 1.2\angle 45° = \frac{\mathbf{V}_a}{-j16} + \frac{\mathbf{V}_a - 4\mathbf{V}_a}{j20}$.
    - Slaytta payda $8 - j9$ yazıyor. Hoca bunu $8 + j9$ olarak düzeltti, bu düzeltme doğrudur.
  - Slayttaki sonuç: $\mathbf{V}_a = 12.43\angle -81.2°$ V, $v_a(t) = 12.43\cos(250t - 81.2°)$ V.
  - Hoca MATLAB ile yeniden hesaplayıp $17.71\angle -60.61°$ V buldu ve slaytı buna göre düzeltmemizi söyledi. Bu düzeltme yanlıştır, slayttaki sonuç doğrudur. Ayrıntı "Ders sonrası notlar"da.
- Örnek 54: süper düğüm ve akım kontrollü gerilim kaynağı
  - Devre: $v_s = 10\cos(10t)$ V kaynağı, seri $R_1 = 10\ \Omega$ ($i$ bu dirençten geçen akım) ile $v_1$ düğümüne gidiliyor. $v_1$ ile toprak arasında $C = 10$ mF ve $R_2 = 10\ \Omega$ paralel. $v_1$'den $v_2$'ye eksi ucu $v_1$ tarafında olan $10i$ bağımlı gerilim kaynağı. $v_2$ ile toprak arasında seri $L = 500$ mH ve $R_3 = 5\ \Omega$. İstenen: $i(t)$.
  - Slaytta kaynak $v_a(t)$ diye yazılmış, devredeki $v_s(t)$ kastediliyor.
  - Fazörler: $\mathbf{V}_s = 10\angle 0°$, $\omega = 10$ rad/s. $Z_C = -j10$, $Z_L = j5\ \Omega$.
  - Birleştirme: $Z_C \parallel R_2 = \frac{10}{1 + j} = 5 - j5\ \Omega$. $Z_L + R_3 = 5 + j5\ \Omega$.
  - Denklemler (3 bilinmeyen: $\mathbf{V}_1$, $\mathbf{V}_2$, $\mathbf{I}$):
    - $\mathbf{I} = \frac{\mathbf{V}_s - \mathbf{V}_1}{R_1}$.
    - Bağımlı kaynak: $\mathbf{V}_2 - \mathbf{V}_1 = 10\mathbf{I}$.
    - Süper düğüm KAY: $\mathbf{I} = \frac{\mathbf{V}_1}{5 - j5} + \frac{\mathbf{V}_2}{5 + j5}$.
  - Slaytta denklemlerde $Z_2$, $Z_3$, şekilde $Z_1$, $Z_2$ yazıyor. Hoca bunları şekle uyacak şekilde düzeltti ($Z_2 \to Z_1$, $Z_3 \to Z_2$).
  - Sonuç (slayt): $\mathbf{V}_1 = 4.472\angle 63.4°$ V, $\mathbf{I} = 0.894\angle -26.6°$ A, $i(t) = 0.894\cos(10t - 26.6°)$ A. Hoca sayısal çözümü derste yapmadı, sonuç Python ile doğrulandı.
- Örnek 56: bağımlı kaynaklı devrenin Norton eşdeğeri (yalnızca fazör)
  - Devre: $10\angle 30°$ V kaynağından seri $30\ \Omega$ ve $5\mathbf{I}_a$ bağımlı gerilim kaynağı (artı ucu sağda) ile bir düğüme gidiliyor. Bu düğüm ile toprak arasında $-j25\ \Omega$ kapasitör var, $\mathbf{I}_a$ bu kapasitörden aşağı akan akım. Düğümden seri $50\ \Omega$ ile çıkış uçlarına gidiliyor.
  - Frekans verilmediği için çözüm fazör uzayında bırakılır.
  - Açık devre gerilimi: $50\ \Omega$'dan akım geçmez. Çevre denklemi: $10\angle 30° = 30\mathbf{I}_a - 5\mathbf{I}_a - j25\mathbf{I}_a$.
    - $\mathbf{I}_a = \frac{10\angle 30°}{25 - j25} = 0.283\angle 75°$ A.
    - $\mathbf{V}_{OC} = -j25\,\mathbf{I}_a = 7.071\angle -15°$ V $= \mathbf{V}_{TH}$.
  - Kısa devre akımı: uçlar kısa devre, iki çevre ($\mathbf{I}_1$ ve $\mathbf{I}_{SC}$), $\mathbf{I}_a = \mathbf{I}_1 - \mathbf{I}_{SC}$.
    - $30\mathbf{I}_1 - 5(\mathbf{I}_1 - \mathbf{I}_{SC}) - j25(\mathbf{I}_1 - \mathbf{I}_{SC}) = 10\angle 30°$.
    - $50\mathbf{I}_{SC} - (-j25)(\mathbf{I}_1 - \mathbf{I}_{SC}) = 0$.
    - Matris: $\begin{bmatrix} 25 - j25 & 5 + j25 \\ j25 & 50 - j25 \end{bmatrix}\begin{bmatrix}\mathbf{I}_1 \\ \mathbf{I}_{SC}\end{bmatrix} = \begin{bmatrix}10\angle 30° \\ 0\end{bmatrix}$.
    - $\mathbf{I}_1 = 0.237\angle 61.4°$ A, $\mathbf{I}_{SC} = 0.106\angle -2°$ A.
  - $Z_N = Z_{TH} = \frac{\mathbf{V}_{OC}}{\mathbf{I}_{SC}} = \frac{7.071\angle -15°}{0.106\angle -2°} = 66.71\angle -13°\ \Omega$. $\mathbf{I}_N = \mathbf{I}_{SC} = 0.106\angle -2°$ A.
  - Hoca ayrıca kaynakları sıfırlayarak $Z_{TH}$'yi hesapladı: $30 \parallel (-j25) + 50 = 64.02\angle -13.3°\ \Omega$. Farkı yuvarlamaya bağladı. Bu yöntem bağımlı kaynaklı devrede geçersizdir. Ayrıntı "Ders sonrası notlar"da.
- Özel fonksiyonlar (dönem içinde hızlı geçilen konunun örneklerle tamamlanması)
  - Birim basamak: $t > 0$ için $u(t) = 1$, $t < 0$ için $0$. İçindeki ifade pozitif olunca $1$ olur: $u(t - 2)$, $t > 2$ için $1$.
  - Birim dürtü (impuls): $\delta(t) = \frac{du}{dt}$. Sonsuz genlikli, alanı $1$ olan anlık darbe.
  - Rampa: $t \geq 0$ için $r(t) = t$, $t < 0$ için $0$. Eğimi $1$. $r(t) = \int u\,dt$.
  - Örnek 45 (kare darbe): $t = 2$ ile $t = 5$ arasında $10$ olan gerilim darbesi.
    - $v(t) = 10u(t - 2) - 10u(t - 5) = 10[u(t - 2) - u(t - 5)]$.
    - Türev: $\frac{dv}{dt} = 10[\delta(t - 2) - \delta(t - 5)]$. $t = 2$'de $+10$, $t = 5$'te $-10$ şiddetinde dürtü.
  - Örnek 46: $0$-$2$ arasında $+10$, $2$-$4$ arasında $-10$ olan akım.
    - $i(t) = 10[u(t) - 2u(t - 2) + u(t - 4)]$. $t = 2$'de $20$ birimlik düşüş gerektiği için orta terimin katsayısı $2$.
    - İntegral: $\int i\,dt = 10[r(t) - 2r(t - 2) + r(t - 4)]$. $t = 2$'de tepe değeri $20$ olan, $t = 4$'te sıfıra inen üçgen.
    - Son terim olmasa grafik $t = 4$'ten sonra eğimi $-10$ ile aşağı devam ederdi.
  - Örnek 47 (testere dişi): $0$-$2$ arasında $0$'dan $10$'a doğrusal yükselen, $t = 2$'de sıfıra düşen gerilim. Üç çözüm:
    - $v(t) = 5r(t) - 5r(t - 2) - 10u(t - 2)$. İlk iki terim $t > 2$ için sabit $10$ bırakır, üçüncü terim onu sıfırlar.
    - $v(t) = 5r(t)[u(t) - u(t - 2)]$. Köşeli parantez $0$-$2$ arasında $1$ olan bir pencere oluşturur.
    - $v(t) = 5r(t)\,u(2 - t)$. Rampa $t < 0$'ı zaten sıfırladığı için yalnızca üst sınır gerekir. $u(-t)$ basamağın dikey eksene göre aynasıdır, $u(2 - t)$ ise $t < 2$ için $1$'dir.
- Final bilgilendirmesi
  - Sınav perşembe günü (hoca önce salı sandı, sonra kontrol edip perşembe olduğunu doğruladı).
  - Büyük ihtimalle vize formatında: çoktan seçmeli. Ek olarak çözümler kâğıda yazılıp sınav sonunda yüklenecek. Doğru şıkkı işaretlemek gerekir. El yazısı çözüm zorunlu ama tek başına not almak için yeterli değil. Çözüm özenli olmak zorunda değil, ama işlem yolu görülebilmeli.
  - Sorulara geri dönülemeyecek (sınavdan önce tekrar duyurulacak).
  - Süre: vizedeki soru başına süre esas alınacak. Öğrenciler vizede sürenin yetmediğini söyleyince hoca diğer şubenin hocasıyla konuşup süreyi biraz uzatmaya çalışacaklarını söyledi.
  - Kapsam: dersin tamamı. Ohm kanunu, KGY, KAY, çevre ve düğüm denklemleri, zaman domeninde RL ve RLC devreleri, sinüzoidal sürekli hâl, fazör gösterim ve fazör uzayında devre teoremleri. Ağırlık vizeden sonraki kısımda.
  - Örnek çözüm dosyaları paylaşılacak. İçlerinde yazım hataları olabilir, bunlara dikkat edilmeli.
  - Laboratuvar: bir deney daha var. Hocanın tahminine göre op-amp'lı türev ve integral alıcı devrelerin zaman domeninde çözümü.
  - Not süreci: yıl içi notu ile final notunun ağırlıklı ortalaması yıl sonu notunu verir. Harf notları çan eğrisiyle belirlenir.
  - Bütünleme: F0 hariç, CC ve altındaki notlar bütünlemeye girebilir. Bütünleme yalnızca finalin yerine geçer. Yeni ortalama, finaldeki çan eğrisinin aralıklarına göre harfe çevrilir.
  - Risk: CC ile bütünlemeye girip finalden düşük not alınırsa harf notu DC'ye düşebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- İkinci dereceden devrede iki başlangıç koşulu gerekir. $\frac{di_L}{dt}(0)$, $V_L = V_C - Ri_L$ bağıntısından bulunur. Zorlanmış çözüm katsayısıyla yazılır ($Ke^{-3t}$).
- Fazör uzayında direnç devrelerindeki bütün teoremler geçerlidir: eşdeğer empedans, kaynak dönüşümü, Thevenin-Norton, süperpozisyon, gerilim ve akım bölücü.
- $\mathbf{V}_{TH} = \mathbf{I}_N Z_N$, $Z_{TH} = Z_N$, $\mathbf{I}_N = \mathbf{I}_{SC}$.
- Toplama için kartezyen, çarpma ve bölme için polar biçim. Polar biçimdeki açılar toplanamaz.
- Bağımlı kaynak varsa $Z_{TH}$, $\mathbf{V}_{OC}/\mathbf{I}_{SC}$ oranından (veya test kaynağıyla) bulunur.
- Finalde doğru şık ve okunabilir bir çözüm yolu birlikte istenecek. Örnekleri mutlaka pratik olarak çözün.

## Kısa Tekrar Notları

- Kısa sınav: $i_L(0^-) = 0$, $V_C(0^-) = 5$ V, $i_L'(0) = 0.5$ A/s, çift kök $-2$.
  - $i_s = 10$: $i_L = 10 - 10e^{-2t} - 19.5te^{-2t}$ A.
  - $i_s = e^{-3t}$: $i_L = -4e^{-2t} + 4.5te^{-2t} + 4e^{-3t}$ A, $i_L(\infty) = 0$.
- Gerilim bölücü: $\mathbf{V}_k = \mathbf{V}_s\frac{Z_k}{\sum Z}$. Akım bölücü: $\mathbf{I}_k = \mathbf{I}_s\frac{Y_k}{\sum Y}$.
- Örnek 05: $i_{C_2}(t) = 143\cos(400t + 74.4°)\ \mu$A (slayttaki $86\ \mu$A hatalı).
- Rezonans örneği: $Z_N = \infty$, $i_N(t) = 10\cos(1000t - 180°)$ mA, $\omega_0 = 1000$ rad/s.
- Örnek 53: $v_a(t) = 12.43\cos(250t - 81.2°)$ V.
- Örnek 54: $i(t) = 0.894\cos(10t - 26.6°)$ A.
- Örnek 56: $\mathbf{I}_N = 0.106\angle -2°$ A, $Z_N = 66.71\angle -13°\ \Omega$.
- $\frac{d}{dt}u = \delta$, $\int u\,dt = r$.

## Detaylı Açıklamalar

### Kaynak dönüşümüyle merdiven devre çözümü

- Akım kaynağı + paralel empedans, gerilim kaynağı + seri empedansa çevrilebilir ($\mathbf{V} = \mathbf{I}Z$). Tersi de geçerlidir ($\mathbf{I} = \mathbf{V}/Z$, empedans paralel).
- Merdiven devrede bu iki dönüşüm sırayla uygulanır. Seri eleman geldiğinde Thevenin biçiminde olunur ve empedanslar toplanır. Paralel eleman geldiğinde Norton biçimine geçilir ve paralel eşdeğer alınır.
- Sonunda yükün uçlarında tek bir kaynak ve tek bir empedans kalır. Yük akımı akım bölücüyle, yük gerilimi $\mathbf{V} = \mathbf{I}Z$ ile bulunur.

### Ders sonrası notlar

- **Örnek 05'in sonucu:** Hoca $\mathbf{V}_{TH1}$'i $12.5\angle -130°$ V olarak düzeltti. Sonra MATLAB ile $Z_{TH}$'yi hesaplayıp slayttaki $906\angle 79.4°\ \Omega$ ile aynı bulunca slaytın arada bir yerde $12.5$'e geçtiğini varsaydı. Bu varsayım yanlıştır: $Z_{TH}$ kaynağın değerine bağlı değildir. Slayttaki $\mathbf{I}_{n2} = 0.255\angle -91.4°$ mA ve $86\ \mu$A değerleri hâlâ $7.5$ V ile hesaplanmış (tam olarak $7.5/12.5 = 0.6$ katı). Python ile yeniden hesaplanan doğru değerler:
  - $\mathbf{I}_{N1} = 3.20\angle -90.2°$ mA, $Z_{C_1} + Z_{R_1}$ ile $Z_{L_1}$'in paraleli $122.4\angle 88.6°\ \Omega$.
  - $\mathbf{V}_{TH2} = 0.392\angle -1.6°$ V, $Z_{eq3} = 922.3\angle 89.8°\ \Omega$.
  - $\mathbf{I}_{n2} = 0.425\angle -91.4°$ mA, $Z_{eq4} = 906.5\angle 79.4°\ \Omega$.
  - $\mathbf{I}_{C_2} = 143.3\angle 74.4°\ \mu$A, yani $i_{C_2}(t) = 143\cos(400t + 74.4°)\ \mu$A. $C_2$ gerilimi $0.512\angle -15.6°$ V.
- **Rezonans örneğindeki faz:** Hocanın bulduğu $\mathbf{I}_N = 0.01\angle -180°$ A doğrudur. Zaman domeninde $i_N(t) = 10\cos(1000t - 180°) = -10\cos(1000t) = 10\sin(1000t - 90°)$ mA. Slayttaki $10\sin(1000t)$ mA ifadesinde faz hatalıdır. Kısa devre akımı yalnızca endüktanstan geçer ve endüktans akımı gerilimden $90°$ geridedir. Bu yüzden kaynak $\sin(1000t)$ ise akım $\sin(1000t - 90°)$ olmalıdır. Yük bağlıyken doğrudan çözüm de aynı sonucu verir: $R_1$ akımı $10\angle -180°$ mA. Derste denenen "$\cos\alpha = \sin(\alpha + 180°)$" eşitliği yanlıştır. Doğrusu $\cos\alpha = \sin(\alpha + 90°)$'dir.
- **Örnek 53'teki hatalı "düzeltme":** Slayttaki $8 - j9$ yalnızca bir yazım hatasıdır. Slayttaki $12.43\angle -81.2°$ V sonucu zaten $8 + j9$ ile hesaplanmıştır ve doğrudur. Hoca MATLAB'a akım kaynağını $1.2\angle 45° = 1.2\sqrt{2} + j1.2\sqrt{2} = 1.697 + j1.697$ olarak girdi. Doğrusu $1.2\cos 45° + j1.2\sin 45° = 1.2\frac{\sqrt{2}}{2}(1 + j) = 0.849 + j0.849$'dur. $17.71\angle -60.61°$ V sonucu bu hatadan geliyor (Python ile aynı hatalı girdiyle $17.71\angle -60.62°$ elde edildi). Doğru cevap: $v_a(t) = 12.43\cos(250t - 81.2°)$ V.
- **Örnek 56'da kaynak sıfırlama:** $64.02\angle -13.3°\ \Omega$ ile $66.71\angle -13°\ \Omega$ arasındaki fark yuvarlamadan değil, yöntem hatasından geliyor. Bağımlı kaynaklar sıfırlanamaz, çünkü uçlara bir test kaynağı bağlandığında $\mathbf{I}_a$ sıfır olmaz. Derste "$\mathbf{I}_a$ sıfır olacağı için bağımlı kaynak da sıfır" denildi, bu doğru değildir. Bağımlı kaynak devredeyken uçlara $1$ A test akımı verilerek hesaplanırsa $Z_{TH} = 66.71\angle -12.99°\ \Omega$ bulunur. Bu değer $\mathbf{V}_{OC}/\mathbf{I}_{SC}$ ile aynıdır. Kaynakları sıfırlayıp içeri bakma yöntemi yalnızca bağımsız kaynaklı devrelerde kullanılabilir.
- **Örnek 54'teki küçük karışıklık:** Hoca birleştirmeleri $5 - j5$ ve $5 + j5$ olarak doğru hesapladı, sonra özet geçerken ikincisini de "$5 - j5$" diye söyledi. $Z_L + R_3 = 5 + j5\ \Omega$'dur.
- **Kısa sınavın başlangıç koşulu:** Anahtar ve $5$ V kaynağı, $L$'nin sağ ucundaki ($R$ ile ortak) düğüme bağlı. Bu yüzden $t < 0$'da $R$ doğrudan $5$ V'a bağlıdır. $C$ açık devre olduğundan $L$ kolundan akım akmaz. $i_L(0^-) = 0$ cevabı doğrudur. Çözümler Python ile de doğrulandı (diferansiyel denklem ve başlangıç koşulları sağlanıyor).
- **Örnek 54 ve 56'nın kontrolü:** Örnek 54 için $\mathbf{V}_1 = 4.472\angle 63.43°$ V, $\mathbf{I} = 0.8944\angle -26.57°$ A. Örnek 56 için $\mathbf{I}_a = 0.2828\angle 75°$ A, $\mathbf{V}_{OC} = 7.071\angle -15°$ V, $\mathbf{I}_{SC} = 0.1060\angle -2.01°$ A. Slayttaki değerler doğrudur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
