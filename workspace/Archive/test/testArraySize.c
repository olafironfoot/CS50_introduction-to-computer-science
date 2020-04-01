#include <stdio.h>
#include <cs50.h>
#define N 3

int main(void)
{
    
    //declare variable
    int counter = 0;
    //declare array
    int array[100];
    
    //for loop to prompt for number storage
    for(int i = 0; i < N; i++)
    {
        printf("insert number for storage\n");
        array[i] = GetInt();
    }
    
    
    do
    {
        printf("which array[value], value do you want to see? key in 0 - 2\n");
        int holder = GetInt();
        if(0 > holder || holder > 2)
        {
            printf("please give a value between 0 - 2\n");
        }
        printf("array number %i is %i <--value\n", holder, array[holder]);
        
        counter++;
        
        if(counter > 2)
        {
            printf("ok you've seen enough\n");
            return true;
        }
        
    }while(true);
    
    return 0;
    
}