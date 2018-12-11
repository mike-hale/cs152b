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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000000903731200_3687061878_init();
    work_m_00000000003991964843_0510015413_init();
    work_m_00000000003186647103_2473891197_init();
    work_m_00000000003972108333_4223219024_init();
    work_m_00000000003991964843_2612893598_init();
    work_m_00000000001397760730_0415658247_init();
    work_m_00000000000448526118_3063521826_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000000448526118_3063521826");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
