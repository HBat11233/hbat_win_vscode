`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/04 16:48:20
// Design Name: 
// Module Name: sim_sw2led
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


module sim_sw2led(

    );
    
    reg sw,sw1;
    wire leg,leg2,leg3,leg4;
    sw2led(
        .sw(sw),
        .sw1(sw1),
        .led(led),
        .led1(led1),
        .led2(led2),
        .led3(led3)
    );
    
endmodule
