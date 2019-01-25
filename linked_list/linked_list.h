#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "list.h"

node_t *LINKED_LIST__create_node(uint32_t value_u);
list_t *LINKED_LIST__create_list(void);
void LINKED_LIST__add_node(list_t *list);
void LINKED_LIST__delete_node(list_t *list, node_t *node);
int LINKED_LIST__list_length(list_t *list);
node_t *LINKED_LIST_first_node(list_t *list);
node_t *LINKED_LIST__last_node(list_t *list);
node_t *LINKED_LIST__next_node(node_t *node, list_t *list);
node_t *LINKED_LIST__previous_node(node_t *node, list_t *list);
uint32_t LINKED_LIST__get_node_value(node_t *node);


#endif // LINKEDLIST_H_INCLUDED
