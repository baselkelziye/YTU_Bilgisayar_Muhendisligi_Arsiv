# Ders 2 Çalışma Özeti

## Genel Konular

- Okunan makale: Multics üzerinde koruma halkaları (protection rings) için donanım mimarisi
  - Derste, Honeywell 645 üzerinde çalışan Multics işletim sistemi bağlamında yazılmış 1972 tarihli bir makale tartışıldı.
  - Makalenin anahtar kelimeleri: protection, protection rings, protection hardware, access control, hardware access control.
  - Makale, segmentli sanal bellekte bir prosedür çağrısı başka bir segmente geçerken erişimin donanımla nasıl denetleneceğini anlatır.
- Makalenin ana motivasyonu: erişim denetimi (access control)
  - Girişteki cümle: "The topic of this paper is the control of access to stored information in a computer utility."
  - Yani amaç, saklanan bilgiye erişimi denetimli hale getirmektir. Ayrıntılar bu ana amaca hizmet eder.
- Makalede sistem tasarımı için konan dört ölçüt (bir öğrencinin aktarımıyla)
  - Functional capability (işlevsel yetenek), economy (ekonomi), simplicity (basitlik), programming generality (programlama genelliği).
- Makalede anlatılan yapı taşları (öğrenci anlatımından)
  - Bellek, kelime dizilerinden (array of words) oluşan segmentlerle düzenlenmiş segmentli sanal bellektir.
  - Sanal adresten gerçek belleğe bir tablo (segment tablosu) üzerinden gidilir. <!-- BELİRSİZ: altyazıda "soft table" geçiyor; büyük olasılıkla "segment tablosu / descriptor table" kastedildi -->
  - Her segmentin okuma (read), yazma (write) ve çalıştırma (execute) izinleri vardır.
- Bu yapıdan önce erişim denetimi
  - İlk olarak yazılımla erişim denetimi denendi; donanım desteği olmadan çalışan bir programın belleğin neresine erişeceğini kısıtlamak mümkün olmadı.
  - Sonra basit donanım mimarileriyle denendi; bunlar yukarıdaki dört ölçütü karşılamadı (ekonomik ve etkili değildi, çoklu prosese ve sanal belleğe tam uyumlu değildi).
- Günümüze etkisi: Intel korumalı kip (protected mode)
  - Intel 286 ile gelen, 386, 486, Pentium ve i3/i5/i7 ailelerinde süren korumalı kipin temelinde bu makaledeki yapı vardır.
  - Linux iki halka kullanır: Ring 0 (çekirdek) ve Ring 3 (kullanıcı kodu).
  - Örnek akış: kullanıcı kodu `printf` çağırır, bu `write` sistem çağrısına gider, yazılım kesmesiyle çekirdeğe geçilir, Ring 3'ten Ring 0'a inilir; aygıt sürücüsü de işin içine girer.
- Makalenin çözdüğü üç temel problem
  - Kullanıcılar başkalarının kullanması için keyfi ama korumalı alt sistemler oluşturabilir.
  - Supervisor (işletim sistemi çekirdeği) zorlanan katmanlar halinde gerçeklenebilir.
  - Kullanıcı kendi ya da ödünç aldığı programları hata ayıklarken kendini koruyabilir.
- Yalıtım (isolation) dereceleri
  - Prosesler arası yalıtım: system call interposition.
  - Aynı prosesin parçaları arasında yalıtım: software fault isolation (SFI).
  - Katmanlara bölme, güvenlikteki compartmentalization kavramının temelidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir makaleyi okurken önce ana motivasyonu bulmak
  - Ayrıntıya girmeden önce "bu çalışma ne için yapıldı?" sorusu cevaplanmalıdır. Bu makalede cevap girişte tek cümleyle yazılıdır: erişim denetimi.
- Makale incelerken sorulacak sorular
  - Amacı ne, kapsamı ne, hangi teorik ve pratik çalışmalar yapılmış, hangi sonuçlar elde edilmiş, ileride incelenmesi gereken kısımlar neler?
- 50 yıllık bir yapının hâlâ yaşaması
  - 1972'de ortaya konan halka yapısı bugün masaüstü, sunucu ve tabletlerdeki işlemcilerde ve Linux, Windows gibi işletim sistemlerinde sürmektedir. Bu, yazarların genelleme (generalization) başarısını gösterir.
  - Intel mühendisleri sıfırdan yeni bir şey düşünmemiş, korumalı kipi bu çalışmaya dayandırmıştır.
- Halka ve kapı (gate) yapısını anlamak
  - Her satırı bilmek gerekmez; ama halka yapısı nedir, kapı yapısına neden ihtiyaç duyulur, düşük korumalı seviyeden yüksek korumalı seviyeye geçiş ile tersi arasında neler olmalı ve olmamalı, bunların nedenleriyle bilinmesi beklenir.
  - Bir `call` ve bir `return` basit görünür; ama gidilen adres aynı halkada ya da aynı segmentte değilse araya kapı yapısı girer.
- Kullanıcıyı kendinden korumak
  - Üçüncü problem (kullanıcının hata ayıklarken kendini koruması) çok önemlidir; yalıtımın ve SFI'nin temelidir.

## Kısa Tekrar Notları

- Makalenin konusu: depolanan bilgiye erişimin denetimi (access control); yıl 1972; donanım Honeywell 645, işletim sistemi Multics.
- Tasarım ölçütleri: functional capability, economy, simplicity, programming generality.
- Segmentli sanal bellek; her segmentin read/write/execute izinleri.
- Önceki yaklaşımlar: önce yazılımla erişim denetimi (yetersiz), sonra basit donanım (ölçütleri karşılamıyor).
- Supervisor/user iki seviyeli ayrım, halkalarla genelleştirilir; paylaşılan sanal bellek ve segmentasyon desteklenir.
- Üç kazanım: korumalı alt sistemler, katmanlı supervisor, kullanıcının kendini koruması.
- Intel korumalı kipi (286 ve sonrası) bu yapıya dayanır; Linux Ring 0 ve Ring 3 kullanır.
- Halkalar arası çağrıda kapı (gate) yapısı devreye girer.
- Yalıtım: prosesler arası (system call interposition), proses içi (SFI); compartmentalization.

## Detaylı Açıklamalar

- Bu ders, öğrencilerin önceden okuduğu bir makalenin sınıfta tartışılması biçiminde geçti. Makale, Multics işletim sisteminde koruma halkalarının donanımla nasıl gerçekleneceğini anlatır. Bir öğrencinin aktardığına göre makale önce bir sistemin sağlaması gereken dört ölçütü koyar: işlevsel yetenek, ekonomi, basitlik ve programlama genelliği. Ardından segmentli sanal belleği anlatır: bellek kelime dizilerinden oluşan segmentlerdir, sanal adres bir tablo aracılığıyla gerçek bellek adresine çevrilir ve her segmentin okuma, yazma, çalıştırma izinleri vardır.
- Hoca, ayrıntılardan önce makalenin ana motivasyonunun sorulması gerektiğini vurguladı. Bir öğrenci motivasyonu "prosedür çağrıları farklı bir bellek segmentine geçerken donanım seviyesinde izin kısıtlamaları koymak, her prosesin her yere erişmesini engellemek" diye özetledi. Hoca bunun doğru yönde olduğunu, ama girişte daha basit bir ifadenin bulunduğunu söyledi: makalenin konusu bilgisayar hizmetinde (computer utility) depolanan bilgiye erişimin denetimidir. Kısacası makale bir erişim denetimi (access control) çalışmasıdır.
- Makaledeki yapının bugün yaşayıp yaşamadığı sorulduğunda bir öğrenci Linux örneğini verdi: Linux yalnız iki halka kullanır; Ring 0 çekirdek kodudur ve donanıma yalnız çekirdek erişir, kullanıcı programları Ring 3'te çalışır. Kullanıcı `printf` çağırdığında bu `write` sistem çağrısını çağırır, yazılım kesmesiyle denetim çekirdeğe geçer ve Ring 3'ten Ring 0'a inilir. Hoca bunun hangi mimariye dayandığını sordu; cevap Intel'dir. Intel'in 286 ile getirdiği ve 386, 486, Pentium ve günümüz i3/i5/i7 ailelerinde süren korumalı kipin temelinde bu 1972 makalesi vardır. Hoca, benzer yapıların bugün kullanımda olan ya da kullanımdan kalkmış başka işlemci mimarilerinde de görüldüğünü ekledi.
- Bu yapıdan önce erişim denetiminin nasıl yapıldığı sorusunun cevabı, önce yazılımla erişim denetimidir. Ancak donanım desteği olmadan çalışan bir programın bellekte nereye erişip erişmeyeceğini kısıtlamak mümkün değildir. Sonra basit donanım mimarileri denenmiştir; bunlar da dört ölçütü karşılamamış, yani ekonomik ve etkili olmamış, birden fazla prosesin aynı anda çalışmasına ve sanal bellek yapısına tam uyum sağlamamıştır.
- Hoca makalenin genelleme yönünü öne çıkardı: o güne kadarki supervisor/user iki seviyeli ayrım halkalarla genelleştirilir ve paylaşılan sanal bellek ile segmentasyon desteklenir. Makale üç temel problemi çözer: kullanıcılar başkaları için korumalı alt sistemler kurabilir; supervisor zorlanan katmanlar halinde gerçeklenebilir (bu, güvenlikteki compartmentalization kavramının temelidir); kullanıcı kendi ya da ödünç aldığı programları hata ayıklarken kendini koruyabilir. Son madde yalıtımın temelidir. Bilgisayar güvenliğinde yalıtımın dereceleri vardır: prosesler arası yalıtım için system call interposition, aynı prosesin parçaları arasındaki yalıtım için software fault isolation (SFI) kullanılır.
- Hoca, makaleden beklenen bakış açısının halka ve kapı yapısını anlamak olduğunu söyledi. Bir çağrı ve dönüş basit görünür; ama hedef adres başka bir halkada ya da segmentteyse geçişin denetlenmesi gerekir ve araya kapı (gate) yapısı girer. Düşük koruma seviyesinden yüksek koruma seviyesine geçiş ile tersi farklı kurallara tabidir; bunların neden böyle olduğu kavranmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
