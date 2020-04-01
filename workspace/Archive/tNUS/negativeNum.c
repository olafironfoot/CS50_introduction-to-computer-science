#include <stdio.h>
#include <cs50.h>

int get_negative_int();

int main(void)
{
    int i = get_negative_int();
    printf("i is %i \n", i);
}

int get_negative_int(void)
{
    int x=0;

    do{
        printf("please give us a negative int..\n");
        x = get_int();
        
    }while(x >= 0);
    return x;
}