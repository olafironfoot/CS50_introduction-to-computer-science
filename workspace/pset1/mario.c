#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //hold user's input
    int n;
    
    //keeping execute this
    do{
        printf("height: ");
        n = GetInt();
       
    }
    
    //keep executing the above if n is more than 23,
    //if it is less, go run the code below.
    while(n > 23);
    
    
    
    //sets number of rows... loop (initialization, condition, update) 
    for (int i=0; i<n; i++)
    {
      //sets what is in each row, the " ".
      for(int s=0; s<n-1-i; s++)
      {
        printf(" ");
      }
      
      //set what is in each row, the "#".
      for(int r=0; r<i+2; r++)
      { 
        printf("#");
      }
      
      
      //prints next row.
      printf("\n");
    }
    
    
    
    
    
    
    
    
    /**
     * ------------
    for (int i=0; i< n+n-1; i++)
    {
      printf("#");
    
    }
    
      for (int i=0; i< n; i++)
    {
      printf("\n");
    
    }
    
    -----
    printf("%s\n", "#");
        
    //keep executing the above if i is less than n
    //if it is less, go run the code below.
    while (i<n);
    return n;
    }
    
    
    printf("it works!\n");
    
    Comment to github/stackexchange for people trying to solve this, 
    about the "n" in the walk through not equating to the "n" in the question. 
    E.g. "n" in walkthrough is the index, while "n" in question is the height. 
    
    **/
    
}