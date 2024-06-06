module dataMemory(address, write_data,write_enable,read_data,clock);

input [31:0] address;
input [31:0] write_data;
input write_enable;
input clock;
output reg[31:0] read_data;

reg [31:0] mem [15:0];
initial begin
    mem[0]  = 32'h00010001; 
    mem[1]  = 32'h00010100;
    mem[2]  = 32'h00000001; 
    mem[3]  = 32'h00011000;
    mem[4]  = 32'h00011100; 
    mem[5]  = 32'h00010001; 
    mem[6]  = 32'h00000011;
    mem[7]  = 32'h00010001; 
    mem[8]  = 32'h00001001; 
    mem[9]  = 32'h00000001;
    mem[10] = 32'h00000110; 
    mem[11] = 32'h00000001; 
    mem[12] = 32'h00010010; 
end



always @(posedge clock) begin
    read_data <= mem[address[3:0]];

    if (write_enable) begin
        mem[address[3:0]] <= write_data; 
    end 
end


endmodule
