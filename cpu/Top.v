`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:00:39 04/16/2017 
// Design Name: 
// Module Name:    Top 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Top(
input clk,
input rst_n,
output [5:0] pc_in1,
output [5:0] pc_out,
output [31:0] inst,
output [4:0] reg_addr3,
output [31:0] reg_din,
output [31:0] srcb,
output [31:0] aluresult,
output [1:0] zero,
output MemtoReg,
output MemWrite,
output Branch,
output ALUSrc,
output RegDst,
output RegWrite
//output [31:0] readdata
    );
	 
//wire [5:0] pc_in;
//wire [5:0] pc_out;
//wire [31:0] inst;   //从指令ram中读出的指令
////wire MemtoReg;
////wire MemWrite;
////wire Branch;
wire [2:0] ALUControl;
////wire ALUSrc;
////wire RegDst;
////wire RegWrite;
wire [31:0] r1_dout;
wire [31:0] r2_dout;
//wire [4:0] reg_addr3;
//wire [31:0] reg_din;
//wire [31:0] srcb;
//wire [31:0] aluresult;
wire [31:0] readdata;
wire [5:0] pc_in2;
wire [5:0] pc_in;
wire [31:0] signlmm;

Pc u_pc(clk,rst_n,pc_in,pc_out);  

Pcplus u_pcplus(pc_out,pc_in1);

instruction_ram u_instruction_ram(pc_out,inst);

control u_control(inst[31:26],MemtoReg,MemWrite,Branch,ALUControl,ALUSrc,RegDst,RegWrite);

reg_file u_reg_file(clk,rst_n,inst[25:21],inst[20:16],reg_addr3,reg_din,RegWrite,r1_dout,r2_dout);

Alu u_alu(r1_dout,srcb,ALUControl,aluresult,zero); //计算地址或者结果

And u_and(Branch,zero,PCSrc);

extend u_extend(zero,inst[15:0],signlmm);

PCBranch u_pcbranch(signlmm[5:0],pc_in1,zero,pc_in2);

data_ram u_data_ram(aluresult[5:0],r2_dout,clk,MemWrite,readdata);

Mux u_mux1({27'b0,inst[15:11]},{27'b0,inst[20:16]},RegDst,reg_addr3[4:0]);

Mux u_mux2(signlmm,r2_dout,ALUSrc,srcb);

Mux u_mux3(readdata,aluresult,MemtoReg,reg_din);

Mux u_mux4({26'b0,pc_in2},{26'b0,pc_in1},PCSrc,pc_in[5:0]);

























endmodule
