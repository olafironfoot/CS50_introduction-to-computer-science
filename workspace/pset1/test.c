#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    
    do
    {
      printf("type a positive num: ");
      n = GetInt();
    }
    while (n<0);
    
    printf("thanks!\n");
    
    return 0;
}