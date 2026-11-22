# Ders 9 Çalışma Özeti

## Genel Konular

- Ara sınav sorularının çözümü (lojik tekrarı)
  - İkiye tümleyen çıkarmada N, V, Z bayrakları: $A=(1100\,0010)_2=-62$, $B=(0011\,1011)_2=59$ için $A-B=A+(-B)$, $-B=(1100\,0101)_2$, sonuç $(1000\,0111)_2$; $N=1$, $V=C_6\oplus C_7=0$, $Z=0$ (ekrandan, 00:05:00).
  - Aritmetik sola kaydırmada taşma: $(1011\,0100)_2=-76$ sola kayınca $(0110\,1000)_2=+104$ olur; işaret değiştiği için $V=1$.
  - Bellek boyutları: $16G\times32$ modülde veri yolu 32 bit, adres yolu $\log_2(2^{34})=34$ bit. $256K\times4$ modüllerle $1M\times32$ RAM için 8 sütun (veri yolu genişletme) $\times$ 4 satır (kapasite genişletme) $=32$ modül ve 2x4 kod çözücü gerekir (ekrandan, 00:10:00).
  - ROM, 4x1 MUX, senkron/asenkron sayıcı, LFSR ve PLA sorularında çıkışın minterim cinsinden bulunması.
- Komut kümesi mimarisi (Instruction Set Architecture, ISA)
  - ISA bir mikroişlemcinin hangi assembly komutlarını desteklediğini gösterir. Her komutun arkasında bir donanım karşılığı vardır; komut kümesi büyüdükçe donanım da karmaşıklaşır.
  - Komut biçimi üç alandan oluşur: Opcode, Mode, Address or operand (ekrandan, 00:25:00).
  - Opcode alanı kaç farklı komut tanımlanabileceğini, Mode alanı adresleme modunu belirler.
  - CISC (ör. 8086) komutlarının uzunlukları ve yürütme süreleri farklıdır; RISC'te komut uzunlukları ve yürütme süreleri eşittir. Derste RISC'e benzeyen, eşit uzunluklu komutlu bir "single cycle computer" incelenecektir.
- Program sayacı ve komutun yürütülmesi
  - Makine kodu program belleğine sıralı yerleşir. Program sayacı (PC) her komuttan sonra bir sonraki komuta ilerler. Dallanmada bir kontrol birimi PC'ye ofset ekler ya da yeni adres yükler.
  - Örnekte her komut iki word kaplar (opcode+mode bir word, adres bir word). Bu yüzden 250'deki komuttan sonra PC 252 olur.
- Adresleme modları (ekrandan, 00:45:00)
  - Direct, immediate, indirect, relative, index, register, register-indirect. Etkin adresler ve ACC içerikleri tablo hâlinde aşağıdadır.
- Tipik komut grupları
  - Veri transferi: LD, ST, MOVE, XCH, PUSH, POP, IN, OUT (ekrandan, 00:55:00).
  - Aritmetik: INC, DEC, ADD, SUB, MUL, DIV, ADDC, SUBB, SUBR, NEG (ekrandan, 01:00:00).
  - Lojik ve bit işleme: CLR, SET, NOT, AND, OR, XOR, CLRC, SETC, COMC (ekrandan, 01:10:00).
  - Kaydırma ve döndürme: SHR, SHL, SHRA, SHLA, ROR, ROL, RORC, ROLC (ekrandan, 01:15:00).
  - Program kontrolü: BR, JMP, CALL, RET, CMP, TEST (ekrandan, 01:45:00).
- Koşullu dallanma
  - Basit dallanmalar tek bir bayrağa bakar: sıfır, elde, işaret ve taşma bayrakları için birer "dallan" ve "dallanma" komutu vardır.
  - Karmaşık dallanmalar CMP sonrasında birden çok bayrağa bakar. İşaretsizde above/below, işaretlide greater/less kullanılır.
- Kesmeler
  - IF bayrağı kurulu iken dış kesme isteği, yürütülen komut bittikten sonra kabul edilir. Kesme alındı (interrupt acknowledge) sinyalinin ardından gelen vektör adresi PC'ye yüklenir.
- Datapath'e giriş: yazmaç dosyası ve fonksiyon birimi
  - Dört yazmaçlı (R0-R3) yazmaç dosyası: A select ve B select (2'şer bit) ile seçilen iki n bitlik 4x1 MUX, A ve B veri kanallarını sürer. Yazma Destination select (2 bit) ile sürülen 2x4 kod çözücü ve Load enable ile yapılır (ekrandan, 02:15:00).
  - MUX B, B kanalı ile komut içine gömülü sabiti (Constant in) seçer. ALU 4 bitlik seçimle ($S_{2:0}$ ve $C_{in}$) çalışır ve V, C, N, Z bayraklarını üretir. Shifter yalnız B kanalını alır ve H select ile (2 bit) yönetilir. MUX F, ALU ile shifter arasında seçim yapar. MUX D, fonksiyon birimi çıkışı ile bellekten gelen veri (Data in) arasında seçim yapar (ekrandan, 02:30:00).
- Aritmetik birim tasarımı
  - Aritmetik birim n bitlik paralel toplayıcı ve B girişi lojiğiyle kurulur: $G=X+Y+C_{in}$ (ekrandan, 02:35:00).
  - Sekiz işlemli bir fonksiyon tablosundan $X_i=A_i$, $C_{in}=K$ ve $Y_i=B_iS_0+\bar{B_i}S_1$ elde edildi (ekrandan, 02:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- İşlem sonucu 0 ise sıfır bayrağı 1 olur
  - Hoca bunun çok karıştırıldığını söyleyip iki kez tekrarladı.
- NEG ile NOT farkı
  - Hoca önce NEG'i bire tümleyen diye anlattı, sonra düzeltti: NEG ikiye tümleyen alır, yani sayının negatifini verir; NOT (complement) bire tümleyendir.
- Aritmetik sağa kaydırma işareti korur
  - SHRA işaret bitini tekrar ederek kaydırır ve sayıyı ikiye böler ($-64\to-32$). SHLA ile SHL aynı sonucu verir.
- CMP ve TEST sonuç saklamaz
  - CMP çıkarma, TEST bit düzeyinde AND gibidir; ikisi de sonucu yazmaca yazmaz, yalnız bayrakları günceller. CMP büyüklük karşılaştırması, TEST bir bitin 0/1 olup olmadığı için kullanılır.
- Alt yordamda yığını temizleme
  - CALL dönüş adresini yığına atar, RET yığının en üstünü PC'ye yükler. Alt yordamda yığına atılan her şey RET'ten önce uygun sırayla çekilmelidir, yoksa yanlış adrese dönülür.
- İşaretli dallanmada $N\oplus V$
  - $A>B$ için taşma ve işaret bayraklarının eşit olması ($N\oplus V=0$) ve $Z=0$ olması gerekir. Taşma olunca işaret bayrağı ters çıkar; bu yüzden tek başına N'ye bakmak yetmez.
- Shifter yalnız B kanalına bağlı
  - Komutlar bu kısıta göre düzenlenmelidir.

## Kısa Tekrar Notları

- Komut biçimi: Opcode | Mode | Address or operand.
- Adresleme modları (PC=250, R1=400, ADRS/NBR=500; M[500]=800, M[800]=300, M[752]=600, M[900]=200, M[400]=700):
  - Direct: ACC $\leftarrow$ M[ADRS] = 800.
  - Immediate: ACC $\leftarrow$ NBR = 500.
  - Indirect: ACC $\leftarrow$ M[M[ADRS]] = 300.
  - Relative: ACC $\leftarrow$ M[ADRS+PC], PC=252 olduğundan etkin adres 752, sonuç 600.
  - Index: ACC $\leftarrow$ M[ADRS+R1], etkin adres 900, sonuç 200.
  - Register: ACC $\leftarrow$ R1 = 400.
  - Register-indirect: ACC $\leftarrow$ M[R1] = 700.
- 8086 karşılıkları: `MOV AL,[100H]` doğrudan, `MOV AL,100H` hemen (immediate), `MOV AL,[SI]` yazmaç dolaylı, `MOV AL,DIZI[BX]` indis adresleme.
- Bit testi: R1'in 4. biti için `AND R1,10H`; sonuç 0'dan farklıysa bit 1'dir. 7. bitin 0 olduğunu anlamak için ya `80H` ile AND edip sonucun 0 olup olmadığına bakılır ya da `7FH` ile OR edilip sonuç FF ile karşılaştırılır.
- Bir yazmaçtaki 1'leri saymak: her adımda kaydırma/döndürme (en düşük bit C'ye düşer) ve ADC ile elde toplanır.
- SHR(1100 1111) = 0110 0111, C=1; SHL(1100 1111) = 1001 1110, C=1.
- İşaretsiz dallanma (CMP R1,R2 sonrası, C ödünç bitidir): BA $C+Z=0$; BAE $C=0$; BB $C=1$; BBE $C+Z=1$; BE $Z=1$; BNE $Z=0$.
- İşaretli dallanma: BG $(N\oplus V)+Z=0$; BGE $N\oplus V=0$; BL $N\oplus V=1$; BLE $(N\oplus V)+Z=1$; BE $Z=1$; BNE $Z=0$.
- 8 bitte işaretsiz aralık 0..255, işaretli aralık $-128..127$.
- Yazmaç dosyası kontrol uçları: A select, B select, D select (Destination select), Load enable.
- Aritmetik birim: $X_i=A_i$, $C_{in}=K$, $Y_i=B_iS_0+\bar{B_i}S_1$.

## Detaylı Açıklamalar

- Program akışı örnekleri
  - PC=250'de "ACC'ye yükle, doğrudan adres, 500" komutu, belleğin 500 adresindeki 800 değerini ACC'ye yükler. Mod immediate olsaydı 500 sabiti doğrudan yüklenirdi.
  - PC=300'de "ACC sıfırsa dallan, doğrudan, 500" komutu bir if yapısı kurar. ACC=0 ise PC'ye 500 yüklenir ve akış 500'den aşağı doğru devam eder. Değilse sonraki komut 302'dir. Bir öğrencinin sorusu üzerine hoca, dallanmadan sonra 500'den aşağı doğru devam edildiğini, geri dönülmediğini açıkladı.
  - 8086'da reset sonrası ilk komut FFFF0H adresinden okunur. Örnek tasarımda ise PC 0000 ile başlar.
- Veri transferi komutları
  - Load bellekten yazmaca, store yazmaçtan belleğe aktarır. XCH üçüncü bir değişken olmadan iki yazmacın ya da iki adresin içeriğini değiştirir (swap).
  - PUSH/POP son giren ilk çıkar (LIFO) yığınını kullanır. 8086'da yığın segmentin en uzak adresinden başlar ve her PUSH'ta SP 2 azalır (word erişimi); SP yine de her zaman yığının üstünü gösterir.
  - IN/OUT G/Ç portlarına erişir. Hoca örnek olarak 8 tuşlu bir buton yazmacından okuma ve LED'lere çıkış göndermeyi verdi. G/Ç adres uzayını bellekten ayırmak, iki uzayı da tam kapasiteyle kullanmayı sağlar; bütün G/Ç MOV ile yapılırsa iki uzay iç içe geçer.
- Aritmetik komutlar
  - CISC'te çarpma/bölme 10-20 saat çevrimi sürebilirken INC bir çevrimde biter. RISC'te karmaşık komutlardan vazgeçilerek komut uzunlukları ve süreleri eşitlenir. 2'nin kuvvetleriyle çarpma ve bölme kaydırmayla yapılabilir.
  - 8086'da `MUL BL` gizli olarak AL'yi kullanır ve sonucu AX'e yazar. `MUL BX` gizli olarak AX'i kullanır ve 32 bitlik sonucu DX:AX'e yazar. Komutlarda bu tür gizli işlenenler olabilir, ama komut tanımında önceden belirtilmeleri gerekir.
  - ADDC (8086'da ADC) büyük veri genişliklerinde düşük kısımdan gelen eldeyi yüksek kısma eklemek için kullanılır. SUBB ödünçlü çıkarma, SUBR ters çıkarmadır ($B-A$).
- Koşullu dallanmanın bayrak analizi
  - İşaretsiz $R1>R2$ ise $R1-R2$ işleminde ödünç oluşmaz ve sonuç sıfırdan farklıdır: $C=0$, $Z=0$, yani $C+Z=0$. $R1\ge R2$ için $C=0$ yeterlidir. $R1<R2$ ise $C=1$ olur. $R1\le R2$ için $C+Z=1$ gerekir.
  - İşaretli $R1>R2$ için üç durum vardır: pozitif-negatif, pozitif-pozitif, negatif-negatif. Son ikisinde taşma olmaz ve $N=0$ olur. Pozitiften negatif çıkarmada taşma olabilir; taşma olursa sonuç negatif görünür ($V=1$, $N=1$). Her durumda $N=V$ olur, ayrıca eşitlik istenmediği için $Z=0$ gerekir: $(N\oplus V)+Z=0$.
  - İşaretli $R1<R2$ için ise her durumda $N\ne V$ olur. Örneğin $-2-1=-3$ işleminde taşma yoktur ve $N=1$ olur. $-120-20=-140$ ise $-128$ sınırının dışına taşar: 8 bitlik sonuç $(0111\,0100)_2$ çıkar, yani $N=0$, $V=1$.
  - Bu bayrak fonksiyonları, örneğin BG desteklenecekse, donanımda N, V ve Z'yi işleyen ek bir lojik devre olarak gerçeklenmelidir.
- Yazmaç dosyası ve işlem örneği
  - `ADD R1,R2,R3`, yani $R1\leftarrow R2+R3$: A select ve B select R2 ile R3'ü kanallara çıkarır. Destination select 01 ile kod çözücü yalnız R1'in yükleme kapısını açar, Load enable 1 yapılır. Veri bütün yazmaçlara gider, ama saat kenarında yalnız R1'e yüklenir (ekrandan, 02:25:00).
  - `CMP R1,R2` sonucu saklanmaz; bu durumda Load enable 0 tutulur.
  - Aynı yazmacın iki kanaldan birden çıkabilmesi (ör. R0+R0) için her kanalın kendi MUX'u vardır.
- Aritmetik birim fonksiyon tablosu (ekrandan, 02:50:00)

| $K=C_{in}$ | $S_1$ | $S_0$ | $G$ | $X_i$ | $Y_i$ |
|---|---|---|---|---|---|
| 0 | 0 | 0 | $A$ | $A_i$ | 0 |
| 0 | 0 | 1 | $A+B$ | $A_i$ | $B_i$ |
| 0 | 1 | 0 | $A+\bar{B}$ | $A_i$ | $\bar{B_i}$ |
| 0 | 1 | 1 | $A-1$ | $A_i$ | 1 |
| 1 | 0 | 0 | $A+1$ | $A_i$ | 0 |
| 1 | 0 | 1 | $A+B+1$ | $A_i$ | $B_i$ |
| 1 | 1 | 0 | $A+\bar{B}+1=A-B$ | $A_i$ | $\bar{B_i}$ |
| 1 | 1 | 1 | $A$ | $A_i$ | 1 |

  - $Y_i$'nin hepsi 1 olunca ikiye tümleyende $-1$ elde edilir; bu sayede $A-1$ (K=0) ve $A-1+1=A$ (K=1) işlemleri yapılır. $C_{in}$ ilk yarıda 0, ikinci yarıda 1 seçildiği için ayrı bir elde lojiği gerekmez; $K$ doğrudan $C_{in}$'e bağlanır.
  - Karnaugh haritası $K$'dan bağımsız çıkar ve $Y_i=B_iS_0+\bar{B_i}S_1$ olur. Bu ifade doğruluk tablosuyla kaba kuvvetle python'da kontrol edildi. Bir öğrencinin sorusu üzerine hoca, B girişi lojiğinin doğrudan MUX'la da tasarlanabileceğini onayladı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
