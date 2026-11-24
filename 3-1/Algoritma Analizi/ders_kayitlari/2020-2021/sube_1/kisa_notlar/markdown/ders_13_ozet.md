# Ders 13 Çalışma Özeti

## Genel Konular

- Hash fonksiyonlarının hatırlatılması
  - Hashing'de bir $x$ değeri hash fonksiyonundan geçirilir, fonksiyon bir adres üretir ve eleman bu adrese yerleştirilir.
  - En çok kullanılan iki yöntem bölme (division) ve çarpma (multiplication) yöntemidir.
  - Bölme yöntemi: $h(key) = key \bmod m$. Tablo uzunluğu 7 iken 25, 4. adrese; 2, 2. adrese yerleşir.
  - Çarpma yöntemi: $h(key) = \lfloor m \cdot ((key \cdot A) \bmod 1) \rfloor$, $A = \frac{\sqrt{5}-1}{2} \approx 0{,}618033$. "mod 1" sayının virgülden sonraki kısmı demektir (ekrandan, 00:05:00).
  - Örnek: $m = 10000$, $key = 123456$ için $123456 \cdot A = 76300{,}0041151\ldots$, kesir kısmı $0{,}0041151$, $\lfloor 10000 \cdot 0{,}0041151 \rfloor = \lfloor 41{,}151 \rfloor = 41$ (ekrandan, 00:05:00).
- Anahtarın sayıya dönüştürülmesi
  - Adres bir tam sayı olduğu için anahtar ne türde olursa olsun (tam sayı, kayan noktalı sayı, string) sonunda bir sayı üretilmelidir.
  - Hash'te kullanılan bilgi tekil (unique) olmalıdır: TC kimlik no, öğrenci no, müşteri no, telefon no gibi (ekrandan, 00:10:00). Yaş ya da ad-soyad gibi tekrar edebilen bilgiler anahtar olarak anlamsızdır.
- String anahtarlar
  - İlk fikir: karakter kodlarının toplamı. Tahtada `'E'+'l'+'i'+'f'` için $70+78+73+71 = 292$, sonra $292 \bmod m$ (ekrandan, 00:15:00; hoca değerleri uydurduğunu söyledi).
  - Sorun: aynı harflerin farklı dizilişleri (`"Elif"` ile `"filE"`) aynı toplamı verir.
  - İkinci fikir: basamak ağırlıkları (1, 10, 100, 1000) ile çarpıp toplamak. Daha iyidir ama çarpan asal olmadığı için benzer değerler üretme ihtimali yüksektir.
  - Horner yöntemi: küçük bir asal $R = 31$ ile $hash = 31^{L-1} s[0] + 31^{L-2} s[1] + \dots + 31^{0} s[L-1]$, $L = \mathrm{strlen}(s)$ (ekrandan, 00:20:00).
  - Döngü biçimi: `hash = R*hash + (s[i]-'A'+1)`, sonunda `hash = hash % M`. Karakterin ASCII kodu yerine kaçıncı harf olduğu kullanılır; böylece gereksiz büyüklük önlenir.
- Bileşik anahtar (compound key)
  - Örnek: gün-ay-yıl biçiminde doğum tarihi. $R$ küçük bir tam sayıdır (31, 23 gibi).
  - $hash = (((day \cdot R + month) \bmod M) \cdot R + year) \bmod M$ ya da $hash = (day \cdot R^2 + month \cdot R + year) \bmod M$ (ekrandan, 00:25:00).
- Kayan noktalı sayılar
  - Önce tam sayıya çevrilir: $35{,}780 \to \mathrm{round}(x \cdot 10000) \bmod M$.
  - $0 \le x \le 1$ ise doğrudan $hash = \mathrm{round}(x \cdot m)$; ayrıca mod almak gerekmez.
  - Java'da anahtarın ikili gösterimi (binary representation) kullanılır.
- Çakışma (collision) problemi
  - Hash tablosu sıradan bir dizidir; "hash" yalnızca bir addır.
  - $m = 7$ iken 5, 5. göze yerleşir. 12 de $12 \bmod 7 = 5$ olduğu için aynı göze yerleşmek ister. Göz doludur: bu çakışmadır.
- Açık adresleme (open addressing) ve doğrusal yoklama (linear probing)
  - Her kontrol bir yoklamadır (probe).
  - $h(key, i) = (h'(key) + i) \bmod m$, $i = 0, 1, 2, \dots$
  - 12: $i=0$ için 5 dolu, $i=1$ için $13 \bmod 7 = 6$ boş, 6. göze yerleşir.
  - 19: $i=0$ için 5 dolu, $i=1$ için $20 \bmod 7 = 6$ dolu, $i=2$ için $21 \bmod 7 = 0$ boş, 0. göze yerleşir. Arama dairesel (circular) sürer; bunu mod sağlar.
- Hash tablosu işlemleri
  - Temel işlemler: insert, search, delete. Boş göz NULL ile gösterilir; tablo başta NULL ile doldurulmuş kabul edilir.
  - Örnek algoritma: eleman tabloda varsa uyarı veren, yoksa ekleyen algoritma (Google hesap adı alma örneği).

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınavlarda en sık görülen hata: adres doluysa adresi mod almadan artırmak
  - Adres 6'dan 7'ye çıkınca tablo dışına taşılır. Her artırmada $adr = (adr + 1) \bmod m$ yazılmalıdır.
- Döngüde $i < m$ kontrolü mutlaka konmalıdır
  - Açık adreslemede tablo, eleman sayısından büyük tutulur (5 eleman için en az 7-8 göz). Yine de tablo beklenmedik biçimde dolarsa bu kontrol yoksa sonsuz döngü oluşur. Hoca bunu güvenlik açısından kritik (safety-critical) kod örneğiyle açıkladı.
- Anahtar mutlaka tekil bir bilgi olmalıdır.
- String ve bileşik anahtarlarda çarpanın küçük bir asal sayı olması önerilir
  - Amaç çakışma olasılığını azaltmaktır. Çakışma hiçbir zaman sıfırlanamaz, yalnızca azaltılabilir.
- Hoca, anahtar olarak string kullanmamaya çalışmayı önerdi; string anahtarlarda çakışma ihtimali daha yüksektir.

## Kısa Tekrar Notları

- Bölme: $key \bmod m$. Çarpma: $\lfloor m \cdot ((key \cdot A) \bmod 1) \rfloor$, $A \approx 0{,}618033$.
- $hash(123456)$, $m = 10000$ için 41.
- String: karakter toplamı permütasyonlarda çakışır; Horner yöntemi $R = 31$ ile $hash = R \cdot hash + (s[i] - 'A' + 1)$, sonra $\bmod M$.
- Bileşik anahtar: $(day \cdot R^2 + month \cdot R + year) \bmod M$.
- Kayan nokta: $\mathrm{round}(x \cdot 10000) \bmod M$; $0 \le x \le 1$ ise $\mathrm{round}(x \cdot m)$.
- Çakışma: iki anahtarın aynı adresi istemesi.
- Doğrusal yoklama: $(h'(key) + i) \bmod m$; dairesel ilerler.
- $m = 7$: 5 → 5, 12 → 6, 19 → 0.
- Ekleme döngüsünün koşulu: `(i < m) && (hash[adr] != NULL) && (hash[adr] != key)`.
- Döngüden sonra: $i = m$ ise "tablo dolu"; `hash[adr] == NULL` ise `hash[adr] = key`; aksi halde "eklenmiş".

## Detaylı Açıklamalar

- **String anahtardan sayı üretme.** Hash tablosunun adresi bir tam sayı olduğundan string anahtar önce bir sayıya çevrilmelidir. C'de bir karakter bir `int` değişkene atanırsa karakterin sayı karşılığı elde edilir (tahtada `int x; x = 'E';`). En basit yol karakter kodlarını toplamaktır, ancak toplama işlemi sıradan bağımsızdır: `"Elif"` ile `"filE"` aynı toplamı verir; bir harfi bir önceki, diğerini bir sonraki harfle değiştirmek de toplamı korur. Hoca bu tür özel durumları tek tek çözmeye çalışmanın sonu olmadığını, asıl amacın çakışma olasılığını genel olarak azaltmak olduğunu söyledi. Basamak ağırlıkları (1, 10, 100, 1000) sırayı hesaba katar, ama 10 asal olmadığından yine benzer değerler üretme ihtimali yüksektir. Bu yüzden küçük bir asal çarpan (31; bazı kaynaklarda 29) ile Horner yöntemi kullanılır:

  ```c
  length = strlen(s); hash = 0;
  for (i = 0; i < length; i++)
      hash = (R * hash + (s[i] - 'A' + 1));
  hash = hash % M;
  ```

  (ekrandan, 00:20:00). Her karakterin ASCII kodu yerine kaçıncı büyük harf olduğu alınır (A, B, C → 0, 1, 2 gibi); ASCII kodunu kullanmak da mümkündür ama gereksiz büyüklük getirir. Hoca bu biçimin Java'da kullanıldığını söyledi.

  > **Ders sonrası not:** Tahtadaki ifade `s[i]-'A'+1` olduğundan A, B, C büyük olasılıkla 0, 1, 2'ye değil 1, 2, 3'e karşılık gelir; tahtadaki "A B C → 0 1 2" gösterimi `s[i]-'A'` ifadesine uyar. Ayrıca Java'nın `String.hashCode` metodu büyük olasılıkla harf sırasını değil karakterin kendi kodunu kullanır: $s[0] \cdot 31^{n-1} + \dots + s[n-1]$.

- **Bileşik anahtar.** Doğum tarihi gibi birden fazla parçadan oluşan bilgiler, küçük bir $R$ çarpanıyla birleştirilir. Ya her adımda mod alınarak ($((day \cdot R + month) \bmod M) \cdot R + year) \bmod M$) ya da tek seferde ($day \cdot R^2 + month \cdot R + year) \bmod M$) hesaplanabilir. Öğrencinin sorusu üzerine hoca $R$'nin asal seçilmesinin önerildiğini, amacın çakışmayı olabildiğince önlemek olduğunu doğruladı.

- **Kayan noktalı sayılar.** Sayı önce tam sayıya çevrilir. Örneğin $35{,}780$ gibi bir değer $10000$ ile çarpılıp yuvarlanır, sonra $M$'ye göre modu alınır. Sayı 0 ile 1 arasındaysa $m$ ile çarpıp yuvarlamak doğrudan tablo aralığında bir adres verir.

  > **Ders sonrası not:** $x$ 1'e çok yakın olduğunda $\mathrm{round}(x \cdot m)$ değeri $m$ olabilir ve $0..m-1$ adres aralığının dışına çıkar (örneğin $\mathrm{round}(0{,}99 \cdot 10) = 10$). Bu yüzden $0 \le x < 1$ için $\lfloor x \cdot m \rfloor$ kullanmak daha güvenlidir.

- **Doğrusal yoklama.** Bir öğrencinin önerdiği gibi, çakışmada boş bir göz bulunana kadar aşağı doğru ilerlenir. Tablo boyuna çizilse de aslında bir dizidir. $m = 7$ tablosunda 5 → 5. göz, 12 → 5 dolu, 6 boş → 6. göz, 19 → 5 ve 6 dolu, $21 \bmod 7 = 0$ → 0. göz. Altıncı gözden sonra durulmaz; mod sayesinde başa dönülür.

- **Ekle ya da uyar algoritması.** Soru: "Bir hash tablosuna yeni bir eleman eklenmek isteniyor. Eğer bu eleman tabloda daha önce varsa kullanıcıya uyarı mesajı veren, yoksa tabloya ekleyen algoritma." (ekrandan, 00:40:00). Akış şeması (ekrandan, 00:50:00):

  ```text
  i = 0
  adr = key mod m
  döngü: (i < m) && (hash[adr] != NULL) && (hash[adr] != key) doğru olduğu sürece
      i++
      adr = (adr + 1) % m
  döngüden sonra:
      i == m ise                 -> "tablo dolu"
      değilse hash[adr] == NULL ise -> hash[adr] = key
      değilse                    -> "eklenmiş" (eleman zaten var)
  ```

  Döngüdeki üç koşul sırasıyla tablonun dolu olup olmadığını, boş göz bulunup bulunmadığını ve anahtarın zaten tabloda olup olmadığını denetler. Anahtarların tam sayı olduğu varsayılmıştır; string için `strcmp` gerekir. Bir öğrenci `adr++ % M` yazımında artırmanın mı modun mu önce yapılacağını sordu; tahtadaki son biçim $adr = (adr + 1) \bmod m$ oldu.

  > **Ders sonrası not:** C'de `adr = adr++ % M` gibi bir ifade, aynı değişkeni bir ifadede iki kez değiştirdiği için tanımsız davranıştır; `adr++ % M` ise artırmadan önceki değerin modunu verir. Doğru yazım `adr = (adr + 1) % M` biçimidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
