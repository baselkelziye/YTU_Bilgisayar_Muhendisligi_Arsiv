# Ders 2 Çalışma Özeti

## Genel Konular

- Ders, lojik devreler dersinden gereken kombinasyonel ve ardışıl yapı taşlarının tekrarıdır. Anlatım slaytlar üzerinde el çizimiyle yürür.
- Küçük MUX'lardan büyük MUX kurmak
  - Üç tane 2'ye 1 MUX ile 4'e 1 MUX kurulur: ilk katmanda iki MUX ortak $s_0$ ile, ikinci katmanda bir MUX $s_1$ ile seçim yapar.
  - Hangi seçim ucunun daha anlamlı olduğu, diğerleri sabitken o ucu değiştirince seçilen girişin kaç basamak kaydığına bakılarak bulunur: 1 basamak kaydıran düşük anlamlı, 2 basamak kaydıran yüksek anlamlıdır.
  - 16'ya 1 MUX beş tane 4'e 1 MUX ile kurulur (ilk katmanda 4, son katmanda 1).
- Dekoderler
  - $n$ giriş, bir enable ucu ve $2^n$ çıkış vardır ($n \times 2^n$ dekoder). Girişteki ikili sayının ondalık değeri hangi çıkışı gösteriyorsa o çıkış aktif olur. Enable pasifse hiçbir çıkış aktif olmaz.
  - Enable ve çıkışlar aktif 1 ya da aktif 0 olabilir.
  - RAM/ROM adres çözümleme ve G/Ç cihazlarının adres aralıklarının belirlenmesi için kullanılır.
  - 2x4 dekoder: $y_3 = En\,w_1 w_0$, $y_2 = En\,w_1 \bar w_0$, $y_1 = En\,\bar w_1 w_0$, $y_0 = En\,\bar w_1 \bar w_0$.
  - Aktif 1 çıkışlı dekoderin çıkışları seçim uçlarının mintermleridir. Bu yüzden dekoder ve bir OR kapısıyla her lojik fonksiyon gerçeklenebilir.
  - Aktif 0 çıkışlı (ve aktif 0 enable'lı) dekoderin çıkışları makstermlerdir. Fonksiyon toplamlar çarpımı biçiminde yazılıp ilgili çıkışlar kullanılır.
  - Dekoder ağacı: beş tane 2x4 dekoderle 4x16 dekoder.
- Demultiplexer (DEMUX)
  - Tek bir veri girişini, seçim uçlarındaki değere göre $2^n$ çıkıştan birine yönlendirir.
  - 1'e 4 DEMUX: $O_3 = s_1 s_0 I$, $O_2 = s_1 \bar s_0 I$, $O_1 = \bar s_1 s_0 I$, $O_0 = \bar s_1 \bar s_0 I$.
- Enkoderler ve öncelik enkoderi
  - $2^n$ girişli, $n$ çıkışlı. Girişte yalnız bir tane 1 olabilir; çıkış o girişin numarasının ikili karşılığıdır.
  - 4'e 2 enkoderde 16 satırın 12'si "don't care" olduğu için Karnaugh haritasıyla $y_1 = w_2 + w_3$, $y_0 = w_1 + w_3$ bulunur.
  - Öncelik enkoderi birden fazla 1'e izin verir, en yüksek anlamlı 1'i kodlar. Hiç 1 yoksa geçerlilik çıkışı $z = 0$ olur. Kesme önceliği belirlemede kullanılır.
- Toplayıcılar
  - Yarım toplayıcı: $C_{out} = AB$, $S = A \oplus B$.
  - Tam toplayıcı: $S = A \oplus B \oplus C_{in}$, $C_{out} = AB + C_{in}(A \oplus B)$.
  - Tam toplayıcı iki yarım toplayıcı ve bir OR kapısıyla ya da yalnız üç yarım toplayıcıyla kurulabilir.
  - 4 bitlik toplama: bir yarım toplayıcı ve üç tam toplayıcı ya da $C_{in} = 0$ verilmiş dört tam toplayıcı.
- Çok bitli bloklar
  - 8 bitlik 4'e 1 MUX: seçim uçları ortak olan sekiz tane 1 bitlik 4'e 1 MUX.
  - $n$ bitlik iki sayının toplamı $n+1$ bit gerektirir. İki 16 bitlik toplayıcıdan 32 bitlik toplayıcı kurulur.
  - Ripple carry toplayıcıda elde basamaktan basamağa ilerler; gecikme bit sayısıyla artar ve saat frekansını sınırlar. Look-ahead toplayıcı bu gecikmeyi azaltır.
- Toplayıcı-çıkarıcı: $A - B = A + \bar B + 1$. $B$ bitleri kontrol ucuyla XOR'lanır, kontrol ucu $c_0$'a da bağlanır.
- Karşılaştırıcı: 4 bitlik eşitlik için bit çiftleri XNOR'lanıp AND'lenir ya da XOR'lanıp NOR'lanır.
- Üç durumlu tampon (tri-state buffer): enable pasifken çıkış yüksek empedanstır (Z), hat kopmuş gibi davranır. Ortak veri yolunda aynı anda tek cihazın konuşması için gerekir. Dört çeşidi vardır.
- Ardışıl devreler
  - Çıkış hem girişlere hem hafızadaki duruma bağlıdır.
  - Latch seviye tetiklemeli, flip-flop kenar tetiklemelidir.
  - SR latch, saatli SR latch ve D latch; D flip-flop.
  - Asenkron preset/clear ile senkron clear.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dekoder çıkışları mintermdir
  - Aktif 1 çıkışlı dekoderde her çıkış seçim uçlarının bir mintermi, aktif 0 çıkışlıda bir makstermidir. Bu, dekoderle fonksiyon gerçeklemenin temelidir.
- Seçim uçlarının anlam sırası
  - Hiyerarşik MUX ve dekoderlerde hangi ucun daha anlamlı olduğu, ucu değiştirince çıkışın kaç basamak kaydığından anlaşılır.
- Don't care durumları
  - 4'e 2 enkoderi yalnız tablodaki dört satırdan yazınca karmaşık bir devre çıkar; geri kalan 12 satırın don't care olduğu kullanılınca devre iki OR kapısına iner.
- Ortak kapı kullanımı
  - Çok çıkışlı fonksiyonlarda Karnaugh haritasının en sade sonucu her zaman en iyi devre değildir. Tam toplayıcıda $A \oplus B$ kapısı hem toplam hem elde için ortak kullanılır.
- Propagasyon gecikmesi
  - Ripple carry toplayıcıda en düşük bitin eldesinin en yüksek bite ulaşması zaman alır. Bu süre geçmeden sonuç bir sonraki çevrimde kullanılamaz; işlemci saat frekansını etkileyen en önemli unsurlardan biridir.
- Latch ile flip-flop farkı
  - Latch'te saat 1 iken D'deki her değişim çıkışa geçer. Flip-flop yalnız saatin yükselen (ya da düşen) kenarında D'yi örnekler.

## Kısa Tekrar Notları

- $2^n$'e 1 MUX: iki tane $2^{n-1}$'e 1 MUX ve bir 2'ye 1 MUX ile kurulur. 16'ya 1 MUX = 5 tane 4'e 1 MUX.
- 4x16 dekoder = 5 tane 2x4 dekoder (biri enable'ları seçer).
- Aktif 1 dekoder → minterm, aktif 0 dekoder → maksterm.
- 4'e 2 enkoder: $y_1 = w_2 + w_3$, $y_0 = w_1 + w_3$.
- Öncelik enkoderinde $z = 0$ ise çıkış anlamsızdır.
- $S = A \oplus B \oplus C_{in}$, $C_{out} = AB + C_{in}(A \oplus B)$.
- $\overline{A \oplus B} = A \odot B$ (XNOR).
- $n$ bit + $n$ bit → $n+1$ bit.
- $A - B = A + \bar B + 1$: XOR'lar ve $c_0 = 1$.
- Eşitlik karşılaştırıcısı: XNOR + AND ya da XOR + NOR.
- Tri-state: $e = 0$ → $f = Z$.
- Asenkron preset/clear saati beklemez; senkron clear bir sonraki saat kenarında etki eder.

## Detaylı Açıklamalar

- **Hiyerarşik MUX tasarımı.** 4'e 1 MUX'un dört girişi ($w_0..w_3$), iki seçim ucu ($s_1, s_0$) ve bir çıkışı vardır. 2'ye 1 MUX'ların tek seçim ucu ve iki girişi olduğu için ilk katmanda iki MUX gerekir; bunların seçim uçları ortaklanır ve böylece ikisi de aynı anda 0 ya da 1 numaralı girişini aktarır. Ortaya çıkan iki aday arasından seçim için ikinci katmanda bir 2'ye 1 MUX daha kullanılır. Hoca, uçların adını bilmiyormuş gibi davranıp $X$ ve $Y$ diye adlandırdı: ilk katmana bağlı ucu değiştirince çıkış $w_0 \to w_1$ gibi bir basamak, ikinci katmana bağlı ucu değiştirince $w_0 \to w_2$ gibi iki basamak kayıyor. Demek ki ilk katmana bağlanan uç $s_0$, ikinci katmana bağlanan uç $s_1$'dir. Aynı mantıkla 16'ya 1 MUX, dört girişli ilk katmandaki dört tane 4'e 1 MUX ile son katmandaki bir tane 4'e 1 MUX'tan, yani toplam beş MUX'tan oluşur (ekrandan, 00:05:00).
- **Dekoderle fonksiyon gerçekleme.** 2x4 dekoderin doğruluk tablosunda her çıkış sütununda yalnız bir doğru minterm vardır; enable 0 iken bütün çıkışlar 0 olduğu için her terim $En$ ile çarpılır (ekrandan, 00:20:00). Enable 1 kabul edilince çıkışlar $w_1, w_0$'ın mintermleri olur. Örnek: $f(a,b)$ fonksiyonu 00 için 0, diğer üç satır için 1 olsun. $f = \bar a b + a \bar b + ab$ olduğundan $a$ yüksek anlamlı seçim ucuna ($w_1$), $b$ düşük anlamlı uca ($w_0$) bağlanır, enable 1 yapılır ve $y_1, y_2, y_3$ bir OR kapısında birleştirilir (ekrandan, 00:30:00). Aktif 0 çıkışlı ve aktif 0 enable'lı dekoderde her sütunda tek bir 0 bulunduğu için çıkışlar maksterm olarak yazılır: $\bar y_3 = \bar E + \bar w_1 + \bar w_0$ biçiminde, burada $\bar E$ enable ucunun kendisidir. Aynı $f$ fonksiyonu toplamlar çarpımı olarak yalnız 0. makstermden oluşur: $f = a + b$. Bu yüzden enable'a 0, $w_1$'e $a$, $w_0$'a $b$ verildiğinde $\bar y_0$ çıkışı doğrudan $f$ olur.
- **Dekoder ağacı.** 4x16 dekoder için çıkış katmanında dört tane 2x4 dekoder kullanılır; seçim uçları ($w_0, w_1$) ortaktır. Bu dört dekoderin enable uçları beşinci bir 2x4 dekoderin çıkışlarına bağlanır; bu dekoderin girişleri $w_2, w_3$ ve dışarıya açılan enable ucudur (ekrandan, 00:35:00). Böylece dışarıda 4 seçim, 1 enable ve 16 çıkış ucu olur. Örnek: girişler $1110$ (14) iken $w_0$ 1 yapılırsa aktif çıkış 15'e geçer; bir basamaklık kayma $w_0$'ın en düşük anlamlı uç olduğunu gösterir.
- **DEMUX.** 1'e 4 DEMUX'ta veri girişi $I$ (tabloda $A$), seçim uçları $s_1 s_0$'ın ondalık değerindeki çıkışa aktarılır, diğer çıkışlar 0 olur. Her çıkış sütununda sıfırdan farklı tek satır olduğu için $O_3 = s_1 s_0 I$, $O_2 = s_1 \bar s_0 I$, $O_1 = \bar s_1 s_0 I$, $O_0 = \bar s_1 \bar s_0 I$ yazılır; iç yapı dört AND kapısı ve iki NOT kapısıdır (ekrandan, 01:00:00).
- **4'e 2 enkoder ve don't care.** Tabloda yalnız dört geçerli satır vardır: $0001 \to 00$, $0010 \to 01$, $0100 \to 10$, $1000 \to 11$ (ekrandan, 01:10:00). $y_1$'i yalnız bu satırların mintermlerinden yazmak $\bar w_3 w_2 \bar w_1 \bar w_0 + w_3 \bar w_2 \bar w_1 \bar w_0$ gibi uzun terimler verir. Dört değişkenli fonksiyonun 16 satırından 12'si don't care olduğu için Karnaugh haritasında iki tane 8'li grup alınır ve $y_1 = w_2 + w_3$, $y_0 = w_1 + w_3$ bulunur (ekrandan, 01:15:00). $w_0$ çıkışa hiç bağlanmaz.
- **Öncelik enkoderi.** Girişler en yüksek anlamlıdan başlayarak taranır; ilk görülen 1'in numarası çıkışa yazılır, daha düşük anlamlı girişlere bakılmaz. Enkoderden farklı iki özel durum vardır: birden fazla 1 olabilir ve hiç 1 olmayabilir. Hiç 1 yoksa çıkış "0 numaralı giriş" anlamına gelmesin diye geçerlilik çıkışı $z$ 0 olur (ekrandan, 01:05:00). Kesme denetleyicisinde en önemli kesme kaynağı en yüksek anlamlı girişe bağlanarak donanımsal öncelik sağlanır.
- **Yarım ve tam toplayıcı.** Yarım toplayıcı iki bitin toplamını $(C S)_2 = A + B$ olarak iki bitle verir: $C_{out} = AB$, $S = \bar A B + A \bar B = A \oplus B$. Tam toplayıcı üç biti toplar; en büyük toplam $1+1+1 = 3 = 11_2$ olduğundan çıkış yine iki bittir (ekrandan, 01:25:00). Toplamın Karnaugh haritası sadeleşmez, ama $A = 0$ ve $A = 1$ yarıları ayrı ayrı XOR ve XNOR desenidir. $X = B \oplus C$ denirse $\overline{X} = B \odot C$ olur ve $S = \bar A X + A \bar X = A \oplus B \oplus C_{in}$ çıkar. XNOR'un XOR'un tümleyeni olduğu De Morgan ile gösterildi: $\overline{\bar a b + a \bar b} = (a + \bar b)(\bar a + b) = ab + \bar a \bar b$ (ekrandan, 01:35:00). Eldede en sade sonuç $AB + AC + BC$ olsa da, $A \oplus B$ kapısını ortak kullanmak için gruplar değiştirilir: $C_{out} = AB + C_{in}(A \oplus B)$ (ekrandan, 01:40:00).
- **Yalnız yarım toplayıcıyla tam toplayıcı.** Standart yapıda iki yarım toplayıcının elde çıkışları bir OR kapısında birleşir (ekrandan, 01:45:00). OR yerine üçüncü bir yarım toplayıcı konup onun toplam çıkışı $C_{out}$ olarak kullanılabilir; bu yarım toplayıcının elde çıkışı kullanılmaz. İki elde aynı anda 1 olamadığı için XOR, OR ile aynı sonucu verir.
- **Çok bitli toplayıcılar ve gecikme.** 16 bitlik ripple carry toplayıcı 16 tane tam toplayıcıdan oluşur; ilk $C_{in}$ 0'dır, en son elde taşma (overflow) sinyalidir ve kritik yol 16 tam toplayıcıdır (ekrandan, 02:00:00). İki 16 bitlik toplayıcıdan 32 bitlik toplayıcı kurarken düşük anlamlı toplayıcının $C_{out}$'u yüksek anlamlı toplayıcının $C_{in}$'ine bağlanır ve sonuç 33 bit olur. Kapıların ve tellerin gecikmesi yüzünden girişler aynı anda verilse de çıkış ancak elde en yüksek bite ulaşınca doğru olur.
- **Toplayıcı-çıkarıcı.** İkiye tümleyende $-B = \bar B + 1$ olduğu için $A - B = A + \bar B + 1$ yazılır. Kontrol ucu 1 iken çıkarma, 0 iken toplama yapılır. $+1$, kontrol ucunun $c_0$'a bağlanmasıyla gelir. $B$'nin her biti kontrol ucuyla XOR'lanır: $x \oplus 1 = \bar x$, $x \oplus 0 = x$ (ekrandan, 02:15:00).
- **Tri-state buffer ve veri yolu.** Adres yolu işlemciden çıkış yönlüdür, ama veri yoluna RAM, ROM, seri/paralel G/Ç ve zamanlayıcı gibi birçok cihaz iki yönlü bağlıdır. Adres çözümleme devresi yalnız ilgili adres aralığındaki cihazı etkinleştirir; diğer cihazlar tri-state buffer ile hattan yalıtılır. $e = 0$ iken çıkış yüksek empedanstır (Z), $e = 1$ iken $f = x$ olur (ekrandan, 02:25:00). Çıkışı ya da enable'ı aktif 0 olan dört çeşit vardır (ekrandan, 02:30:00).
- **Latch ve flip-flop.** Ardışıl devre, kombinasyonel blok ile hafıza elemanlarından oluşur ve aynı girişe farklı zamanlarda farklı çıkış verebilir. Hafızayı geri besleme sağlar. Saatli SR latch'te $Clk = 0$ iken durum değişmez; $S = R = 1$ izin verilmeyen durumdur (ekrandan, 02:35:00). D latch'te saat 1 iken D'deki her değişim çıkışa geçer (transparent latch); D flip-flop yalnız yükselen kenarda D'yi örnekler.
  - Ders sonrası not: Hoca çapraz bağlı kapı çiftini NOR kapısı gibi çözümledi (girişler 0,0 iken durum korunur, 1,1 yasak). Bu, NOR tabanlı SR latch için doğrudur. Slayttaki devre ise NAND kapılıdır; NAND tabanlı latch'te aktif 0 girişler ($\bar S, \bar R$) 1,1 iken durum korunur, 0,0 yasaktır.
- **Preset ve clear.** Aktif 0 olan preset ve clear uçları saatten bağımsız (asenkron) çalışır: preset 0 olunca $Q = 1$, clear 0 olunca $Q = 0$ olur; ikisi de 1 iken flip-flop normal çalışır (ekrandan, 02:45:00). Senkron clear için D girişi clear işaretiyle AND'lenir; clear 0 olsa da $Q$ ancak bir sonraki saat kenarında sıfırlanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
