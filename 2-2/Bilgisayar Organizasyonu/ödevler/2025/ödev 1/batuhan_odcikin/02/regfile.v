`define WORD_SIZE 32

//  Register File
module regfile(
        addr1, addr2, addr3, data1, data2, data3, clk, wr, rst
    );
    
    // Declare Input Variables
    input clk, wr, rst;
    input [1:0] addr1, addr2, addr3;
    input [`WORD_SIZE-1:0] data3;
    
    // Declare Output Variables
    output [`WORD_SIZE-1:0] data1, data2;
    
    // Reigsters
    reg [`WORD_SIZE-1:0] register[3:0];
    initial register[0] = 32'h12345678;
    initial register[1] = 32'h9ABCDEF0;
    initial register[2] = 32'hFFFFFFFF;
    initial register[3] = 32'h00000001;
    
    assign data1 = register[addr1];
    assign data2 = register[addr2];
   
    always @(posedge clk) begin
        if(rst) begin
            register[0] <= 0;
            register[1] <= 0;
            register[2] <= 0;
            register[3] <= 0;
        end
        if(wr) begin
            register[addr3] <= data3;
        end
    end
endmodule

//iverilog -o regfile regfile.v