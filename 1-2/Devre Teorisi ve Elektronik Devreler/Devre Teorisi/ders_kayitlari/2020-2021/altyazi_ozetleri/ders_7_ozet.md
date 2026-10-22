# Ders 7 Çalışma Özeti

## Genel Konular

- Kayıt tarihi: 22 Nisan 2021 Perşembe. Konu işlemsel kuvvetlendirici (op-amp). Dersin sonunda Kısa Sınav 1'in çözümleri anlatıldı.
- Op-amp nedir?
  - Gerilim kontrollü, aktif bir devre elemanı. İki girişi (eviren $v_n$, evirmeyen $v_p$) ve bir çıkışı var.
  - Çalışması için besleme gerilimleri gerekir: $V^+$ ve $V^-$ (ör. ±15 V).
  - LM741 bacakları: 2 eviren giriş, 3 evirmeyen giriş, 6 çıkış, 7 $V^+$, 4 $V^-$. 1 ve 5 ofset ayarı, 8 boş.
- Eşdeğer (gerçek) model
  - Girişler arasında giriş direnci $R_i$. Fark gerilimi $v_d = v_p - v_n$.
  - Çıkışta bağımlı gerilim kaynağı $A\,v_d$ ve seri çıkış direnci $R_o$.
  - Tipik değerler: $A$ çok büyük ($10^5$ civarı), $R_i$ çok büyük (MΩ), $R_o$ küçük (10-100 Ω).
- Açık çevrim ve kapalı çevrim
  - Açık çevrimde çıkış $v_o = A\,v_d$. $A$ çok büyük olduğu için küçük bir $v_d$ bile çıkışı beslemeye dayatır.
  - Çıkış $V^-$ ile $V^+$ arasında kalır. Bu sınırları aşan değerler kırpılır (doyum, saturation).
  - Kapalı çevrimde çıkıştan eviren girişe geri besleme (negatif geri besleme) yapılır. Kazancı dış dirençler belirler.
- Kazancın desibel ile ifadesi
  - Gerilim için $20\log_{10}(A)$, güç için $10\log_{10}(A)$.
  - Örnek: 100 dB, $A = 10^5$ demektir. Katalogda 25 V/mV yazıyorsa $A = 25\,000$ olur (yaklaşık 88 dB).
- İdeal op-amp kuralları (negatif geri besleme varsa)
  - $A \to \infty$, $R_i \to \infty$, $R_o \to 0$.
  - Girişlerden akım akmaz: $i_n = i_p = 0$.
  - Girişlerin gerilimi eşittir: $v_n = v_p$ (sanal kısa devre).
- Sonlu kazançlı eviren kuvvetlendirici (Example 03)
  - $\dfrac{v_o}{v_s} = -\dfrac{R_f}{R_1}\cdot\dfrac{A b}{1 + A b}$, burada $b = \dfrac{R_1}{R_1 + R_f}$.
  - $A \to \infty$ olunca ideal sonuca, $-R_f/R_1$'e gider.
- Temel devreler
  - Eviren (inverting): $v_s$ girişi $R_1$ üzerinden eviren girişe, $R_f$ çıkıştan eviren girişe, evirmeyen giriş toprakta.
    - $v_o = -\dfrac{R_f}{R_1} v_s$.
  - Evirmeyen (non-inverting): $v_s$ evirmeyen girişe. $R_1$ eviren girişten toprağa, $R_f$ çıkıştan eviren girişe.
    - $v_o = \left(1 + \dfrac{R_f}{R_1}\right) v_s$.
  - Gerilim izleyici (voltage follower, tampon): çıkış doğrudan eviren girişe bağlı. $v_o = v_s$.
  - Toplayıcı (summing): birden çok giriş kendi dirençleriyle eviren girişe gelir.
    - $v_o = -R_f\left(\dfrac{v_1}{R_1} + \dfrac{v_2}{R_2} + \dfrac{v_3}{R_3}\right)$.
  - Fark alıcı (difference): bir giriş eviren tarafa, diğeri gerilim bölücü ile evirmeyen tarafa gelir.
  - Kaskat bağlantı: bir katın çıkışı diğerinin girişi olur. Toplam kazanç, kazançların çarpımıdır.
- Kırpılma tabloları
  - Example 04: eviren, $R_1 = 1$ kΩ, $R_f = 10$ kΩ, besleme $+15$ V / $-10$ V. Kazanç $-10$.
    - $v_s = 0$: 0 V. 0.5 V: $-5$ V. 1 V: $-10$ V.
    - 1.1 V: $-11$ V olmalıydı, $-10$ V'ta kırpılır.
    - $-1.2$ V: $+12$ V. $-1.51$ V: $+15.1$ V olmalıydı, $+15$ V'ta kırpılır.
  - Example 05: evirmeyen, kazanç $1 + 10/1 = 11$, aynı besleme.
    - 0.5 V: 5.5 V. 1.6 V: 17.6 V olmalıydı, $+15$ V. $-0.9$ V: $-9.9$ V.
    - $-1.01$ V: $-11.11$ V olmalıydı, $-10$ V'ta kırpılır (slayttaki hata için ders sonrası notlara bakın).
- Toplayıcı örneği (Example 07)
  - Girişler: 1 V (5 kΩ), 3 V (2 kΩ), $-2$ V (4 kΩ). $R_f = 10$ kΩ, besleme ±30 V.
  - $v_o = -10\text{k}\left(\dfrac{1}{5\text{k}} + \dfrac{3}{2\text{k}} + \dfrac{-2}{4\text{k}}\right) = -10(0.2 + 1.5 - 0.5) = -12$ V. Besleme sınırı içinde.
- Fark alıcı örneği (Example 08)
  - $V_A = 2$ V, $R_A = 6$ kΩ üzerinden eviren girişe. $R_f = 30$ kΩ.
  - $V_B = 3$ V, $R_B = 8$ kΩ ve $R_C = 4$ kΩ bölücüsü ile evirmeyen girişe.
  - $v_p = 3\cdot\dfrac{4}{8+4} = 1$ V. Sanal kısa devre ile $v_n = 1$ V.
  - Eviren düğümde KCL: $\dfrac{2 - 1}{6\text{k}} = \dfrac{1 - v_o}{30\text{k}}$, buradan $v_o = -4$ V.
- Kaskat örneği (Example 09)
  - 1. kat evirmeyen: $R_1 = 5$ kΩ, $R_{f1} = 15$ kΩ, $v_s = 2$ V. Çıkış $2(1 + 3) = 8$ V.
  - 2. kat eviren: $R_2 = 2$ kΩ, $R_{f2} = 8$ kΩ. Çıkış $-4 \cdot 8 = -32$ V.
- Tasarım alıştırması: $v_o = -\tfrac12 V_A + 2V_B - 4V_C$ ifadesini veren devre.
  - Hoca fikri verdi: pozitif katsayılı terim için önce bir eviren katla işaret çevrilir, sonra toplayıcı kullanılır.
- Türev alıcı (differentiator)
  - Girişte $C$, geri beslemede $R$. Kapasite akımı $C\,dv_s/dt$, bu akım $R$'den akar.
  - $v_o = -RC\,\dfrac{dv_s}{dt}$.
  - Example 01: $v_s = 3u(t - 5\text{ s})$ V, $C = 40$ µF, $R = 20$ kΩ. $RC = 0.8$ s.
    - Basamağın türevi dürtüdür: $v_o = -0.8\cdot 3\,\delta(t - 5) = -2.4\,\delta(t-5)$ V·s.
  - Sinüs girişi: $v_s = 2\sin 500t$ V, $RC = 2\times10^{-4}$ s.
    - $v_o = -RC \cdot 2\cdot 500\cos 500t = -0.2\cos 500t = 0.2\sin(500t - 90°)$ V.
    - Çıkış girişten 90° geride, genliği 0.2 V.
- İntegral alıcı (integrator)
  - Girişte $R$, geri beslemede $C$.
  - $v_o = -\dfrac{1}{RC}\displaystyle\int v_s\,dt$ (başlangıçta kapasite boş ise).
  - Kare dalga girişi üçgen dalga, üçgen dalga girişi parabol parçaları verir.
  - PSpice çizimi: sinüs girişte çıkış 90° önde ve bir DC ofset üzerinde.
- Bobinli sürümler (hoca tahtada gösterdi)
  - Girişte $R$, geri beslemede $L$: türev alıcı, $v_o = -\dfrac{L}{R}\dfrac{dv_s}{dt}$.
  - Girişte $L$, geri beslemede $R$: integral alıcı, $v_o = -\dfrac{R}{L}\displaystyle\int v_s\,dt$.
- Kısa Sınav 1 (8 Nisan 2021) çözümleri
  - Q1: kaynaklı bir merdiven devresi.
    - (a) Devrede 8 düğüm var.
    - (b) Verilen çevrede KVL: $8 + 3 + 6 - 24 + 4 + 2 - 3 - v_x = 0$, $v_x = -4$ V.
    - (c) KCL: $3 + 5 + i = 10$, $R_5$ akımı $i = 2$ A.
    - (d) $R_5$'in 7 s'de çektiği enerji: $4\text{ V} \cdot 2\text{ A} \cdot 7\text{ s} = 56$ J.
  - Q2: $R_{eq} = 50$ Ω verilmiş, $R$ isteniyor.
    - $12 \parallel 12 \parallel 12 = 4$ Ω. $50 = \big((4 + R + 10) \parallel 60\big) + 30$.
    - $20 = (14 + R)\parallel 60$, buradan $R = 16$ Ω.
  - Q3 sonuçları: $I = -5$ A, $I_y = 3$ A, $V = 36$ kV, $R_x = 4$ kΩ.
  - Q4 düğüm analizi: $V_1 = 24$, $V_2 = 8$, $V_3 = 12$, $V_4 = 0$, $V_5 = -8$ V. Akımlar $i = 6$, $j = 14$, $k = 9$, $i_x = 2$ A.
    - Süpernode kullanılmazsa 9 denklem, kullanılırsa 5 denklem yazılır.
  - Q5 süperçevre: $i_1 = -0.1$, $i_2 = -0.1$, $i_3 = -0.25$, $i_a = -0.05$ A.
- Vize bilgileri
  - Vize gelecek hafta. Çoktan seçmeli ve klasik karışık olacak.
  - Çözümler süre içinde yüklenecek. Yükleme için 5-10 dakika ayırın. Fotoğraf yüklemek uygun.
  - Aksi belirtilmedikçe hesap makinesi ve çevrimiçi araçlar serbest.
  - Op-amp konusu, türev ve integral alıcılar dahil, kapsamda.

## Hocanın Özellikle Vurguladığı Kısımlar

- İdeal op-amp analizinde iki kural yeter: girişlerden akım akmaz, $v_n = v_p$.
- Çıkış hiçbir zaman besleme gerilimlerini aşamaz. Hesap sonucu sınırı aşarsa çıkış o sınırda kırpılır.
- Kırpılmanın hangi sınırda olduğuna dikkat: pozitif sonuç $V^+$'ta, negatif sonuç $V^-$'de kırpılır.
- Eviren devrede işaret ters döner. Evirmeyen devrede kazanç en az 1'dir.
- Türev ve integral alıcılar vize kapsamında.
- Kısa sınavda en sık hata: süperçevre sorusunda $i_3$ ile $i_a$'yı aynı akım sanmak.
- Sınav yüklemesini son dakikaya bırakmayın.

## Kısa Tekrar Notları

- Eviren: $-R_f/R_1$. Evirmeyen: $1 + R_f/R_1$. İzleyici: 1.
- Toplayıcı: $v_o = -R_f\sum v_k/R_k$.
- Türev alıcı: $v_o = -RC\,dv_s/dt$. İntegral alıcı: $v_o = -\frac{1}{RC}\int v_s\,dt$.
- $\frac{d}{dt}\sin\omega t = \omega\cos\omega t$ ve $-\cos\omega t = \sin(\omega t - 90°)$.
- dB: gerilim $20\log$, güç $10\log$. 100 dB = $10^5$.
- Doğrusal bölge (Example 05, evirmeyen, kazanç 11): $-10/11 < v_s < 15/11$ V.

## Detaylı Açıklamalar

### Ders sonrası notlar

- **Example 05, $v_s = -1.01$ V satırı:** Slaytta çıkış $V^+$ sınırına, yani $+15$ V'a kırpılmış gibi yazılmış. Bu yanlış. $11 \cdot (-1.01) = -11.11$ V çıkar. Bu değer $V^- = -10$ V'un altında kaldığı için çıkış **$-10$ V** olur. Hoca da derste bu satırın tutarsız olduğunu fark etti.
- **İdeal kazanç değeri:** Slayt 8'de ideal op-amp için "$A_v > 10^6$" yazıyor. Hoca gerçek op-ampların tipik açık çevrim kazancını $10^4$-$10^5$ olarak söyledi. İkisi çelişmiyor: slayt ideal modeli, hoca gerçek elemanları anlatıyor.
- **Kaskat örneğinde besleme:** Slaytta besleme gerilimi verilmemiş. Sonuç $-32$ V çıktı. Gerçek bir op-amp ±15 V ile beslenseydi çıkış $-15$ V civarında kırpılırdı. Bu soruyu ideal (sınırsız) op-amp kabulüyle düşünün.
- **Türev alıcı Example 01 işareti:** Hoca dürtüyü yukarı doğru çizdi. Doğrusu, türev alıcı eviren yapıda olduğu için $t = 5$ s anında **negatif** bir dürtüdür: $v_o = -2.4\,\delta(t - 5)$ V·s. Slayttaki "$t > 5RC$ için $V_C = 3$ V" ifadesi ideal olmayan (geçici hal içeren) durumu anlatır. Hoca bu kısmı kapsam dışı bıraktı.
- **Tasarım alıştırmasının bir çözümü (derste yazılmadı):** $v_o = -\tfrac12 V_A + 2V_B - 4V_C$.
  - 1. kat eviren: $R = 10$ kΩ, $R_f = 20$ kΩ. Çıkış $V' = -2V_B$.
  - 2. kat toplayıcı, $R_f = 20$ kΩ: $V_A$ için 40 kΩ, $V'$ için 20 kΩ, $V_C$ için 5 kΩ.
  - Sağlama: $v_o = -\big(\tfrac{20}{40}V_A + \tfrac{20}{20}(-2V_B) + \tfrac{20}{5}V_C\big) = -\tfrac12 V_A + 2V_B - 4V_C$.
- **Kısa sınav Q1(d) işareti:** Çözüm belgesinde "$7 \cdot 2 \cdot (-4) = 56$ J" yazıyor. Çarpım aslında $-56$ çıkar. Direnç her zaman güç çeker. Akım $R_5$'in yüksek potansiyelli ucundan girdiği için doğru hesap $|v_x|\cdot i\cdot t = 4 \cdot 2 \cdot 7 = 56$ J'dür. Sonuç doğru, ara adımdaki işaret hatalı.
- **Kısa sınav Q5 slaytı:** Çözümün ② numaralı denkleminde $60(i_2 - i_3)$ yazıyor. O koldaki direnç 40 Ω'dur. Sayısal sonuçlar ($i_1 = i_2 = -0.1$, $i_3 = -0.25$, $i_a = -0.05$ A) 40 Ω ile Python'da yeniden çözüldü ve doğrulandı.
- **Doğrulama:** Bu özetteki op-amp örnekleri ve kısa sınavın Q2, Q4, Q5 sonuçları numpy ile yeniden hesaplandı. Q3 için yalnızca hocanın çözüm belgesindeki sonuçlar aktarıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
