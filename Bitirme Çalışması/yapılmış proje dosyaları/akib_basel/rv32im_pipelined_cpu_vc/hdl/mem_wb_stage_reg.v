`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.12.2023 11:14:36
// Design Name: 
// Module Name: mem_wb_stage_reg
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module mem_wb_stage_reg(
    input clk_i,
    input rst_i,
    input busywait,
    
    input reg_wb_en_mem_wb_i,
    input [4:0] rd_mem_wb_i,
    input [31:0] rd_data_mem_wb_i,
    input [31:0] alu_out_mem_wb_i,
    input [1:0] wb_sel_mem_wb_i,
    input [31:0] imm_mem_wb_i,
    input [31:0] pc_mem_wb_i,
    input is_memory_instruction_mem_wb_i,
    input [31:0] rs2_mem_wb_i,
    
    output reg reg_wb_en_mem_wb_o,//write enable ucu
    output reg [4:0] rd_mem_wb_o,
    output reg [31:0] rd_data_mem_wb_o,
    output reg [31:0] alu_out_mem_wb_o,
    output reg [1:0] wb_sel_mem_wb_o,
    output reg [31:0] imm_mem_wb_o,
    output reg [31:0] pc_mem_wb_o,
    output reg is_memory_instruction_mem_wb_o,
    output reg [31:0] rs2_mem_wb_o

    );// rd yazmacin numaras
    
    
    always @(*)begin
    #0.1; 
        if(rst_i) begin
            reg_wb_en_mem_wb_o = 0;
            rd_mem_wb_o = 5'd0;
            rd_data_mem_wb_o = 32'd0;
            alu_out_mem_wb_o = 32'd0;
            wb_sel_mem_wb_o = 2'd0;
            imm_mem_wb_o = 32'd0;
            pc_mem_wb_o = 32'd0;
            is_memory_instruction_mem_wb_o = 0;
            rs2_mem_wb_o = 32'b0;
        end
    end
    
    always @(posedge clk_i)begin
    #0;     if(!busywait) begin
            reg_wb_en_mem_wb_o <= reg_wb_en_mem_wb_i;
            rd_mem_wb_o <= rd_mem_wb_i;
            rd_data_mem_wb_o <= rd_data_mem_wb_i;
            alu_out_mem_wb_o <=  alu_out_mem_wb_i;
            wb_sel_mem_wb_o <= wb_sel_mem_wb_i;
            imm_mem_wb_o <= imm_mem_wb_i;
            pc_mem_wb_o <= pc_mem_wb_i;
            is_memory_instruction_mem_wb_o <= is_memory_instruction_mem_wb_i;
            rs2_mem_wb_o <= rs2_mem_wb_i;
            end
    end
endmodule
