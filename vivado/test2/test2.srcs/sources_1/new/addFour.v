`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/08 15:05:29
// Design Name: 
// Module Name: addFour
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


module addFour(
    input [3:0] a,
    input [3:0] b,
    output [3:0] c,
    output [3:0] pd,
    input pre
    );
    wire t1,t2,t3,t4;
    addOne a1(a[0],b[0],c[0],t1,pre),
           a2(a[1],b[1],c[1],t2,t1),
           a3(a[2],b[2],c[2],t3,t2),
           a4(a[3],b[3],c[3],t4,t3);
    assign pd[0]=t1;
    assign pd[1]=t2;
    assign pd[2]=t3;
    assign pd[3]=t4;
endmodule
