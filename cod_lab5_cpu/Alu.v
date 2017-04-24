`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:40:26 04/16/2017 
// Design Name: 
// Module Name:    Alu 
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
module Alu(
input [31:0] srca,
input [31:0] srcb,
input [2:0] aluop,
output reg [31:0] aluresult,
output reg [1:0] zero
    );

always@(*)
begin
	case(aluop)
	3'b111:  //加
	begin
		aluresult = srca + srcb;
		zero = 2'b00;
	end
	3'b110:  //bgtz 有条件跳转
	if(srca > srcb)
	begin
		zero = 2'b10;
	end
	else	zero = 2'b00;
	3'b101:  //j 无条件跳转
	begin
		zero = 2'b11;
	end
	default:
	begin
		aluresult = 0;
		zero = 2'b00;
	end
	endcase
end











endmodule
