`include "ALU_32.v"

module ALU_32_tb;

reg [31:0] a, b;
reg [2:0] alucontrol;
wire [31:0] result;

ALU_32 uut (
    .result(result),
    .a(a),
    .b(b),
    .alucontrol(alucontrol)
);

initial begin
    
    a=32'h00000000; b=32'h00000000; alucontrol=3'b000; #1;
    a=32'h00000001; b=32'h00000010; alucontrol=3'b000; #1;
    a=32'h00000010; b=32'h00000011; alucontrol=3'b000; #1;
    a=32'h11000000; b=32'h11000001; alucontrol=3'b000; #1;
    a=32'h11011000; b=32'h01110000; alucontrol=3'b000; #1;
    a=32'h00000000; b=32'h11111111; alucontrol=3'b000; #1;
    a=32'h11111111; b=32'h11111111; alucontrol=3'b000; #5;

    a=32'h00000000; b=32'h00000000; alucontrol=3'b001; #1;
    a=32'h00000001; b=32'h00000010; alucontrol=3'b001; #1;
    a=32'h00000010; b=32'h00000011; alucontrol=3'b001; #1;
    a=32'h11000000; b=32'h11000001; alucontrol=3'b001; #1;
    a=32'h11011000; b=32'h01110000; alucontrol=3'b001; #1;
    a=32'h00000000; b=32'h11111111; alucontrol=3'b001; #1;
    a=32'h11111111; b=32'h11111111; alucontrol=3'b001; #5;

    a=32'h00000000; b=32'h00000000; alucontrol=3'b010; #1;
    a=32'h00000001; b=32'h00000010; alucontrol=3'b010; #1;
    a=32'h00000010; b=32'h00000011; alucontrol=3'b010; #1;
    a=32'h11000000; b=32'h11000001; alucontrol=3'b010; #1;
    a=32'h11011000; b=32'h01110000; alucontrol=3'b010; #1;
    a=32'h00000000; b=32'h11111111; alucontrol=3'b010; #1;
    a=32'h11111111; b=32'h11111111; alucontrol=3'b010; #5;

    a=32'h00000000; b=32'h00000000; alucontrol=3'b011; #1;
    a=32'h00000001; b=32'h00000010; alucontrol=3'b011; #1;
    a=32'h00000010; b=32'h00000011; alucontrol=3'b011; #1;
    a=32'h11000000; b=32'h11000001; alucontrol=3'b011; #1;
    a=32'h11011000; b=32'h01110000; alucontrol=3'b011; #1;
    a=32'h00000000; b=32'h11111111; alucontrol=3'b011; #1;
    a=32'h11111111; b=32'h11111111; alucontrol=3'b011; #5;

    a=32'h00000000; b=32'h00000000; alucontrol=3'b101; #1;
    a=32'h00000001; b=32'h00000010; alucontrol=3'b101; #1;
    a=32'h00000010; b=32'h00000011; alucontrol=3'b101; #1;
    a=32'h11000000; b=32'h11000001; alucontrol=3'b101; #1;
    a=32'h11011000; b=32'h01110000; alucontrol=3'b101; #1;
    a=32'h00000000; b=32'h11111111; alucontrol=3'b101; #1;
    a=32'h11111111; b=32'h11111111; alucontrol=3'b101; #5;

    $finish;
end


initial begin
        $dumpfile("ALU_32_tb.vcd");
        $dumpvars(0, ALU_32_tb);
    end

endmodule

//iverilog -o ALU_32_tb.vvp ALU_32_tb.v
//vvp ALU_32_tb.vvp

