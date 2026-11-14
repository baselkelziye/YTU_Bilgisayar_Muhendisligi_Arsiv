# Ders 6 Çalışma Özeti

## Genel Konular

- Kavramsal tasarımın tekrarı
  - Kavramsal tasarım küçük dünyadaki kısıtları kâğıda, ilişkisel model dönüşümleriyle de makineye aktarmaktır. Bu derste yalnız veri modelleme (hangi veriler, hangi bağıntılar) ele alınır; fonksiyonel modelleme ve yetkilendirme sistem analizi konusudur.
  - Mantıksal tasarımın bir kez yapılıp çok zorda kalınmadıkça değişmemesi umulur; bu yüzden ileride olabilecek değişiklikleri (örneğin bir hocanın birden çok bölüme ait olması) baştan düşünmek profesyonelce bir yaklaşımdır. Fiziksel tasarım ise veri karakteristiğine göre değişmeye açıktır.
  - Tasarımın iki problemi fazlalık ve eksikliktir; hocaya göre üçüncü madde olarak veri kaybı da eklenebilir.
- Üçlü (ternary) bağıntılar ve ikili bağıntılara dönüştürme (ekrandan, 00:25:40)
  - Bazı durumlarda bağıntıyı ikili olmayan biçimde göstermek "daha uygundur" (more convenient); ikili bağıntılarla göstermek imkânsız değildir.
  - `proj_guide` (A: `project`, B: `instructor`, C: `student`) için iki ikili gösterim yolu vardır:
    - Yapay bir `E` (`proj_guide`) varlık seti ve `R_A`, `R_B`, `R_C` ikili bağıntıları: `E` zayıf varlıktır, bağıntıları çift çizgilidir; üçlü bağıntıya denktir.
    - Yalnız `R_AB`, `R_AC`, `R_BC` ikili bağıntıları: Üçlü bağıntıya denk değildir; birleştirmelerle (join) bilgi her zaman geri elde edilemez, bilgi kaybı olabilir.
- Kardinalite gösterimleri
  - Ok ve düz çizgi gösterimi ile `l..h` (minimum..maksimum) gösterimi aynı bilgiyi verir: `instructor` tarafında `0..*`, `student` tarafında `1..1`, ok ve çift çizgiyle gösterilen bire çok, öğrenci tarafı tam katılımlı bağıntıya denktir.
  - İlk değer katılımı (0 kısmi, 1 tam), ikinci değer kardinaliteyi anlatır. Maksimum değer, örneğin bir hocanın kapasitesi, küçük dünyadan aktarılabilir.
  - Hoca, paylaştığı ek dokümandaki UML notasyonunun bu gösterime ters olduğunu, karıştırılmaması gerektiğini söyledi.
- Üçlü bağıntıda oklar
  - Karışıklığı önlemek için üçlü bağıntıda birden fazla ok kullanılmaz (kitap: "we outlaw more than one arrow").
  - Tek ok (yalnız B'ye) belirsizlik taşımaz: Bir `(a, c)` çifti en fazla bir `b` ile eşleşir.
  - İki ok (B ve C'ye) iki farklı biçimde yorumlanabilir; bu yüzden böyle bir kısıt üçlü bağıntıyla değil, yapay varlık setli ikili gösterimle ifade edilmelidir.
- Bağıntı setlerinin birincil anahtarı
  - Çoka çok: İki tarafın birincil anahtarlarının birleşimi.
  - Bire çok / çoka bir: "Çok" tarafının birincil anahtarı.
  - Bire bir: İki taraftan herhangi birinin birincil anahtarı.
- Zayıf varlık ve ER'den tabloya dönüşüm
  - Güçlü varlık seti doğrudan tabloya dönüşür: `course(course_id, title, credits)`.
  - Zayıf varlık seti, güçlü varlığın birincil anahtarı ve ayırt edicisiyle: `section(course_id, sec_id, semester, year)`.
  - Bileşik niteliklerin en alt bileşenleri kullanılır; türetilmiş nitelik (`age`) saklanmaz, hesaplanır.
  - Çok değerli nitelik ayrı tabloya gider: `inst_phone(ID, phone_number)`; anahtar ikisi birden.
  - Çoka çok bağıntı için mutlaka ayrı tablo kurulur; bire çok bağıntıda "bir" tarafın anahtarı "çok" tarafına yabancı anahtar olarak taşınır, ya da ayrı tablo kurulur.
- Genişletilmiş ER (EER): Özelleştirme ve genelleştirme
  - Özelleştirme (specialization) bir varlık setini alt varlık setlerine ayırır; genelleştirme (generalization) aynı yapıya aşağıdan yukarı bakıştır. Alt setlerin kendine özgü nitelikleri olur (`employee.salary`, `student.tot_cred`), böylece boş (null) değerler ortadan kalkar.
  - Örtüşen (overlapping) özelleştirme: Bir kişi hem öğrenci hem çalışan olabilir. Ayrık (disjoint) özelleştirme: Bir çalışan hem hoca hem sekreter olamaz.
  - Tam (total) özelleştirmede üst setteki her varlık bir alt sette olmalıdır; kısmi (partial) özelleştirmede olmayabilir.
  - Şemaya dönüştürme (ekrandan, 01:17:30):
    - Yöntem 1: Üst seviye için bir şema, her alt seviye için üst seviyenin birincil anahtarı ve yerel niteliklerle bir şema: `person(ID, name, street, city)`, `student(ID, tot_cred)`, `employee(ID, salary)`. Dezavantaj: Bir çalışanın bilgisi için iki ilişkiye erişmek gerekir.
    - Yöntem 2: Her varlık seti için yerel ve miras alınan bütün niteliklerle bir şema: `student(ID, name, street, city, tot_cred)`, `employee(ID, name, street, city, salary)`. Dezavantaj: Hem öğrenci hem çalışan olan kişilerin `name`, `street`, `city` bilgisi tekrar edebilir.
- Birleştirme (aggregation) (ekrandan, 01:42:30)
  - Bağıntılar arasında bağıntı gerektiğinde kullanılır. Örnek: `proj_guide` üçlü bağıntısının bazı kombinasyonları değerlendirilir (`evaluation`).
  - Dörtlü bağıntı ya da üçlünün yanına ayrı bir dörtlü bağıntı fazlalık getirir. Çözüm: `proj_guide` birleştirilmiş bir bağıntı, yani daha üst seviye bir "varlık seti" gibi düşünülür ve `eval_for` ile `evaluation`'a bağlanır.
  - Şema: `eval_for` tablosu `proj_guide`'ın birincil anahtarlarını ve `evaluation`'ın anahtarını içerir. Birleştirme `eval_for`'a tam katılıyorsa `proj_guide` şeması fazlalıktır.
- ER diyagramlarında yaygın hatalar (ekrandan, 01:50:30)
  - Bağıntıdan çıkarılabilen bir niteliği (örneğin `stud_dept` varken `student.dept_name`) varlığa yazmak hatadır; yabancı anahtar ancak tabloya dönüşümün sonucu olarak gelir.
  - `stud_section` bağıntısına `assignment` ve `marks` nitelikleri koymak hatadır: Bir öğrenci-şube çifti için yalnız tek bir ödev saklanabilir. Doğru alternatifler: (c) `section`'a `sec_assign` ile bağlı zayıf `assignment` varlığı ve `marks` nitelikli `marks_in` bağıntısı; (d) `stud_section` üzerinde çok değerli, bileşik `{assignment_marks}` niteliği.
- Varlık mı, nitelik mi? Varlık mı, bağıntı mı?
  - Telefonu varlık seti yapmak, telefon numarası hakkında ek bilgi (konum vb.) ve birden çok numara saklamaya izin verir.
  - `takes` bağıntısı yerine `registration` varlık seti kullanılabilir; doğrudur ama daha az özdür. `registration`'ın başka bağıntıları varsa bu tercih gerekli olabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kuralları ezberlemek yerine içini anlamak
  - Örneğin bire çok bağıntıda yabancı anahtarın neden "çok" tarafına gittiği, örnek veri (`I1 D1`, `I2 D1`, `I3 D1`) kurularak görülmelidir: "Bir" tarafa taşınsaydı `D1` satırına birden çok hoca yazmak gerekirdi.
- Çok değerli nitelik ve dizi (array)
  - `phone1`, `phone2`, `phone3` sütunları iyi tasarım değildir: Çoğu hoca için boş kalırlar, bazı hocalar için yetmezler.
  - PostgreSQL gibi sistemler dizi tipini destekler; bu yüzden saf ilişkisel değil, nesne-ilişkisel (object-relational) sistemlerdir. Dizi 1NF'yi bile sağlamaz, ama daha verimli olabilir. Ayrı tablo, saf ilişkisel model için geçerli yoldur.
  - `inst_phone` tablosunun anahtarı yalnız `phone_number` olamaz: Örneğin aynı evde oturan iki hoca aynı telefonu kullanabilir.
- Bire çok bağıntıda ayrı tablo ne zaman?
  - "Çok" tarafı tam katılımlıysa (`inst_dept`) yabancı anahtar taşınır; boş değer olmaz.
  - Kısmi katılım varsa (`advisor`, öğrencilerin bir kısmının danışmanı yoksa) yabancı anahtar çok sayıda null üretir; ayrı tablo daha iyi olabilir. Ama ayrı tablo yeni bir dosya ve join maliyeti demektir; bu bir ödünleşimdir (trade-off).
- Kavramsal tasarımda yabancı anahtarı varlığa yazmayın
  - `instructor` varlığına `dept_name` yazmak hatadır; o bilgi bağıntıda vardır.

## Kısa Tekrar Notları

- Üçlü bağıntı, yapay zayıf varlık + üç ikili bağıntıyla denk gösterilir; yalnız üç ikili bağıntı denk değildir.
- Üçlü bağıntıda en fazla bir ok.
- `l..h`: ilk değer katılım, ikinci değer kardinalite.
- Bağıntı anahtarı: çoka çok iki anahtar, bire çok "çok" tarafı, bire bir herhangi biri.
- Zayıf varlık tablosu = güçlünün anahtarı + ayırt edici.
- Çok değerli nitelik ayrı tablo, anahtar (ID, değer).
- Çoka çok bağıntı her zaman ayrı tablo; bire çok genelde "çok" tarafına yabancı anahtar.
- Özelleştirme: örtüşen/ayrık, tam/kısmi; şemaya iki yöntem.
- Tam ve ayrık özelleştirmede üst seviye tablosuna gerek kalmayabilir.
- Birleştirme: bağıntılar arasında bağıntı; fazlalığı önler.
- Bağıntıya tek değerli nitelik olarak çok değerli bilgi koymak hatadır.

## Detaylı Açıklamalar

- **Üçlü bağıntının ikili gösterimi** (ekrandan, 00:25:40). Slaytta üç gösterim yan yana: (1) `instructor`, `student`, `project` arasında `proj_guide` üçlü bağıntısı; (2) ortada yapay `E` varlık seti, `E`'yi A, B, C'ye bağlayan `R_A`, `R_B`, `R_C`; (3) A, B, C arasında üç ikili bağıntı `R_AB`, `R_AC`, `R_BC`. Hoca (1) ile (2) arasına eşittir, (1) ile (3) arasına "eşit değildir" koydu. (2)'de `E`'nin her elemanı A, B, C'den birer eleman içerir; `(P1, I1, S1)` aynen üretilebilir. (3)'te ise hangi öğrencinin hangi projede hangi hocayla çalıştığı bilgisi ikili çiftlerden her zaman geri çıkarılamaz.
- **İki oklu üçlü bağıntı örneği.** "Bir öğrenci bir projede bir hocayla çalışabilir" kısıtında `(S1, P1, I1)` varken `(S1, P2, I1)` görülmez; ama `(S1, P2, I2)` görülebilir mi? Bu, iki ok gösteriminde belirsiz kalır. Hoca, kitabın konuyu açık bıraktığını, kendi kanaatinin bu tür kısıtları yapay varlıklı gösterimle ifade etmek olduğunu söyledi.
- **Bire çok bağıntı için ayrı tablo.** `inst_dept` için ayrı tablo kurulsaydı şeması `inst_dept(ID, dept_name)`, anahtarı `ID` olurdu: `(I1, D1)` varken `(I1, D2)` olamaz, ama `D1` birçok kez geçer. 1000 hocadan 500'ünün bölümü yoksa yabancı anahtar yaklaşımında 500 null değer olur; ayrı tabloda ise yalnız bölümü olan 500 hoca bir satır olarak yer alır.
- **Özelleştirmenin şemaya dönüşümü.** Hoca dört kombinasyonu (örtüşen-tam, örtüşen-kısmi, ayrık-tam, ayrık-kısmi) değerlendirmeyi önerdi. Tam ve ayrık özelleştirmede `person` tablosuna hiç gerek yoktur: `student(ID, name, street, city, tot_cred)` ve `employee(ID, name, street, city, salary)` tabloları her kişiyi bir kez saklar, veri tekrarı olmaz. Kısmi özelleştirmede alt sette olmayan kişiler için Yöntem 1'deki `person` tablosu gerekir.
- **Birleştirmede şema seçenekleri.** Bütün `proj_guide` kombinasyonları değerlendiriliyorsa yalnız `eval_for(s_ID, project_id, i_ID, evaluation_id)` yeterlidir ve `proj_guide` şeması fazlalıktır. Yalnız bir kısmı değerlendiriliyorsa ayrıca `proj_guide` tablosu tutulur ve kombinasyon iki tabloda tekrar eder. Hoca, slaytta olmayan bir seçenek olarak `proj_guide` için yapay bir anahtar (örneğin sıra numarası) tanımlamayı önerdi; `eval_for` bu anahtarı yabancı anahtar olarak kullanır ve üçlü kombinasyon tekrar etmez.
- **Ödev notları örneği** (ekrandan, 01:50:30). Hocanın ekrandaki örnek verisi: `S1, Sec1, A1, 10`; `S1, Sec2, A1, 30`; `S1, Sec2, A2, 30`; `S2, Sec1, A1, 20`. `stud_section` bağıntısının anahtarı öğrenci ve şube olduğu için bir öğrenci-şube çiftine yalnız bir ödev yazılabilir; oysa `S1, Sec2` için iki ödev vardır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
