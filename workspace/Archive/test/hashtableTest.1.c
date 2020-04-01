/**
 * Create a data structure of node, put data in it, and print data out
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>  //to lower()
#include "hashtableTestNode.h"
#define HASHTABLESIZE 26

//bool check(const char *word);   //prototype
unsigned int size(void); //prototype
bool load(const char *dictionary);   //prototype


int main(int argc, char* argv[])        //debug this!!***** weird now that i turned load into a function... try and make this work.
{
    bool loaded = false;
    int wordCount = 0;
    node* hashtable[HASHTABLESIZE];
    char DicWord[LENGTH];
    
    
    char* dictionary = argv[1];
    
    if(load(dictionary))
    {
        printf("load word!\n");
    }
    
    printf("%i<- wordCount\n", size());
    
} 
bool load(const char *dictionary)
{
    // TODO
    //  * 1. create linked list (Allocate memory to store node) [Done in .h file]
    //  * 2. create hashtable
    //  * 3. populate hashtable with words found in dictionary
    if(argc != 2)
    {
        printf("./hashtableTest.1 small\n");
    }
        //open dictionary small/large [cont here.]
        FILE* fp = fopen(argv[1], "r");
        
        while(fscanf(fp, "%s", DicWord) != EOF)    //this will scan 'fp' for a 'string', and put that string into variable 'word'
        {

    //  * 4. for every word scanned, malloc a node for the word     (new_node will be forgotten and inserted into linklist at end of while() function)
            node *new_node = malloc(sizeof(node));
            if(new_node == NULL)
                {
                    free(new_node);
                    return 1;
                }
    //  * 5. copy word into node
            strcpy(new_node->word, DicWord);
            
    //  * 6. at this point we have a new node with values scanned in from dictionary[no action]
    //  * 7. insert that node into a linked list (don't let go of linked list until, we are sure it's safe. See 9:24)
    //  * 8. use hash function to know which word will be put into which link list (which array number or in this case, hashtable[hashfunction(word)]
            new_node->next = hashtable[hashFunction(new_node->word)];
            hashtable[hashFunction(new_node->word)] = new_node;
            
            //add word count for ever pass
            wordCount++;

            //how to print a link list from a hashtable?
            printf("%s\n", new_node->word);
            //printf("%s\n", node2->word);
            



        }
            printf("dictionary size is.. %i\n", size());
        
           fclose(fp);
           loaded = true;
           return true;
}

/**size funciton, commeting out for now
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 
unsigned int size(void)
{
    // TODO
    //check if dictionary is loaded
   if (!loaded)
   {
       return false;
   }
   else
   {
       return wordCount;
   }
}
**/

/**does not seem like it will work even if the code is right. See file name "hashtableTestTriedUsingOtherPeoplesCode" to see how other people's code also has error
bool check(const char *word)    //remember to debug on 17 Feb 2017!
{   
    // TODO
    // Assume, case insensitive
    // Assume, sting passed in are only alphabets or apostrophes
    
    // ZYMALA's Solution:
    
    //char* word = argv[1];   //assign varible to char word <-- could this be a shadow variable, if so try deleting the statement
    
    //  convert all case to small cap first<-- this is not from Zymala (it is from: http://cs50.stackexchange.com/questions/19991/speller-c-appears-to-be-working-but-is-case-sensitive-cant-recognize-capitol-l)
    node* hashtable[HASHTABLESIZE];
    
    int len = strlen(word + 1);
    char* word2 = malloc(sizeof(len));
    //char word2[strlen(word)];
    strcpy(word2, word);

    
    int i = 0;
    while(i < strlen(word2))    //alternatively, while(i < strlen(word)).. or.. word[i] != NULL; could work too
    {
        if(word2[i] > 'A' && word2[i] < 'Z')  //if characters are between 'A' and 'Z'
        {
            tolower(word2[i]);
        }
        
        i++;
    }
    word2[len] = '\0';
    //  if bucket exisit
    //  which bucket will the word be in? 

    //  //if the word exist, it can be found in the hashtable
    //  search that link list (strcasecmp)
    
    //  Traverse linked list:
    //  question: node* new_node = head?..     //hashtable[bucket]node* new_node = head...?
    
 

    int index = hashFunction(word2);
    node* cursor = hashtable[index];

    //  Assuming true: node* cursor = head;
    //node* cursor = head;
    

     while(cursor != NULL)  //while not at the end of link list
     {
         
         printf("Value of(strcmp(cursor->word, word2) is..%i\n", (strcmp(cursor->word, word2)));
         //do something (compare strings)
         if((strcmp(word2, cursor->word)) == 0)    //if the words are not the same      //see this video for meaning of valgrind error! https://youtu.be/fvTsFjDuag8?t=8m27s
         {
             return true;    //if string compare results in similar words, return true
         }
         
         else
         {
            //if not found, move to next <-- added by erik
            cursor = cursor->next;
                if(cursor == NULL)
                {
                    printf("cursor is NULL after this line!\n");
                }
  
         }
     }
     
     return false;
                                      printf("did we even get to this point?\n");

     //? free(word2);
     //free(word);
}
**/