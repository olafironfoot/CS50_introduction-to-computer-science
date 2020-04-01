/**
 * bmpTest3.h
 * 
 * CS50 pset4 
 * 
 * '.h' file for refrence by resizeTest3
 * 
 * This file includes .bmp type data files
 * 
 **/
 
 #include <stdint.h>
 
 /**
  * Common Data types, between C and Microsoft
  * http://msdn.microsoft.com/en-us/library/cc230309.aspx
  * 
  * In BITMAPFILEHEADER & BITMAPHEADERINFO, we have got to use datatypes like, WORD, DWORD, LONG. 
  * That is the main reason we need to have an alias, so C knows what BYTE, DWORD, LONG, WORD are.
  * 
  * Because datatypes mean different bits in the two systems, we need this so we can define-
  * how many bit is a data type(e.g. how many bit is a LONG? signed or unsigned?).
  * (FIY A good example is long. On one machine, it might be 32 bits (the minimum required by C). On another, it's 64 bits.))
  * 
  * */
 
 typedef uint8_t BYTE;
 typedef uint32_t DWORD; 
 typedef int32_t LONG;
 typedef uint16_t WORD;
 
 /**
  * BITMAFILEHEADER
  * The BITMAPFILEHEADER structure contains information about the type, size, and layout of a file that contains a DIB.
  * 
  * 
  * */
typedef struct
{
  WORD  bfType;
  DWORD bfSize;
  WORD  bfReserved1;
  WORD  bfReserved2;
  DWORD bfOffBits;
} __attribute__((__packed__))
BITMAPFILEHEADER;

/**
 * BITMAPINFOHEADER
 * The BITMAPINFOHEADER structure contains information about the dimensions and color format of a DIB.
 * 
 * */
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


/**
 * RGB values in a pixel
 * This structure describes a color consisting of relative intensities of red, green, and blue. 
 * The bmciColors member of the BITMAPCOREINFO structure consists of an array of RGBTRIPLE structures.
 * */
typedef struct 
{ 
  BYTE rgbtBlue; 
  BYTE rgbtGreen; 
  BYTE rgbtRed; 
} __attribute__((__packed__))
RGBTRIPLE;


/**
 * note to self:
 * a datatype states what is included in it. (e.g. datatype int = numbers from 1 to 2^32-1) (e.g.datatype string = pointers) (e.g. datatype students = name||house)
 * 
 * students(<--datatype) students(<--variable) [3]
 * students students [3]; <-- declaring a struct
 **/