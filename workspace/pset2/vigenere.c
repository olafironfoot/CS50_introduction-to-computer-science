#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//prototype

int main(int argc, string argv[])

{
    
    if (argc == 1)
        {
            printf("please enter only/at least one word after command line\n");
            return 1;
        }
        
//variable declarations
string userMessage = "";
int keyword[strlen(argv[1])];
int keyLength; 
//length of keyword
keyLength = strlen(argv[1]);
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
      
      
    //for each letter in the keyword make it a caps
    for(int i = 0; i < keyLength; i++)
        {   

            
            //stored in "keyword[array number]" by the line below:
            keyword[i] = toupper(argv[1][i]);
            
            //stored in keyword[j] is index number of shift
            keyword[i] = (keyword[i] - 'A');
            //printf("%i<-- shift letter by..\n", keyword[i]);
            
    
            
            //when you do increment the key index, is it equal to the length of the key? 
            //If it is, just reset it to 0. If not, just increment it and move on
        
        }


//printf("keyword[2] Shifts letter by...%i\n", keyword[2]);
//printf("keyword[4] Shifts letter by...%i\n", keyword[4]);
int j = 0;
int k = 0;
    //encrypt user message
    //for each letter of the user message
    for (int i = 0, n = strlen(userMessage); i < n; i++)
        {
            
            //do nothing if it's not alphabet
            if(!isalpha(userMessage[i]))
                {
                    printf("%c", userMessage[i]);
                }
            
             //wrapping the keyword...?
            else
            {
            keyApplied[k] = keyword[j % (keyLength)];
            j++;
            //printf("running through keyword[i].. we are at number %i of [i] now.. \n", j);
            //printf("%i<-- testing keyApplied values, second letter\n", keyApplied[j]);
            }
            
            //if alphabet
            //shift it by the keyword index
            //ensure it wraps around the 26 alphabets
            if(isupper(userMessage[i]))
                {
                    
                    userMessage[i] = (((userMessage[i] - 'A') + keyApplied[k]) % 26) + 'A';
                    printf("%c", userMessage[i]);
                    //printf("%i<-printing encrypted letter, %i<--print keyword shift[j]\n", encrypted[i], keyword[j]);
                }
            else if(islower(userMessage[i]))
                {
                    userMessage[i] = (((userMessage[i] - 'a') + keyApplied[k]) % 26) + 'a';
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