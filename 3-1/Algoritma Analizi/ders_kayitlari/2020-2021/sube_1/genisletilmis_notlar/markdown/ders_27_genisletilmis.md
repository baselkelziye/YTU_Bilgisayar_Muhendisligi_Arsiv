# Ders 27 Genişletilmiş Notu: Kitap Önerme Ödevi: Pearson Benzerliğiyle İşbirlikçi Filtreleme; Böl ve Yönet ile En Küçük Eleman

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Yapısı
- 2. Tavsiye Sistemleri ve İşbirlikçi Filtreleme
- 3. Varyans, Kovaryans ve Korelasyon
- 4. Pearson Korelasyonu ile Kullanıcı Benzerliği
- 5. Ödevdeki Öneri Adımları
- 6. Ödevle İlgili Sorular
- 7. En Küçük Elemanı Bulma: Sıralama Değil, Böl ve Yönet
- 8. Hash Tablosunun Boyutu
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Yapısı

Bu kayıt yeni konu anlatılan bir teori dersi değildir. Dönemin son haftasında yapılan, yaklaşık bir saatlik bir açıklama oturumudur. İlk bölümde son ödevin (kullanıcıdan kullanıcıya benzerlik ile kitap öneren bir sistem) arkasındaki fikir anlatılmış, öğrencilerin ödevle ilgili soruları cevaplanmıştır. İkinci bölümde ara sınavda çok sık görülen hatalar üzerinden iki konu tekrar edilmiştir: böl ve yönet (divide and conquer) ile bir dizinin en küçük elemanını bulmak ve hash tablosunun boyutunu seçmek. Hoca iPad not uygulamasında elle yazarak anlatmıştır.

## 2. Tavsiye Sistemleri ve İşbirlikçi Filtreleme

### 2.1 Tavsiye sistemleri

Tavsiye (recommendation) sistemleri son yıllarda çok popülerdir. Netflix, Amazon, Pinterest, YouTube gibi milyonlarca kullanıcısı olan platformlar bu sistemleri kullanır. Örneğin bir film platformu, kullanıcının daha önce izlediği filmlere bakarak "bunları da izlemek isteyebilirsin" diye öneri yapar. Ödevde benzer şekilde bir kitap önerme sistemi kurulması istenmiştir.

### 2.2 İşbirlikçi filtreleme (collaborative filtering)

Eski sistemler yalnız kullanıcının kendi davranışını değerlendiriyordu. İşbirlikçi filtrelemede ise kullanıcıya benzeyen kişilerin nasıl seçimler yaptığına bakılır ve onların seçimleri önerilir. "Size benzeyen kişi", sizin alışkanlıklarınıza benzeyen, sizin gibi filmler ya da kitaplar seçen kişi demektir. Hoca burada insanların tek düze davranmadığını vurgulamıştır: kimse yalnız romantik komedi ya da yalnız biyografi izlemez, aynı tür içinde de farklı tarzlar vardır. Bu yüzden benzerlik, kişilerin puan örüntüleri üzerinden ölçülür.

İki temel yaklaşım vardır:

- **Kullanıcı tabanlı (user-based):** Size en çok benzeyen kişiler bulunur, onların beğendikleri size önerilir.
- **Öğe tabanlı (item-based):** Daha önce izlediğiniz ya da okuduğunuz öğelere benzeyen öğeler önerilir ("şu kitapları okumuştun, bunu da okursun").

Hocaya göre büyük platformlar bugün genel olarak öğe tabanlı yöntemi kullanır. Ödevde ise basit olduğu için **kullanıcıdan kullanıcıya benzerlik (user-to-user similarity)** seçilmiştir.

## 3. Varyans, Kovaryans ve Korelasyon

Benzerliği ölçmek için kovaryanstan, yani iki bilginin birlikte nasıl değiştiğinden yararlanılır. Hoca bunu kısaca hatırlatmıştır.

### 3.1 Varyans

$n$ tane örneğin varyansı, her örneğin ortalamadan farkının karesinin ortalamasıdır (ekrandan, 00:20:00; paydadaki $n$ sözlü anlatımdan):

$$\mathrm{var}(x)=\frac{1}{n}\sum_{i=1}^{n}(x_i-\bar{x})^2$$

Varyans standart sapmanın karesidir ve örneklerin ortalamaya göre nasıl değiştiğini gösterir. Hoca bunun neden gerekli olduğunu şöyle açıklamıştır: iki farklı dizinin ortalaması aynı çıkabilir (örneğin ikisinin de ortalaması 2), ama dağılımları farklıdır. Yalnız ortalamaya bakınca bu fark görünmez; ortalamaya göre sapmaya bakınca dağılım anlaşılır.

### 3.2 Kovaryans ve korelasyon

Kovaryans, iki bilginin birbirine göre değişimidir. Hoca boy ve kilo gibi iki özelliği örnek vermiştir. Bu iki özelliğin değerleri bir düzlemde nokta olarak çizildiğinde üç durum görülebilir:

- **Pozitif korelasyon:** İki değer birlikte artar. Örneğin küçük çocuklarda boy artarken kilo da artar.
- **Korelasyon yok:** Noktalar arasında bir eğilim yoktur.
- **Negatif korelasyon:** Biri artarken öbürü azalır. Hocanın örneği: sigara içme arttıkça ömür kısalır.

Korelasyon, iki bilginin birlikte nasıl değiştiğini, yani aralarındaki ilişkiyi görmek için kullanılır.

## 4. Pearson Korelasyonu ile Kullanıcı Benzerliği

### 4.1 Pearson katsayısı

İki kullanıcının birbirine göre değişimini görmek için Pearson korelasyonu kullanılır. Katsayı $r$, $-1$ ile $+1$ arasında değişir:

- $r>0$: pozitif ilişki (iki kullanıcı benzer eğilimde),
- $r<0$: negatif ilişki,
- $r=0$: aralarında ilişki yok.

Amaç, bir kullanıcıya en çok benzeyen kişileri bulmaktır. Benzerlik ne kadar büyükse iki kullanıcı birbirine o kadar benzer; $+1$'e yakın değer güçlü benzerlik, $0$ ilişkisizlik, $-1$ zıt eğilim demektir.

### 4.2 Ödevdeki benzerlik formülü

Hocanın ödev metniyle aynı biçimde yazdığı formül (ekrandan, 00:35:00):

$$\mathrm{sim}(a,b)=\frac{\sum_{p\in P}(r_{a,p}-\bar{r}_a)(r_{b,p}-\bar{r}_b)}{\sqrt{\sum_{p\in P}(r_{a,p}-\bar{r}_a)^2}\;\sqrt{\sum_{p\in P}(r_{b,p}-\bar{r}_b)^2}}$$

Terimlerin anlamı (ekrandaki kırmızı notlardan):

- $a$ ve $b$: benzerliği ölçülen iki kullanıcı (user a, user b).
- $P$: $a$ ve $b$'nin **ikisinin de okuduğu** kitaplar. Yalnız birinin okuduğu kitap üzerinden benzerlik ölçülemez.
- $r_{a,p}$: $a$'nın $p$ kitabına verdiği puan.
- $\bar{r}_a$, $\bar{r}_b$: $a$'nın ve $b$'nin rating ortalaması. Ortalama, kullanıcının dolu gözleri (puan verdiği kitaplar) üzerinden hesaplanır.

Pay, ortak kitapların her biri için "$a$'nın puanının kendi ortalamasından farkı" ile "$b$'nin puanının kendi ortalamasından farkı"nın çarpımlarının toplamıdır; yani iki kullanıcının kovaryansıdır. Paydadaki iki karekök terimi standart sapmalara karşılık gelir ve normalizasyon sağlar; sonuç bu sayede $[-1,+1]$ aralığına düşer.

> **Ek bilgi (derste anlatılmadı):** Ortalamaları çıkarmak, "cömert" puan veren bir kullanıcıyla "cimri" puan veren bir kullanıcıyı karşılaştırılabilir hale getirir. Örneğin biri hep 4–5, öbürü hep 2–3 veriyor ama ikisi de aynı kitapları diğerlerinden daha çok beğeniyorsa Pearson katsayısı yine yüksek çıkar. Kayıtta $\bar{r}_a$'nın tüm puanlar mı yoksa yalnız ortak kitaplar üzerinden mi alınacağı açıkça ayrılmadı; ödev metnindeki tanıma uyulmalıdır.

## 5. Ödevdeki Öneri Adımları

### 5.1 Veri

Veri, Excel olarak verilmiş küçük bir tablodur. Hoca, Excel dosyasını kütüphaneyle okumaya çalışmak yerine bir veri dosyası (TXT ya da CSV) olarak kullanmayı söylemiştir. Tablonun yapısı (ekrandan, 00:35:00):

| Bölüm | Satırlar | Sütunlar |
|---|---|---|
| Eski kullanıcılar | U1–U20 | 8 kitap (book 1 … 8) |
| Yeni kullanıcılar | NU1–NU5 | aynı 8 kitap |

Hoca, veri madenciliği terimleriyle eski kullanıcıların eğitim kümesi (train set), yeni kullanıcıların test kümesi (test set) olduğunu belirtmiştir.

### 5.2 Benzerliklerin hesaplanması ve en benzer k kişi

1. Her kullanıcının dolu gözler üzerinden rating ortalaması hesaplanır.
2. Her yeni kullanıcı için U1, U2, …, U20 ile benzerlik hesaplanır: $\mathrm{sim}(NU1,U1)$, $\mathrm{sim}(NU1,U2)$, …, $\mathrm{sim}(NU1,U20)$ (ekrandan, 00:35:00).
3. Benzerliği en yüksek $k$ kişi seçilir. Ödevde $k=3$'tür. Hocanın örneğinde en benzer üç kişi U5, U7 ve U2'dir.

### 5.3 Okunmamış kitaplar için tahmin

Hoca küçük bir örnek çizmiştir (ekrandan, 00:30:00): yeni kullanıcı NU1'in 5 kitaplık puan satırı şöyledir.

| Kitap | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|
| NU1 | 2 | ? | 1 | 4 | ? |

NU1, 2. ve 5. kitapları okumamıştır. Bu iki kitaba verebileceği puan tahmin edilir; hangisine daha yüksek puan verecek gibi görünüyorsa o kitap önerilir. NU1'in rating ortalaması dolu gözlerden $(2+1+4)/3=7/3\approx 2{,}33$'tür (ara adım eklendi).

Tahmin $\mathrm{pred}(NU1,p)$ şu bilgilerle hesaplanır (sözlü anlatımdan):

- yeni kullanıcının kendi rating ortalaması,
- en benzer $k$ kişinin (U5, U7, U2) her biri için NU1 ile daha önce hesaplanmış benzerliği,
- bu kişilerin $p$ kitabına verdiği puan ve kendi ortalamaları.

<!-- BELİRSİZ: tahmin formülünün tamamı karelerde görünmüyor; 00:30:00 karesinde yalnız "pred(NU1, p) = r_a" başlangıcı var. Formülün kesin biçimi ödev metninden alınmalı. -->

> **Ek bilgi (derste anlatılmadı):** Kullanıcı tabanlı işbirlikçi filtrelemede yaygın tahmin formülü büyük olasılıkla şudur: $\mathrm{pred}(a,p)=\bar{r}_a+\dfrac{\sum_{b\in N}\mathrm{sim}(a,b)\,(r_{b,p}-\bar{r}_b)}{\sum_{b\in N}\mathrm{sim}(a,b)}$. Burada $N$ en benzer $k$ kullanıcıdır. Formül, kullanıcının kendi ortalamasına komşuların "ortalamadan sapmalarının" benzerlikle ağırlıklı ortalamasını ekler.

Bu işlem bir yeni kullanıcı için yapıldığında, örnekte iki okunmamış kitap için iki tahmin bulunur ve yüksek olan kitap önerilir. Aynı işlem beş yeni kullanıcının hepsi için tekrarlanır.

### 5.4 Sonuçların gösterimi

Sonuçlar her yeni kullanıcı için bir satır olacak biçimde bir tabloda verilir: en çok benzediği üç kişi ve önerilen kitap. Hoca, kendisi yapsa her kullanıcı için en benzer üç kişinin kitaplara verdiği puanları da yazdıracağını söylemiştir. Veri küçük olduğu için bu sayede benzerlik gözle de görülebilir: örneğin bir kullanıcı üç kitaba 3, 5, 4 veriyor, benzer bulunan kişi de 3, 5, 4 civarında veriyorsa gerçekten benziyorlardır.

### 5.5 Ödevin algoritmik yükü

Hoca bu ödevde rekürsif çözüm ya da backtracking gibi algoritmik bir ağırlık olmadığını vurgulamıştır. Yapılacak hesaplar ortalama almak, ortalamadan farkları bulmak, bunları çarpıp toplamak ve iç içe döngüler kurmaktır. Temel bileşen kovaryanstır: sınavda iki dizi verilip kovaryansının hesaplanması istense kısa sürede yapılabilecek bir iştir. Hazır veri madenciliği kütüphanesine ihtiyaç yoktur. Bugün bu sistemler derin öğrenmeyle geliştirilmiş yöntemlerle kuruluyor olsa da temelleri iki bilginin birlikte değişimine, yani kovaryansa dayanır.

> **Hocanın vurgusu:** Ödevin hedefi, güncel bir konuda bir algoritmayı baştan sona, gereksiz karmaşıklık katmadan tasarlayıp çalışır hale getirebilmektir. Böyle bir çalışma ileride geliştirilebilecek bir başlangıç uygulamasıdır.

## 6. Ödevle İlgili Sorular

**Soru:** Veriler program içinde tanımlanabilir mi? **Cevap:** Hayır, dosyadan okunmalıdır; böylece farklı bir veriyle de denenebilir. Dosya Excel olmamalı; TXT ya da CSV gibi düz bir dosya olabilir. Veri zaten küçüktür (25 satır, 8 sütun).

**Soru:** Veri TXT'ye çevrilirken farklı biçimler (örneğin ilk satırda kitap adları, sonra kullanıcılar, en altta yeni kullanıcılar) kullanılırsa ne olur? **Cevap:** Herkes farklı biçim kullanabileceği için oluşturulan veri dosyası da ödevle birlikte gönderilmelidir. Bir öğrencinin önerisiyle, dosyanın uzantısı değiştirilerek elde edilen CSV biçiminin ortak kullanılması kararlaştırılmıştır.

**Soru:** Sonuçların "tablo olarak" verilmesi dosyaya mı yazdırılmalı? **Cevap:** Hayır; satır satır ekrana yazdırmak yeterlidir.

**Soru:** Yeni kullanıcılar ayrı bir dosyada tutulabilir mi? **Cevap:** Tutulabilir, ama gerekmez. Dosyanın başına ilk sayı olarak kullanıcı (eğitim) sayısı, ikinci sayı olarak test kullanıcısı sayısı yazılarak tek dosyadan okunabilir.

## 7. En Küçük Elemanı Bulma: Sıralama Değil, Böl ve Yönet

### 7.1 Sınavdaki problem ve yaygın hata

Ara sınavda koşu süreleri verilen yarışmacılar arasından altın madalyayı kazananın böl ve yönet algoritmasıyla bulunması istenmişti. Altın madalyayı kazanan en kısa sürede koşan kişidir; yani problem bir dizinin en küçük elemanını bulmaktır. Süreler saat, dakika, saniye biçiminde verilmişti.

Kâğıtların büyük çoğunluğunda dizi önce merge sort ya da quick sort ile sıralanmıştı. Hoca bunun hiç beklenmediğini söylemiştir: en küçük (ya da en büyük) elemanı bulmak birinci sınıfta öğrenilen tek geçişli bir aramadır ve bunun için dizi sıralanmaz. Ayrıca sıralama yapanların bir kısmı en küçük elemanı (sıralı dizinin sıfırıncı elemanını) değil bütün diziyi yazdırmış, birçoğu da süreyi tek bir birime dönüştürmeden sıralamıştı.

### 7.2 Kaba kuvvet çözümün karmaşıklığı

Sorunun devamında kaba kuvvet (brute force) çözümün nasıl olacağı ve daha iyi olup olmayacağı soruluyordu. Çoğunluk kaba kuvvetin $O(n^2)$ olacağını yazmıştı. Bu yanlıştır: en küçük elemanı kaba kuvvetle bulmak diziyi bir kez dolaşıp o ana kadarki en küçüğü tutmaktır ve $O(n)$'dir.

> **Hocanın vurgusu:** En küçük elemanı bulmak için diziyi sıralamak gereksizdir; kaba kuvvet çözüm $O(n)$'dir.

### 7.3 Diziyi bir kez ikiye bölmek

Bir öğrenci diziyi ikiye bölmüş, her yarının en küçüğünü bulmuş ve iki sonucu karşılaştırmıştı. Hoca bu fikri doğru bir başlangıç olarak değerlendirmiştir. Böl ve yönetin önemli kullanımlarından biri paralel programlamadır: dizinin iki yarısı iki ayrı işlemciye verilir, her biri kendi yarısını çözer, sonuçlar karşılaştırılır. İş yükü paralel çalıştırıldığı için süre azalır.

### 7.4 Özyinelemeli çözüm

Asıl böl ve yönet çözümü bu bölmenin özyinelemeli olarak, merge sort'ta olduğu gibi, tek eleman kalana kadar sürdürülmesidir. Tek eleman kaldığında en küçük eleman odur. Geri dönerken her adımda iki parçadan gelen sonuçlar karşılaştırılır ve küçük olanın indisi yukarı döndürülür (ekrandan, 00:50:00 ve 00:55:00).

Tahtadaki çizimde dizi iki yarıya bölünmüş, sol yarının sonucu `tmp1`, sağ yarının sonucu `tmp2` olarak gösterilmiştir. Fonksiyon en küçük elemanın değerini değil, "adresini", yani dizideki indisini döndürür. Hoca durma koşulunu önce `if (l = r)` biçiminde yazmış, ardından iki eşittir olması gerektiğini söyleyerek düzeltmiştir.

Tahtadaki kod (ekrandan, 00:55:00). Hoca değişken bildirimlerini "değişken deklarasyonu" diye geçip yazmamıştır; `temp1, temp2` bildirimi ve küçük bir `main` eklenerek kod `gcc -Wall` ile derlenmiş ve kısa bir diziyle çalıştırılmıştır, en küçük elemanın indisini doğru döndürmüştür:

```c
int findMin(int l, int r, int A[])
{
    int temp1, temp2;                         /* derste "değişken deklarasyonu" diye geçildi */
    if (l == r)
        return l;                             /* tek eleman: en küçük elemanın adresi (indisi) */
    else {
        temp1 = findMin(l, (l + r) / 2, A);       /* sol yarı */
        temp2 = findMin((l + r) / 2 + 1, r, A);   /* sağ yarı */
        if (A[temp1] <= A[temp2])
            return temp1;
        else
            return temp2;
    }
}

int main()
{
    /* ... dizinin okunması ... */
    min = findMin(0, N - 1, A);
    /* A[min] en küçük elemandır */
}
```

`main` içinde fonksiyon dizinin tamamı için, yani $0$'dan $N-1$'e kadar olan aralık için çağrılır. Dönen değer bir indistir; `A[min]` en küçük elemanı verir.

> **Ek bilgi (derste anlatılmadı):** Bu algoritmanın çalışma süresi $T(n)=2T(n/2)+O(1)$ bağıntısını sağlar; ana teoremle $T(n)=\Theta(n)$ bulunur. Yani böl ve yönet çözümü tek işlemcide kaba kuvvetten asimptotik olarak daha hızlı değildir; yarar, iki yarının paralel çözülebilmesindedir.

## 8. Hash Tablosunun Boyutu

Sınavdaki hash sorusunda (bir hash tablosu kullanarak iki dizinin kesişimini bulma) öğrencilerin çoğu tablo uzunluğunu dizi uzunluğuna eşit almıştı; bazıları da beş elemanlı bir dizi için 100 gibi çok büyük bir tablo seçmişti. Hoca iki seçimin de kötü olduğunu söylemiştir.

> **Hocanın vurgusu:** Hash tablosunun uzunluğu, yerleştirilecek dizinin uzunluğunun yaklaşık iki katı alınmalıdır.

> **Ek bilgi (derste anlatılmadı):** Tablo uzunluğunu eleman sayısına eşit almak doluluk oranını 1'e çıkarır; açık adreslemede çarpışmalar ve arama süresi bu durumda çok artar. Çok büyük tablo ise belleği boşa harcar. Yaklaşık iki kat, doluluk oranını 0,5 civarında tutar.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:42:51; ara sınav sorusu): Bir yarışmada koşucuların koşu süreleri (saat, dakika, saniye) verilmiştir. Altın madalyayı kazanan yarışmacıyı böl ve yönet algoritmasıyla bulun. Kaba kuvvet çözümle yapsaydınız karmaşıklık ne olurdu, daha mı iyi olurdu?

> **Çözüm (derste verilen):** Altın madalyayı kazanan en kısa süreyi koşandır; problem en küçük elemanı bulmaktır. Süreler önce tek bir birime (örneğin saniyeye) çevrilir. Böl ve yönet çözümü yukarıdaki `findMin` fonksiyonudur (ekrandan, 00:55:00): dizi tek eleman kalana kadar ikiye bölünür, geri dönüşte iki yarıdan gelen indislerden küçük değerli olan döndürülür; `main` içinde `A[findMin(0, N-1, A)]` sonucu verir. Diziyi sıralamak gereksizdir. Kaba kuvvet çözüm diziyi bir kez dolaşır ve $O(n)$'dir, $O(n^2)$ değildir.

**Soru 2** (derste sözlü, 01:01:44; ara sınav sorusu): Bir hash tablosu kullanarak iki dizinin kesişimini bulun. (Sorudaki ipucu: A dizisinin elemanlarını tabloya yerleştirin, B dizisinin elemanlarını tabloda arayın.)

> **Çözüm (derste verilmedi):** Tablo uzunluğu $m$, A'nın uzunluğunun yaklaşık iki katı seçilir. A'nın her elemanı hash fonksiyonuyla (örneğin $h(k)=k \bmod m$, çarpışmada doğrusal yoklama) tabloya yerleştirilir. Ardından B'nin her elemanı aynı fonksiyonla tabloda aranır: boş göze gelinirse eleman A'da yoktur; eleman bulunursa kesişime eklenir. A'nın $n$, B'nin $m'$ elemanı için ortalama süre $O(n+m')$ olur.

## Dersin Toparlaması

Bu oturumda önce son ödevin konusu olan kullanıcı tabanlı işbirlikçi filtreleme anlatıldı. Varyans ve kovaryans hatırlatılarak, iki kullanıcının ortak okudukları kitaplara verdiği puanların ortalamadan sapmaları üzerinden Pearson korelasyonu ile benzerlik ölçüldü. Her yeni kullanıcı için en benzer üç eski kullanıcı seçilip okunmamış kitaplar için tahmini puan hesaplanıyor ve en yüksek tahmini alan kitap öneriliyor. Hesabın özünün ortalama, fark ve çarpım gibi temel işlemler olduğu, algoritmik bir zorluk içermediği vurgulandı.

İkinci bölümde ara sınavdaki hatalar üzerinden iki temel konu tekrar edildi. En küçük elemanı bulmak için sıralamaya gerek yoktur; kaba kuvvet çözüm $O(n)$'dir ve böl ve yönet çözümü diziyi tek eleman kalana kadar ikiye bölüp küçük olanın indisini geri döndürür. Hash tablosunun uzunluğu ise yerleştirilecek eleman sayısının yaklaşık iki katı seçilmelidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
