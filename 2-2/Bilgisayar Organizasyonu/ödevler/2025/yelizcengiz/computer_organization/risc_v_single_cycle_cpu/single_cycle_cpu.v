module single_cycle_cpu (
    input clk,
    input reset
);

    reg [31:0] pc;
    wire [31:0] instr;
    reg [31:0] instr_mem[0:255];

    initial begin
    pc = 0;
    //lui x5, 0x00010  → x5 = 0x00010000
    instr_mem[0] = 32'h000105B7;
    //lui x5, 0x12345 → x5 = 0x12345000
    instr_mem[1] = 32'h123452B7;
end

    assign instr = instr_mem[pc[9:2]];

    wire [6:0]  opcode = instr[6:0];
    wire [4:0]  rd     = instr[11:7];
    wire [2:0]  funct3 = instr[14:12];
    wire [4:0]  rs1    = instr[19:15];
    wire [4:0]  rs2    = instr[24:20];
    wire        funct7b5 = instr[30];

    wire        regwrite, alusrc, memwrite, branch, jump;
    wire [1:0]  resultsrc, imm_src, alu_op;
    wire [2:0]  alu_control;
    wire [31:0] rd1, rd2, immext, srcb, result, alu_result;
    wire        zero;

    control_unit CU(opcode, regwrite, alusrc, memwrite, resultsrc, imm_src, branch, jump, alu_op);
    alu_decoder ALUDEC(alu_op, funct3, funct7b5, alu_control);
    regfile RF(clk, regwrite, rs1, rs2, rd, result, rd1, rd2);
    imm IG(instr, imm_src, immext);
    alu ALU(rd1, srcb, alu_control, alu_result, zero);

    assign srcb   = alusrc ? immext : rd2;

    reg [31:0] data_mem[0:255];
    wire [31:0] readdata = data_mem[alu_result[9:2]];

    always @(posedge clk) begin
        if (memwrite)
            data_mem[alu_result[9:2]] <= rd2;
    end

    assign result = (resultsrc == 2'b00) ? alu_result :
                    (resultsrc == 2'b01) ? readdata :
                    (resultsrc == 2'b10) ? pc + 4 :
                    (resultsrc == 2'b11) ? immext : 32'd0;

    wire [31:0] pc_target = pc + immext;
    wire        pcsrc = branch & zero;

    always @(posedge clk or posedge reset) begin
        if (reset)
            pc <= 0;
        else if (jump)
            pc <= pc_target;
        else if (pcsrc)
            pc <= pc_target;
        else
            pc <= pc + 4;
    end
endmodule
