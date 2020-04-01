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
    

       
        //define startPoint. numberOfArrayElements(aka size) - (numberOfArrayElements(aka size) - 1) or Element[0]
       int startPoint = 0;
       //define endPoint. numberOfArrayElements(aka size)
       int endPoint = n - 1; //element! we -1 because array start from 0th element. last element of array that is 5 elements big will thus be (total number of Elements - 1)th element.
       
       //define midPoint. numberOfArrayElements(aka size)/2
       int midPoint = startPoint + endPoint/2; //element! //Original is {int midPoint = endPoint/2;} **mistake here was didn't add startpoint to find mid point. 
       
       //while loop? 
       while(startPoint <= endPoint)
            {   
               //if midPoint == needle, return 0
               if(values[midPoint] == value)
               {
                   return 0;
               }
               
               //////////(if midPoint is smaller(to the left) or larger(to the right) than needle)

               //ELSE midPoint < than needle(look right), keep endPoint, change Startpoint element to values[midPoint + 1], define mindPoint again.
               else if(values[midPoint] < value)
               {
                   startPoint = midPoint + 1;
                   
                   //define midpoint again
                   //midPoint = (endPoint + startPoint)/2;
                   //n = endPoint - startPoint + 1;
                   //printf("mid point is less than needle\n");
               }
               
                //ELSE IF midPoint > than needle(look left), keep startPoint, change endPoint element to values[midPoint - 1], define midPoint again.
               else
               {
                   endPoint = midPoint - 1;
                   midPoint = (startPoint + endPoint)/2;
               }
               
               if (startPoint > endPoint)
               {
                printf("starPoint is now greater than endPoint\n");
               }
            }
    return 1;
    
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