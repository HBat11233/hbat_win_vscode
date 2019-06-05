`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/06/02 23:25:12
// Design Name: 
// Module Name: key_vibration
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module key_vibration(
    input mclk,
	input rst_n,
	input[4:0] key,
	output reg [4:0] key_en
    );
    parameter DURATION = 5;                           //��ʱ10ms	
	reg [10:0] cnt; 
	
	initial
	begin
	key_en=0; 
	cnt=0;
	end
	
	wire ken_enable;
	assign ken_enable = key[4] | key[3] | key[2] | key[1] | key[0]; //ֻҪ���ⰴ�������£���Ӧ�İ�����������
	
	always @(posedge mclk or negedge rst_n)
	begin
		if(!rst_n)
			cnt <= 11'd0;
		else if(ken_enable == 1) begin
			if(cnt == DURATION)
				cnt <= cnt;
			else 
				cnt <= cnt + 1'b1;
			end
		else
			cnt <= 11'b0;
	end
	
	always @(posedge mclk or negedge rst_n) 
	begin
		if(!rst_n) key_en <= 5'd0;
		else if(cnt==DURATION) key_en<=key;
		else key_en<=key_en;
	end
endmodule
