# Ders 4 Çalışma Özeti

## Genel Konular

- Y-Δ dönüşümü ve köprü devresinin kısa tekrarı
  - İki üç uçlu ağın eşdeğer olması için her uç çiftinden, üçüncü uç boştayken, görülen direnç iki ağda da aynı olmalıdır (ekrandan, 00:05:00).
  - Y'de $R_1$ sol üst, $R_2$ sağ üst, $R_3$ alt koldadır; Δ'da $R_c$ üstte, $R_a$ solda, $R_b$ sağdadır. Üç eşitlik: $R_1+R_3 = R_a \parallel (R_b+R_c)$, $R_2+R_3 = R_b \parallel (R_a+R_c)$, $R_1+R_2 = R_c \parallel (R_a+R_b)$.
  - Dönüşüm formülleri (ekrandan, 00:10:00): Δ'dan Y'ye $R_1 = \dfrac{R_bR_c}{R_a+R_b+R_c}$, $R_2 = \dfrac{R_aR_c}{R_a+R_b+R_c}$, $R_3 = \dfrac{R_aR_b}{R_a+R_b+R_c}$; Y'den Δ'ya $R_a = \dfrac{R_1R_2+R_2R_3+R_3R_1}{R_1}$, $R_b = \dfrac{\cdots}{R_2}$, $R_c = \dfrac{\cdots}{R_3}$. Eşit dirençlerde $R_\Delta = 3R_Y$.
  - Köprü devresinde dört direnç ortam koşullarından (sıcaklık, ışık, nem) aynı ölçüde etkilenir; ortak etkiler birbirini götürür. Ölçülecek büyüklüğe bağlı $\Delta R$ değişimi köprünün orta uçları arasındaki gerilimde görülür. Hassas tartı gibi ölçümlerde kullanılır.
- Düğüm ve çevre kavramları, yöntem seçimi
  - Düğüm: iki ya da daha fazla elemanın birleştiği nokta. Bir düğüm referans (0 V) seçilir; tercihen bir gerilim kaynağının eksi ucu.
  - Çevre (mesh, çevrim): bir noktadan başlayıp elemanlar üzerinden aynı noktaya dönen kapalı yol. İki gözlü bir devrede üç çevrim yazılabilir ama yalnız ikisi doğrusal bağımsızdır; üçüncüsü diğerlerinin birleşimidir.
  - Tamamen paralel dört elemanlı bir devrede dört bağımsız çevre vardır, ama yalnız iki düğüm vardır; biri referans olunca tek düğüm denklemi yeter. Tamamen seri bir devrede ise çevre analizi daha az denklem verir. Yöntem, düğüm ve göz sayısına bakarak seçilir.
- Matematiksel ön bilgiler: doğrusal denklem sistemleri
  - Bir denklem sisteminin tek çözümü, sonsuz çözümü ya da hiç çözümü olmayabilir. Devre analizinde bağımsız denklem sayısı bilinmeyen sayısına eşit, determinant sıfırdan farklıdır ve tek çözüm vardır.
  - İki bilinmeyende yerine koyma yöntemi pratiktir; daha büyük sistemlerde matris biçimi $A\mathbf{x} = \mathbf{c}$ kullanılır.
  - Cramer kuralı (ekrandan, 00:30:00): $D = a_1b_2 - a_2b_1$, $D_x = c_1b_2 - c_2b_1$, $D_y = a_1c_2 - a_2c_1$; $x = D_x/D$, $y = D_y/D$. Üç bilinmeyende $D_x$, $A$'nın ilk sütunu yerine sağ taraf vektörü konarak elde edilir.
  - 3×3 determinant Sarrus kuralıyla bulunur: ilk iki sütun sağa tekrar yazılır, sol üstten sağ alta inen köşegen çarpımları toplanır, sağ üstten sol alta inen köşegen çarpımları çıkarılır.
  - Sistem Octave ya da MATLAB'da `x = inv(A)*c` ile çözülebilir.
- Düğüm (nodal) analizi
  - Her düğümün referansa göre bir gerilimi vardır. Bu gerilimler dirençlerin uçlarındaki gerilimler değildir; bir direncin akımı iki düğüm geriliminin farkı bölü dirençtir (ekrandan, 00:35:00).
  - Adımlar: referans düğümü seç; düğümleri etiketle; dal akımlarının referans yönlerini ve etiketlerini ver; KCL denklemlerini yaz; her akımı "başlangıç düğümü eksi varış düğümü, bölü direnç" biçiminde düğüm gerilimleriyle yaz; sistemi düğüm gerilimleri için çöz; son olarak dal akımlarını Ohm yasasıyla bul.
  - Gerilim kaynağının referansa bağlı ucu dışındaki ucu doğrudan bilinir ($V_1 = V_{in}$). Seri elemanlara tek bir akım etiketi vermek denklem sayısını azaltır.
- Düğüm analizi örneği 1 (ekrandan, 00:45:00 ve 00:55:00)
  - 10 V kaynak, 9 kΩ, 2 kΩ, 5 kΩ, 3 kΩ, 1 kΩ, 7 kΩ; düğümler $V_1 \ldots V_5$. $V_1 = 10$ V.
  - Direnç gerilimleri: $V_{R1}=4.45$ V, $V_{R2}=0.990$ V, $V_{R3}=1.10$ V, $V_{R4}=0.824$ V, $V_{R5}=0.274$ V, $V_{R6}=3.46$ V (python ile doğrulandı).
  - Hiçbir direnç gerilimi devredeki kaynak gerilimlerinin toplamını (burada 10 V) aşamaz; bu bir sağlamadır.
- Düğüm analizi örneği 2 (ekrandan, 01:10:00 ve 01:20:00)
  - 2 A ve 4 A akım kaynakları, 15 Ω, 7 Ω + 3 Ω seri kolu, 5 Ω. 7 Ω ile 3 Ω arasındaki düğüm, akım kolun toplam direnciyle yazılarak ($I_1 = V_1/10$) yok edilir.
  - Denklemler: $5V_1 - 2V_2 = 60$, $V_1 - 4V_2 = -60$; çözüm $V_1 = V_2 = 20$ V. 15 Ω'dan akım geçmez.
- Süper düğüm (supernode)
  - Uçlarından hiçbiri referansa bağlı olmayan (yüzen) bir bağımsız ya da bağımlı gerilim kaynağı süper düğüm oluşturur. Gerilim kaynağı kendi akımını belirleyemez, bu akımı devrenin geri kalanı belirler.
  - Çözüm: kaynağın iki ucundaki düğüm gerilimleri kaynak gerilimiyle bağlanır ($v_c = v_b + V_2$) ve KCL'de kaynağın akımı yerine ona seri kolun akımı ya da ayrıldığı kolların akımları yazılır (ekrandan, 02:10:00).
  - Örnek 3 (ekrandan, 02:20:00 ve 02:25:00): bağımlı kaynaklı devrede $v_1 = -12$ V, $v_2 = -4$ V, $v_3 = 0$ V, $v_4 = -2$ V.
- Çevre (mesh) analizi
  - Her basit göz için sanal bir çevre akımı tanımlanır. İki gözün paylaştığı elemanın akımı, çevre akımlarının cebirsel farkıdır.
  - Pratik yol: her çevre denklemi yazılırken o çevrenin akım yönünde gerilim düşümü pozitif alınır. Ortak eleman için birinci çevrede $(i_1-i_2)R$, ikinci çevrede $(i_2-i_1)R$ yazılır.
  - Örnek 4 (ekrandan, 01:35:00-01:45:00): $18000i_1 - 5000i_2 = 12$, $-5000i_1 + 14000i_2 = 0$; $i_1 = 740$ µA, $i_2 = 264$ µA. Sağlama: $R_{eq} = 16.2$ kΩ, $I = 12/16.2\text{k} = 740$ µA.
  - İki gözlü örnek (42 V ve 10 V kaynaklar): $9I_1 - 3I_2 = 42$, $-3I_1 + 7I_2 = 10$; $I_1 = 6$ A, $I_2 = 4$ A.
  - Örnek 6 (ekrandan, 01:50:00): 2 V kaynağın gücü $-2.474$ W; kaynak 2.474 W güç verir.
- Süper çevre (supermesh)
  - İki gözün ortak kolunda akım kaynağı varsa, bu iki gözün denklemleri doğrusal bağımlı olur. Bir denklem akım kaynağı kısıtından ($i_1 - i_3 = I_s$) gelir, diğeri akım kaynağını içermeyen daha geniş bir kapalı yoldan yazılır.
  - Örnek 7 (ekrandan, 02:30:00): $i_1 = 9$ A, $i_2 = 2.5$ A, $i_3 = 2$ A.
- Düğüm ve çevre analizinin karşılaştırılması
  - Düzlemsel devre: elemanlar birbirinin üzerinden geçmeden bir düzleme çizilebilen devre. Düzlemsel olmayan devrede çevre analizi doğrudan uygulanamaz.
  - Örnek (ekrandan, 02:40:00 ve 02:45:00): aynı devre düğüm analiziyle üç, çevre analiziyle üç denklemle (dördüncü çevre akımı kaynaktan bilinir) çözülür; iki yöntemde de $i_x = 2.79$ A.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akımı düğüm gerilimleriyle yazarken sıra
  - Akım hangi düğümden hangisine akıyorsa "başlangıç eksi varış" yazılır; "varış eksi başlangıç" yazmak işareti bozar.
- Akım yönü bir kez seçilince değiştirilmez
  - Sonuç negatif çıkarsa akım seçilen yönün tersine akıyordur; yön geri çevrilip denklemler yeniden yazılmaz.
- Ortak elemanda çevre akımlarının işareti
  - Hangi çevrenin denklemi yazılıyorsa o çevrenin akımı pozitif alınır. Sabit bir gerilim referansı kullanılırsa ikinci çevrede "negatifin negatifi" durumu çıkar; dikkat edilmezse hata yapılır.
- Denklem sistemini matris biçimine getirebilmek
  - Asıl iş, bilinmeyenlerin katsayı matrisini doğru yazmaktır. Ödev ve laboratuvar sorularında sonuçların Octave ya da MATLAB ile kontrol edilmesi önerildi.
- İdeal kaynakların davranışı
  - Akım kaynağı kendi kolundaki akımı kesin belirler, uçlarındaki gerilimi devre belirler. Gerilim kaynağı uçlarındaki gerilimi kesin belirler, akımını devre belirler. Süper düğüm ve süper çevre bu yüzden ortaya çıkar.
- Yöntem seçimi
  - Az düğümlü devrede (örneğin tamamen paralel) düğüm analizi, az gözlü devrede (örneğin tamamen seri) çevre analizi daha az denklem verir.

## Kısa Tekrar Notları

- Y-Δ eşdeğerliği: her uç çiftinden, üçüncü uç boşta, aynı direnç görülmeli. Eşit dirençlerde $R_\Delta = 3R_Y$.
- Köprü devresi: ortak ortam etkileri birbirini götürür; ölçülen $\Delta R$ köprü geriliminde görülür.
- Cramer: $x = D_x/D$, $y = D_y/D$; $D_x$, $x$ sütunu yerine sağ taraf konarak bulunur.
- Düğüm analizi: referans seç, düğümleri etiketle, akım yönlerini ver, KCL yaz, akımları $(V_{\text{baş}}-V_{\text{var}})/R$ yaz, çöz, dal akımlarını bul.
- Pratik KCL: bir düğümden dışarı çıkan bütün akımların toplamı sıfırdır (giren kaynak akımları eksi işaretle).
- Bir direncin uçları aynı potansiyeldeyse üzerinden akım geçmez.
- Süper düğüm: yüzen gerilim kaynağı. Uç gerilimleri kaynakla bağlanır, kaynak akımı yerine komşu kolların akımları yazılır.
- Çevre analizi: her göze bir çevre akımı; ortak elemanda akım farkı; kendi çevresinin akımı pozitif.
- Süper çevre: iki gözün ortak kolunda akım kaynağı. Kaynak kısıtı bir denklem, kaynağı içermeyen geniş yol bir denklem verir.
- Sağlama: direnç gerilimi kaynak gerilimleri toplamını aşamaz; çevre akımı ana kol akımını aşamaz; tek kaynaklı devrede ana kol akımı $V/R_{eq}$ ile kontrol edilir.
- Negatif güç: eleman güç veriyordur.

## Detaylı Açıklamalar

- Y-Δ eşdeğerliğinde Y tarafında bir uç boştayken o uca bağlı Y direncinden akım geçmez, bu yüzden yalnız diğer iki Y direnci seri görünür. Δ tarafında ise bakılan iki uç arasındaki Δ direnci, diğer iki Δ direncinin seri toplamına paraleldir. Üç uç çifti için yazılan üç denklem üç bilinmeyeni verir: Y biliniyorsa Δ, Δ biliniyorsa Y bulunur. Köprü devresi ayrıca iki Y, ortak direnci sonsuz (kopuk) iki Δ ya da bir Δ ile bir Y olarak düşünülerek çözülebilir.
- Ders sonrası not: Y-Δ çiziminde (ekrandan, 00:05:00) $R_c$ sol üst ve sağ üst uçlar arasında, $R_a$ sol üst ve alt uç arasında, $R_b$ sağ üst ve alt uç arasındadır. Bu etiketlemeyle üç eşdeğerlik denklemi (python ile sayısal olarak kontrol edildi) $R_1 = R_aR_c/\Sigma$, $R_2 = R_bR_c/\Sigma$ verir. Formül slaytında $R_1$ ile $R_2$'nin payları yer değiştirmiş görünür; formül slaytı büyük olasılıkla $R_a$'nın $R_1$ ucunun karşısında olduğu başka bir etiketlemeye göre hazırlanmıştır. Genel kural: bir Y direnci, kendi ucuna bitişik iki Δ direncinin çarpımı bölü üç Δ direncinin toplamıdır.
- Düğüm analizi örneği 1'de (ekrandan, 00:50:00) $I_7 = I_1 = I_2 = I_6$ ana kol akımıdır ve tek bir $I$ ile gösterilir; $I_4 = I_5$ de aynı koldadır. $I = (V_1-V_2)/9000 = (V_2-V_3)/2000 = V_5/7000$, $I = I_3 + I_4$, $I_3 = (V_3-V_5)/5000$, $I_4 = (V_3-V_4)/3000$ ya da $V_4$ hiç kullanılmadan $I_4 = (V_3-V_5)/4000$ yazılabilir. Hiç indirgeme yapmadan bütün akımlar ayrı bilinmeyen olarak yazılırsa denklem sayısı bilinmeyen sayısını aşabilir; bunların yalnız doğrusal bağımsız olanları kullanılır. Sonuçta $V_1 - V_2 = 4.45$ V ve $I_1 = 4.45/9\text{k} \approx 0.495$ mA.
- Düğüm analizi örneği 2'de KCL: $V_1$ düğümünde $2 = I_1 + I_2$, $V_2$ düğümünde $4 + I_2 = I_3$. $I_1 = (V_1 - V_3)/7$ yazılırsa $V_3$ yeni bilinmeyen olur ve ek denklem gerekir; bunun yerine $I_1 = V_1/10$ yazılır. $I_2 = (V_1-V_2)/15$, $I_3 = V_2/5$. 30 ile çarpılınca $5V_1 - 2V_2 = 60$, 15 ile çarpılınca $V_1 - 4V_2 = -60$. Derste ikinci denklemin sağ tarafı önce $+60$ yazıldı ve Octave $6.67$ V, $-13.3$ V verdi; bir öğrencinin uyarısıyla işaret düzeltildi ve $V_1 = V_2 = 20$ V bulundu (ekrandan, 01:20:00). $I_1 = 2$ A, $I_3 = 4$ A, $I_2 = 0$.
- Ders sonrası not: Uçları aynı potansiyelde olan ve akım taşımayan 15 Ω'luk direnç için derste önce "açık devre gibi", sonra "kısa devre diyebiliriz" denildi. Gerilimi de akımı da sıfır olan bir eleman, devrenin geri kalanını değiştirmeden hem açık devreyle hem kısa devreyle değiştirilebilir.
- Süper düğümde (ekrandan, 02:10:00) $v_a = V_1$ bilinir. $b$ ile $c$ arasındaki kaynağın akımı yazılamaz; ama bu akım $R_1$ kolunun akımıdır: $(V_1 - v_c)/R_1$ ve $v_c = v_b + V_2$. $b$ düğümündeki KCL $\dfrac{V_1 - v_b}{R_2} - \dfrac{v_b}{R_3} + \dfrac{V_1 - (v_b+V_2)}{R_1} = 0$ tek bilinmeyen $v_b$'yi verir. $v_c$ ile $v_b$ arasındaki ilişkiyi karıştırmamak için referanstan başlayıp $v_b$, kaynak ve $v_c$ üzerinden referansa dönen bir KVL yolu yazılabilir: $-v_b - V_2 + v_c = 0$.
- Süper düğüm örneği 3'te (ekrandan, 02:20:00) $v_1 = -12$ V doğrudan bilinir. $v_2$ düğümünde $\dfrac{v_2-v_1}{0.5} + \dfrac{v_2-v_3}{2} = 14$. $v_3$ düğümünde bağımlı gerilim kaynağının akımı, $v_4$'te ikiye ayrılan kolların toplamıyla yazılır: $0.5v_x = \dfrac{v_3-v_2}{2} + \dfrac{v_4}{1} + \dfrac{v_4-v_1}{2.5}$. Ek ilişkiler $v_x = v_2 - v_1$, $v_3 - v_4 = 0.2v_y$, $v_y = v_4 - v_1$. Düzenlenmiş sistem (ekrandan, 02:25:00): $-2v_1 + 2.5v_2 - 0.5v_3 = 14$, $0.1v_1 - v_2 + 0.5v_3 + 1.4v_4 = 0$, $v_1 = -12$, $0.2v_1 + v_3 - 1.2v_4 = 0$. Çözüm python ile doğrulandı.
- Çevre analizi örneği 4'te (ekrandan, 01:40:00) birinci çevre $-12 + 4000i_1 + 8000i_1 + 5000(i_1-i_2) + 1000i_1 = 0$, ikinci çevre $6000i_2 + 3000i_2 + 5000(i_2-i_1) = 0$. 5 kΩ üzerindeki akım $i_1 - i_2 = 476$ µA. Eşdeğer direnç sağlaması (ekrandan, 01:45:00): $R_{eq} = 1 + [5 \parallel (3+6)] + 8 + 4 = 16.2$ kΩ.
- 42 V'luk iki gözlü örnekte birinci çevre $-42 + 6I_1 + 3(I_1 - I_2) = 0$, ikinci çevre $-10 + 3(I_2 - I_1) + 4I_2 = 0$. Çözüm (Octave ekranından, 02:25:00) $I_1 = 6$ A, $I_2 = 4$ A; 6 Ω'da 36 V, 4 Ω'da 16 V, 3 Ω'da $(6-4)\cdot 3 = 6$ V düşer. <!-- BELİRSİZ: Bu örneğin devre şeması karelerde yok; eleman yerleri altyazıdan kurulmuştur. -->
- Örnek 6'da (ekrandan, 01:50:00) $-5 + 4i_1 + 2(i_1-i_2) - 2 = 0$ ve $2 + 2(i_2-i_1) + 5i_2 + 1 = 0$; $i_1 = 43/38 = 1.132$ A, $i_2 = -2/19 = -0.1053$ A. 2 V kaynaktan yukarıdan aşağı $i_1 - i_2 = 1.237$ A geçer; akım kaynağa eksi ucundan girdiği için emilen güç $-(2)(1.237) = -2.474$ W'tır, yani kaynak 2.474 W verir.
- Süper çevre örneği 7'de (ekrandan, 02:30:00) 7 A kaynak $i_1$ ve $i_3$ gözlerinin ortak kolundadır. Süper çevre: $-7 + 1(i_1-i_2) + 3(i_3-i_2) + 1i_3 = 0$; 2. göz: $1(i_2-i_1) + 2i_2 + 3(i_2-i_3) = 0$, yani $-i_1 + 6i_2 - 3i_3 = 0$; kaynak kısıtı $i_1 - i_3 = 7$. Sonuç $i_1 = 9$ A, $i_2 = 2.5$ A, $i_3 = 2$ A. Kaynağa seri 2 Ω'da $7 \cdot 2 = 14$ V, üstteki 1 Ω'da $i_1 - i_2 = 6.5$ A ile 6.5 V, 3 Ω'da verilen yönde $3(i_3 - i_2) = -1.5$ V düşer.
- Karşılaştırma örneğinde (ekrandan, 02:40:00) 100 V kaynaklı düğüm referansa göre bilindiği için etiketlenmez. Düğüm denklemleri: $\dfrac{v_1-100}{8} + \dfrac{v_1}{4} + \dfrac{v_1-v_2}{2} = 0$, $\dfrac{v_2-v_1}{2} + \dfrac{v_2}{3} + \dfrac{v_2-v_3}{10} = 8$, $\dfrac{v_3-v_2}{10} + \dfrac{v_3}{5} + 8 = 0$. Sonuç $v_1 = 25.89$ V, $v_2 = 20.31$ V, $i_x = (v_1-v_2)/2 = 2.79$ A. Çevre denklemleri (ekrandan, 02:45:00): $12i_1 - 4i_2 = 100$, $-4i_1 + 9i_2 - 3i_3 = 0$, $-3i_2 + 18i_3 = -80$ ve $i_4 = -8$ A; $i_2 = i_x = 2.79$ A.
- Ders sonrası not: Karşılaştırma slaytındaki ikinci düğüm denkleminin düzenlenmiş biçimi $-0.5v_1 - 0.9333v_2 - 0.1v_3 = 8$ yazılmıştır; doğrusu $-0.5v_1 + 0.9333v_2 - 0.1v_3 = 8$'dir (python ile kontrol edildi, bu biçim $v_2 = 20.31$ V'u verir). Altyazıda $v_2$ "20.53" geçer; slayttaki ve hesaplanan değer 20.31 V'tur.
- Ders sonrası not: Süper düğümün tek bilinmeyenle çözülmesi derste bir yerde "süperpozisyon özelliği" diye anıldı; kastedilen süper düğümdür. Süperpozisyon ayrı bir konudur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
