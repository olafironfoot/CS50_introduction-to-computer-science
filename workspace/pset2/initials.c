#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

//capitalize
//string Capitalize(void);

int main(void)
{
{
    //use capitalize function
    string s = GetString();
    
    for(int i = 0, n = strlen(s); i < n; i++)
    {
    //capitalizes
    s[i] = toupper(s[i]);
    }
    
    //prints first char of the "array of strings"
    printf("%c", s[0]);
    
    
    //prints any letter after ' '
     for (int j = 0, n = strlen(s); j < n; j++)
        {
            if (s[j] == ' ')
            printf("%c", s[j+1]);
        }
    
    printf ("\n");
    
}
    
    
    /**
    //print first letter       
                
            printf("%c", s[0]);
               
    //if letter is after space, print.   
    //else check next letter 

    for (int j = 0, n = strlen(s); j < n; j++)
        {
            if (s[j] == ' ')
            printf("%c", s[j+1]);
        }
    
    printf("\n");
    **/
    
/**
string Capitalize(void);

string s;
    //get string from user
    string s = GetString();
    
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                {
                    s[i] = s[i] - ('a' - 'A');
                }
        }   
}

**/        
    
    
    
   
   /** int n;
    * 
    //trying to see if we can break down each letter and find the \0
    for(int i = 0; n = strlen(s); i < n; i++)
        //if (s[l] = \0)

    printf("%c%c\n", s[0], s[\0]);
    **/
    
}