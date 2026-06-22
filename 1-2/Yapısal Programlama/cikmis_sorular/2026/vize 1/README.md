# 2025-2026 Yapısal Programlama Vize 1 Sınav Soruları

Bu klasörde Yapısal Programlama dersinin 2026 yılı 1. vize sınavında çıkmış soruları ve bu soruların kod çözümleri yer almaktadır.

> [!WARNING]
> Bu döküman sınavdaki tüm soruları kapsamamaktadır, sadece akılda kalan soruları kapsamaktadır.

---

## 📄 Sınav Soruları PDF Dosyası
Sınav sorularının yer aldığı orijinal formatta derlenmiş PDF dosyasına aşağıdaki bağlantıdan erişebilirsiniz:
- [Vize 1 Soruları (PDF)](./vize1.pdf)

---

## 📌 Sınav Soruları

### Soru 1: Çıktı Analizi
Aşağıdaki C programının ekran çıktısını yazınız (Varsa derleme veya çalışma zamanı hatalarını belirtiniz).

```c
#include <stdio.h>
void printfxy(int);
int x=8;
static int j=2,y=4;

int main(){
    int x,y,k;
    for(x=0;x<2;x++){
        y=3,k=0;
        printf("%d %d %d", x, y, j);
        printfxy(k);
    }
    return 0;
}

void printfxy(int a){
    static int y=12;
    y++;
    printf("%d %d %d %d", x, y, --j, a++);
}
```
> [!NOTE]
> Bu sorunun çözümü ve analizi için **[Soru 1 Klasörüne](./soru%201/ramazan_pirinc/)** göz atabilirsiniz.

---

### Soru 2: Yapı (Struct) Tanımlama ve Sıralama
Aşağıdaki `STUDENT` yapısı verilmiştir:
```c
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} STUDENT;
```

Bu yapıyı kullanarak aşağıdaki işlevleri gerçekleştiren C programını yazınız:
1. `main` fonksiyonu içerisinde kullanıcıdan `n` adet öğrenci sayısı alınıp dinamik bellek tahsisi (`malloc`) yapılarak öğrenci bilgileri alınmalıdır.
2. `sort_by_name` fonksiyonu ile öğrenciler isimlerine (`name`) göre alfabetik olarak sıralanmalıdır. (Sıralama esnasında tüm yapı takas edilmelidir).
3. `print_Students` fonksiyonu ile sıralanmış öğrenci listesi ekrana yazdırılmalıdır.
4. Program sonunda tahsis edilen bellek serbest bırakılmalıdır.

> [!NOTE]
> Bu sorunun çalışan C kodu ve çözümü için **[Soru 2 Klasörüne](./soru%202/ramazan_pirinc/)** göz atabilirsiniz.

---

### Soru 3: Dinamik Matris ve Yeniden Boyutlandırma (realloc)
`n` adet öğrencinin seçtiği kursları tutmak için başlangıçta `n x 2` boyutunda iki boyutlu dinamik bir matris oluşturulacaktır. Kullanıcıdan her öğrencinin kaç adet kurs seçeceği bilgisi alınacaktır:
1. Eğer öğrenci 2'den fazla kurs seçiyorsa, ilgili öğrenci satırı `realloc` kullanılarak genişletilecektir.
2. Öğrenci kurs bilgileri kullanıcıdan alınarak matrise doldurulacaktır.
3. Matris ekrana düzgün bir şekilde yazdırılacaktır.
4. Program sonunda tahsis edilen tüm dinamik bellek alanları serbest bırakılacaktır.

Bu işlemleri gerçekleştiren C programını yazınız. (Yardımcı fonksiyon prototipleri: `CreateMatrix`, `ExtendandFill`, `PrintMatrix`, `FreeMemory`).

> [!NOTE]
> Bu sorunun çalışan C kodu ve çözümü için **[Soru 3 Klasörüne](./soru%203/ramazan_pirinc/)** göz atabilirsiniz.

---

## 💻 Çözüm Kodları
Her sorunun çalışan C kodu çözümü, ilgili soru numarasına ait alt klasörlerde `kod.c` adıyla bulunmaktadır:
- 💻 **Soru 1 Çözümü:** [Soru 1 Kod Klasörü](./soru%201/ramazan_pirinc/)
- 💻 **Soru 2 Çözümü:** [Soru 2 Kod Klasörü](./soru%202/ramazan_pirinc/)
- 💻 **Soru 3 Çözümü:** [Soru 3 Kod Klasörü](./soru%203/ramazan_pirinc/)
