#include <stdio.h>
#include <cs50.h>

void sort(int arrayRack[], int NumberOfArrayElements);

int main(void)

{
//variable declarations
int NumberOfArrayElements = 0;


//Get number of arrays
printf("number of arrays you'd like?\n");
NumberOfArrayElements = GetInt();

//variable array declaration
int arrayRack[NumberOfArrayElements];


//Get number for each int
for(int i = 0; i < NumberOfArrayElements; i++)
    {
        printf("give me an int for the %i th array\n", i + 1);
        arrayRack[i] = GetInt();
    }
    
//print what is currently in the arrayRack
for(int j = 0; j < NumberOfArrayElements; j++)
    printf("{%i}<-- number in %i-th array (unsorted)\n", arrayRack[j], j + 1);
    
sort(arrayRack, NumberOfArrayElements);

for(int i = 0; i < NumberOfArrayElements; i++)
    {
        printf("{%i}<-- number in %i-th array (sorted)\n", arrayRack[i], i + 1);
        
    }
    return 0;
}

//------------------------------------------------------
//this is the funciton, like sort(haystack, size);
void sort(int arrayRack[], int NumberOfArrayElements)
{
//declare variable
int min = 0;
int swap = 0;

//Number of passes
//rem to ask **why n-1..?! (because N number is N-1 passes.. cheyy..e.g. model drawing, 10 boxes, draw 9 lines)
 for(int l = 0; l < NumberOfArrayElements - 1; l++)
    {
        //identify minimum
        //during each pass, get new min from l-th numbers from the left as previous elements are already sorted
        min = l;

        //doing one pass, checking from left to right. Skipping sorted numbers
        for(int k = l + 1; k < NumberOfArrayElements; k++)
            {
                //if [k]th is higher than min, swap.
                if(arrayRack[k] < arrayRack[min])
                    {
                        min = k;
                    }
            }
        //if minimum has changed (see line 55)
        if(min != l)
        {
            //swap min and array[l]
            swap = arrayRack[l];
            //since arrayRack[k] is the new min, push it to left (which is where [l] currently is)
            arrayRack[l] = arrayRack[min];
            arrayRack[min] = swap;
            
        }

            
    }   
}

// ******lesson learn from this is, that I was looking at again, the number in the array[element] instead of the "element number"
// min should have been the position, not the value of the element..!
//see "Sel sort" in Sketch book to understand why, NumberOfPasses is n-1. why j = i + 1. how swaping(value) and min[element] works together. 