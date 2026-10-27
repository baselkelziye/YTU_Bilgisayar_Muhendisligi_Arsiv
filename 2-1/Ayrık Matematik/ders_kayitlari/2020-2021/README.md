# Ayrık Matematik Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Ayrık Matematik (BLM2521)
* **Hoca:** Prof. Dr. Banu Diri
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021
* **Şube:** BLM2521 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Tanışma, Dersin İşleyişi, Ayrık Matematiğe Giriş ve Önermeler Mantığı | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Mantıksal Denklik, Niceleyiciler, İspat Yöntemleri ve Tümevarım | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Bool Cebri, Bool Fonksiyonları, Mintermler, Mantık Kapıları ve Karnaugh Haritaları | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Kümeler ve Küme İşlemleri, Kartezyen Çarpım, Diziler, Dizgiler ve Sayı Sistemleri | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Bağıntılar ve Özellikleri, Bileşke, Denklik ve Sıralama Bağıntıları, Hasse Diyagramı, Kapanış ve Warshall Algoritması | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Fonksiyonlar, Ters Fonksiyon, Taban ve Tavan, Bölüm Soru Çözümü ve Algoritmalara Giriş: Arama, Sıralama, Öklid | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Veri Yapıları, Prefix-Infix-Postfix Gösterimleri, Algoritma Analizi ve Asimptotik Gösterimler | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 9** | Vize Değerlendirmesi, Özyinelemeli Algoritmalar ve Rekürans Bağıntılarının Çözümü | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 10** | Ağaçlara Giriş, İkili Arama Ağaçları, Ağaçta Gezinme, Huffman Kodlaması, DFS, BFS ve Prim Algoritması | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Kruskal Algoritması, Karar Ağaçları, Entropi ve Bilgi Kazancı, Ağaçlarda İzomorfizm ve Graf Türleri | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Euler ve Hamilton Çizgeleri, Dijkstra Algoritması, Çizge Modelleri, Eşyapı ve Kromatik Polinomlar | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Sonlu Durum Makineleri: Tanım, Durum Tablosu ve Diyagramı, Seri Toplayıcı ve Tasarım Örnekleri | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |

> [!NOTE]
> 8 numaralı kayıt arşivde yoktur (27 Kasım 2020 haftası); 1 Ocak 2021 tatildir.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Tanışma, Dersin İşleyişi, Ayrık Matematiğe Giriş ve Önermeler Mantığı
* **Genel Konular:**
  - Dersin tarihi 9 Ekim 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl ders yaklaşık 00:02'de başlar. İlk yarım saat tanışma ve dersin işleyişidir.
  - Dersin işleyişi ve değerlendirme
    - İki vize ve bir final var. Vize iki kısım olabilir: çoktan seçmeli test ve yazılı kısım. Yazılı cevaplar Drive'a yüklenir.
  - Dönemin konu başlıkları
    - Ayrık matematiğe giriş.
  - Ders kitabı
    - Ana kaynak: Rosen, *Discrete Mathematics and Its Applications*. Slaytların yaklaşık %95'i bu kitaptan hazırlandı.
  - Ayrık matematik nedir?
    - Bilgisayar sürekli verilerle çalışamaz. Sürekli bir sinyalden belirli aralıklarla örnek (sample) alınır. İşlem bu ayrık örnekler üzerinde yapılır.
  - Ayrık matematikle çözülen problem örnekleri
    - Belirli kurallara uyan kaç şifre yazılabilir?
  - Kombinatoryal problem türleri
    - Varlık problemi: tenis fikstürü örneği.
* **Hocanın Vurgusu:**
  - Algoritma bu bölümde her şeyin temelidir.
    - Veri Yapıları ve Algoritma Analizi derslerinde kalmanın asıl sebebi algoritma mantığının oturmamasıdır.
  - Koda hemen başlamayın.
    - Terzi gibi önce ölçü alın: blok şeması çizin, modülleri belirleyin, sonra kodlayın.
  - Aynı işi yapan iki programdan karmaşıklığı düşük ve hızlı olan tercih edilir.
  - Graf ve ağaçlar sonraki birçok dersin temelidir.
    - Bu konuları çok dikkatli dinleyin.
  - Terimlerin hem İngilizcesini hem Türkçesini öğrenin.
    - Kaynakların çoğu İngilizcedir.
* **Detaylı Açıklamalar:** Bu ders tanışma, dersin işleyişi ve mantık konusuna girişle geçti. Aşağıda dersin sayısal örnekleri ve doğruluk tabloları toplu olarak verilmiştir.

### 🔹 Ders 2: Mantıksal Denklik, Niceleyiciler, İspat Yöntemleri ve Tümevarım
* **Genel Konular:**
  - Dersin tarihi 16 Ekim 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl ders yaklaşık 00:06'da başlar. İlk dakikalar sohbet ve yüz yüze eğitim haberleri üzerinedir.
  - Önceki dersin tekrarı
    - Önerme, bağlaçlar (AND, OR, XOR, NOT), doğruluk tablosu kurma, koşullu önerme.
  - Mantıksal denklik (logical equivalence)
    - Doğruluk tablosundaki sonuçları aynı olan iki önerme mantıksal olarak denktir: $p \equiv q$.
  - Koşullu önermenin türevleri
    - Karşıt (converse): $q \rightarrow p$. $p \rightarrow q$ ile denk değildir.
  - Çift yönlü koşullu önerme (biconditional): $p \leftrightarrow q$, "ancak ve ancak", "if and only if".
    - $p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p)$.
  - Totoloji (tautology) ve çelişki (contradiction).
  - De Morgan kuralları ve bir alıştırma.
* **Hocanın Vurgusu:**
  - Bir ifadeyi doğruluk tablosuyla çözmek en güvenli yoldur.
    - Tabloyu bir kez kurarsanız, hoca hangi değerleri sorarsa sorsun cevap o satırdadır.
  - Biconditional, XOR'un tam tersidir.
    - XOR'da girişler aynıysa 0, $\leftrightarrow$'da girişler aynıysa 1.
  - Bir cümle için birden fazla doğru ifade yazılabilir.
    - Doğru olanlar birbirine mantıksal olarak denk olmalıdır. Kontrol etmek için doğruluk tablosu kurun.
  - Önermeleri olumlu biçimde tanımlayın. "You cannot ride" yerine $q$: "You can ride" alınır, olumsuzluk $\lnot q$ ile yazılır.
  - Evrensel bir ifadeyi yanlış yapan tek bir örnek yeter.
    - Bu örneğe karşı örnek denir.
* **Detaylı Açıklamalar:** $p \rightarrow q$ ve $\lnot p \lor q$ tabloları aynıdır.

### 🔹 Ders 3: Bool Cebri, Bool Fonksiyonları, Mintermler, Mantık Kapıları ve Karnaugh Haritaları
* **Genel Konular:**
  - Dersin tarihi 23 Ekim 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:04:00'te başlar. Kaydın başı bekleme ve sohbettir.
  - Önceki haftaların tekrarı
    - Önerme, mantık kapıları (AND, OR, NOT, XOR), koşullu önerme, çift koşullu önerme, mantıksal denklik.
  - Bool cebri (Boolean algebra)
    - $B = \{0, 1\}$ üzerinde toplama (OR), çarpma (AND, Boolean product) ve tümleyen (complement).
  - Bool ifadeleri ve Bool fonksiyonları
    - $n$. dereceden Bool fonksiyonu $F: B^n \to B$.
  - Bool cebri özdeşlikleri (Boolean identities)
  - Mintermler, çarpımların toplamı açılımı (sum-of-products expansion)
  - Mantık kapılarıyla devre çizimi ve yarım toplayıcı (half adder)
* **Hocanın Vurgusu:**
  - Karnaugh haritası, Bool fonksiyonunu sadeleştirmenin en hızlı ve en az hatalı yoludur.
    - Hoca, aynı sadeleştirmeyi Bool özdeşlikleriyle yaparken derste takıldığını söyledi. Tabloyla ya da haritayla yaparken hiç hata yapmadığını vurguladı.
  - Gruplar her zaman 2'nin kuvveti büyüklüğünde olur: 1, 2, 4, 8, 16.
    - Önce en büyük grup aranır. Sonra bir küçüğüne inilir.
  - Haritanın kenarları komşudur.
    - Sağ ve sol kenar birleşir. Üst ve alt kenar birleşir. Dört köşe de bir grup oluşturabilir ("bohça gibi katlama").
  - Gereksiz grup almayın.
    - Hoca bunun "çok yapılan bir hata" olduğunu söyledi. Diğer grupların tamamen kapsadığı bir grup sonucu sadeleştirmez, fazladan terim ekler.
  - Doğruluk tablosunu 0'dan başlatın: 000, 001, ...
    - Sütunlar sağdan sola $2^0$, $2^1$, $2^2$ basamaklarıdır.
* **Detaylı Açıklamalar:** Bool cebri yalnızca 0 ve 1 değerleri üzerinde çalışır. Toplama OR, çarpma AND, tümleyen NOT işlemine karşılık gelir. İşlem önceliği: önce parantez, sonra tümleyen, sonra çarpma, en son toplama.

### 🔹 Ders 4: Kümeler ve Küme İşlemleri, Kartezyen Çarpım, Diziler, Dizgiler ve Sayı Sistemleri
* **Genel Konular:**
  - Dersin tarihi 30 Ekim 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:08:00'de başlar. Kaydın başı yoklama, bayram tebriği ve sohbettir.
  - Kümeler (sets)
    - Kümenin gösterimi: liste gösterimi ve tanım (set-builder) gösterimi.
  - Küme işlemleri ve Venn şemaları
    - Birleşim (union), kesişim (intersection), ayrık kümeler (disjoint sets), tümleyen (complement), fark (difference), simetrik fark (symmetric difference).
  - Diziler (sequences)
    - Artan (increasing) ve azalan (decreasing) diziler, alt dizi (subsequence).
  - Dizgiler (strings) ve düzenli ifadelere (regular expressions) giriş
  - Sayı sistemleri: ikilik (binary), sekizlik (octal), onaltılık (hexadecimal)
    - Taban dönüşümleri, ikilik ve onaltılık toplama.
* **Hocanın Vurgusu:**
  - Derste görülen her kavram, başka bir problemin çözümünde kullanılabilir.
    - Hoca bunu iki örnekle gösterdi:
  - Ödevde "kesişimi bul" deniyorsa hazır `intersection` / `union` kütüphanesini kullanan sıfır alır.
    - Bu işlem büyük bir problemin küçük bir alt adımıysa kütüphane kullanılabilir. Hoca bunu "araba yaparken tekerleği yeniden icat etmeyin; ama sizden tekerlek isteniyorsa kendiniz yapın" diye anlattı.
  - Kümenin adı büyük harf, elemanları küçük harfle yazılır.
    - Küme sembolleri büyük-küçük harfe duyarlıdır: $X$ ile $x$ farklıdır.
  - $\emptyset \neq \{\emptyset\}$.
    - Birincisi boş kümedir. İkincisi tek elemanlı bir kümedir; elemanı boş kümedir.
  - $|A|$ gösterimi küme için mutlak değer değil, eleman sayısıdır.
    - Hoca, vizede bunu mutlak değer sanıp itiraz eden bir öğrenciyi örnek verdi.
* **Detaylı Açıklamalar:** Küme, ayrık nesnelerden oluşan topluluktur. Liste gösterimi $A = \{1, 3, 5, 7\}$ biçimindedir. Kitaplarda ve akademik metinlerde tanım gösterimi tercih edilir:

### 🔹 Ders 5: Bağıntılar ve Özellikleri, Bileşke, Denklik ve Sıralama Bağıntıları, Hasse Diyagramı, Kapanış ve Warshall Algoritması
* **Genel Konular:**
  - Dersin tarihi 6 Kasım 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:07:20'de başlar. Kaydın başı selamlaşma ve İzmir depremi (30 Ekim 2020) üzerine sohbettir.
  - Duyurular
    - Bu ders dönemin 5. haftası. Vize 8. haftada.
  - Bağıntılar (relations)
    - Kartezyen çarpım (Cartesian product) ve ikili bağıntı (binary relation).
  - Bağıntıların özellikleri
    - Yansıma (reflexive), "non-reflexive" ve yansımasız (irreflexive).
  - Bağıntının tersi (inverse) ve bağıntıların bileşkesi (composition): $R^2$, $R^3$, $R^n$.
  - Sınıf içi alıştırma: altı bağıntının özelliklerini öğrencilerle birlikte belirleme.
  - Denklik bağıntısı (equivalence relation) ve sıralama bağıntısı (partial order).
* **Hocanın Vurgusu:**
  - Bir özelliği "sağlamıyor" demek için tek bir karşı örnek yeter.
    - Bir ikili özelliği bozuyorsa diğerlerine bakmaya gerek yok. Hoca bunu dolaylı ispat (indirect proof) mantığına bağladı.
  - Geçişme özelliğinde en çok hata yapılır.
    - $(x,y)$ ve $(y,z)$ varsa $(x,z)$ aranır. Bu zincir hiç oluşmuyorsa kontrol edilecek bir şey yoktur, bağıntı geçişlidir.
  - Bir bağıntı aynı anda hem simetrik hem ters simetrik olabilir.
    - Örnek: yalnız $(x,x)$ çiftlerinden oluşan bağıntı.
  - Vize sorusu uyarısı: "$x$ divides $y$" ifadesi "$x$, $y$'yi böler" demektir.
    - Yani $y/x$ tam sayıdır. Öğrenciler sınavda $(x,y)$ yerine $(4,1)$ gibi ters çiftler yazıp puan kaybetmiş.
  - Algoritma yazarken uç noktaları (edge cases) düşünün.
    - İç içe döngüde iç döngü dış döngüye bağlıysa ($j = i+1$'den başlıyorsa) dış döngü $n-1$'de bitmeli.

### 🔹 Ders 6: Fonksiyonlar, Ters Fonksiyon, Taban ve Tavan, Bölüm Soru Çözümü ve Algoritmalara Giriş: Arama, Sıralama, Öklid
* **Genel Konular:**
  - Dersin tarihi 13 Kasım 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:08:40'ta başlar. Kaydın başı bekleme ve selamlaşmadır.
  - Geçen derste bağlantı sorunu yüzünden anlaşılmayan Warshall algoritmasının tekrarı.
  - Bağıntıların matrisle gösterimi (matris bağıntıları).
  - Fonksiyonlar
    - Fonksiyon tanımı, tanım ve değer kümesi.
  - Bölümün soru-cevap slaytları
    - Küme işlemleri, Venn şeması ile gölgelendirme.
  - Yeni bölüm: Algoritmalar
    - Bu bölüm bu dönem derse yeni eklendi. Konu başlıkları: algoritma kavramı, temel veri yapıları, fonksiyonların büyümesi, asimptotik gösterim, karmaşıklık, özyinelemeli algoritmalar ve rekürans bağıntıları.
* **Hocanın Vurgusu:**
  - Fonksiyonu fonksiyon yapan tek şart vardır: tanım kümesindeki her eleman değer kümesinde **tam olarak bir** elemana gider.
    - İki farklı eleman aynı değere gidebilir. Örnek: $x^2$'de $-2$ ve $2$ ikisi de $4$'e gider.
  - Bir fonksiyonun tersinin de fonksiyon olması için fonksiyon birebir ve örten (bijective) olmalıdır.
  - Taban ve tavanı yuvarlama (round) ya da kesme (trunc) ile karıştırmayın.
    - $\lfloor 4.9 \rfloor = 4$ olur, 5 olmaz.
  - Venn şeması ile sayma: bilgileri en içteki bölgeden başlayarak yerleştirin.
    - Bütün bölgeler dolunca hangi soru gelirse gelsin cevap şemadan okunur.
  - Algoritma çalışırken önce akış diyagramı ya da sözde kod yazın, sonra kodlayın.
    - Hoca bunun bölümün bir ekolü olduğunu, doğrudan koda geçmeyi başlangıçta doğru bulmadıklarını söyledi.

### 🔹 Ders 7: Veri Yapıları, Prefix-Infix-Postfix Gösterimleri, Algoritma Analizi ve Asimptotik Gösterimler
* **Genel Konular:**
  - Dersin tarihi 20 Kasım 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:11:40'ta başlar. Kaydın başı vize duyuruları ve Zoom'daki bir isim karışıklığıdır.
  - Algoritmalar bölümünün devamı: temel veri yapıları
    - Dizi (array), bağlı liste (linked list).
  - Yığın uygulaması: matematiksel ifadelerin gösterimi
    - Ara ek (infix), ön ek (prefix, Polish notation) ve son ek (postfix, Reverse Polish notation) gösterimleri.
  - Algoritma analizi
    - Doğruluk, zaman verimliliği, bellek kullanımı ve optimallik.
  - Fonksiyonların büyümesi ve asimptotik gösterim
    - Büyüme sırası: $1 < \log n < n < n\log n < n^2 < n^3 < 2^n < n!$.
  - Özyinelemeli (recursive) algoritmaların analizine geçilmedi. Hoca bu konunun vizeye dahil olmadığını söyledi.
* **Hocanın Vurgusu:**
  - Vize hakkında:
    - Vize bir sonraki Cuma (27 Kasım 2020). Hoca saatin değişmiş olabileceğini, sınav programından bakılmasını söyledi.
  - Klasik sınav kâğıdının fotoğrafını düzgün çekin.
    - Kâğıt düz bir zeminde, tam yukarıdan, kadraja tam girecek şekilde çekilsin. Işığa dikkat edin.
  - Bu derste görülen her şeyin en az %80'ini ileriki derslerde ve kod yazarken farkında olmadan kullanacaksınız.
    - Veri yapılarının ve algoritma analizinin ayrıntıları Veri Yapıları ve Algoritma Analizi derslerinde gelecek.
  - Prefix ve postfix yazarken işlem sırasını mutlaka soldan sağa takip edin.
    - Aynı önceliğe sahip işlemler (çarpma ve bölme, toplama ve çıkarma) soldan sağa yapılır.
  - Üs alma işleminde operandların sırası önemlidir.
    - Prefix'te $\uparrow b\,2$ "$b$'nin karesi"dir. $\uparrow 2\,b$ ise "$2^b$"dir.
* **Detaylı Açıklamalar:** Veri yapısı, veriyi tuttuğumuz ve özelliklerine göre işlediğimiz yapıdır. Kümeler, diziler, matrisler, bağlı listeler, yığınlar, kuyruklar, ağaçlar, graflar ve hash tabloları birer veri yapısıdır.

### 🔹 Ders 9: Vize Değerlendirmesi, Özyinelemeli Algoritmalar ve Rekürans Bağıntılarının Çözümü
* **Genel Konular:**
  - Dersin tarihi 4 Aralık 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Bu ders vizeden sonraki ilk derstir. Vize 27 Kasım 2020'de (8. hafta) klasik olarak yapıldı.
  - Vize değerlendirmesi: sorularda en çok yapılan hatalar.
    - Bağıntı sorusu, prefix/postfix sorusu, Karnaugh sorusu, karmaşıklık sorusu, önerme sorusu.
  - Özyinelemeli (recursive) algoritmalar
    - Yinelemeli (iterative) ve özyinelemeli algoritmaların farkı.
  - Rekürans bağıntıları (recurrence relations, öz yineli diziler)
    - Tanım: içinde kendisinden bir parça bulunan dizi.
  - Çözülebilir (tractable), çözülemez (intractable) ve çözümsüz (unsolvable) problemlere kısa giriş; durma problemi (halting problem), NP-complete ve NP-hard.
* **Hocanın Vurgusu:**
  - Vize sonuçları:
    - En yüksek not 95'tir; 100 alan yok.
  - Klasik sınavda kâğıtlarınıza ad ve numara yazın.
    - Dosyaya ad vermek yetmiyor; sistem indirirken dosya adlarını değiştirdi.
  - Prefix/postfix sorusunda en çok yapılan hatalar:
    - Örtük çarpma işaretini unutmak. $(A+B)C$ ifadesinde araya çarpma işareti konmalıdır.
  - Bir hata herkesin kâğıdında aynı olmaz.
    - Hoca prefix/postfix sorusunda kopya olduğunu düşündüğünü söyledi, ama üzerinde durmayacağını belirtti.
  - Karnaugh sorusunda:
    - 4 giriş (kara yolu, demir yolu, deniz yolu, hava yolu) ve 1 çıkış ($F$) vardı.
* **Detaylı Açıklamalar:** Genel çözüm: $a_n = a_n^{(h)} + a_n^{(ö)}$. Önce homojen kısım çözülür. Sonra $f(n)$'e göre özel çözüm tahmin edilir. $C_1$ ve $C_2$ en son, başlangıç değerleriyle bulunur.

### 🔹 Ders 10: Ağaçlara Giriş, İkili Arama Ağaçları, Ağaçta Gezinme, Huffman Kodlaması, DFS, BFS ve Prim Algoritması
* **Genel Konular:**
  - Dersin tarihi 11 Aralık 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:07:30'da başlar. Kaydın başı bekleme ve selamlaşmadır.
  - Dönem planı duyurusu (ikinci vize, final, kalan konular).
  - Yeni bölüm: Ağaçlar (trees)
    - Ağaç ile graf (graph) farkı, köklü (rooted) ve köksüz ağaç.
  - Ağaçta gezinme (traversal): önden sıralı (preorder), içten sıralı (inorder), sondan sıralı (postorder).
  - Huffman kodlaması ve Huffman ağacı.
  - Kapsayan ağaç (spanning tree)
    - Derin öncelikli arama (Depth First Search, DFS) ve yığın (stack).
* **Hocanın Vurgusu:**
  - Her ağaç bir graftır, ama her graf bir ağaç değildir.
    - Ağaçta kapalı döngü yoktur. Bir düğümden başka bir düğüme tek bir yol vardır.
  - Kök bilgisi verilmedikçe hiçbir düğüme "kök" diyemezsiniz.
    - Alışkanlık olarak en tepedeki düğüm kök kabul edilir. Ama bu ancak bariz bir durumda yapılır.
  - "Ağaç" deyince yalnız ikili ağaç düşünmeyin.
    - Bir düğümden istediği kadar dal çıkabilir.
  - Dengeli BST kurarken her eklemeden sonra kökün solunda ve sağında aynı sayıda (en fazla bir fark) eleman kalmalı.
    - Bir alt ağaçta sol dal dolmadan sağ dala eleman konmaz. Bu kurala dikkat edin.
  - Huffman algoritmasında en sık yapılan hatalar:
    - Toplama girmiş bir değeri tekrar toplamaya sokmak. Her değer yalnız bir kez toplanır.
* **Detaylı Açıklamalar:** Graf düğümlerden (vertex) ve kenarlardan (edge) oluşur. Grafta kapalı döngü olabilir. Döngü yoksa ve graf bağlıysa bu bir ağaçtır. Bu yüzden ağaçlar grafların özel bir alt modelidir.

### 🔹 Ders 11: Kruskal Algoritması, Karar Ağaçları, Entropi ve Bilgi Kazancı, Ağaçlarda İzomorfizm ve Graf Türleri
* **Genel Konular:**
  - Dersin tarihi 18 Aralık 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:11:10'da başlar. Öncesinde ikinci vize duyurusu ve hocanın sınıfa konuşması var.
  - İkinci vize duyurusu.
  - Ağaçlar bölümünün devamı
    - Kruskal algoritması ile en küçük kapsayan ağaç (minimum spanning tree).
  - Yeni bölüm: Graflar (graphs)
    - Graf tanımı, düğüm (vertex) ve kenar (edge) kümeleri.
* **Hocanın Vurgusu:**
  - **İkinci vize 8 Ocak 2021 Cuma günü test olarak yapılacak.**
    - Bölüm ikinci vizeler için takvim ilan etmeyecek. Bilgiyi dersin hocasından alın.
  - Kruskal'da bütün düğümlerin seçilmiş olması işin bittiğini göstermez.
    - Seçilen kenarlar birbirinden ayrı iki ağaç oluşturabilir. Bu ağaçların da bağlanması gerekir.
  - Sınavda küçük graf verilse bile sonucu gözle bakıp yazmayın.
    - Algoritmanın adımlarını gösterin.
  - Karar ağacında kökten yaprağa giden bir yolda bir özellik yalnız bir kez kullanılır.
  - Karar ağacının yüksekliği mümkün olduğunca küçük olmalı.
    - Az soru sorarak sonuca ulaşmak istenir. Bu yüzden köke ve alt düğümlere konacak özellik rastgele değil, bilgi kazancına göre seçilir.
* **Detaylı Açıklamalar:** Kruskal de Prim gibi en küçük kapsayan ağacı bulur. Üç adımdır:

### 🔹 Ders 12: Euler ve Hamilton Çizgeleri, Dijkstra Algoritması, Çizge Modelleri, Eşyapı ve Kromatik Polinomlar
* **Genel Konular:**
  - Dersin tarihi 25 Aralık 2020 Cuma. Ders Zoom üzerinden yapıldı.
    - Hoca 10.30'da fakülte toplantısına katıldı. Ders yaklaşık 01:30 ile 01:57 arasında ara verdi.
  - Çizgeler (graflar) konusunun kısa tekrarı
    - Basit çizge, paralel kenar, çoklu çizge, sözde çizge (pseudograph), yönlü ve ağırlıklı çizgeler.
  - Yol (path) ve devre (cycle)
    - $n$ düğümlü bir yolda $n-1$ kenar vardır. Kapalı devrede düğüm sayısı kadar kenar vardır.
  - Euler devresi ve Euler çizgesi
    - Königsberg köprü problemi.
  - Hamilton devresi ve Hamilton çizgesi
    - Gezgin satıcı problemi, $Q_3$ örneği, Gray kodu ilişkisi.
  - Dijkstra en kısa yol algoritması
    - A-F arası 6 düğümlü örnek ve $u_0$-$u_5$ arası ikinci örnek.
  - Çizge modelleri
    - Niş örtüşme (niche overlap) çizgesi, etki (influence) çizgesi, dairesel turnuva (round-robin tournament) çizgesi.
* **Hocanın Vurgusu:**
  - Euler çizgesi olabilmesi için bütün düğümlerin derecesi çift olmalıdır.
    - Tek dereceli tek bir düğüm görürseniz diğerlerine bakmanıza gerek yok.
  - Euler'de kenarlardan bir kez geçilir.
    - Hamilton'da düğümlerden bir kez geçilir.
  - Dijkstra'da yeni bulunan değer, tablodaki eski değerden büyükse alınmaz.
    - Tabloda her zaman en küçük değer kalır.
  - Çizgeye "influence graph", "precedence graph" gibi bir ad verildiyse çizgeyi o bakış açısıyla okuyun.
  - İki çizgenin şekli farklı görünebilir ama eşyapılı olabilir.
    - Düğüm sayısı, kenar sayısı ve dereceler aynı olmalı.

### 🔹 Ders 13: Sonlu Durum Makineleri: Tanım, Durum Tablosu ve Diyagramı, Seri Toplayıcı ve Tasarım Örnekleri
* **Genel Konular:**
  - Dersin tarihi 8 Ocak 2021 Cuma. Ders Zoom üzerinden yapıldı. Dönemin son kaydıdır.
    - Aynı gün 10.30'da vize sınavı vardı. 1 Ocak tatili yüzünden yetişmeyen konu sınavdan önce kısaca anlatıldı.
  - Sonlu durum makineleri (finite-state machines)
    - Günlük hayattan örnekler: turnike, asansör.
  - Çıktılı sonlu durum makinesinin biçimsel tanımı: $M = (S, I, O, f, g, s_0)$.
  - Durum tablosu ile durum diyagramı arasında geçiş.
  - Verilen bir girdi dizisi için çıktıyı bulma.
  - Başlangıç ve bitiş (final) durumları.
  - Tasarım örnekleri
    - Sağa kaydırma (ikiye bölme) yapan makine.
* **Hocanın Vurgusu:**
  - Bir olayı modellerken önce kaç durum (state) gerektiğine karar verin.
    - Olay bunun üzerine kurulur.
  - Durum tablosu verilirse diyagramı çizebilmeli, diyagram verilirse tabloyu yazabilmelisiniz.
    - Problem karmaşıksa hata yapmamak için tablo çizin. Basitse doğrudan diyagram yeterli.
  - Girdinin soldan mı sağdan mı okunduğu sonucu değiştirir.
    - Tasarımda bunu belirtmek gerekir.
  - Akan bir veri (sürekli giriş) varsa bitiş durumu yoktur.
    - Durma noktası belliyse (ör. ilk hatada çık, şifre uzunluğu) bitiş durumu konur.
  - Kendinize alıştırma yapın: sola kaydırma, iki bitlik sayıları toplama, çıkarma makineleri.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
