# Ders 24 Çalışma Özeti

## Genel Konular

- Oturumun niteliği
  - Bu kayıt bir laboratuvar uygulama oturumudur (MOSFET laboratuvarı). Konu anlatımı yalnız laboratuvar sorularının açıklanması ve öğrenci sorularının cevaplanması sırasında yapılır. Devreler Proteus simülasyon programında kurulur.
- CMOS (tamamlayıcı MOS) lojik
  - CMOS bir transistör tipi değil, bir konfigürasyonun adıdır: aynı devrede hem PMOS hem NMOS transistör bulunur (complementary logic). Bu konfigürasyonla lojik kapılar tasarlanır.
  - CMOS teknolojisinde iki tip transistör ayrı ayrı değil, tek bir yapı üzerinde birlikte üretilir. Telefonlardaki işlemciler gibi küçük boyutlu sistemlerin mümkün olmasının en büyük sebeplerinden biri budur.
  - Bu laboratuvarda MOSFET'in en basit modeli kullanılır: transistör bir anahtardır (on/off). $V_{GS}$, eşik gerilimi ($V_T$), body etkisi gibi ayrıntılarla hesap yapılmaz.
- CMOS evirici (NOT kapısı)
  - Devrede bir PMOS (üstte, beslemeye bağlı) ve bir NMOS (altta, toprağa bağlı) vardır. İki gate birleşip girişi, iki drain birleşip çıkışı oluşturur (ekrandan, 02:25:00).
  - Devrede iki kaynak vardır: giriş işareti ve DC besleme ($V_{DD}$, Proteus'ta "Vsource"). Besleme ve toprak, çıkışta hangi değerin görüleceğini belirler.
  - Giriş sinyali çıkışa doğrudan "terslenerek" aktarılmaz. Transistörlerin açılıp kapanmasına göre çıkış ya beslemeye ya toprağa bağlanır; böylece girişin tersi elde edilir.
  - Giriş en düşük değerdeyken hangi transistörün off, hangisinin on olduğu ve on olanın çıkışa ne verdiği; giriş en yüksek değerdeyken aynı soru: bu, eviricinin çalışma mantığıdır.
- Gerilim transfer karakteristiği (VTC), $V_{OL}$ ve $V_{OH}$
  - $V_{OL}$ (output low voltage): girişe maksimum gerilim uygulandığında çıkışta görülen minimum gerilim. $V_{OH}$ (output high voltage): girişe minimum gerilim uygulandığında çıkışta görülen maksimum gerilim.
  - Çıkışın bu iki değer arasında gidip gelmesine "logic swing" denir. Çıkış tam olarak 0'a ve tam olarak beslemeye ulaşmayabilir; ölçüm bu sınırı tespit etmek içindir.
  - $V_{OL}$ çok küçük (mikrovolt düzeyi ya da daha küçük) olduğundan voltmetrenin ölçme aralığı mikrovolta alınmalıdır. $V_{OH}$ için volt aralığı yeterlidir.
- Kare dalga (pulse) kaynağının parametreleri
  - En düşük gerilim, en yüksek gerilim (bu laboratuvarda 5 V), başlama zamanı (gecikme), yükselme zamanı (rise time), düşme zamanı (fall time), darbe genişliği (pulse width, 1 s) ve periyot.
  - Yükselme ve düşme zamanı sıfır değilse kare dalganın kenarları dik değil eğimli olur.
- PMOS ve NMOS sembollerini ayırt etme
  - Elle çizimde PMOS'un gate tarafına içi boş küçük bir daire (bubble) konur; NMOS'ta bu daire yoktur. Bu, lojik devrelerde eviricinin çıkışındaki daireye benzer.
  - Simülasyon programlarında daire konmayabilir. O zaman ok işaretine bakılır. Dört bacaklı sembolde (bu laboratuvardaki elemanlar) ortadaki body bacağındaki ok içeri doğruysa NMOS, dışarı doğruysa PMOS'tur. Üç bacaklı sembolde alttaki bacağın okuna bakılır. <!-- BELİRSİZ: üç bacaklı sembol için ok yönü kuralı altyazıda net söylenmiyor ("aşağı yönlü bir akış olması lazım") -->
  - MOSFET'in aslında dört ucu vardır (gate, drain, source, body). Simülasyonda body ucu içeride bağlanmış, üç uçlu kullanılan sürüm seçilmiştir.
- Bilinmeyen iki girişli CMOS kapının analizi
  - Verilen devrede önce PMOS ve NMOS'lar belirlenir, sonra açıkta kalan uçların giriş, çıkış, besleme ya da toprak olduğuna karar verilir.
  - İki giriş için dört durum (giriş gerilimi kombinasyonu) uygulanır, çıkış voltmetreyle okunur ve doğruluk tablosu doldurulur. Kapının adı bu verilere dayanarak gerekçelendirilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- PMOS ile NMOS'u karıştırmak
  - Çıkışta lojik 0 beklenen durumda 4 V gibi bir değer görülmesi devrenin yanlış kurulduğunu gösterir. Bu oturumdaki hataların hepsi, internetteki referans devreden eleman alırken PMOS ve NMOS'un yer değiştirmesinden kaynaklandı.
  - Elektronik dersini bitiren biri iki transistör sembolünü görünce hangisinin PMOS, hangisinin NMOS olduğunu söyleyebilmelidir.
- Çıkışı prob ile değil voltmetre ile ölçmek
  - $V_{OL}$/$V_{OH}$ ölçümünde çıkışa voltmetre konur; prob grafiği çizmek içindir. Küçük değer mikrovolt aralığında okunur.
- Giriş sinyalinin çıkışa doğrudan geçtiği düşünülmemeli
  - Çıkıştaki değer transistörlerin anahtarlamasıyla besleme ya da topraktan seçilir.
- Lojik kaynak değil analog kaynak
  - Girişte lojik durum (logic state) kaynağı değil, analog kaynak (kare dalga ya da DC gerilim) kullanılır.

## Kısa Tekrar Notları

- CMOS = aynı devrede PMOS + NMOS; transistör tipi değil konfigürasyon adı.
- CMOS evirici: PMOS üstte ($V_{DD}$'ye), NMOS altta (toprağa); gate'ler giriş, drain'ler çıkış.
- Giriş düşük → PMOS on, NMOS off → çıkış ≈ $V_{DD}$. Giriş yüksek → NMOS on, PMOS off → çıkış ≈ 0. (Derste öğrencilere bırakıldı, derste verilmedi.)
- $V_{OL}$: giriş maksimumken çıkış minimumu; $V_{OH}$: giriş minimumken çıkış maksimumu; aradaki salınım logic swing.
- $V_{OL}$ ölçümü için voltmetre aralığı mikrovolt.
- Pulse kaynağı: düşük/yüksek gerilim, başlama zamanı, rise/fall time, pulse width, periyot.
- Sembol: PMOS'ta gate tarafında daire; dört bacaklı simülasyon sembolünde body okunun yönü (içeri NMOS, dışarı PMOS).
- MOSFET dört uçludur; body ucu simülasyonda içeride bağlı olabilir.

## Detaylı Açıklamalar

Bu oturum MOSFET laboratuvarıdır. Laboratuvar iki sorudan oluşur. Birinci soru bir sentez sorusudur: sıfırdan transistör kombinasyonu icat etmek değil, CMOS teknolojisiyle bilinen bir lojik kapıyı (evirici) kurmak istenir. Önce devre elle çizilir; giriş gerilimi, çıkış gerilimi, DC besleme ve toprak üzerinde gösterilir. Sonra aynı devre Proteus'ta kurulur, beslemeye ve toprağa bağlanır, giriş ve çıkışa gerilim probları konur. Ardından girişe kare dalga verilir. Bunun amacı sürekli değişen bir işaretle kapının görevini yaptığını göstermektir. Kare dalga kaynağının özelliklerinde en düşük ve en yüksek gerilim, başlama zamanı, yükselme ve düşme zamanı, darbe genişliği ve periyot ayarlanır. Yükselme zamanı kenarın ne kadar dik olduğunu, darbe genişliği işaretin lojik 1 seviyesinde ne kadar kaldığını, periyot da sıfırdan sıfıra geçen süreyi belirler.

Simülasyon için analog analiz grafiği (Analogue Analysis) kullanılır. Giriş ve çıkış probları grafiğe iz (trace) olarak eklenir; böylece giriş ve çıkış üst üste görülür ve eviricinin işlemi izlenir. Grafiğin yatay ekseni (simülasyon süresi) 0 ile 50 arasında ayarlanır; varsayılan süre kısa kaldığında grafikte anlamlı bir dalga görülmez (ekrandan, 02:25:00).

Sorunun yorum kısmında gerilim transfer karakteristiği kavramına geçilir. Girişe minimum gerilim uygulandığında çıkışta görülen maksimum gerilim $V_{OH}$, girişe maksimum gerilim uygulandığında çıkışta görülen minimum gerilim $V_{OL}$ olarak adlandırılır. Çıkış bu iki değer arasında salınır (logic swing) ve pratikte tam 0'a ya da tam beslemeye ulaşmayabilir. İstenen, iki uç girişte hangi transistörün on, hangisinin off olduğunu çizip açıklamak ve sonra bu teoriyi DC girişle uygulayıp $V_{OL}$ ile $V_{OH}$'yi voltmetreyle ölçmektir. Küçük değer için voltmetre aralığı mikrovolta alınmalıdır; bir öğrencinin düzeltilmiş devrede $10^{-17}$ mertebesinde bir değer görmesi, doğru kurulmuş eviricide $V_{OL}$'nin pratikte sıfır olduğunu gösterir.

İkinci soru bir analiz sorusudur. Uçları açıkta bırakılmış iki girişli bir CMOS devre verilir. Transistörlerin kodlarından ve ok işaretlerinden PMOS/NMOS ayrımı yapılır, açık uçların hangisinin giriş, çıkış, besleme ya da toprak olduğu belirlenir. Devre Proteus'ta kurulduktan sonra iki girişe dört farklı gerilim kombinasyonu verilir, çıkış voltmetreyle okunur ve bir tabloya yazılır. Kapının hangi lojik işlemi yaptığı bu ölçümlere dayanarak açıklanır.

Oturum sırasında birçok öğrenci çıkışta 0 yerine 4–5 V gördü. Asistan bunun nedeninin PMOS ile NMOS'un yer değiştirmesi olduğunu açıkladı ve sembol okuma kuralını anlattı: elle çizimde PMOS'un gate tarafına bir daire konur; simülasyonda daire yoksa ok yönüne bakılır (üç bacaklı sembolde alt bacağın, dört bacaklı sembolde ortadaki body bacağının). Dört bacaklı sembolde ok içeri doğruysa NMOS, dışarı doğruysa PMOS'tur. MOSFET'in dört ucu vardır; kullanılan simülasyon elemanında body ucu içeride bağlıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
