#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])

{
    //variable declerations
    bool keywordSuccess = false;
    int keywordLength = 0;
    string keyword = "";
    char caesar(char token, int key);
    int key_count = 0;
    
    do
    {
        //get keyword (return 1 if not a "keyword")
        if (argc != 2)
        {
            printf("Please the correct number of words in the command line for the keyword\n");
            return 1;
            
        }
        
        else if(argv[1])
        {
           
            //check if it is alpha (return 1 if any letter is not)
            for(int keywordLetterCounter = 0, keywordlength = strlen(argv[1]); keywordLetterCounter < keywordlength; keywordLetterCounter++)
            {
                
                if(!isalpha(argv[1][keywordLetterCounter]))
                {
                    printf("your input contains illegal characters.\n");
                    return 1;
                }
                
                else
                {
                    keywordSuccess = true;
                    keyword = argv[1];
                    //printf("%c <- character && %d<- index\n", argv[1][keywordLetterCounter], argv[1][keywordLetterCounter]);
                }
            }
            //printf("%c <-first & index of %d <- second letter of keyword captured\n", keyword[0], keyword [1]);
        }
    }
    //successfully confrimed keyword has no non-alphabeticals
    while (!keywordSuccess);
    
    //variable for keyword lenth
    keywordLength = strlen(argv[1]);
    int keycodes[keywordLength];
    //? question the above sentence
    
    //returns the correct index despite upper/lower case
    for(int i = 0; i < keywordLength; i++)
    {
        keycodes[i] = (toupper(argv[1][i]) - 65);
        //printf("%i\n",  keycodes[i]);
    }
            
    //get sentence to encrypt
    string secretsentence = GetString();
    //printf("%s <-print to check if we got the secretmessage right\n", secretsentence);
    
    //go through each "letter of the sentence" and encrypt it.. for.
    for(int i = 0, n = strlen(secretsentence); i < n; i++)
    {
        //process input for parts of secretsentence that are not alphabetical
        if(!isalpha(secretsentence[i]))
        {
            printf("%c", secretsentence[i]);
        }
        
        //process input
        else
        {
            printf("%c", caesar(secretsentence[i], keycodes[key_count]));
            
            if(key_count < keywordLength - 1)
            {
                key_count++;
            }
            else
            {
                key_count = 0;
            }
        }
    }
    
    printf("\n");
    return 0;
}



char caesar(char token, int key)
{
    if(islower(token))
    {
        return((((token - 97)+key)%26)+97);
    }
    else
    {
        return ((((token - 65) + key) %26) +65);
    }
}

    //(encrypt each "letter of the sentence" based on .. each letter of the "keyword")
    //if this "letter of the sentence" is an alphabet
        //get "keyword"'s letter("int argc 2, string argv[][0] <-letter")'s interger and apply(add) it to the "letter of the sentence" 
            //(how do we get the "keyword"'s letters to cycle back? by the number of count?)
            //if it is more than "keyword"'s length, go back to first letter argv[][0]