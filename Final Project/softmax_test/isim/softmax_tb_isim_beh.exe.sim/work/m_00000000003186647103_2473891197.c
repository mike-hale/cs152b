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
static const char *ng0 = "C:/Users/CS152B/Desktop/cs152b/Final Project/fixed_point_calc/verilog_source_code/fadd.v";
static int ng1[] = {30, 0};
static int ng2[] = {0, 0};
static int ng3[] = {31, 0};
static int ng4[] = {1, 0};



static void Cont_34_0(char *t0)
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
    char *t10;

LAB0:    t1 = (t0 + 2960U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 2040);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3624);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t4, 8);
    xsi_driver_vfirst_trans(t5, 0, 31);
    t10 = (t0 + 3528);
    *((int *)t10) = 1;

LAB1:    return;
}

static void Always_36_1(char *t0)
{
    char t6[8];
    char t16[8];
    char t24[8];
    char t46[8];
    char t56[8];
    char t66[8];
    char t68[8];
    char t69[8];
    char t70[8];
    char t132[8];
    char t142[8];
    char t152[8];
    char t162[8];
    char t164[8];
    char t165[8];
    char t166[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t57;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t67;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    unsigned int t77;
    int t78;
    char *t79;
    unsigned int t80;
    int t81;
    int t82;
    char *t83;
    unsigned int t84;
    int t85;
    int t86;
    unsigned int t87;
    int t88;
    unsigned int t89;
    unsigned int t90;
    int t91;
    int t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    char *t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    char *t114;
    char *t115;
    char *t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    char *t123;
    char *t124;
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t133;
    char *t134;
    char *t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    char *t143;
    char *t144;
    char *t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    char *t153;
    char *t154;
    char *t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    char *t163;
    char *t167;
    char *t168;
    char *t169;
    char *t170;
    char *t171;
    char *t172;
    unsigned int t173;
    char *t174;
    unsigned int t175;
    char *t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    int t181;
    int t182;

LAB0:    t1 = (t0 + 3208U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 3544);
    *((int *)t2) = 1;
    t3 = (t0 + 3240);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(36, ng0);

LAB5:    xsi_set_current_line(38, ng0);
    t4 = (t0 + 1320U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 31);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 31);
    t13 = (t12 & 1);
    *((unsigned int *)t4) = t13;
    t14 = (t0 + 1480U);
    t15 = *((char **)t14);
    memset(t16, 0, 8);
    t14 = (t16 + 4);
    t17 = (t15 + 4);
    t18 = *((unsigned int *)t15);
    t19 = (t18 >> 31);
    t20 = (t19 & 1);
    *((unsigned int *)t16) = t20;
    t21 = *((unsigned int *)t17);
    t22 = (t21 >> 31);
    t23 = (t22 & 1);
    *((unsigned int *)t14) = t23;
    memset(t24, 0, 8);
    t25 = (t6 + 4);
    t26 = (t16 + 4);
    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t16);
    t29 = (t27 ^ t28);
    t30 = *((unsigned int *)t25);
    t31 = *((unsigned int *)t26);
    t32 = (t30 ^ t31);
    t33 = (t29 | t32);
    t34 = *((unsigned int *)t25);
    t35 = *((unsigned int *)t26);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB9;

LAB6:    if (t36 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t24) = 1;

LAB9:    t40 = (t24 + 4);
    t41 = *((unsigned int *)t40);
    t42 = (~(t41));
    t43 = *((unsigned int *)t24);
    t44 = (t43 & t42);
    t45 = (t44 != 0);
    if (t45 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 1320U);
    t3 = *((char **)t2);
    t2 = (t0 + 1280U);
    t4 = (t2 + 72U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng3)));
    xsi_vlog_generic_get_index_select_value(t6, 32, t3, t5, 2, t7, 32, 1);
    t14 = ((char*)((ng2)));
    memset(t16, 0, 8);
    t15 = (t6 + 4);
    t17 = (t14 + 4);
    t8 = *((unsigned int *)t6);
    t9 = *((unsigned int *)t14);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t15);
    t12 = *((unsigned int *)t17);
    t13 = (t11 ^ t12);
    t18 = (t10 | t13);
    t19 = *((unsigned int *)t15);
    t20 = *((unsigned int *)t17);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB21;

LAB18:    if (t21 != 0)
        goto LAB20;

LAB19:    *((unsigned int *)t16) = 1;

LAB21:    memset(t24, 0, 8);
    t26 = (t16 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t16);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t26) != 0)
        goto LAB24;

LAB25:    t40 = (t24 + 4);
    t32 = *((unsigned int *)t24);
    t33 = *((unsigned int *)t40);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB26;

LAB27:    memcpy(t68, t24, 8);

LAB28:    t108 = (t68 + 4);
    t109 = *((unsigned int *)t108);
    t110 = (~(t109));
    t111 = *((unsigned int *)t68);
    t112 = (t111 & t110);
    t113 = (t112 != 0);
    if (t113 > 0)
        goto LAB40;

LAB41:    xsi_set_current_line(58, ng0);

LAB71:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 1320U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 0);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t12 & 2147483647U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 2147483647U);
    t5 = (t0 + 1480U);
    t7 = *((char **)t5);
    memset(t16, 0, 8);
    t5 = (t16 + 4);
    t14 = (t7 + 4);
    t18 = *((unsigned int *)t7);
    t19 = (t18 >> 0);
    *((unsigned int *)t16) = t19;
    t20 = *((unsigned int *)t14);
    t21 = (t20 >> 0);
    *((unsigned int *)t5) = t21;
    t22 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t22 & 2147483647U);
    t23 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t23 & 2147483647U);
    memset(t24, 0, 8);
    t15 = (t6 + 4);
    if (*((unsigned int *)t15) != 0)
        goto LAB73;

LAB72:    t17 = (t16 + 4);
    if (*((unsigned int *)t17) != 0)
        goto LAB73;

LAB76:    if (*((unsigned int *)t6) > *((unsigned int *)t16))
        goto LAB74;

LAB75:    t26 = (t24 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t24);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB77;

LAB78:    xsi_set_current_line(66, ng0);

LAB94:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 0);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t12 & 2147483647U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 2147483647U);
    t5 = (t0 + 1320U);
    t7 = *((char **)t5);
    memset(t16, 0, 8);
    t5 = (t16 + 4);
    t14 = (t7 + 4);
    t18 = *((unsigned int *)t7);
    t19 = (t18 >> 0);
    *((unsigned int *)t16) = t19;
    t20 = *((unsigned int *)t14);
    t21 = (t20 >> 0);
    *((unsigned int *)t5) = t21;
    t22 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t22 & 2147483647U);
    t23 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t23 & 2147483647U);
    memset(t24, 0, 8);
    xsi_vlog_unsigned_minus(t24, 31, t6, 31, t16, 31);
    t15 = (t0 + 2040);
    t17 = (t0 + 2040);
    t25 = (t17 + 72U);
    t26 = *((char **)t25);
    t39 = ((char*)((ng1)));
    t40 = ((char*)((ng2)));
    xsi_vlog_convert_partindices(t46, t56, t66, ((int*)(t26)), 2, t39, 32, 1, t40, 32, 1);
    t47 = (t46 + 4);
    t27 = *((unsigned int *)t47);
    t78 = (!(t27));
    t48 = (t56 + 4);
    t28 = *((unsigned int *)t48);
    t81 = (!(t28));
    t82 = (t78 && t81);
    t49 = (t66 + 4);
    t29 = *((unsigned int *)t49);
    t85 = (!(t29));
    t86 = (t82 && t85);
    if (t86 == 1)
        goto LAB95;

LAB96:    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2040);
    t4 = (t0 + 2040);
    t5 = (t4 + 72U);
    t7 = *((char **)t5);
    t14 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t6, t7, 2, t14, 32, 1);
    t15 = (t6 + 4);
    t8 = *((unsigned int *)t15);
    t78 = (!(t8));
    if (t78 == 1)
        goto LAB97;

LAB98:
LAB79:
LAB42:
LAB12:    goto LAB2;

LAB8:    t39 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(38, ng0);

LAB13:    xsi_set_current_line(39, ng0);
    t47 = (t0 + 1320U);
    t48 = *((char **)t47);
    memset(t46, 0, 8);
    t47 = (t46 + 4);
    t49 = (t48 + 4);
    t50 = *((unsigned int *)t48);
    t51 = (t50 >> 0);
    *((unsigned int *)t46) = t51;
    t52 = *((unsigned int *)t49);
    t53 = (t52 >> 0);
    *((unsigned int *)t47) = t53;
    t54 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t54 & 2147483647U);
    t55 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t55 & 2147483647U);
    t57 = (t0 + 1480U);
    t58 = *((char **)t57);
    memset(t56, 0, 8);
    t57 = (t56 + 4);
    t59 = (t58 + 4);
    t60 = *((unsigned int *)t58);
    t61 = (t60 >> 0);
    *((unsigned int *)t56) = t61;
    t62 = *((unsigned int *)t59);
    t63 = (t62 >> 0);
    *((unsigned int *)t57) = t63;
    t64 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t64 & 2147483647U);
    t65 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t65 & 2147483647U);
    memset(t66, 0, 8);
    xsi_vlog_unsigned_add(t66, 31, t46, 31, t56, 31);
    t67 = (t0 + 2040);
    t71 = (t0 + 2040);
    t72 = (t71 + 72U);
    t73 = *((char **)t72);
    t74 = ((char*)((ng1)));
    t75 = ((char*)((ng2)));
    xsi_vlog_convert_partindices(t68, t69, t70, ((int*)(t73)), 2, t74, 32, 1, t75, 32, 1);
    t76 = (t68 + 4);
    t77 = *((unsigned int *)t76);
    t78 = (!(t77));
    t79 = (t69 + 4);
    t80 = *((unsigned int *)t79);
    t81 = (!(t80));
    t82 = (t78 && t81);
    t83 = (t70 + 4);
    t84 = *((unsigned int *)t83);
    t85 = (!(t84));
    t86 = (t82 && t85);
    if (t86 == 1)
        goto LAB14;

LAB15:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1320U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 31);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 31);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t5 = (t0 + 2040);
    t7 = (t0 + 2040);
    t14 = (t7 + 72U);
    t15 = *((char **)t14);
    t17 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t16, t15, 2, t17, 32, 1);
    t25 = (t16 + 4);
    t18 = *((unsigned int *)t25);
    t78 = (!(t18));
    if (t78 == 1)
        goto LAB16;

LAB17:    goto LAB12;

LAB14:    t87 = *((unsigned int *)t70);
    t88 = (t87 + 0);
    t89 = *((unsigned int *)t68);
    t90 = *((unsigned int *)t69);
    t91 = (t89 - t90);
    t92 = (t91 + 1);
    xsi_vlogvar_assign_value(t67, t66, t88, *((unsigned int *)t69), t92);
    goto LAB15;

LAB16:    xsi_vlogvar_assign_value(t5, t6, 0, *((unsigned int *)t16), 1);
    goto LAB17;

LAB20:    t25 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB21;

LAB22:    *((unsigned int *)t24) = 1;
    goto LAB25;

LAB24:    t39 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB25;

LAB26:    t47 = (t0 + 1480U);
    t48 = *((char **)t47);
    t47 = (t0 + 1440U);
    t49 = (t47 + 72U);
    t57 = *((char **)t49);
    t58 = ((char*)((ng3)));
    xsi_vlog_generic_get_index_select_value(t46, 32, t48, t57, 2, t58, 32, 1);
    t59 = ((char*)((ng4)));
    memset(t56, 0, 8);
    t67 = (t46 + 4);
    t71 = (t59 + 4);
    t35 = *((unsigned int *)t46);
    t36 = *((unsigned int *)t59);
    t37 = (t35 ^ t36);
    t38 = *((unsigned int *)t67);
    t41 = *((unsigned int *)t71);
    t42 = (t38 ^ t41);
    t43 = (t37 | t42);
    t44 = *((unsigned int *)t67);
    t45 = *((unsigned int *)t71);
    t50 = (t44 | t45);
    t51 = (~(t50));
    t52 = (t43 & t51);
    if (t52 != 0)
        goto LAB32;

LAB29:    if (t50 != 0)
        goto LAB31;

LAB30:    *((unsigned int *)t56) = 1;

LAB32:    memset(t66, 0, 8);
    t73 = (t56 + 4);
    t53 = *((unsigned int *)t73);
    t54 = (~(t53));
    t55 = *((unsigned int *)t56);
    t60 = (t55 & t54);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t73) != 0)
        goto LAB35;

LAB36:    t62 = *((unsigned int *)t24);
    t63 = *((unsigned int *)t66);
    t64 = (t62 & t63);
    *((unsigned int *)t68) = t64;
    t75 = (t24 + 4);
    t76 = (t66 + 4);
    t79 = (t68 + 4);
    t65 = *((unsigned int *)t75);
    t77 = *((unsigned int *)t76);
    t80 = (t65 | t77);
    *((unsigned int *)t79) = t80;
    t84 = *((unsigned int *)t79);
    t87 = (t84 != 0);
    if (t87 == 1)
        goto LAB37;

LAB38:
LAB39:    goto LAB28;

LAB31:    t72 = (t56 + 4);
    *((unsigned int *)t56) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB32;

LAB33:    *((unsigned int *)t66) = 1;
    goto LAB36;

LAB35:    t74 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t74) = 1;
    goto LAB36;

LAB37:    t89 = *((unsigned int *)t68);
    t90 = *((unsigned int *)t79);
    *((unsigned int *)t68) = (t89 | t90);
    t83 = (t24 + 4);
    t93 = (t66 + 4);
    t94 = *((unsigned int *)t24);
    t95 = (~(t94));
    t96 = *((unsigned int *)t83);
    t97 = (~(t96));
    t98 = *((unsigned int *)t66);
    t99 = (~(t98));
    t100 = *((unsigned int *)t93);
    t101 = (~(t100));
    t78 = (t95 & t97);
    t81 = (t99 & t101);
    t102 = (~(t78));
    t103 = (~(t81));
    t104 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t104 & t102);
    t105 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t105 & t103);
    t106 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t106 & t102);
    t107 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t107 & t103);
    goto LAB39;

LAB40:    xsi_set_current_line(45, ng0);

LAB43:    xsi_set_current_line(46, ng0);
    t114 = (t0 + 1320U);
    t115 = *((char **)t114);
    memset(t69, 0, 8);
    t114 = (t69 + 4);
    t116 = (t115 + 4);
    t117 = *((unsigned int *)t115);
    t118 = (t117 >> 0);
    *((unsigned int *)t69) = t118;
    t119 = *((unsigned int *)t116);
    t120 = (t119 >> 0);
    *((unsigned int *)t114) = t120;
    t121 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t121 & 2147483647U);
    t122 = *((unsigned int *)t114);
    *((unsigned int *)t114) = (t122 & 2147483647U);
    t123 = (t0 + 1480U);
    t124 = *((char **)t123);
    memset(t70, 0, 8);
    t123 = (t70 + 4);
    t125 = (t124 + 4);
    t126 = *((unsigned int *)t124);
    t127 = (t126 >> 0);
    *((unsigned int *)t70) = t127;
    t128 = *((unsigned int *)t125);
    t129 = (t128 >> 0);
    *((unsigned int *)t123) = t129;
    t130 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t130 & 2147483647U);
    t131 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t131 & 2147483647U);
    memset(t132, 0, 8);
    t133 = (t69 + 4);
    if (*((unsigned int *)t133) != 0)
        goto LAB45;

LAB44:    t134 = (t70 + 4);
    if (*((unsigned int *)t134) != 0)
        goto LAB45;

LAB48:    if (*((unsigned int *)t69) > *((unsigned int *)t70))
        goto LAB46;

LAB47:    t136 = (t132 + 4);
    t137 = *((unsigned int *)t136);
    t138 = (~(t137));
    t139 = *((unsigned int *)t132);
    t140 = (t139 & t138);
    t141 = (t140 != 0);
    if (t141 > 0)
        goto LAB49;

LAB50:    xsi_set_current_line(50, ng0);

LAB57:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 0);
    *((unsigned int *)t2) = t11;
    t12 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t12 & 2147483647U);
    t13 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t13 & 2147483647U);
    t5 = (t0 + 1320U);
    t7 = *((char **)t5);
    memset(t16, 0, 8);
    t5 = (t16 + 4);
    t14 = (t7 + 4);
    t18 = *((unsigned int *)t7);
    t19 = (t18 >> 0);
    *((unsigned int *)t16) = t19;
    t20 = *((unsigned int *)t14);
    t21 = (t20 >> 0);
    *((unsigned int *)t5) = t21;
    t22 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t22 & 2147483647U);
    t23 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t23 & 2147483647U);
    memset(t24, 0, 8);
    xsi_vlog_unsigned_minus(t24, 31, t6, 31, t16, 31);
    t15 = (t0 + 2040);
    t17 = (t0 + 2040);
    t25 = (t17 + 72U);
    t26 = *((char **)t25);
    t39 = ((char*)((ng1)));
    t40 = ((char*)((ng2)));
    xsi_vlog_convert_partindices(t46, t56, t66, ((int*)(t26)), 2, t39, 32, 1, t40, 32, 1);
    t47 = (t46 + 4);
    t27 = *((unsigned int *)t47);
    t78 = (!(t27));
    t48 = (t56 + 4);
    t28 = *((unsigned int *)t48);
    t81 = (!(t28));
    t82 = (t78 && t81);
    t49 = (t66 + 4);
    t29 = *((unsigned int *)t49);
    t85 = (!(t29));
    t86 = (t82 && t85);
    if (t86 == 1)
        goto LAB58;

LAB59:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 2040);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t12 & 2147483647U);
    t13 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t13 & 2147483647U);
    t14 = ((char*)((ng2)));
    memset(t16, 0, 8);
    t15 = (t6 + 4);
    t17 = (t14 + 4);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t14);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t15);
    t22 = *((unsigned int *)t17);
    t23 = (t21 ^ t22);
    t27 = (t20 | t23);
    t28 = *((unsigned int *)t15);
    t29 = *((unsigned int *)t17);
    t30 = (t28 | t29);
    t31 = (~(t30));
    t32 = (t27 & t31);
    if (t32 != 0)
        goto LAB63;

LAB60:    if (t30 != 0)
        goto LAB62;

LAB61:    *((unsigned int *)t16) = 1;

LAB63:    t26 = (t16 + 4);
    t33 = *((unsigned int *)t26);
    t34 = (~(t33));
    t35 = *((unsigned int *)t16);
    t36 = (t35 & t34);
    t37 = (t36 != 0);
    if (t37 > 0)
        goto LAB64;

LAB65:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2040);
    t4 = (t0 + 2040);
    t5 = (t4 + 72U);
    t7 = *((char **)t5);
    t14 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t6, t7, 2, t14, 32, 1);
    t15 = (t6 + 4);
    t8 = *((unsigned int *)t15);
    t78 = (!(t8));
    if (t78 == 1)
        goto LAB69;

LAB70:
LAB66:
LAB51:    goto LAB42;

LAB45:    t135 = (t132 + 4);
    *((unsigned int *)t132) = 1;
    *((unsigned int *)t135) = 1;
    goto LAB47;

LAB46:    *((unsigned int *)t132) = 1;
    goto LAB47;

LAB49:    xsi_set_current_line(46, ng0);

LAB52:    xsi_set_current_line(47, ng0);
    t143 = (t0 + 1320U);
    t144 = *((char **)t143);
    memset(t142, 0, 8);
    t143 = (t142 + 4);
    t145 = (t144 + 4);
    t146 = *((unsigned int *)t144);
    t147 = (t146 >> 0);
    *((unsigned int *)t142) = t147;
    t148 = *((unsigned int *)t145);
    t149 = (t148 >> 0);
    *((unsigned int *)t143) = t149;
    t150 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t150 & 2147483647U);
    t151 = *((unsigned int *)t143);
    *((unsigned int *)t143) = (t151 & 2147483647U);
    t153 = (t0 + 1480U);
    t154 = *((char **)t153);
    memset(t152, 0, 8);
    t153 = (t152 + 4);
    t155 = (t154 + 4);
    t156 = *((unsigned int *)t154);
    t157 = (t156 >> 0);
    *((unsigned int *)t152) = t157;
    t158 = *((unsigned int *)t155);
    t159 = (t158 >> 0);
    *((unsigned int *)t153) = t159;
    t160 = *((unsigned int *)t152);
    *((unsigned int *)t152) = (t160 & 2147483647U);
    t161 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t161 & 2147483647U);
    memset(t162, 0, 8);
    xsi_vlog_unsigned_minus(t162, 31, t142, 31, t152, 31);
    t163 = (t0 + 2040);
    t167 = (t0 + 2040);
    t168 = (t167 + 72U);
    t169 = *((char **)t168);
    t170 = ((char*)((ng1)));
    t171 = ((char*)((ng2)));
    xsi_vlog_convert_partindices(t164, t165, t166, ((int*)(t169)), 2, t170, 32, 1, t171, 32, 1);
    t172 = (t164 + 4);
    t173 = *((unsigned int *)t172);
    t82 = (!(t173));
    t174 = (t165 + 4);
    t175 = *((unsigned int *)t174);
    t85 = (!(t175));
    t86 = (t82 && t85);
    t176 = (t166 + 4);
    t177 = *((unsigned int *)t176);
    t88 = (!(t177));
    t91 = (t86 && t88);
    if (t91 == 1)
        goto LAB53;

LAB54:    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2040);
    t4 = (t0 + 2040);
    t5 = (t4 + 72U);
    t7 = *((char **)t5);
    t14 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t6, t7, 2, t14, 32, 1);
    t15 = (t6 + 4);
    t8 = *((unsigned int *)t15);
    t78 = (!(t8));
    if (t78 == 1)
        goto LAB55;

LAB56:    goto LAB51;

LAB53:    t178 = *((unsigned int *)t166);
    t92 = (t178 + 0);
    t179 = *((unsigned int *)t164);
    t180 = *((unsigned int *)t165);
    t181 = (t179 - t180);
    t182 = (t181 + 1);
    xsi_vlogvar_assign_value(t163, t162, t92, *((unsigned int *)t165), t182);
    goto LAB54;

LAB55:    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t6), 1);
    goto LAB56;

LAB58:    t30 = *((unsigned int *)t66);
    t88 = (t30 + 0);
    t31 = *((unsigned int *)t46);
    t32 = *((unsigned int *)t56);
    t91 = (t31 - t32);
    t92 = (t91 + 1);
    xsi_vlogvar_assign_value(t15, t24, t88, *((unsigned int *)t56), t92);
    goto LAB59;

LAB62:    t25 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB63;

LAB64:    xsi_set_current_line(53, ng0);
    t39 = ((char*)((ng2)));
    t40 = (t0 + 2040);
    t47 = (t0 + 2040);
    t48 = (t47 + 72U);
    t49 = *((char **)t48);
    t57 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t24, t49, 2, t57, 32, 1);
    t58 = (t24 + 4);
    t38 = *((unsigned int *)t58);
    t78 = (!(t38));
    if (t78 == 1)
        goto LAB67;

LAB68:    goto LAB66;

LAB67:    xsi_vlogvar_assign_value(t40, t39, 0, *((unsigned int *)t24), 1);
    goto LAB68;

LAB69:    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t6), 1);
    goto LAB70;

LAB73:    t25 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB75;

LAB74:    *((unsigned int *)t24) = 1;
    goto LAB75;

LAB77:    xsi_set_current_line(59, ng0);

LAB80:    xsi_set_current_line(60, ng0);
    t39 = (t0 + 1320U);
    t40 = *((char **)t39);
    memset(t46, 0, 8);
    t39 = (t46 + 4);
    t47 = (t40 + 4);
    t32 = *((unsigned int *)t40);
    t33 = (t32 >> 0);
    *((unsigned int *)t46) = t33;
    t34 = *((unsigned int *)t47);
    t35 = (t34 >> 0);
    *((unsigned int *)t39) = t35;
    t36 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t36 & 2147483647U);
    t37 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t37 & 2147483647U);
    t48 = (t0 + 1480U);
    t49 = *((char **)t48);
    memset(t56, 0, 8);
    t48 = (t56 + 4);
    t57 = (t49 + 4);
    t38 = *((unsigned int *)t49);
    t41 = (t38 >> 0);
    *((unsigned int *)t56) = t41;
    t42 = *((unsigned int *)t57);
    t43 = (t42 >> 0);
    *((unsigned int *)t48) = t43;
    t44 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t44 & 2147483647U);
    t45 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t45 & 2147483647U);
    memset(t66, 0, 8);
    xsi_vlog_unsigned_minus(t66, 31, t46, 31, t56, 31);
    t58 = (t0 + 2040);
    t59 = (t0 + 2040);
    t67 = (t59 + 72U);
    t71 = *((char **)t67);
    t72 = ((char*)((ng1)));
    t73 = ((char*)((ng2)));
    xsi_vlog_convert_partindices(t68, t69, t70, ((int*)(t71)), 2, t72, 32, 1, t73, 32, 1);
    t74 = (t68 + 4);
    t50 = *((unsigned int *)t74);
    t78 = (!(t50));
    t75 = (t69 + 4);
    t51 = *((unsigned int *)t75);
    t81 = (!(t51));
    t82 = (t78 && t81);
    t76 = (t70 + 4);
    t52 = *((unsigned int *)t76);
    t85 = (!(t52));
    t86 = (t82 && t85);
    if (t86 == 1)
        goto LAB81;

LAB82:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2040);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t5) = t11;
    t12 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t12 & 2147483647U);
    t13 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t13 & 2147483647U);
    t14 = ((char*)((ng2)));
    memset(t16, 0, 8);
    t15 = (t6 + 4);
    t17 = (t14 + 4);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t14);
    t20 = (t18 ^ t19);
    t21 = *((unsigned int *)t15);
    t22 = *((unsigned int *)t17);
    t23 = (t21 ^ t22);
    t27 = (t20 | t23);
    t28 = *((unsigned int *)t15);
    t29 = *((unsigned int *)t17);
    t30 = (t28 | t29);
    t31 = (~(t30));
    t32 = (t27 & t31);
    if (t32 != 0)
        goto LAB86;

LAB83:    if (t30 != 0)
        goto LAB85;

LAB84:    *((unsigned int *)t16) = 1;

LAB86:    t26 = (t16 + 4);
    t33 = *((unsigned int *)t26);
    t34 = (~(t33));
    t35 = *((unsigned int *)t16);
    t36 = (t35 & t34);
    t37 = (t36 != 0);
    if (t37 > 0)
        goto LAB87;

LAB88:    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2040);
    t4 = (t0 + 2040);
    t5 = (t4 + 72U);
    t7 = *((char **)t5);
    t14 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t6, t7, 2, t14, 32, 1);
    t15 = (t6 + 4);
    t8 = *((unsigned int *)t15);
    t78 = (!(t8));
    if (t78 == 1)
        goto LAB92;

LAB93:
LAB89:    goto LAB79;

LAB81:    t53 = *((unsigned int *)t70);
    t88 = (t53 + 0);
    t54 = *((unsigned int *)t68);
    t55 = *((unsigned int *)t69);
    t91 = (t54 - t55);
    t92 = (t91 + 1);
    xsi_vlogvar_assign_value(t58, t66, t88, *((unsigned int *)t69), t92);
    goto LAB82;

LAB85:    t25 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB86;

LAB87:    xsi_set_current_line(62, ng0);
    t39 = ((char*)((ng2)));
    t40 = (t0 + 2040);
    t47 = (t0 + 2040);
    t48 = (t47 + 72U);
    t49 = *((char **)t48);
    t57 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t24, t49, 2, t57, 32, 1);
    t58 = (t24 + 4);
    t38 = *((unsigned int *)t58);
    t78 = (!(t38));
    if (t78 == 1)
        goto LAB90;

LAB91:    goto LAB89;

LAB90:    xsi_vlogvar_assign_value(t40, t39, 0, *((unsigned int *)t24), 1);
    goto LAB91;

LAB92:    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t6), 1);
    goto LAB93;

LAB95:    t30 = *((unsigned int *)t66);
    t88 = (t30 + 0);
    t31 = *((unsigned int *)t46);
    t32 = *((unsigned int *)t56);
    t91 = (t31 - t32);
    t92 = (t91 + 1);
    xsi_vlogvar_assign_value(t15, t24, t88, *((unsigned int *)t56), t92);
    goto LAB96;

LAB97:    xsi_vlogvar_assign_value(t3, t2, 0, *((unsigned int *)t6), 1);
    goto LAB98;

}


extern void work_m_00000000003186647103_2473891197_init()
{
	static char *pe[] = {(void *)Cont_34_0,(void *)Always_36_1};
	xsi_register_didat("work_m_00000000003186647103_2473891197", "isim/softmax_tb_isim_beh.exe.sim/work/m_00000000003186647103_2473891197.didat");
	xsi_register_executes(pe);
}
