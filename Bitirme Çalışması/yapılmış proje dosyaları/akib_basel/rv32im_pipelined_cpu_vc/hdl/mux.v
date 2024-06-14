`timescale 1ns / 1ps


//Bu mux full parametrelerle calisir.
//DATA_WIDTH = veri yolu genisligi
//NUM_INPUTS giris sayisi.
//girisleri "{}" operatoru ile alir. {inX,inX-1,...in0} seklinde yollayin.
module mux
#(
    parameter DATA_WIDTH = 8,    // Width of each input
    parameter NUM_INPUTS = 4     // Number of inputs
)
(
    input wire [(DATA_WIDTH*NUM_INPUTS)-1:0] in_flat, // Flat input containing all inputs concatenated
    input wire [$clog2(NUM_INPUTS)-1:0] select,       // Selection line
    output reg [DATA_WIDTH-1:0] out                   // Output
);

integer i;

always @* begin
    out = {DATA_WIDTH{1'b0}}; // Default output to all zeros
    for (i = 0; i < NUM_INPUTS; i = i + 1) begin
        // Check if this input is selected
        if (select == i) begin
            out = in_flat[(i*DATA_WIDTH) +: DATA_WIDTH];
        end
    end
end

endmodule
