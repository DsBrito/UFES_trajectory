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
static const char *ng0 = "C:/Users/diona/OneDrive/Documentos/Projetos Xilinx/lab5/IncrementadorGray/g_inc_tb.vhd";
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );


static void work_a_1932734737_4222206379_p_0(char *t0)
{
    char t12[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    int t10;
    int64 t11;
    char *t13;
    int t14;

LAB0:    t1 = (t0 + 2352U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(19, ng0);
    t2 = (t0 + 4648);
    t4 = (t0 + 2736);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(20, ng0);
    t2 = (t0 + 4652);
    *((int *)t2) = 1;
    t3 = (t0 + 4656);
    *((int *)t3) = 16;
    t9 = 1;
    t10 = 16;

LAB4:    if (t9 <= t10)
        goto LAB5;

LAB7:    xsi_set_current_line(30, ng0);
    if ((unsigned char)0 == 0)
        goto LAB13;

LAB14:    goto LAB2;

LAB5:    xsi_set_current_line(21, ng0);
    t11 = (200 * 1000LL);
    t4 = (t0 + 2160);
    xsi_process_wait(t4, t11);

LAB10:    *((char **)t1) = &&LAB11;

LAB1:    return;
LAB6:    t2 = (t0 + 4652);
    t9 = *((int *)t2);
    t3 = (t0 + 4656);
    t10 = *((int *)t3);
    if (t9 == t10)
        goto LAB7;

LAB12:    t14 = (t9 + 1);
    t9 = t14;
    t4 = (t0 + 4652);
    *((int *)t4) = t9;
    goto LAB4;

LAB8:    xsi_set_current_line(22, ng0);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t2 = (t0 + 4600U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t12, t3, t2, 1);
    t5 = (t0 + 2736);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t13 = *((char **)t8);
    memcpy(t13, t4, 4U);
    xsi_driver_first_trans_fast(t5);
    goto LAB6;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB13:    t2 = (t0 + 4660);
    xsi_report(t2, 20U, (unsigned char)3);
    goto LAB14;

}


extern void work_a_1932734737_4222206379_init()
{
	static char *pe[] = {(void *)work_a_1932734737_4222206379_p_0};
	xsi_register_didat("work_a_1932734737_4222206379", "isim/g_inc_tb_isim_beh.exe.sim/work/a_1932734737_4222206379.didat");
	xsi_register_executes(pe);
}
