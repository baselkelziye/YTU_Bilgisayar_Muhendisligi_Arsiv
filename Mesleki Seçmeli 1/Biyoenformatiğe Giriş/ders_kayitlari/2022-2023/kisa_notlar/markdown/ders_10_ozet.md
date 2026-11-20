# Ders 10 Çalışma Özeti

## Genel Konular

- Filogenetik ağaçların sınıflandırılması (tekrar)
  - Gen ağacı ve tür ağacı ayrımı: gen ağacı, tek bir homolog gen içinde gözlenen ayrışmaya (divergence) göre kurulur (ekrandan, 00:10:00).
  - Kullanılan veriye göre iki tür ağaç vardır: karakter verisi ve uzaklık verisi (ekrandan, 00:15:00).
    - Karakter: sınırlı sayıda farklı durumda bulunabilen, iyi tanımlanmış bir özellik.
    - Uzaklık: iki veri kümesi arasındaki genel, ikili (pairwise) farkın ölçüsü.
- Filogenetik ağaç kurma yöntemlerinin üç grubu
  - Uzaklık tabanlı yöntemler: diziler arasında ikili uzaklıklar hesaplanır, en benzer diziler gruplanır.
  - Karakter tabanlı yöntemler (maksimum parsimoni): farklı varlıklarda paylaşılan karakterlerin ortak atadan geldiği varsayılır; karakterlerin evrimi için en basit açıklama doğru (en tutumlu) kabul edilir.
  - Olasılıksal yöntemler (maksimum olabilirlik, maximum likelihood): belirli bir dizi evrimi modeli altında veri kümesinin, ondan türetilen ağaca uyma olasılığı hesaplanır.
- Yöntemlerin karşılaştırması (ekrandan, 00:20:00)

  ```text
  Uzaklık                     Maksimum parsimoni              Maksimum olabilirlik
  Yalnız ikili uzaklıklar     Yalnız paylaşılan türemiş       Bütün veri
                              karakterler
  En yakın komşular arası     Toplam uzaklığı enküçükler      Belirli parametrelerle ağaç
  uzaklığı enküçükler                                         olabilirliğini enbüyükler
  Çok hızlı                   Yavaş                           Çok yavaş
  Yerel optimuma kolay        Evrim hızlıysa varsayımlar      Varsayılan evrim modeline
  takılır                     bozulur                         çok bağımlı
  ```

  - Hoca, maksimum olabilirliğin çok küçük veri kümeleri ve başka yöntemlerle kurulmuş ağaçları test etmek için çok iyi olduğunu ekledi.
- Uzaklık tabanlı yöntemler
  - Dizi hizalamasından ikili uzaklıklar hesaplanır ve bir uzaklık (farklılık) matrisi kurulur. Ağaç, bu matrise bir kümeleme algoritması uygulanarak elde edilir.
  - Veri madenciliği ya da makine öğrenmesinde görülen herhangi bir kümeleme algoritması kullanılabilir; örnekler UPGMA ve komşu birleştirme (neighbor joining).
  - Örnekte uzaklık ölçüsü Hamming uzaklığıdır (iki dizide farklı olan konum sayısı). Boşluk içeren hizalamalarda Levenshtein uzaklığı, sayısala çevrilmiş dizilerde sayısal uzaklıklar kullanılabilir.
- UPGMA (Unweighted Pair-Group Method with Arithmetic mean) (ekrandan, 00:25:00)
  - En eski ve en basit uzaklık matrisi yöntemidir; kolay gerçeklenir ve kolay anlaşılır. 1960'ların başında morfolojik karakterlerin evrimsel analizi için önerildi.
  - En küçük uzaklıktaki iki tür tek bir bileşik grupta toplanır (ekrandan, 00:30:00). Sonra yeni grubun diğer türlere uzaklığı, grup üyelerinin uzaklıklarının ortalaması alınarak hesaplanır: $d_{(AB)C}=(d_{AC}+d_{BC})/2$. Adı bu aritmetik ortalamadan gelir.
  - Dallanma noktaları, birleştirilen türlerin tam ortasına konur (ilk grup için $d_{AB}/2$ gibi).
  - UPGMA dal uzunluklarını bu basit yolla kestirdiği için kendiliğinden köklü ağaç üretir.
- Dal uzunluklarının kestirimi
  - Dal uzunlukları, uzaklık matrisindeki bilgiyle hesaplanabilir (ekrandan, 00:45:00).
  - Evrim hızının bütün soy hatlarında aynı olduğu varsayılamazsa iş biraz karmaşıklaşır (ekrandan, 00:50:00).
  - Üç dizi için tek bir ağaç topolojisi vardır. Dal uzunlukları $a,b,c$ ise $a+b=d_{AB}$, $b+c=d_{BC}$, $a+c=d_{AC}$ olur. Buradan (ekrandan, 00:55:00):
    - $a=(d_{AB}+d_{AC}-d_{BC})/2$
    - $b=(d_{AB}+d_{BC}-d_{AC})/2$
    - $c=(d_{AC}+d_{BC}-d_{AB})/2$
- Komşuluk ilişkisi yöntemi (Neighbor's Relation Method)
  - Toplam dal uzunluğu en küçük olacak biçimde türleri eşleştirmeyi amaçlar. Köksüz bir ağaçta yalnız bir iç düğümle ayrılan tür çiftleri komşudur.
  - Toplanabilirlik (additivity) geçerliyse dört türlü ağaç için (ekrandan, 01:15:00): $d_{AC}+d_{BD}=d_{AD}+d_{BC}=a+b+c+d+2e=d_{AB}+d_{CD}+2e$. Burada $a,b,c,d$ uç dallar, $e$ tek merkez daldır.
  - Dört nokta koşulu: $d_{AB}+d_{CD}<d_{AC}+d_{BD}$ ve $d_{AB}+d_{CD}<d_{AD}+d_{BC}$.
  - Yöntem toplanabilirlikten sapmalara çok duyarlı değildir, ama toplanabilir olmayan veri yanlış topoloji üretebilir.
- Komşu birleştirme (neighbor joining)
  - Komşuluk yaklaşımının bir çeşididir; aglomeratif (birleştirici) bir tekniktir, ağacı yinelemeyle aşağıdan yukarı kurar (ekrandan, 01:25:00).
  - Bütün türlerin tek bir merkez düğümden çıktığı yıldız biçimli bir ağaçla başlanır; sonra ağacın toplam dal uzunluğunu enküçükleyen komşular sırayla bulunur. Girdi $n\times n$ bir farklılık (uzaklık) matrisidir.
- Karakter tabanlı yöntemler: maksimum parsimoni
  - Parsimoni (tutumluluk) kavramı bütün karakter tabanlı yöntemlerin merkezindedir (ekrandan, 01:30:00). "Parsimonious" parasını harcarken çok dikkatli olan kişidir; Türkçede "tutumlu".
  - Biyolojik anlamı: en az sayıda mutasyon olayı gerektiren evrimsel yolun tercih edilmesi.
  - Bilgi verici (informative) ve bilgi vermeyen konumlar: bütün dizilerde aynı karakter olan değişmez (invariant) konum, üç olası ağacın hepsinde aynı sayıda mutasyon gerektirdiği için bilgi vermez. Üç ağacın hepsinde eşit mutasyon gerektiren konumlar da bilgi vermez. Bir ağaçta 1, diğer ikisinde 2 mutasyon gerektiren konum bilgi vericidir.
  - Bilgi vermeyen konumlar atıldıktan sonra her olası ağaç her bilgi verici konum için ayrı ayrı değerlendirilir; her ağaç için gereken en az değişim sayısı toplanır. Toplamı en küçük olan ağaç en tutumlu ağaçtır.
  - Dört dizi için üç olası köksüz ağaç vardır: (1,2)(3,4), (1,3)(2,4), (1,4)(2,3).
- Maksimum olabilirlik (ekrandan, 01:45:00)
  - Maksimum parsimoni gibi bütün olası ağaçları üretir; ama en kısa evrim adımlı ağaçları tutmak yerine farklı geçiş/dönüşüm (transition/transversion) oranlarının kullanılabildiği bir evrim modeli kullanır.
  - Her ağaç için dizi verisinin her konumunu yansıtma olasılığı hesaplanır, hesap bütün nükleotit konumları için tekrarlanır. En iyi olasılıklı ağaç maksimum olabilirlik ağacıdır; genelde tek bir ağaç kalır.
  - Bütün dallar için eşit geçiş-dönüşüm oranı varsaymadığından daha gerçekçidir.
- Ağaç güvenilirliği
  - Her filogenetik ağaç, veriyi oluşturan dizilerin evrim tarihi hakkında bir hipotezdir. Ağacın tamamına ve parçalarına (dallarına) ne kadar güvenilebileceği sorulur.
  - Bootstrap: belirli bir filogenetik ağacın güven düzeyini kestiren hesaplamalı yöntemdir (ekrandan, 01:50:00). Yerine koyarak rastgele örneklemeye dayanır; yeniden örnekleme yöntemlerindendir. Bir kümenin desteği, yeniden örneklenmiş verilerden kurulan ağaçlardan o kümeyi içerenlerin oranıdır.
  - Parametrik test: en tutumlu ağacın bir alternatif ağaçtan ne kadar daha olası olduğu sorusu. Kishino ve Hasegawa testi, bilgi verici konumların bağımsız ve eşdeğer olduğunu varsayar; iki ağacın gerektirdiği değişim sayıları farkını ($D$) test istatistiği olarak kullanır ve $n-1$ serbestlik dereceli eşleştirilmiş t-testiyle iki ağacın farksız olduğu sıfır hipotezini test eder. <!-- BELİRSİZ: V(D) varyans formülü slaytta gösterildi, ilgili kare yok. -->
- Moleküler filogenetiğin uygulamaları ve hata kaynakları
  - RNA dizileriyle evrensel yaşam ağacı; Yellowstone'daki bir sıcak su kaynağından alınan kültürlenemeyen organizmaların ilişkisi; endosimbiyoz, yani mitokondri ve kloroplastın kökeni (ekrandan, 01:55:00). Ağaçta mitokondri α-mor bakterilerin, kloroplast siyanobakterilerin yanında yer alır.
  - Hata kaynakları: küçük veri kümesi ya da sınırlı örnekleme; duplikasyon, inversiyon, ekleme, silme gibi mutasyonların yanlış sinyal vermesi; kolay saptanamayan hızlı evrimleşen küçük bölgeler (genomik sıcak noktalar); homoplazi.
- İstatistik tekrarı: veri analizinin kategorileri (ekrandan, 02:15:00)
  - Anlatısal (hukuk, sanat), betimsel (sosyal bilimler), istatistiksel/matematiksel (temel ve uygulamalı bilimler), işitsel-optik (telekomünikasyon) ve diğerleri. Araştırma analizlerinin çoğu ilk üçünü kullanır.
  - İstatistik, nesne, olay ya da kişilerden oluşan bir örneklem hakkında anlamlı nicelikler üretir; biyoenformatikte yoğun kullanılır. Basitten karmaşığa korelasyon, ANOVA, MANOVA, regresyon, modelleme gibi konular vardır.
  - İki ana dal: betimsel ve çıkarımsal istatistik. Betimsel istatistik, örneklem bilgisini kullanarak ilişki, eğilim, neden-sonuç ilişkisi, trend, örüntü, dağılım ya da aralık gibi olguları açıklar.
- Hatalardan kaçınma ve analiz ilkeleri (ekrandan, 02:20:00)
  - Araştırma problemini netleştir (uygulanabilirliği), veri analizi tekniklerini oku, benzer işi yapan teknikleri karşılaştır, bir tekniğin ne yapıp ne yapmadığını bil, daha iyi bilenlere danış, pilot veriyle dene.
  - Analizin amaçları: neden-sonuç olgusunu açıklamak, araştırmayı gerçek olaylarla ilişkilendirmek, tahmin etmek, bir probleme cevap bulmak, sonuç çıkarmak, ders almak.
  - "Veri konuşmaz": analiz tanımlama, yorumlama, değerlendirme, açıklama, karşılaştırma gibi bilimsel akıl yürütme içerir. Analizin dört öğesi: veri, bilimsel akıl yürütme/argüman, bulgular, dersler ve sonuçlar.
  - Beklenen cevapları görselleştir, cevapları veriyle doğrula; veriyle desteklenmeyen bir şey söyleme (nesnellik).
- Örneklem, anakütle ve veri türleri
  - İstatistik, anakütlenin temsilci bir örnekleminden gözlenen veriyle anakütle hakkında ifadeler üretir.
  - Parametre: anakütlenin bir özelliğini betimleyen sayısal değer (ekrandan, 02:25:00). İstatistik (statistic): örneklemin bir özelliğini betimleyen sayısal ölçüm. İstatistikle parametre hakkında çıkarım yapılır.
  - Veri keşfi (data exploration): örnekleme sonrası çıkarım ve karar öncesi adımdır. Veri azaltma ile anahtar özelliklere odaklanılır; özet istatistikler kullanılır; bir değişkenin dağılımı öğrenilir; önceden bilinmeyen örüntüler bulunabilir.
  - İstatistiksel çıkarım: örneklem kullanıldığı için kestirimlerde hata biçiminde belirsizlik vardır; belirsizliği ele almanın matematiksel aracı olasılıktır (ekrandan, 02:30:00).
  - Toplanan veri türü, kullanılacak analizi, test edilebilecek hipotezleri ve tahmin modelini belirler. İki ana tür: kategorik ve niceliksel.
    - Kategorik veri etiket ya da kategorilerdir (cinsiyet gibi). Sırası yoksa nominal, sıralanabiliyorsa (ağrı düzeyi gibi) ordinaldir. DNA ve amino asit dizileri kategorik ve nominaldir; analize göre sayısal ya da ordinal veriye çevrilebilir.
    - Niceliksel veri, sayıların bir ölçeğe bağlı olduğu ölçümlerdir (ekrandan, 02:35:00). Sayım verisi kesikli, uzunluk, hacim, kütle gibi gerçek sayılar süreklidir. Niceliksel veri genelde ortalamalarla özetlenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Amaç bütün kümeleme yöntemlerini öğretmek değil, kümeleme yaklaşımıyla filogenetik ağacın nasıl kurulacağını göstermektir.
  - Herhangi bir kümeleme algoritması uzaklık matrisinden ağaç kurmak için kullanılabilir.
- UPGMA basit ve anlaşılırdır: basit bir uzaklık matrisiyle başlanır, basit bir kümeleme uygulanır.
  - Köklü ağaç istenirse UPGMA yaklaşımı, köksüz ağaç istenirse dal uzunluklarını kestiren yaklaşım kullanılır.
- Üç dizi için dal uzunluklarının formülü "basit geometri"dir: $d_{AB}+d_{AC}-d_{BC}=(a+b)+(a+c)-(b+c)=2a$.
- İstatistik biyoenformatikte yoğun kullanılır; analizde nesnel, doğru ve dürüst olunmalı, veriyle desteklenmeyen bir şey söylenmemelidir.

## Kısa Tekrar Notları

- Üç yöntem grubu: uzaklık tabanlı (hızlı, yerel optimuma takılabilir), maksimum parsimoni (yavaş, hızlı evrimde varsayımı bozulur), maksimum olabilirlik (çok yavaş, evrim modeline bağımlı).
- UPGMA: en küçük uzaklıktaki çifti birleştir, yeni grubun uzaklığını ortalamayla hesapla, dallanma noktasını uzaklığın yarısına koy; köklü ağaç verir.
- Beş dizili örnekte ilk birleşen çift D ve E'dir ($d_{DE}=5$, dallar 2.5); sonra A ve C ($d_{AC}=8$, dallar 4) (ekrandan, 00:35:00 ve 00:45:00).
- Üç dizi: $a=(d_{AB}+d_{AC}-d_{BC})/2$ ve benzerleri. Örnekte $a=10$, $b=12$, $c=29$ (ekrandan, 01:00:00).
- Toplanabilir dört türlü ağaç: $d_{AC}+d_{BD}=d_{AD}+d_{BC}=d_{AB}+d_{CD}+2e$.
- Komşu birleştirme: yıldız ağaçla başla, toplam dal uzunluğunu enküçükleyen komşuları sırayla birleştir.
- Parsimoni: en az mutasyon gerektiren ağaç seçilir. Değişmez konumlar ve her ağaçta eşit mutasyon gerektiren konumlar bilgi vermez.
- Maksimum olabilirlik: farklı geçiş/dönüşüm oranlarına izin veren evrim modeliyle en olası ağaç.
- Bootstrap: yerine koyarak yeniden örnekleme; bir kümenin desteği, onu içeren ağaçların oranıdır.
- Parametre anakütleyi, istatistik örneklemi betimler. Belirsizliğin aracı olasılıktır.
- DNA ve protein dizileri kategorik, nominal veridir.

## Detaylı Açıklamalar

- UPGMA örneği (ekrandan, 00:35:00)
  - Beş DNA dizisi (A–E), her biri 50 nükleotit, hizalanmış hâlde verildi. Uzaklık, aynı konumda farklı olan harf sayısıdır. İkili uzaklık matrisi:

    ```text
         A    B    C    D
    B    9    -    -    -
    C    8   11    -    -
    D   12   15   10    -
    E   15   18   13    5
    ```

  - En küçük değer $d_{DE}=5$ olduğu için önce D ve E birleşir. Yeni (DE) satırı ortalamalarla hesaplanır (ekrandan, 00:40:00): $d_{(DE)A}=(12+15)/2=13.5$, $d_{(DE)B}=(15+18)/2=16.5$, $d_{(DE)C}=(10+13)/2=11.5$.
  - İndirgenmiş matriste en küçük değer 8'dir, bu yüzden ikinci grup AC olur.
  - Dal uzunlukları (ekrandan, 00:45:00): D ve E ortak atalarına $d_{DE}/2=2.5$, A ve C $d_{AC}/2=4$ birim uzunluğunda dallarla bağlanır; (AC) ile (DE) arasındaki dallanma noktası slaytta $d_{(AC)(DE)}/2=6.25$ olarak verilir.
  - Ders sonrası not: diziler slayttan alınıp Python ile yeniden sayıldı, matrisin bütün değerleri doğrulandı. İkinci adımdan sonra $d_{(AC)B}=(9+11)/2=10$, $d_{(AC)(DE)}=(13.5+11.5)/2=12.5$ olur. En küçük değer 10 olduğu için standart UPGMA'da üçüncü adımda B, (AC) grubuna katılır, (DE) en son birleşir. 6.25 değeri $12.5/2$ hesabına karşılık gelir. <!-- BELİRSİZ: hocanın 00:41 civarındaki birleştirme sırası anlatımı altyazıda bozuk; üçüncü adımın slaytı karede yok. -->
- Üç dizide dal uzunluğu örneği (ekrandan, 01:00:00)
  - Slaytta $a+b=22$ ve (4) numaralı denklemle $b-a=2$ toplanarak $2b=24$, $b=12$ bulunur; $a=22-12=10$; $a+c=39$ olduğundan $c=29$.
  - Bu, $d_{AB}=22$, $d_{AC}=39$ ve $d_{BC}=b+c=41$ demektir; formülle de $a=(22+39-41)/2=10$, $b=(22+41-39)/2=12$, $c=(39+41-22)/2=29$ çıkar. <!-- BELİRSİZ: uzaklık matrisinin yer aldığı önceki slayt karede yok; $d_{BC}=41$ sonuçtan geriye hesaplandı. -->
- Komşuluk ilişkisi yöntemi örneği (ekrandan, 01:20:00)
  - Dört dizi: A `ACGCGTTGGGCGATGGCAAC`, B `ACGCGTTGGGCGACGGTAAT`, C `ACGCATTGAATGATGATAAT`, D `ACACATTGAGTGATAATAAT`.
  - Uzaklıklar: $d_{AB}=3$, $d_{AC}=7$, $d_{AD}=8$, $d_{BC}=6$, $d_{BD}=7$, $d_{CD}=3$ (Python ile doğrulandı).
  - Hocanın sözlü kontrolüne göre dal uzunlukları $a=2$, $b=1$, $c=1$, $d=2$, $e=4$ ile bütün uzaklıklar tutar: $2+1=3$, $2+4+1=7$, $2+4+2=8$, $1+4+1=6$, $1+4+2=7$, $1+2=3$ (derste sözlü, 01:23:29).
  - Dört nokta koşulu da sağlanır: $d_{AB}+d_{CD}=6<d_{AC}+d_{BD}=d_{AD}+d_{BC}=14$, ve $14=6+2\cdot4$.
- Maksimum parsimoni örneği (ekrandan, 01:40:00)
  - Dört dizi AAG, AAA, GGA, AGA. Sol ağaçta (AAG, AAA) ve (GGA, AGA) gruplanır; iç düğümler AAA, AAA, AGA ile toplam 3 değişim gerekir. Sağ ağaçta (AAG, AGA) ve (AAA, GGA) gruplanır; toplam 4 değişim gerekir. Sol ağaç daha tutumlu olduğu için tercih edilir. Fitch algoritmasıyla yapılan kontrol aynı sonucu verdi (3. ağaç da 4).
  - Derste ayrıca dört kısa diziyle üç ağacın değişim sayıları karşılaştırıldı: ilk ağaç 6, diğer ikisi 7 değişim gerektirdi; en az değişimli ağaç seçildi. <!-- BELİRSİZ: dizilerin harfleri altyazıda bozuk geçiyor, slayt karede yok. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
