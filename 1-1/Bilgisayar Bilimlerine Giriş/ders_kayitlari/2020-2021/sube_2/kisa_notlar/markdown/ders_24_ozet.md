# Ders 24 Çalışma Özeti

## Genel Konular

- Bu ders yeni konu anlatılmayan bir soru-cevap oturumu olarak geçti
  - Hoca yeni bir konu işlemeyeceğini, öğrencilerin sorularını yanıtlayacağını söyledi.
  - Akademik kısım; C öğrenme önerileri, matris transpozu akışındaki hatalar, sıralı diziye eleman ekleme, günlük hayattan algoritma problemi üretme ve C kodundaki hata türleri etrafında toplandı.
- C dilini öğrenmek için kaynak seçimi
  - İnternette rastgele blog ve sitelerdeki kodlar çoğu zaman mühendislik açısından kötü, sistematiği oturmamış ve verimsiz kodlardır; bunlara bakarak kod yazmaya çalışılmamalıdır.
  - Hoca, Türkçe kaynaklarda bol hata gördüğünü, yabancı ve güvenilir bir kitabın tercih edilmesini önerdi. Dönem başında önerdiği eski bir C kitabını, konuları yazılım mühendisliği bakışıyla "neden böyle yapılır" diye anlattığı için iyi bir kaynak olarak andı. <!-- BELİRSİZ: kitabın yazarı altyazıda "Margulis" diye geçiyor; doğru ad doğrulanamadı. -->
  - C derleyicileri programcının hatalarıyla pek ilgilenmez; bu yüzden C'de her türlü hataya açık olunur.
- `break`, `continue`, `goto` kullanılmaz
  - C, Assembly'den sonra gelen yüksek seviyeli bir dildir. Assembly'de kod yazanların alışkanlıklarını sürdürebilmesi için bazı direktifler dile konmuştur.
  - Bunlar sistematik düşünceye aykırıdır ve derleyicinin arka planda yaptığı optimizasyonları bozar. Tek istisna `switch` içindeki `break`'tir.
  - İnternette aranan C kodlarının önemli bir kısmında bu yapılar görülür; kaynak seçiminde seçici olunmalıdır.
- Linux üzerinde çalışarak kendini geliştirmek
  - Paketleri hazır kurmak yerine bir yazılımın kaynak kodunu indirip derlemek, çalıştırılabilir hale getirip kurmak denenebilir.
  - Linux çekirdeğini (kernel) derlemek, modülleri açıp kapatmak ve yeni modül yüklemek, modülün nasıl derlendiğine bakmak önerildi.
  - C, ilerideki işletim sistemi (Linux çekirdeği ile ilgili projeler) ve ağ dersleri (soket programlama) için hakim olunması gereken bir dildir.
- Matris transpozu akışındaki hatalar (bir öğrencinin gönderdiği çözüm üzerinden)
  - Transpoz, elemanların ana köşegene göre karşılıklı yer değiştirmesidir: `A(i)(j)` ile `A(j)(i)` yer değiştirir.
  - Birinci hata: iç döngü bütün matrisi `1`'den dolaşmamalı; yalnız köşegenin üst tarafı dolaşılmalıdır. İç döngü `J ← I + 1`'den başlamalıdır (birinci satırda 2'den, ikinci satırda 3'ten).
  - İkinci hata: `A(I)(J) = A(J)(I)` bir yer değiştirme değildir, yalnız atamadır. Yer değiştirmek için geçici değişken gerekir: `TMP ← A(I)(J)`, `A(I)(J) ← A(J)(I)`, `A(J)(I) ← TMP`. Tek bir operatörle iki değeri değiştirmek mümkün değildir.
- Sıralı bir diziye eleman yerleştirme
  - Sıralı dizide yeni eleman doğru yere konacaksa, önce yeri bulunur, sonra o yerden sonraki elemanlar birer konum sağa kaydırılır, açılan boşluğa yeni eleman yazılır.
  - Bu, derste yapılan "iki sıralı diziyi yeni bir dizide sıralı birleştirme" probleminin tek elemanlı bir versiyonu gibidir.
- Günlük hayattan algoritma problemi üretme
  - Kargo şubesi: boyutları ya da ağırlıkları bir dizide sırayla verilen kolilerin, sırayla yüklendiğinde kaç kamyona sığacağını hesaplayan algoritma.
  - Banka ya da mağaza: belli bir kapasite varken, gelen kişi sayısı bir dizide verildiğinde kapıda en fazla kaç kişilik kuyruk oluşacağı.
  - Saat: verilen bir saat için akrep ile yelkovan arasındaki açı.
  - Dizi problemleri: tek elemanları başa, çift elemanları sona koymak; bir dizinin başka bir dizi içinde geçip geçmediğini bulmak; sıralama ve arama standart problemlerdir.
- Derleme zamanı ile çalışma zamanı ayrımı ve C kodundaki hata türleri
  - Derleme pasif bir durumdur; kodun dilin sözdizimi kurallarına uyup uymadığını gösterir. Sonucun doğru olup olmadığı çalışma zamanında (runtime) görülür.
  - Hataların ağırlığı farklıdır: son `printf`'ten sonra noktalı virgülü unutmak küçük bir hatadır; `main` fonksiyonunu hiç yazmamak, C'de olmayan veri tiplerini (`string`, `boolean` gibi) kullanmak ise programın C olmadığını gösterir.
  - Akışta bir sayacı ilklendirmemek (sıfır atamamak) akışın geri kalanı doğru olsa da yanlış sonuç verir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akış diyagramında yalnız derste gösterilen semboller kullanılır
  - İşlem kutusuna üstten girilir, alttan çıkılır. Kutuya soldan girip üstten ve sağdan çıkan çizimler kabul edilmez.
  - Şekillerin nasıl çizildiği ve neyin nereye gittiği bellidir; bu kurallara uyulması beklenir.
- `break`, `continue` ve `goto` kullanılmaz; tek istisna `switch` içindeki `break`'tir.
- İki değişkenin değerini değiştirmek için geçici değişken şarttır; `A(I)(J) = A(J)(I)` yalnız bir atamadır.
- Bir formülle tek adımda çözülen bir problem de bir algoritmadır
  - Hoca, saat açısı formülü için "formülle de formülsüz de yapabilirsin" dedi; tek bir işlem kutusunda alt alta yazılan işlemlerle çözülen ATM (banknot) problemi de bir algoritmadır.
- Kaynak seçiminde seçici olun; internetteki rastgele kodlardan öğrenmeye çalışmayın.

## Kısa Tekrar Notları

- Transpoz: `A(i)(j)` ile `A(j)(i)` yer değiştirir; yalnız köşegenin üstü dolaşılır, iç döngü `I + 1`'den başlar.
- Bütün matris dolaşılıp her çift değiştirilirse her çift iki kez değişir ve matris eski haline döner.
- Yer değiştirme (swap) üç atamayla ve bir `TMP` ile yapılır.
- Sıralı diziye ekleme: yeri bul, sonraki elemanları birer sağa kaydır, boşluğa yaz.
- Saat açısı (bir öğrencinin söylediği formül): $\theta = \dfrac{|60 \cdot \text{saat} - 11 \cdot \text{dakika}|}{2}$ derece.
- Derleme sözdizimini, çalışma zamanı sonucu doğrular.
- `scanf` ile tamsayı okurken değişkenin önündeki `&` unutulmamalıdır.
- C'de `string` ya da `boolean` diye yerleşik veri tipi yoktur.

## Detaylı Açıklamalar

- **Matris transpozu.** Bir öğrenci, $N \times M$ boyutlu `A` matrisinin transpozunu bulan akışını hocaya göndermişti. Akışta `N, M` ve `A(N)(M)` okunuyor, `I ← 1 || 1` (bitiş `N`) ve içinde `J ← 1 || 1` (bitiş `M`) döngüleri kuruluyor, döngü gövdesinde `A(I)(J) = A(J)(I)` yazıyordu (ekrandan, 00:35:00). Öğrencinin örnek matrisi ve transpozu ekranda şöyleydi:

  ```text
        | 1   8   6 |              | 1   4   7 |
    A = | 4  10   5 |        A^T = | 8  10  11 |
        | 7  11   4 |              | 6   5   4 |
  ```

  Hoca iki hatayı gösterdi. Birincisi, elemanlar köşegene göre karşılıklı yer değiştirdiği için yalnız köşegenin üst tarafını dolaşmak yeterlidir; iç döngü `1`'den değil `I + 1`'den başlamalıdır. Böylece birinci satırda ikinci sütundan, ikinci satırda üçüncü sütundan başlanır ve sınır kendiliğinden kayar. İkincisi, `A(I)(J) = A(J)(I)` yalnız `A(J)(I)`'yı `A(I)(J)`'ye atar; önce `A(I)(J)` bir `TMP`'ye alınmalı, sonra atama yapılmalı, en son `TMP` `A(J)(I)`'ya yazılmalıdır. Python ile denendi: öğrencinin yalın ataması ekrandaki matrisi $\begin{pmatrix}1&4&7\\4&10&11\\7&11&4\end{pmatrix}$ gibi simetrik bir matrise çevirir; bütün matris dolaşılıp swap yapılırsa matris değişmez; `J ← I + 1` ve swap ile ekrandaki $A^T$ elde edilir.

  > **Ders sonrası not:** Aynı matris üzerinde yerinde (in-place) transpoz yalnız kare matriste ($N = M$) çalışır. Öğrencinin akışı `N` ve `M`'yi ayrı okuyor; $N \neq M$ ise transpoz $M \times N$ boyutlu ayrı bir matrise yazılmalıdır. Bu ayrıntı derste konuşulmadı.

- **Sıralı diziye ekleme.** Örnek dizi `3, 5, 7, 9, 11`'dir. Değeri 7 ile 9 arasına düşen bir eleman geldiğinde 9 ve 11 birer konum sağa kaydırılır, aradaki boşluğa yeni eleman yazılır. <!-- BELİRSİZ: eklenen elemanın değeri altyazıda kesik. -->
- **Problem üretme.** Hoca, algoritma çalışmak için kaynak aramaya gerek olmadığını, problemlerin etrafa bakarak üretilebileceğini anlattı. Kargo kamyonu, banka kuyruğu ve saat açısı örneklerini verdi. Bir öğrencinin söylediği saat açısı formülünü kabul etti; problem formülle tek adımda da çözülse bir algoritma problemidir.
- **Hata türleri.** Kodda derlemenin başarılı olması yalnız sözdiziminin doğru olduğunu gösterir; sonucun doğruluğu çalışma zamanında denetlenir. C'de genelde tek bir hata değil bir grup hata yapılır; küçük hatalar (noktalı virgül, `scanf`'te `&`) ile programın yapısını bozan hatalar (`main` yok, C'de olmayan tip) aynı ağırlıkta değildir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
