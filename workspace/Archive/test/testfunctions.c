#include <stdio.h>
#include <cs50.h>


//create a PrintName function
//use it

void PrintName(string name);

int main(void)
{
    printf("Please tell me your name so I can say hello: ");
    string s = GetString();
    PrintName(s);
}

void PrintName(string name)
{
    printf("hello, %s\n", name);
}