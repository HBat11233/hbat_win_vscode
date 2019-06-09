module code_lock(
input clk,
input[1:0] op_state,  //����״̬
input[7:0] key_in,      //������������
input[3:0] btn,         //��ť��������
output reg pass,
output reg fail,
output reg enter, // ����������һλ����
output reg[2:0] cnt   //��������ĸ���
    );

reg[7:0] code;    // ������
reg[2:0] state;
reg[1:0] x1,x2,x3,x4;
reg[31:0] time_count; // ��ʱ��

parameter N = 32'b00001101111101011110000100000000;   // ��Ƶ��
//parameter N = 4'b0011;
parameter s0=3'b000;    //û�н��յ���Чλ�����������
parameter s1=3'b001;    //���յ�һ����Чλ
parameter s2=3'b010;    //���յ�������Чλ
parameter s3=3'b011;    //���յ�������Чλ
parameter s4=3'b100;    //���յ��ĸ���Чλ

always@(posedge clk) 
begin
    case (op_state)
    2'b01:
    begin //��������״̬
        code <= key_in; 
        pass<=0; 
        fail<=0;
        state<=s0; 
        cnt<=0; 
        enter <= 0; 
        time_count <= 0;
        end
    2'b11:
    begin //���������꣬���������벢���
        if(time_count >= N) 
        begin
            x1 <= {code[7],code[6]};   //��һλ����
            x2 <= {code[5],code[4]};   //�ڶ�λ����
            x3 <= {code[3],code[2]};   //����λ����
            x4 <= {code[1],code[0]};   //����λ����
            
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
            else if(btn>0)    //��Ȼ������󣬵����а�������
                cnt <= cnt+1;

            if(cnt == 4)   //��ֻ����������4������֮�����
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
