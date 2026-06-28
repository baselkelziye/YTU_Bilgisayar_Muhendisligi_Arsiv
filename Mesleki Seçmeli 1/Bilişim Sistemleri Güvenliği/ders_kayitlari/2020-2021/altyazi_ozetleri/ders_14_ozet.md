# Ders 14 Çalışma Özeti

## Genel Konular

- Sertifika ve açık anahtar altyapısı
  - Kod parçalarının ve sunucuların dijital sertifikalarla doğrulanması güvenli çalıştırma ve güvenli haberleşme açısından ele alınır.
  - Açık anahtar, gizli anahtar ve sertifika ilişkisi açıklanır.
- Anahtar saklama problemi
  - Şifreleme güvenliği yalnız algoritmaya değil, anahtarın güvenli saklanmasına bağlıdır.
  - Web sunucusu HTTPS anahtarı, disk şifreleme anahtarı veya bellek şifreleme anahtarı açıkta tutulursa güvenlik zayıflar.
- Donanım destekli güvenlik
  - Anahtarların donanım içinde saklanması ve kriptografik işlemlerin donanım tarafından yapılması gizli anahtarın dışarı çıkmasını önleyebilir.
  - TPM/HSM benzeri mantıkla veri donanıma verilir, şifreleme/deşifreleme sonucu alınır.
- Hash ve özet değerleri
  - Verinin bütünlüğünü kontrol etmek ve içerik karşılaştırmak için hash değerleri kullanılır.
  - Güvenli hash fonksiyonlarında küçük değişiklik büyük özet farkı üretmelidir.
- Public key kriptografi uygulamaları
  - Sertifika doğrulama, güvenli kanal kurma, kod imzalama ve kimlik doğrulama açık anahtar kriptografisine dayanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Anahtar güvenliği kriptografinin merkezidir
  - Algoritma güçlü olsa bile anahtar sızarsa güvenlik kaybolur.
- Sertifika güven zinciri gerektirir
  - Bir sertifikaya güvenmek için sertifikanın doğrulanabilir bir otorite zinciriyle ilişkilendirilmesi gerekir.
- Donanım anahtarı dışarı vermeden işlem yapabilir
  - Bu yaklaşım gizli anahtarın yazılım tarafından okunmasını engeller.

## Kısa Tekrar Notları

- Public key açık anahtardır; secret/private key gizli tutulur.
- Sertifika açık anahtarı kimlikle bağlar.
- Hash veri özeti üretir.
- Anahtar saklama en kritik kriptografik problemlerden biridir.
- Donanım destekli modüller anahtar korumayı güçlendirir.

## Detaylı Açıklamalar

- Dijital sertifikalar, bir açık anahtarın belirli bir kimliğe ait olduğunu doğrulamak için kullanılır. HTTPS sunucuları sertifika göndererek istemcinin doğru sunucuyla konuştuğunu kanıtlamaya çalışır. Kod imzalama da benzer biçimde çalıştırılan kodun güvenilir kaynak tarafından üretildiğini doğrulamayı hedefler.
- Şifreleme sistemlerinde anahtarın saklanması algoritma kadar önemlidir. Anahtar yazılım belleğinde açık biçimde bulunuyorsa bellek sızıntısı, debug, zararlı yazılım veya yan kanal saldırılarıyla ele geçirilebilir. Bu nedenle anahtarın donanım içinde tutulduğu ve dışarı çıkarılmadığı tasarımlar tercih edilebilir.
- Hash fonksiyonları, verinin kısa ve sabit uzunlukta özetini üretir. Bütünlük kontrolü, dosya karşılaştırma, parola saklama ve imza süreçlerinde temel bileşendir. Güvenli hash fonksiyonlarının çakışmaya dayanıklı ve tersine çevrilmesi pratikte imkansız olması beklenir.
- Açık anahtar kriptografisinde public key paylaşılabilir, private/secret key ise korunur. Sertifika altyapısı, bu anahtarların kimliklerle güvenilir biçimde eşlenmesini sağlar. TLS ve kod imzalama gibi pratik sistemler bu modele dayanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
