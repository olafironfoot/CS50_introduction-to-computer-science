/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#define MEMORYBLOCK 512
#include <cs50.h>
#include "jpg.h"

int main(void)
{
    //declare variables
    BYTE store[MEMORYBLOCK];       //int == 4 bytes, we want, 1 byte 
    
    //chars of arrays for sprintf
    char title[sizeof "###.jpg"];
    
    //could the 4th byte belong to a jpg?
    bool fourthByteJpg = false;
    
    //filename counter
    int fileNameCounter = 0;
    
    //found jpg?
    bool foundJpg = false;

    //firstPass = true
    bool firstPass = true;
    
    bool foundFirstThreeBytes = false;
    bool storeIsJpg = false;
    //MY PSEUDOCODE
    
    

    

    
//solution 3 (I think this is it..!!)
//once open
   FILE* inptr = fopen("card.raw", "r");
    if(inptr == NULL)
    {
        printf("could not open file\n");
        fclose(inptr);
        return 1;
    }

    //size of card
    fseek(inptr, 0, SEEK_END);
    int cardSize = ftell(inptr);
    
        //for each block in the card
        for(int h = 0, noOfBlocks = cardSize/512; h < noOfBlocks; h++)
        {
            //for within each 512 memory block
            for(int i = 0; i < MEMORYBLOCK; i++)
            {
                //read & store 512bytes in memory[i]
                fread(&(store[i]), 1, 1, inptr);
                
                
                //read & store first four bytes into store[i]
                if(i < 4)
                {
                    fread(&(store[i]), 1, 1, inptr);
                }
            }
            //define if store is jpg
            if(store[3] == 0xe0 || store[3] == 0xe1 || store[3] == 0xe2 || store[3] == 0xe3 || store[3] == 0xe4 || store[3] == 0xe5 || store[3] == 0xe6 ||
            store[3] == 0xe7 || store[3] == 0xe8 || store[3] == 0xe8 || store[3] == 0xe9 || store[3] == 0xea || store[3] == 0xeb || store[3] == 0xec || store[3] == 0xed
             || store[3] == 0xee || store[3] == 0xef)
             {
                 fourthByteJpg = true;
             }
             if(store[0] == 0xff && store[1] == 0xd8 && store[2] == 0xff)
             {
                 foundFirstThreeBytes = true;
             }
             
            if((foundFirstThreeBytes == true) && (fourthByteJpg == true))
            {
                storeIsJpg = true;
            }
            
            //if store[1],[2],[3],[4] is jpg && already found jpg
            if((storeIsJpg == true) && (foundJpg == true))
            {
                //fileNameCounter ++
                fileNameCounter++;
                //foundJpg = false
                foundJpg = false;
                //create a new file, name it accordingly
                sprintf(title, "%03d.txt", fileNameCounter);
                //open the newly created file
                FILE* outptr = fopen(title, "w");
                if(outptr == NULL)
                {
                    printf("could not create file\n");
                    fclose(outptr);
                    return 2;
                }
                
            }
            //if store[1],[2],[3],[4] is jpg || already found jpg
            if((storeIsJpg == true) || (foundJpg == true))
            {    //foundJpg = true
                foundJpg = true;
                //if(firstPass = true)
                    //open the newly created file
                    FILE* outptr = fopen(title, "w");
                    if(outptr == NULL)
                    {
                        printf("could not create file\n");
                        fclose(outptr);
                        return 2;
                    }
                    
                if(firstPass == true);
                {
                    //create a new file, name it accordingly                     //fopen("fileNameCounter.jpg", "w")
                    //create a new file, name it accordingly
                    sprintf(title, "%03d.txt", fileNameCounter);
                    
                    //firsPass = false
                    firstPass = false;
                }   
                //write current memory[i] into output                   ////fwrite(&(store[i]), 1, 1, outptr);
                 for(int i = 0; i < MEMORYBLOCK; i++)
                {
                    fwrite(&(store[i]), 1, 1, outptr);
                }
            }   
        }


    //remember to close opened files and free memory(if any)
    fclose(inptr);
}

    //-ZYMAYLA'S concept explaination
    //-Open memory card file 
    //-Find beginning of jpg 
        //read 512 bytes at a time
    //if there's is an open jpg, close file
    //-else Open a new jpg             //fopen(title, "w");
    //-write 512bytes untill new jpeg is found            //fwrite(&buffer, 512, 1, outfile);
        //when jpeg is found, close
    //-Detect end of file (e.g. once it returns 1 instead of 2 DOGs          fun fact: when using functions in a condition, it will execute the function while checking for the condition...
                                                                                        //if(fread(&bug, sizeof(DOG), 2, ptr) == 1) <--that's how to check for end the file.
    //
    
    //----need to ---
    
    //(?)create a struct that has a title for struct.firstfourbytes




//----------------

    //ZYMAYLA'S ACTUAL PSEUDOCODE
    //open card file
    //repeat untill end of card
        //read 512bytes into a buffer
        //start of a new jpg?
            //yes... do..
            //no... do..
        //already found a jpg?
            //yes... do..
            //no... do..
    //close any remainding files


 
    //----code graveyard---
    
    //ensure it's argc 1 (for 1 inputs from users + ./recover itself)
    //if argv[1] = null, what happens
    //assign variables/pointers
    //ensure correct input by users (create conditions of wrong inputs)
    //feek inptr, SEEK_SET + counter       (once it's fopen, we can fseek)

    
    
    //take input = card.raw (counter for number of .jpegs?)


 /**
        //declaring variable bf. with data type, BITMAPFILEHEADER (like int, string, char) (E.g. 'int i;')
    BITMAPFILEHEADER bf; //BITMAPFILEHEADER is a new datatype, which contains, bfTpye, bfSize..ect.
    
    // read infile's BITMAPFILEHEADER
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    **/
    
    
    //---- code below was pasted from within the code on 5-Dec-2016----
    //--------------------------------------
            
            //ZYMAYLA's
            //start of a new jpg?
            //yes... do..
                //if(yes)
                    //create a new file, name it accordingly                     //fopen("fileNameCounter.jpg", "w")
                    //write current memory[i] into output                   ////fwrite(&(store[i]), 1, 1, outptr);
            //no... do..
                //if(no)
                    //print not the start of a new jpg
            //already found a jpg?
                //yes... do..
                //no... do..
        //close any remainding files 





                


//-------------------------------------------------------------

    //-ZYMAYLA'S concept explaination
    //-Open memory card file 
    //-Find beginning of jpg 
        //read 512 bytes at a time
    //if there's is an open jpg, close file
    //-else Open a new jpg             //fopen(title, "w");
    //-write 512bytes untill new jpeg is found            //fwrite(&buffer, 512, 1, outfile);
        //when jpeg is found, close
    //-Detect end of file (e.g. once it returns 1 instead of 2 DOGs          fun fact: when using functions in a condition, it will execute the function while checking for the condition...
                                                                                        //if(fread(&bug, sizeof(DOG), 2, ptr) == 1) <--that's how to check for end the file.        
     

//-------------------------------------------------------------
    //Go through first 3 byte of each 512 bytes blocks
            //if the first 3 bytes of 512 byte are JPEG markers(0xff, 0xd8, 0xff) && there is the 4th marker 
            //(which is either of these: 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, of 0xef)    
        /**
        for(int i = 0; i < MEMORYBLOCK; i++)
        {
        fread(&(store[i]), 1, 1, inptr);
        fwrite(&(store[i]), 1, 1, outptr);
        }
        **/
    
//solution 1
    //do
        //for every byte    //for(int i = 0; i < sizeof(card.raw); i++)
            //store byte, byte+1, byte+2, byte+3    //forloop + (fread)
            
            
            //if (store[1],[2],[3] are jpg)
                //if store [4] is jpg
                    //store the next 512-4 bytes
                    //fwrite the 512 byte
                    //i = i + 512
        
            
        //else
            //move on to next bytes
    //while(store[1],[2],[3] are jpg)
    
//solution 2
//once open
    //do
            //for 512 memory                        //for(int i = 0; i < MEMORYBLOCK; i++)
                //read & store 512bytes in memory[i]         //fread(&(store[i]), 1, 1, inptr);
                //read & store four bytes into store[i]
                
        //if store[1],[2],[3],[4] is jpg (start of a new jpg?)
            //if a file is open, close file -- e.g. memory[0 - 512] (yes.)
            //fopen, create a new file                     //fopen("fileNameCounter.jpg", "w")
                //read, store, write next 512bytes into outptr          //(?)outptr = fileNameCounter.jpg //fwrite(&(store[i]), 1, 1, outptr);
                //fileNameCounter ++
                //foundJpg == true
                
        //elseif(foundJpg == true) (already fround jpg)
            //read, store, write next 512bytes into outptr
        //if(foundJpg != true)
            //move store[i] to the next byte. //for every byte in file store[i+1]
        //detect end of file             
        
        //----------graveyard below----
        
        //i = i + 512
    //else 

/**
    //The code below prints it into a text file.
    for(int i = 0; i < 10; i++)
        {
        //read card.raw         
        fread(&(store[i]), 512, 1, inptr);        //read 512 bytes at a time
        fwrite(&(store[i]), 512, 1, outptr);
        }
    
            //do this: read from that block onwards, all 512 byte blocks
            //while none have JPEG markers
    
    printf("stored data in array #2--->%i\n", store[0]);
**/ 

    
   
            //for every file [i]
                //open [i].jpg         //FILE* file = fopen("[i].jpg")
                //write the blocks to output titled [i].jpeg
                //[missing] detect end of file          //if(fread(&bug, sizeof(DOG), 2, ptr) == 1)