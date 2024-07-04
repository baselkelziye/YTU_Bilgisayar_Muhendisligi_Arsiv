`timescale 1ns / 1ps

module imm_gen(
    input [24:0]instr_i,
    input [2:0] imm_sel_i,
    output [31:0]imm_o
    );
    
    reg [31:0]imm_r; 
    
    always @ (instr_i or imm_sel_i) begin 
    
    case(imm_sel_i)
    3'b000: // U-Type
        imm_r = {instr_i[24:5],12'h0};
    3'b001: // J-Type
        imm_r = { {32{instr_i[24]}}, {instr_i[12:5]}, {instr_i[13]}, {instr_i[23:14]}, {1'b0} };
    3'b010: // S-Type
        imm_r = { {32{instr_i[24]}}, {instr_i[23:18]}, {instr_i[4:0]}};    
    3'b011: // B-Type
        imm_r = { {32{instr_i[24]}}, {instr_i[0]}, {instr_i[23:18]},{instr_i[4:1]}, {1'b0} }; 
    3'b100: // I-Type Signed
        imm_r = { {32{instr_i[24]}}, {instr_i[24:13]} };
    3'b101: // I-Type Shift
        imm_r = { {32{instr_i[24]}}, {instr_i[17:13]} };
    3'b111: // I-Type Unsigned
        imm_r = { {32'h0}, {instr_i[24:13]} };
    
    endcase
    end
    
    assign imm_o = imm_r;
    
endmodule