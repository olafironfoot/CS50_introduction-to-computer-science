#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please type one keyword\n");
    }
    
    else
    {
    //get keyword (return 1 if not a "keyword")
    string keyword = argv[1];
    printf("%s <-print to check if we got the keyword right\n", argv[1]);
    
    //make sure keyword don't affect code despite being capital or not
    for(int counter = 0, length = strlen(argv[1]); counter < length; counter++)
        {
            if(counter)
            {
                
            }
        }
    
    
    //get sentence to encrypt
    string secretsentence = GetString();
    printf("%s <-print to check if we got the secretmessage right\n", secretsentence);
    
    
    int r = 0;
    //go through each "letter of the sentence" and encrypt it.. for.
    for(int i = 0, n = strlen(secretsentence); i < n; i++)
    
        //(encrypt each "letter of the sentence" based on .. each letter of the "keyword") [c=(p+k)%26]
        //if this "letter of the sentence" is an alphabet
        {
         if (isalpha(secretsentence[i]))
         {
             //get "keyword"'s letter("int argc 2, string argv[][0] <-letter")'s interger and apply(add) it to the "letter of the sentence" 
             /**   
             if (islower(secretsentence[i]))
                {
                    //iterates through each letter of "keyword"
                    for(int j = 0, m = strlen(keyword); j < m; j++)
                    
                     * pretend keyword is ebc, strlen=3, secretsentence == zzzz
                     * 
                     
                    //(how do we get the "keyword"'s letters to cycle back? by the number of count?)
                    //if it is more than "keyword"'s length, go back to first letter argv[][0] (use modulo %)
                    secretsentence[i] = ((((secretsentence[i] - 97 + (keyword[j] - 97) % strlen(keyword))) %26) +97);
                    printf("%c", secretsentence[i]);
                }
               **/
            if (isupper(secretsentence[i]))
                {
                    //iterates through each letter of keyword
                    for(int j = 0, m = keyword[j % strlen(keyword)]; j < m; j++)
                    secretsentence[r] = ((((secretsentence[i] -'A') + (argv[1][j] - 'A')) %26) +'A');
                    printf("%c", secretsentence[r]);
                }
                
         }
        }
        
                
    //print encrypted text
    printf("\n");
    
    }
}




//get key word (return 1 if not a "keyword")
//get sentence to encrypt
//go through each "letter of the sentence" and encrypt it.. for.
    //(encrypt each "letter of the sentence" based on .. each letter of the "keyword")
    //if this "letter of the sentence" is an alphabet
        //get "keyword"'s letter("int argc 2, string argv[][0] <-letter")'s interger and apply(add) it to the "letter of the sentence" 
            //(how do we get the "keyword"'s letters to cycle back? by the number of count?)
            //if it is more than "keyword"'s length, go back to first letter argv[][0]
            
//print encrypted text