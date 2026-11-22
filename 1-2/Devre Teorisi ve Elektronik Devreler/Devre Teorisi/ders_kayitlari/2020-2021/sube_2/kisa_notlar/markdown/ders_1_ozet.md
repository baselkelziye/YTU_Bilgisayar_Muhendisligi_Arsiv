# Ders 1 Çalışma Özeti

## Genel Konular

- Ölçü birimleri ve SI önekleri
  - Devre analizinde her sayısal sonuç birimiyle yazılır: "5" değil, "5 A" ya da "5 mV".
  - Derste en çok kullanılacak önekler slaytta işaretlenmiştir (ekrandan, 00:35:00): giga ($10^{9}$, G), mega ($10^{6}$, M), kilo ($10^{3}$, k), mili ($10^{-3}$, m), mikro ($10^{-6}$, $\mu$), nano ($10^{-9}$, n), piko ($10^{-12}$, p).
  - Birim dönüştürme adımları: önce denklemdeki bütün büyüklükleri aynı birim düzeyine getirmek, sonra sonucu istenen birime çevirmek. Hız örneği: 4000 m'yi 1 dakikada alan aracın km/sa cinsinden hızı için metre kilometreye, dakika saate çevrilir.
- Anlamlı basamak, doğruluk ve yuvarlama
  - Sayılar tam (12 elma) ya da yaklaşık olabilir; laboratuvarda alınan her okuma yaklaşık kabul edilir (ekrandan, 00:40:00).
  - Hassasiyet anlamlı basamak sayısıyla, doğruluk ölçülen değerin bilinen değere yakınlığıyla ilgilidir.
  - Derste sonuçlar virgülden sonra iki basamağa yuvarlanır: $3.186 \cong 3.19$.
- Bilimsel ve mühendislik gösterimi
  - Bilimsel gösterimde ondalık nokta, 1'e eşit ya da büyük ve 10'dan küçük ilk basamaktan hemen sonra gelir.
  - Mühendislik gösteriminde 10'un kuvvetleri 3'ün katıdır, mantis 1 ile 1000 arasındadır (ekrandan, 00:45:00).
  - Üslü sayılarla toplama, çıkarma, çarpma ve bölme kuralları birimli büyüklüklerde de aynen geçerlidir.
- Elektrik akımı ve elektron akımı
  - Elektrik, iletken içinde elektronların hareketiyle oluşur. Elektronlar çok oldukları yerden az oldukları yere, dengeyi sağlamak için hareket eder.
  - Elektron akımı (doğal akım, $\bar{I}$ ile gösterilir) elektronların hareket yönündedir. Ders boyunca kullanılan elektrik akımı $I$ ise bunun tersi yöndedir.
- Potansiyel fark ve su benzetmesi
  - Bir bardaktan diğerine su akması için yükseklik farkı gerekir; elektronların hareketi için de iki nokta arasında potansiyel fark (gerilim) gerekir.
  - Yükseklik farkını ya da bardaktaki su miktarını artırmak akışı güçlendirir; gerilimi artırmak da akımı artırır.
  - Toprak (ground) referans noktasıdır ve gerilimi 0 V kabul edilir. 9 V'luk pil, uçları arasındaki potansiyel farkın 9 V olduğunu söyler.
- Devre elemanları (ekrandan, 01:00:00)
  - Aktif elemanlar: bağımsız ve bağımlı güç kaynakları (gerilim ve akım).
  - Pasif elemanlar: direnç, kondansatör (kapasitör), bobin (indüktör).
  - Ölçü aletleri: ampermetre akımı, voltmetre gerilimi ölçer.
  - Diğerleri: toprak, kablo, anahtar (switch), koruyucu eleman (sigorta).
- Bağımsız ve bağımlı kaynaklar
  - Bağımsız kaynağın değeri sabittir (5 V, 3 A); hiçbir değişkene bağlı değildir. Güç kaynağı yalnız gerilim kaynağı değildir, akım kaynağı da güç kaynağıdır.
  - Bağımlı kaynak eşkenar dörtgen (baklava) sembolüyle çizilir, değeri devredeki başka bir gerilime ya da akıma bağlıdır.
  - Dört tür: VCVS (gerilim kontrollü gerilim kaynağı), CCVS (akım kontrollü gerilim kaynağı), VCCS (gerilim kontrollü akım kaynağı), CCCS (akım kontrollü akım kaynağı) (ekrandan, 01:05:00).
  - Örnek: değeri $5V_1$ olan bir VCVS, $V_1 = 5$ V iken 25 V verir. Kontrol eden büyüklük bir direncin üzerindeki gerilim de olabilir ($5V_{R1}$).
- Pasif elemanlar ve sembolleri (ekrandan, 01:15:00)
  - Direnç: zikzak sembol, birimi ohm ($\Omega$). Değeri üzerindeki renk bantlarından okunur: ilk iki bant basamak, üçüncü bant 10'un kuvveti olan çarpandır.
  - Bobin: sık sarılmış bakır tel, birimi henry (H). Akımı manyetik alan yoluyla üzerinde biriktirir.
  - Kondansatör: iki paralel çizgi, birimi farad (F). Kutuplu türlerde uzun bacak artı uçtur. Gerilimi biriktirir.
  - Direnç enerjiyi anında tüketir; bobin ve kondansatör enerjiyi tutup yavaşça bırakır.
- Kapalı devre, anahtar ve sigorta
  - Akım ancak kapalı çevrimde (closed loop) akar. Açılan anahtar çevrimi keser ve akım durur.
  - Anahtarlar mekanik (buton, lamba anahtarı) ya da elektronik (kızılötesi, sensörle) olabilir.
  - Sigorta ani akım değişimlerinde devre elemanlarını korur; ani kesen ve zamana yayarak kesen türleri vardır.
- Kablo standardı (AWG)
  - American Wire Gauge numarası kablonun kesit alanına göre verilir. Numara küçüldükçe kesit büyür, direnç azalır ve kablo daha fazla akım taşır (ekrandan, 01:25:00).
  - Ev tesisatında 12-14 AWG ($3.31$ ve $2.08\ \text{mm}^2$), telefon kablolarında 22-24 AWG ($0.33$ ve $0.20\ \text{mm}^2$) kullanılır.
- Ders boyunca kabul edilecek kurallar
  - Kablo boyunca gerilim düşümü yoktur; kablonun direnci teorik olarak 0 $\Omega$'dur.
  - Gerilim kaynağının uçlarında her zaman üzerinde yazan gerilim, akım kaynağından her zaman üzerinde yazan akım vardır.
  - Toprak her zaman 0 V'tur.
  - Akım yüksek gerilimden düşük gerilime akar; dirençten Ohm yasasına göre, gerilim kaynağından devredeki diğer elemanlara bağlı miktarda, akım kaynağından kendi değeri kadar geçer (ekrandan, 01:45:00).
- Yük, akım, gerilim, güç ve enerji
  - Yük $Q$ ile gösterilir, birimi coulomb (C).
  - Akım yükün zamana göre türevidir: $i = \dfrac{dq}{dt}$. İki noktadaki yük eşitse akım sıfırdır.
  - DC akım zamanla değişmez (pil); AC akım zamanla değişir (şebeke, priz) (ekrandan, 01:50:00). AC'nin en büyük üstünlüğü uzak mesafeye kolay taşınmasıdır.
  - Gerilim, birim yük başına enerji değişimidir: $v = \dfrac{dw}{dq}$.
  - Güç, enerjinin zamana göre değişimidir: $p = \dfrac{dw}{dt} = \dfrac{dw}{dq}\cdot\dfrac{dq}{dt} = vi$, birimi watt (W) (ekrandan, 01:55:00).
  - Enerji gücün zaman üzerinden integralidir: $w = \int_{t_1}^{t_2} p\,dt$.
- Pasif işaret kuralı
  - Akım bir elemanın artı ucundan giriyorsa eleman güç tüketir, gücü artı işaretlidir.
  - Akım artı uçtan çıkıyorsa eleman güç üretir, gücü eksi işaretlidir (ekrandan, 02:00:00 ve 02:25:00).
  - Kapalı bir devrede bütün güçlerin toplamı sıfırdır (enerjinin korunumu).
- Ohm yasası
  - $V = IR$; yalnız direnç için geçerlidir (ekrandan, 02:05:00). İleride AC devrelerde $R$ yerine empedans $Z$ gelecektir.
  - Gerilim sabitken direnç artarsa akım azalır; direnç sabitken gerilim artarsa akım artar.
- Negatif gerilim ve akım
  - Ters bağlanmış 2 V'luk kaynak $-2$ V demektir; 1 A ile ters yönde $-1$ A aynı şeydir (ekrandan, 02:15:00).
  - Voltmetre ölçülen elemana paralel, ampermetre devreye seri bağlanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Birimler
  - Sonucu birimsiz yazmak ya da mili ile mikroyu karıştırmak bütün soruyu götürür: $5.2$ mA ile $5.2\ \mu$A arasında bin kat fark vardır. Mikro sembolü ($\mu$) ile mili sembolü (m) karıştırılmamalıdır.
- Akımın yönü
  - Devre teorisi zor bir ders olarak görülür, ama hataların çoğu akımın yönünü ters almak gibi küçük noktalardan gelir.
- Güç işareti
  - "Üreten artıdır" yanılgısı çok yaygındır. Üretilen güç eksi, tüketilen güç artı işaretlidir.
- Kaynaklar da güç tüketebilir
  - Bağımsız ya da bağımlı gerilim ve akım kaynakları ters bağlandığında, akım artı uçlarından giriyorsa güç tüketir. Kondansatör ve bobin bir süre güç üretebilir.
- Ohm yasası temeldir
  - İleride görülecek Kirchhoff yasaları, Thevenin, Norton ve süperpozisyon teoremlerinin hepsinin temelinde $V = IR$ vardır.

## Kısa Tekrar Notları

- m = $10^{-3}$, $\mu$ = $10^{-6}$, n = $10^{-9}$, p = $10^{-12}$, k = $10^{3}$, M = $10^{6}$, G = $10^{9}$.
- Önce birimleri eşitle, sonra hesapla, sonra istenen birime çevir.
- Sonuçlar virgülden sonra iki basamağa yuvarlanır.
- Elektrik akımı elektron akımının tersi yöndedir.
- Akım için potansiyel fark ve kapalı devre gerekir.
- Toprak = 0 V referans; kablo boyunca gerilim düşümü yok.
- Bağımlı kaynak: baklava sembolü; VCVS, CCVS, VCCS, CCCS.
- Direnç ($\Omega$), bobin (H), kondansatör (F).
- AWG numarası küçüldükçe kablo kalınlaşır, direnci azalır.
- $i = dq/dt$, $v = dw/dq$, $p = vi$, $w = \int p\,dt$.
- Akım artı uçtan giriyor: tüketim, $+P$. Artı uçtan çıkıyor: üretim, $-P$.
- Kapalı devrede güçlerin toplamı sıfırdır.
- $V = IR$; 10 V ve 4 k$\Omega$ için $I = 2.5$ mA, $P = 25$ mW.
- Voltmetre paralel, ampermetre seri bağlanır.

## Detaylı Açıklamalar

- **Birim dönüşümleri ve gösterim.** Devre sorularında verilen değerler farklı öneklerle gelebilir (örneğin gerilim volt, direnç kiloohm). Akım amper olarak isteniyorsa bütün değerler önce temel birime çevrilir, sonuç gerekirse miliampere dönüştürülür. Önekli büyüklükler üslü sayı gibi işlenir: toplamada üsler eşitlenir, çarpmada katsayılar çarpılıp üsler toplanır. Bilimsel gösterimde mantis 1 ile 10 arasında, mühendislik gösteriminde 1 ile 1000 arasındadır ve üs 3'ün katıdır; bu yüzden mühendislik gösterimi doğrudan k, M, m, $\mu$ gibi öneklere karşılık gelir.
  - Ders sonrası not: Hoca 5 k$\Omega$ ile 3 M$\Omega$'un toplanmasını anlatırken üsleri karıştırıp "3 çarpı 10 üzeri 3 artı 5 çarpı 10 üzeri 6" dedi. Doğrusu $5\times10^{3} + 3\times10^{6} = 3.005\times10^{6}\ \Omega = 3.005$ M$\Omega$'dur.
- **Akım, gerilim ve su benzetmesi.** Elektronlar artı uca doğru hareket eder; elektrik akımı ise artı uçtan çıkıp devreyi dolaşarak eksi uca döner. Suyun yüksekten alçağa akması gibi akım da yüksek potansiyelden düşük potansiyele akar. Barajda yükseklikteki potansiyel enerji kinetik enerjiye çevrilir; devrede de kaynak potansiyel fark oluşturur, akım bu farktan doğar. Leğen benzetmesinde deliğin büyüklüğü direncin tersine karşılık gelir: direnç büyüdükçe delik daralır, akım azalır. Hoca direnci "dikenli yol" benzetmesiyle de anlattı: yolda diken arttıkça geçmek zorlaşır.
- **Bağımlı kaynak örneği.** Devrede bir $R_1$ direncinin gerilimi $V_{R1}$ ise, değeri $5V_{R1}$ yazılan baklava sembollü gerilim kaynağı her an bu gerilimin beş katını verir. Kontrol büyüklüğü gerilimse "gerilim kontrollü", akımsa "akım kontrollü" denir; kaynağın kendisinin gerilim mi akım mı verdiği adın ikinci yarısını belirler.
- **Renk kodu.** Direncin ilk iki bandı basamakları, üçüncü bandı çarpanı ($10^{n}$) verir. Hoca tahtaya "1 0 × 10" yazdı (ekrandan, 01:15:00); bu 100 $\Omega$ eder.
  - Ders sonrası not: Hoca sonucu "110'luk bir direnç" diye söyledi; tahtadaki $10 \times 10^{1}$ hesabı 100 $\Omega$ verir. Hoca renk sırasını da karışık saydı ve mavinin çarpanından emin olmadığını söyledi. Standart sıra büyük olasılıkla siyah 0, kahverengi 1, kırmızı 2, turuncu 3, sarı 4, yeşil 5, mavi 6, mor 7, gri 8, beyaz 9'dur.
- **AWG tablosu.** Slayttaki tabloya göre (ekrandan, 01:25:00) 0000 (4/0) AWG kablonun çapı 11.7 mm, kesiti 107 mm$^2$'dir; 12 AWG 3.31 mm$^2$, 14 AWG 2.08 mm$^2$, 22 AWG 0.33 mm$^2$, 24 AWG 0.20 mm$^2$'dir. Kesit büyüdükçe direnç azalır; direnç malzemeye, kesit alanına ve uzunluğa bağlıdır (ayrıntısı sonraki derste).
  - Ders sonrası not: Hoca en kalın kablo için "10 santimlik" dedi; tablodaki çap 11.7 mm, yani yaklaşık 1.2 cm'dir.
- **Güç ve işaret kuralı.** $p = vi$ bağıntısı $p = dw/dt$ ifadesinin $dw/dq$ ile $dq/dt$ çarpımına ayrılmasıyla elde edilir. 3 A'lik akım kaynağının beslediği ve üzerinde 1 V düşen elemanlı örnekte (ekrandan, 01:10:00) akım kaynağın artı ucundan çıkar ve elemanın artı ucundan girer: kaynak $-3$ W üretir, eleman $+3$ W tüketir, toplam sıfırdır. Derste gösterilen bir başka devrede $-2$ W üreten, $+3$ W ve $+5$ W tüketen elemanlar varken dördüncü elemanın $-6$ W üretmesi gerektiği bulundu. <!-- BELİRSİZ: Bu örneğin karesi yok; +5 W değeri altyazıdaki "3-5 daha 8" ifadesinden çıkarıldı. -->
- **Ohm yasası örnekleri.** 2 $\Omega$'luk dirençten 2 A geçiyorsa direnç üzerinde $2\cdot 2 = 4$ V düşer; bir ucu $x$ volt ise diğer ucu $x+4$ volttur (ekrandan, 02:05:00). 1 V kaynak ve 1 $\Omega$ dirençli devrede direncin uçları $x+1$ ve $x$ volttur, direnç $+1$ W tüketir (ekrandan, 02:10:00). Akkor flamanlı ampul de bir dirençtir; tükettiği enerji ısıya, ısı ışığa dönüşür. Seri bağlı ampuller enerjiyi paylaştığı için daha sönük yanar.
- **10 V, 4 k$\Omega$ örneği.** $10 = 4\times10^{3}\cdot I$ ise $I = 10/4000 = 2.5\times10^{-3}$ A $= 2.5$ mA (ekrandan, 02:20:00). Kaynağın gücü $P = 10 \cdot 2.5\times10^{-3} = 25$ mW'tır; kaynak $-25$ mW üretir, direnç $+25$ mW tüketir. Akım direncin artı ucundan girdiği için direncin üst ucu artı işaretlenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
