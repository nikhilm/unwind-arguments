This is example code for [Retrieving function arguments while unwinding the stack][].

[Retrieving function arguments while unwinding the stack]: http://nikhilism.com/post/2019/possible-to-retrieve-arguments-while-unwinding/

`test_prog.c` is the primary program, which the Makefile compiles under various
debug/release and optimization levels.

`unwind_rdi.c` is a program that requires [libunwind][] installed to build, and
simply unwinds the stack, printing the instruction pointer and `rdi` at each
frame.

[libunwind]: https://www.nongnu.org/libunwind/

This code is public domain.
