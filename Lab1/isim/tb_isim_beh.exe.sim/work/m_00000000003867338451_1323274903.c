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
static const char *ng0 = "C:/Users/CS152B/Desktop/cs152b/Lab1/verilog source files/mux.v";



static void Cont_16_0(char *t0)
{
    char t4[8];
    char t12[8];
    char t47[8];
    char t78[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    int t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    char *t46;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    char *t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    int t70;
    int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    char *t82;
    char *t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    char *t106;
    char *t107;
    char *t108;
    char *t109;
    char *t110;
    unsigned int t111;
    unsigned int t112;
    char *t113;
    unsigned int t114;
    unsigned int t115;
    char *t116;
    unsigned int t117;
    unsigned int t118;
    char *t119;

LAB0:    t1 = (t0 + 2688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(16, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t0 + 1048U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t2) == 0)
        goto LAB4;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;

LAB7:    t13 = *((unsigned int *)t3);
    t14 = *((unsigned int *)t4);
    t15 = (t13 & t14);
    *((unsigned int *)t12) = t15;
    t16 = (t3 + 4);
    t17 = (t4 + 4);
    t18 = (t12 + 4);
    t19 = *((unsigned int *)t16);
    t20 = *((unsigned int *)t17);
    t21 = (t19 | t20);
    *((unsigned int *)t18) = t21;
    t22 = *((unsigned int *)t18);
    t23 = (t22 != 0);
    if (t23 == 1)
        goto LAB8;

LAB9:
LAB10:    t44 = (t0 + 1528U);
    t45 = *((char **)t44);
    t44 = (t0 + 1048U);
    t46 = *((char **)t44);
    t48 = *((unsigned int *)t45);
    t49 = *((unsigned int *)t46);
    t50 = (t48 & t49);
    *((unsigned int *)t47) = t50;
    t44 = (t45 + 4);
    t51 = (t46 + 4);
    t52 = (t47 + 4);
    t53 = *((unsigned int *)t44);
    t54 = *((unsigned int *)t51);
    t55 = (t53 | t54);
    *((unsigned int *)t52) = t55;
    t56 = *((unsigned int *)t52);
    t57 = (t56 != 0);
    if (t57 == 1)
        goto LAB11;

LAB12:
LAB13:    t79 = *((unsigned int *)t12);
    t80 = *((unsigned int *)t47);
    t81 = (t79 | t80);
    *((unsigned int *)t78) = t81;
    t82 = (t12 + 4);
    t83 = (t47 + 4);
    t84 = (t78 + 4);
    t85 = *((unsigned int *)t82);
    t86 = *((unsigned int *)t83);
    t87 = (t85 | t86);
    *((unsigned int *)t84) = t87;
    t88 = *((unsigned int *)t84);
    t89 = (t88 != 0);
    if (t89 == 1)
        goto LAB14;

LAB15:
LAB16:    t106 = (t0 + 3088);
    t107 = (t106 + 56U);
    t108 = *((char **)t107);
    t109 = (t108 + 56U);
    t110 = *((char **)t109);
    memset(t110, 0, 8);
    t111 = 1U;
    t112 = t111;
    t113 = (t78 + 4);
    t114 = *((unsigned int *)t78);
    t111 = (t111 & t114);
    t115 = *((unsigned int *)t113);
    t112 = (t112 & t115);
    t116 = (t110 + 4);
    t117 = *((unsigned int *)t110);
    *((unsigned int *)t110) = (t117 | t111);
    t118 = *((unsigned int *)t116);
    *((unsigned int *)t116) = (t118 | t112);
    xsi_driver_vfirst_trans(t106, 0, 0);
    t119 = (t0 + 3008);
    *((int *)t119) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB8:    t24 = *((unsigned int *)t12);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t12) = (t24 | t25);
    t26 = (t3 + 4);
    t27 = (t4 + 4);
    t28 = *((unsigned int *)t3);
    t29 = (~(t28));
    t30 = *((unsigned int *)t26);
    t31 = (~(t30));
    t32 = *((unsigned int *)t4);
    t33 = (~(t32));
    t34 = *((unsigned int *)t27);
    t35 = (~(t34));
    t36 = (t29 & t31);
    t37 = (t33 & t35);
    t38 = (~(t36));
    t39 = (~(t37));
    t40 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t40 & t38);
    t41 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t41 & t39);
    t42 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t42 & t38);
    t43 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t43 & t39);
    goto LAB10;

LAB11:    t58 = *((unsigned int *)t47);
    t59 = *((unsigned int *)t52);
    *((unsigned int *)t47) = (t58 | t59);
    t60 = (t45 + 4);
    t61 = (t46 + 4);
    t62 = *((unsigned int *)t45);
    t63 = (~(t62));
    t64 = *((unsigned int *)t60);
    t65 = (~(t64));
    t66 = *((unsigned int *)t46);
    t67 = (~(t66));
    t68 = *((unsigned int *)t61);
    t69 = (~(t68));
    t70 = (t63 & t65);
    t71 = (t67 & t69);
    t72 = (~(t70));
    t73 = (~(t71));
    t74 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t74 & t72);
    t75 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t75 & t73);
    t76 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t76 & t72);
    t77 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t77 & t73);
    goto LAB13;

LAB14:    t90 = *((unsigned int *)t78);
    t91 = *((unsigned int *)t84);
    *((unsigned int *)t78) = (t90 | t91);
    t92 = (t12 + 4);
    t93 = (t47 + 4);
    t94 = *((unsigned int *)t92);
    t95 = (~(t94));
    t96 = *((unsigned int *)t12);
    t97 = (t96 & t95);
    t98 = *((unsigned int *)t93);
    t99 = (~(t98));
    t100 = *((unsigned int *)t47);
    t101 = (t100 & t99);
    t102 = (~(t97));
    t103 = (~(t101));
    t104 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t104 & t102);
    t105 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t105 & t103);
    goto LAB16;

}


extern void work_m_00000000003867338451_1323274903_init()
{
	static char *pe[] = {(void *)Cont_16_0};
	xsi_register_didat("work_m_00000000003867338451_1323274903", "isim/tb_isim_beh.exe.sim/work/m_00000000003867338451_1323274903.didat");
	xsi_register_executes(pe);
}
