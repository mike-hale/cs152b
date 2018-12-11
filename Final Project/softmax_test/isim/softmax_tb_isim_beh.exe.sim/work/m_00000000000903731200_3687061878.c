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
static const char *ng0 = "C:/Users/CS152B/Desktop/cs152b/Final Project/fixed_point_calc/verilog_source_code/fmult.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {1U, 0U};



static void Cont_42_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 3280U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2360);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4472);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 2147483647U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 30);
    t18 = (t0 + 4344);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_44_1(char *t0)
{
    char t4[8];
    char t14[8];
    char t22[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;

LAB0:    t1 = (t0 + 3528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 31);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 31);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1320U);
    t13 = *((char **)t12);
    memset(t14, 0, 8);
    t12 = (t14 + 4);
    t15 = (t13 + 4);
    t16 = *((unsigned int *)t13);
    t17 = (t16 >> 31);
    t18 = (t17 & 1);
    *((unsigned int *)t14) = t18;
    t19 = *((unsigned int *)t15);
    t20 = (t19 >> 31);
    t21 = (t20 & 1);
    *((unsigned int *)t12) = t21;
    t23 = *((unsigned int *)t4);
    t24 = *((unsigned int *)t14);
    t25 = (t23 ^ t24);
    *((unsigned int *)t22) = t25;
    t26 = (t4 + 4);
    t27 = (t14 + 4);
    t28 = (t22 + 4);
    t29 = *((unsigned int *)t26);
    t30 = *((unsigned int *)t27);
    t31 = (t29 | t30);
    *((unsigned int *)t28) = t31;
    t32 = *((unsigned int *)t28);
    t33 = (t32 != 0);
    if (t33 == 1)
        goto LAB4;

LAB5:
LAB6:    t36 = (t0 + 4536);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    t39 = (t38 + 56U);
    t40 = *((char **)t39);
    memset(t40, 0, 8);
    t41 = 1U;
    t42 = t41;
    t43 = (t22 + 4);
    t44 = *((unsigned int *)t22);
    t41 = (t41 & t44);
    t45 = *((unsigned int *)t43);
    t42 = (t42 & t45);
    t46 = (t40 + 4);
    t47 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t47 | t41);
    t48 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t48 | t42);
    xsi_driver_vfirst_trans(t36, 31, 31);
    t49 = (t0 + 4360);
    *((int *)t49) = 1;

LAB1:    return;
LAB4:    t34 = *((unsigned int *)t22);
    t35 = *((unsigned int *)t28);
    *((unsigned int *)t22) = (t34 | t35);
    goto LAB6;

}

static void Always_46_2(char *t0)
{
    char t4[16];
    char t7[16];
    char t9[16];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t8;

LAB0:    t1 = (t0 + 3776U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 4376);
    *((int *)t2) = 1;
    t3 = (t0 + 3808);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(46, ng0);

LAB5:    xsi_set_current_line(47, ng0);
    t5 = (t0 + 1320U);
    t6 = *((char **)t5);
    xsi_vlog_get_part_select_value(t4, 64, t6, 30, 0);
    t5 = (t0 + 1480U);
    t8 = *((char **)t5);
    xsi_vlog_get_part_select_value(t7, 64, t8, 30, 0);
    xsi_vlog_unsigned_multiply(t9, 64, t4, 64, t7, 64);
    t5 = (t0 + 2200);
    xsi_vlogvar_wait_assign_value(t5, t9, 0, 0, 64, 0LL);
    xsi_set_current_line(49, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2040);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB2;

}

static void Always_53_3(char *t0)
{
    char t4[8];
    char t25[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t26;
    char *t27;
    char *t28;

LAB0:    t1 = (t0 + 4024U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(53, ng0);
    t2 = (t0 + 4392);
    *((int *)t2) = 1;
    t3 = (t0 + 4056);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(53, ng0);

LAB5:    xsi_set_current_line(55, ng0);
    t5 = (t0 + 2200);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t4, 0, 8);
    t8 = (t4 + 4);
    t9 = (t7 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 15);
    *((unsigned int *)t4) = t11;
    t12 = *((unsigned int *)t9);
    t13 = (t12 >> 15);
    *((unsigned int *)t8) = t13;
    t14 = (t7 + 8);
    t15 = (t7 + 12);
    t16 = *((unsigned int *)t14);
    t17 = (t16 << 17);
    t18 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t18 | t17);
    t19 = *((unsigned int *)t15);
    t20 = (t19 << 17);
    t21 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t21 | t20);
    t22 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t22 & 2147483647U);
    t23 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t23 & 2147483647U);
    t24 = (t0 + 2360);
    xsi_vlogvar_wait_assign_value(t24, t4, 0, 0, 31, 0LL);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 2200);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t4, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 8);
    t8 = (t5 + 12);
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 14);
    *((unsigned int *)t4) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 14);
    *((unsigned int *)t6) = t13;
    t16 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t16 & 131071U);
    t17 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t17 & 131071U);
    t9 = ((char*)((ng2)));
    memset(t25, 0, 8);
    t14 = (t4 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB7;

LAB6:    t15 = (t9 + 4);
    if (*((unsigned int *)t15) != 0)
        goto LAB7;

LAB10:    if (*((unsigned int *)t4) > *((unsigned int *)t9))
        goto LAB8;

LAB9:    t26 = (t25 + 4);
    t18 = *((unsigned int *)t26);
    t19 = (~(t18));
    t20 = *((unsigned int *)t25);
    t21 = (t20 & t19);
    t22 = (t21 != 0);
    if (t22 > 0)
        goto LAB11;

LAB12:
LAB13:    goto LAB2;

LAB7:    t24 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB9;

LAB8:    *((unsigned int *)t25) = 1;
    goto LAB9;

LAB11:    xsi_set_current_line(58, ng0);
    t27 = ((char*)((ng3)));
    t28 = (t0 + 2040);
    xsi_vlogvar_wait_assign_value(t28, t27, 0, 0, 1, 0LL);
    goto LAB13;

}


extern void work_m_00000000000903731200_3687061878_init()
{
	static char *pe[] = {(void *)Cont_42_0,(void *)Cont_44_1,(void *)Always_46_2,(void *)Always_53_3};
	xsi_register_didat("work_m_00000000000903731200_3687061878", "isim/softmax_tb_isim_beh.exe.sim/work/m_00000000000903731200_3687061878.didat");
	xsi_register_executes(pe);
}
