# Ders 1 Çalışma Özeti

## Genel Konular

- Bu ders bir tanışma dersidir. Yapısal programlama konularına geçilmez. Dersin müfredat içindeki yeri ve dersten nasıl verim alınacağı konuşulur.
- Dersin yeri
  - Yapısal Programlamaya Giriş (BLM1012), birinci dönemdeki Bilgisayar Bilimlerine Giriş (BLM1011) dersinin devamıdır. Dersin eski adı "Bilgisayar Bilimlerine Giriş 2" idi.
  - BLM1011'de bilgisayar sisteminin bileşenleri, akış diyagramları, algoritmalar ve C programlamaya giriş görülmüştü. Bu derste o altyapı alınarak daha iyi algoritmaların nasıl geliştirileceği, programlamayla desteklenerek işlenir.
  - Ders, ikinci yılın derslerine temel oluşturur: Yapısal Programlama, Alt Seviye Programlama, Ayrık Matematik, Sinyaller ve Sistemler. Ardından Nesneye Yönelik Programlama, Veri Yapıları ve Algoritmalar, Algoritma Analizi, İşletim Sistemleri, Veritabanı Yönetimi gibi derslerde bu derste öğrenilen C ve algoritma bilgisi doğrudan kullanılır.
  - Dersin bir ön koşulu yoktur. BLM1011'i almamış olanlar da algoritma ve programlamaya bu dersle başlayabilir.
- Algoritma öğrenmek nasıl bir süreçtir?
  - Algoritma bu mesleğin temelidir. Algoritma geliştirmenin bir algoritması yoktur. Bu yüzden "artık oldum" denebilecek bir nokta yoktur. Sürekli yeni problemler çözerek gelişmek gerekir.
  - Hoca bunu yabancı dil öğrenmeye benzetir: dil bilgisini öğrenmek okumak, yazmak ve konuşmak için yetmez. Kelime ve pratik arttıkça ortalamanın üzerine çıkılır.
  - Üniversitenin amacı belirli bir problemin veya belirli bir dilin nasıl çözüleceğini değil, mesleğin mantığını öğretmektir. Hoca hukuk eğitimini örnek verir: kanun maddeleri ezberletilirse kanun değişince bilgi eskir, kanunun mantığı öğretilirse insan kendini güncelleyebilir.
- Programlama ortamı
  - C kodu yazmak için CodeBlocks veya Dev-C++ önerilir. Bunlar derleyici (compiler) değil, geliştirme ortamıdır (IDE). İçlerinde standartlara uygun C derleyicileri bulunur.
  - Visual Studio, Xcode gibi ortamlar kullanılabilir, ama derste anlatılan C standardına dikkat edilmelidir. Derleyicilerin standartları farklı olabilir. C ile C++ sık karıştırılır.
- Kaynaklar
  - Ders sayfasında önerilen kitap bir algoritmalara giriş kitabıdır ve algoritma analizine kadar konuları içerir. MIT'nin "Introduction to Algorithms" ders notları buna uyumludur. Algoritmaları sözde kod (pseudocode) üzerinden anlatır.
  - Hoca, temel C konularının (if, for, fonksiyon, pointer) derste anlatıldığını, bunun için ayrı bir kitap veya kursa gerek olmadığını söyler. Kitap okumak isteyenlere yabancı kaynakları (ör. "Problem Solving and Program Design in C") önerir.
  - Coursera, edX gibi platformlardaki dersler de takip edilebilir. Farklı kaynaklardan ve farklı hocalardan öğrenmek bakış açısını zenginleştirir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu ders ezberlenecek değil, anlaşılacak ve pratik yapılacak bir derstir. Dersten başarısız olanların çoğu derse aktif katılmayanlardır.
- Ders saatleri dışında haftada 2-3 saat C ile kod yazılmalıdır.
- Hocanın paylaştığı kodları kopyalamak yerine kendiniz yazın. Hoca kodları bu yüzden ekran görüntüsü olarak paylaşır: noktalı virgülün nerede kullanıldığını, `printf`'in ve `scanf`'in nasıl çalıştığını ancak yazarak öğrenirsiniz.
- Bilmediğiniz bir şeyi sormaktan çekinmeyin. Hocanın sorularına cevap vermek, "bilmiyorum" demek de dahil, dersin etkileşimli olmasını sağlar.
- Her bilgiyi birinci elden öğrenin. İkinci el bilgiye (bir özetin özeti, bir arkadaştan duyulan bilgi) güvenmeyin.

## Kısa Tekrar Notları

- BLM1012, BLM1011'in devamıdır ve ikinci yılın programlama derslerinin temelidir.
- Algoritma geliştirmek sürekli pratik gerektirir.
- CodeBlocks ve Dev-C++ birer IDE'dir, derleyici değildir.
- Derste anlatılan C standardına uyun, C ile C++'ı karıştırmayın.

## Detaylı Açıklamalar

Dönemin ilk dersi, laboratuvar saatinde yapılan bir tanışma dersidir. Hoca kendini tanıtır: bölümde 8 yıldır çalıştığını, bu dersin laboratuvar uygulamalarında 2013'ten beri görev aldığını ve dersi ilk kez teorik olarak verdiğini söyler. Ardından dersin bölüm müfredatındaki yerini anlatır. Birinci dönem dersiyle üçüncü ve dördüncü dönem dersleri arasında bir köprü kurulduğunu, farklı bir hoca kadrosunun farklı bir bakış açısı ve soru stili getireceğini belirtir.

Hoca kendi geçmişinden yola çıkarak meslek lisesinde öğrendiği algoritma derslerinin bugünkü çalışmalarının temeli olduğunu anlatır. Algoritma öğrenmeyi bitmeyen bir süreç olarak tanımlar ve dil öğrenmeye benzetir. Üniversitenin mesleğin mantığını öğrettiğini, bu mantığın da insanı yeni gelişmelere karşı taze tuttuğunu vurgular.

Dersin sonunda programlama ortamı, kaynak kitaplar ve kurslar hakkındaki sorular cevaplanır. Hoca, derste anlatılmayan bir konunun sorulmayacağını ve temel C bilgisinin dersler ve ödevlerle yeterince öğrenilebileceğini söyler. Bir sonraki derste, birinci dönemin algoritma konularının bir tekrarıyla başlanacaktır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
