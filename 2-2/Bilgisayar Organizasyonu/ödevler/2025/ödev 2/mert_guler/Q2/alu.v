module alu(A, B, ALUControl, zero, out);
  input [31:0] A, B;
  input [2:0] ALUControl;
  output reg zero;
  output reg [31:0] out;

  always @(*) begin
  zero <= (A == B);
	case (ALUControl)
		  0:  out <= A + B; // ADD
		  1:  out <= A - B; // SUB
      2:  out <= A & B; // AND
      3:  out <= A | B; // OR
      4:  out <= A << B[4:0]; // SLL
      5:  out <= $signed(A) < $signed(B); // SLT
		  default: out <= 32'bx;
		endcase
  end
endmodule
