`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/06/04 15:05:30
// Design Name: 
// Module Name: sim_main
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


module sim_main(

    );
    
    
    reg clk;
    reg rst;
    reg [4:0] floor;
    wire[4:0] led;
    wire[7:0] se;
    wire[6:0] lednum;
    main m(.clk(clk),.rst(rst),.floor(floor),.led(led),.se(se),.lednum(lednum));
    //key_vibration k(.mclk(clk),.rst_n(rst),.key(floor),.key_en(led));
    initial
    begin
    clk=0;
    rst=1;
    floor=0;
    
    floor=5'b01000;
    #60
    floor=0;
    #100
    floor=5'b10000;
    #60
    floor=0;
    
    end
    
    always
    begin
    #1
    clk=~clk;
    end
    
endmodule
