`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/06/03 01:06:48
// Design Name: 
// Module Name: hexseg
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


module hexseg(
    input [2:0] hex,
    output reg [6:0] segs
    );
    always@(hex)
    case(hex)
    1: segs = 7'b100_1111;
    2: segs = 7'b001_0010;
    3: segs = 7'b000_0110;
    4: segs = 7'b100_1100;
    5: segs = 7'b010_0100;
    default:
    segs = 7'b111_1111;
    endcase
endmodule
