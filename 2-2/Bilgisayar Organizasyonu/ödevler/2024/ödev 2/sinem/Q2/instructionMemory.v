module instructionMemory(pc, instruction);

input [31:0] pc;
output reg [31:0] instruction;
reg [31:0] mem[13:0]; 

initial begin
    mem[0]  = 32'hFFC4A303; // lw x6, 0(x9) 
    mem[1]  = 32'h0032_A023; // sw  x3, 0(x5) 
    mem[2]  = 32'h0004a303 ; // add x9, x5, x6
    mem[3]  = 32'h406284b3 ; // sub x9, x5, x6
    mem[4]  = 32'h0062a4b3; // slt x9, x5, x6
    mem[5]  = 32'h0062e4b3; // or  x9, x5, x6
    mem[6]  = 32'h0062f4b3; // and x9, x5, x6
    mem[7]  = 32'h00649463; // beq x9, x6, 0x0000000C (PC + 12)
    mem[8]  = 32'h01000493; // addi x9, x0, 16
    mem[9]  = 32'h0801a493; // slti x9, x3, 128
    mem[10] = 32'h0142e493; // ori  x9, x5, 20
    mem[11] = 32'h02d27493; // andi x9, x4, 45
    mem[12] = 32'h000000ef; // jal  x1, 0x00000010 (PC + 16)
end

always @(*) begin
    instruction = mem[pc[3:0]]; 
end

endmodule