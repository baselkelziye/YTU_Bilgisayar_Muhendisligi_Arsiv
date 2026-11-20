# Ders 7 Genişletilmiş Notu: Çoklu Dizi Hizalama Yöntemleri ve Lokal Çoklu Hizalamaya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Çoklu Hizalamada Dinamik Programlama
- 2. Arama Uzayını ve Zamanı Küçültme
- 3. Çiftler Toplamı Yöntemi
- 4. İlerlemeli Çoklu Hizalama
- 5. Yinelemeli Yöntemler
- 6. Optimizasyon Yaklaşımları
- 7. Grup ve Ağaç Yaklaşımları, Profil Analizi ve Program Seçimi
- 8. Lokal Çoklu Dizi Hizalama
- 9. Profillerin Hesaplanması ve Entropi
- Örnek Sorular
- Dersin Toparlaması

## 1. Çoklu Hizalamada Dinamik Programlama

### 1.1 İkili hizalamadan çoklu hizalamaya

Önceki derste çoklu dizi hizalamaya (multiple sequence alignment, MSA) birkaç farklı yaklaşım olduğu söylenmişti. Bu yaklaşımların hepsinin temelinde ayrıntılı işlenen ikili dizi hizalama (pairwise sequence alignment) vardır. İki dizi için dinamik programlama görece kolaydır ve kodlanması da kolaydır: matrisler doldurulur, ardından geri izleme yapılır. Bu derste sorulan soru şudur: aynı yaklaşım ikiden çok diziye (üç, dört, beş ve daha fazla) genişletilirse ne olur?

Slayttaki ilk tespit, çoklu hizalamanın kesin (exact) yöntemlerinin dinamik programlama kullandığı ve bu yöntemlerin en iyi (optimal) çözümü bulmayı garanti ettiğidir (ekrandan, 00:10:00).

### 1.2 Üç dizi için küp

En basit durum olarak üç dizinin hizalanması ele alındı. Örnek amino asit dizileri şunlardır (ekrandan, 00:15:00):

```text
VSNS
SNA
AS
```

İki dizide iki boyutlu bir matris doldurulurken üç dizide kaç boyut gerektiği soruldu. Hoca öğrencileri sinyal sınıflandırmasıyla düşündürdü: zaman serisi tek boyutlu bir sinyaldir, resim iki boyutludur (x ve y), zamanla değişen bir görüntüde zaman üçüncü boyut olur. Aynı mantıkla üç dizi üç boyut, yani doldurulacak bir küp demektir. Diziler x, y ve z eksenlerine yerleştirilir.

Küpte her adımda şu olasılıklar vardır:

- Üç dizinin harfleri birlikte hizalanır.
- A ile B eşleşir, C'de boşluk olur.
- A ile C eşleşir, B'de boşluk olur.
- B ile C eşleşir, A'da boşluk olur.
- A'da harf, B ve C'de boşluk olur.
- B'de harf, A ve C'de boşluk olur.
- C'de harf, A ve B'de boşluk olur. (ara adım eklendi: hoca listeyi B'ye kadar okudu, simetrik yedinci durum eklendi)

Küpteki "Start" köşesinden başlayan kırmızı yol şu hizalamayı verir (ekrandan, 00:20:00):

```text
V S N - S
- S N A -
- - - A S
```

### 1.3 $k$ dizi için karmaşıklık

Bu çok kısa diziler için mümkündür, ama hesaplama karmaşıklığı üstel artar. Gerçek dizilerde karakter sayısı çok daha büyüktür; veri dizisi (array) açısından bakılırsa diziler devasa olur. Dizilerin uzunluklarının eşit ve $n$ olduğu varsayılırsa iki dizi için $n^2$ hücre doldurulur; $n=10$ için bu $10^2=100$ hücre eder. Dizi sayısı arttıkça sayı 1000, 10 000 diye büyür. Genel olarak $k$ dizi için gereken karşılaştırma sayısı

$$n^k$$

olur; burada $n$ dizilerin uzunluğu, $k$ dizi sayısıdır (ekrandan, 00:25:00). Slaytın sonucu: dinamik programlama yaklaşımında hiçbir değişiklik yapılmazsa, bu yöntem az sayıda kısa dizi için bile hızla kullanılamaz hâle gelir. Değişiklik yapılmamış bu dinamik programlamaya doğrudan yöntem (direct method) denir.

Hoca sayısal bir örnek de verdi: boşluklar hariç 300 uzunluğunda iki protein dizisi için dinamik programlamayla yapılacak karşılaştırma sayısı $300^2 = 9\times10^4$, üç protein için $300^3 = 2.7\times10^7$'dir. Bu konuda çoklu dizi hizalamanın karmaşıklığı üzerine bir makale de kaynak olarak gösterildi.

## 2. Arama Uzayını ve Zamanı Küçültme

### 2.1 Kaynak sorunu

Hoca, karmaşıklık arttığında bir hesaplama ortamında hangi sorunla karşılaşıldığını sordu. Cevap: bellek hızla tükenir ve boyutlar arttıkça işlem gücü yetersiz kalır. Kaynaklar sınırlıysa çözüm, önceki derste anlatılan sınırlı (bounded) dinamik programlamada olduğu gibi arama uzayını sınırlamaktır. Bütün matris hücreleri hesaplanmaz; belirli koşullara göre bazı hücreler göz ardı edilip bazılarına yoğunlaşılır. Böylece bellek alanı ve hesaplama süresi azalır.

### 2.2 Carrillo ve Lipman yöntemi

Carrillo ve Lipman'ın önerdiği yöntemde çoklu dizi hizalama uzayı ikili hizalamalarla sınırlandırılır. Bu ikili hizalamaların izdüşümleri sınırlı bir hizalama bölgesi verir (ekrandan, 00:30:00). Slayttaki kaynak: Carrillo H, Lipman DJ (1988). "The Multiple Sequence Alignment Problem in Biology". SIAM Journal on Applied Mathematics 48(5): 1073–1082. Hoca algoritmanın nasıl gerçeklendiğine girmedi; literatürde kaynaklar olduğunu söyledi.

Bellek ve hesaplamayı azaltma fikri şöyle özetlendi (ekrandan, 00:35:00): çoklu dizi hizalama, dizi çiftlerinin her birine bir hizalama dayatır. Her çift için bulunan hizalamalar, çoklu hizalamanın küp (üç dizi) ya da $k$ boyutlu uzay ($k$ dizi) içindeki yerine sınır koyabilir. Adımlar:

1. Diziler için ikili hizalamaları bul.
2. Diziler için bir filogenetik ağaç kestirerek deneme çoklu hizalaması üret.
3. Dizileri ağaçtaki ilişkilerinin sırasına göre çoklu hizala.

Ağaçta bazı diziler birbirine ötekilerden daha yakındır; hizalama sırası bu ilişkiye göre belirlenir. Filogenetik ağacın nasıl kurulduğu sonraki derslerde anlatılacak. Bu yolla bulunan hizalama temel (doğrudan) yöntemdeki gibi en iyi hizalama değildir; bu algoritmalarla bulunan hizalamaların en iyi olması garanti edilmez.

### 2.3 MSA programı

MSA adlı çoklu hizalama programı genişletilmiş dinamik programlama kullanır. <!-- BELİRSİZ: programı geliştirenler altyazıda "NUTMAN89" diye bozuk geçiyor; büyük olasılıkla Lipman ve arkadaşları (1989). Slayt karesi yok. --> Önce $k$ dizinin her ikisi arasında ikili hizalamalar yapılır, bunlardan skorlar üretilir ve bu skorlar algoritmada kullanılır. Bu durumda en iyi hizalama, en iyi çiftler toplamı (sum of pairs) skoruna göre belirlenir.

## 3. Çiftler Toplamı Yöntemi

### 3.1 Tanım

Çoklu dizi hizalamada çiftler toplamı (sum of pairs, SP) kullanılır: her sütundaki ikili hizalama skorları toplanır. Birbirine yakın dizilerin etkisini azaltmak için sütunlar ağırlıklandırılabilir. Slayttaki tanım: çiftler toplamı yöntemi, bir çoklu dizi hizalamasının bir sütunundaki kalıntı çiftlerinin bütün olası birleşimlerini skorlar (ekrandan, 00:40:00).

### 3.2 Örnek hizalama ve çift sayısı

Slayttaki örnek dört diziden oluşan şu hizalamadır (ekrandan, 00:45:00):

```text
E C S Q   (1)
S N S G   (2)
S W K N   (3)
S C S N   (4)
```

Hoca kaç ikili karşılaştırma yapılması gerektiğini sordu. Bir öğrenci dört diziden çift oluşturulacağını, bunun $4\cdot3/2$ olduğunu söyledi; hoca doğruladı. Bu, 4 farklı nesneden 2'sini seçme sayısıdır:

$$\binom{4}{2}=\frac{4!}{(4-2)!\,2!}=\frac{24}{2\cdot2}=6$$

Çiftler tek tek de sayılabilir: 1-2, 1-3, 1-4, 2-3, 2-4, 3-4. Dizi sayısı ve uzunluk arttıkça bunları tek tek saymak pratik olmaz, bu yüzden genel formül kullanılır. Hoca bu küçük aradan sonra, biyoenformatiğin çok disiplinli olduğunu ve istatistik, matematik, algoritma gibi başka alanların kavramlarının sürekli kullanıldığını vurguladı.

### 3.3 PAM250 ile skorlama

Her ikili hizalama PAM250 matrisiyle skorlanır (ekrandan, 00:50:00). Derste 1-2 çifti adım adım hesaplandı:

| Konum | Dizi 1 | Dizi 2 | PAM250 skoru |
|---|---|---|---|
| 1 | E | S | 0 |
| 2 | C | N | −4 |
| 3 | S | S | 2 |
| 4 | Q | G | −1 |
| Toplam | | | −3 |

Öteki çiftler (1-3, 1-4, 2-3, 2-4, 3-4) için de aynı yol izlenir. Bütün çiftlerin hesabı "Örnek Sorular" bölümündedir.

### 3.4 Yöntemin sakıncası ve ağırlıklar

Her algoritmanın bir sakıncası vardır. Bu yöntemde birbirine daha yakın diziler daha yüksek ağırlık kazanır, yani skoru baskılar. Çoklu hizalama programı bunu her dizi çiftine bir ağırlık hesaplayarak aşar. Ağırlıklar, hizalanan dizilerin kestirilen ağacına göre verilir; yine filogenetik ağaç kullanılır.

Akış şöyle özetlendi:

1. Bütün ikili hizalama skorlarını hesapla.
2. Skorları kullanarak ağacı kestir.
3. Ağaca göre çift ağırlıklarını hesapla.
4. Ağaca göre sezgisel (heuristic) bir çoklu dizi hizalaması üret.

Bu yolla her dizi çifti için en büyük ağırlık hesaplanır ve en iyi hizalamayı bulmak için hesaplanması gereken uzaysal konumlar belirlenir.

## 4. İlerlemeli Çoklu Hizalama

### 4.1 Temel fikir

MSA programının boyutu sınırlıdır. İlerlemeli hizalama (progressive alignment) yaklaşımı en çok benzeyen dizilerin hizalamasıyla başlar (ekrandan, 00:55:00). Bu yaklaşımı kullanan algoritmalar birbirinin aynısı değildir, varyantları vardır; ama genel olarak:

- En benzer diziler, geçen hafta anlatılan standart dinamik programlamayla hizalanır.
- Daha az ilişkili diziler adım adım bu başlangıç hizalamasına eklenir.
- Deneme hizalaması önce dizilerin filogenetik ağacı kestirilerek üretilir; diziler ağaçtaki ilişki sırasına göre çoklu hizalanır.

Her seferinde önce ağaç kurulur, hizalama ağaçtaki ilişkiye göre oluşturulur. Bu yaklaşımı kullanan bilinen programlar PILEUP ve CLUSTALW'dır. Bunlar sezgisel yaklaşımlar olduğundan en iyi sonucu garanti etmezler.

### 4.2 Ağacı izleyerek hizalama

Slayttaki çizimde ("follow generated tree") önce ağaçta en yakın olan 1 ve 3 dizileri hizalanır, sonra 2 ve 5 dizileri hizalanır, en sonunda bu iki grup birleştirilir (ekrandan, 01:00:00). Filogenetik ağaç dizilerin ilişkisini, hangi dizinin hangisine yakın olduğunu gösterir; başlangıç hizalamaları bu ağaca göre yapılır.

### 4.3 CLUSTALW ve CLUSTALX

Slayttaki açıklamalar (ekrandan, 01:05:00):

- İlk programlarda kılavuz ağaç, ikili hizalamaların UPGMA ile kümeleme (CLUSTer) analizi yapılarak kurulmuştu; ad CLUSTer ve ALignment'tan gelir: CLUSTAL.
- CLUSTALW ve CLUSTALX ilerlemeli hizalama programlarıdır. W, ağırlıklı (weighted) demektir; ağırlık, ilerlemeli yaklaşımda çiftler toplamı yönteminin sorununu dengelemek içindir. X, X Window demektir; X Window, Unix sistemlerinin grafik kullanıcı arayüzüdür, yani CLUSTALX bu programın Unix grafik arayüzlü sürümüdür.
- UPGMA: unweighted pair group method with arithmetic mean. Filogenetik ağaç kurmada kullanılan bir yaklaşımdır; sonraki derslerde anlatılacak.

İzlenen adımlar:

1. Bütün dizilerin ikili hizalamalarını yap (dinamik programlamayla).
2. Hizalama skorlarını kullanarak filogenetik ağaç üret.
3. Dizileri ağacın rehberliğinde sırayla hizala.

Altyazıya göre bu yaklaşımda uyuşmayan konumların toplam sayısı hizalanan konumların toplam sayısına bölünerek bir skor elde edilir. <!-- BELİRSİZ: bu cümle altyazıda bozuk; paydanın "eşleşen" mi "hizalanan" konumlar mı olduğu net değil, slayt karesi yok. --> Hizalamalara kök düğümden uzaklıklarına göre bir ağırlık verilir. İlerlemeli yöntemlerde boşluklar mevcut bir profile eklenir. CLUSTALW ayrıca boşlukları en uygun yerlere koymak için istatistiksel bir model kullanır.

### 4.4 Ağaçtan ağırlık hesaplama örneği

Slayttaki ağaçta A'nın dalı 0.2, B'nin dalı 0.1, A ile B'nin ortak dalı 0.3, C'nin dalı 0.5'tir; C doğrudan köke bağlıdır (ekrandan, 01:10:00). Ortak dal iki farklı dala ayrıldığı için uzunluğu ikiye bölünür. Kök düğümden sonra başka düğüm ve dal olmadığından hesap kökte biter.

- A: $0.2 + 0.3/2 = 0.2 + 0.15 = 0.35$
- B: $0.1 + 0.3/2 = 0.1 + 0.15 = 0.25$
- C: $0.5$ (yalnız kendi dalı)

Aynı slaytın ikinci bölümünde ağırlıkların kullanımı gösterilir: birinci hizalamanın bir sütununda A dizisinde (ağırlık $a$) K, B dizisinde (ağırlık $b$) I; ikinci hizalamanın bir sütununda C dizisinde (ağırlık $c$) L, D dizisinde (ağırlık $d$) V vardır. Bu iki sütunu bir çoklu hizalamada eşleştirmenin skoru:

$$\frac{a\,c\,s(K,L) + a\,d\,s(K,V) + b\,c\,s(I,L) + b\,d\,s(I,V)}{4}$$

Burada $s(x,y)$ skor matrisindeki değerdir.

Bu ad hoc algoritma CLUSTALW adıyla bir program olarak gerçeklenmiştir; derste programın bir çıktısı da gösterildi. Program European Bioinformatics Institute (EBI) tarafından sunulur.

### 4.5 PILEUP

Hoca bir sonraki programın iç yapısının tam bilinmediğini, ama temelde ilerlemeli hizalama yaklaşımını kullandığını söyledi. Bu programda diziler önce global hizalama için Needleman-Wunsch algoritmasıyla (dinamik programlama) ikili hizalanır; skorlar UPGMA (aritmetik ortalamalı ağırlıksız çift grup yöntemi) ile ağaç üretmekte kullanılır. <!-- BELİRSİZ: altyazının bu kısmı (01:12:16-01:14:42) bozuk; anlatılan programın PILEUP olduğu bağlamdan çıkarıldı. -->

> **Ek bilgi (derste anlatılmadı):** Altyazıda "middleman and Finnish algorithm" diye bozuk geçen ad, global hizalama için kullanılan Needleman-Wunsch algoritmasıdır. Bu algoritma önceki derslerdeki global ikili hizalama konusunun dinamik programlama yöntemidir.

PILEUP, CLUSTALW'a çok benzer; GCG (Genetics Computer Group) paketinin bir parçası olarak gerçeklenmiştir. O da sezgiseldir ve en iyi hizalamayı sağlamaz. Sonunda diziler arasındaki benzerliklerin küme dendrogramını çizer. Slaytta bunun evrimsel bir ağaç olmadığı özellikle belirtilir (ekrandan, 01:15:00). Hoca, filogenetik ağaç denen bu tür ağaca veri madenciliği ve makine öğrenmesi bağlamında dendrogram dendiğini hatırlattı.

### 4.6 İlerlemeli yaklaşımın zayıf yanı

İlerlemeli hizalamanın eksikliği ilk ikili hizalamalara bağımlı olmasıdır. Diziler benzer değilse ilk adımlarda yapılan hatalar sonraki adımlara yayılır.

## 5. Yinelemeli Yöntemler

### 5.1 Genel yaklaşım

Aradan sonra yinelemeli (iterative) yöntemlere geçildi. Bu da tek bir yöntem değil, bir algoritma grubudur ve ilerlemeli yaklaşımdan biraz farklıdır. Slayttaki maddeler (ekrandan, 01:40:00):

- Yinelemeli hizalama yöntemleri dizilerin bir başlangıç hizalamasıyla başlar.
- Bu hizalamalar daha makul bir sonuç verecek biçimde düzeltilir.
- Amaç genel hizalama skorunu iyileştirmektir.
- Hizalama tekrar tekrar iyileştirilir.
- Grupların seçimi filogenetik ağaca dayanır.

Her turda skorlar yeniden hesaplanır. Yinelemenin ne zaman durdurulacağı sorusunun cevabı: skorlar artık değişmeyince ya da belirli bir değişim oranı (eşik) belirlenip değişim bunun altına inince durulur. Başlangıçla son arasında skorları belirlemek için çeşitli nicel yöntemler vardır. Hoca burada da dinamik programlamayla ikili hizalamanın ve filogenetik ağacın yaygın kullanıldığını vurguladı. Slayttaki kaynak: Hirosawa, M., Totoki, Y., Hoshida, M., & Ishikawa, M. (1995). Comprehensive study on iterative algorithms of multiple sequence alignment. Bioinformatics, 11(1), 13–18.

Yinelemeli yöntem kullanan bilinen programlar:

- MultAlin
- PRRP (Profile-based Randomized iterative Refinement method for alignment of Protein sequences)
- DIALIGN (Diagonal Alignment)

### 5.2 MultAlin

MultAlin'de ikili skorlar ilerlemeli hizalama sırasında yeniden hesaplanır. Önce bir hizalama yapılır ve ikili skorlar bulunur; sonra bu skorlar yeniden hesaplanır, filogenetik ağaç da yeniden kurulur. Her turda skorlar yeniden belirlenir ve hizalama iyileşir; bir süre sonra değişiklik olmayınca yineleme durdurulur.

### 5.3 PRRP

PRRP'de başlangıç ikili hizalaması bir ağaç üretir, ağaç ağırlıkları üretir; sonra lokal olarak hizalanmış bölgeler yeni bir hizalama ve ağaç üretmekte kullanılır. Slayttaki akış şeması (ekrandan, 01:45:00):

```text
Başlangıç hizalaması
  -> Filogenetik ağaç
  -> Dizi çiftlerine ağırlıklar w(i,j), 1 <= i,j <= N
  -> Çoklu hizalamanın yinelemeli iyileştirilmesi
       (ağırlıklı çiftler toplamı WSP ile, iç döngü)
  -> Yakınsadı mı?
       Hayır -> filogenetik ağaca geri dön
       Evet  -> Dur
```

Ağırlıklı çiftler toplamı:

$$WSP=\sum_{i<j} w_{i,j}\,S_{i,j}$$

Burada $w_{i,j}$ dizi çiftinin ağırlığı, $S_{i,j}$ o çiftin hizalama skorudur.

### 5.4 DIALIGN

DIALIGN biraz farklı bir yaklaşımdır: hizalamayı ağırlıklı köşegenlerin bir derlemesi oluşturur.

> **Ek bilgi (derste anlatılmadı):** DIALIGN'daki "köşegen", nokta matrisinde boşluksuz eşleşen bir segment çiftine karşılık gelir. Program bu segment çiftlerini ağırlıklandırıp birbiriyle tutarlı olanları birleştirerek hizalamayı kurar; bu yüzden boşluk cezası doğrudan kullanılmaz.

## 6. Optimizasyon Yaklaşımları

### 6.1 Genetik algoritma

Çoklu hizalamada optimizasyon algoritması örneği olarak genetik algoritma ele alındı. Hoca sürecin ilk adımını bir örnekle anlattı: bir dizinin sonu, öteki dizinin başı boşluklarla doldurulur (padding); böylece dizilerin birbirine göre kaydırıldığı başlangıç hizalamaları oluşturulur. <!-- BELİRSİZ: genetik algoritmanın 1. adımının slaytı karede yok; altyazı bu kısımda büyük ölçüde bozuk. -->

Sonraki adımlar slaytta şöyledir (ekrandan, 01:50:00):

- Başlangıç hizalamaları çiftler toplamı yöntemiyle skorlanır. Standart amino asit skor matrisleri ile boşluk açma (gap open) ve boşluk uzatma (gap extension) cezaları kullanılır.
- Başlangıç hizalamaları, yeni bir çoklu hizalama nesli verecek biçimde değiştirilir:
  - Çoklu hizalamaların yarısı değişmeden sonraki nesle geçmek üzere seçilir (doğal seçilim). Bu yarı, her diziye SP skorlarıyla ters orantılı olasılıklar verilerek seçilir (en iyi hizalamalar; SP skorları ebeveynden uzaklıklarına göre ağırlıklandırılır).
  - Öteki yarı da sonraki nesle gönderilir, ama önce mutasyona uğrar.

Mutasyon sürecinde boşluklar dizilere eklenir ve daha yüksek skorlu bir hizalama elde etmek için yeniden düzenlenir. Mutasyona uğrayacak diziler kestirilen filogenetik ağaca göre iki kümeye ayrılır; hizalamada rastgele konumlara rastgele uzunlukta boşluklar eklenir.

### 6.2 Benzetilmiş tavlama

Genetik algoritmaya benzer biçimde çalışan bir başka yaklaşım benzetilmiş tavlamadır (simulated annealing). Slayttaki maddeler (ekrandan, 01:55:00):

- Sezgisel olarak belirlenmiş bir çoklu hizalamayla başlanır; hizalama, skoru artıran değişiklikleri belirleyen olasılıksal modellerle değiştirilir.
- Sakıncası, genel olarak en iyi hizalama yerine yalnız yerel olarak en iyi hizalamada takılıp kalabilmesidir.
- Mevcut hizalamayı olasılıksal bir yaklaşımla yeniden düzenleyerek hizalama skorunu artıran değişiklikleri bulur.

Hoca, bulunan sonucun en iyi hizalama sanılmasının yanlış bir yorum olacağını; asıl en iyi hizalamanın başka bir yerde olabileceğini belirtti.

## 7. Grup ve Ağaç Yaklaşımları, Profil Analizi ve Program Seçimi

### 7.1 Grup yaklaşımı

Bir başka yaklaşımda diziler farklı gruplara ayrılır. Genel akış: önce benzer gruplar belirlenir ve diziler bu benzer gruplar içinde hizalanır; sonra her grubun genel uzlaşı (consensus) dizisi oluşturulur ve gruplar arasında hizalama yapılır.

### 7.2 Ağaç yaklaşımı

Ağaç yaklaşımında önce ağaç kurulur ve ağaçta birbirine en yakın iki dizi hizalanır. Ardından sıradaki en iyi dizi ya da dizi grubu eklenir; bütün diziler hizalanana kadar devam edilir. Hoca ağacın biyoenformatikte çok yaygın kullanıldığını yineledi; PILEUP, CLUSTALW gibi programlar bu ağacı yoğun biçimde kullanır. Tree align algoritması, diziler eklendikçe ağacı en tutumlu (maximum parsimony) ağaç olacak biçimde yeniden düzenler; en tutumlu ağaç evrimsel değişiklikleri verir.

> **Ek bilgi (derste anlatılmadı):** En tutumluluk (maximum parsimony) ilkesi, gözlenen dizileri açıklamak için en az sayıda evrimsel değişiklik (mutasyon) gerektiren ağacı en iyi ağaç sayar. Filogenetik ağaç kurma yöntemleri derste ileride ayrıca ele alınacak.

### 7.3 Profil analizi (global bağlamda)

Profil analizinde önce bir çoklu dizi hizalaması yapılır, sonra korunmuş (conserved) bölgeler seçilir. Hizalama hakkındaki bilgiyi saklamak için bir matris oluşturulur: hizalamadaki her konum için bir satır, her kalıntı için bir sütun vardır; boşluk açma ve boşluk uzatma değerleri de tutulur. Profil seçimi bu yaklaşımın sonucunu çok etkiler.

### 7.4 Tipik görevler için önerilen programlar

Slayttaki tablo, Edgar R.C. ve Batzoglou S.'nin "Multiple sequence alignment" makalesinden (Current Opinion in Structural Biology 16, 368–373, 2006) alınmıştır (ekrandan, 02:10:00):

| Girdi verisi | Öneri |
|---|---|
| Tipik protein uzunluğunda (en çok yaklaşık 10 000 kalıntı), yaklaşık global hizalanabilir 2-100 dizi | ProbCons, T-Coffee ve MAFFT ya da MUSCLE kullanılır, sonuçlar AltAVisT ile karşılaştırılır. Uyuşan bölgelerin doğru olma olasılığı daha yüksektir. Düşük özdeşlik yüzdeli dizilerde ProbCons genelde en doğrusudur; yapı bilgisi varsa T-Coffee'nin bir varyantı olan 3DCoffee ile eklemek çok yararlı olabilir. |
| Yaklaşık global hizalanabilir 100-500 dizi | MUSCLE ya da MAFFT betiklerinden biri varsayılan seçeneklerle kullanılır. AltAVisT ile karşılaştırma mümkündür, ama diziler çok benzer değilse çok sayıda dizide sonuçları yorumlamak zordur. |

Hoca, derste ProbCons, T-Coffee, MAFFT, MUSCLE gibi programların ayrıntısına girilmediğini, bunların da sezgisel algoritmalar olduğunu söyledi. Dizi sayısı 500'den büyükse MUSCLE algoritmasının varyantları ya da daha hızlı MAFFT gerçeklemeleri kullanılabilir. <!-- BELİRSİZ: tablonun 500'den fazla dizi satırı karede görünmüyor; bu cümle altyazıdan. --> Tablo, bu tür bir görevle karşılaşıldığında bir kılavuz olarak sunuldu.

### 7.5 Global çoklu hizalamanın özeti

Hoca global çoklu hizalamayı şöyle özetledi: en iyi hizalamayı veren, pratikte uygulanabilir bir doğrudan yöntem yoktur. En iyi hizalama elde edilebilir, ama sonucun en iyi olduğu garanti edilemez. İkili hizalamada bir skor şeması ve iki dizi verildiğinde dinamik programlama algoritması kesinlikle en iyi hizalamayı verir. Çoklu hizalamada bu iddia edilemez; dinamik programlama, filogenetik ağaç gibi araçlar kullanılarak en iyi olmayabilecek bir sonuç üretilir.

> **Hocanın vurgusu:** İkili hizalamada dinamik programlama en iyi hizalamayı kesin olarak bulur; çoklu hizalamada ise kullanılan yöntemlerle bulunan sonucun en iyi olduğu garanti edilemez.

## 8. Lokal Çoklu Dizi Hizalama

### 8.1 Global ve lokal ayrımı

İkili hizalamada dinamik programlama global ve lokal (ve ayrıca örtüşme, overlap) diye sınıflanmıştı. Çoklu hizalamada da global ve lokal çoklu hizalama vardır.

Global çoklu hizalamada $k$ dizinin hepsi aynı uzunlukta olacak biçimde hizalanmaya çalışılır. Bunun mantığı evrim çalışmalarıdır: diziler aynı ataya sahip olduğu düşünülen türlerden gelir; aynı atadan geldikleri için aynı uzunlukta olmaları beklenir, bu yüzden global hizalanırlar. Ama bazen yalnız lokal hizalamalar ilgilendirir; lokal çoklu hizalamanın asıl amacı budur. Bazı amaçlar için belirli bölgeler, örneğin korunmuş bölgeler, daha ilgi çekicidir.

### 8.2 Lokal hizalamanın önemi

Lokal çoklu hizalama şu nedenlerle önemlidir:

- Genomik DNA'da belirli bir genin yukarı akışında (upstream, genden önce) yer alan bölgelerde, genin transkripsiyonu için transkripsiyon faktörlerinin DNA'ya bağlandığı diziler bulunabilir. Bir gen ailesinin birkaç farklı organizmadaki yukarı akış bölgelerinde bir sinyal olup olmadığı araştırılıyorsa bütün genomik DNA'yı hizalamaya çalışmak yerine yalnız korunmuş bölgeyi bulmak önemlidir.
- Protein dizilerinin lokal hizalamaları, başka bakımdan ilişkisiz proteinlerde bulunan ortak alanlar (domain) hakkında bilgi verebilir.

Hoca, veri analizinde ikili dizi hizalama gibi temel yaklaşımların zaten anlatıldığını, filogenetik ağaç elde etme ve başka kavramların ileride ele alınacağını belirtti.

## 9. Profillerin Hesaplanması ve Entropi

### 9.1 Profil analizi

Lokal hizalamaya yaklaşımlardan biri profil analizidir (ekrandan, 02:20:00). Önce diziler çoklu hizalanarak profiller oluşturulur ve en çok korunmuş bölgeler belirlenir. Profiller bir çoklu dizi hizalamasını bir skor matrisiyle tanımlar.

Profil ancak eğitim kümesindeki çeşitlilik kadar temsil edicidir; yani büyük ölçüde eğitim kümesine bağlıdır ve eğitim verisine doğru bir yanlılık (bias) taşır. Eğitim verisi doğru seçilirse sonuç daha iyi olur; eğitim kümeleri dikkatle kurulmazsa yanlı olabilir.

### 9.2 Profil hücreleri: log-odds skoru

Profil matrisinin her hücresi bir log-odds skorudur (ekrandan, 02:25:00). Tek bir hücrenin değeri, belirli bir kalıntının hizalamadaki belirli bir konumda bulunmasının log-odds skoru olarak hesaplanır; bu, iki amino asidin belirli bir skor şeması (PAM250, BLOSUM80 gibi) kullanılarak rastgele hizalanma olasılığına bölünür. PAM "Percent Accepted Mutation", BLOSUM "Blocks Substitution Matrix" kısaltmasıdır. Profilde boşluk açma ve boşluk uzatma için de ek cezalar (afin boşluk cezası) hesaplanmalıdır. Bazı yöntemler hataları azaltmak için dizi ağırlıklarını da hesaba katar.

### 9.3 Entropi

Bir yöntem Shannon entropisini kullanır. Hoca öğrencilere entropinin ne olduğunu sordu ve Claude Shannon'ı matematikçi ve elektrik mühendisi olarak andı; kavramın veri madenciliği ve makine öğrenmesi derslerinde de geçtiğini söyledi. Entropi, termodinamikte ve bilgi kuramında bir sistemdeki düzensizliğin ya da rastgeleliğin miktarını tanımlayan bir kavramdır; temelde bir rastgelelik, yani bilgi ölçüsüdür. Burada, evrim modelindeki beklenen çeşitlilik verildiğinde her sütundaki çeşitliliği hesaplamak için kullanılır.

Entropi düşük olan sütun daha az çeşitli, yüksek olan sütun daha çeşitlidir; bu yüzden entropi korunmuş bölgeleri belirlemek için iyi bir ölçüdür. Tek bir sütunun entropisi (ekrandan, 02:30:00):

$$H=-\sum_{\text{kalıntılar }(a)} f_a \log(p_a)$$

- $a$: bir kalıntı (amino asit). Veri dosyası açısından kalıntı bir karakterdir; amino asit dizisi bir karakter dizisidir.
- $f_a$: $a$ kalıntısının sütundaki frekansı.
- $p_a$: $a$ kalıntısının o sütundaki olasılığı (beklenen frekansı).

### 9.4 Niteliksel veri ve entropi

Hoca burada veri bilimi kavramlarına döndü ve bir amino asit dizisi veri dosyasının hangi tür veri içerdiğini sordu: niceliksel (quantitative) mi, niteliksel (qualitative) mi? Niceliksel veri sayı demektir; A, B, C, D harfleri sayı değildir, dolayısıyla bu veri niteliksel veridir. Niteliksel veriler de nominal ve ordinal (sıralı) diye sınıflanır; hoca harfler arasında bir sıra olup olmadığını sordu. <!-- BELİRSİZ: nominal/ordinal sorusunun derste verilen cevabı altyazıda okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** Amino asit harfleri arasında doğal bir büyüklük sırası yoktur; bu yüzden bu veri türü nominal (adsal) niteliksel veri olarak sınıflanır.

İstatistiksel veri analizine girişte niteliksel verinin niceliğe dönüştürülmesi için çapraz tablolar (contingency tables) ve frekanslar kullanılır. Burada da yaklaşım çok benzerdir: kalıntıların frekansları, yani bir veri dosyasındaki harflerin sayısı belirlenir; böylece niteliksel bilgi niceliksel hâle getirilir. Entropi denklemi niceliksel bir denklemdir, veri ise niteliksel; entropi bu verideki bilgi miktarını sayısallaştırır.

### 9.5 Entropiyle model ve ağırlık belirleme

$H$, 20 olası ata amino asidin her biri ve çok sayıda evrimsel uzaklık için PAM matrislerinden biri kullanılarak hesaplanır. Her sütun-olası ata birleşimi için $H$'yi en küçük yapan uzaklık, sütundaki çeşitliliği o atadan üreten uzaklığın en iyi kestirimidir. Bu analiz, sütundaki amino asit frekanslarının nasıl oluşmuş olabileceğine dair 20 olası model verir. Ardından, çoklu hizalamadaki sütun çeşitliliğini doğurmuş olabilecek 20 olası dağılımın her biri için koşullu olasılıklar hesaplanır ve ağırlıklar bu olasılıklardan bulunur; $w_a$, $a$ modeline verilen ağırlıktır. <!-- BELİRSİZ: ağırlık formülünün slaytı karede yok. -->

### 9.6 Profilin log-odds skoru

Log-odds skoru yönteminde gözlenen frekansın arka plan (background) frekansına oranının 2 tabanlı logaritması alınır; hoca bunu ileride bir örnekle açıklayacağını söyledi. Profildeki her kalıntı, skor matrislerindeki kavrama benzer biçimde skorlanır. Profilin $i$. satırı ve $j$. amino asidi için log-odds skoru ($\text{Profile}_{ij}$) bir oranla verilir (ekrandan, 02:40:00). Altyazıdan okunabilen terimler: profilin $i$. satırı; $i$. satıra en iyi uyan PAM amino asit dağılımında $j$ amino asidinin frekansı; bu dağılımın olasılığı; $j$ amino asidinin arka plan frekansı. <!-- BELİRSİZ: Profile_ij formülü karede henüz görünmüyor (slayt animasyonlu), altyazı da formülü tam vermiyor. --> Ders bu noktada bitti; konuya sonraki hafta devam edilecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:12:30): Üç dizi dinamik programlamayla hizalanacaksa kaç boyutlu bir yapı doldurulur?

Cevap (derste verildi, 00:17:59): Üç boyutlu; üç dizi için bir küp doldurulur. Hoca soruyu sinyal benzetmesiyle açtı: zaman serisi tek boyutlu, resim iki boyutlu, zamanla değişen görüntü üç boyutludur. $k$ dizi için $k$ boyutlu uzay gerekir.

**Soru 2** (derste sözlü, 00:24:07): Hesaplama karmaşıklığı arttığında bir hesaplama ortamında bir algoritmayı gerçeklerken hangi kaynak sorunları ortaya çıkar, çözüm nedir?

Cevap (derste verildi, 00:26:10): Boyut arttıkça bellek hızla tükenir ve işlem gücü yetersiz kalır. Çözüm, arama uzayını sınırlamaktır (sınırlı dinamik programlama; Carrillo-Lipman yaklaşımı).

**Soru 3** (ekrandan, 00:45:00): ECSQ, SNSG, SWKN, SCSN hizalamasında kaç ikili karşılaştırma vardır?

Cevap (derste verildi, 00:45:15): Dört diziden 2'li seçim sayısı kadar: $\binom{4}{2}=\frac{4\cdot3}{2}=6$. Çiftler: 1-2, 1-3, 1-4, 2-3, 2-4, 3-4.

**Soru 4** (ekrandan, 00:50:00): Aynı hizalamayı PAM250 matrisiyle çiftler toplamı yöntemiyle skorlayın.

Derste yalnız 1-2 çifti hesaplandı: $0 + (-4) + 2 + (-1) = -3$.

> **Çözüm (derste verilmedi):** PAM250 değerleri karedeki matristen okunarak bütün çiftler hesaplandı ve python ile denetlendi:
>
> - 1-2 (ECSQ/SNSG): $0 - 4 + 2 - 1 = -3$
> - 1-3 (ECSQ/SWKN): $0 - 8 + 0 + 1 = -7$
> - 1-4 (ECSQ/SCSN): $0 + 12 + 2 + 1 = 15$
> - 2-3 (SNSG/SWKN): $2 - 4 + 0 + 0 = -2$
> - 2-4 (SNSG/SCSN): $2 - 4 + 2 + 0 = 0$
> - 3-4 (SWKN/SCSN): $2 - 8 + 0 + 2 = -4$
>
> Toplam SP skoru $-3 - 7 + 15 - 2 + 0 - 4 = -1$. Sütun sütun bakıldığında da sonuç aynıdır: 1. sütun (E,S,S,S) 6, 2. sütun (C,N,W,C) −16, 3. sütun (S,S,K,S) 6, 4. sütun (Q,G,N,N) 3; toplam $-1$.

**Soru 5** (ekrandan, 01:10:00): Dal uzunlukları A için 0.2, B için 0.1, A-B ortak dalı 0.3 ve C için 0.5 olan ağaçta CLUSTALW dizi ağırlıkları nedir?

Cevap (derste verildi, 01:09:11): Ortak dal paylaşan dizi sayısına bölünür. A: $0.2 + 0.3/2 = 0.35$; B: $0.1 + 0.3/2 = 0.25$; C: $0.5$.

**Soru 6** (derste sözlü, 02:25:53): Entropi nedir?

Cevap (derste verildi, 02:26:46): Termodinamikte ve bilgi kuramında bir sistemdeki düzensizliğin ya da rastgeleliğin miktarını tanımlayan bir ölçüdür; bir bilgi ölçüsüdür. Hizalamada bir sütunun çeşitliliğini ölçmek ve korunmuş bölgeleri bulmak için kullanılır.

**Soru 7** (derste sözlü, 02:31:01): Amino asit dizisi verisi niceliksel mi, niteliksel midir?

Cevap (derste verildi, 02:32:12): Harfler sayı olmadığından niteliksel veridir. Ardından sorulan "nominal mi, ordinal mi?" sorusunun derste verilen cevabı altyazıda okunmuyor. <!-- BELİRSİZ: nominal/ordinal cevabı. -->

## Dersin Toparlaması

Bu derste ikili dizi hizalamadaki dinamik programlamanın çoklu hizalamaya genişletilmesinin neden pratik olmadığı gösterildi: üç dizide küp, $k$ dizide $n^k$ hücre gerekir ve karmaşıklık üstel artar. Bu yüzden Carrillo-Lipman sınırlaması gibi arama uzayını küçülten yöntemler, çiftler toplamı skoru ve filogenetik ağaçtan hesaplanan ağırlıklar kullanılır. İlerlemeli yöntemler (CLUSTALW, CLUSTALX, PILEUP) en yakın dizilerden başlayıp kılavuz ağacı izler; yinelemeli yöntemler (MultAlin, PRRP, DIALIGN) başlangıç hizalamasını skor değişmeyene kadar iyileştirir; genetik algoritma ve benzetilmiş tavlama gibi optimizasyon yaklaşımları da aynı amaca hizmet eder. Hiçbiri sonucun en iyi olduğunu garanti etmez.

Dersin son bölümünde lokal çoklu hizalamaya geçildi: korunmuş bölgelerin (transkripsiyon faktörü bağlanma yerleri, ortak protein alanları) bulunması amacıyla profil analizi, log-odds skorlu profil matrisleri ve sütun çeşitliliğini ölçen entropi anlatıldı. Profilin log-odds skorunun hesabına ve bunun bir örnekle açıklanmasına sonraki derste devam edileceği söylendi; filogenetik ağaçların (UPGMA dahil) nasıl kurulduğu da ileriki derslerin konusu olarak anıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
