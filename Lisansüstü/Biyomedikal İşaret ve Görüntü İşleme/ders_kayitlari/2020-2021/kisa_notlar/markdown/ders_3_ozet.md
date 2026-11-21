# Ders 3 Çalışma Özeti

## Genel Konular

- İşaret ayrıştırma (signal decomposition) tekrarı
  - Ayrık bir işaret, birim impulsun kaydırılmış ve genlikle çarpılmış kopyalarının toplamıdır: $x[n]=\sum_{k=-\infty}^{\infty} x[k]\,\delta[n-k]$ (ekrandan, 00:20:00).
  - Örneğin $n=3$'teki örnek, $x[3]\,\delta[n-3]$ terimiyle temsil edilir; $x[3]$ o örneğin genliğidir.
- Ayrık zaman sistemleri
  - Tanım: Bir giriş işaretini sabit kurallar kümesi veya işlemlerle başka bir çıkış işaretine dönüştüren matematiksel operatör (ekrandan, 00:35:00).
  - Gösterim: $x[n] \rightarrow T[\cdot] \rightarrow y[n]$. Kutunun içi (algoritma, matematiksel ya da mantıksal işlem) tasarımcıya aittir.
- Ayrık sistem özellikleri
  - Hafızasız/hafızalı sistem: Hafızasız sistemde $n_0$ anındaki çıkış yalnız $n_0$ anındaki girişe bağlıdır. $y[n]=x^2[n]$ ve $y[n]=e^{x[n]}$ hafızasızdır; $y[n]=x[n]+x[n-1]+x^2[n+1]$ hafızalıdır (ekrandan, 00:40:00).
  - Toplamsallık (additivity): $T\{x_1[n]+x_2[n]\}=T\{x_1[n]\}+T\{x_2[n]\}$.
  - Homojenlik (ölçekleme): $T[c\,x[n]]=c\,T[x[n]]$, $c$ sabit/skaler (ekrandan, 00:45:00).
  - Doğrusallık: Toplamsallık ve homojenlik birlikte sağlanır: $T[a_1x_1[n]+a_2x_2[n]]=a_1T[x_1[n]]+a_2T[x_2[n]]$ (ekrandan, 00:45:00).
  - Öteleme ile değişmezlik (shift invariance): Girişteki $n_0$ örneklik gecikme ($x[n-n_0]$) çıkışta da aynı gecikmeyi ($y[n-n_0]$) üretir.
  - Nedensellik (causality): $n_0$ anındaki çıkış yalnız $n_0$ anına kadarki girişlere bağlıdır.
  - Durağanlık/kararlılık (stability): Sınırlı giriş için sınırlı çıkış (BIBO).
- Birim örnek cevabı ve konvolüsyon
  - Doğrusal sistemde $y[n]=\sum_k x[k]\,h_k[n]$, $h_k[n]=T[\delta[n-k]]$ (ekrandan, 00:50:00).
  - Doğrusal ve öteleme ile değişmez (LSI) sistemde $h_k[n]=h[n-k]$ olur ve $y[n]=\sum_k x[k]\,h[n-k]=x[n]*h[n]$ (ekrandan, 00:55:00).
- Konvolüsyonun özellikleri
  - Değişme (commutative): $x[n]*h[n]=h[n]*x[n]$.
  - Birleşme (associative): Kaskat bağlı iki sistem tek sistem olarak düşünülebilir, $h_{eq}[n]=h_1[n]*h_2[n]$.
  - Dağılma (distributive): Paralel bağlı iki sistem için $h_{eq}[n]=h_1[n]+h_2[n]$ (ekrandan, 01:30:00).
- Sonlu uzunluklu dizilerin konvolüsyonu
  - Uzunluk: $L_y=L_x+L_h-1$. Sınırlar: $[M_y, N_y]=[M_x+M_h,\ N_x+N_h]$ (ekrandan, 01:40:00).
  - Grafik yöntem: Birinci dizi sabit tutulur, ikinci dizi ters çevrilip adım adım kaydırılır; üst üste gelen örnekler çarpılıp toplanır.
- MATLAB'de konvolüsyon ve çizim
  - `conv(x,h)` değerleri doğru verir ama indis bilgisi taşımaz. Çıkış indisleri `yi = xi(1)+hi(1) : xi(end)+hi(end)` ile kurulur ve `stem(yi,y)` ile çizilir (ekrandan, 02:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Birim impuls cevabı sistemi karakterize eder
  - Sistemin içini bilmeye gerek yoktur. LSI bir sistemin impulsa verdiği cevap biliniyorsa, herhangi bir girişe cevabı kaydırma, katsayıyla çarpma ve toplama ile (konvolüsyon) bulunur.
- Doğrusallık, sistem cevabının hesaplanmasını büyük ölçüde basitleştirir
  - Toplam ve katsayılar $T$ operatörünün dışına alınabildiği için yalnız kaydırılmış impulslara verilen cevaplar önem kazanır.
- Nedensellikte "gelecek örnek" ölçütü
  - Hesaplanan an "şu an" kabul edilir. Şu anki ve geçmiş örnekler kullanılabilir (geçmiştekiler hafızada tutularak). Gelecekteki bir örneğe ($x[n+1]$ gibi) ihtiyaç varsa sistem nedensel değildir.
- Doğru indisler
  - Konvolüsyon sonucunun değerleri kadar başlangıç ve bitiş indisleri de doğru olmalıdır. Başlangıç indisi dizinin sıfırdan farklı ilk değerinin, bitiş indisi sıfırdan farklı son değerinin yeridir.
- Ayrık işaretlerde `plot` yerine `stem`
  - `plot` noktaları birleştirir; ayrık işaret işlemede örnekleri ayrık çizen `stem` daha uygundur.

## Kısa Tekrar Notları

- $x[n]=\sum_k x[k]\delta[n-k]$: her örnek, genliğiyle çarpılmış kaydırılmış bir impulstur.
- Hafızasız: çıkış yalnız o anki girişe bağlı. $x[n-1]$ veya $x[n+1]$ varsa hafızalı.
- Doğrusal = toplamsal + homojen.
- Öteleme ile değişmez: $x[n-n_0]\rightarrow y[n-n_0]$.
- LSI sistem: $y[n]=x[n]*h[n]=\sum_k x[k]h[n-k]$.
- Nedensel: gelecek örneğe ihtiyaç yok. $y[n]=x[n-1]+x^2[n+1]$ nedensel değildir.
- Kararlı (BIBO): $|x[n]|\le A<\infty \Rightarrow |y[n]|\le B<\infty$. LSI için koşul $\sum_n |h[n]|<\infty$.
- $h[n]=a^n u[n]$, $|a|<1$ ise $\sum_n |a|^n = \frac{1}{1-|a|}$; $a=1/2$ için toplam 2, sistem kararlıdır.
- Kaskat: $h_{eq}=h_1*h_2$. Paralel: $h_{eq}=h_1+h_2$.
- $a^n u[n] * u[n] = \frac{1-a^{n+1}}{1-a}\,u[n]$.
- $L_y=L_x+L_h-1$, $[M_y,N_y]=[M_x+M_h,\ N_x+N_h]$.
- $x=[3,2,1]$ ($n=0..2$), $h=[-1,2,1]$ ($n=-1..1$) için $y=[-3,4,6,4,1]$, $n=-1..3$.

## Detaylı Açıklamalar

- **Ayrık zaman sistemi ve özellikleri.** Ayrık zaman sistemi, ayrık bir giriş dizisini kurallar kümesiyle başka bir diziye dönüştüren operatördür. Bir sistemin hafızalı olup olmadığı, çıkışın o anki girişten başka bir örneğe ihtiyaç duyup duymadığına bakılarak anlaşılır. Örneğin $y[n]=x[n]+x[n-1]$ sisteminde $y[1]=x[1]+x[0]$ olur; $x[0]$'ın bir yerde saklanması gerekir, dolayısıyla sistem hafızalıdır. $y[n]=x^2[n]$ veya $y[n]=e^{x[n]}$ için ise $y[1]$ yalnız $x[1]$'e bağlıdır; bu sistemler hafızasızdır. Toplamsallık ve homojenlik ayrı ayrı tanımlanır; ikisini birlikte sağlayan sisteme doğrusal sistem denir.
- **Doğrusallıktan impuls cevabına.** Giriş, impulsların ağırlıklı toplamı olarak yazılınca $y[n]=T\left[\sum_k x[k]\delta[n-k]\right]$ olur. Sistem doğrusalsa toplam ve $x[k]$ katsayıları dışarı alınır: $y[n]=\sum_k x[k]\,T[\delta[n-k]]=\sum_k x[k]\,h_k[n]$. Burada $h_k[n]$, sistemin $k$ kadar kaydırılmış birim örneğe cevabıdır (impulse response). Sistem ayrıca öteleme ile değişmezse $h_k[n]=h[n-k]$ olur ve çıkış, giriş ile $h[n]$'nin konvolüsyonu olarak bulunur.
- **Nedensellik.** $y[n]=x[n-1]+x^2[n+1]$ için $y[1]=x[0]+x^2[2]$ olur (ekrandan, 01:05:00). $x[0]$ geçmişte oluştuğu için hafızada tutulabilir, fakat $x[2]$ henüz gelmemiş bir örnektir. Bu nedenle sistem nedensel değildir. Bir öğrencinin sorusu üzerine hoca, bu hesap için aradaki $x[1]$ örneğinin "kullanılması" gerekmediğini; ölçütün yalnız şu anki ve geçmiş örneklerle yetinilip yetinilemediği olduğunu açıkladı.
- **Kararlılık.** Girişin genliği sınırlıyken ($|x[n]|\le A<\infty$) çıkış da sınırlı kalıyorsa ($|y[n]|\le B<\infty$) sistem kararlıdır (ekrandan, 01:00:00). Hoca $e^n$ gibi $n$ büyüdükçe sonsuza giden bir diziyi sınırsız işarete örnek verdi. LSI sistemlerde koşul doğrudan impuls cevabı üzerinden yazılır: $\sum_{n=-\infty}^{\infty}|h[n]|<\infty$. Örnek $h[n]=a^n u[n]$ için $u[n]$ toplamın alt sınırını $0$ yapar, toplam $\sum_{n=0}^{\infty}|a|^n$ olur ve $|a|<1$ ise $\frac{1}{1-|a|}$'ya yakınsar. $a=1/2$ için terimler $1, 1/2, 1/4, \dots$ olur ve toplam 2'dir; sistem kararlıdır.
  - Ders sonrası not: Altyazıda toplamın "$1-a$"ya yakınsadığı geçiyor (büyük olasılıkla Whisper ya da sözlü kısaltma kaynaklı); doğrusu $\frac{1}{1-a}$'dır (hocanın verdiği $a=1/2$ için 2 sonucu da bununla tutarlıdır).
  - Ders sonrası not: Tahtada "Casuality" yazılmıştır; doğru yazım "Causality"dir. Hoca "stability" için "durağanlık" dedi; Türkçe işaret işleme kaynaklarında stability için büyük olasılıkla daha yaygın terim "kararlılık"tır, "durağanlık" ise çoğunlukla stationarity karşılığıdır. Tahtadaki $y[n]\le B$ ifadesi de mutlak değerle $|y[n]|\le B$ olarak okunmalıdır.
- **Konvolüsyonun özellikleri.** Değişme özelliği giriş ile impuls cevabının yer değiştirebileceğini söyler. Birleşme özelliği sayesinde arka arkaya (kaskat) bağlı $h_1$ ve $h_2$ sistemleri, $h_{eq}=h_1*h_2$ impuls cevaplı tek sistemle değiştirilebilir. Dağılma özelliği ise paralel bağlı ve çıkışları toplanan iki sistemin $h_{eq}=h_1+h_2$ olan tek sisteme denk olduğunu gösterir.
- **Analitik konvolüsyon örneği.** $x[n]=a^n u[n]$ ve $h[n]=u[n]$ için $y[n]=\sum_k a^k u[k]\,u[n-k]$ yazılır. $u[k]$ alt sınırı $0$, $u[n-k]$ üst sınırı $n$ yapar: $y[n]=\sum_{k=0}^{n}a^k=\frac{1-a^{n+1}}{1-a}$, $n\ge 0$ (python ile $a=1/2$ için ilk değerler $1, 1.5, 1.75, 1.875, \dots$ olarak doğrulandı).
- **Sayısal konvolüsyon örneği.** $x[n]=[3,2,1]$ ($n=0,1,2$) ve $h[n]=[-1,2,1]$ ($n=-1,0,1$) (ekrandan, 01:35:00). $L_y=3+3-1=5$, sınırlar $[0+(-1),\ 2+1]=[-1,3]$. Ters çevrilmiş $h$ kaydırılarak $y[-1]=-1\cdot3=-3$, $y[0]=2\cdot3+(-1)\cdot2=4$, $y[1]=1\cdot3+2\cdot2+(-1)\cdot1=6$, $y[2]=1\cdot2+2\cdot1=4$, $y[3]=1\cdot1=1$ bulunur (ekrandan, 01:55:00). Sonuç MATLAB'de `conv` ile de $[-3,4,6,4,1]$ çıktı (ekrandan, 02:05:00) ve python ile doğrulandı.
- **MATLAB'de indisli çizim.** `xi=0:2`, `hi=-1:1` indis vektörleri tanımlanır; `a:b` yapısı 1'er artan, `a:adım:b` (örneğin `0:0.1:3`) belirli adımla artan vektör üretir. `y=conv(x,h)` sonucu indissiz olduğu için `stem(y)` örnekleri 1'den 5'e kadar çizer; `yi=xi(1)+hi(1):xi(end)+hi(end)` ile $-1..3$ indisleri kurulup `stem(yi,y)` yazılınca doğru eksen elde edilir. Komutun sonuna `;` konursa sonuç ekrana basılmaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
