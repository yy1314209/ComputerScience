`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:22:04 03/28/2017 
// Design Name: 
// Module Name:    control 
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
module control(
input clk,
input rst_n,
input [31:0] din1,   //����alu�����
input [31:0] din2,   //����ram�����
output reg [4:0] addr1,  //reg��
output reg [4:0] addr2,  //reg��
output reg [4:0] addr3,   //regд
output reg we1,    //reg��дʹ��
output reg we2,   //ram��дʹ��
output reg [5:0] ram_addra,  //ram��д��ַ
output reg [5:0] ram_addrb,  //ram�Ķ���ַ
output reg [31:0] dout    //Ҫд��reg������
    );

reg  [4:0] a1;
reg  [4:0] a2;
reg  [1:0] div;
reg  [2:0] count;   //���ڿ���ģ�����еĽ׶�

always@(posedge clk,negedge rst_n)
begin
    if(~rst_n)
	 begin
	   addr1 <= 0;
		addr2 <= 1;
		addr3 <= 2;
		a1 <= 0;
		a2 <= 1;
		we1 <= 0;
		we2 <= 0;
		div <= 0;
		ram_addra <= 0;
		ram_addrb <= 0;
		count <= 0;
	 end
	 else if(count <= 4)
	 begin
	 if(count == 0)
	 ram_addrb <= 0;
	 if(count == 1)
	 begin
	 we1 <= 1;
	 addr3 <= 0;
	 dout <= din2;
	 end
	 if(count == 2)
	 begin
	 we1 <= 0;
	 ram_addrb <= 1;
	 end
	 if(count == 3)
	 begin
	 we1 <= 1;
	 addr3 <= 1;
	 dout <= din2;
	 end
	 if(count == 4)
	 we1 <= 0;
	 count <= count + 1;
	 end
	 else
	 begin
	 if(div == 3)
	 div <= 0;
	 else div <= div + 1;
	 if(div == 0)
	 begin
	 we1 <= 0;
	 we2 <= 0;
	 end
	 else if(div == 3)
    begin
	 we1 <= 1;
	 we2 <= 1;
	 end
	 if((a1<29)&(div==3))
	 a1 <= a1 + 1;
	 else
	 a1 <= a1;
	 if((a2<30)&(div==3))
	 a2 <= a2 + 1;
	 else
	 a2 <= a2;
	 addr1 <= a1;
    addr2 <= a2;
	 addr3 <= a2 + 1;
	 ram_addra <= {0,a2+1};
	 ram_addrb <= {0,a1};
	 dout <= din1;
    end
end	 

endmodule