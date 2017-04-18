`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:19:07 04/15/2017 
// Design Name: 
// Module Name:    Pcplus 
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
module Pcplus(
input [5:0] pc_now,
output [5:0] pcplus4
    );

assign pcplus4 = pc_now + 1;

endmodule
