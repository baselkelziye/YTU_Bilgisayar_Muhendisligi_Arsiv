# Ders 1 Çalışma Özeti

## Genel Konular

- Dönemin ilk dersi (11 Mart 2021 Perşembe). Ders uzaktan, çevrim içi yapılır.
  - Dersi Dr. Erkan Uslu verir. Diğer grubun hocası Hamza Hoca'dır.
  - E-posta: euslu@yildiz.edu.tr. Konu satırı "[ders kodu][2020-2021 bahar] ad soyad numara" biçiminde yazılmalı.
  - Ders materyalleri ve duyurular Google Classroom üzerinden paylaşılır.
- Dersin işleyişi
  - Haftada 3 saat teori ve 2 saat laboratuvar vardır.
  - Beş deney yapılır. Deneyler iki haftada bir, simülasyon ortamında yapılır.
    - Program: Proteus 6.9. Okulun uzak masaüstü sistemi (distro.cc.yildiz.edu.tr) üzerinden kullanılır.
    - Deney konuları: Ohm kanunu, Kirchhoff akım ve gerilim yasaları, devre teoremleri, RC devreleri, işlemsel kuvvetlendirici (op-amp).
  - Devam zorunluluğu: teoride %70, laboratuvarda %80.
    - İki deneye katılmayan öğrenci (mazeretsiz) F0 alır.
    - Teori derslerine yaklaşık yarı yarıya devam eden öğrenci de F0 alır.
- Değerlendirme
  - Vize (8. hafta) %20.
  - İki kısa sınav (4. ve 13. hafta), her biri %5.
  - Beş deney, her biri %6, toplam %30.
  - Yıl içi toplamı %60, final %40.
  - Sınavlar online.yildiz üzerinden yapılır. Klasik ve çoktan seçmeli sorular olabilir. Sınav dili İngilizcedir.
  - Sınavlar ve not eğrisi (çan) diğer grupla ortaktır.
  - Kısa sınav, o haftanın dersiyle ilgili kısa bir sınavdır. İlk kısa sınavdan önce küçük bir deneme yapılabilir.
- Kopya ve benzerlik
  - Gönderilen ödev ve raporlara benzerlik analizi yapılır.
  - Kopya olduğu belirlenen gönderi, o çalışmanın en yüksek puanının eksisi olarak notlandırılır.
  - Hoca WhatsApp gruplarının cevap paylaşma ortamına dönüşmemesi için uyarır.
- Kaynak kitaplar
  - Hayt, Kemmerly, Durbin: Engineering Circuit Analysis (9. baskı).
  - Dorf, Svoboda: Introduction to Electric Circuits (9. baskı).
- Dönemin konuları
  - Temel tanımlar: yük, akım, gerilim, güç. Devre elemanları ve sembolleri. Ohm kanunu.
  - Kirchhoff akım ve gerilim yasaları, tek çevreli devreler. Seri ve paralel bağlama, gerilim ve akım bölücüler.
  - Düğüm gerilimleri ve çevre akımları yöntemleri. Matris biçiminde yazılmaları ve çözümleri. Süper düğüm ve süper çevre.
  - Devre teoremleri: doğrusallık ve süperpozisyon, kaynak dönüşümü, Thevenin ve Norton eşdeğerleri, maksimum güç aktarımı. Bu teoremler yalnız DC'de değil, AC sürekli hâlde de kullanılır.
  - İşlemsel kuvvetlendirici (op-amp).
  - RL ve RC devreleri (birinci dereceden devreler).
  - Sinüzoidal sürekli hâl (AC) analizi.
  - Vize sonrası: AC'de devre teoremleri (10. hafta Ramazan Bayramı'na denk gelir).
  - Frekans cevabı, Bode diyagramları, filtreler (12. hafta civarı).
  - Laplace dönüşümü ve s-domeni (son iki hafta). Zaman kalmazsa çıkarılabilir.
  - Dersin temel amacı: bir devredeki herhangi bir elemanın akımını ve uçları arasındaki gerilimi bulmak. Buradan elemanın harcadığı veya devreye verdiği güç hesaplanır.
- Birimler ve SI sistemi
  - SI temel birimleri: metre (uzunluk), kilogram (kütle), saniye (zaman), amper (akım), kelvin (sıcaklık), mol (madde miktarı), kandela (ışık şiddeti).
  - Ön ekler: atto ($10^{-18}$), femto ($10^{-15}$), piko ($10^{-12}$), nano ($10^{-9}$), mikro ($10^{-6}$), mili ($10^{-3}$), kilo ($10^{3}$), mega ($10^{6}$), giga ($10^{9}$), tera ($10^{12}$), peta ($10^{15}$), eksa ($10^{18}$).
  - Birim dönüşümü örneği: 1 dakikada 4000 m yol alan bir cismin hızı $\frac{4000\ \text{m}}{1\ \text{dk}} \cdot \frac{60\ \text{dk}}{1\ \text{sa}} \cdot \frac{1\ \text{km}}{1000\ \text{m}} = 240$ km/sa.
  - Anlamlı basamak ve yuvarlama: son basamak 5 veya büyükse bir üst basamak artırılır. Örnek: 3.186, iki ondalık basamağa 3.19, bir ondalık basamağa 3.2 olarak yuvarlanır.
- Yük ve akım
  - Yükün birimi coulomb (C). Elektronun yükü $-1.602 \times 10^{-19}$ C'dir.
  - Akım, yükün zamana göre değişimidir: $i = \frac{dq}{dt}$. Birimi amper (A = C/s).
  - Elektronların hareket yönü, akımın (konvansiyonel akım) yönünün tersidir. Derste her zaman konvansiyonel akım yönü kullanılır.
  - Su benzetmesi: akım borudaki su akışına, gerilim su seviyeleri arasındaki farka benzer.
  - Büyük harfli semboller ($I$, $V$) sabit (DC) değerleri, küçük harfli semboller ($i(t)$, $v(t)$) zamanla değişen değerleri gösterir.
- Gerilim
  - Gerilim, birim yük başına yapılan iştir: $v = \frac{dw}{dq}$. Birimi volt (V = J/C).
  - Gerilim iki nokta arasındaki potansiyel farkıdır. Bir noktanın gerilimi, referans düğümüne (toprak, ground) göre ölçülür. Referans düğümü 0 V kabul edilir.
  - Gerilim tanımlanırken artı ve eksi uçlar belirtilir. Ters yönde tanımlanan gerilim, aynı değerin eksi işaretlisidir.
- Güç ve enerji
  - Güç: $p = \frac{dw}{dt} = \frac{dw}{dq} \cdot \frac{dq}{dt} = v \cdot i$. Birimi watt (W = J/s).
  - Enerji günlük hayatta kilowatt-saat (kWh) birimiyle ölçülür.
  - Pasif işaret kuralı: akım elemana artı uçtan giriyorsa $p = vi$ elemanın **çektiği (harcadığı)** güçtür.
    - $p > 0$: eleman güç çeker.
    - $p < 0$: eleman devreye güç verir.
  - Bir devrede bütün elemanların güçlerinin toplamı sıfırdır (enerjinin korunumu).
- Devre elemanları
  - Aktif elemanlar devreye enerji verebilir (kaynaklar). Pasif elemanlar enerji harcar veya depolar (R, L, C).
  - İdeal bağımsız gerilim kaynağı: uçları arasındaki gerilim farkını sabit tutar. Üzerinden geçen akımı devrenin geri kalanı belirler.
  - İdeal bağımsız akım kaynağı: bağlı olduğu koldaki akımı sabit tutar. Uçları arasındaki gerilimi devrenin geri kalanı belirler.
  - Bağımlı kaynaklar baklava (eşkenar dörtgen) sembolüyle çizilir. Değeri devredeki başka bir gerilime veya akıma bağlıdır. Dört türü vardır:
    - Gerilim kontrollü gerilim kaynağı (VCVS): $v = \mu v_x$.
    - Akım kontrollü gerilim kaynağı (CCVS): $v = r i_x$.
    - Gerilim kontrollü akım kaynağı (VCCS): $i = g v_x$.
    - Akım kontrollü akım kaynağı (CCCS): $i = \beta i_x$.
  - Direnç (R, ohm Ω), endüktans (L, henry H), kapasite (C, farad F).
    - Endüktans derste genellikle mH, kapasite μF, nF veya pF mertebesinde kullanılır. Birim dönüşümlerine dikkat edilmeli.
    - DC sürekli hâlde endüktans kısa devre, kapasite açık devre gibi davranır.
  - Ampermetre devreye seri bağlanır. İdeal ampermetre kısa devre gibidir.
  - Voltmetre ölçülen elemana paralel bağlanır. İdeal voltmetre açık devre gibidir.
  - Sigorta devreye seri bağlanır ve yalnızca aşırı akıma karşı korur. Hızlı ve yavaş atan türleri vardır.
  - Anahtar (switch):
    - "Açık" anahtar bağlantıyı keser, akım akmaz.
    - "Kapalı" anahtar iletimi sağlar, akım akar.
  - Toprak (earth) ile devre referansı (ground) farklı kavramlardır. Binadaki topraklama hattı, toprağa çakılmış bakır bir kazıkla yapılır. Derste "ground", devredeki bütün gerilimlerin ölçüldüğü referans noktasıdır.
  - Kablolar: kalınlık AWG standardıyla belirtilir. Yarıçap arttıkça akım taşıma kapasitesi artar. İdeal kablo direnci sıfır olan bir kısa devredir. Kablonun üzerindeki bütün noktalar aynı gerilimdedir.
- Ohm kanunu
  - Bir direnç üzerindeki gerilim, üzerinden geçen akımla doğru orantılıdır: $v = R i$. Orantı katsayısı direncin değeridir.
  - Akım ve gerilim pasif işaret kuralına göre tanımlanır: akımın elemana girdiği uç artı, çıktığı uç eksidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Devamsızlık sınırlarına uyun. İki deneye katılmamak doğrudan F0 demektir.
- Kopya ve benzerlik konusunda katı davranılır. WhatsApp gruplarında cevap paylaşmayın.
- E-postaları istenen konu satırıyla gönderin.
- Birimler ve ön ekler çok önemlidir. Özellikle mH, μF, nF, pF dönüşümlerinde hata yapmayın.
- Referans yönlerini bir kez seçin ve bütün devre boyunca tutarlı kullanın. Gücün işareti bu yönlere bağlıdır.
- Gerilim kaynağı yalnızca kendi uçları arasındaki farkı belirler. Artı ucunun gerilimi devrenin geri kalanına bağlıdır. Örnek: toprağa bağlı 3 V'luk bir kaynağın üstüne 5 V'luk ikinci bir kaynak seri bağlanırsa üst düğüm 8 V olur.
- Anahtarda "açık" ve "kapalı" kavramlarını karıştırmayın. Açık anahtar iletmez.
- Referans olarak seçilen düğüm her zaman 0 V'tur.

## Kısa Tekrar Notları

- $i = \frac{dq}{dt}$, $v = \frac{dw}{dq}$, $p = vi$.
- Akım artı uçtan giriyorsa: $p > 0$ çeker, $p < 0$ verir.
- Devredeki güçlerin toplamı 0'dır.
- Gerilim kaynağı: gerilim sabit, akım devreye bağlı. Akım kaynağı: akım sabit, gerilim devreye bağlı.
- Bağımlı kaynak türleri: VCVS, CCVS, VCCS, CCCS.
- DC'de L kısa devre, C açık devre.
- Ampermetre seri (kısa devre), voltmetre paralel (açık devre).
- Açık anahtar: akım yok. Kapalı anahtar: akım var.
- Ohm: $v = Ri$.

## Detaylı Açıklamalar

### Güç işareti örnekleri

- Bir akım kaynağı 3 A veriyor. Bağlı olduğu elemanın uçları arasında 1 V var ve akım bu elemana artı uçtan giriyor.
  - Eleman: $p = (1)(3) = 3$ W çeker.
  - Akım kaynağı: akım kaynağın artı ucundan çıkar. $p = -(1)(3) = -3$ W, yani 3 W verir.
  - Toplam $3 - 3 = 0$.
- Aynı eleman 1 V'luk bir gerilim kaynağı olsa da sonuç değişmez. Akım gerilim kaynağına artı ucundan girdiği için gerilim kaynağı 3 W çeker. Gerilim kaynakları her zaman güç vermez. Şarj edilen bir akü buna örnektir.
- Öğrenci sorusu: gerçek akım kaynakları her gerilimde çalışabilir mi? Hayır. Gerçek akım kaynakları yalnızca belirli bir gerilim aralığında belirtilen akımı sağlar. Derste ideal kaynaklar kullanılır.

### Ohm kanunu örnekleri

- 2 Ω'luk bir direncin uçları arasında 4 V varsa akım $i = \frac{4}{2} = 2$ A'dir.
- 1 V'luk gerilim kaynağı ile 1 Ω'luk direnç tek bir çevre oluşturuyor. Akım $1$ A'dir.
- Bir düğümün gerilimi bilinmiyorsa (ör. $x$ volt), o düğüm toprağa bağlanarak referans yapılır. Böylece bilinmeyen $x$ ortadan kalkar ve diğer düğümler ona göre hesaplanır.
- Açık devre durumunda akım akacak bir yol yoktur. Direnç üzerinden akım geçmediği için direnç uçlarında gerilim düşümü olmaz.
- Son örnek: 10 V'luk bir gerilim kaynağı 4 kΩ'luk bir dirence bağlı.
  - Akım: $i = \frac{10}{4000} = 2.5$ mA.
  - Direnç: $p = (10)(2.5 \times 10^{-3}) = 25$ mW çeker.
  - Kaynak: akım kaynağın artı ucundan çıkar. $p = -25$ mW, yani 25 mW verir.
  - Toplam 0.

### Ders sonrası notlar

- **Son örnekteki akım:** Derste 01:57:39 civarında akım "2,5 amper" diye söylendi. Doğrusu $\frac{10\ \text{V}}{4\ \text{k}\Omega} = 2.5$ mA'dir. Güç hesabındaki 25 mW sonucu doğrudur.
- **Gerilim kaynağının akımı:** Derste 01:35:36 civarında "gerilim kaynağı üzerinden akan akım ideal durumda üzerindeki değere eşit" denildi. Bu cümle yanlıştır. Hocanın birkaç saniye sonra söylediği gibi, gerilim kaynağı yalnızca uçları arasındaki gerilimi belirler. Üzerinden geçen akımı devrenin diğer elemanları belirler. Akımı sabit tutan eleman akım kaynağıdır.
- **Adım adım yuvarlama:** Hoca yuvarlamanın en düşük basamaktan başlayarak adım adım yapılmasını önerdi. Bu yöntem yanlış sonuç verebilir (çift yuvarlama hatası). Örnek: 3.146 adım adım yuvarlanırsa önce 3.15, sonra 3.2 olur. Oysa 3.146'nın bir ondalık basamağa doğru yuvarlaması 3.1'dir, çünkü atılan kısım 0.046'dır ve 0.05'ten küçüktür. Yuvarlama her zaman doğrudan asıl sayıdan yapılmalıdır. Slayttaki 3.186 örneğinde iki yöntem aynı sonucu (3.2) verdiği için fark görünmez.
- **SI temel birimleri:** Derste coulomb temel birimlerle birlikte sayıldı ve mol listede yoktu. SI'da yedi temel birim vardır: metre, kilogram, saniye, amper, kelvin, mol, kandela. Coulomb türetilmiş bir birimdir ($1\ \text{C} = 1\ \text{A} \cdot \text{s}$). Kandela ışık şiddetinin birimidir.
- **Birimlerin tanımları:** Hoca birimlerin gözleme dayalı standartlar olduğunu, bugün atomik tanımlarla değiştirildiğini söyledi. Güncel tanımlar şöyledir:
  - Metre, ışığın boşlukta $\frac{1}{299\,792\,458}$ saniyede aldığı yoldur.
  - Kilogram ilk olarak 4 °C'deki 1 dm³ suyun kütlesi olarak, sonra bir prototip kütleyle tanımlanıyordu. 2019'dan beri Planck sabitiyle tanımlanır.
  - Saniye, sezyum-133 atomunun belirli bir geçişinde yayılan ışımanın 9 192 631 770 periyodudur. Derste "radyoaktif sezyum atomu" denildi. Sezyum-133 kararlı bir izotoptur, radyoaktif değildir.
- **Elektron yükü:** Elektronun yükü $-1.602 \times 10^{-19}$ C'dir. Derste büyüklüğü $1.6 \times 10^{-19}$ olarak kullanıldı. İşaret, elektronların akım yönünün tersine hareket etmesinin nedenidir.
- **Altyazıdaki hatalar:** Altyazıda "AC süreklisini zoidal hal" ifadesi "AC sürekli sinüzoidal hâl", "süper düğün" ifadesi "süper düğüm", "grant" ifadesi "ground", "I-Tripleen" ifadesi "IEEE", "3-5 toplam 8 volt" ifadesi "3 artı 5, toplam 8 volt" olarak okunmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
