module regfile (
    input         clk,
    input         we3,
    input  [4:0]  ra1, ra2, wa3,
    input  [31:0] wd3,
    output [31:0] rd1, rd2
);
    reg [31:0] regs[31:0];

    assign rd1 = (ra1 != 0) ? regs[ra1] : 32'd0;
    assign rd2 = (ra2 != 0) ? regs[ra2] : 32'd0;

    always @(posedge clk) begin
        if (we3 && wa3 != 0)
            regs[wa3] <= wd3;
    end
endmodule