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
static const char *ng0 = "C:/Users/diona/OneDrive/Documentos/Projetos Xilinx/lab3/chave2por2/chave2por2.vhd";
extern char *IEEE_P_2592010699;



static void work_a_2285039969_0866146828_p_0(char *t0)
{
    char t25[16];
    char *t1;
    char *t2;
    char *t3;
    int t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned char t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned char t24;
    unsigned int t26;
    unsigned char t27;

LAB0:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t1 = (t0 + 4748);
    t4 = xsi_mem_cmp(t1, t2, 2U);
    if (t4 == 1)
        goto LAB3;

LAB7:    t5 = (t0 + 4750);
    t7 = xsi_mem_cmp(t5, t2, 2U);
    if (t7 == 1)
        goto LAB4;

LAB8:    t8 = (t0 + 4752);
    t10 = xsi_mem_cmp(t8, t2, 2U);
    if (t10 == 1)
        goto LAB5;

LAB9:
LAB6:    xsi_set_current_line(92, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t4 = (0 - 1);
    t17 = (t4 * -1);
    t18 = (1U * t17);
    t19 = (0 + t18);
    t1 = (t2 + t19);
    t20 = *((unsigned char *)t1);
    t3 = (t0 + 1032U);
    t5 = *((char **)t3);
    t7 = (1 - 1);
    t21 = (t7 * -1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t3 = (t5 + t23);
    t24 = *((unsigned char *)t3);
    t8 = ((IEEE_P_2592010699) + 4024);
    t6 = xsi_base_array_concat(t6, t25, t8, (char)99, t20, (char)99, t24, (char)101);
    t26 = (1U + 1U);
    t27 = (2U != t26);
    if (t27 == 1)
        goto LAB15;

LAB16:    t9 = (t0 + 2912);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t6, 2U);
    xsi_driver_first_trans_fast_port(t9);

LAB2:    t1 = (t0 + 2832);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(89, ng0);
    t11 = (t0 + 1032U);
    t12 = *((char **)t11);
    t11 = (t0 + 2912);
    t13 = (t11 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t12, 2U);
    xsi_driver_first_trans_fast_port(t11);
    goto LAB2;

LAB4:    xsi_set_current_line(90, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t4 = (0 - 1);
    t17 = (t4 * -1);
    t18 = (1U * t17);
    t19 = (0 + t18);
    t1 = (t2 + t19);
    t20 = *((unsigned char *)t1);
    t3 = (t0 + 1032U);
    t5 = *((char **)t3);
    t7 = (1 - 1);
    t21 = (t7 * -1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t3 = (t5 + t23);
    t24 = *((unsigned char *)t3);
    t8 = ((IEEE_P_2592010699) + 4024);
    t6 = xsi_base_array_concat(t6, t25, t8, (char)99, t20, (char)99, t24, (char)101);
    t26 = (1U + 1U);
    t27 = (2U != t26);
    if (t27 == 1)
        goto LAB11;

LAB12:    t9 = (t0 + 2912);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t6, 2U);
    xsi_driver_first_trans_fast_port(t9);
    goto LAB2;

LAB5:    xsi_set_current_line(91, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t4 = (0 - 1);
    t17 = (t4 * -1);
    t18 = (1U * t17);
    t19 = (0 + t18);
    t1 = (t2 + t19);
    t20 = *((unsigned char *)t1);
    t3 = (t0 + 1032U);
    t5 = *((char **)t3);
    t7 = (0 - 1);
    t21 = (t7 * -1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t3 = (t5 + t23);
    t24 = *((unsigned char *)t3);
    t8 = ((IEEE_P_2592010699) + 4024);
    t6 = xsi_base_array_concat(t6, t25, t8, (char)99, t20, (char)99, t24, (char)101);
    t26 = (1U + 1U);
    t27 = (2U != t26);
    if (t27 == 1)
        goto LAB13;

LAB14:    t9 = (t0 + 2912);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t6, 2U);
    xsi_driver_first_trans_fast_port(t9);
    goto LAB2;

LAB10:;
LAB11:    xsi_size_not_matching(2U, t26, 0);
    goto LAB12;

LAB13:    xsi_size_not_matching(2U, t26, 0);
    goto LAB14;

LAB15:    xsi_size_not_matching(2U, t26, 0);
    goto LAB16;

}


extern void work_a_2285039969_0866146828_init()
{
	static char *pe[] = {(void *)work_a_2285039969_0866146828_p_0};
	xsi_register_didat("work_a_2285039969_0866146828", "isim/chave2por2_tb_isim_beh.exe.sim/work/a_2285039969_0866146828.didat");
	xsi_register_executes(pe);
}
