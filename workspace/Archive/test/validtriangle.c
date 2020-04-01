#include <stdio.h>
#include <cs50.h>

//prototype
int validtriangle(int x, int z);

int main(void)

{
    printf("%i <- 1 is true, 0 is fales\n", validtriangle(2, 1));
}

int validtriangle(int x, int z)
{
    //printf("give me three length to form a triangle\n");
  
    if (x > z)
    {
        return 1;     
    }
    
    else
    {
        return 0;
    }

}