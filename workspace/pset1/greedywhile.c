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
    
    
    //This is the one that stumb me. Tried to use "f=round(f*100)/100" to keep getting float. The best way was to just not use float in the first place.
    // thought.. it's good to find out why i fail.. that way. by right should be able to use float to minus too..?
    f = f*100;
    f = (int)round(f);
    
    
    
    
    //declare indentifier C.. AKA, initialize variable C
    int numcoins=0;
    
    
    
    //minus each coin(25,10,5,1) of the interger off the input number
    while (f>=25)
    { 
        f = f - 25;
        numcoins++;
    }
    
    
    while (f>=10)
    { 
        f = f - 10;
        numcoins++;
    }
    
    
    while (f>=5)
    { 
        f = f - 5;
        numcoins++;
    }
    
    
    while (f>=1)
    { 
        f = f - 1;
        numcoins++;
    }
    
    
    //printing to check
    printf("%i\n", numcoins);
  



}

/**
 * use this to check "check50 2015.fall.pset1.greedy greedy.c"
 * 
 * Something is wrong with 0.01 and 0.10, can't seem to get the correct round off... check...
 * */
 