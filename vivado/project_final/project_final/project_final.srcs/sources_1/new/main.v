`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/06/04 14:04:00
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
    initial
    begin
        n_num=1;
        led=0;
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
        if((tfloor&5'b00001)&&n_num!=1)
            led<=led|5'b00001;
        if((tfloor&5'b00010)&&n_num!=2)
            led<=led|5'b00010;
        if((tfloor&5'b00100)&&n_num!=3)
            led<=led|5'b00100;
        if((tfloor&5'b01000)&&n_num!=4)
            led<=led|5'b01000;
        if((tfloor&5'b10000)&&n_num!=5)
            led<=led|5'b10000;
        case(n_num)
        1:led<=led&5'b11110;
        2:led<=led&5'b11101;
        3:led<=led&5'b11011;
        4:led<=led&5'b10111;
        5:led<=led&5'b01111;
        endcase
    end

    //电梯运行
    reg [4:0] tn_num;
    always@(tclk)
    begin
        tn_num=led&(5'b11111<<n_num);
        if(tn_num>0)
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
    wire [6:0] tlednum;
    hexseg t1(.hex(n_num),.segs(tlednum));
    always@(tlednum)
    begin
        lednum<=tlednum; 
    end



endmodule
