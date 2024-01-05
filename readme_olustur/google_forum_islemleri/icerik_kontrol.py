"""from transformers import AutoTokenizer, AutoModelForSequenceClassification
import torch
import re
class IcerikKontrol:
    def __init__(self, tip): 
        # Karaliste dosyasının adı
        self.dosya_adi = 'karaliste.txt'
        # Model ve tokenizer yükleniyor
        model_name = "savasy/bert-base-turkish-sentiment-cased"
        self.tokenizer = AutoTokenizer.from_pretrained(model_name)
        self.model = AutoModelForSequenceClassification.from_pretrained(model_name)
        # Küfürlerin yerini alacak zararsız kelime
        self.censor_word = "[sansürlendi]"
        self.sansurlenen_yorumlar = []
        self.yazim_hatasi_duzeltilen_yorumlar = []
        # Küfürlü kelimelerin listesi
        self.swear_words = self.dosyadan_kelime_listesi_olustur(self.dosya_adi)
        self.tip = tip
        self.sikintili_yorumlar = []
    def dosyadan_kelime_listesi_olustur(self, dosya_adi):
        # Boş liste oluştur
        kelime_listesi = []

        # Dosyayı aç ve satır satır oku
        with open(dosya_adi, 'r', encoding='utf-8') as dosya:
            for satir in dosya:
                # Satır sonundaki boşlukları ve newline karakterini kaldır
                kelime = satir.strip()
                # Listeye kelimeyi ekle
                kelime_listesi.append(kelime)

        return kelime_listesi
    def metin_on_isleme(self,text):
        if self.pozitif_mi(text):
            self.sikintili_yorumlar.append(text)
        yazim_hatasi_duzeltildi = self.yazim_duzeltici(text)
        if yazim_hatasi_duzeltildi != text:
            self.yazim_hatasi_duzeltilen_yorumlar.append(f"{text} -> {yazim_hatasi_duzeltildi}")
        sansurlu_yorum = self.sansurle(yazim_hatasi_duzeltildi)
        if yazim_hatasi_duzeltildi != sansurlu_yorum:
            self.sansurlenen_yorumlar.append(f"Ana metin: {text} -> Yazım hatası düzeltilmiş metin: {yazim_hatasi_duzeltildi} -> Sansürlü Metin:{sansurlu_yorum}")
        return sansurlu_yorum
    def yazim_duzeltici(self,metin):
        return metin
        # Hunspell nesnesini oluştur ve Türkçe sözlük dosyalarını yükle
        hspell = hunspell.HunSpell('/usr/share/hunspell/tr_TR.dic', '/usr/share/hunspell/tr_TR.aff')
        
        duzeltilmis_kelimeler = []
        
        # Metni kelimelere ayır
        kelimeler = metin.split()
        
        for kelime in kelimeler:
            # Eğer kelime doğru yazılmışsa, doğrudan listeye ekle
            if hspell.spell(kelime):
                duzeltilmis_kelimeler.append(kelime)
            else:
                # Eğer kelime yanlış yazılmışsa, önerilen düzeltmeleri al
                oneriler = hspell.suggest(kelime)
                if oneriler:
                    # İlk öneriyi al ve listeye ekle
                    duzeltilmis_kelimeler.append(oneriler[0])
                else:
                    # Eğer öneri yoksa, orijinal kelimeyi ekle
                    duzeltilmis_kelimeler.append(kelime)
        
        # Düzeltilmiş kelimeleri birleştir ve döndür
        return ' '.join(duzeltilmis_kelimeler)
    def dosya_yaz(self):
        with open(f"sikintili_{self.tip}_yorumlar.txt", "w", encoding="utf-8") as f:
            f.write("\n".join(self.sikintili_yorumlar))
        with open(f"sansurlu_{self.tip}_yorumlar.txt", "w", encoding="utf-8") as f:
            f.write("\n".join(self.sansurlenen_yorumlar))
        with open(f"yazim_hatasi_duzeltilen_{self.tip}_yorumlar.txt", "w", encoding="utf-8") as f:
            f.write("\n".join(self.yazim_hatasi_duzeltilen_yorumlar))
    def sansurle(self,text):
        # Tüm küfürlü kelimeleri sansürle
        for swear_word in self.swear_words:
            # Sadece tam kelime eşleşmelerini sansürle (case insensitive)
            pattern = re.compile(r'\b' + re.escape(swear_word) + r'\b', re.IGNORECASE)
            text = pattern.sub(self.censor_word, text)
        return text
    def pozitif_mi(self,text):
        # Tokenize edilmiş metni hazırla
        inputs = self.tokenizer(text, padding=True, truncation=True, max_length=512, return_tensors="pt")

        # Model ile tahmin yap
        outputs = self.model(**inputs)
        predictions = torch.nn.functional.softmax(outputs.logits, dim=-1)
        positive_score = predictions[:, 1].item()
        # Şimdilik kullanılmıyor
        return True
        # Pozitif skor ne kadar düşükse içerik o kadar olumsuz (muhtemelen küfür veya hakaret içeriyor)
        return positive_score > 0.4  # Eşiği ayarlayabilirsiniz
"""