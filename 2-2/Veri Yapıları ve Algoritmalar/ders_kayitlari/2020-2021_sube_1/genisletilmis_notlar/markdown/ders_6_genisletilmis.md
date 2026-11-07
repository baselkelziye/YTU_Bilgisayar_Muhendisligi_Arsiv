# Ders 6 Genişletilmiş Notu: Yer Karmaşıklığı Hatırlatması (Kısa Kayıt)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yer Karmaşıklığı
- 2. Akış Diyagramı ve Kod

## 1. Yer Karmaşıklığı

Bu kısa kayıtta konu anlatımı yapılmadı. Hoca yalnızca yer karmaşıklığı (space complexity) kavramını kısaca hatırlattı.

> **Hocanın vurgusu:** Bir algoritma tasarlandıktan sonra hem işlem karmaşıklığı hem de yer karmaşıklığı hesaplanmalıdır.

### 1.1 İşlem Karmaşıklığından Farkı

Hocaya göre yer karmaşıklığının işlem karmaşıklığından bir farkı yoktur. Burada da $n$ giriş bilgisine bağlı olarak, yapılan algoritma sonunda ne kadar yer kullanıldığı hesaplanır.

### 1.2 Hocanın Örneği

Hocanın verdiği örnek sözlüydü ve tek adımlıydı:

- **Verilen:** $n$ elemanımız var.
- **Kullanılan yer:** Bir dizilik yer.
- **Sonuç:** Yer karmaşıklığı $n$'dir.

Hoca bu örnekten sonra iki hesap arasında çok büyük bir fark olmadığını yineledi.

> **Ek bilgi (derste anlatılmadı):** Bu sonuç büyük-O gösterimiyle $O(n)$ diye yazılır. Derste kullanılan yerin ek yer olup olmadığı ayrımı yapılmadı. Yer karmaşıklığı genellikle girişin dışında kullanılan ek bellek (auxiliary space) için verilir. Girişi saklayan dizi de sayılırsa her algoritma en az $n$ mertebesinde yer kullanmış olur.

### 1.3 Yeri ve Zamanı Verimli Kullanmak

Hoca, bir problemi çözerken yerin olabildiğince verimli kullanılmasını istedi. Bir çözümün değerlendirilmesinde zamanın ne kadar verimli kullanıldığı da etkilidir.

## 2. Akış Diyagramı ve Kod

<!-- BELİRSİZ: Öğrenci sorusu altyazıda bozuk ("kodu sorulacak akış çeşitli"). Sorunun kod ve akış diyagramı hakkında olduğu hocanın cevabından anlaşılıyor. -->

**Soru:** Çözüm kod olarak mı, akış diyagramı olarak mı yazılmalı?

**Cevap:** Hoca, aslında akış diyagramı yapıp sonra C'ye geçmenin daha doğru olduğunu söyledi.

## Dersin Toparlaması

Yer karmaşıklığı, işlem karmaşıklığıyla aynı mantıkla hesaplanır: $n$ giriş bilgisine bağlı olarak ne kadar yer kullanıldığına bakılır. $n$ eleman için bir dizilik yer kullanan bir algoritmanın yer karmaşıklığı $n$'dir. Bir çözümde hem yer hem zaman verimli kullanılmalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
