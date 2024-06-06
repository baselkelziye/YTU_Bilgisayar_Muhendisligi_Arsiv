`include "22011647_riscv.v"
module testbench();
    reg clk;
    reg reset;
    wire [31:0] WriteData, DataAdr;
    wire MemWrite;
    integer i;


    top uut (
        .clk(clk), 
        .reset(reset), 
        .WriteData(WriteData), 
        .DataAdr(DataAdr), 
        .MemWrite(MemWrite)
    );

    initial begin
        reset <= 1;
        #22; 
        reset <= 0;
    end

    always begin
        clk <= 1; 
        #1; 
        clk <= 0; 
        #1;
    end

    always @(negedge clk) begin

        /*if($time<636) begin
            $display("At time %d: DataAdr = %0d, WriteData = %0d, MemWrite = %0b", $time, DataAdr, WriteData, MemWrite);
            $display("r5: %d  r6: %d  r7: %d  , x3: %d, X2: %d , X8: %d,  x9: %d", uut.rvsingle.dp.rf.rf[5],uut.rvsingle.dp.rf.rf[6],uut.rvsingle.dp.rf.rf[7],uut.rvsingle.dp.rf.rf[3],uut.rvsingle.dp.rf.rf[2],uut.rvsingle.dp.rf.rf[8], uut.rvsingle.dp.rf.rf[9]);      
        end*/

        
        if($time>636) begin
            $display("At time %d: r3: %d", $time,uut.rvsingle.dp.rf.rf[3]);
        end

        if($time > 790) begin
            for(i=40; i<60;i=i+1)begin
                $display("RESULT[%d]: %d",i-40, uut.dmem.RAM[i]);
            end    
            $finish;
        end
    end

    initial begin
        $dumpfile("22011647.vcd"); 
        $dumpvars(0, testbench);
    end
endmodule

