`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:39:44 04/15/2017 
// Design Name: 
// Module Name:    Pc 
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
module Pc(
input clk,
input rst_n,
input [5:0] pc_in,
output reg [5:0] pc_out
    );

always@(posedge clk,negedge rst_n)
begin
	if(~rst_n)
		pc_out <= 0;
	else
		pc_out <= pc_in;
end


endmodule
