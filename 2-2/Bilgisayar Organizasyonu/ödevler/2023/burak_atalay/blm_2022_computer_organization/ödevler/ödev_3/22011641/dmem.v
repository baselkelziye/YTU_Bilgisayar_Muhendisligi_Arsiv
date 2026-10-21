module dmem(
    input clk, we,
    input [31:0] a, wd,
    output [31:0] rd
);
    reg [31:0] RAM[0:63];

    assign rd = RAM[a[31:2]]; // word aligned

    always @(posedge clk) begin
        if (we) begin
            RAM[a[31:2]] <= wd;
        end
    end

    // Initialize the data memory with ARR and COUNT values
    initial begin
        // Initialize ARR
        RAM[0]  <= 32'd3;
        RAM[1]  <= 32'd7;
        RAM[2]  <= 32'd2;
        RAM[3]  <= 32'd6;
        RAM[4]  <= 32'd5;
        RAM[5]  <= 32'd4;
        RAM[6]  <= 32'd1;
        RAM[7]  <= 32'd1000;
        RAM[8]  <= 32'd999;
        RAM[9]  <= 32'd25;
        RAM[10] <= 32'd90;
        RAM[11] <= 32'd100;
        RAM[12] <= 32'd30;
        RAM[13] <= 32'd20;
        RAM[14] <= 32'd10;
        RAM[15] <= 32'd200;
        RAM[16] <= 32'd3300;
        RAM[17] <= 32'd250;
        RAM[18] <= 32'd12;
        RAM[19] <= 32'd75;

        // Initialize COUNT
        RAM[20] <= 32'd17;
        RAM[21] <= 32'd13;
        RAM[22] <= 32'd18;
        RAM[23] <= 32'd14;
        RAM[24] <= 32'd15;
        RAM[25] <= 32'd16;
        RAM[26] <= 32'd19;
        RAM[27] <= 32'd1;
        RAM[28] <= 32'd2;
        RAM[29] <= 32'd9;
        RAM[30] <= 32'd6;
        RAM[31] <= 32'd5;
        RAM[32] <= 32'd8;
        RAM[33] <= 32'd10;
        RAM[34] <= 32'd12;
        RAM[35] <= 32'd4;
        RAM[36] <= 32'd0;
        RAM[37] <= 32'd3;
        RAM[38] <= 32'd11;
        RAM[39] <= 32'd7;
    end
endmodule

