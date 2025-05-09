module instruction_memory(A, RD);
    input [31:0] A;
    output reg [31:0] RD;
    
    reg [31:0] memory[31:0];

    initial begin
        memory[0] = 32'h00100093; // addi x1, x0, 1
        memory[1] = 32'h00200113; // addi x2, x0, 2
        memory[2] = 32'h002081B3; // add x3, x1, x2 -> 3
        memory[3] = 32'h40218233; // sub x4, x3, x2 -> 1
        memory[4] = 32'h0041A2B3; // slt x5, x3, x4 -> 0
        memory[5] = 32'h0031e333; // or x6, x3, x3 -> 3
        memory[6] = 32'h0031f3b3; // and x7, x3, x3 -> 3
        memory[7] = 32'h00100413; // addi x8, x0, 1 -> 1
        memory[8] = 32'h00702023; // sw x7, 0(x0) -> mem(0) = 1
        memory[9] = 32'h00312493; // slti x9, x2, 3 -> 1
        memory[10] = 32'h00016513; // ori x10, x2, 0 -> 2
        memory[11] = 32'h00517593; // andi x11, x2, 5 -> 0
        memory[12] = 32'h00002603; // lw x12, 0(x0) -> 1
        memory[13] = 32'h004006ef; // jal x13, 4 -> 00000038
        memory[14] = 32'h02618063; // beq x3, x6, +32 -> 00000058
    end

    always @(*) begin
        RD = memory[A[31:2]];
    end
endmodule
