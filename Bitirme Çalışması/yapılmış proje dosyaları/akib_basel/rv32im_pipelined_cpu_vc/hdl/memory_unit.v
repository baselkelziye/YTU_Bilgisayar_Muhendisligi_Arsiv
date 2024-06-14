`timescale 1ns / 1ps


module memory_unit(
    input clk,
    input [31:0] address,
    input RWMode,
    input reset,
    input [31:0] dataIn,
    output [31:0] dataOut,
    output hit
    );
    
    cache_memory u1(clk,address,RWMode,dataIn,reset,dataOut,hit);
endmodule