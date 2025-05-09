module instruction_memory(A, RD);
    input [31:0] A;
    output reg [31:0] RD;
    
    reg [31:0] memory[31:0];

    initial begin
        memory[0] = 32'h00100093; // addi x1, x0, 1
        memory[1] = 32'h00200113; // addi x2, x0, 2
        memory[2] = 32'h002091b3; // sll x3, x1, x2 => 0001 -> 0100 = 4
        memory[3] = 32'h22222237; // lui x4, 0x22222 -> 0x22222000
    end

    always @(*) begin
        RD = memory[A[31:2]];
    end
endmodule
