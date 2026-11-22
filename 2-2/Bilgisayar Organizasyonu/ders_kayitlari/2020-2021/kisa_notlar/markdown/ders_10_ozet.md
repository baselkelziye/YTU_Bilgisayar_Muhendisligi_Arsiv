# Ders 10 Çalışma Özeti

## Genel Konular

- Önceki dersin tekrarı: register file ve aritmetik birim
  - Register file'ın iki çıkış kanalı (A ve B) ve bir yazma kanalı (D) vardır. A ve B kanalları için ayrı adres seçim uçları, D kanalı için hedef adres uçları ve bir yazma (write) kontrolü bulunur. İç yapıda MUX'lar okumayı, load uçlarının kontrolü yazmayı sağlar.
  - Function unit iki parçadır: aritmetik lojik birim (ALU) ve kaydırıcı (shifter). ALU da aritmetik birim ve lojik birim olarak ikiye ayrılır.
  - Aritmetik birim $n$ bitlik paralel tam toplayıcıyla kurulur. A kanalı X girişine, B kanalı bir giriş lojiğinden (input logic) geçerek Y girişine bağlanır (ekrandan, 00:05:00).
  - Dışarıdan gelen $C_{in}$ yalnız en düşük anlamlı tam toplayıcının elde girişine bağlıdır, her bit dilimine değil.
  - En genel durumda A giriş lojiği, B giriş lojiği ve elde girişi lojiği vardır. Bu lojikler basit kapılar yerine MUX'larla da kurulabilir.
- Lojik birim tasarımı (ekrandan, 00:15:00)
  - Bit düzeyinde (bitwise) işlemlerde elde taşması yoktur, her bit diğerlerinden bağımsız işlenir. Bu yüzden her bit için bir blok, toplam $n$ blok kullanılır.
  - Her bit dilimi bir 4'e 1 MUX'tır: $S_1S_0 = 00$ girişine $A_i \wedge B_i$, $01$'e $A_i \vee B_i$, $10$'a $A_i \oplus B_i$, $11$'e $\overline{A_i}$ bağlanır.
  - Bütün MUX'ların seçim uçları ortaklanıp $S_1$, $S_0$ olarak dışarı çıkarılır. Çıkışlar $G_0 \ldots G_{n-1}$ olur.
- Aritmetik ve lojik birimin birleştirilmesi
  - İki birim de kombinasyonel olduğu için her zaman sonuç üretir. Hangisinin çıkacağını ek bir seçim ucuna bağlı bir MUX belirler. İki fonksiyon tablosu birleşince ALU'nun fonksiyon tablosu elde edilir.
- Ters yönden soru: giriş lojiğinden fonksiyon tablosu (ekrandan, 00:20:00)
  - $X_i = A_i$, $Y_i = \overline{B_i}S + B_i\overline{C_{in}}$ verilir. $S C_{in}$ = 00: $A+B$, 01: $A+1$, 10: $A-1$, 11: $A-B$.
  - Aynı birim yalnız MUX'larla da kurulabilir: X'e her zaman $A_i$, Y için 4'e 1 MUX'un girişleri sırasıyla $B_i$, 0, 1, $\overline{B_i}$.
- 8 bitlik ALU sorusu (ekrandan, 00:30:00)
  - $S_3$ aritmetik ($S_3 = 0$) ile lojik ($S_3 = 1$) birim arasında seçim yapar. Aritmetik birim $S_2S_1S_0$ ile 8 işlem, lojik birim $S_1S_0$ ile 4 işlem yapar.
  - $C_{in} = S_0$ kısıtı vardır. Bu yüzden her satırda X ve Y'ye ne bağlanacağı $C_{in}$'in değerine göre seçilir (ayrıntı genişletilmiş notta).
- Kaydırıcı (shifter) (ekrandan, 00:45:00)
  - Kaydırıcının tek girişi vardır ve bu giriş B kanalıdır. Kaydırılacak yazmaç mutlaka B kanalından verilmelidir.
  - 4 bitlik örnekte her çıkış bitinde 3 girişli MUX vardır. $S = 00$: $H = B$ (transfer), $01$: $H = sr\,B$ (sağa öteleme, boşalan bite $I_R$), $10$: $H = sl\,B$ (sola öteleme, boşalan bite $I_L$). $11$ tanımsızdır.
- Barrel shifter (döndürme) (ekrandan, 00:50:00)
  - $S_1S_0$ = 00: döndürme yok, 01: bir konum, 10: iki konum, 11: üç konum sola döndürme. $k$ konumluk döndürme için $D_j$, $Y_{(j+k) \bmod 4}$ çıkışındaki MUX'un $k$ numaralı girişine bağlanır.
- Function unit'in tamamı
  - ALU ile kaydırıcının çıkışı arasında MUX F seçim yapar, seçim ucu MF'dir. FS (function select) 4 bittir, son iki biti kaydırıcıya da gider.
- Kontrol kelimesi (control word) (ekrandan, 01:15:00)
  - 8 yazmaçlı register file için DA, AA ve BA 3'er bittir. MB bir bittir: 0 iken B kanalı, 1 iken komuttan gelen sabit (constant in) function unit'in B girişine gider. FS 4 bit, MD 1 bit (0: function unit, 1: data in), RW 1 bittir (1: yaz).
  - 16 bitlik kontrol kelimesi: DA (15-13), AA (12-10), BA (9-7), MB (6), FS (5-2), MD (1), RW (0).
  - Kontrol kelimesi seyrek (sparse) bir gösterimdir ve doğrudan fiziksel uçlara bağlanır. Komut (instruction) ise bunun sıkıştırılmış, kodlanmış hâlidir. Komuttan kontrol kelimesini komut çözücü (instruction decoder) üretir.
- Kontrol kelimesi örnekleri (ekrandan, 01:25:00 ve 02:10:00)
  - $R1 \leftarrow R2 - R3$: 001 010 011 0 0101 0 1
  - $R4 \leftarrow sl\,R6$: 100 XXX 110 0 1110 0 1
  - $R7 \leftarrow R7 + 1$: 111 111 XXX X 0001 0 1
  - $R1 \leftarrow R0 + 2$: 001 000 XXX 1 0010 0 1
  - $Data\ out \leftarrow R3$: XXX XXX 011 0 XXXX X 0
  - $R4 \leftarrow Data\ in$: 100 XXX XXX X XXXX 1 1
  - $R5 \leftarrow 0$: 101 000 000 0 1010 0 1 (aynı yazmaç kendisiyle XOR'lanır)
- ALU durum bitleri (8 bitlik ALU) (ekrandan, 01:50:00)
  - $N = G_7$, $Z = \overline{G_0 + G_1 + \cdots + G_7}$ (NOR), $C = C_7$ (en yüksek anlamlı tam toplayıcının elde çıkışı), $V = C_7 \oplus C_6$.
- Bellekler ve program sayacı (PC)
  - Register file $8 \times 16$ ise veri genişliği 16 bittir. Komut belleği $2^{15} \times 16$ ise PC 15 bit olmalıdır.
  - Dallanma yoksa PC her komuttan sonra 1 artar. Koşullu dallanmada PC'ye işaretli ofset eklenir.
- Komut biçimleri (ekrandan, 01:55:00)
  - Üç biçim vardır: yazmaç (opcode, DR, SA, SB), anlık değerli (immediate) (opcode, DR, SA, OP) ve dallanma/atlama (opcode, AD(sol), SA, AD(sağ)). Opcode 15-9, alanlar 8-6, 5-3 ve 2-0 bitlerindedir.
  - Anlık değer 3 bittir (0-7). Dallanma ofseti 6 bitlik işaretli sayıdır: üst 3 bit 8-6, alt 3 bit 2-0 bitlerindedir.
- Basit bilgisayarın komut kümesi (ekrandan, 02:15:00)
  - MOVA, INC, ADD, SUB, DEC, AND, OR, XOR, NOT, MOVB, SHR, SHL, LDI, ADI, LD, ST, BRZ, BRN, JMP.
  - INC, DEC ve NOT yalnız A kanalından, MOVB ve kaydırmalar yalnız B kanalından çalışır. Sabit yalnız B tarafından gelir.
  - LD: $R[DR] \leftarrow M[R[SA]]$. ST: $M[R[SA]] \leftarrow R[SB]$ (adres A kanalından, veri B kanalından gelir).
  - BRZ/BRN: koşul sağlanırsa $PC \leftarrow PC + se\ AD$, sağlanmazsa $PC \leftarrow PC + 1$. JMP: $PC \leftarrow R[SA]$.
- Bellekteki komutları çözme (ekrandan, 02:30:00)
  - Adres 25: `0000101 001 010 011`, $R1 \leftarrow R2 - R3$. Adres 35: `0100000 000 100 101`, $M[R4] \leftarrow R5$. Adres 45: `1000010 010 111 011`, $R2 \leftarrow R7 + 3$. Adres 55: `1100000 101 110 100`, R6 = 0 ise $PC \leftarrow PC - 20$.
- Tek çevrimli bilgisayarın tamamı (ekrandan, 02:35:00)
  - PC, komut belleği, komut çözücü, zero fill, sign extend, dallanma kontrolü (branch control) ve veri belleği datapath'e eklenir. Kontrol kelimesi 20 bit olur: DA, AA, BA, MB, FS, MD, RW, MW, PL, JB, BC. Komutlar 16 bittir.
- Komut çözücü doğruluk tablosu (ekrandan, 02:45:00)
  - Opcode'un 15, 14, 13 ve 9 numaralı bitleri komut türünü belirler. MB, MD, RW, MW, PL, JB ve BC bu bitlerden üretilir. Tablo Karnaugh haritasıyla sadeleştirilince don't care girişler de 0 ya da 1 değerini alır.
- Kritik yol
  - En uzun gecikme register file okuma, function unit, MUX D ve register file'a yazma yolundadır. Derste toplam yaklaşık 9,8 ns bulundu. Saat periyodu bundan kısa olamaz.

## Hocanın Özellikle Vurguladığı Kısımlar

- $C_{in}$ yalnız en düşük anlamlı tam toplayıcıya bağlıdır
  - Hoca bunu "çok önemli bir nokta" diye vurguladı. Bit dilimi çizilirken ortadaki genel dilim çizilir, 0. ve en yüksek anlamlı bit için özel durumlar (dış $C_{in}$, $C_{out}$) ayrıca belirtilir.
- Kaydırıcının yalnız B kanalını kullanması
  - Kaydırma komutlarında yazmaç B kanalından verilmeli, A kanalı don't care kalır. Kontrol kelimesi sorularında bu sık karıştırılır.
- Artırma yalnız A kanalından
  - Fonksiyon tablosunda $B + 1$ yoktur. Bu yüzden $R7 \leftarrow R7 + 1$ işleminde R7 A kanalına verilmelidir. Hoca "Burası anlaşıldı değil mi? Bu önemli." dedi.
- Kullanılmayan alanlar don't care, ama RW asla
  - $Data\ out \leftarrow R3$ gibi yazma olmayan işlemlerde function unit ve MUX D'nin çıkışı rastgeledir. Bu değerin bir yazmaca yazılmaması için RW mutlaka 0 olmalıdır.
- Komut ile kontrol kelimesi farklıdır
  - Komut kümesinde "sıfırla" gibi bir komut olabilir, ama function unit'te karşılığı yoktur. Bu komut, aynı yazmacı XOR'layan bir kontrol kelimesine çözülür.
- Ters yönlü sorular
  - Giriş lojiğinden fonksiyon tablosuna gitmek, konuyu anlamak için anlamlı bir soru tipi olarak gösterildi.
- Dersin kapsamı
  - Ders yalnız tek çevrimli bilgisayarı kapsar. Kitabın 9. bölümündeki çok çevrimli bilgisayar kısmı kapsam dışıdır.

## Kısa Tekrar Notları

- Lojik birim: bit başına bir 4'e 1 MUX; ortak $S_1S_0$.
- ALU = aritmetik birim + lojik birim + seçici MUX. Function unit = ALU + kaydırıcı + MUX F.
- Aritmetik birimde X'e hep 1'ler bağlanırsa $-1$ (ikiye tümleyen), $C_{in} = 1$ ise $+1$ elde edilir. 0 bağlamak öbür kanalı aktarır.
- $Y_i = \overline{B_i}S + B_i\overline{C_{in}}$, $X_i = A_i$ için: $A+B$, $A+1$, $A-1$, $A-B$.
- Kaydırıcı: 00 transfer, 01 sağa, 10 sola. Barrel shifter: 0-3 konum sola döndürme.
- Kontrol kelimesi (16 bit): DA AA BA MB FS MD RW. Son hâli (20 bit): ek olarak MW, PL, JB, BC.
- MB = 1 sabiti, MD = 1 data in'i seçer. RW = 1 yazar.
- Durum bitleri: $N = G_7$, $Z$ = bütün bitlerin NOR'u, $C = C_7$, $V = C_7 \oplus C_6$.
- PC genişliği = komut belleğinin adres genişliği ($2^{15}$ satır → 15 bit).
- Komut: 7 bit opcode + üç 3 bitlik alan. Anlık değer 3 bit, sıfırla genişletilir (zero fill). Ofset 6 bit, işaretle genişletilir (sign extend).
- $+16$ = 010000, $-16$ = 110000, `101100` = $-20$.
- Komut çözücü: opcode bitleri 15, 14, 13 ve 9 → MB, MD, RW, MW, PL, JB, BC.
- Kritik yol saat periyodunun alt sınırıdır (derste 9,8 ns).

## Detaylı Açıklamalar

- Lojik birim ve ALU'nun birleştirilmesi
  - Lojik birimde her bit dilimi bağımsızdır. AND, OR, XOR ve NOT sonuçları bir 4'e 1 MUX'un girişlerine verilir. $n$ bit için bu dilimden $n$ tane kullanılır, seçim uçları ortaklanır. Aritmetik birim ve lojik birim kombinasyonel oldukları için verilen girişlere göre ikisi de her an bir sonuç üretir. Örneğin biri $A + B$'yi, öbürü $A \wedge B$'yi üretir. Function unit'in çıkışına hangisinin gideceğini fazladan bir seçim ucuna bağlı bir MUX belirler. 8 bitlik ALU sorusunda bu uç $S_3$'tür: $S_3 = 0$ aritmetik, $S_3 = 1$ lojik birim. Hoca önce $S_3\overline{S_2}$ yazılmış çözümü düzeltti ve yalnız $S_3$'e bakmanın yettiğini söyledi.
- $C_{in}$ kısıtlı aritmetik birim tasarımı
  - $C_{in} = S_0$ olduğunda her satırda elde girişi sabittir. Artırma satırlarında $+1$ $C_{in}$'den gelir. $C_{in} = 1$ olan ama $+1$ istenmeyen satırlarda (örneğin $A$ transferi) öbür kanala bütün bitleri 1 verilir: $A + (-1) + 1 = A$. $C_{in} = 0$ iken $-1$ gereken satırlarda da 1'ler bağlanır. Çıkarma $A + \overline{B} + 1$ olarak yapılır. Sonuçta her bit dilimi için X ve Y tarafında birer 8'e 1 MUX gerekir. Seçim uçları $S_2S_1S_0$'dır. X girişleri sırasıyla $A_i, A_i, 0, A_i, A_i, 0, 1, A_i$, Y girişleri $B_i, 1, B_i, 0, 1, B_i, B_i, \overline{B_i}$'dir (ekrandan, 00:40:00). Bu bağlantılar 8 satırın hepsi için python ile kontrol edildi.
- Kontrol kelimesini belirleme yöntemi
  - Önce işlemin hangi kanalları kullandığı belirlenir: kaynaklar A ve B kanalına, hedef D adresine yazılır. Sonra B tarafına yazmaç mı sabit mi geleceği (MB), function unit'te hangi işlemin yapılacağı (FS), D kanalına function unit çıkışının mı data in'in mi verileceği (MD) ve yazma olup olmadığı (RW) seçilir. Fonksiyon tablosunda doğrudan karşılığı olmayan işlemler için eldeki işlemlerden yararlanılır. $+2$ sabiti komuttan MB = 1 ile verilir. Sıfırlama, aynı yazmaç A ve B kanalına verilip XOR'lanarak yapılır (aynı yazmacı çıkarmak da bir seçenektir).
- Durum bitlerinin üretilmesi
  - İşaret biti sonucun en anlamlı bitidir. Sıfır biti, bütün çıkış bitleri 0 iken 1 olmalıdır. OR kapısı yalnız hepsi 0 iken 0 verdiği için çıkışın değili alınır, yani NOR kullanılır. Elde biti tam toplayıcı zincirindeki son elde çıkışıdır. Taşma, iki pozitif sayının toplamı negatif ya da iki negatif sayının toplamı pozitif çıktığında oluşur. Bu durum son iki elde bitinin farklı olmasına denk gelir: $V = C_7 \oplus C_6$.
  - Ders sonrası not: Hoca sözlü olarak "bunlar aynıysa overflow var" dedi. Doğrusu ekrana yazdığı XOR ifadesidir: iki elde biti **farklıysa** taşma vardır.
- Komut biçimleri ve genişletme
  - Yazmaç biçiminde üç alan DR, SA ve SB'dir; ADD R1, R2, R3 $R1 \leftarrow R2 + R3$ demektir. Anlık değerli biçimde son alan 3 bitlik sabittir. LDI ve ADI'de bu sabit sıfırla genişletilerek yazmaç genişliğine tamamlanır ve MUX B'nin 1 girişinden function unit'e verilir. Dallanma biçiminde 6 bitlik ofset iki parçaya bölünür. Ofset ikiye tümleyen işaretli sayıdır ve PC'ye eklenebilmesi için işaret biti tekrarlanarak 15 bite genişletilir. Örneğin BRZ R1, 16'da ofset 010000'dır (8-6 bitlerine 010, 2-0 bitlerine 000). $-16$ ise 110000 olur.
  - Ders sonrası not: Hoca opcode için "6 bit" dedi. Ekrandaki biçimde opcode 15-9 bitlerindedir, yani 7 bittir (komut tablosundaki opcode'lar da 7 basamaklı).
- Bellekteki komutların çözülmesi
  - Bir bellek satırının komut olarak nasıl yorumlanacağı opcode'a bağlıdır. 55. adresteki `1100000 101 110 100` BRZ'dir. Koşul yazmacı SA = 110 (R6) alanındadır. Ofset, sol parça 101 ile sağ parça 100 birleştirilerek `101100` olur. En anlamlı bit 1 olduğu için sayı negatiftir, büyüklüğü 20'dir: R6 = 0 ise PC 20 geri gider. Bir satırın komut mu veri mi olduğu tek başına bilinemez. PC o adresi göstermedikçe satır veri olarak değerlendirilir (örneğin 70. adresteki `0000000011000000`).
- Komut çözücü
  - Opcode'un üst üç biti türü verir. 000: yazmaçlarla function unit işlemleri (MB = 0, MD = 0, RW = 1, MW = 0, PL = 0). 001: bellekten okuma (MD = 1, RW = 1). 010: belleğe yazma (MB = 0, MW = 1, RW = 0, MD don't care). 100: yazmaç ve sabitle işlemler (MB = 1, MD = 0, RW = 1). 110: koşullu dallanma (PL = 1, JB = 0; 9. bit BC'yi verir: 0 sıfır, 1 negatif). 111: koşulsuz atlama (PL = 1, JB = 1). PL = 0 olan komutlarda JB ve BC don't care'dir. Hoca bellekten okumada MB'nin aslında don't care alınabileceğini söyledi.
- Kritik yol ve saat
  - Tek çevrimli bilgisayarda sıralı bloklar (PC, register file, bellekler) ortak saatle çalışır, aradaki bloklar kombinasyonel bloklardır. En uzun yolun gecikmesi saat periyodunun alt sınırıdır. Daha kısa bir periyotta sonuçlar oluşmadan yazılmaya çalışılır. <!-- BELİRSİZ: Ara gecikme değerleri karelerde okunamadı; altyazıda yalnız birikimli toplamlar (4,2; 4,8; 5; 9; 9,2; 9,8 ns) geçiyor. -->
- Soru-cevap: bellek beklerken işlemci boş mu kalır?
  - Tek çevrimli bilgisayarda bir komut tamamen bitmeden sonrakine geçilmez, bu yüzden bu bekleme süresi kullanılamaz. Çok çevrimli yapı ve iş hattı (pipeline) aşamaları ayırarak farklı komutların farklı aşamalarını aynı anda yürütür. Günümüz işlemcileri önceden getirme kuyruğu (prefetch queue) ve dallanma tahminiyle komutları önceden çeker, tahmin yanlışsa bunları atar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
