#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "list.h"

node_t *create_new_node_f(uint32_t value_u);
list_t *create_list_f(void);
void add_node_f(list_t *list);
void delete_node_f(list_t *list, node_t *node);
int list_length_f(list_t *list);
node_t *first_node_f(list_t *list);
node_t *last_node_f(list_t *list);
node_t *next_node_f(node_t *node, list_t *list);
node_t *previous_node(node_t *node, list_t *list);
uint32_t get_node_value(node_t *node);


#endif // LINKEDLIST_H_INCLUDED
