# Ders 23 Çalışma Özeti

## Genel Konular

- Bu kayıt dördüncü ve son laboratuvar sınavıdır (31.05.2021). Ders yapılmadı. Hoca laboratuvardan sonra öğrenciler yorgun olacağı için konulara Cuma günü devam edileceğini söyledi.
- Duyurular
  - İlk üç laboratuvarın puanları bir haftadan kısa sürede açıklandı.
  - Laboratuvar notu dört laboratuvarın en yüksek üçünün ortalamasıdır. İlk üçünden memnun olanlar da soruyu çözmeye çalışmalıdır, çünkü öğretici bir sorudur.
  - Final sınavı olmadığı için kalan konulardan sorumlu olunmayabilir. Ama bu konular gelecek dönem çok işe yarayacaktır. Bir kısım öğrenciyle Çarşamba, bir kısmıyla Cuma görüşülecek. Gelecek hafta dönem değerlendirmesi için ayrıca bir toplantı yapılacak.
- Laboratuvar 4 sorusu: ampul ve butonlar
  - Bir ampulün etrafında farklı enerji değerleri veren butonlar var. Ampulün yanması için tam olarak 3 butona basılmalı ve bunların toplamı gerekli enerjiye tam olarak eşit olmalıdır. Eksik de fazla da olursa ampul yanmaz.
  - Kullanıcıdan üç şey alınır: buton sayısı, butonların değerleri ve gerekli enerji. Buton sayısı değişkendir, seçilecek buton sayısı hep 3'tür.
  - Butonlar sıralı olmak zorunda değildir ve seçilen üçlünün dizide yan yana olması gerekmez.
  - Çıktı yalnızca "Ampul yanar" veya "Ampul yanmaz"dır. Bulunan üçlüyü yazdırmak serbesttir. Bütün kombinasyonları bulmak gerekmez, bir üçlü yeterlidir.
  - Örnekler: butonlar {3, 5, 1, 2, 0, 9, 6}. Enerji 8 ise ampul yanar ({1, 5, 2}, {5, 3, 0}, {6, 2, 0}). Enerji 20 ise yanar ({5, 6, 9}). Enerji 60 ise yanmaz.
  - Çözüm özyinelemeli (recursive) olmalıdır. Döngüyle yazılan bir çözüm puanın büyük kısmını kaybettirir, ama diğer kısımlar için yine puan verilir.
  - Süre 85 dakikadır. Değişkenler `int` olabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Laboratuvarda istenen yöntemle çözün. Bu soruda önemli olan özyinelemedir.
- İlk üç laboratuvarınızdan memnun olsanız da soruyu çözmeye çalışın.

## Kısa Tekrar Notları

- Girdi: buton sayısı, buton değerleri, gerekli enerji. Çıktı: "Ampul yanar" / "Ampul yanmaz".
- Toplamı tam olarak gerekli enerjiye eşit olan herhangi 3 buton aranır.
- Özyinelemede her buton için iki seçenek vardır: seç veya seçme.

## Detaylı Açıklamalar

### Örnek bir özyinelemeli çözüm

Aşağıdaki çözüm derste yazılmadı. Ders sonrasında hazırlandı ve `gcc -Wall -std=c89 -pedantic` ile denendi. Her buton için önce "seç" dalı denenir (kalan sayı ve kalan enerji azalır), olmazsa "seçme" dalı denenir. 3 buton seçildiğinde kalan enerjinin 0 olup olmadığına bakılır:

```c
int ucluVar(int dizi[], int n, int i, int kalanSayi, int kalanEnerji){
    if (kalanSayi == 0) return kalanEnerji == 0;
    if (i == n) return 0;
    if (ucluVar(dizi, n, i + 1, kalanSayi - 1, kalanEnerji - dizi[i])) return 1;
    return ucluVar(dizi, n, i + 1, kalanSayi, kalanEnerji);
}
/* cagri: ucluVar(dizi, n, 0, 3, enerji) */
```

{3, 5, 1, 2, 0, 9, 6} dizisi için enerji 8 ve 20'de "Ampul yanar", 21'de "Ampul yanmaz" sonucu alındı. 20 için 9 + 6 + 5 bulunur. Bu dizideki en büyük üç değerin toplamı 20 olduğu için 21 ve üstü (60 dahil) sağlanamaz.

- Fonksiyon en fazla $\binom{n}{3}$ üçlüyü dener, yani en kötü durumda $n^3$ mertebesindedir. Üç iç içe döngüyle yazılan çözümle aynı mertebededir. Bu soruda istenen performans değil, özyinelemeli düşünmedir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
