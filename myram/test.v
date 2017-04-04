`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:31:16 03/28/2017
// Design Name:   top
// Module Name:   E:/projects/ISE/myram/test.v
// Project Name:  myram
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test;

	// Inputs
	reg clk;
	reg rst_n;

	// Outputs
	wire [31:0] din;
	wire [4:0] addr1;
	wire [4:0] addr2;
	wire [4:0] addr3;
	wire we1;
	wire we2;
	wire [31:0] dout1;
	wire [31:0] dout2;
	wire [5:0] ram_addra;
	wire [5:0] ram_addrb;
	wire [31:0] dout;

	// Instantiate the Unit Under Test (UUT)
	top uut (
		.clk(clk), 
		.rst_n(rst_n), 
		.din(din), 
		.addr1(addr1), 
		.addr2(addr2), 
		.addr3(addr3), 
		.we1(we1), 
		.we2(we2), 
		.dout1(dout1), 
		.dout2(dout2), 
		.ram_addra(ram_addra), 
		.ram_addrb(ram_addrb), 
		.dout(dout)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		rst_n = 0;

		// Wait 100 ns for global reset to finish
		#100;
      rst_n = 1;
		// Add stimulus here

	end
	always #1
	clk = ~clk;
      
endmodule

