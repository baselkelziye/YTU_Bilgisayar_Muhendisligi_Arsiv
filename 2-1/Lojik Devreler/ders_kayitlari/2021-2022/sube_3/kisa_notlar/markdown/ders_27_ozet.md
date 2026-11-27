# Ders 27 Çalışma Özeti

## Genel Konular

- Ardışıl devrenin genel yapısı
  - Ardışıl devre, bir kombinezonsal lojik blok ile bir depolama elemanı biriminden oluşur. Depolama elemanları tutucu (latch) ya da flip-floptur (ekrandan, 00:05:00).
  - Kombinezonsal blok çok çıkışlı bir anahtarlama fonksiyonu gerçekler. Girişler dışarıdan gelen işaretler, çıkışlar dışarıya giden işaretlerdir. Depolama elemanlarından gelen işaretler şimdiki durum (present state), depolama elemanlarına giden işaretler sonraki durum (next state) olarak adlandırılır.
  - Depolama elemanı, kapı gecikmelerinden yararlanarak çıkışların girişe geri beslenmesiyle bir bitlik bilgiyi tutar.
- Senkron ve asenkron davranış
  - Senkron eleman, dışarıdan gelen bir saat (senkronizasyon) işareti olmadan girişteki değişimi çıkışa yansıtmaz. Asenkron eleman girişteki değişimi doğrudan çıkışa aktarır.
  - Hocanın çerçevesinde tutucular asenkron, flip-floplar senkron elemanlardır; tutucunun önüne saatle kontrol edilen kapılar eklenerek flip-flop elde edilir.
- NAND ile temel $\bar S$-$\bar R$ tutucu (ekrandan, 00:10:00)
  - Çapraz bağlı iki NAND kapısıyla kurulur; girişler sıfırda etkindir (aktif düşük).
  - Zaman sırası tablosu (slayttaki sırayla):

    | $R$ | $S$ | $Q$ | $\bar Q$ | Açıklama |
    |---|---|---|---|---|
    | 1 | 1 | ? | ? | Saklanan durum bilinmiyor |
    | 1 | 0 | 1 | 0 | $Q$ 1'e kuruldu (set) |
    | 1 | 1 | 1 | 0 | $Q$ 1'i hatırlıyor |
    | 0 | 1 | 0 | 1 | $Q$ 0'a sıfırlandı (reset) |
    | 1 | 1 | 0 | 1 | $Q$ 0'ı hatırlıyor |
    | 0 | 0 | 1 | 1 | İki çıkış da 1 (istenmeyen durum) |
    | 1 | 1 | ? | ? | Kararsız |

- NOR ile temel S-R tutucu
  - Girişler birde etkindir (aktif yüksek). $S=1$ ise $Q=1$, $R=1$ ise $Q=0$, $S=R=0$ ise önceki durum korunur, $S=R=1$ istenmeyen durumdur.
- Saatli S-R tutucu (S-R flip-flop) (ekrandan, 00:15:00)
  - $\bar S$-$\bar R$ tutucunun önüne, ortak girişi saat $C$ olan iki NAND kapısı daha konur. Böylece girişler aktif yüksek olur ve değişim yalnız saat geldiğinde çıkışa yansır.
  - Karakteristik tablo: $Q(t)\,S\,R = 000 \to 0$ (değişim yok), $001 \to 0$ (sıfırla), $010 \to 1$ (kur), $011 \to$ belirsiz, $100 \to 1$, $101 \to 0$, $110 \to 1$, $111 \to$ belirsiz.
- D flip-flop
  - S-R flip-flopun $S$ girişi $D$'ye, $R$ girişi bir değil kapısı üzerinden $\bar D$'ye bağlanır; tek giriş kalır.
  - Saat geldiğinde $Q(t+1) = D$ olur; önceki duruma bakılmaz ("data" flip-flop).
- JK flip-flop
  - $J$ kurma, $K$ sıfırlama girişine karşılık gelir. S-R'den tek farkı $J=K=1$ durumunda çıkışın tümleyenine dönmesidir: $Q(t+1) = \bar Q(t)$.
- T (toggle) flip-flop (ekrandan, 00:20:00)
  - Tek girişlidir. $T=0$ ise durum değişmez, $T=1$ ise durum tersine döner.
  - İki şekilde kurulabilir: D flip-flopun girişine $T \oplus Q$ veren bir XOR kapısı koyarak ya da JK flip-flopun $J$ ve $K$ girişlerini birleştirerek ($J=K=T$).
- Karakteristik tablo, karakteristik denklem ve uyarma (excitation) tablosu
  - D: $Q(t+1) = D$; uyarma: $Q(t+1)=0 \Rightarrow D=0$, $Q(t+1)=1 \Rightarrow D=1$.
  - T: $Q(t+1) = T \oplus Q$ (ekrandan, 00:25:00); uyarma: $Q(t+1)=Q(t) \Rightarrow T=0$, $Q(t+1)=\bar Q(t) \Rightarrow T=1$.
  - S-R uyarma tablosu ($Q(t) \to Q(t+1)$: $S\,R$): $0\to0$: $0\,X$; $0\to1$: $1\,0$; $1\to0$: $0\,1$; $1\to1$: $X\,0$.
  - JK uyarma tablosu ($Q(t) \to Q(t+1)$: $J\,K$): $0\to0$: $0\,X$; $0\to1$: $1\,X$; $1\to0$: $X\,1$; $1\to1$: $X\,0$.
- Zamanlama diyagramları ve tetikleme türleri (ekrandan, 00:30:00)
  - Yükselen kenar tetiklemede çıkış yalnız saatin yükselen kenarında, düşen kenar tetiklemede yalnız düşen kenarında güncellenir. Düzey tetiklemede saat düzeyi boyunca girişteki değişim çıkışa yansır.
  - Kenardan sonra çıkışta küçük bir gecikme görülür.
  - Aynı $D,T$ dalga biçimi uygulanan D ve T flip-floplarda $Q_D$ her kenarda o anki $D$ değerini alır, $Q_T$ ise yalnız $T=1$ olan kenarlarda tersine döner.
  - JK ve SR aynı girişlerle karşılaştırıldığında $1\,1$ girişinde SR için sonuç tanımsız, JK için çıkışın tümleyenidir.
- Master-slave yapısı
  - Hoca yalnız mantığını kısaca anlattı: tümleyen saatlerle sürülen iki flip-flop art arda bağlanır.
- Ardışıl devre analizi (ekrandan, 00:35:00)
  - Adım 1: Flip-flop girişlerine ve devre çıkışlarına ait Boole fonksiyonları devreye bakılarak yazılır.
  - Adım 2: Flip-flopların geçiş fonksiyonları kullanılarak sonraki durum fonksiyonları elde edilir.
  - Adım 3: Durum tablosu oluşturulur.
  - Adım 4: Durum diyagramı çizilir.
  - $n$ flip-flop en çok $2^n$ durum gösterir; durum sayısından gereken flip-flop sayısı bulunur (4 durum için 2, 8 durum için 3 flip-flop).
- Analiz örnekleri
  - Örnek 1 (iki D flip-flop, giriş $x$, çıkış $y$) (ekrandan, 00:40:00 ve 00:45:00): $A(t+1) = A x + B x$, $B(t+1) = \bar A x$, $y = \bar x (A + B)$.
  - Örnek 2 (girişsiz, üç D flip-flop $A,B,C$, çıkış $Z$): devre 0, 1, 2, 3, 4 durumları arasında döner; 5 ve 6 durumları 2'ye, 7 durumu 4'e gider.
  - Örnek 3 (iki D flip-flop) (ekrandan, 00:50:00): $D_0 = x \cdot \overline{Q_1 Q_0}$, $D_1 = x + \overline{Q_1 Q_0}$, $z = \overline{Q_1 Q_0}$.
  - Örnek 4 (iki JK flip-flop) (ekrandan, 00:55:00): $J_0 = \bar x + \bar Q_1$, $K_0 = Q_1$, $J_1 = Q_0$, $K_1 = \bar x \bar Q_0$, $z = Q_0 \bar Q_1$.
- Ardışıl devre sentezi (tasarımı)
  - Sözel tanımdan durum diyagramı, durum diyagramından durum tablosu çıkarılır; durum sayısından flip-flop sayısı belirlenir; flip-flopların uyarma tablolarına göre giriş fonksiyonları Karnaugh diyagramıyla sadeleştirilir ve devre kurulur.
  - Örnek: $x$ girişine 1010 dizisi gelince $z=1$ üreten devre, D flip-floplarla (ekrandan, 01:20:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Flip-flopların karakteristik tabloları, karakteristik denklemleri ve özellikle uyarma tabloları ezbere bilinmelidir.
  - Uyarma tablosu, istenen durum geçişi için flip-flop girişine ne gelmesi gerektiğini verir; sentezde Karnaugh diyagramları bu tablodan kurulur.
- D ve T flip-flopta uyarma tablosu kolaydır; S-R ve JK'da kayıtsız ($X$) girişler yüzünden daha dikkat ister.
  - JK ile tasarım derste örneklenmedi; hoca bunun ayrıca çalışılmasını istedi.
- Durum tablosundan Mealy mi Moore mu olduğunu ayırt etmek önemlidir.
  - Hoca Örnek 1'in tablosu için bu soruyu sordu ve bunun kesin soru olacağı bir konu olduğunu söyledi.
- D flip-flopta flip-flop girişi ile sonraki durum aynıdır; JK ve S-R'de aynı değildir, sonraki durum girişlerden karakteristik tabloyla bulunur.
- Durum tablosunda sonraki durumlar giriş değerlerine göre yan yana sütunlara yazılırsa (Gray sırası) tablo Karnaugh diyagramına doğrudan uyar.

## Kısa Tekrar Notları

- Ardışıl devre = kombinezonsal lojik + depolama elemanları; depolama elemanı şimdiki durumu tutar.
- NAND tutucu aktif düşük ($\bar S\bar R$), NOR tutucu aktif yüksek (SR).
- NAND tutucuda $00$, NOR tutucuda ve saatli SR'de $11$ istenmeyen girişlerdir.
- $Q_{D}(t+1) = D$, $Q_{T}(t+1) = T \oplus Q$; JK'da $11$ girişi tümler, SR'de $11$ tanımsızdır.
- JK uyarma: $0\,X$, $1\,X$, $X\,1$, $X\,0$. SR uyarma: $0\,X$, $1\,0$, $0\,1$, $X\,0$.
- T flip-flop = JK'da $J=K=T$ ya da D önüne XOR.
- Analiz: girişlerin Boole ifadeleri → sonraki durum denklemleri → durum tablosu → durum diyagramı.
- Sentez: sözel tanım → durum diyagramı → durum tablosu → Karnaugh → devre.
- $n$ flip-flop $2^n$ durum gösterir.
- Çıkış girişe bağlıysa Mealy, yalnız duruma bağlıysa Moore.

## Detaylı Açıklamalar

- **Tutucudan flip-flopa.** Çapraz bağlı iki NAND kapısının her biri diğerinin çıkışını giriş olarak alır; kapı gecikmeleri sayesinde bu geri besleme bir biti saklar. NAND ile kurulan tutucuda girişler sıfırda etkin olduğu için adı $\bar S$-$\bar R$ tutucudur: $S=0$ çıkışı 1'e kurar, $R=0$ çıkışı 0'a sıfırlar, $S=R=1$ önceki değeri korur. $S=R=0$ verilirse iki çıkış da 1 olur; $Q$ ile $\bar Q$ artık birbirinin tümleyeni değildir ve girişler sonra aynı anda 1'e dönerse sonucun ne olacağı bilinemez. NOR ile kurulan tutucuda mantık tersinedir: girişler birde etkindir ve $11$ istenmeyen durumdur. Saatli S-R tutucuda $\bar S\bar R$ tutucunun önüne iki NAND daha eklenir. Saat $C=0$ iken bu NAND'ların ikisi de 1 verir, tutucu önceki durumu korur. $C=1$ iken NAND'lar girişlerin tümleyenini iletir, böylece toplam yapı aktif yüksek bir SR elemanı gibi çalışır. Hoca bunu şöyle özetledi: saat gelmeden girişi değiştirmek çıkışı değiştirmez; örneğin $Q(t)=0$ iken $S=1, R=0$ yapılsa bile saat gelene kadar çıkış 0 kalır.
- **D, JK ve T flip-floplar.** D flip-flopta $S$ ve $R$ girişleri bir değil kapısıyla birbirine bağlanır; tek girişli bu elemanda saat geldiğinde çıkış girişin aynısı olur. JK flip-flop S-R'nin tanımsız durumunu kullanışlı hale getirir: $J=K=1$ iken çıkış tümleyenine döner. T flip-flop JK'nın iki girişi birleştirilerek elde edilir: $T=0$ JK için $00$ yani "değişme", $T=1$ ise $11$ yani "tümleyenini al" demektir. Aynı davranış D flip-flopun girişine $T \oplus Q$ verilerek de sağlanır, çünkü $T=0$ iken XOR çıkışı $Q$'yu aynen geçirir, $T=1$ iken tersler.

  > **Ders sonrası not:** Hoca NAND tutucudaki $00$ durumunda çıkışların "yüksek empedans" gösterdiğini söyledi. Doğrusu, bu durumda iki çıkış da lojik 1 olur; bu istenmeyen (yasak) durumdur, yüksek empedans (üçüncü durum) değildir.

- **Uyarma tablosunun mantığı.** Karakteristik tablo "girişe bunu verirsem sonraki durum ne olur" sorusunu, uyarma tablosu ise tersini, yani "bu geçişin olması için girişe ne vermeliyim" sorusunu cevaplar. Örneğin S-R'de $0 \to 0$ geçişi ya sıfırlama ($S=0,R=1$) ya da değişmeme ($S=0,R=0$) ile olur; ortak koşul $S=0$, $R$ ise önemsizdir: $0\,X$. JK'da $0 \to 1$ geçişi ya kurma ($1\,0$) ya da tümleme ($1\,1$) ile olur: $1\,X$. Sentezde her flip-flop girişi için bu tablolardan değer yazılıp Karnaugh diyagramı çizilir; flip-flopun önüne konacak kombinezonsal devre buradan çıkar.
- **Zamanlama diyagramı örneği (ekrandan, 00:30:00).** Yükselen kenar tetiklemeli D ve T flip-floplara aynı $D,T$ işareti verilir. Birinci kenarda giriş 1'dir: $Q_D$ 1 olur, $Q_T$ 0'dan 1'e döner. İkinci kenarda giriş 0'dır: $Q_D$ 0'a iner, $Q_T$ değişmez. Üçüncü kenarda giriş yine 1'dir: $Q_D$ 1'e çıkar, $Q_T$ 1'den 0'a döner. Dördüncü kenarda giriş 0'dır: $Q_D$ 0'a iner, $Q_T$ 0 kalır. Girişte kenarlar arasında olan değişimler çıkışı etkilemez.
- **Master-slave yapısı.** Hoca bu yapıyı ayrıntıya girmeden, tümleyen saatlerle sürülen iki flip-flopun art arda bağlanması olarak anlattı ve güncellemenin hem yükselen hem düşen kenarda alınmasıyla hızlanma sağlandığını söyledi.

  > **Ders sonrası not:** Master-slave yapısının amacı büyük olasılıkla hocanın söylediği gibi hızlanma değildir. Saatin bir düzeyinde ana (master) eleman girişi alır, diğer düzeyinde yardımcı (slave) eleman bunu çıkışa aktarır; böylece çıkış saat periyodu başına bir kez değişir ve tutucunun saydamlığından doğan yarış durumları önlenir.

- **Analiz örnekleri.** Örnek 1'de $A(t+1) = Ax + Bx$, $B(t+1) = \bar A x$, $y = \bar x (A+B)$ denklemleri yazılıp durum tablosu kurulur (ekrandan, 00:45:00). $x=0$ iken bütün durumlar $00$'a gider; $x=1$ iken $00 \to 01$, $01 \to 11$, $10 \to 10$, $11 \to 10$ olur. Çıkış $x=0$ iken $00$ dışındaki durumlarda 1, $x=1$ iken her zaman 0'dır. Örnek 2 girişsizdir: elektrik verildiğinde devre kendiliğinden durumlar arasında döner. Altyazıya göre $A(t+1) = BC$, $B(t+1) = B \oplus C$, $Z = BC$'dir; devre $0 \to 1 \to 2 \to 3 \to 4 \to 0$ çevriminde döner, 5 ve 6 durumları 2'ye, 7 durumu 4'e gider. <!-- BELİRSİZ: Örnek 2'nin C(t+1) denklemi altyazıda okunmuyor ve bu anın karesi yok; anlatılan geçişler C(t+1) = A'C' ile tutarlıdır (python ile kontrol edildi), ama slayttaki ifade doğrulanamadı. --> Örnek 3'te D flip-flop olduğu için flip-flop girişleri doğrudan sonraki durumdur; tablo ayrıntısı genişletilmiş nottadır. Örnek 4'te JK flip-floplar kullanıldığı için önce $J_1K_1$, $J_0K_0$ değerleri bulunur, sonra her flip-flopun sonraki durumu JK karakteristik tablosuyla hesaplanır (ekrandan, 01:15:00).
- **Sentez örneği.** 1010 dizisini tanıyan devrede dört durum vardır: $d_0$ (bekleniyor: 1), $d_1$ (1 geldi), $d_2$ (10 geldi), $d_3$ (101 geldi). Beklenmeyen bit geldiğinde devre ya başa ya da dizinin yeniden başlayabileceği uygun duruma döner; örneğin $d_1$'de tekrar 1 gelirse $d_1$'de kalınır, $d_3$'te 1 gelirse $d_1$'e geçilir. $d_3$'te 0 gelince $z=1$ olur ve $d_0$'a dönülür. Dört durum için iki D flip-flop yeterlidir; D'de giriş sonraki duruma eşit olduğundan $D_1, D_0$ sütunları doğrudan sonraki durumdan yazılır ve $x, Q_1, Q_0$'a göre Karnaugh diyagramlarıyla sadeleştirilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
