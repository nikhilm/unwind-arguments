#include <stdio.h>
#include <stdint.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

void bar(int bar_arg)
{
    int x = bar_arg;
    int y = &bar_arg;
    size_t z = x + y + 98;
    long w = z * 27;
    printf("The number is %d\n", bar_arg);
    // unwind and print rdi at each frame
	unw_cursor_t cursor; unw_context_t uc;
	unw_word_t ip, rdi;

    unw_getcontext(&uc);
    unw_init_local(&cursor, &uc);
    while (unw_step(&cursor) > 0) {
      unw_get_reg(&cursor, UNW_REG_IP, &ip);
      int suc = unw_get_reg(&cursor, UNW_X86_64_RDI, &rdi);
      printf ("ip = %lx, rdi = %lx rdi fetch success %d signal? %d\n", (long) ip, (long) rdi, suc, unw_is_signal_frame(&cursor));
    }
    printf("The number is %d\n", bar_arg);
}

void foo(int foo_arg)
{
    bar(foo_arg+23);
    printf("unrelated\n");
}

int main()
{
    foo(5);
}
