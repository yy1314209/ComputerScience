`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:20:25 03/28/2017 
// Design Name: 
// Module Name:    alu 
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
module alu(
input signed [31:0] a,
input signed [31:0] b,
input [4:0] op,
output reg [31:0] out
    );

always@(*)
begin
    case(op)
	 0:out=0;
	 1:out=a+b;
	 2:out=a-b;
	 3:out=a&b;
	 4:out=a|b;
	 5:out=a^b;
	 6:out=~(a|b);
	 default:out=0;
	 endcase
end

endmodule
