# Ders 3 Çalışma Özeti

## Genel Konular

- Problemleri arama problemi olarak modellemek
  - Bir problem; durumlar, başlangıç durumu, hedef durumu, durumları birbirine dönüştüren operatörler (aksiyon/hareket) ve kısıtlarla tanımlanır.
  - Çözüm, başlangıç durumundan hedef durumuna götüren hareketler sırasıdır. Arama ağacında hedef bulunduğunda hedefi köke bağlayan yol çözümü verir.
  - Farklı görünen problemler aynı yapıya getirilince hepsi aynı arama algoritmalarıyla çözülebilir.
- Derste modellenen örnek problemler (ekrandan, 00:10:00 - 00:35:00)
  - Küp planlama: masadaki küpleri (A, B, C) mevcut pozisyondan istenen pozisyona getirmek. Hareketler: küp tutma, küpü yere koyma, küpü başka bir küpün üzerine koyma.
  - Robot yol planlama: labirentte başlangıç noktasından (B) hedef noktasına (H) sola, sağa, aşağı, yukarı hareketlerle en az maliyetli yolu bulmak. Hareketlerin maliyetleri farklı olabilir.
  - Çiftçi (Ali), kurt, keçi ve kabak nehir problemi: durum dört harfli bir dörtlüdür (farmer, wolf, goat, cabbage), her harf N (kuzey) ya da S (güney) olur.
  - Su bidonları (jugs) problemi: 4 ve 3 galonluk iki bidon ve sınırsız pompa ile 4 galonluk bidonda tam 2 galon elde etmek.
  - 8'li yapboz (8-puzzle): taşları kaydırarak başlangıç dizilişinden hedef dizilişine ulaşmak.
- Temel tanımlar
  - Durum uzayı / arama uzayı / arama ağacı, operatör, başlangıç ve hedef durumları, operatör uygulama maliyeti, çözüm yolu, optimum yol (en düşük maliyetli çözüm yolu; birden fazla olabilir).
- Aramanın neden zor olduğu
  - İşlenecek durum sayısı dallanma sayısı ve çözüm derinliğiyle üstel büyür; hem zaman hem bellek sorun olur.
- Arama algoritmalarını karşılaştırma kriterleri
  - Tamlık (completeness), zaman karmaşıklığı, hafıza karmaşıklığı, optimumluk.
  - Kullanılan büyüklükler: $b$ maksimum dallanma sayısı, $d$ en az maliyetli çözümün derinliği, $m$ arama uzayının maksimum derinliği (bazen $\infty$).
- Kör (bilgisiz) arama stratejileri
  - Enlemesine arama (BFS), düşük maliyetli arama (uniform cost search), derinlemesine arama (DFS), sınırlı derinlikte arama (depth-limited), artan derinlikli arama (iterative deepening). Çift yönlü arama sonraki derse kaldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çözüm yolu ile durum açma sırası farklı şeylerdir.
  - BFS'te çözüm 1-2-5 olabilir ama algoritma durumlara 1, 2, 3, 4, 5 sırasıyla bakar. Açılan durum sayısı genelde çözüm uzunluğundan çok daha büyüktür.
- BFS ile DFS arasındaki tek fark yeni durumların dizinin neresine eklendiğidir.
  - Hep baştan çekilir. Yeni durumlar sona eklenirse enlemesine, başa eklenirse derinlemesine arama olur. Bu küçük fark algoritmanın bütün özelliklerini değiştirir.
- Optimumluk tanımında "ilk bulunan çözüm" ifadesi önemlidir.
  - Algoritmanın bulduğu ilk çözüm en düşük maliyetli çözüm (ya da onlardan biri) ise algoritma optimumdur.
- Operatör sayısını azaltmak arama uzayını küçültür.
  - 8-puzzle'da her taş için 4 hareket (32 operatör) yerine boş kareyi hareket ettiren 4 operatör yeterlidir.
- Derinlik bir arttığında iş yaklaşık $b$ kat artar.
  - Bilgisayarların hızlanması bu üstel büyümeyi telafi etmez.
- DFS'in en güzel tarafı belleğin doğrusal ($O(bm)$) olmasıdır; artan derinlikli arama bunu korurken tamlık ve (eşit maliyette) optimumluk kazandırır.

## Kısa Tekrar Notları

- Problem gösterimi: durum + başlangıç + hedef + operatörler (+ kısıtlar). Çözüm = operatör dizisi.
- Nehir problemi: $2^4 = 16$ durum; başlangıç (S,S,S,S), hedef (N,N,N,N); 7 hamlelik çözüm.
- Su bidonu çözümü: (0,0) → (0,3) → (3,0) → (3,3) → (4,2) → (0,2) → (2,0).
- 8-puzzle: ortalama çözüm derinliği 22, ortalama dallanma sayısı yaklaşık 2,67.
- BFS: tam ($b$ sonlu ise), zaman ve bellek $O(b^d)$, tüm adım maliyetleri eşitse optimum. Bellek zamandan büyük sorundur.
- Düşük maliyetli arama: kökten toplam maliyeti en az düğümü genişletir; tam ($b$ sonlu, maliyet > 0), zaman ve bellek $O(b^d)$, maliyetler pozitifse optimum. Maliyetler eşitse BFS ile aynıdır.
- DFS: sonsuz derinlik / döngü varsa tam değil, zaman $O(b^m)$, bellek $O(bm)$, optimum değil. Çözümler yoğunsa BFS'ten hızlı bulabilir.
- Sınırlı derinlikte arama (sınır $L$): $L \ge d$ ise tam, zaman $O(b^L)$, bellek $O(bL)$, optimum değil.
- Artan derinlikli arama: tam, zaman $(d+1)b^0 + d\,b^1 + (d-1)b^2 + \dots + b^d = O(b^d)$, bellek $O(bd)$, tüm maliyetler eşitse optimum.

## Detaylı Açıklamalar

Derste önce birkaç problem tek bir yapıya getirildi. Küp problemi için bir kol küp tutabilir, küpü yere ya da başka bir küpün üzerine bırakabilir. Bir başlangıç durumunda uygulanabilecek her hareket yeni bir duruma götürür; bu durumlardan da yeni durumlar çıkar ve böylece bir arama ağacı oluşur (ekrandan, 00:10:00). Hedef durum ağacın bir yerinde bulunduğunda, onu köke bağlayan yol çözümdür. Robot yol planlama probleminde de aynı mantık geçerlidir. Burada kısıtlar duvarlar (kırmızı hücreler) ve yalnız dört yöne gidebilmektir. Hareket maliyetleri farklı olabilir; örneğin yukarı çıkmak yer çekimi yüzünden daha pahalı olabilir (ekrandan, 00:15:00).

Nehir probleminde Ali sandalla kurt, keçi ve kabağı karşıya geçirmek ister. Sandal Ali ile birlikte en fazla bir nesne taşır. Ali yokken kurt ile keçi ya da keçi ile kabak aynı tarafta kalmamalıdır. Durum (farmer, wolf, goat, cabbage) dörtlüsüyle gösterilir. Yasak durumlar slaytta şablonla verildi: kurt keçiyi yer için (N, S, S, \_) ve (S, N, N, \_); keçi kabağı yer için (N, \_, S, S) ve (S, \_, N, N). Burada "\_" o nesnenin yerinin önemli olmadığını gösterir (ekrandan, 00:25:00). Operatörler değişkenle yazılır: Move(Goat, North) kuralı (S, ?wolf, S, ?cabbage) durumunu (N, ?wolf, N, ?cabbage) durumuna çevirir. Değişken kullanımı burada 4 kural yerine 1 kural yazmayı sağlar (ekrandan, 00:30:00). Gösterilen çözüm 7 hamledir: keçiyi götür, yalnız dön, kurdu götür, keçiyi geri getir, kabağı götür, yalnız dön, keçiyi götür.

Su bidonu probleminde durum $(x, y)$ ikilisidir: $x$ 4 galonluk, $y$ 3 galonluk bidondaki su. Başlangıç (0,0), hedef (2, herhangi). Sekiz operatör tanımlandı: bidonları doldurmak, boşaltmak, birinden diğerine dolana kadar aktarmak ve birini diğerine tamamen boşaltmak. Örneğin "4 galonluk bidon dolana kadar 3 galonluktan aktar" operatörü $(x, y) \to (4,\; y-(4-x))$ dönüşümünü yapar ve $x+y \ge 4$, $y>0$ ister. Gösterilen çözüm 2, 7, 2, 5, 3, 7 operatörleriyle 6 adımdır ve python ile doğrulandı.

Arama zorluğu bir tabloyla gösterildi: $b=10$, saniyede 1000 durum, durum başına 100 bayt varsayıldığında derinlik 2 için 111 durum ve 0,1 saniye, derinlik 8 için $10^8$ durum, 31 saat ve 11 GB, derinlik 12 için $10^{12}$ durum, 35 yıl ve 111 TB gerekir (ekrandan, 01:05:00). Ağaç baştan kurulmaz; durumlar arama sırasında üretilir ve bir dizide (kuyruk ya da yığın) tutulur. Algoritmalar bu dizinin nasıl yönetildiğiyle ayrılır: BFS'te yeni durumlar sona eklenir, DFS'te başa eklenir, düşük maliyetli aramada dizideki elemanlardan kökten maliyeti en küçük olan çekilir. Sınırlı derinlikte arama DFS'e bir derinlik sınırı ekler; artan derinlikli arama bu sınırı 0'dan başlayıp birer birer artırır ve her seferinde kökten başlar. Üst seviyelerdeki düğümler tekrar tekrar ziyaret edilse de en büyük terim olan son seviye tekrarlanmadığı için ek maliyet küçüktür: $b=10$, $d=5$ için 111.111 yerine 123.456 düğüm, yani yaklaşık %11 fazlası.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
