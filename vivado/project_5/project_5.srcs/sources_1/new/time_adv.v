`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/06/05 00:24:36
// Design Name: 
// Module Name: time_adv
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


module time_adv#(
parameter N = 100,
	       WIDTH = 7
)
(
    input clk,
    input rst,
    output reg clk_out
    );
    reg [WIDTH:0]counter;
    
    initial
    begin
        counter=0;
        clk_out=0;
    end
    
always @(posedge clk or posedge rst) 
begin
	if (rst) 
	begin// reset
		counter <= 0;
	end
	else if (counter == N-1) 
	begin
		counter <= 0;
	end
	else 
	begin
		counter <= counter + 1;
	end
end

always @(posedge clk or posedge rst) 
begin
	if (rst) 
	begin// reset
		clk_out <= 0; 
	end
	else if (counter == N-1) 
	begin
		clk_out <= !clk_out;;
	end
end    
endmodule
