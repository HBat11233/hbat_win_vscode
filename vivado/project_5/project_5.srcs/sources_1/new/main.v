`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/06/05 00:05:34
// Design Name: 
// Module Name: main
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


module main(
    input rst,
    input clk,
    input [4:0] floor,
    output reg [4:0] led,
    output reg [7:0] se,
    output reg [6:0] lednum
    );

    //初始化
    reg [2:0] n_num;
    reg [4:0] tled;
    initial
    begin
        n_num=1;
        led=0;
        tled=0;
        se=8'b01111111;
        lednum=1;
    end
    
    //时间每秒
    wire tclk;
    time_adv t2(.clk(clk),.rst(~rst),.clk_out(tclk));
    
    //消抖
    wire [4:0] tfloor;
    key_vibration t0(.mclk(clk),.rst_n(rst),.key(floor),.key_en(tfloor));

    //按下楼层呼叫，即电梯到达楼层处理
    always@(tfloor,n_num)
    begin
        if(tfloor[0] && n_num!=1)
            tled[0]=1;
        if(tfloor[1] && n_num!=2)
            tled[1]=1;
        if(tfloor[2] && n_num!=3)
            tled[2]=1;
        if(tfloor[3] && n_num!=4)
            tled[3]=1;
        if(tfloor[4] && n_num!=5)
            tled[5]=1;
        case(n_num)
        1:tled[0]=0;
        2:tled[1]=1;
        3:tled[2]=2;
        4:tled[3]=3;
        5:tled[4]=4;
        endcase 
    end
    
    
    always@(tled)
        led=tled;
    
    //电梯运行
    
    reg [4:0] tn_num;
    always@(tclk)
    begin
        if(tled>(5'b00001<<n_num-1))
            n_num<=n_num+1;
        else
        begin
            if(n_num==1)
                n_num<=n_num;
            else
                n_num<=n_num-1;
        end
    end
    

    //显示楼层
    //七段数码管转
    /*
    wire [6:0] tlednum;
    hexseg t1(.clk(clk),.hex(n_num),.segs(tlednum));
    always@(clk)
    begin
        lednum=tlednum;
    end
*/


endmodule
