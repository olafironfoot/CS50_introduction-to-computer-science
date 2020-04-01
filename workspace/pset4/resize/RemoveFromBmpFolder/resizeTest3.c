/**
 * CS50 pset4/resize
 * 
 * by Erik
 * 
 **/
 
 #include <stdio.h>
 #include <cs50.h>
 
 #include "bmpTest3.h"
 
 
 
int main(int argc, char* argv[])
{
     
 //Create variable for, 'resize amt', 'infile', 'outfile'
 if(argc != 4)
 {
  printf("please type in ./resize (times) (input filename) (output filename)\n");
 }

 //assign each of users input to a variable/pointer
 //and Ensure correct inputs for each input value 
 //(e.g if argv[1] != >0, do...) 
 int n = atoi(argv[1]);
 if(argv[1] == NULL)
 {
  printf("please give number of times to resize\n");
  return 2;
 }
 
 //if n, or argv[1] is less than 1, or a number that is not a whole number, corect and ask again
 if(n < 1 || (n % 1) != 0)
 {
  printf("please ensure value is more than 1 and is a whole number\n");
  return 3;
 }

 char* infile = argv[2];

 
 char* outfile = argv[3];


 
 //[done in "bmpTest3.h"] create structs for easy reference/abstract those details away. Do so for pixels, bmpfile, bmpinfo. Use .h file.
 
 //fopen files, store in variable/create pointer for easy recall 'inptr' and 'outptr' (in file as “r” and out file as “w”)
 //remember to have (if = null) and handle error
 FILE* inptr = fopen("infile", "r");
 if(inptr == NULL)
 {
  printf("infile/argv[2] does not exist.\n");
  return 1;
 }
 
 FILE* outptr = fopen("outfile", "w");
 if(outptr == NULL)
 {
  printf("unable to create out file name.\n");
  return 1;
  //****question, do we return 1 for both fopens?.. check resizeTest.c
 }
 
 //read and store bmp file headers only, using fread(&bf||*bf(<--void* ptr), sizeof(BITMAPFILEHEADER)(<---size_t size), 1(<--size_t blocks), inptr<--(FILE* fp));, store it in &memory 'bf'
 BITMAPFILEHEADER bf; //instead of int "variable"= 2^32 numbers, BITMAPFILEHEADER "variable" = allows only they defined values, which are, bfType;bfSize;bfReserved1;bfReserved2;
 fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
 
 //read and store bmp information only, store it in &address 'bi', aka "buffer"
 BITMAPINFOHEADER bi; 
 fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

 //check through header files that it is indeed bmp
 //return fail statement if (bf != 14 || bi != 40 || bf.bfType != BM ||... more)
 if(bf.bfType != 0x4d42 || bf.bfReserved1 != 0 || bf.bfReserved2 != 0 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0) //the ones in these lines are directly from copy.c that erik missed out. :(
 {
  printf("please ensure it's a bitmap, .bmp file type, thanks!\n");
  return 6;
 }
 
 //write new header files with new header values ****
 fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
 fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);



  //padding formula
  int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

 


  RGBTRIPLE triple;
  //THE ARRAY METHOD

  //for every pixel top to bottom, (aka end of a left to right line)
  for(int inTopToBottomPixel = 0, height = abs(bi.biHeight); inTopToBottomPixel < height; inTopToBottomPixel++)
  {
    //and for every pixel left to right,
    for(int inLeftToRightPixel = 0; inLeftToRightPixel < bi.biWidth; inLeftToRightPixel++)
    {
     //remember pixels in an array,
     fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
     int arrayIn[inLeftToRightPixel][inTopToBottomPixel] = triple;

      //multiply the pixels by n for top to bottom (aka number of rows)
      for(int multiplyRows = 0; multiplyRows < n; multiplyRows++)
      {
      //multiply left to right values by n,
       for(int multiplyColumns = 0; multiplyColumns < n; multiplyColumns++)
       {
       //write array as many times as needed, include padding (this is for one row)
       fputc(int* arrayIn[inLeftToRightPixel][inTopToBottomPixel], outptr); //fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
       //write the array
       
       }
       for (int k = 0; k < padding; k++)
       {
           fputc(0x00, outptr);
       }       
      }
    }
   }
      
    //remember to close opened files

   // close infile
   fclose(inptr);

   // close outfile
   fclose(outptr);

   // that's all folks
   return 0;    
       
 }
 
     //THE FSEEK METHOD
 
      //read on to next line(for each value in height)
       //do this n times
        //move cursor back to first pixel of the width
         //read next pixel(for each value in width)
          //read inptr
           //do this n times
            //write from &triple to 'outptr'
       
     
     //------------------
 
     //**the below is my first attempt at the reading and writting
     //for every pixel top to bottom, for rows(height)
      //(multiply height by n times, because hight need to be resized)
       //cursor to be reset to beginning of left to right
        //for each pixel left to right, for column(width)
         //read and store file content from inptr, store it in &memory 'triple'
     
          //Multiply width by n times
          