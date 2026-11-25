# Ders 13 Çalışma Özeti

## Genel Konular

- Bellek hiyerarşisi ve yerellik (locality) tekrarı
  - Hiyerarşi: yazmaçlar, önbellek (cache), ana bellek ve ikincil birimler. Yazmaçlar ve önbellek işlemcinin içinde, diğerleri dışındadır.
  - Zamansal yerellik (temporal locality): programlar aynı değişkene tekrar tekrar erişir ya da yeni değer atar. Bu verinin her seferinde ana bellekten değil, daha hızlı önbellekten alınması verimi (throughput) artırır.
  - Uzamsal yerellik (spatial locality): dizi işlemlerinde bir elemana erişilince çevresindeki elemanlar da yakında kullanılır. Bir blok önbelleğe alınırsa sonraki erişimler blok genişliği ölçüsünde önbellekten yapılır.
- Önbellek tasarımının soruları (ekrandan, 00:10:00)
  - CPU veriyi fiziksel adresle önbellekte arar. Üç soru vardır: fiziksel adres önbellekte nerede aranır, önbellekte olmayan veri ana bellekten getirilince nereye yerleştirilir, önbellek en yüksek verimi verecek biçimde nasıl düzenlenir.
  - Slayttaki sorular: önbellek nasıl düzenlenir, her bellek adresi nereye eşlenir (önbellek belleğin alt kümesidir, birden çok adres aynı önbellek yerine eşlenir), hangi elemanların önbellekte olduğu nasıl bilinir, bunlar nasıl hızlı bulunur.
- Üç eşleme yöntemi (ekrandan, 00:15:00 ve 00:20:00)
  - Doğrudan eşlemeli (direct mapped): fiziksel adresin en düşük anlamlı kısmı byte offset ve word offset, ortadaki kısmı index, kalanı tag'dir. Index doğrudan önbelleğin hangi satırına bakılacağını belirler. Aynı index'e düşen farklı adresleri ayırmak için satırda tag saklanır.
  - Tam ilişkili (fully associative): index alanı yoktur; offset dışındaki bütün adres tag'dir. Veri sıradaki boş satıra yerleşir. Aramada bütün satırların tag'leri tek tek karşılaştırılır. Önbellek doluysa yer değiştirme politikası gerekir.
  - Küme ilişkili (set associative): ikisinin birleşimidir. Satırlar boyunca doğrudan eşleme, her satırdaki kümeler (yollar) boyunca tam ilişkili yapı vardır. Index ile satır bulunur, yalnız o satırdaki kümelerin tag'leri karşılaştırılır; ıska durumunda yer değiştirme yalnız bu kümeler arasında yapılır.
- Önbellekte önbellek satırına (blok) yerleşen şey adres değil, o adreslerdeki verinin kendisidir; satırda ayrıca tag ve geçerlilik (valid) biti tutulur.
- Küçük doğrudan eşlemeli örnek (ekrandan, 00:25:00)
  - 16 byte'lık bellek, 4 byte'lık doğrudan eşlemeli önbellek, blok 1 byte.
  - Satır sayısı $4/1 = 4$, index $\log_2 4 = 2$ bit; fiziksel adres $\log_2 16 = 4$ bit; byte ve word offset 0 bit; kalan 2 bit tag.
  - Her 4 adreste bir aynı önbellek satırı kullanılır (0, 4, 8, C adresleri 0. satıra eşlenir).
- Doğrudan eşlemenin sorunu ve blok genişliğinin etkisi (ekrandan, 00:30:00)
  - Slayt: adres tag, index ve byte offset alanlarına bölünür.
  - En kötü durum: program hep 512 adres aralıklı verilere erişiyor ve bunlar hep aynı satıra eşleniyorsa her erişim ıska olur, önbelleğin geri kalanı boş kalır.
  - Sabit önbellek kapasitesinde blok genişliği artırıldıkça uzamsal yerellikten yararlanıldığı için ıska oranı önce düşer; satır sayısı kritik bir değere inince yeniden artar. Ortalama erişim süresi de bu artıştan olumsuz etkilenir.
- 16 KB, 4 word'lük bloklu doğrudan eşlemeli önbellekte adres bölümleme (ekrandan, 00:35:00)
  - 32 bitlik mimari: word 4 byte, byte offset $\log_2 4 = 2$ bit; blokta 4 word, word offset 2 bit.
  - Satır sayısı $2^{14} / 2^4 = 2^{10} = 1024$, index 10 bit; tag $32 - 10 - 2 - 2 = 18$ bit.
- Bu önbellekte dört adrese erişim (ekrandan, 00:40:00 - 01:00:00)
  - 0x00000014: index 1, valid 0, ıska; 0x10-0x1F aralığındaki 16 byte satır 1'e getirilir, valid 1, tag 0 yapılır.
  - 0x0000001C: index 1, valid 1, tag eşit, isabet; word 3'ün 0. byte'ı (blok içinde 12. byte) okunur.
  - 0x00000034: index 3, valid 0, ıska; 0x30-0x3F satır 3'e getirilir, tag 0. Farklı satırlarda aynı tag bulunabilir; onları ayıran index'tir.
  - 0x00008014: index 1, valid 1 ama tag 2 ≠ 0, ıska; satır 1'deki veri 0x8010-0x801F ile değiştirilir, tag 2 yapılır.
  - Sonuç: 1 isabet, 3 ıska.
- Erişim durumları
  - Valid biti 0 iken ıska: veri ezilmeden getirilir.
  - Valid biti 1 ve tag farklı: ıska ve blok değiştirme; mevcut veri yeni blokla ezilir.
  - Valid biti 1 ve tag eşit: isabet; adresin word ve byte offset'ine göre veri okunur.
- Önbellek çakışması (thrashing) örneği (ekrandan, 01:20:00)
  - MIPS, 64 KB doğrudan eşlemeli önbellek, 16 byte'lık satır; iki float dizinin aynı sıradaki elemanları çarpılıp bir toplamda biriktirilir. Float 4 byte olduğundan bir satıra 4 eleman sığar.
  - x ve y farklı satırlara eşleniyorsa her 4 elemanda bir ıska: 8 okumada 2 ıska, %25 ıska oranı.
  - x[i] ile y[i] aynı satıra eşleniyorsa her okuma bir öncekinin bloğunu atar: 8 okumada 8 ıska, %100 ıska oranı.
- Ortalama erişim süresi (ekrandan, 01:25:00 ve 01:30:00)
  - $t_a = h\,t_c + (1-h)(t_m + t_c) = t_c + (1-h)\,t_m$.
  - Örnek: $h = 0.85$, $t_m = 50$ ns, $t_c = 5$ ns için $t_a = 5 + 0.15 \cdot 50 = 12.5$ ns.
- İki seviyeli önbellek örneği (derste sözlü, 01:31:06)
  - L1 erişimi 1 çevrim, L2'den getirme 5 çevrim, bellekten L2'ye 100 çevrim; L1 isabet oranı %95, L2 isabet oranı %85.
  - L1 ıska cezası $5 + 0.15 \cdot 100 = 20$ çevrim; ortalama erişim süresi $1 + 0.05 \cdot 20 = 2$ çevrim.
- Yer değiştirme algoritmaları (ekrandan, 01:35:00)
  - Yalnız tam ilişkili ve küme ilişkili önbellekte gerekir; doğrudan eşlemede atılacak blok index ile bellidir.
  - Optimal: en uzun süre kullanılmayacak bloğu atmak; geleceği bilmeyi gerektirir.
  - LRU (en uzun süredir kullanılmayan): her satırda sayaç; erişimde sayaç sıfırlanır, en büyük sayaçlı satır atılır. Gerçeklemesi zordur.
  - FIFO: sayaç yalnız yerleştirmede sıfırlanır; en büyük sayaçlı satır ilk girendir. Gerçeklemesi kolaydır.
  - Random: rastgele bir blok atılır; en kolayıdır.
- Adres bölümleme örneği (ekrandan, 01:45:00 ve 01:50:00)
  - Toplam kapasite 16 byte, blok 2 byte, CPU veri yolu 16 bit, adres yolu 10 bit.
  - Doğrudan eşlemeli: tag 6, index 3, byte offset 1 bit. Tam ilişkili: tag 9, byte offset 1 bit. 2 yollu: tag 7, index 2, byte offset 1. 4 yollu: tag 8, index 1, byte offset 1. Word offset her durumda 0 bittir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Adres alanlarının genişliğini bulmak
  - Genel mantık anlaşıldıktan sonra asıl önemli olan, verilen bir mimari için tag, index, word offset ve byte offset genişliklerini hesaplayabilmektir.
- Önbelleğe adres değil veri yerleşir
  - Satırın data alanında ana bellekteki verinin kendisi, tag alanında adresin tag kısmı saklanır.
- FIFO satırı ile LRU satırı aynı olmak zorunda değildir
  - Önbelleğe ilk giren satır sık erişiliyorsa en uzun süredir kullanılmayan satır o olmaz.
- Önbellek yapısını dikkate almayan kod yavaş çalışabilir
  - Thrashing örneğinde aynı kod, dizilerin bellekteki yerleşimine göre %25 ya da %100 ıska oranı verir.
- Ana bellekten bir byte değil, adresi içeren bütün blok getirilir
  - 16 byte'lık blokta 0x14 için 0x10-0x1F aralığının tamamı önbelleğe alınır.

## Kısa Tekrar Notları

- Doğrudan eşleme: tag | index | word offset | byte offset. Tam ilişkili: tag | word offset | byte offset. Küme ilişkili: index satırı seçer, satırdaki kümelerde tag aranır.
- byte offset $= \log_2$(word başına byte), word offset $= \log_2$(blok başına word), index $= \log_2$(kapasite / satır başına byte), tag = adres − diğerleri.
- $k$ yollu küme ilişkilide satır başına byte $= k \times$ blok genişliği.
- Valid biti başlangıçta 0'dır; ilk erişimler zorunlu ıskadır.
- $t_a = t_c + (1-h)\,t_m$; çok seviyede önce dıştaki seviyenin ortalaması (iç seviyenin ıska cezası) bulunur.
- LRU: erişimde sayaç sıfırlanır. FIFO: yerleştirmede sayaç sıfırlanır. Random: rastgele.

## Detaylı Açıklamalar

- Önbellek tasarımı üç soruya cevap arar: bir fiziksel adres önbellekte nerede aranır, ıska olunca getirilen blok nereye konur ve önbellek en yüksek verimi verecek biçimde nasıl düzenlenir. Doğrudan eşlemeli önbellekte her adresin gideceği satır index alanıyla bellidir; bu arama işini kolaylaştırır ama aynı index'e düşen adresler birbirini sürekli atabilir. Örneğin program hep 512 adres aralıklı verilere erişiyor ve bunlar aynı satıra eşleniyorsa her erişim ıska olur ve önbelleğin kalanı boş kalır. Tam ilişkili önbellekte eşleme yoktur; veri ilk boş satıra konur, bu yüzden yerleştirmek kolay ama aramak zordur, çünkü bütün satırların tag'i karşılaştırılmalıdır. Küme ilişkili önbellek bu iki yapının ortasıdır: satırı index seçer, aranacak yer yalnız o satırdaki kümelerle sınırlanır.
- Doğrudan eşlemeli önbellekte bir satırda valid biti, tag ve data alanı vardır. 16 KB, 4 word'lük bloklu, 32 bitlik örnekte satır 1 valid biti, 18 bitlik tag ve 16 byte veriden oluşur. CPU bir adres ürettiğinde index ile satıra gidilir, valid biti ve tag kontrol edilir; ikisi de uygunsa son 4 bitle 16 byte içinden istenen byte seçilir. Uygun değilse adresi içeren 16 byte'lık blok ana bellekten getirilir, data alanına yazılır, valid 1 ve tag güncellenir; veri CPU'ya önbellekten okunur.
- Dört adres örneğinde 0x14 ve 0x1C aynı bloktadır (0x10-0x1F); ilki ıska, ikincisi isabettir. 0x34 başka bir satıra (index 3) düşer ve ıskadır. 0x8014 ise 0x14 ile aynı index'e (1) ama farklı tag'e (2) sahiptir; satırdaki blok atılır ve yerine 0x8010-0x801F getirilir. Böylece dört erişimde 1 isabet, 3 ıska olur.
- Thrashing örneğinde iki float dizinin aynı sıradaki elemanları çarpılıp toplanır. 16 byte'lık satıra 4 float sığar. Diziler farklı satırlara eşlenirse x[0] ve y[0] ıska, sonraki üçer eleman isabettir; ıska oranı %25 olur. Diziler aynı index'e düşerse x[0] okununca gelen blok y[0] okununca atılır, x[1] okununca yeniden getirilir; bütün okumalar ıska olur (%100). Hoca, kullanılan mimarinin önbellek yapısını dikkate almayan kodun bu yüzden daha yavaş çalışabileceğini vurguladı.
- Ortalama erişim süresi $h$ olasılıkla yalnız önbellekten okuma ($t_c$), $1-h$ olasılıkla ana bellekten önbelleğe getirme ve önbellekten okuma ($t_m + t_c$) maliyetinden oluşur: $t_a = h\,t_c + (1-h)(t_m + t_c) = t_c + (1-h)\,t_m$. %85 isabet, 50 ns bellek ve 5 ns önbellekle 12.5 ns bulunur; önbellek kullanılmasaydı her erişim 50 ns sürecekti, yani süre dörtte birine iner. İki seviyeli örnekte önce L2'den L1'e getirme süresi (L1'in ıska cezası) $5 + 0.15 \cdot 100 = 20$ çevrim, sonra ortalama $1 + 0.05 \cdot 20 = 2$ çevrim bulunur; bellekten doğrudan 100 çevrimlik erişime göre yaklaşık 50 kat iyileşme vardır.
- 16 byte kapasite, 2 byte blok, 16 bit veri yolu ve 10 bit adres yolu örneğinde word 2 byte'tır (byte offset 1 bit), blokta 1 word vardır (word offset 0 bit). Doğrudan eşlemede $16/2 = 8$ satır, index 3 bit, tag 6 bit; tam ilişkilide index yoktur, tag 9 bit; 2 yollu küme ilişkilide satır başına $2 \times 2 = 4$ byte, $16/4 = 4$ satır, index 2 bit, tag 7 bit; 4 yollu durumda satır başına 8 byte, 2 satır, index 1 bit, tag 8 bit olur.
- Ders sonrası not: Hoca hiyerarşiyi anlatırken (00:07:01) dışa doğru gidildikçe maliyetin ve erişim maliyetinin arttığını, erişim süresinin hızlandığını söyledi; doğrusu büyük olasılıkla şudur: dışa doğru kapasite artar, bit başına maliyet düşer, erişim süresi uzar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
