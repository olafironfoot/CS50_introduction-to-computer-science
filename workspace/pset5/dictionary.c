/**
 * Implements a dictionary's functionality.
 * 
 * Erik:" to check if word is true from a dictionary loaded into memory, while returning 
 * number of words in dictionary"
 */

#include <stdbool.h>
#include <string.h> //for strcmp
#include <ctype.h>  //for tolower()
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"


//declare global attributes
int wordCount = 0;

bool loaded = false;
/**
 * hasFunction to be used for identifying first character of string
 */
int hashFunction(char* word)
     {
         int index = 0;
         //if first char of word - beginning of asiic = index
         index = word[0] - 'a';   //'a' = 97
         return index;
     }

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)    //remember to debug on 17 Feb 2017!
{
    // TODO
    // Assume, case insensitive
    // Assume, sting passed in are only alphabets or apostrophes
    
    // ZYMALA's Solution:
    // TODO
    // Assume, case insensitive
    // Assume, sting passed in are only alphabets or apostrophes
    
    // ZYMALA's Solution:
    
    //char* word = argv[1];   //assign varible to char word <-- could this be a shadow variable, if so try deleting the statement
    
    //  convert all case to small cap first<-- this is not from Zymala (it is from: http://cs50.stackexchange.com/questions/19991/speller-c-appears-to-be-working-but-is-case-sensitive-cant-recognize-capitol-l)
    
    int len = strlen(word);
    char tempWord[len + 1];
    //char* tempWord = malloc(sizeof(len + 1));     //suspect this is causing memory leaks?
    //char tempWord[strlen(word)];
    //strcpy(tempWord, word);   //if you do this, it results in invalid read of size 1, suspect its because tmpWord is 1 more char than word..?

    
    for (int i = 0; i < len; i++)
    {
       tempWord[i] = tolower(word[i]);
    }
    tempWord[len] = '\0';
    //  if bucket exisit
    //  which bucket will the word be in? 

    //  //if the word exist, it can be found in the hashtable
    //  search that link list (strcasecmp)
    
    //  Traverse linked list:
    //  question: node* new_node = head?..     //hashtable[bucket]node* new_node = head...?
    
 

    int index = hashFunction(tempWord);
    node* cursor = hashtable[index];
 

    //  Assuming true: node* cursor = head;
    //node* cursor = head;
                   
                    
     while(cursor != NULL)  //while not at the end of link list
     {
         //do something (compare strings)
         if((strcmp(tempWord, cursor->word)) != 0)    //if the words are not the same
         {
             //if not found, move to next <-- added by erik
             cursor = cursor->next;

         }
         
         else
         {
            
            //free(tempWord);
            return true;    //if string compare results in similar words, return true
         }
     }
     //free(tempWord);
     return false;

     //free(tempWord);
     //free(word);
}
    
    
    /**
     * erik attempt number 1.. 
    char* word = argv[1];   //assign varible to char word <-- could this be a shadow variable, if so try deleting the statement
    
    //  convert all case to small cap first<-- this is not from Zymala (it is from: http://cs50.stackexchange.com/questions/19991/speller-c-appears-to-be-working-but-is-case-sensitive-cant-recognize-capitol-l)
    int i = 0;
    while(word[i] != NULL)    //alternatively, while(i < strlen(word)); could work too
    {
        if(word[i] > 'A' && word[i] < 'Z')  //if characters are between 'A' and 'Z'
        {
            tolower(word[i]);
        }
        
        i++;
    }
    //  if bucket exisit
    //  which bucket will the word be in? 

    //  //if the word exist, it can be found in the hashtable
    //  search that link list (strcasecmp)
    
    //  Traverse linked list:
    //  question: node* new_node = head?..     //hashtable[bucket]node* new_node = head...?
    head = hashtable[hashFunction(word)];
    
    //  Assuming true: node* cursor = head;
    node* cursor = head;
    
     while(cursor != NULL)
     {
         //do something (compare strings)
         if(strcmp(word, new_node->word) != 0)
         {
             //if not found, move to next <-- added by erik
             cursor = cursor-> next;
         }
         
         else
         {
            return true;    //if string compare results in similar words, return true
         }
     }
     
     return false;
    **/
    /**
     * ZYMALA's Soultion:-
     * 
     * if bucket exisit
     * which bucket will the word be in? index = hashtable[hashFunction(word)]
     * 
     * //if the word exist, it can be found in the hashtable
     * convert all case to small cap first<-- this is not from Zymala (it is from: http://cs50.stackexchange.com/questions/19991/speller-c-appears-to-be-working-but-is-case-sensitive-cant-recognize-capitol-l)
     * search that link list (strcasecmp)
     * 
     * Traverse linked list:
     * question: node* new_node = head?..
     * Assuming true:
     * node* cursor = head;
     * while(cursor != NULL)
     * {
     * do something (compare strings)
     * cursor = cursor-> next;
     * }
     * 
     * 
     * Erik's attempt:
     * 
     * //not sure if it works, 
     * //but char while((ch = fgetc(ptr)) = !EOF <- in stdio.h)
     * //printf("%c", ch);
    
     */
    
    

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    //  * 1. create linked list (Allocate memory to store node) [Done in .h file]
    //  * 2. create hashtable

    //  * 3. populate hashtable with words found in dictionary
        
        //open dictionary small/large [cont here.]
        FILE* fp = fopen(dictionary, "r");  //trying this instead of using argv[1]...
        if (fp == NULL)
        {
            printf("Could not open dictionary.\n");
            return false;
        }
        
        while(fscanf(fp, "%s", word) != EOF)    //this will scan 'fp' for a 'string', and put that string into variable 'word'
        {
    //  * 4. for every word scanned, malloc a node for the word     (new_node will be forgotten and inserted into linklist at end of while() function)
            node* new_node = malloc(sizeof(node));
            if(new_node == NULL)
                {
                    printf("Could not malloc a new node.\n");
                    return false;
                }
            
            else if (feof(fp))  //this one is from the reference: https://github.com/davidventuri/harvard-cs50/blob/master/pset5/dictionary.c
            {
                // hit end of file
                free(new_node);
                break;
            }
    //  * 5. copy word into node
            strcpy(new_node->word, word);
            
    //  * 6. at this point we have a new node with values scanned in from dictionary[no action]
    //  * 7. insert that node into a linked list (don't let go of linked list until, we are sure it's safe. See 9:24)
    //  * 8. use hash function to know which word will be put into which link list (which array number or in this case, hashtable[hashfunction(word)]
    //  * 9. hash the word
            
            //testing out with "head", head is the very first element of the hashtable's hashfunction
            // node* head = hashtable[hashFunction(new_node->word)];
            // new_node->next = head;
            // head = new_node;
            
            //original, working code is below
            new_node->next = hashtable[hashFunction(new_node->word)];
            hashtable[hashFunction(new_node->word)] = new_node;
            
            //add to word count
            wordCount ++;
   
        }
        
        //if successfully executes all the above code without failing, that means it's loaded
            //close dictionary
            fclose(fp);
            //change global loaded to true so can be used in size()
            loaded = true;
            //give return value for this bool load() function
            return true;
        
}    
    
    /**Zymayla's walkthrough:
     * 1. create linked list (Allocate memory to store node)
     * 2. create hashtable
     * 3. populate hashtable with words found in dictionary
     *      e.g. while(fscanf(file, "%s", word) != EOF)
     *              {
                        ...
                    }
            
     * 4. for every word scanned, malloc a node for the word
            e.g. node *new_node = malloc(sizeof(node));
            if(new_node == NULL)
            {
                unload();
                return false;
            }
     * 5. copy word into node
            e.g. strcpy(new_node->word, word);
            
     * 6. at this point we have a new node with values scanned in from dictionary
     * 7. insert that node into a linked list (don't let go of linked list until, we are sure it's safe. See 9:24)
     * 8. use hash function to know which word will be put into which link list
            -takes a string
            -returns an index
                -index<the number of buckets
            -deterministic
                -the same value need to map to the same bucket every time
            e.g. when hashing the word 'apple', it should give the same index everytime. wheather or not, putting into dictionary for 1st time, or checking it later.
     * 9. hash the word
            -new_node->word has the word from the dictionary
            -hashing new _node->word will give us the index of a bucket in the hash table
            -insert into the linked list
            
     * 
     */
    
    /**
     * --Erik's attempt--
    // for every word till size()
        
        //create a hash-table (an array of buckets)
        node *hashtable[ALPHABETS]; //number of alphabets = number of buckets
        //e.g. int array[26]
        
        //TO DO, seperate words(dictionary) into buckets <--- stopped here****
            //detect which Alphabet the word starts with
        //form a link list within the bucket
        
        //for each bucket
        for(int bucket = 0; bucket < ALPHABETS; bucket++)
        {
            //create enough memory to store the node
            node *node1 = malloc(sizeof(node));
            
            if(node1 == NULL)
            {
                unload();
                return false;
            }            
            
            
            //e.g. array[bucket] = 1
            hashtable[bucket] = node1;

        }
        
        //open dictionary small/large [cont here.]
        FILE* fp = fopen(argv[1], "r");
        
        //if word starts with an Alphabet, || for every bucket, put in words that are 97++ 
        for(int bucket = 0; bucket < ALPHABETS; bucket++)
        {
            if(fgetc(fp) = 97 + bucket) //if alphabet is "a".. on each loop, becomes, if is "b", if is "c"..
            {
                strcpy(node1.word, fp);
                
                //do we need a for loop here with node numbers?..
                
                //while it encouters a "\n"
                while(fgetc(fp) = '\n')
                {
                    //do we need to seekcur 1 step over? or fseek length of word?
                    strcpy(node1.word, fp); //it copies the word where the file pointer is in fp, into node1.word (*remember to* Check if "fp" = where filepointer is currently..)
                }
            }
        }

        //put it into the alphabet's node (which is the start of a bucket)
        fscanf()
        
        //copy word into node
        strcpy(node1->word, word);
        
        // if Alphabet, put into hashtable of the appropriate node

        // Ensure size is equilivant to the memory of the dictionary
        
            //for every word read, use function, check()
            
        --End of Erik's attempt--
        */
    


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    // if loaded
    if(loaded)
    {
        return wordCount;
    }
    
    else
    {
    return 0;
    }
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO Erik's attempt #1
    //go through each hashtable (bucket) 
    for(int i = 0; i < ALPHABETS; i++)
    {
        //go through each linked list
        node* head = hashtable[i];
        node* cursor = head; 
        //node* cursor = hashtable[i];
        
        //free each memory          ****Needs attention here, might not compile, because deleter 
        while(cursor != NULL)
        {
            //point temp to stard to list
            node* temp = cursor;
            //move curosr to next in the list
            cursor = cursor->next;
            //free temp
            free(temp);
        }
    }

    loaded = false;
    
    return true;
}
