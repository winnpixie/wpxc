#include "wpxll.h"
#include <stdlib.h>

// TODO: Implement better handling of failed malloc calls

struct LINKEDLIST *ll_create()
{
	struct LINKEDLIST *list = malloc(sizeof(struct LINKEDLIST));
	if (list == NULL)
	{
		return NULL;
	}

	return list;
}

int ll_free(struct LINKEDLIST *list)
{
	if (list == NULL)
	{
		return -1;
	}

	struct LLNODE *node = list->first_node;
	struct LLNODE *curr;
	while (node != NULL)
	{
		curr = node;
		node = node->next_node;

		free(curr);
	}

	free(list);

	return 0;
}

struct LLNODE *ll_addfirst(void *item, struct LINKEDLIST *list)
{
	struct LLNODE *node = malloc(sizeof(struct LLNODE));
	if (node == NULL)
	{
		return NULL;
	}

	node->item = item;
	node->next_node = list->first_node;

	list->first_node = node;

	if (list->last_node == NULL)
	{
		list->last_node = node;
	}

	return node;
}

struct LLNODE *ll_addlast(void *item, struct LINKEDLIST *list)
{
	struct LLNODE *node = malloc(sizeof(struct LLNODE));
	if (node == NULL)
	{
		return NULL;
	}

	node->item = item;

	struct LLNODE *last_node = list->last_node;
	if (last_node != NULL)
	{
		last_node->next_node = node;
	}

	list->last_node = node;

	if (list->first_node == NULL)
	{
		list->first_node = node;
	}
	
	return node;
}

struct LLNODE *ll_removefirst(struct LINKEDLIST *list)
{
	struct LLNODE *first_node = list->first_node;
	struct LLNODE *next_node = first_node->next_node;

	list->first_node = next_node;

	if (list->last_node == first_node)
	{
		list->last_node = next_node;
	}

	return first_node;
}

struct LLNODE *ll_insertafter(void *item, struct LLNODE *prev_node, struct LINKEDLIST *list)
{
	struct LLNODE *node = malloc(sizeof(struct LLNODE));
	if (node == NULL)
	{
		return NULL;
	}

	node->item = item;

	struct LLNODE *next_node = prev_node->next_node;
	node->next_node = next_node;

	prev_node->next_node = node;

	if (list->last_node == prev_node)
	{
		list->last_node = node;
	}

	return node;
}

struct LLNODE *ll_removeafter(struct LLNODE *prev_node, struct LINKEDLIST *list)
{
	struct LLNODE *node = prev_node->next_node;
	if (node == NULL)
	{
		return NULL;
	}

	struct LLNODE *next_node = node->next_node;
	prev_node->next_node = next_node;

	if (list->last_node == node)
	{
		list->last_node = prev_node;
	}

	return node;
}
