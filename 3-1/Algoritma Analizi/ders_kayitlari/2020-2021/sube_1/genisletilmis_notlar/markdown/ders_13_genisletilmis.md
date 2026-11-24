# Ders 13 Genişletilmiş Notu: Anahtarların Sayıya Dönüştürülmesi, Çakışma ve Doğrusal Yoklama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hash Fonksiyonlarının Hatırlatılması
- 2. Anahtarın Sayıya Dönüştürülmesi
- 3. Çakışma (Collision) Problemi
- 4. Açık Adresleme ve Doğrusal Yoklama
- 5. Hash Tablosu İşlemleri: Ekle ya da Uyar Algoritması
- Örnek Sorular
- Dersin Toparlaması

## 1. Hash Fonksiyonlarının Hatırlatılması

Ders, bir önceki haftada başlanan hashing konusunun özetiyle açıldı. Hashing'de bir $x$ değeri bir hash fonksiyonundan geçirilir; fonksiyon bir adres üretir ve eleman o adrese yerleştirilir. Çok farklı hash fonksiyonları olabilir, ama en çok kullanılan iki temel yöntem bölme (division) ve çarpma (multiplication) yöntemleridir.

### 1.1 Bölme yöntemi

Bölme yönteminde anahtarın tablo uzunluğuna göre modu alınır ve eleman bu adrese yerleştirilir:

$$h(key) = key \bmod m$$

Tablo uzunluğu 7 ise 25 sayısı, $25 \bmod 7 = 4$ olduğu için 4. adrese; 2 sayısı ise 2. adrese yerleşir.

### 1.2 Çarpma yöntemi

Çarpma yönteminde $m$ tablo uzunluğu (table size) olmak üzere (ekrandan, 00:05:00):

$$h(key) = \left\lfloor m \cdot \big((key \cdot A) \bmod 1\big) \right\rfloor, \qquad A = \frac{\sqrt{5}-1}{2} \approx 0{,}618033$$

Buradaki "mod 1" işlemi sayının virgülden sonraki kısmını almak demektir. Tahtadaki örnek adım adım şöyledir (ekrandan, 00:05:00):

- Verilen: $m = 10000$, $key = 123456$ (tabloya yerleşecek sayı).
- $123456 \cdot A = 76300{,}0041151\ldots$
- $\bmod 1$: tam kısım 76300 atılır, $0{,}0041151$ kalır.
- $10000 \cdot 0{,}0041151 = 41{,}151$, taban değeri $41$.
- Sonuç: 123456, tablonun 41. gözüne yerleşir.

> **Ders sonrası not:** Tahtadaki $76300{,}0041151$ çarpımı $A$'nın tam değeriyle ($0{,}6180339887\ldots$) elde edilir. Tahtada yazan altı basamaklı $0{,}618033$ kullanılırsa çarpım $76299{,}882\ldots$ olur ve sonuç 41 değil 8820 çıkar (python ile kontrol edildi). Bu yöntemde $A$'nın yeterli duyarlıkla alınması gerekir.

## 2. Anahtarın Sayıya Dönüştürülmesi

Hoca bu bölüme şu gözlemle başladı: yerleştirilecek eleman tam sayı, kayan noktalı sayı ya da string olabilir; ama adres bir tam sayı olduğuna göre elimizdeki bilgi ne olursa olsun sonunda bir sayı üretmek zorundayız.

### 2.1 Anahtar tekil olmalıdır

Tabloya yerleştirirken kullanılan bilgi mutlaka tekil (unique) olmalıdır. Tahtadaki örnekler TC kimlik numarası, öğrenci numarası, müşteri numarası ve telefon numarasıdır (ekrandan, 00:10:00). Hash, bir elemanın yerini bulmak için bir adres üretme yöntemi olduğundan, yaş gibi birçok kişide aynı olabilecek bir bilgiyi anahtar olarak kullanmanın anlamı yoktur. Ad-soyad da tekil değildir.

### 2.2 String anahtarlar

Hoca, `"Elif"` stringinden nasıl bir adres üretilebileceğini sınıfa sordu (ekrandan, 00:15:00).

**İlk öneri: karakter kodlarını toplamak.** Bir öğrenci her karakterin sayı karşılığını kullanmayı önerdi. Hoca, C'de bunun doğrudan yapılabildiğini hatırlattı: `int x; x = 'E';` yazıldığında `x` karakterin sayı karşılığını alır. Karakterleri yan yana birleştirmek (concatenation) yine bir string verir, bu yüzden işe yaramaz; toplamak ya da çarpmak ise bir sayı üretir. Tahtada değerler örnek olarak $70 + 78 + 73 + 71 = 292$ diye yazıldı (hoca değerleri uydurduğunu açıkça söyledi), sonra bölme yöntemiyle $292 \bmod m$ alınır.

> **Ders sonrası not:** Büyük harflerle `'E'`, `'L'`, `'I'`, `'F'` karakterlerinin gerçek ASCII kodları 69, 76, 73, 70'tir ve toplamları 288'dir (python ile kontrol edildi). Hoca tahtadaki değerlerin yaklaşık olduğunu söylemişti; yöntemin mantığı değişmez.

**Toplamanın sorunu.** Hoca bu yöntemde bir sorun olup olmadığını sordu. Bir öğrenci aynı toplamı veren farklı karakterlerin gelebileceğini söyledi. Örneğin bir harf bir önceki harfle, başka bir harf bir sonraki harfle değiştirilirse toplam aynı kalır. Hoca bu tür özel durumları tek tek çözmeye çalışmanın sonu olmadığını, asıl daha önemli sorunun sıra olduğunu belirtti: toplama sıradan bağımsızdır, bu yüzden

$$'E' + 'l' + 'i' + 'f' = 'f' + 'i' + 'l' + 'E'$$

yani aynı harflerin farklı dizilişleri aynı değeri verir (ekrandan, 00:15:00).

**İkinci öneri: basamak ağırlıkları.** Başka bir öğrenci karakterleri birler, onlar, yüzler, binler basamağına göre çarpıp toplamayı önerdi: `f` 1 ile, `i` 10 ile, `l` 100 ile, `E` 1000 ile çarpılır ve toplamın $m$'ye göre modu alınır. Hoca bunun iyi bir yaklaşım olduğunu, ama çarpanlar asal olmadığından benzer değerler üretme ihtimalinin sürdüğünü söyledi. Çakışma hiçbir zaman tamamen önlenemez; yapılan her şey çakışma olasılığını azaltmaya yöneliktir.

### 2.3 Horner yöntemi

Bunun için önerilen yöntemde çarpan olarak küçük bir asal sayı, 31, seçilir (ekrandan, 00:20:00):

$$hash = 31^{L-1} \cdot s[0] + 31^{L-2} \cdot s[1] + \dots + 31^{0} \cdot s[L-1], \qquad L = \mathrm{strlen}(s)$$

Bu toplam, Horner yöntemiyle bir döngüde şöyle hesaplanır (ekrandan, 00:20:00):

```c
length = strlen(s); hash = 0;
for (i = 0; i < length; i++)
    hash = (R * hash + (s[i] - 'A' + 1));
hash = hash % M;
```

Burada $R = 31$'dir. Stringin tamamen büyük harflerden oluştuğu varsayılır. `s[i] - 'A'` ifadesi karakterin ASCII kodu yerine kaçıncı büyük harf olduğunu verir; tahtada A, B, C harflerinin 0, 1, 2'ye dönüştüğü gösterildi. ASCII kodunu (örneğin A için 65) doğrudan kullanmak da mümkündür, ama gereksiz bir büyüklük getirir. Sonuç en sonda tablo uzunluğuna göre mod alınarak adrese çevrilir.

Hoca `"Elif"` için harf karşılıklarını yine yaklaşık olarak 5, 12, 7, 6 diye yazdı ve değerleri attığını söyledi (ekrandan, 00:20:00). Sonra bunlar sırayla $31^0, 31^1, 31^2, \dots$ kuvvetleriyle çarpılarak toplanır. Hoca bu biçimin Java'da kullanıldığını, 31 yerine 29 kullanan kaynaklar da gördüğünü belirtti. Önemli olan çarpanın küçük bir asal sayı olmasıdır.

> **Ders sonrası not:** Tahtadaki ifade `s[i] - 'A' + 1` olduğundan A, B, C büyük olasılıkla 0, 1, 2'ye değil 1, 2, 3'e karşılık gelir; "A B C → 0 1 2" gösterimi `+1` olmayan `s[i] - 'A'` ifadesine uyar. Harf sıraları E = 5, L = 12, I = 9, F = 6'dır; `+1`'li biçimle `"ELIF"` için döngü $5 \cdot 31^3 + 12 \cdot 31^2 + 9 \cdot 31 + 6 = 160772$ verir (python ile kontrol edildi).

> **Ders sonrası not:** Java'nın `String.hashCode` metodu büyük olasılıkla harf sırasını değil karakterin kendi kodunu kullanır: $s[0] \cdot 31^{n-1} + s[1] \cdot 31^{n-2} + \dots + s[n-1]$, taşmalı 32 bitlik tam sayı aritmetiğiyle. Çarpanın 31 olması dersle aynıdır.

> **Ek bilgi (derste anlatılmadı):** Horner yöntemi aslında bir polinomu $a_0 x^{n} + a_1 x^{n-1} + \dots + a_n = (\dots((a_0 x + a_1) x + a_2) \dots) x + a_n$ biçiminde, yalnız $n$ çarpma ve $n$ toplamayla hesaplama yöntemidir. String hash'i, katsayıları karakterler olan ve $x = 31$ noktasında hesaplanan bir polinom olduğu için bu yöntemle verimli hesaplanır.

### 2.4 Bileşik anahtar (compound key)

İkinci durum, birden fazla parçadan oluşan bir bilgidir. Örnek olarak gün-ay-yıl biçiminde bir doğum tarihi alındı. Yine küçük bir tam sayı olan $R$ çarpanı (31, 23 gibi) kullanılır. Hoca iki biçim yazdı (ekrandan, 00:25:00):

$$hash = \Big( \big( (day \cdot R + month) \bmod M \big) \cdot R + year \Big) \bmod M$$

$$hash = (day \cdot R^2 + month \cdot R + year) \bmod M$$

<!-- BELİRSİZ: tahtadaki ilk formülün parantezleri tam okunmuyor ("(day*R + month) %M * R*year) %M" gibi); hocanın sözlü anlatımına ("R çarpı D ekledim, modunu aldım, R çarpı ... ekledim, tamamının modunu aldım") göre yukarıdaki biçim yazıldı. -->

Birincisinde her adımda mod alınarak sayının büyümesi engellenir; ikincisinde toplam tek seferde hesaplanıp modu alınır. Bunlar yapılabilecek yaklaşımlardan yalnızca birkaçıdır.

**Soru:** $R$ asal mı seçilmeli? **Cevap:** Evet, $R$'nin asal seçilmesi tavsiye edilir; amaç çakışmayı olabildiğince önlemektir.

### 2.5 Kayan noktalı sayılar

Anahtar bir kayan noktalı (floating point) sayıysa önce tam sayıya çevrilmesi gerekir (ekrandan, 00:25:00):

- $35{,}780$ gibi bir sayı için: $\mathrm{round}(x \cdot 10000) \bmod M$. Sayı önce kesirsiz hale getirilir, sonra modu alınır.
- $0 \le x \le 1$ ise: $hash = \mathrm{round}(x \cdot m)$. Sayı 0 ile 1 arasında olduğundan $m$ ile çarpınca zaten tablo uzunluğu aralığında bir değer elde edilir; ayrıca mod almaya gerek yoktur.
- Java'da anahtarın ikili gösterimi (binary representation) alınıp o kullanılır.

> **Ders sonrası not:** $x$ 1'e çok yakın olduğunda $\mathrm{round}(x \cdot m)$ değeri $m$'ye eşit olabilir ve $0..m-1$ adres aralığının dışına çıkar (örneğin $\mathrm{round}(0{,}99 \cdot 10) = 10$). Bu yüzden $0 \le x < 1$ için $\lfloor x \cdot m \rfloor$ kullanmak daha güvenlidir.

> **Hocanın vurgusu:** String'i anahtar olarak mümkün olduğunca kullanmamaya çalışın; string kullanıldığında çakışma ihtimali çok daha fazladır.

## 3. Çakışma (Collision) Problemi

Hoca önce bir yanlış anlamayı düzeltti: hash tablosu denilen şey aslında bildiğimiz bir dizidir. Algoritma kitaplarında dizilere "hash" gibi adlar verilmesi yalnızca bir adlandırmadır; `float` ya da `int` gibi ayrılmış bir sözcük (reserved word) değildir. Java'nın hazır hash metotları ise ayrı bir konudur; derste algoritmik olarak hash işlemlerinin nasıl yapılacağı anlatıldı.

Boyu 7 olan bir tablo düşünelim. $x = 5$ gelirse $5 \bmod 7 = 5$ olduğu için 5. göze yerleşir. Sonra $x = 12$ gelirse o da $12 \bmod 7 = 5$ olduğu için 5. göze yerleşmek ister (ekrandan, 00:30:00). Göz doludur. Hash fonksiyonunun ürettiği adrese yerleşmeyi beklerken o göze daha önce başka bir eleman yerleşmiştir. Bu duruma **çakışma (collision)** denir.

Hoca önce çakışma olduğunda nasıl çözüleceğini, sonra çakışmanın olasılıksal olarak az olması için neler yapılması gerektiğini anlatacağını söyledi.

## 4. Açık Adresleme ve Doğrusal Yoklama

Hoca sınıfa çakışma olduğunda ilk akla gelen çözümü sordu. Bir öğrenci boş bir yer bulunana kadar sağa kaymayı önerdi. Bu, çakışma çözümünde ilk yaklaşım olan **açık adresleme (open addressing)** içindeki **doğrusal yoklama (linear probing)** yöntemidir (ekrandan, 00:30:00).

### 4.1 Yoklama ve formül

Boş mu diye yapılan her kontrole **yoklama (probe)** denir ("Each check is probe"). Doğrusal yoklamada $i$. denemedeki adres:

$$h(key, i) = \big(h'(key) + i\big) \bmod m, \qquad i = 0, 1, 2, \dots$$

Burada $h'$ asıl hash fonksiyonudur (bu örnekte $key \bmod m$).

### 4.2 Örnek: $m = 7$ tablosuna 5, 12 ve 19

Tablo, gösterim kolaylığı için boyuna çizildi; ama yine bir dizidir.

- 5: $i = 0$, $5 \bmod 7 = 5$, 5. göz boş, yerleşir.
- 12:
  - $i = 0$: $12 \bmod 7 = 5$, dolu.
  - $i = 1$: $(12 + 1) \bmod 7 = 13 \bmod 7 = 6$, boş, 6. göze yerleşir.
- 19:
  - $i = 0$: $19 \bmod 7 = 5$, dolu.
  - $i = 1$: $20 \bmod 7 = 6$, dolu.
  - $i = 2$: $21 \bmod 7 = 0$, boş, 0. göze yerleşir.

Altıncı gözden sonra "aşağısı yok" deyip durulmaz; arama dairesel (circular) olarak başa döner. Mod almak bu dairesel bakışı sağlar. (Ara sonuçlar python ile kontrol edildi.)

### 4.3 Sınavlarda en sık yapılan hata

> **Hocanın vurgusu:** Sınavlarda en sık görülen hata, kod yazarken adresi bulduktan sonra göz doluysa adresi mod almadan artırmaktır.

Öğrenciler genellikle `adr = key % m` ile 5'i bulur, 5. göz dolu olunca adresi artıra artıra ilerler: 6, sonra 7. Oysa 7. göz yoktur; tablo dışına taşılır. Bunu önlemek için her artırmada tablo uzunluğuna göre mod alınmalıdır. Her seferinde baştan $key + i$ hesaplamak yerine, elimizdeki adresi bir artırıp modunu almak yeterlidir:

$$adr = (adr + 1) \bmod m$$

Böylece 6 dolu olduğunda bir daha artırılan adres 7 değil $7 \bmod 7 = 0$ olur ve başa dönülür.

**Soru:** Burada `++`'yı önce yazmak gerekmiyor mu (`adr++ % M` yazılırsa önce artırma mı, mod mu yapılır)? **Cevap:** Hoca o anda emin olamadığını, mantıken önce artırıp sonra mod alınacağını söyledi ve karışıklık olmasın diye öğrencinin dediği gibi açık yazmayı tercih etti. Tahtadaki son biçim $adr = (adr + 1) \bmod m$ oldu (ekrandan, 00:50:00).

> **Ders sonrası not:** C'de `adr++ % M` ifadesi artırmadan önceki değerin modunu verir; `adr = adr++ % M` ise aynı değişkeni bir ifadede iki kez değiştirdiği için tanımsız davranıştır. Doğru ve açık yazım `adr = (adr + 1) % M` biçimidir.

## 5. Hash Tablosu İşlemleri: Ekle ya da Uyar Algoritması

Hash tablosu üzerinde yapılacak temel işlemler ekleme (insert), arama (search) ve silmedir (delete). Bir adres boşsa NULL ile gösterilir; tablonun başlangıçta NULL ile doldurulduğu varsayılır (ekrandan, 00:35:00).

### 5.1 Problem

Tahtaya yazılan soru (ekrandan, 00:40:00): "Bir hash tablosuna yeni bir eleman eklenmek isteniyor. Eğer bu eleman tabloda daha önce varsa kullanıcıya uyarı mesajı veren, yoksa tabloya ekleyen algoritma."

Hoca bunun gerçek hayattaki karşılığını şöyle anlattı: bir e-posta servisinde hesap açarken bir kullanıcı adı yazarsınız; sistem durmadan "bu alınmış" der. Aslında yapılan iş, yazdığınız adın bir hash tablosunda aranmasıdır. Ad daha önce varsa alındığı söylenir, yoksa almanıza izin verilir.

### 5.2 Algoritmanın kurulması

Anahtarın okunduğu varsayılır ve başlangıç değerleri verilir: $i = 0$, $adr = key \bmod m$. Hoca döngü koşulunu öğrencilerle birlikte kurdu.

Bir öğrenci ilk koşul olarak "adres NULL olmadığı sürece" dedi. Hoca bunun doğru olduğunu, ama önce başka bir kontrolün konması gerektiğini söyledi: $i < m$.

> **Hocanın vurgusu:** Açık adreslemede tablo, çakışma azalsın diye girilecek eleman sayısından büyük tutulur; 5 eleman için en az 7-8 göz gerekir, dolayısıyla tabloda normalde mutlaka boş yer vardır. Ama tablo sizin kontrolünüz dışında doldurulmuşsa ve bu kontrol yoksa döngü tabloda sürekli döner ve sonsuz döngü oluşur. Güvenlik açısından kritik (safety-critical) bir kod yazıyorsanız (örneğin uzaya füze gönderiyorsanız) bu tür beklenmedik ama olası durumlara karşı $i < m$ kontrolü konmalıdır; $m$'den fazla dönülürse tablo dolu denip çıkılır.

Üçüncü koşul için hoca ipucu verdi: eleman daha önce eklenmişse tekrar eklenmemeli. Bir öğrenci "hash tablosunun adres gözü bizim bulduğumuz değere eşit olmadığı sürece" koşulunu önerdi. Anahtarların tam sayı olduğu varsayıldı (tahtada "integer olduğu varsayılıyor"); string olsaydı `strcmp` ile karşılaştırma gerekirdi.

Tahtadaki akış şeması metin olarak şöyledir (ekrandan, 00:45:00 ve 00:50:00):

```text
i = 0
adr = key mod m
DÖNGÜ: (i < m) && (hash[adr] != NULL) && (hash[adr] != key) doğru olduğu sürece
    i++
    adr = (adr + 1) % m
DÖNGÜDEN SONRA:
    i == m ?
        T -> "tablo dolu"
        F -> hash[adr] == NULL ?
                 T -> hash[adr] = key
                 F -> "Eklenmiş"
```

Döngüdeki üç koşulun görevi:

- $i < m$: tablo dolu mu? Olası sıkıntılara karşı koruma.
- `hash[adr] != NULL`: boş göz bulundu mu?
- `hash[adr] != key`: dolu gözdeki eleman aradığımız anahtar mı? Öyleyse eklenmemeli.

$i$ tabloda kaç kez dönüldüğünü saymak için artırılır; adres ise $adr = (adr + 1) \bmod m$ ile ilerletilir.

### 5.3 Tahtadaki örnekle izleme

Tablo uzunluğu 7, eklenecek anahtar 12 olsun: $adr = 12 \bmod 7 = 5$ (ekrandan, 00:45:00). 5. gözde 5 vardır.

- `hash[5]` NULL mı? Hayır, orada 5 var. `hash[5]` 12'ye eşit mi? Hayır. Döngü sürer: $i = 1$, $adr = 6$.
- Hoca, anahtarın daha önce eklenmiş olduğu durumu göstermek için 6. göze 12'yi yazdı (ekrandan, 00:50:00). `hash[6]` NULL'dan farklıdır ama 12'ye eşittir; döngüden çıkılır.

Döngüden çıkıldıktan sonra çıkış sebebi kontrol edilir. Çıkışın sebebi üç koşuldan biri olmak zorundadır:

- $i = m$ ise $m$ kez dönülmüş demektir: "tablo dolu".
- `hash[adr] == NULL` ise boş göz bulunmuştur: `hash[adr] = key` ile yerleştirilir.
- İkisi de değilse üçüncü koşul bozulmuştur, yani göz hem doludur hem de içinde aynı anahtar vardır: "Eklenmiş" uyarısı verilir.

Hoca, bir e-posta servisinde çalışıyor olsaydık yeni hesap isteyen birine adres verme problemini tam olarak bu şekilde çözmüş olacağımızı söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:10:09; ekrandan, 00:15:00): `"Elif"` stringinden hash tablosu için nasıl bir sayı (adres) üretilebilir? Karakter kodlarını toplamak mantıklı mı, bunun bir sorunu var mı?

> **Çözüm (derste verildi):** Karakterlerin sayı karşılıkları toplanıp $m$'ye göre modu alınabilir, ama toplama sıradan bağımsız olduğu için aynı harflerin farklı dizilişleri (`"Elif"` ile `"filE"`) aynı adrese düşer. Basamak ağırlıkları sırayı hesaba katar, ama asal olmayan çarpanlarla benzer değerler üretme ihtimali sürer. Önerilen çözüm küçük bir asal çarpanla ($R = 31$) Horner yöntemidir: `hash = R*hash + (s[i]-'A'+1)`, sonunda `hash % M`.

**Soru 2** (derste sözlü, 00:27:47; ekrandan, 00:30:00): Boyu 7 olan tabloda 5. gözde 5 varken 12 gelirse ($12 \bmod 7 = 5$) 12 nereye yerleştirilir? Ardından 19 gelirse nereye yerleşir?

> **Çözüm (derste verildi):** Doğrusal yoklama ile $h(key, i) = (h'(key) + i) \bmod 7$. 12 için $i = 1$'de $13 \bmod 7 = 6$ boştur, 12 6. göze yerleşir. 19 için 5 ve 6 doludur, $i = 2$'de $21 \bmod 7 = 0$ boştur, 19 0. göze yerleşir.

**Soru 3** (ekrandan, 00:40:00): Bir hash tablosuna yeni bir eleman eklenmek isteniyor. Eğer bu eleman tabloda daha önce varsa kullanıcıya uyarı mesajı veren, yoksa tabloya ekleyen algoritmayı yazınız.

> **Çözüm (derste verildi, akış şeması tahtadan; ekrandan, 00:50:00):** $i = 0$, $adr = key \bmod m$. `(i < m) && (hash[adr] != NULL) && (hash[adr] != key)` doğru olduğu sürece `i++` ve `adr = (adr + 1) % m`. Döngüden sonra: `i == m` ise "tablo dolu"; değilse `hash[adr] == NULL` ise `hash[adr] = key`; değilse "Eklenmiş" uyarısı.

**Soru 4** (ekrandan, 00:05:00): Çarpma yöntemiyle $m = 10000$ ve $A = \frac{\sqrt{5}-1}{2}$ için $key = 123456$ hangi adrese yerleşir?

> **Çözüm (derste verildi):** $123456 \cdot A = 76300{,}0041151\ldots$; kesir kısmı $0{,}0041151$; $\lfloor 10000 \cdot 0{,}0041151 \rfloor = \lfloor 41{,}151 \rfloor = 41$. (Python ile $A$'nın tam değeriyle doğrulandı.)

## Dersin Toparlaması

Bu derste hash fonksiyonlarının iki temel yöntemi (bölme ve çarpma) hatırlatıldıktan sonra farklı türdeki anahtarların sayıya nasıl dönüştürüleceği görüldü. Anahtarın tekil olması gerektiği vurgulandı. String anahtarlarda karakter toplamının permütasyonlarda çakıştığı, basamak ağırlıklarının da yetersiz kalabildiği gösterildi ve küçük bir asal çarpanla (31) Horner yöntemi anlatıldı. Bileşik anahtarlar için $R$ çarpanlı birleştirme, kayan noktalı sayılar için önce tam sayıya çevirme yöntemleri verildi.

Ardından çakışma problemi tanımlandı ve ilk çözüm olarak açık adresleme içinde doğrusal yoklama işlendi. Adres artırılırken mod alınması gerektiği ve döngüye $i < m$ kontrolü konması gerektiği özellikle vurgulandı. Son olarak eleman tabloda varsa uyaran, yoksa ekleyen algoritma öğrencilerle birlikte kuruldu. Hoca, çakışma olasılığını azaltmak için neler yapılması gerektiğini de ileride anlatacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
