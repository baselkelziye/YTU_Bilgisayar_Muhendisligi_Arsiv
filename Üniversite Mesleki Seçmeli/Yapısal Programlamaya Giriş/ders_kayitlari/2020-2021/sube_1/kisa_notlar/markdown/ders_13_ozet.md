# Ders 13 Çalışma Özeti

## Genel Konular

- Laboratuvar problemi: seyrek matrisi sıkıştırılmış forma dönüştürmek ve geri elde etmek
  - Tanım (ekrandan, 00:30:00): bir matristeki sıfırdan farklı değer sayısı, matrisin eleman sayısına göre az ise bu matris seyrek matristir. Seyrek matriste yalnız sıfır olmayan girişlerin saklanmasıyla önemli bellek kazancı sağlanabilir.
  - Sıkıştırılmış form: sıfırdan farklı her değer için bir satır tutulur; bu satırda değerin bulunduğu satır numarası, sütun numarası ve değerin kendisi yer alır.
  - Ekrandaki örnek (ekrandan, 00:30:00): 5 x 6 boyutlu A matrisinde sıfırdan farklı değerler 1, 2, 3, 5 ve 8'dir. Sıkıştırılmış formu şu 5 satırdır (Satır, Sütun, Değer): (0, 3, 1), (1, 1, 2), (2, 3, 3), (3, 4, 5), (4, 0, 8).
  - İlk satır (0 3 1), seyrek matriste 0'ıncı satır 3'üncü sütundaki değerin 1 olduğunu; ikinci satır (1 1 2), 1'inci satır 1'inci sütundaki değerin 2 olduğunu ifade eder.
- Programdan istenenler
  - Seyrek matristen sıkıştırılmış matrisi ve sıkıştırılmış matristen seyrek matrisi elde eden bir C programı yazılacak.
  - Program bir menü içerir: (1) Seyrek Matristen Sıkıştırılmış Matrise, (2) Sıkıştırılmış Matristen Seyrek Matrise, (3) Çıkış (ekrandan, 00:30:00).
  - Program bir işlemi tamamlayınca kendini yineler: menü yeniden gösterilir, program ancak kullanıcı "Çıkış" seçeneğini seçince sonlanır.
  - Sıfırdan farklı değerlerin satır, sütun ve değer bilgisini tutan yeni bir matris (sıkıştırılmış form) oluşturulmalıdır; yalnız ekrana yazdırmak yetmez (ekrandan, 00:35:00).
- Ekrandaki örnek çalışma (ekrandan, 00:30:00)
  - Menüde 1 seçilir, boyutlar 3 ve 2 girilir, elemanlar sırayla 0, 0, 1, 1, 3, 0 olarak verilir.
  - Çıkan sıkıştırılmış matris: (1, 0, 1), (1, 1, 1), (2, 0, 3). Ardından menü yeniden gelir ve 3 ile program kapanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Matrisin kare olması gerekmez
  - Satır ve sütun sayısı kullanıcıdan alındığı için matris kare de olabilir, olmayabilir de. Ekrandaki örnek çalışmada 3 x 2'lik bir matris girilmiştir.
- Seyreklik kontrolü istenmiyor
  - Girilen matrisin gerçekten seyrek olup olmadığı denetlenmez. Deneme yaparken zaman kaybetmemek için seyrek bir matris girmek yeterlidir.
- Programın sürekliliği
  - Program bir işlemden sonra kapanmamalı; sıkıştırılmış matris yazdırıldıktan sonra menü tekrar görünmeli.
- İyi tasarım
  - Çözüm mümkün olan en iyi biçimde yazılmalıdır; fonksiyonlar öğrenildiyse fonksiyon kullanılmalı, öğrenilmediyse her şey `main` içinde yapılabilir.

## Kısa Tekrar Notları

- Seyrek matris: sıfırdan farklı eleman sayısı toplam eleman sayısına göre az olan matris.
- Sıkıştırılmış form: her sıfırdan farklı eleman için bir (satır, sütun, değer) satırı; satır sayısı sıfırdan farklı eleman sayısı kadar, sütun sayısı 3'tür.
- Seyrekten sıkıştırılmışa: matris satır satır taranır, sıfırdan farklı her eleman yeni matrisin bir sonraki satırına yazılır.
- Sıkıştırılmıştan seyreğe: önce bütün elemanlar 0 yapılır, sonra her (satır, sütun, değer) satırındaki değer yerine konur.
- Menü bir döngü içinde tekrar gösterilir; döngü "Çıkış" seçilince biter.
- Bir satırda hiç sıfırdan farklı eleman olmaması sorun değildir.

## Detaylı Açıklamalar

- Bu kayıt dersin ikinci laboratuvar oturumudur. Laboratuvar sorusu ekranda paylaşıldı, ardından öğrencilerin soruları cevaplandı ve soru bir kez daha sözlü olarak açıklandı. Çözüm derste anlatılmadı.
- Sıkıştırılmış formun mantığı, matrisin büyük kısmı sıfır olduğunda sıfırları hiç saklamamaktır. Bir değerin yerini bilmek için satır ve sütun numarası yeterlidir; bu yüzden her sıfırdan farklı eleman üç sayıyla temsil edilir. Ekrandaki 5 x 6'lık örnekte 30 eleman yerine 5 x 3 = 15 sayı saklanır.
- Geri dönüşümde orijinal matris, sıkıştırılmış matrisin satırlarından kurulur: boyutlar bilindiği için önce sıfırlarla dolu bir matris hazırlanır, sonra her satırdaki değer kendi satır ve sütun konumuna yazılır.
- Aşağıdaki program derste yazılmadı; ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi ve ekrandaki girdilerle denendi. 3 x 2'lik örnekte (0, 0, 1, 1, 3, 0) çıktı (1 0 1), (1 1 1), (2 0 3) oldu; 5 x 6'lık A matrisinde ekrandaki tablo elde edildi ve bu tablodan 2. seçenekle A matrisi geri kuruldu. `break`, `continue`, `goto` ve global değişken içermez; fonksiyonlar henüz işlenmediği için her şey `main` içindedir. 2. seçenekte sıkıştırılmış matrisin nasıl girileceği ekranda görünen kısımda yer almadığından giriş biçimi ajan tarafından seçildi. <!-- BELİRSİZ: Belgenin sonraki maddelerinde 2. seçeneğin girdi biçimi ve switch-case/if-else ile ilgili bir kural olabilir; karelerde görünmüyor. -->

```c
#include <stdio.h>
#define MAX 20

int main(void) {
    int secim, satir, sutun, i, j, k, adet;
    int seyrek[MAX][MAX];
    int sikis[MAX * MAX][3];

    do {
        printf("Menu:\n");
        printf("(1) Seyrek Matristen Sikistirilmis Matrise\n");
        printf("(2) Sikistirilmis Matristen Seyrek Matrise:\n");
        printf("(3) Cikis\n");
        scanf("%d", &secim);

        if (secim == 1) {
            printf("Matrisin Boyutlarini Girin (Satir, Sutun): ");
            scanf("%d %d", &satir, &sutun);
            printf("Matrisin Elemanlarini Giriniz\n");
            for (i = 0; i < satir; i++)
                for (j = 0; j < sutun; j++) {
                    printf("[%d][%d]: ", i, j);
                    scanf("%d", &seyrek[i][j]);
                }
            /* sifirdan farkli her eleman icin (satir, sutun, deger) satiri */
            adet = 0;
            for (i = 0; i < satir; i++)
                for (j = 0; j < sutun; j++)
                    if (seyrek[i][j] != 0) {
                        sikis[adet][0] = i;
                        sikis[adet][1] = j;
                        sikis[adet][2] = seyrek[i][j];
                        adet++;
                    }
            printf("Sikistirilmis Matris\n");
            for (k = 0; k < adet; k++)
                printf("%d\t%d\t%d\n", sikis[k][0], sikis[k][1], sikis[k][2]);
        } else if (secim == 2) {
            printf("Seyrek matrisin boyutlari (Satir, Sutun): ");
            scanf("%d %d", &satir, &sutun);
            printf("Sifirdan farkli eleman sayisi: ");
            scanf("%d", &adet);
            for (k = 0; k < adet; k++) {
                printf("%d. satir (Satir Sutun Deger): ", k + 1);
                scanf("%d %d %d", &sikis[k][0], &sikis[k][1], &sikis[k][2]);
            }
            /* once tum elemanlar 0, sonra kayitli degerler yerine konur */
            for (i = 0; i < satir; i++)
                for (j = 0; j < sutun; j++)
                    seyrek[i][j] = 0;
            for (k = 0; k < adet; k++)
                seyrek[sikis[k][0]][sikis[k][1]] = sikis[k][2];
            printf("Seyrek Matris\n");
            for (i = 0; i < satir; i++) {
                for (j = 0; j < sutun; j++)
                    printf("%d ", seyrek[i][j]);
                printf("\n");
            }
        }
    } while (secim != 3);
    return 0;
}
```

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
