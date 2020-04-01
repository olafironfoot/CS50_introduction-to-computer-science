/**
 * copy.c to resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * to do:
 * //argc should now be 4
 * //set conditions for error on n (times of resize)
 * //fields to modify for bf & bi? (suggested by Pset) - bi.Size, bi.Width, bi.Height * n 
 * //add or subtract padding per scanline? (suggested by Pset) - apply formula 
 * //double the pixel, next to one another on each scan line - RGBTRIPLE * n 
 * 
 * 
 * 
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#define bfStructSize 14

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 2;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    
    
    //resize image, n times
    int n;
    n = atoi(argv[1]);
    
    //if no input
    if (argv[1] == NULL)
    {
        printf("Please tell us, how many times you'd like to resize\n");
    }
    
    //printf("value of n -> %i\n", n);
    //if negative or decimal
    if (n < 1)
    {
        printf("Please provide a number < 1, and no decimals please\n");
        return 1;
    }
    //below doesn't work because atoi does not convert into decimals****
    if((n % 1) != 0)
    {
        printf("Please provide a number < 1, and no decimals please\n");
        return 1;
    }


    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    //declaring variable bf. with data type, BITMAPFILEHEADER (like int, string, char) (E.g. 'int i;')
    BITMAPFILEHEADER bf;
        
    // read infile's BITMAPFILEHEADER
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    //----------------End of error reporting-----------
    
//fields to modify for bf & bi? (suggested by Pset) - bi.Size, bi.Width, bi.Height

    //printf("bi.biSizeImage pre--> %i\n", bi.biSizeImage);             //removing this cause check50 doesn't take it
    
    
    //resizing header files--> bf.Size(?), bi.Size(?), bi.Height, bi.SizeImage, bi.Width
    
    //keep old values somewhere [delete this if there is no use for old values, dangit zymayla..]
    int oldSizeImage;
    oldSizeImage = bi.biSizeImage;
    
    int oldBiWidth;
    oldBiWidth = bi.biWidth;
    
    int oldBiHeight;
    oldBiHeight = bi.biHeight;
    
    //no need bi.bisize, because it's the size required by the structure
    //int oldBiSize;
    //oldBiSize = bi.biSize;
    
    int oldBfSize;
    oldBfSize = bf.bfSize;
    
    
    //[Old check] printf("%i<--- sizeImageOld\n", sizeImageOld);
    //printf("%i<-- old bf.bfSize\n", bf.bfSize);               //removing this cause check50 doesn't take it
    
    //bi.Size is, size of Image only
    bi.biWidth = n * bi.biWidth;
    bi.biHeight = n * bi.biHeight;

//add or subtract padding per scanline? (suggested by Pset) - apply formula 
    // determine padding for scanlines for outptr
    int paddingOutptr =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //determine padding for inptr picture
    int paddingInptr = (4 - (oldBiWidth * sizeof(RGBTRIPLE)) % 4) % 4; 

    //bi.biSizeImage = n * bi.biSizeImage;    //bi.biSizeImage should be .. ((bi.biWidth)* abs(bi.biHeight) * sizeof(RGBTRIPLE)) + paddingOutfile;
    bi.biSizeImage = abs(bi.biHeight) * ((bi.biWidth * sizeof (RGBTRIPLE)) + paddingOutptr);

    //bf.bfSize = bfStructSize + bi.biSize + bi.biSizeImage;
    bf.bfSize = bi.biSizeImage + sizeof (BITMAPFILEHEADER) + sizeof (BITMAPINFOHEADER); 

    //printf("%i<-- new bf.bfSize\n", bf.bfSize);               //removing this cause check50 doesn't take it
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    
    // temporary storage (initalizing triple, of datatype-> RGBTRIPLE)
    RGBTRIPLE triple;
    // iterate over infile's scanlines
    for (int i = 0, oldHeight = abs(oldBiHeight); i < oldHeight; i++)
        {
            //multiple that oldHeigh to get new height
            for(int m = 0; m < n; m++)
            {
                //move the cursfind  position of CUR (within the line/row, SEEK_SET goes to the front of the row again)
                fseek(inptr, (bfStructSize + bi.biSize) + (((oldBiWidth * 3) + paddingInptr) * i), SEEK_SET);
            
                //read old file width
                for(int o = 0; o < oldBiWidth; o++)
                {
                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                                   
                    for(int q = 0; q < n; q++)
                    {
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
                }
            
            
                //on the same line, add the padding back
            for (int k = 0; k < paddingOutptr; k++)
                {
                    fputc(0x00, outptr);
                }       
        
            }
        } 
            
    
            
            //vertically.. fseek, read back to 

            
            
            //small.bmp has padding (not multiple of 4) remember to skip padding
            //skip last read.. somehow..

             

    

            
        
            
        


            //****have to multiply height too!
            //****check if fseek is done correctly. or if fwrite(line 160) is done right..
            //****for fwrite, one option is to write out 1 wideth of scanline .. to see if 'small.bmp' is correctly laid out or not
            
            /**

            **/
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
    
//--------graveyard below---
            /**
             * triple.rgbtBlue = n * triple.rgbtBlue;
            triple.rgbtGreen = n * triple.rgbtGreen;
            triple.rgbtRed = n * triple.rgbtRed;
            
            //allocate more memory first ****
            char* space = malloc(sizeof(RGBTRIPLE) * 10);
            space = "riwhiw";
            printf("%i\n", triple.rgbtGreen);
            
            for(int l = 0; l < n; l++)
            {
            fwrite(&triple.rgbtGreen, sizeof(space), 1, outptr);
            }
            **/
            
            
                            /**
                //fputc paddings at the end of each scanline
                for (int m = 0; m < padding; m++)
                {
                    printf("inserting paddin..\n");
                    fputc(0x00, outptr);
                }
                **/
        //-------------------------------
    /**
             RGBTRIPLE * p = &triple;
            printf("%p<--stored in pointer/&triple\n", p);
                 
            //amount of bytes to move back, each pixel = 3 bytes, bi.biWidth = n.o of pixel
            int size = sizeof(RGBTRIPLE);
            int moveBack = bi.biWidth * size + padding;
            
            fseek(inptr, -(moveBack), SEEK_CUR);
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            for (int l = 0; l < n; l++)
            {
                //write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
            **/

