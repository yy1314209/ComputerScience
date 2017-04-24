`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:00:03 04/17/2017
// Design Name:   Top
// Module Name:   E:/projects/ISE/cpu/test.v
// Project Name:  cpu
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Top
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
	wire [5:0] pc_in1;
	wire [5:0] pc_out;
	wire [31:0] inst;
	wire [4:0] reg_addr3;
	wire [31:0] reg_din;
	wire [31:0] srcb;
	wire [31:0] aluresult;
	wire [1:0] zero;
	wire MemtoReg;
	wire MemWrite;
	wire Branch;
	wire ALUSrc;
	wire RegDst;
	wire RegWrite;

	// Instantiate the Unit Under Test (UUT)
	Top uut (
		.clk(clk), 
		.rst_n(rst_n), 
		.pc_in1(pc_in1), 
		.pc_out(pc_out), 
		.inst(inst), 
		.reg_addr3(reg_addr3), 
		.reg_din(reg_din), 
		.srcb(srcb), 
		.aluresult(aluresult), 
		.zero(zero), 
		.MemtoReg(MemtoReg), 
		.MemWrite(MemWrite), 
		.Branch(Branch), 
		.ALUSrc(ALUSrc), 
		.RegDst(RegDst), 
		.RegWrite(RegWrite)
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

