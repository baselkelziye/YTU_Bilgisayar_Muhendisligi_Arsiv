# Ders 28 Çalışma Özeti

## Genel Konular

- Dersin amacı ve kapsamı
  - Dönemin son konusu üç başlıktır: saklayıcılar (register), sayıcılar (counter) ve bellek (hafıza) elemanları (ekrandan, 00:15:00).
  - Bu konu, lojik devreler ile mikroişlemci dersi arasında köprü kurar. Mikroişlemci dersinde flip-flopun iç yapısı yeniden anlatılmaz; flip-flopların bir araya gelerek oluşturduğu saklayıcılar ve bellek blokları doğrudan kullanılır.
- Saklayıcılar (register)
  - $n$ bitlik bir saklayıcı, ortak saat (CLK) girişine bağlı $n$ tane flip-flopun yan yana getirilmesidir. Bir flip-flop bir bit sakladığı için 8 bitlik saklayıcıda 8, 16 bitlikte 16 flip-flop bulunur.
  - Dört türü vardır: PIPO (paralel giriş, paralel çıkış), SIPO (seri giriş, paralel çıkış), PISO (paralel giriş, seri çıkış), SISO (seri giriş, seri çıkış) (ekrandan, 00:20:00).
  - 4 bitlik PIPO saklayıcıda girişler $G_3G_2G_1G_0$, çıkışlar $\text{Ç}_3\text{Ç}_2\text{Ç}_1\text{Ç}_0$'dır. Örneğin $1001$ girişi bir saat darbesiyle çıkışa aktarılır ve bir sonraki darbeye kadar korunur. Bu iş için D tipi flip-flop kullanılır (ekrandan, 00:20:00).
  - Seri girişli yapıda flip-floplar zincir gibi bağlanır; her saat darbesinde bit bir sonraki flip-floba geçer. Yalnız son flip-floptan okunursa SISO, her flip-floptan ayrı çıkış alınırsa SIPO olur (ekrandan, 00:25:00).
  - Bütün türleri bir arada barındıran saklayıcılara evrensel (universal) saklayıcı denir; az kullanılır.
- Saklayıcı üzerindeki işlemler
  - Saklayıcı ALU'nun yaptığı aritmetik/lojik işlemleri yapmaz. Kendi yapısıyla üç iş yapabilir: set (tüm bitleri 1), reset (tüm bitleri 0) ve öteleme/döndürme (ekrandan, 00:25:00).
  - Set ve reset, flip-flopların ayrı set/sıfırla pinlerinden verilir.
  - Öteleme ve döndürme seri girişli (SISO, SIPO) yapılarla yapılır.
- Öteleme ve döndürme
  - Ötelemede boşalan uca 0 girer, dışarı çıkan bit kaybolur. Döndürmede dışarı çıkan bit öbür uçtan geri girer.
  - $n$ bit sağa öteleme sayıyı $2^n$'e (tam sayı) bölmek, $n$ bit sola öteleme $2^n$ ile çarpmak demektir (ekrandan, 00:40:00).
  - Örnek: $1100\,0101 = 197$; 1 bit sağa öteleme $0110\,0010 = 98$; 1 bit sağa döndürme $1110\,0010$ (ekrandan, 00:40:00).
  - Mikroişlemci 2, 4, 8 ile bölme/çarpmayı ALU'ya gitmeden saklayıcı içinde hızlıca bu yolla yapar.
- Seri ve paralel aktarım karşılaştırması
  - Paralel aktarım daha kısa sürede daha çok veri taşır, ama gürültüden daha çok etkilenir ve mimarisi daha pahalıdır.
  - Seri aktarım daha yavaştır (paket tamamlanana kadar beklenir), ama ucuzdur, uzak mesafeye gönderilebilir ve gürültüden az etkilenir.
  - Mikroişlemci saklayıcılarında genelde PIPO kullanılır.
- Sayıcılar ve sınıflandırılması (ekrandan, 00:45:00)
  - Bit sayısına göre: 4 bitlik sayıcı $0000$-$1111$, 8 bitlik sayıcı 0-255 arasında sayar. Kapasiteyi belirlediği için en kritik parametredir.
  - Sayma sırasına göre: yukarı sayan ve aşağı sayan.
  - Çalışma moduna göre: hem yukarı hem aşağı sayabilen iki modlu ve tek modlu.
  - Durum sayısına göre: modülo sayıcılar (örneğin mod 3 sayıcı 0, 1, 2 sayıp 0'a döner).
  - Geçiş fonksiyonuna göre: senkron ve asenkron.
  - Sayıcı bloğunun girişleri: yüklenen $n$ bitlik başlangıç değeri ve CLK; çıkışları: o anki değer ($n$ bit) ve "sayma tamam" sinyali.
- Ardışık bağlı (kaskat) aşağı sayıcılar
  - Mikroişlemcilerde genelde aşağı sayıcılar kullanılır: yüklenen değerden 0'a kadar sayılır, 0'a gelince "sayma tamam" mikroişlemciyi tetikler.
  - Birinci sayıcının "sayma tamam" çıkışı ikinci sayıcının saatine bağlanırsa, tek sayıcının kapasitesinin yetmediği uzun sayımlar yapılabilir (ekrandan, 00:50:00).
- Özel durum sayıcıları (ekrandan, 01:00:00)
  - İkili (binary) sayıcı: 4 bitle 0-15.
  - BCD sayıcı: 0-9 sayar, 9'dan sonra başa döner.
  - Gray kodu sayıcı: her adımda yalnız bir bit değişir (Hamming uzaklığı 1). Sıra: $0000, 0001, 0011, 0010, 0110, 0111, 0101, 0100, \dots$
  - Modülo 12 sayıcı: 0-11 sayar, sonra 0'a döner.
  - 3 fazlalık sayıcı da bu gruptadır.
- İkili sayıcı ile BCD sayıcı farkı
  - İkili sayıcı aynı aralığı daha az bitle sayar: 99 ikili sistemde $110\,0011$ (7 bit), BCD'de $1001\,1001$ (8 bit) (ekrandan, 01:05:00).
  - BCD sayıcı bazı bit kombinasyonlarını kullanmadığı için bit israfı vardır; ama ondalık değer hiçbir dönüşüm yapmadan, basamak basamak yüklenebilir. İkili sayıcıya ondalık değer yüklemek için bir dönüştürme (devresi) gerekir.
- Hafıza birimleri: RAM, ROM, PROM, EPROM, E²PROM (ekrandan, 01:25:00)
  - Hafıza birimi, her biri tekil (unique) bir adrese sahip hafıza hücrelerinden (bloklarından) oluşur.
  - Gösterim "satır sayısı × sözcük genişliği"dir: 8 satır, 8 bitlik sözcük → $8 \times 8$ bit $= 64$ bit $= 8$ bayt.
  - 1 MB, 16 bitlik sözcük: $512\text{K} \times 16$ bit $= 2^{19} \times 16$ bit; satırları seçmek için 19 adres hattı ($A_0$-$A_{18}$) gerekir (ekrandan, 01:35:00).
- Kod çözücü (decoder) ile adresleme
  - Adres yolundaki bitler kod çözücüye girer; kod çözücü yalnız bir çıkışı etkin yaptığı için yalnız seçilen satır ortak veri yoluna bağlanır. 3x8 kod çözücü 8 satırı, 19 girişli kod çözücü $2^{19}$ satırı seçer.
  - 2x4 kod çözücü ve 12 flip-floptan oluşan 4 satır × 3 bitlik örnek hafıza: adres $A_1A_0 = 01$ gönderilip read sinyali verilince yalnız 01 satırının 3 flip-flopu $D_2D_1D_0$ veri yoluna aktarılır (ekrandan, 01:45:00).
- Veri yolu ve adres yolu
  - Veri yolu genişliği, hafıza bloğunun tek seferde tutabileceği en fazla bit sayısıdır ve mikroişlemcinin saklayıcı genişliğiyle ilişkilidir (16 bitlik saklayıcı için 16 veri hattı).
  - Adres yolu genişliği, mikroişlemcinin seçebileceği satır sayısını belirler. 32 bitlik adresleme en çok 4 GB'ı görebilir; bu yüzden 64 bitlik sistemlere geçilmiştir.
- Statik ve dinamik RAM, ROM türleri (ekrandan, 01:50:00)
  - Statik RAM her biti bir flip-flopta tutar; çok hızlıdır ama çok yer kaplar ve pahalıdır. En önemli örneği işlemcinin içindeki cache bellektir.
  - Dinamik RAM her biti kondansatör + transistörle (şarj/deşarj) tutar; daha yavaştır ama daha yoğun ve ucuzdur. Ana bellek (main memory) böyledir.
  - İşlemci önce cache belleğe bakar, bulamazsa ana belleğe gider.
  - ROM fabrikadan yazılı gelir, değiştirilemez. PROM, EPROM, E²PROM ve flash ROM programlanabilen/silinebilen sürümlerdir; güncel BIOS'lar bu yolla üretilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Saklayıcının bit sayısı = içindeki flip-flop sayısı
  - Bir flip-flop tek bir bit (0 ya da 1) saklar. 8086'nın "16 bitlik" denmesinin nedeni AX, BX, CX, DX saklayıcılarının 16 bitlik, yani 16 flip-floplu olmasıdır.
- Saklayıcı işlemleri ALU işlemi değildir
  - Set, reset, öteleme ve döndürme saklayıcının kendi yapısıyla yapılır; bu yüzden çok hızlıdır.
- Öteleme ile döndürme farkı
  - Öteleme bölme/çarpma anlamına gelir; döndürmede bit kaybolmaz ama sonuç ilgisiz bir değer olur.
- Sayıcının bit sayısı kapasiteyi belirler
  - 4 bitlik ve 8 bitlik sayıcının alabileceği en büyük değeri bilmek gerekir.
- Hafıza bloğu yapısını iyi anlamak
  - Satır sayısı adres yolunu, satır genişliği veri yolunu belirler; bu yapı mikroişlemci dersinde sıkça karşınıza çıkacak.
  - Bu haftanın konusunda ayrıntılı devre çiziminden çok temel kavramlar ve tanımlar önemlidir.

## Kısa Tekrar Notları

- $n$ bitlik saklayıcı = $n$ flip-flop, ortak CLK; veri saklamak için D tipi flip-flop.
- Türler: PIPO, SIPO, PISO, SISO. Mikroişlemci saklayıcıları PIPO; öteleme için SISO/SIPO.
- Saklayıcı işlemleri: set, reset, öteleme/döndürme.
- $n$ bit sağa öteleme: $\lfloor x / 2^n \rfloor$; $n$ bit sola öteleme: $x \cdot 2^n$ (taşma olmazsa).
- Döndürmede çıkan bit diğer uçtan girer.
- $n$ bitlik ikili sayıcı $0$ ile $2^n - 1$ arasında sayar (8 bit: 0-255).
- Mod $m$ sayıcı $0$ ile $m-1$ arasında sayar.
- Gray kodu: ardışık değerler arasında yalnız 1 bit farkı.
- BCD sayıcı 0-9; ondalık değer doğrudan yüklenir ama bit israfı vardır.
- Kaskat sayıcılar: ilk sayıcının "sayma tamam" çıkışı ikincinin saatine bağlanır; toplam sayım uzunlukların çarpımıdır.
- Hafıza: satır × sözcük. $2^k$ satır için $k$ adres hattı gerekir.
- 1 MB ve 16 bitlik sözcük → $2^{19}$ satır → 19 adres hattı.
- SRAM = flip-flop, hızlı, cache; DRAM = kondansatör + transistör, yavaş, ucuz, ana bellek.

## Detaylı Açıklamalar

- **Saklayıcılar ve D flip-flop.** Durum diyagramlarında "durumu tutan" yapı olarak kullanılan flip-floplar yan yana dizilip ortak bir saat sinyaline bağlanınca saklayıcı oluşur. 4 bitlik PIPO saklayıcıda $G_3G_2G_1G_0$ girişlerine $1001$ verilip bir saat darbesi beklendiğinde değer $\text{Ç}_3\text{Ç}_2\text{Ç}_1\text{Ç}_0$ çıkışlarına geçer. Bir sonraki darbeye kadar girişteki değişim çıkışa yansımadığından veri saklanmış olur. Amaç veriyi olduğu gibi tutmak olduğu için D (data) tipi flip-flop seçilir. Mikroişlemcide saat yerine okuma/yazma sinyalleri vardır: yazmada $G$'ler yeni veriyi, okumada $\text{Ç}$'ler saklanan veriyi gösterir.
- **Seri giriş ve öteleme.** Seri girişli yapıda birinci flip-flopun çıkışı ikincinin girişine bağlanır ve bu böyle sürer. Seri girişten gönderilen her bit her saat darbesinde bir sonraki flip-floba ilerler; 4 bitlik bir paket ancak 4 saat darbesinden sonra tamamlanır, arada okunan değer anlamsızdır. Ara düğümlerden çıkış alınırsa yapı SIPO, yalnız son flip-floptan alınırsa SISO olur. Tek flip-flopla da seri giriş/seri çıkış yapılabilir, ama $n$ bitlik bir paket içinde öteleme yapmak için $n$ flip-flop gerekir. <!-- BELİRSİZ: Hocanın seri çıkışta bitlerin hangi sırayla (LSB önce) göründüğüne dair anlatımı altyazıda karışık. -->
- **Öteleme ile bölme ve çarpma.** $0100 = 4$ bir bit sağa ötelenince $0010 = 2$, bir bit daha ötelenince $0001 = 1$ olur. $1000 = 8$ iki bit sağa ötelenince $0010 = 2$ olur. Buradan $n$ bit sağa ötelemenin $2^n$'e bölmek olduğu çıkar. $1100\,0101 = 197$ bir bit sağa ötelenince en sağdaki 1 düşer ve $0110\,0010 = 98$ elde edilir; bu $197/2$'nin tam kısmıdır. Sola ötelemede ise $0001 = 1$ iki bit sola ötelenince $0100 = 4$, iki bit daha ötelenince $1\,0000 = 16$ olur, yani $2^2 = 4$ ile çarpılır.
- **Döndürme.** $1100\,0101$ bir bit sağa döndürülünce dışarı çıkan 1 en sola gelir: $1110\,0010$. Sonuç sayının yarısıyla ilgisizdir.
  - Ders sonrası not: Hoca tahtada $128+64+32+2 = 230$ yazdı; doğrusu $226$'dır (python ile kontrol edildi).
- **Kaskat aşağı sayıcılar.** İki tane 4 bitlik aşağı sayıcı düşünülür. Üstteki sayıcıya $1111$ yüklenir; her saat darbesinde $1110, 1101, \dots, 0000$ diye iner ve 0'a gelince "sayma tamam" çıkışı alttaki sayıcının saat girişini tetikler. Alttaki sayıcıya $1000$ yüklenmişse her 16 adımda bir azalır: $1000 \to 0111 \to 0110 \to 0101 \to 0100 \dots$ Alttaki sayıcının "sayma tamam" çıkışı $16 \times 8 = 128$ sayımdan sonra 1 olur; 4 bitlik tek bir sayıcı bu kadar sayamaz (ekrandan, 00:50:00). Modülo 7 bir aşağı sayıcıya ise en çok $0110 = 6$ yüklenebilir.
- **BCD ile ikili sayıcı seçimi.** Kitaptaki soru: ikili sayıcı ile BCD sayıcı arasındaki fark nedir, uygulamaya göre hangisi seçilir? 99'dan geriye sayan bir sayıcı için ikili sayıcıya $110\,0011$ (7 bit) yüklenir; BCD sayıcıya her basamağın ikili karşılığı yan yana yazılarak $1001\,1001$ (8 bit) yüklenir. İkili sayıcı bitleri verimli kullanır; BCD sayıcı biraz israflıdır ama ondalık girişi dönüşümsüz kabul eder. Örneğin 72 ikiliye çevrilirken $72 - 64 = 8$, $8 - 8 = 0$ diye $2^6$ ve $2^3$ bitleri 1 yapılır ($100\,1000$); BCD'de ise doğrudan $0111\,0010$ yazılır.
- **Hafıza birimi ve adresleme.** Her hücrenin tekil adresi vardır ve bütün hücreler aynı bit genişliğindedir. Kaç satır olduğu adres hattı sayısını belirler: $512\text{K} = 2^9 \cdot 2^{10} = 2^{19}$ satır için adres $000\dots0$'dan 19 tane 1'e kadar gider. Bütün hücreler arka planda ortak veri yoluna bağlı olduğu için yalnız seçilen satırın veri yoluna çıkması gerekir; bunu kod çözücü sağlar, çünkü her seferinde yalnız bir çıkışını etkin yapar. 4 satır × 3 bitlik örnekte mikroişlemci $A_1A_0 = 01$ gönderip read sinyali verdiğinde yalnız 01 satırının üç flip-flopu $D_2, D_1, D_0$ hatlarına bağlanır.
- **Statik ve dinamik RAM.** Statik RAM'de bit, kapı gecikmelerinin geri beslemesiyle veriyi tutan flip-flopta saklanır; hızlıdır ama 1 GB gibi büyük kapasitelerde bu kadar flip-flop kurmak zordur. Dinamik RAM'de bit, kondansatörün şarjlı ya da boş olmasıyla tutulur; daha küçük alanda daha çok veri saklanır ve maliyet düşüktür, ama hız düşüktür. Bu yüzden küçük ve hızlı cache bellekler statik, ana bellek dinamiktir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
