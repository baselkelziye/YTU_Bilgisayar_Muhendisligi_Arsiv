# Ders 17 Çalışma Özeti

## Genel Konular

- Kutuplama (biasing) kavramı
  - Slayttaki tanım: kutuplama, transistörü iletime sokmak ve AC işareti yükseltebilmesini sağlamak için ona uygulanan DC gerilimlerdir (ekrandan, 00:05:00).
  - Doğru çalışma için NPN transistörde baz-emiter eklemi doğru, baz-kolektör eklemi ters polarlanır. Böylece bazdan gelen küçük $I_B$ akımı kolektörden emitere akan $I_C$ akımını denetler: $I_C = \beta I_B$.
- Çalışma noktası (Q noktası) ve çıkış karakteristiği
  - Slaytta $I_C$-$V_{CE}$ çıkış eğrileri, her biri bir $I_B$ değerine (0, 10, 20, ... 80 µA) karşılık gelen çizgilerdir; doyum (saturation), kesim (cutoff) ve aktif bölge işaretlidir (ekrandan, 00:10:00).
  - Kesim: $I_C = 0$ ise dirençlerde gerilim düşmez, $V_{CE} = V_{CC}$ olur. Bu, yatay eksendeki en büyük değerdir.
  - Doyum: $V_{CE} \approx 0$ ise kolektör akımı en büyük değerini alır: $I_{C(sat)} = V_{CC}/R_C$. Gerçekte $V_{CE(sat)}$ sıfır değil, sıfıra çok yakındır.
  - Bu iki uç noktayı birleştiren doğru DC yük doğrusudur. Q noktası, yük doğrusunun devredeki $I_B$ eğrisiyle kesiştiği noktadır.
  - $V_{CC}$ değişirse yük doğrusu paralel kayar; yalnız $R_C$ değişirse yalnız $I_{C(sat)}$ ucu değişir, $V_{CC}$ ucu sabit kalır. $\beta$ (dolayısıyla $\beta I_B$) Q noktasını yük doğrusu üzerinde kaydırır.
- Sabit kutuplama (fixed bias)
  - DC analizde kondansatörler açık devre sayılır, AC giriş ve çıkış devreden düşer (ekrandan, 00:25:00).
  - Baz-emiter çevresi: $V_{CC} - I_B R_B - V_{BE} = 0 \Rightarrow I_B = (V_{CC} - V_{BE})/R_B$. $V_{BE}$: Si için 0,7 V, Ge için 0,3 V.
  - Kolektör-emiter çevresi: $V_{CE} = V_{CC} - I_C R_C$.
- Emiter kararlı kutuplama (emitter-stabilized)
  - Emitere $R_E$ eklenmesi kutuplamayı kararlı hâle getirir (ekrandan, 00:30:00).
  - $I_E = I_C + I_B = (\beta + 1) I_B$ kullanılarak baz çevresinden $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + (\beta + 1) R_E}$ bulunur.
  - Kolektör çevresinde $I_E \approx I_C$ alınır: $V_{CE} = V_{CC} - I_C(R_C + R_E)$, $I_{C(sat)} = V_{CC}/(R_C + R_E)$ (ekrandan, 00:35:00).
- Gerilim bölücü kutuplama (voltage divider)
  - Yaklaşık analiz: $V_B = \dfrac{R_2 V_{CC}}{R_1 + R_2}$, $V_E = V_B - V_{BE}$, $I_E = V_E/R_E$, $V_{CE} = V_{CC} - I_C(R_C + R_E)$. Koşullar $I_B \ll I_1$, $I_1 \cong I_2$ ve $\beta R_E > 10 R_2$ (ekrandan, 00:40:00).
  - Düğüm gerilimleri: $V_C = V_{CC} - I_C R_C = V_E + V_{CE}$, $V_{BC} = V_B - V_C$.
- Kolektör geri beslemeli yapı
  - Baz direnci kolektörden beslenir. Kolektör direncinden $I_C + I_B$ geçer, ama $I_B$ çok küçük olduğundan $I_C$ alınır. Baz çevresi $V_C$ geriliminden başlayarak yazılır.
- Transistörün anahtar olarak kullanılması
  - Yalnız DC kaynakla çalışan transistör elektronik anahtar olarak kullanılabilir (ekrandan, 00:45:00). Giriş 0 V iken $I_B = 0$, transistör kesimde, $V_C = V_{CC}$. Giriş 5 V iken transistör iletimde, kolektör ucu yaklaşık 0 V olur.
- Arıza bulma ipuçları
  - Si için $V_{BE} \cong 0{,}7$ V, doğrusal çalışmada $V_{CE}$ yaklaşık $V_{CC}$'nin %25-%75'i; ohmmetreyle açık/kısa devre testi, lehim kontrolü, transistör test cihazı ve yükün etkisi (ekrandan, 00:50:00).
- PNP transistörde analiz NPN ile aynıdır, yalnız akım yönleri terstir.

## Hocanın Özellikle Vurguladığı Kısımlar

- $I_B$ her zaman $I_C$'ye göre çok küçük çıkmalıdır (genelde mikroamper, $I_C$ ise miliamper). Soruda $I_B$ bu kadar küçük çıkmadıysa çözüm büyük olasılıkla yanlıştır.
- Birimler (mili, mikro, kilo) dikkatle yazılmalıdır; karışıklık en sık hata kaynağıdır.
- $V_{BC}$ negatif çıkmalıdır: baz-kolektör ekleminin ters polarlandığını, yani transistörün aktif bölgede doğru çalıştığını gösterir.
- Transistör soruları zor değildir: KVL denklemleri doğru kurulursa uzun yoldan da kısa yoldan da aynı sonuç çıkar.
- Sorularda "Q" indisi ($I_{B_Q}$, $I_{C_Q}$) özel bir şey istemez; devre çözülünce bulunan değerler zaten Q noktasıdır.

## Kısa Tekrar Notları

- $I_C = \beta I_B$, $I_E = I_C + I_B = (\beta+1)I_B \approx I_C$.
- Kesim ucu: $I_C = 0$, $V_{CE} = V_{CC}$. Doyum ucu: $V_{CE} = 0$, $I_{C(sat)} = V_{CC}/(R_C + R_E)$ ($R_E$ yoksa $V_{CC}/R_C$).
- Sabit kutuplama: $I_B = (V_{CC} - V_{BE})/R_B$, $V_{CE} = V_{CC} - I_C R_C$.
- Emiter kararlı: $I_B = (V_{CC} - V_{BE})/[R_B + (\beta+1)R_E]$.
- Gerilim bölücü: $V_B = R_2 V_{CC}/(R_1+R_2)$; tam analizde $I_B = (E_{Th} - V_{BE})/[R_{Th} + (\beta+1)R_E]$.
- Kolektör geri besleme: $I_B = (V_{CC} - V_{BE})/(R_B + \beta R_C)$ ($R_E$ yoksa).
- $V_E = I_E R_E$, $V_B = V_{BE} + V_E$, $V_C = V_{CE} + V_E$, $V_{BC} = V_B - V_C < 0$.
- DC analizde kondansatörler açık devredir.

## Detaylı Açıklamalar

- Sabit kutuplama örneği (ekrandan, 00:55:00): $V_{CC} = 12$ V, $R_B = 240$ kΩ, $R_C = 2{,}2$ kΩ, $\beta = 50$.
  - $I_{B_Q} = (12 - 0{,}7)/240\text{ k}\Omega = 47{,}08$ µA; $I_{C_Q} = 50 \cdot 47{,}08$ µA $= 2{,}35$ mA.
  - $V_{CE_Q} = 12 - 2{,}35\text{ mA} \cdot 2{,}2\text{ k}\Omega = 6{,}83$ V; $V_B = V_{BE} = 0{,}7$ V, $V_C = V_{CE} = 6{,}83$ V (emiter doğrudan toprakta).
  - $V_{BC} = 0{,}7 - 6{,}83 = -6{,}13$ V. Eksi işaret, eklemin ters polarlandığını gösterir.
  - Yük doğrusu: $V_{CE}$ ucu 12 V, $I_{C(sat)} = 12/2{,}2\text{ k}\Omega$. Hoca bunu "5,1 mA gibi" diye tahmin etti.
  - Ders sonrası not: $12/2{,}2\text{ k}\Omega = 5{,}45$ mA'dir (python ile doğrulandı).
- Emiter kararlı örnek (ekrandan, 01:05:00): $V_{CC} = 20$ V, $R_B = 430$ kΩ, $R_C = 2$ kΩ, $R_E = 1$ kΩ, $\beta = 50$.
  - $I_B = 19{,}3\text{ V}/(430 + 51 \cdot 1)\text{ k}\Omega = 19{,}3/481 = 40{,}1$ µA; $I_C = 50 \cdot 40{,}1$ µA $\cong 2{,}01$ mA.
  - $V_{CE} = 20 - 2{,}01\text{ mA}(2 + 1)\text{ k}\Omega = 20 - 6{,}03 = 13{,}97$ V.
  - $V_E \approx I_C R_E \approx 2{,}01$ V; $V_C = V_{CE} + V_E \approx 15{,}98$ V; $V_B = 0{,}7 + 2{,}01 = 2{,}71$ V; $V_{BC} = 2{,}71 - 15{,}98 \approx -13{,}27$ V (ara adımlar python ile hesaplandı; slaytın bu kısmı karede görünmüyor).
- Gerilim bölücü örnek (ekrandan, 01:10:00): $V_{CC} = 22$ V, $R_1 = 39$ kΩ, $R_2 = 3{,}9$ kΩ, $R_C = 10$ kΩ, $R_E = 1{,}5$ kΩ, $\beta = 140$; $V_{CE}$ ve $I_C$ isteniyor.
  - $V_B = E_{Th} = 22 \cdot 3{,}9/(39 + 3{,}9) = 2$ V. $R_{Th}$, iki direncin paralel eşdeğeridir; $I_B = (E_{Th} - V_{BE})/[R_{Th} + (\beta+1)R_E]$, sonra $I_C = \beta I_B$, $V_{CE} = V_{CC} - I_C(R_C + R_E)$.
  - Sayısal sonuç derste sesli okunmadı. Python ile: $R_{Th} \approx 3{,}55$ kΩ, $I_B \approx 6{,}05$ µA, $I_C \approx 0{,}85$ mA, $V_{CE} \approx 12{,}27$ V (derste verilmedi).
- Tersten tasarım örneği (ekrandan, 01:15:00): $V_{CC} = 18$ V, $R_2 = 18$ kΩ, $R_E = 1{,}2$ kΩ, $I_{C_Q} = 2$ mA, $V_{CE_Q} = 10$ V; $R_1$ ve $R_C$ isteniyor.
  - $V_E \cong I_C R_E = 2{,}4$ V, $V_B = 0{,}7 + 2{,}4 = 3{,}1$ V.
  - $\dfrac{18\text{ k}\Omega \cdot 18\text{ V}}{R_1 + 18\text{ k}\Omega} = 3{,}1$ V $\Rightarrow 324 = 3{,}1R_1 + 55{,}8 \Rightarrow R_1 = 86{,}52$ kΩ.
  - $V_C = V_{CE} + V_E = 12{,}4$ V, $R_C = (18 - 12{,}4)/2\text{ mA} = 2{,}8$ kΩ.
- Anahtarlama örneği (ekrandan, 00:45:00): $V_{CC} = 5$ V, $R_C = 0{,}82$ kΩ, $R_B = 68$ kΩ, $h_{FE} = 125$; giriş 0 V ile 5 V arasında değişen kare dalga.
  - Giriş 0 V: $I_B = 0$, kesim, $V_C = 5$ V. Giriş 5 V: baz akımı oluşur, transistör iletime geçer, $V_C \approx 0$ V. Çıkış girişin tersidir.
  - $I_{C(sat)} = 5/0{,}82\text{ k}\Omega \approx 6{,}1$ mA.
  - Ders sonrası not: hoca bir yerde "6,1 amper" dedi; doğrusu 6,1 mA. Ayrıca 10 µA baz akımı için $125 \cdot 10$ µA $= 1{,}25$ mA'dir (hoca "hemen hemen 1 mA" dedi).
- Ders sonrası not: hoca DC analizin başında kondansatörlerin "kısa devre edildiğini" söyledi; DC analizde kondansatörler açık devredir. Hoca dersin ilerleyen kısmında bunu doğru biçimde (açık devre) tekrarladı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
