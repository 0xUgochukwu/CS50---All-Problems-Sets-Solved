#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 10000

// Defines struct for a node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[HASHTABLE_SIZE];

// Hashes the word (hash function posted on reddit by delipity)
// The word you want to hash is contained within new node, arrow, word.
// Hashing that will give you the index. Then you insert word into linked list.
int hash_index(char *hash_this)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(hash_this); i < n; i++)
    {
        hash = (hash << 2) ^ hash_this[i];
    }
    return hash % HASHTABLE_SIZE;
}

// count read words
int total_words = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Opens dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // Scans dictionary word by word (populating hash table with nodes containing words found in dictionary)
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Mallocs a node for each new word (i.e., creates node pointers)
        node *n_node = malloc(sizeof(node));
        // Checks if malloc succeeded, returns false if not
        if (n_node == NULL)
        {
            unload();
            return false;
        }
        // Copies word into node if malloc succeeds
        strcpy(n_node->word, word);

        // Initializes & calculates index of word for insertion into hashtable
        int h = hash_index(n_node->word);

        // Initializes head to point to hashtable index/bucket
        node *head = hashtable[h];

        // Inserts new nodes at beginning of lists
        if (head == NULL)
        {
            hashtable[h] = n_node;
            word_count++;
        }
        else
        {
            n_node->next = hashtable[h];
            hashtable[h] = n_node;
            counter++;
        }
    }
    fclose(file);
    return true;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // make word lower case for hash function
    int len = strlen(word);
    char lword[len + 1];
    for (int i = 0; i < len; i++)
    {
        lword[i] = tolower(word[i]);
    }
    lword[len] = '\0';

    int index = hash(lword);
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) != 0)
        {
            cursor = cursor->next;
        }
        else
        {
            return true;
        }

    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *head = NULL;
    node *cursor = head;
    // freeing linked lists
    while (cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return true;
}