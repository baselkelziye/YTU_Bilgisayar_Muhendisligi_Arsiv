# Ders 17 Çalışma Özeti

## Genel Konular

- Laboratuvar 2: BJT'li anahtarlama devreleri (Proteus)
  - Bu kayıt bir laboratuvar oturumudur. Öğrenciler soru dosyasındaki iki BJT devresini Proteus'ta kurar, ölçer ve yorumlar. Kaydın sonunda (02:58 sonrası) çözümler anlatılır.
  - Kullanılan malzemeler: BC238 transistör, 2N3703 transistör, 1N4733A zener diyot, direnç, DC ampermetre, DC voltmetre, DC batarya, anahtar (switch) ve en az bir "bilinmeyen eleman" (ekrandan, 00:10:00).
- Soru 1: Anahtar ve BC238 ile lamba sürme
  - Devre: 12 V batarya, anahtar, anahtardan base'e giden $R_1$ direnci, collector koluna bağlı 12 V lamba (iç direnci önce 1 kΩ), emitter toprağa (ekrandan, 01:20:00 ve 03:05:00).
  - Anahtar kapanınca base'den küçük bir akım akar, transistör iletime geçer ve lamba devresi tamamlanır. Anahtar açılınca base akımı kesilir, lamba söner.
  - $R_1$ hesabı: BC238 datasheet'inde test edilmiş en yüksek base akımı $I_B = 5$ mA, $V_{BE(sat)} = 0{,}7$ V kabul edilir: $R_1 = (12 - 0{,}7)/5\,\text{mA} \approx 2{,}2$ kΩ (ekrandan, 03:05:00).
  - $R_1$'in görevi akımı sınırlamaktır; literatürdeki adı akım sınırlayıcı direnç (current limiting resistor).
  - Lamba iç direnci 24 Ω yapılınca lamba daha sönük yanar; çünkü collector akımı transistörün kazancı ($\beta$) ve $I_{C,max}$ değeri ile sınırlıdır.
- Soru 1 (tasarım): Gecikmeli kapanan koridor lambası
  - İstenen: anahtar açıldıktan sonra lamba 5-10 saniye (mümkünse tam 6 saniye) daha yansın. Yalnız basit elemanlar kullanılır.
  - Çözüm: base koluna, $R_1$ üzerinden boşalacak bir kondansatör eklenir. Anahtar açılınca kondansatör base'e enerji sağlar, transistör bir süre daha iletimde kalır.
  - Süre, kondansatörün 12 V'tan 0,7 V'a boşalma süresidir; $R = 2{,}2$ kΩ ile yaklaşık 1000 µF yaklaşık 6 s verir. 5-10 s aralığını sağlayan her değer kabul edilir.
  - Devrenin adı: zaman geciktirme (time delay) devresi.
- Soru 2: Zener diyotlu aşırı gerilim kesme devresi
  - Devre: B1 bataryası, $R_3 = 2{,}2$ kΩ, $R_1 = 1$ kΩ, Q1 (2N3703), D1 (1N4733A zener), $R_4 = 6{,}8$ kΩ, 5 V'luk L1 lambası ve ikinci bir transistör Q2 (ekrandan, 03:10:00).
  - Ölçüm tablosu: B1 = 3 V'ta lamba 3 V (sönük), 5 V'ta 5 V (tam), 7 V'ta ve 12 V'ta 0 V (kapalı) (ekrandan, 03:10:00).
  - Devrenin işlevi: gerilim zener eşiğini (yaklaşık 5,1 V) geçince yükü keser. Adı: yüksek gerilim kesme (High Voltage Cut-Off), bir tür koruma devresi.
  - İki çalışma durumu vardır: yükte gerilim olan çalışma durumu ve kesim (cut-off) durumu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Basit ve temel düşünmek
  - Tasarım sorusunda karmaşık bir çözüm aranmamalıdır; pil dışında devreye bir süre enerji verebilen eleman (kondansatör) yeterlidir. Önemli olan onu doğru yere bağlamaktır.
- Ölçerek anlamak
  - Teorik bilgi yetmese bile simülasyonda istenen noktaya ampermetre ve voltmetre konarak devrenin her durumda nasıl çalıştığı bulunabilir. Deneylerin amacı ölçmektir.
- Şıklar birbirini tamamlar
  - Bir önceki şıkta öğrenilen bilgi bir sonraki şıkkın cevabını verir; ölçüm tablosu devrenin ne yaptığını gösterir.
- Problem odaklı düşünmek
  - Laboratuvar soruları "hesapla, tabloyu doldur" biçiminde değil, "bu problemi çözmek için bu devre nasıl kullanılır" biçimindedir. Derste görülen materyal laboratuvarda karşınıza çıkabilir.

## Kısa Tekrar Notları

- BJT anahtar olarak: base akımı varsa iletim, yoksa kesim.
- Base direnci: $R_B = (V_{CC} - V_{BE})/I_B$; burada $(12 - 0{,}7)/5\,\text{mA} = 2{,}26$ kΩ ≈ 2,2 kΩ.
- Base direnci akım sınırlayıcıdır.
- Yük direnci çok küçülürse collector akımı $\beta I_B$ ve $I_{C,max}$ ile sınırlanır; yük tam gerilimi alamaz.
- Kapanma gecikmesi: base'e kondansatör; süre $t = RC \ln(V_0/V_{BE})$ ile yaklaşık hesaplanır.
- Zener + iki transistör: eşik altında yük beslenir, eşik üstünde yük kesilir (aşırı gerilim koruması).

## Detaylı Açıklamalar

- Soru 1'in ilk kısmında devre olduğu gibi kurulur ve $I_C$, $I_B$, $V_{lamba}$, $V_{BE}$, $V_{CE}$ için üç voltmetre ve iki ampermetre bağlanır. Anahtar, transistörün base'inden akım geçirerek transistörü aktif eder; transistör de lamba devresini tamamlayan bir anahtar gibi çalışır.
- $R_1$ hesabı için BC238 datasheet'indeki test koşullarına bakılır. $V_{BE(sat)}$'ın test edildiği en yüksek base akımı 5 mA'dır. Base kolunda 12 V kaynaktan 0,7 V'luk base-emitter gerilimi düşülür ve kalan gerilim 5 mA'ya bölünür: $R_1 = 11{,}3\,\text{V} / 5\,\text{mA} = 2260\,\Omega$; standart değer olarak 2,2 kΩ seçilir (ekrandan, 03:05:00).
- Lamba direnci 24 Ω olunca transistörsüz bir devrede $I = 12/24 = 0{,}5$ A akardı ve lamba daha parlak yanardı. Transistörlü devrede collector akımı transistörün yükseltebildiği seviyeyle ($\beta$ ve $I_{C,max}$) sınırlıdır; lamba 12 V'a ulaşamaz ve daha sönük yanar.
- Tasarım kısmında anahtar açıldığında base akımının bir süre daha sürmesi gerekir. Base koluna eklenen kondansatör, anahtar kapalıyken 12 V'a dolar; anahtar açılınca $R_1$ ve base üzerinden boşalır. Base gerilimi 0,7 V'un altına inene kadar transistör iletimde kalır. Hoca süreyi çevrim içi bir "capacitor safety discharge" hesaplayıcısıyla buldu: başlangıç 12 V, güvenli gerilim 0,7 V, direnç 2200 Ω. 500 µF'la başlanıp süre yetmezse değer iki katına çıkarılabilir.
  - Ders sonrası not: altyazıda tam 6 s için "bir mikrofarad" geçiyor. $t = RC\ln(12/0{,}7)$ ile 1 µF yalnız yaklaşık 6 ms verir; 1000 µF yaklaşık 6,25 s verir. Hoca hesaplayıcıya da 1000 µF yazmıştı (03:07:35); doğru değer büyük olasılıkla 1000 µF'tır ("bin" sözcüğü "bir" diye yazılmış olabilir).
- Soru 2'de 1N4733A zener'in eşiği yaklaşık 5,1 V'tur. Batarya 0-5 V arasındayken zener iletmez; Q1 kapalı kalır, Q2'nin base'i uygun konumda olduğu için Q2 iletimdedir ve lamba yanar. Batarya örneğin 9 V'a çıkınca zener iletir, Q1 iletime geçer ve bu kez Q2 kesime gider; lamba söner. Böylece yük, belirli bir eşiğin üstündeki gerilimden korunur. <!-- BELİRSİZ: Q2'nin tipi ve bağlantısı ekranda görünmedi; anlatım hocanın sözlü açıklamasından kuruldu. -->
- Lambanın yerine LED, motor ya da başka bir yük konabilir; devrenin işlevi değişmez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
