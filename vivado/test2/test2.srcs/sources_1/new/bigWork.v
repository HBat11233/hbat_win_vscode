`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/10 11:41:24
// Design Name: 
// Module Name: bigWork
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


module bigWork(
    input [3:0] a,
    input [3:0] b,
    input [0:0] o,
    input [0:0] fpre,
    output [3:0] ans,
    output [3:0] pre,
    output npre
    );
    wire[3:0] ta,tb1,tb2,an,pr;
    buMa t1(a,ta);
    assign tb1[3]=(~o&b[3])|(o&~b[3]);
    assign tb1[2]=b[2];
    assign tb1[1]=b[1];
    assign tb1[0]=b[0];
    buMa t2(tb1,tb2);
    addFour t3(ta,tb2,an,pr,fpre);
    buMa t4(an,ans);
    assign pre=pr;
    assign npre=pr[2]|pr[3];
   
endmodule
