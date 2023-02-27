////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: garage_top_synthesis.v
// /___/   /\     Timestamp: Fri Dec 11 21:48:12 2020
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim garage_top.ngc garage_top_synthesis.v 
// Device	: xc3s1200e-4-fg320
// Input file	: garage_top.ngc
// Output file	: C:\Users\diona\OneDrive\Documentos\Projetos Xilinx\PPLAB2.garage_door_ctrl\netgen\synthesis\garage_top_synthesis.v
// # of Modules	: 1
// Design Name	: garage_top
// Xilinx        : C:\Xilinx\14.7\ISE_DS\ISE\
//             
// Purpose:    
//     This verilog netlist is a verification model and uses simulation 
//     primitives which may not represent the true implementation of the 
//     device, however the netlist is functionally correct and should not 
//     be modified. This file cannot be synthesized and should only be used 
//     with supported simulation tools.
//             
// Reference:  
//     Command Line Tools User Guide, Chapter 23 and Synthesis and Simulation Design Guide, Chapter 6
//             
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns/1 ps

module garage_top (
  clk, reset, IV, A, F, L, SE, SI, tick
);
  input clk;
  input reset;
  input IV;
  output A;
  output F;
  output L;
  input SE;
  input SI;
  output tick;
  wire A_OBUF_1;
  wire F_OBUF_3;
  wire IV_IBUF_5;
  wire L_OBUF_7;
  wire N13;
  wire N15;
  wire N17;
  wire N19;
  wire N21;
  wire N23;
  wire N25;
  wire N26;
  wire N31;
  wire N32;
  wire N34;
  wire N36;
  wire N37;
  wire N38;
  wire N40;
  wire N41;
  wire N5;
  wire N7;
  wire SE_IBUF_27;
  wire SI_IBUF_29;
  wire clk_BUFGP_31;
  wire \garage_door_unit/state_reg_FSM_FFd1_32 ;
  wire \garage_door_unit/state_reg_FSM_FFd1-In_33 ;
  wire \garage_door_unit/state_reg_FSM_FFd2_34 ;
  wire \garage_door_unit/state_reg_FSM_FFd2-In ;
  wire \garage_door_unit/state_reg_FSM_FFd2-In10_36 ;
  wire \garage_door_unit/state_reg_FSM_FFd2-In14_37 ;
  wire \garage_door_unit/state_reg_FSM_FFd2-In36 ;
  wire \garage_door_unit/state_reg_FSM_FFd3_39 ;
  wire \garage_door_unit/state_reg_FSM_FFd3-In ;
  wire \garage_door_unit/state_reg_FSM_FFd3-In14_41 ;
  wire \garage_door_unit/state_reg_FSM_FFd3-In33_42 ;
  wire \motor_unit/N0 ;
  wire \motor_unit/N111 ;
  wire \motor_unit/count_sec_reg_mux0000<0>_bdd6 ;
  wire reset_IBUF_59;
  wire tick_OBUF_61;
  wire \timer_unit/count_sec_reg_not0002_74 ;
  wire [3 : 0] \motor_unit/count_reg ;
  wire [3 : 0] \motor_unit/count_reg_mux0000 ;
  wire [1 : 0] \motor_unit/count_sec_reg ;
  wire [1 : 0] \motor_unit/count_sec_reg_mux0000 ;
  wire [3 : 0] \timer_unit/count_next ;
  wire [3 : 0] \timer_unit/count_reg ;
  wire [1 : 0] \timer_unit/count_sec_reg ;
  wire [1 : 0] \timer_unit/count_sec_reg_mux0000 ;
  FDC #(
    .INIT ( 1'b0 ))
  \garage_door_unit/state_reg_FSM_FFd3  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\garage_door_unit/state_reg_FSM_FFd3-In ),
    .Q(\garage_door_unit/state_reg_FSM_FFd3_39 )
  );
  FDC #(
    .INIT ( 1'b0 ))
  \garage_door_unit/state_reg_FSM_FFd1  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\garage_door_unit/state_reg_FSM_FFd1-In_33 ),
    .Q(\garage_door_unit/state_reg_FSM_FFd1_32 )
  );
  FDP #(
    .INIT ( 1'b0 ))
  \garage_door_unit/state_reg_FSM_FFd2  (
    .C(clk_BUFGP_31),
    .D(\garage_door_unit/state_reg_FSM_FFd2-In ),
    .PRE(reset_IBUF_59),
    .Q(\garage_door_unit/state_reg_FSM_FFd2_34 )
  );
  FDC   \motor_unit/count_reg_3  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\motor_unit/count_reg_mux0000 [0]),
    .Q(\motor_unit/count_reg [3])
  );
  FDC   \motor_unit/count_reg_2  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\motor_unit/count_reg_mux0000 [1]),
    .Q(\motor_unit/count_reg [2])
  );
  FDC   \motor_unit/count_reg_1  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\motor_unit/count_reg_mux0000 [2]),
    .Q(\motor_unit/count_reg [1])
  );
  FDC   \motor_unit/count_reg_0  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\motor_unit/count_reg_mux0000 [3]),
    .Q(\motor_unit/count_reg [0])
  );
  FDC   \motor_unit/count_sec_reg_1  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\motor_unit/count_sec_reg_mux0000 [1]),
    .Q(\motor_unit/count_sec_reg [1])
  );
  FDC   \motor_unit/count_sec_reg_0  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\motor_unit/count_sec_reg_mux0000 [0]),
    .Q(\motor_unit/count_sec_reg [0])
  );
  FDC   \timer_unit/count_reg_3  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\timer_unit/count_next [3]),
    .Q(\timer_unit/count_reg [3])
  );
  FDC   \timer_unit/count_reg_2  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\timer_unit/count_next [2]),
    .Q(\timer_unit/count_reg [2])
  );
  FDC   \timer_unit/count_reg_1  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\timer_unit/count_next [1]),
    .Q(\timer_unit/count_reg [1])
  );
  FDC   \timer_unit/count_reg_0  (
    .C(clk_BUFGP_31),
    .CLR(reset_IBUF_59),
    .D(\timer_unit/count_next [0]),
    .Q(\timer_unit/count_reg [0])
  );
  FDCE   \timer_unit/count_sec_reg_1  (
    .C(clk_BUFGP_31),
    .CE(\timer_unit/count_sec_reg_not0002_74 ),
    .CLR(reset_IBUF_59),
    .D(\timer_unit/count_sec_reg_mux0000 [0]),
    .Q(\timer_unit/count_sec_reg [1])
  );
  FDCE   \timer_unit/count_sec_reg_0  (
    .C(clk_BUFGP_31),
    .CE(\timer_unit/count_sec_reg_not0002_74 ),
    .CLR(reset_IBUF_59),
    .D(\timer_unit/count_sec_reg_mux0000 [1]),
    .Q(\timer_unit/count_sec_reg [0])
  );
  LUT3 #(
    .INIT ( 8'hFD ))
  \garage_door_unit/state_reg_FSM_Out21  (
    .I0(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I1(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .I2(\garage_door_unit/state_reg_FSM_FFd1_32 ),
    .O(L_OBUF_7)
  );
  LUT2 #(
    .INIT ( 4'h7 ))
  \timer_unit/count_next<3>_SW0  (
    .I0(\timer_unit/count_reg [1]),
    .I1(\timer_unit/count_reg [0]),
    .O(N5)
  );
  LUT4 #(
    .INIT ( 16'h00A6 ))
  \timer_unit/count_next<3>  (
    .I0(\timer_unit/count_reg [3]),
    .I1(\timer_unit/count_reg [2]),
    .I2(N5),
    .I3(\timer_unit/count_sec_reg_not0002_74 ),
    .O(\timer_unit/count_next [3])
  );
  LUT3 #(
    .INIT ( 8'hF7 ))
  \timer_unit/tick_and0000_SW0  (
    .I0(\timer_unit/count_sec_reg [1]),
    .I1(\timer_unit/count_sec_reg [0]),
    .I2(\timer_unit/count_reg [0]),
    .O(N7)
  );
  LUT4 #(
    .INIT ( 16'h0001 ))
  \timer_unit/tick_and0000  (
    .I0(\timer_unit/count_reg [3]),
    .I1(\timer_unit/count_reg [2]),
    .I2(\timer_unit/count_reg [1]),
    .I3(N7),
    .O(tick_OBUF_61)
  );
  LUT2 #(
    .INIT ( 4'h9 ))
  \motor_unit/Mmux_count_reg_mux0000121  (
    .I0(\motor_unit/count_reg [0]),
    .I1(N41),
    .O(\motor_unit/count_reg_mux0000 [3])
  );
  LUT3 #(
    .INIT ( 8'hA6 ))
  \motor_unit/Mmux_count_reg_mux000091  (
    .I0(\motor_unit/count_reg [1]),
    .I1(\motor_unit/count_reg [0]),
    .I2(\motor_unit/N0 ),
    .O(\motor_unit/count_reg_mux0000 [2])
  );
  LUT4 #(
    .INIT ( 16'hCC6C ))
  \motor_unit/Mmux_count_reg_mux000061  (
    .I0(\motor_unit/count_reg [0]),
    .I1(\motor_unit/count_reg [2]),
    .I2(\motor_unit/count_reg [1]),
    .I3(\motor_unit/N0 ),
    .O(\motor_unit/count_reg_mux0000 [1])
  );
  LUT3 #(
    .INIT ( 8'h80 ))
  \motor_unit/A_and00002  (
    .I0(\motor_unit/count_sec_reg [0]),
    .I1(\motor_unit/count_sec_reg [1]),
    .I2(\motor_unit/N111 ),
    .O(A_OBUF_1)
  );
  LUT3 #(
    .INIT ( 8'h02 ))
  \garage_door_unit/state_reg_FSM_FFd3-In6  (
    .I0(\garage_door_unit/state_reg_FSM_FFd1_32 ),
    .I1(SE_IBUF_27),
    .I2(SI_IBUF_29),
    .O(\garage_door_unit/state_reg_FSM_FFd2-In36 )
  );
  LUT4 #(
    .INIT ( 16'hFFEA ))
  \garage_door_unit/state_reg_FSM_FFd3-In42  (
    .I0(\garage_door_unit/state_reg_FSM_FFd2-In36 ),
    .I1(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I2(\garage_door_unit/state_reg_FSM_FFd3-In33_42 ),
    .I3(\garage_door_unit/state_reg_FSM_FFd3-In14_41 ),
    .O(\garage_door_unit/state_reg_FSM_FFd3-In )
  );
  LUT3 #(
    .INIT ( 8'h7F ))
  \motor_unit/count_sec_reg_mux0000<0>31  (
    .I0(\motor_unit/count_reg [0]),
    .I1(\motor_unit/count_reg [1]),
    .I2(\motor_unit/count_reg [2]),
    .O(\motor_unit/count_sec_reg_mux0000<0>_bdd6 )
  );
  LUT3 #(
    .INIT ( 8'h02 ))
  \motor_unit/F_and00001  (
    .I0(\motor_unit/N111 ),
    .I1(\motor_unit/count_sec_reg [0]),
    .I2(\motor_unit/count_sec_reg [1]),
    .O(F_OBUF_3)
  );
  LUT4 #(
    .INIT ( 16'hFB40 ))
  \motor_unit/count_sec_reg_mux0000<1>  (
    .I0(\motor_unit/count_sec_reg_mux0000<0>_bdd6 ),
    .I1(\motor_unit/count_reg [3]),
    .I2(N13),
    .I3(\motor_unit/count_sec_reg [1]),
    .O(\motor_unit/count_sec_reg_mux0000 [1])
  );
  LUT4 #(
    .INIT ( 16'hFB40 ))
  \motor_unit/count_sec_reg_mux0000<0>  (
    .I0(\motor_unit/count_sec_reg_mux0000<0>_bdd6 ),
    .I1(\motor_unit/count_reg [3]),
    .I2(N15),
    .I3(\motor_unit/count_sec_reg [0]),
    .O(\motor_unit/count_sec_reg_mux0000 [0])
  );
  LUT2 #(
    .INIT ( 4'h1 ))
  \garage_door_unit/state_reg_FSM_FFd2-In14  (
    .I0(IV_IBUF_5),
    .I1(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .O(\garage_door_unit/state_reg_FSM_FFd2-In14_37 )
  );
  LUT4 #(
    .INIT ( 16'hEEEC ))
  \garage_door_unit/state_reg_FSM_FFd2-In39  (
    .I0(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I1(\garage_door_unit/state_reg_FSM_FFd2-In36 ),
    .I2(\garage_door_unit/state_reg_FSM_FFd2-In14_37 ),
    .I3(\garage_door_unit/state_reg_FSM_FFd2-In10_36 ),
    .O(\garage_door_unit/state_reg_FSM_FFd2-In )
  );
  IBUF   reset_IBUF (
    .I(reset),
    .O(reset_IBUF_59)
  );
  IBUF   IV_IBUF (
    .I(IV),
    .O(IV_IBUF_5)
  );
  IBUF   SE_IBUF (
    .I(SE),
    .O(SE_IBUF_27)
  );
  IBUF   SI_IBUF (
    .I(SI),
    .O(SI_IBUF_29)
  );
  OBUF   A_OBUF (
    .I(A_OBUF_1),
    .O(A)
  );
  OBUF   F_OBUF (
    .I(F_OBUF_3),
    .O(F)
  );
  OBUF   L_OBUF (
    .I(L_OBUF_7),
    .O(L)
  );
  OBUF   tick_OBUF (
    .I(tick_OBUF_61),
    .O(tick)
  );
  LUT4 #(
    .INIT ( 16'hCC6C ))
  \motor_unit/Mmux_count_reg_mux00003  (
    .I0(N17),
    .I1(\motor_unit/count_reg [3]),
    .I2(\motor_unit/count_reg [2]),
    .I3(\motor_unit/N0 ),
    .O(\motor_unit/count_reg_mux0000 [0])
  );
  LUT3 #(
    .INIT ( 8'hFE ))
  \timer_unit/tick_and0000_SW1  (
    .I0(\timer_unit/count_reg [3]),
    .I1(\timer_unit/count_reg [2]),
    .I2(\timer_unit/count_reg [1]),
    .O(N19)
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  \motor_unit/A_and00002_SW0  (
    .I0(\motor_unit/count_sec_reg [1]),
    .I1(\motor_unit/count_sec_reg [0]),
    .O(N21)
  );
  LUT4 #(
    .INIT ( 16'h0444 ))
  \garage_door_unit/state_reg_FSM_FFd3-In14  (
    .I0(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I1(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .I2(N40),
    .I3(N21),
    .O(\garage_door_unit/state_reg_FSM_FFd3-In14_41 )
  );
  LUT2 #(
    .INIT ( 4'hE ))
  \motor_unit/F_and00001_SW0  (
    .I0(\motor_unit/count_sec_reg [1]),
    .I1(\motor_unit/count_sec_reg [0]),
    .O(N23)
  );
  LUT2 #(
    .INIT ( 4'hE ))
  \motor_unit/F_and00001_SW1  (
    .I0(SI_IBUF_29),
    .I1(SE_IBUF_27),
    .O(N25)
  );
  LUT4 #(
    .INIT ( 16'hEEE0 ))
  \motor_unit/F_and00001_SW2  (
    .I0(SE_IBUF_27),
    .I1(SI_IBUF_29),
    .I2(\motor_unit/count_sec_reg [0]),
    .I3(\motor_unit/count_sec_reg [1]),
    .O(N26)
  );
  LUT4 #(
    .INIT ( 16'hABA8 ))
  \garage_door_unit/state_reg_FSM_FFd1-In  (
    .I0(N32),
    .I1(N7),
    .I2(N19),
    .I3(N31),
    .O(\garage_door_unit/state_reg_FSM_FFd1-In_33 )
  );
  LUT3 #(
    .INIT ( 8'h80 ))
  \timer_unit/count_sec_reg_not0002_SW3  (
    .I0(\timer_unit/count_reg [3]),
    .I1(\timer_unit/count_reg [2]),
    .I2(\timer_unit/count_reg [0]),
    .O(N34)
  );
  LUT4 #(
    .INIT ( 16'hF222 ))
  \timer_unit/count_sec_reg_not0002  (
    .I0(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .I1(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I2(\timer_unit/count_reg [1]),
    .I3(N34),
    .O(\timer_unit/count_sec_reg_not0002_74 )
  );
  MUXF5   \garage_door_unit/state_reg_FSM_FFd1-In_SW0_SW0  (
    .I0(N36),
    .I1(N37),
    .S(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .O(N31)
  );
  LUT4 #(
    .INIT ( 16'hE0EF ))
  \garage_door_unit/state_reg_FSM_FFd1-In_SW0_SW0_F  (
    .I0(SI_IBUF_29),
    .I1(SE_IBUF_27),
    .I2(\garage_door_unit/state_reg_FSM_FFd1_32 ),
    .I3(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .O(N36)
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \garage_door_unit/state_reg_FSM_FFd1-In_SW0_SW0_G  (
    .I0(\garage_door_unit/state_reg_FSM_FFd1_32 ),
    .I1(SI_IBUF_29),
    .I2(SE_IBUF_27),
    .O(N37)
  );
  LUT4 #(
    .INIT ( 16'h6A00 ))
  \timer_unit/count_next<2>1  (
    .I0(\timer_unit/count_reg [2]),
    .I1(\timer_unit/count_reg [1]),
    .I2(\timer_unit/count_reg [0]),
    .I3(N38),
    .O(\timer_unit/count_next [2])
  );
  LUT3 #(
    .INIT ( 8'h31 ))
  \timer_unit/count_sec_reg_mux0000<1>1  (
    .I0(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .I1(\timer_unit/count_sec_reg [0]),
    .I2(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .O(\timer_unit/count_sec_reg_mux0000 [1])
  );
  LUT3 #(
    .INIT ( 8'h31 ))
  \timer_unit/count_next<0>1  (
    .I0(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .I1(\timer_unit/count_reg [0]),
    .I2(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .O(\timer_unit/count_next [0])
  );
  LUT4 #(
    .INIT ( 16'h283C ))
  \timer_unit/count_sec_reg_mux0000<0>1  (
    .I0(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I1(\timer_unit/count_sec_reg [1]),
    .I2(\timer_unit/count_sec_reg [0]),
    .I3(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .O(\timer_unit/count_sec_reg_mux0000 [0])
  );
  LUT4 #(
    .INIT ( 16'h283C ))
  \timer_unit/count_next<1>1  (
    .I0(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I1(\timer_unit/count_reg [1]),
    .I2(\timer_unit/count_reg [0]),
    .I3(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .O(\timer_unit/count_next [1])
  );
  BUFGP   clk_BUFGP (
    .I(clk),
    .O(clk_BUFGP_31)
  );
  LUT4_D #(
    .INIT ( 16'h0001 ))
  \motor_unit/A_and000011  (
    .I0(\motor_unit/count_reg [3]),
    .I1(\motor_unit/count_reg [2]),
    .I2(\motor_unit/count_reg [1]),
    .I3(\motor_unit/count_reg [0]),
    .LO(N40),
    .O(\motor_unit/N111 )
  );
  LUT4_D #(
    .INIT ( 16'h18FF ))
  \motor_unit/Mmux_count_reg_mux0000311  (
    .I0(\motor_unit/count_sec_reg [1]),
    .I1(\motor_unit/count_sec_reg [0]),
    .I2(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I3(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .LO(N41),
    .O(\motor_unit/N0 )
  );
  LUT2_L #(
    .INIT ( 4'h8 ))
  \motor_unit/Mmux_count_reg_mux00003_SW0_SW0  (
    .I0(\motor_unit/count_reg [1]),
    .I1(\motor_unit/count_reg [0]),
    .LO(N17)
  );
  LUT4_L #(
    .INIT ( 16'hEE2E ))
  \garage_door_unit/state_reg_FSM_FFd3-In33  (
    .I0(IV_IBUF_5),
    .I1(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .I2(\motor_unit/N111 ),
    .I3(N23),
    .LO(\garage_door_unit/state_reg_FSM_FFd3-In33_42 )
  );
  LUT4_L #(
    .INIT ( 16'h0C44 ))
  \garage_door_unit/state_reg_FSM_FFd2-In10  (
    .I0(N25),
    .I1(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .I2(N26),
    .I3(\motor_unit/N111 ),
    .LO(\garage_door_unit/state_reg_FSM_FFd2-In10_36 )
  );
  LUT4_L #(
    .INIT ( 16'hAE2A ))
  \motor_unit/count_sec_reg_mux0000<1>_SW0  (
    .I0(\motor_unit/count_sec_reg [1]),
    .I1(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .I2(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I3(\motor_unit/count_sec_reg [0]),
    .LO(N13)
  );
  LUT4_L #(
    .INIT ( 16'h2BCC ))
  \motor_unit/count_sec_reg_mux0000<0>_SW0  (
    .I0(\motor_unit/count_sec_reg [1]),
    .I1(\motor_unit/count_sec_reg [0]),
    .I2(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I3(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .LO(N15)
  );
  LUT3_L #(
    .INIT ( 8'hA8 ))
  \garage_door_unit/state_reg_FSM_FFd1-In_SW0_SW1  (
    .I0(\garage_door_unit/state_reg_FSM_FFd1_32 ),
    .I1(SI_IBUF_29),
    .I2(SE_IBUF_27),
    .LO(N32)
  );
  LUT2_L #(
    .INIT ( 4'hB ))
  \timer_unit/count_next<2>1_SW0  (
    .I0(\garage_door_unit/state_reg_FSM_FFd2_34 ),
    .I1(\garage_door_unit/state_reg_FSM_FFd3_39 ),
    .LO(N38)
  );
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

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
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

