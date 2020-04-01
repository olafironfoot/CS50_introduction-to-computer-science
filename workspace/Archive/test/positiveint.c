#include <stdio.h>
#include <cs50.h>

//create a GetPositiveInt function
//use it

int GetPositiveInt(void);

int main(void)
{
    int n;
    n = GetPositiveInt();
    printf("thanks for the %i, really needed that!\n", n);
    
}

int GetPositiveInt(void)
{
    int n;

    do
    {
        printf("Give me a positive integer: ");
        n = GetInt();
    }
    
    while(n < 1);
    return n;
}