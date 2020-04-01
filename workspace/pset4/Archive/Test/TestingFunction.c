/**
 * Success and completes. now to implement it into recover..!
 **/


#include <stdio.h>
#include "jpg.h"
#include <cs50.h>

bool jpgCheck(BYTE data[], BYTE jpgSig[]);

int main(void)
{
    BYTE jpgSig[4] = { 0xff, 0xd8, 0xff, 0xe8 };
    BYTE data[4] = { 0xff, 0xd8, 0xff, 0xe8 };
    

    if(jpgCheck(data, jpgSig))          //this line seem to be the problem.. It doesn't return my printf even thought it's true..
    {
        printf("matched cause true!\n");
    }

    printf("%hhu\n", jpgSig[3]);
    
}



bool jpgCheck(BYTE store[], BYTE jpgSig[])
{
    for (int i = 0; i < 2; i++)
    {
        if ((store[i]) != (jpgSig[i]))
        {
            return false;
        }
    
    
    }
    
    if (store[3] < 0xe0 || store[3] > 0xef)
    {
        return false;
    }
    
    printf("function jpgCheck Works!\n");

    return true;
}