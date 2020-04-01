#include <stdio.h>
#include <string.h>
#include <cs50.h>




int main(void)

{
    //get string from user
    string s = GetString();
   
    //capitalize
    for (int i = 0, n = strlen(s); i < n; i++)
    //the 'for' loop will iterate over all n'th letters
    {
            if (s[i] >= 'a' && s[i] <= 'z')
                {
                    s[i] = s[i] - ('a' - 'A');
                }
    }            
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
    
        
        
    
    
    
   
   /** int n;
    * 
    //trying to see if we can break down each letter and find the \0
    for(int i = 0; n = strlen(s); i < n; i++)
        //if (s[l] = \0)

    printf("%c%c\n", s[0], s[\0]);
    **/
    
}