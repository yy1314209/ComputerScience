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
    work_m_00000000003055018757_1547046708_init();
    work_m_00000000002320247569_3052657050_init();
    xilinxcorelib_ver_m_00000000001067635404_3146710437_init();
    work_m_00000000003452451064_3059417024_init();
    work_m_00000000002400734858_3037777339_init();
    work_m_00000000002843242381_3866583278_init();
    work_m_00000000002962029257_2587490486_init();
    work_m_00000000000151415697_3267345094_init();
    work_m_00000000000220704561_1545735058_init();
    work_m_00000000003663742272_4274534429_init();
    xilinxcorelib_ver_m_00000000001067635404_0950652053_init();
    work_m_00000000004259014342_0362415942_init();
    work_m_00000000004045760824_1989334135_init();
    work_m_00000000002855255380_3683860065_init();
    work_m_00000000000757232315_1985558087_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000000757232315_1985558087");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
