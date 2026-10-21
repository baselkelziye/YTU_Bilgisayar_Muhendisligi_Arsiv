// File: 24011949_imem.v
// Instruction memory for the ARRAY/COUNT program.
// The machine codes are embedded directly, so no extra machine-code file is required.

module imem(
    input  [31:0] a,
    output [31:0] rd
);

  reg [31:0] RAM [0:63];

  initial begin
    RAM[0]  = 32'h00000093; // addi x1, x0, 0      ; ARRAY base address = 0
    RAM[1]  = 32'h05000113; // addi x2, x0, 80     ; COUNT base address = 80
    RAM[2]  = 32'h01400193; // addi x3, x0, 20     ; number of array elements

    RAM[3]  = 32'h0000A283; // lw   x5, 0(x1)      ; load ARRAY[i]
    RAM[4]  = 32'h00000313; // addi x6, x0, 0      ; count = 0
    RAM[5]  = 32'h00100393; // addi x7, x0, 1      ; mask = 1, starts from bit 0
    RAM[6]  = 32'h01000493; // addi x9, x0, 16     ; 16 even-positioned bits

    RAM[7]  = 32'h0072F433; // and  x8, x5, x7     ; test selected even bit
    RAM[8]  = 32'h00040463; // beq  x8, x0, +8     ; skip increment if bit is 0
    RAM[9]  = 32'h00130313; // addi x6, x6, 1      ; count++
    RAM[10] = 32'h007383B3; // add  x7, x7, x7     ; mask <<= 1
    RAM[11] = 32'h007383B3; // add  x7, x7, x7     ; mask <<= 2
    RAM[12] = 32'hFFF48493; // addi x9, x9, -1     ; bit counter--
    RAM[13] = 32'h00048463; // beq  x9, x0, +8     ; if finished, store count
    RAM[14] = 32'hFE5FF06F; // jal  x0, -28        ; repeat inner loop

    RAM[15] = 32'h00612023; // sw   x6, 0(x2)      ; COUNT[i] = count
    RAM[16] = 32'h00408093; // addi x1, x1, 4      ; next ARRAY address
    RAM[17] = 32'h00410113; // addi x2, x2, 4      ; next COUNT address
    RAM[18] = 32'hFFF18193; // addi x3, x3, -1     ; element counter--
    RAM[19] = 32'h00018463; // beq  x3, x0, +8     ; if all elements done, finish
    RAM[20] = 32'hFBDFF06F; // jal  x0, -68        ; repeat outer loop
    RAM[21] = 32'h0000006F; // jal  x0, 0          ; infinite halt loop
  end

  assign rd = RAM[a[31:2]];

endmodule
