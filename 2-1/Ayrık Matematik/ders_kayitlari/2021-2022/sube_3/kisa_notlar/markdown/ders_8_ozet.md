# Ders 8 Çalışma Özeti

## Genel Konular

- Graf tanımı ve temel kavramlar
  - Bir graf $G=(V,E)$ biçiminde düğümler (vertex) kümesi $V$ ile kenarlar (edge) kümesi $E$'den oluşan bir ikilidir. Her kenar iki düğümü birbirine bağlar.
  - Bir düğümden çıkıp başka düğümleri dolaşarak aynı düğüme dönülebiliyorsa bu bir kapalı döngüdür. Ağaçlar grafların özel bir alt türüdür; ağaçta kapalı döngü yoktur.
  - Hiçbir kenarı olmayan düğüme yalıtılmış düğüm (isolated vertex) denir.
  - Paralel kenar: aynı iki düğüm arasında birden fazla kenar olmasıdır. Döngü (loop): başlangıç ve bitiş noktası aynı düğüm olan kenardır (ekrandan, 00:20:00).
- Graf türleri (ekrandan, 00:25:00)
  - Basit graf: yönsüz, paralel kenar yok, döngü yok.
  - Çoklu graf (multigraph): yönsüz, paralel kenar var, döngü yok.
  - Sözde graf (pseudograph): yönsüz, paralel kenar var, döngü var.
  - Yönlü graf (directed graph, digraph): yönlü, paralel kenar yok, döngü var.
  - Yönlü çoklu graf: yönlü, paralel kenar var, döngü var.
  - Ağırlıklı graf (weighted graph): kenarlara uzaklık, maliyet, kapasite gibi bir değer verilmiş graftır.
- Graflarla benzerlik problemi (ekrandan, 00:30:00 ve 00:35:00)
  - Beş programın satır sayısı, `return` sayısı ve fonksiyon çağrısı sayısı verilir. Her program bir düğümdür.
  - Benzer olmama (dissimilarity) fonksiyonu: $v=(p_1,p_2,p_3)$, $w=(q_1,q_2,q_3)$ için $s(v,w)=\sum_{k=1}^{3}|p_k-q_k|$.
  - Seçilen bir eşik $N$ için $s(v,w)<N$ ise $v$ ile $w$ arasına kenar eklenir. $N=25$ alındığında yalnız $v_1$-$v_3$ ($24$) ve $v_3$-$v_5$ ($20$) kenarları eklenir.
- Özel graflar
  - Tam graf $K_n$: her düğüm kendisi dışındaki bütün düğümlere bağlıdır.
  - Çevre graf $C_n$ ($n\ge 3$): düğümler bir çember oluşturacak biçimde sırayla bağlanır.
  - Tekerlek graf $W_n$: $C_n$'ye bir merkez düğüm eklenir ve bu düğüm bütün düğümlere bağlanır. Merkez düğüm $n$'e sayılmaz.
  - Küp graf $Q_n$: $2^n$ düğüm vardır. Düğümler $n$ bitlik dizilerle etiketlenir ve yalnız bir biti farklı olan düğümler bağlıdır (ekrandan, 00:45:00).
- İki parçalı (bipartite) graflar
  - Düğümler, aynı parça içinde hiç kenar olmayacak biçimde kesişimi boş iki kümeye ayrılabiliyorsa graf iki parçalıdır.
  - $K_3$ iki parçalı değildir; $C_6$ iki parçalıdır (ekrandan, 00:55:00).
  - Tam iki parçalı graf $K_{m,n}$: bir parçadaki her düğüm öbür parçadaki her düğüme bağlıdır (ekrandan, 01:00:00).
- Özel grafların düğüm ve kenar sayıları (ekrandan, 01:05:00)
  - $K_n$: $n$ düğüm, $n(n-1)/2$ kenar. $C_n$: $n$ düğüm, $n$ kenar. $W_n$: $n+1$ düğüm, $2n$ kenar. $K_{m,n}$: $m+n$ düğüm, $mn$ kenar. $Q_n$: $2^n$ düğüm, $n\,2^{n-1}$ kenar.
- Yollar ve döngüler
  - $n$ uzunluğunda bir yolda $n+1$ düğüm, $n$ uzunluğunda bir döngüde $n$ düğüm vardır.
- Düğüm derecesi ve el sıkışma teoremi
  - Yönsüz bir grafta $\delta(v)$, düğüme gelen kenar sayısıdır; döngü dereceye 2 kez katılır (ekrandan, 01:25:00).
  - El sıkışma teoremi: $\sum_{v\in V}\delta(v)=2|E|$.
  - Yönlü grafta giriş derecesi (in-degree) ve çıkış derecesi (out-degree) ayrı sayılır; bütün giriş derecelerinin toplamı bütün çıkış derecelerinin toplamına eşittir.
- Euler döngüsü ve Königsberg köprü problemi
  - Euler döngüsü, her kenardan tam bir kez geçip başlangıç düğümüne dönen kapalı yoldur. Euler döngüsü olan grafa Euler grafı denir.
  - Euler grafında bütün düğüm dereceleri çifttir. Königsberg grafında düğüm dereceleri 3, 3, 3, 5 olduğu için problemin çözümü yoktur (ekrandan, 01:20:00).
  - Her kenardan bir kez geçilip başka bir düğümde bitiriliyorsa bu bir Euler yoludur (path), graf Euler grafı değildir (ekrandan, 01:40:00).
- Hamilton döngüsü
  - Her düğümden tam bir kez geçip başlangıç düğümüne dönen kapalı yoldur. Bu yola sahip grafa Hamilton grafı denir. Gezgin satıcı (travelling salesperson) problemi bununla ilişkilidir.
  - Euler için derece gibi basit bir koşul yoktur. $Q_3$ bir Hamilton döngüsüne sahiptir.
- Dijkstra algoritması (ekrandan, 01:45:00 ve 01:50:00)
  - Başlangıç düğümüne 0, diğerlerine çok büyük bir değer ($M$) verilir. Her adımda ziyaret edilmemiş en küçük değerli düğüm seçilir, komşularının değeri daha kısa bir yol bulunduysa güncellenir.
  - Derste $a$'dan başlayan örnekte sonuç $b=2$, $c=3$, $e=4$, $d=5$, $f=7$ çıkar.
- Graf modelleri
  - Niş örtüşme (niche overlap) grafı, etki (influence) grafı, round-robin turnuva grafı ve öncelik (precedence) grafı.
  - Öncelik grafında her iş, kendinden önce yapılmış ve sonucunu kullandığı işlere bağlanır (ekrandan, 02:25:00 ve 02:30:00).
- Düzlemsel graf ve Euler formülü (ekrandan, 02:35:00)
  - Kenarları birbirini kesmeyecek biçimde çizilebilen grafa düzlemsel (planar) graf denir. Bağlı düzlemsel bir grafta $v-e+f=2$ olur.
- Graf izomorfizmi
  - İki graf izomorfik ise düğüm sayıları, kenar sayıları ve derece dizileri aynıdır. Komşuluk matrisleri, satır ve sütunların aynı permütasyonu ile birbirine dönüştürülebilir.
- Ağ topolojileri
  - Yıldız topolojisi $K_{1,n}$, halka topolojisi $C_n$, hibrit topoloji $W_n$ grafıdır (ekrandan, 02:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Graf türleri arasındaki fark
  - Basit graftan başlayıp sırayla paralel kenar, döngü, ağırlık ve yön eklenerek daha karmaşık graf türlerine geçilir. Hangi graf türünde neye izin verildiği tablodan bilinmelidir.
- Bir problemin grafa indirgenmesi
  - Programların benzerliği, Königsberg köprüleri, şehirler arası yollar, kanalizasyon hattı gibi problemler graf olarak modellenip graf teorisiyle çözülebilir.
- İki parçalı graf koşulu
  - Bir parçanın içindeki düğümler arasında hiç kenar olmamalıdır. Tam graflar ($K_n$, $n\ge 3$) iki parçalı yapılamaz.
- Euler ve Hamilton farkı
  - Euler'de her **kenardan**, Hamilton'da her **düğümden** bir kez geçilir. Euler grafı için bütün düğüm dereceleri çift olmalıdır.
- Dijkstra'da güncelleme kuralı
  - Bir düğüme yeni bulunan yol eskisinden uzunsa eski (küçük) değer korunur. Yalnız daha kısa bir yol bulunursa değer değiştirilir.
- Öncelik grafında yön
  - Bir iş yalnız kendisinden önce yapılmış işlere bağlanabilir. Sonra gelen bir iş, önceki işlerin girdisi olamaz.

## Kısa Tekrar Notları

- $G=(V,E)$: düğümler ve kenarlar.
- Paralel kenar: aynı iki düğüm arasında birden fazla kenar. Döngü: düğümün kendisine bağlanan kenar.
- Basit graf: yönsüz, paralel kenarsız, döngüsüz. Çoklu graf paralel kenara, sözde graf ayrıca döngüye izin verir.
- $K_n$: $n(n-1)/2$ kenar. $C_n$: $n$ kenar. $W_n$: $n+1$ düğüm, $2n$ kenar. $K_{m,n}$: $mn$ kenar. $Q_n$: $2^n$ düğüm, $n2^{n-1}$ kenar.
- $Q_n$ düğümleri yalnız bir biti farklı olacak biçimde (Gray kodu gibi) etiketlenir.
- İki parçalı: düğümler iki kümeye ayrılır, aynı kümede kenar yoktur. $C_6$ iki parçalıdır, $K_3$ değildir.
- El sıkışma teoremi: $\sum \delta(v)=2|E|$. Her birinin derecesi 6 olan 10 düğümlü grafta $60=2|E|$, yani 30 kenar vardır.
- Euler döngüsü: her kenardan bir kez, başa dönüş. Bağlı grafta bütün dereceler çift olmalı.
- Hamilton döngüsü: her düğümden bir kez, başa dönüş.
- Dijkstra: başlangıç 0, diğerleri $M$; en küçük geçici değerli düğümü seç, komşuları güncelle.
- Euler formülü (düzlemsel, bağlı graf): $v-e+f=2$. Dörtyüzlüde $4-6+4=2$.
- İzomorfizm için gerekli koşullar: aynı düğüm sayısı, aynı kenar sayısı, aynı derece dizisi; sonra komşuluk matrisleri permütasyonla karşılaştırılır.

## Detaylı Açıklamalar

- **Graf türleri.** Ders, grafın bir düğüm kümesi ve bir kenar kümesinden oluştuğunu söyleyerek başladı. Graflar özel kenarlarına göre ayrılır. Basit grafta yön, paralel kenar ve döngü yoktur. Buna paralel kenar eklenince çoklu graf, ayrıca döngü eklenince sözde graf elde edilir. Kenarlara ağırlık verilirse ağırlıklı graf, kenarlara yön verilirse yönlü graf olur. Ekrandaki tabloya göre yönlü graf paralel kenara izin vermez ama döngüye izin verir; yönlü çoklu graf ikisine de izin verir. Ağırlıklar problemin türüne göre uzaklık, maliyet ya da elektrik hattının kapasitesi olabilir. Yönlü graflar tek yönlü ve çift yönlü caddeleri modellemek için kullanılabilir.

- **Benzerlik örneği.** Beş programın üç özelliği tablo olarak verildi (ekrandan, 00:35:00): program 1 $(66,20,1)$, program 2 $(41,10,2)$, program 3 $(68,5,8)$, program 4 $(90,34,5)$, program 5 $(75,12,14)$. Her çift için $s(v,w)=\sum|p_k-q_k|$ hesaplanır. Örneğin $s(v_1,v_2)=|66-41|+|20-10|+|1-2|=25+10+1=36$. Bütün çiftler hesaplanınca (python ile kontrol edildi) yalnız $s(v_1,v_3)=24$ ve $s(v_3,v_5)=20$ değerleri $N=25$'ten küçük çıkar. Bu yüzden grafta $v_1$-$v_3$ ve $v_3$-$v_5$ kenarları vardır; $v_2$ ve $v_4$ yalnız kalır.
  - Ders sonrası not: Hoca, kenarla bağlanan $v_1$, $v_3$, $v_5$ düğümleri için "birbirine benzemiyor" dedi. Slayttaki tanıma göre $s(v,w)<N$ ise kenar eklenir ve aralarında yol olan düğümler aynı sınıftadır. Benzer olmama değeri küçükse programlar birbirine **benzer** demektir; doğrusu $v_1$, $v_3$, $v_5$'in aynı benzerlik sınıfında olmasıdır.

- **Özel graflar ve sayıları.** $K_5$'te her düğüm diğer dört düğüme bağlıdır. $C_4$ bir kare, $C_6$ bir altıgendir. $C_6$'ya bütün köşegenler eklenirse $K_6$ elde edilir. $W_n$, $C_n$'nin içine bir merkez düğüm konup bütün düğümlere bağlanmasıyla çizilir; merkez dışarıya da konabilir ama kenarlar kesişeceği için içeride çizmek daha okunaklıdır. $Q_1$ iki düğümlü tek kenardır; $Q_2$ dört düğümlü bir karedir, yani $C_4$ ile aynıdır; $Q_3$ bir küptür; $Q_4$ iç içe iki küpün karşılıklı köşeleri bağlanarak çizilir. Kenar formülleri küçük örneklerle doğrulandı: $K_3$ için $3\cdot2/2=3$, $K_4$ için $4\cdot3/2=6$, $W_6$ için $2\cdot6=12$, $Q_1$ için $1\cdot2^0=1$, $Q_2$ için $2\cdot2^1=4$.

- **İki parçalı graflar.** $C_6$'nın düğümleri $a,b,c,d,e,f$ olsun. $a$ birinci kümeye konur; $b$, $a$'ya bağlı olduğu için ikinci kümeye; $c$, $a$'ya bağlı olmadığı için birinci kümeye konur. Böyle sürdürülünce $\{a,c,e\}$ ve $\{b,d,f\}$ kümeleri elde edilir; $C_6$ iki parçalıdır. $K_3$'te ise üç düğüm birbirine bağlı olduğu için ikisi aynı kümeye düşer, graf iki parçalı olamaz. $K_{3,2}$'de her üst düğüm her alt düğüme bağlı olduğu için $3\cdot2=6$ kenar vardır; bu kenarlardan biri eksik olsaydı graf iki parçalı olurdu ama tam iki parçalı olmazdı.

- **Derece ve el sıkışma teoremi.** Ekrandaki grafta (ekrandan, 01:25:00) dereceler $a=4$, $b=3$, $c=4$, $d=6$, $e=4$, $f=4$, $g=3$'tür; toplam $28$, yani grafta $14$ kenar vardır ($a$ ile $c$ arasında paralel iki kenar bulunur). Hocanın çizdiği beş düğümlü bir grafta (ekrandan, 01:30:00) dereceler $2,3,3,3,3$ olup toplam $14$'tür, bu da $7$ kenar verir. Yönlü bir grafta her düğümün giriş ve çıkış dereceleri ayrı sayılır ve bütün düğümler üzerinden toplam giriş derecesi toplam çıkış derecesine eşittir.
  - Ders sonrası not: Hoca derecesi 0 olan tek başına düğüme "pendant" dedi. Doğrusu: derecesi 0 olan düğüm yalıtılmış (isolated), derecesi 1 olan düğüm sarkık (pendant) düğümdür.
  - Ders sonrası not: Hoca yönlü grafta "düğümlerin giriş ve çıkış dereceleri eşit olmalı" dedi. Eşitlik tek tek düğümler için değil, bütün düğümlerin toplamı için geçerlidir; her ikisi de kenar sayısına eşittir.

- **Euler ve Hamilton.** Königsberg probleminde kara parçaları düğüm, köprüler kenardır. Derecelerin dördü de tek olduğu için her köprüden bir kez geçip başa dönmek mümkün değildir. Ekrandaki dört örnekte (ekrandan, 01:40:00) dereceleri çift olmayan iki graf için "path var, Euler grafı değil", bütün dereceleri çift olan iki graf için "Euler grafı" yazılıdır. Hamilton döngüsünde ise her düğümden bir kez geçilir; bazı kenarlar hiç kullanılmayabilir.
  - Ders sonrası not: Bağlı bir grafta Euler döngüsü ancak bütün düğüm dereceleri çiftse vardır; Euler yolu (başa dönmeyen) ancak tam iki düğümün derecesi tekse vardır. Hoca bir yerde "Euler cycle var ama Euler grafı değil" dedi, sonra bir öğrencinin sorusu üzerine bunun bir "path" olduğunu kabul etti.

- **Dijkstra örneği.** Kenarlar $ab=2$, $ac=3$, $bd=5$, $be=2$, $ce=5$, $de=1$, $df=2$, $ef=4$'tür (ekrandan, 01:45:00). $a$'dan başlanır: $b=2a$, $c=3a$. $b$ seçilir: $d=7ab$, $e=4ab$. $c$ seçilir: $e$ için $3+5=8$ bulunur ama $4<8$ olduğu için $4ab$ korunur. $e$ seçilir: $d=4+1=5$ ($7$'den küçük, güncellenir), $f=4+4=8$. $d$ seçilir: $f=5+2=7$ ($8$'den küçük, güncellenir). Sonuç ağacının kenarları $ab$, $ac$, $be$, $ed$, $df$'dir ve ağırlıkları toplamı $10$'dur (python ile kontrol edildi).
  - Ders sonrası not: Hoca Dijkstra'yı ve Kruskal'ı "en kısa yol" ve "minimum yayılan ağaç" algoritmaları olarak karıştırdı. Dijkstra tek kaynaktan en kısa yolları bulur ve bir en kısa yol ağacı üretir. Kruskal ve Prim minimum yayılan ağaç (minimum spanning tree) algoritmalarıdır. Bu örnekte iki ağacın toplam ağırlığı tesadüfen aynıdır (10), ama genelde farklı olabilir.

- **Öncelik grafı.** İşler $S_1\,a{:}0$, $S_2\,b{:}1$, $S_3\,c{:}a+1$, $S_4\,d{:}b+a$, $S_5\,e{:}d+1$, $S_6\,e{:}c+d$ olarak verilmiştir (ekrandan, 02:25:00). Her iş, kullandığı değeri üreten işe ve onun bağlı olduğu işlere bağlanır. Ekrandaki graf (ekrandan, 02:30:00) şu yönlü kenarları içerir: $S_1\to S_3$, $S_1\to S_4$, $S_1\to S_5$, $S_1\to S_6$, $S_2\to S_4$, $S_2\to S_5$, $S_2\to S_6$, $S_3\to S_6$, $S_4\to S_5$, $S_4\to S_6$.

- **Düzlemsellik ve izomorfizm.** Dörtyüzlüde $v=4$, $e=6$, $f=4$ olduğu için $4-6+4=2$ olur. İzomorfizmde önce düğüm sayısı, kenar sayısı ve dereceler karşılaştırılır; bunlar tutuyorsa komşuluk matrisleri çıkarılır. Ekrandaki örnekte (ekrandan, 02:40:00) $u$ grafının matrisinde $u_2$ ile $u_4$'ün hem satırları hem sütunları yer değiştirilince $v$ grafının matrisi elde edilir; iki graf izomorfiktir. Derecesi 1 olan bir düğümü olan graf, böyle bir düğümü olmayan grafla izomorfik olamaz.
  - Ders sonrası not: Hoca "$v-e+f=2$ ise graf düzlemseldir" dedi. Formül ters yönde kullanılır: bağlı bir graf düzlemsel çizilebiliyorsa bu çizimde $v-e+f=2$ olur. Yüz sayısı ancak düzlemsel bir çizim üzerinden sayılabildiği için formül tek başına düzlemselliği kanıtlamaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
