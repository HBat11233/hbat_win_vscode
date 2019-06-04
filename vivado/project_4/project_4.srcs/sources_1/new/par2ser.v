`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/30 16:09:02
// Design Name: 
// Module Name: par2ser
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


module par2ser(clk, set, d, q );
input clk;
input set;
input [7:0] d;
output reg q;
reg [7:0] data_buff;

always @(posedge clk or posedge set) begin
    if(set) begin
        q<=1'b0;
        data_buff<=d;
    end
    else begin
        data_buff<=data_buff<<1;
        q<=data_buff[7];
    end
end
endmodule
