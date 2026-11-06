# Ders 13 Çalışma Özeti

## Genel Konular

- Bu derste yeni konu işlenmedi. Kaydın tamamı proje gösterimlerinden oluşuyor.
- Gösterimlerde görülen sorunlar
  - Kapalı yöntemlerde uç noktalardan biri tam kökse ($f(a) = 0$ veya $f(b) = 0$) program "ikisi de pozitif" gibi hatalı bir mesaj verdi. $f(a)\cdot f(b) = 0$ durumu da kontrol edilmeli.
  - Logaritma, üstel gibi fonksiyonları `math.h` kullanmadan Taylor serisiyle kendisi yazan bir programda, hata çıktığında hatanın matematik fonksiyonundan mı yöntemden mi geldiği ayırt edilemedi (02:23:27).
  - Durma koşulunu kullanıcıya soran programlarda hoca "durma koşulunu kendin ver" diyerek sorgulamadı. Newton-Raphson için ardışık kök farkı ölçütü Ders 12'de söylenmişti.
  - Hocanın verdiği $4 \times 4$ matrisin tersi istenince bir program "determinant sıfır" uyarısı verdi, determinant `NaN` çıktı (01:21:54-01:22:36). Matris $\begin{bmatrix} 1 & 3 & 5 & 9 \\ 1 & 3 & 1 & 7 \\ 4 & 3 & 9 & 7 \\ 5 & 2 & 0 & 9 \end{bmatrix}$ tekil değildir: $\det = -376$ (Python ile hesaplandı). Sorun ikinci pivotun sıfır olmasıdır: ikinci satırdan birinci çıkarılınca $[0, 0, -4, -2]$ kalır. Satır değiştirmeyen kod burada sıfıra böler. Ters almadan önce determinant kontrol edilmeli, sıfır pivotta satır değiştirilmelidir.
- Gösterimlerde kullanılan bazı girdiler (kendi kodunuzu sınamak için)
  - Regula falsi: $x^2 - 4x - 5$.
  - Matris tersi: $\begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 2 & 9 \end{bmatrix}$.
  - Gauss-Seidel: köşegeni maksimum olacak şekilde $3x + y = 11$, $2x + 5y = 16$ (çözüm $x = 3$, $y = 2$).

## Hocanın Özellikle Vurguladığı Kısımlar

- Ters almadan önce determinantın sıfır olup olmadığı kontrol edilmeli (01:21:56).
- Aralık uçlarından biri kök olabilir, kod bu durumu da kontrol etmeli (01:48:51).

## Kısa Tekrar Notları

- Uç nokta kök olabilir: $f(a) \cdot f(b) \le 0$ kontrolü.
- Sıfır pivot, matrisin tekil olduğu anlamına gelmez: önce satır değiştirilir.

## Detaylı Açıklamalar

### Ders sonrası notlar

- **Uç nokta kontrolü:** Ders 2 ve 3'te anlatılan şart $f(a)\cdot f(b) < 0$ idi. Ama $f(a) = 0$ veya $f(b) = 0$ ise kök zaten bulunmuştur. Programda önce bu durumu kontrol edip doğrudan kökü döndürmek, sonra $f(a)\cdot f(b) > 0$ ise "işaret değişimi yok, bu aralıkta kök garanti değil" demek gerekir. Bu durumda kök olmadığı kesin değildir: $x^2 - 4x - 5$ için $[-5, 6]$ aralığında $f(-5) = 40$, $f(6) = 7$ ikisi de pozitiftir ama aralıkta $-1$ ve $5$ kökleri vardır (hoca bu aralığı 01:49:41'de verdi). Gösterimde $x^2 - 4x - 5$ için $b = 5$ verilince uç nokta durumu ortaya çıktı.
- **Tekil matris:** Gauss-Jordan ile ters alırken bir satır tamamen sıfır olursa (determinant sıfır) ters yoktur (Ders 4). Kodunuz bu durumda sıfıra bölmek yerine anlamlı bir mesaj vermeli.
- **Gösterimdeki Gauss-Seidel sisteminin çözümü:** $3x + y = 11$ ve $2x + 5y = 16$ sisteminin çözümü $x = 3$, $y = 2$'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
