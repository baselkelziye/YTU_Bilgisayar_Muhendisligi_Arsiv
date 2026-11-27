# Ders 18 Çalışma Özeti

## Genel Konular

- Ağaçla dizin (klasör) sistemi simülasyonu: uygulama probleminin çözümü
  - Bu uygulama saatinde, ağaç veri yapısıyla bir dizin sistemi simüle eden programın örnek çözümü slaytlar üzerinden adım adım incelendi.
  - Beş komut gerçeklenir: `mkdir` (yeni dizin oluşturma), `chdir` (dizinler arasında gezinme), `rmdir` (dizin silme), `dir` (bulunulan dizindeki alt dizinleri listeleme) ve `count` (bulunulan dizindeki alt dizin sayısını verme).
- Düğüm yapısı ve ilk çocuk / sonraki kardeş gösterimi
  - Her düğümde dizinin adı (`name`) ile `left`, `right` ve `parent` işaretçileri bulunur.
  - `left` bir alt seviyeye, yani dizinin ilk alt dizinine gider. `right` aynı seviyedeki bir sonraki dizine (kardeşe) gider. Böylece aşağı inildikçe dizin derinleşir, yatayda aynı dizindeki dizinler görülür.
  - `parent` işaretçisi düğümün kendisini işaret eden düğüme bağlanır: bir dizinin ilk alt dizini için bu gerçek üst dizindir, sonraki kardeşler için solundaki kardeştir.
- `mkdir name`
  - Bulunulan dizinin `left` alanı `NULL` ise dizin boştur; yeni düğüm `left` alanına oluşturulur ve yeni düğümün `parent` alanı bulunulan dizine bağlanır (ekrandan, 00:15:00).
  - Dizin boş değilse ilk alt dizine inilir, `right` zinciri sonuna kadar dolaşılır ve her düğümde aynı ad var mı diye bakılır. Döngü son düğümde durduğu için son düğüm döngüden sonra ayrıca kontrol edilir (ekrandan, 00:20:00).
  - Aynı ad yoksa yeni düğüm son kardeşin `right` alanına eklenir ve `parent` alanı o kardeşe bağlanır.
- `chdir name`
  - `..` ile bir üst dizine çıkma: `parent` NULL değilse (kökte değilse), `node->parent->right == node` olduğu sürece sola, kardeşler boyunca geri gidilir; sonra bir kez daha `parent` alınarak gerçek üst dizine ulaşılır (ekrandan, 00:25:00).
  - Alt dizine inme: ilk alt dizine inilir, ad bulunana ya da zincirin sonuna gelinene kadar sağa gidilir; son düğüm de adla eşleşmiyorsa "böyle bir dizin yok" mesajı basılır (ekrandan, 00:30:00).
- `rmdir name`
  - Aranan dizin yoksa hata mesajı basılır.
  - Dizinin alt dizini varsa (`left` NULL değilse) silinmez: "dizin boş olmalı" mesajı basılır.
  - Alt dizini olmayan bir dizin için üç durum vardır: dizin, üst dizine bağlı ilk düğümdür; arada bir düğümdür; zincirin son düğümüdür (ekrandan, 00:35:00 ve 00:40:00).
- `dir` ve `count`
  - `dir`: `left` NULL ise "dizin yok" yazılır; değilse ilk alt dizinden başlayıp `right` zinciri boyunca adlar basılır (ekrandan, 00:45:00).
  - `count`: `dir` ile aynı dolaşmadır; ad basmak yerine her düğümde bir sayaç bir artırılır ve sonunda sayaç basılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yeni düğümün üst bağlantısı ayrıca kurulmalıdır
  - Üst düğümün `left` (ya da `right`) alanına yeni düğüm eklenince üst düğüm yeni düğümü tanır, ama yeni düğüm kendi `parent` alanını bilmez. Bu yüzden ekleme her zaman `...->parent = node;` satırıyla tamamlanır.
- Döngüden sonraki ek ad kontrolü
  - `while (node->right != NULL ...)` döngüsü son düğümü işlemeden çıkar. Son düğümü (sağında NULL olan dizini) de kontrol etmek için döngüden sonra ad bir kez daha karşılaştırılır.
- `parent != NULL` kontrolünün nedeni
  - Kökün üst dizini yoktur; kökteyken `..` komutu üst dizine gidemez. Bu durum `node->parent != NULL` koşuluyla yakalanır.
- `left` ve `right` anlamını karıştırmamak
  - Bu tasarımda `left` bir alt dizin seviyesine inmek, `right` aynı dizindeki bir sonraki dizine geçmek demektir.
- Silinen düğümün belleği
  - Bağlantılar koparıldıktan sonra silinen düğüm `free` ile serbest bırakılabilir (bir öğrencinin önerisi, onaylandı).
- Programı birden fazla örnekle denemek
  - Tek bir dizin ekleyip doğru çalıştığını görmek yetmez; iki, üç dizin eklendiğinde hata veren çözümler görüldü. Test durumları arttıkça programın doğruluğundan daha çok emin olunur.

## Kısa Tekrar Notları

- Düğüm: `name`, `left` (ilk alt dizin), `right` (sonraki kardeş), `parent` (kendisini işaret eden düğüm).
- `mkdir`: boşsa `left`'e ekle; değilse `right` zincirini dolaş, aynı ad varsa çık, yoksa son kardeşin `right`'ına ekle; her durumda yeni düğümün `parent`'ını bağla.
- `chdir ..`: `while (node->parent->right == node) node = node->parent;` ardından `node = node->parent;`.
- `chdir name`: `node = node->left;` sonra ad bulunana ya da zincir bitene kadar `node = node->right;` döngüden sonra son kontrol.
- `rmdir`: alt dizini varsa silme. İlk düğüm: `node->parent->left` güncellenir. Ara düğüm: `node->parent->right = node->right;` ve `node->right->parent = node->parent;`. Son düğüm: `node->parent->right = NULL;`.
- `dir` ve `count` aynı `right` zinciri dolaşmasıdır; biri ad basar, diğeri sayaç artırır.
- Silinen düğüm `free` edilebilir.

## Detaylı Açıklamalar

- Çok çocuklu bir dizin ağacı, her düğümde yalnız iki çocuk işaretçisi kullanılarak gösterilir. Bir dizinin alt dizinleri `left` ile başlayan ve `right` ile devam eden bir bağlı liste oluşturur. Örnek ağaçta kökün altında `dir1`, `dir2`, `dir3` vardır ve `dir2`'nin altında `abc` bulunur. Kök `left` ile `dir1`'e, `dir1` `right` ile `dir2`'ye, `dir2` `right` ile `dir3`'e bağlıdır; `dir2`'nin `left` alanı `abc`'yi gösterir (ekrandan, 00:25:00).
- `parent` işaretçisi bu çözümde düğümü işaret eden düğümü tutar. `mkdir` boş dizine eklerken `node->left->parent = node;`, sona eklerken son kardeş `node` olduğu için yeni düğümün `parent` alanı o kardeş olur. Bu yüzden `dir2`'nin `parent` alanı `dir1`, `abc`'nin `parent` alanı ise `dir2`'dir. Ders sonrası C ile yapılan denemede de bu ilişki doğrulandı.
- `chdir ..` bu ilişkiye dayanır. `abc`'den çıkarken `abc->parent` `dir2`'dir ve `dir2->right` `abc` olmadığı için döngüye girilmez; tek `node = node->parent;` ile `dir2`'ye çıkılır. `dir3`'ten çıkarken ise önce `dir2`'ye, sonra `dir1`'e geri gidilir (çünkü her birinin solundakinin `right` alanı kendisidir); `dir1`'in `parent` alanı olan kökün `right` alanı `dir1` olmadığından döngü biter ve son `node = node->parent;` ile köke ulaşılır.
- `rmdir` ilk düğüm durumunda `node->parent->left == node` koşulu sağlanır. Silinen düğümün sağında düğüm yoksa üst dizinin `left` alanı NULL yapılır; varsa üst dizinin `left` alanı sağdaki düğüme bağlanır ve sağdaki düğümün `parent` alanı üst dizin yapılır. Örnekte `dir1` silinince kök doğrudan `dir2`'yi gösterir (ekrandan, 00:35:00). Ara düğümde (örnekte `dir3`) solundaki kardeşin `right` alanı sağdaki kardeşe bağlanır ve sağdakinin `parent` alanı soldaki kardeş olur. Son düğümde (örnekte `dir4`) solundaki kardeşin `right` alanı NULL yapılır (ekrandan, 00:40:00).
- Ders sonrası not: Oturumdaki bir soruya ilk cevapta `dir2`'nin `parent` alanının kök olduğu söylendi, birkaç dakika sonra aynı soruya `dir1` dendi. Slayttaki kodla kurulan yapıda doğrusu `dir1`'dir (C ile denendi).
- Ders sonrası not: Slayttaki `chdir` kodunda aranan dizin bulunamazsa hata mesajı basılır ama fonksiyon yine de zincirin son düğümünü döndürür; böylece bulunulan dizin istemeden son kardeşe geçer. Ayrıca bulunulan dizinin hiç alt dizini yoksa `node = node->left;` sonrasında `node->right` NULL işaretçi üzerinden okunur. Bu iki durum derste konuşulmadı; C ile yapılan denemede ilk durum görüldü. Gerçek bir çözümde bu durumlar için ayrı kontrol eklenmesi gerekir.
- Derste alternatif bir tasarım da dile getirildi: düğümde yalnız çocuk ve kardeş işaretçileri tutup alt dizinlere inildikçe üst dizinleri bir yığında (stack) saklamak. Bu da geçerli bir çözüm yolu olarak kabul edildi; önemli olan aynı dizindeki dizinleri ve hiyerarşiyi doğru ifade edebilmektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
