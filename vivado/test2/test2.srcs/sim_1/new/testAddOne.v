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
reg[3:0] a,b;
wire[3:0] ans,pre;
wire npre;
reg o,fpre;

bigWork t(a,b,o,fpre,ans,pre,npre);
//buMa t(a,ans);

initial begin
    repeat(16)
    begin
    #100
    a={$random}%16;
    b={$random}%16;
    o={$random}%2;
    fpre={$random}%2;
    end
end
    
endmodule
