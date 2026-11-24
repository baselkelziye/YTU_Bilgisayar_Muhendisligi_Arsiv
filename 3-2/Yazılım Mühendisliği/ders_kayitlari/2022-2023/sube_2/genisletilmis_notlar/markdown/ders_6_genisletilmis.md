# Ders 6 Genişletilmiş Notu: Tasarım Kalıplarına Giriş (MVC), Tasarımın Belgelendirilmesi, Sözleşmeler ve Sıralama Şemaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersten Bağlantı: Uyum ve Bağlaşım
- 2. Tasarım Kalıpları Neden Önemli?
- 3. Tasarım Kalıbı Nedir ve Bileşenleri Nelerdir?
- 4. Tasarım Kalıplarının Yararları
- 5. "Kalıp" Tartışması ve GoF Sınıflandırması
- 6. Örnek Tasarım Kalıbı: Model-View-Controller (MVC)
- 7. MVC'nin Yararları
- 8. MVC Çeşitlemeleri
- 9. Tasarımın Belgelendirilmesi
- 10. Sözleşme ile Tasarım (Design by Contract)
- 11. Sıralama Şemalarının Hatırlatılması
- 12. Uygulama: Person.introduceSelf() için Sıralama Şeması
- 13. Sıralama Şemalarında Sık Yapılan Hatalar
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersten Bağlantı: Uyum ve Bağlaşım

Ders, nesneye yönelik tasarım sürecinde kalınan yerden açıldı. Ekrandaki slaytta önceki dersin son konusu olan yüksek uyum (high cohesion) özetleniyordu (ekrandan, 00:15:00). Uyum, bir parçanın sorumluluklarının birbirleriyle uyumlu olma oranıdır. Yüksek uyum sınıfın anlaşılmasını, yeniden kullanılmasını ve bakımını kolaylaştırır; sınıfın değişikliklerden etkilenme olasılığını düşürür. Genellikle düşük bağlaşım getiren bir tasarım yüksek uyumu, yüksek bağlaşım getiren bir tasarım ise düşük uyumu beraberinde getirir. Bu derste bu ilkelerin üzerine tasarım kalıpları konusu açıldı.

## 2. Tasarım Kalıpları Neden Önemli?

İyi bir tasarım yapmaya çalışsak ve bunun ölçütlerini belirlesek de her tasarımı sıfırdan bulmamız gerekmez. Hocanın deyişiyle tekerleği yeniden icat etmeye gerek yoktur. Bir problem alanındaki ilişkilerden yola çıkarak nesneye yönelik modelleme ve tasarım yaparken sık sık karşılaşılan (recurring) bazı durumlar vardır. Bunları kendimiz de düşünüp güzelce modelleyebiliriz. Ancak deneyimli kişiler bu problemler üzerinde uzun uzun düşünmüş, iyi çözümler önermiş ve bu çözümleri avantajları ve dezavantajlarıyla birlikte hazır bir deneyim olarak sunmuştur. Bu çözümlerden haberdar olursak modelleme ve tasarım aşamalarımız kolaylaşır.

Önceki yıl nesneye yönelimin temel ilkeleri, kavramları ve prensipleri öğrenildi. Hocaya göre bu noktadan sonra, özellikle yazılım geliştirme alanında çalışacak biri için ilerlenmesi gereken yer tasarım kalıplarıdır. Tasarım kalıplarına uymak daha esnek ve daha iyi bir tasarım elde etmeyi sağlar.

> **Hocanın vurgusu:** Tasarım kalıpları teknik mülakatlarda karşınıza çıkar ve yazılım alanında çalışacaksanız bunları mutlaka kullanmanız gerekecektir. Bu konuya zaman ve çaba ayırın, yatırım yapın.

### 2.1 Temel kaynak

Konunun temel kaynağı "Dörtlü Çete" (Gang of Four, GoF) diye anılan dört yazarın kitabıdır: *Design Patterns – Elements of Reusable Object-Oriented Software*, Erich Gamma et al., Addison-Wesley, 1994 (ekrandan, 00:15:00). Tasarım kalıbı denince akla gelen kitap budur. Kitap kütüphanede basılı olarak ve abonelik kapsamında elektronik olarak bulunmaktadır. Konu çok yaygın olduğu için internette de pek çok iyi anlatım vardır.

> **Ek bilgi (derste anlatılmadı):** Dörtlü Çete'nin dört yazarı Erich Gamma, Richard Helm, Ralph Johnson ve John Vlissides'tir. Derste hoca üç yazarı saydı, dördüncüsünü hatırlayamadı.

Ek kaynaklar farklı bir yol izler. Bazıları her bölümde bir problem ve bir kalıp anlatır. Bazıları büyükçe bir bilgi sistemini gerçeklerken karşılaşılan problemleri tasarım kalıplarıyla çözerek "yaparak öğretme" yolunu izler. Kalıpların birlikte kullanımını görmek için bu kaynaklardan da çalışmak yararlıdır.

## 3. Tasarım Kalıbı Nedir ve Bileşenleri Nelerdir?

Tanım olarak tasarım kalıbı, yazılım tasarımında karşılaşılan belirli sorunların yalın ve güzel çözümlerinin tarifidir (ekrandan, 00:20:00). Çözüm somut olabileceği gibi biraz soyut da kalabilir. Hoca, hem anlatım kolaylığı hem de Dörtlü Çete'nin de aynı sırayla gitmesi nedeniyle konuyu Model-View-Controller kalıbıyla bağlayacağını söyledi. Bu ilk kalıp biraz soyut gelebilir; diğer kalıplar genelde daha ayrıntılı bir ana tasarımla anlatılır. Amaç, yeniden keşfetmeden iyi bir tasarıma ulaşmak ve sonunda esnek, yeniden kullanılabilir bir çözüm elde etmektir.

Bir tasarım kalıbı önerebilmek için aşağıdaki bileşenlerin hepsinin ele alınması gerekir.

### 3.1 İsim

Kalıbı en güzel şekilde anlatan bir ya da birkaç kelimelik bir isimdir. İsmi ilk gördüğünüzde her şeyi anlamazsınız. Ama kalıbı çalışıp özümsedikten sonra ismin kalıbı çok güzel özetlediğini, ana fikrini taşıdığını görürsünüz. Kendiniz bir kalıp önerecekseniz çözümü inceleyip ayırt edici özelliğinin ne olduğunu düşünerek isimlendirmelisiniz. Hoca, iyi bir isim vermenin kolay olmadığını, düşünüp emek vermek gerektiğini ekledi.

### 3.2 Sorun

Kalıbın hangi sorunu çözmeye çalıştığı güzelce tarif edilmelidir. Sorun kelimelerle anlatılınca basit görünebilir. Ancak çözüm kısmının ayrıntıları görülünce düşünülmesi gereken çok şey olduğu ve farklı problemler için farklı avantaj ve dezavantajlar çıktığı anlaşılır.

### 3.3 Çözüm

Sorunu çözmek için önerilen tasarımın bileşenleri anlatılır: bu bileşenlerin ilişkileri nedir, sorumlulukları nelerdir, birlikte nasıl çalışırlar? Nesneye yönelimden söz edildiği için bileşenler aslında sınıflardır.

### 3.4 Tartışma ve sonuçlar

Önerilen çözümün sistemin bütününe esneklik, yeniden kullanılabilirlik, genişletilebilirlik ve taşınabilirlik açısından etkileri anlatılır. Çözümün güçlü ve zayıf yönleri, hangi problemlere uygun olup hangilerine uygun olmadığı tartışılır.

Bu bölümde yer-zaman çelişkileri (time-memory trade-off) de ele alınır. Bir problemi çözerken daha fazla bellek kullanma pahasına daha kısa zamanda çözmeyi seçebilirsiniz. Örneğin gerçek zamanlı uygulamalarda önceden hesaplanmış tablolar bellekte tutulur ve yeniden hesaplamak yerine tablodan bakılır (look-up). Bu yol, işlemci kaynağı görece düşük ama bellek kaynağı görece yüksek sistemlerde de seçilir. Tersine, bellek kısıtlıysa geçici değişkenler ve ara hesap sonuçları tutulamaz; bazı hesaplar her seferinde yeniden yapılır. Hoca, algoritma önerirken bu ikisini birlikte en iyilemeye çalışan çözümler üzerinde de düşünüldüğünü ekledi.

Son olarak başka kalıplarla işbirliği olanakları anlatılmalıdır. Bir tasarım kalıbı çoğu zaman daha büyük bir problemin yalnız bir parçasını çözer. Diğer parçalar çözülürken o parçaların kalıplarıyla en uygun biçimde nasıl etkileşim kurulacağını anlatmak yararlıdır.

## 4. Tasarım Kalıplarının Yararları

Slayttaki yararlar dört maddedir (ekrandan, 00:25:00):

- Tekerleği yeniden icat etmemek.
- Üzerinde birçok deneyimli kişinin emeği geçtiğinden "kaliteli" bir çözüm.
- Deneyimin yazılı biçimde aktarılabilmesi.
- Yazılım ekibi arasında ortak bir sözlük oluşturması.

**Daha az çabayla iyi bir çözüm.** Tekerleği yeniden icat etmeden, daha az çaba harcayarak iyi bir çözüme ulaşılır. Çözümün iyi olması, üzerinde birçok deneyimli kişinin emeği geçmesinden gelir. Yine de hoca bunun gözü kapalı kabul edilmemesi gerektiğini söyledi. Çalışmalarda tasarım kalıplarıyla yapılan çözümlerin çeşitli kalite ölçütlerinde iyileşme sağladığı genelde gösterilir. Bazı ölçütlerde gerileme olabilir; ama bu gerileme gelecekteki gereksinim değişikliklerine daha rahat uyum sağlanarak telafi edilir.

**Deneyimin aktarılması.** Deneyim normalde bir şey üzerinde çalışarak kazanılır, hazır gelmez. Tasarım kalıpları ise deneyimi, hocanın deyişiyle "hap gibi", yazılı biçimde sunar. Tasarım kalıpları çalışıldıkça kalıplarla henüz çözülmemiş başka problemlerde de daha iyi çözümler üretme birikimi artar. Bir konuda ne kadar haşır neşir olunursa o konudaki yetenek o kadar gelişir.

**Ortak sözlük.** Hoca bir tasarım toplantısı örneği verdi. Ekipten biri "Bölme algoritması zamanla çok sık değişebiliyor; burada strateji kalıbını kullanalım" der. Bir başkası "Evet, ama algoritmaların temeli değişmemeli, yalnız bazı alt adımlarında düzenleme yapılabilmeli; o yüzden template method kalıbı iyi olur" der. Ekipteki herkes hangi kalıbın nerede kullanıldığını biliyorsa bu birkaç kısa cümle tasarımı hızla belirli bir noktaya getirir. Kalıbı bilmeyen birine ise "bir üst sınıf olsun, soyut olsun, şu metotları soyut, şu metotları somut olsun, alt sınıflar bunları geçersiz kılsın" diye uzun uzun anlatmak gerekir. Template method kalıbını bilen biri bunu tek kelimeyle anlar.

## 5. "Kalıp" Tartışması ve GoF Sınıflandırması

### 5.1 Neye kalıp denir?

Bir kişinin "kalıp" dediği şeye bir başkası "basit bir yapı taşı" ya da "temel bir ilke" diyebilir (ekrandan, 00:30:00). Hoca her iki tarafın da kendi açısından haklı olabileceğini, bu tartışmaya girmeye gerek olmadığını söyledi; zaten bir tasarım kalıbının çok somut olması gerekmez.

"Tasarım kalıbı" (design pattern) terimi mimarlıktan gelir. Yazılım mühendisliği görece yeni bir meslek olduğu için daha eski mesleklerden terim alır. Örnek bir mimari tasarım kalıbı şudur: içinde bir insanın bir saatten fazla zaman geçireceği her bölmede mutlaka bir pencere olmalıdır. Bu kalıba uyulmazsa orada çalışanların verimliliği düşer, yapay aydınlatma gerektiği için elektrik masrafı artar, daha kalın kablo hatları gerekeceği için inşaat maliyeti artar. Bir-iki cümlelik bu ifade bile mimaride bir tasarım kalıbı sayılır. Bu yüzden MVC gibi biraz soyut kalan bir çözüm de tasarım kalıbı adını hak eder.

Tasarım kalıpları bilgisayar bilimlerinde Dörtlü Çete'nin kitabıyla popülerlik kazandı; yararları hızla görülünce sektörde yoğun biçimde kullanılmaya başlandı.

### 5.2 Üç küme

Eserde GoF kalıpları amaçlarına göre üç kümeye ayrılır (ekrandan, 00:30:00):

- **Creational (Yaratımsal):** Nesnelerin oluşturulması, temsili ve ilişkilendirilmelerindeki bağımlılığı azaltmaya yönelik kalıplardır. Yani bağlaşımı (coupling) düşürmeye yöneliktir.
- **Structural (Yapısal):** Sınıflar ve nesnelerin bir araya getirilerek daha büyük yapılar elde edilmesine yönelik kalıplardır.
- **Behavioral (Davranışsal):** Sorumlulukların nesnelere dağıtılmasına ve algoritma seçimine esneklik kazandırılmasına yönelik kalıplardır.

Hoca, bir kalıbın iki aileye birden konduğunu ama hangisi olduğunu o an hatırlayamadığını söyledi; meraklı olanların kitabın giriş bölümlerindeki sınıflandırmaya bakmasını önerdi. <!-- BELİRSİZ: Hangi kalıbın iki aileye konduğu derste belirtilmedi. -->

### 5.3 Kalıp kullanmanın bedeli

Bir problemi hem tasarım kalıbıyla hem kalıpsız çözdüğümüzde, kalıpsız çözümün bağlaşımı bazen daha düşük çıkabilir; hoca bunu "%10, %15, %20 kadar" diye örnekledi. Kalıplı çözümün getirdiği şey, yakın gelecekte olası gereksinim değişikliklerine karşı bağışıklıktır. Öte yandan önceki derslerde "şu anki gereksinimlere göre tasarla, geleceği düşünme" ilkesi, özellikle çevik çalışırken "basit tut" (keep it simple) ilkesi önerilmişti. Bu yüzden karar duruma göre verilir: yakın gelecekte gereksinim değişikliği öngörülüyor ve bundan eminseniz tasarım kalıbıyla biraz daha ağır bir çözüm yapabilirsiniz. Böyle bir durum yoksa eldeki problemi en iyi çözen tasarımı uygulayıp kalıptan vazgeçebilirsiniz.

## 6. Örnek Tasarım Kalıbı: Model-View-Controller (MVC)

MVC denince bazen önce Microsoft'un MVC framework'ü akla gelir. Hoca, o framework'ün de bu tasarım kalıbına dayandığını, özünde MVC kalıbı bulunduğunu söyledi. Kalıp başka pek çok yerde de kullanılır; hocaya göre Java'nın GUI framework'leri de bu kalıbı kullanır, çünkü kalıp tam olarak bu alana yöneliktir.

### 6.1 Sorun ve çözüm

Slayttaki tarif şöyledir (ekrandan, 00:35:00):

- **Sorun:** Aynı veriyi farklı biçimlerde gösterebilmek istiyoruz. Kullanıcıya verinin nasıl ve ne kadarının gösterileceğini seçebilme gibi olanaklar sağlamak istiyoruz.
- **Çözüm:** Veriyi, verinin gösterimini ve gösterimin yönetimini ayrı sınıflar şeklinde ele almak.

Çözümün arkasında daha önce görülen genel bir ilke vardır: neyin değiştiğini bul ve onu sarmala (encapsulate). Veri, gösterim ve gösterimin yönetimi ayrı sorumluluklardır; ayrı sorumluluklar da ayrı sınıflar demektir.

### 6.2 Sınıflar ve bağlaşımlar

Kalıbın adı sınıflarının baş harflerinden gelir. Slayttaki şema metin olarak şöyledir (ekrandan, 00:35:00):

```text
            +------------+
            | Controller |
            +------------+
             |          |
             v          v
        +------+     +-------+
        | View | --> | Model |
        +------+     +-------+
```

- **Model sınıfı:** Ham veriyi simgeler.
- **View sınıfı:** Verinin çeşitli gösterim biçimlerini simgeler.
- **Controller sınıfı:** Kullanıcı komutlarını alıp işler; bu komutlar nedeniyle View ya da Model üzerinde işlemler yürütür.

Bağlaşımların yönü önemlidir. Model'den çıkan ok yoktur; Model hiçbir sınıfa bağımlı değildir. Model gösterilmeyi bekleyen veridir; onu View ve Controller kullanır. View'dan Model'e ok vardır, çünkü View veriye erişip uygun biçimde gösterecektir. Controller, kullanıcının verinin bir kısmını görmek, bir kısmını gizlemek ya da filtreleme yapmak gibi komutlarını alır ve View'a bunların gereğini yaptırır. Model'de bir değişiklik gerekiyorsa probleme göre Controller bunu doğrudan yapabilir ya da View'a yaptırabilir. Gerekli işlemlerin başlangıç noktası Controller'dır. Şemadaki bağlaşımlar en az olması gerekenlerdir; ihtiyaç olursa başka bağlaşımlar da çizilebilir.

### 6.3 Ressam benzetmesi

Kalıp genelde bir ressam ve çizdiği resim üzerinden anlatılır; veriye "model" denmesinin nedeni de budur. Diyelim ki bir ressama resmimi yaptırıyorum. Ben ressama modellik ederim, yani modelim. Resmin nasıl çizileceğini de ben söylerim: "beni tam boy çiz", "beni portre olarak, omuzlarımdan yukarısını çiz" ya da "beni karikatür olarak çiz" diyebilirim. Karikatürde ressam bazı özellikleri abartır; tam boy resimde portrede görünmeyen ayrıntılar da görünür. Sevdiğim bir etkinliği yaparken çizilmeyi de isteyebilirim. Bu durumda talebi ben söylerim, ressam view'u ona göre ayarlar. Ressam kendisi bir eser ortaya koymak isterse ve ben yalnız model olursam, ressam aynı zamanda kontrolcü olur: hangi view'u kullanacağına kendisi karar verir ve çizimini ona göre yapar.

## 7. MVC'nin Yararları

Slayttaki yararlar şunlardır (ekrandan, 00:40:00): gösterim, kontrol ve veriyi birbirlerinden ayırarak

- bunları çalışma anında değiştirebilmek,
- ilgi alanlarının ayrılmasını sağlamak,
- yeniden kullanımı arttırmak.

### 7.1 Çalışma anında değiştirebilme

Birden fazla view olabilir. Hoca slayttaki şemaya View sınıfından kalıtımla türeyen VA ve VB alt sınıflarını çizdi (ekrandan, 00:45:00). Kullanıcı bir seçenek seçerek ya da bir komut vererek VA, VB ya da başka bir alt sınıftan bir nesne üzerinden görüntülemeye geçebilir. Kontrolcüye hangi view ile çalışacağını biz de söyleyebiliriz. Bunlar ayrılmasaydı gösterimi değiştirmek için programı kapatıp kaynak kodu ya da yapılandırmayı değiştirip yeniden çalıştırmak gerekirdi. Ayırarak, sistemin geri kalanını etkilemeden çalışma anında değiştirme ve geliştirme olanağı elde edilir.

### 7.2 İlgi alanlarının ayrılması ve yeniden kullanım

Veri, gösterim ve kontrol üç temel sorumluluktur. İlgi alanlarını ayırmak doğrudan iyi bir tasarıma götürür: problem hangi düzeyde bileşenlere ayrılabiliyorsa tasarım da o düzeyde bileşenlere ayrılmalıdır. Yeniden kullanım da artar; belirli bir view türü uygun başka modellerle de kullanılabilir.

### 7.3 Seçim yayını örneği

Hoca bütün bileşenleri anlattığı için bu örneği sevdiğini söyledi. Seçim gecesi televizyonlarda sürekli çeşitli veriler gösterilir: açılan sandıklar, sandıklardan çıkan oylar, sandıkların açılma yüzdesi, il düzeyinde sonuçlar; üç bölgeye ayrılan büyük bir şehrin hem genel hem bölge düzeyindeki sonuçları. Bu sonuçlar kimi zaman sayılarla, kimi zaman pasta grafikle, kimi zaman çubuk grafikle, kimi zaman harita üzerinde en çok oyu alan partinin rengiyle gösterilir. Haber spikeri "şimdi şu görüntüye geçelim", "şuradaki sandıklar açıldı, oraya bakalım" diyerek sürekli neyin, ne kadarının ve nasıl gösterileceğini kontrol eder. Burada veriler model, grafikler ve harita view, spiker controller rolündedir. Bir kez pasta grafik (pie chart) ya da çubuk grafik (bar chart) bileşeni yazıldığında farklı problemlerde kolaylıkla yeniden kullanılabilir.

## 8. MVC Çeşitlemeleri

Temel yapı, eldeki problemin ayrıntılarına göre çeşitli varyasyonlara tabi tutulabilir. Bunların hepsi Dörtlü Çete'nin kitabında tartışılır. Slayttaki çeşitlemeler şunlardır (ekrandan, 00:45:00):

- Model'in geçirdiği değişiklikleri View'a bildirmesi
- Birden fazla view: iç içe (nested), ayrı/tek görevcikte (thread), örtüşen/ayrık
- Birden fazla kontrolcü: farklı denetim biçimleri (klavye, fare, ses, ...)

### 8.1 Model'in değişiklikleri View'a bildirmesi

Model'deki bir veri değiştiğinde View bunu nasıl fark etmelidir? İlişkileri artırmak istemiyorsak View zaman zaman Model'e "değiştin mi?" diye sorar. Model değiştiyse View ya bütün veriyi ya da o anda göstermesi gereken kadarını Model'den çeker. Bu ise View'un belirli aralıklarla Model'i sorgulamasını gerektirir. Model ve View ağ ile bağlı farklı bilgisayarlardaysa bu sorgulamalar hem zaman hem haberleşme yükü getirir; tarifeli bir bağlantıda (örneğin mobil veri) ek haberleşme masrafı da çıkar. Hocanın deyişiyle View boş yere "değiştin mi? değişmedim" diye sorup durur. Model değiştiğini kendisi bildirebilseydi daha az haberleşme yapılırdı.

Bu maliyet önemli ve kritikse Model'in View'u bilmesi yararlı olur; o zaman Model'den View'a doğru da bir ok çizilir. Model o anda hangi view'larla ilişkili olduğunu bilir; bir güncelleme olunca ilişkili View'a "ben değiştim" der. View de Model'den değişen veriyi ya da bütün veriyi çeker; nasıl davranacağına View karar verir. Bu noktada işin içine başka bir tasarım kalıbı, Observer kalıbı girer. Yani gerekirse MVC'de Model ile View arasında Observer kalıbı da kurulabilir.

Önceki yıl nesneye dayalı programlamada çift yönlü ilişkilerin kurulmasının ve tutarlılığının korunmasının daha karmaşık olduğu görülmüştü. Gereksinim çift yönlü ilişki gerektiriyorsa kurulur; gerektirmiyorsa tasarıma boş yere ek karmaşıklık ve bağlaşım katılmaz.

> **Ek bilgi (derste anlatılmadı):** Observer (gözlemci) kalıbı GoF'un davranışsal kalıplarındandır. Bir nesnenin (özne) durumu değişince ona abone olan nesnelere (gözlemciler) otomatik olarak haber verilir. Özne, gözlemcileri yalnız ortak bir arayüz üzerinden tanıdığı için aralarındaki bağlaşım gevşek kalır.

### 8.2 Birden fazla view

Şemada nicelikler yazılı değildir. Hoca şemaya nicelikleri ekledi (ekrandan, 00:50:00). Belirli bir anda bir view bir modelle ilişkilidir. Ama bir kontrolcünün her zaman tek bir view ile ilişkili olması gerekmez; Controller ile View arasındaki ilişkinin View tarafına `1..*` yazılabilir. Özellikle VA, VB gibi alt sınıflarla farklı view'lar oluşturulmuşsa kontrolcü hepsinden birer örnek tutabilir ve istendiğinde birinden ötekine geçebilir; belirli bir anda birden fazlasıyla da çalışabilir.

**Örtüşen view'lar.** Örneğin bir denetim ekranında dört-beş farklı panel olsun ve her biri modelin farklı bir kısmını göstersin. Bu kısımlar kesişebilir. Seçim örneğinde bir panel sandıkların yarısından fazlasının açıldığı illeri, öbür panel A partisinin önde olduğu illeri gösterebilir; bazı iller iki panelde de, bazıları tek panelde görünür. Model ve view ayrıştırıldığı için yalnız gösterimde bu sorun yaratmaz. Ama kullanıcıdan Model'de değişiklik yapma talebi geliyorsa durum değişir. Seçim yayınında böyle bir talep yoktur; ama imzalı ve mühürlü sandık tutanaklarının sisteme girildiği bilgi sisteminde vardır. Böyle bir durumda giriş işlemlerini view üzerinden değil Controller üzerinden kodlamak yararlıdır. Çünkü bir view yaptığı değişikliği Model'e aktarır, ama öbür view'un bundan haberi olmayabilir. Model'in view'ları bilgilendirmesine dair çözümlerden bazıları bu durumda daha iyi işleyebilir ya da ek işlemler gerekebilir; bunları düşünüp koda katmak gerekir.

**İç içe view'lar.** View'lar iç içe de olabilir. Hoca, metot içinde metot çağrısına benzer bir durum olduğunu söyledi ama pratik bir örnek vermedi.

**Görevcikler.** Birden fazla view olduğunda her biri farklı görevciklerde (thread) çalışıyorsa eşzamanlama (senkronizasyon) sorunları çıkabilir. Önceki yıl nesneye dayalı programlama dersinin son haftalarında çok görevcikli programlamaya girişte görüldüğü gibi yarış durumlarını (race condition) engellemek gerekir; burada da buna dikkat edilmelidir.

### 8.3 Birden fazla kontrolcü

Bir başka çeşitleme birden fazla kontrolcü olmasıdır. Örneğin bilgisayara veri girişi bazen klavyeyle, bazen sesle yapılabilir. Hoca şemaya bunun için CA ve CB adlı farklı kontrolcü sınıfları çizdi. Sistem çalışırken önce "şu kontrolcüyle başla" denip, duruma göre yeni bir kontrolcüye geçen kod yazılabilir. Bunlar yalnız gerekiyorsa yapılır; hocanın vurgusuyla, ne gerekiyorsa o yapılmalıdır.

## 9. Tasarımın Belgelendirilmesi

Gereksinimler için Yazılım Gereksinim Belirtimi (SRS, Software Requirements Specification) belgesi ve bunun bir standardı vardır. Tasarım için bu kadar ayrıntılı bir standart olmasa da genelde UML şemalarına başvurulur. Slayttaki maddeler şunlardır (ekrandan, 00:55:00):

- Bir nesneye yönelimli programın tasarım sürecinin belgelendirilmesinde yer alan önemli belgeler: ayrıntılı UML sınıf şemaları vazgeçilmezdir.
- Tasarımın ihtiyaçlarına göre şu belgelerin çeşitli bileşimleri de kullanılabilir:
  - Sözleşmeler
  - UML etkileşim şemaları (interaction diagrams): sıralama şemaları (sequence diagrams) ve işbirliği şemaları (collaboration diagrams)
  - UML etkinlik şemaları (activity diagrams)
  - UML durum diyagramları (state diagrams)

UML etkileşim şemaları, nesnelerin çalışma anındaki davranışını gösteren şemalardır. Sıralama şemaları önceki yıl nesneye yönelim dersinde görülmüştü; bu derste kısaca hatırlatıldı. Etkinlik ve durum şemaları sonraki derslere bırakıldı.

## 10. Sözleşme ile Tasarım (Design by Contract)

### 10.1 Sözleşme nedir?

Bir sözleşme, belirli bir kullanım senaryosunun ayrıntılandırılmasıyla elde edilir; her metot bir sözleşmeyle ayrıntılandırılabilir. Sözleşmeler bir metodun çalışma anında nasıl yürütüleceğini koda yakın bir biçimde anlatmak için hazırlanır. Tasarım sözleşmeler üzerinden yapılırsa geriye yalnız bunu koda dökmek kalır. Ancak bütün bir tasarımı sözleşmelerle hazırlamak verimli değildir. Kritik bazı sorumluluklar söz konusuysa onlara sözleşme yazmak yararlıdır; onun dışında pek gerekmez.

### 10.2 Örnek sözleşme: satış kalemi girişi

Derste bir örnek sözleşme gösterildi. Sözleşmeye numara ve ad verilir: "Sözleşme No 2: Satış kalemi girişi". Satış kalemi önceki derste tartışılan kritik bir konuydu; bu yüzden ayrıca belgelendirilmesi istenebilir. Ya da geliştirme sürecinde o aşamada işlem çok ayrıntılı konuşulmamıştır ve kodlarken yanlışlık yapılmasın diye sözleşmeyle ayrıntılandırılır.

Sözleşmenin bölümleri şunlardır:

- **İşlem:** Sözleşmenin tarif ettiği metot yazılır. UML gösterimiyle (örneğin `barkod: String`) ya da doğrudan kodlama dilinin gösterimiyle (örneğin `String barkod`) yazılabilir; derste UML gösterimi kullanılmıştı. <!-- BELİRSİZ: Sözleşme slaytı karelerde yok; işlemin tam adı ve parametre listesi altyazıdan kesin okunamadı. -->
- **İlişkili kullanım senaryosu:** Sözleşmenin hangi kullanım senaryosuyla ilişkili olduğu.
- **Ön koşullar:** Metodun yürütülebilmesi ve işe yarar anlamlı bir iş yapabilmesi için sistemin içinde bulunması gereken durum.
- **Son koşullar:** Metodun tanımlandığı sınıfın nesnesinde ya da onunla sahiplik, parça-bütün veya diğer ilişki türleriyle bağlı başka sınıfların nesnelerinde meydana gelen her türlü yeni oluşturma, ilişki kurma ve ilişki değiştirme eylemi ile üye alan değişiklikleri.

Satış kalemi girişi örneğinin son koşulları altyazıdan şöyle aktarılabilir:

- Bir satış kalemi nesnesi oluşturulmuştur.
- Satış kalemi, süregelen satış nesnesiyle ilişkilendirilmiştir.
- Satış kalemi nesnesinin miktar üye alanına malın satış adedi atanmıştır.
- Satış kalemi, satılan malla uyuşan barkod sayesinde bir ürün nesnesiyle ilişkilendirilmiştir.

Kurulması gereken bütün ilişkiler, oluşturulması gereken bütün nesneler ve bunlarla ilgili durumlar yazılır. Hocanın ifadesiyle böyle olunca kodun nasıl yazılacağına dair ayrıntıların yaklaşık %80'i sözleşmeden görülüp anlaşılabilir; sözleşmenin yararı budur.

### 10.3 Sözleşmeler hakkında ayrıntılar

Slayttaki maddeler şunlardır (ekrandan, 01:00:00):

- Ön koşullar tüm sistem hakkındaki bilgilerdir.
- Son koşullar sadece problem alanı ile ilgili nesnelerin durum değişiklikleri hakkındadır.
- Sözleşmeler her zaman gerekli olmayabilir.
- Son koşullarda edilgen geçmiş zaman kullanılması, bunların işlemin sonunda tamamlanmış eylemler olduğunu vurgulamak açısından yerinde olacaktır.
- Sözleşme içerisinde ilişkilerin kurulmasını belirtmeyi unutmayın!
- Sözleşme yazılması problem alanı çözümlemesinde güncellemelere yol açabilir.

Ön koşullar tüm sistem hakkındadır, çünkü metot başlamadan önce bütün sistemin durumu göz önüne alınır. Son koşullarda edilgen geçmiş zaman ("oluşturulmuştur", "ilişkilendirilmiştir") kullanılır, çünkü metot tamamlandıktan sonraki durumu anlatır. Kullanım senaryosu metinlerinde ise tersine her adım etken çatıyla ve geniş ya da şimdiki zamanla yazılır.

Sözleşme ayrıntısında düşünürken çözümleme aşamasında bir şeyin eksik kaldığı fark edilebilir ve orada düzeltme yapılabilir. Böylece analiz aşamasındaki bir problem hiç olmazsa tasarım aşamasında, kodlamaya geçmeden yakalanır. İdeali, problemi kendi aşamasında biçimsel bir teknik gözden geçirmeyle (formal technical review) bulmaktır; ama her zaman bulunamayabilir. Sınama, bütün hataların yakalanacağı bir güvenlik ağı gibi düşünülmemelidir; mutlaka gözden kaçan şeyler olur.

## 11. Sıralama Şemalarının Hatırlatılması

Bu konu "Nesneye Dayalı Kavramlar" dersinde edinilen altyapının bir hatırlatmasıdır (ekrandan, 01:05:00). Slayttaki şema metin olarak şöyledir:

```text
 nesne1: Sınıf1                         nesne2: Sınıf2
      |                                      |
     [ ]  [koşul] değişken := birMetot(      |
     [ ]         param1: Tip, ... )          |
     [ ] ---------------------------------> [ ]
     [ ] <- - - - - - - - - - - - - - - - - [ ]
     [ ]                                     |
     [ ]--+                                  |
     [[ ]<+   (nesnenin kendi metodunu çağırması)
     [ ]                                     |
```

Slaydın sağındaki gösterim açıklamaları:

| Gösterim | Anlamı |
|---|---|
| Düz ok | Mesaj (metot çağırma) |
| Kesikli ok | Geri dönüş (ihmal edilebilir) |
| `[koşul]` ile ok | Koşullu mesaj (if) |
| `*[koşul]` ile ok | Döngülü mesajlar (for, while vb.) |
| `new` ile ok | Nesne oluşturma |
| İç içe activation bar | Nesnenin kendi metodunu çağırması |

### 11.1 Nesne kutusu

Nesne kutusuna nesnenin adı, iki nokta üst üste ve nesnenin türü (sınıfı) yazılır ve altı çizilir: `nesne2: Sınıf2`. Tek bir metodun şeması çiziliyorsa çağıran tarafı ayrıntılı yazmaya gerek yoktur; hoca slaytta çizdiği dikey çizginin sağının yeterli olduğunu gösterdi. Ama şema daha geniş bir senaryonun parçasıysa metodu çağıran nesne de belli olabilir.

### 11.2 Mesaj okunun üzerindeki yazı

Metoda parametre veriliyorsa her biri `parametreAdı: Tip` biçiminde yazılır, birden fazlaysa virgülle ayrılır. Metodun döndürdüğü bir değer varsa bu değer isteğe bağlı olarak geri dönüş okunun üstüne yazılabilir. Dönen değerin bir değişkene atandığı da gösterilebilir. Slaytta atama için Pascal gösterimine benzer `:=` kullanılmıştır; normal `=` de kullanılabilir.

Metot çağrısı bir if koşuluna bağlıysa koşul köşeli parantez içinde, ok üzerindeki yazının en başına konur. Döngü için yıldız kullanılır. Örneğin Sınıf2 türünden nesnelerin bir dizisi varsa ve dizideki bütün nesneler için bir metot çağrılıyorsa yalnız `*` koyup metodu yazmak yeterlidir; yıldız çokluk belirtir ve for döngüsü anlamına gelir. Bir while döngüsü anlatılacaksa ya da döngünün devam koşulu ayrıntılı yazılmak isteniyorsa yıldızın yanına köşeli parantez içinde koşul da yazılır. İster döngü koşulu (başında yıldız ile) ister if koşulu (yıldızsız) olsun, koşul her zaman en başa yazılır. Çağrılan metot bir kurucu (constructor) ise yalnız `new` yazmak yeter; parametre varsa parantez içinde yazılır.

### 11.3 Nesnenin kendi metodunu çağırması

Bir nesnenin bir metodu yürürken o metodun içinde nesne kendi başka bir metodunu çağırırsa kendisinden kendisine giden bir ok çizilir ve içeride ikinci bir dikdörtgen çizilir. Bu dikdörtgene activation bar denir. Bu durumda geri dönüş oku çizilmez, çünkü iç dikdörtgenin alt ucu o metodun sona erdiği noktayı gösterir. Buna karşılık metot içinde başka bir nesnenin metodu çağrılırsa ondan çıkan çağrı oku ve çağrı tamamlandığında geri dönen kesikli ok ile gösterilir.

### 11.4 Ok hangi nesneye girer?

> **Hocanın vurgusu:** Bir ok bir nesneye giriyorsa okun üzerindeki metot o nesnenin sınıfında tanımlı bir metot olmalıdır; aksi halde şema yanlıştır.

Slayttaki örnekte `birMetot` Sınıf2'de tanımlı olduğu için ancak Sınıf2 türünden bir nesneye giren okun üzerine yazılabilir. Sık yapılan bir hata, çağıran nesne1 olduğu için okun nesne1'e doğru çizilip üzerine bu metodun yazılmasıdır. Hangi metodun nerede tanımlı olduğuna sınıf şemasından bakılır; metot Sınıf2'deyse Sınıf1'den bir nesneye böyle bir çağrı yapılamaz.

## 12. Uygulama: Person.introduceSelf() için Sıralama Şeması

### 12.1 Car sınıfı

Hoca önce nesneye dayalı programlama dersinin malzemesinden Car sınıfını açtı (ekrandan, 01:15:00). Slayttaki UML sınıf şemasında Car sınıfının `- plate : String` üye alanı ve `+ Car(plateNr : String)`, `+ getPlate() : String`, `+ setPlate(String)`, `+ introduceSelf()`, `+ main(String[])` metotları vardı. Slayttaki kod şudur:

```java
package nyp01a;
public class Car {
    private String plate;
    public Car( String plateNr ) {
        plate = plateNr;
    }
    public String getPlate() {
        return plate;
    }
    public void setPlate(String plate) {
        this.plate = plate;
    }
    public void introduceSelf( ) {
        System.out.println( "My plate: " + getPlate() );
    }
    public static void main( String[] args ) {
        Car aCar;
        aCar = new Car( "34 RA 440" );
        aCar.introduceSelf( );
    }
}
```

Slayttaki öneriler: önce sınıf şeması çizilmeli, sonra şema koda dökülmeli; düzgün biçimlendirme ve deve yazımı (camel casing) gibi kurallara uyulmalı.

Hoca ardından plaka ve şasi numarası alanları olan bir Car sürümünü anlattı. Bu sürümde kurucu iki parametre alır. Hoca, şemada parametre adlarının da yazılmasının (yalnız tür yazmak yerine) hangi parametrenin hangisi olduğunu daha açık göstereceğini söyledi. Hocaya göre plaka için get ve set metotları, şasi numarası için yalnız get metodu vardır, çünkü bir aracın şasi numarası değiştirilemez. <!-- BELİRSİZ: Eclipse karesinde (ekrandan, 01:20:00) açık olan nyp01b paketindeki Car.java'da setChassisNR metodu da görünüyor; hocanın anlattığı sürümle bu dosya aynı olmayabilir. --> Hoca bu örneğin bir sıralama şeması için fazla basit kaldığını söyleyip iki sınıf arasında ilişki olan örneğe geçti.

### 12.2 Person ve Car ilişkisi

Tasarımda bir Person sınıfı vardır. Kişinin bir adı vardır ve bir kişi bir arabaya sahip olabilir. Sınıf şemasında Person'dan Car'a giden, ucu açık oklu düz bir çizgi vardır: "bir kişi sıfır ya da bir arabaya sahiptir".

**Neden 0..1?** Person'ın kurucusuna isim verilir ama araba verilmez. Demek ki bir kişi arabasız oluşturulabilir; araba daha sonra setter metoduyla atanır. Nicelik bu yüzden 0..1'dir. Sahiplik ilişkisi Person tarafında Car türünden bir üye alan olarak kendini göstermek zorundadır.

Eclipse'te açılan Person kodu şudur (ekrandan, 01:25:00):

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
        intro += " and I have a car with licen..." // satır ekranda kesik
            + car.getPlate();
    intro += ".";
    return intro;
}
```

`introduceSelf()` kişinin kendisi hakkında bilgi içeren bir metin oluşturup döndürür. Her insanın bir ismi vardır ama her insanın arabası olmayabilir. Bu yüzden metinde isim her zaman yer alır; araba plakası ise yalnız `car` üye alanı `null` değilse eklenir.

Hoca iki bakış açısının da mümkün olduğunu söyledi. Kod henüz yazılmamışsa önce sıralama şeması tasarlanıp sonra koda dökülebilir. Ya da metot önemli ve karmaşık bir metottur; kaynak koda bakmadan nasıl çalıştığının şemadan anlaşılabilmesi için belgelenmek istenir. Derste anlatımı netleştirmek için kod bir tarafta açılıp şema ondan çizildi.

### 12.3 Şemanın adım adım çizimi

Şema Violet UML Editor ile çizildi (ekrandan, 01:25:00 ve 01:35:00). Adımlar şunlardır:

1. Paletten "Object lifeline" seçilip bir nesne konur ve adı `:Person` yazılır. Nesnenin adı önemli değildir; iki nokta ve sınıf adı "bir Person nesnesi" anlamına gelir. Araç alt çizgiyi kendisi ekler.
2. `introduceSelf()` public bir metot olduğu için herhangi bir nesne çağırabilir. Bu yüzden çağıran için adı boş bırakılmış bir "dummy" nesne konur. İki nesneye de activation bar eklenir.
3. "Call / Create message" aracıyla boş nesneden `:Person` nesnesine bir ok çizilir ve üstüne `introduceSelf()` yazılır.
4. Kodda tanımlanan `intro` gibi yerel değişkenler gösterilmez. Gösterilecek olan, problem alanındaki varlıkların metot çağrılarıdır: Person'ın kendi `getName()` çağrısı ve koşula bağlı olarak `car` üye alanının `getPlate()` çağrısı.
5. Kendi metodunu çağırma: çağrı oku `:Person`'ın activation bar'ının içinde başlayıp aynı activation bar'ın içinde bitecek biçimde çizilirse araç bunu kendi kendine çağrı şekline dönüştürür. Oka `getName()` yazılır. `getName()` yalnız `return name;` yaptığı için ayrıca açılmasına gerek yoktur.
6. Koşullu çağrı: 17. satırdaki koşula bağlı olarak 19. satırdaki `car.getPlate()` çağrısı yapılır. Bu çağrı, `getName()`'in iç activation bar'ı bittikten sonra ama Person'ın dış activation bar'ının dışına çıkmadan bir yerden başlatılır.
7. Çağrılacak nesne, Person nesnesinin küçük harfle yazılmış `car` üye alanıdır. Yeni bir nesne konur ve adı `car : Car` yazılır: küçük harfli `car` üye alanın adı, büyük harfli `Car` türüdür. Ok bu nesnenin lifeline çizgisi üzerine bırakılınca araç activation bar'ı kendisi ekler. (Hoca, aracın bunu yapmadığı durumda önce activation bar konup sonra okun ona çizilebileceğini, sonucun aynı olduğunu söyledi.) Ok çizilince Person tarafındaki activation bar da kendiliğinden uzar.
8. `getPlate()` Car sınıfında tanımlı olduğu için ok Car nesnesine girer ve üzerine `getPlate()` yazılır. Çağrı bir if koşuluna bağlı olduğundan başına if içindeki ifade köşeli parantezle eklenir: `[car!=null] getPlate()` (ekrandan, 01:45:00).
9. `getPlate()` plakayı döndürür, içinde başka çağrı yoktur; işini yapıp geri döner. Car'dan Person'a kesikli bir geri dönüş oku çizilir.
10. Koddaki 20. satırda başka bir metot çağrısı yoktur; 21. satırda `return` gerçekleşir. Person'ın activation bar'ının bu noktayı simgeleyen yerinden "Return message" aracıyla, `introduceSelf()`'i çağıran nesneye kesikli bir geri dönüş oku çizilir.

Ortaya çıkan şema metin olarak şöyledir (ekrandan, 01:45:00):

```text
 (çağıran)                 :Person                    car : Car
    |                         |                           |
   [ ] -- introduceSelf() --> [ ]                         |
   [ ]                        [ ]--+ getName()            |
   [ ]                        [[ ]<+                      |
   [ ]                        [ ] -- [car!=null] getPlate() --> [ ]
   [ ]                        [ ] <- - - - - - - - - - - - - - [ ]
   [ ] <- - - - - - - - - - - [ ]                         |
    |                         |                           |
```

### 12.4 Şemadan ne okunur?

Bu tip şemalarda aşağı doğru inildikçe zamanda da ileri gidilir. Hangi metodun hangisinden sonra çağrıldığı açıkça görülür. `getName()` ve `getPlate()` çağrılarının `introduceSelf()` içinde olduğu anlaşılır, çünkü ikisi de `introduceSelf()`'in activation bar'ının başlangıç ve bitiş çizgileri arasında yer alır. Önce `getName()` başlar ve biter, ardından `getPlate()` başlar ve biter.

## 13. Sıralama Şemalarında Sık Yapılan Hatalar

### 13.1 Dikey boşluk bırakmamak

Şemayı elle ya da UML'ye özel olmayan bir çizim aracıyla çizenler bazen `getName()` okunu `introduceSelf()` ile neredeyse aynı hizadan başlatır. Hoca bunu yapmamayı, arada küçük bir dikey boşluk bırakmayı istedi. `introduceSelf()` içinde yapılan ilk iş `getName()` çağrısı olsa bile, bir metot içinden yeni bir metot çağrıldığında çağıran metodun durum bilgisi bellekteki yığına (stack) atılır ve yeni çağrı için yeni bellek alanı açılır. O da başka bir metot çağırırsa onun durumu da yığına atılır; her metot bittikçe bir önceki metodun kaldığı yerin durumu yığından geri alınır. Bunlar belirli bir gecikmeyle yapılır. Bunu bir kenara bıraksak bile araya konan boşluk şemanın anlaşılırlığını önemli ölçüde artırır.

Daha kötüsü, bazıları iç çağrıyı dış çağrıdan daha yukarıdaki bir noktadan başlatır. Şemada yukarı çıkmak zamanda geri gitmek demektir; zamanda geri gidilemeyeceğine göre bu yanlıştır ve aradaki boşluk korunmalıdır.

### 13.2 Oku yanlış nesneye çizmek

`getPlate()` Car sınıfındadır, Person'da değildir. Bu yüzden ok bir Car nesnesine doğru gider. Person'a doğru giden bir `getPlate()` oku çizmek, konunun anlaşılmadığının göstergesidir, çünkü Person'da `getPlate()` diye bir metot yoktur.

### 13.3 Problem alanı dışındaki çağrıları çizmek

Sıralama şemalarında `print` gibi çağrılar yerine problem alanına yönelik metot çağrıları çizilir.

## Örnek Sorular

**Soru 1** (ekrandan, 01:25:00): Person sınıfının `introduceSelf()` metodunun UML sıralama şemasını çiziniz. Kod 12.2'deki gibidir: metot önce kendi `getName()` metodunu çağırır, `car` üye alanı `null` değilse `car.getPlate()` çağrısıyla plakayı metne ekler ve metni döndürür.

> **Çözüm (derste verildi):** Çağıran adsız bir nesneden `:Person` nesnesine `introduceSelf()` mesajı gider. `:Person` içinde iç içe bir activation bar ile `getName()` kendi kendine çağrısı çizilir (geri dönüş oku yok). `getName()` bittikten sonra, biraz aşağıdan, `car : Car` nesnesine `[car!=null] getPlate()` mesajı çizilir; Car'dan Person'a kesikli geri dönüş oku gelir. Son olarak Person'dan çağırana kesikli geri dönüş oku çizilir. Şema 12.3'tedir.

**Soru 2** (derste sözlü, 01:16:43): Person ile Car arasındaki sahiplik ilişkisinde Car tarafına neden 0..1 niceliği yazılmıştır?

> **Çözüm (derste verildi):** Person'ın kurucusu yalnız ismi alır, arabayı almaz. Bir kişi arabasız oluşturulabilir ve araba sonradan `setCar` ile atanır. Bir kişinin en fazla bir arabası olduğu için nicelik 0..1'dir.

**Soru 3** (derste sözlü, 00:42:42): MVC'de Model'in geçirdiği değişiklikleri View'a bildirmesi yararlı olabilir mi?

> **Çözüm (derste verildi):** İlişki eklenmezse View Model'i belirli aralıklarla sorgulamak zorunda kalır; Model ve View farklı bilgisayarlardaysa bu zaman ve haberleşme maliyeti getirir. Bu maliyet kritikse Model'den View'a da ok çizilir ve Model değişince View'a haber verir (Observer kalıbı). Maliyet önemli değilse gereksiz çift yönlü ilişki ve bağlaşım eklenmez.

**Soru 4** (derste sözlü, 01:37:29): Sıralama şeması yalnız `introduceSelf()` için mi çizildi, başka metotlar için de çizmek gerekir mi?

> **Çözüm (derste verildi):** Evet, bu şema yalnız `introduceSelf()` içindir. İç mantığı ya da sistem tasarımı açısından çok önemli, kritik bir metot varsa onun sıralama şemasını çizmek her zaman yararlıdır; onun dışında gerek yoktur.

## Dersin Toparlaması

Bu derste tasarım kalıplarına giriş yapıldı. Tasarım kalıbı, sık karşılaşılan tasarım sorunlarına deneyimli kişilerin önerdiği yalın ve iyi çözümlerin tarifidir; isim, sorun, çözüm ve tartışma/sonuçlar bileşenleriyle anlatılır. Kalıplar tekerleği yeniden icat etmeden kaliteli çözüme ulaşmayı, deneyimin yazılı aktarılmasını ve ekip içinde ortak bir sözlük kurulmasını sağlar; ancak her durumda kullanılmaları gerekmez, gelecekteki değişiklik beklentisine göre karar verilir. GoF kalıpları yaratımsal, yapısal ve davranışsal olarak üç kümeye ayrılır. Örnek olarak MVC kalıbı ayrıntılı incelendi: veri, gösterim ve gösterimin yönetimi ayrı sınıflara bölünür; bu sayede gösterim çalışma anında değiştirilebilir, ilgi alanları ayrılır ve yeniden kullanım artar. Model'den View'a bildirim, çoklu view ve çoklu kontrolcü çeşitlemeleri ve bunların getirdiği Observer kalıbı, eşzamanlama gibi konular tartışıldı.

Dersin ikinci yarısında tasarımın belgelendirilmesine geçildi. UML sınıf şeması vazgeçilmezdir; sözleşmeler ve etkileşim, etkinlik, durum şemaları ihtiyaca göre eklenir. Sözleşmelerde ön koşulların tüm sistem hakkında, son koşulların problem alanı nesnelerindeki değişiklikler hakkında olduğu ve edilgen geçmiş zamanla yazıldığı görüldü. Son olarak sıralama şemalarının gösterimi hatırlatıldı ve Person.introduceSelf() metodunun şeması Violet UML Editor ile adım adım çizildi. Sonraki derslerde UML etkinlik şemaları ve durum şemaları ele alınacak; NextGen POS örneğinin sınıf şeması tasarıma taşınırken yeni şema türleri ve bir sıralama şeması birlikte çizilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
