# Ders 7 Çalışma Özeti

## Genel Konular

- Diyotun temel davranışının tekrarı
  - Diyot doğru polarmada akımı tek yönde ileten, ters polarmada açık devre gibi davranan (sonsuz direnç gösteren) bir devre elemanıdır. Uçları anot (artı) ve katottur (eksi).
  - Diyot sembolünün altındaki Si, Ge gibi kısaltmalar malzemeyi gösterir. Eşik gerilimleri: silisyum 0,7 V, germanyum 0,3 V, galyum arsenür 1,2 V.
  - İdeal diyot, anot-katot gerilimi sıfırın üstüne çıkınca iletime geçer ve üzerinde gerilim düşmez.
- Seri diyot devresi (ekrandan, 00:15:00 ve 00:20:00)
  - Doğru polarmada silisyum diyot için $V_D = 0{,}7$ V (eğer $E < 0{,}7$ V ise $V_D = E$), $V_R = E - V_D$, $I_D = I_R = I_T = V_R / R$.
  - Ters polarmada diyot açık devredir: $V_D = E$, $V_R = 0$ V, $I_D = 0$ A.
  - Kural: diyot kesimdeyken üzerindeki gerilim besleme gerilimine eşittir; iletimdeyken yalnız eşik gerilimi kadardır (ideal diyotta 0 V).
- Paralel diyot devresi (ekrandan, 00:25:00)
  - 10 V kaynak, $0{,}33\ \text{k}\Omega$ direnç ve paralel iki silisyum diyot: $V_O = 0{,}7$ V, $V_R = 9{,}3$ V, $I_R \approx 28$ mA, $I_{D1} = I_{D2} \approx 14$ mA.
  - KCL'ye göre kollardaki akımların toplamı ana kol akımına eşittir; kollardan birinde direnç olsa da bu eşitlik bozulmaz.
- Doğrultucular (AC'den DC'ye çevirme)
  - Yarım dalga doğrultucu: diyot yalnız pozitif yarı periyotta iletir, çıkış ortalaması $V_{DC} = 0{,}318\,V_m$ (ekrandan, 00:30:00).
  - Tepe ters gerilimi (PIV): diyotun ters polarmada dayanabileceği en büyük gerilim, girişin tepe değerinden büyük olmalıdır; aksi hâlde diyot bozulur ve kısa devre gibi davranabilir.
  - Tam dalga köprü doğrultucu: dört diyot, her yarı periyotta iki diyot iletir, $V_{DC} = 0{,}636\,V_m$ (ekrandan, 00:40:00).
  - Orta uçlu transformatörlü doğrultucu: her yarı periyotta tek diyot iletir, $V_{DC} = 0{,}636\,V_m$.
- Kırpıcılar (clipper)
  - Sinyalin bir kısmını kesen devrelerdir. Yarım dalga doğrultucu bir kırpıcıdır, ama her doğrultucu kırpıcı değildir; tepeleri kesen devre de kırpıcıdır.
  - Seri, paralel, beslemeli (DC kaynaklı) ve çift yönlü türleri vardır (ekrandan, 00:50:00, 00:55:00, 01:00:00, 01:05:00).
- Kenetleyiciler (clamper)
  - Diyot, kondansatör ve dirençten oluşur; sinyalin biçimini değiştirmeden onu belirli bir DC seviyeye kaydırır (ekrandan, 01:25:00).
  - Beslemeli kenetleyicide DC kaynak kenetleme seviyesini ayarlar (ekrandan, 01:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Diyot uygulamaları konusu çok önemlidir
  - Hoca bu konunun her sınavda soru olarak gelebileceğini, diyotun endüstride çok yaygın kullanıldığını söyledi. Kırpıcı ve kenetleyici devrelerin kafa karıştırıcı sorulara uygun olduğunu ayrıca vurguladı.
- Analize $t = 0$ anından başlamak
  - Beslemeli kırpıcılarda giriş sıfırken diyotun iletimde mi kesimde mi olduğuna bakmak, devrenin geri kalan davranışı için ipucu verir.
  - Kenetleyicilerde ise kondansatörün dolduğu (diyotun iletime geçtiği) yarı periyottan başlamak daha mantıklıdır.
- Çıkışın nereden ölçüldüğüne dikkat
  - Seri kırpıcıda çıkış direnç üzerinden, paralel kırpıcıda diyot (ve varsa kaynak) üzerinden alınır. Çıkışın artı-eksi yönü ters verilirse grafik eksene göre ters döner.
- Ezber yerine mantık
  - Devrelerin çok fazla varyasyonu vardır. Hoca her devreyi bir simülasyon programında kurup osiloskopta çıkışını gözlemlemeyi önerdi.
- Doğrultucu formüllerinde işlem sırası
  - Hoca gerçekçi formüllerde önce $0{,}318\,V_m$ (ya da $0{,}636\,V_m$) çarpımının alınıp sonra diyot düşümünün çıkarıldığını söyledi (bkz. Detaylı Açıklamalar'daki ders sonrası not).

## Kısa Tekrar Notları

- Si: 0,7 V, Ge: 0,3 V, GaAs: 1,2 V. İdeal diyotta iletimde 0 V.
- Diyot kesimde: $V_D = E$, akım yok. Diyot iletimde: $V_D = 0{,}7$ V (Si).
- Paralel aynı diyotlar akımı eşit paylaşır; $V_O = 0{,}7$ V.
- Yarım dalga: $0{,}318\,V_m$; köprü ve orta uçlu: $0{,}636\,V_m$.
- Köprüde her yarı periyotta iki diyot, orta uçluda bir diyot iletir.
- Diyotun PIV değeri giriş tepe geriliminden büyük olmalıdır.
- Beslemeli seri kırpıcı (5 V, ±20 V giriş): çıkış $v_i + 5$ V, en çok 25 V; $v_i < -5$ V iken çıkış 0.
- Paralel kırpıcı, diyotu doğru polarlayan gerilimi kırpar; seri DC kaynak kırpma seviyesini değiştirir.
- Kenetleyici: kare dalga $\pm V$ girişte çıkış 0 ile $-2V$ arası (diyot yönüne göre 0 ile $+2V$).
- Beslemeli kenetleyici (10 V, ±20 V giriş): kondansatör 10 V'a dolar, çıkış $-10$ V ile $+30$ V arası.

## Detaylı Açıklamalar

- Diyot tekrarı ve gerilim kuralları
  - Doğru polarmada diyot, malzemesine özgü eşik gerilimi aşılınca iletime geçer. Seri bir devrede diyot iletimdeyse üzerindeki gerilim eşik kadardır, kalan gerilim dirençte düşer. Örneğin girişte 0,3 V varsa silisyum diyot iletime geçemez; kesimde olduğu için üzerindeki gerilim 0,3 V'un tamamıdır. Aynı 0,3 V ideal bir diyota uygulanırsa diyot iletimdedir ve üzerinde 0 V okunur.
  - Ters polarmada akım geçmediği için dirençte gerilim oluşmaz; KVL'ye göre kaynağın bütün gerilimi diyot üzerinde görülür.
  - > **Ders sonrası not:** Hoca 0,7 V'u silisyumun "iç direncinden doğan" bir gerilim olarak tarif etti. 0,7 V büyük olasılıkla p-n eklemindeki potansiyel bariyerden (tükenme bölgesi) kaynaklanan eşik gerilimidir; diyotun ayrıca küçük bir iç direnci vardır.
- Paralel diyot örneği
  - 10 V kaynak, $R = 0{,}33\ \text{k}\Omega$ ve paralel iki Si diyotta diyotlar iletimdedir. Çıkış diyotların üzerinden alındığı için $V_O = 0{,}7$ V olur. Dirençte $10 - 0{,}7 = 9{,}3$ V düşer ve $I_R = 9{,}3/0{,}33 \approx 28$ mA bulunur. Diyotlar aynı olduğu için akım ikiye bölünür: $I_{D1} = I_{D2} \approx 14$ mA (ekrandan, 00:25:00; python ile kontrol: 28,18 mA ve 14,09 mA).
  - Kollardan biri kaldırılıp diğer kola ikinci bir seri diyot eklenirse kolda $1{,}4$ V düşer, ana kol akımı azalır, ama tek kalan koldan geçen akım öncekine göre artar. Diyotlar ters bağlanırsa akım sıfır olur ve $V_O = 10$ V okunur.
- Doğrultucular
  - Şebekedeki AC gerilim, küçük cihazlar ve bataryalar için DC'ye çevrilmelidir. Yarım dalga doğrultucuda diyot pozitif yarı periyotta iletir ve çıkış girişe eşittir; negatif yarı periyotta kesimdedir ve çıkış 0'dır. AC sinüsün ortalaması sıfırdır; negatif kısımlar silinince ortalama $0{,}318\,V_m$ olur. Hoca $V_m = 5$ V için yaklaşık 1,6 V verdi (python: 1,59 V).
  - Köprü doğrultucuda pozitif yarı periyotta bir diyot çifti, negatif yarı periyotta öbür çift iletir; ölçü aletinin uçları değiştirilmediği hâlde direnç üzerindeki gerilim iki yarı periyotta da aynı işaretlidir. Ortalama iki katına çıkar: $0{,}636\,V_m$.
  - Orta uçlu transformatörlü devrede transformatör girişi iki kola aynı genlikte verir (gerilimi iki katına çıkarmaz, iki kanal açar). Her yarı periyotta kollardan yalnız birindeki diyot iletir.
  - Gerçekçi değerler (ekrandan, 00:45:00): yarım dalga $0{,}318\,V_m - 0{,}7$, köprü $0{,}636\,V_m - 2(0{,}7\ \text{V})$, orta uçlu $0{,}636\,V_m - 0{,}7$ V.
  - > **Ders sonrası not:** Hoca slayttaki gibi önce çarpılıp sonra 0,7 V çıkarılacağını, $(V_m - 0{,}7)$'nin çarpılmayacağını söyledi. Diyot düşümü tepe değerinden düştüğü için ortalama büyük olasılıkla $0{,}318\,(V_m - 0{,}7)$'ye daha yakındır. Ajan sayısal integralle kontrol etti: $V_m = 5$ V için gerçek ortalama 1,26 V, $0{,}318(V_m - 0{,}7) = 1{,}37$ V, $0{,}318V_m - 0{,}7 = 0{,}89$ V.
- Kırpıcılar
  - Basit seri kırpıcıda diyot yönüne göre ya pozitif ya negatif yarı periyot geçer. Basit paralel kırpıcıda çıkış diyot üzerinden alınır; diyot iletimdeyken (ideal) çıkış 0, kesimdeyken çıkış girişe eşittir.
  - Beslemeli seri kırpıcı (5 V kaynak, ±20 V giriş): $t = 0$'da 5 V kaynak diyotu iletimde tutar, çıkış 5 V'tur. Çıkış $v_i + 5$ V olarak 25 V'a çıkar, $v_i = -5$ V'a inince diyot kesime girer ve çıkış 0 olur (ekrandan, 00:50:00). Diyot silisyum ise kaynak etkin olarak 4,3 V gibi davranır.
  - Beslemeli paralel kırpıcılarda kaynağın yönü kırpma seviyesini belirler; iki zıt yönlü kollu çift yönlü kırpıcı çıkışı $V_1$ ile $-V_2$ arasında sınırlar (ekrandan, 01:05:00).
- Kenetleyiciler
  - Diyot iletimdeyken kondansatör dolar, diyot kesime girince kondansatör gerilimi girişe eklenir. Kare dalga $\pm V$ girişte çıkış 0 ile $-2V$ arasında olur (ekrandan, 01:25:00).
  - Beslemeli kenetleyicide (10 V kaynak, ±20 V giriş) diyot giriş $-10$ V'un altına inince iletir, kondansatör 10 V'a dolar ve çıkış $-10$ V ile $+30$ V arasında salınır (ekrandan, 01:30:00). Kaynak 5 V olsaydı kondansatör 15 V'a dolar, çıkış $-5$ V ile $+35$ V arasında olurdu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
