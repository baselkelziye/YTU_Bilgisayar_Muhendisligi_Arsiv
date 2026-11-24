# Ders 3 Çalışma Özeti

## Genel Konular

- Bilişim suçlarının ortaya çıkışı ve neden bilinmesi gerektiği
  - Bilgisayar çağı 1950'lerde başladı. Hayatın her alanında olduğu gibi bilişim alanında da suç işlenmesi beklenen bir sonuçtur.
  - Bazı suçlar internetten önce de vardı (özellikle bilgi sistemleriyle ilgili olanlar). Asıl artış, internetin bütün dünyanın kullanımına açılmasıyla oldu.
  - Daha önce yaşanmış olayları bilmek, hem bilişim etiği hem de bilişim hukuku açısından aynı hatalara düşmemeyi sağlar.
  - Siber suç (cybercrime): bilgisayarın ya da bir bilişim sisteminin suçun nesnesi olduğu ya da suç işlemek için araç olarak kullanıldığı suçtur.
- Saldırı ve dolandırıcılıkların sınıflandırılması (ekrandan, 00:10:00)
  - Teknik açıdan üç sınıflandırma:
    - Etken ve edilgen saldırı ve dolandırıcılıklar.
    - İçeriden ve dışarıdan yapılan saldırı ve dolandırıcılıklar.
    - Amaca yönelik saldırı ve dolandırıcılıklar.
  - AB uyumlu yasalarımıza göre dört küme:
    - Daha önceden bilinen ancak artık bilişim yoluyla da işlenen suçlar.
    - Özel hayata ve hayatın gizli alanına karşı işlenen suçlar.
    - Mal varlığına karşı işlenen suçlar.
    - Bilişim alanında işlenen suçlar.
- Etken ve edilgen saldırılar
  - Etken saldırı: amaç verileri değiştirmek, eklemek, silmek, sistemin çalışmasını durdurmak ya da sekteye uğratmak, donanım ve yazılım kaynaklarına zarar vermektir. Sonucunda karşı taraf zarar görür.
  - Edilgen saldırı: amaç yalnız bilgiyi okumak ve elde etmektir; veriye ya da sisteme müdahale yoktur. Yine de hakkı ve izni olmayan bilgiyi okumak bir saldırıdır.
- İçeriden ve dışarıdan saldırılar (ekrandan, 00:15:00)
  - İç saldırı: kurum çalışanlarının (insider) kendi kurumlarına karşı yaptığı dolandırıcılıktır. Hedefleri ödeme, tedarik, seyahat ve yolluk, çalışan yönetimi sistemleri; ödeme belgelerine ulaşarak ya da kuruluşun varlık ve bilgilerini kullanarak kişisel kazanç sağlamaktır.
  - Dış saldırı: bir kişi, takım, kuruluş, hatta bir ülke tarafından yapılır. Amaçları bilgileri okumak, verileri değiştirmek ya da silmek, çalışmayı aksatmak, kaynaklara zarar vermek, işlemleri engellemek ve finansal kazanç sağlamaktır. Dış saldırılar genellikle etken saldırıdır.
  - Amaca yönelik saldırı: hedef bireyler, varlıklar (asset), kurum ve kuruluşlar ya da bir toplumun tamamı olabilir.
- İçeriden yapılan saldırıların dört örneği: salam dilimi, dış uzman, sanal saatli bomba, bilgi hırsızlığı
  - Bu saldırılar parasal işlemlerin yoğun olduğu bankacılık, perakende ve hizmet sektörlerinde sık görülür.
- Salam dilimi (ekrandan, 00:20:00)
  - Tanım: bankada faiz hesaplamaları sonunda ortaya çıkan küçük rakamların özel bir hesaba aktarılması ve müşteri hesabında sıfırlanması.
  - Banka örneği: kuruş yuvarlama kuralı (yarım kuruşun altı aşağı, üstü yukarı) değiştirilip bütün küsuratlar aşağı yuvarlanıyor, fark programcının hesabına aktarılıyor; yakalanmamak için kod rastgele zamanlarda çalıştırılıyor.
  - Araç kiralama örneği: araçların yakıt depoları sistemde olduğundan büyük tanımlanıyor (örneğin 50 litrelik depo 70 litre), müşterilerden fazla yakıt parası alınıyor ve fark programcıya gidiyor.
  - Hukuk: programcı müşterilerin ve bankanın hesabından para çalmıştır, suçludur. Etik: programcı kuruluşun etik kurallarını çiğnemiş, kuruluş saygınlık kaybı yaşamıştır.
  - Korunma: yazılım güvenlik kontrol birimi, kod gözden geçirme (code review) ve canlıya almadan önce işlevsel ve işlevsel olmayan gereksinimler açısından test.
- Dış uzman (ekrandan, 00:35:00)
  - Tanım: büyük boy bilgisayarın bakımı için gelen dış uzmana verilen kullanıcı adı ve parola bilgilerinin daha sonra kötü amaçla kullanılması.
  - Bakım için genellikle en üst yetki (admin, root) verilir; iş bitince hesap kapatılmazsa uzman ayrıldıktan sonra da sisteme girebilir.
  - Hukuk: dış uzman suçludur; yetkiyi kaldırmayı savsaklayan kuruluş yetkilisi de hatalıdır. Etik: erişim hakkını amacı dışında kullanmak etik değerlere aykırıdır.
  - Çözüm: bakım bitince yetki hemen iptal edilir; her yeni bakım için yalnız o işle sınırlı yeni yetki tanımlanır.
- Sanal saatli bomba (ekrandan, 00:45:00)
  - Tanım: yazılımın içine, zamanı geldiğinde programları ve verileri bozacak bir programın eklenmesi.
  - İçeriden: işten atılma korkusu olan ya da mutsuz bir çalışan; dışarıdan: lisans ya da bakım anlaşması bitince yazılımı veya veriyi bozan satıcı firma.
  - Hukuk: bilinçli ve planlı zarar hedeflendiği için suçtur; kendisine sağlanan yetkileri kullanarak yerleştirildiği için bir kat daha suçtur, ceza ağırlaşır. Lisans süresi dolan kuruluş yazılımı olduğu gibi kullanmaya devam edebilir, yalnız güncelleme ve yamalardan yararlanamaz.
  - Ülkemizdeki bir bankada bomba programı saptanamadığı için işten çıkarılan programcı suçlu bulunamamıştır; banka bu olaydan ders çıkarmıştır.
- Bilgi hırsızlığı (ekrandan, 00:50:00)
  - Ticari sırlar, mali bilgiler, AR-GE sonuçları, müşteri portföyü kurum için gizlidir.
  - Örnekler: başka bankaya geçen şube müdürünün müşterilerini götürmesi; silah üreticisi yöneticisinin tüfeğin teknik bilgilerini satması; MERNİS kayıtlarının sızması.
  - Hukuk: müşteri bilgisi aktarımının kanıtlanması ve suçlu bulunma olasılığı düşüktür; silah bilgisinin satışı suçtur, ulusal tüfekse ulusal sır sattığı için ikinci bir cezaya çarptırılır; MERNİS sızıntısının bilinçli mi bilinçsiz mi olduğu belirlenememiştir.
  - Etik: müşteri bilgileri banka içinde gizlidir, aktarılması etik değildir; silah bilgisini satmak hem kuruluş etiğine hem ulusal değerlere terstir; bilinçsiz sızıntı özensiz davranıştır ve etik kuralların çiğnenmesidir.
- İçeriden ve dışarıdan yapılan saldırılarda eylemler
  - Bilgi çalma, değiştirme, silme (ekrandan, 00:55:00): bir bilgi sistemine erişme hakkı olmadan girip bilgileri çalmak, değiştirmek ya da silmek.
    - Hukuk: izinsiz girmek kilide anahtar uydurarak bir konuta girmeye benzer; amaç ne olursa olsun suçtur, "açığı göstermek için yaptım" demek suçu hafifletmez. Girdikten sonra veri çalmak, değiştirmek, silmek ayrıca suçtur (iki ayrı suç).
    - En kötüsü değiştirmedir: değişiklik kayıtları çoğu zaman tutulmaz, fark edilmesi ve geri alınması zordur.
  - Bilgi sisteminin çalışmasının engellenmesi (ekrandan, 01:00:00): sistemi meşgul ederek hizmetlerde aksamaya neden olmak.
    - Her sistemin istek karşılama limiti vardır; robot ya da zombi bilgisayarlar tek merkezden yönetilip tek sunucuya sürekli istek yollar.
    - Hukuk: suçtur, ancak yöneticiyi saptamak zor, ülke dışındaysa yakalamak daha zordur; başka bir ülke destekliyorsa yapılabilecek fazla şey yoktur. Etik: rakip firma ya da düşman ülke fark etmez, etik değildir.
- Genelağ (internet) bankacılığı soygunları (ekrandan, 01:05:00)
  - Tuş izleme: iletişim şifreli olduğu için hat dinlenerek parola alınamaz; müşterinin bilgisayarına yerleştirilen casus program (keylogger) ile alınır.
  - Ekran kopyalama: bankalar sanal tuş takımına geçince, ekranın fotoğrafını ve fare tıklamalarını gönderen programlar kullanılmaya başlandı.
  - Tek kullanımlık parola (TKP): müşteriye verilen bir program ya da donanım (akıllı anahtar) belli bir algoritmaya göre parola üretir; SMS ile iki aşamalı doğrulama da bu ailedendir. SIM kart kopyalamaya karşı SIM değişikliğinde bloke gibi önlemler gelmiştir.
  - Davalar: bilgisayarına casus yazılım bulaşan bir müşterinin davasında müşteri %15, banka %85 sorumlu bulunmuştur; isme havale yoluyla çalınan paralarda banka %100 sorumlu bulunmuştur.
  - Diğer yöntemler: sahte kimlikle isme havale, kandırılan kişilerin hesaplarının şebekeye kullandırılması, çalıntı paranın kuyumcudan altın alınarak çekilmesi.
  - Önlemler: tanımsız hesaplara aktarım için ek doğrulama, telefon numarası gibi doğrulama bilgilerinin internetten değiştirilememesi.
- Kredi kartı soygunları (ekrandan, 01:30:00)
  - Tarihçe: 1949'da McNamara'nın restoranda cüzdanını unutmasıyla doğan Diners Club kartı kredi kartının atası sayılır; 1980'lerde karbon kopyalı slip dönemi.
  - Yöntemler: fazla kopya çıkarma, gerçek kredi kartı bilgisini kullanma (manyetik şeridin kopyalanması), kart üzerindeki bilgileri değiştirme.
  - Kart numarasının yapısı: 16 haneli kartta ilk 6 hane kartı üretip dağıtan kuruluş, sonraki 9 hane kartın tekil numarası, son hane kontrol basamağıdır (Luhn algoritması).
- Bilinen ancak bilişim yoluyla işlenen suçlar
  - İntihara yönlendirme, uyuşturucu ve uyarıcı madde kullanımı, sağlık için tehlikeli maddelerin sağlanması, kumar için yer ve olanak sağlama (TCK 228. madde), müstehcenlik, fuhuş, çocukların cinsel istismarı.
- Özel hayata ve mal varlığına karşı suçlar
  - Haberleşme özgürlüğü vardır; haberleşmenin dinlenmesi, kaydedilmesi ve yayımlanması yasaktır, dinleme ancak hâkim kararıyla yapılabilir. Kişisel veriler Kişisel Verilerin Korunması Kanunu ile korunur.
  - Bilişim sistemi kullanılarak para ya da mal çalmaya nitelikli hırsızlık denir.
- Saldırı biçimleri (ekrandan, 01:50:00)
  - Virüs saldırıları, kurtulmalık (fidye) yazılımlar, bilgisayar denetimli sistemlere saldırılar.
- Türkiye'de bilişim mevzuatı
  - 2007'de bütüncül bir bilişim yasası taslağı hazırlandı ama yasalaşmadı. Yerine parça parça düzenlemeler çıktı: Fikir ve Sanat Eserleri Kanunu güncellemeleri, Elektronik İmza Kanunu, Kişisel Verilerin Korunması Kanunu, internet yayınlarını düzenleyen kanun, e-ticaret kanunu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Her olay hem hukuk hem etik açısından ayrı ayrı değerlendirilir
  - Bir eylem hukuken suç olmayıp etik açıdan yanlış olabilir (müşteri portföyünü başka bankaya götürmek gibi). Hoca her örnekte iki değerlendirmeyi ayrı yaptı.
- "Açığı göstermek için girdim" savunması geçersizdir
  - Beyaz şapkalı olduğunu söylemek izinsiz girişi hafifletmez; kilidi izinsiz açtığınız gerçeği değişmez.
- Verinin değiştirilmesi silinmesinden ve çalınmasından daha tehlikelidir
  - Silinen veri yedekten dönebilir, ama değişiklik kayıtları çoğu zaman tutulmadığı için değişikliği fark etmek ve geri almak zordur.
- Güvenlik bir "hırsız polis" ya da kedi fare oyunudur
  - Banka bir açığı kapatır, saldırgan yeni bir yol bulur (parola, sanal klavye, ekran kopyalama, TKP, SIM kopyalama...). Bu yüzden önlemler sürekli güncellenmelidir.
- Dış uzmana verilen yetki iş bitince hemen kaldırılmalıdır
  - Kaldırmayı savsaklayan kuruluş yetkilisi de hukuken sorumludur.
- Yazılım güvenlik kontrol birimi ve kod gözden geçirme
  - Salam dilimi ve saatli bomba gibi içeriden saldırılar ancak kodların gözden geçirilip test edilmesiyle önlenebilir.

## Kısa Tekrar Notları

- Siber suç: bilgisayarın suçun nesnesi ya da aracı olduğu suç.
- Teknik sınıflandırma: etken/edilgen, içeriden/dışarıdan, amaca yönelik.
- Yasal sınıflandırma (AB uyumlu): bilinen ama bilişimle işlenen, özel hayata karşı, mal varlığına karşı, bilişim alanında işlenen suçlar.
- Etken saldırı veriyi ya da sistemi bozar; edilgen saldırı yalnız okur, ama izinsiz okumak da saldırıdır.
- İçeriden saldırı örnekleri: salam dilimi, dış uzman, sanal saatli bomba, bilgi hırsızlığı.
- Salam dilimi: fark edilmeyecek küçük tutarların özel hesaba aktarılması.
- Dış uzman: bakım için verilip kaldırılmayan üst düzey yetkinin kötüye kullanılması.
- Sanal saatli bomba: zamanı gelince programı ve veriyi bozan gömülü kod; yetki kullanılarak yerleştirildiği için ceza ağırlaşır.
- Lisansı biten yazılım olduğu gibi kullanılabilir; yalnız güncelleme, yama ve destek kesilir.
- Bilgi çalma, değiştirme, silme: izinsiz giriş ayrı suç, veriye müdahale ayrı suç.
- Çalışmayı engelleme: zombi bilgisayarlarla sistemi meşgul etmek; failin yakalanması zordur.
- İnternet bankacılığı: tuş izleme, ekran kopyalama, TKP, SIM kopyalama, isme havale, hesap kullandırma.
- Kredi kartı: fazla kopya, gerçek kart bilgisini kullanma, kart bilgisini değiştirme; 6 + 9 + 1 haneli yapı ve Luhn kontrol basamağı.
- Saldırı biçimleri: virüs, kurtulmalık (fidye) yazılım, bilgisayar denetimli sistemlere saldırı.
- Kumar için yer sağlama TCK 228. maddede düzenlenmiştir.

## Detaylı Açıklamalar

- **Salam dilimi neden fark edilmez?** Salamı ince dilimlere bölüp her gün bir dilim almak gibi, her işlemden alınan tutar çok küçüktür. Banka örneğinde müşteriler zaten yuvarlama yapıldığını bilir ve yarım kuruşu önemsemez; işlemlerin yarısında kaybedip yarısında kazandıklarını düşünürler. Programcı yuvarlama kuralını "bir kuruşun altındaki her şeyi sıfıra yuvarla" diye değiştirip yukarı yuvarlanması gereken tutarları kendi hesabına aktarır. Sürekli yaparsa on binlerce hesaptan gelen toplam göze batacağı için kodu rastgele zamanlarda çalıştırır. Araç kiralama örneğinde ise müşteriler depoyu çoğu zaman doldurmadan teslim edip farkı öder; depo hacmi büyük tanımlandığı için her müşteriden fazladan 5-20 litre yakıt parası alınmış, toplam soygun 1-2 milyon düzeyinde fark edilmiştir.
- **Dış uzman riski:** Büyük kurumların mainframe ya da veri merkezlerinin işletim sistemi, sürücü, ağ, veritabanı ve web sunucusu bakımları çoğunlukla dış firmalara yaptırılır. Uzman işletim sistemi düzeyinde iş yapacağı için en üst yetki verilir. Bu hesap kapatılmazsa uzman sonradan para aktarabilir, vergi borcu silebilir ya da askerlik kaydı oluşturabilir. Hoca finans kuruluşlarının bilgi güvenliğine yönelik bir düzenlemenin bu konuyu ele aldığını söyledi. <!-- BELİRSİZ: altyazıda "Covid yönetmeliği" geçiyor; büyük olasılıkla COBIT çerçevesi ya da bankaların bilgi sistemlerine ilişkin BDDK yönetmeliği kastediliyor. -->
- **Ders kaydı betiği tartışması:** Ders kaydında sürekli istek yollayan bir betik yazan öğrencinin eylemi, amacı sistemi çökertmek olmadığı için hukuken suç sayılmaz. Etik açıdan, betiği yalnız kendisi kullanırsa göz yumulabilir; ama arkadaşlarıyla paylaşıp kitlesel hale getirince diğer öğrencilerin hakkını aldığı için etik değildir. Önlem olarak CAPTCHA ve gerekirse danışman onayı gibi insan faktörü eklenebilir.
- **Kredi kartı kart bilgisi değiştirme örneği:** Limiti dolan bir kişi, limitini artıracağını söyleyen bir dolandırıcıya kartını verir; dolandırıcı yurt dışındaki başka bir kişinin kart bilgilerini bu kartın manyetik şeridine kopyalar. Kişi araç kiralar, yakıt alır, telefon alır. Gerçek kart sahibi kısa süre içinde kendi ülkesinde alışveriş yapınca banka aynı kartla birkaç dakika arayla iki ülkede işlem yapılamayacağını fark eder ve kartı çalıntı olarak işaretler. Kartı yaptıran ve dolandırıcı suçludur; kimlik ve kart bilgilerini karşılaştırmayan araç kiralama firması, benzinlikler, lokanta ve ilk telefon satıcısı da hatalıdır.
- **Luhn kontrol basamağı (ekrandan, 01:30:00):** Slayttaki örnek kart numarası `4411 0512 3456 7897`. Soldan başlayarak tek sıradaki (1., 3., 5., ...) haneler 2 ile çarpılır, sonuç 9'dan büyükse 9 çıkarılır: 4→8, 1→2, 0→0, 1→2, 3→6, 5→10−9=1, 7→14−9=5, 9→18−9=9. Son satır `8 4 2 1 0 5 2 2 6 4 1 6 5 8 9 7` olur; toplam 70'tir ve 10'a tam bölündüğü için numara geçerlidir (toplam ve bölünebilirlik ajan tarafından python ile kontrol edildi; derste toplam adımı sözlü anlatılmadı).
- **Kurtulmalık (fidye) yazılım:** Olağan dışı tutarda bir telefon faturası gibi görünen kandırma e-postasındaki düğmeye basılınca kötücül program yüklenir, bilgisayardaki veri ve belgeleri şifreli olarak sıkıştırır; ardından "şu kadar ödeme yaparsanız çözücü parolayı göndeririz" denir. Verisine ulaşmak için ödeme yapmak zorunda kalan çok kuruluş vardır.
- **Ders sonrası notlar:**
  - Hoca yıllık %15 faizle 1000 liranın günlük faizini yaklaşık 35 kuruş olarak söyledi; $150/365 \approx 0{,}41$ lira, yani yaklaşık 41 kuruştur (ajan hesabı).
  - Hoca dış uzmana erişim için "authorization" ve "authentication" sağlanması gerektiğini söylerken yetki vermeyi authentication'a bağladı; yetki verme authorization (yetkilendirme), kimliğin doğrulanması authentication'dır.
  - Hoca TR uzantılı sitelere yapılan engelleme saldırısını 2016 olarak andı; bu saldırı büyük olasılıkla Aralık 2015'te yaşanmıştır.
  - Altyazıda internet yayınlarına ilişkin kanunun sayısı "5.150" olarak geçiyor; bu kanun büyük olasılıkla 5651 sayılı kanundur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
