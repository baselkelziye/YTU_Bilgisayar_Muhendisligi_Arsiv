# Ders 13 Genişletilmiş Notu: Pekiştirmeli Öğrenme, RLHF ve Yapay Zekanın Etik/Hukuk İlişkileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Pekiştirmeli Öğrenmeye Giriş
- 2. Temel Kavramlar
- 3. Q-Öğrenme: 9 Durumlu Araba Örneği
- 4. Keşfetmek / Kullanmak İkilemi
- 5. Q-Öğrenme Algoritması ve Örnek Güncellemeler
- 6. Labirent ve Adım Cezası
- 7. Yeni Durumlar ve Derin Q-Ağı
- 8. Diğer Kavramlar: Çok Ajanlı Yapılar, İnsan Taklidi, Ters Pekiştirmeli Öğrenme
- 9. İnsan Geri Bildirimiyle Pekiştirmeli Öğrenme (RLHF)
- 10. Tartışma 2023: Bu Modeller Zeki mi?
- 11. Yapay Zekanın Etik ve Hukuk İlişkileri
- Örnek Sorular

## 1. Pekiştirmeli Öğrenmeye Giriş

Makine öğrenmesi konusunun son bölümü pekiştirmeli öğrenmedir (reinforcement learning). Türkçede "destekleyici" ya da "takviyeli öğrenme" diye de çevrilir (ekrandan, 00:20:00). Bu da denetimli (supervised) bir yaklaşım sayılabilir: başka birinin (bir insanın, başka bir modelin ya da ortamın) emeğiyle, olması gerekene dair bir bilgi sisteme geri bildirim olarak verilir. Ancak bu bilgi doğru cevabın kendisi değildir.

Temel fikir **ödül ve ceza ile eğitim**dir. Sistem bir şey yaptığında, yaptığının doğru ya da yanlış olduğu, hatta ne kadar doğru ya da ne kadar yanlış olduğu söylenir ("süper yaptın", "az yanlış yaptın" gibi dereceler olabilir). Sisteme bir durumda ne yapması gerektiği **açıkça söylenmez**; yalnız ödül ya da ceza verilir. Slayttaki maddeler şöyledir (ekrandan, 00:20:00):

- Ödül/ceza ile eğitim.
- Ödül genelde uzaktadır.
- Hangi durumda ($S$) hangi hareketin ($A$) yapılacağı öğrenilir.
- Ne yapması gerektiğini söylemeyiz, yalnız ödül/ceza veririz.
- Ajan toplam ödülü en büyük yapmaya çalışır.
- Ajanın hareketleri hangi verilere erişeceğini belirler.

### 1.1 Problem yapısı

Bu yöntem, ajanın içinin nasıl olduğunu bilmediği bir ortamda mantıklı ve rasyonel hareket etmesinin beklendiği problemlerde kullanılır. Ajan bir başlangıç durumundan başlar; ortam ve ajanın kendi hareketlerine göre değişen bir süreçten sonra süreç biter. Bu sürece **bölüm (epizod)** denir. Bölüm boyunca ajan ortamda hareket eder ve ortamdan ödül ya da ceza biçiminde geri bildirim alır. İstenen, ajanın bu bölüm boyunca **en çok ödülü toplayacak bir hareket dizisi** üretmesidir.

Ortam dışarıdan açıkça verilmiş olabilir, ama ajanın kafasında daha soyut bir dünya modeli olarak da oluşturulabilir. Derste önce en basit durum, durumların belli olduğu ayrık (discrete) bir uzay ele alındı ve bu uzayda en temel pekiştirmeli öğrenme algoritmalarından biri olan Q-öğrenme anlatıldı.

### 1.2 Ajan-ortam döngüsü

Slayttaki şema (ekrandan, 00:20:00) bütün olayı özetler:

```text
Agent  --(action A_t)-->  Environment
Environment --(state S_{t+1}, reward R_{t+1})--> Agent
(Ajan bir sonraki adımda S_t ve R_t olarak bunları algılar.)
```

Ajan iki şey yapabilir: hareket eder ve ortamı algılar. Algılama iç ya da dış sensörlerle olabilir; ödül ve ceza da sensörlerden gelen bir bilgi gibi düşünülebilir. Ajan algılar, hareket eder, yeniden algılar, yeniden hareket eder ve böylece bir hareketler dizisi oluşturur.

Ödül sayısal bir değerdir; belli bir aralıkta sürekli ya da ayrık olabilir ve probleme göre değişir. Örneğin bir hareketin ödülü 0, başka birinin 10 olabilir; 0 ödül almak pek de iyi bir şey değildir. Kötü bir harekete $-10$ verilebilir. Bunların hepsi "ödül" başlığı altında, artı ve eksi değerlerle ifade edilir.

### 1.3 Neden oyunlarda iyi çalışır?

Olası tüm durumların erişilebilir olduğu simülasyon dünyalarında, en başta oyunlarda, pekiştirmeli öğrenme çok iyi çalışır. Bunun temel sebebi **ölçeklenebilirlik**tir: ödülü oyunun kendisi üretir. Bir insanın "bu durumda şunu yapman lazım" demesine gerek yoktur. Oyun geri bildirimi kolayca verdiği için eğitim, hiçbir insan müdahalesi olmadan çok uzun süre yürütülebilir.

## 2. Temel Kavramlar

Slayttaki temel kavramlar şunlardır (ekrandan, 00:25:00):

- **Environment / ortam:** ajanın içinde bulunduğu ortam.
- **State / durum:** mevcut durum. Ayrık bir uzayda bir indis olabilir; sürekli bir yapıya geçildiğinde farklı veri yapıları tutabilir.
- **Reward / ödül:** ortamdan gelen geri besleme. Adı "ödül" olsa da yalnız pozitif değildir; bir geri bildirim olarak düşünülmelidir.
- **Policy / politika:** ajanın durumlarını hareketlerine eşleyen tablo. Politikanın anlamı "hangi durumda ne yapayım?" sorusunun cevabıdır.
- **Value / gelecek ödül:** bir durumda bir hareket yapılınca alınacak gelecekteki ödül. O anda alınan ödül değil, ileride alınacak ödüldür.

Hoca politikanın illa tablo olması gerekmediğini vurguladı. Ayrık uzaylar için tablo kullanılır; ama eşleme işi bir vektörü başka bir vektöre eşleyen herhangi bir fonksiyonla, genellikle doğrusal olmayan fonksiyonlarla, yani yapay sinir ağlarıyla da yapılabilir. Amaç her durumda politikayı iyileştirmektir.

## 3. Q-Öğrenme: 9 Durumlu Araba Örneği

### 3.1 Problem

Örnek dünyada 0'dan 8'e kadar dokuz durum vardır (ekrandan, 00:30:00). Ekrandaki yerleşim şöyledir:

```text
üst sıra :  5 (çukur)   1           0 (araba)
orta sıra:  6           2           4 (çukur)
alt sıra :  8 (ev)      3           7
```

- Araba 0 durumundadır, ev (hedef) 8 durumundadır.
- 4 ve 5 çukurdur.
- Her durumda uygun yönlerde en çok dört hareket yapılabilir: Up, Down, Left, Right.
- Durumlar arası geçişler bellidir. Hocanın saydığı örnekler: 1'den aşağı gidilirse 2'ye, 2'den sağa gidilirse 4'e, 0'dan sola gidilirse 1'e, 0'dan aşağı gidilirse 4'e (çukur), 1'den sola gidilirse 5'e (çukur), 2'den sola gidilirse 6'ya, 2'den aşağı gidilirse 3'e, 7'den sola gidilirse 3'e, 3'ten sola ve 6'dan aşağı gidilirse 8'e varılır.
- **Ödüller yalnız 8'e giden iki harekettedir:** 6'dan aşağı inmek ve 3'ten sola gitmek; ikisinin de ödülü 10'dur. Başka hiçbir ödül yoktur.

### 3.2 Q tablosu

Politika bir **Q tablosu** ile ifade edilir. Satırlar durumlar (9 tane), sütunlar hareketlerdir (4 tane). Başlangıçta ($t = 0$) tablonun bütün değerleri sıfırdır. Bu, her durumda her hareketin seçilme olasılığının eşit olması gibi düşünülebilir: "Bu durumdayken hangi hareketi yapmak mantıklı? Hepsi aynı."

Ajan ortamda hareket edip ödül aldıkça değerler yavaş yavaş değişir. Slaytta Q-öğrenme çalıştırıldıktan sonraki tablo da gösterilir (ekrandan, 00:30:00):

| Durum | UP | DOWN | LEFT | RIGHT |
|---|---|---|---|---|
| 0 | 0 | 0 | 0.45 | 0 |
| 1 | 0 | 1.01 | 0 | 0 |
| 2 | 0 | 2.25 | 2.25 | 0 |
| 3 | 0 | 0 | 5 | 0 |
| 4 | 0 | 0 | 0 | 0 |
| 5 | 0 | 0 | 0 | 0 |
| 6 | 0 | 5 | 0 | 0 |
| 7 | 0 | 0 | 2.25 | 0 |
| 8 | 0 | 0 | 0 | 0 |

Tablonun yorumu:

- 0 durumunda Left yapmak mantıklıdır. 0'da yalnız iki seçenek vardır: sola ya da aşağı. Aşağı gitmek çukura (4) düşürür.
- 1 durumunda Down yapmak mantıklıdır. Sıfıra geri dönmek makul değildir, 5'e gitmek de çukura düşmektir; aşağı gidince 2'ye varılır.
- 2 durumunda Down ya da Left yapmak eşit derecede mantıklıdır.
- 6 durumunda mutlaka Down, 3 durumunda mutlaka Left yapılmalıdır.
- 7 durumunda Left yapmak mantıklıdır.

Amaç, sıfırlarla dolu başlangıç tablosundan bu tabloya ulaşmaktır.

## 4. Keşfetmek / Kullanmak İkilemi

### 4.1 Q-öğrenmede bölüm

Q-öğrenmede sürekli olarak, başlangıçtan başlayıp başarısızlıkla (fail) ya da hedefle biten hareket dizileri üretilir. Buna bölüm (epizod) denir. Başarısızlık bir oyunda düşmek ya da ölmek, ya da en uzun sürenin dolması olabilir. Politika, bulunulan durumda yapılacak hareketi Q tablosuna göre seçer. Örneğin eğitimin ortasında 3 durumuna gelinmişse, 3 satırındaki değerlere bakılır ve bunlardan biri seçilir.

Ajan iyi bir politikayı deneme-yanılmayla arar: genelde bütün hareketlerin eşit seçilme şansına sahip olduğu bir politikayla başlar ve onu iyileştirir. Bu iyileştirmede pekiştirmeli öğrenmenin temel ikilemi ortaya çıkar: **keşfetmek / kullanmak (exploration vs. exploitation)**.

### 4.2 İkilemin anlamı

- **Kullanmak (exploitation):** O an en faydalı görünen hareketi yapmak. Örneğin 3 durumunda Left'in değeri 5 ve diğerleri 0 ise Left'i seçmek. Bu, hedefe daha az maliyetle ve daha çok puanla ulaşmayı amaçlar; bir tür "en iyi önce" seçimidir.
- **Keşfetmek (exploration):** O an en iyi olmayan bir hareketi denemek. Bu, ortamda yeni ve belki daha iyi durumlara ulaşmayı sağlar. Gerçek oyunlarda çok fazla durum vardır; bulunan bir yoldan daha iyisini bulmak için o yolu izlemekten vazgeçmek gerekir. O an iyi görünen hareket uzun vadede o kadar iyi olmayabilir; bunu yalnız onu izleyerek fark edemezsiniz.

### 4.3 Günlük hayat örnekleri

Slayttaki örnekler (ekrandan, 00:35:00):

- **Acıktınız:** yeni bir yeri denemek (keşfetmek) ya da iyi bildiğiniz bir yere gitmek (kullanmak). Bilinen yerin avantajı risk olmaması, ne kadar memnun kalacağınızı bilmenizdir; dezavantajı daha iyi bir yeri hiç görememenizdir. Yeni bir yerin dezavantajı kötü çıkabilmesi, avantajı daha iyi bir yer bulma şansıdır.
- **Petrol arıyorsunuz:** daha önce petrol çıkmış bölgede çalışmak kullanmak, yeni bir bölgede çalışmak keşfetmektir.
- **Benzetimli tavlamayı hatırlayın:** rastgele bir hareket seçilir; iyiyse uygulanır, değilse azalan bir olasılıkla uygulanır. Başta kötü görünen hareketleri kabul etme olasılığı yüksektir, sistem bir yere yakınsasın diye zamanla azaltılır. Q-öğrenmede de süreç benzerdir.

## 5. Q-Öğrenme Algoritması ve Örnek Güncellemeler

### 5.1 Algoritmanın adımları

Hocanın anlattığı akış şöyledir:

```text
Her bölüm için tekrarla:
    s <- başlangıç durumu (S0)
    Bölüm sonu olmadığı sürece:
        Politikaya (Q tablosunun s satırına) göre bir a hareketi seç
            (burada keşfet / kullan ikilemi devreye girer)
        a hareketini yap
        Ödülü R ve sonraki durumu s' belirle
        Q[s,a] <- Q[s,a] + alfa * (R + gama * max_a' Q[s',a'] - Q[s,a])
        s <- s'
```

Sonraki durumu bir geçiş (transition) matrisi, ödülü bir ödül matrisi belirleyebilir; bir oyunun içindeyseniz bunlar farklı yapılarda olabilir. Temel mantık aynıdır: hareketi yap, ödülü ve sonraki durumu gör, sonra $s$ durumunda $a$ hareketini yapmanın değerini güncelle.

### 5.2 Güncelleme kuralının anlamı

Güncelleme formülü (ekrandan, 00:40:00):

$$Q[s,a] = Q[s,a] + \alpha \left(R + \gamma \max_{a'} Q[s',a'] - Q[s,a]\right)$$

- $\alpha$ bir katsayıdır (öğrenme oranı). Eklenen değer her zaman pozitif olmak zorunda değildir.
- $R$, o hareketi yaptığınız için o anda aldığınız ödüldür. Örneğin 1'de sola gitmenin ödülü yoktur, 3'te sola gitmenin ödülü 10'dur.
- $\max_{a'} Q[s',a']$, varılan yeni durumda yapılabilecek hareketlerin en iyisinden elde edilebilecek değerdir, yani **gelecekteki ödül**dür. Örneğin 7'deyken 3'e gitmek o an ödül getirmez; ama 3'ten sonra alınabilecek en büyük ödül bu hareketin içine gömülür.
- Bu toplamın mevcut $Q[s,a]$'dan farkı alınır ve güncelleme yapılır.

Hareket seçiminde **epsilon-açgözlü (epsilon-greedy)** yöntem kullanılır: rastgele hareket seçme olasılığı giderek azaltılır. Başta rastgele seçim daha çok yapılır, zamanla azalır; benzetimli tavlamadaki sıcaklık gibi.

$\gamma$ yakın ödüllere mi uzak ödüllere mi odaklanılacağını belirler. Gelecek ödül $\gamma$ ile çarpılır; $\gamma = 1$ olursa gelecek ödül sürece çok katılır, $\gamma = 0$ olursa gelecek terimi yok olur ve yalnız o anki ödül hesaba girer.

> **Ek bilgi (derste anlatılmadı):** Epsilon-açgözlü seçimde $\varepsilon$ olasılıkla rastgele bir hareket, $1 - \varepsilon$ olasılıkla Q değeri en yüksek hareket seçilir. $\varepsilon$ eğitim boyunca genellikle küçültülür, böylece ajan başta çok keşfeder, sonra öğrendiğini kullanır.

### 5.3 Örnek Q güncellemeleri

Slayttaki örnekte $\alpha = 0.5$, $\gamma = 0.9$ seçilmiştir (ekrandan, 00:40:00). $\gamma = 0.9$ 1'e yakındır, yani gelecek ödüllere odaklanan bir seçimdir.

**İlk bölümler (3 durumundayım, Left seçtim):** 3'ten sola gidilince 8'e varılır. 8'de yapılabilecek hiçbir hareketin ödülü tanımlı değildir; zaten 8 oyunun sonudur.

$$Q[3,L] = Q[3,L] + 0.5\,(10 + 0.9 \cdot \max[Q(8,U), Q(8,D), Q(8,R), Q(8,L)] - Q[3,L])$$
$$Q[3,L] = 0 + 0.5\,(10 + 0.9 \cdot \max[0,0,0,0] - 0) = 5$$

Benzer olarak $Q[6,D] = 5$ olur. Burada değeri 0'dan 5'e çıkaran yalnız o anki ödüldür; gelecek ödülün hiçbir katkısı yoktur.

**Sonraki bölümler (2 durumundayım, Left seçtim):** 2'den sola gidilince 6'ya varılır. Bu hareketin o anki ödülü 0'dır; ama 6'dan aşağı inmenin değeri artık 5'tir.

$$Q[2,L] = Q[2,L] + 0.5\,(0 + 0.9 \cdot \max[Q(6,U), Q(6,D), Q(6,R), Q(6,L)] - Q[2,L])$$
$$Q[2,L] = 0 + 0.5\,(0 + 0.9 \cdot \max[0,5,0,0] - 0) = 2.25$$

Benzer olarak $Q[2,D] = 2.25$ ve $Q[7,L] = 2.25$ olur. Bu adımda değeri artıran gelecek durumun katkısıdır.

- Ders sonrası not: Sayılar python ile doğrulandı. Aynı mantıkla $Q[1,D] = 0.5 \cdot 0.9 \cdot 2.25 = 1.0125$ ve $Q[0,L] = 0.5 \cdot 0.9 \cdot 1.0125 \approx 0.456$ çıkar; slayttaki son tabloda bunlar 1.01 ve 0.45 olarak görünür. Slaytta bu tablo "$t=\infty$" diye etiketlenmiştir; güncellemeler sürdürülürse değerler büyük olasılıkla daha da artar (örneğin $Q[3,L]$ her güncellemede 10'a yaklaşır).

### 5.4 Amaç bir yol bulmak değil, politika öğrenmektir

Hoca burada bir yanlış anlamayı düzeltti: amaç tek bir başlangıçtan hedefe giden yolu bulup bitirmek değildir. Amaç, ortamın her durumunda ne yapmanın mantıklı olduğunu söyleyen bir politika üretmektir. 8'e varıldığında o bölüm biter, yeni bölüm yeniden 0'dan başlar. Örneğin bir bölümde 0'dan 1'e, 1'den 5'e (çukura) gidilir ve oyun biter; sonraki bölümde 5'e gitmek kötülendiği için belki 2 seçilir ve oradan devam edilir. Bölümler tekrarlandıkça tablo adım adım dolar.

## 6. Labirent ve Adım Cezası

Daha büyük bir örnekte bir labirent vardır (ekrandan, 00:50:00). Q-öğrenme bu labirentte çalıştırılırsa durum sayısı beyaz hücre sayısı kadar, sütun sayısı ise 4 olur. Öğrenme bitince her hücredeki ok, o durumda Q değeri en yüksek olan hareketi gösterir ("Oklar: s durumunda en iyi value (gelecek ödül)'ya sahip olan hareket"). Alttaki tabloda gelecek ödüller yer alır: bitişin yanındaki hücre $-1$'dir ve başlangıca doğru gidildikçe değerler $-2, -3, \dots$ diye azalır, en uzak hücrelerde $-23$, $-24$'e iner.

Değerlerin hep eksi olması ilk bakışta garip görünebilir. Burada ödül yalnız bitiştedir. Tek ödül bitişte olursa, başlangıçtan bitişe doğrudan giden kusursuz bir bölüm ile ileri geri dolanan bir bölüm aynı toplam ödülü alır. Yani algoritma kısa yolu öncelemez. Çözüm sınıfa soru olarak soruldu (aşağıdaki Örnek Sorular'a bakın): **her adımın ödülünü $-1$ yapmak**. Her adımda ceza alan ajan en az toplam cezayı, yani en az sayıda adımı arar; adım sayısını kendiliğinden en aza indirir.

## 7. Yeni Durumlar ve Derin Q-Ağı

### 7.1 Q tablosunun sınırları

Labirent ve basit oyunlarda Q-öğrenmeyi kullanmakta bir sıkıntı yoktur: durum sayısı baştan bilinir, geçişler bellidir, Q matrisi sabit boyutludur. Ancak:

- Ortamı keşfederek ilerlerken zaman içinde **yeni durumlar** oluşabilir. Bu, Q tablosuna yeni satırlar eklemek demektir.
- Q-öğrenme görmediği bir durumun değerini bilemez; yeni bir duruma uyum sağlaması mümkün değildir.
- Oyunlarda eğitimde görülmeyen yeni durum sayısı çok fazladır.

Video oyunlarında hareketler klavye ya da fare ile yapılabilecek sınırlı şeylerdir, ama durum belirsizdir: ekrandaki görüntüdür. Yeni bir durumu mevcut durumlardan birine benzetmek bir çözüm olabilir, ama durum bir ekranı algılamak olunca işler zorlaşır; renkli bir ekranda olası durum sayısı kestirilemez (ekrandan, 00:55:00).

### 7.2 Derin Q-ağı (deep Q-network)

Bu sorun için DeepMind'ın Nature'da yayımlanan bir çalışması anlatıldı (slaytta nature14236 kaynağı). Slayttaki fikir: "Resmi (durumu) CNN'lerle işle, Q(s,a)'ları / hareketi belirle" (ekrandan, 00:55:00).

- Giriş, o anki durumu gösteren ekran görüntüsüdür.
- Görüntü evrişim (convolution) katmanlarından ve tam bağlı (fully connected) katmanlardan geçer.
- Çıkışta her hareket bir sınıf gibi düşünülür. Örnekteki kontrol mekanizmasında sekiz yön ve bir düğme vardır; sekiz yönün düğmeye basarak ya da basmadan yapılması gibi hareketler ayrı sınıflardır. Başka kontrol mekanizmaları için sınıflar değiştirilir.

Olay bir Q tablosu öğrenmek değil, **Q tablosunun yaptığı işi yapmaktır**: belli bir durumda hangi hareketin yapılacağını seçmek. Bu bilgi dışarıdan bakılıp görülebilecek bir tablo değil, bir ağın içinde tutulur. Yöntem oyunlarda çok iyi çalıştı; çünkü yine insan emeği olmadan çok uzun süre eğitim mümkündür. Oyunların büyük kısmında, belli bir eğitimden sonra insan oyuncular kadar başarılı oynayan modeller üretildi ve bu, "yapay sinir ağları oyun oynayabiliyor" diye büyük yankı buldu.

## 8. Diğer Kavramlar: Çok Ajanlı Yapılar, İnsan Taklidi, Ters Pekiştirmeli Öğrenme

Slayttaki "Dahası var" listesi (ekrandan, 01:15:00):

- Multi agent collaboration / competitive.
- Human imitation (sparse reward games).
- Inverse RL (pseudo rewards).
- Policy gradient methods (PPO vb.).
- Bir oyun olarak diyalog: RLHF.

### 8.1 Çok ajanlı yapılar

Bir ortamda tek ajan değil birden fazla ajan bulunabilir. Bunların birlikte iş yapması ya da birbiriyle yarışması gibi durumlarda da pekiştirmeli öğrenme başarıyla uygulanabilir; çok ajanlı yapılar da bu yöntemle eğitilebilir.

### 8.2 Seyrek ödül problemi ve insan taklidi

**Seyrek ödül (sparse reward)**, ödüllerin seyrek olması demektir. Ödül belki ancak arka arkaya 10, hatta 100 doğru adım atıldığında karşınıza çıkar. Boş bir tabloyla başlayıp rastgele seçimlerle ilerlersek, herhangi bir ödülle karşılaşmadığımız sürece hiçbir güncelleme gerçekleşmez: güncelleme formülündeki $R$ ve $\max Q[s',\cdot]$ ikisi de sıfırdır. Her adımda 4 seçenek varsa ve 100 doğru hamle gerekiyorsa, rastgele ulaşma şansı $1/4^{100}$ gibi çok küçük bir sayıdır (python ile yaklaşık $6 \times 10^{-61}$). Hoca bunu, gradyanla hatayı azaltmaya çalışırken her yönün dümdüz olduğu bir yerde bulunmaya benzetti: hangi yöne gideceğinizi kestiremezsiniz.

**İnsan taklidi (human imitation)** bu soruna bir yaklaşımdır: oyun ya da ortam ödül vermiyorsa insanlar o ortamda oynatılır. Bir durumda insanın olası hareketlerden hangisini yaptığı bilgisi bir **yardımcı ödül** gibi kullanılır. Böylece ajan seyrek yapıdan bir miktar daha iyi bir hale getirilir.

### 8.3 Ters pekiştirmeli öğrenme ve sahte ödüller

Ajan insanlardan öğrendikten sonra yeni bir ortama girdiğinde yine ödül bekler, ama oyun ödül vermez. Bu durumda "şu durumda insan şunu yaptı" örneklerinden oluşan bir eğitim kümesiyle, yeni bir durumda insanın ne yapacağını tahmin eden **harici bir model** eğitilebilir. Ortamda gerçekte öyle bir ödül yoktur, ama harici model ödül varmış gibi davranmayı sağlar. Buna **sahte ödül (pseudo reward)** denir. Hoca bu fikrin birazdan anlatılacak RLHF'ye zemin oluşturduğunu vurguladı.

### 8.4 Daha yeni algoritmalar

Q-öğrenmeden sonra birçok yapı geliştirilmiştir: Double Q-ağları, aktör-kritik (actor-critic) yapılar vb. En yaygın kullanılanlardan biri OpenAI'ın PPO algoritmasıdır. OpenAI'ın pekiştirmeli öğrenme altyapısı robot el çalışmaları ve Dota video oyununda dünya şampiyonu ekibi yenme çalışmaları gibi projelerle güçlendi; bu birikim bugünkü ChatGPT gibi teknolojilere zemin oldu.

> **Ek bilgi (derste anlatılmadı):** PPO (Proximal Policy Optimization), politika gradyanı ailesinden bir yöntemdir. Politikayı doğrudan parametreli bir fonksiyon olarak günceller ve her adımda politikanın eskisinden çok uzaklaşmasını sınırlayarak eğitimi kararlı hale getirir.

## 9. İnsan Geri Bildirimiyle Pekiştirmeli Öğrenme (RLHF)

### 9.1 Diyalog bir oyundur

Hoca, bir dil bilimciden (Wittgenstein) aktarılan bir fikirle başladı: diyalog iki kişi arasında oynanan bir oyundur. Oyunlar pekiştirmeli öğrenmeyle eğitilebiliyorsa diyaloglar da eğitilebilir.

Slayttaki şekil OpenAI'ın blogundan alınmıştır (ekrandan, 01:20:00). Hoca bunun ChatGPT'nin kesin yapısı olmadığını vurguladı: ChatGPT'nin iç yapısına dair teknik bir makale yoktur. Ancak önceki model olan InstructGPT'nin teknik makalesi vardır ve orada bu yaklaşımın kullanıldığı bilinir; blog yazılarında da ChatGPT için bu yöntemin kullanıldığı söylenir. ChatGPT'yi taklit etmeye çalışan yaklaşımlar da temelde bunu kullanır. InstructGPT tek adımlı bir işti (kullanıcı bir şey söyler, model cevap verir) ve diyalog tabanlı olmadığı, doğrudan kullanıcıya açılmadığı için çok etki yaratmadı; ChatGPT diyalog tabanlıdır ve başarısı yüksek olduğu için genel kullanıma açıldı.

### 9.2 Ön hazırlık: büyük dil modeli ve öz-denetimli öğrenme

Dil modeli kabaca **bir sonraki token'ı tahmin etmek üzere eğitilmiş bir yapay sinir ağıdır**. Bir cümle verirsiniz, sonraki kelimenin ne olacağını sorarsınız; doğru cevap verirse iyi, yanlışsa model güncellenir. Burada pekiştirmeli öğrenme yoktur, **öz-denetimli (self-supervised)** bir yaklaşım vardır.

Öz-denetimlinin anlamı şudur. Kedi ve köpek resimlerini sınıflandırmak için bir insanın her resme bakıp etiket yazması gerekir. Oysa sonraki kelimeyi tahmin etmek için eğitim kümesi kurarken insana gerek yoktur. "Ali bugün okula giderken yolda eski arkadaşını gördü" gibi bir cümleden "Ali bugün okula giderken" girdisi ve "yolda" çıktısı, "Ali bugün okula giderken yolda" girdisi ve "eski" çıktısı gibi çiftler basit bir kodla üretilir. Token bir kelime, alt kelime ya da karakter olabilir; hepsi "sonraki token tahmini"dir. Çıktının ne olması gerektiği yine modele söylenir (bu yüzden "denetimli"dir), ama etiketli veriyi algoritma kendisi oluşturur. İnternetteki bütün dijital metinler bu yolla eğitim kümesine dönüşebilir.

İnsan emeği pahalı ve ölçeklenemezdir. Hoca bunu ilk dönem arama motorlarıyla örnekledi: web siteleri önceden editörler tarafından elle kategorilere ayrılıyordu; Google'ın algoritmaları bu işi insan emeğinden bağımsız ve ölçeklenebilir hale getirdi. Aynı fikir resimlerde (resmin bir parçasını kapatıp tahmin etmek), videoda (sonraki kareyi tahmin etmek, next frame prediction) ve metinde (bir kelimeyi kapatıp bulmak) kullanılır; böylece çok büyük verilerle çalışılabilir.

### 9.3 Adım 1: Gösterim verisi ve denetimli ince ayar

Elde, bir sonraki kelimeyi tahmin edebilen bir model vardır (hoca GPT-3 için 175 milyar parametreden söz etti). Bu model bir şey söylendiğinde devamını getirebilir. Ama istenen, soruya ya da talebe cevap veren bir modeldir; bu ikisinin eğitim süreci farklıdır.

GPT-3 ticari kullanıma açıldığında kullanıcılar, modelden istedikleri cevabı alabilmek için çeşitli girdiler denediler. Slayttaki tanım: "Prompt dataset: GPT-3 kullanıcılarının modele istedikleri çıkışı verdirmek için denedikleri prompt'lar" (ekrandan, 01:20:00).

Slayttaki Adım 1 (ekrandan, 01:20:00):

- Prompt veri kümesinden bir prompt örneklenir (slayttaki örnek: "Explain reinforcement learning to a 6 year old").
- Bir insan etiketleyici istenen çıktıyı yazar.
- Bu veri GPT-3.5'i denetimli öğrenmeyle ince ayarlamak (SFT) için kullanılır.

Burada da eğitim token tahmini ile yapılır, ama girdi ve çıktının ne olması gerektiği doğrudan bellidir: "böyle bir şey denirse böyle cevap ver." İnsan etiketlemesi vardır.

### 9.4 Adım 2: Karşılaştırma verisi ve ödül modeli

İkinci adımın amacı, birinci adımdaki insan emeğini ölçeklenebilir hale getirmektir (ekrandan, 01:20:00):

- Bir prompt ve modelin birkaç çıktısı örneklenir. Modelin içindeki rastgelelik sayesinde aynı girdi için farklı çıktılar üretilebilir; örnekte dört çıktı (A, B, C, D) vardır.
- Bir insan etiketleyici çıktıları en iyiden en kötüye sıralar (örneğin D > C > A = B).
- Bu verilerle bir **ödül modeli (reward model, RM)** eğitilir.

Ödül modelinin eğitim kümesi şudur: "Şöyle bir girdiye karşılık şöyle bir çıktı gelirse, ödülü şu olsun." Ödül modeli insanın yaptığı sıralama işini taklit eder. Bu, insan taklidi ve sahte ödül fikrinin aynısıdır: önce insan etiketler, sonra insanın yerine geçebilecek bir model eğitilir. Pekiştirmeli öğrenmede modeli eğitmek için geri bildirime, yani ödüle ihtiyaç vardır; ödülü artık bu model verir.

### 9.5 Adım 3: PPO ile politika optimizasyonu

Slayttaki Adım 3 (ekrandan, 01:20:00):

- Veri kümesinden yeni bir prompt örneklenir (örnek: "Write a story about otters").
- PPO modeli, denetimli politikadan başlatılır.
- Politika bir çıktı üretir ("Once upon a time...").
- Ödül modeli çıktı için bir ödül ($r_k$) hesaplar.
- Ödül, politikayı PPO ile güncellemek için kullanılır.

Bu adımda insan yoktur; bu yüzden ölçeklenebilirdir ve istenildiği kadar çalıştırılabilir. Birinci adımda insan cevabı doğrudan yazıyordu, ikinci adımda çıktıların iyiliğini söylüyordu, ödül modeli bu insan ödüllerini taklit etmeyi öğrendi, üçüncü adımda ise süreç tamamen insansız yürür.

Süreç burada bitmez. Model iyileşince yeniden **Adım 2'ye** dönülür: yeni girdiler için yeni çıktılar üretilir, insanlar bunları yeniden sıralar, ödül modeli yenilenir ve onunla model yeniden eğitilir. Bu birkaç yineleme sürer; kaç yineleme olduğu bilinmemektedir. Hoca, InstructGPT için insan emeğinin (birinci ve ikinci adım toplamı) yaklaşık 20 bin saat olarak söylendiğini, ama bundan emin olmadığını belirtti; ChatGPT için bu bilgi yoktur. <!-- BELİRSİZ: 20 bin saatlik insan emeği rakamı hocanın emin olmadığı bir bilgi; kaynakla doğrulanmadı. -->

## 10. Tartışma 2023: Bu Modeller Zeki mi?

Dönemin başında "makineye zeki der miyiz?" sorusu tartışılmıştı. Hoca, şu an büyük bir değişimin ortasında olduğumuzu hissettiğini söyledi ve 2023'teki tartışmayı iki görüşle özetledi (ekrandan, 01:40:00).

### 10.1 Birinci görüş: Hinton

Hinton, Bengio ve LeCun ile birlikte derin öğrenmeye katkılarından dolayı Turing Ödülü'nü aldı; geri yayılım (backpropagation) algoritmasını ortaya koyan üç kişiden biridir (diğer ikisi ödülü paylaştığı kişiler değildir). Google'dan ayrılırken dile getirdiği argüman slaytta şöyledir: "İnsan beyni kadar iyi çalışan sistemler yapmaya çalıştık. Ama şimdi 1T parametreli bu modeller bizim 100T parametreli beynimize çok yakın işler yapabiliyorlar. Yani bilgiyi bizden daha iyi temsil edebiliyorlar şu anda. Yakında ..."

- 1 trilyon, GPT-4'ün yaklaşık parametre sayısı için bir tahmindir.
- 100 trilyon kabaca şöyle hesaplanır: beyinde yaklaşık 100 milyar hücre, hücre başına ortalama 1000 bağlantı; $10^{11} \cdot 10^3 = 10^{14}$.
- Hiçbir insan bu modellerin kapsadığı kadar geniş bir bilgi dağarcığına sahip olamaz. İyi bilgi temsili iyi zekanın ölçütü sayılırsa, çok daha az parametreyle bilgiyi daha iyi temsil eden bu sistemlerin sonu "çok hayırlı değildir".

> **Ders sonrası not:** Hoca ödülün "geçen sene" alındığını söyledi; Hinton, Bengio ve LeCun büyük olasılıkla 2018 Turing Ödülü'nü almıştır (ödül 2019'da açıklanmıştı).

### 10.2 İkinci görüş: güvenilmezlik ve "yüksek teknoloji kopyacılığı"

Slayttaki ikinci madde: "Plan yapamıyorlarsa, nasıl kod yazıyorlar? Yepyeni problemleri, çözümü olanlar kadar iyi çözemiyorlar. (Bu high-tech plagiarism [Chomsky]). Aynı şeyler IBM'in Jeopardy sistemi için de söylenmişti. Abartmayalım."

- Bu modeller bir problem için kod, hatta algoritma yazabiliyor; ama basit bir plan yaptırmaya çalışınca iyi plan yapamıyor. GPT-4 üzerine Microsoft'un deneylerini anlatan makalenin sınırlılıklar bölümünde bile ciddi bir planlama eksikliği olduğu belirtiliyor. Daha zor bir problemi çözebilen bir sistemin daha kolayını çözememesi çok gariptir.
- Dil bilimci Chomsky bu modellere "yüksek teknoloji kopyacılığı" diyor: o kadar iyi kopya çekiyorlar ki kopya çektikleri anlaşılmıyor.
- Yaklaşık on yıl önce IBM'in Jeopardy sistemi (fact-based bir genel kültür yarışması) dünya şampiyonlarını yenmişti. Bilgi temsilini mükemmel yapan sistemler bulunduğu, ilk olarak tıp dünyasına uyarlanacağı söylenmişti; büyük çalışmalar yapılmasına rağmen bu beklenen başarıyı göstermedi.

Slayttaki soru: "Zorluk seviyesi çok daha fazla olan şeyleri yapabiliyorken daha az olanları yapamamanın, kolayca kandırılabilmelerinin açıklaması nedir?" Slaytta verilen olası cevaplar: yüksek teknoloji kopyacılığı (süper kopyacılar); bizim gibi hiyerarşik kabiliyet kümeleri yok, başka türlü, sistematik ve düzenli olmayan, hiyerarşik olmayan bir öğrenme; başka?

### 10.3 Büyütmek yeter mi?

Hoca bir başka noktaya değindi: OpenAI'ın baş mühendisi (Hinton'ın eski öğrencisi), yaptıklarının temelde yalnız büyütmek (hem veriyi hem modeli) olduğunu, korkunç farklı yeni şeyler yapmadıklarını söylüyor. Eğer iş gerçekten buysa, yani yalnız büyütmek daha iyi işler yapmaya yetiyorsa, Hinton'ın dediği doğru olabilir. Değilse, modeller o kadar iyi kopyacılardır ki nasıl kopya çektiklerini şu an anlayamıyoruz; zaten kara kutu durumundalar. Hangisinin doğru olduğunu zaman gösterecek.

### 10.4 İnsanları tahmin edilebilir hale getirmek

Slayttaki son madde: "İnsanları tahmin edemiyorsan, insanları tahmin edilebilir hale getir. Bu tür araçlar insanların tahmin edilebilirliğini arttırır mı?" Hoca bunu küreselleşmeyle ilişkilendirdi: insanların merak ettiği, istediği şeyler birbirinden o kadar farklı değilmiş; herkes benzer girdilere maruz kaldıkça benzer çıktılar üretiyor ve çeşitlilik (diversite) azalıyor. Belki birkaç yüz bin prompt'luk bir veri kümesi insanların dertlerinin büyük kısmını çözebiliyor.

## 11. Yapay Zekanın Etik ve Hukuk İlişkileri

### 11.1 Tanımlar

Slayttaki tanımlar (ekrandan, 02:00:00):

- **Etik / Ahlak:** İyi / kötü nedir? Hangi durumda ne yapılmalıdır? Felsefenin bir alt dalı gibi görülebilir, ama yaşamın tam içinden sorulardır: iyinin ve kötünün kaynağı nedir, hangi durumda ne yapmak iyidir.
- **Hukuk:** Toplumu düzenleyen ve devlet yaptırımıyla güçlendirilmiş bulunan kuralların, yasaların bütünü.
- **YZ:** karar veren bir sistem.

Hukukta devletin yaptırımı vardır; ahlakta ise illa devlet yaptırımı olması şart değildir, toplumsal yaptırımlar devreye girebilir. YZ, belli bir durumda kendisi ya da başkası için ne yapılması gerektiğine karar veren bir sistem olarak tanımlanınca doğrudan etik, ahlak ve hukukun alanına girer.

### 11.2 Hukuki olan her zaman etik midir?

Hayır. Hukuk ve etik zamandan ve kültürden bağımsız değildir. Bir zamanlar herkese normal, ahlaki ve hukuki gelen şeyler zamanla ne kadar kötü olduğu anlaşılan şeylere dönüşür. Kölelik bir zamanlar hemen bütün devletlerin hukukunda yer alıyordu ve çok eski olmayan bir tarihte kalktı; o kültürün içinde yaşayanlara bu garip gelmiyordu. Slayttaki soru: "Gelecek?" Yani bugün normal gördüğümüz neler gelecekte etik dışı ya da insanlık dışı bulunacak? Hoca bunun iyi bir beyin jimnastiği olacağını söyledi.

> **Ders sonrası not:** Hoca köleliğin dünyada en son 1965 civarında kalktığını söyledi. Büyük olasılıkla resmi olarak en son kaldıran ülke 1981'de Moritanya'dır (suç olarak tanımlanması 2007).

### 11.3 Verilerdeki önyargı

YZ sistemleri veriden öğrenir; bu veri çoğunlukla internetteki yazılı verilerdir. Veride bir önyargı varsa sistem onu da öğrenir. Örneğin bir insan kaynakları işe alım sürecini geçmiş kararlarla modellerseniz ve o kararlarda cinsiyet, yaş vb. açılardan ayrımcılık varsa model de ayrımcılık yapar. Bu kötü bir durumdur ama beklenmedik değildir.

Ayrıca yazılı metinler gerçek dünyayı olduğu gibi yansıtmaz. Slayttaki örnekler (ekrandan, 02:05:00):

| Arama | Sonuç sayısı |
|---|---|
| «kırmızı muz» | 13.400 |
| «sarı muz» | 30.400 |
| «yeşil muz» | 33.600 |
| «yemek yedi» | 714.000 |
| «öldürdü» | 26.100.000 |

Gerçek dünyada muzların çoğu sarıdır ve birine muzun rengi sorulsa "sarı" der; ama "sarı muz" pek söylenmez, yazılmaz. Yazmak, olağan dışı şeyleri haber vermek için yapılır. Benzer şekilde yazılı metinlere bakan bir yapay zeka, insanların yemek yemekten çok birilerini öldürdüğünü sanabilir. Slayttaki sonuç: "Normalde olan şeyleri söylemez, yazmayız. Gerçek dünyadaki olayların frekanslarıyla yazılı metinler ya da konuşmalardaki frekansları çok farklı olur." Hareketlerimizin temel kaynağı nadir olaylar değil, sağduyudur (common sense). Bu yüzden robotlar bir gün aramızda dolaşacaksa, yalnız internetteki metinlerle değil, dünyanın içinde gezinip gerçek olay ve davranış dağılımını öğrenerek uyum sağlayabilirler.

### 11.4 Doktor bilmecesi ve kendi önyargılarımız

Slaytta bir bilmece soruldu (ekrandan, 02:10:00; ayrıntı için Örnek Sorular'a bakın). Öğrenciler karmaşık senaryolar önerdi; doğru açıklama çok basittir: cerrah çocuğun annesidir. Bilmecenin garip gelmesinin nedeni, doktorların erkek olduğu yönündeki bir önyargının modelde değil, **bizde** olmasıdır. Hikaye "bir kadın ve oğlu" diye anlatılsaydı hiç garip gelmezdi.

Hoca şunları vurguladı:

- Hepimizde, farkında olsak da olmasak da önyargılar vardır (bu konuyu işleyen Crash filmini örnek verdi).
- Önyargılar olmadan insanlar karar veremez; önyargılar hızlı karar almamızı sağlar. Bütün önyargılar kötü değildir.
- Önemli olan önyargının zararlı olup olmadığı, bizim ya da başkalarının hayatını kısıtlayıp kısıtlamadığıdır. Bu yüzden onların farkına varmak önemlidir.

> **Hocanın vurgusu:** Önyargılardan kurtulmak kolay değildir; ama zararlı olanlarının farkına varmak önemlidir.

### 11.5 Eş zamanlılık ve nedensellik

Slayttaki maddeler (ekrandan, 02:15:00):

- Benzer zamanda olan şeyler her zaman sebep-sonuç ilişkisine sahip değildir.
- İnternetin yaygınlaşması ile dünyadaki ağaç sayısının azalması.
- Resmi çekilen kedi sayısındaki artış ile trafik kazalarının sayısındaki artış.
- Kadınlara oy hakkı verilmesi ile dünya savaşlarının başlaması (1900'ler).

Hoca, derinlemesine düşünülmediğinde eş zamanlılığın kolayca sebep-sonuç gibi algılandığını söyledi. Bilgi bombardımanı derin düşünmeyi engelliyor: sürekli akan bir enformasyon yığını içinde hiçbir şeyin üzerinde 30 saniyeden fazla durmuyoruz ve yüzeyde geziniyoruz; arka planı görme şansımız kalmıyor. Yüz tanıma testlerinde bu tür önyargıları ortaya çıkarmak için çeşitli yaklaşımlar da vardır.

### 11.6 Sorumluluk

Karanlık bir yolda bisikletli bir kişi aniden otobana girer ve otonom bir araç ona çarpıp ölümüne neden olur. Bu bir hatadır; arabayı bir insan sürseydi kurtarabilir miydi, orası soru işaretidir. Asıl soru hukuki anlamda sorumlunun kim olacağıdır; hukukun bu alana girmesi gerekecektir. Yapay zekanın işlerimizi elimizden alıp almayacağı da eskiden şaka gibi görünürken artık ciddi bir soru haline gelmiştir.

> **Ders sonrası not:** Hocanın anlattığı olay büyük olasılıkla 2018'de ABD'de, bisikletini iterek yolu geçen bir yayaya test halindeki bir otonom aracın çarptığı kazadır.

### 11.7 Manipülasyon

Soru: birinin bir konu hakkındaki fikrini ona video izleterek, haber okutarak değiştirmek mümkün müdür? Hocaya göre evet; bütün reklam sektörü bunun üzerine kuruludur ve gençler değişime daha açıktır. Sosyal medyada karşınıza çıkan içerik size bir ürünü satın aldırmayı ya da bir konudaki fikrinizi değiştirmeyi amaçlayabilir. Bir yapay zeka sistemi böyle bir amaç edinirse bunu başarabilir; bu sistemlerin kullanılıp kullanılmadığı ayrı bir konudur, ama olasılık dahilindedir. Sosyal medya modelleri başta insanların ne istediğini öğrenmeye çalışıyordu; şimdiki hali insanları da tahmin edilebilir hale getirmektir.

### 11.8 Kişisel verilerin sahibi

Slayttaki maddeler (ekrandan, 02:20:00):

- Ne amaçla, hangi verilerinizi kullandığını, kimlere vereceğini açıklamalı, size ait verileri göstermeli.
- Ham veriler bir şey, işlenmiş veriler başka bir şeydir: tıkladığınız haberler → siyasi tercihiniz; koordinatlarınız → rakip şirketle görüşmeye gittiniz.
- "Reklam amaçlı kullanacağım" = ???

Sizin hakkınızda üretilen tahminlerin sizinle ya da başkalarıyla paylaşılıp paylaşılmayacağı da bir sorudur. Cep telefonunuzun verilerini inceleyen biri hakkınızda neredeyse her şeyi öğrenebilir; asıl soru neyi öğrenemeyeceğidir. Kişisel veriler kimlerle (sigorta şirketleri, ebeveynler, eşler, patron vb.) paylaşılmalıdır?

Veri paylaşımı çoğu zaman karşılıklı kazançlı (win-win) bir ilişkidir: size en yakın kebapçıyı bulmak için konum verinizi paylaşırsınız; siz hızlı hizmet alırsınız, şirket de nerelerde dolaştığınızı ve tercihlerinizi öğrenir. Sağlıkta bu durum çok daha ciddidir: sağlık verileri ileride çok daha fazla toplanacak ve işlenecektir. Örneğin kalp krizini birkaç dakika önceden fark edebilecek bir sistem olursa, insanlar bu verileri seve seve paylaşacaktır. Ama bu verilerin kimlerle paylaşılacağı birçok soru işareti doğurur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): Q-öğrenme güncelleme kuralı $Q[s,a] = Q[s,a] + \alpha(R + \gamma \max Q(s',A) - Q[s,a])$, $\alpha = 0.5$, $\gamma = 0.9$ ve başta sıfır olan Q tablosu ile 9 durumlu araba örneğinde, önce 3 durumunda Left (ödül 10, varılan durum 8), sonra 2 durumunda Left (ödül 0, varılan durum 6) seçilirse $Q[3,L]$ ve $Q[2,L]$ ne olur?

> **Cevap (derste verildi):** $Q[3,L] = 0 + 0.5(10 + 0.9 \cdot \max[0,0,0,0] - 0) = 5$; benzer olarak $Q[6,D] = 5$. Sonra $Q[2,L] = 0 + 0.5(0 + 0.9 \cdot \max[0,5,0,0] - 0) = 2.25$; benzer olarak $Q[2,D] = 2.25$ ve $Q[7,L] = 2.25$.

**Soru 2** (derste sözlü, 00:49:48; ekrandan, 00:50:00): Labirentte ödül yalnız bitişte varsa, kısa ve uzun yollar aynı toplam ödülü alır. Q-öğrenmenin kısa yolu bulmasını sağlamak için ödüllerle nasıl oynanabilir?

> **Cevap (derste verildi):** Her adımın ödülü $-1$ yapılır. Ajan her adımda ceza aldığı için en az toplam cezayı, yani en az sayıda adımı arar; adım sayısını kendiliğinden en aza indirir.

**Soru 3** (derste sözlü, 01:13:38): Ödül ancak arka arkaya 100 doğru hamleden sonra geliyorsa ve her adımda 4 seçenek varsa, rastgele hareketle ödüle ulaşma şansı nedir? Bu neden bir sorundur?

> **Cevap (derste verildi):** $1/4^{100}$ (python ile yaklaşık $6.2 \times 10^{-61}$). Ödülle karşılaşılmadıkça Q tablosu hiç güncellenmez; bu seyrek ödül problemidir.

**Soru 4** (ekrandan, 02:10:00): "Bir adam ve oğlu ciddi bir trafik kazası geçirmişler ve acildeler. Çocuğun ameliyat olması gerekiyor. Ameliyatı yapacak doktor çocuğa bakıyor ve «bu ameliyatı yapamam, bu benim oğlum» diyor. Bu mümkün mü?"

> **Cevap (derste verildi):** Evet; cerrah çocuğun annesidir. Bilmecenin garip gelmesi, doktorların erkek olduğu yönünde bizde var olan bir önyargıdan kaynaklanır.

**Soru 5** (ekrandan, 01:40:00): Zorluk seviyesi çok daha fazla olan şeyleri yapabiliyorken daha az olanları yapamamanın, kolayca kandırılabilmelerinin açıklaması nedir?

> **Cevap (slaytta verilen olası açıklamalar):** "High-tech plagiarism", yani süper kopyacılar; ya da bizim gibi hiyerarşik kabiliyet kümelerinin olmaması (sistematik, düzenli, hiyerarşik olmayan başka türlü bir öğrenme). Slayt "Başka??" diye soruyu açık bırakır.

**Soru 6** (derste sözlü, 02:17:44): Birinin bir konu hakkındaki fikrini ona video izleterek, haber okutarak değiştirmek mümkün müdür?

> **Cevap (derste verildi):** Evet, mümkündür; reklam sektörü bunun üzerine kuruludur. Bir yapay zeka sistemi birine bir şey satın aldırmayı ya da bir konudaki fikrini değiştirmeyi amaç edinirse bunu başarabilir.

**Soru 7** (derste sözlü, 02:20:15): Cep telefonunuzun verilerini inceleyen biri sizin hakkınızda neler öğrenebilir?

> **Cevap (derste verildi):** Neredeyse her şeyi; asıl soru neyi öğrenemeyeceğidir. Ham veriler işlenince örneğin tıklanan haberlerden siyasi tercih, koordinatlardan rakip bir şirketle görüşmeye gidildiği çıkarılabilir.

## Dersin Toparlaması

Bu derste makine öğrenmesinin son ayağı olan pekiştirmeli öğrenme işlendi. Ajan, doğru cevabı söylenmeden yalnız ödül ve ceza ile, ortamda hareket ederek toplam ödülü en büyük yapacak politikayı öğrenir. Q-öğrenme, ayrık bir uzayda durumlarla hareketleri eşleyen bir Q tablosunu $Q[s,a] \leftarrow Q[s,a] + \alpha(R + \gamma \max Q[s',\cdot] - Q[s,a])$ kuralıyla günceller; max terimi sayesinde hedefteki ödül geriye doğru yayılır. Keşfetmek / kullanmak ikilemi epsilon-açgözlü seçimle dengelenir; adım cezası kısa yolu öncelemeyi sağlar. Durum sayısının kestirilemediği oyunlarda Q tablosunun işini derin Q-ağı üstlenir; seyrek ödüllü ortamlarda insan taklidi ve sahte ödüller kullanılır.

Bu fikirler, büyük dil modellerinin insan geri bildirimiyle eğitildiği RLHF'de birleşir: denetimli ince ayar, insan sıralamasını taklit eden bir ödül modeli ve PPO ile insansız, ölçeklenebilir politika güncellemesi. Dersin sonunda bu modellerin zekası üzerine 2023 tartışması ve yapay zekanın etik ve hukuk ilişkileri ele alındı: verideki ve bizdeki önyargılar, eş zamanlılık ile nedensellik farkı, sorumluluk, manipülasyon ve kişisel verilerin sahipliği.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
