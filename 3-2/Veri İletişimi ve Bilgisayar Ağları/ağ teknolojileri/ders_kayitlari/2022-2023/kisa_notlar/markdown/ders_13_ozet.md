# Ders 13 Çalışma Özeti

## Genel Konular

- Kontrol düzlemi ve yönlendirme protokollerinin amacı
  - Ağ katmanı veri düzlemi ve kontrol düzlemi olarak ikiye ayrılmıştı; veri düzlemi önceki derslerde bitmiş, kontrol düzlemine bir önceki derste başlanmıştı.
  - Yönlendirme protokolünün amacı, gönderen konaktan alıcı konağa yönlendiriciler ağı üzerinden "iyi" yolları (rotaları) belirlemektir (ekrandan, 00:10:00).
  - Yol (path): bir paketin kaynak konaktan son hedefe giderken geçtiği yönlendiriciler dizisidir. Yolu bulmak yönlendiriciler arasında eşgüdüm gerektirir.
  - "İyi" ifadesinin anlamı tanımlanmalıdır: en ucuz, en hızlı ya da en az tıkanık yol. Yönlendirme, ağ alanındaki ilk on sorundan biri olarak anılır.
- Ağın çizge (graf) soyutlaması
  - Çizge $G = (N, E)$: $N$ yönlendiriciler kümesi ($u, v, w, x, y, z$), $E$ bağlantılar kümesi ($(u,v), (u,x), (v,x), (v,w), (x,w), (x,y), (w,y), (w,z), (y,z)$ ve $(u,w)$).
  - $c_{a,b}$: $a$ ile $b$ arasındaki doğrudan bağlantının maliyeti; örnekte $c_{w,z} = 5$. Doğrudan bağlantı yoksa maliyet $\infty$ alınır.
  - Maliyeti ağ işletmecisi ya da ISS belirler: hep 1 olabilir, bant genişliğiyle ya da tıkanıklıkla ters orantılı olabilir.
- Yönlendirme algoritmalarının sınıflandırılması (ekrandan, 00:15:00)
  - Küresel (global): bütün yönlendiriciler tam topolojiyi ve bağlantı maliyetlerini bilir; bağlantı durumu (link state, LS) algoritmaları.
  - Merkezi olmayan (decentralized): yinelemeli hesaplama ve komşularla bilgi değişimi; yönlendiriciler başta yalnız komşularına olan maliyeti bilir; uzaklık vektörü (distance vector, DV) algoritmaları.
  - Statik: rotalar zamanla çok yavaş değişir. Dinamik: rotalar daha hızlı değişir, periyodik güncelleme ya da bağlantı maliyeti değişimine tepki olarak güncellenir.
- Dijkstra'nın bağlantı durumu algoritması
  - Merkezi/küresel: her düğüm bütün topolojiyi bilir; bu, bağlantı durumu yayınıyla (link state broadcast) sağlanır, böylece bütün düğümler aynı bilgiye sahip olur.
  - Bir düğümden diğer bütün düğümlere en düşük maliyetli yolları hesaplar ve o düğümün iletim tablosunu verir. Yinelemelidir: $k$ yinelemeden sonra $k$ hedefin en düşük maliyetli yolu bilinir.
  - Gösterim: $c_{x,y}$ doğrudan bağlantı maliyeti; $D(v)$ kaynaktan $v$'ye o anki en düşük maliyet tahmini; $p(v)$ yol üzerindeki önceki düğüm; $N'$ en düşük maliyetli yolu kesin bilinen düğümler kümesi.
  - Güncelleme kuralı: $D(v) = \min(D(v),\ D(w) + c_{w,v})$ (ekrandan, 00:20:00).
  - Karmaşıklık: $n$ düğüm için $n(n+1)/2$ karşılaştırma, yani $O(n^2)$; daha verimli gerçeklemelerle $O(n \log n)$. Mesaj karmaşıklığı $O(n^2)$ (ekrandan, 00:30:00).
  - Bağlantı maliyetleri trafik miktarına bağlıysa rota salınımı (oscillation) olabilir.
- Bellman-Ford denklemi ve uzaklık vektörü algoritması
  - $D_x(y) = \min_v \{ c_{x,v} + D_v(y) \}$: $x$'ten $y$'ye en düşük maliyet, komşu $v$'ye doğrudan maliyet ile $v$'nin $y$'ye tahmini en düşük maliyetinin toplamlarının en küçüğüdür.
  - Her düğüm zaman zaman kendi uzaklık vektörünü komşularına gönderir; yeni vektör alan düğüm kendi vektörünü Bellman-Ford ile günceller, değişiklik varsa komşularına bildirir.
  - Özellikleri: yinelemeli, eşzamansız (asenkron), dağıtık ve kendiliğinden duran (self-stopping) bir algoritmadır.
  - İyi haber hızlı yayılır (maliyet düşüşü), kötü haber yavaş yayılır (maliyet artışı, sonsuza sayma sorunu).
- LS ve DV karşılaştırması (ekrandan, 00:50:00)
  - Mesaj karmaşıklığı, yakınsama hızı ve sağlamlık (robustness) açısından karşılaştırma; DV'de bozuk ya da ele geçirilmiş bir yönlendiricinin "kara delik" (black-holing) oluşturması.
- Ölçeklenebilir yönlendirme: özerk sistemler (AS)
  - Gerçekte yönlendiriciler özdeş, ağ düz değildir; milyarlarca hedef vardır ve hepsi tek tabloda tutulamaz. Ayrıca her ağ yöneticisi kendi ağındaki yönlendirmeyi denetlemek ister.
  - Yönlendiriciler "özerk sistem" (autonomous system, AS, diğer adıyla "domain") denen bölgelerde toplanır (ekrandan, 00:55:00).
  - AS içi (intra-AS) ve AS'ler arası (inter-AS) yönlendirme; ağ geçidi yönlendiricileri (gateway router) her ikisini de çalıştırır.
- AS içi yönlendirme protokolleri (ekrandan, 01:20:00)
  - RIP (RFC 1723): klasik DV, vektörler 30 saniyede bir değiştirilir, artık yaygın kullanılmaz.
  - EIGRP (RFC 7868): DV tabanlı, uzun süre Cisco'ya özeldi, 2013'te açıldı.
  - OSPF (RFC 2328): bağlantı durumu tabanlı; IS-IS (ISO standardı) esasen OSPF ile aynıdır.
- OSPF
  - Açık (open), klasik bağlantı durumu protokolü; bağlantı durumu duyuruları TCP/UDP yerine doğrudan IP üzerinden taşınır.
  - Birden çok maliyet ölçütü (bant genişliği, gecikme) kullanılabilir; her yönlendirici tam topolojiyi tutup Dijkstra ile iletim tablosunu hesaplar; bütün mesajlar kimlik doğrulamalıdır.
  - Hiyerarşik OSPF: iki seviye, yerel alan (area) ve omurga (backbone); alan sınır yönlendiricileri, iç yönlendiriciler ve omurga yönlendiricileri (ekrandan, 01:25:00).
- BGP (Border Gateway Protocol)
  - AS'ler arası fiilî standart protokol; "interneti bir arada tutan yapıştırıcı".
  - eBGP komşu AS'lerden alt ağ erişilebilirlik bilgisini alır; iBGP bu bilgiyi AS içindeki bütün yönlendiricilere yayar.
  - BGP mesajları eşler (peer) arasında TCP bağlantısı üzerinden değiştirilir. Dört mesaj türü: OPEN, UPDATE, KEEPALIVE, NOTIFICATION.
  - Duyurulan rota = önek + öznitelikler; iki önemli öznitelik AS-PATH ve NEXT-HOP (ekrandan, 01:30:00).
  - Politika tabanlı yönlendirme: içe alma (import) politikası, sağlayıcı ve müşteri ağları, iki sağlayıcıya bağlı (dual-homed) müşteri.
  - Rota seçimi: yerel tercih değeri, en kısa AS-PATH, en yakın NEXT-HOP ve ek ölçütler.
- SDN kontrol düzlemi
  - Geleneksel yaklaşımda her yönlendirici kendi kontrol düzlemini çalıştırır (yönlendirici başına kontrol); SDN'de iletim tabloları uzaktaki mantıksal olarak merkezi bir denetleyici tarafından hesaplanıp kurulur.
  - Ana bilgisayardan PC'ye geçiş benzetmesi: dikey, kapalı yapıdan yatay, açık arayüzlü yapıya geçiş (ekrandan, 01:40:00).
  - Bileşenler: veri düzlemi anahtarları, SDN denetleyicisi (ağ işletim sistemi), ağ denetim uygulamaları; kuzeye dönük (northbound) ve güneye dönük (southbound) API'ler (ekrandan, 01:45:00).
  - OpenFlow protokolü: denetleyiciden anahtara, anahtardan denetleyiciye ve simetrik mesajlar; bağlantı kopması örneğinde denetim/veri düzlemi etkileşimi (ekrandan, 01:50:00).
  - OpenDaylight ve ONOS denetleyicileri; SDN'nin güçlükleri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yönlendirmenin iki anahtar kavramı: "yol" ve "iyi"
  - Yol yönlendiriciler dizisidir; "iyi"nin ne olduğu (ucuz, hızlı, tıkanıklığı az) önceden tanımlanmalıdır. Yönlendirme protokolü kaynaktan hedefe iyi bir yol bulmaktır.
- Dijkstra örneğinin tablo üzerinden adım adım çözülmesi
  - Hoca iki ayrı çizgede $N'$ kümesinin nasıl büyüdüğünü ve her adımda $D(v), p(v)$ değerlerinin nasıl güncellendiğini tek tek gösterdi; sonuçta $u$'nun iletim tablosu elde edilir.
- DV'de "kötü haber yavaş yayılır"
  - Maliyet düştüğünde güncelleme birkaç adımda biter, maliyet arttığında ise yönlendiriciler birbirinin eski bilgisine güvenerek döngüye girer (sonsuza sayma).
- Ele geçirilmiş yönlendirici ve kara delik
  - DV'de bir yönlendirici "her yere sıfır maliyetle gidebilirim" diye duyurursa komşular bunu kabul eder, bütün trafik o yönlendiriciye akar ve paketler tehlikeye girer.
- İki ayrı yönlendirme türünün gerekçesi: ölçeklenebilirlik ve yönetim özerkliği
  - AS içinde tek yönetici olduğundan performansa odaklanılır; AS'ler arasında ise hangi trafiğin geçirileceğine dair politika belirleyicidir.
- OSPF doğrudan IP üzerinden, BGP ise TCP üzerinden çalışır
  - Hoca bu farkı BGP mesajlarını anlatırken özellikle hatırlattı.
- SDN'de merkezi yönetimin kolaylığı
  - Tablo bir kez merkezde hesaplanıp bütün yönlendiricilere dağıtılır; trafik mühendisliği (örneğin kırmızı ve mavi trafiği farklı yollardan göndermek) geleneksel yönlendirmeye göre çok daha kolaydır.

## Kısa Tekrar Notları

- Yönlendirme protokolü: kaynaktan hedefe "iyi" yolu bulur; yol = yönlendiriciler dizisi.
- Çizge $G=(N,E)$; $c_{a,b}$ bağlantı maliyeti; doğrudan bağlantı yoksa $\infty$.
- Küresel = bağlantı durumu (LS, Dijkstra); merkezi olmayan = uzaklık vektörü (DV, Bellman-Ford).
- Dijkstra: $D(v) = \min(D(v), D(w) + c_{w,v})$; $O(n^2)$, verimli gerçeklemede $O(n\log n)$; mesaj $O(n^2)$.
- Birinci örnekte $u$'dan maliyetler: $v=2$, $x=1$, $y=2$, $w=3$, $z=4$; $v$ dışındaki bütün hedeflere $(u,x)$ bağlantısıyla gidilir.
- İkinci örnekte $u$'dan maliyetler: $w=3$, $x=5$, $v=6$, $y=10$, $z=12$.
- Bellman-Ford: $D_x(y) = \min_v \{c_{x,v} + D_v(y)\}$; örnekte $D_u(z) = \min(2+5,\ 1+3,\ 5+3) = 4$, sonraki atlama $x$.
- DV: yinelemeli, eşzamansız, dağıtık, kendiliğinden duran; iyi haber hızlı, kötü haber yavaş (sonsuza sayma).
- AS içi: RIP (DV, 30 s), EIGRP (DV, eskiden Cisco'ya özel), OSPF (LS, IP üzerinden, hiyerarşik), IS-IS.
- AS'ler arası: BGP; eBGP/iBGP; TCP üzerinden; OPEN, UPDATE, KEEPALIVE, NOTIFICATION; AS-PATH ve NEXT-HOP.
- AS içi performansa, AS'ler arası politikaya odaklanır.
- SDN: merkezi denetleyici, kuzeye dönük API (uygulamalar), güneye dönük API (anahtarlar, OpenFlow); OpenDaylight, ONOS.

## Detaylı Açıklamalar

- Dijkstra birinci örnek (ekrandan, 00:25:00)
  - Çizge: $c_{u,v}=2$, $c_{u,x}=1$, $c_{u,w}=5$, $c_{v,w}=3$, $c_{v,x}=2$, $c_{x,w}=3$, $c_{x,y}=1$, $c_{y,w}=1$, $c_{w,z}=5$, $c_{y,z}=2$.
  - Başlangıç ($N'=\{u\}$): $D(v)=2$, $D(w)=5$, $D(x)=1$, $D(y)=D(z)=\infty$. En küçük $x$ seçilir.
  - $x$ eklenince: $D(v)=\min(2, 1+2)=2$ kalır, $D(w)=\min(5, 1+3)=4$ (önceki $x$), $D(y)=1+1=2$ (önceki $x$). Hoca eşit olan $v$ ve $y$ arasından $y$'yi seçti.
  - $y$ eklenince: $D(w)=\min(4, 2+1)=3$ (önceki $y$), $D(z)=2+2=4$ (önceki $y$). Sonra $v$ eklenir; $v$ üzerinden $w$ için $2+3=5 > 3$, değişmez.
  - $w$ eklenince $z$ için $3+5=8 > 4$, değişmez; en son $z$ eklenir.
  - En düşük maliyetli yol ağacı: $u$–$v$, $u$–$x$–$y$–$w$, $u$–$x$–$y$–$z$. $u$'nun iletim tablosu: $v$ için $(u,v)$; $x$, $y$, $w$, $z$ için $(u,x)$.
  - Slayttaki tablonun son satırında hedef "x" yazıyor; çizgeye göre bu satır büyük olasılıkla $z$ olmalıdır (ekrandan, 00:25:00).
- Dijkstra ikinci örnek
  - Hocanın okuduğu değerlere göre kenarlar: $c_{u,v}=7$, $c_{u,w}=3$, $c_{u,x}=5$, $c_{w,v}=3$, $c_{w,x}=4$, $c_{w,y}=8$, $c_{x,y}=7$, $c_{x,z}=9$, $c_{v,y}=4$, $c_{y,z}=2$. <!-- BELİRSİZ: bu çizgenin karesi yok; kenarlar altyazıdaki toplamlardan çıkarıldı, x–v kenarına dair söylenen "5, 9, 12" anlaşılamadı -->
  - Seçim sırası $u, w, x, v, y, z$; sonuç: $w=3$ ($u$), $x=5$ ($u$), $v=6$ ($w$), $y=10$ ($v$), $z=12$ ($y$). Sonuç python ile doğrulandı.
- Rota salınımı
  - Dört yönlendirici ($a$–$d$), hedef $a$; bağlantı maliyetleri yönlü ve taşıdıkları trafiğe bağlı. Bir trafik değeri $e<1$ olduğundan saat yönünde ve tersinde toplam maliyetler sırayla değişir, her hesaplamada rotalar yön değiştirir. <!-- BELİRSİZ: senaryodaki maliyet değerleri altyazıda bozuk, karesi yok -->
- Bellman-Ford örneği (ekrandan, 00:35:00)
  - $u$'nun komşuları $v, x, w$; $z$ için $D_v(z)=5$, $D_x(z)=3$, $D_w(z)=3$.
  - $D_u(z) = \min\{c_{u,v}+D_v(z),\ c_{u,x}+D_x(z),\ c_{u,w}+D_w(z)\} = \min\{2+5,\ 1+3,\ 5+3\} = 4$; en küçüğü veren komşu $x$ olduğundan $z$'ye sonraki atlama $x$'tir.
- Uzaklık vektörü örneği (ekrandan, 00:40:00)
  - $3\times3$ ızgara: $a$–$b$ 8, $b$–$c$ 1, $a$–$d$ 1, $b$–$e$ 1, $d$–$e$ 1, $e$–$f$ 1, $d$–$g$ 1, $e$–$h$ 1, $f$–$i$ 1, $g$–$h$ 1, $h$–$i$ 1; $c$–$f$ bağlantısı yok ("asimetriler": eksik bağlantı ve büyük maliyet).
  - $t=0$'da $a$'nın vektörü: $D_a(a)=0$, $D_a(b)=8$, $D_a(d)=1$, diğerleri $\infty$.
  - $b$, $a$, $c$ ve $e$'den vektör alıp hesaplar: $D_b(a)=8$, $D_b(c)=1$, $D_b(d)=2$, $D_b(e)=1$, $D_b(f)=2$, $D_b(h)=2$; $g$ ve $i$ hâlâ $\infty$ (python ile doğrulandı).
  - $c$ yalnız $b$'den alır: $D_c(a)=1+8=9$, $D_c(e)=2$.
  - Bilgi yayılımı: $c$'nin durumu $t=0$'da yalnız $c$'dedir; her yinelemede bir atlama daha uzağa ulaşır, dördüncü adımda bütün ağı kaplar.
- Bağlantı maliyeti değişimi
  - Üç düğüm $x, y, z$; $x$–$y$ maliyeti 4'ten 1'e düşünce $y$ hemen güncelleyip bildirir; $z$ $x$'e maliyetini 5'ten 2'ye indirir; $y$'nin değeri artık değişmez. İyi haber iki adımda yayılır.
  - $x$–$y$ maliyeti 4'ten 60'a çıkınca $y$, $z$'nin eski "5" bilgisine güvenip $z$ üzerinden gitmeye çalışır; $y$ ile $z$ birbirine bakarak değerlerini adım adım artırır. Buna sonsuza sayma (count-to-infinity) denir.
  - Ders sonrası not: Hoca $y$'nin değerini 5'e güncellediğini söyledi; Bellman-Ford'a göre $D_y(x)=\min(60,\ 1+5)=6$ olur. <!-- BELİRSİZ: x–z maliyeti altyazıda "9" diye geçiyor; karesi yok -->
- BGP duyurusu
  - $X$ alt ağı AS3'e bağlıdır; AS3'ün sınır yönlendiricisi "AS3, X" duyurur; AS2 bunu "AS2, AS3, X" olarak AS1'e iletir. AS1 ile AS3 arasında doğrudan bağlantı varsa AS1 iki yol öğrenir ve politikaya göre birini seçer.
  - Sağlayıcı ağlar ($A$, $B$, $C$) ve müşteri ağlar ($W$, $X$, $Y$): iki sağlayıcıya bağlı $X$, gereksiz geçiş trafiği taşımamak için $B$'den $C$'ye rota duyurmaz.
- SDN bağlantı kopması örneği (ekrandan, 01:50:00)
  - S1 ile S2 arasındaki bağlantı kopar; S1 OpenFlow port durum mesajıyla denetleyiciyi uyarır; denetleyici bağlantı durumu bilgisini günceller; Dijkstra uygulaması çağrılır, yeni rotalar hesaplanır; akış tablosu hesaplama bileşeni yeni tabloları hesaplar ve etkilenen anahtarlara dağıtır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
