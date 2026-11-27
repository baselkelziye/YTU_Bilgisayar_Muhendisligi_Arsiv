# Ders 7 Çalışma Özeti

## Genel Konular

- Ders büyük ölçüde İngilizce anlatıldı, bazı yerler Türkçe açıklandı.
  - Kayıtta iki ara var (yaklaşık 00:52-01:06 ve 01:57-02:12).
  - Anlatım hazır slaytlar ve tablette el yazısıyla çözülen örnekler üzerinden ilerledi.
- Bağlamdan bağımsız diller (context-free languages, CFL)
  - Düzenli diller CFL'lerin alt kümesidir. $a^*b^*$ ve $(a+b)^*$ düzenlidir; $\{a^nb^n : n \ge 0\}$ ve $\{ww^R\}$ düzenli değildir ama bağlamdan bağımsızdır (ekrandan, 00:05:00).
  - Bu dillerde semboller arasında bir "bağlam" vardır: $a$ sayısı $b$ sayısına eşit olmalı ya da ikinci yarı ilk yarının tersi olmalı. Belleği sınırlı bir NFA/DFA bunu tanıyamaz.
  - CFL'ler düzenli ifadeyle değil bağlamdan bağımsız gramerle (CFG) ifade edilir ve NFA/DFA ile değil yığıtlı otomatla (pushdown automaton, PDA) tanınır. PDA = otomat + yığıt (stack).
- Gramer kavramı ve İngilizce örnek
  - $\langle sentence\rangle \to \langle noun\_phrase\rangle\langle predicate\rangle$, $\langle noun\_phrase\rangle \to \langle article\rangle\langle noun\rangle$, $\langle predicate\rangle \to \langle verb\rangle$; $\langle article\rangle \to a \mid the$, $\langle noun\rangle \to cat \mid dog$, $\langle verb\rangle \to runs \mid sleeps$ (ekrandan, 00:10:00).
  - "the dog sleeps" ve "a cat runs" türetildi. Gramerin dili 8 cümleden oluşur (ekrandan, 00:15:00).
- Üretim kuralları, değişkenler, uç simgeler (terminals)
  - Değişkenler (variables) büyük harfle, uç simgeler küçük harfle yazılır. Uç simge başka bir şeye dönüşmez.
  - $S \to aSb \mid \varepsilon$ gramerinden $ab$, $aabb$, $aaabbb$ türetildi; bu gramer $\{a^nb^n : n\ge 0\}$ dilini üretir.
- Kısaltma gösterimleri
  - $\overset{*}{\Rightarrow}$: bir ya da daha çok türetim adımı (ekrandan, 00:20:00). Sıfır adım için de $w \overset{*}{\Rightarrow} w$ yazılır.
  - $\mid$ (dikey çizgi) "ya da" anlamındadır: $S \to aSb$ ve $S \to \varepsilon$ birlikte $S \to aSb \mid \varepsilon$ yazılır.
- Gramerin biçimsel tanımı: $G = (V, T, S, P)$ (ekrandan, 00:25:00)
  - $V$ değişkenler, $T$ uç simgeler, $S$ başlangıç değişkeni, $P$ üretimler.
  - $L(G) = \{w \in T^* : S \overset{*}{\Rightarrow} w\}$.
  - $L$ bağlamdan bağımsızdır $\iff$ $L = L(G)$ olan bir CFG $G$ vardır (ekrandan, 00:30:00).
- Gramer örnekleri
  - $S \to aSa \mid bSb \mid \varepsilon$: $L = \{ww^R : w \in \{a,b\}^*\}$ (ekrandan, 00:35:00).
  - Eşleşen parantezler: $L(G) = \{w : n_a(w) = n_b(w)$ ve her önek $v$ için $n_a(v) \ge n_b(v)\}$; $a = ($, $b = )$ (ekrandan, 00:40:00).
- En soldan ve en sağdan türetim (leftmost / rightmost derivation)
  - Örnek gramer: $S \to AB$, $A \to aaA \mid \varepsilon$, $B \to Bb \mid \varepsilon$; dizgi $aab$ (ekrandan, 00:45:00).
- Türetim ağacı (parse tree) ve ürünü (yield) (ekrandan, 00:50:00)
- Belirsizlik (ambiguity)
  - $E \to E+E \mid E*E \mid (E) \mid a$ gramerinde $a+a*a$ için iki farklı türetim ağacı vardır (ekrandan, 01:20:00).
  - if-then-else (dangling else) örneği.
  - Belirsiz gramerin belirsiz olmayan eşdeğeri: $E \to E+T \mid T$, $T \to T*F \mid F$, $F \to (E) \mid a$ (ekrandan, 01:40:00).
  - Doğası gereği belirsiz dil: $\{a^nb^nc^m\} \cup \{a^nb^mc^m\}$ (ekrandan, 01:45:00).
- Sonlu otomattan gramer yazma, iki dilin bitiştirmesinin grameri, bir DFA'nın grameri ve düzenli ifadesi
- Bir dilin bağlamdan bağımsız olup olmadığını sezgisel olarak değerlendirme ("bağlam sayısı") örnekleri; pompalama önsavına (CFL için) giriş olarak anıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağlamdan bağımsız diller sonraki sınavlarda ve finalde çok önemli yer tutacak.
- $a+a*a$ gibi bir ifade bu derste bir dizgidir, aritmetik işlem değildir.
  - Dil, dizgilerin kümesidir. $+$, $*$, parantez ve $a$ yalnız sembollerdir. Hoca, geçmişte bu dizgiyi hesaplayıp "sonuç 5" gibi yorum yapanların yanlış yaptığını vurguladı.
- Programlama dillerinde her dizginin tek bir türetim ağacı olmalıdır.
  - Aynı dizgi için iki ağaç olursa derleyici ifadeyi iki farklı biçimde yorumlayabilir: $a=2$ için $2+2*2$ bir ağaçta 6, diğerinde 8 verir.
- Bir dilin birden çok grameri olabilir. Bazıları belirsiz, bazıları belirsiz olmayabilir. Hoca bunun iyi bir doğru-yanlış sorusu olduğunu söyledi.
- Sınavda türetim ağacı çizmeniz istenebilir.
- Düzenli diller CFL'nin alt kümesidir; her düzenli dilin bir CFG'si vardır ama her CFL'nin düzenli ifadesi yoktur.

## Kısa Tekrar Notları

- CFG: $G=(V,T,S,P)$, üretimler $A \to x$ biçiminde, $A$ tek değişken.
- $L(G)=\{w\in T^* : S\overset{*}{\Rightarrow}w\}$.
- $S\to aSb\mid\varepsilon$ $\Rightarrow$ $\{a^nb^n:n\ge0\}$; $S\to aSa\mid bSb\mid\varepsilon$ $\Rightarrow$ $\{ww^R\}$.
- En soldan türetim: her adımda en soldaki değişken açılır; en sağdan türetim: en sağdaki.
- En soldan ve en sağdan türetim aynı ağacı verebilir; sıra bazen önemli değildir.
- Belirsiz gramer: bir dizginin iki farklı türetim ağacı (eşdeğer olarak iki farklı en soldan türetimi) vardır.
- $E\to E+E\mid E*E\mid(E)\mid a$ belirsizdir; $E\to E+T\mid T$, $T\to T*F\mid F$, $F\to(E)\mid a$ aynı dili belirsizlik olmadan üretir (öncelik değişkenlerle kodlanır).
- Doğası gereği belirsiz dil: onu üreten her gramer belirsizdir. Örnek: $\{a^nb^nc^m\}\cup\{a^nb^mc^m\}$ ($abc$ iki kümede de var).
- Sonlu otomattan gramer: her durum bir değişken; $q \xrightarrow{x} p$ geçişi $Q \to xP$; kabul durumu için $Q\to\varepsilon$.
- İki gramerin bitiştirmesi: yeni başlangıç $S\to S_1S_2$; çakışan değişken adları yeniden adlandırılır.
- $\{a^nb^ma^n\}$ CFL'dir; $\{a^nb^na^n\}$ CFL değildir.

## Detaylı Açıklamalar

- **Neden yeni bir dil sınıfı?** $\{a^nb^n\}$ dilinde makinenin önce $a$'ları, sonra $b$'leri tanıması ve sayılarının eşit olduğunu da doğrulaması gerekir. Sayının sınırı olmadığı için sonlu belleği olan NFA/DFA bunu yapamaz. $\{ww^R\}$ dilinde de ikinci yarının ilk yarının tersi olduğu denetlenmelidir. Bu "bağlam" ilişkileri düzenli ifadeyle anlatılamaz; bunun için bağlamdan bağımsız gramer kullanılır. Bu dilleri tanıyan makine, bir otomata yığıt eklenerek elde edilen yığıtlı otomattır.
- **Gramer ve türetim.** Gramer, doğal dillerde olduğu gibi cümle kurma kurallarıdır. $S\to aSb\mid\varepsilon$ gramerinde $S\Rightarrow aSb\Rightarrow aaSbb\Rightarrow aaaSbbb\Rightarrow aaabbb$ türetimi her adımda $S$'nin bir üretimle değiştirilmesiyle yapılır. Kısaca $S\overset{*}{\Rightarrow}aaabbb$ yazılır. $|$ işareti aynı değişkenin seçeneklerini birleştirir.
- **Biçimsel tanım.** $S\to aSb\mid\varepsilon$ için $V=\{S\}$, $T=\{a,b\}$, başlangıç değişkeni $S$, $P=\{S\to aSb,\ S\to\varepsilon\}$ (ekrandan, 00:25:00). $\varepsilon$ boş dizgidir, alfabenin elemanı değildir. Tablette $S\to aSa\mid bSb\mid\varepsilon$ için $G=(\{S\},\{a,b\},S,\{S\to aSa, S\to bSb, S\to\varepsilon\})$ yazıldı ve $S\Rightarrow aSa\Rightarrow abSba\Rightarrow abaSaba\Rightarrow abaaba$ türetildi (ekrandan, 00:35:00); $abaaba$ dizgisinde ilk yarının tersi ikinci yarıdır.
- **Eşleşen parantezler.** Slayttaki türetimler: $S\Rightarrow SS\Rightarrow aSbS\Rightarrow abS\Rightarrow ab$ ve $S\Rightarrow SS\Rightarrow aSbS\Rightarrow abS\Rightarrow abaSb\Rightarrow abab$ (ekrandan, 00:40:00). $a$ yerine "(", $b$ yerine ")" konunca dil doğru kapanmış parantez dizilerini anlatır. Hoca bunu, bir C programındaki bütün karakterler atılıp yalnız parantezler bırakıldığında elde edilen dizinin bu dile uyması gerektiği örneğiyle açıkladı. <!-- BELİRSİZ: Gramerin üretim satırı karede görünmüyor; türetimlerden S → aSb | SS | ε olduğu anlaşılıyor (python ile bu gramerin 6 uzunluğa kadar tam olarak dengeli dizgileri ürettiği doğrulandı). -->
- **En soldan / en sağdan türetim.** Üretimler: 1. $S\to AB$, 2. $A\to aaA$, 3. $A\to\varepsilon$, 4. $B\to Bb$, 5. $B\to\varepsilon$ (ekrandan, 00:45:00).
  - En soldan: $S\overset{1}{\Rightarrow}AB\overset{2}{\Rightarrow}aaAB\overset{3}{\Rightarrow}aaB\overset{4}{\Rightarrow}aaBb\overset{5}{\Rightarrow}aab$.
  - En sağdan: $S\overset{1}{\Rightarrow}AB\overset{4}{\Rightarrow}ABb\overset{5}{\Rightarrow}Ab\overset{2}{\Rightarrow}aaAb\overset{3}{\Rightarrow}aab$.
  - İkisi aynı türetim ağacını verir: kök $S$; çocukları $A$ ve $B$; $A$'nın çocukları $a, a, A$ ve alttaki $A\to\varepsilon$; $B$'nin çocukları $B, b$ ve alttaki $B\to\varepsilon$. Yapraklar soldan sağa $aa\varepsilon\varepsilon b = aab$ (yield) (ekrandan, 00:50:00 ve 00:55:00).
- **Belirsizlik.** $a+a*a$ için en soldan türetim: $E\Rightarrow E+E\Rightarrow a+E\Rightarrow a+E*E\Rightarrow a+a*E\Rightarrow a+a*a$ (ekrandan, 01:15:00). İkinci en soldan türetim $E\Rightarrow E*E\Rightarrow E+E*E\Rightarrow a+E*E\Rightarrow a+a*E\Rightarrow a+a*a$ derste bir öğrencinin sorusu üzerine tablette yazıldı. Birinci ağacın kökünde $+$, ikincisinin kökünde $*$ vardır. $a=2$ alınırsa birinci ağaç $2+(2\cdot2)=6$, ikincisi $(2+2)\cdot 2=8$ verir. Doğru sonuç 6'dır, çünkü çarpmanın önceliği vardır; belirsiz gramerde öncelik bilgisi yoktur.
- **Dangling else.** $IF\_STMT\to if\ EXPR\ then\ STMT$ ve $IF\_STMT\to if\ EXPR\ then\ STMT\ else\ STMT$ (ekrandan, 01:30:00) üretimleriyle "if E1 then if E2 then S1 else S2" dizgisi iki yoldan türetilir: $else$ ya içteki ya da dıştaki $if$'e bağlanır (ekrandan, 01:35:00). Hoca, programlama dillerinde bloğu kapatan "end" ya da süslü parantez gibi işaretlerin bu belirsizliği kaldırdığını söyledi.
- **Belirsizliği kaldırma.** $E\to E+T\mid T$, $T\to T*F\mid F$, $F\to(E)\mid a$ gramerinde her işlem farklı bir değişken düzeyinde tanımlanır; böylece $a+a*a$'nın tek bir ağacı olur. İki gramer eşdeğerdir, yani aynı dili üretir (ekrandan, 01:40:00).
- **Doğası gereği belirsiz dil.** $L=\{a^nb^nc^m\}\cup\{a^nb^mc^m\}$, $n,m\ge0$ için tablette yazılan gramer: $S\to AC\mid DB$, $A\to aAb\mid\varepsilon$, $C\to cC\mid\varepsilon$, $D\to aD\mid\varepsilon$, $B\to bBc\mid\varepsilon$ (ekrandan, 01:45:00; python ile 6 uzunluğa kadar doğrulandı). $abc$ hem $AC$ hem $DB$ yoluyla türetilir. Slayta göre bu dili üreten her gramer belirsizdir.
- **Otomattan gramer.** NFA $M_1$: başlangıç $S$; $S\xrightarrow{a}B$, $B\xrightarrow{a}B$, $B\xrightarrow{b}C$, $C\xrightarrow{a}C$, $C\xrightarrow{c}S$; kabul durumu $B$. Grameri: $S\to aB$, $B\to aB\mid bC\mid\varepsilon$, $C\to aC\mid cS$ (ekrandan, 01:55:00). $M_2$: başlangıç ve kabul durumu $S$; $S\xrightarrow{a}S$, $S\xrightarrow{b}A$, $A\xrightarrow{a}A$, $A\xrightarrow{b}S$. Grameri: $S\to aS\mid\varepsilon\mid bA$, $A\to aA\mid bS$. $L(M_1)L(M_2)$ için: $S\to S_1S_2$, $S_1\to aB_1$, $B_1\to aB_1\mid bC_1\mid\varepsilon$, $C_1\to aC_1\mid cS_1$, $S_2\to aS_2\mid\varepsilon\mid bA$, $A\to aA\mid bS_2$. $C_1\to cS_1$ kuralında $S$'nin $S_1$ olarak yenilenmesi gerektiğine dikkat edilmelidir. (Bütün gramerler python ile otomatlara karşı denetlendi.)
- **DFA'nın grameri ve düzenli ifadesi.** $\{0,1\}$ üzerinde DFA: başlangıç $A$; $A\xrightarrow{0}A$, $A\xrightarrow{1}B$, $B\xrightarrow{0}B$, $B\xrightarrow{1}C$, $C\xrightarrow{0}C$, $C\xrightarrow{1}A$; kabul durumları $A$ ve $C$ (ekrandan, 02:20:00). Tablette yazılan gramer: $A\to0A\mid1B$, $B\to0B\mid1C$, $C\to0C\mid1A$. Örnekler: $0\in L(M)$, $00\in L(M)$, $1\notin L(M)$, $11\in L(M)$.
  - Ders sonrası not: Kabul durumları $A$ ve $C$ olduğu için gramere $A\to\varepsilon$ ve $C\to\varepsilon$ de eklenmelidir; yoksa gramer hiçbir dizgi üretmez.
  - Ders sonrası not: Ekranda $001\in L(M)$ yazıyor; $001$ dizgisi $B$ durumunda biter, bu yüzden $001\notin L(M)$ (python ile denetlendi).
  - Ders sonrası not: Dil, 1 sayısı 3'e bölündüğünde kalanı 0 ya da 2 olan dizgilerdir. Ekrandaki düzenli ifade örneğin $1111$ dizgisini de (dört tane 1) kabul ediyor. Doğru bir ifade $0^*(10^*10^*10^*)^*(\varepsilon+10^*10^*)$ olur (python ile 9 uzunluğa kadar doğrulandı).
- **Bağlamdan bağımsız mı?** Hoca, kaba bir sezgi olarak dildeki sayı ilişkilerini ("bağlam") saydı: tek bir sınırsız ilişki varsa dil CFL'dir, birbirine bağlı birden çok sınırsız ilişki varsa değildir (ekrandan, 02:25:00 ve 02:30:00).
  - $\{a^nb^ma^n : n,m\ge0\}$ CFL; $\{a^nb^na^n : n\ge0\}$ CFL değil.
  - $\{a^nb^mc^k : k=\max(m,n)\}$ CFL değil (hoca bir öğrencinin itirazı üzerine bu sonuca vardı; o anki karede bu dilin yanında "CFL" yazıyor); $\{a^nb^mc^k : n>k,\ m>k\}$ CFL değil.
  - $\{a^mb^nc^k : m,n\ge0,\ k=\min(m,5)\}$ hem düzenli hem CFL. $\{a^mb^mc^k : k=\min(m,5)\}$ CFL'dir ama düzenli değildir: $c$ sayısı en çok 5 olduğundan $a$ ile $c$ arasındaki ilişki sonlu sayıda durumla sınırlıdır.
  - Sonlu bir dil ($\varepsilon, abc, \dots, aaaaabbbbbccccc$ gibi 6 elemanlı) hem düzenli hem CFL'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
