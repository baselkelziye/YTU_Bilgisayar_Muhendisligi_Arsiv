`timescale 1ns / 1ps
`define BLOCKS 256
`define WORDS 16
`define SIZE 32
`define BLOCK_SIZE 512


module cache_memory(
    input clk,
    input [31:0]address,
    input RWMode,
    input [31:0]dataIn,
    input reset,
    
    output reg [31:0]dataOut,
    output reg hit,
    output reg busy
    );
    
    reg [`BLOCK_SIZE+20:0] buffer;
    reg [7:0] index;
    reg [3:0] blockOffset;
    reg [`BLOCK_SIZE+21:0] cache [`BLOCKS-1:0]; //BLOCK_SIZE + Valid bit + Tag 
    reg memReset;
   
    wire memBusy;
    wire [`BLOCK_SIZE-1:0]memDataOut;
    
    integer i;
    
    main_memory memory(.clk(clk),
                       .address(address),
                       .dataIn(dataIn),
                       .RWMode(RWMode),
                       .reset(memReset),
                       .hit(hit),
                       .busy(memBusy),
                       .dataOut(memDataOut));
    always @(posedge reset) begin //reset
        busy = 1;
        if (reset == 1) begin
            memReset = 1;
            for(i = 0; i <`BLOCKS; i = i+1) begin
                cache[i] = 534'b0;
            end
        end
        busy = 1;
    end
                       
    always @(posedge clk) begin //check hit or miss
        index = address[11:4];
        if(cache[index][0] == 1'b1 && cache[index][31:12] == address[31:12]) begin
            hit = 1;
        end
        else begin
            hit = 0;
        end
        #0.2;
        /////////////////////////////read-write data
        index = address[11:4];
        blockOffset = address[3:0];
        busy = 1;
        if(RWMode == 0 && address !==32'bX) begin
            if(hit == 1) begin
                dataOut = cache[index][32*blockOffset+21 +: 32];
                busy = 0;
            end                 
            else begin // if miss
                if(memBusy == 0) begin
                    buffer[0] = 1; //valid bit set to 1
                    buffer[20:1] = address[31:12]; //tag bit set
                    buffer[532:21] = memDataOut;
                    cache[index] = buffer;
                    dataOut = cache[index][32*blockOffset+21 +: 32]; 
                    busy = 0;
 
                end
            end
        end
        else if(RWMode == 1 && address !==32'bX) begin
            if(hit == 1) begin
               buffer[0] = 1; //valid bit set to 1
               buffer[20:1] = address[31:12]; //tag bit set
               buffer[532:21] = memDataOut;
               cache[index] = buffer;
               busy = 0;
            end
            else begin
               buffer[0] = 1; //valid bit set to 1
               buffer[20:1] = address[31:12]; //tag bit set
               buffer[532:21] = memDataOut;
               cache[index] = buffer;
               busy = 0;
            end
            dataOut = cache[index][32*blockOffset+21 +: 32];
        end
        /////////////////////////////eof read-write data
    end
    
endmodule