# Ders 27 Çalışma Özeti

## Genel Konular

- Oturumun yapısı
  - Bu kayıt yeni konu anlatılan bir teori dersi değildir. Dönemin son haftasında yapılan kısa bir açıklama oturumudur: önce son ödevin (kitap önerme sistemi) arkasındaki fikir anlatılmış, sonra ara sınavda sık yapılan algoritmik hatalar üzerinden böl ve yönet ile en küçük elemanı bulma ve hash tablosu boyutu konuları tekrar edilmiştir.
  - Hoca iPad not uygulamasında elle yazarak anlatmıştır.
- Tavsiye (recommendation) sistemleri ve işbirlikçi filtreleme (collaborative filtering)
  - Film ya da kitap öneren sistemler, kullanıcının geçmiş seçimlerine ve ona benzeyen kullanıcıların seçimlerine bakarak öneri yapar.
  - İki temel yaklaşım vardır: kullanıcı tabanlı (user-based, size benzeyen kişilerin beğendiklerini önerme) ve öğe tabanlı (item-based, daha önce seçtiğiniz öğelere benzeyen öğeleri önerme).
  - Ödevde basit olduğu için kullanıcıdan kullanıcıya benzerlik (user-to-user similarity) kullanılır.
- Varyans, kovaryans ve korelasyon
  - Varyans, $n$ örneğin ortalamaya göre ne kadar değiştiğini gösterir: $\mathrm{var}(x)=\frac{1}{n}\sum_{i=1}^{n}(x_i-\bar{x})^2$ (ekrandan, 00:20:00; paydadaki $n$ sözlü anlatımdan). Standart sapmanın karesidir.
  - Ortalamaları aynı olan iki dizinin dağılımları farklı olabilir; bu farkı ortalamaya göre sapma gösterir.
  - Kovaryans iki bilginin birbirine göre (birlikte) nasıl değiştiğini ölçer.
  - Korelasyon pozitif (birlikte artma, örneğin küçük çocuklarda boy ve kilo), sıfır (ilişki yok) ya da negatif (biri artarken öbürü azalır) olabilir.
- Pearson korelasyonu ile kullanıcı benzerliği
  - Pearson katsayısı $-1$ ile $+1$ arasında değişir; $r>0$ pozitif, $r<0$ negatif ilişki, $r=0$ ilişki yok demektir.
  - Formül (ekrandan, 00:35:00):
    $$\mathrm{sim}(a,b)=\frac{\sum_{p\in P}(r_{a,p}-\bar{r}_a)(r_{b,p}-\bar{r}_b)}{\sqrt{\sum_{p\in P}(r_{a,p}-\bar{r}_a)^2}\sqrt{\sum_{p\in P}(r_{b,p}-\bar{r}_b)^2}}$$
  - $a$ ve $b$ iki kullanıcıdır; $P$, $a$ ve $b$'nin ikisinin de okuduğu kitaplardır; $\bar{r}_a$ ve $\bar{r}_b$ kullanıcıların rating ortalamalarıdır.
  - Pay iki kullanıcının kovaryansıdır; payda (iki standart sapma) normalizasyon sağlar.
- Ödevdeki öneri adımları
  - Veri bir tablodur: sütunlarda 8 kitap, satırlarda eğitim kullanıcıları U1–U20 ve yeni kullanıcılar NU1–NU5 (ekrandan, 00:35:00).
  - Her yeni kullanıcının U1–U20 ile benzerliği hesaplanır; $k=3$ için en benzer 3 kişi seçilir (örnekte U5, U7, U2).
  - Yeni kullanıcının okumadığı her kitap için tahmini puan $\mathrm{pred}(NU1,p)$ hesaplanır; en yüksek tahmini puanı alan kitap önerilir (ekrandan, 00:30:00).
  - Eski kullanıcılar eğitim kümesi (train set), yeni kullanıcılar test kümesi (test set) gibidir.
- Böl ve yönet ile en küçük elemanı bulma
  - En küçük elemanı bulmak için diziyi sıralamak gereksizdir; tek geçişli kaba kuvvet (brute force) çözüm $O(n)$'dir, $O(n^2)$ değildir.
  - Böl ve yönet çözümü dizi tek eleman kalana kadar ikiye bölünür, her parçanın en küçük elemanının indisi geri döndürülür ve iki sonuç karşılaştırılır (merge sort mantığı).
- Hash tablosu boyutu
  - Tablo uzunluğu, yerleştirilecek dizi uzunluğunun yaklaşık iki katı alınmalıdır; dizi uzunluğuna eşit ya da çok büyük (örneğin 5 eleman için 100) almak yanlıştır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu ödevde algoritmik bir ağırlık yoktur
  - Yapılacak hesaplar ortalama, farklar ve çarpımlar ile iç içe döngülerdir; hazır veri madenciliği kütüphanesine gerek yoktur.
  - Amaç baştan sona, güncel bir konuda çalışan bir algoritma tasarlayabilmektir.
- Benzerlik kovaryansa dayanır
  - Derin öğrenmeye dayanan modern sistemlerin temelinde de iki bilginin birlikte değişimi (kovaryans) fikri vardır; "göz korkutacak" bir şey yoktur.
- Benzerlik yalnız ortak kitaplar üzerinden ölçülür
  - Yalnız birinin okuduğu kitap üzerinden iki kullanıcının benzerliği ölçülemez.
- En küçük elemanı bulmak için sıralama yapılmaz
  - Bu, birinci sınıfta öğrenilen $O(n)$'lik tek geçişli aramadır; sıralamak ($O(n\log n)$) gereksizdir.
- Böl ve yönet çözümü özyinelemeli olmalıdır
  - Diziyi yalnız bir kez ikiye bölüp iki yarıyı karşılaştırmak fikrin başlangıcıdır; asıl çözüm bunun tek eleman kalana kadar özyinelemeli tekrarlanmasıdır.
  - Böl ve yönetin önemli bir kullanımı paralel programlamadır: iki yarı iki ayrı işlemciye verilir, sonuçlar karşılaştırılır.
- Hash tablosu boyutu
  - Tablo uzunluğu dizi uzunluğunun yaklaşık iki katı olmalıdır.

## Kısa Tekrar Notları

- User-based öneri: sana benzeyenlerin beğendiğini öner. Item-based öneri: senin seçtiklerine benzeyeni öner.
- $\mathrm{var}(x)=\frac{1}{n}\sum (x_i-\bar{x})^2$; kovaryans iki değişkenin birlikte değişimidir.
- Pearson $r\in[-1,+1]$: $r>0$ benzer, $r=0$ ilişkisiz, $r<0$ zıt eğilimli.
- $\mathrm{sim}(a,b)$ hesabında toplam yalnız iki kullanıcının da puan verdiği kitaplar üzerindendir; $\bar{r}_a$, $a$'nın verdiği puanların ortalamasıdır.
- Adımlar: ortalamaları bul, U1–U20 ile benzerlikleri hesapla, en benzer $k=3$ kişiyi seç, okunmamış kitaplar için tahmini puanı hesapla, en yüksek olanı öner.
- En küçük eleman: brute force $O(n)$; sıralama gereksiz.
- `findMin(l, r, A)`: `l == r` ise `l` döner; değilse iki yarıdan gelen indislerden küçük değerli olan döner; `main` içinde `A[findMin(0, N-1, A)]` en küçük elemandır.
- Hash tablosu uzunluğu $\approx 2\times$ dizi uzunluğu.

## Detaylı Açıklamalar

- İşbirlikçi filtreleme
  - Eski öneri sistemleri yalnız kullanıcının kendi davranışını değerlendirirdi. İşbirlikçi filtrelemede kullanıcıya benzeyen kişilerin seçimleri de hesaba katılır. "Benzeyen kişi", aynı türde film izleyen ya da benzer kitaplar seçen kişidir; insanlar tek bir türde izleme yapmadığı için bu benzerlik puan örüntüleri üzerinden ölçülür.
  - Kullanıcı tabanlı yöntemde kullanıcıya en çok benzeyen kişiler bulunur ve onların beğendikleri önerilir. Öğe tabanlı yöntemde kullanıcının seçtiği öğelere benzeyen öğeler önerilir. Hocaya göre büyük platformlar bugün daha çok öğe tabanlı yöntemi kullanır; ödevde basitliği nedeniyle kullanıcı tabanlı yöntem seçilmiştir.
- Varyanstan Pearson katsayısına
  - Varyans bir değişkenin ortalamaya göre yayılımını, kovaryans iki değişkenin birlikte değişimini gösterir. Boy ve kilo gibi iki özellik birlikte artıyorsa pozitif korelasyon, bir ilişki yoksa sıfır korelasyon, biri artarken öbürü azalıyorsa (hocanın örneği: sigara içme ile ömür) negatif korelasyon vardır.
  - Pearson katsayısının payı iki kullanıcının ortak kitaplardaki puanlarının ortalamadan farklarının çarpımlarının toplamıdır, yani kovaryanstır. Payda iki kullanıcının standart sapmalarına benzer terimlerin çarpımıdır ve sonucu $[-1,+1]$ aralığına normalize eder. Benzerlik ne kadar büyükse iki kullanıcı birbirine o kadar benzer.
- Öneri tahmini
  - Hocanın küçük örneğinde yeni kullanıcı NU1, 5 kitaptan 1., 3. ve 4. kitaplara sırasıyla 2, 1 ve 4 puan vermiş, 2. ve 5. kitapları okumamıştır (ekrandan, 00:30:00). NU1'in rating ortalaması dolu gözler üzerinden $(2+1+4)/3 \approx 2{,}33$'tür (ara adım eklendi).
  - Okunmamış kitaplar için tahmin; yeni kullanıcının ortalaması, en benzer $k$ kişinin (U5, U7, U2) NU1 ile benzerlikleri ve bu kişilerin o kitaba verdikleri puanlar kullanılarak hesaplanır. Daha yüksek tahmin alan kitap önerilir. <!-- BELİRSİZ: tahmin formülünün tamamı karelerde görünmüyor; 00:30:00 karesinde yalnız "pred(NU1, p) = r_a" başlangıcı var. -->
  - Hoca sonuçların her yeni kullanıcı için en benzer 3 kişi ve önerilen kitaplarla bir tablo halinde yazdırılmasını, istenirse en benzer kişilerin kitap puanlarının da yazdırılarak benzerliğin gözle kontrol edilmesini önermiştir.
- Böl ve yönet ile en küçük eleman (ekrandan, 00:55:00)
  - Fonksiyon bir aralığın en küçük elemanının değerini değil indisini ("adresini") döndürür. Hoca durma koşulunu önce `l = r` yazmış, `==` olması gerektiğini söyleyerek düzeltmiştir.
  - Tahtadaki kod (ara değişken bildirimleri eklendi, `gcc -Wall` ile derlenip küçük bir diziyle çalıştırıldı; doğru indisi döndürdü):

    ```c
    int findMin(int l, int r, int A[])
    {
        int temp1, temp2;
        if (l == r)
            return l;              /* en küçük elemanın adresi (indisi) */
        else {
            temp1 = findMin(l, (l + r) / 2, A);
            temp2 = findMin((l + r) / 2 + 1, r, A);
            if (A[temp1] <= A[temp2])
                return temp1;
            else
                return temp2;
        }
    }
    /* main içinde: min = findMin(0, N - 1, A);  A[min] en küçük elemandır */
    ```

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
