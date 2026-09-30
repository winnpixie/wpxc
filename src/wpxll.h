#ifndef H_WPXLL
#define H_WPXLL

struct LLNODE
{
	void *item;
	struct LLNODE *next_node;
};

struct LINKEDLIST
{
	struct LLNODE *first_node;
	struct LLNODE *last_node; // ref to last node allows for a bit of convenience
};

struct LLNODE *ll_addfirst(void *item, struct LINKEDLIST *list);
struct LLNODE *ll_addlast(void *item, struct LINKEDLIST *list);

struct LLNODE *ll_removefirst(struct LINKEDLIST *list);

struct LLNODE *ll_insertafter(void *item, struct LLNODE *prev_node, struct LINKEDLIST *list);
struct LLNODE *ll_removeafter(struct LLNODE *prev_node, struct LINKEDLIST *list);

#endif
