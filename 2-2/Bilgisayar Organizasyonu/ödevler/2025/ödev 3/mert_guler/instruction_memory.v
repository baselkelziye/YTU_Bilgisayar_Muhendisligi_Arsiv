module instruction_memory(A, RD);
    input [31:0] A;
    output reg [31:0] RD;
    
    reg [31:0] memory[512:0];

    initial begin
    $readmemh("instruction_data.hex", memory, 0, 16);
    end

    always @(*) begin
        RD = memory[A[31:2]];
    end
endmodule
