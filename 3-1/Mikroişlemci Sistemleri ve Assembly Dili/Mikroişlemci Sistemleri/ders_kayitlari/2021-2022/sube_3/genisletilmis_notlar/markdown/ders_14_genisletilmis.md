# Ders 14 Genişletilmiş Notu: 8255 BSR, Mod 1 ve Mod 2

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki haftalardan köprü: neden 8255 üzerinde duruldu
- 2. 8255 modlarına genel bakış ve kontrol sözcüğü
- 3. Bit set/reset (BSR) modu
- 4. Mod 1: el sıkışmalı (handshake) G/Ç
- 5. Mod 1 zamanlama diyagramları
- 6. Mod 1 durum sözcüğü
- 7. Mod 1 uygulaması: tuş takımı ve 7 parçalı gösterge
- 8. Mod 2: çift yönlü veri yolu
- 9. Modların özeti
- 10. Ders sonu soruları: DT/R ucu ve donanımsal gecikme
- Örnek Sorular

## 1. Önceki haftalardan köprü: neden 8255 üzerinde duruldu

Önceki iki hafta 8255 ile mod 0 örnekleri yapılmıştı: LED ve düğme, 7 parçalı gösterge ve 3x4 tuş tarama (ekrandan, 00:05:00). Hoca 8255 üzerinde bu kadar durulmasının nedenini şöyle açıkladı: 8255, 8086'nın adres uzayında bir çevre biriminin nasıl çalıştığının ilk örneğidir. Mikroişlemci bir LED'i doğrudan bir ucuna bağlayıp sürmez; LED ya da düğme adres uzayında bir adrese yerleştirilir, işlemci o adrese yazar ya da o adresten okur.

Mod 0 bu fikri göstermenin en basit yoludur: herhangi bir "veri hazır mı, veri geldi mi" protokolü olmadan porta yazılır ya da porttan okunur. Bu derste kalan modlara geçilir: BSR, mod 1 ve mod 2 (ekrandan, 00:10:00).

## 2. 8255 modlarına genel bakış ve kontrol sözcüğü

Slayttaki ağaç yapısına göre G/Ç modu üçe ayrılır (ekrandan, 00:15:00):

- **Mode 0:** Simple I/O for all the three ports A, B and C.
- **Mode 1:** Handshake I/O for ports A and B. Port C bits are used for handshake signals.
- **Mode 2:** Bidirectional data bus only for Port A. Port B can be used in either mode 0 or mode 1. Handshake signals derived from bits of Port C.

Mod 0'da port C'nin 4 üst ve 4 alt biti birbirinden bağımsız olarak giriş ya da çıkış yapılabiliyordu. Mod 1'de port A ve port B yine tek yönlüdür: kontrol sözcüğünde giriş denildiyse 8 bitin hepsi giriş, çıkış denildiyse hepsi çıkıştır. Port C ise artık veri portu olarak değil, el sıkışma sinyallerinin ve durum bitlerinin taşındığı port olarak kullanılır; genel amaçlı kullanılabilen yalnız iki biti kalır. Mod 2'nin en büyük farkı çift yönlü (bidirectional) olmasıdır: port A için giriş mi çıkış mı diye bir ayar yapılmaz.

### 2.1 Mod seçim bitleri neden mod 2'yi yalnız port A'ya bırakır

Hoca kontrol sözcüğünü yeniden hatırlattı. Soldaki bitler grup A'yı (port A ve port C'nin üst yarısı), sağdaki bitler grup B'yi (port B ve port C'nin alt yarısı) programlar. Grup A'nın mod seçimi iki bittir (D6-D5): 00 mod 0, 01 mod 1, 10 ya da 11 mod 2. Grup B'nin mod seçimi tek bittir (D2): 0 mod 0, 1 mod 1. Tek bitle üç mod kodlanamayacağı için mod 2 yalnız grup A'da, yani port A'da tanımlanabilir. Port A mod 2'deyken port B istenirse mod 0 ya da mod 1 olarak kullanılabilir.

## 3. Bit set/reset (BSR) modu

Mod 0, 1 ve 2 dışında bir kullanım biçimi daha vardır: bit set/reset. Bu, port C'nin tek bir ucunu diğer uçları bozmadan doğrudan 1 ya da 0 yapmayı sağlar. Mod 1 ve mod 2'de kesme etkinleştirme (INTE) flip-flop'ları bu yolla açılıp kapatılır.

BSR sözcüğünün yapısı:

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|----|----|----|----|----|----|----|----|
| 0 | X | X | X | bit seçimi | bit seçimi | bit seçimi | S/R |

- D7 = 0 olunca 8255 mod seçimi yerine BSR biçimine geçer.
- D6-D4 önemsizdir; 0 da 1 de yazılabilir.
- D3-D2-D1, port C'nin hangi bitinin değişeceğini ikili olarak verir. Örneğin 101 yazılırsa PC5 seçilir.
- D0, seçilen bite yazılacak değerdir: 1 set, 0 reset.

### 3.1 BSR örneği

Slayttaki soru (ekrandan, 00:20:00): 80H adresinden itibaren ardışık çift adreslere yerleştirilmiş bir 8255'te PC2'yi lojik 1 olacak şekilde, PC6'da ise doluluk oranı (duty cycle) %66 olan bir kare dalga üretecek şekilde programlayın.

**Adresler.** 80H port A'dır. Ardışık çift adreslerde port B 82H, port C 84H, kontrol yazmacı 86H olur. BSR sözcüğü kontrol yazmacına, yani 86H'ye gönderilir (karede "86H → CW" notu).

**PC2'yi 1 yapmak.** D7 = 0 (BSR), D6-D4 = XXX, D3-D1 = 010 (PC2), D0 = 1:

$$0\ XXX\ 010\ 1 \Rightarrow 0000\,0101_2 = 05H \quad \text{ya da} \quad 0111\,0101_2 = 75H$$

Hoca X bitleri önemsiz olduğu için 05H da 75H da gönderilse sonucun değişmeyeceğini, ikisinin de PC2'yi 1 yaptığını vurguladı (karede "0101 → 05h, 75h").

**PC6'da %66 doluluk oranlı kare dalga.** Önce normal kare dalga hatırlatıldı: periyot $T$ ise $T/2$ süre 1, $T/2$ süre 0'dır; bu %50 doluluk oranıdır. %66 doluluk oranında ise periyot üçe bölünür: $2T/3$ süre 1, $T/3$ süre 0.

PC6 için bit seçimi 110'dur (karede "0xxx 110"). Buna göre (ara adım eklendi):

- PC6'yı 1 yapan sözcük: $0\ XXX\ 110\ 1 = 0000\,1101_2 = 0DH$
- PC6'yı 0 yapan sözcük: $0\ XXX\ 110\ 0 = 0000\,1100_2 = 0CH$

Program akışı:

```text
86H'ye 05H yaz            ; PC2 = 1
DONGU:
  86H'ye PC6 = 1 sözcüğü yaz
  DELAY çağır
  DELAY çağır             ; 2 birim süre 1
  86H'ye PC6 = 0 sözcüğü yaz
  DELAY çağır             ; 1 birim süre 0
  DONGU'ye atla
```

Hoca slaytta `MOV AL, ...` / `OUT 86H, AL` satırlarını tek tek yazmadığını, yalnız mantığı gösterdiğini belirtti. <!-- BELİRSİZ: slayttaki tam program karelerde görünmüyor; akış altyazıdan, 0DH/0CH değerleri bit düzeninden hesaplandı. -->

Hoca BSR'nin mod 1 için asıl öneminin PC2, PC4 ve PC6 gibi kesme etkinleştirme bitlerini açmak olduğunu söyledi.

## 4. Mod 1: el sıkışmalı (handshake) G/Ç

Mod 1, tek yönlü veri gönderme ya da almayı bir haberleşme protokolüyle yapar. Slayttaki iki temel bilgi (ekrandan, 00:25:00):

- Grup A ve grup B ayrı ayrı mod 1 için programlanabilir.
- Her grupta 8 bit veri, 4 bit kontrol işareti vardır.

Port A ve port B'nin ikisi de giriş, ikisi de çıkış ya da biri giriş biri çıkış olabilir. Port C uçları el sıkışma işaretlerini okumak ve üretmek için kullanılır. Ağ derslerinden bilinen "handshake" kavramı burada da geçerlidir: iki taraf karşılıklı anlaşarak veri gönderip alır.

> **Hocanın vurgusu:** Bu şemaları ezberlemeye gerek yok. Hangi INTE'nin PC4'ten, hangisinin PC6'dan açıldığını ezberlemek yerine şemayı okumayı ve mantığı kavramayı bilmek yeterlidir; bu şemalar bütün entegreleri ve akış diyagramlarını içeren bir arayüz belgesinde verilmektedir.

### 4.1 Dört kullanım ve kontrol sözcükleri

Mod 1'de dört kullanım vardır: port A giriş, port A çıkış, port B giriş, port B çıkış. Her birinin kontrol sözcüğü ve port C bit görevleri slaytta gösterildi (ekrandan, 00:30:00):

**Port A giriş (mod 1):**

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|----|----|----|----|----|----|----|----|
| 1 | 0 | 1 | 1 | 1/0 | X | X | X |

- D7 = 1: mod seçim biçimi. D6-D5 = 01: grup A mod 1. D4 = 1: port A giriş.
- D3: PC6, PC7 yönü (1 giriş, 0 çıkış). Port A girişken genel amaçlı kalan bitler PC6 ve PC7'dir.
- PC4 = $\overline{STB_A}$ (giriş), PC5 = $IBF_A$ (çıkış), PC3 = $INTR_A$ (çıkış). INTE A, PC4 ile kontrol edilir.

**Port A çıkış (mod 1):**

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|----|----|----|----|----|----|----|----|
| 1 | 0 | 1 | 0 | 1/0 | X | X | X |

- D4 = 0: port A çıkış. D3: PC4, PC5 yönü.
- PC6 = $\overline{ACK_A}$ (giriş), PC7 = $\overline{OBF_A}$ (çıkış), PC3 = $INTR_A$. INTE A, PC6 ile kontrol edilir.
- 0, 1, 2, 3, 6 ve 7 numaralı bitler el sıkışma için ayrıldığından LED ya da düğme için kullanılamaz.

**Port B giriş (mod 1):** `1 X X X X 1 1 X` (D2 = 1 grup B mod 1, D1 = 1 port B giriş). PC2 = $\overline{STB_B}$, PC1 = $IBF_B$, PC0 = $INTR_B$; INTE B, PC2 ile kontrol edilir.

**Port B çıkış (mod 1):** `1 X X X X 1 0 X` (D1 = 0 port B çıkış). PC2 = $\overline{ACK_B}$, PC1 = $\overline{OBF_B}$, PC0 = $INTR_B$; INTE B yine PC2'dir.

> **Ders sonrası not:** Slaytta port B giriş şemasındaki strobe girişi $\overline{STB_A}$ diye etiketlenmiş; doğrusu $\overline{STB_B}$'dir (ekrandan, 00:30:00).

Port B'nin kontrol sözcüklerinde X ile gösterilen grup A bitleri "kullanılamaz" anlamına gelmez; yalnız port B'yi ilgilendirmez. Örneğin port A ve port B ikisi de mod 1 giriş yapılabilir; bu durumda PC6-PC7 genel amaçlı kalır. Port A çıkış, port B giriş yapılırsa bu kez PC4-PC5 genel amaçlı kalır. Port C'nin alt yarısı ise port B mod 1'deyken tamamen el sıkışmaya gider; genel amaçlı olarak yalnız port A'nın yönüne bağlı iki üst bit (6-7 ya da 4-5) kullanılabilir.

> **Hocanın vurgusu:** Port A giriş ya da çıkış yapıldığında set edilecek INTE biti değişir (girişte PC4, çıkışta PC6). Bunlar karışıyor; şemadan doğru okumayı bilin.

### 4.2 El sıkışma mantığı

El sıkışmanın özü karşılıklı onaydır: gönderen "sana veri gönderdim" der, alan "veriyi aldım, yenisini gönderebilirsin" der, gönderen de "aldığını biliyorum, yenisini gönderiyorum" diyerek döngüyü sürdürür.

Giriş tarafında bakılacak ilk sinyal $\overline{STB}$ (strobe) sinyalidir: karşı tarafın "sana veri gönderdim" bilgisidir. Bu gelince 8255 veriyi alır ve $IBF$ (input buffer full) sinyalini üretir: "veriyi tamponuma aldım". Strobe biter ve $IBF$ 1 iken kesme oluşur; bu "veri okunmaya hazır" demektir.

Çıkış tarafında 8255 veriyi porta yazınca $\overline{OBF}$ (output buffer full) sinyalini üretir: "tamponumda veri var, al". Karşı taraf veriyi alınca $\overline{ACK}$ (acknowledgement) ile onaylar. İkisinin uygun bileşiminden kesme oluşur ve bu "veri gönderildi" bilgisini verir.

Hoca kavramı iki 8255 portunu çapraz bağlayarak anlattı. Port B veri yazan, port A veri okuyan olsun. Port B'nin $\overline{OBF_B}$ çıkışı port A'nın $\overline{STB_A}$ girişine, port A'nın $IBF_A$ çıkışı port B'nin $\overline{ACK_B}$ girişine bağlanır. Port B "veriyi gönderdim" der, port A strobe'u görür, veriyi alır ve $IBF_A$ ile "aldım" der; bu da port B'ye onay olarak gider.

Kesme çıkışları port C'nin içindeki VE kapılarıyla üretilir (ekrandan, 00:35:00):

- Port A giriş: $INTR_A = INTE_A \cdot \overline{STB_A} \cdot IBF_A$ (strobe 1'e dönmüş, IBF 1). INTE A, PC4'e BSR ile 1 yazılarak açılır. Kesme PC3'ten okunur.
- Port B çıkış: $INTR_B = INTE_B \cdot \overline{ACK_B} \cdot \overline{OBF_B}$. INTE B, PC2'ye BSR ile 1 yazılarak açılır. Kesme PC0'dan okunur.
- Port A çıkışta INTE A, PC6'dan açılır ve PC6 ($\overline{ACK_A}$), PC7 ($\overline{OBF_A}$) durumuna göre yine PC3 üretilir. Yani $INTR_A$ her iki yönde PC3, $INTR_B$ her iki yönde PC0'dır.

Derste bu iki port arasındaki çapraz bağlantının örneği yapılmadı; örnekte 8255 dış birimlerle haberleşir. Dış birim bir okuma yapıyorsa strobe çıkışı birimin "latch enable" ucuna, $IBF$ ise "output enable" ucuna bağlanır.

**Soru:** Kesme etkinleştirme (INTE) bitleri her zaman 1 midir, yoksa bit set/reset ile biz mi set ediyoruz?
**Cevap:** Programın başında BSR ile set edilmeleri gerekir. Örneğin port A girişse PC4 set edilir: `0 XXX 100 1` = 09H. 8255 60H'den başlayan çift adreslerdeyse bu sözcük kontrol yazmacına (66H) gönderilir. Port B'de PC2 set edilir: `0 XXX 010 1` = 05H.

> **Ders sonrası not:** Hoca bu cevapta adresleri "port A 60, port B 64, C 66'da kontrol" diye saydı (altyazı bozuk olabilir). Ardışık çift adreslerde doğrusu port A 60H, port B 62H, port C 64H, kontrol yazmacı 66H'dir; BSR sözcüğü 66H'ye gönderilir.

## 5. Mod 1 zamanlama diyagramları

### 5.1 Giriş zamanlaması

Slayttaki diyagramda $\overline{STB}$, $IBF$, $INTR$, $\overline{RD}$ ve "input from peripheral" sinyalleri vardır; $t_{ST}$, $t_{SIB}$, $t_{SIT}$, $t_{RIT}$, $t_{RIB}$, $t_{PS}$, $t_{PH}$ süreleri işaretlidir (ekrandan, 00:45:00). Okumada işlem karşı taraftan strobe gelince başlar; el sıkışma bunu gerektirir.

Adım adım:

1. Çevre biriminden veri gelir. Normalde 1'de duran $\overline{STB}$ 0'a düşer: "sana veri gönderdim".
2. 8255 kısa bir gecikmeyle ($t_{SIB}$) kendi içindeki $IBF$'yi 1 yapar: "input buffer full".
3. Bir süre sonra ($t_{ST}$ strobe süresi sonunda) $\overline{STB}$ tekrar 1'e çıkar. Artık strobe 1, $IBF$ 1 ve INTE 1 olduğundan VE kapısı $INTR$'yi 1 yapar ($t_{SIT}$).
4. İşlemci kesme oluştuktan sonra $\overline{RD}$ ile okuma yapar. $\overline{RD}$ 0'da etkindir.
5. $\overline{RD}$'nin düşen kenarında $INTR$ 0'a düşer ($t_{RIT}$): okuma yapıldığı için yeni kesme alınabilmelidir.
6. Okuma bitip $\overline{RD}$ 1'e döndüğünde $IBF$ 0'a düşer ($t_{RIB}$).
7. Yeni veri gelince $\overline{STB}$ yine 0'a düşer, $IBF$ yine 1 olur ve döngü tekrarlanır.

Hoca önemli bir noktayı vurguladı: okuma daha geç yapılsaydı $INTR$ okuma yapılana kadar 1 kalırdı; $INTR$ ancak $\overline{RD}$'nin düşen kenarında sıfırlanır.

### 5.2 Çıkış zamanlaması

Yazmada sıra terstir: önce işlemcinin $\overline{WR}$ sinyali gelir, sonra $\overline{OBF}$ gibi sinyaller üretilir.

1. $\overline{WR}$ 0'a düşer, yazma başlar. Bu düşen kenar $INTR$'yi 0'a çeker: "şu an kesme yok, yazma sürüyor". (Başlangıçta $INTR$ 1'dir, yani önceki yazma tamamlanmıştır.)
2. Yazma bitince $\overline{WR}$ 1'e çıkar ve $\overline{OBF}$ 0'a düşer: karşı tarafa "tamponda veri var" denir. Bu sinyal karşı tarafın strobe'una karşılık gelir.
3. Karşı taraf veriyi alınca $\overline{ACK}$'yi 0'a çeker (karşı taraf giriş yapan bir 8255 ise bu onun $IBF$ sinyalidir). $\overline{ACK}$ gelince $\overline{OBF}$ kendini tekrar 1 yapar.
4. Bir süre sonra $\overline{ACK}$ de biter ve 1'e döner. $\overline{OBF}$ = 1 ve $\overline{ACK}$ = 1 olduğunda, küçük bir gecikmeyle $INTR$ 1 olur: yazma işlemi bitti.
5. $INTR$ bir sonraki $\overline{WR}$ düşen kenarına kadar 1 kalır.

> **Ders sonrası not:** Hoca çıkış sırasını özetlerken bir yerde "RD sinyalini göndererek interrupt'ı sıfırlıyorum" dedi (altyazıda); çıkış modunda $INTR$'yi sıfırlayan $\overline{WR}$'nin düşen kenarıdır. Hemen ardından anlattığı akış da buna uygundur.

## 6. Mod 1 durum sözcüğü

Mod 1'de port C'den okuma yapıldığında okunan değer durum sözcüğüdür (status word). Hoca örnek verdi: kontrol yazmacı 86H, port C 84H ise `IN AL, 84H` ile okunan değer o anki durum sözcüğüdür (karede "in A, 84h" notu).

Slayttaki tablo (ekrandan, 00:50:00):

| Mod | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|----|----|----|----|----|----|----|----|----|
| Giriş | I/O | I/O | $IBF_A$ | $INTE_A$ | $INTR_A$ | $INTE_B$ | $IBF_B$ | $INTR_B$ |
| Çıkış | $\overline{OBF_A}$ | $INTE_A$ | I/O | I/O | $INTR_A$ | $INTE_B$ | $\overline{OBF_B}$ | $INTR_B$ |

D7-D3 grup A'ya, D2-D0 grup B'ye aittir. I/O yazan bitler genel amaçlı G/Ç bitleridir ve o anki giriş-çıkış değerini gösterir. En kritik bitler $INTR_A$ ve $INTR_B$'dir: port A girişse $INTR_A$ = 1 okumanın yapılabileceğini, port B çıkışsa $INTR_B$ = 1 yazmanın bittiğini gösterir. $INTE_A$ ve $INTE_B$ ise $INTR$'nin çalışabilmesi için 1 yapılması gereken bitlerdir.

## 7. Mod 1 uygulaması: tuş takımı ve 7 parçalı gösterge

Hoca mod 2'ye geçmeden önce Proteus'ta bir örnek açtı (ekrandan, 00:55:00 ve 01:25:00). Hedef: tuş takımına basıldığı algılanınca basılan tuşun kodunu 7 parçalı göstergede göstermek. Kod, bir sonraki tuşa basılana kadar sabit kalır, basılınca güncellenir. Bu bir sıra (sequence) gerektirdiği için basit G/Ç yerine el sıkışma kullanılır.

### 7.1 Devre

- **Adres çözme:** Bu kez 4'e 16 bir kod çözücü (74154) kullanılmıştır. Çıkışları etkin düşüktür (bubble output); iki etkinleştirme girişi vardır ve ikisi de etkin düşüktür.
- **Tuş takımı tarafı (port A, giriş):** Tuş takımını otomatik tarayan bir entegre (MM74C922) basılan tuşun koordinatını 4 bitlik onaltılık bir değer olarak verir (A en düşük, D en yüksek anlamlı bit). Örneğin bir köşe tuşuna basılınca ABCD = 0000, yanındakine basılınca 0001 verir. Entegrenin iki ucu daha vardır: veri hazır (data available) ucu bir tuşa basılınca 1 olur; çıkış etkinleştirme (output enable) ucu ise verinin okunduğunu entegreye bildirir. Karede bu uçların bir DEĞİL kapısı (U13) üzerinden PC4'e ($\overline{STB_A}$) ve PC5'ten ($IBF_A$) bir DEĞİL kapısı (U11) üzerinden geri gittiği görülür (ekrandan, 00:55:00). <!-- BELİRSİZ: hangi DEĞİL kapısının hangi uca gittiği karede kesin seçilemiyor; altyazıya göre strobe PC4'e, IBF (PC5) output enable'a bağlı. -->
- **Gösterge tarafı (port B, çıkış):** Göstergenin önünde bir BCD-7 parçalı kod çözücü (4511) vardır. Önceki haftalardaki örneklerde segment kodu porttan elle gönderiliyordu; bu entegre gelen 4 bitlik sayıyı kendi kod tablosuyla segmentlere çevirir (örneğin 0001 gelince 1 yazar). Entegrenin bir mandal (latch/strobe) ucu vardır.
- **Yapay onay:** PC1 ($\overline{OBF_B}$) mandal ucuna gider; aynı sinyal art arda iki DEĞİL kapısından (U14, U15) geçip PC2'ye ($\overline{ACK_B}$) döner (ekrandan, 01:25:00).

> **Ek bilgi (derste anlatılmadı):** 4511 bir BCD-7 parçalı kod çözücüdür; 0-9 dışındaki 4 bitlik girişlerde göstergeyi büyük olasılıkla karartır. Bu yüzden onaltılık A-F değerleri bu entegreyle harf olarak gösterilemez.

### 7.2 Adres çözme ve kısmi adresleme

8255'in $\overline{CS}$ ucu kod çözücünün IO1 çıkışına bağlıdır. Kod çözücünün girişlerine A9-A12 gelir; IO1'in seçilmesi için A9 = 1, A10 = A11 = A12 = 0 olmalıdır. A13, A14, A15 bir kapı yapısından geçer: üçü de 0 olduğunda kapı çıkışı 1 olur, bu da evrilerek etkin düşük etkinleştirme girişine 0 olarak gider. CPU'nun A2-A1 bitleri 8255'in A1-A0 uçlarına bağlıdır; A0 = 0 alınır (çift adresler).

Bitleri yerine koyunca:

$$A_{15..0} = 0000\ 0010\ 0000\ 0000_2 = 0200H$$

Buna göre port adresleri (A2A1 = 00, 01, 10, 11):

| Port | Adres |
|----|----|
| Port A | 200H |
| Port B | 202H |
| Port C | 204H |
| Kontrol yazmacı | 206H |

Hoca bu devrenin bilerek istenmeyen bir adreslemeye örnek olarak kurulduğunu söyledi. A3-A8 bitleri adres çözmeye katılmamıştır. Kodda A6 = 1 yazılsa da $\overline{CS}$ koşulu sağlanır; yani 8255 yalnız 200H'de değil, 220H, 240H, 260H gibi adreslerde de seçilir. Doğru tasarımda "0200H adresinde tanımlanmış bir 8255" isteniyorsa adres çözmeye girmeyen bu bitler de (örneğin bir VEYA kapısıyla) etkinleştirme koşuluna katılmalıdır.

> **Hocanın vurgusu:** Sınavda bu sık unutuluyor: "200H'da çalışıyor" demek yetmez; sorun yalnız 200H'da çalışmamasıdır. Adres bu yüzden tam çözülmelidir.

### 7.3 Program

Karelerde görünen kod (ekrandan, 01:00:00 ve 01:05:00):

```asm
CODE    SEGMENT PUBLIC 'CODE'
        ASSUME CS:CODE

START:
        mov dx, 206h

        mov al, 09h
        out dx, al
        mov al, 05h
        out dx, al
        mov al, 0BCh
        out dx, al
        mov dx, 202h

ENDLESS:

tekrar1:mov dx, 204h
        in al, dx
        and al, 08h
        cmp al,00
        je tekrar1

        mov dx, 200h
        in al, dx
```

36. satırdan sonrası karelerde görünmüyor; aşağıdaki kısım hocanın anlatımından kurulmuştur:

```asm
        mov bl, al          ; okunan tuş kodu BL'de saklanır
tekrar2:mov dx, 204h        ; durum sözcüğü yeniden okunur
        in al, dx
        and al, 01h         ; INTR_B (PC0)
        cmp al, 00
        je tekrar2
        mov dx, 202h
        mov al, bl
        out dx, al          ; tuş kodu port B'ye yazılır
        jmp ENDLESS
```

<!-- BELİRSİZ: ikinci döngünün etiket adı, BL'nin port B'ye aktarılış biçimi ve döngü sonu atlama satırı karelerde görünmüyor; altyazıdaki anlatıma göre yazıldı. -->

Satır satır açıklama:

- **`mov dx, 206h`:** Kontrol yazmacının adresi DX'e alınır.
- **`09H`:** $0000\,1001_2$: D7 = 0 (BSR), bit seçimi 100 (PC4), D0 = 1. PC4 set edilir. Port A mod 1 giriş olduğu için INTE A, PC4'tür.
- **`05H`:** $0000\,0101_2$: PC2 set edilir. Port B giriş de çıkış da olsa INTE B, PC2'dir.
- Hoca INTE bitlerinin mod seçiminden önce, programın en başında BSR ile açılması gerektiğini vurguladı.
- **`0BCH`:** $1011\,1100_2$: D7 = 1 (mod seçimi), D6-D5 = 01 (grup A mod 1), D4 = 1 (port A giriş), D3 = 1 (port C üst yarısı giriş; port A girişken kullanılabilen PC6-PC7 giriş yapılmıştır, örnekte kullanılmaz), D2 = 1 (grup B mod 1), D1 = 0 (port B çıkış), D0 = 0.
- **`mov dx, 202h`:** Port B'ye geçilir; hocaya göre bu satırın burada pek önemi yoktur.
- **`tekrar1` döngüsü:** 204H port C'dir; mod 1'de port C'den okunan değer durum sözcüğüdür. `AND AL, 08H` ile yalnız D3, yani $INTR_A$ (PC3) bırakılır. Sonuç 00 ise `JE` ile başa dönülür; $INTR_A$ = 1 olunca sonuç 08H olur, atlama gerçekleşmez ve program aşağı devam eder.
- **`mov dx, 200h` / `in al, dx`:** Port A'dan tuş kodu okunur ve geçici olarak BL'ye konur.
- **İkinci döngü:** Durum sözcüğü yeniden okunur, bu kez `AND AL, 01H` ile D0, yani $INTR_B$ (PC0) süzülür. 0 ise beklenir; 1 olunca port B müsaittir ve BL'deki kod 202H'ye yazılır.

**Soru:** Durum sözcüğünü neden 08H ile VE'liyoruz?
**Cevap (bir öğrenci):** Kesmenin aktif olup olmadığını kontrol etmek için. Hoca bunu "$INTR_A$ biti 1 mi 0 mı" diye netleştirdi: PC3 = 1 iken VE işleminin sonucu 08H olur, 00 ile karşılaştırma eşit çıkmaz ve döngüden çıkılır; PC3 = 0 iken sonuç 00'dır ve döngü sürer.

> **Ders sonrası not:** Hoca açıklamanın bir bölümünde "interrupt 0 ise veriyi okuyabilirim" ve "port C'nin durumunda port A'ya ait bir interrupt yok, okuma yapabilirim" dedi. Doğrusu tersidir ve hocanın kendi döngü açıklaması da buna uyar: port A mod 1 girişte $INTR_A$ = 1, çevre biriminin veriyi strobe ile mandalladığını ve okunmaya hazır olduğunu gösterir. Program $INTR_A$ = 0 iken bekler, 1 olunca okur; okuma ($\overline{RD}$) $INTR_A$'yı yeniden 0 yapar.

Simülasyonda hoca bir tuşa basıp tuttuğunda kodlayıcının ABCD çıkışlarının tuşun koordinatını verdiğini (yan tuşlarda 0001, 0010, 0011) ve kodun göstergede göründüğünü gösterdi. İşlemci veriyi aldı, karşı tarafın müsait olup olmadığını sordu ve müsaitlik bilgisi gelince kodu yazdı.

### 7.4 Bağlantıların yeniden okunması

Arayüz belgesinden (ekrandan, 01:10:00) port A okumada PC4'ün $\overline{STB_A}$, PC5'in $IBF_A$ olduğu görülür. Strobe "veri geliyor" bilgisini PC4'e taşır; PC5 "veriyi aldım" bilgisini kodlayıcının çıkış etkinleştirme ucuna gönderir ve kesme oluşur. Ardından yeni tuşun koordinatı okunabilir.

Port B tarafında $\overline{OBF_B}$ (PC1) ve $\overline{ACK_B}$ (PC2) vardır. Burada küçük bir hile yapılmıştır: 4511 karşı taraftan bir onay sinyali üretmez. Bu yüzden $\overline{OBF_B}$ hem mandal ucuna verilir hem de iki DEĞİL kapısından geçirilerek $\overline{ACK_B}$'ye döndürülür. Kapılardan geçerken geçen süre sonunda 8255'e "veri alındı" bilgisi gitmiş olur. Karşı taraf onay üretmiyorsa bu teknik kullanılabilir; el sıkışma bir anlamda atlatılmış (bypass) olur.

> **Hocanın vurgusu:** Bu örnek önemli bir örnektir; üzerinde ayrıca çalışın.

## 8. Mod 2: çift yönlü veri yolu

Mod 2'de yalnız grup A'daki port A kullanılır; port A hem okuma hem yazma yapabilir. 8 bit çift yönlü veri, 5 bit port C'den el sıkışma için kullanılır.

Kontrol sözcüğü (ekrandan, 01:20:00):

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|----|----|----|----|----|----|----|----|
| 1 | 1 | X | X | X | 1/0 | 1/0 | 1/0 |

- D7 = 1 mod seçimi, D6-D5 = 1X (10 ya da 11 fark etmez) mod 2.
- D4 ve D3'ün önemi yoktur: port A çift yönlü olduğu için yön biti yazmaya gerek kalmaz.
- D2: grup B modu (0 mod 0, 1 mod 1). D1: port B (1 giriş, 0 çıkış). D0: PC2-PC0 (1 giriş, 0 çıkış).

Port C'nin yalnız PC0-PC2'si yön ayarına göre genel amaçlı G/Ç olarak kullanılabilir; diğer bitler el sıkışmaya gider.

Mod 2 şemasında (ekrandan, 01:20:00):

- PC4 = $\overline{STB_A}$, PC5 = $IBF_A$: veri geldi, veriyi okudum.
- PC6 = $\overline{ACK_A}$, PC7 = $\overline{OBF_A}$: veri gönderdim, karşı taraf okudu.
- PC3 = $INTR_A$: kesmenin oluşup oluşmadığına bakılacak uç.
- INTE 1 (PC6 ile kontrol edilir) ve INTE 2 (PC4 ile kontrol edilir): kesmenin oluşması için 1 yapılmaları gerekir.

İki VE kapısının çıkışı bir VEYA kapısında birleşir; böylece kesme hem okurken hem yazarken oluşabilir. Çift yönlülüğün sonucu budur. Durum sözcüğünde de port B'ye ait $INTR$ yoktur; kesme yine PC3'ten okunur, etkinleştirme bitleri 4 ve 6'dır. A/B yerine 1/2 diye adlandırılırlar: INTE 1 verinin gönderilmesiyle, INTE 2 verinin alınmasıyla ilgili kesmeyi açar.

Zamanlama mod 1'dekiyle aynıdır: yazma ucu düşünce kesme düşer; yazma bittikten sonra $\overline{OBF}$ oluşur ve karşı tarafa "veri gönderiliyor" denir. $\overline{ACK}$ gelince bir süre sonra $\overline{OBF}$ 1 olur, $\overline{ACK}$ de 1'e dönünce kesme oluşur ve bir sonraki yazmaya kadar sürer. Strobe tarafı okumadaki yapıyla aynıdır.

## 9. Modların özeti

| Mod | Port A | Port B | Port C |
|----|----|----|----|
| Mod 0 | basit G/Ç | basit G/Ç | tamamen G/Ç (üst/alt yarı ayrı) |
| Mod 1 | tek yönlü, el sıkışmalı | tek yönlü, el sıkışmalı | port A girişse PC6-7, çıkışsa PC4-5 genel amaçlı; kalanı durum bitleri |
| Mod 2 | çift yönlü | mod 0 ya da mod 1 (mod 2 olamaz) | PC0-PC2 genel amaçlı; kalanı durum bitleri |

## 10. Ders sonu soruları: DT/R ucu ve donanımsal gecikme

**Soru:** Mikroişlemcinin 40 bacağından biri read, biri write, biri de DT/R (data transmit/receive). Read ya da write seçildiğinde veri gönderilecek mi alınacak mı zaten belli olmuyor mu? DT/R ne işe yarar?
**Cevap:** Read ve write sinyalleri `IN` ve `OUT` komutlarıyla otomatik olarak üretilir; ayrıca bir uç etkinleştirilmez. DT/R ise bir mandal ya da tampon entegresinin yönünü (direction) belirlemek için kullanılabilecek bir uçtur. Derste şematik bir gösterimde değinilmiş, örneklerde kullanılmamıştır.

> **Ders sonrası not:** Hoca DT/R'yi "içeriden programlayabileceğimiz normal bir pin" gibi anlattı. Doğrusu büyük olasılıkla şudur: 8086 minimum modda DT/R ucunu her veri aktarımında kendisi sürer (yazmada 1, okumada 0) ve bu uç veri yolu alıcı-vericilerinin (örneğin 8286) yön girişine bağlanır; yazılımla ayrıca programlanmaz.

**Soru:** Bir yerde fiziksel gecikme mi yapıldı, gecikme donanımsal olarak nasıl sağlandı?
**Cevap:** Lojik devrelerde flip-flop'lar kağıt üzerinde bir bitlik veriyi tutan yapılar olarak anlatılır, ama bu bilgi gerçekte kapılardaki gecikmeler sayesinde tutulur. Örnekte de akış normalde "veri gönderdim" ($\overline{OBF}$) ve "veriyi aldım" ($\overline{ACK}$) şeklindedir, fakat göstergedeki entegre onay sinyali üretmez. Bunun yerine $\overline{OBF_B}$ (PC1) iki DEĞİL kapısından geçirilip $\overline{ACK_B}$'ye (PC2) bağlanmıştır; sinyal çıkıp kısa bir gecikmeyle geri döner. Bu bir hiledir ve el sıkışmayı atlatır.

> **Ders sonrası not:** Hoca kapı gecikmesini "0,2-0,3 milisaniye" diye verdi. Tek bir lojik kapının yayılım gecikmesi büyük olasılıkla nanosaniyeler (onlarca ns) mertebesindedir, milisaniye değil.

## Örnek Sorular

### Soru 1: BSR modu ile PC2 ve PC6 programlama

(ekrandan, 00:20:00) 80H adresinden itibaren ardışık çift adreslere yerleştirilmiş bir 8255'te PC2'yi lojik 1 olacak şekilde, PC6'da ise duty cycle'ı %66 olan bir kare dalga üretecek şekilde programlayın.

**Çözüm (derste verilen):** Kontrol yazmacı 86H'dir. PC2 için `0 XXX 010 1` = 05H (ya da 75H) 86H'ye yazılır. PC6 için bit seçimi 110'dur; PC6 set edilip iki gecikme beklenir, reset edilip bir gecikme beklenir ve bu döngüde tekrarlanır.

> **Çözüm (derste verilmedi):** Tam kod satırları: PC6 set sözcüğü $0000\,1101_2$ = 0DH, reset sözcüğü $0000\,1100_2$ = 0CH (python ile doğrulandı).
>
> ```asm
>         mov al, 05h
>         out 86h, al      ; PC2 = 1
> DONGU:  mov al, 0Dh
>         out 86h, al      ; PC6 = 1
>         call DELAY
>         call DELAY
>         mov al, 0Ch
>         out 86h, al      ; PC6 = 0
>         call DELAY
>         jmp DONGU
> ```

### Soru 2: INTE bitlerinin açılması

(derste sözlü, 00:39:29) Kesme etkinleştirme bitleri kendiliğinden 1 midir, yoksa BSR ile mi set edilir?

**Çözüm (derste verilen):** Programın başında BSR ile set edilir. Port A mod 1 girişse PC4: `0 XXX 100 1` = 09H; port B için PC2: `0 XXX 010 1` = 05H. 60H tabanlı bir 8255'te bu sözcükler kontrol yazmacına (66H) gönderilir.

### Soru 3: Durum sözcüğünü maskeleme

(derste sözlü, 01:07:35) Örnek programda port C'den okunan değeri neden `AND AL, 08H` ile VE'liyoruz ve ardından neden 00 ile karşılaştırıp `JE` ile başa dönüyoruz?

**Çözüm (derste verilen):** 08H maskesi durum sözcüğünün D3 bitini, yani $INTR_A$'yı (PC3) bırakır. $INTR_A$ = 0 iken sonuç 00'dır, `JE` gerçekleşir ve program beklemeye devam eder. $INTR_A$ = 1 olunca (veri mandallandı) sonuç 08H olur, atlama gerçekleşmez ve port A okunur. Port B için aynı mantıkla `AND AL, 01H` ile $INTR_B$ (PC0) beklenir.

### Soru 4: Kısmi adres çözme

(ekrandan, 00:55:00) Örnek devrede 8255 74154'ün IO1 çıkışından seçilmekte, A9-A12 kod çözücüye, A13-A15 etkinleştirme kapısına, A2-A1 8255'in A1-A0 uçlarına gitmektedir. 8255 hangi adreslerde çalışır? Tasarımın sorunu nedir?

**Çözüm (derste verilen):** Taban adres 200H'dir (port A 200H, B 202H, C 204H, kontrol 206H). Ancak A3-A8 adres çözmeye katılmadığı için 8255 yalnız 200H'de değil 220H, 240H, 260H gibi adreslerde de seçilir. Yalnız 200H'de çalışması için bu bitlerin de etkinleştirme koşuluna eklenmesi gerekir.

### Soru 5: DT/R ucunun görevi

(derste sözlü, 01:22:19) Read ve write uçları varken 8086'daki DT/R ucu ne işe yarar? Cevap ve düzeltme için Bölüm 10'a bakın.

## Dersin Toparlaması

Bu derste 8255'in mod 0 dışındaki kullanımları işlendi. BSR modu port C'nin tek bir bitini kontrol sözcüğüyle set ya da reset etmeyi sağlar ve bu yolla hem kare dalga gibi basit sinyaller üretilebilir hem de mod 1 ve mod 2'deki kesme etkinleştirme bitleri açılır. Mod 1, port A ve port B için tek yönlü, el sıkışmalı G/Ç sunar: girişte $\overline{STB}$/$IBF$, çıkışta $\overline{OBF}$/$\overline{ACK}$ çiftleri kullanılır, $INTR_A$ PC3'ten, $INTR_B$ PC0'dan çıkar. Zamanlama diyagramları bu sinyallerin hangi kenarda değiştiğini, durum sözcüğü ise yazılımın bu durumu nasıl yokladığını gösterir.

Proteus örneğinde tuş kodlayıcıdan gelen kod el sıkışmayla okunup 4511 üzerinden göstergeye yazıldı; aynı örnekte kısmi adres çözmenin yol açtığı çoklu adresleme ve onay üretmeyen bir entegre için kapı gecikmesiyle kurulan yapay onay da görüldü. Son olarak mod 2'nin yalnız port A için çift yönlü bir veri yolu sağladığı, iki INTE bayrağının bir VEYA kapısıyla tek $INTR_A$ çıkışında birleştiği anlatıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
