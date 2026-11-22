# Ders 6 Çalışma Özeti

## Genel Konular

- Paralel yüklemeli yazmaç ve yükleme (load) kontrolü
  - $n$ bitlik paralel yüklemeli yazmaç $n$ adet D flip-flop'tan oluşur. Saat uçları ortaklanır, D uçları dışarı çıkarılır, asenkron reset uçları ortaklanarak aktif sıfır bir $\overline{Clear}$ ucu olur (ekrandan, 00:15:00).
  - D flip-flop'ta paralel yükleme için ek lojik gerekmez: $D = D_i$. T flip-flop kullanılırsa girişe $T = D_i \oplus q$ bağlanmalıdır.
  - Asenkron reset saati beklemeden çıkışı sıfırlar. Senkron reset ise saatin yükselen kenarında etkili olur.
  - Yükleme kontrolünün bir yolu saat işaretini kapılamaktır: $C = \overline{Load} + Clock$ (ekrandan, 00:20:00). $Load = 0$ iken flip-flop'ların saat girişi sürekli 1 kalır, yükleme olmaz.
  - Daha doğru yol saati değil D girişini değiştirmektir: $D_i = \overline{L}\,q_i + L\,D_i$. Doğruluk tablosu ve Karnaugh haritası tahtada çıkarıldı (ekrandan, 00:25:00).
- Kontrol birimi ve datapath
  - Kontrol birimi üst seviye kontrol girişlerini bit seviyesinde kontrol sinyallerine (örneğin load) dönüştürür. Datapath'ten durum (status) sinyalleri alır, dışarıya kontrol çıktıları verir (ekrandan, 00:40:00).
  - Datapath, verinin yazmaçlar ve işlem blokları arasında aktarıldığı bağlantı yapısıdır. Bayraklar (carry, overflow) datapath'in ürettiği durum bilgisine örnektir.
  - En basit örnek: $K1: R2 \leftarrow R1$. $K1 = 1$ iken saatin yükselen kenarında R1'in içeriği R2'ye kopyalanır. Buradaki datapath R1'in çıkışlarını R2'nin girişlerine bağlayan $n$ bitlik yoldur (bus).
- Yazmaçlara erişim biçimleri
  - Yazmaç adıyla tümüne, destekleniyorsa tek tek bitlerine ya da 16 bitlik mimaride düşük ve yüksek baytlara erişilebilir. 8086'da AX 16 bitlik, AL ve AH bunun 8 bitlik yarılarıdır.
- RTL (Register Transfer Language) gösterimi (ekrandan, 00:45:00)
  - Yazmaçlar büyük harf ve rakamla gösterilir: AR, R2, DR, IR.
  - Normal parantez yazmacın bir parçasını gösterir: $R2(1)$, $R2(7{:}0)$, $AR(L)$.
  - Ok veri transferidir: $R1 \leftarrow R2$. Virgül eş anlı transferleri ayırır: $R1 \leftarrow R2,\ R2 \leftarrow R1$.
  - Köşeli parantez bellek adresini gösterir: $DR \leftarrow M[AR]$ (dolaylı adresleme).
  - Verilog karşılıkları sözlü anlatıldı: kombinasyonel atama `assign`, eş anlı (non-blocking) yazmaç transferi `<=`.
- Aritmetik mikro işlemler ve toplayıcı-çıkarıcı datapath'i (ekrandan, 01:10:00)
  - Tablo: $R0 \leftarrow R1 + R2$, $R2 \leftarrow \overline{R2}$, $R2 \leftarrow \overline{R2} + 1$, $R0 \leftarrow R1 + \overline{R2} + 1$, $R1 \leftarrow R1 + 1$, $R1 \leftarrow R1 - 1$.
  - Ortak blok toplayıcı-çıkarıcıdır: Y girişleri $S$ (AS) ucuyla XOR'lanır, aynı uç elde girişine verilir. $S = 0$: $X + Y$, $S = 1$: $X + \overline{Y} + 1 = X - Y$.
  - R1 ve R2 kaynak, R0 hedef olan datapath'te bütün işlemler R0'a yazılacak biçimde ve gerekirse iki adımda yapıldı (ayrıntı genişletilmiş notta).
- Lojik mikro işlemler (ekrandan, 01:45:00)
  - $R0 \leftarrow \overline{R1}$, $R0 \leftarrow R1 \wedge R2$, $R0 \leftarrow R1 \vee R2$, $R0 \leftarrow R1 \oplus R2$.
  - Dört işlemin her biri için $n$ bitlik kapı dizisi kurulur, çıkışlar 4 girişli $n$ bitlik bir MUX'a verilir. $S_1S_0$ işlemi, $L0$ yüklemeyi seçer.
- Öteleme mikro işlemleri (ekrandan, 01:50:00)
  - $R1 \leftarrow sl\ R2$ ve $R1 \leftarrow sr\ R2$. Örnek: sl 10011110 = 00111100, sr 11100101 = 01110010.
- Kaynak seçimi MUX ile (ekrandan, 01:55:00)
  - 2'ye 1 MUX ile R0'a R2 ($K1 = 0$) ya da R1 ($K1 = 1$) yüklenir. R0'ın yükleme ucuna $K1 + K2$ bağlıdır.
  - Genelleştirilmiş hâlde geniş bir MUX'un girişlerine yazmaçlar ve adanmış kombinasyonel lojikler (toplayıcı, kapılar, öteleyiciler) bağlanır.
- Ötelemeli yazmaçlar
  - Seri girişli ötelemeli yazmaç kaskat bağlı D flip-flop'lardır (ekrandan, 02:10:00). Yön, bitlerin hangi sırayla adlandırıldığına bağlıdır.
  - Paralel yüklemeli ötelemeli yazmaç (ekrandan, 02:15:00) analiz edildi: Shift = 0, Load = 0: durumu koru; Shift = 0, Load = 1: paralel yükle; Shift = 1: ötele.
  - MUX'lu bit dilimi (ekrandan, 02:25:00): $S_1S_0 = 00$ koru, $01$ $Q_i \leftarrow Q_{i-1}$, $10$ $Q_i \leftarrow Q_{i+1}$, $11$ $Q_i \leftarrow D_i$.
- Sayıcı hatırlatması
  - Ripple sayıcı (ekrandan, 02:30:00): her kademe bir öncekinin yarı frekansında değişir, 0'dan 15'e sayar.
  - Yüklemeli sayıcıda $Q_3$ ve $Q_0$ ilk kez birlikte 1 olduğunda (9) 0 yüklenir, sayıcı 0-9 arasında sayar.
- Yazmaçlar arası transfer yapıları (ekrandan, 02:35:00)
  - Adanmış MUX'lar: her yazmacın önünde kendi 2'ye 1 MUX'u vardır. Farklı kaynaklardan farklı hedeflere eş anlı atama yapılabilir, yazmaç kendi üzerine atanamaz.
  - Tek ortak bus: tek bir 3'e 1 MUX bütün yazmaçları besler. Kendi üzerine atama ve bir kaynaktan birden çok hedefe atama yapılabilir, farklı kaynaklardan farklı hedeflere eş anlı atama yapılamaz.
  - Üç durumlu tamponlarla giriş ve çıkış aynı bus üzerinden de yapılabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Eş anlı (paralel) atama ile sıralı atama farkı
  - $R1 \leftarrow R2,\ R2 \leftarrow R1$ eş anlıdır ve değerleri takas eder: R1 = FFH, R2 = 00H ise sonuçta R1 = 00H, R2 = FFH olur.
  - Sıralı yazılırsa (önce $R1 \leftarrow R2$, sonra $R2 \leftarrow R1$) ikisi de 00H olur.
  - Bu fark programlama dillerinde pek görülmez, Verilog ve FPGA tasarımında önemlidir.
- Saat işaretine müdahale etmemek
  - Saati load ile kapılamak senkron yapıyı bozar. Load uzun kalırsa birden çok yükselen kenar gelir ve hatalı değer yüklenebilir. Bunun yerine D girişine bağlanan değer değiştirilmelidir.
- T flip-flop ile paralel yükleme
  - T girişine doğrudan $D_i$ bağlamak yanlıştır. Doğrusu $T = D_i \oplus q$'dur.
- Datapath gerçeklenebilecek komutları belirler
  - Toplayıcı-çıkarıcıda yalnız ikinci kanal (Y) tümlenebilir. Bu yüzden $R0 \leftarrow \overline{R1}$, $R0 \leftarrow -R1$, $R0 \leftarrow R2 - R1$ ve hedefi R0 olmayan işlemler o datapath ile yapılamaz.
- Carry ve overflow bayrakları
  - Carry, işaretsiz sonucun $n$ bite sığmadığını gösterir. Overflow, işaretli (ikiye tümleyen) sonucun aralık dışına çıktığını gösterir. 8 bitte aralık $-128$ ile $127$'dir. $V = C_n \oplus C_{n-1}$.
- Bus yapılarının karşılaştırılması
  - Adanmış MUX'lar farklı kaynaktan farklı hedefe eş anlı atamaya izin verir. Ortak bus buna izin vermez ama daha az donanım ister.

## Kısa Tekrar Notları

- D flip-flop'ta paralel yükleme: $D = D_i$. T flip-flop'ta: $T = D_i \oplus q$.
- Load kontrollü yükleme: $D_i = \overline{L}\,q_i + L\,D_i$.
- Kapılı saat: $C = \overline{Load} + Clock$. Çalışır ama önerilmez.
- RTL: büyük harf yazmaç, ( ) bit aralığı, $\leftarrow$ transfer, virgül eş anlı transfer, [ ] bellek adresi.
- $K1: R2 \leftarrow R1$ biçimi "kontrol koşulu: transfer" demektir.
- Toplayıcı-çıkarıcı: $S = 0$ ise $X + Y$, $S = 1$ ise $X + \overline{Y} + 1$.
- 8 bitte $-1 = 11111111_2 = FFH$.
- $R0 \leftarrow \overline{R2}$: önce $R1 \leftarrow FFH$, sonra $L0 \cdot AS$.
- $R0 \leftarrow -R2$: önce $R1 \leftarrow 0$, sonra $L0 \cdot AS$.
- $R0 \leftarrow R1 \pm 1$: önce $R2 \leftarrow 1$, sonra $L0 \cdot \overline{AS}$ (artırma) ya da $L0 \cdot AS$ (azaltma).
- Lojik datapath: MUX girişleri 0: NOT, 1: AND, 2: OR, 3: XOR.
- Ortak bus için seçim ucu sayısı $\lceil \log_2(\text{yazmaç sayısı}) \rceil$.
- Ortak bus: aynı anda yalnız tek kaynak. Adanmış MUX: her hedefin kendi kaynağı.

## Detaylı Açıklamalar

- **Paralel yüklemeli yazmacın tasarımı.** Ters tanım bağıntısından hareketle, D flip-flop'ta sonraki durum $Q$ ne olmalıysa D'ye o verilir. Dışarıdan $D_i$ girişi eklenip $Q = D_i$ istenince $D = \overline{q}D_i + qD_i = D_i$ bulunur, yani ek lojik gerekmez. Load ucu eklenince giriş değişkenleri $L$, $D_i$, $q$ olur. $L = 1$ iken $Q = D_i$, $L = 0$ iken $Q = q$ istenir. Sekiz satırlık tablonun D sütunu $L, D_i, q$ sırasıyla 0, 1, 0, 1, 0, 0, 1, 1'dir (ekrandan, 00:25:00). Karnaugh haritasından $D = \overline{L}q + LD_i$ çıkar. Bu, saat işaretine dokunmadan yüklemeyi kontrol eder. Aynı iş bir 2'ye 1 MUX ile de yapılabilir.
- **Eş anlı atamanın donanımdaki karşılığı.** İki yazmacın çıkışları çaprazlama birbirinin girişine bağlı olsun ve iki load ucu birlikte 1 yapılsın. Saatin yükselen kenarında her yazmaç girişindeki eski değeri içeri alır. Yeni değer çıkışa çıkıp diğer yazmacın girişine yayılana kadar (propagasyon gecikmesi) saat kenarı geçmiş ve load düşmüş olur. Bu yüzden değerler birbirinin üzerine yazılmaz, takas edilir.
- **Toplayıcı-çıkarıcı datapath'i ile aritmetik işlemler.** R1 X girişine, R2 Y girişine, çıkış R0'a bağlıdır. Her yazmacın ayrı load ucu vardır (L0, L1, L2), AS işlem seçer. Tek adımda $L0 \cdot \overline{AS}: R0 \leftarrow R1 + R2$ ve $L0 \cdot AS: R0 \leftarrow R1 + \overline{R2} + 1 = R1 - R2$ yapılır. Diğer işlemler bir yazmaca önce sabit yükleyerek elde edilir. Örneğin R1'e FFH (yani $-1$) yüklenip çıkarma seçilince $-1 + \overline{R2} + 1 = \overline{R2}$ olur. Hepsi 8 bit için python ile doğrulandı.
- **Paralel yüklemeli ötelemeli yazmacın analizi ve tasarımı.** Şekildeki devrede her flip-flop'un önünde üç AND kapısı ve bir OR kapısı vardır. Hoca Load ve Shift değerlerine göre hangi AND kapılarının kapandığını izleyerek fonksiyon tablosunu çıkardı. Ters yönde soru da sorulabilir: fonksiyon tablosu verilir ve D flip-flop ile tasarım istenir. O zaman girişler ($D_i$, SI, Shift, Load, $q_i$) ile tablo kurulur, sonraki durum tablodan yazılır ve her D girişi için fonksiyon çıkarılır. En sade hâli şekildeki devredir.
- **Bus yapıları.** Adanmış MUX yapısında her yazmacın kendi seçim ucu ($S0, S1, S2$) ve load ucu vardır. Örnek: $R0 \leftarrow R1$ için $S0 = 1$, $L0 = 1$, diğer load uçları 0. Tek bus yapısında bir 3'e 1 MUX ($S_1S_0$) ortak bus'ı sürer. Örnek: $R0 \leftarrow R1$ için $S_1S_0 = 01$, $L0 = 1$, $L1 = L2 = 0$. $R0 \leftarrow R1,\ R2 \leftarrow R0$ gibi iki farklı kaynaklı eş anlı atama tek bus'ta yapılamaz, adanmış MUX'ta yapılabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
