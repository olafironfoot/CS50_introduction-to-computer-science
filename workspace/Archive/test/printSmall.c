#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* buffer = malloc(sizeof(char));
    FILE* fp = fopen("small", "r");
    
    if (fp == NULL)
    {
        printf("File does not exist.\n");
        return 1;
    }
    
    fseek(fp, 4, SEEK_SET);
    fread(buffer, 1, 1, fp);
    
    printf("%s<--\n", buffer);
    fclose(fp);
    free(buffer);
    
    return 0;
}