`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/30 16:42:09
// Design Name: 
// Module Name: moore
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


module moore(clock,resetn,w,z);
    input clock,resetn,w;
    output z;
    reg s;
    parameter [2:0] A=3'b000, B=3'b001, C=3'b010, D=3'b011, E=3'b100;
    
    always@(clock)
    case(y)
        A:if(w)Y=B;
          else Y=A;
        B:if(w)Y=C;
          else Y=A;
        C:if(w)Y=C;
          else Y=D;
        D:if(w)Y=E;
          else Y=A;
        E:if(w)Y=C;
          else Y=A;
        default:Y=A;
    endcase
    
    always@(negedge resetn,posedge clock)
    begin
    if(resetn==0)y<=A;
    else y<=Y;
    end
    
   always@(resetn,y)
   s<=(y==E);
    
    assign z=s;
endmodule
