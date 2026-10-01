#include "wpxbill.h"
#include <stdlib.h>
#include <stdio.h>

// TODO: Implement better malloc handling

struct BILINKEDLIST *bill_create()
{
	struct BILINKEDLIST *list = malloc(sizeof(struct BILINKEDLIST));
	if (list == NULL)
	{
		return NULL;
	}

	return list;
}

int bill_free(struct BILINKEDLIST *bill)
{
	if (bill == NULL)
	{
		return -1;
	}

	struct BILLNODE *node = bill->first_node;
	struct BILLNODE *curr;
	while (node != NULL)
	{
		curr = node;
		node = node->next_node;

		free(curr);
	}

	free(bill);
	return 0;
}

struct BILLNODE *bill_addfirst(void *item, struct BILINKEDLIST *list)
{
	struct BILLNODE *node = malloc(sizeof(struct BILLNODE));
	if (node == NULL)
	{
		return NULL;
	}

	node->item = item;

	struct BILLNODE *first_node = list->first_node;
	if (first_node != NULL)
	{
		first_node->prev_node = node;
		node->next_node = first_node;
	}

	list->first_node = node;

	if (list->last_node == NULL)
	{
		list->last_node = node;
	}

	return node;
}

struct BILLNODE *bill_addlast(void *item, struct BILINKEDLIST *list)
{
	struct BILLNODE *node = malloc(sizeof(struct BILLNODE));
	if (node == NULL)
	{
		return NULL;
	}

	node->item = item;

	struct BILLNODE *last_node = list->last_node;
	if (last_node != NULL)
	{
		last_node->next_node = node;
		node->prev_node = last_node;
	}
	
	list->last_node = node;

	if (list->first_node == NULL)
	{
		list->first_node = node;
	}

	return node;
}

struct BILLNODE *bill_removefirst(struct BILINKEDLIST *list)
{
	struct BILLNODE *first_node = list->first_node;
	struct BILLNODE *next_node = first_node->next_node;

	list->first_node = next_node;

	if (list->last_node == first_node)
	{
		list->last_node = next_node;
	}

	if (next_node != NULL)
	{
		next_node->prev_node = NULL;
	}

	return first_node;
}

struct BILLNODE *bill_removelast(struct BILINKEDLIST *list)
{
	struct BILLNODE *last_node = list->last_node;
	struct BILLNODE *prev_node = last_node->prev_node;

	list->last_node = prev_node;

	if (list->first_node == last_node)
	{
		list->first_node = prev_node;
	}

	if (prev_node != NULL)
	{
		prev_node->next_node = NULL;
	}

	return last_node;
}

struct BILLNODE *bill_insertbefore(void *item, struct BILLNODE *next_node, struct BILINKEDLIST *list)
{
	struct BILLNODE *node = malloc(sizeof(struct BILLNODE));
	if (node == NULL)
	{
		return NULL;
	}

	node->item = item;
	node->next_node = next_node;

	struct BILLNODE *prev_node = next_node->prev_node;
	if (prev_node != NULL)
	{
		node->prev_node = prev_node;
		prev_node->next_node = node;
	}

	next_node->prev_node = node;

	if (list->first_node == next_node)
	{
		list->first_node = node;
	}

	return node;
}

struct BILLNODE *bill_insertafter(void *item, struct BILLNODE *prev_node, struct BILINKEDLIST *list)
{
	struct BILLNODE *node = malloc(sizeof(struct BILLNODE));
	if (node == NULL)
	{
		return NULL;
	}

	node->item = item;
	node->prev_node = prev_node;

	struct BILLNODE *next_node = prev_node->next_node;
	if (next_node != NULL)
	{
		node->next_node = next_node;
		next_node->prev_node = node;
	}

	prev_node->next_node = node;

	if (list->last_node == prev_node)
	{
		list->last_node = node;
	}

	return node;
}

struct BILLNODE *bill_removebefore(struct BILLNODE *next_node, struct BILINKEDLIST *list)
{
	struct BILLNODE *node = next_node->prev_node;
	if (node == NULL)
	{
		return NULL;
	}

	struct BILLNODE *prev_node = node->prev_node;
	if (prev_node != NULL)
	{
		prev_node->next_node = next_node;
	}

	next_node->prev_node = prev_node;

	if (list->first_node == node)
	{
		list->first_node = next_node;
	}

	return node;
}

struct BILLNODE *bill_removeafter(struct BILLNODE *prev_node, struct BILINKEDLIST *list)
{
	struct BILLNODE *node = prev_node->next_node;
	if (node == NULL)
	{
		return NULL;
	}

	struct BILLNODE *next_node = node->next_node;
	if (next_node != NULL)
	{
		next_node->prev_node = prev_node;
	}

	prev_node->next_node = next_node;

	if (list->last_node == node)
	{
		list->last_node = prev_node;
	}

	return node;
}
