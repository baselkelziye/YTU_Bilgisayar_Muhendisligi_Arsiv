sorular = [
    "İdris DEMİR'in sınav yaklaşımı nasıldır",
    "İdris DEMİR sınavlara nasıl bir yaklaşım benimser",
    "İdris DEMİR sınavlara karşı tutumu nasıldır",
    "İdris DEMİR sınavlara nasıl bir tutum sergiler",
    "İdris DEMİR sınavlara nasıl hazırlanmayı tavsiye eder"
]

cevaplar = [
   "Sınavlardan önce zorlayıcı olabilir, ancak iyi bir insan olarak değerlendirilir.","Sınavlardan önce zorlayıcı olabilir, ancak iyi bir insan olarak değerlendirilir",
    "Sınavlara yaklaşımı genellikle zorlayıcı olsa da, iyi bir insan olarak kabul edilir",
    "Sınavlara karşı zorlayıcı bir tutum sergileyebilir, ancak genel olarak iyi bir insan olarak görülür",
    "Sınavlara karşı zorlayıcı olabilir, ancak genel olarak iyi bir insan olarak nitelendirilir"
]

for cevap in cevaplar:
    for soru in sorular:
        print(f"\"Soru: {soru}? Cevap: {cevap}.\"")