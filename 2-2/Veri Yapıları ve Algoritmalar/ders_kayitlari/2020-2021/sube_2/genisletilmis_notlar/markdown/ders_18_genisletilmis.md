# Ders 18 Genişletilmiş Notu: Ağaçla Dizin Simülasyonu: mkdir, chdir, rmdir, dir ve count Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Akışı ve Problem
- 2. Düğüm Yapısı ve Ağacın Gösterimi
- 3. mkdir: Yeni Dizin Oluşturma
- 4. chdir: Dizinler Arasında Gezinme
- 5. rmdir: Dizin Silme
- 6. dir ve count
- 7. Soru-Cevap ve Alternatif Tasarım
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Akışı ve Problem

Bu oturum dersin uygulama saatiydi ve üç grup birlikte katıldı. Yeni bir konu anlatılmadı; daha önceki uygulama saatinde tanıtılan ağaçla dizin (klasör) sistemi simülasyonu probleminin örnek çözümü, kod parçaları ve ağaç şekilleri içeren slaytlarla adım adım incelendi. Kayıt Zoom üzerinden yapıldı; oturumu dersin asistanı yürüttü, PowerPoint slaytlarını paylaştı ve şekiller üzerinde kalemle çizim yaptı.

Problemde beş komutu gerçekleyen bir program yazılır:

- `mkdir name`: bulunulan dizinin altında yeni bir dizin oluşturur.
- `chdir name`: var olan dizinler arasında hareket eder (`..` ile bir üst dizine çıkılır, ad verilirse o alt dizine inilir).
- `rmdir name`: bir dizini siler.
- `dir`: bulunulan dizindeki alt dizinleri listeler.
- `count`: bulunulan dizinde kaç alt dizin olduğunu söyler.

## 2. Düğüm Yapısı ve Ağacın Gösterimi

Programın temeli bir ağaç düğümüdür. Düğümün dizinin adını tutan bir `name` alanı, hiyerarşiyi kurmak için de `left`, `right` ve `parent` işaretçileri vardır. Slaytta bir düğümün `left` ile alttaki bir düğüme bağlandığı, alttaki düğümün de `parent` ile yukarıdakine geri bağlandığı gösterildi (ekrandan, 00:15:00).

Bir dizinin istenen sayıda alt dizini olabilir, ama düğümde yalnız iki çocuk işaretçisi vardır. Bir öğrenci bu noktayı sordu:

**Soru:** Bir dizinin birden fazla alt dizini olursa daha fazla çocuk işaretçisine ihtiyaç olmayacak mı?

**Cevap:** Hayır; devam eden yapıda görüleceği gibi alt dizinler yatayda birbirine bağlanır.

Tasarımda iki yön farklı anlam taşır:

- Aşağı inmek (`left`): o dizinin altındaki dizinlere, yani bir alt seviyeye geçmek demektir. `left` her zaman dizinin ilk alt dizinini gösterir.
- Yatayda ilerlemek (`right`): aynı dizindeki, aynı seviyedeki bir sonraki dizine geçmek demektir.

Bu, çoklu ağacın ilk çocuk / sonraki kardeş gösterimidir. Örnek ağaç (ekrandan, 00:25:00):

```text
root
  dir1
  dir2
    abc
  dir3
```

İşaretçilerle gösterimi:

```text
root
 | left
dir1 --right--> dir2 --right--> dir3
                 | left
                abc
```

`parent` işaretçisi bu çözümde "beni işaret eden düğüm" anlamındadır. Bir dizinin ilk alt dizininin `parent` alanı gerçek üst dizindir (`dir1` için `root`, `abc` için `dir2`). Sonraki kardeşlerin `parent` alanı ise solundaki kardeştir (`dir2` için `dir1`, `dir3` için `dir2`). Bu ilişki `mkdir` kodundan doğar ve `chdir ..` ile `rmdir` kodları buna dayanır.

## 3. mkdir: Yeni Dizin Oluşturma

### 3.1 Ağacın (dizinin) boş olduğu durum

Bulunulan dizinin hiç alt dizini yoksa `left` alanı `NULL`'dır. Bu durumda yeni düğüm bu `left` alanına oluşturulur (ekrandan, 00:15:00):

```c
if(node->left == NULL){
        create_new_node(node->left, name);
        node->left->parent = node;
}
```

İlk satırla üst düğüm yeni düğümü tanır: `node->left` artık bir dizini temsil eder. Ama yeni düğüm kendi üst düğümünün kim olduğunu bilmez. İkinci satır bu bağlantıyı kurar: bulunulan dizinin `left`'indeki düğümün `parent` alanı, bulunulan dizine eşitlenir. Böylece ilişki iki yönlü tanımlanmış olur.

> **Hocanın vurgusu:** Yeni bir düğüm eklemek yetmez; yeni düğümün `parent` bağlantısı da ayrıca kurulmalıdır. Aksi halde yeni düğüm üstünün kim olduğunu bilmez.

> **Ek bilgi (derste anlatılmadı):** Slayttaki `create_new_node(node->left, name)` çağrısı C'de işaretçinin değerini kopyalayarak geçirir; fonksiyonun `node->left` alanını gerçekten değiştirebilmesi için ya adresinin (`&node->left`) verilmesi ya da yeni düğümün döndürülüp atanması gerekir. Slayt fikri göstermek için bu ayrıntıyı atlamıştır.

### 3.2 Aynı adda dizin olup olmadığını kontrol etme

Dizin boş değilse `else` dalına girilir. Örnekte kökün altında `dir1`, `dir2`, `dir3` vardır ve `new` adlı bir dizin eklenmek istenir. Slayttaki kod (ekrandan, 00:20:00; gri gösterilen ilk kısım slayttaki gibi `parent` adıyla yazılmıştır):

```c
if(parent->left == NULL){
        create_new_node(parent->left, name);
        parent->left->parent = parent;
}
else {
        node = node ->left;
        while(node ->right != NULL){
                if(!strcmp(name, node ->name)){
                        printf(">%s file alredy exist!\n",name);
                        return;
                }
        node = node ->right;
        }
        if(!strcmp(name, node->name)){
                printf(">%s directory is alredy exist!\n",name);
                return;
        }
}
```

Adım adım izleme:

1. Kökteyken `root->left` `NULL` değildir (`dir1` vardır), `else`'e girilir. `node = node->left;` ile `node` artık `dir1`'dir.
2. `dir1->right` `NULL` değildir, döngüye girilir. `dir1` adı `new` ile aynı değil; `node = node->right;` ile `dir2`'ye geçilir.
3. `dir2->right` `NULL` değildir. `dir2` adı `new` değil; `dir3`'e geçilir.
4. `dir3->right` `NULL`'dır, döngüden çıkılır. Döngü `dir3`'ü kontrol etmeden bitmiştir.
5. Döngüden sonraki `if` son düğümü kontrol eder: `dir3` adı `new` ile aynı değil. Aynı olsaydı "bu dizin zaten var" denip fonksiyondan çıkılacaktı.

Asistan anlatırken bir an `dir3` için de döngü gövdesinin çalıştığını söyleyip hemen düzeltti: `dir3`'ün sağı `NULL` olduğu için döngü gövdesi çalışmaz, `dir3` döngüden sonraki `if` ile kontrol edilir.

### 3.3 Yeni düğümü sona ekleme

Ad hiçbir düğümle eşleşmezse yeni düğüm son kardeşin, yani `dir3`'ün sağına eklenir. Anlatıma göre bu kısım şu iki satırdan oluşur:

```c
create_new_node(node->right, name);
node->right->parent = node;
```

<!-- BELİRSİZ: Bu iki satırın gösterildiği slaydın karesi yok; satırlar anlatımdan ("create new node ile node'un right'ına ... ekledik", "right'da bulunan node'un parent'ı ... node'un kendisine eşit olacak") kuruldu. -->

İlk satırla `dir3` yeni düğümü tanır. İkinci satırla yeni düğümün `parent` alanı `dir3` olur. Yani sona eklenen dizinin `parent` alanı gerçek üst dizin değil, solundaki kardeştir.

## 4. chdir: Dizinler Arasında Gezinme

### 4.1 Bir üst dizine çıkma (`..`)

Örnekte `dir2`'nin altında `abc` dizini vardır ve şu an `abc`'de bulunulur; amaç bir üst dizin olan `dir2`'ye çıkmaktır (ekrandan, 00:25:00):

```c
if(!strcmp(name,"..") && node->parent!=NULL){
                while(node->parent->right == node){
                        node = node->parent;
                }
                node = node->parent;
}
return node;
```

Önce gelen parametrenin `..` olup olmadığı, sonra `node->parent`'ın `NULL` olup olmadığı kontrol edilir. Kökteyken üst dizin yoktur; `parent != NULL` koşulu "üst dizine gidilemez" durumunu yakalar.

`abc`'den çıkış:

1. `abc->parent` `dir2`'dir, `NULL` değil; `if`'e girilir.
2. `node->parent->right`, yani `dir2->right`, `dir3`'tür; `abc`'ye eşit değildir. Döngüye girilmez.
3. `node = node->parent;` ile `node` artık `dir2`'dir ve döndürülür.

`while` döngüsünün görevi, bulunulan düğüm bir kardeş zincirinin ortasındaysa önce zincirin başına geri gitmektir. Bir kardeşin `parent` alanı solundaki kardeş olduğundan, "solumdakinin sağı ben miyim" koşulu sağlandıkça sola gidilir. Zincirin ilk düğümüne gelince `parent` gerçek üst dizindir ve onun `right` alanı bu düğüm değildir; döngü biter ve son atama gerçek üst dizine çıkarır.

Örneğin `dir3`'teyken `..` verilirse (ara adım eklendi): `dir2->right == dir3` olduğu için `node = dir2`; `dir1->right == dir2` olduğu için `node = dir1`; `root->right` `dir1` olmadığı için döngü biter; `node = dir1->parent` ile köke çıkılır. Bu izleme ders sonrası C ile de doğrulandı.

### 4.2 Alt dizine inme

Kökteyken `dir2`'ye gidilmek istenir (ekrandan, 00:30:00):

```c
if(!strcmp(name,"..") && node->parent!=NULL){
                while(node->parent->right == node){
                        node = node->parent;
                }
                node = node->parent;
}
else{
        node = node->left;
        while(node->right != NULL && strcmp(node->name,name)){
                node = node ->right;
        }
        if(strcmp(name, node->name)){
                printf(">There is no such directoryt!\n");
        }
}
return node;
```

1. Ad `..` değil (ayrıca kökün `parent`'ı `NULL`), `else`'e girilir.
2. `node = node->left;` ile `dir1`'e inilir.
3. `dir1->right` `NULL` değil ve `dir1` adı `dir2` değil; `node = node->right;` ile `dir2`'ye geçilir.
4. `dir2` adı aranan adla aynı olduğu için döngü biter.
5. Son `if`'te ad eşleştiği için hata basılmaz; `dir2` döndürülür ve yeni dizin olur.

Kökün altında `dir1`, `dir2`, `dir3` olduğu için kökten doğrudan `dir2`'ye gidilebilir. Döngüden sonraki `if`'in görevi, `mkdir`'de olduğu gibi, döngü sağında `NULL` olan son düğümde durduğu için o düğümü de kontrol etmektir. Örneğin `dir56` aranırsa `dir3`'e kadar gidilir, `dir3`'ün sağı boş olduğu için döngüden çıkılır, son kontrolde ad eşleşmez ve "böyle bir dizin yok" mesajı basılır.

> **Ders sonrası not:** Slayttaki kodda aranan dizin bulunamazsa mesaj basılır ama fonksiyon yine son kontrol edilen düğümü (örnekte `dir3`) döndürür; bulunulan dizin istemeden o düğüme geçer. Ayrıca bulunulan dizinin hiç alt dizini yoksa `node = node->left;` sonrasında `node` `NULL` olur ve `node->right` okunması programı çökertir. Bu iki durum derste konuşulmadı; ilki ders sonrası C denemesinde görüldü. Tam bir çözümde bu durumlarda bulunulan dizin değiştirilmeden döndürülmelidir.

## 5. rmdir: Dizin Silme

Silme kodu slaytlar boyunca parça parça tamamlandı; her yeni slayt, önceki kısmı gri bırakıp yeni durumu ekledi.

### 5.1 Olmayan bir dizini silmeye çalışma

Kökteyken `dir56` silinmek istenir. Önce `chdir`'deki aynı arama yapılır: kökten bir alta inilir ve o seviyedeki bütün düğümler sırayla aranır. `dir1`, `dir2`, `dir3`, `dir4` adla eşleşmez; ad eşleşme `if`'ine girilmez, `else`'e düşülür ve kullanıcıya böyle bir dizinin olmadığı söylenir.

### 5.2 Alt dizini olan bir dizini silmeye çalışma

`dir2`'nin altında `abc` dizini vardır; normalde bu dizin silinememelidir. Arama `dir2`'yi bulur, ad eşleşme `if`'ine girilir ve önce `node->left` kontrol edilir. Bu tasarımda `left` bir alt dizin demektir; `dir2->left` doludur (`abc`), bu yüzden "dizin boş olmalı" mesajı basılır ve fonksiyondan çıkılır.

### 5.3 Alt dizini olmayan bir dizini silme: üç durum

Alt dizini olmayan bir dizin silinirken üç durum vardır:

- Silinen dizin üst dizine bağlı ilk düğümdür (örnekte `dir1`).
- Silinen dizin arada bir düğümdür; solunda ve sağında düğüm vardır (örnekte `dir3`). Aradaki her düğüm aynı şekilde ele alınır.
- Silinen dizin zincirin sonundadır; sağı `NULL`'dır (örnekte `dir4`). Bu durumda yalnız solundaki düğümün `right` alanı `NULL` yapılır.

Tam kod (ekrandan, 00:35:00 ve 00:40:00):

```c
node = node ->left;
while(node->right != NULL && strcmp(node->name,name)){
                node = node->right;
}
if(!strcmp(name,node->name)){
        if(node->left != NULL){
                printf(">The directory must be empty\n");
                return;
        }
        if(node->parent->left == node){
                if(node->right == NULL){
                        node->parent->left = NULL;
                }
                else{
                        node->parent->left = node->right;
                        node->right->parent = node->parent;
                }
        }
        else if(node->right==NULL){
                node->parent->right = NULL;
        }
        else{
                node->parent->right = node->right;
                node->right->parent = node->parent;
        }
}
else{
        printf("> There is no such directoryt!\n ");
}
```

Örnek ağaç (ekrandan, 00:35:00):

```text
root
 | left
dir1 -- dir2 -- dir3 -- dir4
         |
        abc
```

**İlk düğümü silme (`dir1`):** `dir1->parent` köktür ve kökün `left` alanı `dir1`'dir; `node->parent->left == node` sağlanır, yani baştan silme yapılır. Sonra `dir1`'in sağında düğüm olup olmadığına bakılır: sağında `dir2` vardır, `else`'e girilir. Kökün `left` alanı `dir1`'in sağındaki düğüme, yani `dir2`'ye bağlanır; `dir2`'nin `parent` alanı da köke eşitlenir. Böylece kök doğrudan `dir2`'yi gösterir ve `dir1` ağaçtan çıkar. Sağında düğüm olmasaydı kökün `left` alanı `NULL` yapılacaktı.

**Ara düğümü silme (`dir3`):** `dir3`'ün `parent` alanı `dir2`'dir ve `dir2`'nin `left` alanı `dir3` değildir (`abc`'dir); ilk durum sağlanmaz. `dir3`'ün sağı da boş değildir, son `else`'e girilir. `node->parent->right = node->right;` ile `dir2`'nin sağı `dir4` olur. `node->right->parent = node->parent;` ile `dir4`'ün `parent` alanı `dir3` yerine `dir2` olur. Böylece `dir2`–`dir3` ve `dir3`–`dir4` bağları koparılmış, yerine `dir2`–`dir4` bağı kurulmuştur.

**Son düğümü silme (`dir4`):** Bu aşamada ağaçta kökün altında `dir2` (altında `abc`) ve onun sağında `dir4` kalmıştır (ekrandan, 00:40:00). `dir4`'ün sağı `NULL`'dır; `else if (node->right == NULL)` dalına girilir ve `node->parent->right = NULL;` ile `dir2`'nin sağı boşaltılır. Sonuçta kökün altında yalnız `dir2` kalır.

Ders sonrası C denemesinde bu üç silme sırayla uygulandığında listeler `dir2, dir3, dir4`, sonra `dir2, dir4`, en sonda yalnız `dir2` oldu; `dir1` silindikten sonra `dir2`'nin `parent` alanı kök, `dir3` silindikten sonra `dir4`'ün `parent` alanı `dir2` olarak bulundu.

**Soru:** Burada silinen düğümü `free` etsek daha iyi olmaz mı?

**Cevap:** Evet, öyle yapılabilir. Düğüm ağaçtan çıkarıldığı için bellekteki alanı da serbest bırakılabilir. Son düğüm silinirken de aynı şey hatırlatıldı.

## 6. dir ve count

### 6.1 dir

Kökteyken kökün altındaki dizinler listelenir (ekrandan, 00:45:00):

```c
if(node->left == NULL){
        printf(">there is no directory!\n");
}
else{
        node = node->left;
        printf(">");
        while(node != NULL){
                printf("%s\n",node->name);
                node=node->right;
        }
}
```

Kökün `left` alanı `NULL` olsaydı dizin boştur ve kullanıcıya "dizin yok" yazılırdı. Örnekte `dir1` vardır; `else`'e girilir, `node` `dir1` olur. `node` `NULL` olmadığı sürece adı basılıp sağa geçilir: `dir1`, `dir2`, `dir3` basılır. Kökün altında üç dizin vardır ve üçü de doğru basılmıştır. Burada döngü koşulu `node != NULL` olduğu için son düğüm de döngünün içinde işlenir; ayrı bir son kontrol gerekmez.

### 6.2 count

`count` aynı mantıkla çalışır. Ad basmak yerine bir tamsayı sayaç tanımlanır ve her düğümde bir artırılır; sonunda sayacın değeri basılır. Örnekte `dir1`'de sayaç 1, `dir2`'de 2, `dir3`'te 3 olur ve 3 basılır.

<!-- BELİRSİZ: count slaydının karesi yok; kod yalnız anlatımdan biliniyor (dir koduyla aynı dolaşma, ad yerine "counter" adlı tamsayı sayaç). -->

> **Hocanın vurgusu:** `dir` komutunu yapan biri `count`'u da yapabilmelidir; ikisi aynı dolaşmadır, fark yalnız ad basmak yerine sayaç artırmaktır.

## 7. Soru-Cevap ve Alternatif Tasarım

Anlatımdan sonra bir öğrenci yapıyı tekrar sordu.

**Soru:** Bu yapıda `dir2`'nin `parent`'ı `dir1` mi?

**Cevap:** İlk cevapta hayır, kök olduğu söylendi; `dir1`, `dir2`, `dir3` hepsi kökün altındadır, `abc` ise `dir2`'nin altındadır. Örneğin `abc`'nin yanına yeni bir düğüm eklenseydi o da `dir2`'nin altında olurdu: aşağı inildikçe dizin derinleşir, yatayda aynı seviyedeki dizinler görülür.

<!-- BELİRSİZ: Soru altyazıda bozuk ("Dirk'in parent'ı Dirk 1 mi?"); bağlamdan dir2'nin parent alanı soruluyor. -->

Öğrenci `rmdir`'de ortadaki bir düğüm silinirken neden `parent` kullanıldığını sorunca `chdir ..` kodu `dir2` örneğiyle tekrar izlendi ve bu kez `dir2`'nin `parent` alanının `dir1` olduğu söylendi. Asistan, bütün dizinlerin doğrudan köke bağlanmadığını, bu yapıda `parent` alanının düğümü işaret eden düğüm olduğunu belirtti.

> **Ders sonrası not:** İlk cevaptaki "dir2'nin parent'ı kök" ifadesi ağaç anlamında (dir2 kökün alt dizinidir) doğrudur, ama slayttaki kodla kurulan yapıda `dir2->parent` alanı `dir1`'dir. Kod düzeyinde doğru olan ikinci cevaptır (C ile denendi).

Bir öğrenci farklı bir yol izlediğini anlattı: düğümde tek yönlü olarak yalnız çocuk (child) ve kardeş (sibling) işaretçileri tutmak, alt dizinlere inildikçe üst dizinleri bir yığında (stack) saklamak. Cevap olarak, aynı dizindeki dizinleri ve hiyerarşiyi doğru ifade eden her yapının kabul edilebileceği, her çözümden daha iyi bir çözüm bulunabileceği, ama slayttaki yapının kendi tasarımına göre doğru çalıştığı söylendi. Oturumun sonunda da yığın kullanımının farklı ve geçerli bir çözüm yolu olduğu tekrarlandı.

> **Ek bilgi (derste anlatılmadı):** Yığınlı tasarımda `chdir name` ile inerken bulunulan düğüm yığına itilir, `chdir ..` ile yığından çekilerek üst dizine dönülür; böylece düğümde `parent` alanı tutmaya gerek kalmaz. Buna karşılık `rmdir` sırasında silinen düğümün solundaki kardeşi bulmak için zincirin başından dolaşmak gerekir.

Son olarak programın tek bir örnekle denenip bırakılmaması önerildi: köke bir dizin eklemek doğru çalışırken iki ya da üç dizin eklendiğinde hata veren çözümler görüldü. Test durumları arttıkça programın doğruluğundan daha çok emin olunur.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:28:00): `chdir` ile alt dizin aranırken döngüde düğüm bulunduğu halde döngüden sonra ad neden bir kez daha karşılaştırılıyor?

> **Çözüm (derste verildi):** Döngü, düğümün sağı `NULL` olduğunda da biter; yani aranan ad hiç bulunmadan zincirin sonuna gelinmiş olabilir. Ayrıca döngü sağı `NULL` olan son düğümü (örnekte `dir3`) gövdede kontrol etmez. Bu yüzden döngüden sonra son durulan düğümün adı tekrar karşılaştırılır.

**Soru 2** (derste sözlü, 00:29:11): Kökteyken `dir2` yerine olmayan bir dizin, örneğin `dir56`, aranırsa ne olur?

> **Çözüm (derste verildi):** `dir1`, `dir2`, `dir3` sırayla kontrol edilir. `dir3`'ün sağı `NULL` olduğu için döngüden çıkılır. Son kontrolde `dir3` adı `dir56` ile eşleşmez ve kullanıcıya "böyle bir dizin yok" mesajı basılır. (Fonksiyonun bu durumda `dir3`'ü döndürmesi için bölüm 4.2'deki ders sonrası nota bakın.)

**Soru 3** (derste sözlü, 00:36:56): Kökün altında `dir1 -- dir2 -- dir3 -- dir4` varken `dir1` silindi: kökün `left` alanı `dir2`'ye bağlandı ve `dir2`'nin `parent` alanı kök yapıldı. Bu işlemde eksik ya da hatalı bir şey var mı?

> **Çözüm (derste verildi):** Bağlantılar doğrudur. Eklenebilecek şey, ağaçtan çıkarılan `dir1` düğümünün belleğinin `free` ile serbest bırakılmasıdır.

**Soru 4** (derste sözlü, 00:44:07): Örnek ağaçta `abc`'nin sağına yeni bir düğüm eklenseydi bu düğüm hangi dizinin altında olurdu?

> **Çözüm (derste verildi):** `dir2`'nin altında. `abc` ile yeni düğüm aynı yatay zincirdedir ve bu zincirin başı `dir2`'nin `left` alanına bağlıdır.

## Dersin Toparlaması

Bu uygulama saatinde çok çocuklu bir dizin ağacının `left` (ilk alt dizin) ve `right` (sonraki kardeş) işaretçileriyle, ek olarak düğümü işaret eden düğümü tutan bir `parent` işaretçisiyle nasıl kurulacağı, beş komutun kodu üzerinden izlendi. `mkdir` yeni düğümü boş dizinde `left`'e, dolu dizinde zincirin sonuna ekler ve her seferinde `parent` bağlantısını kurar. `chdir ..` kardeşler boyunca sola geri gidip gerçek üst dizine çıkar; alt dizine inmek ise zincirde ad aramaktır. `rmdir` alt dizini olan dizini reddeder, alt dizini olmayanı ilk, ara ve son düğüm durumlarına göre bağlantıları yeniden kurarak çıkarır. `dir` ve `count` aynı zincir dolaşmasının iki kullanımıdır.

Bütün aramalarda ortak bir desen vardır: `while (node->right != NULL ...)` döngüsü son düğümü gövdede işlemediği için döngüden sonra ayrı bir kontrol gerekir. Düğüm sildikten sonra belleği serbest bırakmak, bulunamayan ve boş dizin gibi uç durumları ayrıca ele almak ve programı birden fazla girdiyle denemek, çözümün doğru çalışmasını sağlayan tamamlayıcı adımlardır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
