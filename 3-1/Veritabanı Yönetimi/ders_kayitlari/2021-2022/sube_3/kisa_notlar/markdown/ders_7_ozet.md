# Ders 7 Çalışma Özeti

## Genel Konular

- Gereksinim raporundan kavramsal tasarıma geçiş (COMPANY veritabanı)
  - Gereksinim raporundaki cümlelerin özneleri varlık kümelerine, fiilleri (yüklemleri) bağıntılara işaret eder. Bu bir algoritma değil, deneyimle kazanılan bir sezgidir (heuristik).
  - Her özne için körü körüne varlık kümesi açılmaz: "The company is organized into DEPARTMENTs" cümlesinin öznesi company olsa da yalnız tek bir şirketin bilgisi tutulduğu için COMPANY diye bir varlık kümesi gerekmez. Hoca bunun en sık yapılan hatalardan biri olduğunu söyledi.
  - Raporda (ekrandan, 00:10:00) dört varlık kümesi öne çıkar: DEPARTMENT, PROJECT, EMPLOYEE ve DEPENDENT. Bağıntılar: manages, controls, works for, works on (haftalık saat bilgisiyle), direct supervisor ve has (dependents).
  - İlk tasarımda (ekrandan, 00:25:00) bağıntılar da nitelik olarak yazılır: DEPARTMENT (number BA, name, manager, managerStartDate, locations), PROJECT (number BA, name, location, controllingDept), EMPLOYEE (Ssn BA, fName, lName, department, birthDate, salary, worksOnProjects, supervisor, adress), DEPENDENT (name, dependsToEmp, birthDate, relationships).
- İlk tasarım sonrası iyileştirmeler (ekrandan, 00:20:00)
  - Nitelik başka bir varlığa işaret ediyorsa bağıntıya dönüşür (manager, department, worksOnProjects, supervisor, controllingDept, dependsToEmp).
  - Nitelik çok değer alabiliyorsa varlık kümesine dönüşür (departmanın locations niteliği → LOCATION, "locates in" bağıntısı).
  - Varlık kümesinin tek niteliği ve tek bağıntısı varsa niteliğe dönüşür.
  - Mümkünse genelleme yapılır (top-down ya da bottom-up). Bağıntıların dereceleri yeniden değerlendirilir, gerekirse kümeleme kullanılır.
  - Gereksiz bilgi ve tekrarlar (redundancy) çıkarılır.
- COMPANY UML ve ER diyagramları (ekrandan, 00:30:00 ve 00:35:00)
  - İki varlık arasında farklı rollerde birden çok bağıntı olabilir: EMPLOYEE ile DEPARTMENT arasında hem WORKS_FOR (N:1, iki taraf da zorunlu katılım) hem MANAGES (1:1; departman tarafı zorunlu, çalışan tarafı isteğe bağlı) vardır.
  - WORKS_ON M:N'dir ve Hours niteliği bağıntıya aittir. MANAGES'in Start_date niteliği bağıntıya aittir. SUPERVISION, EMPLOYEE üzerinde 1:N recursive bağıntıdır.
  - DEPENDENT zayıf varlıktır: raporda onu bütün veritabanında tek kılacak bir nitelik (SSN gibi) istenmez. Ayırt edici nitelik Name'dir (bir çalışanın iki yakını aynı adı taşımaz).
- Diğer tasarım örnekleri
  - Şehir-Ülke-Nehir (ekrandan, 00:40:00): nehir ülkeyle bağlanırsa hangi şehirlerden geçtiği tutulamaz; nehir şehirle (N:M) bağlanırsa ülke bilgisi şehir-ülke bağıntısı üzerinden dolaylı olarak çıkarılır. Bağıntının yükü artar ama bilgi kaybolmaz.
  - Bölüm-Personel (ekrandan, 00:45:00): yönetici ancak o bölümün personeliyse "sahip" bağıntısına "yönetici mi" niteliği yeter. Herhangi bir personel yönetici olabiliyorsa ayrı bir yönetme bağıntısı gerekir.
  - Satış formu (ekrandan, 00:50:00): SATIŞ (sNO BA, tarih), PARÇA (pNo BA, isim, fiyat, tanım), SATIR (satırNo AN) zayıf varlık. genelToplam ve satırToplamFiyatı türetilmiş niteliklerdir; kavramsal tasarımda yazılmasa da olur. SATIŞ ile SATIR "sahip", SATIR ile PARÇA "var" bağıntısıyla bağlanır; ayrıca SATIŞ-PARÇA bağıntısına gerek yoktur.
  - Takım-Oyuncu-Oyun (ekrandan, 01:10:00): oyun ayrı bir varlık yapılır, takıma "ev" ve "misafir" bağıntılarıyla (her biri 1:N, skor niteliğiyle) bağlanır, oyuncuyla "oynar" (M:N) bağıntısı kurulur. Takım-takım recursive bağıntısı oyuna katılan oyuncuları tutamazdı.
  - Banka hesabı işlemleri (ekrandan, 01:40:00): işlem zayıf varlıktır; gün ve saat (GS) kısmi anahtar olur. Aynı hesapta bir saat içinde birden çok işlem olabiliyorsa daha ince zaman bilgisi gerekir.
  - Uçak rezervasyon sistemi (ekrandan, 01:45:00 ve 01:50:00): FLIGHT güçlü; FLIGHT_LEG, LEG_INSTANCE ve SEAT zayıf varlık zinciridir. Anahtarlar: Flight number; + LegNo; + Date; + SeatNo.
  - Genelleme örneği (ekrandan, 02:00:00): EMPLOYEE'nin üç ayrı özelleştirmesi: {SECRETARY, TECHNICIAN, ENGINEER} (d), {MANAGER}, {HOURLY_EMPLOYEE, SALARIED_EMPLOYEE} (d). Alt sınıfa özgü nitelikler ve bağıntılar (MANAGES-PROJECT, BELONGS_TO-TRADE_UNION) alt sınıfa bağlanır.
- ER'dan ilişkisel modele dönüşüm (mapping)
  - Adım 1: her güçlü varlık için bir tablo; anahtarı seçilen birincil anahtar (birleşikse bütün bileşenler) (ekrandan, 02:05:00).
  - Adım 2: her zayıf varlık için bir tablo; güçlü varlığın birincil anahtarı yabancı anahtar olarak eklenir, birincil anahtar güçlünün anahtarı + kısmi anahtardır (DEPENDENT: {ESSN, DEPENDENT_NAME}).
  - Adım 3: 1:1 bağıntı için üç yol (ekrandan, 02:10:00): yabancı anahtar (tercih edilen; zorunlu katılımlı tarafa eklenir), tabloları birleştirme (iki taraf da zorunlu ve nitelik azsa), ayrı bağıntı tablosu.
  - 1:N bağıntıda N tarafına yabancı anahtar eklenir. M:N bağıntı için mutlaka ayrı tablo kurulur, anahtarı iki tarafın anahtarlarıdır. Çok değerli nitelik için ayrı tablo kurulur (DEPT_LOCATIONS).
  - Adım 8: özelleştirme dönüşümü dört seçenek (ekrandan, 02:25:00): 8A süper ve alt sınıflar için ayrı tablolar, 8B yalnız alt sınıf tabloları, 8C tek tablo ve bir tür niteliği, 8D tek tablo ve birden çok tür bayrağı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kavramsal tasarım "iki kere iki dört" gibi kesin kurallı değildir
  - Farklı doğru tasarımlar olabilir. Fazladan bir bağıntı veritabanını yanlış yapmaz ama gereksiz yük (redundancy, performans, ek fonksiyon) getirir.
- Çalışma yöntemi
  - Gereksinim raporunu okuyup diyagrama bakmadan boş kağıda çizin, sonra slayttakiyle karşılaştırın. Diyagrama bakıp "anladım" demek yeterli değildir.
- Gereksinim raporunda istenen nitelikler tutulur
  - Raporda olmayan bir anahtar (örneğin dependent için SSN) kendiliğinden eklenmez. Bu yüzden DEPENDENT zayıf varlık olur.
- Zayıf varlık zinciri iyi bir tasarımın işaretidir
  - Uçak rezervasyon örneğinde tek bir gerçek birincil anahtar (Flight number) vardır, diğerleri doğru biçimde zayıf yapılmıştır.
- ER'dan ilişkisel tablolara dönüşüm soruları sınavlarda en çok sorulan sorulardır
  - Hangi niteliğin neden altı çizili olduğu, yabancı anahtarın neden o tabloya gittiği anlaşılarak çalışılmalıdır.
- 1:1 bağıntıda yabancı anahtar zorunlu katılımlı tarafa eklenir
  - MANAGES için Mgr_ssn DEPARTMENT'a eklenir; EMPLOYEE'ye eklenirse çalışanların çok küçük bir kısmı yönetici olduğundan sütun çoğunlukla NULL kalır.

## Kısa Tekrar Notları

- Özne → varlık adayı, fiil → bağıntı adayı; tek örneği olan kavram (company) varlık olmaz.
- Başka varlığa işaret eden nitelik → bağıntı; çok değerli nitelik → varlık/ayrı tablo.
- Türetilmiş nitelikler (genel toplam, satır toplamı, yaş) saklanmak yerine sorguda hesaplanabilir.
- Zayıf varlık: bütün nitelikleriyle bile anahtarı olmayan küme; anahtarı = güçlünün anahtarı + ayırt edici nitelik.
- Güçlü varlık → tablo; zayıf varlık → tablo (güçlünün PK'sı FK ve PK'nın parçası).
- 1:1 → zorunlu katılımlı tarafa FK (ya da birleştirme ya da ayrı tablo); 1:N → N tarafına FK; M:N → ayrı tablo; çok değerli nitelik → ayrı tablo.
- Recursive 1:N bağıntıda FK aynı tabloya işaret eder (Super_ssn → Ssn).
- Özelleştirme: 8A her zaman uygulanabilir; 8B için katılımın zorunlu (total) olması gerekir; 8C disjoint için tek tür niteliği, 8D overlap için alt sınıf başına bayrak.

## Detaylı Açıklamalar

- COMPANY veritabanında tasarım adımları
  - Gereksinim raporu okunduğunda departmanlar için ad, numara, yöneten çalışan, yöneticinin başlama tarihi ve birden çok konum; projeler için tek ad, tek numara ve tek konum; çalışanlar için SSN, adres, maaş, doğum tarihi; yakınlar için ad, cinsiyet, doğum tarihi ve çalışanla yakınlık derecesi istenir (ekrandan, 00:10:00).
  - İlk tasarımda her şey nitelik olarak yazılır, sonra iyileştirme kurallarıyla bağıntılar ortaya çıkar. UML diyagramında üzeri çizilen nitelikler (manager, managerStartDate, locations, worksOnProjects, supervisor, controllingDept, dependsToEmp) bağıntılara dönüşmüştür (ekrandan, 00:30:00). Hoca EMPLOYEE'deki department niteliğinin de üzerinin çizilmesi gerektiğini, slaytta eksik kaldığını belirtti.
  - Relationship niteliği (eş, çocuk gibi) çalışanla yakınlık derecesidir; bunun için ayrı varlık kümesi gerekmez.
  - Hoca, tasarımın bu adım adım yolla yapılmasının şart olmadığını; deneyim kazanıldıkça öznelerden ve yüklemlerden doğrudan ER çizilebileceğini söyledi.
- Satış formu örneğinde türetilmiş nitelikler
  - Formda satır 1: parça 23645 ayakkabı, miktar 1, birim fiyat 110, toplam 110; satır 2: parça 12674 gömlek, miktar 2, birim fiyat 80, toplam 160; genel toplam 880 (diğer satırlar "..." ile gösterilmiş) (ekrandan, 00:50:00).
  - Satır toplamı miktar × birim fiyattır ($1 \times 110 = 110$, $2 \times 80 = 160$); genel toplam satır toplamlarının toplamıdır. Bunlar SQL içinde hesaplanabilir.
  - Hoca yaş örneğini hatırlattı: yaş her yıl güncellenmesi gerektiği için türetilmesi daha kritiktir. Fatura değişmiyorsa toplamı saklamak yalnız ek depolama yüküdür.
  - Satır numarası tek başına anahtar olamaz (her faturada 1, 2, 3 diye gider), ama bir satış içinde benzersizdir; satırın güçlüsü satıştır, parça olamaz (bir parça birçok satırda geçebilir).
- Takım-Oyun örneğinde anahtar tartışması
  - Slaytta oyunun birincil anahtarı tarih ve sonuçtan oluşan birleşik bir anahtardır (ekrandan, 01:10:00). Hoca tarihin tek başına yetmeyeceğini (farklı takımlar aynı gün oynayabilir), daha iyi tasarımın oyunu zayıf varlık yapmak olduğunu söyledi: anahtar iki takımın adları + tarih (iki takımın aynı gün birden çok maç yapmadığı varsayımıyla).
  - Takım adları ülke çapında tekrar etmiyorsa ad, anahtar olarak kullanılabilir; ayrıca ID gerekmez.
  - Hoca üçlü bağıntıların gösterimi konusunda kitaplar arasında tam bir uzlaşma olmadığını, bu yüzden mümkünse ikili bağıntılarla çözmenin tercih edildiğini söyledi.
- Uçak rezervasyon sistemi (Elmasri/Navathe Figure 3.17)
  - FLIGHT (Number, Airline, Weekdays) bir uçuş planıdır; FLIGHT_LEG (LegNo) planlanan ayaklardır ve DEPARTURE_AIRPORT ile ARRIVAL_AIRPORT bağıntılarında planlanan kalkış ve varış saatleri (ScheduledDepTime, ScheduledArrTime) tutulur. LEG_INSTANCE (Date, No-of-avail seats) ayağın belirli bir tarihteki gerçekleşmesidir; DEPARTS ve ARRIVES bağıntılarında gerçek saatler (DepTime, ArrTime), ASSIGNED bağıntısıyla kullanılan uçak tutulur. SEAT (SeatNo) RESERVATION (CustomerName, CPhone) ile LEG_INSTANCE'a bağlanır. FARE (Code, Amount, Restrictions) uçuşa bağlıdır. AIRPLANE_TYPE ile AIRPORT arasında CAN_LAND (M:N) vardır (ekrandan, 01:50:00).
  - Planlanan ile gerçekleşen değerlerin ayrı tutulması gecikme istatistikleri çıkarmayı sağlar.
- Gemi takip örneğinde ilişkiler (ekrandan, 02:30:00)
  - SHIP [Sname, Owner, scName, Pname, Type], PORT [scName, Pname, solName], STATE/COUNTRY [Name, Continent], SEA/OCEAN/LAKE [Name], SHIP_MOVEMENT [Sname, Date, Time, Longitude, Latitude], SHIP_TYPE [Type, Tonnage, Hull], VISITS [scName, Pname, Sname, startDate, EndDate]. Altı çizili (birincil anahtar) nitelikler: SHIP'te Sname; PORT'ta scName, Pname; STATE/COUNTRY'de Name; SEA/OCEAN/LAKE'te Name; SHIP_MOVEMENT'ta Sname, Date, Time; SHIP_TYPE'ta Type; VISITS'te scName, Pname, Sname, startDate.
  - PORT zayıf varlıktır; anahtarı, var olma bağıntısıyla bağlı olduğu ülkenin adı + liman adıdır. SHIP ile PORT arasındaki 1:N bağıntıda N tarafı SHIP olduğundan PORT'un anahtarı (scName + Pname) SHIP'e yabancı anahtar olarak gelir; Type ise SHIP_TYPE'a işaret eden yabancı anahtardır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
