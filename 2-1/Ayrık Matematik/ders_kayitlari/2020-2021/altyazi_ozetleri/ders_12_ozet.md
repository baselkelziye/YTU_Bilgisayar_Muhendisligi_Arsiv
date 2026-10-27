# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin tarihi 25 Aralık 2020 Cuma. Ders Zoom üzerinden yapıldı.
  - Hoca 10.30'da fakülte toplantısına katıldı. Ders yaklaşık 01:30 ile 01:57 arasında ara verdi.
- Çizgeler (graflar) konusunun kısa tekrarı
  - Basit çizge, paralel kenar, çoklu çizge, sözde çizge (pseudograph), yönlü ve ağırlıklı çizgeler.
  - Tam çizge ($K_n$), döngü çizgesi ($C_n$), tekerlek çizgesi ($W_n$), küp çizgesi ($Q_n$, $2^n$ düğüm), iki parçalı (bipartite) ve tam iki parçalı çizgeler.
- Yol (path) ve devre (cycle)
  - $n$ düğümlü bir yolda $n-1$ kenar vardır. Kapalı devrede düğüm sayısı kadar kenar vardır.
- Euler devresi ve Euler çizgesi
  - Königsberg köprü problemi.
  - Düğüm derecesi, yalıtılmış (isolated) düğüm, sarkık (pendant) düğüm.
  - El sıkışma teoremi: derecelerin toplamı kenar sayısının iki katıdır.
  - Yönlü çizgede giriş derecesi (in-degree) ve çıkış derecesi (out-degree).
- Hamilton devresi ve Hamilton çizgesi
  - Gezgin satıcı problemi, $Q_3$ örneği, Gray kodu ilişkisi.
- Dijkstra en kısa yol algoritması
  - A-F arası 6 düğümlü örnek ve $u_0$-$u_5$ arası ikinci örnek.
- Çizge modelleri
  - Niş örtüşme (niche overlap) çizgesi, etki (influence) çizgesi, dairesel turnuva (round-robin tournament) çizgesi.
  - Öncelik (precedence) çizgesi: $S_1$-$S_6$ program deyimleri örneği.
- Düzlemsel (planar) çizge ve Euler formülü $v-e+f=2$.
- Çizge eşyapısı (izomorfizm)
  - Komşuluk matrisi ve satır/sütun yer değiştirme.
- Ağ topolojileri ile çizge türleri
  - Yıldız = $K_{1,n}$, halka = $C_n$, hibrit = $W_n$.
- Çizge boyama ve kromatik polinomlar
  - Kromatik sayı $\chi(G)$, kromatik polinom $P_G(x)$.
  - Silme-büzme (deletion-contraction) yöntemi.
  - Bilinen çizgelerin polinomları, ortak kenar/düğümle birleşen çizgeler.
  - Polinomun doğruluk kontrolleri, eski bir vize sorusu ($W_4$).

## Hocanın Özellikle Vurguladığı Kısımlar

- Euler çizgesi olabilmesi için bütün düğümlerin derecesi çift olmalıdır.
  - Tek dereceli tek bir düğüm görürseniz diğerlerine bakmanıza gerek yok.
- Euler'de kenarlardan bir kez geçilir. Hamilton'da düğümlerden bir kez geçilir.
  - Hamilton çizgesini gösteren basit bir ipucu yoktur. Algoritmayla aranır.
- Dijkstra'da yeni bulunan değer, tablodaki eski değerden büyükse alınmaz.
  - Tabloda her zaman en küçük değer kalır.
- Çizgeye "influence graph", "precedence graph" gibi bir ad verildiyse çizgeyi o bakış açısıyla okuyun.
- İki çizgenin şekli farklı görünebilir ama eşyapılı olabilir.
  - Düğüm sayısı, kenar sayısı ve dereceler aynı olmalı.
  - Gerekirse satır/sütun yer değiştirerek komşuluk matrisleri eşlenmelidir.
- Kromatik polinomda bilinen çizgeleri tanıyın.
  - Noktasal çizge, çizgisel çizge (ağaç), $K_n$.
  - Bilinen bir çizge görünceye kadar çizgeyi bölün. Ne kadar erken tanırsanız iş o kadar kolaylaşır.
- Polinomu bulduktan sonra mutlaka kontrol edin.
  - Derece = düğüm sayısı.
  - İkinci katsayının mutlak değeri = kenar sayısı.
  - Baş katsayı 1, işaretler $+,-,+,\dots$ diye değişir, sabit terim yok.
  - Katsayıların toplamı 0.
- Silme-büzme işleminde dışarıda kalan noktaları unutmayın.
  - Tekrar eden alt çizgelere bir ad (ör. $A$) verip en sonda yerine koyun.
- Önümüzdeki Cuma (1 Ocak) ders yok. Ondan sonraki hafta vize var ve test olacak.

## Kısa Tekrar Notları

- Euler devresi (Euler circuit): her kenardan tam bir kez geçen kapalı yürüyüş.
  - Bağlantılı bir çizgede Euler devresi vardır ⇔ bütün dereceler çifttir.
- Euler yolu (Euler path): her kenardan bir kez geçer ama başladığı düğümde bitmez.
  - Bağlantılı bir çizgede tam iki tek dereceli düğüm varsa vardır.
- El sıkışma teoremi: $\sum_{v} \deg(v) = 2e$.
  - Örnek: 10 düğümün her birinin derecesi 6 ise $e = 60/2 = 30$.
- Yönlü çizgede: $\sum \deg^-(v) = \sum \deg^+(v) = e$.
- Hamilton devresi: her düğümden tam bir kez geçen kapalı devre.
- Dijkstra: başlangıca 0, diğerlerine $\infty$ verilir.
  - Her adımda ziyaret edilmemiş en küçük etiketli düğüm seçilir.
  - Komşularının etiketi $\min(\text{eski}, d(u)+w(u,v))$ olur.
- Euler formülü (bağlantılı düzlemsel çizge): $v - e + f = 2$.
- Kromatik polinomlar:
  - Tek düğüm: $P = x$.
  - $n$ düğümlü ağaç (yol çizgesi dahil): $P = x(x-1)^{n-1}$.
  - $K_n$: $P = \prod_{k=0}^{n-1}(x-k)$.
- Silme-büzme: $P(G) = P(G - e) - P(G / e)$.
- $G_1$ ile $G_2$ ortak bir $K_r$ ile birleşiyorsa $P(G) = \dfrac{P(G_1)\,P(G_2)}{P(K_r)}$.
  - Ortak düğüm için $K_1$ ($x$), ortak kenar için $K_2$ ($x(x-1)$) kullanılır.
- Kromatik sayı: $P(k) \neq 0$ yapan en küçük $k$. $P(k)$ ise $k$ renkle kaç farklı boyama yapılabileceğini verir.

## Detaylı Açıklamalar

### Königsberg köprü problemi

- Yerleşim bölgeleri A, B, C, D düğüm, 7 köprü kenar olarak alınır.
  - A-D arasında iki köprü, D-C arasında iki köprü var.
  - B-A, B-C ve B-D arasında birer köprü var.
- Dereceler: $\deg(A)=3$, $\deg(B)=3$, $\deg(C)=3$, $\deg(D)=5$. Toplam $14 = 2\cdot 7$.
- Tek dereceli düğüm olduğu için Euler devresi yoktur.
  - Dört düğümün de derecesi tek olduğu için Euler yolu da yoktur.

### Euler ve Hamilton örnekleri

- Derslerdeki örnek çizgeler için yöntem aynıdır.
  - Önce dereceler hesaplanır.
  - Hepsi çiftse çizge Euler çizgesidir. Kapalı devre çizilerek gösterilebilir.
  - Tek dereceli düğüm varsa Euler devresi yoktur.
  - Tam iki tek dereceli düğüm varsa, biri başlangıç diğeri bitiş olmak üzere her kenardan bir kez geçilebilir. Bu bir Euler yoludur.
- $Q_3$ küpünde her düğümden bir kez geçen kapalı devre vardır. Bu yüzden $Q_3$ bir Hamilton çizgesidir.
  - Düğüm etiketleri Gray kodudur. Komşu etiketler arasında yalnız bir bit değişir.
  - Hamilton devresi boyunca etiketleri sırayla okumak bir Gray kodu dizisi verir.
- Prim ve Kruskal algoritmaları da her düğüme uğrar, ama sonuçları kapalı devre değil, ağaçtır (minimum yayılan ağaç).

### Dijkstra örneği (A'dan F'ye)

- Kenarlar ve ağırlıklar:
  - A-B: 2, A-C: 3
  - B-D: 5, B-E: 2
  - C-E: 5
  - E-D: 1, E-F: 4
  - D-F: 2
- Adımlar:
  - A seçilir: $B=2$ (A'dan), $C=3$ (A'dan).
  - B seçilir: $D=7$ (A-B), $E=4$ (A-B).
  - C seçilir: E için $3+5=8 > 4$ olduğu için E değişmez.
  - E seçilir: $D=\min(7, 4+1)=5$, $F=4+4=8$.
  - D seçilir: $F=\min(8, 5+2)=7$.
  - F seçilir.
- Sonuç: A'dan F'ye en kısa yol A-B-E-D-F, uzunluğu 7.
- Diğer en kısa uzaklıklar: B=2, C=3, E=4, D=5.
- İkinci örnekte ($u_0$-$u_5$) aynı kural uygulanır.
  - Örnek: $u_4$'e önce 16 ile ulaşılıyordu. $u_5$ üzerinden $8+7=15$ ile ulaşılınca 16 silinir.

### Öncelik (precedence) çizgesi

- Slayttaki deyimler: $S_1: a:=0$, $S_2: b:=1$, $S_3: c:=a+1$, $S_4: d:=b+a$, $S_5: e:=d+1$, $S_6: e:=c+d$.
- Bir deyim, sağ tarafında kullandığı değişkeni sol tarafta tanımlayan deyime bağlıdır.
- Doğrudan bağımlılık kenarları:
  - $S_1 \to S_3$ ($a$)
  - $S_1 \to S_4$ ($a$), $S_2 \to S_4$ ($b$)
  - $S_4 \to S_5$ ($d$)
  - $S_3 \to S_6$ ($c$), $S_4 \to S_6$ ($d$)
- Hoca $d$'nin içindeki $a$ ve $b$ yüzünden $S_5$ ve $S_6$'ya $S_1$, $S_2$ kenarlarını da ekledi. Bkz. ders sonrası notlar.

### Düzlemsel çizge

- Kenarlar kesişmeden düzleme çizilebilen çizgeye düzlemsel çizge denir.
- İki kenarın kesişme noktasında düğüm çizilmemişse kenarlar üst üste geçiyor demektir.
- $K_4$ (piramit) örneği: $v=4$, $e=6$. $4-6+f=2 \Rightarrow f=4$.
  - Taban ve üç yan yüz.

### Eşyapı (izomorfizm)

- Kare ($C_4$) ve "kelebek" görünümlü çizge eşyapılıdır.
  - Kelebekte kenarlar kesişmiyor, kesişme noktasında düğüm yok.
  - $u_2$ ile $u_4$'ün satır ve sütunları yer değiştirince iki komşuluk matrisi aynı olur.
- 5 düğümlü, 5 kenarlı, bütün dereceleri 2 olan beşgen ile yıldız aynı çizgedir. İkisi de $C_5$.
- Bir çizgede derecesi 1 olan düğüm varken diğerinde yoksa çizgeler eşyapılı değildir.

### Ağ topolojileri

- Yıldız topolojisi = $K_{1,n}$. Ortadaki düğüm sunucudur.
- Halka topolojisi = $C_n$. Bir hat kopunca o düğüm diğerleri üzerinden dolaşır.
- Hibrit topoloji = $W_n$. En sağlam ama en pahalı yapıdır.

### Kromatik polinom örnekleri

- $K_4$: $P = x(x-1)(x-2)(x-3) = x^4 - 6x^3 + 11x^2 - 6x$.
  - $P(1)=P(2)=P(3)=0$, $P(4)=24$.
  - $K_4$ en az 4 renkle boyanır. 4 renkle 24 farklı boyama vardır.
- $K_4$'ü silme-büzmeyle çözme:
  - $P(K_4) = P(K_4 - e) - P(K_3)$.
  - $K_4 - e$ (elmas, iki üçgen ortak kenarla): $P = \dfrac{[x(x-1)(x-2)]^2}{x(x-1)} = x(x-1)(x-2)^2 = x^4 - 5x^3 + 8x^2 - 4x$.
  - Elmas en az 3 renkle boyanır. 3 renkle 6 farklı boyama vardır.
- $C_4$: $P = x(x-1)^3 - x(x-1)(x-2) = x(x-1)(x^2 - 3x + 3)$.
- Çarpma kısayolu: katsayıları çarpıp işaretleri $+,-,+,-$ diye yerleştirin.
  - $(x-1)(x^2-5x+6)$ katsayıları için $1,5,6$ ile $1,1$ çarpılır, $1,6,11,6$ elde edilir.

### Eski vize sorusu: $W_4$

- 4 köşe ($C_4$) ve hepsine bağlı bir merkez düğüm (düğüm 5): 5 düğüm, 8 kenar.
- Hoca 2-4 kenarını sildi ve büzdü.
  - Silinen çizge iki parça olarak çözüldü. Tekrar eden alt çizgeye $A$ adı verildi.
  - Büzülen çizge $K_4$ oldu.
- Sonuç: $P(W_4) = x^5 - 8x^4 + 24x^3 - 31x^2 + 14x$.
- Kontroller:
  - Derece 5 = düğüm sayısı.
  - İkinci katsayı 8 = kenar sayısı.
  - Katsayılar toplamı $1-8+24-31+14=0$.
- $P(1)=P(2)=0$, $P(3)=6$. En az 3 renkle boyanır. 3 renkle 6 farklı boyama vardır.

### Ders sonrası notlar

- **Euler devresinin tanımı:** Hoca bir yerde Euler devresini "her düğümden bir kez geçerek" diye tanımladı. Doğrusu her **kenardan** bir kez geçmektir. Düğümlerden bir kez geçmek Hamilton devresinin tanımıdır. Hoca sonraki örneklerde doğru tanımı kullandı.
- **"Euler devresi var ama Euler çizgesi değil" ifadesi:** Rosen'daki terimlerle başlangıç ve bitişi farklı olan, her kenardan bir kez geçen yürüyüş bir **Euler yoludur** (Euler path). Euler devresi tanım gereği kapalıdır. Euler devresi varsa çizge zaten Euler çizgesidir.
- **Euler şartının eksik kısmı:** "Bütün dereceler çift" şartı çizge **bağlantılıysa** yeterlidir. Bağlantısız bir çizgede dereceler çift olsa da Euler devresi olmayabilir.
- **Königsberg dereceleri:** Derste A'nın derecesi önce "4" dendi. Altyazıdaki köprü dağılımına göre dereceler 3, 3, 3 ve 5'tir. Python ile sayıldı.
- **Kromatik polinomun tanımı:** Hoca $P_G(k)$'yı "minimum renkle kaç farklı şekilde boyanır" diye tanımladı. Doğrusu: $P_G(k)$, elimizde $k$ renk varken kaç farklı uygun boyama yapılabileceğini verir. Bunu her $k$ için verir. Kromatik sayı, $P_G(k)>0$ olan en küçük $k$'dır.
- **Polinomun "son terimi $x$ ile biter" kuralı:** Bu kural yalnız bağlantılı çizgeler için doğrudur. $c$ bileşenli bir çizgede en küçük üs $x^c$'dir. "Katsayılar toplamı 0" kuralı da çizgede en az bir kenar varsa geçerlidir. Çünkü $P(1)=0$ olur.
- **$K_4$ slaytı:** Hoca slaytta polinomun ilk yazılan hâlinin ve çizgenin hatalı olduğunu söyledi. Doğru polinom $x^4-6x^3+11x^2-6x$'tir. Brute force sayımla $P(4)=24$ doğrulandı.
- **Öncelik çizgesinde fazladan kenarlar:** Hoca $S_5$'e $S_1$ ve $S_2$'yi, $S_6$'ya $S_1$'i de bağladı. Öncelik çizgesinde yalnız doğrudan bağımlılık kenarları çizilir. Dolaylı bağımlılıklar zaten yol üzerinden gelir ($S_1 \to S_4 \to S_5$). Rosen'daki örnekte de çizge yalnız doğrudan kenarlardan oluşur.
- **Doğrulama:** Dijkstra sonuçları, Königsberg dereceleri, $K_4$, elmas, $C_4$ ve $W_4$ kromatik polinomları Python ile kontrol edildi. Polinomlar $k=0,\dots,5$ için tek tek boyama sayılarak doğrulandı.
- Altyazıdaki "öler" Euler, "hil graf" wheel (tekerlek) çizgesi, "pentant" pendant, "Dishkstra" Dijkstra, "kromotik" kromatik, "dilatation/deletition contraction" deletion-contraction demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
