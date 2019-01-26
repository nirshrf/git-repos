#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "node.h"


typedef struct list_s {
    struct node_s *head;
	struct node_s *tail;
    uint32_t node_num;
} list_t;

list_t *LIST__create_list(void);
void LIST__add_node(list_t *list);
void LIST__delete_node(list_t *list, node_t *node);
uint32_t LIST__list_length(list_t *list);
node_t *LIST__first_node(list_t *list);
node_t *LIST__last_node(list_t *list);
void LIST__clear_nodes(list_t *list);
void LIST__clear_list(list_t *list);
void LIST__delete_list(list_t *list);

#endif // LIST_H_INCLUDED
