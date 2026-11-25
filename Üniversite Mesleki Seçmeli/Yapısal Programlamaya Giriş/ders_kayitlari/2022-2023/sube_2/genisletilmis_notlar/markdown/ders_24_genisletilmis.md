# Ders 24 Genişletilmiş Notu: Şifreleme Algoritmaları (Sezar, Afin, Matris ve Yer Değiştirme Şifreleri), scanf Girdi Tamponu ve Bağlı Listelere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Şifreleme ve kriptolojiye giriş
- 2. Sezar şifresi
- 3. Afin şifreleme ve modüler ters
- 4. Matris ile şifreleme ve frekans analizi
- 5. Kelime şifreleme: tam kare matrisle yer değiştirme
- 6. Parolaların saklanması
- 7. scanf ile boşluklu metin okuma ve girdi tamponu
- 8. Diziler ve sınırları
- 9. Bağlı listelere giriş
- 10. Dizilerle bağlı liste: A[] ve PO[] dizileri
- 11. struct ve işaretçilerle bağlı liste
- 12. Dairesel ve çift yönlü bağlı listeler
- Örnek Sorular
- Dersin Toparlaması

Ders, daha önce işlenen algoritmik araçların (döngüler, koşullar, diziler, matrisler, fonksiyonlar) gerçek bir uygulama alanındaki karşılığını göstermek için şifreleme örnekleriyle başladı. Aradan sonra `scanf` ile ilgili iki pratik sorun ele alındı, ardından bağlı listelere giriş yapıldı. Hoca anlatımı bir çizim tahtası, hazır PDF ders notları ve Dev-C++ ile yazılmış örnek programlar üzerinden yürüttü.

## 1. Şifreleme ve kriptolojiye giriş

Bir şeyi şifrelemenin ilk nedeni güvenliktir. Bu işin bilimine kriptoloji denir ve iki kola ayrılır: kriptografi bir metni ya da veriyi şifrelemeyi, kriptanaliz ise şifrelenmiş bir veriyi çözmeyi inceler. Hoca bu ikisinin ayrı bilim dalları gibi düşünülebileceğini söyledi.

Şifreleme, kodlamaya (encoding) benzer ama amacı farklıdır. Kodlamada amaç büyük bir veriyi daha az sayıda sembolle temsil etmektir; şifrelemede amaç veriyi başkalarının okuyamayacağı hale getirmektir. İkisinde de bir veri bir fonksiyondan geçirilir ve başka bir veri elde edilir (ekrandan, 00:10:00):

$$\text{Data}_1 \xrightarrow{\;f\;} \text{Data}_2$$

Orijinal veriye geri dönebilmek için bu fonksiyonun tersi alınabilir olmalıdır. Hoca derste bütün şifreleme algoritmalarını anlatmanın amaçlanmadığını, yalnız derste öğrenilen algoritmik yapıların burada nasıl karşılık bulduğunu göstermek istediğini belirtti; bu konular bölümde ayrı derslerde ayrıntılı işlenir.

### 1.1 Özel anahtar ve açık anahtar

Kitaplarda iki taraf genelde Alice ve Bob diye anılır.

- **Özel anahtar (private key):** Alice ile Bob arasında bir anahtar vardır ve bu anahtarı yalnız ikisi bilir. Alice mesajını bu anahtarla şifreler, Bob aynı anahtarla açar; tersi de geçerlidir. Anahtar kimsede yoksa güvenli görünür ama bu yöntemin birçok sıkıntısı vardır.
- **Açık anahtar (public key):** Anahtar herkese açıktır, ortadadır. Şifreli mesajlar gidip gelir, ama Alice ve Bob dışında kimse mesajı çözemez; anahtarın varlığı çözmeye yetmez. Bunun için taraflar bu ortak anahtardan ($K_1$) kendi anahtarlarını üreten bir protokol uygular; bunun için birçok algoritma geliştirilmiştir.

Derste yalnız özel anahtarlı basit yöntemler işlendi.

## 2. Sezar şifresi

En eski bilinen yöntem Sezar (Caesar) şifresidir. Bir metin, örneğin `M: ABC`, şu fonksiyondan geçirilir (ekrandan, 00:10:00):

$$f(x_i) = x_i + c_1$$

Burada $x_i$ her karakterin sayısal karşılığıdır, $c_1$ bir sabittir (hoca harf `C` ile karışmasın diye $c_1$ yazdı). Anahtar $c_1$'dir: Alice ve Bob'un bilmesi gereken bilgi budur.

İngilizce alfabedeki 26 büyük harf üzerinden gidilir (Ç, Ş, Ü gibi harfler yoktur); işlem ASCII tablosundaki büyük harfler üzerinde düşünülebilir. Toplama mod 26'da yapılır, yani sonuç 0-25 aralığında kalır.

**Örnek ($c_1 = 2$):**

- `A` → `C`, `B` → `D`, `C` → `E`; yani `ABC` → `CDE`.
- `Z` gönderilirse iki karakter sonrası başa sarar: `Z` → `B`.

**Çözme:** Fonksiyonun tersi alınır: $f^{-1}(x_i) = (x_i - c_1) \bmod 26$. Mod 26'da çalışıldığı unutulmamalıdır. `B` çözülürken `B`'nin sırası 1'dir: $1 - 2 = -1$. $-1$ diye bir karakter olmadığı için 26 eklenir: $-1 + 26 = 25$, bu da `Z`'dir. Böylece `B`'nin karşılığı yine `Z` bulunur.

Kod yazılırsa kullanıcıdan büyük harflerden oluşan bir string ve bir $c$ sayısı alınır; şifrelerken her karaktere $c$ eklenir, çözerken çıkarılır.

### 2.1 Daha geniş karakter kümesi

Yalnız büyük harfle çalışmanın sorunu, Türkçe harflerin, küçük harflerin, rakamların ve noktalama işaretlerinin olmamasıdır. Bunlar da işin içine katılmak istenirse kendi karakter dizinizi tanımlayabilirsiniz. Hoca kabaca şöyle saydı: 29 büyük harf, 29 küçük harf (58), 10 rakam (68), 10 noktalama işareti (78). 78 elemanlı bir `char` dizisi oluşturulup doldurulur ve mod 78'de çalışılır.

Bu durumda ASCII koduyla toplama yapılmaz; karakterin bu dizideki indisi kullanılır. Dizi Türkçe alfabeyle doldurulursa (`A, B, C, Ç, D, …`) `C` 2. indistedir; anahtar 2 ise $2 + 2 = 4$. indisteki `D` şifreli karakter olur. Basit bir algoritmadır ve ortada tek bir anahtar vardır.

## 3. Afin şifreleme ve modüler ters

Sezar fonksiyonu biraz zorlaştırılır: $x$'in önüne bir $a$ katsayısı eklenir (ekrandan, 00:15:00 ve 00:30:00):

$$f(x_i) = (a\,x_i + c) \bmod 26$$

Artık iki anahtar vardır: kullanıcıdan alınan $a$ ve $c$. Hoca bu fonksiyonun bir doğru denklemine benzediğini, ama sabit terim yüzünden doğrusal değil "afin" fonksiyon sayıldığını, bu yönteme de afin şifreleme (affine cipher) dendiğini belirtti.

### 3.1 Ters fonksiyon

Hoca sınıfa $ax + c$'nin tersini sordu.

**Soru:** $ax + c$ fonksiyonunun tersi nedir? **Cevap:** $y = ax + c$ yazılır, $x$ ile $y$ yer değiştirilir: $a y + c = x$. $y$ yalnız bırakılır: $y = \dfrac{x - c}{a}$. Yani $f^{-1}(x) = \dfrac{x - c}{a}$.

Mod 26'da bölme doğrudan yapılamaz, çünkü rasyonel bir sayı çıkar. Bu yüzden bölme, $a$'nın tersiyle çarpma olarak yazılır (ekrandan, 00:30:00):

$$f^{-1}(x_i) = \left[a^{-1}\,(x_i - c)\right] \bmod 26, \qquad \alpha = a^{-1} \bmod 26$$

Önce $x$'ten $c$ çıkarılır, sonra $a^{-1}$ ile çarpılır, en son mod 26 alınır.

### 3.2 Bir sayının mod 26'daki tersi

$a^{-1}$, $a$'nın mod 26'da çarpmaya göre tersidir: $a \cdot a^{-1} \equiv 1 \pmod{26}$. Mod 26'da olası değerler 0'dan 25'e kadardır. $a$ bu değerlerden hangisiyle çarpılınca mod 26'da 1 veriyorsa ters odur. Bir sayının en fazla bir tersi vardır; hiç olmayabilir de.

> **Hocanın vurgusu:** Her fonksiyonun tersi olmaz. Mod 26'da tersi olmayan bir $a$ ile şifreleme yaparsanız mesajı geri çeviremezsiniz. Önce $a$'nın tersinin olup olmadığına bakılmalıdır.

**2 için deneme** (ekrandan, 00:20:00): $2 \cdot 0 = 0$, $2 \cdot 1 = 2$, $2 \cdot 2 = 4$, $2 \cdot 3 = 6$, …, $2 \cdot 12 = 24$, $2 \cdot 13 = 26 \equiv 0$, $2 \cdot 14 = 28 \equiv 2$ … Sonuçlar 0, 2, 4, 6, 8, … diye yalnız çift sayılar arasında döner ve hiç 1'e ulaşmaz. Demek ki 2'nin mod 26'da tersi yoktur; 2 bu yöntemde anahtar olamaz.

**3 için deneme** (ekrandan, 00:30:00): $3 \cdot 0 = 0$, $3 \cdot 1 = 3$, $3 \cdot 2 = 6$, $3 \cdot 3 = 9$, $3 \cdot 4 = 12$, $3 \cdot 5 = 15$, $3 \cdot 6 = 18$, $3 \cdot 7 = 21$, $3 \cdot 8 = 24$, $3 \cdot 9 = 27 \equiv 1$. Demek ki $3^{-1} = 9$; 3 kullanılabilir. Çözen taraf $c$'yi çıkardıktan sonra 9 ile çarpar.

$c$ için kısıt yoktur, çünkü mod 26'da toplamanın tersi her sayı için vardır: 3 eklenirse 3, 5 eklenirse 5 çıkarılır. Hoca örnekte $a = 3$, $c = 8$ seçti; çözerken önce 8 çıkarılır, sonra 9 ile çarpılır.

Karakter kümesi 78 elemanlıysa bu kez mod 78'de tersi olan bir $a$ aranır.

> **Ders sonrası not:** Hoca deneme sırasında 5 için "5 kere 5, 25" diyerek bir an 5'i örnek almayı düşündü, sonra 3'e geçti. 5'in mod 26'da tersi de vardır: $5 \cdot 21 = 105 = 4 \cdot 26 + 1$, yani $5^{-1} = 21$ (python ile kontrol edildi).

> **Ek bilgi (derste anlatılmadı):** Bir $a$ sayısının mod $m$'de çarpmaya göre tersi ancak ve ancak $\gcd(a, m) = 1$ ise vardır. 26 = 2·13 olduğundan çift sayıların ve 13'ün tersi yoktur. Tersi olan değerler 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25'tir (python ile kontrol edildi).

### 3.3 Afin şifrenin C kodu

Hoca kodu önceden yazmıştı ve satır satır açıkladı. Ekranda görülen ana kısım şudur (ekrandan, 00:25:00):

```c
do{
    printf("a Degeri:"); scanf("%d",&a);
    inva=inverseA(a);
} while(inva==-1);

printf("A nin tersi:%d\n",inva);
printf("B Degeri:"); scanf("%d",&b);

printf("Buyuk harflerle Metin giriniz: Orn ABC");
scanf("%s",metin);
printf("Girilen Metin: %s\n",metin);
while(metin[++uzunluk]!='\0'){  }
printf("Uzunluk: %d\n",uzunluk);

for(i=0;i<uzunluk;++i){
    x=metin[i];
    y= ((a*(x- 65)+ b ) % 26)+'A';
    cipherText[i]=y;
}
cipherText[i]='\0';
```

Açıklamalar:

- `inverseA` fonksiyonu önce tersi $-1$ (yok) kabul eder, sonra 0'dan 26'ya kadar her $i$ için `a*i % 26`'nın 1 olup olmadığına bakar. Döngü bitince ya tersi bulunur ya da $-1$ kalır. $-1$ dönerse kullanıcıdan yeni bir $a$ istenir.
- `while(metin[++uzunluk]!='\0'){ }` tek satırda `strlen` işini görür: karakter `\0` değilse uzunluk artar.
- Şifrelemede ASCII değerinden 65 (`'A'`) çıkarılır; böylece `A` 0, `B` 1 olur ve 0-25 aralığında çalışılır. Sonuç $a$ ile çarpılır, $b$ eklenir, mod 26 alınır ve `'A'` eklenerek şifreli karakterin ASCII kodu bulunur. Döngü bitince şifreli metnin sonuna `\0` eklenir.
- Çözmede önce 65, sonra $b$ çıkarılır, $a^{-1}$ ile çarpılır, mod 26 alınır ve `'A'` eklenir. En son çözülen metne `\0` eklenir.

**Demo:** $a$ için 2 ve 4 girildiğinde tersi olmadığı için yeniden soruldu; 3 girilince tersi 9 bulundu. $b = 3$ ile fonksiyon $3x + 3$ olur.

- `A` (0): $3 \cdot 0 + 3 = 3$ → `D`
- `B` (1): $3 \cdot 1 + 3 = 6$ → `G`
- `C` (2): $3 \cdot 2 + 3 = 9$ → `J`
- `D` (3): $3 \cdot 3 + 3 = 12$ → `M`

`ABCD` → `DGJM`, çözünce yine `ABCD` bulundu.

> **Ders sonrası not:** Hoca demo sırasında "3 kere 9, 25" dedi; doğrusu $3 \cdot 9 = 27$, mod 26'da 1'dir.

> **Ders sonrası not:** C'de `%` işlecinin sonucu, bölünen negatifse negatiftir (`-27 % 26 == -1`). Çözme adımında $x - 65 - b$ negatif olabilir; örneğin $b = 3$ iken `A`'ya şifrelenmiş bir karakter (`Z`) çözülürken $9 \cdot (0 - 3) = -27$ ve `-27 % 26 = -1` çıkar, karakter bozulur. Derste girilen `ABCD` örneğinde bu durum oluşmadı. Doğru çalışması için mod sonucu negatifse 26 eklenmelidir. Bu düzeltmeyle yazılan tam program `gcc -Wall` ile derlendi: `ABCD` → `DGJM` → `ABCD` ve `AZ` → `DA` → `AZ`. Çözme satırı derste ekranda tam görülmedi; düzeltme ajan tarafından eklendi.

```c
for (i = 0; i < uzunluk; ++i) {
    x = cipherText[i];
    y = (inva * ((x - 65) - b)) % 26;
    if (y < 0) y += 26;      /* negatif kalanı düzelt */
    clearText[i] = y + 'A';
}
clearText[i] = '\0';
```

> **Ders sonrası not:** `while(metin[++uzunluk]!='\0')` ön artırma kullandığı için ilk bakılan indis 1'dir. Boş string girilirse `metin[1]` okunur; bu değer başlatılmamışsa tanımsız davranıştır. `%s` boş string okumadığı için derste sorun çıkmaz.

## 4. Matris ile şifreleme ve frekans analizi

Bu kez 26 harf bir matrise yerleştirilir; sıralı da, karışık da yerleştirilebilir (ekrandan, 00:35:00). Hoca önce 6×6, sonra 6×5 düşündü; 30 hücreye 26 harf girer, kalan hücreler $-1$ ya da boş olur.

Şifrelerken her harfin yerine matristeki satır ve sütun numarası gönderilir. Örneğin `A` 1. satır 3. sütundaysa `13`, `B` 3. satır 5. sütundaysa `35` gönderilir. `ABC` → `13 35 …`. Anahtar artık bu matristir; iki tarafta da bulunmalı ve ortalığa paylaşılmamalıdır. Karşı taraf `13`'ü görünce matriste 1. satır 3. sütuna bakar ve `A` olduğunu anlar. Sayı tek bir tamsayı olarak tutuluyorsa satır ve sütun bölme ve kalan işlemleriyle ayrılabilir.

### 4.1 Frekans analizi saldırısı

Bu yöntemin sıkıntısı, her harfin tek bir karşılığının olmasıdır. Metin çok uzun olsun, örneğin bir kitap kadar. Şifreli metindeki sembollerin (13'lerin, 35'lerin, 48'lerin…) kaç kez geçtiği sayılıp histogramı çıkarılır. Metnin dilinin harf sıklığı histogramı da bilinir; bunun istatistiksel çalışmaları vardır.

**Soru:** Türkçede en çok kullanılan harf hangisidir? **Cevap:** Türkçede en çok `A`, İngilizcede en çok `E` kullanılır.

Metin yeterince uzunsa şifreli metnin histogramı dilin histogramına benzer. Saldırgan en sık geçen sembolün yerine `A`'yı, ikinciye bir sonraki en sık harfi yerleştirir; yerleştirdikçe kelimeler ortaya çıkar. Anahtarı bilmeden metin büyük oranda çözülebilir. Aynı saldırı Sezar ve afin şifreler için de geçerlidir: fonksiyon bilinmese bile frekanslara bakılarak çözülebilir.

### 4.2 Çözüm: sık harfleri çok hücreye dağıtmak

Matris büyütülür ve `A` gibi sık geçen harfler birden fazla hücreye yerleştirilir. Bir `A` için 13, ileride başka bir `A` için 10, bir başkası için 28 gönderilir. Matris iki tarafta da olduğu için karşı taraf hepsini `A` diye okur. Dışarıdaki biri ise her sembolü ayrı sayar; `A`'nın sıklığı birkaç sembole bölündüğü için şifreli metnin histogramı dil histogramıyla eşleşmez.

78 karakterlik bir küme ve en sık kullanılan, örneğin 30 karakter için bu karakterleri matriste beşer altışar kez tekrarlamak gerekir. Amaç, şifreli metnin histogramının düzgün (uniform) dağılıma yakın çıkmasıdır.

> **Ek bilgi (derste anlatılmadı):** Bir harfin birden çok sembolle temsil edildiği bu tür şifrelere literatürde "homofonik yerine koyma şifresi" (homophonic substitution) denir.

## 5. Kelime şifreleme: tam kare matrisle yer değiştirme

Kullanıcıdan bir mesaj alınır, uzunluğu bulunur ve karakterler bu uzunluktan büyük en yakın tam karelik bir matrise yerleştirilir. 29 karakter için 36'lık (6×6), 24 karakter için 25'lik (5×5) matris kullanılır. Karakterler matrise rastgele değil, belli bir düzende yazılır ve başka bir düzende okunur.

**Örnek: MERHABA** (ekrandan, 00:40:00). 7 karakter vardır, en yakın büyük tam kare 9'dur; 3×3 matris kullanılır. Matris satır satır doldurulur:

| | 0 | 1 | 2 |
|---|---|---|---|
| 0 | M | E | R |
| 1 | H | A | B |
| 2 | A | (boş) | (boş) |

Sonra sütun sütun okunur, boş hücreler atlanır: `M H A`, `E A`, `R B` → şifreli metin `MHAEARB`.

Karşı tarafa yalnız bu metin gönderilir ve matrisin hangi düzende doldurulduğu söylenir. Çözen taraf önce kaç karakter olduğuna (7) ve matrisin boyutuna (9) bakar; matrisin sonundan geriye doğru $9 - 7 = 2$ hücreyi boş işaretler. Sonra şifreli metni okuma düzeniyle (sütun sütun) boş olmayan hücrelere yerleştirir: `M H A`, `E A`, `R B`. En son yazma düzeniyle (satır satır) okur ve `MERHABA` bulunur. Matris sütun sütun doldurulup satır satır okunursa da aynı mantık işler.

### 5.1 Kod

Ekranda görülen fonksiyonlar (ekrandan, 00:45:00 ve 00:50:00):

```c
    while (i * i <= length)   // 1 den n e kadar tam kare arama islemi
        i++;                  // Tam kare degilse 1 artirilir
    return i;
}
void sifrele(char clearText[50],char cipherText[50],int length, int n)
{
    char matris[50][50];
    int i,j,say=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(say!=length)
                matris[j][i]=clearText[say++];
            else
                matris[j][i]='\0';
        }
    }
    say=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matris[i][j]!='\0')
                cipherText[say++]=matris[i][j];
        }
    }
    ...
```

- `matris[j][i]` ile yazmak, iç döngü `j` olduğu için sütun sütun doldurmak demektir; `matris[i][j]` ile okumak satır satır okumaktır. Sonuç, yukarıdaki satır satır yazıp sütun sütun okuma ile aynı şifreli metni verir.
- 50×50'lik büyük bir matris tanımlanır, yalnız $n \times n$'lik kısmı kullanılır.
- Hoca "en yakın tam kare", "metnin uzunluğu" gibi alt işlerin basit algoritmalar olduğunu, fonksiyonlara ayrıldığını söyledi.

Çözme fonksiyonu daha ayrıntılıdır (ekrandan, 00:50:00): önce boş hücreler tespit edilir. $n^2$ hücrenin $n^2 - \text{length}$ tanesi boştur. Dolu olacak hücrelere yer tutucu olarak `'0'` karakteri, boş hücrelere `'\0'` yazılır. Hoca `'0'` ile `'\0'`'ın farklı şeyler olduğunu vurguladı; yer tutucu olarak $-1$ gibi başka bir değer de seçilebilir. Sonra:

```c
say=0;
for(i=0;i<n;i++){  // bos olmayan yerlere sifreli metnin kopyalanmasi
    for(j=0;j<n;j++){
        if(matris[i][j]!='\0')
            matris[i][j]=text[say++];
    }
}
say=0;
for(i=0;i<n;i++) // sifreli metnin cozulmesi
{
    for(j=0;j<n;j++)
    {
        if(matris[j][i]!='\0')
            clearText[say++]=matris[j][i];
    }
}
```

Önce boş olmayan hücrelere şifreli metin satır satır yazılır, sonra matris sütun sütun okunarak açık metin bulunur.

> **Ders sonrası not:** Ekrandaki `tamKare` döngüsü `while (i*i <= length) i++;` karesi uzunluğu aşan ilk sayıyı döndürür. Uzunluk tam kareyse (ör. 9 karakter) 3×3 yerine 4×4 seçilir; boş hücreler atlandığı için yöntem yine doğru çalışır. Hocanın kodunun boş hücre işaretleyen kısmı ekranda tam görülmedi; ekrandaki parçalara göre yazılan tam program `gcc -Wall` ile derlendi ve `MERHABA` → `MHAEARB` → `MERHABA`, 9 karakterlik bir metin için de doğru sonuç verdi.

Demoda hoca kodda bir sınır olduğunu, ilk denemede en fazla 9 karakter (3×3) desteklendiğini, sınırı 6 yapınca 36 karaktere kadar çalışacağını söyledi. "Bilgisayar Mühendisliği" girildi; boşluklu metin olduğu için okuma satırında özel bir biçim kullanıldı (bkz. Bölüm 7). 22-23 karakterlik metin 5×5 matrise yerleşti ve şifrelenip yeniden çözüldü.

Bu yöntemde her harf yerinde kalmaz, ama yine de çok uzun bir metinde harf sıklıkları değişmediği için histogram eşleştirmesiyle çözülebilir. Hoca bütün bu örneklerin döngü, koşul, matris ve fonksiyonlarla yazılmış tamamen algoritmik işlemler olduğunu vurguladı. Günümüzdeki ayrıntılı algoritmalar (blockchain'in kullandığı eliptik eğri yöntemleri, RSA, AES, DES gibi) da sonuçta kodlanmış algoritmalardır.

## 6. Parolaların saklanması

**Soru:** Bir sitede "şifremi unuttum" dediğinizde sistem ne yapar? **Cevap:** Parolayı sıfırlatır. Çünkü parolalar açık metin olarak tutulmaz; özetleme (hash) fonksiyonlarından geçirilerek saklanır. Bu fonksiyonun tersini almak çok zor olduğu için sistem parolayı hatırlatamaz, yeni bir parola oluşturmanızı ister.

Bazı eski ya da kalitesiz siteler parolayı veritabanında açık metin olarak tutar ve unutulduğunda doğrudan e-postayla gönderir. Bu tür sitelerde güvenlik yoktur.

> **Hocanın vurgusu:** E-Devlet, OBS gibi önemli sistemlerdeki parolalarınızı başka sitelerde kullanmayın.

## 7. scanf ile boşluklu metin okuma ve girdi tamponu

### 7.1 Boşluklu string okuma

`scanf("%s", ad)` ile `yildiz teknik` girildiğinde yalnız `yildiz` alınır ve uzunluk 6 bulunur (ekrandan, 01:05:00). Bunun nedeni `%s`'nin beyaz boşlukta (whitespace) okumayı bitirmesidir.

> **Ders sonrası not:** Hoca boşluğun `\0` gibi algılandığını söyledi. Daha doğrusu: `%s` beyaz boşluk görünce okumayı durdurur, okuduğu kısmın sonuna kendisi `\0` ekler; kalan karakterler (` teknik`) girdi tamponunda bekler.

Satırın tamamını okumak için tarama kümesi (scanset) biçimi kullanılır: `scanf("%[^\n]", ad)`. Satır Enter ile biter ve Enter `\n` karakteridir; `%[^\n]` "`\n` görene kadar ki karakterleri al" demektir. `^` burada "değil" anlamındadır. Örneğin `%[^e]` ilk `e` harfine kadar okur: `yildiz teknik` girilince `yildiz t` alınır; 6 harf, bir boşluk ve `t` ile uzunluk 8'dir. Hoca satır okumak gerektiğinde `%[^\n]` kullanılmasını önerdi.

**Soru:** Bu şekilde okunan metni sonra yazdırırken de özel bir işlem gerekir mi? **Cevap:** Hayır; metin boşluklarıyla birlikte kaydedildiği için `printf` ile yazdırırken sorun olmaz.

Dizi adı (etiketi) işaretçi gibi davrandığı için string okurken `&` yazılmaz. Sıradan değişkenlerde `&` zorunludur.

### 7.2 String uzunluğu

`while` ve `if` koşullarında 0 yanlış (false), 0'dan farklı her değer doğru (true) sayılır; `true`/`false` ya da 0/1 ile ayrıca karşılaştırmak gerekmez. String uzunluğu şöyle bulunur:

```c
int y = 0;
while (ad[y++]);
y--;
```

Döngü `\0` karakterine gelene kadar her adımda `y`'yi artırır. `\0` 0 olduğu için döngüden çıkılır, ama son kontrolde `y` bir kez daha arttığı için bir azaltılır. Demoda kodda iki kez azaltma kaldığı için 13 karakterlik metin 12 çıktı; ikinci azaltma silinince 13 bulundu. Hoca `y` ile birlikte ayrı bir `counter` değişkeni artırmanın gereksiz olduğunu, ikisinin hep eşit arttığını belirtti.

### 7.3 %c ve tamponda kalan Enter

Ekrandaki örnek (ekrandan, 01:10:00):

```c
printf("Enter an int");
scanf("%d",&y);   //65 enter
printf("Enter a char");
scanf("%c",&c);
```

`65` yazıp Enter'a basınca 65 `y`'ye alınır, ama Enter'ın `\n` karakteri tamponda kalır. Sonraki `scanf("%c", &c)` kullanıcıya karakter girme fırsatı vermeden bu `\n`'yi okur ve program bir sonraki satıra geçer. Demoda "Enter a char" yazısından sonra hiçbir şey girilemeden devam edildi.

**Soru:** 15-20 tane `scanf` olsa hepsi etkilenir mi? **Cevap:** Hayır. `%d` sayı bekler ve beyaz boşlukları atlar, bu yüzden bir `%d`'den sonraki `%d` etkilenmez. Etkilenen yalnız `%c`'dir, çünkü Enter bir karakterdir. Bir karakter okuyup Enter'a bastıktan sonra yine `%c` ile karakter okunacaksa o da etkilenir. Bir stringin karakterleri kullanıcıdan tek tek alınırken de aynı sorun yaşanır.

Test (ajan tarafından): `65⏎y⏎` girdisinde `scanf("%d")` 65'i, ardından `scanf("%c")` 10 değerini (`\n`) okur; `scanf(" %c")` ise `y` okur.

Hocanın gösterdiği iki çözüm:

1. `%c`'nin önüne boşluk koymak: `scanf(" %c", &c);`. Format dizisindeki boşluk, beyaz boşlukları atlar. Hoca bunu biraz "ilkel" bir yol olarak niteledi.
2. `scanf` öncesinde tamponu temizlemek: `fflush(stdin);`.

### 7.4 Standart akışlar

Hangi işletim sistemi ve programlama dili olursa olsun, çalışan programa bellekte yer verilir: veri bölümü (data segment), kod bölümü (code segment) ve dosya tanımlayıcıları (file descriptor) (ekrandan, 01:15:00). Her program üç standart tanımlayıcıyla başlar: `stdin`, `stdout`, `stderr`. Bunları programla dış dünya arasında üç kanal (tampon) gibi düşünün: girdi `stdin`'den gelir, normal çıktı `stdout`'a, hata çıktısı `stderr`'e gider. `printf` ve `scanf` aslında bu akışları kullanır; ileride görülecek dosya işlemleri de bunlarla ilişkilidir.

Klavyeden girilenler bir bayt akışı olarak tampona dolar: örneğin `A`, Enter, `65`, Enter. Sayı okunurken Enter beyaz boşluk olarak yok sayılır, ama `%c` onu karakter olarak alır.

> **Ders sonrası not:** Hoca tamponu temizlemenin "esas" yolunun `fflush(stdin)` olduğunu söyledi ve `fflush(stdout)` da kullanılabileceğini belirtti. C standardında `fflush` yalnız çıktı akışları için tanımlıdır; `fflush(stdin)` tanımsız davranıştır. Derste kullanılan Windows ortamında çalışır, ama Linux/glibc gibi ortamlarda güvenilir değildir. Taşınabilir çözüm `" %c"` ya da satır sonuna kadar okuyup atan `int ch; while ((ch = getchar()) != '\n' && ch != EOF);` döngüsüdür.

## 8. Diziler ve sınırları

Hoca bağlı listelerin dersin tam konusu olmadığını, ama bazı yerlerde gerekeceği için teorik bir giriş yapacağını söyledi. Konu bellekle ilgilidir.

5 elemanlı bir dizi oluşturulduğunda elemanlar bellekte ardışık bulunur (ekrandan, 01:25:00). 2×2'lik bir matriste önce birinci satır, hemen ardından ikinci satır gelir. Üç boyutlu bir dizide ($A \times B \times C$) $C$ tane $A \times B$ matris arka arkaya dizilir: birinci matrisin satırları, sonra ikinci matrisin satırları. Bunlara geleneksel dizi (array) denir.

Bu yapının güzel yanı, `d[2][3]` gibi bir elemana arka planda yapılan adres hesabıyla doğrudan erişilebilmesidir; döngülerde `d[i][j]` hesaplanıp değerler kolayca değiştirilebilir.

**Soru:** Dizinin üçüncü elemanına erişmenin karmaşıklığı nedir: $O(n)$ mi, $O(\log n)$ mi, $O(1)$ mi? **Cevap:** $O(1)$. Başlangıç adresine işaretçi aritmetiğiyle 3 eklenir (`d + 3`) ve tek işlemde ulaşılır.

### 8.1 Boyut sorunu

Dizilerde boyut genelde `#define N 10` ile sabitlenir. Program çalışırken boyut belirlemek de mümkündür: kullanıcıdan `N` alınıp `malloc` ile `N` elemanlık yer istenir, sonra yine `dizi[i]` ile kullanılır. `malloc` işletim sisteminden özel izin ister; yer verilirse kullanılır. Hoca bunun gelecek dönem görüleceğini, bu sorunun üstesinden gelmenin zor olmadığını söyledi.

### 8.2 Sıralı diziye ekleme ve silme

Sıralı bir dizi olsun: `2, 5, 8, 10, 17, 27, …` ve araya 1 eklenecek, sıra bozulmayacak (ekrandan, 01:25:00).

**Soru:** Sırayı bozmadan eleman eklemek için nasıl bir algoritma gerekir? **Cevap (bir öğrenci):** Eklenecek elemandan büyük olanların hepsi sağa kaydırılır, açılan yere eleman yazılır.

1. **Birinci yaklaşım:** Elemanı son boş hücreye ekle, sonra diziyi yeniden sırala (re-sort). Hoca bunun maliyetini $N^2$ olarak verdi; iyi bir yaklaşım değildir.
2. **İkinci yaklaşım:** Önce baştan itibaren eklenecek elemandan büyük ilk eleman aranarak yer bulunur ($N$ arama), sonra o yerden sonraki elemanlar kaydırılır ($N$ kaydırma). Toplam yaklaşık $2N$'dir.

Kaydırma sondan başlamalıdır. Bulunan yerden başlanırsa 2, 5'in üzerine yazılır ve bütün elemanlar 2 olur. Bu yüzden önce 27 bir sağa, sonra 17, sonra diğerleri kaydırılır; en son açılan yere 1 yazılır: `1, 2, 5, 8, 10, 17, 27`.

Bu tek eleman eklemek içindir. $N$ eleman daha eklenecekse (örneğin sınıfa 20 öğrenci gelmiş, sonra 20 öğrenci daha gelmiş ve öğrenci numarasına göre sıralı tutulacak) maliyet $N \cdot 2N$, yani yine $O(N^2)$ olur. Silmede de durum aynıdır: önce silinecek elemanın yeri bulunur ($N$), sonra boşluk kalmasın diye sonraki elemanlar sola kaydırılır ($N$); $N$ silme $O(N^2)$ tutar.

> **Ders sonrası not:** Hoca yeniden sıralamanın maliyetini $N^2$ olarak verdi; bu basit sıralama algoritmaları (seçme, kabarcık) için geçerlidir. Büyük olasılıkla birleştirmeli sıralama gibi verimli algoritmalarla $O(N \log N)$'dir; yine de tek eleman için ikinci yaklaşımın $O(N)$ maliyetinden kötüdür.

### 8.3 Bitişik bellek sorunu

**Soru:** Dizilerin bellekte bitişik olmasına ne denir? **Cevap:** İngilizcesi *contiguous*. Hoca *continuous* kelimesinin zamanda süreklilik anlamına geldiğini, burada ise mekansal bir bitişiklik söz konusu olduğunu belirtti.

Çok büyük bir yer istendiğinde (örneğin bir milyar eleman) bellekte toplamda o kadar boş yer olsa bile bitişik olarak bulunmayabilir. Bellek bir yaz-boz tahtası gibidir; süreçler gelir gider. İşletim sistemi bitişik yer açmak için diğer süreçlere "şuraya kay" diyemez; bunu yaparsa diğer süreçler donabilir. Herkes oturduğu yerde oturur ve yer ayrılamadığı için hata alınır. Bitişik olmayan boş yerlerden yararlanabilmek gerekir.

## 9. Bağlı listelere giriş

Bu iki soruna (kaydırma maliyeti ve bitişik bellek) çözüm bağlı listelerdir (linked list). Özellikleri (ekrandan, 01:35:00):

- **Bitişik olması gerekmez (non-contiguous):** İstenen kadar yer alma olasılığı artar.
- **Uzunluk dinamiktir (dynamic length):** Bu özellik `malloc` ile dizilerde de sağlanabilir.
- **Kaydırma gerekmez (shift operation is unnecessary):** Araya eklenecek ya da aradan silinecek eleman kaydırma yapmadan bağlanır ya da çıkarılır.
- **Fazladan bellek gerekir (needs extra memory):** Her elemanın yanında bir adres saklanır.

İlk üçü avantaj, sonuncusu bedeldir. Hoca bunu bir trade-off olarak niteledi: zamandan kazanmak için bellekten kaybediliyor. Dizilerde de bir trade-off vardır: bitişiklik erişimi kolaylaştırır ama ekleme/silmeyi zorlaştırır.

### 9.1 Yapı

Her eleman bir veri alanı ve bir sonraki elemanın bellekteki adresini tutan bir adres alanından oluşur (ekrandan, 01:35:00):

```text
[A Data | &B] --> [B Data | &C] --> [C Data | null]
```

İkinci alan, "fazladan bellek" dediğimiz şeydir. Veri tamsayı olmak zorunda değildir, her türden olabilir.

### 9.2 Haber zinciri benzetmesi

Hoca sınıfı 100 kişilik ve e-postanın, telefonun olmadığı bir dünyada yaşıyor gibi düşünmeyi önerdi. Sözlü bir haber (örneğin "sınav saat üçte") herkese nasıl ulaştırılır?

**Soru:** Gönderilen bir haberi herkes nasıl alabilir? **Cevap (bir öğrenci):** Ben birine söylerim, o bir diğerine, o da bir diğerine.

Bir protokol belirlenir: hoca mesajını yalnız bir öğrenciye gönderir. O öğrenci kimden mesaj alacağını ve kime ileteceğini bilir; her öğrenci bir sonrakine iletir. Son öğrenci kimseye iletmez (adres alanı null). Son öğrenci mesajı hocaya geri iletirse sistem kontrol edilmiş olur ve yapı dairesel hale gelir (son elemanın adres alanında ilk elemanın adresi tutulur). Son kişiye mesaj ulaştıysa arada kopukluk yok demektir. Bu yapı bir bağlı listedir.

### 9.3 Bellekte görselleştirme

N elemanlı tek yönlü bir bağlı liste şöyle görselleştirilebilir (adresler varsayımdır) (ekrandan, 01:40:00):

| Veri | 1 | 2 | 3 | 4 | 5 | 6 | … | N-2 | N-1 | N |
|---|---|---|---|---|---|---|---|---|---|---|
| Bellekteki adresi | 100 | 108 | 200 | 194 | 94 | 380 | … | … | 250 | 40 |
| Sonraki elemanın adresi | 108 | 200 | 194 | 94 | 380 | … | … | 250 | 40 | NULL |

1 verisi 100 numaralı adreste durur ve sonraki elemanın adresi olarak 108'i tutar. 2 verisi 108'dedir ve 200'ü tutar; 3 verisi 200'dedir ve 194'ü tutar… Son eleman NULL tutar. Adresler ardışık değildir: 100'den 108'e, 200'e, 194'e, 94'e, 380'e gidilir. Tamsayı dizisinde ise adresler 100, 104, 108, 112, … diye artardı.

**Soru:** Bütün listeyi gezmek için neyi bilmeliyiz? **Cevap:** İlk elemanı. Bu elemana head denir; örnekte head 100 adresini tutar.

**Soru:** Listenin sonuna geldiğimizi nasıl anlarız? **Cevap:** Adres alanında NULL (dizi gerçeklemesinde $-1$) görürüz. Adresler 0 ya da pozitif olduğu için $-1$ geçerli bir adres değildir.

**Soru:** n. elemana gitmek için baştan itibaren bütün elemanları gezmek gerekmiyor mu? Dizide n. elemana tek seferde ulaşılıyor. **Cevap:** Evet, doğrudan erişim isteniyorsa dizi daha hızlıdır. Ama sıralı ekleme probleminde dizide de üçüncü elemana doğrudan gidilmez; eklenecek yeri bulmak için 0., 1., 2. elemana sırayla (ya da ikili aramayla) bakılır. Yeri bulma maliyeti dizide de bağlı listede de vardır ve bundan kaçış yoktur. Bağlı liste yalnız kaydırma maliyetini ve bitişik bellek sorununu ortadan kaldırır.

**Soru:** Bu durumda hızdan da bir trade-off yok mu? **Cevap:** Trade-off hız ile bellek arasındadır. Hızdan bir kayıp vardır, ama bunu tamamen sıfırlamak RAM modelindeki bilgisayarlarda mümkün değildir.

Bağlı listeler iki yolla oluşturulabilir: dizilerle ve işaretçilerle.

## 10. Dizilerle bağlı liste: A[] ve PO[] dizileri

`malloc` henüz görülmediği için önce en ilkel yol, dizilerle bağlı liste gösterildi. İki dizi kullanılır (ekrandan, 01:45:00):

- `A[]`: elemanları geliş sırasıyla tutar (sıralı değildir).
- `PO[]`: her elemanın referans verdiği, yani kendinden sonra gelecek elemanın indisini tutar.

`A[]` dizisinin ilk elemanı (head) `PO[0]`'da tutulur. Sıfırıncı hücreler C'deki 0 indisiyle karışmasın diye bilerek boş bırakılır; elemanlar 1'den N'ye kadar yerleşir.

### 10.1 Tahtadaki örnek

Önce kavram tahtada gösterildi: liste 1, 2, 5, 7 iken 4 eklenecek. 2'den sonra 4, 4'ten sonra 5 gelmelidir. İki adım yapılır:

1. 2'nin gösterdiği adres (5'in adresi) 4'ün adres alanına kopyalanır.
2. 4'ün adresi 2'nin adres alanına yazılır.

5 hiç kaydırılmaz. En sona eklenen bir eleman (örneğin 8) eski son elemanın $-1$'ini alır, eski son eleman 8'i gösterir. Baştakinden küçük bir eleman (1) eklenirse head değişir: 1 eski head'i (2'yi) gösterir, head 1'i gösterir.

### 10.2 PDF'teki örnek

Elemanlar `2, 5, 4, 8, 1` sırasıyla girilmiştir (ekrandan, 02:00:00):

| i | A[] | PO[] |
|---|---|---|
| 0 | | 5 |
| 1 | 2 | 3 |
| 2 | 5 | 4 |
| 3 | 4 | 2 |
| 4 | 8 | -1 |
| 5 | 1 | 1 |

Okuma: en küçük eleman 1'dir ve 5. indistedir, bu yüzden `PO[0] = 5`. 1'den sonra 2 gelir; 2 1. indistedir, `PO[5] = 1`. 2'den sonra 4 gelir (3. indis), `PO[1] = 3`. 4'ten sonra 5 gelir (2. indis), `PO[3] = 2`. 5'ten sonra 8 gelir (4. indis), `PO[2] = 4`. 8'den sonra eleman yoktur, `PO[4] = -1`.

**Bu listeye 7 eklenirse:** 7, `A[6]`'ya yazılır. Baştan gezilir: `PO[0] = 5` → 1, 7'den büyük değil; `PO[5] = 1` → 2, değil; `PO[1] = 3` → 4, değil; `PO[3] = 2` → 5, değil; `PO[2] = 4` → 8, 7'den büyük. Demek ki 7, 5 ile 8 arasına girecek. Önce 5'in gösterdiği 4 indisi `PO[6]`'ya kopyalanır, sonra `PO[2]` 6 yapılır:

| i | A[] | PO[] |
|---|---|---|
| 0 | | 5 |
| 1 | 2 | 3 |
| 2 | 5 | **6** |
| 3 | 4 | 2 |
| 4 | 8 | -1 |
| 5 | 1 | 1 |
| 6 | **7** | **4** |

**Soru:** Bu algoritma yine $n$ olmadı mı? **Cevap:** Oldu, ama $2n$ olmadı; kaydırma ortadan kalktı. $n$ eleman eklenince elbette $n^2$ olur, ama $2n^2$'lik maliyetten kurtulunur. Bellek bitişikliği sorunu da çözülür.

Ardından 3 eklendi (7. indis). Baştan: 1 küçük, 2 küçük, 4 büyük. 3, 2 ile 4 arasına girer: 2'nin gösterdiği 3 indisi `PO[7]`'ye kopyalanır, `PO[1]` 7 yapılır. Hoca ilk denemede bağları karıştırdı, sonra düzeltti. Sıralı gezinti: `PO[0]` → 5 (1) → 1 (2) → 7 (3) → 3 (4) → 2 (5) → 6 (7) → 4 (8) → $-1$.

### 10.3 Ekleme kodu

Ana programın başı (ekrandan, 01:50:00):

```c
#include <stdio.h>
void elemanEkle (int*,int,int,int*);
void elemanSil (int*,int,int*);
void listeleriYazdir(int*,int*,int);
void siraliYazdir (int*,int*);
int main()
{
    int B[10]={0},A[10]={0},PO[10]={0},N,i,j,k,ek,sil;
    printf("eklenecek dizi eleman sayisi?\n");
    scanf("%d",&N);
    printf("elemanlar?\n");
    for (i=1;i<=N;i++)
        scanf("%d",&B[i]);
    PO[0]=1;
    A[1]=B[1];
    PO[1]=-1;
    for (i=2;i<=N;i++)
    {
        ek=B[i];
        elemanEkle (A,i,ek,PO);
    }

    listeleriYazdir(A,PO,N);

    printf("eklenecek eleman?\n");
    scanf("%d",&ek);
    elemanEkle (A,i,ek,PO);
    ...
```

`B` geçici dizidir; elemanlar karışık sırayla buraya okunur. Asıl önemli olanlar `A` ve `PO`'dur. Hazırlık adımında, bir dizinin en küçüğünü bulurken ilk elemanı en küçük kabul etmeye benzer şekilde, ilk eleman listenin tek elemanı yapılır: `PO[0] = 1` (head 1. indis), `A[1] = B[1]`, `PO[1] = -1` (ondan sonra eleman yok). Sonra 2. elemandan başlayarak her eleman `elemanEkle` ile eklenir.

`elemanEkle` fonksiyonu (ekrandan, 01:55:00):

```c
void elemanEkle (int A[],int i,int ek,int PO[])
{
    int k=0;        //ilgili elemana referans veren. Suan liste basini isaret ediyor
    int j;          //bir sonraki elemana gecebilmek icin
    A[i]=ek;        //yeni elemani A[] dizisinin i. indisine yaz
    j=PO[0];        //j liste basindaki elemanin indisini gostersin
    while ((j!=-1) && (A[j]<ek))  //listenin sonuna ulasmadigin ve siradaki eleman eklenecek elemandan kucuk oldugu surece
    {   //bir sonraki elemana gec ama oncekini de sakla
        k=j;        //bu elemana referans verenin indisi
        j=PO[j];    //bu elemanin referans verdiginin indisi
    }
    PO[k]=i;
    PO[i]=j;        //yeni elman siradaki elemana referans versin
}
```

`j` gezinme indisidir, `k` bir önceki elemanın indisidir. `k` 0'dan başladığı için, yeni eleman en küçükse döngüye hiç girilmez ve `PO[0] = i` olur; yani head otomatik güncellenir. Döngü listenin sonuna gelindiğinde ya da eklenecek elemandan büyük bir eleman bulunduğunda durur.

**Adım adım (B = 2, 5, 4, 8, 1)** (ekrandan, 01:55:00): Hazırlıkta `A[1] = 2`, `PO = [1, -1]`. 5 eklenir: `A[2] = 5`; `j = PO[0] = 1`, `A[1] = 2 < 5`, ilerle: `k = 1`, `j = PO[1] = -1`; döngü biter. `PO[1] = 2`, `PO[2] = -1`. 4 eklenir: `A[3] = 4`; `j = 1` (2 < 4), `k = 1`, `j = 2`; `A[2] = 5` 4'ten büyük, döngü biter. `PO[1] = 3`, `PO[3] = 2`. 8 ve 1 de aynı şekilde eklenir ve yukarıdaki tablo oluşur.

**Demo** (ekrandan, 02:05:00): eleman sayısı 5, elemanlar `1, 5, 9, 3, 4` girildi. Program çıktısı:

```text
i--A[]--PO[]
0   0   1
1   1   4
2   5   3
3   9   -1
4   3   5
5   4   2
```

Hoca bunun geçen yılın sınav sorularından biri olduğunu söyledi: `A` elemanları verilip `PO` elemanları soruluyor (bkz. Örnek Sorular).

### 10.4 Silme

Kavram (tahtada): Listeden bir eleman silinirken, silinecek elemandan önceki elemanın adres alanına silinecek elemanın adres alanındaki değer kopyalanır. Böylece önceki eleman doğrudan sonrakini gösterir ve aradaki bağ kopar. Sonra eleman bellekten temizlenir. Liste sıralı olmak zorunda değildir.

Sıralı listeden 4 silinecekse 4 baştan aranır: `PO[0] = 5` → 1, 4 değil; `PO[5] = 1` → 2, değil; `PO[1] = 7` → 3, değil; `PO[7] = 3` → 4 bulundu. 4'e 7. indisten gelindi; 4'ten sonra 2. indis (5) gelir. Önceki elemanın bağı `PO[7] = PO[3] = 2` yapılır. 4 hâlâ `A[3]`'te durur ve `PO[3]` hâlâ 2'yi gösterir, ama listeye hiçbir eleman onu göstermediği için devreden çıkmıştır. Daha temiz silmek için `PO[3]`'e $-2$ gibi bir değer ya da 0 yazılabilir; $-1$ yazmak sakıncalıdır, çünkü $-1$ son eleman anlamına gelir.

Silme fonksiyonu (ekrandan, 02:10:00):

```c
void elemanSil (int A[],int sil,int PO[])
{
    int k=0,j;
    j=PO[0];
    while ((j!=-1) && (A[j]!=sil))
    {
        k=j;
        j=PO[j];
    }
    if (j==-1)
    {
        printf("Silinecek eleman bulunamadi\n");
        return;
    }
    PO[k]=PO[j];   //bir önceki eleman bir sonrakini göstersin
    ...
```

Liste sonuna ($-1$) kadar gezilip eleman bulunamadıysa eleman yoktur. Bulunduysa bir önceki eleman bir sonrakini gösterir ve aradaki eleman devreden çıkar.

**Demo:** elemanlar `2, 6, 1, 4, 9`, sonra 3 eklendi, 4 silindi. Sonuç: head 3. indis (1); 1'den sonra 1. indis (2); 2'den sonra 6. indis (3); 3'ten sonra artık 4 yoktur, 2. indis (6); 6'dan sonra 5. indis (9); 9'dan sonra $-1$.

> **Ders sonrası not:** Ekrandaki `main`, `elemanEkle` ve `elemanSil` parçalarına göre yazılan tam program (`listeleriYazdir` ve `siraliYazdir` derste ekranda görülmedi, ajan tarafından eklendi; silinen hücreye $-2$ yazıldı) `gcc -Wall` ile derlendi. Üç örnek de derstekiyle aynı `PO` değerlerini verdi. Diziler 10 elemanlı olduğundan $N \ge 9$ girilip bir eleman daha eklenirse dizi sınırı aşılır; bu tanımsız davranıştır.

> **Hocanın vurgusu:** Sınavda silme sonrası `PO` dizisinin son hali sorulursa silinen elemanın karşılığında $-1$'den farklı negatif bir değer (ör. $-2$) görülebilir; bu silinmiş link demektir. Adımları baştan sona izlemek yeterlidir.

Dizilerle bağlı liste kurmak öğretici ama ideal değildir; diziler yine bitişik yapılardır. İdeal yol `struct` ve işaretçilerdir.

## 11. struct ve işaretçilerle bağlı liste

`struct` ayrıntılı olarak anlatılmadı, yalnız mantığı gösterildi. Yeni bir veri türü tanımlanır; bir kişinin yaşı, numarası, adı olabilir. Bir sonraki elemanın adresini tutmak için aynı türden bir işaretçi eklenir. Ekrandaki örnek (ekrandan, 02:15:00; örnek adlar genel adlarla değiştirildi):

```c
#include <stdio.h>
#include <string.h>
typedef struct Person{
    int age;
    int id;
    char name[50];
    struct Person * next;
    struct Person * prev;
}PERSON;

int main(){
    PERSON p,p2={25,444,"Ayse",NULL};
    p.age=5;
    p.id=333;
    strcpy(p.name,"Mehmet");
    p.next=NULL;
    PERSON *head;
    printf("%d >>> %d >>> %s\n",p.id,p.age,p.name);
    printf("%d >>> %d >>> %s\n",p2.id,p2.age,p2.name);

    p.next = &p2;

    head=&p;

    printf("\nYeni Durum\n%d >>> %d >>> %s\n",head->id,head->age,head->name);
    printf("%d >>> %d >>> %s\n",head->next->id,head->next->age,head->next->name);
}
```

Değişken tanımlanırken değerler alan sırasına göre küme parantezi içinde verilebilir (`p2`), ya da nokta işleciyle tek tek atanabilir (`p`). Bu program `gcc -Wall` ile derlendi; `333 >>> 5 >>> …` ve `444 >>> 25 >>> Ayse` satırlarını yazar.

### 11.1 Sayı tutan bağlı liste

Derste canlı yazılan örnek (ekrandan, 02:20:00 ve 02:25:00):

```c
#include <stdio.h>
#include <string.h>
typedef struct data{
    int sayi;
    struct data * next;
}DATA;

int main(){
   DATA d1, d2, d3, d4;
   DATA *head;
   d1.sayi=1;
   d2.sayi=2;
   d3.sayi=3;
   d4.sayi = 4;

   head = &d2;
   d2.next = &d1;  // head d2
   d1.next = &d4;
   d4.next = &d3;
   d3.next = NULL;

   while(head!=NULL){
    printf("%d",head->sayi);
    head = head->next;
   }
   ...
```

`d1`…`d4`'ü `int` değişkenler gibi düşünmek gerekir; tek fark `DATA` türünde olmalarıdır. `DATA *head` da `int *` gibi bir işaretçidir. Hoca önce `head`'i `DATA` türünde bir değişken gibi yazmaya başladı, sonra bunun böyle yazılmayacağını, `head`'in `d2`'nin adresini tutan bir işaretçi olması gerektiğini söyledi.

Bağlantı: head → d2 → d1 → d4 → d3 → NULL. Hoca `d1..d4` yerine bir `DATA` dizisi de açılabileceğini, ama o zaman yine bitişik bellek kullanılacağı için bunu tercih etmediğini belirtti.

Değişken üzerinden üyeye nokta işleciyle (`d1.sayi`), işaretçi üzerinden üyeye `->` işleciyle (`head->sayi`) erişilir.

**Soru:** Bu `while` döngüsüyle elemanlar ekrana hangi sırayla yazılır? **Cevap:** `head` NULL olmadığı sürece `head`'in gösterdiği sayı yazdırılır ve `head = head->next` ile bir sonrakine geçilir. Çıktı: `2143`.

**Soru:** 25. satırın sonunda, yani döngü bittiğinde `head` nereyi gösterir? **Cevap:** NULL'u. `head` sürekli `next` yapılarak güncellendi ve listenin başı kaybedildi. Zincir bozulmadı, yalnız başlangıç kayboldu. Bu yüzden ikinci aynı döngü hiçbir şey yazmaz; önce `head = &d2` ile başa dönmek gerekir.

## 12. Dairesel ve çift yönlü bağlı listeler

### 12.1 Dairesel liste

**Soru:** Listeyi bir tur yazdırıp yeniden ilk elemana gelmek istersek döngüyü nasıl değiştirmeliyiz? **Cevap:** Artık NULL kontrolü yapılmaz. Son elemanın `next`'i NULL yerine ilk elemanın adresi yapılır: `d3.next = &d2`. Böylece d2 → d1 → d4 → d3 → d2 diye bir daire oluşur. Bu yapıya dairesel bağlı liste (circular linked list) denir.

En az bir kez yazdırılacağı için `do-while` kullanılır ve koşul "`head` başlangıç elemanının adresinden farklı iken" olur. Hoca ilk denemede `head = head->next`'i yazdırmadan önce yaptığı için baştaki eleman eksik çıktı. Düzeltmesi: döngüye girmeden önce baştaki sayıyı bir kez yazdırmak, sonra döngüde önce bir sonrakine geçip yazdırmak, en son kontrol etmek. Derste son çıktı `2 1 4 3 2` oldu: başlangıçtan bir tur atılıp yeniden başa gelindi.

Derste ekranda tam görülmeyen bu son biçim, ajan tarafından şöyle yazılıp `gcc -Wall` ile derlendi; `21432` yazar:

```c
head = &d2;            /* listenin başına dön */
d3.next = &d2;         /* dairesel liste */
printf("%d", head->sayi);
do {
    head = head->next;
    printf("%d", head->sayi);
} while (head != &d2);
```

### 12.2 Çift yönlü liste

Bir sonraki eleman varsa bir önceki eleman da vardır. Listede hem ileri hem geri gidilmek isteniyorsa her eleman veriyle birlikte hem sonrakinin hem öncekinin adresini tutar. Buna çift yönlü bağlı liste (doubly linked list) denir.

Hocanın örneğinde 1 verisi 100, 2 verisi 108 numaralı adrestedir. 1'in sonraki adresi 108; 2'nin sonraki adresi 3'ün adresi; 3'ün önceki adresi 108; 2'nin önceki adresi 100'dür. Head'in öncesi ve son elemanın sonrası NULL'dur.

**Soru:** Bu liste dairesel yapılmak istenirse son elemanın sonrası ve ilk elemanın öncesi ne olur? **Cevap:** Son elemanın sonrası ilk elemanın adresi (100), ilk elemanın öncesi son elemanın adresi (örnekte 40) olur. Böylece çift yönlü dairesel bağlı liste elde edilir.

Kodda bunun için `Person` yapısındaki gibi ikinci bir işaretçi (`prev`) tutulur. Dizilerle yapılmak istenirse biri öncekiler, biri sonrakiler için iki ayrı indis dizisi tutulur. Hoca `prev` bağlantılarının kurulmasını sonraki derse bıraktı.

## Örnek Sorular

**1.** (derste sözlü, 00:16:07) $f(x) = ax + c$ fonksiyonunun tersi nedir?

> **Çözüm:** $y = ax + c$ yazılır, $x$ ve $y$ yer değiştirilir: $ay + c = x \Rightarrow y = (x - c)/a$. Mod 26'da bölme yerine $a^{-1}$ ile çarpılır: $f^{-1}(x) = [a^{-1}(x - c)] \bmod 26$.

**2.** (ekrandan, 00:20:00 ve 00:30:00) 2'nin ve 3'ün mod 26'da çarpmaya göre tersi var mıdır?

> **Çözüm:** $2k \bmod 26$ yalnız çift değerler alır ve 1'e ulaşmaz; 2'nin tersi yoktur. $3 \cdot 9 = 27 \equiv 1$; $3^{-1} = 9$.

**3.** (ekrandan, 00:10:00) Sezar şifresinde $c_1 = 2$ ise `ABC` ve `Z` neye dönüşür; şifreli `B` nasıl çözülür?

> **Çözüm:** `ABC` → `CDE`, `Z` → `B`. `B` (1) için $1 - 2 = -1$, $-1 + 26 = 25$ → `Z`.

**4.** (derste sözlü, 00:27:08) Afin şifrede $a = 3$, $b = 3$ ise `ABCD` neye şifrelenir?

> **Çözüm:** $3x + 3$: A(0) → 3 (D), B(1) → 6 (G), C(2) → 9 (J), D(3) → 12 (M). Sonuç `DGJM`.

**5.** (derste sözlü, 00:33:45) Türkçede en çok kullanılan harf hangisidir ve bu bilgi şifre çözmede nasıl kullanılır?

> **Çözüm:** Türkçede `A` (İngilizcede `E`). Uzun şifreli metnin sembol histogramı dilin harf histogramıyla eşleştirilerek anahtarsız çözüm yapılır.

**6.** (ekrandan, 00:40:00) `MERHABA` 3×3 matrise satır satır yazılıp sütun sütun okunursa şifreli metin nedir?

> **Çözüm:** Satırlar `MER`, `HAB`, `A__`; sütunlar `MHA`, `EA`, `RB` → `MHAEARB`.

**7.** (derste sözlü, 00:49:32) Bir sitede parolanızı unuttuğunuzda sistem size ne yaptırır, neden?

> **Çözüm:** Parolayı sıfırlatır; parolalar hash fonksiyonundan geçirilerek saklandığı için geri elde edilemez.

**8.** (ekrandan, 01:10:00) `scanf("%d",&y);` ile 65 girilip Enter'a basıldıktan sonra `scanf("%c",&c);` neden karakter beklemeden geçer?

> **Çözüm:** Enter'ın `\n` karakteri tamponda kalır ve `%c` onu okur. `" %c"` kullanılmalı ya da tampon temizlenmelidir.

**9.** (derste sözlü, 01:20:59) Bir dizinin üçüncü elemanına erişimin karmaşıklığı nedir?

> **Çözüm:** $O(1)$; adres başlangıç adresine indis eklenerek tek işlemde hesaplanır.

**10.** (ekrandan, 01:25:00) Sıralı `2, 5, 8, 10, 17, 27` dizisine sırayı bozmadan 1 eklemek için hangi yaklaşımlar vardır, maliyetleri nedir?

> **Çözüm:** Sona ekleyip yeniden sıralamak (derste $N^2$ olarak verildi) ya da yeri bulup ($N$) sonraki elemanları sondan başlayarak kaydırmak ($N$), toplam ≈ $2N$. $N$ eleman eklenirse $O(N^2)$. Sonuç: `1, 2, 5, 8, 10, 17, 27`.

**11.** (derste sözlü, 02:03:34; geçmiş yıl sınav sorusu tipi) `A[1..5] = 1, 5, 9, 3, 4` ise `PO[]` dizisi nedir?

> **Çözüm** (ekrandan, 02:05:00): `PO = [1, 4, 3, -1, 5, 2]`. Head 1. indis (1); 1'den sonra 3 (4. indis); 3'ten sonra 4 (5. indis); 4'ten sonra 5 (2. indis); 5'ten sonra 9 (3. indis); 9'dan sonra $-1$.

**12.** (ekrandan, 02:00:00) `A = [_, 2, 5, 4, 8, 1]`, `PO = [5, 3, 4, 2, -1, 1]` listesine 7 eklenirse `PO` nasıl değişir?

> **Çözüm:** `A[6] = 7`, `PO[2]`: 4 → 6, `PO[6] = 4`.

**13.** (derste sözlü, 02:12:50) Elemanlar `2, 6, 1, 4, 9` girilip 3 eklendikten sonra 4 silinirse `PO` dizisinin son hali nedir?

> **Çözüm (derste sözlü verildi, program ile kontrol edildi):** `A = [_, 2, 6, 1, 4, 9, 3]`, `PO = [3, 6, 5, 1, -2, -1, 2]`. `PO[4]` silindi işareti olarak $-2$ yazılmıştır; hiç değiştirilmezse eski değeri (2) kalır ve bu da doğru kabul edilir, çünkü artık hiçbir eleman 4. indisi göstermez. Sıralı gezinti: 1, 2, 3, 6, 9.

**14.** (ekrandan, 02:25:00) `head = &d2; d2.next = &d1; d1.next = &d4; d4.next = &d3; d3.next = NULL;` için `while(head != NULL)` döngüsü ne yazar; döngü bitince `head` nereyi gösterir?

> **Çözüm:** `2143`; `head` NULL'u gösterir, listenin başı kaybolmuştur.

**15.** (derste sözlü, 02:31:30) Çift yönlü bir listeyi dairesel yapmak için son elemanın "sonraki" ve ilk elemanın "önceki" alanına ne yazılır?

> **Çözüm:** Son elemanın sonrasına ilk elemanın adresi (100), ilk elemanın öncesine son elemanın adresi (40).

## Dersin Toparlaması

Dersin ilk yarısında şifreleme, döngü, koşul, dizi, matris ve fonksiyon gibi temel yapıların gerçek bir uygulaması olarak işlendi. Sezar şifresi toplama ile, afin şifre çarpma ve toplama ile çalışır. Afin şifrede çözme, anahtarın mod 26'daki çarpmaya göre tersine dayanır ve her sayının tersi yoktur. Matris ile şifrelemede ve tam kare matrisle yer değiştirmede anahtar matrisin kendisi ya da yazma/okuma düzenidir. Tek karşılıklı yöntemler frekans analizine açıktır; sık harfleri birden çok sembole dağıtmak bu saldırıyı zorlaştırır. Parolalar hash ile saklandığı için unutulduğunda sıfırlanır. Aradan sonra `%[^\n]` ile satır okuma ve `%c` öncesi tamponda kalan Enter sorunu çözüldü.

İkinci yarıda dizilerin iki zayıflığı ortaya kondu: sıralı ekleme ve silmede kaydırma maliyeti ve büyük dizilerde bitişik bellek bulamama. Bağlı listeler bu iki sorunu, her elemanda fazladan bir adres tutma bedeliyle çözer. Önce `A[]` ve `PO[]` dizileriyle ilkel bir bağlı liste kuruldu, ekleme ve silme kodu adım adım izlendi. Sonra `struct` ve işaretçilerle gerçek bağlı liste, dairesel liste ve çift yönlü liste tanıtıldı. Hoca bağlı listelerden türeyen ağaç yapılarının ileride veri yapıları derslerinde ayrıntılı işleneceğini, konuya sonraki derste devam edileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
