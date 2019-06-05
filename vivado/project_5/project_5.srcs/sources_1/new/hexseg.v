module hexseg(
    input clk,
    input [2:0] hex,
    output reg [6:0] segs
    );
    always@(clk)
    case(hex)
    1: segs = 7'b100_1111;
    2: segs = 7'b001_0010;
    3: segs = 7'b000_0110;
    4: segs = 7'b100_1100;
    5: segs = 7'b010_0100;
    default:
    segs = 7'b111_1111;
    endcase
endmodule