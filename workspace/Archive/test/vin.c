#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//prototype

int main(int argc, string argv[])

{
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
//string keyword = "";
//ensure caps and normal letters give the same index
//variables declared below this line:
//int key_count;
//int encrypted[strlen(userMessage)];


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
                        //printf("%c <-letters success\n", argv[1][i]);
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
            //printf("%i<-- shift letter by..\n", keyword[i]);
            
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
            keyApplied[j] = keyword[i % (keyLength)];
            //printf("%i<-- testing keyApplied values, second letter\n", keyApplied[j]);
               
            //do nothing if it's not alphabet
            if(!isalpha(userMessage[i]))
                {
                    printf("%i", userMessage[i]);
                }
                
            //if alphabet
            //shift it by the keyword index
            //ensure it wraps around the 26 alphabets
            else if(isupper(userMessage[i]))
                {
                    
                    userMessage[i] = (((userMessage[i] - 65) + keyApplied[j]) % 26) + 65;
                    printf("%c", userMessage[i]);
                    //printf("%i<-printing encrypted letter, %i<--print keyword shift[j]\n", encrypted[i], keyword[j]);
                }
            else if(islower(userMessage[i]))
                {
                    userMessage[i] = (((userMessage[i] - 97) + keyApplied[j]) % 26) + 97;
                    printf("%c", userMessage[i]);
                    

                }

            
            /**
            //keycount
            for(int k = 0; k < keyLength ; k++)
            {
                keyCount = k++;
            
                
            //If you increment c, and then modulo, 
            //it will not change anything when c < key length, 
            //and will reset to 0 when c = key length.
            if (keyCount == keyLength - 1)
                {
                 k = 0; 
                }
            }
            **/
        }
//print encrypted message with an enter sign
printf("\n");
//printf("%i<--- keyCount, %i <---keyApplied second letter of key\n", keyCount, keyApplied[1]);

}







//get user keyword
    //for each letter
        //reject user keywords if non-alpha is present
        //get it's index
        //wrap around the length of the keyword
    //The funciton above should spit out index repeatly. 
    
//get user message

//encrypt user message
    //for each letter of the user message
        //do nothing if it's not alphabet
        //if alphabet
            //shift it by the keyword index
            //ensure it wraps around the 26 alphabets
            
//print encrypted message


//question at the end, how does global variables work, do they work?
//how are arrays recorded, do they last past an {}argument?
}