# Ders 6 Çalışma Özeti

## Genel Konular

- Laboratuvar 0: simülasyon ortamına giriş
  - Bu kayıt dersin laboratuvar tanıtımıdır (ekrandan, 00:25:00, "Elektronik Devreler 2021 Bahar – LAB 0"). Laboratuvar konuları ders sırasını izler: diyot, opamp, BJT (bipolar junction transistor) ve CMOS.
  - Laboratuvarlarda istenen iş: verilen devreyi simülasyon programında kurmak, simüle etmek, sonuçları hesapla doğrulamak ve yorumlamak.
- Proteus Design Suite ile çalışma
  - Ekranda Proteus Design Suite 8.12 demonstration (öğrenci, değerlendirme) sürümü kullanılır (ekrandan, 00:35:00). Demo sürümde proje kaydedilemez, her devre sıfırdan kurulur.
  - Kurulumda varsayılan seçenekler bırakılır; mikroişlemci, firmware ya da PCB layout işi yoktur.
  - Mac kullananlar için Multisim gibi başka bir simülatör de kullanılabilir; önemli olan devrenin kurulup simüle edilmesi ve sonuçların gösterilmesidir.
- Eleman seçme ve yerleştirme
  - Eleman seçmek için araç çubuğundaki P harfine tıklanır ya da klavyeden P tuşuna basılır. Açılan pencerede anahtar kelimeyle filtrelenir (örneğin "diode", "resistor", "opamp").
  - Diyot listesinde Schottky, zener ve eşik gerilimi yaklaşık 0,7 V olan silisyum diyot gibi farklı modeller vardır. Soruda belirtilen diyot kullanılır; belirtilmemişse uygun olan seçilir (örneğin istenmeden zener seçmek hatadır).
  - Yerleştirilen elemana çift tıklanarak ya da sağ tuş "Edit Component" ile adı ve değeri (direnç için ohm cinsinden) girilir. Silmek için seçip Delete; kopyalama Ctrl-C/Ctrl-V ile değil, sağ tuş blok kopyalama ile yapılır.
  - Bağlantı, fareyle elemanın bir ucundan tutup diğer uca sürüklenerek yapılır.
- Kaynaklar
  - İki portlu gerilim kaynağı (VSOURCE, DC voltage source) ya da batarya kullanılabilir.
  - Tek portlu kaynaklar (GENERATORS listesi): DC, SINE, PULSE, EXP, SFFM, PWLIN, FILE, AUDIO ve dijital kaynaklar (ekrandan, 01:00:00). Tek portlu kaynak bir iğne gibi bağlandığı noktayı besler; diğer ucu arka planda toprağa bağlı sayılır.
  - DC kaynakta yalnız gerilim değeri girilir. Sinüzoidal kaynakta genlik, frekans, faz ve offset gibi parametreler girilir. Pulse (kare dalga) kaynakta yükselme eğimi, yükseklik ve periyot gibi parametreler gerekir.
- Ölçüm araçları
  - INSTRUMENTS listesi: osiloskop, lojik analizör, sayıcı, sinyal üreteci, DC/AC voltmetre, DC/AC ampermetre, wattmetre (ekrandan, 00:45:00).
  - PROBES listesi: gerilim probu ve akım probu (ekrandan, 00:55:00). Prob bir kalem ucu gibi dokunduğu noktanın değerini verir; gerilim probunun referansı topraktır.
  - Simülasyon play tuşuyla ya da "Run Simulation" ile başlatılır. Hata olursa alttaki mesaj alanı (i simgesi) hangi elemanda sorun olduğunu gösterir (ör. floating devre, ampermetre hatası).
- Toprak bağlantısı
  - İki portlu ölçüm aletleri eksi uçlarını referans aldığı için topraksız devrede de doğru gösterebilir. Tek portlu gerilim probu ise referans olarak toprağı kullandığından topraksız devrede yanlış değer verir (örnekte 5 V yerine 3,3 V).
  - Kural: devreye her zaman toprak konur.
- Voltmetre ve ampermetre bağlantısı, işaret
  - Voltmetre ölçülen elemana paralel bağlanır, çünkü paralel elemanların uçları arasındaki gerilim eşittir.
  - Ampermetre seri bağlanır; akım bir ucundan girip diğerinden çıkmalıdır. Paralel bağlanan ampermetre içinden düşük dirençli kısa yol oluşturur ve hata verir.
  - Ampermetre ya da akım probu ters yönde bağlanırsa değer eksi işaretli çıkar. Akım probu sağ tuş "Rotate 180" ile çevrilerek işaret düzeltilir.
  - Akım probu doğrudan tele tıklanarak konmalı; uzaktan kablo çekilerek bağlanırsa hata verir (gerilim probunda bu sorun yoktur).
- Zamana bağlı grafik
  - Graph modundan analog grafik alınır, sağ tuş "Add Trace" ile prob değerleri eklenir, "Simulate Graph" ile çizilir. DC devrede değer zamanla değişmez.
- Osiloskop
  - Gerilim izleyici (voltage follower) örneğinde opamp çıkışı A kanalına (sarı), giriş B kanalına (mavi) bağlanır (ekrandan, 01:10:00). Proteus osiloskobunun A, B, C, D olmak üzere dört kanalı vardır.
  - Yatay eksen (Horizontal) bütün kanallar için ortaktır ve zamanı gösterir; örnekte bir kare 0,2 ms'dir (ekrandan, 01:15:00). Düşey eksen her kanal için ayrı ayarlanır ve gerilimi gösterir; örnekte bir kare 5 mV'tur.
  - Osiloskop düğmeleri sinyalin değerini değiştirmez, yalnız gösterimi ölçekler. Ölçek yanlışsa sinyal düz çizgi gibi görünebilir.
  - Kapatılan osiloskop penceresi Debug menüsünden "Digital Oscilloscope" seçilerek yeniden açılır.
- Breadboard ve Fritzing
  - Breadboard'da üst ve alttaki uzun güç satırları kendi içinde yatay olarak bağlıdır. Ortadaki bölümde her sütundaki beşli delik grubu kendi içinde bağlıdır; ortadaki oluğun iki yanı birbirinden ayrıdır.
  - Fritzing bir simülatör değildir; devrenin breadboard üzerine fiziksel bağlantısını göstermeye yarar (ekrandan, 01:20:00). Proteus ise ölçüm ve simülasyon içindir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Devre teorisi bilgilerini tazelemek
  - Seri/paralel bağlantı, gerilim ve akım bölücü, direnç, kapasite, bobin ve RLC devreleri hızla hatırlanmalıdır. Bu ders bunları yeniden anlatmaz; transistör konularına geçince bu temel olmadan kopulur.
  - İki ucu birbirine bağlı elemanlar paraleldir; çizimin biçimi (yatay ya da dikey) önemli değildir.
- Eşit iki paralel direncin eşdeğeri yarısıdır; genelde "çarpımları bölü toplamları" ile hızlıca hesaplanır.
- Osiloskop okumak
  - Girişteki ve çıkıştaki sinyalin frekans ve genliğini osiloskobun kanal ve yatay ayar değerlerinden okuyup gösterebilmek beklenir. Donanım derslerinde öğrencilerin büyük kısmının osiloskop kullanamadığını, bunun bu laboratuvarda çözülmesi gerektiğini söyledi.
- Akım işareti: akımın yönünü doğru tespit edip ölçüm aletini buna göre bağlamak gerekir; ters bağlantı eksi değer verir.
- Devre her zaman topraklanır.
- Programın arayüzünü önceden kendi denemelerinizle öğrenmek gerekir; laboratuvar sırasında "probu bulamıyorum" gibi sorunlara zaman yoktur.

## Kısa Tekrar Notları

- Proteus'ta eleman seçme: P tuşu; değer girme: çift tıklama ya da sağ tuş "Edit Component".
- Tek portlu kaynaklar (DC, SINE, PULSE...) iğne gibi bağlanır, diğer ucu gizlice topraklıdır.
- Voltmetre paralel, ampermetre seri; ters bağlanan ampermetre eksi değer gösterir.
- Gerilim probu toprağı referans alır; toprak yoksa yanlış okur.
- Örnek devre: $R_1=R_2=5\ \Omega$ seri, $R_3=10\ \Omega$ ile paralel, $R_4=5\ \Omega$ ile seri, 10 V kaynak. $R_{\text{eş}}=10\ \Omega$, $I=1$ A, kollara $0{,}5$ A + $0{,}5$ A, ara düğüm gerilimi 5 V.
- Osiloskopta yatay eksen ortak ve zaman/kare, düşey eksen kanal başına volt/kare.
- Osiloskop ayarları sinyali değiştirmez, yalnız gösterimi ölçekler.
- Breadboard: güç satırları yatay, orta bölümde sütunlar kendi içinde bağlı.

## Detaylı Açıklamalar

- Basit tek göz devre (ekrandan, 00:50:00 ve 00:55:00)
  - 5 V'luk $V_1$ kaynağına 5 Ω'luk $R_1$ bağlanmıştır. Voltmetre kaynağa ve dirence paraleldir, bu yüzden direnç uçlarında 5 V okunur. Akım $I = V/R = 5/5 = 1$ A olmalıdır.
  - Akım probu akım yönüne ters yerleştirildiği için ekranda $I=-1$ görünür (ekrandan, 00:55:00). Prob 180° döndürülünce $+1$ A okunur. Aynı durum ampermetre ters bağlandığında da görülür.
  - Ampermetrenin elemana paralel konduğu çizimde akım ampermetrenin içinden kısa yoldan geçer ve simülasyon hata verir.
- Dört dirençli devre (ekrandan, 01:00:00 ve 01:05:00)
  - Elemanlar: $R_1 = 5\ \Omega$, $R_2 = 5\ \Omega$, $R_3 = 10\ \Omega$, $R_4 = 5\ \Omega$. Devre sağ uçtan tek portlu 10 V DC kaynakla beslenir.
  - $R_1$ ve $R_2$ seridir: $5+5=10\ \Omega$. Bu, $R_3=10\ \Omega$ ile paraleldir; eşit oldukları için eşdeğer $5\ \Omega$. Buna seri $R_4 = 5\ \Omega$ eklenince toplam $10\ \Omega$ olur.
  - Ana kol akımı $I = 10/10 = 1$ A. Eşit dirençli iki kola eşit bölünür: her kolda $0{,}5$ A. Ekranda probların gösterdiği değerler: $V=0$ (toprak tarafı), $I=-0{,}5$, $V=5$, $I=-1$; eksi işaretler probların yönünden gelir (ekrandan, 01:00:00). Ara düğüm gerilimi $10 - 1\cdot 5 = 5$ V'tur.
  - Grafikte $R_1$ akımı 0–1 s boyunca sabit 0,5 A (prob yönüne göre $-0{,}5$ A) çizilir, çünkü kaynak DC'dir.
- Gerilim izleyici ve osiloskop (ekrandan, 01:10:00, 01:15:00, 01:25:00)
  - Opamp U1, 10 Ω'luk yük direnci $R_5$ ve tek portlu sinüs kaynağı kullanılır. Çıkış A kanalına, giriş B kanalına bağlıdır. Ekranda çıkış ve giriş aynı genlik ve frekansta iki sinüs olarak görünür.
  - Kullanım amacı olarak girişteki gerilimin aynısının çıkışta alınması söylendi.
  - <!-- BELİRSİZ: Hoca kullanım amacı için "delay koymak" ifadesini kullandı; gerilim izleyicinin olağan kullanımı empedans ayırmadır (tampon). Altyazıdan net değil. -->
  - Ders sonrası not: Ekrandaki çizimde geri besleme opampın + girişine, sinüs girişi − girişine bağlı görünmektedir (ekrandan, 01:10:00), hoca da "eksi terminalinden giriş uygulanmış" dedi. Standart gerilim izleyicide çıkış − girişe geri beslenir, sinyal + girişe verilir. Çizimdeki bağlantı gerçek devrede pozitif geri besleme olurdu; simülasyonda aynı sinüsün görülmesi büyük olasılıkla kullanılan ideal opamp modelinden kaynaklanır.
- Breadboard örneği (ekrandan, 01:20:00)
  - Fritzing'de bir güç girişine bağlı iki direnç, aynı dikey sütunda bir ucu ortak olacak biçimde yerleştirilmiştir. Diğer uçları farklı sütunlarda olduğu için iki direnç seridir.
  - Breadboard'da bir bobinin iki bacağı aynı bağlı sütuna takılırsa eleman kısa devre edilir: akım elemandan değil, breadboard'un içindeki bağlantıdan geçer.
  - İki direnç paralel bağlanmak istenirse her iki ucu da ortak (bağlı) satırlara takılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
