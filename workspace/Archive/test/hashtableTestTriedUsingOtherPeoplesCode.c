/**
 * Create a data structure of node, put data in it, and print data out
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>  //to lower()
#include "hashtableTestNode.h"
#define HASHTABLESIZE 10

bool check(const char *word);   //prototype

int main(int argc, char* argv[])
{
    node* hashtable[HASHTABLESIZE];
    int word_count = 0;
    bool loaded = false;
    if (argc != 2)
    {
        printf("argc needs to be 2\n");
    }
    
    for (int i = 0; i < HASHTABLESIZE; i++)
    {
        hashtable[i] = NULL;
    }
    
    // open dictionary
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    while (true)
    {
        // malloc a node for each new word
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not malloc a new node.\n");
            return false;
        }
        
        // read a word from the dictionary and store it in new_node->word
        fscanf(fp, "%s", new_node->word);
        new_node->next = NULL;
        
        if (feof(fp))
        {
            // hit end of file
            free(new_node);
            break;
        }

        word_count++;
        
        // hashtable[h] is a pointer to a key-value pair
        int h = hashFunction(new_node->word);
        node* head = hashtable[h];
        
        // if bucket is empty, insert the first node
        if (head == NULL)
        {
            hashtable[h] = new_node;
        }
        // if bucket is not empty, attach node to front of list
        // design choice: unsorted linked list to minimize load time rather
        // than sorted linked list to minimize check time
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
        }
        printf("new_node->word is.. %s\n", new_node->word);
        
        if (check(new_node->word))
        {
            printf("no misspelling!\n");
        }
        else 
        {
            printf("missspelling!\n");
        }
    }
    // close dictionary
    fclose(fp);
    loaded = true;
    return true;
}

bool check(const char* word)
{
    // create char array to store copy of word
    // word is a const char* and non-read actions cannot be performed on it
    node* hashtable[26];
    int len = strlen(word);
    char word_copy[len + 1];
    
    // convert word to lowercase and store it in word_copy
    for (int i = 0; i < len; i++)
    {
       word_copy[i] = tolower(word[i]);
    }
    
    // add null terminator to end of char array
    word_copy[len] = '\0';
    
    // get hash value (a.k.a. bucket)
    int h = hashFunction(word_copy);
    
    // assign cursor node to the first node of the bucket
    node* cursor = hashtable[h];
    
    // check until the end of the linked list
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, word_copy) == 0)
        {
            // word is in dictionary
            return true;
        }
        else
        {
            // check next node
            cursor = cursor->next;
        }
    }
    return false;
}

