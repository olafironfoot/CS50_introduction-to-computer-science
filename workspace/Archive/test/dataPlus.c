/**
 * To store specific lines of data from fread into array.
 * Alternatively, to make the buffer recieved from fread, readible
 **/

#include <stdio.h>

int main(void)
{

FILE* in = fopen("in.txt", "r");

if (in == NULL)
{
    printf("File does not exist.\n");
    return 1;
}


FILE* out = fopen("out.txt", "w");
if (out == NULL)
{
    printf("File does not exist.\n");
    return 2;
}

//read file information into array.
int* ptr[4];

//error here... Tried to store it directly into array instead of buffer..
    for(int i = 0; i < 4; i++)
    {
        fread(&ptr[i] + 1, 1, 1, in);
    }
    
    
    for(int j = 0; j < 4; j++)
    {
        printf("success. Array[%i] is --> %p value\n", j, ptr[j]);
    }
    
fclose(in);
fclose(out);
}