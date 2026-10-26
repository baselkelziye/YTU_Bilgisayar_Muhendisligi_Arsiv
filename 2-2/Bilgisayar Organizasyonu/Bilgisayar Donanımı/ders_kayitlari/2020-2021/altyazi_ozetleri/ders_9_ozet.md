# Ders 9 Çalışma Özeti

## Genel Konular

- Dersin tarihi 7 Mayıs 2021 Cuma. Ders Zoom üzerinden yapıldı.
  - Asıl anlatım yaklaşık 00:12'de başlar. Öncesi selamlaşma ve vize sonrası sohbettir.
  - Kaynak: Mano & Kime, *Logic and Computer Design Fundamentals*, 9. bölüm (Computer Design Basics).
- İşlemci tasarımına giriş
  - CPU iki temel bloktan oluşur: veri yolu birimi (datapath unit) ve kontrol birimi (control unit).
  - CPU'nun dış dünyaya bağlantısı: veri yolu (data bus), adres yolu (address bus), kontrol yolu (control bus).
- Örnek datapath (4 register'lı)
  - Register kümesi (register file), kaynak seçen MUX'lar, MUX B, fonksiyon birimi (ALU + shifter), MUX F, MUX D ve hedef seçen decoder.
- Aritmetik devre tasarımı
  - $n$-bit paralel toplayıcı (parallel adder) ve önüne konan B giriş lojiği (B input logic) ile 8 aritmetik işlem.
  - Karnaugh haritası ile giriş lojiğinin sadeleştirilmesi.
- Alıştırmalar (kitabın bölüm sonu soruları)
  - Hem A hem B giriş lojiği gereken aritmetik devre tasarımı.
  - Verilen $X_i$, $Y_i$ fonksiyonlarından devrenin yaptığı işlemleri bulma (tersine mühendislik).
- Lojik devre, ALU ve kaydırıcı (shifter)
  - AND, OR, XOR, NOT işlemlerini yapan lojik blok.
  - Aritmetik ve lojik bloğun 2'den 1'e MUX ile birleştirilmesi (ALU).
  - MUX'larla kombinasyonel kaydırıcı ve 4 bitlik barrel shifter.
- Genel datapath ve kontrol kelimesi (control word)
  - 8 register'lı datapath için 16 bitlik kontrol kelimesi.
  - Mikro işlemlerin (micro-operation) sembolik ve ikili kontrol kelimesiyle yazılması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dersi derste öğrenin.
  - Sadece ders notlarıyla çalışmak çok vakit kaybettirir.
- İşlemci tasarımı, pipeline, önbellek ve sanal bellek mesleğin temel konularıdır.
  - Mano'nun kitabı bu kavramları belli bir işlemciye bağlı kalmadan anlatır.
- Aritmetik devrede en dikkat edilecek nokta $A-1$ işlemidir.
  - $Y$ girişine "hepsi 1" (all ones) verilir. Bu, ikiye tümleyende $-1$ demektir.
  - $C_{in}=1$ olunca aynı satır $G=A$ verir.
- $C_{in}$ işlem seçme ucu gibi davranır.
  - 2 seçme ucu + $C_{in}$ ile 8 farklı aritmetik işlem tanımlanır.
- B giriş lojiğinde kullanılan $C_{in}$, en düşük anlamlı bite dışarıdan gelen elde girişidir.
  - Tam toplayıcılar arasındaki ara elde bitleriyle karıştırmayın.
- Aritmetik blok ile lojik blok (ve ALU ile shifter) paralel çalışır.
  - İkisi de aynı anda sonuç üretir. Çıkıştaki MUX hangisinin alınacağını seçer.
- Sınavda datapath şeması ve kontrol kelimesi kodlama tablosu verilir.
  - Tabloları ezberlemek gerekmez. Önemli olan tabloyu okuyabilmektir.
  - Kontrol kelimesi soruları klasik sınavların en kolay sorularındandır.
- Kaydırma işlemleri yalnızca B yolu üzerinden yapılır.
  - Kaynak register B adresiyle seçilmelidir.
- Kullanılmayan alanlar "don't care"dir.
  - Tire ile geçilir. Bir değer yazmak gerekirse 0 yazılır.
- Kısa sınav (quiz) ve sınav duyuruları
  - Vize test olarak yapıldı. Bir soruda iki doğru şık olduğu için o şıkkı işaretleyen 14 öğrenciye de 10'ar puan verildi.
  - Kalan quiz klasik olacak. Final sınavının biçimine henüz karar verilmedi.
  - Bu dersten sonra 4 haftalık ders kaldı. Sonraki hafta bayram tatili.

## Kısa Tekrar Notları

- Datapath = register file + fonksiyon birimi (ALU + shifter) + MUX'lar.
- Kontrol birimi datapath'e komut gönderir. Datapath durum bitlerini (V, C, N, Z) geri gönderir.
- 4 register için 4'ten 1'e, 8 register için 8'den 1'e kaynak MUX'u gerekir.
- MUX B: register ile sabit sayı girişi (constant in) arasında seçer.
- MUX F: ALU çıkışı ile shifter çıkışı arasında seçer.
- MUX D: fonksiyon birimi çıkışı ile dışarıdan gelen veri (data in) arasında seçer.
- Hedef register: decoder + load enable ile seçilir.
- Sıfır bayrağı (Z): bütün çıkış bitlerinin NOR'u.
- Aritmetik devre: $G = X + Y + C_{in}$. $X = A$, $Y$ = B giriş lojiğinin çıkışı.
- Mano tablosu: $Y_i = B_i S_0 + \overline{B_i} S_1$.
- ALU: $S_2$ (mode select) = 0 ise aritmetik, 1 ise lojik sonuç.
- 16 bitlik kontrol kelimesi: DA(3) AA(3) BA(3) MB(1) FS(4) MD(1) RW(1).
- $R1 \leftarrow R2 - R3$ için FS = 0101 ($A + \overline{B} + 1$).
- Register'ı sıfırlamanın en kısa yolu: kendisiyle XOR'lamak.

## Detaylı Açıklamalar

### 1. CPU'nun genel yapısı

- CPU içinde iki blok vardır:
  - **Kontrol birimi (control unit):** datapath'e komut (kontrol işaretleri) gönderir.
  - **Datapath birimi (datapath unit):** komutu işler, sonucu üretir ve durum bilgisini kontrol birimine gönderir.
- CPU'nun üç yolu vardır:
  - **Veri yolu (data bus):** çift yönlüdür. Genişliği işlemcinin kaç bitlik olduğunu gösterir.
  - **Adres yolu (address bus):** CPU'dan dışarıya doğrudur.
  - **Kontrol yolu (control bus):** Memory Read, Memory Write, I/O Read, I/O Write ve DMA işaretleri gibi kontrol işaretlerini taşır.

### 2. Örnek datapath (4 register'lı)

- **Register file:** R0, R1, R2, R3.
- **Kaynak seçimi:** İki tane 4'ten 1'e MUX vardır.
  - A select (2 bit) A yolunu (A data) seçer.
  - B select (2 bit) B yolunu (B data) seçer.
  - Register sayısı 8 olsaydı 8'den 1'e MUX ve 3 bitlik seçme ucu gerekirdi.
- **MUX B (2'den 1'e, MB select):** B yolundaki register ile sabit sayı girişi (constant in) arasında seçer.
  - Örnek: "R1'e R0 + 3 yaz" gibi anlık (immediate) işlemler sabit sayı girişinden yapılır.
- **Fonksiyon birimi (function unit):**
  - ALU'nun 4 bitlik G select ucu vardır. Bu uçla 16 farklı işlem seçilebilir.
  - Shifter'ın 2 bitlik H select ucu vardır. Shifter yalnızca B yolundan giriş alır. Kaydırmada boşalan bite seri giriş olarak 0 girer.
  - **MUX F (MF select):** ALU çıkışı ile shifter çıkışı arasında seçer.
  - Durum bitleri: V (taşma, overflow), C (elde, carry), N (negatif), Z (sıfır).
- **MUX D (MD select):** fonksiyon biriminin çıkışı ile dışarıdan gelen veri (data in) arasında seçer.
  - Data in kaynağı bellek ya da bir G/Ç (I/O) birimi olabilir.
- **Hedef seçimi:**
  - MUX D çıkışı bütün register'ların girişine bağlıdır.
  - Hangi register'a yazılacağını hedef seçme decoder'ı (destination select) ve load enable belirler.
  - Örnek: destination select = 00 ise decoder'ın 0 numaralı çıkışı 1 olur. Yalnızca R0 yüklenir.
- **Dış bağlantılar:** A yolundan address out, B yolundan data out çıkar. Bunlar bellek ve G/Ç ile haberleşmek içindir.

### 3. Sıfır algılama (zero detect)

- Hoca sordu: "Bütün bitler 0 iken çıkışı 1 olan tek kapı hangisi?"
- Cevap: **NOR kapısı.**
  - OR, bütün girişler 0 iken 0 verir. NOR ise 1 verir.
  - Girişlerden biri bile 1 olursa NOR çıkışı 0 olur.

### 4. Aritmetik devre tasarımı (Mano örneği)

- Yapı: $n$-bit paralel toplayıcı. $X = A$, $Y$ = B giriş lojiğinin çıkışı.
  - Paralel toplayıcı tam toplayıcılardan (full adder) oluşur. Her tam toplayıcı $A_i$, $B_i$ ve gelen eldeyi toplar.
  - Çıkış: $G = X + Y + C_{in}$.
- Fonksiyon tablosu:

| $S_1 S_0$ | $Y$ | $C_{in}=0$ | $C_{in}=1$ |
| :---: | :---: | :--- | :--- |
| 00 | hepsi 0 | $G = A$ (aktarım) | $G = A + 1$ (artırma) |
| 01 | $B$ | $G = A + B$ (toplama) | $G = A + B + 1$ |
| 10 | $\overline{B}$ | $G = A + \overline{B}$ | $G = A + \overline{B} + 1$ (çıkarma, $A - B$) |
| 11 | hepsi 1 | $G = A - 1$ (azaltma) | $G = A$ (aktarım) |

- "Hepsi 1" neden $-1$ eder?
  - İkiye tümleyende bütün bitleri 1 olan sayı $-1$'dir.
  - $A + (-1) = A - 1$. $C_{in}=1$ olunca $A - 1 + 1 = A$.
- B giriş lojiği için doğruluk tablosu ($S_1$, $S_0$, $B_i$ girişli) Karnaugh haritasına taşınır.
- Sadeleşmiş ifade: $Y_i = B_i S_0 + \overline{B_i} S_1$.
- Devre: her bit için bir B giriş lojiği bloğu bir tam toplayıcının önüne konur. $C_{in}$ en düşük anlamlı bite girer, her bitin eldesi bir sonrakine gider.

### 5. Alıştırma 1: A ve B giriş lojiği olan aritmetik devre

- İstenen işlemler:

| $S_1 S_0$ | $C_{in}=0$ | $C_{in}=1$ |
| :---: | :--- | :--- |
| 00 | $F = A + B$ | $F = A + \overline{B} + 1$ ($A - B$) |
| 01 | $F = \overline{A} + B$ | $F = \overline{A} + B + 1$ ($B - A$) |
| 10 | $F = A - 1$ | $F = A + 1$ |
| 11 | $F = \overline{A}$ | $F = \overline{A} + 1$ ($-A$, ikiye tümleyen) |

- Bir öğrenci farkı fark etti: $\overline{A}$ geçtiği için A'nın önüne de bir giriş lojiği gerekir.
- $C_{in}$'in etkisi:
  - 00 satırında $C_{in}$ değişince $Y$ de $B$'den $\overline{B}$'ye değişiyor. Bu yüzden B giriş lojiği $C_{in}$'i de giriş olarak almalıdır.
  - A giriş lojiğinde böyle bir değişim yoktur.
- Her satır için $X_i$ ve $Y_i$:

| $S_1 S_0$ | $X_i$ | $Y_i$ ($C_{in}=0$) | $Y_i$ ($C_{in}=1$) |
| :---: | :---: | :---: | :---: |
| 00 | $A_i$ | $B_i$ | $\overline{B_i}$ |
| 01 | $\overline{A_i}$ | $B_i$ | $B_i$ |
| 10 | $A_i$ | 1 | 0 |
| 11 | $\overline{A_i}$ | 0 | 0 |

- A giriş lojiği: $X_i = S_0 \oplus A_i$. Öğrenciler sohbette XOR olduğunu buldu.
- B giriş lojiği (4 değişkenli, hocanın sonucu):
  - $Y_i = \overline{C_{in}}\,\overline{S_1} B_i + \overline{C_{in}} S_1 \overline{S_0} + \overline{S_1} S_0 B_i + C_{in} \overline{S_1}\,\overline{S_0}\,\overline{B_i}$
  - Hoca bu ifadeyi doğruluk tablosu ve Karnaugh haritasıyla kendinizin bulmanızı istedi.
- Alıştırma 2 (4 bitlik devre, iki seçme ucu): A ve B'nin biçimi $C_{in}$'e göre değişmiyor. Bu yüzden daha kolay; size bırakıldı.

### 6. Alıştırma 3: Fonksiyondan işlemi bulma

- Verilen: $X_i = A_i$, $Y_i = \overline{B_i} S + B_i \overline{C_{in}}$.
- Sonuç tablosu:

| $S$ | $C_{in}$ | $Y_i$ | $F = X + Y + C_{in}$ |
| :---: | :---: | :---: | :--- |
| 0 | 0 | $B_i$ | $A + B$ (toplama) |
| 0 | 1 | 0 | $A + 1$ (artırma) |
| 1 | 0 | 1 (hepsi 1) | $A - 1$ (azaltma) |
| 1 | 1 | $\overline{B_i}$ | $A + \overline{B} + 1 = A - B$ (çıkarma) |

### 7. Lojik devre ve ALU

- Lojik blok: her bit için bir 4'ten 1'e MUX ve önündeki kapılar.
  - $S_1 S_0$: 00 AND, 01 OR, 10 XOR, 11 NOT ($\overline{A}$).
  - 8 bitlik iki sayı için 8 MUX ve her MUX'un önünde bu kapılardan birer takım gerekir.
- ALU'nun bir biti (one stage of ALU):
  - Aritmetik devrenin bir biti: $A_i$, $B_i$, $S_0$, $S_1$, $C_i$.
  - Lojik devrenin bir biti: seçme uçları olarak $S_0$ yerine $C_{in}$, $S_1$ yerine $S_0$ bağlanır.
  - İki çıkış bir 2'den 1'e MUX'a girer. Seçme ucu $S_2$ (mode select).
  - $S_2 = 0$: 8 aritmetik işlem ($S_1$, $S_0$, $C_{in}$ ile). $S_2 = 1$: 4 lojik işlem.

### 8. Kaydırıcı (shifter) ve barrel shifter

- Tasarım kombinasyonel devreyle yapılır. Flip-flop kullanılmaz.
  - Önceki konularda D flip-floplarla senkron kaydırma register'ı tasarlanmıştı. Bu farklı bir yapıdır.
- 4 bitlik B yolu için 4 tane 4'ten 1'e MUX. Her MUX'un yalnızca 3 girişi kullanılır:
  - $S = 00$: değişiklik yok (aktarım).
  - $S = 01$: sağa kaydırma (ör. $H_2 \leftarrow B_3$, $H_1 \leftarrow B_2$).
  - $S = 10$: sola kaydırma (ör. $H_3 \leftarrow B_2$, $H_2 \leftarrow B_1$).
- Bir öğrenci sordu: "Bir seferde 3 bit kaydırabilir mi?"
  - Bu yapı yalnızca 1 bit kaydırır. Birden fazla bit için barrel shifter kullanılır.
- **4 bitlik barrel shifter:**
  - $S = 00$: döndürme yok. $S = 01$, $10$, $11$: sola 1, 2, 3 konum döndürme (rotate).
  - Örnek (1 konum): $Y_3 = D_2$, $Y_2 = D_1$, $Y_1 = D_0$, $Y_0 = D_3$.
  - 4 konum döndürmek "döndürme yok" ile aynıdır.
  - Döndürme olduğu için seri giriş kanalı yoktur. Yine 4'ten 1'e MUX'larla yapılır.

### 9. Genel datapath ve 16 bitlik kontrol kelimesi

- Genel gösterim: register file $2^m \times n$.
  - $2^m$ register vardır, her biri $n$ bittir. Örnek: 8 register, 16 bit için $2^3 \times 16$.
  - Register seçme adresleri $m$ bittir.
- 8 register'lı datapath için kontrol kelimesi:

| Bitler | Alan | Görev |
| :---: | :---: | :--- |
| 15-13 | DA | Hedef register adresi |
| 12-10 | AA | A kaynak register adresi |
| 9-7 | BA | B kaynak register adresi |
| 6 | MB | 0: register, 1: sabit sayı |
| 5-2 | FS | Fonksiyon seçimi |
| 1 | MD | 0: fonksiyon birimi, 1: data in |
| 0 | RW | 0: yazma yok, 1: yaz |

- Register kodları: R0 = 000, …, R7 = 111.
- FS kodları:

| FS | İşlem | FS | İşlem |
| :---: | :--- | :---: | :--- |
| 0000 | $F = A$ | 1000 | $F = A \wedge B$ |
| 0001 | $F = A + 1$ | 1001 | $F = A \vee B$ |
| 0010 | $F = A + B$ | 1010 | $F = A \oplus B$ |
| 0011 | $F = A + B + 1$ | 1011 | $F = \overline{A}$ |
| 0100 | $F = A + \overline{B}$ | 1100 | $F = B$ |
| 0101 | $F = A + \overline{B} + 1$ | 1101 | $F = \text{sr } B$ |
| 0110 | $F = A - 1$ | 1110 | $F = \text{sl } B$ |
| 0111 | $F = A$ | | |

### 10. Mikro işlem örnekleri (Tablo 9-6)

| Mikro işlem | DA | AA | BA | MB | FS | MD | RW |
| :--- | :---: | :---: | :---: | :---: | :--- | :---: | :---: |
| $R1 \leftarrow R2 - R3$ | R1 | R2 | R3 | Register | $A + \overline{B} + 1$ | Function | Write |
| $R4 \leftarrow \text{sl } R6$ | R4 | — | R6 | Register | sl B | Function | Write |
| $R7 \leftarrow R7 + 1$ | R7 | R7 | — | — | $A + 1$ | Function | Write |
| $R1 \leftarrow R0 + 2$ | R1 | R0 | — | Constant | $A + B$ | Function | Write |
| Data out $\leftarrow R3$ | — | — | R3 | Register | — | — | No Write |
| $R4 \leftarrow$ Data in | R4 | — | — | — | — | Data in | Write |
| $R5 \leftarrow 0$ | R5 | R0 | R0 | Register | $A \oplus B$ | Function | Write |

- Notlar:
  - Kaydırma işleminde kaynak B yolundan (BA) seçilir.
  - $R1 \leftarrow R0 + 2$: komutun içindeki sabit (immediate operand) sabit sayı girişinden alınır.
  - Data out işleminde fonksiyon birimi ve MUX D kullanılmaz. Register'a yazma yoktur.
  - Data in işleminde yalnızca MUX D (data in), DA ve RW önemlidir.
- İkili kontrol kelimesi örnekleri:
  - $R1 \leftarrow R2 - R3$: `001 010 011 0 0101 0 1` = `0010100110010101`.
  - $R4 \leftarrow \text{sl } R6$ (kullanılmayan AA = 000): `100 000 110 0 1110 0 1`.
- Hoca soruyu iki biçimde de sorabilir: sembolik gösterim ya da ikili kod.
- Alıştırma 4: Şekil 11'deki datapath için verilen mikro işlemlerin 16 bitlik kontrol kelimelerini yazın. Ödev olarak bırakıldı.
- Sonraki ders: kontrol birimi ve datapath'in birlikte çalışması.

### Ders sonrası notlar

- **"R3'e 3 ekle, sonucu R4'e yaz" örneği:** Bu örnek datapath'te yalnızca R0-R3 vardır. R4 yoktur. Hocanın kendisi de birkaç saniye sonra örneği "R3 + 3 → R0" diye kullandı.
- **Alıştırma 1, son satır:** $S_1 S_0 = 11$, $C_{in} = 1$ için hoca "A komplement ile 0'ı toplayarak A artı 1 elde ederim" dedi. Doğrusu $\overline{A} + 1$'dir. Bu, A'nın ikiye tümleyenidir ($-A$). $A + 1$ değildir.
- **Alıştırma 1, B giriş lojiği:** Hocanın verdiği 4 terimli $Y_i$ ifadesi, alıştırmanın tablosuyla birlikte 4 bitlik bütün $A$, $B$ değerleri için Python ile denendi. 8 işlemin hepsi doğru çıktı.
- **Alıştırma 3:** $Y_i = \overline{B_i} S + B_i \overline{C_{in}}$ ifadesi Python ile denendi. Dört işlem ($A+B$, $A+1$, $A-1$, $A-B$) doğru çıktı.
- **Mano'nun $Y_i = B_i S_0 + \overline{B_i} S_1$ ifadesi** de Python ile denendi. Tablodaki 8 işlemin hepsi doğru.
- **Kontrol kelimesi bit numaraları:** Hoca BA için önce "7, 6" dedi, sonra düzeltti. Doğrusu BA: 9-7, MB: 6.
- **Lojik bloğun seçme uçları:** Ekrandaki şekle göre lojik bloğun $S_0$ girişine $C_{in}$, $S_1$ girişine $S_0$ bağlıdır. Bu yüzden lojik işlemler $S_2 = 1$ iken $S_0$ ve $C_{in}$ ile seçilir.
- Altyazıda "Manon" Mano, "Kuyuz" quiz, "Data Path Unity" datapath unit, "Carnot Map/Karnomep" Karnaugh haritası, "TUS/Tuz komplement" two's complement (ikiye tümleyen) demektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
