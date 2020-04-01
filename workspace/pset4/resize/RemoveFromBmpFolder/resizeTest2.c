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
    
    printf("value of n -> %i\n", n);
    //if negative or decimal
    if (n < 1)
    {
        printf("Please provide a number < 1, and no decimals please\n");
    }
    //below doesn't work because atoi does not convert into decimals****
    if((n % 1) != 0)
    {
        printf("Please provide a number < 1, and no decimals please\n");
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

    printf("bi.biSizeImage pre--> %i\n", bi.biSizeImage);
    
    
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
    printf("%i<-- old bf.bfSize\n", bf.bfSize);
    
    //bi.Size is, size of Image only
    bi.biSizeImage = n * bi.biSizeImage;
    bi.biWidth = n * bi.biWidth;
    bi.biHeight = n * bi.biHeight;
    bf.bfSize = bfStructSize + bi.biSize + bi.biSizeImage;
    printf("%i<-- new bf.bfSize\n", bf.bfSize);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // temporary storage
    RGBTRIPLE triple;
    
    //declare array variable
    RGBTRIPLE array [oldBiWidth];
    RGBTRIPLE * p = &triple;
    // iterate over infile's scanlines
    

        // iterate over pixels in scanline
        for (int j = 0; j < oldBiWidth; j++)
        {
            
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            //store in array
            for(int arrayTimes = 0; arrayTimes < (n - 1); arrayTimes++)
                {
                    array [j] = *p;
                }
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
     
        
    //write to output file
  
        for(int outColumn = 0; outColumn < bi.biWidth; outColumn++)
            {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            
            for(int arrayTimes = 0; arrayTimes < (n - 1); arrayTimes++)
                {
                    //write in stored array to file
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                
            }
        // then add it back 
        for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
    
    //Each line of image data from the original file needs to be processed n times, 
    //meaning that you need to go back and read the input line and reprocess it n times before moving forward
    
    
    

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}