# GSM8K Türkçe Veri Kümesi Çıkarıcı

Bu proje, HuggingFace üzerinden "ytu-ce-cosmos/gsm8k_tr" veri kümesini çekerek istenen sayıda soru-cevap çiftini rastgele seçen ve CSV dosyasına kaydeden bir araçtır.

## Proje Hakkında

GSM8K (Grade School Math 8K) veri kümesinin Türkçe versiyonu üzerinde çalışmak için kullanılan bu araç, belirli bir seed değeri kullanarak rastgele örnekleme yaparak daha sonraki çalışmalarda tekrarlanabilir sonuçlar elde edilmesini sağlar.

## Gereksinimler

Python 3.12.3 veya üzeri sürümü gerekmektedir. Aşağıdaki kütüphanelere ihtiyaç vardır:

```datasets pandas numpy argparse```


Gereksinimleri kurmak için:

```bash
pip install -r gereksinimler.txt
```
## Kullanım
Script aşağıdaki parametreyi kabul eder:
* -s, --seed: Rastgele seçim için kullanılacak seed değeri (varsayılan: 42)
Örnek kullanım:
```bash
python main.py --seed 37
```
Bu komut, belirtilen seed değeriyle (örneğin 37) GSM8K Türkçe veri kümesinden rastgele 1000 soru-cevap çifti seçer ve `gsm8k_tr_1000_soru_cevap.csv` dosyasına kaydeder.
## Çıktı
Script, çalıştırıldığı dizine aşağıdaki formatta bir CSV dosyası oluşturur:
```bash
gsm8k_tr_1000_soru_cevap.csv
```

Bu dosya iki sütundan oluşur:
* question: Türkçe dilinde matematik sorusu
* answer: Soruya ait cevap

## Çalıştırma Adımları
Kodlar `python sürümü == 3.12.3` ve `pip sürümü == 24.0` ile çalıştırılmıştır. Aşağıdaki adımları takip ederek kod'u çalıştırabilirsiniz:
1. Gerekli kütüphaneleri yükleyin:
```bash
pip install -r gereksinimler.txt
```
2. Script'i çalıştırın:
```bash
python main.py --seed 37
```
3. Çıktı dosyasını kontrol edin: Çalıştırma tamamlandıktan sonra, gsm8k_tr_1000_soru_cevap.csv dosyasını script'in bulunduğu dizinde bulabilirsiniz.

## Not
* Bu projede varsayılan seed değeri 42'dir, ancak komut satırı parametresiyle farklı bir seed değeri belirtilebilir. Aynı seed değeri kullanıldığında her zaman aynı soru-cevap çiftleri seçilir, böylece sonuçların tekrarlanabilirliği sağlanır.
* Varolan `gs8k_tr_1000_soru_cevap.csv` dosyası seed değeri 37 ile oluşturulmuştur.