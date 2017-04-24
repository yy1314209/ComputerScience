`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:11:11 04/17/2017 
// Design Name: 
// Module Name:    PCBranch 
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
module PCBranch(
input [5:0] signlmm,
input [5:0] pc_in,
input [1:0] zero,
output reg [5:0] pc_out
    );	 
always@(*)
begin
	if(zero == 2'b10)
		pc_out = pc_in + signlmm;
	else if(zero == 2'b11)
		pc_out = signlmm;
	else pc_out = 0;
end

endmodule
