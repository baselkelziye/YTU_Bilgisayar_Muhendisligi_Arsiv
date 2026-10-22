# Ders 14 Çalışma Özeti

## Genel Konular

- Dönemin son haftası. Yeni konu işlenmedi, kayıt proje gösterimlerinin son haftasıdır.
- Final duyurusu
  - Final sınavı klasik olacak, **üç** klasik soru sorulacak. Hoca bunu bütün sınıfa duyurmanızı istedi.
  - Her sorunun çözümünün fotoğrafı çekilip hepsi tek bir PDF dosyası hâlinde sisteme yüklenecek.
  - Fotoğraf çekerken yalnızca kağıt görüntüye girsin. Önceki yıllarda çorap, yatak örtüsü gibi şeyler görüntüye giriyordu. Sayfaları düz çevirin, ters dönmüş PDF okumak çok zor.
- Gösterim düzeni
  - Hoca raporu yükleyip henüz gösterim yapmamış olanların listesini çıkarmıştı.
  - Hız için iki öğrenci aynı anda çalıştı: biri ekranını paylaşıp görüntülü bağlandı, diğeri aynı girdileri arka planda kendi programına girdi, sonra sıra ona geçti.
  - "Artık bu son haftamız, mikrofonum yoktu demeyin."
  - Önceki hafta bazı yöntemleri hata veren öğrenciler düzeltilmiş hâllerini gösterdi.
  - Ekstra fonksiyonlar (üstel, logaritmik) ekstra puan kapsamındadır. Yapamayanlar bunun için puan kaybetmez.
- Gösterimlerde görülen tipik hatalar
  - Katsayıları veya ara değişkenleri `int` tanımlamak: 0.1 gibi ondalıklı katsayılar girilince sonuç yanlış çıktı. Simpson ve trapezde hata veren bir öğrencinin sorunu da `double` yerine `int` kullanmasıymış. Hoca sonraki öğrencilere "inşallah katsayılar değişkenini integer tanımlamadınız" diye sordu.
  - Gauss-Seidel'de maksimum köşegen kontrolünün yanlış çalışması: köşegeni zaten büyük olan bir sistem verildiğinde doğru sonuç çıkmadı.
  - Polinom katsayılarını hesaplayan ortak bir fonksiyonda dizi/işaretçi aktarımı hatası: katsayıların yalnızca ilk iki elemanı kullanılıyordu. Bu fonksiyona bağlı altı yöntemin hepsi bozuldu. Hoca "parametre göndermede hata var demek" dedi ve sordu: "Çalışan bir kodu bozmadan önce neden kopyasını almadın?" Öğrenciye akşama kadar düzeltip e-postayla göndermesi için süre verildi.
  - Bazı programlar polinomun "terim sayısını" sorduğu için eksik kuvvetler (ör. $x^3$ ve $x^4$ olmayan bir polinom) karışıklığa yol açtı. Programınız katsayısı sıfır olan terimlerin nasıl girileceğini açıkça belirtmeli.
- Gösterimlerde kullanılan bazı girdiler
  - Kök bulma: $x^2 - 4x - 5$ (kökler −1 ve 5).
  - Sayısal türev: merkezi fark, $h = 0.25$.
  - Gauss eliminasyon (3 bilinmeyen): çözüm 26, 28, 22 olan bir sistem.

## Hocanın Özellikle Vurguladığı Kısımlar

- Final klasik, 3 soru. Çözümler tek PDF olarak yüklenecek, görüntüde yalnızca kağıt olsun.
- Çalışan kodun yedeğini almadan değişiklik yapmayın.
- Ondalıklı sayılarla çalışan değişkenleri `double` tanımlayın.

## Kısa Tekrar Notları

- Final: klasik, 3 soru, fotoğraf, tek PDF.
- Sık hata: `int` yerine `double`, dizi aktarımı, maksimum köşegen kontrolü.

## Detaylı Açıklamalar

### Ders sonrası notlar

- **Final biçimi:** Ders 7'de finalin yüz yüze ve klasik olacağı söylenmişti. Bu derste fotoğrafı çekilip PDF olarak yüklenen klasik bir sınav tarif edildi, yani final de online yapılmış görünüyor. Ders 11'de 4-5 soru dendi, bu derste sayı 3 olarak verildi. Kesin bilgi için o dönemin duyurularına bakın.
- **`int` hatası neden olur?** C'de `int a = 0.1;` ataması 0 değerini verir ve `1/2` gibi tam sayı bölmeleri 0 sonucunu üretir. Sayısal yöntemlerde katsayılar, adım uzunluğu $h$ ve ara sonuçlar hep ondalıklı olduğundan `double` kullanılmalıdır. Döngü sayaçları ve dizi indisleri ise `int` kalabilir.
- **Ortak fonksiyonlarda dizi aktarımı:** C'de bir diziyi fonksiyona gönderince dizinin boyutu kaybolur, yalnızca ilk elemanın adresi gider. `sizeof(dizi)` fonksiyon içinde işaretçinin boyutunu verir. Bu yüzden boyutu (ör. polinomun derecesi) ayrı bir parametre olarak gönderin. Gösterimdeki "yalnızca ilk iki katsayıyı alıyor" belirtisi bu tür bir boyut veya aktarım hatasına benziyor.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
