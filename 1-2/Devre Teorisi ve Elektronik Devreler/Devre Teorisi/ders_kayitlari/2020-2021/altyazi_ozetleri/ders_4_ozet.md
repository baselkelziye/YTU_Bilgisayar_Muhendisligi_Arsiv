# Ders 4 Çalışma Özeti

## Genel Konular

- Dersin tarihi 1 Nisan 2021 Perşembe. Kayıt iki parçadan oluşur.
  - İlk parça (yaklaşık 2 saat 17 dakika) Lab 1 oturumudur. Oturumu araştırma görevlisi yürütür. Diğer grubun teslimlerini Kübra Hoca takip eder.
  - Asıl ders yaklaşık 02:18'de başlar.
- Lab 1: Ohm kanunu, seri ve paralel DC devreler
  - Direnç değerleri öğrenci numarasının rakamlarından alınır. Rakam 0 ise yerine 1 kullanılır.
  - Soru 1: 10 V kaynakla seri devre. Üç durum incelenir: yalnızca $R_4$ çıkarılmış, $R_2$ ve $R_4$ çıkarılmış, $R_1$-$R_4$ hepsi devrede.
    - Her durumda $V_1$, $V_2$, $V_3$, ölçülen ve hesaplanan akım, $R_{eş}$ ve (isteğe bağlı) devrenin toplam gücü tabloya yazılır.
  - Soru 2: 20 V kaynakla paralel devre.
  - Hesaplar elle, öğrenci numarası yazılı kâğıda yapılır ve fotoğrafı çekilir.
  - Simülasyon ekran görüntüleri (beyaz arka plan) Word belgesine eklenir ve "No-Ad Soyad" adlı PDF olarak yüklenir. Rapor Türkçe yazılır, yaklaşık 6 ekran görüntüsü beklenir.
  - Teslim saati 19:10. Geç kalan 5 dakika içinde e-posta ile gönderebilir.
- Lab 1: Proteus ipuçları
  - Toprak, Terminals Mode'dan eklenir.
  - Ampermetre yatay yerleştirildiğinde doğru okur. Dikey yerleştirilince 0 gösterebilir.
  - DC devrede DC ölçü aleti kullanılmalıdır. DC ve AC aletler karıştırılmamalıdır.
  - Pilin (battery) iç direnci 0 yapılmalıdır. Aksi hâlde ölçülen ve hesaplanan değerler tutmaz (ör. 33.1 ve 44.4).
  - "Library not found" hatasında program yönetici olarak çalıştırılır.
  - Direnç ohmmetre ile değil, voltmetre ve ampermetre ile ölçülen değerlerden bulunur.
- Kısa sınav duyurusu
  - Bu hafta planlanan kısa sınav, diğer grupla eş zamanlı olmak için 8 Nisan'a ertelendi. Dersin son saatinde online.yildiz üzerinden yapılacak.
  - Kapsam: dersin başından çevre (mesh) analizinin sonuna kadar. Kirchhoff yasaları, Ohm kanunu, düğüm ve çevre analizi dahil.
  - Kaynak dönüşümü, doğrusallık, Thevenin, Norton ve maksimum güç kısa sınava dahil değil.
  - Slaytlar Hamza Hoca'nın grubu aynı konuya gelince paylaşılacak.
- Yöntem seçimi
  - $n$ düğümlü bir devrede düğüm analizi $n-1$ denklem gerektirir. Çevre analizi ise göz (mesh) sayısı kadar denklem gerektirir.
  - Daha az denklem veren yöntem seçilir.
- Süper düğüm kuralı (hocanın ifadesi)
  - Eksi ucu referansa bağlı olmayan gerilim kaynağı süper düğüm oluşturur. Her süper düğüm için bir ek (kısıt) denklemi yazılır.
  - Gerilim kaynağı uçları arasındaki gerilimi belirler, akımını komşu elemanlar belirler.
  - Kısa örnek: referans seçildikten sonra 8 V'luk kaynak için $V_B = V_A + 8$, 4 V'luk kaynak için $V_C = -4$ V yazılır.
  - Süper düğümün sınırı kaynağın uçlarındaki düğümlerdir. Kaynakla bir sonraki düğüm arasında direnç varsa sınır o dirençte biter.
- Süper düğüm örneği (Örnek 03, slayt 30)
  - Devre: dört düğüm ($v_1$-$v_4$) ve ortada referans düğümü.
    - $v_1$ ile referans arasında 12 V kaynak, artı ucu referansta. Bu yüzden $v_1 = -12$ V.
    - $v_1$ ile $v_2$ arasında 0.5 Ω ($v_x$ bu direncin gerilimi, artı ucu $v_2$ tarafında).
    - Referanstan $v_2$'ye doğru 14 A akım kaynağı. $v_2$ ile $v_3$ arasında 2 Ω.
    - Referanstan $v_3$'e doğru $0.5 v_x$ bağımlı akım kaynağı.
    - $v_1$ ile $v_4$ arasında 2.5 Ω ($v_y$ bu direncin gerilimi, artı ucu $v_4$ tarafında). Referans ile $v_4$ arasında 1 Ω.
    - $v_3$ ile $v_4$ arasında $0.2 v_y$ bağımlı gerilim kaynağı. $v_3$ ve $v_4$ birlikte süper düğümdür.
  - Denklemler:
    - $v_2$ düğümü: $\frac{v_2 - v_1}{0.5} + \frac{v_2 - v_3}{2} = 14$.
    - Süper düğüm: $0.5 v_x = \frac{v_3 - v_2}{2} + \frac{v_4}{1} + \frac{v_4 - v_1}{2.5}$.
    - Kısıt (referans üzerinden çevre): $-v_3 + 0.2 v_y + v_4 = 0$, yani $v_3 = v_4 + 0.2 v_y$.
    - Bağımlı kaynak değişkenleri: $v_x = v_2 - v_1$, $v_y = v_4 - v_1$.
  - Çözüm: $v_1 = -12$ V, $v_2 = -4$ V, $v_3 = 0$ V, $v_4 = -2$ V.
- Çevre (mesh) analizi
  - Her göze sanal bir çevre akımı atanır. Ortak koldaki direncin akımı iki çevre akımının farkıdır (ör. $R_3$ için $I_1 - I_2$).
  - Çevre, bir eleman alt kümesinin etrafındaki en küçük kapalı yoldur. Her eleman en az bir çevreye ait olmalıdır.
  - Adımlar: çevre akımlarını tanımla, her çevrede KVL yaz, sistemi çöz, eleman akım ve gerilimlerini bul.
  - Çevre akımı bir direnci ters yönde geçiyorsa direncin gerilimi eksi işaretle girer (ör. $V_4 = -I_2 R_4$).
- Çevre analizi örnek 04 (slayt 37)
  - Devre: 12 V kaynak, 4 kΩ ($V_1$), 8 kΩ ($V_2$), ortak kolda 5 kΩ ($V_3$), sağ gözde 6 kΩ ($V_4$) ve 3 kΩ ($V_5$), dönüş yolunda 1 kΩ ($V_6$).
  - Denklemler: $18k\,i_1 - 5k\,i_2 = 12$, $-5k\,i_1 + 14k\,i_2 = 0$.
  - Çözüm: $i_1 = 740$ µA, $i_2 = 264$ µA. Ortak 5 kΩ'dan geçen akım $i_1 - i_2 = 476$ µA.
  - Gerilimler: $V_1 = 2.96$ V, $V_2 = 5.92$ V, $V_3 = 2.38$ V, $V_4 = 1.59$ V, $V_5 = 0.79$ V, $V_6 = 0.74$ V.
  - Kontrol: dış çevrede $2.96 + 5.92 + 2.38 + 0.74 = 12$ V. Sağ gözde $V_3 - V_4 - V_5 = 0$.
- Bu haftanın lab notları açıklandı (ara sonrası, yaklaşık 03:21).
- Çevre analizi örnek 05 (slayt 43)
  - Devre: soldan 42 V kaynak, üstte 6 Ω, ortak kolda 3 Ω, üstte 4 Ω, sağda 10 V kaynak (artı ucu altta).
  - Denklemler: $-42 + 6i_1 + 3(i_1 - i_2) = 0$, $3(i_2 - i_1) + 4i_2 - 10 = 0$.
  - Düzenlenmiş hâli: $9i_1 - 3i_2 = 42$, $-3i_1 + 7i_2 = 10$.
  - Çözüm: $i_1 = 6$ A, $i_2 = 4$ A. 3 Ω'dan aşağı yönde $2$ A geçer.
  - Pratik yazım: bir çevreyi yazarken o çevrenin akımı pozitif alınır, komşu çevre akımı çıkarılır. Birinci çevrede $3(i_1 - i_2)$, ikinci çevrede $3(i_2 - i_1)$ yazılır.
  - Referans yönü ters seçilirse de aynı denklem sistemi çıkar. Tek şart: dirençte gerilim yönü ile akım yönü uyumlu (pasif işaret kuralı) seçilmelidir.
- Çevre analizi örnek 06 (slayt 44)
  - Devre: solda 5 V kaynak, üstte 4 Ω ve 5 Ω, ortak kolda 2 Ω ile 2 V kaynak (eksi ucu üstte), sağda 1 V kaynak (artı ucu üstte).
  - Denklemler: $-5 + 4i_1 + 2(i_1 - i_2) - 2 = 0$, $2 + 2(i_2 - i_1) + 5i_2 + 1 = 0$.
  - Düzenlenmiş hâli: $6i_1 - 2i_2 = 7$, $-2i_1 + 7i_2 = -3$.
  - Çözüm: $i_1 = \frac{43}{38} = 1.132$ A, $i_2 = -\frac{2}{19} = -0.105$ A.
  - Ortak koldan aşağı yönde $i_1 - i_2 = 1.237$ A geçer. Bu akım 2 V kaynağa eksi ucundan girer.
  - 2 V kaynağın çektiği güç $-(2)(1.237) = -2.474$ W. Yani kaynak devreye 2.474 W verir.
- Süper çevre (supermesh)
  - İki çevrenin ortak kolunda akım kaynağı varsa kısıt denklemi gelir: ör. $i_1 - i_2 = I_S$.
  - Akım kaynağı kendi akımını belirler, gerilimini ise komşu elemanlar belirler. Bu, süper düğümün dual durumudur.
  - Bu iki çevre, akım kaynağını dışarıda bırakan daha büyük bir çevre ile birleştirilir. Böylece ortak akım kaynağı içeren çevre kalmaz.
- Süper çevre örneği (Örnek 07, slayt 47)
  - Devre: solda 7 V kaynak. Ortada üstte 1 Ω, altında 7 A akım kaynağı (aşağı yönlü) ve 2 Ω seri. Sağda üstte 2 Ω, altta 1 Ω. Orta düğüm ile sağ düğüm arasında 3 Ω ($i$ sağa doğru).
  - Çevre 1 (sol) ile çevre 3 (sağ alt) 7 A kaynağını ortak kullanır. Çevre 2 sağ üst gözdür.
  - Süper çevre: $-7 + 1(i_1 - i_2) + 3(i_3 - i_2) + 1 i_3 = 0$.
  - Çevre 2: $1(i_2 - i_1) + 2i_2 + 3(i_2 - i_3) = 0$, yani $-i_1 + 6i_2 - 3i_3 = 0$.
  - Kısıt: $i_1 - i_3 = 7$.
  - Çözüm: $i_1 = 9$ A, $i_2 = 2.5$ A, $i_3 = 2$ A. İstenen akım $i = i_3 - i_2 = -0.5$ A.
- Düğüm ve çevre analizinin karşılaştırılması
  - Örnek 07 çevre analiziyle 3 denklem ister ve biri çok basittir. Düğüm analiziyle 4 düğüm gerekir.
  - Düzlemsel (planar) devre: hiçbir tel başka bir telin üstünden geçmeden çizilebilen devredir.
    - Düzlemsel devrede göz sayısı doğrudan sayılır. Düzlemsel olmayan devrede daha dikkatli saymak gerekir.
    - Bazı devreler ilk bakışta düzlemsel görünmez. Bir düğüm ortaya taşınınca veya dirençler dışarı alınınca düzlemsel olduğu görülür.
- Karşılaştırma örneği (slayt 50-51)
  - Devre: 100 V kaynak, seri 8 Ω, düğüm $v_1$. $v_1$'den toprağa 4 Ω. $v_1$ ile $v_2$ arasında 2 Ω ($i_x$ sağa). $v_2$'den toprağa 3 Ω. $v_2$ ile $v_3$ arasında 10 Ω. $v_3$'ten toprağa 5 Ω. 8 A akım kaynağı $v_3$'ten $v_2$'ye doğru (10 Ω'a paralel).
  - Düğüm analizi: 100 V kaynağın üst düğümü doğrudan 100 V'tur. Üç denklem yeterli.
    - $\frac{v_1 - 100}{8} + \frac{v_1}{4} + \frac{v_1 - v_2}{2} = 0$.
    - $\frac{v_2 - v_1}{2} + \frac{v_2}{3} + \frac{v_2 - v_3}{10} - 8 = 0$.
    - $\frac{v_3 - v_2}{10} + \frac{v_3}{5} + 8 = 0$.
    - Çözüm: $v_1 = 25.89$ V, $v_2 = 20.31$ V, $v_3 = -19.90$ V. $i_x = \frac{v_1 - v_2}{2} = 2.79$ A.
  - Öğrenci sorusu: ilk terim $\frac{100 - v_1}{8}$ diye yazılsa ne olur? Giren akımlar çıkan akımlara eşitlenirse aynı denklem çıkar.
  - Çevre analizi: dört göz var. 8 A kaynağı yalnızca 4. gözde ve yönü çevre yönüne ters, bu yüzden $i_4 = -8$ A. Üç denklem kalır.
    - $-100 + 8i_1 + 4(i_1 - i_2) = 0$, yani $12i_1 - 4i_2 = 100$.
    - $4(i_2 - i_1) + 2i_2 + 3(i_2 - i_3) = 0$, yani $-4i_1 + 9i_2 - 3i_3 = 0$.
    - $3(i_3 - i_2) + 10(i_3 + 8) + 5i_3 = 0$, yani $-3i_2 + 18i_3 = -80$.
    - Çözüm: $i_1 = 9.26$ A, $i_2 = i_x = 2.79$ A, $i_3 = -3.98$ A.
- Yeni konuya giriş: devre teoremleri
  - Sıradaki konular: doğrusallık ve süperpozisyon, kaynak dönüşümü, Thevenin ve Norton eşdeğerleri, maksimum güç aktarımı.
  - Kaynak dönüşümü: akım kaynağı ve paralel direnç, gerilim kaynağı ve seri direnç olarak yazılabilir. Tersi de geçerlidir.
  - Pasif elemanlardan oluşan herhangi bir devre, iki ucundan bakıldığında gerilim kaynağı ve seri direnç (Thevenin) veya akım kaynağı ve paralel direnç (Norton) ile gösterilebilir.
  - Bu teoremler devre çözümünü kolaylaştıran pratik yöntemlerdir.
- Doğrusallık
  - Doğrusal fonksiyon orijinden geçer: $f(x) = cx$. $f(x) = ax + b$ ($b \neq 0$) doğrusal değildir.
  - Homojenlik: $f(ax) = a f(x)$. $f(x) = ex + f$ için $f(ax) = eax + f$, oysa $a f(x) = eax + af$. Eşit değildir.
  - Toplamsallık: $f(a x_1 + b x_2) = a f(x_1) + b f(x_2)$.
  - Direnç doğrusal elemandır. Akım-gerilim grafiği orijinden geçen, eğimi sabit bir doğrudur.
  - İdeal gerilim kaynağının grafiği: akım ne olursa olsun gerilim sabit. İdeal akım kaynağının grafiği: gerilim ne olursa olsun akım sabit.
  - Doğrusal bileşenler: direnç, endüktans, kapasite, bağımsız kaynaklar, doğrusal kontrol edilen bağımlı kaynaklar (ör. $a i_x$, $b v_x$).
  - Doğrusal olmayan bileşenler: diyot ve LED (silisyumda yaklaşık 0.7 V'tan sonra akım üstel artar), transistör, manyetik anahtar, $a i_x^2$ gibi kontrol edilen bağımlı kaynaklar.
  - Güç doğrusal değildir: $p = i^2 R = \frac{v^2}{R}$. Eğim akıma göre değişir.
- Kaynakları sıfırlamak
  - Gerilim kaynağını sıfırlamak, yerine kısa devre (tel) koymaktır. İki ucun gerilim farkı 0 olur.
  - Akım kaynağını sıfırlamak, yerine açık devre koymaktır. Koldan akım geçmez.
  - Öğrenci önerisi "ters yönde ikinci bir kaynak bağlamak" doğru değil. Soru, sıfır değerli kaynağın eşdeğer elemanıdır.
- Süperpozisyon örnek 01 (slayt 12)
  - Devre: 10 Ω, 5 V kaynak ve 2 A akım kaynağı birbirine paralel. İstenen 10 Ω'un akımı $I$.
  - Yalnız 5 V: $I_1 = \frac{5}{10} = 0.5$ A.
  - Yalnız 2 A: gerilim kaynağı kısa devre olur. 10 Ω'un iki ucu aynı düğüme bağlanır, $I_2 = 0$.
  - Toplam $I = 0.5$ A. Doğrudan çözüm de aynıdır: paralel elemanların gerilimini 5 V kaynak belirler.
- Süperpozisyon teoremi
  - Bir elemanın akımı veya gerilimi, her bağımsız kaynağın tek başına yaptığı katkıların (yönlü) toplamıdır.
  - AC ve DC devrelerde geçerlidir.
  - Adımlar: bir bağımsız kaynak bırakılır, diğer bağımsız kaynaklar sıfırlanır, katkı not edilir. Bu her kaynak için tekrarlanır, katkılar toplanır.
  - Bağımlı kaynaklar devreden çıkarılmaz.
  - Referans yönleri her alt devrede aynı tutulmalıdır.
- Süperpozisyon örnek 6 (slayt 26-34)
  - Devre: 3 V kaynak ($V_1$, artı ucu üstte), seri $R_1 = 50\ \Omega$, A düğümü. A'dan toprağa $R_3 = 20\ \Omega$. A ile B arasında $R_2 = 30\ \Omega$ ve ona paralel 2 A kaynak (A'dan B'ye). B'den toprağa 1 A kaynak.
  - Yalnız 3 V: $R_2$'nin ucu boşta kalır. $R_1$ ve $R_3$ akımı $\frac{3}{70} = 42.9$ mA, $R_2$ akımı 0.
  - Yalnız 2 A: 2 A kaynağı ile $R_2$ kendi kapalı çevresini oluşturur. $R_2$'den 2 A geçer, $R_1$ ve $R_3$ akımı 0.
  - Yalnız 1 A: $R_{eş} = R_2 + R_1 \parallel R_3 = 44.3\ \Omega$. A düğümü $-14.3$ V. $R_2$'den 1 A geçer, gerilimi 30 V'tur.
  - Toplam (PSpice ile doğrulandı): A düğümü $-13.43$ V, B düğümü $16.57$ V. $R_1$ akımı 328.57 mA, $R_3$ akımı 671.43 mA (topraktan A'ya), $R_2$ akımı 1 A.
- Proteus uyarıları (lab soruları üzerine)
  - Deneyden önce elemanları sürükleme ve bağlamayı denemiş olmanız beklenir. Kısıtlı süreli yeni sürüm devreyi kaydetmeyebilir.
  - En sık hata: bir pinin bağlantısız kalması. Simülasyonda gri görünen uç bağlantısızdır.
  - Gerilim kaynağının uçlarını kısa devre yapan bir devreye simülatörün izin vermemesi normaldir. Gerçekte kaynak yanar.
- Bağımlı kaynaklı süperpozisyon örneği (Örnek 9, slayt 38)
  - Devre 1 (yalnız 4 A): üç göz. $i_1 = 4$ A (akım kaynağı belirler).
    - Çevre 2: $3(i_2 - i_1) + 2i_2 - 5i_o' + (i_2 - i_3) = 0$, yani $-3i_1 + 6i_2 - i_3 - 5i_o' = 0$.
    - Çevre 3: $5(i_3 - i_1) + 1(i_3 - i_2) + 5i_o' + 4i_3 = 0$, yani $-5i_1 - i_2 + 10i_3 + 5i_o' = 0$.
    - $i_o'$ akımı: $i_o' = i_1 - i_3$.
    - Çözüm (MATLAB `inv(A)*T`): $i_2 = 4.706$ A, $i_3 = 0.941$ A, $i_o' = \frac{52}{17} = 3.059$ A.
  - Devre 2 (yalnız 20 V): akım kaynağının kolu açık devre olur, iki göz kalır.
    - $6i_4 - i_5 - 5i_o'' = 0$, $-i_4 + 10i_5 + 5i_o'' = 20$, $i_5 = -i_o''$.
    - Çözüm: $i_o'' = -\frac{60}{17} = -3.529$ A.
  - Toplam: $i_o = i_o' + i_o'' = -\frac{8}{17} = -0.4706$ A.
  - Gösterim: $i_o'$ yalnız 4 A kaynağının, $i_o''$ yalnız 20 V kaynağının katkısıdır.
- Ders sonu: süperpozisyon tamamlandı. Kaynak dönüşümü, Thevenin, Norton ve maksimum güç gelecek haftalara kaldı. Kısa sınav gelecek hafta dersin son saatinde.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kısa sınav 8 Nisan'da, dersin son saatinde. Konular başlangıçtan çevre analizinin sonuna kadar.
- Dirençlerde gerilim referans yönü ile akım yönü uyumlu seçilirse, yönler keyfi seçilse bile aynı denklem sistemi çıkar.
- Süperpozisyonda bağımlı kaynaklar asla sıfırlanmaz. "En çok dikkat etmemiz gereken nokta bu."
- Gerilim kaynağı sıfırlanınca kısa devre, akım kaynağı sıfırlanınca açık devre olur.
- Denklem sistemini matris biçiminde yazmayı ve $A^{-1} b$ ile çözmeyi öğrenin.
- Proteus'ta bağlantısız kalan pinlere dikkat edin. Pilin iç direncini 0 yapın.

## Kısa Tekrar Notları

- Düğüm analizi: $n-1$ denklem. Çevre analizi: göz sayısı kadar denklem.
- Yüzen gerilim kaynağı: süper düğüm ve kısıt denklemi.
- İki çevrenin ortak kolundaki akım kaynağı: süper çevre ve $i_a - i_b = I_S$.
- Bir çevrenin dış kolundaki akım kaynağı: o çevre akımını doğrudan belirler.
- Doğrusallık: $f(a x_1 + b x_2) = a f(x_1) + b f(x_2)$.
- Süperpozisyon: bağımsız kaynakları tek tek bırak, katkıları topla. Bağımlı kaynaklar kalır.
- Güç doğrusal değildir. Süperpozisyonla güç toplanmaz.

## Detaylı Açıklamalar

### Matris biçimine geçiş

- Her denklemde her bilinmeyenin katsayısı aynı sütuna yazılır. Bilinmeyeni olmayan terimler sağ tarafa geçer.
- Örnek 9, devre 1: bilinmeyenler $(i_1, i_2, i_3, i_o')$.
  - $A$ matrisinin satırları: $(1, 0, 0, 0)$, $(-3, 6, -1, -5)$, $(-5, -1, 10, 5)$, $(1, 0, -1, -1)$.
  - Sağ taraf vektörü: $T = (4, 0, 0, 0)^T$.
  - MATLAB'da: `A=[1 0 0 0; -3 6 -1 -5; -5 -1 10 5; 1 0 -1 -1]; T=[4;0;0;0]; inv(A)*T`.
  - $A I = T$ ise iki taraf soldan $A^{-1}$ ile çarpılır: $I = A^{-1} T$.
- Örnek 9, devre 2: bilinmeyenler $(i_4, i_5, i_o'')$.
  - $B$ matrisinin satırları: $(6, -1, -5)$, $(-1, 10, 5)$, $(0, 1, 1)$. Sağ taraf: $Z = (0, 20, 0)^T$.
  - MATLAB'da: `B=[6 -1 -5; -1 10 5; 0 1 1]; Z=[0;20;0]; inv(B)*Z`.

### Süper düğüm ve süper çevre karşılaştırması

- Süper düğüm: gerilim kaynağı gerilimi belirler, akımı bilinmez. Kaynağın iki ucu tek düğüm gibi alınır ve gerilim farkı kısıt olarak yazılır.
- Süper çevre: akım kaynağı akımı belirler, gerilimi bilinmez. Kaynağı paylaşan iki çevre tek çevre gibi alınır ve akım farkı kısıt olarak yazılır.
- Her ikisi de bir bilinmeyenden (kaynağın akımı veya gerilimi) kurtulmak içindir.

### Ders sonrası notlar

- **Süper düğüm tanımı:** Hoca kuralı "eksi ucu referansa bağlı olmayan gerilim kaynağı süper düğümdür" diye verdi. Bu kural, artı ucu referansta olan kaynakları da süper düğüm sayar. Doğrusu, iki ucundan hiçbiri referansa bağlı olmayan (yüzen) kaynaktır. Slayt 28'deki tanım da böyledir. Artı ucu referansta olan kaynak süper düğüm değildir, o düğümün gerilimini doğrudan verir. Örnek 03'te $v_1 = -12$ V ve kısa örnekteki $V_C = -4$ V bu durumdadır.
- **Örnek 9 matrisinin son satırı:** Derste $i_1 - i_o' - i_3 = 0$ denkleminin katsayıları "1, 0, 1, 1" diye okundu. Doğrusu $1, 0, -1, -1$'dir. MATLAB'daki sonuç (4, 4.7059, 0.9412, 3.0588) doğru katsayılarla elde edilen sonuçtur.
- **Örnek 9 devre 2:** Hoca ikinci çevre denkleminde önce 4 Ω'luk direnci unuttu ve sonuç tutmadı. Düzeltilmiş hâlinde $i_5$ katsayısı 10'dur. Sonuç $i_o'' = -\frac{60}{17}$ A.
- **Örnek 04 gerilimleri:** Altyazıda $V_3 = 2.39$ V ve $V_5 = 0.804$ V geçiyor. Hesapla bulunan değerler $V_3 = 2.38$ V ve $V_5 = 0.79$ V'tur. Fark yuvarlamadan kaynaklanır.
- **Karşılaştırma örneği slaytı:** Slayt 50'deki ikinci düzenlenmiş denklem $-0.5v_1 - 0.9333v_2 - 0.1v_3 = 8$ yazılmış. Doğrusu $-0.5v_1 + 0.9333v_2 - 0.1v_3 = 8$'dir. Slayttaki $v_1$, $v_2$ ve $i_x$ sonuçları doğrudur.
- **Süperpozisyon örnek 6 slaytı:** Slayt 30'da direnç birimi "W" yazılmış ($R_{eq} = 44.3$ W, 20 W). Doğrusu Ω'dur.
- **SCR:** Hoca slayttaki "SCR" kısaltmasını hatırlayamadı. Bu bağlamda SCR, silisyum kontrollü doğrultucudur (tristör), doğrusal olmayan bir yarı iletken elemandır. "Seçici katalitik indirgeme" anlamıyla ilgisi yoktur.
- **Altyazıdaki hatalar:** "Super Machine" ifadesi "süper mesh", "Norton TV'nin" ifadesi "Norton, Thevenin", "Matlak" ifadesi "MATLAB", "online yıldız edi terden" ifadesi "online.yildiz.edu.tr'den" olarak okunmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
