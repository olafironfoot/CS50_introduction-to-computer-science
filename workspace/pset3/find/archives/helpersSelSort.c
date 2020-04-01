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
    //variable declerations
    int swap;
    int min;
    int NumberOfPass = n - 1;
    // TODO: implement an O(n^2) sorting algorithm- sort(haystack, size);
    
    //implement Selection Sort
    //values gets pushed in to this function
    
    //for elements first to last, do number of pass through the elements
    for(int i = 0; i < NumberOfPass; i++)
        {
        //assume first element as minimum
        min = i;
        
        //each pass = (first to last elements), FOR each first to last element..
        for(int j = i + 1; j < n; j++) 
            {
            //define the new minimum element IF any.
            if(values[j] < values[min])
                {
                    //established new minimum-th element upon the pass
                    //value[j] has not changed
                    min = j;
                }

            }
        //IF min element has changed (only happen if the IF function above triggers)
        if(min != i)
                {
                    //swap that element to become the current minimum element
                    //hold value in swap
                    swap = values[i];
                    //replace min with j
                    values[i] = values[min];
                    //replace j with hold value of old min
                    values[min] = swap;
                }
                //consider this sorted, don't look back
                //LOOP this, look forward(to do so, + 1?) for a new minimum on next pass (see line 71)
    
        }
        for(int k = 0; k < n; k++)
         //print to check
            {
                printf("{%i}<-- number in %i-th array (sorted)\n", values[k], k);
                
            }
}