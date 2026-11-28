# Ders 8 Çalışma Özeti

## Genel Konular

- İyi bir ilişkisel tasarımın özellikleri
  - Normalizasyon, kavramsal (ilişkisel model) tasarımın ikinci bölümüdür. Amaç, ER diyagramından dönüştürülen tabloları veri tekrarını en aza indirecek şekilde "iyi" hale getirmektir. Hoca normalizasyonu tasarımın üzerine sürülen bir "cila"ya benzetti.
  - Derste ders kitabının (Database System Concepts, 7. baskı) 7. bölümünün ilk 31 slaytı işlendi: iyi tasarımın özellikleri, fonksiyonel bağımlılıklar, fonksiyonel bağımlılıklarla parçalama, BCNF ve 3NF (ekrandan, 00:10:00).
- Veri tekrarı ve anomaliler: in_dep örneği
  - instructor ve department tablolarının doğal birleşimi tek tablo olarak tutulursa (in_dep(ID, name, salary, dept_name, building, budget)), birleştirme (join) gerektiren sorgular için cazip görünür (ekrandan, 00:25:00).
  - Sorunlar: aynı bölümün building ve budget değerleri her hoca için tekrar eder (yer kaybı); bir bölümün bütçesi değişince o bölümdeki her satır güncellenmelidir (tutarlılığı korumak zorlaşır); hocası olmayan yeni bir bölüm eklemek için null değer gerekir; bölümün son hocası silinince bölüm bilgisi de kaybolur.
  - Her birleştirme tekrara yol açmaz: sec_class(sec_id, building, room_number) ile section(course_id, sec_id, semester, year) birleştirilince tekrar oluşmaz, çünkü bütün nitelikler section'a bağlıdır (ekrandan, 00:30:00).
- Parçalama (decomposition): yitimli ve yitimsiz
  - Tekrar sorununu gidermenin yolu şemayı parçalamaktır. Parçalar ortak bir nitelik üzerinden doğal birleşimle (natural join) yeniden birleştirilebilmelidir.
  - Yitimli (lossy) parçalama örneği: employee(ID, name, street, city, salary), (ID, name) ve (name, street, city, salary) olarak bölünür. Aynı adlı iki çalışan (Kim) varsa doğal birleşim 2 yerine 4 satır üretir; satır sayısı artar ama hangi Kim'in nerede oturduğu bilgisi kaybolur (ekrandan, 00:35:00).
  - Biçimsel tanım: $R = R_1 \cup R_2$ için $\Pi_{R_1}(r) \bowtie \Pi_{R_2}(r) = r$ ise parçalama yitimsizdir (lossless); $r \subset \Pi_{R_1}(r) \bowtie \Pi_{R_2}(r)$ ise yitimlidir (ekrandan, 00:40:00).
- Fonksiyonel bağımlılık (FD)
  - Anahtar kavramının genelleştirilmiş halidir. $\alpha \to \beta$: $\alpha$ değerleri aynı olan her iki satırda $\beta$ değerleri de aynıdır, yani $t_1[\alpha] = t_2[\alpha] \Rightarrow t_1[\beta] = t_2[\beta]$ (ekrandan, 01:00:00).
  - FD'ler küçük dünyanın (gerçek hayatın) kurallarından gelir: ID kişiyi belirler, her bölümün tek bütçesi ve tek binası vardır (ekrandan, 00:50:00).
  - Legal instance: küçük dünyanın bütün kısıtlarını sağlayan tablo durumu. Tek bir durum bir FD'yi sağlıyor gibi görünebilir (örneğin hiç ad tekrar etmiyorsa name → ID), ama bu FD'nin gerçekte geçerli olduğunu göstermez.
  - Trivial FD: $\beta \subseteq \alpha$ ise $\alpha \to \beta$ önemsizdir (ID, name → ID; name → name) (ekrandan, 01:10:00).
  - $F^+$ (kapanış): F'den mantıksal olarak çıkarılabilen bütün FD'ler. Örnek: $A \to B$ ve $B \to C$ ise $A \to C$.
- Süper anahtar ve aday anahtar
  - K süper anahtardır $\iff K \to R$. K aday anahtardır $\iff K \to R$ ve $K$'nın hiçbir öz alt kümesi $R$'yi belirlemez (minimal süper anahtar) (ekrandan, 01:05:00).
  - FD'ler süper anahtarla ifade edilemeyen kısıtları da ifade eder: in_dep'te dept_name → building ve ID → building beklenir, dept_name → salary beklenmez.
- Yitimsiz parçalama testi
  - $R_1 \cap R_2 \to R_1$ ya da $R_1 \cap R_2 \to R_2$ $F^+$ içindeyse parçalama yitimsizdir; yani ortak nitelikler parçalardan birinin anahtarıdır.
  - Örnek: $R=(A,B,C)$, $F=\{A \to B, B \to C\}$. $(A,B),(B,C)$: kesişim B ve $B \to BC$, yitimsiz. $(A,B),(A,C)$: kesişim A ve $A \to AB$, yitimsiz (ekrandan, 01:15:00).
- Bağımlılık koruma (dependency preservation)
  - Her FD parçalamadan sonra tek bir tabloda denetlenebiliyorsa parçalama bağımlılığı korur. Aksi halde denetim için birleşim ya da kartezyen çarpım gerekir ve her güncellemede bu denetim maliyetlidir (ekrandan, 01:20:00).
  - dept_advisor(s_ID, i_ID, dept_name) örneği, FD'ler $i\_ID \to dept\_name$ ve $s\_ID, dept\_name \to i\_ID$: hiçbir parçalama ikinci FD'nin bütün niteliklerini tek tabloda tutamaz, bu yüzden parçalama bağımlılığı koruyamaz (ekrandan, 01:45:00).
- Boyce-Codd normal formu (BCNF)
  - $F^+$'daki her $\alpha \to \beta$ için ya FD trivialdir ya da $\alpha$ süper anahtardır.
  - in_dep BCNF değildir: dept_name → building, budget ama dept_name süper anahtar değildir.
  - BCNF parçalama kuralı: BCNF'yi bozan $\alpha \to \beta$ için $R$, $(\alpha \cup \beta)$ ve $(R - (\beta - \alpha))$ olarak bölünür. in_dep → (dept_name, building, budget) ve (ID, name, dept_name, salary) (ekrandan, 01:55:00).
  - $R=(A,B,C)$, $F=\{A \to B, B \to C\}$: B süper anahtar olmadığı için BCNF değildir. Parçalama $(B,C)$ ve $(A,B)$; yitimsiz ve bağımlılık korunur. $(A,B),(A,C)$ ise yitimsizdir ama $B \to C$ korunmaz (ekrandan, 02:00:00).
  - BCNF parçalaması her zaman yitimsizdir ama her zaman bağımlılık koruyamaz: dept_advisor BCNF değildir ($i\_ID$ süper anahtar değil), parçalanınca (s_ID, i_ID) ve (i_ID, dept_name) elde edilir ve $s\_ID, dept\_name \to i\_ID$ korunmaz (ekrandan, 02:05:00).
- Üçüncü normal form (3NF)
  - $F^+$'daki her $\alpha \to \beta$ için şunlardan en az biri sağlanır: FD trivialdir; $\alpha$ süper anahtardır; $\beta - \alpha$ içindeki her nitelik bir aday anahtarın içindedir (nitelikler farklı aday anahtarlarda olabilir) (ekrandan, 02:10:00).
  - Hocanın yorumu: üçüncü koşul, asal olmayan (hiçbir anahtara girmeyen) nitelikler arasında geçişli bağımlılık olmamasına karşılık gelir.
  - BCNF olan her şema 3NF'dir. Üçüncü koşul, bağımlılık korumayı sağlamak için BCNF'nin en küçük gevşetilmesidir.
  - dept_advisor örneği: aday anahtarlar {s_ID, dept_name} ve {s_ID, i_ID}. BCNF değildir ama 3NF'dir, çünkü $i\_ID \to dept\_name$ için $\{dept\_name\} - \{i\_ID\} = \{dept\_name\}$ bir aday anahtarın içindedir (ekrandan, 02:15:00).
  - 3NF'de tekrar: $R=(J,K,L)$, $F=\{JK \to L, L \to K\}$ 3NF'dir ama BCNF değildir. Örnek durumda $(l_1,k_1)$ çifti tekrar eder ve $J$ değeri olmayan $(l_2,k_2)$ ilişkisi için null gerekir (ekrandan, 02:20:00).
- Türkçe ek sunu (hocanın kendi ders notları)
  - Ekleme, silme ve güncelleme anomalileri; EMP_DEPT ve EMP_PROJ örnekleri (ekrandan, 02:25:00).
  - Armstrong kuralları: dönüşlülük, arttırma, geçişlilik; birleşim ve ayrıştırma kuralları.
  - Kanonik örtü (minimal FD kümesi): artık (türetilebilen) bağımlılıklar atılır, sol taraflar birbirinden farklı olur. Aday anahtar bulmada kullanılır.
  - Normal formların özeti: 1NF (yalın/atomik değerler), 2NF (asal olmayan nitelikler anahtarlara tam bağımlı), 3NF (asal olmayan nitelikler anahtarlara geçişli bağımlı değil), BCNF (bütün belirleyenler anahtar) (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Normalizasyon bir "cila"dır
  - ER'den dönüştürülen tablolar normalizasyonla daha güvenli hale getirilir. Küçük, kişisel bir veritabanında yapılmasa da büyük tehlike olmayabilir; gerçek bir sistemde yapılması zorunlu olabilir.
- Yitimli parçalamada satır sayısı artar ama bilgi kaybolur
  - Kim örneğinde birleşim daha çok satır verir, "daha çok bilgi" gibi görünür, ama gerçek adres bilgisi kaybolmuştur. Bu, aynı adlı kişilerin olabildiği gerçek hayatta beklenen bir durumdur.
- FD'ler küçük dünyadan gelir
  - Bağımlılıklar tablonun anlık durumuna bakılarak değil, gerçek hayat kurallarına göre belirlenir. Anlık durumda name → ID geçerli görünse bile gerçekçi değildir.
  - dept_name → building geçerlidir, ama building → dept_name değildir: aynı binada (Watson) birden çok bölüm (fizik, biyoloji) olabilir.
- BCNF ile 3NF arasındaki denge
  - BCNF en katı formdur, veri bütünlüğü açısından en iyisidir, ama bazı parçalamalarda bağımlılık korunamaz ve FD denetimi birden çok tabloya dağılır.
  - 3NF her zaman hem yitimsiz hem bağımlılık koruyan bir parçalamaya izin verir; bedeli tekrar ve null değerlerdir.
- Kapsam
  - Derste yalnız fonksiyonel bağımlılıklar ve BCNF/3NF işlendi. Çok değerli bağımlılıklar (multivalued dependencies), 4NF ve 5NF ile parçalama algoritmaları kapsam dışı bırakıldı.
- Aday anahtarların bulunması
  - Küçük tablolarda aday anahtarlar teker teker, ikili, üçlü nitelik grupları denenerek bulunabilir; karmaşık şemalarda kanonik örtüden yararlanılır. Aday anahtarlar 3NF denetiminde gerekir.

## Kısa Tekrar Notları

- Veri tekrarı: yer kaybı, güncelleme tutarsızlığı, null zorunluluğu, silmede istenmeyen bilgi kaybı.
- Yitimsiz parçalama: $\Pi_{R_1}(r) \bowtie \Pi_{R_2}(r) = r$. Test: $R_1 \cap R_2$, $R_1$ ya da $R_2$'yi belirliyor mu?
- FD: $t_1[\alpha] = t_2[\alpha] \Rightarrow t_1[\beta] = t_2[\beta]$. Trivial: $\beta \subseteq \alpha$.
- Süper anahtar: $K \to R$. Aday anahtar: minimal süper anahtar.
- Bağımlılık koruma: her FD tek bir tabloda denetlenebilmeli.
- BCNF: her trivial olmayan $\alpha \to \beta$ için $\alpha$ süper anahtar. Parçalama: $(\alpha \cup \beta)$ ve $(R - (\beta - \alpha))$.
- 3NF: BCNF koşulları ya da $\beta - \alpha$'daki her nitelik bir aday anahtarda.
- BCNF $\Rightarrow$ 3NF $\Rightarrow$ 2NF $\Rightarrow$ 1NF.
- BCNF: her zaman yitimsiz, bağımlılık korumayabilir. 3NF: yitimsiz ve bağımlılık koruyan parçalama her zaman mümkün; tekrar ve null olabilir.
- dept_advisor(s_ID, i_ID, dept_name): BCNF değil, 3NF.

## Detaylı Açıklamalar

- in_dep örneği neden kötü bir tasarım?
  - Ders kitabındaki üniversite veritabanında instructor ve department ayrı varlıklar, dolayısıyla ayrı tablolardır. Bu ikisini sık birlikte sorguladığımız için tek tabloda tutmak (in_dep) birleştirme maliyetini ortadan kaldırır. Ancak Comp. Sci. bölümünde Katz, Srinivasan ve Brandt varsa, bölümün Taylor binası ve 100000 bütçesi üç kez yazılır (ekrandan, 00:25:00). Bütçe 200000 yapılmak istenirse bölümdeki hoca sayısı kadar satır güncellenir ve bunların hepsinin birlikte değişmesi sağlanmalıdır. Hocası olmayan yeni bir bölüm eklemek için ID, name, salary alanlarına null yazmak gerekir; tablonun anahtarı ID olduğu için bu da mümkün olmaz. Tersine, bir bölümün tek hocası ayrılıp satırı silinince bölümün bina ve bütçe bilgisi de silinir. Tek kazanç birleştirmeden kurtulmaktır; bedeli veri bütünlüğü sorunlarıdır.
- Yitimli parçalamanın mekanizması
  - employee tablosu (ID, name) ve (name, street, city, salary) olarak bölünür. Ortak nitelik name'dir. 57766 ve 98776 numaralı iki çalışanın adı Kim'dir; biri Main/Perryridge/75000, diğeri North/Hampton/67000 bilgisine sahiptir. Parçalar name üzerinden doğal birleşimle birleştirilince her Kim, iki adres satırıyla eşleşir ve 4 satır çıkar (ekrandan, 00:35:00; python ile 4 satır doğrulandı). Asıl sorun, name'in ikinci parçanın anahtarı olmamasıdır. Bu nedenle parçalamada ortak nitelik grubunun parçalardan birini fonksiyonel olarak belirlemesi gerekir.
- Yitimsiz parçalama örneği
  - $R=(A,B,C)$ şemasının $\{(\alpha,1,A),(\beta,2,B)\}$ durumu $(A,B)$ ve $(B,C)$ olarak bölünür. B sütununda tekrar olmadığı için doğal birleşim özgün tabloyu aynen verir. <!-- BELİRSİZ: Bu slaytın karesi yoktu; değerler altyazıdan (00:42:19) alındı. -->
- FD tanımının bir tablo üzerinde denetlenmesi
  - $r(A,B)$ durumu $\{(1,4),(1,5),(3,7)\}$ olsun (ekrandan, 01:00:00). A=1 olan iki satırda B değerleri 4 ve 5'tir, dolayısıyla $A \to B$ sağlanmaz. B değerleri hiç tekrar etmediği için $B \to A$'yı bozan bir durum yoktur, bu durumda $B \to A$ sağlanır. Hoca, (4,1) satırının yanında (4,2) gibi bir satır olsaydı $B \to A$'nın da sağlanmayacağını ekledi.
- BCNF parçalaması adım adım
  - in_dep için BCNF'yi bozan FD dept_name → building, budget'tır: $\alpha$ = dept_name, $\beta$ = building, budget. Birinci parça $\alpha \cup \beta$ = (dept_name, building, budget). $\beta - \alpha$ = (building, budget) olduğundan ikinci parça $R - (\beta - \alpha)$ = (ID, name, dept_name, salary). Ortak nitelik dept_name ikinci tabloda yabancı anahtar olur. İki parçada da belirleyenler anahtar olduğu için BCNF sağlanır (ekrandan, 01:55:00).
  - $R=(A,B,C)$, $F=\{A \to B, B \to C\}$ örneğinde A'nın kapanışı ABC'dir, A anahtardır. $B \to C$'de B süper anahtar değildir, BCNF bozulur. $\alpha \cup \beta$ = (B,C), $R - (C)$ = (A,B). Kesişim B ve $B \to BC$ olduğu için yitimsiz; $A \to B$ birinci, $B \to C$ ikinci tabloda denetlenebildiği için bağımlılık korunur.
- dept_advisor ve 3NF
  - Küçük dünya: bir hoca tek bir bölüme aittir; bir öğrencinin bir bölümde en fazla bir danışmanı vardır, çift anadal yapan öğrencinin farklı bölümlerde farklı danışmanları olabilir. Aday anahtarlar {s_ID, dept_name} ve {s_ID, i_ID}'dir; (i_ID, dept_name) süper anahtar değildir, çünkü bir hoca aynı bölümde birçok öğrenciye danışmanlık yapar (python ile doğrulandı). $i\_ID \to dept\_name$'de i_ID süper anahtar olmadığı için BCNF yoktur. BCNF parçalaması (i_ID, dept_name) ve (s_ID, i_ID) verir ama $s\_ID, dept\_name \to i\_ID$ hiçbir tabloda tek başına denetlenemez. 3NF açısından ise $\beta - \alpha$ = dept_name bir aday anahtarın içinde olduğundan şema 3NF'dir ve parçalamaya gerek yoktur.
- Kanonik örtü örneği
  - Hocanın Türkçe sunusunda verilen FD kümesinden artık bağımlılıklar atıldı: $B \to C$ ve $C \to A$ geçişlilikle $B \to A$'yı verdiği için $B \to A$ atılır; $BC \to A$ da bu FD'lerden türetilebildiği için atılır. Geriye kalan kanonik örtü $\{B \to C, C \to A\}$'dır. <!-- BELİRSİZ: Bu anın karesi yoktu; verilen FD kümesi altyazıdan (02:30:45-02:33:07) çıkarıldı, ekrandaki küme tam doğrulanamadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
