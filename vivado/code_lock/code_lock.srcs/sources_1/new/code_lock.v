module code_lock(
input clk,
input[1:0] op_state,  //操作状态
input[7:0] key_in,      //开关设置密码
input[3:0] btn,         //按钮输入密码
output reg pass,
output reg fail,
output reg enter, // 提醒输入下一位密码
output reg[2:0] cnt   //输入密码的个数
    );

reg[7:0] code;    // 存密码
reg[2:0] state;
reg[1:0] x1,x2,x3,x4;
reg[31:0] time_count; // 计时器

parameter N = 32'b00001101111101011110000100000000;   // 分频、
//parameter N = 4'b0011;
parameter s0=3'b000;    //没有接收到有效位或者密码错误
parameter s1=3'b001;    //接收到一个有效位
parameter s2=3'b010;    //接收到两个有效位
parameter s3=3'b011;    //接收到三个有效位
parameter s4=3'b100;    //接收到四个有效位

always@(posedge clk) 
begin
    case (op_state)
    2'b01:
    begin //输入密码状态
        code <= key_in; 
        pass<=0; 
        fail<=0;
        state<=s0; 
        cnt<=0; 
        enter <= 0; 
        time_count <= 0;
        end
    2'b11:
    begin //密码设置完，需输入密码并检查
        if(time_count >= N) 
        begin
            x1 <= {code[7],code[6]};   //第一位密码
            x2 <= {code[5],code[4]};   //第二位密码
            x3 <= {code[3],code[2]};   //第三位密码
            x4 <= {code[1],code[0]};   //第四位密码
            
            if(btn[x1]==1 && state==s0)
            begin
                state <= s1;
                cnt <= cnt+1;
            end
            else if(btn[x2]==1 && state==s1)
            begin
                state <= s2;
                cnt <= cnt+1;
            end
            else if(btn[x3]==1 && state==s2)
            begin
                state <= s3;
                cnt <= cnt+1;
            end
            else if(btn[x4]==1 && state==s3)
            begin
                state <= s4;
                cnt <= cnt+1;
            end
            else if(btn>0)    //虽然密码错误，但是有按键按下
                cnt <= cnt+1;

            if(cnt == 4)   //灯只有在输入了4个密码之后才亮
            begin
                if(state == s4) begin pass <= 1; fail <= 0;  end
                else begin   pass <= 0; fail <= 1; end
            end
            
            enter <= enter + 1;
            time_count <= 0;
        end
        else 
            time_count <= time_count + 1;
    end
        
    default: 
    begin
        pass<=0; 
        state<=s0; 
        cnt<=0; 
        fail<=0; 
        enter <= 0; 
        time_count <= 0;
    end
    endcase
end
endmodule
