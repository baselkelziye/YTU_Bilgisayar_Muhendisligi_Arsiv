`include "../02/datapath.v"
`include "../02/regfile.v"
`include "../01/alu.v"

module datapath_tb_a;
    reg clk, rst, wr;
    reg [1:0] addr1, addr2, addr3;
    reg [2:0] ALUControl;

    datapath dp(
        .clk(clk), .rst(rst), .wr(wr),
        .addr1(addr1), .addr2(addr2), .addr3(addr3),
        .ALUControl(ALUControl)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        $dumpfile("datapath_a.vcd");
        $dumpvars(0, datapath_tb_a);

        // R0 = R1 + R2
        addr1 = 2'd1; addr2 = 2'd2; addr3 = 2'd0;
        ALUControl = 3'b000; // ADD
        wr = 1; #10; 
        wr = 0; #10;

        // R1 = R2 AND R3
        addr1 = 2'd2; addr2 = 2'd3; addr3 = 2'd1;
        ALUControl = 3'b010; // AND
        wr = 1; #10; wr = 0; #10;

        // R3 = R2 XOR R0
        addr1 = 2'd2; addr2 = 2'd0; addr3 = 2'd3;
        ALUControl = 3'b011; // XOR
        wr = 1; #10; wr = 0; #10;

        // R2 = R1 - R3
        addr1 = 2'd1; addr2 = 2'd3; addr3 = 2'd2;
        ALUControl = 3'b001; // SUB
        wr = 1; #10; wr = 0; #10;
        $finish;
    end
endmodule
