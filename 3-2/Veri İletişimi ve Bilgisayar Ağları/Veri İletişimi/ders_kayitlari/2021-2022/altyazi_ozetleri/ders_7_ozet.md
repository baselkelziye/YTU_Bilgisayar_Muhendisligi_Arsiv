# Ders 7 Çalışma Özeti

## Genel Konular

- Dersin tarihi 25 Ekim 2021 Pazartesi. Ders online yapıldı.
  - Asıl anlatım yaklaşık 00:04:39'da başlıyor.
  - Ders yaklaşık 00:57'de bitiyor. Bu grup diğer gruplardan önde olduğu için hoca dersi erken kesti.
- Önceki dersin tekrarı: Manchester ve diferansiyel Manchester.
- Bipolar kodlama: AMI, B8ZS, HDB3.
- Örneksel-sayısal kodlama
  - PAM (Pulse Amplitude Modulation).
  - PCM (Pulse Code Modulation).
  - Örnekleme teoremi (Nyquist).
- Sayısal-örneksel kodlama
  - Taşıyıcı işaret.
  - Bit hızı ve baud hızı.
  - ASK, FSK, PSK, QAM.
- Örneksel-örneksel kodlama: AM, FM, PM.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Bipolar kodlamanın amacı DC bileşenden kurtulmaktır:** 1'ler sırayla pozitif ve negatif kodlanır. Uzun vadede ortalama gerilim sıfır olur.
- **AMI'nin kalan sorunu uzun 0 dizileridir:** İşarette değişim olmaz ve alıcı senkronu kaybeder. B8ZS ve HDB3 bu dizileri bilerek "bozarak" çözer.
- **Bilgisayar haberleşmesinde bir uç hep sayısaldır:** Bu yüzden sayısal-sayısal, örneksel-sayısal ve sayısal-örneksel kodlamalar önemlidir. Örneksel-örneksel kısım hızlı geçildi.
- **Örneksel işaretin temel özelliği sürekliliktir:** Hoca "analog" cevabını eksik buldu. Gerçek zamanlı işletim sistemini "gerçek zamanlı işletim sistemi" diye tanımlamaya benzetti. Aradığı cevap süreklilikti (kesintisiz işaret).
- **Örnekleme kuralları:** Örnekler eşit aralıklarla alınmalıdır. Örnekleme hızı da işaretin karakterini yakalayacak kadar yüksek olmalıdır.
- **Nyquist örnekleme teoremi:** Kayıpsız geri elde etmek için en yüksek frekans bileşeninin en az iki katı hızda örnek alınır. Ses için en yüksek frekans 4 kHz alınırsa saniyede 8000 örnek gerekir.
- **Bit hızı her zaman baud hızına eşit veya ondan büyüktür:** Bir baud (sembol) birden fazla bit taşıyabilir.
- **ASK'de hangi genliğin 0, hangisinin 1 olduğuna uygulayan karar verir.** Bu bir standart değil, tasarım kararıdır.
- **ASK gürültüye karşı hassastır:** Dış etkiler önce genliği değiştirir. 0 ve 1 karışabilir. FSK frekansla çalıştığı için daha dayanıklıdır (robust).
- **Taşıyıcı frekansı ne kadar yüksekse taşıma kapasitesi o kadar yüksektir.**
- **Gerçek veri iletiminde çoğunlukla QAM kullanılır.** Saf ASK veya FSK pek kullanılmaz.

## Kısa Tekrar Notları

- Manchester:
  - 1 = negatiften pozitife geçiş.
  - 0 = pozitiften negatife geçiş.
- Diferansiyel Manchester:
  - Bit başında geçiş varsa 0, yoksa 1.
  - Bit ortasında her zaman geçiş vardır.
- AMI (Alternate Mark Inversion):
  - 0 = 0 V.
  - 1'ler sırayla $+$ ve $-$ ile kodlanır.
  - Aradaki 0'lar 1'lerin polaritesini etkilemez.
- B8ZS (Bipolar with 8-Zero Substitution):
  - 8 ardışık 0 yerine özel bir desen konur.
  - Kuzey Amerika'da kullanılır.
- HDB3 (High Density Bipolar 3):
  - 4 ardışık 0 yerine özel bir desen konur.
  - Avrupa ve Japonya'da kullanılır.
- PAM: analog işaretten belli anlarda gerilim değeri örnekleri alır.
- PCM:
  - PAM örneklerini sayısal değerlere çevirir.
  - Telefonda 8 bit kullanılır: 1 işaret biti ve 7 değer biti, $-127$ ile $+127$ arası.
  - Yüksek kalite için 16 veya 24 bit PCM de kullanılır.
- Örneksel-sayısal adımları:
  1. PAM ile örnekle.
  2. PCM ile sayıya çevir.
  3. İkili diziye dönüştür.
  4. Sayısal-sayısal bir kodlamayla hatta gönder.
- Sayısal-örneksel kodlamada taşıyıcı işaretin bir özelliği değiştirilir. Buna kipleme veya modülasyon (modulation, keying) denir.
  - ASK (Amplitude Shift Keying): genlik değişir. Frekans ve faz sabit kalır.
  - FSK (Frequency Shift Keying): frekans değişir. Genlik ve faz sabit kalır.
  - PSK (Phase Shift Keying): faz değişir.
  - QAM (Quadrature Amplitude Modulation): genlik ve faz birlikte değişir.
- Bağlantı kapasitesi üç şeye bağlıdır: hattın taşıma kapasitesi, modülasyon tekniği ve taşıyıcı frekansı.
- Bit hızı = baud hızı × (sembol başına bit sayısı).
- Bir sembolde taşınan bit grubunun adı:
  - 2 bit: dibit.
  - 3 bit: tribit.
  - 4 bit: quadbit.
  - 5 bit: pentabit.
- Örneksel-örneksel kodlamalar:
  - AM (Amplitude Modulation): taşıyıcının genliği ses işaretiyle kiplenir.
  - FM (Frequency Modulation): taşıyıcının frekansı kiplenir.
  - PM (Phase Modulation): taşıyıcının fazı kiplenir.

## Detaylı Açıklamalar

### B8ZS Ayrıntısı

- 8 ardışık 0'dan önceki son işaret pozitifse:
  - İlk üç 0 olduğu gibi kalır.
  - Sonra $+$ ve $-$ gelir.
  - Sonra bir 0 gelir.
  - Sonra $-$ ve $+$ gelir.
  - Yani desen: $0\,0\,0\,+\,-\,0\,-\,+$.
- Önceki işaret negatifse desen bunun tersidir: $0\,0\,0\,-\,+\,0\,+\,-$.
- Bu desen normal AMI'de oluşamayacak bilerek yapılmış ihlaller (bipolar violation) içerir. Alıcı deseni tanır ve yerine 8 tane 0 koyar.

### HDB3 Ayrıntısı

- 4 ardışık 0 yapay olarak bozulur.
- Bozmada son değiştirmeden bu yana gönderilen 1'lerin sayısına bakılır:
  - **Tek sayıda 1 geldiyse:** Desen $0\,0\,0\,V$ olur. Son 0 yerine önceki darbeyle aynı polaritede bir ihlal darbesi ($V$) konur. Önceki darbe pozitifse son 0 pozitif yapılır.
  - **Çift sayıda 1 geldiyse:** Desen $B\,0\,0\,V$ olur. İlk 0 yerine kurala uygun bir darbe ($B$) de eklenir.
- Böylece ihlal darbeleri de sırayla pozitif ve negatif olur. DC bileşen oluşmaz.
- Hoca slayttaki örnekte 9 tane ardışık 0 olan bir girişin nasıl bozulduğunu gösterdi.

### PAM Örneği ve Örnek Sayısı

- Slayttaki örnek işarette toplam 19 örnek alınmış. Bu örneklerle işaret neredeyse aynen yeniden oluşturulabilir.
- Örnek sayısı 6 olsaydı birden fazla işaret bu noktalara uyabilirdi.
- Sadece iki tepe noktasından örnek alınsaydı işaretin aşağı inişi hiç izlenemezdi.
- Bir öğrenci ADC (Analog-Digital Converter) dedi. Hoca örnekleme bağlamında bunu doğru buldu.
- Hoca ilginç bir not düştü: sıkıştırmalı algılama (compressed sensing). Bu yöntem, belirli koşullarda az örnekle (undersampling) de bilginin geri çıkarılabileceğini söylüyor. Merak edenlerin okumasını önerdi.

### PCM Dizisi

- PCM ile elde edilen dizi örneğin 16, 48, 50, 18, $-16$ gibi sayılardan oluşur.
- Bu sayılar ikili sisteme çevrilir. Sonra NRZ, Manchester gibi sayısal-sayısal bir kodlamayla gönderilir.
- Hangi kodlamanın seçileceği, bilginin hangi ortamdan nasıl gideceğine bağlıdır.

### Dial-Up ve DSL Farkı

- İnternetin ilk yaygınlaştığı dönemde telefon hattı üzerinden bağlanılıyordu (POTS, Plain Old Telephone System).
  - Sayısal bilgi, hattın ses için ayrılmış frekans aralığında örneksel işarete çevrilip gönderiliyordu.
  - Bu yüzden telefonu kaldırınca cızırtılı sesler duyuluyordu, çünkü iletim duyulabilir bantta yapılıyordu.
- DSL'de de aynı kablo kullanılıyor, ama kablonun ucu santraldeki DSLAM cihazına bağlıdır.
  - Ses bandının dışındaki daha yüksek frekanslar kullanılır.
  - Bu yüzden hız çok daha yüksektir.

### Taşıyıcı İşaret ve Saat Kayması

- Modülasyon için ortada değiştirilecek bir işaret olmalıdır. Buna taşıyıcı işaret (carrier) denir. Genelde yüksek frekanslıdır.
- Alıcı ve gönderici çoğu zaman taşıyıcı frekansı konusunda kendi aralarında otomatik olarak anlaşmalıdır (auto-negotiation).
- Sebebi şu: Frekans bir saatten (clock) elde edilir. Dağıtık sistemlerde iki tarafın saatleri birbirinden bağımsızdır. Hedef aynı frekans olsa da aralarında kaymalar (drift) olur.

### ASK, FSK, PSK Örnekleri

- **ASK örneği:**
  - Slayttaki işarette frekans değişmiyor, sadece tepe noktalarının yüksekliği değişiyor.
  - Her baud bir bit taşıyor. Bit hızı 5, baud hızı 5.
- **FSK örneği:**
  - 0 veya 1 olmasına göre frekans sıklaşıyor veya seyreliyor.
  - Yine 5 baud ve 5 bit.
- **PSK örneği:**
  - İki faz kullanılıyor: 0° ve 180°.
  - 180° kaydırılmış işaret alttan başlar.
  - Baud hızı ile bit hızı aynıdır.
- **4-PSK örneği:**
  - Dört faz kullanılıyor: 00 = 0°, 01 = 90°, 10 = 180°, 11 = 270°.
  - Her baud 2 bit taşıyor. Baud hızı 5 iken bit hızı 10 olur.
  - Faz adımı 45° gibi daha küçük de seçilebilir. Bu tasarım kararıdır.

### QAM

- 4 faz ve 1 genlik kullanılırsa 4-QAM elde edilir. Bu 4-PSK ile aynıdır, her baud 2 bit taşır.
- Asıl fark hem fazda hem genlikte birden fazla seviye kullanıldığında ortaya çıkar.
- **8-QAM:**
  - 4 faz ve 2 genlik kullanılır.
  - Yıldız diyagramında (constellation) iç içe iki kare görülür.
  - $2\times 4 = 8$ durum, yani her baud 3 bit taşır.
  - 5 baud ile bit hızı $5\times 3 = 15$ olur.
- **16-QAM:** Her baud 4 bit taşır. Bit hızı baud hızının 4 katıdır.
- Genel kural: $M$ durumlu bir QAM'de her sembol $\log_2 M$ bit taşır.

### AM ve FM

- Radyo yayını örneksel-örneksel kodlamanın günlük hayattaki örneğidir.
- AM daha uzak mesafelere gidebilir. Hoca sebebi dalga boyu ve iletim menzili ilişkisine bağlıyor. İyi bir antenle Amerika'daki bir AM yayınının burada dinlenebileceğini söylüyor.
- FM'de bu çok daha zordur.

### Ders sonrası notlar

- **FSK paragrafındaki kısaltma:** Hoca FSK'yi anlatırken bir kez "taşıyıcının sınırları PSK'nın efektifliği açısından önemli" dedi. Bağlama göre kastedilen FSK'dir.
- **DSLAM'ın açılımı:** Hoca "Digital Subscriber Line Access Modem" dedi. Doğrusu *Digital Subscriber Line Access Multiplexer*'dır. Bu cihaz, birçok abone hattını santralde bir araya getirir.
- **Telefon PCM hızı:** Saniyede 8000 örnek × 8 bit = 64 kbps eder. Bu değer, sayısal telefon şebekesinin temel kanal hızıdır (DS0).
- **Örnekleme hızı sınırı:** Kesin ifade şudur: örnekleme hızı en yüksek frekansın iki katından büyük olmalıdır ($f_s > 2f_{max}$). Ses bandı aslında 300-3400 Hz'dir. 4 kHz, koruma payıyla birlikte alınan kanal genişliğidir.
- **Sıkıştırmalı algılama:** Bu yöntem "kayıp önemsizse az örnek yeter" demek değildir. İşaretin uygun bir tabanda seyrek (sparse) olmasını şart koşar. Bu şart sağlanırsa Nyquist hızının altında alınan örneklerden işaret yüksek doğrulukla geri çıkarılabilir.
- **AM ve FM'de "uzun dalga - kısa dalga":** Hoca "uzun dalga AM, kısa dalga FM" dedi. Bu ifade yanıltıcı.
  - AM yayınları orta dalga (MW, yaklaşık 530-1700 kHz) ve uzun dalgadadır (LW). Dalga boyları yüzlerce metredir.
  - FM yayınları 88-108 MHz'te, VHF bandındadır. Dalga boyu yaklaşık 3 metredir.
  - "Kısa dalga" (shortwave, HF, 3-30 MHz) ayrı bir bant adıdır ve çoğunlukla AM yayını içerir.
  - AM'nin uzağa gitmesinin sebebi düşük frekanslı dalgaların yer dalgası olarak yayılması ve geceleri iyonosferden yansımasıdır (gök dalgası, skywave). VHF'deki FM ise çoğunlukla görüş hattıyla sınırlıdır.
- **Altyazı hataları:**
  - "Alternate Marked Immersion" Alternate Mark Inversion (AMI) demektir.
  - "Bipolar H0 synchronizing" ve "bipolar 80 synchronizing" B8ZS (Bipolar with 8-Zero Substitution) demektir.
  - "Pulse Amputate Modulation" Pulse Amplitude Modulation, "Postcode Modulation" Pulse Code Modulation demektir.
  - "Shift gain" ve "shift key" keying, "Quadritude" Quadrature demektir.
  - "Bout" ve "balt" baud, "EM" AM demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
