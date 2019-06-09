`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/06/09 15:19:45
// Design Name: 
// Module Name: code_lock_sim
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


module code_lock_sim();
reg clk;
reg[1:0] op_state; //操作状态
reg[7:0] key_in;      //开关设置密码
reg[3:0] btn;
wire pass;
wire fail;
wire enter;
wire cnt;
code_lock u(.clk(clk),.op_state(op_state),.key_in(key_in),.btn(btn),.pass(pass),.fail(fail),.enter(enter),.cnt(cnt));
initial begin
op_state=2'b01;
clk=1;
key_in<=8'b00000000;
btn<=4'b0000;
#25 op_state<=2'b11;
#25 key_in<=8'b00011011;
#25 btn[3]<=1;
#25 btn[2]<=1;
#25 btn[1]<=1;
#25 btn[0]<=1;
end
always #1 clk=~clk;

endmodule

