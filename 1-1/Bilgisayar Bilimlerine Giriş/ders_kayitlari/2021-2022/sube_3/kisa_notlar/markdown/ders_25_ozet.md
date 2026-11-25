# Ders 25 Çalışma Özeti

## Genel Konular

- Rakamları birbirinden farklı mı? (sayı oyunu kuralı)
  - Problem: verilen bir sayının (örnek 5879) bütün rakamlarının birbirinden farklı olup olmadığını bulmak. Herhangi iki rakam aynıysa sayı kurala uymaz.
  - Çözüm iki aşamalıdır: önce sayı rakamlarına ayrılıp bir diziye konur, sonra her rakam kendinden sonraki rakamlarla karşılaştırılır (5 ile 8, 7, 9; sonra 8 ile 7, 9; sonra 7 ile 9).
  - Basamak sayısı bilinmediği için rakamlara ayırma `while` ile yapılır: `DIZI[I] = N mod 10`, `N = N div 10`, `I = I + 1` (ekrandan, 00:15:00).
  - 5879 için dizi tersten dolar: 1. göz 9, 2. göz 7, 3. göz 8, 4. göz 5. Karşılaştırma açısından ters sıranın bir sakıncası yoktur.
  - Karşılaştırma iç içe iki `while` ile yapılır; `isunique` bayrağı 1 iken döngüler sürer, eşitlik bulununca 0 yapılır ve iki döngüden de çıkılır (ekrandan, 00:30:00).
- İlk akış diyagramındaki hatalar ve düzeltmeleri (ekrandan, 00:30:00)
  - Koşul `N > 9` olduğu için en soldaki rakam (5) diziye girmez; döngüden sonra `DIZI[I] = N` eklenmelidir.
  - Dış döngüde `J = J + 1` unutulmuştu.
  - İç döngü sayacı 1'den değil `K = J + 1`'den başlamalıdır; aksi halde eleman kendisiyle karşılaştırılır ve hatalı "tekrar var" kararı verilir.
  - Döngü sınırları `N` değil `I` olmalıdır: `N` artık son basamağı tutar, dizideki eleman (basamak) sayısını `I` tutar. Doğru koşullar `J < I AND isunique = 1` ve `K <= I AND isunique = 1`.
  - Sonuç: `isunique = 1` ise `'+'` (kurala uygun), değilse `'-'` (uygun değil) yazdırılır.
- Daha verimli çözüm: sayaç (counter) dizisi (ekrandan, 00:35:00 ve 00:40:00)
  - On gözlü bir dizi her rakamın görülüp görülmediğini tutar; başta bütün gözler 0 yapılır.
  - Her adımda `I = N mod 10` alınır; ilgili göz 0 ise 1 yapılır, 0 değilse rakam tekrar etmiştir ve `isunique = 0` yapılır; sonra `N = N div 10`.
  - Akış diyagramında dizi 1'den 10'a numaralandığı için 0 rakamı 1. gözle temsil edilir: `DIZI[I+1]` kullanılır.
  - Son rakamın da işlenmesi için koşul `N > 0` olur; döngü `N > 0 AND isunique = 1` iken sürer, `isunique` başta 1 yapılır.
  - C kodunda diziler 0'dan başladığı için `dizi[i]` doğrudan kullanılır, `+1` gerekmez (ekrandan, 00:45:00).
- İşlem sayısı karşılaştırması
  - İkili karşılaştırma yönteminde $n$ basamak için en kötü durumda $\frac{n(n-1)}{2}$ karşılaştırma yapılır; 5879 için $3 + 2 + 1 = 6$.
  - Sayaç dizisiyle en kötü durumda yalnız basamak sayısı kadar (5879 için 4) kontrol yapılır; iç içe iki döngü yerine tek döngü yeter.
  - Bellekten biraz alan harcanarak zaman karmaşıklığı (işlem sayısı) azaltılır.
- Asal sayı testi (ekrandan, 01:00:00)
  - Asal sayı yalnız 1'e ve kendisine bölünen sayıdır; 2'den $N-1$'e kadar bölenler denenir.
  - İlk çözüm: `I = 2`; `N mod I ≠ 0` iken `I = I + 1`; döngüden çıkınca `N = I` ise asal, değilse asal değil. Masa testi: 2 ve 3 asal, 4 asal değil.
  - Bölen bulunduğu anda durmak gerektiği için `while` kullanılır; 92 gibi çift bir sayı ilk adımda elenir.
- Asal sayı testini iyileştirme (ekrandan, 01:15:00 ve 01:20:00)
  - Bir sayının, kendisi dışında, yarısından büyük böleni olamaz; `M = N div 2`, döngü `I <= M AND isprime = 1` iken sürer, `N mod I = 0` ise `isprime = 0`.
  - Çift sayıları atlamak: önce 2'ye bölünme tek bir `if` ile denenir, sonra `I = 3`'ten başlanıp ikişer artırılır.
  - Karekök sınırı: bölenler karekökün iki yanında çiftler halinde bulunur (36 için 2-18, 3-12, 4-9, 6-6); karekökten büyük her bölenin karekökten küçük bir eşi vardır. Bu yüzden `sqrt(N)`'e kadar denemek yeter.
- $N$'e kadar bütün asal sayılar: eleme yöntemi (ekrandan, 01:25:00 ve 01:30:00)
  - Bir dizide 2'nin katları 1 ile işaretlenir; sonra işaretsiz ilk sayının (3) katları işaretlenir.
  - 3 için işarete $3^2 = 9$'dan başlanır ve 6'şar ilerlenir (9, 15, 21, ...), çünkü çift katlar zaten işaretlidir; 5 için 25'ten başlanıp 10'ar ilerlenir (25, 35, 45, ...).
  - Sonunda 0 kalan gözler asal, 1 olanlar asal olmayan sayılardır. Hoca yöntemin bir antik Yunan adıyla anıldığını, "E" harfiyle başladığını söyledi.
  - Asal sayılar rastgele sayı üretiminde, şifrelemede ve hash fonksiyonlarındaki mod alma işleminde kullanılır.
- Diziler üzerinde temel işlemler (ekrandan, 01:40:00)
  - Insert, Delete, Update, Search, Min, Max, Sort, Avg.
  - Arama ve güncelleme: sırasız $n$ elemanlı dizide en kötü durumda $n$ kontrol gerekir; güncelleme için de önce aranır. Elemanların tekrar etmediği varsayılır.
  - Silme: eleman bulunur, sağındakiler birer sola kaydırılır (3, 1, 2, 4, 5'ten 4 silinince 3, 1, 2, 5, 5), sonra yalnız ilk $n-1$ eleman gösterilir.
  - Ekleme: sırasız dizide sona eklenir. Sıralı dizide (1, 2, 4, 5, 6'ya 3) önce yer bulunur, elemanlar sondan başlayarak (6, 5, 4) birer sağa kaydırılır; baştan kaydırılırsa elemanlar üzerine yazılıp kaybolur.
- En küçük eleman ve yeri (ekrandan, 01:45:00 ve 01:55:00)
  - Değer: `min = dizi[1]`; `I` 2'den `N`'e kadar; `dizi[I] < min` ise `min = dizi[I]`; sonunda `min` yazdırılır.
  - En büyük için yalnız karşılaştırma işareti (ve değişken adı) değişir.
  - Yer: `yer = 1`; `I = 2..N`; `dizi[I] < dizi[yer]` ise `yer = I`; sonunda `yer` ve `dizi[yer]` yazdırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- `for` mu `while` mı?
  - Adım sayısı belliyse `for`, döngünün nerede biteceği belli değilse (eşitlik ya da bölen bulununca durmak gibi) `while` kullanılır.
  - Döngüyü `break` gibi yollarla akış diyagramında yarıda kesmek yanlış kabul edilir; döngü koşula bir bayrak (`isunique`, `isprime`) eklenerek bitirilir.
  - Durması gereken yerde `for` kullanmak gereksiz karşılaştırma demektir. Tersine, adım sayısı belli bir işte `while` işlem sayısını artırmaz ama `for` tercih edilir; derleyici adım sayısı belli döngüleri daha iyi eniyileyebilir.
- Akış diyagramı kuralları
  - Bir akış diyagramının tek bir START ve tek bir STOP noktası vardır.
  - Bir `if`'in yanlış (F) kolu olup doğru (T) kolu boş olamaz; böyle bir durumda koşul ters çevrilmelidir.
- Önce doğru çalışma, sonra verimlilik
  - Çözümün doğru çalışması esastır, ama gereksiz işlemden kaçınmak da beklenir. Milyonlarca kayıtlı sistemlerde (banka, sağlık verisi, kimlik numarasıyla arama) ekleme, silme, güncelleme ve arama sürekli yapılır.
- Sayaç dizisi fikri
  - Bir diziyi sayaç gibi kullanmak (göz = değer, içerik = kaç kez görüldü) işlem sayısını belirgin biçimde azaltır.

## Kısa Tekrar Notları

- Rakamlara ayırma: `mod 10` ile son basamak, `div 10` ile sayıyı küçültme; döngü koşulu `N > 0` olursa son basamak da işlenir.
- İkili karşılaştırmada iç sayaç `K = J + 1`'den başlar, sınırlar eleman sayısını tutan değişkene göre konur.
- $n$ basamak için ikili karşılaştırma: $\frac{n(n-1)}{2}$; sayaç dizisi: $n$.
- Asal sayı testi için `sqrt(N)`'e kadar denemek yeter; 2'den sonra yalnız tek sayılar denenebilir.
- Elemede $p$'nin katlarına $p^2$'den başlanır, tek $p$ için $2p$ adımla ilerlenir.
- Silmede sola, sıralı eklemede sondan başlayarak sağa kaydırma yapılır.
- Min/max: ilk eleman en küçük kabul edilir, kalanlar tek tek karşılaştırılır; yer gerekiyorsa değer yerine indis tutulur.

## Detaylı Açıklamalar

- Rakamları farklı mı problemi, ikili karşılaştırma çözümü (ekrandan, 00:30:00)
  - Düzeltilmiş akış diyagramı:

```text
START
  oku N
  I = 1
  while N > 9:
      DIZI[I] = N mod 10
      N = N div 10
      I = I + 1
  DIZI[I] = N              (en soldaki basamak; I = basamak sayısı)
  J = 1, isunique = 1
  while J < I AND isunique = 1:
      K = J + 1
      while K <= I AND isunique = 1:
          if DIZI[K] = DIZI[J]:  isunique = 0
          K = K + 1
      J = J + 1
  if isunique = 1:  yaz '+'   else:  yaz '-'
STOP
```

  - Ders sonrası not: Dizi tersten dolduğu için (9, 7, 5, 5) 5579 örneğinde eşitlik ilk karşılaştırmada değil son karşılaştırmada bulunur; hoca ilk adımda yakalanacağını sayıyı soldan okuyarak anlattı. Sonuç değişmez, yalnız karşılaştırma sayısı değişir (python ile denendi).
- Sayaç dizisi çözümünün C kodu (ekrandan, 00:45:00; hoca kodun bir kısmını ekranda, kalanını sözlü yazdı)
  - Aşağıdaki kod derste yazılanın tamamlanmış biçimidir; `gcc -Wall` ile derlendi ve 5879 (uygun), 5579 (uygun değil), 1020 (uygun değil), 9 (uygun) girdileriyle denendi.

```c
#include <stdio.h>

int main() {
    int i, number, dizi[20], isunique = 1;

    printf("sayi giriniz\n");
    scanf("%d", &number);
    for (i = 0; i < 10; i++)
        dizi[i] = 0;
    while ((number > 0) && (isunique == 1)) {
        i = number % 10;
        if (dizi[i] == 0) {
            dizi[i] = 1;
        } else {
            isunique = 0;
        }
        number = number / 10;
    }
    if (isunique == 1)
        printf("sayi kurallara uygundur\n");
    else
        printf("sayi kurallara uygun degildir\n");
    return 0;
}
```

  - Hoca diziyi 20 elemanlı tanımladı; bir öğrencinin sorusu üzerine 10 elemanın bu soru için yeterli olduğunu söyledi. `isunique` tanımlanırken 1 yapıldığı için ayrıca atama gerekmez. Tam sayı bölmesi (`/`) iki işlenen de tam sayı olduğu için `div` gibi çalışır.
- Asal sayı, yarıya kadar deneme (ekrandan, 01:20:00)

```text
START
  oku N
  I = 2
  M = N div 2              (iyileştirme: M = sqrt(N))
  isprime = 1
  while I <= M AND isprime = 1:
      if N mod I = 0:  isprime = 0
      I = I + 1
  if isprime = 1:  yaz 'Asal sayı'   else:  yaz 'Asal sayı değil'
STOP
```

  - 48 için: `M = 24`, `I = 2` iken `48 mod 2 = 0` olduğu için `isprime = 0` olur ve döngüden hemen çıkılır.
  - Karekök sınırıyla 101 için yalnız 10'a kadar denemek yeter; ilk çözümde 100'e, yarıya kadar denemede 50'ye kadar gidilirdi.
  - Ders sonrası not: Hoca 48 için "7'ye kadar" dedi; $\sqrt{48} \approx 6{,}93$ olduğundan tam sayı olarak 6'ya kadar denemek yeterlidir.
- Neden yarıya ve karekök sınırına kadar?
  - $N = a \cdot b$ ise $a \geq 2$ olduğundan $b \leq N/2$'dir; ayrıca $a$ ile $b$'den biri mutlaka $\leq \sqrt{N}$'dir. Bu yüzden $\sqrt{N}$'e kadar bölen bulunamazsa sayı asaldır.
- Diziler üzerinde işlemler ve sıralı verinin önemi
  - Sıralı ya da sırasız olmak arama, ekleme ve silme algoritmalarını değiştirir. Sınıftaki en yüksek ve en düşük notu bulmak, ortalama ve istatistik hesapları min/max ve ortalama işlemlerine dayanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
