module key_vibration(
    input clk,
	input rst_n,
	input[3:0] key,
	output reg [3:0] key_en
    );
    parameter DURATION = 50_000;                           //延时10ms	
	reg [10:0] cnt; 
	
	wire ken_enable;
	assign ken_enable =  key[3] | key[2] | key[1] | key[0]; //只要任意按键被按下，相应的按键进行消抖
	
	always @(posedge clk or negedge rst_n)
	begin
		if(!rst_n)
			cnt <= 11'd0;
		else if(ken_enable == 1) begin
			if(cnt == DURATION)
				cnt <= cnt;
			else 
				cnt <= cnt + 1'b1;
			end
		else
			cnt <= 11'b0;
	end
	
	always @(posedge clk or negedge rst_n) 
	begin
		if(!rst_n) key_en <= 5'd0;
		else if(key[0]) key_en[0] <= (cnt == DURATION-1'b1) ? 1'b1 : 1'b0;
		else if(key[1]) key_en[1] <= (cnt == DURATION-1'b1) ? 1'b1 : 1'b0;
		else if(key[2]) key_en[2] <= (cnt == DURATION-1'b1) ? 1'b1 : 1'b0;
		else if(key[3]) key_en[3] <= (cnt == DURATION-1'b1) ? 1'b1 : 1'b0;
		else key_en <= key_en;
	end
endmodule
