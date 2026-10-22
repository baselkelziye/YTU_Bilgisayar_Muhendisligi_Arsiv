# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin tarihi 25 Mart 2021 Perşembe. Kayıt iki parçadan oluşur.
  - İlk yaklaşık bir saat Lab 0 tanıtımıdır. Bu kısmı Erkan Hoca'nın grubunun araştırma görevlisi anlatır. Hamza Hoca'nın grubunda bu görevi Mecit Hoca yürütür.
  - Asıl ders yaklaşık 00:58'de başlar.
- Lab 0: laboratuvarın işleyişi
  - Beş deney yapılır. Deneyler iki haftada bir, iki grupta aynı anda yapılır.
  - Sorular deney saatinde verilir. Öğrenci 2 saat içinde raporunu PDF olarak Google Forms ile yükler.
  - Katılmayan öğrenci o deneyden 0 alır. Boş PDF kabul edilmez. Kopya ve kopyala-yapıştır yasaktır.
  - Raporda bütün formüller, hesaplar ve simülasyon ekran görüntüleri bulunmalıdır.
  - Bütün iletişim Google Classroom üzerinden yapılır.
- Lab 0: donanım tanıtımı (pandemi nedeniyle yalnızca gösterildi)
  - Breadboard: aynı satır veya sütundaki delikler birbirine bağlıdır. İki direncin bacakları aynı iki hatta takılırsa dirençler paraleldir.
  - Multimetre gerilim, akım ve direnç ölçer. Direnç renk kodları ve kondansatörler de gösterildi. Osiloskop yalnızca tanıtıldı.
- Lab 0: Proteus kullanımı
  - Proteus önerilir. Multisim de kullanılabilir. Demo sürüm projeyi kaydetmez, bu yüzden raporda ekran görüntüsü yeterlidir.
  - Yeni proje: File, New Project, ad ve konum, "Create a schematic from the selected template" (Default), PCB yok, firmware yok, Finish.
  - Eleman eklemek için "P" düğmesi kullanılır. Arama kutusuna "resistance" veya "source" yazılır. Değer çift tıklanarak değiştirilir (ör. 10k yerine 20k, 20 V yerine 30 V).
  - Toprak (ground) Terminals bölümünden eklenir. DC ampermetre ve voltmetre Instruments simgesinden alınır.
  - Ampermetre seri, voltmetre paralel bağlanır.
  - Okulun distro sürümü bazı Windows sistemlerde hata verebilir.
- Duyurular
  - Google Classroom'a üye olun. Duyurular oradan yapılır.
  - Dersten sonra Lab 0 oturumuna online.yildiz üzerinden ayrıca bağlanmak gerekir. Muafiyet bilgileri Classroom'daki belgededir.
- Gerilim bölücü
  - Seri bağlı $R_1$ ve $R_2$ için KVL: $-V + IR_1 + IR_2 = 0$. Buradan $I = \frac{V}{R_1 + R_2}$.
  - Genel kural: $V_k = V \frac{R_k}{R_{eş}}$. Büyük direnç büyük gerilim alır.
  - LED örneği: 9 V kaynak, LED 20 mA akım ve 1.4 V gerilim istiyor. Seri direncin gerilimi $9 - 1.4 = 7.6$ V, direnç $R = \frac{7.6}{0.02} = 380\ \Omega$.
  - Pratik ölçüm: 8.4 V kaynak, 10, 30 ve 100 Ω seri. Gerilimler 0.6, 1.8 ve 6 V, akım 60 mA.
    - Voltmetrenin uçları ters bağlanırsa −6 V okunur. Ampermetre ters bağlanırsa −60 mA okunur.
    - Ölçüm kademesi: 2 V kademesi 20 V kademesinden daha hassastır. Ölçülen değer kademeyi aşmamalıdır.
- Gerilim bölücü örnekleri
  - Örnek 1: $20 \sin 377t$ V kaynak, 3 kΩ ve 4 kΩ seri. $V_1 = 8.57 \sin 377t$ V, $V_2 = 11.43 \sin 377t$ V.
  - Örnek 2: 1 V kaynak, 200, 400 ve 100 Ω seri. Gerilimler 0.286, 0.571 ve 0.143 V.
  - Örnek 3: $12 \sin t$ V kaynak, 4 Ω seri, ardından paralel 6 Ω ve 3 Ω. $6 \parallel 3 = 2\ \Omega$, $v_x = 12 \sin t \cdot \frac{2}{6} = 4 \sin t$ V.
- Akım bölücü
  - İki paralel direnç: $I_1 = I \frac{R_2}{R_1 + R_2}$. Akım küçük dirençli kola daha çok gider.
  - Genel kural: $I_k = I \frac{R_{eş}}{R_k}$. İletkenlikle yazılırsa $I_k = I \frac{G_k}{G_{eş}}$. Bu, gerilim bölücünün dual (eşlenik) hâlidir.
  - Paralellik gösterimi: $R_1 \parallel R_2 = \frac{R_1 R_2}{R_1 + R_2}$.
  - Ampermetre kısa devre gibi davranır ve seri bağlanır. Bir kolun akımını ölçmek için o koldaki elemanın ucu ayrılır ve aradaki boşluk ampermetre ile tamamlanır. Ana hatta bağlanan ampermetre toplam akımı ölçer.
  - Pratik ölçüm: 12 V kaynak, paralel 1 kΩ ve 3 kΩ. Kol akımları 12 mA ve 4 mA, toplam 16 mA.
- Akım bölücü örnekleri
  - Örnek 4: 4 A kaynak, paralel 200, 400 ve 600 Ω. $R_{eş} = 109.09\ \Omega$. $I_1 = 2.18$ A, $I_2 = 1.09$ A, $I_3 = 0.727$ A.
  - Örnek 5: 1 V DC ve $0.5 \sin 20t$ V kaynaklar seri. $R_1 = 200\ \Omega$ seri, ardından paralel $R_2 = 400\ \Omega$ ve $R_3 = 100\ \Omega$.
    - $R_p = 400 \parallel 100 = 80\ \Omega$, $R_{eş} = 280\ \Omega$.
    - $I_1 = 3.571 + 1.786 \sin 20t$ mA.
    - $V_1 = 0.714 + 0.357 \sin 20t$ V, $V_p = 0.286 + 0.143 \sin 20t$ V.
    - $I_2 = \frac{V_p}{400} = 0.714 + 0.357 \sin 20t$ mA, $I_3 = \frac{V_p}{100} = 2.857 + 1.429 \sin 20t$ mA.
- Yıldız-üçgen (Y-Δ) ve T-π dönüşümleri
  - Y bağlantısında üç direnç ortak bir düğümde birleşir. Δ (üçgen) bağlantısında üç direnç bir üçgen oluşturur.
  - T bağlantısı Y'nin, π bağlantısı Δ'nın farklı çizimidir.
  - Üç direnç eşitse: $R_Δ = 3 R_Y$.
  - Dönüşüm formüllerinin ispatı teoremlerden (Thevenin vb.) sonra yapılacak.
  - Kullanım alanı: güç sistemleri ve üç fazlı motorlar. Hocaya göre Y bağlantı düşük devirde, Δ bağlantı yüksek devirde daha iyi tork verir.
  - Dirençleri eşit bir Y bağlantıya aynı genlikte ve 120° faz farklı üç AC kaynak verilirse ortak düğümün gerilimi her zaman 0 olur. Bu yüzden dördüncü (nötr) tele gerek kalmaz.
- Köprü devreleri
  - İki gerilim bölücü aynı kaynağa paralel bağlanır. Ölçüm, iki bölücünün orta noktaları (C ve D) arasında yapılır.
  - Sık yapılan breadboard hatası: C ve D noktalarını birbirine bağlamak. Bu durumda $V_{CD} = 0$ okunur.
  - Sensör uygulaması: sıcaklık gibi ortam etkileri dört direnci aynı biçimde etkiler ve birbirini götürür. Yalnızca algılayıcı koldaki fark $V_{CD}$ olarak okunur.
  - Bölücüye seri eklenen sabit bir direnç ölçüm aralığını sınırlamak için kullanılır.
  - Köprüler ardışık Y yapılarıyla veya iç içe iki Δ yapısıyla da kurulabilir.
- Doğrusal denklem sistemleri
  - Çözüm için determinant sıfırdan farklı olmalıdır. Denklemler doğrusal bağımsız olmalıdır.
  - Cramer kuralı: $x = \frac{D_x}{D}$. 3×3 determinant için Sarrus kuralı.
  - Matris tersi ile çözüm: $A x = b$ ise $x = A^{-1} b$. MATLAB'da `inv(A)*b`.
- Düğüm (node) analizi
  - Adımlar: referans düğümü seç, diğer düğümlere gerilim ata, her düğümde KCL yaz, sistemi çöz.
  - Düğüm gerilimleri referans düğüme göre tanımlanır.
  - Örnek 1: $V_{in} = 10$ V, $R_1 = 9$ k, $R_2 = 2$ k, $R_3 = 5$ k, $R_4 = 3$ k, $R_5 = 1$ k, $R_6 = 7$ k (Ω).
    - Bağlantı: $V_{in}$ artı ucu, $R_1$, düğüm $V_2$, $R_2$, düğüm $V_3$. $V_3$ ile $V_5$ arasında $R_3$. $V_3$ ile $V_4$ arasında $R_4$, $V_4$ ile $V_5$ arasında $R_5$. $V_5$ ile referans arasında $R_6$.
    - Denklemler: $\frac{10 - V_2}{9k} = \frac{V_2 - V_3}{2k} = \frac{V_5}{7k}$, $\frac{V_2 - V_3}{2k} = \frac{V_3 - V_5}{5k} + \frac{V_3 - V_4}{3k}$, $\frac{V_3 - V_4}{3k} = \frac{V_4 - V_5}{1k}$.
    - Çözüm: $V_2 = 5.55$ V, $V_3 = 4.56$ V, $V_4 = 3.74$ V, $V_5 = 3.46$ V.
    - $R_4$ ve $R_5$ seri olduğu için birleştirilirse bilinmeyen sayısı üçe iner.
  - Örnek 2: 2 A ve 4 A akım kaynakları, 7 Ω ve 3 Ω (seri, toplam 10 Ω), $v_1$ ile $v_2$ arasında 15 Ω, 5 Ω.
    - Düzenlenmiş denklemler: $5V_1 - 2V_2 = 60$, $-V_1 + 4V_2 = 60$.
    - Çözüm: $V_1 = V_2 = 20$ V. 15 Ω'dan geçen akım $i = 0$.
    - Hoca çözümü MATLAB ile gösterdi. Bir öğrenci bir işaret hatasını düzeltti.
    - İki akım kaynağı birleştirilemez, çünkü aradaki 15 Ω paralelliği bozar.
- Süper düğüm (supernode)
  - Uçlarından hiçbiri referansa bağlı olmayan gerilim kaynağına "yüzen" (floating) kaynak denir.
  - Gerilim kaynağı akımını kendisi belirlemez. Akımı komşu elemanlar belirler. Bu yüzden kaynağın iki ucu tek bir süper düğüm gibi ele alınır.
  - Slayt 28 örneği: $V_1$ a düğümünde, $V_2$ b ile c arasında yüzüyor.
    - Kısıt denklemi: $v_c = v_b + V_2$.
    - b'deki KCL: $\frac{V_1 - v_b}{R_2} - \frac{v_b}{R_3} + \frac{V_1 - (v_b + V_2)}{R_1} = 0$.
    - Toprak üzerinden çevre ile yazılırsa: $-V_C + V_2 + V_B = 0$.
- Ders sonu: gelecek hafta düğüm örneklerine devam edilecek ve çevre (mesh) analizine geçilecek. Slaytlar diğer grup aynı konuya gelince paylaşılacak.

## Hocanın Özellikle Vurguladığı Kısımlar

- Lab raporunda bütün formüller, hesaplar ve ekran görüntüleri olmalı. Rapor 2 saat içinde yüklenmeli, boş PDF kabul edilmez.
- Ampermetre seri (kısa devre gibi), voltmetre paralel (açık devre gibi) bağlanır. Kol akımı ölçülürken kol açılıp ampermetre araya konur.
- Köprü devresini kurarken C ve D noktalarını birbirine bağlamayın.
- Gerilim kaynağının akımını kaynak değil, komşu elemanlar belirler. Süper düğüm bu yüzden gerekir.
- Örnek 2'deki $V_1 = V_2$ durumu kısa devre değildir. Yalnızca iki düğüm arasında gerilim farkı yoktur.

## Kısa Tekrar Notları

- Gerilim bölücü: $V_k = V \frac{R_k}{R_{eş}}$.
- Akım bölücü: $I_k = I \frac{R_{eş}}{R_k} = I \frac{G_k}{G_{eş}}$. İki direnç için $I_1 = I \frac{R_2}{R_1 + R_2}$.
- $R_1 \parallel R_2 = \frac{R_1 R_2}{R_1 + R_2}$.
- Eşit dirençlerde $R_Δ = 3 R_Y$.
- Dengeli köprüde $V_{CD} = 0$.
- Düğüm analizi: referans seç, KCL yaz, $A x = b$ çöz.
- Yüzen gerilim kaynağı: süper düğüm ve bir kısıt denklemi.

## Detaylı Açıklamalar

### Y-Δ dönüşüm formülleri

Formül slaytı kayıtta net görünmüyor. Aşağıdaki standart formüller bu özete eklenmiştir.

- Gösterim: Y'de $R_1$ a ucuna, $R_2$ b ucuna, $R_3$ c ucuna bağlıdır. Δ'da $R_A$ a ile c, $R_B$ a ile b, $R_C$ b ile c arasındadır.
- Δ'dan Y'ye: $R_1 = \frac{R_A R_B}{R_A + R_B + R_C}$, $R_2 = \frac{R_B R_C}{R_A + R_B + R_C}$, $R_3 = \frac{R_A R_C}{R_A + R_B + R_C}$.
  - Kural: Y direnci, o uca bağlı iki Δ direncinin çarpımının Δ dirençleri toplamına bölümüdür.
- Y'den Δ'ya: $R_B = \frac{R_1 R_2 + R_2 R_3 + R_3 R_1}{R_3}$, $R_A = \frac{R_1 R_2 + R_2 R_3 + R_3 R_1}{R_2}$, $R_C = \frac{R_1 R_2 + R_2 R_3 + R_3 R_1}{R_1}$.
  - Kural: Δ direnci, çarpımlar toplamının karşı uçtaki Y direncine bölümüdür.
- Kontrol: üç Y direnci $R$ ise her Δ direnci $\frac{3R^2}{R} = 3R$ olur.

### Köprü devresi (slayt 41)

- Kaynak $V_T$. Sol kolda iki $R$ seri, sağ kolda $R$ ve $R - δR$ seri. C sol kolun, D sağ kolun orta noktasıdır.
- $V_C = \frac{V_T}{2}$, $V_D = \frac{R - δR}{2R - δR} V_T$.
- $V_{CD} = V_C - V_D = \frac{δR}{2(2R - δR)} V_T$.
- $δR$ küçükse $V_{CD} \approx \frac{δR}{4R} V_T$. Çıkış gerilimi direnç değişimiyle yaklaşık doğrusal değişir.
- $δR = 0$ ise köprü dengededir ve $V_{CD} = 0$.

### Düğüm analizi örnek 1 akımları

- $R_1$, $R_2$ ve $R_6$ aynı akımı taşır: $I = 0.495$ mA.
- $R_3$ akımı $0.220$ mA, $R_4$ ve $R_5$ akımı $0.275$ mA. Toplam $0.220 + 0.275 = 0.495$ mA, KCL sağlanır.

### Ders sonrası notlar

- **Slayt 41 köprü formülleri:** Slayttaki ara adımlar ve sonuç hatalı. Sonuç ifadesi $δR = 0$ için $V_{CD} = V_T$ veriyor. Dengeli köprüde bu değer 0 olmalıdır. Doğru ifadeler yukarıdaki "Köprü devresi" başlığındadır.
- **Örnek 4 eşdeğer direnç formülü:** Slaytta $R_{eş}$ formülünde $\frac{1}{R_2}$ iki kez yazılmış, $\frac{1}{R_3}$ unutulmuş. Doğrusu $\frac{1}{R_{eş}} = \frac{1}{200} + \frac{1}{400} + \frac{1}{600}$, yani $R_{eş} = 109.09\ \Omega$. Slayttaki sayısal sonuçlar doğrudur.
- **Örnek 2 ve Örnek 5 direnç değerleri:** Altyazıdaki "110" ve "410" değerleri tanıma hatasıdır. Gerilim bölücü örneğinde dirençler 200, 400 ve 100 Ω'dur. Örnek 5'te $I_2 = \frac{V_p}{400}$ ve $I_3 = \frac{V_p}{100}$ olmalıdır.
- **"Kısa devre gibi" ifadesi:** Düğüm örnek 2'de $V_1 = V_2$ çıkınca hoca önce "kısa devre gibi" dedi, sonra düzeltti. 15 Ω kısa devre değildir. Yalnızca uçları arasında gerilim farkı olmadığı için akım geçmez.
- **Y-Δ formülleri:** Formüller derste net okunamadığı için standart hâlleri bu özete eklendi. Kendi slaytınızdaki harf düzeniyle karşılaştırın.
- **Düğüm analizi sayıları:** Örnek 1'in düğüm gerilimleri ve akımları slayttaki denklemlerden yeniden hesaplanarak kontrol edilmiştir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
