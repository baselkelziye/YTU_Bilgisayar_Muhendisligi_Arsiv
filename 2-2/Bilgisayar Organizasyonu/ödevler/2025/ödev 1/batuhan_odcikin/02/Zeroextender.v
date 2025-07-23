module ZeroExtender(
    input in,              // 1-bit input
    output [31:0] out      // 32-bit zero-extended output
);
    assign out = {31'b0, in}; // Concatenate 31 zeros with the input
endmodule
