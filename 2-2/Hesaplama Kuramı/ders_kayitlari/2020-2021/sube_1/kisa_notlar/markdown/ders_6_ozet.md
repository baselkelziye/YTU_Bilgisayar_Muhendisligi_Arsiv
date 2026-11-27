# Ders 6 Çalışma Özeti

## Genel Konular

- Ders ağırlıkla İngilizce anlatıldı, bazı açıklamalar Türkçe tekrar edildi. Anlatım tablette slayt ve el yazısıyla yürüdü.
  - Kayıt üç bölümden oluşur: yaklaşık 00:03:30-00:50:20, 01:02:00-02:03:15 ve 02:15:35-02:57:25. Aralarda ders arası verildi.
- Geçen dersten bağlantı: DFA/NFA'daki döngüler ve güvercin yuvası ilkesi
  - Bir NFA ya da DFA'da döngü varsa makinenin tanıdığı dil sonsuzdur.
- Sonlu diller her zaman düzenlidir
  - Örnek: $\Sigma=\{a,b,c,d\}$ üzerinde $L=\{a, ab, abc, d\}$ için NFA kurulur, ölü durum (dead state) eklenerek DFA'ya tamamlanır (ekrandan, 00:15:00).
  - Sonlu bir dilin düzenli olduğunu göstermek için pompalama önsavına gerek yoktur.
- Pompalama önsavının (pumping lemma) arkasındaki fikir
  - Sonsuz düzenli bir dilin DFA'sında $m$ durum varsa, uzunluğu $m$'den büyük bir dizgi okunurken güvercin yuvası ilkesi gereği en az bir durum tekrar eder (ekrandan, 00:05:00).
  - İlk tekrar eden durum $q$ alınır; dizgi $w=xyz$ diye üçe bölünür: $x$ başlangıçtan $q$'ya, $y$ $q$'dan yine $q$'ya (döngü), $z$ $q$'dan kabul durumuna (ekrandan, 00:25:00).
  - Döngü hiç dönülmeden ($xz$), iki kez ($xy^2z$, ekrandan, 00:35:00) ya da istendiği kadar dönülerek de kabul durumuna varılır.
- Pompalama önsavının ifadesi
  - $L$ sonsuz düzenli dil, $m$ kritik uzunluk olsun. $|w|\ge m$ olan her $w\in L$ için $w=xyz$, $|xy|\le m$, $|y|\ge 1$ olacak şekilde yazılabilir ve her $i\ge 0$ için $xy^iz\in L$ olur.
- Dilin düzenli olmadığını ispatlama yöntemi (çelişki ile)
  - Dilin düzenli olduğu varsayılır, önsavdan çelişki elde edilir, dilin düzenli olmadığı sonucuna varılır (ekrandan, 00:40:00).
  - Klasik örnek: $L=\{a^nb^n : n\ge 0\}$ için $w=a^mb^m$ seçilir; $y=a^k$ olur ve $xy^2z=a^{m+k}b^m\notin L$ (ekrandan, 00:45:00).
- Tablette çözülen örnekler
  - $L=\{a^mb^n : m,n\ge 0\}$: yanlış ve doğru bölme karşılaştırması (ekrandan, 01:10:00 ve 01:20:00).
  - İlk, orta ve son sembolü aynı olan dizgiler (ekrandan, 01:25:00 ve 01:30:00).
  - $L=\{vv^R : v\in\{a,b\}^*\}$ (ekrandan, 01:35:00 ve 01:45:00).
  - $L=\{a^kb^l : k>l\ge 0\}$ (ekrandan, 01:50:00).
  - $L=\{a^nb^lc^{n+l}\}$ (ekrandan, 02:20:00).
  - $L=\{a^nb^{n \bmod m}\}$, $m=2$ için (ekrandan, 02:25:00 ve 02:30:00).
- Hızlı düzenlilik değerlendirmesi örnekleri
  - $a^nb^nc^n$ düzenli değil; $a^nb^m$ düzenli; $a^nb^ma^n$ düzenli değil (ekrandan, 02:35:00).
  - $b^{m!}$ düzenli değil; $b^{m! \bmod 3}$ düzenli (ekrandan, 02:45:00 ve 02:50:00).
  - $(ab)^n$ düzenli, $a^nb^n$ düzenli değil (ekrandan, 02:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Pompalama önsavı bir dilin düzenli **olmadığını** ispatlamak için kullanılır, düzenli olduğunu ispatlamak için değil.
  - Önsav yalnız sonsuz dillere uygulanır. Sonlu dil zaten düzenlidir.
- Çelişki için tek bir uygun $i$ değeri yeterlidir.
  - Seçilen $w$ mutlaka dilin elemanı olmalıdır.
- İspata başlamadan önce dili iyi anlayın.
  - Dile ait olan ve olmayan küçük dizgileri yazarak deseni (pattern) bulun.
- Sınavda sık yapılan hata: $y$'yi iki farklı sayma desenini karıştıracak şekilde seçmek.
  - $a^mb^n$ dilinde $y=ab$ seçilirse $xy^2z$ dilin dışında kalır, ama bu dilin düzenli olmadığını göstermez; $a^mb^n$ düzenlidir (NFA'sı vardır).
  - $y$ ya yalnız $a$'ların sayıldığı bölgeden ya da yalnız $b$'lerin sayıldığı bölgeden seçilmelidir.
- Somut, küçük sayılarla çalışmak kritik uzunluğu ve bölmeyi görmeyi kolaylaştırır.

## Kısa Tekrar Notları

- Sonlu dil $\Rightarrow$ düzenli.
- Sonsuz düzenli dilin DFA'sında döngü vardır; uzun dizgi döngüyü en az bir kez kullanır.
- Önsav koşulları: $|w|\ge m$, $w=xyz$, $|xy|\le m$, $|y|\ge 1$, her $i\ge 0$ için $xy^iz\in L$.
- $xy^0z=xz$ de dilde olmalıdır.
- İspat adımları: düzenli varsay, $m$ al, $w\in L$ ve $|w|\ge m$ seç, $w=xyz$ yaz, bir $i$ için $xy^iz\notin L$ göster, çelişki.
- Sayılar arasında zorunlu bir ilişki varsa ($a^nb^n$, $a^nb^nc^n$, $a^nb^ma^n$, $a^nb^lc^{n+l}$, $vv^R$) dil genelde düzenli değildir.
- Sayılar bağımsızsa ya da yalnız sonlu bir kalanla ilgiliyse ($a^nb^m$, $a^nb^{n \bmod 2}$) dil düzenlidir.
- $b^{m!}$: art arda kabul edilen uzunluklar arasındaki fark sürekli büyür, sonlu durumla tanınamaz.
- $b^{m! \bmod 3}=\{\varepsilon, b, bb\}$: sonlu, dolayısıyla düzenli.

## Detaylı Açıklamalar

**Sonlu diller.** $L=\{a, ab, abc, d\}$ dilinin NFA'sı ekranda şöyledir (ekrandan, 00:15:00): $q_0$ başlangıç durumu; $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{b} q_2$, $q_2 \xrightarrow{c} q_3$, $q_0 \xrightarrow{d} q_3$; $q_1, q_2, q_3$ kabul durumlarıdır. DFA'ya geçmek için her durumdan alfabedeki dört sembolün her biri için birer geçiş olmalıdır. Eksik geçişler ölü durum $D$'ye yönlendirilir: $q_0$'dan $b,c$; $q_1$'den $a,c,d$; $q_2$'den $a,b,d$; $q_3$'ten $a,b,c,d$; $D$'den de $a,b,c,d$ yine $D$'ye. Sonlu her dil için böyle bir makine kurulabildiğinden sonlu diller düzenlidir.

**Önsavın sezgisi.** Sonsuz düzenli bir dili tanıyan DFA'nın $m$ durumu olsun. Uzunluğu $k>m$ olan bir dizgi okunurken $k+1$ durum ziyaret edilir; güvercinler dizginin sembolleri, yuvalar durumlardır. Bu yüzden bir durum en az iki kez görülür. İlk tekrar eden durum $q$ seçilir. Başlangıçtan $q$'nun ilk görülmesine kadar okunan kısım $x$, $q$'dan $q$'ya dönen kısım $y$, $q$'dan kabul durumuna giden kısım $z$'dir. Tekrar eden ilk durum seçildiği için $|xy|\le m$ olur; döngü en az bir sembol içerdiği için $|y|\ge 1$ olur. Döngü sıfır, bir, iki ya da daha çok kez dönülebildiğinden $xz$, $xyz$, $xy^2z$, ... hepsi kabul edilir.

**Önsavın kullanımı.** İspat çelişki ile yapılır. Dil düzenli varsayılır, $m$ kritik uzunluk alınır, $|w|\ge m$ olan bir $w\in L$ seçilir, $w=xyz$ yazılır ve bir $i\ne 1$ için $xy^iz\notin L$ gösterilir. $L=\{a^nb^n\}$ için $w=a^mb^m$ seçilince $|xy|\le m$ koşulu $y$'nin yalnız $a$'lardan oluştuğunu söyler: $y=a^k$, $k\ge 1$. $i=2$ için $a^{m+k}b^m$ elde edilir; $a$ ve $b$ sayıları eşit olmadığından dilde değildir.

**Tablette çözülen örneklerden öne çıkanlar.**

- $L=\{a^kb^l : k>l\ge 0\}$, $w=aaaaabb$ (ekrandan, 01:50:00): $y=a$ seçilirse bütün pompalamalar dilde kalır. $y$ $b$'lerden seçildiğinde ($x=aaaaa$, $y=b$, $z=b$) $xy^4z=a^5b^5$ elde edilir ve $k>l$ bozulur. Hoca bu yolla dilin düzenli olmadığı sonucuna varır.
- $L=\{a^nb^lc^{n+l} : n,l\ge 0\}$ (ekrandan, 02:20:00): $ac, bc, abcc, aabccc, abbccc, aaaccc\in L$; $abc, abccc, aaacccc\notin L$. $y$ yalnız $a$'lardan seçilince pompalama $a$ sayısını artırır ama $c$ sayısı aynı kalır, dil düzenli değildir. $y$'yi hem $b$ hem $c$ içerecek seçmek deseni bozar ve geçersiz bir akıl yürütmeye yol açar.
- $L=\{a^nb^{n \bmod 2}\}$ (ekrandan, 02:30:00): $L_{odd}=\{a^{2k+1}\}$, $L_{even}=\{a^{2k}\}$ olmak üzere $L=L_{odd}\cdot\{b\}\cup L_{even}$. Düzenli dillerin birleştirme ve birleşim altında kapalı olmasından $L$ düzenlidir. Hoca ayrıca $y$'nin uzunluğunun 2 seçilmesi gerektiğini, 1 seçilirse tek/çift düzeninin bozulacağını gösterir.
- $L=\{b^{m! \bmod 3} : m\ge 0\}$ (ekrandan, 02:50:00): $0!$ ve $1!$ için kalan 1, $2!$ için 2, $m\ge 3$ için 0'dır. Dil $\{\varepsilon, b, bb\}$ olur ve sonlu olduğu için düzenlidir. Hoca önce $\varepsilon$'u unutmuş, bir öğrencinin uyarısıyla düzeltmiştir.
- $L_1=\{(ab)^n\}$ ile $L_2=\{a^nb^n\}$ aynı değildir: $aabb\in L_2$, $aabb\notin L_1$; $abab\in L_1$, $abab\notin L_2$ (ekrandan, 02:55:00). $L_1$ için başlangıçtan $a$, sonra $b$ ile kabul durumuna giden ve $\varepsilon$ ile başa dönen bir NFA çizilir; $L_1$ düzenlidir. $L_2$ için böyle bir makine yoktur.

- **Ders sonrası not:** Pompalama önsavında $x,y,z$ bölmesini ispatı yapan kişi seçemez; önsav yalnız böyle bir bölmenin var olduğunu söyler. Bu yüzden düzenli olmadığını ispatlarken $|xy|\le m$ ve $|y|\ge 1$ koşulunu sağlayan **her** bölme için bir $i$ bulunmalıdır. Derste ise belirli bir bölme seçilip incelendi. Aynı nedenle, seçilen bir bölmede çelişki çıkmaması dilin düzenli olduğunu göstermez; düzenlilik bir NFA/DFA, düzenli ifade ya da kapanma özellikleriyle gösterilir.
- **Ders sonrası not:** Hoca 01:02:40 civarında düzenli dillerin "düzenli olmayan dillerin alt kümesi" olduğunu söyledi. Doğrusu: düzenli diller bütün dillerin bir alt kümesidir; düzenli olmayan diller bu kümenin dışında kalanlardır.
- **Ders sonrası not:** $L_1=\{(ab)^n : n\ge 0\}$ boş dizgiyi de içerir. Çizilen NFA'da başlangıç durumu kabul durumu değilse $\varepsilon$ kabul edilmez; başlangıç durumunun da kabul durumu yapılması gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
