#include <stdio.h>

char userText[10];

int main(void)
{
    FILE * leFile = fopen("filePrint.txt", "w");
    
    //char textToInsert[]= "To be or not to be";
    
    scanf("%s", userText);
    
    //size_t fwrite(void* ptr, size_t size, size_t blocks, FILE* fp);
    //fwrite(buffer, 12, 1, out);
    //printf(textToInsert)
    fwrite(userText, 1, 18, leFile);
    
    fclose(leFile);
}