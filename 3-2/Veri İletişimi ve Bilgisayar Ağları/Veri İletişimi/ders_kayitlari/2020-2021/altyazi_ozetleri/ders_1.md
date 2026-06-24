# Ders 1 Çalışma Özeti

## Genel Konular

- OSI katmanlı mimariden fiziksel iletime geçiş
  - Mesajın katmanlardan geçerken başlıklarla paketlendiği, veri bağı katmanında hata kontrolü için ek bilgiler kullanılabildiği hatırlatılır.
  - Paketlenmiş bilginin karşı tarafa ulaşabilmesi için fiziksel ortamda sinyal olarak temsil edilmesi gerekir.
- Analog ve dijital sinyal ayrımı
  - Analog sinyal zamanın her anında tanımlıdır; genlik, frekans ve faz değerleri sürekli değişebilir.
  - Dijital ya da ayrık sinyal belirli değer kümeleriyle ifade edilir; bu yüzden bilgisayar verisini temsil etmeye daha uygundur.
- Periyodik ve periyodik olmayan sinyaller
  - Periyodik sinyal belirli bir zaman aralığında aynı örüntüyü tekrarlar.
  - Periyodik olmayan sinyal düzenli tekrar göstermez; veri iletiminde kullanılan gerçek sinyaller çoğu zaman ideal çizimlerden daha karmaşıktır.
- Sinyal parametreleri
  - Genlik sinyalin yüksekliğini, frekans birim zamandaki tekrar sayısını, faz ise sinyalin başlangıç konumundaki kaymayı anlatır.
  - Bu parametreler veri kodlama için değiştirilebilir; örneğin bilgi genlik, frekans veya faz değişimiyle taşınabilir.
- Gürültü ve sinyal bozulması
  - Hiçbir iletim hattı tamamen gürültüsüz değildir.
  - Sıcaklık, elektromanyetik etkiler, çevresel koşullar ve hat özellikleri sinyalin alıcıya bozulmuş ulaşmasına sebep olabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sinyal, verinin fiziksel dünyadaki temsilidir.
  - Veri paketlenmiş olsa bile, gerçek iletim sinyalin ortamda taşınmasıyla gerçekleşir.
- Analog ve dijital farkı sadece cihaz türü farkı değildir.
  - Analog tarafta değerler süreklidir; dijital tarafta ayrık değerler üzerinden yorum yapılır.
- Gürültü kaçınılmazdır.
  - Bu yüzden sinyal değerleri birbirinden ayırt edilebilir seçilmeli ve hata ihtimali baştan hesaba katılmalıdır.

## Kısa Tekrar Notları

- Analog sinyal sürekli, dijital sinyal ayrık yapıdadır.
- Genlik, frekans ve faz sinyalin temel karakteristikleridir.
- Periyodik sinyal aynı örüntüyü tekrarlar.
- Veri, sinyal özellikleri değiştirilerek kodlanabilir.
- Gürültü veri iletiminde temel problemlerden biridir.

## Detaylı Açıklamalar

Bu derste veri iletişiminin fiziksel katmanla ilişkisi kurulmuştur. OSI modelinde üst katmanlardan gelen veri, alt katmanlara indikçe çeşitli başlıklar ve kontrol bilgileriyle kapsüllenir. Ancak bu kapsüllenmiş yapı tek başına iletim anlamına gelmez; verinin karşı tarafa ulaşması için fiziksel ortamda bir sinyale dönüştürülmesi gerekir.

Sinyaller analog ve dijital olarak ele alınır. Analog sinyal zamana göre sürekli değişebilen bir yapıdır; genlik, frekans ve faz gibi büyüklükler geniş bir değer aralığında değişebilir. Dijital sinyal ise belirli ayrık değerlerle ifade edilir. Bilgisayar sistemlerinde ikili veri kullanıldığı için dijital temsil daha doğrudan görünse de, iletim ortamı çoğu zaman analog fiziksel davranışlara sahiptir.

Sinyal üzerinde veri taşımak için genlik, frekans veya faz değiştirilebilir. Bu değişimlerin alıcı tarafından doğru yorumlanabilmesi için değerlerin yeterince ayırt edilebilir olması gerekir. Gürültü, sinyal zayıflaması ve çevresel etkiler bu ayrımı zorlaştırır. Bu nedenle kodlama yapılırken sadece ideal sinyal çizimleri değil, gerçek iletim hattının bozucu etkileri de düşünülmelidir.
