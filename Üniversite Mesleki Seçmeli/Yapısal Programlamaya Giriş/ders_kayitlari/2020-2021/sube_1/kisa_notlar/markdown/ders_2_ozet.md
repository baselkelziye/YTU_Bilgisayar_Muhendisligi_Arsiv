# Ders 2 Çalışma Özeti

> Kayıt iki parçadır; arşivde parçalar ters sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## Genel Konular

- Dersin kapsamı
  - Ders C programlama dili üzerinden yürütülür. Odak, algoritmik düşünce ve iyi algoritma geliştirmektir.
  - Ekranda gösterilen konu listesi: algoritma ve iyi algoritma, yaklaşık değer bulma ($\pi$, $e^x$, $\cos(x)$), tempsiz swap, palindrom sayılar, binary arama, seçim sistemleri, sıralama, rekürsif olmayan algoritmaların analizi, rastgele değer üretimi, fonksiyonlar, rekürsif fonksiyonlar ve analizleri, stringler, NP türü algoritmalar (ekrandan, 01:16:31).
  - Laboratuvarlarda verilen problemler çözülür.
- Algoritma nedir?
  - Bir problemi çözmek için atılması planlanan tanımlı ve sonlu adımlar dizisidir.
  - Algoritma yalnız bilgisayar problemlerine özgü değildir. Yemek tarifi de bir algoritmadır.
- Tarif örnekleri: omlet ve pizza hamuru
  - Derste iki öğrenci omlet ve pizza hamuru tarifini anlattı. Hoca belirsiz kalan yerleri sorularla netleştirdi: "ne kadar beklersin", "piştiğini nasıl anlarsın", "ne kadar çırparsın".
  - Bu soruların amacı, algoritmanın karşı taraf tarafından anlaşılabilecek kadar net olması gerektiğini göstermektir.
- Gündelik dil ile programlama yapıları arasındaki karşılıklar
  - Süresi ya da miktarı belli tekrar ("10 dakika ısıt", "500 metre git"): `for`.
  - Bir koşul oluşana kadar tekrar ("soğanlar pembeleşinceye kadar ısıt", "X'i görünceye kadar düz git"): `while`.
  - Seçenekli adım ("kekik yoksa nane koy"): `if-then-else`.
  - Bir yerden bir yere aktarma ("makarnayı süzgeçten tencereye aktar"): atama.
- Robota ev çizdirme deneyi
  - Hoca robot rolüne girdi. Bir öğrenci beyaz ekranda ev çizdirmek için sözlü komut verdi. Komutlar belirsiz olduğu için çizgiler sık sık silinip yeniden çizildi.
  - Sonuç: komutlar kesin ve anlaşılır olmalı, önce plan (algoritma) yapılmalı, sonra koda geçilmelidir.
- Programlama dillerine neden ihtiyaç var?
  - İnsan dili bilgisayar için fazla muğlaktır. İnsanlarla konuşurken birçok şeyi söylemeyiz, karşı tarafın bildiğini varsayarız.
  - Bilgisayarla iletişim için kesin kurallı programlama dilleri gerekir. Algoritma, koda kolay dönüştürülebilecek biçimde kurulmalıdır.
- İyi algoritmanın ölçütleri
  - Bir algoritma diğerinden daha hızlı, daha az donanım/enerji kullanan, daha anlaşılabilir, daha doğru ya da daha modüler olabilir (ekrandan, 01:46:31).
  - Hiçbir ölçüt her zaman diğerlerinden önemli değildir. Önemi duruma göre değişir.
- Ödünleşim (trade-off)
  - Genelde bir ölçütte kazanırken başka bir ölçütte kaybedilir (ekrandan, 01:51:31):
    - Daha fazla bellek kullanarak daha hızlı bir algoritma geliştirilebilir.
    - Daha fazla enerji (GPU) kullanarak daha hızlı bir algoritma geliştirilebilir.
    - Daha yavaş bir algoritma kullanarak daha doğru bir algoritma elde edilebilir.
  - Örnekler: küçük RAM'li bir işlemcide yavaş ama az bellekli algoritma seçilir. Video öneri sisteminde çok doğru ama yavaş algoritma yerine biraz daha az doğru ama hızlı algoritma seçilir.
- Gauss toplamı örneği
  - $1+2+\dots+100 = 50 \cdot 101 = 5050$ (ekrandan, 01:56:31).
  - Genel hali $1+2+\dots+N = (N/2)\cdot(N+1)$.
  - Döngüyle toplamak $N$ işlem, formül 3 işlem (toplama, bölme, çarpma) ister (ekrandan, 02:01:31).
- Karmaşıklık azaltmanın etkisi
  - Ekrandaki örnekler: $N \to N/2$, $N\cdot N \to N$, $N \to \log_2 N$ (ekrandan, 02:06:31).
  - $\log_2$ değerleri: $1000 \to 10$, $1000000 \to 20$, $1000000000 \to 30$. Girdi 1000 kat büyüyünce adım sayısı yalnız 10 artar.
- Google ve PageRank örneği
  - Google'ı öne çıkaran önemli parçalardan biri, arama ile sayfa benzerliğini sayfanın güvenilirliğiyle birleştirmesiydi. Güvenilirliği PageRank algoritması hesaplar: bir siteye ne kadar çok başka siteden link verilirse o site o kadar güvenilir sayılır.
  - Önceki arama motorlarında sayfaları elle kategorilere ayırma işi ölçeklenebilir değildi. Web sayfası sayısı üstel arttığı için çalışan sayısının da üstel artması gerekirdi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Amaç algoritma geliştirmek değil, iyi algoritma geliştirmektir
  - Bir işi yapmanın birçok yolu vardır. Herkes bir çözüm bulabilir. Bilgisayar mühendisinden beklenen iyi çözümdür.
- Trade-off'u aklınızdan çıkarmayın
  - Hız, bellek, enerji ve doğruluk arasında hep bir denge vardır. Hangisinin seçileceği ortama ve amaca bağlıdır.
- İyi algoritma geliştirmek iteratif bir süreçtir
  - İlk seferde mükemmel algoritma beklenmez. Önce bir algoritma kurulur, sonra yavaş ve çok bellek tüketen parçaları incelenip iyileştirilir.
- Algoritma geliştirmenin bir algoritması yoktur
  - Algoritma geliştirmek deneyimle, algoritma geliştirerek öğrenilir. Bunun bir algoritması olsaydı bilgisayar mühendislerine gerek kalmazdı.
  - Algoritmik düşüncede zorlananlara code.org sitesinin bütün seviyeleri önerildi.
- "Bilgisayarlar zaten hızlı" yanılgısı
  - Mühendislerin işlediği veri miktarı bilgisayarların hızından daha hızlı büyür. Bu yüzden iyi algoritmaya ihtiyaç artar.
  - $N$'den sabit sayıda işleme inmek çok nadir ve mükemmel bir iyileşmedir. Genelde $N^2 \to N$ ya da $N \to \log_2 N$ gibi iyileştirmeler üzerinde çalışılır.
- İyileştirmeyi bekleyen çok problem var
  - Google çıktığında kimse daha iyi bir arama motoru beklemiyordu. "Zaten yapılmış, daha iyisi olur mu?" diye düşünülmemelidir.

## Kısa Tekrar Notları

- Algoritma: problemi çözen tanımlı, sonlu adımlar dizisi.
- Algoritma net olmalı. "Biraz bekle", "piştiğinde" gibi ifadeler netleştirilmeli.
- `for`: sayısı/süresi belli tekrar. `while`: koşul sağlanana kadar tekrar. `if-else`: seçim. Aktarma: atama.
- Programlama dilleri, insan dilinin muğlaklığı yüzünden gereklidir.
- İyi algoritma ölçütleri: hızlı, az donanım/enerji, anlaşılabilir, doğru, modüler.
- Ölçütler arasında trade-off vardır: bellek ↔ hız, enerji ↔ hız, hız ↔ doğruluk.
- $1+\dots+N$: döngüyle $N$ işlem, $(N/2)(N+1)$ ile 3 işlem.
- $\log_2 1000 \approx 10$, $\log_2 10^6 \approx 20$, $\log_2 10^9 \approx 30$.
- Algoritma geliştirmek iteratif bir süreçtir ve deneyimle öğrenilir.
- PageRank: çok link alan sayfa daha güvenilir. Elle kategorileme ölçeklenemezdi.

## Detaylı Açıklamalar

- **Algoritmanın netliği.** Derste omlet tarifinde "zeytinyağını koyup biraz beklerim" ifadesi "küçük baloncuklar çıkana kadar beklerim" diye netleşti. Yumurtanın 2-3 dakika çatalla çırpıldığı, pizza hamurunda 6 bardak unun parça parça eklendiği ve hamurun 1,5-2 katına çıkana kadar bekletildiği soru sorularak ortaya çıktı. Hoca bu soruları algoritmanın karşı taraf tarafından anlaşılabilecek kadar açık olması gerektiğini göstermek için sordu. Bilgisayara verilen talimatta "biraz", "kızarınca" gibi belirsiz ifadeler kullanılamaz.
- **Gündelik dil ve programlama yapıları.** Yemek tariflerinde ve yol tariflerinde kullanılan kalıplar programlama dillerinin temel yapılarına karşılık gelir. "500 metre git, sonra sola dön" ne kadar gidileceğini önceden söylediği için `for` döngüsüne, "şunu görene kadar düz git" bir koşula bağlı olduğu için `while` döngüsüne benzer. "Evde kekik yoksa nane koy" bir `if-then-else` yapısıdır. "Makarnayı süzgeçten tencereye aktar" ise bir şeyi bir yere koymak, yani atamadır.
- **Robot deneyi ve programlama dilinin gereği.** Hoca kendini robot gibi davranan bir çizim aracı olarak tanıttı ve bir öğrencinin sözlü komutlarıyla ev çizmeye çalıştı. "Biraz daha aşağı in", "60 derecelik bir çizgi çek", "üstten" gibi komutlar farklı yorumlandı, birçok çizgi silinip yeniden çizildi ve sonunda tuhaf bir ev çıktı. Buradan iki ders çıkarıldı: komutların kesin olması ve önceden plan yapılması gerekir. Robotun neyi anladığı baştan bilinmiyordu. Bir programlama dilinde ise dilin neyi anladığı önceden bellidir. Önce plan, yani algoritma oluşturulur, sonra koda dönüştürülür. İnsan dili insanlar için bile muğlak olabildiğinden bilgisayara kesin iş yaptırmak için programlama dilleri gerekir.
- **İyi algoritma ve trade-off.** Öğrencilerin önerileriyle ekrana iyi algoritmanın ölçütleri yazıldı: hızlı, az donanım/enerji, anlaşılabilir, doğru, modüler. Doğruluk için hava tahmini ve video öneri sistemleri örnek verildi. Modülerlik için algoritmanın parçalarının iyi tasarlanması anlatıldı. Hoca bu ölçütlerin hiçbirinin tek başına her zaman en önemli olmadığını, çoğu zaman birinden kazanılırken diğerinden kaybedildiğini söyledi (trade-off, Türkçesi ödünleşim). Az RAM'li küçük bir işlemcide yavaş ama az bellek kullanan algoritma zorunlu olabilir. Öneri sisteminde ise kullanıcı videoyu bitirmeden öneriler hazır olmalıdır. Bu yüzden 5-10 saniyede çok doğru öneri üreten algoritma yerine daha hızlı, biraz daha az doğru algoritma seçilir.
- **Gauss toplamı.** Gauss'un ilkokul öğretmeni sınıfı meşgul etmek için 1'den 100'e kadar sayıların toplamını istemiş. Gauss baştaki ve sondaki sayıların toplamının 101, baştan ikinci ile sondan ikincinin toplamının da 101 olduğunu görmüş. 50 tane 101 olduğu için sonuç $50 \cdot 101 = 5050$ olur. Genel halde $1+2+\dots+N = (N/2)\cdot(N+1)$ yazılır (ekrandan, 01:56:31). Döngüyle toplama $N$ tane toplama ister. Formül ise $N$ ne kadar büyük olursa olsun 3 işlem ister. Bir işlemi eleman sayısına bağlı olmaktan çıkarıp sabit sayıda işleme indirmek çok nadir rastlanan, mükemmel bir iyileştirmedir.
- **Logaritmik iyileşme.** $N \to N/2$ iyileştirmesi işi yarıya indirir. $N^2 \to N$ ise $N$ milyar mertebesindeyken çok büyük fark yaratır. $N \to \log_2 N$ için hoca şu tabloyu yazdı (ekrandan, 02:06:31): $1000 \to 10$, $1000000 \to 20$, $1000000000 \to 30$. Yani 1000 adım yerine 10, 1 milyon adım yerine 20, 1 milyar adım yerine 30 adım. Python ile kontrol: $\log_2 1000 \approx 9{,}97$, $\log_2 10^6 \approx 19{,}93$, $\log_2 10^9 \approx 29{,}90$. Değerler yaklaşık olarak doğrudur ($2^{10}=1024$).
- **Google örneği.** Hoca, geçmişte Yahoo ve AltaVista gibi arama motorlarının yeterli görüldüğünü, Google çıkınca kullanıcıların kısa sürede ona geçtiğini anlattı. Google'ın öne çıkmasındaki önemli parçalardan biri algoritmasıydı. Kullanıcı aramasıyla sayfa arasındaki benzerliği sayfanın güvenilirliğiyle birleştirdi. Güvenilirlik PageRank ile hesaplanır: çok sayıda siteden link alan site daha güvenilir sayılır (bu, algoritmanın yayımlandığı haliyle bilinen mantığıdır). Diğer arama motorlarında binlerce kişi yeni sayfaları elle kategorilere ayırıyordu. Web üstel büyüdüğü için bu yöntem ölçeklenebilir değildi. Ölçeklenebilirlik, $N^2$ olan bir işi $N$'e indirmek gibi, veri büyüdükçe maliyetin kontrol altında kalması demektir.
- **Algoritma karmaşıklığının hesabı.** Bir öğrenci, çok sayıda döngü içeren algoritmaların işlem sayısının nasıl hesaplanacağını sordu. Hoca bunun dönem içinde görüleceğini söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
