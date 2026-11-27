# Ders 26 Çalışma Özeti

## Genel Konular

- Ardışıl devrelerin yapısının tekrarı
  - Ardışıl devre, bir kombinezonsal devre ile bir saklama (depolama) biriminden oluşur. Saklama birimi tutucu (latch) ya da flip-flop ile kurulur (ekrandan, 00:05:00).
  - Kombinezonsal kısmın girişleri dış girişler ve saklama biriminden gelen şimdiki durumdur (present state). Çıkışları ise dış çıkışlar ile saklama birimine giden bir sonraki durumdur (next state).
  - Kombinezonsal devrede doğruluk tablosunun her satırı yalnız o anki girişlere bakar. Ardışıl devrede ise önceki durum da saklanır ve çıkışı belirlemekte kullanılır (örneğin bir sayıcının bir sonraki sayıyı üretebilmesi için şimdiki sayıyı bilmesi gerekir).
- Mealy ve Moore makineleri
  - Mealy: $z(t) = f\big(d(t), x(t)\big)$, $d(t+1) = f\big(d(t), x(t)\big)$. Çıkış hem duruma hem girişe bağlıdır (ekrandan, 00:10:00).
  - Moore: $z(t) = f\big(d(t)\big)$, $d(t+1) = f\big(d(t), x(t)\big)$. Çıkış yalnız duruma bağlıdır.
  - Bir sonraki durumu belirleyen fonksiyon iki modelde de aynıdır; fark yalnız çıkış fonksiyonundadır.
- Senkron ve asenkron ardışıl devreler
  - Senkron devrede saklama birimleri girişlerini yalnız ortak bir saat işaretinin (clock pulse) belirli anlarında gözler ve durum değiştirir (ekrandan, 00:15:00). İşlemci ve DDR bellekler senkron ardışıl devrelere örnektir.
  - Asenkron devrede belirli bir frekans yoktur; davranış girişlerin herhangi bir andaki değerine ve değişme sırasına bağlıdır. Slaytta "saat başka bir giriş gibi görülürse bütün devreler asenkrondur" notu yer alır.
  - Tetikleme yükselen kenarda, düşen kenarda ya da seviyede olabilir. Güncelleme tetiklemeden hemen sonra değil, bir gecikme sonra çıkışa yansır.
- Kapı gecikmesiyle veri saklama
  - 0,5 ns gecikmeli iki girişli VE-DEĞİL (NAND) kapısında anlık çıkış $F(I)$ ile gecikmeli çıkış $F$ karşılaştırılır (ekrandan, 00:20:00). Girişteki değişiklikten sonra eski değer 0,5 ns boyunca çıkışta kalır; yani gecikme kısa süreli bir saklama sağlar.
  - Gecikme modeli: DEĞİL 0,2 ns, VE 0,4 ns, VEYA 0,5 ns.
- 2'ye 1 çoğullayıcıda (MUX) gecikme ve glitch
  - $S = 0$ iken $Y = A$, $S = 1$ iken $Y = B$ (ekrandan, 00:25:00).
  - $S$ 0'dan 1'e geçince $B$ yolunun gecikmesi $0{,}4 + 0{,}5 = 0{,}9$ ns olur. $S$ 1'den 0'a geçince $\bar S$ 0,2 ns geç yükselir; bu arada iki VE kapısının da bir girişi 0 olduğundan çıkışta kısa bir sıfır darbesi (glitch) oluşur.
- Durum saklama: çıkışın girişe geri beslenmesi
  - $A$ girişi $Y$'ye bağlanırsa: $S = 1$ iken $Y = B$, $S = 0$ iken $Y(t) = Y(t - 0{,}9)$ olur; devre önceki değeri tutar (ekrandan, 00:30:00).
  - Geri besleme bir DEĞİL kapısı (0,2 ns) üzerinden yapılırsa $S = 0$ iken çıkış her $0{,}4 + 0{,}5 + 0{,}2 = 1{,}1$ ns'de bir terslenir; osilasyon yapan kararsız bir devre elde edilir.
- Durumlar, durum tablosu ve durum diyagramı
  - Durum, problemdeki adımlardır: 0'dan 7'ye sayan devrede 0, 1, …, 7 değerleri; adres tarifinde geçilen noktalar (ekrandan, 00:40:00).
  - Durum tablosu doğruluk tablosuna benzer: şimdiki durum ve girişler sol tarafta (giriş gibi), bir sonraki durum ve çıkışlar sağ tarafta (çıkış gibi) yer alır. Sonraki durum $A(t+1)$ ya da $A'$ ile gösterilir.
  - Devre kurulurken sonraki durumun her biti ve her çıkış için ayrı Karnaugh haritası yapılır, sadeleşmiş fonksiyonlar flip-floplarla gerçeklenir.
  - Durum diyagramında her durum bir çemberdir; şimdiki durumdan sonraki duruma giden yönlü ok bir durum geçişidir ve okun üzerinde geçişe yol açan giriş yazılır (ekrandan, 00:50:00).
  - Mealy gösteriminde çıkış ok üzerine "giriş/çıkış" biçiminde, Moore gösteriminde çemberin içine "durum/çıkış" biçiminde yazılır. Moore gösteriminde genelde bir durum fazladan gerekir.
- Dizi tanıyıcı (şifre) örnekleri
  - 1110 şifresi: (a) şifre bulunduğunda başlangıç durumuna dönen ve (b) çıkışı kilitleyen iki durum diyagramı (ekrandan, 01:00:00).
  - 1101 dizisini örtüşmeli (overlapping) tanıyan Mealy makinesi ve aynı problemin Moore modeli (ekrandan, 01:10:00, 01:20:00).
  - 011010 şifresini çözüp çıkışı kilitleyen sonlu durum makinesi (ekrandan, 01:25:00).
- Tutucular ve flip-floplar
  - VE-DEĞİL kapılarıyla kurulan $\bar S \bar R$ tutucusu sıfırda aktiftir; $\bar S \bar R = 00$ tanımsız, $11$ ise önceki durumu korur. VEYA-DEĞİL (NOR) kapılarıyla kurulan SR tutucusu birde aktiftir; $SR = 00$ önceki durumu korur, $11$ tanımsızdır.
  - Bu tutucular asenkrondur. Önüne saat girişli iki VE-DEĞİL kapısı eklenince saatli SR tutucusu elde edilir.
  - SR tutucusuna bir DEĞİL kapısı eklenince D tutucusu elde edilir: $Q(t+1) = D$, tanımsız durum yoktur (ekrandan, 02:00:00).
  - JK flip-flopu: $Q(t+1) = J\bar Q + \bar K Q$; $JK = 11$ durumunda çıkışın tersini alır (ekrandan, 02:10:00).
  - T flip-flopu: $Q(t+1) = T \oplus Q$; JK'nın iki girişi birleştirilerek ya da D flip-flopunun önüne bir XOR kapısı konarak gerçeklenir (ekrandan, 02:05:00).
  - Karakteristik tablo, girişlere göre sonraki durumu verir. Uyarma (excitation) tablosu ise istenen $Q(t) \to Q(t+1)$ geçişi için girişlerin ne olması gerektiğini verir ve tasarımda kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Moore gösterimi de öğrenilmeli
  - Öğrenciler kombinezonsal devre alışkanlığıyla Mealy gösterimini daha kolay benimser; ama hoca Moore gösteriminin de mutlaka öğrenilmesi gerektiğini tekrar tekrar söyledi.
- Durum tablosunu doğru kurmak
  - Durum tablosu, sorunun doğru anlaşılıp anlaşılmadığının denetlendiği yerdir ve bütün devre tasarımı bu tablodaki 1'lerden yapılan Karnaugh haritalarına dayanır.
- Ara durumların davranışı
  - Dizi tanıyıcı sorularında doğru yolu çizmek kolaydır. Asıl önemli olan, yanlış bit geldiğinde her ara durumun nereye gideceğini ve örtüşen dizilerin kaçırılmamasını analiz etmektir.
- Uyarma tablosu
  - Hoca uyarma tablosunun karakteristik tablodan daha önemli olduğunu, ezberlenmese bile anlamının kavranması gerektiğini ve sorularda çokça kullanılacağını söyledi.
- Saat işaretinin önemi
  - D flip-flopunda girişteki değişiklikler saat tetiklenene kadar çıkışa yansımaz. Butonla sayan bir devrede saat butona basma süresinden çok hızlı olduğu için tek basışta birkaç durum atlanabilir.

## Kısa Tekrar Notları

- Ardışıl devre = kombinezonsal devre + saklama birimi (tutucu/flip-flop).
- Mealy: çıkış = f(durum, giriş); Moore: çıkış = f(durum). Sonraki durum ikisinde de f(durum, giriş).
- Senkron: ortak saat, belirli anlarda güncelleme; asenkron: saat yok, girişlerin değişimine bağlı.
- Gecikme modeli: DEĞİL 0,2 ns, VE 0,4 ns, VEYA 0,5 ns.
- MUX'ta $S$ 1'den 0'a inerken $\bar S$ gecikmeli yükseldiği için glitch oluşur.
- $A = Y$ geri beslemesiyle MUX 0,9 ns'lik bir saklama yapar; DEĞİL üzerinden geri beslenirse 1,1 ns'de bir terslenen osilatör olur.
- Durum tablosu: sol = şimdiki durum + giriş, sağ = sonraki durum + çıkış.
- Durum diyagramı: Mealy'de "x/y" ok üzerinde; Moore'da "durum/y" çember içinde. Moore'da genelde bir durum fazla.
- Örtüşmeli 1101 tanıyıcıda D durumunda 1 gelince çıkış 1 olur ve B'ye dönülür; C'de 1 gelince C'de kalınır.
- NAND $\bar S\bar R$ tutucusu: 00 tanımsız; NOR SR tutucusu: 11 tanımsız.
- $Q_D(t+1) = D$, $Q_T(t+1) = T \oplus Q$, $Q_{JK}(t+1) = J\bar Q + \bar K Q$.
- Uyarma tabloları: SR için $0\to0$: $S{=}0, R{=}X$; JK için $0\to0$: $0X$, $0\to1$: $1X$, $1\to0$: $X1$, $1\to1$: $X0$.

## Detaylı Açıklamalar

Ardışıl devreler, kombinezonsal devrelere bir saklama birimi eklenerek elde edilir. Kombinezonsal devrede doğruluk tablosunun her satırı yalnız o anki girişlerle çıkışı ilişkilendirir. Ardışıl devrede ise saklama biriminde tutulan şimdiki durum da kombinezonsal kısma giriş olarak girer ve kombinezonsal kısım hem dış çıkışları hem de saklama birimine yazılacak bir sonraki durumu üretir. Örneğin 1'den 10'a sayan bir devre, bir sonraki sayıyı üretebilmek için o anda hangi sayıda olduğunu bilmek zorundadır.

Çıkışın nasıl üretildiğine göre iki model vardır. Mealy makinesinde çıkış $z(t) = f\big(d(t), x(t)\big)$ biçiminde hem şimdiki duruma hem girişe bağlıdır. Moore makinesinde ise çıkış $z(t) = f\big(d(t)\big)$ biçiminde yalnız duruma bağlıdır. Bir sonraki durum iki modelde de $d(t+1) = f\big(d(t), x(t)\big)$ ile bulunur. Hoca çıkışı bir LED'i yakmak ya da trafik ışığında yeşil süresinin bittiğini bildiren bir kontrol sinyali gibi düşünmeyi önerdi; durumlar ise ışığın kırmızıdan sarıya, sarıdan yeşile geçtiği adımlardır.

Senkron ardışıl devrelerde bütün saklama birimleri ortak bir saat işaretiyle tetiklenir. İşlemcilerin "2,8 GHz" gibi saat frekansları, sistemi saniyede yaklaşık 2,8 milyar kez tetikleyebildiklerini gösterir. DDR bellekler de verilerin belirli frekansta yenilendiği senkron devrelerdir. Asenkron devrelerde dışarıdan bir saat gelmez; bir düğmeye basılması gibi bir dış giriş güncellemeyi başlatır ve gecikmeler birbirinden farklı olabilir.

Saklamanın lojik düzeyde nasıl mümkün olduğunu görmek için kapı gecikmeleri incelenir. 0,5 ns gecikmeli NAND kapısında $A = B = 1$ iken çıkış 0'dır. $t = 0$'da $A$ 0'a inince anlık çıkış hemen 1 olur, ama gerçek çıkış 0,5 ns boyunca 0'da kalır. $t = 0{,}8$ ns'de $A$ yeniden 1 olunca anlık çıkış 0'a döner, gerçek çıkış ise $0{,}8 + 0{,}5 = 1{,}3$ ns'ye kadar 1'de kalır (ekrandan, 00:20:00). Demek ki kapı gecikmesi, girişteki değişiklikten sonra eski değeri kısa bir süre saklar.

Aynı fikir 2'ye 1 çoğullayıcıda daha belirgin görülür. $S = 1$ yapılınca $B$ değeri VE (0,4 ns) ve VEYA (0,5 ns) üzerinden 0,9 ns sonra çıkışa ulaşır. $S$ 1'den 0'a indirildiğinde $\bar S$ DEĞİL kapısının gecikmesi yüzünden 0,2 ns geç yükselir. Bu kısa aralıkta iki VE kapısının da bir girişi 0 olduğu için çıkışta istenmeyen bir sıfır darbesi (glitch) oluşur. $A$ girişi $Y$'ye bağlanırsa devre $S = 0$ iken kendi çıkışını geri okur ve $Y(t) = Y(t - 0{,}9)$ olur; yani bilgi saklanır. Geri besleme bir DEĞİL kapısı üzerinden yapılırsa çıkış her 1,1 ns'de bir terslenir ve devre osilasyon yapar.

Durum tablosu, doğruluk tablosunun ardışıl devre karşılığıdır. 0'dan 7'ye sayıp tek sayılarda çıkışı 1 yapan devrede şimdiki durumlar $A B C$ = 000 … 111, sonraki durumlar bir fazlasıdır ve çıkış sütunu sonraki durumun tek olduğu satırlarda 1'dir (ekrandan, 00:45:00). Devre kurulurken $A'$, $B'$, $C'$ ve $Z$ için ayrı Karnaugh haritaları yapılır.

Durum diyagramında Mealy ve Moore'un farkı, çıkışın yazıldığı yerdir. Mealy'de ok üzerinde "x/y" yazılır; Moore'da çıkış durum çemberinin içine yazılır. Moore'da çıkış girişe bağlanamadığı için, "dizi tamamlandı" bilgisini taşıyan ayrı bir durum gerekir; bu yüzden genelde bir durum fazla olur. 1101 tanıyıcısında Mealy dört durumla (A, B, C, D) çalışırken Moore beş durum (A–E) gerektirir.

Dizi tanıyıcı sorularında doğru yol önce çizilir, sonra her durumda yanlış bit gelince nereye gidileceği belirlenir. Örtüşmeli 1101 tanıyıcıda D'de 1 gelince hem çıkış 1 olur hem de bu son 1 yeni dizinin ilk 1'i sayılarak B'ye gidilir. C'de (iki 1 görülmüşken) bir 1 daha gelirse son iki bit hâlâ 11 olduğu için C'de kalınır. A, B ve D'de 0 gelince A'ya dönülür.

Tutucular ve flip-floplar saklama biriminin temel yapı taşlarıdır. NAND ile kurulan $\bar S\bar R$ tutucusu sıfırda aktiftir ve 00 girişi tanımsızdır; NOR ile kurulan SR tutucusu birde aktiftir ve 11 girişi tanımsızdır. SR tutucusunun önüne saat girişli iki NAND eklenince saatli SR elde edilir. D tutucusu, SR'nin R girişine DEĞİL kapısıyla D'nin tersi verilerek elde edilir; tek giriş olduğundan tanımsız durum oluşmaz ve $Q(t+1) = D$ olur. JK flip-flopu SR'nin 11 tanımsızlığını tümleme işlemine çevirir. T flip-flopu $T = 0$'da durumu korur, $T = 1$'de tersler; JK'nın iki girişi birleştirilerek ya da D flip-flopunun önüne $T \oplus Q$ üreten bir XOR konarak gerçeklenir. Tasarımda asıl kullanılan, istenen geçiş için girişlerin ne olması gerektiğini veren uyarma tablolarıdır; "X" değerleri Karnaugh haritasında don't care olarak kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
