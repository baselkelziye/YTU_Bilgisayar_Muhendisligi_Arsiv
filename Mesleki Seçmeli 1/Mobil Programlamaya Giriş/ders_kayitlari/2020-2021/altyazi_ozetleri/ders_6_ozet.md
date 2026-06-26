# Ders 6 Çalışma Özeti

## Genel Konular

- Intent kavramı ve temel tanımı
  - Intent bileşeni, bir activity'den başka bir activity'ye geçiş sırasında bu görevi gerçekleştiren bileşendir.
  - Intent'lerle hem gidilmek istenen aktivite belirtilir hem de yapılmak istenen iş belirtilerek sisteme uygun aktiviteler listeletilebilir.
  - Kendi uygulaması içinde aktiviteler arasında gezmeyi sağladığı gibi bir uygulamadan başka bir uygulamaya geçerek o andaki işi yapabilmesi.

- İki tip intent
  - Explicit Intent (Açık Intent): doğrudan işi yapacak aktivitenin veya ait olduğu paketleme isminin belirtildiği; hedefin net olarak gösterildiği intent türü.
  - Implicit Intent (Örtük Intent): yapılmak istenen işin ne olduğunun belirtildiği, bunu yapabilecek uygulamaların sistemden talep edildiği intent türü.
  - Explicit intent uygulama içerisinde kalır, implicit intent sistem seviyesine kadar çıkar; bu yüzden explicit intent performans açısından daha önemlidir.
  - Bir web adresinin gösterilmesi veya bir numaranın aranması implicit intent örnekleridir; sistem uygun uygulamaları (Chrome, Firefox, telefon uygulaması) listeler.

- Intent özellikleri ve metodları
  - Explicit intent'te genelde target'ın component name field'ının set edilmesi beklenir.
  - Implicit intent'te component name field'ı boş bırakılmalı, sadece hangi aksiyonun alınacağı eklenmelidir.
  - Önemli metodlar: setComponent, setType, putExtra, setData, setAction.
  - Birden fazla bilgi göndermek için ArrayList yapısı kullanılabilir; URI bilgisi intent'in constructor'ına aktarılır.
  - putExtra metodu: intent'in içine bilgi yerleştirmek için kullanılır; her aksiyona ait sabitler (EXTRA_EMAIL, EXTRA_SUBJECT gibi) vardır.

- Intent karşılama (handle) süreci
  - Bir intent oluşturulduğunda karşı tarafın bu intenti alması gerekir.
  - Alabilme yolu: setContentView'dan sonra getIntent metodu ile gelen intent'i alacak kodun yazılması.
  - İçeriğin kontrol edilip (resim mi, metin mi vb.) uygun aksiyonun kodlanması gerekir.
  - Bu kod yazılmazsa intent discard edilir, aktivite sadece kodlanmış işi yapar.

- startActivity vs startActivityForResult
  - Çağrılan activity'den bilgi alınacaksa startActivityForResult metodu kullanılır.
  - Sadece bilgi gönderilecekse ve alınmayacaksa startActivity yeterlidir.
  - AndroidX ile birlikte startActivityForResult yerine daha çok önerilen yeni API'ler gelmiştir (AndroidX activity 1.2.0.alpha.02, Fragment 1.3.0).

- IntentFilter ve manifest bildirimi
  - Kendi uygulamasının belirli işleri yapabilmesi için Android Manifest'te intent filter olarak gömülmesi gerekir.
  - Bu sayede işletim sistemi uygulamanın hangi yeteneklere sahip olduğunu bilir ve diğer uygulamaların talepleri karşısında uygulamayı listeleyebilir.
  - Email client, web browser, harita, sosyal medya uygulamaları hep bu yapıyı kullanır.
  - Data kısıtlaması ile belirli domainlere yönlendirme gibi durumlar yönetilebilir; action bazında değil, kategori bazında filtreleme yapılabilir.

- onActivityResult metodu
  - startActivityForResult ile başlatılan aktiviteden geri dönüldüğünde çağrılan metot.
  - Request code, result code ve intent bilgisi parametre olarak gelir.
  - Request code: gönderilen isteği tanımlayan kod (birden fazla istek arasında ayrım için).
  - Result code: işlemin gerçekleştirilip gerçekleştirilmediğini belirten kod (RESULT_OK, RESULT_CANCELLED).
  - Result ok ise cursor üzerinden gelen veri alınır ve kullanılır.

- Chooser (Seçici) kullanımı
  - Implicit intent'te sistem "Just once" / "Always" seçenekleri sunar.
  - "Always" seçilirse hep aynı uygulama açılır; her seferinde sormak için chooser oluşturulabilir.
  - intent.createChooser ile chooser oluşturulur.
  - Implicit intent'te uygulama seçimini filtrelemek (örneğin Chrome'u gizlemek) mümkün değildir; bu işletim sistemi tarafından organize edilir.

- Performans ipuçları
  - Bir karşılayan yoksa intent başarısız olur; bu yüzden package manager üzerinden queryIntentActivities çağrılarak dönen size sıfırdan büyük mü kontrol edilmelidir.
  - Aksi halde kullanıcıya bilgilendirme yapılmalıdır, yoksa hata mesajı alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Explicit intent'in performans açısından tercih edilmesi gerektiği
  - "Doğrudan bir hedefiniz varsa onun için implicit intent tanımlamalısınız" ifadesiyle, eğer hedef belli ise system seviyesine çıkıp tekrar inmeye gerek olmadığı vurgulanmıştır.
  - Explicit intent uygulama içerisinde kaldığı için daha performanslıdır.

- IntentFilter'ın Android geliştirmedeki kritik rolü
  - Kendi uygulamasının yeteneklerini manifest'te intent filter olarak gömmek, uygulamanın diğer uygulamalar tarafından keşfedilebilirliği için şarttır.
  - WhatsApp, Signal gibi uygulamaların "instant mesaj gönder" yeteneği bu şekilde tanımlanır.

- Yeni API'lerin kullanımı konusunda farkındalık
  - AndroidX ile birlikte startActivityForResult'un yerini yeni API'ler almıştır.
  - Eski API'ler hâlâ desteklense de, yeni projelerde AndroidX activity 1.2.0.alpha.02 ve Fragment 1.3.0 API'lerinin tercih edilmesi gerektiği.

- Code paylaşımı ve akademik dürüstlük konusunda ders genelinde vurgulanan tutum
  - Ödevlerde birebir paylaşımın notun sıfırlanmasına yol açacağı, bu konuda çok sert yaptırımlar uygulanabileceği.

## Kısa Tekrar Notları

- İki intent türü: Explicit (hedef net) ve Implicit (aksiyon belirtilir, sistem uygulama seçer).
- Explicit intent uygulama içinde kalır, performanslıdır; implicit intent sistem seviyesine çıkar.
- Intent metodları: setComponent, setType, putExtra, setData, setAction.
- putExtra: intent'e bilgi eklemek için (EXTRA_EMAIL, EXTRA_SUBJECT).
- startActivity: bilgi alınmayacaksa; startActivityForResult: bilgi alınacaksa.
- onActivityResult: geri dönüşte çağrılır; requestCode, resultCode, intent parametreleri alır.
- RESULT_OK, RESULT_CANCELLED sonuç kodları.
- AndroidX ile yeni API'ler geldi: startActivityForResult yerine registerForActivityResult.
- IntentFilter: manifest'te uygulamanın hangi intent'lere cevap verebileceğini belirtir.
- Chooser: her seferinde uygulama seçtirmek için intent.createChooser.
- packageManager.queryIntentActivities: karşılayan var mı kontrolü.

## Detaylı Açıklamalar

Dersin başlangıcında hoca, artık hızlı gitmeleri gerektiğini, 3-4 keçe gibi başlayacaklarını belirtmiştir. Zoom'da mikrofon ve kameranın default kapalı olması için ayar önerilmiştir (Ayarlar > Video/Audio > "Toplantıya katılırken mikrofonumu kapat" ve "videomu durdur"). Her hafta bir-iki kişinin istenmeyen ses yayınına yol açtığı, bu ayarın bir kez yapılmasının yeterli olduğu vurgulanmıştır.

Geçen haftanın ödevi hatırlatılmıştır: Bir login ekranı tasarlanmış, kişi üç defa yanlış giriş yaptığında login butonunun disable olması implement edilmişti. Hemen arkasında bir sign up ekranı yazılacak, intent ile ilgili bilgiler öğrenilip kayıtlar görülecekti. Yarım saat sonra yapılacak uygulama ile ilgili bilgi verilmiştir: Android aktiviteleri üzerinden quiz/sınav soruları oluşturulacak, bir soru girişi yapılacak, şıklar oluşturulacak, doğru şık işaretlenip kaydedilecektir. Bir ekran bunu yapmayı sağlayacak, başka bir ekran soruları görmeyi sağlayacaktır. Bu bir alıştırma olarak yapılacak, daha sonra ödev olarak istenebileceği belirtilmiştir.

Intent kavramı detaylı olarak anlatılmıştır. Uygulamalar arası ve aktiviteler arası geçiş için gerekli olan bu bileşen, hem bilgi taşımak hem de bir butona tıklandığında yeni bir aktiviteye geçmek istendiğinde kullanılır. İki tip intent olduğu belirtilmiştir: Explicit intent ve Implicit intent. Explicit intent'te doğrudan o işi yapacak aktivitenin veya ait olduğu paketleme isminin belirtildiği, hedefin net gösterildiği vurgulanmıştır. Implicit intent'te ise yapılmak istenen işin ne olduğunun belirtildiği, bunu yapabilecek neler varsa sistemden talep edildiği açıklanmıştır. Örnek olarak bir haritada adres gösterilecekse ActionView, bir numara aranacaksa ActionDial, bir web adresi gösterilecekse ActionView kullanıldığı belirtilmiştir. Implicit intent'te browser'lar arasından seçim yapılabileceği (Chrome, Safari, Firefox, Explorer) vurgulanmıştır.

Performans açısından explicit intent'in daha avantajlı olduğu, çünkü uygulama içerisinde kalıp sistem seviyesine çıkıp tekrar aşağı inmeye gerek olmadığı vurgulanmıştır. Explicit intent'te target'ın component name field'ının set edilmesi gerektiği, bu ya package özelinde ya da doğrudan class ismi verilerek yapıldığı belirtilmiştir. Implicit intent'te ise component name field'ının boş bırakılması, sadece hangi aksiyonun alınacağının eklenmesi gerektiği söylenmiştir.

Intent'in oluşturulması ve bilgi taşıma yöntemleri açıklanmıştır. Constructor'a aksiyon ve bilgi eklenebileceği, URI üzerinden bilgi parse edilip intent'e aktarıldığı belirtilmiştir. Bir email intent'i oluşturulurken ActionSend kullanıldığı, bu bilgiyi gönderebilecek uygulamalarla ilgilenildiği, uygulamaların Android manifestlerinde intent filter olarak yeteneklerini dekler ettikleri için işletim sisteminin hangi uygulamaların bunu yapabileceğini bildiği açıklanmıştır. Tip belirleme, to/subject gibi bilgileri putExtra metoduyla aktarma yöntemi anlatılmıştır. Birden fazla bilgi (örneğin birden fazla kişi ismi) göndermek için ArrayList yapısının kullanılabileceği belirtilmiştir.

startActivityForResult ve onActivityResult detaylı olarak ele alınmıştır. Bir activity'ye gidip oradan bilgi alarak geri dönmek için startActivityForResult metodu çağrılır. startActivityForResult sonrası onActivityResult metodu tanımlanmalıdır. Bu metoda requestCode, resultCode ve intent parametreleri gelir. Request code öğrenciye verilmiş bir kod, result code ise karşı tarafın verdiği koddur. Result code RESULT_OK, RESULT_CANCELLED gibi değerler alabilir. Result ok ise cursor üzerinden gelen veri alınır, content provider kullanıldığında cursor yapısı kullanılır.

Chooser (seçici) kavramı açıklanmıştır. Implicit intent'te sistem "Just once" / "Always" seçenekleri sunar. Always seçilirse hep aynı uygulama açılır. Her seferinde sormak için chooser oluşturulur, intent.createChooser ile yapılır. Bu sayede Just once ve Always seçeneği devre dışı bırakılmış olur. Ancak bir uygulamayı listeden filtrelemenin (örneğin Chrome'u gizlemek) mümkün olmadığı, bu işlemin işletim sistemi tarafından organize edildiği belirtilmiştir.

IntentFilter ve manifest bildirimi detaylı olarak anlatılmıştır. Kendi uygulamasının belirli işleri yapabilmesi için Android Manifest'te intent filter olarak gömülmesi gerektiği, bu sayede işletim sisteminin uygulamanın hangi yeteneklere sahip olduğunu bilmesi ve diğer uygulamaların talepleri karşısında uygulamayı listeleyebilmesi açıklanmıştır. Email client, harita, web browser, sosyal medya uygulamalarının hepsinin bu yapıyı kullandığı belirtilmiştir. Action bazında değil, kategori (data) bazında filtreleme yapılabileceği, örneğin sadece text gönderme yeteneği tanımlanırsa resim gönderilmek istendiğinde uygulamanın bunu yapmayacağı vurgulanmıştır.

Hoca, login ekranından başarı giriş sonrası menü ekranına geçiş örneği vererek Explicit intent kullanımını somutlaştırmıştır. Intent'in o andaki context'i (bulunulan activity) alıp hedef activity'nin ismini (package.ClassName formatında) yazdığını açıklamıştır. putExtra ile UserID gibi bilgiler eklendiğini, bu bilgilerin yeni ekranda "Hoş geldiniz X kişisi" gibi mesajlar için kullanılabileceğini belirtmiştir. Eğer 3 defa hatalı giriş yapılırsa toast mesajıyla kullanıcıya bilgi verildiğini ve finish ile uygulamanın destroy edildiğini (ödev kapsamında), ya da butonun disable edileceğini söylemiştir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
