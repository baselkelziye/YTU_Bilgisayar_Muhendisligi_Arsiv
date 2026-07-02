# Deneme 1 - GPT2'ye tag ürettirmek.
"<düşünce>" "<cevap>" şeklinde tag'lerin üretmesini istedim başta öğrenmedi. Cevapların doğruluğu iyiydi ama.
Acaba ödülde mi sorun var diye düşündüm, o yüzden verisetini çok küçük yapıp epoch sayısını arttırdım ki formatı öğrenebiliyor mu öğrenemiyor mu onu görelim en azından diye. Çünkü daha önceki eğitimlerde tek tük tag üretse de devamlılığı sağlamakta iyi değildi. 

# Deneme 2 - Overfit'i zorlamak
15 tane veri olan bir verisetinde 15 epoch boyunca eğiterek overfit olmasını bekledim. Ancak overfit olmadı bir türlü. Üstelik formatı da öğrenmedi. 

# Deneme 3 - Formatı basitleştirmek
Formatı öğrenmesinin zor olduğunu düşünerek formatı basitleştirmeyi düşündüm. Öyle de artık çok fazla öğrenmeyince saldım bir şeyleri öğretmeyi zorlamayı.

# Deneme 4 - Saldım
Format öğretmeyi saldım artık. Ödül fonksiyonlarını tanımlıcam. olursa olur. olmazsa olmaz. 
Fonksiyon 1:
Doğru cevapta ödül, ve kısa cevap: toplam kelime sayısı 7'den azsa ceza, 30'dan çoksa ceza. Şık belirtmezse ceza. Ayrıca spam harf/kelime spam yaparsa da ceza. kalanı ödül. kelime sayısı belirtilen aralığa göre soft ceza alsın. çok uzaklaşırsa çok ceza alsın.
Fonksiyon 2:
Doğru cevapta ödül, ve uzun cevap: toplam kelime sayısı 20'den az, 100'den çoksa ceza. şık belirtmeze ceza, spamda ceza. kalanı ödül. kelime sayısı cezası üstteki gibi soft
Fonksiyon 3:
Doğru cevapta ödül, yazdığı kelimeler arasında türkçede olan ingilizcede olmayan harflerin kullanımının çok az olması. "ğüşıöç" %5'ten çoksa ödül. azsa ceza yok. "qwx" harfleri %10'dan çoksa artan ceza. altında az ceza.
Fonksiyon 4:
Doğru cevapta ödül, cümle içerisinde "çünkü, sebebiyle, dolayısıyla, yani, bu yüzden" gibi sebep sonuç bağlaçlarını içermesi ödül. maks 3 bağlaca kadar ödül, 3'ten fazla bağlaç ceza. 

Bütün fonksiyonlarda spam harf ve spam kelime koruması olarak ceza. Doğru şıkkı söylememesi de ceza

## Not Lora konfigürasyonu aşağıdaki gibi seçildi. dahafazla da arttırılabilir.

"""LoRA konfigürasyonu"""
r: int = 64  # LoRA rank
lora_alpha: int = 128  # LoRA alpha
lora_dropout: float = 0.05
target_modules: list = None
bias: str = "none"

# Deneme 5
Eğittiğim modeller pek baaşrılı olmadı. baseline baaşrııs %13 seviyesindeydi ama o şansa bala olmuş sanırım. bir daha çalıştrınca o kadar yüksek bir sonuç alamadık. Birkaç fix yaptım. utils kısmında ve ödül fonksiyonlarının ölçeğiyle ilgili. Son bir kez daha çalıştıracağım grpo'yu. öğrenirse öğrenecek umarım.