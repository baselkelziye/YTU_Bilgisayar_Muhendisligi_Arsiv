


  module half_adder(a,b,sum,carry);
 input a, b;
 output sum, carry;
 xor x1(sum, a, b);
 and a1(carry, a, b);
  endmodule



module full_adder(a, b, cin, sum, carry);
    input a, b, cin;
    output sum, carry;
    wire s1, c1, c2;
    half_adder ha1(a, b, s1, c1);
    half_adder ha2(s1, cin, sum, c2);
    or o1(carry, c1, c2);
endmodule


module four_bit_adder(a, b, cin, sum, carry);
    input [3:0] a, b;
    input cin;
    output [3:0] sum;
    output carry;
    wire c1, c2, c3;
    full_adder fa1(a[0], b[0], cin, sum[0], c1);
    full_adder fa2(a[1], b[1], c1, sum[1], c2);
    full_adder fa3(a[2], b[2], c2, sum[2], c3);
    full_adder fa4(a[3], b[3], c3, sum[3], carry);
endmodule


module thirty_two_bit_adder(a, b, cin, sum, carry);

    input [31:0] a, b;
    input cin;
    output [31:0] sum;
    output carry;
    wire [6:0] c;
    wire c_out;
    four_bit_adder fa1(a[3:0], b[3:0], cin, sum[3:0], c[0]);
    four_bit_adder fa2(a[7:4], b[7:4], c[0], sum[7:4], c[1]);
    four_bit_adder fa3(a[11:8], b[11:8], c[1], sum[11:8], c[2]);
    four_bit_adder fa4(a[15:12], b[15:12], c[2], sum[15:12], c[3]);
    four_bit_adder fa5(a[19:16], b[19:16], c[3], sum[19:16], c[4]);
    four_bit_adder fa6(a[23:20], b[23:20], c[4], sum[23:20], c[5]);
    four_bit_adder fa7(a[27:24], b[27:24], c[5], sum[27:24], c[6]);
    four_bit_adder fa8(a[31:28], b[31:28], c[6], sum[31:28], c_out);
    or o1(carry, c_out, c[6]);
endmodule



module and_4bit(a,b,out);
    input [3:0] a,b;
    output[3:0] out;

    and(out[0],a[0],b[0]);
    and(out[1],a[1],b[1]);
    and(out[2],a[2],b[2]);
    and(out[3],a[3],b[3]);

    
endmodule


module and_32bit(a,b,out);
 
 input [31:0] a,b;
    output[31:0] out;

     and_4bit and1(a[3:0],b[3:0],out[3:0]);
        and_4bit and2(a[7:4],b[7:4],out[7:4]);
        and_4bit and3(a[11:8],b[11:8],out[11:8]);
        and_4bit and4(a[15:12],b[15:12],out[15:12]);
        and_4bit and5(a[19:16],b[19:16],out[19:16]);
        and_4bit and6(a[23:20],b[23:20],out[23:20]);
        and_4bit and7(a[27:24],b[27:24],out[27:24]);
        and_4bit and8(a[31:28],b[31:28],out[31:28]);



endmodule


module xor_4bit(a,b,out);
    input [3:0] a,b;
    output[3:0] out;

    xor(out[0],a[0],b[0]);
    xor(out[1],a[1],b[1]);
    xor(out[2],a[2],b[2]);
    xor(out[3],a[3],b[3]);


endmodule




module xor_32bit(a,b,out);
 
 input [31:0] a,b;
    output[31:0] out;

     xor_4bit xor1(a[3:0],b[3:0],out[3:0]);
        xor_4bit xor2(a[7:4],b[7:4],out[7:4]);
        xor_4bit xor3(a[11:8],b[11:8],out[11:8]);
        xor_4bit xor4(a[15:12],b[15:12],out[15:12]);
        xor_4bit xor5(a[19:16],b[19:16],out[19:16]);
        xor_4bit xor6(a[23:20],b[23:20],out[23:20]);
        xor_4bit xor7(a[27:24],b[27:24],out[27:24]);
        xor_4bit xor8(a[31:28],b[31:28],out[31:28]);


endmodule



module or_4bit(a,b,out);
    input [3:0] a,b;
    output[3:0] out;

    or(out[0],a[0],b[0]);
    or(out[1],a[1],b[1]);
    or(out[2],a[2],b[2]);
    or(out[3],a[3],b[3]);


endmodule

module or_32bit(a,b,out);
 
 input [31:0] a,b;
    output[31:0] out;

     or_4bit or1(a[3:0],b[3:0],out[3:0]);
        or_4bit or2(a[7:4],b[7:4],out[7:4]);
        or_4bit or3(a[11:8],b[11:8],out[11:8]);
        or_4bit or4(a[15:12],b[15:12],out[15:12]);
        or_4bit or5(a[19:16],b[19:16],out[19:16]);
        or_4bit or6(a[23:20],b[23:20],out[23:20]);
        or_4bit or7(a[27:24],b[27:24],out[27:24]);
        or_4bit or8(a[31:28],b[31:28],out[31:28]);


endmodule


module zero_extend(a,out);
    input a;
    output [31:0] out;
   
    genvar i;
    generate
        for(i=1;i<32;i=i+1)
        begin
            xor(out[i],a,a);
        end
    endgenerate

    and(out[0],a,a);
endmodule


module not_32bit(a,out);
    input [31:0] a;
    output [31:0] out;

    genvar i;
    generate
        for(i=0;i<32;i=i+1)
        begin
            not n1(out[i],a[i]);
        end
    endgenerate
endmodule


// 32 bitlik sayının 2'lik tümleyeni 
module twos_complement(a,out);
  
 
    input [31:0] a;
    output [31:0] out;
    wire [31:0] not_a;
    wire [31:0] one;
    wire carry;
    not_32bit not1(a,not_a);
    zero_extend  zero1(1'b1,one);
    thirty_two_bit_adder add1(not_a,one,1'b0,out,carry);



endmodule






















  
