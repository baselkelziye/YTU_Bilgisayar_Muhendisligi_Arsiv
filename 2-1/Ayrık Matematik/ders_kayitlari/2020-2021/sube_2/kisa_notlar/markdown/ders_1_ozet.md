# Ders 1 Çalışma Özeti

## Genel Konular

- Ayrık matematiğin yeri ve kapsamı
  - Ayrık matematik (sonlu matematik), matematiğin süreklilik içermeyen, ayrık yapılarla ilgilenen dalıdır. Eski adıyla soyut matematik dersinin devamıdır.
  - Lojik devreler, hesaplama kuramı, algoritma analizi, veri yapıları ve kriptoloji gibi dersler zamanla bu dersin içinden ayrılmıştır. Bu ders hepsine giriş yapar.
  - Dönemin konu akışı: giriş ve mantık, Boole cebri ve kombinasyonel devreler, genel matematik tekrarı, sayı teorisi, algoritmalar ve karmaşıklık (asimptotik gösterim), graf ve ağaç veri yapıları, kromatik polinomlar, otomatlar, gramerler ve diller (sonlu durum makineleri).
  - Ana kaynak Rosen'ın *Discrete Mathematics and Its Applications* kitabıdır. MIT OpenCourseWare *Mathematics for Computer Science* dersi de önerilir (ekrandan, 00:15:00).
- Sürekli ve ayrık sinyal
  - Sürekli sinyal $x(t)$ zamanın her anında tanımlıdır. Belirli aralıklarla örnekleme yapılınca ayrık sinyal $x[n]$ elde edilir (ekrandan, 00:20:00).
  - Doğada olan sürekli, bilgisayarda saklanan ayrıktır. Her örneğin değeri de bilgisayarda en yakın gösterilebilir değere yuvarlanarak tutulur.
  - Sürekli matematik sürekli nesnelerle, ayrık matematik ayrık nesnelerle (tam sayılar, algoritma adımları, haritadaki yollar) ilgilenir.
- Ayrık matematikle çözülen problem türleri (ekrandan, 00:25:00)
  - Şifre sayısı, geçerli İnternet adresi sayısı, piyango olasılığı, ağda bağlantı varlığı, istenmeyen e-posta tespiti, şifreleme, toplayıcı devre, en kısa yol, gezgin satıcı problemi, cümlelerin mantıksal temsili, sonsuz sayıda asal sayı, sıralama ve sıralamanın doğruluğu.
  - Ayrık problemler üç gruba ayrılabilir: varlık problemi (çözüm var mı?), sayma problemi (kaç çözüm var?), optimizasyon problemi (en iyi çözüm hangisi?).
- Gezgin satıcı problemi ve kesin/optimal çözüm
  - A, B, C, D şehirlerinde A'dan başlayıp A'da biten turlar: diğer üç şehrin sıralaması $3! = 6$ farklı tur verir. Her turun maliyeti hesaplanır, en ucuzu seçilir (ekrandan, 00:35:00).
  - 81 il için başlangıç sabitlenince $80!$ tur vardır; kaba kuvvetle (brute force) hesaplamak pratikte mümkün değildir.
  - Kesin çözüm (exact solution) bütün durumları inceleyip en iyisini bulmaktır. Optimal (yaklaşık) çözüm ise kabul edilebilir, en iyiye yakın bir çözümdür; genetik algoritma ve karınca kolonisi gibi yöntemlerle aranır.
- Örnek problemler (slaytlardan)
  - Atama problemi: üç çalışan, üç iş, saat ücretleri ve iş süreleri tablosu; toplam ödemeyi en aza indiren atama aranır (Macar algoritması) (ekrandan, 00:40:00).
  - Planlama problemi: işler öncelik grafı olarak gösterilir, eş zamanlı yapılabilen işler paralel yürütülür. PERT diyagramında her işin bitiş zamanı, öncüllerinin en büyük bitiş zamanı artı kendi süresidir. Örnekte toplam süre 28 gündür; geriye doğru izlenen yol kritik yoldur (ekrandan, 00:45:00).
  - Pilot-şehir eşleştirmesi: iki taraflı (bipartite) graf ile modellenir; bağlantılar yalnız iki küme arasındadır.
  - Modelleme örneği: su molekülü de, şehir haritası da bir graf olarak gösterilebilir.
- Mantık ve önermeler
  - Mantık, doğru çıkarım elde etme çalışmasıdır (ekrandan, 01:05:00). Matematikte teorem ispatında, bilgisayar biliminde koşul ifadelerinde (if, for koşulları) kullanılır.
  - Önerme (proposition): doğru ya da yanlış olan, hüküm bildiren ifadedir. Derste doğru 1, yanlış 0 ile gösterilir.
  - Önerme değişkenleri $p, q, r, s, t$ ya da lojik devrelerdeki gibi $A_1, A_2, \dots, A_n$ olabilir.
- Birleştiriciler (connectives) (ekrandan, 01:10:00)
  - VE (conjunction, $\wedge$), VEYA (inclusive disjunction, $\vee$), YA DA (exclusive OR, XOR, $\oplus$), DEĞİL (negation, $\sim p$, $\neg p$ ya da $p'$), ise (implication, $\rightarrow$), ancak ve ancak (double implication, $\leftrightarrow$).
- Doğruluk tabloları
  - $n$ değişkenli bir ifadenin doğruluk tablosunda $2^n$ satır vardır. Sütunlar sağdan sola birer, ikişer, dörder satırda bir değişir.
  - VE: yalnız iki giriş de 1 ise 1. Seri bağlı iki anahtarlı devre gibi (ekrandan, 01:15:00).
  - VEYA: en az bir giriş 1 ise 1. Paralel bağlı anahtarlar gibi (ekrandan, 01:20:00).
  - XOR: girişler farklıysa 1, aynıysa 0. Kümelerde simetrik farka karşılık gelir (ekrandan, 01:25:00).
  - Özdeşlikler: $p\wedge 0=0$, $p\wedge 1=p$, $p\wedge p=p$, $p\wedge p'=0$; $p\vee 1=1$, $p\vee 0=p$, $p\vee p=p$, $p\vee p'=1$; $p\oplus p=0$, $p\oplus p'=1$, $p\oplus 1=p'$, $p\oplus 0=p$.
  - $p\oplus q=(p\wedge q')\vee(p'\wedge q)$ (ekrandan, 01:30:00).
- Şartlı önerme ve mantıksal denklik
  - $p\rightarrow q$ ("if p then q"); yalnız $p=1$, $q=0$ iken yanlıştır (ekrandan, 01:45:00).
  - $p$ hipotez (yeterli şart), $q$ sonuçtur (gerekli şart) (ekrandan, 01:50:00).
  - $p\rightarrow q\equiv p'\vee q$. $p\rightarrow p\equiv 1$, $p\rightarrow p'\equiv p'$, $p\rightarrow 1\equiv 1$, $p\rightarrow 0\equiv p'$.
  - Doğruluk tablolarındaki sonuç sütunları aynı olan iki önerme mantıksal olarak denktir.
  - Karşıt (converse) $q\rightarrow p$, ters (inverse) $p'\rightarrow q'$, karşıt ters (contrapositive) $q'\rightarrow p'$. Converse, $p\rightarrow q$'ya denk değildir (ekrandan, 01:55:00).
- Çift yönlü önerme, totoloji, çelişki ve De Morgan
  - $p\leftrightarrow q$ girişler aynıyken 1'dir; XOR'un tersidir. $p\leftrightarrow q\equiv(p\rightarrow q)\wedge(q\rightarrow p)\equiv(p'\vee q)\wedge(q'\vee p)$ (ekrandan, 02:05:00).
  - Totoloji: her satırda doğru olan önerme (ör. $p\rightarrow(p\vee q)$). Çelişki: her satırda yanlış olan önerme (ör. $p\wedge p'$).
  - De Morgan: $\sim(p\vee q)\equiv(\sim p)\wedge(\sim q)$, $\sim(p\wedge q)\equiv(\sim p)\vee(\sim q)$ (ekrandan, 02:10:00).
- Alıştırmalar: önermenin değilini yazma, sözel cümleyi sembolle yazma, $p\rightarrow q$ biçimine çevirme, converse yazma, değer verilen önermelerin sonucunu bulma ve totoloji kontrolü.

## Hocanın Özellikle Vurguladığı Kısımlar

- Doğruluk tablolarında T/F yerine 1/0 kullanılması
  - Lojik devrelerde de 1/0 kullanılacağı için şimdiden alışılması istendi.
- Tabloları ezberlemek yerine mantığını kurmak
  - VE için "bir giriş 0 ise sonuç 0", VEYA için "bir giriş 1 ise sonuç 1", XOR için "girişler farklıysa 1" kuralı yeterlidir.
  - $p\rightarrow q$ için "1 ise 0 durumu 0, diğerleri 1" kısa yoldur; asıl anlamı seçim vaadi örneğiyle anlatıldı: vaat yalnız şart sağlanıp sonuç gerçekleşmezse bozulur.
- Operatörleri birbiri cinsinden yazmak
  - XOR, ise ve ancak ve ancak bağlaçlarının yalnız VE, VEYA, DEĞİL ile yazılması bu dersin önemli konusudur. Bir programlama dilinde ilgili operatör yoksa bu açılımlar kullanılır.
- $p\rightarrow q\equiv p'\vee q$ eşdeğerliği
  - Hoca bunu bilinmesi gereken bir dönüşüm olarak vurguladı. De Morgan ise bağlacı için bu açılımdan sonra uygulanır.
- XOR'un kriptolojideki önemi
  - $p\oplus 1=p'$ olduğu için bir anahtarı bütün bitleri 1 olan bir diziyle XOR'lamak tersini verir; $p\oplus 0=p$ değeri korur.
- Converse, inverse ve contrapositive'in sözel ifadesi
  - Sınavda bir cümlenin karşıtı, tersi ve karşıt tersinin sözel olarak istenebileceği söylendi. Contrapositive ileride ispat yöntemlerinde kullanılacak.

## Kısa Tekrar Notları

- Ayrık matematik: süreklilik içermeyen yapılar; problemler varlık, sayma, optimizasyon türlerindedir.
- Sürekli $x(t)$, örneklenince ayrık $x[n]$ olur.
- $n$ şehirli turda başlangıç sabitse $(n-1)!$ sıralama vardır; büyük $n$ için kaba kuvvet imkânsızdır, yaklaşık (optimal) çözüm aranır.
- PERT: bitiş zamanı = öncüllerin en büyük bitiş zamanı + işin süresi; sondan geriye izlenen yol kritik yoldur.
- Önerme: doğru ya da yanlış olan ifade. $n$ değişken için $2^n$ satır.
- $p\wedge q$: ikisi de 1 ise 1. $p\vee q$: en az biri 1 ise 1. $p\oplus q$: farklıysa 1.
- $p\oplus q=(p\wedge q')\vee(p'\wedge q)$.
- $p\rightarrow q$ yalnız $1\rightarrow 0$ için 0; $p\rightarrow q\equiv p'\vee q$.
- $p\leftrightarrow q$ aynıysa 1; $\equiv(p\rightarrow q)\wedge(q\rightarrow p)$.
- Converse $q\rightarrow p$, inverse $p'\rightarrow q'$, contrapositive $q'\rightarrow p'$.
- Totoloji: hep 1. Çelişki: hep 0.
- De Morgan: $\sim(p\vee q)\equiv\sim p\wedge\sim q$, $\sim(p\wedge q)\equiv\sim p\vee\sim q$.

## Detaylı Açıklamalar

- **Sürekli ve ayrık.** Sürekli bir sinyalde her $t$ anı için bir değer vardır ve bu değerlerin sayısı sonsuzdur. Bilgisayar bu sinyali belirli aralıklarla örnekleyerek saklar: $x(t)$ yerine $x[n]$ tutulur. Örnek sayısı bilgisayarın kapasitesiyle sınırlıdır ve her örneğin değeri de gösterilebilir en yakın değere yuvarlanır. Fonksiyon biliniyorsa (ör. $x(t)=2\sin t$) değer tam hesaplanabilir, ama ölçümden gelen veride bu mümkün olmayabilir. Türev gibi işlemler de bu durumda sayısal ve ayrık yöntemlerle yapılır (ekrandan, 00:35:00).

- **Gezgin satıcı problemi.** Dört şehirde A'dan başlayıp her şehri bir kez ziyaret ederek A'ya dönen turlar: ABCDA, ACBDA, ACDBA vb. B, C, D'nin sıralaması $3!=6$ farklı tur verir. Her turun maliyeti yazılır ve en küçüğü seçilir; bunun için şehirler arası bağlantıların (topolojinin) bilinmesi gerekir. 81 il için başlangıç sabitlendiğinde $80!\approx 7{,}2\times10^{118}$ tur vardır, bu yüzden kesin çözüm yerine optimal (kabul edilebilir) çözüm aranır.
  - **Ders sonrası not:** Yol uzunlukları simetrikse her tur iki yönde aynı maliyeti verir; büyük olasılıkla farklı maliyetli tur sayısı $(n-1)!/2$'dir (4 şehirde 3). Hocanın verdiği 6 ve $80!$ yön ayrımı yapılan sayılardır.

- **PERT örneği (ekrandan, 00:45:00).** İşler ve süreleri: A=3, B=2, C=2, D=4, E=3, F=2, G=3, H=1, I=5, J=2, K=10. C, A ve B'den sonra başlar ve $\max(3,2)+2=5$'te biter. G: $5+3=8$, D: $5+4=9$, E: $5+3=8$. F, D ve E'yi bekler: $\max(9,8)+2=11$. H: $8+1=9$. I: $11+5=16$. J, H ve I'yı bekler: $\max(9,16)+2=18$. K: $18+10=28$. Toplam süre 28 gündür (30 günlük sınırın içinde). Kritik yol sondan geriye izlenir: K, J, I, F, D, C, A. Bu yoldaki bir işin gecikmesi bütün projeyi geciktirir. Gantt diyagramı da benzer amaçla kullanılır.

- **Önermeler ve bağlaçlar.** Önerme bir hüküm bildirir ve doğru ya da yanlıştır ("Bugün yağmur yağıyor"). Doğruluk değeri olmayan ifade (soru, emir) önerme değildir. Bağlaçlar önermeleri birleştirir. VE kesişime, VEYA birleşime, XOR simetrik farka karşılık gelir.
  - VE: elektrik devresinde seri bağlı iki anahtar; lamba yalnız iki anahtar da kapalıyken yanar. Örnek: "Kaplan vahşi bir hayvandır" (1) ve "Balina bir sürüngendir" (0) → $p\wedge q=0$.
  - VEYA: paralel bağlı anahtarlar; en az biri kapalıysa lamba yanar.
  - XOR: "ya ... ya da ..."; Türkçede "ya da". Devrede iki konumlu iki anahtarla (vavien bağlantısı) gerçeklenir. Örnek: "Ne Cüneyt programcıdır ne de Zeynep avukattır" ise $p\oplus q$ yanlıştır (ekrandan, 01:25:00).

- **XOR özdeşlikleri.** $p\oplus p'=1$ (girişler hep farklı), $p\oplus p=0$, $p\oplus 1=p'$ (tersleme, inversion), $p\oplus 0=p$ (aynalama, mirror). Hocanın kriptoloji örneğinde $111000\oplus111111=000111$ olur, yani anahtarın tersi elde edilir.

- **Üç değişkenli tablo.** $(p\vee q)\wedge r$ için 8 satır yazılır. VE bağlacı yüzünden $r=0$ olan bütün satırlar doğrudan 0'dır. $r=1$ satırlarında sonuç $p\vee q$'ya eşittir; yalnız $p=q=0$ iken 0 olur.

- **Şartlı önerme.** "Seçimi kazanırsam park yapacağım" vaadi: kazanıp yaparsa doğru; kazanıp yapmazsa yanlış; kazanmayıp yapmazsa da kazanmayıp yaparsa da vaat bozulmamıştır, doğru. Bu yüzden $p\rightarrow q$ yalnız $p=1,q=0$ iken 0'dır. Tabloda bu satırı yok etmek için $p'\vee q$ yazılır ve iki sütunun aynı olduğu gösterilir (ekrandan, 01:50:00). Aynı açılımla: $p\rightarrow p=p'\vee p=1$, $p\rightarrow p'=p'\vee p'=p'$, $p\rightarrow 1=1$, $p\rightarrow 0=p'$. $p\rightarrow q$ ile $q\rightarrow p$ denk değildir; tablolar yalnız $(1,0)$ ve $(0,1)$ satırlarında ayrılır.

- **Converse, inverse, contrapositive örneği.** $p$: "Bugün cumartesi", $q$: "Yarın pazar". Converse: "Yarın pazar ise bugün cumartesidir". Inverse: "Bugün cumartesi değilse yarın pazar değildir". Contrapositive: "Yarın pazar değilse bugün cumartesi değildir". Derste $p\rightarrow q$ ile inverse'in tabloları yazıldı, aynı çıkmadığı için denk olmadıkları gösterildi.

- **Çift yönlü önerme.** "Ancak ve ancak seçilirsem yaparım" ifadesinde seçilip yapmak ve seçilmeyip yapmamak doğrudur, diğer iki durum yanlıştır. XOR'un değili olduğu De Morgan ile de görülür: $\big((p'\wedge q)\vee(p\wedge q')\big)'=(p\vee q')\wedge(p'\vee q)$, bu da $(p\rightarrow q)\wedge(q\rightarrow p)$ açılımıdır.

- **Alıştırmalardan seçmeler (derste sözlü, 02:11:16; ekrandan, 02:15:00 ve 02:20:00).** "Bugün perşembe" önermesinin değili "Bugün pazartesi, salı, çarşamba, cuma, cumartesi ya da pazardır" olur. $2+1=3$'ün değili "$2+1<3$ ya da $2+1>3$"tür. "Dersten A almak, finalden A almak ve kitaptaki her alıştırmayı yapmakla sağlanır (yeterlidir)" cümlesi $(p\wedge q)\rightarrow r$, "Ancak ve ancak ya her alıştırmayı yaparsan ya da finalden A alırsan dersten A alırsın" cümlesi $r\leftrightarrow(p\vee q)$ olarak yazılır. $p$ doğru, $q$ yanlış, $r$ bilinmiyorsa $p\vee r$ ve $q\rightarrow r$ doğrudur; $p\wedge r$ ise $r$'ye eşittir. $[\sim p\wedge(p\rightarrow q)]\rightarrow\sim q$ totoloji değildir, $p=0,q=1$ satırında 0 olur.
  - **Ders sonrası not:** Slaytta "Dersten A almak için finalden A almak gereklidir" cümlesi $p\rightarrow r$ olarak yazılmıştı ve hoca da böyle okudu. Gerekli şart sonuç tarafında olduğu için doğrusu $r\rightarrow p$'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
