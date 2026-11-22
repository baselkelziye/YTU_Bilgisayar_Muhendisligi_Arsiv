# Ders 23 Çalışma Özeti

## Genel Konular

- İkinci ara sınav sorularının akademik değerlendirmesi
  - Ekranda üç soru gösterildi (ekrandan, 00:30:00 ve 00:35:00): iki matrisin aynı olup olmadığını bulan algoritmanın akışı, bu akışın C ile kodlanması ve bir matriste istenen iki sütunun yerini değiştiren algoritmanın akışı.
  - Her sorunun hangi yapıyla çözülmesi gerektiği ve öğrenci cevaplarında görülen tipik hatalar konuşuldu.
- Matris eşitliği: her elemanı gezmek yerine ilk farkta durmak
  - Örnekte A ve B matrislerinin ilk iki satırı 2 3 7 ve 1 6 6 / 1 4 6 biçimindedir; satır satır gezildiğinde beşinci karşılaştırmada (2. satır, 2. sütun) 6 ile 4 farklı çıkar ve geri kalan elemanlara bakmaya gerek kalmaz.
  - İki iç içe `for` ile bütün elemanları tarayıp bir bayrak değişkenini değiştirmek doğru sonuç verir, ama hoca bunu yeterli çözüm saymadı: büyük bir matriste (ör. milyonlarca pikselli bir resim) ilk elemanlarda fark varsa geri kalan işlemler boşa gider.
  - Doğru yapı bir şartın kontrolüne dayanan `while` döngüsüdür. Döngü şartı yalnız "A[i][j] eşittir B[i][j]" olursa iki matris aynı olduğunda döngüden çıkılamaz; şart, sınır kontrolünü de içermelidir.
- Sütun takası
  - Önce N, M ve A matrisi, sonra değiştirilecek iki sütun numarası (X, Y) okunur. Satır sayısı kadar dönen tek bir `for` döngüsü yeterlidir; her satırda geçici bir değişken (`tmp`) ile iki göz takas edilir, sonunda matris yazdırılır.
  - Ekrandaki örnekte 3 x 5 matrisin 1. ve 4. sütunları takas edilir: `1 2 3 4 5` satırı `4 2 3 1 5` olur (ekrandan, 00:35:00).
- Akış diyagramı çizim kuralları
  - Okuma (input) kutusuna her zaman üstten girilir, alttan çıkılır; kutuya soldan, sağdan girmek ya da yanından çıkmak derste gösterilen gösterime aykırıdır.
  - Bir değişken değil de metin yazdırılıyorsa metin tırnak içinde yazılmalıdır.
  - İnternetteki farklı kaynakların akış sembolleri birbirinden farklıdır; derste verilen gösterim esas alınmalıdır.
- `for` ile `while` arasındaki seçim
  - Tekrar sayısı belliyse `for`, belli bir şart sağlanana (ya da sağlanmayana) kadar dönülecekse `while` kullanılır.
  - Bir `for` döngüsünden erken çıkmak isteniyorsa bu iş `while` ile yapılmalıdır. `break`, `continue` gibi yapılarla döngüyü bozmak bu derste kabul edilmez.
  - Sonsuz döngü (ör. sürekli hizmet veren bir sunucu) makul bir kullanım örneğidir; `for` alanları boş bırakılarak ya da hep doğru olan bir şartla `while` yazılarak kurulabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Soruyu dikkatle okumak
  - Akış istenen yerde kod yazmak, kod istenen yerde akış çizmek ya da problemin farklı bir varyasyonunu çözmek, istenen problemi çözmemek demektir.
- Önce temel yapıyı öğrenmek
  - Akışta "yaratıcılık" beklenmiyor; temiz, sade ve anlaşılır akışlar bekleniyor. Derste gösterilmeyen sembolleri başka kaynaklardan alıp kullanmak hatalı sonuç doğurur.
- Döngü seçiminin gerekçesi
  - `for` içinden erken çıkmak kodun okunabilirliğini bozar. Hoca ayrıca derleyici ve işlemcinin döngüler için yaptığı optimizasyonları (önbellekleme, boru hattı) da gerekçe olarak verdi.
- Kod yazma pratiği
  - `main`, `return`, `#include` gibi temel yapılar düşünmeden yazılabilecek hale gelmelidir; basit bir akışı kodlayamamak çoğunlukla C pratiği eksikliğinden kaynaklanır.

## Kısa Tekrar Notları

- Matris eşitliği: ilk farkta duran `while` yapısı; şart hem sınır hem eşitlik kontrolünü içerir.
- İki iç içe `for` + bayrak çözümü doğru ama verimsiz kabul edildi.
- Sütun takası: tek `for` (satır sayısı kadar), `tmp` ile takas, sonra yazdırma.
- Okuma kutusuna yalnız üstten girilir.
- Yazdırılan sabit metin tırnak içinde yazılır.
- Tekrar sayısı belli: `for`; şarta bağlı: `while`. `break`/`continue` kullanılmaz.
- Sonsuz döngü sunucu gibi sürekli çalışan sistemlerde makuldür.
- `.c` dosyası düz metin dosyasıdır; uzantı yalnız insanın okuması içindir.

## Detaylı Açıklamalar

- Bu kayıt yeni bir konu anlatmaktan çok ikinci ara sınavın akademik değerlendirmesine ayrıldı. Hoca soruları ekranda açtı ve her biri için beklenen çözümü anlattı.
- Birinci soru, eşit boyutlu iki matrisin aynı olup olmadığını bulmaktır. Matrisler, aynı pozisyondaki bütün elemanlar eşitse aynıdır. Ekrandaki eşitlik örneğinde iki matris de `2 3 7 / 1 4 6 / 5 8 0`dır; eşit olmama örneğinde A'nın ikinci satırı `1 6 6`, B'ninki `1 4 6`dır (ekrandan, 00:30:00). Hoca, 2 ile 2, 3 ile 3, 7 ile 7, 1 ile 1 karşılaştırıldıktan sonra 6 ile 4'ün farklı çıktığını, bundan sonrasına bakmanın anlamı olmadığını gösterdi. Bu yüzden çözüm "farklı bir eleman görene kadar devam et" mantığıyla, bir `while` döngüsüyle kurulmalıdır. Derste bir öğrenci, eşitlik sürdükçe dönen ve i, j indislerini artıran bir `while` önerdi; hoca bu döngünün iki matris aynı olduğunda bitmeyeceğini hatırlattı. Şartın nasıl kurulacağını hoca öğrencilerin düşünmesine bıraktı.
- İkinci soru, birinci sorunun akışını C ile kodlamaktır. Hoca bu akışın basit olduğunu, kodlanamıyorsa sorunun C ortamına yeterince alışmamak olduğunu söyledi.
- Üçüncü soru, bir matriste istenen iki sütunun yerini değiştirmektir. Hoca akışı sözlü olarak tarif etti: N, M ve A okunur, X ve Y sütun numaraları okunur, satır sayısı kadar dönen tek bir `for` içinde her satırın X ve Y gözleri geçici değişkenle takas edilir, son olarak matris yazdırılır. Bu akışın konuyu bilen biri için beş ile on dakikada çizilebileceğini söyledi.
- Bir öğrencinin cevabı ekranda gösterilerek akış kuralları tekrarlandı: okuma kutusuna soldan bir geri dönüş oku girmesi, tırnaksız yazılmış bir mesaj ve derste gösterilmemiş bir sembol hata olarak işaretlendi (ekrandan, 00:55:00). <!-- BELİRSİZ: Hocanın "böyle bir sembol göstermedim" dediği sembolün hangisi olduğu altyazıdan ve kareden kesin anlaşılmıyor. --> Hoca, sütun numaralarının matris boyutunu aşıp aşmadığı kontrol edilmek isteniyorsa bunun bir `if` ile kontrol edilip program sonlandırılarak ya da bir `while` döngüsüyle yapılabileceğini söyledi.
- `for` döngüsünden erken çıkma sorusu üzerine hoca, tekrar sayısı belli işlerde `for`, şarta bağlı işlerde `while` kullanılacağını yineledi. `for` içinden çıkmak `break`, `continue` gibi yapılar demektir ve bu derste kullanılmaz. Hoca gerekçe olarak okunabilirliği ve işlemcinin önbellek/boru hattı optimizasyonlarını gösterdi; sonsuz döngüyü ise sunucu gibi sistemler için makul bir örnek olarak verdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
