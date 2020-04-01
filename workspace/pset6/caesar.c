#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

//Get the "key" from user
//argc == argument count, argv == argument vector
int main(int argc, string argv[])

{
    //declaring variables
    bool success = false;
    int k = 0;
    string usersecretmessage = "";
    //guess we can use a "do, while" loop here too.. to get the "return 1" value?
    do
    {
        if(argc != 2)
        {
            //prints instructions and quits program if there's not exactly 2 commands in argument count. 
            printf("please enter a ...key..\n");
            return 1;
        }
        
        else
        {
            {
                k = atoi(argv[1]);
                success = true;
            }
        }
    }while(!success);
            //or you can type, "int k = atoi(argv[1])"
            //printf("%i <-- to check we got the right key\n", k);
           
    
    //Get the "passage" they want to be encrypted
           printf("plaintext: ");
           usersecretmessage = get_string();
           //printf("%s<-- check usersecretmessage\n", usersecretmessage);
            printf("ciphertext: ");
    //Encrypt the "message"
            //int r = 0;
            //the 'for' loop will iterate over each letter in usersecretmessage
            for(int i = 0, n = strlen(usersecretmessage); i < n; i++)
            {
                //first thing to check, is if the character is an alphabet
                if(isalpha(usersecretmessage[i]))
                // made mistake to above code, note to self- int i = interger in the for loop, where as, usersecretmessage[i] = i'th letter of "usersecretmessage"
                {
                     //printf("secret message is alpha\n");

                    //now that we are at the letter level, encrypt each letter of usersecretmessage string AKA usersecretmessage[i].
                    if(islower(usersecretmessage[i]))
                    //encrypted letter = (usersecretmessage letter + key)%26
                    {
                        usersecretmessage[i] = (((usersecretmessage[i] - 97) + k) % 26) + 97;
                        printf("%c", usersecretmessage[i]);
                    }
                    
                    else
                    {
                        usersecretmessage[i] = (((usersecretmessage[i] - 65) + k) % 26) + 65;
                        printf("%c", usersecretmessage[i]);
                    }
                }
               
               else
                {
                    printf("%c", usersecretmessage[i]);
                }
 
        }
    
    
    printf("\n");
    return 0;
}
   //if the letter is.. 
        //if(usersecretmessage[i] >= 'a' && usersecretmessage[i] <=z || usersecretmessage[i] >= 'A' && usersecretmessage [i])
    /**
     * for(int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[2]);
    }
    
    **/
   
   





//Print the encrypted message