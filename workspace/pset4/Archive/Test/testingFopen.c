#include <stdio.h>
#include <cs50.h>
#include "jpg.h"

int main(void)
{

    int counter = 1;
    BYTE store[10] = { };
    char title[sizeof "file100.txt"];
             
        
        FILE* inptr = fopen("fOpenTestText.txt", "r");
         
        for(int i = 0; i < 9; i++)
        {
            //move curser 1 bytes ahead
            //if this number is set, the program, seeks two from start everytime, and reads into store[i]
            fseek(inptr, i, SEEK_SET);
            
            fread(&(store[i]), 1, 1, inptr);
            
            

        }
            sprintf(title, "file%03d.txt", counter);

            FILE* fp = fopen(title,"w");
        
        for(int h = 0; h < 3; h++)
        {
            for(int i = 0; i < 3; i++)
            {
    
                fwrite(&(store[i]), 1, 1, fp);
            }
                            //same results, but store 0 - 3 is going to be the same.. since they are not changing.
            printf("%hhu[0], %hhu[1], %hhu[2], %hhu[3]\n", store[0], store[1], store[2], store[3]);
            
        }
               
    
            fclose(fp);
            fclose(inptr);
}