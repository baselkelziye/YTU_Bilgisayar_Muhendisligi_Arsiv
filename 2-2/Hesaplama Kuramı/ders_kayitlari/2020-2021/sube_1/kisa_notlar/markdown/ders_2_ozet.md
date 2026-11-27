# Ders 2 Çalışma Özeti

## Genel Konular

- Ders İngilizce anlatıldı, araya Türkçe açıklamalar girdi.
  - Asıl anlatım yaklaşık 00:09'da başlar. Kayıtta iki ara vardır (yaklaşık 01:12-01:21 ve 02:02-02:11).
- Hesaplama kuramı nedir?
  - Hesaplama kuramı, neyin hesaplanabileceğini soyutlamalarla inceleyen, bilgisayar bilimi ile matematiğin birleştiği bir daldır.
  - Gerçek bilgisayarın ayrıntıları atılır, yerine biçimsel (formal) modeller konur.
  - Üç ana alanı vardır: otomata kuramı (automata theory), hesaplanabilirlik kuramı (computability theory) ve hesaplama karmaşıklığı kuramı (computational complexity theory).
- Problemlerin dizgi kümesi olarak gösterilmesi
  - Bir problem, çoğu zaman ikili (binary) dizgilerden oluşan bir küme olarak gösterilir. Örnek: 3'e bölünebilen bütün ikili sayıların kümesi.
  - Problemi çözmek, her aday dizgi için "kümede mi, değil mi?" sorusuna evet ya da hayır diyebilmektir. Bunu yapan bir algoritma varsa problem karar verilebilir (decidable) bir problemdir.
  - Daha büyük alfabeler de kullanılabilir: `#` ile ayrılmış ikili sayı listeleri ve "sayılar artan sırada mı?" problemi.
  - Makine (otomat), yalnız belirli dizgileri içeri alan bir kapı bekçisine benzetildi.
- Hesaplayıcı (computer) kavramı
  - Bilgisayar, hesap yapan makinedir. Abaküs, mekanik hesap makinesi, süper bilgisayar ve dominolarla kurulan devre de birer hesaplayıcıdır.
  - Dominolarla kurulmuş 4 bitlik ikili toplayıcı videosu izlendi (yarım toplayıcı, tam toplayıcı, elde, zamanlama sorunu).
- Hesaplama kuramının soruları
  - Bilgisayar donanımının ve yazılımının matematiksel özellikleri nelerdir?
  - Hesaplama nedir, algoritma nedir? Bunlara kesin matematiksel tanımlar verilebilir mi?
  - Bilgisayarların sınırları nelerdir? Her şey hesaplanabilir mi? (Cevap: hayır.)
  - Amaç: gerçek bilgisayarları yansıtan biçimsel matematiksel hesaplama modelleri geliştirmek.
- Karmaşıklık kuramı
  - Bazı problemler kolaydır: sıralama, telefon rehberinde isim arama, iki nokta arasındaki en hızlı yolu bulma.
  - Bazı problemler zordur: ders programı çizelgeleme, 300 basamaklı bir sayıyı asal çarpanlarına ayırma, VLSI yonga yerleşimi.
  - Ana soru: problemleri zorluk derecesine göre sınıflandırmak ve zor görünen problemlerin gerçekten zor olduğunu kesin olarak ispatlamak.
- Hesaplanabilirlik kuramı
  - 1930'larda bazı temel problemlerin bilgisayarla çözülemeyeceği keşfedildi.
  - Ana soru: problemleri çözülebilir ve çözülemez diye sınıflandırmak.
- Otomata kuramı
  - Sonlu otomatlar (DFA ve NFA): metin işleme, derleyiciler ve donanım tasarımında kullanılır.
  - Bağlamdan bağımsız gramerler: programlama dillerinin tanımında ve yapay zekâda kullanılır. Sonlu otomattan güçlüdür, bellek de kullanır.
  - Turing makineleri: gerçek bir bilgisayarın basit soyut modelidir.
  - Ana soru: bu modellerin gücü aynı mı, yoksa biri ötekinden daha çok problem çözebilir mi?
- Kümeler kuramı (set theory)
  - $\mathbb{N}$, $\mathbb{Z}$, $\mathbb{Q}$, $\mathbb{R}$; alt küme, kuvvet kümesi.
  - Birleşim, kesişim, fark, Kartezyen çarpım, tümleyen; ikili bağıntı, fonksiyon, denklik bağıntısı.
- Boole mantığı
  - Değil (NOT), ve (AND), veya (OR), dışlayan veya (XOR), denklik ve gerektirme.
- Teorem ve ispat
  - Aksiyom, hipotez, teorem, lemma ve sonuç (corollary).
  - İspat için ipuçları.
  - Beş teknik: doğrudan ispat, yapıcı ispat, yapıcı olmayan ispat, olmayana ergi, tümevarım; ayrıca güvercin yuvası ilkesi.
- Düzenli ifadelere giriş: alfabe, dizgi, dil
  - Alfabe, sembol, dizgi, uzunluk, boş dizgi, ters çevirme, alt dizgi, önek, sonek.
  - Birleştirme, $x^n$ gösterimi, Kleene yıldızı ve $\Sigma^+$.
  - Dil: bir alfabe üzerindeki dizgilerin kümesi. Düzenli diller ve kapalılık özellikleri.
  - Birli (unary) toplama ve kare alma işlemlerinin dil olarak yazılması.
  - $\emptyset$ ile $\{\varepsilon\}$ arasındaki fark.
- Sonlu otomata ilk bakış: dizgiyi alıp "kabul" ya da "ret" çıktısı veren makine.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bilgisayar "hesaplayıcı"dır.
  - Hocaya göre bilgi sayılamaz. Bu yüzden İngilizcedeki "computer" sözcüğünün doğru karşılığı "hesaplayıcı"dır. Hesap yapan her düzenek (abaküs bile) bir bilgisayardır.
  - Hesaplayıcılarla programlama dilleri aracılığıyla konuşulur.
- Bilgisayarlar sınırlıdır.
  - Kaynaklar (RAM, işlemci gücü) sınırlı olduğu için her şey hesaplanamaz.
- Teoremi anlamak ispatın en zor kısmıdır.
  - Teoremi kendi sözlerinizle yeniden yazın, basit durumlarda deneyin.
  - "A ancak ve ancak B" iki gerektirmeyi, "A = B" ise $A \subseteq B$ ve $B \subseteq A$ göstermeyi gerektirir. Bu yöntem ileride pompalama önsavında da kullanılacak.
- Gösterimlere dikkat
  - $w^R$ yalnız "ters çevirme" için kullanılır, başka anlamda kullanılmamalı.
  - Kuvvet ($x^n$) dizgilerde çarpma değil, $n$ kez birleştirme demektir.
  - Alfabedeki rakamlar sayı değil semboldür. "11", "bir bir" dizgisidir.
- Boş küme ile boş dizgi karıştırılmamalı.
  - $|\emptyset| = 0$, $|\{\varepsilon\}| = 1$ (küme büyüklüğü), $|\varepsilon| = 0$ (dizgi uzunluğu). Hoca, sınavda çoğu öğrencinin bunu karıştıracağını söyledi.
- "Automaton" tekil, "automata" çoğuldur ("datum" ve "data" gibi).

## Kısa Tekrar Notları

- Hesaplama kuramının üç alanı: otomata, hesaplanabilirlik, karmaşıklık.
- Problem = dizgi kümesi. Problemi çözmek = üyelik sorusuna evet/hayır demek.
- $P(B) = \{A : A \subseteq B\}$, $\emptyset \in P(B)$ ve $B \in P(B)$.
- $|A \times B| = |A| \cdot |B|$.
- Denklik bağıntısı: yansımalı, simetrik, geçişli.
- Doğrudan ispat: $n = 2k+1 \Rightarrow n^2 = 2(2k^2+2k)+1$ tektir.
- Yapıcı ispat: bir örnek kurmak yeter. Yapıcı olmayan ispat: varlık, nesne kurulmadan gösterilir.
- Olmayana ergi: $\sqrt{2} = p/q$ varsayımı, $p$ ve $q$'nun ikisinin de çift çıkmasıyla çelişir.
- Tümevarım: taban adımı ($n=1$), sonra $P(n) \Rightarrow P(n+1)$.
- Güvercin yuvası: $n+1$ nesne $n$ kutuya konursa bir kutuda en az 2 nesne olur. $|A| > |B|$ ise $A$'dan $B$'ye bire bir fonksiyon yoktur.
- $n^2+1$ farklı sayıdan oluşan her dizide $n+1$ uzunluğunda artan ya da azalan bir alt dizi vardır.
- Alfabe: sonlu, boş olmayan sembol kümesi ($\Sigma$, $\Gamma$).
- Dil: $\Sigma^*$'ın bir alt kümesi. $\Sigma^+ = \Sigma^* - \{\varepsilon\}$.
- $|uv| = |u| + |v|$. $\varepsilon$ her dizginin hem öneki hem sonekidir.
- Düzenli diller birleşim, kesişim, tümleyen, birleştirme ve yıldız altında kapalıdır.

## Detaylı Açıklamalar

- **Problem ve dil.** Hesaplama kuramında problem bir dizgi kümesiyle gösterilir. Örneğin "3'e bölünebilen ikili sayılar" problemi, bu sayıları gösteren bütün ikili dizgilerin kümesidir. Bir aday dizgi verildiğinde kümede olup olmadığına karar veren bir algoritma varsa problem çözülmüş olur. Hoca bu tür problemlere karar verilebilir problemler dedi. Daha karmaşık girdiler de aynı biçimde yazılabilir: `#` sembolüyle ayrılmış ikili sayı listeleri ve bu sayıların artan sırada olup olmadığı sorusu. Makine, kendisine verilen programı çalıştırıp her aday dizgi için evet ya da hayır diyen bir kapı bekçisi gibidir.

- **Dil benzetmesi.** İnsanlar Türkçe gibi bir dille konuşur: harfler sözcükleri, sözcükler cümleleri oluşturur. Makineyle konuşmak, ona bir hesap yaptırmak için de makinenin anladığı bir dil gerekir. Örneğin Java'da `import`, `if`, `for`, `while`, `class` gibi sözcükler vardır ve derleyici bunları tanır. Hesaplama kuramında "dil" sözcüğü tam olarak bu anlamda, yani bir dizgi kümesi anlamında kullanılır.

- **Domino bilgisayarı.** İzlenen videoda dominolarla iki tane 4 bitlik ikili sayıyı toplayan bir devre kuruldu. Birler basamağında yarım toplayıcı (half adder), diğer basamaklarda önceki basamağın eldesini de alan tam toplayıcı (full adder) vardı. Örnek işlemde $9 + 3 = 12$ hesaplandı. Çıkışta 4'ler ve 8'ler basamağı düşmeliydi ($12 = 8 + 4$). Videoda zamanlama hatası yüzünden yanlış basamaklar da düştü. Bu, devredeki gecikmelerin önemini gösterdi. Hocanın asıl mesajı, hesap yapmak için bir dizüstü bilgisayarın gerekmediği, mekanik bir düzeneğin de hesaplayıcı olabileceğiydi.

- **Kaynakların sınırlılığı.** Hoca, sınırlı bir evrende kaynakların da sınırlı olduğunu, bu yüzden hesaplama gücünün sonsuz olamayacağını anlattı. RAM azsa ya da işlemci gücü düşükse bazı uygulamalar pratikte çalıştırılamaz. Bu sınırları aşmak için dağıtık işlemciler ve dağıtık bellekler kullanılır. Örneğin bugünün cep telefonları da birer hesaplayıcıdır.

- **Karmaşıklık örneği.** Hoca, verilen 100 (ya da 1 milyon) sayıyı, iki gruptaki sayıların karelerinin toplamı eşit olacak biçimde iki gruba ayırma problemini zor problem örneği olarak verdi. Bu problem sayı arttıkça bilgisayarla çözülemeyecek kadar zorlaşır. Buna karşılık 1 milyon sayıyı sıralamak kolaydır.
  - **Ders sonrası not:** Hoca bu problem için "çözülemez" ve "hesaplanamaz" (uncomputable) sözcüklerini de kullandı. Bu tür bir bölme problemi hesaplanabilirdir: bütün bölmeler tek tek denenerek çözülebilir. Zor olan, verimli (hızlı) çözümdür. Yani bu bir karmaşıklık sorusudur, hesaplanabilirlik sorusu değildir.

- **Kümeler.** Küme, iyi tanımlanmış nesnelerin topluluğudur (ekrandan, 01:25:00):
  - $\mathbb{N} = \{1, 2, 3, \dots\}$, $\mathbb{Z} = \{\dots, -2, -1, 0, 1, 2, \dots\}$.
  - $\mathbb{Q} = \{m/n : m \in \mathbb{Z},\ n \in \mathbb{Z},\ n \neq 0\}$. $\mathbb{R}$ gerçel sayılardır.
  - $A$'nın her elemanı $B$'de de varsa $A \subseteq B$ yazılır.
  - $P(B) = \{A : A \subseteq B\}$. $\emptyset \in P(B)$ ve $B \in P(B)$.
  - **Ders sonrası not:** Kuvvet kümesinin eleman sayısı $|P(B)| = 2^{|B|}$'dir. Altyazıda hocanın sözü "iki üssü artı bir" gibi duyuluyor. Boş küme bu $2^{|B|}$ altkümenin içinde zaten sayılır.
  - Kartezyen çarpım ikililerden oluşur: $A \times B = \{(a,b) : a \in A,\ b \in B\}$ ve $|A \times B| = |A|\cdot|B|$. İki küme arasındaki bir bağıntı, Kartezyen çarpımlarının bir alt kümesidir. Fonksiyon bir eşlemedir (mapping).

- **Boole mantığı** (ekrandan, 01:30:00). Değerler 1 (doğru) ve 0 (yanlış). İşlemler: değil $\neg$, ve $\wedge$, veya $\vee$, dışlayan veya $\oplus$, denklik $\leftrightarrow$ ya da $\Leftrightarrow$, gerektirme $\rightarrow$ ya da $\Rightarrow$. VE'de girişlerden biri 0 ise sonuç 0, VEYA'da biri 1 ise sonuç 1 olur. XOR, girişler farklıysa 1 verir.

- **Kavramlar.** Aksiyomlar, matematiksel yapının altındaki varsayımlardır. Hipotez ispatlanınca teorem olur. Lemma, ispatı zaten bilinen (çoğunlukla daha basit) bir teoremdir. Sonuç (corollary), bir teoremden çıkarılan sonuçtur.

- **Doğrudan ispat** (ekrandan, 01:40:00). Teorem: $n$ tek pozitif tamsayı ise $n^2$ de tektir. $n = 2k+1$ ($k \ge 0$) yazılır:
  $$n^2 = (2k+1)^2 = 4k^2 + 4k + 1 = 2(2k^2 + 2k) + 1.$$
  $2(2k^2+2k)$ çifttir. Çift artı bir tek olduğu için $n^2$ tektir.

- **Yapıcı ispat.** "Öyle bir nesne vardır" diyen teoremler için bir örnek kurmak yeter. Örnek: $q$ ve $r$ irrasyonel olmak üzere $p = q^r$ biçiminde yazılabilen rasyonel bir $p$ vardır. Seçim: $q = \sqrt{2}^{\sqrt{2}}$, $r = \sqrt{2}$. O zaman $q^r = \sqrt{2}^{\sqrt{2}\cdot\sqrt{2}} = \sqrt{2}^2 = 2$ olur ve 2 rasyoneldir.
  - **Ders sonrası not:** Hoca "irrasyonel üssü irrasyonel her zaman irrasyoneldir" dedi. Bu genel olarak doğru değildir; hemen sonraki teorem bunun tersine bir örneği gösterir. $\sqrt{2}^{\sqrt{2}}$'nin irrasyonel olduğu ayrı bir sonuçtur (Gelfond-Schneider teoremi).

- **Yapıcı olmayan ispat** (ekrandan, 01:45:00). Teorem: $x^y$ rasyonel olacak biçimde irrasyonel $x$ ve $y$ sayıları vardır. İki durum vardır. $\sqrt{2}^{\sqrt{2}}$ rasyonelse $x = y = \sqrt{2}$ alınır. Rasyonel değilse $x = \sqrt{2}^{\sqrt{2}}$, $y = \sqrt{2}$ alınır ve $x^y = 2$ olur. İspat teoremi kanıtlar ama hangi çiftin işe yaradığını söylemez.
  - **Ders sonrası not:** Slaytta üs işareti kaybolmuş, "xy" ve "Case 1: $\sqrt{2} \in Q$" yazıyor. Hoca da slaytta hata olduğunu fark etti. Doğrusu yukarıdaki gibi $x^y$ ve "Durum 1: $\sqrt{2}^{\sqrt{2}} \in \mathbb{Q}$" olmalıdır.

- **Olmayana ergi** (ekrandan, 01:50:00). $\sqrt{2}$'nin rasyonel olduğu varsayılır: ortak çarpanı olmayan pozitif $p, q$ için $\sqrt{2} = p/q$. Buradan $2q^2 = p^2$ çıkar, yani $p^2$ çifttir. Tek sayının karesi tek olduğu için $p$ de çifttir: $p = 2r$. Yerine konunca $2q^2 = 4r^2$, yani $q^2 = 2r^2$ olur ve $q$ da çifttir. $p$ ile $q$'nun ortak çarpanı 2 çıkar. Bu, varsayımla çelişir. Demek ki $\sqrt{2}$ irrasyoneldir.

- **Tümevarım** (ekrandan, 01:55:00). $P(n)$, $n$'ye bağlı bir önerme olsun. Önce $n = 1$ için doğruluğu gösterilir (taban). Sonra $P(n)$ doğruysa $P(n+1)$'in de doğru olduğu gösterilir. Örnek: $1 + 2 + \dots + n = \frac{n(n+1)}{2}$. $n=1$ için iki taraf da 1'dir. $n=2$ için $3 = \frac{2\cdot 3}{2}$. Tümevarım adımında $\frac{n(n+1)}{2} + (n+1) = \frac{(n+1)(n+2)}{2}$ elde edilir.

- **Güvercin yuvası ilkesi.** $n+1$ nesne $n$ kutuya konursa en az bir kutuda en az iki nesne bulunur. Kümelerle: $|A| > |B|$ ise $A$'dan $B$'ye bire bir fonksiyon yoktur. Örnek: 3 yuva ve 4 güvercin varsa bir yuvada en az 2 güvercin olur. Teorem (ekrandan, 02:00:00): $n$ pozitif tamsayı olsun. $n^2 + 1$ farklı gerçel sayıdan oluşan her dizi, $n+1$ uzunluğunda artan ya da azalan bir alt dizi içerir. Slayttaki dizi $(19, 10, 9, 7, 11, 2, 21, 1, 20, 31)$, $10 = 3^2 + 1$ elemanlıdır. Artan alt dizi $(10, 11, 21, 31)$, derste bulunan azalan alt dizi $(19, 9, 7, 1)$ vardır. Bu alt diziler python ile kontrol edildi. Teoremin genel ispatı derste anlatılmadı, okumaya bırakıldı.

- **Alfabe ve dizgi** (ekrandan, 02:20:00). Alfabe sonlu, boş olmayan bir sembol kümesidir. Genelde $\Sigma$ ve $\Gamma$ kullanılır: $\Sigma_1 = \{0,1\}$, $\Sigma_2 = \{a, b, \dots, z\}$, $\Gamma = \{0, 1, x, y, z\}$. Dizgi, alfabedeki sembollerin sonlu bir dizisidir: 01101, $\Sigma_1$ üzerinde; abracadabra, $\Sigma_2$ üzerinde bir dizgidir. $|w|$, $w$'deki sembol sayısıdır. Uzunluğu 0 olan dizgi boş dizgidir ($\varepsilon$). $w = w_1 w_2 \cdots w_n$ ise $w^R = w_n \cdots w_2 w_1$. "cad", "abracadabra"nın alt dizgisidir.

- **Birleştirme ve kuvvet** (ekrandan, 02:25:00). $x = x_1 \dots x_m$, $y = y_1 \dots y_n$ ise $xy = x_1 \dots x_m y_1 \dots y_n$. $x^3 = xxx$, $x^n$ ise $x$'in $n$ kez birleştirilmesidir. $|uv| = |u| + |v|$. Örnekte $|w| = 5$ ve $|v| = 6$ için $|wv| = 11$.

- **Önek ve sonek** (ekrandan, 02:40:00). $w = xyyxy$ için önekler $x, xy, xyy, xyyx, xyyxy$, sonekler $y, xy, yxy, yyxy, xyyxy$'dir. $\varepsilon$ her dizginin hem öneki hem sonekidir. Her dizgi kendisinin öneki ve sonekidir.

- **Yıldız ve artı.** $\{a,b\}^* = \{\varepsilon, a, b, aa, ab, ba, bb, aaa, \dots\}$, yani alfabedeki sembollerin bütün olası birleştirmeleridir. $\Sigma^+ = \Sigma^* - \{\varepsilon\}$. $\Sigma^*$ o alfabenin "evrensel dili"dir; her dil onun bir alt kümesidir.

- **Dil örnekleri** (ekrandan, 02:45:00). $\Sigma = \{a, b\}$ üzerinde $L_1 = \{\varepsilon\}$, $L_2 = \{a, b, aa, ab, ba, bb\}$ (6 dizgi), $L_3 = \{\varepsilon, a, aa, aaa, \dots\}$ (sonsuz), $L_4 = \{a^n b^n : n \ge 0\} = \{\varepsilon, ab, aabb, aaabbb, \dots\}$. Rakam alfabesi üzerinde asal sayılar, çift sayılar ve tek sayılar da birer dildir. Buradaki rakamlar sembol olarak düşünülmelidir.
  - **Ders sonrası not:** Slaytta $L_4$'te "aaabbbb" yazıyor; $n = 3$ için doğrusu $aaabbb$'dir.

- **İşlemleri dil olarak yazmak** (ekrandan, 02:50:00). $\Sigma = \{1, +, =\}$ üzerinde $\text{ADDITION} = \{x + y = z : x = 1^m,\ y = 1^n,\ z = 1^k,\ k = m+n\}$. $111+11=11111 \in \text{ADDITION}$, $111+111=1111 \notin \text{ADDITION}$. $\Sigma = \{1, \#\}$ üzerinde $\text{SQUARES} = \{x\#y : x = 1^m,\ y = 1^n,\ n = m^2\}$. $111\#111111111$ (9 tane 1) kümededir, $1111\#11111111$ (8 tane 1) kümede değildir. Burada matematiksel işlem yapılmaz, yalnız sembol dizgilerinin kümeye ait olup olmadığına bakılır. Böylece bir toplamanın doğru olup olmadığı yalnız sembollerle anlaşılabilir.

- **Dil işlemleri ve kapalılık** (ekrandan, 02:30:00 ve 02:55:00). Birleşim $A \cup B = \{x \mid x \in A \text{ veya } x \in B\}$, birleştirme $A \circ B = \{xy \mid x \in A,\ y \in B\}$, yıldız $A^* = \{x_1 x_2 \dots x_k \mid k \ge 0,\ x_i \in A\}$. Düzenli diller birleşim, kesişim, tümleyen, birleştirme ve yıldız altında kapalıdır. Yani iki düzenli dile bu işlemler uygulanınca yine bir otomatın tanıyabileceği bir dil çıkar. Örnek: $A = \{a, ab, aaaa\}$, $B = \{ab, bb\}$ için $A \cup B = \{a, ab, bb, aaaa\}$, $A \cap B = \{ab\}$, $\overline{A} = \Sigma^* - A = \{\varepsilon, b, aa, ba, bb, aba, \dots\}$.
  - **Ders sonrası not:** Slaytta $A - B = \{a, bb, aaaa\}$ yazıyor; doğrusu $A - B = \{a, aaaa\}$'dır ($bb \notin A$). Slayttaki yıldız tanımında "$k > 0$" yazıyor; Sipser'deki tanım $k \ge 0$'dır ve $\varepsilon$ her zaman $A^*$'ın elemanıdır (hocanın $\{a,b\}^*$ örneğiyle de uyumlu). Slaytta tümleyen listesinde $b$ görünmüyor, oysa $b \notin A$ olduğu için $b \in \overline{A}$'dır.

- **Sonlu otomat** (ekrandan, 03:00:00). Sonlu otomat, giriş şeridindeki dizgiyi okur ve "kabul" ya da "ret" çıktısı verir. Dizgi dilin elemanıysa kabul edilir. Durumlar arasında sembollere göre geçiş yapılır; giriş bitince otomat kabul durumundaysa (çift halkalı durum) dizgi tanınmış olur. <!-- BELİRSİZ: hocanın 02:57 civarında gösterdiği q0-q5 durumlu örnek otomat karelerde görünmüyor; geçişler yalnız kısmen altyazıdan anlaşılıyor (q0 --a--> q1, bir durumdan b ile q5'e, a ile kabul durumu q4'e). -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
