////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: top_level_lab7_synthesis.v
// /___/   /\     Timestamp: Sun Nov 22 22:33:51 2020
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim top_level_lab7.ngc top_level_lab7_synthesis.v 
// Device	: xc3s1200e-4-fg320
// Input file	: top_level_lab7.ngc
// Output file	: C:\Users\diona\OneDrive\Documentos\Projetos Xilinx\lab5\FSM\netgen\synthesis\top_level_lab7_synthesis.v
// # of Modules	: 1
// Design Name	: top_level_lab7
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

module top_level_lab7 (
  clk, reset, an, sseg
);
  input clk;
  input reset;
  output [3 : 0] an;
  output [7 : 0] sseg;
  wire an_0_OBUF_20;
  wire an_1_OBUF_21;
  wire an_2_OBUF_22;
  wire an_3_OBUF_23;
  wire clk_BUFGP_25;
  wire \fsm_unit/state_reg_FSM_FFd1_26 ;
  wire \fsm_unit/state_reg_FSM_FFd1-In ;
  wire \fsm_unit/state_reg_FSM_FFd2_28 ;
  wire \fsm_unit/state_reg_FSM_FFd2-In ;
  wire reset_IBUF_31;
  wire sseg_1_OBUF_40;
  wire sseg_2_OBUF_41;
  wire sseg_3_OBUF_42;
  wire sseg_4_OBUF_43;
  wire sseg_6_OBUF_44;
  wire sseg_7_OBUF_45;
  wire timer_tick;
  wire \timer_unit/Mcount_count_reg_cy<0>_rt_48 ;
  wire \timer_unit/timer_tick_cmp_eq000012_94 ;
  wire \timer_unit/timer_tick_cmp_eq000025_95 ;
  wire \timer_unit/timer_tick_cmp_eq000049_96 ;
  wire \timer_unit/timer_tick_cmp_eq000062_97 ;
  wire [15 : 0] Result;
  wire [14 : 0] \timer_unit/Mcount_count_reg_cy ;
  wire [15 : 1] \timer_unit/Mcount_count_reg_lut ;
  wire [15 : 0] \timer_unit/count_reg ;
  GND   XST_GND (
    .G(sseg_1_OBUF_40)
  );
  VCC   XST_VCC (
    .P(sseg_7_OBUF_45)
  );
  FDP   \timer_unit/count_reg_0  (
    .C(clk_BUFGP_25),
    .D(Result[0]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [0])
  );
  FDP   \timer_unit/count_reg_1  (
    .C(clk_BUFGP_25),
    .D(Result[1]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [1])
  );
  FDP   \timer_unit/count_reg_2  (
    .C(clk_BUFGP_25),
    .D(Result[2]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [2])
  );
  FDP   \timer_unit/count_reg_3  (
    .C(clk_BUFGP_25),
    .D(Result[3]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [3])
  );
  FDP   \timer_unit/count_reg_4  (
    .C(clk_BUFGP_25),
    .D(Result[4]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [4])
  );
  FDP   \timer_unit/count_reg_5  (
    .C(clk_BUFGP_25),
    .D(Result[5]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [5])
  );
  FDP   \timer_unit/count_reg_6  (
    .C(clk_BUFGP_25),
    .D(Result[6]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [6])
  );
  FDP   \timer_unit/count_reg_7  (
    .C(clk_BUFGP_25),
    .D(Result[7]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [7])
  );
  FDP   \timer_unit/count_reg_8  (
    .C(clk_BUFGP_25),
    .D(Result[8]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [8])
  );
  FDP   \timer_unit/count_reg_9  (
    .C(clk_BUFGP_25),
    .D(Result[9]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [9])
  );
  FDP   \timer_unit/count_reg_10  (
    .C(clk_BUFGP_25),
    .D(Result[10]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [10])
  );
  FDP   \timer_unit/count_reg_11  (
    .C(clk_BUFGP_25),
    .D(Result[11]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [11])
  );
  FDP   \timer_unit/count_reg_12  (
    .C(clk_BUFGP_25),
    .D(Result[12]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [12])
  );
  FDP   \timer_unit/count_reg_13  (
    .C(clk_BUFGP_25),
    .D(Result[13]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [13])
  );
  FDP   \timer_unit/count_reg_14  (
    .C(clk_BUFGP_25),
    .D(Result[14]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [14])
  );
  FDP   \timer_unit/count_reg_15  (
    .C(clk_BUFGP_25),
    .D(Result[15]),
    .PRE(reset_IBUF_31),
    .Q(\timer_unit/count_reg [15])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<0>  (
    .CI(sseg_7_OBUF_45),
    .DI(sseg_1_OBUF_40),
    .S(\timer_unit/Mcount_count_reg_cy<0>_rt_48 ),
    .O(\timer_unit/Mcount_count_reg_cy [0])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<0>  (
    .CI(sseg_7_OBUF_45),
    .LI(\timer_unit/Mcount_count_reg_cy<0>_rt_48 ),
    .O(Result[0])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<1>  (
    .CI(\timer_unit/Mcount_count_reg_cy [0]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [1]),
    .O(\timer_unit/Mcount_count_reg_cy [1])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<1>  (
    .CI(\timer_unit/Mcount_count_reg_cy [0]),
    .LI(\timer_unit/Mcount_count_reg_lut [1]),
    .O(Result[1])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<2>  (
    .CI(\timer_unit/Mcount_count_reg_cy [1]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [2]),
    .O(\timer_unit/Mcount_count_reg_cy [2])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<2>  (
    .CI(\timer_unit/Mcount_count_reg_cy [1]),
    .LI(\timer_unit/Mcount_count_reg_lut [2]),
    .O(Result[2])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<3>  (
    .CI(\timer_unit/Mcount_count_reg_cy [2]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [3]),
    .O(\timer_unit/Mcount_count_reg_cy [3])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<3>  (
    .CI(\timer_unit/Mcount_count_reg_cy [2]),
    .LI(\timer_unit/Mcount_count_reg_lut [3]),
    .O(Result[3])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<4>  (
    .CI(\timer_unit/Mcount_count_reg_cy [3]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [4]),
    .O(\timer_unit/Mcount_count_reg_cy [4])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<4>  (
    .CI(\timer_unit/Mcount_count_reg_cy [3]),
    .LI(\timer_unit/Mcount_count_reg_lut [4]),
    .O(Result[4])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<5>  (
    .CI(\timer_unit/Mcount_count_reg_cy [4]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [5]),
    .O(\timer_unit/Mcount_count_reg_cy [5])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<5>  (
    .CI(\timer_unit/Mcount_count_reg_cy [4]),
    .LI(\timer_unit/Mcount_count_reg_lut [5]),
    .O(Result[5])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<6>  (
    .CI(\timer_unit/Mcount_count_reg_cy [5]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [6]),
    .O(\timer_unit/Mcount_count_reg_cy [6])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<6>  (
    .CI(\timer_unit/Mcount_count_reg_cy [5]),
    .LI(\timer_unit/Mcount_count_reg_lut [6]),
    .O(Result[6])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<7>  (
    .CI(\timer_unit/Mcount_count_reg_cy [6]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [7]),
    .O(\timer_unit/Mcount_count_reg_cy [7])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<7>  (
    .CI(\timer_unit/Mcount_count_reg_cy [6]),
    .LI(\timer_unit/Mcount_count_reg_lut [7]),
    .O(Result[7])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<8>  (
    .CI(\timer_unit/Mcount_count_reg_cy [7]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [8]),
    .O(\timer_unit/Mcount_count_reg_cy [8])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<8>  (
    .CI(\timer_unit/Mcount_count_reg_cy [7]),
    .LI(\timer_unit/Mcount_count_reg_lut [8]),
    .O(Result[8])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<9>  (
    .CI(\timer_unit/Mcount_count_reg_cy [8]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [9]),
    .O(\timer_unit/Mcount_count_reg_cy [9])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<9>  (
    .CI(\timer_unit/Mcount_count_reg_cy [8]),
    .LI(\timer_unit/Mcount_count_reg_lut [9]),
    .O(Result[9])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<10>  (
    .CI(\timer_unit/Mcount_count_reg_cy [9]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [10]),
    .O(\timer_unit/Mcount_count_reg_cy [10])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<10>  (
    .CI(\timer_unit/Mcount_count_reg_cy [9]),
    .LI(\timer_unit/Mcount_count_reg_lut [10]),
    .O(Result[10])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<11>  (
    .CI(\timer_unit/Mcount_count_reg_cy [10]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [11]),
    .O(\timer_unit/Mcount_count_reg_cy [11])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<11>  (
    .CI(\timer_unit/Mcount_count_reg_cy [10]),
    .LI(\timer_unit/Mcount_count_reg_lut [11]),
    .O(Result[11])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<12>  (
    .CI(\timer_unit/Mcount_count_reg_cy [11]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [12]),
    .O(\timer_unit/Mcount_count_reg_cy [12])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<12>  (
    .CI(\timer_unit/Mcount_count_reg_cy [11]),
    .LI(\timer_unit/Mcount_count_reg_lut [12]),
    .O(Result[12])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<13>  (
    .CI(\timer_unit/Mcount_count_reg_cy [12]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [13]),
    .O(\timer_unit/Mcount_count_reg_cy [13])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<13>  (
    .CI(\timer_unit/Mcount_count_reg_cy [12]),
    .LI(\timer_unit/Mcount_count_reg_lut [13]),
    .O(Result[13])
  );
  MUXCY   \timer_unit/Mcount_count_reg_cy<14>  (
    .CI(\timer_unit/Mcount_count_reg_cy [13]),
    .DI(sseg_7_OBUF_45),
    .S(\timer_unit/Mcount_count_reg_lut [14]),
    .O(\timer_unit/Mcount_count_reg_cy [14])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<14>  (
    .CI(\timer_unit/Mcount_count_reg_cy [13]),
    .LI(\timer_unit/Mcount_count_reg_lut [14]),
    .O(Result[14])
  );
  XORCY   \timer_unit/Mcount_count_reg_xor<15>  (
    .CI(\timer_unit/Mcount_count_reg_cy [14]),
    .LI(\timer_unit/Mcount_count_reg_lut [15]),
    .O(Result[15])
  );
  FDC #(
    .INIT ( 1'b0 ))
  \fsm_unit/state_reg_FSM_FFd1  (
    .C(clk_BUFGP_25),
    .CLR(reset_IBUF_31),
    .D(\fsm_unit/state_reg_FSM_FFd1-In ),
    .Q(\fsm_unit/state_reg_FSM_FFd1_26 )
  );
  FDC #(
    .INIT ( 1'b0 ))
  \fsm_unit/state_reg_FSM_FFd2  (
    .C(clk_BUFGP_25),
    .CLR(reset_IBUF_31),
    .D(\fsm_unit/state_reg_FSM_FFd2-In ),
    .Q(\fsm_unit/state_reg_FSM_FFd2_28 )
  );
  LUT2 #(
    .INIT ( 4'hD ))
  \decod_unit/Mdecod_s11  (
    .I0(\fsm_unit/state_reg_FSM_FFd1_26 ),
    .I1(\fsm_unit/state_reg_FSM_FFd2_28 ),
    .O(an_1_OBUF_21)
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  \ascii_sseg_unit/sseg_or00021  (
    .I0(\fsm_unit/state_reg_FSM_FFd2_28 ),
    .I1(\fsm_unit/state_reg_FSM_FFd1_26 ),
    .O(sseg_2_OBUF_41)
  );
  LUT2 #(
    .INIT ( 4'h1 ))
  \ascii_sseg_unit/sseg_cmp_eq00351  (
    .I0(\fsm_unit/state_reg_FSM_FFd2_28 ),
    .I1(\fsm_unit/state_reg_FSM_FFd1_26 ),
    .O(sseg_6_OBUF_44)
  );
  LUT2 #(
    .INIT ( 4'hE ))
  \an<3>1  (
    .I0(\fsm_unit/state_reg_FSM_FFd1_26 ),
    .I1(\fsm_unit/state_reg_FSM_FFd2_28 ),
    .O(an_3_OBUF_23)
  );
  LUT2 #(
    .INIT ( 4'h7 ))
  \an<0>1  (
    .I0(\fsm_unit/state_reg_FSM_FFd2_28 ),
    .I1(\fsm_unit/state_reg_FSM_FFd1_26 ),
    .O(an_0_OBUF_20)
  );
  LUT2 #(
    .INIT ( 4'h6 ))
  \ascii_sseg_unit/sseg<4>1  (
    .I0(\fsm_unit/state_reg_FSM_FFd1_26 ),
    .I1(\fsm_unit/state_reg_FSM_FFd2_28 ),
    .O(sseg_4_OBUF_43)
  );
  LUT2 #(
    .INIT ( 4'hD ))
  \an<2>1  (
    .I0(\fsm_unit/state_reg_FSM_FFd2_28 ),
    .I1(\fsm_unit/state_reg_FSM_FFd1_26 ),
    .O(an_2_OBUF_22)
  );
  LUT2 #(
    .INIT ( 4'h6 ))
  \fsm_unit/state_reg_FSM_FFd2-In1  (
    .I0(\fsm_unit/state_reg_FSM_FFd2_28 ),
    .I1(timer_tick),
    .O(\fsm_unit/state_reg_FSM_FFd2-In )
  );
  LUT3 #(
    .INIT ( 8'h6A ))
  \fsm_unit/state_reg_FSM_FFd1-In1  (
    .I0(\fsm_unit/state_reg_FSM_FFd1_26 ),
    .I1(\fsm_unit/state_reg_FSM_FFd2_28 ),
    .I2(timer_tick),
    .O(\fsm_unit/state_reg_FSM_FFd1-In )
  );
  LUT4 #(
    .INIT ( 16'h0001 ))
  \timer_unit/timer_tick_cmp_eq000025  (
    .I0(\timer_unit/count_reg [4]),
    .I1(\timer_unit/count_reg [5]),
    .I2(\timer_unit/count_reg [6]),
    .I3(\timer_unit/count_reg [7]),
    .O(\timer_unit/timer_tick_cmp_eq000025_95 )
  );
  LUT4 #(
    .INIT ( 16'h0001 ))
  \timer_unit/timer_tick_cmp_eq000049  (
    .I0(\timer_unit/count_reg [8]),
    .I1(\timer_unit/count_reg [9]),
    .I2(\timer_unit/count_reg [10]),
    .I3(\timer_unit/count_reg [11]),
    .O(\timer_unit/timer_tick_cmp_eq000049_96 )
  );
  LUT4 #(
    .INIT ( 16'h0001 ))
  \timer_unit/timer_tick_cmp_eq000062  (
    .I0(\timer_unit/count_reg [12]),
    .I1(\timer_unit/count_reg [13]),
    .I2(\timer_unit/count_reg [14]),
    .I3(\timer_unit/count_reg [15]),
    .O(\timer_unit/timer_tick_cmp_eq000062_97 )
  );
  LUT4 #(
    .INIT ( 16'h8000 ))
  \timer_unit/timer_tick_cmp_eq000076  (
    .I0(\timer_unit/timer_tick_cmp_eq000012_94 ),
    .I1(\timer_unit/timer_tick_cmp_eq000025_95 ),
    .I2(\timer_unit/timer_tick_cmp_eq000049_96 ),
    .I3(\timer_unit/timer_tick_cmp_eq000062_97 ),
    .O(timer_tick)
  );
  IBUF   reset_IBUF (
    .I(reset),
    .O(reset_IBUF_31)
  );
  OBUF   an_3_OBUF (
    .I(an_3_OBUF_23),
    .O(an[3])
  );
  OBUF   an_2_OBUF (
    .I(an_2_OBUF_22),
    .O(an[2])
  );
  OBUF   an_1_OBUF (
    .I(an_1_OBUF_21),
    .O(an[1])
  );
  OBUF   an_0_OBUF (
    .I(an_0_OBUF_20),
    .O(an[0])
  );
  OBUF   sseg_7_OBUF (
    .I(sseg_7_OBUF_45),
    .O(sseg[7])
  );
  OBUF   sseg_6_OBUF (
    .I(sseg_6_OBUF_44),
    .O(sseg[6])
  );
  OBUF   sseg_5_OBUF (
    .I(an_3_OBUF_23),
    .O(sseg[5])
  );
  OBUF   sseg_4_OBUF (
    .I(sseg_4_OBUF_43),
    .O(sseg[4])
  );
  OBUF   sseg_3_OBUF (
    .I(sseg_3_OBUF_42),
    .O(sseg[3])
  );
  OBUF   sseg_2_OBUF (
    .I(sseg_2_OBUF_41),
    .O(sseg[2])
  );
  OBUF   sseg_1_OBUF (
    .I(sseg_1_OBUF_40),
    .O(sseg[1])
  );
  OBUF   sseg_0_OBUF (
    .I(sseg_6_OBUF_44),
    .O(sseg[0])
  );
  LUT1 #(
    .INIT ( 2'h2 ))
  \timer_unit/Mcount_count_reg_cy<0>_rt  (
    .I0(\timer_unit/count_reg [0]),
    .O(\timer_unit/Mcount_count_reg_cy<0>_rt_48 )
  );
  LUT2 #(
    .INIT ( 4'h2 ))
  \ascii_sseg_unit/sseg_cmp_eq00181  (
    .I0(\fsm_unit/state_reg_FSM_FFd2_28 ),
    .I1(\fsm_unit/state_reg_FSM_FFd1_26 ),
    .O(sseg_3_OBUF_42)
  );
  BUFGP   clk_BUFGP (
    .I(clk),
    .O(clk_BUFGP_25)
  );
  INV   \timer_unit/Mcount_count_reg_lut<1>_INV_0  (
    .I(\timer_unit/count_reg [1]),
    .O(\timer_unit/Mcount_count_reg_lut [1])
  );
  INV   \timer_unit/Mcount_count_reg_lut<2>_INV_0  (
    .I(\timer_unit/count_reg [2]),
    .O(\timer_unit/Mcount_count_reg_lut [2])
  );
  INV   \timer_unit/Mcount_count_reg_lut<3>_INV_0  (
    .I(\timer_unit/count_reg [3]),
    .O(\timer_unit/Mcount_count_reg_lut [3])
  );
  INV   \timer_unit/Mcount_count_reg_lut<4>_INV_0  (
    .I(\timer_unit/count_reg [4]),
    .O(\timer_unit/Mcount_count_reg_lut [4])
  );
  INV   \timer_unit/Mcount_count_reg_lut<5>_INV_0  (
    .I(\timer_unit/count_reg [5]),
    .O(\timer_unit/Mcount_count_reg_lut [5])
  );
  INV   \timer_unit/Mcount_count_reg_lut<6>_INV_0  (
    .I(\timer_unit/count_reg [6]),
    .O(\timer_unit/Mcount_count_reg_lut [6])
  );
  INV   \timer_unit/Mcount_count_reg_lut<7>_INV_0  (
    .I(\timer_unit/count_reg [7]),
    .O(\timer_unit/Mcount_count_reg_lut [7])
  );
  INV   \timer_unit/Mcount_count_reg_lut<8>_INV_0  (
    .I(\timer_unit/count_reg [8]),
    .O(\timer_unit/Mcount_count_reg_lut [8])
  );
  INV   \timer_unit/Mcount_count_reg_lut<9>_INV_0  (
    .I(\timer_unit/count_reg [9]),
    .O(\timer_unit/Mcount_count_reg_lut [9])
  );
  INV   \timer_unit/Mcount_count_reg_lut<10>_INV_0  (
    .I(\timer_unit/count_reg [10]),
    .O(\timer_unit/Mcount_count_reg_lut [10])
  );
  INV   \timer_unit/Mcount_count_reg_lut<11>_INV_0  (
    .I(\timer_unit/count_reg [11]),
    .O(\timer_unit/Mcount_count_reg_lut [11])
  );
  INV   \timer_unit/Mcount_count_reg_lut<12>_INV_0  (
    .I(\timer_unit/count_reg [12]),
    .O(\timer_unit/Mcount_count_reg_lut [12])
  );
  INV   \timer_unit/Mcount_count_reg_lut<13>_INV_0  (
    .I(\timer_unit/count_reg [13]),
    .O(\timer_unit/Mcount_count_reg_lut [13])
  );
  INV   \timer_unit/Mcount_count_reg_lut<14>_INV_0  (
    .I(\timer_unit/count_reg [14]),
    .O(\timer_unit/Mcount_count_reg_lut [14])
  );
  INV   \timer_unit/Mcount_count_reg_lut<15>_INV_0  (
    .I(\timer_unit/count_reg [15]),
    .O(\timer_unit/Mcount_count_reg_lut [15])
  );
  LUT4_L #(
    .INIT ( 16'h0001 ))
  \timer_unit/timer_tick_cmp_eq000012  (
    .I0(\timer_unit/count_reg [0]),
    .I1(\timer_unit/count_reg [1]),
    .I2(\timer_unit/count_reg [2]),
    .I3(\timer_unit/count_reg [3]),
    .LO(\timer_unit/timer_tick_cmp_eq000012_94 )
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

