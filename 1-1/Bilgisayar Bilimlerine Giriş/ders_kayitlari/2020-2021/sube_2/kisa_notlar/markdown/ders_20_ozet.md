# Ders 20 Çalışma Özeti

## Genel Konular

- Art arda en çok tekrar eden eleman problemi
  - Problem (ekrandan, 00:35:00): "Bir dizi içerisinde **art arda** en çok tekrar eden eleman ve tekrar sayısı" bulunacak.
  - Örnek dizi (ekrandan, 00:15:00): `3 5 5 5 4 4 7 6 6 6 6 3 3`. Art arda tekrar uzunlukları: 5'ler 3, 4'ler 2, 6'lar 4, sondaki 3'ler 2. Cevap: 6 değeri, 4 kez.
  - "Art arda" vurgusu: dizide toplam kaç tane olduğu değil, birbirini takip eden tekrarlar sayılır. Dizideki 3'ler toplanıp "3 tane 3 var" denmez.
  - Elemanı bildirmenin iki yolu vardır: yalnız değeri (6) söylemek ya da konumunu (8. eleman) söylemek. Konum daha bilgilidir: tekrarın nereden başladığı, hangi sayı olduğu ve (tekrar sayısıyla birlikte) nereye kadar sürdüğü konumdan çıkarılabilir.
- Öğrencilerle birlikte çizilen akış ve düzeltmeleri
  - İlk akış (ekrandan, 00:25:00): `N, A(N)` okunur; `CNT = 1`, `MAX = 1`, `PL = 1`; `I ← 1 || 1` döngüsünde `A(I) = A(I+1)` sorulur. Doğruysa `CNT = CNT + 1`; yanlışsa `CNT > MAX` sorulur, doğruysa `MAX = CNT`, yanlışsa `CNT = 1`.
  - Düzeltme 1 (ekrandan, 00:30:00): döngü bitişi `N` değil `N-1` olmalıdır. `I = N` iken `A(I+1)` dizinin dışına çıkar.
  - Düzeltme 2: sonda `A(I)` değil `A(PL)` yazdırılmalıdır (çıktı: `A(PL), MAX`).
  - Düzeltme 3: `MAX = CNT` atanırken konum `PL = I` değil `PL = I - MAX + 1` olmalıdır. Yanlış kola düşüldüğünde `I` tekrarın son elemanını gösterir, başlangıç için tekrar uzunluğu çıkarılıp 1 eklenir.
  - Düzeltme 4: `CNT = 1` sıfırlaması `CNT > MAX` kararının hem doğru hem yanlış kolunda yapılmalıdır. Yalnız yanlış kolda yapılırsa yeni bir rekordan sonra sayaç sıfırlanmaz ve sonraki tekrar eski değerin üstüne sayılır.
  - Sınır durumu (ekrandan, 00:40:00): `3 5 5 5 4 4 7 3 3 6 6 6 6` dizisinde en uzun tekrar dizinin sonundadır. Akış yalnız eşitsizlik görünce `MAX`'ı güncellediği için sondaki tekrar hiç değerlendirilmez; akış bu durum için yeniden düzenlenmelidir.
- Akış diyagramında karşılaştırma gösterimi
  - Karar kutusunda eşitlik tek `=` ile yazılır. `==` C dilinin yazımıdır; akışta programlama dili sözdizimi kullanılmaz.
- Ek dizi kullanmak ve yer karmaşıklığı
  - Aynı elemanları ayrı bir diziye kopyalayıp orada aramak önerildi. Hoca bunun büyük problemlerde makul olmadığını söyledi: karmaşıklık yalnız zaman (time complexity) değil, yer (space complexity) açısından da ölçülür. Bir birim ek yer ile problemin boyutu kadar ek yer aynı şey değildir.
  - Sayma örneği: `N` elemanlı bir dizide değerler 0-9 arasındaysa hangi değerden kaç tane olduğunu bulmak için 10 elemanlı bir sayaç dizisi açılır, değerler bu dizinin indisi olarak kullanılır. Değer aralığı 0'dan 4 milyara kadarsa bu yöntem mantıklı olmaz.
- Gri seviye resmin histogramı
  - Renkli resimler genelde 24 bit RGB'dir (Red, Green, Blue için 8'er bit); 32 ve 16 bitlik biçimler de vardır (ekrandan, 00:45:00).
  - 8 bit gri seviye (gray level / gray scale) resimde her piksel 0-255 arasında bir değer alır; toplam 256 değer vardır. Resim bir matris olarak düşünülür (örneğin 640 × 480).
  - Eşik (threshold) değerini hesaplamak için önce histogram gerekir: 0, 1, 2, ..., 255 değerlerinin her birinden kaç tane olduğu bulunur.
  - Problemin özü (ekrandan, 00:55:00): elde bir matris var, içinde 0-255 arası değerler var; her değerden kaç tane olduğu bulunacak.
- Değeri indis olarak kullanma (sayma dizisi)
  - Tek bir değer (örneğin 71) sayılacak olsaydı bütün elemanlar dolaşılıp bir sayaç artırılırdı. 256 değer için 256 ayrı sayaç gerekir; 256 tane `if` yazılmaz.
  - `CNT` dizisi 256 gözlüdür ve indisleri 1'den başlar. Matris elemanı 0-255 arasında olduğu için `A(I)(J) + 1` doğrudan `CNT`'nin indisi olarak kullanılır (ekrandan, 01:55:00):
    - `CNT(A(I)(J)+1) = CNT(A(I)(J)+1) + 1`
  - `CNT` eşitliğin sağ tarafında önce kullanıldığı için **sıfırla ilklendirilmelidir**.
- Matris çarpımı
  - Örnek boyutlar (ekrandan, 01:30:00): A 7 × 8, B 8 × 5; sonuç C 7 × 5.
  - A'nın bir satırı ile B'nin bir sütununun karşılıklı elemanları çarpılıp toplanır ve C'nin tek bir gözüne yazılır. Örneğin $C_{12} = A_{11}B_{12} + A_{12}B_{22} + \dots + A_{18}B_{82}$.
  - Akış (ekrandan, 01:45:00): `L, M, N`, `A(L)(M)`, `B(M)(N)` okunur; `I ← 1 || 1` (bitiş `L`); `K ← 1 || 1` (bitiş `N`); `SUM = 0`; `J ← 1 || 1` (bitiş `M`); `SUM = SUM + A(I)(J) * B(J)(K)`. J döngüsünden çıkınca `C(I)(K) = SUM`; sonunda matris yazdırılır.
  - Kullanıcıdan dört boyut yerine yalnız üç sayı (`L`, `M`, `N`) istenir; böylece A'nın sütun sayısı ile B'nin satır sayısının uyuşmaması baştan engellenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akışı analizle test etmek
  - Akış çizildikten sonra değişkenlerin her adımda aldığı değerler bir tabloda izlenerek denenir. Matris çarpımı için tablo sütunları: `I`, `K`, `J`, `SUM`, `A(I)(J)`, `B(J)(K)` (ekrandan, 01:50:00).
  - Tek bir örnekle yetinilmez; uç nokta ve sınır değerler (en başta, en sonda olan durumlar) de denenir.
  - Bir çözümün doğru olup olmadığını başkasına sormak yerine analizle kendiniz bulabilmelisiniz.
- Problemi önce anlamak
  - Hemen çizmeye atlamak yerine problem gerekirse tekrar tekrar okunur. Önemli olan hızlı değil doğru yapmaktır.
  - Problemle ilgisiz şeyler söylemek problemin anlaşılmadığını gösterir. Yan problemlere (kullanıcı 256 girerse ne olur gibi) değil, ana probleme odaklanılır.
- Değeri başka bir dizinin indisi olarak kullanmak
  - Matris elemanı bir sayı olduğu için başka bir dizinin indisi olabilir. Sayma dizisinin ilk değeri sıfır olmalıdır.
- Geçici değişkenle toplama
  - Döngü içinde doğrudan `C(I)(K)` üzerinde toplamak yerine geçici bir değişkende (`SUM`, `TMP`) toplayıp sonucu en son matrise atamak tercih edilir. Matris indislemede adres hesabı yapılır; büyük matrislerde bu daha fazla zaman alabilir. Etkisi platforma ve mimariye göre değişir.
- Sıfır ile O harfini ayırmak
  - Hoca sıfırı içine çizgi koyarak yazar (`Ø`); eski nokta vuruşlu (dot matrix) ekranlardaki gibi sıfırın O harfiyle karışmaması için akışlarda bu şekilde yazmak tavsiye edildi.

## Kısa Tekrar Notları

- "Art arda en çok tekrar eden" problemi: `A(I) = A(I+1)` ise `CNT` artar; değilse `CNT > MAX` kontrolü, gerekirse `MAX = CNT` ve `PL = I - MAX + 1`; her iki durumda `CNT = 1`.
- `A(I+1)` kullanılan döngüde bitiş `N-1` olur.
- Konum (`PL`) saklanırsa değer `A(PL)` ile, tekrar uzunluğu `MAX` ile verilir.
- En uzun tekrar dizinin sonundaysa döngü içindeki kontrol onu yakalamaz; sınır durumunu ayrıca test et.
- Akışta eşitlik `=` ile, C'de `==` ile yazılır.
- Yer karmaşıklığı da önemlidir; dizinin kopyasını almak büyük verilerde makul değildir.
- 8 bit gri seviye: 0-255, 256 değer. Histogram = her değerin kaç kez geçtiği.
- Sayma dizisi: `CNT(A(I)(J)+1) = CNT(A(I)(J)+1) + 1`, `CNT` önce sıfırlanır.
- (7 × 8) · (8 × 5) = (7 × 5). Çarpım için A'nın sütun sayısı B'nin satır sayısına eşit olmalıdır.
- Matris çarpımı üç iç içe döngüdür: satır (`I`), sütun (`K`), ortak boyut (`J`); toplam `SUM`'da tutulur, J döngüsü bitince `C(I)(K) = SUM`.
- Akışı değişken tablosuyla analiz ederek kendin doğrula.

## Detaylı Açıklamalar

- **Art arda tekrar akışının mantığı.** Dizi soldan sağa bir kez dolaşılır ve her eleman sağındakiyle karşılaştırılır. İkisi eşitse içinde bulunulan tekrar bir uzar (`CNT = CNT + 1`). Eşit değilse içinde bulunulan tekrar bitmiştir; uzunluğu o ana kadarki en büyük uzunluktan (`MAX`) büyükse `MAX` güncellenir ve tekrarın başlangıç konumu `PL = I - MAX + 1` olarak saklanır. Ardından yeni tekrar için sayaç 1'e döner. `CNT` ve `MAX` 1 ile başlar, çünkü tek başına duran bir eleman da 1 uzunluğunda bir tekrardır. Örnek dizide 5'lerin tekrarı biterken `I = 4`, `CNT = 3` olur; `PL = 4 - 3 + 1 = 2`, yani tekrar 2. elemandan başlar. 6'ların tekrarı biterken `I = 11`, `CNT = 4`; `PL = 11 - 4 + 1 = 8`. Sonuç `A(8) = 6`, `MAX = 4` (python ile doğrulandı).
- **Sıfırlama neden iki kolda.** `CNT = 1` yalnız `CNT > MAX` kararının yanlış kolunda olursa, yeni bir en uzun tekrar bulunduğunda sayaç sıfırlanmaz. Örnek dizide 5'lerden sonra `CNT = 3` olarak kalır, ardından gelen 4'ler 4'e çıkarır ve sonuç yanlış olur (bu akışla örnek dizide sonuç 5 değeri, 4 tekrar çıkıyor; python ile denendi). Bu yüzden sıfırlama karar kutusundan sonra, iki kolun birleştiği yere taşınır.
- **Sondaki tekrar.** İkinci dizide (`... 7 3 3 6 6 6 6`) 6'lar dizinin sonunda biter, sonrasında eşitsizlik görülmez. Akış `MAX`'ı yalnız eşitsizlikte güncellediği için döngü bittiğinde 6'ların tekrarı hiç değerlendirilmemiş olur ve sonuç 5'lerin tekrarı (3) çıkar (python ile denendi). Hoca akışın bu duruma göre yeniden çizilmesi gerektiğini söyledi; bu, sınır değer testinin neden gerekli olduğunun örneğidir.
- **Histogram ve sayma dizisi.** Gri seviye bir resim 0-255 arası değerlerden oluşan bir matristir. Her değerden kaç tane olduğunu bulmak için 256 gözlü bir `CNT` dizisi kullanılır. Matrisin her elemanı okunduğunda, değerin kendisi (artı 1, çünkü dizi indisleri 1'den başlar) `CNT`'de hangi gözün artırılacağını gösterir: değer 0 ise 1. göz, 255 ise 256. göz. Böylece her eleman için 256 karşılaştırma yapmak yerine tek bir işlemle ilgili göz artırılır. `CNT` sağ tarafta okunduğu için önce sıfırlanmalıdır. Hoca bu sayma fikrini yer karmaşıklığıyla da ilişkilendirdi: değer aralığı küçükse (0-9, 0-255) sayaç dizisi makuldür; aralık çok büyükse milyonlarca gözlü bir dizi açmak mantıklı değildir.
- **Matris çarpımı akışı.** `I` A'nın satırlarını (1'den `L`'ye), `K` B'nin sütunlarını (1'den `N`'ye) dolaşır. Her `(I, K)` çifti için `SUM = 0` yapılır ve `J` ortak boyut üzerinde (1'den `M`'ye) dönerek `A(I)(J) * B(J)(K)` çarpımları toplanır. J döngüsü bitince toplam `C(I)(K)`'ya yazılır. Bu yapı 7 × 8 ve 8 × 5 boyutlu rastgele matrislerle python'da denendi; sonuç kütüphane çarpımıyla aynı ve 7 × 5 boyutlu çıktı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
