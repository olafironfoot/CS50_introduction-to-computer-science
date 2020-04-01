/**
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define ALPHABETS 25   //0 to 25 = 26 numbers in total

//prototypes
char word[LENGTH];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word);

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

/**
 * node for linked list (as per speller/load -2 of 4, walkthrough video, zymala, 6 min mark)
 */
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//this variable has to be declared after node is created
node* hashtable[ALPHABETS];




#endif // DICTIONARY_H
