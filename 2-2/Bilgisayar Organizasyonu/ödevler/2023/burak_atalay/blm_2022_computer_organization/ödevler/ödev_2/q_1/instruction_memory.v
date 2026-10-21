module Instruction_Memory(
    input [31:0] A,
	output [31:0] RD);

    reg [31:0] MEMORY_BLOCK[63:0];
    
    initial
    begin
        MEMORY_BLOCK[0]  = 32'h00400093;
        MEMORY_BLOCK[1]  = 32'h3e800113;
        MEMORY_BLOCK[3]  = 32'h402081b3;
        MEMORY_BLOCK[4]  = 32'h0020a1b3;
        MEMORY_BLOCK[5]  = 32'h0020e1b3;
        MEMORY_BLOCK[6]  = 32'h0020f1b3;
        MEMORY_BLOCK[7]  = 32'h00208c63;
        MEMORY_BLOCK[8]  = 32'h00a08193;
        MEMORY_BLOCK[9]  = 32'h00a0a193;
        MEMORY_BLOCK[10] = 32'h00a0e193;
        MEMORY_BLOCK[11] = 32'h00a0f193;
        MEMORY_BLOCK[12] = 32'h008000ef;
        MEMORY_BLOCK[13] = 32'h00a0e193;
        MEMORY_BLOCK[14] = 32'h00a0a193;
    end

   assign RD = MEMORY_BLOCK[A[31:2]];

endmodule