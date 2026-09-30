#include "wpxll.h"
#include "wpxbill.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct LINKEDLIST *ll = malloc(sizeof(struct LINKEDLIST));
	if (ll == NULL)
	{
		perror("ll");
	}

	ll_addfirst("Hi!", ll);
	ll_addlast("Wowie", ll);
	ll_addlast("Zowie!", ll);
	ll_addfirst("DOA", ll);
	ll_removefirst(ll);

	struct LLNODE *ll_elem = ll->first_node;
	while (ll_elem != NULL)
	{
		printf("LL: %s\n", ll_elem->item);
		ll_elem = ll_elem->next_node;
	}

	struct BILINKEDLIST *bill = malloc(sizeof(struct BILINKEDLIST));
	if (bill == NULL)
	{
		perror("bill");
	}

	bill_addfirst("Hello", bill);
	bill_addlast("World!", bill);
	bill_addlast("Nice.", bill);
	bill_addfirst("MIA", bill);
	bill_removefirst(bill);

	struct BILLNODE *bill_elem = bill->first_node;
	while (bill_elem != NULL)
	{
		printf("BiLL: %s\n", bill_elem->item);
		bill_elem = bill_elem->next_node;
	}

	puts("Now, reverse!");

	bill_elem = bill->last_node;
	while (bill_elem != NULL)
	{
		printf("BiLL(r): %s\n", bill_elem->item);
		bill_elem = bill_elem->prev_node;
	}

	return 0;
}
