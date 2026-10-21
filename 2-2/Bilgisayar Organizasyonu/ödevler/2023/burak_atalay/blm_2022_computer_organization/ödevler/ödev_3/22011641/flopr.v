module flopr #(
    parameter WIDTH = 8
)(
    input clk, reset,
    input [WIDTH-1:0] d,
    output [WIDTH-1:0] q
);
    reg [WIDTH-1:0] q;
    always @(posedge clk or posedge reset) begin
        if (reset) q <= 0;
        else q <= d;
    end
endmodule
