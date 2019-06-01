`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/30 17:06:59
// Design Name: 
// Module Name: smoore
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


module smoore();
    reg clock,resetn,ww;
    wire z;
    moore m(.clock(clock),.resetn(resetn),.w(ww),.z(z));
    
    initial begin
    clock=1;
    resetn=1;
    ww=1;
    end
    
    always
        begin
            #25
            clock=~clock;
            ww={$random}%2;
        end
    
endmodule
