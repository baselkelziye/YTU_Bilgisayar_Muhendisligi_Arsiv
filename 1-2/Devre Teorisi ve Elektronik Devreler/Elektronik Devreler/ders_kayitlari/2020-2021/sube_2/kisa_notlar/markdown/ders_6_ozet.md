# Ders 6 Çalışma Özeti

## Genel Konular

- Laboratuvar tanıtımı (Lab 0) ve simülasyon ortamı
  - Bu kayıt, teori dersinden ayrı bir laboratuvar tanıtım oturumudur (slayt kapağı: "Elektronik Devreler 2021 Bahar – LAB 0", ekrandan, 00:10:00). Laboratuvarlar çevrim içi olduğu için devreler Proteus 8 simülasyon programında kurulur.
  - Laboratuvar konuları sırasıyla diyot, op-amp, BJT (bipolar jonksiyonlu transistör) ve CMOS transistörlerdir; son laboratuvarın lojik kapılarla ilgili olacağı tahmin edilmektedir.
  - Her laboratuvarın konusu önce teori derslerinde işlenir, laboratuvar ondan sonra yapılır.
- Proteus 8 demo sürümü
  - Ücretsiz demo (öğrenci) sürümü kullanılır. Ekrandaki sınırlamalar: süre sınırı yok; yalnız örnek tasarımlardan şema yazdırılabilir; çalışma kaydedilemez; kendi mikrodenetleyici tasarımınız simüle edilemez (ekrandan, 00:20:00).
  - Kayıt yapılamadığı için simülasyon kapatılınca kurulan devre kaybolur; elektrik ya da bağlantı kesintisine karşı dikkatli olmak gerekir.
- Yeni proje ve eleman seçimi
  - File > New Project ile boş proje açılır; şablon ve donanım ailesi seçilmez ("No firmware project"). Çalışma alanı ızgaralı boş bir sayfadır.
  - Eleman, "P" düğmesiyle ya da Devices listesinden anahtar kelimeyle aranır (direnç için RES, kondansatör için CAP, diyot, BAT/battery, DC kaynak vb.). Seçilen eleman pembe görünür, tıklanan yere bırakılır.
  - Elemanın değeri çift tıklanarak girilir (örneğin direnç 5 Ω). Bağlantılar fareyle uçtan uca çekilir; bağlantı noktasında bir kez daha tıklamak gerekir.
- Simülasyonu çalıştırma ve hata mesajları
  - Sol alttaki oynat düğmesi ya da menüdeki "Run Simulation" ile çalıştırılır. Alttaki Messages alanı yeşilse sorun yok, kırmızıysa hata vardır.
  - Hata mesajları her zaman açık değildir; örneğin ampermetre yanlış bağlanınca yalnız kaynakla ilgili bir "fatal error" verir. Bağlanmamış uçlar için "floating" uyarısı çıkabilir.
- Ölçü aletleri: voltmetre ve ampermetre
  - Instruments listesinde Oscilloscope, Logic Analyser, Signal Generator, DC/AC Voltmeter, DC/AC Ammeter, Wattmeter vb. bulunur (ekrandan, 00:30:00).
  - Voltmetre ölçülen elemana paralel bağlanır: iç direnci sonsuz kabul edilir ve iki nokta arasındaki gerilim farkını ölçer; paralel elemanların gerilimi eşittir.
  - Ampermetre seri bağlanır: iç direnci sıfır kabul edilir, ölçülecek akımın üzerinden geçmesi gerekir. Paralel bağlanırsa akım ampermetreden geçer ve hata oluşur.
  - Ölçü aletlerinin artı ve eksi uçları vardır. Akım eksi uçtan girerse değer eksi görünür (ekrandan, 00:35:00).
- Toprak ve problar
  - Proteus topraksız devreyi de çalıştırır, ama devreye her zaman toprak konur.
  - Tek uçlu gerilim ve akım probları, toprağa göre o noktanın değerini verir. Toprak yoksa prob referansı bilemez ve yanlış değer gösterebilir.
  - Gerilim probu bir kabloyla istenen noktaya bağlanabilir; akım probu ise doğrudan devre hattının üzerine konmalıdır. Akım probunun ok yönü ölçülen akımın pozitif yönünü belirler; prob 180° döndürülerek işaret düzeltilir.
- Örnek DC devreler (ekrandan, 00:35:00, 00:40:00, 00:45:00)
  - 5 V kaynak ve 5 Ω direnç: $I = V/R = 1$ A; ampermetre ters uçtan bağlı olduğu için $-1{,}00$ gösterir.
  - 10 V tek uçlu kaynak, $R_4 = 5\ \Omega$, $R_3 = 10\ \Omega$, $R_1 + R_2 = 10\ \Omega$: paralel kısım 5 Ω, toplam 10 Ω, $I = 1$ A; düğüm gerilimi 5 V; akım iki kola 0,5 A'er bölünür.
- Grafik (analog graph) ile zamana bağlı izleme
  - Graph listesinden analog grafik çalışma alanına konur, Add Trace ile prob seçilir, sağ tık > Simulate Graph ile zamana bağlı eğri çizilir. X ekseni aralığı grafiğe çift tıklanarak ayarlanır.
  - DC kaynaklı devrede akım zamanla sabittir (örnekte $-0{,}5$ A sabit çizgi).
- Sinüs kaynak, gerilim izleyici ve osiloskop
  - Tek uçlu kaynak çift tıklanıp DC'den sinüse çevrilebilir; genlik, tepeden tepeye değer, rms, ofset, frekans ve periyot girilebilir.
  - Op-amp ile kurulan gerilim izleyici (voltage follower, buffer) girişteki gerilimi çıkışa aynen verir (ekrandan, 00:50:00).
  - Ders sonrası not: ekrandaki şemada çıkış artı girişe, kaynak eksi girişe bağlı görünüyor; gerilim izleyicide doğru bağlantı giriş artı uca, çıkışın eksi uca geri beslenmesidir. Simülasyonun yine izleyici gibi davranması büyük olasılıkla ideal op-amp modelinden kaynaklanır.
  - Proteus'un dijital osiloskobu dört kanallıdır (A, B, C, D). Ekranda yatay ölçek 0,2 ms/kare, A ve B kanalları 5 mV/kare olarak görünür (ekrandan, 00:55:00).
  - Osiloskop okuma: yatayda kareler sayılıp kare başına süreyle çarpılarak periyot (ve frekans), dikeyde kareler sayılıp kare başına gerilimle çarpılarak genlik bulunur. Ölçek ayarı sinyali değiştirmez, yalnız görüntüyü ölçekler.
- Breadboard ve Fritzing
  - Fritzing bir simülatör değil, devreyi breadboard üzerinde çizme programıdır (ekrandan, 01:00:00, 01:10:00).
  - Breadboard'da üst ve alttaki uzun güç hatları boylu boyunca, ortadaki deliklerse kısa gruplar hâlinde kendi içinde bağlıdır.
  - İki eleman tek uçtan ortak gruptaysa seri, iki ucu da ortak gruplardaysa paraleldir. Bir elemanın iki bacağını aynı bağlı gruba takmak kısa devredir.
- Proje kapsamında entegreler
  - Projelerde Arduino kartı kullanılmaz; istenirse ATmega gibi bir işlemci çipi ya da LM555, op-amp entegresi gibi IC'ler kullanılabilir. Vu-metre, gelen ses sinyalinin seviyesine göre sırayla yanan LED'lerden oluşan bir göstergedir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Devre teorisi bilgileri tekrar edilmeli
  - Thevenin ve Norton eşdeğerleri, düğüm ve çevre (mesh) analizi, gerilim ve akım bölücü bu derste sürekli kullanılır; elektronikte çok daha karışık devreler gelecektir.
  - Devre teorisinde görülen her şey (op-amp'ın AC analizi dahil) bu dersin kapsamındadır; ayrıca diyot ve transistörler ayrıntılı işlenir.
- Ölçü aletinin ve probun yönü
  - Ampermetre ya da akım probu ters yönde konursa işaret eksi çıkar; rapora eksi işaretli değer yazmak işaret hatası olur. Prob döndürülerek akım yönüyle aynı yöne getirilmeli.
- Osiloskop okumayı bilmek
  - Her laboratuvarda osiloskopla ilgili soru gelir: çıkış sinyalinin ekran görüntüsü, frekansı ve genliği. Okuma yalnız yatay ve dikey kareleri sayıp ölçekle çarpmaktır.
- Sinüs sinyalinin parametreleri
  - Genlik, tepeden tepeye değer, ofset, frekans ve periyodun anlamı bilinmeli; osiloskopta bunlar ölçülür.
- Osiloskop penceresi kaybolursa
  - Simülasyon çarpıdan kapatılınca osiloskop penceresi kaybolur; Debug menüsünden dijital osiloskop yeniden seçilerek açılır.

## Kısa Tekrar Notları

- Voltmetre paralel (iç direnç sonsuz), ampermetre seri (iç direnç sıfır) bağlanır.
- Akım ölçerin eksi ucundan giren akım eksi okunur.
- Devreye her zaman toprak konur; tek uçlu problar toprağa göre ölçer.
- Akım probu doğrudan hat üzerine konur; ok yönü pozitif akım yönüdür.
- Seri dirençler toplanır; iki paralel direnç $\dfrac{R_a R_b}{R_a + R_b}$, eşitse $R/2$.
- 10 V, 5 Ω + (10 Ω ∥ 10 Ω) örneğinde toplam 10 Ω, akım 1 A, kollarda 0,5 A, orta düğüm 5 V.
- Gerilim izleyici çıkışta girişi aynen verir (tampon).
- Osiloskop: periyot = yatay kare sayısı × s/kare; genlik = dikey kare sayısı × V/kare; $f = 1/T$.
- Breadboard: güç hatları yatay boyunca, orta delikler kısa gruplar hâlinde bağlı; iki bacak aynı grupta = kısa devre.
- Proteus demo sürümü çalışmayı kaydetmez.

## Detaylı Açıklamalar

- **Ölçü aletlerinin bağlanması.** Gerilim iki nokta arasındaki potansiyel farkıdır; paralel elemanlar aynı gerilimi paylaştığı için voltmetre ölçülen elemana paralel bağlanır. İç direncinin sonsuz kabul edilmesi, devreden akım çekmediği ve ölçümü bozmadığı anlamına gelir. Akım ise bir elemanın üzerinden akar; ölçülmesi için akımın ölçü aletinden geçmesi gerekir, bu yüzden ampermetre seri bağlanır ve iç direnci sıfır kabul edilir. Derste ampermetre önce yanlış (kola paralel) konunca Proteus yalnız kaynakla ilgili bir hata verdi; hatanın nedenini kullanıcının çıkarması gerekir.
- **İşaret ve yön.** Ekrandaki ilk devrede 5 V kaynak ve 5 Ω direnç vardır (ekrandan, 00:35:00). Ohm yasasından $I = 5/5 = 1$ A akar. Ampermetre, akım eksi ucundan girecek biçimde bağlandığı için $-1{,}00$ A gösterir; voltmetre kaynağa doğru yönde paralel olduğu için $+5{,}00$ V gösterir. Problarla bakıldığında kaynağın artı ucu $V = 5$, direncin diğer ucu ve toprak $V = 0$ görünür (ekrandan, 00:40:00); direncin uçları arasında 5 V düşer.
- **İkinci DC örneği.** Ekrandaki devrede $R_1 = R_2 = 5\ \Omega$ seri, $R_3 = 10\ \Omega$, $R_4 = 5\ \Omega$ ve $R_4$'ün ucunda tek uçlu 10 V'luk kaynak vardır (ekrandan, 00:45:00). $R_1 + R_2 = 10\ \Omega$, bu da $R_3$ ile paralel: $10 \parallel 10 = 5\ \Omega$. Toplam direnç $5 + 5 = 10\ \Omega$, kaynaktan çekilen akım $10/10 = 1$ A. Eşit kollar akımı ikiye böler: her kolda 0,5 A. Orta düğüm gerilimi $10 - 1\cdot 5 = 5$ V'tur; ekrandaki prob da $V = 5$ ve kol akımı için $I = -0{,}5$ gösterir (eksi işaret prob yönünden gelir). Değerler python ile kontrol edildi.
- **Zamana bağlı grafik ve osiloskop.** Analog grafik, seçilen probların zaman içindeki değerini çizer; DC devrede bu sabit bir çizgidir. AC çalışmalarda kaynak sinüse çevrilir ve çıkış osiloskopla izlenir. Örnekte op-amp ile kurulan gerilim izleyicide giriş sinyali B kanalına, çıkış A kanalına bağlanmış, iki sinyal aynı biçimde görülmüştür (ekrandan, 00:50:00, 00:55:00). Osiloskopta her kanalın ölçek düğmesi yalnız o kanalı etkiler; farklı kanallara farklı V/kare verilirse her sinyal kendi ölçeğiyle okunur.
- **Breadboard mantığı.** Breadboard'da üstteki ve alttaki güç hatları boylu boyunca birbirine bağlıdır ve kaynak ile toprak buraya verilir. Ortadaki delikler kısa gruplar hâlinde alttan bağlıdır. Bir direncin bacağıyla başka bir direncin bacağı aynı gruba takılırsa iki direnç seri bağlanır; ikinci bir direncin iki bacağı ilk direncin iki ucunun gruplarına takılırsa paralel bağlanır. Bir direncin iki bacağı aynı bağlı gruba takılırsa direnç kısa devre olur; akım dirençten değil, boş yoldan geçer.

<!-- BELİRSİZ: 00:53:47'de genlik için "5 volt" dendi; ekranda ve 00:55:06'daki anlatımda kare başına ölçek 5 mV'tur. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
