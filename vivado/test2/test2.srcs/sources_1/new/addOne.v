`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/08 14:38:12
// Design Name: 
// Module Name: addOne
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


module addOne(
    input a,
    input b,
    output sum,
    output presum,
    input prec
    );
    wire t1,t2;
    assign t1=a^b;
    assign t2=a&b;
    assign presum=t1&prec|t2;
    assign sum=t1^prec;
endmodule
