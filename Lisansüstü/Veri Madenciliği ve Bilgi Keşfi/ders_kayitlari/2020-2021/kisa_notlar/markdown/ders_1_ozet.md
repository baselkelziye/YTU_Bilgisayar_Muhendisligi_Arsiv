# Ders 1 Çalışma Özeti

## Genel Konular

- Veri madenciliği nedir ve neden gereklidir
  - Ders slaytının tanımı: veri madenciliği (veriden bilgi keşfi), büyük miktardaki veriden ilginç (önemsiz olmayan, örtük, önceden bilinmeyen ve potansiyel olarak yararlı) örüntülerin ya da bilginin çıkarılmasıdır (ekrandan, 00:35:20).
  - İnternette ve sistemlerde toplanan veri her gün artıyor. Kullanıcıların bağlandığı saatler, ilgilendiği sayfalar gibi her hareket loglanıyor. Bu birikmiş verinin anlamlı bilgiye dönüştürülmesi gerekiyor.
  - Veri madenciliği karar destek sistemlerini veriden öğrenir. Bu yüzden biriken veriyi kullanmak işletmelere büyük avantaj sağlar.
  - Veri tabanı yönetim sistemlerindeki gelişmeler, verinin düzenli ve yapısal biçimde toplanmasını sağladığı için veri madenciliğini kolaylaştırır.
- Veri kaynakları
  - İşletme ve ticari veriler: e-ticaret, bankacılık, bireysel emeklilik, borsa işlemleri.
  - Bilimsel alanda toplanmış veriler.
  - Sosyal platformlarda oluşan veriler.
- Veri madenciliğinin diğer adları
  - Slayttaki liste: veri tabanlarında bilgi keşfi (KDD), knowledge extraction, data/pattern analysis, data archeology, data dredging, information harvesting, business intelligence (ekrandan, 00:35:20).
  - İşletme tarafı bu yöntemleri "iş zekası" (BI) başlığı altında toplamıştır. Farklı adlarla sunulan bu çalışmaların hepsi aslında veri madenciliğidir.
  - Slaytta ayrıca basit arama ve sorgu işlemenin ve (tümdengelimli) uzman sistemlerin veri madenciliği sayılmadığı uyarısı var (ekrandan, 00:35:20).
- Potansiyel uygulama alanları (ekrandan, 00:40:00)
  - Veri analizi ve karar destek
    - Pazar analizi ve yönetimi: hedefli pazarlama, müşteri ilişkileri yönetimi (CRM), market sepeti analizi, çapraz satış, pazar segmentasyonu.
    - Risk analizi ve yönetimi: tahmin (forecasting), müşteriyi elde tutma, improved underwriting, kalite kontrol, rekabet analizi.
    - Sahtecilik tespiti (fraud detection) ve olağandışı örüntülerin (aykırı değerlerin) tespiti.
  - Diğer uygulamalar: metin madenciliği (haber grupları, e-posta, belgeler) ve web madenciliği, akan veri (stream data) madenciliği, biyoinformatik ve biyolojik veri analizi.
- Veri madenciliği stratejileri hiyerarşisi (ekrandan, 01:17:30)
  - Üç ana strateji: eğiticisiz kümeleme (unsupervised clustering), eğiticili öğrenme (supervised learning), market sepeti analizi (market basket analysis).
  - Eğiticili öğrenmenin altında üç işlem: sınıflandırma (classification), kestirim (estimation), öngörü (prediction).
- Eğiticili öğrenme ve karar ağacı örneği
  - Kaynağı bilinen (etiketli) örneklerle bir öğrenen model kurulur; model, kaynağı bilinmeyen yeni örneklerin sonucunu belirlemek için kullanılır (ekrandan, 01:20:00).
  - Hasta teşhisi veri setiyle bir karar ağacı kurulur ve test hastalarına uygulanır.
- Eğiticisiz kümeleme ve Acme yatırımcı veri seti
  - Sınıf etiketi yoktur; birbirine benzeyen örnekler kümelere ayrılır.
  - Aynı veri setinde bir öz nitelik çıkış değişkeni seçilirse eğiticili öğrenme de yapılabilir.
- Sınıflandırma, kestirim ve öngörü arasındaki farklar
- Market sepeti analizi ve birliktelik kuralları
- Üretim kuralları (production rules), kural doğruluğu ve kural kapsaması
  - Kredi kartı promosyonu veri seti üzerinde iki kural için hesap yapılır.
- Bilgi keşfi (KDD) süreci ve adımları
- Veri madenciliği ve iş zekası piramidi
- Veri madenciliğinin çok disiplinli yapısı

## Hocanın Özellikle Vurguladığı Kısımlar

- Verinin önce iyi tanınması
  - Hocaya göre dersin en önemli noktası, veri madenciliği süreçlerine girmeden önce veriyi çok iyi analiz etmek, tanımak ve gerekli düzenlemeleri yapmaktır.
  - Ders programının ilk haftaları bu yüzden veri ayrıklaştırma (discretization), veri temizleme, aykırı değer analizi ve eksik veri gibi konulara ayrılmıştır.
- "Unsupervised classification" denmez
  - Eğiticisiz yapılan işlem kümelemedir (clustering). Hoca bu kavramın yanlış kullanılmaması gerektiğini özellikle vurguladı.
- Sınıflandırma, kestirim ve öngörünün ayrımı
  - Ayrım iki soruya dayanır: çıkış değişkeni kategorik mi, sayısal mı; sonuç mevcut durum için mi, gelecek için mi?
  - Hoca bu kavramları iyi ayırt etmenin, ileride hangi yöntemin kullanılacağına karar vermeyi kolaylaştıracağını söyledi.
- Veri temizleme ve ön işleme emeğin büyük kısmını alır
  - Slaytta bu adımın emeğin %60'ını alabileceği yazıyor (ekrandan, 02:35:10). Hoca, projenin son gününde bile hâlâ veriyle uğraşıyor olacağınızı söyledi.
- Başarı yalnız doğrulukla ölçülmez
  - Accuracy dışında precision gibi başka değerlendirme ölçütlerine de bakılır ve farklı algoritmalar karşılaştırılır.
- Algoritmaları kodlayabilecek düzeyde anlamak
  - Derste algoritmaların yalnızca adı verilmeyecek; adımları, kodlanabilecek düzeyde anlatılacak. Hazır araçları kullanmak yerine algoritmayı geliştiren ve iyileştiren tarafta olmak hedefleniyor.
- Sahtecilik tespitinde müşteri mağduriyeti
  - Hoca, yurt dışında yaptığı bir harcamadan sonra teyit alınmadan kartının bloke edildiği bir deneyimi anlattı. Sahteciliği önlemek kadar gerçek müşteriyi mağdur etmemek de önemlidir; yanlış alarm veren bir sistem iyi tasarlanmamış demektir.

## Kısa Tekrar Notları

- Veri madenciliği = büyük veriden önemsiz olmayan, örtük, önceden bilinmeyen ve yararlı örüntülerin çıkarılması.
- Diğer adları: KDD, knowledge extraction, data archeology, data dredging, information harvesting, business intelligence.
- Üç strateji: eğiticili öğrenme, eğiticisiz kümeleme, market sepeti analizi.
- Eğiticili öğrenme: sınıflandırma, kestirim, öngörü.
- Eğitim verisi (training set) etiketlidir; test verisinin de etiketi vardır ama model etiketi görmeden karar verir, sonra gerçek etiketle karşılaştırılarak başarı ölçülür.
- Satır = örnek (sample, instance); sütun = öz nitelik (feature, attribute); teşhis sütunu = çıkış (bağımlı) değişkeni, sınıf etiketi.
- Sınıflandırma: eğiticili, çıkış kategorik, sınıflar iyi tanımlı, gelecek değil mevcut davranış.
- Kestirim: eğiticili, çıkış sayısal, mevcut davranış (ör. ev fiyatı; regresyon).
- Öngörü: gelecek tahmini, çıkış kategorik ya da sayısal olabilir (ör. İMKB 100 endeksinin yarınki kapanışı).
- Kümeleme: etiket yok, benzer örnekler gruplanır.
- Market sepeti analizi: perakende ürünler arasındaki ilginç ilişkiler; birliktelik kuralı algoritmaları.
- Kural doğruluğu (rule accuracy) = koşulu sağlayanlar içinde sonucu da doğru olanların oranı (sınıflar arası ölçü).
- Kural kapsaması (rule coverage) = hedef sınıftaki örneklerin kaçta kaçını kuralın tarif ettiği (sınıf içi ölçü).
- KDD: veri temizleme ve bütünleştirme, veri ambarı, seçim, göreve uygun veri, veri madenciliği, örüntü değerlendirme, bilgi; sonuç yetersizse geri dönülür.
- Veri temizleme ve ön işleme emeğin %60'ını alabilir.

## Detaylı Açıklamalar

- **Eğiticili öğrenme ve karar ağacı örneği.** Eğiticili öğrenme iki aşamalıdır. Önce alan uzmanının etiketlediği veriyle (eğitim verisi) bir model eğitilir. Sonra modelin başarısı test verisiyle ölçülür. Test örneklerinin de gerçekte bir sınıf bilgisi vardır. Model bu bilgiyi kullanmadan karar verir, ardından modelin cevabı bilinen etiketle karşılaştırılır. Derste kullanılan eğitim verisi aşağıdadır (ekrandan, 01:21:45):

  | Hasta | Sore Throat | Fever | Swollen Glands | Congestion | Headache | Diagnosis |
  |---|---|---|---|---|---|---|
  | 1 | Yes | Yes | Yes | Yes | Yes | Strep throat |
  | 2 | No | No | No | Yes | Yes | Allergy |
  | 3 | Yes | Yes | No | Yes | No | Cold |
  | 4 | Yes | No | Yes | No | No | Strep throat |
  | 5 | No | Yes | No | Yes | No | Cold |
  | 6 | No | No | No | Yes | No | Allergy |
  | 7 | No | No | Yes | No | No | Strep throat |
  | 8 | Yes | No | No | Yes | Yes | Allergy |
  | 9 | No | Yes | No | Yes | Yes | Cold |
  | 10 | Yes | Yes | No | Yes | Yes | Cold |

  Bu 10 örnekle kurulan karar ağacı (ekrandan, 01:24:15) önce bez şişmesini (swollen glands) sorar. Cevap evetse teşhis boğaz enfeksiyonudur (strep throat). Hayırsa ateş (fever) sorulur: ateş yoksa alerji, varsa soğuk algınlığı. Slayttaki tanım: iç düğümlerin bir ya da birkaç öz nitelik üzerindeki testleri, yaprak düğümlerin karar sonuçlarını gösterdiği ağaç yapısı. Beş sorudan yalnızca ikisi kullanılmıştır, çünkü bu 10 örnekte üç sınıfı ayırmak için iki soru yeter. Daha fazla örnek ve sınıf olsaydı diğer öz nitelikler de gerekebilirdi. Model 10 eğitim örneğinin hepsini doğru sınıflandırır (python ile doğrulandı). Test hastaları (ekrandan, 01:30:00) için sonuç:

  | Hasta | Sore Throat | Fever | Swollen Glands | Congestion | Headache | Modelin teşhisi |
  |---|---|---|---|---|---|---|
  | 11 | No | No | Yes | Yes | Yes | Strep throat |
  | 12 | Yes | Yes | No | No | Yes | Cold |
  | 13 | No | No | No | No | Yes | Allergy |

- **Eğiticisiz kümeleme ve yatırımcı veri seti.** Acme Investors veri setinde (ekrandan, 01:33:00) beş müşteri için hesap türü, margin hesabı, işlem yöntemi (online ya da broker), aylık işlem sayısı, cinsiyet, yaş aralığı, hobi ve yıllık gelir vardır. Sınıf etiketi olmadığı için yapılabilecek ilk iş, birbirine benzeyen müşterileri kümelere ayırmaktır. Bir öz nitelik (örneğin işlem yöntemi) çıkış değişkeni seçilirse veri eğitim verisine dönüşür ve eğiticili öğrenme yapılabilir: online yatırımcının genel profili çıkarılabilir ya da yeni bir müşterinin margin hesabı açıp açmayacağı tahmin edilebilir. Hoca, yaşı ileri müşterilerin online işlem yerine telefonla bir aracı üzerinden işlem yapmayı tercih edebileceği örneğini verdi.
  - Ders sonrası not: Hoca 01:35:46'da müşterileri gruplama işlemi için "supervised tarafta" dedi; bağlamdan anlaşıldığı gibi doğrusu eğiticisiz (unsupervised) taraftır.
- **Sınıflandırma, kestirim, öngörü.** Sınıflandırma slaytı (ekrandan, 01:40:00): öğrenme eğiticilidir, bağımlı değişken kategoriktir, sınıflar iyi tanımlıdır, gelecek değil mevcut davranış esas alınır. Kestirimde bağımlı değişken sayısaldır ve yine mevcut durum için sonuç üretilir. Öngörü slaytı (ekrandan, 01:41:45): vurgu mevcut değil gelecekteki sonuçları tahmin etmektir; çıkış öz niteliği kategorik ya da sayısal olabilir. Derste konuşulan örnekler:
  - İMKB 100 endeksinin yarınki ya da bir hafta sonraki kapanış değeri: sayısal ve gelecek, yani öngörü.
  - Oda sayısı, kat, konum, otopark gibi özelliklerden ev fiyatı: sayısal ve mevcut, yani kestirim. Bir öğrencinin sorusu üzerine hoca kestirimin regresyon olduğunu onayladı.
  - EKG sonuçlarından kalp krizi geçirip geçirmeyeceğini tahmin etmek: kategorik ve gelecek, yani öngörü (sınıflandırma türünde).
  - Seçimi hangi partinin kazanacağı: kategorik; kazanma olasılığı verilirse sayısal.
  - Hisse için "al/sat" kararı veren robotlar: kategorik çıkış.
- **Market sepeti analizi.** Slayt (ekrandan, 01:50:00): perakende ürünler arasında ilginç ilişkiler bulmak; birliktelik kuralı algoritmaları kullanılır. Sık satılan ve birlikte satılan ikili, üçlü ürün grupları belirlenerek satış artırılmaya çalışılır. Online satışta hangi kullanıcının hangi ürünleri birlikte aldığı bilindiği için bu sistemler kişiye özel öneri sistemlerine (personalized recommendation) dönüşmektedir.
- **Üretim kuralları ve kredi kartı promosyonu veri seti.** Veri setinde 15 örnek ve 7 öz nitelik (gelir aralığı, dergi promosyonu, saat promosyonu, hayat sigortası promosyonu, kredi kartı sigortası, cinsiyet, yaş) vardır (ekrandan, 02:20:00). Sayısal olan tek öz nitelik yaştır. Gelir aralığı aralıklara bölündüğü için kategoriktir. Yaşı da aralıklara bölüp kategorik yapmak mümkündür, ama o zaman örnekler arasındaki uzaklık (yaş yakınlığı) ölçülemez.
  - Kural 1 (ekrandan, 02:17:30): IF Sex = Female & $19 \le Age \le 43$ THEN Life Insurance Promotion = Yes. Koşulu 6 kadın sağlar ve 6'sı da "Yes" demiştir: doğruluk $6/6 = \%100$. Hayat sigortasına "Yes" diyen toplam 9 kişi vardır: kapsama $6/9 = \%66{,}67$.
  - Kural 2 (derste sözlü, 02:22:53): IF Sex = Male & Income Range = 40-50K THEN Life Insurance Promotion = No. Koşulu 3 kişi sağlar, üçü de "No" demiştir: doğruluk $3/3 = \%100$. "No" diyen toplam 6 kişi vardır: kapsama $3/6 = \%50$.
  - Slayta göre kural doğruluğu sınıflar arası (between-class), kural kapsaması sınıf içi (within-class) bir ölçüdür (ekrandan, 02:17:30).
  - Ders sonrası not: Hoca sayım sırasında önce 5 kişi ve "Yes" diyen 4 kişi dedi, sonra 6 ve 9'a düzeltti. Doğru sayılar 6 ve 9'dur; kapsama %66 değil %66,67'dir (python ile doğrulandı).
- **KDD süreci.** Slayttaki şemaya göre (ekrandan, 02:30:00) veri madenciliği bilgi keşfi sürecinin çekirdeğidir. Veri tabanlarından veri temizleme ve veri bütünleştirme ile veri ambarına, oradan seçim (selection) ile göreve uygun veriye, sonra veri madenciliğine ve örüntü değerlendirmeye, en sonunda bilgiye ulaşılır. Şemadaki geri dönüş okları, sonuç yeterli değilse önceki adımlara (ör. öz nitelik seçimi) dönüldüğünü gösterir. Hoca örnek olarak şirketi terk edecek müşterileri bulma amacını verdi: sonucu etkileyebilecek bütün öz nitelikler veri setine konur, sonra öz nitelik seçimi (feature selection) ile gerçekten gerekli olanlar seçilir, ardından birden fazla algoritma denenip karşılaştırılır.
  - Anahtar adımlar (ekrandan, 02:35:10): uygulama alanını öğrenmek (ilgili ön bilgi ve uygulamanın amacı); hedef veri setini oluşturmak (veri seçimi); veri temizleme ve ön işleme (emeğin %60'ını alabilir); veri indirgeme ve dönüştürme (yararlı öz nitelikleri bulmak, boyut/değişken azaltma, değişmez gösterim); veri madenciliği işlevini seçmek (özetleme, sınıflandırma, regresyon, birliktelik, kümeleme); madencilik algoritmasını seçmek; veri madenciliği (ilginç örüntü arama); örüntü değerlendirme ve bilgi sunumu (görselleştirme, dönüştürme, gereksiz örüntüleri ayıklama vb.); keşfedilen bilginin kullanılması.
- **Veri madenciliği ve iş zekası piramidi.** Aşağıdan yukarıya (ekrandan, 02:38:00): veri kaynakları (kâğıt, dosyalar, web belgeleri, bilimsel deneyler, veri tabanı sistemleri); veri ön işleme/bütünleştirme ve veri ambarları (DBA); veri keşfi (istatistiksel özet, sorgulama, raporlama); veri madenciliği (bilgi keşfi; veri analisti); veri sunumu (görselleştirme teknikleri; iş analisti); karar verme (son kullanıcı). Yukarı çıktıkça iş kararlarını destekleme potansiyeli artar. Hoca, veri analistinin veri tabanı yöneticisine hangi alanlara ihtiyaç duyduğunu bildirdiğini, verinin onun tarafından hazırlandığını anlattı.
- **Çok disiplinli yapı.** Veri madenciliği veri tabanı teknolojisi, istatistik, makine öğrenmesi, örüntü tanıma, algoritma, görselleştirme ve diğer disiplinlerin kesişimindedir (ekrandan, 02:40:00). Bu alanla uğraşan kişinin istatistik, algoritma, veri tabanı, görselleştirme ve makine öğrenmesi bilmesi gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
