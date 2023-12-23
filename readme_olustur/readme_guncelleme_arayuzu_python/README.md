# Proje Dokümantasyonu

Bu README dosyası, projenin ana bileşenlerini ve her bir Python dosyasının işlevlerini açıklar.

## Nasıl Çalıştırılır

Bu bölümde, projeyi yerel makinenizde nasıl çalıştırabileceğinize dair adımlar anlatılmaktadır.

### Python 3 Kurulumu

1. Python'un en son sürümünü [Python'un resmi web sitesinden](https://www.python.org/downloads/) indirin.
2. İndirilen yükleyiciyi çalıştırın.
3. Kurulum sırasında "Add Python 3.x to PATH" seçeneğini işaretleyin.
4. Kurulumu tamamlayın.

### pip3 Kurulumu

pip, Python için paket yöneticisidir ve genellikle Python ile birlikte gelir.

- Python'ı yükledikten sonra, komut istemcisinde `python -m ensurepip --upgrade` komutunu çalıştırarak pip'in en son sürümünün yüklü olduğundan emin olun.

### Gerekli Kütüphanelerin Kurulumu

Projede kullanılan PyQt5 ve diğer kütüphaneleri yüklemek için aşağıdaki komutları kullanın:


pip3 install PyQt5
# Diğer gerekli kütüphaneler varsa, aşağıdaki gibi yükleyin:
pip3 install requests
pip3 install json5
# ... ve diğer gerekli kütüphaneler ...


### Projeyi çalıştırmak
python3 main.py

### Ne işe yarar
Readme oluşturmak için kullanılan json dosyalarına veri ekler sielr ve veri günceller

## Dosyalar ve İşlevleri

### 1. hoca_ekle_guncelle_window.py
- **Amaç**: Hocaları eklemek ve güncellemek için bir arayüz sağlar.
- **Sınıflar**:
  - `HocaEkleGuncelleWindow(QDialog)`: Hocaları eklemek ve güncellemek için kullanılan diyalog penceresi.
  - `HocaDuzenlemeWindow(QDialog)`: Seçilen hocayı düzenlemek için kullanılan diyalog penceresi.
- **Fonksiyonlar**:
  - İçerik yükleme, arayüz kurulumu, hocaları listeleme, ekleme ve düzenleme gibi işlemleri içeren fonksiyonlar.
- **İmportlar**: PyQt5, sys, json.

### 2. main.py
- **Amaç**: Uygulamanın ana giriş noktası, diğer pencereleri açma ve yönetme.
- **Sınıflar**:
  - `App(QWidget)`: Ana uygulama penceresi.
- **Fonksiyonlar**:
  - Arayüz kurulumu, diğer pencereleri açma fonksiyonları.
- **İmportlar**: PyQt5, sys, os, diğer modül pencereleri.

### 3. katkida_bulunanlari_duzenle_window.py
- **Amaç**: Katkıda bulunanları düzenlemek için kullanılan arayüz.
- **Sınıflar**:
  - `KatkidaBulunanGuncelleWindow(QDialog)`: Katkıda bulunanları güncellemek için diyalog penceresi.
  - `KatkidaBulunanDuzenleWindow(QDialog)`: Seçilen katkıda bulunanı düzenlemek için diyalog penceresi.
- **Fonksiyonlar**:
  - Katkıda bulunanları listeleme, ekleme ve düzenleme fonksiyonları.
- **İmportlar**: PyQt5, json, requests.

### 4. yazarin_notlari_duzenle_window.py
- **Amaç**: Yazarın notlarını düzenlemek için kullanılan arayüz.
- **Sınıflar**:
  - `YazarinNotlariWindow(QDialog)`: Notları listelemek ve yönetmek için diyalog penceresi.
  - `NotDuzenleWindow(QDialog)`: Seçilen notu düzenlemek için diyalog penceresi.
- **Fonksiyonlar**:
  - Notları yükleme, yenileme, ekleme ve düzenleme fonksiyonları.
- **İmportlar**: PyQt5, sys, json.

### 5. katkida_bulunan_ekle_window.py
- **Amaç**: Yeni katkıda bulunanları eklemek için kullanılan arayüz.
- **Sınıflar**:
  - `KatkidaBulunanEkleWindow(QDialog)`: Katkıda bulunan ekleme diyalog penceresi.
- **Fonksiyonlar**:
  - Arayüz kurulumu ve katkıda bulunan ekleme fonksiyonları.
- **İmportlar**: PyQt5, sys, json, requests.

## Genel Bakış

Her bir dosya, belirli görevler için özel arayüzler ve işlevler sağlayarak kullanıcı arayüzüne odaklanır. İmport edilen modüller ve kütüphaneler, bu dosyaların PyQt5 kütüphanesini kullanarak grafiksel kullanıcı arayüzü (GUI) bileşenleri oluşturduğunu göstermektedir.
