# Ders 5 Çalışma Özeti

## Genel Konular

- PN eklemi (p-n junction) ve tükenme bölgesi
  - Silisyum ya da germanyum kristalin bir ucu p tipi, diğer ucu n tipi katkılanınca PN eklemi oluşur (ekrandan, 00:10:00). Diyotun temel yapısı budur.
  - P tipi malzemede hareketli pozitif yükler (delikler), n tipi malzemede hareketli negatif yükler (fazla elektronlar) çoğunluktadır.
  - İki malzeme birleşince eklem çevresinde yüklerin göçüyle bir geçiş bölgesi oluşur. Buna depletion region, Türkçede tükenme bölgesi denir; uzay yükü katmanı (space charge layer) olarak da geçer.
  - Bir yönde pozitif, öbür yönde negatif yükün yayılması bir yük dengesizliği üretir. Bu da eklem boyunca bir potansiyel bariyeri ($V_b$) doğurur (ekrandan, 00:15:00). Potansiyel n tarafında yüksek, p tarafında düşüktür.
- Eklemdeki üç durum: yalıtılmış eklem, ileri kutuplama, ters kutuplama (ekrandan, 00:20:00)
  - Yalıtılmış eklem (isolated junction): dışarıdan gerilim yoktur, bariyer sabittir.
  - İleri kutuplama (forward bias): p tarafına artı, n tarafına eksi verilir. Tükenme bölgesi daralır, bariyer düşer, çoğunluk taşıyıcıları geçer ve akım akar.
  - Ters kutuplama (reverse bias): p tarafına eksi verilir. Tükenme bölgesi genişler, bariyer yükselir. Yalnız azınlık taşıyıcılarından gelen çok küçük bir ters akım akar.
- Diyot akım-gerilim bağıntısı ve karakteristik eğri
  - Oda sıcaklığında $e/kT \approx 40\ \text{V}^{-1}$ alınır (ekrandan, 00:25:00).
  - $V > +0.1$ V için $I \approx I_s\,\exp\!\left(\frac{eV}{kT}\right) = I_s\,\exp(40V)$; $V < -0.1$ V için $I \approx I_s(0-1) = -I_s$ (ekrandan, 00:25:00).
  - $I_s$ ters doyma akımıdır (reverse saturation current), mikroamper düzeyindedir.
  - İdeal diyotta $V_D$ sıfırı epsilon kadar geçince akım akar. Gerçek diyotta önce bariyeri aşacak gerilim verilmelidir: silisyumda yaklaşık 0,7 V, germanyumda 0,3 V, galyum arsenitte yaklaşık 1,2 V.
- Diyotun üç çalışma koşulu
  - Kutuplama yok (no bias): $I_D = 0$ mA.
  - Ters kutuplama: diyot açık devre gibidir, yalnız $I_s$ kadar ters akım vardır.
  - İleri kutuplama: bariyer geriliminden sonra diyot iletir.
- Zener bölgesi (ekrandan, 00:30:00)
  - Ters gerilim çok büyürse diyot kırılır (breakdown) ve ters akım birden artar. Karakteristiğin bu kısmına Zener bölgesi, kırılmanın başladığı gerilime Zener gerilimi ($V_Z$) denir.
  - Diyotu Zener bölgesine sokmayan en büyük ters gerilime tepe ters gerilim (peak inverse voltage ya da peak reverse voltage, PIV/PRV) denir.
- Sıcaklık ve direnç seviyeleri
  - Sıcaklık diyota enerji verir ve gereken ileri kutuplama gerilimini düşürür; bu kararlı çalışmayı bozar.
  - Diyotun iç direnci DC ve AC için ayrı hesaplanır. Karakteristik eğride iki nokta arasındaki eğimin tersi direnci verir: $r_{av} = \Delta V_d / \Delta I_d$ (noktadan noktaya) (ekrandan, 00:35:00).
  - Ters kutuplama bölgesinde $r'_d = \infty$ kabul edilir; diyot açık devre gibidir (ekrandan, 00:35:00).
- Diyot eşdeğer devresi, sembolü ve paketleri
  - Gerçek diyot: ideal diyot + 0,7 V bariyer gerilimi + iç direnç, seri bağlı.
  - Sembolde halka (çizgi) olan uç katottur (n tipi, eksi), diğer uç anottur (p tipi, artı).
  - Paket türleri: düşük akımlı silindir gövdeli diyotlar, büyük akım ve güç uygulamaları için iri diyotlar, PCB yüzeyine monte edilen (yüzey montaj) diyotlar.
- Diyot testi
  - Multimetre direnç konumundayken kırmızı uç anoda, siyah uç katoda konunca düşük direnç, ters bağlanınca yüksek direnç okunmalıdır. Aksi durumda diyot bozuktur.
  - Eğri çiziciler (curve tracer) farklı gerilimler uygulayıp akım-gerilim karakteristiğini nokta nokta çizer.
- Diğer diyot türleri (ekrandan, 00:40:00)
  - Normal diyot, Zener diyot, ışık yayan diyot (LED), diyot dizileri.
  - Zener diyot ters bağlanarak kullanılır; kırılma gerilimi üretimde malzemeyle ayarlanır (örneğin 1,8 V, 3,6 V, 5 V, 12 V). Yaygın aralık 1,8 V ile 200 V arasıdır. Sembolünde uçlar kırık çizilir.
  - LED ileri kutuplanınca foton yayar; ışık kızılötesi ya da görünür bölgede olabilir. İleri kutuplama gerilimi genellikle 2-3 V arasıdır (ekrandan, 00:45:00). Görünür ışık yaklaşık 400-700 nm aralığındadır. RGB LED'ler ekranlarda pikselleri oluşturur.
  - Diyot dizileri, çok sayıda diyotun tek bir entegre gövdede toplanmasıdır; ortak anotlu ve ortak katotlu olmak üzere ikiye ayrılır.
- Yük doğrusu ve çalışma noktası (ekrandan, 00:50:00)
  - Devre analizinde diyotun karakteristik eğrisi ile devrenin yük doğrusu (load line) kesiştirilir. Kesişim noktası Q noktasıdır (çalışma noktası); $I_{D_Q}$ ve $V_{D_Q}$'yu verir.
  - Yük doğrusunda en büyük akım $E/R$, en büyük diyot gerilimi $E$'dir.
- Seri ve paralel diyot devreleri
  - İleri kutuplanmış seri devrede silisyum diyotun üzerine 0,7 V düşer (germanyumda 0,3 V, idealde 0 V); kalan gerilim dirence düşer ve $I_D = I_R$, $V_R = I_R R$ olur.
  - Ters kutuplamada diyot açık devredir: $I_D = I_R = 0$, $V_R = 0$, uygulanan gerilimin tamamı diyotun uçlarına düşer.
  - Paralel diyot örneği (ekrandan, 01:05:00): $E = 10$ V, $R = 0{,}33$ kΩ, iki özdeş Si diyot. $V_{D1} = V_{D2} = V_o = 0{,}7$ V, $V_R = 9{,}3$ V, $I_R = (10 - 0{,}7)/0{,}33\ \text{k}\Omega = 28$ mA, $I_{D1} = I_{D2} = 14$ mA.
- AC'den DC'ye dönüşüm ve doğrultucular
  - Elektronik cihazlar DC ile çalışır. Adaptörler şebekedeki 220 V AC'yi DC'ye çevirir. İlk adım doğrultmadır (rectification); kalan dalgalanma sonra kondansatörlerle ve başka devrelerle düzeltilir.
  - Yarım dalga doğrultucu (half-wave): pozitif yarı periyotta diyot iletir, $v_o = v_i$; negatif yarı periyotta açık devredir, $v_o = 0$ (ekrandan, 01:15:00). DC çıkış $V_{dc} = 0{,}318\,V_m$.
  - Tam dalga doğrultucu (full-wave): negatif yarı periyot da pozitife çevrilir. $V_{dc} = 0{,}636\,V_m$ (ekrandan, 01:20:00).
  - Köprü doğrultucu (bridge rectifier): dört diyot köprü biçiminde bağlıdır. Her yarı periyotta iki diyot iletir, ikisi kesimdedir; akım yükten her iki yarı periyotta aynı yönde geçer (ekrandan, 01:35:00).
  - Orta uçlu transformatörlü tam dalga doğrultucu da vardır; derste ayrıntısına girilmedi.
- Diyot kırpıcılar (clippers)
  - Girişe sinüs, sıfır ortalamalı kare dalga ya da üçgen dalga gibi AC işaretler uygulanabilir.
  - Diyot devreye seri bağlıysa seri kırpıcı adını alır. İdeal diyotla işaretin pozitif kısmı geçer, negatif kısmı kesilir; bu aslında yarım dalga doğrultucudur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bariyer gerilimleri hesaplarda kullanılacak
  - Silisyum 0,7 V, germanyum 0,3 V, galyum arsenit yaklaşık 1,2 V. Bu gerilim aşılmadan diyottan akım akmaz.
- İleri ve ters kutuplamada tükenme bölgesinin davranışı
  - İleri kutuplamada tükenme bölgesi daralır, bariyer düşer; ters kutuplamada genişler, bariyer yükselir. Diyotun iletip iletmemesi buna dayanır.
- Diyot bir enerji kaynağı değildir
  - Diyot pil gibi tükenmez; potansiyel bariyeri aşılınca direnci düşüp akımı geçiren bir elemandır. Yarı iletkenler uzun ömürlüdür; genellikle çalışma sınırları dışındaki gerilimlerle yanarak bozulur.
- Paralel diyotlarda akımın eşit bölünmesi
  - Ana koldaki 28 mA, diyotlar özdeş olduğu için 14 mA ve 14 mA olarak ikiye ayrılır. Özdeşlik şartı önemlidir.
- Doğrultucuların DC seviyeleri
  - Yarım dalgada $0{,}318\,V_m$, tam dalgada bunun iki katı $0{,}636\,V_m$. Gerçek diyotla yarım dalgada bir, köprü doğrultucuda iki diyot gerilimi (2 × 0,7 V) hesaba katılmalıdır.
- Diyotların önemi
  - Akımı geçiren ya da kesen bir anahtar gibi, LED'lerde, doğrultucularda, koruma devrelerinde ve dalga şekli üzerinde oynayan kırpıcı devrelerde kullanılır. Transistörler diyotun daha karmaşık bir halidir.

## Kısa Tekrar Notları

- PN eklemi = diyot. Eklemde tükenme bölgesi ve potansiyel bariyeri oluşur.
- İleri kutuplama: bölge daralır, akım akar. Ters kutuplama: bölge genişler, yalnız $I_s$ akar.
- $I \approx I_s \exp(40V)$ ($V > 0{,}1$ V), $I \approx -I_s$ ($V < -0{,}1$ V).
- Eşik: Si 0,7 V, Ge 0,3 V, GaAs ≈ 1,2 V.
- Zener bölgesi: büyük ters gerilimde kırılma; $V_Z$ Zener gerilimi, PIV Zener bölgesine girmeyen en büyük ters gerilim.
- Ters kutuplamada $r'_d = \infty$; ortalama AC direnç $r_{av} = \Delta V_d/\Delta I_d$.
- Gerçek diyot eşdeğeri: ideal diyot + 0,7 V + iç direnç.
- Diyot türleri: normal, Zener, LED (2-3 V), diyot dizileri (ortak anot / ortak katot).
- Q noktası: karakteristik eğri ile yük doğrusunun kesişimi; yük doğrusu $E/R$ ve $E$ noktalarından geçer.
- Paralel örnek: 10 V, 0,33 kΩ, iki Si diyot → 28 mA, her diyotta 14 mA.
- Yarım dalga $V_{dc} = 0{,}318\,V_m$; tam dalga (köprü) $V_{dc} = 0{,}636\,V_m$.
- Köprü doğrultucuda her yarı periyotta iki diyot iletir.
- Seri kırpıcı ideal diyotla yarım dalga doğrultucu gibi davranır.

## Detaylı Açıklamalar

- PN ekleminin fiziği
  - P ve N tipi malzemeler, saf yarı iletkene (silisyum, germanyum, galyum arsenit) çok küçük miktarda farklı atomlar katılarak elde edilir. P tipinde delik, N tipinde elektron fazlalığı vardır. İki malzeme birleştirilince eklemin iki yanında yükler birbirini çeker ve iter; p tarafında eklem yakınında negatif, n tarafında pozitif yük birikir. Bu yük dağılımının integrali potansiyeli verir ve p tarafından n tarafına doğru yükselen bir potansiyel bariyeri oluşur (ekrandan, 00:15:00).
  - Dışarıdan ileri yönde gerilim verildiğinde gelen taşıyıcılar eklemdeki yükleri dengeler, bölge daralır ve bariyer $V$ kadar azalır. Ters yönde verildiğinde bölge genişler ve bariyer $V$ kadar artar (ekrandan, 00:20:00). Hoca bu konudaki Boltzmann sabiti ve sıcaklığa bağlı ayrıntılı hesaplara girmedi.
- İdeal ve gerçek diyot karakteristiği
  - İdeal diyotta $V_D = V_A - V_B$ negatifken akım akmaz (açık devre), $V_D$ sıfırı epsilon kadar geçince diyot kısa devre gibi davranır. Gerçek diyotta eğri 0,7 V civarında hızla yükselir, ters yönde ise mikroamper düzeyinde bir $I_s$ akımı vardır. Ters gerilim çok artarsa Zener bölgesinde ters akım çığ gibi yükselir.
  <!-- BELİRSİZ: Hoca GaAs eşik gerilimini önce "1,3 yanlış hatırlamıyorsam" dedi (00:24:49), ekrana da elle 1,3 yazdı; sonra slayttan 1,2 V okudu (00:32:16). Notta slayttaki 1,2 V kullanıldı. -->
- Paralel diyot örneğinin çözümü (ekrandan, 01:05:00)
  - Devrede 10 V kaynak, 0,33 kΩ seri direnç ve buna paralel iki özdeş silisyum diyot vardır. 10 V, 0,7 V eşiğini aştığı için iki diyot da iletir. Paralel uçlar arasındaki gerilim eşittir: $V_{D1} = V_{D2} = V_o = 0{,}7$ V. Dirence kalan gerilim $V_R = 10 - 0{,}7 = 9{,}3$ V'tur. Ana kol akımı $I_R = I_1 = 9{,}3\ \text{V} / 0{,}33\ \text{k}\Omega \approx 28$ mA (tam değer 28,18 mA). Diyotlar özdeş olduğu için $I_{D1} = I_{D2} = 28/2 = 14$ mA olur.
- Yarım dalga doğrultucunun çalışması
  - Girişe $v_i$ sinüs işareti uygulanır, çıkış seri diyottan sonraki direncin üzerinden alınır. Pozitif yarı periyotta ($0$ ile $T/2$ arası) ideal diyot kısa devredir ve $v_o = v_i$ olur. Negatif yarı periyotta diyot ters kutuplanır, açık devre olur ve $v_o = 0$ V'tur (ekrandan, 01:15:00). Sıfır ortalamalı sinüs böylece pozitif ortalamalı bir işarete dönüşür. Bu ortalama $0{,}318\,V_m$'dir; örneğin $V_m = 10$ V ise yaklaşık 3,18 V olur.
- Köprü doğrultucunun çalışması
  - Pozitif yarı periyotta D2 ve D3 iletir, D1 ve D4 ters kutuplandığı için kesimdedir (ekrandan, 01:35:00). Negatif yarı periyotta roller değişir ve D1 ile D4 iletir. Her iki durumda da yükün aynı ucu daha yüksek potansiyelde kaldığı için negatif yarı periyot çıkışta pozitif görünür. Böylece alan iki katına çıkar ve $V_{dc} = 0{,}636\,V_m$ olur.
  - Kesimdeki diyotun neden iletmediği: akım dirençten geçerken gerilim kaybeder; direncin çıkış ucundaki potansiyel hâlâ giriş ucunun potansiyelinden düşük olduğu için oraya bağlı diyot ters kutuplu kalır.
- Seri kırpıcı
  - Seri diyotlu devreye kare dalga uygulanınca pozitif kısımlar geçer, negatif kısımlar kesilir. Üçgen dalga uygulanınca da üçgenin pozitif olduğu yerler geçer. Hoca, sonraki adımda devreye DC kaynaklar eklenmiş farklı kırpıcı bağlantılarının örnekler üzerinden inceleneceğini söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
