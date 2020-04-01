//**This code, once compiled with "make"/ clang-o function-1 function-1.c
//** will create a program that is open-able in terminal to ask untill it gets a positive number.

#include <stdio.h>
#include <cs50.h>

int GetPositiveInt();

int main(void)
{
    int n = GetPositiveInt();
    printf("Thanks for the %i!\n", n);
}

int GetPositiveInt(void)
{
    int n;
    do 
    {
        printf("please give me a positive int: ");
        n=GetInt();
    }
    while (n<1);
    return n;
}