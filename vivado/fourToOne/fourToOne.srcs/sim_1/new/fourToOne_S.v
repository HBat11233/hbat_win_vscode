`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/25 15:18:23
// Design Name: 
// Module Name: fourToOne_S
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


module fourToOne_S(

    );
    reg a=0;
    reg b=0;
    reg c=0;
    reg d=0;
    reg x=0;
    reg y=0;
    wire o;
    fourToOne ans(a,b,c,d,x,y,o);
    initial
        begin
            #100 a=1;
            #100 a=0;
            #100 x=1;
            #100 b=1;
            #100 b=0;
            #100 x=0;
            #000 y=1;
            #100 c=1;
            #100 c=0;
            #100 x=1;
            #100 d=1;
            #100 d=0;
        end
endmodule
