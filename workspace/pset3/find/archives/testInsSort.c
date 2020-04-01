#include <stdio.h>
#include <cs50.h>

void sort(int array[], int NumberOfElements);

int main(void)


{
    //decalre variable
    int NumberOfElements;
    
    printf("how many Element would you like in this array?\n");
    NumberOfElements = GetInt();
    
    //declare variable for array
    int array[NumberOfElements];

    
    for(int i = 0; i < NumberOfElements; i++)
        {
            printf("alright, please key in value of each element\n");
            array[i] = GetInt();
        }
    
    sort(array, NumberOfElements);
    
    for (int i = 0; i < NumberOfElements; i++)
        {
            printf("alright, here is your array sorted, element %i is %i\n", i, array[i]);
        }
    

}


//----------
void sort(int array[], int NumberOfElements)
{
    //declare variable
    int element;
    
    //number of iterations (or passes?). Skip first because first array is already sorted
    for (int i = 1; i < NumberOfElements; i++)
        {
            //value of element moving into sorted portion
            element = array[i];
            
            //declare variable
            int j = 0;
            
            //index into the unsorted portion
            j = i;
        
            //iterate sorted portion from right to left while sorted portion is greater than 'Element' being compared in this iteration of i.
            //basically, it stops this loop once the 'Element' is placed to the left of all greater&&sorted numbers.
            while(j > 0 && array[j - 1] > element)
            {
                //shift all sorted positions to the right 
                array[j] = array [j - 1];
                
                // this enables the loop to move left through the sorted portion
                j = j - 1; 
                
            }
            
            //insert temp holder value into the position which is now empty because all sorted&&greater number are to the right of 'Element'
            array[j] = element;
        
        }
    
}

