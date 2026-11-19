# Ders 9 Çalışma Özeti

## Genel Konular

- Prosedür ve makro ile modüler programlama
  - Büyük bir programı tek dosyada tek akış olarak yazmak, geliştirmeyi ve bakımı zorlaştırır. Kendi içinde bütün olan bir işi ayrı bir fonksiyon (prosedür, yordam) olarak, tercihen ayrı bir dosyada ya da kütüphanede geliştirmek daha sürdürülebilirdir.
  - Bir modül, beklediği girdiler ve ürettiği çıktılarla tanımlıdır. Girdi ve çıktıların tipi ve sayısı sağlandığı sürece başka prosedürlerden çağrılabilir.
  - Ayrı modülde bir uç durum gözden kaçmışsa iyileştirme yalnız o fonksiyonda yapılır. Kod tekrar kullanılır, aynı şey yeniden yazılmaz.
  - EXE tipi programda FAR tipinde tek bir ana prosedür bulunur; alt yordamlar NEAR ya da FAR olabilir. COM tipi programda aynı dosyadaki bütün yordamlar NEAR'dır.
- Prosedür ile makro arasındaki temel fark
  - Prosedür çağrıldığında akış (IP, gerekirse CS) yordamın bulunduğu yere gider. Dönüşte CALL satırından hemen sonraki satırdan devam edilir. Yordamın makine kodu programda tek kopya olarak bulunur, her çağrı kodu büyütmez.
  - Makro çağrıldığında makronun kod bloğu, derlemeden önce çağrıldığı yere olduğu gibi kopyalanır. Her makro çağrısı kodu makro boyutu kadar büyütür. Makro tanımının kendisi için makine kodu üretilmez, yalnız kopyalandığı yerler için üretilir.
- Prosedür tanımı (ekrandan, 00:20:00)
  - Şablon: `Yordam_ismi PROC {NEAR|FAR}`, `yordam_kodu`, `RET`, `Yordam_ismi ENDP`.
  - Tip yazılmazsa NEAR kabul edilir. FAR yordam `RETF` ile, NEAR yordam `RET` ile döner. FAR bir yordamda `RET` yazılsa da assembler bunu RETF olarak üretir; hoca yine de FAR yordamda RETF yazılmasını istedi.
- CALL ve RET sırasında yığın
  - Alt yordama gidilirken yazmaçlar olduğu gibi kalır; bu yüzden yazmaçlar doğrudan aktarılmış parametre gibi kullanılabilir (IP ve FAR çağrıda CS hariç).
  - NEAR CALL yığına yalnız IP'yi (dönüş ofsetini) atar. FAR CALL önce CS'yi, sonra IP'yi atar.
  - RET yığının en üstündeki değeri IP'ye yükler. RETF önce en üstteki değeri IP'ye, sonra sıradakini CS'ye yükler. İşlemci yığında "IP" ya da "CS" etiketli bir değer aramaz; ne üstteyse onu alır.
- Makro tanımı (ekrandan, 00:30:00)
  - Şablon: `Makro_ismi MACRO {parametre_listesi}`, `LOCAL ...`, `makro_kodu`, `ENDM`.
  - Parametre listesi virgülle ayrılır. Çağırırken verilen değerler, tanımdaki parametrelerle boyut ve tip bakımından uyumlu olmalıdır (örneğin dizi başlangıç adresi ve eleman sayısı).
  - `LOCAL` ardından makro içindeki dallanma ve döngü etiketleri yazılır. Makro birden çok kez çağrıldığında assembler bu etiketleri her kopyada benzersiz adlarla değiştirir; böylece aynı etiketin birden çok kez tanımlanması önlenir.
- Parametre aktarım yolları
  - Yazmaçlar üzerinden (varsayılan durum, bu dersin konusu).
  - Yığın üzerinden: parametreler CALL'dan önce yığına atılır, alt yordamda BP yazmacıyla bulunur. Sonuç parametrelerin üzerine yazılarak yığından ya da yazmaçtan döndürülebilir. Ayrıntısı sonraki haftaya bırakıldı.
  - Ortak/harici veri üzerinden: EXTRN ve PUBLIC ile başka dosyadaki veri etiketleri kullanılır; ileri aşaması ortak veri kesimidir.
- Örnek: iki ayrı dosyada EBOB (GCD) alt yordamı
  - Ana dosya `GCD_reg.ASM` EXE tipidir: yığın (`DW 32 DUP(?)`), veri (`ASAYISI DW 13`, `BSAYISI DW 15`, `GCD DW ?`) ve kod kesimi. A ve B sayılarını AX ve DX'e yükler, `CALL GCD_PROC` ile alt yordamı çağırır, AX'teki sonucu `GCD`'ye yazar (ekrandan, 01:15:00).
  - Alt dosya `GCD_alt.ASM` yalnız bir kod kesimi içerir; kendi veri ve yığın kesimi yoktur, ana programın yığınını kullanır. `GCD_PROC PROC FAR`; girdi AX ve DX, çıktı AX (ekrandan, 00:55:00).
  - Ana dosyada `EXTRN GCD_PROC:FAR`, alt dosyada `PUBLIC GCD_PROC` bulunur.
- EXTRN/PUBLIC hataları ve derleme adımları
  - EXTRN yoksa ana dosya assembler aşamasında hata verir (etiket tanımlı değil).
  - EXTRN var ama alt yordamın obje dosyası linke verilmezse linkleme aşamasında hata çıkar.
  - Alt dosyada PUBLIC yoksa iki obje dosyası da hatasız oluşur; hata yine linkleme aşamasında çıkar, çünkü etiketi dışarıya sunan bir obje dosyası yoktur.
  - İki dosya ayrı ayrı MASM ile obje dosyasına çevrilir, sonra `LINK birinci.obj + ikinci.obj` ile birlikte linklenir. Sıra önemli değildir.
- LST ve MAP dosyaları
  - Ana dosyanın LST'sinde dış yordamı çağıran CALL satırında, adresi linkleme ya da yükleme sırasında doldurulacak bir yer bırakılır.
  - MAP dosyasında tek prosedürlü EXE programda üç kesim (yığın, veri, kod), COM programda tek kesim görülür. İki dosyalı yapıda oluşan EXE'de iki kod kesimi, bir veri ve bir yığın kesimi vardır. Giriş noktası (entry point) ana kod kesiminin 0 ofsetidir.
- Döngüsel GCD ve debug ile yığın izleme
  - Döngüsel sürüm: `CMP AX,DX` / `JAE L2` / `XCHG AX,DX`; `L2: CMP DX,0` / `JE L3` / `MOV BX,DX` / `XOR DX,DX` / `DIV BX` / `MOV AX,BX` / `JMP L2`; `L3: RETF` (ekrandan, 01:10:00).
  - Başlangıçta SP = 0040h (64 byte'lık yığın). `PUSH DS` ve `PUSH AX` (0) sonrası SP = 003Ch. FAR CALL sonrası SP = 0038h; yığında üstten alta ana IP (0015h), ana CS, OS IP = 0, OS CS bulunur (ekrandan, 01:20:00).
  - CALL 076F:0010 adresindedir, 5 byte uzunluğundadır; dönüş ofseti bir sonraki satır olan 0015h'tir.
  - 13 ve 15 aralarında asaldır, sonuç 1'dir ve veri kesiminin 4. ofsetine yazılır. Ana programın RETF'inden sonra SP = 0040h olur, yığın tamamen boşalır.
  - SP'nin altında kalan bellek bölgesindeki değerler çöptür; anlamlı olan SP'den yığının sonuna kadar olan kısımdır.
- Aynı dosyada iki prosedür
  - Alt yordam FAR tanımlı ve aynı dosyadaysa ana yordamda `CALL FAR PTR GCD_PROC` yazılmalıdır; yazılmazsa derleme hata verdi (ekrandan, 01:25:00). Farklı dosyada `EXTRN ...:FAR` tanımı FAR çağrıyı kendiliğinden garanti eder.
  - Alt yordam NEAR tanımlanırsa CALL yalnız ofset içeren NEAR çağrıya dönüşür; yığına tek bir değer (dönüş ofseti 0013h) atılır.
- Özyinelemeli (recursive) GCD
  - Tanım: $\gcd(x,0)=x$, $\gcd(x,y)=\gcd(y,\ x \bmod y)$. x için AX, y için DX kullanılır, sonuç AX'tedir (ekrandan, 01:35:00).
  - Kod: `CMP AX,DX` / `JAE DEVAM` / `XCHG AX,DX`; `DEVAM: CMP DX,0` / `JA RECUR` / `JMP EXIT`; `RECUR: MOV BX,DX` / `XOR DX,DX` / `DIV BX` / `MOV AX,BX` / `CALL GCD_PROC`; `EXIT: RETF` (ekrandan, 01:30:00).
  - 13 ve 15 için çağrılar: (15,13) → (13,2) → (2,1) → (1,0). Ana programdan 1, özyinelemeyle 3 çağrı; her FAR çağrı yığına 4 byte ekler. SP sırasıyla 0038h, 0034h, 0030h, 002Ch olur.
  - İç çağrıların dönüş adresi alt yordamdaki `RETF` satırıdır (0771:001A); en dıştaki çağrı ana yordamdaki `MOV GCD,AX` satırına döner (ekrandan, 01:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- COM tipi programda aynı dosyadaki bütün yordamlar NEAR'dır; EXE tipinde ana prosedür kesinlikle FAR olmalıdır.
- Yığına alt yordamda bir şey atıldıysa uygun sırada geri çekilmelidir. Çekilmezse RET/RETF yanlış değeri IP'ye (ve CS'ye) yükler, program yanlış yere döner.
- Dönüş adresi CALL satırı değil, CALL'dan sonraki satırdır; CALL'a dönülseydi alt yordam yeniden çağrılırdı.
- İki dosyalı yapıda iki seviye de geçilmelidir: assembler aşaması için EXTRN, linkleme aşaması için alt yordamın obje dosyası ve PUBLIC tanımı.
- FAR tipinde tanımlanan yordamın dönüşü de RETF olmalıdır (derste yapılan anlaşma).
- `MOV AX,DATASG` / `MOV DS,AX` satırları çalışmadan `MOV AX,[0000]` veri kesimini göstermez; DS o anda işletim sisteminin segmentindedir.
- Özyinelemeli fonksiyonlarda iç içe çağrı sayısı kabaca öngörülüp yığın o derinliğe yetecek genişlikte tanımlanmalıdır. Yığından parametre aktarımında yığının düzenini bilmek ayrıca gerekecektir.

## Kısa Tekrar Notları

- Prosedür: tek kopya, akış oraya gider ve geri döner. Makro: her çağrıda kod kopyalanır, kod büyür.
- `PROC` tipi yazılmazsa NEAR. FAR → RETF, NEAR → RET.
- NEAR CALL: yığına IP. FAR CALL: yığına CS, sonra IP. RETF: önce IP, sonra CS çekilir.
- `LOCAL` makro içi etiketleri her çağrıda benzersiz yapar.
- Parametre aktarımı: yazmaç, yığın (BP ile), ortak/harici veri (EXTRN/PUBLIC, ortak kesim).
- Ana dosya: `EXTRN ad:FAR`. Alt dosya: `PUBLIC ad`. Link: `LINK a.obj + b.obj`, sıra fark etmez.
- EXTRN yok → assembler hatası. Obje yok ya da PUBLIC yok → linkleme hatası.
- Alt yordam dosyasında yalnız kod kesimi olur; yığın ana programınkidir.
- İki dosyalı EXE'nin MAP'inde 2 kod, 1 veri, 1 yığın kesimi görülür.
- Aynı dosyada FAR yordam: `CALL FAR PTR ad`.
- Özyinelemeli GCD(15,13): 4 FAR çağrı, yığın en derinde SP = 002Ch.
- SP'nin altındaki yığın baytları çöptür.

## Detaylı Açıklamalar

- **Neden prosedür ve makro?** Hoca konuya diğer programlama dillerindeki fonksiyon mantığıyla girdi. Bir işi (örneğin iki sayının en büyük ortak bölenini bulmayı) ana akışın içine gömmek yerine ayrı bir yordam olarak yazmak, onu tek bir sayı çifti için bir kez, bir dizinin karşılıklı elemanları için eleman sayısı kadar çağırmaya olanak verir. Yordam ayrı dosyada olduğunda yalnız ona odaklanılarak iyileştirilebilir. Makrolar da kendi başına anlamı olan kod parçalarıdır ve onlar da ayrı dosyalarda tutulabilir; fakat çağrıldıkları yere kopyalandıkları için davranışları prosedürden farklıdır.

- **CALL/RET mekanizması.** NEAR çağrıda CALL, dönüş ofsetini (CALL'dan sonraki komutun ofseti) yığına atar ve IP'yi yordamın başına ayarlar. RET yığının en üstündeki word'ü IP'ye yükler. FAR çağrıda CS ve IP birlikte saklanır; RETF en üstteki word'ü IP'ye, sıradakini CS'ye yükler. Hoca, işlemcinin yığında hangi değerin IP, hangisinin CS olduğunu bilmesinin mümkün olmadığını vurguladı: alt yordam içinde PUSH yapılıp POP unutulursa RETF bu değeri dönüş adresi sanar.

- **İki dosyalı EBOB örneği.** Ana dosya standart EXE iskeletidir: `BASLA PROC FAR`, `PUSH DS`, `XOR AX,AX`, `PUSH AX`, `MOV AX,DATASG`, `MOV DS,AX`, ardından `MOV AX,ASAYISI`, `MOV DX,BSAYISI`, `CALL GCD_PROC`, `MOV GCD,AX`, `RETF` (ekrandan, 01:15:00 ve 01:30:00). Alt dosyanın başında `PUBLIC GCD_PROC` ve yalnız `CDESG SEGMENT PARA 'CODE'` vardır. Hoca, yordamın başına girdi ve çıktıyı belirten yorum yazılmasını önerdi: `;GCD_PROC input AX, DX`, `;GCD_PROC output AX`. Başlangıçtaki `CMP AX,DX` / `JAE` / `XCHG AX,DX` üçlüsü büyük sayıyı AX'e, küçüğü DX'e koyar; böylece küçük sayının sıfır olup olmadığı doğrudan sonlanma koşulu olarak denetlenir.

- **Derleme hatalarının deneyle gösterilmesi.** Hoca EXTRN satırını kaldırıp ana dosyayı derledi; assembler `GCD_PROC` etiketinin tanımlı olmadığını söyledi. EXTRN geri konunca alt yordam henüz derlenmemiş olsa bile ana dosyanın obje dosyası oluştu; bu kez tek başına linklemede etiket hiçbir obje dosyasında bulunamadı. Alt dosyada PUBLIC satırı yorum yapıldığında iki obje dosyası da hatasız oluştu, fakat linkleme yine aynı hatayı verdi. Her şey yerindeyken linkleme sırası ters çevrilerek de denendi ve sorun çıkmadı.

- **Debug ile yığının izlenmesi (döngüsel sürüm).** EXE yüklendiğinde DS işletim sisteminin segmentini (075A) gösterir. `PUSH DS` ile bu segment, `PUSH AX` ile 0 yığına atılır; SP 0040h → 003Eh → 003Ch olur. CALL satırı debug'da `CALL 0771:0000` (makine kodu `9A00007107`) olarak görünür; segment ve ofset birlikte verildiği için bu FAR çağrıdır (ekrandan, 01:15:00). CALL çalışınca yalnız CS ve IP değişir (CS 076F → 0771, IP 0010 → 0000), SP 0038h olur. `d ss:38` ile yığında dönüş ofseti 0015h, ana CS 076Fh, 0 ve 075Ah görülür. 13 ile 15 için döngü üç bölme yapar ve AX = 1 ile `L3: RETF`'e gelinir; RETF sonrası SP tekrar 003Ch olur, sonuç `MOV [0004],AX` ile veri kesimine yazılır.

- **Özyinelemeli sürümde yığın.** Alt yordam kendini `CALL GCD_PROC` ile çağırır; yordam aynı dosyada ve FAR olduğu için bu çağrı da FAR'dır (`CALL 0771:0000`, CALL 0771:0015 adresinde). Her iç çağrı yığına 0771:001A dönüş adresini (alt yordamın RETF satırı) atar. En derinde (AX = 1, DX = 0) SP = 002Ch olur; ardından üç RETF alt yordamın kendi RETF satırına, dördüncü RETF ana yordamdaki `MOV GCD,AX` satırına döner ve SP 003Ch'ye çıkar.

> **Ders sonrası not:** Döngüsel sürümdeki `DIV BX; 0:AX/DX; DX<-AX%DX;` yorumu (ekrandan, 01:10:00) bölenin DX olduğunu düşündürüyor. `DIV BX` komutu DX:AX çiftini BX'e böler; DX = 0 yapıldığı için bu AX/BX işlemidir, bölüm AX'e, kalan (AX mod BX) DX'e yazılır. BX, DX'in eski değerini (y) tuttuğu için sonuç $x \bmod y$'dir.

- **Soru-cevap: tail call optimization.** Bir öğrenci, özyinelemeli çağrı fonksiyonun son işi olduğunda yığına yeni dönüş adresi atılmayan "tail call optimization" mantığının burada hazır olup olmadığını sordu. Hoca, güncel derleyicilerde varsa güncel işlemcilerin assembly'sinde desteklenebileceğini, ancak incelenen 8086 yapısında böyle bir hazır mekanizma olmadığını, daha yeni yapılar için emin olmadığını söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
