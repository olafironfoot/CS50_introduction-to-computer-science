#include <stdio.h>
#include "jpg.h"


    
int main(void)
{
    //ZYMAYLA'S ACTUAL PSEUDOCODE
    //open card file
    
    FILE* inptr = fopen("card.raw", "r");
    if(inptr == NULL)
    {
        printf("could not open file\n");
        fclose(inptr);
        return 1;
    }
    
    FILE* outptr = fopen("testOutput", "w");
    if(outptr == NULL)
    {
        printf("could not create file\n");
        fclose(outptr);
        return 2;
    }
    
    //repeat untill end of card
    IDENTIFIER id;
    unsigned char buffer;
        
        //read 512bytes into a buffer
        fread(&id, sizeof(IDENTIFIER), 1, inptr);
        
        //start of a new jpg?
        for(int i = 0; i < 17000000; i++)       //unable to use sizeof(card.raw).. why?
        {
            fseek(inptr, 1, SEEK_CUR);         //fseek(out, 0, SEEK_SET);
            
            if(id.identifierI == 0xff && id.identifierII == 0xd8 && id.identifierIII== 0xff 
            && (id.identifierIV == 0xe0 || id.identifierIV == 0xe1 || id.identifierIV == 0xe2 || 
            id.identifierIV == 0xe3 || id.identifierIV == 0xe4|| id.identifierIV == 0xe5|| id.identifierIV == 0xe6||
            id.identifierIV == 0xe7|| id.identifierIV == 0xe8|| id.identifierIV == 0xe8|| id.identifierIV == 0xe9||
            id.identifierIV == 0xea|| id.identifierIV == 0xeb|| id.identifierIV == 0xec|| id.identifierIV ==  0xed|| 
            id.identifierIV == 0xee|| id.identifierIV == 0xef))
            {
                printf("found jpeg!\n");
                fwrite(&id, sizeof(IDENTIFIER), 1, outptr);
    
                fread(&buffer, 512, sizeof(unsigned char), inptr);
                fwrite(&buffer, 512, sizeof(unsigned char), outptr);
            }
        }

            //yes... do..
            //no... do..
        //already found a jpg?
            //yes... do..
            //no... do..
    //close any remainding files
    fclose(inptr);
    fclose(outptr);
}