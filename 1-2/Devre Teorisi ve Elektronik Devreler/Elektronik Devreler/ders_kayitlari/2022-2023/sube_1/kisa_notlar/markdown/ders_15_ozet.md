# Ders 15 Çalışma Özeti

## Genel Konular

- Ders bir problem çözümü dersidir: BJT DC kutuplama devreleri için hazır çözümlü sorular slayt üzerinde kalemle işaretlenerek tek tek çözülür.
  - Bütün sorular aynı yolla çözülür: önce baz-emetör çevresinden (giriş çevresi) $I_B$ bulunur, sonra $I_C = \beta I_B$ ile kolektör akımı, en sonda kolektör-emetör çevresinden (çıkış çevresi) $V_{CE}$ ve nokta gerilimleri bulunur.
  - Silisyum transistörde $V_{BE} = 0{,}7$ V alınır. Kondansatörler DC analizde açık devredir; girişteki ve çıkıştaki kuplaj kondansatörleri yalnız AC bileşeni geçirir.
- Temel bağıntılar
  - $\beta = I_C / I_B$: transistöre özgü güçlendirme katsayısıdır; baz akımının çıkışta kaç kat büyüdüğünü gösterir.
  - $I_E = I_C + I_B = (\beta + 1) I_B$. $I_B$ mikroamper mertebesinde olduğu için $I_E \approx I_C$ alınabilir.
  - Tek indisli gerilim ($V_B$, $V_C$, $V_E$) o noktanın toprağa göre gerilimidir. Çift indisli gerilim iki nokta arasındaki farktır: $V_{BC} = V_B - V_C$, $V_{BE} = V_B - V_E$.
- Sabit kutuplama sorusu (ekrandan, 00:05:00)
  - $V_{CC} = 12$ V, $R_B = 240$ kΩ, $R_C = 2{,}2$ kΩ, $\beta = 50$, emetör doğrudan toprakta.
  - $I_{B_Q} = \dfrac{V_{CC} - V_{BE}}{R_B} = \dfrac{12 - 0{,}7}{240\text{ k}\Omega} = 47{,}08\ \mu$A, $I_{C_Q} = \beta I_{B_Q} = 2{,}35$ mA.
  - $V_{CE_Q} = V_{CC} - I_C R_C = 12 - (2{,}35\text{ mA})(2{,}2\text{ k}\Omega) = 6{,}83$ V.
  - $V_B = V_{BE} = 0{,}7$ V, $V_C = V_{CE} = 6{,}83$ V, $V_{BC} = V_B - V_C = -6{,}13$ V.
- Emetör kararlı kutuplama sorusu (ekrandan, 00:15:00)
  - $V_{CC} = 20$ V, $R_B = 430$ kΩ, $R_C = 2$ kΩ, $R_E = 1$ kΩ (40 µF ile köprülenmiş), $\beta = 50$.
  - Giriş çevresi: $V_{CC} = I_B R_B + V_{BE} + I_E R_E$, $I_E = (\beta+1)I_B$ yazılarak $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + (\beta+1)R_E} = 40{,}1\ \mu$A; $I_C = 2{,}01$ mA.
  - Çıkış çevresi: $V_{CE} = V_{CC} - I_C(R_C + R_E) = 13{,}97$ V.
  - $V_C = V_{CC} - I_C R_C = 15{,}98$ V, $V_E = I_E R_E \approx 2{,}01$ V, $V_B = V_{BE} + V_E = 2{,}71$ V.
- Gerilim bölücü kutuplama sorusu (ekrandan, 00:25:00 ve 00:30:00)
  - $V_{CC} = 22$ V, $R_1 = 39$ kΩ, $R_2 = 3{,}9$ kΩ, $R_C = 10$ kΩ, $R_E = 1{,}5$ kΩ (50 µF ile köprülenmiş), $\beta = 140$.
  - Baz tarafı Thevenin eşdeğerine çevrilir: $R_{Th} = R_1 \parallel R_2 = 3{,}55$ kΩ, $E_{Th} = \dfrac{R_2 V_{CC}}{R_1 + R_2} = 2$ V.
  - $I_B = \dfrac{E_{Th} - V_{BE}}{R_{Th} + (\beta+1)R_E} = \dfrac{1{,}3\text{ V}}{3{,}55 + 211{,}5\text{ k}\Omega} = 6{,}05\ \mu$A, $I_C = 0{,}85$ mA, $V_{CE} = V_{CC} - I_C(R_C + R_E) = 12{,}22$ V.
- Kolektör geri beslemeli kutuplama soruları (ekrandan, 00:40:00 ve 00:45:00)
  - $R_E$'li devre: $V_{CC} = 18$ V, $R_C = 3{,}3$ kΩ, $R_1 = 91$ kΩ ve $R_2 = 110$ kΩ (kolektörden baza seri), $R_E = 510$ Ω, $\beta = 75$. $I_C' \approx I_C$ alınarak $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + \beta(R_C + R_E)} = 35{,}5\ \mu$A ($R_B = R_1 + R_2 = 201$ kΩ), $V_C = V_{CC} - I_C R_C = 9{,}22$ V.
  - $R_E$'siz devre: $V_{CC} = 20$ V, $R_C = 4{,}7$ kΩ, $R_B = 680$ kΩ, $\beta = 120$. $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + \beta R_C} = 15{,}51\ \mu$A, $I_C = 1{,}86$ mA, $V_{CE} = 11{,}26$ V, $V_B = V_{BE} = 0{,}7$ V.
- Tasarım (ters yönde) sorusu (ekrandan, 00:50:00)
  - $V_{CC} = 18$ V, $R_2 = 18$ kΩ, $R_E = 1{,}2$ kΩ; $I_{C_Q} = 2$ mA ve $V_{CE_Q} = 10$ V verilmiş, $R_1$ ve $R_C$ isteniyor.
  - $V_E \approx I_C R_E = 2{,}4$ V, $V_B = V_{BE} + V_E = 3{,}1$ V; gerilim bölücüden $R_1 = 86{,}52$ kΩ.
  - $R_C$: $18 = I_C(R_C + R_E) + V_{CE}$ ya da $V_C = V_{CE} + V_E = 12{,}4$ V ve $R_C = (V_{CC} - V_C)/I_C$; iki yol da $R_C = 2{,}8$ kΩ verir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Temel kavramlar bilindikten sonra bu soruların geri kalanı yalnız işlemdir
  - Her soru aynı iki çevre denklemine ve $I_C = \beta I_B$, $I_E = (\beta+1)I_B$ bağıntılarına dayanır. Hoca bu tür soruların sınavda çıkacağını söyledi.
- $V_{BE}$'yi çevre denkleminde unutmamak
  - Baz-emetör çevresi yazılırken 0,7 V'luk $V_{BE}$ düşümü her zaman eklenir; $I_C$ yerine $\beta I_B$ yazılarak tek bilinmeyen $I_B$'ye indirilir.
- Sonucu kendi kendine kontrol etme
  - Baz akımı mutlaka çok küçük (mikroamper) çıkar. $I_B$ miliamper çıkıyorsa $I_C$'nin çok daha büyük olması gerekir; bu bir hata işaretidir.
- Bir nokta gerilimine iki yoldan ulaşılabilir
  - Örneğin $V_C$ yukarıdan ($V_{CC} - I_C R_C$) ya da aşağıdan ($V_{CE} + V_E$) hesaplanır; iki yol da aynı sonucu verir. Kısa olan yol seçilir.
- Birimler yazılmalı
  - Sonuçlarda kΩ, mA, µA gibi birimler unutulmamalıdır.

## Kısa Tekrar Notları

- Giriş çevresi: $V_{CC}$ (ya da $E_{Th}$) $= I_B R_B + V_{BE} + I_E R_E$.
- Çıkış çevresi: $V_{CC} = I_C R_C + V_{CE} + I_E R_E \approx I_C(R_C + R_E) + V_{CE}$.
- Sabit kutuplama: $I_B = (V_{CC} - V_{BE})/R_B$.
- Emetör kararlı: $I_B = (V_{CC} - V_{BE})/[R_B + (\beta+1)R_E]$.
- Gerilim bölücü: $R_{Th} = R_1 R_2/(R_1 + R_2)$, $E_{Th} = R_2 V_{CC}/(R_1 + R_2)$, $I_B = (E_{Th} - V_{BE})/[R_{Th} + (\beta+1)R_E]$.
- Kolektör geri beslemeli: $I_B = (V_{CC} - V_{BE})/[R_B + \beta(R_C + R_E)]$; $R_E$ yoksa payda $R_B + \beta R_C$.
- Emetör toprakta ise $V_E = 0$, $V_B = 0{,}7$ V, $V_C = V_{CE}$.
- Aktif bölgedeki npn transistörde $V_{BC}$ negatif çıkar (baz-kolektör eklemi ters kutuplu).
- Tasarım sorusunda sıra: $V_E \to V_B \to R_1$ (bölücüden) ve çıkış çevresinden $R_C$.

## Detaylı Açıklamalar

- **Çözüm stratejisi.** Hoca her devrede iki çevre çizer. Birinci çevre $V_{CC}$'den baz direncine, baz-emetör eklemine ve emetör direncinden toprağa iner; bu çevrede tek bilinmeyen $I_B$ kalacak biçimde $I_E$ yerine $(\beta+1)I_B$, $I_C$ yerine $\beta I_B$ yazılır. İkinci çevre $V_{CC}$'den kolektör direncine, kolektör-emetör uçlarına ve emetör direncinden toprağa iner; $I_C$ bilindiği için buradan $V_{CE}$ çekilir. Bu iki denklem bilindiğinde soruların tamamı yerine koyma işlemine dönüşür.
- **$\beta$ ve akım bağıntıları.** Bir öğrencinin sorusu üzerine hoca $\beta$'nın $I_C/I_B$ oranı, yani giriş (baz) akımının çıkışta kaç kat güçlendiğini gösteren, transistöre özgü bir parametre olduğunu tekrarladı. $I_E = I_C + I_B = (\beta+1)I_B$ ifadesinde $\beta = 50$ iken $I_C = 50 I_B$, $I_E = 51 I_B$ olur; fark küçük olduğu için çoğu çözümde $I_E \approx I_C$ kabul edilir. Yine de giriş çevresinde gerçekçi olması için $(\beta+1)$ ile yazılır.
- **Nokta gerilimleri.** $V_C$ gibi tek indisli gerilimin ikinci ucu gizli bir topraktır: $V_C = V_C - V_{\text{toprak}}$. Emetör doğrudan toprakta ise $V_E = 0$, $V_B = V_{BE} = 0{,}7$ V ve $V_C = V_{CE}$ olur. Emetörde direnç varsa $V_E = I_E R_E$, $V_B = V_E + 0{,}7$ V, $V_C = V_{CC} - I_C R_C$ ya da $V_C = V_{CE} + V_E$ bulunur. $V_{BC} = V_B - V_C$ farkının negatif çıkması, baz-kolektör ekleminin ters kutuplu olduğunu, yani transistörün doğrusal yükseltme için doğru bölgede olduğunu gösterir (slayt açıklaması, ekrandan, 00:05:00).
- **Gerilim bölücü ve Thevenin eşdeğeri.** $R_1$ ile $R_2$'nin orta noktası baza bağlıdır. Bir öğrencinin Thevenin kısmını sorması üzerine hoca bölücü formülünü baştan çıkardı: bölücüde baz akımı ihmal edilince $R_1$ ve $R_2$'den aynı akım geçer, $I_1 = I_2$. $I_1 = (V_{CC} - V_B)/R_1$, $I_2 = V_B/R_2$ eşitlenirse $R_2 V_{CC} = V_B (R_1 + R_2)$ ve $V_B = \dfrac{R_2}{R_1 + R_2} V_{CC}$ çıkar (ekrandan, 00:35:00). Bu, Thevenin gerilimi $E_{Th}$'dir. Thevenin direnci için kaynak toprağa çekilmiş gibi düşünülür; iki direnç tabandan toprağa paralel kalır ve $R_{Th} = R_1 \parallel R_2$ olur. Böylece devre, $E_{Th}$ kaynağı ve $R_{Th}$ baz direnci olan emetör kararlı bir devreye dönüşür.
- **Kolektör geri beslemeli devre.** Baz direnci $V_{CC}$'ye değil kolektöre bağlıdır. $R_C$'den geçen akım $I_C' = I_C + I_B$'dir; $I_B$ çok küçük olduğu için $I_C' \approx I_C$ alınır (bu soruda $I_B$, $I_C$'nin 75'te biri kadardır). Giriş çevresi $V_{CC}$'den $R_C$'ye, oradan $R_B$ (ya da seri $R_1 + R_2$) üzerinden baza, baz-emetöre ve $R_E$'ye iner: $V_{CC} = I_C' R_C + I_B R_B + V_{BE} + I_E R_E$. $I_C$ ve $I_E$ yerine $\beta I_B$ yazılınca $I_B = (V_{CC} - V_{BE})/[R_B + \beta(R_C + R_E)]$ çıkar. $R_1$-$R_2$ ortasındaki kondansatör DC'de açık devre olduğu için iki direnç seri sayılır.
- **Tasarım sorusu.** Akım ve $V_{CE}$ verilip direnç istendiğinde sıra tersine döner. $V_E \approx I_C R_E$ ile emetör gerilimi, $V_B = V_E + 0{,}7$ V ile baz gerilimi bulunur. Bölücü formülünde tek bilinmeyen $R_1$ kaldığı için $3{,}1 = \dfrac{18\text{ k}\Omega}{R_1 + 18\text{ k}\Omega}\cdot 18$ V'tan $R_1 = 86{,}52$ kΩ elde edilir. $R_C$ çıkış çevresinden $18 = (2\text{ mA})(R_C + 1{,}2\text{ k}\Omega) + 10$ ile $R_C = 2{,}8$ kΩ bulunur; aynı sonuç $V_C = 12{,}4$ V ve $R_C = (18 - 12{,}4)/2\text{ mA}$ ile de doğrulanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
