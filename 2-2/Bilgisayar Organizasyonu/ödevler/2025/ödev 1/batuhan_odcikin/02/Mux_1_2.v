module Mux_1_2 (
    input wire [31:0]a,       // Input 1
    input wire [31:0]b,       // Input 2
    input wire sel,     // Select signal
    output wire [31:0]y       // Output
);

    assign y = sel ? b : a;

endmodule