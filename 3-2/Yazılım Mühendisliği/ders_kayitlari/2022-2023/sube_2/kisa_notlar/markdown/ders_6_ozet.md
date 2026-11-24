# Ders 6 Çalışma Özeti

## Genel Konular

- Tasarım kalıplarına (design patterns) giriş
  - Nesneye yönelik modelleme ve tasarımda sık karşılaşılan (recurring) problemler için deneyimli kişilerin önerdiği, avantaj ve dezavantajlarıyla birlikte sunulmuş hazır çözümlerdir (ekrandan, 00:15:00).
  - Tanım: yazılım tasarımında karşılaşılan belirli sorunların yalın ve güzel çözümlerinin tarifidir; çözüm somut ya da biraz soyut olabilir (ekrandan, 00:20:00).
  - Tasarım kalıplarına uymak daha esnek bir tasarım elde etmeyi sağlar. Temel kaynak "Dörtlü Çete" (Gang of Four, GoF) kitabıdır: Design Patterns – Elements of Reusable OO Software, Erich Gamma et al., Addison-Wesley, 1994. Ek kaynaklardan da çalışılması yararlıdır.
  - Nesneye yönelim temellerinden sonra, yazılım geliştirme alanında çalışacak biri için ilerlenmesi gereken ilk nokta tasarım kalıplarıdır.
- Bir tasarım kalıbının bileşenleri
  - İsim: kalıbı en iyi anlatan bir ya da birkaç kelime. İyi isim vermek emek ister; kalıp özümsendikten sonra ismin onu özetlediği görülür.
  - Sorun: kalıbın hangi sorunu çözdüğünün tarifi.
  - Çözüm: önerilen tasarımın bileşenleri (sınıflar), ilişkileri, sorumlulukları ve birlikte nasıl çalıştıkları.
  - Tartışma / sonuçlar: esneklik, yeniden kullanılabilirlik, genişletilebilirlik, taşınabilirlik üzerindeki etkiler; güçlü ve zayıf yönler; hangi problemlere uyduğu; yer-zaman çelişkileri (time-memory trade-off); başka kalıplarla işbirliği olanakları.
- Tasarım kalıplarının yararları (ekrandan, 00:25:00)
  - Tekerleği yeniden icat etmemek.
  - Üzerinde birçok deneyimli kişinin emeği geçtiğinden "kaliteli" bir çözüm.
  - Deneyimin yazılı biçimde aktarılabilmesi.
  - Yazılım ekibi arasında ortak bir sözlük oluşturması.
- Kalıp tartışması ve sınıflandırma (ekrandan, 00:30:00)
  - Bir kişinin "kalıp" dediğine diğeri "basit bir yapı taşı" ya da "temel bir ilke" diyebilir.
  - "Kalıp" terimi mimarlıktan gelir. Mimari kalıp örneği: içinde bir insanın bir saatten fazla zaman geçireceği her bölmede bir pencere olmalıdır.
  - GoF kalıpları amaçlarına göre üç kümeye ayrılır: yaratımsal (creational), yapısal (structural), davranışsal (behavioral).
- Örnek tasarım kalıbı: Model-View-Controller (MVC) (ekrandan, 00:35:00)
  - Sorun: aynı veriyi farklı biçimlerde göstermek; kullanıcıya verinin nasıl ve ne kadarının gösterileceğini seçebilme olanağı sağlamak.
  - Çözüm: veriyi, verinin gösterimini ve gösterimin yönetimini ayrı sınıflar olarak ele almak.
  - Model ham veriyi, View verinin çeşitli gösterim biçimlerini simgeler; Controller kullanıcı komutlarını alıp işler.
  - Bağlaşım yönleri: Controller → View, Controller → Model, View → Model. Model hiçbir sınıfa bağımlı değildir.
- MVC'nin yararları ve çeşitlemeleri (ekrandan, 00:45:00)
  - Gösterim, kontrol ve veriyi ayırarak bunları çalışma anında değiştirebilmek, ilgi alanlarını ayırmak ve yeniden kullanımı artırmak.
  - Çeşitlemeler: Model'in değişiklikleri View'a bildirmesi; birden fazla view (iç içe, ayrı/tek görevcikte, örtüşen/ayrık); birden fazla kontrolcü (klavye, fare, ses gibi farklı denetim biçimleri).
- Tasarımın belgelendirilmesi (ekrandan, 00:55:00)
  - Ayrıntılı UML sınıf şemaları vazgeçilmezdir.
  - İhtiyaca göre sözleşmeler, UML etkileşim şemaları (sıralama ve işbirliği şemaları), UML etkinlik şemaları ve UML durum şemaları birlikte kullanılabilir.
- Sözleşme ile tasarım (Design by Contract)
  - Sözleşme bir kullanım senaryosunun ayrıntılandırılmasıyla elde edilir; her metot bir sözleşmeyle ayrıntılandırılabilir.
  - Bölümleri: numara ve ad, işlem (metot imzası), ilişkili kullanım senaryosu, ön koşullar, son koşullar.
  - Örnek: satış kalemi girişi sözleşmesi ve son koşulları.
- Sıralama şemalarının (sequence diagram) gösterimi (ekrandan, 01:05:00)
  - Nesne kutusu `nesne: Sınıf` biçiminde, altı çizili yazılır.
  - Mesaj (metot çağırma) düz okla, geri dönüş kesikli okla gösterilir; geri dönüş ihmal edilebilir.
  - Koşullu mesaj `[koşul]`, döngülü mesaj `*` ya da `*[koşul]`, nesne oluşturma `new` ile gösterilir; nesnenin kendi metodunu çağırması iç içe bir activation bar ile çizilir.
- Örnek: Person.introduceSelf() metodunun sıralama şeması (ekrandan, 01:25:00 ve 01:45:00)
  - Person sınıfının `name` ve `Car` türünde `car` üye alanı vardır; Person ile Car arasında 0..1 nicelikli tek yönlü ilişki vardır.
  - Şema Violet UML Editor ile çizildi: çağıran nesne → `introduceSelf()` → `:Person`; `:Person` kendi `getName()` metodunu çağırır; `[car!=null] getPlate()` mesajı `car : Car` nesnesine gider; geri dönüşler kesikli okla çizilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tasarım kalıpları yazılım geliştiren herkes için zorunlu bir birikimdir
  - Teknik mülakatlarda sorulur ve yazılım alanında çalışırken kullanılması gerekir; bu konuya zaman ve çaba ayrılmalıdır.
- Kalıp kullanmak her zaman bedelsiz değildir
  - Kalıplı çözümde bağlaşım, kalıpsız çözüme göre biraz yüksek çıkabilir. Karşılığında gelecekteki gereksinim değişikliklerine karşı bağışıklık elde edilir.
  - Çevik çalışırken "basit tut" ilkesi geçerlidir: yakın gelecekte gereksinim değişikliği öngörülmüyorsa eldeki problemi en iyi çözen tasarım seçilip kalıptan vazgeçilebilir.
- Ortak sözlük etkisi
  - Ekipteki herkes kalıpları bilirse "burada strateji kalıbı, şurada template method" gibi birkaç cümleyle tasarım hızla ilerler; sınıf hiyerarşisini uzun uzun anlatmaya gerek kalmaz.
- Çift yönlü ilişki yalnız gerekiyorsa kurulmalı
  - Model'in View'u bilmesi ancak sürekli sorgulamanın (polling) haberleşme maliyeti önemliyse yararlıdır; gereksiz ek karmaşıklık ve bağlaşım eklenmemelidir.
- Sıralama şemalarında ok yönü
  - Bir nesneye giren okun üzerindeki metot, o nesnenin sınıfında tanımlı olmalıdır. `getPlate()` Car'da tanımlı olduğu için ok Car nesnesine girer; Person'a giren bir `getPlate()` oku konunun anlaşılmadığını gösterir.
- Sıralama şemalarında zaman ve boşluk
  - Şemada aşağı inildikçe zamanda ileri gidilir. İç çağrının oku, dış metodun başladığı hizadan değil biraz aşağıdan başlatılmalıdır; yukarı doğru çizilen bir çağrı zamanda geri gitmek anlamına gelir.
- Sıralama şemalarında problem alanı çağrıları
  - `print` gibi çağrılar değil, problem alanındaki varlıkların metot çağrıları çizilir.

## Kısa Tekrar Notları

- Tasarım kalıbı: sık karşılaşılan tasarım sorununa yalın ve iyi bir çözümün tarifi.
- Kalıp bileşenleri: isim, sorun, çözüm, tartışma/sonuçlar.
- Yararlar: tekerleği yeniden icat etmemek, kaliteli çözüm, deneyimin yazılı aktarımı, ortak sözlük.
- GoF kümeleri: yaratımsal, yapısal, davranışsal.
- MVC: Model = veri, View = gösterim, Controller = kullanıcı komutlarının işlenmesi; Model kimseye bağımlı değil.
- MVC yararları: çalışma anında değiştirebilme, ilgi alanlarının ayrılması, yeniden kullanım.
- MVC çeşitlemeleri: Model → View bildirimi (Observer), çoklu view (iç içe, görevcik, örtüşen/ayrık), çoklu kontrolcü.
- Tasarım belgeleri: UML sınıf şeması zorunlu; sözleşmeler, etkileşim, etkinlik ve durum şemaları ihtiyaca göre.
- Sözleşme: işlem, ilişkili senaryo, ön koşullar (tüm sistem), son koşullar (problem alanı nesnelerindeki değişiklikler, edilgen geçmiş zaman).
- Sıralama şeması: `[koşul]` = if, `*` = döngü, `new` = kurucu, kendi metodunu çağırma = iç activation bar, geri dönüş kesikli ok (isteğe bağlı).

## Detaylı Açıklamalar

- **Tasarım kalıbı ne işe yarar?** Nesneye yönelik bir modelleme yaparken bazı durumlarla tekrar tekrar karşılaşılır. Bunları kendi başımıza da modelleyebiliriz, ama deneyimli kişiler bu problemler üzerinde düşünmüş ve çözümlerini avantaj ve dezavantajlarıyla birlikte yazmıştır. Bu çözümleri bilmek modelleme ve tasarım aşamalarını kolaylaştırır. Amaç, yeniden keşfetmeden esnek ve yeniden kullanılabilir iyi bir tasarıma ulaşmaktır. Tasarım kalıplarıyla yapılan çözümler çoğu kalite ölçütünde iyileşme sağlar. Bazı ölçütlerde gerileme olabilir, ama bu gerileme gelecekteki gereksinim değişikliklerine daha kolay uyum sağlanarak telafi edilir.

- **Tartışma bölümündeki yer-zaman çelişkisi.** Bir problemi daha çok bellek kullanarak daha kısa zamanda çözmek tercih edilebilir. Örneğin gerçek zamanlı bir uygulamada önceden hesaplanmış tablolar bellekte tutulur ve sonuç yeniden hesaplanmadan tablodan okunur (look-up). İşlemci kaynağı düşük ama belleği bol sistemlerde de bu yol seçilir. Bellek kısıtlıysa ara sonuçlar tutulamaz ve bazı hesaplar her seferinde yeniden yapılır. Bir kalıbın tartışma bölümü bu tür ödünleşimleri de ele almalıdır.

- **MVC ve bir benzetme.** MVC'de Model ham veridir; View bu verinin gösterim biçimlerinden biridir; Controller kullanıcı komutlarını alır ve View ya da Model üzerinde işlem yürütür. Model'de bir değişiklik gerekiyorsa probleme göre bunu Controller doğrudan yapabilir ya da View'a yaptırabilir. Hocanın benzetmesi bir ressamdır: resmi yapılan kişi modeldir. Kişi ressama tam boy, portre ya da karikatür istediğini söyleyebilir; ressam da view'u buna göre ayarlar. Ressam kendisi bir eser ortaya koyacaksa hangi görünümü kullanacağına kendisi karar verir ve kontrolcü rolüne geçer.

- **Seçim yayını örneği.** Seçim gecesi televizyonda açılan sandıklar, oylar ve sandıkların açılma yüzdesi il ve bölge düzeyinde sayılarla, pasta grafikle, çubuk grafikle ya da harita üzerinde renklendirmeyle gösterilir. Spiker hangi görüntüye geçileceğini, neyin ne kadar ve nasıl gösterileceğini sürekli kontrol eder. Bu örnekte MVC'nin bütün bileşenleri görülür. Bir kez yazılmış bir pasta ya da çubuk grafik bileşeni başka problemlerde de kolayca yeniden kullanılabilir.

- **Çalışma anında değiştirebilme.** View sınıfından kalıtımla VA, VB gibi alt sınıflar türetilebilir (ekrandan, 00:45:00). Kullanıcı bir seçenek seçtiğinde Controller VA ya da VB nesnesi üzerinden gösterime geçebilir. Bu ayrım yapılmasaydı programı kapatıp kaynak kodu ya da yapılandırmayı değiştirip yeniden çalıştırmak gerekirdi.

- **Model değişikliğinin View'a bildirilmesi.** İlişkileri artırmak istemiyorsak View zaman zaman Model'e "değiştin mi?" diye sorar ve değiştiyse veriyi çeker. Model ile View farklı bilgisayarlardaysa bu sorgulama zaman ve haberleşme maliyeti (ücretli bağlantılarda para) getirir. Bu maliyet önemliyse Model'den View'a da bir ok çizilir; Model değişince ilişkili View'a haber verir. Bu durumda işin içine Observer tasarım kalıbı girer. Çift yönlü ilişkilerin kurulması ve tutarlı tutulması daha karmaşıktır; yalnız gerekiyorsa kurulmalıdır.

- **Birden fazla view ve kontrolcü.** Belirli bir anda bir view bir modelle ilişkilidir, ama bir kontrolcü birden fazla view ile ilişkili olabilir (nicelik 1..*) (ekrandan, 00:50:00). Örneğin bir denetim ekranında modelin farklı kısımlarını gösteren birkaç panel olabilir; gösterdikleri veriler örtüşebilir. Model'de değişiklik yapma isteği kullanıcıdan geliyorsa (örneğin sandık tutanaklarının sisteme girilmesi), bu girişi bir view üzerinden değil Controller üzerinden kodlamak daha iyidir; aksi halde bir view'un yaptığı değişiklikten öbür view habersiz kalabilir. View'lar farklı görevciklerde (thread) çalışıyorsa eşzamanlama sorunlarına ve yarış durumlarına (race condition) dikkat edilmelidir. Klavye ve ses gibi farklı denetim biçimleri için CA, CB gibi farklı kontrolcü sınıfları olabilir; sistem bir kontrolcüyle başlatılıp duruma göre başka kontrolcüye geçebilir.

- **Sözleşmeler.** Sözleşmeler bir metodun çalışma anında nasıl yürütüleceğini koda yakın biçimde anlatır; tasarım sözleşmelerle yapılırsa geriye yalnız kodlamak kalır. Bütün tasarımı sözleşmelerle yazmak verimli değildir; kritik sorumluluklar için yazmak yararlıdır. Derste gösterilen örnek "Sözleşme No 2: Satış kalemi girişi" idi. Son koşullarında şu tür maddeler vardı: bir satış kalemi nesnesi oluşturulmuştur; satış kalemi süregelen satış nesnesiyle ilişkilendirilmiştir; satış kaleminin miktar üye alanına malın satış adedi atanmıştır; satış kalemi barkodla eşleşen ürün nesnesiyle ilişkilendirilmiştir. Böyle yazılınca kodlamanın ayrıntılarının büyük bölümü sözleşmeden anlaşılır. <!-- BELİRSİZ: Sözleşme örneğinin slaytı karelerde yok; işlem satırındaki metot adı ve parametreleri (barkod: String, miktar gibi) altyazıdan kesin okunamadı. -->

- **Ön ve son koşulların dili.** Ön koşullar tüm sistem hakkındaki bilgilerdir; son koşullar yalnız problem alanındaki nesnelerin durum değişiklikleri hakkındadır (ekrandan, 01:00:00). Son koşullarda edilgen geçmiş zaman kullanılır, çünkü bunlar işlemin sonunda tamamlanmış eylemlerdir. Kullanım senaryosu metinlerinde ise adımlar etken ve geniş ya da şimdiki zamanla yazılır. Sözleşmede ilişkilerin kurulmasını belirtmek unutulmamalıdır. Sözleşme yazmak, çözümleme aşamasında atlanan bir eksiği kodlamadan önce ortaya çıkarabilir; çünkü teknik gözden geçirmeler ve sınama her hatayı yakalayan bir güvenlik ağı değildir.

- **Sıralama şeması gösterimleri.** Nesne kutusuna `nesne2: Sınıf2` biçiminde ad, iki nokta üst üste ve sınıf yazılır, altı çizilir (ekrandan, 01:05:00). Tek bir metodun şeması çiziliyorsa çağıran nesnenin adını yazmaya gerek yoktur. Parametreler `param1: Tip` biçiminde, virgülle ayrılarak yazılır. Dönen değer isteğe bağlı olarak geri dönüş okunun üstüne yazılır; bir değişkene atandığı `değişken := birMetot(...)` biçiminde gösterilebilir. Çağrı bir if koşuluna bağlıysa koşul köşeli parantez içinde başa yazılır. Bir dizideki bütün nesneler için çağrı yapılıyorsa başa `*` konur; döngü koşulu da yazılmak istenirse `*[koşul]` kullanılır. Kurucu çağrısı için `new` yazmak yeterlidir. Nesnenin kendi metodunu çağırması kendinden kendine giden bir okla ve iç içe ikinci bir activation bar ile gösterilir; bu durumda geri dönüş oku çizilmez, çünkü iç dikdörtgenin alt ucu metodun bittiği noktayı gösterir.

- **Person.introduceSelf() örneği.** Eclipse'te açılan kod (ekrandan, 01:25:00):

```java
public class Person {
private String name;
private Car car;

public Person( String name ) {
    this.name = name;
}
public String getName( ) { return name; }
public Car getCar( ) { return car; }
public void setCar( Car car ) { this.car = car; }

public String introduceSelf( ) {
    String intro;
    intro = "Hello, my name is " + getName();
    if( car != null )
        intro += " and I have a car with licen..." // satırın sonu ekranda kesik
            + car.getPlate();
    intro += ".";
    return intro;
}
```

  - Kurucu yalnız ismi alır, arabayı almaz; bu yüzden bir kişi arabasız oluşturulabilir ve araba sonradan `setCar` ile atanır. Person'dan Car'a olan ilişkinin niceliği bu nedenle 0..1'dir.
  - Şemada çağıran nesne adsız bırakılır, çünkü `introduceSelf` public'tir ve herhangi bir nesne çağırabilir. `:Person` nesnesinin activation bar'ının içinden kendi `getName()` çağrısı çizilir. `getName()` bittikten sonra, dış activation bar'ın içinde kalarak `car : Car` nesnesine `[car!=null] getPlate()` mesajı gider. `getPlate()` Car sınıfında tanımlı olduğu için ok Car nesnesine girer. Car'dan Person'a, sonra Person'dan çağırana kesikli geri dönüş okları çizilir (ekrandan, 01:45:00).
  - Şema, `getName` ve `getPlate` çağrılarının `introduceSelf` içinde ve bu sırayla yapıldığını gösterir. Bir metot içinden başka bir metot çağrıldığında çağıranın durum bilgisi yığına atılır ve yeni metot için alan açılır; bu iş zaman alır. Şemada iç çağrının dış çağrıyla aynı hizadan başlatılmaması, araya küçük bir dikey boşluk bırakılması bu yüzden hem doğru hem daha anlaşılırdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
