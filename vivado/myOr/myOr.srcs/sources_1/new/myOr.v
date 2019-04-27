`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/25 16:16:00
// Design Name: 
// Module Name: myOr
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


module myOr(
    input [2:0] a,
    input [2:0] b,
    input [2:0] c,
    input [2:0] d,
    output [2:0] o
    );
    assign o = a|b|c|d;
endmodule
