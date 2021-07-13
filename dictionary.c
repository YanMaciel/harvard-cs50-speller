// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 3000;

// Hash table
node *table[N];

// Number of words loaded to measure the size of our dictionary.
long word_counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //--------------------------------------------------------------\\
    // 1. Hash word to obtain hash value.                           \\
    // 2. Access linked list at that index in the hash table.       \\
    // 3. Traverse linked list, looking for the word (strcasecmp);  \\
    //--------------------------------------------------------------\\

    // 1. Hash word to obtain hash value.
    int hash_index = hash(word);

    // 2. Access linked list at that index in the hash table.
    node *cursor = table[hash_index];
    while (cursor != NULL)  // if it equals to NULL: it didn't found.
    {
        if (strcasecmp(word, cursor->word) == 0)  // strcasecmp returns 0 if the strings are equal.
        {
            return true;
        }
        cursor = cursor->next;  // if not found, goes to next node in said linked list.
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Source: djib2 by Dan Bernstein. Available at: http://www.cse.yorku.ca/~oz/hash.html.
    // Modified by Reddit user SocratesSatisfied for better understanding.

    unsigned long hash = 5381;
    int c = *word;
    c = tolower(c);  // Assigns the lowercase ASCII value of first letter of the word.

    while (*word != 0)  // Checks end of the string "NULL".
    {
        hash = ((hash << 5) + hash) + c;  // Left-shift: denoted as ‘(x<<y)’ is equivalent to multiplying x with 2^y.
        c = *word++;
        c = tolower(c);
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // -------------------------------------------------//
    // 1. Open dictionary file.                         //
    // 2. Read strings from file one at a time.         //
    // 3. Create a new node for each word.              //
    // 4. Hash word to obtain a hash value.             //
    // 5. Insert node into hash table at that location. //
    // -------------------------------------------------//

    // 1. Open dictionary file:
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // 2. Read strings from file one at a time:
    // Array (buffer) to store each word read from dictionary. Usage: load().
    char curr_word[LENGTH + 1];
    while (fscanf(file, "%s", curr_word) != EOF)
    {
        // 3. Create a new node for each word.
        word_counter += 1;
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, curr_word); // Copy the word into the node.

        // 4. Hash word to obtain a hash value for the linked list.
        unsigned int index = hash(&curr_word[0]);

        // 5. Insert node into hash table at that location.
        if (table[index] == NULL)  // If it's the first value in the table.
        {
            n->next = NULL;
        }
        else
        {
            n->next = table[index];  // New node for the first element of table[index] so we don't lose said linked list.
        }

        table[index] = n;  // Now we reassign the "head" of the linked list to our new element 'n'.
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // While loading, number of words was being counted and here it is;
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)  // Iterates through table[N] to reach each linked list.
    {
        node *cursor = table[i];
        node *tmp = table[i];  // As explained in the Walkthroughs.

        while (true)
        {
            if (cursor == NULL)  // It means that we reached the end of this linked list, so we break out of the while-loop.
            {
                break;
            }
            else
            {
                cursor = cursor->next;
                free(tmp);
                tmp = cursor;
            }
        }
    }
    return true;
}
