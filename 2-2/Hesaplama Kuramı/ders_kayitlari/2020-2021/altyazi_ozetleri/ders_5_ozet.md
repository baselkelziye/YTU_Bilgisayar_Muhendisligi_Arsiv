# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin tarihi 6 Nisan 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl anlatım yaklaşık 00:03:00'te başlar. Kayıtta iki ara var (yaklaşık 01:01-01:17 ve 02:04-02:14).
- NFA'dan DFA'ya dönüşüm örneğinin tamamlanması (alt küme yapısı, subset construction)
  - Geçen haftaki örnekte $q_1$'in kabul durumu olduğu düzeltildi.
  - Tuzak durum (dead state) $\emptyset$, kabul durumlarının belirlenmesi.
- Dönüşümün genel yöntemi
- Düzenli olmayan diller (non-regular / irregular languages): $a^n b^n$, $w w^R$
- Güvercin yuvası ilkesi (pigeonhole principle) ve sonlu otomatta tekrar eden durum
- Pompalama önsavı (pumping lemma) ve üç koşulu
- Pompalama önsavıyla bir dilin düzenli olmadığını ispatlama yöntemi (çelişkiyle ispat)
- Üç ispat örneği: $a^n b^n$, $a^n b^l c^{n+l}$, $a^{n!}$
- Düzenlilik ve düzensizlik ispatlarının özeti
- Çalışma kâğıdı ve kitap çalışma duyurusu

## Hocanın Özellikle Vurguladığı Kısımlar

- Dönüşümde yeni DFA durumu oluştukça her durum için her sembolü sorun.
  - "Bu durum $a$ alınca nereye gider, $b$ alınca nereye gider?" sorusu, yeni durum çıkmayana kadar tekrarlanır.
- DFA'da her sembolün bir geçişi olmalıdır.
  - NFA'da geçiş yoksa DFA'da $\emptyset$ adlı reddeden bir tuzak durum açılır. Bu durumdan çıkış yoktur.
- Kabul durumlarını yazmayı unutmayın.
  - NFA'nın bir kabul durumunu içeren her DFA durumu kabul durumudur.
- Pompalama önsavı yalnızca bir dilin düzenli olmadığını göstermek için kullanılır.
  - Sonlu dil her zaman düzenlidir. Bu yüzden düzenli olmayan her dil sonsuzdur.
- İspat her zaman çelişkiyle yapılır.
  - Önce dilin düzenli olduğu varsayılır, sonra pompalama önsavından bir çelişki çıkarılır.
- Seçilen dizgi deseni $m$'yi içermeli ve uzunluğu en az $m$ olmalı.
- $|xy| \le m$ koşulu çok işe yarar.
  - $x$ ve $y$ dizginin başındadır. Bu koşul olası bölmeleri azaltır.
- Bir dil için sonlu otomat tasarlayamamanız, o dilin düzenli olmadığını göstermez.
  - Düzensizlik pompalama önsavıyla ispatlanır.
- Çalışma kâğıdı (study sheet) çok faydalı. Soru 13-17 NFA'larla ilgili; artık bunları yapabilirsiniz.

## Kısa Tekrar Notları

- Alt küme yapısı: DFA durumları, NFA durumlarının alt kümeleridir. En fazla $2^{|Q|}$ durum olur.
  - Başlangıç durumu: $\{q_0\}$ ve ondan $\varepsilon$ ile ulaşılan durumlar.
  - Geçiş: kümedeki her durumun o sembolle gittiği durumların birleşimi, ardından $\varepsilon$ ile ulaşılanlar.
  - Kabul: NFA kabul durumu içeren her küme.
- Güvercin yuvası ilkesi: $n$ güvercin, $m$ yuva ve $n > m$ ise en az bir yuvada birden çok güvercin vardır.
- $m$ durumlu otomatta uzunluğu en az $m$ olan dizginin yürüyüşünde (walk) $m+1$ durum vardır. Bu yüzden en az bir durum tekrar eder ve bir döngü oluşur.
- Pompalama önsavı: $L$ düzenli ise bir $m$ (kritik uzunluk, critical length; Sipser'da pompalama uzunluğu $p$) vardır. $|w| \ge m$ olan her $w \in L$ için $w = xyz$ yazılabilir ve:
  1. her $i \ge 0$ için $xy^iz \in L$,
  2. $|y| \ge 1$,
  3. $|xy| \le m$.
- $i = 0$ "aşağı pompalama" (pump down), $i \ge 2$ "yukarı pompalama" (pump up).
- İspat adımları:
  1. $L$'nin düzenli olduğunu varsay. $L$ sonsuz olduğundan pompalama önsavı geçerli olmalı.
  2. $m$ kritik uzunluk olsun.
  3. $w \in L$, $|w| \ge m$ olan ve $m$ içeren bir desen seç.
  4. $|xy| \le m$, $|y| \ge 1$ koşulunu sağlayan **her** bölme için bir $i$ bul ki $xy^iz \notin L$ olsun.
  5. Çelişki: $L$ düzenli değildir.
- Düzenlilik ispatı: dili kabul eden bir DFA/NFA veya onu tanımlayan bir düzenli ifade ver.
- Düzenli diller kesişim altında kapalıdır (closure). Kapanma özellikleri de ispatlarda kullanılabilir.

## Detaylı Açıklamalar

### NFA'dan DFA'ya dönüşüm örneğinin tamamlanması

NFA (ders 4'teki örnek): $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{a} q_1$, $q_1 \xrightarrow{\varepsilon} q_2$, $q_2 \xrightarrow{b} q_0$. Başlangıç $q_0$. Bu derste $q_1$'in kabul durumu olduğu söylendi; notlarınıza ekleyin.

| DFA durumu | $a$ | $b$ | Kabul? |
| :---: | :---: | :---: | :---: |
| $\{q_0\}$ (başlangıç) | $\{q_1, q_2\}$ | $\emptyset$ | Hayır |
| $\{q_1, q_2\}$ | $\{q_1, q_2\}$ | $\{q_0\}$ | Evet ($q_1$ içeriyor) |
| $\emptyset$ (tuzak) | $\emptyset$ | $\emptyset$ | Hayır |

- $q_0$ $a$ alınca $q_1$'e gider. $q_1$'den $\varepsilon$ ile hemen $q_2$'ye de geçilir. Bu yüzden hedef $\{q_1, q_2\}$'dir.
- $\{q_1, q_2\}$ $a$ alınca: $q_1 \to q_1$, $q_2$'nin $a$ geçişi yok. $\varepsilon$ ile yine $q_2$ eklenir. Sonuç kendisi, yani bir döngü.
- $\{q_1, q_2\}$ $b$ alınca: $q_1$'in $b$ geçişi yok, $q_2 \to q_0$. Sonuç $\{q_0\}$.
- Dizgi $b$ ile başlarsa tuzak duruma düşülür ve hiçbir zaman çıkılmaz.
- Bu DFA'nın dili $a(a \cup ba)^*$'dır. Bu sonuç 12 sembole kadar bütün dizgilerde Python ile denendi.

### Dönüşümün genel yöntemi

- NFA durumları $q_0, q_1, \dots$ ise DFA durumları $\emptyset, \{q_0\}, \{q_1\}, \{q_0, q_1\}, \dots$ olabilir. Bu, kuvvet kümesidir.
- Her DFA durumu $\{q_i, q_j, \dots, q_m\}$ ve her sembol $\sigma$ için: her $q$'nun $\sigma$ ile gittiği durumları bul ve birleşimini al. Bu birleşim yeni (ya da var olan) DFA durumudur.
- Yeni durum eklenmeyene kadar devam edilir.
- Son olarak NFA'nın kabul durumu $q_f$'yi içeren bütün DFA durumları kabul durumu yapılır.

### Düzenli olmayan diller

- Bir NFA ya da DFA ile kabul edilebilen diller düzenli dillerdir.
- $\{a^n b^n \mid n \ge 0\}$ ve $\{w w^R \mid w \in \{a, b\}^*\}$ düzenli değildir. Bunu ispatlamak için pompalama önsavı kullanılır.

### Pompalama önsavına giriş: tekrar eden durum

Tahtadaki DFA (kareden): $q_1 \xrightarrow{a} q_2$, $q_2 \xrightarrow{b} q_2$, $q_2 \xrightarrow{a} q_3$, $q_3 \xrightarrow{a} q_2$, $q_3 \xrightarrow{b} q_4$, $q_4 \xrightarrow{b} q_4$, $q_4 \xrightarrow{a} q_3$. Başlangıç $q_1$, kabul $q_4$. 4 durum var.

- $w = aabb$ (4 sembol): yürüyüş $q_1, q_2, q_3, q_4, q_4$. 5 durum ziyaret edilir, $q_4$ tekrar eder.
- $w = aaaab$ (5 sembol): yürüyüş $q_1, q_2, q_3, q_2, q_3, q_4$. $q_2$ ve $q_3$ tekrar eder. Python ile doğrulandı.
- Güvercinler yürüyüşteki durumlar, yuvalar makinenin durumlarıdır. Uzunluğu en az $m$ olan dizgide $m+1$ güvercin, $m$ yuva vardır.

### Dizgiyi $xyz$ olarak bölme

- $x$: döngüden önceki kısım. $y$: döngü. $z$: döngüden sonraki kısım.
- $aaaab$ örneğinde $x = a$ ($q_1 \to q_2$), $y = aa$ ($q_2 \to q_3 \to q_2$), $z = ab$.
- Döngü istenildiği kadar tekrarlanabilir ya da hiç kullanılmayabilir. Makine yine kabul eder.
  - $xyyz$: $x$ döngünün başına getirir, her $y$ yine döngünün başına döner, $z$ kabul durumuna götürür.
  - $xz$ ($i = 0$): döngüye hiç girilmez.
- $|xy| \le m$: döngünün başladığı durum dışında hiçbir durum iki kez kullanılmaz. Bu yüzden $x$ ve $y$ birlikte en fazla $m$ uzunluktadır.
- $|y| \ge 1$: bir döngüde en az bir geçiş vardır.

### Örnek 1: $L = \{a^n b^n \mid n \ge 0\}$ düzenli değildir

1. $L$'nin düzenli olduğunu varsayalım. $L$ sonsuzdur, pompalama önsavı geçerli olmalı.
2. $m$ kritik uzunluk olsun.
3. $w = a^m b^m$ seçilir. $|w| = 2m \ge m$.
4. $|xy| \le m$ olduğu için $x$ ve $y$ yalnızca $a$'lardan oluşur. $y = a^k$, $1 \le k \le m$.
5. $i = 2$ için $xy^2z = a^{m+k} b^m$ olur.
6. $k \ge 1$ olduğu için $a$ sayısı $b$ sayısından fazladır. Bu dizgi $L$'de değildir. Çelişki.
7. Sonuç: $L$ düzenli değildir.

Derste bir öğrenci $i$ ile $k$'nin farkını sordu. Hoca Türkçe açıkladı:
- $i$, $y$'nin kaç kez tekrarlandığıdır.
- $k$, $y$'nin içindeki $a$ sayısıdır.
- Genel olarak $xy^iz = a^{m + (i-1)k} b^m$ olur.

### Örnek 2: $L = \{a^n b^l c^{n+l} \mid n, l \ge 0\}$ düzenli değildir

- Örnek dizgiler: $\varepsilon$, $ac$, $abcc$, ...
- Desen: $w = a^m b^m c^{2m}$, $|w| = 4m \ge m$.
- $|xy| \le m$ olduğu için $y = a^k$, $1 \le k \le m$.
- Bu sefer aşağı pompalama: $i = 0$ için $xz = a^{m-k} b^m c^{2m}$.
- $(m - k) + m \ne 2m$ olduğu için dizgi $L$'de değildir. Çelişki.

### Örnek 3: $L = \{a^{n!} \mid n \ge 0\}$ düzenli değildir

- Desen: $w = a^{m!}$, $|w| = m! \ge m$.
- Bütün dizgi $a$'lardan oluşur. $y = a^k$, $1 \le k \le m$.
- $i = 2$ için $xy^2z = a^{m! + k}$. Bu dizgi $L$'de ise bir $n$ için $m! + k = n!$ olmalı.
- Eşitsizlik zinciri ($m \ge 2$ için):

$$m! < m! + k \le m! + m < m! + m \cdot m! = (m+1)!$$

- $m! + k$, ardışık iki faktöriyel ($m!$ ve $(m+1)!$) arasında kalır. Bu yüzden hiçbir sayının faktöriyeli değildir. Çelişki.
- Bu aralık 2 ile 11 arasındaki bütün $m$ değerleri ve $1 \le k \le m$ için Python ile denendi.

### Özet: düzenlilik nasıl ispatlanır?

- $L$ sonlu ise düzenlidir.
- $L$ sonsuz ise düzenli de olabilir, olmayabilir de.
  - Düzenli olduğunu göstermek için $L$'yi kabul eden bir sonlu otomat (ya da düzenli ifade) verilir.
  - Düzenli olmadığını göstermek için pompalama önsavı kullanılır.
  - Küme kapanma özellikleri (ör. düzenli diller kesişim altında kapalıdır) her iki yönde de kullanılabilir.

### Duyurular ve çalışma

- Çalışma kâğıdı 1: Soru 1-12 DFA, soru 13-17 NFA konusunda. Artık hepsi yapılabilir.
- Sipser'da Bölüm 1 bitti. Bölüm 1 sonundaki alıştırma ve problemleri çalışın.
- Derste atlanan düzenli ifadeler (regular expressions) kısmını (kitapta s. 63-66) kendiniz okuyun. Hoca bu konuya ders 7'de geri döndü.

### Ders sonrası notlar

- Hoca pompalama önsavını "sonsuz düzenli dil" için yazdı. Sipser'daki biçim bütün düzenli diller için geçerlidir. Sonlu dilde $m$, en uzun dizgiden büyük seçilir; koşul boş yere sağlanır.
- Hoca desenin uzunluğu için birkaç kez "$m$'den büyük" dedi. Doğru koşul $|w| \ge m$'dir.
- $aaaab$ örneğinde hoca $|xy|$'yi "iki" diye saydı. Doğrusu $x = a$, $y = aa$ olduğu için $|xy| = 3 \le 4$. Hoca durumları saymış.
- Örnek 1'de hoca "$k$ birden büyükse" dedi ve $i$ ile $k$'yi karıştırdı. Doğrusu: her $1 \le k \le m$ için $a^{m+k}b^m \notin L$. $k = 1$ de çelişki verir.
- Örnek 2'de "$|y| > m$" diye bir sürçme geçiyor. Doğru koşul $|y| \ge 1$'dir. Ayrıca "non-linear" değil, non-regular denmek istendi. $n = l = 1$ için dizgi $abcc$'dir.
- Örnek 3'te hoca yalnızca $m! + k < (m+1)!$ tarafını gösterdi. İspat için $m! + k > m!$ olduğu da söylenmeli. İkisi birlikte $m! + k$'nin hiçbir faktöriyele eşit olmadığını gösterir. Hoca sonuçta "$a^{m+k}$" dedi; doğrusu $a^{m!+k}$.
- Pompalama önsavında çelişki için bütün olası bölmeler ele alınmalı. Bu örneklerde $|xy| \le m$ koşulu bütün bölmeleri "$y$ yalnız $a$'lardan oluşur" durumuna indirdiği için tek durum incelemek yeterli oldu.
- Özette hoca "otomat tasarlayamazsanız bu, dilin düzenli olduğunu göstermez" dedi. Kastedilen: dilin düzenli **olmadığını** göstermez.
- Alt küme yapısında başlangıç durumu $q_0$'ın $\varepsilon$-kapanışıdır. Bu örnekte $q_0$'dan $\varepsilon$ geçişi olmadığı için küme $\{q_0\}$'dır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Ders İngilizce anlatılmıştır; altyazı da büyük ölçüde İngilizcedir.
