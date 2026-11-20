# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin konu akışı
  - Ders yapay zekanın tanımları ve tarihçesiyle başlar. Ardından kör ve sezgisel arama algoritmaları (yapay zekanın en temel konusu), oyunlar, bilgi gösterimi ve çıkarım mekanizmaları, makine öğrenmesi ve en sonda yapay zekada etik ve hukuk konuları gelir.
  - Temel kaynak hocanın slaytlarıdır. Daha fazlası için yapay zekanın klasik ders kitabı Russell ve Norvig'in kitabı önerildi.
- Zeka nedir?
  - Zekayı yalnız insanı diğer canlılardan ayıran bir özellik olarak tanımlamak doğru değildir; hayvanların da zekice davranışları vardır (cevizleri arabaların altına atıp kırdıran kargalar, kavanozun kapağını açan ahtapot, ayna testi).
  - Webster sözlüğüne göre zeka, öğrenme ve problem çözme kapasitesidir (ekrandan, 00:25:00).
  - Slayttaki rakamlı yazı ("1N73LL1G3NC3 15 7H3 4B1L17Y 70 4D4P7 70 CH4NG3. 573PH3N H4WK1NG") Stephen Hawking'in "Zeka, değişime uyum sağlama yeteneğidir" sözüdür. Bu yazıyı ilk kez görüp okuyabilmek, sözün anlattığı uyum yeteneğinin kendisidir (ekrandan, 00:25:00).
- Yapay zeka tanımları
  - Marvin Minsky: İnsanlar tarafından yapıldığında zeka gerektiren şeyleri makinelere yaptırma arayışı.
  - Chris Riesbeck: "Bilgisayarlar neden bu kadar aptal?" sorusuna cevap arama. Buradaki "aptal", bilgisayarın ona her şey söylenmeden bir şey yapamaması demektir.
- Yapay zekaya nasıl ulaşmalı? Dört yaklaşım (ekrandan, 00:30:00)
  - İki boyut vardır: düşünmek / hareket etmek ve insan gibi / rasyonel.
  - Dört yaklaşım: insan gibi düşünmek, rasyonel düşünmek, insan gibi hareket etmek, rasyonel hareket etmek. Bugün benimsenen yaklaşım rasyonel hareket etmektir.
  - Rasyonel (doğru) davranış: eldeki verilere göre hedefe ulaşmada en büyük faydayı sağlayan davranış.
  - "Uçmayı kuşlardan öğrenmedik": uçaklar kanat kullanır ama kanat çırpmaz, yine de kuşlardan hızlıdır. Zeki davranış için de insan beynini birebir taklit etmek gerekmez.
  - "Hareket etmek" fiziksel hareket değil, dışarıdan ölçülebilen çıktılarla değerlendirme demektir. İnsanın nasıl düşündüğünü tam bilmediğimiz için "insan gibi düşünüyor mu?" ölçülemez; "insan kadar ya da daha iyi yapabiliyor mu?" ölçülebilir.
- Yapay zekanın iki temel hedefi (ekrandan, 00:35:00)
  - Pragmatik hedef: makineleri daha akıllı ve yararlı hale getirmek.
  - Kendimizi anlamak: insan zekasını simüle eden programlar yazmak. Bir şeyi simüle edebilmek için onu anlamak gerekir (bilardo simülasyonu için fizik kurallarının bilinmesi gibi).
- Akıllı / zeki davranışın ipuçları (ekrandan, 00:40:00)
  - Tecrübelerden öğrenme, yeni duruma başarılı ve çabuk adaptasyon, problem çözebilme, bilgiyi bulma ve kullanma, muhakeme edebilme, rastlantılardan yararlanabilme, farklılar arasındaki benzerlikleri ve benzerler arasındaki farkları görebilme, yeni fikir ve kavram üretebilme, çok anlamlı ya da çelişki içeren bilgileri kullanabilme.
- Düşünce deneyi (ekrandan, 00:50:00 ve 00:55:00)
  - 1000 yıl önce yaşayan birine bugünkü bir bilgisayarı göstersek ona zeki der mi? Nasıl çalıştığını anlatsak hâlâ zeki der mi?
  - Hoca dersin sonunda yüzünü sıyırıp bir android olduğunu gösterse ona hâlâ zeki der miyiz? Programını görsek?
  - Beyin görüntüsünde beynimizin yerinde elektronik bir sistem olduğunu öğrensek kendimize hâlâ zeki der miyiz?
- Yapay zekayla ilgili disiplinler: bilgisayar bilimleri, psikoloji, felsefe, dilbilim, nöroloji.
- Turing testi (ekrandan, 01:15:00)
  - Bir sorgulayıcı, duvarın ardındakiyle yalnız yazışarak onun insan mı makine mi olduğuna karar vermeye çalışır. Ayırt edemiyorsa ve karşıdaki bir yapay zeka sistemiyse sisteme zeki denmelidir.
  - Test yalnız çıktılara bakar; sistemin içinde nasıl çalıştığıyla ilgilenmez (fonksiyonelist bakış).
  - Loebner yarışması bu fikrin yarışma biçimidir. Testi uzun bir diyalogda geçebilen bir sistem henüz yoktur.
- ELIZA (1965, Joseph Weizenbaum) (ekrandan, 01:20:00)
  - İlk sohbet programı; bir terapisti simüle eder. Kalıp (şablon) kurallarıyla çalışır, kullanıcının cümlesini dönüştürüp soru olarak geri söyler (Rogerian psikoterapi tekniği).
  - Zeki olmadığı açıktır ama dönemin bazı insanlarını kandırabilmiştir.
- Searle'ün Çin odası
  - Odadaki kişi Çince bilmeden, kural kitabına ve veri çekmecelerine bakarak Çince girdilere doğru çıktılar üretir. Kişi işlemciyi, kural kitabı programı, veri çekmeceleri RAM ve diski temsil eder.
  - Searle'e göre bir programı izleyerek çalışan bir sistem, dışarıdan ne yaparsa yapsın zeki sayılamaz; sözdizimi tek başına anlam (semantik) üretmez.
- İki öğrenci (Gauss) örneği (ekrandan, 01:25:00)
  - $1+2+\dots+N$ toplamını biri tek tek çok hızlı toplar, diğeri $\frac{N}{2}(N+1)$ formülünü bulur. Yalnız sonuca bakılırsa hızlı olan daha değerli görünebilir; sürece bakılırsa formülü bulan daha zekicedir. Hızlı öğrenci bilgisayarı temsil eder.
- Ned Block'un soru-cevap ağacı (ekrandan, 01:30:00)
  - Belirli bir süreden kısa bütün olası söyleşileri içeren dev bir ağaç, yalnız eğer-ise kurallarıyla Turing testini geçebilir. Block'a göre zeka yalnız ayırt edilemeyecek biçimde cevap verme yeteneği değildir; bir davranışa zeki demek, onun nasıl üretildiği hakkında bir önermedir.
- Rudolf Arnheim: yöntem sorunu
  - Zekanın çözebildiği her problemin yalnız zekayla çözüleceği söylenemez. Zihinsel süreçler çıktıları üzerinden tanımlanmadıkça ya da insan zekasının mekanizması ortaya çıkmadıkça bilgisayarların yöntemine zekice denemez; bilgisayarlar yalnız daha hızlıdır.
- Yapay zeka savunucuları (ekrandan, 01:45:00)
  - Aşağıdan yukarıyacılar: beynin fiziksel yapısı bilişsel yapımızda önemlidir; yapay sinir ağları ve örnek tabanlı öğrenme.
  - Yukarıdan aşağıyacılar: simgesel temsil şemalarına ve düşünme kurallarına odaklanır; arama, mikro dünyalar, Marvin Minsky'nin frame'leri, Roger Schank'ın senaryoları, sağduyu bilgisi.
  - Bugün aşağıdan yukarıyacılar öndedir, ama bu zamanla değişebilir.
- Yapay zeka karşıtları
  - Searle: sözdizimi anlam üretmez, bilgisayarlar işledikleri simgelerin anlamını bilmez.
  - Gödel teoremi: aritmetik içeren her biçimsel sistemde insanın doğruluğunu bildiği ama sistemin ispatlayamadığı doğrular vardır. John Lucas buradan insan zihninin makinelerin hep üstünde kalacağı sonucunu çıkarır.
  - Turing'e göre soru felsefi değil deneysel ele alınmalıdır; Searle'e göre deneysel yaklaşım olamaz, çünkü program izleyen bir şey düşünemez.
- Yapay zekanın kısa tarihi
  - 1943 McCulloch ve Pitts ilk yapay nöron; 1949 Hebb öğrenme kuralı (aynı anda aktif iki nöron arasındaki bağ güçlenir); 1950 Turing'in makalesi; 1951 Minsky ve Edmonds ilk yapay sinir ağı bilgisayarı.
  - 1950-1966 büyük beklentiler dönemi (ekrandan, 01:50:00): Turing'in 50 yıllık tahmini, Newell ve Simon'ın "10 yılda dünya satranç şampiyonu bir bilgisayar olacak" tahmini (1997'de gerçekleşti), otomatik çevirinin yakın olduğu beklentisi.
  - Neden gerçekleşmediler: dünya / sağduyu bilgisinin büyük etkisi, problem karmaşıklığının üstel artması, kısıtlı dünyaların (mikro dünyalar) gerçek dünyayı modelleyememesi.
  - 1966-1973 "biraz da gerçekler" (ekrandan, 01:55:00): Minsky ve Papert'in yapay sinir ağlarının birçok problemde başarısızlığını göstermesi ve fonların kesilmesi; Bryson ve Ho'nun çok katmanlı ağları (eğitim algoritması olmadığı için 1980'lere kadar ilgi görmedi); otomatik çeviride hüsran.
  - 1979-1990 uzman sistemler; Japonya'nın Prolog tabanlı Fifth Generation projesi; ABD ve Avrupa'nın büyük YZ yatırımları; "now with AI" pazarlama klişesi.
  - 1991-1995 YZ kışı: Fifth Generation durduruldu; odak insanın yerini alan programlardan uygun problemlere YZ uygulamaya ve insanı destekleyen programlara kaydı.
  - Günümüz (ekrandan, 02:00:00): Deep Blue 1997'de Kasparov'u yendi; Go ve StarCraft'ta insanlar yenildi; DARPA sürücüsüz araç yarışması (132 mil); Mars'ta otonom robot; konuşmayı yazıya çeviren programlar; daha ileri tarihli ve daha ince aralıklı hava tahmini.
- Kimine kolay, kimine zor (ekrandan, 02:05:00)
  - İnsan için zor, makine için kolay: çok veriye göre işlem gerektiren, formal tanımlı, bütün durumlarına makinenin erişebildiği problemler (planlama, lojistik, uçuş saatleri, satranç gibi oyunlar).
  - İnsan için kolay, makine için zor: sayı dizisinde sonrakini bulma, Bongard problemleri, dil anlama, resim anlama, dünya bilgisi; yani değişkenliği yüksek, olası bütün durumların kapsanamadığı problemler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Arama algoritmaları yapay zekanın en temel konusudur
  - Dersin büyük bir bloğu kör ve sezgisel aramaya ayrılmıştır; oyunlar da aramanın devamıdır.
- Zeka tanımında net bir uzlaşı yoktur
  - Bir sürü tanım vardır, ama herkesin kabul ettiği açık bir tanım yoktur. Zekayı tanımlamak zor, zeki bir davranışı görünce tanımak kolaydır.
- Bugünkü ana çizgi "rasyonel hareket etmek"tir
  - İnsanın nasıl düşündüğünü bilmediğimiz için ölçüt çıktılardır; zeki davranış için insanı birebir taklit etmek gerekmez.
- Turing ile karşıtlarının tartışması hâlâ açıktır
  - Turing çıktılara, karşıtları (Searle, Block, Arnheim) sürece bakar. Hoca hangi tarafın kesin haklı olduğunu söylemedi; öğrencilerin bu tartışmayı bilmesini istedi.
- İlk kez görülen bir problemi çözebilmek asıl kritik olandır
  - Benzerini gördükten sonra çözmek çok şey ifade etmez; zeki davranışın göstergesi yeni bir duruma çabuk uyum sağlamaktır.
- Problemlerin karmaşıklığı üstel artar
  - 8×8 satrançta bilgisayarlar insandan çok iyidir; ama 24×24 gibi yeni ve çok daha büyük bir tahtada arama uzayı çok büyüyeceği için bu üstünlük korunamayabilir.

## Kısa Tekrar Notları

- Webster: zeka = öğrenme ve problem çözme kapasitesi. Hawking: değişime uyum sağlama yeteneği.
- Minsky: insanın zekayla yaptığını makineye yaptırma. Riesbeck: "bilgisayarlar neden bu kadar aptal?"
- Dört yaklaşım: insan gibi / rasyonel × düşünmek / hareket etmek. Hedef: rasyonel hareket etmek.
- Rasyonel davranış: eldeki verilere göre hedefe ulaşmada en büyük fayda.
- YZ'nin iki hedefi: yararlı makineler ve insan zekasını anlamak.
- Turing testi çıktıya bakar; Çin odası, Ned Block ağacı ve Arnheim sürece bakar.
- ELIZA (1965, Weizenbaum): kalıp kurallarıyla çalışan terapist programı.
- Çin odası: kişi = işlemci, kural kitabı = program, veri = RAM/disk.
- Gauss örneği: $1+\dots+N = \frac{N}{2}(N+1)$; hız değil süreç zekadır.
- Aşağıdan yukarı (sinir ağları) ve yukarıdan aşağı (simgesel) yaklaşımlar.
- Tarih: 1943 yapay nöron, 1949 Hebb, 1950 Turing, 1969 Minsky-Papert, 1980'ler geri yayılım, uzman sistemler, Fifth Generation, YZ kışı, 1997 Deep Blue.
- Makine için zor: değişkenliği yüksek, bütün durumları kapsanamayan problemler (Bongard, dil ve resim anlama, dünya bilgisi).

## Detaylı Açıklamalar

- **Zeka ve yapay zeka:** Ders zekanın ne olduğu sorusuyla başladı. Zekayı insana özgü saymak hayvanlardaki zekice davranışlar yüzünden doğru olmaz: kargaların cevizleri yola atıp arabaların kırmasını beklemesi, ahtapotun kavanozun kapağını açması, ahtapotun ayna testini geçmesi örnek verildi. Ayna testinde hayvan uyurken yüzüne boya sürülür; uyandığında aynada kendini görüp boyayı çıkarmaya çalışıyorsa kendinin farkındadır. Webster tanımı zekayı öğrenme ve problem çözme kapasitesi olarak verir. Slayttaki harfleri rakamlarla değiştirilmiş yazı, Stephen Hawking'in "Zeka değişime uyum sağlama yeteneğidir" sözüdür; yazının biçimi sözün içeriğini gösterir, çünkü onu ilk kez görüp okuyabilmek tam da uyum yeteneğidir.

- **Dört yaklaşım ve rasyonellik:** İnsan her zaman rasyonel değildir; zararını bile bile bir şey yapabilir, duygular kararları etkiler. Bu yüzden hedef "insan gibi" değil "rasyonel" olmaya kaymıştır. Uçak örneği bunu anlatır: uçmayı kuşlardan esinlenerek öğrendik ama uçaklar kanat çırpmaz, jet motoruyla kuşlardan hızlı gider. Benzer şekilde zeki sistemler kurmak için beyindeki nöron bağlantılarını birebir modellemek gerekmez. Düşünmekten hareket etmeye geçiş de ölçülebilirlik yüzündendir: insanın nasıl düşündüğünü bilmediğimiz için bir sistemin "insan gibi düşündüğünü" test edemeyiz, ama problemi insan kadar ya da daha iyi çözüp çözmediğini çıktılarından ölçebiliriz.

- **Düşünce deneyi:** Üç aşamalı bir sınıf tartışması yapıldı. Birinci aşamada 1000 yıl önceki birine bilgisayar gösterilir; büyük olasılıkla zeki der, ama nasıl çalıştığı anlatılırsa demeyebilir (bugün bizim kendi bilgisayarlarımıza "iyi programlanmış araç" dememiz gibi). İkinci aşamada karşımızdaki hocanın bir android olduğu ortaya çıkar; öğrencilerin bir kısmı "insan gibi her şeyi yapıyorsa zekidir" derken bir kısmı "aldatılmış hissederim" dedi. Üçüncü aşamada kendi beynimizin elektronik bir sistem olduğunu öğreniriz. Tartışma, açıklanabilen bir şeye zeki demekte zorlandığımızı ve bir şeyin programlanmış olmasının zeki sayılıp sayılmamasını etkileyip etkilememesi gerektiğini gösterdi.

- **Turing testi ve karşı görüşler:** Turing 1950'deki "Bilgisayarlar düşünebilir mi?" makalesinde, yalnız yazışmayla karşıdakinin insan mı makine mi olduğunu ayırt edemeyen bir sorgulayıcı varsa makineye zeki denmesini önerdi. Test yalnız çıktıya bakar. Süre önemlidir: kısa sürede sorulabilecek soru sayısı az olduğu için bir dakika insan taklidi yapmak, on dakika yapmaktan çok daha kolaydır. ELIZA kalıp kurallarıyla (ör. "My boyfriend made me come here" → "YOUR BOYFRIEND MADE YOU COME HERE?") dönemin bazı insanlarını etkilemiştir, ama arkası çok basittir. Searle'ün Çin odasında içerideki kişi Çince bilmeden kural kitabıyla doğru cevap üretir; bu düzen bir bilgisayarın kendisidir ve Searle'e göre böyle çalışan bir şey zeki sayılamaz. Gauss örneği, Ned Block'un soru-cevap ağacı ve Arnheim'ın yöntem sorunu da aynı noktaya varır: önemli olan çıktı değil, çıktının nasıl üretildiğidir. Öte yandan insanın nasıl düşündüğünü bilmediğimiz için süreç ölçütü nesnel değildir; Turing bu yüzden çıktılara odaklanır. Hocaya göre tartışma hâlâ açıktır.

- **Tarihçe:** Yapay nöron (1943) ve Hebb kuralından (1949) sonra 1950-1966 büyük beklentiler dönemidir. Tahminler zamanında gerçekleşmedi; nedenleri sağduyu bilgisinin bilgisayara aktarılamaması, problem karmaşıklığının üstel artması ve küçük dünyalarda çalışan sistemlerin gerçek dünyaya ölçeklenememesidir. 1969'da Minsky ve Papert yapay sinir ağlarının sınırlarını gösterince fonlar kesildi; çok katmanlı ağlar eğitim algoritması olmadığı için 1980'lere kadar ilgi görmedi. 1980'lerde geri yayılımla sinir ağları yeniden gündeme geldi, asıl yükseliş 2012'den sonra başladı. Uzman sistemler ve Japonya'nın Prolog tabanlı Fifth Generation projesi büyük yatırım çekti; beklentiler karşılanmayınca proje durduruldu ve YZ kışı geldi. Sonrasında odak, insanın yerini almak yerine uygun problemlere YZ uygulamaya ve insanı destekleyen programlara kaydı.

- **Kimine kolay kimine zor:** Formal tanımlı ve bütün durumlarına erişilebilen problemler (planlama, oyunlar) makine için kolaydır; satrançta 10-15 hamle ilerisini hesaplamak insan için zor, makine için yalnız zaman meselesidir. Buna karşılık `1 4 9 61 ?` dizisinde sonrakini bulmak insan için kolay, makine için zordur: sayılar 1, 2, 3, 4, 5'in karelerinin rakamları ters çevrilmiş halidir (16 → 61), sonraki 25 → **52**'dir (ekrandan, 02:05:00). Bongard problemlerinde sol ve sağ gruptaki şekilleri ayıran kuralı bulmak gerekir; her problem birbirinden çok farklı olduğu için makineler zorlanır. Resim anlamada bugünkü sistemler nesneleri, kişileri ve duruşları bulabilir, ama fotoğraftaki olayı (birinin tartıya ayağıyla bastırıp tartılan kişiyi daha ağır gösterdiği şakayı) anlatamaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
