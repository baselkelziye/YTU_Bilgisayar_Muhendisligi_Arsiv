`timescale 1ns / 1ps


module branch_jump(
    input [31:0]in1_i,
    input [31:0]in2_i,
    input [2:0]bj_sel_i,
    output PC_sel_o
    );
    
    reg equal_r;
    reg less_t_r;
    
    reg out_sel_r;
    
    always @ (in1_i or in2_i or bj_sel_i) begin
        
    if (bj_sel_i < 3'b110) begin 
        if($signed(in1_i) == $signed(in2_i)) begin
            equal_r = 1'b1;
        end else begin
            equal_r = 1'b0;
        end 
        if($signed(in1_i) < $signed(in2_i)) begin 
            less_t_r = 1'b1;
        end else begin
            less_t_r = 1'b0;
        end
    end else begin 
        if($unsigned(in1_i) == $unsigned(in2_i)) begin
            equal_r = 1'b1;
        end else begin
            equal_r = 1'b0;
        end 
        if($unsigned(in1_i) < $unsigned(in2_i)) begin 
    
        end else begin
        
        end
    end
    
    case(bj_sel_i)
    3'b000:
        out_sel_r = equal_r;
    3'b001:
        out_sel_r = ~equal_r;
    3'b010:
        out_sel_r = 1'b0;
    3'b011:
        out_sel_r = 1'b1;
    3'b100:
        out_sel_r = less_t_r;
    3'b101:
        out_sel_r = equal_r | ~less_t_r;
    3'b110:
        out_sel_r = less_t_r;
    3'b111:
        out_sel_r = equal_r | ~less_t_r;
    endcase
    end
    
    assign PC_sel_o = out_sel_r;
    
endmodule