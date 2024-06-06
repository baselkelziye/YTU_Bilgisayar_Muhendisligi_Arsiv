module pcCounter (clk, reset, pc_in, pc_out);
    input clk, reset;
    input [31:0] pc_in; 
    output reg [31:0] pc_out; 

    always @ (posedge clk or posedge reset)
    begin
        if (reset == 1'b1)
            pc_out = 0; 
        else
            pc_out <= pc_in; 
    end
endmodule