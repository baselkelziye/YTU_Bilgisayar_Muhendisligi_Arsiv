`include "Alu.v"
module Datapath(R1, R2, R3,selector)

    input[31:0] R1,R2,R3;
    input[2:0] selector;
    output [31:0] R0;

    Alu a1(R0, R1,R2,selector);
    Alu a2 (R1,R2,R3,selector);
    Alu a3 (R3,R2,R0,selector);
    Alu a4 (R2, R1,R3,selector);

endmodule
