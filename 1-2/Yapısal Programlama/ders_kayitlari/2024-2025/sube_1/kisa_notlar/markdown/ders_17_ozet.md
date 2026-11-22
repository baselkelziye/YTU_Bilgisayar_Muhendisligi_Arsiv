# Ders 17 Çalışma Özeti

## Genel Konular

- Uygulama dersi: dosya işlemleri ve bağlı liste
  - Ders bir laboratuvar uygulamasıdır. İki soru çözüldü: birincisi canlı olarak satır satır yazıldı, ikincisi hazır çözüm kodu üzerinden anlatıldı.
  - Ortak kalıp: bir metin dosyasındaki her satır bir `struct` düğümüne dönüştürülür, düğümler bağlı listede tutulur, liste sıralanır, ekrana yazılır ve yeni dosyalara yazılır.
- Dosya açma ve kapatma
  - `FILE *fp = fopen(ad, "r");` dosyayı okuma modunda açar. Yazmak için `"w"` modu kullanılır.
  - `"w"` modunda dosya yoksa sıfırdan oluşturulur, varsa içi boşaltılıp baştan yazılır.
  - Okunacak dosya, programın çalıştığı klasörde (kaynak kodun bulunduğu klasörde) olmalıdır. Derste dosya başka klasörde kaldığı için program ilk denemede çalışmadı.
  - İş bitince dosya `fclose(fp)` ile kapatılır.
  - Dosya açılamazsa (yoksa ya da erişim izni yoksa) `fopen` `NULL` döner; bu durumda hata mesajı yazılır.
- Soru 1: virgülle ayrılmış personel kayıtları (ID, ad, departman)
  - Düğüm yapısı: `int ID; char Name[50]; char Department[20]; struct data *next;` (ekrandan, 00:15:00).
  - Satır okuma: `fgets(buf, 255, fp)`; dosya sonunda ya da boş dosyada `NULL` döner.
  - Satırı parçalama: `strtok(buff, delimiter)` ilk parçayı verir, sonraki parçalar için ilk argüman `NULL` yazılır.
  - Tür dönüşümü: `atoi` metni tamsayıya çevirir (okurken); `itoa` tamsayıyı metne çevirir (yazarken).
  - Son parçanın sonundaki satır sonu karakteri `token[strlen(token)-1] = '\0';` ile silinir (ekrandan, 00:25:00).
  - Liste ID'ye göre azalan ve artan sırada sıralanıp iki ayrı dosyaya yazılır.
- Fonksiyon işaretçisi ile genel sıralama
  - `data* Sort_Data(data* head, int (*Sort_Condition)(int,int))` sıralama ölçütünü parametre olarak alır (ekrandan, 00:45:00).
  - `Sort_Ascending` `first<second`, `Sort_Descending` `first>second` döndürür (ekrandan, 01:00:00).
  - Sıralama, özyinelemeli bir seçmeli sıralamadır (selection sort): ölçüte göre en uç düğüm bulunur, listeden çıkarılır, başa konur ve kalan liste aynı fonksiyonla sıralanır.
- Dosyaya yazma fonksiyonları
  - `fputs` metni, `fputc` tek karakteri dosyaya yazar. Aynı iş `fprintf` ile de yapılabilir.
- Soru 2: uçuş bilgileri ve pist dosyaları
  - Her satır: 4 haneli uçuş kodu, kalkış şehri, varış şehri, saat, iç/dış hat bilgisi (0: iç hat, 1: dış hat), pist numarası (ekrandan, 01:20:00).
  - Uçuşlar dosyadan okunurken uçuş koduna göre küçükten büyüğe sıralı biçimde listeye eklenir; ayrıca sıralama gerekmez.
  - Her pist için `pistN.txt` adlı bir dosya açılır ve o pisti kullanan uçuşlar bu dosyaya yazılır.
  - Satırlar boşlukla ayrıldığı için `strtok` gerekmez; okuma biçimli girişle yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- `strtok` ilk çağrıda tampon dizisiyle, sonraki çağrılarda `NULL` ile çağrılır
  - İlk çağrı ayrıştırılacak metni verir; `NULL`, aynı metnin kaldığı yerden devam edilmesini sağlar.
- Dosyadan okunan her şey metindir
  - ID dosyada metin olarak durur. Okurken `atoi` ile tamsayıya, yazarken tamsayıdan metne çevrilmesi gerekir.
- Bağlı listede son düğümün `next` alanı `NULL` yapılır
  - Listenin sonu bu şekilde belli olur; yazdırma ve dolaşma döngüleri `NULL` görünce durur.
- `head`'i doğrudan değiştirmemek için geçici işaretçi kullanılır
  - Listeyi dolaşırken `current` gibi bir işaretçi kullanılır; böylece listenin başını gösteren işaretçi bozulmaz.
- Uzun kodda takip
  - Sıralama gibi uzun kodlarda nerede kalındığını takip etmek önemlidir; asistan öğrencilerden yazdığı kodu birlikte izlemelerini ve gördükleri hataları söylemelerini istedi.

## Kısa Tekrar Notları

- `fopen(ad, "r")` okuma, `fopen(ad, "w")` yazma; `"w"` dosyayı oluşturur ya da içini siler.
- `fgets(buf, 255, fp)` bir satır okur, bitince `NULL` döner.
- `strtok(buf, ",")` ilk parça, `strtok(NULL, ",")` sonraki parçalar.
- `atoi`: metin → tamsayı. `itoa`: tamsayı → metin (standart dışı; `sprintf` taşınabilir seçenek).
- `fputs` metin, `fputc` karakter yazar; `fprintf` ikisinin işini görür.
- Liste kurulurken `prev->next = curr; prev = curr;`, sonda `prev->next = NULL`.
- Fonksiyon işaretçisi: `int (*kosul)(int,int)`; çağrı `kosul(a, b)`.
- Sıralı ekleme: liste boşsa ya da yeni kod baştakinden küçükse başa; değilse `current->next->kod < yeni->kod` olduğu sürece ilerle, sonra araya ekle.
- Başı değişebilen fonksiyona `Flight** head` (işaretçinin adresi) verilir.
- Pist dosyaları: `FILE* files[10] = { NULL };`, ad `snprintf(ad, sizeof(ad), "pist%d.txt", pist)`.

## Detaylı Açıklamalar

- Soru 1'in akışı
  - `File_Read` dosyayı açar, ilk satırı `fgets` ile okur. Satır varsa ekrana yazar ve `Split_Data` ile ilk düğüme (`head`) ayrıştırır; dosya boşsa `NULL` döner. Sonra `while (fgets(...) != NULL)` döngüsünde her satır için `malloc` ile yeni düğüm açılır, önceki düğümün `next`'ine bağlanır, `Split_Data` ile doldurulur ve `prev_data = curr_data` yapılır. Döngüden sonra son düğümün `next`'i `NULL` yapılır, dosya kapatılır ve `head` döndürülür (ekrandan, 00:40:00).
  - `Split_Data(data* holder, char buff[255], char delimiter[2])` üç parçayı sırasıyla alır: ID `atoi` ile, ad `strcpy` ile, departman satır sonu silindikten sonra `strcpy` ile düğüme yazılır.
  - `Print_List` `while (head != NULL)` ile listeyi dolaşır ve `ID: %d, Name:%s, Department:%s` biçiminde yazar.
  - `File_Write(data* head, char *File_Name, char delimiter)` dosyayı `"w"` ile açar; her düğüm için ID'yi `itoa(head->ID, tmp, 10)` ile metne çevirip `fputs` ile, ayırıcıyı `fputc` ile, adı ve departmanı `fputs` ile yazar; satır sonuna ayırıcı değil `'\n'` konur (ekrandan, 01:05:00).
  - `main` önce dosyayı okur ve yazdırır, sonra azalan sıralar, yazdırır ve `New_dataset_descending.txt` dosyasına yazar; ardından aynı işlemi artan sıra için yapar (ekrandan, 01:10:00).
- Özyinelemeli seçmeli sıralama
  - Liste boşsa ya da tek elemanlıysa olduğu gibi döner. Değilse ilk düğümün ID'si başlangıç uç değeridir; `prev`, `to_move` (uç düğümün bir öncesi) ve `tmp` (dolaşan işaretçi) ile liste taranır.
  - Uç değer baştaki düğümse `head->next = Sort_Data(head->next, ...)` yapılıp `head` döner. Değilse uç düğüm, öncülünün `next`'i bir sonrakine bağlanarak listeden çıkarılır, kalan liste özyinelemeli sıralanıp onun arkasına eklenir ve uç düğüm yeni baş olarak döner.
  - Derste ekranda yazılan sürümde birkaç hata vardı (kıyaslamada tanımsız `max`, sonuç kontrolünün döngünün içinde kalması, çıkarılan düğüm yerine öncülünün kullanılması). Çalıştırma, önceden hazırlanmış çözüm dosyasıyla yapıldı.
  - Ders sonrası not: ajan, aynı mantığın düzeltilmiş bir sürümünü `gcc -Wall` ile derleyip küçük bir örnek dosyayla denedi; azalan ve artan sıralama doğru çalıştı. Tam kod genişletilmiş nottadır.
- Soru 2'nin akışı
  - `createFlight` düğüm için `malloc` ile yer açar, tamsayı alanlarını `=` ile, metin alanlarını `strcpy` ile doldurur, `next`'i `NULL` yapar ve düğümün adresini döndürür (ekrandan, 01:45:00).
  - `insertFlight(Flight** head, Flight* newFlight)` sıralı ekleme yapar. Ekrandaki açıklama örneği: liste 1001 → 2005 → 3050 ve yeni kod 2500 ise `current` 1001 iken sonraki 2005 < 2500 olduğu için ilerlenir; `current` 2005 iken sonraki 3050 < 2500 olmadığı için döngü biter ve yeni düğüm 2005 ile 3050 arasına girer (ekrandan, 01:45:00).
  - `displayFlights` `current` işaretçisiyle listeyi dolaşıp her uçuşu bir satırda yazar (ekrandan, 01:50:00).
  - `writeFlightsToFiles` 10 elemanlı `FILE*` dizisini `NULL` ile başlatır; her uçuş için dosya adını `snprintf` ile kurar, o pistin dosyası henüz açılmamışsa `"w"` ile açar ve uçuşu `fprintf` ile yazar; sonunda açık dosyaları kapatır.
  - `main` içinde liste başı `Flight* flightList = NULL;` ile boş liste olarak başlatılır.
  - Örnek girdi ve beklenen çıktı ekrandaki soru metnindedir (ekrandan, 01:40:00): sıralı liste 1012, 1015, 2013, 3001; `pist1.txt` içinde 1012 ve 3001, `pist2.txt` içinde 1015, `pist8.txt` içinde 2013 bulunur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
