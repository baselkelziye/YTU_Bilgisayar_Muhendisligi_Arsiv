# Ders 21 Genişletilmiş Notu: Laboratuvar 3: Haritada İki Ev Arasındaki En Düşük Skorlu Yol

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvar problemi
- 2. Programdan istenenler
- 3. Örnek harita ve örnek çıktılar
- 4. Derste netleşen varsayımlar
- 5. Çözüm fikri ve örnek bir C programı
- Örnek Sorular
- Dersin Toparlaması

Bu kayıt dersin üçüncü laboratuvar oturumudur. Oturumda laboratuvar belgesi ekranda paylaşıldı, soru kısaca açıklandı ve öğrencilerin soruları cevaplandı. Problemin çözümü derste anlatılmadı. Aşağıdaki çözüm bölümü bu yüzden ajan tarafından eklenmiştir ve öyle işaretlenmiştir.

## 1. Laboratuvar problemi

### 1.1 Harita

Bir sitenin haritası $N \times N$ boyutlu bir tamsayı (`int`) matrisiyle ifade edilir. Matrisi bir site gibi düşünmek gerekir: içinde 0 yazan hücrelerin bulunduğu konumda bir ev vardır. Diğer sayılar evler arasındaki yolları ifade eder ve aslında yolların ağırlığıdır. Yollarda sağa, sola, yukarı ve aşağı hareket edilebilir; çapraz hareket yoktur (ekrandan, 00:30:00).

<!-- BELİRSİZ: problem metninin ilk satırları karede ekranın üstünde kalmış; tanım altyazıdaki anlatımdan ve karede görünen son satırlardan kuruldu. -->

### 1.2 Görev

Belgede görev şöyle tanımlanır (ekrandan, 00:30:00): kullanıcının girdiği iki konumdaki evler arasındaki en az skora sahip yolu bulan bir algoritma gerçeklenecektir. <!-- BELİRSİZ: cümlenin "algoritma... dilinde gerçekleyiniz" kısmındaki dil adı karenin kenarında kesik; dersin C dersi olması ve teslim dosyasının .c olması nedeniyle büyük olasılıkla C. -->

Bir yolun skoru, o yolda geçilen hücrelerdeki sayıların toplamıdır. Program, iki ev arasındaki yolların skorlarını hesaplayıp en düşük skorlu yolu bulmalı ve kullanıcıya "şuradan gidersen sana daha ucuza mal olur" diyebilmelidir. Başlangıç noktası birinci ev, hedef noktası ikinci ev olarak düşünülebilir.

## 2. Programdan istenenler

Belgedeki "İstenenler" listesi şöyledir (ekrandan, 00:30:00):

1. Program her çalıştığında kullanıcıdan $N$, başlangıç noktası ve hedef noktası alınmalıdır.
2. Programın hızlı test edilmesi için verilen örnek 5x5'lik harita doğrudan koda yapıştırılabilir. Kullanıcıdan adım adım Board elemanları alınmaz.
3. Başlangıç ve bitiş noktalarının 0 olduğu kontrol edilmelidir.
4. Bu noktalar arasındaki en kısa yol, örnekte verilen resimlerdeki bilgileri barındıracak şekilde yazdırılmalıdır. (Burada "en kısa yol" ile kastedilen, en az skora sahip yoldur.)
5. Program farklı haritalarla test edileceği için kod örnek haritaya sabit olarak yazılmamalıdır.

Belgede ayrıca kullanıcıdan girdi alırken açıklayıcı mesajlar yazılması istenir (ekrandan, 00:30:00).

### 2.1 Örnek Board

Koda yapıştırılacak örnek harita şudur (ekrandan, 00:30:00):

```c
int Board[5][5]={{0,5,30,-20,40},{20,-10,10,5,50},{5,50,-40,15,60},{10,-10,10,-5,70},{15,20,30,-20,0}};
```

Belgenin altında bu harita için kullanıcıdan alınacak bilgiler yazılıdır: $N = 5$; Start = 0,0; End = 4,4 (ekrandan, 00:30:00). Bu Board'da yalnız iki ev, yani iki tane 0 vardır: biri (0,0)'da, biri (4,4)'te.

### 2.2 Harita neden kullanıcıdan alınmıyor?

Haritanın elemanlarını kullanıcıdan tek tek "şunu gir, bunu gir" diye almak hem öğrenci hem değerlendiren için çok zaman alır. Bu yüzden harita kodun içinde dizi olarak tanımlanır. Değerlendirmede bunun yerine farklı bir harita koda yapıştırılarak program yeniden denenecektir. Bu nedenle program yalnız verilen harita için yazılmamalıdır.

> **Hocanın vurgusu:** Örnek harita 5x5 olsa da $N$'in yalnız 5 olduğunu düşünmeyin; kodda boyutu "magic number" denen sabit 5 ile ifade etmeyin.

## 3. Örnek harita ve örnek çıktılar

### 3.1 Belgedeki örnek harita

Belgenin ikinci sayfasında şu harita verilir (ekrandan, 00:10:00):

| | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| **0** | -10 | 5 | 30 | -20 | 40 |
| **1** | 20 | 0 | 10 | 5 | 50 |
| **2** | 5 | 50 | -40 | 15 | 60 |
| **3** | 10 | -10 | 0 | -5 | 70 |
| **4** | 15 | 20 | 30 | -20 | 0 |

Bu harita koddaki örnek Board ile aynı değildir. Bu haritada üç ev vardır: (1,1), (3,2) ve (4,4). Koddaki Board'da ise iki ev vardır. Satır ve sütun numaraları 0'dan başlar; örneğin (1,1), ikinci satırın ikinci sütunudur.

Ekrandaki çıktılarda hareketler sayılarla kodlanır (ekrandan, 00:20:00):

- 1: Sağa
- 2: Sola
- 3: Yukarı
- 4: Aşağı

### 3.2 Birinci örnek: (1,1)'den (4,4)'e

Belgede, yukarıdaki haritada 1,1 noktasından 4,4 noktasına gidilmek istendiğinde oluşacak sonuç şöyle verilir (ekrandan, 00:20:00):

```text
1- Saga
2-Sola
3-Yukari
4-Asagi
Hareketi Temsil Etmektedir
Total Address: 1 1 1 4 4 4

Min Road: -55 Min Road: 1 4 4 1 4 1
Current Place: 1 1 Board Value: 0 Current Total: 0
Next Move: 1
Current Place: 1 2 Board Value: 10 Current Total: 10
Next Move: 4
Current Place: 2 2 Board Value: -40 Current Total: -30
Next Move: 4
Current Place: 3 2 Board Value: 0 Current Total: -30
Next Move: 1
Current Place: 3 3 Board Value: -5 Current Total: -35
Next Move: 4
Current Place: 4 3 Board Value: -20 Current Total: -55
Next Move: 1
Current Place: 4 4 Board Value: 0 Total: -55
```

Adım adım okunuşu:

- Verilen: başlangıç (1,1), hedef (4,4); ikisi de 0 (ev).
- (1,1)'den başlanır, ara toplam 0.
- Sağa (1): (1,2) değeri 10, ara toplam $0 + 10 = 10$.
- Aşağı (4): (2,2) değeri $-40$, ara toplam $10 - 40 = -30$.
- Aşağı (4): (3,2) değeri 0, ara toplam $-30$. Bu hücre de bir evdir; yol başka bir evin üzerinden geçebilir.
- Sağa (1): (3,3) değeri $-5$, ara toplam $-35$.
- Aşağı (4): (4,3) değeri $-20$, ara toplam $-55$.
- Sağa (1): (4,4) değeri 0, sonuç $-55$.

Çıktının başındaki "Total Address: 1 1 1 4 4 4" satırı en düşük skorlu olmayan, sıradan bir gidiş yolunu gösterir (önce üç kez sağa, sonra üç kez aşağı). Derste bir öğrencinin tespitiyle bu satırın minimum olmayan normal gidiş yolu olduğu söylendi; asıl istenen "Min Road" satırındaki rotadır. Bu yolun toplamı $10 + 5 + 50 + 60 + 70 + 0 = 195$'tir (ara adım eklendi, python ile kontrol edildi).

### 3.3 İkinci örnek: (3,2)'den (1,1)'e

Aynı haritada 3,2 noktasından 1,1 noktasına gidilmek istendiğinde sonuç şöyledir (ekrandan, 00:25:00):

```text
Total Address: 2 3 3

Min Road: -30 Min Road: 3 3 2
```

<!-- BELİRSİZ: bu örneğin adım adım satırları karede ekranın altında kalmış; aşağıdaki ara toplamlar haritadan hesaplandı. -->

- Yukarı (3): (2,2) değeri $-40$, ara toplam $-40$.
- Yukarı (3): (1,2) değeri 10, ara toplam $-30$.
- Sola (2): (1,1) değeri 0, sonuç $-30$.

"Total Address: 2 3 3" (sola, yukarı, yukarı) yolunun toplamı ise $-10 + 50 + 0 = 40$'tır (ara adım eklendi).

### 3.4 Çıktı ne kadar ayrıntılı olmalı?

Örnekteki gibi her adımda "Current Place" yazdırmanın zorunlu olup olmadığı soruldu. Cevap: fark etmez, bu bir örnektir. Asıl istenen, en düşük toplam ve bu toplamın hangi yoldan geldiğidir. Rotayı yazmak yeterlidir; ancak örnekteki gibi nereden geçildiğini ve ara toplamları açıklamak değerlendirenin işini kolaylaştırır.

## 4. Derste netleşen varsayımlar

Öğrencilerin sorularına verilen cevaplarla şu noktalar netleşti:

- **En iyi yol bulunacak.** Herhangi bir yolun skoru değil, en düşük skorlu yol bulunacak. Bu, yolların skorlarını birbiriyle karşılaştırmak ve iki nokta arasındaki bütün yolları denemek demektir.
- **Başlangıç ve bitiş birer evdir.** Kullanıcı yalnız 0 olan hücreleri seçer. Kullanıcı evlerin yerini biliyor kabul edilir ve iki ev arasında gitmek ister. Program yine de girilen noktaların 0 olduğunu kontrol etmelidir; girilen koordinat 0 değilse programın durması kabul edilir.
- **Başlangıç ve bitiş hücreleri toplamı değiştirmez.** İkisi de 0 olduğu için toplama katılsa da katılmasa da sonuç aynıdır.
- **Herhangi iki ev seçilebilir.** Evlerin haritanın köşelerinde olması gerekmez; örnekteki gibi (3,2) ile (1,1) arasında da gidilebilir.
- **Kullanıcıdan alınanlar:** haritanın boyutu $N$ (harita karedir), başlangıç noktası ve bitiş noktası. Harita elemanları, uzaklıklar ve hareket komutları kullanıcıdan alınmaz; hareketleri program hesaplar.
- **Test haritası 5x5'ten büyük olmayacak**, ama kod yine de sabit 5'e bağlanmamalıdır.
- **Özyineleme zorunlu değil.** Soru, normal kaba kuvvet (brute force) ile çözüleceği düşünülerek hazırlandı; bu yüzden harita 5x5 seçildi. Özyinelemeli (recursive) çözüm yapan da puan kaybetmez.
- **Gereksiz hareket yapılmamalı.** Bulunan en kısa yolda gereksiz sağa-sola gidiş olmamalıdır. Örneğin sağa ve yukarı gidiliyorsa sola dönülmemeli, bir konumdayken geri yönü kontrol etmeye kalkılmamalıdır. Gereksiz hareketler döngülerde elenmelidir.

**Soru:** $N$ neden kullanıcıdan alınıyor, Board zaten belli? **Cevap:** Doğru, ama yine de $N$ kullanıcıdan alınacak.

**Soru:** Yolların üzerindeki negatif değerler toplandığında örneğin $-60$ çıkarsa onu mu alacağız, yoksa sıfıra yakın olan değeri mi? **Cevap:** En küçük değer alınır. $-60$, $-50$'den küçük olduğu için seçilir; sıfıra yakınlık aranmaz. Önemli olan costlardır, kaç kare gidildiği değil.

**Soru:** Board elemanlarını kullanıcıdan tek tek istememize gerek yok, değil mi? **Cevap:** Hayır, istemeyin. Tek bir harita olacak ve koda yapıştırılacak; kullanıcı bu harita içinde istediği iki ev arasında gidecek.

## 5. Çözüm fikri ve örnek bir C programı

Bu bölüm derste anlatılmadı. Çözüm ajan tarafından, problem metni ve derste netleşen varsayımlar izlenerek yazıldı.

### 5.1 Fikir

Gereksiz hareket yapılmayacağı için yol yalnız hedefe doğru giden dikey ve yatay adımlardan oluşur. Başlangıç $(s_r, s_c)$, hedef $(e_r, e_c)$ ise dikey adım sayısı $d = |e_r - s_r|$, yatay adım sayısı $y = |e_c - s_c|$'dir. Her geçerli yol $d + y$ adımlık bir dizidir ve bu adımların tam $d$ tanesi dikeydir. Dikey adım yönü hedefin altta ya da üstte olmasına göre hep aynıdır (4 ya da 3); yatay adım yönü de hep aynıdır (1 ya da 2).

Kaba kuvvet çözümünde bu dizilerin hepsi denenir. $d + y$ bitlik her sayı (maske) bir diziyi temsil edebilir: 1 olan bit dikey, 0 olan bit yatay adımdır. Bit sayısı tam $d$ olan maskeler geçerli yollardır. Her yol için geçilen hücrelerin toplamı hesaplanır; en küçük toplam ve o yolun hamleleri saklanır.

> **Ek bilgi (derste anlatılmadı):** Bu yöntemle denenen yol sayısı $\binom{d+y}{d}$'dir. 5x5 haritada köşeden köşeye $d = y = 4$ olduğundan $\binom{8}{4} = 70$ yol denenir; $2^8 = 256$ maske taranır. Harita büyüdükçe bu sayı hızla artar; daha büyük haritalarda büyük olasılıkla dinamik programlama gibi yöntemler tercih edilir.

### 5.2 Program

Program dersin kurallarına uyar: `break`, `continue`, `goto` ve global değişken kullanılmaz. Harita boyutu en çok `MAX` olabilir; $N$ kullanıcıdan alınır ve koordinatların harita içinde olduğu ile başlangıç ve bitişin 0 olduğu kontrol edilir.

```c
#include <stdio.h>
#define MAX 10

int main(void) {
    int Board[MAX][MAX] = {{0,5,30,-20,40},{20,-10,10,5,50},{5,50,-40,15,60},
                           {10,-10,10,-5,70},{15,20,30,-20,0}};
    int n, sr, sc, er, ec;
    int dikey, yatay, adimSayisi, dikeyHamle, yatayHamle;
    int maske, birSayisi, i, r, c, toplam, enIyiToplam, enIyiVar;
    int hamle[2 * MAX], enIyiHamle[2 * MAX];

    printf("Harita boyutunu (N) giriniz: ");
    scanf("%d", &n);
    printf("Baslangic noktasini (satir sutun) giriniz: ");
    scanf("%d %d", &sr, &sc);
    printf("Bitis noktasini (satir sutun) giriniz: ");
    scanf("%d %d", &er, &ec);

    if (n < 1 || n > MAX || sr < 0 || sr >= n || sc < 0 || sc >= n ||
        er < 0 || er >= n || ec < 0 || ec >= n) {
        printf("Gecersiz boyut ya da koordinat.\n");
    } else if (Board[sr][sc] != 0 || Board[er][ec] != 0) {
        printf("Baslangic ve bitis noktalari 0 (ev) olmalidir.\n");
    } else {
        /* 1-Saga 2-Sola 3-Yukari 4-Asagi */
        dikey = er - sr;
        yatay = ec - sc;
        dikeyHamle = (dikey > 0) ? 4 : 3;
        yatayHamle = (yatay > 0) ? 1 : 2;
        if (dikey < 0) dikey = -dikey;
        if (yatay < 0) yatay = -yatay;
        adimSayisi = dikey + yatay;
        enIyiVar = 0;
        enIyiToplam = 0;
        /* Her maske bir yol: 1 olan bit dikey, 0 olan bit yatay hamle */
        for (maske = 0; maske < (1 << adimSayisi); maske++) {
            birSayisi = 0;
            for (i = 0; i < adimSayisi; i++)
                birSayisi += (maske >> i) & 1;
            if (birSayisi == dikey) {
                r = sr; c = sc; toplam = 0;
                for (i = 0; i < adimSayisi; i++) {
                    if ((maske >> i) & 1) {
                        hamle[i] = dikeyHamle;
                        r += (dikeyHamle == 4) ? 1 : -1;
                    } else {
                        hamle[i] = yatayHamle;
                        c += (yatayHamle == 1) ? 1 : -1;
                    }
                    toplam += Board[r][c];
                }
                if (!enIyiVar || toplam < enIyiToplam) {
                    enIyiVar = 1;
                    enIyiToplam = toplam;
                    for (i = 0; i < adimSayisi; i++)
                        enIyiHamle[i] = hamle[i];
                }
            }
        }
        printf("1-Saga 2-Sola 3-Yukari 4-Asagi hareketi temsil etmektedir\n");
        printf("Min Road: %d Hamleler:", enIyiToplam);
        for (i = 0; i < adimSayisi; i++)
            printf(" %d", enIyiHamle[i]);
        printf("\n");
        r = sr; c = sc; toplam = 0;
        printf("Current Place: %d %d Board Value: %d Current Total: %d\n", r, c, Board[r][c], toplam);
        for (i = 0; i < adimSayisi; i++) {
            if (enIyiHamle[i] == 1) c++;
            else if (enIyiHamle[i] == 2) c--;
            else if (enIyiHamle[i] == 3) r--;
            else r++;
            toplam += Board[r][c];
            printf("Next Move: %d\n", enIyiHamle[i]);
            printf("Current Place: %d %d Board Value: %d Current Total: %d\n", r, c, Board[r][c], toplam);
        }
    }
    return 0;
}
```

Program `gcc -Wall` ile uyarısız derlendi. Test sonuçları:

- Koddaki Board ile $N = 5$, başlangıç 0 0, bitiş 4 4 girildiğinde: `Min Road: -50`, hamleler 1 4 1 4 4 1 4 1. Yol (0,1)=5, (1,1)=$-10$, (1,2)=10, (2,2)=$-40$, (3,2)=10, (3,3)=$-5$, (4,3)=$-20$, (4,4)=0 hücrelerinden geçer; toplam $-50$. Bu değer python ile bütün yollar denenerek de doğrulandı.
- Başlangıç 1 1 girildiğinde koddaki Board'da (1,1) değeri $-10$ olduğu için "Baslangic ve bitis noktalari 0 (ev) olmalidir." mesajı verildi.
- Board belgedeki örnek haritayla değiştirildiğinde (1,1) → (4,4) için `Min Road: -55`, hamleler 1 4 4 1 4 1; (3,2) → (1,1) için `Min Road: -30`, hamleler 3 3 2 çıktı. İkisi de ekrandaki örnek çıktılarla aynıdır.

> **Ek bilgi (derste anlatılmadı):** Dört yönde hareket serbest bırakılıp yalnız aynı hücreden iki kez geçmemek koşulu konsaydı, negatif ağırlıklar yüzünden dolambaçlı bir yol daha düşük toplam verebilirdi. Bu haritadaki üç örnekte python ile yapılan denemede böyle bir yol daha düşük toplam vermedi; yani "gereksiz hareket yok" kısıtı bu örneklerde sonucu değiştirmez.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00 ve 00:10:00): Bir sitenin haritası $N \times N$ boyutlu bir tamsayı matrisiyle ifade edilmektedir. Değeri 0 olan hücrelerde ev bulunur, diğer sayılar evler arasındaki yolların skorudur. Yollarda sağa, sola, yukarı ve aşağı hareket edilebilir. Kullanıcının girdiği iki konumdaki evler arasındaki en az skora sahip yolu bulan programı yazın. Program kullanıcıdan $N$, başlangıç ve hedef noktasını almalı, bu noktaların 0 olduğunu kontrol etmeli, haritayı koddan okumalı ve örnek çıktıdaki bilgileri (hamleler, her adımdaki konum, hücre değeri ve ara toplam) yazdırmalıdır. Örnek: belgedeki haritada (1,1)'den (4,4)'e en düşük skorlu yol 1 4 4 1 4 1 hamleleriyle $-55$; (3,2)'den (1,1)'e 3 3 2 hamleleriyle $-30$'dur. Test için koddaki örnek Board: `{{0,5,30,-20,40},{20,-10,10,5,50},{5,50,-40,15,60},{10,-10,10,-5,70},{15,20,30,-20,0}}`, başlangıç 0,0, bitiş 4,4.

> **Çözüm (derste verilmedi):** Hedefe doğru giden bütün dikey/yatay adım dizileri kaba kuvvetle denenir, her dizinin geçtiği hücrelerin toplamı hesaplanır ve en küçük toplamlı dizi saklanır. Bölüm 5.2'deki program `gcc -Wall` ile derlendi; belgedeki haritada ekrandaki $-55$ (1 4 4 1 4 1) ve $-30$ (3 3 2) sonuçlarını verdi. Koddaki örnek Board'da (0,0) → (4,4) için en düşük toplam $-50$'dir (hamleler 1 4 1 4 4 1 4 1); bu değer python ile de doğrulandı.

**Soru 2** (derste sözlü, 00:30:10): Yol üzerindeki değerlerin toplamı bir yolda $-60$, başka bir yolda $-50$ çıkarsa hangisi seçilir?

> **Cevap (derste verildi):** $-60$ seçilir, çünkü daha küçüktür. Sıfıra yakın olan değer aranmaz; ölçüt geçilen kare sayısı değil, skorların toplamıdır.

## Dersin Toparlaması

Bu laboratuvar oturumunda bir ızgara (matris) üzerinde iki nokta arasındaki en düşük maliyetli yolu bulma problemi tanıtıldı. Harita bir tamsayı matrisidir; 0 olan hücreler ev, diğer hücreler yol ağırlığıdır. Program kullanıcıdan yalnız harita boyutunu, başlangıç ve bitiş noktalarını alır, bu noktaların ev olduğunu kontrol eder, iki ev arasındaki yolları dener ve en küçük toplamlı yolu adım adım yazdırır. Derste özellikle en iyi yolun bulunması, negatif toplamlarda da en küçük değerin seçilmesi, kodun 5x5'e sabitlenmemesi ve gereksiz hareketlerin elenmesi vurgulandı.

Problemin kaba kuvvetle (bütün yolları deneyerek) çözülebileceği, özyinelemeli çözümün de kabul edildiği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
