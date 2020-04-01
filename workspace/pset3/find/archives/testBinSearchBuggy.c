#include <stdio.h>
#include <cs50.h>

void sort(int array[], int NumberOfElements);
bool search(int value, int values[], int n);

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
    
    printf("value ot search for?\n");
    int value = GetInt();
    search(value, array, NumberOfElements);
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

//--------------
bool search(int value, int values[], int n)
 
{
    // TODO: implement a Binary searching algorithm (You are welcome to take an iterative approach (as with a loop) or a recursive approach (wherein a function calls itself).)
    
    //variables declaration
    //int startPoint;
    //int endPoint;
    //int midPoint;
       
        //define startPoint. numberOfArrayElements(aka size) - (numberOfArrayElements(aka size) - 1) or Element[0]
       
       //define endPoint. numberOfArrayElements(aka size)
       int endPoint = n - 1; //element!
       
       //define midPoint. numberOfArrayElements(aka size)/2
       int midPoint = endPoint/2; //element!
       
       //while loop? 
       while(n > 0)
            {   
               //if midPoint == needle, return 0
               if(values[midPoint] == value)
               {
                   printf("found it!\n");
                   return 0;
               }
               
               //////////(if midPoint is smaller(to the left) or larger(to the right) than needle)
               //ELSE IF midPoint > than needle(look left), keep startPoint, change endPoint element to values[midPoint - 1], define midPoint again.
               else if(values[midPoint] > value)
               {
                   endPoint = midPoint - 1;
                   midPoint = endPoint/2;
                   n = endPoint;
               }
               //ELSE midPoint < than needle(look right), keep endPoint, change Startpoint element to values[midPoint + 1], define mindPoint again.
               else if(values[midPoint] < value)
               {
                   int startPoint = midPoint + 1;
                   
                   //define midpoint again
                   midPoint = (endPoint + startPoint)/2;
                   n = endPoint - startPoint + 1;
               }
               

            }
    
  
      printf("could not find it\n");
      return 1;
}