from pynq import Overlay
import time

ol = Overlay("Senkron.bit")
r = ol.reset.channel1; e = ol.enable.channel1; o = ol.result.channel1
r.setdirection("out"); e.setdirection("out"); o.setdirection("in")
r.setlength(1); e.setlength(1); o.setlength(8)

# Asenkron reset: Clock'u beklemeden sıfırlanma durumu
r.write(1, 0x1)
time.sleep(0.001)
print(f"Reset sonrasi okuma: {o.read()}")
r.write(0, 0x1)

# Enable=0 Durumu (İlk ripple asamasi durur, zincir ilerlemez)
before = o.read()
time.sleep(0.01)
after = o.read()
print(f"Enable = 0 durumu için, Oncesi: {before}, Sonrasi: {after}")

# Enable=1 Durumu (Ripple sayacda FCLK_CLK0 ile ilerliyor)
e.write(1, 0x1)

for i in range(10):
    time.sleep(0.01)
    print(f"Count sayisi: {o.read()}")

e.write(0, 0x1)
