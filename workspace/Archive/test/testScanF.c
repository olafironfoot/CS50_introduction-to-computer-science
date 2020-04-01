#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size;
    printf("how big a memory do you want to allocate?\n");
    scanf("%d", &size);
    
    printf("what is the string you'd like to store?\n");
    string str = malloc(size * sizeof(char));
    scanf("%s", str);
    
    //prints from memory
    printf("%s\n", str);
    free(str);
    
    return 0;
    
}

