#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for input
    printf("Give me an integer: ");
    int x = GetInt();
    printf("Give me another integer: ");
    int y = GetInt();
    printf("give me a string: ");
    string s = GetString();

    // do the math
    printf("The sum of %i and %i is %i! and here is the string-%s!\n", x, y, x + y, s);
}