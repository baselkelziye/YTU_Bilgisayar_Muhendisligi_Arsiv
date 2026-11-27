# Ders 11 Çalışma Özeti

## Genel Konular

- Ders büyük ölçüde İngilizce anlatıldı, bazı yerler Türkçe açıklandı.
  - Anlatım hazır slaytlar ve tablette el yazısıyla çözülen örnekler üzerinden ilerledi. Kayıtta iki ara var (yaklaşık 00:50-01:03 ve 01:50-02:05).
- Dil hiyerarşisi ve Turing makinesine geçiş
  - Düzenli diller ($a^*$, $a^*b^*$) NFA/DFA ile, bağlamdan bağımsız diller ($a^nb^n$, $ww^R$) PDA ile tanınır (ekrandan, 00:05:00).
  - $a^nb^nc^n$ ve $ww$ bağlamdan bağımsız değildir: CFG'leri, dolayısıyla PDA'ları yoktur. Bu diller Turing makinesiyle tanınır (ekrandan, 00:10:00).
  - Hocaya göre bugünkü bilgisayarlar ve cep telefonları birer Turing makinesi olarak görülebilir.
- Turing makinesinin yapısı
  - Sonsuz uzunlukta bir şerit (tape), şerit üzerinde okuyup yazan bir kafa (head) ve bir kontrol birimi vardır.
  - Şeridin her hücresi bir simge tutar. Kafa her adımda üç iş yapar: simgeyi okur, yerine bir simge yazar, bir hücre sola (L) ya da sağa (R) gider.
  - Boş hücreler $\Diamond$ (blank) ile gösterilir. Boş simge, giriş dizgisinin nerede başlayıp bittiğini gösterir (C'deki dizgi sonu `\0` gibi). Başka bir simge (\$, $\Delta$, 0) de seçilebilir.
  - Kafa her zaman giriş dizgisinin en soldaki simgesinden başlar (ekrandan, 00:15:00).
- Geçişler
  - $q_1 \xrightarrow{a \to b,\,R} q_2$: kafanın altındaki simge $a$ ise $a$ okunur, yerine $b$ yazılır, kafa sağa gider ve durum $q_2$ olur (ekrandan, 00:20:00).
  - Kafanın altında $\Diamond$ varken de geçiş yapılabilir ($\Diamond \to g, R$ gibi).
- Belirlenimcilik (determinism)
  - Turing makineleri belirlenimcidir: bir durumdan aynı okunan simge için iki geçiş olamaz. $q_1$'den $a \to b,R$ ve $b \to d,L$ izinlidir; $a \to b,R$ ve $a \to d,L$ izinli değildir (ekrandan, 00:25:00).
  - Epsilon geçişleri yoktur: her adımda uzunluğu 1 olan bir simge okunup yazılır.
- Kısmi geçiş fonksiyonu ve durma (halt)
  - Her durumda her simge için geçiş tanımlı olmak zorunda değildir.
  - İzlenecek geçiş yoksa makine durur (halts).
- Son durumlar ve kabul
  - Son (kabul) durumlarından çıkan geçiş yoktur; son duruma ulaşınca makine durur.
  - Kabul: makine bir son durumda durursa dizgi kabul edilir.
  - Ret: makine son olmayan bir durumda durursa ya da sonsuz döngüye girerse dizgi reddedilir (ekrandan, 00:35:00).
  - Gözlem: kabul ya da ret için dizginin tüm simgelerini taramak gerekmez.
- Düzenli diller için Turing makinesi örnekleri
  - $\Sigma=\{a,b\}$, $L=a^*$: $q_0$'da $a \to a,R$ döngüsü, $q_0 \xrightarrow{\Diamond \to \Diamond, L} q_1$ (son) (ekrandan, 00:40:00).
  - $aaa$ kabul edilir; $aba$ için $q_0$'da $b$ okunurken geçiş yoktur, makine durur ve dizgiyi reddeder (ekrandan, 00:45:00).
  - $\Sigma=\{a\}$ iken $a^*$ için başlangıç durumunun aynı zamanda son durum olduğu, geçişi olmayan tek durumlu makine yeterlidir; hiç tarama yapmadan kabul eder.
  - Sonsuz döngü örneği, $L=a^*+b(a+b)^*$: $q_0$'da $a\to a,R$ ve $b \to b,L$ döngüleri, $q_0 \xrightarrow{\Diamond\to\Diamond,L} q_1$ (son) (ekrandan, 00:50:00). $ab\ldots$ ile başlayan dizgide kafa iki hücre arasında sonsuza dek gidip gelir (ret); $b$ ile başlayan dizgide kafa sola, $\Diamond$'a gider ve makine kabul eder.
  - Tablette çözülen örnek: $r=b(a+b)^*b$ (ekrandan, 01:15:00 ve 01:20:00). Ders sonunda hoca çizimde bir döngüyü unuttuğunu söyleyip düzeltti.
- $\{a^nb^n : n\ge 1\}$ için Turing makinesi (ekrandan, 01:25:00)
  - Fikir: en soldaki $a$'yı $x$ yap, en soldaki $b$'yi bulup $y$ yap, geri dön; $a$ ve $b$ kalmayana dek tekrarla. Sonunda yalnız $y$'ler kalırsa kabul et.
  - $aaabbb \to xaaybb \to xxayyb \to xxxyyy$ (ekrandan, 01:30:00).
  - Hoca, aynı fikrin $a^nb^nc^n$ için Turing makinesine genişletilebileceğini söyledi ve bunu öğrencilere bıraktı.
- Biçimsel tanımlar
  - Geçiş fonksiyonu: $\delta(q_1,a)=(q_2,b,R)$ (ekrandan, 01:40:00).
  - Turing makinesi yedili: $M=(Q,\Sigma,\Gamma,\delta,q_0,\Diamond,F)$; tek başlangıç durumu vardır; $\Sigma \subseteq \Gamma$.
  - Anlık betim (instantaneous description): şerit $\Diamond\Diamond c\,a\,\underline{b}\,a\Diamond\Diamond$, durum $q_1$ ise $ca\,q_1\,ba$ yazılır (ekrandan, 01:45:00). Bir hamle $\succ$, birçok hamle $\overset{*}{\succ}$ ile gösterilir.
  - Başlangıç yapılandırması $q_0\,w$'dir. $L(M)=\{w : q_0 w \overset{*}{\succ} x_1 q_f x_2,\ q_f\in F\}$.
  - $M$ tarafından kabul edilen dile Turing-tanınabilir (Turing-recognizable), Turing-kabul edilebilir ya da özyinelemeli sayılabilir (recursively enumerable) denir.
- Turing makineleriyle fonksiyon hesaplama
  - Fonksiyon, $D$ tanım kümesinden $S$ sonuç kümesine bir eşlemedir: $w\in D$, $f(w)\in S$.
  - Sayılar birli (unary) gösterimle yazılır: 5 = $11111$.
  - $f$ hesaplanabilirdir (computable) $\iff$ her $w\in D$ için $q_0\,w \overset{*}{\succ} q_f\,f(w)$ olan bir $M$ vardır (ekrandan, 02:20:00).
  - Toplama $f(x,y)=x+y$: giriş $x0y$, çıkış $xy0$. Örnek $3+5$: $111011111 \to 111111110$ (ekrandan, 02:25:00). Makine $0$'ı $1$ yapar, en sağdaki $1$'i $0$ yapar, başa döner (ekrandan, 02:40:00).
  - İkiye katlama $f(x)=2x$: her $1$ önce \$ yapılır; her \$ için \$ yeniden $1$ olur ve sona bir $1$ eklenir. $11 \to 1111$ (ekrandan, 02:45:00).
  - Karşılaştırma: $f(x,y)=1$ ($x>y$), $0$ ($x\le y$). Hoca bunu birim basamak fonksiyonu $u(x-y)$ ile ilişkilendirdi. Sözde kod: $x$'teki $1$'leri $y$'deki $1$'lerle eşleştir.
  - Turing makinelerinin birleştirilmesi: karşılaştırıcı, toplayıcı ve silici blokları birleştirilerek $x>y$ ise $x+y$, değilse $0$ hesaplanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kafa her zaman giriş dizgisinin en soldaki simgesinden başlar.
  - Hoca bunun kural olduğunu ve çok önemli olduğunu iki kez söyledi.
- Son durumdan çıkan geçiş olamaz.
  - Hoca, sınavda son durumdan çıkan geçiş çizilen çözümlerin tanıma aykırı olduğu için yanlış sayılacağını vurguladı.
- Turing makineleri belirlenimcidir ve epsilon geçişi yoktur.
- Verilen bir düzenli ifade için Turing makinesi tasarlamak basit bir soru türüdür; hoca bu tür soruların sorulabileceğini söyledi.
- Turing makinesi bir hesaplayıcıdır ve sayarak (counting) hesaplar.
  - $a^nb^n$ makinesi $a$ ve $b$ sayılarını karşılaştırır; toplama makinesi birli gösterimdeki $1$'leri bir araya getirir.
  - Hoca "computer" kelimesinin karşılığının "hesaplayıcı" olduğunu, "bilgisayar" sözcüğünün bu anlamı tam vermediğini söyledi.

## Kısa Tekrar Notları

- Turing makinesi = sonsuz şerit + okuma/yazma kafası + kontrol birimi.
- Geçiş etiketi $a \to b, R$: oku $a$, yaz $b$, sağa git.
- $\Diamond$ boş hücredir; giriş dizgisini sınırlar.
- Kafa en soldaki giriş simgesinden başlar.
- Belirlenimci, epsilon geçişi yok, geçiş fonksiyonu kısmi olabilir.
- Geçiş yoksa makine durur. Son durumda durursa kabul, değilse ret. Sonsuz döngü de rettir.
- Son durumdan çıkan geçiş yoktur.
- Kabul için bütün girişi okumak gerekmez.
- $M=(Q,\Sigma,\Gamma,\delta,q_0,\Diamond,F)$, $\Sigma\subseteq\Gamma$.
- Anlık betim: $u\,q\,v$ (kafa $v$'nin ilk simgesinde).
- Turing-tanınabilir = Turing-kabul edilebilir = özyinelemeli sayılabilir.
- Hesaplanabilir fonksiyon: $q_0 w \overset{*}{\succ} q_f f(w)$.
- Birli gösterim: $n$ sayısı $n$ tane $1$ ile yazılır. Toplama: $x0y \to xy0$.

## Detaylı Açıklamalar

- **Neden Turing makinesi?** Düzenli diller için NFA/DFA, bağlamdan bağımsız diller için PDA yeterlidir. $a^nb^nc^n$ dilinde $a$, $b$ ve $c$ sayıları arasında birden fazla eşitlik ilişkisi vardır; tek yığıtla bu denetlenemez, dilin CFG'si ve PDA'sı yoktur. $ww$ (bir dizginin kendisiyle birleştirilmesi) de aynı durumdadır. Bu diller için daha güçlü bir makine gerekir: Turing makinesi. PDA'da yalnız yığıtın tepesine erişilir; Turing makinesinde kafa şeridin her yerine gidip okuyup yazabilir. Bu yüzden Turing makinesi PDA'dan güçlüdür.

- **Bir adımın anlamı.** $q_1 \xrightarrow{a\to b,R} q_2$ geçişi, makine $q_1$'deyken kafanın altında $a$ varsa geçerlidir. Slayttaki örnekte şerit $abac$, kafa üçüncü hücredeki $a$ üzerinde ve durum $q_1$ iken geçiş uygulanınca şerit $abbc$ olur, kafa $c$'ye kayar, durum $q_2$ olur (ekrandan, 00:20:00). Aynı geçiş $L$ ile olsaydı kafa sola, $b$'nin üstüne giderdi.

- **Durma, kabul ve ret.** Makinenin kabul ya da ret kararı durduğu yere bakılarak verilir. $a^*$ makinesinde $aaa$ girişi için kafa sağa ilerler, $\Diamond$'ı görünce sola bir adım atıp $q_1$'e (son durum) geçer ve kabul eder. $aba$ girişinde $q_0$'da $b$ için geçiş olmadığından makine ikinci simgede durur. $q_0$ son durum olmadığı için dizgi reddedilir; üçüncü simgeye hiç bakılmaz.

- **Sonsuz döngü.** $a^*+b(a+b)^*$ makinesinde $q_0$'da $a\to a,R$ ve $b\to b,L$ döngüleri vardır. Girişin ilk simgesi $b$ ise kafa hemen sola, $\Diamond$'a gider; $\Diamond\to\Diamond,L$ ile $q_1$'e geçilir ve dizgi kabul edilir; kalan simgelere bakmaya gerek yoktur, çünkü alfabe $\{a,b\}$ olduğundan $b$ ile başlayan her dizgi dildedir. Giriş yalnız $a$'lardan oluşuyorsa kafa sona kadar gider ve kabul eder. $ab\ldots$ ile başlayan girişte ise kafa $a$'dan $b$'ye, $b$'den $a$'ya sonsuza dek gidip gelir; makine hiç durmaz ve dizgi reddedilmiş sayılır (ekrandan, 01:05:00).

- **$b(a+b)^*b$ makinesi.** Dil, $b$ ile başlayıp $b$ ile biten, uzunluğu en az 2 olan dizgilerdir: $b \notin L(r)$, $bb, bab, baab \in L(r)$ (ekrandan, 01:20:00). Tablette çizilen makine: $q_0 \xrightarrow{b\to b,R} q_1$; $q_1 \xrightarrow{a\to a,R} q_2$; $q_1 \xrightarrow{b\to b,R} q_3$; $q_2 \xrightarrow{b\to b,R} q_3$; $q_3 \xrightarrow{a\to a,R} q_1$; $q_3 \xrightarrow{\Diamond\to\Diamond,L} q_4$ (son). Hoca ikinci aradan sonra bir döngünün unutulduğunu, yoksa $bbb$ gibi dizgilerin tanınamayacağını söyledi; düzeltilmiş kare kayıtta yok. <!-- BELİRSİZ: Hocanın kırmızıyla eklediği döngü kayıttaki karelerde görünmüyor. -->
  - Ders sonrası not: Python benzetimine göre doğru bir makine için iki döngü gerekir: $q_3$'te $b\to b,R$ ($bbb$ için) ve $q_2$'de $a\to a,R$ ($baab$ için). İkisi eklenince uzunluğu 7'ye kadar olan bütün $\{a,b\}$ dizgilerinde makine dili doğru tanıyor.

- **$a^nb^n$ makinesi.** Geçişler (ekrandan, 01:25:00): $q_0\xrightarrow{a\to x,R}q_1$; $q_1$'de $a\to a,R$, $y\to y,R$ döngüleri; $q_1\xrightarrow{b\to y,L}q_2$; $q_2$'de $a\to a,L$, $y\to y,L$ döngüleri; $q_2\xrightarrow{x\to x,R}q_0$; $q_0\xrightarrow{y\to y,R}q_3$; $q_3$'te $y\to y,R$ döngüsü; $q_3\xrightarrow{\Diamond\to\Diamond,L}q_4$ (son). Her turda bir $a$ $x$'e, bir $b$ $y$'ye çevrilir; yani makine durumlar ve şerit içeriğiyle $a$ ve $b$ sayılarını eşleştirir. $q_0$'da $a$ yerine $y$ görülürse bütün $a$'lar bitmiştir; $q_3$ sağa doğru yalnız $y$ görüp $\Diamond$'a ulaşırsa bütün $b$'ler de bitmiştir ve dizgi kabul edilir. $aabb$ ve $aaabbb$ için makine python ile benzetildi; ikisi de $q_4$'te kabul edilir (şerit $xxyy$, $xxxyyy$).

- **Fonksiyon hesaplama.** Toplama makinesi (ekrandan, 02:40:00): $q_0$'da $1\to1,R$ döngüsü; $q_0\xrightarrow{0\to1,R}q_1$; $q_1$'de $1\to1,R$ döngüsü; $q_1\xrightarrow{\Diamond\to\Diamond,L}q_2$; $q_2\xrightarrow{1\to0,L}q_3$; $q_3$'te $1\to1,L$ döngüsü; $q_3\xrightarrow{\Diamond\to\Diamond,R}q_4$ (son). $11011$ ($2+2$) girişi $11110$ olur, yani 4. İkiye katlama makinesi (ekrandan, 02:45:00): $q_0$'da $1\to\$,R$; $q_0\xrightarrow{\Diamond\to\Diamond,L}q_1$; $q_1$'de $1\to1,L$; $q_1\xrightarrow{\$\to1,R}q_2$; $q_2$'de $1\to1,R$; $q_2\xrightarrow{\Diamond\to1,L}q_1$; $q_1\xrightarrow{\Diamond\to\Diamond,R}q_3$ (son). Hoca toplama yapılabiliyorsa çıkarma, çarpma ve bölmenin de yapılabileceğini, böylece her şeyin saymaya dayandığını anlattı. İki makine de python ile çeşitli girişlerde benzetildi ve doğru sonuç verdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
