module registerFile(address1, address2, address3, readData1, readData2, writeData, clk, regWrite, reset);
    
    input clk, regWrite, reset;
    input [4:0] address1, address2, address3;
    input [31:0] writeData;
    
    output [31:0] readData1, readData2;
    
    reg [31:0] register[3:0];
    initial register[0] = 32'h12345678;
    initial register[1] = 32'h9ABCDEF0;
    initial register[2] = 32'hFFFFFFFF;
    initial register[3] = 32'h00000001;
    
    assign readData1 = register[address1];
    assign readData2 = register[address2];
   
    always @(posedge clk) begin
        if(reset) begin
            register[0] <= 0;
            register[1] <= 0;
            register[2] <= 0;
            register[3] <= 0;
        end
        if(regWrite) begin
            register[address3] <= writeData;
        end
    end
endmodule

