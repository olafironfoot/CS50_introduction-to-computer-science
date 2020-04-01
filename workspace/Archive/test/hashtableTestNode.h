/**
 * Testing node and hashtable, see if able to create a linked list
 */

#define LENGTH 45

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

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