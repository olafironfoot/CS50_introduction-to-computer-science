
#include <stdio.h>
#define MEMORYBLOCK 512
#include <cs50.h>
#include "jpg.h"

bool jpgCheck(BYTE data[], BYTE jpgSig[]);

int main(void)
{
//declare variables
BYTE store[MEMORYBLOCK];       //int == 4 bytes, we want, 1 byte 
char title[sizeof "###.jpg"];
int fileNameCounter = 0;
BYTE jpgSig[3] = { 0xff, 0xd8, 0xff };

     //-ZYMAYLA'S concept explaination
    //1) -Open memory card file [fopen("card.raw", "r"]
    FILE* inptr = fopen("card.raw", "r");
        if(inptr == NULL)
        {
            printf("could not open file\n");
            fclose(inptr);
            return 1;
        }
    while(!feof(inptr)) //returns non-zero value at end of file     //while(fread(&bug, sizeof(DOG), 2, ptr) == 2)? ****discovered that this line needed a '!'.
    {
        //read & store 
        fread(store, sizeof(BYTE), MEMORYBLOCK, inptr);
        /**for(int i = 0; i < MEMORYBLOCK; i++)
        {
            //read & store 512bytes in memory[i]
            fread(&(store[i]), 1, 1, inptr);        //do we need *inptr instead?
            
        }
        **/
        //if find jpg, decide what to do. //if jpgCheck true, write file.  [read 512 bytes at a time] [compare first 4bytes, jpgCheck] [close jpg if any (on second pass?)]
        if(jpgCheck(store, jpgSig)) //is true
        {

            //2) -Open a new jpg [name it accordingly]            //fopen(title, "w");
            sprintf(title, "%03d.jpg", fileNameCounter);
            //open the newly created file
            FILE* outptr = fopen(title, "w");
            if(outptr == NULL)
            {
                printf("could not create file\n");
                fclose(outptr);
                return 2;
            }
            
            //keep track of file name counter
            fileNameCounter++;

            
            //3) -write 512bytes for "non-star files" until new jpeg is found [i.e line 2)] //if jpgCheck is not true, write. //else(true), close current file and go to line 2.        
            fwrite(store, sizeof(BYTE), MEMORYBLOCK, outptr);
            /**
            for(int i = 0; i < MEMORYBLOCK; i++)
            {
                fwrite(&(store[i]), 1, 1, outptr);
            }
            **/
            

            do
            {
                //read
                fread(store, sizeof(BYTE), MEMORYBLOCK, inptr);
                /**for(int i = 0; i < MEMORYBLOCK; i++)
                {
                    fread(&(store[i]), 1, 1, inptr);
                    
                }
                **/
                

                //if not jpg, write. 
                if(!(jpgCheck(store, jpgSig)))
                {
                    //write
                    fwrite(store, sizeof(BYTE), MEMORYBLOCK, outptr);
                    /**
                     * for(int i = 0; i < MEMORYBLOCK; i++)
                    {
                        fwrite(&(store[i]), 1, 1, outptr);
                    }
                    //move cur
                    fseek(inptr, 512, SEEK_CUR);
                    **/
                }
                
            }while(!(jpgCheck(store, jpgSig))); //is not start of jpg file
           
            //if not first file, close previosu opened file
            if(fileNameCounter > 0)
            {
                fclose(outptr);
            } 
        }
        //else jpgCheck not true,!=, then, fseek, and keep looking

        
    }
    //4) -Detect end of file (e.g. once it returns 1 instead of 2 DOGs          fun fact: when using functions in a condition, it will execute the function while checking for the condition...
                                                                                             //if(fread(&bug, sizeof(DOG), 2, ptr) == 1) <--that's how to check for end the file.
    fclose(inptr);
}

//function to JpgCheck
bool jpgCheck(BYTE store[], BYTE jpgSig[])
{
    for (int i = 0; i < 2; i++)
    {
        if ((store[i]) != (jpgSig[i]))
        {
            return false;
        }
    }
    if (store[3] < 0xe0 || store[3] > 0xef)
    {
        return false;
    }
    return true;
}

//--------------------------------------
 //-ZYMAYLA'S concept explaination
    //1) -Open memory card file [fopen("card.raw", "r"]
    
    //2) -Find beginning of jpg [read 512 bytes at a time] [compare first 4bytes, jpgCheck] [close jpg if any (on second pass?)]
    //3) -Open a new jpg [name it accordingly]            //fopen(title, "w");
    //4) -write 512bytes for "non-star files" until new jpeg is found [i.e line 2)]           
            
    //5) -Detect end of file (e.g. once it returns 1 instead of 2 DOGs          fun fact: when using functions in a condition, it will execute the function while checking for the condition...
                                                                                        //if(fread(&bug, sizeof(DOG), 2, ptr) == 1) <--that's how to check for end the file.
    //
 //----------------------------------------   
//Erik's evolution
//do    
//read & store 
//if find jpg, decide what to do. //if jpgCheck true, write file.  [read 512 bytes at a time] [compare first 4bytes, jpgCheck] [close jpg if any (on second pass?)]
    
    //2) -Open a new jpg [name it accordingly]            //fopen(title, "w");
    //3) -write 512bytes for "non-star files" until new jpeg is found [i.e line 2)] //if jpgCheck is not true, write. //else(true), close current file and go to line 2.        
            
    //4) -Detect end of file (e.g. once it returns 1 instead of 2 DOGs          fun fact: when using functions in a condition, it will execute the function while checking for the condition...
                                                                                        //if(fread(&bug, sizeof(DOG), 2, ptr) == 1) <--that's how to check for end the file.
//else jpgCheck not true,!=, then, fseek, and keep looking

//while(fread(&bug, sizeof(DOG), 2, ptr) == 2)?


 //----------------------------------------   
    //ZYMAYLA'S ACTUAL PSEUDOCODE
    //open card file
    //repeat untill end of card

        //read 512bytes into a buffer           //fread(&data, size, number, inptr)
        
        //start of a new jpg? (find beginning of jpg) <-- will affect file management, which one to open which to close.
            //yes... do..[if] 
                //[Open a new jpg, name accordingly]
                //[if hit jpg again, close previous jpg if any was opened]
                
            //no... do..  [else] (?keep writing, or find the next jpg)
                //[then keep same jpg open and write 512byte at a time]
                
        //already found a jpg?
            //yes... do.. [write 512 bytes until new jpg is found]
            //no... do.. [do not write, keep looking till find one]
    
    //close any remainding files