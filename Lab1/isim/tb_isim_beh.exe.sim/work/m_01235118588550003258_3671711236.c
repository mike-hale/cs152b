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

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/ise/Michael/Documents/Senior Year 18/CS 152B/cs152b/Lab1/tb.v";
static int ng1[] = {1, 0};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {0U, 0U, 0U, 0U};
static const char *ng5 = "Test cases for the register file:";
static unsigned int ng6[] = {21930U, 0U};
static int ng7[] = {32, 0};
static int ng8[] = {16, 0};
static int ng9[] = {2, 0};
static const char *ng10 = "Reading register %d...";
static const char *ng11 = "Success";
static const char *ng12 = "Fail (0x%x)";
static unsigned int ng13[] = {15U, 0U};
static unsigned int ng14[] = {19U, 0U};
static unsigned int ng15[] = {1U, 0U};
static unsigned int ng16[] = {34U, 0U};
static const char *ng17 = "Adder Pass 1";
static const char *ng18 = "Adder Fail 1 (15 + 19 = %d)";
static unsigned int ng19[] = {43605U, 0U};
static unsigned int ng20[] = {2U, 0U};
static unsigned int ng21[] = {65535U, 0U};
static const char *ng22 = "OR Pass 1";
static const char *ng23 = "OR Fail 1 (0x55AA | 0xAA55 = 0x%x)";
static unsigned int ng24[] = {3U, 0U};
static const char *ng25 = "AND Pass 1";
static const char *ng26 = "AND Fail 1 (0x55AA & 0xAA55 = 0x%x)";
static unsigned int ng27[] = {255U, 0U};
static unsigned int ng28[] = {170U, 0U};
static const char *ng29 = "AND Pass 2";
static const char *ng30 = "AND Fail 2 (0x55AA & 0x00FF = 0x%x)";
static unsigned int ng31[] = {4U, 0U};
static unsigned int ng32[] = {21931U, 0U};
static const char *ng33 = "INC Pass 1";
static const char *ng34 = "INC Fail 1 (0x55AA++ = 0x%x)";
static const char *ng35 = "INC Pass 2";
static const char *ng36 = "INC Fail 2 (0xFFFF++ = 0x%x)";



static void Initial_33_0(char *t0)
{
    char t6[8];
    char t18[8];
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
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;

LAB0:    t1 = (t0 + 4440U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);

LAB4:    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(35, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(36, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    t4 = (t0 + 2568);
    xsi_vlogvar_assign_value(t4, t2, 5, 0, 5);
    t5 = (t0 + 2408);
    xsi_vlogvar_assign_value(t5, t2, 10, 0, 5);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    t4 = (t0 + 3208);
    xsi_vlogvar_assign_value(t4, t2, 16, 0, 16);
    t5 = (t0 + 3048);
    xsi_vlogvar_assign_value(t5, t2, 32, 0, 16);
    xsi_set_current_line(40, ng0);
    xsi_vlogfile_write(1, 0, 0, ng5, 1, t0);
    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(42, ng0);
    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB5:    t2 = (t0 + 3528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng7)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(48, ng0);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB11:    t2 = (t0 + 3528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng8)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB12;

LAB13:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB35;

LAB1:    return;
LAB6:    xsi_set_current_line(42, ng0);

LAB8:    xsi_set_current_line(44, ng0);
    t13 = (t0 + 4248);
    xsi_process_wait(t13, 10000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(44, ng0);
    t14 = (t0 + 3528);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t0 + 2728);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 5);
    xsi_set_current_line(45, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(46, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(46, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 2248);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 3528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB5;

LAB12:    xsi_set_current_line(48, ng0);

LAB14:    xsi_set_current_line(50, ng0);
    t13 = (t0 + 4248);
    xsi_process_wait(t13, 10000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(50, ng0);
    t14 = ((char*)((ng9)));
    t15 = (t0 + 3528);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t18, 0, 8);
    xsi_vlog_signed_multiply(t18, 32, t14, 32, t17, 32);
    t19 = (t0 + 2408);
    xsi_vlogvar_assign_value(t19, t18, 0, 0, 5);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 3528);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    xsi_vlog_signed_multiply(t6, 32, t2, 32, t5, 32);
    t7 = ((char*)((ng1)));
    memset(t18, 0, 8);
    xsi_vlog_signed_add(t18, 32, t6, 32, t7, 32);
    t13 = (t0 + 2568);
    xsi_vlogvar_assign_value(t13, t18, 0, 0, 5);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB16:    xsi_set_current_line(53, ng0);
    t3 = (t0 + 2408);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    xsi_vlogfile_write(0, 0, 1, ng10, 2, t0, (char)118, t5, 5);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t20 = (t11 ^ t12);
    t21 = (t10 | t20);
    t22 = *((unsigned int *)t4);
    t23 = *((unsigned int *)t5);
    t24 = (t22 | t23);
    t25 = (~(t24));
    t26 = (t21 & t25);
    if (t26 != 0)
        goto LAB20;

LAB17:    if (t24 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t6) = 1;

LAB20:    t13 = (t6 + 4);
    t27 = *((unsigned int *)t13);
    t28 = (~(t27));
    t29 = *((unsigned int *)t6);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(56, ng0);

LAB25:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng12, 2, t0, (char)118, t3, 16);

LAB23:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(0, 0, 1, ng10, 2, t0, (char)118, t4, 5);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t20 = (t11 ^ t12);
    t21 = (t10 | t20);
    t22 = *((unsigned int *)t4);
    t23 = *((unsigned int *)t5);
    t24 = (t22 | t23);
    t25 = (~(t24));
    t26 = (t21 & t25);
    if (t26 != 0)
        goto LAB29;

LAB26:    if (t24 != 0)
        goto LAB28;

LAB27:    *((unsigned int *)t6) = 1;

LAB29:    t13 = (t6 + 4);
    t27 = *((unsigned int *)t13);
    t28 = (~(t27));
    t29 = *((unsigned int *)t6);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB30;

LAB31:    xsi_set_current_line(62, ng0);

LAB34:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng12, 2, t0, (char)118, t3, 16);

LAB32:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 3528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 3528);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB11;

LAB19:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB20;

LAB21:    xsi_set_current_line(54, ng0);

LAB24:    xsi_set_current_line(55, ng0);
    xsi_vlogfile_write(1, 0, 0, ng11, 1, t0);
    goto LAB23;

LAB28:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB29;

LAB30:    xsi_set_current_line(60, ng0);

LAB33:    xsi_set_current_line(61, ng0);
    xsi_vlogfile_write(1, 0, 0, ng11, 1, t0);
    goto LAB32;

LAB35:    xsi_set_current_line(68, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 2088);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB36;
    goto LAB1;

LAB36:    xsi_set_current_line(69, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 2088);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 20000LL);
    *((char **)t1) = &&LAB37;
    goto LAB1;

LAB37:    xsi_set_current_line(76, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng16)));
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = (t3 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t3);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t7);
    t20 = (t11 ^ t12);
    t21 = (t10 | t20);
    t22 = *((unsigned int *)t5);
    t23 = *((unsigned int *)t7);
    t24 = (t22 | t23);
    t25 = (~(t24));
    t26 = (t21 & t25);
    if (t26 != 0)
        goto LAB41;

LAB38:    if (t24 != 0)
        goto LAB40;

LAB39:    *((unsigned int *)t6) = 1;

LAB41:    t14 = (t6 + 4);
    t27 = *((unsigned int *)t14);
    t28 = (~(t27));
    t29 = *((unsigned int *)t6);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB42;

LAB43:    xsi_set_current_line(78, ng0);

LAB46:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng18, 2, t0, (char)118, t3, 16);

LAB44:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 20000LL);
    *((char **)t1) = &&LAB47;
    goto LAB1;

LAB40:    t13 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB41;

LAB42:    xsi_set_current_line(76, ng0);

LAB45:    xsi_set_current_line(77, ng0);
    xsi_vlogfile_write(1, 0, 0, ng17, 1, t0);
    goto LAB44;

LAB47:    xsi_set_current_line(84, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 3208);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB48;
    goto LAB1;

LAB48:    xsi_set_current_line(88, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng21)));
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = (t3 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t3);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t7);
    t20 = (t11 ^ t12);
    t21 = (t10 | t20);
    t22 = *((unsigned int *)t5);
    t23 = *((unsigned int *)t7);
    t24 = (t22 | t23);
    t25 = (~(t24));
    t26 = (t21 & t25);
    if (t26 != 0)
        goto LAB52;

LAB49:    if (t24 != 0)
        goto LAB51;

LAB50:    *((unsigned int *)t6) = 1;

LAB52:    t14 = (t6 + 4);
    t27 = *((unsigned int *)t14);
    t28 = (~(t27));
    t29 = *((unsigned int *)t6);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB53;

LAB54:    xsi_set_current_line(90, ng0);

LAB57:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng23, 2, t0, (char)118, t3, 16);

LAB55:    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB58;
    goto LAB1;

LAB51:    t13 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB52;

LAB53:    xsi_set_current_line(88, ng0);

LAB56:    xsi_set_current_line(89, ng0);
    xsi_vlogfile_write(1, 0, 0, ng22, 1, t0);
    goto LAB55;

LAB58:    xsi_set_current_line(97, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = (t3 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t3);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t7);
    t20 = (t11 ^ t12);
    t21 = (t10 | t20);
    t22 = *((unsigned int *)t5);
    t23 = *((unsigned int *)t7);
    t24 = (t22 | t23);
    t25 = (~(t24));
    t26 = (t21 & t25);
    if (t26 != 0)
        goto LAB62;

LAB59:    if (t24 != 0)
        goto LAB61;

LAB60:    *((unsigned int *)t6) = 1;

LAB62:    t14 = (t6 + 4);
    t27 = *((unsigned int *)t14);
    t28 = (~(t27));
    t29 = *((unsigned int *)t6);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB63;

LAB64:    xsi_set_current_line(99, ng0);

LAB67:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng26, 2, t0, (char)118, t3, 16);

LAB65:    xsi_set_current_line(102, ng0);
    t2 = ((char*)((ng27)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB68;
    goto LAB1;

LAB61:    t13 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB62;

LAB63:    xsi_set_current_line(97, ng0);

LAB66:    xsi_set_current_line(98, ng0);
    xsi_vlogfile_write(1, 0, 0, ng25, 1, t0);
    goto LAB65;

LAB68:    xsi_set_current_line(104, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng28)));
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = (t3 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t3);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t7);
    t20 = (t11 ^ t12);
    t21 = (t10 | t20);
    t22 = *((unsigned int *)t5);
    t23 = *((unsigned int *)t7);
    t24 = (t22 | t23);
    t25 = (~(t24));
    t26 = (t21 & t25);
    if (t26 != 0)
        goto LAB72;

LAB69:    if (t24 != 0)
        goto LAB71;

LAB70:    *((unsigned int *)t6) = 1;

LAB72:    t14 = (t6 + 4);
    t27 = *((unsigned int *)t14);
    t28 = (~(t27));
    t29 = *((unsigned int *)t6);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB73;

LAB74:    xsi_set_current_line(106, ng0);

LAB77:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng30, 2, t0, (char)118, t3, 16);

LAB75:    xsi_set_current_line(109, ng0);
    xsi_vlog_finish(1);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng31)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB78;
    goto LAB1;

LAB71:    t13 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB72;

LAB73:    xsi_set_current_line(104, ng0);

LAB76:    xsi_set_current_line(105, ng0);
    xsi_vlogfile_write(1, 0, 0, ng29, 1, t0);
    goto LAB75;

LAB78:    xsi_set_current_line(114, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng32)));
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = (t3 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t3);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t7);
    t20 = (t11 ^ t12);
    t21 = (t10 | t20);
    t22 = *((unsigned int *)t5);
    t23 = *((unsigned int *)t7);
    t24 = (t22 | t23);
    t25 = (~(t24));
    t26 = (t21 & t25);
    if (t26 != 0)
        goto LAB82;

LAB79:    if (t24 != 0)
        goto LAB81;

LAB80:    *((unsigned int *)t6) = 1;

LAB82:    t14 = (t6 + 4);
    t27 = *((unsigned int *)t14);
    t28 = (~(t27));
    t29 = *((unsigned int *)t6);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB83;

LAB84:    xsi_set_current_line(116, ng0);

LAB87:    xsi_set_current_line(117, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng34, 2, t0, (char)118, t3, 16);

LAB85:    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(120, ng0);
    t2 = (t0 + 4248);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB88;
    goto LAB1;

LAB81:    t13 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB82;

LAB83:    xsi_set_current_line(114, ng0);

LAB86:    xsi_set_current_line(115, ng0);
    xsi_vlogfile_write(1, 0, 0, ng33, 1, t0);
    goto LAB85;

LAB88:    xsi_set_current_line(121, ng0);
    t3 = (t0 + 1368U);
    t4 = *((char **)t3);
    t3 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = (t3 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t3);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t7);
    t20 = (t11 ^ t12);
    t21 = (t10 | t20);
    t22 = *((unsigned int *)t5);
    t23 = *((unsigned int *)t7);
    t24 = (t22 | t23);
    t25 = (~(t24));
    t26 = (t21 & t25);
    if (t26 != 0)
        goto LAB92;

LAB89:    if (t24 != 0)
        goto LAB91;

LAB90:    *((unsigned int *)t6) = 1;

LAB92:    t14 = (t6 + 4);
    t27 = *((unsigned int *)t14);
    t28 = (~(t27));
    t29 = *((unsigned int *)t6);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB93;

LAB94:    xsi_set_current_line(123, ng0);

LAB97:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng36, 2, t0, (char)118, t3, 16);

LAB95:    goto LAB1;

LAB91:    t13 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB92;

LAB93:    xsi_set_current_line(121, ng0);

LAB96:    xsi_set_current_line(122, ng0);
    xsi_vlogfile_write(1, 0, 0, ng35, 1, t0);
    goto LAB95;

}

static void Always_128_1(char *t0)
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

LAB0:    t1 = (t0 + 4688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(128, ng0);

LAB4:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 4496);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(129, ng0);
    t4 = (t0 + 1928);
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
    t24 = (t0 + 1928);
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


extern void work_m_01235118588550003258_3671711236_init()
{
	static char *pe[] = {(void *)Initial_33_0,(void *)Always_128_1};
	xsi_register_didat("work_m_01235118588550003258_3671711236", "isim/tb_isim_beh.exe.sim/work/m_01235118588550003258_3671711236.didat");
	xsi_register_executes(pe);
}
