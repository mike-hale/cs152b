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
static const char *ng0 = "C:/Users/CS152B/Desktop/cs152b/Final Project/softmax.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {32768U, 0U};
static unsigned int ng3[] = {1U, 0U};
static int ng4[] = {1, 0};
static int ng5[] = {3, 0};



static void Cont_55_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    t1 = (t0 + 8896U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 4376U);
    t3 = *((char **)t2);
    t2 = (t0 + 4336U);
    t5 = (t2 + 72U);
    t6 = *((char **)t5);
    t7 = (t0 + 4336U);
    t8 = (t7 + 48U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t4, 32, t3, t6, t9, 2, 1, t10, 32, 1);
    t11 = (t0 + 11128);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t4, 8);
    xsi_driver_vfirst_trans(t11, 0, 31);
    t16 = (t0 + 10952);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Cont_72_1(char *t0)
{
    char t3[8];
    char t4[8];
    char t9[8];
    char t35[8];
    char t40[8];
    char t50[8];
    char t59[8];
    char t68[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    char *t66;
    char *t67;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;

LAB0:    t1 = (t0 + 9144U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 5896);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3096U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t7 = (t6 + 4);
    t10 = (t8 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t8);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB7;

LAB4:    if (t20 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t9) = 1;

LAB7:    memset(t4, 0, 8);
    t24 = (t9 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t9);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t24) != 0)
        goto LAB10;

LAB11:    t31 = (t4 + 4);
    t32 = *((unsigned int *)t4);
    t33 = *((unsigned int *)t31);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB12;

LAB13:    t61 = *((unsigned int *)t4);
    t62 = (~(t61));
    t63 = *((unsigned int *)t31);
    t64 = (t62 || t63);
    if (t64 > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t31) > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t4) > 0)
        goto LAB18;

LAB19:    memcpy(t3, t68, 8);

LAB20:    t78 = (t0 + 11192);
    t79 = (t78 + 56U);
    t80 = *((char **)t79);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    memcpy(t82, t3, 8);
    xsi_driver_vfirst_trans(t78, 0, 31);
    t83 = (t0 + 10968);
    *((int *)t83) = 1;

LAB1:    return;
LAB6:    t23 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB11;

LAB10:    t30 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB11;

LAB12:    t36 = ((char*)((ng2)));
    t37 = (t0 + 6216);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t41 = (t0 + 6216);
    t42 = (t41 + 72U);
    t43 = *((char **)t42);
    t44 = (t0 + 6216);
    t45 = (t44 + 64U);
    t46 = *((char **)t45);
    t47 = (t0 + 5896);
    t48 = (t47 + 56U);
    t49 = *((char **)t48);
    xsi_vlog_generic_get_array_select_value(t40, 32, t39, t43, t46, 2, 1, t49, 3, 2);
    memset(t50, 0, 8);
    t51 = (t50 + 4);
    t52 = (t40 + 4);
    t53 = *((unsigned int *)t40);
    t54 = (t53 >> 0);
    *((unsigned int *)t50) = t54;
    t55 = *((unsigned int *)t52);
    t56 = (t55 >> 0);
    *((unsigned int *)t51) = t56;
    t57 = *((unsigned int *)t50);
    *((unsigned int *)t50) = (t57 & 2147483647U);
    t58 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t58 & 2147483647U);
    memset(t59, 0, 8);
    xsi_vlog_unsigned_minus(t59, 31, t36, 31, t50, 31);
    t60 = ((char*)((ng3)));
    xsi_vlogtype_concat(t35, 32, 32, 2U, t60, 1, t59, 31);
    goto LAB13;

LAB14:    t65 = (t0 + 6216);
    t66 = (t65 + 56U);
    t67 = *((char **)t66);
    t69 = (t0 + 6216);
    t70 = (t69 + 72U);
    t71 = *((char **)t70);
    t72 = (t0 + 6216);
    t73 = (t72 + 64U);
    t74 = *((char **)t73);
    t75 = (t0 + 5896);
    t76 = (t75 + 56U);
    t77 = *((char **)t76);
    xsi_vlog_generic_get_array_select_value(t68, 32, t67, t71, t74, 2, 1, t77, 3, 2);
    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 32, t35, 32, t68, 32);
    goto LAB20;

LAB18:    memcpy(t3, t35, 8);
    goto LAB20;

}

static void Initial_75_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(75, ng0);

LAB2:    xsi_set_current_line(76, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 5576);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 3, 0LL);
    xsi_set_current_line(77, ng0);
    t1 = ((char*)((ng4)));
    t2 = (t0 + 5256);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    xsi_set_current_line(78, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 5416);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    xsi_set_current_line(79, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 6536);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 3, 0LL);

LAB1:    return;
}

static void Cont_97_3(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    t1 = (t0 + 9640U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 6536);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memcpy(t5, t4, 8);
    t6 = (t0 + 11256);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t5, 8);
    xsi_driver_vfirst_trans(t6, 0, 31);
    t11 = (t0 + 10984);
    *((int *)t11) = 1;

LAB1:    return;
}

static void Cont_98_4(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
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
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 9888U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(98, ng0);
    t2 = (t0 + 6216);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 6216);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 6216);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = (t0 + 5896);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    xsi_vlog_generic_get_array_select_value(t5, 32, t4, t8, t11, 2, 1, t14, 3, 2);
    t15 = (t0 + 11320);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t5, 8);
    xsi_driver_vfirst_trans(t15, 0, 31);
    t20 = (t0 + 11000);
    *((int *)t20) = 1;

LAB1:    return;
}

static void Cont_99_5(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    t1 = (t0 + 10136U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 5896);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memcpy(t5, t4, 8);
    t6 = (t0 + 11384);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t5, 8);
    xsi_driver_vfirst_trans(t6, 0, 31);
    t11 = (t0 + 11016);
    *((int *)t11) = 1;

LAB1:    return;
}

static void Cont_100_6(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
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

LAB0:    t1 = (t0 + 10384U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 6216);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 6216);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 6216);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng5)));
    xsi_vlog_generic_get_array_select_value(t5, 32, t4, t8, t11, 2, 1, t12, 32, 1);
    t13 = (t0 + 11448);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t5, 8);
    xsi_driver_vfirst_trans(t13, 0, 31);
    t18 = (t0 + 11032);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_103_7(char *t0)
{
    char t11[8];
    char t30[8];
    char t58[8];
    char t62[16];
    char t75[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    char *t10;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    int t54;
    int t55;
    int t56;
    int t57;
    unsigned int t59;
    char *t60;
    char *t61;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;

LAB0:    t1 = (t0 + 10632U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 11048);
    *((int *)t2) = 1;
    t3 = (t0 + 10664);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(103, ng0);

LAB5:    xsi_set_current_line(104, ng0);
    t4 = (t0 + 6536);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = (t0 + 744);
    t8 = *((char **)t7);
    t9 = xsi_vlog_unsigned_case_compare(t6, 3, t8, 32);
    if (t9 == 1)
        goto LAB7;

LAB8:    t2 = (t0 + 880);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t9 == 1)
        goto LAB9;

LAB10:    t2 = (t0 + 1016);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t9 == 1)
        goto LAB11;

LAB12:    t2 = (t0 + 1152);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t9 == 1)
        goto LAB13;

LAB14:    t2 = (t0 + 1288);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t9 == 1)
        goto LAB15;

LAB16:    t2 = (t0 + 1424);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t9 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(105, ng0);

LAB20:    xsi_set_current_line(106, ng0);
    t7 = ((char*)((ng4)));
    t10 = (t0 + 5256);
    xsi_vlogvar_wait_assign_value(t10, t7, 0, 0, 1, 0LL);
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 2776U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t11, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t12 = *((unsigned int *)t3);
    t13 = *((unsigned int *)t2);
    t14 = (t12 ^ t13);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t5);
    t17 = (t15 ^ t16);
    t18 = (t14 | t17);
    t19 = *((unsigned int *)t4);
    t20 = *((unsigned int *)t5);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB24;

LAB21:    if (t21 != 0)
        goto LAB23;

LAB22:    *((unsigned int *)t11) = 1;

LAB24:    t8 = (t11 + 4);
    t24 = *((unsigned int *)t8);
    t25 = (~(t24));
    t26 = *((unsigned int *)t11);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB25;

LAB26:
LAB27:    goto LAB19;

LAB9:    xsi_set_current_line(127, ng0);

LAB50:    xsi_set_current_line(128, ng0);
    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 7496);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);

LAB51:    t2 = (t0 + 7496);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 472);
    t7 = *((char **)t5);
    memset(t11, 0, 8);
    xsi_vlog_signed_less(t11, 32, t4, 32, t7, 32);
    t5 = (t11 + 4);
    t12 = *((unsigned int *)t5);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB52;

LAB53:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 4216U);
    t3 = *((char **)t2);
    memset(t11, 0, 8);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = *((unsigned int *)t2);
    t14 = (t12 | t13);
    if (t14 != 15U)
        goto LAB58;

LAB57:    if (*((unsigned int *)t2) == 0)
        goto LAB59;

LAB60:    t4 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t4) = 1;

LAB58:    t5 = (t0 + 6696);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memset(t30, 0, 8);
    t10 = (t8 + 4);
    t15 = *((unsigned int *)t8);
    t16 = *((unsigned int *)t10);
    t17 = (t15 | t16);
    if (t17 != 15U)
        goto LAB63;

LAB61:    if (*((unsigned int *)t10) == 0)
        goto LAB62;

LAB64:    t29 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t29) = 1;

LAB62:    t18 = *((unsigned int *)t11);
    t19 = *((unsigned int *)t30);
    t20 = (t18 & t19);
    *((unsigned int *)t58) = t20;
    t31 = (t11 + 4);
    t32 = (t30 + 4);
    t45 = (t58 + 4);
    t21 = *((unsigned int *)t31);
    t22 = *((unsigned int *)t32);
    t23 = (t21 | t22);
    *((unsigned int *)t45) = t23;
    t24 = *((unsigned int *)t45);
    t25 = (t24 != 0);
    if (t25 == 1)
        goto LAB65;

LAB66:
LAB67:    t53 = (t58 + 4);
    t48 = *((unsigned int *)t53);
    t49 = (~(t48));
    t50 = *((unsigned int *)t58);
    t51 = (t50 & t49);
    t59 = (t51 != 0);
    if (t59 > 0)
        goto LAB68;

LAB69:
LAB70:    goto LAB19;

LAB11:    xsi_set_current_line(135, ng0);

LAB72:    xsi_set_current_line(136, ng0);
    t2 = (t0 + 4536U);
    t4 = *((char **)t2);
    t2 = (t0 + 4496U);
    t5 = (t2 + 72U);
    t7 = *((char **)t5);
    t8 = (t0 + 4496U);
    t10 = (t8 + 48U);
    t29 = *((char **)t10);
    t31 = ((char*)((ng5)));
    xsi_vlog_generic_get_array_select_value(t62, 44, t4, t7, t29, 2, 1, t31, 32, 1);
    t32 = (t0 + 6856);
    xsi_vlogvar_wait_assign_value(t32, t62, 0, 0, 44, 0LL);
    xsi_set_current_line(137, ng0);
    t2 = (t0 + 1152);
    t3 = *((char **)t2);
    t2 = (t0 + 6536);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 3, 0LL);
    xsi_set_current_line(138, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 7176);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB19;

LAB13:    xsi_set_current_line(140, ng0);

LAB73:    xsi_set_current_line(141, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 7176);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(142, ng0);
    t2 = (t0 + 4696U);
    t3 = *((char **)t2);
    memset(t11, 0, 8);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t3);
    t13 = *((unsigned int *)t2);
    t14 = (t12 | t13);
    if (t14 != 15U)
        goto LAB75;

LAB74:    if (*((unsigned int *)t2) == 0)
        goto LAB76;

LAB77:    t4 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t4) = 1;

LAB75:    t5 = (t0 + 7176);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memset(t30, 0, 8);
    t10 = (t8 + 4);
    t15 = *((unsigned int *)t10);
    t16 = (~(t15));
    t17 = *((unsigned int *)t8);
    t18 = (t17 & t16);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB81;

LAB79:    if (*((unsigned int *)t10) == 0)
        goto LAB78;

LAB80:    t29 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t29) = 1;

LAB81:    t31 = (t30 + 4);
    t32 = (t8 + 4);
    t20 = *((unsigned int *)t8);
    t21 = (~(t20));
    *((unsigned int *)t30) = t21;
    *((unsigned int *)t31) = 0;
    if (*((unsigned int *)t32) != 0)
        goto LAB83;

LAB82:    t26 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t26 & 1U);
    t27 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t27 & 1U);
    t28 = *((unsigned int *)t11);
    t33 = *((unsigned int *)t30);
    t34 = (t28 & t33);
    *((unsigned int *)t58) = t34;
    t45 = (t11 + 4);
    t46 = (t30 + 4);
    t52 = (t58 + 4);
    t35 = *((unsigned int *)t45);
    t36 = *((unsigned int *)t46);
    t37 = (t35 | t36);
    *((unsigned int *)t52) = t37;
    t38 = *((unsigned int *)t52);
    t39 = (t38 != 0);
    if (t39 == 1)
        goto LAB84;

LAB85:
LAB86:    t61 = (t58 + 4);
    t68 = *((unsigned int *)t61);
    t69 = (~(t68));
    t70 = *((unsigned int *)t58);
    t71 = (t70 & t69);
    t72 = (t71 != 0);
    if (t72 > 0)
        goto LAB87;

LAB88:
LAB89:    goto LAB19;

LAB15:    xsi_set_current_line(149, ng0);

LAB91:    xsi_set_current_line(150, ng0);
    xsi_set_current_line(150, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 7496);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);

LAB92:    t2 = (t0 + 7496);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 472);
    t7 = *((char **)t5);
    memset(t11, 0, 8);
    xsi_vlog_signed_less(t11, 32, t4, 32, t7, 32);
    t5 = (t11 + 4);
    t12 = *((unsigned int *)t5);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB93;

LAB94:    xsi_set_current_line(153, ng0);
    t2 = (t0 + 7656);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 472);
    t7 = *((char **)t5);
    memset(t11, 0, 8);
    t5 = (t4 + 4);
    t8 = (t7 + 4);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t7);
    t14 = (t12 ^ t13);
    t15 = *((unsigned int *)t5);
    t16 = *((unsigned int *)t8);
    t17 = (t15 ^ t16);
    t18 = (t14 | t17);
    t19 = *((unsigned int *)t5);
    t20 = *((unsigned int *)t8);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB101;

LAB98:    if (t21 != 0)
        goto LAB100;

LAB99:    *((unsigned int *)t11) = 1;

LAB101:    t29 = (t11 + 4);
    t24 = *((unsigned int *)t29);
    t25 = (~(t24));
    t26 = *((unsigned int *)t11);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB102;

LAB103:    xsi_set_current_line(155, ng0);

LAB106:    xsi_set_current_line(156, ng0);
    t2 = (t0 + 4056U);
    t3 = *((char **)t2);
    t2 = (t0 + 4016U);
    t4 = (t2 + 72U);
    t5 = *((char **)t4);
    t7 = (t0 + 4016U);
    t8 = (t7 + 48U);
    t10 = *((char **)t8);
    t29 = (t0 + 5576);
    t31 = (t29 + 56U);
    t32 = *((char **)t31);
    xsi_vlog_generic_get_array_select_value(t11, 32, t3, t5, t10, 2, 1, t32, 3, 2);
    t45 = (t0 + 4056U);
    t46 = *((char **)t45);
    t45 = (t0 + 4016U);
    t52 = (t45 + 72U);
    t53 = *((char **)t52);
    t60 = (t0 + 4016U);
    t61 = (t60 + 48U);
    t73 = *((char **)t61);
    t74 = (t0 + 7656);
    t76 = (t74 + 56U);
    t77 = *((char **)t76);
    xsi_vlog_generic_get_array_select_value(t30, 32, t46, t53, t73, 2, 1, t77, 3, 2);
    memset(t58, 0, 8);
    t78 = (t11 + 4);
    if (*((unsigned int *)t78) != 0)
        goto LAB108;

LAB107:    t79 = (t30 + 4);
    if (*((unsigned int *)t79) != 0)
        goto LAB108;

LAB111:    if (*((unsigned int *)t11) < *((unsigned int *)t30))
        goto LAB109;

LAB110:    t81 = (t58 + 4);
    t12 = *((unsigned int *)t81);
    t13 = (~(t12));
    t14 = *((unsigned int *)t58);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB112;

LAB113:    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7976);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB114:    xsi_set_current_line(160, ng0);
    t2 = (t0 + 7656);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 32, t4, 3, t5, 32);
    t7 = (t0 + 7656);
    xsi_vlogvar_wait_assign_value(t7, t11, 0, 0, 3, 0LL);

LAB104:    xsi_set_current_line(162, ng0);
    t2 = (t0 + 5736);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t12 = *((unsigned int *)t5);
    t13 = (~(t12));
    t14 = *((unsigned int *)t4);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB115;

LAB116:
LAB117:    goto LAB19;

LAB17:    xsi_set_current_line(169, ng0);

LAB119:    xsi_set_current_line(170, ng0);
    t2 = (t0 + 2776U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t11, 0, 8);
    t5 = (t4 + 4);
    t7 = (t2 + 4);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t2);
    t14 = (t12 ^ t13);
    t15 = *((unsigned int *)t5);
    t16 = *((unsigned int *)t7);
    t17 = (t15 ^ t16);
    t18 = (t14 | t17);
    t19 = *((unsigned int *)t5);
    t20 = *((unsigned int *)t7);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB123;

LAB120:    if (t21 != 0)
        goto LAB122;

LAB121:    *((unsigned int *)t11) = 1;

LAB123:    t10 = (t11 + 4);
    t24 = *((unsigned int *)t10);
    t25 = (~(t24));
    t26 = *((unsigned int *)t11);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB124;

LAB125:
LAB126:    goto LAB19;

LAB23:    t7 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB24;

LAB25:    xsi_set_current_line(107, ng0);

LAB28:    xsi_set_current_line(108, ng0);
    t10 = (t0 + 2296U);
    t29 = *((char **)t10);
    t10 = ((char*)((ng1)));
    memset(t30, 0, 8);
    t31 = (t29 + 4);
    t32 = (t10 + 4);
    t33 = *((unsigned int *)t29);
    t34 = *((unsigned int *)t10);
    t35 = (t33 ^ t34);
    t36 = *((unsigned int *)t31);
    t37 = *((unsigned int *)t32);
    t38 = (t36 ^ t37);
    t39 = (t35 | t38);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 | t41);
    t43 = (~(t42));
    t44 = (t39 & t43);
    if (t44 != 0)
        goto LAB32;

LAB29:    if (t42 != 0)
        goto LAB31;

LAB30:    *((unsigned int *)t30) = 1;

LAB32:    t46 = (t30 + 4);
    t47 = *((unsigned int *)t46);
    t48 = (~(t47));
    t49 = *((unsigned int *)t30);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB33;

LAB34:    xsi_set_current_line(118, ng0);

LAB49:    xsi_set_current_line(119, ng0);
    t2 = (t0 + 1424);
    t3 = *((char **)t2);
    t2 = (t0 + 6536);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 3, 0LL);
    xsi_set_current_line(120, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5896);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(122, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5416);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB35:    goto LAB27;

LAB31:    t45 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB32;

LAB33:    xsi_set_current_line(108, ng0);

LAB36:    xsi_set_current_line(109, ng0);
    t52 = ((char*)((ng4)));
    t53 = (t0 + 5256);
    xsi_vlogvar_wait_assign_value(t53, t52, 0, 0, 1, 0LL);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 2456U);
    t3 = *((char **)t2);
    t2 = (t0 + 6056);
    t4 = (t0 + 6056);
    t5 = (t4 + 72U);
    t7 = *((char **)t5);
    t8 = (t0 + 6056);
    t10 = (t8 + 64U);
    t29 = *((char **)t10);
    t31 = (t0 + 2616U);
    t32 = *((char **)t31);
    xsi_vlog_generic_convert_array_indices(t11, t30, t7, t29, 2, 1, t32, 3, 2);
    t31 = (t11 + 4);
    t12 = *((unsigned int *)t31);
    t9 = (!(t12));
    t45 = (t30 + 4);
    t13 = *((unsigned int *)t45);
    t54 = (!(t13));
    t55 = (t9 && t54);
    if (t55 == 1)
        goto LAB37;

LAB38:    xsi_set_current_line(111, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 6696);
    t4 = (t0 + 6696);
    t5 = (t4 + 72U);
    t7 = *((char **)t5);
    t8 = (t0 + 2616U);
    t10 = *((char **)t8);
    xsi_vlog_generic_convert_bit_index(t11, t7, 2, t10, 3, 2);
    t8 = (t11 + 4);
    t12 = *((unsigned int *)t8);
    t9 = (!(t12));
    if (t9 == 1)
        goto LAB39;

LAB40:    xsi_set_current_line(112, ng0);
    t2 = (t0 + 6696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t11, 0, 8);
    t5 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 | t13);
    if (t14 != 15U)
        goto LAB42;

LAB41:    if (*((unsigned int *)t5) == 0)
        goto LAB43;

LAB44:    t7 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t7) = 1;

LAB42:    t8 = (t11 + 4);
    t15 = *((unsigned int *)t8);
    t16 = (~(t15));
    t17 = *((unsigned int *)t11);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB45;

LAB46:
LAB47:    xsi_set_current_line(117, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5736);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB35;

LAB37:    t14 = *((unsigned int *)t11);
    t15 = *((unsigned int *)t30);
    t56 = (t14 - t15);
    t57 = (t56 + 1);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, *((unsigned int *)t30), t57, 0LL);
    goto LAB38;

LAB39:    xsi_vlogvar_wait_assign_value(t3, t2, 0, *((unsigned int *)t11), 1, 0LL);
    goto LAB40;

LAB43:    *((unsigned int *)t11) = 1;
    goto LAB42;

LAB45:    xsi_set_current_line(112, ng0);

LAB48:    xsi_set_current_line(113, ng0);
    t10 = ((char*)((ng1)));
    t29 = (t0 + 5256);
    xsi_vlogvar_wait_assign_value(t29, t10, 0, 0, 1, 0LL);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 880);
    t3 = *((char **)t2);
    t2 = (t0 + 6536);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 3, 0LL);
    goto LAB47;

LAB52:    xsi_set_current_line(128, ng0);

LAB54:    xsi_set_current_line(129, ng0);
    t8 = ((char*)((ng1)));
    t10 = (t0 + 6696);
    t29 = (t0 + 6696);
    t31 = (t29 + 72U);
    t32 = *((char **)t31);
    t45 = (t0 + 7496);
    t46 = (t45 + 56U);
    t52 = *((char **)t46);
    xsi_vlog_generic_convert_bit_index(t30, t32, 2, t52, 32, 1);
    t53 = (t30 + 4);
    t17 = *((unsigned int *)t53);
    t9 = (!(t17));
    if (t9 == 1)
        goto LAB55;

LAB56:    xsi_set_current_line(128, ng0);
    t2 = (t0 + 7496);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t11, 0, 8);
    xsi_vlog_signed_add(t11, 32, t4, 32, t5, 32);
    t7 = (t0 + 7496);
    xsi_vlogvar_assign_value(t7, t11, 0, 0, 32);
    goto LAB51;

LAB55:    xsi_vlogvar_wait_assign_value(t10, t8, 0, *((unsigned int *)t30), 1, 0LL);
    goto LAB56;

LAB59:    *((unsigned int *)t11) = 1;
    goto LAB58;

LAB63:    *((unsigned int *)t30) = 1;
    goto LAB62;

LAB65:    t26 = *((unsigned int *)t58);
    t27 = *((unsigned int *)t45);
    *((unsigned int *)t58) = (t26 | t27);
    t46 = (t11 + 4);
    t52 = (t30 + 4);
    t28 = *((unsigned int *)t11);
    t33 = (~(t28));
    t34 = *((unsigned int *)t46);
    t35 = (~(t34));
    t36 = *((unsigned int *)t30);
    t37 = (~(t36));
    t38 = *((unsigned int *)t52);
    t39 = (~(t38));
    t9 = (t33 & t35);
    t54 = (t37 & t39);
    t40 = (~(t9));
    t41 = (~(t54));
    t42 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t42 & t40);
    t43 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t43 & t41);
    t44 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t44 & t40);
    t47 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t47 & t41);
    goto LAB67;

LAB68:    xsi_set_current_line(131, ng0);

LAB71:    xsi_set_current_line(132, ng0);
    t60 = (t0 + 1016);
    t61 = *((char **)t60);
    t60 = (t0 + 6536);
    xsi_vlogvar_wait_assign_value(t60, t61, 0, 0, 3, 0LL);
    goto LAB70;

LAB76:    *((unsigned int *)t11) = 1;
    goto LAB75;

LAB78:    *((unsigned int *)t30) = 1;
    goto LAB81;

LAB83:    t22 = *((unsigned int *)t30);
    t23 = *((unsigned int *)t32);
    *((unsigned int *)t30) = (t22 | t23);
    t24 = *((unsigned int *)t31);
    t25 = *((unsigned int *)t32);
    *((unsigned int *)t31) = (t24 | t25);
    goto LAB82;

LAB84:    t40 = *((unsigned int *)t58);
    t41 = *((unsigned int *)t52);
    *((unsigned int *)t58) = (t40 | t41);
    t53 = (t11 + 4);
    t60 = (t30 + 4);
    t42 = *((unsigned int *)t11);
    t43 = (~(t42));
    t44 = *((unsigned int *)t53);
    t47 = (~(t44));
    t48 = *((unsigned int *)t30);
    t49 = (~(t48));
    t50 = *((unsigned int *)t60);
    t51 = (~(t50));
    t9 = (t43 & t47);
    t54 = (t49 & t51);
    t59 = (~(t9));
    t63 = (~(t54));
    t64 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t64 & t59);
    t65 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t65 & t63);
    t66 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t66 & t59);
    t67 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t67 & t63);
    goto LAB86;

LAB87:    xsi_set_current_line(142, ng0);

LAB90:    xsi_set_current_line(143, ng0);
    t73 = ((char*)((ng1)));
    t74 = (t0 + 5576);
    xsi_vlogvar_wait_assign_value(t74, t73, 0, 0, 3, 0LL);
    xsi_set_current_line(144, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7656);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(145, ng0);
    t2 = (t0 + 1288);
    t3 = *((char **)t2);
    t2 = (t0 + 6536);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 3, 0LL);
    goto LAB89;

LAB93:    xsi_set_current_line(150, ng0);

LAB95:    xsi_set_current_line(151, ng0);
    t8 = (t0 + 4056U);
    t10 = *((char **)t8);
    t8 = (t0 + 4016U);
    t29 = (t8 + 72U);
    t31 = *((char **)t29);
    t32 = (t0 + 4016U);
    t45 = (t32 + 48U);
    t46 = *((char **)t45);
    t52 = (t0 + 7496);
    t53 = (t52 + 56U);
    t60 = *((char **)t53);
    xsi_vlog_generic_get_array_select_value(t30, 32, t10, t31, t46, 2, 1, t60, 32, 1);
    t61 = (t0 + 6216);
    t73 = (t0 + 6216);
    t74 = (t73 + 72U);
    t76 = *((char **)t74);
    t77 = (t0 + 6216);
    t78 = (t77 + 64U);
    t79 = *((char **)t78);
    t80 = (t0 + 7496);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    xsi_vlog_generic_convert_array_indices(t58, t75, t76, t79, 2, 1, t82, 32, 1);
    t83 = (t58 + 4);
    t17 = *((unsigned int *)t83);
    t9 = (!(t17));
    t84 = (t75 + 4);
    t18 = *((unsigned int *)t84);
    t54 = (!(t18));
    t55 = (t9 && t54);
    if (t55 == 1)
        goto LAB96;

LAB97:    xsi_set_current_line(150, ng0);
    t2 = (t0 + 7496);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t11, 0, 8);
    xsi_vlog_signed_add(t11, 32, t4, 32, t5, 32);
    t7 = (t0 + 7496);
    xsi_vlogvar_assign_value(t7, t11, 0, 0, 32);
    goto LAB92;

LAB96:    t19 = *((unsigned int *)t58);
    t20 = *((unsigned int *)t75);
    t56 = (t19 - t20);
    t57 = (t56 + 1);
    xsi_vlogvar_assign_value(t61, t30, 0, *((unsigned int *)t75), t57);
    goto LAB97;

LAB100:    t10 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB101;

LAB102:    xsi_set_current_line(153, ng0);

LAB105:    xsi_set_current_line(154, ng0);
    t31 = ((char*)((ng4)));
    t32 = (t0 + 5736);
    xsi_vlogvar_wait_assign_value(t32, t31, 0, 0, 1, 0LL);
    goto LAB104;

LAB108:    t80 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t80) = 1;
    goto LAB110;

LAB109:    *((unsigned int *)t58) = 1;
    goto LAB110;

LAB112:    xsi_set_current_line(157, ng0);
    t82 = (t0 + 7656);
    t83 = (t82 + 56U);
    t84 = *((char **)t83);
    t85 = (t0 + 5576);
    xsi_vlogvar_wait_assign_value(t85, t84, 0, 0, 3, 0LL);
    goto LAB114;

LAB115:    xsi_set_current_line(162, ng0);

LAB118:    xsi_set_current_line(163, ng0);
    t7 = (t0 + 744);
    t8 = *((char **)t7);
    t7 = (t0 + 6536);
    xsi_vlogvar_wait_assign_value(t7, t8, 0, 0, 3, 0LL);
    xsi_set_current_line(164, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 5256);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 5416);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB117;

LAB122:    t8 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB123;

LAB124:    xsi_set_current_line(170, ng0);

LAB127:    xsi_set_current_line(171, ng0);
    t29 = (t0 + 5896);
    t31 = (t29 + 56U);
    t32 = *((char **)t31);
    t45 = (t0 + 472);
    t46 = *((char **)t45);
    t45 = ((char*)((ng4)));
    memset(t30, 0, 8);
    xsi_vlog_unsigned_minus(t30, 32, t46, 32, t45, 32);
    memset(t58, 0, 8);
    t52 = (t32 + 4);
    t53 = (t30 + 4);
    t33 = *((unsigned int *)t32);
    t34 = *((unsigned int *)t30);
    t35 = (t33 ^ t34);
    t36 = *((unsigned int *)t52);
    t37 = *((unsigned int *)t53);
    t38 = (t36 ^ t37);
    t39 = (t35 | t38);
    t40 = *((unsigned int *)t52);
    t41 = *((unsigned int *)t53);
    t42 = (t40 | t41);
    t43 = (~(t42));
    t44 = (t39 & t43);
    if (t44 != 0)
        goto LAB131;

LAB128:    if (t42 != 0)
        goto LAB130;

LAB129:    *((unsigned int *)t58) = 1;

LAB131:    t61 = (t58 + 4);
    t47 = *((unsigned int *)t61);
    t48 = (~(t47));
    t49 = *((unsigned int *)t58);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB132;

LAB133:    xsi_set_current_line(175, ng0);

LAB136:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 5896);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 32, t4, 3, t5, 32);
    t7 = (t0 + 5896);
    xsi_vlogvar_wait_assign_value(t7, t11, 0, 0, 3, 0LL);
    xsi_set_current_line(178, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 5416);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB134:    goto LAB126;

LAB130:    t60 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t60) = 1;
    goto LAB131;

LAB132:    xsi_set_current_line(171, ng0);

LAB135:    xsi_set_current_line(172, ng0);
    t73 = (t0 + 744);
    t74 = *((char **)t73);
    t73 = (t0 + 6536);
    xsi_vlogvar_wait_assign_value(t73, t74, 0, 0, 3, 0LL);
    xsi_set_current_line(173, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5416);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(174, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5896);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB134;

}


extern void work_m_00000000001397760730_0415658247_init()
{
	static char *pe[] = {(void *)Cont_55_0,(void *)Cont_72_1,(void *)Initial_75_2,(void *)Cont_97_3,(void *)Cont_98_4,(void *)Cont_99_5,(void *)Cont_100_6,(void *)Always_103_7};
	xsi_register_didat("work_m_00000000001397760730_0415658247", "isim/softmax_tb_isim_beh.exe.sim/work/m_00000000001397760730_0415658247.didat");
	xsi_register_executes(pe);
}
