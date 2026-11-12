# Ders 8 Çalışma Özeti

## Genel Konular

- Dersin yapısı: üçüncü (son) ödevin sunumları
  - Ders tümüyle öğrenci sunumlarına ayrıldı. Hoca yeni konu anlatmadı; her sunumda yöntemi, ölçütleri ve grafikleri sorguladı.
  - Ödevin sorusu: bir dil modeli sonradan eğitildikçe (SFT, Multi-SFT, GRPO) ürettiği cevapların doğruluğu ile birbirinden farklılığı (çeşitliliği, diversity) nasıl değişir?
  - Ödev yine iki yoldan çözülüyordu: öğrencinin kendi çözümü ve bir yapay zekâ aracına yaptırılan çözüm. Hoca sunumda iki çözümün farkını görmek istedi.
- Deney düzeni (sunumlarda ortak olan)
  - Veri: Türkçe matematik problemleri, `ytu-ce-cosmos/gsm8k_tr`; 1000 eğitim, 500 test sorusu (ekrandan, 01:45:00).
  - Taban model: `Qwen/Qwen3.5-4B` (ekrandan, 01:45:00). Bazı öğrenciler kaynak sıkıntısı ya da taban başarının zaten yüksek olması yüzünden Qwen2.5'in 1.5B, 3B, 14B sürümlerine ya da Qwen3-4B'ye geçti.
  - Öğretmen model: SFT çözümlerini üretmek için büyük bir model, çoğunlukla `gpt-oss-120b`; bazı sunumlarda DeepSeek ya da Llama 70B.
  - Altı model karşılaştırıldı: Base, SFT, Multi-SFT, GRPO, SFT+GRPO, Multi-SFT+GRPO.
  - Her soru için her modelden 10 cevap üretilir. 10 cevaptan $\binom{10}{2}=45$ cevap çifti çıkar. Her çift grafikte bir noktadır.
  - Hedefler: SFT ile tabana göre yaklaşık %10, SFT+GRPO ile yaklaşık %20 doğruluk artışı.
- Cevap çifti için iki koordinat
  - Y (çift doğruluğu): iki cevap da doğruysa 1, biri doğruysa 0.5, ikisi de yanlışsa 0.
  - X (farklılık): iki cevap metninin ne kadar farklı olduğu. En sık kullanılan ölçüt $1-\cos(\mathbf{e}_i,\mathbf{e}_j)$; $\mathbf{e}$ cevabın embedding'idir.
  - İdeal bölge sağ üst köşedir: hem doğru hem birbirinden farklı cevaplar (ekrandan, 00:15:00).
- Doğruluğun ölçülmesi: cevaptan sayıyı çıkarma
  - Düzenli ifade (regex) ile `#### <sayı>` kalıbı aranır; yoksa metindeki son sayı alınır (ekrandan, 02:30:00).
  - Sorunlar: `42.0` ile `42`'nin eşleşmemesi, binlik ayracı noktası ve ondalık virgül, model cevabının İngilizce ya da LaTeX içinde gelmesi, cevabın sonda değil ortada yazılması.
  - Bir öğrenci veri kümesindeki bazı referans cevapların yanlış olduğunu fark edip düzeltti; böylece doğru cevaplar yanlış sayılmadı.
- Farklılığın ölçülmesi
  - Embedding ile: Türkçe E5 Large (Cosmos), `paraphrase-multilingual-mpnet-base-v2`, MiniLM; ardından $1-\cos$.
  - Embedding'siz: TF-IDF vektörleri ile kosinüs, kelime kümeleri üzerinde Jaccard, karakter düzeyinde SequenceMatcher, en uzun ortak alt diziye dayanan ROUGE-L.
- SFT ve Multi-SFT verisi
  - SFT: her soruya öğretmen modelden bir çözüm. Multi-SFT: aynı soruya birden çok (3-5) farklı çözüm.
  - Bazı öğrenciler öğretmen çözümlerinden yalnız doğru olanları tuttu.
  - Öğretmenin LaTeX'li, İngilizce karışık çözümleriyle eğitilen model bu stili ezberledi; bir öğrencide test artışı yalnız %1.7 oldu. Veri kümesinin kendi Türkçe çözümlerine geçince test doğruluğu 0.421'den 0.581'e çıktı (ekrandan, 01:04:00).
- GRPO
  - Algoritma: aynı istem için $K$ cevap üret; her cevaba ödül ver; grup ortalamasına göre göreli avantajı hesapla; politikayı KL cezasıyla güncelle (ekrandan, 01:07:00).
  - Ödüller kural tabanlıydı: doğruluk ödülü (ör. doğruysa 1 ya da 2) ve format ödülü (ör. `####` ya da `Final: <sayı>` varsa 0.2-0.5); bazı sunumlarda uzunluk ödülü ve yanlış cevaba ceza da vardı (ekrandan, 01:30:00).
  - Gruptaki bütün cevaplar doğru ya da bütün cevaplar yanlışsa avantaj sıfırdır; o sorudan öğrenme sinyali gelmez.
  - Format ödülü doğruluktan bağımsızsa model mantık yürütmeyi bırakıp formattan puan toplamaya yönelebilir (ödül sömürüsü).
- Ortak bulgular
  - SFT doğruluğu belirgin artırdı ama cevaplar birbirine benzedi; farklılık düştü.
  - GRPO tek başına tabana göre küçük bir artış verdi; SFT ya da Multi-SFT üzerine eklenince katkısı çoğunlukla 1-2 puan kaldı ya da hiç olmadı.
  - Bir sunumda doğruluk ile farklılık arasında neredeyse tam negatif bir ilişki çıktı (Pearson $r\approx-0.99$) (ekrandan, 01:12:55).
  - SFT ailesinde eğitim-test farkı %10-12 civarındaydı (hafif aşırı uyum); yalnız GRPO'da fark sıfıra yakındı (ekrandan, 03:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Her nokta bir cevap çiftidir
  - Hoca grafikte her noktanın soru başına ortalama değil, tek bir cevap çifti olmasını istedi. 500 test sorusunda 45'er çift, toplam 22.500 nokta olur. Soru başına ortalama alan bir grubu bu yüzden uyardı.
- Yöntemini bilmek ve anlatabilmek
  - "Kodda hesaplattım" bir cevap değildir. Farklılığın, doğruluğun ya da bir sayının nasıl hesaplandığı açıkça anlatılabilmelidir.
  - Bir terimin (ör. ödül listesindeki bir parametre) ne demek olduğunu bilmeden sunuma koymamak gerekir.
- Multi-SFT'nin tanımı
  - Multi-SFT aynı soruya birden çok farklı cevap vermektir. Farklı alanlardan farklı sorular toplamak başka bir fikirdir; ödevde istenen o değildir.
  - Multi-SFT'de 1'e 3 cevap varsa eğitim örneği SFT'nin 3 katıdır; karşılaştırmada bu hesaba katılmalıdır.
- Bilgiyi yarım bırakmamak
  - "Grup tamamen doğru ya da tamamen yanlışsa öğrenme sinyali sıfırdır" diye yazılıyorsa, bu durumun ne sıklıkla oluştuğu da hesaplanmalı ve sonuca bağlanmalıdır.
- Analizi doğru alt kümede yapmak
  - Taban modelin zorlandığı sorular eğitimin etkisini daha iyi gösterir. Zor/orta/kolay ayrımı yapılmışsa grafik ve tablo zor sorular için de, farklılık için de çıkarılmalıdır.
- Sayıları oransal vermek
  - "181 soru, 284 soru" gibi mutlak sayılar yerine oran verilmeli; aksi hâlde fark olduğundan büyük görünür.
- Örnek seçimi
  - Hiçbir modelin çözemediği bir soru göstermek iyidir; yanında tabanın çözemeyip eğitilmiş modelin çözdüğü bir örnek de konmalıdır.
- Eğitim verisinin büyüklüğü
  - Birkaç yüz örnekle anlamlı bir sonradan eğitim beklenemez.
- Yapay zekâ kullanımı
  - Kodun tamamını yapay zekâya yazdırmak ödevin amacını boşa çıkarır. Hoca, problemleri kendi başına çözmeden ilerlemenin zamanla kişinin kendi kabiliyetini zayıflattığını söyledi ve "yapay zekâ diyeti" önerdi.

## Kısa Tekrar Notları

- 10 cevap → 45 çift; 500 test sorusu → 22.500 nokta.
- Y: çiftte 2 doğru = 1, 1 doğru = 0.5, 0 doğru = 0. X: $1-\cos$ farklılığı.
- İdeal: sağ üst (doğru ve çeşitli).
- SFT doğruluğu artırır, çeşitliliği düşürür; öğretmen stili ezberlenebilir.
- Öğretmen verisindeki biçim (LaTeX, İngilizce) öğrenciye geçer; temiz Türkçe çözümler daha iyi sonuç verdi.
- GRPO: grup içi göreli avantaj; hepsi doğru/hepsi yanlış → sinyal yok.
- Base modelin doğruluğu 0.421 ve grup 8 ise bir grupta ortalama $8\times0.421\approx3.4$ doğru cevap düşer (ekrandan, 01:07:00).
- Format ödülü bağımsızsa ödül sömürüsü olabilir; farklılığı ödüllendiren bir terim çeşitliliği artırabilirdi.
- `num_generations` (grup büyüklüğü) küçükse (ör. 4) GRPO'nun etkisi zayıf kalabilir.
- Eğitim-test farkı küçükse aşırı uyum azdır; SFT ailesinde fark ~%10.
- Multi-SFT'de aynı soruya birden çok çözüm vardır.

## Detaylı Açıklamalar

- Çift grafiği nasıl okunur?
  - Bir soru için 45 nokta çizilir. Yeşil noktalar iki cevabın da doğru olduğu çiftlerdir (Y=1), turuncular birinin doğru olduğu çiftlerdir (Y=0.5), kırmızılar ikisinin de yanlış olduğu çiftlerdir (Y=0).
  - Bir sunumda taban modelin hiç çözemediği zor bir soruda (Base: ortalama doğruluk 0.10, farklılık 0.87), SFT ve Multi-SFT sonrası yeşil noktalar oluştu; SFT+GRPO'da ortalama doğruluk 0.90, farklılık 0.90'a çıktı (ekrandan, 00:16:20). Öğrenci bunun özellikle seçilmiş iyi bir örnek olduğunu, kolay sorularda çoğu zaman tersinin görüldüğünü söyledi.
  - Bütün test sorularının noktaları aynı grafiğe konunca yorum zorlaşır. Bir öğrenci bu yüzden yalnız 5 soruyu çizdi.
- Zorluk düzeylerine ayırma
  - Bir öğrenci test sorularını taban modelin 10 cevaptaki başarısına göre ayırdı: başarı %40'ın altıysa zor (yaklaşık %30), %40-%79 arası orta (yaklaşık %20), %80 ve üstü kolay (yaklaşık %50). Eğitimler zor sorularda belirgin artış verdi, kolay sorularda ise başarı düştü. Öğrenci bunun aşırı uyum ya da halüsinasyondan olabileceğini düşündü.
- Örnek sonuç tablosu (bir sunum, test, 500 soru) (ekrandan, 02:57:25)

  | Model | binary | soft | farklılık | base'e göre |
  |---|---|---|---|---|
  | base | %42.4 | %61.2 | 0.139 | — |
  | grpo | %51.7 | %68.1 | 0.116 | +%9.3 |
  | sft | %58.2 | %71.1 | 0.099 | +%15.8 |
  | multisft | %59.0 | %71.9 | 0.096 | +%16.6 |
  | sft_grpo | %59.9 | %72.9 | 0.096 | +%17.5 |
  | multisft_grpo | %61.0 | %74.2 | 0.094 | +%18.6 |

  - "Base'e göre" sütunu yüzde puan farkıdır. Doğruluk arttıkça farklılık sistematik olarak azaldı; en doğru model en az çeşitli olandı.
  - Aynı sunumda GRPO yalnız başına eğitim-test farkı sıfıra yakın (%51.5'e %51.7) bir model verdi; SFT ailesinde fark %9.7-%11.8 oldu (ekrandan, 03:00:00). Öğrencinin yorumu: model ne kadar temel ise GRPO o kadar çok iyileştiriyor; eğitilmiş bir modelin üstüne az şey katıyor.
- GRPO'da öğrenme sinyalinin kaybolması
  - Bir öğrenci bu durumu iki senaryoyla gösterdi (ekrandan, 01:07:00): 8 cevabın hepsi doğruysa grup ortalaması 1.0, her cevabın avantajı $1.0-1.0=0$; hepsi yanlışsa ortalama 0, avantaj $0-0=0$. İki durumda da güncelleme olmaz. Önerilen çözüm önce SFT, sonra GRPO (warm start).
  - Hoca bu bilginin yanında bu senaryoların ne sıklıkla oluştuğunun da verilmesi gerektiğini söyledi.
- Ödül sömürüsü
  - Bir öğrencinin GRPO'su format ödülünü kolayca alınca doğruluğu bırakıp formata yöneldi; SFT ile kazanılan doğruluğu da bozdu. Öğrenci ayrıca KL katsayısını (beta) güncellemeyi çok hızlı yapacak biçimde seçtiğini düşündü.
  - Bir başka sunumda doğruluk ödülü 2, format ödülü (`####` varsa) 0.5 idi ve ikisi bağımsızdı (ekrandan, 02:35:17). Hoca cevap yanlışken formattan puan alındığını teyit etti.
- Embedding'siz ve embedding'li farklılık
  - Karakter ya da kelime örtüşmesine dayanan ölçütler (Jaccard, SequenceMatcher, ROUGE-L) anlamsal farkı değil yüzeysel farkı ölçer. Bir öğrenci kendi sonucunda bunu not etti: farklı bir, anlamsal ölçüt farklı sonuç verebilir.
  - Farklı dillerde ya da farklı biçimde (LaTeX'li ve LaTeX'siz) yazılmış cevaplar aynı mantığı taşısa da "farklı" görünebilir; tersine, ortak İngilizce kalıp cümleler farklılığı yapay olarak düşürebilir.
- Hiçbir modelin çözemediği soru (ekrandan, 01:51:55)
  - Bir kasada 42 elma var; fabrikaya 12 kasa geldi; 4 elma çürük çıktı; kalanlar 10'arlı kutulara konacak; kaç kutu gerekir? Referans cevap 50.
  - Modeller "kasa" ile "elma" arasındaki ilişkiyi kuramadı: SFT modeli $42-4=38$, $38/10\to3$ diyerek 12 kasayı atladı. Öğrenci bunu küçük modelin bağlamsal ilişki kurmadaki zayıflığına bağladı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
