`timescale 1ns / 1ps

module cpu_tb();

reg CLK, RESET;

cpu u_cpu(  .clk_i(CLK),
            .rst_i(RESET),
            .instr_mem_read_i(),
            .data_mem_read_i(),
            .data_busy_i(),
            .inst_busy_i(),
            .inst_mem_read_o(),
            .data_mem_read_o(),
            .data_mem_write_o(),
            .instr_addr_o(),
            .data_addr_o(),
            .data_mem_w_data_o());


initial begin

    CLK = 1'b0;
    RESET = 1'b1;
    #5;
    RESET = 1'b1;
    #10;
    RESET = 1'b0;

#1000
$finish;

end

always begin
    #1 CLK = ~CLK;
end


endmodule