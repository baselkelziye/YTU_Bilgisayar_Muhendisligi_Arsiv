# Ders 3 Çalışma Özeti

## Genel Konular

- İşaret (sinyal) ve sistem tanımları
  - İşaret: fiziksel bir durum hakkında bilgi taşıyan, bir ya da birden fazla değişkene bağlı fonksiyondur. Bir boyutlu işarette değişken zamandır ($x(t)$). Gri seviyeli görüntü iki uzamsal (spatial) değişkene, MR gibi katmanlı biyomedikal görüntüler üç değişkene bağlıdır.
  - Örnekler: radyo işareti, yayın ya da kablo TV, ses, devredeki gerilim ya da akım; daha genel olarak ölçülebilen her fiziksel ya da soyut büyüklük (bisiklet fren kablosundaki gerginlik, uzay aracının dönme hızı, hücredeki enzim derişimi, döviz kuru) (ekrandan, 00:10:00).
  - Sistem: istenen nitelikte işaret üreten ya da verilen giriş işaretlerine göre belirli çıkışlar üreten düzenektir. Girişteki işaret kutu içinde işlenir, çıkışta değiştirilmiş işaret elde edilir.
  - Sistem örnekleri: kütle-yay sistemi, iki tanklı sıvı sistemi, cep telefonu şebekesi, radyo alıcısı, mikrofon, hücresel metabolizma, ekonomik sistemler.
- Frekans domeni neden önemli?
  - Her işaret, farklı genlik ve frekanstaki sinüzoidallerin toplamı olarak yazılabilir. Domain "uzay" anlamındadır: zaman domeni (yatay eksen $t$) ve frekans domeni (yatay eksen $f$).
  - Frekans gösterimi birçok işaret için daha basittir, doğrusal (linear) sistemlerin analizini kolaylaştırır ve sistemin temel karakteristiklerini ortaya çıkarır (ekrandan, 00:25:00).
  - Piyano örneği: bir akorun zaman domenindeki görüntüsünden hangi tuşlara basıldığı anlaşılmaz; frekans domeninde akoru oluşturan birkaç temel frekans ve harmonikleri ayrı ayrı görülür.
  - Araba ve kaldırım örneği: arabanın dinamiği diferansiyel denklemlerle verilir ve doğrudan çözmek zordur; frekans domeninde basit bir transfer fonksiyonuyla çözülür (ekrandan, 00:30:00).
  - Hız sabitleme örneği: istenen hız ile gerçek hız arasındaki hata bir kazançla çarpılıp gaza uygulanır. Salınımı (osilasyonu) denetlemek için frekans analizi kullanılır.
- Sinüzoidal işaretin parametreleri
  - $x(t) = A\cos(2\pi f_0 t + \phi)$: $A$ genlik, $f_0$ frekans (Hz), $\omega = 2\pi f_0$ açısal frekans (rad/s), $\phi$ faz, $T_0 = 1/f_0$ periyot.
  - Slayt örneği: $x(t) = 3\cos(2\pi\cdot 2\cdot t - 3\pi/4)$ için $A = 3$, $f_0 = 2$, $\phi = 3\pi/4$ ($135^\circ$), $T_0 = 0{,}5$ s. Tepe noktası $t = 3/16$ s'de, bir sonraki tepe $3/16 + 1/2$ s'de (ekrandan, 00:45:00).
- İşaretlerin sınıflandırılması
  - Sürekli ve ayrık zamanlı: sürekli işaret $x(t)$ normal parantezle, ayrık işaret $x[n]$ köşeli parantezle yazılır. Ayrık işaret çoğunlukla sürekli işaretin eşit aralıklarla örneklenmesiyle elde edilir.
  - Periyodik ve aperiyodik: $f(t) = f(t+T)$ sağlanıyorsa işaret periyodiktir.
  - Nedensel (causal), antinedensel (anti-causal) ve nedensel olmayan (non-causal): nedensel işaret $t<0$ için sıfırdır, antinedensel işaret $t>0$ için sıfırdır, nedensel olmayan işaret iki tarafta da değer alır.
  - Çift ve tek: çift işaret $f(t) = f(-t)$ (düşey eksene göre simetrik, örn. kosinüs), tek işaret $f(t) = -f(-t)$ (örn. sinüs) (ekrandan, 00:55:00).
  - Deterministik ve rastgele: deterministik işaretin her andaki değeri bir formül, kural ya da tabloyla bellidir; rastgele işaretin değeri önceden bilinemez (örn. konuşma işareti).
- Çift-tek ayrıştırması (even-odd decomposition)
  - Her işaret bir çift ve bir tek parçanın toplamıdır: $e(t) = \tfrac{1}{2}[f(t) + f(-t)]$, $o(t) = \tfrac{1}{2}[f(t) - f(-t)]$, $f(t) = e(t) + o(t)$ (ekrandan, 01:15:00).
- MATLAB ile ilk işaret
  - MATLAB yorumlanan (interpreter) bir betik dilidir; değişkenler satır satır oluşturulur, `;` çıktıyı ekrana basmaz, `clc` ekranı, `clear all` çalışma alanını temizler.
  - $f(t) = \sin(2\pi t)/t$ ($t \ge 1$), $f(t)=0$ ($t<1$) işareti küçük adımlı ($0{,}01$) zaman ekseniyle çizilir. Eleman eleman bölme için `./` gerekir (ekrandan, 01:45:00).
- Sistem türleri
  - Sürekli zamanlı sistem (AM/FM radyo, tamamen mekanik araba), ayrık zamanlı sistem (bilgisayar oyunu, MATLAB, kredi hesabı), hibrit sistem (A/D ve D/A çeviricili; elektronik kontrol üniteli modern arabalar) (ekrandan, 01:50:00).
- İşaretler üzerinde işlemler
  - Genlik ölçekleme: $a\,x(t)$ ve $a\,x[n]$; $a>1$ genliği büyütür, $0<a<1$ küçültür.
  - Zamanda ölçekleme: $x(bt)$; $b>1$ işareti sıkıştırır, $0<b<1$ genişletir. Ayrıkta $x[2n]$ her ikinci örneği alır (downsampling), $x[n/2]$ araya örnek ekler (upsampling).
  - Zamanda ters çevirme: $x(-t)$, $x[-n]$; işaret düşey eksene göre aynalanır (ölçeklemenin $b=-1$ hali).
  - Zamanda öteleme: $x(t-t_1)$ ve $x[n-n_1]$ ($t_1, n_1 > 0$) gecikmiş, $x(t+t_1)$ ve $x[n+n_1]$ ilerlemiş işarettir.
  - Birleşik işlemlerde sıra önemlidir: $x(2(t-1))$ örneği.
  - Periyodik işaretler: $x(t+T_0) = x(t)$, $x[n+N_0] = x[n]$; en küçük $T_0$ ya da $N_0$ temel periyottur. Tek periyot $x_1(t)$ kaydırılıp toplanarak periyodik uzantı elde edilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Gösterim farkı
  - Sürekli işaretlerde normal parantez $x(t)$, ayrık işaretlerde köşeli parantez $x[n]$ kullanılır. Ayrık işaretin indisi tam sayıdır.
- Frekans domeni gerçek dünyaya alternatif bir bakış açısıdır
  - Zaman domeninde ayırt edilemeyen işaretler (iki farklı akor gibi) frekans domeninde uygun algoritmalarla ayırt edilebilir.
- MATLAB'de sürekli işaret aslında ayrıktır
  - Ekranda sürekli görünen çizim, zaman ekseninin çok küçük adımlarla örneklenmesiyle elde edilir.
  - `./` olmadan `sin(2*pi*t1)/t1` yazmak dizinin her elemanını kendi zaman değerine bölmez; eleman eleman işlem için nokta şarttır.
- Ölçekleme ve kaydırmanın sırası
  - $x(2(t-1)) = x(2t-2)$. Önce 2 ile sıkıştırıp sonra 1 kaydırmak ya da önce 2 kaydırıp sonra 2 ile sıkıştırmak doğru sonucu verir. Önce 1 kaydırıp sonra sıkıştırmak yanlıştır. Kontrol için "argüman nerede sıfır olur?" sorusu sorulur: $2(t-1)=0 \Rightarrow t=1$ (ekrandan, 02:15:00).
- Yeni işareti değer vererek bulmak
  - $y(t)$ çizilirken $t$'ye değerler verilir ve $x$'in hangi noktasının okunacağı hesaplanır. Böylece işlem sırası karışmaz.
- Upsampling'de ara örnekler
  - $x[n/2]$'de tam sayı olmayan indislere karşılık değer yoktur. Ara örnekler ya sıfırla doldurulur (standart upsampling) ya da komşu örneklerden ara değerleme (interpolasyon) ile doldurulur.

## Kısa Tekrar Notları

- İşaret: bilgi taşıyan, bir ya da daha çok değişkene bağlı fonksiyon. Sistem: girişi istenen çıkışa dönüştüren düzenek.
- Her işaret sinüzoidallerin toplamıdır; frekans domeni analizi ve doğrusal sistem çözümünü kolaylaştırır.
- $x(t) = A\cos(2\pi f_0 t + \phi)$, $T_0 = 1/f_0$. $f_0 = 2$ Hz ise $T_0 = 0{,}5$ s. $3\pi/4 = 135^\circ$.
- Sınıflar: sürekli/ayrık, periyodik/aperiyodik, nedensel/antinedensel/nedensel olmayan, çift/tek, deterministik/rastgele.
- Çift: $f(t)=f(-t)$. Tek: $f(t)=-f(-t)$. $e(t)=\frac{f(t)+f(-t)}{2}$, $o(t)=\frac{f(t)-f(-t)}{2}$.
- $\sin(2\pi t)/t$ ($t\ge 1$), 0 ($t<1$): sürekli, analog, aperiyodik, sonsuz uzunluklu, nedensel, ne çift ne tek, deterministik.
- MATLAB: `a:adim:b` dizi üretir, `zeros(1,N)` sıfır dizisi, `./` eleman eleman bölme, `plot(x,y)` çizim; `x` ve `y` aynı uzunlukta olmalı.
- $x(bt)$: $b>1$ sıkıştırma, $0<b<1$ genişletme. $x[2n]$ downsampling, $x[n/2]$ upsampling.
- $x(-t)$: ters çevirme. $x(t-t_1)$: gecikme (sağa kayma), $x(t+t_1)$: ilerleme (sola kayma).
- Birleşik işlemde argümanın sıfır olduğu noktayı kontrol et.
- Periyodik: $x(t+T_0)=x(t)$, $x[n+N_0]=x[n]$; en küçük değer temel periyot.

## Detaylı Açıklamalar

- **Sinüzoidal örnek.** $x(t) = 3\cos(4\pi t - 3\pi/4)$ işareti $-3$ ile $3$ arasında salınır. Periyodu $T_0 = 1/2$ s'dir. Tepe noktası kosinüsün argümanının sıfır olduğu yerdedir: $4\pi t - 3\pi/4 = 0 \Rightarrow t = 3/16$ s. Bu noktada $x = 3\cos 0 = 3$. Yarım saniye sonra ($t = 3/16 + 1/2$) yine tepe değerine dönülür. Faz $3\pi/4$, $\pi = 180^\circ$ alınırsa $135^\circ$'dir. Yani işaret bir kosinüsün $3/8$ periyot kaydırılmış halidir.
  - Ders sonrası not: Hoca fazı önce "270 derece" diye okudu, sonra $135^\circ$ olarak düzeltti. Ayrıca $3/16$ s'yi "yaklaşık 0,3 saniye" dedi; doğrusu $3/16 = 0{,}1875$ s.
- **Piyano notaları.** Her tuş belirli bir frekansta sinüzoidal ses üretir; klavyede sağa gidildikçe frekans artar. Notalar C, D, E, F, G, A, B (Do, Re, Mi, Fa, Sol, La, Si) diye adlandırılır ve her oktavda tekrarlanır. Hocanın gösterdiği tabloda C5 = 523,25 Hz, D5 = 587,33 Hz, E5 = 659,25 Hz idi (ekrandan, 00:35:00). Bir akorda birkaç tuşa birlikte basılır; duyulan ses bu frekansların toplamıdır.
  - Ders sonrası not: Hoca 523 Hz'lik Do'yu piyanonun ortasındaki C4 olarak andı ve La sesini "770 Hz miydi, emin değilim" dedi. Standart akortta orta Do (C4) yaklaşık 261,63 Hz, 523,25 Hz ise C5'tir; La (A4) 440 Hz'dir.
  - Bir öğrencinin sorusu üzerine hoca, işaretin kısa zaman pencerelerinde ayrı ayrı incelenebileceğini söyledi. Bu yöntemin adı kısa zamanlı Fourier dönüşümüdür (Short Time Fourier Transform). Zamanla frekans içeriği değişen işaretlerde kullanılır.
- **Çift-tek ayrıştırma örneği.** Slayttaki $f(t)$, $-1$'den $0$'a doğrusal olarak $0$'dan $1$'e çıkar, $0$ ile $1$ arasında $1$ değerinde sabit kalır, sonra sıfır olur (ekrandan, 01:15:00). $f(-t)$ bu işaretin düşey eksene göre aynalanmasıdır. Toplam $f(t)+f(-t) = 2e(t)$: $t=0$'da $2$, $t=\pm 1$'de $1$. İkiye bölünce $e(t)$: $t=0$'da $1$, $t=\pm1$'de $0{,}5$ olan çift işaret. Fark $f(t)-f(-t) = 2o(t)$, $-1$ ile $1$ arasında giden tek işarettir; $o(t)$, $0 < t < 1$ için $t/2$, $t=1$'de $0{,}5$, $t=-1$'de $-0{,}5$ değerini alır. Kontrol: $t=0$'da $e+o = 1+0 = 1$, $t=1$'de $0{,}5+0{,}5 = 1$, $t=-1$'de $0{,}5-0{,}5 = 0$; bunlar $f(t)$'nin değerleridir.
- **MATLAB kodu.** Slayttaki kod (ekrandan, 01:45:00):

```matlab
% Code written for Last Example in Lecture1
clc
clear all
close all

t1 = 1:0.01:10;
t2 = -10:0.01:1-0.01;
timeAxis = [t2 t1];
MySignal = [zeros(1,length(t2)) sin(2*pi*t1)./t1];
plot(timeAxis,MySignal)
ylabel('Amplitude', 'fontsize', 20)
xlabel('time', 'fontsize', 20)
title('My First Signal','fontsize', 20)
```

  - `t1` 901, `t2` 1100 elemanlıdır; `timeAxis` ve `MySignal` 2001 elemanlıdır (numpy ile kontrol edildi). Çizimde $t<1$ için işaret sıfırdır, $t=1$'den sonra sönümlenen bir sinüs görülür; en büyük değer yaklaşık $0{,}8$'dir ($t\approx 1{,}23$) (ekrandan, 01:40:00).
  - Hoca noktayı silip `/t1` yazınca sonucun 1101 elemanlı çıktığını, yani bölmenin eleman eleman yapılmadığını gösterdi.
- **Zamanda ölçekleme.** $y(t) = x(2t)$ için $y(0) = x(0)$, $y(1/4) = x(1/2)$. Yani $x$'in $0{,}5$'teki değeri $y$'de $0{,}25$'e gelir ve işaret sıkışır (ekrandan, 02:00:00). Ayrıkta $y[n] = x[2n]$ için $y[0]=x[0]$, $y[1]=x[2]$, $y[2]=x[4]$; örnekler birer atlanarak alınır (downsampling). $y[n] = x[n/2]$ için $y[0]=x[0]$, $y[1]=x[1/2]$ (tanımsız), $y[2]=x[1]$. Hocanın örneğinde $x[0]=1$, $x[1]=3$, $x[2]=4$ alınırsa sıfır doldurmayla $1, 0, 3, 0, 4$, ortalamayla ara değerlemeyle $1, 2, 3, 3{,}5, 4$ elde edilir (ekrandan, 02:30:00).
- **Ters çevirme ve ölçekleme birlikte.** Slayttaki üçgen işaret $x(t)$, $t=-1$'de 0'dan başlayıp $t=0$'da 1'e çıkar, $t=2$'de 0'a iner (ekrandan, 02:20:00). $y(t) = x(-t/2)$ için değerler: $y(0)=x(0)=1$, $y(1)=x(-1/2)=0{,}5$, $y(2)=x(-1)=0$, $y(-1)=x(1/2)=0{,}75$, $y(-2)=x(1)=0{,}5$, $y(-3)=x(3/2)=0{,}25$, $y(-4)=x(2)=0$. Yani $y(t)$, $t=-4$ ile $t=2$ arasında, tepe noktası $t=0$'da olan üçgendir. Bu, işaretin ters çevrilip 2 kat genişletilmesidir.
  - Ders sonrası not: Hoca bu değerleri grafikten göz kararıyla yaklaşık 0,8, 0,6 ve 0,3 diye okudu. Üçgenin doğrusal kenarlarından hesaplanan değerler 0,75, 0,5 ve 0,25'tir (python ile kontrol edildi).
- **Analogdan sayısala çevirmede kayıp.** Bir öğrencinin sorusu üzerine hoca, örneklemede iki yerden bilgi kaybedildiğini anlattı: örnekler arasındaki değerler kaybolur ve her örnek en yakın kuantalama seviyesine yuvarlandığı için genlik hatası oluşur. Geri çevrilen ses orijinale çok yakındır ama aynısı değildir. 4 kHz'lik işaret 8 kHz ile örneklenirse örnek aralığı $1/8000$ s $= 125\ \mu$s olur; bu fark insan kulağıyla pek algılanmaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
