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
static const char *ng0 = "C:/Users/diona/OneDrive/Documentos/Projetos Xilinx/PPLAB2.garage_door_ctrl/timer.vhd";
extern char *IEEE_P_1242562249;

unsigned char ieee_p_1242562249_sub_1781507893_1035706684(char *, char *, char *, int );
char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );


static void work_a_0141943142_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned char t12;

LAB0:    xsi_set_current_line(53, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 992U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 4608);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(54, ng0);
    t1 = xsi_get_transient_memory(4U);
    memset(t1, 0, 4U);
    t5 = t1;
    memset(t5, (unsigned char)2, 4U);
    t6 = (t0 + 4720);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(55, ng0);
    t1 = xsi_get_transient_memory(2U);
    memset(t1, 0, 2U);
    t2 = t1;
    memset(t2, (unsigned char)2, 2U);
    t5 = (t0 + 4784);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_fast(t5);
    goto LAB3;

LAB5:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1832U);
    t6 = *((char **)t2);
    t2 = (t0 + 4720);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t6, 4U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(58, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 4784);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 2U);
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB7:    t2 = (t0 + 1032U);
    t5 = *((char **)t2);
    t11 = *((unsigned char *)t5);
    t12 = (t11 == (unsigned char)3);
    t3 = t12;
    goto LAB9;

}

static void work_a_0141943142_3212880686_p_1(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    int t7;
    unsigned char t8;
    char *t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t2 = (t0 + 7860U);
    t4 = (t0 + 2448U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t7 = (t6 - 1);
    t8 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t3, t2, t7);
    if (t8 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t16 = (t0 + 4848);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t16);

LAB2:    t21 = (t0 + 4624);
    *((int *)t21) = 1;

LAB1:    return;
LAB3:    t11 = (t0 + 4848);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t11);
    goto LAB2;

LAB5:    t4 = (t0 + 1672U);
    t9 = *((char **)t4);
    t4 = (t0 + 7844U);
    t10 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t9, t4, 0);
    t1 = t10;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0141943142_3212880686_p_2(char *t0)
{
    char t15[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    int t11;
    int t12;
    char *t13;
    char *t14;
    unsigned int t16;
    unsigned int t17;

LAB0:    xsi_set_current_line(65, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 4912);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(66, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 4976);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 4U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t7 = *((unsigned char *)t2);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(71, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7844U);
    t3 = (t0 + 2568U);
    t4 = *((char **)t3);
    t11 = *((int *)t4);
    t12 = (t11 - 1);
    t7 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t2, t1, t12);
    if (t7 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7844U);
    t3 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t15, t2, t1, 1);
    t4 = (t15 + 12U);
    t16 = *((unsigned int *)t4);
    t17 = (1U * t16);
    t7 = (4U != t17);
    if (t7 == 1)
        goto LAB13;

LAB14:    t5 = (t0 + 4976);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    memcpy(t13, t3, 4U);
    xsi_driver_first_trans_fast(t5);

LAB6:
LAB3:    t1 = (t0 + 4640);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(68, ng0);
    t1 = xsi_get_transient_memory(4U);
    memset(t1, 0, 4U);
    t3 = t1;
    memset(t3, (unsigned char)2, 4U);
    t4 = (t0 + 4976);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t9 = (t6 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(69, ng0);
    t1 = xsi_get_transient_memory(2U);
    memset(t1, 0, 2U);
    t2 = t1;
    memset(t2, (unsigned char)2, 2U);
    t3 = (t0 + 4912);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_fast(t3);
    goto LAB3;

LAB5:    xsi_set_current_line(72, ng0);
    t3 = xsi_get_transient_memory(4U);
    memset(t3, 0, 4U);
    t5 = t3;
    memset(t5, (unsigned char)2, 4U);
    t6 = (t0 + 4976);
    t9 = (t6 + 56U);
    t10 = *((char **)t9);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t3, 4U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 7860U);
    t3 = (t0 + 2448U);
    t4 = *((char **)t3);
    t11 = *((int *)t4);
    t12 = (t11 - 1);
    t7 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t2, t1, t12);
    if (t7 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(76, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 7860U);
    t3 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t15, t2, t1, 1);
    t4 = (t15 + 12U);
    t16 = *((unsigned int *)t4);
    t17 = (1U * t16);
    t7 = (2U != t17);
    if (t7 == 1)
        goto LAB11;

LAB12:    t5 = (t0 + 4912);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    memcpy(t13, t3, 2U);
    xsi_driver_first_trans_fast(t5);

LAB9:    goto LAB6;

LAB8:    xsi_set_current_line(74, ng0);
    t3 = xsi_get_transient_memory(2U);
    memset(t3, 0, 2U);
    t5 = t3;
    memset(t5, (unsigned char)2, 2U);
    t6 = (t0 + 4912);
    t9 = (t6 + 56U);
    t10 = *((char **)t9);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t3, 2U);
    xsi_driver_first_trans_fast(t6);
    goto LAB9;

LAB11:    xsi_size_not_matching(2U, t17, 0);
    goto LAB12;

LAB13:    xsi_size_not_matching(4U, t17, 0);
    goto LAB14;

}


extern void work_a_0141943142_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0141943142_3212880686_p_0,(void *)work_a_0141943142_3212880686_p_1,(void *)work_a_0141943142_3212880686_p_2};
	xsi_register_didat("work_a_0141943142_3212880686", "isim/garage_door_tb_isim_beh.exe.sim/work/a_0141943142_3212880686.didat");
	xsi_register_executes(pe);
}
