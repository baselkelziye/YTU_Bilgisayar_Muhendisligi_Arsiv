module alu (
    input [31:0] a,
    input [31:0] b,
    input [2:0] sel,
    output reg [31:0] y,
    output zero
);
    always @* begin
        case (sel)
            3'b000: y = a + b;  // add, addi
            3'b001: y = a - b;  // sub
            3'b010: y = (a < b) ? 32'b1 : 32'b0;  // slt, slti
            3'b011: y = a | b;  // or, ori
            3'b100: y = a & b;  // and, andi
            default: y = 32'b0;
        endcase
    end

    assign zero = (y == 32'b0);
endmodule