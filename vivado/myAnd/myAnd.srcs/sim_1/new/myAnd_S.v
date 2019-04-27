`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/25 15:51:58
// Design Name: 
// Module Name: myAnd_S
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


module myAnd_S(

    );
    reg s1=1;
    reg s2=1;
    reg [2:0]d=7;
    wire [2:0]od;
    myAnd myand(s1,s2,d,od);
    initial 
        begin
            #100 d[1]=0;
            #100 s1=0;
            #100 s1=1;
            #100 s2=0;
        end
    
endmodule
