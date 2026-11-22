# Ders 24 Çalışma Özeti

## Genel Konular

- Sepet analizi (birlikte satılan ürünleri bulma)
  - Bir süpermarkette ya da e-ticaret sitesinde müşterilerin sepetlerine baktığımızda hangi ürünlerin aynı sepette birlikte yer aldığını bulmak amaçlanır.
  - Bu bilgi reklam, markalar arası anlaşma, reyonları yakın koyma, depolama stratejisi, kampanya ("şunu alana şu indirimli") ve özellikle e-ticarette kişiye özel ürün önerme için kullanılır.
- Veri yapıları: S, A ve T matrisleri
  - S ($N \times 2$): her satırı bir (sepet ID, ürün ID) çiftidir. Örnek satırlar: (1, 783), (1, 442), (2, 13) (ekrandan, 00:15:00).
  - A ($\text{ürünN} \times \text{sepetN}$): $A(i,j)=1$ ise $i$. ürün $j$. sepettedir, değilse 0. Bir sütun bir sepetin içeriğini gösterir.
  - T ($\text{ürünN} \times \text{ürünN}$): $T(i,j)$, $i$. ve $j$. ürünün kaç sepette birlikte geçtiğini tutar; 0, 1, 2, 3, ... gibi sayılar alır.
- S'ten A'ya geçiş (ekrandan, 00:25:00)
  - Önce $N$ okunur, sonra döngüyle her satırda $S(i,1)$ ve $S(i,2)$ okunur.
  - A iki iç içe döngüyle sıfırlanır.
  - S'in her satırı için tek işlem yapılır: $A(S(i,2), S(i,1)) = 1$. Örneğin (3, 42) satırı 42. ürünün 3. sepette olduğunu gösterir.
- A'dan T'ye geçiş: ürün ikilileri (ekrandan, 00:45:00 ve 00:50:00)
  - Üç iç içe döngü: $i = 1..\text{ürünN}$, $j = i+1..\text{ürünN}$, $k = 1..\text{sepetN}$.
  - İlk hâli: `A(i,k)==1 && A(j,k)==1` ise `T(i,j) = T(i,j) + 1`.
  - İyileştirilmiş hâli: if kaldırılır, `T(i,j) = T(i,j) + A(i,k) * A(j,k)` yazılır.
- Ürün üçlüleri
  - T üç indisli olur. Döngüler: $i=1..\text{ürünN}$, $j=i+1..\text{ürünN}$, $k=j+1..\text{ürünN}$, $m=1..\text{sepetN}$.
  - Güncelleme: $T(i,j,k) = T(i,j,k) + A(i,m) \cdot A(j,m) \cdot A(k,m)$.
- Basit şifreleme (ekrandan, 01:15:00)
  - Harfler 5x5'lik bir tabloya dağıtılır. Her harf, bulunduğu satır numarasının 10 katı ile sütun numarasının toplamıyla kodlanır.
  - Tablodaki konumlarla ABC metni 23 12 15 olur (A: 2. satır 3. sütun, B: 1. satır 2. sütun, C: 1. satır 5. sütun).
  - Boşluk da bir sayıyla kodlanır, bu yüzden kelime sınırları görünmez.
- Frekans analiziyle şifre kırma ve buna karşı çoklu temsil
  - Her harfin tek bir karşılığı varsa, uzun bir şifreli metinde sayıların frekansları dildeki harf frekanslarıyla eşleştirilerek harfler tahmin edilebilir.
  - Çözüm: tabloda her harf, dildeki frekansıyla orantılı sayıda yer alır. Şifrelerken harfin konumlarından biri rastgele seçilir. Böylece şifreli metindeki sayıların frekansları birbirine yaklaşır.
- Metinde kelime ikilileri (ekrandan, 01:30:00)
  - M dizisi metindeki kelimelerin ID'lerini tutar. Örnek: "Ali bugün okula geldi" → 45, 120, 748, 12.
  - W ($\text{kelimeN} \times \text{kelimeN}$): $i = 1..N-1$ için $W(M(i), M(i+1)) = W(M(i), M(i+1)) + 1$. W'nin bir satırındaki büyük değerler o kelimeden sonra en çok gelen kelimeleri gösterir.
- Metinde $\pm K$ komşuluk (ekrandan, 01:40:00)
  - Dış döngü $i = 1+K..N-K$, iç döngü $j = -K..K$; güncelleme $W(M(i), M(i+j))$ bir artırılır.
  - $j=0$ olduğunda kelime kendisiyle sayılır; bu fazlalık her adımda ya da en sonda $W(M(i), M(i))$ azaltılarak giderilir.
- Birlikte geçişten kelime koordinatlarına (slayt, 01:50:00 - 02:05:00)
  - W iki yolla kurulabilir: büyük bir derlemde $K$'lık pencere içinde birlikte geçme sayısı ya da iki kelimenin kaç dokümanda birlikte geçtiği (arama motorunun döndürdüğü sonuç sayısı).
  - Harris varsayımı: birlikte geçen kelimeler anlamsal olarak birbirine yakındır.
  - MDS (Multidimensional Scaling): aralarındaki uzaklıklar bilinen noktalara bu uzaklıklarla uyumlu koordinatlar bulur. Çözüm tek değildir (kaydırma ve döndürme). PCA ile ilişkilidir.
  - 30 kelimelik bir denemede kelime türü verilmeden hayvanlar, yerler ve taşıtlar ayrı öbekler oluşturmuştur.

## Hocanın Özellikle Vurguladığı Kısımlar

- T matrisinin boyutu $\text{ürünN} \times \text{ürünN}$'dir, $N \times N$ değildir
  - $N$, S matrisinin satır sayısıdır; ürünN ise farklı ürün sayısıdır.
- T'nin yalnız sağ üst üçgeni gezilir
  - Köşegen (bir ürünün kendisiyle birlikte geçişi) gereksizdir, alt üçgen simetrik olduğu için tekrar hesaplanmaz. Bu yüzden $j$ döngüsü $i+1$'den başlar.
- Sepet döngüsü kısaltılamaz
  - $k$ sepetleri gezdiği için $j+1$'den başlatılamaz; her sepet incelenmelidir.
- if yerine çarpım
  - İki ikilik değerin ikisinin de 1 olması ancak çarpımlarının 1 olmasıyla mümkündür.
- Birebir eşleme şifrenin zayıf noktasıdır
  - Bir harf hep aynı sayıyla gösterilirse frekans analiziyle kırılabilir; çoklu temsil bunu zorlaştırır.
- MDS'in çözümü tek değildir
  - Aynı uzaklıkları sağlayan sonsuz sayıda koordinat takımı vardır; bunlardan biri seçilir.

## Kısa Tekrar Notları

- S: (sepet ID, ürün ID) listesi, $N \times 2$.
- A: ürün-sepet ikilik matrisi; $A(S(i,2), S(i,1)) = 1$.
- T: ürün-ürün birlikte geçiş sayısı; $T(i,j) \mathrel{+}= A(i,k) \cdot A(j,k)$, $j > i$.
- İkililer için karmaşıklık yaklaşık $\text{ürünN} \cdot \text{ürünN} \cdot \text{sepetN}$ ile orantılıdır.
- Üçlüler: $T(i,j,k) \mathrel{+}= A(i,m) A(j,m) A(k,m)$, $i<j<k$.
- Daha verimli yöntemler için Apriori algoritmasına bakılabilir.
- Şifre: kod = 10 × satır + sütun; tek karşılık frekans analizine açıktır.
- Çoklu temsil: sık harf tabloda çok kez yer alır, konumlarından biri rastgele seçilir.
- Ardışık ikililer: $W(M(i), M(i+1))$ artırılır.
- $\pm K$ komşuluk: $i=1+K..N-K$, $j=-K..K$, sonra kendisiyle sayım düzeltilir.
- Harris: birlikte geçen kelimeler anlamca yakındır.
- MDS: uzaklık matrisi → koordinatlar.

## Detaylı Açıklamalar

- S'ten A'ya geçiş akış diyagramı
  - Diyagram ekrandaki çizime göre (ekrandan, 00:25:00) şöyledir; 3. kısım altyazıdaki anlatımdan kurulmuştur:

```text
BAŞLA
Oku: N
i ← 1, 1, N:            Oku: S(i,1), S(i,2)
i ← 1, 1, ürünN:
    j ← 1, 1, sepetN:   A(i,j) ← 0
i ← 1, 1, N:            A(S(i,2), S(i,1)) ← 1
```

  - A'yı C'de `static` tanımlamak da sıfırlamayı sağlar; static diziler sıfırla başlatılır.
  - Aynı ürün bir sepette birden çok kez olsa da A'ya 1 yazılır, artırılmaz. Adet tutulmak istenirse artırma yapılabilir, ama birlikte geçiş için buna gerek yoktur.
- A'dan T'ye geçiş ve iyileştirmeler
  - $i$ ve $j$ döngüleri ürün çiftlerini, $k$ döngüsü sepetleri gezer. $k$. sepette hem $i$. hem $j$. ürün varsa $T(i,j)$ bir artırılır.
  - Bir öğrenci $k$ döngüsünü $i$ ile $j$ döngülerinin arasına almayı önerdi: $A(i,k)=1$ değilse $j$ döngüsü hiç çalıştırılmaz. Hoca bunun gereksiz kontrolleri azaltacağını ve işi hızlandıracağını kabul etti.
  - Diğer iyileştirme koşulu kaldırıp çarpım kullanmaktır.
- Şifrelemenin kırılması
  - Kısa bir şifreli metinde (örneğin 23 12 15) farklı harflerden oluşan bütün üç harfli kelimeler aday olacağından çözüm tek değildir.
  - Metin uzunsa her sayının frekansı sayılır, dildeki harflerin (boşluk dahil) frekanslarıyla eşleştirilir. Hocaya göre Türkçede en sık harfler A ve E'dir. Birkaç harf tahmin edildikten sonra gerisi kolaylaşır.
- Kelime koordinatları ne işe yarar
  - Koordinatları yakın olan kelimeler anlamca da yakınsa, hiç ortak kelimesi olmayan iki metnin benzerliği bulunabilir. Hocanın örneğinde "Cimbom" ile "Galatasaray", "kazandı" ile "yendi" yakın çıkacağından iki farklı cümlenin benzer anlam taşıdığı anlaşılabilir.
  - Günümüzde bu koordinatlar yapay sinir ağlarıyla üretilmektedir; yapılan iş yine kelimelerin ya da cümlelerin koordinatlarını bulmaktır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
