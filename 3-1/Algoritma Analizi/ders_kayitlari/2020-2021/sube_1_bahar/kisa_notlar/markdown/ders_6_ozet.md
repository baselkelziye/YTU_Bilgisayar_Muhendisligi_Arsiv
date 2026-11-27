# Ders 6 Çalışma Özeti

## Genel Konular

- Arama işlemleri ve karmaşıklıkları
  - Bilinen arama yöntemleri: doğrusal arama (sıralı ya da sırasız dizi), ikili arama (sıralı dizi), interpolasyon araması (sıralı ve düzgün dağılımlı dizi), ikili arama ağacı (BST) ve hashing (ekrandan, 00:10:00).
  - Arama (S), ekleme (I) ve silme (D) işlemlerinin en kötü ve ortalama durum maliyetleri bir tabloda karşılaştırıldı (ekrandan, 00:15:00). Bu yapıların en iyisi bile $\log n$ düzeyindedir; hashing ile bu işlemler ideal durumda $O(1)$'e indirilmek istenir.
  - Sırayla eklenen 4, 5, 6, 7, 8 değerleri BST'yi bağlı listeye dönüştürür; dengesiz ağaçta işlemler $n$ adıma çıkar.
- Hashing'in temel fikri
  - Doğrudan adres tablosu (direct address table): dizide `a[3]` gibi indisle doğrudan erişim. Hashing bu fikri genelleştirir (ekrandan, 00:20:00).
  - Hashing bir $\langle key, value\rangle$ eşleştirmesidir: key bir hash fonksiyonundan geçer, bir adres (indis) üretilir ve değer hash tablosunda bu adreste saklanır.
  - Key, nesneyi ayırt eden tekil (unique) bir tanımlayıcıdır (öğrenci numarası, kimlik numarası gibi). Çakışmayı (collision) ne kadar azaltırsa o kadar iyidir.
- Hash fonksiyonunun özellikleri
  - Hesaplaması ve gerçeklemesi kolay olmalı; maliyeti, yerini aldığı arama yapılarının maliyetini geçmemeli.
  - Tutarlı (consistent) olmalı: aynı key her zaman aynı indisi vermeli.
  - Adresleri düzgün (uniform) dağıtmalı; bunun için genellikle asal sayılar kullanılır. $M = 10$ iken 3, 13 ve 23 aynı indise düşer.
  - Üç temel soru: tablo ne kadar büyük olmalı, hash fonksiyonu nasıl seçilmeli, çakışma nasıl çözülmeli? $M$ tablo boyutu, $N$ eleman sayısıdır.
- Yaygın hash fonksiyonları
  - Bölme yöntemi: $h(key) = key \bmod M$. Örnek $M = 7$: $25 \bmod 7 = 4$, $2 \bmod 7 = 2$, $4 \bmod 7 = 4$ (çakışma) (ekrandan, 00:30:00).
  - Çarpma yöntemi: $0 < A < 1$ sabiti ile $h(key) = \lfloor M \cdot ((key \cdot A) \bmod 1) \rfloor$, $A = (\sqrt{5}-1)/2 \approx 0.61803$. Örnek: $M = 10000$, $key = 123456$ için sonuç 41 (ekrandan, 00:35:00).
- Doğum günü paradoksu ve çakışma olasılığı
  - $k$ kişinin farklı günlerde doğma olasılığı $\frac{364}{365}\cdot\frac{363}{365}\cdots\frac{365-(k-1)}{365}$ (ekrandan, 00:40:00).
  - Boyutu $M$ olan tabloda $k$ key için çakışmama olasılığı yaklaşık $e^{-k(k-1)/(2M)}$, çakışma olasılığı bunun 1'den farkıdır.
  - Yaklaşık 4 milyarlık adres uzayında 77.163 eklemeden sonra çakışma olasılığı %50'ye, yaklaşık 250.000 eklemeden sonra neredeyse %100'e çıkar.
- Farklı key türlerinden indis üretme
  - Tamsayı doğrudan kullanılır. Kayan noktalı sayı tamsayıya çevrilir: $x = 35.780$ için $\text{round}(x \cdot 10000) \bmod m$; $0 \le x \le 1$ için $\text{round}(x \cdot m)$ (ekrandan, 00:45:00).
  - String: karakter kodlarını toplamak "ELMA", "MALE", "ALME" gibi anagramlarda aynı sonucu verir. Karakterin konumu da hesaba katılmalıdır.
  - Horner yöntemi: $key = R^{L-1}\cdot str[0] + R^{L-2}\cdot str[1] + \dots + R^{0}\cdot str[L-1]$, $R$ asal (Java'da 31), sonra $key \bmod M$.
  - Bileşik key (ör. doğum tarihi): gün, ay ve yıl $R$'nin farklı kuvvetleriyle çarpılıp toplanır, sonra $\bmod M$ alınır.
- Çakışma çözümleri
  - Açık adresleme (open addressing, closed hashing) ve ayrı zincirleme (separate chaining, open hashing) (ekrandan, 01:10:00).
  - Doğrusal yoklama (linear probing): $h(key, i) = (h'(key) + i) \bmod M$. Örnek $M = 7$: 5 → 5, 12 → 6, 19 → 0 (ekrandan, 01:15:00).
  - Karesel yoklama (quadratic probing): $h(k, i) = (h'(k) + c_1 i + c_2 i^2) \bmod M$; derste $(h'(k) + i^2) \bmod M$ kullanıldı. Örnek: 9 → 2, 3 dolu → 6 (ekrandan, 01:25:00).
  - Çift hashing (double hashing): $h(k, i) = [h_1(k) + i \cdot h_2(k)] \bmod M$, $h_1(k) = k \bmod M$, $h_2(k) = 1 + (k \bmod K)$, $K < M$ (ekrandan, 01:30:00).
  - Ayrı zincirleme: tablo pointer tutar, aynı indise düşen elemanlar bağlı listede saklanır (ör. $\bmod 7$ ile 8, 15, 22 → 1). Başa ekleme $O(1)$ (ekrandan, 01:35:00).
  - Evrensel hashing (universal hashing): $h_1, \dots, h_n$ arasından rastgele bir hash fonksiyonu seçilir (ekrandan, 01:50:00).
- Doluluk oranı (load factor) ve başarısız arama
  - $\alpha = N/M$. Açık adreslemede $M > N$ olmalıdır; ayrı zincirlemede $M < N$ olabilir.
  - $\alpha$ büyüdükçe ortalama yoklama sayısı artar: 0,1 → 1,11; 0,5 → 2,5; 0,9 → 50,5. $\alpha = 0{,}5$ yani $M = 2N$ önerilir.
  - Başarısız arama: $P(\text{ilk hücre dolu}) = \alpha$, $P(\text{boş}) = 1-\alpha$, $P(\text{ilk iki dolu}) \approx \alpha^2$, $P(\text{yoklama 2. adımda biter}) = \alpha(1-\alpha)$ (ekrandan, 01:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Hashing'in amacı arama, ekleme ve silmeyi $O(1)$'e yaklaştırmaktır
  - Bölme yönteminde bir key en fazla bir bölme ve bir dizi erişimiyle bulunur; dizinin elemanlarına tek tek bakılmaz.
  - Ancak çakışma kaçınılmazdır ve hashing'in temel dezavantajıdır. Tablo dolmaya yaklaştıkça açık adreslemede en kötü durum $O(n)$'e gider.
- Hash fonksiyonu basit ve tutarlı olmalı
  - Karmaşık bir fonksiyon, BST ya da ikili aramadan daha pahalıysa hashing'in üstünlüğü kalmaz.
  - Tablo boyutu için asal sayı seçmek dağılımı düzgünleştirir.
- Doğrusal yoklamanın kümelenme (clustering) problemi
  - 5, 12, 19 gibi aynı indise düşen değerler tablonun 5-6-0 bölgesinde yığılır; dizinin diğer kısımları boş kalır. Tablo dairesel kabul edilir.
- Silme ve yeniden hashleme
  - Açık adreslemede silinen hücreye $-1$ gibi bir silindi işareti konur.
  - Tablo dolunca daha büyük bir tablo açılır; elemanlar aynı indislere kopyalanmaz, yeni tabloya göre yeniden hashlenir (rehashing).
- Ayrı zincirlemede başa ekleme
  - Bağlı listenin sonuna ekleme $O(n)$'dir; ya son düğümün adresi tutulmalı ya da başa eklenmelidir ($O(1)$).
  - Aramada en iyi durum $O(1)$, en kötü durum $O(n)$'dir. Liste yerine dengeli ağaç kullanılırsa en kötü durum $\log n$'e iner.

## Kısa Tekrar Notları

- Hashing: key → hash fonksiyonu → adres → hash tablosu.
- İyi hash fonksiyonu: hızlı, tutarlı, düzgün dağıtan; tablo boyutu tercihen asal.
- Bölme: $key \bmod M$. Çarpma: $\lfloor M((key\cdot A) \bmod 1)\rfloor$, $A \approx 0.618$.
- Çakışma olasılığı doğum günü paradoksuyla hızla büyür.
- String key'lerde karakter konumu hesaba katılır (Horner, $R = 31$).
- Açık adresleme: doğrusal $(h'+i)$, karesel $(h'+i^2)$, çift hashing $(h_1 + i\,h_2)$; hepsi $\bmod M$.
- Doğrusal yoklama kümelenme üretir.
- Ayrı zincirleme: her hücre bir bağlı liste; başa ekleme $O(1)$, arama en kötü $O(n)$.
- Evrensel hashing: fonksiyonlar arasından rastgele seçim.
- $\alpha = N/M$; açık adreslemede $M > N$, önerilen $\alpha \approx 0{,}5$.

## Detaylı Açıklamalar

- **Arama yapılarının karşılaştırılması.** Hoca aşağıdaki tabloyu öğrencilerle birlikte doldurdu (ekrandan, 00:15:00). Sırasız dizide ekleme sona doğrudan yapıldığı için en kötü durumda 1 adımdır. Sıralı dizide ise sırayı bozmamak için eklenecek yer bulunmalı ve elemanlar kaydırılmalıdır. BST'nin ortalama durumu, ağacın dengeye yakın olduğu durumdur.

| Yapı | En kötü S | En kötü I | En kötü D | Ortalama S | Ortalama I | Ortalama D |
|---|---|---|---|---|---|---|
| Sıralı (doğrusal) arama | $n$ | 1 | $n$ | $n/2$ | $n$ | $n/2$ |
| İkili arama | $\log N$ | $N$ | $N$ | $\log N$ | $N/2$ | $N/2$ |
| BST | $N$ | $N$ | $N$ | $\log N$ | $\log N$ | $\log N$ |
| Dengeli ağaç | $\log N$ | $\log N$ | $\log N$ | $\log N$ | $\log N$ | $\log N$ |

- Dengeli ağacın ortalama sütunu karede tamamlanmamıştı. Hoca bu sütunun da $\log n$ olduğunu sözlü söyledi. Doğrusal aramada ortalama ekleme ekranda $N$ yazıldı. <!-- BELİRSİZ: en kötü ekleme 1 iken ortalama eklemenin N yazılması tutarsız görünüyor; tekrar kontrolü yapılan ekleme kastedilmiş olabilir. -->
- **Çarpma yöntemi örneği.** $123456 \cdot A = 76300.0041151\ldots$ olur. Kesirli kısım $0.0041151$, $10000$ ile çarpılınca $41.151$, tabana yuvarlanınca 41 bulunur (ekrandan, 00:35:00). Hoca önce $M$ ile çarpıp sonra mod 1 aldı, ardından düzeltti: önce $(key \cdot A) \bmod 1$ alınır, sonra $M$ ile çarpılır.
  - Ders sonrası not: tahtadaki ara değer $A$'nın tam değeriyle $(\sqrt5-1)/2$ hesaplanmıştır. $A$ beş basamakta kesilip $0.61803$ alınırsa çarpım $76299.51168$ olur ve sonuç 5116 çıkar (python ile doğrulandı).
- **Horner yöntemiyle string key.** Hoca karakteri sayıya `s[i] - 'A' + 1` ile çevirdi. Kod (ekrandan, 00:50:00; döngü gövdesinin sonu sözlü anlatımdan):

```c
length = strlen(s);
hash = 0;
for (i = 0; i < length; i++)
    hash = R * hash + (s[i] - 'A' + 1);
hash = hash % M;
```

  - Ders sonrası not: hoca 'C' karakterinin ASCII kodunu 68 dedi; doğrusu 67'dir ('A' = 65). `'C' - 'A' + 1 = 3` sonucu değişmez.
  - "ELMA", "MALE" ve "ALME" için ASCII toplamı hepsinde 287'dir. Horner ($R = 31$) ile 160891, 388621 ve 41731 gibi farklı key'ler çıkar (python ile doğrulandı).
- **Açık adreslemede arama ve ekleme (ekrandan, 01:20:00).** Arama döngüsü:

```text
i = 0
h = key mod M
while (i < M AND hash[h] != key AND hash[h] != NULL)
    i = i + 1
    h = (h + 1) mod M
```

  - Döngüden sonra ekleme için: $i == M$ ise tablo doludur. Değilse ve `hash[h] == NULL` ise key bu adrese yazılır. Aksi halde key daha önce eklenmiştir.
- **Çift hashing örneği.** $M = 13$, key 14 için $h_1(14) = 14 \bmod 13 = 1$; $i = 0$ denemesinde 14 adres 1'e yerleşir. <!-- BELİRSİZ: hoca K = 5 seçip h2 değerini 4 olarak söyledi; formüle göre h2(14) = 1 + (14 mod 5) = 5 olur. -->
- **Ayrı zincirleme kodu (ekrandan, 01:40:00 ve 01:45:00).** `struct node` içinde `int key`, `char name[40]` ve `struct node *next`; `struct hash` içinde `struct node *head` ve eleman sayacı `int count` bulunur. Tablo `calloc(M, sizeof(struct hash))` ile açılır. Ekleme fonksiyonu indisi `key % m` ile bulur, liste boşsa düğümü baş yapar ve sayacı 1 yapar; değilse düğümü başa ekleyip sayacı artırır. Bu parçaları birleştiren ve `createNode` ile arama fonksiyonunu ajanın eklediği tam bir C programı `gcc -Wall` ile derlenip 8, 15 ve 22 eklenerek çalıştırıldı; liste `22 15 8` sırasıyla oluştu.
- **Doluluk oranı tablosu.** Hocanın verdiği ortalama yoklama sayıları ($\alpha$ = 0,1: 1,11; 0,2: 1,28; 0,3: 1,52; 0,5: 2,5; 0,9: 50,5) doğrusal yoklamada başarısız aramanın beklenen yoklama sayısı $\frac12\left(1+\frac{1}{(1-\alpha)^2}\right)$ ile uyuşur (python ile doğrulandı).
- **Doğum günü istatistiği.** Ders sonrası not: hoca çakışmama olasılığını $e^{-k(k-1)/M}$ diye söyledi; yaygın yaklaşım $e^{-k(k-1)/(2M)}$'dir. Altyazıda adres uzayı $2^{30}$ geçiyor; 77.163 değeri $M = 2^{32}$ (yaklaşık 4 milyar) ile uyuşur: $\sqrt{2\ln 2 \cdot 2^{32}} \approx 77163$ (python ile doğrulandı).
- **Evrensel hashing ve parolalar.** Hoca parola sıfırlama örneğiyle, sistemlerin parolayı açık metin değil hash'lenmiş olarak sakladığını, bu yüzden "şifremi unuttum" denince eskisinin gönderilemeyip yenisinin oluşturulduğunu anlattı. Evrensel hashing'i de bu güvenlik fikriyle ilişkilendirdi.
  - Ders sonrası not: evrensel hashing'in asıl amacı büyük olasılıkla güvenlik değil, kötü seçilmiş girdilere karşı beklenen $O(1)$ performansı garanti etmektir. Parola saklamada MD5, SHA-512 gibi kriptografik hash fonksiyonları kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
