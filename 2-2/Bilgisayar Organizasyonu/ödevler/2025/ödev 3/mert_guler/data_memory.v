module data_memory(WE, clk, A, WD, RD);
    input WE, clk;
    input [31:0] A, WD;
    output [31:0] RD;
    
    reg [31:0] memory[512:0];
    integer i;
    
    assign RD = memory[A[31:2]];

    initial begin
    $readmemh("array_data.hex", memory, 0, 19);
    end

    always @(posedge clk) begin
        if (WE) 
           memory[A[31:2]] <= WD;
    end
      
endmodule