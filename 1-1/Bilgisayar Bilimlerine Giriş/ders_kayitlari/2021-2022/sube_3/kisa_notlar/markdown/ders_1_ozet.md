# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin amacı
  - Ders, daha önce hiç programlama ya da bilgisayar mühendisliği deneyimi olmayan bir öğrenciyi başlangıç noktası kabul eder (ekrandan, 00:20:00).
  - İki temel hedef vardır: bilgisayar mühendisliğinin temel bilgilerini öğretmek ve algoritma tasarlama yeteneği kazandırmak.
  - Algoritmik düşünme, bir probleme analitik bir çözüm geliştirip bu çözümü adım adım bir algoritma olarak ifade etmektir.
  - Yalnız doğru çalışan değil, verimli (başarımı yüksek) algoritmalar tasarlamak da hedeflenir.
- Dersin içeriği (genel başlıklar)
  - Bilgisayarın ve hesaplama makinelerinin tarihçesi: hesaplamaların hangi cihazlarla yapıldığı, bugünkü yapıya nasıl gelindiği.
  - Bilgisayar mühendisliğinin temel araştırma problemleri ve alanları; yazılım ve donanımla ilgili temel kavramlar.
  - Bilgisayar mimarisi: bu derste tasarlanan algoritmaların hangi mimariye göre düşünüldüğü.
  - Verinin bilgisayarda nasıl işlendiği ve depolandığı: işaretli sayılar, işaretsiz sayılar, kesirli sayılar.
  - Sayı sistemleri ve sistemler arası dönüşümler.
  - Algoritma kavramı: algoritmanın gösterimi, girdi ve çıktılar, aritmetik işlemler, kontrol deyimleri, tekrarlı (döngüsel) işlemler.
  - Kodlamaya giriş: C dili temel alınır. Temel veri tipleri ve aynı tipteki verilerin bir araya gelmesiyle oluşan diziler işlenir.
  - Karakter dizileri ve çok boyutlu (n boyutlu) diziler.
  - Aynı problemin farklı algoritmik yaklaşımlarla çözülmesi ve bu yaklaşımların artı ve eksilerinin karşılaştırılması.
  - Arama algoritmaları ve sıralama algoritmaları.
  - Algoritma karmaşıklığına farkındalık düzeyinde giriş.
  - İşletim sistemleri ve bilgisayar ağlarına temel bir bakış.
- Konu sırası (ekrandan, 00:30:00)
  - Bilgisayarın tarihçesi, veri depolama, sayı sistemleri.
  - Bilgisayar mimarisi, veri manipülasyonu, tam sayılar ve kesirli sayılar.
  - Bilgisayar bilimlerini tanıtıcı problemler.
  - Algoritma kavramları, akış diyagramı ve sembolleri, algoritmalarda girdi, çıktı ve kontroller.
  - Algoritmalarda yineleme yapıları ve döngü koşulları.
  - C programlama diline giriş ve tek boyutlu diziler.
  - Karakter dizileri, çok boyutlu diziler.
  - Arama algoritmaları, sıralama algoritmaları.
  - İşletim sistemleri ve bilgisayar ağları.
- Dersin öğrenim çıktıları (ekrandan, 00:25:00)
  - Bilgisayar mühendisliğiyle ilgili temel kavramları öğrenmek.
  - Doğru ve verimli algoritma tasarımını öğrenmek.
  - Algoritmaları akış şemaları kullanarak betimlemeyi öğrenmek.
  - Bilgisayar mühendisliğinin alt alanları hakkında bilgi sahibi olmak.
- Kaynaklar
  - Temel kaynak derste anlatılanlar ve öğrencinin kendi tuttuğu notlardır.
  - Basılı temel kaynak: Brookshear, *Computer Science: An Overview* (derste 12. baskı gösterildi; son birkaç baskı temel konularda birbirine çok yakındır, farklar daha çok güncel teknolojilerle ilgilidir).
  - Türkçe yardımcı kaynak: Fahri Vatansever, *Algoritma Geliştirme ve Programlamaya Giriş* (Seçkin Yayıncılık).

## Hocanın Özellikle Vurguladığı Kısımlar

- Algoritmik düşünme herkes için aynı hızda gelişmez
  - Kimi öğrenci birkaç haftada, kimi birkaç ayda alışır. İlk başta zorlanmak olağandır ve başarısızlık anlamına gelmez.
- Çözülen örnekleri kapatıp yeniden çözmek
  - Derste çözülen soruları ve anlatılan konuları bakmadan yeniden çözüp sonra kontrol etmek, ek olarak onlarca soru çözmekten daha çok yol aldırır.
- Giriş dersi bir binanın temeli gibidir
  - Sonraki bütün dersler bu derste öğrenilen temel bilgilerin üzerine kurulur. Programlama bildiğini düşünen öğrenci de bu derste eksik ya da yanlış bildiklerini düzeltme fırsatı bulur.
- Başkasının notuna güvenmemek
  - Herkes anladığı kadar not tutar; başkasının notunda yanlış anlaşılmış bilgiler olabilir. Kendi anladığınla kendi notunu oluşturmak önerilir.
- Karmaşıklık bu derste yalnız farkındalık düzeyindedir
  - Biçimsel karmaşıklık analizi ileride veri yapıları ve algoritma analizi derslerinde ayrıntılı işlenir.

## Kısa Tekrar Notları

- Dersin iki ana hedefi: bilgisayar mühendisliğinin temel bilgileri ve algoritma tasarlama yeteneği.
- İyi bir algoritma doğru girdi için doğru sonuç üretir ve verimli çalışır.
- Algoritmalar bu derste ağırlıklı olarak akış şemalarıyla gösterilir.
- Gerçekleme (kodlama) dili C'dir.
- Konu akışı: tarihçe ve sayı sistemleri → mimari ve sayıların gösterimi → algoritma ve akış diyagramı → döngüler → C ve diziler → karakter dizileri ve çok boyutlu diziler → arama ve sıralama → işletim sistemleri ve ağlar.
- Arama ve sıralama algoritmaları, aynı problemin farklı çözümlerinin karşılaştırıldığı temel örneklerdir.
- Karmaşıklık burada yalnız tanıtılır, ayrıntısı sonraki derslerdedir.

## Detaylı Açıklamalar

Bu ilk ders bir tanışma ve tanıtım dersidir; teknik konulara henüz girilmez. Dersin akademik çerçevesi şöyle çizilir: öğrencinin hiçbir ön deneyimi olmadığı varsayılır ve ders bu tabandan başlar. Amaç, bilgisayar mühendisliğinin temel kavramlarını vermek ve özellikle algoritmik düşünmeyi kazandırmaktır. Algoritmik düşünme, bir problemi analiz edip çözümünü adım adım, belirsizlik bırakmadan ifade edebilmektir. Ders bunun yanında etkin, yani mümkün olduğunca iyi başarımlı algoritmalar tasarlamanın temel taşlarını da göstermeyi hedefler.

İçerik bilgisayarın tarihçesiyle başlar, ardından verinin bilgisayarda nasıl tutulduğuna geçer. Bu kısımda sayı sistemleri ve aralarındaki dönüşümler, işaretli ve işaretsiz tam sayılar ve kesirli sayıların gösterimi işlenir. Farklı mimarilerde farklı gösterimler kullanılabileceği için, dersin algoritmalarının hangi mimariyi esas aldığı da ayrıca ele alınır.

Dersin merkezinde algoritma kavramı vardır: algoritmanın nasıl gösterildiği, girdi ve çıktıların nasıl ifade edildiği, aritmetik işlemler, kontrol deyimleri (karar yapıları) ve tekrar eden işlemler (döngüler). Algoritmalar ağırlıklı olarak akış şemalarıyla gösterilir. Teoride kalmamak için algoritmalar C dilinde gerçeklenir; temel veri tipleri, tek boyutlu diziler, karakter dizileri ve çok boyutlu diziler bu gerçeklemelerle birlikte işlenir. Hoca, neden Python yerine C ile başlandığı sorusunun, Python'un dil ve değişken yapısıyla C'nin tasarım yaklaşımı arasındaki farklarla ilgili olduğunu söyler ve tartışmayı C'ye geçilen haftaya bırakır.

Dönemin sonlarına doğru arama ve sıralama algoritmaları üzerinden aynı problemin farklı yaklaşımlarla nasıl çözülebildiği, her yaklaşımın ne kazandırıp ne kaybettirdiği karşılaştırılır. Bir algoritmanın başarımını ölçmek için karmaşıklık kavramı farkındalık düzeyinde tanıtılır. Son konu işletim sistemleri ve bilgisayar ağlarıdır; hoca, adları çok farklı olsa da bu iki alanın temelde benzer kavramları paylaştığını ve problemleri benzer tasarım fikirleriyle çözdüğünü belirtir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
