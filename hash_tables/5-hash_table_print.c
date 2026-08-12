#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table in array-then-list order
 * @ht: The hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp;
	int first;

	if (ht == NULL)
		return;

	first = 1;
	printf("{");
	i = 0;
	while (i < ht->size)
	{
		tmp = ht->array[i];
		while (tmp != NULL)
		{
			if (first == 0)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			first = 0;
			tmp = tmp->next;
		}
		i++;
	}
	printf("}\n");
}
