from pynq import Overlay
import time

ol = Overlay("SenkronTimer.bit")
r = ol.Reset.channel1; e = ol.Enable.channel1; c = ol.counter.channel1
r.setdirection("out"); e.setdirection("out"); c.setdirection("in")
r.setlenght(1); e.setlenght(1); c.setlenght(8)

# Senkron Reset
r.write(1, 0x1)
time.sleep(0.01)
print(f"Reset Uygulanırken: {c.read()}")
r.write(0, 0x1)

# Enable = 0 (Sayaç sabit ve saymıyor)
e.write(0, 0x1)
before = c.read()
time.sleep(0.01) #1ms durur
after = c.read()
print(f"Enable = 0 için;\n  before = {before}\n  after = {after}")

# Enable = 1 (Sayaç tekrar saymaya başladı)
e.write(1, 0x1)
for i in range(10):
	time.sleep(0.001)
	print(f"Count = {c.read()}")
e.write(0, 0x1)
