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
    output[4:0] led,
    output reg [7:0] se,
    output [6:0] lednum
    );

    //��ʼ��
    reg [4:0] n_num;
    reg [4:0] mled;
    reg [6:0] mlednum;
    initial
    begin
        n_num=1;
        mled=0;
        se=8'b01111111;
        mlednum=1;
    end
    
    //ʱ��ÿ��
    wire tclk;
    time_adv t2(.clk(clk),.rst(~rst),.clk_out(tclk));

    //����
    wire [4:0] tfloor;
    key_vibration t0(.mclk(clk),.rst_n(rst),.key(floor),.key_en(tfloor));

    //����¥����У������ݵ���¥�㴦��
    
    always@(tfloor,n_num)
    begin
        mled=mled|tfloor;
        case(n_num)
        1:mled[0]=0;
        2:mled[1]=0;
        4:mled[2]=0;
        8:mled[3]=0;
        16:mled[4]=0;
        endcase
    end
    
    
    //��������
    always@(tclk)
    begin
        if(mled>n_num)
            n_num<=n_num<<1;
        else
        begin
            if(n_num==1)
                n_num<=n_num;
            else
                n_num<=n_num>>1;
        end
    end

    //��ʾ¥��
    //�߶������ת
    wire [6:0] tlednum;
    hexseg t1(.hex(n_num),.segs(tlednum));

    always@(tlednum)
        mlednum=tlednum;
    
    assign lednum=mlednum;
    assign led=mled;



endmodule
