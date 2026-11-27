# Ders 5 Çalışma Özeti

## Genel Konular

- Ders anlatımı ağırlıkla İngilizce yapıldı, bazı açıklamalar Türkçe tekrar edildi.
  - Asıl anlatım yaklaşık 00:03:30'da başlar.
  - Araya iki ara verildi (yaklaşık 00:56:10-01:08:30 ve 01:59:50-02:10:20).
- Düzenli ifadeler (regular expressions)
  - Düzenli ifadeler düzenli dilleri, yani sonlu otomatların tanıdığı dilleri betimler.
  - İşlemler: birleşim ($+$), birleştirme ($\cdot$), Kleene yıldızı ($^*$) ve öncelik için parantez. Temel ifadeler: $\varepsilon$, $\emptyset$ ve alfabedeki tek tek semboller.
  - $(a+b\cdot c)^*$ ifadesi $\{a,bc\}^*=\{\varepsilon,a,bc,aa,abc,bca,\dots\}$ dilini betimler (ekrandan, 00:05:00).
  - $(a+b+)$ kurala uymadığı için düzenli ifade değildir (ekrandan, 00:10:00).
- Düzenli ifadenin dili $L(r)$
  - $L(r_1+r_2)=L(r_1)\cup L(r_2)$, $L(r_1\cdot r_2)=L(r_1)L(r_2)$, $L(r_1^*)=(L(r_1))^*$, $L((r_1))=L(r_1)$ (ekrandan, 00:20:00).
  - Basit ifadeler çok büyük, hatta sonsuz dilleri kısaca yazmayı sağlar: $|L((a+b)^*(a+bb))|=\infty$.
- Düzenli ifade ile dil arasında iki yönlü çeviri örnekleri
  - $(aa)^*(bb)^*b=\{a^{2n}b^{2m}b : n,m\ge 0\}$.
  - $(0+1)^*00(0+1)^*$: içinde $00$ geçen bütün dizgiler.
  - "00 ya da 010 içeren", "00 ve 010 içeren", "00 ya da 010 ile biten", "00 ya da 11 ile başlayan ya da biten", "00 ya da 11 ile başlayıp biten" ve "tek uzunluklu, 00 ya da 11 ile başlayıp biten" dizgiler.
  - $(1+01)^*(0+\varepsilon)$: içinde $00$ geçmeyen bütün dizgiler.
- Denk düzenli ifadeler
  - Dilleri aynı olan iki düzenli ifade denktir. Aynı dili betimleyen birden fazla ifade bulunabilir.
- Teorem: Düzenli ifadelerin ürettiği diller = düzenli diller
  - 1. kısım: her düzenli ifadenin dili düzenlidir (ifadenin boyu üzerinde tümevarım; birleşim, birleştirme ve yıldız için NFA kurma).
  - 2. kısım: her düzenli dil için bir düzenli ifade vardır (NFA'dan genelleştirilmiş geçiş grafına, durum silerek düzenli ifadeye).
- NFA'dan düzenli ifadeye dönüşüm örnekleri
  - Başlangıçtan kabul durumlarına giden yolları yazıp toplama, döngüleri Kleene yıldızıyla ekleme.
  - Genel durum silme kuralı ve iki durumlu son graftan ifade okuma.
- Düzenli dillerin standart gösterimleri: DFA, NFA, düzenli ifade.
- Düzenli olmayan diller ve makinenin gücü
  - $\{a^nb^m : n,m\ge 0\}$ bir DFA ile tanınır; $\{a^nb^n : n\ge 0\}$ için sonsuz sayıda durum gerekir, bu yüzden düzenli değildir.
  - Güvercin yuvası ilkesi, DFA'da durumların tekrar kullanılması ve döngü ile sonsuz dil ilişkisi. Pompalama önsavına hazırlık.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir dili düzenli ifadeye ve bir düzenli ifadeyi dile çevirebilmek gerekir.
  - Hoca "bu biçimde verilen bir dilin ifadesini yazabilmelisiniz" diyerek çok sayıda örnek çözdü ve "böyle bir sürü soru üretebiliriz" dedi.
- Bir kümeyle bir sembol doğrudan birleştirilemez.
  - $L$ yazılırken ifadenin her parçası önce kümeye çevrilir, sonra küme işlemleri uygulanır.
- Aynı dil için farklı ama doğru düzenli ifadeler yazılabilir.
  - Sınavda farklı öğrencilerin bulduğu farklı ifadelerin hepsi doğru olabilir. Daha sade olan ifade tercih edilir.
- Çözüm yazarken sınır durumlarını kontrol edin.
  - Tek uzunluklu dizgiler örneğinde bir öğrencinin uyarısıyla $000$ ve $111$ dizgileri ifadeye eklendi.
- NFA'dan ifade yazarken önce kabul durumuna giden yolu yazın, sonra o durumdaki döngüyü yıldızlı parantez içinde ekleyin.
- Bir NFA ya da DFA'da döngü varsa dil sonsuzdur.
  - Sonsuz bir dili sonlu sayıda durumla yakalamanın yolu bazı durumları birden çok kez kullanmaktır.

## Kısa Tekrar Notları

- Düzenli ifade işlemleri: $+$ (birleşim), $\cdot$ (birleştirme), $^*$ (Kleene yıldızı), parantez (öncelik).
- $\varepsilon$ boş dizgidir, $|\varepsilon|=0$.
- $L(r_1+r_2)=L(r_1)\cup L(r_2)$, $L(r_1r_2)=L(r_1)L(r_2)$, $L(r_1^*)=(L(r_1))^*$.
- $(0+1)^*$: $\{0,1\}$ alfabesindeki bütün dizgiler.
- "İçerir" için $(0+1)^*X(0+1)^*$, "ile biter" için $(0+1)^*X$, "ile başlar" için $X(0+1)^*$ kalıbı kullanılır.
- Tek uzunluk: $(0+1)((0+1)(0+1))^*$.
- $(1+01)^*(0+\varepsilon)=(0+\varepsilon)(1+10)^*$: $00$ içermeyen bütün dizgiler.
- Denk ifadeler: $L(r_1)=L(r_2)$.
- Teorem: düzenli ifadelerin dilleri tam olarak düzenli dillerdir.
- Durum silme: $q_i \xrightarrow{a} q \xrightarrow{b} q_j$ ve $q$'da $e$ döngüsü varsa yeni etiket $ae^*b$ olur.
- İki durumlu son graf için $r=r_1^*r_2(r_4+r_3r_1^*r_2)^*$.
- Standart gösterimler: DFA, NFA, düzenli ifade.
- $\{a^nb^n\}$ düzenli değildir; sonlu otomatın gücü buna yetmez.
- Döngü $\Rightarrow$ sonsuz dil. Güvercin yuvası ilkesi pompalama önsavının temelidir.

## Detaylı Açıklamalar

- **Düzenli ifadenin tanımı ve okunuşu.** Düzenli ifade, alfabedeki semboller ile $\varepsilon$'dan başlayıp birleşim, birleştirme ve Kleene yıldızı uygulanarak kurulur; parantez yalnızca öncelik verir. $(a+b\cdot c)^*$ ifadesinde üç sembol ($a,b,c$) vardır, $\Sigma=\{a,b,c\}$ alınır. İfade $\{a\}\cup\{bc\}=\{a,bc\}$ kümesinin yıldızıdır: $\{\varepsilon,a,bc,aa,abc,bca,\dots\}$. Hoca, ifadenin çok kısa, dilin ise sonsuz ve tek tek yazılamayacak kadar büyük olduğunu vurguladı. Bu yüzden analizde dilin kendisi yerine düzenli ifadesi kullanılır.
- **Bir otomatın dilini ifadeyle yazma (ilk örnek).** Ekrandaki makinede (ekrandan, 00:15:00) $q_0$'da $1$ döngüsü, $q_0\xrightarrow{0}q_1$, $q_1$'de $0$ döngüsü ve $q_1\xrightarrow{1}q_0$ geçişi vardır; kabul durumu $q_1$'dir. Hoca $1^*0+1^*00^*+1^*00^*1^*0$ gibi bir ifade yazıp fazlalık parçaları sildi. <!-- BELİRSİZ: Hocanın vardığı son sade ifade karede ve altyazıda net değil. -->
  - Ders sonrası not: bu makine tam olarak $0$ ile biten dizgileri kabul eder, yani dili $(0+1)^*0$'dır. Ekrandaki üç parçalı ifade bu dilin yalnız bir alt kümesidir; örneğin $0100$ dizgisini kapsamaz (python ile kontrol edildi).
- **Küme yazımı.** $(aa)^*(bb)^*b$ için $\{aa\}^*\{bb\}^*\{b\}$ yazılır; $a$ sayısı çift, $b$ sayısı tektir. $a$ ve $b$ sayıları birbirinden bağımsız olduğu için iki ayrı üs kullanılır: $\{a^{2n}b^{2m}b : n,m\ge 0\}$.
- **"İçerir", "biter", "başlar" kalıpları.** "00 ya da 010 içeren" dil $(0+1)^*(00+010)(0+1)^*$'dır (ekrandan, 00:35:00). Bir öğrencinin sorusu üzerine hoca, sondaki $(0+1)^*$ kaldırılırsa dilin "00 ya da 010 ile biten" dizgilere döneceğini açıkladı. "00 ve 010 içeren" dil için iki sıra (önce 00 ya da önce 010) birleşimle yazıldı: $(0+1)^*00(0+1)^*010(0+1)^* + (0+1)^*010(0+1)^*00(0+1)^*$. "00 ya da 010 ile biten" dil $(0+1)^*00+(0+1)^*010=(0+1)^*(00+010)$'dır (ekrandan, 00:40:00).
  - Ders sonrası not: "00 ve 010 içeren" ifadesi, iki alt dizginin üst üste bindiği $0100$ ve $0010$ gibi dizgileri kapsamaz. Tam ifade için $(0+1)^*(0100+0010)(0+1)^*$ terimi de eklenmelidir (python ile kontrol edildi).
- **Başlar ya da biter / başlar ve biter.** "00 ya da 11 ile başlayan ya da biten" dil $(00+11)(0+1)^*+(0+1)^*(00+11)$'dır (ekrandan, 00:45:00). "Başlar ve biter" olunca $(00+11)(0+1)^*(00+11)$ yazıldı; öğrenciler $00\dots11$ ve $11\dots00$ biçimlerinin de dahil olduğunu belirtti.
  - Ders sonrası not: $(00+11)(0+1)^*(00+11)$ ifadesi en az dört uzunluklu dizgileri üretir; $00$, $11$, $000$, $111$ dizgileri de "00 ya da 11 ile başlayıp biten" koşulunu sağlar ama ifadede yoktur (python ile kontrol edildi).
- **Tek uzunluklu dizgiler.** Dil $\{w : |w| \text{ tek}, w \text{ 00 ya da 11 ile başlar ve biter}\}$. Baştaki ve sondaki $(00+11)$ toplam 4 sembol verir, aradaki parçanın uzunluğu tek olmalıdır. Hoca bunun için iki durumlu bir DFA çizdi ($q_0\xrightarrow{0,1}q_1$, $q_1\xrightarrow{0,1}q_0$, kabul durumu $q_1$) ve ifadesini $r_x=(0+1)((0+1)(0+1))^*=(0+1)(00+01+10+11)^*$ diye okudu. Bir öğrenci $000$'ın da koşulu sağladığını söyledi; hoca $111$'i de ekledi. Sonuç: $r=(00+11)\,r_x\,(00+11)+000+111$ (ekrandan, 01:00:00). Python ile 10 uzunluğa kadar doğrulandı.
- **00 içermeyen dizgiler ve denk ifadeler.** $(1+01)^*$ boş dizgi ya da $00$ içermeyip $1$ ile biten dizgileri verir; sona $(0+\varepsilon)$ eklenince $00$ içermeyen bütün dizgiler elde edilir (ekrandan, 01:10:00 ve 01:15:00). $(1+10)^*$ ise boş dizgi ya da $00$ içermeyip $1$ ile başlayan dizgileri verir. Ekranda üç denk ifade yazıldı (ekrandan, 01:20:00): $r_1=(1+01)^*(0+\varepsilon)$, $r_2=(1^*011^*)^*(0+\varepsilon)+1^*(0+\varepsilon)$, $r_3=(0+\varepsilon)(1+10)^*$. Hoca $r_1$ ve $r_3$'ü daha sade bulduğunu söyledi. Üçünün de aynı dili verdiği python ile kontrol edildi.
- **Teoremin ispatı.** 1. kısımda tümevarım tabanı $\varepsilon$ ve tek sembol için birer küçük NFA'dır. Tümevarım varsayımı: $L(r_1)$ ve $L(r_2)$ düzenlidir. Düzenli diller birleşim, birleştirme ve yıldız altında kapalı olduğundan (önceki derste NFA kurulumlarıyla gösterildi) $L(r_1+r_2)$, $L(r_1r_2)$, $L(r_1^*)$ de düzenlidir. 2. kısımda $L$ düzenli olduğundan onu tanıyan, tek kabul durumlu bir NFA vardır. Bu NFA genelleştirilmiş geçiş grafına çevrilir (okların etiketleri düzenli ifade olur, örneğin $a,b$ yerine $a+b$), durumlar teker teker silinerek iki duruma inilir ve ifade okunur.
- **Genelleştirilmiş geçiş grafı örneği** (ekrandan, 01:30:00). $q_0\xrightarrow{b}q_1$, $q_1\xrightarrow{a}q_0$, $q_1$'de $b$ döngüsü, $q_1\xrightarrow{a+b}q_2$, $q_2$'de $b$ döngüsü; kabul durumu $q_2$. $q_1$ silinince $q_0$'da $bb^*a$ döngüsü ve $q_0\xrightarrow{bb^*(a+b)}q_2$ kalır. Sonuç: $r=(bb^*a)^*bb^*(a+b)b^*$ (python ile doğrulandı).
- **Yol sayarak ifade yazma.** Durumlar $q_0,q_1,q_2$; $q_0$'da $1$ döngüsü, $q_0\xrightarrow{0}q_1$, $q_0\xrightarrow{1}q_2$, $q_1$ ve $q_2$'de $1$ döngüsü, $q_2\xrightarrow{0}q_1$. Kabul durumu yalnız $q_1$ ise iki yol vardır: $1^*01^*+1^*11^*01^*$. $q_2$ de kabul durumu olunca $+1^*11^*$, $q_0$ da kabul durumu olunca $+1^*$ eklenir. Sonra $q_1\xrightarrow{0}q_0$ geçişi eklendi ve üç durumun hepsi kabul durumu yapıldı (ekrandan, 01:45:00 ve 01:50:00). Bu durumda her kabul durumu için "oraya ulaş, sonra o durumdaki döngüyü yıldızla" yöntemi uygulandı: $1^*(1^*11^*01^*01^*)^*+1^*11^*(1^*01^*01^*11^*)^*+1^*11^*01^*(1^*01^*11^*01^*)^*$. <!-- BELİRSİZ: Üçüncü terim karede tam görünmüyor, altyazıdaki sözlü anlatımdan kuruldu. --> Üç terimin birleşiminin makinenin diline eşit olduğu python ile kontrol edildi.
- **Genel durum silme kuralı.** $q_i\xrightarrow{a}q\xrightarrow{b}q_j$, $q$'da $e$ döngüsü, ayrıca $q_j\xrightarrow{c}q\xrightarrow{d}q_i$ yolu varsa $q$ silinir; yeni etiketler $ae^*b$ ($q_i\to q_j$), $ce^*d$ ($q_j\to q_i$), $ae^*d$ ($q_i$ döngüsü), $ce^*b$ ($q_j$ döngüsü) olur. İşlem iki durum kalana kadar sürer; son grafta $q_0$'da $r_1$, $q_f$'de $r_4$ döngüsü, $q_0\xrightarrow{r_2}q_f$ ve $q_f\xrightarrow{r_3}q_0$ varsa $r=r_1^*r_2(r_4+r_3r_1^*r_2)^*$ olur (ekrandan, 01:55:00).
- **Makinenin gücü.** $\{a^nb^m : n,m\ge 0\}$ dili için birkaç durumlu bir DFA yeterlidir; dilin ifadesi $a^*b^*$'dır. Bir öğrencinin önerisiyle hoca, ara durumun kaldırılıp başlangıç durumuna $a$ döngüsü konabileceğini kabul etti: aynı dili tanıyan birden çok makine olabilir. $m$ yerine $n$ yazılınca dil $\{a^nb^n : n\ge 0\}=\{\varepsilon,ab,aabb,\dots\}$ olur. Her $n$ için ayrı bir $a$ ve $b$ zinciri gerektiğinden sonsuz sayıda duruma ihtiyaç vardır; durum sayısı sonlu olduğundan bu dil için NFA ya da DFA yoktur, dil düzenli değildir. <!-- BELİRSİZ: a^n b^m için çizilen DFA'nın tam geçişleri karelerden okunamadı. -->
- **Güvercin yuvası ilkesi.** $n$ güvercin $m$ yuvaya konursa ve $n>m$ ise en az bir yuvada birden çok güvercin vardır. DFA'da her okunan sembolle bir duruma varılır; durumlar yuva, varışlar güvercindir. Ekrandaki 4 durumlu DFA'da (ekrandan, 02:35:00) $q_1$'de $b$ döngüsü, $q_1\xrightarrow{a}q_2$, $q_2$'de $b$ döngüsü, $q_2\xrightarrow{a}q_3$, $q_3\xrightarrow{a}q_2$, $q_3\xrightarrow{b}q_4$, $q_4$'te $b$ döngüsü, $q_4\xrightarrow{a}q_3$ vardır; kabul durumu $q_4$'tür. $aab$ okunurken her duruma bir güvercin düşer; $aabb$ okunurken $q_4$'te iki güvercin olur; $bbaabbb$ için $q_1$'de 2, $q_2$'de 1, $q_3$'te 1, $q_4$'te 3 güvercin olur. Sonsuz bir dili sonlu sayıda durumla tanıyabilmek için bazı durumlar tekrar tekrar kullanılmalıdır; bu da döngü demektir. Sonuç: NFA ya da DFA'da döngü varsa dil sonsuzdur; sonsuz bir düzenli dili tanıyan makinede de döngü bulunmalıdır. Bu fikir bir sonraki derste pompalama önsavında kullanılacak.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
