# Ders 8 Genişletilmiş Notu: Bağlı Liste Alıştırmaları: Ters Çevirme, En Büyüğü Sona Taşıma ve Tek-Çift Ayırma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Yapısı
- 2. Bağlı Listeyi Ters Çevirme
- 3. En Büyük Elemanı Sona Taşıma
- 4. Tek Sayıları Başa, Çift Sayıları Sona Toplama
- 5. Kendi Başına Çalışma Önerileri
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Yapısı

Bu kayıt yaklaşık 18 dakikalık kısa bir uygulama oturumudur. Kayıt boyunca ekranda yalnız hocanın kamera görüntüsü vardır; slayt, kod ya da tahta paylaşılmamıştır. Bu yüzden aşağıdaki bütün problemler sözlü anlatımdan aktarılmıştır. Hoca bu oturumda yeni bir uygulama yapmadı. Önce öğrencilerin soruları olup olmadığını sordu, sonra daha önce bağlı listeyle insertion sort anlattığını hatırlatıp bunu deneyen olup olmadığını sordu. Ardından bağlı listelerle "el alıştırması" olsun diye birkaç yeni problem ortaya attı ve bunların çözümlerini öğrencilerle birlikte konuştu. Hoca bir ara sohbete küçük bir örnek liste yazdığını söyledi; sohbet penceresi kayıtta görünmüyor, ancak örnek sözlü olarak da tekrarlandı.

## 2. Bağlı Listeyi Ters Çevirme

### 2.1 Problem

Elimizde tek yönlü bir bağlı liste vardır ve bu listeyi tersine çevirmek isteriz. Hoca "tersine çevirmek" ile ne kastettiğini şöyle tanımladı: son eleman yeni baş (head) olmalı, ilk elemanın işaretçisi de `NULL` olmalıdır. Düğümler A, B, C, D, E, F sırasıyla birbirini gösteriyorsa, işlemden sonra F, E, D, C, B, A sırasıyla birbirini göstermelidir. Hoca bunu "listeyi baş aşağı çevirmek" diye de anlattı.

### 2.2 Kaç değişken gerekir?

Hoca bunun için kaç ekstra değişken kullanmak gerektiğini ve nasıl bir mantıkla ilerlemek gerektiğini sordu. Bir öğrenci iki işaretçinin yeterli olduğunu söyledi; hoca bunları "previous ve current" olarak tekrarladı.

**Soru:** Sondan kesip başa ekleyerek yapabilir miyiz?
**Cevap:** Hoca, istenenin yalnız elemanların yerini değiştirmek değil, bütün bağlantıları ters çevirmek olduğunu söyledi: A'nın B'yi, B'nin C'yi gösterdiği bağlantılar ters yöne dönmelidir.

### 2.3 Baştan mı, sondan mı?

Hoca ardından işleme listenin neresinden başlamanın mantıklı olduğunu sordu. Cevap, listenin sonunun bilinmediği, bu yüzden baştan başlanacağı oldu. Hoca iki yolu karşılaştırmayı önerdi:

- Baştan başlamak: head elemandan başlanır, birinci düğümün işaretçisi `NULL`a çevrilir, sonra ikinci düğüm birinciye bağlanır ve bu şekilde `NULL`a kadar gidilir.
- Sondan başlamak: önce `NULL`a kadar gidilip oradan geri gelinmeye çalışılır. Bu, en azından bir kez sona kadar gitmeyi gerektirdiği için açıkça ek bir maliyet getirir.

> **Ek bilgi (derste anlatılmadı):** Baştan başlayan iki işaretçili çözümde, current düğümün bağlantısı değiştirilmeden önce bir sonraki düğümün adresi geçici olarak saklanmalıdır; yoksa listenin geri kalanına ulaşılamaz. Bu yüzden uygulamada previous ve current yanında kısa ömürlü bir "next" değişkeni de kullanılır. İşlem tek geçişte biter, yani zaman karmaşıklığı büyük olasılıkla $O(n)$, ek bellek $O(1)$ olur.

## 3. En Büyük Elemanı Sona Taşıma

### 3.1 Problem

Tamsayılardan oluşan bir bağlı listede, en büyük elemanı listenin sonuna koyan (ya da en küçük elemanı başa alan) bir algoritma tasarlanacaktır.

### 3.2 Temel çözüm

Hoca her zaman önce bir temel çözümle, en basit çözümle başlanması gerektiğini hatırlattı. Bu problemde en basit çözüm şudur:

- Listeyi bir kez gezip en büyük değerin ne olduğu öğrenilir (hocanın örneğinde en büyük değer 567 çıkıyor).
- Liste yeniden gezilerek değeri 567 olan düğüm bulunur.
- Sonra `NULL` görülene kadar ilerlenir ve düğüm bir "sil" ve bir "ekle" işlemiyle sona konur.

> **Hocanın vurgusu:** Önce temel çözüm bulunur, sonra "acaba biraz daha etkili hâle getirilebilir mi?" diye sorulur.

### 3.3 Daha etkili çözüm

Bir öğrenci, bulunan en büyük değeri geçici bir değişkende tutmayı, böylece sona varıldığında tekrar gezmeden bağlantı yapılabileceğini önerdi. Hoca bunu, yalnız bir tamsayı tutmanın bile yeterli olabileceğini, ama bir geçici düğüm (temporary node) yapıp her yeni en büyük değer görüldüğünde bu düğümün değerini güncellemenin de mümkün olduğunu söyleyerek yorumladı. `NULL` görüldüğünde bu geçici düğüm son eleman olarak eklenebilir.

Hoca burada asıl zorluğu sordu: sona ekleme tamam, ama aradaki en büyük değerli düğüm listeden nasıl silinecek? Öğrenci bunun için en büyük düğümün adresini bir geçici değişkende tutacağını, silme işlemini bu adres üzerinden yapacağını söyledi. Hoca bunu "max işaretçisini tutmak" olarak özetledi ve çözümün bu hâliyle doğru olduğunu belirtti. Aynı yöntem en küçük elemanı başa almak için de kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** Tek yönlü bağlı listede bir düğümü çıkarmak için o düğümden bir önceki düğümün bağlantısını değiştirmek gerekir. Bu yüzden uygulamada en büyük düğümün kendisiyle birlikte ondan önceki düğümün adresi de tutulur. Böylece çözüm tek geçişte, ek bellek olarak yalnız birkaç işaretçiyle tamamlanır.

## 4. Tek Sayıları Başa, Çift Sayıları Sona Toplama

### 4.1 Problem

Yine tamsayılardan oluşan bir bağlı liste vardır. Tek sayılar başa, çift sayılar sona gitmelidir. Örneğin 10 elemanın 4'ü tek, 6'sı çiftse, tekler 1-4. düğümlerde, çiftler 5-10. düğümlerde olmalıdır. Ayrıca elemanlar bağlı listedeki ilk dizilişlerini kaybetmemelidir.

**Soru:** Tek sayılar kendi içinde sıralı mı olacak?
**Cevap:** Hayır, sıralı (sorted) olmaları istenmiyor. İstenen, her grubun listedeki ilk sırasını korumasıdır.

Hoca bunu bir örnekle açıkladı. Liste 2, 3, 1, 6, 7 ise sonuç 3, 1, 7, 2, 6 olmalıdır: tekler öne gelir ama aralarındaki ilk sırayı korur (3, 1, 7), çiftler de arkada yine ilk sıralarıyla kalır (2, 6).

> **Ders sonrası not:** Hoca problemi anlatırken bir an "çiftler başta" dedi, sonra düzeltip teklerin öne geleceğini söyledi. Çözümü anlatırken de bir yerde "bütün çift sayılar başa geldi" dedi ve hemen "ya da tek sayılar, hangisi ise" diye ekledi. Derste kullanılan tanım teklerin başa gelmesidir; hangisinin başa geleceği yalnız kontrol koşulunu değiştirir.

### 4.2 Derste konuşulan çözüm

Bir öğrenci şu çözümü önerdi: çiftlerin ilkinin işaretçisi tutulur ve ne zaman bir tek sayı bulunursa o düğüm bu ilk çifte bağlanır (önüne eklenir). Hoca bunun için ek bir bağlı liste mi kullanılacağını sordu; öğrenci ek liste değil, yalnız tek bir işaretçi kullanılacağını söyledi.

Örnek liste üzerinde adımlar şöyledir:

- Başlangıç: 2, 3, 1, 6, 7. İlk çift sayı 2'dir; işaretçi 2'yi gösterir.
- 2'nin sonrasına gidilir, 3 görülür. 3 tek olduğu için 2'nin önüne eklenir: 3, 2, 1, 6, 7.
- Sonraki eleman 1'dir. Tek olduğu için yine 2'nin önüne eklenir: 3, 1, 2, 6, 7.
- Sonraki eleman 6'dır. Çift olduğu için yerinde bırakılır.
- Sonraki eleman 7'dir. Tek olduğu için yine 2'nin önüne eklenir: 3, 1, 7, 2, 6.
- `NULL`a gelinir. Sonuç: 3, 1, 7, 2, 6.

Hoca bu yöntemin neden sırayı koruduğunu da açıkladı: bütün tekler aynı noktaya, ilk çiftin önüne, bulundukları sırayla eklendiği için 3 önce, sonra 1, sonra 7 gelir. Sonda da 2 ve 6 kendi ilk sıralarıyla kalır.

<!-- BELİRSİZ: Tek yönlü listede bir düğümü ilk çiftin "önüne" eklemek için, ilk çiftten hemen önceki düğümün (son yerleştirilen tek sayının) adresi de tutulmalıdır; ayrıca taşınan düğümün eski yerinden çıkarılması için gezintideki önceki düğüm bilinmelidir. Bu ayrıntılar derste açıkça konuşulmadı. -->

> **Hocanın vurgusu:** Bu tür problemleri düşünün, algoritmasını tasarlayın, akışını çizin ve kodlayın; amaç bağlı listelerle elinizin alışmasıdır.

## 5. Kendi Başına Çalışma Önerileri

Hoca, oturumun kalan süresinde öğrencilerin birkaç bağlı liste problemini kendi başlarına düşünüp elle uygulamasını önerdi ve şu konuları saydı:

- Çift yönlü (doubly) ve dairesel (circular) bağlı listeler: ileri ve geri gezintiler denenebilir.
- Deneysel çalışma süresi ölçümü: eleman sayısı rastgele 100, 1000, 10.000 yapıldığında işlemlerin (örneğin oluşturma ve sıralama) ne kadar sürdüğü ölçülüp karşılaştırılabilir; böylece $n^2$ ya da $\log n$ gibi büyüme biçimlerinin pratikte nasıl arttığı görülebilir.
- Seyrek (sparse) matrisin bağlı listeyle gösterimi ve genel olarak bir matris yapısının bağlı listelerle nasıl temsil edilebileceği; çift taraflı (iki yönlü) bağlantılarla bunun nasıl yapılabileceği.

Hoca ayrıca Josephus probleminden daha önce bahsedildiğini hatırlattı.

> **Hocanın vurgusu:** Bağlı liste temel ve çok esnek bir veri yapısıdır; sonraki pek çok konuda ve pek çok veri yapısında sıkça kullanılacaktır.

## Örnek Sorular

Bu oturumda ekranda soru gösterilmedi; aşağıdaki sorular derste sözlü olarak soruldu. Derste kod yazılmadı. Aşağıdaki Python kodları derste yazılmamıştır; ajan tarafından yazılıp küçük girdilerle çalıştırılarak test edilmiştir.

Ortak düğüm tanımı:

```python
class Node:
    def __init__(self, v, nxt=None):
        self.v = v
        self.next = nxt
```

### Soru 1 (derste sözlü, 00:05:05)

Bir bağlı listeyi tersine çevirin: son eleman head olsun, ilk elemanın işaretçisi `NULL` olsun (A, B, C, D, E, F → F, E, D, C, B, A). Kaç ekstra değişken gerekir ve hangi uçtan başlanmalıdır?

Derste verilen cevap: previous ve current işaretçileri yeterlidir; sonu bilinmediği için baştan başlanır.

> **Çözüm (derste verilmedi):**
>
> ```python
> def reverse(head):
>     prev, cur = None, head
>     while cur:
>         nxt = cur.next     # kalan listeyi kaybetmemek için
>         cur.next = prev    # bağlantıyı ters çevir
>         prev, cur = cur, nxt
>     return prev            # yeni head
> ```
>
> A, B, C, D, E, F girdisiyle çıktı F, E, D, C, B, A oldu.

### Soru 2 (derste sözlü, 00:07:23)

Tamsayılardan oluşan bir bağlı listede en büyük elemanı en sona koyan (ya da en küçük elemanı en başa koyan) bir algoritma tasarlayın.

Derste verilen cevap: temel çözüm listeyi birkaç kez gezer; daha etkili çözümde tek geçişte en büyük düğümün adresi (max işaretçisi) tutulur, sona gelindiğinde düğüm çıkarılıp sona eklenir.

> **Çözüm (derste verilmedi):**
>
> ```python
> def max_to_end(head):
>     if head is None or head.next is None:
>         return head
>     maxprev, maxn = None, head
>     prev, cur = head, head.next
>     while cur:
>         if cur.v > maxn.v:
>             maxn, maxprev = cur, prev
>         prev, cur = cur, cur.next
>     tail = prev
>     if maxn is tail:
>         return head
>     if maxprev is None:
>         head = maxn.next
>     else:
>         maxprev.next = maxn.next
>     tail.next, maxn.next = maxn, None
>     return head
> ```
>
> 4, 567, 2, 9 girdisiyle çıktı 4, 2, 9, 567; 9, 1, 2 girdisiyle 1, 2, 9 oldu.

### Soru 3 (derste sözlü, 00:10:00)

Tamsayılardan oluşan bir bağlı listede tek sayılar başa, çift sayılar sona gelsin; her grup ilk sırasını korusun. Örnek: 2, 3, 1, 6, 7 → 3, 1, 7, 2, 6.

Derste verilen cevap: ilk çift sayının adresi tutulur, her tek sayı bu düğümün önüne eklenir, çiftler yerinde bırakılır.

> **Çözüm (derste verilmedi):** İlk çift düğümün (`firsteven`) yanında son yerleştirilen tek düğüm (`lastodd`) ve gezintideki önceki düğüm (`prev`) de tutulur.
>
> ```python
> def odd_first(head):
>     lastodd = firsteven = prev = None
>     cur = head
>     while cur:
>         nxt = cur.next
>         if cur.v % 2:                  # tek
>             if firsteven is None:      # henüz çift görülmedi
>                 lastodd = prev = cur
>             else:
>                 prev.next = nxt        # eski yerinden çıkar
>                 cur.next = firsteven   # ilk çiftin önüne ekle
>                 if lastodd is None:
>                     head = cur
>                 else:
>                     lastodd.next = cur
>                 lastodd = cur
>         else:                          # çift
>             if firsteven is None:
>                 firsteven = cur
>             prev = cur
>         cur = nxt
>     return head
> ```
>
> 2, 3, 1, 6, 7 girdisiyle çıktı 3, 1, 7, 2, 6; 5, 2, 3, 4, 1 girdisiyle 5, 3, 1, 2, 4 oldu.

## Dersin Toparlaması

Bu kısa uygulama oturumunda bağlı listeler üzerinde üç tasarım problemi konuşuldu. Listeyi ters çevirmede previous ve current işaretçileriyle baştan başlayıp her bağlantının bir önceki düğüme çevrilmesi gerektiği; en büyük elemanı sona taşımada önce temel çözümün bulunup sonra en büyük düğümün adresini tutarak tek geçişe indirgenebileceği; tekleri başa, çiftleri sona toplamada ilk çiftin adresini tutup her teki onun önüne ekleyerek grupların iç sırasının korunabileceği görüldü. Ortak fikir, bağlı listede düğümlerin değerlerini değil bağlantılarını değiştirerek çalışmak ve silme ya da araya ekleme için doğru adresleri elde tutmaktır.

Hoca, çift yönlü ve dairesel listeler, deneysel çalışma süresi ölçümü ve seyrek matrisin bağlı listeyle gösterimi gibi alıştırmaları önerdi ve bağlı listelerin sonraki derslerde tanıtılacak pek çok veri yapısının temelinde yer alacağını vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
