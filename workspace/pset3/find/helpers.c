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
//search(needle, haystack, size)
bool search(int value, int values[], int n)
 
{
    // TODO: implement a Binary searching algorithm (You are welcome to take an iterative approach (as with a loop) or a recursive approach (wherein a function calls itself).)
    
    //variables declaration
    //int startPosition;
    //int endPosition;
    //int midPosition;
       
        //define startPosition. numberOfArrayElements(aka size) - (numberOfArrayElements(aka size) - 1) or Element[0]
       int startPosition = 0;
       //define endPosition. numberOfArrayElements(aka size)
       int endPosition = n - 1; //element!

       
       
       //while loop? 
       while(n > 0)
            {   
                //define midPosition. numberOfArrayElements(aka size)/2
                int midPosition = (startPosition + endPosition)/2; //element!
               
               //if midPosition == needle, return 0
               if(values[midPosition] == value)
               {
                   return true;
               }
               
               //////////(if midPosition is smaller(to the left) or larger(to the right) than needle)
               //ELSE IF midPosition > than needle(look left), keep startPosition, change endPosition element to values[midPosition - 1], define midPosition again.
               else if(values[midPosition] > value)
               {
                   //-1 because we don't need to check the midPosition again since != value as per line 101
                   endPosition = midPosition - 1;
                   //number of Elements left
                   n = midPosition;
               }
               //ELSE midPosition < than needle(look right), keep endPosition, change StartPosition element to values[midPosition + 1], define mindPosition again.
               else if(values[midPosition] < value)
               {
                   startPosition = midPosition + 1;
                   
                   //number of Elements left
                   n = endPosition - midPosition;
               }
               

            }
    
    
    //-------------------------
       //define startPosition. numberOfArrayElements(aka size) - (numberOfArrayElements(aka size) - 1) or Element[0]
       //define endPosition. numberOfArrayElements(aka size)
       //define midPosition. numberOfArrayElements(aka size)/2
       //while
       //if midPosition == needle, return 0
       //////////(if midPosition is smaller(to the left) or larger(to the right) than needle)
       //ELSE IF midPosition < than needle(look left), keep startPosition, change endPosition to value[midPosition - 1], define midPosition again.
       //ELSE midPosition > than needle(look right), keep endPosition, change StartPosition to value[midPosition + 1], define mindPosition again.
      printf("could not find it\n");
      return false;
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
    
/**
        for(int k = 0; k < n; k++)
         //print to check
            {
                printf("{%i}<-- number in %i-th array (sorted)\n", values[k], k);
                
            }
**/
}


//Lesson learnt here was that, bool is a little funky, if we change the return to "1" instead to false, and "0" instead of "true". It gets buggy...