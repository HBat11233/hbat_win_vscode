`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/10 14:35:50
// Design Name: 
// Module Name: fourToSeven
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


module fourToSeven(
    input [3:0] in,
    output [6:0] ou
    );
    //6 a, 5b....
    reg [6:0] ou;
    always @(in)
    begin
    case (in)
        0: ou=1;
        1: ou=7'b1001111;
        2: ou=7'b0010010;
        3: ou=7'b0000110;
        4: ou=7'b1001100;
        5: ou=7'b0100100;
        6: ou=7'b0100000;
        7: ou=7'b0001111;
        8: ou=7'b0000000;
        9: ou=7'b0001100;
        10: ou=7'b0001000;
        11: ou=7'b1100000;
        12: ou=7'b1110010;
        13: ou=7'b1000010;
        14: ou=7'b0110000;
        15: ou=7'b0111000;
    endcase
    end
endmodule
