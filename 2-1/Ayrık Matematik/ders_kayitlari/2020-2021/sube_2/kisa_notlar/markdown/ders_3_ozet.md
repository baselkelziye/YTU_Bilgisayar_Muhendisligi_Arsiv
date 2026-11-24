# Ders 3 Çalışma Özeti

## Genel Konular

- Bool cebri (Boole cebri), mantığın bir uygulaması olarak
  - Bilgisayarda bütün bilgi 0 ve 1 ile saklanır; komutların arkasındaki işlemler mantık kapılarıyla gerçekleştirilir. Bool cebri bu kapıların matematiğidir.
  - $B=\{0,1\}$ üzerinde üç temel işlem vardır: Bool toplamı ($+$, OR), Bool çarpımı ($\cdot$, AND) ve tümleyen ($\overline{x}$, NOT).
  - Örnek (ekrandan, 01:25:00): $1\cdot 0+\overline{(0+1)} = 0+\overline{1} = 0+0 = 0$.
- Bool ifadeleri ve Bool fonksiyonları
  - $x$ yalnız $B$'den değer alıyorsa Bool değişkenidir. $F: B^n \to B$ fonksiyonu $n$. dereceden Bool fonksiyonudur.
  - Fonksiyonun değeri doğruluk tablosuyla bulunur. Örnek: $F(x,y,z)=xy+\overline{z}$ (ekrandan, 00:20:00).
  - İki Bool fonksiyonu, bütün girdilerde aynı değeri veriyorsa eşittir. Örneğin $xy$, $xy+0$ ve $xy\cdot 1$ denktir.
  - $(F+G)(x)=F(x)+G(x)$ ve $(FG)(x)=F(x)G(x)$; çarpım dağılma özelliğiyle açılır.
  - $n$ değişkenli $2^n$ farklı girdi dizisi, dolayısıyla $2^{2^n}$ farklı Bool fonksiyonu vardır (ekrandan, 00:30:00).
- Bool cebrinin özdeşlikleri (ekrandan, 00:35:00)
  - Çift tümleyen, eş kuvvetlilik (idempotent), birim (identity), baskınlık (domination), değişme, birleşme, dağılma, De Morgan, yutma (absorption), birim özelliği ($x+\overline{x}=1$), sıfır özelliği ($x\overline{x}=0$).
  - Derste eklenen kurallar: $x+\overline{x}y = x+y$ ve $x(\overline{x}+y)=xy$.
  - XOR ve XNOR'un açılımları.
- Doğruluk tablosundan Bool ifadesi bulma
  - Fonksiyonun 1 olduğu her satır bir çarpım terimi (minterm) verir; bu terimler toplanır: çarpımların toplamı (sum of products, SOP).
  - Değişken ya da tümleyenine öge (literal) denir.
  - Sonra ifade sadeleştirilir, çünkü her terim fiziksel bir devre, alan ve güç kaybı demektir.
- Mantık kapıları ve devreler
  - Üç temel kapı: inverter (NOT), OR, AND. Uygulamada NAND, NOR (evrensel kapılar), XOR ve XNOR da kullanılır. OR ve AND çok girişli olabilir.
  - İfadelerden devre çizimi örnekleri ve iki bitlik yarım toplayıcı (half adder).
- Karnaugh haritaları
  - İki, üç ve dört değişkenli haritalar; sütun ve satır etiketleri her adımda tek bit değişecek biçimde sıralanır: 00, 01, 11, 10.
  - 1'ler $2^0, 2^1, 2^2, \dots$ büyüklüğünde gruplanır; grup içinde değişen değişken yazılmaz, değişmeyen yazılır.
  - $\sum m(\dots)$ gösterimi, çözümlü örnekler ve not ağırlıklarından geçme devresi örneği.

## Hocanın Özellikle Vurguladığı Kısımlar

- $2^{2^n}$ formülü
  - $n$ değişkenle $2^n$ girdi durumu, bu durumlar üzerinden $2^{2^n}$ fonksiyon tanımlanır. 5 değişken için $2^{32}$ fonksiyon vardır. Hoca bunu "önemli" diye işaretledi.
- Temel özdeşlikler ve De Morgan
  - Çift tümleyen, eş kuvvetlilik, birim ve baskınlık en çok kullanılan kurallardır.
  - De Morgan ile bir ifadenin değili alınırken her terimin değili alınır ve AND ile OR yer değiştirir. Programdaki `if` koşulları da bu kurala göre dönüştürülebilir.
- $x+\overline{x}y=x+y$ kuralı
  - "Çok kullanışlı, karşınıza çok gelir." Yanındaki değişkenin değili ortadan kalkar.
- Sadeleştirme neden gerekli?
  - Her terim bir kapı, yani alan ve güç kaybıdır. Bool cebri kuralları karmaşık ifadelerde yetersiz kalınca Karnaugh haritası kullanılır.
- Karnaugh haritasının doğru çizilmesi
  - En sık hata etiket sırasıdır. Doğruluk tablosu ikilik sayma sırasıyla (00, 01, 10, 11), Karnaugh haritası tek bit değişimiyle (00, 01, 11, 10) ilerler.
  - Üçlü ya da altılı grup yoktur; gruplar 1, 2, 4, 8, 16 elemanlıdır. Çapraz grup yoktur.
  - Haritanın kenarları ve köşeleri komşudur (harita bir top gibi katlanmış düşünülür).
  - Grup ne kadar büyükse terim o kadar sadedir.
- Bu konudan soru gelir
  - Hoca, bir senaryodan doğruluk tablosu, Bool ifadesi, Karnaugh ile sadeleştirme ve devre çizimi isteyen soruların sorulduğunu söyledi.

## Kısa Tekrar Notları

- OR ↔ Bool toplamı, AND ↔ Bool çarpımı, NOT ↔ tümleyen.
- $n$ değişken: $2^n$ girdi, $2^{2^n}$ fonksiyon. $n=2$ için 16 fonksiyon.
- De Morgan: $\overline{xy}=\overline{x}+\overline{y}$, $\overline{x+y}=\overline{x}\,\overline{y}$.
- Yutma: $x+xy=x$, $x(x+y)=x$.
- $x+\overline{x}y=x+y$, $x(\overline{x}+y)=xy$.
- XOR: $x\oplus y=\overline{x}y+x\overline{y}=(x+y)(\overline{x}+\overline{y})$. XNOR: $\overline{x}\,\overline{y}+xy=(x+\overline{y})(\overline{x}+y)$.
- Doğruluk tablosundan SOP: 1 olan satırların mintermlerini topla, sonra sadeleştir.
- Yarım toplayıcı: $S=x\oplus y$, $C=xy$.
- Karnaugh etiket sırası: 00, 01, 11, 10.
- 4 değişkenli haritada grup büyüklüğü ve terim: 16'lı → $1$, 8'li → tek harf, 4'lü → iki harf, 2'li → üç harf, tek hücre → dört harf.
- $\sum m(1,4,7,9)$: en büyük indis 9 > 7 olduğundan en az 4 değişken gerekir.

## Detaylı Açıklamalar

- **Bool fonksiyonunun doğruluk tablosu ve devresi.** $F(x,y,z)=xy+\overline{z}$ için önce $xy$ ve $\overline{z}$ sütunları, sonra toplamları yazılır (ekrandan, 00:20:00). Fonksiyon $x,y,z$ değerleri 111, 110, 100, 010, 000 iken 1'dir. Devre: $x$ ve $y$ bir AND kapısına, $z$ bir NOT kapısına girer, iki çıkış bir OR kapısında toplanır (ekrandan, 00:25:00). Ters yönde, 1 olan satırlardan $xyz+xy\overline{z}+x\overline{y}\,\overline{z}+\overline{x}y\overline{z}+\overline{x}\,\overline{y}\,\overline{z}$ yazılır ve sadeleştirilince yeniden $xy+\overline{z}$ bulunur (python ile doğrulandı).
- **Fonksiyon sayısı.** Saymanın çarpma ilkesine göre 0 ve 1'den oluşan $n$'lik dizilerin sayısı $2^n$'dir; her diziye 0 ya da 1 atanarak $2^{2^n}$ fonksiyon kurulur. Ekrandaki tablo: $n=1,\dots,6$ için 4; 16; 256; 65.536; 4.294.967.296; 18.446.744.073.709.551.616 (ekrandan, 00:30:00).
- **Özdeşliklerin doğruluk tablosuyla ispatı.** $x(y+z)=xy+xz$ eşitliği, iki tarafın sütunları 8 satırda da aynı çıktığı için doğrudur (ekrandan, 00:35:00).
- **De Morgan'ın program koşulunda kullanımı.** Ekranda $(d<20 \;\&\&\; c>40)$ koşulu yazıldı (ekrandan, 00:35:00). Değili $(d\ge 20) \lor (c\le 40)$ olur: her karşılaştırma tersine döner, "ve" de "veya" olur. <!-- BELİRSİZ: d ve c değişkenlerinin anlamı altyazıda net değil; devam ve not gibi bir örnek olduğu anlaşılıyor. -->
- **Tablodan ifade bulma.** Tablodaki $F$ yalnız $x=z=1$, $y=0$ iken 1'dir, bu yüzden $F=x\overline{y}z$. $G$ ise 110 ve 010 satırlarında 1'dir: $G=xy\overline{z}+\overline{x}y\overline{z}=y\overline{z}(x+\overline{x})=y\overline{z}$ (ekrandan, 00:40:00). Terimler arasındaki çarpım, üç koşulun aynı anda sağlanması gerektiğini gösterir; terimler arasındaki toplam ise "ya bu durum ya şu durum" demektir. Sadeleşmiş halde $x$'in $G$ üzerinde etkisi yoktur.
- **$(x+y)\overline{z}$ fonksiyonunun açılımı.** Çözüm 1: tablodan $F=xy\overline{z}+x\overline{y}\,\overline{z}+\overline{x}y\overline{z}$. Çözüm 2: dağılma ($x\overline{z}+y\overline{z}$), özdeşlik ($x1\overline{z}+1y\overline{z}$), birim özelliği ($x(y+\overline{y})\overline{z}+(x+\overline{x})y\overline{z}$), dağılma ve tekrar eden $xy\overline{z}$ teriminin bir kez yazılması (ekrandan, 00:45:00). Slaytın dağılma satırında bir terimde $y$ unutulmuştur ($\overline{x}\,\overline{z}$ yerine $\overline{x}y\overline{z}$ olmalıdır); hoca bunu derste düzeltti.
  - Ders sonrası not: Slaytın sorusu "toplamların çarpımı açılımı" diyor, ama bulunan sonuç bir çarpımların toplamıdır (SOP). Büyük olasılıkla kaynak kitaptaki "sum-of-products expansion" ifadesi yanlış çevrilmiştir.
- **$x+\overline{x}y=x+y$ kuralının türetilmesi.** $x$, $1$ ile çarpılır ve $1=1+y$ yazılır: $x(1+y)+\overline{x}y = x+xy+\overline{x}y = x+y(x+\overline{x}) = x+y$ (ekrandan, 01:00:00). Benzer kural: $x(\overline{x}+y)=x\overline{x}+xy=xy$.
- **XOR ve XNOR.** XOR için $x\oplus y=\overline{x}y+x\overline{y}$ yazıldı (ekrandan, 00:55:00). XNOR için $\overline{x}\,\overline{y}+xy$.
  - Ders sonrası not: Tahtada XOR, $(x+\overline{y})(\overline{x}+y)$ diye, XNOR da $(x+y)(\overline{x}+\overline{y})$ diye yazıldı. Bu iki toplamların çarpımı biçimi yer değiştirmiştir. Açınca $(x+\overline{y})(\overline{x}+y)=xy+\overline{x}\,\overline{y}$ çıkar, bu XNOR'dur. Doğrusu: $x\oplus y=(x+y)(\overline{x}+\overline{y})$ ve XNOR $=(x+\overline{y})(\overline{x}+y)$ (python ile doğrulandı). Hoca açılımda bir hata olduğunu fark etti, ama tahtadaki ifade düzeltilmedi.
- **İfadelerden devre (ekrandan, 01:05:00).**
  - (a) $(x+y)\overline{x}$: $x,y$ → OR; $x$ → NOT; iki çıkış → AND.
  - (b) $\overline{x}\,\overline{(y+\overline{z})}$: $z$ → NOT; $y$ ile → OR; çıkış → NOT; $x$ → NOT; ikisi → AND.
  - (c) $(x+y+z)(\overline{x}\,\overline{y}\,\overline{z})$: üç girişli OR; üç NOT ve üç girişli AND; iki çıkış → AND.
- **Yarım toplayıcı (ekrandan, 01:10:00).** Tablo: $(x,y)=(1,1)\to s=0, c=1$; $(1,0)$ ve $(0,1)\to s=1, c=0$; $(0,0)\to s=0, c=0$. Slayttaki devre $S=(x+y)\overline{(xy)}$, $C=xy$ verir; hoca toplamı $\overline{x}y+x\overline{y}$ diye de yazdı. Tam toplayıcılar bu yarım toplayıcılardan kurulur; ayrıntısı mantık devreleri dersinin konusudur.
- **İki ve üç değişkenli Karnaugh haritası (ekrandan, 01:15:00 ve 01:20:00).** İki değişkenli haritada $x=0$ satırının iki hücresi 1 ise grup $\overline{x}$ verir; bu, $\overline{x}\,\overline{y}+\overline{x}y=\overline{x}(y+\overline{y})$ sadeleştirmesinin aynısıdır. Üç değişkenli örnekte 1'ler $\overline{x}yz$, $x\overline{y}\,\overline{z}$, $x\overline{y}z$, $xy\overline{z}$ hücrelerindedir. Gruplar: $x=1$ satırında 00–01 ikilisi → $x\overline{y}$; aynı satırda kenardan dolanan 00–10 ikilisi → $x\overline{z}$; tek kalan hücre → $\overline{x}yz$. Sonuç $F=x\overline{y}+x\overline{z}+\overline{x}yz$ (python ile doğrulandı).
- **Dört değişkenli ilk örnek ($x,y$ satır, $z,t$ sütun).** Ortadaki dörtlü → $yt$; dört köşe → $\overline{y}\,\overline{t}$; $xy=01$ satırı ilk önce ikili ($\overline{x}y\overline{t}$) alındı, sonra aynı satırın tamamı dörtlü alınarak $\overline{x}y$ yazıldı. Sonuç $yt+\overline{y}\,\overline{t}+\overline{x}y$. <!-- BELİRSİZ: 01:20:00 karesinde köşelerden yalnız alt satırdakiler dolu görünüyor; üst köşelerin sonradan doldurulduğu altyazıdaki "bütün köşelerde y sıfır" anlatımından çıkarıldı. -->
- **$\sum m(1,4,7,9)$ (ekrandan, 02:10:00 ve 02:25:00).** Doğruluk tablosunda 0001, 0100, 0111, 1001 satırları 1'dir. Haritada ikili grup 0001–1001 → $\overline{b}\,\overline{c}d$; tek hücreler 0100 → $\overline{a}b\overline{c}\,\overline{d}$ ve 0111 → $\overline{a}bcd$. Sonuç $F=\overline{b}\,\overline{c}d+\overline{a}b\overline{c}\,\overline{d}+\overline{a}bcd$.
- **Notlarla geçme devresi (ekrandan, 02:35:00 ve 02:40:00).** Ağırlıklar $a$ %20, $b$ %10, $c$ %20, $d$ %50; toplam en az 60 ise çıkış 1. 1 olan mintermler 3, 5, 7, 9, 11, 13, 15'tir. Haritada üç dörtlü: $ad$, $bd$, $cd$. SOP sonucu $F=ad+bd+cd$ (python ile doğrulandı). Bu 3 AND ve 2 OR kapısı ister; $d(a+b+c)$ biçimi daha az kapı (2 OR, 1 AND) ister ama SOP biçimi bozulur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
