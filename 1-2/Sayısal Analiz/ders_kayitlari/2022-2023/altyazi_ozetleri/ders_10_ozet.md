# Ders 10 Çalışma Özeti

## Genel Konular

- Duyurular
  - Birinci vizenin sınıf ortalaması hocanın beklediğinden düşük, diğer grubun ortalaması biraz daha yüksek. İkinci vize de aynı biçimde (online test) olacak. Finalde kağıt kalemi daha hızlı kullanmanız gerekecek.
  - Bu hafta enterpolasyon bitiyor, gelecek hafta regresyon. Sonraki hafta (17 Mayıs çarşamba) ikinci vize. Aynı gün kalan sürede projesini bitirenlerin projelerine bakılacak.
  - Proje raporu Online Yıldız'daki yükleme alanına yüklenecek.
  - Not dağılımı: yıl içi %60 = proje %20 + vize 1 %20 + vize 2 %20.
  - Dersin ortasında hocanın interneti koptu, bir süre ses gitmedi. Hoca öğrencilerden arada ses vermelerini rica etti.
- Enterpolasyon tekrarı
  - Bir ölçümde bazı girdilere karşılık çıktılar alınmıştır. Ara girdiler için çıktıyı ölçüm yapmadan tahmin etmek için, verilen noktaları sağlayan bir fonksiyon bulunur. Bu enterpolasyondur. "Ortalama" ile ilgisi yoktur.
  - Örnek: bütçeniz yalnızca 10 ölçüme yetiyor ama 100 farklı girdi için sonuca ihtiyacınız var. 10 ölçümden fonksiyonu bulup diğerlerini fonksiyondan hesaplarsınız.
  - Gerçek fonksiyon $f(x)$ bilinmez. Enterpolasyonla bulunan tahmin $F(x)$ (büyük F) ile gösterilir. Amaç $|F(x) - f(x)| \le \varepsilon$.
  - Sınavda "aşağıdakilerden hangisi enterpolasyonun tanımıdır/değildir" gibi sorular gelebilir.
  - Fonksiyon $[a, b]$'de sürekliyse polinom, $[0, 2\pi]$'de periyodik ise trigonometrik enterpolasyon kullanılır.
- Doğrusal enterpolasyon (tekrar)
  - Eğim yöntemi: $\frac{f(x_2) - f(x_1)}{x_2 - x_1} = \frac{f(x_3) - f(x_1)}{x_3 - x_1}$. Her yeni nokta için eğimi yeniden yazmak gerekir.
  - Doğru denklemi yöntemi: $F(x) = Ax + B$, uç noktalarda $Aa + B = f(a)$, $Ab + B = f(b)$. Bir kez bulunur, her $x$ için kullanılır.
  - Örnek fikir: $(1, -2)$ ve $(3, 4)$ noktalarından geçen doğru bulunup $x = 1.5$ veya $x = 3.5$ yerine konur.
  - İkinci dereceden polinom için üç nokta, 7. dereceden polinom için 8 nokta ve 8 denklem gerekir. Derece arttıkça bu yol çok yorucudur. Bölünmüş farklı ($b_0, b_1, b_2, \ldots$) formül de derece arttıkça karmaşıklaşır. Bu yüzden Gregory-Newton gibi yöntemler kullanılır.
- Gregory-Newton enterpolasyonu (tekrar ve devam)
  - $F(x) = f_0 + \sum_{i=1}^{n}\binom{k}{i}\Delta^i f_0$, $k = \frac{x - x_0}{h}$.
  - Genel hâl: $F(x) = f_0 + \frac{x - x_0}{h}\Delta f_0 + \frac{(x - x_0)(x - x_1)}{2!\,h^2}\Delta^2 f_0 + \frac{(x - x_0)(x - x_1)(x - x_2)}{3!\,h^3}\Delta^3 f_0 + \ldots$
  - $x_0 = 0$ ve $h = 1$ ise en basit hâl: $F(x) = f_0 + x\Delta f_0 + \frac{x(x-1)}{2!}\Delta^2 f_0 + \frac{x(x-1)(x-2)}{3!}\Delta^3 f_0 + \ldots$
  - Fark tablosunda hangi sütun sabitlenirse polinomun derecesi odur. Örneğin 3. fark sabitse fonksiyon 3. derecedendir. 4 veya 2 çıkarsa bir yerde hata yapılmıştır.
  - Örnek 1 (tekrar): $x$: 0…6, $f$: −4, −2, 14, 62, 160, 326, 578. $\Delta f_0 = 2$, $\Delta^2 f_0 = 14$, $\Delta^3 f_0 = 18$. $F(x) = -4 + 2x + \frac{x(x-1)}{2}14 + \frac{x(x-1)(x-2)}{6}18$.
  - Örnek 2: $x$: 2, 4, 6, 8, 10, $f$: 10, 50, 122, 226, 362. $x_0 = 2 \ne 0$, $h = 2 \ne 1$, ama $h$ sabit.
    - $\Delta f$: 40, 72, 104, 136. $\Delta^2 f$: 32, 32, 32. 2. fark sabit.
    - Genel formül: $F(x) = 10 + \frac{x - 2}{2}40 + \frac{(x - 2)(x - 4)}{2^2 \cdot 2!}32$.
- Değişken dönüşümü
  - $x_0 \ne 0$ ve/veya artımlar 1 değilse (hatta eşit değilse) kullanılır. Hoca "en azından finalde mutlaka sorarız" diye vurguladı.
  - Adımlar:
    1. Yeni bir değişken $z$ uydurulur: 0'dan başlar, birer artar. Veri sayısı kadar değer alır (6 veri için $z = 0, \ldots, 5$).
    2. $z$ "sahte girdi" olduğu için çıktısı yoktur. Çıktı olarak orijinal $x$ değerleri yazılır: $F(z) = x$.
    3. Bu tablonun fark tablosu ($\Delta x$, $\Delta^2 x$, …) çıkarılır ve basit Gregory-Newton formülü uygulanır: $x = x_0 + z\Delta x_0 + \frac{z(z-1)}{2!}\Delta^2 x_0 + \ldots$. Buradan $z$, $x$ cinsinden çekilir.
    4. Orijinal $f$ değerleri $z$'nin fonksiyonuymuş gibi fark tablosu çıkarılır ve basit formülle bir **ara enterpolasyon fonksiyonu** $F(z)$ yazılır.
    5. $F(z)$'deki her $z$ yerine 3. adımda bulunan $x$ cinsinden ifade konur. Sonuç aranan $F(x)$'tir.
  - Örnek (artımlar eşit değil): $x$: −1, 0, 3, 8, 15, 24, $f$: 2, 1, 10, 65, 226, 577.
    - $z$: 0…5, $F(z) = x$: −1, 0, 3, 8, 15, 24. $\Delta x$: 1, 3, 5, 7, 9. $\Delta^2 x$: 2 (sabit).
    - $x = -1 + z \cdot 1 + \frac{z(z-1)}{2}2 = z^2 - 1$, yani $z = \mp\sqrt{x + 1}$.
    - $f$ tablosu: $\Delta f$: −1, 9, 55, 161, 351. $\Delta^2 f$: 10, 46, 106, 190. $\Delta^3 f$: 36, 60, 84. $\Delta^4 f$: 24 (sabit).
    - $F(z) = 2 - z + 10\frac{z(z-1)}{2} + 36\frac{z(z-1)(z-2)}{6} + 24\frac{z(z-1)(z-2)(z-3)}{24} = z^4 - 2z^2 + 2$ (ara enterpolasyon formülü).
    - $z^2 = x + 1$ konunca: $F(x) = (x+1)^2 - 2(x+1) + 2 = x^2 + 1$. Kontrol: $F(-1) = 2$, $F(0) = 1$, $F(3) = 10$.
    - Ara fonksiyon 4. dereceden olduğu hâlde sonuç 2. derecedendir, çünkü $z$ ile $x$ arasında ikinci dereceden bir ilişki vardır.
  - Örnek (her iki yolla): $x$: 2, 4, 6, 8, 10, $f$: 3, 7, 19, 39, 67.
    - Fark tablosu: $\Delta f$: 4, 12, 20, 28. $\Delta^2 f$: 8 (sabit).
    - Dönüşümsüz (genel formül, $h = 2$): $F(x) = 3 + \frac{x - 2}{2}4 + \frac{(x-2)(x-4)}{4 \cdot 2}8 = x^2 - 4x + 7$.
    - Dönüşümle: $z$: 0…4, $x = 2 + 2z$, yani $z = \frac{x - 2}{2}$. $F(z) = 3 + 4z + \frac{z(z-1)}{2}8 = 4z^2 + 3$. $z$ yerine konunca $F(x) = 4\left(\frac{x-2}{2}\right)^2 + 3 = (x-2)^2 + 3 = x^2 - 4x + 7$.
    - İki yol aynı sonucu verir. Kontrol: $F(2) = 3$, $F(4) = 7$, $F(10) = 67$.
  - Hoca bu iki örneği slaytlara bakmadan kendinizin çözmesini istedi.
- Lagrange enterpolasyonu
  - Noktaların aralıklarının eşit olup olmamasının, $x_0$'ın sıfır olup olmamasının hiçbir önemi yoktur.
  - $g(x) = \sum_{i=0}^{n} L_i(x)\,y_i$. Her veri noktası için bir Lagrange katsayısı $L_i(x)$ hesaplanır:
    - $L_i(x) = \prod_{j=0,\ j \ne i}^{n} \frac{x - x_j}{x_i - x_j}$
  - $j \ne i$ şartı paydanın sıfır olmaması içindir: $j = i$ olursa $x_i - x_i = 0$ olur.
  - $n + 1$ veri için $n + 1$ tane $L$ hesaplanır. 0'dan başlandığı için toplamın üst sınırı $n$'dir.
  - Örnek 1: $(0, -5)$, $(1, 1)$, $(3, 25)$.
    - $L_0 = \frac{(x - 1)(x - 3)}{(0 - 1)(0 - 3)} = \frac{1}{3}(x-1)(x-3)$, $L_1 = \frac{(x - 0)(x - 3)}{(1 - 0)(1 - 3)} = -\frac{1}{2}(x^2 - 3x)$, $L_2 = \frac{(x - 0)(x - 1)}{(3 - 0)(3 - 1)} = \frac{1}{6}(x^2 - x)$.
    - $g(x) = \frac{1}{3}(x-1)(x-3)(-5) - \frac{1}{2}(x^2 - 3x)(1) + \frac{1}{6}(x^2 - x)(25) = 2x^2 + 4x - 5$. $g(1) = 1$, $g(2) = 11$.
  - Örnek 2: $(3, 1)$, $(7, -8)$, $(15, -22)$, $(22, -9)$, $n = 3$.
    - $L_0 = -\frac{1}{912}(x-7)(x-15)(x-22)$, $L_1 = \frac{1}{480}(x-3)(x-15)(x-22)$, $L_2 = -\frac{1}{672}(x-3)(x-7)(x-22)$, $L_3 = \frac{1}{1995}(x-3)(x-7)(x-15)$.
    - $g(4) = -1.0297$, $g(10) = -14.9737$.
  - Lagrange elle çözülürken zahmetlidir ve hataya açıktır: her veri için bir $L$ hesaplanır. 50 veri varsa 50 $L$. Gregory-Newton'da ise fark tablosu çoğu zaman erken sabitlenir. Kodla yapılınca ikisinde de hata olmaz.
- Enterpolasyon özeti
  - Doğru: eğimden veya doğru denkleminden.
  - Polinom: Gregory-Newton ($x_0 = 0$ ve $h = 1$ ise basit formül, değilse genel formül veya değişken dönüşümü) ya da Lagrange (aralıklardan bağımsız).
  - Gelecek hafta regresyon: o da fonksiyon uydurur ama daha yaklaşık uydurur, $f$ ile $F$ arasındaki fark daha büyük olabilir. Doğrusal olmayan fonksiyonlar da uydurulabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Değişken dönüşümü çok önemli, finalde mutlaka sorulur.
- Fark tablosunun sabitlendiği sütun polinomun derecesini verir. Bulduğunuz derece bununla uyuşmuyorsa hata yapmışsınızdır.
- Gregory-Newton'un basit formülü yalnızca $x_0 = 0$ ve $h = 1$ ise kullanılır.
- Lagrange'ta formülü yazarken sırayı karıştırmayın: payda $x - x_j$, paydada $x_i - x_j$, $j \ne i$.
- Lagrange elle hataya açıktır, çok dikkatli olun.
- Projeyi son ana bırakmayın, raporu Online Yıldız'a yükleyin.

## Kısa Tekrar Notları

- Basit Gregory-Newton: $F(x) = f_0 + x\Delta f_0 + \frac{x(x-1)}{2!}\Delta^2 f_0 + \ldots$ ($x_0 = 0$, $h = 1$).
- Genel: $F(x) = f_0 + \frac{x - x_0}{h}\Delta f_0 + \frac{(x - x_0)(x - x_1)}{2!h^2}\Delta^2 f_0 + \ldots$
- Değişken dönüşümü: $z = 0, 1, 2, \ldots$, $F(z) = x$ ile $z$'yi $x$ cinsinden bul, sonra $f$ için ara $F(z)$ yaz, $z$'yi yerine koy.
- Lagrange: $g(x) = \sum L_i(x)y_i$, $L_i(x) = \prod_{j \ne i}\frac{x - x_j}{x_i - x_j}$.
- Not: proje %20, vize 1 %20, vize 2 %20.

## Detaylı Açıklamalar

### Enterpolasyon polinomunun tekliği

- $n + 1$ farklı noktadan geçen en fazla $n$. dereceden polinom **tektir**. Bu yüzden Gregory-Newton (bütün farklar kullanıldığında), Lagrange ve bölünmüş farklar aynı noktalar için aynı polinomu verir. Yöntemler arasındaki fark sonuçta değil, hesaplama kolaylığındadır.
- Örneğin Lagrange örneği 1'deki noktalar $(0, -5)$, $(1, 1)$, $(3, 25)$ Gregory-Newton (değişken dönüşümüyle) ile çözülse de $2x^2 + 4x - 5$ çıkar.
- Lagrange'ın bir avantajı: yeni bir veri eklenince Gregory-Newton'da tabloya bir satır eklemek yeter, Lagrange'ta ise bütün $L_i$'ler yeniden hesaplanır. Lagrange'ın avantajı da eşit aralık gerektirmemesidir.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Bütün örnekler ders sonrasında Python ile yeniden hesaplandı. Değişken dönüşümü örnekleri ($x^2 + 1$ ve $x^2 - 4x + 7$) ve Lagrange örnekleri doğrudur. Lagrange örneği 2'de $g(4)$'ün kesin değeri $-1.0296992$'dir (slaytta $-1.0296854$, ara yuvarlamadan).
- **Örnek 2'nin ($x$: 2…10) sonucu:** Derste formül kuruldu ama sonuç sözle verilmedi ve tahtadaki sadeleştirmede $\frac{32}{4}$ yazılıp $2!$ unutulmuş gibi görünüyor. Doğrusu $\frac{(x-2)(x-4)}{2^2 \cdot 2!}32 = 4(x-2)(x-4)$'tür. Sonuç $F(x) = 10 + 20(x - 2) + 4(x - 2)(x - 4) = 4x^2 - 4x + 2$. Kontrol: $F(2) = 10$, $F(8) = 226$, $F(10) = 362$. Hocanın "8 koydum, 226 verdi" kontrolü bu fonksiyonla tutar. $F(3) = 26$.
- **"Gregory daha yakın sonuç verir" ifadesi:** Hoca Lagrange'ı anlatırken Gregory'nin daha yakın sonuç verdiğini söyledi. Aynı noktaların tamamı kullanılırsa iki yöntem de aynı polinomu bulur (yukarıdaki "teklik" notuna bakın). Fark yalnızca elle hesaplarken hata yapma olasılığındadır. Gregory-Newton'da fark tablosu erken sabitlenirse daha az işlem yapılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
