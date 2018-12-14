
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name seven_seg_test -dir "C:/Users/CS152B/Desktop/cs152b/seven_seg_test/planAhead_run_1" -part xc5vlx50tff1136-2
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "seven_seg.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {seven_seg.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top seven_seg $srcset
add_files [list {seven_seg.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc5vlx50tff1136-2
