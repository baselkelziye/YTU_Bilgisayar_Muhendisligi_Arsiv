`timescale 1ns / 1ps

module pc_reg(
    input clk_i,
    input rst_i,
    input [31:0]PC_i,
    input busy_i,
    input stall,
    output reg [31:0]PC_o
    );
    
    always @ (rst_i) begin
    
        if(rst_i) begin 
            #1; PC_o = 32'd0;
        end
    end
    
    
    always @ (posedge clk_i) begin
    #1; 
        if(!busy_i && !rst_i && !stall)  PC_o = PC_i;
    end
    
    
endmodule