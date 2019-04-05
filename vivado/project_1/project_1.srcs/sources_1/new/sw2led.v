`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/04 15:19:33
// Design Name: 
// Module Name: sw2led
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


module sw2led(
    input sw,
    input sw2,
    output led,
    output led2,
    output led3,
    output led4
    );
    assign led = sw & sw2;
    assign led2 = sw | sw2;
    assign led3 = sw ^ sw2;
    assign led4 = !(sw ^ sw2);
endmodule
