module program_counter(reset, clk, pc_in, pc_out);
    input clk, reset;
    input [31:0] pc_in;
    output reg [31:0] pc_out;

    always@(posedge clk)
    if (reset)
        pc_out <= 32'b00000000;
    else
        pc_out <= pc_in;    

endmodule