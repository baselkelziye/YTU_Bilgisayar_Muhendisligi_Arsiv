# Ders 7 Çalışma Özeti

## Genel Konular

- Birinci vize sorularının çözümü (ekrandan, 00:10:00 - 00:25:00)
  - Soru 1: $R=\{(x,y)\in\mathbb{Z}^2 \mid xy\ge 1\}$ bağıntısının özellikleri. $0\cdot 0 = 0$ olduğu için refleksif değil; $1\cdot 1 = 1$ olduğu için irrefleksif de değil; köşegenin bir kısmı var, bir kısmı yok, yani nonrefleksif. Çarpma değişmeli olduğu için simetrik; $(1,2)$ ve $(2,1)$ birlikte bulunduğu için antisimetrik değil; geçişli.
  - Soru 2: $S=\{0,2,5,10,11,15\}$ üzerinde $x\le y$ bağıntısı refleksif, antisimetrik ve geçişli olduğu için sıralama bağıntısıdır; Hasse diyagramı çizilebilir. Grafın üzerinden refleksif halkalar ve geçişlilikten gelen kenarlar silinince geriye $0-2-5-10-11-15$ zinciri kalır.
  - Soru 3: Kredi problemi. Doğruluk tablosu 16 satırdır, $F(E,A,B,I)=\sum m(1,3,5,6,7,8,9,10,11,12,13,14,15)$. Karnaugh haritasında iki 8'li ve bir 4'lü grupla $F = I + E + AB$ bulunur.
  - Soru 4: Bir ifadenin prefix ve postfix gösterimi; kök alma işlemi $1/3$ üssüyle ($\uparrow$) yazılır.
  - Soru 5: İç içe iki döngülü bir algoritmanın işlem sayısı $T(n)$ ve büyük O gösterimi: $T(n)=5n^2+12n+c$, yani $O(n^2)$.
- Öz yinelemeli (rekürsif) bağıntılar ve çözüm yöntemleri
  - $n$ bağımsız değişkenine göre ifade edilen ve kendi önceki değerlerini içinde bulunduran fonksiyonlardır; örneğin $T(n)=T(n-1)+1$ (ekrandan, 00:30:00).
  - Çözüm yöntemleri: ileri yerine koyma (forward substitution), geri yerine koyma (backward substitution), özyineleme ağacı, Master teoremi, karakteristik denklem yöntemi (2. ve daha yüksek dereceden bağıntılar için).
  - Örnekler: $T(n)=T(n-1)+1$, $T(1)=2$ için $T(5)=6$; $f(n)=n+f(n-1)$, $f(1)=1$ için $f(5)=15$ (ekrandan, 00:35:00); faktöriyel $f(n)=n\cdot f(n-1)$ (ekrandan, 00:40:00).
- Rekürans bağıntısı ile dizi arasındaki fark
  - Bir dizinin içinde kendisinden bir parça varsa rekürans bağıntısıdır (ekrandan, 00:45:00). $a_n=5n+1$ bir dizidir, $a_{20}=101$ doğrudan bulunur. $a_n=2a_{n-1}+3$ ise rekürans bağıntısıdır; $a_0=3$ verilince $a_1=9$ olur.
  - Rekürans bağıntısında $a_{99}$'u bulmak için bütün ara terimlerin hesaplanması gerekir; amaç bağıntıyı çözüp $n$'ye bağlı kapalı bir formül elde etmektir.
- Rekürans bağıntılarının sınıflandırılması
  - Derece: $a_n$'nin kendisinden önceki en uzak terime göre belirlenir. $a_n=5a_{n-1}+n^2$ 1., $a_n=3a_{n-1}-5a_{n-2}$ 2., $a_n=3a_{n-1}+a_{n-3}+3^n$ 3., $a_n=2a_{n-4}+1$ 4. derecedir (ekrandan, 00:50:00).
  - Homojenlik: bağıntıda $a$ içermeyen bir terim (sabit sayı ya da $n$'ye bağlı ifade) varsa homojen değildir.
  - Lineerlik: $a$'lı terimlerin üssünün alınması ya da birbirleriyle çarpılması lineerliği bozar (ekrandan, 00:55:00).
  - Sabit katsayılılık: $a$'lı terim $n$'li bir şeyle çarpılmışsa (örneğin $n\cdot a_{n-1}$ ya da $3^n a_{n-2}$) sabit katsayılı değildir.
- Sabit katsayılı homojen bağıntıların karakteristik kök yöntemiyle çözümü
  - En yüksek indisli terime $r^k$, sonrakilere $r^{k-1},\dots,1$ yazılarak karakteristik denklem kurulur. $a_n=3a_{n-1}+4a_{n-2}$ için $r^2-3r-4=0$, kökler $4$ ve $-1$ (ekrandan, 01:10:00).
  - Farklı kökler: $a_n^{(h)}=c_1r_1^n+c_2r_2^n$. Çakışık kökler: $a_n^{(h)}=c_1r^n+c_2\,n\,r^n$; daha fazla çakışmada $n^2, n^3$ çarpanları eklenir.
  - $c_1, c_2$ başlangıç koşullarından bulunur.
- Homojen olmayan bağıntılar
  - Genel çözüm: $a_n = a_n^{(h)} + a_n^{(\text{ö})}$. Özel çözüm $a_n^{(\text{ö})}$, homojenliği bozan $f(n)$'ye bakılarak tahmin edilir (ekrandan, 01:30:00).
  - $f(n)$ sabitse özel çözüm $A$; birinci dereceden polinomsa $An+B$; üstel $k^n$ ise $A\cdot k^n$ alınır.
  - Üstel terim homojen çözümdeki bir kökle çakışıyorsa özel çözüm $n$ ile, iki kökle çakışıyorsa $n^2$ ile çarpılır (ekrandan, 01:40:00).
- Sayı dizilerini ve sözel problemleri rekürans bağıntısına dönüştürme
  - $4,7,13,25,49,97,\dots$ için $a_0=4$, $a_n=2a_{n-1}-1$ (ekrandan, 02:05:00).
  - $1,3,7,17,41,99,239,\dots$ için $a_0=1$, $a_1=3$, $a_n=2a_{n-1}+a_{n-2}$ (ekrandan, 02:10:00).
  - Ardışık iki terimin toplamına $2^{n-1}$ eklenerek üretilen bir dizi için $a_n=a_{n-1}+a_{n-2}+2^{n-1}$.
  - Sözel problem: $n$ uzunluğundaki 0-1 dizilerinden "00" içerenlerin sayısı (ekrandan, 02:15:00).
- Problemlerin karmaşıklık sınıfları
  - Tractable (çözülebilir): en kötü durumda polinom zamanlı bir algoritmayla çözülebilen problem.
  - Intractable (çözülemez): polinom zamanlı bir algoritmayla çözülemeyen problem; pratikte özel durumlar ya da yaklaşık çözümlerle üstesinden gelinebilir (ekrandan, 02:25:00).
  - Unsolvable problemler, P, NP ve NP-tam sınıfları terim olarak anıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hasse diyagramı, bağıntının grafı değildir
  - Bağıntıyı sağlayan bütün kenarlarla çizilen graf Hasse diyagramı olarak verilmemelidir. Önce refleksif halkalar, sonra $(x,y)$ ve $(y,z)$ varken gelen $(x,z)$ kenarları silinir.
  - Hasse diyagramı denklik bağıntısı için değil, kısmi sıralama bağıntısı (refleksif, antisimetrik, geçişli) için çizilir.
- İrrefleksif ve nonrefleksif farkı
  - İrrefleksifte köşegen elemanlarının hiçbiri bağıntıda yoktur; nonrefleksifte bir kısmı vardır, bir kısmı yoktur.
- Rekürans bağıntısını çözmenin amacı
  - Çözülmemiş bir bağıntıda $a_{80}$ için $a_{79}, a_{78}, \dots$ bütün terimler hesaplanmalıdır. Çözülmüş kapalı formülde yalnız $n$ yerine değer konur.
- İki tür beceri gerekir
  - Verilen bir rekürans bağıntısını çözmek ve sözel olarak verilen bir problemi rekürans bağıntısı olarak modellemek. İkincisi daha zordur; dizinin örüntüsünü görmek kişiden kişiye değişir ve her zaman bulunamayabilir.
- Üstel özel çözümde çakışma kontrolü
  - Özel çözüm yazılmadan önce $f(n)$'deki üstel tabanın homojen çözüm köklerinden biriyle aynı olup olmadığına bakılmalıdır.

## Kısa Tekrar Notları

- $xy\ge 1$ bağıntısı ($\mathbb{Z}$ üzerinde): nonrefleksif, simetrik, geçişli; refleksif, irrefleksif ve antisimetrik değil.
- Hasse = sıralama bağıntısının grafından halkalar ve geçişli kenarlar silinmiş hali.
- Rekürans bağıntısı: içinde kendisinden bir parça bulunan dizi; ilk değer(ler) verilmelidir. $k$. dereceden bağıntı için $k$ başlangıç değeri gerekir.
- Derece: en uzak geri terim; homojen: $a$ içermeyen terim yok; lineer: $a$'lı terimlerin üssü ya da çarpımı yok; sabit katsayılı: $a$'lı terimler yalnız sabitlerle çarpılmış.
- Karakteristik denklem: $a_n = p\,a_{n-1}+q\,a_{n-2} \Rightarrow r^2-pr-q=0$.
- Farklı kökler: $c_1r_1^n+c_2r_2^n$; çakışık kök: $(c_1+c_2n)r^n$.
- Genel çözüm $= a_n^{(h)}+a_n^{(\text{ö})}$; özel çözüm tahmini: sabit $\to A$, $n$'nin 1. dereceden polinomu $\to An+B$, $k^n \to A k^n$ (kökle çakışırsa $n$, $n^2$ çarpanı).
- $c_1, c_2$ katsayıları her zaman özel çözüm eklendikten sonra, genel çözüm üzerinden bulunur.
- Tractable: polinom zamanda çözülebilir; intractable: polinom zamanda çözülemez.

## Detaylı Açıklamalar

- Vize sorusundaki bağıntı ve Hasse diyagramı
  - $\mathbb{Z}$ üzerinde $xy\ge 1$ koşulunda $1\cdot 1$, $2\cdot 2$, $(-1)(-1)$ gibi çiftler bağıntıdadır ama $0\cdot 0=0$ olduğu için $(0,0)$ yoktur. Köşegenin tamamı ne var ne de yok olduğu için bağıntı nonrefleksiftir. $xy\ge1$ ve $yz\ge1$ ise $x,y,z$ sıfırdan farklı ve aynı işaretlidir; bu yüzden $xz\ge1$ olur ve bağıntı geçişlidir.
  - $S=\{0,2,5,10,11,15\}$ üzerinde $\le$ bağıntısının çiftleri önce köşegen ($(0,0),(2,2),\dots$), sonra $x<y$ olan bütün çiftlerdir. Bu tam sıralı bir küme olduğu için Hasse diyagramı tek bir zincirdir: $0 - 2 - 5 - 10 - 11 - 15$.
- Kredi probleminin Karnaugh çözümü
  - Değişkenler: ev ($E$), araba ($A$), bankada belirli miktarın üzerinde para ($B$), iş yeri ($I$). Kural: en az bir ev ya da iş yeri varsa kredi verilir; ikisi de yoksa hem para hem araba olmalıdır.
  - Haritada $I=1$ olan 8'li grup ve $E=1$ olan 8'li grup alınır; açıkta kalan $0110$ hücresi, önceden gruplanmış hücrelerle birlikte $AB$ dörtlüsüne katılır. Sonuç $F = I + E + AB$.
- Prefix ve postfix
  - Hoca derste ifadeyi "$a^2$ ile $b^2$ çarpılır, $c^2$ çıkarılır, $a$'ya bölünür, sonra küp kökü alınır" sırasıyla okudu ve önce prefix, sonra postfix biçimini yazdı (ayrıntı genişletilmiş notta).
  - <!-- BELİRSİZ: Ekrandaki cevap anahtarı kökü yalnız parantez içine uygulayarak farklı bir sıra veriyor; iki okuma genişletilmiş notta karşılaştırıldı. -->
- Algoritma analizi sorusu
  - Dış döngü $i=n$'den $2n$'ye kadar döner: $n+1$ tur, $n+2$ karşılaştırma. İç döngü $j=1$'den $j+n\le 2n$ olana kadar döner: dış döngünün her turunda $n$ tur, $n+1$ karşılaştırma.
  - Her satırın işlem sayısı frekansıyla çarpılıp toplanır. Sabit terim sayma ayrıntısına göre değişebilir, ama baskın terim $5n^2$'dir ve karmaşıklık $O(n^2)$'dir.
- İleri yerine koyma
  - $T(n)=T(n-1)+1$, $T(1)=2$ için $T(5)$ istenirse $T(4)$, $T(3)$, $T(2)$ gerekir. $T(1)=2$'den başlanarak ileri doğru $T(2)=3$, $T(3)=4$, $T(4)=5$, $T(5)=6$ bulunur.
  - $1+2+\dots+n=\frac{n(n+1)}{2}$ toplamı Gauss'un yöntemiyle (dizi bir de tersten yazılıp toplanır, $n$ tane $n+1$ elde edilir, ikiye bölünür) bulunur. Aynı toplam $f(n)=n+f(n-1)$, $f(1)=1$ bağıntısıyla da ifade edilir: $f(5)=15=\frac{5\cdot 6}{2}$.
  - Faktöriyel: $n! = n\cdot (n-1)!$, $0! = 1$. Fonksiyon kendini çağırarak $f(0)$'a kadar iner, dönüşte değerler çarpılır.
- Karakteristik kök yönteminin örnekleri
  - $a_n=3a_{n-1}+10a_{n-2}$, $a_0=5$, $a_1=8$: $r^2-3r-10=0$, kökler $5$ ve $-2$. $c_1+c_2=5$, $5c_1-2c_2=8$ denklemlerinden $c_1=\frac{18}{7}$, $c_2=\frac{17}{7}$. Sonuç $a_n=\frac{18}{7}5^n+\frac{17}{7}(-2)^n$ (ekrandan, 01:15:00; python ile doğrulandı).
  - $a_n=-4a_{n-1}-4a_{n-2}$, $a_0=3$, $a_1=5$: $r^2+4r+4=0$, çakışık kök $r=-2$. $a_n=c_1(-2)^n+c_2\,n(-2)^n$; $c_1=3$, $c_2=-\frac{11}{2}$ (ekrandan, 01:20:00; python ile doğrulandı).
- Homojen olmayan bağıntı örnekleri
  - $a_n=2a_{n-1}+3a_{n-2}+5$, $a_0=4$, $a_1=10$: homojen kısım $c_13^n+c_2(-1)^n$; özel çözüm $A=2A+3A+5 \Rightarrow A=-\frac54$. Başlangıç koşullarıyla $c_1=\frac{33}{8}$, $c_2=\frac98$: $a_n=\frac{33}{8}3^n+\frac98(-1)^n-\frac54$ (ekrandan, 01:30:00).
  - $a_n=a_{n-1}+2a_{n-2}+3n+4$, $a_0=5$, $a_1=7$: homojen kısım $c_12^n+c_2(-1)^n$; özel çözüm $An+B$, $A=-\frac32$, $B=-\frac{23}{4}$ (ekrandan, 01:35:00).
  - $a_n=-4a_{n-1}-3a_{n-2}+2\cdot 5^n$, $a_0=6$, $a_1=10$: kökler $-3$ ve $-1$; $5^n$ bunlarla çakışmaz; özel çözüm $A\cdot 5^n$, $A=\frac{25}{24}$ (ekrandan, 01:40:00).
  - $a_n=2a_{n-1}+3a_{n-2}+3^n$, $a_0=7$, $a_1=5$: kökler $3$ ve $-1$; $3^n$ bir kökle çakıştığı için özel çözüm $A\cdot n\cdot 3^n$, $A=\frac34$ (ekrandan, 01:45:00).
- "00" içeren 0-1 dizileri
  - $n=0,1,2,3,4$ için sayılar elle listelenir: $0,0,1,3,8$. Hoca bu ilk terimlerden $a_n=2a_{n-1}+a_{n-2}+1$ ($n\ge2$, $a_0=a_1=0$) bağıntısını çıkardı (ekrandan, 02:15:00).
  - Ders sonrası not: Bu bağıntı ilk beş terimi tutturuyor ama $n=5$ için $20$ veriyor; gerçek sayı $19$'dur (python ile sayıldı). Doğru bağıntı $a_n=a_{n-1}+a_{n-2}+2^{n-2}$'dir (ayrıntı genişletilmiş notta).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
