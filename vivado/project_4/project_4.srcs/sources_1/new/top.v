`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/30 16:10:56
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

module top(clk,set,rst,d,z);
    input set;
    input rst;
    input clk;
    input [7:0]d;   //并行输入
    output z;
    wire q;    //串行输出  接入FSM
    par2ser u(.clk(clk),.set(set),.d(d),.q(q));
    moorefsm fsm(.clk(clk),.rst(rst),.a(q),.z(z));
endmodule
