#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc, string argv[])
{
    if (argc < 1)
    {
        printf("please provide command line argument\n");
    }
    
    else
    {
        
        //printf("%c<- first letter of argv\n", argv[1][0]);
        
        // string s = argv[1];
        for(int i = 0; i < strlen(argv[1]); i++)
        {
            printf("%ith letter of command argument is %c\n", i, argv[1][i]);
        }
            return 0;

    }
}