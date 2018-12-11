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
static const char *ng0 = "C:/Users/CS152B/Desktop/cs152b/Final Project/fixed_point_calc/verilog_source_code/qdiv.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {0, 0, 0, 0, 0, 0};
static int ng4[] = {0, 0};
static int ng5[] = {0, 0, 0, 0};
static int ng6[] = {1, 0};
static int ng7[] = {45, 0};
static int ng8[] = {15, 0};
static int ng9[] = {76, 0};
static int ng10[] = {46, 0};



static void Initial_55_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(55, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3480);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Initial_56_1(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(56, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 3800);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Initial_57_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(57, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 3640);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Initial_59_3(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(59, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 2680);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 77);

LAB1:    return;
}

static void Initial_60_4(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(60, ng0);
    t1 = ((char*)((ng4)));
    t2 = (t0 + 2840);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB1:    return;
}

static void Initial_61_5(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(61, ng0);
    t1 = ((char*)((ng5)));
    t2 = (t0 + 3000);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 46);

LAB1:    return;
}

static void Initial_62_6(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(62, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 3160);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 77);

LAB1:    return;
}

static void Initial_63_7(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(63, ng0);
    t1 = ((char*)((ng4)));
    t2 = (t0 + 3320);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB1:    return;
}

static void Cont_66_8(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 6704U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2840);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t12 & 2147483647U);
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 2147483647U);
    t14 = (t0 + 8160);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 2147483647U;
    t20 = t19;
    t21 = (t3 + 4);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 30);
    t27 = (t0 + 8016);
    *((int *)t27) = 1;

LAB1:    return;
}

static void Cont_67_9(char *t0)
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

LAB0:    t1 = (t0 + 6952U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 3640);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8224);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
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
    xsi_driver_vfirst_trans(t5, 31, 31);
    t18 = (t0 + 8032);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_68_10(char *t0)
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

LAB0:    t1 = (t0 + 7200U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8288);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
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
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 8048);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_69_11(char *t0)
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

LAB0:    t1 = (t0 + 7448U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 3800);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8352);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
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
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 8064);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_71_12(char *t0)
{
    char t7[8];
    char t21[8];
    char t28[8];
    char t68[8];
    char t75[24];
    char t76[16];
    char t77[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    int t52;
    int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;
    int t69;
    int t70;
    int t71;
    int t72;
    int t73;
    int t74;

LAB0:    t1 = (t0 + 7696U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 8080);
    *((int *)t2) = 1;
    t3 = (t0 + 7728);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(71, ng0);

LAB5:    xsi_set_current_line(72, ng0);
    t4 = (t0 + 3480);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t7, 0, 8);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t8) != 0)
        goto LAB8;

LAB9:    t15 = (t7 + 4);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t15);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB10;

LAB11:    memcpy(t28, t7, 8);

LAB12:    t60 = (t28 + 4);
    t61 = *((unsigned int *)t60);
    t62 = (~(t61));
    t63 = *((unsigned int *)t28);
    t64 = (t63 & t62);
    t65 = (t64 != 0);
    if (t65 > 0)
        goto LAB20;

LAB21:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (~(t9));
    t11 = *((unsigned int *)t4);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB34;

LAB32:    if (*((unsigned int *)t5) == 0)
        goto LAB31;

LAB33:    t6 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t6) = 1;

LAB34:    t8 = (t7 + 4);
    t16 = *((unsigned int *)t8);
    t17 = (~(t16));
    t18 = *((unsigned int *)t7);
    t22 = (t18 & t17);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB35;

LAB36:
LAB37:
LAB22:    goto LAB2;

LAB6:    *((unsigned int *)t7) = 1;
    goto LAB9;

LAB8:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB9;

LAB10:    t19 = (t0 + 1640U);
    t20 = *((char **)t19);
    memset(t21, 0, 8);
    t19 = (t20 + 4);
    t22 = *((unsigned int *)t19);
    t23 = (~(t22));
    t24 = *((unsigned int *)t20);
    t25 = (t24 & t23);
    t26 = (t25 & 1U);
    if (t26 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t19) != 0)
        goto LAB15;

LAB16:    t29 = *((unsigned int *)t7);
    t30 = *((unsigned int *)t21);
    t31 = (t29 & t30);
    *((unsigned int *)t28) = t31;
    t32 = (t7 + 4);
    t33 = (t21 + 4);
    t34 = (t28 + 4);
    t35 = *((unsigned int *)t32);
    t36 = *((unsigned int *)t33);
    t37 = (t35 | t36);
    *((unsigned int *)t34) = t37;
    t38 = *((unsigned int *)t34);
    t39 = (t38 != 0);
    if (t39 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t21) = 1;
    goto LAB16;

LAB15:    t27 = (t21 + 4);
    *((unsigned int *)t21) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB16;

LAB17:    t40 = *((unsigned int *)t28);
    t41 = *((unsigned int *)t34);
    *((unsigned int *)t28) = (t40 | t41);
    t42 = (t7 + 4);
    t43 = (t21 + 4);
    t44 = *((unsigned int *)t7);
    t45 = (~(t44));
    t46 = *((unsigned int *)t42);
    t47 = (~(t46));
    t48 = *((unsigned int *)t21);
    t49 = (~(t48));
    t50 = *((unsigned int *)t43);
    t51 = (~(t50));
    t52 = (t45 & t47);
    t53 = (t49 & t51);
    t54 = (~(t52));
    t55 = (~(t53));
    t56 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t56 & t54);
    t57 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t57 & t55);
    t58 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t58 & t54);
    t59 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t59 & t55);
    goto LAB19;

LAB20:    xsi_set_current_line(72, ng0);

LAB23:    xsi_set_current_line(74, ng0);
    t66 = ((char*)((ng2)));
    t67 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t67, t66, 0, 0, 1, 0LL);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t2 = (t0 + 472);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t3, 32, t4, 32);
    t2 = ((char*)((ng6)));
    memset(t21, 0, 8);
    xsi_vlog_signed_minus(t21, 32, t7, 32, t2, 32);
    t5 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t5, t21, 0, 0, 32, 0LL);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2680);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 77, 0LL);
    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3000);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 46, 0LL);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3160);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 77, 0LL);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 1320U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t7) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t13 & 2147483647U);
    t16 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t16 & 2147483647U);
    t5 = (t0 + 3000);
    t6 = (t0 + 3000);
    t8 = (t6 + 72U);
    t14 = *((char **)t8);
    t15 = ((char*)((ng7)));
    t19 = ((char*)((ng8)));
    xsi_vlog_convert_partindices(t21, t28, t68, ((int*)(t14)), 2, t15, 32, 1, t19, 32, 1);
    t20 = (t21 + 4);
    t17 = *((unsigned int *)t20);
    t52 = (!(t17));
    t27 = (t28 + 4);
    t18 = *((unsigned int *)t27);
    t53 = (!(t18));
    t69 = (t52 && t53);
    t32 = (t68 + 4);
    t22 = *((unsigned int *)t32);
    t70 = (!(t22));
    t71 = (t69 && t70);
    if (t71 == 1)
        goto LAB24;

LAB25:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    *((unsigned int *)t7) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    *((unsigned int *)t2) = t12;
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t13 & 2147483647U);
    t16 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t16 & 2147483647U);
    t5 = (t0 + 3160);
    t6 = (t0 + 3160);
    t8 = (t6 + 72U);
    t14 = *((char **)t8);
    t15 = ((char*)((ng9)));
    t19 = ((char*)((ng10)));
    xsi_vlog_convert_partindices(t21, t28, t68, ((int*)(t14)), 2, t15, 32, 1, t19, 32, 1);
    t20 = (t21 + 4);
    t17 = *((unsigned int *)t20);
    t52 = (!(t17));
    t27 = (t28 + 4);
    t18 = *((unsigned int *)t27);
    t53 = (!(t18));
    t69 = (t52 && t53);
    t32 = (t68 + 4);
    t22 = *((unsigned int *)t32);
    t70 = (!(t22));
    t71 = (t69 && t70);
    if (t71 == 1)
        goto LAB26;

LAB27:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 1320U);
    t3 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 31);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 31);
    t16 = (t13 & 1);
    *((unsigned int *)t2) = t16;
    t5 = (t0 + 1480U);
    t6 = *((char **)t5);
    memset(t21, 0, 8);
    t5 = (t21 + 4);
    t8 = (t6 + 4);
    t17 = *((unsigned int *)t6);
    t18 = (t17 >> 31);
    t22 = (t18 & 1);
    *((unsigned int *)t21) = t22;
    t23 = *((unsigned int *)t8);
    t24 = (t23 >> 31);
    t25 = (t24 & 1);
    *((unsigned int *)t5) = t25;
    t26 = *((unsigned int *)t7);
    t29 = *((unsigned int *)t21);
    t30 = (t26 ^ t29);
    *((unsigned int *)t28) = t30;
    t14 = (t7 + 4);
    t15 = (t21 + 4);
    t19 = (t28 + 4);
    t31 = *((unsigned int *)t14);
    t35 = *((unsigned int *)t15);
    t36 = (t31 | t35);
    *((unsigned int *)t19) = t36;
    t37 = *((unsigned int *)t19);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB28;

LAB29:
LAB30:    t20 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t20, t28, 0, 0, 1, 0LL);
    goto LAB22;

LAB24:    t23 = *((unsigned int *)t68);
    t72 = (t23 + 0);
    t24 = *((unsigned int *)t21);
    t25 = *((unsigned int *)t28);
    t73 = (t24 - t25);
    t74 = (t73 + 1);
    xsi_vlogvar_wait_assign_value(t5, t7, t72, *((unsigned int *)t28), t74, 0LL);
    goto LAB25;

LAB26:    t23 = *((unsigned int *)t68);
    t72 = (t23 + 0);
    t24 = *((unsigned int *)t21);
    t25 = *((unsigned int *)t28);
    t73 = (t24 - t25);
    t74 = (t73 + 1);
    xsi_vlogvar_wait_assign_value(t5, t7, t72, *((unsigned int *)t28), t74, 0LL);
    goto LAB27;

LAB28:    t39 = *((unsigned int *)t28);
    t40 = *((unsigned int *)t19);
    *((unsigned int *)t28) = (t39 | t40);
    goto LAB30;

LAB31:    *((unsigned int *)t7) = 1;
    goto LAB34;

LAB35:    xsi_set_current_line(86, ng0);

LAB38:    xsi_set_current_line(87, ng0);
    t14 = (t0 + 3160);
    t15 = (t14 + 56U);
    t19 = *((char **)t15);
    t20 = ((char*)((ng6)));
    xsi_vlog_unsigned_rshift(t75, 77, t19, 77, t20, 32);
    t27 = (t0 + 3160);
    xsi_vlogvar_wait_assign_value(t27, t75, 0, 0, 77, 0LL);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_minus(t7, 32, t4, 32, t5, 32);
    t6 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t6, t7, 0, 0, 32, 0LL);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3160);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    xsi_vlog_unsigned_greatereq(t75, 77, t4, 46, t8, 77);
    t14 = (t75 + 4);
    t9 = *((unsigned int *)t14);
    t10 = (~(t9));
    t11 = *((unsigned int *)t75);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB39;

LAB40:
LAB41:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t7, 0, 8);
    t6 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t8);
    t16 = (t12 ^ t13);
    t17 = (t11 | t16);
    t18 = *((unsigned int *)t6);
    t22 = *((unsigned int *)t8);
    t23 = (t18 | t22);
    t24 = (~(t23));
    t25 = (t17 & t24);
    if (t25 != 0)
        goto LAB48;

LAB45:    if (t23 != 0)
        goto LAB47;

LAB46:    *((unsigned int *)t7) = 1;

LAB48:    t15 = (t7 + 4);
    t26 = *((unsigned int *)t15);
    t29 = (~(t26));
    t30 = *((unsigned int *)t7);
    t31 = (t30 & t29);
    t35 = (t31 != 0);
    if (t35 > 0)
        goto LAB49;

LAB50:    xsi_set_current_line(104, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_minus(t7, 32, t4, 32, t5, 32);
    t6 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t6, t7, 0, 0, 32, 0LL);

LAB51:    goto LAB37;

LAB39:    xsi_set_current_line(91, ng0);

LAB42:    xsi_set_current_line(92, ng0);
    t15 = ((char*)((ng1)));
    t19 = (t0 + 2680);
    t20 = (t0 + 2680);
    t27 = (t20 + 72U);
    t32 = *((char **)t27);
    t33 = (t0 + 3320);
    t34 = (t33 + 56U);
    t42 = *((char **)t34);
    xsi_vlog_generic_convert_bit_index(t7, t32, 2, t42, 32, 2);
    t43 = (t7 + 4);
    t16 = *((unsigned int *)t43);
    t52 = (!(t16));
    if (t52 == 1)
        goto LAB43;

LAB44:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3160);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    xsi_vlog_unsigned_minus(t75, 77, t4, 46, t8, 77);
    t14 = (t0 + 3000);
    xsi_vlogvar_wait_assign_value(t14, t75, 0, 0, 46, 0LL);
    goto LAB41;

LAB43:    xsi_vlogvar_wait_assign_value(t19, t15, 0, *((unsigned int *)t7), 1, 0LL);
    goto LAB44;

LAB47:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB48;

LAB49:    xsi_set_current_line(97, ng0);

LAB52:    xsi_set_current_line(98, ng0);
    t19 = ((char*)((ng1)));
    t20 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 1, 0LL);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 2680);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2840);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 32, 0LL);
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 2680);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlog_get_part_select_value(t76, 45, t4, 76, 32);
    t5 = ((char*)((ng5)));
    xsi_vlog_unsigned_greater(t77, 45, t76, 45, t5, 32);
    t6 = (t77 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t77);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB53;

LAB54:
LAB55:    goto LAB51;

LAB53:    xsi_set_current_line(101, ng0);
    t8 = ((char*)((ng1)));
    t14 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t14, t8, 0, 0, 1, 0LL);
    goto LAB55;

}


extern void work_m_00000000003991964843_0510015413_init()
{
	static char *pe[] = {(void *)Initial_55_0,(void *)Initial_56_1,(void *)Initial_57_2,(void *)Initial_59_3,(void *)Initial_60_4,(void *)Initial_61_5,(void *)Initial_62_6,(void *)Initial_63_7,(void *)Cont_66_8,(void *)Cont_67_9,(void *)Cont_68_10,(void *)Cont_69_11,(void *)Always_71_12};
	xsi_register_didat("work_m_00000000003991964843_0510015413", "isim/softmax_tb_isim_beh.exe.sim/work/m_00000000003991964843_0510015413.didat");
	xsi_register_executes(pe);
}
