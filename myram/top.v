`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:20:45 03/28/2017 
// Design Name: 
// Module Name:    top 
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
module top(
input clk,
input rst_n,
output [31:0] din,
output [4:0] addr1,
output [4:0] addr2,
output [4:0] addr3,
output we1,
output we2,
output [31:0] dout1,
output [31:0] dout2,
output [5:0] ram_addra,
output [5:0] ram_addrb,
output [31:0] dout
    );
	 
wire [4:0] op;
assign op=1;
wire [31:0] doutb;

control u_control(
.clk(clk),
.rst_n(rst_n),
.din1(din),
.din2(doutb),
.addr1(addr1),
.addr2(addr2),
.addr3(addr3),
.we1(we1),
.we2(we2),
.ram_addra(ram_addra),
.ram_addrb(ram_addrb),
.dout(dout)
);

reg_file u_reg(
.clk(clk),
.rst_n(rst_n),
.r1_addr(addr1),
.r2_addr(addr2),
.r3_addr(addr3),
.r3_din(dout),
.r3_wr(we1),
.r1_dout(dout1),
.r2_dout(dout2)
);

ram u_ram(
.clka(clk),
.wea(we2),
.addra(ram_addra),
.dina(dout),
.clkb(clk),
.addrb(ram_addrb),
.doutb(doutb)
);


alu u_alu(
.a(dout1),
.b(dout2),
.op(op),
.out(din)
);


endmodule
