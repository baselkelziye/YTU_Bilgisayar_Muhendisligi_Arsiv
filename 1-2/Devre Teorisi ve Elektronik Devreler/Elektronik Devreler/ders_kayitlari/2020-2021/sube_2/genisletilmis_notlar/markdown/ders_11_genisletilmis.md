# Ders 11 Genişletilmiş Notu: BJT Konfigürasyonları, Alfa ve Beta, Kutuplama ve Çalışma Noktası

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. BJT yapısının ve çalışma şartının tekrarı
- 2. Transistör akımları
- 3. Ortak base konfigürasyonu
- 4. Ortak emiter konfigürasyonu ve beta
- 5. Ortak kolektör konfigürasyonu ve güç harcaması
- 6. Bilgi sayfası, bacak düzeni ve transistör testi
- 7. Kutuplama ve çalışma noktası
- 8. Kutuplama devrelerinin analizi
- 9. Transistörlü anahtarlama devresi
- Örnek Sorular
- Dersin Toparlaması

## 1. BJT yapısının ve çalışma şartının tekrarı

Ders, önceki derste girişi yapılan transistör konusunun devamıdır. Hoca bu derste formüllerin nereden geldiğini göstereceğini, soru çözümüne ise sonraki derste geçeceğini söyledi.

Bipolar transistör, diyottaki p-n eklemi mantığıyla kurulur; iki diyotun art arda (sırt sırta) bağlanması gibi düşünülebilir. Üç bölge (p ve n maddelerinin üçlü kombinasyonu) olduğu için iki tip vardır: orta bacağın, yani base'in n tipi olduğu PNP ve p tipi olduğu NPN. Transistörün üç bacağı emiter (E), base (B) ve kolektör (C)'dür.

Transistörün çalışabilmesi için iki şart vardır:

- Base-emiter eklemi doğru polarlanır. PNP'de p tarafına (emitere) artı, n tarafına (base'e) eksi verilince yükler birbirini iter ve bu eklemdeki fakirleşmiş bölge (depletion region) daralır.
- Base-kolektör eklemi ters polarlanır, böylece buradaki fakirleşmiş bölge genişler.

Bu kural transistörün PNP ya da NPN olmasına göre değişmez. NPN'de doğru polarma için emitere eksi, base'e artı; kolektöre ise artı verilir.

> **Hocanın vurgusu:** Emiter-base doğru polarmalı, base-kolektör ters polarmalı bağlanır. Transistörün bütün çalışması bu kurala dayanır.

Şematik sembolde ok emiter bacağı üzerindedir ve okun yönüne bakarak transistörün NPN mi PNP mi olduğu anlaşılır. <!-- BELİRSİZ: Hocanın okun yönünü tiple eşleştirdiği anlatım altyazıda bozuk (00:22:11-00:22:52). -->

> **Ek bilgi (derste anlatılmadı):** Standart sembolde ok, emiterdeki geleneksel akım yönünü gösterir. NPN'de ok dışarı (emiterden çıkan akım), PNP'de içeri doğrudur.

## 2. Transistör akımları

Slayttaki NPN yapısında (n-p-n blok, $V_{EE}$ ve $V_{CC}$ kaynakları) emiter akımı kolektör ve base akımlarının toplamıdır (ekrandan, 00:20:00):

$$I_E = I_C + I_B$$

Bu bağıntı akımların korunumundan (KCL) gelir ve bütün konfigürasyonlarda geçerlidir. Hoca bunu dersin en çok kullanılacak formülü olarak tanıttı. Emiter akımı giriş, kolektör akımı çıkış akımı gibi düşünülebilir.

Base akımı çok küçüktür, mikroamper düzeyindedir.

> **Hocanın vurgusu:** Bir soruda $I_B$'yi bulduğunuzda amper ya da örneğin 50 mA gibi bir değer çıkarsa büyük olasılıkla bir yerde hata yapmışsınızdır. Base akımının mikroamper düzeyinde çıkması beklenir.

Slaytta kolektör akımının iki bileşenden oluştuğu da yazılıdır (ekrandan, 00:20:00):

$$I_C = I_{C\,majority} + I_{CO\,minority}$$

Hoca azınlık taşıyıcı akımına ($I_{CO}$) girmeyeceklerini, bunun sıcaklıkla ilgili bir sızıntı akımı olduğunu ve derste hesaplanmayacağını söyledi.

> **Ders sonrası not:** Hoca base akımını "gerçek bir akım değil, sızıntı akımı" diye niteledi. Doğrusu, base akımı büyük olasılıkla base bölgesindeki yeniden birleşmeden ve base'ten emitere taşıyıcı enjeksiyonundan kaynaklanan gerçek bir akımdır; sızıntı akımı slayttaki $I_{CO}$ bileşenidir.

## 3. Ortak base konfigürasyonu

### 3.1 Bağlantı

Ortak base (common-base, CB) konfigürasyonunda base hem emiter hem kolektör devresine bağlıdır, yani ikisinde de ortaktır. Önceki anlatımın tamamı bu senaryo üzerindedir: PNP'de emitere artı, base'e eksi; NPN'de emitere eksi, base'e artı verilerek BE doğru polarlanır, kolektör tarafı ters polarlanır. CB konfigürasyonu genelde yükselteç (amplifier) devrelerinde kullanılır.

### 3.2 Giriş karakteristiği

Ortak base'de en önemli giriş değişkeni emiter akımıdır. Slayttaki eğri, $I_E$ (mA) ile $V_{BE}$ (V) arasındaki ilişkiyi $V_{CB}$ = 1 V, 10 V ve 20 V için gösterir (ekrandan, 00:25:00).

Grafikte $V_{BE}$ yaklaşık 0,6–0,7 V'a gelene kadar emiter akımı oluşmaz; ne kadar doğru polarma verilse de eşik aşılmadan akım akmaz. Hoca bunu slaytın kenarına iki diyot çizerek açıkladı: base-emiter eklemi bir diyottur ve silisyumdan kaynaklanan yaklaşık 0,7 V'luk bariyer aşılınca iletime geçer. $V_{BE}$ 0,7 V'u geçip doğru polarma sağlanınca emiterde akım oluşur.

$V_{CB}$'nin etkisi: kolektör-base arasındaki ters polarma gerilimi ne kadar artırılırsa, aynı $V_{BE}$'de emiter akımı o kadar yüksek olur. Hoca örnek olarak $V_{BE}$ = 0,8 V için $V_{CB}$ = 1 V'ta yaklaşık 5 mA, $V_{CB}$ = 20 V'ta yaklaşık 8 mA okudu. <!-- BELİRSİZ: Bu iki değer altyazıdan alındı; karede eğriler 0,8 V civarında bitiyor ve değerler tam okunmuyor (00:27:08). -->

Hocanın yorumu: transistörün temel kuralı "kolektör-base ne kadar ters, emiter-base ne kadar doğru polarmalı ise o kadar iyi" diye düşünülebilir. Eşikten sonra $V_{BE}$'yi artırmak $I_E$'de çok hızlı bir artış sağlar; $V_{CB}$'yi artırmak daha az etkilidir ama yine $I_E$'yi artırır.

### 3.3 Çıkış karakteristiği

Çıkıştan kastedilen kolektör akımıdır. Slayttaki grafik $I_C$ (mA) ile $V_{CB}$ (V) ilişkisini $I_E$ = 0, 1, 2, ..., 7 mA için gösterir (ekrandan, 00:30:00). Grafikte üç bölge vardır:

- Aktif bölge (taranmamış alan): eğriler yataydır ve $I_C$ yaklaşık $I_E$'ye eşittir. Örneğin $I_E$ = 1 mA iken herhangi bir $V_{CB}$ değerinde $I_C$ de yaklaşık 1 mA'dir.
- Kesim bölgesi (cutoff): $I_E = 0$ eğrisinin altı; emiter akımı olmadığından kolektör akımı da oluşmaz.
- Doyum bölgesi (saturation): $V_{CB}$'nin negatif olduğu sol taraftaki dar şerit.

Hoca, başta sözle anlatılan "emiter-base doğru, base-kolektör ters" kuralının bu grafiklerde görüldüğünü belirtti.

### 3.4 Yaklaşık analiz ve alfa

Normalde $I_E = I_C + I_B$'dir; ama base akımı o kadar küçüktür ki yaklaşık analizde $I_C \approx I_E$ alınmasında sakınca görülmez. Bazı sorularda yine de $I_B$'nin bulunması gerekir. Base-emiter gerilimi $V_{BE} \approx 0{,}7$ V alınır.

Alfa, kolektör akımının emiter akımına (çıkış akımının giriş akımına) oranıdır:

$$\alpha = \frac{I_C}{I_E}$$

İdealde $\alpha = 1$'dir, yani base akımı yok sayılır. Pratikte $I_B$ sıfır olmadığından $\alpha$ 0,9 ile 0,998 arasında bir değerdir. Soruda $\alpha$ verilebilir ya da bulunması istenebilir. $\alpha$ ve $I_E$ verilirse $I_C = \alpha I_E$ bulunur, ardından $I_B = I_E - I_C$ kolayca hesaplanır.

### 3.5 Ortak base yükselteç örneği

Hoca ortak base devresinin yükseltme işlevini bir örnekle gösterdi (derste sözlü, 00:32:04):

- Verilen: girişte 200 mV'luk sinüs işaret, 20 Ω'luk giriş direnci ($R_i$), çıkışta 5 kΩ'luk yük direnci; $V_L$ isteniyor.
- Emiter akımı: $I_E = 200\text{ mV} / 20\ \Omega = 10$ mA.
- Kabul: base akımı yok sayılır, $I_C \approx I_E = 10$ mA.
- Çıkış gerilimi: $V_L = I_C R_L = 10\text{ mA} \times 5\text{ kΩ} = 50$ V.
- Sonuç: 200 mV'luk giriş 50 V'a çıkmıştır; gerilim kazancı $50 / 0{,}2 = 250$'dir (python ile doğrulandı).

## 4. Ortak emiter konfigürasyonu ve beta

### 4.1 Bağlantı

Ortak emiter (common-emitter, CE) konfigürasyonunda emiter bacağı hem base hem kolektör devresine gider. Yine emiter-base doğru polarlanır; örneğin NPN'de base'teki p bölgesine artı, emitere eksi verilir. Hoca hangi eklemin ters polarlanmasının daha önemli olduğunu sordu ve cevapladı: kolektöre her zaman ters polarma verilmelidir, çünkü kolektör, kolektör-base arasındaki fakirleşmiş bölgeyi genişleten elemandır. $I_E = I_C + I_B$ burada da geçerlidir.

### 4.2 Karakteristikler

Slaytta iki grafik vardır (ekrandan, 00:35:00):

- Kolektör karakteristiği: $I_C$ (mA) – $V_{CE}$ (V), $I_B$ = 0, 10, 20, ..., 90 µA için. Sol kenarda doyum bölgesi ($V_{CE\,sat}$), $I_B = 0$ eğrisinin altında kesim bölgesi ($I_{CEO} \cong \beta I_{CBO}$) ve ortada aktif bölge işaretlidir.
- Base karakteristiği: $I_B$ (µA) – $V_{BE}$ (V), $V_{CE}$ = 1 V, 10 V ve 20 V için.

Base karakteristiğinde de $I_B$'nin oluşması için $V_{BE}$'nin 0,7 V'u geçmesi gerekir. Burada fark şudur: aynı $V_{BE}$'de $V_{CE}$ küçükken $I_B$ daha büyüktür (grafikte $V_{CE}$ = 1 V eğrisi en soldadır). Hoca bunu, $V_{CC}$'nin base tarafına da bir doğru polarma etkisi yapmasıyla açıkladı ve CE için $V_{CE}$'yi ters polarmayı koruyarak küçük tutmanın base akımını daha verimli aldığını söyledi.

Kolektör karakteristiğinde $V_{CE}$ sıfırın üstünde olmalıdır. Base akımı arttıkça kolektör akımı daha yüksek seviyelere çıkar.

### 4.3 Alfa ile ilişki ve sızıntı akımı

Hoca alfanın tanımını hatırlattı: $\alpha = I_C / I_E$ ve $I_C$, $I_E$'den biraz küçük olduğu için 0,9 civarı (ve üstü) bir değerdir. Soruda $I_E$ ve $\alpha$ verilirse $I_C = \alpha I_E$ ile kolektör akımı bulunur. Slayttaki azınlık kolektör akımı (sızıntı akımı) sıcaklıkla ilgili sorunlarda hesaplanır; hoca bu hesaba girmeyeceklerini söyledi.

### 4.4 Beta

Beta, kolektör akımının base akımına oranıdır:

$$\beta = \frac{I_C}{I_B}$$

Base akımı mikroamper, kolektör akımı miliamper düzeyinde olduğundan beta genelde 50, 100, 200 gibi değerler alır.

### 4.5 Grafikten beta bulma

Slayttaki örnekte $V_{CE}$ = 7,5 V'ta beta isteniyor (ekrandan, 00:40:00). $V_{CE}$ = 7,5 V'tan dikey bir çizgi çekilir ve iki komşu $I_B$ eğrisiyle kesiştiği noktalarda $I_C$ okunur:

- $I_{B2}$ = 30 µA iken $I_{C2}$ = 3,2 mA,
- $I_{B1}$ = 20 µA iken $I_{C1}$ = 2,2 mA.

$$\beta_{AC} = \frac{3{,}2\text{ mA} - 2{,}2\text{ mA}}{30\text{ µA} - 20\text{ µA}} = \frac{1\text{ mA}}{10\text{ µA}}\Big|_{V_{CE}=7{,}5} = 100$$

Slaytta aynı $V_{CE}$'deki Q-noktası ($I_B$ = 25 µA, $I_C$ = 2,7 mA) için DC beta da verilmiştir:

$$\beta_{DC} = \frac{2{,}7\text{ mA}}{25\text{ µA}}\Big|_{V_{CE}=7{,}5} = 108$$

(İki sonuç python ile doğrulandı.)

Hoca, betanın transistörün üretimden (fabrikasyondan) gelen bir parametresi olduğunu, bu yüzden aynı hesabın örneğin $V_{CE}$ = 15 V'ta yapılmasının da yakın bir sonuç vereceğini söyledi. İki farklı değerin ortalaması alınarak da bulunabilir ve yakın çıkar; ama en doğru yöntem üreticinin verdiği gerçek değeri kullanmaktır.

### 4.6 Alfa ve beta bağıntıları

Bütün işlemler üç akım üzerinden yürür: $I_E$, $I_B$, $I_C$. Bilinen iki bağıntı ($I_E = I_C + I_B$ ve $\beta = I_C/I_B$) birleştirilerek yeni formüller türetilir:

$$I_C = \beta I_B$$

$$I_E = I_C + I_B = \beta I_B + I_B = (\beta + 1) I_B$$

Hoca bu türetmeyi slayt üzerinde adım adım yazdı: $I_C$ yerine $\beta I_B$ konur, $I_B$ ortak paranteze alınır. Böylece base akımı biliniyorsa betanın bir fazlasıyla çarpılarak doğrudan emiter akımı bulunur; emiter akımından base akımı çıkarılınca da kolektör akımı elde edilir.

Alfa ve beta da birbirine bağlıdır; $I_E$'ler eşitlenerek şu formüller bulunur:

$$\alpha = \frac{\beta}{\beta + 1}, \qquad \beta = \frac{\alpha}{1 - \alpha}$$

> **Ek bilgi (derste anlatılmadı):** $\alpha = I_C/I_E = \beta I_B / [(\beta+1) I_B] = \beta/(\beta+1)$ olarak elde edilir; bu ifade $\beta$ için çözülünce $\beta = \alpha/(1-\alpha)$ çıkar.

## 5. Ortak kolektör konfigürasyonu ve güç harcaması

### 5.1 Ortak kolektör

Ortak kolektör (common-collector, CC) konfigürasyonunda kolektör hem base hem emiter devresine dahildir. Karakteristikleri ortak emitere benzer, hoca üzerinde fazla durmadı. Bilinmesi gereken: belli bir $V_{CE}$ değerinde (örneğin 5 V) analiz isteniyorsa, o $V_{CE}$'de $I_B$ eğrilerine karşılık gelen akım değerleri grafikten okunur.

> **Ders sonrası not:** Hoca ortak kolektörde "base-kolektör doğru, emiter-kolektör ters polarize edilir" dedi. Doğrusu, transistör hangi konfigürasyonda bağlanırsa bağlansın aktif bölgede base-emiter eklemi doğru, base-kolektör eklemi ters polarlanır; konfigürasyon yalnız hangi bacağın giriş ve çıkışta ortak olduğunu belirler.

### 5.2 Güç harcaması

Devre teorisinden hatırlanacağı gibi güç $P = VI = I^2R = V^2/R$ biçimlerinde yazılır. Transistörde harcanan güç çıkış bacağı olan kolektör üzerinden hesaplanır; base akımı güce katılmaz. Slayttaki formüller (ekrandan, 00:45:00):

- Ortak base: $P_{C\max} = V_{CB} I_C$
- Ortak emiter: $P_{C\max} = V_{CE} I_C$
- Ortak kolektör: $P_{C\max} = V_{CE} I_E$

## 6. Bilgi sayfası, bacak düzeni ve transistör testi

### 6.1 Sınır değerler ve transistörün önemi

Bilgi sayfalarında sıcaklığa bağlı değişimler ve kolektör-emiter maksimum gerilimi gibi sınır değerler verilir; transistör devreye bu karakteristik değerlere göre yerleştirilir.

Hoca transistörün elektronik devrelerde ve bilgisayar mimarisinde en çok kullanılan devre elemanı olduğunu vurguladı. İlk bilgisayarlar transistör yerine büyük tüplerle kurulmuştu; ENIAC bunun bilinen örneğidir. Tüplerden transistöre geçiş bilgisayar sistemlerinin hızla gelişmesini sağladı. Bugün merkezi işlem biriminin içinde tamamen transistörlü kapı yapıları vardır: transistörler mantık kapılarını, mantık kapıları da bilgisayar mimarisini oluşturur.

> **Ders sonrası not:** Hoca ENIAC'ı "tüp diyot tabanlı" diye andı. ENIAC büyük olasılıkla on yedi binden fazla vakum tüpü (çoğu triyot) kullanan bir bilgisayardı; yani "diyot tabanlı" demek yerine "vakum tüpü tabanlı" demek daha doğrudur.

Transistörün en çok kullanıldığı işlevlerden biri anahtarlamadır. Kolektöre bir gerilim bağlanır; akımın kolektörden aşağı (emitere) akmasını kontrol eden nokta base-emiter ekleminin doğru polarmasıdır. Base-emiter doğru polarlanmazsa akım akmaz ve transistör kesimde kalır.

> **Ders sonrası not:** Hoca bir yerde emiteri "transistörü kontrol etmemizi sağlayan bacak" diye andı. Doğrusu kontrol bacağı base'tir: küçük base akımı (ya da base-emiter gerilimi) büyük kolektör akımını kontrol eder.

### 6.2 Bilgi sayfası örneği: 2N4123

Slayttaki bilgi sayfası (ekrandan, 00:50:00) genel amaçlı NPN silisyum transistör 2N4123'e aittir (kılıf TO-92):

| Sınır değer | Sembol | Değer |
|---|---|---|
| Kolektör-emiter gerilimi | $V_{CEO}$ | 30 V |
| Kolektör-base gerilimi | $V_{CBO}$ | 40 V |
| Emiter-base gerilimi | $V_{EBO}$ | 5,0 V |
| Sürekli kolektör akımı | $I_C$ | 200 mA |
| Toplam güç harcaması (25 °C) | $P_D$ | 625 mW (25 °C üstünde 5,0 mW/°C azaltılır) |
| Çalışma ve saklama sıcaklığı | $T_J, T_{stg}$ | −55 ile +150 °C |
| Isıl direnç, eklem-kılıf | $R_{\theta JC}$ | 83,3 °C/W |
| Isıl direnç, eklem-ortam | $R_{\theta JA}$ | 200 °C/W |

Bacak düzeni bu slaytta 1 emiter, 2 base, 3 kolektördür. Hoca bacakların gerçekte 1-2-3 diye numaralandığını, düz yüzey (sırt) tarafından bakılarak sayıldığını anlattı. Önce düzenin slaytta yanlış yazılmış olabileceğini düşündü, sonra bu transistörde emiterin sol bacak olarak verildiğini kabul etti. Hoca kolektör-base arasında 40 V'u, emiter-base arasında 5 V'u aşınca bozulma (breakdown) olacağını belirtti.

> **Ek bilgi (derste anlatılmadı):** Bacak sırası kılıfa ve üreticiye göre değişir; aynı TO-92 kılıfında farklı transistörlerin E-B-C sırası farklı olabilir. Bu yüzden bacak düzeni her zaman o transistörün bilgi sayfasından kontrol edilmelidir.

Hoca bilgi sayfalarında ayrıca küçük işaret karakteristikleri ve bozulma (breakdown) gerilimleri gibi bilgilerin bulunduğunu söyledi; bu slaytlar ekrana gelmedi. <!-- BELİRSİZ: Bu kısımdaki slaytlar ekranda görüntülenemedi (00:50:21-00:51:01). -->

### 6.3 Transistörün bozuk olup olmadığının testi

Transistör, ohmmetre (direnç ölçümü) ile kontrol edilir. Örnekteki NPN transistörde:

- Ölçü aletinin artı ucu base'e, eksi ucu emitere bağlanır. Base-emiter arasındaki p-n yapısı doğru polarlandığı için çok küçük bir direnç görülmelidir.
- Artı ucu kolektöre, eksi ucu base'e bağlanır. Base-kolektör eklemi ters yönde beslendiği için çok yüksek bir direnç görülmelidir.

Bu iki sonuç alınamazsa transistör bozuktur. Hoca bunun projelerde işe yarayacağını belirtti. Ayrıca foto sensörü olarak kullanılan fototransistör gibi farklı transistör türlerinin de olduğunu söyledi.

## 7. Kutuplama ve çalışma noktası

### 7.1 Kutuplama

Slayttaki tanım (ekrandan, 00:55:00): kutuplama (biasing), transistörü açmak ve AC işareti yükseltebilmesini sağlamak için ona uygulanan DC gerilimlerdir.

Hoca şu ayrımın akılda tutulmasını istedi: transistörün polarmasını DC gerilimler sağlar, ama transistör AC işaretler üzerinde işlem yapar (işareti yükseltir ya da azaltır). Transistörün çalışma noktası belirlenirken base-emiter ve kolektör-emiter tamamen DC gerilimlerle kutuplanır. Sorularda kullanılacak kısım bu DC kontrol mimarisidir.

> **Hocanın vurgusu:** Transistör AC işaret üzerinde işlem yapsa da onu aktif bölgeye sokan gerilimler DC'dir; transistör DC kontrol ile kontrol edilen bir elemandır.

### 7.2 Çalışma noktası (Q-point)

DC giriş, çalışma noktasını (quiescent point, Q-point) belirler (ekrandan, 01:00:00). Q-noktası, transistörün karakteristik eğrisi üzerinde nerede doğru polarmalı biçimde çalışabileceğini söyleyen noktadır. Slayttaki grafikte çalışma alanının sınırları şunlardır:

- $V_{CE\max}$: örnekte 20 V. Bilgi sayfasına göre bu değerin üstünde transistör bozulur.
- Kesim (cutoff): base akımının ya da kolektör akımının olmadığı alt bölge; çalışma alanına girmez.
- $P_{C\max}$ eğrisi: $I_B$ arttıkça $I_C$ de artar; güç $P = I_C V_{CE}$ olduğundan yüksek akımlarda daha küçük $V_{CE}$'de güç sınırına ulaşılır ve bunun ötesi transistörü bozar.
- $I_{C\max}$: örnekte yaklaşık 25 mA.
- Doyum (saturation): sol kenardaki $V_{CE\,sat}$ bölgesi.

Bu eğri bilgi sayfasındaki karakteristiklere göre çıkarılır. Önemli olan, transistöre gönderilen değerlerin bu bölge içinde kalması gerektiğini bilmektir. Hoca slayttaki C noktasını örnek olarak okudu: $I_B$ = 10 µA, $V_{CE}$ yaklaşık 3 V ve $I_C$ yaklaşık 4 mA olan bu nokta transistörü çalıştırabilecek bir çalışma noktasıdır.

### 7.3 Çalışma bölgeleri

Transistörün üç çalışma durumu vardır:

- Aktif bölge: base-emiter doğru, base-kolektör ters polarlıdır. Yükselteç olarak çalışılan bölge budur.
- Kesim bölgesi: base-emiter eklemi ters bağlanır, fakirleşmiş bölge genişler ve akım akmaz (grafiğin alt bölgesi).
- Doyum bölgesi: base-emiter yine doğru polarlıdır, ama base-kolektör ters polarlanması gerekirken doğru polarlanmıştır; bu durumda kolektör tarafındaki fakirleşmiş bölge de daralır (grafiğin sol kenarı).

Hoca doyumu, NPN transistörde kolektör-emiter arasına negatif gerilim verilmesi senaryosuyla anlattı ve bu bölgenin çalışma bölgesi dışında, istenmeyen bir durum olduğunu söyledi.

> **Ders sonrası not:** Doyumu tanımlayan şey base-kolektör ekleminin de doğru polarlanmasıdır; bunun için $V_{CE}$'nin negatif olması gerekmez. Doyumda $V_{CE}$ büyük olasılıkla küçük pozitif bir değerdedir ($V_{CE\,sat}$ ≈ 0,1–0,3 V). Doyum yükselteç için istenmez, ama anahtarlama devrelerinde "açık" durum olarak kullanılır.

## 8. Kutuplama devrelerinin analizi

Hoca birçok farklı kutuplama konfigürasyonu çıkarılabileceğini, önemli olanın mantığı oturtmak olduğunu söyledi. Her analizde devre iki çevreye ayrılır: önce base-emiter çevresinden $I_B$, sonra kolektör-emiter çevresinden $V_{CE}$ bulunur.

### 8.1 Sabit kutuplama: base-emiter çevresi

Devrede $V_{CC}$ kaynağı hem $R_B$ üzerinden base'e hem $R_C$ üzerinden kolektöre bağlıdır, emiter toprağa (eksiye) bağlıdır. Emiter eksi uçta, base'e artı geldiği için $V_{BE}$ doğru polarlanır ve transistör iletime geçer.

Önce yalnız base tarafı analiz edilir (kolektör kolu koparılmış gibi düşünülür). KVL'ye göre bir çevredeki bütün elemanların gerilimleri toplamı sıfırdır (enerjinin korunumu). Akımın dirence girdiği uç artı, çıktığı uç eksi işaretlenir; direnç enerji harcayan bir eleman olduğu için kaynağa ters yönde gerilim düşürür. Base-emiter arasında da diyot yapısından gelen 0,7 V'luk iç gerilim vardır. Slayttaki KVL (ekrandan, 01:05:00):

$$+V_{CC} - I_B R_B - V_{BE} = 0 \quad\Rightarrow\quad I_B = \frac{V_{CC} - V_{BE}}{R_B}$$

$R_B$ biliniyorsa ve $V_{BE}$ silisyum için 0,7 V alınırsa $I_B$ doğrudan bulunur.

> **Hocanın vurgusu:** Bunlar transistörler için kritik noktalardır; KVL'yi doğru işaretlerle yazabilmek gerekir.

### 8.2 Sabit kutuplama: kolektör-emiter çevresi

Sağ tarafta $V_{CC}$, $R_C$ ve kolektör-emiter arasından geçen bir çevre vardır. Kolektör-emiter arası NPN'de ters (doğru polar olmayan) yönde olduğu için artı-eksi işaretlenir:

$$V_{CC} - I_C R_C - V_{CE} = 0 \quad\Rightarrow\quad V_{CE} = V_{CC} - I_C R_C$$

Soruda beta verildiyse ve önceki adımda $I_B$ bulunduysa $I_C = \beta I_B$ hesaplanır, sonra $V_{CC}$'den $I_C R_C$ çıkarılarak $V_{CE}$ bulunur. <!-- BELİRSİZ: Bu çevrenin slaytı karede yok; denklem altyazıdan ve hocanın anlatımından kuruldu (01:05:14-01:06:36). -->

Doyum: transistörün doyuma girdiği noktadaki kolektör akımı $I_{C\,sat}$, kolektör-emiter gerilimi sıfır kabul edilerek bulunur; sabit kutuplamada $V_{CC}$, kolektör direncine bölünür: $I_{C\,sat} = V_{CC}/R_C$.

### 8.3 Emiter dirençli kutuplama

Önceki devreden farkı emiter bacağının doğrudan toprağa değil, bir $R_E$ direnci üzerinden bağlanmasıdır. Analiz aynıdır. Slayttaki KVL (ekrandan, 01:10:00):

$$+V_{CC} - I_B R_B - V_{BE} - I_E R_E = 0$$

Slaytta ilk terim yanlışlıkla $I_E R_E$ gibi yazılmıştı; hoca bunun $I_B R_B$ olması gerektiğini söyleyip kalemle düzeltti. Değişkeni tek bir akıma indirmek için $I_E$ yerine $(\beta+1)I_B$ yazılır. Bu bağıntı şöyle gelir: $I_E = I_C + I_B$ ve $\beta = I_C/I_B$ olduğundan $I_C = \beta I_B$, dolayısıyla $I_E = \beta I_B + I_B = (\beta+1) I_B$.

$$V_{CC} - I_B R_B - V_{BE} - (\beta+1) I_B R_E = 0$$

Slaytın sonraki satırında $V_{BE}$ yazılmamıştı (ideal kabul edilip silinmiş); hoca $V_{BE}$'nin denklemde kalması gerektiğini söyleyip ekledi. $I_B$ çekilince:

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + (\beta+1) R_E}$$

Burada $V_{CC}$ besleme gerilimi, $R_B$ ve $R_E$ direnç değerleri, beta da soruda verilir. $V_{BE}$ ise malzemeye göre silisyumda 0,7 V, germanyumda 0,3 V, galyum arsenitte 1,2 V'tur.

Kolektör-emiter çevresi: $I_B$ bulunduktan sonra $I_C = \beta I_B$ çıkarılır ve

$$V_{CE} = V_{CC} - I_C R_C - I_E R_E$$

ile kolektör-emiter gerilimi bulunur. Slaytta çevre ters yönde yazılmıştı ($I_C R_C + I_E R_E + V_{CE} - V_{CC} = 0$); sonuç aynıdır. $I_E \approx I_C$ kabul edilebilir, ya da $I_B$ bulunduysa akımlar onun cinsinden yazılabilir.

Düğüm gerilimleri de bulunabilir:

- Emiter gerilimi: $V_E = I_E R_E$ (emiter ile toprak arasındaki potansiyel fark).
- Kolektör gerilimi: $V_C = V_{CE} + V_E$, ya da $V_C = V_{CC} - I_C R_C$.
- Base gerilimi: $V_B = V_E + V_{BE}$ (yani $V_E + 0{,}7$ V), ya da $V_B = V_{CC} - I_B R_B$.

Doyum akımı: kolektör-emiter arasındaki potansiyel fark sıfır alınırsa $I_{C\,sat} = \dfrac{V_{CC}}{R_C + R_E}$ olur. <!-- BELİRSİZ: Bu kısımdaki ilk cümle ("VCC, CE max'ı geçiyorsa...") altyazıda bozuk (01:13:03-01:13:24). -->

### 8.4 Gerilim bölücülü kutuplama

Base tarafında iki direnç ($R_1$ ve $R_2$) olması, $V_{CC}$'nin bir gerilim bölücüyle bölündüğünü gösterir. Slayttaki yaklaşık analiz (ekrandan, 01:15:00) şu şartlar altında geçerlidir: $I_B \ll I_1$ ve $I_1 \cong I_2$, ayrıca $\beta R_E > 10 R_2$.

- Base gerilimi $R_2$ üzerindeki gerilimdir:
  $$V_B = \frac{R_2 V_{CC}}{R_1 + R_2}$$
- Emiter gerilimi, base geriliminden malzemeden gelen $V_{BE}$ (0,7; 0,3 ya da 1,2 V) çıkarılarak bulunur: $V_E = V_B - V_{BE}$.
- Emiter akımı: $I_E = V_E / R_E$.
- Kolektör-emiter gerilimi (KVL ve $I_E \cong I_C$ ile):
  $$V_{CE} = V_{CC} - I_C R_C - I_E R_E \cong V_{CC} - I_C (R_C + R_E)$$

Hoca bu kısmın devre teorisinden bildikleri bir adım ötesi olduğunu söyledi.

### 8.5 Gerilim geri beslemeli DC kutuplama

Bu konfigürasyonda $V_{CC}$ önce $R_C$ direncinden geçer, $R_B$ ise kolektörden base'e bağlıdır; base akımı kolektör düğümünden alınır. Bu yüzden $R_C$'den geçen akım $I'_C = I_C + I_B$'dir. Base akımı için yazılan KVL çevresi $V_{CC}$, $R_C$, $R_B$, base-emiter eklemi ve $R_E$'den geçer:

$$V_{CC} - I'_C R_C - I_B R_B - V_{BE} - I_E R_E = 0$$

$I_B$, $I_C$'ye göre çok küçük olduğu için $I'_C \approx I_C$ (ve $I_E \approx I_C$) kabul edilebilir; ya da beta biliniyorsa $I_C$ yerine $\beta I_B$ yazılır. Denklemde $I_C$ görülen yerlere $\beta I_B$ yazılıp $I_B$ çekilince base akımı bulunur; bunun yine çok küçük bir değer çıkması gerekir. $I_B$'den $I_C$ ve $I_E$ elde edilir. <!-- BELİRSİZ: Bu slaytın karesi yok; denklem altyazıdan kuruldu (01:17:10-01:18:17). -->

> **Ek bilgi (derste anlatılmadı):** $I'_C \approx I_C \approx I_E \approx \beta I_B$ kabulüyle denklem $V_{CC} - \beta I_B (R_C + R_E) - I_B R_B - V_{BE} = 0$ olur ve $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + \beta (R_C + R_E)}$ elde edilir.

Kolektör-emiter çevresi için: $V_{CC} - I'_C R_C - V_{CE} - I_E R_E = 0$; burada da $I_B$ çok küçük kabul edilerek $V_{CE}$ çekilir. Hoca slayttaki bu çevrede bir terimin unutulduğunu belirtti.

## 9. Transistörlü anahtarlama devresi

Slaytta yalnız DC kaynak uygulanan transistörlerin elektronik anahtar olarak kullanılabileceği yazılıdır (ekrandan, 01:20:00). Örnek devrede girişe 0 V ile 5 V arasında değişen bir kare dalga uygulanır; $V_{CC}$ = 5 V, $R_C$ = 0,82 kΩ, $R_B$ = 68 kΩ, $h_{FE} = \beta$ = 125'tir. Çıkış ($V_C$) girişin tersidir: giriş 5 V iken çıkış 0 V, giriş 0 V iken çıkış 5 V.

Hoca girişteki 5 V'un transistörü anahtarlamak için kullanıldığını, burada amacın transistör aktifken işaret üzerinde yapacağı işlemi değil, iç yapısında aktif olabilmesi için $I_B$, $I_C$ ve $I_E$ akımlarını bulmak olduğunu söyledi. Örneğin çözümü sonraki derse kaldı (çözüm için Örnek Sorular'a bakın).

## Örnek Sorular

**Soru 1** (derste sözlü, 00:32:04): Ortak base yükselteçte girişte 200 mV'luk bir sinüs işaret ve 20 Ω'luk giriş direnci, çıkışta 5 kΩ'luk yük direnci vardır. $I_C \approx I_E$ kabulüyle yük gerilimi $V_L$ ve gerilim kazancı nedir?

> **Çözüm (derste verildi):** $I_E = 200\text{ mV}/20\ \Omega = 10$ mA. $I_C \approx I_E = 10$ mA. $V_L = 10\text{ mA} \times 5\text{ kΩ} = 50$ V. Kazanç $50/0{,}2 = 250$.

**Soru 2** (ekrandan, 00:40:00): Verilen ortak emiter kolektör karakteristiğinde $V_{CE}$ = 7,5 V için $\beta_{AC}$ ve Q-noktasındaki ($I_B$ = 25 µA, $I_C$ = 2,7 mA) $\beta_{DC}$ nedir? Grafikte $V_{CE}$ = 7,5 V'ta $I_B$ = 30 µA için $I_C$ = 3,2 mA, $I_B$ = 20 µA için $I_C$ = 2,2 mA okunur.

> **Çözüm (derste verildi):** $\beta_{AC} = (3{,}2 - 2{,}2)\text{ mA} / (30 - 20)\text{ µA} = 1\text{ mA}/10\text{ µA} = 100$. $\beta_{DC} = 2{,}7\text{ mA}/25\text{ µA} = 108$.

**Soru 3** (ekrandan, 01:00:00): Çalışma noktası grafiğinde C noktası transistörün çalışabileceği bir nokta mıdır, değerleri nedir?

> **Çözüm (derste verildi):** C noktası aktif bölge içindedir; $I_B$ = 10 µA, $V_{CE}$ yaklaşık 3 V, $I_C$ yaklaşık 4 mA'dir (değerler grafikten yaklaşık okunmuştur).

**Soru 4** (ekrandan, 01:20:00): Anahtarlama devresinde $V_{CC}$ = 5 V, $R_C$ = 0,82 kΩ, $R_B$ = 68 kΩ, $h_{FE}$ = 125'tir; giriş 0 V ile 5 V arasında değişir. Giriş 5 V iken transistörün durumu nedir?

> **Çözüm (derste verilmedi):** Giriş 5 V iken $I_B = (5 - 0{,}7)\text{ V}/68\text{ kΩ} \approx 63{,}2$ µA. Doyum akımı $I_{C\,sat} = V_{CC}/R_C = 5\text{ V}/0{,}82\text{ kΩ} \approx 6{,}10$ mA. Aktif bölge kabul edilse $\beta I_B = 125 \times 63{,}2\text{ µA} \approx 7{,}90$ mA olurdu; bu değer $I_{C\,sat}$'tan büyük olduğu için transistör doyumdadır, $I_C \approx 6{,}1$ mA ve $V_C \approx 0$ V'tur. Giriş 0 V iken $I_B = 0$, transistör kesimdedir, $I_C = 0$ ve $V_C = V_{CC} = 5$ V'tur. (Değerler python ile hesaplandı.)

## Dersin Toparlaması

Bu derste bipolar transistörün üç konfigürasyonu (ortak base, ortak emiter, ortak kolektör), bunların giriş ve çıkış karakteristikleri, alfa ve beta parametreleri ve aralarındaki bağıntılar, konfigürasyonlara göre güç harcaması, bilgi sayfası okuma ve ohmmetre ile transistör testi işlendi. Ardından kutuplamanın DC olduğu, çalışma noktasının karakteristik üzerindeki sınırları ve aktif, kesim, doyum bölgeleri anlatıldı; sabit kutuplama, emiter dirençli kutuplama, gerilim bölücülü kutuplama ve gerilim geri beslemeli kutuplama devrelerinin KVL ile analizi gösterildi.

Hoca, transistör sorularında en önemli becerinin devre ne kadar karışık olursa olsun KVL denklemini yazabilmek olduğunu; $I_E = I_C + I_B$ kuralını ve base akımının çok küçük olduğunu bilmenin yeterli olacağını vurguladı. Anahtarlama devresi örneği ve transistörle ilgili soru çözümleri sonraki derse bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
