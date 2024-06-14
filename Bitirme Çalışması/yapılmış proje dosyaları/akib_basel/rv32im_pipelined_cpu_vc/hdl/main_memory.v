`timescale 1ns / 1ps
`define OffsetSize 16
`define MemSize 4096
module main_memory(
    input clk,
    input [31:0] address,
    input [31:0] dataIn,
    input RWMode,
    input hit,
    input reset,
    
    output reg busy,
    output reg [511:0] dataOut
    );
    reg [31:0]memory[`MemSize-1:0];
    reg[511:0] offsetBlock;
    //reg[31:0] initialAddress;
    integer i;
    integer q;
    reg [31:0] tmpAddress;
    
    
    always @ (posedge clk) begin //when miss return block of data
        #0.1;
        busy = 1;
        if(address !== 32'bX && hit == 0 && RWMode == 0)begin
            q = 0;
            tmpAddress = address;
            for(i = 0; i < `OffsetSize ; i = i+1) begin
                offsetBlock[q +:32] = memory[tmpAddress];
                q = q + 32;
                tmpAddress = tmpAddress + 1;
            end
            dataOut = offsetBlock;
        end
        busy = 0;
    end
    
    always @ (posedge RWMode) begin // storing data
        if (RWMode == 1) begin
            memory[address] = dataIn;
        end
    end
    
    always @ (posedge reset) begin //reset
        busy = 1;
        if (reset == 1) begin
            for(i = 0; i < `MemSize; i = i+1) begin
                memory[i] = 32'b0;
            end
        end
        busy = 0;
    end
    
//    always @ (posedge clk) begin
//        initialAddress = {address[31:4],{4'b0000}};
//        q = 31;
//        for(i = 0; i < 16; i = i+1) begin
//            data_out[q-:32] = initialAddress;
//            q = q+32;
//            initialAddress = initialAddress + 1;
//        end
//    end
endmodule