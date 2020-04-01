/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
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
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int swap;
    // TODO: implement an O(n^2) sorting algorithm- sort(haystack, size);
    //for each pair of values
    for(i = 0; i < n; i++)
        {
            
        
        //if left number bigger than right number, swap.
        if(value [i] > value[i+1])
            {
                swap = value [i];
                value [i] = value [i+1];
                value [i+1] = swap;
            }
        }
    return;
}