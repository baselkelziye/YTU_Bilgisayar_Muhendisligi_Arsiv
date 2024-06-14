`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

//Forwarding unit.
//Result from load instruction is forwarded when ForwardA/B is  = 3 (2'b11)
//Since load instruction's value can be forwarded only from mem/wb stage (load hazard) only that case is checked.
//we add is_memory_instruction_mem_wb_o to check if the instruction is load, if yes we forward the value from LOAD, if its not we pass alu result.
//ex/mem is simple. not addition logic needed.
//////////////////////////////////////////////////////////////////////////////////


module forwarding_unit(
    input [4:0] rd_label_ex_mem_o,
    input [4:0] rd_label_mem_wb_o,
    input [4:0] rs1_label_id_ex_o,
    input [4:0] rs2_label_id_ex_o,
    
    input reg_wb_en_ex_mem_o,
    input reg_wb_en_mem_wb_o,
    input is_memory_instruction_mem_wb_o,
    input [6:0] opcode,
    output reg [1:0]  forwardA,
    output reg  [1:0]  forwardB
    );
    
    always @(rs1_label_id_ex_o, reg_wb_en_ex_mem_o, reg_wb_en_mem_wb_o, rd_label_ex_mem_o, rd_label_mem_wb_o,is_memory_instruction_mem_wb_o) begin
    
    if (    reg_wb_en_mem_wb_o && //wb writes to destination
           (rd_label_mem_wb_o != 0) &&  //rd is not r0 
           (rd_label_mem_wb_o == rs1_label_id_ex_o) && // rd (in mem/wb) = r1 
            !(reg_wb_en_ex_mem_o && (rd_label_ex_mem_o != 0) && (rd_label_ex_mem_o == rs1_label_id_ex_o)) && // double data forwarding problem
            //if ex/mem and mem/wb forwards to same register, we should take the newest (ex/mem)
            // EX: add x3,x2,x1
            //MEM: add x1, x4,x0
            //WB: add x1, x5,x0
            // data should be forwarded from MEM because its the UPDATED VALUE
            !is_memory_instruction_mem_wb_o //is mem/wb stage the instruction is not load (data will come from alu out)
            ) begin
            forwardA = 2'b01; 
        end
     else  if(  reg_wb_en_mem_wb_o &&   //Everything is the same but here its LOAD instruction. (data comes form the data loaded from memory)
               (rd_label_mem_wb_o != 0) &&  
               (rd_label_mem_wb_o == rs1_label_id_ex_o) && 
               !(reg_wb_en_ex_mem_o && (rd_label_ex_mem_o != 0) && (rd_label_ex_mem_o == rs1_label_id_ex_o)) &&
                is_memory_instruction_mem_wb_o)
                begin
                 forwardA = 2'b11;
                end
        
        else if(rd_label_ex_mem_o != 5'b0  && //rd != 0
           reg_wb_en_ex_mem_o && // instruction writes to destınation register
           rd_label_ex_mem_o == rs1_label_id_ex_o) //
           begin
            forwardA = 2'b10;//RS1 = EX/MEM RD
           end
                
        else 
            begin
            forwardA = 2'b00; //no forwarding
            end 
    end
    
    
    //every thing is the same here but instead of rs1, we compare RS2
        always @(rs2_label_id_ex_o, reg_wb_en_ex_mem_o, reg_wb_en_mem_wb_o, rd_label_ex_mem_o, rd_label_mem_wb_o,is_memory_instruction_mem_wb_o) begin    

        if(rd_label_ex_mem_o  && 
           reg_wb_en_ex_mem_o &&
           rd_label_ex_mem_o == rs2_label_id_ex_o)
            begin                               
                    forwardB = 2'b10; // RS2 = EX/MEM  RD
            end         
                 
        else if(reg_wb_en_mem_wb_o &&  //yaz sinyali = 1
               (rd_label_mem_wb_o != 0) &&   // kaynak yazmac != 0
               (rd_label_mem_wb_o == rs2_label_id_ex_o) && // kaynak yazmac su an EX asamasinda var
        !(reg_wb_en_ex_mem_o && (rd_label_ex_mem_o != 0) && (rd_label_ex_mem_o == rs2_label_id_ex_o)) &&
            !is_memory_instruction_mem_wb_o) begin  
            forwardB = 2'b01;   //RS2 = MEM/WB RD
        end
     else  if(reg_wb_en_mem_wb_o &&  //yaz sinyali = 1
               (rd_label_mem_wb_o != 0) &&   // kaynak yazmac != 0
               (rd_label_mem_wb_o == rs2_label_id_ex_o) && // kaynak yazmac su an EX asamasinda var
        !(reg_wb_en_ex_mem_o && (rd_label_ex_mem_o != 0) && (rd_label_ex_mem_o == rs2_label_id_ex_o)) &&
            is_memory_instruction_mem_wb_o)
                begin
                 forwardB = 2'b11;
                end
        else
            begin
            forwardB = 2'b00; //no forwarding
            end
    end
    endmodule




    

//endmodule

