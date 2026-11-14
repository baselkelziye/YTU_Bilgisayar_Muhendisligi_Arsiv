# Ders 11 Genişletilmiş Notu: Fazör Uzayında Pasif Elemanlar: Empedans, Admitans, Seri-Paralel Eşdeğer ve Fazör Devre Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Haftanın Tekrarı: Fazör Uzayına Gidiş ve Dönüş
- 2. Pasif Elemanların Fazör Uzayındaki Karşılıkları
- 3. Filtre Fikrine İlk Bakış
- 4. Fazör Uzayında Devre Çözme Yöntemi
- 5. Örnek: Akım Kaynaklı Paralel RLC Devresi
- 6. Fazör Gösterimi Üstel Biçimle Nasıl İlişkilidir?
- 7. Fazör Uzayında Ohm Kanunu ve Empedans
- 8. Admitans ve Uç Frekanslardaki Davranış
- 9. Şönt Endüktans ve Şönt Kapasite ile Filtreleme
- 10. Empedans ve Admitansın Polar ve Kartezyen Gösterimleri
- 11. Seri ve Paralel Bağlı Elemanların Eşdeğer Empedansı
- 12. Örnek: Seri RL Devresi
- 13. Örnek: Akım Kaynaklı Paralel RCL Devresi
- 14. Fazörün Arkasındaki Tam Gösterim
- 15. Sonraki Konular: Norton, Thevenin, Gerilim ve Akım Bölücü
- 16. Hocanın Önerdiği Pratikler

## 1. Geçen Haftanın Tekrarı: Fazör Uzayına Gidiş ve Dönüş

Hoca derse, geçen hafta kurulan matematiksel altyapıyı hatırlatarak başladı. Devre çözümlerini artık fazör denen bir uzayda yapmak istiyoruz. Bunun için önce karmaşık sayıların gösterimleri ele alınmıştı: karmaşık sayılar kartezyen koordinatta, polar koordinatta ve üstel biçimde gösterilebiliyordu. Üstel biçim ile polar biçim arasındaki dönüşüm de Euler formülü üzerinden yapılıyordu. Geçen dersin sonunda, fazör uzayında devre elemanlarının tanım bağıntılarının nasıl olacağı noktasına gelinmişti. Şu ana kadar fazöre geçiş yalnızca kaynaklar için tamamlanmıştı.

### 1.1 Kaynağı Fazöre Çevirmek

Fazör uzayına geçerken kaynak kosinüs biçiminde yazılır. Bu yazımda iki koşula dikkat edilir: kosinüsün önündeki katsayı pozitif olmalı, içerideki faz açısı $-180^\circ$ ile $+180^\circ$ arasında olmalıdır. Trigonometrik dönüşümlerle bu koşulları sağlayan bir ifade elde edilince, genlik ve faz açısı alınır ve kaynağın fazör karşılığı yazılır:

$$V_m\cos(\omega t + \theta) \;\rightarrow\; V_m\angle\theta$$

Bu sırada sistemin frekansı bir yere mutlaka not edilir. Çünkü sistemde sinüzoidal bir zorlayıcı kaynak varsa bütün akım ve gerilimler aynı frekansta çalışır. Frekans bir kez not edilince artık yedekte duran bir bilgi olur.

### 1.2 Fazör Uzayından Geri Dönmek

Geri dönerken genlik kosinüsün önüne yazılır. Kosinüsün içine de not edilmiş $\omega$ ile fazörden gelen faz açısı konur, yani $\omega t + \theta$ yazılır. Bu işlem, karmaşık sayının reel kısmını almaya karşılık gelir. Derste kosinüsler üzerinden çalışılması konusunda anlaşılmıştı. Bir karmaşık sayının kosinüslü terimi reel kısımdan geldiği için, fazörden dönerken de reel kısım alınır.

### 1.3 Fazör Uzayının Avantajı

Fazör uzayına geçmenin avantajı, diferansiyel denklemlerin doğrusal denklemlere dönüşmesidir. Hoca burada sınıfa bir soru sordu.

**Soru:** Zaman domeninde doğrusal eleman hangisiydi? **Cevap:** Direnç.

Fazör uzayında bütün eleman denklemleri doğrusal denkleme dönüşüyorsa, endüktansa da kapasitansa da direnç elemanıymış gibi davranılabilir. Yani fazör uzayında devre, yalnız dirençlerden oluşan bir devre gibi çözülebilir. Tek fark şudur: Zaman domeninde direncin değeri reel bir sayıdır. Fazör uzayında ise endüktans ve kapasitansın direnç karşılığı olan terim, yani **empedans**, karmaşık bir sayıdır. Empedans, fazör uzayında pasif elemanların akıma karşı gösterdiği dirençtir.

Empedans frekansla değişir. Devredeki sinüzoidal kaynağın frekansı arttıkça ya da azaldıkça elemanın akıma gösterdiği direnç de değişir. Bir direncin uçlarına sinüzoidal işaret uygulayıp frekansı ne kadar değiştirirsek değiştirelim $R$ değişmez. Endüktans ve kapasitans için durum böyle değildir.

> **Ders sonrası not:** Hoca bu noktada bir an "R, L ve C elemanları için bu durum böyle değil" dedi; doğrusu yalnız L ve C içindir. Dersin devamında hocanın kendisi de direncin empedansının frekanstan bağımsız olduğunu gösterdi.

## 2. Pasif Elemanların Fazör Uzayındaki Karşılıkları

Hoca üç pasif elemanı sırayla ele aldı. Her birinde zaman domenindeki tanım bağıntısından yola çıktı, iki tarafı fazöre çevirdi ve gerilim fazörünün akım fazörüne oranına baktı.

### 2.1 Direnç

Direncin uçlarına $v(t) = V_m\cos(\omega t + \theta_1)$ kaynağı bağlansın. $\theta_1$'in $-180^\circ$ ile $+180^\circ$ arasında olduğu varsayılır. O zaman gerilimin fazör karşılığı $\mathbf{V} = V_m\angle\theta_1$ olur.

Akım için $i(t) = I_m\cos(\omega t + \theta_2)$ biçiminde bir denklem bekleriz. Akım, gerilimin $R$'ye bölünmüş hâlidir. Bu yüzden $I_m = V_m/R$ olur ve $\omega$ değişmez. Hoca burada faz açısının değişip değişmeyeceğini sordu.

**Soru:** Akımın faz açısı $\theta$ değişir mi? **Cevap:** Değişmez, $\theta_2 = \theta_1$ olur.

Dolayısıyla $\mathbf{I} = I_m\angle\theta_1$ yazılır. $R$ sabit bir çarpan olduğu için fazör uzayında dışarı alınabilir ve $\mathbf{V} = R\,\mathbf{I}$ elde edilir. Oran şöyledir:

$$\frac{\mathbf{V}}{\mathbf{I}} = \frac{V_m\angle\theta_1}{I_m\angle\theta_1} = \frac{V_m}{I_m}\angle 0^\circ = R$$

Bölme işleminde açılar çıkarılır, $\theta_1 - \theta_1 = 0$ kalır. Açısı sıfır olan bir fazör reel bir sayıdır.

> **Hocanın vurgusu:** Bu çok önemli birinci özelliktir: Direnç elemanının fazör uzayındaki empedans karşılığı, direncin kendi değeridir: $Z_R = R$.

### 2.2 Endüktans

Endüktansın tanım bağıntısı $v_L = L\,\dfrac{di_L}{dt}$ şeklindedir. Akım $i_L(t) = I_m\cos(\omega t + \theta_2)$ olsun. Türev alındığında kosinüsün türevinden eksi sinüs, içerideki fonksiyondan da $\omega$ gelir:

$$v_L(t) = -L\,I_m\,\omega\,\sin(\omega t + \theta_2)$$

Bu ifadeyi fazöre çevirebilmek için kosinüs biçimine getirmek gerekir. Hoca önce $\sin\alpha = \cos(90^\circ - \alpha) = \cos(\alpha - 90^\circ)$ dönüşümünü hatırlattı. Kosinüsün içi negatif olduğunda değeri değişmediği için ikinci eşitlik yazılabilir.

Hoca, önündeki eksi işaretini içeri alırken önce $-\sin\alpha = \sin(-\alpha)$ yolunu denedi ve bir anda faz farkı için $-90^\circ$, empedans için $-j\omega L$ buldu. Bu sonucun beklenenle uyuşmadığını gördü, öğrencilerin de uyarısıyla işlemi baştan kontrol etti. Sorun şuydu: $\sin(-\alpha)$ yazılırsa içeride $-\omega t$ oluşur, bu da istenmez. Bunu bozmamak için aynı eşitliğin öteki biçimi kullanılmalıdır:

$$-\sin\alpha = \sin(180^\circ + \alpha)$$

Yani dıştaki eksiyi kaybetmek için içerideki açıya $180^\circ$ eklenir. Sonra sinüsten kosinüse geçişte $90^\circ$ çıkarılır ve net olarak $+90^\circ$ kalır (ara adım eklendi):

$$-\sin\alpha = \sin(\alpha + 180^\circ) = \cos(\alpha + 180^\circ - 90^\circ) = \cos(\alpha + 90^\circ)$$

Böylece doğru sonuç elde edilir:

$$v_L(t) = L\,I_m\,\omega\,\cos(\omega t + \theta_2 + 90^\circ)$$

Fazör karşılıkları $\mathbf{V}_L = L I_m\omega\angle(\theta_2 + 90^\circ)$ ve $\mathbf{I}_L = I_m\angle\theta_2$ olur. Bunları böldüğümüzde $I_m$ sadeleşir, açılar çıkarılır:

$$\frac{\mathbf{V}_L}{\mathbf{I}_L} = \omega L\angle 90^\circ$$

Genliği 1, açısı $90^\circ$ olan karmaşık sayı $j$'dir. Bu nedenle:

$$Z_L = j\omega L$$

Bu sabit bir değerdir. Karmaşık bir sayı olsa da sabittir ve $\omega$'ya bağlıdır. Empedansın değişkeni $Z$ harfidir. Uygulanan gerilimin frekansı arttıkça endüktansın akıma gösterdiği empedans yükselir.

DC şartlarda çalışmak $\omega = 0$ vermek demektir. O zaman $Z_L = 0$ olur. Daha önce öğrenildiği gibi endüktans DC şartlarda kısa devre gibi çalışıyordu. Bu formül de aynı sonucu verir.

> **Hocanın vurgusu:** Endüktans ve kapasitenin formülleri zamanla karışabilir. Bunu önlemek için şöyle düşünün: Endüktans DC şartlarda kısa devreydi. Hatırladığınız formülde $\omega = 0$ koyunca kısa devre çıkıyor mu, bakarak doğrulayabilirsiniz.

### 2.3 Kapasite

Kapasite için $v_C(t) = V_m\cos(\omega t + \theta_1)$ gerilimi uygulansın. Fazör karşılığı $\mathbf{V}_C = V_m\angle\theta_1$ olur. Akım, $i_C = C\,\dfrac{dv_C}{dt}$ bağıntısından gelir:

$$i_C(t) = -C\,V_m\,\omega\,\sin(\omega t + \theta_1)$$

Mantık endüktanstakine çok benzer. Önce $\sin\alpha = \cos(\alpha - 90^\circ)$ ile kosinüse geçilir ve $-C V_m\omega\cos(\omega t + \theta_1 - 90^\circ)$ elde edilir. Sıra eksi işaretini içeri almaya gelmiştir.

Artık kosinüsle çalışıldığı için hoca birim çember üzerinden düşündü. $-\cos\alpha$ iki biçimde yazılabilir: $\cos(180^\circ - \alpha)$ ya da $\cos(180^\circ + \alpha)$. Birincisi tercih edilmez, çünkü içeride $-\omega t$ oluşur. Demek ki açıya $180^\circ$ eklenir:

$$i_C(t) = C\,V_m\,\omega\,\cos(\omega t + \theta_1 + 90^\circ)$$

Fazör karşılığı $\mathbf{I}_C = C V_m\omega\angle(\theta_1 + 90^\circ)$ olur. Oran alındığında $V_m$ ve $\theta_1$ gider:

$$\frac{\mathbf{V}_C}{\mathbf{I}_C} = \frac{V_m\angle\theta_1}{C V_m\omega\angle(\theta_1 + 90^\circ)} = \frac{1}{\omega C\angle 90^\circ}$$

Paydadaki genliği 1, açısı $90^\circ$ olan sayı yine $j$'dir. Böylece:

$$Z_C = \frac{1}{j\omega C}$$

Kapasitenin empedansı da frekansla değişir. DC şartlarda $\omega = 0$ olduğunda $Z_C$ sonsuza gider. Bu da önceki derslerde görülen, kapasitenin DC şartlarda açık devre gibi davranması bilgisiyle uyumludur.

### 2.4 Üç Elemanın Özeti

Hoca üç sonucu yan yana yazdı:

$$Z_R = R, \qquad Z_L = j\omega L, \qquad Z_C = \frac{1}{j\omega C}$$

Endüktans ve kapasitenin değerleri frekansla değişen direnç değerleri gibidir. Bunlar empedanstır, ama anlamak açısından direnç gibi düşünülebilir.

## 3. Filtre Fikrine İlk Bakış

Empedansın frekansla değişmesi önemli bir kapı açar. Belirli frekansları süzen, belirli frekansları geçiren devreler yapmak istersek, uygun endüktans ve kapasite elemanları seçerek alçak geçiren, yüksek geçiren, bant geçiren ve çentik (notch) filtre gibi çeşitli filtreler tasarlayabiliriz. Bu yüzden elde edilen sonuçlar AC sinyal ve filtre tasarımı açısından önemlidir.

**Soru:** Filtreden kastedilen nedir? **Cevap:** Analog filtredir. Hoca bir mikrofon örneği verdi: Mikrofona konuşuyorum, sesimi filtreliyorum, yüksek frekanslı sesleri süzüp sönümlendiriyorum, sonra hoparlörden veriyorum. Sesim çok kalın çıkar. Tersine, sesimdeki bas unsurları süzüp sönümlendirirsem hoparlörden çok ince bir ses çıkar.

> **Ders sonrası not:** Hoca ikinci durum için "alçak geçiren filtre uyguluyorum" dedi; doğrusu yüksek geçiren filtredir. Dersin ilerleyen kısmında hocanın kendisi de düşük frekansları süzen elemanı "yüksek frekansları geçiren" diye tanımladı. Birinci durumda, yani yüksek frekanslar süzülüp ses kalınlaştığında, kullanılan filtre alçak geçirendir.

Hoca, dersin son haftasına yetişirse Bode diyagramı (Bode plot) kavramına da değinileceğini, şu anda bu konunun henüz bilinmediğini söyledi.

## 4. Fazör Uzayında Devre Çözme Yöntemi

Fazör uzayında direnç, endüktans ve kapasite elemanlarının gerilim bölü akım değerleri sabittir. Bu sabitlik belirli bir frekans içindir: Devrede belirli bir frekansta çalışan tek bir kaynak olduğu için $\omega$ sabit durur. Frekans değiştiğinde değerin değişmesi burada önemli değildir. Zaman domeninden farkı, bu değerlerin karmaşık sayı olmasıdır.

Bütün elemanlar fazör uzayına geçirilince hepsi doğrusal bir direnç elemanı gibi davranır. Paralel ve seri devreler için eşdeğer empedans hesaplanabilir. Norton ve Thevenin teoremleri, süperpozisyon, çevre ve akım denklemleri, yani görülen bütün teoremler burada uygulanabilir ve devre doğrusal denklemler üzerinden çözülür.

> **Ders sonrası not:** Hoca burada endüktans ve kapasite için "non-linear elemanlarım" ifadesini kullandı. Burada kastedilen, zaman domeninde bu elemanların gerilim-akım bağıntısının sabit bir oran olmaması, türev içermesidir. Yaygın devre teorisi terminolojisinde L ve C büyük olasılıkla doğrusal eleman sayılır, çünkü türev doğrusal bir işlemdir.

### 4.1 Neden Fazör Uzayını Tercih Ediyoruz?

Birinci koşul şudur: Kaynak sinüzoidal olmalı ve devreyi pratikte yeterince uzun bir süre, yaklaşık $5\tau$ kadar sürmüş olmalıdır. Bu durumda geçici hâller tamamlanmıştır ve diferansiyel denklemin homojen çözümüyle ilgilenmeye gerek kalmaz. Devre artık sürekli sinüzoidal hâlde çalışır.

Sürekli sinüzoidal hâlde, kaynağın frekansı neyse bütün elemanlardaki akım ve gerilimler de o frekanstadır. Değişen yalnız iki şey vardır: genlikler ve faz açıları. Fazör de zaten bu iki bilgiyi tutar. Dolayısıyla bu iki bilgiyi alıp karmaşık sayı düzlemine geçeriz, bütün devre çözümünü orada yaparız, sonra sonucun reel kısmını alarak zaman domenindeki çözüme eşdeğer sonucu elde ederiz.

### 4.2 İzlenecek Yol

1. Kaynağın fazör gösterimini elde et, frekansını not et.
2. Direnç, kapasitans ve endüktans elemanları için empedans değerlerini hesapla.
3. Devreyi direnç devresiymiş gibi, ama karmaşık sayı uzayında çöz.
4. Karmaşık sayı olarak çıkan sonucun reel kısmını alıp zaman domenine dön.

> **Ek bilgi (derste anlatılmadı):** Bu yöntemin neden çalıştığı üstel biçimden de görülebilir. $A e^{j(\omega t + \varphi)}$ ifadesinin zamana göre türevi, kendisinin $j\omega$ ile çarpımıdır. Yani fazör uzayında türev almak $j\omega$ ile çarpmaya dönüşür. Bu özdeşlik, derste kosinüs üzerinden türetilen $Z_L = j\omega L$ ve $Z_C = 1/(j\omega C)$ sonuçlarıyla aynı şeyi söyler. Bu özdeşlik sayısal türevle python ile hesaplandı.

## 5. Örnek: Akım Kaynaklı Paralel RLC Devresi

Bu örnek kısa notta "Örnek 2" olarak geçer. Zaman domeninde ele alınsaydı karşımıza bir diferansiyel denklem çıkacaktı. Ama varsayımımız şudur: Kaynak devreyi belirli bir süre beslemiş, geçici rejimler sona ermiştir, sürekli sinüzoidal hâldeyiz.

**Verilen:** $i_s(t) = 8\cos(2\pi\cdot 10^6\, t + 30^\circ)$ mA. Kaynağa paralel $R = 70\ \Omega$, $L = 10\ \mu$H ve $C = 2$ nF bağlıdır. **İstenen:** Elemanların uçlarındaki $v(t)$ gerilimi.

<!-- BELİRSİZ: Devre şeması slaytta; altyazıda yalnızca sözlü olarak anlatılıyor. Bağlantı biçimi hocanın kol akımlarını anlatımından kuruldu. -->

**Adım 1: Kaynak.** Kaynak zaten kosinüs biçimindedir. Fazör karşılığı $\mathbf{I}_s = 8\angle 30^\circ$ mA olur. Bu sefer kaynak $\omega$ ile değil, frekans cinsinden verilmiştir. $\omega$ açısal frekanstır ve $\omega = 2\pi f$ bağıntısı geçerlidir. Kosinüsün içi $\omega t$ yerine $2\pi f t$ olarak da yazılabilir. Burada $f = 10^6$ Hz not edilir.

**Adım 2: Empedanslar.** Direnç için $Z_R = 70\ \Omega$. Endüktans için:

$$Z_L = j\omega L = j\cdot 2\pi\cdot 10^6\cdot 10\cdot 10^{-6} = j20\pi\ \Omega$$

$10^6$ ile $10^{-6}$ birbirini götürür. Kapasite için, mili, mikro, nano sırasından nano $10^{-9}$ olduğu için:

$$Z_C = \frac{1}{j\omega C} = \frac{1}{j\cdot 2\pi\cdot 10^6\cdot 2\cdot 10^{-9}} = \frac{1}{j\,4\pi\cdot 10^{-3}} = \frac{1000}{j4\pi} = \frac{250}{j\pi}\ \Omega$$

**Adım 3: Kol akımları.** İstenen $v(t)$ olduğu için onun fazör karşılığını $\mathbf{V}$ ile gösterelim. Kaynak akımı düğüme giren yönde, kol akımları çıkan yönde tanımlanırsa kol akımlarının toplamı giren akıma eşit olmalıdır:

$$\mathbf{I}_R = \frac{\mathbf{V}}{70}, \qquad \mathbf{I}_L = \frac{\mathbf{V}}{j20\pi}, \qquad \mathbf{I}_C = \frac{\mathbf{V}}{250/(j\pi)} = \mathbf{V}\,\frac{j\pi}{250}$$

$$\mathbf{I}_s = \mathbf{V}\left(\frac{1}{70} + \frac{1}{j20\pi} + \frac{j\pi}{250}\right)$$

**Adım 4: Toplama.** Toplama ve çıkarma işlemi kartezyen biçimde kolaydır. Bu yüzden terimler kartezyene çevrilir. $20\pi \approx 62.8$ olduğu için endüktans terimi $1/(j62.8)$ biçimindedir. Paydadaki $j$'den kurtulmak için hoca bir öğrencinin sorusu üzerine bu adımı ayrıca gösterdi.

**Soru:** $1/(j62.8)$ nasıl hesaplandı? **Cevap:** Alt ve üst taraf $j$ ile çarpılır. Payda $j^2\cdot 62.8 = -62.8$ olur, payda $j$ kalır. Sonuç $-j/62.8$'dir. Bir eksi işareti gelmiş olur. Paydada $j$ bırakmamak için bu işlemi yapıyorduk.

> **Ders sonrası not:** Altyazıya göre hoca $1/62.8$ değerini "eksi 0.159" olarak okudu; doğrusu $-0.0159$'dur (python ile hesaplandı: $1/62.8 = 0.01592$).

Terimler şöyledir (ara adım eklendi):

$$\frac{1}{70} = 0.0143, \qquad \frac{1}{j20\pi} = -j0.0159, \qquad \frac{j\pi}{250} = j0.0126$$

$$\frac{\mathbf{I}_s}{\mathbf{V}} = 0.0143 - j0.0033$$

Sanal kısımların toplamı $-0.0159 + 0.0126 = -0.0033$ eder.

**Adım 5: Polara çevirme.** Hoca, kartezyen biçimdeki sonucun polara hesap makinelerindeki kartezyen-polar dönüşümüyle çevrildiğini söyledi, sonra işlemin ne olduğunu açtı. Genlik, reel ve sanal kısımların karelerinin toplamının kareköküdür. Açı da $\tan^{-1}(-0.0033/0.0143) \approx -13^\circ$'dir:

$$0.0143 - j0.0033 = 0.0147\angle -13^\circ$$

> **Ders sonrası not:** Hoca bu sayıya "eşdeğer empedans" dedi; doğrusu eşdeğer **admitanstır**. Çünkü denklemde $\mathbf{I}_s = \mathbf{V}\cdot(\ldots)$ biçiminde gerilimle çarpılmaktadır, yani $\mathbf{I}_s/\mathbf{V}$ oranıdır. Altyazıya göre açı hesabında payda "0.043" diye geçiyor; doğrusu $0.0143$'tür. Python ile hesaplandı: $1/70 = 0.01429$, sanal kısım $-0.00335$, genlik $0.01467$, açı $-13.19^\circ$.

**Adım 6: Gerilim.** Kaynak fazörü bu sayıya bölünür. Akım miliamper olduğu için sonuç milivolt cinsinden çıkar:

$$\mathbf{V} = \frac{8\angle 30^\circ}{0.0147\angle -13^\circ} = 544\angle 43^\circ \text{ mV}$$

**Adım 7: Zaman domenine dönüş.** Genlik olduğu gibi başa gelir. Kaynak kosinüs biçiminde olduğu için dönüşüm gerekmez. Not edilen frekans yazılır, çünkü bu frekans devredeki bütün değişkenler için aynıdır. Faz açısı da fazörden gelir:

$$v(t) = 544\cos(2\pi\cdot 10^6\, t + 43^\circ) \text{ mV}$$

> **Ders sonrası not:** Dersteki 544 ve $43^\circ$, ara değerlerin yuvarlanmasından gelir ($8/0.0147 = 544.2$). Python ile hesaplandı: Ara yuvarlama yapılmadan $\mathbf{V} = 545.2\angle 43.19^\circ$ mV bulunur. Bu değerle hesaplanan üç kol akımının toplamı $8\angle 30^\circ$ mA'yı verir.

## 6. Fazör Gösterimi Üstel Biçimle Nasıl İlişkilidir?

Aradan sonra hoca, artık kullanılabilecek her eleman için fazör uzayına geçişin ve pasif elemanların empedans karşılıklarının elde edildiğini söyledi. Bundan sonra devre teorisinde görülen konular fazör uzayında adeta tekrarlanacak. Arka tarafta RLC devreleri çözülüyor olsa da bunlar fazör uzayında direnç devresi gibi çözülebilecek.

Zaman domenine dönerken "reel kısmı almak" ne demektir? Elimizde $A$ genliği ve $\varphi$ açısı olsun, $\omega$ da daha önceden not edilmiş olsun. Bu sayı üstel biçimde $A e^{j\varphi}$ olarak yazılabilir. Not ettiğimiz $\omega$ da üsse getirilirse Euler formülüyle şu elde edilir:

$$A e^{j(\omega t + \varphi)} = A\cos(\omega t + \varphi) + jA\sin(\omega t + \varphi)$$

Reel kısmı almak, yalnız kosinüslü terimi almak demektir. Pratikte ise şöyle akılda tutulabilir: Genliği getir, açıyı getir, not ettiğin $\omega$ ile $\omega t$ yaz, kosinüs biçiminde yaz.

## 7. Fazör Uzayında Ohm Kanunu ve Empedans

Devre teoremlerinin uygulanmasında ilk adım şudur: Fazör uzayında bütün pasif elemanlar için Ohm kanunu geçerlidir. $x$ harfi $R$, $L$ ya da $C$'den biri olmak üzere:

$$\frac{\mathbf{V}_x}{\mathbf{I}_x} = \text{sabit}$$

Elemanın uçlarındaki gerilimin üzerinden geçen akıma oranının sabit olması, Ohm kanununun tam tanımıdır. Bu sabite **empedans** (impedance) denir. Değerleri daha önce bulunmuştu:

$$Z_R = R, \qquad Z_L = j\omega L, \qquad Z_C = \frac{1}{j\omega C}$$

Direnç için bu değer reel bir sayıdır. Endüktans ve kapasite için ise yalnız $j$ çarpanlı terimlerden oluşan karmaşık sayılardır.

### 7.1 Kapasitede Faz Farkı

Hoca, kapasite için $Z_C$'nin paydada karmaşık sayı bırakılmadan da yazılabileceğini gösterdi. Pay ve payda $j$ ile çarpılırsa:

$$Z_C = \frac{1}{j\omega C} = -\frac{j}{\omega C}$$

İkisi aynı şeydir, ama hocaya göre $1/(j\omega C)$ biçimini hatırlamak daha kolaydır.

Bu sonucun anlamı nedir? $-j$ sayısının fazör karşılığı, genliği 1 ve açısı $-90^\circ$ olan sayıdır:

$$\frac{\mathbf{V}_C}{\mathbf{I}_C} = \frac{1}{\omega C}\angle -90^\circ$$

Gerilimin açısı akımın açısından $90^\circ$ daha küçüktür. Yani kapasite elemanında akım, gerilimden $90^\circ$ önde gider.

> **Ders sonrası not:** Hoca bu noktada bir kez "$V_C/I_C$ değerinin eksi $j\omega C$ olması" dedi; doğrusu $-j/(\omega C)$'dir.

### 7.2 Endüktansta Faz Farkı

Endüktans için $Z_L = \mathbf{V}_L/\mathbf{I}_L = j\omega L$ idi. $\omega L$ genlik olarak alınır, $j$ yerine de fazör karşılığı $1\angle 90^\circ$ yazılır. Reel ekseni ve sanal ekseni çizersek $j$ sayısı sanal eksen üzerindedir, açısı $90^\circ$, genliği 1'dir. Buradan gerilimin akımdan $90^\circ$ önde gittiği doğrudan görülür. Yani kimin önde, kimin geride olduğu empedansa bakılarak söylenebilir.

## 8. Admitans ve Uç Frekanslardaki Davranış

Zaman domeninde direnç ve iletkenlik kavramları vardı, $G = 1/R$ idi. Bunun fazör uzayındaki karşılığı **admitanstır**:

$$Y = \frac{1}{Z}$$

Elemanların admitansları şöyledir:

$$Y_R = \frac{1}{R} = G, \qquad Y_C = j\omega C, \qquad Y_L = \frac{1}{j\omega L}$$

Hoca, uç frekanslarda bu değerlerin nasıl değiştiğini tablo üzerinden gösterdi:

| Eleman | $Z$, $\omega = 0$ | $Z$, $\omega \to \infty$ | $Y$, $\omega = 0$ | $Y$, $\omega \to \infty$ |
|---|---|---|---|---|
| Direnç | $R$ | $R$ | $G$ | $G$ |
| Endüktans | $0$ | $\infty$ | $\infty$ | $0$ |
| Kapasite | $\infty$ | $0$ | $0$ | $\infty$ |

<!-- BELİRSİZ: Slayttaki tablonun kendisi altyazıda okunmuyor. Tablo, hocanın sözlü anlatımından ve Y = 1/Z bağıntısından kuruldu. -->

Direnç için frekansla bir değişim olmaz. Endüktansta $\omega = 0$ empedansı sıfırlar, yani DC şartlarda kısa devredir. $\omega$ sonsuz olduğunda ise açık devre gibi çalışır.

> **Ders sonrası not:** Kısa nota göre slayttaki tabloda admitans değerleri "$\infty\ \Omega$", "$0\ \Omega$" diye yazılmıştır; bu altyazıdan doğrulanamadı. $Y = 1/Z$ olduğu için admitansın birimi $\Omega^{-1}$'dir. Bu birimin adı büyük olasılıkla ders kitaplarında siemens (S) olarak geçer.

## 9. Şönt Endüktans ve Şönt Kapasite ile Filtreleme

Hoca uç frekans davranışının anlamını yine filtrelere değerek açıkladı. Çok kaba ve çok ideal durumlar üzerinden konuştuğunu özellikle belirtti.

Bir endüktansın uçlarına giriş sinyali bağlayıp yine uçlarından çıkış almak istediğimizi düşünelim. İlgili dirençler çizilmemiştir, ama var olduğu varsayılır.

- **$\omega = 0$:** Endüktans kısa devre gibi davranır, $V_{out} = 0$ görülür.
- **$\omega \to \infty$:** Endüktans açık devre gibi davranır, karşıda girişteki değer görülür: $V_{out} = V_{in}$.

Demek ki bu bağlantıda endüktans, yüksek frekansları geçiren, düşük frekansları süzen bir filtre elemanı gibi çalışır.

Aynı akıl yürütme kapasite için de yapılır. Kapasite DC şartlarda açık devre gibidir. Dolayısıyla bu bağlantıda düşük frekansları geçirir, yüksek frekansları süzer. Hoca bunun bilinen bir uygulamasını anlattı: Motor uçlarına birer seramik kapasite bağlanır. Amaç, yüksek frekanslı gürültüleri süzerek motorun daha kararlı ve daha gürültüsüz çalışmasını sağlamaktır. Bunun altındaki sebep, frekansa karşılık gerilimin karşıya geçip geçmemesini gösteren filtre cevabıdır.

Admitans için de benzer şeyler söylenebilir, çünkü admitans empedansın bir bölüsüdür. Hoca bu konuya tekrar değinileceği için kısmen önemli olduğunu, detayına sonra bakılacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** Dersteki yorum, elemanın çıkışa paralel (şönt) bağlı olduğu ve girişle arasında bir direnç bulunduğu durum içindir. Aynı endüktans giriş ile çıkış arasına seri bağlanırsa davranış tersine döner. Python ile hesaplandı: Seri $R$ ve şönt $L$ için $|V_{out}/V_{in}|$ düşük frekansta 0, yüksek frekansta 1'e gider. Seri $L$ ve şönt $R$ için ise düşük frekansta 1, yüksek frekansta 0'a gider. Seri $R$ ve şönt $C$ de düşük frekansta 1, yüksek frekansta 0 verir.

## 10. Empedans ve Admitansın Polar ve Kartezyen Gösterimleri

Empedans karmaşık bir sayı olduğu için karmaşık sayılardaki gibi farklı gösterimlere sahiptir. Polar gösterimde genlik ve faz açısıyla, kartezyen gösterimde reel ve sanal kısımla yazılır. Hoca burada kalın $\mathbf{Z}$ ile ince $z$'yi ayırdı: İnce $z$ genliktir.

$$\mathbf{Z} = z\angle\varphi = R + jX$$

**Kartezyenden polara:** Elimizde $R$ ve $X$ vardır, $z$ ve $\varphi$ aranır.

$$z = \sqrt{R^2 + X^2}, \qquad \varphi = \tan^{-1}\frac{X}{R}$$

**Polardan kartezyene:** Elimizde $z$ ve $\varphi$ vardır, $R$ ve $X$ aranır.

$$R = z\cos\varphi, \qquad X = z\sin\varphi$$

Admitans için de aynısı geçerlidir. $\mathbf{Y} = G + jB$ biçiminde yazılırsa genlik $\sqrt{G^2 + B^2}$ olur. Faz açısı, sanal eksendeki değerin reel eksendeki değere oranının arktanjantıdır. Genlik biliniyorsa, genliğin kosinüs $\delta$ ile çarpımı reel bileşeni, sanal eksene izdüşümü de admitansın sanal kısmını verir.

## 11. Seri ve Paralel Bağlı Elemanların Eşdeğer Empedansı

Bir devreyle karşılaşınca yapılacaklar aynıdır: Kaynak mutlaka sinüzoidal olmalıdır. Kaynağın fazör karşılığı hesaplanır, frekansı not edilir, çünkü geri dönerken gerekir. Sonra her pasif eleman için empedans yazılır. Bundan sonra fazör uzayında olduğumuzu unutmadan bir direnç devresi çözer gibi ilerleriz.

### 11.1 Seri Bağlantı

Tek gözlü seri bir devrede bir $\mathbf{V}_s$ kaynağı ile $Z_1$ ve $Z_2$ empedansları bulunsun. Kirchhoff gerilimler yasası uygulanır. Kaynağa eksi ucundan girildiği için $-\mathbf{V}_s$ yazılır.

Pasif elemanlarda gerilim referans yönü, tanımlanan akım referans yönüyle aynı seçilir. Çünkü pasif elemanların enerji tüketmesi gerekir. Enerji tüketebilmesi için üzerindeki akım ve gerilim referans yönlerinin aynı olması gerekir. Böylece:

$$-\mathbf{V}_s + \mathbf{V}_1 + \mathbf{V}_2 = 0, \qquad \mathbf{V}_1 = Z_1\mathbf{I}, \qquad \mathbf{V}_2 = Z_2\mathbf{I}$$

Ana koldan akan akım her iki elemanda da $\mathbf{I}$'dır. Buradan:

$$\mathbf{I} = \frac{\mathbf{V}_s}{Z_1 + Z_2}, \qquad Z_{\text{eş}} = Z_1 + Z_2$$

Tıpkı direnç devrelerinde olduğu gibi, seri bağlı elemanların eşdeğer empedansı toplanarak bulunur.

### 11.2 Paralel Bağlantı

Elimizde bir $\mathbf{I}_s$ akım kaynağı ve ona paralel bağlı $Z_1$, $Z_2$ empedansları olsun. Kaynak akımı giren yönde, kol akımları çıkan yönde alınırsa giren akım çıkanlara eşit olur: $\mathbf{I}_s = \mathbf{I}_1 + \mathbf{I}_2$.

Paralel elemanlarda gerilim düşümü eşit olmak zorundadır, yani $\mathbf{V}$ ikisinde de ortaktır. Ohm kanunundan $\mathbf{I}_1 = \mathbf{V}/Z_1$ ve $\mathbf{I}_2 = \mathbf{V}/Z_2$ yazılır. Bu iki eleman yerine tek bir $Z_{\text{eş}}$ konsaydı $\mathbf{I}_s Z_{\text{eş}} = \mathbf{V}$ olacaktı. Buradan:

$$Z_{\text{eş}} = \frac{1}{\dfrac{1}{Z_1} + \dfrac{1}{Z_2}}, \qquad \frac{1}{Z_{\text{eş}}} = \frac{1}{Z_1} + \frac{1}{Z_2}$$

Bu da paralel direnç devrelerindeki eşdeğer direnç hesabıyla aynı sonuçtur.

### 11.3 Admitans Kullanılırsa

Direnç devrelerinde seri elemanların dirençleri toplanırken, iletkenlik kullanıldığında paralel elemanların iletkenlikleri toplanıyordu. Seri elemanların iletkenliği için ise paralel dirençlerdeki gibi hesap yapılıyordu. Fazör uzayında da aynı karşılıklar geçerlidir: Paralel elemanların admitansları toplanır, seri elemanlarda ise paralel empedans hesabındaki biçim kullanılır.

## 12. Örnek: Seri RL Devresi

Bu örnek kısa notta "Örnek 3" olarak geçer. Fazör uzayı açısından değerlendirildiğinde tek çevreli bir seri devredir.

**Verilen:** $v_1(t) = 12\sin(100t + 30^\circ)$ V, seri bağlı $L = 10$ mH ve $R = 10\ \Omega$. **İstenen:** Ana kol akımı.

Kaynak sinüs biçimindedir. Kosinüse çevirip dönüşte reel kısmı almakta anlaşmıştık. Hoca bunun bir keyfiyet olduğunu özellikle söyledi: Tıpkı referans yönlerinin seçimi gibi. Sinüs üzerinden hesap yapıp fazör uzayından dönerken sanal kısmı almak da bir çözümdür. Ama derste notasyon şöyledir: Fazör için sinyal kosinüse çevrilir, dönüşte reel kısım alınır.

**Adım 1: Frekans.** Açısal frekans $\omega = 100$ rad/s olarak not edilir. Bu değer endüktansın empedansı için kullanılacaktır.

**Adım 2: Empedanslar.** Direnç frekanstan bağımsızdır: $Z_R = 10\ \Omega$. Endüktans için:

$$Z_L = j\omega L = j\cdot 100\cdot 10\cdot 10^{-3} = j\cdot 10^{2}\cdot 10^{-2} = j\ \Omega$$

**Adım 3: Kaynak fazörü.** $\sin\alpha = \cos(90^\circ - \alpha) = \cos(\alpha - 90^\circ)$ kullanılır:

$$12\sin(100t + 30^\circ) = 12\cos(100t + 30^\circ - 90^\circ) = 12\cos(100t - 60^\circ)$$

Genlik 12, faz açısı $-60^\circ$ alınır: $\mathbf{V}_1 = 12\angle -60^\circ$ V. Kosinüs kullanıldığı için dönüşte reel kısım alınacaktır.

**Adım 4: Ana kol akımı.** İki empedans seridir ve eşdeğerleri toplanır:

$$\mathbf{I} = \frac{\mathbf{V}_1}{Z_L + Z_R} = \frac{12\angle -60^\circ}{10 + j}$$

**Adım 5: Paydayı polara çevirme.** Bölme işlemi olduğu için payda polara çevrilir. Genlik $\sqrt{10^2 + 1^2} = \sqrt{101} = 10.05$, açı $\tan^{-1}(1/10) = \tan^{-1}(0.1) = 5.71^\circ$ olur:

$$10 + j = 10.05\angle 5.71^\circ$$

**Soru:** $\sqrt{101}$ nereden geldi? **Cevap:** Kartezyen biçimde karmaşık düzlemde $(10, 1)$ noktasındayız. Bu noktanın merkeze uzaklığı $\sqrt{10^2 + 1^2} = \sqrt{101}$'dir. Paydadaki sayının genliği budur.

**Soru:** Şu anda kartezyenden polara mı çeviriyoruz? **Cevap:** Evet. Bölme işlemi olduğu için, işlemi daha pratik yapabilmek adına polara çeviriyoruz.

Hoca arktanjantı hesap makinesindeki karmaşık sayı dönüşümüyle de gösterdi ve öğrencilerin de aynı fonksiyonu kullanabileceğini söyledi.

**Adım 6: Bölme.** Genlikler bölünür, açılar çıkarılır. Hoca bu adımda paydayı yuvarlanmış olarak $10.1\angle 5.7^\circ$ aldı:

$$\mathbf{I} = \frac{12\angle -60^\circ}{10.1\angle 5.7^\circ} = 1.19\angle -65.7^\circ \text{ A}$$

**Adım 7: Zaman domenine dönüş.** Baştaki anlaşmaya göre genlik alınır, kosinüse $\omega t$ ve faz açısı yazılır:

$$i(t) = 1.19\cos(100t - 65.7^\circ) \text{ A}$$

Sonuç python ile hesaplandı: $Z_{\text{eş}} = 10.05\angle 5.71^\circ\ \Omega$, $\mathbf{I} = 1.194\angle -65.71^\circ$ A. Bu akım zaman domeninde $L\,di/dt + Ri = v_1$ denklemine konduğunda da eşitlik sağlanır. Dersteki sonuç doğrudur.

Gerilimin açısı ($-60^\circ$), akımın açısından ($-65.7^\circ$) daha büyüktür. Bu, endüktans bölümünde görülen "gerilim akımdan öndedir" sonucuyla uyumludur.

## 13. Örnek: Akım Kaynaklı Paralel RCL Devresi

Bu örnek kısa notta "Örnek 4" olarak geçer. Hoca çözümde birkaç hata yaptı, bir bölümünü öğrenci uyarısıyla düzeltti. Burada önce derste izlenen yol, ardından doğru sonuç verilmiştir.

**Verilen:** $i_1(t) = 4\cos(300t - 10^\circ)$ A. Kaynağa paralel $R = 1\ \Omega$, $C = 1$ mF ve $L = 1$ H bağlıdır. **İstenen:** Her kola eşit olarak düşen gerilim $v(t)$.

**Adım 1: Kaynak.** Kaynak kosinüs biçimindedir, doğrudan $\mathbf{I}_1 = 4\angle -10^\circ$ A yazılır ve $\omega$ not edilir. Hoca önce yanlışlıkla $\omega = 100$ yazdı. Öğrenci uyarısıyla $300$ rad/s olarak düzeltti: $\omega$, kaynak ifadesindeki $\omega t$ teriminden okunur.

**Adım 2: Empedanslar.** $Z_R = 1\ \Omega$. Kapasite için:

$$Z_C = \frac{1}{j\omega C} = \frac{1}{j\cdot 300\cdot 10^{-3}} = \frac{10}{3j} = -j\frac{10}{3} = -j3.33\ \Omega$$

Hoca önce paydayı yanlış sadeleştirip $10/15$ ve $-0.66j$ yazdı. Öğrenci "10 bölü 15 değil, 10 bölü 3 olacak" diye uyardı ve düzeltildi. Endüktans için:

$$Z_L = j\omega L = j\cdot 300\cdot 1 = j300\ \Omega$$

**Adım 3: Eşdeğer empedans.** Elemanlar paraleldir:

$$\frac{1}{Z_{\text{eş}}} = \frac{1}{1} + \frac{1}{-j3.33} + \frac{1}{j300}$$

Hoca pratik bir yol olarak bunun admitans cinsinden doğrudan toplanabileceğini, ama aynı hesaba denk geleceğini söyledi. Toplama için MATLAB'dan yararlandı.

**Adım 4: MATLAB ile polar biçim.** MATLAB'da karmaşık sayı $i$ cinsinden yazılır. Hoca şu fonksiyonları kullandı:

- `abs(x)`: Karmaşık sayının genliğini verir, yani reel kısmın karesi ile sanal kısmın karesinin toplamının karekökünü alır.
- `angle(x)`: Faz açısını verir. Hoca açının birimini kontrol etmek için $y = 1 + i$ sayısını denedi. Bu sayının açısı $45^\circ$'dir ve `angle(y)` sonucu radyan çıktı.
- `rad2deg(angle(x))`: Açıyı dereceye çevirir.

**Soru:** Genlik, sanal ve reel kısımlardan mı bulunuyor? **Cevap:** Evet. $Z_{\text{eş}}$ hesaplandıktan sonra polar biçimde yazmak için `abs` alınır, bu da reel kısmın karesi ile sanal kısmın karesinin toplamının kareköküdür.

Hoca derste $Z_{\text{eş}} = 0.9569\angle 16.89^\circ\ \Omega$ sonucunu okudu.

**Adım 5: Gerilim.** Hoca önce bölme yaptı: $4/0.9569 = 4.1802$ ve açı $-10^\circ - 16.89^\circ = -26.89^\circ$. Öğrenci, gerilim bulmak için çarpmak gerektiğini söyleyince hoca işlemi $\mathbf{V} = Z_{\text{eş}}\mathbf{I}_1$ biçiminde düzeltti ve şu sonucu yazdı:

$$\mathbf{V} = 0.9569\angle 16.89^\circ \cdot 4\angle -10^\circ = 3.8276\angle 6.89^\circ \text{ V}, \qquad v(t) = 3.8276\cos(300t + 6.89^\circ) \text{ V}$$

Hoca sonunda öğrencilere işlem hatası olup olmadığını kontrol etmelerini söyledi.

> **Ders sonrası not:** Hoca $Z_{\text{eş}} = 0.9569\angle 16.89^\circ$ ve $v(t) = 3.8276\cos(300t + 6.89^\circ)$ V dedi; doğrusu $Z_{\text{eş}} = 0.9587\angle -16.52^\circ\ \Omega$ ve $v(t) = 3.835\cos(300t - 26.5^\circ)$ V'tur (python ile hesaplandı).
>
> Doğru hesap şöyledir: $1/Z_C = j\omega C = +j0.3$ ve $1/Z_L = -j/300 = -j0.00333$ olduğu için $Y_{\text{eş}} = 1 + j0.29667 = 1.0431\angle 16.52^\circ$ S olur. Tersi alınırsa $Z_{\text{eş}} = 0.9587\angle -16.52^\circ\ \Omega$ çıkar. Sonra $\mathbf{V} = 4\angle -10^\circ \cdot 0.9587\angle -16.52^\circ = 3.835\angle -26.52^\circ$ V bulunur.
>
> Dört işaret birleşimi python ile denendi: $0.9569\angle +16.89^\circ$ sonucunu yalnız kapasite teriminin ters işaretli ($-j0.3003$), endüktans teriminin doğru işaretli ($-j0.00333$) olduğu toplam verir. Bu yüzden derste MATLAB'a kapasite terimi büyük olasılıkla ters işaretle girilmiştir. Altyazıda ifade sözlü olarak "eksi 3.33i" diye okunuyor, ekran görülemediği için yazım doğrulanamadı.
>
> Bu sonuç sezgiyle de uyumludur: $\omega C = 0.3$, $1/(\omega L) = 0.0033$'ten çok büyük olduğu için devre kapasitif davranır. Kapasitede akım gerilimden önde gittiği için gerilimin faz açısı ($-26.5^\circ$), kaynak akımınınkinden ($-10^\circ$) geride kalmalıdır. Dersteki ara sonuç $-26.89^\circ$ bu değere yakın görünse de doğru değildir: Yanlış işaretli $Z_{\text{eş}}$ ile bölme yapıldığı için iki hata açıda birbirini büyük ölçüde götürmüştür.

<!-- BELİRSİZ: Hoca bölmeden sonra slayttaki çözüme bakıp "26.5 bizim de bulduğumuz açı derecesiydi" dedi. Slayttaki değerlerin tamamı altyazıda okunmuyor. Kısa nota göre slayttaki çözüm Y = 1 + j0.297 = 1.04∠16.5°, Z = 0.959∠-16.5° şeklindedir ve bu, python hesabıyla uyumludur. Kare bulunmadığı için slayttan doğrulanamadı. -->

## 14. Fazörün Arkasındaki Tam Gösterim

Örneğin sonunda elde edilen $3.8276\angle 6.89^\circ$ gibi bir fazör gösteriminden hoca neyin kastedildiğini açtı. Bu sayı doğru sonuç olmasa da gösterimin anlamı aynıdır. Fazör uzayında asıl tutulan değer şudur:

$$e^{j\omega t}\cdot A e^{j\varphi}$$

Burada $e^{j\omega t}$ frekansı belirleyen terimdir, $A e^{j\varphi}$ ise fazör terimidir. Derste hep fazör terimiyle ilgilenildi, $e^{j\omega t}$ arka tarafta not edilip bırakıldı. Reel kısmı alınan sayı aslında bu çarpımın tamamıdır. Çarpım tek üste toplanır ve Euler formülü uygulanır:

$$A e^{j(\omega t + \varphi)} = A\cos(\omega t + \varphi) + jA\sin(\omega t + \varphi)$$

Bu sayının reel kısmı alınınca başlangıçtaki $A\cos(\omega t + \varphi)$ kaynak biçimi kalır. "Reel kısmı almak" tam olarak bunu ifade eder.

$e^{j\omega t}$ çarpanı, gizli bir işlenen (operand) gibi kabul edilir. Kaynak fazöre çevrilirken $\omega$ not edilerek arka planda tutulur. Bütün eleman akım ve gerilimlerinde $\omega$ sabit olacağı için bu terim görmezden gelinir, yalnız $A$ genliği ve $\varphi$ faz açısıyla ilgilenilir. Hoca bu kısmın biraz ekstra olduğunu da ekledi.

## 15. Sonraki Konular: Norton, Thevenin, Gerilim ve Akım Bölücü

Eşdeğer empedans ve admitans hesabı paralel ve seri için verildikten sonra sıra Norton ve Thevenin eşdeğerlerine gelir. Hoca bunları çok kabaca tanıttı, ayrıntısı gelecek derse kaldı.

Mantık, zaman domeninde direnç elemanlarından oluşan devreler için anlatılanla aynıdır. Fazör uzayında pasif elemanlardan oluşan devreler için tekrarlanacaktır. Herhangi bir terminalden bakıldığında karmaşık bir devrenin yerine, bir kaynak ile bir Norton ya da Thevenin empedansından oluşan eşdeğer konabilir. Bir yük empedansı sürülmek istendiğinde karmaşık devre yerine bu eşdeğeri koymak yeterli olur. Norton'da eşdeğer empedans paralel, Thevenin'de seri kullanılır.

Gerilim ve akım bölme de benzer şekilde çalışır:

- **Gerilim bölücü:** Zaman domeninde seri bağlı dirençler gerilim bölücüydü. Fazör uzayında seri bağlı empedanslar gerilim bölücü olarak çalışır. Her eleman, empedans değeriyle orantılı bir gerilime sahip olur.
- **Akım bölücü:** Zaman domeninde paralel bağlı dirençler akım bölücüydü. Fazör uzayında paralel bağlı empedanslar akım bölücü olarak çalışır. Karşı koldaki empedans ne kadar yüksekse elemanın üzerinden geçen akım o kadar yüksek olur. Başka bir deyişle akım, elemanın kendi empedansıyla ters orantılıdır.

## 16. Hocanın Önerdiği Pratikler

> **Hocanın vurgusu:** Şu pratikleri mutlaka yapın.

1. **Fazöre çevirme:** Herhangi bir sinüzoidal işaret verildiğinde, sinüs, kosinüs, önünde eksi ya da artı, içinde artı ya da eksi işaret, faz farkı şu ya da bu yönde olsa da fazör uzayına çevirebiliyor muyuz? Bununla ilgili tablo kullanılarak sonuç doğrulanabilir.
2. **Empedans hesabı:** Herhangi bir endüktans ve kapasite elemanı için empedans hesabı nasıl yapılıyor?
3. **Polar ve kartezyen dönüşüm:** Bu dönüşümler ne zaman gerekir? Fazör uzayında seri bir RLC devresi çözülüyorsa eşdeğer empedans için toplama yapılacaktır, bu yüzden kartezyen biçim uygundur. Paralel bir RLC devresinde eşdeğer empedans için çarpma ve bölme gerekir, bu yüzden polar biçimde yazmak daha pratik olabilir. Kaynak polar, eşdeğer empedans kartezyen olduğunda aralarındaki dönüşümün de pratiği yapılmalıdır.

## Dersin Toparlaması

Bu derste sürekli sinüzoidal hâldeki bir devrenin nasıl cebirsel olarak çözüldüğü görüldü. Zaman domenindeki tanım bağıntılarından yola çıkılarak $Z_R = R$, $Z_L = j\omega L$ ve $Z_C = 1/(j\omega C)$ türetildi. Endüktansta gerilimin, kapasitede akımın $90^\circ$ önde gittiği gösterildi. DC şartlardaki kısa devre ve açık devre bilgisi bu formüllerle doğrulandı ve frekansla değişen empedansın filtre tasarımının temeli olduğu görüldü. Ohm kanununun fazör uzayındaki karşılığı olarak $\mathbf{V}_x/\mathbf{I}_x = Z_x$, tersi olarak da admitans tanımlandı. Seri elemanların empedansları, paralel elemanların admitansları toplandı. Üç örnekte yöntemin dört adımı uygulandı: kaynağı fazöre çevirmek, empedansları hesaplamak, devreyi karmaşık sayılarla direnç devresi gibi çözmek ve reel kısmı alarak zaman domenine dönmek.

Gelecek derste fazör uzayında Norton ve Thevenin eşdeğerleri ile gerilim ve akım bölücü devreler ayrıntılı işlenecek, AC devre analizinin ardından frekans cevabı ve Bode diyagramına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
