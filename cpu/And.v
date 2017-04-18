`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:06:44 04/17/2017 
// Design Name: 
// Module Name:    And 
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
module And(
input a,
input [1:0] b,
output reg c
    );
always@(*)
begin
	if(a == 1 & (b == 2'b10 | b == 2'b11)) //branch==1 并且 （bgtz条件满足 或者 遇到j指令）
		c = 1;
	else c = 0;
end

endmodule
