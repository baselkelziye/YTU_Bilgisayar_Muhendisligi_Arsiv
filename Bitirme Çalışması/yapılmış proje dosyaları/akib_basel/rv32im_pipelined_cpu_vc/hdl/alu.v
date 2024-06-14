`timescale 1ns / 1ps
module alu (input [31:0]alu1_i,
            input [31:0]alu2_i,
            input [4:0] alu_op_i,
            output [31:0]result_o);

            reg [63:0]mul_r;
            reg [31:0]result_r;
            
            always @ (alu1_i or alu2_i or alu_op_i) begin
                
                case (alu_op_i)
                5'b00000:   //ADD
                result_r = alu1_i + alu2_i;
                5'b00010:   //SUB
                result_r = alu1_i - alu2_i;
                5'b00100:   //SLL
                result_r = alu1_i << alu2_i;
                5'b01000:   //SLT
                result_r = $signed(alu1_i) < $signed(alu2_i) ? 1 : 0;
                5'b01100:   //SLTU
                result_r = alu1_i < alu2_i ? 1 : 0;
                5'b10000:   //XOR
                result_r = alu1_i ^ alu2_i;
                5'b10100:   //SRL
                result_r = alu1_i >> alu2_i;
                5'b10110:   //SRA
                result_r = $signed(alu1_i) >>> alu2_i;
                5'b11000:   //OR
                result_r = alu1_i | alu2_i;
                5'b11100:   //AND
                result_r = alu1_i & alu2_i;
                5'b00001:   //MUL
                result_r = alu1_i * alu2_i;
                5'b00101:   //MULH 
                begin
                    mul_r = $signed(alu1_i) * $signed(alu2_i);
                    result_r = mul_r[63:32];
                end
                5'b01001:   //MULHU
                begin
                    mul_r = $unsigned(alu1_i) * $unsigned(alu2_i);
                    result_r = mul_r[63:32];
                end
                5'b01101:   //MULHSU
                begin
                    mul_r = $signed(alu1_i) * $unsigned(alu2_i);
                    result_r = mul_r[63:32];
                end
                5'b10001:   //DIV
                begin
                    if(alu2_i == 32'h0) begin
                    result_r = -32'h1; 
                    end else if(alu1_i[31] == 1'b1 && alu2_i == -32'h1) begin 
                    result_r = alu1_i;
                    end else begin 
                    result_r = $signed(alu1_i) / $signed(alu2_i);
                    end
                end
                5'b10101:   //DIVU
                begin
                    if(alu2_i == 32'h0) begin
                    result_r = (2**32)-1;
                    end else begin 
                    result_r = $unsigned(alu1_i) / $unsigned(alu2_i);
                    end
                end
                5'b11001:   //REM 
                begin
                if(alu2_i == 32'h0) begin
                    result_r = alu1_i; 
                    end else if(alu1_i[31] == 1'b1 && alu2_i == -32'h1) begin 
                    result_r = 32'h0;
                    end else begin 
                    result_r = $signed(alu1_i) % $signed(alu2_i);
                    end
                end
                5'b11101:   //REMU
                begin
                if(alu2_i == 32'h0) begin
                    result_r = alu1_i;
                    end else begin 
                    result_r = $unsigned(alu1_i) % $unsigned(alu2_i);
                    end
                end
                endcase
            end
            
            assign result_o = result_r;


endmodule