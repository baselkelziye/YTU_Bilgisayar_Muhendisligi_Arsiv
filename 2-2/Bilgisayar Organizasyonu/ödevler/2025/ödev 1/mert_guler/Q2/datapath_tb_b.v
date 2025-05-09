`include "../02/datapath.v"
`include "../02/regfile.v"
`include "../01/alu.v"

module datapath_tb_b;
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
        $dumpfile("datapath_b.vcd");
        $dumpvars(0, datapath_tb_b);

        // R1 = 0, R1 - R1 = 0
        addr1 = 2'd1; addr2 = 2'd1; addr3 = 2'd1;
        ALUControl = 3'b001; // SUB
        wr = 1; #10; 
        wr = 0; #10;

        // R0 = -1, R2 AND R2 (R2 = -1)
        addr1 = 2'd2; addr2 = 2'd2; addr3 = 2'd0;
        ALUControl = 3'b010; // AND
        wr = 1; #10; 
        wr = 0; #10;

        // R2 = R1 - 1, R1 ADD R0 (R0 = -1), Result = -1
        addr1 = 2'd1; addr2 = 2'd0; addr3 = 2'd2;
        ALUControl = 3'b000; // ADD
        wr = 1; #10; wr = 0; #10;

        // R3 = R0 + 1, R0 SUB R0 (-R0 = 1)  Result = 0
        addr1 = 2'd0; addr2 = 2'd0; addr3 = 2'd3;
        ALUControl = 3'b001; // SUB
        wr = 1; #10; wr = 0; #10;
        $finish;
    end
endmodule
