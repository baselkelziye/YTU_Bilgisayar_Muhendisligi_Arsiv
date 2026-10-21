//THIS IS PROCESSOR WITHOUT INSTRUCTION MEMORY

module RiscV_SingleCycle(
    input clk,
    input reset,
    output reg [31:0] pc,
    input [31:0] instruction,
    output reg [31:0] alu_result,
    output [31:0] write_data,
    input [31:0] read_data
);

    // Define memory
    reg [31:0] memory[0:1023]; // 1K words of memory

    // Register and next PC logic
    reg [31:0] next_pc;
    reg [31:0] registers[0:31];

    // Decode fields from instruction
    wire [6:0] opcode = instruction[6:0];
    wire [4:0] rd = instruction[11:7];
    wire [4:0] rs1 = instruction[19:15];
    wire [4:0] rs2 = instruction[24:20];
    wire [2:0] funct3 = instruction[14:12];
    wire [6:0] funct7 = instruction[31:25];
    wire [31:0] rs1_data = registers[rs1];
    wire [31:0] rs2_data = registers[rs2];

    // Immediate value processing
    wire signed [31:0] imm_i = {{20{instruction[31]}}, instruction[30:20]};
    wire signed [31:0] imm_s = {{20{instruction[31]}}, instruction[30:25], instruction[11:7]};
    wire [31:0] sign_extended_imm = (opcode == 7'b0000011 || opcode == 7'b0100011) ? imm_s : imm_i;

    // PC and reset handling
   always @(posedge clk or posedge reset) begin
        if (reset) begin
            pc <= 0;  // Initialize PC to 0 or a known address on reset
        end else begin
            pc <= next_pc;  // Update PC to the next PC
        end
    end

    // ALU operation
    reg [31:0] alu_out;
    always @(*) begin
        case (opcode)
            7'b0110011: // R-type operations
                case (funct3)
                    3'b000: alu_out = (funct7 == 7'b0000000) ? rs1_data + rs2_data : rs1_data - rs2_data;
                    3'b101: alu_out = (funct7 == 7'b0000000) ? rs1_data >> rs2_data[4:0] : $signed(rs1_data) >>> rs2_data[4:0];
                    3'b110: alu_out = rs1_data | rs2_data;
                    3'b111: alu_out = rs1_data & rs2_data;
                    3'b010: alu_out = ($signed(rs1_data) < $signed(rs2_data)) ? 1 : 0;
                endcase
            7'b1101111: // JAL
                begin
                    next_pc = pc + {{11{instruction[31]}}, instruction[19:12], instruction[20], instruction[30:21], 1'b0};
                    registers[rd] <= pc + 4;
                end
            7'b1100011: // BEQ
                if (funct3 == 3'b000 && rs1_data == rs2_data) begin
                   next_pc = pc + {{19{instruction[31]}}, instruction[7], instruction[30:25], instruction[11:8], 1'b0};
                   
                   $display("nexpc=%d",next_pc);
                end else begin
                    $display("girmedi=%d",next_pc);
                end

            7'b0000011: alu_out = rs1_data + sign_extended_imm; // LW
            7'b0100011: alu_out = rs1_data + sign_extended_imm; // SW
            7'b0010011: // I-type ALU operations
                case (funct3)
                    3'b000: alu_out = rs1_data + sign_extended_imm;
                    3'b110: alu_out = rs1_data | sign_extended_imm;
                    3'b111: alu_out = rs1_data & sign_extended_imm;
                    3'b010: alu_out = ($signed(rs1_data) < $signed(sign_extended_imm)) ? 1 : 0;
                endcase
        endcase
    end

     // Update alu_result on clock edge to capture the computed ALU output
    always @(posedge clk) begin
        alu_result <= alu_out;
    end

    
    // Write data to registers and handle load/store
    assign write_data = registers[rd];
    always @(posedge clk) begin
        if (!reset && rd != 0) begin
            if (opcode == 7'b0000011) // LW
                registers[rd] <= memory[alu_out[9:0]]; // Read from memory
            else if (opcode != 7'b0100011) // Not SW
                registers[rd] <= alu_out;
        end
        if (opcode == 7'b0100011) // SW
            memory[alu_out[9:0]] <= rs2_data; // Write to memory
    end

    // Update next_pc
    always @(posedge clk or posedge reset) begin
        if (!reset && opcode != 7'b1100011 && opcode != 7'b1101111)
            next_pc <= pc + 4;
    end

    always @(posedge clk) begin
    $display("Time: %t, Opcode: %b, Funct3: %b, RS1 Data: %d, RS2 Data: %d, ALU Result: %d",
             $time, opcode, funct3, rs1_data, rs2_data, alu_result);
end


endmodule
