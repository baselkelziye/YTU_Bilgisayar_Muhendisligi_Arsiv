# Ders 6 Çalışma Özeti

## Genel Konular

- Yüksek Uyum (*High Cohesion*) Özeti ve Tasarım Kalıpları (*Design Patterns*)
  - **Yüksek uyumun yararları:** Sınıfın anlaşılma kolaylığının artması, yeniden kullanılabilirliğin (*reusability*) artması, bakım kolaylığının artması ve sınıfın değişikliklerden etkilenme olasılığının düşmesi (genellikle düşük bağlaşım yüksek uyumu, yüksek bağlaşım ise düşük uyumu beraberinde getirir) (ekrandan, 00:35:00).
  - **Tasarım Kalıpları (*Design Patterns*):** Kökeni bina mimarisine dayanan (ör. *"içinde en az yarım saat kesintisiz zaman geçirilecek her odanın en az bir penceresi olmalıdır"* kuralı), nesneye yönelik modelleme alanında sık karşılaşılan problemlere kanıtlanmış ve esnek çözüm önerileri sunan yapı şablonları (ekrandan, 00:35:00).
  - **Dörtlü Çete (*Gang of Four* — GoF) klasiği:** Erich Gamma, Richard Helm, Ralph Johnson ve John Vlissides tarafından yazılan ***Design Patterns: Elements of Reusable Object-Oriented Software*** (Addison-Wesley, 1994) kitabı (yaklaşık 23–24 temel tasarım kalıbı) (ekrandan, 00:35:00).
- Tasarım Sürecinin Belgelendirilmesi (Tasarım Yapıtları / *Artefacts*)
  - **Ayrıntılı UML Sınıf Şemaları (*Detailed Class Diagrams*):** Yazılacak kodun ana oyun planı olduğu için tasarım belgelendirmesinde **vazgeçilmez** (*zorunlu*) bileşen (ekrandan, 00:39:00).
  - Tasarımın ihtiyaçlarına göre kullanılan **seçimlik** belgeler: 1) **Sözleşmeler (*Contracts*)**, 2) **UML Etkileşim Şemaları (*Interaction Diagrams*)** — **Sıralama şemaları (*Sequence diagrams*)** ve **İşbirliği şemaları (*Collaboration diagrams*)**, 3) **UML Etkinlik Şemaları (*Activity Diagrams*)**, 4) **UML Durum Diyagramları (*State Diagrams*)** (ekrandan, 00:39:00).
- Sözleşme ile Tasarım (*Design by Contract*)
  - Kullanım senaryolarının kritik veya karmaşık metotlar düzeyinde ayrıntılandırılması; bir sözleşmenin **İşlem** (metot imzası), **Çapraz Başvurular** (ilişkili kullanım senaryosu), **Ön Koşullar** (tüm sistem hakkındaki durum bilgisi) ve **Son Koşullar** (yalnızca problem alanı nesnelerinin durum değişiklikleri: nesne oluşturulması, üye alan değerlerinin atanması ve nesneler arası ilişkilerin kurulması/kırılması; tamamlanmış eylem vurgusu için **edilgen geçmiş zamanla** yazılır) bölümlerinden oluşması (ekrandan, 01:00:00; ekrandan, 01:02:00).
  - *NextGenPOS* örneği: `Sözleşme No: 2 – Satış Kalemi Girişi`, `ürünGir(barkod: String, adet: integer)` sözleşmesi (ekrandan, 01:00:00).
- UML Sıralama Şemaları (*Sequence Diagrams*) Ayrıntıları
  - Nesneler arasındaki metot çağrımlarını zaman ekseninde (yukarıdan aşağıya) gösteren etkileşim şeması: **`nesne1: Sınıf1`** (altı çizili dikdörtgen), **yaşam çizgisi / *activation bar*** (düşey çubuk), **mesaj / metot çağırma** (`[koşul] değişken := birMetot(param1: Tip, ...)`), **geri dönüş** (kesikli ok), **koşullu mesaj** (`[koşul]`), **döngülü mesajlar** (`* [koşul]`), **nesne oluşturma** (`new`), **nesnenin kendi metodunu çağırması** (*self-call*) ve çoklu koşullu/döngülü mesajları gruplayan çerçeve (*frame*) gösterimi (ekrandan, 01:05:00).
- UML Etkinlik Şemaları (*Activity Diagrams*) ve *NextGenPOS* Uygulaması
  - Bir kullanım senaryosundaki denetim ve işlem akışını (koşullar, döngüler ve paralel/*multi-threaded* süreçler dahil) teknik olmayan paydaşların da anlayabileceği düzeyde gösteren şema türü (ekrandan, 01:20:00).
  - Temel bileşenler: **Etkinlik başlangıcı** (içi dolu siyah daire), **Sinyal alma / Olay (*event*) kabul etme** (sağ kenarı içbükey beşgen / bayrak, zamanlayıcı [*timer*] için de kullanılır), **Sinyal gönderme** (sağ kenarı dışbükey beşgen), **Eylem (*Action*)** (kenarları yuvarlatılmış dikdörtgen), **Karar verme (`if`)** (elmas `<>` ve köşeli parantezli `[koşul]` dalları), **Eşgüdüm (*Synchronization bar*)** (paralel süreçleri başlatan **çatallanma [*fork*]** ve tüm paralel kollar bitene kadar bekleyip birleştiren **birleşme [*join*]** kalın çubuğu) ve **Etkinlik sonu** (hedef tahtası / çember içinde siyah daire) (ekrandan, 01:20:00).
  - Havayolu **Check-in** örneği (ekrandan, 01:20:00), çoklu aktörleri sütunlara ayıran **Kulvarlar (*Swimlanes*)** ile aktörler arası nesne/veri akışı (`[yolcu listesi]`) örneği (ekrandan, 01:26:00) ve *NextGenPOS* **Satış İşlemi Etkinlik Şeması** (`3-7a` ürün silme alternatif senaryosunun `Bkz. Ürün iptali senaryosu` çerçevesiyle kapsanması) (ekrandan, 02:38:30).
- UML Durum Şemaları (*State Diagrams*)
  - Problem alanındaki önemli bir varlığın yaşam döngüsü boyunca bulunabileceği **durumları (*states*)** ve hangi **olay (*event*)** gerçekleştiğinde hangi durumdan hangisine geçeceğini gösteren şema türü (ekrandan, 01:40:00).
  - Gösterim kuralları: Başlangıç, Durum (yuvarlatılmış dikdörtgen), Bitiş ve **`«M» Olay [koşul] / Eylem;`** (*Mutate*) biçimindeki durum geçiş okları (veya durumu değiştirmeyen iç olayların durum kutusu içine yazılması) (ekrandan, 01:40:00; ekrandan, 01:44:00; ekrandan, 01:52:00).
  - Havayolu **Yolcu Uçağı Yaşam Döngüsü** örneği (`Sipariş aşamasında` $\rightarrow$ `Bakımda` $\leftrightarrow$ `Kullanıma hazır` $\rightarrow$ `Bakım sırası beklemede` $\rightarrow$ `Bakımda` $\rightarrow$ `Emekli edildi` ve `CREATE`, `SET`, `DELETE` komutları) (ekrandan, 01:40:00; ekrandan, 01:44:00; ekrandan, 01:52:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Sıralama Şeması (*Sequence Diagram*) ile İşbirliği Şeması (*Collaboration Diagram*) Karşılaştırması
  - Her iki etkileşim şeması da nesnelerin birbirlerinin metotlarını hangi sırada çağırdığını gösterir; ancak **İşbirliği şemaları** kompakt olmasına rağmen çağrı sırasını yalnızca oklar üzerindeki `1.1.1`, `1.1.2` gibi numaralarla gösterdiği için akışı zihinde canlandırmak zordur. **Sıralama şemaları (*Sequence diagrams*)** ise nesne sayısı arttıkça sağa doğru genişlese de, düşey eksen doğrudan zamanı temsil ettiği için hangi metodun hangisinin içinde ve hangi sırada çağrıldığını ilk bakışta net olarak gösterir ve sektörde çok daha fazla tercih edilir.
- Sıralama Şeması ile Sınıf Şeması Arasındaki Tutarlılık Kuralı
  - Sıralama şemasında `nesne1`'den `nesne2: Sınıf2`'ye doğru `birMetot()` çağrı oku çizilmişse, bu metot **`nesne1`'in değil, çağrıyı alan `nesne2`'nin (`Sınıf2`'nin) metodudur**; dolayısıyla tasarım sınıf şemasında `Sınıf2` kutusunun içinde `birMetot()` imzası mutlaka yer almalıdır (aksi hâlde ciddi bir tasarım hatası yapılmış olur) (ekrandan, 01:05:00).
  - Ayrıca iç içe metot çağrılarında zaman yukarıdan aşağıya ($y$ ekseninde) aktığı için, çağrılan alt metot oku ve geri dönüşü dış metot oklarıyla aynı hizada veya daha yukarıda olamaz; mutlaka düşey mesafe bırakılarak içeride çizilmelidir.
- Sözleşmelerde (*Contracts*) Son Koşulların Yazım Dili ve Kapsamı
  - Bir metot sözleşmesinde **Ön Koşullar** tüm sistem hakkındaki genel durumu ifade ederken, **Son Koşullar** yalnızca problem alanı nesnelerinin durum değişikliklerini (1. Hangi nesne oluşturuldu? 2. Hangi üye alana ne değer atandı? 3. Hangi nesneler arasında hangi sahiplik/ilişki kuruldu veya kırıldı?) belirtir ve işlemin tamamlandığını vurgulamak için **edilgen geçmiş zamanla** (*"... oluşturulmuştur, ... ilişkilendirilmiştir, ... atanmıştır"*) yazılır (ekrandan, 01:00:00; ekrandan, 01:02:00).
- Use Case Şeması Yerine İşlem Sırası İçin Etkinlik Şeması (*Activity Diagram*) Kullanılması
  - Hangi işin hangi sırada ve hangi aktör tarafından yapıldığını göstermek için asla *Use Case* şeması kullanılmaz; bu amaç için doğru araç, hem çok iş parçacıklı (*multi-threaded* — `fork` ve `join` eşgüdüm çubuklu) akışları hem de yüzme kulvarları (**swimlanes**) ile aktör sorumluluklarını gösteren **UML Etkinlik Şemasıdır (*Activity Diagram*)** (ekrandan, 01:20:00; ekrandan, 01:26:00).
- Durum Şemalarında (*State Diagrams*) "Durum" (*State*) ile "Olay" (*Event*) Kavramlarını Karıştırmama
  - Durum şeması çizerken yapılan en büyük hata, **olayları (eylemleri) durum kutusu içine yazmak** veya **durumları geçiş oku üzerine yazmaktır**. Örneğin *"Uçuş atamak"* veya *"Uçağın teslim edilmesi"* birer **olaydır** (`«M»` ile ok üzerine yazılır); buna karşılık uçağın *"Sipariş aşamasında"*, *"Bakımda"*, *"Kullanıma hazır"* veya *"Bakım sırası beklemede"* olması ise varlığın içinde bulunduğu **durumlardır** (kutuların içine yazılır) (ekrandan, 01:44:00).

## Kısa Tekrar Notları

- **Yüksek uyumun (*high cohesion*) 4 yararı:** 1) Sınıfın anlaşılma kolaylığı artar, 2) Yeniden kullanılabilirlik artar, 3) Bakım kolaylığı artar, 4) Değişikliklerden etkilenme olasılığı düşer (ekrandan, 00:35:00).
- **GoF (*Gang of Four*) kitabı:** *Design Patterns – Elements of Reusable Object-Oriented Software*, Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides (Addison-Wesley, 1994) (ekrandan, 00:35:00).
- **Tasarım belgelendirmesi:** **Ayrıntılı UML Sınıf Şeması** zorunludur; **Sözleşmeler**, **Etkileşim Şemaları (*Sequence* / *Collaboration*)**, **Etkinlik Şemaları (*Activity*)** ve **Durum Şemaları (*State*)** ihtiyaca göre seçilir (ekrandan, 00:39:00).
- **Sözleşme (*Contract*) yapısı:** `İşlem` (metot imzası), `Çapraz Başvurular`, `Ön Koşullar` (sistem durumu) ve `Son Koşullar` (nesne oluşturma, nitelik atama, ilişki kurma — edilgen geçmiş zaman) (ekrandan, 01:00:00; ekrandan, 01:02:00).
- **Sıralama şeması (*Sequence diagram*) gösterimleri (ekrandan, 01:05:00):**
  - Nesne kutusu: `nesne1: Sınıf1` (altı çizili; yalnız `: Sınıf1` veya yalnız `nesne1` de yazılabilir ama **alt çizgi** sınıf ile nesneyi ayırmak için zorunludur).
  - Mesaj: `[koşul] değişken := birMetot(param1: Tip, ...)` (düz ok).
  - Döngü: `* [koşul]` (veya ardışık mesajları çevreleyen `[koşul]` çerçevesi).
- **Etkinlik şeması (*Activity diagram*) özel sembolleri (ekrandan, 01:20:00; ekrandan, 01:26:00):**
  - **Sinyal alma (`>|` bayrak):** Harici olay kabul etme veya zamanlayıcı (*timer*) süresi dolması.
  - **Sinyal gönderme (`|>` dışbükey beşgen):** Başka bir sürece/aktöre olay gönderme (sinyal alma şekliyle birleştiğinde tam dikdörtgen oluşturur).
  - **Eşgüdüm çubuğu (kalın yatay çizgi):** 1 giriş $\rightarrow$ çok çıkış = **`fork`** (paralel süreç başlatma); çok giriş $\rightarrow$ 1 çıkış = **`join`** (tüm paralel kollar bitene kadar bloklayıp birleştirme).
  - **Ok üzerinde `[nesne]`:** Elmastan çıkmayan düz bir eylem okunun üzerindeki `[yolcu listesi]` ifadesi `if` koşulu değil, iki eylem arasında aktarılan **bilgi/nesne akışıdır** (ekrandan, 01:26:00).
- **Durum şeması (*State diagram*) geçiş sözdizimi:** `«M» OlayAdı [koşul] / KOMUTLAR;` (buradaki `«M»`, *Mutate* [durum değişimi/olay] stereotipidir; `/` işareti olayı çalıştırılacak sözde kod veya SQL/prosedür komutlarından ayırır) (ekrandan, 01:40:00; ekrandan, 01:52:00).

## Detaylı Açıklamalar

### 1. Yüksek Uyum, Tasarım Kalıpları (Design Patterns) ve Tasarımın Belgelendirilmesi

Geçen dersin sonunda incelenen **Yüksek Uyum (*High Cohesion*)** ilkesi —yani bir sınıfın yalnızca kendi alt problem alanıyla ilgili, birbiriyle yakından ilişkili sorumlulukları üstlenmesi— dört temel mühendislik avantajı sağlar (ekrandan, 00:35:00):
1. Sınıfın anlaşılma kolaylığı artar,
2. Yeniden kullanılabilirlik (*reusability*) artar,
3. Bakım kolaylığı artar,
4. Sınıfın değişikliklerden etkilenme olasılığı düşer (ekrandan, 00:35:00).

Nesneye yönelik tasarımda hem problem alanı (iş katmanı) hem de sistem katmanı modellenirken, geçmişteki başarılı yazılım mühendislerinin deneyim süzgecinden geçmiş **Tasarım Kalıplarından (*Design Patterns*)** yararlanılır (ekrandan, 00:35:00). Kökeni bina mimarisine (örneğin *"içinde en az yarım saat kesintisiz vakit geçirilecek her odanın en az bir penceresi olmalıdır"* gibi mimari tasarım kurallarına) dayanan bu kavram, yazılım dünyasına **Dörtlü Çete (*Gang of Four* — GoF)** olarak anılan dört yazarın (**Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides**) 1994 yılında yayımladığı ***Design Patterns: Elements of Reusable Object-Oriented Software*** (Addison-Wesley) kitabıyla yerleşmiştir (ekrandan, 00:35:00). Kitapta nesneye yönelik modellemede sık karşılaşılan problemlere yönelik 23 temel tasarım kalıbı tanımlanmıştır; bu kalıplara uymak, gelecekteki gereksinim değişikliklerini bakım maliyetini artırmadan karşılayabilen **esnek tasarımlar** üretmeyi sağlar.

**Tasarım Sürecinin Belgelendirilmesi (ekrandan, 00:39:00):**
- **Ayrıntılı UML Sınıf Şemaları (*Vazgeçilmez*):** Analiz aşamasındaki alan modeline üye metotların, erişim belirleyicilerin ve kesinleşmiş ilişki oklarının eklenmesiyle oluşan şemadır; kodlamanın doğrudan oyun planı olduğu için her projede bulunması zorunludur.
- **Seçimlik Tasarım Yapıtları:** Projenin büyüklüğüne ve karmaşıklığına göre **Sözleşmeler (*Contracts*)**, **UML Etkileşim Şemaları** (**Sıralama şemaları [*Sequence diagrams*]** ve **İşbirliği şemaları [*Collaboration diagrams*]**), **UML Etkinlik Şemaları (*Activity diagrams*)** ve **UML Durum Diyagramları (*State diagrams*)** kullanılır (ekrandan, 00:39:00).

### 2. Sözleşme ile Tasarım (Design by Contract) ve Sıralama Şemaları (Sequence Diagrams)

#### 2.1 Sözleşme ile Tasarım (Design by Contract)

**Sözleşme (*Contract*)**, bir kullanım senaryosunda yer alan kritik ve karmaşık bir sorumluluğun (metodun) kodlanmadan önce çalışma kurallarını netleştiren belgedir (kolay ve açık metotlar için sözleşme yazmaya gerek yoktur) (ekrandan, 01:00:00; ekrandan, 01:02:00). Slaytta *NextGenPOS* sistemindeki `ürünGir` metodu için verilen örnek sözleşme şöyledir (ekrandan, 01:00:00):

```text
Sözleşme No: 2 – Satış Kalemi Girişi
--------------------------------------------------------------------------------
İşlem:              ürünGir( barkod: String, adet: integer )
Çapraz Başvurular:  Satış kullanım senaryosu
Ön Koşullar:        Süregelen bir satış işleminin olması
Son Koşullar:       - Bir SatışKalemi örneği olan satisKalemi oluşturulmuştur.
                    - satisKalemi süregelen satis ile (Satış örneği)
                      ilişkilendirilmiştir.
                    - satisKalemi.miktar üyesine o malın satış adedi atanmıştır.
                    - satisKalemi, satılan mal ile uyuşan barkod sayesinde bir
                      Urun örneği ile ilişkilendirilmiştir.
```

Sözleşme yazımında dikkat edilmesi gereken kurallar şunlardır (ekrandan, 01:02:00):
- **Ön Koşullar** tüm sistem hakkındaki genel durum bilgisidir (ör. süregelen bir satış işleminin başlamış olması; eğer satış başlamadan `ürünGir` çağrılırsa metot hiçbir şey yapmadan döner).
- **Son Koşullar** ise yalnızca problem alanı nesnelerinin durum değişikliklerini anlatır ve işlemin tamamlandığını vurgulamak amacıyla **edilgen geçmiş zamanla** yazılır: 1) Hangi sınıftan hangi nesne örneği (*instance*) oluşturuldu? 2) Hangi üye alana hangi değer atandı? 3) Nesneler arasındaki sahiplik ilişkileri nasıl kuruldu? Bu sözleşmeye bakan bir programcı `ürünGir` metodunu hiçbir ilişkiyi atlamadan doğrudan kodlayabilir; ayrıca sözleşme yazarken alan modelinde unutulmuş bir ilişki fark edilirse geri dönülüp sınıf şeması güncellenir (ekrandan, 01:02:00).

#### 2.2 UML Sıralama Şemaları (Sequence Diagrams)

Nesnelerin birbirlerine gönderdikleri mesajların (metot çağrılarının) zaman sırasını göstermek için UML Etkileşim Şemalarından **Sıralama Şemaları (*Sequence Diagrams*)** tercih edilir (İşbirliği [*Collaboration*] şemaları daha az yer kaplasa da `1.1.1`, `1.1.2` şeklindeki numaraları takip etmek zordur; sıralama şemasında ise düşey $y$ ekseni doğrudan zamanı gösterir) (ekrandan, 01:05:00):

```text
  +----------------+                      +----------------+
  | nesne1: Sınıf1 |                      | nesne2: Sınıf2 |
  +----------------+                      +----------------+
          |                                       |
          |  [koşul] değişken := birMetot(        |
         +-+          param1: Tip, ... )          |
         | |------------------------------------->+-+
         | |                                      | | (Activation Bar:
         | |< - - - - - - - - - - - - - - - - - - +-+  metot çalışıyor)
         | |       (Geri dönüş - ihmal edilebilir)|
         | |----+                                 |
         | | +-+| (Nesnenin kendi                 |
         | | | ||  metodunu çağırması)            |
         | |<--+|                                 |
         +-+    |                                 |
          :                                       :
```

- **Nesne Gösterimi:** Üstteki kutuların içine `nesneAdı: SınıfAdı` (veya yalnız `arabam` ya da yalnız `: SınıfAdı`) yazılır ve bunun bir sınıf değil **nesne (*object*)** olduğunu belirtmek için **altı mutlaka çizilir** (ekrandan, 01:05:00).
- **Etkinlik Çubuğu (*Activation Bar*) ve Sınıf Tutarlılığı:** Düşey kesikli yaşam çizgisi (*lifeline*) üzerindeki ince dikdörtgenler (*activation bar*), o nesnenin bir metodunun o anda çalışmakta olduğunu gösterir. `nesne1`'den `nesne2: Sınıf2`'ye `birMetot(...)` oku gidiyorsa, **`birMetot` mutlaka `Sınıf2`'nin bir üye metodudur** ve sınıf şemasında `Sınıf2` içinde yer almalıdır.
- **Koşul, Döngü ve Çerçeve (*Frame*) Gösterimi:** Koşullu çağrılar `[koşul]`, döngülü çağrılar `* [koşul]` (for/while) ile gösterilir (ekrandan, 01:05:00). Aynı `if` koşuluna veya döngüye bağlı ardışık birden fazla metot çağrısı varsa, her okun üzerine tekrar tekrar `[koşul]` yazmak yerine bu okların etrafına büyük bir dikdörtgen çerçeve çizilip sol üst köşesine bir kez `[koşul]` yazılabilir.

### 3. UML Etkinlik Şemaları (Activity Diagrams) ve NextGenPOS Uygulaması

**UML Etkinlik Şemaları (*Activity Diagrams*)**, denetim ve iş akışını olaylar üzerinden gösteren, çok iş parçacıklı (*multi-threaded* / paralel) süreçleri destekleyen ve hem müşterinin hem konu alanı uzmanının kolayca anlayabildiği bir şema türüdür (ekrandan, 01:20:00).

**1. Havayolu Check-in ve Uçağa Biniş Örneği (Eşgüdüm / Paralel Akış) (ekrandan, 01:20:00):**

```text
              +----------------------------------+
              | Yolcu check-in bankosuna gelir.   \
              |                                   /  (Sinyal alma / Olay kabul etme)
              +-----------------+----------------+
                                |
                                v
                     .--------------------.
                     | Yolcu check-in     |
                     | yapar.             |
                     '---------+----------'
                               |
                               v
                             .---.
                            /     \          [else]
                           <  if?  >-----------------------> (o) (Etkinlik sonu)
                            \     /
                             '---'
                               | [check-in başarılı]
                               v
             ======================================  <-- Eşgüdüm (Fork / Çatallanma)
                     |                    |
                     v                    v
          .--------------------. .--------------------.
          | Yolcu uçağa biner  | | Bagajlar uçağa     |
          '---------+----------' | yüklenir           |
                    |            '---------+----------'
                    v                      v
             ======================================  <-- Eşgüdüm (Join / Birleşme)
                               |
                               v
                     .--------------------.
                     | Uçak piste yönelir |
                     '---------+----------'
                               |
                               v
                              (o) (Etkinlik sonu)
```

- Şema içi dolu siyah daire (**etkinlik başlangıcı**) ile başlayabileceği gibi, sağ kenarı içeri girintili bayrak şeklindeki **Sinyal alma / Olay kabul etme** sembolüyle de başlayabilir (bu sembol aynı zamanda bir zamanlayıcının [*timer*] dolması olayını göstermek için de kullanılır; başka bir sürece olay fırlatan **Sinyal gönderme** sembolü ise sağ kenarı dışa sivri beşgendir ve sinyal alma şekliyle uç uca getirildiğinde tam bir dikdörtgen oluşturur) (ekrandan, 01:20:00).
- **Karar Verme (`if`) Elması:** Elmastan (`<>`) çıkan okların üzerinde köşeli parantez içinde `[check-in başarılı]` ve `[else]` koşulları yer alır (üçlü veya daha fazla dallanmada ya elmasın üç köşesinden ayrı koşullar çıkarılır ya da ardışık iki elmas `if -> else -> if` şeklinde bağlanır) (ekrandan, 01:20:00).
- **Eşgüdüm Çubuğu (*Synchronization Bar* — `fork` ve `join`):** Kalın yatay çubuğa tek ok girip birden fazla ok çıkması paralel çalışmanın başlangıcını (**`fork`**), paralel kolların tekrar kalın çubuğa girip tek ok olarak çıkması ise paralel çalışmanın bitişini (**`join`**) gösterir. *Join* çubuğu bloklayıcıdır (*blocking*): hem yolcuların uçağa binmesi hem de bagajların konveyör bantla uçağa yüklenmesi tamamen bitmeden uçak piste yönelemez (ekrandan, 01:20:00).

**2. Kulvarlar (*Swimlanes*) ve Aktörler Arası Bilgi/Nesne Akışı Örneği (ekrandan, 01:26:00):**
Eylemlerin hangi aktör tarafından yapıldığını her kutunun içine tekrar tekrar yazmak yerine, olimpik yüzme havuzu kulvarları gibi şema dikey sütunlara (**kulvar / *swimlane***) bölünür (ekrandan, 01:26:00):

```text
+-----------------------------------+-----------------------------------+
|          Yer Hizmetleri           |         Müşteri Hizmetleri        |
+-----------------------------------+-----------------------------------+
|                                   |                 (*)               |
|                                   |                  |                |
|                                   |                  v                |
|     .------------------------.    |     .------------------------.    |
|     | Yolcu listesini oluştur|<---|-----|  Yolcu listesini iste  |    |
|     '-----------+------------'    |     '------------------------'    |
|                 |                 |                                   |
|                 v                 |                                   |
|     .------------------------.    |     .------------------------.    |
|     | Yolcu listesini gönder |----+---->| Yolcu listesini kabul  |    |
|     '------------------------' [yolcu   | et                     |    |
|                                listesi] '-----------+------------'    |
|                                   |                 |                 |
|                                   |                 v                 |
|                                   |     .------------------------.    |
|                                   |     | Kesinleşmiş yolcu      |    |
|                                   |     | listesini veritabanına |    |
|                                   |     | kaydet                 |    |
|                                   |     '-----------+------------'    |
|                                   |                 |                 |
|                                   |                 v                 |
|                                   |                (o)                |
+-----------------------------------+-----------------------------------+
```

Burada `Yolcu listesini gönder` eyleminden `Yolcu listesini kabul et` eylemine giden ok bir karar elmasından (`<>`) çıkmadığı hâlde üzerinde **`[yolcu listesi]`** yazmaktadır; iki eylem arasındaki düz ok üzerinde köşeli parantez içinde yazılan ifade bir `if` koşulu değil, bir eylemden diğerine aktarılan **nesne/veri/belge akışıdır** (ekrandan, 01:26:00).

**3. *NextGenPOS* Satış İşlemi Etkinlik Şeması Uygulaması (ekrandan, 02:38:30):**
Dersin üçüncü saatinde *NextGenPOS* satış senaryosu etkinlik şemasına dönüştürülmüştür (ekrandan, 02:38:30):
- `Satış işlemi başlat` (veya `Müşteri kasaya alacağı ürünlerle gelir` $\rightarrow$ `Kasiyer yeni bir satış işlemi başlatır`) adımından sonra `Barkod gir` eylemine geçilir.
- `barkod geçerli mi?` karar elmasında `[hayır]` (veya `[geçersiz barkod]`) ise `Sistem uyarı mesajı verir` eylemine gidilip tekrar `Barkod gir` adımına dönülür; `[evet]` (`[geçerli barkod]`) ise `Satış kalemi oluştur` adımına geçilir.
- `alınacak mal kaldı mı?` karar elmasında `[evet]` ise tekrar `Barkod gir` adımına dönülür; `[hayır]` (`[başka ürün yok]`) ise `Sistem toplam bedeli KDV ile birlikte hesaplar` $\rightarrow$ `Toplamı bildir ve ödeme iste` adımlarına inilir.
- Kullanım öyküsündeki **`3-7a. Müşteri bir kalem malı alışverişten çıkartmak ister`** alternatif senaryosu 3. adımdan (`Barkod gir`) 7. adıma (`Toplamı bildir`) kadar herhangi bir anda gerçekleşebileceği için, her adımın altına ayrı bir elmas çizip şemayı karmaşıklaştırmak yerine 3. adımdan 7. adıma kadar olan tüm bölge büyük bir dikdörtgen çerçeve içine alınmış ve sol üst köşesine **`Bkz. Ürün iptali / silme senaryosu`** etiketi konulmuştur (ekrandan, 02:38:30). Çerçevenin dışına çıkıldıktan sonra `Ödeme al` $\rightarrow$ `Harici sistemlere bilgi aktarımı` $\rightarrow$ `Makbuz (fiş) ver` $\rightarrow$ `Bitiş (o)` adımlarıyla şema tamamlanır (ekrandan, 02:38:30).

### 4. UML Durum Şemaları (State Diagrams)

**UML Durum Şemaları (*State Diagrams*)**, problem alanındaki önemli bir varlığın yaşam döngüsü boyunca içinde bulunabileceği **durumları (*states*)** ve hangi **olaylar (*events*)** gerçekleştiğinde hangi durumdan hangisine geçeceğini modelleyen diyagramlardır (ekrandan, 01:40:00; ekrandan, 01:44:00; ekrandan, 01:52:00).

Slaytlarda bir havayolu şirketindeki **Yolcu Uçağı** varlığının yaşam döngüsü üç aşamada geliştirilmiştir (ekrandan, 01:40:00; ekrandan, 01:44:00; ekrandan, 01:52:00):

```text
   (*) (Başlangıç)
    |
    | «M» Uçağın alım emri verildi /
    | CREATE; SET kayıtNo = (INPUT);
    v
.---------------------.
| Sipariş aşamasında  |
|  (Sipariş Edildi)   |
'----------+----------'
           |
           | «M» Uçak teslim edildi /
           | SET teslimTarihi = (INPUT);
           v
      .---------.        «M» Uçak emekli edildi / DELETE;
      | Bakımda |---------------------------------------------------> (o) (Bitiş)
      '---------'
       ^   ^   \
      /     \   \ «M» Bakım tamamlandı /
     /       \   v
    |         \ .-----------------.
    |          \| Kullanıma hazır |---+ «M» Uçuş ata /
    |           |                 |<--+ «M» Uçuş yap /
    |           '--------+--------'
    |     «M» Arıza      |
    |     bulundu /      | «M» Bakım isteği geldi /
    |                    v
    |    .-------------------------------------------.
    |    | Bakım sırası beklemede                    |
    +----| «M» Uçuş yap [atanmış uçuş varsa] /       |
«M» Uçuş '-------------------------------------------'
yap [atanmış uçuş kalmamışsa] /
```

- **Durum (*State*) vs. Olay (*Event*) Ayrımı:** Yuvarlatılmış dikdörtgenlerin içindeki ifadeler (`Sipariş aşamasında`, `Bakımda`, `Kullanıma hazır`, `Bakım sırası beklemede`) uçağın içinde bulunduğu **durumlardır**. Okların üzerindeki **`«M»`** (*Mutate* — değişim/mutasyon stereotipi) ile başlayan ifadeler ise durum geçişini tetikleyen **olaylardır** (ekrandan, 01:40:00).
- **Aynı Durumda Kalan Olaylar ve Koşullu Geçişler (ekrandan, 01:44:00):**
  - Uçak `Kullanıma hazır` durumundayken bir arıza bulunursa (`«M» Arıza bulundu /`) derhal `Bakımda` durumuna çekilir.
  - Ancak rutin bir bakım isteği geldiğinde (`«M» Bakım isteği geldi /`), uçak hemen bakıma alınmaz; önce **`Bakım sırası beklemede`** durumuna geçer. Bu durumdayken uçağın önceden planlanmış uçuşları varsa onları yapmaya devam eder (`«M» Uçuş yap [atanmış uçuş varsa] /` — bu iç olay kutunun içine yazılabileceği gibi `Kullanıma hazır` durumunda olduğu gibi kendinden kendine dönen bir okla da gösterilebilir). Planlanmış uçuşların tamamı bittiğinde (`«M» Uçuş yap [atanmış uçuş kalmamışsa] /`) uçak `Bakımda` durumuna geçer (ekrandan, 01:44:00).
- **Geçiş Sırasında İşlenen Komutların Gösterimi (`/` Sonrası Eylemler) (ekrandan, 01:52:00):**
  - Bir olay gerçekleştiğinde çalıştırılacak sözde kod (*pseudocode*), SQL sorguları veya saklı yordamlar (*stored procedures*) eğik çizgiden (`/`) sonra noktalı virgülle (`;`) bitirilerek yazılır.
  - Örneğin alım emri verildiğinde `CREATE; SET kayıtNo = (INPUT);` ile veritabanında uçak kaydı oluşturulup kullanıcıdan kayıt numarası alınır; uçak teslim edildiğinde `SET teslimTarihi = (INPUT);` ile teslim tarihi kaydedilir; uçak emekli edildiğinde ise `DELETE;` (veya resmi arşiv/mali tablo kaydı tutulacaksa `SET durum = pasif;`) komutu çalıştırılır (ekrandan, 01:52:00). Böylece `«M»` stereotipi yeni bir olayın başladığını, `/` işareti ise olay adı ile çalıştırılacak komutların sınırını net biçimde ayırır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
