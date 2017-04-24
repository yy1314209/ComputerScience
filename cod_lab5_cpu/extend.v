`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:05:53 04/17/2017 
// Design Name: 
// Module Name:    extend 
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
module extend(
input [1:0] zero,
input [15:0] a,
output reg [31:0] b
    );

always@(*)
begin
	if(a[15:11]==5'b0)  //如果为正数或者0 高为补0
	begin
		if(zero == 2'b11)
			b = {16'b0,a};
		else
			b = {16'b0,a}>>2;
	end
	else           //负数补1
		b = {16'hffff,a};
end
endmodule
