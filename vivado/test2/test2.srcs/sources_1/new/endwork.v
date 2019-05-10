`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/10 15:09:30
// Design Name: 
// Module Name: endwork
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


module endwork(
    input [3:0] a,
    input [3:0] b,
    input [0:0] o,
    input [0:0] fpre,
    output [6:0] ans,
    output [7:0] se,
    output [3:0] pre,
    output npre,
    input clk
    );
    wire [3:0] ta,tb,te;
    bigWork t1(a,b,o,fpre,te,pre,npre);
    assign ta=a;
    assign tb=b;
    show t2(ta,tb,te,ans,se,clk);
endmodule
