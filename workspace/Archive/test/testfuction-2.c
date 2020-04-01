#include <stdio.h>
#include <cs50.h>

//prototype
void PrintName(int x);

int main(void)
{
    
    PrintName(4);
}

void PrintName(int x)

{
    if(x > 3)
    {
        printf("please type your name\n");
        string s = GetString();
        
        printf("hello, %s\n", s);
    }
}