# Ders 7 Çalışma Özeti

## Genel Konular

- Çoklu dizi hizalamada dinamik programlama (doğrudan yöntem)
  - Çoklu hizalamanın kesin (exact) yöntemleri dinamik programlama kullanır ve en iyi (optimal) çözümü bulmayı garanti eder (ekrandan, 00:10:00).
  - Üç dizi için iki boyutlu matris yerine üç boyutlu bir küp doldurulur. Örnek diziler: VSNS, SNA, AS (ekrandan, 00:15:00). Küpteki yol şu hizalamayı verir (ekrandan, 00:20:00):

    ```text
    V S N - S
    - S N A -
    - - - A S
    ```

  - Küpteki her adımda olasılıklar: üç dizi birden eşleşir; iki dizi eşleşir ve üçüncüde boşluk olur (üç farklı durum); bir dizide harf, öteki ikisinde boşluk olur.
  - $k$ dizi ve dizi uzunluğu $n$ için doldurulacak hücre sayısı $n^k$ olur; karmaşıklık üstel artar (ekrandan, 00:25:00). Bu yüzden yöntem az sayıda kısa dizi için bile hızla kullanılamaz hâle gelir.
  - Uzunluğu 300 olan iki protein için yaklaşık $9\times10^4$, üç protein için $2.7\times10^7$ karşılaştırma gerekir.
- Arama uzayını ve zamanı küçültme
  - Sınırlı kaynaklı bir bilgisayarda boyut arttıkça bellek hızla tükenir, işlem gücü yetersiz kalır. Çözüm, arama uzayını sınırlamaktır (sınırlı dinamik programlamadaki fikir).
  - Carrillo ve Lipman (1988): çoklu hizalama uzayı ikili hizalamalarla sınırlandırılır; bu hizalamaların izdüşümleri sınırlı bir hizalama bölgesi verir (ekrandan, 00:30:00).
  - Fikir: çoklu hizalama her dizi çiftine bir ikili hizalama dayatır. Çiftler için bulunan hizalamalar, çoklu hizalamanın küp (ya da $k$ boyutlu uzay) içindeki yerine sınır koyar. Adımlar: ikili hizalamaları bul; dizilerin filogenetik ağacını kestirerek deneme hizalaması üret; dizileri ağaçtaki ilişki sırasına göre çoklu hizala (ekrandan, 00:35:00).
  - MSA programı genişletilmiş dinamik programlama kullanır; en iyi hizalama en iyi "çiftler toplamı" (sum of pairs) skoruna göre seçilir. <!-- BELİRSİZ: programı geliştirenler altyazıda "NUTMAN89" diye bozuk geçiyor; büyük olasılıkla Lipman ve arkadaşları (1989). -->
- Çiftler toplamı (sum of pairs, SP) yöntemi
  - Bir hizalama sütunundaki bütün kalıntı çiftleri skorlanıp toplanır (ekrandan, 00:40:00).
  - Dört dizide çift sayısı $\binom{4}{2}=6$'dır: 1-2, 1-3, 1-4, 2-3, 2-4, 3-4.
  - Örnek hizalama ECSQ, SNSG, SWKN, SCSN; skorlar PAM250 matrisinden alınır (ekrandan, 00:45:00 ve 00:50:00). 1-2 çifti: E/S 0, C/N −4, S/S 2, Q/G −1, toplam −3.
  - Sakınca: birbirine çok yakın diziler skora fazla ağırlık katar. Bunu dengelemek için dizi çiftlerine ağırlık verilir; ağırlıklar kestirilen filogenetik ağaçtan hesaplanır.
  - Özet akış: bütün ikili hizalama skorlarını hesapla, skorlardan ağaç kestir, ağaçtan çift ağırlıklarını hesapla, ağaca göre sezgisel bir çoklu hizalama üret.
- İlerlemeli (progressive) çoklu hizalama
  - En çok benzeyen dizilerin hizalamasıyla başlanır, sonra daha az ilişkili diziler adım adım bu hizalamaya eklenir (ekrandan, 00:55:00). Sıra, üretilen kılavuz ağaca göre belirlenir (ekrandan, 01:00:00).
  - Sezgisel olduğu için en iyi sonucu garanti etmez.
  - CLUSTAL adı UPGMA ile yapılan kümeleme (CLUSTer) ve ikili hizalamalardan (ALignment) gelir. CLUSTALW'da W ağırlıklı (weighted), CLUSTALX'te X, Unix'in grafik arayüzü X Window demektir. UPGMA: unweighted pair group method with arithmetic mean (ekrandan, 01:05:00).
  - Adımlar: bütün dizilerin ikili hizalamaları; hizalama skorlarından filogenetik ağaç; ağaca göre sırayla hizalama.
  - Ağırlık örneği: A dalı 0.2, B dalı 0.1, A ile B'nin ortak dalı 0.3, C dalı 0.5. Ortak dal iki diziye paylaştırılır: A için $0.2+0.3/2=0.35$, B için $0.1+0.3/2=0.25$, C için $0.5$ (ekrandan, 01:10:00).
  - İki sütunun eşleşme skoru, ağırlıklar çarpılarak bulunur: $[a\cdot c\cdot s(K,L)+a\cdot d\cdot s(K,V)+b\cdot c\cdot s(I,L)+b\cdot d\cdot s(I,V)]/4$ (ekrandan, 01:10:00).
  - PILEUP: GCG paketinde, CLUSTALW'a çok benzer bir ilerlemeli yöntem; sonunda dizi benzerliklerinin küme dendrogramını çizer. Bu dendrogram evrimsel ağaç değildir (ekrandan, 01:15:00).
  - Zayıf yanı: sonuç ilk ikili hizalamalara bağlıdır; diziler benzer değilse ilk hatalar sonraki adımlara yayılır.
- Yinelemeli (iterative) yöntemler
  - Bir başlangıç hizalaması yapılır, sonra skor iyileşecek biçimde tekrar tekrar düzeltilir. Skor artık değişmeyince ya da değişim belirlenen eşiğin altına inince durulur (ekrandan, 01:40:00).
  - Grupların seçimi filogenetik ağaca dayanır. Programlar: MultAlin, PRRP ve DIALIGN.
  - MultAlin'de ikili skorlar ilerlemeli hizalama sırasında yeniden hesaplanır, ağaç da yeniden kurulur.
  - PRRP döngüsü: başlangıç hizalaması → filogenetik ağaç → dizi çiftlerine ağırlıklar $w_{i,j}$ → ağırlıklı çiftler toplamı $WSP=\sum_{i<j} w_{i,j}\,S_{i,j}$ ile yinelemeli iyileştirme → yakınsadıysa dur, yakınsamadıysa ağaca dön (ekrandan, 01:45:00).
  - DIALIGN'da hizalamayı ağırlıklı köşegenlerin bir derlemesi oluşturur.
- Optimizasyon yaklaşımları
  - Genetik algoritma: başlangıç hizalamaları dizilerin uçlarına boşluk eklenerek üretilir ve SP yöntemiyle (standart amino asit skor matrisleri, boşluk açma ve uzatma cezalarıyla) skorlanır. Hizalamaların yarısı skorlarına göre seçilip değişmeden yeni nesle geçer (doğal seçilim); öteki yarısı mutasyona uğrar: rastgele uzunlukta boşluklar rastgele konumlara eklenir (ekrandan, 01:50:00).
  - Benzetilmiş tavlama (simulated annealing): sezgisel bir hizalamadan başlar, skoru artıran değişiklikleri olasılıksal modelle bulur. Sakıncası yerel en iyiye takılabilmesidir (ekrandan, 01:55:00).
- Grup ve ağaç yaklaşımları, profil analizi
  - Grup yaklaşımında benzer diziler gruplara ayrılıp grup içinde hizalanır, her grubun uzlaşı (consensus) dizisi çıkarılır, sonra gruplar arasında hizalama yapılır.
  - Ağaç yaklaşımında en yakın iki dizi hizalanır, sonra sıradaki en iyi dizi ya da grup eklenir. Tree align algoritması diziler eklendikçe ağacı en tutumlu (maximum parsimony) ağaç olacak biçimde yeniden düzenler.
  - Profil analizinde önce çoklu hizalama yapılır, korunmuş bölgeler seçilir ve bilgi bir matriste tutulur: hizalamadaki her konum için bir satır, her kalıntı için bir sütun, ayrıca boşluk açma ve uzatma değerleri.
  - Tipik görevler için öneriler: 2-100 protein dizisi (en çok yaklaşık 10 000 kalıntı) için ProbCons, T-Coffee ve MAFFT ya da MUSCLE; 100-500 dizi için MUSCLE ya da MAFFT betikleri (ekrandan, 02:10:00). Daha çok dizi için MUSCLE ve MAFFT'nin hızlı sürümleri anıldı.
- Lokal çoklu dizi hizalama
  - Global çoklu hizalamada aynı atadan geldiği düşünülen türlerin dizileri bütün uzunluklarıyla hizalanır. Bazen yalnız belirli (korunmuş) bölgeler ilgilendirir.
  - Örnek: bir genin yukarı akışında (upstream) transkripsiyon faktörlerinin DNA'ya bağlandığı bölgeler; farklı organizmalarda bir gen ailesinin bu bölgelerindeki sinyali aramak için bütün genomik DNA'yı değil yalnız korunmuş bölgeyi hizalamak gerekir. Proteinlerde lokal hizalama, başka bakımdan ilişkisiz proteinlerde ortak alanlar (domain) hakkında bilgi verir.
  - Profil analizi (ekrandan, 02:20:00): diziler çoklu hizalanır, en çok korunmuş bölgeler belirlenir, hizalama bir skor matrisiyle tanımlanır. Profil, eğitim kümesindeki çeşitlilik kadar temsil edicidir; eğitim kümesine doğru bir yanlılık taşır.
  - Profil matrisinin her hücresi log-odds skorudur: belirli bir konumda belirli bir kalıntıyı bulma olasılığının, iki amino asidin rastgele hizalanma olasılığına oranı; PAM250, BLOSUM80 gibi bir skor şeması kullanılır. Boşluk açma ve uzatma cezaları da hesaplanmalıdır (ekrandan, 02:25:00).
- Entropi
  - Termodinamik ve bilgi kuramından gelen, bir sistemdeki düzensizlik ya da rastgeleliğin ölçüsüdür (Claude Shannon).
  - Bir sütunun entropisi: $H=-\sum_{a} f_a \log(p_a)$; $a$ kalıntı, $f_a$ kalıntının sütundaki frekansı, $p_a$ o sütunda beklenen frekansı (ekrandan, 02:30:00). Entropi düşükse sütun korunmuş, yüksekse çeşitlidir; korunmuş bölgeleri bulmak için iyi bir ölçüdür.
  - Amino asit dizisi niteliksel (qualitative) veridir; frekanslar hesaplanarak niceliğe çevrilir.
  - $H$, 20 olası ata amino asit ve birçok evrimsel uzaklık için PAM matrisleriyle hesaplanır; her sütun-ata birleşimi için $H$'yi en küçük yapan uzaklık en iyi kestirimdir. Bu, 20 olası model verir; modellerin olasılıklarından ağırlıklar hesaplanır.
  - Log-odds skoru, gözlenen frekansın arka plan frekansına oranının 2 tabanlı logaritmasıdır. <!-- BELİRSİZ: profilin log-odds formülü (Profile_ij) karede görünmüyor; altyazıda yalnız terimler okunuyor. -->

## Hocanın Özellikle Vurguladığı Kısımlar

- Çoklu hizalamada en iyi sonuç garanti edilemez
  - İkili hizalamada skor şeması verilince dinamik programlama kesin olarak en iyi hizalamayı bulur. Çoklu hizalamada doğrudan yöntem pratikte kullanılamadığından dinamik programlama, filogenetik ağaç ve sezgisel adımlar birleştirilir; sonuç en iyi olabilir ama bu garanti edilemez.
- Karmaşıklık üstel artar
  - Dizi sayısı arttıkça hücre sayısı $n^k$ olur; bellek ve işlem gücü yetmez. Bu yüzden arama uzayı sınırlandırılır.
- Filogenetik ağaç ve ikili hizalama her yerde
  - Hemen bütün çoklu hizalama yöntemleri ikili dinamik programlama hizalamasını ve filogenetik ağacı kullanır. Ağacın nasıl kurulduğu sonraki derslerde anlatılacak.
- Biyoenformatik çok disiplinlidir
  - Kombinasyon sayısı, entropi, veri türleri gibi istatistik, matematik ve bilgi kuramı kavramları sürekli kullanılır.

## Kısa Tekrar Notları

- Kesin (exact) çoklu hizalama = dinamik programlama; 3 dizi için küp, $k$ dizi için $n^k$ hücre.
- 300 uzunlukta 2 protein: $9\times10^4$; 3 protein: $2.7\times10^7$ karşılaştırma.
- Carrillo-Lipman: ikili hizalamalar çoklu hizalama uzayını sınırlar.
- SP yöntemi: sütundaki bütün çiftlerin skor toplamı; $k$ dizide $\binom{k}{2}$ çift.
- Yakın dizilerin baskınlığı ağaçtan hesaplanan ağırlıklarla dengelenir.
- İlerlemeli: en benzer çiftle başla, ağaç sırasıyla ekle (CLUSTALW, CLUSTALX, PILEUP). Hata ilk adımlardan yayılır.
- CLUSTAL = CLUSTer + ALignment; W = weighted, X = X Window; UPGMA ile kılavuz ağaç.
- Ağırlık: kendi dalı + paylaşılan dalın paylaşan dizi sayısına bölümü.
- Yinelemeli: MultAlin, PRRP ($WSP=\sum w_{i,j}S_{i,j}$), DIALIGN; skor değişmeyince dur.
- Genetik algoritma: yarısı seçilip geçer, yarısı boşluk mutasyonuna uğrar. Benzetilmiş tavlama yerel en iyiye takılabilir.
- Lokal çoklu hizalama: korunmuş bölgeler, profil analizi, log-odds hücreleri, entropi $H=-\sum f_a\log p_a$.

## Detaylı Açıklamalar

- Ders, ikili dizi hizalamada kullanılan dinamik programlamanın ikiden çok diziye genişletilmesi sorusuyla başladı. İki dizide iki boyutlu bir matris doldurulur; üç dizide boyut sayısı dizi sayısı kadar olur ve bir küp doldurmak gerekir. Hoca bunu sinyal sınıflandırmasıyla örnekledi: zaman serisi tek boyutlu, resim iki boyutlu, zamanla değişen görüntü üç boyutlu bir sinyaldir. VSNS, SNA ve AS dizilerinin küpteki en iyi yolu `VSN-S / -SNA- / ---AS` hizalamasını verir (ekrandan, 00:20:00). Uzunlukları eşit $k$ dizi için doldurulacak hücre sayısı $n^k$'dir; $n=10$ için iki dizide 100 hücre gerekirken dizi sayısı arttıkça sayı üstel büyür. Gerçek diziler çok daha uzun olduğundan doğrudan yöntem pratik değildir.
- Kaynak sorunu bellek ve işlem gücüdür. Çözüm, sınırlı dinamik programlamada olduğu gibi bütün hücreleri değil, belirli koşullara göre seçilen hücreleri hesaplamaktır. Carrillo ve Lipman, çoklu hizalamanın her çifte bir ikili hizalama dayattığı gözleminden yola çıkarak ikili hizalamaların izdüşümleriyle çoklu hizalamanın yerini sınırlamıştır. Hoca algoritmanın gerçeklenmesine girmedi, literatürdeki kaynakları gösterdi.
- Çiftler toplamı yönteminde bir sütundaki bütün kalıntı çiftleri bir skor matrisiyle (örnekte PAM250) skorlanır ve toplanır. Dört dizide 6 çift vardır; sayı $\frac{4!}{2!\,2!}=6$ formülüyle bulunur. Çok sayıda dizide çiftleri tek tek saymak pratik olmadığından genel formül kullanılır. Birbirine yakın dizilerin skoru fazla etkilemesi, filogenetik ağaçtan hesaplanan ağırlıklarla dengelenir.
- İlerlemeli yöntemlerde kılavuz ağaca göre en yakın diziler önce hizalanır. CLUSTALW'da ağırlık, dizinin kökten uzaklığına göre hesaplanır: dizinin kendi dal uzunluğuna, paylaşılan dalların uzunluğunun o dalı paylaşan dizi sayısına bölümü eklenir. Ağırlıklar iki hizalama sütununun eşleşme skorunda çarpan olarak kullanılır. CLUSTALW boşlukları istatistiksel bir modelle en olası yerlere koymaya çalışır. CLUSTALW'ın European Bioinformatics Institute tarafından sunulan programın bir çıktısı da gösterildi.
- Yinelemeli yöntemler başlangıç hizalamasını adım adım iyileştirir. PRRP'nin akış şemasında ağaç, ağırlıklar ve ağırlıklı SP skoru her turda yeniden hesaplanır ve yakınsama denetlenir. Optimizasyon yaklaşımları (genetik algoritma, benzetilmiş tavlama) da aynı amaca, hizalama skorunu artırmaya yöneliktir ama en iyi sonucu garanti etmez; hoca benzetilmiş tavlamada bulunan yerel en iyinin genel en iyi sanılmasının yanlış yorum olacağını belirtti.
- Lokal çoklu hizalamada yalnız ilgilenilen korunmuş bölgeler hizalanır. Profil analizinde korunmuş bölgelerden bir skor matrisi (profil) çıkarılır; hücreler log-odds skorudur. Entropi, bir sütunun ne kadar çeşitli olduğunu ölçerek korunmuş bölgeleri belirlemeye yarar: niteliksel olan harf verisi, frekanslar üzerinden niceliksel bir ölçüye dönüştürülür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
