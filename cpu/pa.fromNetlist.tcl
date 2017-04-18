
# PlanAhead Launch Script for Post-Synthesis pin planning, created by Project Navigator

create_project -name cpu -dir "E:/projects/ISE/cpu/planAhead_run_1" -part xc3s500efg320-4
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "E:/projects/ISE/cpu/Top.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {E:/projects/ISE/cpu} {ipcore_dir} }
add_files [list {ipcore_dir/data_ram.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/instruction_ram.ncf}] -fileset [get_property constrset [current_run]]
set_param project.pinAheadLayout  yes
set_property target_constrs_file "foot.ucf" [current_fileset -constrset]
add_files [list {foot.ucf}] -fileset [get_property constrset [current_run]]
link_design
