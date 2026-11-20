# Ders 9 Çalışma Özeti

## Genel Konular

- 8255'in 16 bitlik veri yoluna bağlanmasının tekrarı
  - 8086 tek bir okuma/yazma çevriminde çift adresten 8 bit, tek adresten 8 bit ve çift adresten 16 bit aktarım yapar. Bu yüzden 1M × 8 bellek işlemciye 512K × 16, 64K × 8 G/Ç uzayı da 32K × 16 olarak görünmek ister.
  - Ardışık çift adreslerde A0 = 0 aranır, 8255'in A1, A0 uçlarını işlemcinin A2, A1 uçları sürer, veri D0-D7 üzerinden gelir. A0 = 0 aramak $\overline{BHE}$ = 1 aramakla eşdeğerdir.
  - Ardışık tek adreslerde A0 = 1 aranır, veri D8-D15 üzerinden gelir. A0 = 1 aramak $\overline{BHE}$ = 0 aramakla eşdeğerdir.
  - Ardışık adreslere yerleştirme ek tampon ve mandal mantığı ister; bu durumda dört kombinasyonu A1 ve A0 oluşturur. Bu yerleşim dersin kapsamı dışında tutuldu.
  - Adres sabit 8 bitlik bir sayıysa (`IN AL, port8` / `OUT port8, AL`) adres çözümleme A7-A0 ile yapılır. Sekiz adres ucu ve M/$\overline{IO}$ dokuz uç eder; ikisi 8255'e doğrudan gider, yedisi altı girişli 3'e 8 kod çözücüye bağlanacağı için iki uç birleştirilir (ekrandan, 00:05:00).
- $\overline{BHE}$ ucunun anlamı (derste sorulan soru üzerine)
  - x16 düzende çift adresli blok A0 = 0 ile, tek adresli blok $\overline{BHE}$ = 0 ile seçilir. Bu yüzden A0'a "bus low enable" da denir.
  - Çift adresten 16 bitlik işlemde A0 = 0 ve $\overline{BHE}$ = 0 birlikte oluşur; iki bloğun aynı satırı etkinleşir ve 16 bit tek seferde okunur.
  - 80386 ve 80486'da 32 bitlik veri yolu vardır; bellek dört blok yan yana (x32) görülür ve her blok ayrı bir byte enable ucuyla seçilir (adresin 4'e bölümünden kalan 0, 1, 2, 3).
- Zorunlu olmayan ödevlerin değerlendirilmesi
  - Dört 7 segment göstergede farklı değer gösterme: tarama frekansı yetersizse bütün haneler üst üste binmiş (8 gibi) görünür; hane geçişi düzgün yapılmazsa iki hane kısa süre aynı anda yanar ve görüntü bozulur.
  - 4x4 tuş takımı: derste aynı anda iki tuşa basılmadığı varsayılır. Aynı anda basılma olasılığı varsa satır/sütun hatları diyotlarla korunmalıdır; aksi hâlde biri 0, biri 1 sürülen iki sütun kısa devre olabilir. Basılan tuş değeri yazılımda saklanmalı (mandallanmalı), yeni tuşa basılana kadar korunmalıdır.
- 8255'in modlarına genel bakış (ekrandan, 00:30:00)
  - Mod 0 (basic/simple I/O): port A ve port B 8 bit, port C üst ve alt yarıları 4 bit olarak ayrı ayrı giriş ya da çıkış olur. Veri gönderilir ya da okunur, ulaşıp ulaşmadığı ya da geçerli olup olmadığı denetlenmez. LED, düğme, 7 segment ve tuş takımı gibi işlerde kullanılır.
  - Mod 1 (strobed I/O): grup A (port A + port C üst) ve grup B (port B + port C alt) için tanımlanır. El sıkışmalıdır ve veri yönü tektir, baştan belirlenir. Port A/B veriyi taşır, port C uçları kontrol ve el sıkışma işaretleri için kullanılır.
  - Mod 2 (bidirectional): yalnız grup A için vardır; port A ve port C birlikte kullanılır, yönü yürütülen komut (`IN`/`OUT`) belirler. Port B yalnız mod 0 ya da mod 1'de kullanılabilir.
  - Bir grup mod 1'de iken diğer grubun portları mod 0'da kullanılabilir.
- Kontrol yazmacının tekrarı (ekrandan, 00:35:00)
  - Kontrol yazmacına 8255'in $\overline{CS}$ = 0, A1 = 1, A0 = 1 olduğu adreste yazma işlemiyle erişilir. D7 = 1 mod ayar sözcüğü, D7 = 0 BSR sözcüğüdür.
  - D6-D5 grup A modu (00 mod 0, 01 mod 1, 1X mod 2), D4 port A yönü, D3 port C üst yönü, D2 grup B modu (0 ya da 1), D1 port B yönü, D0 port C alt yönü; 1 giriş, 0 çıkıştır.
  - Çıkış olarak ayarlanmış uçlardan `IN` ile okunan değerler anlamsızdır, maskelenerek atılmalıdır.
  - BSR sözcüğü: D7 = 0, D6-D4 önemsiz, D3-D1 port C uç numarası, D0 o uca yazılacak değer.
- BSR modu örneği: 80H'den itibaren ardışık çift adresler (ekrandan, 00:40:00, 00:45:00, 00:50:00)
  - Adresler: PA = 80H, PB = 82H, PC = 84H, CW = 86H.
  - a) PC2 = 1: sözcük 0000 0101B = 05H. `OUT` komutunun veri işleneni yalnız AL ya da AX olabildiği için tek komutla yapılamaz: `MOV AL, 05H` ve `OUT 86H, AL`.
  - b) PC6'da %66 görev çevrimli kare dalga: görev çevrimi = 1'de kalma süresi / periyot. 1'de 2 birim, 0'da 1 birim kalınırsa $2x / 3x \approx \%66$ olur.
  - PC6 = 1 sözcüğü 0000 1101B = 0DH, PC6 = 0 sözcüğü 0000 1100B = 0CH. Döngüde 0DH yazılıp iki kez, 0CH yazılıp bir kez bir birimlik `DELAY` çağrılır, `JMP L1` ile başa dönülür.
  - İşletim sistemi olmayan mikroişlemci sistemlerinde program sonsuz döngüde çalışır. Resetten sonra CS = FFFFH, IP = 0000H yüklenir; bu fiziksel adreste kullanıcı programına atlayan bir komut bulunur.
- Mod 1 uçları ve kontrol sözcükleri (ekrandan, 01:00:00)
  - Grup A mod 1 giriş: sözcük 1 0 1 1 X (D3 boşta kalan PC6, PC7'nin yönü); $\overline{STB_A}$ = PC4, IBF$_A$ = PC5, INTR$_A$ = PC3, INTE$_A$ PC4 üzerinden kurulur.
  - Grup A mod 1 çıkış: sözcük 1 0 1 0 X (D3 boşta kalan PC4, PC5'in yönü); $\overline{ACK_A}$ = PC6, $\overline{OBF_A}$ = PC7, INTR$_A$ = PC3, INTE$_A$ PC6 üzerinden kurulur.
  - Grup B mod 1 giriş: D7 = 1, D2 = 1, D1 = 1; $\overline{STB_B}$ = PC2, IBF$_B$ = PC1, INTR$_B$ = PC0, INTE$_B$ PC2 üzerinden kurulur.
  - Grup B mod 1 çıkış: D7 = 1, D2 = 1, D1 = 0; $\overline{ACK_B}$ = PC2, $\overline{OBF_B}$ = PC1, INTR$_B$ = PC0, INTE$_B$ PC2 üzerinden kurulur.
  - INTE bitleri iç bitlerdir, fiziksel uçları yoktur. Şekilde aynı satırdaki port C ucuna BSR moduyla 1 ya da 0 yazılarak açılıp kapatılır.
- Mod 1 giriş akışı (klavye örneği, ekrandan 01:05:00 ve 01:20:00)
  - Çevre birimi veriyi port uçlarına koyar, sonra $\overline{STB}$'yi 0 yapar. 8255 veriyi iç yazmacına kopyalar ve IBF'yi 1 yapar; bu, çevre birimi için alındı (acknowledge) işaretidir.
  - $\overline{STB}$ = 1, IBF = 1 ve INTE = 1 olunca INTR 1 olur. İşlemci portu okuduğunda ($\overline{RD}$) INTR 0'a, okuma bitince IBF 0'a düşer.
  - $\overline{STB}$'yi çevre birimi, IBF ve INTR'yi 8255, $\overline{RD}$'yi 8086 sürer.
- Mod 1 çıkış akışı (yazıcı örneği, ekrandan 01:15:00 ve 01:25:00)
  - İşlemci port yazmacına yazınca $\overline{OBF}$ 0 olur; bu, yazıcı için strobe işaretidir. Yazıcı veriyi alıp işleyince $\overline{ACK}$'i 0 yapar, $\overline{OBF}$ yeniden 1 olur.
  - $\overline{ACK}$ = 1, $\overline{OBF}$ = 1 ve INTE = 1 iken INTR 1 olur; yeni yazma işlemi ($\overline{WR}$'nin düşen kenarı) INTR'yi sıfırlar.
- Durum (status) sözcüğü
  - Mod 1'de port C adresinden yapılan okuma durum sözcüğünü verir. Girişte IBF ve INTR bitleri, çıkışta OBF ve INTR bitleri buradan yoklanabilir. INTR bitlerine bakmak yalnız ilgili INTE açıksa anlamlıdır.
  - Kesmeler henüz işlenmediği için INTR değerleri de şimdilik durum sözcüğünden yoklamayla kullanılır.
- Tek 8255'te grup A çıkış ile grup B girişini birbirine bağlama (ekrandan, 01:35:00)
  - PA uçları PB uçlarına, $\overline{OBF_A}$ $\overline{STB_B}$'ye bağlanır. IBF$_B$ aktif 1, $\overline{ACK_A}$ aktif 0 olduğu için IBF$_B$ bir DEĞİL kapısından geçirilip $\overline{ACK_A}$'ya verilir.
- Proteus örneği: mod 1 ile tuş takımından 7 segment göstergeye (ekrandan, 01:40:00 - 01:55:00)
  - MM74C922 tuş tarama entegresi 16 tuşu tarar, basılan tuşun 4 bitlik kodunu D, C, B, A uçlarına verir. Tuşa basılınca aktif 1 DA (data available) oluşur; $\overline{OE}$ = 0 iken kod çıkışa verilir.
  - Grup A mod 1 giriş: DA bir DEĞİL kapısından $\overline{STB_A}$'ya (PC4), IBF$_A$ (PC5) bir DEĞİL kapısından $\overline{OE}$'ye gider.
  - Grup B mod 1 çıkış: 4511 ortak katot 7 segment sürücü; $\overline{OBF_B}$ mandal izni (LE) ucuna gider, 4511'de alındı çıkışı olmadığı için $\overline{OBF_B}$ iki DEĞİL kapısından geciktirilerek $\overline{ACK_B}$ yapılır. Bu yüzden el sıkışma tam denetlenmiş olmaz.
  - Adres çözümleme 74154 ile: A12-A9 seçim girişlerine, A15-A13 bir NOR + DEĞİL ile (yani VEYA) aktif düşük bir izin girişine, M/$\overline{IO}$ diğerine gider. $\overline{IO1}$ çıkışı için A9 = 1, diğerleri 0; 8255 A1, A0 uçlarına işlemcinin A2, A1 uçları bağlı. Adresler 200H, 202H, 204H, 206H'dir (CW = 206H). Adres 8 bite sığmadığı için DX kullanılır.
  - Kodda CW'ye sırayla 09H (PC4 = 1, INTE$_A$), 05H (PC2 = 1, INTE$_B$) ve 0BCH (1011 1100B: grup A mod 1 giriş, PC üst giriş, grup B mod 1 çıkış, PC alt çıkış) yazılır.
  - Döngüde port C okunup `AND AL, 08H` ile INTR$_A$ beklenir, port A okunup BL'ye saklanır; sonra `AND AL, 01H` ile INTR$_B$ beklenir ve değer port B'ye yazılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- `OUT` komutu doğrudan sayı gönderemez
  - Veri önce AL'ye (ya da AX'e) alınmalıdır. Kodun yanına `; BSR mod ile C2 set için CW değeri` gibi açıklama yazılması beklenir.
- Mod 1'de hangi ucu kimin sürdüğünü bilmek
  - Hoca konunun anlaşılması için bunun "çok önemli" olduğunu söyledi: $\overline{STB}$'yi çevre birimi, IBF/INTR/$\overline{OBF}$'yi 8255, $\overline{RD}$/$\overline{WR}$'yi 8086, $\overline{ACK}$'i çevre birimi sürer.
- El sıkışmada sıra ve denetim
  - Alındı işareti gelmeden yeni veri gönderilirse önceki veri ezilebilir, veri kaybolur.
- El sıkışma olsa da işlemci tarafında yoklama vardır
  - Kesme kullanılmazsa 8086, IBF ya da OBF bitini sürekli yoklamak zorundadır. INTE açılıp INTR işlemcinin kesme girişine bağlanırsa yoklama gerekmez.
- Aynı anda birden çok tuşa basılabiliyorsa tuş takımı diyotlarla korunmalıdır
  - Bu, 8255'in de korunması anlamına gelir.

## Kısa Tekrar Notları

- Çift adres: A0 = 0 ≡ $\overline{BHE}$ = 1, veri D0-D7. Tek adres: A0 = 1 ≡ $\overline{BHE}$ = 0, veri D8-D15.
- Mod 0: denetimsiz basit G/Ç. Mod 1: tek yönlü el sıkışma, grup A ve B. Mod 2: çift yönlü el sıkışma, yalnız grup A.
- CW: D7 = 1 mod ayarı, D7 = 0 BSR. BSR: D3-D1 uç no, D0 değer.
- 80H tabanlı 8255: PC2 set 05H; PC6 set 0DH, PC6 reset 0CH; CW adresi 86H.
- Görev çevrimi = $d/T$; 2 birim 1, 1 birim 0 → %66.
- Mod 1 giriş: $\overline{STB}$ ↓ → veri alınır → IBF = 1 → ($\overline{STB}$ = 1, IBF = 1, INTE = 1) → INTR = 1 → $\overline{RD}$ → INTR = 0, IBF = 0.
- Mod 1 çıkış: $\overline{WR}$ → $\overline{OBF}$ = 0 → çevre birimi $\overline{ACK}$ = 0 → $\overline{OBF}$ = 1 → ($\overline{ACK}$ = 1, $\overline{OBF}$ = 1, INTE = 1) → INTR = 1 → yeni $\overline{WR}$ → INTR = 0.
- INTE$_A$: girişte PC4, çıkışta PC6. INTE$_B$: her iki yönde PC2. INTR$_A$ = PC3, INTR$_B$ = PC0.
- Mod 1'de port C adresinden okuma durum sözcüğünü verir.
- Proteus örneği: 8255 200H-206H, CW 206H; 09H, 05H, 0BCH yazılır.

## Detaylı Açıklamalar

- BSR modunun kullanım alanı
  - BSR modu port C'nin tek bir ucunu çıkış gibi 1 ya da 0 yapar. Tek bitlik çıkış üretmenin yanında mod 1 ve mod 2'de INTE gibi ayarları açıp kapatmak için de kullanılır. Hoca laboratuvarda BSR'nin çıkış örneği olmadığını, ancak mod 1'de kesme izin ayarları için kullanılacağını söyledi.
- %66 görev çevrimli kare dalga programı (ekrandan, 00:50:00; gecikme çağrıları altyazıdan)
  - Program aşağıdaki gibidir. `DELAY` önceden tanımlanmış, bir birim bekleyen boş bir döngü ya da NOP'lardan oluşan bir alt programdır.

    ```asm
    L1: MOV AL, 0DH      ; PC6 = 1 icin BSR sozcugu
        OUT 86H, AL
        CALL DELAY       ; 1 birim
        CALL DELAY       ; 1 birim (toplam 2 birim 1'de)
        MOV AL, 0CH      ; PC6 = 0 icin BSR sozcugu
        OUT 86H, AL
        CALL DELAY       ; 1 birim 0'da
        JMP L1
    ```

  - Uç 1'e çıkar, iki birim bekler, 0'a düşer, bir birim bekler ve döngü tekrar eder. Bu sonsuz döngü işletim sistemsiz sistemlerde olağandır; tuş takımını tarayıp göstergede değer yakma gibi işler de böyle sürekli tekrarlanır.
- Mod 1 giriş zamanlaması (ekrandan, 01:20:00)
  - Çevre birimi önce veriyi hatta koyar, sonra $\overline{STB}$'yi düşürür. Düşen kenar verinin içeri alınmasını başlatır ve IBF yükselir. Çevre birimi $\overline{STB}$'yi kaldırır, kısa süre sonra veriyi de hattan çeker.
  - $\overline{STB}$ = 1, IBF = 1 ve INTE = 1 koşulları birlikte sağlanınca INTR yükselir. İşlemci yaptığı işi bitirip kesme alt programına geçer ve portu okur; $\overline{RD}$ düşünce INTR düşer, okuma bitince IBF düşer ve yeni veri alınabilir.
- Mod 1 çıkış zamanlaması
  - Slaytta INTR için şu tanım verildi: $\overline{ACK}$ = 1, $\overline{OBF}$ = 1 ve INTE = 1 iken INTR 1 olur; $\overline{WR}$'nin düşen kenarıyla sıfırlanır (ekrandan, 01:25:00).
  - Akış: işlemci yazar, $\overline{OBF}$ düşer (yazıcı için strobe); yazıcı veriyi işler ve $\overline{ACK}$'i düşürür; $\overline{OBF}$ yükselir; yazıcı $\overline{ACK}$'i kaldırınca INTR yükselir ve işlemci sonraki karakteri yazabilir.
- Proteus örneğinin kodu (ekrandan, 01:55:00)

    ```asm
    START:  MOV DX, 206H     ; kontrol yazmaci
            MOV AL, 09H      ; BSR: PC4 = 1 -> INTE_A = 1
            OUT DX, AL
            MOV AL, 05H      ; BSR: PC2 = 1 -> INTE_B = 1
            OUT DX, AL
            MOV AL, 0BCH     ; A: mod 1 giris, B: mod 1 cikis
            OUT DX, AL
            MOV DX, 202H
    ENDLESS:
    tekrar1: MOV DX, 204H    ; port C (durum sozcugu)
            IN AL, DX
            AND AL, 08H      ; INTR_A
            CMP AL, 00
            JE tekrar1
            MOV DX, 200H     ; port A
            IN AL, DX
            MOV BL, AL
    tekrar: MOV DX, 204H
            IN AL, DX
            AND AL, 01H      ; INTR_B
            CMP AL, 00
            JE tekrar
            MOV DX, 202H     ; port B
            MOV AL, BL
            OUT DX, AL
            JMP ENDLESS
    ```

  - Tuş tarayıcının verdiği ikilik kod doğrudan 4511'e gönderildiği için basılan tuşun 7 segment karşılığı görünür. 4511 onlu (BCD) sürücü olduğundan 9'dan büyük kodlarda gösterge boş kalır.

> **Ders sonrası not:** Hoca grup B'de INTE$_B$'yi açmak için PC2'nin BSR modunda "reset" edilmesi gerektiğini söyledi (01:14:14). Doğrusu PC2'ye 1 yazılmasıdır (set); derste gösterilen kodda da 05H (PC2 = 1) kullanılır.

> **Ders sonrası not:** Hoca bir yerde mod 1'de grup A verisinin "port B'de" taşındığını söyledi (00:54:18). Doğrusu grup A verisi port A'da, grup B verisi port B'de taşınır.

<!-- BELİRSİZ: 01:33:27'de bir öğrencinin sorusuna hoca "her birinden birer bit boşta kalıyor, 3 bit demek mantıklı olabilir" diye cevap verdi; soru altyazıda yok, neyin 3 bit olduğu net değil. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
