Nasıl kullanılır
hocalar.json dosyası hoca bilgilerini içerir ve readmeleri oluşturmakta kullanılır
formatı şu şekildedir
{
    "hocalar": [{
            "ad": "Prof. Dr. Banu Diri",
            "ofis": "EEF-D222",
            "link": "http://avesis.yildiz.edu.tr/diri/",
            "dersler": ["Sayısal Analiz", "Ayrık Matematik", "Doğal Dil İşlemeye Giriş"],
            "hakkinda": "Çok tatlı bir hoca, derslerini seviyor, yoklamaya biraz önem veriyor, güzel anlatıyor, anlattığını soruyor. Arada sırada çok sinirleniyor.",
            "anlatim_puani": 90,
            "kolaylik_puani": 90,
            "ogretme_puani": 90,
            "eglence_puani": 90
}]}

giris.json readme dosyasının giriş bilgilerini içerir ve formatı şu şekildedir
{
    "baslik": "Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği Ders Notları",
    
    "aciklama": "Bu repository, Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği bölümünde verilen derslerin notları, örnek soruları ve ilgili kaynakları barındırmaktadır. Öğrencilerin dersleri daha etkin bir şekilde öğrenmelerini desteklemek amacıyla hazırlanmıştır."
    
    ,"icindekiler": [
        "[Hocalar](#hocalar)",
        "[Dersler](#dersler)",
        "[Repo Kullanımı](#repo-kullanımı)",
        "[Yazarın Notları](#yazarın-notları)"
    ]
}


donemler.json dönem bilgilerini tutar ve formatı şu şekildedir
{
    "donemler": [
      {
        "dosya_yolu": "../1-1",
        "donem_adi": "1. Sınıf Güz",
        "genel_tavsiyeler": ["Düzenli ders çalışmayı ihmal etmeyin", "Lab uygulamalarına katılın"],
        "yil": 1,
        "donem": "Güz"
      }]}

dersler.json ders bilgilerini tutar ve formatı şu şekildedir

{"dersler":[
    {"ad": "İşletim Sistemleri",
        "yil": 3,
        "donem": "Güz",
        "tip": "Zorunlu",
        "hakkinda": "",
        "kolaylik_puani": 0,
        "gereklilik_puani": 0,
        "faydali_olabilecek_kaynaklar":["Abraham-Silberschatz-Operating-System-Concepts-10th-2018","kitap oldukça güzel, ders slaytları da bu kitaptan alınmış."],
        "derse_dair_oneriler":["Lablardan tam puan almanız lazım.","Çıkmış çözmeniz lazım."],
        "dersi_veren_hocalar":["ZCT","G1","MAG"]
    }]}

repo_kullanimi.json reponun nasıl kullanılacağı bilgilerini tutar
yazarin_notlari.json ek notları tutar

bu dosyalarla kök klasörde, her dersin klasöründe ve her dönemin klasöründe readme dosyaları oluşur