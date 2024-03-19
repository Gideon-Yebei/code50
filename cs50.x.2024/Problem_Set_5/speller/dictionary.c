// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

// Counter for words in the dictionary
unsigned int dictionarySize = 0;

// Hash function
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int len = strlen(word);
    char *temp = malloc(len + 1);
    if (temp == NULL)
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        temp[i] = tolower(word[i]);
    }
    temp[len] = '\0';

    unsigned int h = hash(temp);
    node *cursor = table[h];
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, temp) == 0)
        {
            free(temp);
            return true;
        }
        cursor = cursor->next;
    }
    free(temp);
    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Initialize table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        dictionarySize++;

        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        strcpy(new_node->word, word);

        int h = hash(word);
        new_node->next = table[h];
        table[h] = new_node;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictionarySize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
