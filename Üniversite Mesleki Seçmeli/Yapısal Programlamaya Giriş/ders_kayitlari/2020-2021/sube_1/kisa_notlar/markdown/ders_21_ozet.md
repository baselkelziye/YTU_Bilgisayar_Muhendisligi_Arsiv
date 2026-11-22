# Ders 21 Çalışma Özeti

## Genel Konular

- Laboratuvar 3 problemi: haritada iki ev arasındaki en düşük skorlu yolu bulmak
  - Bir sitenin haritası $N \times N$ boyutlu bir tamsayı (`int`) matrisiyle ifade edilir. Değeri 0 olan hücrelerde ev bulunur; diğer sayılar evler arasındaki yolları ve bu yolların ağırlığını (skorunu) gösterir (ekrandan, 00:30:00).
  - Yollarda sağa, sola, yukarı ve aşağı hareket edilebilir. Kullanıcının girdiği iki konumdaki evler arasındaki en az skora sahip yolu bulan algoritma gerçeklenecektir (ekrandan, 00:30:00). <!-- BELİRSİZ: problem metninin ilk satırları karede ekranın üstünde kalmış, okunamadı; anlatım altyazıdan alındı. -->
  - Yolun skoru, geçilen hücrelerdeki sayıların toplamıdır. Başlangıç ve bitiş hücreleri 0 olduğu için toplama katılıp katılmamaları sonucu değiştirmez.
- İstenenler (ekrandan, 00:30:00)
  - Program her çalıştığında kullanıcıdan $N$, başlangıç noktası ve hedef noktası alınır.
  - Hızlı test için verilen örnek 5x5 harita doğrudan koda yapıştırılabilir; harita elemanları kullanıcıdan tek tek alınmaz.
  - Başlangıç ve bitiş noktalarının 0 (ev) olduğu kontrol edilir.
  - Bu iki nokta arasındaki yol, örnek çıktılardaki bilgileri içerecek biçimde yazdırılır.
  - Program farklı haritalarla test edileceği için kod örnek haritaya sabit olarak yazılmaz.
- Örnek Board (ekrandan, 00:30:00)
  - `int Board[5][5]={{0,5,30,-20,40},{20,-10,10,5,50},{5,50,-40,15,60},{10,-10,10,-5,70},{15,20,30,-20,0}};`
  - Bu tabloda iki ev vardır: (0,0) ve (4,4). Kullanıcıdan alınacak bilgiler: $N = 5$, başlangıç 0,0, bitiş 4,4.
- Örnek harita ve çıktılar (ekrandan, 00:10:00 ve 00:25:00)
  - Belgedeki örnek harita koddaki Board ile aynı değildir; üç ev içerir: (1,1), (3,2), (4,4).
  - Hareket kodları: 1 Sağa, 2 Sola, 3 Yukarı, 4 Aşağı.
  - (1,1)'den (4,4)'e en düşük skorlu yol: hamleler 1 4 4 1 4 1, toplam $-55$.
  - (3,2)'den (1,1)'e en düşük skorlu yol: hamleler 3 3 2, toplam $-30$.

## Hocanın Özellikle Vurguladığı Kısımlar

- En iyi yol bulunmalı
  - Herhangi bir yolun skoru değil, en düşük skorlu yol istenir. Bu, iki nokta arasındaki bütün yolların denenip skorlarının karşılaştırılması anlamına gelir.
- Negatif toplamda da en küçük değer seçilir
  - Toplam $-60$ ve $-50$ çıkan iki yol varsa $-60$ seçilir; sıfıra yakın olan değil. Önemli olan geçilen kare sayısı değil, skorlar (costlar) toplamıdır.
- Magic number kullanılmamalı
  - Verilen örnek 5x5 olsa da $N$ yalnız 5 diye düşünülmemeli, kodda boyut sabit 5 olarak yazılmamalı. Test haritası da en fazla 5x5 olacaktır.
- Özyineleme zorunlu değil
  - Problem kaba kuvvet (brute force) ile çözülebilir. Özyinelemeli (recursive) çözüm de kabul edilir.
- Gereksiz hareket yapılmamalı
  - Bulunan yolda gereksiz sağa-sola gidiş olmamalı; örneğin sağa ve yukarı gidiliyorsa sola dönülmemeli. Gereksiz hareketler döngülerde elenmeli.
- Çıktıda yol gösterilmeli
  - Asıl istenen toplam ve rota olsa da, örnekteki gibi her adımın konumunu, hücre değerini ve ara toplamı yazdırmak okumayı kolaylaştırır.

## Kısa Tekrar Notları

- Harita: $N \times N$ tamsayı matrisi; 0 = ev, diğer değerler = yol ağırlığı.
- Girdi: $N$, başlangıç (satır, sütun), bitiş (satır, sütun); harita kodda tanımlı.
- Kontrol: koordinatlar haritanın içinde mi, başlangıç ve bitiş 0 mı?
- Hamle kodları: 1 Sağa, 2 Sola, 3 Yukarı, 4 Aşağı.
- Hedef: geçilen hücre değerlerinin toplamı en küçük olan yol; negatif değerlerde de en küçük toplam.
- Örnek haritada (1,1) → (4,4): 1 4 4 1 4 1, toplam $-55$; (3,2) → (1,1): 3 3 2, toplam $-30$.
- Örnek Board'da (0,0) → (4,4) için en küçük toplam $-50$'dir (derste söylenmedi; ajanın programı ve python ile hesaplandı).

## Detaylı Açıklamalar

- Örnek çıktının okunuşu (ekrandan, 00:20:00)
  - (1,1)'den başlanır, toplam 0. Sağa (1) gidilir: (1,2) değeri 10, toplam 10. Aşağı (4): (2,2) değeri $-40$, toplam $-30$. Aşağı (4): (3,2) değeri 0, toplam $-30$. Sağa (1): (3,3) değeri $-5$, toplam $-35$. Aşağı (4): (4,3) değeri $-20$, toplam $-55$. Sağa (1): (4,4) değeri 0, toplam $-55$.
  - Çıktıdaki "Total Address" satırı (1 1 1 4 4 4) en düşük skorlu olmayan sıradan bir gidiş yolunu gösterir; asıl sonuç "Min Road" satırıdır.
  - Koordinatlar 0'dan başlar: (1,1), ikinci satırın ikinci sütunudur.
- Çözüm fikri (derste anlatılmadı)
  - Gereksiz hareket yapılmayacağı için yol yalnız hedefe doğru dikey ve yatay adımlardan oluşur. Dikey fark $d$, yatay fark $y$ ise her yol $d + y$ adımlık bir dizidir ve bu adımların $d$ tanesi dikeydir.
  - Bütün bu diziler denenir (kaba kuvvet), her birinin toplamı hesaplanır, en küçüğü ve hamleleri saklanır.
  - Ajanın yazdığı program (genişletilmiş notta) `gcc -Wall` ile derlendi; ekrandaki iki örnekte $-55$ (1 4 4 1 4 1) ve $-30$ (3 3 2) sonuçlarını verdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
