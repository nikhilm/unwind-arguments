#include <stdio.h>

void bar(int bar_arg)
{
    printf("The number is %d\n", bar_arg);
}

void foo(int foo_arg)
{
    bar(foo_arg + 23);
    printf("unrelated\n");
}

int main()
{
    foo(5);
}
