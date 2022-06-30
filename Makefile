project     := parser

# Variables for path of source, header, and test files
inc_dir    := ./include
src_dir     := ./src
sources     := $(wildcard ${src_dir}/*.c)
test_dir    := ./test
unit_tests  := $(wildcard ${test/*.cpp})

# Variables for paths of object files and binary targets
build_dir           := ./build
obj_dir             := ${build_dir}/obj
bin_dir             := ${build_dir}/bin
unit_test_build_dir := ${build_dir}/test
executable          := ${bin_dir}/${project}
build_dirs          := ${obj_dir} ${bin_dir} ${unit_test_build_dir}  
objs        := $(subst .c,.o,$(subst ${src_dir},${obj_dir},${sources})) 

# Variables for compiler and compiler flags, and linker
cc          := gcc # Using gcc compiler (alternative: clang) 
cflags      := -I${inc_dir} -g -Wall -std=c11 -O0 

# Variables for testing memory leak-check
valgrind    := $(valgrind --leak-check=full)


.PHONY:all run clean test unit_test leak-check

all:${executable} # all is the default goal


run:${executable} # Execute the project's binary file
	@${^}

${executable}:${objs} | ${bin_dir} # Build the project by combining all object files
	${cc}  ${cflags} -o ${@} ${^}

${obj_dir}/%.o: ${src_dir}/%.c | ${obj_dir} # Build object files from sources in a template
	${cc} ${cflags} -c -o ${@} ${<}

${build_dirs}:
	mkdir -p ${obj_dir} ${bin_dir} ${unit_test_build_dir}


leak-check:
	${valgrind} ${executable}

test:
	cmake -S . -B ${test_dir}
	cmake --build ${test_dir}
	cd ${test_dir} && ctest
	
clean:
	rm -rf ${build_dir}
