# Ders 23 Çalışma Özeti

## Genel Konular

- DAC ve ADC'nin sistemdeki yeri (tekrar) (ekrandan, 00:05:00)
  - Fiziki dünya analog, mikroişlemci sistemi sayısaldır. Dış dünyada ölçüm ve kontrol yapmak için ADC (analog-dijital dönüştürücü) ve DAC (dijital-analog dönüştürücü) gerekir.
  - Ölçülen fiziki büyüklüğü elektriksel işarete (ya da elektriksel işareti başka bir fiziki büyüklüğe) çeviren eleman dönüştürücüdür (transducer). Sıcaklığa göre fan hızı ayarlama örneğinde giriş dönüştürücüsü sıcaklıkla direnci değişen bir eleman, çıkış dönüştürücüsü motorun kendisi olabilir.
  - Akış: Fiziki dünya (sıcaklık, analog) → Transducer → elektriksel analog → ADC → elektriksel dijital → µP → işlenmiş veri → DAC → elektriksel analog → Transducer → Fiziki dünya (fan hızı).
  - Analog işaret her $t$ anında tanımlıdır ve değeri sürekli bir kümeden gelir. Sayısal işaret hem zamanda ayrıktır (örnekleme) hem de genlikte kuantalanmıştır; 8 bitlik bir ADC çıktısı 00H-FFH arasında 256 farklı değer alır.
- DAC0830 (tekrar ve tamamlama)
  - Dışarı çıkan uçlar: D0-D7 veri uçları, $\overline{CS}$, $\overline{WR}$ ve analog çıkış. Diğer bağlantılar hazır kabul edilir (bunlardan öğrenci sorumlu değildir).
  - Adres ucu olmadığı için G/Ç uzayında $2^0 = 1$ bayt yer kaplar. Yalnız çıkış yönlü çalışır; okuma işleminde seçilmemesi $\overline{WR}$ ile sağlanır.
  - 0-5 V aralığında doğrusal çıkış: 00H → 0 V, 7FH → yaklaşık 2,5 V, FFH → 5 V. Adım büyüklüğü $5/255 \approx 0{,}0196$ V.
  - Zamanlama diyagramı (ekrandan, 00:10:00): `OUT DX, AL` ile adres çözme devresi $\overline{CS}$ üretir, işlemci $\overline{WR}$ üretir ve veri uçlarına geçerli veriyi koyar. Çıkış belirli bir oturma süresi ($t_S$, "settled to ±½ LSB") sonunda kararlı hale gelir. Bu yüzden her yazmadan sonra bir süre beklemek gerekir.
  - 1000H adresli DAC örneği: adres 8 bitten büyük olduğu için DX üzerinden verilir; AL 0'dan başlatılıp sürekli artırılarak DAC'ye yazılır. AL FFH'tan sonra 00H'a döner; çıkış 0-5 V arası yükselen ve dik düşen bir testere dişi dalgadır.
- Paralel (flash) ADC (ekrandan, 00:15:00)
  - Bir direnç dizisi (gerilim bölücü), bir karşılaştırıcı dizisi ve 8 girişli-3 çıkışlı bir öncelik kodlayıcıdan (8-line to 3-line priority encoder) oluşur.
  - Karşılaştırıcı geri beslemesiz bir opamp gibidir: $A > B$ ise çıkış lojik 1, $A \le B$ ise lojik 0 (derste sonradan eşitlik 1 tarafına alındı: $A \ge B$ → 1).
  - $V_{ref} = 5$ V ve 7 eşit $R$ ile düğüm gerilimleri $5 \cdot k/7$ V olur: 5; 4,29; 3,57; 2,86; 2,14; 1,43; 0,71 V.
  - Öncelik kodlayıcı en yüksek anlamlı girişten başlayarak ilk 1 gördüğü girişin numarasını ikili olarak verir. 4 V giriş → 101, 0 V → 000, 5 V → 111 (3 bitlik çözünürlük).
- Rampa (ramp) dönüştürücü
  - 8 bitlik bir sayıcı (counter) saat ile 00H'tan FFH'a sayar; çıkışı bir DAC'ye verilir. DAC çıkışı adım adım artar.
  - Karşılaştırıcı, DAC çıkışı ölçülen gerilimi geçtiği anı yakalar: o anki sayıcı değeri bir yazmaca (shift register) kopyalanır, sayıcı sıfırlanır. Yazmaçtaki 8 bit ADC sonucudur.
  - Dönüşüm süresi sabit değildir; ölçülen gerilim büyüdükçe uzar. Bu yüzden ADC dönüşümün bittiğini bir uçla bildirmelidir.
- ADC0804 entegresi (ekrandan, 00:30:00 ve 00:35:00)
  - Dışarı çıkan uçlar: DB0-DB7 (AD0-AD7 veri yoluna), $\overline{CS}$ (şemada $\overline{IO1}$), $\overline{RD}$, $\overline{WR}$, analog giriş VIN+ ve $\overline{INTR}$. VIN+ girişine 1k'lık bir potansiyometre (RV1) bağlıdır.
  - Adres ucu yoktur, iç yazmacından durum okunamaz. Dönüşüm herhangi bir değerle yapılan "boş yazma" (`OUT`) ile başlar; dönüşüm bitince $\overline{INTR}$ ucu 0'a düşer.
  - $\overline{INTR}$ ucu 74125 üç durumlu tampon (U4:A) üzerinden veri yolunun bir bitine (örnekte AD7) bağlanır. Tamponun kontrol ucu ikinci bir chip select ($\overline{IO2}$) olur; bu uç 1 bitlik "sanal" bir G/Ç cihazı gibi ayrı bir adrese yerleştirilir.
  - Akış: ADC adresine boş yazma → sanal cihazın adresinden sürekli oku, ilgili biti maskele (yoklama, polling) → bit 0 ise ADC adresinden sonucu oku. Okuma $\overline{INTR}$'yi yeniden 1 yapar ve döngü baştan başlar.
  - Cihazlar çift adrese yerleştirildiği için tampon çıkışı D0-D7 arasındaki herhangi bir bite bağlanabilir; test maskesi bağlanan bite göre seçilir (AD7 → 80H, AD0 → 01H).
  - Kesme konusu öğrenildiğinde sanal cihaza gerek kalmaz; $\overline{INTR}$ doğrudan kesme isteği olarak kullanılır.
- Proteus uygulamaları
  - DAC örneği: testere dişi dalganın periyodu gecikme (DELAY) alt programındaki bekleme süresiyle belirlenir. Kod değiştirilerek üçgen dalga ve 0-3 V aralıklı, yaklaşık 5 Hz'lik üçgen dalga üretildi.
  - ADC örneği: potansiyometre ortadayken lojik analizörde $\overline{INTR}$ 0'a düştüğü anda veri yolunda 80H görüldü (yaklaşık 2,5 V).
- Kesmelere giriş (ekrandan, 01:15:00 - 01:25:00)
  - Yoklama ile kesme farkı (kova benzetmesi). Kesme kaynakları: yazılımsal (INT n, INTO, INT 3, sıfıra bölme gibi komut sonucu oluşan kesmeler) ve donanımsal (INTR, NMI).
  - Kesme uçları: INTR (maskelenebilir), NMI (maskelenemez), $\overline{INTA}$ (kesme onayı). Bayraklar: IF ve TF. Dönüş komutu: IRET.
  - Kesme vektör tablosu: belleğin 00000H-003FFH aralığı, 256 göz × 4 bayt = 1024 bayt; her gözde ilgili kesme alt programının offset ve segment değeri bulunur.

## Hocanın Özellikle Vurguladığı Kısımlar

- DAC'ye her değer yazıldıktan sonra beklemek gerekir
  - Analog çıkış ancak oturma süresinden sonra kararlıdır; gecikme olmadan arka arkaya yazmak verimli çıkış üretmez.
- ADC dönüşümünün bittiğini bir fiziki uç bildirir ve bu uç doğru okunmalıdır
  - Hoca bu noktayı "çok önemli" diye vurguladı. ADC0804'ün yazmacından durum okunamadığı için $\overline{INTR}$ ucu üç durumlu tamponla 1 bitlik ayrı bir G/Ç cihazına dönüştürülür ve yoklanır.
- Maske, tamponun bağlandığı veri bitine göre seçilir
  - AD7'ye bağlıysa `TEST AL, 80H`, AD0'a bağlıysa 01H ile test edilir. Çift adres kullanıldığı için D0-D7'den herhangi biri seçilebilir.
- Testere dişinin periyodunu gecikme alt programı belirler
  - Gecikme bir basamağın genişliğidir; bir periyotta 255 kez çağrıldığı için periyodu doğrudan değiştirir.
- Kesme alt programı FAR tipindedir ve IRET ile döner
  - NEAR yordam RET, FAR yordam RETF ile döner; kesme alt programı NEAR yazılamaz ve IRET ile bitmek zorundadır.
- Kesme alt programına girince IF ve TF otomatik sıfırlanır
  - Varsayılan olarak iç içe kesme olmaz; iç içe kesme isteniyorsa alt programda IF'yi 1 yapmak kullanıcının sorumluluğundadır.

## Kısa Tekrar Notları

- DAC0830: 1 bayt G/Ç yeri, yalnız yazma, 00H → 0 V, FFH → 5 V, adım $5/255$ V.
- 1000H gibi 8 bitten büyük port adresi DX ile verilir.
- AL'yi sürekli artırmak testere dişi; önce 255 adım artırıp sonra 255 adım azaltmak üçgen dalga verir.
- Gecikme büyürse periyot büyür; derste gecikme sayacı 00FFH'tan 0FH'a indirilince periyot belirgin biçimde kısaldı.
- $V$ volt üst sınırı için sayaç sınırı $255 \cdot V/5$: 3 V için 153 = 99H.
- Paralel ADC: direnç dizisi + karşılaştırıcılar + öncelik kodlayıcı; 3 bitlik örnekte 4 V → 101.
- Rampa ADC: sayıcı + DAC + karşılaştırıcı + yazmaç; dönüşüm süresi girişe bağlıdır.
- ADC0804: boş `OUT` ile başlat, $\overline{INTR}$ = 0 olana kadar yokla, sonra `IN` ile sonucu oku.
- Kesme vektör tablosu 00000H-003FFH, 256 × 4 bayt, her gözde offset ve segment.
- INTR maskelenebilir (IF = 1 iken kabul edilir), NMI maskelenemez, $\overline{INTA}$ onay ucudur.
- TF = 1 ise her komuttan sonra kesme oluşur (adım adım hata ayıklama).

## Detaylı Açıklamalar

- **DAC0830 ile dalga üretimi.** Derste kullanılan Proteus kodu şöyledir (ekrandan, 00:45:00):

  ```asm
          mov DX, 1000H
          MOV AL, 00H
  ENDLESS:
          OUT DX, AL
          CALL DELAY
          INC AL
          JMP ENDLESS

  DELAY PROC NEAR
          PUSH CX
          MOV CX, 00FFH
  L1:     LOOP L1
          POP CX
          RET
  DELAY ENDP
  ```

  Her `OUT` DAC çıkışını bir basamak yükseltir; `DELAY` o basamağın süresidir. Çıkış aslında basamaklıdır, uzaktan bakınca doğrusal bir rampa gibi görünür. Ölçülen periyot önce yaklaşık 800 ms idi. Gecikme sayacı büyütülünce (5FF civarı) periyot yaklaşık 4,7 s'ye çıktı, 0FH'a indirilince yaklaşık 60 ms'ye düştü.
  <!-- BELİRSİZ: Hoca 00:48:23'te ilk periyodu "400 milisaniyeydi" diye andı; 00:43:18'de 800 ms ölçülmüştü. -->

- **Üçgen dalga.** Bir öğrencinin önerisi üzerine iki döngü kullanıldı (ekrandan, 00:55:00):

  ```asm
  ENDLESS:
          MOV CX, 255
  L1:     OUT DX, AL
          CALL DELAY
          INC AL
          LOOP L1

          MOV CX, 255
  L2:     OUT DX, AL
          CALL DELAY
          DEC AL
          LOOP L2
          JMP ENDLESS
  ```

  AL 0'dan 255'e 255 adımda çıkar, sonra 255 adımda 0'a iner. Periyot testere dişinin iki katı, yaklaşık 120 ms oldu ve dalga 0-5 V arasında değişti.

- **0-3 V, 5 Hz üçgen dalga.** 255 → 5 V olduğundan 3 V için $x = 255 \cdot 3/5 = 153 = 99\text{H}$. Döngü sınırı ilk denemede onluk 99 yazıldığı için tepe yaklaşık 2 V çıktı; 99H yazılınca tepe 3 V oldu. 5 Hz için periyot $1/5 = 200$ ms olmalıdır. Gecikme değeri deneme yanılmayla ayarlandı ve yaklaşık 200-210 ms elde edildi. Hassas hesap zordur, çünkü yığına itme/çekme, `CALL`/`RET`, `LOOP` ve atama komutları da süre harcar; aslında komutların çevrim sayıları ve işlemci saat frekansından tam hesap yapılabilir. Genlikte daha yüksek hassasiyet için daha çok bitli bir DAC gerekir.

- **Paralel ADC örneği.** $V_{in} = 4$ V için karşılaştırıcılar üstten: 5 V ile 0, 4,29 V ile 0, 3,57 V ile 1 ve aşağıdakilerin hepsi 1 verir. Öncelik kodlayıcının üstten girişleri 7, 6, 5, ... diye numaralandığında ilk 1 giriş 5'tedir; çıkış $101_2 = 5$. 0 V için bütün karşılaştırıcılar 0 verir ve çıkış 000 olur. 5 V'un 111 vermesi için eşitlik durumu karşılaştırıcının 1 tarafına alındı.

- **ADC0804 örnek kodu** (ekrandan, 00:40:00). ADC 0200H'ta, $\overline{INTR}$ için sanal cihaz 0400H'tadır:

  ```asm
  TEKRAR:
          MOV DX, 0200H
          MOV AL, 00H
          OUT DX, AL          ; boş yazma: dönüşümü başlat
          MOV DX, 0400H
  INTR_KONTROL:
          IN AL, DX           ; sanal cihazı oku
          TEST AL, 80H        ; INTR AD7'de
          JNZ INTR_KONTROL    ; 1 ise dönüşüm bitmedi
          MOV DX, 0200H
          IN AL, DX           ; ADC sonucunu oku
          CALL DELAY
          JMP TEKRAR
  ```

  Ders sonrası not: Hoca anlatımda ADC'yi 100H'a, sanal cihazı 200H'a yerleştirdi (ekrandan, 00:35:00); slayttaki kodda ise ADC 0200H, sanal cihaz 0400H'tadır. Proteus örneği de 200H/400H ile çalışır. Mantık aynıdır, yalnız adresler farklıdır.

- **Lojik analizörde gözlem.** Potansiyometre %50 iken $\overline{INTR}$ 0'a düştüğü anda veri yolunda 80H görüldü; $128 \cdot 5/255 \approx 2{,}51$ V, yani orta değer. Aradaki 00H değerleri boş yazmada AL'den gönderilen 0'dır. Tampon AD0'a taşınıp maske 01H yapılınca 400H okunurken 01H, boş yazmada 00H ve aradaki kısa sürede ADC sonucu (80H) görüldü.

- **Kesme vektör tablosu.** 8086'da 256 kesme tipi (0-255) vardır. Her tip için kesme alt programının adresi 2 bayt offset + 2 bayt segment olarak tabloda tutulur. Tablo $256 \times 4 = 1024$ bayttır ve 0H-3FFH (0-1023) adreslerini kaplar. Kesme oluşunca işlemci tablodan offset ve segmenti alıp alt programa dallanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
