Modüller:

adder.v: 32-bit toplama
alu.v: ALU
aludec.v: ALU dekoderi/kontrolcusu
controller.v: işlemci kontrol sinyalleri
datapath.v: işlemci veri yolu
dmem.v: Veri belleği, RAM
extend.v: İmmidiate extend
flopenr.v: Enable/reset flip-flop
flopr.v: Reset flip-flop
imem.v: Komut belleği (ROM)
maindec.v: Ana kontrol sinyalleri
mux2.v: 2 girişli mux
mux3.v: 3 girişli mux
regfile.v: Register dosyası
riscvsingle.v: RISC-V işlemci
top.v: Üst modül (işlemci + bellekler)

testbench ve yüklenen program hakkında açıklama:

testbench: Programı belleklerde çalıştırılması ve 100 adresine 25 yazılıp yazılmadığını kontrol edilmesi.
riscvtest.txt: Hex formatında makine kodu içermektedir.

testbenchi çalıştırmak için:

iverilog -o riscvtest top.v riscvsingle.v controller.v maindec.v aludec.v datapath.v adder.v extend.v flopr.v flopenr.v mux2.v mux3.v alu.v imem.v regfile.v dmem.v testbench.v
vvp riscvtest

gtkwave:

gtkwave riscvtest.vcd

Kaynak:
Sarah L. Harris ve David Money Harris, "Digital Design and Computer Architecture" p. 457-467, 7.6.1 Single Cycle Processor.
