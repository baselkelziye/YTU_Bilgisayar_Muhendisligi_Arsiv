`include "thirty_two_bit_not.v"
`include "thirty_two_one_mux.v"
`include "thirty_two_bit_full_adder.v"
`include "thirty_two_bit_and.v"
`include "thirty_two_bit_xor.v"
`include "SLT.v"
`include "thirty_two_three_mux.v"

/*
 * componentleri include ederken bir sorunla karsilastim.
 * her component kendi dosyasinda, ornegin thirty_two_zeroExtender dosyasi icerisinde:
 * thirty_two_bit_zeroExtender_tb.vvp thirty_two_bit_zeroExtender_tb.v komutunu calistirinca erisebilmeme ragmen
 * SLT dosyasinda veya ana dosyada ALU yapmaya calisirken iverilog -o SLT_tb.vvp SLT_tb.v veya Alu_tb.vvp Alu_tb.v komutunu calistirdigimda
 * ./components\zeroExtender\thirty_two_bit_zeroExtender\thirty_two_bit_zeroExtender.v:2: Include file ..\four_bit_zeroExtender\four_bit_zeroExtender.v not found
 * ./nots\thirty_two_bit_not\thirty_two_bit_not.v:2: Include file ..\four_bit_not\four_bit_not.v not found
 * gibi erisim hatalari aldim. Bu sebepten oturu butun componentleri ayni dosyaya koymak zorunda kaldim.
 * Ancak her componentin kendilerine ait vcd ve vvp dosyalari kendilerine ait dizinlerinde mevcuttur.
*/
module Alu(result,A,B,ALUControl);
    input[31:0] A,B;
    input[2:0] ALUControl;
    output[31:0] result;
    output Cout;

    wire[31:0] sum, modifiedB, B_not, and_result,xor_result, SLT_result;

    thirty_two_bit_not n1(B_not,B);
    thirty_two_one_mux t1(modifiedB,B,B_not,ALUControl[0]);
    thirty_two_bit_full_adder a1(A,modifiedB,ALUControl[0],Cout,sum);
    thirty_two_bit_and an1(and_result,A,B);
    thirty_two_bit_xor x1(xor_result,A,B);
    SLT s1(SLT_result,ALUControl[0],B[31],A[31],ALUControl[1],sum[31]);
    thirty_two_three_mux  m1 (result,sum,sum,and_result,xor_result,SLT_result,0,0,0,ALUControl);
   
endmodule

