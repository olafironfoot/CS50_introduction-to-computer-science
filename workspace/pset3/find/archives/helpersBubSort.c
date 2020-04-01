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
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int swap;
    int NumberOfArrayElements = n;
    // TODO: implement an O(n^2) sorting algorithm- sort(haystack, size);
    
    //For each one element. (Minus 1 because last element shouldn't swap with untouchable memory of the array)
    for(int i = 0; i < NumberOfArrayElements - 1; i++)
        {
        
        //make one pass of 'swap check'. Minus -1(see above why). Then minus more, because the largest element is already on the right handside.
        for(int j = 0; j < NumberOfArrayElements - i - 1; j++)
            {
                
            //for each values, if right number is bigger swap.
            if(values[j] > values[j + 1])
                {
                    swap = values[j];
                    values[j] = values[j + 1];
                    values[j + 1] = swap;
                }
            }
        }
        
    for(int i = 0; i < NumberOfArrayElements; i++)
    {
        printf("{%i}<-- number in %i-th array (sorted)\n", values[i], i + 1);
        
    }
}