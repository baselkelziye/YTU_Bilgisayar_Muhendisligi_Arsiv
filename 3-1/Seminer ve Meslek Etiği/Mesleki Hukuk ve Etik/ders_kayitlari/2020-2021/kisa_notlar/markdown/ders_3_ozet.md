# Ders 3 Çalışma Özeti

## Genel Konular

- Bilişim suçlarının sınıflandırılması
  - Teknik açıdan bilişim suçları ikiye ayrılır: kuruluşun içinden yapılan eylemler ve kuruluşun dışından yapılan eylemler.
  - Hukuki açıdan dört küme vardır (Türk yasaları ve uyum sağlanan Avrupa Birliği yasalarına göre):
    - Önceden bilinen, artık bilişim kanallarıyla da işlenebilen suçlar (intihara yönlendirme, çocukların cinsel istismarı, kumar gibi).
    - Özel hayata ve hayatın gizli alanına karşı suçlar (haberleşmenin gizliliğini ihlal, kişisel verileri izinsiz kaydetme gibi).
    - Mal varlığına karşı suçlar: nitelikli hırsızlık ve nitelikli dolandırıcılık (genelde internet bankacılığı ve kredi kartı temelli).
    - Bilişim alanında işlenen suçlar: bilişim sistemine izinsiz girme, sistemin çalışmasını engelleme, verileri bozma, silme veya değiştirme, banka kartlarının kötüye kullanılması.
  - Saldırılar etken/edilgen olmalarına ve amaçlarına (bireye, varlığa/paraya, kuruluşa, topluma yönelik) göre de sınıflandırılabilir.
- Etken ve edilgen saldırı
  - Bilgisayar ya da bilişim sistemi suçun nesnesi veya aracıysa buna siber suç denir.
  - Etken saldırı: verileri değiştirmek, silmek, sistemin çalışmasını durdurmak ya da sisteme zarar vermek.
  - Edilgen saldırı: yetkisi olmadığı hâlde bilgiyi yalnızca okumak ve başkasına aktarmak (örneğin yetkisiz bir çalışanın müşteri bakiyelerine bakması).
- İç saldırılar ve dolandırıcılıklar (ekrandan, 00:10:00)
  - Çalışanların kuruluşa karşı yaptığı dolandırıcılıklardır; ödeme, tedarik, seyahat ve yolluk, çalışan yönetimi sistemleri ya da ödeme belgeleri ve kuruluş varlıkları üzerinden kişisel kazanç amaçlanır.
  - Dört türü vardır: salam dilimi, dış uzman, sanal saatli bomba (logic bomb), bilgi hırsızlığı.
- Dış saldırılar ve dolandırıcılıklar (ekrandan, 00:10:00)
  - Bir kişi, takım ya da kuruluş tarafından yapılır; amaçları bilgileri okumak, verileri değiştirmek ya da silmek, çalışmayı aksatmak, sistem kaynaklarına zarar vermek, işlemleri engellemek ve finansal kazanç sağlamaktır.
  - Başlıkları: bilgi çalma, değiştirme veya silme; bilgi sisteminin çalışmasının engellenmesi; genelağ (internet) bankacılığı soygunları; kredi kartı soygunları.
- Bilinen ama bilişim yoluyla işlenen suçlar, özel hayata ve mal varlığına karşı suçlar, virüs ve fidye yazılımı saldırıları, Türkiye'de bilişim yasası olmaması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Her örnek iki açıdan değerlendirilir: hukuk açısından (suç mu, ispatlanabilir mi) ve etik açısından (kuruluşun ve mesleğin etik kurallarına uygun mu).
- Veri değiştirmek, veri silmekten ve çalmaktan daha tehlikelidir.
  - Çalma loglardan, silme yedeklerden bir ölçüde telafi edilebilir; ama neyin, ne kadar değiştirildiğini bulmak için bütün işlemlerin geriye dönük incelenmesi gerekir.
- İzinsiz giriş, amacı ne olursa olsun suçtur.
  - "Kendimi kanıtlamak için" ya da "açığınızı göstermek için" girdim demek suçu hafifletmez; kilidin kolay açıldığını göstermek için kilidi kırıp eve girmeye benzer (ekrandan, 00:50:00).
  - Şirketin özel izni olmadan sistemde açık aramak da erişim hakkı olmadan girmek sayılır; şirket açık bulma çağrısı yaparsa suç olmaz.
- Hukukta kesin ispat gerekir: saatli bomba ve bilgi hırsızlığı örneklerinde kod ya da fiziki kanıt bulunamadığı için suçlama yapılamamıştır.
- Bir hareket yasal olsa bile etik olmayabilir (ders seçme botu örneği).
- Salam dilimi gibi değişikliklere karşı önlem: hiçbir kod, güvenlik birimince incelenmeden (code review) ve test edilmeden canlıya alınmamalıdır; yalnız kod değil, veri tabanındaki parametreler de denetlenmelidir.
- Lisans süresi dolan yazılım "olduğu hâliyle" kullanılmaya devam edebilmelidir; güncelleme, yama ve bakım desteği kesilir ama kuruluşun kendi verisine erişimi engellenemez (sözleşmede aksi yazmıyorsa).

## Kısa Tekrar Notları

- Bilişim suçları: teknik olarak içeriden/dışarıdan; hukuki olarak dört küme.
- İç saldırılar: salam dilimi, dış uzman, sanal saatli bomba, bilgi hırsızlığı.
- Salam dilimi: faiz yuvarlamasından kalan küçük tutarları kendi hesabına aktarma; araç kiralamada depoları büyük tanımlama.
- Dış uzman: bakım için verilen yüksek yetkili hesabın kapatılmaması ve kötüye kullanılması; hem uzman hem hesabı kapatmayan yetkili hatalıdır.
- Sanal saatli bomba: zamanı gelince program ve verileri bozan kod; yetki kötüye kullanıldığı için ceza ağırlaşır.
- Bilgi hırsızlığı: ticari sır, müşteri bilgisi, MERNİS kayıtları gibi verilerin dışarı aktarılması; kanıtlamak zordur.
- Dış saldırılar: bilgi çalma/değiştirme/silme, çalışmayı engelleme (DDoS), internet bankacılığı ve kredi kartı soygunları.
- İnternet bankacılığı: tuş izleme → sanal klavye → ekran kopyalama → tek kullanımlık parola (TKP) → SMS ve ikinci SIM kart açığı → push bildirimi. Saldırgan ile banka arasında "kedi-fare" yarışı vardır.
- Kredi kartı soygunları: fazla kopya çıkarma, gerçek kart bilgisini kullanma, kart üzerindeki (manyetik şerit) bilgiyi değiştirme.
- Kart numarası geçerliliği: Luhn tipi kontrol; toplam 10'a bölünüyorsa numara geçerlidir (ekrandan, 01:40:00).
- Mal varlığına karşı suçların adı: nitelikli hırsızlık ve dolandırıcılık.
- Türkiye'de ayrı bir bilişim yasası yoktur; ilgili alanlar fikir ve sanat eserleri, elektronik imza, kişisel verilerin korunması, e-ticaret ve internet yayınları yasalarıyla düzenlenir.

## Detaylı Açıklamalar

- **Salam dilimi (salami fraud).** Büyük bir salamdan fark edilmeden ince bir dilim almaya benzetilir; çoğunlukla bilgi işlemde çalışan programcılar yapar (ekrandan, 00:15:00).
  - Banka örneği (Amerika): faiz hesabında 5 sentin altı aşağı, üstü yukarı yuvarlanacağı sözleşmede yazılıdır. Programcı her şeyi aşağı yuvarlamış, aradaki farkı kendi hesabına aktarmıştır. Yakalanmamak için bunu her gün değil, rastgele günlerde yapmış; olay, hesaplarını kontrol eden dikkatli müşterilerin şikâyetiyle ortaya çıkmıştır.
  - Hocanın kaba hesabı: 1 milyon müşteriden kişi başı yarım kuruş alınırsa günde 5.000 TL eder. <!-- BELİRSİZ: Hoca hesapta "1 milyon çarpı 0,05 = 50 bin lira" da dedi; 0,05 TL beş kuruştur. Yarım kuruş (0,005 TL) için 1.000.000 × 0,005 = 5.000 TL olur. -->
  - Araç kiralama örneği (Amerika): şirket aracı dolu depoyla verir, eksik yakıtın parasını müşteriden alır. Programcı depoları sistemde 5-20 litre büyük tanımlamıştır. 50 litrelik depo 60 litre tanımlıysa, yarım depoyla dönen müşteri 25 yerine 35 litrenin parasını öder; 10 litrelik fark programcıya gider. Müşteri şikâyetleriyle ortaya çıkmış, toplam 47 bin işlem tespit edilmiştir.
  - Hukuk: programcı hem müşterinin hem bankanın hesabından para çalmıştır, suçludur. Etik: kuruluşun etik kurallarını çiğnemiş, müşteriyle yapılan sözleşmeye aykırı davranmış ve kuruluşun saygınlık kaybına yol açmıştır.
  - Derste benzer bir iç dolandırıcılık örneği de konuşuldu: bir restoranda adisyondan ana yemeklerin silinip yalnız içeceklerin kasaya girilmesi; stok sayımında et miktarı ile satış sayısı tutmayınca ortaya çıkmıştır.
- **Dış uzman.** Banka, borsa, maliye, kredi kayıt bürosu gibi büyük (mainframe) bilgisayar kullanan yerlerde bakım ve güncelleme için üretici firmanın uzmanına yüksek yetkili (admin/root) bir hesap açılır. Güvenlik birimi bu hesabı işten sonra kapatmayı unutur ya da "haftaya yine gelecek" diye açık bırakır. Uzman kötü niyetliyse uzaktan erişip verileri değiştirebilir, silebilir ya da para transferi yapabilir.
  - Hukuk: uzman, yetkisini amacı dışında kullandığı için suçludur; hesabı kapatmayan kurum yetkilisi de kapıyı açık bıraktığı için hatalıdır.
  - Etik: güvenle verilmiş erişimi amacı dışında kullanmak etik değerlere aykırıdır.
  - <!-- BELİRSİZ: Hoca finans sektöründe güvenlik seviyelerini tanımlayan bir yönetmelikten söz etti; altyazıda "COVID yönetmeliği" yazıyor. Büyük olasılıkla BDDK düzenlemesi ya da COBIT kastedildi. -->
- **Sanal saatli bomba (logic bomb).** Yazılımın içine, zamanı gelince programları ve verileri bozacak bir kodun eklenmesidir (ekrandan, 00:30:00).
  - Örnek: mutsuz bir programcı kodun içine bir tarih kontrolü koyar ve tarihi sürekli öteler; işten ayrılınca öteleme durur ve kod veri tabanını siler ya da verileri değiştirir.
  - Örnek: lisans bedeli ödenmeyince ertesi gün çalışmayı durduran ticari yazılım; bakım anlaşmasının bittiği günün ertesinde verilere erişimin engellenmesi.
  - Türkiye'deki bir banka olayında, veriler bozulmuş ama bomba programı bulunamamıştır. Ya hiç yoktu ya da kendini silecek şekilde yazılmıştı; ispatlanamadığı için işten çıkarılan programcı suçlu bulunamamış, banka önlemlerini artırmıştır.
  - Hukuk: bilinçli ve planlı biçimde zarar vermeyi hedeflediği için suçludur; kendisine sağlanan yetkileri kullanarak yerleştirdiği için bir kat daha suçludur, cezası ağırlaşır. Bomba programını yazılıma gömülü satmak da suçtur.
  - Etik: çalışan kuruluşuna zarar veremez; yazılım satan kuruluş, nedeni ne olursa olsun sattığı yazılıma bomba program yerleştiremez.
- **Bilgi hırsızlığı.** Ticari sırlar (ör. bir elektrikli araç üreticisinin pil yerleşim düzeni), mali bilgiler, Ar-Ge bilgileri, müşteri bilgileri ve kamu veri tabanları hedef olabilir (ekrandan, 00:45:00).
  - Banka çalışanının menfaat karşılığı müşteri bilgilerini başka bankaya aktarması yanlıştır ama kanıtlanması ve suçlu bulunması olasılığı düşüktür (bilgi sözlü aktarılmış olabilir).
  - Silah üretimiyle ilgili teknik bilgilerin satılması suçtur; tüfek ulusal bir tüfekse ulusal sırları satmaktan ikinci bir cezaya çarptırılır.
  - MERNİS kayıtlarının dışarı sızması kabul edilemez; sızıntının nasıl olduğu ve bilinçli mi bilinçsiz mi yapıldığı kesin belirlenememiştir. Bilinçsizce olduysa özensiz davrananlar etik kuralları çiğnemiştir.
  - Öğrenci sorusu: patent haklarının etrafından dolaşmak bilgi hırsızlığı değildir, ama ayrı bir suç olabilir.
- **Bilgi çalma, değiştirme veya silme (dış saldırı).** Erişim hakkı olmayan bir sisteme girip mali, sağlık ya da ulusal güvenlik bilgilerini almak, değiştirmek ya da silmektir. İnternetle birlikte kolaylaşmıştır, çünkü internetin altyapısı güvenlik amacıyla tasarlanmamıştır. Hukukta izinsiz giriş, eve anahtar uydurarak ya da pencereden girmeye benzetilir; giriş ve sonrasındaki çalma, değiştirme, silme ceza yasalarında suç olarak tanımlanmıştır. Ceza davasının ardından zarar görenin açtığı hukuk davası da gelebilir.
- **Bilgi sisteminin çalışmasının engellenmesi.** Sistemi meşgul ederek hizmetlerini aksatmaktır; en bilinen biçimi DDoS'tur (ekrandan, 01:00:00).
  - Güvenlik açıkları kullanılarak çok sayıda bilgisayar zombiye (robot bilgisayara) çevrilir; bunlar bir sunucuya sürekli istek gönderip darboğaz yaratır.
  - Yöneticiyi saptamak zordur; saptansa bile ülke dışındaysa yakalamak zordur; bir başka devlet destekliyorsa yapılabilecek pek bir şey yoktur. Bu tür eylemler çoğunlukla belli gruplar ya da istihbarat kuruluşlarınca yapılır.
  - Örnek: Rusya ile yaşanan siyasi krizde .tr uzantılı sitelere yapılan engelleme saldırısı. <!-- BELİRSİZ: Hoca olayı 2016 diye andı; bu saldırı büyük olasılıkla Aralık 2015'te yaşandı. -->
  - Her kesinti saldırı değildir: bulut veri merkezinde arıza ya da denizaltı kablosunun kopması da hizmeti kesebilir.
- **Ders seçme botu tartışması.** Bir öğrenci ders kayıt sistemine saniyede yüzlerce istek gönderen bir bot yazıp derslerini herkesten önce seçer. Sınıfın ve hocanın görüşü: etik değildir (fırsat eşitliğini bozar), ama tek başına kullanıldığında bir yasa hükmü olmadığı için suç sayılamaz. Öğrenci botu 20-30 arkadaşına dağıtırsa, sistemin çalışmasını dağıtık yüklenmeyle etkilediği için hukuki açıdan da sorun doğabilir. Botu para karşılığı satmak ayrıca sorunludur.
- **İnternet (genelağ) bankacılığı soygunları** (ekrandan, 01:10:00).
  - Tuş izleme: bankanın sunucusuna girmek ve şifreli hattı dinlemek zor olduğu için saldırgan müşterinin bilgisayarına casus program yerleştirir (ör. sahte fatura e-postası).
  - Ekran kopyalama: bankalar yerleri karışan sanal klavyeye geçince, fare durduğu anda ekran görüntüsü alıp gönderen programlar ortaya çıkmıştır.
  - Tek kullanımlık parola (TKP): müşteriye verilen program ya da donanım (akıllı anahtar) belli bir algoritmayla ve müşteriye özel gizli başlangıç değeriyle (seed) parola üretir; bu değeri yalnız banka bilir. Kâğıda basılı tek kullanımlık şifre listeleri de kullanılmıştır.
  - SMS açığı: saldırganın müşterinin hattı için ikinci (eş) SIM kart çıkarması, onay SMS'ini ele geçirmesini sağlamıştır. Devlet operatörlere ikinci kart çıkarmayı zorlaştırmış; bazı bankalar yalnız TKP cihazına ya da mobil uygulama bildirimine geçmiştir.
  - Hoca bir davada tuş izleme yazılımıyla hesabı boşaltılan müşterinin %15, bankanın %85 kusurlu bulunduğunu, TKP ile ilgili olaylarda ise mahkemelerin bankayı tamamen kusurlu bulmaya başladığını anlattı.
  - Parayı nakde çevirme: geliri düşük birinin ATM kartını kiralayıp parayı onun hesabına aktarmak; kartını kullandıran kişi suç ortağı olur. Bir olayda dolandırıcılar sahte nişanlı çift olarak kuyumcudan altın almış, parayı bu kartla kuyumcunun hesabına havale etmiş, ardından kart sahibine kartı "kaybettim" diye iptal ettirmiştir.
  - Önlemler: tanımsız hesaplara havale engeli, telefon numarasının yalnız güçlü kimlik doğrulamasıyla değiştirilebilmesi, bekleme süreleri.
- **Kredi kartı soygunları** (ekrandan, 01:40:00).
  - Kısa tarihçe: hocaya göre ilk kredi kartı Diners Club'dır; bir iş adamının 1949'da lokantada cüzdanını unutmasıyla fikir doğmuş, kart 1950'lerde kullanılmaya başlanmıştır. İlk kartlar kabartmalıydı ve kopya kâğıtlı makbuzlarla işlem yapılırdı.
  - Fazla kopya çıkarma: satıcı kartı boş makbuzlara birden çok kez geçirip sonra başka işletme adlarıyla doldurur.
  - Gerçek kart bilgisini kullanma: düzenli alışveriş yapılan dükkânın kopyaladığı bilgiyle müşteri yurt dışındayken işlem yapılması; kopya kartla bilet alıp iade istenmesi.
  - Kart üzerindeki bilgiyi değiştirme: "limitini artırırım" diyen dolandırıcı, kartın manyetik şeridine yurt dışındaki birinin kart bilgilerini yazar. Kartı kullanan kişi, gerçek kart iptal edilip POS ekranında "Bu kredi kartı çalıntıdır" uyarısı çıkana kadar alışveriş yapar. Satıcılar slipteki isim ve son dört haneyi kartın üzerindeki kabartma bilgiyle karşılaştırsaydı fark edilirdi. Çipli kartlar ve PIN bu açığı büyük ölçüde kapatmıştır.
  - Kart numarası yapısı: çoğunlukla 16 hane; ilk 6 hane kartı üreten/dağıtan kuruluşu kodlar, sonraki 9 hane kartın tekil numarasıdır, son hane kontrol hanesidir.
  - Geçerlilik algoritması (ekrandan, 01:40:00): kart numarası `4411 0512 3456 7897` için baştan itibaren tek sıradaki haneler (1., 3., 5., ...) 2 ile çarpılır; sonuç 9'dan büyükse 9 çıkarılır. Dönüşmüş haneler `8 4 2 1 0 5 2 2 6 4 1 6 5 8 9 7` olur; toplamları 70'tir ve 10'a bölündüğü için numara geçerlidir.
  - Ders sonrası not: Hoca son haneye "CRC check" dedi; bu hane CRC değil, Luhn (mod 10) algoritmasının kontrol hanesidir.
- **Bilinen ama bilişim yoluyla işlenen suçlar** (ekrandan, 01:45:00): intihara yönlendirme (ör. "mavi balina" oyunu), uyuşturucu veya uyarıcı madde kullanılmasını kolaylaştırma, sağlık için tehlikeli madde sağlama, kumar için yer ve olanak sağlama, müstehcenlik, fuhuş, çocukların cinsel istismarı. Kumar, müstehcenlik ve fuhuşun suç sayılması ülkeden ülkeye değişir; kumarı yasaklayan ülkeler ancak para trafiğini engellemeye çalışabilir. Çocukların cinsel istismarı ise dünyanın ortak olarak suç kabul ettiği konudur; bu tür içeriği bulundurmak bile birçok ülkede suçtur.
  - Ders sonrası not: Hoca Türkiye'de kumarhanelerin "80'lerde, 82 ya da 84'te" kapandığını tahmin etti; kumarhaneler büyük olasılıkla 1997-1998'de kapatıldı.
- **Özel hayata karşı suçlar.** Sabıka ve mahkûmiyet bilgileri, güvenlik tedbirleri, biyometrik veriler gibi kişisel verilerin bilişim ortamında ele geçirilmesi, kullanılması ve dağıtılması bu kümededir. Konu Birleşmiş Milletler İnsan Hakları Evrensel Beyannamesi'nde de önemle yer alır.
- **Mal varlığına karşı suçlar** (ekrandan, 01:50:00): bilişim sistemleriyle başkasının parasını veya malını çalmaya nitelikli hırsızlık denir; internet bankacılığı ve kredi kartı soygunları nitelikli hırsızlık ve dolandırıcılık kapsamındadır. Kayıp veya çalıntı kart kullanımı en yaygın yöntemdir. Kimlik hırsızlığı yalnız manyetik şeritli kartlarda, şeritteki bilgi değiştirilerek yapılır.
- **Virüsler ve diğer saldırılar.** İlk virüsler tanınmak ya da kişisel tatmin için yazılmıştır: Apple II'ye disketle bulaşan Elk Cloner ve Pakistan'da iki kişinin yazdığı, PC'lere bulaşan Brain. Sonra Melissa ve e-postayla adres defterindeki kişilere kendini gönderen ILOVEYOU gibi virüsler yayıldı. Fidye yazılımları (ransomware) verileri şifreleyip parola karşılığında bitcoin ya da para ister; bu nitelikli soyguna girer. Bilgisayar denetimli sistemlere saldırıya örnek olarak İran'ın nükleer tesisini etkileyen ve kapalı ağa flash bellekle sokulan Stuxnet anlatıldı. <!-- BELİRSİZ: Virüs slaytı karelerde yok; adlar altyazıdan ("Elk Clonal", "İlalvi") düzeltildi. -->
- **Türkiye'de yasal durum.** Hocaya göre 2007'de bir bilişim yasası taslağı çalışması başlamış ama sonuçlanmamıştır. Bugün fikir ve sanat eserleri, elektronik imza, kişisel verilerin korunması, e-ticaret ve internet ortamında yapılan yayınların düzenlenmesi yasaları vardır, ama ayrı bir bilişim yasası yoktur. <!-- BELİRSİZ: 2007 tarihi kareden doğrulanamadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
