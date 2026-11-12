# Ders 1 Genişletilmiş Notu: Derse Giriş: Kapsam, Ders Akışı ve Hedefler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kapsamı ve ön bilgi
- 2. Ders akışı: beş bölüm
- 3. Modern mimari yaklaşımlar
- 4. Ders hedefleri
- 5. Haftalık konu planı
- 6. Mimari problem örneği ve tasarımı öğrenme yolu
- 7. Agile ile mimari tasarımın farkı ve dersin seviyesi
- 8. Kaynak kitaplar
- Örnek Sorular

Bu kayıt dönemin ilk dersidir ve kısa bir tanıtım dersidir. Derste yeni bir teknik konu işlenmez; dersin kapsamı, akışı, hedefleri ve kaynakları anlatılır. Bu not yalnız bu akademik kısmı aktarır.

## 1. Dersin kapsamı ve ön bilgi

BLM5126 İleri Yazılım Mimarisi, yüksek lisans seçimlik ders havuzunda yer alan bir derstir (ekrandan, 00:08:50 ve 00:17:20).

> **Ders sonrası not:** Altyazıda dersin adı iki yerde (00:01:26 ve 00:17:42) "İleri Yazılım Mühendisliği" olarak geçer. Slayt kapağındaki ad "İleri Yazılım Mimarisi"dir. Bu fark büyük olasılıkla bir dil sürçmesi ya da Whisper hatasıdır.

### 1.1 Beklenen ön bilgi

Slaytta yazılı ön koşullar şunlardır (ekrandan, 00:17:20):

- Yazılım mühendisliği temelleri ve/veya sektörde yazılım geliştirme deneyimi.
- En azından bir dilde program kodlayabilme.

Hoca bunların resmî değil, "yazılı olmayan" ön koşullar olduğunu, ama dersin bu bilgiyi varsaydığını söyler. Dersin ilerleyen kısımlarında hem kavramsal yazılım mühendisliği bilgisi hem de kod yazma becerisi gerekir.

### 1.2 Kapsam

Slayttaki kapsam iki maddedir (ekrandan, 00:17:20):

- Detaylı tasarım yerine yüksek seviyeli mimari tasarıma,
- Nesneye yönelik tasarıma odaklanılacaktır.

Hoca bunu şöyle açar: ders, uygulamalar için, özellikle günümüzün modern ve yüksek hacimli uygulamaları için yüksek seviyeli mimari tasarımların ne olduğunu inceler. Dersin derdi yazılımın detaylı tasarımı değil, mimari tasarımın nasıl olacağını göstermektir. Fakat bir mimariyi ifade edebilmek için önce yazılımın analizini ve tasarımını düzgün biçimde yapabilmek gerekir. Bu analiz ve tasarım nesneye yönelik yaklaşımla ele alınır; geleneksel ya da işlevsel (fonksiyonel) yaklaşımlara girilmez. Amaç, analizi ve tasarımı "olması gerektiği gibi" ifade etmektir.

## 2. Ders akışı: beş bölüm

Ders akışı slaytı dersi beş bölüme ayırır (ekrandan, 00:19:05). Hoca ilk üç bölümü birlikte düşünülebilecek bir giriş bloğu olarak görür.

- **1. Bölüm, Giriş:** Önce birkaç giriş dersi yapılır. Yazılım ve yazılım mühendisliğiyle ilgili temel problemlerin üzerinden geçilir.
- **2. Bölüm, UML ve Analiz:** Bir tasarım problemi nasıl analiz edilir, UML ve OCL ile nasıl tanımlanır, analizin statik ve dinamik yönleri nelerdir. Hoca burada analizin nasıl dokümante edileceğinin ve nasıl tanımlanacağının da öğrenileceğini söyler.
- **3. Bölüm, Yazılım Mimarisi:** Mimariler hakkında düşünmek, onları ifade etmek, işlevsel olmayan gereksinimlerin mimarinin belirlenmesine etkileri ve mimari tasarımların gerçekleştirilecek modüller hâline nasıl getirileceği.
- **4. Bölüm, Yazılım Tasarımı:** Tasarımla ilgili nesne tasarımı, tasarım kalıpları, tasarım prensipleri, tasarım gözden geçirimi gibi özel detaylar.
- **5. Bölüm, Modern Mimari Yaklaşımlar:** Monolitikten sunucusuz mimarilere kadar olan yenilikçi yaklaşımlar.

> **Ek bilgi (derste anlatılmadı):** OCL (Object Constraint Language), UML modellerine kesin, biçimsel kısıtlar eklemek için kullanılan bildirimsel bir dildir. Örneğin bir sınıfın değişmezleri (invariant) ya da bir işlemin ön ve son koşulları OCL ile yazılır. Böylece yalnız diyagramla anlatılamayan kurallar belirsizlik olmadan tanımlanır.

## 3. Modern mimari yaklaşımlar

Hoca beşinci bölümü dersin en önemli kısmı ve dersin yarısı olarak tanımlar. Bu bölümde incelenecek yaklaşımlar şu sırayla anlatılır:

- **Monolitik yaklaşım:** başlangıç noktasıdır.
- **Servis tabanlı yaklaşım:** monolitik yapının içinde de servis tabanlı bir ayrım incelenir.
- **Mikro çekirdek (microkernel) tabanlı yaklaşım.**
- **Mikroservis mimarisi:** slaytta ayrıca yazmasa da en çok üzerinde durulacak konudur.
- **Sunucusuz (serverless) mimari.**
- **Üst düzey mimari tasarım.**

### 3.1 Mikroservis mimarisi ve tasarım kalıpları

Hoca mikroservis mimarisinde iki soruyu öne çıkarır: mikroservis mimarisi nedir ve bu mimaride uyulması gereken tasarım kalıpları (mikroservis tasarım kalıpları, yazılım mimarisi tasarım kalıpları) nelerdir. Bu kalıpların ayrıntılı olarak araştırılıp öğrenilmesi beklenir.

Hocaya göre mikroservis tasarım kalıpları beş ana başlık altında toplanır ve her başlığın alt kırılımları vardır. Bir kalıp incelenirken şu sorular sorulur:

- Bu kalıp hangi problemi nasıl çözüyor?
- Neden böyle bir kalıp var?
- Nasıl bir uygulama alanı var?
- Mikroservis modelinde bu kalıp nereye ve nasıl uygulanır?

<!-- BELİRSİZ: Beş ana başlığın adları derste söylenmedi ve ekranda gösterilmedi. -->

> **Hocanın vurgusu:** Dersin en önemli kısmı mikroservis mimarisi ve bu mimaride kullanılan tasarım kalıplarıdır.

### 3.2 Sunucusuz mimari

Hoca "serverless architecture" kavramını Türkçeye "sunucusuz mimari" diye çevirir. Bu yaklaşım günümüzde yaygınlaşmaktadır, ama hocanın uyarısıyla her problemde değil, gerektiği yerde kullanılmalıdır.

### 3.3 Orta katman ve mimari tasarım kalıpları

Dönemin ikinci yarısında orta katman (middleware) çözümleri ve, en çok mikroservis üzerinde olmak üzere, mimari tasarım kalıpları çalışılır. Slayttaki konu başlıkları "Orta Katman Çözümleri" ve "Mimari Tasarım kalıpları"dır (ekrandan, 00:23:03). Monolitik, mikroservis ve sunucusuz mimariler için şu sorular ele alınır: bu mimariler nedir, üst düzey tasarımları nasıl yapılır, nelere dikkat edilir, nerede kullanılmalı ve nerede kullanılmamalıdır.

## 4. Ders hedefleri

Ders hedefleri slaytı şöyledir (ekrandan, 00:22:20). Dönemi tamamladığımızda:

1. Bir uygulamanın analiz ve tasarımını UML ile ifade edebilmeyi,
2. Yazılım mimarilerini tanımlayıp değerlendirebilmeyi,
3. Uygun mimari biçimi seçip kullanabilmeyi,
4. Nesneye yönelik tasarım tekniklerini anlayıp uygulayabilmeyi,
5. Uygun yazılım tasarım kalıplarını seçip kullanabilmeyi

öğrenmeyi hedefliyoruz.

Hoca bu maddeleri sözlü olarak açar. Birinci hedefte UML ile ifadenin "kitabına uygun, olması gerektiği gibi" olması istenir. İkinci hedef, "yazılım mimarisi" dendiğinde temel yaklaşımların neler olduğunu bilip değerlendirebilmektir. Üçüncü hedef için hoca şu örneği verir: eldeki probleme bakıp "burada Pipe and Filter kullanayım" diyebilmek. Beşinci hedef, özellikle mikroservis dünyasında hangi tasarım kalıbının hangi problemde ya da hangi çözümü geliştirirken seçileceğini bilmektir.

> **Ek bilgi (derste anlatılmadı):** Pipe and Filter (boru ve süzgeç) bir mimari biçimdir. Sistem, her biri girdisini işleyip çıktısını üreten bağımsız bileşenlere (filtre) bölünür. Filtreler birbirine veri akışını taşıyan bağlantılarla (boru) zincirlenir. Derleyici aşamaları ve Unix kabuğundaki `|` ile kurulan komut zincirleri bilinen örneklerdir.

## 5. Haftalık konu planı

Hoca ders planını ekranda kısaca gösterir, ama üzerinden ayrıntılı geçmez (ekrandan, 00:22:55). Ekranda görünen ilk yedi haftanın konuları şunlardır:

| Hafta | Konu |
|---|---|
| 1 | Giriş, ders planı, genel bilgiler |
| 2 | Tasarım kavramları, UML, nesneye yönelik analiz, UML sınıf modelleri |
| 3 | Tasarım çalışmaları, formal tanımlama, OCL |
| 4 | Davranış modelleme |
| 5 | Yazılım mimarisi, mimari görünümler |
| 6 | Mimari biçimler, işlevsel olmayan gereksinimler |
| 7 | Orta katman çözümleri - 1 |

<!-- BELİRSİZ: Planın sekizinci ve sonraki haftaları ekranda gösterilmedi. -->

Hocaya göre dönemin ilk yarısı analiz, tasarım ve temel mimarilere, ikinci yarısı orta katman ve mimari tasarım kalıplarına ayrılır. Tabloya göre ilk haftalar beş bölümlük akışın ilk dört bölümünü izler: UML ile statik analiz (sınıf modelleri), OCL ile formal tanımlama, davranış (dinamik) modelleme, ardından mimari görünümler ve mimari biçimler.

## 6. Mimari problem örneği ve tasarımı öğrenme yolu

### 6.1 Alışveriş sitesi örneği

Hoca, derste ele alınan türden bir mimari problemi gerçek hayattan bir örnekle anlatır. Büyük bir çevrimiçi alışveriş sitesini düşünelim: çok sayıda dükkân ve farklı satıcı vardır, bir de milyonlarca alıcı vardır. Site belli dönemlerde kampanya yapar. Soru şudur: kampanya dönemlerinde gelen talep, hizmeti yavaşlatmadan ya da sistem mümkün olduğunca kararlı kalacak biçimde nasıl karşılanır? Bunun için nasıl bir mimari tasarım yapılmalıdır?

Hoca böyle bir problemin çözümünün yalnız kâğıt üzerinde kalmaması gerektiğini, uygulamasının da yazılabileceğini söyler. Örnek olarak sunucusuz bir çözümün AWS üzerinde kurgulanabileceğini belirtir. Böylece mimari tasarım ve onun gerçekleştirimi birlikte görülmüş olur.

> **Ek bilgi (derste anlatılmadı):** Bu tür ani yük artışlarında mimaride genellikle yatay ölçekleme (aynı servisin daha çok kopyasını çalıştırma) ve servislerin birbirinden bağımsız ölçeklenebilmesi aranır. Mikroservis ve sunucusuz mimarilerin bu derste öne çıkmasının bir nedeni büyük olasılıkla budur: yükü artan parça, sistemin geri kalanından ayrı olarak büyütülebilir.

### 6.2 Tasarım yaparak öğrenilir

Slayttaki ilke şudur: "Tasarım öğretilmez, yaparak öğrenilir. Modelleme ve teknolojilerden bahsedilir, sizler de tasarım problemlerini nasıl çözeceğinizi düşünürken bunlardan faydalanırsınız." (ekrandan, 00:23:03). Aynı slaytta, gerçek hayat problemlerine artımlı çözüm getiren, etaplardan oluşan bir çalışma fikri de yer alır. Hoca bunu, anlatılan ifade yöntemleri (UML) ve mimarilerle gerçek bir problemi seçip ona adım adım çözüm geliştirmek olarak açıklar.

## 7. Agile ile mimari tasarımın farkı ve dersin seviyesi

**Soru:** Bir öğrenci, lisanstaki yazılım mühendisliği dersinden kavramları hatırladığını ama bu dersin daha ileri geldiğini söyler ve Agile gibi konuların bu dersin kapsamında olup olmadığını sorar.

**Cevap:** Hoca, Agile'ın bir süreç yönetimi olduğunu söyler. Bu ders ise süreç yönetimine değil, bir ürünün geliştirilmesine, yani ürünün analizine, tasarımına ve mimarisine odaklanır.

Hoca ayrıca bu dersi lisansta da seçimlik olarak açtığını anlatır. Lisans dersinde yalnız temel mimarilerden bahsedip gerektiği kadar kalıp verir; mikroservis tasarım kalıpları gibi konulara girmez. Gerekçesi, lisans öğrencilerinin yazılım mühendisliğini yeni almış olması ve temel kavramlar yerine oturmadan ileri mimarilere geçmenin verimli olmamasıdır. Lisansüstü dersi lisans dersinden ayıran şey bu ileri konulardır.

## 8. Kaynak kitaplar

Kaynak kitaplar slaytında dört kitap vardır (ekrandan, 00:30:10):

- Len Bass, Paul Clements, Rick Kazman: *Software Architecture in Practice*, 3. baskı (SEI Series in Software Engineering).
- Richard N. Taylor, Nenad Medvidovic, Eric M. Dashofy: *Software Architecture: Foundations, Theory, and Practice* (Wiley).
- Paul Clements, Felix Bachmann, Len Bass, David Garlan, James Ivers, Reed Little, Paulo Merson, Robert Nord, Judith Stafford: *Documenting Software Architectures: Views and Beyond*, 2. baskı (SEI Series in Software Engineering).
- Dominic Duggan: *Enterprise Software Architecture and Design: Entities, Services, and Resources* (Wiley).

Hoca *Documenting Software Architectures* kitabını temel kitap olarak kullandığını söyler. Lisans dersinde ise ikinci kaynak olarak *Software Architecture in Practice* kitabını kullanır.

## Örnek Sorular

Bu tanıtım dersinde ekranda soru ya da alıştırma gösterilmedi. Aşağıdaki soru derste sözlü olarak tartışılan bir kavram sorusudur.

**Soru 1** (derste sözlü, 00:28:48): Agile bir yazılım mimarisi konusu mudur? Agile ile bu dersin odağı arasındaki fark nedir?

> **Cevap (derste verildi):** Agile bir süreç yönetimi yaklaşımıdır; yazılımın geliştirilme sürecinin nasıl yürütüleceğiyle ilgilenir. Bu ders ise bir ürünün kendisine, yani nesneye yönelik analiz ve tasarımına ve yüksek seviyeli mimarisine odaklanır.

## Dersin Toparlaması

Bu ilk derste dersin çerçevesi çizildi. Ders, detaylı tasarım yerine yüksek seviyeli mimari tasarımı ve nesneye yönelik yaklaşımı merkeze alır. Akış beş bölümdür: giriş, UML ve analiz (UML, OCL, statik ve dinamik yön), yazılım mimarisi (mimari görünümler, mimari biçimler, işlevsel olmayan gereksinimlerin etkisi), yazılım tasarımı (kalıplar, prensipler, gözden geçirme) ve modern mimari yaklaşımlar. Son bölüm dersin yarısıdır: monolitik, servis tabanlı, mikro çekirdek, mikroservis ve sunucusuz mimariler. En büyük ağırlık mikroservis mimarisi ve onun tasarım kalıplarındadır.

Hedef, dönem sonunda bir uygulamanın analiz ve tasarımını UML ile doğru ifade edebilmek, mimarileri tanımlayıp değerlendirebilmek ve probleme uygun mimari biçimi ve tasarım kalıbını seçebilmektir. Ders planına göre bir sonraki ders tasarım kavramları, UML, nesneye yönelik analiz ve UML sınıf modelleriyle başlar.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
