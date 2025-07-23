// RegFile.v
module RegFile (
    input         clk,
    input         we3,        // write enable
    input  [4:0]  ra1, ra2, ra3,  // read addresses
    input  [4:0]  wa3,       // write address
    input  [31:0] wd3,       // write data
    output [31:0] rd1, rd2   // read data
);
    
    reg [31:0] regs [0:31];
    integer i;

    initial begin
        for (i = 0; i < 32; i = i + 1)
            regs[i] = 32'd0;
    end

    always @(posedge clk) begin
        if (we3 && wa3 != 5'd0)
            regs[wa3] <= wd3;
    end

    assign rd1 = (ra1 != 5'd0) ? regs[ra1] : 32'd0;
    assign rd2 = (ra2 != 5'd0) ? regs[ra2] : 32'd0;
endmodule
