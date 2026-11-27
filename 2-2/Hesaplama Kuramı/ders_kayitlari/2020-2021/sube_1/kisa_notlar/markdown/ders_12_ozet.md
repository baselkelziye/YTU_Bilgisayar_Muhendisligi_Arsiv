# Ders 12 Çalışma Özeti

## Genel Konular

- Ders ağırlıkla İngilizce anlatıldı, bazı açıklamalar Türkçe yapıldı. Örnekler tablette el yazısıyla çözüldü, son bölümde slaytlara geçildi.
  - Akademik bölümler yaklaşık 00:01:15-00:53:00 (Turing makinesi tasarım örnekleri), 01:04:45-01:44:00 (sıralama yapan Turing makinesi ve sözde kod) ve 01:44:00-02:23:30 (Turing tezi, algoritma tanımı, Turing makinesi çeşitleri) aralığındadır. Arada ders arası verildi.
- Düzenli ifadeden Turing makinesi tasarlama
  - $r = 0^*10(0+1)^*$, $\Sigma=\{0,1\}$, şerit alfabesi $\Gamma=\{0,1,\$\}$; burada $\$$ boşluk (blank) sembolüdür (ekrandan, 00:05:00).
  - Makine: $q_0 \xrightarrow{\$\to\$,R} q_1$; $q_1$ üzerinde $0\to0,R$ döngüsü ($0^*$); $q_1 \xrightarrow{1\to1,R} q_2 \xrightarrow{0\to0,R} q_3$ (kabul) (ekrandan, 00:10:00 ve 00:15:00).
  - $(0+1)^*$ kısmı için ayrıca bir şey çizmeye gerek yoktur: $10$ okunduğunda kabul durumuna varılır ve Turing makinesi kabul durumuna varınca durur, dizgi kabul edilir. Kabul durumundan dışarı geçiş yoktur.
  - $r=0^*10$ olsaydı $q_3$ kabul durumu olmaz, ondan sonra boşluk okunması beklenirdi: $q_3 \xrightarrow{\$\to\$,L} q_4$ (kabul) (ekrandan, 00:15:00).
  - Boşluk sembolü yalnız bir gösterimdir; $\$$, $\#$ ya da baklava (elmas, $\diamond$) seçilebilir.
- $r=(a+b)^*aa(a+b)^*$ için Turing makinesi (ekrandan, 00:20:00)
  - Turing makinesi deterministiktir; NFA'daki gibi $(a+b)^*$ için tek bir döngü koyup ardından $aa$ beklenemez.
  - Çözüm fikri: $q_1$'de $b$ okundukça kalınır, $a$ okununca $q_2$'ye geçilir; $q_2$'de $b$ gelirse $q_1$'e dönülür, ikinci $a$ gelirse kabul durumuna ($q_3$) gidilir. <!-- BELİRSİZ: son diyagram karede görünmüyor; geçişler altyazıdaki anlatımdan kuruldu. -->
- $L=\{0^{2^n} \mid n\ge 0\}$ için Turing makinesi (ekrandan, 00:25:00-00:45:00)
  - $\varepsilon\notin L$, $0, 00, 0000, 00000000 \in L$; $000, 00000, 000000, 0000000 \notin L$.
  - Bu dil düzenli değildir, bağlamdan bağımsız da değildir; yalnız bir Turing makinesi tanıyabilir.
  - Fikir: her turda sıfırların yarısı $x$ ile işaretlenir (bir sıfır kalır, bir sıfır $x$ olur). Sayı her turda ikiye bölünebiliyorsa ve sonunda tek sıfır kalıyorsa dizgi kabul edilir. Şerit alfabesi $\Gamma=\{x,0,\diamond\}$.
  - Hesaplama izleri: $00$ kabul edilir, $000$ reddedilir.
- Sıralama yapan Turing makinesi (ekrandan, 00:50:00-01:20:00)
  - $\Sigma=\{a,b\}$ üzerindeki bir dizgi, bütün $a$'lar bütün $b$'lerden önce gelecek şekilde yeniden düzenlenir. Örnek: $abaabbbbabb \to aaaabbbbbbb$, $bbba \to abbb$.
  - Algoritma: $b$'lerden sonra gelen ilk $a$ bulunur ve kendisinden önceki $b$ ile yer değiştirir (yani "$ba$" bloğu "$ab$" yapılır), sonra dizginin başına dönülür. Böyle bir $a$ kalmayınca dizgi sıralanmıştır.
- $L=\{0^n1^n2^n \mid n\ge 0\}$ için sözde kod (implementation-level description) (ekrandan, 01:25:00-01:40:00)
  - $L \subset L(0^*1^*2^*)$ gözlemiyle başlanır; her turda en soldaki $0$, $1$ ve $2$ birer $x$ yapılır.
- Turing tezi ve algoritma (ekrandan, 01:45:00 ve 01:50:00)
  - Turing tezi: mekanik yollarla yapılabilen her hesaplama bir Turing makinesiyle yapılabilir.
  - Bir problem için algoritma, o problemi çözen bir Turing makinesidir.
- Turing makinesi çeşitleri (ekrandan, 02:15:00 ve 02:20:00)
  - Standart model: iki yönde sonsuz şerit, okuma-yazma kafası, sola ya da sağa hareket, deterministik kontrol birimi.
  - Çeşitler: kalma seçeneği (stay-option), yarı sonsuz şerit, çok şeritli, çok boyutlu, deterministik olmayan Turing makineleri.
  - Bu sınıfların hepsi standart Turing makinesiyle aynı güçtedir. Aynı güç, aynı dil kümesini kabul etmek demektir.
  - Benzetim (simulation) ile ispat: $M_2$, $M_1$'i benzetebiliyorsa $M_2$'nin gücü $M_1$'inkinden küçük değildir; iki yönde de benzetim varsa güçler eşittir ve $L(M_1)=L(M_2)$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Turing makinesi kabul durumuna varınca durur ve girdiyi kabul eder.
  - Bu yüzden düzenli ifadenin sonundaki $(0+1)^*$ gibi "geri kalan her şey" kısımları için ayrıca durum çizmek gerekmez.
- Turing makinesinde algoritma kurarken kafayı hep dizginin bir başına bir sonuna götürmek gerekir.
  - Ortadan bir yerden başlanırsa konum kaybedilir; baş-son taraması daha hatasız algoritma verir.
- Sıralama makinesinde $b$'lerden sonraki **ilk** $a$ seçilmelidir.
  - Sondaki $a$ seçilince ($aababa$ örneğinde) iki $a$ yan yana gelip algoritma bozuldu; hoca bu yüzden "ilk $a$" kuralına döndü.
- Sıralama makinesi gibi sorular final sınavında çıkabilecek türdendir; bunları iyi öğrenmek gerekir.
- Kod yazmak yalnız hazır kütüphane çağırmak değildir.
  - "Sıralama için kütüphane kullanırım" cevabı yetmez; kütüphanesiz bir sıralama algoritması kurabilmek, yani algoritma geliştirme becerisi gerekir. Bunun temeli hesaplama kuramıdır.
- Sözde koddan Turing makinesi diyagramına geçişi öğrenciler kendileri yapmalıdır; yapılmazsa Turing makinesi öğrenilemez.
- Bir dilin bağlamdan bağımsız olup olmadığına desendeki bağıntı sayısına bakarak hızlıca karar verilebilir.
  - $0^n1^n2^n$'de üç bağıntı vardır, bağlamdan bağımsız değildir. $0^n1^n$ ya da $0^n1^{2n}$'de tek bağıntı vardır, bağlamdan bağımsızdır.

## Kısa Tekrar Notları

- Turing makinesi geçiş etiketi: $a\to b,R$ = "$a$ oku, $b$ yaz, sağa git". Kabul durumuna varınca makine durur.
- $0^*10(0+1)^*$: $q_0 \xrightarrow{\$\to\$,R} q_1 (0\to0,R) \xrightarrow{1\to1,R} q_2 \xrightarrow{0\to0,R} q_3$ (kabul).
- $0^*10$: aynı makine, ama $q_3 \xrightarrow{\$\to\$,L} q_4$ (kabul) eklenir.
- $0^{2^n}$: düzenli değil, bağlamdan bağımsız değil. Her turda sıfırların yarısı $x$ yapılır; tek sıfır kalırsa kabul, tur ortasında sıfır sayısı tek çıkarsa red.
- Sıralama: $b$'lerden sonraki ilk $a$ ile önceki $b$ yer değiştirir, başa dönülür, tekrar edilir.
- $0^n1^n2^n$: önce $0^*1^*2^*$ deseni denetlenir; sonra her turda bir $0$, bir $1$, bir $2$ işaretlenir; sıfır kalmayınca $1$ ya da $2$ kalmışsa red, yoksa kabul.
- Turing tezi: mekanik her hesaplama bir Turing makinesiyle yapılabilir. Algoritma = problemi çözen Turing makinesi.
- Dil hiyerarşisi: düzenli (DFA, NFA, düzenli ifade) $\subset$ bağlamdan bağımsız (PDA) $\subset$ Turing makinesinin tanıdıkları.
- Kalma seçenekli, yarı sonsuz şeritli, çok şeritli, çok boyutlu ve deterministik olmayan Turing makineleri standart modelle aynı güçtedir; ispat benzetimle yapılır.

## Detaylı Açıklamalar

- **Düzenli ifadeden Turing makinesi.** Tasarım NFA/DFA tasarımına benzer, ama her geçişte okunan sembol, yazılan sembol ve kafanın hareketi yazılır. $0^*10(0+1)^*$ için başlangıçta boşluk ($\$$) okunup sağa geçilir. $q_1$'deki $0\to0,R$ döngüsü $0^*$'ı, ardından gelen iki geçiş $1$ ve $0$'ı tanır. $10$ okunduğu anda dizgi dile girmiş olur, çünkü geri kalan her şey $(0+1)^*$ ile eşleşir. Bu yüzden $q_3$ kabul durumu yapılır ve makine orada durur. İfade $0^*10$ olsaydı $10$'dan sonra dizginin bitmesi, yani boşluk okunması gerekirdi. O zaman $q_3$'ten $\$\to\$,L$ ile yeni bir kabul durumu $q_4$'e geçilir. Örnek elemanlar: $10, 010, 0010, 0\cdots010, 0\cdots0101 \in L(r)$; $\varepsilon, 0 \notin L(r)$.
- > **Ders sonrası not:** Hoca, döngü içeren makine için "undecidable" (karar verilemez), döngüsüz makine için "decidable" dedi (00:16:25). Bir durumda kendine dönen geçiş olması makineyi karar verilemez yapmaz. Bu makinelerin her adımı kafayı sağa götürür ve sonlu girdi bitince makine durur. Yani makine her girdide durur ve dili karar verir (decide). Düzenli dillerin hepsi karar verilebilirdir.
- **$(a+b)^*aa(a+b)^*$.** NFA'da $(a+b)^*$ için tek bir döngü koymak yeterlidir, çünkü makine "hangi $a$'nın $aa$'nın başı olduğunu" tahmin edebilir. Turing makinesi deterministik olduğundan bu yapılamaz: $q_1$'de $a\to a,R$ döngüsü varken bir de $q_1$'den $a$ ile çıkış yazılamaz. Bu yüzden son okunan sembol durumlarda tutulur: $q_1$'de "son sembol $a$ değil", $q_2$'de "son sembol $a$" bilgisi vardır. $q_2$'de ikinci bir $a$ gelirse $aa$ bulunmuştur ve kabul durumuna gidilir. Gerisi yine $(a+b)^*$ olduğundan ayrıca durum gerekmez. Bu tasarım tüm kısa dizgilerde python ile denenmiş ve doğru çıkmıştır.
- **$0^{2^n}$ makinesi.** Geçişler (ekrandan, 00:40:00 ve 00:45:00):

  ```text
  q1 : 0 -> ◇,R  => q2        ◇ -> ◇,R => q_reject
  q2 : x -> x,R  (döngü)      ◇ -> ◇,R => q_accept     0 -> x,R => q3
  q3 : x -> x,R  (döngü)      0 -> 0,R => q4           ◇ -> ◇,L => q5
  q4 : x -> x,R  (döngü)      0 -> x,R => q3           ◇ -> ◇,R => q_reject
  q5 : 0 -> 0,L , x -> x,L (döngü)                     ◇ -> ◇,R => q2
  ```

  İlk sıfır boşlukla ($\diamond$) değiştirilir; böylece kafa geri dönerken dizginin başını tanır. $q3$ ile $q4$ arasında gidip gelirken sıfırlar sırayla bırakılır ve $x$ yapılır, yani sıfırların yarısı silinir. Sağ uçta sıfır sayısı tekse ($q4$'te boşluk) dizgi reddedilir. Çiftse $q5$ ile başa dönülür ve yeni tura başlanır. $q2$'de yalnız $x$ görüp boşluğa ulaşmak tek sıfır kaldığını gösterir ve kabul edilir.
- **Hesaplama izleri** (ekrandan, 00:40:00 ve 00:45:00):
  - $00$: $q_1 00 \succ \diamond q_2 0 \succ \diamond x q_3 \diamond \succ \diamond q_5 x \succ q_5 \diamond x \succ \diamond q_2 x \succ \diamond x q_2 \diamond \succ \diamond x \diamond q_{accept}$. Kabul.
  - $000$: $q_1 000 \succ \diamond q_2 00 \succ \diamond x q_3 0 \succ \diamond x 0 q_4 \diamond \succ q_{reject}$. Red.
  - Yazımda dizginin iki yanındaki sonsuz boşluklar yazılmaz.
- **Sıralama makinesi.** Boşluk sembolü $\#$, $\Gamma=\{a,b,\#\}$ (ekrandan, 01:20:00):

  ```text
  q0 : a -> a,L , b -> b,L (döngü)    # -> #,R => q1     (dizgi başına dön)
  q1 : a -> a,R (döngü)               b -> b,R => q2     # -> #,L => kabul
  q2 : b -> b,R (döngü)               a -> b,L => q3
  q3 : b -> a,L => q0
  ```

  $q1$ baştaki $a$'ları geçer, ilk $b$ ile $q2$'ye girer; $q2$ $b$'leri geçer. Bir $a$ bulunursa $b$ yazılır, bir sola gidilir ve oradaki $b$ $a$ yapılır; böylece "$ba$" "$ab$" olur ve $q0$ ile başa dönülür. Dizgi boşsa ya da yalnız $a$'lardan oluşuyorsa $q1$'de $\#$ görülür ve kabul edilir.
  - > **Ders sonrası not:** Hoca, $b$'lerden sonra hiç $a$ kalmamışsa da boşluk okunup kabul edilmesi gerektiğini söyledi (01:20:01), ama bu geçiş karede görünmüyor. Bu geçiş ($q2$'de $\# \to \#,L$ ile kabul) olmazsa $ab$ ya da $bbb$ gibi zaten sıralı dizgiler kabul edilmez. Makine bu geçişle birlikte python'da 9 uzunluğa kadar bütün $\{a,b\}$ dizgilerinde denendi ve hepsini doğru sıraladı.
- **$0^n1^n2^n$ için sözde kod.** Tahtadaki adımlar (ekrandan, 01:40:00), hocanın yeniden numaralandırmasıyla:
  1. Girdiyi soldan sağa tara, $w \in L(0^*1^*2^*)$ olduğunu denetle; değilse reddet.
  2. Kafayı şeridin sol ucuna (w'nin soluna) geri getir.
  3. Şeride hiç $0$ kalmayana kadar şunları tekrarla:
  4. En soldaki $0$'ı $x$ yap.
  5. Bir $1$ görene kadar sağa tara; hiç $1$ yoksa reddet.
  6. En soldaki $1$'i $x$ yap.
  7. Bir $2$ görene kadar sağa tara; hiç $2$ yoksa reddet.
  8. En soldaki $2$'yi $x$ yap.
  9. Kafayı sol uca geri getir ve 3. adıma dön.
  10. Şeritte hâlâ $1$ ya da $2$ varsa reddet; yoksa kabul et.
  <!-- BELİRSİZ: 7-10. adımların karesi yok; metin altyazıdaki anlatımdan kuruldu. -->

  Bu sözde kod python ile denendi: 8 uzunluğa kadar bütün $\{0,1,2\}$ dizgilerinde yalnız $0^n1^n2^n$ biçimindekileri (boş dizgi dahil) kabul ediyor. Sözde koddan diyagrama geçiş derste yapılmadı, öğrencilere bırakıldı.
- **Turing tezi ve algoritma.** Hoca Turing tezini, mekanik araçlarla yapılan hesaplamaların Turing makinesinin adımlarına (okuma, yazma, sağa ve sola gitme) çevrilebileceği diye açıkladı. Bir algoritma vardır demek, onu yürüten ve problemi çözen bir Turing makinesi vardır demektir. Turing makinesi yoksa o problem için algoritma da yoktur. Hoca dil sınıflarını iç içe kümelerle gösterdi: en içte düzenli diller (DFA, NFA, düzenli ifade), onu kapsayan bağlamdan bağımsız diller (PDA), onu kapsayan Turing makinesiyle ve programlama dillerinde yazılan sözde kodlarla ifade edilenler (ekrandan, 02:05:00).
- **Turing makinesi çeşitleri ve benzetim.** Kalma seçeneği olan makinede kafa sola ve sağa gitmenin yanında olduğu yerde de kalabilir; örneğin $q_1$'de $a$ okunur, $b$ yazılır, $q_2$'ye geçilir ve kafa yer değiştirmez. Yarı sonsuz şeritte şeridin başı vardır ama sonu yoktur. Çok şeritli makinede birden fazla şerit, çok boyutlu makinede yukarı ve aşağı hareket de vardır. Bu çeşitlerin hepsi standart Turing makinesiyle aynı dil kümesini kabul eder. Bu yüzden kuram standart model üzerinde kurulur; standart model için gösterilen bir sonuç diğerleri için de geçerlidir. Aynı güç şöyle tanımlanır: birinci sınıftaki her $M_1$ için ikinci sınıfta $L(M_1)=L(M_2)$ olan bir $M_2$ vardır (ve tersi). Benzetimde orijinal makinenin her $d_i$ yapılandırmasına benzetim makinesinde bir $d_i'$ yapılandırması karşılık gelir. Bir adım birkaç adımla taklit edilebilir; bu yüzden hesaplama $\succ^*$ ile yazılır. Güç adım sayısına göre değil, kabul edilen dile göre tanımlanır. Ders, "kalma seçenekli makineler standart Turing makineleriyle aynı güçtedir" teoreminin ispat planı verilirken bitti: (1) kalma seçenekli makineler standart makineleri benzetir, (2) standart makineler kalma seçenekli makineleri benzetir (ekrandan, 02:25:00). İspat sonraki derse kaldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
