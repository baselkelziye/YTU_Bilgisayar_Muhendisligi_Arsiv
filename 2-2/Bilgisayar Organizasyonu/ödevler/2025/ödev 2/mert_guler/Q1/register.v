module register(WE3, clk, A1, A2, A3, WD3, RD1, RD2);
    input WE3, clk;
    input [4:0] A1, A2, A3;
    input [31:0] WD3;
    output reg [31:0] RD1, RD2;
    reg [31:0] registerFile[31:0];
    
    always@(posedge clk)
    if (WE3)
        registerFile[A3] <= WD3;
    
    always@(*) begin
        RD1 = (A1 != 0) ? registerFile[A1] : 0;
        RD2 = (A2 != 0) ? registerFile[A2] : 0;
    end

endmodule