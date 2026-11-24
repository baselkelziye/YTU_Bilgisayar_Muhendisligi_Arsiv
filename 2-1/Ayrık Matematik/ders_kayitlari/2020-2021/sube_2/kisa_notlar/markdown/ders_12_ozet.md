# Ders 12 Çalışma Özeti

## Genel Konular

- Graf gösterimleri tekrarı
  - Geliş (incidence) matrisi: satırlarda köşeler ($V_1,\dots,V_4$), sütunlarda kenarlar ($E_1,\dots,E_5$) bulunur; köşe o kenarın ucuysa 1, değilse 0 yazılır. Komşuluk matrisiyle karıştırılmamalıdır.
  - Komşuluk matrisi $A$ için $A^2$ iki adımda, $A^3$ üç adımda gidilebilecek köşe çiftlerini gösterir.
- Euler yolu ve Euler döngüsü (ekrandan, 00:25:00)
  - Bütün düğüm dereceleri çift ise graf Euler grafıdır; bu durumda hem Euler yolu hem Euler döngüsü vardır.
  - Tek dereceli düğüm sayısı 2 ya da 0 ise Euler yolu vardır.
  - Euler yolu: bütün kenarlardan birer kez geçilerek bütün düğümler gezilir; başlangıca dönme şartı yoktur.
  - Euler döngüsü (cycle): bütün kenarlardan birer kez geçilerek başlangıç düğümüne geri dönülür.
  - Örnek: kenarları $1$–$2$, $2$–$3$, $3$–$4$, $4$–$2$ olan grafta dereceler $1,3,2,2$; iki tek dereceli düğüm olduğu için Euler yolu $1\to2\to3\to4\to2$ vardır, döngü yoktur. Kare ($1$–$2$–$3$–$4$–$1$) grafında bütün dereceler 2 olduğu için Euler döngüsü vardır.
- Dijkstra en kısa yol algoritması tekrarı (ekrandan, 00:30:00)
  - Her adımda en küçük maliyetli ziyaret edilmemiş düğüm seçilir, komşularının maliyetleri daha küçükse güncellenir.
  - Her düğümde yalnız bir önceki düğüm saklanırsa yol sondan geriye izlenerek (backtrace) bulunur.
  - Slayt örneğinde $a$'dan $f$'ye en kısa yol $a\to b\to e\to d\to f$, maliyeti 7'dir.
- Düzlemsel (planar) graf ve Euler formülü
  - Kenarları birbirini kesmeyecek şekilde çizilebilen graf düzlemseldir. Bağlı düzlemsel grafta $v-e+f=2$ ($v$ düğüm, $e$ kenar, $f$ yüz sayısı).
- Graf izomorfizmi
  - Şartlar: düğüm sayıları, kenar sayıları ve düğüm dereceleri aynı olmalı; komşuluk matrisleri aynı ya da satır-sütun yer değiştirmeleriyle birbirine dönüşebilir olmalı.
- Özel tip graflar ve ağ topolojileri (ekrandan, 00:35:00)
  - Yıldız topoloji: bütün cihazlar merkezdeki cihaz (hub/switch) üzerinden haberleşir; $K_{1,n}$ tam iki parçalı graf ile gösterilir.
  - Halka topoloji: her cihaz yalnız bir öncekini ve bir sonrakini bilir ($C_n$).
  - Yıldız ve halkanın birleşimi tekerlek grafıdır ($W_n$).
- Graf boyama (ekrandan, 00:40:00)
  - Düğüm boyama: komşu iki düğüm aynı renge boyanamaz. Kenar boyama: ortak düğümü olan iki kenar aynı renge boyanamaz. Derste düğüm boyamaya odaklanıldı.
  - Graf boyama üstel zamanda çözülebilen, zor bir problemdir.
  - Kromatik sayı $\chi(G)$: grafı boyamak için gereken en az renk sayısı.
- Kromatik polinom $P(G,x)$
  - $x$ renk varken grafın kaç farklı şekilde boyanabileceğini verir. $P(G,k)>0$ yapan en küçük $k$ kromatik sayıdır; $P(G,\chi(G))$ en az renkle farklı boyama sayısıdır.
  - Bilinen graflar (ekrandan, 00:55:00): noktasal graf $x$; çizgisel graf $x(x-1)$; $n$ düğümlü U grafı (yol) $x(x-1)^{n-1}$; tam graf $K_n=\prod_{k=0}^{n-1}(x-k)$; 4 yapraklı yıldız $x(x-1)^4$; iki parçalı graf 2 renkle boyanır.
- Kenar silme ve birleştirme (deletion-contraction) yöntemi
  - $P(G,x)=P(G-e,x)-P(G/e,x)$. $G-e$: $e$ kenarı silinmiş graf; $G/e$: $e$'nin uçları tek düğümde birleştirilmiş graf.
- Ortak nokta yöntemi (ekrandan, 01:10:00)
  - Graf, noktasal ya da çizgisel bir ortak parça ile iki grafa ayrılabiliyorsa $P(G)=\dfrac{P(G_1)\,P(G_2)}{P(G_1\cap G_2)}$.
- Kromatik polinom özellikleri (ekrandan, 01:00:00)
  - $P(x)=a_0x^n-a_1x^{n-1}+a_2x^{n-2}-\dots$ biçimindedir.
- Polinom çarpımı katsayı konvolüsyonuyla yapılabilir (ekrandan, 01:15:00).
- Harita boyama problemi: komşu bölgeler farklı renk olacak şekilde haritalar en fazla dört renkle boyanabilir.
- BFS ve DFS farkı: BFS kuyruk, DFS yığın kullanır; BFS komşulara katman katman yayılır.
- Öğrenci sorusu üzerine kısa kriptografi girişi (ekrandan, 01:30:00): Sezar, afin şifreleme ve RSA.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dijkstra algoritması çalışılmalı
  - Soruda yalnız en kısa yolu çizip bırakmak çözüm sayılmaz; her adımdaki maliyet ve önceki düğüm bilgisini içeren tablo doldurulmalıdır.
- Euler yolu/döngüsü şartı ve dereceler
  - Dereceler sayılarak doğrudan karar verilir: hepsi çift ise döngü (ve yol), tam iki tek dereceli düğüm varsa yalnız yol.
- Kromatik polinomu deletion-contraction ve ortak nokta yöntemleriyle bulma
  - Soruda yöntem belirtilirse o yöntem kullanılmalıdır; doğrudan permütasyon mantığıyla ($x$, $x-1$, ...) yazmak yalnız sağlama içindir.
  - Bu yöntemlerle ilgili farklı ama aşırı karmaşık olmayan örnekler çözülmesi tavsiye edildi.
- Kromatik polinomu kontrol etme
  - Bulunan polinomun özellikleri (baş katsayı 1, derece = düğüm sayısı, ikinci katsayının mutlak değeri = kenar sayısı, işaretler $+,-,+,-$, $P(0)=P(1)=0$) kontrol edilerek hata yakalanabilir.
- BFS/DFS sırasında kuyruğun ya da yığının içeriği
  - Belirli bir adımda kuyruktan hangi düğümün çekildiği gibi sorular test türü sınavlara uygundur.

## Kısa Tekrar Notları

- Euler döngüsü: bütün dereceler çift. Euler yolu: 0 ya da 2 tek dereceli düğüm.
- Dijkstra: en küçük maliyetli düğümü seç, komşuları güncelle, önceki düğümü sakla, sonunda geriye izle.
- Düzlemsel graf: $v-e+f=2$.
- İzomorfizm: düğüm sayısı, kenar sayısı, derece dizisi aynı; komşuluk matrisi permütasyonla eşlenir.
- Yıldız $K_{1,n}$, halka $C_n$, tekerlek $W_n$.
- $\chi(G)$: en az renk sayısı. $\chi(K_4)=4$; 4 köşeli kare ve merkezden oluşan tekerlek için 3; altıgen tekerlek için 3.
- $P(K_n,x)=x(x-1)\cdots(x-n+1)$; yol: $x(x-1)^{n-1}$; nokta: $x$.
- $P(G)=P(G-e)-P(G/e)$.
- Ortak nokta: $P(G)=P(G_1)P(G_2)/P(\text{ortak})$; ortak nokta için bölen $x$, ortak kenar için $x(x-1)$.
- $P(K_4,x)=x^4-6x^3+11x^2-6x$, $P(K_4,4)=24$.
- Elmas graf ($K_4$'ten bir kenar eksik): $x^4-5x^3+8x^2-4x$, en az 3 renk, 6 boyama.
- Sınav çizelgeleme: dersler düğüm, ortak öğrencisi olan dersler arasında kenar, renkler sınav saatleri.
- BFS → kuyruk, DFS → yığın.

## Detaylı Açıklamalar

- **Euler yolu ve döngüsü.** Hoca tahtaya şu kuralları yazdı (ekrandan, 00:25:00): "Bütün düğüm dereceleri çift olursa Euler graf; bu durumda Euler yolu ve Euler döngüsü de vardır. 2 veya 0 sayıda tek dereceli düğüm varsa Euler yolu vardır." Euler yolunda her kenardan tam bir kez geçilir ve bütün düğümler gezilir; başlangıca dönmek gerekmez. Euler döngüsünde ise ayrıca başlangıç düğümüne dönülür. Kenarları $1$–$2$, $2$–$3$, $3$–$4$, $4$–$2$ olan grafta dereceler $d(1)=1$, $d(2)=3$, $d(3)=2$, $d(4)=2$'dir; iki tek dereceli düğüm vardır, $1\to2\to3\to4\to2$ Euler yoludur. 4'ten 1'e kenar olmadığı için döngü kurulamaz. Kare grafta ise $1\to2\to3\to4\to1$ Euler döngüsüdür. Önceki dersteki bir grafta dereceler $2,4,3,3$ çıktığı için Euler yolu var, döngü yoktur.
  > **Ders sonrası not:** Hoca Euler döngülerinin sayısının, her düğüm derecesinden 1 çıkarılıp faktöriyelleri çarpılarak bulunduğunu söyledi. Bu çarpım, büyük olasılıkla BEST teoreminin bir parçasıdır; teorem yönlü graflar içindir ve bu çarpım ayrıca kapsayan ağaç (arborescence) sayısıyla çarpılır. Formül bu haliyle genel bir sayım kuralı olarak kullanılmamalıdır.
- **Dijkstra tekrarı.** Slayttaki grafın kenarları (ekrandan, 00:30:00): $a$–$b$=2, $a$–$c$=3, $b$–$d$=5, $b$–$e$=2, $c$–$e$=5, $d$–$e$=1, $d$–$f$=2, $e$–$f$=4. Tablo adım adım ($M$ = henüz bilinmiyor/sonsuz):

  ```text
       a    b    c    d     e     f
  1.   0    M    M    M     M     M      a seçildi
  2.   -    2a   3a   M     M     M      b seçildi
  3.   -    -    3a   7ab   4ab   M      c seçildi
  4.   -    -    -    7ab   4ab   M      (c üzerinden e = 8ac > 4ab, güncellenmez) e seçildi
  5.   -    -    -    5abe  -     8abe   d seçildi
  6.   -    -    -    -     -     7abed  f
  ```

  Sonuç: en kısa yol $a\to b\to e\to d\to f$, maliyet $2+2+1+2=7$. Her hücrede yolun tamamı yerine yalnız son düğüm (örneğin $7d$, $5e$) tutulup geriye doğru izlenerek de yol bulunabilir.
- **Düzlemsel graf ve izomorfizm.** Kenarları kesişmeden çizilebilen graf düzlemseldir ve $v-e+f=2$ sağlanır. İzomorfizm kontrolünde önce kolay şartlar (düğüm, kenar sayısı, derece dizisi) bakılır; biri tutmazsa graflar izomorfik değildir. Slayttaki örnekte iki grafın 4 düğümü, 4 kenarı vardır, bütün dereceler 2'dir; komşuluk matrislerinde $u_2$ ve $u_4$ satır-sütunları yer değiştirince matrisler eşleşir, graflar izomorfiktir. Büyük graflarda bu kontrol algoritmayla yapılır.
- **Ağ topolojileri.** Yerel ağlarda (LAN) yıldız topolojide bütün cihazlar merkezdeki cihaz üzerinden bağlanır; bu $K_{1,n}$ tam iki parçalı graftır, uçtaki iki bilgisayar doğrudan bağlı değildir. Halka topolojide her cihaz komşu iki cihazı bilir. İkisinin birleşimi tekerlek grafı $W_n$'dir.
- **Graf boyama ve permütasyon benzetmesi.** Rakamları birbirinden farklı dört basamaklı sayı sayısı $10\cdot9\cdot8\cdot7=P(10,4)$ iken yalnız yan yana rakamların farklı olması istenirse $10\cdot9\cdot9\cdot9$ olur (ekrandan, 00:40:00). İkinci durum 4 düğümlü bir yol grafının boyanmasıdır: $x$ renkle $x(x-1)(x-1)(x-1)$. Bu polinomda $P(0)=P(1)=0$, $P(2)=2$ olduğu için graf en az 2 renkle, 2 farklı şekilde boyanır (kırmızı-sarı-kırmızı-sarı ya da tersi).
  - Slayttaki bir üçgen ve ona bağlı bir uç düğümden oluşan grafta polinom $x(x-1)^2(x-2)$'dir; $P(3)=3\cdot4\cdot1=12$. Slayttaki 12 farklı boyama bu sayıyla örtüşür (ekrandan, 00:40:00).
- **Kromatik sayı örnekleri** (ekrandan, 00:45:00 ve 00:50:00): $K_4$'te her düğüm diğer üçünü gördüğü için $x(x-1)(x-2)(x-3)$, $\chi=4$. Kareye bir merkez düğüm eklenip merkez dört köşeye bağlanınca karşılıklı köşeler aynı renk alabilir, $\chi=3$ (slaytta önce 4 yazıyordu, hoca derste 3 olarak düzeltti). Altıgen tekerlekte de $\chi=3$.
- **Sınav çizelgeleme uygulaması.** Dersler düğüm, ortak öğrencisi olan iki ders arasında kenar, renkler sınav saatleri olur. Hocanın örneğinde (ekrandan, 00:50:00) 1. dersi A, B, C, D; 2. dersi A, B, X, Y; 3. dersi X, A; 4. dersi T, L, B öğrencileri alır. Kenarlar $1$–$2$, $1$–$3$, $2$–$3$, $1$–$4$, $2$–$4$ olur; 3 ile 4 arasında kenar yoktur. En az 3 sınav saati gerekir; 3. ve 4. dersler aynı saatte yapılabilir. Profesörlerden oluşan 10 kurulun toplantı çizelgesi de aynı şekilde modellenir: düğümler kurullar, kenarlar ortak üyeler, renkler toplantı zamanları.
  > **Ders sonrası not:** Hoca bu graf için $x(x-1)^2(x-2)$ dedi. Bu graf $K_4$'ten bir kenarı eksik (elmas) graftır; polinomu $x(x-1)(x-2)^2=x^4-5x^3+8x^2-4x$'tir (01:10:00'daki slaytla aynı graf). Sonuç değişmez: en az 3 saat gerekir; 3 saatle 6 farklı atama vardır.
- **Kromatik polinom özellikleri** (ekrandan, 01:00:00): $P(x)=a_0x^n-a_1x^{n-1}+a_2x^{n-2}+\dots a_nx^0$ için (1) $a_0=1$; (2) derece $n$ düğüm sayısıdır; (3) ikinci terimin katsayısı (mutlak değerce) kenar sayısıdır; (4) katsayılar toplamı 0, yani $P(1)=0$; (5) işaretler $+,-,+,-$ düzenindedir; (6) sabit terim yoktur, $P(0)=0$.
- **$K_4$ için deletion-contraction** (ekrandan, 01:05:00): Köşeler 1, 2, 3, 4. Önce $1$–$3$ kenarı silinir: $P(K_4)=P(K_4-e)-P(a)$; $(a)$, 1 ile 3'ün birleştiği üçgendir. Sonra $2$–$4$ kenarı silinir: $P(K_4-e)=P(\text{kare})-P(b)$; $(b)$, 2 ile 4'ün birleştiği 3 düğümlü yoldur. Son olarak $2$–$3$ kenarı silinir: $P(\text{kare})=P(c)-P(d)$; $(c)$ 4 düğümlü yol, $(d)$ üçgendir. Böylece $P(K_4)=P(c)-P(d)-P(b)-P(a)$:
  - $P(a)=P(d)=x(x-1)(x-2)$, $P(b)=x(x-1)^2$, $P(c)=x(x-1)^3$.
  - $P(K_4)=x(x-1)^3-2x(x-1)(x-2)-x(x-1)^2=x^4-6x^3+11x^2-6x$.
  - 4 düğüm, 6 kenar, işaretler doğru, sabit terim yok. $P(1)=P(2)=P(3)=0$, $P(4)=24$: en az 4 renk, 24 farklı boyama.
- **Ortak nokta yöntemi** (ekrandan, 01:10:00 ve 01:15:00): Elmas graf (kare ve bir köşegen) köşegen kenarı boyunca iki üçgene ayrılır; ortak parça çizgisel graftır:
  $$P(G)=\frac{x^2(x-1)^2(x-2)^2}{x(x-1)}=x(x-1)(x-2)^2=(x^2-x)(x^2-4x+4)=x^4-5x^3+8x^2-4x.$$
  $P(0)=P(1)=P(2)=0$, $P(3)=6$: en az 3 renk, $3\cdot2\cdot1=6$ farklı boyama. İkinci örnekte bir noktada birleşen iki üçgen ortak nokta ($x$) ile ayrılır: $P(G)=\dfrac{[x(x-1)(x-2)]^2}{x}=x(x-1)^2(x-2)^2=x^5-6x^4+13x^3-12x^2+4x$ (5 düğüm, 6 kenar).
  > **Ders sonrası not:** Hoca bu ikinci grafın 3 renkle 6 farklı şekilde boyandığını söyledi. Polinomdan $P(3)=3\cdot2^2\cdot1^2=12$ çıkar; doğru sayı büyük olasılıkla 12'dir (ortak düğüme 3, her üçgenin kalan iki düğümüne $2\cdot1$ seçenek: $3\cdot2\cdot2=12$).
- **Polinom çarpımı konvolüsyonla** (ekrandan, 01:15:00): $(x^2-x)(x^2-4x+4)$ için katsayıların mutlak değerleri $1\,4\,4$ ve $1\,1$ kaydırılarak toplanır: $1\,5\,8\,4$; işaretler $+,-,+,-$ verilerek $x^4-5x^3+8x^2-4x$ bulunur. Aynı şekilde $1\,5\,6$ ile $1\,1$'in konvolüsyonu $1\,6\,11\,6$, yani $K_4$ polinomunu verir.
- **Harita boyama.** Komşu bölgelerin farklı renk olması istenen haritalar en fazla dört renkle boyanabilir; beşinci renge gerek yoktur.
  > **Ek bilgi (derste anlatılmadı):** Bu sonuç Dört Renk Teoremi olarak bilinir ve büyük olasılıkla 1976'da Appel ve Haken tarafından bilgisayar destekli olarak ispatlanmıştır.
- **BFS ve DFS.** BFS kuyruk, DFS yığın kullanır. Matris üzerinde aramada BFS başlangıçtan katman katman yayılır (komşular 2, onların komşuları 3, ...); DFS bir yönde sonuna kadar ilerler. Graf görselleştirme sitelerinde Dijkstra ve BFS adım adım izlenebilir.
- **Kriptografi girişi (öğrenci sorusu üzerine).** Afin şifrelemede karakter kodu $x$ için $y=(ax+b)\bmod 26$; $a$ ve $b$ anahtardır. Çözmede $x=a^{-1}(y-b)\bmod 26$ kullanılır; $a^{-1}$, $a$'nın mod 26'daki çarpmaya göre tersidir (ekrandan, 01:30:00). $a$ olmadan $y=x+b$ Sezar şifrelemesidir. RSA'da şifreleme anahtarı herkese açıktır, çözme anahtarı farklıdır.
  > **Ders sonrası not:** Hoca afin şifrelemeyi önce "açık anahtarlı" diye andı, sonra "gizli" dedi. Afin ve Sezar şifrelemeleri tek (gizli) anahtarlı, simetrik yöntemlerdir; açık anahtarlı yöntem RSA'dır. Tahtadaki $y^{-1}=\frac{x-b}{a}$ yazımı ters fonksiyonu anlatır; mod 26'da bölme yerine $a^{-1}$ ile çarpılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
