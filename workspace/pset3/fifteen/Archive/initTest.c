#include <stdio.h>
#include <cs50.h>

int main(void)
{
int d = GetInt();
int countDownStart = (d * d - 1);
int array[10][10];

        //if even, do this (counDownStart % 2 ==0)
        for(int i = 0; i < d; i++)
            {   
                for(int j = 0; j < d; j++)
                    {
                        array[i][j] = countDownStart--;
                    }
            }
        //if not even, do this:
 
 
    // TODO
    for(int i = 0; i < d; i++)
    {
        printf("\n");
        
        for(int j = 0; j < d; j++)
        {
            if(array[i][j] > 2)
            {
                printf(" %2d", array[i][j]);
            }
            /**
            else if (countDownStart % 2 == 0)
                {
                    printf("blah");
                }
            **/
            else
            {
                printf(" _");
            }
        }
        printf("\n");
    }
    

}