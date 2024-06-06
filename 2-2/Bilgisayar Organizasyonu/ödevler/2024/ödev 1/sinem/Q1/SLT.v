`include "three_input_and.v"
`include "three_input_xnor.v"
`include "thirty_two_bit_zeroExtender.v"
/*
 * zero extender kisminda thirty two zero extender i include ederken bir sorunla karsilastim.
 * four_bit_zeroExtender dosyasina, thirty_two_zeroExtender dosyasi icerisinde:
 * thirty_two_bit_zeroExtender_tb.vvp thirty_two_bit_zeroExtender_tb.v komutunu calistirinca erisebilmeme ragmen
 * SLT dosyasinda iverilog -o SLT_tb.vvp SLT_tb.v komutunu calistirdigimda
 * ./components\zeroExtender\thirty_two_bit_zeroExtender\thirty_two_bit_zeroExtender.v:2: Include file ..\four_bit_zeroExtender\four_bit_zeroExtender.v not found
 * hatasini aldim. Bu sebepten oturu butun zeroExtenderlari ayni dosyaya koymak zorunda kaldim.
*/

module SLT(out_thirty_two_bit,ALUControl0,B,A,ALUControl1,SUM);
    input ALUControl0, ALUControl1, SUM,A,B;
    output [31:0] out_thirty_two_bit;
    wire out_xnor, out_xor, ALUControl1_not, out_and, out_one_bit;

    three_input_xnor xnor1(A, B, ALUControl0, out_xnor);
    xor x1(out_xor, A, SUM);
    not(ALUControl1_not, ALUControl1);
    three_input_and and1(out_xnor, out_xor, ALUControl1_not, out_and);
    xor x2(out_one_bit, SUM, out_and);

    thirty_two_bit_zeroExtender z1(out_thirty_two_bit, out_one_bit);
endmodule
