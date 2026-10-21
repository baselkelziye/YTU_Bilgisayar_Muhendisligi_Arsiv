import requests
import re

url = "http://127.0.0.1:1234/v1/chat/completions"

payload = {
    "model": "turkish-gemma-9b-t1",  # LM Studio’da yüklü modelin adı
    "messages": [
        {"role": "user", "content": """Aşağıdaki görevde amaç, bir regresyon modelinin eğitimi için soru–cevap çiftlerinden oluşan bir veri seti oluşturmaktır. 
        Farklı, temel konulardan 15 adet soru yazılmalı ve her soru için bir doğru, bir de tamamen alakasız yanlış cevap üretilmelidir.
Doğru ve yanlış cevaplar aşağıdaki biçimde tutulmalıdır:

Soru, Doğru Cevap, Yanlış Cevap

Her soru bloğu yeni satırda yer almalıdır.
Yanlış cevaplar, soruyla bağlantısı olmayan başka bir konudan olmalıdır.
Doğru cevaplar ise daha açıklayıcı olmalı ve soru cümlesinin bir kısmını doğal şekilde içermelidir. Örneğin:

Türkiye’nin başkenti neresidir?,
Türkiye’nin başkenti Ankara şehridir ve ülkenin yönetim merkezi olarak hizmet verir.,
Maksimum ses seviyesine sahip müzik türü genelde heavy metaldir.

Bu tarzda 20 satırlık bir TXT dosyası oluşturulması beklenmektedir.
"""}
    ],
    "temperature": 0.5
}

response = requests.post(url, json=payload)
text = response.json()["choices"][0]["message"]["content"]

text = re.sub(r"<think>.*?</think>", "", text, flags=re.DOTALL)

with open("../Data/train.txt", "w", encoding="utf-8") as f:
    f.write(text)
