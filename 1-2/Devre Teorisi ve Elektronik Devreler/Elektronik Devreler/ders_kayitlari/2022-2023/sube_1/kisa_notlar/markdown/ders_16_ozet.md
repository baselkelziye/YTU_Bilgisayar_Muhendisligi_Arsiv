# Ders 16 Çalışma Özeti

## Genel Konular

- Konu sırası ve işlemsel yükselteçlerin araya alınması
  - BJT'lerden sonra normalde FET'ler (MOSFET tabanlı transistörler) gelir. Bu derste araya işlemsel yükselteçler (operational amplifiers, op-amp) alınır; FET'lere sonraki haftalarda devam edilecektir (ekrandan, 00:10:00).
- İşlemsel yükseltecin kullanım amacı
  - Adı üstünde, küçük bir giriş işaretini daha büyük bir işarete yükseltmek için kullanılır.
  - Örnek kullanım: haberleşme devrelerinde gelen çok zayıf sinyallerin işlenebilmesi için yükseltilmesi; uydu yayıncılığında uydudan gelen zayıf sinyallerin yükseltilip temizlenmesi.
- Paketler ve bacak numaralandırma (ekrandan, 00:15:00)
  - İki tip paket yapısı anılır: yüzeye montajlı SMD (Surface Mounted Device) paketler ve delikli kartlara takılıp lehimlenen paketler. Delikli paketler daha eski teknolojidir ama prototip ve hızlı devre kurmada hâlâ kullanılır.
  - Paketteki nokta ya da çentik referans alınır; bacaklar 1'den başlayarak saat yönünün tersine numaralandırılır.
  - Tekli op-amp (8 bacak): 2 eviren giriş (Inv inp), 3 evirmeyen giriş (Non-inv inp), 4 $V_{neg}$, 6 çıkış, 7 $V_{pos}$. 1, 5 ve 8 numaralı bacaklar derste boş olarak anıldı.
  - İkili op-amp (8 bacak): 1 çıkış, 2 eviren giriş, 3 evirmeyen giriş, 4 $V_{neg}$; ikinci op-amp 5-7 numaralı bacaklardadır, besleme ortaktır.
  - 14 bacaklı bir paketin içine dört op-amp sığdırılabilir. Paketin içeriği üretici belgelerinden (spec) okunur.
- Op-amp sembolü
  - Üçgen biçiminde; iki girişi ($-$ eviren, $+$ evirmeyen) ve bir çıkışı vardır. "Evirmek" İngilizce *invert* kelimesinden gelir, tersine çevirmek demektir.
  - Ayrıca pozitif ve negatif besleme uçları vardır; bunlar şekilde ayrıca çizilebilir ya da gösterilmeyebilir.
- İdeal op-amp
  - Gerilim kazancı sonsuz, giriş direnci sonsuz, çıkış direnci sıfırdır.
- Gerilim kazancı ve evirme
  - Gerilim kazancı $A_v = G = V_o/V_i$'dir; girişin ne kadar kuvvetlendirildiğinin ölçüsüdür. İngilizcede *gain* denir.
  - $A_v = 2$ ise 1 V'luk giriş 2 V olur; sinüsün tepe değeri iki katına çıkar.
  - $A_v$ negatifse çıkış evrilmiştir: pozitif değerler negatife, negatifler pozitife döner. Bu, giriş ile çıkış arasında 180 derecelik ($\pi$ kadar) faz farkı demektir.
- Bütün op-amp çözümlerinin iki temel varsayımı
  - $V_- = V_+$: giriş direnci sonsuz kabul edildiği için iki giriş ucunun gerilimi eşittir.
  - $I_- = I_+ = 0$: op-amp'in girişlerinden içeri akım girmez.
- Evirmeyen yükselteç (non-inverting amplifier) (ekrandan, 00:25:00 ve 00:30:00)
  - Giriş $+$ uca verilir; $-$ uç, çıkış ile toprak arasındaki $R_1$ (üstte, geri besleme) ve $R_2$ (altta, toprağa) dirençlerinin ortasına bağlıdır.
  - Gerilim bölücüden: $V_i = \dfrac{R_2}{R_1 + R_2} V_o$, buradan $G = \dfrac{V_o}{V_i} = \dfrac{R_1 + R_2}{R_2}$.
  - Aynı sonuç akım eşitliğinden de çıkar: $\dfrac{V_o - V_i}{R_1} = \dfrac{V_i - 0}{R_2}$.
  - Dirençler daima pozitif olduğu için $G$ pozitiftir; çıkış evrilmez. Kazanç direnç oranıyla ayarlanır.
- Eviren yükselteç (inverting amplifier) (ekrandan, 00:35:00)
  - Giriş $R_2$ üzerinden $-$ uca verilir; $R_1$ çıkış ile $-$ uç arasındaki geri besleme direncidir; $+$ uç topraktadır, bu yüzden $V_- = V_+ = 0$.
  - $\dfrac{V_i - 0}{R_2} = \dfrac{0 - V_o}{R_1}$, buradan $A_v = \dfrac{V_o}{V_i} = -\dfrac{R_1}{R_2}$.
  - Baştaki eksi işareti girişle çıkış arasındaki 180 derecelik faz farkını gösterir.
- Birim kazançlı tampon (buffer, gerilim izleyici)
  - Çıkış doğrudan $-$ uca bağlıdır: $V_o = V_- = V_+ = V_i$. Kazanç yoktur.
  - Girişten akım çekmediği için giriş ve çıkışı birbirinden yalıtır; yüksek giriş direnci ve düşük çıkış direnci sayesinde koruma amaçlı, örneğin işlemci bacak çıkışlarında kullanılır.
- Akımdan gerilime dönüştürücü (ekrandan, 00:40:00)
  - Giriş akımı $I_i$ doğrudan $-$ uca girer, geri besleme yolunda $R$ vardır; $+$ uç topraktadır.
  - $I_i = -I_R = -\dfrac{V_o - 0}{R}$, buradan $V_o = -I_i R$.
  - Yalnız voltmetre varken akım ölçmek için kullanılabilir. $R = 1\ \Omega$ ise çıkış sayıca akımın eksilisidir; $R = 1$ k$\Omega$ ise ölçülen gerilim 1000'e bölünerek akım bulunur.
- Fark yükselteci (çıkarıcı, differential amplifier) (ekrandan, 00:45:00)
  - $V_2$, $R_2$ üzerinden $-$ uca; $V_1$, $R_2$ üzerinden $+$ uca girer; $+$ uçtan toprağa $R_1$, çıkıştan $-$ uca $R_1$ bağlıdır.
  - $V_+ = \dfrac{R_1}{R_1 + R_2} V_1$; $-$ uçtaki akım eşitliğinden $V_- = \dfrac{R_1 V_2 + R_2 V_o}{R_1 + R_2}$.
  - $V_+ = V_-$ yazılınca $V_o = (V_1 - V_2)\dfrac{R_1}{R_2}$ bulunur. $R_1 = R_2$ ise devre yalnız çıkarma yapar.
- Eviren toplayıcı (inverting summing amplifier)
  - Giriş gerilimlerini toplar, ama toplam 180 derece faz farkıyla (eksi işaretli) oluşur.
  - $-$ uç sıfır kabul edilir; düğümde $I_1 + I_2 = -I_3$ yazılır; her giriş akımı $V_k/R$, geri besleme akımı $V_o/R$ biçiminde yazılarak çözülür. <!-- BELİRSİZ: Toplayıcı devresinin direnç adları altyazıda karışık, ilgili an için kare yok. -->
- İntegral alıcı ve türev alıcı (ekrandan, 00:50:00)
  - İntegral alıcıda geri besleme yolunda kondansatör, girişte direnç vardır: $V_o = -\dfrac{1}{RC}\displaystyle\int_0^t V_i\,dt$. Giriş evrilerek "toplanır" (integrali alınır).
  - Kondansatör ile direncin yeri değiştirilince devre türev alıcı olur; çıkıştan girişin değişiminin (türevinin) okunduğu söylenir. <!-- BELİRSİZ: Türev alıcı slaytının formülü için kare yok. -->

## Hocanın Özellikle Vurguladığı Kısımlar

- Bütün op-amp sorularında aynı iki varsayım kullanılır
  - $V_- = V_+$ ve $I_- = I_+ = 0$. $V_+$ her zaman toprağa bağlı olmayabilir; o zaman $V_+$ ayrıca (örneğin gerilim bölücüyle) bulunur.
- Devre tiplerini ezberlemek gerekmez
  - Önemli olan verilen devreyi bu iki varsayım, düğüm akımları ve Ohm yasasıyla çözebilmektir.
- Eksi kazancın anlamı
  - Eksi işaret 180 derecelik faz farkını, yani işaretin tersine dönmesini gösterir.
- Direnç oranı kazancı belirler
  - Evirmeyende $(R_1 + R_2)/R_2$, evirende $-R_1/R_2$. Fark yükseltecinde dirençler yalnız bir çarpan gibi düşünülebilir; asıl işlev farkı almaktır.
- Birimlere dikkat
  - Hesaplarda miliamper ve mikroamper yerine amper yazmak gibi birim hataları yapılmamalıdır.

## Kısa Tekrar Notları

- İdeal op-amp: $A \to \infty$, $R_{in} \to \infty$, $R_{out} = 0$.
- Çözüm anahtarları: $V_- = V_+$, $I_- = I_+ = 0$.
- Evirmeyen: $G = 1 + R_1/R_2$ (pozitif, evirmez). $G = 25$ için $R_2 = 1$ k$\Omega$, $R_1 = 24$ k$\Omega$.
- Eviren: $A_v = -R_1/R_2$ (evirir, 180°). $R_1 = 10$ k$\Omega$, $R_2 = 1$ k$\Omega$ ise $A_v = -10$.
- Tampon: $V_o = V_i$, yalıtım sağlar.
- Akımdan gerilime: $V_o = -I_i R$.
- Fark yükselteci: $V_o = (V_1 - V_2) R_1/R_2$.
- Eviren toplayıcı: girişlerin eksi işaretli toplamı.
- İntegral alıcı: $V_o = -\frac{1}{RC}\int_0^t V_i\,dt$; türev alıcıda R ve C yer değiştirir.

## Detaylı Açıklamalar

- İşlemsel yükselteç, iki girişli ve tek çıkışlı bir yükselteç bloğudur. Derste iç yapısına girilmez; ideal op-amp tanımından yola çıkılarak hesap yapılır. İdeal op-amp'te gerilim kazancı sonsuz, iki giriş ucu arasında ölçülecek direnç sonsuz, çıkış direnci sıfırdır. Giriş direnci çok yüksek olduğu için uçlardan içeri akım akmıyormuş gibi kabul edilir ($I_- = I_+ = 0$) ve iki giriş ucunun gerilimi birbirine eşit alınır ($V_- = V_+$). Bütün devreler bu iki kabulle, Ohm yasası ve düğümdeki akım eşitliğiyle çözülür.
- Evirmeyen yükselteçte giriş $+$ uca verildiği için $V_- = V_i$ olur. $-$ uç, çıkışla toprak arasındaki $R_1$-$R_2$ gerilim bölücüsünün orta noktasıdır. Bu yüzden $V_i = V_o R_2/(R_1 + R_2)$ ve $G = (R_1 + R_2)/R_2$ bulunur. Aynı sonuç, $-$ uca akım girmediği için $R_1$ ve $R_2$ üzerinden aynı akımın geçtiği yazılarak da elde edilir. Örneğin iki direnç de 1 k$\Omega$ ise kazanç 2; $R_1 = 1$ k$\Omega$, $R_2 = 2$ k$\Omega$ ise kazanç $3/2$ olur. Slayttaki örnekte 25 kazançlı bir evirmeyen yükselteç için $R_1 = 24R_2$ seçilir, $R_2 = 1$ k$\Omega$ ve $R_1 = 24$ k$\Omega$ alınır; 10 mV'lik giriş 250 mV'lik, evrilmemiş bir çıkış verir (ekrandan, 00:30:00).
- Eviren yükselteçte $+$ uç toprağa bağlı olduğu için $V_- = 0$'dır. Girişten $R_2$ üzerinden gelen akım, op-amp'e girmeyip tamamen $R_1$ üzerinden çıkışa gider: $V_i/R_2 = -V_o/R_1$. Buradan $A_v = -R_1/R_2$. Akım yönünü ters kabul etmek sonucu değiştirmez; yalnız gerilim farkları yöne göre ters yazılır. $R_1 = 10$ k$\Omega$ ve $R_2 = 1$ k$\Omega$ için kazanç $-10$'dur; çıkış girişin on katı ve ters işaretlidir.
- Tampon devre gerilim kazancı sağlamaz ama girişten akım çekmediği ve çıkış direnci düşük olduğu için önceki devreyi sonraki yükten yalıtır. Akımdan gerilime dönüştürücüde ise giriş bir akımdır; $V_o = -I_i R$ olduğu için çıkış gerilimi ölçülerek akım bulunur, ölçülen dalga akımın 180 derece faz farklı hâlidir.
- Fark yükseltecinde iki giriş vardır. $+$ ucun gerilimi $V_1$'in $R_2$-$R_1$ bölücüsündeki payıdır. $-$ uç için $V_2$'den $R_2$ üzerinden gelen akım $R_1$ üzerinden çıkışa gider: $(V_2 - V_-)/R_2 = (V_- - V_o)/R_1$. İki ifade eşitlenince $V_o = (V_1 - V_2)R_1/R_2$ çıkar. $R_1 = 2R_2$ seçilirse farkın iki katı alınır; dirençler eşitse devre basit bir çıkarıcıdır.
- Eviren toplayıcıda $-$ uç yine sıfır kabul edilir; girişlerden gelen akımların toplamı geri besleme akımının eksisine eşittir. İntegral alıcıda geri besleme elemanı kondansatördür ve çıkış girişin integralinin eksi işaretlisidir; $R$ ve $C$ 1 kabul edilirse devre doğrudan eviren bir integral alıcı gibi düşünülebilir. Kondansatör ve direncin yerleri değiştirilince devre türev alır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
