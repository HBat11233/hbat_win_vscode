`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/08 14:46:24
// Design Name: 
// Module Name: testAddOne
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


module testAddOne( );
reg[3:0] a;
wire[3:0] c;

buMa t(a,c);

initial begin
    repeat(9)
    #100 begin
        a={$random}%16;
    end
end
endmodule
