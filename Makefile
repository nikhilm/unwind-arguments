.PHONY: clean view

all: debug debug_opt release release_opt release_no_unwind

debug: test_prog.c
	clang -g -O0 test_prog.c -o debug

debug_opt: test_prog.c
	clang -g -O2 test_prog.c -o debug_opt

release: test_prog.c
	clang -O0 test_prog.c -o release

release_opt: test_prog.c
	clang -O2 test_prog.c -o release_opt

release_no_unwind: test_prog.c
	clang -O0 test_prog.c -o release_no_unwind -fno-asynchronous-unwind-tables

unwind_rdi:
	clang -g unwind_rdi.c -o unwind_rdi -lunwind

clean: 
	rm -f test_prog debug debug_opt release release_opt unwind_rdi
