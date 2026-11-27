# Ders 2 Çalışma Özeti

## Genel Konular

- Bu kayıt kısa bir uygulama dersidir. Konu, algoritma geliştirmeye nasıl yaklaşılacağı ve bunun bir örnek problem üzerinde gösterilmesidir.
- Algoritma geliştirme yaklaşımı (ekrandan, 00:10:00)
  - Önce problemi doğru çözen basit bir algoritma tasarlanır. Bu ilk çözüm küçük örneklerde analiz yapmayı kolaylaştırır ve performans ölçümü için temel seviyeyi (baseline) belirler.
  - Sonra algoritma iyileştirilir. Veri yapıları ve algoritmalar her zaman el eledir.
  - Basit bir algoritma gücünü karmaşık bir veri yapısından alabilir; karmaşık bir algoritma ise yalnız dizi gibi çok basit bir veri yapısı kullanabilir.
  - Programı hızlandırmak için 10-100 kat güçlü bir bilgisayar satın almak yerine algoritmayı 10 kat hızlı çalışacak şekilde tasarlamak para tasarrufu sağlar.
  - Belirli bir iş için en iyi algoritmayı seçmek oldukça karmaşık olabilir; bazen ayrıntılı matematik yerine basit zaman ölçümleri kullanılır.
- Bağlantı problemi (connectivity problem) (ekrandan, 00:20:00)
  - Birbirine bağlı varlık çiftleri `p-q` biçiminde sırayla verilir. Bağlantı çift yönlüdür: `p-q` verildiyse `q` da `p` ile bağlıdır.
  - Kolaylık için her varlık benzersiz bir tamsayı ile gösterilir.
  - Amaç yalnız yeni (önceden var olmayan) bağlantıları bulmaktır. Dolaylı yoldan zaten bağlı olan bir çift için yeni bağlantı kurulmaz.
- Problemin gerçek dünya karşılıkları (ekrandan, 00:25:00)
  - Çok geniş bir ağdaki bilgisayarlar: haberleşmeleri için yeni hat mı çekilmeli, yoksa zaten bağlılar mı? Milyonlarca, milyarlarca cihaz olabilir.
  - Bir baskılı devredeki kontaklar: gereksiz bağlantı olmadan bütün uçların bağlanması.
  - Sosyal ağdaki kişiler, ağ yönlendiricileri (router), Fortran'daki değişken adları.
- Problemi tanımlamak ve gerekirse değiştirmek (ekrandan, 00:30:00)
  - Algoritma tasarımında ilk iş problemi anlaşılır ve açıklanabilir biçimde tanımlamaktır.
  - Problem çok maliyetliyse, işe yarar bilgi üreten algoritmaları kullanabilmek için tanım biraz değiştirilebilir.
  - Örnekte yalnız "bağlıdır / değildir" cevabı verilir; hangi yolla bağlı olduğu söylenmez.
- Hızlı bulma (quick-find) çözümü (ekrandan, 00:35:00 ve 00:40:00)
  - Her düğümün hangi kümede olduğu tek boyutlu bir `id[]` dizisinde tutulur.
  - Yeni çift gelince iki elemanın kümesi bulunur; aynıysa çift zaten bağlıdır. Değilse iki küme birleştirilir.
  - Her küme bir bağlı bileşen (connected component) oluşturur.
- C ile dinamik iki boyutlu dizi (matris) yaratma (ekrandan, 00:50:00)
  - `malloc` ile önce satır işaretçileri dizisi, sonra her satır için sütun sayısı kadar `int` alanı ayrılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir algoritmanın en önemli özelliği doğru çözmesidir. Yanlış çözen bir yöntem ne kadar hızlı olursa olsun değerli değildir.
- Doğru ve en iyi çözüm bir anda bulunmaz. Basit ama doğru bir çözümle başlayıp üzerinde düşünerek iyileştirmek gerekir.
- Veri yapıları ve algoritmalar ayrılmaz parçalardır; probleme ve ortama göre birlikte düşünülmelidir.
- Bağlantı problemini bağlantı matrisiyle tutmak milyonlarca düğümde milyon çarpı milyon yer gerektirir. Matris ikili ilişkileri yakalar ama 2-3-4-9 gibi zincirleri doğrudan göstermez.
- Hızlı bulma çözümünde veri yapısı olarak yalnız tek boyutlu bir dizi kullanılır.
- `malloc` sonrası bellek ayrılıp ayrılmadığı kontrol edilmelidir; slayttaki kod sığması için bu kontrolleri içermez.

## Kısa Tekrar Notları

- Algoritma geliştirme: önce doğru ve basit çözüm (baseline), sonra iyileştirme.
- Bağlantı problemi: `p-q` çiftleri geliyor; zaten (dolaylı) bağlı olanlar için yeni bağlantı yok.
- Örnek girdi (ekrandan, 00:20:00): 3-4, 4-9, 8-0, 2-3, 5-6, **2-9**, 5-9, 7-3, 4-8, **0-2**, 6-1. Kalın çiftler zaten bağlıdır (2-3-4-9 ve 0-8-4-3-2 yolları vardı).
- Hızlı bulma:
  - Başlangıç: `id[i] = i` (her düğüm kendi kümesinde).
  - `p-q` geldiğinde `id[p] == id[q]` ise zaten bağlı, bir şey yapılmaz.
  - Değilse `id[p]` değerine sahip bütün elemanlar `id[q]` değerine çekilir.
  - Kümelerin sayısı, dizideki farklı değerlerin sayısıdır.
- Yeni bağlantı kurulup kurulmayacağına karar vermek için önceki bağlantıların bir yerde saklanması şarttır.
- N düğümü birbirine bağlamak için en az N-1 bağlantı gerekir (minimum yayılan ağaç, MST).
- Dinamik matris: `int **arr = (int **) malloc(sizeof(int *) * rows);` sonra her satıra `(int *) malloc(sizeof(int) * cols)`.

## Detaylı Açıklamalar

### Algoritma geliştirmeye yaklaşım

- Algoritma geliştirme bir kitabın bölümünü okuyup soruları çözerek öğrenilen bir konu değildir. Elimizde bir problem ve kısıtlar vardır; amaç problemi bu kısıtlar altında olabildiğince iyi çözmektir.
- Bu iş tek adımda yapılamayabilir. Problem küçültülebilir ya da önce düzgün çalışan, hem düşünmesi hem gerçekleştirmesi basit bir ilk çözüm (initial solution) kurulur.
  - Bu ilk çözüm, örneğin 100 ya da 1000 örnekli küçük veri kümelerinde hızlı analiz yapmayı ve uç durumları test etmeyi sağlar.
  - Aynı zamanda bir karşılaştırma temeli (baseline) oluşturur: örneğin 1000 örnek için 10 saniyede çalışıyorsa, daha iyi bir tasarımla bu süre 5 ya da 1 saniyeye indirilmeye çalışılır.
- Sonraki adım, algoritmik yöntemleri denemek ya da alternatif veri yapıları kullanmak suretiyle algoritmayı daha az zaman veya daha az bellek kullanacak biçimde iyileştirmektir.
- Hoca, $n$ elemanlı bir sıralamada $n^2$ mertebesinde (kuadratik) çalışan bir algoritma örneği verdi: daha güçlü bir bilgisayar almak programı 10-100 kat hızlandırır ama binlerce dolara mal olur. Algoritmayı elden geçirmek aynı hızlanmayı maliyetsiz sağlayabilir.
  - **Ders sonrası not:** Hoca kuadratik karmaşıklığa "üstsel karmaşıklık" da dedi; doğrusu kuadratik ($n^2$) karmaşıklık polinomsaldır, üstsel (exponential) karmaşıklık $2^n$ gibi büyümelerdir.

### Bağlantı problemi

- Girdi `p-q` çiftleridir. Çift, `p` ile `q`'nun bağlı olduğunu söyler (kablo ile bağlı iki bilgisayar ya da birbirini takip eden iki kişi gibi). Bağlantı çift yönlüdür.
- Örnekte (ekrandan, 00:20:00) çiftler sırayla işlenir:
  - 3-4, 4-9, 8-0, 2-3, 5-6 yeni bağlantılardır.
  - 2-9 geldiğinde 2-3-4-9 yolu zaten vardır; yeni bağlantı kurulmaz.
  - 5-9, 7-3, 4-8 yeni bağlantılardır.
  - 0-2 geldiğinde 0-8-4-3-2 yolu zaten vardır; yeni bağlantı kurulmaz.
  - 6-1 yeni bağlantıdır.
- Mantık bir küme mantığıdır: birbirine bağlı olan bütün elemanlar aynı kümededir ve aralarında ikinci bir bağlantı tanımlanmaz.
- Problemi büyütmek mümkündür (örneğin bütün yolları bulmak), ama bunlar ayrı ve daha karmaşık problemlerdir. Hangi yolla bağlı olunduğunu bulmak en kısa yol problemine gider.
- Bu problemi modellemek için en uygun veri yapısı çizgedir (graf); aslında çizgede bağlı bileşen aranmaktadır. Burada yalnız iki noktanın bağlı olup olmadığını true/false döndüren basit bir çözüm hedeflenir.
- "N nesneyi bağlamak için M bağlantı yeterli mi?" sorusu için slaytta "Esasen, N-1 bağlantı yeterli. M<N-1 ise true, değilse false (MST)" yazar (ekrandan, 00:30:00).
  - **Ders sonrası not:** Slayttaki ve sözlü anlatımdaki koşul büyük olasılıkla ters yazılmıştır. $N$ düğümü bağlamak için en az $N-1$ bağlantı gerekir; $M < N-1$ ise bağlantılar yetersizdir (false). $M \ge N-1$ olması gereklidir ama tek başına yeterli değildir; bağlantıların hangi çiftler arasında olduğu da önemlidir.

### Hızlı bulma (quick-find) çözümü

- Her yeni çift geldiğinde yeni bağlantı olup olmadığına bakılır; bu yüzden önceki bağlantılar bir şekilde saklanmalıdır.
- Çift, önceden bağlı bir gruba değiyorsa o grubun kümesine alınır: önce birinci elemanın kümesi, sonra ikinci elemanın kümesi bulunur, sonra iki küme birleştirilir (ekrandan, 00:35:00).
- Küme numaraları `id[]` dizisinde tutulur. Slayttaki örnek (ekrandan, 00:35:00):

| İndis | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|
| `id[]` | 0 | 1 | 1 | 8 | 8 | 0 | 0 | 1 | 8 | 8 |

- Bu durumda 0, 5, 6 düğümleri 0 numaralı kümede; 1, 2, 7 düğümleri 1 numaralı kümede; 3, 4, 8, 9 düğümleri 8 numaralı kümededir. Slayttaki çizimde kenarlar 0-5, 5-6, 1-2, 2-7, 3-4, 3-8, 4-9'dur.
- 6-1 çifti gelirse 0 değerli bütün gözler 1 yapılır; geriye 1 ve 8 numaralı iki küme kalır.

### Adım adım örnek

- Başlangıçta `id[i] = i`; 10 düğüm, 10 küme vardır. `p-q` "p'yi q'ya bağla" diye okunur: `id[p]` değerine sahip bütün gözlere `id[q]` yazılır. Ara durumlar python ile doğrulandı.

| Çift | `id[0..9]` sonrası | Küme sayısı | Açıklama |
|---|---|---|---|
| 4-3 | 0 1 2 3 3 5 6 7 8 9 | 9 | 4, 3'ün kümesine geçti |
| 3-8 | 0 1 2 8 8 5 6 7 8 9 | 8 | 3 değerli bütün gözler 8 oldu |
| 6-5 | 0 1 2 8 8 5 5 7 8 9 | 7 | |
| 9-4 | 0 1 2 8 8 5 5 7 8 8 | 6 | |
| 2-1 | 0 1 1 8 8 5 5 7 8 8 | 5 | |
| 8-9 | değişmez | 5 | `id[8] = id[9] = 8`, zaten bağlı |
| 5-0 | 0 1 1 8 8 0 0 7 8 8 | 4 | 5 değerli iki göz 0 oldu |
| 7-2 | 0 1 1 8 8 0 0 1 8 8 | 3 | |
| 6-1 | 1 1 1 8 8 1 1 1 8 8 | 2 | 0 değerli bütün gözler 1 oldu |
| 7-3 | 8 8 8 8 8 8 8 8 8 8 | 1 | hepsi tek kümede (sözlü) |

- **Ders sonrası not:** Slaytta (ekrandan, 00:40:00) 9-4, 2-1 ve 8-9 satırlarında `id[6]` değeri 8 görünür. Hoca derste bunun kopyalama hatası olduğunu ve 5 olması gerektiğini söyledi; tablo düzeltilmiş hâliyle verilmiştir.
- Kodun mantığı (altyazıdan; kod slaytı karelerde yok): dizi `id[i] = i` ile ilklendirilir, `scanf` iki tamsayı okuduğu sürece döngü devam eder, `id[p] == id[q]` ise `continue` ile geçilir, değilse `t = id[p]` alınıp `id[i] == t` olan her göz `id[q]` yapılır. Slayttaki kodda boyut sabit (100) tanımlanmıştır; pratikte dinamik olması beklenir.
  <!-- BELİRSİZ: Hızlı bulma kodunun slaytı karelerde görünmüyor; kod metni birebir aktarılamadı, yalnız anlatılan mantık yazıldı. -->

### C ile dinamik matris yaratma

- Kod ekrandan birebir alınmıştır (ekrandan, 00:50:00). `gcc -Wall` ile derlendi ve $n=3$, $m=4$ girdisiyle çalıştırıldı.

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

- `main`'den önceki satır, fonksiyon `main`'den sonra tanımlandığı için gereken imzadır (prototip).
  - **Ders sonrası not:** Hoca bu satıra "function pointer" dedi; doğrusu bu satır `int **` döndüren bir fonksiyonun prototipidir, işlev işaretçisi (function pointer) değildir.
- İki boyutlu yapı "dizilerin dizisi" olarak kurulur: önce `rows` tane `int *` için yer ayrılır (her satırın başı bir `int` işaretçisidir), sonra her satıra `cols` tane `int` için yer ayrılır.
- Gözlere `rand() % 9` ile 0-8 arası değer atanır; 0 da yazılabilir. Fonksiyon `int **` türündeki `arr`'ı döndürür, `main`'deki `a` da aynı türdedir.
- Eksik olan: `malloc` başarısız olursa hata kontrolü yoktur; gerçek kodda eklenmelidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
