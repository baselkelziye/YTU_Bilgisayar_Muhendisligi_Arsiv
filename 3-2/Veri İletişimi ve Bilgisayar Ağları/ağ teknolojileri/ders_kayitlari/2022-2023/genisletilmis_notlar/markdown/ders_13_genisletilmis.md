# Ders 13 Genişletilmiş Notu: Ağ Katmanı Kontrol Düzlemi: Yönlendirme Algoritmaları, OSPF, BGP ve SDN

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kontrol Düzlemine Dönüş ve Yönlendirme Protokolünün Amacı
- 2. Çizge Soyutlaması ve Maliyetler
- 3. Yönlendirme Algoritmalarının Sınıflandırılması
- 4. Dijkstra'nın Bağlantı Durumu Algoritması
- 5. Dijkstra Algoritmasının Karmaşıklığı ve Salınım
- 6. Bellman-Ford Denklemi ve Uzaklık Vektörü Algoritması
- 7. Uzaklık Vektörü Örneği ve Bilginin Yayılması
- 8. Bağlantı Maliyeti Değişimi: İyi Haber ve Kötü Haber
- 9. Bağlantı Durumu ile Uzaklık Vektörünün Karşılaştırılması
- 10. Ölçeklenebilir Yönlendirme ve Özerk Sistemler
- 11. AS İçi Yönlendirme Protokolleri ve OSPF
- 12. BGP: AS'ler Arası Yönlendirme
- 13. Neden İki Ayrı Yönlendirme Türü?
- 14. SDN Kontrol Düzlemi
- 15. OpenFlow ve SDN Denetleyicileri
- Örnek Sorular

## 1. Kontrol Düzlemine Dönüş ve Yönlendirme Protokolünün Amacı

Ders, önceki haftanın hatırlatılmasıyla açıldı. Ağ katmanı iki parçaya bölünmüştü: veri düzlemi (data plane) ve kontrol düzlemi (control plane). Veri düzlemi bitmiş, bir önceki derste kontrol düzlemine başlanmıştı. Bu derste kontrol düzleminin merkezindeki konu, yani yönlendirme protokolleri işlendi. Yönlendirme protokolü temelde kaynaktan hedefe giden yolu belirler. Ele alınacak iki ana tür vardır: bağlantı durumu (link state) tabanlı olanlar ve uzaklık vektörü (distance vector) tabanlı olanlar.

Ağın amacı, mesajı bir uçtan (edge) diğer uca göndermektir. Uç, dizüstü bilgisayar, masaüstü bilgisayar ya da evdeki başka bir cihaz olabilir. Slayttaki tanıma göre yönlendirme protokolünün hedefi, gönderen konaktan alıcı konağa, yönlendiricilerden oluşan ağ üzerinden "iyi" yolları (eşdeğer olarak rotaları) belirlemektir (ekrandan, 00:10:00). Slayttaki şekilde bir kurumsal ağdan çıkan paketin ulusal ya da küresel ISS ağları, mobil ağ ve veri merkezi ağı arasından geçerek hedefe ulaştığı kırmızı bir yol görülür; yol üzerindeki her yönlendiricide yalnız ağ, bağlantı ve fiziksel katmanlar çalışır.

Hoca tanımdaki iki anahtar kelimenin, "yol" ve "iyi" kelimelerinin üzerinde durdu. Yol (path), bir paketin kaynak konaktan son hedefe aktarılırken geçtiği yönlendiriciler dizisidir. Yol üzerinde çok sayıda yönlendirici olduğundan, yolu bulmak yönlendiriciler arasında eşgüdüm gerektirir. "İyi" ise tanımlanması gereken bir değerdir: bir yol ucuz olduğu için, en hızlı olduğu için ya da en az tıkanık olduğu için iyi sayılabilir. Yönlendirme protokolü bu tanıma göre kaynaktan hedefe iyi bir yol bulur. Hoca yönlendirme sorununu dünyadaki ilk on ağ sorunundan biri olarak andı.

## 2. Çizge Soyutlaması ve Maliyetler

Yönlendirme protokollerine geçmeden önce terminoloji bir çizge (graf) üzerinden tanıtıldı. Çizgede $u, v, w, x, y, z$ adlı yönlendiriciler ve aralarındaki bağlantılar vardır; bağlantıların üzerindeki değerler ISS'ler tarafından belirlenir.

Çizge $G = (N, E)$ biçiminde yazılır:

- $N$: yönlendiriciler (düğümler) kümesi, $N = \{u, v, w, x, y, z\}$.
- $E$: bağlantılar (kenarlar) kümesi; örneğin $(u,v)$, $(u,x)$, $(v,x)$, $(v,w)$, $(x,w)$, $(x,y)$, $(w,y)$, $(w,z)$, $(y,z)$.

$c_{a,b}$, $a$ yönlendiricisinden $b$ yönlendiricisine doğrudan bağlantının maliyetidir. Örneğin çizgede $c_{w,z} = 5$'tir. Maliyet sonsuz ise iki düğüm arasında doğrudan bağlantı yoktur.

Maliyeti ağ işletmecisi ya da ISS tanımlar. Maliyet her bağlantı için hep 1 olabilir, bant genişliğiyle ters orantılı olabilir, tıkanıklıkla ters orantılı olabilir ya da işletmecinin tanımladığı başka bir ölçüte bağlı olabilir.

## 3. Yönlendirme Algoritmalarının Sınıflandırılması

Slayttaki sınıflandırma iki eksenlidir (ekrandan, 00:15:00). Dikey eksen "küresel mi, merkezi olmayan bilgi mi?" sorusunu, yatay eksen "rotalar ne kadar hızlı değişir?" sorusunu gösterir.

**Küresel (global):** bütün yönlendiriciler tam topolojiye ve bağlantı maliyeti bilgisine sahiptir. Ağdaki her yönlendirici bütün topolojiyi bilir. Bunlar "bağlantı durumu" (link state) algoritmalarıdır.

**Merkezi olmayan (decentralized) ya da dağıtık:** hesaplama yinelemeli bir süreçtir ve komşu yönlendiriciler arasında bilgi değişimiyle yürür. Yönlendiriciler başta yalnız doğrudan bağlı komşularına olan bağlantı maliyetlerini bilir; sonra komşularıyla bilgi değişip tablolarını günceller. Örneği "uzaklık vektörü" (distance vector) algoritmasıdır.

İkinci sınıflandırma rotaların değişme hızına göredir:

- **Statik:** rotalar zamanla çok yavaş değişir.
- **Dinamik:** rotalar daha hızlı değişir; güncelleme periyodik olarak ya da bağlantı maliyeti değişimine tepki olarak yapılır.

## 4. Dijkstra'nın Bağlantı Durumu Algoritması

### 4.1 Algoritmanın özellikleri

Dijkstra algoritması bir bağlantı durumu algoritmasıdır, yani küresel (merkezi) bir algoritmadır. Her yönlendirici bütün ağ topolojisini bilir. Bu bilgi bağlantı durumu yayınıyla (link state broadcast) sağlanır; algoritma küresel olduğu için bütün düğümler aynı bilgiye sahiptir.

Algoritma bir düğümden ağdaki diğer bütün düğümlere giden en düşük maliyetli yolları hesaplar. Sonuç, o yönlendiricinin iletim tablosunu verir. Topoloji değiştikçe bilgi yeniden değiştirilir ve ilgili iletim tablosu güncellenir. Algoritma yinelemelidir: $k$ yinelemeden sonra her yönlendirici $k$ hedefe giden en düşük maliyetli yolu bilir.

### 4.2 Gösterim

- $c_{x,y}$: $x$ düğümünden $y$ düğümüne doğrudan bağlantı maliyeti; komşu değillerse $\infty$.
- $D(v)$: kaynaktan $v$ hedefine giden en düşük maliyetli yolun o anki tahmini maliyeti.
- $p(v)$: kaynaktan $v$'ye giden yol üzerinde $v$'den önceki düğüm.
- $N'$: en düşük maliyetli yolu kesin olarak bilinen düğümler kümesi.

### 4.3 Algoritma

Slayttaki sözde kod şöyledir (ekrandan, 00:20:00):

```text
1  Initialization:
2    N' = {u}                    /* u'dan diğer bütün düğümlere en düşük maliyetli yol */
3    for all nodes v
4      if v adjacent to u        /* u başta yalnız doğrudan komşularına maliyeti bilir */
5        then D(v) = c(u,v)      /* ama bu en düşük maliyet olmayabilir */
6      else D(v) = ∞
7
8  Loop
9    find w not in N' such that D(w) is a minimum
10   add w to N'
11   update D(v) for all v adjacent to w and not in N':
12     D(v) = min( D(v), D(w) + c(w,v) )
13   /* v'ye yeni en düşük maliyet ya v'ye eski en düşük maliyettir
14      ya da w'ye bilinen en düşük maliyet artı w'den v'ye doğrudan maliyettir */
15 until all nodes in N'
```

Başlangıçta $N'$ yalnız başlangıç düğümü $u$'yu içerir. $u$'ya komşu her $v$ için $D(v) = c_{u,v}$, komşu olmayanlar için $D(v) = \infty$ alınır. Döngüde $N'$'de olmayan düğümler arasından $D(w)$'si en küçük olan $w$ bulunur ve $N'$'ye eklenir. Sonra $w$'ye komşu olup $N'$'de bulunmayan her $v$ için $D(v)$, önceki $D(v)$ ile $D(w) + c_{w,v}$'nin küçüğü olarak güncellenir.

### 4.4 Birinci örnek

Çizgenin kenar maliyetleri şöyledir (ekrandan, 00:25:00): $c_{u,v}=2$, $c_{u,x}=1$, $c_{u,w}=5$, $c_{v,w}=3$, $c_{v,x}=2$, $c_{x,w}=3$, $c_{x,y}=1$, $c_{y,w}=1$, $c_{w,z}=5$, $c_{y,z}=2$. Başlangıç noktası $u$'dur.

**Adım 0 ($N' = \{u\}$):** $u$'dan $v$'ye doğrudan bağlantı vardır, $D(v)=2$, $p(v)=u$. $w$'ye doğrudan maliyet 5'tir, $D(w)=5$, $p(w)=u$. $x$'e maliyet 1'dir, $D(x)=1$, $p(x)=u$. $y$ ve $z$'ye doğrudan bağlantı yoktur, $D(y)=D(z)=\infty$. En küçük değer 1 olduğundan $x$ seçilir.

**Adım 1 ($N' = \{u, x\}$):** $x$'e geçilir.

- $v$ için: önceki değer 2, $x$ üzerinden $1 + 2 = 3$; 2 daha küçük olduğundan $D(v)=2$ kalır.
- $w$ için: $1 + 3 = 4 < 5$, $D(w)=4$, $p(w)=x$ olur.
- $y$ için: önceki değer $\infty$, $x$ üzerinden $1 + 1 = 2$; $D(y)=2$, $p(y)=x$.
- $z$ için hâlâ bağlantı yoktur, $\infty$.

Bu adımda $v$ ile $y$ eşit (2) değerdedir. Hoca $y$'yi seçti.

**Adım 2 ($N' = \{u, x, y\}$):** $y$ üzerinden $w$'ye toplam maliyet $u$–$x$–$y$–$w$ yoluyla $2 + 1 = 3$ olur; bu 4'ten küçük olduğundan $D(w)=3$, $p(w)=y$. $z$'ye artık erişilebilir: $2 + 2 = 4$, $D(z)=4$, $p(z)=y$. Sonra $v$ (2) seçilir.

**Adım 3 ($N' = \{u, x, y, v\}$):** $v$ üzerinden $w$'ye $2 + 3 = 5 > 3$ olduğundan $D(w)=3$ kalır. $z$ değeri 4 olarak korunur. En küçük değer 3 olan $w$ seçilir.

**Adım 4 ($N' = \{u, x, y, v, w\}$):** $w$ üzerinden $z$'ye $3 + 5 = 8 > 4$ olduğundan $D(z)=4$, $p(z)=y$ kalır. Son olarak $z$ eklenir.

Sonuçta $u$'dan en düşük maliyetler $v=2$, $x=1$, $y=2$, $w=3$, $z=4$'tür (python ile doğrulandı). En düşük maliyetli yol ağacı $u$–$v$, $u$–$x$–$y$–$w$ ve $u$–$x$–$y$–$z$ dallarından oluşur. $u$'nun iletim tablosu şöyledir (ekrandan, 00:25:00):

| Hedef | Çıkış bağlantısı |
|---|---|
| $v$ | $(u,v)$ |
| $x$ | $(u,x)$ |
| $y$ | $(u,x)$ |
| $w$ | $(u,x)$ |
| $z$ | $(u,x)$ |

> **Ders sonrası not:** Slayttaki tablonun son satırında hedef olarak yine "x" yazıyor. Çizgede geriye kalan hedef $z$ olduğundan bu satır büyük olasılıkla $z$ olmalıdır.

Hoca bu tabloyu şöyle yorumladı: $u$, $v$'ye $(u,v)$ bağlantısıyla gider; $x$, $y$, $w$ ve $z$'ye ise hep $x$ üzerinden, yani $(u,x)$ bağlantısıyla gider. Böylece merkezi Dijkstra algoritmasıyla $u$'nun yönlendirme tablosu elde edilmiş olur.

### 4.5 İkinci örnek

Hoca aynı işlemi başka bir çizgede tekrarladı. Kenar maliyetleri hocanın okuduğu toplamlardan şöyle çıkarılabilir: $c_{u,v}=7$, $c_{u,w}=3$, $c_{u,x}=5$, $c_{w,v}=3$, $c_{w,x}=4$, $c_{w,y}=8$, $c_{x,y}=7$, $c_{x,z}=9$, $c_{v,y}=4$, $c_{y,z}=2$. <!-- BELİRSİZ: bu çizgenin karesi yok; kenarlar altyazıdaki toplamlardan çıkarıldı. x adımında v için söylenen "5, 9, 12" anlaşılamadı, v değeri 6 olarak kaldı -->

**Adım 0 ($N' = \{u\}$):** $D(v)=7$, $D(w)=3$, $D(x)=5$, $D(y)=D(z)=\infty$. En küçük 3 olduğundan $w$ seçilir.

**Adım 1 ($N' = \{u, w\}$):** $w$ üzerinden $v$'ye $3 + 3 = 6 < 7$, $D(v)=6$, $p(v)=w$. $x$'e $3 + 4 = 7 > 5$, $D(x)=5$ kalır. $y$'ye $3 + 8 = 11$, $D(y)=11$, $p(y)=w$. $z$'ye bağlantı yoktur. En küçük 5 olduğundan $x$ seçilir.

**Adım 2 ($N' = \{u, w, x\}$):** $v$ 6 olarak kalır. $y$'ye $x$ üzerinden $5 + 7 = 12 > 11$, $D(y)=11$ kalır. $z$'ye $5 + 9 = 14$, $D(z)=14$, $p(z)=x$. En küçük 6 olduğundan $v$ seçilir.

**Adım 3 ($N' = \{u, w, x, v\}$):** $v$ üzerinden $y$'ye $6 + 4 = 10 < 11$, $D(y)=10$, $p(y)=v$. $v$'den $z$'ye doğrudan bağlantı olmadığından $D(z)=14$ kalır. En küçük 10 olan $y$ seçilir.

**Adım 4 ($N' = \{u, w, x, v, y\}$):** $y$ üzerinden $z$'ye $10 + 2 = 12 < 14$, $D(z)=12$, $p(z)=y$ olur. Son olarak $z$ eklenir.

Sonuç: $w=3$ ($u$ üzerinden), $x=5$ ($u$), $v=6$ ($w$), $y=10$ ($v$), $z=12$ ($y$). Bu değerler python ile doğrulandı.

## 5. Dijkstra Algoritmasının Karmaşıklığı ve Salınım

### 5.1 Algoritma ve mesaj karmaşıklığı

Slayta göre (ekrandan, 00:30:00):

- **Algoritma karmaşıklığı ($n$ düğüm):** $n$ yinelemenin her birinde $N'$'de olmayan bütün $w$ düğümlerinin kontrol edilmesi gerekir. Toplam $n(n+1)/2$ karşılaştırma yapılır, bu da $O(n^2)$ karmaşıklık demektir. Daha verimli gerçeklemelerle $O(n \log n)$ mümkündür.
- **Mesaj karmaşıklığı:** her yönlendirici kendi bağlantı durumu bilgisini diğer $n$ yönlendiriciye yayınlamalıdır. Verimli yayın algoritmaları bir kaynaktan çıkan mesajı $O(n)$ bağlantı geçişiyle herkese ulaştırır. Her yönlendiricinin mesajı $O(n)$ bağlantıdan geçtiğinden toplam mesaj karmaşıklığı $O(n^2)$'dir.

> **Ek bilgi (derste anlatılmadı):** $O(n \log n)$ ifadesi, en küçük $D(w)$'yi bulmak için öncelik kuyruğu (yığın, heap) kullanan gerçeklemelere dayanır; kenar sayısı da hesaba katılınca karmaşıklık genellikle $O((n + |E|) \log n)$ biçiminde yazılır.

### 5.2 Rota salınımı

Kuramsal olarak, bağlantı maliyetleri taşıdıkları trafik miktarına bağlıysa rota salınımı (oscillation) olabilir. Hocanın senaryosunda dört yönlendirici ($a$–$d$) vardır ve hedef $a$'dır. Trafik $d$, $c$ ve $b$ düğümlerinden girer; girişlerden birinin hızı $e < 1$, diğerleri 1'dir. Bağlantı maliyetleri yönlüdür ve taşınan trafiğe bağlıdır. Rotalar saat yönünün tersine hesaplandığında maliyetler bir değer alır, bu maliyetlere göre trafik saat yönüne kayar; bu kez saat yönündeki maliyetler artar ve trafik tekrar ters yöne kayar. Böylece her hesaplamada rotalar yön değiştirir. <!-- BELİRSİZ: senaryodaki maliyet değerleri (e, 1+e, 2+e) altyazıda bozuk; karesi yok -->

## 6. Bellman-Ford Denklemi ve Uzaklık Vektörü Algoritması

### 6.1 Bellman-Ford denklemi

Merkezi olmayan algoritma, Bellman-Ford (BF) denklemine dayanan uzaklık vektörü algoritmasıdır. $D_x(y)$, $x$'ten $y$'ye en düşük maliyetli yolun maliyeti olsun. O zaman

$$D_x(y) = \min_v \{ c_{x,v} + D_v(y) \}$$

yazılır. Burada $c_{x,v}$, $x$'ten komşusu $v$'ye doğrudan maliyettir; $D_v(y)$ ise $v$'den $y$'ye tahmini en düşük maliyettir. Minimum, $x$'in bütün komşuları $v$ üzerinden alınır.

> **Ders sonrası not:** Hoca denklemi tanıttıktan sonra bir an "bu denkleme Dijkstra denir" dedi, ardından doğru adla Bellman-Ford denklemi diye sürdürdü. Bu denklem Bellman-Ford denklemidir.

### 6.2 Bellman-Ford örneği

Birinci Dijkstra örneğindeki çizge kullanıldı (ekrandan, 00:35:00). $u$'nun komşuları $x$, $v$ ve $w$'dir. Bu komşuların $z$ hedefi için bildikleri en düşük maliyetler şunlardır:

- $D_v(z) = 5$ ($v$, $z$'ye $w$–$y$–$z$ ya da $x$–$y$–$z$ gibi yollarla 5 maliyetle ulaşabileceğini bilir),
- $D_x(z) = 3$ ($x$–$y$–$z$: $1 + 2$),
- $D_w(z) = 3$ ($w$–$y$–$z$: $1 + 2$).

$u$ bunları kullanarak hesaplar:

$$D_u(z) = \min\{ c_{u,v} + D_v(z),\ c_{u,x} + D_x(z),\ c_{u,w} + D_w(z) \} = \min\{ 2+5,\ 1+3,\ 5+3 \} = \min\{7, 4, 8\} = 4$$

En küçük değer $x$ üzerinden geldiği için $u$, $z$'ye $x$ üzerinden gidecek biçimde değerini günceller. Bu, birinci Dijkstra örneğindeki $D(z)=4$ ve $(u,x)$ sonucuyla tutarlıdır.

### 6.3 Uzaklık vektörü algoritmasının işleyişi

Her düğüm zaman zaman kendi uzaklık vektörü tahminini komşularına gönderir. $x$ düğümü herhangi bir komşusundan yeni bir uzaklık vektörü aldığında kendi vektörünü Bellman-Ford denklemiyle günceller. Küçük, doğal koşullar altında $D_x(y)$ tahmini gerçek en düşük maliyet $d_x(y)$'ye yakınsar.

Her düğüm üç durum arasında döner:

- yerel bağlantı maliyetinde bir değişiklik ya da komşudan bir mesaj gelmesini **bekler**,
- uzaklık vektörünü Bellman-Ford ile **yeniden hesaplar**,
- bir şey değiştiyse komşularına **bildirir**, sonra tekrar beklemeye döner.

Algoritmanın özellikleri:

- **Yinelemeli ve eşzamansız (asenkron):** her yerel yinelemeyi ya yerel bağlantı maliyeti değişimi ya da komşudan gelen uzaklık vektörü güncellemesi tetikler.
- **Dağıtık:** merkezi değildir; her düğüm yalnız bir şey değiştiğinde komşularını uyarır.
- **Kendiliğinden duran (self-stopping):** mesaj gelirse hesaplanır, bir şey değişirse dağıtılır. Mesaj gelmez ya da bağlantı değişmezse yeni mesaj da üretilmez, algoritma kendiliğinden durur.

## 7. Uzaklık Vektörü Örneği ve Bilginin Yayılması

### 7.1 Başlangıç durumu

Örnek, $3 \times 3$ ızgara biçiminde dokuz düğümlü bir ağdır (ekrandan, 00:40:00). Bağlantılar: $a$–$b$ 8, $b$–$c$ 1, $a$–$d$ 1, $b$–$e$ 1, $d$–$e$ 1, $e$–$f$ 1, $d$–$g$ 1, $e$–$h$ 1, $f$–$i$ 1, $g$–$h$ 1, $h$–$i$ 1. Slayt iki "asimetriye" dikkat çeker: $c$ ile $f$ arasında bağlantı yoktur (eksik bağlantı) ve $a$–$b$ maliyeti diğerlerinden büyüktür (8).

$t = 0$'da bütün düğümler yalnız en yakın komşularına olan uzaklığı bilir. $a$'nın uzaklık vektörü:

| Hedef | $a$ | $b$ | $c$ | $d$ | $e$ | $f$ | $g$ | $h$ | $i$ |
|---|---|---|---|---|---|---|---|---|---|
| $D_a(\cdot)$ | 0 | 8 | $\infty$ | 1 | $\infty$ | $\infty$ | $\infty$ | $\infty$ | $\infty$ |

$D_a(a) = 0$'dır çünkü düğümün kendisidir; $D_a(b) = 8$ doğrudan bağlantıdır; $D_a(d) = 1$; diğerleri doğrudan bağlantı olmadığından sonsuzdur. Hoca, $a$'nın bu aşamada $b$ üzerinden $c$'ye nasıl gidileceğini henüz bilmediğini vurguladı.

Benzer biçimde $t=0$'da $b$'nin vektörü $D_b(a)=8$, $D_b(c)=1$, $D_b(e)=1$, diğerleri $\infty$; $c$'nin vektörü yalnız $D_c(b)=1$ içerir. Ortadaki $e$ düğümünün vektörü: $b$, $d$, $f$ ve $h$'ye 1, diğerlerine $\infty$.

### 7.2 Birinci yineleme: b ve c'nin hesaplaması

Her düğüm vektörünü hesaplayıp komşularına dağıtır. $b$, komşuları $a$, $c$ ve $e$'den vektör alır ve hesaplar. Örneğin

$$D_b(a) = \min\{ c_{b,a} + D_a(a),\ c_{b,c} + D_c(a),\ c_{b,e} + D_e(a) \} = \min\{8 + 0,\ 1 + \infty,\ 1 + \infty\} = 8$$

$$D_b(c) = \min\{ 8 + \infty,\ 1 + 0,\ 1 + \infty \} = 1$$

Aynı biçimde devam edilince (ara adım eklendi) $b$'nin yeni vektörü şöyle olur (python ile doğrulandı):

| Hedef | $a$ | $b$ | $c$ | $d$ | $e$ | $f$ | $g$ | $h$ | $i$ |
|---|---|---|---|---|---|---|---|---|---|
| $D_b(\cdot)$ | 8 | 0 | 1 | 2 | 1 | 2 | $\infty$ | 2 | $\infty$ |

Hocanın belirttiği gibi $b$'nin bu aşamada $g$ ve $i$ hakkında hâlâ bilgisi yoktur; diğer değerler bulunmuştur. $b$ bu vektörü kaydedip yeniden dağıtır.

$c$ ise yalnız $b$'den vektör alır: $D_c(a) = 1 + 8 = 9$, $D_c(b) = 1 + 0 = 1$, $D_c(e) = 1 + 1 = 2$; $b$'nin $t=0$ vektöründe sonsuz olan hedefler için $1 + \infty = \infty$ kalır. Böylece $c$'nin vektörü güncellenir. $e$ de $b$, $d$, $f$ ve $h$'den gelen vektörlerle aynı işlemi yapar.

### 7.3 Bilginin yayılması

Hoca, $c$'nin durum bilgisinin ağa nasıl yayıldığını adım adım gösterdi (ekrandan, 00:45:00). $t = 0$'da $c$'nin durumu yalnız $c$'dedir. Her yinelemede bilgi bir atlama daha uzağa ulaşır ve dördüncü adımda bütün ağı kaplar. Bu, algoritmanın yinelemeli ve dağıtık olmasının sonucudur: komşu yönlendiriciler arasında mesaj değişimi, hesaplama, uzaklık vektörünün güncellenmesi, yeni vektörün dağıtılması ve yeniden hesaplama gerekir.

Ağdaki atlama uzaklıklarına göre yayılım sırası şöyledir (python ile hesaplandı): $t=1$'de $b$, $t=2$'de $a$ ve $e$, $t=3$'te $d$, $f$ ve $h$, $t=4$'te $g$ ve $i$. <!-- BELİRSİZ: hocanın her adımda saydığı düğümler altyazıda karışık ("A ve E", "ADH"); sıra karesiz olarak atlama uzaklığından kuruldu -->

## 8. Bağlantı Maliyeti Değişimi: İyi Haber ve Kötü Haber

### 8.1 İyi haber hızlı yayılır

Ağ üç düğümlüdür: $x$, $y$, $z$. $x$–$y$ maliyeti 4, $y$–$z$ maliyeti 1'dir. <!-- BELİRSİZ: x–z maliyeti altyazıda "9" diye geçiyor; karesi yok --> $x$–$y$ bağlantısının maliyeti 4'ten 1'e düşsün.

- $t_0$: $y$ bağlantı maliyeti değişimini fark eder, uzaklık vektörünü günceller ve komşularını bilgilendirir.
- $t_1$: $z$, $y$'den güncellemeyi alır, tablosunu günceller ve $x$'e yeni en düşük maliyeti hesaplar: önceki 5 iken yeni değer $1 + 1 = 2$ olur; vektörünü komşularına gönderir.
- $t_2$: $y$, $z$'nin güncellemesini alır ve vektörünü günceller; ancak $y$'nin en düşük maliyetleri değişmez, çünkü doğrudan bağlantı 1'dir ve $z$ üzerinden gelen değer daha büyüktür. Bu yüzden $y$ mesaj göndermez.

Kısacası maliyet azaldığında uzaklık vektörleri çok hızlı güncellenir: iyi haber hızlı yayılır.

### 8.2 Kötü haber yavaş yayılır

Sorun maliyet arttığında ortaya çıkar. $x$–$y$ maliyeti 4'ten 60'a çıksın. $y$, $x$'e doğrudan bağlantının yeni maliyetinin 60 olduğunu görür. Ama $z$ daha önce $x$'e 5 maliyetle gidebildiğini bildirmiştir; oysa $z$'nin bu yolu zaten $y$'den geçmektedir. $y$ bunu bilemez ve $z$ üzerinden gitmeyi seçerek değerini günceller, sonra $z$'ye dağıtır. $z$ de bu yeni değere göre kendi değerini artırır. İkisi birbirinin eski bilgisine bakarak değerlerini adım adım artırır; doğru değere ulaşmak çok sayıda yineleme alır. Buna sonsuza sayma (count-to-infinity) sorunu denir.

> **Ders sonrası not:** Altyazıda hoca $y$'nin değerini 5'e güncellediğini söylüyor. Bellman-Ford'a göre $D_y(x) = \min\{60,\ c_{y,z} + D_z(x)\} = \min\{60,\ 1 + 5\} = 6$ olur.

> **Ek bilgi (derste anlatılmadı):** Sonsuza sayma sorununu hafifletmek için "zehirli ters" (poisoned reverse) yöntemi kullanılır: $z$, $x$'e $y$ üzerinden gidiyorsa $y$'ye $x$ için uzaklığını sonsuz diye bildirir. Bu yöntem iki düğümlü döngüleri önler, ancak üç ya da daha fazla düğümlü döngüleri çözmez.

## 9. Bağlantı Durumu ile Uzaklık Vektörünün Karşılaştırılması

Slayttaki karşılaştırma üç başlık altındadır (ekrandan, 00:50:00):

- **Mesaj karmaşıklığı:** LS'de $n$ yönlendirici için $O(n^2)$ mesaj gönderilir. DV'de mesajlar yalnız komşular arasında değiştirilir; yakınsama süresi değişkendir ve düğüm sayısına bağlıdır.
- **Yakınsama hızı:** LS $O(n^2)$ algoritma ve $O(n^2)$ mesajdır, salınım olabilir. DV'de yakınsama süresi değişkendir; yönlendirme döngüleri ve sonsuza sayma sorunu olabilir.
- **Sağlamlık (robustness):** bir yönlendirici arızalanırsa ya da ele geçirilirse ne olur?
  - LS: yönlendirici yanlış bağlantı maliyeti duyurabilir; ama her yönlendirici yalnız kendi tablosunu hesaplar.
  - DV: yönlendirici yanlış yol maliyeti duyurabilir ("her yere gerçekten düşük maliyetli bir yolum var"); her yönlendiricinin tablosu başkaları tarafından kullanıldığından hata bütün ağa yayılır.

Hoca DV'deki bu durumu "kara delik" (black hole, black-holing) diye açıkladı. Ele geçirilmiş bir yönlendirici, aslında doğrudan bağlantısı olmadığı halde bir yere sıfır maliyetle gidebildiğini duyurur. Komşular tablolarını buna göre günceller, bütün trafik o yönlendirici üzerinden gönderilir ve bütün paketler de tehlikeye girebilir.

## 10. Ölçeklenebilir Yönlendirme ve Özerk Sistemler

### 10.1 İdeal varsayımlar ve gerçek

İnternet ağların ağıdır. Bir ağ bir özerk sisteme, yani bir ISS'ye ait olabilir; başka bir ağ başka bir ISS'ye aittir. Bu yüzden iki tür yönlendirme algoritması vardır: aynı sahibe ait yönlendiriciler arasındaki ISS içi (intra-ISP) yönlendirme ve farklı ISS'ler arasındaki ISS'ler arası (inter-ISP) yönlendirme. ISS içi için OSPF (Open Shortest Path First), ISS'ler arası için BGP (Border Gateway Protocol) işlenecektir. Hoca BGP'yi "internetin yapıştırıcısı" diye tanıttı, çünkü farklı ağları birbirine bağlayan bir şeye ihtiyaç vardır.

Buraya kadarki yönlendirme incelemesi idealleştirilmiştir: bütün yönlendiriciler özdeş ve ağ düz varsayılmıştır. Uygulamada bu doğru değildir:

- **Ölçek:** milyarlarca hedef vardır. Her yönlendiricinin bütün hedefleri yönlendirme tablosunda tutması imkânsızdır. Tablo değişimi de imkânsız olur, çünkü dev tabloların yönlendiriciler arasında dağıtılması bağlantıları boğar.
- **Yönetim özerkliği:** internet ağların ağı olduğundan her ağ yöneticisi (her ISS'nin yöneticisi) kendi ağındaki yönlendirmeyi denetlemek isteyebilir.

### 10.2 Özerk sistemler

İnternetin ölçeklenebilir yönlendirme yaklaşımı, yönlendiricileri "özerk sistem" (autonomous system, AS) denen bölgelerde toplamaktır; özerk sistemlere "domain" de denir (ekrandan, 00:55:00). Bir AS genellikle bir ISS'ye aittir.

- **AS içi (intra-AS, intra-domain):** aynı AS (aynı "ağ") içinde yönlendirme.
  - AS içindeki bütün yönlendiriciler aynı AS içi protokolü çalıştırmalıdır, çünkü ağ tek bir sahibe aittir.
  - Farklı AS'lerdeki yönlendiriciler farklı AS içi protokoller çalıştırabilir.
  - **Ağ geçidi yönlendiricisi (gateway router):** kendi AS'sinin "kenarında" bulunur ve başka AS'lerdeki yönlendiricilere bağlantısı vardır.
- **AS'ler arası (inter-AS, inter-domain):** AS'ler arasında yönlendirme. Ağ geçitleri hem AS içi protokolü (ağ içinde bilgi değişimi için) hem de AS'ler arası protokolü (farklı AS'lerle bilgi değişimi için) çalıştırır.

Slayttaki örnekte AS1, AS2 ve AS3 adlı üç özerk sistem vardır; içlerinde AS içi yönlendirme, kenarlar arasında AS'ler arası yönlendirme yapılır. Her yönlendiricinin iletim tablosu hem AS içi hem AS'ler arası yönlendirme algoritmalarıyla yapılandırılır.

## 11. AS İçi Yönlendirme Protokolleri ve OSPF

### 11.1 Yaygın AS içi protokoller

Slayttaki listeye göre (ekrandan, 01:20:00):

- **RIP (Routing Information Protocol) [RFC 1723]:** klasik uzaklık vektörü protokolüdür; vektörler 30 saniyede bir değiştirilir. Artık yaygın kullanılmamaktadır.
- **EIGRP (Enhanced Interior Gateway Routing Protocol):** uzaklık vektörü tabanlıdır. On yıllarca Cisco'ya özel (proprietary) kaldı, yalnız Cisco yönlendiricilerinde kullanıldı; Cisco 2013'te açmaya karar verdi ve ardından RFC 7868 yayımlandı.
- **OSPF (Open Shortest Path First) [RFC 2328]:** bağlantı durumu yönlendirmesidir. Benzeri olan IS-IS protokolü RFC değil ISO standardıdır, ama esasen OSPF ile aynıdır.

> **Ders sonrası not:** Altyazıda EIGRP'nin açılımı "Exchange Interior Gateway Routing Protocol" diye geçiyor. Slayttaki doğru açılım "Enhanced Interior Gateway Routing Protocol"dur (ekrandan, 01:20:00).

### 11.2 OSPF

En yaygın kullanılan AS içi protokol OSPF'tir.

- "Açık" (open) olması, herkese açık olarak yayımlanmış olması demektir.
- Klasik bağlantı durumu protokolüdür; merkezi (küresel) çalışır. Her yönlendirici OSPF bağlantı durumu duyurularını AS içindeki bütün diğer yönlendiricilere yayar (flood). Bu duyurular TCP ya da UDP kullanılmadan doğrudan IP üzerinden taşınır.
- Birden çok bağlantı maliyeti ölçütü mümkündür: bant genişliği, gecikme.
- Her yönlendiricide tam topoloji bulunur; iletim tablosu bağlantı durumu (Dijkstra) algoritmasıyla hesaplanır.
- Güvenlik: kötü niyetli müdahaleyi önlemek için bütün OSPF mesajlarında kimlik doğrulama yapılır.

### 11.3 Hiyerarşik OSPF

OSPF hiyerarşik bir protokoldür ve iki hiyerarşi seviyesi vardır: yerel alan (local area) ve omurga (backbone) (ekrandan, 01:25:00).

- Bağlantı durumu duyuruları yalnız alan içinde ya da yalnız omurgada yayılır.
- Her düğüm kendi alanının topolojisini ayrıntılı bilir; diğer hedeflere ise yalnız hangi yönden gidileceğini bilir.

Şekilde omurga üzerinde üç alan (area 1, 2, 3) görülür. Yönlendirici rolleri:

- **Alan sınır yönlendiricileri (area border routers):** kendi alanındaki hedeflere uzaklıkları özetler ve omurgaya duyurur.
- **Yerel (iç) yönlendiriciler:** bağlantı durumunu yalnız kendi alanında yayar, yönlendirmeyi yalnız o alan içinde hesaplar ve alan dışına giden paketleri sınır yönlendiricisi üzerinden iletir.
- **Omurga yönlendiricileri:** OSPF'i yalnız omurgayla sınırlı olarak çalıştırır, bütün bölge için değil.
- AS'den başka bir AS'ye çıkış da bir sınır yönlendiricisi üzerinden olur.

## 12. BGP: AS'ler Arası Yönlendirme

### 12.1 BGP'nin işlevi

BGP (Border Gateway Protocol) AS'ler arası yönlendirme protokolüdür ve AS'ler arası yönlendirmenin fiilî (de facto) standardıdır. "İnterneti bir arada tutan yapıştırıcıdır." Bir alt ağın kendi varlığını ve erişebildiği hedefleri internetin geri kalanına duyurmasını sağlar.

BGP her AS'ye iki araç sağlar:

- **eBGP:** komşu AS'lerden alt ağ erişilebilirlik bilgisini alır. Farklı AS'lerin sınır yönlendiricileri (örneğin 1c–2a, 2c–3a) arasında kullanılır.
- **iBGP:** erişilebilirlik bilgisini AS içindeki bütün yönlendiricilere yayar.

### 12.2 BGP duyurusu ve mesajları

Üç AS olsun ve $X$ hedefi AS3'teki bir yönlendiriciye bağlı olsun. AS3'ün sınır yönlendiricisi 3a, $X$'in AS3 üzerinden erişilebilir olduğunu duyurur: "AS3, X". BGP mesajları eşler (peer) arasında TCP bağlantısı üzerinden değiştirilir. Hoca burada OSPF ile farkı hatırlattı: OSPF bilgiyi doğrudan IP üzerinden değiştirir, BGP ise TCP kullanır.

Dört BGP mesaj türü vardır:

- **OPEN:** uzaktaki BGP eşine TCP bağlantısı açar ve gönderen BGP eşinin kimliğini doğrular.
- **UPDATE:** yeni bir yol duyurur (ya da eski yolu geri çeker).
- **KEEPALIVE:** güncelleme olmadığında bağlantıyı canlı tutar; OPEN isteğine onay (ACK) olarak da kullanılır.
- **NOTIFICATION:** önceki mesajdaki hataları bildirir; bağlantıyı kapatmak için de kullanılır.

> **Ders sonrası not:** Hoca BGP mesajlarının tanımlandığı belge için "RFC 4371" dedi. BGP-4'ün tanımlandığı belge büyük olasılıkla RFC 4271'dir.

### 12.3 Yol öznitelikleri

BGP ile duyurulan rota, önek (prefix) ve özniteliklerden (attributes) oluşur (ekrandan, 01:30:00):

- **Önek:** duyurulan hedeftir.
- **İki önemli öznitelik:**
  - **AS-PATH:** önek duyurusunun içinden geçtiği AS'lerin listesi.
  - **NEXT-HOP:** bir sonraki AS'ye giden, AS içindeki belirli yönlendiriciyi gösterir.

Politika tabanlı yönlendirmede rota duyurusunu alan ağ geçidi, içe alma politikasını (import policy) kullanarak duyuruyu kabul eder ya da reddeder. AS politikası, bir yolun komşu AS'lere duyurulup duyurulmayacağını da belirler.

### 12.4 Duyurunun yayılması

$X$, AS3'e bağlıdır; AS3'ün sınır yönlendiricisi bunu AS2'ye duyurur: $X$'e ulaşmak isteyen AS3'e bağlanmalıdır. AS2'nin sınır yönlendiricisi bu kez "AS2, AS3, X" yolunu AS1'e duyurur. Böylece 1c, $X$'e AS2 ve AS3 üzerinden nasıl ulaşılacağını öğrenir. 1c ile 3a arasında doğrudan bağlantı da varsa AS3 aynı hedefi doğrudan AS1'e de duyurur; bu durumda AS1 iki yol öğrenir ve hangi yolu kullanacağını (ve hangisini duyuracağını) politikasına göre özgürce seçer.

### 12.5 Politika örneği: sağlayıcılar ve müşteriler

Şekilde $A$, $B$ ve $C$ sağlayıcı ağlar, $W$, $X$ ve $Y$ müşteri ağlardır. $W$, $A$'nın müşterisidir ve $A$, $W$'ye erişim için duyuru yapar. $X$ iki sağlayıcıya bağlı (dual-homed) bir müşteridir: iki ağa birden bağlıdır. $X$ hiçbir şey duyurmayabilir; çünkü duyurursa gereksiz trafik $X$ üzerinden $B$'ye ulaşabilir. Benzer biçimde sağlayıcılar da bir rotayı duyurup duyurmamayı politikaya göre seçer. <!-- BELİRSİZ: 01:32:30–01:33:00 arasında altyazı bozuk (tekrarlanan "B'ye/A'ya görebilirsiniz"), bu kısımdaki duyuru ayrıntıları çıkarılamadı -->

> **Ek bilgi (derste anlatılmadı):** Sağlayıcı-müşteri politikasının temel kuralı, bir ağın yalnız kendi müşterileri adına geçiş trafiği taşımak istemesidir. Bu yüzden iki sağlayıcıya bağlı bir müşteri, bir sağlayıcıdan öğrendiği rotayı diğerine duyurmaz; duyurursa iki sağlayıcı arasındaki trafik kendi ağından geçer.

## 13. Neden İki Ayrı Yönlendirme Türü?

AS içinde OSPF, AS'ler arasında BGP kullanılır. Bu ayrımın gerekçeleri şunlardır (ekrandan, 01:35:00):

- **Politika:** AS'ler arası yönlendirmede yönetici, trafiğinin nasıl yönlendirileceği ve ağı üzerinden kimin trafik geçireceği üzerinde denetim ister. AS içinde tek bir yönetici olduğundan politika daha az sorundur. Bazı AS'ler belirli trafiğin geçmesine izin verir, bazıları vermez.
- **Ölçek:** hiyerarşik yönlendirme tablo boyutunu küçültür ve güncelleme trafiğini azaltır.
- **Performans:** AS içi yönlendirme performansa odaklanabilir. AS'ler arası yönlendirme ise politikaya odaklanır, çünkü hangi trafiğin geçirileceğine, hangisinin geçirilmeyeceğine karar vermesi gerekir.

BGP rota seçiminde bir yönlendirici bir hedefe birden fazla rota öğrenebilir. AS rotayı şu ölçütlere göre seçer: politika kararına bağlı yerel tercih (local preference) değeri özniteliği, en kısa yol (AS-PATH), en yakın NEXT-HOP; bunlara ek ölçütler de eklenebilir.

> **Ek bilgi (derste anlatılmadı):** "En yakın NEXT-HOP" ölçütü sıcak patates (hot potato) yönlendirmesi olarak bilinir: paket, AS içi maliyeti en düşük olan ağ geçidine gönderilerek kendi ağından olabildiğince çabuk çıkarılır.

## 14. SDN Kontrol Düzlemi

### 14.1 Geleneksel yaklaşım ve SDN

Buraya kadar geleneksel ağ kontrol düzlemi işlendi. İnternet ağ katmanı tarihsel olarak yönlendirici başına dağıtık kontrol yaklaşımıyla gerçeklenmiştir. Bu yapı monolitiktir: yönlendirici anahtarlama donanımını içerir, internet standartlarının (IP, RIP, IS-IS, OSPF, BGP) özel gerçeklemelerini ya da Cisco IOS gibi özel yönlendirici işletim sistemlerini çalıştırır. Farklı ağ katmanı işlevleri için farklı ara kutular (middlebox) vardır: güvenlik duvarları, yük dengeleyiciler, NAT kutuları, IDS ve IPS gibi. Yaklaşık 2005'ten itibaren ağ kontrol düzlemini yeniden düşünmeye ilgi arttı, çünkü dağıtık yapının yönetimi çok zorlaşmıştı.

Yönlendirici başına kontrol düzleminde, daha önce görülen şekildeki gibi, her yönlendirici gelen datagramı başlığına göre iletmekten sorumludur ve kendi yerel iletim tablosunu tutar. Kontrol düzleminde de her yönlendirici, yerel iletim tablosunu bir yönlendirme algoritmasıyla güncellemekten sorumludur. SDN'de ise yine her yönlendirici yerel iletim tablosunu kullanır, ama bu tablo uzaktaki bir denetleyici (remote controller) tarafından güncellenir; yönetim merkezidir.

### 14.2 Neden mantıksal olarak merkezi bir kontrol düzlemi?

- Ağ yönetimi daha kolaydır; yönlendirici yanlış yapılandırmalarından kaçınılır, trafik akışlarında daha büyük esneklik elde edilir.
- Tablo tabanlı iletim yapılır; hatırlanacağı gibi OpenFlow API'leriyle yönlendiriciler programlanabilir.
- Merkezi programlama daha kolaydır: tablo merkezde hesaplanıp bütün yönlendiricilere dağıtılır. Dağıtık programlama daha zordur, çünkü her yönlendirici kendi tablosunu hesaplayıp güncellemelidir.
- SDN açıktır, tescilli (proprietary) değildir; merkezi kontrol düzlemini gerçeklemek herkese açıktır.

### 14.3 Ana bilgisayardan PC devrimine benzetmesi

Hoca bunu bilgisayarların gelişimine benzetti (ekrandan, 01:40:00). Erken dönemde özelleşmiş donanım, onun üzerinde özelleşmiş işletim sistemi ve en üstte özelleşmiş uygulamalar vardı. Bu yapı dikey olarak bütünleşik, kapalı ve tescillidir; yeniliğe çok yavaş açıktır ve kapalı olduğu için küçük bir sektördür. Bugün ise açık bir mikroişlemci (örneğin Intel) ve açık arayüzler vardır; herhangi bir mikroişlemciye her türlü işletim sistemi ve pek çok uygulama kurulabilir. Yapı yatay hale gelmiştir; çok sayıda açık arayüz ve katkı sayesinde yenilik hızlıdır ve dev bir sektör oluşmuştur. SDN de ağ dünyasında aynı dönüşümü hedefler.

### 14.4 Trafik mühendisliği örneği

Geleneksel ağda trafik mühendisliğini yönetmek zordur. İletim tablosu uzaklık vektörü ya da bağlantı durumu algoritmasıyla güncellendiğinden trafik hep aynı rotayı izler. Bir trafiği bir rotadan, başka bir trafiği başka bir rotadan göndermek istenirse yeni bir algoritma gerekir. Yük dengeleme için trafiği iki rotaya bölüp paralel göndermek de geleneksel yönlendirmede imkânsızdır. Merkezi yönlendirme mekanizmasıyla ise kırmızı trafik bir yönden, mavi trafik diğer yönden gönderilebilir; her iletim tablosu merkezi denetleyici tarafından güncellenir.

### 14.5 SDN'nin bileşenleri

Veri düzleminde her yönlendiricide bir istemci ajan bulunur ve uzaktaki denetleyiciye bağlıdır. Kontrol düzleminde, denetleyicinin üzerinde yönlendirme uygulaması, erişim denetimi uygulaması, yük dengeleyici gibi pek çok uygulama çalışabilir. Bu uygulamaları gerçeklemek geleneksel ağlara göre daha kolaydır. Genel ilkeler:

- Akış tabanlı iletim: örneğin her yerel iletim tablosunu güncellemek için OpenFlow kullanılabilir.
- Kontrol düzlemi ile veri düzleminin ayrılması: kontrol düzlemi, veri düzlemi anahtarlarının dışındadır.
- Programlanabilir kontrol uygulamaları: bilgisayarların evrimine benzer.

**Veri düzlemi anahtarları** (ekrandan, 01:45:00):

- Genelleştirilmiş veri düzlemi iletimini donanımda gerçekleyen hızlı, basit, sıradan (commodity) anahtarlardır.
- Akış (iletim) tablosu denetleyicinin gözetiminde hesaplanır ve kurulur.
- Tablo tabanlı anahtar denetimi için bir API vardır (örneğin OpenFlow); neyin denetlenebilir olup neyin olmadığını tanımlar.
- Denetleyiciyle iletişim protokolü de OpenFlow'dur.

**SDN denetleyicisi (ağ işletim sistemi):** ağ durum bilgisini tutar, sistemin kalbidir. Bir işletim sistemine benzer: ağ denetim uygulamalarıyla kuzeye dönük (northbound) API'ler üzerinden, ağ anahtarlarıyla güneye dönük (southbound) API'ler üzerinden etkileşir. Başarım, ölçeklenebilirlik, hata toleransı ve sağlamlık için dağıtık bir sistem olarak gerçeklenir.

**Ağ denetim uygulamaları:** en üstte yer alır ve kontrolün "beyni"dir. Denetim işlevlerini, SDN denetleyicisinin sağladığı alt seviye kuzeye dönük API'leri kullanarak gerçekler. Ayrıştırılmıştır (unbundled): yönlendirici üreticisinden ve SDN denetleyicisinden farklı üçüncü taraf şirketlerce sağlanabilir. Yani ağ denetim uygulaması katmanında her türlü uygulama geliştirilebilir.

**SDN denetleyicisinin iç bileşenleri:**

- **İletişim katmanı:** SDN denetleyicisi ile denetlenen anahtarlar arasındaki iletişim (OpenFlow, SNMP).
- **Ağ çapında durum yönetimi:** ağ bağlantılarının, anahtarların ve hizmetlerin durumu; dağıtık bir veritabanı.
- **Ağ denetim uygulamalarına arayüz katmanı:** uygulamaların kullandığı API soyutlaması.

## 15. OpenFlow ve SDN Denetleyicileri

### 15.1 OpenFlow protokolü

OpenFlow denetleyici ile anahtarlar arasında çalışır. Hoca, mesaj değişiminde TCP'nin güvenlik ve kimlik doğrulama için kullanıldığını söyledi; mesajlar isteğe bağlı olarak şifrelenebilir. Üç OpenFlow mesaj sınıfı vardır: denetleyiciden anahtara, anahtardan denetleyiciye (asenkron) ve simetrik. OpenFlow protokolü, genelleştirilmiş iletim eylemlerini belirtmek için kullanılan OpenFlow API'sinden farklıdır.

**Denetleyiciden anahtara mesajlar:**

- **Features:** denetleyici anahtarın özelliklerini sorgular, anahtar cevap verir.
- **Configure:** denetleyici anahtarın yapılandırma parametrelerini sorgular ya da ayarlar.
- **Modify-state:** OpenFlow tablosunda akış girdisi ekler, siler ya da değiştirir.
- **Packet-out:** denetleyici bu paketi anahtarın belirli bir portundan dışarı gönderebilir.

**Anahtardan denetleyiciye mesajlar:**

- **Packet-in:** paketi denetleyiciye aktarır.
- **Flow-removed:** anahtardaki bir akış tablosu girdisinin silindiğini bildirir.
- **Port status:** denetleyiciyi anahtarın bir portundaki değişiklik hakkında bilgilendirir.

### 15.2 Denetim ve veri düzlemi etkileşimi örneği

Ağda S1–S4 adlı dört anahtar vardır (ekrandan, 01:50:00). Adımlar:

1. S1, S2 ile arasındaki bağlantıda arıza yaşar ve denetleyiciyi OpenFlow port durum (port status) mesajıyla uyarır.
2. SDN denetleyicisi OpenFlow mesajını alır ve bağlantı durumu bilgisini günceller.
3. Rota değişikliklerine bağlı olarak Dijkstra bağlantı durumu yönlendirme uygulaması çağrılır.
4. Dijkstra uygulaması denetleyicideki ağ çizgesi ve bağlantı durumu bilgisine erişip yeni rotaları hesaplar.
5. Bağlantı durumu yönlendirme uygulaması, SDN denetleyicisindeki akış tablosu hesaplama bileşeniyle etkileşir; bu bileşen gereken yeni akış tablolarını hesaplar.
6. Güncellenen tablolar, bağlantı arızasından etkilenen anahtarlara dağıtılır.

<!-- BELİRSİZ: 3., 4. ve 6. adımların ayrıntısı altyazıdan ve slayttaki 5. adım metninden kuruldu; diğer adımların slayt metnini gösteren kare yok -->

### 15.3 Denetleyici örnekleri ve güçlükler

**OpenDaylight (ODL):** kuzeye dönük API tarafında trafik mühendisliği, güvenlik duvarı, yük dengeleme gibi ağ orkestrasyonları ve uygulamaları bulunur. Güneye dönük API tarafında OpenFlow, NETCONF, SNMP ve OVSDB protokolleri vardır. Arada hizmetler, temel ağ işlevleri ve mesaj soyutlama katmanı yer alır.

**ONOS:** yapısı farklıdır; konaklar, yollar, akış kuralları, topoloji ve cihazlar soyutlamaları ile güneye dönük soyutlama protokolleri bağlantı, konak ve akış bilgisini tutar. Denetim uygulamaları denetleyiciden ayrıdır ve hizmetler yüksek seviyede, "nasıl" yerine "ne" yapılacağı biçiminde belirtilir.

**SDN'nin güçlükleri:** kontrol düzlemini sağlamlaştırmak, yani güvenilir, dayanıklı, başarımı ölçeklenebilir ve güvenli bir dağıtık sistem kurmak; arızalara dayanıklılık için güvenilir dağıtık sistemler kuramından yararlanmak; güvenilirlik ve güvenlik.

Hoca, zaman kısıtı nedeniyle bölümün kalan yaklaşık 8–10 slaytının öğrencilerce kendi başlarına incelenmesini istedi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): Kenar maliyetleri $c_{u,v}=2$, $c_{u,x}=1$, $c_{u,w}=5$, $c_{v,w}=3$, $c_{v,x}=2$, $c_{x,w}=3$, $c_{x,y}=1$, $c_{y,w}=1$, $c_{w,z}=5$, $c_{y,z}=2$ olan çizgede Dijkstra algoritmasıyla $u$'dan bütün düğümlere en düşük maliyetli yolları bulun ve $u$'nun iletim tablosunu yazın.

> **Çözüm (derste verildi):** Seçim sırası $u, x, y, v, w, z$ ($v$ ile $y$ eşit olduğunda hoca $y$'yi seçti). Sonuç: $D(v)=2$ ($u$), $D(x)=1$ ($u$), $D(y)=2$ ($x$), $D(w)=3$ ($y$), $D(z)=4$ ($y$). İletim tablosu: $v \to (u,v)$; $x, y, w, z \to (u,x)$. Ayrıntılı adımlar Bölüm 4.4'tedir.

**Soru 2** (derste sözlü, 00:25:32): Kenar maliyetleri $c_{u,v}=7$, $c_{u,w}=3$, $c_{u,x}=5$, $c_{w,v}=3$, $c_{w,x}=4$, $c_{w,y}=8$, $c_{x,y}=7$, $c_{x,z}=9$, $c_{v,y}=4$, $c_{y,z}=2$ olan çizgede $u$'dan bütün düğümlere en düşük maliyetli yolları bulun. <!-- BELİRSİZ: çizgenin karesi yok; kenarlar altyazıdaki toplamlardan çıkarıldı -->

> **Çözüm (derste verildi):** Seçim sırası $u, w, x, v, y, z$. Sonuç: $w=3$ ($u$), $x=5$ ($u$), $v=6$ ($w$), $y=10$ ($v$), $z=12$ ($y$). Python ile doğrulandı. Ayrıntılı adımlar Bölüm 4.5'tedir.

**Soru 3** (ekrandan, 00:35:00): $u$'nun komşuları $v$, $x$, $w$ ve bunların $z$ için bildiği en düşük maliyetler $D_v(z)=5$, $D_x(z)=3$, $D_w(z)=3$ ise, $c_{u,v}=2$, $c_{u,x}=1$, $c_{u,w}=5$ için Bellman-Ford denklemiyle $D_u(z)$'yi ve sonraki atlamayı bulun.

> **Çözüm (derste verildi):** $D_u(z) = \min\{2+5,\ 1+3,\ 5+3\} = \min\{7, 4, 8\} = 4$. En küçük değer $x$ üzerinden geldiğinden $z$'ye sonraki atlama $x$'tir.

**Soru 4** (ekrandan, 00:40:00): Bölüm 7'deki ızgara ağda ($a$–$b$ 8, diğer bütün bağlantılar 1, $c$–$f$ bağlantısı yok) $t=0$ vektörlerinden sonra $b$'nin birinci yinelemede hesapladığı uzaklık vektörünü bulun.

> **Çözüm (derste kısmen verildi):** Derste $D_b(a)=8$ ve $D_b(c)=1$ hesaplandı, $g$ ve $i$'nin hâlâ bilinmediği söylendi. Tamamı (python ile doğrulandı): $D_b = (a{:}\,8,\ b{:}\,0,\ c{:}\,1,\ d{:}\,2,\ e{:}\,1,\ f{:}\,2,\ g{:}\,\infty,\ h{:}\,2,\ i{:}\,\infty)$.

**Soru 5** (derste sözlü, 00:47:43): Üç düğümlü ağda $x$–$y$ maliyeti 4'ten 60'a çıktığında $y$ neden $x$'e giden yolu yanlış hesaplar, buna ne ad verilir?

> **Çözüm (derste verildi):** $z$ daha önce $x$'e 5 maliyetle gidebildiğini bildirmiştir, ama bu yol $y$ üzerinden geçer. $y$ bunu bilmediğinden $D_y(x) = \min\{60,\ 1 + 5\} = 6$ alıp $z$ üzerinden gitmeye çalışır; $y$ ile $z$ değerlerini birbirine bakarak adım adım artırır. Buna sonsuza sayma (count-to-infinity) sorunu denir: kötü haber yavaş yayılır.

## Dersin Toparlaması

Bu derste ağ katmanının kontrol düzlemindeki yönlendirme konusu baştan sona işlendi. Önce yönlendirmenin amacı ("iyi" yolu bulmak) ve ağın çizge soyutlaması tanıtıldı. Ardından iki temel algoritma ailesi karşılaştırıldı: her yönlendiricinin tam topolojiyi bilip Dijkstra ile kendi tablosunu hesapladığı bağlantı durumu (LS) algoritmaları ve komşular arasında uzaklık vektörlerinin Bellman-Ford denklemiyle yinelemeli olarak güncellendiği uzaklık vektörü (DV) algoritmaları. İki Dijkstra örneği tablo üzerinden çözüldü; DV'de iyi haberin hızlı, kötü haberin yavaş yayıldığı ve ele geçirilmiş bir yönlendiricinin kara delik oluşturabileceği gösterildi.

Sonra bu idealleştirilmiş modelden gerçek internete geçildi. Ölçek ve yönetim özerkliği gereği yönlendiriciler özerk sistemlerde toplanır; AS içinde RIP, EIGRP ve özellikle hiyerarşik OSPF, AS'ler arasında ise politika tabanlı BGP kullanılır. Son olarak kontrolü yönlendiricilerden alıp mantıksal olarak merkezi bir denetleyiciye taşıyan SDN anlatıldı: veri düzlemi anahtarları, SDN denetleyicisi, kuzeye ve güneye dönük API'ler, OpenFlow mesajları, bir bağlantı arızasında denetleyicinin yeni tabloları hesaplayıp dağıtması ve OpenDaylight ile ONOS denetleyicileri. Bölümün kalan slaytları öğrencilerin kendi incelemesine bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
