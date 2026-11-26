# Ders 20 Çalışma Özeti

## Genel Konular

- BJT'den FET'e geçiş
  - Standart transistörler NPN ve PNP yapılı bipolar jonksiyon transistörlerdir (BJT). Bu derste daha gelişmiş bir teknoloji olan alan etkili transistörlere (Field Effect Transistor, FET) geçilir.
  - Benzerlikler: ikisi de yükseltme (güçlendirme) yapar, ikisi de anahtarlama elemanı olarak lojik 0-1 geçişlerinde kullanılır, ikisi de empedans uydurma devrelerinde kullanılır.
  - En önemli fark: BJT akım kontrollü bir elemandır ($I_C = \beta I_B$), FET ise gerilim kontrollü bir elemandır (çıkış akımı $I_D$, $V_{GS}$ gerilimiyle denetlenir).
  - BJT'lerle daha büyük gerilim kazançları elde edilebilir. FET'ler sıcaklık değişimlerine daha az duyarlıdır ve tümleşik devre (çip) yapımında daha kolay gerçeklenir; buna karşılık statik elektriğe BJT'lerden daha duyarlıdır.
- FET'lerin sınıflandırılması (ekrandan, 00:15:00)
  - JFET: Junction FET (eklem FET).
  - MOSFET: Metal-Oxide-Semiconductor FET. İkiye ayrılır: D-MOSFET (Depletion, kanal ayarlamalı) ve E-MOSFET (Enhancement, kanal oluşturmalı).
  - Üç yapının her biri n kanallı ya da p kanallı olabilir; toplam 6 tip FET vardır.
- JFET yapısı ve uçları (ekrandan, 00:20:00)
  - Ortadan kesilmiş bir silindir gibi düşünülür: n kanallı JFET'te ana blok (kanal) n tipidir, etrafına içeri doğru bir miktar nüfuz eden p tipi bir kuşak sarılmıştır. p kanallıda tipler yer değiştirir.
  - Üç uç vardır: Drain (D, boşaltma; BJT'deki kolektöre karşılık gelir), Gate (G, kapı; baza karşılık gelir), Source (S, kaynak; emetöre karşılık gelir).
  - Slayttaki tanım: Drain ve Source n kanala, Gate p tipi malzemeye bağlıdır.
- JFET'in çalışması
  - Gate akımı sıfır kabul edilir ($I_G = 0$), çünkü gate girişi çok yüksek empedans gösterir. Her FET'te $I_D = I_S$'dir.
  - Gate (p) ile kanal (n) arasındaki tüketim (depletion) bölgesi $V_{GS}$ ile genişletilip daraltılır; kanal daraldıkça $I_D$ azalır.
  - $V_{GS} = 0$ iken kanal en geniştir ve en büyük akım $I_{DSS}$ akar.
  - n kanallı JFET'te $V_{GS}$ negatif yapıldıkça kanal daralır; belli bir negatif gerilimde iki tüketim bölgesi birleşir ve akım kesilir. Bu gerilime kısılma (pinch-off) gerilimi $V_P$ denir. n kanallıda pozitif $V_{GS}$ kullanılmaz.
- JFET transfer eğrisi (ekrandan, 00:25:00 ve 00:30:00)
  - Slayttaki örnekte $I_{DSS} = 8$ mA, $V_P = -4$ V'tur; $V_{GS} = 0, -1, -2, -3, -4$ V için çıkış karakteristiğinin doyma akımları sol taraftaki $I_D$-$V_{GS}$ eğrisine taşınır.
  - Giriş-çıkış ilişkisi (Shockley denklemi): $I_D = I_{DSS}\left(1 - \dfrac{V_{GS}}{V_P}\right)^2$. $I_{DSS}$ ve $V_P$ transistöre özgüdür, değişken $V_{GS}$'dir.
- p kanallı JFET (ekrandan, 00:40:00)
  - Kanal p tipi, kuşak n tipidir. Gerilim polariteleri ve akım yönleri tersine döner: $V_{GS}$ pozitif bölgede çalışır, $V_{GS}=0$'da $I_{DSS}$ akar, pozitif $V_P$'de akım kesilir.
  - Akım source'tan girip drain'den çıkar (n kanalda drain'den girip source'tan çıkıyordu).
- JFET sembolü (ekrandan, 00:35:00 ve 00:45:00)
  - Gate'teki ok n tipini gösterir: ok kanala doğru (içeri) ise n kanallı, dışarı doğru ise p kanallı JFET'tir. Bu, BJT'de emetör okunun malzeme tipini göstermesine benzer.
  - Slaytta örnek olarak p kanallı genel amaçlı 2N2844 JFET gösterilir: 1 Source, 2 Gate, 3 Drain (kılıf).
- D-MOSFET (kanal ayarlamalı) (ekrandan, 00:50:00 ve 00:55:00)
  - n kanallı yapıda ana gövde (substrate, SS) p tipidir. Drain ve source n katkılı bölgelere metal kontaklarla bağlanır, bu iki bölge hazır bir n kanalla birleştirilmiştir.
  - Gate kanala ince bir SiO$_2$ yalıtkan katmanla bağlıdır; bu yüzden gate'ten akım akmaz ($I_G = 0$).
  - Negatif $V_{GS}$ kanalı daraltır (tüketim kipi, depletion mode); pozitif $V_{GS}$ kanalı genişletir ve akım $I_{DSS}$'nin üstüne çıkar (zenginleştirme kipi, enhancement mode).
  - Denklemi JFET ile aynıdır: $I_D = I_{DSS}\left(1 - \dfrac{V_{GS}}{V_P}\right)^2$; fark, eğrinin $V_{GS}$'nin diğer polaritesine de uzayabilmesidir.
  - p kanallı D-MOSFET'te kanal p, gövde n tipidir; eğri aynalanır (ekrandan, 01:00:00).
- MOSFET sembolleri (ekrandan, 01:05:00)
  - Gövdeyi (SS) gösteren okun yönü kanal tipini verir: ok içeri ise n kanallı, dışarı ise p kanallıdır.
  - Gövde ayrı bir uç olarak ya da source'a bağlı olarak çizilebilir; daha çok source'a bağlı çizim kullanılır.
- E-MOSFET (kanal oluşturmalı) (ekrandan, 01:10:00)
  - Hazır bir kanal yoktur; kanal uygulanan $V_{GS}$ ile oluşturulur.
  - n kanallı E-MOSFET'te p tipi gövdede n kanal oluşturmak için pozitif $V_{GS}$ gerekir. $V_{GS}$, eşik (threshold) gerilimi $V_T$'yi geçene kadar akım sıfırdır; sonra $V_{GS}$ arttıkça $I_D$ artar.
  - Denklem: $I_D = k\,(V_{GS} - V_T)^2$, $k$ transistöre özgü bir sabittir.
  - Sembolde kanal kesikli çizgiyle gösterilir: kanal henüz oluşmamıştır.
  - p kanallı E-MOSFET'te kanal negatif $V_{GS}$ ile oluşturulur.
- Özet tablo (ekrandan, 01:15:00)
  - n-JFET, n kanallı D-MOSFET ve n kanallı E-MOSFET için $I_G = 0$, $I_D = I_S$; ilk ikisinin parametreleri $I_{DSS}$ ve $V_P$, sonuncusunun $V_T$ (ya da $V_{GS(Th)}$), $I_{D(on)}$, $V_{GS(on)}$'dur.
  - E-MOSFET için $k = \dfrac{I_{D(on)}}{(V_{GS(on)} - V_{GS(Th)})^2}$.
- CMOS ve MOS yapıları
  - MOS yapıları elektronik etkilere çok duyarlıdır ve sürekli geliştirilmektedir (CMOS gibi). CMOS lojik tasarımda daha yüksek giriş empedansı, daha hızlı 0-1 geçişleri, daha düşük çalışma gerilimi ve daha kararlı çalışma sağlar.

## Hocanın Özellikle Vurguladığı Kısımlar

- BJT ile FET arasındaki temel fark
  - BJT akım kontrollü, FET gerilim kontrollüdür. Hoca bunu "aklınızda tutacağınız en önemli fark" diye vurguladı.
- Giriş-çıkış denklemi
  - JFET için $I_D$ ile $V_{GS}$ arasındaki ilişki doğrusal değildir; $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ denkleminin bilinmesi gerektiği vurgulandı.
- $I_G = 0$ kabulü
  - BJT'de $I_B$ hesaplanırken FET'lerde gate akımı daima sıfır kabul edilir; kontrol parametresi $V_{GS}$'dir.
- Üç n tipi karakteristiğin bilinmesi
  - n-JFET, n kanal ayarlamalı ve n kanal oluşturmalı MOSFET karakteristiklerinin ve hangi yöne gittiklerinin bilinmesi gerektiği söylendi. p tipleri bunların aynalanmışıdır.
  - Hocanın özeti: n-JFET ve n kanallı D-MOSFET eğrileri negatif bölgeden başlayıp sağa doğru yükselir; n kanallı E-MOSFET eğrisi ise pozitif bölgeden, $V_T$'den başlar.
- Mode ve type adlandırmasının karışmaması
  - D-MOSFET'in eğrisindeki "depletion mode" ve "enhancement mode" bölgeleri, MOSFET türleri olan "D-type" ve "E-type" ile aynı adları taşır ama farklı kavramlardır.

## Kısa Tekrar Notları

- FET = gerilim kontrollü; BJT = akım kontrollü.
- Uç eşlemesi: Gate ↔ Base, Drain ↔ Collector, Source ↔ Emitter.
- Her FET'te $I_G = 0$, $I_D = I_S$.
- JFET ve D-MOSFET: $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$.
- E-MOSFET: $I_D = k(V_{GS} - V_T)^2$, $V_{GS} < V_T$ iken $I_D = 0$.
- n-JFET: $V_P \le V_{GS} \le 0$ aralığında çalışır; $V_{GS}=0$'da $I_D = I_{DSS}$, $V_{GS}=V_P$'de $I_D = 0$.
- D-MOSFET: $V_{GS} < 0$ tüketim kipi, $V_{GS} > 0$ zenginleştirme kipi.
- E-MOSFET: kanal yoktur, $V_{GS}$ ile oluşturulur; sembolde kanal kesikli çizilir.
- Ok yönü: içeri = n kanal, dışarı = p kanal.
- p kanallı elemanlarda polariteler ve akım yönleri ters, eğriler aynalanmış.

## Detaylı Açıklamalar

- BJT'de çıkış akımı giriş akımının doğrusal bir katıdır: $I_C = \beta I_B$. FET'te ise girişte bir akım yoktur ($I_G = 0$); çıkış akımı $I_D$, gate ile source arasına uygulanan $V_{GS}$ gerilimiyle denetlenir ve ilişki doğrusal değil kareseldir. Bu yüzden FET'ler gerilim kontrollü eleman olarak anılır.
- n kanallı JFET'te gate p tipi kuşağa, drain ve source n tipi kanalın iki ucuna bağlıdır. Gate-source arasındaki p-n eklemi ters kutuplandıkça (n kanalda $V_{GS}$ negatif yapıldıkça) tüketim bölgesi genişler ve kanalın akım geçirebilen kısmı daralır. Hoca bunu iki parmak ucunun birleşmesine (İngilizce *pinch*) benzetti: tüketim bölgeleri ortada birleştiğinde akım kesilir; bu andaki $V_{GS}$ değeri kısılma gerilimi $V_P$'dir.
- Slayttaki JFET transfer eğrisi örneğinde $I_{DSS} = 8$ mA ve $V_P = -4$ V'tur (ekrandan, 00:25:00). Shockley denklemiyle $V_{GS} = -1$ V için $I_D = 8(1 - 1/4)^2 = 4{,}5$ mA, $V_{GS} = -2$ V için $2$ mA, $V_{GS} = -3$ V için $0{,}5$ mA, $V_{GS} = -4$ V için $0$ bulunur; bunlar slayttaki eğri noktalarıyla uyumludur (python ile kontrol edildi). Sağdaki $I_D$-$V_{DS}$ eğrilerinde her $V_{GS}$ için akım belli bir $V_{DS}$'den sonra sabitlenir; bu doyma değerleri soldaki transfer eğrisini oluşturur.
- p kanallı JFET'te her şey tersine döner: $V_{GS}$ pozitif bölgede çalışır, pozitif gerilim arttıkça kanal daralır ve pozitif bir $V_P$'de akım kesilir. Akım source'tan girip drain'den çıkar.
- D-MOSFET'te p tipi gövde içinde drain ve source'u birleştiren hazır bir n kanal vardır; gate bu kanaldan ince SiO$_2$ katmanla yalıtılmıştır. Negatif $V_{GS}$ kanaldaki taşıyıcıları iterek kanalı daraltır; pozitif $V_{GS}$ ise kanala ek elektron çekerek onu genişletir. Böylece JFET'ten farklı olarak $V_{GS} > 0$ bölgesine geçilip $I_{DSS}$'den büyük akımlar elde edilebilir. Slayttaki p kanallı D-MOSFET örneğinde $I_{DSS} = 6$ mA, $V_P = +6$ V'tur ve eğri $V_{GS} = -1$ V'a kadar uzanır (ekrandan, 01:00:00).
- E-MOSFET'te başlangıçta kanal yoktur. n kanallı yapıda gate'e pozitif gerilim verildiğinde p tipi gövdedeki elektronlar yalıtkanın altına toplanır ve $V_{GS}$ eşik gerilimini geçince ince bir n kanal oluşur. Bundan sonra $V_{GS}$ arttıkça kanal kalınlaşır ve $I_D = k(V_{GS} - V_T)^2$ ile artar. Slayttaki örnekte $V_T = 2$ V'tur (ekrandan, 01:10:00).
- Özet tablodaki JFET eğrisinde iki pratik nokta işaretlidir: $V_{GS} = V_P/2$ için $I_D = I_{DSS}/4$, $V_{GS} = 0{,}3V_P$ için $I_D \approx I_{DSS}/2$ (ekrandan, 01:15:00). Bunlar denklemden doğrudan çıkar: $(1 - 0{,}5)^2 = 0{,}25$ ve $(1 - 0{,}3)^2 = 0{,}49$.
- Ders sonrası not: Hoca $I_D$-$V_{GS}$ ilişkisini birkaç kez "eksponansiyel" diye andı; doğrusu ilişkinin karesel (kare yasası) olmasıdır, denklemlerdeki üs 2'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
