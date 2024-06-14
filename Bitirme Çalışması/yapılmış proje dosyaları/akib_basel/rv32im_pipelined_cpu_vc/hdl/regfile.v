
module regfile(
    input clk_i,
    input rst_i,
    input write_en_i,
    input [4:0] rd_i,
    input [31:0] rd_data_i,
    input [4:0] rs1_i,
    input [4:0] rs2_i,
    output [31:0] rs1_data_o,
    output [31:0] rs2_data_o
);

    reg [31:0] registers [31:1]; // Array of 31 registers (register 0 is always 0)
    integer i;
    // Synchronous register write on the positive edge of the clock
    always @(*)//make this * solved the problem?
    begin
        if (rst_i)
        begin
            // Reset all registers to 0
          
            for (i = 1; i < 32; i = i + 1)
                registers[i] <= 32'h00000000;
        end
        else if (write_en_i && rd_i != 0) // Ensure rd_i is not 0, as x0 is always 0
        begin 
            registers[rd_i] <= rd_data_i;
        end
    end

    reg [31:0] rs1_value_r, rs2_value_r;

    // Asynchronous read on the negative edge of the clock
    always @(negedge clk_i)
    begin
        rs1_value_r <= (rs1_i == 0) ? 32'h00000000 : registers[rs1_i];
        rs2_value_r <= (rs2_i == 0) ? 32'h00000000 : registers[rs2_i];
    end

    assign  rs1_data_o = rs1_value_r;
    assign  rs2_data_o = rs2_value_r;

endmodule
