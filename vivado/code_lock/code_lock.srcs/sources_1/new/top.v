`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/06/09 15:17:51
// Design Name: 
// Module Name: top
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


//顶层模块：
module top(clk,rst,key,key_in,op_state,pass,fail,enter,cnt);
    input rst;
    input clk;
    input [3:0]key;   //输入
    input[1:0] op_state; //操作状态
    input[7:0] key_in;     //开关设置密码
    //output reg [3:0] key_en;
    output wire pass;
    output wire fail;
    output wire enter; // 提醒输入下一位密码
    output wire[2:0] cnt;   //输入密码的个数
    wire [3:0] key_en;    
    key_vibration u(.clk(clk),.rst_n(rst),.key(key),.key_en(key_en));
    code_lock lock(.clk(clk),.op_state(op_state),.key_in(key_in),.btn(key_en),.pass(pass),.fail(fail),.enter(enter),.cnt(cnt));
endmodule

