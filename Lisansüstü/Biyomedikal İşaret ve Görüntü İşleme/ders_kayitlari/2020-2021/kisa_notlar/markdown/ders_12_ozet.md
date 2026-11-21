# Ders 12 Çalışma Özeti

## Genel Konular

- Proje ilerleme sunumları
  - Ders, öğrencilerin dönem projelerindeki ilerlemeyi ekran paylaşarak anlattığı ve hocanın her projeye yöntemsel geri bildirim verdiği bir oturum olarak geçti.
  - Projelerin ortak ekseni histopatolojik ve sitolojik görüntülerde hücre/çekirdek sınıflandırma, bölütleme ve önceden eğitilmiş ağlarla transfer öğrenmedir.
- Kolon kanseri hücre çekirdeği sınıflandırma
  - Veri setinde 500×500 boyutlu görüntüler ve her çekirdeğin konumu verilmiştir; dört çekirdek sınıfı vardır (fibroblast, epitel vb.).
  - Verilen koordinatların etrafından 27×27 yamalar kırpılıyor, sonra bu yamalar transfer öğrenmeyle sınıflandırılacak.
  - MATLAB Deep Network Designer'da SqueezeNet tabanlı bir ağ açıldı: son katmanlar `conv10` (convolution2dLayer), `relu_conv10`, `pool10` (globalAveragePooling), `prob` (softmax); 68 katman, 75 bağlantı (ekrandan, 00:10:00).
- Transfer öğrenme ve topluluk (ensemble) modelleri
  - Kullanılan modeller: InceptionV3, InceptionResNetV2, VGG16, VGG19, DenseNet201, DenseNet169, ResNet152V2; hepsi ImageNet ağırlıklarıyla başlatıldı (ekrandan, 00:15:00).
  - Son katman yeni göreve göre değiştirildi, diğer katmanlar da eğitilebilir bırakıldı (ince ayar).
  - EfficientNet tek başına 0,89 doğruluk verdi; TensorFlow 2.3 ve Python 3.8 gerektirdiği için diğer modellerle sürüm uyumsuzluğu çıktı (ekrandan, 00:15:00).
  - Model ortalaması (model averaging) ve ağırlıklı ortalama (weighted average) topluluk yöntemleri denendi.
- MATLAB'de transfer öğrenme akışı
  - Hoca MathWorks "Get Started with Transfer Learning" sayfasını gösterdi: önceden eğitilmiş ağı yükle, son katmanları değiştir, ağı eğit, doğruluğu ölç, sonucu kullan (ekrandan, 00:20:00).
  - Önerilen yeni ağlar: NASNet, ShuffleNet, DarkNet-53 ve benzerleri.
- Kan hücresi (akyuvar) sınıflandırma ve eğitim süresi sorunu
  - Daha temiz yeni bir veri setinde eozinofil, lenfosit, monosit ve nötrofil sınıfları var; öğrencinin bölütleme yöntemi bu sette çok daha iyi çalıştı.
  - CPU ile eğitimin çok uzun sürdüğü eğitim ekranında görüldü (ekrandan, 00:25:00).
  - GPU sürücü sürümü uyumsuzluğu ve çözüm yolları: Google Colab, Kaggle, MATLAB'in AWS üzerindeki sürümü, MathWorks Cloud Center (ekrandan, 00:30:00).
- CRC ve Extended-CRC birleşik veri seti
  - İki veri seti birleştirildi; toplam 386 görüntü, üç derece (normal, düşük dereceli, yüksek dereceli kanser) (ekrandan, 00:35:00).
  - ResNet50 ve DenseNet201 ile 3 katlı çapraz doğrulama yapıldı; ortalama doğruluk ResNet50 için %92, DenseNet201 için %93.
- PanNuke veri seti
  - Hem sınıflandırma hem bölütleme için kullanılabilir; veri üç parça (fold) halinde, görüntüler 256×256×3.
  - Maske 6 katmanlıdır: beş çekirdek kategorisi ve bir arka plan katmanı. Makaledeki kategoriler neoplastik, neoplastik olmayan epitel, bağ dokusu (connective), iltihabi (inflammatory) ve ölü hücredir (dead) (ekrandan, 00:45:00).
  - Ayrıca her görüntünün hangi dokudan alındığını veren bir tip dosyası var: 19 doku tipi (ekrandan, 00:55:00).
- Beyin tümöründe GAN uygulaması
  - BraTS2020 verisi üzerinde vox2vox GAN kodu çalıştırıldı; bellek yetersizliği (out of memory) hatası alındı (ekrandan, 01:05:00).
- Servikal sitoloji verileri
  - Cervix93 verisinde çekirdek koordinatları görüntü üzerine basıldığında hücrelere denk gelmedi (ekrandan, 01:10:00).
  - Herlev verisi için U-Net ile bölütleme modeli kuruldu, ardından sınıflandırma yapılacak.
- Makale yazımına hazırlık
  - Proje sonunda bildiri ya da makale yazılacağı için okumalar sırasında kaynak ve not toplanması istendi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Birden fazla ağı karşılaştırmalı denemek
  - Yalnız bir hazır ağ yetmez; SqueezeNet, NASNet, Inception, ResNet, DenseNet, ShuffleNet, DarkNet gibi farklı ve olabildiğince yeni yöntemler denenip başarımları karşılaştırılmalı.
  - Transfer öğrenmenin farklı biçimleri de denenmeli: yalnız son katmanları eğitmek ya da ortadaki katmanları belli bir derinliğe kadar eğitmek.
- Başarım ölçütleri tablo halinde verilmeli
  - Genel doğruluk (overall accuracy), F-ölçütü, kesinlik (precision), duyarlılık (recall) ve ROC bir tabloda sunulmalı; karışıklık matrisi çıkarılmalı.
- k katlı çapraz doğrulamada ortalama raporlanır
  - Her katın sonucu ayrı ayrı gösterilmez; katların sonuçlarının ortalaması verilir.
  - k-fold bölmesi modelden bağımsızdır; hazır KFold fonksiyonu hangi örneğin hangi katta kullanılacağının indislerini verir, elle bölmeye gerek yoktur.
- Çekirdek sınıflandırmasında görüntünün tamamı verilmez
  - 256×256'lık bir görüntüde farklı tipte birçok çekirdek olabilir. Önce problem netleştirilmeli: çekirdek tipi mi, yama (patch) ya da doku tipi mi sınıflandırılacak?
  - Çekirdek tipi sınıflandırılacaksa her çekirdeğin etrafından ortak boyutlu bir çerçeve (örneğin 32×32 ya da 50×50) kesilip sınıf klasörlerine kaydedilir, sonra ağlar eğitilir.
  - Arka plandan da yama alınırsa model hücre olmayan bölgeyi de öğrenir.
- Veriyi tanımak ve hata ayıklamak
  - Koordinatlar hücrelere denk gelmiyorsa bir hata vardır; koordinatların transpozu alınarak, görüntü döndürülerek denenmeli.
  - Bir deneme olmadıysa bir sonraki derse kadar beklemek yerine araştırmaya devam edilmeli.
- Az veriyle sıfırdan eğitim zordur
  - Veri azken sıfırdan eğitilen ağ (örneğin U-Net) iyi öğrenemez; önceden eğitilmiş ağlarla transfer öğrenme işe yarar.
- Makale hazırlığı
  - Bir yayında en az 20 civarı kaynak olmalı; kaynaklar web sayfalarından çok bilimsel makaleler olmalı.
  - En az 1-1,5 sayfalık bir giriş (introduction) gerekir. Aynı veri setini kullanan makalelerin veri setini nasıl tanıttığı, tabloları, akış şeması ve başarım ölçütleri incelenmeli.

## Kısa Tekrar Notları

- Transfer öğrenme: ImageNet gibi büyük veride eğitilmiş ağın ilk katmanları düşük seviyeli öznitelikleri (kenar, leke, renk), son katmanları göreve özgü öznitelikleri öğrenir; son katmanlar yeni sınıflara göre değiştirilir.
- Topluluk modeli: birden fazla modelin çıktısı ortalanır; eşit ağırlıkla 0,88, doğruluğa göre elle ağırlıklandırınca 0,89 doğruluk elde edildi (derste sözlü).
- Ağırlıklar elle değil bir optimizasyon yöntemiyle otomatik bulunabilir.
- k-fold sonuçlarının ortalaması raporlanır.
- CRC + Extended-CRC: 177 normal, 121 düşük dereceli, 88 yüksek dereceli, toplam 386 görüntü (ekrandan, 00:35:00).
- PanNuke maskesi 6 katmanlı; bir katmanda sıfırdan farklı pikseller o katmanın çekirdek tipine aittir; renkler yalnızca Python'un matris değerlerini boyamasıdır.
- Çekirdek sınıflandırması için çekirdek etrafından sabit boyutlu yama çıkarılır.
- Bellek hatasında kullanılmayan değişkenler silinir; Colab ya da Kaggle'ın GPU/TPU hizmeti kullanılabilir.
- Koordinat-görüntü uyuşmazlığında transpoz ve döndürme denenir.
- Makale için kaynak, giriş cümleleri, veri seti tanıtımı ve başarım tablosu örnekleri şimdiden toplanır.

## Detaylı Açıklamalar

- **Transfer öğrenmede neyin eğitildiği.** Bir öğrenci yedi farklı önceden eğitilmiş modeli ImageNet ağırlıklarıyla başlattı, son katmanı kendi sınıflarına göre değiştirdi ve diğer katmanları da eğitilebilir bıraktı. Yani bütün ağ ImageNet ağırlıklarından başlayarak yeniden eğitildi. Hoca diğer öğrenciden de transfer öğrenmenin farklı biçimlerini denemesini istedi: yalnız son katmanları eğitmek ya da ortadaki katmanları belli bir derinliğe kadar eğitmek. MATLAB'in transfer öğrenme sayfasındaki akış da aynıdır: önceden eğitilmiş ağ yüklenir, son katmanlar yeni sınıflara göre değiştirilir, ağ eğitilir, test görüntülerinde doğruluk ölçülür ve gerekirse ağ iyileştirilir (ekrandan, 00:20:00). Sayfaya göre sıfırdan, rastgele ağırlıklarla eğitmeye kıyasla bu yol çok daha hızlıdır ve daha az eğitim görüntüsü ister.
- **Topluluk (ensemble) modelleri.** Model ortalamasında her modelin çıktısı eşit ağırlıkla birleştirilir. Sunumda tek başına modellerin doğruluğu 0,82 ile 0,84 arasındaydı (InceptionV3 için 0,84). Eşit ağırlıklı topluluk 0,88'e, doğruluğu yüksek modellere daha fazla ağırlık verilen elle ağırlıklandırılmış topluluk 0,89'a çıktı (derste sözlü). Öğrenci ağırlıkları otomatik bulan bir yöntem kullanmayı planlıyor. Hoca sonuçların genel doğruluk ve F-ölçütüyle bir tabloda karşılaştırılmasını istedi.
  <!-- BELİRSİZ: Ağırlıkları otomatik bulan yöntem altyazıda "derivatif yöntem" diye geçiyor; büyük olasılıkla diferansiyel evrim (differential evolution). Veri setinin adı da altyazıda "10.000 istikleri seti" diye bozuk geçiyor. -->
- **k katlı çapraz doğrulama.** Veri eğitim ve test diye bir kez bölünmek yerine k parçaya ayrılır; her seferinde bir parça test, kalanı eğitim olur. MATLAB kodunda `num_folds=3` ile 3 katlı döngü kuruldu (ekrandan, 00:40:00). Hoca her katın sonucunu tek tek göstermek yerine katların ortalamasının raporlanması gerektiğini söyledi. Başka bir öğrenciye de k-fold bölmesinin modelden bağımsız olduğunu, hazır bir KFold fonksiyonunun her kat için kullanılacak örneklerin indislerini verdiğini anlattı.
- **PanNuke maskesinin yapısı.** Her görüntünün maskesi 6 katmanlıdır. Makaleye göre katmanlar beş çekirdek kategorisine (neoplastik, neoplastik olmayan epitel, bağ dokusu, iltihabi, ölü hücre) ve arka plana karşılık gelir (ekrandan, 00:45:00); son katman (indis 5) arka plandır. <!-- BELİRSİZ: Öğrencinin altyazıda okuduğu katman sırası (neoplastik, neoplastik olmayan, iltihabi, bağ dokusu, ölü, çekirdek olmayan) bozuk geçiyor; katman-sınıf eşlemesi derste kesinleşmedi. --> Bir katmanda sıfırdan farklı değer alan pikseller o katmanın çekirdek tipine aittir. Arka plan katmanında ise tersine çekirdekler 0, arka plan 1'dir. Bir maske katmanındaki değerler sayıldığında 0 değeri 60518 piksel, 49, 54, 62, 63, 80 ve 83 değerleri birkaç yüz ile 1358 piksel arasında çıktı (ekrandan, 00:50:00). Toplam $256 \times 256 = 65536$ pikseldir. Öğrenci 49, 54, 62 gibi değerlerin anlamını bulamadı. Hoca renklerin yalnızca Python'un matris değerlerini boyaması olduğunu söyledi.
- **Hücre tabanlı sınıflandırma için yama çıkarma.** Hoca şu yolu önerdi: her katmandaki her çekirdeğin etrafına onu kapsayan en küçük çerçeve alınır. Bütün veri setindeki çekirdekleri sığdıracak ortak bir çerçeve boyutu (örneğin 32×32 ya da 50×50) seçilir. Kesilen yamalar sınıf numarasına göre ayrı klasörlere kaydedilir. Sonra farklı ağlarla ve k-fold ile sınıflar ayrıştırılabiliyor mu diye bakılır. Arka plan katmanındaki hücresiz bölgelerden de yama alınırsa model hücre ile arka planı ayırmayı da öğrenir. Alternatif bir problem, görüntünün tamamından 19 doku tipini sınıflandırmaktır (örneğin tiroid ile kolon dokusu ayrışıyor mu).
- **Koordinatların görüntüye denk getirilmesi.** Cervix93 verisinde koordinatlar basıldığında noktalar görüntünün sağ üstünde toplandı, hücreler ise sol altta yoğundu (ekrandan, 01:10:00). Makaleye göre bir çekirdeğin yarısı çerçeve içindeyse ya da sınıra 10 piksel uzaklıktaysa işaretlenmiştir. Ama noktalar hücre olmayan yerlere de düşüyordu. Hoca koordinatların transpozunun alınıp yeniden basılmasını, görüntünün döndürülmesini önerdi. Bu tür denemelerin veriyi tanımanın ve hata ayıklamanın parçası olduğunu vurguladı.
- **Hesaplama kaynakları.** CPU ile MATLAB'de eğitimde 50 epoch yaklaşık 220 dakika sürdü (ekrandan, 00:25:00). Hoca Google Colab ve Kaggle'ın GPU hizmetlerini, MATLAB'in Amazon Web Services üzerindeki sürümünü ve MathWorks Cloud Center'ı önerdi. Cloud Center, Amazon bulutunda hesaplama kümeleri kurup bunlara MATLAB'den Parallel Computing Toolbox ile iş göndermeyi sağlar (ekrandan, 00:30:00). Bellek yetersizliği hatası için kullanılmayan değişkenlerin silinmesini ve Kaggle not defterinin ayarlarından GPU ya da TPU hızlandırıcının açılmasını önerdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
