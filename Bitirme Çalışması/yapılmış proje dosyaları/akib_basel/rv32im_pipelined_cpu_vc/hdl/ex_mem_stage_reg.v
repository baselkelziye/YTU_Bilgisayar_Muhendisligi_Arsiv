`timescale 1ns / 1ps

module ex_mem_stage_reg(
    input clk_i,
    input rst_i,
    input busywait,
    
    input [31:0] alu_out_ex_mem_i, //ALU CIKISI
    input reg_wb_en_ex_mem_i, //writeback control sinyali
    input [4:0] rd_ex_mem_i,
    input [31:0] pc_ex_mem_i,
    input [1:0] wb_sel_ex_mem_i,
    input [31:0] imm_ex_mem_i,
    input [4:0] rs1_label_ex_mem_i,
    input [4:0] rs2_label_ex_mem_i,
    input [3:0] read_write_sel_ex_mem_i,
    input [31:0] rs2_ex_mem_i,//data cache'a yazilacak deger
    input is_memory_instruction_ex_mem_i,
    input PC_sel_w_ex_mem_i,
    
    
    output reg [31:0] alu_out_ex_mem_o,
    output reg reg_wb_en_ex_mem_o,
    output reg [4:0] rd_ex_mem_o,
    output reg [31:0] pc_ex_mem_o,//bunlara gerek yok aslinda cunku ALU nun cikisi direkt PC counter'a bagli bizde
    output reg [1:0] wb_sel_ex_mem_o,
    output reg [31:0] imm_ex_mem_o,
    output reg [4:0] rs1_label_ex_mem_o,
    output reg [4:0] rs2_label_ex_mem_o,
    output reg [3:0] read_write_sel_ex_mem_o, 
    output reg [31:0] rs2_ex_mem_o,
    output reg is_memory_instruction_ex_mem_o,
    output reg PC_sel_w_ex_mem_o
    
    
    );
    
    always @(*)begin
    #0.1;
        if(rst_i) begin
        alu_out_ex_mem_o <= 32'd0;
        reg_wb_en_ex_mem_o <= 0;
        rd_ex_mem_o <= 5'd0;
        pc_ex_mem_o <= 32'd0;
        wb_sel_ex_mem_o <= 2'd0;
        imm_ex_mem_o <= 32'd0;
        rs1_label_ex_mem_o <= 5'd0;
        rs2_label_ex_mem_o <= 5'd0;
        read_write_sel_ex_mem_o <= 4'd0;
        rs2_ex_mem_o <= 32'd0;
        is_memory_instruction_ex_mem_o <= 0;
        PC_sel_w_ex_mem_o <= 0;
        end
    end
    
    always @(posedge clk_i) begin
    #0;
       if(!busywait)begin
        alu_out_ex_mem_o <= alu_out_ex_mem_i;
        reg_wb_en_ex_mem_o <= reg_wb_en_ex_mem_i;
        rd_ex_mem_o <= rd_ex_mem_i;
        pc_ex_mem_o <= pc_ex_mem_i;
        wb_sel_ex_mem_o <= wb_sel_ex_mem_i;
        imm_ex_mem_o <= imm_ex_mem_i;
        rs1_label_ex_mem_o <= rs1_label_ex_mem_i;
        rs2_label_ex_mem_o <= rs2_label_ex_mem_i;
        read_write_sel_ex_mem_o <= read_write_sel_ex_mem_i;
        rs2_ex_mem_o <= rs2_ex_mem_i;
        is_memory_instruction_ex_mem_o <= is_memory_instruction_ex_mem_i;
        PC_sel_w_ex_mem_o <= PC_sel_w_ex_mem_i;
        end
        end
    
endmodule
