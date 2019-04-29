`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/25 14:27:13
// Design Name: 
// Module Name: fourToOne
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


module fourToOne(
    input a[2:0],
    input b[2:0],
    input c[2:0],
    input d[2:0],
    input x,
    input y,
    output o[2:0]
    );
    assign o[0]=(~x&~y&a[0])|(x&~y&b[0])|(~x&y&c[0])|(x&y&d[0]);
    assign o[1]=(~x&~y&a[1])|(x&~y&b[1])|(~x&y&c[1])|(x&y&d[1]);
    assign o[2]=(~x&~y&a[2])|(x&~y&b[2])|(~x&y&c[2])|(x&y&d[2]);
    
endmodule
