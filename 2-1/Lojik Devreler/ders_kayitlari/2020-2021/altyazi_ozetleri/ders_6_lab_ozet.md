# Ders 6 Lab Çalışma Özeti

## Genel Konular

- Karnaugh haritası ile sadeleştirme uygulaması
  - Fonksiyonun `1` olduğu hücreler haritaya yerleştirilir.
  - Komşu hücreler en büyük gruplar halinde seçilir.
- Kapı düzeyinde devre kurulumu
  - Sadeleşmiş ifade seçilen kapı türüne göre dönüştürülür.
  - NOT gereksinimleri kapı girişleri birleştirilerek veya ayrı tümleyen kapısıyla sağlanır.
- Simülasyon tabanlı kontrol
  - Devre çıkışları doğruluk tablosundaki beklenen değerlerle karşılaştırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Karnaugh haritasında amaç bütün `1`leri kapsamak ve gereksiz grup oluşturmamaktır.
- Büyük gruplar daha fazla değişkenin elenmesini sağlar.
- Devre doğrulaması için yalnızca çizim değil, giriş kombinasyonları üzerinden test gerekir.

## Kısa Tekrar Notları

- Haritadaki komşuluk Gray kod sırasına göre belirlenir.
- Grup boyutları 1, 2, 4, 8 gibi ikinin kuvvetleri olmalıdır.
- Her grup bir sade terim üretir.
- Sade ifade simülasyonda doğrulanmalıdır.

## Detaylı Açıklamalar

- Laboratuvar çalışmasında teorik sadeleştirme pratiğe aktarılır. Minterm değerleri Karnaugh haritasına yerleştirilir ve fonksiyonun en sade hali bulunur.
- Sadeleşmiş ifade doğrudan standart AND-OR kapılarıyla kurulabileceği gibi NAND veya NOR gibi tek tip kapılarla da kurulabilir. Bu durumda De Morgan dönüşümleri devre gerçekleme aşamasında kullanılır.
- Simülasyonda tüm giriş kombinasyonlarının denenmesi, hem Karnaugh sadeleştirmesinin hem de devre bağlantılarının doğru olduğunu gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
