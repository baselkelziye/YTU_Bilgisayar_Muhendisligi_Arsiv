`timescale 1ns / 1ps
//TODO

//6.01.2023
//forwarding unitte is_memory_instruction ne ise yariyor?
//store da yonlendirme ne isi yariyor?
//data cache forward ne ayak?

//if_id_o ve id_ex_o lari resetlemek lazim.
//if_id_o icin addi x0,x0,0 i koyabiliriz muxla?

//TEKNOFEST ICIN YAPILACAKLAR
//koda yorum ekle, daha anlasilir yap. gereksiz sinyalleri sil.
//otomatik bi sekilde OBJ KODLARI OKUYUP INSTURCTION CACHE'e YERLESTIR
//memory erisiminde adres alignment bakilacak mi?
//resetleri aktif 0 yap
//Hazard detection yapinca aradaki komutu NOP yapmamiz gerekir mi?

module cpu( input clk_i,
            input rst_i,
            input [31:0] instr_mem_read_i,
            input [31:0] data_mem_read_i,
            input data_busy_i,
            input inst_busy_i,
            
            output inst_mem_read_o,
            output data_mem_read_o,
            output data_mem_write_o,
            output [31:0] instr_addr_o,
            output [31:0] data_addr_o,
            output [31:0] data_mem_w_data_o);
    
    wire [31:0] PC_last_w;  
    wire [31:0] PC_w;
    wire [31:0] PC_4_w;
    wire [31:0] instruction_if_id_i;
    wire [31:0] data_data_w;
    
    //***********IF-ID STAGE VARIABLES************
    wire [31:0] pc_if_id_o; //ID asamasina giren PC olduugu icin PC_ID_O isimlend
    wire [31:0] instruction_if_id_o;     
    
    wire [4:0] rd_if_id_o  = instruction_if_id_o[11:7]; 
    wire [4:0] rs1_if_id_o = instruction_if_id_o[19:15]; 
    wire [4:0] rs2_if_id_o = instruction_if_id_o[24:20];
    wire [6:0] instruction_opcode_if_id_o = instruction_if_id_o[6:0];
    wire [2:0] instruction_funct3_if_id_o = instruction_if_id_o[14:12];
    wire [6:0] instruction_funct7_if_id_o = instruction_if_id_o[31:25];
    wire [24:0] instruction_payload_if_id_o = instruction_if_id_o[31:7];
    
    //*******************ID-EX STAGE VARIABLES***********   
    wire [31:0] rs1_id_ex_i; // pass rs1 register ID/EX stage
    wire [31:0] rs1_id_ex_o;
    
    wire [31:0] pc_id_ex_o; //pass PC to ID/EX stage
    
    wire [31:0] rs2_id_ex_i; //pass rs2 to ID/EX stage
    wire [31:0] rs2_id_ex_o;
    
    wire [31:0] imm_id_ex_i; //pass imm to ID/EX stage
    wire [31:0] imm_id_ex_o;
    
    wire [2:0] imm_sel_id_ex_i; //control signal for imm
    wire [2:0] imm_sel_id_ex_o; 
     
    wire alu_op1_sel_id_ex_i; //alu op1 control signal 
    wire alu_op1_sel_id_ex_o;
       
    wire alu_op2_sel_id_ex_i; //alu op2 control signal
    wire alu_op2_sel_id_ex_o; 
    
    wire [4:0] alu_op_id_ex_i; //alu operation selection signal
    wire [4:0] alu_op_id_ex_o; 
    
    wire [2:0] branch_sel_id_ex_i; //branch unit selection
    wire [2:0] branch_sel_id_ex_o;  
    
    wire [3:0] read_write_sel_id_ex_i; //read write to cache
    wire [3:0] read_write_sel_id_ex_o; 
    
    wire [1:0] wb_sel_id_ex_i; //which value to write back
    wire [1:0] wb_sel_id_ex_o;
      
    wire reg_wb_en_id_ex_i; //writeback signal
    wire reg_wb_en_id_ex_o;  
    
    wire [4:0] rd_id_ex_o; //pass rd label for the writeback   
    wire [4:0] rs1_label_id_ex_o; //forwarding unit
    
    wire [4:0] rs2_label_id_ex_o;    
    wire [6:0] opcode_id_ex_o;
    wire is_memory_instruction_id_ex_o;
    
    //*****************EX-MEM******************
    wire [31:0] alu_out_ex_mem_i; // for alu output
    wire [31:0] alu_out_ex_mem_o;
    wire [1:0] wb_sel_ex_mem_i;
    wire reg_wb_en_ex_mem_i;
    wire reg_wb_en_ex_mem_o;
    wire [4:0] rd_ex_mem_i;
    wire [4:0] rd_ex_mem_o;  
    wire [31:0] pc_ex_mem_o;  
    wire [1:0] wb_sel_ex_mem_o; // control signal to WB                              
    wire [31:0] imm_ex_mem_o;   
    wire [3:0] read_write_sel_ex_mem_o;
    wire [4:0] rs1_label_ex_mem_o;
    wire [4:0] rs2_label_ex_mem_o;   
    wire [31:0] rs2_ex_mem_o; 
    wire is_memory_instruction_ex_mem_o;  
    wire PC_sel_w_ex_mem_o;
    
    // forwarding unit                   
    wire [31:0] alu_in1_forwarded_input;
    wire [31:0] alu_in2_forwarded_input;
    wire [1:0] forwardA;
    wire [1:0] forwardB;
    
    //    *********** MEM-WB STAGE ***************
    wire reg_wb_en_mem_wb_i;
    wire reg_wb_en_mem_wb_o;  
    wire [4:0] rd_mem_wb_o;  
    wire [31:0] alu_out_mem_wb_o;  
    wire [1:0] wb_sel_mem_wb_o; // control signal to write back to reg file (which value) 
    wire [31:0] rd_data_mem_wb_i;
    wire [31:0] rd_data_mem_wb_o; 
    wire [31:0] imm_mem_wb_o;
    wire [31:0] pc_mem_wb_o;
    wire [3:0] read_write_sel_mem_wb_o;
    wire is_memory_instruction_mem_wb_o; 
    wire [31:0] rs2_mem_wb_o;   
    wire [31:0] pc_mem_wb_o_4; 

    //************ tmp values *******************\\
    
    //tmp control signals
    wire is_memory_signal;
    wire is_load_instruction_id_ex_i;
    wire stall;
    wire [31:0] alu_in1_w;
    wire [31:0] alu_in2_w; 
    wire [31:0] reg_wb_data_w;
    wire data_busy_w;
    wire ins_busy_w;
    wire busy_w;
    wire write_en_w;
    
    assign busy_w = (data_busy_w | ins_busy_w);
    assign write_en_w = (reg_wb_en_mem_wb_o & !busy_w); //reg i mem_wb_o yapmak laizm en son

    //Bu mux Program Counterin degerini seciyor
    //girisler: 
    //in0: PC + 4
    //in1: ALU Res
    //select ucu: ex_mem asamasinin cikisinda olan "Dallanma sinyali"
    //cikis: yeni PC                  
    mux #(
        .DATA_WIDTH(32), //each data is 32 wide
        .NUM_INPUTS(2)   // 2x1 mux, each line is 32bit
    ) u_PC_mux (
        .in_flat(
            {alu_out_ex_mem_o,   //ALU de hesaplanan dallanacak adres (in1)
             PC_4_w              //normal PC degeri mi (in0)
            }), 
        .select(PC_sel_w_ex_mem_o), // jump biriminde tetiklenir
        .out(PC_last_w)             // cikis: yeni PC
    );
    
    //PC_reg basit bir flipflop gibi dusunulebilir, giristeki PC degeri cikisa aktarir
    pc_reg r_pc_reg(
        .clk_i(clk_i),     //saat derbesinde PC registerdeki degeri disariya verir
        .rst_i(rst_i),
        .busy_i(busy_w),   //PC i degistiginde 1 olur, ne zaman okunursa 0'a duser
        .stall(stall),
        .PC_i(PC_last_w),  // giris PC
        .PC_o(PC_w)        // cikis PC
    );
    
    //Su an ki PC degerini 4 ile toplar
    pc_adder u_pc_adder(
        .in_i(PC_w),       //PC i 4 ile toplar
        .out_o(PC_4_w)
    );
    
    //Komutlarin saklandigi hafiza                    
    instr_cache c_instr_cache(
        .clk_i(clk_i),
        .rst_i(rst_i),
        .address_i(PC_w),                     //PC i gir
        .read_data_o(instruction_if_id_i),    // komut getir
        .busy_o(ins_busy_w)
    );

    //******* IF-ID PIPELINE MODULE**********        
    // "_i" ile biten giris, "_o" ile biten cikistir          
    if_id_stage_reg if_id(
        .clk_i(clk_i),
        .rst_i(rst_i),
        .busywait(busy_w),
        .stall(stall),
        .flush(PC_sel_w_ex_mem_o),
        .instruction_if_id_i(instruction_if_id_i),
        .pc_if_id_i(PC_w),
        .instruction_if_id_o(instruction_if_id_o),
        .pc_if_id_o(pc_if_id_o)
    );

    //Yazmaclarin durdugu yer
    regfile u_regfile
    (
        .clk_i(clk_i                  ),
        .rst_i(rst_i                  ),
        .write_en_i(reg_wb_en_mem_wb_o),//yazmaca yaz sinyali (mem/wb asamasindan gelir)
        .rd_i(rd_mem_wb_o             ),//rd yazmac numarasi
        .rd_data_i(reg_wb_data_w      ),//rd yazmac degeri
        .rs1_i(rs1_if_id_o            ),//rs1 yazmac numarasi (okumak icin)
        .rs2_i(rs2_if_id_o            ),//rs2 yazmac numarasi (okumak icin)
        .rs1_data_o(rs1_id_ex_i       ),//rs1 yazmac degeri (cikis)
        .rs2_data_o(rs2_id_ex_i       )//rs2 yazmac degeri (cikis)
    );
    
    
    // Load Data Hazard durumlarindaki Pipeline'i stall etmek icin
    hazard_detection_unit hazard_detection_unit
    (
        .is_load_instruction(is_load_instruction_id_ex_o  ), // EX asamasinda LOAD islemi var
        .rd_label_id_ex_o(rd_id_ex_o                      ), // EX asamasinda RD
        .rs1_label_if_id_o(rs1_if_id_o                    ), // ID rs1 numarasi
        .rs2_label_if_id_o(rs2_if_id_o                    ), // ID rs2 numarasi
        .stall(stall                                      )  // cikis stall sinyali
    );

    
    
    //Control Unit (umutun raporuna bakilmali)
    control_unit u_control_unit(
        .opcode_i(instruction_opcode_if_id_o),
        .funct3_i(instruction_funct3_if_id_o),
        .funct7_i(instruction_funct7_if_id_o),
        .imm_sel_o(imm_sel_id_ex_i),
        .op1_sel_o(alu_op1_sel_id_ex_i),
        .op2_sel_o(alu_op2_sel_id_ex_i),
        .alu_op_o(alu_op_id_ex_i),
        .branch_sel_o(branch_sel_id_ex_i),
        .read_write_o(read_write_sel_id_ex_i),
        .wb_sel_o(wb_sel_id_ex_i),
        .reg_w_en_o(reg_wb_en_id_ex_i),
        .is_memory_instruction_o(is_memory_signal),
        .is_load_instruction(is_load_instruction_id_ex_i)
    );
    
    //Anlik genisletme birimi (umutun ara raporuna bakilmali)
    imm_gen u_imm_gen(
        .instr_i(instruction_payload_if_id_o),
        .imm_sel_i(imm_sel_id_ex_i),
        .imm_o(imm_id_ex_i) // ID-EX yazmacina imm-gen sonucu yaz
    );
                         
    //Dallanma birimi (umutuun raporuna bakilmali)
    branch_jump u_branch_jump(
        .in1_i(alu_in1_w),          //alu output yap
        .in2_i(alu_in2_w),
        .bj_sel_i(branch_sel_id_ex_o), //sinyal
        .PC_sel_o(PC_sel_w)            //sinyal
    );
        
    //****************ID-EX PIPELINE REGISTER**************
    wire flush_id_ex_o;
    id_ex_stage_reg id_ex(
        .clk_i(clk_i),
        .rst_i(rst_i),
        .busywait(busy_w),
        .flush(PC_sel_w_ex_mem_o),
        .pc_id_ex_i(pc_if_id_o),          //passing PC for the Branch UNIT
        .pc_id_ex_o(pc_id_ex_o),
        
        .rs1_id_ex_i(rs1_id_ex_i),       // passing rs1 32 bit value
        .rs1_id_ex_o(rs1_id_ex_o),
        
        .rs2_id_ex_i(rs2_id_ex_i),       //passinng rs2 32bit value
        .rs2_id_ex_o(rs2_id_ex_o),
        
        .imm_id_ex_i(imm_id_ex_i),       // passing the 32bit imm result
        .imm_id_ex_o(imm_id_ex_o),
        
        .imm_sel_id_ex_i(imm_sel_id_ex_i),//passing 3 bit selection for imm unit
        .imm_sel_id_ex_o(imm_sel_id_ex_o),
        
        .alu_op1_sel_id_ex_i(alu_op1_sel_id_ex_i), //alu op1 1bitsignal
        .alu_op1_sel_id_ex_o(alu_op1_sel_id_ex_o),
        
        .alu_op2_sel_id_ex_i(alu_op2_sel_id_ex_i), //alu op2 1 bit signal
        .alu_op2_sel_id_ex_o(alu_op2_sel_id_ex_o),
        
        .alu_op_id_ex_i(alu_op_id_ex_i),   //alu operation signal 5bit
        .alu_op_id_ex_o(alu_op_id_ex_o),
        
        .branch_sel_id_ex_i(branch_sel_id_ex_i),   //branch unit select
        .branch_sel_id_ex_o(branch_sel_id_ex_o),   //signal 3 bit
        
        .read_write_sel_id_ex_i(read_write_sel_id_ex_i), //in case of stall, send 0
        //else send old value
        .read_write_sel_id_ex_o(read_write_sel_id_ex_o),
        
        .wb_sel_id_ex_i(wb_sel_id_ex_i),//
        .wb_sel_id_ex_o(wb_sel_id_ex_o),
        
        .reg_wb_en_id_ex_i(reg_wb_en_id_ex_i),
        .reg_wb_en_id_ex_o(reg_wb_en_id_ex_o),
        
        .rd_id_ex_i(rd_if_id_o),
        .rd_id_ex_o(rd_id_ex_o),
        .rs1_label_id_ex_i(rs1_if_id_o),
        .rs1_label_id_ex_o(rs1_label_id_ex_o),
        .rs2_label_id_ex_i(rs2_if_id_o),
        .rs2_label_id_ex_o(rs2_label_id_ex_o),
        .opcode_id_ex_i(instruction_opcode_if_id_o),
        .opcode_id_ex_o(opcode_id_ex_o),
        .is_memory_instruction_id_ex_i(is_memory_signal),
        .is_memory_instruction_id_ex_o(is_memory_instruction_id_ex_o),
        .is_load_instruction_id_ex_i(is_load_instruction_id_ex_i),
        .is_load_instruction_id_ex_o(is_load_instruction_id_ex_o)
    );
                         
     //Yonlendirma birimi, kendi dosyasinda aciklama yapildi
    forwarding_unit forwarding_unit(
        .rd_label_ex_mem_o(rd_ex_mem_o),
        .rd_label_mem_wb_o(rd_mem_wb_o),
        .rs1_label_id_ex_o(rs1_label_id_ex_o),
        .rs2_label_id_ex_o(rs2_label_id_ex_o),
        .reg_wb_en_ex_mem_o(reg_wb_en_ex_mem_o),
        .reg_wb_en_mem_wb_o(reg_wb_en_mem_wb_o),
        .is_memory_instruction_mem_wb_o(is_memory_instruction_mem_wb_o),
        .forwardA(forwardA),
        .forwardB(forwardB),
        .opcode(opcode_id_ex_o)
    );
    
    
        //bu mux RS1 degerinin en guncelini secer (forwarding unit ile)
    mux #(
        .DATA_WIDTH(32),
        .NUM_INPUTS(4)   
    ) rs1_latest_value_selector (
        .in_flat(
        {rd_data_mem_wb_o, // LOAD sonucu
         alu_out_ex_mem_o, // ex_mem deki ALU sonucu
         alu_out_mem_wb_o, // mem_wb deki ALU sonucu
         rs1_id_ex_o}),    // reg file dan okunan rs1 degeri
        .select(forwardA), // Selection signal
        .out(alu_in1_w)    // Output of the MUX
    );


    mux #(
        .DATA_WIDTH(32),    
        .NUM_INPUTS(2)      
    ) pc_or_rs1_selector (
        .in_flat(
        {pc_id_ex_o,                  //PC degeri
         alu_in1_w}),                 // En guncel rs1 degeri
        .select(alu_op1_sel_id_ex_o), 
        .out(alu_in1_forwarded_input) 
    );


    //Asagidaki iki mux yukari ile ayni sadece farkli seyleri seciyor
    mux #(
        .DATA_WIDTH(32),    
        .NUM_INPUTS(2)      
    ) imm_or_rs2_selector (
        .in_flat(
        {imm_id_ex_o,                  //imm degeri
         alu_in2_w}),                  // en guncel rs2 degeri
        .select(alu_op2_sel_id_ex_o),  
        .out(alu_in2_forwarded_input)       
    );

   
    mux #(
        .DATA_WIDTH(32),    
        .NUM_INPUTS(4)      
    ) rs2_latest_value_selector (
        .in_flat(
        {rd_data_mem_wb_o, 
         alu_out_ex_mem_o,
         alu_out_mem_wb_o,
         rs2_id_ex_o}), 
        .select(forwardB),         
        .out(alu_in2_w) 
    );
                                   
    alu u_alu(
        .alu1_i(alu_in1_forwarded_input),  //bunlar anlik cikis oldugu icin pipeline'a girmelerine gerek yok.
        .alu2_i(alu_in2_forwarded_input),
        .alu_op_i(alu_op_id_ex_o),
        .result_o(alu_out_ex_mem_i)
    );

    wire [31:0] calculated_address;

    ex_mem_stage_reg ex_mem(
        .clk_i(clk_i),
        .rst_i(rst_i),
        .busywait(busy_w),
        .alu_out_ex_mem_i(alu_out_ex_mem_i),
        .alu_out_ex_mem_o(alu_out_ex_mem_o),
        .reg_wb_en_ex_mem_i(reg_wb_en_id_ex_o),
        .reg_wb_en_ex_mem_o(reg_wb_en_ex_mem_o),
        .rd_ex_mem_i(rd_id_ex_o), //in_id nin cikisini ver buraya
        .rd_ex_mem_o(rd_ex_mem_o),
        .pc_ex_mem_i(pc_id_ex_o),
        .pc_ex_mem_o(pc_ex_mem_o),
        .wb_sel_ex_mem_i(wb_sel_id_ex_o),
        .wb_sel_ex_mem_o(wb_sel_ex_mem_o),
        .imm_ex_mem_i(imm_id_ex_o),
        .imm_ex_mem_o(imm_ex_mem_o),
        .rs1_label_ex_mem_i(rs1_label_id_ex_o),
        .rs1_label_ex_mem_o(rs1_label_ex_mem_o),
        .rs2_label_ex_mem_i(rs2_label_id_ex_o),
        .rs2_label_ex_mem_o(rs2_label_ex_mem_o),
        .read_write_sel_ex_mem_i(read_write_sel_id_ex_o),
        .read_write_sel_ex_mem_o(read_write_sel_ex_mem_o),
        .rs2_ex_mem_i(alu_in2_w),
        .rs2_ex_mem_o(rs2_ex_mem_o),
        .is_memory_instruction_ex_mem_i(is_memory_instruction_id_ex_o),
        .is_memory_instruction_ex_mem_o(is_memory_instruction_ex_mem_o),
        .PC_sel_w_ex_mem_i(PC_sel_w),
        .PC_sel_w_ex_mem_o(PC_sel_w_ex_mem_o)
    );
                 
    wire [31:0] data_cache_data_out;
    wire [31:0] data_address_forwarded_input;

    data_cache c_data_cache(
        .clk_i(clk_i),
        .rst_i(rst_i),
        .address_i(alu_out_ex_mem_o),
        .write_data_i(rs2_ex_mem_o), //rs2 n�n de�erini ta�� yaz oraya
        .read_write_sel_i(read_write_sel_ex_mem_o),
        .read_data_o(data_cache_data_out),
        .busy_o(data_busy_w)
    );
   
    mem_wb_stage_reg mem_wb(
        .clk_i(clk_i),
        .rst_i(rst_i),
        .busywait(busy_w),
        .reg_wb_en_mem_wb_i(reg_wb_en_ex_mem_o),
        .reg_wb_en_mem_wb_o(reg_wb_en_mem_wb_o),
        .rd_mem_wb_i(rd_ex_mem_o),
        .rd_mem_wb_o(rd_mem_wb_o),
        .rd_data_mem_wb_i(data_cache_data_out),
        .rd_data_mem_wb_o(rd_data_mem_wb_o),
        .alu_out_mem_wb_i(alu_out_ex_mem_o),
        .alu_out_mem_wb_o(alu_out_mem_wb_o),
        .wb_sel_mem_wb_i(wb_sel_ex_mem_o),
        .wb_sel_mem_wb_o(wb_sel_mem_wb_o),
        .imm_mem_wb_i(imm_ex_mem_o),
        .imm_mem_wb_o(imm_mem_wb_o),
        .pc_mem_wb_i(pc_ex_mem_o),
        .pc_mem_wb_o(pc_mem_wb_o),
        .is_memory_instruction_mem_wb_i(is_memory_instruction_ex_mem_o),
        .is_memory_instruction_mem_wb_o(is_memory_instruction_mem_wb_o),
        .rs2_mem_wb_i(rs2_ex_mem_o),
        .rs2_mem_wb_o(rs2_mem_wb_o)
    );

    pc_adder u_pc_adder1(
        .in_i(pc_mem_wb_o), //PC i 4 ile toplar
        .out_o(pc_mem_wb_o_4) // cunku son muxta PC+4 var, su ana kadar sadece PC i ilettik biz, 4 ile toplayip yollamamiz lazim.
    );

    mux #(
        .DATA_WIDTH(32),    // Set the data width of each input to 32 bits
        .NUM_INPUTS(4)      // Set the number of inputs to 4 (for a 4-to-1 MUX)
    ) u_wb_mux (
        .in_flat({pc_mem_wb_o_4, imm_mem_wb_o, rd_data_mem_wb_o, alu_out_mem_wb_o}), // Concatenate inputs for the mux
        .select(wb_sel_mem_wb_o),    // Selection signal
        .out(reg_wb_data_w)          // Output of the MUX
    );
     
endmodule
