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
static const char *ng0 = "C:/Users/diona/OneDrive/Documentos/Projetos Xilinx/LAB91/seq_mult_v1.vhd";
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1547198987_1035706684(char *, char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_1919437128_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_3454299738_1035706684(char *, char *, char *, char *, char *);


static void work_a_2508368337_3313388377_p_0(char *t0)
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
    unsigned char t10;
    unsigned char t11;
    unsigned char t12;
    char *t13;

LAB0:    xsi_set_current_line(27, ng0);
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
LAB3:    t1 = (t0 + 5928);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(28, ng0);
    t1 = (t0 + 6040);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(29, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t2 = t1;
    memset(t2, (unsigned char)2, 8U);
    t5 = (t0 + 6104);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(30, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t2 = t1;
    memset(t2, (unsigned char)2, 16U);
    t5 = (t0 + 6168);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 16U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(31, ng0);
    t1 = xsi_get_transient_memory(4U);
    memset(t1, 0, 4U);
    t2 = t1;
    memset(t2, (unsigned char)2, 4U);
    t5 = (t0 + 6232);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 4U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(32, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t2 = t1;
    memset(t2, (unsigned char)2, 16U);
    t5 = (t0 + 6296);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 16U);
    xsi_driver_first_trans_fast(t5);
    goto LAB3;

LAB5:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 2312U);
    t6 = *((char **)t2);
    t12 = *((unsigned char *)t6);
    t2 = (t0 + 6040);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t13 = *((char **)t9);
    *((unsigned char *)t13) = t12;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 6104);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(36, ng0);
    t1 = (t0 + 2952U);
    t2 = *((char **)t1);
    t1 = (t0 + 6168);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 16U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(37, ng0);
    t1 = (t0 + 3272U);
    t2 = *((char **)t1);
    t1 = (t0 + 6232);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(38, ng0);
    t1 = (t0 + 3592U);
    t2 = *((char **)t1);
    t1 = (t0 + 6296);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 16U);
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB7:    t2 = (t0 + 1032U);
    t5 = *((char **)t2);
    t10 = *((unsigned char *)t5);
    t11 = (t10 == (unsigned char)3);
    t3 = t11;
    goto LAB9;

}

static void work_a_2508368337_3313388377_p_1(char *t0)
{
    char t13[16];
    char t14[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    char *t11;
    char *t12;
    int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    int t22;
    int t23;
    unsigned int t24;
    int t25;
    static char *nl0[] = {&&LAB3, &&LAB4, &&LAB5};

LAB0:    xsi_set_current_line(45, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t1 = (t0 + 6360);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 8U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(46, ng0);
    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t1 = (t0 + 6424);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 16U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(47, ng0);
    t1 = (t0 + 3112U);
    t2 = *((char **)t1);
    t1 = (t0 + 6488);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 4U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(48, ng0);
    t1 = (t0 + 3432U);
    t2 = *((char **)t1);
    t1 = (t0 + 6552);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 16U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(49, ng0);
    t1 = (t0 + 6616);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(50, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t7 = *((unsigned char *)t2);
    t1 = (char *)((nl0) + t7);
    goto **((char **)t1);

LAB2:    t1 = (t0 + 5944);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(52, ng0);
    t3 = (t0 + 1352U);
    t4 = *((char **)t3);
    t8 = *((unsigned char *)t4);
    t9 = (t8 == (unsigned char)3);
    if (t9 != 0)
        goto LAB6;

LAB8:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 6680);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB7:    xsi_set_current_line(65, ng0);
    t1 = (t0 + 6616);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB2;

LAB4:    xsi_set_current_line(67, ng0);
    t1 = (t0 + 3432U);
    t2 = *((char **)t1);
    t1 = (t0 + 10364U);
    t3 = (t0 + 2792U);
    t4 = *((char **)t3);
    t3 = (t0 + 10332U);
    t5 = ieee_p_1242562249_sub_1547198987_1035706684(IEEE_P_1242562249, t13, t2, t1, t4, t3);
    t6 = (t13 + 12U);
    t16 = *((unsigned int *)t6);
    t20 = (1U * t16);
    t7 = (16U != t20);
    if (t7 == 1)
        goto LAB14;

LAB15:    t10 = (t0 + 6552);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t17 = (t12 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t5, 16U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(68, ng0);
    t1 = (t0 + 6680);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB5:    xsi_set_current_line(70, ng0);
    t1 = (t0 + 3112U);
    t2 = *((char **)t1);
    t1 = (t0 + 10348U);
    t3 = ieee_p_1242562249_sub_1919437128_1035706684(IEEE_P_1242562249, t13, t2, t1, 1);
    t4 = (t13 + 12U);
    t16 = *((unsigned int *)t4);
    t20 = (1U * t16);
    t7 = (4U != t20);
    if (t7 == 1)
        goto LAB16;

LAB17:    t5 = (t0 + 6488);
    t6 = (t5 + 56U);
    t10 = *((char **)t6);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 4U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(71, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t1 = (t0 + 3888U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t22 = (t15 - 1);
    t16 = (7 - t22);
    t20 = (t16 * 1U);
    t21 = (0 + t20);
    t1 = (t2 + t21);
    t5 = ((IEEE_P_1242562249) + 3000);
    t6 = (t14 + 0U);
    t10 = (t6 + 0U);
    *((int *)t10) = 7;
    t10 = (t6 + 4U);
    *((int *)t10) = 1;
    t10 = (t6 + 8U);
    *((int *)t10) = -1;
    t23 = (1 - 7);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t10 = (t6 + 12U);
    *((unsigned int *)t10) = t24;
    t4 = xsi_base_array_concat(t4, t13, t5, (char)99, (unsigned char)2, (char)97, t1, t14, (char)101);
    t24 = (1U + 7U);
    t7 = (8U != t24);
    if (t7 == 1)
        goto LAB18;

LAB19:    t10 = (t0 + 6360);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t17 = (t12 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t4, 8U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(72, ng0);
    t1 = (t0 + 2792U);
    t2 = *((char **)t1);
    t1 = (t0 + 3888U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t22 = (2 * t15);
    t23 = (t22 - 2);
    t16 = (15 - t23);
    t20 = (t16 * 1U);
    t21 = (0 + t20);
    t1 = (t2 + t21);
    t5 = ((IEEE_P_1242562249) + 3000);
    t6 = (t14 + 0U);
    t10 = (t6 + 0U);
    *((int *)t10) = 14;
    t10 = (t6 + 4U);
    *((int *)t10) = 0;
    t10 = (t6 + 8U);
    *((int *)t10) = -1;
    t25 = (0 - 14);
    t24 = (t25 * -1);
    t24 = (t24 + 1);
    t10 = (t6 + 12U);
    *((unsigned int *)t10) = t24;
    t4 = xsi_base_array_concat(t4, t13, t5, (char)97, t1, t14, (char)99, (unsigned char)2, (char)101);
    t24 = (15U + 1U);
    t7 = (16U != t24);
    if (t7 == 1)
        goto LAB20;

LAB21:    t10 = (t0 + 6424);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t17 = (t12 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t4, 16U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 3272U);
    t2 = *((char **)t1);
    t1 = (t0 + 10348U);
    t3 = (t0 + 10518);
    t5 = (t13 + 0U);
    t6 = (t5 + 0U);
    *((int *)t6) = 0;
    t6 = (t5 + 4U);
    *((int *)t6) = 3;
    t6 = (t5 + 8U);
    *((int *)t6) = 1;
    t15 = (3 - 0);
    t16 = (t15 * 1);
    t16 = (t16 + 1);
    t6 = (t5 + 12U);
    *((unsigned int *)t6) = t16;
    t7 = ieee_p_1242562249_sub_3454299738_1035706684(IEEE_P_1242562249, t2, t1, t3, t13);
    if (t7 != 0)
        goto LAB22;

LAB24:    xsi_set_current_line(80, ng0);
    t1 = (t0 + 6680);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB23:    goto LAB2;

LAB6:    xsi_set_current_line(53, ng0);
    t3 = (t0 + 1672U);
    t5 = *((char **)t3);
    t3 = (t0 + 6360);
    t6 = (t3 + 56U);
    t10 = *((char **)t6);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t5, 8U);
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(54, ng0);
    t1 = (t0 + 10510);
    t3 = (t0 + 1512U);
    t4 = *((char **)t3);
    t5 = ((IEEE_P_1242562249) + 3000);
    t6 = (t14 + 0U);
    t10 = (t6 + 0U);
    *((int *)t10) = 0;
    t10 = (t6 + 4U);
    *((int *)t10) = 7;
    t10 = (t6 + 8U);
    *((int *)t10) = 1;
    t15 = (7 - 0);
    t16 = (t15 * 1);
    t16 = (t16 + 1);
    t10 = (t6 + 12U);
    *((unsigned int *)t10) = t16;
    t10 = (t0 + 10252U);
    t3 = xsi_base_array_concat(t3, t13, t5, (char)97, t1, t14, (char)97, t4, t10, (char)101);
    t16 = (8U + 8U);
    t7 = (16U != t16);
    if (t7 == 1)
        goto LAB9;

LAB10:    t11 = (t0 + 6424);
    t12 = (t11 + 56U);
    t17 = *((char **)t12);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t3, 16U);
    xsi_driver_first_trans_fast(t11);
    xsi_set_current_line(55, ng0);
    t1 = (t0 + 4128U);
    t2 = *((char **)t1);
    t1 = (t0 + 6488);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 4U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(56, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t2 = t1;
    memset(t2, (unsigned char)2, 16U);
    t3 = (t0 + 6552);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t10 = *((char **)t6);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(57, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t15 = (0 - 7);
    t16 = (t15 * -1);
    t20 = (1U * t16);
    t21 = (0 + t20);
    t1 = (t2 + t21);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(60, ng0);
    t1 = (t0 + 6680);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB12:    goto LAB7;

LAB9:    xsi_size_not_matching(16U, t16, 0);
    goto LAB10;

LAB11:    xsi_set_current_line(58, ng0);
    t3 = (t0 + 6680);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t10 = *((char **)t6);
    *((unsigned char *)t10) = (unsigned char)1;
    xsi_driver_first_trans_fast(t3);
    goto LAB12;

LAB14:    xsi_size_not_matching(16U, t20, 0);
    goto LAB15;

LAB16:    xsi_size_not_matching(4U, t20, 0);
    goto LAB17;

LAB18:    xsi_size_not_matching(8U, t24, 0);
    goto LAB19;

LAB20:    xsi_size_not_matching(16U, t24, 0);
    goto LAB21;

LAB22:    xsi_set_current_line(74, ng0);
    t6 = (t0 + 2632U);
    t10 = *((char **)t6);
    t22 = (0 - 7);
    t16 = (t22 * -1);
    t20 = (1U * t16);
    t21 = (0 + t20);
    t6 = (t10 + t21);
    t8 = *((unsigned char *)t6);
    t9 = (t8 == (unsigned char)3);
    if (t9 != 0)
        goto LAB25;

LAB27:    xsi_set_current_line(77, ng0);
    t1 = (t0 + 6680);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB26:    goto LAB23;

LAB25:    xsi_set_current_line(75, ng0);
    t11 = (t0 + 6680);
    t12 = (t11 + 56U);
    t17 = *((char **)t12);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)1;
    xsi_driver_first_trans_fast(t11);
    goto LAB26;

}

static void work_a_2508368337_3313388377_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(84, ng0);

LAB3:    t1 = (t0 + 3432U);
    t2 = *((char **)t1);
    t1 = (t0 + 6744);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 16U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 5960);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_2508368337_3313388377_init()
{
	static char *pe[] = {(void *)work_a_2508368337_3313388377_p_0,(void *)work_a_2508368337_3313388377_p_1,(void *)work_a_2508368337_3313388377_p_2};
	xsi_register_didat("work_a_2508368337_3313388377", "isim/mult_seq_tb_isim_beh.exe.sim/work/a_2508368337_3313388377.didat");
	xsi_register_executes(pe);
}
