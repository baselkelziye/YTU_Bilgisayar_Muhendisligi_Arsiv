# Ders 5 Çalışma Özeti

## Genel Konular

- Sayısal türevin hatırlatılması
  - Sayısal türev, analitik türevi zor alınan bir fonksiyonun bir noktadaki türevini, türev fonksiyonunu bulmadan yalnız $f(x)$ değerlerinden yaklaşık hesaplamaktır.
  - Geri fark: $f'(x_i) \approx \dfrac{f(x_i) - f(x_i - h)}{h}$ (ekrandan, 00:05:00). İleri farkta $x_i + h$, merkezi farkta $x_i \pm h$ noktaları kullanılır; merkezi farkta payda $2h$ olur.
- Taylor serisiyle türev formülü türetme
  - $x_i$ çevresindeki noktalar ($x_i \pm h$, $x_i \pm 2h$) Taylor serisine açılır. Her türev ayrı bir bilinmeyen gibi düşünülür; istenmeyen türevler denklemler taraf tarafa toplanarak yok edilir.
  - İleri farklarla birinci türev (ekrandan, 00:10:00): $f'_i = \dfrac{1}{2h}\left[-3f_i + 4f_{i+1} - f_{i+2}\right]$.
  - Aynı açılımlardan, birinci türevler yok edilerek ileri farklarla ikinci türev: $f''_i \approx \dfrac{f_i - 2f_{i+1} + f_{i+2}}{h^2}$.
  - Merkezi farklarla ikinci türev (ekrandan, 00:25:00): $f''(x_i) \approx \dfrac{f(x_{i+1}) - 2f(x_i) + f(x_{i-1})}{h^2}$.
  - Beş noktalı merkezi farklarla üçüncü türev (ekrandan, 00:40:00): $f'''(x_i) \approx \dfrac{-f_{i-2} + 2f_{i-1} - 2f_{i+1} + f_{i+2}}{2h^3}$.
- Sayısal yöntemler için hazır araçlar
  - Python ile sayısal yöntemler anlatan bir çevrim içi kitap tanıtıldı: Matplotlib ile çizim, SymPy ile sembolik işlem, `numpy.linalg.solve` ile doğrusal sistem çözümü, kök bulma için hazır fonksiyonlar.
- Jacobi ve Gauss-Seidel yöntemlerinin Excel'de karşılaştırılması
  - Sistem: $x + 2y = 5$, $3x + y = 5$; gerçek çözüm $x = 1$, $y = 2$ (ekrandan, 01:05:00).
  - Denklemler köşegen baskın olacak biçimde yer değiştirildi, başlangıç $(0,0)$ alındı. Gauss-Seidel yaklaşık yarı iterasyonda sonuca ulaştı.
  - Köşegen baskınlık sağlanmadığında aynı sistem ıraksadı.
- C ile sayısal yöntem kodlama ilkeleri
  - Her yöntem ayrı fonksiyon olmalı; fonksiyon değeri hesaplama ortak bir yardımcı fonksiyonda toplanmalı.
  - Durdurma koşulu $|x_{yeni} - x_{eski}| \le \varepsilon$ biçiminde yazılmalı, hata bir sayıya `!=` ile karşılaştırılmamalı.
  - Polinom `struct` ile (katsayı ve üs içeren terimler dizisi) modellenebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Taylor serisiyle türev türetmenin sistematiği
  - Kaç türev bilinmeyeni varsa o kadar denklem (nokta) gerekir. Mantık anlaşıldıktan sonra istenen mertebede türev formülü aynı yolla elde edilir.
- Köşegen baskınlığın önemi
  - Köşegendeki büyük katsayı paydaya gelir ve kesrin değerini küçültür; bu yüzden yineleme yakınsar. Baskınlık yoksa basit bir sistem bile çözülemeyebilir.
- Kayan noktalı sayılarda eşitlik kontrolü
  - `while (e != 0.01)` gibi bir koşul sonsuz döngüye yol açar, çünkü iki kayan noktalı sayının farkı hiçbir zaman bit bit tam olarak o değere eşit olmayabilir. Doğrusu, farkın mutlak değerinin $\varepsilon$'dan küçük ya da eşit olmasını kontrol etmektir. Hoca bunu "çok önemli bir detay" diye vurguladı.
- Kodun okunabilirliği
  - Fonksiyon başına girdi ve çıktıyı anlatan kısa bir açıklama yazılmalı; her satıra yorum eklenmemeli. Kullanıcı hataları (ör. tersi alınamayan matris, geçersiz menü seçimi) kontrol edilmeli, program kapanmamalı.

## Kısa Tekrar Notları

- Geri fark: $\dfrac{f_i - f_{i-1}}{h}$; ileri fark: $\dfrac{f_{i+1} - f_i}{h}$; merkezi fark: $\dfrac{f_{i+1} - f_{i-1}}{2h}$.
- İleri farkla birinci türev (3 nokta): $\dfrac{-3f_i + 4f_{i+1} - f_{i+2}}{2h}$.
- İleri farkla ikinci türev (3 nokta): $\dfrac{f_i - 2f_{i+1} + f_{i+2}}{h^2}$.
- Merkezi farkla ikinci türev: $\dfrac{f_{i+1} - 2f_i + f_{i-1}}{h^2}$.
- Merkezi farkla üçüncü türev (5 nokta): $\dfrac{-f_{i-2} + 2f_{i-1} - 2f_{i+1} + f_{i+2}}{2h^3}$.
- Jacobi: yeni $x$ ve yeni $y$ hep önceki iterasyonun değerleriyle hesaplanır. Gauss-Seidel: yeni $y$ hesaplanırken o adımda bulunan yeni $x$ kullanılır, daha hızlı yakınsar.
- Örnek sistemde Jacobi yaklaşık 17-18, Gauss-Seidel yaklaşık 9 iterasyonda $x=1$, $y=2$'ye oturdu.
- Durdurma koşulu: $|x_{n+1} - x_n| \le \varepsilon$ ya da en fazla iterasyon sayısı.
- Polinom modeli: `TERM {double coef; int exponent;}`, `POLY {TERM t[MAX]; int n;}`.

## Detaylı Açıklamalar

- **Taylor serisiyle ileri fark formülleri.** $f(x_i + h)$ ve $f(x_i + 2h)$ ikinci kuvvete kadar açılır (ekrandan, 00:10:00):
  - $f(x_i + h) = f(x_i) + h f'(x_i) + \dfrac{h^2}{2!} f''(x_i)$
  - $f(x_i + 2h) = f(x_i) + 2h f'(x_i) + \dfrac{(2h)^2}{2!} f''(x_i) = f(x_i) + 2h f'(x_i) + 2h^2 f''(x_i)$
  - Birinci türevi bulmak için ikinci türev yok edilir: ilk denklem $-4$ ile çarpılıp ikincisiyle toplanır. $f(x_i + 2h) - 4f(x_i + h) = -3f(x_i) - 2h f'(x_i)$ bulunur, buradan $f'(x_i) = \dfrac{1}{2h}\left[-3f(x_i) + 4f(x_i + h) - f(x_i + 2h)\right]$ çıkar.
  - İkinci türevi bulmak için birinci türev yok edilir: ilk denklem $-2$ ile çarpılıp ikincisiyle toplanır ve $f''(x_i) \approx \dfrac{f(x_i) - 2f(x_i+h) + f(x_i+2h)}{h^2}$ elde edilir (katsayılar ara adım olarak eklendi; derste formülün hangi noktaları içerdiği söylendi).
  - Kullanımı: $x_i = 5$, $h = 0.001$ seçilirse fonksiyon $5$, $5.001$ ve $5.002$ noktalarında hesaplanır, katsayılarla birleştirilir ve $2h = 0.002$'ye bölünür. Kodda bu, fonksiyon değerini hesaplayan bir C fonksiyonunun üç kez çağrılması demektir.
- **Merkezi farklarla ikinci türev.** $f(x_{i+1})$ ve $f(x_{i-1})$ açılır; $x_{i+1} - x_i = h$, $x_{i-1} - x_i = -h$ olur (ekrandan, 00:25:00):
  - $f(x_{i+1}) = f(x_i) + h f'(x_i) + \dfrac{h^2}{2} f''(x_i)$
  - $f(x_{i-1}) = f(x_i) - h f'(x_i) + \dfrac{h^2}{2} f''(x_i)$
  - İki denklem doğrudan toplanınca birinci türevler gider: $f(x_{i+1}) + f(x_{i-1}) - 2f(x_i) = h^2 f''(x_i)$. Böylece $f''(x_i) \approx \dfrac{f(x_{i+1}) - 2f(x_i) + f(x_{i-1})}{h^2}$ bulunur.
  - İkinci denklem birincisinden çıkarılırsa ikinci türevler gider ve slayttaki merkezi fark formülü $f'(x_i) \approx \dfrac{f(x_{i+1}) - f(x_{i-1})}{2h}$ yeniden elde edilir.
  - Hoca öğrencilere $f(x) = x^3 - 8x^2$ için $h = 0.1$ alıp $f''(4)$'ü bu formülle hesaplamayı bıraktı: $3.9$, $4$ ve $4.1$ noktalarındaki değerler kullanılır. (Ders sonrası kontrol: sonuç $8$ çıkar ve analitik $f''(4) = 6 \cdot 4 - 16 = 8$ ile örtüşür; kübik fonksiyonda bu formülün kesme hatası sıfırdır.)
- **Beş noktalı merkezi farklar.** $x_{i-2}, x_{i-1}, x_i, x_{i+1}, x_{i+2}$ noktaları dördüncü türeve kadar açılır (ekrandan, 00:35:00). $x_{i\pm2}$ için $\pm 2h$, $x_{i\pm1}$ için $\pm h$ yazılır; $-h$ ve $-2h$'nin tek kuvvetleri eksi işaret getirir.
  - Dört denklem birlikte toplanınca birinci ve üçüncü türevler gider: $f_{i+2} + f_{i+1} + f_{i-1} + f_{i-2} = 4f_i + 5h^2 f''_i + \dfrac{17}{12} h^4 f^{(4)}_i$.
  - Uygun katsayılarla birleştirilerek istenen türev bulunur; derste sonuç olarak üçüncü türev formülü verildi (ekrandan, 00:40:00): $f'''(x_i) \approx \dfrac{-f_{i-2} + 2f_{i-1} - 2f_{i+1} + f_{i+2}}{2h^3}$, burada $f_i = f(x_i)$, $f_{i+1} = f(x_i + h)$.
  - Ders sonrası not: Hoca dört denklemin toplamında dördüncü türev katsayısını $\dfrac{4}{3}h^4$ diye hesapladı; $\pm 2h$ terimlerinden $2 \cdot \dfrac{16}{24}$, $\pm h$ terimlerinden $2 \cdot \dfrac{1}{24}$ gelir, toplam $\dfrac{17}{12}h^4$ olur. Üçüncü türev formülü bu hatadan etkilenmez ve doğrudur (python ile kontrol edildi).
- **Python araçları.** Tanıtılan kitapta Matplotlib ile $-5$ ile $5$ arası 100 noktalık bir dizide $x^2$ grafiği çizilir. SymPy ile semboller tanımlanıp denklemler kurulur, `simplify` ile sadeleştirme yapılır. Doğrusal sistem örneği (ekrandan, 00:45:00): $4x_1 + 3x_2 - 5x_3 = 2$, $-2x_1 - 4x_2 + 5x_3 = 5$, $8x_1 + 8x_2 = -3$; `numpy.linalg.solve` sonucu $[2.20833333,\ -2.58333333,\ -0.18333333]$ verir (ayrıca kesir olarak $53/24$, $-31/12$, $-11/60$ diye doğrulandı). Hoca bu araçların öğrencinin kendi yazdığı kodun sonuçlarını denetlemek için kullanılabileceğini söyledi.
  - Ders sonrası not: Hoca `numpy.linalg.solve`'un arka planda Cholesky yöntemini kullandığını söyledi; ekrandaki sayfa çözücünün LU ayrıştırması yaptığını yazıyor.
- **Jacobi ve Gauss-Seidel (Excel).** $x + 2y = 5$, $3x + y = 5$ köşegen baskın değildir. Satırlar yer değiştirilerek $3x + y = 5$, $x + 2y = 5$ yazılır (ekrandan, 01:05:00):
  - Jacobi: $x_{i+1} = \dfrac{5 - y_i}{3}$, $y_{i+1} = \dfrac{5 - x_i}{2}$. İlk adımlar: $(1.666667,\ 2.5)$, $(0.833333,\ 1.666667)$, $(1.111111,\ 2.083333)$, $(0.972222,\ 1.944444)$. Değerler $1$ ve $2$'nin iki yanında salınarak yaklaşır.
  - Gauss-Seidel: $x_{i+1} = \dfrac{5 - y_i}{3}$, $y_{i+1} = \dfrac{5 - x_{i+1}}{2}$. İlk adımlar: $(1.666667,\ 1.666667)$, $(1.111111,\ 1.944444)$, $(1.018519,\ 1.990741)$, $(1.003086,\ 1.998457)$ (ekrandan, 01:10:00).
  - Ardışık $x$ değerleri arasındaki fark ($\Delta x$) da tabloya eklendi: $1.666667$, $-0.555556$, $-0.092593$, $-0.015432$, ... ve yaklaşık $10^{-8}$ düzeyine iner. Kodda bu farkın mutlak değeri durdurma koşulu olarak kullanılır.
  - Satırlar değiştirilmeden $x = 5 - 2y$, $y = 5 - 3x$ ile yinelenirse değerler $(5, 5)$, $(-5, -10)$, $(25, 20)$, ... diye büyür; yöntem ıraksar.
- **C kodlama ilkeleri.** Polinom değeri hesaplama (function evaluation) bütün yöntemlerin ortak ihtiyacıdır ve ayrı bir yardımcı (auxiliary) fonksiyonda yazılmalıdır. `sin`, `log` gibi fonksiyonlar için `math.h` kullanılabilir, ama türev ya da integral hesaplayan hazır kütüphane kullanılmaz; yöntemler derste anlatıldığı gibi sıfırdan yazılır. Fonksiyon prototipleri `main`'den önce, gövdeleri `main`'den sonra yazılırsa kod daha okunabilir olur. Değişken adlarında tek bir dil (tercihen İngilizce) kullanılmalıdır. Özyinelemeli fonksiyonlar dikkatle kullanılmalıdır.
- **Polinomun `struct` ile modellenmesi.** Hoca Dev-C++'ta şu kodu yazıp çalıştırdı (ekrandan, 01:45:00 ve 01:50:00). `MAX` tanımı ekranda görünmüyor, ajan tarafından `#define MAX 15` olarak eklendi; `gcc -Wall` ile derlendi ve `3 2 4 1 6 0` girdisiyle `3.000000 X ^ 2 +4.000000 X ^ 1 +6.000000 X ^ 0` çıktısı alındı.

```c
#include <stdio.h>
#define MAX 15   /* ekranda görünmüyor, eklendi */

typedef struct term{
    double coef;
    int exponent;
}TERM;
typedef struct poly{
    TERM t[MAX];
    int n;
}POLY;
int main(){
    int m=3;
    POLY p;
    int i;
    p.n=m;
    for(i=0;i<m;i++){
        scanf("%lf",&p.t[i].coef);
        scanf("%d",&p.t[i].exponent);
    }

    for(i=0;i<p.n-1;i++){
        printf("%lf X ^ %d +",p.t[i].coef,p.t[i].exponent);
    }
    printf("%lf X ^ %d",p.t[i].coef,p.t[i].exponent);
    return 0;
}
```

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
