# Ders 11 Çalışma Özeti

## Genel Konular

- Dönemin genel tekrarı ve kavram haritası
  - Bu ders, dönem başından beri işlenen konuların toplu tekrarı ve soru çözümü olarak yapıldı. Hoca konuları sırayla listeledi: sinyal işlemleri (öteleme, ters çevirme, ölçekleme, tek/çift kısımlar), örnekleme, sistem özellikleri ve testleri, konvolüsyon, frekans uzayı (Fourier serileri ve Fourier dönüşümü) (ekrandan, 00:20:00).
  - Her konunun iki kolu vardır: sürekli zaman ve ayrık zaman.
  - Dönüşümlerin amacı, bir sinyali bilinen temel sinyallerin (sinüs ve kosinüslerin) toplamı olarak ifade etmektir: $x(t)=\sum_{i} A_i\cos(2\pi f_i t+\phi_i)$; ayrık zamanda $t$ yerine $n$ gelir, parantezler köşeli olur (ekrandan, 00:20:00).
- Fourier ailesinin kısaltmaları (ekrandan, 00:20:00)
  - Fourier serileri (periyodik sinyaller): sürekli zamanda FS / CTFS, ayrık zamanda DFS (bazı kaynaklarda DFT diye de geçer).
  - Fourier dönüşümü (periyodik olmayan sinyaller): sürekli zamanda FT / CTFT (Türkçe kaynaklarda "sürekli zamanlı Fourier dönüşümü"), ayrık zamanda DTFT.
  - Ters dönüşümler: IFT / ICTFT ve IDTFT. Bir şeyin dönüşüm sayılması için tersinin de olması gerekir; serilerde ters işlem doğrudan bileşenleri toplamaktır.
- Matematiksel hatırlatmalar
  - Karmaşık düzlemde gerçel kısım $\sigma$, sanal kısım $j\omega$ ile gösterilir: $s=\sigma+j\omega$.
  - $3+4j$ sayısı kutupsal biçimde $5\,e^{j\alpha}$ olarak yazılır; $r=\sqrt{3^2+4^2}=5$, $\tan\alpha=4/3$.
  - Temel integraller: $\int e^{at}\,dt=\frac{e^{at}}{a}$, $\int t^n\,dt=\frac{t^{n+1}}{n+1}$; trigonometrik özdeşlikler ve dönüşüm tabloları bilinmelidir.
- Sinyal işlemleri: öteleme ve ters çevirme
  - Örnek: $x[n]=\{0,\underline{0},1,2,3,3\}$ (altı çizili eleman $n=0$), yani $x[1]=1$, $x[2]=2$, $x[3]=3$, $x[4]=3$ (ekrandan, 00:25:00).
  - $x[-n+2]$ için önce öteleme ($x[n+2]$: iki birim sola), sonra ters çevirme ($n\to -n$) yapılır. Sonuç: $x[-n+2]$ değerleri $n=1,0,-1,-2$ noktalarında sırasıyla $1,2,3,3$ olur (ekrandan, 00:35:00).
  - Genel kural: $A\,g\!\left(\frac{t-t_0}{a}\right)$ elde etmek için sırasıyla genlik çarpımı ($A\,g(t)$), zaman ölçekleme ($t\to t/a$) ve öteleme ($t\to t-t_0$) yapılır (ekrandan, 00:35:00).
- Zamanda ve genlikte çarpma, örnekleme
  - $x(t)=1-|t|$, $-1\le t\le 1$ (başka yerde 0) üçgen sinyali üzerinden: $x(2t)$ zamanda sıkıştırma (downsampling benzeri, iki kat hızlı dinleme), $2x(t)$ genlikte büyütme (sesi açma) demektir (ekrandan, 00:45:00).
  - $T_s=0.25$ s ile örnekleme: $x[n]=x(nT_s)=1-\frac{|n|}{4}$; $x[0]=1$, $x[\pm1]=0.75$, $x[\pm2]=0.5$, $x[\pm3]=0.25$, $x[\pm4]=0$ (ekrandan, 00:55:00).
  - Nyquist şartı: $f_s\ge 2f_{max}$. Örneklenmiş sinyal için $t$ yerine $nT_s=n/f_s$ yazılır ($T_sf_s=1$).
  - $A=\cos(2\pi 300t)+\cos(2\pi 500t)$, $f_s=1000$ Hz: $x[n]=\cos\!\left(\frac{3\pi n}{5}\right)+\cos(\pi n)$ (ekrandan, 00:55:00).
- Periyodiklik
  - $x(t)=\cos(t+\pi/4)$: $\omega_0=1$, $T_0=2\pi$ (ekrandan, 01:00:00).
  - $x(t)=\cos(\pi t/3)+\sin(\pi t/4)$: $T_1=6$, $T_2=8$; oran $6/8$ rasyonel, temel periyot $\mathrm{EKOK}(6,8)=24$ (ekrandan, 01:05:00).
  - $x[n]=\cos n+\sin(\sqrt2\,n)$: $N_1=2\pi$, $N_2=\sqrt2\,\pi$, oran $\sqrt2$ irrasyonel, periyodik değil (ekrandan, 01:05:00).
  - Temel frekans için EBOB, temel periyot için EKOK alınır. Örnek: 150 Hz ve 400 Hz bileşenleri için $f_0=\mathrm{EBOB}(150,400)=50$ Hz, $f_s\ge 800$ Hz (ekrandan, 01:25:00).
- Enerji ve güç
  - $E=\int_{-\infty}^{\infty}|x(t)|^2dt<\infty$ ise enerji sinyali; $P=\frac{1}{T_0}\int_{T_0}|x(t)|^2dt<\infty$ ise güç sinyali (ekrandan, 01:05:00).
  - $x(t)=t\,u(t)$ (rampa): $E=\infty$ ve $P=\infty$ çıkar; ne enerji ne güç sinyalidir (ekrandan, 01:10:00).
- Birim basamak ve dürtü ile işlemler
  - $x(t)u(1-t)$, $x(t)[u(t)-u(t-1)]$ (pencereleme), $x(t)\delta(t-3/2)$ (örnekleme özelliği) (ekrandan, 01:20:00 ve 01:25:00).
  - Ayrık karşılıkları: $x[n]u[1-n]$, $x[n](u[n+2]-u[n])$, $x[n]\delta[n-1]$.
  - Türev: $x(t)=u(t)-u(t-a)$ için $x'(t)=\delta(t)-\delta(t-a)$; $\mathrm{sgn}(t)$ için $\frac{d}{dt}\mathrm{sgn}(t)=2\delta(t)$ (ekrandan, 01:30:00 ve 01:35:00).
- Sistem özellikleri
  - $y(t)=x(t)\cos\omega t$ (modülatör): belleksiz, nedensel, lineer, zamanla değişen, BIBO kararlı (ekrandan, 01:35:00 ve 01:40:00).
  - $y[n]=n\,x[n]$: belleksiz, nedensel, lineer, zamanla değişen, kararsız.
- Tek ve çift kısımlar
  - $g_e[n]=\frac{g[n]+g[-n]}{2}$, $g_o[n]=\frac{g[n]-g[-n]}{2}$ (ekrandan, 01:45:00).
  - $g[n]=\sin(2\pi n/7)(1+n^2)$ için $g_e[n]=0$, $g_o[n]=g[n]$: sinyal tektir.
- Konvolüsyon
  - Sürekli: $x(t)=u(t)-u(t-3)$, $h(t)=u(t)-u(t-2)$; $y(t)=t\,u(t)-(t-2)u(t-2)-(t-3)u(t-3)+(t-5)u(t-5)$. Grafik: $0$–$2$ arası artan, $2$–$3$ arası 2'de plato, $3$–$5$ arası azalan yamuk (ekrandan, 01:50:00 ve 02:00:00).
  - Ayrık: dört birlik ve üç birlik dizilerin konvolüsyonu dürtülerin dağılma özelliğiyle $\{1,2,3,3,2,1\}$ bulunur (ekrandan, 02:15:00).
- Fourier serileri
  - Üstel biçim: $x(t)=\sum_{k=-\infty}^{\infty}c_k e^{jk\omega_0t}$, $c_k=\frac{1}{T_0}\int_{T_0}x(t)e^{-jk\omega_0t}dt$, $c_0=\frac{1}{T_0}\int_{T_0}x(t)dt$ (DC bileşen) (ekrandan, 02:20:00).
  - Trigonometrik biçim: $x(t)=\frac{a_0}{2}+\sum(a_k\cos k\omega_0t+b_k\sin k\omega_0t)$; $a_0=2c_0$, $a_k=2\,\mathrm{Re}\{c_k\}$, $b_k=-2\,\mathrm{Im}\{c_k\}$.
  - Kare dalga örneği (genlik $A$, $|t|<T_0/4$ aralığında $A$): $c_k=\frac{A}{k\pi}\sin\frac{k\pi}{2}$, $c_0=\frac{A}{2}$ (ekrandan, 02:30:00).
- Fourier dönüşümü ve özellikleri
  - $X(\omega)=\int x(t)e^{-j\omega t}dt$, $x(t)=\frac{1}{2\pi}\int X(\omega)e^{j\omega t}d\omega$ (ekrandan, 02:35:00).
  - Türev $\leftrightarrow j\omega X(\omega)$; öteleme; konvolüsyon $\leftrightarrow$ çarpım; frekans cevabı $H(\omega)=Y(\omega)/X(\omega)$; dürtü cevabı $h(t)=\mathcal{F}^{-1}\{H(\omega)\}$ (ekrandan, 02:45:00).
  - DTFT: $X(\Omega)=\sum_n x[n]e^{-j\Omega n}$, $x[n]=\frac{1}{2\pi}\int_{2\pi}X(\Omega)e^{j\Omega n}d\Omega$.
- Uygulamalar
  - Radyo: istenen kanalın bandını geçiren, diğerlerini bastıran bant geçiren filtre.
  - Kontrol: bir seranın sıcaklık modeli gibi sistemlerin diferansiyel denklemi Laplace/Fourier ile transfer fonksiyonuna çevrilir.
  - Diferansiyel denklem örneği: $y'(t)+2y(t)=x(t)+x'(t)$ $\Rightarrow$ $H(\omega)=\frac{1+j\omega}{2+j\omega}=1-\frac{1}{2+j\omega}$ $\Rightarrow$ $h(t)=\delta(t)-e^{-2t}u(t)$ (ekrandan, 02:50:00 ve 02:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- $x[-n+2]$ gibi bileşik işlemlerde sıra
  - Önce öteleme, sonra ters çevirme yapılır. "Eksiyle çarpmak" genlikleri eksi yapmak değildir; yalnız $n$ yerine $-n$ yazılır. Kontrol yöntemi: bir değerin hangi $n$'de oluştuğunu, argümanı eşitleyerek bulmak ($-n+2=2\Rightarrow n=0$).
- Zamanda çarpma ile genlikte çarpma farklıdır
  - "2 ile çarpın" ifadesi belirsizdir; soru, zaman ekseninde mi ($x(2t)$) genlik ekseninde mi ($2x(t)$) olduğunu belirtmelidir.
- $nT_s$ ile $n/f_s$ aynıdır
  - Bazı kitaplar $t=nT_s$, bazıları $t=n/f_s$ yazar; $T_sf_s=1$ olduğu için ikisi eşdeğerdir.
- Türev bir değişimdir
  - Türev farkı, değişimi gösterir; basamaktaki ani sıçrama türevde dürtü olarak görünür.
- Linearlik testinde $x(t)$ yerine yeni sinyal verilir, $t$ yerine değil
  - $\cos\omega t$ yalnız zamana bağlı ayrı bir sinyaldir; içine $x_1+x_2$ yazılmaz.
- Fourier dönüşümünün türev ve konvolüsyon özellikleri
  - Diferansiyel denklem çözmek yerine türevi $j\omega$ ile çarpmak, konvolüsyon yerine frekans düzleminde çarpım almak sistem modellemede çok kullanılır.

## Kısa Tekrar Notları

- Fourier serisi periyodik, Fourier dönüşümü periyodik olmayan sinyaller içindir; ikisinin de sürekli ve ayrık sürümü vardır.
- Öteleme sonra ters çevirme: $x[n]\to x[n+2]\to x[-n+2]$.
- $A\,g((t-t_0)/a)$: önce $A$, sonra $t\to t/a$, sonra $t\to t-t_0$.
- Örnekleme: $x[n]=x(nT_s)$, $f_s\ge 2f_{max}$.
- Sürekli zamanda periyotların oranı rasyonelse toplam periyodiktir; temel periyot EKOK, temel frekans EBOB.
- Ayrık zamanda $2\pi/\Omega$ rasyonel değilse sinüzoid periyodik değildir.
- Rampa $t\,u(t)$ ne enerji ne güç sinyalidir.
- $x(t)\delta(t-t_0)=x(t_0)\delta(t-t_0)$: dürtü bir örnekleme elemanıdır.
- $\frac{d}{dt}u(t)=\delta(t)$, $\frac{d}{dt}\mathrm{sgn}(t)=2\delta(t)$.
- $y(t)=x(t)\cos\omega t$: lineer ama zamanla değişen; $\cos$ sınırlı olduğu için kararlı.
- $y[n]=n\,x[n]$: lineer, zamanla değişen, kararsız.
- İki dikdörtgenin (genişlik 3 ve 2) konvolüsyonu yamuktur: $0$–$2$ artış, $2$–$3$ plato, $3$–$5$ azalış.
- $\{1,1,1,1\}*\{1,1,1\}=\{1,2,3,3,2,1\}$.
- Kare dalga: $c_k=\frac{A}{k\pi}\sin\frac{k\pi}{2}$, $c_0=A/2$.
- $y'+2y=x+x'$ için $h(t)=\delta(t)-e^{-2t}u(t)$.

## Detaylı Açıklamalar

- **Öteleme ve ters çevirme örneği.** $x[n]$ dizisi $n=-1$ ve $n=0$'da 0, $n=1,2,3,4$'te sırasıyla $1,2,3,3$ değerini alır (ekrandan, 00:25:00). Hoca $x[-n+2]$'yi önce ters çevirip sonra öteleyerek çizmeye başladı, bir öğrencinin uyarısıyla düzeltti: doğru sıra önce $x[n+2]$'yi bulmak (bütün örnekler iki birim sola kayar: $x[n+2]$, $n=-1,0,1,2$'de $1,2,3,3$), sonra $n$ yerine $-n$ yazmaktır. Sonuçta $x[-n+2]$, $n=1,0,-1,-2$'de $1,2,3,3$ olur (ekrandan, 00:35:00). Bir öğrencinin önerdiği sağlama: orijinalde $x[2]=2$ olduğuna göre $-n+2=2$ denkleminden $n=0$ bulunur, yani yeni dizide 2 değeri $n=0$'dadır.
- **Örnekleme ve ayrık denklem.** $x(t)=\cos(2\pi f t)$ sinyali $f_s=2f$ ile örneklenirse $T_s=\frac{1}{2f}$ ve $x[n]=\cos(2\pi f\,nT_s)=\cos(\pi n)$ olur; $f$'ler sadeleşir (ekrandan, 00:55:00). İki bileşenli $\cos(2\pi300t)+\cos(2\pi500t)$ için en büyük frekans 500 Hz olduğundan $f_s=1000$ Hz seçilir ve $x[n]=\cos(3\pi n/5)+\cos(\pi n)$ bulunur. Sinyal açık biçimde verilmeyebilir: $\cos(600\pi t)=\cos(2\pi\cdot300\,t)$ yazılarak frekansın 300 Hz olduğu görülür. Hoca, bu sürekli ve ayrık sürümleri MATLAB'de `plot` ve `stem` ile çizdirerek karşılaştırmayı önerdi.
- **Periyodiklik.** Sürekli zamanda her bileşenin periyodu $T_i=2\pi/\omega_i$ ile bulunur; oranlar rasyonelse toplam periyodiktir ve temel periyot EKOK'tur ($\pi/3$ ve $\pi/4$ için $6$ ve $8$, EKOK 24). Ayrık zamanda $\cos n+\sin\sqrt2 n$ örneğinde $N_1=2\pi$, $N_2=\sqrt2\pi$ ve oran $\sqrt2$ irrasyonel olduğu için sinyal periyodik değildir (ekrandan, 01:05:00).
- **Enerji ve güç: rampa.** $x(t)=t\,u(t)$ için $E=\lim_{T\to\infty}\int_0^{T/2}t^2dt=\lim\frac{(T/2)^3}{3}=\infty$ ve $P=\lim_{T\to\infty}\frac1T\int_{-T/2}^{T/2}t^2u(t)\,dt=\lim\frac{(T/2)^3}{3T}=\infty$ çıkar (ekrandan, 01:10:00); rampa ne enerji ne güç sinyalidir.
- **Birim basamak ve dürtü ile işlemler.** Verilen $x(t)$ (ekrandan, 01:20:00): $-1\le t\le0$ aralığında $0$'dan $1$'e doğrusal artan, $0\le t\le1$ aralığında 1, $1<t\le2$ aralığında 2 olan bir parçalı sinyal. $x(t)u(1-t)$ sinyalin $t\le1$ kısmını, $x(t)[u(t)-u(t-1)]$ yalnız $0\le t\le1$ kısmını geçirir (pencere ya da süzgeç gibi), $x(t)\delta(t-3/2)$ ise $t=1.5$'teki değeri (2) çekerek $2\,\delta(t-1.5)$ verir. Dürtüyü sinyal üzerinde gezdirmek sinyalin bütün değerlerini tek tek almak, bir anlamda "röntgenini çekmek"tir. Ayrık sürümde $x[n]u[1-n]$ $n\le1$ örneklerini, $x[n](u[n+2]-u[n])$ yalnız $n=-2,-1$ örneklerini, $x[n]\delta[n-1]$ yalnız $x[1]$'i bırakır. <!-- BELİRSİZ: ayrık x[n] dizisinin tek tek değerleri karede tam okunamadı (01:20:00); bu yüzden sonuçlar yalnız hangi örneklerin kaldığı olarak yazıldı. -->
- **Türev.** $x(t)=u(t)-u(t-a)$ dikdörtgeninin türevi, yukarı sıçramada $\delta(t)$, aşağı sıçramada $-\delta(t-a)$'dır. $\mathrm{sgn}(t)=u(t)-u(-t)$ yazılırsa türevi $\delta(t)+\delta(t)=2\delta(t)$ olur; sıçrama $-1$'den $+1$'e iki birimlik olduğu için dürtünün ağırlığı 2'dir (ekrandan, 01:35:00).
- **Sistem özellikleri: $y(t)=x(t)\cos\omega t$.** Çıkış yalnız şimdiki girişe bağlı olduğundan belleksiz ve nedenseldir. Toplamsallık: $x_1+x_2$ girişi $(x_1+x_2)\cos\omega t=y_1+y_2$ verir; çarpımsallık: $Ax$ girişi $A\,y$ verir; ikisi birlikte süperpozisyon, yani lineer. Zamanla değişmezlik: girişi geciktirince $x(t-\tau)\cos\omega t$, çıkışı geciktirince $x(t-\tau)\cos\omega(t-\tau)$ çıkar; eşit olmadığından zamanla değişendir (ekrandan, 01:40:00). $|\cos\omega t|\le1$ olduğu için sınırlı giriş sınırlı çıkış verir: kararlı.
- **Sürekli konvolüsyon (analitik).** $y(t)=\int[u(\tau)-u(\tau-3)][u(t-\tau)-u(t-\tau-2)]d\tau$ dört integrale açılır. Her birinin birim olduğu aralık bulunur: (1) $0<\tau<t$ → $t\,u(t)$; (2) $0<\tau<t-2$ → $(t-2)u(t-2)$; (3) $3<\tau<t$ → $(t-3)u(t-3)$; (4) $3<\tau<t-2$ → $(t-5)u(t-5)$ (ekrandan, 02:00:00). Toplam yamuktur: tepe değeri 2, $2\le t\le3$ arası plato.
- **Ayrık konvolüsyon (dağılma özelliği).** $x[n]=\delta[n]+\delta[n-1]+\delta[n-2]+\delta[n-3]$, $y[n]=\delta[n]+\delta[n-1]+\delta[n-2]$. $x[n]*\delta[n-k]=x[n-k]$ olduğundan $x*y=x[n]+x[n-1]+x[n-2]$; aynı gecikmeli dürtüler toplanınca $\delta[n]+2\delta[n-1]+3\delta[n-2]+3\delta[n-3]+2\delta[n-4]+\delta[n-5]$ (ekrandan, 02:15:00). Kaydır-çarp-topla yöntemi aynı sonucu verir; işlem polinom çarpmasına benzer.
- **Kare dalganın Fourier serisi.** $T_0$ periyotlu, $|t|<T_0/4$'te $A$ olan kare dalga için $c_k=\frac1{T_0}\int_{-T_0/4}^{T_0/4}Ae^{-jk\omega_0t}dt=\frac{A}{-jk\omega_0T_0}\left(e^{-jk\pi/2}-e^{jk\pi/2}\right)=\frac{A}{k\pi}\sin\frac{k\pi}{2}$ ve $c_0=A/2$ (ekrandan, 02:30:00). Sinyal çift olduğu için yalnız kosinüs terimleri kalır.
- **Diferansiyel denklemden dürtü cevabı.** $y'+2y=x+x'$ denkleminin Fourier dönüşümü $(2+j\omega)Y=(1+j\omega)X$ verir; $H(\omega)=\frac{1+j\omega}{2+j\omega}=1-\frac{1}{2+j\omega}$; tablolardan $\mathcal F^{-1}\{1\}=\delta(t)$ ve $\mathcal F^{-1}\{\frac1{2+j\omega}\}=e^{-2t}u(t)$; dolayısıyla $h(t)=\delta(t)-e^{-2t}u(t)$ (ekrandan, 02:55:00). Bir sonraki adım olarak ayrık zamanda fark denklemleri (ör. $y[n]-\frac34y[n-1]$ içeren) aynı yolla DTFT ile çözülür; çözüm üstel $a^n$ biçimli terimler içerir.
- **Ders sonrası notlar.**
  - Hoca kare dalga örneğinde $a_k$'ların sinyal tek olduğu için sıfır çıktığını ve $b_k=(-1)^k\frac{2A}{(2k+1)\pi}$ olduğunu söyledi; doğrusu: $|t|<T_0/4$ aralığında merkezlenmiş kare dalga **çifttir**, $b_k=0$ ve $a_k=2c_k=\frac{2A}{k\pi}\sin\frac{k\pi}{2}$; tek $k=2m+1$ için $a_{2m+1}=(-1)^m\frac{2A}{(2m+1)\pi}$.
  - Hoca $\sin(k\pi/2)$ değerlerini "1, 1, 1, 0" diye saydı; doğrusu $k=1,2,3,4$ için $1,0,-1,0$.
  - Tahtada dürtü cevabı $\delta(t)-e^{2t}u(t)$ yazıldı; doğrusu $h(t)=\delta(t)-e^{-2t}u(t)$ ($\frac{1}{2+j\omega}\leftrightarrow e^{-2t}u(t)$).
  - Tahtada öteleme özelliği $x(t-t_0)\leftrightarrow X(\omega)e^{j\omega_0t}$ biçiminde yazıldı; doğrusu $x(t-t_0)\leftrightarrow X(\omega)e^{-j\omega t_0}$.
  - Tahtada $\cos(300t)+\cos(800t)$ yazıldı ve frekanslar 150 Hz ile 400 Hz olarak okundu; bu frekanslar ancak $\cos(300\pi t)+\cos(800\pi t)$ için doğrudur ($\pi$ büyük olasılıkla unutuldu).
  - $y[n]=n\,x[n]$ için altyazıda zamanla değişmezlik kısmı bozuk; doğrusu sistem zamanla **değişendir** ($n$ katsayısı zamana bağlıdır).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
