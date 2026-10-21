module PC(	
    input wire clk,reset,
    input wire [31:0] PCNext,
    output wire [31:0] PC);
   
    reg [31:0] PCReg;

    always@(posedge clk or posedge reset)
    begin
	if (reset) PCReg <= 0;
	else PCReg <= PCNext;
    end	

   assign PC = PCReg;

endmodule

module PC_Plus_4(
	input wire [31:0] PC,
	output wire [31:0] PCPlus4);

    assign PCPlus4 = PC + 32'd4;

endmodule

module PC_Target(
		input wire [31:0] PC,ImmExt,
		output wire [31:0] PCTarget
		);

   assign PCTarget= PC + ImmExt;

endmodule

module PC_Mux(
	input wire [31:0] PC_Plus_4, PC_Target,
    input wire PCSrc,
	output wire [31:0] PC_Next);

   assign PC_Next = PCSrc ? PC_Target : PC_Plus_4;

endmodule
 
