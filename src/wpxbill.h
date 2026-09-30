#ifndef H_WPXBILL
#define H_WPXBILL

struct BILLNODE
{
	void *item;
	struct BILLNODE *prev_node;
	struct BILLNODE *next_node;
};

struct BILINKEDLIST
{
	struct BILLNODE *first_node;
	struct BILLNODE *last_node;
};

struct BILLNODE *bill_addfirst(void *item, struct BILINKEDLIST *list);
struct BILLNODE *bill_addlast(void *item, struct BILINKEDLIST *list);

struct BILLNODE *bill_removefirst(struct BILINKEDLIST *list);
struct BILLNODE *bill_removelast(struct BILINKEDLIST *list);

struct BILLNODE *bill_insertbefore(void *item, struct BILLNODE *next_node, struct BILINKEDLIST *list);
struct BILLNODE *bill_insertafter(void *item, struct BILLNODE *prev_node, struct BILINKEDLIST *list);

struct BILLNODE *bill_removebefore(struct BILLNODE *next_node, struct BILINKEDLIST *list);
struct BILLNODE *bill_removeafter(struct BILLNODE *prev_node, struct BILINKEDLIST *list);

#endif
