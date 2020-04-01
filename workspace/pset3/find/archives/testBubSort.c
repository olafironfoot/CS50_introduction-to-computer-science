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
int swap = 0;

//This is an element. (-1 because otherwise, it will compare last array with out side of array memory)
 for(int l = 0; l < NumberOfArrayElements - 1; l++)
    {
        //In each Element, make one pass, from left to right, [0], [1], [2].... [NumberOfArrayElements - 1])
        //because largest number is already on the most right, we don't need to count that again, we do so with "- l"
        for(int k = 0; k < NumberOfArrayElements - l - 1; k++)
            {
                //if [1] is higher, swap with [2]
                if(arrayRack[k] > arrayRack[k + 1])
                {
                    swap = arrayRack[k];
                    arrayRack[k] = arrayRack[k + 1];
                    arrayRack[k + 1] = swap;
                    //printf("%i<- this is [2]\n", arrayRack[2]);
                }
            }
    }   
}