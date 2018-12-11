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
static const char *ng0 = "C:/Users/CS152B/Desktop/cs152b/Final Project/test_softmax.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {32768U, 0U};
static int ng3[] = {1, 0};
static int ng4[] = {1000, 0};
static const char *ng5 = "FORWARD %d, 0x%h";
static int ng6[] = {4, 0};
static unsigned int ng7[] = {36608U, 0U};
static unsigned int ng8[] = {240U, 0U};
static const char *ng9 = "BACKPROP %d, error_out: 0x%h, latched: 0x%h, %d";
static int ng10[] = {3, 0};
static const char *ng11 = "Max: %d";



static void Initial_41_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(41, ng0);

LAB2:    xsi_set_current_line(42, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    xsi_set_current_line(43, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    xsi_set_current_line(44, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 32, 0LL);
    xsi_set_current_line(45, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 3, 0LL);
    xsi_set_current_line(46, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 11, 0LL);
    xsi_set_current_line(47, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    xsi_set_current_line(48, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    xsi_set_current_line(49, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);
    xsi_set_current_line(50, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 3, 0LL);

LAB1:    return;
}

static void Always_53_1(char *t0)
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
    char *t13;
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

LAB0:    t1 = (t0 + 5016U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(53, ng0);

LAB4:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 4824);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(54, ng0);
    t4 = (t0 + 2408);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t7) == 0)
        goto LAB6;

LAB8:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB9:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB11;

LAB10:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 2408);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB11:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB10;

}

static void Initial_58_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(58, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3848);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 1, 0LL);

LAB1:    return;
}

static void Always_59_3(char *t0)
{
    char t6[8];
    char t28[8];
    char t35[8];
    char t43[8];
    char t83[8];
    char t98[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
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
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    int t67;
    int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    char *t81;
    char *t82;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t99;
    char *t100;
    char *t101;
    char *t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    char *t108;
    char *t109;
    char *t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    char *t125;
    char *t126;

LAB0:    t1 = (t0 + 5512U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 6080);
    *((int *)t2) = 1;
    t3 = (t0 + 5544);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(59, ng0);

LAB5:    xsi_set_current_line(60, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 3528);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 11, t5, 32);
    t7 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:
LAB12:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t2) != 0)
        goto LAB15;

LAB16:    t5 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t5);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB17;

LAB18:    memcpy(t43, t6, 8);

LAB19:    t75 = (t43 + 4);
    t76 = *((unsigned int *)t75);
    t77 = (~(t76));
    t78 = *((unsigned int *)t43);
    t79 = (t78 & t77);
    t80 = (t79 != 0);
    if (t80 > 0)
        goto LAB31;

LAB32:
LAB33:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB54;

LAB51:    if (t18 != 0)
        goto LAB53;

LAB52:    *((unsigned int *)t6) = 1;

LAB54:    memset(t28, 0, 8);
    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB55;

LAB56:    if (*((unsigned int *)t8) != 0)
        goto LAB57;

LAB58:    t22 = (t28 + 4);
    t31 = *((unsigned int *)t28);
    t32 = *((unsigned int *)t22);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB59;

LAB60:    memcpy(t83, t28, 8);

LAB61:    t92 = (t83 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t83);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB73;

LAB74:
LAB75:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(63, ng0);
    xsi_vlog_finish(1);
    goto LAB12;

LAB13:    *((unsigned int *)t6) = 1;
    goto LAB16;

LAB15:    t4 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB16;

LAB17:    t7 = (t0 + 2568);
    t8 = (t7 + 56U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng1)));
    memset(t28, 0, 8);
    t29 = (t21 + 4);
    t30 = (t22 + 4);
    t17 = *((unsigned int *)t21);
    t18 = *((unsigned int *)t22);
    t19 = (t17 ^ t18);
    t20 = *((unsigned int *)t29);
    t23 = *((unsigned int *)t30);
    t24 = (t20 ^ t23);
    t25 = (t19 | t24);
    t26 = *((unsigned int *)t29);
    t27 = *((unsigned int *)t30);
    t31 = (t26 | t27);
    t32 = (~(t31));
    t33 = (t25 & t32);
    if (t33 != 0)
        goto LAB23;

LAB20:    if (t31 != 0)
        goto LAB22;

LAB21:    *((unsigned int *)t28) = 1;

LAB23:    memset(t35, 0, 8);
    t36 = (t28 + 4);
    t37 = *((unsigned int *)t36);
    t38 = (~(t37));
    t39 = *((unsigned int *)t28);
    t40 = (t39 & t38);
    t41 = (t40 & 1U);
    if (t41 != 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t36) != 0)
        goto LAB26;

LAB27:    t44 = *((unsigned int *)t6);
    t45 = *((unsigned int *)t35);
    t46 = (t44 & t45);
    *((unsigned int *)t43) = t46;
    t47 = (t6 + 4);
    t48 = (t35 + 4);
    t49 = (t43 + 4);
    t50 = *((unsigned int *)t47);
    t51 = *((unsigned int *)t48);
    t52 = (t50 | t51);
    *((unsigned int *)t49) = t52;
    t53 = *((unsigned int *)t49);
    t54 = (t53 != 0);
    if (t54 == 1)
        goto LAB28;

LAB29:
LAB30:    goto LAB19;

LAB22:    t34 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB23;

LAB24:    *((unsigned int *)t35) = 1;
    goto LAB27;

LAB26:    t42 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t42) = 1;
    goto LAB27;

LAB28:    t55 = *((unsigned int *)t43);
    t56 = *((unsigned int *)t49);
    *((unsigned int *)t43) = (t55 | t56);
    t57 = (t6 + 4);
    t58 = (t35 + 4);
    t59 = *((unsigned int *)t6);
    t60 = (~(t59));
    t61 = *((unsigned int *)t57);
    t62 = (~(t61));
    t63 = *((unsigned int *)t35);
    t64 = (~(t63));
    t65 = *((unsigned int *)t58);
    t66 = (~(t65));
    t67 = (t60 & t62);
    t68 = (t64 & t66);
    t69 = (~(t67));
    t70 = (~(t68));
    t71 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t71 & t69);
    t72 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t72 & t70);
    t73 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t73 & t69);
    t74 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t74 & t70);
    goto LAB30;

LAB31:    xsi_set_current_line(65, ng0);

LAB34:    xsi_set_current_line(66, ng0);
    t81 = ((char*)((ng3)));
    t82 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t82, t81, 0, 0, 1, 0LL);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (~(t9));
    t11 = *((unsigned int *)t4);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB35;

LAB36:
LAB37:    goto LAB33;

LAB35:    xsi_set_current_line(67, ng0);

LAB38:    xsi_set_current_line(68, ng0);
    t7 = (t0 + 3048);
    t8 = (t7 + 56U);
    t21 = *((char **)t8);
    t22 = (t0 + 2888);
    t29 = (t22 + 56U);
    t30 = *((char **)t29);
    xsi_vlogfile_write(1, 0, 0, ng5, 3, t0, (char)118, t21, 3, (char)118, t30, 32);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB40;

LAB39:    t8 = (t5 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB40;

LAB43:    if (*((unsigned int *)t4) < *((unsigned int *)t5))
        goto LAB41;

LAB42:    t22 = (t6 + 4);
    t9 = *((unsigned int *)t22);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB44;

LAB45:
LAB46:    goto LAB37;

LAB40:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB42;

LAB41:    *((unsigned int *)t6) = 1;
    goto LAB42;

LAB44:    xsi_set_current_line(69, ng0);

LAB47:    xsi_set_current_line(70, ng0);
    t29 = (t0 + 3048);
    t30 = (t29 + 56U);
    t34 = *((char **)t30);
    t36 = ((char*)((ng3)));
    memset(t28, 0, 8);
    xsi_vlog_unsigned_add(t28, 32, t34, 3, t36, 32);
    t42 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t42, t28, 0, 0, 3, 0LL);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng7)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 32, 0LL);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 3848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (~(t9));
    t11 = *((unsigned int *)t4);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB48;

LAB49:
LAB50:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB46;

LAB48:    xsi_set_current_line(73, ng0);
    t7 = (t0 + 2888);
    t8 = (t7 + 56U);
    t21 = *((char **)t8);
    t22 = ((char*)((ng8)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 32, t21, 32, t22, 32);
    t29 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t29, t6, 0, 0, 32, 0LL);
    goto LAB50;

LAB53:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB54;

LAB55:    *((unsigned int *)t28) = 1;
    goto LAB58;

LAB57:    t21 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB58;

LAB59:    t29 = (t0 + 2568);
    t30 = (t29 + 56U);
    t34 = *((char **)t30);
    t36 = ((char*)((ng3)));
    memset(t35, 0, 8);
    t42 = (t34 + 4);
    t47 = (t36 + 4);
    t37 = *((unsigned int *)t34);
    t38 = *((unsigned int *)t36);
    t39 = (t37 ^ t38);
    t40 = *((unsigned int *)t42);
    t41 = *((unsigned int *)t47);
    t44 = (t40 ^ t41);
    t45 = (t39 | t44);
    t46 = *((unsigned int *)t42);
    t50 = *((unsigned int *)t47);
    t51 = (t46 | t50);
    t52 = (~(t51));
    t53 = (t45 & t52);
    if (t53 != 0)
        goto LAB65;

LAB62:    if (t51 != 0)
        goto LAB64;

LAB63:    *((unsigned int *)t35) = 1;

LAB65:    memset(t43, 0, 8);
    t49 = (t35 + 4);
    t54 = *((unsigned int *)t49);
    t55 = (~(t54));
    t56 = *((unsigned int *)t35);
    t59 = (t56 & t55);
    t60 = (t59 & 1U);
    if (t60 != 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t49) != 0)
        goto LAB68;

LAB69:    t61 = *((unsigned int *)t28);
    t62 = *((unsigned int *)t43);
    t63 = (t61 & t62);
    *((unsigned int *)t83) = t63;
    t58 = (t28 + 4);
    t75 = (t43 + 4);
    t81 = (t83 + 4);
    t64 = *((unsigned int *)t58);
    t65 = *((unsigned int *)t75);
    t66 = (t64 | t65);
    *((unsigned int *)t81) = t66;
    t69 = *((unsigned int *)t81);
    t70 = (t69 != 0);
    if (t70 == 1)
        goto LAB70;

LAB71:
LAB72:    goto LAB61;

LAB64:    t48 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t48) = 1;
    goto LAB65;

LAB66:    *((unsigned int *)t43) = 1;
    goto LAB69;

LAB68:    t57 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t57) = 1;
    goto LAB69;

LAB70:    t71 = *((unsigned int *)t83);
    t72 = *((unsigned int *)t81);
    *((unsigned int *)t83) = (t71 | t72);
    t82 = (t28 + 4);
    t84 = (t43 + 4);
    t73 = *((unsigned int *)t28);
    t74 = (~(t73));
    t76 = *((unsigned int *)t82);
    t77 = (~(t76));
    t78 = *((unsigned int *)t43);
    t79 = (~(t78));
    t80 = *((unsigned int *)t84);
    t85 = (~(t80));
    t67 = (t74 & t77);
    t68 = (t79 & t85);
    t86 = (~(t67));
    t87 = (~(t68));
    t88 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t88 & t86);
    t89 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t89 & t87);
    t90 = *((unsigned int *)t83);
    *((unsigned int *)t83) = (t90 & t86);
    t91 = *((unsigned int *)t83);
    *((unsigned int *)t83) = (t91 & t87);
    goto LAB72;

LAB73:    xsi_set_current_line(79, ng0);

LAB76:    xsi_set_current_line(81, ng0);
    t99 = (t0 + 2728);
    t100 = (t99 + 56U);
    t101 = *((char **)t100);
    memset(t98, 0, 8);
    t102 = (t101 + 4);
    t103 = *((unsigned int *)t102);
    t104 = (~(t103));
    t105 = *((unsigned int *)t101);
    t106 = (t105 & t104);
    t107 = (t106 & 1U);
    if (t107 != 0)
        goto LAB80;

LAB78:    if (*((unsigned int *)t102) == 0)
        goto LAB77;

LAB79:    t108 = (t98 + 4);
    *((unsigned int *)t98) = 1;
    *((unsigned int *)t108) = 1;

LAB80:    t109 = (t98 + 4);
    t110 = (t101 + 4);
    t111 = *((unsigned int *)t101);
    t112 = (~(t111));
    *((unsigned int *)t98) = t112;
    *((unsigned int *)t109) = 0;
    if (*((unsigned int *)t110) != 0)
        goto LAB82;

LAB81:    t117 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t117 & 1U);
    t118 = *((unsigned int *)t109);
    *((unsigned int *)t109) = (t118 & 1U);
    t119 = (t98 + 4);
    t120 = *((unsigned int *)t119);
    t121 = (~(t120));
    t122 = *((unsigned int *)t98);
    t123 = (t122 & t121);
    t124 = (t123 != 0);
    if (t124 > 0)
        goto LAB83;

LAB84:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    t2 = (t0 + 1208U);
    t4 = *((char **)t2);
    t2 = (t0 + 1688U);
    t5 = *((char **)t2);
    t2 = (t0 + 1648U);
    t7 = (t2 + 72U);
    t8 = *((char **)t7);
    t21 = (t0 + 1648U);
    t22 = (t21 + 48U);
    t29 = *((char **)t22);
    t30 = ((char*)((ng3)));
    xsi_vlog_generic_get_array_select_value(t6, 32, t5, t8, t29, 2, 1, t30, 32, 1);
    t34 = (t0 + 3208);
    t36 = (t34 + 56U);
    t42 = *((char **)t36);
    xsi_vlogfile_write(1, 0, 0, ng9, 5, t0, (char)118, t3, 3, (char)118, t4, 32, (char)118, t6, 32, (char)118, t42, 3);

LAB85:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng10)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB89;

LAB86:    if (t18 != 0)
        goto LAB88;

LAB87:    *((unsigned int *)t6) = 1;

LAB89:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB90;

LAB91:
LAB92:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 3848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (~(t9));
    t11 = *((unsigned int *)t4);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB96;

LAB94:    if (*((unsigned int *)t5) == 0)
        goto LAB93;

LAB95:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;

LAB96:    t8 = (t6 + 4);
    t21 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = (~(t14));
    *((unsigned int *)t6) = t15;
    *((unsigned int *)t8) = 0;
    if (*((unsigned int *)t21) != 0)
        goto LAB98;

LAB97:    t20 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t20 & 1U);
    t23 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t23 & 1U);
    t22 = (t0 + 3848);
    xsi_vlogvar_wait_assign_value(t22, t6, 0, 0, 1, 0LL);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB75;

LAB77:    *((unsigned int *)t98) = 1;
    goto LAB80;

LAB82:    t113 = *((unsigned int *)t98);
    t114 = *((unsigned int *)t110);
    *((unsigned int *)t98) = (t113 | t114);
    t115 = *((unsigned int *)t109);
    t116 = *((unsigned int *)t110);
    *((unsigned int *)t109) = (t115 | t116);
    goto LAB81;

LAB83:    xsi_set_current_line(82, ng0);
    t125 = ((char*)((ng3)));
    t126 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t126, t125, 0, 0, 1, 0LL);
    goto LAB85;

LAB88:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB89;

LAB90:    xsi_set_current_line(86, ng0);
    t21 = ((char*)((ng1)));
    t22 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t22, t21, 0, 0, 1, 0LL);
    goto LAB92;

LAB93:    *((unsigned int *)t6) = 1;
    goto LAB96;

LAB98:    t16 = *((unsigned int *)t6);
    t17 = *((unsigned int *)t21);
    *((unsigned int *)t6) = (t16 | t17);
    t18 = *((unsigned int *)t8);
    t19 = *((unsigned int *)t21);
    *((unsigned int *)t8) = (t18 | t19);
    goto LAB97;

}

static void Always_92_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 5760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 6096);
    *((int *)t2) = 1;
    t3 = (t0 + 5792);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(92, ng0);

LAB5:    xsi_set_current_line(93, ng0);
    t4 = (t0 + 1848U);
    t5 = *((char **)t4);
    xsi_vlogfile_write(1, 0, 0, ng11, 2, t0, (char)118, t5, 3);
    xsi_set_current_line(94, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB2;

}


extern void work_m_00000000000448526118_3063521826_init()
{
	static char *pe[] = {(void *)Initial_41_0,(void *)Always_53_1,(void *)Initial_58_2,(void *)Always_59_3,(void *)Always_92_4};
	xsi_register_didat("work_m_00000000000448526118_3063521826", "isim/softmax_tb_isim_beh.exe.sim/work/m_00000000000448526118_3063521826.didat");
	xsi_register_executes(pe);
}
