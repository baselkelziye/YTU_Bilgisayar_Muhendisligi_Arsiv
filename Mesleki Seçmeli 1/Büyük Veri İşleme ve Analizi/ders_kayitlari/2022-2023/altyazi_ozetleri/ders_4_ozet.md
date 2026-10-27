# Ders 4 Çalışma Özeti

## Genel Konular

- Ders 22 Mart 2023 Çarşamba günü online yapıldı.
- Hoca dersi Türkçe ve İngilizce karışık anlattı.
- Konu: 3. bölüm (chapter 3), büyük veri kümelerinde benzer kümeleri bulma (Finding Similar Sets).
- İşlenen konular:
  - Benzer doküman bulmanın kullanım alanları.
  - Shingling ile dokümanı kümeye çevirme.
  - Jaccard benzerliği (Jaccard similarity).
  - Dokümanları 0-1 kolon vektörlerinden oluşan girdi matrisine (input matrix) çevirme.
  - MinHashing ile imza matrisi (signature matrix) oluşturma: permütasyonla ve hash fonksiyonlarıyla.
  - Locality Sensitive Hashing (LSH): bantlara bölme, kovalar (bucket), aday ikililer (candidate pairs).
  - LSH'de hata olasılığının hesabı.
- 3. bölüm bu derste bitti.
- Dönem projesi için ilk duyurular yapıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Problemin büyüklüğü.** Doküman sayısı çok fazla ve her doküman çok büyük. Veri tek bir bilgisayarın belleğine sığmaz. Bu bölümdeki algoritmalar problemi tek bilgisayar belleğiyle bile çözmeyi sağlar.
- **Üç aşamalı süreç:** Shingling, MinHashing, Locality Sensitive Hashing.
- **MinHashing'in temel ilkesi.** İki dokümanın imza matrisindeki benzerliği, girdi matrisindeki Jaccard benzerliğine yakınsar. Bu yüzden benzerliğe imza matrisi üzerinden bakılabilir.
- **İmza matrisinin asıl avantajı az yer kaplamasıdır.** Kolon sayısı aynı kalır. Satır sayısı hash fonksiyonu sayısına düşer.
- **Permütasyon tabanlı hash büyük veride uygun değildir.** Her hash fonksiyonu için milyonlarca satırlık bir permütasyonu bellekte tutmak gerekir. Bunun yerine $h(x) = (ax+b) \bmod n$ biçimli hash fonksiyonları kullanılır.
- **LSH'nin fikri:** Bütün ikilileri karşılaştırmak yerine yalnız benzer olma olasılığı yüksek ikilileri karşılaştırmak.
- **Hash işin içine girince yaklaşık (approximation) sonuç konuşulur.** Hash fonksiyonu %100 başarılı değildir.
- Shingling ve LSH için örnek sorular ve MapReduce örneği cevaplarıyla dersin sayfasına konacak.

## Kısa Tekrar Notları

- **Kullanım alanları:**
  - Benzer dokümanları bulma ve sınıflandırma.
  - Netflix gibi servislerde aynı kişilerin izlediği filmleri gruplayıp öneri yapma.
  - Farklı sosyal medya platformlarında aynı kişiye ait hesapları bulma.
  - Arama motorlarında aynı içerikli sayfaları tek sonuçta gösterme.
  - İntihal (plagiarism) tespiti.
  - Google News gibi sitelerde aynı haberi tekrar göstermeme.
- **Shingling.** Dokümandan $k$ uzunluğundaki karakter dizileri çıkarılır. Sonuç bir kümedir, aynı eleman iki kez yer almaz. NLP'deki n-gram ile aynı fikirdir.
- **Jaccard benzerliği:** $\text{sim}(C_1, C_2) = \dfrac{|C_1 \cap C_2|}{|C_1 \cup C_2|}$.
- **İsteğe bağlı sıkıştırma.** Shingle'lar hash ile 4 baytlık tamsayılara çevrilebilir. Arada çakışma (iki farklı dizinin aynı sayıya düşmesi) olabilir. Bellek kazancı buna değer.
- **Girdi matrisi.** Satırlar shingle'lar, kolonlar dokümanlardır. Shingle dokümanda varsa 1, yoksa 0 yazılır.
- **İmza matrisinde benzerlik:** Aynı olan satır sayısı / toplam satır sayısı.
- **LSH parametreleri:** İmza matrisi $b$ banda bölünür. Her bantta $r$ satır vardır. $n = b \cdot r$.
- **Aday ikili.** Bir bantta iki dokümanın parçası aynı kovaya düşerse ikili aday olur. Gerçek benzerlik yalnız adaylar için hesaplanır.

## Detaylı Açıklamalar

### Shingling örneği

- Doküman `abcab`, $k = 2$ olsun.
- 2 uzunluğundaki shingle'lar: `ab`, `bc`, `ca`.
- `ab` iki kez geçiyor ama küme olduğu için bir kez yazılır.

### Jaccard benzerliği ve girdi matrisi

- Geçen haftaki örnekte kesişim 3, birleşim 8 idi. Benzerlik $3/8$.
- Girdi matrisi örneği: Bütün dokümanlarda toplam 700 farklı shingle varsa, her doküman 700 boyutlu bir 0-1 vektörüdür.
- İki kolon karşılaştırılırken dört satır tipi vardır:
  - İkisinde de 1.
  - Birincide 1, ikincide 0.
  - Birincide 0, ikincide 1.
  - İkisinde de 0.
- Jaccard benzerliği: pay "ikisinde de 1" olan satırların sayısı. Payda "en az birinde 1" olan satırların sayısı. "İkisinde de 0" olan satırlar hesaba girmez.
- Derste gösterilen örnekte ikisinde de 1 olan satır 2, en az birinde 1 olan satır 5 idi: benzerlik $2/5 = 0.4$.

### MinHashing: permütasyonla

- İmza matrisinin her satırı bir hash fonksiyonuna karşılık gelir.
- Permütasyon yönteminde hash fonksiyonu satırların karışık bir sırasıdır (permuted order).
- Bir doküman için: Permütasyon sırasıyla satırlar gezilir. İlk 1 görülen satırın numarası, o hash fonksiyonu için imza değeridir.
- Örnek: 2. hash fonksiyonu, 3. doküman. Permütasyon sırasında 1., 2., 3. satırlarda 0, 4. satırda 1 var. İmza değeri 4.
- İmza matrisinde benzerlik örnekleri (3 hash fonksiyonu, 4 doküman):
  - $C_1$ ve $C_3$: 3 satırın 2'si aynı. Benzerlik $2/3$.
  - $C_2$ ve $C_4$: 3 satırın 3'ü de aynı. Benzerlik $3/3 = 1$.
  - $C_1$ ve $C_2$: hiçbir satır aynı değil. Benzerlik $0/3 = 0$.

### MinHashing: hash fonksiyonlarıyla (bellekte permütasyon tutmadan)

- Örnek: 5 satırlı girdi matrisi, 2 doküman ($C_1$, $C_2$).
- Hash fonksiyonları: $h_1(x) = x \bmod 5$, $h_2(x) = (2x + 1) \bmod 5$.
- İmza matrisi $2 \times 2$ olur: 2 hash fonksiyonu, 2 doküman.
- Algoritma:
  1. İmza matrisinin bütün hücrelerine $\infty$ yazılır.
  2. Her satır $r$ için önce $h_1(r)$ ve $h_2(r)$ hesaplanır.
  3. Her doküman $c$ için: girdi matrisinde $(r, c)$ hücresi 0 ise hiçbir şey yapılmaz.
  4. Hücre 1 ise her hash fonksiyonu $i$ için: $\text{SIG}(i, c) = \min(\text{SIG}(i, c),\ h_i(r))$.
- Satır satır ilerleyiş:

| Satır | $C_1$ | $C_2$ | $h_1$ | $h_2$ | $C_1$ imzası | $C_2$ imzası |
|---|---|---|---|---|---|---|
| 1 | 1 | 0 | 1 | 3 | (1, 3) | (∞, ∞) |
| 2 | 0 | 1 | 2 | 0 | (1, 3) | (2, 0) |
| 3 | 1 | 1 | 3 | 2 | (1, 2) | (2, 0) |
| 4 | 1 | 0 | 4 | 4 | (1, 2) | (2, 0) |
| 5 | 0 | 1 | 0 | 1 | (1, 2) | (0, 0) |

- Sonuç: $C_1$ imzası $(1, 2)$, $C_2$ imzası $(0, 0)$.
- Sözde kodun yapısı:

```
her hücre için SIG(i, c) = ∞
her satır r için:
    her hash fonksiyonu i için h_i(r) hesapla
    her doküman c için:
        eğer M(r, c) == 1:
            her i için SIG(i, c) = min(SIG(i, c), h_i(r))
```

- Avantajı: Permütasyonları bellekte tutmaya gerek kalmaz.

### Locality Sensitive Hashing (LSH)

- İmza matrisi küçülse bile ikili karşılaştırma sayısı sorun olarak kalır. 1 milyon dokümanda $\binom{10^6}{2}$ ikili vardır.
- LSH yalnız benzer olma olasılığı yüksek ikilileri bulur.
- Adımlar:
  1. Bir benzerlik eşiği (threshold) seçilir, örneğin $s = 0.8$.
  2. İmza matrisi $b$ banda bölünür. Örnek: 100 satır, $b = 5$ ise $r = 20$.
  3. Her bantta, her dokümanın o banttaki $r$ tamsayılık parçası bir hash fonksiyonuna verilir. Parça bir kovaya (bucket) düşer.
  4. Aynı bantta aynı kovaya düşen dokümanlar aday ikili olur.
  5. Gerçek benzerlik yalnız aday ikililer için hesaplanır. Örneğin bir kovada 80 doküman varsa yalnız bu 80'in ikilileri karşılaştırılır.
- Hash fonksiyonunun çözünürlüğü kusursuz değildir. Benzer olmayan iki doküman aynı kovaya düşebilir (yanlış pozitif, false positive).

### LSH hata hesabı örneği

- 100.000 doküman (kolon), 100 MinHash fonksiyonu (satır).
- İmza matrisinin boyutu: $100 \times 100.000 \times 4$ bayt $= 40$ MB.
- LSH olmadan karşılaştırılacak ikili sayısı: $\binom{100.000}{2} \approx 5$ milyar.
- Seçim: $b = 20$ bant, $r = 5$ satır. Hedef: benzerliği 0.8 olan ikilileri bulmak.
- $C_1$ ve $C_2$'nin benzerliği 0.8 olsun.
  - Belirli bir bantta 5 satırın hepsinin aynı olma olasılığı: $0.8^5 \approx 0.328$.
  - Bir bantta aynı olmama olasılığı: $1 - 0.328 = 0.672$.
  - 20 bandın hiçbirinde aynı olmama olasılığı: $0.672^{20} \approx 0.00035$.
- Yani gerçekten %80 benzer bir ikili yaklaşık 3000'de 1 olasılıkla aday olarak bulunamaz. Bu yanlış negatiftir (false negative).

### Dönem projesi duyurusu

- 5. derste (gelecek hafta) 4. bölüm başlayacak ve dönem projesi ayrıntılı anlatılacak.
- Proje tek kişilik ya da 2 kişilik grup olabilir. Gruplar şimdiden kurulmalı.
- Proje MapReduce programlama ile büyük veri işleme ve analiz algoritmaları kullanılarak yapılacak.
- Sonra bir proje önerisi (proposal) istenecek: konu, veri kümesi, grup üyeleri.

### Ders sonrası notlar

- **Hata olasılığı.** Altyazıda değer "0.3035" diye geçiyor. Doğru hesap: $(1 - 0.8^5)^{20} = 0.672^{20} \approx 0.00035$. Bu da hocanın söylediği "3000'de 1" ile uyumludur.
- **Yanlış negatifin anlamı.** Hoca bu değeri yanlış negatif olarak adlandırdı. Bu doğrudur: değer, gerçekten benzer bir ikilinin hiçbir bantta aynı kovaya düşmeme olasılığıdır. Hoca hemen ardından bunu "benzer olmayan dokümanların kovaya konması" diye açıkladı. Bu yanlıştır; o durum yanlış pozitiftir (false positive).
- **Aday olma koşulu.** Hoca bir yerde "bantların %80'inden fazlası aynı kovaya düşerse aday" dedi. Standart LSH'de en az bir bantta aynı kovaya düşmek yeterlidir. Hata hesabındaki "20 bandın hiçbirinde" ifadesi de bu standart tanıma dayanır. 0.8 değeri bant oranı değil, benzerlik eşiğidir.
- **Hash fonksiyonu örneği.** Tablodaki değerler hocanın derste söylediği sayılardan yeniden kuruldu. 3. satırda $h_1 = 3$, $h_2 = 7 \bmod 5 = 2$.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
