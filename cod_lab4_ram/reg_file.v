`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:21:10 03/28/2017 
// Design Name: 
// Module Name:    reg_file 
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
module reg_file(
input clk,
input rst_n,
input [4:0] r1_addr,
input [4:0] r2_addr,
input [4:0] r3_addr,
input [31:0] r3_din,
input r3_wr,
output reg [31:0] r1_dout,
output reg [31:0] r2_dout
    );

reg [31:0] r[0:31];
integer i;


always@(posedge clk,negedge rst_n)
begin
    if(~rst_n)
	 begin
		for(i=0;i<=31;i=i+1)
			r[i] <= 0;
	 end
	 else
	 begin
	 if(r3_wr)
	 r[r3_addr] <= r3_din;
	 r1_dout <= r[r1_addr];
	 r2_dout <= r[r2_addr];
	 end
	 
end

endmodule
