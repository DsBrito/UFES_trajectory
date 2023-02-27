/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/diona/OneDrive/Documentos/Projetos Xilinx/PPLAB2.garage_door_ctrl/garage_door_tb.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1258338084_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_3524040528_1446275585_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 3592U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(34, ng0);
    t2 = (t0 + 2608U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3400);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(36, ng0);
    t2 = (t0 + 2608U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3400);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_3524040528_1446275585_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int64 t8;
    int64 t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(42, ng0);

LAB3:    t1 = (t0 + 5048);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 0U, 1, 0LL);
    t6 = (t0 + 2608U);
    t7 = *((char **)t6);
    t8 = *((int64 *)t7);
    t9 = (t8 / 2);
    t6 = (t0 + 5048);
    t10 = (t6 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)2;
    xsi_driver_subsequent_trans_delta(t6, 0U, 1, t9);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3524040528_1446275585_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;

LAB0:    t1 = (t0 + 4088U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 5112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 5176);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 5240);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(53, ng0);

LAB6:    t2 = (t0 + 4408);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t4 = (t0 + 4408);
    *((int *)t4) = 0;
    xsi_set_current_line(54, ng0);

LAB10:    t2 = (t0 + 4424);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    t4 = (t0 + 4424);
    *((int *)t4) = 0;
    xsi_set_current_line(55, ng0);

LAB14:    t2 = (t0 + 4440);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB8;
    else
        goto LAB10;

LAB11:    goto LAB9;

LAB12:    t4 = (t0 + 4440);
    *((int *)t4) = 0;
    xsi_set_current_line(56, ng0);

LAB18:    t2 = (t0 + 4456);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB13:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB12;
    else
        goto LAB14;

LAB15:    goto LAB13;

LAB16:    t4 = (t0 + 4456);
    *((int *)t4) = 0;
    xsi_set_current_line(57, ng0);

LAB22:    t2 = (t0 + 4472);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB17:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB16;
    else
        goto LAB18;

LAB19:    goto LAB17;

LAB20:    t4 = (t0 + 4472);
    *((int *)t4) = 0;
    xsi_set_current_line(58, ng0);

LAB26:    t2 = (t0 + 4488);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB21:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB20;
    else
        goto LAB22;

LAB23:    goto LAB21;

LAB24:    t4 = (t0 + 4488);
    *((int *)t4) = 0;
    xsi_set_current_line(59, ng0);

LAB30:    t2 = (t0 + 4504);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB31;
    goto LAB1;

LAB25:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB24;
    else
        goto LAB26;

LAB27:    goto LAB25;

LAB28:    t4 = (t0 + 4504);
    *((int *)t4) = 0;
    xsi_set_current_line(60, ng0);

LAB34:    t2 = (t0 + 4520);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB29:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB28;
    else
        goto LAB30;

LAB31:    goto LAB29;

LAB32:    t4 = (t0 + 4520);
    *((int *)t4) = 0;
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 5112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 5240);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(65, ng0);

LAB38:    t2 = (t0 + 4536);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB39;
    goto LAB1;

LAB33:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB32;
    else
        goto LAB34;

LAB35:    goto LAB33;

LAB36:    t4 = (t0 + 4536);
    *((int *)t4) = 0;
    xsi_set_current_line(66, ng0);
    t2 = (t0 + 5240);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(68, ng0);

LAB42:    t2 = (t0 + 4552);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB37:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB36;
    else
        goto LAB38;

LAB39:    goto LAB37;

LAB40:    t3 = (t0 + 4552);
    *((int *)t3) = 0;
    xsi_set_current_line(70, ng0);

LAB46:    t2 = (t0 + 4568);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB47;
    goto LAB1;

LAB41:    t3 = (t0 + 1992U);
    t4 = *((char **)t3);
    t7 = *((unsigned char *)t4);
    t8 = (t7 == (unsigned char)3);
    if (t8 == 1)
        goto LAB40;
    else
        goto LAB42;

LAB43:    goto LAB41;

LAB44:    t3 = (t0 + 4568);
    *((int *)t3) = 0;
    xsi_set_current_line(71, ng0);

LAB50:    t2 = (t0 + 4584);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB51;
    goto LAB1;

LAB45:    t3 = (t0 + 2312U);
    t4 = *((char **)t3);
    t7 = *((unsigned char *)t4);
    t8 = (t7 == (unsigned char)3);
    if (t8 == 1)
        goto LAB44;
    else
        goto LAB46;

LAB47:    goto LAB45;

LAB48:    t4 = (t0 + 4584);
    *((int *)t4) = 0;
    xsi_set_current_line(72, ng0);

LAB54:    t2 = (t0 + 4600);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB55;
    goto LAB1;

LAB49:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB48;
    else
        goto LAB50;

LAB51:    goto LAB49;

LAB52:    t4 = (t0 + 4600);
    *((int *)t4) = 0;
    xsi_set_current_line(73, ng0);

LAB58:    t2 = (t0 + 4616);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB53:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB52;
    else
        goto LAB54;

LAB55:    goto LAB53;

LAB56:    t4 = (t0 + 4616);
    *((int *)t4) = 0;
    xsi_set_current_line(74, ng0);

LAB62:    t2 = (t0 + 4632);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB63;
    goto LAB1;

LAB57:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB56;
    else
        goto LAB58;

LAB59:    goto LAB57;

LAB60:    t4 = (t0 + 4632);
    *((int *)t4) = 0;
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 5112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(77, ng0);
    t2 = (t0 + 5176);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(79, ng0);

LAB66:    t2 = (t0 + 4648);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB67;
    goto LAB1;

LAB61:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB60;
    else
        goto LAB62;

LAB63:    goto LAB61;

LAB64:    t3 = (t0 + 4648);
    *((int *)t3) = 0;
    xsi_set_current_line(80, ng0);

LAB70:    t2 = (t0 + 4664);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB71;
    goto LAB1;

LAB65:    t3 = (t0 + 2152U);
    t4 = *((char **)t3);
    t7 = *((unsigned char *)t4);
    t8 = (t7 == (unsigned char)3);
    if (t8 == 1)
        goto LAB64;
    else
        goto LAB66;

LAB67:    goto LAB65;

LAB68:    t4 = (t0 + 4664);
    *((int *)t4) = 0;
    xsi_set_current_line(81, ng0);

LAB74:    t2 = (t0 + 4680);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB75;
    goto LAB1;

LAB69:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB68;
    else
        goto LAB70;

LAB71:    goto LAB69;

LAB72:    t4 = (t0 + 4680);
    *((int *)t4) = 0;
    xsi_set_current_line(82, ng0);

LAB78:    t2 = (t0 + 4696);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB79;
    goto LAB1;

LAB73:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB72;
    else
        goto LAB74;

LAB75:    goto LAB73;

LAB76:    t4 = (t0 + 4696);
    *((int *)t4) = 0;
    xsi_set_current_line(83, ng0);

LAB82:    t2 = (t0 + 4712);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB83;
    goto LAB1;

LAB77:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB76;
    else
        goto LAB78;

LAB79:    goto LAB77;

LAB80:    t4 = (t0 + 4712);
    *((int *)t4) = 0;
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 5240);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(86, ng0);

LAB86:    t2 = (t0 + 4728);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB87;
    goto LAB1;

LAB81:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB80;
    else
        goto LAB82;

LAB83:    goto LAB81;

LAB84:    t4 = (t0 + 4728);
    *((int *)t4) = 0;
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 5240);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(89, ng0);

LAB90:    t2 = (t0 + 4744);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB91;
    goto LAB1;

LAB85:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB84;
    else
        goto LAB86;

LAB87:    goto LAB85;

LAB88:    t3 = (t0 + 4744);
    *((int *)t3) = 0;
    xsi_set_current_line(91, ng0);

LAB94:    t2 = (t0 + 4760);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB95;
    goto LAB1;

LAB89:    t3 = (t0 + 1992U);
    t4 = *((char **)t3);
    t7 = *((unsigned char *)t4);
    t8 = (t7 == (unsigned char)3);
    if (t8 == 1)
        goto LAB88;
    else
        goto LAB90;

LAB91:    goto LAB89;

LAB92:    t3 = (t0 + 4760);
    *((int *)t3) = 0;
    xsi_set_current_line(93, ng0);

LAB98:    t2 = (t0 + 4776);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB99;
    goto LAB1;

LAB93:    t3 = (t0 + 2312U);
    t4 = *((char **)t3);
    t7 = *((unsigned char *)t4);
    t8 = (t7 == (unsigned char)3);
    if (t8 == 1)
        goto LAB92;
    else
        goto LAB94;

LAB95:    goto LAB93;

LAB96:    t4 = (t0 + 4776);
    *((int *)t4) = 0;
    xsi_set_current_line(94, ng0);

LAB102:    t2 = (t0 + 4792);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB103;
    goto LAB1;

LAB97:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB96;
    else
        goto LAB98;

LAB99:    goto LAB97;

LAB100:    t4 = (t0 + 4792);
    *((int *)t4) = 0;
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 5112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(97, ng0);

LAB106:    t2 = (t0 + 4808);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB107;
    goto LAB1;

LAB101:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB100;
    else
        goto LAB102;

LAB103:    goto LAB101;

LAB104:    t4 = (t0 + 4808);
    *((int *)t4) = 0;
    xsi_set_current_line(98, ng0);

LAB110:    t2 = (t0 + 4824);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB111;
    goto LAB1;

LAB105:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB104;
    else
        goto LAB106;

LAB107:    goto LAB105;

LAB108:    t4 = (t0 + 4824);
    *((int *)t4) = 0;
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 5112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(102, ng0);

LAB114:    t2 = (t0 + 4840);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB115;
    goto LAB1;

LAB109:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB108;
    else
        goto LAB110;

LAB111:    goto LAB109;

LAB112:    t3 = (t0 + 4840);
    *((int *)t3) = 0;
    xsi_set_current_line(103, ng0);

LAB118:    t2 = (t0 + 4856);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB119;
    goto LAB1;

LAB113:    t3 = (t0 + 2152U);
    t4 = *((char **)t3);
    t7 = *((unsigned char *)t4);
    t8 = (t7 == (unsigned char)3);
    if (t8 == 1)
        goto LAB112;
    else
        goto LAB114;

LAB115:    goto LAB113;

LAB116:    t4 = (t0 + 4856);
    *((int *)t4) = 0;
    xsi_set_current_line(104, ng0);

LAB122:    t2 = (t0 + 4872);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB123;
    goto LAB1;

LAB117:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB116;
    else
        goto LAB118;

LAB119:    goto LAB117;

LAB120:    t4 = (t0 + 4872);
    *((int *)t4) = 0;
    xsi_set_current_line(105, ng0);

LAB126:    t2 = (t0 + 4888);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB127;
    goto LAB1;

LAB121:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB120;
    else
        goto LAB122;

LAB123:    goto LAB121;

LAB124:    t4 = (t0 + 4888);
    *((int *)t4) = 0;
    xsi_set_current_line(106, ng0);

LAB130:    t2 = (t0 + 4904);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB131;
    goto LAB1;

LAB125:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB124;
    else
        goto LAB126;

LAB127:    goto LAB125;

LAB128:    t4 = (t0 + 4904);
    *((int *)t4) = 0;
    xsi_set_current_line(110, ng0);
    if ((unsigned char)0 == 0)
        goto LAB132;

LAB133:    goto LAB2;

LAB129:    t3 = (t0 + 992U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t7 == 1)
        goto LAB128;
    else
        goto LAB130;

LAB131:    goto LAB129;

LAB132:    t2 = (t0 + 8349);
    xsi_report(t2, 20U, (unsigned char)3);
    goto LAB133;

}


extern void work_a_3524040528_1446275585_init()
{
	static char *pe[] = {(void *)work_a_3524040528_1446275585_p_0,(void *)work_a_3524040528_1446275585_p_1,(void *)work_a_3524040528_1446275585_p_2};
	xsi_register_didat("work_a_3524040528_1446275585", "isim/garage_door_tb_isim_beh.exe.sim/work/a_3524040528_1446275585.didat");
	xsi_register_executes(pe);
}
