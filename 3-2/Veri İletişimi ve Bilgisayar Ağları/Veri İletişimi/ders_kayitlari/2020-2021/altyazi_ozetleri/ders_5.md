# Ders 5 Çalışma Özeti

## Genel Konular

- Data link protokolleri
  - Veri bağı katmanında framing, hata kontrolü, akış kontrolü ve bağlantı düzenini protokol kuralları belirler.
- HDLC yaklaşımı
  - HDLC, veri bağı katmanı için bit yönelimli bir protokol olarak ele alınır.
  - Frame yapısında flag, address, control, information ve FCS alanları bulunur.
- Flag ve frame sınırları
  - Flag alanı frame'in başlangıç ve bitişini gösterir.
  - Veri içinde flag'e benzeyen bit dizileri oluşursa alıcının frame sınırlarını karıştırmaması gerekir.
- Bit stuffing ve byte stuffing
  - Bit stuffing, özel flag dizisinin veri içinde yanlış algılanmasını önlemek için araya bit ekler.
  - Byte/character stuffing, özel karakterlerin veri olarak mı kontrol karakteri olarak mı yorumlanacağını ayırmaya çalışır.
- Primary ve secondary istasyonlar
  - Primary taraf bağlantıyı yöneten, secondary taraf ise yönetilen taraf olarak düşünülebilir.
  - Bu ayrım protokolün komut/cevap düzenini belirler.
- HDLC frame türleri
  - I-frame veri taşır.
  - S-frame denetim ve akış/hata kontrolü için kullanılır.
  - U-frame bağlantı kurma, sonlandırma ve yönetim amaçlıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Frame sınırları güvenilir belirlenmelidir.
  - Alıcı başlangıç ve bitişi yanlış algılarsa bütün veri yanlış yorumlanabilir.
- Stuffing mekanizmaları ezberden çok mantıkla anlaşılmalıdır.
  - Özel diziler veri içinde geçince protokol bunları kaçış mantığıyla ayırt eder.
- HDLC frame türleri farklı görevler taşır.
  - Veri göndermek, onaylamak ve bağlantıyı yönetmek aynı frame tipiyle yapılmaz.

## Kısa Tekrar Notları

- HDLC bit yönelimli bir veri bağı protokolüdür.
- Flag, frame sınırını gösterir.
- Bit stuffing özel bit dizilerinin karışmasını önler.
- I-frame veri; S-frame kontrol; U-frame yönetim taşır.
- Primary/secondary ayrımı iletişim düzenini belirler.

## Detaylı Açıklamalar

Bu derste veri bağı katmanı protokollerinin nasıl somutlaştığı HDLC üzerinden açıklanmıştır. HDLC frame yapısı, verinin sadece içerik olarak değil, kontrol ve hata denetimi bilgileriyle birlikte taşındığını gösterir. Frame başlangıcı ve bitişi flag alanıyla belirtilir; bu sayede alıcı gelen bit akışını frame'lere ayırabilir.

Özel flag dizilerinin veri alanında geçmesi durumunda karışıklık oluşabilir. Bit stuffing bu problemi çözmek için veri akışına fazladan bit ekler; alıcı bu eklenen biti çıkararak özgün veriyi elde eder. Karakter yönelimli yapılarda benzer amaçla escape karakterleri kullanılabilir.

HDLC'de I, S ve U frame ayrımı protokolün işleyişini düzenler. I-frame esas veri yükünü taşır. S-frame alındı bildirimi, akış kontrolü ve hata durumları için kullanılır. U-frame ise bağlantının kurulması, sonlandırılması ve genel yönetim işlemleri için devrededir.
