/**
 * Jpg.h
 * 
 * CS50 pset4 
 * 
 * '.h' file for refrence by recover.c
 * 
 * This file includes jpeg type data files
 * 
 **/

#include <stdint.h>
typedef uint8_t BYTE;

 
 /**
  * BITMAFILEHEADER
  * The BITMAPFILEHEADER structure contains information about the type, size, and layout of a file that contains a DIB.
  * 
  * 
  * */
/**
 * typedef struct
{
  BYTE identifierI;
  BYTE identifierII;
  BYTE identifierIII;
  BYTE identifierIV;
} __attribute__((__packed__))
IDENTIFIER;
**/
/**
 * BITMAPINFOHEADER
 * The BITMAPINFOHEADER structure contains information about the dimensions and color format of a DIB.
 * 

typedef struct
{
  DWORD biSize;
  LONG  biWidth;
  LONG  biHeight;
  WORD  biPlanes;
  WORD  biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG  biXPelsPerMeter;
  LONG  biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} __attribute__((__packed__))
BITMAPINFOHEADER;


 * RGB values in a pixel
 * This structure describes a color consisting of relative intensities of red, green, and blue. 
 * The bmciColors member of the BITMAPCOREINFO structure consists of an array of RGBTRIPLE structures.
 * ----
typedef struct 
{ 
  BYTE rgbtBlue; 
  BYTE rgbtGreen; 
  BYTE rgbtRed; 
} __attribute__((__packed__))
RGBTRIPLE;



 * note to self:
 * a datatype states what is included in it. (e.g. datatype int = numbers from 1 to 2^32-1) (e.g.datatype string = pointers) (e.g. datatype students = name||house)
 * 
 * students(<--datatype) students(<--variable) [3]
 * students students [3]; <-- declaring a struct
 
 **/