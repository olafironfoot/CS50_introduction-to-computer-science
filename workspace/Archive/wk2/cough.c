#include <stdio.h>
#include <cs50.h>

//prototypes
void cough(int n);
void say(string word, int n);
void sneeze(int n);

int main(void)

{
    //cough three times
    cough(4);
    
    //sneeze three times
    sneeze(6);
    
}


/**
 * coughs n times
 */
 
void cough(int n)
{
    say("cough", n);
}


/**
 * Says word n times.
 */
void say(string word, int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%s\n", word);
    }
}
/**
 * Sneeze n times.
 */
 void sneeze(int n)
 {
     say("achoooohoo", n);
 }