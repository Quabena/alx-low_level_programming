#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node, *temp;

	if (ht == NULL)
		return;

	/* Loop through the hash table array */
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];

		/* Free the linked list at this index */
		while (node != NULL)
		{
			temp = node->next;
			free(node->key);   /* Free the key */
			free(node->value); /* Free the value */
			free(node);        /* Free the node */
			node = temp;
		}
	}
	free(ht->array); /* Free the array itself */
	free(ht);        /* Free the hash table structure */
}
