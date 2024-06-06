`include "aluComponents/thirty_two_bit_not.v"
`include "aluComponents/thirty_two_one_mux.v"
`include "aluComponents/thirty_two_bit_full_adder.v"
`include "aluComponents/thirty_two_bit_and.v"
`include "aluComponents/thirty_two_bit_xor.v"
`include "aluComponents/SLT.v"
`include "aluComponents/thirty_two_three_mux.v"

module Alu(result,A,B,ALUControl,zero);
    input[31:0] A,B;
    input[2:0] ALUControl;
    output[31:0] result;
    output Cout;
    output reg zero;

    wire[31:0] sum, modifiedB, B_not, and_result,xor_result, SLT_result;

    thirty_two_bit_not n1(B_not,B);
    thirty_two_one_mux t1(modifiedB,B,B_not,ALUControl[0]);
    thirty_two_bit_full_adder a1(A,modifiedB,ALUControl[0],Cout,sum);
    thirty_two_bit_and an1(and_result,A,B);
    thirty_two_bit_xor x1(xor_result,A,B);
    SLT s1(SLT_result,ALUControl[0],B[31],A[31],ALUControl[1],sum[31]);
    thirty_two_three_mux  m1 (result,sum,sum,and_result,xor_result,0,SLT_result,0,0,ALUControl);
   
    always @(*) begin
    if (result == 32'h00000000) begin
        zero = 1'b1; 
    end
    else begin
        zero = 1'b0; 
    end
end


endmodule

