#include <stdio.h> //for printf


void swap(int* a, int* b);

int main(void)
{
    int x = 2;
    int y = 1;
    
    printf("swapping\n");
    swap(&x, &y);
    
    printf("swaped\n");
    printf("x = %i, y = %i \n", x, y);
    
}



//under the hood of swap funciton. we Don't want to change the value OF 'a', we want to change the value AT 'a'
void swap(int* a, int* b)
{
    int tmp = *a;   //a is an address.
    *a = *b;        
    *b = tmp;
    
}

