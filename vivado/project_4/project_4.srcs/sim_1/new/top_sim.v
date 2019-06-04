`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/30 16:38:25
// Design Name: 
// Module Name: top_sim
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


module top_sim();
    reg set;
    reg clk;
    reg rst;
    reg [7:0]d;   //????????
    wire  z;
    top u1(.clk(clk),.set(set),.rst(rst),.d(d),.z(z));
    initial
        begin
        d=8'b11011101;set = 1'b1; clk = 1'b1; rst =0;
        #10 set = 1'b1;
        #10 set = 1'b0;
        end
    always
        begin
            #25 clk = ~clk;
        end
endmodule
