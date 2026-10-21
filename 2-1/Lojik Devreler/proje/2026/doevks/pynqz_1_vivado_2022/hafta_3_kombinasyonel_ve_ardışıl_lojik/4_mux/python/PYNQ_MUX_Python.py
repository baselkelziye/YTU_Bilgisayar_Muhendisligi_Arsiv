
from pynq import Overlay
Ol = Overlay("Four_MUX.bit")

control = o.gpio_input.channel1
result = o.gpio_result.channel1

control.setdirection("out"); control.setlenght(32)
control.setdirection("in"); control.setlenght(32)

#D3 ... D0 --> 0101

data = 0b0101 #this methode tests decimal 5.
for sel in range(4):
	 control.write(data | (sel << 4))
	 y = result.read() & 0x1
	 print(f"sel=, {sel}, y= {y}") #sel is selection 1,2,3,... while y reads the bit result of the selection.
