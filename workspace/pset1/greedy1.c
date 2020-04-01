#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    
 //make sure there's memory to hold user input
    float input;
    
//get user input
    do
    {
    printf("oh hai, how much change do you need?\n");
    input = GetFloat();
    }
    
    while (input<0);

//round off user float input into interger
    
    input = round(input*100)/100;
    
    printf("%f\n", input);

    return 0;
}
