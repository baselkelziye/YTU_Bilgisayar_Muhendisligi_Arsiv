# Ders 24 Genişletilmiş Notu: Soru-Cevap: Matris Transpozu, Sıralı Diziye Ekleme ve Problem Üretme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi
- 2. C Dilini Öğrenmek İçin Kaynak Seçimi
- 3. Neden break, continue ve goto Kullanmıyoruz
- 4. Linux Üzerinde Çalışarak Kendini Geliştirmek
- 5. Matris Transpozu Akışındaki İki Hata
- 6. Günlük Hayattan Algoritma Problemi Üretmek
- 7. Dizilerle Problem Üretmek ve Sıralı Diziye Ekleme
- 8. Derleme Zamanı, Çalışma Zamanı ve Hata Türleri
- Örnek Sorular

## 1. Dersin Biçimi

Bu oturumda yeni bir konu anlatılmadı. Hoca dersin başında yeni bir şey işlemeyeceğini, öğrencilerin merak ettiği ve sormak istediği konulara cevap vereceğini söyledi. Bu yüzden notun akışı, sorulan soruların sırasını izler. Sınav düzeni, notlandırma oranları, mazeret ve bütünleme sınavları, yaz okulu gibi idari konular da konuşuldu; bunlar akademik olmadığı için bu nota alınmadı.

## 2. C Dilini Öğrenmek İçin Kaynak Seçimi

Bir öğrenci, derste C'nin bir kısmının öğrenildiğini, ara tatilde dili geliştirmek için internette nereye bakılabileceğini sordu. Hoca şu an için internete çok bakılmamasını önerdi. Gerekçesi, C'yi doğru düzgün kullanan insan sayısının bile az olmasıydı.

Hoca Türkçe kaynaklarda bugüne kadar bol hata gördüğünü söyledi: yanlış yazılan, eksik bırakılan, atlanan bir grup şey. Mümkün olduğunca yabancı kaynaklara yönelinmesini, ama orada da rastgele bir kaynağa gidilmemesini istedi. Sıradan birinin blogunda yazdığı kodlara bakarak kod yazmaya çalışmak doğru değildir. Bu kodlar genelde mühendislik açısından kötüdür: gelişigüzel yazılmış, mantığı ve sistematiği yerine oturmamış, bilgisayarın yapısı ve modeli açısından bakıldığında verimli olmayan kodlardır.

Hoca dönemin başında önerdiği eski bir C kitabını hatırlattı. Kitap 1970'lerin sonlarına ait, sonradan ikinci baskısı da yapılmış bir kitaptır. İyi tarafı, konuları yazılım mühendisliği açısından "bu şöyle olmalı, bunu şundan dolayı böyle yapıyoruz" diye anlatmasıdır. Zayıf tarafı ise bölümlerin sıralamasıdır; birden çok farklı bir yere atlayabilir. Derste ise öğrenciler daha yavaş ve daha korunaklı bir sırayla ilerletilir. <!-- BELİRSİZ: kitabın yazarı altyazıda "Margulis" diye geçiyor; doğru ad doğrulanamadı. -->

Korunaklı ilerlemenin nedeni şudur: C derleyicileri programcının yaptığı hatalarla pek ilgilenmez. Bu yüzden C'de her türlü hataya açık olunur ve her türlü tuhaflık ihtimal dahilindedir.

Derste daha sonra bir öğrenci ekranını paylaşarak bulduğu bir C kitabını sordu. Hoca kitabı tanımadığını söyledi. Bir kitabı tavsiye edebilmek için onu baştan sona okuyup kontrol etmiş olmak gerektiğini, bu yüzden kitap hakkında kesin bir şey söyleyemeyeceğini belirtti. Bulunan bir kaynaktan alınan bilgi, derste konuşulanların süzgecinden geçirilerek ve dikkatli kullanılırsa sorun değildir.

## 3. Neden break, continue ve goto Kullanmıyoruz

Hoca, C'nin tarihsel gelişimini hatırlattı: C yüksek seviyeli bir dildir, ama Assembly'den sonra gelen dillerdendir. Assembly'de kod yazan insanlar dışlanmasın, C'de de iş yapabilsinler diye dile bazı direktifler konmuştur.

Önceki derste bir öğrenci `break` ve `continue` hakkında sormuş, başka kaynaklardan okuyan öğrenciler "bunu kullansak olmaz mı" diye sormuştu. Hocanın cevabı açıktır: kullanmayın. İki gerekçesi vardır:

- Mantıklı ve makul değildir, sistematik düşünceye aykırıdır.
- Arka planda (derleyicinin) yapılan pek çok optimizasyonu bozar.

Hoca, internette herhangi bir problem için C kodu arandığında çıkan sonuçların büyük bir kısmında `goto`, `continue` ve `break` görüleceğini söyledi. Bu, kaynak seçiminde seçici olmak için bir sebep daha.

> **Hocanın vurgusu:** `break`, `continue` ve `goto` kullanılmaz. Tek istisna `switch` yapısındaki `break`'tir.

## 4. Linux Üzerinde Çalışarak Kendini Geliştirmek

Hoca, C ile ve genel olarak bilgisayar mühendisliğiyle ilgili kendini geliştirmek isteyenlere Linux'u kurcalamayı önerdi. Derste bir sanal makine (VM) kurulmuştu, ama öğrenciler şimdiye kadar korunaklı bir ortamdaydı. Önerdiği adımlar şunlardır:

- Bir yazılımı paket olarak hazır kurmak yerine kaynak kodunu indirmek, derleyip çalıştırılabilir (executable) hale getirmek ve sonra kurmak.
- Linux çekirdeğini (kernel) derlemeyi denemek.
- Çekirdek modüllerini açıp kapatmak, yeni modül yüklemek.
- Linux için modülün nasıl yazıldığına (hazır şablonu vardır), nasıl derlendiğine bakmak.

Hoca C'nin ilerideki dersler için önemini de anlattı. Sonraki dönemde bu dersin devamı niteliğinde bir derste yine akış, algoritma ve C görülecek. İkinci sınıftaki yapısal programlama dersinde önişlemcinin (preprocessor) makro kısmı, işaretçiler (pointer), dinamik bellek ayırma (dynamic memory allocation), yapılar (structure), dosya işlemleri ve fonksiyon işaretçileri konuşulacak. İşletim sistemi dersinde çoğunlukla Linux çekirdeğiyle ilgili projeler, ağ ile ilgili bir derste ise C üzerinde soket programlama yapılır. Bu yüzden C hakim olunması gereken bir dildir ve buna ulaşmak zaman ister; o zaman Linux'u kullanarak ve inceleyerek iyi değerlendirilebilir.

## 5. Matris Transpozu Akışındaki İki Hata

Bir öğrenci, daha önce hocaya e-postayla gönderdiği soruların cevabını sordu. Hoca öğrencinin gönderdiği çözümü ekranda açtı ve üzerinde çizerek anlattı. Bu bölüm o çözüm üzerindendir.

### 5.1 Problem ve öğrencinin akışı

Ekrandaki problem "Find transpose of given matrix", yani verilen bir matrisin transpozunu bulmaktır (ekrandan, 00:35:00). Öğrenci örnek olarak şu matrisi ve transpozunu yazmıştı:

```text
        | 1   8   6 |              | 1   4   7 |
    A = | 4  10   5 |        A^T = | 8  10  11 |
        | 7  11   4 |              | 6   5   4 |
```

Öğrenci yanına `A12 → A21`, `A13 → A31`, `A23 → A32` gibi eşleşmeleri yazmış, bunların köşegene göre ayna (mirror) olduğunu not etmişti. Ayrıca şu soruyu yazmıştı: "`A(i)(j) = A(j)(i)` yazmamda bir sorun var mı?"

Öğrencinin akışı şöyleydi (ekrandan, 00:35:00):

```text
START
  |
[ N, M ; A(N)(M) oku ]
  |
[ I <- 1 || 1 ]  bitiş N
  |
  [ J <- 1 || 1 ]  bitiş M
    |
    [ A(I)(J) = A(J)(I) ]
  (döngüler kapanınca)
[ A(J)(I) yazdır ]
  |
STOP
```

Hoca, öğrencinin ne yapmak istediğini bildiğini ama çizdiği yapının bununla örtüşmediğini söyledi. Yapılması gereken, elemanların köşegen ekseni boyunca karşılıklı yer değiştirmesidir. Bunun için köşegenin üst tarafını dolaşmak yeterlidir; üst taraf dolaşılırken yerler değişir ve iş biter.

### 5.2 Birinci hata: döngünün başlangıcı

Öğrencinin akışı iç döngüde de `1`'den başlayıp bütün matrisi ($N \times M$) dolaşıyordu. Hoca bunun yanlış olduğunu söyledi ve iç döngünün nereden başlaması gerektiğini sordu. Öğrenci bir sonraki konumdan başlaması gerektiğini söyledi. Hoca bunu `I`'nın bir fazlası olarak netleştirdi: iç döngü `J ← I + 1`'den başlar. Böylece:

- Birinci satırda ikinci sütundan başlanır.
- İkinci satırda üçüncü sütundan başlanır.
- Matris 5×5 olsaydı başlangıç aşağı doğru yine birer birer kayardı.

Her şey kendiliğinden kayar ve yalnız köşegenin üstündeki elemanlar ele alınır. Köşegendeki elemanlar ($A(i)(i)$) yer değiştirmez.

### 5.3 İkinci hata: atama yer değiştirme değildir

İkinci sorun `A(I)(J) = A(J)(I)` kutusudur. Öğrenci `A(I)(J)` ile `A(J)(I)`'nın yerini değiştirmek istiyordu, ama böyle bir işlem yoktur. Bu kutu yalnız `A(J)(I)`'nın değerini `A(I)(J)`'ye atar ve `A(I)(J)`'nin eski değeri kaybolur. Yapılması gereken üç adımlı bir değiş tokuştur (exchange):

```text
TMP     <- A(I)(J)
A(I)(J) <- A(J)(I)
A(J)(I) <- TMP
```

> **Hocanın vurgusu:** Tek bir operatörle iki değişkenin değerini değiştirme şansınız yok. Değiş tokuş geçici bir değişkenle yapılır.

### 5.4 Python ile kontrol

Ekrandaki matrisle üç durum denendi:

- Öğrencinin akışı (bütün matris, yalın atama): sonuç $\begin{pmatrix}1&4&7\\4&10&11\\7&11&4\end{pmatrix}$ olur. Alt üçgen üst üçgene kopyalanır ve matris simetrik hale gelir; transpoz bulunmaz.
- Bütün matris dolaşılıp her konumda değiş tokuş yapılırsa: her çift iki kez değiştirilir ve matris başlangıçtaki haline döner. Bu, döngünün `I + 1`'den başlamasının neden şart olduğunu gösterir.
- İç döngü `J ← I + 1`'den başlar ve değiş tokuş yapılırsa: sonuç ekrandaki $A^T$ ile aynıdır.

> **Ders sonrası not:** Aynı matris içinde yerinde (in-place) transpoz yalnız kare matriste ($N = M$) mümkündür. Öğrencinin akışı `N` ve `M`'yi ayrı okuyor. $N \neq M$ ise transpoz $M \times N$ boyutlu ayrı bir matrise yazılmalıdır (`B(J)(I) ← A(I)(J)`). Bu ayrıntı derste konuşulmadı.

Aynı öğrenci, bir diziye eleman eklemek için elemanları birer kaydırmak gerektiğini sorduğu soruyu da anladığını söyledi. Bu konu 7. bölümde hocanın kendi anlatımıyla yer alıyor.

## 6. Günlük Hayattan Algoritma Problemi Üretmek

Öğrencinin kitap sorusunun ardından hoca, algoritma üzerinde çalışmak için pratik problem arayanların bunları kendileri ortaya çıkarabileceğini anlattı. Problem ortaya atmak hayal gücü de gerektirmez; etrafa bakınca her yerde bir problem görülür. Verdiği örnekler:

- **Kargo kamyonları.** Kargo şubesinin arkasında koliler üst üste yığılmıştır. Kamyon yanaştırılır, eline ne geçerse sırayla içeri atılır; kolilerin ağır mı büyük mü olduğuna bakılmaz. Bir mahalleye gidecekler bir kamyona, diğerine gidecekler başka kamyona doldurulur. Problem: boyutları ya da ağırlıkları bir dizi içinde sırayla verilen kolilerin kaç kamyona sığacağını hesaplayan algoritma.
- **Banka ya da mağaza kuyruğu.** Bankaya ya da mağazaya aynı anda en fazla belli sayıda kişi girebilir. Belli zamanlarda gelen kişi sayısı bir dizide verilir, bankanın kapasitesi bellidir. Problem: bu süre boyunca kapıda en fazla kaç kişilik kuyruk oluşur?
- **Saat açısı.** Verilen bir saat için akrep ile yelkovan arasındaki açının kaç derece olduğunu bulmak.
- Ağ programlamaya geçildiğinde taksi durağı simülasyonu gibi daha büyük problemler de yapılabilir.

Bir öğrenci saat açısı için bir formül olduğunu söyledi: saat çarpı 60, eksi 11 çarpı dakika, bölü 2. Hoca bunun kullanılabileceğini, formülsüz de çözülebileceğini söyledi. Bir problem tek bir adımda, tek bir formülle çözülse bile, bir problem olduğu ve çözüm için bir şey üretmek gerektiği gerçeği değişmez. Hoca ilk çözülen algoritmalardan ATM (para makinesi) problemini hatırlattı: makinenin parayı hangi banknotlarla vereceği. O problemde ne `if` vardı ne de başka bir yapı; tek bir işlem kutusunda alt alta yazılan bir dizi işlem vardı. Formülle çözümün bundan bir farkı yoktur.

> **Ek bilgi (derste anlatılmadı):** Yelkovan dakikada $6^\circ$, akrep ise dakikada $0{,}5^\circ$ döner. Bu yüzden açı $|30 \cdot \text{saat} - 5{,}5 \cdot \text{dakika}|$ olur; bu, öğrencinin söylediği $\dfrac{|60 \cdot \text{saat} - 11 \cdot \text{dakika}|}{2}$ ile aynıdır. Sonuç $180^\circ$'yi geçerse küçük açı $360^\circ$'den çıkarılarak bulunur.

**Soru:** Örnek problemler ve çözümlerini içeren ayrı bir kaynak var mı? **Cevap:** Hayır. Bu dersi farklı dönemlerde farklı kişiler verse de hepsi aynı ekolden yetiştiği için benzer problemler sorulur ve bu problemlerin bir kitabı yoktur; hocaların ders notlarında birikmiş halde durur. Ama problem üretmek zor değildir (7. bölüm). Çözümler için hocaya e-postayla akış ya da soru gönderilebilir; hoca anlamayana nerede takıldığını anlatır, gönderilen akışı düzeltip geri yollar.

## 7. Dizilerle Problem Üretmek ve Sıralı Diziye Ekleme

Hoca, derste yapılanları hatırlattı: dizi sıralandı, çünkü sıralama standart problemlerden biridir; eleman arandı, çünkü arama (search) bilgisayardaki temel problemlerden biridir. Ama dizilerle yapılabileceklerin sınırı yoktur. Örnekler:

- Dizinin tek elemanlarını başa, çift elemanlarını sona koymak.
- Bir dizinin başka bir dizi içinde geçip geçmediğini bulmak.
- İki sıralı diziyi yeni bir dizide sıralı olarak birleştirmek (derste yapılmıştı).

### 7.1 Sıralı diziye eleman yerleştirme

Hoca, bir öğrencinin sorduğu sorunun aslında iki sıralı diziyi birleştirme probleminin tek adımlık bir versiyonu olduğunu söyledi. Elde sıralı bir dizi vardır ve verilen bir eleman bu dizide doğru yere yerleştirilmek istenir. Dizi `3, 5, 7, 9, 11` olsun. Değeri 7 ile 9 arasına düşen bir eleman geldiğinde bu eleman 7 ile 9'un arasına girmelidir. <!-- BELİRSİZ: eklenen elemanın değeri altyazıda kesik. -->

Bunun için:

- Önce dizi genişletilir: yerleşilecek konumdan sonraki elemanlar (burada 9 ve 11) birer konum sağa kaydırılır.
- Arada bir boşluk oluşur.
- Yeni eleman bu boşluğa yazılır.

```text
önce     :  3   5   7   9  11
kaydırma :  3   5   7   _   9  11
sonra    :  3   5   7   x   9  11      (7 < x < 9)
```

> **Ek bilgi (derste anlatılmadı):** Kaydırma sondan başa doğru yapılmalıdır (önce 11 bir sağa, sonra 9). Baştan sona kaydırılırsa her eleman bir sonrakinin üstüne yazılır ve değerler kaybolur. Bu, transpozdaki değiş tokuşla aynı türden bir "üzerine yazma" tuzağıdır.

## 8. Derleme Zamanı, Çalışma Zamanı ve Hata Türleri

Bir öğrenci akışta ya da kodda sonucu yanlış çıkaran hataların nasıl değerlendirildiğini sordu ve "kodu derleyince sonuç yanlış çıkıyor" dedi. Hoca önce bu ifadeyi düzeltti.

### 8.1 Derleme ile çalıştırma farkı

Derleme (compilation) pasif bir durumdur. Kod o sırada aktif olarak çalışmaz ve bir sonuç üretmez; yalnız kodun dilin sözdizimi (sentaks) kurallarına uyup uymadığı görülür. Sonucun doğru olup olmadığı derleme zamanında (compile time) değil, çalışma zamanında (runtime) görülür.

### 8.2 Hataların ağırlığı

Hoca bazı hataların affedilmez, bazılarının ise önemsiz ve kabul edilebilir olduğunu söyledi. Verdiği örnekler:

- Son `printf`'ten sonra noktalı virgülü unutmak küçük bir hatadır.
- `scanf` ile tamsayı okurken değişkenin önündeki `&` işaretini unutmak bir hatadır ama programı tümden geçersiz kılmaz.
- `#include <stdio.h>` yazıp değişken tanımlayıp `printf` ve `scanf` satırlarını yazmaya başlamak, ama `main` fonksiyonunu hiç yazmamak ciddi bir hatadır.
- C'de olmayan veri tipleri (`string`, `boolean` gibi) tanımlamak, kodun başka bir programlama dilinde yazıldığını gösterir.
- Akışta bir sayacı ilklendirmeyi (ona sıfır atamayı) unutmak, akışın geri kalanı doğru olsa bile akışın düzgün çalışmamasına yol açar.

Hoca C kodunda genelde tek bir hata değil bir grup hata yapıldığını da ekledi.

### 8.3 Akış sembolleri ve işlem kutusu kuralı

> **Hocanın vurgusu:** Akışta yalnız derste gösterilen semboller kullanılır. İşlem kutusuna üstten girilir, alttan çıkılır. Kutuya soldan girip hem üstten hem sağdan çıkan bir çizim kabul edilemez.

Hoca transpoz sorusundaki çizim için de benzer bir şey söyledi: akışlarda kullanılan şekil sayısı azdır, şekillerin nasıl çizildiği ve neyin nereye gittiği bellidir; bunların doğru çizilmesi beklenir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): Verilen bir matrisin transpozunu bulan akışı çiziniz. Bir öğrenci akışında döngü gövdesine `A(I)(J) = A(J)(I)` yazmış ve "bunu yazmamda bir sorun var mı?" diye sormuştur. Örnek matris:

```text
    | 1   8   6 |
A = | 4  10   5 |
    | 7  11   4 |
```

> **Çözüm (derste verildi, 00:35:24-00:37:17):** İki sorun var. (1) İç döngü `1`'den değil `I + 1`'den başlamalıdır; yalnız köşegenin üstü dolaşılır. (2) `A(I)(J) = A(J)(I)` yer değiştirme değil atamadır; `TMP ← A(I)(J)`, `A(I)(J) ← A(J)(I)`, `A(J)(I) ← TMP` yapılmalıdır. Sonuç (python ile doğrulandı):
>
> ```text
>       | 1   4   7 |
> A^T = | 8  10  11 |
>       | 6   5   4 |
> ```

**Soru 2** (ekrandan, 00:35:00): "Sum of right diagonals of a matrix", yani bir matrisin sağ köşegeninin elemanlarının toplamı. Soru aynı sayfanın altında görünüyor, derste konuşulmadı. <!-- BELİRSİZ: "right diagonal" ifadesinin ters köşegen (sağ üstten sol alta) anlamında kullanıldığı varsayıldı. -->

> **Çözüm (derste verilmedi):** $N \times N$ matriste ters köşegendeki elemanlar `A(I)(N + 1 - I)` biçimindedir (1'den başlayan indislerle). `TOP ← 0` ile başlanır, `I ← 1 || 1` (bitiş `N`) döngüsünde `TOP ← TOP + A(I)(N + 1 - I)` yapılır, döngü bitince `TOP` yazdırılır. Tek döngü yeterlidir; iki döngüyle bütün matrisi dolaşıp `I + J = N + 1` koşulunu sınamak da doğru sonuç verir ama gereksiz iş yapar.

**Soru 3** (derste sözlü, 00:53:06): Verilen bir saat için akrep ile yelkovan arasındaki açıyı bulan algoritma.

> **Çözüm (derste bir öğrenci formülü söyledi, hoca kabul etti, 00:54:02):** $\theta = \dfrac{|60 \cdot \text{saat} - 11 \cdot \text{dakika}|}{2}$ derece. Python ile denendi: 3:00 için $90^\circ$, 3:30 için $75^\circ$ çıkar. Sonuç $180^\circ$'yi geçerse küçük açı $360^\circ - \theta$'dır (bu son adım derste söylenmedi).

**Soru 4** (derste sözlü, 00:51:18): Boyutları ya da ağırlıkları bir dizide sırayla verilen koliler, geliş sırasıyla kamyonlara yükleniyor. Kolilerin kaç kamyona sığacağını hesaplayan algoritmayı yazınız.

> **Çözüm (derste verilmedi):** Kamyon kapasitesi `K` ve koliler `A(1..N)` okunur. `SAYAC ← 1`, `DOLU ← 0` ile başlanır. Her koli için `DOLU + A(I) ≤ K` ise `DOLU ← DOLU + A(I)` yapılır; değilse yeni kamyona geçilir: `SAYAC ← SAYAC + 1`, `DOLU ← A(I)`. Döngü bitince `SAYAC` yazdırılır. Sıra değiştirilmediği için koliler sıralanmaz. Kapasiteden büyük bir koli varsa problem çözümsüzdür; bu durum ayrıca kontrol edilmelidir.

**Soru 5** (derste sözlü, 00:57:17): Sıralı bir diziye verilen bir elemanı, dizi sıralı kalacak biçimde yerleştiriniz (örnek dizi `3, 5, 7, 9, 11`).

> **Çözüm (derste anlatıldı, 00:57:44):** Elemanın gireceği konum bulunur, o konumdan sonraki elemanlar birer sağa kaydırılır, açılan boşluğa eleman yazılır. Kaydırmanın sondan başa yapılması gerektiği derste söylenmedi.

## Dersin Toparlaması

Bu oturum yeni konu içermeyen bir soru-cevap dersiydi. Akademik açıdan öne çıkan noktalar şunlardı: C öğrenirken güvenilir ve sistematik kaynaklara yönelmek; `break`, `continue` ve `goto`'dan (yalnız `switch` içindeki `break` hariç) kaçınmak; Linux'ta kaynak koddan derleme ve çekirdek modülleriyle uğraşarak pratik kazanmak. Matris transpozu örneğinde iki temel ders vardı: köşegene göre simetrik bir işlemde yalnız üst üçgeni dolaşmak, ve iki değeri değiştirmek için geçici değişken kullanmak. Sıralı diziye ekleme ise kaydırma mantığını ve iki sıralı diziyi birleştirme problemiyle bağlantısını gösterdi.

Hoca ayrıca algoritma pratiği için problemin her yerde bulunabileceğini; kargo kamyonu, banka kuyruğu, saat açısı ve dizi problemleri gibi örneklerin kolayca türetilebileceğini anlattı. Son olarak derlemenin yalnız sözdizimini denetlediğini, sonucun çalışma zamanında doğrulandığını ve hataların ağırlığının farklı olduğunu vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
