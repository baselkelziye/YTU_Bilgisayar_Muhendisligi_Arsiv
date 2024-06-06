`include "thirty_two_bit_not.v"

module thirty_two_bit_not_tb;

    reg[31:0] a;
    wire[31:0] out;

    thirty_two_bit_not not1(out,a);

    initial begin
        
        $dumpfile("thirty_two_bit_not_tb.vcd");
        $dumpvars(0,thirty_two_bit_not_tb);
        
        a = 32'd342325; 
        #1;
        a = 32'd12341;  
        #1;
        a = 32'd11111; 
        #1;
        a = 32'd546451; 
        #1;
        a = 32'd22123145; 
        #1;
        a = 32'd00000;  

    end

endmodule