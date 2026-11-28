# Ders 14 Çalışma Özeti

## Genel Konular

- 8255 modlarına genel bakış (ekrandan, 00:15:00)
  - Mod 0 (simple I/O): üç port (A, B, C) da el sıkışma (handshake) sinyali olmadan doğrudan giriş ya da çıkış olarak kullanılır. LED, düğme, 7 parçalı gösterge ve tuş tarama örnekleri önceki iki haftada bu modla yapılmıştı (ekrandan, 00:05:00).
  - Mod 1 (handshake I/O): yalnız port A ve port B için geçerlidir. Portlar tek yönlüdür (ya giriş ya çıkış); port C bitleri el sıkışma ve durum sinyallerini taşır.
  - Mod 2 (bidirectional): yalnız port A için tanımlanır, port A çift yönlü veri yolu olur. Port B bu sırada mod 0 ya da mod 1'de kullanılabilir; el sıkışma sinyalleri port C bitlerinden türetilir.
  - Kontrol yazmacında grup A'nın (port A + port C üst yarısı) mod seçimi 2 bittir (D6-D5: 00 mod 0, 01 mod 1, 1X mod 2); grup B'nin (port B + port C alt yarısı) mod seçimi tek bittir (D2: 0 mod 0, 1 mod 1). Bu yüzden mod 2 yalnız grup A'da mümkündür.
- Bit set/reset (BSR) modu
  - Kontrol sözcüğünün D7 biti 0 olunca 8255 mod seçimi yerine BSR biçimine geçer. D6-D4 önemsizdir (X), D3-D2-D1 port C'nin hangi bitinin seçildiğini ikili olarak verir, D0 o bite yazılacak değerdir (1 set, 0 reset).
  - Mod 1 ve mod 2'de kesmeyi etkinleştiren iç INTE flip-flop'ları bu yolla (port C bitlerine BSR sözcüğü yazılarak) 1 yapılır.
- BSR örneği: 80H'den itibaren ardışık çift adreslere yerleştirilmiş 8255 (ekrandan, 00:20:00)
  - Adresler: port A 80H, port B 82H, port C 84H, kontrol yazmacı 86H. BSR sözcüğü kontrol yazmacına (86H) gönderilir.
  - PC2'yi lojik 1 yapmak: `0 XXX 010 1` → 05H (X'ler 1 alınırsa 75H; ikisi de aynı işi yapar).
  - PC6'da %66 doluluk oranlı (duty cycle) kare dalga: PC6 için bit seçimi 110'dur (ekrandan, 00:20:00). PC6'yı 1 yapan sözcük `0 XXX 110 1` = 0DH, 0 yapan `0 XXX 110 0` = 0CH (ara adım eklendi). PC6 1 yapılıp iki gecikme (periyodun 2/3'ü), sonra 0 yapılıp bir gecikme (1/3'ü) beklenir ve bu döngü tekrarlanır.
- Mod 1 kontrol sözcükleri ve port C bit görevleri (ekrandan, 00:30:00)
  - Port A giriş: `1 01 1 D3 X X X` (D3: PC6,7 için 1 giriş, 0 çıkış). Port A çıkış: `1 01 0 D3 X X X` (D3: PC4,5 için).
  - Port B giriş: `1 X X X X 1 1 X`; port B çıkış: `1 X X X X 1 0 X`.
  - Port A giriş: PC4 = $\overline{STB_A}$ (giriş), PC5 = $IBF_A$ (çıkış), PC3 = $INTR_A$, PC6-PC7 genel amaçlı G/Ç. INTE A, PC4'e BSR ile 1 yazılarak etkinleşir.
  - Port A çıkış: PC6 = $\overline{ACK_A}$ (giriş), PC7 = $\overline{OBF_A}$ (çıkış), PC3 = $INTR_A$, PC4-PC5 genel amaçlı G/Ç. INTE A, PC6 ile etkinleşir.
  - Port B giriş: PC2 = $\overline{STB_B}$, PC1 = $IBF_B$, PC0 = $INTR_B$. Port B çıkış: PC2 = $\overline{ACK_B}$, PC1 = $\overline{OBF_B}$, PC0 = $INTR_B$. Port B'de INTE B her iki yönde de PC2 ile etkinleşir.
  - Her iki grup mod 1'de kullanıldığında port C'nin boşta kalan bitleri yalnız port A'nın yönüne bağlı ikilidir: port A girişse PC6-PC7, çıkışsa PC4-PC5.
  - Her grupta 8 bit veri ve 4 bit kontrol işareti vardır (ekrandan, 00:25:00).
- El sıkışma mantığı
  - Gönderen taraf "veriyi gönderdim", alan taraf "veriyi aldım, yenisini gönderebilirsin" sinyali üretir; döngü bu karşılıklı onayla sürer.
  - İki 8255 portu çapraz bağlanabilir: gönderenin $\overline{OBF}$ çıkışı alıcının $\overline{STB}$ girişine, alıcının $IBF$ çıkışı gönderenin $\overline{ACK}$ girişine gider.
  - Kesme çıkışı ($INTR$) bir VE kapısıyla üretilir: giriş modunda $INTE \cdot \overline{STB} \cdot IBF$, çıkış modunda $INTE \cdot \overline{ACK} \cdot \overline{OBF}$ sinyallerinin hepsi 1 iken $INTR$ = 1 olur.
- Mod 1 giriş zamanlaması (ekrandan, 00:45:00)
  - Çevre birimi veriyi koyar ve $\overline{STB}$'yi 0'a çeker; kısa bir gecikmeyle ($t_{SIB}$) $IBF$ 1 olur (veri tampona alındı).
  - $\overline{STB}$ tekrar 1'e çıkınca ($IBF$ = 1 ve INTE = 1 iken) $INTR$ 1 olur.
  - İşlemci $\overline{RD}$ ile okur. $\overline{RD}$'nin düşen kenarı $INTR$'yi 0'a çeker ($t_{RIT}$), yükselen kenarı $IBF$'yi 0'a çeker ($t_{RIB}$). Okuma yapılmazsa $INTR$ okuma yapılana kadar 1 kalır.
- Mod 1 çıkış zamanlaması
  - $\overline{WR}$'nin düşen kenarı $INTR$'yi 0'a çeker (yazma sürüyor). Yazma bitince ($\overline{WR}$ yükselince) $\overline{OBF}$ 0 olur (veri hazır).
  - Karşı taraf veriyi alınca $\overline{ACK}$'yi 0'a çeker; bu $\overline{OBF}$'yi tekrar 1 yapar. $\overline{ACK}$ 1'e dönünce $INTR$ 1 olur: yazma işlemi tamamlandı.
- Mod 1 durum sözcüğü (status word) (ekrandan, 00:50:00)
  - Mod 1'de port C okunduğunda (`IN AL, <port C adresi>`) okunan değer durum sözcüğüdür.
  - Giriş: D7 I/O, D6 I/O, D5 $IBF_A$, D4 $INTE_A$, D3 $INTR_A$, D2 $INTE_B$, D1 $IBF_B$, D0 $INTR_B$.
  - Çıkış: D7 $\overline{OBF_A}$, D6 $INTE_A$, D5 I/O, D4 I/O, D3 $INTR_A$, D2 $INTE_B$, D1 $\overline{OBF_B}$, D0 $INTR_B$.
- Mod 1 uygulaması: tuş takımından okunan tuş kodunu 7 parçalı göstergede gösterme (Proteus, ekrandan, 00:55:00 ve 01:25:00)
  - Adres çözme: 4'e 16 kod çözücüye (74154, etkin düşük çıkışlar, iki etkin düşük etkinleştirme girişi) A9-A12 girer; 8255'in $\overline{CS}$ ucu IO1 çıkışına bağlıdır. A13-A15 bir kapı yapısından geçip etkinleştirme girişini sürer (üçü 0 iken etkin). CPU A2-A1 → 8255 A1-A0.
  - Taban adres 200H'dir: port A 200H, port B 202H, port C 204H, kontrol 206H.
  - Tuş takımını bir tuş kodlayıcı entegre (MM74C922) tarar ve basılan tuşun koordinatını 4 bit (A en düşük, D en yüksek anlamlı) olarak verir; veri hazır (DA) ve çıkış etkinleştirme (OE) uçları vardır. DA bir DEĞİL kapısıyla PC4'e ($\overline{STB_A}$), PC5 ($IBF_A$) bir DEĞİL kapısıyla OE'ye gider.
  - Göstergeyi BCD-7 parçalı kod çözücü (4511) sürer; gelen sayıyı kendi kod tablosuyla segmentlere çevirir. PC1 ($\overline{OBF_B}$) mandal ucuna (LE/STB) gider; aynı sinyal iki DEĞİL kapısından geçip PC2'ye ($\overline{ACK_B}$) döner. Karşı entegre onay sinyali üretmediği için kapı gecikmeleriyle yapay bir onay oluşturulmuştur.
- Örnek kod (ekrandan, 01:00:00 ve 01:05:00)
  - `09H` (BSR, PC4 = 1) → INTE A; `05H` (BSR, PC2 = 1) → INTE B; `0BCH` = 1011 1100 → grup A mod 1, port A giriş, PC üst yarı giriş, grup B mod 1, port B çıkış.
  - Döngü: port C (204H) okunur, `AND AL, 08H` ile $INTR_A$ (PC3) süzülür, 0 ise beklenir; 1 olunca port A (200H) okunur. Sonra durum sözcüğü yeniden okunur, `AND AL, 01H` ile $INTR_B$ (PC0) beklenir; 1 olunca veri port B'ye (202H) yazılır.
- Mod 2 (ekrandan, 01:20:00)
  - Kontrol sözcüğü: `1 1 X X X D2 D1 D0` (D2 grup B modu, D1 port B yönü, D0 PC2-PC0 yönü).
  - PC3 = $INTR_A$, PC7 = $\overline{OBF_A}$, PC6 = $\overline{ACK_A}$, PC4 = $\overline{STB_A}$, PC5 = $IBF_A$; PC2-PC0 genel amaçlı G/Ç.
  - İki kesme etkinleştirme bayrağı vardır: INTE 1 (PC6, gönderme tarafı) ve INTE 2 (PC4, alma tarafı). İki VE kapısının çıkışı bir VEYA kapısında birleşir; hem okumada hem yazmada $INTR_A$ üretilebilir.
- Özet tablo
  - Mod 0: el sıkışma yok; port C de A ve B gibi tamamen G/Ç olarak kullanılır.
  - Mod 1: A ve B tek yönlü; port C'den yalnız iki bit (port A girişse PC6-7, çıkışsa PC4-5) genel amaçlıdır.
  - Mod 2: yalnız port A çift yönlü; port B mod 0 ya da mod 1; port C'nin PC0-PC2'si genel amaçlı, diğerleri durum bitleri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Mod 1 şemalarını ezberlemeye gerek yok
  - Hangi port C ucunun $\overline{STB}$, $IBF$, $INTE$ olduğunu ezberlemek yerine şemayı okumayı ve el sıkışma mantığını kavramak gerekir; bu bilgiler arayüz belgesinde verilir.
- Port A'nın yönüne göre INTE biti değişir
  - Port A girişte INTE A PC4 ile, çıkışta PC6 ile etkinleşir; port B'de her iki yönde PC2'dir. Bu kolayca karıştırılır.
- INTE bitleri programın başında BSR ile set edilmelidir
  - Bir öğrenci sorusu üzerine: kesme etkinleştirme bitleri kendiliğinden 1 değildir; mod seçiminden önce BSR sözcükleriyle 1 yapılır.
- Kısmi adres çözme hatası
  - Adres çözmeye girmeyen bitler (örnekte A3-A8) yüzünden 8255 yalnız 200H'de değil, 220H, 240H, 260H gibi adreslerde de seçilir. "200H'da çalışıyor" demek yetmez; yalnız 200H'da çalışması için bu bitlerin de kapı yapısına katılması gerekir. Sınavda sık unutulur.
- Mod 1 örneği önemli
  - Tuş takımı ve gösterge örneği üzerinde ayrıca çalışılmalıdır.

## Kısa Tekrar Notları

- BSR: D7 = 0, D3-D1 bit numarası, D0 değer. PC2 set = 05H, PC4 set = 09H, PC6 set = 0DH, PC6 reset = 0CH.
- Mod 1: yalnız A ve B, tek yönlü; mod 2: yalnız A, çift yönlü.
- Giriş el sıkışması: $\overline{STB}$ (çevre → 8255), $IBF$ (8255 → çevre); çıkış: $\overline{OBF}$ (8255 → çevre), $\overline{ACK}$ (çevre → 8255).
- $INTR_A$ = PC3, $INTR_B$ = PC0 (her iki yönde).
- Giriş zamanlaması: $\overline{STB}$↓ → $IBF$↑; $\overline{STB}$↑ → $INTR$↑; $\overline{RD}$↓ → $INTR$↓; $\overline{RD}$↑ → $IBF$↓.
- Çıkış zamanlaması: $\overline{WR}$↓ → $INTR$↓; $\overline{WR}$↑ → $\overline{OBF}$↓; $\overline{ACK}$↓ → $\overline{OBF}$↑; $\overline{ACK}$↑ → $INTR$↑.
- Mod 1'de port C okumak durum sözcüğünü okumaktır; `AND` maskesiyle istenen $INTR$ biti süzülür.
- Kısmi adres çözme birden çok adreste seçilmeye yol açar.

## Detaylı Açıklamalar

- BSR ile kare dalga üretimi: 8255 port C'nin tek bir bitini diğer bitleri bozmadan değiştirmenin yolu BSR sözcüğüdür. 80H tabanlı örnekte kontrol yazmacı 86H'dir. PC2'yi 1 yapmak için `0 XXX 010 1` yazılır; X bitleri önemsiz olduğundan 05H da 75H da aynı sonucu verir. PC6'da %66 doluluk oranlı kare dalga için periyot üçe bölünür: 2/3'ü 1, 1/3'ü 0. Program PC6'yı set eder, gecikme alt programını iki kez çağırır, PC6'yı reset eder, gecikmeyi bir kez çağırır ve başa döner. Hoca slaytta `OUT` satırlarını yazmadığını, yalnız mantığı gösterdiğini belirtti. <!-- BELİRSİZ: slayttaki tam kod karelerde görünmüyor; 0DH/0CH değerleri bit düzeninden hesaplandı. -->
- Mod 1 giriş akışı: Çevre birimi veriyi port A'ya koyar ve $\overline{STB_A}$'yı 0'a çeker. 8255 veriyi mandallar ve $IBF_A$'yı 1 yapar. $\overline{STB_A}$ 1'e dönünce, INTE A da 1 ise, VE kapısının çıkışı $INTR_A$ (PC3) 1 olur. İşlemci bunu kesme olarak ya da durum sözcüğünü yoklayarak fark eder ve `IN` ile okur. $\overline{RD}$'nin düşen kenarı $INTR_A$'yı temizler, yükselen kenarı $IBF_A$'yı 0 yapar; çevre birimi yeni veriyi gönderebilir.
- Mod 1 çıkış akışı: İşlemci `OUT` ile port B'ye yazar. $\overline{WR}$'nin düşen kenarı $INTR_B$'yi 0 yapar; yazma bitince $\overline{OBF_B}$ 0 olur ve karşı tarafa "veri hazır" denir. Karşı taraf $\overline{ACK_B}$ ile onaylar; $\overline{ACK_B}$ düşünce $\overline{OBF_B}$ 1'e döner, $\overline{ACK_B}$ yükselince $INTR_B$ 1 olur. Bu, port B'nin yeni veri almaya hazır olduğunu gösterir.
- Örnek devre ve program: 8255, 74154 kod çözücünün IO1 çıkışından seçilir; taban adres 200H. Program önce DX = 206H yükler, `09H` ve `05H` BSR sözcükleriyle INTE A ve INTE B'yi açar, sonra `0BCH` mod sözcüğüyle port A'yı mod 1 giriş, port B'yi mod 1 çıkış yapar. Sonsuz döngüde 204H'den durum sözcüğü okunur ve `AND AL, 08H` / `CMP AL, 00` / `JE` ile $INTR_A$ 1 olana kadar beklenir. Sonra 200H'den tuş kodu okunur, BL'de saklanır, aynı yöntemle `AND AL, 01H` ile $INTR_B$ beklenir ve kod 202H'ye yazılır. Simülasyonda bir tuşa basılınca kodu göstergede görünür ve yeni tuşa basılana kadar kalır.
- Yapay onay sinyali: 4511 kod çözücü "veriyi aldım" sinyali üretmez. Bu yüzden $\overline{OBF_B}$ mandal ucuna verilir ve aynı sinyal art arda iki DEĞİL kapısından geçirilerek $\overline{ACK_B}$'ye döndürülür. Kapıların yayılım gecikmesi kısa bir onay süresi oluşturur ve el sıkışma bu şekilde kısa devre edilir.
- Mod 2: Port A çift yönlüdür; okuma için $\overline{STB_A}$/$IBF_A$ (PC4/PC5), yazma için $\overline{ACK_A}$/$\overline{OBF_A}$ (PC6/PC7) kullanılır. INTE 1 (PC6) gönderme, INTE 2 (PC4) alma kesmesini açar ve iki yol bir VEYA kapısıyla tek $INTR_A$ (PC3) çıkışında birleşir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
