# Ders 5 Çalışma Özeti

## Genel Konular

- Devre teorisi ile elektronik devreler arasındaki fark
  - Devre teorisi KCL, KVL ve Ohm kanunu gibi temel yasaları ve pasif devre elemanlarını (direnç, kondansatör, bobin) ele alır.
  - Elektronik devreler bu yasaların bilindiğini varsayar ve yarı iletken elemanların analizine geçer. Dersin kapsamındaki üç yarı iletken eleman diyot, transistör ve MOSFET'tir.
- Diyotun tanımı ve ideal diyot
  - Diyot iki terminalli (iki bacaklı) bir devre elemanıdır. İdeal olarak yalnız bir yönde iletir (ekrandan, 00:35:00).
  - Doğru polarmada ideal diyot kısa devre gibi davranır; akımı devrenin geri kalanı sınırlar. Ters polarmada açık devre gibi davranır, $I_D = 0$ olur.
  - Soruda aksi belirtilmedikçe diyot ideal kabul edilir.
- Yarı iletken malzemeler ve katkılama (doping)
  - Yarı iletken elemanlar silisyum (Si), germanyum (Ge) ve galyum arsenür (GaAs) ile üretilir.
  - Si ve Ge'nin elektriksel özellikleri, başka malzemeler eklenerek (doping, katkılama) değiştirilir. İki tip katkılı malzeme vardır: n-tipi (iletim bandı elektronu fazlası) ve p-tipi (valans bandı deliği fazlası) (ekrandan, 00:40:00).
- p-n eklemi ve tükenme bölgesi
  - p-tipi ve n-tipi malzeme birleştirilince n tarafındaki elektronlar eklemi geçerek p tarafındaki deliklere gider. Eklemin p tarafında negatif, n tarafında pozitif yük birikir ve eklem çevresinde tükenme bölgesi (depletion region) oluşur (ekrandan, 00:45:00).
  - Bu bölge yüklerin dengeye geldiği, potansiyel bir bariyer gibi davranan bölgedir. Diyotun tek yönlü iletimi bu bariyere dayanır.
- Üç polarma durumu
  - Polarmasız (no bias): dış gerilim yok, tükenme bölgesi dengededir, net akım yoktur.
  - Ters polarma (reverse bias): n tarafına artı, p tarafına eksi uç bağlanır. Tükenme bölgesi genişler, akım geçmez (ekrandan, 00:50:00).
  - Doğru polarma (forward bias): p tarafına artı, n tarafına eksi uç bağlanır. Tükenme bölgesi daralır ve kalkınca akım p'den n'ye doğru akar (akım yönü elektron hareketinin tersidir).
- Diyot denklemi ve gerçek karakteristik
  - Ekrandaki ifade: $I \approx I_s\left(e^{eV/kT}-1\right)$; oda sıcaklığında $e/kT \approx 40\ \text{V}^{-1}$. $V > +0{,}1$ V için $I \approx I_s e^{40V}$, $V < -0{,}1$ V için $I \approx -I_s$. $I_s$ ters doyma akımıdır (ekrandan, 00:55:00).
  - Gerçek diyotta doğru polarmada eşik (diz) gerilimine kadar akım çok küçüktür, eşikten sonra üstel olarak hızla artar. Ters polarmada mikroamper düzeyinde küçük bir ters akım akar (grafikte $-0{,}1\ \mu$A civarı) (ekrandan, 01:05:00).
  - Eşik gerilimleri: Ge için 0,3 V, Si için 0,7 V, GaAs için 1,2 V.
- Zener bölgesi ve zener diyot
  - Ters gerilim yeterince büyürse diyot kırılır (breakdown) ve ters akım birden artar. Diyotu zener bölgesine sokmayan en büyük ters gerilime tepe ters gerilimi (PIV/PRV), zener bölgesine sokan gerilime zener gerilimi ($V_Z$) denir (ekrandan, 01:10:00).
  - Zener diyot doğru polarmada normal diyot gibi, ters polarmada $V_Z$ aşılınca iletime geçen diyottur. Yaygın zener gerilimleri 1,8 V ile 200 V arasıdır (ekrandan, 01:25:00).
- Sıcaklık etkisi, diyot direnci ve eşdeğer devre
  - Sıcaklık arttıkça doğru polarma eşik gerilimi düşer (örneğin 0,7 V'tan 0,6 V civarına). Sıcaklıktan en çok etkilenen malzeme germanyumdur.
  - DC (statik) direnç $R_D = V_D / I_D$ ile bulunur.
  - Pratik diyot eşdeğer devresi: seri bağlı $V_K = 0{,}7$ V'luk bir kaynak, $r_{av} = 10\ \Omega$'luk bir direnç ve ideal diyot (ekrandan, 01:15:00).
- Diyot kapasitansı, ters toparlanma süresi ve veri sayfası
  - Diyotta yük birikmesinden doğan pikofarad düzeyinde bir kapasitans vardır, pratikte enerji depolamak için kullanılamaz.
  - Doğru polarmadan ters polarmaya geçilince diyot bir süre ters akım geçirir. Bu süreye ters toparlanma süresi (reverse recovery time) denir; hızlı anahtarlama yapan devrelerde bu yüzden dikkat gerekir.
  - Veri sayfalarında ileri gerilimin sıcaklık ve akımla değişimi, sıcaklığa göre en büyük akım, ters akım, kapasitans, ters toparlanma süresi ve çalışma sıcaklığı aralığı verilir.
- Diyot sembolü, uçları ve test yöntemleri
  - Anot artı, katot eksi uçtur. Diyot gövdesindeki şerit katodu gösterir.
  - Diyot testi üç yöntemle yapılır: diyot test cihazı (diode checker), ohmmetre ve eğri izleyici (curve tracer) (ekrandan, 01:20:00).
- Diğer diyotlar
  - LED (ışık yayan diyot), fotodiyot (opto diyot), diyot dizileri (örneğin yedi parçalı göstergeler).

## Hocanın Özellikle Vurguladığı Kısımlar

- İdeal diyot varsayımı
  - Soruda aksi belirtilmedikçe diyot idealdir: doğru polarmada kısa devre, ters polarmada açık devre. Soruda germanyum ya da silisyum diyot denirse eşik gerilimi hesaba katılmalıdır.
- Teori ile pratiğin ayrımı
  - Sıfır direnç ve sonsuz direnç teorik kavramlardır. Gerçek diyotta küçük bir iç direnç, bir eşik gerilimi ve küçük bir ters akım vardır.
- Anot ve katot
  - Anot artı, katot eksidir; sembolün çizgili tarafı katottur. Bu ezbere bilinmesi gereken bir noktadır ve karıştırılmamalıdır.
- Formüllerin ayrıntısı
  - Sızıntı akımı ve iç direnç formülleri ayrıntılı analizdir; bu derste ters polarmada diyot kesimdeymiş gibi düşünülür.
- Zener diyotun anlamı
  - Diyot donanımsal bir "if-else" gibidir; zener diyot ise iki eşikli bir "switch-case" yapısına benzetilir.

## Kısa Tekrar Notları

- İdeal diyot: doğru polarmada kısa devre, ters polarmada açık devre.
- Yarı iletken malzemeler: Si, Ge, GaAs. Katkılama ile n-tipi (fazla elektron) ve p-tipi (fazla delik) elde edilir.
- p-n eklemi tükenme bölgesi oluşturur. Ters polarma bölgeyi genişletir, doğru polarma daraltır.
- Akım p'den n'ye akar; akım yönü elektron hareketinin tersidir.
- Eşik gerilimleri: Ge 0,3 V, Si 0,7 V, GaAs 1,2 V.
- Diyot denklemi: $I \approx I_s(e^{eV/kT}-1)$, $e/kT \approx 40\ \text{V}^{-1}$.
- Zener diyot ters polarmada $V_Z$'de iletir; $V_Z$ yaygın olarak 1,8 V ile 200 V arasındadır.
- Sıcaklık artınca ileri eşik gerilimi düşer.
- Pratik model: $V_K = 0{,}7$ V + $r_{av} = 10\ \Omega$ + ideal diyot.
- Test: diode checker, ohmmetre (doğru yönde küçük, ters yönde büyük direnç), curve tracer.

## Detaylı Açıklamalar

- **Diyotun tek yönlü iletimi.** Diyotun iki ucu vardır ve bir polarma yönü tanımlıdır. Artı uç anoda, eksi uç katoda gelirse diyot doğru polarmadadır ve ideal diyot bir kablo gibi davranır. Ters bağlanırsa açık devre olur. Hoca bunu Ohm kanunuyla da açıkladı: $V = IR$ ifadesinde $R \to 0$ giderken $I$ büyür. Ekrandaki şekilde doğru polarmadaki akımın devre tarafından sınırlandığı yazar ("limited by circuit"), ters polarmada ise $I_D = 0$'dır (ekrandan, 00:35:00).

> **Ders sonrası not:** Hoca doğru polarmada ideal diyottan geçen akımın "sonsuz" olduğunu söyledi. İdeal diyot kısa devre gibi davranır, ama akımın değerini diyota bağlı devre (kaynak ve dirençler) belirler; slaytta da "limited by circuit" yazar.

- **Katkılama ve p-n eklemi.** Saf silisyum ya da germanyuma başka malzemeler eklenerek elektriksel özellikleri değiştirilir. n-tipi malzemede iletim bandında fazla elektron, p-tipi malzemede valans bandında fazla delik bulunur. İki tip yan yana getirilince eklemde elektronlar n'den p'ye geçer, eklemin iki yanında zıt işaretli yükler kalır ve tükenme bölgesi oluşur. Bu bölge bir potansiyel bariyerdir ve diyotun tek yönlü davranışını sağlar.

> **Ders sonrası not:** Hoca p-tipini "proton ya da pozitif yükü fazla olan" malzeme diye anlattı. Slaytta da yazdığı gibi p-tipinde fazla olan, hareketli pozitif yük taşıyıcısı gibi davranan deliklerdir (valence band holes); protonlar hareket etmez.

- **Polarma durumları.** Ters polarmada n tarafına bağlanan artı uç elektronları, p tarafına bağlanan eksi uç delikleri eklemden uzağa çeker. Tükenme bölgesi genişler ve akım geçmez. Doğru polarmada p'ye artı, n'ye eksi verilir; taşıyıcılar ekleme doğru itilir, tükenme bölgesi daralır. Bölge ortadan kalkınca akım p'den n'ye akar. Bölgenin kalkması anında olmaz: gerilim sıfırdan başlayıp eşik değerine ulaşana kadar akım çok küçüktür.

- **Ters akım ve sıcaklık.** Gerçek diyotta ters polarmada da çok küçük bir ters akım ($I_s$, ters doyma akımı) vardır. Slayttaki karakteristikte bu akım mikroamper altı düzeydedir. Hoca bu akımın hesaplarda genelde ihmal edildiğini söyledi.

> **Ders sonrası not:** Hoca tükenme bölgesinin genişlemesini sızıntı akımına bağladı ve sıcaklık artınca ters yöndeki sızıntının azaldığını söyledi. Tükenme bölgesini genişleten dışarıdan uygulanan ters gerilimdir. Ters doyma akımı ise azınlık taşıyıcılardan oluşur ve sıcaklık arttıkça artar (büyük olasılıkla her 10 °C artışta yaklaşık iki katına çıkar).

- **Eşik gerilimi ve malzeme seçimi.** Ge diyot 0,3 V, Si diyot 0,7 V, GaAs diyot 1,2 V civarında iletime geçer (ekrandan, 01:05:00). Bir öğrenci eşiğin kaliteyi mi kullanım alanını mı gösterdiğini sordu; hoca kullanım alanını ve maliyeti belirlediğini söyledi. Silisyum doğada bol olduğu için çoğu diyot silisyumdandır. Çok sayıda diyot kullanılan bir tasarımda her diyotun üzerinde eşik gerilimi kadar gerilim düşer; bu bir güç kaybıdır ve düşük eşikli diyot tercih edilebilir.

- **Zener diyot.** Normal diyot teoride ters polarmada hiç iletmez; pratikte ise çok yüksek ters gerilimde kırılır ve zarar görebilir. Zener diyot ters polarmada belirli bir gerilimde ($V_Z$) bilinçli olarak iletime geçecek biçimde üretilir. Sembolü normal diyota benzer ama katot çizgisinde iki çentik vardır; sorularda yanında $V_Z$ değeri yazılır.

- **Pratik diyot modeli.** Simülasyon programı yalnız ideal diyot sunuyorsa gerçek diyot şöyle modellenir: ideal diyota seri bağlı, iletime karşı koyan yönde 0,7 V'luk bir $V_K$ kaynağı ve $r_{av} = 10\ \Omega$'luk bir direnç (ekrandan, 01:15:00). Girişteki gerilim $V_K$'yı aşmadıkça ideal diyot iletime geçmez.

> **Ders sonrası not:** Hoca bu modeli anlatırken "germanyum olduğu için 0,7 V" dedi. Slayttaki 0,7 V silisyum diyota aittir; germanyumda eşik 0,3 V'tur.

- **Kapasitans ve ters toparlanma.** Diyotta yük birikmesinden kaynaklanan pikofarad ($10^{-12}$ F) düzeyinde bir kapasitans vardır. Bu kapasitans bir LED'i yakacak kadar enerji depolamaz. Diyot iletimdeyken birden ters polarmaya geçirilirse bir süre ters akım akar, sonra normale döner. Bu süre veri sayfasında ters toparlanma süresi olarak verilir.

- **Diyot testi.** Diyot test cihazı (multimetrelerde de bulunur) sağlam bir silisyum diyotta yaklaşık 0,7 V, germanyumda yaklaşık 0,3 V gösterir. Ohmmetrede artı uç anoda, ortak (COM) uç katoda bağlanınca küçük, ters bağlanınca çok büyük direnç okunmalıdır. Eğri izleyicide (osiloskop benzeri) diyot karakteristiği görülürse diyot sağlamdır.

- **LED ve diyot dizileri.** LED doğru polarmada ışık yayan diyottur. Yedi parçalı göstergeler gibi diyot dizileri birden fazla diyotun birleşiminden oluşur.

> **Ders sonrası not:** Hoca LED'in akkor ampul gibi "aynı mantıkla" çalıştığını söyledi. Akkor ampulde ışık, direncin ısınmasından gelir. LED'de ışık, eklemde elektronların deliklerle birleşmesi sırasında açığa çıkan enerjiden gelir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
