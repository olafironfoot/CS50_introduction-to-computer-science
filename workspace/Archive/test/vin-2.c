#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>



int main(int argc, string argv[])

{
//prototype
//int x = 0;
string keyword = argv[1];
//printf("%s\n", keyword);
//int j;
//userMessageLength = 10;

//variable declarations
string userMessage = "";
int keyword[strlen(argv[1])];
int keyLength; 
//length of keyword
keyLength = strlen(argv[1]);
int keyCount = 0;

int j = 0;
//int keyApplied[j]; 
char *keyApplied = argv[1];





//get user keyword
    //ensure it is only 1 word
    if (argc != 2)
        {
            printf("please enter only/at least one word after command line\n");
            return 1;
        }
    else
        {

        //for each letter
        for(int i = 0, n = strlen(argv[1]); i < n; i++)
            {
                //reject user keywords if non-alpha is present
                if(isalpha(argv[1][i]))
                    {
                        printf("%c <-letters success\n", argv[1][i]);
                        
                    }
               
               else
                    {
                        printf("keyword contains non-alphabets\n");
                        return 1;
                    }

        
            }
    
    
    
    //get user message
    userMessage = GetString(); 
      
      
    //for each letter in the keyword
    for(int i = 0; i < keyLength; i++)
        {   

            
            //stored in "keyword[array number]" by the line below:
            keyword[i] = toupper(argv[1][i]);
            
            //stored in keyword[j] is index number of shift
            keyword[i] = (keyword[i] - 65);
            printf("%i<-- shift letter by..\n", keyword[i]);
            
            keyCount++;

            
            //when you do increment the key index, is it equal to the length of the key? 
            //If it is, just reset it to 0. If not, just increment it and move on
        
        }
        //wrap around the length of the keyword
            //to keep repeating keyword over length of user message
            //strlen(usermessage) %strlen(argv[1])
                


    //encrypt user message
    //for each letter of the user message
    for (int i = 0, n = strlen(userMessage); i < n; i++)
        {
            
            //wrapping the keyword...?
            keyApplied[j] = keyword[i] % keyLength;
            printf("%i<-- testing keyApplied values, second letter\n", keyApplied[j]);
            
        }
    /**
     * 
    for(int i = 0, n = userMessageLength; i < n; i++)
        {
            
        
            printf("%c-- printing letters\n", keyword[i]);
            
            if(keyword[i] < strlen(keyword - 1))
            {
                i ++;
            }
            else
            {
                keyword[i] = 0;
            }

        }
}  
        **/
    
    /**
    //variable for keyword lenth
    keywordLength = strlen(argv[1]);
    int keycodes[keywordLength];
    //? question the above sentence
    
    //returns the correct index despite upper/lower case
    for(int i = 0; i < keywordLength; i++)
    {
        keycodes[i] = (toupper(argv[1][i]) - 65);
        printf("%i\n",  keycodes[i]);
    }
    **/
        
         


/**
//returns the correct index despite upper/lower case
    for(int i = 0; i < keywordLength; i++)
    {
        keycodes[i] = (toupper(argv[1][i]) - 65);
        printf("%i\n",  keycodes[i]);
    }
    **/
        }