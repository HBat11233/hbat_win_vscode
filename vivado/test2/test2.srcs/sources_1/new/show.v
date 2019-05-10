`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/10 15:58:53
// Design Name: 
// Module Name: show
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


module show(
    input [3:0] a,
    input [3:0] b,
    input [3:0] c,
    output [6:0] ans,
    output [7:0] se,
    input clk
    );
    reg [19:0] cnt=0;
    reg [7:0] se;
    reg [6:0] ans;
    always @(posedge clk)
    begin
        if(cnt==20'b11111111111111111111)
            cnt=0;
        else
            cnt=cnt+1;
    end
    always @(posedge clk)
    begin
        case(cnt[19:17])
            3'b000:
                begin
                    se=8'b01111111;
                    case (a)
                        0: ans=1;
                        1: ans=7'b1001111;
                        2: ans=7'b0010010;
                        3: ans=7'b0000110;
                        4: ans=7'b1001100;
                        5: ans=7'b0100100;
                        6: ans=7'b0100000;
                        7: ans=7'b0001111;
                        8: ans=7'b0000000;
                        9: ans=7'b0001100;
                        10: ans=7'b0001000;
                        11: ans=7'b1100000;
                        12: ans=7'b1110010;
                        13: ans=7'b1000010;
                        14: ans=7'b0110000;
                        15: ans=7'b0111000;
                    endcase
                end
            3'b001:
            begin
                se=8'b10111111;
                ans=~0;
                end
            3'b010:
                begin
                    se=8'b11011111;
                    case (b)
                        0: ans=1;
                        1: ans=7'b1001111;
                        2: ans=7'b0010010;
                        3: ans=7'b0000110;
                        4: ans=7'b1001100;
                        5: ans=7'b0100100;
                        6: ans=7'b0100000;
                        7: ans=7'b0001111;
                        8: ans=7'b0000000;
                        9: ans=7'b0001100;
                        10: ans=7'b0001000;
                        11: ans=7'b1100000;
                        12: ans=7'b1110010;
                        13: ans=7'b1000010;
                        14: ans=7'b0110000;
                        15: ans=7'b0111000;
                    endcase
                end
            3'b011:
            begin
            se=8'b11101111;
            ans=~0;
                end
            3'b100:
            begin
            se=8'b11110111;
            ans=~0;
                end
            3'b101:
            begin
            se=8'b11111011;
            ans=~0;
                end
            3'b110:
            begin
            se=8'b11111101;
            ans=~0;
                end
            3'b111:
            begin
                se=8'b11111110;
                case (c)
                        0: ans=1;
                        1: ans=7'b1001111;
                        2: ans=7'b0010010;
                        3: ans=7'b0000110;
                        4: ans=7'b1001100;
                        5: ans=7'b0100100;
                        6: ans=7'b0100000;
                        7: ans=7'b0001111;
                        8: ans=7'b0000000;
                        9: ans=7'b0001100;
                        10: ans=7'b0001000;
                        11: ans=7'b1100000;
                        12: ans=7'b1110010;
                        13: ans=7'b1000010;
                        14: ans=7'b0110000;
                        15: ans=7'b0111000;
                    endcase
            end
        endcase
    end
endmodule
