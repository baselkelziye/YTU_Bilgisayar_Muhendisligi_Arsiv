module pcAdder (pc_in,addingval, pc_out);
    input [31:0] pc_in, addingval; 
    output reg [31:0] pc_out; 

    always @(*) begin
        pc_out = pc_in + addingval;
    end
endmodule