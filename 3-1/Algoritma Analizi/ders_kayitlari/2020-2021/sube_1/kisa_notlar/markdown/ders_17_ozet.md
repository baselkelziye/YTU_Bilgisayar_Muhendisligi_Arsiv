# Ders 17 Çalışma Özeti

## Genel Konular

- Ayrık zincirleme (separate chaining)
  - Açık adreslemeden (open addressing) sonraki ikinci çakışma çözümüdür. Çakışma olduğunda boş göz aranmaz; aynı adrese düşen elemanlar bağlı liste (linked list) ile uç uca eklenir.
  - Tablo bir adres tablosudur: her göz, o adrese düşen elemanların oluşturduğu zincirin (chain) başlangıç adresini (head) tutar.
  - Tablo uzunluğu $M$ eleman sayısı $N$'den küçük seçilir. $M$ çok büyük olursa yer boşa gider, çok küçük olursa zincirler uzar. Derste uygun değer olarak $M \approx N/5$ verildi (ekrandan, 01:05:00).
  - Tahtadaki örnek (ekrandan, 00:10:00): 11 anahtarı 4. göze yerleşir (düğüm 1500 adresinde, next = NULL). Sonra 8 de 4. adresi üretir; 8 için yeni düğüm (1000 adresinde) açılır, tablonun head'i 1000 olur, 8'in next'i 1500'ü (11'i) gösterir.
- Ayrık zincirleme için C veri yapısı (ekrandan, 00:10:00)
  - `struct node { int key; char name[40]; struct node *next; };`
  - `struct hash { struct node *head; int count; };`
  - Tablo: `struct hash *hashTable = NULL;`, `main` içinde `hashTable = (struct hash *) calloc(M, sizeof(struct hash));` ile $M$ gözlük, başlangıçta sıfırlanmış bir "bağlı liste dizisi" oluşturulur.
  - `count` zincirdeki eleman sayısıdır. Zorunlu değildir; zincir bir eşiği geçince yeniden özetleme (rehash) kararı vermek için kullanılabilir.
- Ekleme (`insertToHash`) ve düğüm oluşturma (`createNode`) (ekrandan, 00:20:00 ve 00:25:00)
  - `hashIndex = key % M;` ($M$ global tanımlı).
  - `createNode` ile yeni düğüme yer alınır (`malloc(sizeof(struct node))`), alınamadıysa kontrol edilir, `key` ve `name` kopyalanır, `next = NULL` yapılır, düğümün adresi döndürülür.
  - Göz boşsa (`!hashTable[hashIndex].head`): head yeni düğüm olur, `count = 1`.
  - Göz doluysa yeni düğüm zincirin başına eklenir: `newNode->next = hashTable[hashIndex].head;`, sonra head yeni düğüm olur ve `count` bir artar. Zincirin sonuna eklemek gereksiz yere zinciri dolaşmak demektir.
- Açık adreslemede silme sorunu ve DELETED/EMPTY bayrağı (ekrandan, 00:35:00 - 00:45:00)
  - $M = 5$, doğrusal yoklama: 3 → 3. göz, 8 → 3 dolu olduğu için 4. göz, 13 → 3 ve 4 dolu, 0. göze yerleşir.
  - Arama: 8 için önce 3. göze, sonra 4. göze bakılır ve bulunur. 11 için $11 \bmod 5 = 1$; 1. göz boş olduğundan 11 tabloda yoktur.
  - 3 silinip göz boş bırakılırsa 8 aranırken 3. gözde durulur ve "8 yok" denir. 8'i yukarı çekmek de çözüm değildir, altındaki bütün elemanları yeniden kontrol etmek (rehash) gerekir.
  - Çözüm: her göze bir bayrak (flag) değişkeni eklenir. Hiç kullanılmamış göz EMPTY, silinmiş göz DELETED olur. Aramada DELETED görülürse devam edilir, EMPTY görülürse durulur.
- Ayrık zincirlemenin avantajı
  - Silme hiçbir şeyi bozmaz; düğüm zincirden çıkarılır. Çok silme yapılan uygulamalarda açık adresleme etkin değildir.
- Hashing analizi (ekrandan, 00:50:00 ve 00:55:00)
  - Doluluk oranı (load factor) $\alpha = N/M$: $\alpha = 0$ boş tablo, $\alpha = 1$ tamamen dolu tablo.
  - Bir gözün dolu olma olasılığı $\lambda$, boş olma olasılığı $1-\lambda$. Boş yer ilk denemede bulunmazsa ikincide bulunma olasılığı $\lambda(1-\lambda)$, üçüncüde $\lambda^2(1-\lambda)$, $k$. denemede $\lambda^{k-1}(1-\lambda)$. Bu bir geometrik seridir.
  - Doğrusal yoklamada beklenen deneme (probe) sayısı tablosu: 0,1 → 1,11; 0,2 → 1,28; 0,3 → 1,52; 0,4 → 1,89; 0,5 → 2,5; 0,6 → 3,62; 0,7 → 6,06; 0,8 → 13; 0,9 → 50,5.
  - Sonuç: açık adreslemede $M \approx 2N$ seçilir. Ortalama durumda ekleme ve arama $O(1)$'dir.
- Tablo uzunluğu neden asal sayı? (ekrandan, 01:00:00)
  - Anahtarlar 64, 100, 128, 200, 300, 400, 500 ve $M = 8$ iken $key \bmod 8$ yalnız 0 ya da 4 çıkar; anahtarlar ortak bölenlerde birleşip sürekli çakışır.
  - $M = 11$ (asal) iken adresler 9, 1, 7, 2, 3, 4, 5 olur; hiç çakışma olmaz.
- Yeniden özetleme (rehash)
  - Doluluk oranı yaklaşık %70-80'i geçince yeni, daha büyük bir tablo açılır ve bütün elemanlar yeniden yerleştirilir. Yeni tablo uzunluğu da asal seçilir.
- Hash'e yönelik hizmet engelleme (denial of service) saldırısı
  - Saldırgan hash fonksiyonunu öğrenip hepsi aynı adresi üreten anahtarlar gönderir; ayrık zincirlemede tek bir uzun zincir oluşur ve erişim süresi $N$'e çıkar.
  - Önlem: çalışma zamanında birkaç hash fonksiyonu arasından rastgele seçim yapmak (farklı tablo uzunluğu, çift özetlemede farklı adım gibi).
- Hashing uygulamaları
  - Yazım denetleyici (kelime sözlükte var mı), tarayıcıda gidilen URL'ler, spam filtresi (IP adresi anahtar), kredi kartı sahtecilik tespiti (çalıntı kart numaraları tablosu), arama motorlarında kelimeden doküman listesine erişim.
- Dinamik programlama (dynamic programming) giriş (ekrandan, 01:35:00 ve 01:40:00)
  - 1950'lerde Richard Bellman geliştirdi. "Programming" sözcüğü bilgisayar programından değil planlamadan (planning) gelir.
  - Böl ve yönetten farkı: alt problemler bağımsız değil, birbirine bağlıdır (subproblems are dependent); bir alt problemin sonucu başka alt problemlerde yeniden kullanılır.
  - Fibonacci: $fib(n) = fib(n-1) + fib(n-2)$. Özyinelemeli çözüm aynı değerleri defalarca hesaplar ($fib(6)$ için $fib(4)$ iki kez, $fib(3)$ üç kez); işlem sayısı üsteldir (yaklaşık $1{,}6^n$).
  - Dinamik programlama çözümü: `for i = 2 to n do f[i] = f[i-1] + f[i-2];` Önceki sonuçlar bir dizide saklanır.
  - Adımlar: 1) alt problemleri tanımla, 2) rekürans bağıntısını yaz, ilk (başlangıç) değerleri belirle, 3) sonuçları dizi ya da matriste saklayarak çöz.
- 0-1 sırt çantası problemi (0-1 knapsack) (ekrandan, 01:50:00)
  - Kapasitesi $W$ olan bir çantaya, ağırlıkları $w_1,\dots,w_n$ ve değerleri $v_1,\dots,v_n$ olan $n$ eşyadan, kapasiteyi aşmadan toplam değeri en büyük olacak şekilde seçim yapılır. 0 = alma (abandon), 1 = al (select).
  - Kaba kuvvet (brute force, exhaustive search) $2^n$ kombinasyon dener.
  - Dinamik programlamada bilgi bir matriste tutulur: satır $i$ (kaçıncı eşyaya gelindiği), sütun $w$ (çantadaki ağırlık), değer $P[i,w]$ (o noktadaki en büyük kazanç). Konu bir sonraki derste sürecek.

## Hocanın Özellikle Vurguladığı Kısımlar

- Silme için bayrak kullanımı
  - Açık adreslemede silinen göz boş bırakılamaz; DELETED ile EMPTY ayrımı yapılmazsa daha önce çakışma yüzünden aşağı kaymış elemanlar bulunamaz.
  - DELETED bir gözün altında doğru yerleşmiş tek bir eleman görmek, o gözü EMPTY yapmak için yeterli değildir; daha aşağıda çakışmadan kaymış elemanlar olabilir.
- Dinamik bellek kontrolü
  - `malloc` sonucunun kontrolü ihmal edilmemelidir; güvenlik açısından kritik yazılımlarda (uzay, bankacılık) "olmaz" denen hatalar da kontrol edilir.
- Dinamik ayrılan adres ile yerel dizi farkı
  - `malloc` ile alınan yer yığın (heap) bölgesindedir ve program boyunca geçerlidir, adresi döndürülebilir. Fonksiyon içindeki yerel bir dizinin adresini döndürmek sözdizimi hatası vermez ama fonksiyondan çıkınca o bölge başkasına verilebilir; program bazen çalışır, bazen çalışmaz.
- Tablo uzunluğu kuralları
  - Açık adreslemede $M \approx 2N$, ayrık zincirlemede $M \approx N/5$, her durumda $M$ asal; doluluk %70-80'i geçince rehash.
- $O(1)$'in kaynağı
  - Hash'te ortalama arama ve ekleme karmaşıklığının $N$'e bağlı olmaması olasılık hesabıyla kanıtlanır: $\lambda = 0{,}5$ iken ortalama 2,5 deneme yeterlidir.

## Kısa Tekrar Notları

- Ayrık zincirleme: aynı adrese düşenler bağlı listede; yeni eleman zincirin başına eklenir.
- `struct hash { struct node *head; int count; }`, tablo `calloc(M, sizeof(struct hash))`.
- Açık adreslemede silme: EMPTY'de dur, DELETED'de devam et.
- Ayrık zincirlemede silme sorun değildir.
- $\alpha = N/M$; $\lambda$ = dolu olma olasılığı; $k$. denemede boş bulma olasılığı $\lambda^{k-1}(1-\lambda)$.
- Doğrusal yoklama: $\lambda = 0{,}5$ → 2,5 deneme; $0{,}8$ → 13; $0{,}9$ → 50,5.
- Ortalama durumda ekleme ve arama $O(1)$; sıralı aramada $n$, ikili aramada $\log n$.
- Tablo uzunluğu asal: mod ile çalışan hash'te ortak bölenlerden doğan çakışmaları azaltır.
- Rehash: daha büyük, yine asal uzunlukta tabloya bütün elemanları yeniden yerleştirme.
- DoS saldırısına karşı rastgele seçilen hash fonksiyonu.
- Dinamik programlama: bağımlı alt problemler, rekürans + başlangıç değerleri + tabloda saklama.
- Özyinelemeli Fibonacci üsteldir; dizi ile hesap doğrusal.
- 0-1 knapsack: kaba kuvvet $2^n$; DP matrisi $P[i,w]$.

## Detaylı Açıklamalar

- **Ayrık zincirleme ve ekleme.** Açık adreslemede bir çakışmada tablonun içinde boş göz aranırken, ayrık zincirlemede tablo yalnızca zincir başlarını tutar. Bir anahtar hash fonksiyonundan geçip bir adres üretir. O gözün head'i NULL ise zincir yeni başlar: yeni düğümün adresi head'e yazılır ve count 1 olur. Head doluysa yeni düğümün next alanı mevcut head'i gösterir ve head yeni düğüm olur. Böylece ekleme zincir uzunluğundan bağımsız sabit sürede yapılır. Derste yalnızca ekleme kodlandı; arama ve silmenin bağlı liste bilgisiyle benzer biçimde yazılabileceği söylendi.

  ```c
  void insertToHash(int key, char name[]) {
      int hashIndex;
      hashIndex = key % M;              /* M global */
      struct node *newNode = createNode(key, name);
      if (!hashTable[hashIndex].head) {
          hashTable[hashIndex].head = newNode;
          hashTable[hashIndex].count = 1;
      } else {
          newNode->next = hashTable[hashIndex].head;
          hashTable[hashIndex].head = newNode;
          hashTable[hashIndex].count++;
      }
  }

  struct node *createNode(int key, char name[]) {
      struct node *newNode;
      newNode = (struct node *) malloc(sizeof(struct node));
      /* kontrol: yer ayrılamadıysa uyarı ver ve dön */
      newNode->key = key;
      strcpy(newNode->name, name);
      newNode->next = NULL;
      return newNode;
  }
  ```

  Kodun ilk satırları ve `createNode` ekrandan alındı (00:20:00, 00:25:00); `else` dalının son iki satırı altyazıdaki anlatımdan kuruldu.

- **Silme bayrağı neden gerekli?** $M = 5$ tabloda 3, 8 ve 13 doğrusal yoklamayla 3., 4. ve 0. gözlere yerleşir. 3 silinip göz boşaltılırsa, 8'in aranması 3. gözde boşluk görünce biter. Bu yüzden her göz için bir tam sayı bayrak tutulur: EMPTY hiç kullanılmamış göz, DELETED silinmiş göz. Arama EMPTY'de durur, DELETED'de sürer. Sınav sorusundaki iki durum: DELETED gözün altı EMPTY ise o göze daha önce hiç çakışma yüzünden taşma olmamıştır, DELETED güvenle EMPTY yapılabilir. Altında doğru yerleşmiş bir eleman varsa bu yeterli değildir; daha aşağıda o gözden taşmış elemanlar olabilir.

- **Analiz.** Rastgele (düzgün) dağılmış anahtarlarda bir gözün dolu olma olasılığı $\lambda$ ise, ilk $k-1$ göz dolu ve $k$. göz boş olma olasılığı $\lambda^{k-1}(1-\lambda)$'dır. Bu geometrik serinin açılımından beklenen deneme sayısı bulunur. Tablodaki değerler 0,5'e kadar 2'nin altında ya da çevresinde kalır, 0,6'dan sonra hızla büyür. Ortalama deneme sayısı $N$'e değil doluluk oranına bağlı olduğu için ortalama ekleme ve arama $O(1)$ sayılır.

  > **Ek bilgi (derste anlatılmadı):** Tablodaki değerler büyük olasılıkla Knuth'un doğrusal yoklama için verdiği başarısız arama/ekleme formülünden gelir: $\frac{1}{2}\left(1 + \frac{1}{(1-\lambda)^2}\right)$. Bu formül tablodaki bütün değerleri verir; $\lambda = 0{,}1$ için sonuç 1,117'dir (tahtada 1,11).

- **Asal tablo uzunluğu.** $h(key) = key \bmod M$ biçimindeki bir fonksiyonda anahtarlar ile $M$'nin ortak böleni büyükse anahtarlar az sayıda adreste toplanır. $M = 8$ iken 64, 128, 200, 400 adres 0'a; 100, 300, 500 adres 4'e gider. $M = 11$ iken adresler 9, 1, 7, 2, 3, 4, 5 olur.

  > **Ders sonrası not:** Hoca 4. adrese 300 ile 500'ün gittiğini söyledi; 100 de $100 \bmod 8 = 4$ olduğu için 4. adrese gider. Hoca ayrıca 200, 300, 400, 500 ile 8'in en büyük ortak böleninin 4 olduğunu söyledi; doğrusu 300 ve 500 için 4, 200 ve 400 için 8'dir (python ile kontrol edildi).

- **Dinamik programlama.** Özyinelemeli Fibonacci'de `fibonacci(6)` çağrısı `fibonacci(5)` ve `fibonacci(4)`'ü, `fibonacci(5)` de yine `fibonacci(4)` ve `fibonacci(3)`'ü çağırır; özyinelemenin belleği olmadığından aynı değerler tekrar tekrar hesaplanır. Dinamik programlama bu sonuçları bir dizide saklar. Fibonacci için dizi şart değildir, iki değişken yeterlidir; örnek yalnızca rekürans bağıntısı kolay olduğu için seçildi.

- **0-1 sırt çantası.** Bir hırsızın 15 kg taşıyan çantasına "yükte hafif, pahada ağır" eşyaları seçmesi örneği verildi. Her eşya için al/alma kararı vardır; bütün kombinasyonları denemek $n$ eşya için $2^n$ olasılık demektir (5 eşyada 32). Karar için hem ağırlık hem değer, ayrıca hangi eşyada olunduğu bilinmelidir; bu yüzden tek boyutlu dizi yetmez, matris gerekir. Satırlar eşyaları, sütunlar ağırlığı, hücreler o andaki en büyük kazancı $P[i,w]$ gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
