// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
// Date        : Sun Jun  2 00:54:12 2019
// Host        : DESKTOP-91J4R11 running 64-bit major release  (build 9200)
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               C:/Users/HBat/Desktop/20174240»ÆÃôÐù_ÊµÑéËÄÄ¦¶û×´Ì¬»úÐòÁÐ¼ì²âÆ÷/project_4/project_4.sim/sim_1/synth/timing/xsim/top_sim_time_synth.v
// Design      : top
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

module moorefsm
   (z_OBUF,
    clk_IBUF_BUFG,
    rst_IBUF,
    q);
  output z_OBUF;
  input clk_IBUF_BUFG;
  input rst_IBUF;
  input q;

  wire \FSM_sequential_cur_sta[0]_i_1_n_0 ;
  wire \FSM_sequential_cur_sta[1]_i_1_n_0 ;
  wire \FSM_sequential_cur_sta[2]_i_1_n_0 ;
  wire clk_IBUF_BUFG;
  wire [2:0]cur_sta;
  wire q;
  wire rst_IBUF;
  wire z_OBUF;

  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT5 #(
    .INIT(32'h00000110)) 
    \FSM_sequential_cur_sta[0]_i_1 
       (.I0(rst_IBUF),
        .I1(cur_sta[2]),
        .I2(q),
        .I3(cur_sta[1]),
        .I4(cur_sta[0]),
        .O(\FSM_sequential_cur_sta[0]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT5 #(
    .INIT(32'h01011400)) 
    \FSM_sequential_cur_sta[1]_i_1 
       (.I0(rst_IBUF),
        .I1(cur_sta[0]),
        .I2(cur_sta[2]),
        .I3(q),
        .I4(cur_sta[1]),
        .O(\FSM_sequential_cur_sta[1]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT5 #(
    .INIT(32'h00400000)) 
    \FSM_sequential_cur_sta[2]_i_1 
       (.I0(cur_sta[2]),
        .I1(cur_sta[0]),
        .I2(q),
        .I3(rst_IBUF),
        .I4(cur_sta[1]),
        .O(\FSM_sequential_cur_sta[2]_i_1_n_0 ));
  (* FSM_ENCODED_STATES = "S1:001,S3:011,S4:100,S0:000,S2:010" *) 
  FDCE #(
    .INIT(1'b0)) 
    \FSM_sequential_cur_sta_reg[0] 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(rst_IBUF),
        .D(\FSM_sequential_cur_sta[0]_i_1_n_0 ),
        .Q(cur_sta[0]));
  (* FSM_ENCODED_STATES = "S1:001,S3:011,S4:100,S0:000,S2:010" *) 
  FDCE #(
    .INIT(1'b0)) 
    \FSM_sequential_cur_sta_reg[1] 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(rst_IBUF),
        .D(\FSM_sequential_cur_sta[1]_i_1_n_0 ),
        .Q(cur_sta[1]));
  (* FSM_ENCODED_STATES = "S1:001,S3:011,S4:100,S0:000,S2:010" *) 
  FDCE #(
    .INIT(1'b0)) 
    \FSM_sequential_cur_sta_reg[2] 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(rst_IBUF),
        .D(\FSM_sequential_cur_sta[2]_i_1_n_0 ),
        .Q(cur_sta[2]));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT4 #(
    .INIT(16'h0010)) 
    z_OBUF_inst_i_1
       (.I0(cur_sta[1]),
        .I1(cur_sta[0]),
        .I2(cur_sta[2]),
        .I3(rst_IBUF),
        .O(z_OBUF));
endmodule

module par2ser
   (q,
    clk_IBUF_BUFG,
    set_IBUF,
    d_IBUF);
  output q;
  input clk_IBUF_BUFG;
  input set_IBUF;
  input [7:0]d_IBUF;

  wire clk_IBUF_BUFG;
  wire [7:0]d_IBUF;
  wire \data_buff_reg[0]_LDC_i_1_n_0 ;
  wire \data_buff_reg[0]_LDC_i_2_n_0 ;
  wire \data_buff_reg[0]_LDC_n_0 ;
  wire \data_buff_reg[0]_P_n_0 ;
  wire \data_buff_reg[1]_C_n_0 ;
  wire \data_buff_reg[1]_LDC_i_1_n_0 ;
  wire \data_buff_reg[1]_LDC_i_2_n_0 ;
  wire \data_buff_reg[1]_LDC_n_0 ;
  wire \data_buff_reg[1]_P_n_0 ;
  wire \data_buff_reg[2]_C_n_0 ;
  wire \data_buff_reg[2]_LDC_i_1_n_0 ;
  wire \data_buff_reg[2]_LDC_i_2_n_0 ;
  wire \data_buff_reg[2]_LDC_n_0 ;
  wire \data_buff_reg[2]_P_n_0 ;
  wire \data_buff_reg[3]_C_n_0 ;
  wire \data_buff_reg[3]_LDC_i_1_n_0 ;
  wire \data_buff_reg[3]_LDC_i_2_n_0 ;
  wire \data_buff_reg[3]_LDC_n_0 ;
  wire \data_buff_reg[3]_P_n_0 ;
  wire \data_buff_reg[4]_C_n_0 ;
  wire \data_buff_reg[4]_LDC_i_1_n_0 ;
  wire \data_buff_reg[4]_LDC_i_2_n_0 ;
  wire \data_buff_reg[4]_LDC_n_0 ;
  wire \data_buff_reg[4]_P_n_0 ;
  wire \data_buff_reg[5]_C_n_0 ;
  wire \data_buff_reg[5]_LDC_i_1_n_0 ;
  wire \data_buff_reg[5]_LDC_i_2_n_0 ;
  wire \data_buff_reg[5]_LDC_n_0 ;
  wire \data_buff_reg[5]_P_n_0 ;
  wire \data_buff_reg[6]_C_n_0 ;
  wire \data_buff_reg[6]_LDC_i_1_n_0 ;
  wire \data_buff_reg[6]_LDC_i_2_n_0 ;
  wire \data_buff_reg[6]_LDC_n_0 ;
  wire \data_buff_reg[6]_P_n_0 ;
  wire \data_buff_reg[7]_C_n_0 ;
  wire \data_buff_reg[7]_LDC_i_1_n_0 ;
  wire \data_buff_reg[7]_LDC_i_2_n_0 ;
  wire \data_buff_reg[7]_LDC_n_0 ;
  wire \data_buff_reg[7]_P_n_0 ;
  wire p_0_in;
  wire [7:1]p_2_in;
  wire q;
  wire set_IBUF;

  LUT2 #(
    .INIT(4'h8)) 
    \data_buff[1]_C_i_1 
       (.I0(\data_buff_reg[0]_LDC_n_0 ),
        .I1(\data_buff_reg[0]_P_n_0 ),
        .O(p_2_in[1]));
  LUT3 #(
    .INIT(8'hB8)) 
    \data_buff[2]_C_i_1 
       (.I0(\data_buff_reg[1]_P_n_0 ),
        .I1(\data_buff_reg[1]_LDC_n_0 ),
        .I2(\data_buff_reg[1]_C_n_0 ),
        .O(p_2_in[2]));
  LUT3 #(
    .INIT(8'hB8)) 
    \data_buff[3]_C_i_1 
       (.I0(\data_buff_reg[2]_P_n_0 ),
        .I1(\data_buff_reg[2]_LDC_n_0 ),
        .I2(\data_buff_reg[2]_C_n_0 ),
        .O(p_2_in[3]));
  LUT3 #(
    .INIT(8'hB8)) 
    \data_buff[4]_C_i_1 
       (.I0(\data_buff_reg[3]_P_n_0 ),
        .I1(\data_buff_reg[3]_LDC_n_0 ),
        .I2(\data_buff_reg[3]_C_n_0 ),
        .O(p_2_in[4]));
  LUT3 #(
    .INIT(8'hB8)) 
    \data_buff[5]_C_i_1 
       (.I0(\data_buff_reg[4]_P_n_0 ),
        .I1(\data_buff_reg[4]_LDC_n_0 ),
        .I2(\data_buff_reg[4]_C_n_0 ),
        .O(p_2_in[5]));
  LUT3 #(
    .INIT(8'hB8)) 
    \data_buff[6]_C_i_1 
       (.I0(\data_buff_reg[5]_P_n_0 ),
        .I1(\data_buff_reg[5]_LDC_n_0 ),
        .I2(\data_buff_reg[5]_C_n_0 ),
        .O(p_2_in[6]));
  LUT3 #(
    .INIT(8'hB8)) 
    \data_buff[7]_C_i_1 
       (.I0(\data_buff_reg[6]_P_n_0 ),
        .I1(\data_buff_reg[6]_LDC_n_0 ),
        .I2(\data_buff_reg[6]_C_n_0 ),
        .O(p_2_in[7]));
  (* XILINX_LEGACY_PRIM = "LDC" *) 
  LDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[0]_LDC 
       (.CLR(\data_buff_reg[0]_LDC_i_2_n_0 ),
        .D(1'b1),
        .G(\data_buff_reg[0]_LDC_i_1_n_0 ),
        .GE(1'b1),
        .Q(\data_buff_reg[0]_LDC_n_0 ));
  LUT2 #(
    .INIT(4'h8)) 
    \data_buff_reg[0]_LDC_i_1 
       (.I0(d_IBUF[0]),
        .I1(set_IBUF),
        .O(\data_buff_reg[0]_LDC_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \data_buff_reg[0]_LDC_i_2 
       (.I0(set_IBUF),
        .I1(d_IBUF[0]),
        .O(\data_buff_reg[0]_LDC_i_2_n_0 ));
  FDPE #(
    .INIT(1'b1)) 
    \data_buff_reg[0]_P 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .D(1'b0),
        .PRE(\data_buff_reg[0]_LDC_i_1_n_0 ),
        .Q(\data_buff_reg[0]_P_n_0 ));
  FDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[1]_C 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(\data_buff_reg[1]_LDC_i_2_n_0 ),
        .D(p_2_in[1]),
        .Q(\data_buff_reg[1]_C_n_0 ));
  (* XILINX_LEGACY_PRIM = "LDC" *) 
  LDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[1]_LDC 
       (.CLR(\data_buff_reg[1]_LDC_i_2_n_0 ),
        .D(1'b1),
        .G(\data_buff_reg[1]_LDC_i_1_n_0 ),
        .GE(1'b1),
        .Q(\data_buff_reg[1]_LDC_n_0 ));
  LUT2 #(
    .INIT(4'h8)) 
    \data_buff_reg[1]_LDC_i_1 
       (.I0(d_IBUF[1]),
        .I1(set_IBUF),
        .O(\data_buff_reg[1]_LDC_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \data_buff_reg[1]_LDC_i_2 
       (.I0(set_IBUF),
        .I1(d_IBUF[1]),
        .O(\data_buff_reg[1]_LDC_i_2_n_0 ));
  FDPE #(
    .INIT(1'b1)) 
    \data_buff_reg[1]_P 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .D(p_2_in[1]),
        .PRE(\data_buff_reg[1]_LDC_i_1_n_0 ),
        .Q(\data_buff_reg[1]_P_n_0 ));
  FDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[2]_C 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(\data_buff_reg[2]_LDC_i_2_n_0 ),
        .D(p_2_in[2]),
        .Q(\data_buff_reg[2]_C_n_0 ));
  (* XILINX_LEGACY_PRIM = "LDC" *) 
  LDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[2]_LDC 
       (.CLR(\data_buff_reg[2]_LDC_i_2_n_0 ),
        .D(1'b1),
        .G(\data_buff_reg[2]_LDC_i_1_n_0 ),
        .GE(1'b1),
        .Q(\data_buff_reg[2]_LDC_n_0 ));
  LUT2 #(
    .INIT(4'h8)) 
    \data_buff_reg[2]_LDC_i_1 
       (.I0(d_IBUF[2]),
        .I1(set_IBUF),
        .O(\data_buff_reg[2]_LDC_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \data_buff_reg[2]_LDC_i_2 
       (.I0(set_IBUF),
        .I1(d_IBUF[2]),
        .O(\data_buff_reg[2]_LDC_i_2_n_0 ));
  FDPE #(
    .INIT(1'b1)) 
    \data_buff_reg[2]_P 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .D(p_2_in[2]),
        .PRE(\data_buff_reg[2]_LDC_i_1_n_0 ),
        .Q(\data_buff_reg[2]_P_n_0 ));
  FDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[3]_C 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(\data_buff_reg[3]_LDC_i_2_n_0 ),
        .D(p_2_in[3]),
        .Q(\data_buff_reg[3]_C_n_0 ));
  (* XILINX_LEGACY_PRIM = "LDC" *) 
  LDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[3]_LDC 
       (.CLR(\data_buff_reg[3]_LDC_i_2_n_0 ),
        .D(1'b1),
        .G(\data_buff_reg[3]_LDC_i_1_n_0 ),
        .GE(1'b1),
        .Q(\data_buff_reg[3]_LDC_n_0 ));
  LUT2 #(
    .INIT(4'h8)) 
    \data_buff_reg[3]_LDC_i_1 
       (.I0(d_IBUF[3]),
        .I1(set_IBUF),
        .O(\data_buff_reg[3]_LDC_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \data_buff_reg[3]_LDC_i_2 
       (.I0(set_IBUF),
        .I1(d_IBUF[3]),
        .O(\data_buff_reg[3]_LDC_i_2_n_0 ));
  FDPE #(
    .INIT(1'b1)) 
    \data_buff_reg[3]_P 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .D(p_2_in[3]),
        .PRE(\data_buff_reg[3]_LDC_i_1_n_0 ),
        .Q(\data_buff_reg[3]_P_n_0 ));
  FDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[4]_C 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(\data_buff_reg[4]_LDC_i_2_n_0 ),
        .D(p_2_in[4]),
        .Q(\data_buff_reg[4]_C_n_0 ));
  (* XILINX_LEGACY_PRIM = "LDC" *) 
  LDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[4]_LDC 
       (.CLR(\data_buff_reg[4]_LDC_i_2_n_0 ),
        .D(1'b1),
        .G(\data_buff_reg[4]_LDC_i_1_n_0 ),
        .GE(1'b1),
        .Q(\data_buff_reg[4]_LDC_n_0 ));
  LUT2 #(
    .INIT(4'h8)) 
    \data_buff_reg[4]_LDC_i_1 
       (.I0(d_IBUF[4]),
        .I1(set_IBUF),
        .O(\data_buff_reg[4]_LDC_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \data_buff_reg[4]_LDC_i_2 
       (.I0(set_IBUF),
        .I1(d_IBUF[4]),
        .O(\data_buff_reg[4]_LDC_i_2_n_0 ));
  FDPE #(
    .INIT(1'b1)) 
    \data_buff_reg[4]_P 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .D(p_2_in[4]),
        .PRE(\data_buff_reg[4]_LDC_i_1_n_0 ),
        .Q(\data_buff_reg[4]_P_n_0 ));
  FDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[5]_C 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(\data_buff_reg[5]_LDC_i_2_n_0 ),
        .D(p_2_in[5]),
        .Q(\data_buff_reg[5]_C_n_0 ));
  (* XILINX_LEGACY_PRIM = "LDC" *) 
  LDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[5]_LDC 
       (.CLR(\data_buff_reg[5]_LDC_i_2_n_0 ),
        .D(1'b1),
        .G(\data_buff_reg[5]_LDC_i_1_n_0 ),
        .GE(1'b1),
        .Q(\data_buff_reg[5]_LDC_n_0 ));
  LUT2 #(
    .INIT(4'h8)) 
    \data_buff_reg[5]_LDC_i_1 
       (.I0(d_IBUF[5]),
        .I1(set_IBUF),
        .O(\data_buff_reg[5]_LDC_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \data_buff_reg[5]_LDC_i_2 
       (.I0(set_IBUF),
        .I1(d_IBUF[5]),
        .O(\data_buff_reg[5]_LDC_i_2_n_0 ));
  FDPE #(
    .INIT(1'b1)) 
    \data_buff_reg[5]_P 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .D(p_2_in[5]),
        .PRE(\data_buff_reg[5]_LDC_i_1_n_0 ),
        .Q(\data_buff_reg[5]_P_n_0 ));
  FDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[6]_C 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(\data_buff_reg[6]_LDC_i_2_n_0 ),
        .D(p_2_in[6]),
        .Q(\data_buff_reg[6]_C_n_0 ));
  (* XILINX_LEGACY_PRIM = "LDC" *) 
  LDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[6]_LDC 
       (.CLR(\data_buff_reg[6]_LDC_i_2_n_0 ),
        .D(1'b1),
        .G(\data_buff_reg[6]_LDC_i_1_n_0 ),
        .GE(1'b1),
        .Q(\data_buff_reg[6]_LDC_n_0 ));
  LUT2 #(
    .INIT(4'h8)) 
    \data_buff_reg[6]_LDC_i_1 
       (.I0(d_IBUF[6]),
        .I1(set_IBUF),
        .O(\data_buff_reg[6]_LDC_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \data_buff_reg[6]_LDC_i_2 
       (.I0(set_IBUF),
        .I1(d_IBUF[6]),
        .O(\data_buff_reg[6]_LDC_i_2_n_0 ));
  FDPE #(
    .INIT(1'b1)) 
    \data_buff_reg[6]_P 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .D(p_2_in[6]),
        .PRE(\data_buff_reg[6]_LDC_i_1_n_0 ),
        .Q(\data_buff_reg[6]_P_n_0 ));
  FDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[7]_C 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(\data_buff_reg[7]_LDC_i_2_n_0 ),
        .D(p_2_in[7]),
        .Q(\data_buff_reg[7]_C_n_0 ));
  (* XILINX_LEGACY_PRIM = "LDC" *) 
  LDCE #(
    .INIT(1'b0)) 
    \data_buff_reg[7]_LDC 
       (.CLR(\data_buff_reg[7]_LDC_i_2_n_0 ),
        .D(1'b1),
        .G(\data_buff_reg[7]_LDC_i_1_n_0 ),
        .GE(1'b1),
        .Q(\data_buff_reg[7]_LDC_n_0 ));
  LUT2 #(
    .INIT(4'h8)) 
    \data_buff_reg[7]_LDC_i_1 
       (.I0(d_IBUF[7]),
        .I1(set_IBUF),
        .O(\data_buff_reg[7]_LDC_i_1_n_0 ));
  LUT2 #(
    .INIT(4'h2)) 
    \data_buff_reg[7]_LDC_i_2 
       (.I0(set_IBUF),
        .I1(d_IBUF[7]),
        .O(\data_buff_reg[7]_LDC_i_2_n_0 ));
  FDPE #(
    .INIT(1'b1)) 
    \data_buff_reg[7]_P 
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .D(p_2_in[7]),
        .PRE(\data_buff_reg[7]_LDC_i_1_n_0 ),
        .Q(\data_buff_reg[7]_P_n_0 ));
  LUT3 #(
    .INIT(8'hB8)) 
    q_i_1
       (.I0(\data_buff_reg[7]_P_n_0 ),
        .I1(\data_buff_reg[7]_LDC_n_0 ),
        .I2(\data_buff_reg[7]_C_n_0 ),
        .O(p_0_in));
  FDCE #(
    .INIT(1'b0)) 
    q_reg
       (.C(clk_IBUF_BUFG),
        .CE(1'b1),
        .CLR(set_IBUF),
        .D(p_0_in),
        .Q(q));
endmodule

(* NotValidForBitStream *)
module top
   (clk,
    set,
    rst,
    d,
    z);
  input clk;
  input set;
  input rst;
  input [7:0]d;
  output z;

  wire clk;
  wire clk_IBUF;
  wire clk_IBUF_BUFG;
  wire [7:0]d;
  wire [7:0]d_IBUF;
  wire q;
  wire rst;
  wire rst_IBUF;
  wire set;
  wire set_IBUF;
  wire z;
  wire z_OBUF;

initial begin
 $sdf_annotate("top_sim_time_synth.sdf",,,,"tool_control");
end
  BUFG clk_IBUF_BUFG_inst
       (.I(clk_IBUF),
        .O(clk_IBUF_BUFG));
  IBUF clk_IBUF_inst
       (.I(clk),
        .O(clk_IBUF));
  IBUF \d_IBUF[0]_inst 
       (.I(d[0]),
        .O(d_IBUF[0]));
  IBUF \d_IBUF[1]_inst 
       (.I(d[1]),
        .O(d_IBUF[1]));
  IBUF \d_IBUF[2]_inst 
       (.I(d[2]),
        .O(d_IBUF[2]));
  IBUF \d_IBUF[3]_inst 
       (.I(d[3]),
        .O(d_IBUF[3]));
  IBUF \d_IBUF[4]_inst 
       (.I(d[4]),
        .O(d_IBUF[4]));
  IBUF \d_IBUF[5]_inst 
       (.I(d[5]),
        .O(d_IBUF[5]));
  IBUF \d_IBUF[6]_inst 
       (.I(d[6]),
        .O(d_IBUF[6]));
  IBUF \d_IBUF[7]_inst 
       (.I(d[7]),
        .O(d_IBUF[7]));
  moorefsm fsm
       (.clk_IBUF_BUFG(clk_IBUF_BUFG),
        .q(q),
        .rst_IBUF(rst_IBUF),
        .z_OBUF(z_OBUF));
  IBUF rst_IBUF_inst
       (.I(rst),
        .O(rst_IBUF));
  IBUF set_IBUF_inst
       (.I(set),
        .O(set_IBUF));
  par2ser u
       (.clk_IBUF_BUFG(clk_IBUF_BUFG),
        .d_IBUF(d_IBUF),
        .q(q),
        .set_IBUF(set_IBUF));
  OBUF z_OBUF_inst
       (.I(z_OBUF),
        .O(z));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule
`endif
