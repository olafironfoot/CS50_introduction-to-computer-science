/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
#include <stdio.h>       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
//will return true, or false.
//funciton name is 'search'
//use it for(valueToFind, theArray, length of thArray) ---search(needle, haystack, size)--- iThoughtItWas(number of commands, state a value, something else) 
{
    // TODO: implement a searching algorithm
    for(int i = 0; i < n; i++)
        {
            if(values[i] == value)
                {
                    return true;
                }
        }
        
    return false;
    /**
     *
    //if int value is in int values[], return true
    if(value == values[n])
        {
            
            return true;
        }
    
     
    //if int value is in int values[], return true
    else
        {
            for(int i = 0; i < n; i++)
                {
                    if(value == values)
                }
                
            return true;
        }
        
    **/
    
}

/**
 * Sorts array of n values. Done with Insertion sort*
 */
void sort(int values[], int n)
{
    //declare variable
    int element;
    
    //number of iterations (or passes?). Skip first because first array is already sorted
    for (int i = 1; i < n; i++)
        {
            //value of element moving into sorted portion
            element = values[i];
            
            //declare variable
            int j = 0;
            
            //index into the unsorted portion
            j = i;
        
            //iterate sorted portion from right to left while sorted portion is greater than 'Element' being compared in this iteration of i.
            //basically, it stops this loop once the 'Element' is placed to the left of all greater&&sorted numbers.
            while(j > 0 && values[j - 1] > element)
            {
                //shift all sorted positions to the right 
                values[j] = values[j - 1];
                
                // this enables the loop to move left through the sorted portion
                j = j - 1; 
                
            }
            
            //insert temp holder value into the position which is now empty because all sorted&&greater number are to the right of 'Element'
            values[j] = element;
        
        }
    

        for(int k = 0; k < n; k++)
         //print to check
            {
                printf("{%i}<-- number in %i-th array (sorted)\n", values[k], k);
                
            }
}