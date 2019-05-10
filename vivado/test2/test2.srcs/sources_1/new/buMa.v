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
    assign b[3]=(a[3]&a[0])|(a[3]&a[2]&~a[1])|(a[3]&a[1]);
    assign b[2]=(a[2]&~a[1]&~a[0])|(~a[3]&a[2]&a[0])|(~a[3]&a[2]&a[1])|(a[3]&~a[2]&a[0])|(a[3]&~a[2]&a[1]);
    assign b[1]=(~a[3]&a[1])|(a[3]&~a[1]&a[0])|(a[3]&a[1]&~a[0]);
    assign b[0]=a[0];
endmodule