# Ders 24 Genişletilmiş Notu: Matris Uygulamaları: Sepet Analizi, Basit Şifreleme ve Kelimelerin Birlikte Geçişi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sepet analizi: problem ve kullanım alanları
- 2. Veri yapıları: S ve A matrisleri
- 3. S matrisinden A matrisine geçiş
- 4. A matrisinden T matrisine geçiş: ürün ikilileri
- 5. İyileştirmeler
- 6. Ürün üçlüleri
- 7. Basit bir şifreleme uygulaması
- 8. Frekans analizi ve çoklu temsil
- 9. Metinde arka arkaya gelen kelime ikilileri
- 10. Kelimenin K komşuluğundaki kelimeler
- 11. Birlikte geçişten kelime koordinatlarına: Harris varsayımı ve MDS
- 12. Kelime koordinatlarının kullanımı
- Örnek Sorular
- Dersin Toparlaması

## 1. Sepet analizi: problem ve kullanım alanları

Dersin ilk konusu **sepet analizi**dir. Bir süpermarket düşünelim: kasaların önünde insanlar aldıklarını sepetlere doldurmuş, ödeme noktalarından geçiyorlar. Bir sürü sepet ve her sepetin içinde farklı farklı ürünler vardır; örneğin bir sepette deterjan, çikolata, simit olabilir (ekrandan, 00:15:00). Amaç, **hangi ürünlerin birlikte satıldığını** bulmaktır. "Birlikte satılmak" burada aynı sepetin içinde yer almak demektir. Aynı durum internet sitelerindeki sepetler için de geçerlidir.

Hoca bu bilginin nerelerde kullanılabileceğini sorar. Öğrencilerden gelen ve hocanın onayladığı cevaplar şunlardır:

- Reklam ve markalar arası anlaşma.
- Birlikte satılan ürünlerin reyonlarını yakın koymak; satışlar artabilir.
- Depolama stratejisi.
- Kampanyalar: "şunu alana şu indirimli" gibi.
- Kullanıcılara ürün önermek: "bu ürünü alanlar şunları da aldı".

Hoca son maddeyi özellikle önemli bulur. Ürün önerme büyük bir pazardır ve en etkili hâli e-ticarettedir. Gerçek bir süpermarkette herkes aynı mağazaya girer; e-ticaret sitesinde ise **kişiselleştirme** sayesinde her kullanıcıya kendisine özel arayüzler ve sayfalar gösterilebilir. Bu yüzden birlikte satılma bilgisi ticari olarak kritik bir problemdir.

## 2. Veri yapıları: S ve A matrisleri

Önce ürün **ikilileri** ile başlanır. Sepet verilerinin tutulduğu yapıya **S** denir (ekrandan, 00:15:00). S'in iki sütunu vardır: sepet ID ve ürün ID. Tahtadaki örnek satırlar şunlardır:

| sepet ID | ürün ID |
|---|---|
| 1 | 783 |
| 1 | 442 |
| 2 | 13 |
| ... | ... |

Yani 1 numaralı sepette 783 ve 442 numaralı ürünler, 2 numaralı sepette 13 numaralı ürün vardır. S'in $N$ satırı ve 2 sütunu vardır, yani $N \times 2$'lik bir matristir.

İkinci matris **A**, hangi ürünün hangi sepette olduğunu gösterir. Satırları ürünlere, sütunları sepetlere karşılık gelir. **ürünN** farklı ürün sayısıdır (ekrandan, 00:15:00), **sepetN** sepet sayısıdır. Dolayısıyla A, $\text{ürünN} \times \text{sepetN}$'lik bir matristir. Örneğin $A(1,2) = 1$ olması 1 ID'li ürünün 2 ID'li sepette olduğunu gösterir. A'nın içi yalnız 1 ve 0'lardan oluşur: o sepette o ürün var mı, yok mu. S'in içinde ise her türlü sayı olabilir.

Hoca tablo başlıklarının (sepet ID'leri, ürün ID'leri) ayrıca oluşturulmayacağını, yalnız tabloların iç kısmının doldurulacağını belirtir. Ürün ID'leri 1'den ürünN'e kadar sıralanıyor olabilir; bu ayrıntı çok önemli değildir.

## 3. S matrisinden A matrisine geçiş

Veri S biçiminde verilmiştir. Başlangıçta A'nın içi boştur. Hoca öğrencilere S'i kullanarak A'yı oluşturmalarını ister ve birkaç dakika süre verir.

Çözümün akış diyagramı tahtadadır (ekrandan, 00:25:00). Önce $N$ okunur, çünkü S'in kaç satır olduğu başlangıçta bilinmez. Sonra $i = 1$'den $N$'e kadar bir döngüyle her satırda iki değer okunur: $S(i,1)$ ve $S(i,2)$. Satırdaki iki değer için ayrıca döngü açmaya gerek yoktur, doğrudan okunur.

Ardından A sıfırlanır; bellekte önceki işlerden kalmış değerlerle uğraşmamak için bu gereklidir. Hoca C'de diziyi `static` tanımlamanın da içini sıfırlayarak oluşturduğunu hatırlatır. Sıfırlama iki iç içe döngüyle yapılır: $i = 1..\text{ürünN}$, $j = 1..\text{sepetN}$, $A(i,j) = 0$.

Asıl iş S'in her satırı için tek bir işlemdir. Örneğin bir satırda (3, 42) varsa, bu 42 numaralı ürünün 3 numaralı sepette olduğunu söyler; A'nın 42. satırının 3. sütunu 1 yapılır. Yani S'in birinci sütunundaki değer (sepet ID) A'da sütun numarası, ikinci sütundaki değer (ürün ID) satır numarası olur. Döngü S'in satır sayısı kadar döner:

```text
BAŞLA
Oku: N
i ← 1, 1, N:            Oku: S(i,1), S(i,2)
i ← 1, 1, ürünN:
    j ← 1, 1, sepetN:   A(i,j) ← 0
i ← 1, 1, N:            A(S(i,2), S(i,1)) ← 1
```

İlk iki kısım ekrandaki çizimden (ekrandan, 00:25:00), son satır hocanın anlatımından alınmıştır. Bu döngü bittiğinde S'teki bütün bilgiler A'ya işlenmiş olur.

Bir ürün aynı sepette birden fazla kez geçebilir. A'da bu durumda da hücre artırılmaz, doğrudan 1 yapılır; bu yüzden A yalnız 1 ve 0'lardan oluşur. Her sepette her üründen kaç tane olduğu da tutulmak istenirse hücre artırılabilir. Ama burada amaç birlikte geçişleri bulmak olduğu için buna gerek yoktur.

## 4. A matrisinden T matrisine geçiş: ürün ikilileri

Asıl soru şudur: hangi ürün hangi ürünle **kaç kez** birlikte satılmış? Bunun için yeni bir matrise, **T**'ye ihtiyaç vardır.

**Soru:** Bu matrisin boyutları ne olmalıdır? **Cevap:** Bir öğrenci "ürün ID çarpı ürün ID" der. Hoca ürün ID'nin sabit bir sayı olmadığını, değişen bir değer olduğunu hatırlatır. Doğru cevap $\text{ürünN} \times \text{ürünN}$'dir.

> **Hocanın vurgusu:** T, $N \times N$ değildir. $N$, S matrisinin satır sayısıdır; ürünN ise farklı ürün sayısıdır.

T kare bir matristir. Örneğin $i$. ürün çikolata, $j$. ürün şeker ise ve $T(i,j) = 41$ ise, çikolata ile şeker 41 sepette birlikte bulunmuştur (ekrandan, 00:30:00). $T(i,j) = 0$ ise bu iki ürün hiç birlikte satılmamıştır.

T, A kullanılarak üretilir. A'nın bir **sütunu** bir sepettir; örneğin bir sütunda 1, 0, 0, 0, 1, 0, ... varsa o sepette 1. ve 5. ürünler vardır. Hoca öğrencilere A'dan T'yi oluşturmaları için beş dakika verir.

Bir öğrencinin önerisi "iki tane for açarız, sonra şöyleyse şöyleyse" biçimindedir; hoca benzer bir şey yapılacağını söyler. T'nin önce sıfırlanması gerekir; hoca bunu yazmadan T'nin sıfırlanmış olduğunu varsayar.

Her ürün her ürünle kontrol edilmelidir, bu yüzden ürünler üzerinde iki döngü gerekir. Ama 3. ürünle 5. ürün kontrol edildikten sonra 5. ürünle 3. ürünü yeniden kontrol etmeye gerek yoktur. Bu yüzden ilk döngü $i = 1..\text{ürünN}$, ikinci döngü $j = i+1..\text{ürünN}$ olur. Böylece 1. ürün 2, 3, 4, 5, ... ile; 2. ürün 3, 4, 5, ... ile kontrol edilir.

İki ürünün kaç sepette birlikte olduğunu saymak için bütün sepetler gezilmelidir. Bu da üçüncü bir döngü gerektirir: $k = 1..\text{sepetN}$, yani A'nın sütun sayısı kadar. Döngünün içinde şu sorulur: $k$. sepette $i$. ürün ve $j$. ürün var mı? İkisi de 1 ise $T(i,j)$ bir artırılır (ekrandan, 00:45:00):

```text
i ← 1, 1, ürünN:
    j ← i+1, 1, ürünN:
        k ← 1, 1, sepetN:
            (A(i,k) == 1) && (A(j,k) == 1) ise:
                T(i,j) ← T(i,j) + 1
```

Bu işlem bitince T'nin içinde 0, 1, 2, 3, ... gibi sayılar olur; çünkü $T(i,j)$, $i$. ve $j$. ürünün kaç sepette birlikte yer aldığıdır.

T'nin her gözü doldurulmamıştır; yalnız sağ üst üçgeni doldurulmuştur. Köşegen, yani bir ürünün kendisiyle birlikte geçişi gerekli değildir; bir ürünün kaç kez satıldığı burada istenmez. Alt üçgen ise üst üçgenin simetriğidir. Bu yüzden yalnız üst kısmı gezmek yeterlidir.

## 5. İyileştirmeler

Hoca bu çözümü iyileştirmek için neler yapılabileceğini sorar.

**Soru:** $k$ döngüsünü de $j+1$'den başlatsak olur mu? **Cevap:** Hayır. $k$ sepetleri gösterir, ürünlerle ilgisi yoktur; her sepetin gezilmesi gerekir.

**Soru:** Bir öğrenci $k$ döngüsünü öne almayı önerir: $k$. sepette $A(i,k)$ 1 ise $j$ döngüsü çalışsın, değilse hiç çalışmasın; çalışırsa $A(j,k)$ 1 ise işlem yapılsın. **Cevap:** Hoca önce $k$'yı en dışa almanın if'i yazmayı zorlaştıracağını söyler. Öğrenci $k$'yı $i$ ile $j$ döngülerinin arasına almayı kastettiğini açıklayınca hoca bunu kabul eder: iki kontrolü her seferinde birden yapmak yerine, ikinci kontrol yalnız gerektiğinde, yani $i$. ürün o sepette varsa yapılır. Bu işi hızlandırır.

```text
i ← 1, 1, ürünN:
    k ← 1, 1, sepetN:
        A(i,k) == 1 ise:
            j ← i+1, 1, ürünN:
                A(j,k) == 1 ise: T(i,j) ← T(i,j) + 1
```

Bu sürüm hocanın tahtaya yazdığı biçim değildir, öğrencinin sözlü önerisinden kurulmuştur.

**Soru:** İlk hâldeki if'ten kurtulabilir miyiz? **Cevap:** Evet. Bir öğrenci "artı bir yerine $A(i,k) \cdot A(j,k)$" der. İki ikilik değerin ikisinin de 1 olması, ancak çarpımlarının 1 olmasıyla mümkündür. Bu yüzden if kaldırılıp şu yazılabilir (ekrandan, 00:50:00):

$$T(i,j) = T(i,j) + A(i,k) \cdot A(j,k)$$

Hoca bu hâliyle bile işin oldukça karmaşık olduğunu belirtir: döngüler yaklaşık $\text{ürünN} \cdot \text{ürünN} \cdot \text{sepetN}$ kez döner ve bu büyük rakamlar demektir. Farklı varyasyonlarla daha da iyileştirme yapmak mümkündür.

## 6. Ürün üçlüleri

Aradan sonra aynı iş ürün **üçlüleri** için yapılır. A'nın yapısı değişmez; yine hangi ürünün hangi sepette olduğunu tutar. Bu kez her sepet için "bu üç ürün birlikte geçiyor mu?" sorusu sorulur.

T bu sefer **üç indisli** bir matristir: $T(i,j,k)$. T sıfırlandıktan sonra döngüler şöyledir:

```text
i ← 1, 1, ürünN:
    j ← i+1, 1, ürünN:
        k ← j+1, 1, ürünN:
            m ← 1, 1, sepetN:
                T(i,j,k) ← T(i,j,k) + A(i,m) * A(j,m) * A(k,m)
```

Yine T'nin tamamı gezilmez, gerektiği kadarı gezilir. Hoca bunun da hızlandırılabileceğini, burada sunulan çözümlerin karmaşıklığının yüksek olduğunu söyler. Konuyla daha çok ilgilenenlere çok daha iyi çözümler sunan **Apriori** algoritmasını incelemelerini önerir.

> **Ek bilgi (derste anlatılmadı):** Apriori, büyük olasılıkla şu gözleme dayanır: bir ürün kümesi az sayıda sepette geçiyorsa, onu içeren daha büyük kümeler de en fazla o kadar sepette geçer. Bu yüzden önce sık geçen tekli ürünler, sonra yalnız bunlardan kurulan ikililer, sonra üçlüler sayılır. Böylece bütün ikili ve üçlüleri tek tek saymak gerekmez.

### 6.1 Ders sonrası denetim

Ders sonrası, yukarıdaki S → A, ikili ve üçlü sayımı küçük bir C programına dökülüp `gcc -Wall` ile derlendi (bu tam program derste yazılmadı, ajan tarafından test edildi). Dizilerin 1'den başlayan indislerle kullanılması için boyutlar bir fazla alındı ve diziler `static` tanımlandı:

```c
#include <stdio.h>
#define MAXN 100
#define MAXURUN 10
#define MAXSEPET 10

int main() {
    static int S[MAXN + 1][3];
    static int A[MAXURUN + 1][MAXSEPET + 1];
    static int T[MAXURUN + 1][MAXURUN + 1];
    static int T3[MAXURUN + 1][MAXURUN + 1][MAXURUN + 1];
    int N, urunN, sepetN, i, j, k, m;

    scanf("%d %d %d", &N, &urunN, &sepetN);
    for (i = 1; i <= N; i++)
        scanf("%d %d", &S[i][1], &S[i][2]);   /* sepetID, urunID */

    for (i = 1; i <= urunN; i++)
        for (j = 1; j <= sepetN; j++)
            A[i][j] = 0;

    for (i = 1; i <= N; i++)
        A[S[i][2]][S[i][1]] = 1;

    for (i = 1; i <= urunN; i++)              /* urun ikilileri */
        for (j = i + 1; j <= urunN; j++)
            for (k = 1; k <= sepetN; k++)
                T[i][j] = T[i][j] + A[i][k] * A[j][k];

    for (i = 1; i <= urunN; i++)              /* urun uclulari */
        for (j = i + 1; j <= urunN; j++)
            for (k = j + 1; k <= urunN; k++)
                for (m = 1; m <= sepetN; m++)
                    T3[i][j][k] = T3[i][j][k] + A[i][m] * A[j][m] * A[k][m];

    for (i = 1; i <= urunN; i++)
        for (j = i + 1; j <= urunN; j++)
            if (T[i][j] > 0)
                printf("T[%d][%d] = %d\n", i, j, T[i][j]);
    for (i = 1; i <= urunN; i++)
        for (j = i + 1; j <= urunN; j++)
            for (k = j + 1; k <= urunN; k++)
                if (T3[i][j][k] > 0)
                    printf("T3[%d][%d][%d] = %d\n", i, j, k, T3[i][j][k]);
    return 0;
}
```

Denemede 3 sepet kullanıldı: 1. sepette 1, 2, 3; 2. sepette 1, 2; 3. sepette 1, 2, 3 numaralı ürünler. Program $T(1,2)=3$, $T(1,3)=2$, $T(2,3)=2$ ve $T(1,2,3)=2$ verdi; elle sayımla aynıdır.

## 7. Basit bir şifreleme uygulaması

İkinci konu yine matrislerle ilgilidir: basit bir şifreleme uygulaması. Şifrelenmiş mesaj, orijinali bilinmeden bakıldığında anlaşılmayan mesajdır. Şifrelemenin uzun bir tarihi vardır; savaşlarda haber iletmek için kullanılmıştır. Amaç, mesaj düşmanın eline geçtiğinde okunamaması, dostun eline geçtiğinde okunabilmesidir. İnternette de birçok uygulama mesajları şifreleyip gönderir.

Hoca harfleri bir matrisin gözlerine yerleştirir (ekrandan, 01:05:00). Tabloda bazı harfler eksik, bazı gözler boştur; bunun önemi yoktur. ABC metni şöyle kodlanır (ekrandan, 01:15:00):

| harf | satır | sütun | kod |
|---|---|---|---|
| A | 2 | 3 | 23 |
| B | 1 | 2 | 12 |
| C | 1 | 5 | 15 |

Yani her harf, bulunduğu satır numarasının 10 katına sütun numarası eklenerek kodlanır. Algoritma basittir: girdi bir karakter dizisidir (string); her karakter tabloda aranır, bulunduğu yerin satır ve sütun numarasından sayı üretilir. Şifre fonksiyonunun çıktısı bu sayıların dizisidir: ABC için 23, 12, 15. Hoca bu algoritmanın kodunu yazmaz.

> **Ders sonrası not:** Hoca önce "sütun numarasını 10 ile çarpıp satır numarasını eklemek" dedi (01:05:30), hemen sonra "satır numarasını 10 ile çarpıp sütun numarasını eklemek" diye anlattı (01:06:03). Tablodaki konumlara göre doğrusu ikincisidir: A 2. satır 3. sütundadır ve kodu 23'tür.

Boşluk da tabloda yer alır ve bir sayıyla kodlanır. Hoca "Ali geliyor" örneğinde A'yı 23, L'yi 12, İ'yi 45, boşluğu 33 diye yazar (ekrandan, 01:15:00). Böylece şifreli metinde kelimelerin nerede başlayıp bittiği de görünmez. Bu örnekteki sayılar yalnız açıklama içindir; L'nin kodu yukarıdaki tablodaki B'nin koduyla aynı yazılmıştır.

## 8. Frekans analizi ve çoklu temsil

**Soru:** Yalnız şifreli metni görsek ve metnin Türkçe olduğunu bilsek, tabloyu bilmeden şifreyi çözmek mümkün müdür, nasıl yapılır? **Cevap:** Önce kısa metin düşünülür: 23, 12, 15. Her sayının bir harfe karşılık geldiğini bilmek büyük bir bilgidir, ama elde kelime yoktur. Üç sayı birbirinden farklı olduğu için, farklı harflerden oluşan bütün üç harfli Türkçe kelimeler çözüm olabilir. Yani kısa bir metinde çözüm tek değildir ve bu pek işe yaramaz.

**Soru:** Elimizde çok uzun bir metnin şifreli hâli olsa avantaj sağlar mı? **Cevap:** Öğrenciler önce aynı sayıların aynı harfler olduğundan, tekrar eden üçlü ve dörtlü sayı gruplarını Türkçedeki kelimelerle eşleştirmekten söz eder. Hoca şifreli metinde kelimelerin bile belli olmadığını, üç harfli bir grubun hangi kelime olduğunu anlamanın zor olduğunu belirtir. Sonunda bir öğrenci en çok geçen sayıya bakmayı önerir: örneğin 23 metinde 50 kez geçmişse bu A ya da E olabilir. Hoca bunu onaylar: harflerin o dildeki **frekansları** kullanılır.

Hocaya göre Türkçe bir metinde en çok A'lar, sonra E'ler tekrar eder. Kısa bir metinde bu yapılamaz. Uzun bir metinde şifreli sayıların frekansları bulunur ve dildeki harflerin (boşluk dahil) frekanslarıyla eşleştirilir. Yukarıda en çok tekrar eden sayı ile dilde en çok tekrar eden harf aşağı yukarı eşleşecektir. Önce belli harfler tahmin edilir, sonra iş kolaylaşır.

> **Hocanın vurgusu:** Bu zayıflığın nedeni **birebir eşlemedir**. 23 görülen her yer her zaman A'dır.

**Soru:** Bu problemi ortadan kaldırmak için nasıl şifrelenebilir? **Cevap:** Bir öğrenci birçok tablo kullanmayı önerir; hoca tek tablonun yeteceğini, ama tablonun büyütüleceğini söyler. Fikir, bir harfin tek bir karşılığı yerine **birçok karşılığı** olmasıdır. Her harfin dildeki frekansına bakılır ve harfler tabloda frekanslarıyla orantılı sayıda yer alır. Örneğin A metinlerde %10, B %3, C %3 geçiyorsa A tabloda çok, B ve C daha az kez yer alır. Şifrelenecek metinde bir A geldiğinde, tablodaki bütün A'ların konumlarına bakılır ve bunlardan biri **rastgele** seçilip yazılır.

Bunun sonucunda uzun bir şifreli metinde bütün sayıların geçme frekansları birbirine çok yakın olur; "en fazla 23 geçmiş" diye bir şey kalmaz, çünkü 23 de, 42 de, 65 de A'nın temsilleridir. Bire bir şifreleme yerine bire çok temsil kullanmak, şifre kıran açısından problemi çok zorlaştırır.

Hoca bu şifrelemenin kodlarının dersin sayfasında olduğunu belirtir. Bir dildeki karakterlerin frekansını sayıp tabloyu buna göre oluşturmak gibi kısımları öğrencilerin kendilerinin gerçeklemesini, bunun öğretici bir çalışma olacağını söyler.

> **Ek bilgi (derste anlatılmadı):** Bir harfi birden çok simgeyle gösteren bu yönteme büyük olasılıkla **homofonik (eş sesli) yerine koyma şifresi** denir. Her harfin tek bir karşılığı olan ilk yönteme ise basit yerine koyma (monoalfabetik) şifresi denir ve frekans analizine karşı zayıflığı bilinir.

## 9. Metinde arka arkaya gelen kelime ikilileri

Sonraki problem sepet problemine benzer, ama uygulama alanı bambaşkadır. Elimizde bir metin ve bir sözlük vardır. Sözlükte her kelimenin bir ID'si bulunur. Metin, kelimelerin ID'lerinden oluşan **M** dizisiyle tutulur (ekrandan, 01:30:00):

| Ali | bugün | okula | geldi |
|---|---|---|---|
| 45 | 120 | 748 | 12 |

Metindeki kelime sayısı $N$, sözlüğün boyutu (farklı kelime sayısı) **kelimeN**'dir.

**Soru:** Bu metinde arka arkaya en çok geçen kelime ikililerini bulun. **Cevap:** Bunun için $\text{kelimeN} \times \text{kelimeN}$'lik bir **W** matrisi gerekir; tıpkı sepetlerdeki ürün-ürün matrisi gibi. W oluşturulduktan sonra içindeki en yüksek değerler, arka arkaya en çok geçen kelime ikilileridir.

Bir öğrencinin çözümünde iki döngü vardır: biri $i$, öteki $j = i+1$'den gider. Hoca bunun bir kelimeyi kendisinden sonraki bütün kelimelerle eşlediğini, oysa yalnız bitişik kelimelere bakmak gerektiğini gösterir. İkinci döngüye gerek yoktur; tek döngü yeterlidir ve $M(i)$ ile $M(i+1)$ kullanılır (ekrandan, 01:30:00):

```text
i ← 1, 1, N-1:
    W(M(i), M(i+1)) ← W(M(i), M(i+1)) + 1
```

Döngü $N-1$'e kadar gider, çünkü son kelimenin arkasında kelime yoktur. W'nin bazı gözleri 0, bazılarında sayılar olur.

Bu W'nin bir satırı, o kelimeden sonra en çok gelen kelimeleri gösterir. Hoca "kedi" örneğini verir: "kedi" satırında sıfır olan çok kelime vardır, ama "kedi tırnağı", "kedi kuyruğu", "kedi miyavladı", "kedi yavrusu" gibi kediden sonra sık gelen kelimelerin gözlerinde yüksek sayılar görülür.

## 10. Kelimenin K komşuluğundaki kelimeler

Sonra problem değiştirilir. Bu kez ardışıklığa bakılmaz. Her kelimenin $K$ öncesinden $K$ sonrasına kadarki aralıkta, yani $2K+1$ genişliğindeki pencerede (ortada kelimenin kendisi vardır) en çok hangi kelimelerin bulunduğu istenir (ekrandan, 01:30:00). Sonuç yine bir W matrisidir. "Kedi" satırındaki yüksek frekanslı kelimeler bu kez kedinin $K$ komşuluğunda bulunan kelimeler olacaktır; yalnız kediden sonra gelenler değil, önce gelenler de.

Hoca öğrencilerin çözümleri üzerine konuşur. Ortadaki kelimenin konumu birer birer kaydırılır: bir yerde durulur, $K$ etrafına bakılır, bir yana kayılır, yine $K$ etrafına bakılır.

**Soru:** Bir öğrenci yalnız ileriye bakmanın yeteceğini düşünür. **Cevap:** Hoca bunun olmayacağını tahmin eder; o zaman yalnız kelimeden sonra gelen kelimelere bakılmış olur. $-K$'dan $K$'ya bakmak yerine 1'den $2K$'ya bakmak aynı şeyi ifade etmez.

Dizi belki 100.000 ya da 100.000.000 elemanlıdır (ekrandan, 01:40:00). Başlangıç noktası, kelimenin solunda $K$ genişliğinde yer kalacak biçimde seçilmeli ve sağda $K$ yer kalacak noktaya kadar gidilmelidir. Bu yüzden dış döngü $i = 1+K$'dan $N-K$'ya kadar gider (ekrandan, 01:40:00). Bir öğrenci en baştan başlayıp indise $2K$ ekleyerek aynı işin yapılabileceğini söyler; hoca bu tür hilelerin de olabileceğini, olayı değiştirmeyeceğini belirtir.

$K$ sabit bir sayı olmadığından komşulara erişmek için bir iç döngü gerekir: $j = -K..K$. $M(i)$ ile $M(i+j)$ çifti için W güncellenir:

```text
i ← 1+K, 1, N-K:
    j ← -K, 1, K:
        W(M(i), M(i+j)) ← W(M(i), M(i+j)) + 1
    W(M(i), M(i)) ← W(M(i), M(i)) - 1
```

**Soru:** İkinci döngüye gerek var mı; doğrudan $i-K$ ve $i+K$ konumları artırılsa olmaz mı? **Cevap:** Hayır. Yalnız $K$ uzaklığındaki kelimelere bakılmaz; $K$ bir aralıktır ve aralığın içindeki bütün kelimelere bakılır. Bu yüzden döngü gerekir.

Küçük bir düzeltme de yapılır: $j$, $-K$'dan $K$'ya giderken 0'dan da geçer ve o zaman $W(M(i), M(i))$ kelimenin kendisiyle bir artırılır. Kendisinin işe karışmaması için her adımda bu değer bir azaltılabilir ya da iş bittikten sonra toplu olarak düzeltilebilir. Hoca bunun çok da şart olmadığını söyler.

### 10.1 Ders sonrası denetim

İki W hesabı küçük bir C programıyla denendi (bu tam program derste yazılmadı, ajan tarafından `gcc -Wall` ile derlenip test edildi):

```c
#include <stdio.h>
#define MAXN 100
#define MAXKELIME 10

int main() {
    int M[MAXN + 1];
    static int W[MAXKELIME + 1][MAXKELIME + 1];
    static int W2[MAXKELIME + 1][MAXKELIME + 1];
    int N, kelimeN, K, i, j;

    scanf("%d %d %d", &N, &kelimeN, &K);
    for (i = 1; i <= N; i++)
        scanf("%d", &M[i]);

    for (i = 1; i <= N - 1; i++)              /* ardisik ikililer */
        W[M[i]][M[i + 1]] = W[M[i]][M[i + 1]] + 1;

    for (i = 1 + K; i <= N - K; i++) {        /* -K..K komsuluk */
        for (j = -K; j <= K; j++)
            W2[M[i]][M[i + j]] = W2[M[i]][M[i + j]] + 1;
        W2[M[i]][M[i]] = W2[M[i]][M[i]] - 1;
    }

    for (i = 1; i <= kelimeN; i++) {
        for (j = 1; j <= kelimeN; j++) printf("%d ", W[i][j]);
        printf("\n");
    }
    printf("\n");
    for (i = 1; i <= kelimeN; i++) {
        for (j = 1; j <= kelimeN; j++) printf("%d ", W2[i][j]);
        printf("\n");
    }
    return 0;
}
```

$M = 1, 2, 3, 1, 2, 4, 1, 2$ ve $K = 1$ ile ardışık W'de $W(1,2) = 3$ çıktı: "1 2" ikilisi metinde üç kez geçer. Komşuluk W'sinde 1. kelimenin satırı $0, 2, 1, 1$ oldu; $i=4$ ve $i=7$ konumlarındaki 1'lerin komşuları (3, 2) ve (4, 2)'dir, elle sayımla aynıdır.

## 11. Birlikte geçişten kelime koordinatlarına: Harris varsayımı ve MDS

Hoca bu basit görünen problemlerin önemli uygulamaları olduğunu göstermek için bir slayta geçer. Slaytta yer, hayvan ve taşıt isimlerinden oluşan 30 kelime vardır (berber, bakkal gibi); ama hangi kelimenin hangi türden olduğu bilgisi algoritmaya verilmez.

### 11.1 W'yi kurmanın iki yolu

Slayttaki iki yol şunlardır (ekrandan, 01:55:00):

- Birinci yol: elde $k_1, k_2, k_3, \ldots$ diye çok uzun bir derlem vardır. $W(i,j)$: $i$ ve $j$ kelimeleri derlemde $K$'lık pencere içinde kaç kez birlikte geçmiştir. Bu, 10. bölümde yapılan iştir.
- İkinci yol: elde $D_1, D_2, D_3, \ldots$ diye milyarlarca doküman (örneğin web sayfası) vardır. $W(i,j)$: $i$ ve $j$ kelimeleri kaç dokümanda birlikte geçmiştir. Burada $K$'ya bakılmaz; iki kelime aynı dokümandaysa birlikte geçmiş sayılır.

İkinci yol için bir ticari arama motoru ya da kurum içinde kurulmuş bir arama motoru kullanılabilir. İki kelime birlikte arandığında arama motoru "şu kadar sonuç" bilgisini verir. Bu sayı, yazılan kelimelerin kaç kaynakta birlikte bulunduğudur. Bu sayı W'nin ilgili gözüne yazılır. Sonuçların sıralanması ayrı bir konudur; burada yalnız sayı kullanılır. Hoca bir öğrencinin isteği üzerine iki yolu yeniden, tahtada da göstererek anlatır.

30 kelime için hangi yolla kurulursa kurulsun W, $30 \times 30$'luk bir matristir.

### 11.2 Harris varsayımı

Dil bilimci **Harris**'in bir varsayımı vardır (ekrandan, 02:00:00): **birlikte geçen kelimeler anlamsal olarak birbirlerine yakındır.** W'deki $W(i,j)$ değerinin büyük olması iki kelimenin, dokümanlarda ya da pencerelerde, çok sık birlikte geçtiğini gösterir. Harris'e göre bu, iki kelimenin anlamca yakın olması demektir. Yani W, kavramlar arasındaki anlamsal yakınlıkları verir.

### 11.3 Uzaklıklardan koordinat bulma

Şimdi W kullanılarak kelimelere **koordinatlar** atanacaktır; örneğin iki boyutlu koordinatlar. Bu koordinatlar W'deki değerlerle uyumlu olmalıdır. Problem şudur: elimizde $n$ tane nokta var; noktaların birbirine uzaklıklarını biliyoruz, ama koordinatlarını bilmiyoruz. Bu uzaklıklarla uyumlu koordinatları bulmak istiyoruz. Burada noktalar kelimelerdir.

Anlaşılmayınca hoca işi tersten anlatır. Önce üç nokta alır: $(1,1)$, $(2,2)$, $(3,3)$ ve bunların W matrisini öğrencilerle birlikte kurar (ekrandan, 02:05:00):

| W | 1 | 2 | 3 |
|---|---|---|---|
| 1 | 0 | 1 | 2 |
| 2 | 1 | 0 | 1 |
| 3 | 2 | 1 | 0 |

1. noktanın 2. noktaya uzaklığına 1 denir; 1. noktanın 3. noktaya uzaklığı bunun iki katı olduğu için 2, 2. noktanın 3. noktaya uzaklığı 1'dir. Köşegen 0'dır. Asıl problem bunun tersidir: elimizde yalnız bu W varsa, ondan koordinat tablosu üretilebilir mi?

> **Ders sonrası not:** Hoca 1. ve 2. noktanın uzaklığının "tam bir olmaz, bir diyelim" dedi. Öklid uzaklıkları $|(1,1)-(2,2)| = \sqrt{2} \approx 1{,}414$ ve $|(1,1)-(3,3)| = 2\sqrt{2} \approx 2{,}828$'dir (python ile denetlendi). Tablo bu uzaklıkların $\sqrt{2}$'ye bölünmüş hâlidir; oranlar (1 : 2 : 1) korunduğu için anlatılan fikir değişmez.

Bir öğrenci bir orijin ve merkez noktası belirlemek gerektiğini söyler. Hoca bunun aslında çözümün tek olmadığı anlamına geldiğini açıklar: üç nokta aralarında birer birim aralık bulunan bir doğru üzerindedir; bu noktalar istenildiği gibi kaydırılabilir ve döndürülebilir. Aynı W'ye eşit derecede uygun sonsuz sayıda çözüm vardır; bunlardan biri seçilir.

Bu işi yapan algoritma **MDS (Multidimensional Scaling, çok boyutlu ölçekleme)**dir (ekrandan, 02:05:00). Hoca ayrıntısına girmez; temel mantığının PCA ile benzediğini söyler. MDS'e koordinatları bilinmeyen ama aralarındaki uzaklıkları bilinen noktaların uzaklıkları verilir, o da uygun bir koordinat takımı döndürür. Hoca W'nin "yakınlıklar" ya da "uzaklıklar" matrisi olmasının burada fark etmediğini söyler.

> **Ek bilgi (derste anlatılmadı):** Klasik MDS büyük olasılıkla şöyle çalışır: uzaklıkların kareleri merkezlenerek noktaların iç çarpım matrisi elde edilir, bu matrisin en büyük özdeğerlerine karşılık gelen özvektörler koordinat olarak alınır. PCA ile benzerliği bu özdeğer ayrışımından gelir.

### 11.4 Sonuçlar

Slayttaki ilk grafikte (ikinci yolla, arama motoru sonuç sayılarıyla kurulmuş W), 30 kelime için $30 \times 30$'luk W MDS'e verilmiş ve iki boyutlu koordinatlar alınmıştır. Öğrenciler kelimelerin kümelendiğini fark eder: hayvanlar bir tarafta, yerler bir tarafta durur. Bakkal ile büfe, park ile okul birbirine yakın çıkmıştır; limuzin ile tren de yakın çıkmıştır. Önemli olan, algoritmanın kelimelerin hangisinin yer, hangisinin hayvan, hangisinin taşıt olduğunu hiç bilmemesidir; buna rağmen aynı türden kelimeler öbeklenmiştir.

Başka bir kelime kümesinde ev eşyaları ve hayvanlar vardır. Divan ile bit yakın çıkmıştır; hoca eskiden divanlarda bit olduğunu hatırlatır. At ile bizon, ahır ile bazı hayvanlar da yakın çıkmıştır. Bir öğrenci ambulansın hastaneye uzak çıktığını fark eder; hoca bunun yakın çıkmasının daha güzel olacağını kabul eder. Bu yalnız 30 kelimeyle yapılmış bir denemedir ve mükemmel değildir; iyi ve kötü örnekler vardır, ama iyi örnekler epey fazladır ve yöntem iyileştirilebilir.

<!-- BELİRSİZ: MDS sonuç grafiklerinin kareleri yok (02:05-02:10 arası slayt dışı ya da kelime tablosu slaytı görünmüyor); kelime yakınlıkları yalnız altyazıdan alındı. -->

## 12. Kelime koordinatlarının kullanımı

**Soru:** Kelimelerin koordinatlarını bulmak ne sağlar? **Cevap:** Bir öğrenci şifre çözmeyi önerir; hoca bunun olmadığını söyler. Hoca bu amaçla, yani kelime koordinatları üretmek için oluşturulmuş yapılara ait anahtar kelimeler verir ve bunların araştırılmasını önerir. Bu yapılar MDS'in işini yapay sinir ağlarıyla yapar; ama ortaya çıkan şey yine kelimelerin ya da cümlelerin koordinatlarıdır.

<!-- BELİRSİZ: Hocanın verdiği anahtar kelimeler ekranda gösterildi, ama karelerde okunmuyor. -->

Koordinatı yakın olan kelimeler anlamca da yakınsa, **iki metnin benzerliği** bulunabilir. Bu, doğal dil işleme çalışmalarındaki büyük problemlerden biridir. Metinlerin ortak kelimelerine bakılarak bir şeyler çıkarılabilir; ama hiç ortak kelime içermeyen iki ifade anlamca çok ilişkili olabilir ve bu, harflere ya da kelimelere bakarak bulunamaz. Hoca örnekte "Cimbom" ile "Galatasaray"ın, "kazandı" ile "yendi"nin koordinat olarak yakın çıkacağını söyler; böylece bu iki ifadenin benzer şeyler söylediği anlaşılabilir. Bunun için böyle koordinat uzaylarına ihtiyaç vardır.

<!-- BELİRSİZ: Ekranda gösterilen iki ifadenin tam metni karelerde yok; yalnız altyazıdaki Cimbom/Galatasaray ve kazandı/yendi eşleri biliniyor. -->

> **Ek bilgi (derste anlatılmadı):** Yapay sinir ağlarıyla kelime koordinatı (kelime vektörü, "word embedding") üreten yöntemlere büyük olasılıkla word2vec ve GloVe örnek verilebilir. Bu yöntemler de kelimelerin bir pencere içinde birlikte geçmesinden yararlanır; yani 10. bölümdeki $K$ komşuluğu fikrine dayanır.

## Örnek Sorular

### Soru 1: Birlikte satılma bilgisinin kullanımı

(derste sözlü, 00:08:59) Hangi ürünlerin birlikte satıldığını bulsak, bu bilgi ne gibi amaçlarla kullanılabilir?

> **Çözüm (derste verildi, 00:10:05 - 00:11:59):** Reklam, markalar arası anlaşma, reyonları yakın koyma, depolama stratejisi, kampanyalar ve kullanıcılara ürün önerme ("bu ürünü alanlar şunları da aldı"). Ürün önerme özellikle e-ticarette, kişiselleştirme sayesinde etkilidir.

### Soru 2: S'ten A'ya geçiş

(ekrandan, 00:15:00 ve derste sözlü, 00:18:11) Sepet ID ve ürün ID çiftlerini tutan $N \times 2$'lik S matrisinden, $\text{ürünN} \times \text{sepetN}$'lik ikilik A matrisini (ürün o sepette varsa 1) oluşturan akış diyagramını çizin.

> **Çözüm (derste verildi, 00:22:05 - 00:26:08):** $N$ ve S okunur; A iki döngüyle sıfırlanır; $i = 1..N$ için $A(S(i,2), S(i,1)) = 1$ yapılır. Ayrıntı 3. bölümdedir.

### Soru 3: T matrisinin boyutu

(derste sözlü, 00:27:47) Hangi ürünün hangi ürünle kaç kez birlikte satıldığını tutacak matris kaça kaçlık olmalıdır?

> **Çözüm (derste verildi, 00:28:07):** $\text{ürünN} \times \text{ürünN}$. $N \times N$ değildir, çünkü $N$ S'in satır sayısıdır.

### Soru 4: A'dan T'ye geçiş ve iyileştirme

(ekrandan, 00:45:00; derste sözlü, 00:31:22 ve 00:42:05) A matrisini kullanarak T matrisini oluşturun. Sonra çözümü iyileştirin; içteki if'ten kurtulabilir misiniz?

> **Çözüm (derste verildi, 00:36:48 - 00:46:39):** $i = 1..\text{ürünN}$, $j = i+1..\text{ürünN}$, $k = 1..\text{sepetN}$; $A(i,k)$ ve $A(j,k)$ 1 ise $T(i,j)$ bir artırılır. İyileştirmeler: $k$ döngüsünü $i$ ile $j$ arasına alıp $A(i,k) = 1$ değilse $j$ döngüsünü çalıştırmamak; ya da if yerine $T(i,j) = T(i,j) + A(i,k) \cdot A(j,k)$ yazmak.

### Soru 5: Ürün üçlüleri

(derste sözlü, 00:47:10) T matrisini ürün üçlüleri için oluşturun.

> **Çözüm (derste verildi, 01:00:01 - 01:02:26):** T üç indisli olur; $i < j < k$ ürünler ve $m = 1..\text{sepetN}$ için $T(i,j,k) = T(i,j,k) + A(i,m) \cdot A(j,m) \cdot A(k,m)$.

### Soru 6: Tablo bilinmeden şifre çözme

(derste sözlü, 01:07:13 ve 01:09:30) Harf tablosu bilinmeden, yalnız şifreli sayılar (örneğin 23, 12, 15) ve metnin Türkçe olduğu bilinerek şifre çözülebilir mi? Şifreli metin çok uzun olsaydı ne değişirdi? Bu zayıflığı gidermek için nasıl şifrelenebilir?

> **Çözüm (derste verildi, 01:08:37 - 01:18:27):** Kısa metinde çözüm tek değildir; farklı harflerden oluşan her üç harfli kelime aday olur. Uzun metinde sayıların frekansları dildeki harf frekanslarıyla (boşluk dahil) eşleştirilerek harfler tahmin edilir. Zayıflığın nedeni birebir eşlemedir; çözüm, harfleri tabloda frekanslarıyla orantılı sayıda yerleştirip şifrelerken konumlardan birini rastgele seçmektir.

### Soru 7: Arka arkaya en çok geçen kelime ikilileri

(ekrandan, 01:30:00; derste sözlü, 01:21:03) Kelime ID'lerini tutan $N$ elemanlı M dizisinde arka arkaya en çok geçen kelime ikililerini bulmak için W matrisini oluşturun.

> **Çözüm (derste verildi, 01:27:23 - 01:28:47):** W $\text{kelimeN} \times \text{kelimeN}$'liktir. $i = 1..N-1$ için $W(M(i), M(i+1))$ bir artırılır. En yüksek değerli gözler en sık ardışık ikililerdir.

### Soru 8: K komşuluğu

(ekrandan, 01:30:00; derste sözlü, 01:29:30) Her kelimenin $-K..+K$ aralığında en çok hangi kelimelerin bulunduğunu gösteren W matrisini oluşturun.

> **Çözüm (derste verildi, 01:39:44 - 01:43:21):** $i = 1+K..N-K$, $j = -K..K$ için $W(M(i), M(i+j))$ bir artırılır; $j = 0$ durumundaki kendisiyle sayım için $W(M(i), M(i))$ bir azaltılır.

### Soru 9: Uzaklık matrisi ve koordinatlar

(ekrandan, 02:05:00; derste sözlü, 02:00:02 ve 02:01:30) $(1,1)$, $(2,2)$, $(3,3)$ noktaları için W uzaklık matrisini kurun. Elinizde yalnız W olsaydı koordinatları bulabilir miydiniz; çözüm tek midir?

> **Çözüm (derste verildi, 02:00:42 - 02:03:17):** Derste W = [[0, 1, 2], [1, 0, 1], [2, 1, 0]] kuruldu (gerçek Öklid uzaklıkları $\sqrt{2}$ ve $2\sqrt{2}$'dir; oranlar aynıdır). W'den koordinat bulunabilir, ama çözüm tek değildir: noktalar kaydırılıp döndürülebilir. Bu işi MDS algoritması yapar.

### Soru 10: Kelime koordinatlarının faydası

(derste sözlü, 02:09:24) Kelimelerin koordinatlarını bulmak ne sağlar?

> **Çözüm (derste verildi, 02:10:24 - 02:12:20):** Koordinatı yakın kelimeler anlamca da yakın olduğundan, hiç ortak kelime içermeyen iki metnin anlamsal benzerliği bulunabilir (örneğin "Cimbom" ve "Galatasaray", "kazandı" ve "yendi" yakın çıkar).

## Dersin Toparlaması

Bu derste matrislerle çalışan üç uygulama işlendi. Sepet analizinde (sepet ID, ürün ID) listesi olan S'ten ürün-sepet ikilik matrisi A, A'dan da ürün-ürün birlikte geçiş sayısı matrisi T elde edildi. T'nin yalnız üst üçgeni gezildi; çözüm, döngülerin yerini değiştirerek ve if yerine çarpım kullanarak iyileştirildi, sonra üç indisli T ile ürün üçlülerine genişletildi. Daha verimli yöntem olarak Apriori algoritması önerildi.

Basit şifreleme örneğinde harfler tablodaki satır ve sütun numaralarıyla kodlandı. Birebir eşlemenin frekans analiziyle kırılabileceği, harfleri dildeki frekanslarıyla orantılı sayıda temsil edip rastgele seçmenin bunu zorlaştırdığı görüldü. Son olarak, sepet fikri metne taşındı: ardışık kelime ikilileri ve $K$ komşuluğundaki kelimeler için W matrisleri kuruldu. Harris varsayımıyla bu birlikte geçiş matrisinin anlamsal yakınlık verdiği, MDS ile kelimelere koordinat atanabildiği ve bunun metin benzerliği gibi doğal dil işleme problemlerinde kullanıldığı gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
