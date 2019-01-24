#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED




typedef struct node_s {
    struct node_s *next;
    struct node_t *prev;
    uint32_t value;
} node_t;



typedef struct list_s {
    struct node_s *head;
	struct node_s *tail;
    uint32_t node_num;
} list_t;

#endif // LIST_H_INCLUDED
