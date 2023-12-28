
# YTU Hocalar-Dersler Puanlama Sistemi 📊

Bu proje, Yıldız Teknik Üniversitesi'ndeki hocaları puanlamak ve bu puanları yönetmek için kullanılan bir dizi script içermektedir.

## Gereksinimleri İndirme 📦

Projeyi başarıyla çalıştırabilmek için aşağıdaki adımları izleyerek gerekli kütüphaneleri ve bağımlılıkları yükleyiniz:

1. **Python 3 Kurulumu:** Projeyi çalıştırmak için Python 3'ün bilgisayarınızda yüklü olması gerekmektedir. Python'ı [buradan](https://www.python.org/downloads/) indirebilirsiniz (linux için `sudo apt install python3`). Kurulum tamamlandıktan sonra terminali açın ve `python3 --version` komutu ile kurulumun başarılı olduğunu doğrulayın. 🐍

2. **Pip3 Kurulumu:** Pip, Python paketlerini yönetmek için kullanılan bir araçtır. Python 3 ile birlikte genellikle otomatik olarak yüklenir. Kurulumunu doğrulamak için terminali açın ve `pip3 --version` komutunu çalıştırın. Eğer kurulu değilse, [Pip'in resmi belgelerini](https://pip.pypa.io/en/stable/installing/) takip ederek kurulum yapabilirsiniz.(linux için `sudo apt install python3-pip`) 🛠️

3. **Gerekli Kütüphanelerin Yüklenmesi:** Projede kullanılan kütüphaneleri yüklemek için, terminalinize `pip3 install -r ../gereksinimler.txt` komutunu girin. Bu komut, `gereksinimler.txt` dosyasında listelenen tüm paketleri yükleyecektir. 📚

## Dosyalar 📂

### `hoca_adlari_olustur.py`

- **Amaç:** Bu script, `hocalar.json` dosyasında bulunan hoca adlarını çeker ve bu adları Google Formlar'da kullanılmak üzere bir CSV dosyasına kaydeder. 📝
- **Nasıl Çalışır:** `hocalar.json` dosyasını okur, hocaların adlarını alır ve bu adları `hocalar.csv` adlı bir dosyaya kaydeder. 🔍
- **Kullanımı:** `python3 hoca_adlari_olustur.py` komutuyla çalıştırılır. Scripti çalıştırmak için, `hocalar.json` dosyasının aynı dizinde bulunması gerekmektedir. 🚀

### `hoca_icerikleri_guncelle.py`

- **Amaç:** Bu script, Google Formlar'dan alınan hoca puanlama sonuçlarına göre `hocalar.json` dosyasındaki hocaların yıldızlarını (puanlarını) günceller. ⭐
- **Nasıl Çalışır:** Google Formlar'dan alınan verileri işler ve hocaların yeni ortalamalarını hesaplar. Ardından, bu yeni ortalamaları `hocalar.json` dosyasında ilgili hocaların kayıtlarını güncelleyerek yansıtır. 📊
- **Kullanımı:** `python3 hoca_icerikleri_guncelle.py` ile çalıştırılır. Scripti çalıştırmak için, Google Formlar'dan alınan verilerin bir CSV dosyası olarak erişilebilir olması ve `hocalar.json` dosyasının script ile aynı dizinde bulunması gerekmektedir. 🔄

### `ders_adlari_olustur.py`

- **Amaç:** Bu script, `dersler.json` dosyasında bulunan ders adlarını çeker ve bu adları Google Formlar'da kullanılmak üzere bir CSV dosyasına kaydeder. 📋
- **Nasıl Çalışır:** `dersler.json` dosyasını okur, derslerin adlarını alır ve bu adları `dersler.csv` adlı bir dosyaya kaydeder. 🔎
- **Kullanımı:** `python3 ders_adlari_olustur.py` komutuyla çalıştırılır. Scripti çalıştırmak için, `dersler.json` dosyasının aynı dizinde bulunması gerekmektedir. 🚀

### `ders_icerikleri_guncelle.py`

- **Amaç:** Bu script, Google Formlar'dan alınan ders puanlama sonuçlarına göre `dersler.json` dosyasındaki derslerin yıldızlarını (puanlarını) günceller. ⭐
- **Nasıl Çalışır:** Google Formlar'dan alınan verileri işler ve derslerin yeni ortalamalarını hesaplar. Ardından, bu yeni ortalamaları `dersler.json` dosyasında ilgili derslerin kayıtlarını güncelleyerek yansıtır. 📊
- **Kullanımı:** `python3 ders_icerikleri_guncelle.py` ile çalıştırılır. Scripti çalıştırmak için, Google Formlar'dan alınan verilerin bir CSV dosyası olarak erişilebilir olması ve `dersler.json` dosyasının script ile aynı dizinde bulunması gerekmektedir. 🔄