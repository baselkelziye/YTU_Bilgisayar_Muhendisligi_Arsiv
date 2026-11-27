# Ders 2 Genişletilmiş Notu: Algoritma Geliştirme, Bağlantı Problemi ve Hızlı Bulma Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri ve Planı
- 2. Algoritma Geliştirmek
- 3. Bağlantı Problemi
- 4. Problemin Gerçek Dünya Karşılıkları
- 5. Problemi Tanımlamak ve Değiştirmek
- 6. Hızlı Bulma (Quick-Find) Çözümü
- 7. Adım Adım Örnek
- 8. Hızlı Bulma Kodu
- 9. C ile Dinamik Matris Yaratma
- 10. Örnek Sorular

## 1. Dersin Yeri ve Planı

Bu kayıt haftanın kısa uygulama saatidir ve yaklaşık bir saat sürer. Hoca, pazartesi günkü teorik derste veri, veri yapısı ve algoritma kavramlarının tanımlandığını, algoritmanın sözde kod ve akış diyagramıyla nasıl ifade edildiğini, bir algoritmanın taşıması gereken özellikleri ve dersteki geliştirmelerin ANSI C ile yapılacağı için C dilinin ince noktalarını hatırlattı.

Bu saatin planı şöyle açıklandı: önce "çok basit değil ama zor bir problemin basit bir çözümü" birlikte tasarlanacak, yani bir algoritma geliştirilip nasıl çalıştığına bakılacak. Sonra C ile ilgili kısa kod parçaları (işaretçiler, işaretçilerle dizi oluşturma, dinamik bellek ayırma, `typedef`, `struct`) ve basit bir simülasyon örneği gösterilecekti. Zaman yetmediği için derste yalnız bağlantı problemi ve dinamik matris örneği işlendi; kalan iki örnek sonraki derslere bırakıldı.

## 2. Algoritma Geliştirmek

### 2.1 Önce doğru ve basit çözüm

Hoca algoritma geliştirmenin "şu bölümü okuyun, şu soruları çözün, algoritma geliştirmeyi öğrendiniz" diye öğrenilebilecek bir konu olmadığını söyledi. Elimizde bir problem vardır ve bu problemi verilen kısıtlara göre mümkün olan en iyi şekilde çözmeye çalışırız. Ancak bütün kısıtları karşılayan güzel bir çözümü tek adımda üretmek her zaman mümkün değildir. Bu yüzden "çiğneyebileceğimiz boyutta lokmalar" alınır: problem küçültülebilir ya da önce basit bir çözüm kurulur.

Slayttaki ana fikir şudur (ekrandan, 00:10:00):

- Problemi mümkün olan en iyi şekilde çözmeye çalışırız.
  - Önce, problemi doğru çözen basit bir algoritma tasarlamalıyız.
    - Küçük örneklerde analiz yapmamızı kolaylaştırır.
    - Performans ölçümü için temel seviyemizi belirler.
  - Sonra algoritmamızı iyileştirebiliriz.

> **Hocanın vurgusu:** En önemli şey doğru çözmektir. Yanlış çözen bir yöntem istediği kadar hızlı olsun, değerli bir yöntem değildir.

Bu ilk çözüm (initial solution) hem düşünmesi hem gerçekleştirmesi basit olmalıdır; belki bildiğimiz adımları sırayla işleterek kurulur. Ne sağladığı şöyle anlatıldı:

- 100 ya da 1000 örnekli küçük veri kümelerinde hızlı analiz yapılabilir, yöntemin gerçekten doğru çalışıp çalışmadığına ve uç durumlara bakılabilir.
- Bir karşılaştırma temeli (baseline) oluşur. Örneğin 1000 örnek için program 10 saniyede çalışıyorsa, daha iyi bir tasarımla bu 5 saniyeye ya da 1 saniyeye indirilmeye çalışılır. En azından "bu problemi şu kadar zamanda, şu performansla çözebiliyorum" denebilir.

Ardından algoritma üzerine oturup düşünülür: algoritmik çözüm yöntemleri denenir, belki alternatif veri yapıları kullanılır ve algoritma daha kısa zamanda ya da daha az bellekle çalışacak hâle getirilir. Bu iyileştirme adım adım (iteratif) yapılır.

### 2.2 Veri yapıları ve algoritmalar el eledir

Algoritma bir probleme çözüm getirme yoludur, ama tek başına her zaman yeterli değildir. Hoca, dersin ve müfredatların adının bu yüzden "veri yapıları ve algoritmalar" olduğunu söyledi. Slaytta iki karşıt durum vardır (ekrandan, 00:10:00):

- Basit bir algoritma karmaşık bir veri yapısı kullanabilir. "İki tane `for`, bir tane `if` yazmışlar" denebilecek bir algoritma gücünü karmaşık ya da verimli çalışan bir veri yapısından alıyor olabilir.
- Karmaşık bir algoritma çok basit veri yapıları kullanabilir. Okurken anlamakta zorlanılan bir algoritma yalnız dizi kullanıyor olabilir.

Hangisine yüklenileceği konusunda kesin bir kural yoktur. Probleme ve ortama göre veri yapısı ve algoritma birlikte, bütünleşik bir çözüm olarak düşünülmelidir.

### 2.3 Para harcamak ya da algoritmayı iyileştirmek

Hoca $n$ elemanı $n^2$ mertebesinde (kuadratik karmaşıklıkla) sıralayan düz bir sıralama algoritması örneğini verdi. 100 milyon örneği eldeki bilgisayarla 10 dakikada sıralayabildiğimizi düşünelim. Çok işlemcili, bütün veriyi bellekte tutabilecek, 10 ya da 100 kat güçlü bir sunucu alıp aynı programı çalıştırırsak program 10-100 kat hızlanır; ama bunun için binlerce dolar harcanır. Bunun yerine algoritma elden geçirilip farklı yaklaşımlar ya da veri yapıları kullanılarak 10 kat hızlı çalışacak biçimde tasarlanırsa o para cepte kalır ya da başka yerde kullanılır (ekrandan, 00:10:00).

> **Ders sonrası not:** Hoca kuadratik karmaşıklık için "üstsel karmaşıklık" ifadesini de kullandı. Doğrusu $n^2$ büyümesi polinomsaldır; üstsel (exponential) karmaşıklık $2^n$ gibi büyümeleri anlatır.

Son madde olarak, belirli bir iş için en iyi algoritmayı seçmenin oldukça karmaşık olabileceği söylendi. Algoritmaları karşılaştırmak bazen çok matematik gerektirir. Algoritma analizine derste çok girilmeyecek, ama temelleri sonraki iki haftada görülecektir. Matematiksel analiz zor olduğunda basit zaman ölçümleri gibi pratik yollar kullanılabilir.

Özetle algoritma tasarımı için hazır bir reçete yoktur. Problemi sakin ve analitik biçimde anlamak, gerekirse problemi biraz değiştirmek ve ona uygun bir tasarım yapmak gerekir.

## 3. Bağlantı Problemi

### 3.1 Tanım

Örnek olarak bilgisayar biliminin temel problemlerinden biri olan bağlantı problemi (connectivity problem) seçildi. Slayttaki tanım şöyledir (ekrandan, 00:20:00):

- Birbiri ile bağlantıda olan varlık çiftleri veriliyor.
  - `p-q` → `p` ile `q` bağlıdır (`q` da `p` ile bağlıdır).
  - Kolay olması için her varlık bir tamsayı ile ifade edilsin.
- Amacımız, sadece yeni (önceden var olmayan) bağlantıları bulmak.

`p-q` girdisi, `p` varlığının `q` varlığına bağlı olduğunu söyler: belki gerçekten kabloyla bağlı iki bilgisayar, belki sosyal ağda birbirini takip eden iki kişi. İşi basitleştirmek için bağlantı çift yönlüdür; hoca bunu "ben seni takip ediyorum, sen beni takip etmiyorsun gibi bir şey yok; bağlandıysak bağlandık" diye açıkladı. Programlamayı kolaylaştırmak için her varlık benzersiz bir tamsayıyla, örneğin bir kimlik numarasıyla gösterilir: 3-4 çifti, kimlik numarası 3 olan kişiyle 4 olan kişinin arkadaş olduğunu söyler.

Amaç, aralarında zaten (dolaylı da olsa) bağlantı olan bir çifti bir daha bağlamamaktır: oraya bir daha kablo çekmek ya da veritabanında yeni bir satır açmak istemeyiz. 3-4 ve 4-9 bağlıysa 3 ile 9 da 3-4-9 yoluyla bağlıdır. Bu bir küme mantığıdır: birbiriyle bağlantılı bütün elemanlar aynı kümededir.

### 3.2 Örnek girdi

Slayttaki örnek dizi şudur (ekrandan, 00:20:00):

| Sıra | Çift | Durum |
|---|---|---|
| 1 | 3-4 | yeni bağlantı |
| 2 | 4-9 | yeni bağlantı |
| 3 | 8-0 | yeni bağlantı |
| 4 | 2-3 | yeni bağlantı |
| 5 | 5-6 | yeni bağlantı |
| 6 | 2-9 | zaten bağlı (2-3-4-9 vardı) |
| 7 | 5-9 | yeni bağlantı |
| 8 | 7-3 | yeni bağlantı |
| 9 | 4-8 | yeni bağlantı |
| 10 | 0-2 | zaten bağlı (0-8-4-3-2 vardı) |
| 11 | 6-1 | yeni bağlantı |

Slaytta 2-9 ve 0-2 kırmızıdır. Hoca bunların "yüzünden bağlı" demek istemediğini, bu çiftlerin zaten birbirini gördüğünü ve bu yüzden yeniden bağlanmayacağını vurguladı. Bu sonuç python ile doğrulandı.

### 3.3 Sınıfta gelen öneriler

Hoca "Nasıl çözeriz?" diye sordu.

**Soru (bir öğrencinin önerisi):** Bağlı listeyle (linked list) her sayının bağlı olduğu elemanlar `NULL` görülene kadar gezilir; bağlanmak istenen sayıya bir yoldan bağlı değilse bağlanır. **Cevap:** Hoca bağlı listelerin henüz işlenmediğini, şu anda yalnız dizi kullanılabildiğini söyledi.

**Soru (bir öğrencinin önerisi):** Bir bağlantı matrisinde bağlantı gördükçe işaretlemek. **Cevap:** Hoca bunu mantıklı buldu, ama matrisin ikili bağlantıları yakaladığını, 2-3, 3-4, 4-9 üzerinden gelen 2-9 gibi zincirleri doğrudan yakalamadığını söyledi. Ayrıca milyonlarca düğüm olduğunda matris milyon çarpı milyon, yani trilyon mertebesinde yer kaplar.

Bir öğrencinin "`while` ile" önerisine hoca, çift bilgi gelmeye devam ettiği sürece kontrol yapılacağı için gerçekten bir `while` döngüsü kullanılacağını, ama tek başına `while`'ın çözüm olmadığını söyledi.

## 4. Problemin Gerçek Dünya Karşılıkları

Slaytta sayı çiftlerinin şunlar olabileceği yazar (ekrandan, 00:25:00):

- Çok geniş bir ağdaki bilgisayarlar olabilir.
  - Haberleşmeleri için `p-q` arasında yeni bağlantı mı yapacağız, yoksa zaten birbirlerine bağlılar mı?
  - Milyonlarca – milyarlarca cihaz olabilir.
- Bir devrede birbiri ile (tellerle bağlı olan) kontaklar olabilir.
  - Gereksiz bağlantı olmadan tüm uçları nasıl bağlayacağımızı bulmuş oluruz.
- Sosyal ağdaki bağlı kişiler olabilir.
- Fortran'daki değişken isimleri olabilir.

Hoca her birini kısaca açtı. İnternet gibi bir ağda `P` ve `Q` düğümleri arasında paket göndermek için yeni hat mı çekilmeli, yoksa 2-3-4-9 gibi bir yoldan zaten veri gönderilebiliyor mu? Baskılı devrede bileşenlerin iki, üç ya da (mikroçiplerde) daha fazla kontağı vardır; hangi uçların bağlı olduğu, gereksiz bağlantı ya da kısa devre olup olmadığı bu algoritmayla kontrol edilebilir. Bir yönlendiricinin işletim sistemi de temelde "bu düğüm şu düğüme bağlı mı" bilgisini tutar. Sosyal ağda kimin kimle hangi dereceden de olsa bağlantılı olduğu, hangi grupların oluştuğu sorulabilir. Fortran maddesi derste açılmadı.

Görünüşte çok farklı olan bu gerçek dünya problemlerinin hepsi aynı biçimde modellenir ve altta aynı algoritma çalışır.

Hoca ardından çok sayıda düğümün birbirine bağlı olduğu bir şekil gösterdi ve seçilen iki düğümün bağlı olup olmadığını sordu; gazetelerdeki labirent bulmacalarına benzetti. Cevap, iki düğümün bir ara düğümler dizisi üzerinden bağlı olduğuydu; dolayısıyla aralarına yeni hat çekmeye gerek yoktur.
<!-- BELİRSİZ: Bu şeklin bulunduğu slayt karelerde görünmüyor; düğüm düzeni ve yol aktarılamadı. -->

## 5. Problemi Tanımlamak ve Değiştirmek

Slaytta şu ilkeler yer alır (ekrandan, 00:30:00):

- Algoritma tasarlarken ilk iş, *problemi* makul (anlaşılır, açıklanabilir) bir şekilde tanımlamaktır.
- Bazen problemi çözmek çok maliyetli ve zor olabilir. Bu durumlarda, orijinal problem tanımından biraz farklı olsa da, işe yarar bilgi veren/çözüm üreten algoritmaları kullanmak üzere problem tanımını değiştirebiliriz.
- Örneğimizde, sadece verilen bir `p-q` çifti için bağlıdır/değildir cevabını veriyoruz.
  - Hangi yolla bağlı olduğunu söylemiyoruz.
  - Bunu söylemenin de yolu var (ama karmaşık bir algoritma).
- N nesneyi bağlamak için M bağlantı yeterli mi?
  - Esasen, N-1 bağlantı yeterli. M<N-1 ise true, değilse false (MST).

Hoca, matris ya da bağlı liste gibi ilk akla gelen fikirlerin trilyonlarca bayt yer gerektirecek kadar maliyetli olabileceğini, bu durumda iyi çalıştığı bilinen bir algoritmayla problemin biraz değiştirilmiş hâlinin çözülebileceğini, oradan elde edilen bilgiyle gerçek problemin ikinci aşamada daha rahat çözülebileceğini anlattı.

Bu örnekte yalnız "bağlıdır / değildir" (true/false) cevabı isteniyor; 2-3-4-9 üzerinden bağlı olduğunu söylemek ayrı bir iştir ve en kısa yol (shortest path) problemine gider. Hoca, dersi daha önce almış olanlar için bu problemi modellemenin en uygun veri yapısının çizge (graf) olduğunu ve aslında çizgede bağlı bileşen (connected component) arandığını belirtti.

"N nesne için M bağlantı yeterli mi?" sorusunda hoca, $N$ düğüm için $N-1$ bağlantının yeterli olduğunu ve minimum yayılan ağaçta (minimum spanning tree) $N$ düğüm için $N-1$ kenar bulunduğunu hatırlattı; ama şimdilik bu seviyeye geçilmeyecekti.

> **Ders sonrası not:** Slayttaki ve sözlü anlatımdaki koşul büyük olasılıkla ters yazılmıştır. $N$ düğümü bağlamak için en az $N-1$ bağlantı gerekir; $M < N-1$ ise bağlantılar kesinlikle yetersizdir (false). $M \ge N-1$ olması gereklidir ama tek başına yeterli değildir, çünkü bağlantıların bir kısmı zaten bağlı çiftler arasında olabilir.

## 6. Hızlı Bulma (Quick-Find) Çözümü

### 6.1 Fikir

Slayttaki adımlar şöyledir (ekrandan, 00:35:00):

- Her yeni çift geldikçe, yeni bağlantı mı değil mi bakmalıyız.
  - Öyleyse önceki bağlantıları bir şekilde tutmalıyız.
- Önceden bağlı olanlara değiyorsa, bu çifti de o bağlantı kümesine almalıyız.
  - Önce birinci elemana sahip olan kümeyi bul.
  - Sonra ikinci elemana sahip olan kümeyi bul.
  - Sonra iki elemanın kümelerini birleştir (bağladık).
- Her bir küme, bir bağlı bileşen oluşturacaktır.

Veri sürekli gelir: 3-4, 5-7, 4-9 gibi. Her yeni çift için ilk bakılacak şey bu iki elemanın önceden bağlı olup olmadığıdır. Zaten aynı kümedelerse cevap "false"tur, yani bağlantı kurulmaz. Bunu bilebilmek için kimin kimle bağlı olduğu bir yerde saklanmalıdır; bu olmadan "önceden bağlı mıydınız" sorusu cevaplanamaz.

Hoca bir örnekle gösterdi: 1 bir kümede, 6 başka bir kümedeyse 1-6 geldiğinde bunlar bağlanmalıdır. Önce bir elemanın kümesi bulunur, sonra bağlama sırasında diğer kümenin bütün elemanları da o kümeye alınır, yani iki küme birleştirilir ve tek küme olarak devam eder.

### 6.2 `id[]` dizisi

Küme bilgisi, kimlik anlamında `id` adlı bir dizide küme numarası olarak tutulur. Slayttaki dizi ve çizim şöyledir (ekrandan, 00:35:00):

| İndis | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|
| `id[]` | 0 | 1 | 1 | 8 | 8 | 0 | 0 | 1 | 8 | 8 |

Çizimdeki kenarlar şunlardır:

```text
0       1 --- 2       3 --- 4
|             |       |     |
5 --- 6       7       8     9
```

Dizinin okunuşu: 0., 5. ve 6. düğümler 0 numaralı kümededir; 1., 2. ve 7. düğümler 1 numaralı kümededir; 3., 4., 8. ve 9. düğümler 8 numaralı kümededir. Düğümler çizimde yalnız düzgün görünsün diye iki satıra dizilmiştir.

Bu durumda 6 ile 1 bağlanırsa ya bütün 1'ler 0 yapılır ya da bütün 0'lar 1 yapılır; hangisinin seçileceği gerçekleştirmeye (birinciyi ikinciye mi, ikinciyi birinciye mi bağladığımıza) bağlıdır. Hoca 6'yı 1'e bağladı: `id[6]` 1 olur, ama 6'nın bağlı olduğu 0 ve 5 de 1 yapılmalıdır. Sonuçta elde 1 ve 8 numaralı iki ayrık küme kalır.

## 7. Adım Adım Örnek

Başlangıçta her düğüm kendi kümesindedir: `id[i] = i`, yani 10 düğüm için 10 küme vardır. `p-q` çifti "p'yi q'ya bağla" diye okunur: `id[p]` değerine sahip bütün gözlere `id[q]` yazılır. Aşağıdaki ara durumlar hocanın anlatımından ve slaytlardan alınmış, python ile doğrulanmıştır.

| Adım | Çift | `id[0..9]` sonrası | Küme sayısı |
|---|---|---|---|
| 0 | başlangıç | 0 1 2 3 4 5 6 7 8 9 | 10 |
| 1 | 4-3 | 0 1 2 3 3 5 6 7 8 9 | 9 |
| 2 | 3-8 | 0 1 2 8 8 5 6 7 8 9 | 8 |
| 3 | 6-5 | 0 1 2 8 8 5 5 7 8 9 | 7 |
| 4 | 9-4 | 0 1 2 8 8 5 5 7 8 8 | 6 |
| 5 | 2-1 | 0 1 1 8 8 5 5 7 8 8 | 5 |
| 6 | 8-9 | değişmez (zaten bağlı) | 5 |
| 7 | 5-0 | 0 1 1 8 8 0 0 7 8 8 | 4 |
| 8 | 7-2 | 0 1 1 8 8 0 0 1 8 8 | 3 |
| 9 | 6-1 | 1 1 1 8 8 1 1 1 8 8 | 2 |
| 10 | 7-3 | 8 8 8 8 8 8 8 8 8 8 | 1 |

Adımların anlatımı:

- **4-3:** 4 dördüncü, 3 üçüncü kümededir; bağlı değiller. `id[4]` yerine `id[3]` değeri olan 3 yazılır. 3 ile 4 arasına bir çizgi çekilmiş olur; bundan sonra aynı küme numarasına sahip oldukları için bağlı oldukları hemen görülür.
- **3-8:** 3 üçüncü, 8 sekizinci kümededir. `id[3]` yerine 8 yazmak yetmez, çünkü 3 zaten 4'e bağlıdır; değeri 3 olan bütün gözler 8 yapılır. Artık üç düğüm 8 numaralı kümededir.
- **6-5:** `id[6]` yerine 5 yazılır. Elde iki bağlı bileşen vardır. Farklı değerler sayılarak 7 küme olduğu görülür.
- **9-4:** 9 dokuzuncu, 4 sekizinci kümededir; `id[9]` 8 yapılır, iki küme birleşir (ekrandan, 00:40:00).
- **2-1:** 2 ikinci, 1 birinci kümededir; `id[2]` 1 yapılır. Başka 2 değeri yoktur. 5 küme kalır.
- **8-9:** "İşte en güzel örneğimiz" denen adım. Normalde 8 ile 9 arasına bir çizgi çekmek gerekirdi; ama aidiyet tablosunda 8 de 9 da 8 numaralı kümededir. Bunlar zaten bağlıdır, false döndürülür ve hiçbir işlem yapılmaz (ekrandan, 00:40:00).
- **5-0:** 5 değerli iki göz (5 ve 6) 0 yapılır. 0, 5, 6 düğümleri 0 numaralı kümede; 1, 2 düğümleri 1 numaralı kümede; 3, 4, 8, 9 düğümleri 8 numaralı kümededir; 7 hâlâ yalnızdır.
- **7-2:** `id[7]` 1 yapılır. 3 bağlı bileşen kalır: 0 numaralı kümede 3, 1 numaralı kümede 3, 8 numaralı kümede 4 eleman vardır. Bu durum, Bölüm 6.2'deki dizinin aynısıdır.
- **6-1:** 6 sıfırıncı, 1 birinci kümededir; bütün 0'lar 1 yapılır. 1 numaralı kümede 6 eleman, 8 numaralı kümede 4 eleman kalır.
- **7-3:** Hoca bu adımı sözlü ekledi: bütün değerler 8 olur ve bütün düğümler tek kümede birleşir.

> **Ders sonrası not:** Slaytta (ekrandan, 00:40:00) 9-4, 2-1 ve 8-9 satırlarında `id[6]` değeri 8 olarak görünür. Hoca derste bunun kopyalama hatası olduğunu, o gözlerin 5 olması gerektiğini söyledi. Yukarıdaki tablo düzeltilmiş değerlerle verilmiştir; 5-0 satırı slaytta doğrudur (`0 1 1 8 8 0 0 7 8 8`).

Hoca sonuçta veri yapısı olarak yalnız tek boyutlu bir dizi kullanıldığını vurguladı. Kimin kime bağlı olduğu adım adım güncellenebilir ve geçmiş bağlantılar takip edilebilir.

> **Ek bilgi (derste anlatılmadı):** Bu yöntemde iki elemanın bağlı olup olmadığına bakmak (`id[p] == id[q]`) tek karşılaştırmadır, bu yüzden "hızlı bulma" adını alır. Buna karşılık her birleştirme işlemi bütün diziyi dolaşır, yani $N$ adım sürer. $N$ düğüm ve $M$ birleştirme için toplam iş büyük olasılıkla $M \cdot N$ mertebesindedir; çok büyük ağlarda bu yavaş kalır.

## 8. Hızlı Bulma Kodu

Hoca bir slaytta bu algoritmanın C kodunu gösterdi ve "inanmayan yazsın baksın" dedi. Kodun slaytı karelerde görünmüyor; aşağıdaki anlatım altyazıdan alınmıştır.

- Boyut sabit tanımlanmıştır (100). Bu, sisteme 100'den fazla düğüm verilemeyeceği anlamına gelir; pratikte dinamik olması beklenir, ama slayta sığması için basit tutulmuştur.
- Değişkenler: iki döngü değişkeni, geçici değişken `t`, `scanf` ile okunacak çift `p` ve `q`, ve küme dizisi `id`.
- Önce `0`'dan `N`'e kadar `id[i] = i` ataması yapılır.
- `scanf` iki değer okuduğu sürece (dönüş değeri 2 olduğu sürece) döngü devam eder; değerler `p` ve `q`'nun adreslerine yazılır.
- `id[p] == id[q]` ise çift zaten bağlıdır; normalde bir mesaj verilebilir, kodda doğrudan `continue` ile döngünün sonraki adımına geçilir.
- Değilse `t = id[p]` alınır ve `i = 0`'dan `N`'e kadar `id[i] == t` olan her göz `id[q]` yapılır. Slaytta yer kazanmak için `t` ataması `for`'un ilk değer kısmına yazılmıştır; hoca akış diyagramında bu atamanın döngüden önce yapılmasının daha okunaklı olacağını söyledi.
- Son olarak bağlantının kurulduğunu göstermek için basit bir `printf` vardır; bu zorunlu değildir.
- Girdi sayısı biliniyorsa (örneğin 5000 çift) `while` yerine sabit sayılı bir döngü de kullanılabilir.

<!-- BELİRSİZ: Slayttaki hızlı bulma kodu karelerde görünmüyor; aşağıdaki kod birebir slayt metni değildir. -->

Aşağıdaki kod derste ekrandan alınmadı; altyazıdaki anlatıma göre ajan tarafından yazıldı, `gcc -Wall` ile derlendi ve Bölüm 7'deki çiftlerle çalıştırılarak doğrulandı (8-9 çifti beklendiği gibi atlandı).

```c
#include <stdio.h>
#define N 100

int main(void) {
    int i, p, q, t, id[N];

    for (i = 0; i < N; i++)
        id[i] = i;

    while (scanf("%d %d", &p, &q) == 2) {
        if (id[p] == id[q])
            continue;
        for (t = id[p], i = 0; i < N; i++)
            if (id[i] == t)
                id[i] = id[q];
        printf(" %d %d\n", p, q);
    }
    return 0;
}
```

Hoca algoritma tasarlarken iki şeyin birlikte düşünülmesi gerektiğini söyledi: ne yapılacağı ve bunu yaparken ne kullanılacağı. Burada değerler dizide tutulur, çünkü elde tek boyutlu bir bilgi (her düğümün küme numarası) vardır. İkili ilişkiler önemli olsaydı matris, dinamik bir yapı gerekseydi bağlı liste kullanılabilirdi; bu tür yapılar sonraki haftalarda görülecektir.

## 9. C ile Dinamik Matris Yaratma

### 9.1 Kod

Hoca, ilk haftada hatırlatma olsun diye dinamik dizi yaratma kodunu gösterdi. Kod ekrandan birebir alınmıştır (ekrandan, 00:50:00); `gcc -Wall` ile uyarısız derlendi ve $n=3$, $m=4$ girdisiyle çalıştırıldı.

```c
#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int, int);

int main ( void )  {
   int i, j, n, m;
   int **a;

   printf("Enter n:"); scanf("%d",&n);
   printf("Enter m:"); scanf("%d",&m);

   a = createMatrix(n,m);

   for(i=0; i<n; i++)  {
      for(j=0; j<m; j++) {
         printf("%d ", a[i][j]);
      }
      printf("\n");
   }

   return 0;
}

int **createMatrix(int rows, int cols)  {

   int i,j;
   int **arr;

   arr = (int **) malloc(sizeof(int *) * rows);

   for(i=0;i<rows;i++)  {
      arr[i] = (int *) malloc(sizeof(int)*cols);
   }

   for(i=0;i<rows;i++)  {
      for(j=0;j<cols;j++) {
         arr[i][j] = rand() % 9;
      }
   }

   return arr;
}
```

### 9.2 Açıklama

`main`'den önceki `int **createMatrix(int, int);` satırı bir imzadır: fonksiyon çağrıldığı yerden önce yazılmadığı için derleyiciye önceden bildirilmesi gerekir.

> **Ders sonrası not:** Hoca bu satır için "double pointer" ve "function pointer" ifadelerini kullandı. Doğrusu bu satır `int **` (int işaretçisinin işaretçisi) döndüren bir fonksiyonun prototipidir; işlev işaretçisi (function pointer) değildir.

`main`, satır sayısı `n` ve sütun sayısı `m`'yi kullanıcıdan okur, `createMatrix(n, m)` ile `int **` türündeki `a`'ya bir matris alır ve iç içe iki döngüyle matrisi satır satır, her satırın sonunda bir satır sonu basarak yazdırır.

`createMatrix` içinde parametre adları okunaklı olsun diye `rows` ve `cols` seçilmiştir. Matris "dizilerin dizisi" olarak kurulur:

1. Önce matrisin başlangıç adresini tutan `int **arr` tanımlanır.
2. `malloc(sizeof(int *) * rows)` ile `rows` tane `int *` için yer ayrılır ve sonuç `(int **)` türüne dönüştürülür. Böylece her satırın başı bir `int` işaretçisi olur; bu, aşağı doğru uzanan bir işaretçi dizisidir.
3. Her `i` satırı için `malloc(sizeof(int) * cols)` ile `cols` tane `int` için yer ayrılır ve `(int *)` olarak `arr[i]`'ye atanır.
4. Satırlar `i`, sütunlar `j` ile gezilerek her göze bir değer atanır. Slaytta `rand() % 9` ile 0-8 arası değer verilir; 0 da yazılabilir.
5. `arr` geri döndürülür. Dönüş türü `int **` olduğu ve `main`'deki `a` da aynı türde tanımlandığı için atama uyumludur.

> **Hocanın vurgusu:** Kodda `malloc`'un yer ayıramadığı durum için hata kontrolü yoktur. Kod slayta sığsın diye bu kontroller atılmıştır; gerçek kodda bellek yetersizliği kontrolleri eklenmelidir.

> **Ek bilgi (derste anlatılmadı):** `malloc` başarısız olduğunda `NULL` döndürür; bu yüzden her çağrıdan sonra dönen işaretçinin `NULL` olup olmadığına bakılır. Ayrıca iş bitince önce her satır (`free(arr[i])`), sonra satır işaretçileri dizisi (`free(arr)`) serbest bırakılmalıdır; slayttaki kodda bu adım da yoktur.

## 10. Örnek Sorular

### Soru 1: Bağlantı problemi nasıl çözülür?

(derste sözlü, 00:21:06) Bağlı çiftler sırayla geliyor. Daha önce doğrudan ya da dolaylı bağlı olan çiftler için yeni bağlantı kurmayan bir yöntemi nasıl tasarlarız?

> **Çözüm (derste verildi):** Her düğümün küme numarası tek boyutlu bir `id[]` dizisinde tutulur; başlangıçta `id[i] = i`. Gelen `p-q` için `id[p] == id[q]` ise çift zaten bağlıdır, bir şey yapılmaz. Değilse `id[p]` değerine sahip bütün gözler `id[q]` yapılır (hızlı bulma çözümü, Bölüm 6-7).

### Soru 2: Hangi çiftler yeni bağlantıdır?

(ekrandan, 00:20:00) Sırayla 3-4, 4-9, 8-0, 2-3, 5-6, 2-9, 5-9, 7-3, 4-8, 0-2, 6-1 çiftleri geliyor. Hangileri için yeni bağlantı kurulmamalıdır?

> **Çözüm (derste verildi):** 2-9 (2-3-4-9 yolu vardı) ve 0-2 (0-8-4-3-2 yolu vardı). Diğer dokuz çift yeni bağlantıdır. Python ile hızlı bulma simülasyonu bu sonucu doğruladı; son çift 6-1 ile bütün düğümler tek kümede toplanır.

### Soru 3: 6-1 bağlanınca dizi ne olur?

(derste sözlü, 00:34:31) `id[] = 0 1 1 8 8 0 0 1 8 8` iken 6 ile 1 bağlanırsa (6, 1'e bağlanıyor) dizi ne olur, kaç küme kalır?

> **Çözüm (derste verildi):** `id[6] = 0` değerine sahip bütün gözler (0, 5, 6) `id[1] = 1` yapılır: `1 1 1 8 8 1 1 1 8 8`. 1 ve 8 numaralı iki küme kalır.

### Soru 4: N nesneyi bağlamak için M bağlantı yeterli mi?

(ekrandan, 00:30:00) N nesneyi birbirine bağlamak için M bağlantı yeterli midir?

> **Çözüm (derste verildi, düzeltmeyle):** Derste $N$ düğüm için $N-1$ bağlantının yeterli olduğu (minimum yayılan ağaçta $N-1$ kenar) söylendi. Doğru koşul şudur: $M < N-1$ ise yeterli değildir (false). $M \ge N-1$ gereklidir ama yeterli olması bağlantıların hangi çiftler arasında olduğuna bağlıdır (bkz. Bölüm 5'teki ders sonrası not).

## Dersin Toparlaması

Bu uygulama saatinde algoritma tasarımına nasıl yaklaşılacağı gösterildi: önce problemi anlaşılır biçimde tanımlamak, gerekirse problemi biraz değiştirmek, doğru çalışan basit bir ilk çözüm kurmak ve bunu bir karşılaştırma temeli olarak kullanıp iyileştirmek. Bağlantı problemi bu yaklaşımın örneği oldu. Yalnız tek boyutlu bir dizi ve basit bir karşılaştırma ile, gelen bir çiftin zaten bağlı olup olmadığı bulunabildi ve bağlı değilse iki küme birleştirildi; yani bulma (find) ve birleştirme (union) işlemleriyle doğru çalışan bir çözüm elde edildi. Ardından C'de `malloc` ile iki boyutlu dinamik dizi yaratma hatırlatıldı.

Hoca bu problemin başka çözüm algoritmaları da olduğunu söyledi: burada hızlı bulma (quick-find) kullanıldı; hızlı birleştirme (quick-union) ve birleştir-bul (union-find) yöntemleriyle ya da çizge algoritmalarıyla da çözülebilir. Bunlar ve algoritma analizinin temelleri sonraki derslerde ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
