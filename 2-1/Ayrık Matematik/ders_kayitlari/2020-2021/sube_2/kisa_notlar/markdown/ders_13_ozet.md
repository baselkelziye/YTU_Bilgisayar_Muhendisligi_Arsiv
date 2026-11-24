# Ders 13 Çalışma Özeti

## Genel Konular

- Sonlu durum makinelerinin dersteki yeri
  - Konu bu derste kısa bir giriş olarak işlenir; ayrıntısı sonraki dönemdeki hesaplama kuramı dersinde, onun üzerine de biçimsel diller ve derleyici tasarımı derslerinde görülür.
  - Hesaplama kuramı, yazılan programın üzerinde çalışacağı makinenin modeliyle ilgilenir: örneğin derleyicinin bir `for` döngüsünün kuralını nasıl tanıyacağı. En basit makinelerden daha karmaşık makinelere doğru ilerlenir.
- RAM modeli
  - Bugün C gibi dillerde kullandığımız makine modeli RAM (rastgele erişimli bellek) modelidir: program kodu rastgele erişilebilen bir belleğe kopyalanır.
  - Sıralı erişimli bellekte (teyp, kaset) bir ifadeyi tanımak için şeridin karakter karakter ileri geri sarılması gerekirdi; bu performansı düşürür. Rastgele erişim bu işi kolaylaştırır.
- Günlük hayattan örnek: turnike
  - Turnikenin iki durumu vardır: kapalı ve açık. Kapalıyken jeton atmak turnikeyi açar; açıkken turnikeden geçmek onu kapatır.
  - Açıkken jeton atılırsa ne olacağı da tanımlanmalıdır (örneğin jeton geri verilir). Hoca, bu geçiş tanımlanmazsa makineye deterministik olmayan dediğini söyledi (bkz. "Ders sonrası not").
  - Bazı metrolarda üç durumlu turnike vardır: bilet verilir, bilet geri alınınca turnike açılır, kişi geçince başlangıç durumuna dönülür. Bilet alınmadan durum değişmez; geçişten hemen sonra durum değiştiği için aynı anda iki kişi geçemez.
  - Durumlar bir grafın düğümleri, geçişler kenarlarıdır. Kenar etiketi iki parçalıdır: gelen olay (girdi) ve sonuçta oluşan çıkış.
- Mealy ve Moore makineleri
  - Çıkış üreten iki tür sonlu durum makinesi vardır: Mealy ve Moore (ekrandan, 00:10:00).
  - Mealy makinesinde çıkış hem o anki duruma hem de o anki girdiye bağlıdır. Ekrandaki kaynakta 6'lı $(Q,\Sigma,O,\delta,X,q_0)$ ile tanımlanır: $\delta: Q\times\Sigma\to Q$ geçiş fonksiyonu, $X: Q\times\Sigma\to O$ çıkış fonksiyonu.
  - Hoca, Moore makinesinde durumun içinde ek bir bilgi (çıkış) tanımlandığını söyledi. Ayrıntılar lojik devreler ve hesaplama kuramı derslerinde verilir.
  - Hepsinin ortak özelliği sonlu sayıda duruma sahip olmalarıdır. Dil ve konuşma tanıma da örnek uygulamalardır.
- Sonlu durum makinesinin tanımı (ekrandan, 00:15:00)
  - $M=(I,O,S,f,g,\sigma)$ 6'lısı: $I$ giriş sembollerinin sonlu kümesi, $O$ çıkış sembollerinin sonlu kümesi, $S$ sonlu durumlar kümesi, $f: S\times I\to S$ gelecek durum fonksiyonu, $g: S\times I\to O$ çıkış fonksiyonu, $\sigma$ başlangıç durumu.
  - Bunlara ek olarak bir de kabul durumu vardır. İfadenin sonunda kabul durumuna ulaşılırsa ifade kabul edilir. Diyagramda kabul durumu iç içe iki daireyle çizilir.
  - Düzenli ifade örneği: $a^*b^*c^*$ istenen sayıda $a$, sonra $b$, sonra $c$ içeren dizgileri tanımlar ($abc$, $abbc$, $abcc$, $aabcc$ kabul).
  - Hoca $a^k b^l c^m$, $0<k<l<m$ kuralını da örnek verdi: $abbccc$ kabul, $aabbccc$ kabul değil.
- Durum tablosu ve deterministik makine
  - Geçiş ve çıkış fonksiyonları graf (durum diyagramı) ya da tablo ile gösterilir; tablo yöntemi lojikteki flip-flop tablolarına benzer.
  - Örnek: girdi $\{a,b\}$, çıkış $\{0,1\}$, durumlar $\sigma_0,\sigma_1$. $\sigma_0$'da $a$ gelirse $\sigma_0$'da kalınır, çıkış 0; $b$ gelirse $\sigma_1$'e geçilir, çıkış 1.
  - Deterministik makine: her durumda her girdi için gidilecek durum ve çıkış bellidir; belirsiz bir şey yoktur. Sonraki dönem deterministik ve deterministik olmayan sonlu otomatlar (DFA, NFA) ayrı ayrı incelenir.
- Çıkış dizisini bulma
  - Beş durumlu ($s_0$-$s_4$) bir makineye $101011$ girdisi verildiğinde izleme $s_0\to s_3\to s_1\to s_2\to s_3\to s_0\to s_3$, çıkış $001000$ olur. <!-- BELİRSİZ: Bu makinenin diyagramının karesi yok; girdi ve geçişler altyazıdan alındı. -->
- Sağa bir kez öteleme yapan makine (ekrandan, 00:25:00)
  - Durumlar $S_0$ (başlangıç), $S_1$, $S_2$. Geçişler (girdi, çıkış): $S_0\xrightarrow{1,0}S_1$, $S_0\xrightarrow{0,0}S_2$, $S_1\xrightarrow{1,1}S_1$, $S_1\xrightarrow{0,1}S_2$, $S_2\xrightarrow{1,0}S_1$, $S_2\xrightarrow{0,0}S_2$.
  - $S_1$ "son gelen bit 1", $S_2$ "son gelen bit 0" anlamına gelir; çıkış bir önceki girdidir. Makine diziyi bir bit sağa öteler, başa 0 koyar: $01\to 00$.
- Seri toplama
  - İki tabanda toplama yapan makinede girdi bit çiftleridir ($00,01,10,11$), çıkış 0 ya da 1'dir. İki durum vardır: $s_0$ eldesiz, $s_1$ eldeli ($x+y$ ya da $x+y+1$ toplanır). Bu örnek derste tamamlanmadı.
- Giriş (login) makinesi (ekrandan, 00:30:00)
  - Girdiler: $v$ geçerli ID, $i$ geçersiz ID, $p$ geçerli parola, $q$ geçersiz parola. Çıkışlar: $a$ Enter User ID, $b$ Enter Password, $c$ prompt. $x$ herhangi bir girdi.
  - $s_0\xrightarrow{i,a}s_0$, $s_0\xrightarrow{v,b}s_1$, $s_1\xrightarrow{q,a}s_0$, $s_1\xrightarrow{p,c}s_2$, $s_2\xrightarrow{x,c}s_2$.
- Dört karakterli değişken adı denetleyicisi (ekrandan, 00:40:00 ve 00:45:00)
  - Kurallar: ad 4 karakterlidir; ilk karakter dışındakiler rakam olabilir; $0$-$9$, $A$-$Z$, $a$-$z$ dışındaki karakterler geçersizdir; $\Sigma$ geçersiz karakterleri gösterir.
  - $S_0$'da $\Sigma$ ya da $0$-$9$ gelirse $S_0$'da kalınır; harf gelirse $S_1$'e geçilir. $S_1$, $S_2$, $S_3$'te $\Sigma$ gelirse aynı durumda kalınır; harf ya da rakam gelirse bir sonraki duruma geçilir. $S_4$ kabul durumudur.
  - Denemeler: `0Abc` ve `Ab#c` $S_3$'te kalır, kabul edilmez; `A1ad` $S_4$'e ulaşır, kabul edilir.
- Art arda üç 1 gelince hata veren makine (ekrandan, 00:40:00)
  - Her 1 yeni bir duruma geçirir: $s_0\xrightarrow{1/0}s_1\xrightarrow{1/0}s_2$; $s_2$'de üçüncü 1 gelince çıkış 1 olur ve aynı durumda kalınır. Her 0 makineyi $s_0$'a döndürür (çıkış 0).

## Hocanın Özellikle Vurguladığı Kısımlar

- Konu ezber değildir
  - Kabul durumu ve diyagram gösterimi kullanıla kullanıla öğrenilir; ayrıntılara sonraki dönem girilecektir.
- Dört karakter kuralı neden ayrı durumlar ister
  - Harf geçişi tek durum üzerinde kendine döndürülseydi sonsuz uzunlukta ad kabul edilirdi; dört karakter şartı ancak $S_1$-$S_4$ zinciriyle sağlanır.
  - Önemli olan ifadenin sonunda kabul durumuna ulaşmaktır. Karakter sayısını ayrıca saklamaya gerek yoktur; durumlar bunu zaten belirtir.
  - Problem "yanlış karakterde baştan gir" deseydi bütün $\Sigma$ geçişleri $S_0$'a gönderilirdi.
- Diyagramlar algoritmanın çözümlenmesini ve analizini sağlar; lojik devrelerde de bu yüzden kullanılır.
- Bu dersin konuları (graflar, ağaçlar, yığın, kuyruk, bağlı listeler, özyineleme) veri yapıları, algoritma analizi ve hesaplama kuramının temelidir. Hoca bu algoritmaları öğrencilerin kendilerinin kodlamasını önerdi (C ya da Java); örneğin merge sort ve quick sort güzel özyinelemeli uygulamalardır.

## Kısa Tekrar Notları

- SDM: $M=(I,O,S,f,g,\sigma)$; $f$ sonraki durum, $g$ çıkış, $\sigma$ başlangıç durumu; kabul durumu çift daire.
- Mealy: çıkış duruma ve girdiye bağlı, kenarda yazılır. Moore: çıkış durumun içinde tanımlanır.
- Deterministik: her (durum, girdi) çifti için tek bir sonraki durum ve çıkış.
- Turnike: kapalı --jeton--> açık --geçiş--> kapalı.
- Sağa öteleme makinesinde çıkış bir önceki girdidir; ilk çıkış 0.
- Seri toplayıcı: $s_0$ eldesiz, $s_1$ eldeli.
- Art arda üç 1: $s_0\to s_1\to s_2$, $s_2$'de 1 gelirse çıkış 1; her 0 başa döndürür.
- Değişken adı: $S_0$ harf bekler, $S_1$-$S_3$ harf/rakam ile ilerler, $\Sigma$ ile bekler, $S_4$ kabul.

## Detaylı Açıklamalar

- Sonlu durum makinesi, sonlu sayıda durum arasında girdilere göre geçiş yapan ve her geçişte bir çıkış üretebilen soyut bir modeldir. Turnike örneğinde durumlar "kapalı" ve "açık"tır; jeton atma ve geçme olaylar (girdiler), turnikenin açılıp kapanması da sonuçtur. Durumları graf düğümleri, geçişleri kenarlar olarak çizince durum diyagramı elde edilir. Kenar etiketi "girdi, çıkış" biçimindedir: hangi olay olunca hangi duruma geçileceğini ve çıkışta ne görüleceğini birlikte söyler.
- Ders sonrası not: Hoca, açıkken jeton atılması gibi tanımlanmamış bir geçiş olduğunda makineye deterministik olmayan dendiğini söyledi. Büyük olasılıkla daha doğru ifade şudur: tanımlanmamış geçişi olan makine eksik tanımlı (kısmi) bir makinedir; deterministik olmama ise aynı durumda aynı girdi için birden fazla sonraki durumun mümkün olmasıdır.
- Biçimsel tanımda $f: S\times I\to S$ her durum-girdi çifti için bir sonraki durumu, $g: S\times I\to O$ çıkışı verir (ekrandan, 00:15:00). Bu fonksiyonlar diyagram yerine tablo ile de verilebilir: satırlar durumlar, sütunlar $f$ ve $g$ altında her girdi değeridir. Hoca bunu lojikte flip-flopların Karnaugh haritasıyla denklemlerini çıkarmaya benzetti.
- Ders sonrası not: Hoca $a^k b^l c^m$ ($0<k<l<m$) dilini tanıyan otomat örneği verdi. Büyük olasılıkla bu dil sonlu durum makinesiyle tanınamaz, çünkü $a$, $b$ ve $c$ sayılarını karşılaştırmak sınırsız bellek ister; $a^*b^*c^*$ ise düzenli bir dildir ve sonlu durum makinesiyle tanınır.
- Sağa öteleme örneğinde ekrandaki el yazısı tablo şöyledir (ekrandan, 00:25:00):

  | Durum | $f$, girdi 1 | $f$, girdi 0 | $g$, girdi 1 | $g$, girdi 0 |
  | :---: | :---: | :---: | :---: | :---: |
  | $S_0$ | $S_1$ | $S_2$ | 0 | 0 |
  | $S_1$ | $S_1$ | $S_2$ | 1 | 1 |
  | $S_2$ | $S_1$ | $S_2$ | 0 | 0 |

  Hangi durumdan gelinirse gelinsin 1 girdisi $S_1$'e, 0 girdisi $S_2$'ye götürür; çıkış ise yalnız bulunulan duruma bağlıdır. Böylece her adımın çıkışı bir önceki girdi olur ve ilk çıkış 0'dır. Python ile kontrol edildi: $01\to 00$, $1101\to 0110$.
- Giriş makinesinde (ekrandan, 00:30:00) $s_0$ kullanıcı ID'si bekler. Geçersiz ID ($i$) gelirse yeniden ID istenir ($a$) ve $s_0$'da kalınır. Geçerli ID ($v$) gelince parola istenir ($b$) ve $s_1$'e geçilir. $s_1$'de geçersiz parola ($q$) ID girişini yeniden başlatır ($a$, $s_0$'a dönüş); geçerli parola ($p$) komut ortamını açar ($c$, $s_2$). $s_2$'de her komuttan sonra yeniden prompt'a dönülür.
- Değişken adı makinesinde denemeler (ekrandan, 00:45:00) Python ile kontrol edildi: `0Abc` için $0$ $S_0$'da bırakır, $A,b,c$ ile $S_3$'e gelinir; `Ab#c` için `#` $S_2$'de bekletir, $c$ ile $S_3$'e gelinir; ikisi de kabul edilmez. `A1ad` $S_1,S_2,S_3,S_4$ sırasıyla kabul durumuna ulaşır.
- Art arda üç 1 makinesinde her 1 bir sonraki durumu açar; üçüncü 1'de çıkış 1 olur ve $s_2$'de kalındığı için ardından gelen her 1 de çıkış 1 verir. 0 gelirse sayım baştan başlar. Hoca lojik derslerinde örtüşen (overlap) dizilerin ayrıca incelendiğini, flip-floplarla devresinin kurulduğunu hatırlattı. Derste örnek girdi olarak $01001110000$ verildi ve çıkışın sorulabileceği söylendi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
