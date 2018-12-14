run_add:
	make build_add
	vvp test_sim | tee a_sim_results.txt

run_mult:
	make build_mult
	vvp test_sim | tee m_sim_results

build_mult: 
	iverilog -o test_sim \
		verilog_source_code/Test_mult.v \
		verilog_source_code/qmult.v

build_add:
	iverilog -o test_sim \
		verilog_source_code/Test_add.v \
		verilog_source_code/qadd.v

clean:
	rm test_sim