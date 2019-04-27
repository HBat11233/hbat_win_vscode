`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/25 16:17:01
// Design Name: 
// Module Name: myOr_S
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


module myOr_S(

    );
    reg [2:0]a=4;
    reg [2:0]b=2;
    reg [2:0]c=1;
    reg [2:0]d=0;
    wire [2:0]r;
    myOr myor(a,b,c,d,r);
    initial
        begin
            #100 b=0;
            #100 d=2;
        end
endmodule
