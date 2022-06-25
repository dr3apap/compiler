project     := parser
build_dir   := ./build
executable  := ${bin}/${project}
bin         := ${build_dir}/bin
obj_dir     := ${build_dir}/obj
test_dir    := ${build_dir}/test
src_dir     := ./src
incl_dir    := ./include
objs        := $(patsubst %.c,%.o,$(wildcard ${src_dir}/*.c)) 
src         := $(wildcard ${src_dir}/*.c)
cc          := gcc 
cflags      := -Iinclude -std=c11 -Wall -O0 


.PHONY: all build clean test unit_test test_all

all:${executable}

${executable}:${obj_dir}
	${cc}  -o ${@} ${<}

${obj_dir}:
	${cc} -c ${cflags} ${src}

run:${executable}
	@${^}


test:
	cmake -S . -B ${test_dir}
	cmake --build ${test_dir}
	cd ${test_dir} && ctest
	

clean:
	rm -rf ${build_dir}
