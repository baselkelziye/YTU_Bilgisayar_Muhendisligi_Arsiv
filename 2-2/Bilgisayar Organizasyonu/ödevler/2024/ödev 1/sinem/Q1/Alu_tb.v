`include "Alu.v"

module Alu_tb;

    reg[31:0] A,B;
    reg[2:0] ALUControl;
    wire[31:0] result;

    Alu a1(result,A,B,ALUControl);

    initial begin
        
        $dumpfile("Alu.vcd");
        $dumpvars(0,Alu_tb);
        
        A = 32'd25342; B = 32'd0; ALUControl = 3'b000;
        #1;
        A = 32'd2134; B = 32'd2134; ALUControl = 3'b001;
        #1;
        A = 32'd56431; B = 32'd343455; ALUControl = 3'b010;
        #1;
        A = 32'd1433; B = 32'd39435; ALUControl = 3'b011;
        #1;
        A = 32'd1; B = 32'd12355; ALUControl = 3'b100;
        #1;
        A = 32'd1; B = 32'd1; ALUControl = 3'b101;
        #1;
        A = 32'd1; B = 32'd1; ALUControl = 3'b111;
        #1;
        A = 32'd34321; B = 32'd545230; ALUControl = 3'b011;
        #1;
        A = 32'd165; B = 32'd12; ALUControl = 3'b010;
        #1;
        A = 32'd1345; B = 32'd12462; ALUControl = 3'b001;
        #1;
        A = 32'd4521; B = 32'd100; ALUControl = 3'b011;
        #1;
        A = 32'd4562; B = 32'd5453; ALUControl = 3'b001;

    end

endmodule