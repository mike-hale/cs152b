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
    work_m_12201410829633544809_1694758078_init();
    work_m_12359238400034136294_0121378644_init();
    work_m_08845499736989828580_3679542180_init();
    work_m_16976325798469663955_0282338572_init();
    work_m_00306569014681778059_2514145277_init();
    work_m_00306569014681778059_2753650360_init();
    work_m_03449677127405292449_1502314056_init();
    work_m_06967389315167219776_3703936247_init();
    work_m_06967389315167219776_3510384231_init();
    work_m_06967389315167219776_4270567520_init();
    work_m_06967389315167219776_1374639036_init();
    work_m_12674043831134643923_1687390023_init();
    work_m_00672102483617743505_2762932987_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_00672102483617743505_2762932987");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
