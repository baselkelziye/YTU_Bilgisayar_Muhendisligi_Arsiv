# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin ilk bölümü bir kısa sınavın sorularının çözümüdür, ikinci bölümü yazmaç transfer seviyesi (Register Transfer Level, RTL) tasarımıdır. Slaytlar Mano ve Kime'nin "Logic and Computer Design Fundamentals" kitabının 7. bölümündendir.
- Kısa sınav soruları (lojik devreler tekrarı)
  - $n$ değişkenli farklı lojik fonksiyon sayısı $2^{2^n}$'dir: 3 değişkenle $2^8 = 256$, 4 değişkenle $2^{16} = 65536$.
  - Tam küme (complete set): AND, OR, NOT'u gerçekleyebilen kapı kümesi. Yalnız NAND ya da yalnız NOR yeterlidir; OR ve NOT birlikte tam kümedir; AND ve OR ile NOT kurulamadığı için tam küme değildir.
  - $(1000\,0000)_2$ işaretsiz 128, ikiye tümleyenli işaretli $-128$; $(1111\,1111)_2$ işaretsiz 255, işaretli $-1$ (ekrandan, 00:10:00).
  - İşaret genişletme (sign extension): en yüksek anlamlı bit sola doğru tekrarlanarak sayı daha geniş bite taşınır.
  - Karnaugh haritasıyla minimal çarpımlar toplamı ve toplamlar çarpımı, 4'e 1 MUX ile gerçeklenen fonksiyonun indirgenmesi, 1 bitlik karşılaştırıcı (eşitlik için XNOR, eşitsizlik için XOR), yüklemeli sayıcının sayma aralığı, çok fonksiyonlu yazmacın bit dilimi bağlantıları, toggle eden flip-flop yapıları ve ROM ile toplayıcı gerçeklemede korunan sigorta sayısı.
- Paralel yüklemeli yazmaç ve enable
  - 4 bitlik paralel yüklemeli yazmaç ortak saatli 4 D flip-flop'tan oluşur. Clear ucu genelde asenkrondur.
  - Yüklemeyi kontrol etmenin iki yolu: saati Load ile kapılamak (saat işareti bozulur) ya da D girişinin önüne enable mantığı koymak (saat bozulmaz).
  - Enable'lı D flip-flop: $D_{FF} = \overline{EN}\,Q + EN\,D$ (ekrandan, 01:05:00).
- Veri yolu (datapath) ve kontrol birimi
  - Datapath: yazmaçlar, aralarındaki bağlantı yolları ve kombinasyonel devreler (toplayıcı, ALU vb.).
  - Kontrol birimi: paketlenmiş kontrol kelimesini kontrol sinyallerine çevirir ve sistemin durum bilgisine göre sonraki adımı belirler.
- Yazmaçların CPU'daki kullanımı
  - Bellek hiyerarşisinin en hızlı ve en küçük birimleridir. Genel amaçlı yazmaçlar, alt alanlar (8086'da AX, AL, AH), komut göstergesi (IP/PC) ve vektör yazmaçları (128/256/512 bit, SIMD).
- Yazmaç transfer notasyonu (ekrandan, 01:30:00)
  - Büyük harf yazmaçtır (AR, R2, DR, IR); parantez yazmacın bir parçasıdır (R2(1), R2(7:0), AR(L)); ok veri transferidir ($R1 \leftarrow R2$); virgül eş zamanlı transferleri ayırır ($R1 \leftarrow R2,\ R2 \leftarrow R1$); köşeli parantez bellek adresidir ($DR \leftarrow M[AR]$).
  - Koşullu transfer: $K_1: R2 \leftarrow R1$; transfer $K_1 = 1$ iken gelen yükselen kenarda olur (ekrandan, 01:25:00).
- Aritmetik, lojik ve öteleme mikro işlemleri
  - Aritmetik (ekrandan, 01:35:00): $R0 \leftarrow R1 + R2$, $R2 \leftarrow \overline{R2}$, $R2 \leftarrow \overline{R2} + 1$, $R0 \leftarrow R1 + \overline{R2} + 1$, $R1 \leftarrow R1 + 1$, $R1 \leftarrow R1 - 1$. Hepsi bir toplayıcı-çıkarıcı ve yazmaçlarla kurulur.
  - Durum bitleri: $C$ işaretsiz taşma (elde), $V = C_n \oplus C_{n-1}$ işaretli taşma (ekrandan, 02:05:00).
  - Lojik (ekrandan, 02:10:00): NOT, AND, OR, XOR; her bit dilimi için bir 4'e 1 MUX ile tek datapath'te birleştirilir.
  - Öteleme (ekrandan, 02:15:00): $R1 \leftarrow sl\ R2$, $R1 \leftarrow sr\ R2$; boşalan bit 0 ile doldurulur.
- MUX ile yazmaç seçimi: $K_1$ MUX'u, $K_1 + K_2$ R0'ın Load ucunu sürer (ekrandan, 02:20:00).
- Ötelemeli yazmaçlar: seri giriş/seri çıkış, Shift/Load öncelikli yazmaç (Shift > Load > koruma) ve MUX'lu çift yönlü ötelemeli yazmaç.
- Sayıcılar: asenkron (dalgalı) sayıcı, doygun sayıcı, senkron sayıcı, yüklemeli BCD sayıcı ve kullanılmayan durumlar için kendini düzeltme.

## Hocanın Özellikle Vurguladığı Kısımlar

- Paralel (eş zamanlı) transfer
  - $R1 \leftarrow R2,\ R2 \leftarrow R1$ takası kenar tetiklemeli flip-flop'larla doğru çalışır: girişteki değerler saat kenarında içeri alınır, yeni çıkışlar karşı yazmacın girişine ulaşmadan kenar geçmiştir.
  - Seviye tetiklemede iki yazmaçta da aynı değer görülebilirdi.
- Saat işaretini bozmamak
  - Load'u saat üzerinden değil D girişi üzerinden uygulamak, devredeki tüm yazmaçların aynı saati kullanmasını ve senkron yapının korunmasını sağlar.
- Ortak datapath
  - Altı aritmetik işlem için altı ayrı devre yerine tek bir toplayıcı-çıkarıcı, yazmaçlar ve uygun kontrol uçları yeter. Bu, komut kümesinin ve ALU/CPU tasarımının (tek çevrimli, çok çevrimli, boru hatlı) çıkış noktasıdır.
- Carry ve overflow farkı
  - Carry işaretsiz sayılardaki, overflow işaretli sayılardaki taşmayı gösterir. 8 bitte işaretsiz aralık 0..255, işaretli aralık $-128..127$.
- MUX ile tasarım
  - Karmaşık kombinasyonel blok yerine flip-flop'ların önüne MUX koymak tasarımı çok kolaylaştırır.
  - Hoca sola ve sağa ötelemeyi şöyle tanımlar: sola ötelemede LI (left in) 0. bite, sağa ötelemede RI (right in) en yüksek bite girer.
- Kendini düzeltme: minimal fonksiyon seçilirken don't care'lere verilen değerler kullanılmayan durumların nereye geçeceğini belirler. Kullanılmayan durumlar kendi aralarında dönüyorsa sayıcı kendini düzeltemez.

## Kısa Tekrar Notları

- $2^{2^n}$ farklı $n$ değişkenli fonksiyon vardır.
- NAND tek başına, NOR tek başına, {OR, NOT} tam kümedir; {AND, OR} değildir.
- $(1111\,1111)_2$ işaretli $-1$'dir.
- İşaret genişletme: MSB sola kopyalanır.
- Enable'lı D flip-flop: $D = \overline{EN}Q + EN\,D$.
- RTL: $K_1: R2 \leftarrow R1$; virgül eş zamanlılık; $M[AR]$ bellek.
- $A - B = A + \overline{B} + 1$.
- $\overline{R2}$: A girişine $-1$ (hepsi 1), çıkarma modu; $-R2$: A girişine 0, çıkarma modu.
- $R1+1$: toplama modunda ikinci girişe 1; $R1-1$: çıkarma modunda ikinci girişe 1.
- $C = C_n$, $V = C_n \oplus C_{n-1}$.
- Shift > Load > No change önceliği: $D_i = S\,Q_{i-1} + \bar S L D_i + \bar S \bar L Q_i$.
- MUX'lu ötelemeli yazmaç: 00 koru, 01 $Q_{i-1}$, 10 $Q_{i+1}$, 11 $D_i$.
- Asenkron sayıcıda her kat frekansı ikiye böler: $f/2, f/4, f/8, f/16$.
- Doygun (saturated) sayıcı sınıra gelince orada kalır.
- 0, 1, 2, 4, 5, 6 sayıcısında 3 → 6 ve 7 → 2 geçişleri olduğu için kendini düzeltir.

## Detaylı Açıklamalar

- **Kısa sınav sorularının çözüm mantığı.** ROM ile gerçeklemede çıkış bitlerinde kaç tane 1 varsa o kadar sigorta korunur. İki bitlik iki sayının toplamı ($S_2S_1S_0$) için 16 satırın toplamlarında toplam 22 tane 1 vardır (ekrandan, 00:45:00; python ile doğrulandı). Yüklemeli sayıcıda önce yüklenen değer (örneğin $1001_2 = 9$), sonra Load'u süren bitin ilk 1 olduğu değer bulunur. $Q_2$'yi izleyen sayıcı 9'dan 12'ye kadar sayar (ekrandan, 00:30:00). Toggle sorusunda $D = \bar Q$, $JK = 11$, $J = \bar Q, K = Q$ ve $T = 1$ toggle eder; $T = \bar Q$ olan yapı 1'de, $T = Q$ olan yapı 0'da takılır.
- **Paralel yüklemeli yazmaç ve enable.** Yükleme saatle kontrol edilirse Load ile saat bir kapıdan geçirilir ve o yazmacın gördüğü saat değişir. Enable D girişinden uygulanırsa her flip-flop sistem saatini aynen kullanır. Enable'lı D flip-flop'un fonksiyonu $EN$, $D$ ve $Q$ için doğruluk tablosundan çıkarılır: $EN = 0$ iken $Q$ korunur, $EN = 1$ iken $D$ yüklenir. Dört minterm indirgenince $\overline{EN}Q + EN\,D$ kalır. Bu blok kutulanır ve dört tanesi ortak Load ve Clock ile 4 bitlik yüklemeli yazmacı oluşturur (ekrandan, 01:05:00).
- **Datapath ve kontrol.** Örneğin 5 bitlik bir kontrol kelimesi 32 komutu kodlayabilir, ama bu komutlar 10 ayrı kontrol ucunu sürebilir (yazmaç seçimi, ALU fonksiyonu, hedef yazmaç). Kontrol birimi bu paketi açar ve durum bitlerine (örneğin elde) göre sonraki işlemi belirler. Datapath ise A ve B yazmaçlarını toplayıp sonucu yine A'ya yazan bir toplayıcı-yazmaç düzeni gibi düşünülmelidir.
- **Komut göstergesi.** IP/PC program belleğinin adres uçlarını sürer. Sıralı yürütmede komut boyu kadar artar. Dallanmada ofset bir toplayıcı-çıkarıcı üzerinden eklenir. RISC'te komut boyu sabittir; CISC'te komut boyu değişir ve artış miktarı komut çözülürken belirlenir.
- **Vektör yazmaçları ve SIMD.** 128/256/512 bitlik bir yazmaca birden çok int, short ya da char sığar. Tek komut tüm alt alanlara uygulanır; bu throughput'u artırır. Derleyiciler ve özel kütüphaneler bu yazmaçları kullanır.
- **Mikro işlemlerin donanımı.** Toplayıcı kombinasyonel olduğu için $R1 + R2$ saat gelmeden çıkışta hazırdır; kenarda R0'a yüklenir. $R2 \leftarrow \overline{R2}$ için ya her bite bir NOT kapısı konur ya da toplayıcı-çıkarıcıda $S = 1$ ve A girişine $-1$ (tüm bitler 1) verilir: $-1 + \overline{B} + 1 = \overline{B}$. $R2 \leftarrow \overline{R2} + 1$ için A girişine 0 verilir. $R1 \leftarrow R1 + 1$ için toplama modunda ikinci girişe 0001 verilir ve sonuç her kenarda R1'e geri yazılır. $R1 \leftarrow R1 - 1$ için çıkarma modunda ikinci girişe 1 verilir. Yazmaçlar bir yazmaç dosyasında tutulup iki kaynak ve bir hedef adresiyle seçilirse sonuç yazmacı da kaynaklarla aynı yerde bulunabilir.
- **Lojik mikro işlemler.** Dört işlem 00, 01, 10, 11 kodlarıyla seçilir. Her bit dilimi için bir 4'e 1 MUX'un girişlerine $\overline{R1_i}$, $R1_i \wedge R2_i$, $R1_i \vee R2_i$, $R1_i \oplus R2_i$ bağlanır. MUX çıkışları R0'ın girişlerine gider.
- **Öteleme ve veri seçimi.** Sağa/sola öteleme yapabilen yazmaçta LI ve RI girişleri 0 ile beslenir. Bu örnekte R2 yerinde ötelendiği için R2 de bozulur; R2 korunacaksa önce yükleyip sonra hedefte ötelemek gerekir. MUX'lu yazmaç seçiminde $K_1 = 1$ iken R1, $K_2 = 1, K_1 = 0$ iken R2 R0'a yüklenir, ikisi de 0 iken yükleme yoktur.
- **Shift/Load yazmacı.** $i$. dilimin girişleri Shift, Load, seri giriş, $D_i$, $Q_{i-1}$ ve $Q_i$'dir. Devre önce Shift'e bakar; Shift varsa Load dikkate alınmaz. Shift yoksa ve Load varsa $D_i$ yüklenir. İkisi de yoksa $Q_i$ korunur (ekrandan, 02:30:00 ve 02:35:00).
- **Sayıcılar.** Asenkron sayıcıda her flip-flop'un saati bir öncekinin çıkışından gelir. Senkron sayıcıda tüm flip-flop'lar aynı saati kullanır, $D_i = Q_i \oplus (EN \cdot Q_0 \cdots Q_{i-1})$ biçiminde XOR ve AND zinciri kullanılır (ekrandan, 02:45:00). Yükleme eklenince sayma bloğu ile yükleme bloğu Load ile ayrılır. 0, 1, 2, 4, 5, 6 sayan devrenin durum diyagramında kullanılmayan 011 durumu 110'a, 111 durumu 010'a geçer (ekrandan, 02:50:00). Diyagramdaki geçişler $D_A = A \oplus B$, $D_B = C$, $D_C = \bar B \bar C$ denklemleriyle tutarlıdır (python ile doğrulandı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
