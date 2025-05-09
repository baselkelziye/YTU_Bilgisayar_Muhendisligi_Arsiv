module data_memory(WE, clk, A, WD, RD);
    input WE, clk;
    input [31:0] A, WD;
    output [31:0] RD;
    
    reg [31:0] memory[31:0];
    
    assign RD = memory[A[31:2]];
    
    always @(posedge clk) begin
        if (WE) 
           memory[A[31:2]] <= WD;
    end
      
endmodule