`include "Adder.v"
`include "AND_gate.v"
`include "OR_gate.v"
`include "NOT_gate.v"
`include "Mux_3_8.v"
`include "Mux_1_2.v"
`include "ZeroExtender.v"
`include "SLT.v"


module ALU32(
    input [31:0] A,
    input [31:0] B,
    input [2:0] ALUControl,
    output [31:0] Result,
    output Zero,
    output Overflow
);
wire [31:0] Bnot;
wire [31:0] B1_Result;
wire [31:0] B_mux;
wire B1_Cout;
wire [31:0] and_Result;
wire [31:0] or_Result;
wire [31:0] Sum;
wire Cout;
wire LT_1;
wire [31:0] LT;
wire Overflow;

NOT_gate not_gate (
    .A(B),
    .Result(Bnot)
);

Mux_1_2 mux_1_2 (
    .a(B),
    .b(Bnot),
    .sel(ALUControl[0]),
    .y(B_mux)
);

Adder adder (
    .A(A),
    .B(B_mux),
    .Cin(ALUControl[0]),
    .Sum(Sum),
    .Cout(Cout)
);

AND_gate and_gate (
    .A(A),
    .B(B),
    .Result(and_Result)
);

OR_gate or_gate (
    .A(A),
    .B(B),
    .Result(or_Result)
);


SLT slt (
    .A(A[31]),
    .B(B[31]),
    .ALUControl(ALUControl),
    .Sum(Sum[31]),
    .LT(LT_1),
    .Overflow(Overflow)
);

ZeroExtender zero_extender (
    .in(LT_1),
    .out(LT)
);

Mux_3_8 mux (
    .in0(Sum),
    .in1(Sum),
    .in2(and_Result),
    .in3(or_Result),
    .in4(32'b0),
    .in5(LT),   
    .in6(32'b0),
    .in7(32'b0),
    .sel(ALUControl[2:0]),
    .out(Result)
);

assign Zero = (Result == 32'b0) ? 1'b1 : 1'b0; // Zero flag

endmodule