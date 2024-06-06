`include "completeRISCV.v"

module completeRISCV_tb;

  reg  clk;
  reg  reset;

  wire [31:0] WriteData, DataAdr;
  wire  MemWrite;

  completeRiscv dut(clk, reset, WriteData, DataAdr, MemWrite);
  
  initial begin
    $dumpfile("completeRISCV_tb.vcd");
    $dumpvars(0, completeRISCV_tb);
  end

  always begin
    #5; clk = 1; #5; clk = 0;
  end

  always @(negedge clk) begin
    
    if(MemWrite) begin
      if((DataAdr == 100) && (WriteData == 25)) begin
        $display("Simulation succeeded");
        $stop;
      end
      else if (DataAdr != 96) begin
        $display("Simulation failed");
        $stop;
      end
    end
  end
endmodule
