# Ders 3 Çalışma Özeti

## Genel Konular

- Senkron ardışıl devre tasarımına dönüş: Mealy ve Moore makineleri
  - Önceki derste yapılan seri toplayıcı bir Mealy makinesiydi: çıkış hem şimdiki duruma hem girişlere bağlıydı.
  - Bu derste örnek bir Moore makinesidir: çıkış yalnız şimdiki duruma bağlıdır, durum diyagramında çıkış durumun altına yazılır.
  - Senkron demek bütün flip-flop'ların ortak bir saat işaretiyle aynı anda durum değiştirmesi demektir.
- Örnek: 1, 2, 3, 4, 1, 2, ... şeklinde sayan senkron devreyi JK flip-flop ile tasarlama
  - Dışarıdan giriş yoktur. Geçişleri saat darbesi tetikler, hangi duruma gidileceğini ise mevcut durum belirler.
  - Gereken flip-flop sayısı $\lceil \log_2(\text{durum sayısı}) \rceil$ ile bulunur. 4 durum için 2 flip-flop yeter (örnek önce 1-5 sayıcı olarak yazıldı, 3 flip-flop gerektiği için 1-4'e indirildi).
  - Durum kodları ardışık durumlar arasında tek bit değişecek biçimde seçildi: 1 → 00, 2 → 01, 3 → 11, 4 → 10 (ekrandan, 00:15:00).
  - JK ileri yönlü tanım tablosundan ters tanım (uyarma) tablosu çıkarıldı, durum tablosu doldurulup Karnaugh haritalarıyla giriş ve çıkış fonksiyonları bulundu.
- Durum kodlamanın devreye etkisi
  - Kodlardaki bitlerin yerini değiştirmek yalnız flip-flop çıkışlarının adlarını değiştirmektir, yapı değişmez.
  - Kodların tümleyenini almak, çıkışların $\bar{Q}$ uçlarından alınmasıyla karşılanır, yapı yine değişmez.
  - Kodların sırası değişirse devre yapısı değişebilir. Bu konu "durum kodlama optimizasyonu" adıyla ayrıca incelenir, ders kapsamında değildir.
- İlk durumu oluşturma: asenkron set ve reset uçları
  - JK flip-flop'ta aktif sıfır çalışan $\bar{S}$ ve $\bar{R}$ uçları vardır. $\bar{S}\bar{R}=11$ iken flip-flop normal çalışır.
  - Bu uçlarla saat darbesi beklenmeden ilk durum 1 ya da 0 yapılabilir. Buna asenkron ilk durum oluşturma denir.
- Kullanılmayan durumlar ve kendi kendini düzeltme (self-correcting)
  - 0-5 sayıcısı 3 flip-flop ister. 8 durumdan 6'sı kullanılır, 6 ve 7 don't care olur.
  - Don't care seçimi sonucunda 6 ve 7 kendi aralarında dönüyorsa devre yanlış bir ilk durumdan asıl döngüye hiç giremez. Böyle devre kendi kendini düzeltmeyen bir devredir.
  - Don't care'ler, kullanılmayan durumlar asıl döngüye dönecek biçimde düzenlenirse devre kendi kendini düzeltir.
- Asenkron (ripple) sayıcılar
  - İkili sayarken her basamak bir alttakinin yarı frekansıyla değişir. Bu yüzden bir katın çıkışı bir sonraki katın saati yapılabilir.
  - Her kat kendi içinde 0, 1, 0, 1 sayan (toggle eden) bir senkron devredir: D flip-flop'ta $D=\bar{q}$, T flip-flop'ta $T=1$, JK flip-flop'ta $J=K=1$.
  - Toggle eden flip-flop saat frekansını yarıya böler.
  - Yükselen kenar tetiklemeli katlarda bir katın $Q$ çıkışı sonrakinin saatine bağlanır ve çıkışlar $Q$'lardan alınırsa sayıcı geri sayar (7, 6, 5, ...). Çıkışlar $\bar{Q}$'lardan alınırsa ileri sayar. Düşen kenar tetiklemede durum tersinedir.
- Senkron ardışıl devre blokları
  - Paralel yüklemeli yazmaç (register): n adet D flip-flop, ortak saat. Yükselen kenarda $Q=D$, diğer zamanlarda $Q=q$.
  - Ötelemeli yazmaç (shift register): kaskat bağlı D flip-flop'lar, ortak saat. Seri gelen n bitlik veri n saat darbesinde paralel hale gelir. Kaskat bağlanarak daha uzun yazmaç yapılır.
  - Anlam sırası $Q_1Q_2Q_3Q_4$ kabul edilirse aynı yapı sağa öteler, $Q_4Q_3Q_2Q_1$ kabul edilirse sola öteler.
  - Paralel yüklemeli ötelemeli yazmaç: $\overline{\text{Shift}}/\text{Load}=0$ iken öteleme, 1 iken paralel yükleme. Her kat için $D_i = \bar{C}\,S_i + C\,D_i$; kapılarla ya da 2'ye 1 MUX'larla gerçeklenir.
  - MUX yapısı genelleştirilebilir: tümleyen yükleme, sıfırlama, birden fazla bitlik öteleme ve döndürme (rotate) aynı yapıyla yapılır.
- Yükleme ucu olan 4 bit senkron yukarı sayıcı
  - Enable = 1, Load = 0 iken her yükselen kenarda bir artar (0-15). Load = 1 iken $D$ girişlerindeki değer yüklenir. Carry çıkışı kaskat bağlamada kullanılır.
  - Load ucu, çıkış belirli bir değere gelince bir başlangıç değeri yükleyecek biçimde sürülürse sayıcı istenen aralıkta sayar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tasarımda giriş olup olmadığını önce belirlemek
  - Sayıcı örneğinde dış giriş yoktur. Geçişi saat tetikler ama 1'den 2'ye geçişle 4'ten 1'e geçişi ayıran mevcut durumdur.
- Blok gösterim notasyonu
  - Bloğun içine yazılan etiketler bloğun kendi iç fonksiyonunu, uçlara dışarıdan yazılan değerler dış dünyadan bağlanan değeri gösterir. Hoca bu notasyona uyulmasını istedi.
- Durum kodlamada sezgisel kural
  - Birbirini izleyen durumlar tek bit farkla kodlanırsa Karnaugh haritasında daha büyük gruplar kurma şansı artar.
- Kendi kendini düzeltme
  - Kullanılmayan durumlar don't care alındığında devrenin bu durumlarda sıkışıp kalıp kalmadığı mutlaka incelenmelidir. Yanlış ilk durum; elektromanyetik girişim ya da elektrik kesilmesi gibi nedenlerle oluşabilir.
- Küçük bloklardan büyük bloklar
  - Tümleyen yükleme sorusunda T flip-flop önerisine karşı hoca, amacın MUX'lu genel yapıyı kullanmak olduğunu söyledi.
- Sayıcı aralığı ayarlarken don't care kullanmak
  - 0-12 sayıcıda sayıcı 13, 14, 15'e hiç ulaşmayacağı için bu değerler don't care alınır ve $L = q_2 q_3$ yeter.

## Kısa Tekrar Notları

- Moore: çıkış = f(durum). Mealy: çıkış = f(durum, giriş).
- Flip-flop sayısı = $\lceil \log_2 N \rceil$.
- JK ters tanım tablosu: $0\to0$: $J=0, K=x$; $0\to1$: $J=1, K=x$; $1\to0$: $J=x, K=1$; $1\to1$: $J=x, K=0$.
- 1-2-3-4 sayıcı (kodlar 00, 01, 11, 10): $J_1=q_2$, $K_1=\bar{q}_2$, $J_2=\bar{q}_1$, $K_2=q_1$; $Z_1=q_1\bar{q}_2$, $Z_2=q_2$, $Z_3=\overline{q_1\oplus q_2}$.
- Bit yer değiştirme ya da tümleyen alma devre yapısını değiştirmez; sıralama değişikliği değiştirebilir.
- $\bar{S}$, $\bar{R}$ aktif sıfır; saatten bağımsız (asenkron) ilk durum verir.
- Kullanılmayan durumlar kendi aralarında dönüyorsa devre kendi kendini düzeltmez.
- Toggle: D'de $D=\bar{q}$, T'de $T=1$, JK'da $J=K=1$. Toggle eden flip-flop frekansı ikiye böler.
- Ripple sayıcı: yükselen kenar + $Q$ çıkış → geri sayıcı; yükselen kenar + $\bar{Q}$ çıkış → ileri sayıcı; düşen kenarda tersi.
- Paralel yüklemeli yazmaç: $Q^+ = D$ (yükselen kenarda).
- Shift register: n bit seri veri n saat darbesinde yüklenir; sağa öteleme $Q^+ = S_{in}\,q_1q_2q_3$.
- Paralel yüklemeli shift register: $D_i=\bar{C}S_i + C D_i$; 2 fonksiyon → 2'ye 1 MUX, 4 fonksiyon → 4'e 1 MUX.
- 4 bit sayıcı: 0-10 için $L=\bar{q}_0 q_1 \bar{q}_2 q_3$, $D=0000$; 0-12 için $L=q_2q_3$; 5-12 için $L=q_2q_3$, $D_3D_2D_1D_0=0101$.

## Detaylı Açıklamalar

- **Moore makinesi ile 1-2-3-4 sayıcı.** Devrenin dış girişi yoktur, durum diyagramındaki oklar etiketsizdir. Dört durum 1 → 00, 2 → 01, 3 → 11, 4 → 10 diye kodlanır. Durum tablosu (ekrandan, 00:30:00):

  | $q_1q_2$ | $Q_1Q_2$ | $J_1K_1$ | $J_2K_2$ | $Z_1Z_2Z_3$ |
  |---|---|---|---|---|
  | 00 | 01 | 0x | 1x | 001 |
  | 01 | 11 | 1x | x0 | 010 |
  | 10 | 00 | x1 | 0x | 100 |
  | 11 | 10 | x0 | x1 | 011 |

  Çıkış 1'den 4'e kadar ikili gösterildiği için 3 bit gerekir. Karnaugh haritalarından $J_1=q_2$, $K_1=\bar{q}_2$, $J_2=\bar{q}_1$, $K_2=q_1$, $Z_1=q_1\bar{q}_2$, $Z_2=q_2$, $Z_3=\bar{q}_1\bar{q}_2+q_1q_2$ (XNOR) bulunur (ekrandan, 00:35:00). İki flip-flop'un saatleri ortak bağlanır. 00 ilk durumundan başlayan devre 1, 2, 3, 4, 1, ... sayar; başka bir durumdan başlarsa döngü aynıdır, yalnız başlangıç değeri farklı olur. Bu yüzden ilk durum set/reset uçlarıyla verilir. Tasarım python ile simüle edildi, çıkış dizisi 1, 2, 3, 4, 1, 2 çıktı.
- **Durum kodlama.** 00, 01, 10, 11 yerine 00, 10, 01, 11 (bitlerin yeri değişmiş) kullanılırsa yalnız $q_1$ ve $q_2$ adları yer değiştirir. 11, 10, 01, 00 (tümleyen) kullanılırsa aynı devrede durum değişkenleri $\bar{Q}$ uçlarından alınır. Her iki durumda devrenin ana yapısı değişmez.
- **Kendi kendini düzeltme.** 0-5 sayıcıda 6 ve 7 kodlanmamış durumlardır. Don't care'ler 1 ya da 0 seçilirken 6 → 7 → 6 gibi bir döngü oluşabilir (ekrandan, 00:45:00). Devre bu durumlardan birinde başlarsa asıl aralığa hiç dönmez. Don't care'ler 6 ve 7'yi asıl döngüdeki bir duruma götürecek biçimde seçilirse devre kendi kendini düzeltir.
- **Asenkron sayıcı.** Sayma tablosunda en düşük basamak her sayımda, bir üstteki iki sayımda bir, sonraki dört sayımda bir değişir. $D=\bar{q}$ bağlı D flip-flop her yükselen kenarda durum değiştirir ve çıkış frekansı saatin yarısıdır. Üç kat kaskat bağlanır: her katın saati bir öncekinin $Q$ çıkışıdır. 000'dan başlayan zaman diyagramında sayma 111, 110, 101, 100, 011, 010, 001, 000 olarak çıkar, yani geri sayar (ekrandan, 01:10:00). İleri saydırmak için çıkışlar $\bar{Q}$'lardan alınır ya da düşen kenar tetiklemeli flip-flop kullanılıp çıkışlar $Q$'lardan alınır. Bu sonuçlar python simülasyonuyla doğrulandı.
- **Yazmaçlar.** 4 bitlik paralel yüklemeli yazmaç dört D flip-flop'tur (ekrandan, 01:35:00); ALU giriş ve sonuçlarını saklamak için kullanılır. Shift register'da seri girişe LSB önce gelirse n darbe sonra LSB sondaki, MSB baştaki flip-flop'ta olur. Slayttaki örnekte $S_{in}$ dizisi 1, 0, 1, 1, 1, 0, 0, 0 iken $Q_1Q_2Q_3Q_4$ değerleri 0000, 1000, 0100, 1010, 1101, 1110, 0111, 0011 olur (ekrandan, 01:40:00). İki 8 bitlik shift register, birincinin çıkışı ikincinin seri girişine bağlanarak 16 bitlik veri tutar.
- **Paralel yüklemeli ötelemeli yazmaç.** Fonksiyon tablosu (ekrandan, 01:50:00): $\overline{S}/L=0$, $S_{in}=0$ → $0\,q_3q_2q_1$; $\overline{S}/L=0$, $S_{in}=1$ → $1\,q_3q_2q_1$; $\overline{S}/L=1$ → $D_3D_2D_1D_0$ yüklenir. MUX'lu tasarımda her D flip-flop'un önünde 2'ye 1 MUX vardır. Seçim uçları ortak bağlanıp $\overline{S}/L$'ye gider. 1 girişlerine $D_3..D_0$, 0 girişlerine en üst katta $S_{in}$, diğerlerinde bir üst katın $Q$ çıkışı bağlanır.
- **Yüklemeli sayıcı ile aralık ayarlama.** Çıkış 10 (1010) olduğunda $L=1$ yapılırsa sonraki yükselen kenarda $D=0000$ yüklenir ve sayıcı 0-10 arasında döner (ekrandan, 02:20:00). 5-12 için $D=0101$ ve $L=q_2q_3$ kullanılır. Sayıcı 0'dan başlarsa ilk turda 0-4 değerleri de görülür, sonra 5-12 arasında döner. Bu diziler python simülasyonuyla doğrulandı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
