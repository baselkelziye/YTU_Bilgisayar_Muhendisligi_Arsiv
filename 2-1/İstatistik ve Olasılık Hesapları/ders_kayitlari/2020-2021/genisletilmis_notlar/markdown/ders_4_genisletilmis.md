# Ders 4 Genişletilmiş Notu: Bayes Kuralı, Zincir Kuralı, Güvenilirlik ve Sayma Yöntemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Toplam Olasılık Kuralı ve Torba Örneği
- 2. Bayes Kuralı
- 3. Şartlı Bağımsızlık
- 4. Zincir Kuralı
- 5. Güvenilirlik Problemleri
- 6. Sayma ve Çarpma İlkesi
- 7. Örnekleme: Dört Durum
- 8. Sıralı ve Yerine Koymalı Örnekleme
- 9. Sıralı ve Yerine Koymasız Örnekleme: Permütasyon
- 10. Sırasız ve Yerine Koymasız Örnekleme: Kombinasyon
- 11. Sırasız ve Yerine Koymalı Örnekleme

## 1. Toplam Olasılık Kuralı ve Torba Örneği

Hoca derse, bugün temel olasılığı bitirip saymaya başlayacağımızı söyleyerek girdi. Ders bu noktadan sonra İngilizce sürdü.

### 1.1 Kuralın Hatırlatılması

Önceki derste toplam olasılık kuralını (law of total probability) görmüştük. Bir $A$ kümesinin olasılığını bulmak için, $A$'nın $B_1, B_2, B_3, B_4$ gibi kümelerle kesişimlerinin olasılıklarını toplayabiliriz. Üstelik her kesişim şartlı olasılıkla yazılabilir:

$$P(A) = \sum_{i=1}^{4} P(A \cap B_i) = \sum_{i=1}^{4} P(A \mid B_i)\,P(B_i)$$

### 1.2 Önce Modelleme

Önceki derste yazılıp çözümü eve bırakılan örneğe döndük. Bir torbada 3 para var ve her birinin seçilme olasılığı aynı. Paralar hileli (unfair). Normalde tura (heads) gelme olasılığı $0.5$ olmalıydı, ama burada 1. para için $0.9$, 2. para için $0.6$, 3. para için $0.3$. Torbadan rastgele bir para çekip atıyoruz. Tura gelme olasılığı nedir?

> **Hocanın vurgusu:** Olasılık sorusunu çözmeden önce olaylara harf vermek ve böylece problemi modellemek iyi bir fikirdir. Sonra verilenleri de, sorulanı da bu harflerle matematiksel ifade olarak yazın.

Harfler şöyle seçildi: $H$ atılan paranın tura gelmesi olayıdır. $C_1, C_2, C_3$ de sırasıyla 1., 2. ve 3. paranın torbadan seçilmesi olaylarıdır. "1. para için tura olasılığı $0.9$" cümlesi aslında bir şartlı olasılıktır: 1. parayı seçtiysek tura gelme olasılığı $0.9$'dur. Verilenler böylece denklem hâline gelir:

$$P(H \mid C_1) = 0.9, \qquad P(H \mid C_2) = 0.6, \qquad P(H \mid C_3) = 0.3$$

Sorulan şey de $P(H)$'dir.

### 1.3 Çözüm

Yeni öğrendiğimiz kuralı uygulamamız yeterli. Üç para olduğu için $i$, 1'den 3'e gider. Her para için, tura gelme olasılığının o paraya şartlı değerini o paranın seçilme olasılığıyla çarparız. Paralar torbadan eşit olasılıkla çekildiğine göre her birinin seçilme olasılığı $1/3$'tür.

- **Verilen:** $P(H \mid C_1) = 0.9$, $P(H \mid C_2) = 0.6$, $P(H \mid C_3) = 0.3$, $P(C_i) = 1/3$.
- **İşlem:** $P(H) = \sum_{i=1}^{3} P(H \mid C_i)\,P(C_i) = 0.9 \cdot \frac{1}{3} + 0.6 \cdot \frac{1}{3} + 0.3 \cdot \frac{1}{3}$
- **Ara sonuçlar (ara adım eklendi):** $0.3 + 0.2 + 0.1$
- **Sonuç (ara adım eklendi):** $P(H) = 0.6$

> **Ders sonrası not:** Hoca toplamı yazıp "bu sayı her neyse olasılığımız odur" dedi, sayısal sonucu söylemedi. Sonuç $0.6$'dır. Python ile hesaplandı.

## 2. Bayes Kuralı

### 2.1 Kural ve Türetilmesi

Temel olasılıkta sıradaki kural Bayes kuralıdır (Bayes' rule). Hoca bunun çok önemli olduğunu baştan söyledi. Herhangi iki $A$ ve $B$ olayı için, $P(A) \neq 0$ ise

$$P(B \mid A) = \frac{P(A \mid B)\,P(B)}{P(A)}$$

Kural doğrudan şartlı olasılığın tanımından çıkar. Tanımı iki yönde yazalım:

$$P(B \mid A) = \frac{P(A \cap B)}{P(A)}, \qquad P(A \mid B) = \frac{P(A \cap B)}{P(B)}$$

İkinci eşitlikte $P(B)$'yi öbür tarafa geçirince $P(A \cap B) = P(A \mid B)\,P(B)$ olur. Bunu birinci eşitlikte yerine koyunca Bayes kuralı elde edilir.

> **Ders sonrası not:** Altyazıda hoca son adımı "$P(A \cap B)$ çarpı $P(B)$ bölü $P(A)$" diye söylüyor. Doğrusu, payda $P(A \cap B)$ değil $P(A \mid B)$ bulunmasıdır: $P(A \mid B)\,P(B) / P(A)$. Hoca kuralın kendisini doğru yazmıştı.

Bayes kuralındaki $P(A)$'yı hesaplamak için çoğu zaman toplam olasılık kuralı gerekir. Bu durumda formül biraz karmaşık görünür, ama sonuçta aynı şeydir.

### 2.2 Örnek: Tura Geldi, Hangi Para?

Aynı torba ve para problemine dönelim, ama soruyu tersine çevirelim. Torbadan bir para çektik, attık ve tura geldi. Bu paranın 1. para olma olasılığı nedir? Yani $P(C_1 \mid H)$ soruluyor.

Bayes kuralını uygulayalım. Hoca formülü şöyle okudu: İlk terim aradığımızın tersidir, yani $P(H \mid C_1)$. Yanına $P(C_1)$ gelir. Paydada da $P(H)$ bulunur.

$$P(C_1 \mid H) = \frac{P(H \mid C_1)\,P(C_1)}{P(H)}$$

Eldekilere bakalım. $P(H \mid C_1) = 0.9$ biliniyor. $P(C_1) = 1/3$ biliniyor. Eksik olan $P(H)$'dir ve onu toplam olasılık kuralıyla buluruz:

$$P(C_1 \mid H) = \frac{P(H \mid C_1)\,P(C_1)}{\sum_{i=1}^{3} P(H \mid C_i)\,P(C_i)}$$

Paydanın biçimi payınkine çok benzer, yalnız $C_1$ yerine $C_i$ gelir. Kullandığımız iki kural budur: dıştaki Bayes kuralı, paydadaki toplam olasılık kuralı. Artık her şey sayıdır, çünkü $P(C_i)$ daima $1/3$'tür ve $P(H \mid C_i)$ değerleri verilmiştir.

- **Verilen:** $P(H \mid C_1) = 0.9$, $P(C_1) = 1/3$, ve bölüm 1'den $P(H) = 0.6$.
- **Pay (ara adım eklendi):** $0.9 \cdot \frac{1}{3} = 0.3$
- **Sonuç (ara adım eklendi):** $P(C_1 \mid H) = \dfrac{0.3}{0.6} = 0.5$

> **Ders sonrası not:** Hoca burada da sayısal sonucu söylemedi. Sonuç $0.5$'tir. Python ile hesaplandı.

> **Ek bilgi (derste anlatılmadı):** Para atılmadan önce 1. paranın seçilmiş olma olasılığı $1/3$ iken, tura gözlendikten sonra $1/2$'ye çıktı. Aynı hesapla 2. para için sonuç $1/3$, 3. para için $1/6$'dır (python ile hesaplandı). Tura gelmesi en yatkın paranın olasılığını artırıp en az yatkın olanınkini azaltmıştır. Kaynaklarda bu iki değere büyük olasılıkla önsel (prior) ve sonsal (posterior) olasılık denir.

> **Hocanın vurgusu:** Bayes kuralı çok önemlidir, sınavda çıkacağından neredeyse emindir. Kuralla yapay zekâ ve makine öğrenmesinde her yerde karşılaşacaksınız. Naive Bayes gibi yöntemler doğrudan bu kuraldan başlar. Kuralın kendisi çok zor değildir, ama bilmeniz gerekir.

## 3. Şartlı Bağımsızlık

Önce bağımsızlığı hatırlayalım. İki $A$ ve $B$ olayının bağımsız olduğunu iki yoldan kontrol edebiliriz:

$$P(A \cap B) = P(A)\,P(B) \qquad \text{ya da} \qquad P(A \mid B) = P(A)$$

İlkinde kesişimin olasılığını, olasılıkları çarparak buluruz. İkincisinin anlamı şudur: $B$'nin gerçekleşmesi bize $A$ hakkında bilgi vermez.

Bu kuralların şartlı biçimleri de yazılabilir. $A$ ve $B$ olayları, bir $C$ olayı verildiğinde şartlı bağımsızdır (conditionally independent) ancak ve ancak

$$P(A \cap B \mid C) = P(A \mid C)\,P(B \mid C)$$

Hocanın dediği gibi, burada yaptığımız tek şey çarpım kuralının her yerine "verilen $C$" eklemektir.

## 4. Zincir Kuralı

### 4.1 İki Olay

Öğrenmemiz gereken bir başka şey, zincir kuralıdır (chain rule). Şartlı olasılığın doğrudan uygulanmasıdır:

$$P(A \cap B) = P(A \mid B)\,P(B)$$

> **Ders sonrası not:** Hoca kuralı önce sonda $P(A)$ ile yazdı, hemen düzeltip $P(B)$ olması gerektiğini söyledi. Doğru biçim yukarıdakidir.

Kural şöyle okunabilir: Önce $B$ gerçekleşir, bunun olasılığı $P(B)$'dir. $B$ gerçekleştikten sonra $A$'nın olasılığı $P(A \mid B)$'dir. Bu ikisini çarparsak kesişimin olasılığını buluruz.

### 4.2 Üç Olay

Aynı kuralın üçlü biçimi de vardır ve birçok şekilde yazılabilir. Önce hangisinin gerçekleşeceğini seçeriz. Diyelim ki önce $C$ oldu: Olasılığı $P(C)$. $C$ olduktan sonra $B$'nin olasılığı $P(B \mid C)$. Şimdi hem $C$ hem $B$ olmuş durumda, dolayısıyla $A$'nın olasılığı $P(A \mid B, C)$ olur. Bu gösterim, $B$ ve $C$'nin ikisinin de gerçekleştiğini bildiğimizi söyler.

$$P(A \cap B \cap C) = P(C)\,P(B \mid C)\,P(A \mid B, C)$$

Sıra değiştirilebilir. Örneğin $A$ ile başlayarak:

$$P(A \cap B \cap C) = P(A)\,P(B \mid A)\,P(C \mid A, B)$$

### 4.3 Şartlı Biçim

Zincir kuralının şartlı biçimi de yazılabilir. İki olaylı kuralı alır, bütün şartlara $C$ ekleriz. $B$ zaten şartta olduğu için $A$'nın şartı "$B$ ve $C$" olur:

$$P(A \cap B \mid C) = P(A \mid B, C)\,P(B \mid C)$$

### 4.4 Virgül Gösterimi

Olasılıkta virgül gördüğünüz her yerde anlamı kesişimdir. Farklı yazarlar farklı gösterim kullanır, ama özellikle kesişim çok kullanıldığı için böyle kısaltmalar yaygındır. Bazı yazarlar araya hiçbir şey koymaz, harfleri yan yana yazar. Bunların hepsi aynı şeydir:

$$P(A \mid B, C) = P(A \mid B \cap C) = P(A \mid BC)$$

Aynı şey çizginin solunda da olabilir: $P(A, B \mid C) = P(A \cap B \mid C)$.

> **Hocanın vurgusu:** Bu kısım önemlidir, anlaşılmış olmalıdır.

**Soru:** Zincir kuralının ispatını görecek miyiz? **Cevap:** Hayır, derste verilmeyecek. Ama zor değil. İki olaylı kural doğrudan şartlı olasılığın tanımından gelir: $P(A \mid B) = P(A \cap B)/P(B)$ eşitliğinde $P(B)$'yi öbür tarafa geçirmekten başka bir şey yapılmamıştır. Üçlü hâli evde denemek için iyi bir alıştırmadır. Hoca, kuralı birkaç kez uygulayarak elde edilebileceğini düşündüğünü söyledi.

> **Ek bilgi (derste anlatılmadı):** Üçlü hâl, hocanın dediği gibi ikili kuralın iki kez uygulanmasıyla çıkar. $B \cap C$'yi tek olay sayarsak $P(A \cap B \cap C) = P(A \mid B \cap C)\,P(B \cap C)$ olur. Sonra $P(B \cap C) = P(B \mid C)\,P(C)$ yazılır. Eşitlik, sonlu örneklem uzaylarında üretilen olaylar üzerinde python ile denetlendi.

<!-- BELİRSİZ: 00:44:00-00:50:30 ve 01:02:07-01:05:04 arasında konuşma büyük ölçüde Türkçe, altyazı bozuk ve döngülü. Okunabildiği kadarıyla konu ders dışı; bu aralıktan akademik içerik çıkarılamadı. -->

## 5. Güvenilirlik Problemleri

Temel olasılık neredeyse bitti. Şimdi karşınıza çıkabilecek özel bir uygulamaya bakalım: güvenilirlik (reliability). Bu tür sorularda bir sistemin bozulmadan çalışma olasılığı istenir.

### 5.1 Yedekli Sabit Disk Örneği

Bir sabit diskin bozulma olasılığı %1'dir. Bu yüzden iki de yedek disk var ve her birinin bozulma olasılığı %2'dir. Üç disk birbirinden bağımsızdır: Biri bozulduğunda öbürleri bozulabilir de bozulmayabilir de. Saklanan bilgi yalnızca üç disk birden bozulursa kaybolur. Bilginin korunma olasılığı nedir?

Her zamanki gibi önce olaylara harf verelim. $H$ ana diskin, $B_1$ birinci yedeğin, $B_2$ ikinci yedeğin bozulması olayı olsun. Verilenler:

$$P(H) = 0.01, \qquad P(B_1) = 0.02, \qquad P(B_2) = 0.02$$

Bilginin korunması, disklerden en az birinin çalışması demektir. Bunu doğrudan yazabiliriz: ana disk bozulmaz **veya** birinci yedek bozulmaz **veya** ikinci yedek bozulmaz.

$$P(H^c \cup B_1^c \cup B_2^c)$$

Bu eşitlik doğrudur, ama doğrudan hesaplamak biraz karmaşıktır. Çünkü üç kümenin birleşim kuralı gerekir:

$$P(A \cup B \cup C) = P(A) + P(B) + P(C) - P(A \cap B) - P(A \cap C) - P(B \cap C) + P(A \cap B \cap C)$$

Bu kuralı üç kesişen küme çizerek düşünebiliriz. Tek tek olasılıkları toplayınca ikili kesişimler iki kez sayılmış olur, bu yüzden onları çıkarırız. Bu kez de ortadaki üçlü kesişim fazla çıkarılmış olur, onu geri ekleriz. İşaretler artı, eksi, artı diye gider.

Bunun yerine tersten düşünelim. "Bilgi korunur" demek, "hepsi birden bozulmaz" demektir. "Hepsi bozulur" olayı $H \cap B_1 \cap B_2$'dir. Bilginin korunması bunun tümleyenidir:

$$P(\text{bilgi korunur}) = 1 - P(H \cap B_1 \cap B_2)$$

Diskler bağımsız olduğu için kesişimi, olasılıkları çarparak buluruz. Olaylar bağımsız olmasaydı zincir kuralını kullanmamız gerekirdi.

- **İşlem:** $P(\text{bilgi korunur}) = 1 - P(H)\,P(B_1)\,P(B_2) = 1 - 0.01 \cdot 0.02 \cdot 0.02$
- **Ara sonuç (ara adım eklendi):** $0.01 \cdot 0.02 \cdot 0.02 = 0.000004$
- **Sonuç (ara adım eklendi):** $1 - 0.000004 = 0.999996$

> **Ders sonrası not:** Hoca bu sayıyı derste hesaplamadı. Sonuç $0.999996$'dır. Birleşim kuralının 7 terimi ayrı ayrı yazılınca da aynı değer çıkar. İkisi de python ile hesaplandı.

**Soru:** Birinci yöntemi kullansaydık, olaylar bağımsız olduğu için kesişimlerin olasılığı sıfır olmaz mıydı? **Cevap:** Hayır, kesişimlerin olasılığı sıfır değildir, ama kolay hesaplanır. Olaylar bağımsızsa kesişimin olasılığı olasılıkların çarpımıdır. Örneğin $P(A \cap C) = P(A)\,P(C)$. Yani birinci yöntemle de hesap yapılabilir. Ama orada yedi terim vardır, tümleyen yolunda ise yalnızca iki terim.

> **Hocanın vurgusu:** Bu sorularda tersten düşünebilmek işi çok kolaylaştırabilir.

### 5.2 Seri ve Paralel Bağlantı

Güvenilirlik soruları bazen devre tasarımı biçiminde sorulur. $A$ ve $B$ bir sabit disk, bir ampul ya da devredeki herhangi bir cihaz olabilir.

**Seri bağlantıda** bütün sistemin çalışması için hem $A$ hem $B$ çalışmalıdır. Bir akım düşünün: Akımın ilerlemesi için önce birinden, sonra öbüründen geçmesi gerekir. Biri bozulursa akım öbür tarafa geçemez. Elbette bu yalnızca akım için geçerli değildir, iki cihazın birlikte çalışmak zorunda olduğu her durum böyledir.

$S$ sistemin bozulmadan çalışması, $A$ ve $B$ de ilgili cihazların çalışması olayları olsun. $A$ **ve** $B$ çalışmalıdır, bu da kesişimdir:

$$P(S) = P(A \cap B)$$

**Paralel bağlantıda** cihazlardan biri bozulsa bile sistem çalışır. Akım geldiğinde iki yoldan birini seçebilir, $B$ çalışmıyorsa $A$'dan geçer. Bu bir yedek gibidir: Biri sabit disk, öbürü de yedeği olsun. Sabit disk bozulursa veriyi yedekten alırız. Burada $A$ **veya** $B$'nin çalışması gerekir. Birleşim "veya", kesişim "ve" gibidir.

$$P(S) = P(A \cup B)$$

Bu birleşimi iki yoldan hesaplayabiliriz. Birleşim kuralı kullanılabilir, ya da özellikle cihaz sayısı ikiden fazlaysa, tümleyenlerin kesişimi 1'den çıkarılabilir:

$$P(A \cup B) = P(A) + P(B) - P(A \cap B) = 1 - P(A^c \cap B^c)$$

Cihazlar bağımsız çalışıyorsa bunu basit bir çarpmayla hesaplarız.

### 5.3 Beş Bileşenli Sistem Örneği

Bir sistem veriliyor. Her bileşen, öbürlerinden bağımsız olarak $0.92$ olasılıkla çalışıyor. Bütün sistemin çalışma olasılığı, yani güvenilirliği nedir?

Üst kolda $A$ ve $B$ seri bağlıdır. Alt kolda $C$, paralel bağlı $D$ ve $E$ ile seridir. İki kol da birbirine paraleldir. Anlatımdan kurulan şema:

```
          +---- A ---- B ----------------+
          |                              |
giris ----+            +--- D ---+       +---- cikis
          |            |         |       |
          +---- C -----+         +-------+
                       |         |
                       +--- E ---+
```

<!-- BELİRSİZ: Şekil slaytta, altyazıda yalnız sözlü anlatılıyor. Şema "A ve B üst kolda seri, D ve E paralel, C ile G seri, F ile H paralel" ifadelerinden kuruldu. Alt kolda C'nin D-E grubunun solunda mı sağında mı olduğu altyazıdan okunmuyor; bu sonucu değiştirmez. -->

İyi bir yaklaşım böl ve fethet (divide and conquer) uygulamaktır. Önce seri bir parça, sonra paralel bir parça bulunur ve problem adım adım küçültülür. Her seri kolda kesişim, her paralel kolda birleşim alınır. Her zamanki gibi $A$, $B$, $C$, $D$, $E$ ilgili cihazın çalışması olayları, $S$ de bütün sistemin çalışmasıdır.

1. **Üst kol:** $A$ ve $B$ seridir. Bunları tek bir $F$ cihazı sayalım. Kolun çalışması için ikisi de çalışmalıdır ve bağımsızdırlar: $P(F) = P(A \cap B) = 0.92^2 = 0.8464$.
2. **Paralel grup:** $D$ ve $E$ paraleldir, bunları $G$ diye adlandıralım. Her birinin tümleyeninin olasılığı $0.08$'dir: $P(G) = P(D \cup E) = 1 - 0.08^2 = 0.9936$.
3. **Alt kol:** Artık sistem küçüldü. $C$ ve $G$ seridir, bunları $H$ diye birleştirelim: $P(H) = P(C \cap G) = 0.92 \cdot 0.9936 = 0.914112$.
4. **Sistem:** $F$ ve $H$ paraleldir: $P(S) = P(F \cup H) = 1 - (1 - 0.8464)(1 - 0.914112) = 1 - 0.1536 \cdot 0.085888 = 1 - 0.0131923968 = 0.9868076032$.

> **Ders sonrası not:** Slaytta 2. adımda bir hata vardı ve hoca bunu derste fark etti: Birleşim için tümleyenlerin kesişimi çıkarılmalıdır, doğru ifade $1 - 0.08^2$'dir. Hoca sayısal değerleri söylemedi, 3. ve 4. adımda yalnız yöntemi tarif edip "son güvenilirlik değerini bu verir" dedi. Yukarıdaki sayılar python ile hesaplandı. Beş bileşenin $2^5$ durumu tek tek toplanınca da aynı sonuç çıktı.

Hoca bu tür problemlerin Baron'un kitabında bulunduğunu, Pishro-Nik'in kitabında olup olmadığını hatırlamadığını söyledi.

## 6. Sayma ve Çarpma İlkesi

### 6.1 Neden Saymayı Öğreniyoruz?

Burada sayı saymayı değil, kümenin elemanlarını saymayı öğreneceğiz. Bir deneyin çıktıları eşit olasılıklıysa, bir olayın olasılığını şöyle hesaplarız: olaydaki çıktı sayısı bölü örneklem uzayındaki çıktı sayısı.

$$P(A) = \frac{|A|}{|S|}$$

<!-- BELİRSİZ: 01:29:04 civarında hoca örneklem uzayını bazen başka bir sembolle de yazdığını söylüyor. Sembol slaytta, altyazıda okunmuyor. Önceki derslerdeki Omega olabilir. -->

Demek ki bir olayın çıktılarını sayabilmeliyiz. Olay yalnızca bir kümedir, yani bir kümenin elemanlarını sayabilmemiz gerekir.

### 6.2 Çarpma İlkesi

Sayma için önce çarpma ilkesini (multiplication principle) ele alırız. Deneyleri sırayla yaptığımızı varsayalım: önce 1. deney, sonra 2. deney, sonra 3. deney, böylece $r$ deney. 1. deneyin $n_1$ çıktısı, 2. deneyin $n_2$ çıktısı, son deneyin $n_r$ çıktısı olsun. Bu $r$ deneylik dizinin çıktı sayısı, hepsinin çarpımıdır:

$$n_1 \cdot n_2 \cdots n_r$$

Hocanın dediği gibi, söylemesi uzun ama fikri çok basit.

### 6.3 Örnek: Alt Komite

Bir üniversitenin planlama komitesinde 3 birinci sınıf (freshman), 4 ikinci sınıf (sophomore), 5 üçüncü sınıf (junior) ve 2 dördüncü sınıf (senior) öğrencisi var. Bunlardan daha küçük bir alt komite seçilecek ve her sınıftan bir kişi alınacak. Kaç farklı alt komite mümkündür?

Üç birinci sınıf öğrencisinden birini seçmek 1. deneyimizdir. Çıktısı bu üç kişiden biridir, yani $n_1 = 3$. Aynı şekilde ikinci sınıftan seçim 2. deneydir ve $n_2 = 4$. Üçüncü deneyin $n_3 = 5$, sonuncunun $n_4 = 2$ çıktısı vardır. Çarpma ilkesiyle:

$$3 \cdot 4 \cdot 5 \cdot 2 = 120$$

Demek ki bu gruptan 120 farklı alt komite kurulabilir.

## 7. Örnekleme: Dört Durum

Çarpma ilkesinin üstüne sayma yöntemlerini kuracağız. Sayacağımız şey örneklerdir. Örnekleme (sampling), bir torbadan nesne çekmek ya da bir kümeden eleman seçmek olarak düşünülebilir. Torba bir küme gibidir, ikisi aynı şeydir. Birden fazla eleman çekiyorsak iki soruyu sormamız gerekir.

**Birinci soru: Çekilen nesneyi geri koyuyor muyuz?** Bir nesne çektik ve yeniden çekeceğiz. Elimizdeki nesneyi yeniden çekmeden önce torbaya geri koyuyorsak buna yerine koymalı örnekleme (sampling with replacement) denir. Nesne hâlâ torbada olduğu için yeniden seçilebilir, yani tekrara izin vardır. Nesneyi geri koymuyor, bir kenara atıyorsak torbada daha az nesne kalır. Buna yerine koymasız örnekleme (sampling without replacement) denir. Bu durumda seçilenlerde tekrar olmaz, bu yüzden bazen tekrarsız (no repetition) da denir.

**İkinci soru: Sıra önemli mi?** $A_1$, $A_2$, $A_3$ nesnelerini çektiğimizi düşünelim. "Önce birinci, sonra ikinci, sonra üçüncü" çekmek ile "önce üçüncü, sonra ikinci, sonra birinci" çekmek farklı sayılıyorsa buna sıralı örnekleme (ordered sampling) denir. Sıra önemli değilse sırasız örneklemedir (unordered sampling).

İki soru birlikte dört durum verir. Bunları sırayla inceleyeceğiz:

| | Yerine koymalı | Yerine koymasız |
| :--- | :---: | :---: |
| **Sıralı** | Bölüm 8 | Bölüm 9 |
| **Sırasız** | Bölüm 11 | Bölüm 10 |

## 8. Sıralı ve Yerine Koymalı Örnekleme

### 8.1 Sayım ve Formül

Bütün durumlarda aynı küçük örneği kullanacağız: $A = \{1, 2, 3\}$ kümesinden 2 eleman seçiyoruz. Bundan sonra $n$ kümedeki eleman sayısını, $k$ seçilecek eleman sayısını gösterecek. Burada $n = 3$, $k = 2$.

Yerine koymalı olduğu için iki seçim aynı eleman olabilir: İlk çekişte 2 geldiyse ikincide yine 2 gelebilir. Sıralı olduğu için de 12 ile 21 farklıdır. Olası bütün seçimler:

$$11,\ 12,\ 13,\ 21,\ 22,\ 23,\ 31,\ 32,\ 33$$

Toplam 9 olasılık vardır. Bunu nasıl hesaplarız? İlk eleman için $n$ seçeneğimiz var. Çektiğimizi geri koyduğumuz için ikinci seçimde de hâlâ $n$ seçenek var. Her çekiş bir deneydir ve her deneyin $n$ çıktısı vardır. Çarpma ilkesiyle $k$ tane $n$'yi çarparız:

$$\underbrace{n \cdot n \cdots n}_{k \text{ tane}} = n^k$$

Örneğimizde $3^2 = 9$.

> **Hocanın vurgusu:** Bu formül kullanılabilir, ama fikri kullanmak genellikle daha kolaydır. Hoca bu formülü ezberinde tutmadığını, yalnızca mantığını hatırladığını söyledi.

### 8.2 Örnek: Türkiye'de Plaka Sayısı

Türkiye'de kaç farklı plaka mümkündür? Plakalar $34\ \text{BA}\ 1482$ kalıbındadır. Hoca sorunun pratik anlamını da belirtti: Araç sayısı bu kalıbın verebileceği sayıyı aşarsa kalıbı değiştirmek, daha fazla hane eklemek gerekir.

Problemi üç parçaya ayıralım: önce 2 rakam, sonra 2 harf, sonra 4 rakam seçeceğiz.

1. **İlk iki rakam:** Küme $\{0, 1, \ldots, 9\}$, yani $n = 10$. Sıfır da gelebilir diye kabul edelim, işi basitleştirir. $10^2$ seçenek vardır.
2. **Harfler:** Hoca önce Türkçenin 29 harfini aldı. Sonra yumuşak G'nin herhalde kullanılamayacağını söyleyip 28'e indirdi. Her harf için 28 seçenek vardır, yani $28^2$.
3. **Son dört rakam:** Her biri için 10 seçenek vardır, yani $10^4$.

Çarpma ilkesiyle sonuç:

$$10^2 \cdot 28^2 \cdot 10^4 = 100 \cdot 784 \cdot 10\,000 = 784\,000\,000$$

> **Ders sonrası not:** Hoca çarpımı yapmadı, "bu sayının ne olduğunu bilmiyorum ama muhtemelen çok büyük, kalıbı değiştirmemiz gerekeceğini sanmıyorum" dedi. Sonuç $784\,000\,000$'dur. Python ile hesaplandı.

**Soru:** Bir öğrenci, 9 ile başlayan plaka olup olmadığını sordu. **Cevap:** Hoca haklı olduğunu söyledi. Bu ayrıntıya girmedik, bütün sayıların kullanılabildiğini kabul ettik. Aksi hâlde her haneyi tek tek düşünüp orada hangi değerlerin kullanılabildiğine bakmak gerekir.

> **Ek bilgi (derste anlatılmadı):** Bu hesap yalnızca çarpma ilkesini göstermek için kaba bir modeldir. Gerçek kurallar büyük olasılıkla daha kısıtlıdır: İlk iki hane 01-81 arası il kodudur, plakalarda Ç, Ğ, İ, Ö, Ş, Ü kullanılmaz, harf sayısı 1-3, rakam sayısı 2-4 arasında değişir. Bu ayrıntılar altyazıda geçmiyor, kısa nottan alındı.

## 9. Sıralı ve Yerine Koymasız Örnekleme: Permütasyon

### 9.1 Sayım ve Formül

Yine iki eleman alıyoruz ve sıra önemli, ama ilk çektiğimizi geri koymuyoruz. $\{1, 2, 3\}$ kümesinden şu ikililer çıkar:

$$12,\ 13,\ 21,\ 23,\ 31,\ 32$$

Önceki listeyle karşılaştıralım: 11, 22 ve 33 artık yok. Çünkü 1'i çektiysek yeniden 1 çekemeyiz. Toplam 6 olasılık kaldı.

Bu sayıya nasıl ulaşırız? Oldukça basit. İlk eleman seçilirken bütün elemanlar kümededir, $n$ seçenek var. Birini aldık ve geri koymuyoruz, ikinci seçimde $n - 1$ eleman var. Üçüncü bir eleman seçecek olsaydık $n - 2$ seçenek kalırdı. Böyle devam edersek $k$. seçimde $n - k + 1$ seçeneğimiz olur:

$$n (n-1) (n-2) \cdots (n-k+1)$$

Sayılar küçükse hoca bu basit mantığı kullanmayı tercih ediyor. Ama bunu bir formüle de çevirebiliriz. İfade $n!$'e benziyor, yalnız sondaki $(n-k)$, $(n-k-1)$, ..., $1$ çarpanları eksik. Onlardan kurtulmak için $n!$'i bunlara, yani $(n-k)!$'e böleriz:

$$P(n, k) = \frac{n!}{(n-k)!}$$

Büyük sayılarda bu formül kullanılır. Küçük sayılarda mantıkla gidilebilir. Örneğimizde $\frac{3!}{1!} = 6$.

### 9.2 Ayırt Edilebilirlik

Bu büyüklük bazen $P(n, k)$ diye gösterilir ve $n$ ayırt edilebilir (distinguishable) nesnenin $k$'lı permütasyonu diye adlandırılır. Bazı kitaplar "sıralı" der, bazıları "ayırt edilebilir". Benzer biçimde "sırasız" yerine de "ayırt edilemez" (indistinguishable) denir.

Sırasız örneklemede 1. nesneyi 2. nesneden ayırt edemeyiz, sıranın önemsiz olmasının nedeni budur. Ancak ayırt edilebilirlik soyuttur. Siz nesneleri birbirinden ayırt edebilirsiniz, ama bu problem açısından önemli olmayabilir. Burada kastedilen, nesnelerin **problemin bakış açısından** ayırt edilemez olmasıdır.

### 9.3 Formülün Geçerlilik Koşulu

Formülde $k$, $n$'den büyük olamaz. Bu mantıklıdır: Üç nesneniz varsa içinden dört tane alamazsınız, en fazla üç alırsınız. Formülü kullanırken bu koşula dikkat edilmelidir. Hoca negatif sayının faktöriyelinin tanımlı olup olmadığını bilmediğini, bu ders açısından önemi olmadığını söyledi.

> **Ders sonrası not:** Hoca koşulu söylerken "$k$, $n$'den küçük ya da eşit, $0$'dan büyük" dedi, sonra kısaca "$k$, $n$'den küçüktür" diye bağladı. $k = n$ durumu da geçerlidir, üç nesneden üçü alınabilir: $\frac{3!}{0!} = 6$. Kısa not koşulu $0 \le k \le n$ diye verir; $k = 0$ için de formül $\frac{3!}{3!} = 1$ verir (python ile hesaplandı).

## 10. Sırasız ve Yerine Koymasız Örnekleme: Kombinasyon

### 10.1 Sayım

Hoca bu konuların liseden bilindiğini, bu yüzden biraz hızlı geçtiğini söyledi. Yine $n = 3$, $k = 2$. Bu kez sıra önemsiz: 12 varsa 21'i ayrıca saymayız, ikisi bu tür seçimde aynı şeydir. Elimizde şunlar kalır:

$$12,\ 13,\ 23$$

Yani 3 olasılık var. Bu durum, önceki listeden 21, 31 ve 32'yi atmak gibidir, çünkü onlar 12, 13 ve 23 ile aynı seçimdir.

Bu tür seçime kombinasyon (combination) deriz. Önceki duruma da permütasyon demiştik.

> **Ders sonrası not:** Hoca burada "sıralı, yerine koymalı örnekleme permütasyondu" dedi. Doğrusu: Permütasyon, sıralı ve **yerine koymasız** örneklemedir. Sıralı ve yerine koymalı durumun sayısı $n^k$'dır.

### 10.2 Formül

Kombinasyonu permütasyondan elde ederiz. Permütasyon sayısı $\frac{n!}{(n-k)!}$ idi. Fazla sayılanlardan kurtulmak için $k!$'e böleriz:

$$\binom{n}{k} = \frac{P(n, k)}{k!} = \frac{n!}{k!\,(n-k)!}$$

Bu büyüklük "$n$ seç $k$" (n choose k) diye okunur. Kombinasyon sırayı ortadan kaldırır.

**Soru:** Kombinasyonu $P$ ile değil de $C$ ile gösteremez miyiz? **Cevap:** Hoca kombinasyona geldiğini, $P$'yi $k!$'e bölerek $C$'yi elde edeceğimizi söyledi. Gösterim olarak iki biçim de kullanılır.

> **Ders sonrası not:** Hoca neden $k!$'e bölündüğünü o an hatırlayamadığını söyledi. Açıklama şudur: Seçilen $k$ elemanın $k!$ farklı sıralaması vardır ve permütasyon bunların hepsini ayrı sayar, kombinasyonda ise hepsi tek seçimdir. Örneğimizde $k = 2$ için her seçim $2! = 2$ kez sayılmıştır: $6 / 2 = 3$. Python ile listelenerek de doğrulandı.

### 10.3 Örnek: 52 Kartlık Desteden 5 Kartlık El

Bir iskambil destesinde 52 kart var. Elinizde 5 kart var. Kaç farklı el olabilir? 52 karttan 5 kart seçiyoruz.

Bu sırasızdır: Önce şu kartı ya da önce bu kartı almış olmanız önemli değildir, önemli olan elinizde ne olduğudur. Yerine koymasızdır da: Kartı desteden fiziksel olarak aldığınız için aynı kartı yeniden çekemezsiniz. Yani bu bir kombinasyondur:

$$\binom{52}{5} = \frac{52!}{5!\,47!} = 2\,598\,960$$

> **Ders sonrası not:** Hoca sonucu $\binom{52}{5}$ olarak bıraktı. Sayısal değer python ile hesaplandı.

## 11. Sırasız ve Yerine Koymalı Örnekleme

### 11.1 Sayım

Son durumda sıra önemsiz, ama tekrar serbest. Yine $n = 3$, $k = 2$. 12 ile 21 aynı şey olduğundan yalnız birini sayarız. Şunlar kalır:

$$11,\ 12,\ 13,\ 22,\ 23,\ 33$$

Yani 6 olasılık. Listeye 31, 21 ve 32'yi almadık, çünkü 13, 12 ve 23 zaten var.

### 11.2 Formül ve Derste Bulunan Hata

Hoca formülün nasıl elde edildiğini derste göstermeyeceğini söyleyip formülü yazdı, sonra örnekle kontrol etti. Kontrol sonucu tutmadı. Hoca "burada bir hata var galiba" dedi. Bir öğrenci formülde $n + k - 1$ olması gerektiğini söyledi. Bunun üzerine denendi:

$$\binom{n+k-1}{k} = \binom{3+2-1}{2} = \binom{4}{2} = \frac{4!}{2!\,2!} = \frac{4 \cdot 3 \cdot 2}{2 \cdot 2} = 6$$

Bu sonuç listeyle uyuştu.

> **Ders sonrası not:** Formül önce $\binom{n-k+1}{k}$ biçimindeydi. Bu $n = 3$, $k = 2$ için $\binom{2}{2} = 1$ verir (python ile hesaplandı), oysa liste 6 elemanlıdır. Doğrusu $\binom{n+k-1}{k} = \binom{n+k-1}{n-1}$'dir. İki biçim aynıdır, çünkü $(n+k-1) - k = n - 1$.

### 11.3 Örnek: Donut Seçimi

Hoca bu örneği Wikipedia'dan aldığını söyledi. Bir restorandasınız ve menüde dört çeşit donut var: örneğin çikolatalı, ballı, muzlu, meyveli. Üç donut seçmek istiyorsunuz. Aynı çeşidi birden fazla alabilirsiniz, örneğin iki çikolatalı ve bir muzlu.

Burada $n = 4$, $k = 3$. Bu sayı bazen $CR(n, k)$ diye gösterilir, hoca bunun Baron'un gösterimi olduğunu söyledi.

$$\binom{n+k-1}{k} = \binom{4+3-1}{3} = \binom{6}{3} = 20$$

<!-- BELİRSİZ: Gösterim altyazıda "CRN, CRNK" diye geçiyor. Slayttaki tam biçim okunmuyor. -->

> **Ders sonrası not:** Hoca menüyü anlatırken bir yerde "üç çeşit donut" dedi. Doğrusu, örneğin başındaki gibi dört çeşittir. $\binom{6}{3} = 20$ sonucu python ile hesaplandı.

### 11.4 Yıldızlar ve Çubuklar

Formülde sanki seçilecek nesne sayısını artırıyoruz: Dört çeşit varken altıdan seçiyoruz. Bunun fikri yıldızlar ve çubuklar (stars and bars) yöntemidir. Her yıldız bir donuttur. Çubuklar ise donut çeşitlerini birbirinden ayırır. İki seçimi şöyle yazabiliriz:

- `** | | | *` : Birinci çeşitten 2, ikinciden 0, üçüncüden 0, dördüncüden 1 donut.
- `* | * | * |` : Birinci, ikinci ve üçüncü çeşitten birer donut, dördüncüden hiç.

Sayılacak nesneler böylece artmış olur: Çubukları da katınca seçilecek 6 şey vardır. Hoca bu noktada 6 içinden neden 3 seçildiğini derste tam toparlayamadı, Wikipedia'dan ya da kitaptan okunabileceğini söyledi.

> **Ders sonrası not:** Eksik kalan açıklama şudur: $n$ çeşidi ayırmak için $n-1$ çubuk gerekir. $k$ yıldız ve $n-1$ çubuk birlikte $n+k-1$ konum oluşturur. Bir seçimi belirlemek için bu konumlardan hangi $k$ tanesinin yıldız olduğunu seçmek yeterlidir. Donut örneğinde 3 yıldız ve 3 çubuk 6 konum verir ve $\binom{6}{3} = 20$ olur. Bütün konum seçimleri python ile sayılarak 20 bulundu.

**Soru:** Dört farklı donuttan üç tane seçiyoruz ve tekrar edebiliyoruz. O hâlde sonuç $4 \cdot 4 \cdot 4$ olmayacak mı? **Cevap:** Hoca "hayır, mantığını biraz daha düşünmek lazım" dedi ve Wikipedia'daki tam listeyi açtı. Orada 20 seçimin hepsi yazılıydı. Hoca, sonucun $x_1 + x_2 + x_3 + x_4 = 3$ denkleminin çözümlerinden elde edildiğini, ayrıca çubukların yerleştirilebileceği farklı yerler üzerinden de görülebileceğini söyledi.

> **Ders sonrası not:** Hoca soruya doğrudan bir gerekçe vermedi. $4^3 = 64$ sıralı seçimleri sayar. Burada ise (çikolatalı, muzlu, çikolatalı) ile (çikolatalı, çikolatalı, muzlu) aynı seçimdir. Çeşitlere 1-4 numarası verilince 20 seçim şunlardır: 111, 112, 113, 114, 122, 123, 124, 133, 134, 144, 222, 223, 224, 233, 234, 244, 333, 334, 344, 444. Denklemin negatif olmayan tam sayı çözümleri de 20 tanedir. İkisi de python ile sayıldı.

<!-- BELİRSİZ: 02:46:50-02:49:47 arasında hoca Wikipedia'daki listeyi ve çubuk gösterimini Türkçe okuyor. Altyazı bozuk, ayrıntılar okunmuyor. -->

**Soru:** Bunun kombinasyondan farkı ne? **Cevap:** Kombinasyonda donutları tekrar edemezsiniz: Her çeşitten en fazla bir tane alacağım derseniz standart kombinasyon olur. Birinden birden fazla alabilirim dediğiniz anda bu duruma dönüşür.

## Dersin Toparlaması

Ders temel olasılığın son kurallarıyla başladı. Toplam olasılık kuralı torba ve para örneğinde uygulandı, Bayes kuralı da şartlı olasılığın tanımından türetilerek aynı örnekte ters soruya, yani tura geldiğinde paranın hangisi olduğuna uygulandı. Şartlı bağımsızlık, bağımsızlığın her yerine "verilen $C$" eklenmiş hâlidir. Zincir kuralı, kesişimi olayları birer birer gerçekleşiyormuş gibi şartlı olasılıklarla yazar. Güvenilirlik problemlerinde seri bağlantı kesişime, paralel bağlantı birleşime karşılık gelir. Birleşimi doğrudan hesaplamak yerine tümleyenden gitmek ve karmaşık sistemi böl ve fethet ile adım adım küçültmek işi kolaylaştırır.

Dersin ikinci yarısı saymaya ayrıldı. Eşit olasılıklı çıktılarda olasılık, kümenin eleman sayısına dayandığı için çarpma ilkesi ve dört örnekleme durumu görüldü: sıralı ve yerine koymalı $n^k$, sıralı ve yerine koymasız $P(n,k)$, sırasız ve yerine koymasız $\binom{n}{k}$, sırasız ve yerine koymalı $\binom{n+k-1}{k}$. Hoca, Baron'un kitabında Bölüm 2'nin bittiğini, Pishro-Nik'in kitabında da temel kavramların ve kombinatoriğin büyük kısmının tamamlandığını söyledi. Bölüm sonlarındaki problemlerin çözülmesini önerdi. Sıradaki konu kesikli rastgele değişkenlerdir (discrete random variables).

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
