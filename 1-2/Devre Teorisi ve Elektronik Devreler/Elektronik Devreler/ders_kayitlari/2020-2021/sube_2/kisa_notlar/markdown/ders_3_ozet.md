# Ders 3 Çalışma Özeti

## Genel Konular

- Dönüştürücüler (transducer): sensörler ve eyleyiciler
  - Dönüştürücü, bir fiziksel niceliği başka bir niceliğe çeviren devre elemanıdır (ekrandan, 00:20:00).
  - Örnekler: cıvalı cam termometre (sıcaklığı cıva sütununun yer değiştirmesine çevirir), mikrofon (sesi elektriksel sinyale çevirir).
  - Sensör (algılayıcı) fiziksel niceliği elektriksel sinyale, eyleyici (actuator) elektriksel sinyali fiziksel bir etkiye (hareket, ısı, ışık, ses) çevirir.
  - Elektronik sistemler fiziksel dünyadaki sürekli (analog) büyüklükleri sensörlerle okur, işledikten sonra eyleyicilerle dünyaya geri verir.
- Sensör performansını tanımlayan ölçütler
  - Aralık (range): sensörün ölçebildiği en küçük ve en büyük değer arası. Aralık genişledikçe hassasiyet genelde düşer.
  - Çözünürlük (resolution): sensörün ayırt edebildiği en küçük değişim. Mutfak tartısı gramı ölçer; kargo kantarının çözünürlüğü düşük, aralığı yüksektir.
  - Hata (error): gerçek değer ile ölçülen değer arasındaki fark. Hiçbir sensör sıfır hatalı değildir; önemli olan kabul edilebilir hata payıdır (örn. ±%1).
  - Doğruluk (accuracy): hatanın tersi; $\text{doğruluk} = 1 - \text{hata}$. %97 doğruluk %3 hata demektir.
  - Kesinlik (precision): aynı büyüklük tekrar tekrar ölçüldüğünde sonuçların birbirine yakınlığı (tutarlılık).
  - Doğrusallık (linearity): gerçek tepkinin en iyi uyan doğrudan en büyük sapması (ekrandan, 00:30:00).
  - Duyarlılık (sensitivity): ölçülen büyüklükteki belli bir değişim için çıkışta oluşan değişim (ekrandan, 00:30:00).
- Sensör türleri
  - Fiziksel ilkeye göre: dirençsel (resistive), endüktif, kapasitif, piezoelektrik, fotorezistif, elastik (strain gauge), termal.
  - Sıcaklık: platin dirençli termometre (PRT; doğrusal ama duyarlılığı düşük), termistör (ucuz, doğrusal değil), pn eklem sensörü (ucuz, doğrusal, kolay; aralığı yaklaşık $-50$ °C ile $150$ °C arası) (ekrandan, 00:35:00 ve 00:40:00).
  - Işık: fotovoltaik pn eklem (fotodiyot; hızlı ama gerilim ışık şiddetiyle doğrusal değil) (ekrandan, 00:45:00), ışığa göre direnci değişen fotodirenç.
  - Basınç/gerinim: emniyet kemeri uyarısı veren koltuk sensörü gibi, gerildiğinde direnci değişen yapılar.
  - Anahtarlar ve opto-anahtarlar: yansımalı ve yarıklı opto-anahtar; ışık kaynağı ile ışık sensörü tek gövdede (ekrandan, 01:10:00).
  - Yer değiştirme: artımlı konum kodlayıcı (incremental encoder); birbirine göre az kaydırılmış iki sensör, yönü ve darbe sayısıyla konumu verir (ekrandan, 00:50:00).
  - Hareket: IMU, GPS modülleri; ses: mikrofon.
- Sensörün devreye bağlanması (sensor interfacing)
  - Dirençsel sensör gerilim bölücünün bir kolu olarak kullanılır: $V_o = V \dfrac{R_s}{R_1 + R_s}$ (ekrandan, 00:55:00). Çıkış, direnç değişimine doğrusal bağlı değildir.
  - Potansiyometre aynı mantığın elle ayarlanan biçimidir.
  - Anahtar sensörde anahtar açıkken $V_o = V$, kapalıyken $V_o \approx 0$ olur; mekanik anahtarlarda anahtar sıçraması (switch bounce) görülür (ekrandan, 01:00:00).
  - Kapasitif ve endüktif sensörler daha çok AC devrelerde kullanılır.
- Eyleyiciler
  - Isı (ısıtıcı direnç), ışık (lamba, LED, LCD, fiber optik iletim), kuvvet/hareket (selenoid, motor), ses (hoparlör, ultrasonik verici).
  - Selenoid: bobin ve ferromanyetik çekirdek; enerji verilince çekirdek bobine çekilir, kuvvet akımla orantılıdır, çoğu zaman açık/kapalı modda kullanılır (ekrandan, 01:05:00).
  - Motorlar: AC, DC ve adım (step) motorlar. Adım motoru sargılara sırayla gerilim verilerek belli açılarla döndürülür; açısal konum bilgisi gereken yerlerde (robot kolu) kullanılır.
  - Ultrasonik sensör: gönderilen ses dalgasının yansıyıp dönmesine bakarak mesafe ölçer (araçların park sensörü).
- Laboratuvar ölçü aletleri
  - Multimetre (avometre) yalnız sayısal değer gösterir, dalga biçimi göstermez.
  - Osiloskop gerilimi zamana göre çizer; sinyalin AC/DC olduğu ve dalga biçimi görülür. Analog osiloskopta ayarlar elle yapılır, dijitalde ölçümler ekranda sayısal verilir.
- Veri sayfası (datasheet) okuma: LM35 örneği
  - Bir entegre ya da sensörle çalışırken ilk bakılacak belge veri sayfasıdır; sensörün "kimlik kartı" gibidir.
  - LM35 (ekrandan, 01:20:00): Celsius'a doğrudan kalibre, doğrusal $+10.0$ mV/°C, $+25$ °C'de $0.5$ °C doğruluk garantili, $-55$ °C ile $+150$ °C arası, 4-30 V besleme, 60 µA'dan az akım, doğrusalsızlık tipik $\pm 1/4$ °C.

## Hocanın Özellikle Vurguladığı Kısımlar

- Doğruluk ve kesinlik birlikte düşünülmeli
  - İstenen sensör hem doğruluğu hem kesinliği yüksek olandır. Kesinliğin düşük olması, doğruluğun düşük olması kadar kötüdür; her ölçümde farklı bir hata okunur.
  - Maliyet nedeniyle bir miktar hata kabul edilebilir, ama kesinliğe de bakılmalıdır.
- Sensörler devrede gerilim bölücü olarak kullanılır
  - Sensörün değişen direnci devredeki gerilimi ya da akımı değiştirir; projede sensörün ne yaptığı bu dille yorumlanmalıdır.
- Fiyat farkı performans ölçütlerinden gelir
  - Aynı büyüklüğü ölçen çok pahalı bir endüstriyel sensör ile birkaç liralık bir entegre arasındaki fark aralık, hata, kesinlik gibi ölçütlerden kaynaklanır.
- Yüksek frekanslı devrelerden kaçınmak
  - Frekans yükseldikçe sinyal gürültüden daha kolay etkilenir (FM verici, RF uzaktan kumanda). Ev ortamında iyi yalıtım sağlamak zordur.
- Veri sayfası okunmalı, ezberlenmemeli
  - Sensörlerin hepsini ezberlemek gerekmez; veri sayfasındaki aralık, hata, kesinlik, çözünürlük ve besleme değerlerinin nasıl yorumlanacağı bilinmelidir.

## Kısa Tekrar Notları

- Dönüştürücü: bir niceliği başka bir niceliğe çevirir. Sensör fiziksel → elektriksel, eyleyici elektriksel → fiziksel.
- Performans ölçütleri: aralık, çözünürlük, hata, doğruluk ($1-$hata), kesinlik, doğrusallık, duyarlılık.
- Doğruluk: gerçeğe yakınlık. Kesinlik: tekrar eden ölçümlerin birbirine yakınlığı.
- PRT doğrusal ama duyarlılığı düşük; termistör doğrusal değil; pn eklem ucuz ve doğrusal ama sıcaklık aralığı sınırlı.
- Fotodiyot hızlıdır, çıkışı ışık şiddetiyle doğrusal değildir.
- Artımlı kodlayıcıda iki kaydırılmış sensör hareket yönünü verir; mutlak konum için başlangıçta sıfırlama gerekir.
- Dirençsel sensör: $V_o = V R_s/(R_1+R_s)$.
- Mekanik anahtar kapanırken çıkış birkaç kez salınır: anahtar sıçraması (switch bounce).
- Selenoid: kuvvet akımla orantılı, genelde açık/kapalı kullanılır.
- Adım motoru açısal konum kontrolü sağlar.
- Osiloskop dalga biçimini, multimetre yalnız sayısal değeri gösterir.
- LM35: 10 mV/°C, $-55$...$+150$ °C, 4-30 V.

## Detaylı Açıklamalar

- **Dönüştürücü kavramı.** Bir sistemin işe yaraması için çevresiyle etkileşmesi gerekir; bunu sensörler ve eyleyicilerle yapar. Cıvalı termometre sıcaklığı cıvanın genleşmesiyle bir uzunluğa çevirir, yani bir birimden başka bir birime dönüşüm yapar. Mikrofon ses dalgalarını elektriksel sinyale çevirir: ses, kulak zarı gibi bir zarı titretir, bu titreşim elektriksel sinyal olarak yorumlanır. Sensörlerin çoğu çıkışını gerilim olarak verir ve bir kısmı içinde analog-dijital dönüştürücü (ADC) barındırır; ADC analog sinyali dijitale, DAC dijitali analoğa çevirir.

- **Performans ölçütleri ve hedef tahtası benzetmesi.** Ekrandaki şekilde gerçek değer hedefin merkezidir. Sonuçlar merkezden uzak ve dağınıksa doğruluk da kesinlik de düşüktür. Sonuçlar merkezden uzak ama birbirine yakın kümelenmişse doğruluk düşük, kesinlik yüksektir. Hocanın tartı örneğinde 10 kg olduğu bilinen bir paket kantarda 9,7 kg okunursa hata $0{,}3$ kg, yani %3'tür; doğruluk %97'dir. Aralık ve çözünürlük birbiriyle dengelenir: geniş aralıklı kargo kantarı gram ayırt edemez, mutfak tartısı ise büyük yükleri ölçemez.

- **Doğrusallık örneği.** Bir basınç sensörünün çıkışı gerilim olsun. Hoca 2,2 bar için 3 V, 5 bar için 6,2 V veren bir doğru çizdi (tahta üzerinde). Doğrusal bir tepki tasarımı kolaylaştırır; çıkış gerilimi basit bir kuralla basınca çevrilir. Bu örnekte eğim $(6{,}2-3)/(5-2{,}2) \approx 1{,}14$ V/bar olur (ara adım eklendi). Gerçek sensörde ise malzeme kalitesi ve yalıtım nedeniyle basınç ya da sıcaklık arttıkça çıkış doğrunun altına düşebilir; bu sapma doğrusallık ölçütüyle tanımlanır.

- **Dirençsel sensörler ve $R = \rho L / A$.** Telin direnci özdirenç $\rho$, boy $L$ ve kesit alanı $A$ ile belirlenir. Sıcaklıkla telin boyu uzarsa direnç artar; kesit alanı büyürse direnç azalır. Endüstride sıvı sıcaklığı ölçmek için kullanılan, dayanıklı metal kılıflı platin dirençli termometreler bu ilkeyle çalışır, doğrusaldır ama duyarlılığı düşüktür. Termistörler aynı mantıkla çalışan, daha küçük ve gündelik devrelerde kullanılan, doğrusal olmayan elemanlardır.

- **pn eklem sıcaklık sensörü.** Diyot özelliği gösteren yarı iletken bir elemandır; ucuz, doğrusal ve kullanımı kolaydır, ama yarı iletken malzemenin doğası gereği sıcaklık aralığı sınırlıdır (ekranda yaklaşık $-50$ °C ile $150$ °C). Yarı iletkenler ve diyotlar sonraki derslerin konusudur.

- **Diğer sensörler.** Işık sensörleri merdiven otomatiği ve sokak lambalarında, düşen ışığa göre iletkenliği değişen elemanlardır. Basınç (gerinim) sensörleri gerildiklerinde iç yolları arasındaki mesafe değiştiği için direnç değiştirir. Asansör kapısındaki ışık anahtarında bir tarafta ışık kaynağı, karşıda alıcı vardır; ışın kesilince kapıyı kapatmama sinyali üretilir. Kodlayıcılar şeritli bir yüzeyi okuyup konum ve dönüş bilgisi verir (barkod okuyucuya benzer). <!-- BELİRSİZ: Hoca IMU'yu yeryüzü manyetik alanına dayalı hız sensörü gibi anlattı; ayrıntı net değil. -->

- **Gerilim bölücü ile arayüz.** Ekrandaki devrede $V$ kaynağı, üstte sabit $R_1$, altta sensör $R_s$ vardır; çıkış iki direncin birleşim noktasından alınır: $V_o = V R_s/(R_1+R_s)$. Örneğin bir alkış devresinde ses sensörünün direnci değişince $V_o$ değişir ve bu değişim bir LED'i yakmak için kullanılır.

> **Ders sonrası not:** Hoca, direnç artınca sensördeki gerilimin düştüğünü, kesit alanı artıp direnç azalınca da üzerine düşen gerilimin arttığını söyledi. Ekrandaki gerilim bölücüde (sensör alt kolda) durum tersidir: $R_s$ arttıkça $V_o = V R_s/(R_1+R_s)$ artar, $R_s$ azaldıkça düşer. Örneğin $V=5$ V, $R_1=10$ kΩ için $R_s=5$, $10$, $20$ kΩ değerlerinde $V_o \approx 1{,}67$, $2{,}5$, $3{,}33$ V olur.

- **Anahtar sıçraması.** Anahtar açıkken $R_1$ üzerinden akım akmaz ve $V_o = V$ olur; kapanınca çıkış $0$'a iner. Ekrandaki grafikte anahtar kapandıktan hemen sonra çıkış çok kısa bir süre içinde birkaç kez salınır. Hoca bu salınımı yazılımsal ya da donanımsal yöntemlerle bastırmanın başka derslerde ele alınacağını söyledi.

> **Ders sonrası not:** Hoca salınımı anahtarın iç direncine ve kaçak akımlara bağladı. Anahtar sıçramasının asıl nedeni büyük olasılıkla mekanik kontakların kapanırken fiziksel olarak birkaç kez sekmesidir.

- **Eyleyiciler ve motorlar.** Diyafonla apartman kapısının açılması (elektriksel sinyalin mekanik kilidi tetiklemesi), ısıtıcılar (yüksek dirençte elektrik enerjisinin ısıya dönüşmesi), lambalar, LED ve LCD eyleyici örnekleridir. Fiber optik iletişimde elektriksel sinyal ışığa çevrilip cam ya da polimer kablodan gönderilir, karşıda tekrar elektriğe çevrilir; polimer kablolar kısa mesafede (ekranda yaklaşık 20 m), cam kablolar yüzlerce kilometrede kullanılır. Adım motorunda sargılara sırayla (A, B, C, ...) gerilim verilerek rotor adım adım döndürülür; bu, Arduino gibi bir kartla bir döngü içinde programlanabilir. Açısal konum bilgisi bilinmeyen sıradan bir motorla, örneğin su ibriğini çevirip geri getiren bir robot kolunda, ibriğin nereye baktığı bilinemez.

- **Osiloskop.** Devredeki gerilimi zaman ekseninde gösteren ölçü aletidir. Multimetre yalnız sayısal değer ve gerekirse eksi işareti gösterir; osiloskopta sinyalin DC mi AC mi olduğu ve dalga biçimi görülür.

- **LM35 veri sayfası.** Hoca LM35 veri sayfasını açıp performans ölçütlerinin nasıl okunduğunu gösterdi (ekrandan, 01:20:00): ölçüm aralığı $-55$ °C ile $+150$ °C, ölçek çarpanı $+10{,}0$ mV/°C, $+25$ °C'de garanti edilen doğruluk $0{,}5$ °C, besleme 4-30 V. Besleme 30 V'un üstüne çıkarsa sensör çalışmaz. Tam aralık devresinde çıkış $150$ °C'de $+1500$ mV, $25$ °C'de $+250$ mV, $-55$ °C'de $-550$ mV'tur (10 mV/°C ile doğrulandı).

> **Ders sonrası not:** Hoca doğrusallığı "0'da 10, 1'de 20" diye örnekledi. 10 mV/°C ölçek çarpanıyla çıkış 0 °C'de 0 mV, 1 °C'de 10 mV'tur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
