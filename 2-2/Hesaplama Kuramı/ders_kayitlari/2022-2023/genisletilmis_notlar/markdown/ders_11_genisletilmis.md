# Ders 11 Genişletilmiş Notu: Bağlamdan Bağımsız Dillerin Kapalılık Özellikleri, Düzenli Gramerler ve Deterministik Yığıtlı Otomatlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağlamdan bağımsız diller için pompalama önsavının tekrarı
- 2. $\{vv\}$ dilinin bağlamdan bağımsız olmadığının ispatı
- 3. Bağlamdan bağımsız dillerin kapalı olduğu işlemler
- 4. Kesişim ve tümleme altında kapalı olmama
- 5. Düzenli dillerle karşılaştırma
- 6. Bağlamdan bağımsız dil ile düzenli dilin kesişimi
- 7. Kesişim özelliğinin uygulamaları
- 8. Doğrusal ve düzenli gramerler
- 9. Düzenli gramerler düzenli dilleri üretir
- 10. Her düzenli dil bir düzenli gramerle üretilir
- 11. Deterministik yığıtlı otomatlar (DPDA)
- Örnek Sorular
- Dersin Toparlaması

## 1. Bağlamdan bağımsız diller için pompalama önsavının tekrarı

Ders, önceki derste görülen bağlamdan bağımsız diller için pompalama önsavının (pumping lemma) kısa bir tekrarıyla başladı. Önsavın nereden geldiği önceki derste ayrıntılı anlatıldığı için tekrar edilmedi; bunun yerine bir örnek yeniden çözüldü. Slaytlar Costas Busch'un ders slaytlarıdır.

Önsavın ifadesi şöyledir (ekrandan, 00:10:00): sonsuz bir bağlamdan bağımsız dil $L$ için öyle bir tam sayı $m$ vardır ki $|w| \ge m$ olan her $w \in L$ dizgesi

$$w = uvxyz, \qquad |vxy| \le m, \qquad |vy| \ge 1$$

biçiminde beş parçaya bölünebilir ve her $i \ge 0$ için

$$uv^ixy^iz \in L$$

olur. $m$'ye kritik uzunluk (critical length) denir; kitapta ve slaytların ilk bölümlerinde $p$ olarak, bu slaytlarda $m$ olarak geçer, ikisi aynı şeydir. "Sonsuz dil" içinde sonsuz sayıda dizge bulunduran dil demektir. Önsavın söylediği şudur: ortadaki $vxy$ parçası en çok $m$ uzunluğundadır, $v$ ile $y$ birlikte en az bir sembol içerir ve $v$ ile $y$ istenildiği kadar çoğaltılabilir (pump up) ya da tamamen kaldırılabilir (pump down); elde edilen dizge yine dildedir.

Önsav bir dilin bağlamdan bağımsız **olmadığını** ispatlamak için kullanılır. Hocanın verdiği örnekler: $\{a^nb^nc^n\}$ (üç sembol aynı sayıda ve sırayla) ve $\{vv\}$ (ikinci yarısı ilk yarısının tekrarı olan dizgeler). İkisi de bağlamdan bağımsız değildir ve bu önsavla gösterilebilir.

## 2. $\{vv\}$ dilinin bağlamdan bağımsız olmadığının ispatı

Dil: $L = \{vv : v \in \{a,b\}^*\}$ (ekrandan, 00:15:00).

### 2.1 Varsayım ve dizge seçimi

İspat olmayana ergi (proof by contradiction) ile yapılır. Önce $L$'nin bağlamdan bağımsız olduğu varsayılır; bundan sonra bu varsayım doğruymuş gibi ilerlenir ve bir çelişkiye ulaşılınca varsayımın yanlış olduğu sonucuna varılır. $L$ sonsuz ve (varsayım gereği) bağlamdan bağımsız olduğu için önsav uygulanabilir; önsav bize bir "sihirli sayı" $m$ verir.

Şimdi dilde olan, $m$'den uzun ve pompalanamadığı gösterilebilecek bir dizge seçmek gerekir. Slaytta seçilen dizge (ekrandan, 00:15:00):

$$a^mb^ma^mb^m \in L$$

Bu dizgenin uzunluğu $4m$'dir ve $v = a^mb^m$ alındığında dildedir. Hoca, neden örneğin $a^ma^m = a^{2m}$ seçilmediğini sordu: bu dizge de dilde ve $m$'den uzun, ama birçok bölünmede pompalanabilir; dolayısıyla onunla çelişki gösterilemez. Önsav "her uygun dizge pompalanabilir" dediği için, işimize gelen, pompalanınca kalıbı bozulacak bir dizge seçmeliyiz.

> **Hocanın vurgusu:** Dizge seçimi keyfi değildir; pompalanamayacağını gösterebileceğimiz bir kalıp seçmeliyiz.

### 2.2 Durumların incelenmesi

Önsav $a^mb^ma^mb^m = uvxyz$ yazılabileceğini, $|vxy| \le m$ ve $|vy| \ge 1$ olduğunu söyler. Çelişkiyi göstermek için $vxy$'nin dizgede nerede olabileceği tek tek incelenir ve her durumda "olmadı" denir.

**Durum 1: $vxy$ ilk $a^m$ bloğunun içinde** (ekrandan, 00:20:00). Bu durumda $v = a^{k_1}$, $y = a^{k_2}$ ve $k_1 + k_2 \ge 1$ olur; $k_1$ ya da $k_2$ tek başına sıfır olabilir ama ikisi birden sıfır olamaz. Yukarı pompalanınca ($i = 2$) bir $v$ ve bir $y$ daha gelir, yani ilk bloğa $k_1 + k_2$ tane fazladan $a$ eklenir:

$$uv^2xy^2z = a^{m+k_1+k_2}b^ma^mb^m$$

Bu dizgede ilk yarı ile ikinci yarı aynı değildir (ilk blok, üçüncü bloktan daha fazla $a$ içerir), dolayısıyla dizge $L$'de değildir. Çelişki.

$vxy$ tamamen $b^m$ bloklarından birinin ya da ikinci $a^m$ bloğunun içindeyse durum Durum 1'e birebir benzer ve aynı biçimde çelişki çıkar.

**Durum 2: $v$ ilk $a$ ve $b$ bloklarının sınırında.** $v$ bir miktar $a$ ve bir miktar $b$ içerir: $v = a^{k_1}b^{k_2}$, $k_1 \ge 1$, $k_2 \ge 1$; $x$ ve $y$ $b$'lerin içindedir, $y = b^{k_3}$ boş olabilir (çünkü $|vy| \ge 1$ koşulunu zaten $v$ sağlıyor). Pompalanınca $v$ iki kere yazılır ve $a$ ile $b$ iç içe girer (ara adım eklendi):

$$uv^2xy^2z = a^m\, b^{k_2}a^{k_1}\, b^{m+k_3}a^mb^m$$

Bu dizge kendini tekrar eden iki eş yarıya bölünemez, yani $L$'de değildir. Çelişki.

**Öteki durumlar:** $y$'nin bir sınırda olması ya da $v$/$y$'nin öteki blok sınırlarında (b-a ya da a-b sınırları) bulunması incelenen bu iki duruma benzer.

**$vxy$ üç bloğa birden dokunabilir mi?** Hayır. $vxy$ üç bloğa dokunacaksa ortadaki bloğun tamamını ($m$ sembol) ve iki yanından en az birer sembol içermelidir; bu $|vxy| \le m$ koşuluyla çelişir.

> **Ders sonrası not:** Hoca bu durumu anlatırken "burası 3M ... VXY 3M boyutunda bir alanı kaplayamaz" dedi. Kastedilen, üç bloğa yayılmanın $m$'den uzun bir $vxy$ gerektirdiğidir; üç bloğa dokunmak için gereken uzunluk en az $m + 2$'dir.

### 2.3 Sonuç

Bütün olası durumlarda çelişki elde edildi (ekrandan, 00:25:00). Dolayısıyla $L = \{vv : v \in \{a,b\}^*\}$'nin bağlamdan bağımsız olduğu varsayımı yanlıştır: $L$ bağlamdan bağımsız değildir. Slaytta bir örnek daha vardı; hoca onu öğrencilerin kendi başına incelemesine bıraktı.

## 3. Bağlamdan bağımsız dillerin kapalı olduğu işlemler

Bu bölümden sonra ders İngilizce sürdü; bazı yerler Türkçe tekrar edildi. Yeni slayt dosyası bağlamdan bağımsız dillerin özellikleri (properties of context-free languages) üzerinedir.

Bir dil sınıfının bir işlem altında **kapalı** (closed) olması, o sınıftan dillere işlem uygulanınca elde edilen dilin de o sınıfta olması demektir.

### 3.1 Birleşim (union)

İki bağlamdan bağımsız dilin birleşimi bağlamdan bağımsızdır. Slayttaki örnekte $L_1 = \{a^nb^n\}$ dili başlangıç değişkeni $S_1$ olan bir gramerle, $L_2$ ise başlangıç değişkeni $S_2$ olan ikinci bir gramerle üretilir. <!-- BELİRSİZ: örnek gramerler ve L2 karede görülmedi -->

Birleşimi üreten gramer için yeni bir başlangıç değişkeni $S$ yazılır ve bu değişken $S_1$ ya da $S_2$ üretir. Genel hâli (ekrandan, 00:30:00): başlangıç değişkenleri $S_1, S_2$ olan $G_1, G_2$ gramerlerine sahip $L_1, L_2$ için $L_1 \cup L_2$'nin grameri yeni başlangıç değişkeni $S$ ve ek kural

$$S \to S_1 \mid S_2$$

ile elde edilir. Hoca, aradaki "$\mid$" işaretinin birleşimin "veya" olmasına karşılık geldiğini belirtti.

### 3.2 Birleştirme (concatenation)

$L_1L_2$ için yine yeni bir başlangıç değişkeni $S$ eklenir ve

$$S \to S_1S_2$$

kuralı yazılır. Birleşimden farkı, iki değişkenin arasına "veya" yerine doğrudan yan yana yazılmasıdır.

### 3.3 Yıldız işlemi (star operation)

$L$ bağlamdan bağımsızsa $L^*$ da bağlamdan bağımsızdır. Yine yeni bir başlangıç değişkeni eklenir; yeni değişken ile özgün başlangıç değişkeni arka arkaya (birleştirme ile) yazılır ve sonlandırmak için $\lambda$ eklenir. Böylece yeni değişken istenildiği kadar açılarak istenen sayıda $S_1$ üretilir, sonunda $\lambda$ ile kurtulunur ve geri kalan gramer her $S_1$'den $L$'nin bir dizgesini üretir. <!-- BELİRSİZ: kuralın tam yazımı karede görülmedi; Busch slaytlarında büyük olasılıkla $S \to SS_1 \mid \lambda$ -->

## 4. Kesişim ve tümleme altında kapalı olmama

### 4.1 Kesişim (intersection)

Bağlamdan bağımsız diller kesişim altında kapalı **değildir** (ekrandan, 00:35:00). Hoca bu ifadenin anlamını özellikle açıkladı: $L_1$ ve $L_2$ bağlamdan bağımsızsa $L_1 \cap L_2$ bağlamdan bağımsız olabilir de olmayabilir de; "kapalı değil" demek kesişimin kesinlikle bağlamdan bağımsız olmadığı anlamına gelmez, yalnız bağlamdan bağımsız olmasının garanti olmadığı anlamına gelir.

> **Hocanın vurgusu:** "Kapalı değil", "hiçbir zaman değil" demek değildir; "zorunlu olarak değil" demektir.

Örnek (ekrandan, 00:40:00):

- $L_1 = \{a^nb^nc^m\}$: $a$ ve $b$ sayısı eşit, $c$ sayısı farklı olabilir. Grameri: $S \to AC$, $A \to aAb \mid \lambda$, $C \to cC \mid \lambda$.
- $L_2 = \{a^nb^mc^m\}$: $b$ ve $c$ sayısı eşit, $a$ sayısı farklı olabilir. Grameri: $S \to AB$, $A \to aA \mid \lambda$, $B \to bBc \mid \lambda$.

İkisi de bağlamdan bağımsızdır. Kesişimleri ise üç sembolün de aynı sayıda olduğu dildir:

$$L_1 \cap L_2 = \{a^nb^nc^n\}$$

Bu dil bağlamdan bağımsız değildir. Dolayısıyla kesişim bağlamdan bağımsız dillerin dışına çıkabilir.

### 4.2 Tümleme (complement)

Tümleme, dilde olmayan dizgelerin kümesini almaktır. Bağlamdan bağımsız diller tümleme altında da kapalı değildir: bir bağlamdan bağımsız dilin tümleyeni bağlamdan bağımsız olabilir ama olmak zorunda değildir.

İspat yine olmayana ergiyle ve aynı örnek dillerle yapılır (ekrandan, 00:40:00). Hoca slaytı önce Türkçe yorumladı, sonra İngilizce tekrar etti:

1. Tümlemenin bağlamdan bağımsız dillerde kapalı olduğunu varsayalım.
2. $L_1$ bağlamdan bağımsız olduğu için $\overline{L_1}$ de bağlamdan bağımsızdır; aynı biçimde $\overline{L_2}$ de.
3. Birleşim kapalı olduğu için $\overline{L_1} \cup \overline{L_2}$ bağlamdan bağımsızdır.
4. Bir kez daha tümleme alınınca $\overline{\overline{L_1} \cup \overline{L_2}}$ de bağlamdan bağımsız olmalıdır.
5. De Morgan kurallarına göre $\overline{\overline{L_1} \cup \overline{L_2}} = L_1 \cap L_2 = \{a^nb^nc^n\}$'dir ve bu dil bağlamdan bağımsız değildir.

Çelişkiye ulaşıldı. Kullanılan adımlar içinde birleşimin kapalı olduğu zaten bilindiği için hatalı olan tek varsayım tümlemenin kapalı olduğudur; demek ki bağlamdan bağımsız diller tümleme altında kapalı değildir.

**Soru:** Bu işlemler De Morgan kuralları mıydı? **Cevap:** Evet; bir öğrencinin onayladığı gibi, tümleyenlerin birleşiminin tümleyeni kesişimi verir.

## 5. Düzenli dillerle karşılaştırma

Hoca, ders başında görülen düzenli dillerin kapalılık özelliklerini hatırlatmak için ilgili eski slaytı açtı. Düzenli diller birleşim, birleştirme, yıldız, tümleme ve kesişim altında kapalıdır. Bağlamdan bağımsız diller ilk üç işlemde aynı şekilde kapalıdır; kesişim ve tümlemede ise ayrılırlar: bu ikisi düzenli dillerde kapalıdır, bağlamdan bağımsız dillerde değildir.

**Soru (hocadan):** Bağlamdan bağımsız diller ters çevirme (reversal) altında kapalı mıdır, tahmin edebilir misiniz? **Cevap:** Bir öğrenci olmaması için bir neden görmediğini söyledi; hoca da kapalı olduğunu düşündüğünü ama emin olmak için biraz uğraşmak gerektiğini belirtti.

> **Ek bilgi (derste anlatılmadı):** Bağlamdan bağımsız diller ters çevirme altında kapalıdır. Gramerdeki her kuralın sağ tarafı ters çevrilerek $L^R$'yi üreten bir bağlamdan bağımsız gramer elde edilir.

## 6. Bağlamdan bağımsız dil ile düzenli dilin kesişimi

### 6.1 Teorem

Bağlamdan bağımsız dillerle düzenli dilleri birlikte ilgilendiren bir özellik vardır: bir bağlamdan bağımsız dil ile bir düzenli dilin kesişimi bağlamdan bağımsızdır.

$$L_1 \text{ bağlamdan bağımsız},\ L_2 \text{ düzenli} \ \Rightarrow\ L_1 \cap L_2 \text{ bağlamdan bağımsız}$$

Hoca bu özelliğe büyük olasılıkla bağlamdan bağımsız dillerin "düzenli kapanışı" (regular closure) dendiğini söyledi.

### 6.2 NPDA ve DPDA adları

Slayt ispat için bir NPDA (nondeterministic pushdown automaton) kuruyor. Hoca, derste öğrenilen yığıtlı otomatların zaten deterministik olmadığını, yani NPDA ile PDA'nın aynı şey olduğunu açıkladı. "N" harfi, deterministik yığıtlı otomat (DPDA) diye ayrı bir alt sınıf bulunduğu için ayrım amacıyla yazılır. Arada hoca iki ders kitabına baktığını, ikisinde de "NPDA" adının geçmediğini, DPDA'nın ise yığıtlı otomatların bir alt kümesi olarak tanımlandığını aktardı. Kısacası slaytlarda NPDA görülen yerde PDA okunabilir.

**Soru:** NPDA adı, PDA'lar zaten deterministik olmadığı için deterministik olanlardan ayırmak amacıyla mı kullanılıyor? **Cevap:** Evet.

### 6.3 İnşa: iki makineyi paralel benzetme

İspat inşa yoluyladır (proof by construction) (ekrandan, 00:50:00):

- $L_1$ bağlamdan bağımsız olduğu için onu kabul eden bir NPDA $M_1$ vardır.
- $L_2$ düzenli olduğu için onu kabul eden bir DFA $M_2$ vardır.
- $L_1 \cap L_2$'yi kabul eden yeni bir NPDA $M$ kurulur; $M$, $M_1$ ile $M_2$'yi paralel olarak benzetir.

Bağlamdan bağımsız dillerin hem gramerleri hem yığıtlı otomatları olduğu için ispat ikisinden biriyle yapılabilir; burada otomat kullanılır, çünkü bu yol çok daha basittir.

$M$'nin durumları, $M_1$'in bir durumu ile $M_2$'nin bir durumundan oluşan $(q, p)$ çiftleridir. Geçişler şöyle kurulur:

- **Okuma geçişleri:** $M_1$'de $q_1 \xrightarrow{a,\ b \to c} q_2$ (girdiden $a$ okunur, yığıt üstündeki $b$ çıkarılıp $c$ konur) ve $M_2$'de $p_1 \xrightarrow{a} p_2$ geçişi varsa, $M$'de $(q_1,p_1) \xrightarrow{a,\ b \to c} (q_2,p_2)$ geçişi eklenir.
- **$\lambda$ geçişleri:** $M_1$'de girdi okumadan yapılan $q_1 \xrightarrow{\lambda,\ b \to c} q_2$ geçişi için $M_2$'nin her $p$ durumunda $(q_1,p) \xrightarrow{\lambda,\ b \to c} (q_2,p)$ eklenir. DFA girdi okumadığı için yerinde kalır; yığıt işlemi doğrudan $M_1$'den gelir.
- **Başlangıç durumu:** iki başlangıç durumu birleştirilerek $(q_0,p_0)$.
- **Kabul durumları:** $q$, $M_1$'in kabul durumu ve $p$, $M_2$'nin kabul durumu olan bütün $(q,p)$ çiftleri.

Hoca $\lambda$ geçişi kuralının kendisi için de yeni olduğunu söyleyerek slaytı birlikte okudu.

> **Ders sonrası not:** Altyazıda $\lambda$ geçişi için eklenen geçiş "Q1, P1'den Q2, P2'ye" gibi duyuluyor. Doğrusu, $\lambda$ geçişinde DFA bileşeninin değişmediği $(q_1,p) \to (q_2,p)$ biçimidir; DFA girdi okumadan durum değiştiremez.

Genel sonuç (ekrandan, 01:25:00 civarı slayt listesi): $M$, bir $w$ dizgesini ancak ve ancak $M_1$ de $M_2$ de $w$'yi kabul ediyorsa kabul eder; yani

$$L(M) = L(M_1) \cap L(M_2)$$

Böyle bir NPDA kurulabildiği için $L_1 \cap L_2$ bağlamdan bağımsızdır.

### 6.4 Örnek

$L_1 = \{w_1w_2 : |w_1| = |w_2|,\ w_1 \in \{a,b\}^*,\ w_2 \in \{c,d\}^*\}$ (ekrandan, 00:55:00). Yani $a$ ve $b$'lerden oluşan bir parçayı, aynı uzunlukta $c$ ve $d$'lerden oluşan bir parça izler. Bu dil bağlamdan bağımsızdır; slayt NPDA $M_1$'i doğrudan veriyor:

| Geçiş | Girdi, yığıt |
|---|---|
| $q_0 \to q_1$ | $\lambda, \lambda \to \lambda$ |
| $q_1 \to q_1$ (döngü) | $a, \lambda \to 1$ ve $b, \lambda \to 1$ |
| $q_1 \to q_2$ | $\lambda, \lambda \to \lambda$ |
| $q_2 \to q_2$ (döngü) | $c, 1 \to \lambda$ ve $d, 1 \to \lambda$ |
| $q_2 \to q_3$ | $\lambda, \lambda \to \lambda$ |

Başlangıç durumu $q_0$; slaytta $q_0$ ve $q_3$ kabul durumu olarak çizilmiş. $a$ ya da $b$ okundukça yığıta $1$ konur; $q_2$'de $c$ ya da $d$ okundukça bu $1$'ler çıkarılır. Sayılar eşitse sonunda yığıtta $1$ kalmaz ve $q_3$'e geçilir.

**Soru:** $q_2$'den $q_3$'e geçerken yığıtta $\$$ görülmesi gerekmiyor mu? Yoksa yığıtın boşaldığını nasıl anlarız? **Cevap:** Hoca ara verip slaytı denedi ve öğrenciye hak verdi: bu hâliyle makine yanlış çalışır. Girdi olarak yalnız bir $a$ verildiğinde yığıta bir $1$ konur, sonra $\lambda$ geçişleriyle $q_3$'e ulaşılır ve dizge kabul edilir; oysa dil $a,b$ sayısının $c,d$ sayısına eşit olmasını ister. Son geçiş, yığıt sonu sembolü $\$$ görüldüğünde yapılacak biçimde düzeltildi (ekrandan, 01:20:00). <!-- BELİRSİZ: düzeltilmiş geçişin tam yazımı karede tamamlanmamış ($\lambda, \$ \to$ ...); büyük olasılıkla $\lambda, \$ \to \$$ -->

> **Ek bilgi (derste anlatılmadı):** Bu tür PDA'larda başlangıçta yığıtta bir $\$$ sembolü bulunduğu (ya da ilk geçişte konduğu) kabul edilir. Yığıt üstünde yeniden $\$$ görülmesi, konan bütün $1$'lerin çıkarıldığını gösterir; kabul durumuna yalnız bu koşulla geçilmesi sayıların eşitliğini garanti eder.

$L_2 = \{a,c\}^*$ düzenli bir dildir: yalnız $a$ ve $c$'lerden oluşan her dizge. DFA $M_2$ tek bir $p_0$ durumundan oluşur; $p_0$ hem başlangıç hem kabul durumudur ve $a$, $c$ ile kendine döner.

Kesişim: kesişimdeki dizgeler iki kalıba da uymalıdır. $L_2$'de $b$ ve $d$ bulunamaz, dolayısıyla kesişimde $b$ ve $d$'ler ortadan kalkar; $a,b$ sayısı $c,d$ sayısına eşit olmalı koşulu $a$ sayısının $c$ sayısına eşit olmasına dönüşür:

$$L_1 \cap L_2 = \{a^nc^n : n \ge 0\}$$

Kurulan NPDA $M$ (ekrandan, 01:25:00): DFA'nın tek durumu $p_0$ olduğu için her duruma $p_0$ eklenir; $b$ ve $d$ geçişlerinin DFA'da karşılığı olmadığı için düşer.

| Geçiş | Girdi, yığıt |
|---|---|
| $(q_0,p_0) \to (q_1,p_0)$ | $\lambda, \lambda \to \lambda$ |
| $(q_1,p_0) \to (q_1,p_0)$ (döngü) | $a, \lambda \to 1$ |
| $(q_1,p_0) \to (q_2,p_0)$ | $\lambda, \lambda \to \lambda$ |
| $(q_2,p_0) \to (q_2,p_0)$ (döngü) | $c, 1 \to \lambda$ |
| $(q_2,p_0) \to (q_3,p_0)$ | $\lambda, \lambda \to \lambda$ |

Kabul durumları $(q_0,p_0)$ ve $(q_3,p_0)$'dır. Hoca, iki makinenin grafiğini kâğıtta yan yana görerek bu çizimin daha kolay yapılacağını söyledi.

## 7. Kesişim özelliğinin uygulamaları

Bu özellik bir dilin bağlamdan bağımsız olduğunu da, olmadığını da ispatlamak için kullanılabilir.

> **Hocanın vurgusu:** Düzenli kapanış her iki amaç için de kullanılabilir: bağlamdan bağımsızlığı ispatlamak ve çürütmek.

### 7.1 Bağlamdan bağımsız olduğunu ispat

Dil: $L = \{a^nb^n : n \ne 100,\ n \ge 0\}$. $a$ ve $b$ sayısı eşittir ama $100$ olamaz. Bu dil, $n$ üzerinde koşul olmayan $\{a^nb^n\}$ bağlamdan bağımsız dilinin bir alt kümesidir; eksik olan tek dizge $a^{100}b^{100}$'dür.

Adımlar (ekrandan, 01:30:00):

1. $L_1 = \{a^{100}b^{100}\}$ düzenlidir (tek dizgeli sonlu dil).
2. Tümleyeni $\overline{L_1} = \{(a+b)^*\} - \{a^{100}b^{100}\}$, yani $a$ ve $b$'lerden oluşan, $a^{100}b^{100}$ dışındaki bütün dizgeler. Düzenli diller tümleme altında kapalı olduğu için $\overline{L_1}$ düzenlidir.
3. $\{a^nb^n\}$ bağlamdan bağımsız, $\overline{L_1}$ düzenli olduğundan düzenli kapanış ile $\{a^nb^n\} \cap \overline{L_1}$ bağlamdan bağımsızdır.
4. $\{a^nb^n\} \cap \overline{L_1} = \{a^nb^n : n \ne 100,\ n \ge 0\} = L$.

Dolayısıyla $L$ bağlamdan bağımsızdır.

### 7.2 Bağlamdan bağımsız olmadığını ispat

Dil: $L = \{w : n_a(w) = n_b(w) = n_c(w)\}$, yani $a$, $b$ ve $c$ sayılarının üçünün de eşit olduğu dizgeler (sıra serbest). Bu dil bağlamdan bağımsız değildir; ispat olmayana ergi ile yapılır:

1. $L$'nin bağlamdan bağımsız olduğunu varsayalım.
2. $L(a^*b^*c^*)$ düzenlidir: herhangi sayıda $a$, ardından herhangi sayıda $b$, ardından herhangi sayıda $c$.
3. Düzenli kapanış ile $L \cap L(a^*b^*c^*)$ bağlamdan bağımsız olmalıdır.
4. Oysa $L \cap L(a^*b^*c^*) = \{a^nb^nc^n\}$ ve bu dil bağlamdan bağımsız değildir.

Çelişki; demek ki $L$ bağlamdan bağımsız değildir.

## 8. Doğrusal ve düzenli gramerler

Bağlamdan bağımsız dillerin özellikleri bitince hoca konu sırasını hatırlattı: düzenli gramerler, DPDA'lar ve sonra Turing makineleri. Düzenli gramerlere doğrusal gramerlerden başlanır.

### 8.1 Doğrusal gramer (linear grammar)

Doğrusal gramer, her kuralın sağ tarafında **en çok bir** değişken bulunan gramerdir. Sağ tarafta iki değişken olan bir kural (örneğin $SS$ içeren) grameri doğrusal olmaktan çıkarır. $a$ ve $b$ sayısının eşit olduğu bir dilin grameri doğrusal olmayabilir; $\{a^nb^n\}$ dilini üreten gramerde ise her kuralda en çok bir değişken vardır, yani bu gramer doğrusaldır. <!-- BELİRSİZ: slayttaki doğrusal olmayan ve doğrusal örnek gramerlerin kuralları karede görülmedi -->

### 8.2 Sağ doğrusal ve sol doğrusal gramerler

Doğrusal gramerler ikiye ayrılır:

- **Sağ doğrusal (right-linear):** bütün kurallar $A \to xB$ ya da $A \to x$ biçimindedir; $x$ bitiş sembollerinden oluşan bir dizgedir. Değişken kuralın sağ ucundadır ya da hiç değişken yoktur. Slayttaki örnekte tekrar tekrar uygulanabilen bir kural $ab$ parçalarını üretiyor, sonunda son $S$ bir $a$ ile kaldırılıyor. <!-- BELİRSİZ: örnek gramer karede görülmedi; anlatımdan büyük olasılıkla $S \to abS \mid a$, dili $(ab)^*a$ -->
- **Sol doğrusal (left-linear):** bütün kurallar $A \to Bx$ ya da $A \to x$ biçimindedir; değişken sağ tarafın sol ucundadır (ekrandan, 01:50:00). Örnek:

$$S \to Aab, \qquad A \to Aab \mid B, \qquad B \to a$$

Burada $A \to Aab$ kuralıyla istenildiği kadar $ab$ üretilir, sonra $A \to B$ ve $B \to a$ ile başa bir $a$ gelir. Gramerin dili $aab(ab)^*$'dır (ajan tarafından python ile kontrol edildi).

### 8.3 Düzenli gramer (regular grammar)

Düzenli gramer, sağ doğrusal ya da sol doğrusal olan herhangi bir gramerdir. Önemli teorem: **düzenli gramerler düzenli dilleri üretir** ve her düzenli dil bir düzenli gramerle üretilir. Hoca, iki kümenin eşitliğini ispatlarken iki yönü ayrı ayrı göstermek gerektiğini hatırlattı:

$$\{\text{düzenli gramerlerin ürettiği diller}\} \subseteq \{\text{düzenli diller}\} \quad \text{ve} \quad \{\text{düzenli diller}\} \subseteq \{\text{düzenli gramerlerin ürettiği diller}\}$$

## 9. Düzenli gramerler düzenli dilleri üretir

### 9.1 Sağ doğrusal gramer durumu

$G$ sağ doğrusal bir gramer olsun. $L(G)$'nin düzenli olduğunu göstermek için $L(M) = L(G)$ olan bir NFA $M$ kurulur; NFA'ların kabul ettiği diller düzenli olduğu için bu yeterlidir.

Örnek gramer (ekrandan, 01:55:00):

$$S \to aA \mid B, \qquad A \to aaB, \qquad B \to bB \mid a$$

NFA'nın kuruluşu:

1. Her değişken için bir durum yazılır: $S$, $A$, $B$. $S$ başlangıç durumudur.
2. Ek olarak özel bir kabul durumu $V_F$ eklenir.
3. Her kural için grafa bir kenar (gerekirse ara durumlarla bir yol) eklenir.

Kurallardan elde edilen geçişler (ekrandan, 02:00:00):

| Kural | NFA geçişi |
|---|---|
| $S \to aA$ | $S \xrightarrow{a} A$ |
| $S \to B$ | $S \xrightarrow{\lambda} B$ |
| $A \to aaB$ | $A \xrightarrow{a} q \xrightarrow{a} B$ ($q$ ara durum) |
| $B \to bB$ | $B \xrightarrow{b} B$ |
| $B \to a$ | $B \xrightarrow{a} V_F$ |

Kuralı neredeyse doğrudan okuyabiliriz: "$S$, $a$ okuyup $A$'ya gider". $B$'nin önünde bitiş sembolü olmadığı için $S \to B$ bir $\lambda$ geçişi olur. Sağında değişken olmayan kural ($B \to a$) kabul durumuna gider.

**Örnek türetim ve NFA çalışması:** $aaaba$ dizgesi (ekrandan, 02:00:00):

$$S \Rightarrow aA \Rightarrow aaaB \Rightarrow aaabB \Rightarrow aaaba$$

NFA aynı dizgeyi şöyle işler (hoca karenin üzerine çizerek izledi; ara durumu $q$ diye adlandırdı):

| Okunan | Etkin durumlar |
|---|---|
| başlangıç | $\{S, B\}$ ($\lambda$ geçişi sayesinde $B$ de etkin) |
| $a$ | $\{A, V_F\}$ ($S \xrightarrow{a} A$, $B \xrightarrow{a} V_F$; yalnız $a$ da kabul edilir) |
| $a$ | $\{q\}$ ($V_F$ $a$ okuyamaz, o kol ölür) |
| $a$ | $\{B\}$ |
| $b$ | $\{B\}$ |
| $a$ | $\{V_F\}$, kabul |

Gramerin ve NFA'nın dili düzenli ifade olarak:

$$L = aaab^*a + b^*a$$

Yani ya üç $a$, herhangi sayıda $b$ ve son bir $a$; ya da herhangi sayıda $b$ ve son bir $a$ (ajan tarafından python ile kontrol edildi).

**Genel yöntem:** $G$'nin değişkenleri $V_0, V_1, V_2, \dots$ ve kuralları $V_i \to a_1a_2\dots a_mV_j$ ya da $V_i \to a_1a_2\dots a_m$ biçiminde olsun.

- Her $V_i$ değişkeni için bir durum, ayrıca bir kabul durumu $V_F$ oluşturulur.
- $V_i \to a_1a_2\dots a_mV_j$ için $V_i$'den $V_j$'ye $a_1, a_2, \dots, a_m$ etiketli kenarlardan ve gerekli ara durumlardan oluşan bir yol eklenir.
- $V_i \to a_1a_2\dots a_m$ için aynı biçimde $V_i$'den $V_F$'ye giden bir yol eklenir.

Bu yöntemle elde edilen NFA $L(G)$'yi kabul eder; dolayısıyla sağ doğrusal gramerlerin dilleri düzenlidir.

### 9.2 Sol doğrusal gramer durumu

Sol doğrusal gramerler için sıfırdan başlamak yerine, onları eşdeğer bir sağ doğrusal gramere çevirme fikri kullanılır (ekrandan, 02:05:00). $G$ sol doğrusal olsun; kuralları $A \to Ba_1a_2\dots a_k$ ya da $A \to a_1a_2\dots a_k$ biçimindedir. Yeni gramer $G'$'de her kuralın sağ tarafı ters çevrilir:

| $G$ (sol doğrusal) | $G'$ (sağ doğrusal) |
|---|---|
| $A \to Ba_1a_2\dots a_k$ | $A \to a_k\dots a_2a_1B$ |
| $A \to a_1a_2\dots a_k$ | $A \to a_k\dots a_2a_1$ |

$G'$ sağ doğrusaldır ve ürettiği dil özgün dilin tersidir:

$$L(G) = L(G')^R$$

$G'$ sağ doğrusal olduğu için $L(G')$ düzenlidir. Düzenli diller ters çevirme işlemi altında kapalıdır (dersin ilk bölümlerinde görülmüştü); dolayısıyla $L(G) = L(G')^R$ de düzenlidir.

Böylece ispatın ilk yönü tamamlanır: sol ya da sağ doğrusal gramerlerin dilleri için NFA elde edilebilir, yani bu diller düzenlidir.

## 10. Her düzenli dil bir düzenli gramerle üretilir

İkinci yön: düzenli gramerlerin ürettiği diller kümesi düzenli dilleri kapsar. $L$ düzenliyse $L = L(M)$ olan bir NFA $M$ vardır; $M$'den $L(M) = L(G)$ olan bir düzenli gramer $G$ kurulur (ekrandan, 02:10:00). Bu, gramerden NFA'ya giderken yapılanın tersidir.

### 10.1 Örnek

NFA $M$ (ekrandan, 02:15:00):

| Geçiş | Sembol |
|---|---|
| $q_0 \to q_1$ | $a$ |
| $q_1 \to q_1$ (döngü) | $b$ |
| $q_1 \to q_2$ | $a$ |
| $q_2 \to q_3$ | $b$ |
| $q_3 \to q_1$ | $\lambda$ |

Başlangıç durumu $q_0$, kabul durumu $q_3$. Dil: bir $a$, sonra herhangi sayıda $b$, sonra $ab$; $q_3$'ten $q_1$'e dönüş sayesinde bu kısım tekrarlanabilir. Düzenli ifade olarak $a(b^*ab)^+$ biçiminde yazılabilir (ajan tarafından python ile kontrol edildi).

Durumlar değişken olur; her geçiş bir kural verir; kabul durumu için $\lambda$ kuralı eklenir. Gramer $G$ (ekrandan, 02:15:00):

$$q_0 \to aq_1, \quad q_1 \to bq_1, \quad q_1 \to aq_2, \quad q_2 \to bq_3, \quad q_3 \to q_1, \quad q_3 \to \lambda$$

Hoca, gramerden NFA'ya giderken kabul durumunun gramerde değişkeni olmadığını, burada ise $q_3$'ün gramere değişken olarak girdiğini fark etti ve sadeleştirme ile $q_3$'ten kurtulmayı denedi:

1. **Birim kuralın atılması:** $q_3 \to q_1$ bir birim kuraldır. $q_3$ sağ tarafta yalnız $q_2 \to bq_3$ kuralında geçer; orada $q_3$ yerine $q_1$ yazılarak $q_2 \to bq_1$ eklenir, sonra $q_3 \to q_1$ silinir.
2. **$\lambda$ kuralının atılması:** $q_3 \to \lambda$ için $q_2 \to bq_3$'teki $q_3$ yerine $\lambda$ yazılır: $q_2 \to b$. Sonra $q_2 \to bq_3$ ve $q_3 \to \lambda$ silinir; artık hiçbir yerde $q_3$ kalmaz.

Sonuç gramer:

$$q_0 \to aq_1, \qquad q_1 \to bq_1 \mid aq_2, \qquad q_2 \to bq_1 \mid b$$

Bu sırada bir öğrenci $q_2$ için bir de $b$ geçişi eklenmesini önerdi; hoca sıra oraya gelince bunun yapıldığını gösterdi. Mantık kontrolü: $q_2$'den $b$ ile $q_1$'e gidilebilir (NFA'da $b$ ile $q_3$'e gidilip $\lambda$ ile $q_1$'e geçilir) ve $q_2$'den $b$ okuyup bitirmek de mümkündür ($q_3$ kabul durumudur). Slaytın yöntemi iki adım fazla ekleyip biraz daha büyük bir gramer veriyor, ama bu gramer sadeleştirilebilir. İki gramerin aynı dili ürettiği ajan tarafından python ile kontrol edildi.

### 10.2 Genel yöntem

- NFA'nın her durumu bir değişken olur.
- Her $q_i \xrightarrow{a} q_j$ geçişi için $q_i \to aq_j$ kuralı eklenir; girdiden okunan sembol bitiş sembolü olur.
- Her kabul durumu $q_f$ için $q_f \to \lambda$ kuralı eklenir.

Elde edilen $G$'de değişkenler hep sağdadır ve her kuralda en çok bir değişken vardır, yani $G$ sağ doğrusaldır, dolayısıyla düzenli bir gramerdir ve $L(G) = L(M) = L$ (ekrandan, 02:20:00). Böylece iki yön birlikte düzenli gramerlerin tam olarak düzenli dilleri ürettiğini gösterir.

## 11. Deterministik yığıtlı otomatlar (DPDA)

### 11.1 Hangi geçişlere izin var?

DPDA, yığıtlı otomatların özel bir durumudur. $\lambda$ içeren geçişlere izin verilir, ama NPDA'da izin verilen bazı geçiş birleşimleri DPDA'da yasaktır.

> **Hocanın vurgusu:** NFA ile DFA ayrılırken DFA'da $\lambda$ geçişi olamıyordu. NPDA ile DPDA ayrılırken DPDA'da $\lambda$ geçişi olabilir; fark bu açıdan farklıdır.

İzin verilmeyen durumlar (non deterministic choices) (ekrandan, 02:40:00):

- Aynı $q_1$ durumundan $a, b \to w_1$ ile $q_2$'ye ve $a, b \to w_2$ ile $q_3$'e gitmek: aynı girdi ve aynı yığıt üstüyle iki farklı şey yapılamaz.
- Aynı $q_1$ durumundan $\lambda, b \to w_1$ ile $q_2$'ye ve $a, b \to w_2$ ile $q_3$'e gitmek: yığıt üstü aynı ($b$) iken hem girdi okumadan hem $a$ okuyarak geçiş yapılamaz.

Hoca, izin verilen ve verilmeyen slaytları karşılaştırarak kuralı Türkçe özetledi:

- Girdi sembolleri farklıysa (yığıt üstü aynı olsa bile) geçişler serbesttir.
- Girdi aynı ama yığıt üstü farklıysa serbesttir.
- Bir geçiş girdi okumuyor ($\lambda$) ama öteki geçişle yığıt üstü farklıysa serbesttir.
- Girdi ve yığıt üstü birebir aynıysa izin yoktur.
- Yığıt üstü aynı iken bir geçişin girdi okumaması, ötekinin okuması izin verilmez.

### 11.2 Deterministik bağlamdan bağımsız diller

Slaytta bir dil için bir DPDA örneği verildi; hoca geçişlerde kurala aykırı bir şey olmadığını gösterdi. <!-- BELİRSİZ: DPDA örneğinin dili ve geçişleri karede görülmedi --> Bir $L$ dilini kabul eden bir DPDA varsa $L$ **deterministik bağlamdan bağımsız** (deterministic context-free) bir dildir.

Ardından deterministik olmayan bir PDA örneği gösterildi: bu makinede aynı yığıt üstüyle hem $\lambda$ okuyan hem girdi okuyan geçişler var; geçişler yalnız girdide farklı ve biri $\lambda$ olduğu için bu yasaktır, dolayısıyla makine deterministik değildir. <!-- BELİRSİZ: örnek makine karede görülmedi -->

### 11.3 PDA'lar DPDA'lardan güçlüdür

Deterministik bağlamdan bağımsız diller kümesi, bağlamdan bağımsız diller kümesinin alt kümesidir (ekrandan, 02:45:00):

$$\{\text{deterministik bağlamdan bağımsız diller (DPDA)}\} \subseteq \{\text{bağlamdan bağımsız diller (PDA)}\}$$

Bunu görmek kolaydır, çünkü her DPDA aynı zamanda bir PDA'dır. "Daha güçlü" demek için kapsamanın kesin olduğunu, yani iki kümenin eşit olamayacağını göstermek gerekir; bunun için bağlamdan bağımsız olup hiçbir DPDA tarafından kabul edilmeyen bir dil gösterilir. Kullanılacak dil:

$$L = \{a^nb^n\} \cup \{a^nb^{2n}\}, \quad n > 0$$

İlk kısımda $a$ ve $b$ sayısı eşit, ikinci kısımda $b$ sayısı $a$ sayısının iki katıdır. $L$'nin bağlamdan bağımsız olduğu ama deterministik bağlamdan bağımsız olmadığı gösterilecek; ispata bir sonraki derste devam edilecek.

> **Ders sonrası not:** Hoca bu yerde "hiçbir pushdown automata tarafından kabul edilmeyen bir bağlamdan bağımsız dil" dedi; doğrusu "hiçbir **deterministik** pushdown automata (DPDA) tarafından kabul edilmeyen" olmalıdır, çünkü her bağlamdan bağımsız dil bir PDA tarafından kabul edilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): $L = \{vv : v \in \{a,b\}^*\}$ dilinin bağlamdan bağımsız olmadığını pompalama önsavıyla ispatlayın.

> **Çözüm:** Derste verildi (Bölüm 2). $a^mb^ma^mb^m$ seçilir; $vxy$ tek bir bloğun içindeyse pompalama o bloğu büyütür ve iki yarı eşitliği bozulur; $v$ ya da $y$ blok sınırındaysa pompalama $a$ ile $b$'yi iç içe sokar; $|vxy| \le m$ olduğu için üç bloğa birden dokunulamaz. Her durumda çelişki çıkar.

**Soru 2** (ekrandan, 00:40:00): $L_1 = \{a^nb^nc^m\}$ ve $L_2 = \{a^nb^mc^m\}$ bağlamdan bağımsızdır. Bunu kullanarak bağlamdan bağımsız dillerin kesişim ve tümleme altında kapalı olmadığını gösterin.

> **Çözüm:** Derste verildi (Bölüm 4). $L_1 \cap L_2 = \{a^nb^nc^n\}$ bağlamdan bağımsız değildir. Tümleme kapalı olsaydı $\overline{\overline{L_1} \cup \overline{L_2}} = L_1 \cap L_2$ bağlamdan bağımsız olurdu; çelişki.

**Soru 3** (derste sözlü, 00:44:03): Bağlamdan bağımsız diller ters çevirme altında kapalı mıdır?

> **Çözüm:** Derste kesin cevap verilmedi; hoca ve bir öğrenci kapalı olduğunu tahmin etti. Bölüm 5'teki ek bilgiye bakın: her kuralın sağ tarafı ters çevrilerek $L^R$ için bir bağlamdan bağımsız gramer elde edilir, yani kapalıdır.

**Soru 4** (ekrandan, 00:55:00 ve 01:25:00): $L_1 = \{w_1w_2 : |w_1| = |w_2|,\ w_1 \in \{a,b\}^*,\ w_2 \in \{c,d\}^*\}$ için verilen NPDA ile $L_2 = \{a,c\}^*$ için verilen DFA'dan $L_1 \cap L_2$'yi kabul eden NPDA'yı kurun. Slayttaki NPDA $M_1$ yalnız $a$ dizgesini kabul eder mi?

> **Çözüm:** Derste verildi (Bölüm 6.4). Kesişim $\{a^nc^n : n \ge 0\}$; $M$'nin durumları $(q_i, p_0)$, yalnız $a$ ve $c$ döngüleri kalır. Slayttaki $M_1$ son geçişte yığıtı denetlemediği için yalnız $a$ dizgesini de kabul eder; geçiş $\$$ okunacak biçimde düzeltilmelidir.

**Soru 5** (ekrandan, 01:30:00): $L = \{a^nb^n : n \ne 100,\ n \ge 0\}$ dilinin bağlamdan bağımsız olduğunu ispatlayın.

> **Çözüm:** Derste verildi (Bölüm 7.1). $\overline{\{a^{100}b^{100}\}}$ düzenlidir; $L = \{a^nb^n\} \cap \overline{\{a^{100}b^{100}\}}$ düzenli kapanış ile bağlamdan bağımsızdır.

**Soru 6** (derste sözlü, 01:31:07): $L = \{w : n_a(w) = n_b(w) = n_c(w)\}$ dilinin bağlamdan bağımsız olmadığını ispatlayın.

> **Çözüm:** Derste verildi (Bölüm 7.2). $L$ bağlamdan bağımsız olsaydı $L \cap L(a^*b^*c^*) = \{a^nb^nc^n\}$ de olurdu; çelişki.

**Soru 7** (ekrandan, 01:55:00): $S \to aA \mid B$, $A \to aaB$, $B \to bB \mid a$ sağ doğrusal gramerine eşdeğer bir NFA kurun ve $aaaba$ dizgesinin kabul edildiğini gösterin.

> **Çözüm:** Derste verildi (Bölüm 9.1). Etkin durum kümeleri $\{S,B\}$, $\{A,V_F\}$, $\{q\}$, $\{B\}$, $\{B\}$, $\{V_F\}$; dizge kabul edilir. Dil $aaab^*a + b^*a$.

**Soru 8** (ekrandan, 02:15:00): Bölüm 10.1'deki NFA'dan sağ doğrusal bir gramer elde edin ve birim ile $\lambda$ kurallarını atarak sadeleştirin.

> **Çözüm:** Derste verildi (Bölüm 10.1). $q_0 \to aq_1$, $q_1 \to bq_1 \mid aq_2$, $q_2 \to bq_1 \mid b$.

## Dersin Toparlaması

Ders, bağlamdan bağımsız diller için pompalama önsavının $\{vv\}$ örneğiyle tekrarlanmasıyla başladı ve bağlamdan bağımsız dillerin kapalılık özelliklerine geçti. Bu diller birleşim, birleştirme ve yıldız altında kapalıdır; kesişim ve tümleme altında kapalı değildir, ki bu düzenli dillerden önemli bir farktır. Buna karşın bir bağlamdan bağımsız dilin düzenli bir dille kesişimi yine bağlamdan bağımsızdır; bu, NPDA ile DFA'nın paralel benzetimiyle ispatlandı ve hem bağlamdan bağımsızlığı ispatlamak hem çürütmek için kullanıldı. Ardından doğrusal, sağ doğrusal ve sol doğrusal gramerler tanımlandı; düzenli gramerlerin tam olarak düzenli dilleri ürettiği, gramerden NFA'ya ve NFA'dan gramere dönüşümlerle iki yönlü gösterildi.

Son bölümde deterministik yığıtlı otomatlara giriş yapıldı: DPDA'da $\lambda$ geçişleri olabilir ama aynı durum ve yığıt üstü için birden fazla seçenek olamaz. Deterministik bağlamdan bağımsız diller bağlamdan bağımsız dillerin alt kümesidir; bu kapsamanın kesin olduğunu $\{a^nb^n\} \cup \{a^nb^{2n}\}$ dili üzerinden gösterme işi bir sonraki derse kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
