#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //ask user for input
    printf("minutes: ");
    
    //gather input data
    int x = GetInt();
    
    //do the math with the side effect to print
    printf("bottles: %i\n", x*192/16);
}