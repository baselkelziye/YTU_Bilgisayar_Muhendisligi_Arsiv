# Ders 25 Çalışma Özeti

## Genel Konular

- Uygulama problemi: acil servis hasta kuyruğu
  - Bu oturum bir uygulama (lab) oturumudur; yeni konu anlatılmadı, struct, bağlı liste, dinamik bellek ve dosya işlemleri hazır yazılmış bir program üzerinden pekiştirildi.
  - Hastaların ad, soyad, T.C. kimlik numarası, yaş ve öncelik bilgisi tutulur. Vakalar acil (öncelikli) ve normal olarak ikiye ayrılır (ekrandan, 00:10:00).
  - Kurallar: normal hasta kuyruğun sonuna eklenir (FIFO); öncelikli hasta listedeki son öncelikli hastanın arkasına, hiç öncelikli hasta yoksa listenin başına eklenir; vazgeçen hasta adıyla kuyruktan çıkarılır; kuyruk bilgisi dosyada tutulur ve istenince dosyadan okunur.
  - Ekrandaki örnek: 1, 2, 3, 4, 5 normal hastalar; 6 öncelikli gelince 6, 1, 2, 3, 4, 5; ardından öncelikli 7 gelince 6, 7, 1, 2, 3, 4, 5; 3 silinince 6, 7, 1, 2, 4, 5.
- Modüler program yapısı
  - Program üç dosyaya bölündü: yapı tanımlarının olduğu `struct_patient.h`, dosya işlemlerinin olduğu `file_opr.c` ve `main` ile liste işlemlerinin olduğu `uygulama.c` (ekrandan, 00:15:00).
  - Amaç hem görülen konuları (struct, dosya işlemleri, bağlı liste) birlikte kullanmak hem de programı birden fazla modülden kurmaktır.
- Veri yapıları
  - `Patient`: ad, soyad, ID (string), yaş ve öncelik (`prior`, öncelikli ise 1, değilse 0) alanları.
  - `Patient_Node`: bir `Patient` verisi (`data`) ve sonraki düğümü gösteren `next` işaretçisi.
- Dosya işlemleri (`fread`/`fwrite`)
  - Kuyruk her değişiklikten sonra baştan sona `fwrite(&(var_head->data), sizeof(Patient), 1, fs)` ile dosyaya yazılır (ekrandan, 00:15:00).
  - Okuma `while(fread(&patient, sizeof(Patient), 1, fs))` döngüsüyle yapılır; her okunan kayıt `patient.name` gibi nokta işleciyle yazdırılır.
  - `fread(void *buffer, size_t size, size_t count, FILE *stream)`: verinin konacağı adres, bir elemanın bayt boyu, okunacak eleman sayısı ve dosya işaretçisi.
- Ana menü
  - `while(choose > 0)` döngüsünde 1 ekleme, 2 adla silme, 3 dosyadan listeleme, 0 çıkış; seçim `switch` ile değerlendirilir (ekrandan, 00:35:00).
- Ekleme fonksiyonu `insert_patient_to_list`
  - Liste boşsa yeni düğüm doğrudan baş olur.
  - Öncelikli hasta için listede son öncelikli düğüm (`last_prior`) bulunur; `last_prior` başlangıçta baştır. Baş hâlâ `last_prior` ve başın önceliği yoksa yeni hasta yeni baş olur; aksi hâlde `last_prior`'ın arkasına araya eklenir.
  - Önceliksiz hasta için `next` NULL olana kadar ilerlenip son düğüme eklenir.
- Silme fonksiyonu `delete_patient`
  - Liste `strcmp` ile adla taranır, eşleşen düğüm `patient` işaretçisinde tutulur.
  - Silinen baş ise `(*head) = (*head)->next`; bulunamadıysa mesaj verilir; değilse ikinci döngüyle önceki düğüm bulunur, `var_head->next = var_head->next->next` yapılır ve `free(patient)` çağrılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- İki döngüye gerek yok
  - Arama sırasında geçerli düğümle birlikte bir önceki düğüm de bir işaretçide tutulursa önceki düğümü bulmak için ikinci döngüye gerek kalmaz.
- Baş işaretçisi neden çift işaretçiyle gönderiliyor
  - Silme (ve ekleme) sırasında baş değişebilir. Değişikliğin çağırana yansıması için ya yeni baş `return` edilmeli ya da başın adresi (çift işaretçi) gönderilmelidir. Tek işaretçiyle gönderilen baş fonksiyon içinde değişse bile çağırandaki değer değişmez.
- Bağlı liste mantığını kâğıt üzerinde çizerek kurmak
  - Bağlı liste ve ikili ağaç gibi yapılarda önce düğümler ve bağlar kâğıda çizilmeli, kod sonra yazılmalı. İşaretçi ve düğüm mantığı sonraki veri yapıları dersinin ve gömülü sistemler gibi alanların temelidir.
- Adla silmenin zayıflığı
  - Aynı adlı birden fazla hasta olabileceği için silme işlemi T.C. kimlik numarası gibi benzersiz bir alanla yapılsa daha doğru olurdu.

## Kısa Tekrar Notları

- Normal hasta: listenin sonuna. Öncelikli hasta: son öncelikli hastanın arkasına, yoksa başa.
- `last_prior` başlangıçta baştır; baş önceliksizse yeni öncelikli hasta yeni baş olur.
- Araya ekleme: `temp = last_prior->next; last_prior->next = new_node; new_node->next = temp;`
- Başa ekleme: `temp = *head; *head = new_node; new_node->next = temp;`
- Silme: önceki düğümün `next`'i silinenin `next`'ine bağlanır, sonra `free`.
- `fread`/`fwrite` dörtlüsü: adres, `sizeof(Patient)`, 1, dosya işaretçisi.
- Baş değişebiliyorsa `Patient_Node **head` kullanılır ya da yeni baş döndürülür.
- Her işlemde dosyadan okumak verimli değildir; burada yalnız dosya işlemlerini göstermek için yapıldı.

## Detaylı Açıklamalar

- Ekleme algoritmasının ayrıntısı
  - Ekranda görünen kodda öncelik arama döngüsü `while(var_head != NULL)` içinde önceliği sıfırdan farklı her düğümü `last_prior`'a atar (ekrandan, 00:20:00). Öncelikli hastalar hep listenin önünde biriktiği için bu döngü son öncelikli hastayı verir.
  - Döngüden sonra `last_prior == (*head)` ise iki durum vardır: başın önceliği yoksa listede hiç öncelikli hasta yoktur ve yeni hasta başa konur; başın önceliği varsa baştaki tek öncelikli hastanın arkasına eklenir. `last_prior` baş değilse yine `last_prior`'ın arkasına eklenir (ekrandan, 00:25:00).
  - Bu kontrol yapılmasaydı öncelikli hasta önceliksiz bir başın arkasına eklenir ve "önceliksiz, öncelikli, önceliksiz..." gibi yanlış bir sıra oluşurdu.
- Silme algoritmasının ayrıntısı
  - İlk döngü listenin tamamını dolaşıp adı eşleşen düğümü bulur. İkinci döngü `while(var_head->next != patient)` ile silinecek düğümün bir öncesine kadar ilerler; sonra önceki düğüm silinecek düğümün sonrakine bağlanarak düğüm aradan çıkarılır (ekrandan, 00:40:00).
  - Ders sonrası not: Ekrandaki kodda silinen düğüm baş ise `free` çağrılmıyor; ayrıca liste boşken `patient` ve `*head` ikisi de NULL olduğu için `(*head)->next` erişimi programı çökertir. İlk döngüde `break` olmadığından aynı adlı birden fazla hasta varsa sonuncusu silinir. Bunlar kod üzerinden görülen noktalardır, derste konuşulmadı.
- Dosya okuma fonksiyonu `read_File`
  - Dosya `fopen("list.txt", "rb")` ile açılır, açılamazsa mesaj verilip `exit(0)` çağrılır; `fread` 1 döndürdükçe kayıtlar okunup ad, soyad, ID, yaş ve öncelik yazdırılır, sonunda `fclose` yapılır (ekrandan, 00:15:00).
- Öğrencinin proje sorusu
  - Birden fazla dosyadan (öğrenci, ders vb.) oluşan bir projede yapılar arasında bağlı liste kurmaya gerek olup olmadığı soruldu. Cevap: her dosya için bir struct yeterli; ID'ler üzerinden eşleşme yapılır, ekleme ve silmede olmayan bir kaydın eklenmemesine dikkat edilir. Yapılar arasında doğrudan bağ kurmak nesneye yönelik dillerdeki kadar kolay değildir ve ekstra yük getirir; ancak listeleme yaparken bir derse ait kayıtları struct'lara çekip birleştirmek kullanılabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
