# Ders 10 Çalışma Özeti

## Genel Konular

- Doğrusal ayrılabilirlik ve tek nöron
  - AND, OR ve XOR fonksiyonları iki girişli düzlemde gösterilir. AND ve OR tek bir doğruyla ayrılabilir, XOR ayrılamaz (ekrandan, 00:20:00).
  - Tek nöron doğrusal bir sınıflayıcıdır. Bu yüzden XOR tek nöronla çözülemez, en az bir gizli katman gerekir.
  - İki özellikli bir nöronda karar sınırı $w_1 x + w_2 y + w_3 b = 0$ doğrusudur. Bias ($b = 1$ ile çarpılan $w_3$) doğrunun orijinden geçmek zorunda kalmamasını sağlar (ekrandan, 00:30:00).
- Nöronun çalışması
  - Girişler ağırlıklarla çarpılır ve toplanır. Bu toplam $S$ preaktivasyondur: $S = x_1 w_1 + x_2 w_2 + \dots + b \cdot 1$ (ekrandan, 01:10:00).
  - $S$ bir aktivasyon fonksiyonundan geçer ve nöronun çıktısı $y = f(S)$ olur. Örnek fonksiyonlar: basamak, signum, sigmoid, tanh, ReLU.
  - Aktivasyonun değer aralığı önemlidir: sigmoid $(0,1)$, tanh $(-1,1)$, ReLU pozitif tarafta doğrusal. Beklenen çıktılar bu aralığa göre kodlanır.
  - Biyolojik benzetme: girişler dendritler, ağırlıklar nörotransmitterler, aktivasyon hücre çekirdeği gibi düşünülür.
- Çok katmanlı algılayıcının yapısı
  - Giriş katmanı, bir ya da daha fazla gizli katman ve çıkış katmanı vardır. Tam bağlı ağda her nöron sonraki katmanın bütün nöronlarına bağlıdır. Bazı bağlantılar kaldırılırsa budama (pruning) yapılmış olur.
  - Katmanlar arası hesap matris çarpımıdır: $X_{i \times j}$ giriş matrisi, $W_{(1)}$ $j \times k$, $W_{(n)}$ $p \times m$, $W_{(n+1)}$ $m \times t$ boyutludur (ekrandan, 00:40:00).
  - GPU'larla matris çarpımının hızlanması derin öğrenmenin yaygınlaşmasının önemli bir nedenidir.
  - Gizli katman sayısı ve nöron sayısı problemin doğrusal olmama derecesine bağlıdır. Kesin bir kural yoktur, deneme yanılma ile seçilir. Giriş boyutu veriye, çıkış boyutu probleme göre belirlenir.
- Eğitimin üç adımı
  - İleri geçiş (forward pass): girişten çıkışa çarp, topla, aktivasyondan geçir, çıkıştaki hataları bul.
  - Geri geçiş (backward pass): hatadan geriye doğru giderek her ağırlık için türev hesapla.
  - Ağırlık güncelleme.
  - Hata fonksiyonu olarak ortalama kare hata (MSE) ya da hinge loss kullanılabilir. $E_{total} = E_1 + \dots + E_t$, $t$ çıkış nöronu sayısıdır.
- Epoch, batch ve doğrulama
  - Eğitim kümesinin tamamının bir kez ağdan geçmesi bir epoch'tur.
  - Batch: örnekler gruplara ayrılır. Grubun her örneği için ileri geçiş yapılır, grubun ortalama hatası üzerinden bir kez geri geçiş ve güncelleme yapılır.
  - Stokastik gradyan düşümünde batch boyutu 1, batch gradyan düşümünde eğitim kümesi boyutu kadardır. Mini-batch arada kalır (ekrandan, 00:45:00).
  - Eğitim kümesinden ayrılan bir doğrulama (validation) kümesiyle eğitim sırasında başarım izlenir. Test kümesine eğitim bitene kadar dokunulmaz.
- Geri yayılımın türetilmesi
  - Hata ağırlık cinsinden doğrudan yazılamadığı için zincir kuralı kullanılır:
    $\dfrac{\partial E_{total}}{\partial w} = \dfrac{\partial E_{total}}{\partial y} \cdot \dfrac{\partial y}{\partial S} \cdot \dfrac{\partial S}{\partial w}$ (ekrandan, 01:20:00).
  - Örnekte aktivasyon tanh'tır: $y = \tanh(S)$, $\partial y / \partial S = 1 - \tanh^2(S)$ (ekrandan, 01:20:00).
  - $\partial S / \partial w$ her zaman o ağırlığın çarpıldığı girişe (önceki katmanın çıktısına) eşittir.
  - Güncelleme: $\hat{w} = w - \eta \, \partial E_{total} / \partial w$. Burada $\eta$ öğrenme oranıdır (ekrandan, 01:25:00).
  - İlk iki çarpan $\delta$ olarak tanımlanır: $\delta = \dfrac{\partial E_{total}}{\partial y} \cdot \dfrac{\partial y}{\partial S} = \dfrac{\partial E_{total}}{\partial S}$. Çıkış ağırlığı için $\hat{w} = w - \eta \, \delta \, y_{\text{önceki}}$ olur.
  - Gizli katman ağırlığı için sonraki katmanın $\delta$ değerleri ağırlıklarla toplanarak geriye taşınır. Genel kural (ekrandan, 01:35:00):
    $\hat{w}_{(\varsigma)_{i\_j}} = w_{(\varsigma)_{i\_j}} - \eta \left[ \left( \sum_{\alpha} \delta_{(\varsigma+1)_\alpha} w_{(\varsigma+1)_{j\_\alpha}} \right) f'(S_{(\varsigma)_j}) \, y_{(\varsigma-1)_i} \right]$
- Öğrenme oranı
  - Çok küçük $\eta$ öğrenmeyi çok yavaşlatır, çok büyük $\eta$ minimumun üzerinden atlatır ve ıraksamaya götürebilir.
  - En iyisi uyarlamalı öğrenme oranıdır: hata azaldıkça adım küçültülür (Adam gibi yöntemler). Öğrenme oranına göre kayıp (loss) izlenerek karar verilir (ekrandan, 01:40:00).
- Uygulama notları
  - Ağırlık başlatma (Xavier): ağırlıklar katman boyutlarına bağlı bir aralıktan seçilir: $\left[-4\sqrt{\tfrac{6}{size(\varsigma)+size(\varsigma+1)}},\ 4\sqrt{\tfrac{6}{size(\varsigma)+size(\varsigma+1)}}\right]$ (ekrandan, 01:45:00).
  - Girişin ölçeklenmesi: büyük giriş değerleri sigmoid ya da tanh'ı doyuma (satürasyon) sokar. Bu yüzden min-max normalizasyonu yapılır, 8 bitlik gri görüntüde pikseller 255'e bölünür.
  - Batch kullanımı hem hızı hem genellemeyi destekler.
- MNIST uygulaması
  - El yazısı rakam veri kümesi: $28 \times 28 = 784$ gri piksel, 10 sınıf, 60.000 eğitim ve 10.000 test örneği (ekrandan, 01:50:00).
  - Giriş katmanı 784 nöron, çıkış katmanı 10 nörondur. Literatürde iki gizli katmanlı (1024-1024) bir ağ yaklaşık %97 doğruluk verir.
  - Beklenen çıktılar one-hot kodlanır: "3" etiketi için dördüncü nöron 1, diğerleri 0 (ekrandan, 01:55:00).
  - Fashion-MNIST ve CIFAR gibi küçük veri kümeleri de denemek için uygundur.

## Hocanın Özellikle Vurguladığı Kısımlar

- İleri geçiş, geri geçiş ve ağırlık güncelleme adlarını ve sırasını bilmek önemlidir.
  - Geri yayılım bu üç adımın üzerine kuruludur.
- Zincir kuralındaki çarpımlar geri yayılımın en çok zaman alan kısmıdır.
  - Batch kullanmak geri geçiş sayısını azaltarak hızı artırır.
- Aktivasyon fonksiyonunun türevi mutlaka bilinmelidir.
  - Ağ sıfırdan yazılırken geri yayılımda hep bu türev gerekir.
- Çıkış formülü ile gizli katman formülü farklıdır.
  - Çıkışta geriye taşınan bir $\delta$ yoktur, gizli katmanlarda sonraki katmandan gelen $\delta$'lar toplama girer.
- Öğrenme oranı seçilirken izlenecek büyüklük kayıptır (loss).
- Hazır çerçevelerde (Keras gibi) iki satırda ağ kurulabilir, ama arkada ne olduğunu bilmek gerekir. Xavier, Adam gibi parametre adlarının ne anlama geldiği bilinmelidir.

## Kısa Tekrar Notları

- XOR doğrusal ayrılamaz, tek nöron yetmez.
- Tek nöron = doğrusal sınıflayıcı. Bias doğruyu orijinden kaydırır.
- $S$ = ağırlıklı toplam (preaktivasyon), $y = f(S)$.
- Eğitim: ileri geçiş, geri geçiş, güncelleme.
- Epoch: bütün eğitim kümesinin bir turu. Batch: ortalama hatayla toplu güncelleme.
- $\partial E/\partial w = (\partial E/\partial y)(\partial y/\partial S)(\partial S/\partial w)$.
- $\tanh'(S) = 1 - \tanh^2(S)$.
- $\delta = \partial E / \partial S$; çıkışta $\hat{w} = w - \eta\,\delta\,y_{\text{önceki}}$.
- Gizli katmanda $\delta$, sonraki katmanın $\sum \delta \cdot w$ toplamı ile $f'(S)$'nin çarpımıdır.
- Büyük $\eta$ ıraksar, küçük $\eta$ yavaştır, uyarlamalı $\eta$ en iyisidir.
- Xavier başlatma ve girişlerin $[0,1]$ aralığına ölçeklenmesi doyumu önler.
- MNIST: 784 giriş, 10 çıkış, one-hot hedef.

## Detaylı Açıklamalar

- Bu ders bir araştırma görevlisi tarafından, önceki derste hocanın anlattığı geri yayılımın tekrarı ve formüllerin adım adım çıkarılması amacıyla verilmiştir. Anlatım tek nörondan başlar ve çok katmanlı algılayıcıya kadar büyütülür.
- Tek nöronun karar sınırı. İki özellikli bir nöronun çıktısı sıfıra eşitlendiğinde $w_1 x + w_2 y + w_3 = 0$ doğrusu elde edilir ($b = 1$). Buradan $y = -\dfrac{w_1}{w_2}x - \dfrac{w_3}{w_2}$ bulunur. Slaytta eğim, eksenleri kestiği iki noktadan $-\dfrac{w_3/w_2}{w_3/w_1} = -\dfrac{w_1}{w_2}$ olarak, sabit terim ise $c = -w_3/w_2$ olarak hesaplanır (ekrandan, 00:30:00). Eğitimle bulunan ağırlıklar böyle bir doğruya karşılık gelir. Doğrusal ayrılabilen iki sınıflı rastgele veride eğitilen ağın doğrusu ideal ayırıcı doğruyla karşılaştırılabilir.
- Katman boyutları ve matrisler. $i$ eğitim örneği sayısı, $j$ giriş nöronu sayısı, $k$ ilk gizli katman boyutu, $n$ gizli katman sayısı (nohl), $p$ $(n-1)$. gizli katmanın boyutu, $m$ son gizli katmanın boyutu, $t$ çıkış boyutudur (ekrandan, 00:40:00). Ardışık matrislerin boyutları çarpıma uygun olmalıdır.
- Eğitim algoritması slayttaki iç içe döngülerle verilir (ekrandan, 00:45:00):

```text
for epoch <- 1 ... last_epoch
    for batch <- 1 ... (input_samples_count / batch_size)
        for elements_in_batch <- 1 ... batch_size
            for layer <- 1 ... hidden_layer_number+1
                do forward_path()
        for layer <- hidden_layer_number+1 ... 1
            do backward_path()
        do update_weights()
    do cross_validation_test()
```

- Batch örneği. 100 eğitim görüntüsü tek tek verilirse 100 güncellemeyle bir epoch biter. 25'erli 4 gruba bölünürse her grubun ortalama hatasıyla 4 güncelleme yapılır. Eğitim kümesi 50, batch boyutu 5 ise bir epoch'ta 10 güncelleme olur.
- Zincir kuralı ile türetme. Çıkış katmanındaki $w_{(nohl+1)_{1\_1}}$ ağırlığı için üç çarpan ayrı ayrı bulunur. Birincisi hatanın çıktıya göre türevidir; $E_{total}$ içindeki yalnız $E_1$ terimi $y_{(nohl+1)_1}$'e bağlı olduğu için diğerleri sıfır olur. İkincisi aktivasyonun türevidir, tanh için $1 - \tanh^2(S)$. Üçüncüsü $\partial S / \partial w$'dir ve yalnız o ağırlığın çarptığı girişi bırakır.
- Gizli katmana genelleme. $\partial E_{total} / \partial y_{(nohl)_1}$ bütün çıkış hatalarının toplamıdır: $\sum_{u} \dfrac{\partial E_u}{\partial y_{(nohl+1)_u}} \dfrac{\partial y_{(nohl+1)_u}}{\partial S_{(nohl+1)_u}} \dfrac{\partial S_{(nohl+1)_u}}{\partial y_{(nohl)_1}}$ (ekrandan, 01:30:00). İlk iki çarpan $\delta$'dır, üçüncüsü ($\partial S/\partial y$) ilgili ağırlığı verir. Böylece $\sum_\alpha \delta_{(nohl+1)_\alpha} w_{(nohl+1)_{1\_\alpha}}$ elde edilir ve bu toplam geriye yayılan bilgidir (ekrandan, 01:35:00).
- Doyum (satürasyon). Örneğin 25, 38, 42 gibi büyük girişler rastgele ağırlıklarla çarpılıp binlerce nörondan toplanırsa sigmoid hep 1 (ya da 0) verir. Türev sıfıra yaklaşır ve öğrenme durur. Bunu önlemek için ağırlıklar Xavier aralığından seçilir, girişler min-max ile ölçeklenir.

> **Ders sonrası not:** Slayttaki min-max formülü $\bar{x} = \dfrac{x + \min(X)}{\max(X) - \min(X)}$ biçiminde yazılmıştır (ekrandan, 01:45:00). Doğrusu $\bar{x} = \dfrac{x - \min(X)}{\max(X) - \min(X)}$'tir; bu biçim değerleri $[0,1]$ aralığına getirir.

> **Ders sonrası not:** Hata fonksiyonundaki $\tfrac{1}{2}$ katsayısı için derste "ortalama alınıyor" denmiştir. Bu katsayı büyük olasılıkla kare alınan terimin türevindeki 2'yi sadeleştirmek için konur, ortalama anlamına gelmez.

- One-hot kodlama. Çıkışta sigmoid kullanıldığında değerler $[0,1]$ aralığında olduğu için beklenen çıktı en büyük değer 1, diğerleri 0 olacak biçimde kodlanır. Rakam "3" için 0, 1, 2, 3 sırasındaki dördüncü nöron 1 olur. Gerçek çıktılarla bu vektör arasındaki hata her nöron için ayrı hesaplanır ve geri yayılım başlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
