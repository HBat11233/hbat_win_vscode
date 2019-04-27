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
    input a,
    input b,
    input c,
    input d,
    input x,
    input y,
    output o
    );
    assign o=(~x&~y&a)|(x&~y&b)|(~x&y&c)|(x&y&d);
endmodule
