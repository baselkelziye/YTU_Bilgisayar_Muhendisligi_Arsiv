# Ders 4 Çalışma Özeti

## Genel Konular

- Lojik fonksiyonların indirgenmesi
  - Amaç, fonksiyonun doğruluk tablosundaki çıkışları değiştirmeden daha az terimli ve daha düşük maliyetli ifade elde etmektir.
  - Daha az terim daha az kapı, daha az bağlantı ve daha sade devre anlamına gelir.
- İndirgeme yöntemleri
  - Görüşe dayalı indirgeme Boolean cebri kurallarını sezgisel kullanır.
  - Karnaugh haritası komşu `1` veya `0` gruplarını kullanarak sistematik sadeleştirme sağlar.
  - Quine-McCluskey yöntemi daha algoritmik ve tablo tabanlı bir yaklaşımdır.
- Boolean cebri kuralları
  - Ortak paranteze alma, tümleyen ilişkisi, `A + A' = 1`, `A · A' = 0` gibi özdeşlikler indirgemede kullanılır.
  - De Morgan kuralları çarpım ve toplam işlemlerini tümleyen altında birbirine dönüştürür.
- Kanonik gösterimler
  - Minimum terimler biçimi fonksiyonun `1` olduğu satırlar üzerinden yazılır.
  - Maksimum terimler biçimi fonksiyonun `0` olduğu satırlar üzerinden yazılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- İndirgeme yapılırken fonksiyonun çıkışı değişmemelidir.
  - Sadeleşen ifade ile ilk ifade aynı doğruluk tablosunu üretmelidir.
- Görüşe dayalı indirgeme kesin biçimde en küçük sonucu garanti etmeyebilir.
  - Ara bir sadeleşmede durmak yerine ifadenin daha da indirgenip indirgenemeyeceği kontrol edilmelidir.
- De Morgan dönüşümlerinde işaret değişimi dikkatle takip edilmelidir.
  - Tümleyen alınırken AND, OR'a; OR, AND'e dönüşür ve terimler tek tek tümleyenlenir.
- Minterm açılımında ikili sayının her biti değişkenin düz veya tümleyen halini belirler.

## Kısa Tekrar Notları

- İndirgeme: aynı çıkış, daha az terim.
- `A + A' = 1`, `A · A' = 0` temel sadeleştirme kurallarıdır.
- De Morgan: `(A · B)' = A' + B'`, `(A + B)' = A' · B'`.
- Mintermde `0` olan bit tümleyen, `1` olan bit düz değişkenle yazılır.
- Karnaugh haritasında komşu hücreler büyük gruplar halinde alınır.

## Detaylı Açıklamalar

- Lojik fonksiyon indirgeme, devre tasarımında maliyet ve karmaşıklığı azaltmak için kullanılır. Örneğin çok sayıda AND, OR ve NOT kapısı gerektiren bir ifade, doğru sadeleştirme ile daha az kapıyla kurulabilir.
- Görüşe dayalı indirgemede ifadedeki ortak çarpanlar aranır. Ortak paranteze alma, tümleyen çiftlerini fark etme ve De Morgan uygulama temel araçlardır. Bu yöntem hızlıdır; ancak öğrencinin Boolean cebri kurallarını iyi görmesini gerektirir.
- Kanonik gösterimlerde fonksiyon, doğruluk tablosundaki satır numaralarıyla ifade edilebilir. `F(x,y,z)=Σm(0,4)` biçimi fonksiyonun 0 ve 4 numaralı mintermlerde `1` olduğunu anlatır. Bu satırlar ikili karşılıklarına çevrilerek açık çarpım terimleri yazılır.
- Karnaugh haritası, komşuluk ilişkilerini görsel hale getirir. Komşu `1` grupları büyüdükçe sadeleşen terimde daha fazla değişken elenir. Bu nedenle en büyük geçerli grupları seçmek önemlidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
