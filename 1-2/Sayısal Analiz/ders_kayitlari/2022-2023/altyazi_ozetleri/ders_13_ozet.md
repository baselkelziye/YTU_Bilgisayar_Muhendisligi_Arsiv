# Ders 13 Çalışma Özeti

## Genel Konular

- Bu derste yeni konu işlenmedi. Kaydın tamamı (yaklaşık 2 saat 45 dakika) proje gösterimlerinden oluşuyor. Gösterimlerin ikinci haftası.
- Gösterim düzeni
  - Hoca isim okur. Öğrenci numarasını söyler, kamerasını açar, ekranını paylaşır ve kaç yöntemi kodladığını söyler.
  - Hoca bir ya da iki yöntem seçer, kendi girdisini verir ve sonucu elindeki çözümle karşılaştırır. Kalabalık yüzünden bazı öğrencilerde tek kod çalıştırıldı.
  - Zamandan kazanmak için zaman zaman iki öğrenci aynı soruyu birlikte çalıştırdı.
  - Hocanın gözü ekrana uzun süre bakmaktan yorulduğu için bir kısım öğrenci sonraki haftaya kaldı. İsteyenlere ertesi gün akşamüstü bir saat ek gösterim zamanı verildi.
  - Hoca öğrenci numaralarının nasıl okunacağını hatırlattı: ilk iki hane giriş yılı (22), sonraki üç hane bölüm kodu (011), son üç hane sıra numarası.
- Rapor
  - Bütün öğrencilere raporu Online Yıldız'a yükleyip yüklemedikleri soruldu. Raporlara akşam bakılacak.
  - Polinom dışındaki ek fonksiyonlar (üstel, logaritmik, trigonometrik, ters trigonometrik) ekstra puan sayılır. Bunları yapanlar raporda belirtmeli.
  - Hata bulan bir öğrenciye düzeltip aynı gün gece yarısına kadar yeniden yükleme izni verildi.
- Hocanın genel mesajları
  - "Benim için önemli olan kendinizi geliştirmeniz." Hoca öğrencilere güvendiğini, hiçbirini ayırmayacağını söyledi.
  - "Bu kodu yapay zekaya yazdırdım ya da bir yerde buldum diyerek beni çok rahat kandırabilirsiniz, ama kendinizi de kandırmış olursunuz."
  - Bir öğrenci logaritma, üstel gibi fonksiyonları `math.h` kullanmadan Taylor serisiyle kendisi yazmıştı. Hoca bunu gereksiz derecede alt seviyede bulsa da "uğraştıysan kendin kazandın" dedi. Öğrenci, hata çıktığında hatanın kendi matematik fonksiyonundan mı yöntemden mi geldiğini ayırt edemediğini anlattı.
- Gösterimlerde görülen sorunlar
  - Kapalı yöntemlerde uç noktalardan biri tam kökse ($f(a) = 0$ veya $f(b) = 0$) program "ikisi de pozitif" gibi hatalı bir mesaj verdi. $f(a)\cdot f(b) = 0$ durumu da kontrol edilmeli.
  - Durma koşulunu kullanıcıya soran programlarda hoca "durma koşulunu kendin ver" diyerek sorgulamadı. Ama asıl beklenen ölçüt ardışık iki kökün farkıdır.
  - Determinantı sıfır olan bir matrisin tersi istenince bir program hata verdi. Ters almadan önce determinant veya sıfır satır kontrolü yapılmalı.
  - Bazı öğrenciler Gregory-Newton'u yapamamıştı. Bir öğrenci Regula Falsi'yi son günlere bıraktığı için yetiştiremedi.
- Gösterimlerde kullanılan bazı girdiler (kendi kodunuzu sınamak için)
  - Regula falsi: $x^2 - 4x - 5$.
  - Matris tersi: $\begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 2 & 9 \end{bmatrix}$.
  - Gauss-Seidel: köşegeni maksimum olacak şekilde $3x + y = 11$, $2x + 5y = 16$ (çözüm $x = 3$, $y = 2$).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kendiniz yapın, kendinizi kandırmayın. Amaç gelişiminiz.
- Raporu yükleyin, ekstra fonksiyonları raporda belirtin.
- Kamera ve ses açık olmalı.

## Kısa Tekrar Notları

- Gösterim: numara, kamera, yöntem sayısı, hocanın girdisiyle çalıştırma.
- Ek fonksiyonlar (üstel, logaritmik, trigonometrik) ekstra puan.
- Uç nokta kök olabilir: $f(a) \cdot f(b) \le 0$ kontrolü.

## Detaylı Açıklamalar

### Ders sonrası notlar

- **Uç nokta kontrolü:** Ders 2 ve 3'te anlatılan şart $f(a)\cdot f(b) < 0$ idi. Ama $f(a) = 0$ veya $f(b) = 0$ ise kök zaten bulunmuştur. Programda önce bu durumu kontrol edip doğrudan kökü döndürmek, sonra $f(a)\cdot f(b) > 0$ ise "aralıkta kök yok" demek gerekir. Gösterimde $x^2 - 4x - 5$ için $b = 5$ verilince bu durum ortaya çıktı.
- **Tekil matris:** Gauss-Jordan ile ters alırken bir satır tamamen sıfır olursa (determinant sıfır) ters yoktur (Ders 4). Kodunuz bu durumda sıfıra bölmek yerine anlamlı bir mesaj vermeli.
- **Gösterimdeki Gauss-Seidel sisteminin çözümü:** $3x + y = 11$ ve $2x + 5y = 16$ sisteminin çözümü $x = 3$, $y = 2$'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
