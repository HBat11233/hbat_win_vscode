`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/25 15:46:41
// Design Name: 
// Module Name: myAnd
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


module myAnd(
    input s1,
    input s2,
    input [2:0] d,
    output [2:0] od
    );
    assign od[0]=s1&s2&d[0];
    assign od[1]=s1&s2&d[1];
    assign od[2]=s1&s2&d[2];
endmodule
