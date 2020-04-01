
#include <stdio.h>
#include <cs50.h>

int cube(int a);

int main(void)
{
    int x = 2;
    printf("x is now %i\n", x);
    printf("Cubing...\n");
    x = cube(x);
    printf("cubed!\n");
    printf("x is now %i\n",x);
}

int cube(int n)
{
    return n *n * n;
}