# Ders 7 Genişletilmiş Notu: Hash Tabloları, Algoritma Analizi ve Asimptotik Notasyonlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Temel Veri Yapılarına Dönüş: Kuyruk ve Arama Süreleri
- 2. Hash Tabloları ve Hash Fonksiyonları
- 3. Algoritma Analizi ve Değerlendirme Ölçütleri
- 4. Kaba Analiz, Teorik Analiz ve Temel İşlem
- 5. Yürütme Zamanı, Alan Maliyeti ve Asimptotik İfade
- 6. Koddan T(n) Çıkarma Örnekleri
- 7. Fonksiyonların Büyüme Hızları ve Analiz Türleri
- 8. Big O Gösterimi
- 9. Big Omega ve Big Theta Gösterimleri
- 10. Bileşik Algoritmalar, Limit ve Tümevarım Yöntemleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Temel Veri Yapılarına Dönüş: Kuyruk ve Arama Süreleri

Ders, önceki derste anlatılan temel veri yapıları slaytına dönülerek başladı (ekrandan, 00:20:00). Slayttaki liste şöyledir: listeler (dizi, bağlantılı liste, string), yığın (stack), kuyruk (queue), öncelikli kuyruk (priority queue), çizge (graf), ağaçlar ve kümeler. Yığın için söylenen ekleme ve silme mantığının kuyruk ve diğer yapılar için de geçerli olduğu hatırlatıldı.

### 1.1 Kuyruğun kullanım yerleri

Kuyrukta ekleme arka uçtan, çıkarma ön uçtan yapılır; tıpkı günlük hayattaki sıra gibi. Ekleme işlemine enqueue, çıkarma işlemine dequeue denir. Kuyruk özellikle iş sıralamada (scheduling) kullanılır: işletim sistemleri dersindeki süreç yönetimi (process management) konusunda ve Gantt diyagramlarında işler bir sayı doğrusu üzerinde sıraya konur. Örneğin $P_1$ işlemi 0. zamandan 5. zamana kadar, $P_2$ 8'e kadar, $P_3$ 9'a kadar sürer; böylece hem süreler hem de sıra görülür ("$P_1$ bitmeden $P_2$ başlayamaz"). Kuyruk işlemleri ileride graf algoritmalarında ayrıntılı kullanılacaktır. Dizi ve bağlı listeyle kuyruk kurmanın kodu yapısal programlama ve veri yapıları derslerinde ele alınır.

### 1.2 Bir elemanı kaç adımda buluruz?

Hoca, veri yapılarının amacını sordu. Bir öğrencinin cevabı "veriyi verimli saklamak ve işlemek" oldu. Hoca bunu şöyle açtı: 100 öğrencinin notu 100 ayrı değişkenle de tutulabilir, ama bir dizi kullanmak hem programlamayı kolaylaştırır hem de algoritmayı verimli kılar. Veri yapısı budur.

Ardından şu soruyu sordu: $n$ elemanlı sırasız bir dizide ya da bağlı listede, kesinlikle var olan bir eleman en fazla kaç denemede bulunur? Cevap $n$'dir. Dizi sıralıysa ikili arama (binary search) kullanılabilir. Günlük hayattan örnek: 100 sayfalık bir kitapta 40. sayfayı bulmak için sayfaları tek tek çevirmek doğrusal aramadır; önce 50. sayfaya, sonra 25. sayfaya, sonra 25 ile 50 arasına gitmek ikili aramadır. İnsanın kitabı kabaca açıp ilgili yere yakın bir yerden başlaması ise interpolasyon aramasına benzer.

256 elemanlı bir dizi için (ekrandan, 00:20:00):

- Doğrusal arama: en fazla 256 deneme.
- İkili arama: $\log_2 256 = 8$ deneme.
- İnterpolasyon araması: $\log_2 \log_2 256 = \log_2 8 = 3$ deneme.

İkili arama için dizinin sıralı olması gerekir. İnterpolasyon araması için sıralı olmanın yanında verinin düzgün (uniform) dağılımlı olması da gerekir; o zaman çok hızlı sonuç verir. Böyle bir sıra ya da dağılım yoksa farklı bir teknik olan hash tabloları kullanılır.

> **Ders sonrası not:** Hoca sıralı dizide aramanın "$n\log n$'e" düştüğünü söyledi; doğrusu ikili aramada $\log n$ adımdır. Aynı örnekte 256 eleman için 8 adım hesaplanması da bunu gösterir.

## 2. Hash Tabloları ve Hash Fonksiyonları

### 2.1 Hash tablosunun mantığı

Hash tablosunda ideal durumda aranan eleman tek denemede bulunur. Saklanacak veri basit bir tamsayı ya da karakter olabileceği gibi, bir `struct` ya da nesne gibi bileşik bir değer de olabilir. Veri tabloya eklenmeden önce bir $f$ fonksiyonundan geçirilir (programlamadaki fonksiyon değil, matematikteki fonksiyon gibi düşünülmelidir). Fonksiyonun sonucu bir indekstir ve veri tablonun o indeksine yazılır (ekrandan, 00:25:00; tahtada tablo "index | data" sütunlarıyla, solda $\text{index}=f(\text{data})$ çizildi).

Arama sırasında da aynı $f$ fonksiyonu kullanılır: önce verinin indeksi hesaplanır, sonra doğrudan o indekse gidilir. Bu yüzden asıl soru, her veriye ayrı bir indeks veren ve tek seferde bulmayı sağlayan fonksiyonun nasıl seçileceğidir. Bu fonksiyona hash fonksiyonu (hash function) denir.

### 2.2 Mod alma ile hash

En basit hash fonksiyonu mod alma işlemidir. Tabloda 10 göz varsa, C'de indisler 0'dan 9'a kadardır ve

$$\text{indeks} = \text{veri} \bmod 10$$

kullanılır:

- 13 gelirse 3. göze,
- 22 gelirse 2. göze,
- 48 gelirse 8. göze yazılır.

İlk bakışta güzel görünür, ama 13 de 33 de 3. göze düşer. Bu çakışma için farklı çözümler geliştirilmiştir; ayrıntıları veri yapıları ve algoritma analizi derslerinde anlatılır.

> **Ek bilgi (derste anlatılmadı):** Çakışmayı çözmenin iki yaygın yolu, aynı göze düşen elemanları o gözdeki bir bağlı listede tutmak (zincirleme, chaining) ve boş bir göz bulana kadar tabloda ilerlemektir (açık adresleme, open addressing).

### 2.3 Parolaların saklanması

Hash fonksiyonlarının günlük hayattaki bir uygulaması parola saklamadır. Bir siteye üye olunduğunda kullanıcı adı ve parola alınır. Güvenlik kuralları gereği parola veri tabanında açık metin olarak tutulmamalıdır; web sitelerine güvenlik sertifikası veren kurumlar da kullanıcı bilgilerinin nasıl saklandığını denetler. Parola ya bir kriptoloji algoritmasıyla şifrelenir ya da bir hash fonksiyonundan geçirilir. Örnek olarak MD5 ve SHA-256 verildi. MD5 girdiyi alır ve çıktı olarak bir indeks değeri gibi, şifrelenmiş görünen bir değer üretir.

Hoca öğrencilere "şifremi unuttum" dendiğinde sitelerin ne yaptığını sordu. Cevap: e-postayla bir bağlantı gönderilir ve parola sıfırlanır; eski parola geri gönderilmez. Bunun nedeni hash fonksiyonunun tersinin alınamaması ya da tersini bulmanın çok uzun sürmesidir. Sezgi için verilen örnek: harflere $0,1,2,\dots$ ve bazı sayılara $-1,-2,-3$ gibi değerler verilip $x^2$ ile kodlama yapılırsa, $1^2=1$ ve $(-1)^2=1$ olur; sonuçtan hangi değerin girildiği bilinemez. Tersi alınabilse bile, kabul edilebilir bir sürede çözülemeyen problemler vardır; bu konu derste ileride problem sınıflandırmasında görülecektir.

> **Hocanın vurgusu:** "Şifremi unuttum" dediğinizde parolanız size açık metin olarak geliyorsa o site güvenli değildir, sertifikası olsa bile dikkat edin.

**Soru:** Parola geri döndürülemeyen bir fonksiyonla saklanıyorsa giriş sırasında eşleştirme nasıl yapılıyor?
**Cevap:** Fonksiyon sabittir. Her girişte yazılan parola aynı fonksiyondan geçirilir ve elde edilen hash değeri kayıtlı değerle karşılaştırılır. Eşitse giriş yapılır, değilse hata verilir. Girişte de hiçbir geri döndürme işlemi yoktur.

**Soru:** İki farklı parola aynı sonucu üretmez mi?
**Cevap:** Fonksiyonların birebir ve örten olma özellikleri burada devreye girer. Tanım kümesindeki iki farklı değer görüntü kümesinde aynı yere giderse sorun çıkar; bu yüzden fonksiyonun iki girdiyi aynı değere götürmeyecek şekilde tasarlanması gerekir. Hoca MD5 ve SHA-256'nın nasıl fonksiyonlar olduğunu ayrık matematik gözüyle incelemeyi önerdi.

> **Ders sonrası not:** Hoca hash fonksiyonunun birebir olması gerektiğini söyledi. Büyük olasılıkla daha doğru ifade şudur: MD5 ve SHA-256 sınırsız sayıda girdiyi sabit uzunlukta bir çıktıya götürdüğü için birebir olamaz, yani çakışmalar mutlaka vardır; iyi bir hash fonksiyonunda bunları bulmak pratikte çok zordur. MD5'te çakışma üretilebildiği için büyük olasılıkla artık parola saklamada güvenli sayılmaz.

## 3. Algoritma Analizi ve Değerlendirme Ölçütleri

Bir işi yapmak için birden fazla algoritma geliştirilebilir: A, B, C, D algoritmaları. Hangisinin daha iyi olduğu sorusunda genellikle bir "trade-off" ortaya çıkar: bazı şeylerden kazanç sağlanırken bazı şeylerden kayıp verilir. Algoritma analizi, bu "bazı şeyleri" yani değerlendirme ölçütlerini inceler:

- Doğruluk: algoritmanın ne kadar doğru sonuç verdiği. Özellikle optimizasyon algoritmalarında önemlidir.
- Zaman verimliliği: en doğru sonuca ne kadar sürede ulaşıldığı.
- Bellek verimliliği: bu sırada ne kadar bellek kullanıldığı.
- En iyi (optimal) çözüm: en doğru sonuca en kısa sürede ve en az bellekle ulaşan algoritma arayışı. Diğer üç ölçüt birbirini etkiler.

### 3.1 Doğruluk için bir optimizasyon örneği

Hoca doğruluğu bir makale üzerinden anlattı (ekrandan, 00:35:00). Problem görüntüde kontrast iyileştirmedir. Her piksel değeri $x$ için $a$, $b$, $c$ parametreli bir dönüşüm uygulanır: kabaca $x$ $a$ ile çarpılır, $b$ eklenir ve sonuç $c$'inci ya da $1/c$'inci kuvvete yükseltilir; değerler 0-255 aralığına getirilir. <!-- BELİRSİZ: Dönüşümün tam formülü ekranda okunmadı; altyazıda "ax+b, c'inci ya da 1/c'inci kuvvet" diye anlatılıyor. --> Kontrastı bozulmuş bir görüntü bu dönüşümden geçince düzeltilmiş hali elde edilir. Asıl iş $a$, $b$, $c$ parametrelerini uygun seçmektir. Bunlar gerçel sayılar olduğu için sonsuz aday vardır ve arama yinelemeli bir süreçtir.

Parametreler iki farklı optimizasyon algoritmasıyla arandı: parçacık sürü optimizasyonu (PSO; balık ve kuş sürülerinden esinlenir) ve yapay arı kolonisi (ABC; arıların davranışından esinlenir). Başarım ölçütü, düzeltilmiş görüntünün bozulmamış asıl görüntüye ne kadar yakın olduğudur (kabaca aralarındaki fark). Ekrandaki şekilde asıl görüntü ile kontrastı $+1$, $-1$, $+2$, $-2$ değiştirilmiş görüntüler gösterildi. Bir görüntüde PSO daha iyi sonuç verirken diğerinde ABC daha iyi sonuç verdi. Buradan çıkan ders: bir algoritmanın bir örnekte daha iyi çıkması her durumda daha iyi olduğu anlamına gelmez.

### 3.2 Zaman ve bellek

Arama uzayı şöyle canlandırıldı: iki parametreye bağlı bir fonksiyonu çizmek için üçüncü boyuta çıkmak gerekir. Bu, dağları ve ovaları olan uçsuz bucaksız bir araziye benzer: iki boyut konumu, üçüncü boyut yüksekliği gösterir. Amaç bu arazideki en derin ya da en yüksek noktayı (global minimum ya da maksimum) bulmaktır. Bu bir arama işlemidir; bir doğruluğa ulaşılır, bu sırada zaman geçer ve bellek kullanılır.

Bilgisayarın kapasitesini zorlamayan bellek kullanımı sorun değildir. Ama bazı algoritmalar o kadar çok bellek ister ki bulut bilişimle bile karşılanamaz. Teoride çok kısa sürede sonuç veren ama belleği elde edilemeyen bir algoritma gerçekleştirilemez. Trade-off genellikle zaman ile bellek arasındadır ve bunun sonucundan doğruluk ya da optimallik etkilenir.

## 4. Kaba Analiz, Teorik Analiz ve Temel İşlem

Analiz iki yolla yapılır: analitik çözümlerle yapılan teorik analiz ve daha naif ama yine de bilgi veren kaba (deneysel, ampirik) analiz.

### 4.1 Kaba analiz

Slayttaki adımlar (ekrandan, 00:45:00):

- Bir giriş verisi seçilir.
- Zaman birimi (milisaniye) ya da yürütülen temel işlem adımlarının sayısı seçilir.
- Deneysel verilerle analiz yapılır.

Örneğin $n$ elemanlı bir dizi üzerinde çalışan kodun başına ve sonuna birer zamanlayıcı konur; iki zaman arasındaki fark çalışma süresini verir. Sabit bir $n$ için program defalarca çalıştırılır ve sürelerin ortalaması, standart sapması, minimum, maksimum ve medyanı raporlanır. Ya da tekrarlanan işlemlere bir sayaç konur; sayaç değerinin $n$'e, $n/2$'ye ya da $n\log n$'e yaklaştığı gözlenerek çıkarım yapılır. Bu yöntem programlama dillerinde kolayca uygulanır ama çok kesin değildir.

### 4.2 Temel işlem nedir?

Hoca "temel işlem" kavramını öğrencilere sordu. Bir öğrenci, amaca ulaşmak için döngü içinde yapılan işlemleri, örneğin en küçük elemanı bulurken bir elemanı minimum kabul edip diğerleriyle tek tek karşılaştırmayı ve küçük olanı yeni minimum yapmayı söyledi.

Hoca bunu şöyle toparladı: En küçük elemanı bulurken önce bir eleman minimum kabul edilir; bu atama yalnız başta bir kez yapılır. Sonra her eleman için bir karşılaştırma yapılır ve sonuca göre bir atama (yedekleme) yapılır. Atama yalnız koşul doğruysa yapılır, karşılaştırma ise her adımda kesin yapılır. Bu yüzden en küçük ya da en büyük bulmada temel işlem karşılaştırmadır. Temel işlemler genellikle `if` yapılarında görülür: `if (a == 5) ... else ...` ifadesinde koşulun kendisi kesin çalışır (Assembly'de bir SUB ya da CMP komutu), dallardan hangisinin çalıştığı ise bu analizde önemli değildir.

Toplama, çıkarma ve atama da temel işlem sayılabilir; kontrol sayısı, döngü sayısı ve atama sayısı kullanılabilir. Ancak her zaman yapılmayan atama, minimum bulma gibi programlarda temel işlem olmaz.

### 4.3 Teorik analiz

Slayttaki tanımlar (ekrandan, 00:50:00):

- Zaman verimliliği, girdi boyutunun bir fonksiyonu olarak temel işlemin tekrar sayısı belirlenerek analiz edilir. Bellek verimliliği de benzer biçimde incelenir.
- Temel işlem (basic operation): algoritmanın çalışma süresini en çok etkileyen işlemdir. "Sıralamada ........ temel işlemdir" boşluğuna "comparison" (karşılaştırma) yazıldı.

Sıralamada takas (swap) temel işlem değildir, çünkü her adımda olmayabilir. Karşılaştırma ise her denemede yapılır. Karşılaştırma programın darboğazıdır (bottleneck); onu analiz etmek sıralama algoritmasının tamamını analiz etmek demektir. A algoritmasında da B algoritmasında da takas yapılacaktır; fark, takasa karar verirken yapılan karşılaştırmalardadır. Ekrana yazma gibi işlemler problemin temel işlemi değilse analize katılmaz. Temel işlem ne kadar doğru belirlenirse analiz o kadar doğru olur.

### 4.4 Problemlere göre temel işlemler

Slayttaki tablo (ekrandan, 00:55:00):

| Problem | Giriş verisinin büyüklüğü | Temel işlemler |
|---|---|---|
| $n$ elemanlı bir dizide eleman arama | Dizinin eleman sayısı $n$ | Elemanları karşılaştırma |
| İki matrisin çarpımı | Matris boyutu veya toplam eleman sayısı | İki sayının çarpımı |
| Integer bir sayının asal olup olmadığının kontrolü | $N$ sayısının dijit sayısı (ikili gösterim) | Bölme |
| Graf problemi | Düğüm / kenar sayısı | Düğüm ve kenarların gezilmesi |

Matris çarpımında bir matrisin satırıyla diğerinin sütununun elemanları çarpılır; temel işlem iki sayının çarpımıdır (son yapılan atama da dahil edilebilir). Asallık testinde kaç kez bölme yapıldığı sayılır. Graf problemlerinde düğümleri gezmek ile kenarları gezmek farklı şeylerdir; gezme (visit) temel işlem olarak tanımlanır.

Önce temel işlem belirlenir, sonra $n$ elemanlı girdiye göre temel işlemin sayısı $T(n)$ fonksiyonu olarak yazılır. Bu fonksiyon birinci, ikinci, üçüncü dereceden bir polinom, üstel ya da logaritmik olabilir. Her algoritma için $T_A(n)$, $T_B(n)$ gibi fonksiyonlar bulunur ve $n\to\infty$ iken büyüme hızları karşılaştırılır. Daha hızlı büyüyen daha çok zaman gerektirir; örneğin tahtada $T_A(n)=n^3$, $T_B(n)=n$ yazıldı ve bu durumda B algoritması daha iyidir (ekrandan, 00:55:00).

**Soru:** Algoritmalar belli aralıklarda farklı büyüme oranlarına sahip olabilir mi?
**Cevap:** Fonksiyonun yalnız bir kısmına bakılırsa evet. Örneğin $n^3$ ile $n^2+n+5$ karşılaştırılsın. $n=1$ için $1$ ile $7$, $n=2$ için $8$ ile $11$ çıkar; bu iki değerde $n^3$ daha iyi görünür. $n=3$ için $27$ ile $17$ olur ve bundan sonra fark hızla açılır. Belli bir $k$ noktasından sonra bir fonksiyon çok hızlı büyür. Aralığa göre analiz ayrı bir konudur ve daha çok veri yapıları dersinde işlenir; burada $n\to\infty$ durumuna bakılır.

Bellek de bir fonksiyonla ($S(n)$) yazılabilir. $T$ ve $S$ aynı yönde iyiyse seçim kolaydır. Ama örneğin A algoritmasının zamanı $n^3$, belleği $n$; B'nin zamanı $n^2$, belleği $n^4$ olabilir. Hoca bunu İstanbul'dan Ankara'ya yürüyerek, kendi aracıyla, trenle ya da uçakla gitme seçimine benzetti: para ve kaynak varsa daha hızlı olan seçilir. Bir milyon elemanı sıralamaya yetecek bellek varsa (gömülü sistem, kişisel bilgisayar ya da başka bir sistem) B seçilir. Bellek kısıtlıysa ve işin hemen bitmesi gerekmiyorsa A seçilir. Trade-off tam olarak budur.

> **Hocanın vurgusu:** Kavramlar önemli. Sorularda kavramlar birbirine girebiliyor; doğru kavramı doğru yerde kullanmaya dikkat edin.

## 5. Yürütme Zamanı, Alan Maliyeti ve Asimptotik İfade

### 5.1 Temel kavramlar

Slayttaki tanımlar (ekrandan, 01:00:00):

- **Yürütme zamanı (running time) $T(n)$:** Algoritmanın işlevini yerine getirebilmesi için kabul edilen (temel) işlemlerden kaç adet yürütülmesi gerektiğini gösteren matematiksel bir ifadedir. İşlem olarak karşılaştırma sayısı, çevrim sayısı ya da aritmetik işlem sayısı kabul edilir. $T(n)$ hesaplanırken hangi işleme göre hesaplandığı bildirilmelidir.
- **Alan maliyeti (space cost):** Algoritmanın işlevini yerine getirebilmesi için gerekli olan bellek ihtiyacıdır. Maliyet programın kodu, veri yapısı alanları ve yığın bellek alanıdır (stack ve heap). Alan maliyeti, algoritma rekürsif değilse ve veri yapısı alanı çok çok büyük değilse pek hesaplanmaz.

İteratif algoritmalarda alan maliyeti genelde dikkate alınmaz. Rekürsif algoritmalar ise hızdan kazandırırken bellekten kaybettirir; bu yüzden onlarda alan maliyetinin üzerinde durulur. İkisi her algoritma için hesaplanabilir, ama kitaplarda algoritmalar genellikle $T(n)$ üzerinden karşılaştırılır. Bu yetmediğinde ikinci ölçüt olarak bellek kullanılır.

### 5.2 Asimptotik ifade

Elde edilen $T(n)$ ve $S(n)$ ifadeleri asimptotik olarak incelenir. Asimptot kavramı matematikten hatırlatıldı: bir fonksiyonun düşey ve yatay asimptotları vardır; fonksiyon sonsuza giderken asimptota belki hiç değmez ama ona en çok yaklaşır (tahtada bir eğri ve kesikli asimptotları çizildi, ekrandan, 01:15:00). Burada ise yöntem, $T(n)$'ye yakın olan bilinen bir başka fonksiyonu asimptot kabul etmeye dayanır. Böylece algoritmalar en sade biçimde karşılaştırılır.

Slayttaki tanımlar (ekrandan, 01:15:00):

- **Asimptotik ifade:** Bir problemin büyümesinin üst, alt ve ortalama sınırını belirleyen bir ifadedir. Notasyonlar: Big O → $O$, Big Omega → $\Omega$, Big Theta → $\Theta$, Little O → $o$ ve Little Omega → $\omega$. Bazı kaynaklarda yalnız ilk üçü görülür; ayrıntılı kaynaklarda beşi de vardır.
- **Alan karmaşıklığı (space complexity):** Eleman sayısı $n$'nin büyük değerleri için bellek alanı gereksiniminin artışını gösteren asimptotik bir ifadedir.
- **Zaman karmaşıklığı (time complexity):** Algoritma yürütülürken geçecek zamanın artması hakkında bilgi veren asimptotik bir ifadedir. $O(g(n))$, $\Theta(g(n))$, $\Omega(g(n))$, $o(g(n))$ ile gösterilir ve veri kümesinin büyümesi durumunda çalışma süresinin nasıl etkileneceği hakkında bilgi verir.

Her algoritma için bulunan $T(n)$ bu notasyonlarla yazılır ve karşılaştırma bu sonuçlar üzerinden yapılır: "A algoritmasının Big O sonucu şu, B'ninki bu" gibi. $T(n)=1$ ise sabit, $\log n$ ise logaritmik (ikili arama gibi), $n$ ise doğrusal, $n^2$ ise karesel, $n^3$ ise kübik denir. Genel yol şudur: $T(n)$ koddan, temel işleme ve giriş boyutuna göre çıkarılır; sonra asimptotik notasyonla gösterilip yorumlanır.

## 6. Koddan T(n) Çıkarma Örnekleri

### 6.1 Ortalama bulma (BulOrta)

Slayttaki kod (ekrandan, 01:20:00):

```c
float BulOrta(float A[], int n)
{
    float ortalama, toplam = 0;
    int k;
    for (k = 0; k < n; k++)
        toplam = toplam + A[k];
    ortalama = toplam / n;
    return ortalama;
}
```

Satır satır sayım:

- `toplam=0`: 1 işlem.
- `for` döngüsü: `k=0` 1 kez, `k<n` $(n+1)$ kez (son kontrolde $k=n$ olduğu da sınanır), `k++` $n$ kez. Toplam $1+(n+1)+n=2n+2$.
- `toplam = toplam + A[k]`: atama ve toplama 2 işlem, döngü içinde $n$ kez, toplam $2n$.
- `ortalama = toplam/n`: döngü dışında bölme ve atama, 2 işlem.
- `return ortalama`: 1 işlem.

$$T(n)=1+(2n+2)+2n+2+1=4n+6$$

Değişken tanımlamaları (`float ortalama`, `int k`) sayılmaz; atama sayılır. Hocanın gerekçesi: her sayılan işlem makinede doğrudan bir komuta karşılık gelir. Atama Assembly'deki MOVE'a, `k<n` bir karşılaştırmaya (compare), `k++` bir artırmaya (increment) karşılık gelir. Artırma işlemcide tek saat çevrimlik bir işlem olarak kabul edilebilir.

Hoca bir de yalnız tekrarlı kısma bakarak sadeleştirdi: döngü gövdesindeki iki işlem $n$ kez yapılır ve $2n$ gelir; döngünün kendi kontrol ve artırması eklenince $4n$ ve sabitlerle $4n+3$ ya da $4n+6$ gibi bir ifade çıkar. $n\to\infty$ iken bu ifadede belirleyici olan $4n$'dir, hatta katsayı atılınca $n$'dir. $4n+6$, $2n$ ve $n$'nin hepsi doğrusaldır, büyüme hızları hemen hemen aynıdır. Bu yüzden sonuç $O(n)$ olacaktır.

Aynı ortalamayı diziyi gereksiz yere iki kez gezen başka bir algoritma da hesaplayabilir; onun yürütme zamanı örneğin $T_2(n)=n^2+4n$ çıkarsa ikinci algoritma daha kötüdür (tahtada $T_2(n)=n^2+4n$ yazıldı, ekrandan, 01:25:00).

Hoca döngünün çalışma sırasını da tahtada numaraladı (ekrandan, 01:25:00): önce `k=0` (1), sonra `k<n` kontrolü (2), doğruysa gövde (3), sonra `k++` (4), yine kontrol (5), gövde (6), artırma (7), kontrol (8), gövde (9)... Başlatma bir daha yapılmaz.

Döngü sayımı toplam sembolüyle de yazılabilir: $\sum_{k=0}^{n-1} 2 = 2n$. Döngü her zaman $0$'dan $n$'e kadar gitmeyebilir; örneğin $\log n$'e kadar da gidebilir. Sınırlara dikkat edilmelidir.

> **Hocanın vurgusu:** Bu tarz bir soru gelebilir. Değişken tanımlamaları değil, atama, karşılaştırma, artırma ve aritmetik işlemler sayılır; her birinin kaç kez yapıldığını kontrol etmek gerekir.

`return` satırı hakkında hocanın görüşü: `return` ve fonksiyon çağrısı programlamayla ilgilidir, algoritmayla değil. Kod bir sözde kod (pseudo code) olsaydı ne fonksiyon çağrısı ne de `return` olurdu. Bu yüzden sayılmaması önerildi; bazı kitaplar ise onu da sayar ve sayılması yanlış kabul edilmez. Dersin sonunda bir öğrenci aynı şeyi sordu:

**Soru:** $T(n)$ hesaplarken `return`'ü almadınız, slaytlarda alınmış. Hangisine göre yapacağız?
**Cevap:** Verilecek kodda `return` olmayacaktır. Sayılırsa yalnız $+1$ getirir ve yanlış kabul edilmez, ama algoritmayla ilgili olmadığı için eklenmesi pek doğru değildir.

### 6.2 Dizide en küçük elemanı bulma

<!-- BELİRSİZ: Bu örneğin kod slaytının karesi yok; aşağıdaki sayım altyazıdaki anlatımdan kuruldu. -->

Hoca kodda önce sayılacak yerleri işaretledi: başlangıçtaki atama, döngünün başlatma, kontrol ve artırma kısımları, karşılaştırma (temel işlem) ve koşula bağlı atama. Döngü $k=1$'den başlar:

- `k=1`: 1 kez.
- `k<n`: $n$ kez.
- `k++`: $n-1$ kez.
- Karşılaştırma: $n-1$ kez (her elemanla bir kez).
- Koşullu atama: belli değildir; durum analizi (case analysis) gerekir.

Durum analizinde en iyi durum (best case), en kötü durum (worst case) ve ortalama durum (average case) vardır. Bu problemde en iyi duruma bakmak "fazla iyimser, hayalperest" olur; en küçüğü bulmak için her durumda dizinin sonuna kadar bakmak gerekir. Bu yüzden en kötü durum kabul edilir: her karşılaştırmada atamanın da yapıldığı varsayılır. Gerçekte bu satır her seferinde çalışmaz; kaba analizle, örneğin bir atama sayacı tutularak, 100 elemanlı bir dizide yalnız 8 atama olduğu görülebilir. En kötü durum daha temkinli bir yaklaşım sağlar. Toplandığında yaklaşık $4n$ elde edilir.

> **Ek bilgi (derste anlatılmadı):** Başlangıçtaki `min = A[0]` ataması da sayılırsa en kötü durum için $1+1+n+(n-1)+(n-1)+(n-1)=4n-1$ çıkar. Sabit terim sayım kuralına göre değişse de mertebe $O(n)$'dir.

Hoca, sayıma fonksiyon başlığının, gelen verilerin kopyalanmasının ve `return`'ün katılmasına gerek olmadığını; soru sorulursa yalnız algoritma kısmının (ya da en fazla değişkenlerinin tanımlandığı kısmın) sorulacağını belirtti.

### 6.3 Seçmeli sıralama (selection sort)

Seçmeli sıralama bilinen en basit sıralama algoritmasıdır: dizinin birinci yeri için $n$ elemandan en küçüğü bulunup getirilir, ikinci yer için kalan $n-1$ elemandan, sonra $n-2$ elemandan... Böylece birden $n$'e kadar sayıların toplamı gibi, yani $\frac{n(n+1)}{2}$ mertebesinde bir iş çıkar.

Slayttaki kod (ekrandan, 01:30:00); hocanın belirttiği gibi bu kod C değil, C'ye benzeyen bir Java kodudur:

```java
public static int[] selectionsort(int[] A, int n)
{
    int tmp;
    int min;

    for (int i = 0; i < n-1; i++)          // I
    {
        min = i;                            // II
        for (int j = i; j < n; j++)         // III
        {
            if (A[j] < A[min]) {            // IV
                min = j;                    // V
            }
        }
        tmp = A[i];                         // VI
        A[i] = A[min];
        A[min] = tmp;
    }
    return A;                               // VII
}
```

Slayttaki sayım tablosu (ekrandan, 01:30:00):

| | İşlem | Tekrar | Toplam |
|---|---|---|---|
| I | 1, 1, 1 | 1, $n$, $n$ | $2n+1$ |
| II | 1 | $n$ | $n$ |
| III | 1, 1, 1 | $n$, $\frac{n(n+1)}{2}$, $\frac{n(n+1)}{2}$ | $n+2\frac{n(n+1)}{2}$ |
| IV | 1 | $\frac{n(n+1)}{2}$ | $\frac{n(n+1)}{2}$ |
| V | 1 | $\frac{n(n+1)}{2}$ | $\frac{n(n+1)}{2}$ |
| VI | 1, 1, 1 | 1, 1, 1 | 3 |
| VII | 1 | 1 | 1 |
| | | | $4\frac{n(n+1)}{2}+4n+5=2n^2+6n+5$ |

$$T(n)=2n^2+6n+5$$

Açıklamalar:

- I: dış döngünün başlatması 1 kez, kontrolü ve artırması $n$ kez sayılmış.
- II: `min=i` dış döngüye bağlıdır.
- III: iç döngünün başlatması her dış adımda bir kez ($n$), kontrolü ve artırması $i$'ye bağlı olarak $n$, $n-1$, ... şeklinde azaldığı için toplamda $\frac{n(n+1)}{2}$ kez.
- IV: karşılaştırma, yani bu dizinin temel işlemi, $\frac{n(n+1)}{2}$ kez.
- V: atama da en kötü durumda $\frac{n(n+1)}{2}$ kez.
- VI: takas üç atamadır (bu satırın tekrarı tabloda 1 olarak yazılmış).

Hoca II satırı hakkında şunu söyledi: bu satır dış `for`'a bağlıdır ve dış döngü `i < n-1` koşuluyla döndüğü için aslında $n-1$ kez çalışır; $n-1$ yazmak daha doğru görünür. Ama kod hazır bir kaynaktan alınmıştır ve sonuç mertebesini değiştirmez.

> **Ders sonrası not:** Dış döngü koşulu `i < n-1` olduğundan II ve VI satırları büyük olasılıkla $n-1$ kez çalışır (tablodaki VI satırının tekrarı da $1,1,1$ yerine $n-1$ olmalıdır). Tablodaki sayım bir üst yaklaşım olarak okunmalıdır; sonuç yine $O(n^2)$'dir.

Bu tablodaki değerler en kötü duruma göredir. Sıralamada en kötü durum dizinin ters sıralı olmasıdır. Hocanın sözlü örneğinde başta 8, sonda 3 olan, kabaca ters sıralı bir dizi alındı: önce en küçük 3 bulunup 8 ile yer değiştirilir, sonra kalanlar arasında 4 bulunup getirilir ve bu böyle sürer.

Zaman yoksa kısa yol (tahtada, ekrandan, 01:35:00): dış döngü $i=0$'dan $n-1$'e gider. İç döngü $i$'den $n$'e kadar birer birer ilerlediği için her dış adımda yaklaşık $n-i+1$ kez döner ve her seferinde bir karşılaştırma yapılır:

$$\sum_{i=0}^{n-1}(n-i+1)=\sum_{i=0}^{n-1}(n+1)-\sum_{i=0}^{n-1} i$$

İlk toplam $n(n+1)=n^2+n$ mertebesinde, ikincisi birden $n$'e kadar sayıların toplamı gibi $\frac{n(n+1)}{2}$ mertebesindedir. Sonuçta $n^2$'li bir terim baskın çıkar; aynı $n^2$ ifadesi buradan da bulunur. Genel kural: iki iç içe döngü varsa genelde $n^2$ çıkar, ama bazı özel durumlara bakmak gerekir.

### 6.4 Matris toplamı

<!-- BELİRSİZ: Matris toplamı kodunun karesi yok; sayım altyazıdaki anlatımdan kuruldu, sonuç python ile kontrol edildi. -->

$n$ satırlı, $m$ sütunlu iki matrisin toplamında iç içe iki döngü vardır:

- Dış döngü: $1+(n+1)+n=2n+2$.
- İç döngü: her dış adımda $1+(m+1)+m=2m+2$, toplam $n(2m+2)=2mn+2n$.
- Gövde (toplama ve atama): $2mn$.

$$T(n,m)=4mn+4n+2$$

Soruda $m=n$ kabulü yapılırsa:

$$T(n)=4n^2+4n+2$$

Bu bir kabuldür (assumption). Buraya kadarki bütün örnekler iteratif algoritmalardı; rekürsif algoritmaların $T(n)$'si daha sonra ele alınacaktır.

## 7. Fonksiyonların Büyüme Hızları ve Analiz Türleri

### 7.1 Neden büyüme hızı?

Elimizde kod ve giriş boyutu vardır; her algoritma için bir fonksiyon bulunmuştur. Bu fonksiyonlar karşılaştırılırken sonsuzdaki davranışlarına bakılır. Büyümeyi tetikleyen şey girdi boyutunun artmasıdır. Amaç, iki ya da daha fazla algoritmadan hangisinin girdi büyüdükçe daha iyi olacağını önceden bilmektir.

Karmaşıklık (complexity), bir algoritmanın üzerinde çalıştığı veri kümesinin eleman sayısı arttığında yürütme zamanı maliyetinin nasıl değişeceğini gösteren asimptotik ifadedir. Bellek için alan karmaşıklığı, yürütme için zaman karmaşıklığı denir. Karmaşıklıktaki amaç gerçek zaman ya da bellek miktarını vermek değil, veri kümesi büyüdüğünde maliyetin nasıl değiştiğini göstermektir.

### 7.2 Önemli fonksiyonların büyüme hızı

Slayttaki tablo (ekrandan, 01:40:00):

| $n$ | $\log_2 n$ | $n$ | $n\log_2 n$ | $n^2$ | $n^3$ | $2^n$ | $n!$ |
|---|---|---|---|---|---|---|---|
| $10$ | 3.3 | $10^1$ | $3.3\cdot10^1$ | $10^2$ | $10^3$ | $10^3$ | $3.6\cdot10^6$ |
| $10^2$ | 6.6 | $10^2$ | $6.6\cdot10^2$ | $10^4$ | $10^6$ | $1.3\cdot10^{30}$ | $9.3\cdot10^{157}$ |
| $10^3$ | 10 | $10^3$ | $1.0\cdot10^4$ | $10^6$ | $10^9$ | | |
| $10^4$ | 13 | $10^4$ | $1.3\cdot10^5$ | $10^8$ | $10^{12}$ | | |
| $10^5$ | 17 | $10^5$ | $1.7\cdot10^6$ | $10^{10}$ | $10^{15}$ | | |
| $10^6$ | 20 | $10^6$ | $2.0\cdot10^7$ | $10^{12}$ | $10^{18}$ | | |

Yanındaki grafikte $1$, $\log n$, $n$, $n\log n$, $n^2$, $2^n$ ve $n!$ eğrileri $n=2$'den 8'e kadar çizilmiştir.

- $\log n$: ikili arama gibi algoritmalar.
- $n$: doğrusal.
- $n\log n$: ikisinin çarpımı, linearitmik. Örnek olarak merge sort, quick sort ve heap sort verildi (tahtaya yazıldı). Bunlar veri yapıları ve algoritma analizi derslerinde görülür. Basit sıralama algoritmaları $n^2$ iken bunlar bellekten kayıp verip rekürsif mantıkla $n\log n$'e inmiştir.
- $n^2$ ve $n^3$: karesel ve kübik.
- $2^n$, $3^n$: üstel (exponential).
- $n!$: faktöriyel; çok daha kötü algoritmalar.

Sıralamadaki bu değerler en kötü durumdur. En iyi durum da incelenecektir: örneğin kabarcık sıralamada (bubble sort) dizi zaten sıralıysa her çifte bakılır, hiçbir takasa gerek olmadığı görülür ve $n$ adımda çıkılır. Algoritmalar bu fonksiyonlar cinsinden karşılaştırılır; örneğin $n^3$ olan bir algoritma $n^2$'den büyük, $2^n$'den küçüktür.

### 7.3 Analiz türleri

**En kötü durum analizi (worst case):** Algoritmanın en fazla çalışacağı varsayımıyla yapılır. Bir üst sınır (upper bound) verir; algoritmanın verilen durumdan daha uzun sürmeyeceğini garanti eder: "olsa olsa bu kadar olur". En küçüğü bulma örneğinde böyle yapıldı. Her zaman en kötü duruma bakmak zorunlu değildir, ama birçok problemde en kötü durum kullanıldığı için akla önce o gelir.

**En iyi durum analizi (best case):** Algoritmanın en kısa sürede, en az adımla çalıştığı durumdur: "en az bu kadar olur". Çalışma zamanının alt sınırını (lower bound) verir.

**Ortalama durum analizi (average case):** İkisinin arasında, gerçek uygulamada ortalama ne kadar sürdüğüdür. Örneğin 500 elemanlı rastgele diziler oluşturulup her birinin çalışma süresi hesaplanır ve ortalaması alınır. Gerçek budur ama analitik olarak zordur; bu yüzden analizler genellikle en iyi durum (alt sınır) ve en kötü durum (üst sınır) üzerinden yapılır.

Slayttaki açıklama (ekrandan, 01:45:00): Bir algoritmanın genelde en kötü durumdaki çalışma zamanına bakılır, çünkü:

- En kötü durum çalışma zamanında bir üst sınırdır ve o algoritma için verilen durumdan daha uzun sürmeyeceği garantisini verir.
- Bazı algoritmalar için en kötü durum oldukça sık rastlanır. Arama algoritmasında aranan öğe genellikle dizide olmaz, dolayısıyla döngü $N$ kez çalışır.
- Ortalama çalışma zamanı genellikle en kötü çalışma zamanı kadardır. Arama algoritması için hem ortalama hem de en kötü çalışma zamanı doğrusal fonksiyondur.

Arama örneği: en iyi durumda eleman ilk denemede bulunur ($1$); en kötü durumda $n$ deneme gerekir. Aradaki bir yerde bulunması ortalama durumdur; bu, en kötü duruma yakın kabul edilip $n$'e yaklaştırılır. Böylece en kötü ve ortalama durum $n$, en iyi durum $1$ yazılır.

### 7.4 İki algoritmanın grafikle karşılaştırılması

<!-- BELİRSİZ: Bu slaytın karesi yok; fonksiyonların hangisinin A, hangisinin B olduğu altyazıdan kesin çıkmıyor. -->

Ekranda A ve B algoritmalarının $T_A$ ve $T_B$ çalışma zamanları küçük bir aralıkta ($n\le 14$) çizildi. Bu aralıkta B daha iyi görünüyordu. Hoca eğrilerin eğimlerine bakarak ileride kesişebileceklerini, bu yüzden bu aralığa bakarak karar vermenin "ürkütücü" olduğunu söyledi. Aralık büyütüldüğünde fonksiyonların $n^2$ ve $50n$ olduğu ve $n=50$'de kesiştikleri görüldü. Sonuç: küçük bir aralığa bakmak yerine fonksiyonun tamamına ya da denklemine bakmak doğru sonuç verir.

### 7.5 Asimptotik notasyonun amacı

Slayttaki açıklama (ekrandan, 01:50:00):

- Asimptotik notasyon, eleman sayısı $n$'nin sonsuza gitmesi durumunda algoritmanın benzer işi yapan algoritmalarla karşılaştırılması için kullanılır.
- Eleman sayısının küçük olduğu durumlar mümkün olabilir, fakat bu birçok uygulama için geçerli değildir.
- Verilen iki algoritmanın çalışma zamanı $T_1(N)$ ve $T_2(N)$ fonksiyonları şeklinde gösterilir; hangisinin daha iyi olduğunu belirlemek için bir yol gerekir:
  - Big-O: asimptotik üst sınır.
  - Big $\Omega$: asimptotik alt sınır.
  - Big $\Theta$: asimptotik alt ve üst sınır.
- $f(x)$ bir algoritmanın fonksiyon şeklindeki gösterimiyse karmaşıklık $O(f(x))$, $\Omega(f(x))$, ... şeklinde gösterilir.

Örneğin $T(n)=2n^2+4n$ ifadesinde $4n$'nin $2n^2$ yanında hükmü yoktur: $n=100$ için $2n^2$ on binlerdeyken $4n$ yalnız 400'dür. İfade ayrıntılarından arındırılıp $O(n^2)$ diye yazılır (tahtada, ekrandan, 02:05:00). "Dizim olsa olsa 100 elemanlı olur" gibi bir kabul yapılmaz; eleman sayısının çok büyük olabileceği göz önüne alınmalıdır.

Hoca Big Theta'nın bazen ortalama duruma benzetildiğini ama tam olarak ortalama durum olmadığını belirtti.

## 8. Big O Gösterimi

### 8.1 Tanım

Big O bir üst sınırdır: geliştirilen algoritmanın en fazla bu kadar olabileceğini, bunu geçmeyeceğini söyler. Örneğin $T(n)$ $n^2$'li bir ifadeyse algoritma $O(n^2)$ ile gösterilir. $O(n^3)$ ya da $O(n^4)$ de onu geçmez, ama bir üst dereceye çıkmaya gerek yoktur.

Slayttaki tanım (ekrandan, 02:10:00):

> **Tanım:** $f$ ve $g$, tamsayı kümesinden veya reel sayı kümesinden reel sayılara tanımlanmış olsun ($\mathbb{Z}^+\to\mathbb{R}$). Eğer $x>k$ olduğunda $|f(x)|\le C|g(x)|$ oluyorsa ve bu eşitsizliği sağlayan $C$ ve $k$ gibi sabit sayılar varsa $f(x)=O(g(x))$ olmaktadır.

- Pozitif tamsayılara bakılır, çünkü incelenen $n$ veri boyutudur; hiçbir zaman sıfır ya da negatif olmaz.
- Mutlak değer pozitif değerleri dikkate almak içindir.
- Eşitsizlik, $k$'dan büyük bütün $x$ değerleri için tek bir $C$ katsayısıyla sağlanmalıdır. Eşitsizliği sağlayan en az bir $C$ ve $k$ çifti bulmak yeterlidir.
- Yorum: $C\,g(x)$, $f(x)$'i üstten sınırlar (baskılar).

### 8.2 En yakın üst sınırı vermek

Bir algoritmanın eğrisi $n$ ile $n^2$ arasında bir yerde kalıyorsa en yakın üst sınır $O(n^2)$'dir. Ona $O(n^3)$ ya da $O(2^n)$ demek de doğrudur, çünkü bunlar da üst sınırdır; ama hocanın deyişiyle bu "fazla mütevazı davranmak" olur ve gerek yoktur.

**Soru:** $n^2$ mertebesindeki bir algoritmaya $O(n\log n)$ diyebilir miyiz?
**Cevap:** Diyemeyiz. Bu iyimser davranmak değil, tanıma aykırıdır: $n^2\le C\,n\log n$ eşitsizliğini sağlayan bir $C$ bulunamaz. İyimser bir alt sınır söylemek için başka bir notasyon kullanılır.

### 8.3 Katsayı bularak ispat

Kitaplarda bir $T(n)$ verilip "$O(\cdot)$ olduğunu ispat edin" denir ve bu, mümkün bir $C$ katsayısı bulunarak yapılır. En kolay yol: hedef fonksiyon $n^2$ ise ifadedeki her terim $n^2$ gibi düşünülür.

- $T(n)=n^2+5$: $n\ge1$ için $n^2+5\le n^2+5n^2=6n^2$. $C=6$ ile $n^2+5=O(n^2)$.
- Aynı ifade $O(n^3)$ müdür? Her terim $n^3$ gibi düşünülürse yine $C=6$ verilebilir: $n=1$ için $1+5=6\le6$, $n=2$ için $9\le48$ ve sonrası hep sağlanır. Yani $n^2+5=O(n^3)$ de doğrudur, ama bu fazla geniş bir sınırdır; önce $n^2$'ye bakmak gerekir.
- $T(n)=n^2+5n$, $O(\log n)$ müdür? $n=1$ için sol taraf 6, $\log 1=0$; $n=2$ için de sol taraf büyük gelir. Hiçbir $C$ bulunamaz; bu yüzden $O(\log n)$ denemez. Fonksiyonların büyümesi gereği de böyledir; aynı sonuç ileride limit ve L'Hospital kuralıyla da gösterilecektir.

Hoca bu yaklaşımın ispat tekniklerine, hatta tümevarıma benzediğini belirtti: önemli olan bir tane $C$ katsayısı bulabilmektir.

### 8.4 Slayttaki örnek: $x^2+2x+1=O(x^2)$

Slayttaki örnek (ekrandan, 02:15:00):

> Show that $f(x)=x^2+2x+1$ is $O(x^2)$.

$x>1$ iken $x<x^2$ ve $1<x^2$ olduğundan:

$$0\le x^2+2x+1\le x^2+2x^2+x^2=4x^2$$

$C=4$ ve $k=1$ tanık (witness) olarak alınabilir; dolayısıyla $f(x)=O(x^2)$.

Alternatif olarak $x>2$ iken $2x\le x^2$ ve $1<x^2$ olduğundan:

$$0\le x^2+2x+1\le x^2+x^2+x^2=3x^2$$

Bu kez $C=3$ ve $k=2$ tanık olarak alınabilir. Böyle tek tek bakmaya gerek yoktur: tanıma uyan en az bir $C$ gösterilebiliyorsa ifade o notasyonla gösterilebilir. Sonuçta $x^2+2x+1$ yerine en sade haliyle $x^2$ karşılaştırılır.

### 8.5 Grafiksel gösterim

$C\,g(x)$ eğrisi belli bir $x=k$ noktasından sonra $f(x)$'in üstünde kalıyorsa (onu bastırıyorsa) $f(x)=O(g(x))$ denir. $k$'dan önceki bölüm önemli değildir; daha önce iki algoritmayı küçük bir aralıkta karşılaştırırken söylendiği gibi, bir noktaya kadar hangisinin büyük olduğu anlamlı değildir. Ders sonundaki "Big-oh" slaytında aynı şey gösterildi (ekrandan, 02:40:00): $n_0$ noktasından önceki bölge "doesn't matter" diye işaretlidir, sonrasında $c\,g(n)$ eğrisi $t(n)$'nin üstündedir; altta $t(n)\in O(g(n))$ yazar.

### 8.6 Sıralı arama ve karmaşıklık tablosu

Sıralı aramada (sequential search):

- En kötü durumda eleman en sonda bulunur: $T(n)=n$, asimptotik olarak $O(n)$.
- En iyi durumda ilk denemede bulunur: $T(n)=1$, yani $O(1)$.
- Ortalama durumda birinci, ikinci, ... konumda bulma ve bulamama olasılıkları toplanıp ortalama alınır ve $\frac{n+1}{2}$ çıkar. Bu da $O(n)$'dir, çünkü $n$, $\frac{n+1}{2}$'yi bir noktadan sonra geçer.

**Soru:** Bütün arama algoritmalarının en iyi durumu $O(1)$ mi olur?
**Cevap:** Dizide eleman aramada evet; şanslıysanız ilk elemanda bulursunuz.

Hoca $\frac{n+1}{2}$'nin "en iyi ve en kötü durumun ortalaması" olduğunu, ortalama durum analizinin olasılıklarla yapılan daha zor bir hesap olduğunu söyledi.

> **Ders sonrası not:** Aranan elemanın dizide olduğu ve her konumda eşit olasılıkla bulunabildiği kabul edilirse ortalama karşılaştırma sayısı $\frac{1+2+\dots+n}{n}=\frac{n+1}{2}$ olur. Yani bu sonuç büyük olasılıkla gerçek ortalama durumdur; burada en iyi ve en kötü durumun ortalamasıyla aynı sayıya denk gelir.

Slayttaki karmaşıklık tablosu (ekrandan, 02:20:00):

| Zaman karmaşıklığı | Açıklama | Örnek |
|---|---|---|
| $O(1)$ | Sabit: veri giriş boyutundan bağımsız gerçekleşen işlemler | Bağlı listeye ilk eleman olarak ekleme yapma |
| $O(\log N)$ | Logaritmik: problemi küçük veri parçalarına bölen algoritmalarda görülür | Binary search tree veri yapısı üzerinde arama |
| $O(N)$ | Lineer, doğrusal: veri giriş boyutuna bağlı doğrusal artan | Sıralı olmayan bir dizide bir eleman arama |
| $O(N\log N)$ | Doğrusal çarpanlı logaritmik: problemi küçük veri parçalarına bölen ve daha sonra bu parçalar üzerinde işlem yapan | $N$ elemanı böl-parçala-yönet yöntemiyle sıralama, Quick Sort |
| $O(N^2)$ | Karesel | Bir grafikte iki düğüm arasındaki en kısa yolu bulma veya Bubble Sort |
| $O(N^3)$ | Kübik | Ardarda gerçekleştirilen lineer denklemler |
| $O(2^N)$ | İki tabanında üssel | Hanoi'nin Kuleleri problemi |

Bağlı listenin başında bir `head` vardır; ilk eleman olarak ekleme doğrudan, tek adımda yapılır. İkili arama ağacında arama $\log n$'dir. Linearitmik algoritmalar (quick sort, merge sort, heap sort) daha çok rekürsif algoritmalarla birlikte görülür.

Hanoi kuleleri: büyükten küçüğe dizili diskler, bir boş direk yardımıyla başka bir direğe taşınır; büyük bir disk kendisinden küçük bir diskin üstüne konamaz. Hoca disk sayısı 3 ise 8, 4 ise 16, 10 ise 1024 hamle gerektiğini ve bunun iki tabanında üstel bir algoritma olduğunu söyledi.

> **Ders sonrası not:** Hanoi kulelerinde $n$ disk için en az hamle sayısı $2^n-1$'dir: 3 disk için 7, 4 disk için 15, 10 disk için 1023. Mertebe yine $O(2^n)$'dir.

### 8.7 Fonksiyonları büyüme mertebesine göre sıralama

Slayttaki alıştırma (ekrandan, 02:25:00): Aşağıdaki fonksiyonları, her biri listede kendinden sonrakinin big-O'su olacak şekilde sıralayın.

- $f_1(n)=(1.5)^n$
- $f_2(n)=8n^3+17n^2+111$
- $f_3(n)=(\log n)^2$
- $f_4(n)=2^n$
- $f_5(n)=\log(\log n)$
- $f_6(n)=n^2(\log n)^3$
- $f_7(n)=2^n(n^2+1)$
- $f_8(n)=n^3+n(\log n)^2$
- $f_9(n)=10000$
- $f_{10}(n)=n!$

Hoca genel sırayı hatırlattı: en büyük faktöriyel, sonra üsteller, sonra polinomlar, sonra $n\log n$ türü linearitmikler, sonra logaritma, en küçük de sabittir. Bu sırayla büyükten küçüğe gitti:

- En büyük $f_{10}=n!$.
- Üsteller: $f_7=2^n(n^2+1)$, $2^n$'ye bir $n^2$ çarpanı eklendiği için $f_4=2^n$'den büyüktür (ikisi de $2^n$ mertebesinde görünse de). Sonra $f_1=(1.5)^n$ gelir.
- Kübikler: $f_8$ ve $f_2$ ikisi de $n^3$ mertebesindedir, aynı sırada sayılır.
- Sonra $f_6=n^2(\log n)^3$.
- Logaritmikler: $f_3=(\log n)^2$ ile $f_5=\log(\log n)$. $n=256$ için $\log n=8$ ve $\log\log n=3$; $(\log n)^2=64$ olduğundan $f_5$ daha küçüktür. Hoca tahtada önce bu ikisinin sırasını karıştırdığını söyleyip düzeltti.
- En küçük $f_9=10000$: sabittir, $n$'ye bağlı değildir. Girdi 10.000 de olsa 100.000 de olsa iş miktarı değişmez; bu yüzden $O(1)$'dir.

Slayttaki çözüm, en yavaş büyüyenden başlayarak (ekrandan, 02:25:00):

$$f_9 \prec f_5 \prec f_3 \prec f_6 \prec f_2 \sim f_8 \prec f_1 \prec f_4 \prec f_7 \prec f_{10}$$

Slayttaki gerekçeler: $f_9$ sabittir; $f_5$ diğerlerinin hepsinden yavaş büyür; $f_3$ ondan sonra gelir; $f_6$'da $(\log n)^3$ çarpanı $n$'nin her kuvvetinden küçüktür; $f_2$ ile $f_8$ eşit sayılır; $f_1$ bir sonraki, üstel bir fonksiyondur; $f_4$, $2>1.5$ olduğu için daha hızlı büyür; $f_7$, $n^2+1$ çarpanı yüzünden daha hızlıdır; $n!$ her $c$ için $c^n$'den hızlı büyür.

### 8.8 $2^n = O(n!)$ mi?

**Soru (derste sözlü):** $2^n$, $O(n!)$'in elemanı mıdır? İspatlayın.

Gösterilmesi gereken: bir $C$ için $2^n\le C\cdot n!$. Hoca $n!$ için Stirling formülünün de kullanılabileceğini söyledi, ama $C$ değerlerini deneyerek ilerledi:

- $C=1$, $n=1$: $2\le1$ değil; olmadı.
- $C=2$, $n=1$: $2\le2$, sağlanır.
- $C=3$, $n=1$: $2\le3$, sağlanır.

Hoca, bir $C$ bulunduktan sonra $n!$'in $2^n$'yi her zaman baskıladığını söyledi. Dolayısıyla $2^n=O(n!)$.

> **Ek bilgi (derste anlatılmadı):** $C=2$ ile bütün $n\ge1$ değerleri sağlanır: $n=1,2,3,4,5$ için sol taraf $2,4,8,16,32$, sağ taraf $2,4,12,48,240$'dır; $n$ bir arttığında sol taraf 2 ile, sağ taraf $n+1\ge2$ ile çarpılır.

## 9. Big Omega ve Big Theta Gösterimleri

### 9.1 Big Omega

Big Omega, küçük omeganın büyük halidir. Alt sınırı verir; hocanın anlatımında en iyi durum analizinde kullanılan yöntemdir. Big O'nun tersidir: $f(x)$, $g(x)$'ten en az onun kadar hızlı büyüyorsa ve

$$|f(x)|\ge C|g(x)|,\quad x>k$$

eşitsizliğini sağlayan $C$ ve $k$ sayıları varsa $f(x)=\Omega(g(x))$ yazılır.

Big O ile Big Omega arasında sıkı bir ilişki vardır:

$$f(x)=\Omega(g(x)) \iff g(x)=O(f(x))$$

Örneğin $2^n$ ve $3^n$ için $3^n=\Omega(2^n)$ yazılabilir.

<!-- BELİRSİZ: Big Omega örnek slaytının karesi yok; fonksiyon altyazıdan "8x³+5x²+7" olarak alındı. -->

Örnek: $f(x)=8x^3+5x^2+7$ ve $g(x)=x^3$ için $f(x)=\Omega(g(x))$ olduğunu gösterin. Her terim pozitif olduğundan $x$'in pozitif değerleri için $8x^3+5x^2+7\ge x^3$ olur; yani $C=1$ ile $f(x)=\Omega(x^3)$. Negatif değerler katılırsa işler bozulur, ama zaten yalnız pozitif değerler incelenir.

Hoca bir de tersini, yani $g(x)=x^3$'ün $f(x)$ cinsinden Omega olup olmadığını tanımlardan yola çıkarak çalışma sorusu olarak bıraktı (Örnek Sorular bölümüne bakın).

### 9.2 Big Theta

Hoca daha fazla örneği olduğunu, ama diğer grubun hocasıyla bunların veri yapıları dersine bırakılmasına karar verildiğini söyledi.

Big Theta, $f$ ve $g$ için hem Big Omega'nın hem de Big O'nun koşullarını aynı anda sağlar: bir $C_1$ katsayısı $g$'yi $f$'in altında, bir $C_2$ katsayısı $f$'in üstünde gösterir.

Slayttaki tanım (ekrandan, 02:30:00):

> **Tanım:** $f$ ve $g$, tamsayı kümesinden veya reel sayı kümesinden reel sayılara tanımlanmış olsun ($\mathbb{Z}^+\to\mathbb{R}$). Eğer $f(x)$, $O(g(x))$ ve $f(x)$, $\Omega(g(x))$ ise $f(x)$, $\Theta(g(x))$ deriz. Eğer $x>k$ olduğunda $C_1|g(x)|\le|f(x)|\le C_2|g(x)|$ oluyorsa ve bu eşitsizliği sağlayan pozitif $C_1$ ve $C_2$ reel sayıları ve bir pozitif $k$ reel sayısı bulunabiliyorsa bu durumda $f(x)$'in $\Theta(g(x))$ olduğunu gösterebiliriz.

$x^2$, $O(x^3)$ olarak gösterilebilir ama $\Theta(x^3)$ olarak gösterilemez; çünkü Theta fonksiyonu hem alttan hem üstten sınırlar. Bu yüzden daha ayrıntılı ve kesine daha yakın (tam kesin değil) bir analiz sağlar.

Bir ifadenin $\Theta(x^2)$ olduğunu göstermek için önce üst sınır için bir $C_2$ (örneğin 8 gibi) bulunur, sonra alt sınır için daha küçük olduğunu gösteren bir $C_1$ bulunur. İkisi bulunursa ifade hem $O(x^2)$ hem $\Theta(x^2)$ olur. <!-- BELİRSİZ: Bu örnekteki fonksiyon ve katsayılar ekranda okunmadı. -->

Theta simetriktir:

$$f(x)=\Theta(g(x)) \iff g(x)=\Theta(f(x)) \iff f(x)=O(g(x)) \text{ ve } g(x)=O(f(x))$$

> **Hocanın vurgusu:** Bazı kaynaklarda Big O'nun Big Theta ile aynı olduğunu görebilirsiniz; bu bir hatadır, tam aynı değildir. Theta aralığın kesin sınırını verir.

### 9.3 Arama ve sıralama algoritmalarının karmaşıklıkları

Ekranda Wikipedia'dan alınmış, arama ve sıralama algoritmalarının en iyi ve en kötü durum zaman ve alan karmaşıklıklarını Big O cinsinden karşılaştıran tablolar gösterildi; graf ve heap algoritmalarına graflar konusunda dönülecek. Sıralamada en kötü durum ters sıralı diziden kaynaklanır: her şeyi baştan sona tek tek yer değiştirmek gerekir. Hocanın verdiği kısa yol: dizinin ters sıralı olduğu bir şekilde tespit edilebilirse diziyi ters çevirmek, onu sıralamaktan çok daha kolaydır. Ama bunu önceden bilmenin yolu yoksa en kötü duruma takılınır.

## 10. Bileşik Algoritmalar, Limit ve Tümevarım Yöntemleri

### 10.1 Birden fazla alt programdan oluşan algoritmalar

Slayttaki kural (ekrandan, 02:35:00): Birçok algoritma birden fazla alt programdan oluşabilir.

$$f_1\to O(n^c),\quad f_2\to O(n^d),\quad 1<c<d \;\Rightarrow\; \max(O(n^c),O(n^d))=O(n^d)$$

Hangi parça daha maliyetliyse o seçilir. Tahtadaki örnekler: $2^n$ ile $3^n$ arasında $3^n$, $n^3$ ile $n^2$ arasında $n^3$ seçilir.

Örnek problem: iki matrise eleman girilecek, matrisler çarpılacak ve sonuç ekrana yazdırılacak.

- Matrise eleman okuma: $n^2$.
- Kare matrislerin çarpımı: $n^3$.
- Sonucu ekrana yazdırma: $n^2$.

Programın genelinde $n^3$'lük bir çarpma algoritması olduğu için problem üzerine geliştirilen algoritma $O(n^3)$'tür; en üst derece alınır. Diğer örnekler: $\log n$ ile $n$'den $O(n)$; $2n$ ile $2^n$'den $O(2^n)$; $n^2$ ile $n^2$'den $O(n^2)$.

Burada karşılaştırılan şey $T(n)$'lerin kendisi değil, asimptotik halleridir. Örneğin biri $2n^2+5n$, diğeri $n^2-n$ olsa ikisi de $O(n^2)$ ya da $\Theta(n^2)$ olarak görülür.

### 10.2 Toplam ve çarpımlardan oluşan ifadeler

<!-- BELİRSİZ: Bu iki örneğin slayt karesi yok; ifadeler altyazıdan kuruldu. -->

Örnek: $f(n)=3n\log(n!)+(n^2+3)\log n$ fonksiyonunun Big O karşılığı. İlk terimde $3n$ kısmı $O(n)$'dir. $\log(n!)$ ise $n!$ değil, logaritmik bir ifadedir: $\log(n!)\le\log(n^n)=n\log n$ yazılır. Böylece ilk terim $n\cdot n\log n=n^2\log n$ olur. İkinci terim $(n^2+3)\log n$ da $n^2\log n$ mertebesindedir. Sonuç: $f(n)=O(n^2\log n)$. Hoca $\log(n!)$'in "doğrudan $n!$ diye" alınmaması gerektiğine dikkat çekti.

Örnek: $f(x)=(x+1)\log(x^2+1)+3x^2$. $(x+1)$ kısmı $O(x)$, $\log(x^2+1)$ kısmı $\log(x^2)=2\log x$ gibidir; çarpımları $x\log x$ mertebesindedir. Diğer terim $3x^2$, yani $x^2$'dir. $x^2$ daha büyük olduğu için $f(x)=\Theta(x^2)$ (dolayısıyla $O(x^2)$).

Polinom biçimindeki bir çalışma zamanında Big O, Big Theta ve Big Omega için doğrudan en büyük terim alınır; diğer terimler göz ardı edilir. Örneğin bir ifadede $x^5$, diğerinde $x^{199}$ en büyük terimse sonuç onlara göre yazılır.

### 10.3 Büyüme mertebesinin anlamı

- $f(n)=O(g(n))$: $f$, $g$'den daha hızlı büyümez; $g$ daha hızlı (ya da aynı hızda) büyür.
- $f(n)=\Theta(g(n))$: $f$, $g$ ile neredeyse aynı hızda büyür (slaytta "at the same rate").
- $f(n)=\Omega(g(n))$: $f$, en az $g$ kadar hızlı büyür; hocanın deyişiyle en iyi durumda $g$ kadar bir çalışma vardır.

Grafiksel gösterimler (ekrandan, 02:40:00): Big O'da $c\,g(n)$ eğrisi $t(n)$'yi üstten sınırlar; Big Omega'da $c\,g(n)$ $t(n)$'nin altında kalır, yani en az bu kadar çalışacağını gösterir; Big Theta'da $t(n)$, $c_1 g(n)$ ile $c_2 g(n)$ arasında kalır.

### 10.4 Limit yöntemi

Algoritmaları karşılaştırmanın asıl yolu tanımlardır. Bir diğer teknik limit kullanmaktır:

$$\lim_{n\to\infty}\frac{T(n)}{g(n)}=
\begin{cases}
0 & \Rightarrow\; T \text{ daha yavaş büyür},\; T(n)\in O(g(n))\\
c>0 & \Rightarrow\; \text{aynı mertebe},\; T(n)\in\Theta(g(n))\\
\infty & \Rightarrow\; T \text{ daha hızlı büyür},\; T(n)\in\Omega(g(n))
\end{cases}$$

Limit sıfırsa "sayı bölü sonsuz" gibidir: payda daha büyüktür. Sabit bir sayı ($4$, $2$ gibi) çıkarsa iki fonksiyonun büyümesi hemen hemen eşittir. Sonsuz çıkarsa pay daha hızlı büyür. Belirsizlik ($\infty/\infty$) çıkarsa türev alınır (L'Hospital kuralı). Logaritmanın ve $2^n$'nin türevini almak kolaydır, ama $n!$'in türevi sorun çıkarır; onu yaklaşık bir ifadeyle (Stirling) düşünmek gerekir. Hoca bunun matematik dersi olmadığını, $n!$'in türevinin sorulmayacağını belirtti.

Örnek: $f(x)=4x^3+3x^2$ ve $g(x)=x^4$ için $f$'i $g$ cinsinden yazın. <!-- BELİRSİZ: Fonksiyonlar ekranda görülmedi; altyazıdan "4x³+3x²" ve "x⁴" olarak kuruldu. -->

$$\lim_{x\to\infty}\frac{4x^3+3x^2}{x^4}=\lim_{x\to\infty}\left(\frac{4}{x}+\frac{3}{x^2}\right)=0$$

Limit sıfır olduğu için $4x^3+3x^2=O(x^4)$. Aslında $O(x^3)$ da olur, ama soru böyle verilmiştir. Aynı sonuç tanım yoluyla da gösterilebilir: $x\ge1$ için $4x^3+3x^2\le 4x^4+3x^4=7x^4$, yani $C=7$ ile bütün $x\ge1$ değerlerinde sağlanır. Aynı yöntem $O(x^3)$ için de denenebilir.

### 10.5 Tümevarım yöntemi

Bazı fonksiyonların türevini ya da limitini almak zordur; o zaman tümevarım (induction) kullanılabilir.

Slayttaki örnek (ekrandan, 02:45:00): $n>6$ ve $n$ bir tamsayı iken $3n<n!$ olduğunu ispatlayın. Tümevarım olabilir veya Big O kullanılır.

1. $n\in\{7,8,9,\dots\}$ kümesinden. $n=7$ için $3\cdot7=21<7!=5040$, doğru.
2. $n=k$ için doğru kabul edilir: $3k<k!$.
3. $n=k+1$ için doğruluğu gösterilir:

$$3(k+1)\overset{?}{<}(k+1)!$$
$$3k+3<(k+1)\cdot k!$$
$$3k+3<k\cdot k!+k!$$

$k>6$ için $k!>3k$ doğru kabul edildi. Burada $k\cdot k!>3$ olduğu ispat edilmeli; $k>6$ için bu doğrudur. O halde $3n<n!$ doğrudur.

Bu sonuç, $3n$'nin $O(n!)$'in elemanı olduğunu da söyler (burada Big Theta değil Big O kullanılır). Aynı şey limit ya da Big O tanımıyla da gösterilebilirdi; tanımda $C$ katsayısını bulmak şartıyla.

### 10.6 Karmaşıklık sınıflarının özeti

Ders sonunda sınıflar yeniden sıralandı: $O(1)$ sabit, logaritmik, doğrusal $O(n)$, linearitmik, polinom, üstel ve faktöriyel.

> **Hocanın vurgusu:** Polinom ile üsteli karıştırmayın. Polinomda $n$ aşağıdadır ($n^2$, $n^3$); üstelde $n$ yukarıdadır ($2^n$).

Üstel algoritma örnekleri: doğruluk tablosu oluşturmak ve parola denemek. Türkçede 29 büyük harf vardır. 6 haneli parolanın her hanesine 29 harften biri gelebilir; bütün parolaları deneyen bir algoritma $29^6=594\,823\,321$ deneme yapar. Hane sayısı $n$ ise deneme sayısı $29^n$'dir ve algoritma üsteldir. Son olarak, farklı problem boyutlarında bu karmaşıklıklardaki algoritmaların kaç saniye sürdüğünü ve kaç bit işlemi kullandığını gösteren, her kaynakta bulunabilen bir tablo gösterildi. <!-- BELİRSİZ: Bu son tablonun karesi yok; değerleri aktarılmadı. -->

Bu derste iteratif ve özyinelemeli algoritmaların analizine henüz gelinmedi; işlenenler konunun en temel kısmıdır.

## Örnek Sorular

### Soru 1 (derste sözlü, 00:16:00)

$n$ elemanlı sırasız bir dizide ya da bağlı listede, kesinlikle var olan bir eleman en fazla kaç denemede bulunur? Sıralı dizide ve sıralı, düzgün dağılımlı dizide durum nedir? $n=256$ için hesaplayın.

**Çözüm (derste verildi):** Sırasız dizide en fazla $n$ deneme. Sıralı dizide ikili arama ile $\log_2 n$, sıralı ve düzgün dağılımlı dizide interpolasyon araması ile $\log_2\log_2 n$. $n=256$ için sırasıyla 256, 8 ve 3 deneme.

### Soru 2 (ekrandan, 00:50:00)

"Temel işlem (basic operation): algoritmanın çalışma süresini en çok etkileyen işlemdir. Sıralamada ........ temel işlemdir." Boşluğu doldurun.

**Çözüm (derste verildi):** Karşılaştırma (comparison). Takas her adımda yapılmadığı için temel işlem değildir.

### Soru 3 (ekrandan, 01:20:00)

`BulOrta` fonksiyonunun (bkz. 6.1) $T(n)$'sini bulun.

**Çözüm (derste verildi):** $T(n)=1+(2n+2)+2n+2+1=4n+6$; asimptotik olarak $O(n)$.

### Soru 4 (ekrandan, 01:30:00)

`selectionsort` fonksiyonunun (bkz. 6.3) en kötü durum $T(n)$'sini satır satır sayım tablosuyla bulun.

**Çözüm (derste verildi):** $T(n)=(2n+1)+n+\left(n+2\tfrac{n(n+1)}{2}\right)+\tfrac{n(n+1)}{2}+\tfrac{n(n+1)}{2}+3+1=2n^2+6n+5$, yani $O(n^2)$.

### Soru 5 (derste sözlü, 01:35:26)

$n\times m$ iki matrisin toplamını yapan iç içe iki döngülü kodun $T(n)$'sini bulun; $m=n$ kabul edin. <!-- BELİRSİZ: Kod ekranda görülmedi. -->

**Çözüm (derste verildi):** $T=4mn+4n+2$; $m=n$ için $T(n)=4n^2+4n+2$.

### Soru 6 (ekrandan, 02:15:00)

$f(x)=x^2+2x+1$ fonksiyonunun $O(x^2)$ olduğunu gösterin.

**Çözüm (derste verildi):** $x>1$ için $0\le x^2+2x+1\le x^2+2x^2+x^2=4x^2$; $C=4$, $k=1$. Ya da $x>2$ için $\le3x^2$; $C=3$, $k=2$.

### Soru 7 (ekrandan, 02:25:00)

$f_1(n)=(1.5)^n$, $f_2(n)=8n^3+17n^2+111$, $f_3(n)=(\log n)^2$, $f_4(n)=2^n$, $f_5(n)=\log(\log n)$, $f_6(n)=n^2(\log n)^3$, $f_7(n)=2^n(n^2+1)$, $f_8(n)=n^3+n(\log n)^2$, $f_9(n)=10000$, $f_{10}(n)=n!$ fonksiyonlarını, her biri kendinden sonrakinin big-O'su olacak şekilde sıralayın.

**Çözüm (derste verildi):** $f_9, f_5, f_3, f_6, f_2, f_8, f_1, f_4, f_7, f_{10}$ ($f_2$ ile $f_8$ aynı mertebede).

### Soru 8 (derste sözlü, 02:25:38)

$2^n$, $O(n!)$'in elemanı mıdır? İspatlayın.

**Çözüm (derste verildi):** Evet. $C=2$ için $n=1$'de $2\le2$ sağlanır ve $n!$ bundan sonra $2^n$'yi hep baskılar; $2^n\le 2\cdot n!$.

### Soru 9 (derste sözlü, 02:29:01)

$f(x)=8x^3+5x^2+7$ ve $g(x)=x^3$ için önce $f(x)=\Omega(x^3)$ olduğunu gösterin. Sonra $g(x)=x^3$'ün $f(x)$ cinsinden Omega olup olmadığını (yani $x^3=\Omega(8x^3+5x^2+7)$ olup olmadığını) önceki tanımlardan yola çıkarak inceleyin. <!-- BELİRSİZ: Çalışma sorusunun tam metni ekranda görülmedi; altyazıdaki "Gx, x küp ise Omega bu var mıdır" ifadesinden bu biçimde yorumlandı. -->

İlk kısım derste verildi: pozitif $x$ için $8x^3+5x^2+7\ge x^3$, $C=1$.

> **Çözüm (derste verilmedi):** $x\ge1$ için $8x^3+5x^2+7\le 8x^3+5x^3+7x^3=20x^3$, yani $x^3\ge\frac{1}{20}(8x^3+5x^2+7)$. $C=\frac{1}{20}$, $k=1$ ile $x^3=\Omega(8x^3+5x^2+7)$ doğrudur. İki yön birlikte $8x^3+5x^2+7=\Theta(x^3)$ demektir. Kontrol: $x=1$ için $20\le20$, $x=2$ için $91\le160$.

### Soru 10 (derste sözlü, 02:42:47)

$f(x)=4x^3+3x^2$ fonksiyonunu $g(x)=x^4$ cinsinden limit kullanarak yazın. <!-- BELİRSİZ: Fonksiyonlar altyazıdan kuruldu. -->

**Çözüm (derste verildi):** $\lim_{x\to\infty}\frac{4x^3+3x^2}{x^4}=0$, dolayısıyla $f(x)=O(x^4)$. Tanım yoluyla $C=7$: $x\ge1$ için $4x^3+3x^2\le7x^4$.

### Soru 11 (ekrandan, 02:45:00)

$n>6$ ve $n$ bir tamsayı iken $3n<n!$ olduğunu ispatlayın.

**Çözüm (derste verildi):** Tümevarım. $n=7$: $21<5040$. $3k<k!$ kabul edilir. $3(k+1)=3k+3<k\cdot k!+k!=(k+1)!$, çünkü $3k<k!$ ve $k>6$ için $3<k\cdot k!$. Dolayısıyla $3n<n!$ ve $3n=O(n!)$.

## Dersin Toparlaması

Ders, veri yapılarının algoritmaların verimliliğini nasıl etkilediğiyle başladı: sırasız dizide doğrusal, sıralı dizide logaritmik, düzgün dağılımlı sıralı dizide $\log\log n$ adımda arama yapılabilirken hash tabloları ideal durumda tek adımda erişim sağlar. Hash fonksiyonlarının parola saklamadaki kullanımı, fonksiyonların birebirlik ve ters alınabilirlik özellikleriyle ayrık matematiğe bağlandı.

Dersin ana kısmı algoritma analizine ayrıldı. Algoritmalar doğruluk, zaman ve bellek ölçütleriyle karşılaştırılır ve bunlar arasında bir trade-off vardır. Teorik analizde önce temel işlem belirlenir, sonra koddan temel işlemin tekrar sayısı $T(n)$ olarak çıkarılır (BulOrta için $4n+6$, seçmeli sıralama için $2n^2+6n+5$, matris toplamı için $4n^2+4n+2$). $T(n)$ en kötü, en iyi ya da ortalama duruma göre yazılabilir. Sonra $n\to\infty$ davranışına bakılarak Big O (üst sınır), Big Omega (alt sınır) ve Big Theta (sıkı sınır) ile ifade edilir. Bunun için tanımdaki $C$ ve $k$ sabitleri bulunur, limit alınır ya da tümevarım kullanılır. Bir sonraki adım, iteratif ve özyinelemeli (rekürsif) algoritmaların analizidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
