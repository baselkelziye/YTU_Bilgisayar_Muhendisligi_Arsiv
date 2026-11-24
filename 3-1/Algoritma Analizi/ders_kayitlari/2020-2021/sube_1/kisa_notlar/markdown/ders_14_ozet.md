# Ders 14 Çalışma Özeti

## Genel Konular

- Açık adreslemede (open addressing) arama
  - Arama, ekleme (insert) ile aynı mantıkla yapılır: önce anahtarın adresi hesaplanır, sonra o gözden başlanarak sırayla bakılır.
  - Göz boşsa aranan eleman tabloda yoktur; göz doluysa ve aranan anahtar değilse bir sonraki göze geçilir, tablonun sonundan başa dönülür.
  - Örnek (ekrandan, 00:05:00): $m = 5$, sırasıyla 4, 3 ve 13 yerleştirilmiş. $13 \bmod 5 = 3$; 3. göz dolu (3), 4. göz dolu (4), başa dönülür ve 13 0. gözde bulunur. $x = 8$ aranırken 3, 4 ve 0. gözler dolu ve 8 değildir; 1. göz boş olduğu için 8 bulunamadı denir.
- Açık adreslemede silme (delete) problemi
  - 3 tablodan doğrudan silinip göz boşaltılırsa 13 arandığında 3. göz boş görünür ve arama yanlışlıkla "yok" sonucuyla biter.
  - Bir öğrencinin önerdiği elemanları geri kaydırmak doğru değildir: doğru yerindeki elemanlar da yer değiştirir, hash düzeni bozulur. Hash tablosu sıradan bir dizi gibi sırayla taranmaz.
  - Silme sonrasında bütün tabloyu yeniden yerleştirmek (rehash) mümkündür ama çok sayıda elemanda (örneğin bir milyon) tek silme için pahalıdır.
  - Genel yöntem: her göze bir durum bayrağı (flag) eklenir: Normal (dolu), Empty (boş), Deleted (silinmiş). Aramada Deleted gözde durulmaz, aramaya devam edilir; yalnız Empty gözde arama biter (ekrandan, 00:10:00).
- Doğrusal sınamada kümelenme (clustering)
  - Linear probing'de adım büyüklüğü 1'dir; yerine yerleşemeyen eleman bir sonraki göze geçer, onun yüzünden bir sonraki eleman da yerine yerleşemez ve arka arkaya dolu gruplar oluşur.
  - Örnek: $m = 5$ tabloda 3 3. göze, 8 de ($8 \bmod 5 = 3$) dolu olduğu için 4. göze yerleşir; sonra gelen 4 kendi gözü dolu olduğu için 0. göz de doluyken 1. göze kadar kayar.
- Çift hash (double hashing)
  - Formül (ekrandan, 00:25:00): $hash(key, i) = [hash_1(key) + i \cdot hash_2(key)] \bmod m$; $i$ deneme (step) numarasıdır.
  - $hash_2(key)$ doğrusal sınamanın adım büyüklüğünü (step size) verir; adım anahtara bağlı olduğu için kümelenme olasılığı azalır.
  - Örnek: $m = 13$, $hash_1(key) = key \bmod 13$, $hash_2(key) = key \bmod 11$. 96 5. göze, 79 1. göze yerleşir. 14 için $hash_1 = 1$ (dolu), $hash_2 = 3$; sırasıyla 4, 7, 10 ve $13 \bmod 13 = 0$. gözlere bakılır (ekrandan, 00:30:00).
  - $hash_2$'deki bölen (11) rastgele, tablo uzunluğundan küçük bir sayı seçilir.
- Tablo uzunluğunun seçimi ve doğum günü paradoksu
  - $N$ kişinin doğum günlerinin farklı olma olasılığı $\frac{365}{365} \cdot \frac{364}{365} \cdot \frac{363}{365} \cdots$ çarpımıdır (ekrandan, 00:35:00). 23 kişilik bir toplulukta iki kişinin doğum gününün aynı olma olasılığı yaklaşık %50'dir.
  - 32 bitlik hash değerlerinde yaklaşık 77.163 eklemeden sonra çakışma olasılığı %50'ye ulaşır; ders için verilen bir başka değer de 250.000 eklemede çakışmanın neredeyse kesin olmasıdır.
  - $k$ eleman için çakışma olasılığı yaklaşık $1 - e^{-k(k-1)/(2M)}$ olarak bulunur.
  - Sonuç: $N$ eleman için tablo uzunluğu $M \approx 2N$ seçilir (ekrandan, 00:40:00), tercihen $2N$'ye yakın bir asal sayı (10 eleman için 20 yerine örneğin 23).
- Yük faktörü (load factor)
  - $\alpha = N / M$ tablonun ne kadar dolu olduğunu gösterir.
  - $M$ çok büyükse boş yer kaybı, çok küçükse çakışmalar yüzünden aramada zaman kaybı olur. Açık adreslemede ideal $\alpha \approx 1/2$'dir.
- Kapalı hash (closed hashing, separate chaining)
  - Her göz bir bağlı listenin başını gösterir; aynı adrese düşen elemanlar o listeye eklenir. Bu yüzden $M < N$ alınabilir; istatistiksel çalışmalara göre $M \approx N/5$ yeterlidir (ekrandan, 00:45:00).
  - Örnek: $m = 5$; $8 \bmod 5 = 3$ ve $13 \bmod 5 = 3$, 3. gözün listesi $8 \to 13 \to NULL$ olur. Sonra 23 gelir ($23 \bmod 5 = 3$) ve listenin başına eklenir.
  - Düğüm yapısı: anahtar (key), anahtara bağlı bilgi (örneğin name) ve sonraki düğümün adresi (next). Hash yapısı: listenin baş düğümü (head) ve düğüm sayısı (count).

## Hocanın Özellikle Vurguladığı Kısımlar

- Arama ve silmede tabloyu sıradan bir dizi gibi düşünmemek
  - Hash tablosu "delik deşik" bir tablodur; stack ve queue'da olduğu gibi kendi erişim kuralı vardır. Sırayla tarama hash'in amacını ortadan kaldırır.
- Silme için Deleted bayrağı
  - Açık adreslemede silme ciddi bir problemdir; silinen göz Empty değil Deleted olarak işaretlenir ki arama zinciri kopmasın.
- Çakışma kaçınılmazdır
  - Sonsuz boş yer olmadıkça çakışmadan kurtulmak mümkün değildir; amaç hem zamanı hem yeri verimli kullanarak çakışma olasılığını düşürmektir.
- Bağlı listeye başa ekleme
  - Yeni eleman listenin sonuna değil başına eklenirse sona kadar ilerlemekle zaman kaybedilmez.
- Hash algoritmalarında sık yapılan hatalar
  - Adres artırılırken mod alınmadığı için başa dönülememesi: $adres = adres + 1$ yerine $adres = (adres + 1) \bmod M$ yazılmalıdır.
  - Yerleştirilmek istenen anahtarın tabloda zaten bulunup bulunmadığının kontrol edilmemesi.
- Kavramları ezberlemeden öğrenmek
  - Big-O, Big-Theta, Big-Omega, karmaşıklık, asimptotik analiz, böl ve yönet gibi kavramlar ileride Ar-Ge çalışmalarında algoritma geliştirmenin temelidir; klavyede kelime tamamlama ya da yol tarifinde daha kısa yol önerme gibi işler iyi algoritmalarla yapılır.

## Kısa Tekrar Notları

- Açık adreslemede arama, eklemeyle aynı sırayla gözleri dolaşır; Empty gözde durur.
- Doğrudan silme aramayı bozar; çözüm Normal/Empty/Deleted bayrağıdır, Deleted gözde aramaya devam edilir.
- Linear probing kümelenmeye yol açar.
- Double hashing: $hash(key, i) = [hash_1(key) + i \cdot hash_2(key)] \bmod m$; $hash_2$ adım büyüklüğüdür.
- $m = 13$, $hash_2 = key \bmod 11$ ile 14'ün deneme sırası: 1, 4, 7, 10, 0.
- Doğum günü paradoksu: 23 kişide aynı doğum günü olasılığı yaklaşık %50; çakışma sanılandan erken başlar.
- Açık adreslemede $M \approx 2N$ (yakın bir asal), $\alpha = N/M \approx 1/2$.
- Separate chaining'de $M < N$, yaklaşık $M = N/5$; yeni eleman listenin başına eklenir.
- Kodda adres artırırken mod almayı ve anahtarın tabloda zaten olup olmadığını kontrol etmeyi unutmayın.

## Detaylı Açıklamalar

- **Arama:** Tablo $m = 5$ ve $h(x) = x \bmod 5$ olsun. 4 4. göze, 3 3. göze yerleşir; 13'ün adresi $13 \bmod 5 = 3$'tür, 3. ve 4. gözler dolu olduğundan tablonun sonundan başa dönülür ve 13 0. göze yerleşir. 13 arandığında aynı yol izlenir: 3. göz (3, değil), 4. göz (4, değil), 0. göz (13, bulundu). 8 arandığında 3, 4 ve 0. gözler dolu ve 8 değildir; 1. göz boş olduğundan 8'in tabloda olmadığı anlaşılır (ekrandan, 00:05:00 ve 00:10:00).
- **Silme:** 3 silinip 3. göz boş bırakılırsa, 13 arandığında ilk bakılan göz boş olduğu için arama "yok" der; oysa 13 tablodadır. Bir öğrenci elemanları geri kaydırmayı önerdi; hoca bunun doğru yerindeki 4'ü de yerinden oynatacağını, yani yeniden hash gerektireceğini söyledi. Bir başka öneri, silmeden sonra bütün elemanları yeniden yerleştirmekti (rehash); bu yapılabilir ama bir milyon elemanlı tabloda tek bir silme için her şeyi oynatmak verimsiz olur. Genel yöntem her göze bir bayrak koymaktır. Bayrağın üç değeri vardır: Normal (dolu), Empty (hiç kullanılmamış boş göz) ve Deleted (önceden doluydu, silindi). 13 aranırken 3. göz boş ama Deleted işaretliyse, orada önceden bir eleman bulunduğu ve 13'ün ileriki gözlerden birinde olabileceği anlaşılır; arama sürer. Arama yalnız Empty gözde biter (ekrandan, 00:10:00).
  - Ders sonrası not: Hoca tahtada boş göz için önce NULL yazdı, bir öğrencinin uyarısıyla bunun Empty olması gerektiğini düzeltti.
- **Kümelenme:** Linear probing'de dolu gözden sonra hep bir sonraki göze bakıldığı için çakışan elemanlar art arda dizilir. Bu dolu blok büyüdükçe kendi adresi bu bloğa düşen yeni elemanlar da bloğun sonuna kayar. Örnekte 3 ve 8 3. ve 4. gözlere, sonra gelen 4 de 0. gözün dolu olmasıyla 1. göze yerleşir. <!-- BELİRSİZ: Bu örnekte 0. gözdeki elemanın hangisi olduğu altyazıdan net değil (hoca önce 12 dedi, sonra 4 yerine 8 koydu); kümelenme örneği bu aralığa ait kare bulunmadığı için ekrandan doğrulanamadı. -->
- **Double hashing:** Çözüm, adım büyüklüğünü 1 yerine başka bir değer, üstelik anahtara bağlı bir değer yapmaktır. $hash(key, i) = [hash_1(key) + i \cdot hash_2(key)] \bmod m$ formülünde $i = 0$ için terim sıfırdır ve adres $hash_1(key)$ olur; ilk denemede yerleşemeyen anahtar için ne kadar ileri gidileceğini $hash_2(key)$ belirler. Örnekte $m = 13$, $hash_1(key) = key \bmod 13$, $hash_2(key) = key \bmod 11$ alındı (ekrandan, 00:25:00). $96 \bmod 13 = 5$, $79 \bmod 13 = 1$, $14 \bmod 13 = 1$ çıkar. 14 için 1. göz dolu, $hash_2(14) = 14 \bmod 11 = 3$'tür. 1, 4, 7, 10 ve 12. gözlerin dolu olduğu varsayılan tabloda 14 için sırasıyla $i = 1$'de 4, $i = 2$'de 7, $i = 3$'te 10, $i = 4$'te $(1 + 4 \cdot 3) \bmod 13 = 0$. göze bakılır; 0. göz boş olduğundan 14 oraya yerleşir (ekrandan, 00:30:00; python ile doğrulandı).
  - Ders sonrası not: Hoca $i = 3$ için önce 12. göze bakıldığını söyledi ve ekranda $(12 + 3) \bmod 13 = 2$ hesabını yaptı; sonra bunu düzelterek doğru gözün 10 olduğunu belirtti. Doğru sıra 1, 4, 7, 10, 0'dır.
  - Bir öğrencinin $hash_2$'deki 11'in neye göre seçildiği sorusuna hoca, bu sayının rastgele, tablo uzunluğu olan 13'ten küçük bir sayı olarak seçildiğini söyledi.
- **Tablo uzunluğu:** Hoca, tablo uzunluğunun nasıl seçileceğini doğum günü paradoksuyla açıkladı. Birinin doğum günü 365 günden biriyse, ikincinin farklı olma olasılığı $364/365$, üçüncünün $363/365$'tir; $k$ kişinin hepsinin farklı olma olasılığı bu oranların çarpımıdır (ekrandan, 00:35:00). 23 kişilik bir toplulukta aynı doğum gününe sahip iki kişi bulunma olasılığı yaklaşık %50'dir (python ile 0,507). Hash için de 32 bitlik değerlerde yaklaşık 77.163 eklemeden sonra çakışma olasılığı %50 olur. Tablo uzunluğu $M$ iken ikinci sayının birinciyle çakışmama olasılığı $(M-1)/M$, üçüncünün $(M-2)/M$'dir; bu sürdürülünce çakışma olasılığı yaklaşık $1 - e^{-k(k-1)/(2M)}$ olarak bulunur. Buradan $M \approx 2N$ seçmenin çakışmayı yeterince düşük tuttuğu sonucu çıkar.
  - Ders sonrası not: Hoca 250.000 eklemeden sonra çakışma olasılığının %100 olduğunu söyledi. Formülle bu değer büyük olasılıkla %99,93 civarındadır (python ile hesaplandı); yani "neredeyse kesin" demek daha doğrudur.
- **Yük faktörü:** $\alpha = N/M$. 10 eleman için $2N = 20$'ye yakın bir asal sayı, örneğin 23 seçilebilir.
- **Separate chaining:** Bu yöntemde tablo gözleri bağlı listelerin başını tutar. $m = 5$ tabloda $8 \bmod 5 = 3$ olduğundan 8, 3. gözün listesine; $13 \bmod 5 = 3$ olduğundan 13 de aynı listeye eklenir: $8 \to 13 \to NULL$. Sonra 23 gelince ($23 \bmod 5 = 3$) listenin başına eklenir. Ardından 1 ve 6 geldiğinde ikisi de 1. göze düşer; 6 başa eklendiğinden liste $6 \to 1$ olur (ekrandan, 00:45:00 ve 00:50:00). Burada tablo $N$'den küçük alınır: çok küçük olursa zincirler uzar, çok büyük olursa boş göz sayısı artar. Eleman yerleştirme açık adreslemedekiyle aynı biçimde bölme (division) ya da çarpma (multiplication) yöntemiyle yapılır.
  - Hoca bu yapının kodunu anlatmaya başladı (düğüm: key, name, next; hash yapısı: head, count) ama kalem ve tablet sorunu yüzünden kodu tamamlamadı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
