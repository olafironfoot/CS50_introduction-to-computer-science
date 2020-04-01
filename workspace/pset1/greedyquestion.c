#include <cs50.h>
#include <stdio.h>
#include <math.h>
//insert math.h on top?

int main(void)
{
    //hold user input
    float f;
   
    
    /**
     * what the pset told us to input?
    float f = 0.01;
    printf("%.50f\n", f);
    **/
    
    //Get float from user
    do
    {
    printf("O hai! How much chage is owed?\n");
    f = GetFloat();
    }
    
    //ask again if negative
    while (f<0);
    
    
    
    
    
    
    
    /**
     * 
    //checking if float is correct
    printf("%f\n", f);
    **/
    
    
    //convert float into interger, cheap way
    f = round(f*100)/100;
    printf("%f <--this number is just to check what is user input\n",f);
    
    /**
     * 
     * 
     *  input = round(input*100)/100;
     * 
    //checking if %i is correct
    printf("%i\n", i);
    **/
    
    //declare indentifier C.. AKA, initialize variable C
    int numcoins=0;
    
    
    
    //minus each coin(25,10,5,1) of the interger off the input number
    for( ; f>=0.25; numcoins++)
    { 
        f = f - 0.25;
    }
    printf("%f<---amount left after deducting 0.25s\n",f);
    
    for( ; f>=0.10; numcoins++)
    { 
        f=f-0.10;
    }
    printf("%f<---amount left after deducting 0.10s\n",f);
    
    for( ; f>=0.05; numcoins++)
    { 
        f=(f-0.05);
    }
    printf("%f<---amount left after deducting 0.05s\n",f);
    
   for( ; f>=0.01000; numcoins++)
    { 
        f = f - 0.01;
    }
    printf("%f<---amount left after deducting 0.01s\n",f);
 
    
    //printing to check
    printf("%i\n", numcoins);
  



}

/**
 * 
 * My question is...Tried to use "f=round(f*100)/100" and kept minus-ing float e.g 0.25, 0.10, 0.05, 0.01. But why couldn't it work?
 * 
 * 
 * */
 