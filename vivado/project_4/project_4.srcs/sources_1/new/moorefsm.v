`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/28 19:25:18
// Design Name: 
// Module Name: moorefsm
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
module moorefsm(clk,rst,z,a);
input clk,rst,a;
    output z;
    reg s;
    parameter [2:0] A=3'b000, B=3'b001, C=3'b010, D=3'b011, E=3'b100;
    reg [2:0] y,Y;
    initial 
    begin
        y=0;
        Y=0;
    end
    
    always@(clk)
    case(y)
        A:if(a)Y=B;
          else Y=A;
        B:if(a)Y=C;
          else Y=A;
        C:if(a)Y=C;
          else Y=D;
        D:if(a)Y=E;
          else Y=A;
        E:if(a)Y=C;
          else Y=A;
        default:Y=A;
    endcase
    
    always@(negedge rst,posedge clk)
    begin
    if(rst)y<=A;
    else y<=Y;
    end
    
   always@(rst,y)
   s<=(y==E);
    
    assign z=s;
endmodule
