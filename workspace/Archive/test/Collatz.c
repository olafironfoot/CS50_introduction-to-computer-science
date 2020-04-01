/**
 * Pset4 > Section > Recursion > 11:21 > Collatz conjuncture
 * 
 * Task:
 * use recurssion to write a collatz conjuncture code
 * 
 **/
 #include <cs50.h>
 #include <stdio.h>
 
 
 int collatz(int n);
 
  //initialize
 int stepsCounter = 0;
 
 int main(void)
 {
  printf("%i\n", collatz(15));
 }
 
 
 

 
 int collatz(int n)
 {

  
     while(n > 1)
     {
      
      if((n%2) == 0)    //n == even
      {
          stepsCounter ++;
          return collatz(n/2);   //we want to return the number of steps
          
      }
      
      else   //n == odd
      {
          stepsCounter ++;
          return collatz((3*n) + 1);    //we want to return the number of steps 
          
      }
      
     }
     return stepsCounter;
     
 }