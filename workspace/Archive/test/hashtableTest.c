/**
 * Create a data structure of node, put data in it, and print data out
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtableTestNode.h"
#define HASHTABLESIZE 1

int main(void)
{
    node* hashtable[HASHTABLESIZE];
    node* node1;    //node1 is a variable, node is the data structure (e.g. int node1)
    node* node2; 
    
    //create enough memory to store the node
    node2 = malloc(sizeof(node));
    
    if(node2 == NULL)
    {
        free(node2);
        return 1;
    }  
    
    
    for(int bucket = 0; bucket < HASHTABLESIZE; bucket++)
        {
            //create enough memory to store the node
            node1 = malloc(sizeof(node));
            
            if(node1 == NULL)
            {
                free(node1);
                return 1;
            }            
            
            
            //e.g. array[bucket] = 1
            hashtable[bucket] = node1;

        }
    // node2->word = "wa" (Cannot be done because arrays in C are not assignable. "char word[LENGTH + 1]" http://stackoverflow.com/questions/1292586/char-array-in-a-struct-incompatible-assignment)
    
    
    strcpy(node1->word, "foo");
    strcpy(node2->word, "yo");
    node1->next = node2;
    
    printf("%s\n", node1->word);
    printf("%s\n", node2->word);
    
    free(node1->word);
    free(node2->word);
    
}

