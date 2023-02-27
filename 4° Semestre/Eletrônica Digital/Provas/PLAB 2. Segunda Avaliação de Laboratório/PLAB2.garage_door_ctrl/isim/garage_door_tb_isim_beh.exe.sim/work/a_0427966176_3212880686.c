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
static const char *ng0 = "C:/Users/diona/OneDrive/Documentos/Projetos Xilinx/PPLAB2.garage_door_ctrl/motor_ctrl.vhd";
extern char *IEEE_P_1242562249;

unsigned char ieee_p_1242562249_sub_1781507893_1035706684(char *, char *, char *, int );
char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );
char *ieee_p_1242562249_sub_1919437128_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_3125432260_1035706684(char *, char *, char *, int );


static void work_a_0427966176_3212880686_p_0(char *t0)
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

LAB0:    xsi_set_current_line(51, ng0);
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
LAB3:    t1 = (t0 + 5424);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(52, ng0);
    t1 = xsi_get_transient_memory(4U);
    memset(t1, 0, 4U);
    t5 = t1;
    memset(t5, (unsigned char)2, 4U);
    t6 = (t0 + 5568);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(53, ng0);
    t1 = xsi_get_transient_memory(2U);
    memset(t1, 0, 2U);
    t2 = t1;
    memset(t2, (unsigned char)2, 2U);
    t5 = (t0 + 5632);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 2U);
    xsi_driver_first_trans_fast(t5);
    goto LAB3;

LAB5:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2152U);
    t6 = *((char **)t2);
    t2 = (t0 + 5568);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t6, 4U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(56, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t1 = (t0 + 5632);
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

static void work_a_0427966176_3212880686_p_1(char *t0)
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

LAB0:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2312U);
    t3 = *((char **)t2);
    t2 = (t0 + 9340U);
    t4 = (t0 + 2768U);
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
LAB8:    t16 = (t0 + 5696);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t16);

LAB2:    t21 = (t0 + 5440);
    *((int *)t21) = 1;

LAB1:    return;
LAB3:    t11 = (t0 + 5696);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t11);
    goto LAB2;

LAB5:    t4 = (t0 + 1992U);
    t9 = *((char **)t4);
    t4 = (t0 + 9324U);
    t10 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t9, t4, 0);
    t1 = t10;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0427966176_3212880686_p_2(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    char *t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;

LAB0:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2312U);
    t3 = *((char **)t2);
    t2 = (t0 + 9340U);
    t4 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t3, t2, 0);
    if (t4 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t13 = (t0 + 5760);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t13);

LAB2:    t18 = (t0 + 5456);
    *((int *)t18) = 1;

LAB1:    return;
LAB3:    t8 = (t0 + 5760);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t8);
    goto LAB2;

LAB5:    t5 = (t0 + 1992U);
    t6 = *((char **)t5);
    t5 = (t0 + 9324U);
    t7 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t6, t5, 0);
    t1 = t7;
    goto LAB7;

LAB9:    goto LAB2;

}

static void work_a_0427966176_3212880686_p_3(char *t0)
{
    char t27[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    int t12;
    int t13;
    unsigned char t14;
    char *t15;
    char *t16;
    char *t17;
    int t18;
    int t19;
    unsigned char t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t28;

LAB0:    xsi_set_current_line(65, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t1 = (t0 + 5824);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(66, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 5888);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 4U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 9396);
    t7 = 1;
    if (2U == 2U)
        goto LAB5;

LAB6:    t7 = 0;

LAB7:    if (t7 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 9398);
    t7 = 1;
    if (2U == 2U)
        goto LAB23;

LAB24:    t7 = 0;

LAB25:    if (t7 != 0)
        goto LAB21;

LAB22:
LAB3:    t1 = (t0 + 5472);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(68, ng0);
    t6 = (t0 + 2312U);
    t9 = *((char **)t6);
    t6 = (t0 + 9340U);
    t10 = (t0 + 2768U);
    t11 = *((char **)t10);
    t12 = *((int *)t11);
    t13 = (t12 - 1);
    t14 = ieee_p_1242562249_sub_3125432260_1035706684(IEEE_P_1242562249, t9, t6, t13);
    if (t14 != 0)
        goto LAB11;

LAB13:
LAB12:    goto LAB3;

LAB5:    t8 = 0;

LAB8:    if (t8 < 2U)
        goto LAB9;
    else
        goto LAB7;

LAB9:    t4 = (t2 + t8);
    t5 = (t1 + t8);
    if (*((unsigned char *)t4) != *((unsigned char *)t5))
        goto LAB6;

LAB10:    t8 = (t8 + 1);
    goto LAB8;

LAB11:    xsi_set_current_line(69, ng0);
    t10 = (t0 + 1992U);
    t15 = *((char **)t10);
    t10 = (t0 + 9324U);
    t16 = (t0 + 2888U);
    t17 = *((char **)t16);
    t18 = *((int *)t17);
    t19 = (t18 - 1);
    t20 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t15, t10, t19);
    if (t20 != 0)
        goto LAB14;

LAB16:    xsi_set_current_line(73, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 9324U);
    t3 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t27, t2, t1, 1);
    t4 = (t27 + 12U);
    t8 = *((unsigned int *)t4);
    t28 = (1U * t8);
    t7 = (4U != t28);
    if (t7 == 1)
        goto LAB19;

LAB20:    t5 = (t0 + 5888);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 4U);
    xsi_driver_first_trans_fast(t5);

LAB15:    goto LAB12;

LAB14:    xsi_set_current_line(70, ng0);
    t16 = xsi_get_transient_memory(4U);
    memset(t16, 0, 4U);
    t21 = t16;
    memset(t21, (unsigned char)2, 4U);
    t22 = (t0 + 5888);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t16, 4U);
    xsi_driver_first_trans_fast(t22);
    xsi_set_current_line(71, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t1 = (t0 + 9340U);
    t3 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t27, t2, t1, 1);
    t4 = (t27 + 12U);
    t8 = *((unsigned int *)t4);
    t28 = (1U * t8);
    t7 = (2U != t28);
    if (t7 == 1)
        goto LAB17;

LAB18:    t5 = (t0 + 5824);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 2U);
    xsi_driver_first_trans_fast(t5);
    goto LAB15;

LAB17:    xsi_size_not_matching(2U, t28, 0);
    goto LAB18;

LAB19:    xsi_size_not_matching(4U, t28, 0);
    goto LAB20;

LAB21:    xsi_set_current_line(77, ng0);
    t6 = (t0 + 2312U);
    t9 = *((char **)t6);
    t6 = (t0 + 9340U);
    t14 = ieee_p_1242562249_sub_3125432260_1035706684(IEEE_P_1242562249, t9, t6, 0);
    if (t14 != 0)
        goto LAB29;

LAB31:
LAB30:    goto LAB3;

LAB23:    t8 = 0;

LAB26:    if (t8 < 2U)
        goto LAB27;
    else
        goto LAB25;

LAB27:    t4 = (t2 + t8);
    t5 = (t1 + t8);
    if (*((unsigned char *)t4) != *((unsigned char *)t5))
        goto LAB24;

LAB28:    t8 = (t8 + 1);
    goto LAB26;

LAB29:    xsi_set_current_line(78, ng0);
    t10 = (t0 + 1992U);
    t11 = *((char **)t10);
    t10 = (t0 + 9324U);
    t15 = (t0 + 2888U);
    t16 = *((char **)t15);
    t12 = *((int *)t16);
    t13 = (t12 - 1);
    t20 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t11, t10, t13);
    if (t20 != 0)
        goto LAB32;

LAB34:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 9324U);
    t3 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t27, t2, t1, 1);
    t4 = (t27 + 12U);
    t8 = *((unsigned int *)t4);
    t28 = (1U * t8);
    t7 = (4U != t28);
    if (t7 == 1)
        goto LAB37;

LAB38:    t5 = (t0 + 5888);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 4U);
    xsi_driver_first_trans_fast(t5);

LAB33:    goto LAB30;

LAB32:    xsi_set_current_line(79, ng0);
    t15 = xsi_get_transient_memory(4U);
    memset(t15, 0, 4U);
    t17 = t15;
    memset(t17, (unsigned char)2, 4U);
    t21 = (t0 + 5888);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t15, 4U);
    xsi_driver_first_trans_fast(t21);
    xsi_set_current_line(80, ng0);
    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t1 = (t0 + 9340U);
    t3 = ieee_p_1242562249_sub_1919437128_1035706684(IEEE_P_1242562249, t27, t2, t1, 1);
    t4 = (t27 + 12U);
    t8 = *((unsigned int *)t4);
    t28 = (1U * t8);
    t7 = (2U != t28);
    if (t7 == 1)
        goto LAB35;

LAB36:    t5 = (t0 + 5824);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 2U);
    xsi_driver_first_trans_fast(t5);
    goto LAB33;

LAB35:    xsi_size_not_matching(2U, t28, 0);
    goto LAB36;

LAB37:    xsi_size_not_matching(4U, t28, 0);
    goto LAB38;

}

static void work_a_0427966176_3212880686_p_4(char *t0)
{
    char t5[16];
    char t7[16];
    char *t1;
    char *t3;
    char *t4;
    char *t6;
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    xsi_set_current_line(87, ng0);

LAB3:    t1 = (t0 + 9400);
    t3 = (t0 + 2312U);
    t4 = *((char **)t3);
    t6 = ((IEEE_P_1242562249) + 3000);
    t8 = (t7 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 0;
    t9 = (t8 + 4U);
    *((int *)t9) = 1;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t11 = (t11 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t11;
    t9 = (t0 + 9340U);
    t3 = xsi_base_array_concat(t3, t5, t6, (char)97, t1, t7, (char)97, t4, t9, (char)101);
    t12 = (t0 + 5952);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t3, 4U);
    xsi_driver_first_trans_fast_port(t12);

LAB2:    t17 = (t0 + 5488);
    *((int *)t17) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0427966176_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0427966176_3212880686_p_0,(void *)work_a_0427966176_3212880686_p_1,(void *)work_a_0427966176_3212880686_p_2,(void *)work_a_0427966176_3212880686_p_3,(void *)work_a_0427966176_3212880686_p_4};
	xsi_register_didat("work_a_0427966176_3212880686", "isim/garage_door_tb_isim_beh.exe.sim/work/a_0427966176_3212880686.didat");
	xsi_register_executes(pe);
}
