# Altyazıdan Çalışma Özeti Çıkarma ve Altyazı README'si Oluşturma Talimatı

Aşağıdaki talimat; ders kaydı altyazılarından zaman bağımsız çalışma özetleri çıkarmak ve altyazıların bulunduğu klasöre standart bir `README.md` belgesi eklemek amacıyla kullanılabilir.

## Talimat

Sana bir dersin altyazı (.srt) dosyaları ve bu dosyaların bulunduğu klasör verilecek. Senden istenenler:
1. Her bir altyazı dosyasından öğrencinin daha sonra çalışırken kullanabileceği düzenli ve anlaşılır bir ders özeti çıkar. Oluşturulan özetleri `altyazilar/` diziniyle aynı seviyede olan `altyazi_ozetleri/` klasörüne kaydet.
2. Altyazı dosyalarının bulunduğu klasöre (`altyazilar/` dizini altına) aşağıdaki formatta bir `README.md` belgesi oluştur veya mevcutsa güncelle.

### 1. Çalışma Özeti Çıkarma Kuralları

Özeti hazırlarken aşağıdaki kurallara uy:
- Sadece derste işlenen **akademik/teorik içerikleri** dikkate al.
- Ödev, sınav, yoklama, dersin ne zaman yapılacağı, sonraki hafta ne işleneceği, teknik aksaklıklar, kayıt bilgisi, Zoom/toplantı organizasyonu, değerlendirme takvimi, notlandırma, laboratuvar organizasyonu ve benzeri zaman bağımlı veya organizasyonel bilgileri **hiçbir şekilde çıkarma**.
- Altyazıda geçen ifadeleri doğrudan kopyalamak yerine anlamı koruyarak temiz ve anlaşılır bir dille yeniden yaz.
- Konular arasında mantıklı sıra kur.
- Derece ve ayrıntı seviyesini yüksek tutarak, her ana konuyu ve önemli vurguyu açıklayıcı alt maddelerle (iç içe listeler şeklinde) zenginleştir.
- Gereksiz tekrarları temizle.
- Emin olmadığın veya altyazıda net olmayan kısımları kesin bilgi gibi yazma.
- Çıktı Türkçe olmalı.

#### Özet Çıktı Formatı

```md
# Ders Çalışma Özeti

## Genel Konular

- Derste ele alınan birinci ana konu başlığı
  - Bu konunun içeriği, ne anlama geldiği ve derste anlatılan temel açıklamaları.
- Derste ele alınan ikinci ana konu başlığı
  - Bu konunun temel mantığı, çalışma şekli ve önemli teknik detayları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hocanın üzerinde durduğu birinci önemli kavram/uyarı/tanım
  - Bu kavramın veya uyarının neden kritik olduğu ve hoca tarafından yapılan açıklaması.
- Hocanın üzerinde durduğu ikinci önemli nokta
  - Bu noktanın sınav veya uygulamalı çalışmalar için neden önem arz ettiği.

## Kısa Tekrar Notları

- Dersten sonra hızlı tekrar yapmak için en önemli noktaları kısa maddeler halinde yaz.
- Bu bölümde de zaman bağımlı bilgi kullanma.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

- Dersteki konuları, kavramları ve varsa kod/devre örneklerini daha uzun ve detaylı paragraflar halinde açıkla.
- Bu kısım konuyu daha derinlemesine anlamak veya kaçırılan dersi telafi etmek isteyenler için kapsamlı bilgi içermelidir.
```

### 2. Altyazı Klasörü README.md Kuralları

Altyazıların bulunduğu klasörün içindeki `README.md` dosyasını oluştururken/güncellerken şu kurallara uy:
- **Hoca Bilgisi:** README belgesine dersi veren hoca bilgisini ekle. Eğer dersi veren hoca adını bilmiyorsan, bunu tahmin etmeye çalışma; **kesinlikle kullanıcıya hoca adını sor** ve aldığın cevaba göre ekle.
- **İlk Ders Başlangıç Tarihi:** README belgesine dersin ilk başlangıç tarihini ekle. Eğer ilk dersin başlangıç tarihi kullanıcı tarafından verilmemişse veya mevcut dosyalardan kesin olarak anlaşılamıyorsa, bunu tahmin etmeye çalışma; **kesinlikle kullanıcıya ilk dersin başlangıç tarihini sor** ve aldığın cevaba göre ekle.
- **Hafta Bilgisi ve Eksik Kayıtlar:** Klasördeki `.srt` dosyalarını analiz ederek haftalık listeyi ve varsa eksik haftaları listele.
- **Format Şablonu:** Aşağıdaki yapıyı birebir referans al:

```md
# [Ders Adı] Ders Kayıtları Altyazıları

Bu klasör, [Dönem] eğitim öğretim yılı [Dönem] dönemindeki [Ders Adı] ders kayıtlarının altyazılarını içerir.

* **Dersi Veren Akademisyen:** [Hoca Adı]

Dersler [İlk Ders Tarihi] günü başlamıştır. Dosya adlarındaki `ders_x.srt` ifadesinde `x`, ilgili kaydın ders haftasını gösterir.

## Hafta Bilgisi

- `ders_1.srt`: [Tarih]
- `ders_2.srt`: [Tarih]
...

## Eksik Kayıtlar

- [Eksik Hafta No]. hafta [Sebep] nedeniyle kayıt bulunmamaktadır.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
```

### 3. Ana Kaynak Listesine (dersler.json) Göreli Yol Ekleme Kuralları

- Dersin altyazı çalışma özetlerine ve ders kayıtlarına kolayca ulaşılabilmesi için, projenin kök dizinindeki `readme_olustur/dersler.json` dosyası güncellenmelidir.
- İlgili dersin `faydali_olabilecek_kaynaklar` dizisi içerisine, dersin kendi ana dizininden (kökteki ders klasöründen) `ders_kayitlari/` dizinine işaret eden göreli bir yol (relative path) eklenmelidir.
- **Güncel Ders Kontrolü:** Eğer altyazı klasörü kök ders klasörünün altındaki eski/pasif bir ders dizininde bulunuyorsa, kaynak bağlantısını eski/pasif dersin `faydali_olabilecek_kaynaklar` alanına ekleme. Örneğin yapı `dönem/güncel_ders/eskimis_ders/ders_kayitlari/...` biçimindeyse, bağlantı `readme_olustur/dersler.json` içinde `eskimis_ders` kaydına değil kökteki `güncel_ders` kaydına eklenmelidir.
- Bu durumda göreli yol da güncel ders klasöründen hedef kayıt dizinine gidecek şekilde yazılmalıdır; örnek biçim: `./eskimis_ders/ders_kayitlari/`.
- Örnekler:
  - Yapay Zeka için: `"**Ders Kayıtları:** [Yapay Zeka Ders Kayıtları Altyazıları](./ders_kayitlari/)"`
  - Mikroişlemci Sistemleri ve Assembly Dili için: `"**Ders Kayıtları:** [Alt Seviye Programlama Ders Kayıtları Altyazıları](./alt%20seviye%20programlama/ders_kayitlari/)"`
  - Güncel ders altındaki eski/pasif ders kayıtları için: `"**Ders Kayıtları:** [Eski Ders Ders Kayıtları Altyazıları](./eskimis_ders/ders_kayitlari/)"`

### 4. Commit Atma Kuralları

- Tüm özetler, `README.md` dosyaları, `dersler.json` güncellemesi ve gerekiyorsa `readme_olustur.py` çıktıları tamamlandıktan sonra `git status` ile değişiklikleri kontrol et.
- Sadece bu işlemle ilgili dosyaları stage et; kullanıcının başka değişikliklerini commit'e dahil etme.
- Standart commit mesajı olarak şu kalıbı kullan:

```bash
git commit -m "özellik: [ders adı] altyazı özetleri eklendi"
```

## Kullanım

Aşağıdaki şablonu doldurarak asistan modele iletin:

```text
Hedef Altyazı Klasörü: [Buraya klasör yolu gelecek, örn: .../3-2/Yapay Zeka/ders_kayitlari/2022-2023/altyazilar]
İlk Ders Başlangıç Tarihi: [Biliyorsanız yazın; verilmezse asistan sormalıdır]
```
