// File: alu.v
module alu(
    input  [31:0] a,
    input  [31:0] b,
    input  [2:0]  ctrl,
    output reg [31:0] y,
    output        zero
);
  always @(*) begin
    case (ctrl)
      3'b000: y = a + b;             // add
      3'b001: y = a - b;             // sub
      3'b010: y = a & b;             // and
      3'b011: y = a | b;             // or
      3'b101: y = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;  // slt/slti
      default: y = 32'bx;
    endcase
  end

  assign zero = (y == 32'd0);
endmodule
