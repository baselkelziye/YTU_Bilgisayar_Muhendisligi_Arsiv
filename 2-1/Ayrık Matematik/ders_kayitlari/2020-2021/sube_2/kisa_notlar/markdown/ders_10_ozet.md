# Ders 10 Çalışma Özeti

## Genel Konular

- Bağıntılardan graflara, graflardan ağaçlara geçiş
  - İkili bağıntı küme, 0-1 matris ya da yönlü graf (digraph) ile gösterilebilir; graf, bağıntının daha genel gösterimidir.
  - Tanım (ekrandan, 00:10:00): $G=(V,E)$ grafı boş olmayan bir köşe (düğüm) kümesi $V$ ve kenar kümesi $E$'den oluşur. Her kenarın uç noktaları adı verilen bir ya da iki köşesi vardır; kenar iki köşe arasındaki ilişkiyi gösterir. Slayt örneği: dört köşeli ($a,b,c,d$), beş kenarlı bir graf.
  - Uygulamalar: şehirler arası yollar, sosyal ağdaki arkadaşlık ilişkileri, öğrenciler arası kod/ödev benzerliği gibi kenara sayı yazılan ilişkiler.
  - Ağaç, kapalı çevrim (döngü) içermeyen özel bir graftır.
- Ağaç kavramı ve terminoloji
  - Ağaç: iki düğüm arasında tek bir yol bulunan, döngü içermeyen basit graf. Döngülü bir graftan döngüleri bozan kenarlar silinerek ağaç elde edilebilir.
  - Köklü ağaç: bir düğüm en üst düzey (kök, root) seçilince düğümler arasında seviye ve ata-çocuk ilişkisi belirlenir.
  - Düğüm seviyesi $l(v)$: düğümden köke olan yolun uzunluğu. Ağaç yüksekliği: $h=\max_{v\in V(T)} l(v)$ (ekrandan, 00:20:00); slayttaki ağacın yüksekliği 3.
  - Terimler: kök/ebeveyn (parent), ata (ancestor), çocuk (child), torun/alt düğüm (descendant), kardeş (sibling), uç/yaprak (terminal, leaf), ara düğüm (internal), alt ağaç (subtree).
  - Ağaçlarda kenar uzunluğunun anlamı yoktur; ağırlıklı kenarlar graflarda karşımıza çıkar.
- Ağaçların karakteristiği (ekrandan, 00:25:00)
  - $T$ $n$ düğümlü bir graf ise şunlar denktir: (a) $T$ bir ağaçtır; (b) $T$ bağlantılı ve döngüsüzdür (acyclic); (c) $T$ bağlantılı ve $n-1$ kenarlıdır; (d) $T$ döngüsüz ve $n-1$ kenarlıdır.
- İkili ağaç (binary tree)
  - Her düğümün en fazla iki çocuğu (sol ve sağ) vardır; bir düğümün 0, 1 ya da 2 çocuğu olabilir.
- İfade ağaçları ve infix/prefix/postfix dönüşümleri
  - Ara düğümlerde operatörler, yapraklarda operandlar bulunur. Ağaca yerleştirme (parsing) infix ifadeden yapılır.
  - Gezinme sıraları: prefix = kök-sol-sağ, infix = sol-kök-sağ, postfix = sol-sağ-kök (ekrandan, 00:35:00).
  - Ağaç her gösterimde aynıdır; değişen yalnız ağaç üzerinde dolaşma sırasıdır.
  - Sınav ve ders örnekleri: $(a+b-c)\sqrt[n]{x}$, $(a+b)(a-c)\cdot 2^2-(b/c)$, postfix `2 2 ↑ 2 1 * + 3 ↑ 2 *`, prefix `+ * + ↑ 3 2 a / b a 3`.
- İkili ağaç türleri
  - Aynı düğüm sayısıyla farklı ikili ağaçlar: $n=0$ boş ağaç, $n=1$ için 1, $n=2$ için 2, $n=3$ için 5 ağaç (ekrandan, 01:50:00).
  - Tam (full) ikili ağaç: yapraklar dışındaki her düğümün iki çocuğu vardır. $i$ ara düğüm varsa $i+1$ yaprak ve toplam $2i+1$ düğüm olur.
  - Dengeli ağaç: yüksekliği $h$ olan ağacın bütün yaprakları $h$ ya da $h-1$ seviyesindedir.
- İkili arama ağacı (binary search tree)
  - İlk eleman köktür; kökten küçükler sola, büyükler sağa yerleştirilir.
  - Sıralı veri eklenince ağaç doğrusal listeye dönüşür (dengesiz ağaç).
  - Ağacın dizide saklanması: kök 1. indiste, $i$ indisli düğümün sol çocuğu $2i$, sağ çocuğu $2i+1$ indisindedir; boş yerler 0 ile doldurulur (ekrandan, 02:05:00).
- Ağaç gezinme (traversal)
  - Preorder ($r\,T_1\,T_2\ldots T_n$), inorder ($T_1\,r\,T_2\ldots T_n$), postorder ($T_1\,T_2\ldots T_n\,r$); ikiden fazla çocuklu ağaçlara da uygulanır (ekrandan, 02:10:00, 02:15:00).
- Huffman kodlama
  - Sık geçen sembole az bit, seyrek geçene çok bit atayan sıkıştırma yöntemi. Semboller yapraktadır; köke göre sola gidiş 0, sağa gidiş 1 eklenir.
  - Slayt örneği: $a,e,k,l,m,z$ sembolleri için sıklıklar $25,14,8,7,4,2$ (ekrandan, 02:25:00).
- Kapsayan ağaç (spanning tree)
  - Grafın bütün düğümlerini içeren, döngüsüz alt ağaç. Ağırlıklı graflarda en az maliyetlisi minimum kapsayan ağaçtır.
  - Oluşturma yöntemleri: genişlik öncelikli arama (BFS, kuyruk kullanır) ve derinlik öncelikli arama (DFS, geri izleme, yığın kullanır).

## Hocanın Özellikle Vurguladığı Kısımlar

- Dönüşümleri ezberlemeyin, $A+B$ ağacının mantığını öğrenin
  - Operatör yukarıda, $A$ solda, $B$ sağda. $+AB$ prefix'in, $AB+$ postfix'in kalıbıdır; büyük ifadelerde aynı kural her alt ağaca özyinelemeli (recursive) uygulanır.
  - Prefix'te önce kökü yaz, sonra sol alt ağaca, sonra sağ alt ağaca geç; postfix'te gidebildiğin kadar sola in, sonra sağa, en son kökü yaz.
- İfade dönüşümlerinde ağaç kullanmak yığından kolaydır
  - Yığında yalnız ekle-çıkar hareketi vardır; ağaçta iki boyutlu hareket edilir. Sınavda "herhangi bir yöntemle dönüştürün" denirse önce ağaca yerleştirmek en kolay yoldur.
  - Kısa yoldan tarama yaparak değerlendirmede hata yapma olasılığı yüksektir; ağacı kullanın.
- Bir düğümün altına aynı seviyede üçüncü bir operand eklenemez
  - Ardışık iki işlem varsa ilk işlemin sonucu yeni bir alt ağaç olur ve sonraki operatör bu alt ağacın üstüne kök olarak gelir.
- İşlem önceliği ağacın şeklini belirler
  - $(a+b)(a-c)\cdot 2^2-(b/c)$ ile $(a+b)(a-c)-2^2-(b/c)$ farklı ağaçlar verir.
- Ağaç terminolojisi bilgisayar biliminin birçok alanında (veri yapıları, işletim sistemleri, derleyiciler) kullanılır; problem çözerken terimlere hakim olmak gerekir.
- BFS ve DFS kör (bilgisiz) arama yöntemleridir; en düşük maliyetli kapsayan ağacı vermezler.

## Kısa Tekrar Notları

- Ağaç = döngüsüz, bağlantılı graf; $n$ düğümlü ağacın $n-1$ kenarı vardır.
- Seviye $l(v)$ = köke uzaklık; yükseklik $h=\max l(v)$.
- Kök de bir ara düğümdür (en az bir çocuğu varsa); çocuğu olmayan düğüm yapraktır.
- İfade ağacında ara düğümler operatör, yapraklar operanddır.
- Prefix: kök-sol-sağ; infix: sol-kök-sağ; postfix: sol-sağ-kök.
- Postfix değerlendirme: soldan tara, operatör görünce önceki iki operandı işle (ilki sol, ikincisi sağ).
- Prefix değerlendirme: operatörün hemen ardından iki operand gelmişse o işlemi yap, ifadeyi küçült.
- Tam ikili ağaçta $i$ ara düğüm $\Rightarrow$ $i+1$ yaprak, $2i+1$ düğüm.
- İkili arama ağacı: küçük sola, büyük sağa; sıralı ekleme dengesiz ağaç verir.
- Dizide saklama: sol çocuk $2i$, sağ çocuk $2i+1$.
- Huffman: en küçük iki sıklığı birleştir, sola 0 sağa 1 ver.
- BFS kuyruk, DFS yığın kullanır.

## Detaylı Açıklamalar

- **Ağaçların yeri.** Ders, ikili bağıntıların yönlü grafla gösterilmesini hatırlatarak başladı. Graf, köşeler ve kenarlar arasındaki ilişkiyi gösteren özel bir bağıntıdır. Graf çok sayıda kapalı çevrim içerebilir; kapalı çevrim içermeyen özel hali ağaçtır. Bu yüzden konu sırası bağıntı, graf, ağaç biçiminde düşünülmelidir.
- **Terminoloji.** Köklü ağaçta kök tektir. Bir düğümün bir üst düğümü ebeveyni, alt düğümleri çocuklarıdır. Aynı ebeveyne bağlı düğümler kardeştir. Çocuğu olmayan düğüm yapraktır (terminal); en az bir çocuğu olan düğüm, kök dahil, ara düğümdür (internal). Bir kenar koparıldığında ayrılan parça alt ağaçtır; $T'$, $T$'nin alt ağacıysa $V(T')\subseteq V(T)$ ve $E(T')\subseteq E(T)$ olur.
  - **Ders sonrası not:** Hoca kardeşleri "aynı seviyedeki düğümler" diye tanımladı; doğrusu, kardeşler aynı ebeveyne sahip düğümlerdir (aynı seviyede olup ebeveyni farklı olan düğümler kardeş sayılmaz). Ata da yalnız bir üst düğüm değil, kökten o düğüme giden yol üzerindeki bütün düğümlerdir; bir üst düğüme ebeveyn denir.
- **Soru:** Ağaç için en az kaç düğüm gerekir? **Cevap:** Düğüm sayısına bir sınır yoktur; ama kenar sayısı düğüm sayısının bir eksiğidir. Alt-üst ilişkisi görmek için en az iki düğüm gerekir.
- **İfade ağacına yerleştirme.** $A+B$ için $+$ kök, $A$ sol çocuk, $B$ sağ çocuktur. $A+B-C$ için iki operatör ara düğüm, üç operand yaprak olur. Ağaç yapraklardan köke doğru kurulur; en son yapılacak işlem köktür.
- **Örnek 1** (ekrandan, 00:45:00–00:50:00): $(a+b-c)\sqrt[n]{x}$. Kök ifadesi $x^{1/n}$ olarak yazılır. Kök $*$; sol alt ağaç $(a+b)-c$, sağ alt ağaç $x\uparrow(1/n)$.
  - Prefix: `* - + a b c ↑ x / 1 n`
  - Postfix: `a b + c - x 1 n / ↑ *`
- **Örnek 2** (ekrandan, 00:55:00–01:05:00): $(a+b)*(a-c)*2\wedge2-(b/c)$, $a=2,\ b=2,\ c=1$. Kök $-$; solunda $((a+b)*(a-c))*(2\uparrow2)$, sağında $b/c$.
  - Prefix: `- * * + a b - a c ↑ 2 2 / b c`
  - Postfix: `a b + a c - * 2 2 ↑ * b c / -`
  - Değer: $4\cdot1=4$, $4\cdot4=16$, $2/1=2$, $16-2=14$ (python ile doğrulandı).
  - Ara işlem $(a+b)(a-c)-2^2-(b/c)$ olsaydı soldaki iki çıkarma önce yapılır: kök $-$, solunda $((a+b)(a-c))-(2\uparrow2)$, sağında $b/c$; değer $4-4-2=-2$ (ekrandan, 01:30:00).
- **Örnek 3, postfix'ten ağaca** (ekrandan, 01:40:00): `2 2 ↑ 2 1 * + 3 ↑ 2 *` ($m=1,\ n=2$ yerleştirilmiş hali). Okunan iki operand bir operatörün sol ve sağ çocuğu olur; operatör gelince oluşan alt ağaç bir sonraki işlemin sol çocuğudur.
  - Infix: $\big(((2\uparrow2)+(2*1))\uparrow3\big)*2$
  - Prefix: `* ↑ + ↑ 2 2 * 2 1 3 2`
  - Değer: $4+2=6$, $6^3=216$, $216\cdot2=432$.
- **Örnek 4, prefix'ten ağaca** (ekrandan, 01:45:00): `+ * + ↑ 3 2 a / b a 3`, $a=2,\ b=4$.
  - Infix: $\big((3\uparrow2)+a\big)*(b/a)+3$
  - Postfix: `3 2 ↑ a + b a / * 3 +`
  - Değer: $9+2=11$, $4/2=2$, $11\cdot2=22$, $22+3=25$.
- **İkili arama ağacı ve dizide saklama.** $4,3,8,9$ dizisinde 4 kök, 3 sol, 8 sağ, 9 da 8'in sağ çocuğudur. Slayttaki $23,13,19,47,11,43,7,29,52$ dizisi eklendiğinde dizi gösterimi (indis 1–15): `23 13 47 11 19 43 52 7 0 0 0 29 0 0 0` (ekrandan, 02:05:00; python ile doğrulandı).
- **Gezinme örneği** (ekrandan, 02:10:00, 02:15:00): kökü $a$ olan çok çocuklu ağaçta ($a$: $b,c,d$; $b$: $e,f$; $e$: $j,k$; $k$: $n,o,p$; $d$: $g,h,i$; $g$: $l,m$)
  - Preorder: `a b e j k n o p f c d g l m h i`
  - Inorder: `j e n k o p b f a c l g m d h i`
  - Postorder: `j n o p k e f b c l m g h i d a`
- **Huffman.** Slayttaki iki ağaçla "rate" kelimesi `001 000 011 100` ve `11 000 001 10` olarak kodlanır (ekrandan, 02:20:00). Sıklıklar $2,4,7,8,14,25$ sıralanır; ara toplamlar $-6,-13,-21,-35,-60$ ile gösterilir (eksi işareti ara toplam demektir). $n$ sembol için genişletilmiş dizi $2n-1$ elemanlıdır (ekrandan, 02:25:00).
- **BFS örneği** (ekrandan, 02:40:00): A'dan başlayınca çıktı `A-B-C-F-E-D-H-J`.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
