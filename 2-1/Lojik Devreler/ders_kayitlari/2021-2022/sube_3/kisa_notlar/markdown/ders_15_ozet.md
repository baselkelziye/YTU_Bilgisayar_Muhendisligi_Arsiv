# Ders 15 Çalışma Özeti

## Genel Konular

- Lojik fonksiyonların indirgenmesi
  - Amaç, aynı giriş değerleri için aynı çıkışı veren, daha az değişken ve daha az terimle yazılmış eşdeğer bir ifade bulmaktır. $n$ değişkenli bir fonksiyonun doğruluk tablosunda $2^n$ satır vardır; indirgenmiş ifade bu satırların hepsinde asıl fonksiyonla aynı çıkışı verir.
  - Her terim lojik kapılarla gerçekleştirildiği için daha sade ifade daha az kapı, daha düşük maliyet, daha az güç tüketimi ve devrede daha az ısınma demektir.
  - Derste üç yöntem sayıldı: (a) görüşe dayalı indirgeme, (b) Karnaugh diyagramları (haritaları), (c) Quine-McCluskey yöntemi (ekrandan, 00:15:00).
  - Tümleyen iki biçimde gösterilebilir: $\bar a = a'$ (ekrandan, 00:15:00).
- Görüşe dayalı indirgeme
  - Bilinen aksiyom ve teoremlerle (ortak paranteze alma, De Morgan, dağılma) elle yapılan sadeleştirmedir; az değişkenli ifadelerde hızlıdır.
  - Örnek: $f(a,b,c,d) = a'bc' + ad + bc'd'$ (ekrandan, 00:15:00).
    - $= bc'(a'+d') + ad$ (ortak parantez)
    - $= bc'\,(ad)' + ad$ (De Morgan: $a'+d' = (ad)'$)
    - $= (ad + bc')\,((ad)' + ad)$ (dağılma: $x + yz = (x+y)(x+z)$)
    - $= ad + bc'$ (çünkü $(ad)' + ad = 1$) (ekrandan, 00:20:00). Sonuç python ile doğrulandı.
  - Kapı karşılaştırması: ilk ifade iki adet 3 girişli VE, bir adet 2 girişli VE, bir adet 3 girişli VEYA ve tümleyenler gerektirir; indirgenmiş ifade iki adet 2 girişli VE, bir adet 2 girişli VEYA ve tek bir DEĞİL ($c'$) ile kurulur (ekrandan, 00:20:00).
  - Minterm örneği: $f(x,y,z) = \sum(0,4) = m_0 + m_4 = x'y'z' + xy'z' = y'z'(x'+x) = y'z'$ (ekrandan, 00:20:00 ve 00:25:00).
- Karnaugh diyagramları (haritaları)
  - Yöntemi önce Veitch 1952'de önermiş, Karnaugh 1953'te son biçimini vermiştir (ekrandan, 00:25:00).
  - Doğruluk tablosu bir matrisin üzerine yerleştirilir. 2 değişkende $2\times2$ (satır $x$, sütun $y$; hücreler $m_0, m_1, m_2, m_3$), 3 değişkende $2\times4$ ya da $4\times2$, 4 değişkende $4\times4$ matris kullanılır (ekrandan, 00:25:00 ve 00:30:00).
  - Satır ve sütun etiketleri $00, 01, 11, 10$ sırasıyla yazılır: art arda gelen iki etiket arasındaki Hamming uzaklığı 1 olmalıdır. Hamming uzaklığı iki bit dizisindeki farklı bit sayısıdır; örneğin $001$ ile $000$ arasında 1, $101$ ile $011$ arasında 2'dir (ekrandan, 00:25:00).
  - Bu sıra yüzünden hücrelere mintermler sırayla değil "atlayarak" yerleşir: 3 değişkende ($x$ satır, $yz$ sütun) birinci satır $m_0, m_1, m_3, m_2$, ikinci satır $m_4, m_5, m_7, m_6$ olur (ekrandan, 00:30:00).
  - Değişkenlerin hangi kenara yazılacağı serbesttir; önemli olan her hücreye doğru mintermin konmasıdır.
- Karnaugh haritasında komşuluk kavramı
  - Tanım: $n$ değişkenli bir fonksiyonda $2^k$ ($k = 1, 2, 3, \dots$) terimin toplamı kısalıp $(n-k)$ çarpanlı tek bir terime dönüşüyorsa, bu $2^k$ terim $k$. mertebeden komşudur (ekrandan, 00:35:00).
  - Komşu hücrelerin oluşturduğu bölgeye "alan" denir. Alanın sonucu, alan boyunca değişmeyen değişkenlerden yazılır: değeri hep 1 olan değişken olduğu gibi, hep 0 olan tümlenmiş yazılır; değişen değişken atılır.
  - Teorem 1 (birinci derece, $k=1$): 2 komşu hücre, $n-1$ çarpanlı terim verir. Örnek: $a'bc'd + a'bcd = a'bd(c'+c) = a'bd$ (ekrandan, 00:40:00).
  - Teorem 2 (ikinci derece, $k=2$): 4 hücre; bir sıra ya da bir kare oluşturmalıdır. $n-2$ çarpanlı terim verir.
  - Teorem 3 (üçüncü derece, $k=3$): 8 hücre; 4 değişkende tek değişkene iner.
  - Teorem 4 ($k=4$): 4 değişkenli haritanın 16 hücresinin hepsi 1 ise $f = 1$ olur (ekrandan, 01:00:00).
  - Harita bir "soba borusu" gibi düşünülür: sol ve sağ kenarlar, üst ve alt kenarlar birbirine komşudur. Dört köşe birlikte 4'lü bir alan oluşturur. Çapraz (köşegen) hücreler komşu değildir.
- Karnaugh haritasıyla indirgeme kuralları
  - Bütün 1'ler kapsanmalı ve her 1, alabileceği en büyük alanla kapsanmalıdır.
  - Başka zorunlu alanlarla zaten tamamen kapsanan büyük bir alan ifadeye yazılmaz (ekrandan, 01:20:00).
  - Aynı haritada 0'lar gruplanarak toplamlar çarpımı (POS) biçimi de yazılabilir: alan boyunca 0 olan değişken olduğu gibi, 1 olan tümlenmiş yazılır ve terimler VEYA'lı, terimler arası VE'li olur.
- Eksik Boole işlevleri (don't care durumları)
  - Bazı giriş kombinasyonlarında çıkışın 0 ya da 1 olması önemsizdir (ya da bu girişler hiç oluşmaz). Bu hücreler $\phi$ ile gösterilir ve $\sum_\phi$ ile verilir (ekrandan, 01:35:00 ve 01:40:00).
  - $\phi$ hücrelerine, daha büyük alan oluşturmaya yarıyorsa 1, yaramıyorsa 0 değeri verilir.
- Quine-McCluskey yöntemi
  - 5-6 ve daha fazla değişkende Karnaugh haritası zorlaşır; Quine-McCluskey algoritmik (programlanabilir) bir yöntemdir.
  - Adımlar: mintermler ikilik tabanda yazılır ve içerdikleri 1 sayısına göre gruplanır; ardışık gruplardaki terimler karşılaştırılır, yalnız tek bitte farklı olanlar birleştirilir ve farklı bit "_" ile işaretlenir; işlem "_" konumları aynı olan terimlerle tekrarlanır (ekrandan, 01:45:00, 01:50:00 ve 01:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Karnaugh haritasında etiket sırası $00, 01, 11, 10$'dur
  - Sebep komşuluk kavramıdır: yan yana iki hücre tek bir değişkende farklı olmalı ki birleştirildiklerinde o değişken düşsün.
- 4'lü komşuluk illa kare olmak zorunda değildir
  - Hoca, kitapta 4'lü komşuluğun bir kare oluşturması gerektiği yönündeki ifadenin eksik olduğunu, 4 hücrenin bir sıra (satır ya da sütun) da oluşturabileceğini vurguladı.
- Çapraz komşuluk yoktur
  - Kenar komşuluğu (haritanın sağ-sol ve üst-alt kenarlarının birbirine yapışık sayılması) vardır, köşegen komşuluğu yoktur. Dört köşenin birlikte oluşturduğu 4'lü alan, kenar komşuluğunun özel bir hâlidir.
- Daima en büyük alanla, ama gereksiz alan almadan
  - Amaç en büyük komşuluk ise de, başka zorunlu alanların zaten kapsadığı büyük bir alan ifadeyi uzatır; bu yüzden "olabildiğince büyük alan" kuralı tek başına yeterli değildir, gereksiz alan atılmalıdır.
- Don't care hücrelerinin değeri serbesttir
  - $\phi$'ye 1 vermek, gereksiz yeni bir terim doğuracaksa yanlış bir tercihtir; böyle hücrelere 0 verilir.

## Kısa Tekrar Notları

- İndirgeme: aynı doğruluk tablosu, daha az kapı.
- Üç yöntem: görüşe dayalı, Karnaugh, Quine-McCluskey.
- $a'bc' + ad + bc'd' = ad + bc'$.
- $\sum(0,4)$ üç değişkende $= y'z'$.
- Karnaugh etiket sırası: $00, 01, 11, 10$ (Hamming uzaklığı 1).
- $2^k$ komşu hücre $\Rightarrow$ $(n-k)$ çarpanlı tek terim.
- 2 hücre: 3 çarpan; 4 hücre: 2 çarpan; 8 hücre: 1 çarpan; 16 hücre: $f = 1$ (4 değişkende).
- Kenarlar komşu, köşeler birlikte komşu, köşegen komşu değil.
- Alan değeri: değişmeyen değişkenler; 1 ise kendisi, 0 ise tümleyeni.
- 0'lar gruplanırsa POS: terimde 0 olan değişken kendisi, 1 olan tümleyeni.
- $\sum(0,1,2,6,8,9,10) = b'c' + b'd' + a'cd' = (a'+b')(c'+d')(b'+c)$.
- $\sum(0,3,4,5,6,7,13,14) = a'c'd' + bc'd + a'cd + bcd'$; $a'b$ gereksizdir.
- $\sum(3,7,11,12,15) + \sum_\phi(0,10,13,14) = ab + cd$.
- Quine-McCluskey: 1 sayısına göre grupla, tek bit farkla birleştir, "_" konumları aynı olanlarla devam et.

## Detaylı Açıklamalar

- Görüşe dayalı indirgemede en sık kullanılan araçlar ortak paranteze alma, De Morgan ve VEYA'nın VE üzerine dağılmasıdır ($x + yz = (x+y)(x+z)$). Derste $a'bc' + ad + bc'd'$ ifadesinde önce $bc'$ ortak parantezine alındı, $a'+d'$ ifadesi De Morgan ile $(ad)'$ olarak yazıldı. Böylece ifade $bc'(ad)' + ad$ biçimine geldi. Burada $x = ad$, $y = bc'$, $z = (ad)'$ alınarak dağılma uygulandı: $(ad + bc')((ad)' + ad)$. İkinci parantez bir değişken ile tümleyeninin toplamıdır, daima 1'dir. Sonuç $ad + bc'$ oldu. Bu sonuç devreyi iki adet 2 girişli VE, bir adet 2 girişli VEYA ve bir DEĞİL kapısına indirir (ekrandan, 00:20:00).
- Karnaugh haritası doğruluk tablosunun görsel bir düzenidir. 4 değişkende satırlara $ab$, sütunlara $cd$ yazılır; her iki kenarda etiketler $00, 01, 11, 10$ sırasındadır. Bu sırada art arda iki etiket yalnız bir bitte farklıdır, bu yüzden yan yana iki hücrenin mintermleri tek bir değişkende ayrılır ve birleşince o değişken düşer.
- Birinci derece komşuluk örneği (ekrandan, 00:45:00): haritada $ab = 00$ satırında $cd = 00, 01, 10$; $ab = 01$ satırında $cd = 01, 11$; $ab = 11$ satırında $cd = 11$; $ab = 10$ satırında $cd = 01$ hücreleri 1 olsun (toplam 7 adet 1; mintermler $0, 1, 2, 5, 7, 9, 15$). İkili alanlarla:
  - $ab = 00$ satırının iki uç hücresi (kenar komşuluğu): $a'b'd'$
  - $ab = 01$ satırında $cd = 01, 11$: $a'bd$
  - $cd = 11$ sütununda $ab = 01, 11$: $bcd$
  - $cd = 01$ sütununda $ab = 00, 10$ (kenar komşuluğu): $b'c'd$
  - Sonuç: $f = a'b'd' + a'bd + bcd + b'c'd$. Bu ifade 7 mintermin 4 terimle yazılmış hâlidir (python ile doğrulandı).
- İkinci derece komşuluk örneği (ekrandan, 00:50:00 ve 00:55:00): $cd = 01$ sütununun dört hücresi $c'd$ verir; $ab = 01, 11$ satırları ile $cd = 11, 10$ sütunlarının kesiştiği kare $bc$ verir; $f = c'd + bc$. Dört köşe birlikte $b'd'$, $ab = 01, 11$ satırlarında $cd = 00$ ve $cd = 10$ sütunları (kenar komşuluğu) $bd'$ verir.
- Üçüncü derece komşuluk örneği (ekrandan, 01:00:00): $cd = 01$ ve $cd = 11$ sütunlarının sekiz hücresi $d$ verir; $ab = 00$ ve $ab = 10$ satırlarının sekiz hücresi (üst-alt kenar komşuluğu) $b'$ verir. Aynı fonksiyonu sekiz mintermle yazmak ($a'b'c'd + a'b'cd + \dots$) çok daha uzun olurdu.
- Derste çözülen soru: $f = a'b'c' + b'cd' + a'bcd' + ab'c'$ önce doğruluk tablosuna, sonra haritaya döküldü (mintermler $0, 1, 2, 6, 8, 9, 10$). 1'ler gruplanınca $f = b'c' + b'd' + a'cd'$; 0'lar gruplanınca $f = (a'+b')(c'+d')(b'+c)$ bulundu. İki ifade aynı fonksiyondur (python ile doğrulandı); biri çarpımlar toplamı, diğeri toplamlar çarpımıdır (ekrandan, 01:10:00 ve 01:15:00).
- Gereksiz alan örneği: $f = \sum(0,3,4,5,6,7,13,14)$. $ab = 01$ satırının tamamı 4'lü bir alan ($a'b$) gibi görünür, ama diğer 1'ler ($m_0, m_3, m_{13}, m_{14}$) zaten ikili alanlarla kapsanmak zorundadır ve bu ikili alanlar $a'b$'nin bütün hücrelerini de kapsar. Bu yüzden $a'b$ yazılmaz: $f = a'c'd' + bc'd + a'cd + bcd'$ (ekrandan, 01:20:00).
- Don't care örneği: $f(a,b,c,d) = \sum(3,7,11,12,15) + \sum_\phi(0,10,13,14)$. $m_{13}$ ve $m_{14}$'e 1 verilirse $ab = 11$ satırı 4'lü bir alan olur ($ab$); $cd = 11$ sütunu da 4'lü bir alandır ($cd$). $m_0$ ve $m_{10}$'a 0 verilir, çünkü örneğin $m_{10}$'a 1 vermek $ac$ gibi gereksiz bir terim ekler. Sonuç $f = ab + cd$ (ekrandan, 01:40:00).
- Quine-McCluskey örneği: $f = \sum(3,7,11,12,13,14,15)$ (ekrandan, 01:45:00 - 01:55:00).
  - Gruplar: iki 1'li $\{3 = 0011,\ 12 = 1100\}$; üç 1'li $\{7 = 0111,\ 11 = 1011,\ 13 = 1101,\ 14 = 1110\}$; dört 1'li $\{15 = 1111\}$.
  - 2. adım: $3,7 = 0\_11$; $3,11 = \_011$; $12,13 = 110\_$; $12,14 = 11\_0$; $7,15 = \_111$; $11,15 = 1\_11$; $13,15 = 11\_1$; $14,15 = 111\_$.
  - 3. adım: $3,7,11,15 = \_\_11$ ve $12,13,14,15 = 11\_\_$ (her biri iki farklı eşleşmeyle iki kez çıkar, birini almak yeterlidir).
  - Sonuç: $f = ab + cd$. "_" konumları yazılmaz, sabit kalan bitler 1 ise değişkenin kendisi, 0 ise tümleyeni yazılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
