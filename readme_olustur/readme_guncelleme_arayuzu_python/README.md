# Proje Dokümantasyonu 📄

Bu README dosyası, projenin temel bileşenlerini ve her bir Python dosyasının işlevlerini detaylı bir şekilde açıklamaktadır.

## Gereksinimleri İndirme 📦

Projeyi başarıyla çalıştırabilmek için aşağıdaki adımları izleyerek gerekli kütüphaneleri ve bağımlılıkları yükleyiniz:

1. **Python 3 Kurulumu:** Projeyi çalıştırmak için Python 3'ün bilgisayarınızda yüklü olması gerekmektedir. Python'ı [buradan](https://www.python.org/downloads/) indirebilirsiniz (linux için `sudo apt install python3`). Kurulum tamamlandıktan sonra terminali açın ve `python3 --version` komutu ile kurulumun başarılı olduğunu doğrulayın. 🐍

2. **Pip3 Kurulumu:** Pip, Python paketlerini yönetmek için kullanılan bir araçtır. Python 3 ile birlikte genellikle otomatik olarak yüklenir. Kurulumunu doğrulamak için terminali açın ve `pip3 --version` komutunu çalıştırın. Eğer kurulu değilse, [Pip'in resmi belgelerini](https://pip.pypa.io/en/stable/installing/) takip ederek kurulum yapabilirsiniz.(linux için `sudo apt install python3-pip`) 🛠️

3. **Gerekli Kütüphanelerin Yüklenmesi:** Projede kullanılan kütüphaneleri yüklemek için, terminalinize `pip3 install -r ../gereksinimler.txt` komutunu girin. Bu komut, `gereksinimler.txt` dosyasında listelenen tüm paketleri yükleyecektir. 📚

## Nasıl Çalıştırılır 🚀

Bu bölümde, projeyi yerel makinenizde nasıl çalıştırabileceğinize dair adımlar anlatılmaktadır.

- Projeyi çalıştırmak için terminalde `python3 main.py` komutunu kullanın.

## Dosyalar ve İşlevleri 📂

### 1. main.py

Bu bölüm, `main.py` dosyasının işlevlerini ve nasıl kullanılacağını açıklar. Bu dosya, uygulamanın ana giriş noktasını temsil eder ve farklı modüller arasında koordinasyon sağlar.

#### Özellikler 🌟

- **Grafiksel Kullanıcı Arayüzü (GUI)**: PyQt5 kütüphanesini kullanarak oluşturulmuş, kullanıcı dostu bir arayüz sunar.
- **Modül Entegrasyonu**: Diğer modüllerle (örneğin, `katkida_bulunanlari_duzenle_window`, `yazarin_notlari_duzenle_window`, vb.) entegrasyon sağlar, bu sayede uygulamanın farklı fonksiyonları arasında geçiş yapılabilir.
- **Butonlar ve İşlevsellik**: Kullanıcıların farklı işlemleri gerçekleştirmesine olanak tanıyan çeşitli butonlar içerir.

#### Kullanımı

Bu dosyayı çalıştırarak uygulamanın ana arayüzünü başlatırsınız:

1. **Uygulamayı Başlatma**: Terminalde `python3 main.py` komutunu kullanarak uygulamayı başlatın.
2. **Modüllere Erişim**: Ana arayüzde yer alan butonları kullanarak katkıda bulunanları düzenleme, yazarın notlarını düzenleme gibi işlemleri gerçekleştirebilirsiniz.
3. **Ayarlar ve Yapılandırma**: Uygulama, kullanıcı ihtiyaçlarına göre yapılandırılabilir ve genişletilebilir.

#### Geliştirme Notları

- Arayüz, PyQt5 kütüphanesi kullanılarak geliştirilmiştir.
- Uygulamanın modüler yapısı, kolay güncelleme ve bakım sağlar.

Bu dosya, projenin merkezi ve başlangıç noktası olarak hizmet eder ve kullanıcıların projenin diğer modüllerine kolayca erişmesini sağlar.


### 2. hoca_ekle_guncelle_window.py

Bu bölüm, `hoca_ekle_guncelle_window.py` dosyasının işlevlerini, içerdiği sınıfları ve fonksiyonları kapsamlı bir şekilde açıklar. Bu dosya, hocaları eklemek ve güncellemek için kullanılan bir grafiksel kullanıcı arayüzü sağlar.

#### Özellikler 🌟

- **Hoca Ekleme/Güncelleme**: Kullanıcılar, hocaların bilgilerini ekleyebilir ve mevcut bilgileri güncelleyebilir.
- **Kullanıcı Dostu Arayüz**: PyQt5 kullanılarak geliştirilen bu arayüz, kolay ve anlaşılır bir kullanım sunar.
- **JSON Entegrasyonu**: Hoca bilgileri, `.json` formatında kaydedilir ve bu dosyadan okunur, bu sayede kolayca güncellenebilir ve yönetilebilir.

#### Kullanımı

Bu arayüzü kullanarak hoca bilgilerini yönetmek için aşağıdaki adımları takip edin:

1. **Hoca Ekleme**: 'Ekle' butonuna tıklayarak yeni hoca bilgileri ekleyin.
2. **Hoca Düzenleme**: Mevcut hocalar arasından seçim yaparak bilgilerini güncelleyin.
3. **Bilgi Kontrolü ve Kaydetme**: Girilen bilgilerin doğruluğunu kontrol edip 'Kaydet' butonu ile kaydedin.

#### Geliştirme Notları

- **`initUI()`**: Arayüzü başlatan ve bileşenleri yerleştiren fonksiyon.
- **`HocaEkleGuncelleWindow(QDialog)`**: Hocaları eklemek ve güncellemek için kullanılan ana diyalog penceresi sınıfı.

#### Fonksiyonlar ve Sınıflar

- **`HocaEkleGuncelleWindow(QDialog)`**: Hocaların bilgilerini eklemek ve düzenlemek için kullanılan ana diyalog penceresi sınıfı.
  - **`initUI()`**: Arayüz bileşenlerini başlatır ve yerleştirir.
  - **`ekleBtn`, `kaydetBtn`**: Hoca eklemek ve değişiklikleri kaydetmek için kullanılan butonlar.
  - Diğer UI bileşenleri ve yardımcı fonksiyonlar.

Bu dosya, projenin eğitim yönetimini kolaylaştıran önemli bir parçası olarak hizmet eder ve kullanıcıların hoca bilgilerini verimli bir şekilde yönetmesine olanak tanır.


### 3. katkida_bulunanlari_duzenle_window.py

Bu bölüm, `katkida_bulunanlari_duzenle_window.py` dosyasının işlevlerini, içerdiği sınıfları ve fonksiyonları kapsamlı bir şekilde açıklar. Bu dosya, projeye katkıda bulunanları düzenlemek ve yönetmek için kullanılan bir grafiksel kullanıcı arayüzü sağlar.

#### Özellikler 🌟

- **Katkıda Bulunanları Düzenleme/Güncelleme**: Kullanıcılar, katkıda bulunan kişilerin bilgilerini düzenleyebilir ve güncelleyebilir.
- **Kullanıcı Dostu Arayüz**: PyQt5 kullanılarak geliştirilen bu arayüz, kolay ve anlaşılır bir kullanım sunar.
- **JSON Entegrasyonu**: Katkıda bulunanların bilgileri, `.json` formatında kaydedilir ve bu dosyadan okunur, bu sayede kolayca güncellenebilir ve yönetilebilir.

#### Kullanımı

Bu arayüzü kullanarak katkıda bulunanların bilgilerini yönetmek için aşağıdaki adımları takip edin:

1. **Katkıda Bulunanları Düzenleme**: Mevcut katkıda bulunanlar arasından seçim yaparak bilgilerini güncelleyin.
2. **Yeni Katkıda Bulunan Ekleme**: 'Ekle' butonuna tıklayarak yeni katkıda bulunanlar ekleyin.
3. **Bilgileri Kaydetme**: Değişiklikleri kaydetmek için 'Kaydet' butonuna tıklayın.

#### Geliştirme Notları

- **`initUI()`**: Arayüzü başlatan ve bileşenleri yerleştiren fonksiyon.
- **`KatkidaBulunanGuncelleWindow(QDialog)`**: Katkıda bulunanları düzenlemek için kullanılan ana diyalog penceresi sınıfı.

#### Fonksiyonlar ve Sınıflar

- **`KatkidaBulunanGuncelleWindow(QDialog)`**: Katkıda bulunanların bilgilerini düzenlemek için kullanılan ana diyalog penceresi sınıfı.
  - **`initUI()`**: Arayüz bileşenlerini başlatır ve yerleştirir.
  - **`ekleBtn`, `kaydetBtn`**: Katkıda bulunan eklemek ve değişiklikleri kaydetmek için kullanılan butonlar.
  - Diğer UI bileşenleri ve yardımcı fonksiyonlar.

Bu dosya, projenin topluluk yönetimini kolaylaştıran önemli bir parçası olarak hizmet eder ve kullanıcıların katkıda bulunan kişileri verimli bir şekilde yönetmesine olanak tanır.


### 4. yazarin_notlari_duzenle_window.py

Bu bölüm, `yazarin_notlari_duzenle_window.py` dosyasının işlevlerini, içerdiği sınıfları ve fonksiyonları kapsamlı bir şekilde açıklar. Bu dosya, yazarın notlarını eklemek, düzenlemek ve görüntülemek için kullanılan bir grafiksel kullanıcı arayüzü sağlar.

#### Özellikler 🌟

- **Not Ekleme/Düzenleme**: Kullanıcılar, yazarın notlarını ekleyebilir ve mevcut notları düzenleyebilir.
- **Kullanıcı Dostu Arayüz**: PyQt5 kullanılarak geliştirilen bu arayüz, kolay ve anlaşılır bir kullanım sunar.
- **JSON Entegrasyonu**: Notlar, `.json` formatında kaydedilir ve bu dosyadan okunur, bu sayede kolayca güncellenebilir ve yönetilebilir.

#### Kullanımı

Bu arayüzü kullanarak yazarın notlarını yönetmek için aşağıdaki adımları takip edin:

1. **Not Ekleme**: 'Not Ekle' butonuna tıklayarak yeni notlar ekleyin.
2. **Not Düzenleme**: Mevcut notlar arasından seçim yaparak bilgilerini güncelleyin.
3. **Not Görüntüleme**: Notları görmek için arayüzdeki kaydırma çubuğunu kullanın.

#### Geliştirme Notları

- **`initUI()`**: Arayüzü başlatan ve bileşenleri yerleştiren fonksiyon.
- **`YazarinNotlariWindow(QDialog)`**: Yazarın notlarını eklemek ve düzenlemek için kullanılan ana diyalog penceresi sınıfı.

#### Fonksiyonlar ve Sınıflar

- **`YazarinNotlariWindow(QDialog)`**: Yazarın notlarını yönetmek için kullanılan ana diyalog penceresi sınıfı.
  - **`initUI()`**: Arayüz bileşenlerini başlatır ve yerleştirir.
  - **`ekleBtn`**: Not eklemek için kullanılan buton.
  - **`notSayisiLabel`**: Eklenen toplam not sayısını gösteren etiket.
  - Diğer UI bileşenleri ve yardımcı fonksiyonlar.

Bu dosya, projenin dokümantasyon ve not yönetimini kolaylaştıran önemli bir parçası olarak hizmet eder ve kullanıcıların yazarın notlarını verimli bir şekilde yönetmesine olanak tanır.


### 5. katkida_bulunan_ekle_window.py

Bu bölüm, `katkida_bulunan_ekle_window.py` dosyasının işlevlerini, içerdiği sınıfları ve fonksiyonları kapsamlı bir şekilde açıklar. Bu dosya, projeye katkıda bulunanları eklemek için kullanılan bir grafiksel kullanıcı arayüzü sağlar.

#### Özellikler 🌟

- **Katkıda Bulunan Ekleme**: Kullanıcılar, projeye katkıda bulunan kişilerin adını ve GitHub bağlantısını ekleyebilir.
- **Kullanıcı Dostu Arayüz**: PyQt5 kullanılarak geliştirilen bu arayüz, kolay ve anlaşılır bir kullanım sunar.
- **JSON Entegrasyonu**: Katkıda bulunan bilgileri, `.json` formatında kaydedilir ve bu dosyadan okunur, bu sayede kolayca güncellenebilir ve yönetilebilir.

#### Kullanımı

Bu arayüzü kullanarak katkıda bulunan bilgilerini yönetmek için aşağıdaki adımları takip edin:

1. **Katkıda Bulunan Ekleme**: 'Ekle' butonuna tıklayarak yeni katkıda bulunan bilgileri ekleyin.
2. **Bilgi Kontrolü**: Girilen bilgilerin doğruluğunu kontrol etmek için ilerleme diyalogu gösterilir.

#### Geliştirme Notları

- **`initUI()`**: Arayüzü başlatan ve bileşenleri yerleştiren fonksiyon.
- **`KatkidaBulunanEkleWindow(QDialog)`**: Katkıda bulunan ekleme işlemini gerçekleştiren ana diyalog penceresi sınıfı.

#### Fonksiyonlar ve Sınıflar

- **`KatkidaBulunanEkleWindow(QDialog)`**: Katkıda bulunan kişileri eklemek için kullanılan ana diyalog penceresi sınıfı.
  - **`initUI()`**: Arayüz bileşenlerini başlatır ve yerleştirir.
  - **`progressDialog`**: Bilgi kontrolü sırasında gösterilen özelleştirilmiş ilerleme diyalogu.
  - **Giriş alanları**: Katkıda bulunanın adı ve GitHub bağlantısı için kullanılan alanlar.
  - **Butonlar ve diğer UI bileşenleri**: Kullanıcı eylemlerini yönetmek için kullanılan butonlar ve diğer bileşenler.

Bu dosya, projenin topluluk yönetimini kolaylaştıran önemli bir parçası olarak hizmet eder ve kullanıcıların projeye katkıda bulunan kişileri verimli bir şekilde yönetmesine olanak tanır.

### 6. repo_kullanimi_window.py

Bu bölüm, `repo_kullanimi_window.py` dosyasının işlevlerini ve nasıl kullanılacağını açıklar. Bu dosya, kullanıcılara repo kullanım talimatlarını eklemek, düzenlemek ve görüntülemek için grafiksel bir arayüz sağlar.

#### Özellikler 🌟

- **Talimat Ekleme ve Düzenleme**: Kullanıcılar, repo kullanımı ile ilgili talimatları ekleyebilir ve mevcut talimatları düzenleyebilir.
- **Kaydırılabilir Alan**: Talimatlar çok uzun olduğunda içeriği rahatça görmek için kaydırılabilir bir alan sunar.
- **JSON Entegrasyonu**: Talimatlar, `.json` formatında kaydedilir ve bu dosyadan okunur, bu sayede kolayca güncellenebilir ve yönetilebilir.

#### Kullanımı

Bu arayüzü kullanarak repo kullanım talimatlarını yönetmek için aşağıdaki adımları takip edin:

1. **Talimat Ekleme**: 'Ekle' butonuna tıklayarak yeni talimatlar ekleyin.
2. **Talimat Düzenleme**: Listeden bir talimat seçin ve 'Düzenle' butonuna tıklayarak mevcut talimatları güncelleyin.
3. **Görüntüleme**: Talimatları görmek için arayüzdeki kaydırma çubuğunu kullanın.

#### Geliştirme Notları

- Arayüz, PyQt5 kütüphanesi kullanılarak geliştirilmiştir.
- JSON dosyası, talimatların kalıcı bir şekilde saklanması için kullanılır.

Bu dosya, projenin daha geniş bir parçası olarak, kullanıcılara daha verimli ve anlaşılır bir repo yönetimi deneyimi sunmayı amaçlamaktadır.
### 7. threadler.py

Bu bölüm, `threadler.py` dosyasının işlevlerini ve nasıl kullanılacağını açıklar. Bu dosya, çeşitli arka plan işlemlerini yönetmek ve uygulamanın yanıt verme kabiliyetini korurken ağır görevleri gerçekleştirmek için thread (iş parçacığı) sınıflarını tanımlar.

#### Özellikler 🌟

- **ScriptRunnerThread**: Çeşitli Python scriptlerini arka planda çalıştırmak için kullanılır. Bu sayede ana kullanıcı arayüzü donmadan işlemler gerçekleştirilebilir.
- **HocaKaydetThread**: Uzun sürebilecek hoca kaydetme işlemleri için ayrı bir thread. İşlem tamamlandığında bir sinyal gönderir.
- **Sinyal Entegrasyonu**: İşlemlerin başarıyla tamamlandığını veya hata ile karşılaşıldığını belirten sinyaller gönderir. Bu sinyaller, kullanıcıya geri bildirim sağlamak için GUI ile entegre edilebilir.

#### Kullanımı

Bu threadler, ağır işlemleri arka planda çalıştırmak ve uygulamanın akıcı bir şekilde çalışmaya devam etmesini sağlamak için kullanılır:

1. **Script Çalıştırma**: `ScriptRunnerThread` nesnesi oluşturarak ve `run` metodunu çağırarak scriptlerinizi arka planda çalıştırabilirsiniz.
2. **Hoca Kaydetme**: `HocaKaydetThread` nesnesi oluşturarak ve `run` metodunu çağırarak hoca bilgilerini kaydetme işlemini arka planda gerçekleştirebilirsiniz.
3. **Sinyalleri Dinleme**: İşlemlerin durumu hakkında kullanıcıya bilgi vermek için threadler tarafından gönderilen sinyalleri dinleyin.

#### Geliştirme Notları

- Threadler, PyQt5'in `QThread` sınıfını kullanarak oluşturulmuştur.
- İşlemler sırasında oluşan hatalar, kullanıcıya geri bildirim sağlamak için sinyaller aracılığıyla iletilir.

Bu dosya, uygulamanın performansını ve kullanıcı deneyimini iyileştirmek için önemli bir rol oynar. Arka planda gerçekleşen işlemler sayesinde, uygulama daha akıcı ve yanıt verir bir hale gelir.

### 8. ders_ekle_guncelle_window.py

Bu bölüm, `ders_ekle_guncelle_window.py` dosyasının işlevlerini, içerdiği sınıfları ve fonksiyonları kapsamlı bir şekilde açıklar. Bu dosya, dersleri eklemek ve güncellemek için kullanılan bir grafiksel kullanıcı arayüzü sağlar.

#### Özellikler 🌟

- **Ders Ekleme/Güncelleme**: Kullanıcılar, ders bilgilerini ekleyebilir ve mevcut ders bilgilerini güncelleyebilir.
- **Kullanıcı Dostu Arayüz**: PyQt5 kullanılarak geliştirilen bu arayüz, kolay ve anlaşılır bir kullanım sunar.
- **JSON Entegrasyonu**: Ders bilgileri, `.json` formatında kaydedilir ve bu dosyadan okunur, bu sayede kolayca güncellenebilir ve yönetilebilir.

#### Kullanımı

Bu arayüzü kullanarak ders bilgilerini yönetmek için aşağıdaki adımları takip edin:

1. **Ders Ekleme**: 'Ders Ekle' butonuna tıklayarak yeni ders bilgileri ekleyin.
2. **Ders Düzenleme**: Mevcut dersler arasından seçim yaparak bilgilerini güncelleyin.

#### Geliştirme Notları

- **`initUI()`**: Arayüzü başlatan ve bileşenleri yerleştiren fonksiyon.
- **`hoca_sirala(hoca)`**: Hocaları sıralamak için kullanılan yardımcı fonksiyon.
- **JSON Yolları**: Ders ve hoca bilgileri için kullanılan JSON dosyalarının yolları tanımlanır.

#### Fonksiyonlar ve Sınıflar

- **`DersEkleGuncelleWindow(QDialog)`**: Ders eklemek ve güncellemek için kullanılan ana diyalog penceresi sınıfı.
  - **`initUI()`**: Arayüz bileşenlerini başlatır ve yerleştirir.
  - **`ekleBtn`**: Ders eklemek için kullanılan buton.
  - Diğer UI bileşenleri ve yardımcı fonksiyonlar.

Bu dosya, projenin eğitim yönetimini kolaylaştıran önemli bir parçası olarak hizmet eder ve kullanıcıların ders bilgilerini verimli bir şekilde yönetmesine olanak tanır.

### 9. hoca_kisaltma_olustur.py

Bu bölüm, `hoca_kisaltma_olustur.py` dosyasının işlevlerini ve nasıl kullanılacağını kapsamlı bir şekilde açıklar. Bu dosya, hoca isimlerinden kısaltmalar oluşturmak için kullanılan bir yardımcı programdır.

#### Özellikler 🌟

- **Kısaltma Oluşturma**: Hoca isimlerinden, unvanlarını ve noktalama işaretlerini çıkararak kısaltmalar oluşturur.
- **Esnek ve Anlaşılır**: Farklı isim ve unvan yapısındaki isimler için uygun kısaltmalar üretir.

#### Kullanımı

Bu fonksiyon, hoca isimlerinden kısaltmalar oluşturmak için kullanılır. İşlevi şu adımları takip eder:

1. **Unvanları Kaldırma**: İsimden unvanları ve noktalama işaretlerini çıkarır.
2. **Kısaltma Oluşturma**: İsimlerin baş harflerini alarak kısaltma oluşturur. Özel durumlar için özel kurallar uygulanabilir.

#### Geliştirme Notları

- **`hoca_kisaltma_olustur(isim)`**: İsimleri kısaltmaya çeviren fonksiyon.
  - **Parametreler**: `isim` - Kısaltması oluşturulacak hoca ismi.
  - **Dönüş**: Oluşturulan kısaltma.

#### Fonksiyonlar ve Kullanımı

- **`hoca_kisaltma_olustur(isim)`**: Belirli kurallara göre hoca isimlerinden kısaltma oluşturur.
  - Örnek kullanım: `hoca_kisaltma_olustur("Prof. Dr. Ahmet Elbir")` sonucunda `"AEL"` döner.

Bu dosya, hoca isimlerini yönetirken ve onlara atıfta bulunurken tutarlılık ve kolaylık sağlamak amacıyla geliştirilmiştir.

## Genel Bakış 🌐

Her bir dosya, belirli görevler için özel arayüzler ve işlevler sağlayarak kullanıcı arayüzüne odaklanır. İmport edilen modüller ve kütüphaneler, bu dosyaların PyQt5 kütüphanesini kullanarak grafiksel kullanıcı arayüzü (GUI) bileşenleri oluşturduğunu göstermektedir.
