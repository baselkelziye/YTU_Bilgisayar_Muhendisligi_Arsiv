module Register_File(
		input clk, WE3,
		input [4:0] RA1, RA2, WA3,
		input [31:0] WD3,
		output [31:0] RD1, RD2
		);

    reg [31:0] MEMORY_BLOCK[31:0];

    always@(posedge clk)
    begin
	if(WE3)
	  MEMORY_BLOCK[WA3] <= WD3;
    end

   assign RD1 = (RA1 != 0) ? MEMORY_BLOCK[RA1] : 0;
   assign RD2 = (RA2 != 0) ? MEMORY_BLOCK[RA2] : 0;

endmodule