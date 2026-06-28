# Ders 1 Çalışma Özeti

## Genel Konular

- Bilişim sistemleri güvenliğinin temel problemi
  - Yazılım hataları, sosyal mühendislik ve saldırı ekonomisi güvenlik risklerinin ana kaynakları olarak ele alınır.
  - Her hata aynı düzeyde risk üretmez; uygulamanın kontrol akışını değiştirmeye veya yetkisiz kod çalıştırmaya izin veren hatalar zafiyet niteliği kazanır.
- Güncel zafiyet ekosistemi
  - İşletim sistemleri, tarayıcılar, mobil platformlar, ofis yazılımları, PDF okuyucuları ve eklenti teknolojileri yaygın kullanım nedeniyle yüksek saldırı yüzeyine sahiptir.
  - Zafiyetlerin sayısı kadar yaygın kurulum tabanı da önemlidir; çok kullanılan ürünlerdeki tek bir açık çok geniş etki alanı oluşturabilir.
- Sosyal mühendislik
  - E-posta, SMS, sosyal medya veya bağlantı üzerinden gelen yönlendirmeler kullanıcıyı kimlik bilgisi paylaşmaya veya zararlı yazılım çalıştırmaya ikna edebilir.
  - Teknik güvenlik mekanizmaları kullanıcı davranışındaki zayıflıklarla aşılabilir.
- Saldırı ekonomisi
  - Zafiyet bulma, ele geçirilmiş makine kiralama, zararlı yazılım yükletme, veri çalma ve fidye yazılımı faaliyetleri ekonomik değer üretir.
  - Kripto para benzeri ödeme araçları saldırı pazarlarını kolaylaştırabilir.
- Zoom örneği üzerinden yerel servis zafiyeti
  - Tarayıcı ile yerel uygulama arasındaki bağlantıda yerel web sunucusu kullanılması saldırı yüzeyi oluşturabilir.
  - Herhangi bir web sitesinin yerel servise istek gönderebilmesi, kullanıcı bilgisi dışında toplantıya katılma veya istemciyi başlatma gibi davranışlara yol açabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kriptografi kütüphanesi kullanmak tek başına güvenlik anlamına gelmez
  - Şifreleme doğru protokol, doğru anahtar yönetimi ve doğru kullanım modeliyle anlamlıdır.
- Zafiyet değerlendirmesinde etki belirleyicidir
  - Basit hata ile kontrol akışını ele geçirmeye izin veren hata aynı kategoride düşünülmemelidir.
- Yaygınlık riski büyütür
  - Tarayıcı, Android, Office, PDF ve toplantı yazılımları çok kullanıldığı için saldırgan açısından cazip hedeflerdir.
- Güvenlik haberleri hem risk hem iyileştirme kaynağıdır
  - Ortaya çıkan zafiyetler mağduriyet üretir; fakat aynı zamanda ürünlerin daha sağlam hale getirilmesini sağlar.

## Kısa Tekrar Notları

- Güvenlik problemlerinin ana nedenleri: hata, insan faktörü, ekonomik motivasyon.
- Zafiyet, uygulamayı tasarlanan davranışının dışına çıkarabilen hatadır.
- Sosyal mühendislik teknik önlemleri bypass edebilir.
- Yerel servisler ve tarayıcı-uygulama entegrasyonları saldırı yüzeyi oluşturur.
- Şifreleme doğru kullanılmazsa mahremiyet garantisi vermez.

## Detaylı Açıklamalar

- Bilişim sistemleri güvenliğinde temel varsayım, karmaşık yazılımların hata içereceğidir. Hatalar algoritma seçiminden, kullanılan kütüphanelerden, sistem mimarisinden veya bileşenler arası etkileşimden kaynaklanabilir. Güvenlik açısından kritik olan, hatanın uygulamanın normal kontrol akışını değiştirip değiştirmediğidir.
- Sosyal mühendislik, teknik zafiyet kadar güçlü bir saldırı aracıdır. Kullanıcının o anda ilgilendiği konuyla uyumlu görünen bir mesaj, bağlantı veya form, kimlik ve banka bilgisi gibi hassas verilerin paylaşılmasına ya da zararlı kodun kurulmasına yol açabilir.
- Saldırıların arkasında ekonomik motivasyon bulunur. Ele geçirilmiş sistemler kiralanabilir, hedef makinelerde belirli kodların yüklenmesi için ödeme alınabilir, hassas veriler satılabilir veya veriler şifrelenerek fidye istenebilir.
- Zoom benzeri uygulamalarda tarayıcının yerel istemciyi başlatması kullanım kolaylığı sağlar; ancak yerel web sunucusu gibi ara mekanizmalar doğru sınırlandırılmazsa başka web siteleri bu mekanizmaya istek gönderebilir. Bu durum güvenlik tasarımında otomasyon ile yetki kontrolünün birlikte düşünülmesi gerektiğini gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
