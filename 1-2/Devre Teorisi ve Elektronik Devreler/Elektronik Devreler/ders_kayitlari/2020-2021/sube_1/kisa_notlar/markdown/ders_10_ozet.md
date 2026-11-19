# Ders 10 Çalışma Özeti

## Genel Konular

- Laboratuvar 1: diyot uygulamaları
  - Bu kayıt diyot laboratuvarıdır. Öğrenciler Proteus'ta verilen devreleri kurar, ölçer ve yorumlar; kaydın son kısmında soruların çözümü anlatılır (02:20:27 sonrası).
  - Laboratuvarın ana konusu doğrultucu devreler (yarım dalga ve tam dalga köprü doğrultucu), kondansatör filtresi, dalgalılık (ripple) gerilimi ve zener diyotla gerilim regülasyonudur.
- Ön hazırlık: kondansatör filtreli yarım dalga doğrultucu
  - Hazırlık dokümanında aynı yarım dalga doğrultucu iki farklı yük direnciyle verilir: $C_1 = 1\,\text{mF}$, solda $R_1 = 220\,\Omega$, sağda $R_1 = 10\,\Omega$ (ekrandan, 02:25:00).
  - Yük direnci küçükse kondansatör hızlı boşalır ve ripple büyür; yük direnci artınca ripple azalır.
  - Hazırlık soruları: transformatör nedir, giriş filtresi (input filter) nedir, yarım köprü doğrultucu nedir ve iyileştirilebilir mi, ripple gerilimi nedir, 12 V AC nasıl 12 V DC yapılır, zener diyot gerilim regülatörü olarak kullanılabilir mi (ekrandan, 02:25:00).
- Soru 1: zener diyotlu regülatör
  - Devre: $V_s$ kaynağı, seri $R_1 = 100\,\Omega$, paralel zener D1 (1N4739A) ve $1\,\text{k}\Omega$ yük (ekrandan, 02:40:00).
  - $V_s$ = 5, 8, 9, 10, 15 V için $V_{load}$, $I_{load}$, $I_{zener}$, $I_{main}$ ölçülür; sonra D1'in amacı tablodan çıkarılır.
  - Sonuç: kaynak belli bir değeri geçince yük gerilimi zener gerilimine (yaklaşık 9 V) sabitlenir. Zener diyot yük gerilimini regüle eder.
- Soru 2: tam dalga köprü doğrultucu ve iyileştirilmesi
  - Devre: dört 1N4001 diyotlu köprü, $R_1 = 100\,\Omega$, $V_1$ = 50 V, 60 Hz sinüs (ekrandan, 00:35:00).
  - Pozitif yarım periyotta akım D1 → yük → D4 yolunu, negatif yarım periyotta D2 → yük → D3 yolunu izler. Yükte iki yarım periyotta da aynı yönde gerilim görülür: tam dalga doğrultucu.
  - İyileştirme adımları: (1) çıkışa paralel kondansatör (çözümde $C_1 = 2{,}2\,\text{mF}$), (2) ripple'ı azaltmak için yük direncini büyütmek ($100\,\Omega$ → $1\,\text{k}\Omega$), (3) kondansatöre paralel 24 V zener ile çıkışı 24 V'a regüle etmek (ekrandan, 02:30:00).
  - Bonus: devre ilk açıldığında boş kondansatör kısa devre gibi davranır, diyotlardan çok büyük bir ani akım geçer ve diyot yanabilir. Çözüm: diyotların önüne seri direnç ya da bobin.
- Soru 3: gerçek bir adaptör kartının tanınması
  - Fotoğraftaki kartta mavi bölge dört diyot, 400 V / 47 µF kondansatör ve dirençten oluşan doğrultucu; kırmızı bölge transformatör; yeşil bölge bobin ve kondansatörlerden oluşan LC filtredir (ekrandan, 02:35:00).
  - Giriş AC'dir (yaklaşık 220 V), çıkış daha düşük bir DC gerilimdir. Kartın tamamı bir adaptördür.
- Proteus'ta grafik ile gösterim
  - Giriş ve çıkışa gerilim probu konur, Graph menüsünden "Analogue" grafik eklenir, problar grafiğe sürüklenir, simülasyon kısa süre çalıştırılıp durdurulur ve grafiğe sağ tıklanıp "Simulate" seçilir. Ripple bu grafikte osiloskoptan daha net görünür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Laboratuvar soruları çıkarım ve sentez gerektirir
  - Sorular yalnız ölçüm (analiz) değil, devreye eleman ekleyerek tasarım (sentez) ister. Hazırlık dokümanındaki her soru laboratuvarın bir adımının ipucudur.
- Ripple'ı azaltmak için yük direnci
  - Hoca ripple'ı azaltmanın en iyi yolunun yük direncini artırmak olduğunu söyledi. Kondansatörü büyütmenin ripple'ı fazla etkilemeyeceğini söyledi (bkz. ders sonrası not).
- Zener diyotun toprağa bağlanması
  - Zenerin fazla akımı toprağa akıtılmalıdır. Zener toprağa değil devreye geri bağlanırsa devrede kararsızlık görülür.
- Ani akım (inrush) tehlikesi
  - Boş kondansatör ilk anda kısa devre gibidir; diyotun dayanabileceği maksimum akım aşılabilir. Seri direnç ya da bobin diyotu korur.
- Gerçek devrede elemanları tanımak
  - Diyot, kondansatör, bobin ve transformatörün gerçek kart üzerinde nasıl göründüğü tanınmalıdır.

## Kısa Tekrar Notları

- Yarım dalga doğrultucu tek diyotla sinüsün yalnız bir yarısını geçirir; tam dalga köprü dört diyotla iki yarıyı da aynı yöne çevirir.
- Köprüde pozitif yarıda D1 ve D4, negatif yarıda D2 ve D3 iletimdedir (bu laboratuvarın devre çiziminde).
- Çıkışa paralel kondansatör, sinyal düşerken yükü besler; çıkış sıfıra inmez, ripple kalır.
- Ripple, kondansatörün boşalma hızına bağlıdır; boşalma $RC$ zaman sabitiyle belirlenir.
- Zener diyot ters yönde, kırılma geriliminde gerilimi sabit tutar; seri dirençle birlikte basit bir regülatördür.
- Kondansatörlü doğrultucuda açılış anında büyük ani akım oluşur; seri direnç ya da bobin önlem olur.
- Adaptör zinciri: AC giriş → doğrultucu → transformatör → LC filtre → düşük DC çıkış.

## Detaylı Açıklamalar

- Soru 1, zener regülatör. $R_1 = 100\,\Omega$ ve $R_L = 1\,\text{k}\Omega$ olduğundan zener iletime geçmeden önce yük gerilimi gerilim bölücüyle $V_L = V_s \cdot \frac{1000}{1100}$ olur. 1N4739A'nın zener gerilimi 9,1 V'tur; zener ancak $V_L$ bu değere ulaşınca akım çekmeye başlar ve fazla akımı toprağa geçirir. Böylece $V_s$ arttıkça $I_{main}$ ve $I_{zener}$ artar, $V_L$ ve $I_L$ sabit kalır.
  - İdeal zenerle hesap (python ile; derste tablo değerleri okunmadı): $V_s = 9$ V'ta $V_L \approx 8{,}18$ V, $V_s = 10$ V'ta $V_L \approx 9{,}09$ V, $V_s = 15$ V'ta $V_L = 9{,}1$ V, $I_L = 9{,}1$ mA, $I_{main} = 59$ mA, $I_{zener} \approx 49{,}9$ mA.
  - Ders sonrası not: Hoca "9 V ve yukarısı için yük gerilimi 9 V'a sabitlenir" dedi. Hesaba göre bölücü yüzünden zener eşiği $V_s \approx 9{,}1 \cdot 1{,}1 \approx 10$ V'tur; 9 V kaynakta yük gerilimi yaklaşık 8,2 V'tur. Sabitlenme 10 V ve üzerinde belirgindir.
- Soru 2, köprü doğrultucu. Kaynağın üst ucu pozitifken akım D1'den yüke gider ve yükün alt ucundan D4 üzerinden kaynağa döner; D2 ve D3 ters kutuplanmıştır. Kaynak ters dönünce akım D2'den yüke gider, D3 üzerinden döner. İki durumda da yükten aynı yönde akım geçer; sinüsün negatif yarısı yukarı katlanmış olur. Bu devrenin adı tam dalga (köprü) doğrultucudur.
  - Kondansatör eklenince sinyal tepeden düşerken kondansatör yükü besler; çıkış sıfıra inmez, tepeden biraz düşüp tekrar dolar. Bu dalgalanma ripple gerilimidir.
  - Yük direnci 10 kat artırılınca ($100\,\Omega$ → $1\,\text{k}\Omega$) kondansatör daha yavaş boşalır, ripple belirgin azalır. Çözüm ekranında prob değerleri yaklaşık 23,5 V ve 24,09 V'tur (ekrandan, 02:30:00).
  - Son adımda kondansatöre paralel 24 V zener bağlanır; ripple tamamen kaybolur ve çıkış 24 V'ta kalır.
  - <!-- BELİRSİZ: Soruda V1 = 50 V yazıyor, ama çözümdeki prob değerleri (~23,5 V ve ~24,09 V) ve 24 V regülasyon hedefi 25 V civarı tepe genliğe uyuyor. Proteus'ta girilen genlik değeri kayıttan net çıkmıyor. -->
  - Ders sonrası not: Hoca kondansatörü büyütmenin ripple'ı fazla etkilemeyeceğini, asıl yolun yük direncini artırmak olduğunu söyledi. Tam dalga doğrultucuda ripple yaklaşık $V_{r(pp)} \approx \frac{V_m}{2 f R_L C}$ ile verilir; $R_L$ ile $C$ formülde çarpım olarak yer alır. Kondansatörü 10 kat büyütmek de yük direncini 10 kat artırmak kadar ripple'ı azaltır.
- Bonus, ani akım. Devre açıldığında kondansatör boştur ve ilk anda kısa devre gibi davranır. Diyotlar üzerinden çok yüksek bir şarj akımı geçer; diyotun modeline göre izin verilen maksimum akım aşılırsa diyot yanar. Diyotların önüne seri direnç ya da bobin konarak akım sınırlanır. Bobin Proteus'ta simüle edilemediği için hazırlıkta yalnız direnç gösterildi.
- Soru 3, adaptör. Mavi bölgede dört diyot, kondansatör ve direnç vardır; bu, Soru 2'deki kondansatörlü köprü doğrultucunun aynısıdır. Doğrultucu varsa giriş AC'dir. Transformatör AC ile çalıştığı için sinyal bir yerde tekrar AC'ye çevrilmiş, transformatörde gerilimi düşürülmüş, sonra LC filtreyle yeniden DC'ye yaklaştırılmıştır. Giriş kondansatörünün 400 V'luk çalışma gerilimi, girişin şebeke gerilimi (220 V) olduğunu gösterir. Çıkış daha düşük bir DC'dir; kartın tamamı bir adaptördür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
