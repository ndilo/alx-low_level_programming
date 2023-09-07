#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created sorted hash table, or NULL if it fails.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *new_table = NULL;
    unsigned long int i;

    if (size == 0)
        return (NULL);

    new_table = malloc(sizeof(shash_table_t));
    if (new_table == NULL)
        return (NULL);

    new_table->size = size;
    new_table->array = malloc(sizeof(shash_node_t *) * size);
    if (new_table->array == NULL)
    {
        free(new_table);
        return (NULL);
    }

    for (i = 0; i < size; i++)
    {
        new_table->array[i] = NULL;
    }

    new_table->shead = NULL;
    new_table->stail = NULL;

    return (new_table);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: The sorted hash table to add or update the key/value in.
 * @key: The key to add or update.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeds, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *current;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            /* Key already exists, update the value */
            free(current->value);
            current->value = strdup(value);
            if (current->value == NULL)
                return (0);
            return (1);
        }
        current = current->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    /* Update the sorted linked list */
    new_node->snext = NULL;
    new_node->sprev = NULL;

    if (ht->shead == NULL)
    {
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else
    {
        current = ht->shead;
        while (current != NULL && strcmp(current->key, key) < 0)
        {
            current = current->snext;
        }

        if (current == NULL)
        {
            /* Insert at the end */
            new_node->sprev = ht->stail;
            ht->stail->snext = new_node;
            ht->stail = new_node;
        }
        else if (current == ht->shead)
        {
            /* Insert at the beginning */
            new_node->snext = ht->shead;
            ht->shead->sprev = new_node;
            ht->shead = new_node;
        }
        else
        {
            /* Insert in the middle */
            new_node->snext = current;
            new_node->sprev = current->sprev;
            current->sprev->snext = new_node;
            current->sprev = new_node;
        }
    }

    return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key in a sorted hash table.
 * @ht: The sorted hash table to look into.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if the key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return (current->value);
        current = current->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current;

    if (ht == NULL)
        return;

    current = ht->shead;

    printf("{");
    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);
        if (current->snext != NULL)
            printf(", ");
        current = current->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: The sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current;

    if (ht == NULL)
        return;

    current = ht->stail;

    printf("{");
    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);
        if (current->sprev != NULL)
            printf(", ");
        current = current->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *current, *next;

    if (ht == NULL)
        return;

    for (current = ht->shead; current != NULL; current = next)
    {
        next = current->snext;
        free(current->key);
        free(current->value);
        free(current);
    }

    free(ht->array);
    free(ht);
}
