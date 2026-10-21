module Data_Memory(input clk, WE,
	input [31:0] A, WD,
    output [31:0] RD);

    reg [31:0] RAM[63:0];

    assign RD = RAM[A[31:2]];

    initial begin
    RAM[0]  = 32'h0000000F;
    RAM[1]  = 32'h0000000D; 
    RAM[2]  = 32'h0000000A;
    RAM[3]  = 32'h00000003; 
    RAM[4]  = 32'h00000004; 
    RAM[5]  = 32'h00000009;  
    end

    always @(posedge clk)
        if (WE)
        RAM[A[31:2]] <= WD;

endmodule