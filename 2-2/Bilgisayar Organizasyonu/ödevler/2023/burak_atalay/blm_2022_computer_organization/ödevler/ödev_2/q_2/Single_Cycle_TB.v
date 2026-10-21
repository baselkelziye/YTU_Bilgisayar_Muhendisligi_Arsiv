
`include "Single_Cycle_Top.v"

module Single_Cycle_TB();

reg clk = 0, reset;
wire [31:0] WriteData, DataAddress;
wire MemWrite;

always #10 clk = ~clk;

Single_Cycle_Top DUT(
	.clk(clk),
	.reset(reset),
	.WriteData(WriteData),
	.DataAddress(DataAddress),
	.MemWrite(MemWrite)
);

initial begin
    $dumpfile("Single_Cycle_TB.vcd");
    $dumpvars(0, Single_Cycle_TB);
    #20; reset = 0; 
    #20; reset = 1; 
	#20; reset = 0;
end

always@(posedge clk)  begin
  
    if(MemWrite) begin
      if(DataAddress == 100 & WriteData == 25) begin
        $display("PASSED: Data 25 written when Data Address is 100");
        $stop;
      end else if (DataAddress != 96) begin
        $display("FAILED");
        $stop;
      end
    end
end

endmodule
//iverilog -o Single_Cycle_TB.vvp Single_Cycle_TB.v
//vvp Single_Cycle_TB.vvp