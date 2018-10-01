
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name Lab0 -dir "C:/Users/TA/Documents/CS152B Team 3/Lab0/planAhead_run_2" -part xc5vlx50tff1136-2
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "counter.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {counter.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top counter $srcset
add_files [list {counter.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc5vlx50tff1136-2
