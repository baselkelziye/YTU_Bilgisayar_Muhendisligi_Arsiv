`timescale 1ns / 1ps

module if_id_stage_reg(
    input clk_i,
    input rst_i,
    input busywait,
    input [31:0] instruction_if_id_i,
    input [31:0] pc_if_id_i,//jump birimi PC i kullandigi icin onu da iletmemiz gerekiyor boru hattinda

    input stall,
    input flush,
    output reg [31:0] instruction_if_id_o,
    output reg [31:0] pc_if_id_o

    );
    
    always @(*)
     begin
        if(rst_i || flush) 
        begin
        #0.1;
        pc_if_id_o = 32'd0;
        instruction_if_id_o = 32'h00000013;//addi x0,x0,0      
        end
     end   
     
     
     always @(posedge clk_i)
     begin
        #0;
        if(!busywait && !stall)
            begin
            pc_if_id_o <= pc_if_id_i;
            instruction_if_id_o <= instruction_if_id_i;
            end
     end        
endmodule