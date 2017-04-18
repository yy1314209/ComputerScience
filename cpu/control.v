`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:47:37 04/16/2017 
// Design Name: 
// Module Name:    control 
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
module control(
input [5:0] op,
output reg MemtoReg,
output reg MemWrite,
output reg Branch,
output reg [2:0] ALUControl,
output reg ALUSrc,
output reg RegDst,
output reg RegWrite
    );

always@(*)
begin
	case(op)
	6'b000000:	//add 指令
	begin
		MemtoReg = 0;
		MemWrite = 0;
		Branch = 0;
		ALUControl = 3'b111;
		ALUSrc = 0;
		RegDst = 1;
		RegWrite = 1;
	end
	6'b001000:   //addi 指令
	begin
		MemtoReg = 0;
		MemWrite = 0;
		Branch = 0;
		ALUControl = 3'b111;
		ALUSrc = 1;
		RegDst = 0;
		RegWrite = 1;
	end
	6'b100011:   //lw 指令
	begin
		MemtoReg = 1;
		MemWrite = 0;
		Branch = 0;
		ALUControl = 3'b111;
		ALUSrc = 1;
		RegDst = 0;
		RegWrite = 1;
	end
	6'b101011:   //sw 指令
	begin
		MemtoReg = 0;
		MemWrite = 1;
		Branch = 0;
		ALUControl = 3'b111;
		ALUSrc = 1;
		RegDst = 0;
		RegWrite = 0;
	end
	6'b000111:    //bgtz 指令
	begin
		MemtoReg = 0;
		MemWrite = 0;
		Branch = 1;
		ALUControl = 3'b110;
		ALUSrc = 0;
		RegDst = 1;
		RegWrite = 0;
	end
	6'b000010:   //j 指令
	begin
		MemtoReg = 0;
		MemWrite = 0;
		Branch = 1;
		ALUControl = 3'b101;
		ALUSrc = 0;
		RegDst = 1;
		RegWrite = 0;
	end
	default:
	begin	
		MemtoReg = 1;
		MemWrite = 0;
		Branch = 0;
		ALUControl = 3'b111;
		ALUSrc = 0;
		RegDst = 1;
		RegWrite = 0;
	end
	endcase
end
	
















endmodule
