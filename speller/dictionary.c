// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26;

int dictionarysize = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);

    node *temp = table[index];

    while(temp != NULL)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    if (strlen(word) == 1)
    {
        return ((int)(toupper(word[0]) - 'A') * 26);
    }
    else
    {
        return ((int)(toupper(word[0]) - 'A') * 26) + ((int)(toupper(word[1]) - 'A'));
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    unsigned int index;

    while(fscanf(infile, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(infile);
            return false;
        }

        else
        {
            strcpy(n->word, word);
            n->next = NULL;

            index = hash(word);
            node *temp = table[index];

            if (table[index] == NULL)
            {
                table[index] = n;
                dictionarysize++;
            }
            else
            {
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = n;
                dictionarysize++;
            }
        }
    }

    fclose(infile);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictionarysize;
}

// Unloads dictionary from memory, returning true if successful, else false

bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *hashstart = table[i];
        node *temp;

        if (hashstart == NULL)
        {
            continue;
        }
        else
        {
            while (hashstart != NULL)
            {
                temp = hashstart;
                hashstart = hashstart->next;
                free(temp);
            }
        }
    }

    return true;
}
