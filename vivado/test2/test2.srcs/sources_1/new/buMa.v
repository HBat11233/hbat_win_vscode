`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/08 16:17:20
// Design Name: 
// Module Name: buMa
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


module buMa(
    input [3:0] a,
    output [3:0] b
    );
    wire [3:0] t,p,s;
    assign p[3]=a[3];
    assign p[2]=~a[2];
    assign p[1]=~a[1];
    assign p[0]=~a[0];
    addFour tp(p,0,s,t,1);
    assign t[3]=a[3];
    assign t[2]=a[3];
    assign t[1]=a[3];
    assign t[0]=a[3];
    assign b=(~t&a)|(t&s);
endmodule