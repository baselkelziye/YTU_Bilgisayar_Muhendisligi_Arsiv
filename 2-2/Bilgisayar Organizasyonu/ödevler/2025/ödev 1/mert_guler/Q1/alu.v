`include "../01/full_adder_32bit.v"
`include "../01/mux_8x1_32bit.v"
`include "../01/zero_extender_32bit.v"

module alu(A, B, ALUControl, result);

input [31:0] A, B;
input [2:0] ALUControl;
output [31:0] result;

wire [31:0] mux_2x1, mux_8x1, sum, andResult, xorResult, sltResult;
wire overflow;

mux_2x1_32bit mux1(B, ~B, ALUControl[0], mux_2x1);
full_adder_32bit adder(.a(A), .b(mux_2x1), .cin(ALUControl[0]), .result(sum));

assign andResult = A & B;
assign xorResult = A ^ B;

assign overflow = ~(A[31] ^ B[31] ^ ALUControl[0]) & (A[31] ^ sum[31]) & (ALUControl[1]);
zero_extender_32bit extender((overflow ^ sum[31]), sltResult);

mux_8x1_32bit mux2(sum, sum, andResult, xorResult, 32'b0, sltResult, 
                32'b0, 32'b0, ALUControl, result);

endmodule