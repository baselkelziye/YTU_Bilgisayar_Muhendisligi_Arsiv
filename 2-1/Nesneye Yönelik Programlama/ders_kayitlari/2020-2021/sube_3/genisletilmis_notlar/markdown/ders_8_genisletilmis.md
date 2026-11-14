# Ders 8 Genişletilmiş Notu: Laboratuvar 1: Müşteri-Sipariş-Ürün Sorusu (Kısa Kayıt)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sorunun Biçimi
- 2. UML Diyagramı
- 3. Metotlardan İstenen Davranış
- 4. Kodu Yazarken

## 1. Sorunun Biçimi

Bu kayıt konu anlatımı değil, Laboratuvar 1'in kısa açılış oturumudur. Çözüm yapılmadı. Akademik içerik olarak yalnız sorunun kendisi konuşuldu. Soru, Online Yıldız'daki `Lab1.rar` dosyasının içindedir. Konu bir müşteri, sipariş ve ürün uygulamasıdır.

Toprak Hoca soru biçimini şöyle anlattı:

- Bir UML diyagramı verilir.
- Diyagramdaki metotlardan get ve set olmayanların ne yapacağı metinle açıklanır.
- `main` metodunu içeren test sınıfı yazılı olarak hazır verilir.
- Test sınıfının üreteceği çıktılar da verilir.

Öğrencinin işi, kalan üç sınıfı doldurup bu çıktıları üretmektir. Kontrol de bu çıktılar üzerinden yapılır.

> **Hocanın vurgusu:** `main` sınıfını kendiniz tekrardan yazmayın. Dosyadan kopyalayıp yapıştırın ve aşağıdaki çıktıyı elde etmeye çalışın.

Hoca, kısıtlara ve söylenenlere dikkat edilirse sorunun çok basit olduğunu söyledi. Yapı, derste yapılan uygulamaya da "neredeyse aynı" diye benzetildi. Bu uygulama, kısa nota göre Ders 6'daki Kitap-Raf-Kitaplık örneğidir.

## 2. UML Diyagramı

Soru dosyası kayıtta ekranda gösterildi, ama altyazıda diyagramın içeriği sözlü olarak okunmuyor. Aşağıdaki liste kısa nottan alındı.

<!-- BELİRSİZ: UML, kısa notun ekran karesinden aktardığı biçimiyle verildi. Bu işte hazır kare yok, yeniden doğrulanamadı. Kısa not, küçük yazılı kısımlarda harf hatası olabileceğini belirtiyor; asıl soru dosyası esas alınmalı. -->

### 2.1 Sınıflar

- `Musteri`
  - Alanlar: `- ad: String`, `- soyad: String`, `- siparisler: Siparis[]`
  - Metotlar: `Musteri(String ad, String soyad)`, `siparisVer(int siparisNo, Urun urun)`, `siparisBilgisi(int siparisNo)`, `tumSiparisler()`, `kacSiparis(String urunAdi)`, `tumSiparislerdenUrunCikar(Urun urun)`, `urunCikar(int siparisNo, Urun urun)`, `getSiparisTutari(int siparisNo): double`
- `Siparis`
  - Alan: `- urunler: Urun[]`
  - Metotlar: `Siparis()`, `getUrunler(): Urun[]`, `urunEkle(Urun urun)`, `urunleriGoster()`, `urunCikar(Urun urun)`, `getToplamTutar(): double`
- `Urun`
  - Alanlar: `- ID`, `- ad`, `- fiyat`, `- zamSayisi <static>`
  - Metotlar: `Urun(int ID, String ad, double fiyat)`, `getAdi(): String`, `getID(): int`, `getFiyat(): double`, `setAd(String ad)`, `zamYap(double zamOrani)`, `getZamSayisi(): int`, `toString(): String`

> **Ders sonrası not:** Kısa nota göre diyagramda `Urun` alanlarının tipleri yazılmamış. Constructor'dan bakılınca tipler büyük olasılıkla `int ID`, `String ad`, `double fiyat` ve `static int zamSayisi` şeklindedir.

### 2.2 İlişkiler ve Kapasiteler

İki ilişki vardır:

1. `Musteri`, dolu elmasla `Siparis`'e bağlıdır (bileşim).
2. `Siparis`, boş elmasla `Urun`'e bağlıdır (birleştirme).

Her müşterinin 3 siparişi, her siparişin 5 ürünü olmalıdır.

> **Ek bilgi (derste anlatılmadı):** Bu ayrım Ders 6'daki kod kuralıyla okunabilir. Koyu elmasta nesne sınıfın içinde oluşur; o hâlde `Musteri` constructor'ı büyük olasılıkla `new Siparis[3]` ile diziyi ayırdıktan sonra her hücreye ayrıca `new Siparis()` koyar. Boş elmasta nesne dışarıda oluşur; `new Urun[5]` yalnız referans için yer ayırır, ürünler `urunEkle` ile dışarıdan gelir. Aynı `Urun` nesnesi birden fazla hücreden gösterilebildiği için `zamYap` ile değişen fiyat, o ürünü içeren bütün siparişlerin tutarına yansır (javac ile denendi).

### 2.3 Uygulamayla Eşleşme

Kısa nota göre sınıflar Ders 6'daki örnekle birebir eşleşir:

| Ders 6 uygulaması | Laboratuvar 1 |
|---|---|
| `Kitaplik` | `Musteri` |
| `Raf` | `Siparis` |
| `Kitap` | `Urun` |

## 3. Metotlardan İstenen Davranış

Altyazıda metot açıklamaları tek tek okunmuyor; hoca yalnız "burada açıklıyoruz metotları" diyerek dosyayı gösterdi. Bu bölümdeki kurallar kısa nottan alındı.

<!-- BELİRSİZ: Metot açıklamalarının tam metni soru dosyasında kaldı. Sipariş numarasının 0'dan mı 1'den mi başladığı, zamOrani'nın biçimi, çıktı metinlerinin tam hâli ve bir siparişte aynı ürün iki kez varsa urunCikar'ın hangisini çıkaracağı altyazı ve kısa nottan anlaşılmıyor. -->

### 3.1 Bilgi Yazdıran Metotlar

- `siparisBilgisi`: Verilen sipariş numarasındaki bütün ürünlerin bilgilerini yazdırır.
- `tumSiparisler`: Müşterinin bütün siparişlerindeki ürünleri sırayla yazdırır.

`toString`, `Urun` sınıfında override edilmeli ve ürün bilgilerini içeren bir `String` döndürmelidir.

### 3.2 En Çok Mantık Gerektiren Metot: kacSiparis

`kacSiparis`, verilen ürün adının kaç siparişte ve toplam kaç kez sipariş edildiğini yazdırır. Dikkat edilecek nokta, bir ürünün aynı siparişte birden fazla kez olabilmesidir. Bu yüzden istenen iki sayı aynı şey değildir.

> **Hocanın vurgusu:** Soruda en mantık gerektiren şey bu metottur. Stratejinize göre önce veya sonra yapabilirsiniz.

<!-- BELİRSİZ: Altyazıda hoca yalnız "şu metod" diyor, ekranı gösteriyor. Metodun kacSiparis olduğu kısa nottan alındı. -->

> **Ek bilgi (derste anlatılmadı):** Derste çözüm yapılmadı; aşağıdaki kod resmî çözüm değil, büyük olasılıkla kabul edilebilecek bir yazımdır. Her sipariş için ayrı bir adet sayılır: adet sıfırdan büyükse sipariş sayısı bir artar, adet her durumda toplama eklenir. Boş hücreler `null` olduğu için `getAdi` çağrılmadan önce kontrol edilir ve ad `String` olduğu için `equals` ile karşılaştırılır. `getUrunler` metodu, `Musteri`'nin ürünlere bu şekilde ulaşmasını sağlar. Çıktı metni burada örnek olarak yazıldı; asıl biçim soru dosyasındadır (javac ile derlendi ve çalıştırıldı).
>
> ```java
> public void kacSiparis(String urunAdi) {
>     int siparisSayisi = 0;
>     int toplam = 0;
>     for (Siparis siparis : siparisler) {
>         int buSiparistekiAdet = 0;
>         for (Urun urun : siparis.getUrunler()) {
>             if (urun != null && urun.getAdi().equals(urunAdi)) {
>                 buSiparistekiAdet++;
>             }
>         }
>         if (buSiparistekiAdet > 0) {
>             siparisSayisi++;
>         }
>         toplam += buSiparistekiAdet;
>     }
>     System.out.println(urunAdi + ": " + siparisSayisi + " sipariste, toplam "
>             + toplam + " kez");
> }
> ```

### 3.3 Ürün Çıkarma ve Tutar

- `urunCikar`: Verilen sipariş numarasından ürünü çıkarır.
- `tumSiparislerdenUrunCikar`: Ürünü bütün siparişlerden çıkarır.
- `getSiparisTutari`: Siparişteki ürünlerin fiyatlarını toplar ve `double` döndürür.

### 3.4 Statik Alan: zamSayisi

`zamSayisi`, tek bir ürünün değil, bütün ürünlerin toplam zam sayısını tutar. Bu yüzden statik bir alandır: hangi ürüne zam yapılırsa yapılsın aynı sayaç değişir.

## 4. Kodu Yazarken

Hoca, get, set ve `toString` gibi kısımlar için NetBeans'in ya da kullanılan IDE'nin otomatik üretme özelliğini hızlıca kullanmak gerektiğini söyledi.

## Dersin Toparlaması

Laboratuvar 1, Ders 6'daki üç katmanlı yapının yeni bir senaryoya uygulanmasıdır: müşteri siparişlerden oluşur, sipariş ise ürünleri içerir. Soru UML diyagramı, metot açıklamaları, hazır test sınıfı ve beklenen çıktıyla verilir. Öğrenci üç sınıfı yazıp bu çıktıyı üretir. Dikkat isteyen başlıca yerler, aynı ürünün bir siparişte birden fazla kez olabildiği `kacSiparis` metodu ve bütün ürünler için ortak tutulan statik `zamSayisi` alanıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
