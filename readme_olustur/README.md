
# Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği Ders Notları

Bu repository, Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği bölümünde verilen derslerin notları, örnek soruları ve ilgili kaynakları barındırmaktadır. Öğrencilerin dersleri daha etkin bir şekilde öğrenmelerini desteklemek amacıyla hazırlanmıştır.

## Gereksinimleri İndirme 📦

Projeyi başarıyla çalıştırabilmek için aşağıdaki adımları izleyerek gerekli kütüphaneleri ve bağımlılıkları yükleyiniz:

1. **Python 3 Kurulumu:** Projeyi çalıştırmak için Python 3'ün bilgisayarınızda yüklü olması gerekmektedir. Python'ı [buradan](https://www.python.org/downloads/) indirebilirsiniz (linux için `sudo apt install python3`). Kurulum tamamlandıktan sonra terminali açın ve `python3 --version` komutu ile kurulumun başarılı olduğunu doğrulayın. 🐍

2. **Pip3 Kurulumu:** Pip, Python paketlerini yönetmek için kullanılan bir araçtır. Python 3 ile birlikte genellikle otomatik olarak yüklenir. Kurulumunu doğrulamak için terminali açın ve `pip3 --version` komutunu çalıştırın. Eğer kurulu değilse, [Pip'in resmi belgelerini](https://pip.pypa.io/en/stable/installing/) takip ederek kurulum yapabilirsiniz.(linux için `sudo apt install python3-pip`) 🛠️

3. **Gerekli Kütüphanelerin Yüklenmesi:** Projede kullanılan kütüphaneleri yüklemek için, terminalinize `pip3 install -r gereksinimler.txt` komutunu girin. Bu komut, `gereksinimler.txt` dosyasında listelenen tüm paketleri yükleyecektir. 📚
## Nasıl Kullanılır

Proje dosyaları arasında, hocalar, dersler, dönemler ve diğer bilgileri içeren JSON formatında çeşitli dosyalar bulunmaktadır. Bu dosyalar, projenin çeşitli yerlerinde kullanılarak dinamik bir içerik oluşturur.

Örneğin:
- `hocalar.json` hoca bilgilerini içerir ve README'leri oluşturmakta kullanılır.
- `dersler.json` ders bilgilerini tutar.
- `donemler.json` dönem bilgilerini tutar.
- `giris.json` README dosyasının giriş bilgilerini içerir.

Bu dosyalarla birlikte, her dersin ve her dönemin klasöründe README dosyaları oluşturulur.

### Projeyi Çalıştırmak

Projeyi çalıştırmak için aşağıdaki adımı izleyin:

```bash
python3 readme_olustur.py
```
Eğer rutin şekilde google form girdilerinin dinlenip güncelleme işlemi yapılmasını istiyorsanız
Linux için
```bash
./rutin_kontrol.sh
```
Windows için `rutin_kontrol.bat`
komutlarını kullanabilirsiniz.

Bu komut, projenin kök klasöründeki tüm ilgili dosyaları okuyacak ve gerekli README dosyalarını oluşturacaktır.
