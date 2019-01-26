#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"
#include "node.h"

struct node_s *NODE__create_node(void)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->next = NULL;
    node->prev = NULL;
    node->value = 0;

    return node;
}

void NODE_update_value(struct node_s *node, uint32_t value)
{
	node->value = value;
}

struct node_s *NODE__next_node(struct node_s *node, struct list_s *list)
{
	if (list->tail == node) return NULL;
	return node->next;
}

struct node_s *NODE__previous_node(struct node_s *node, struct list_s *list)
{
	if (list->head == node) return NULL;
	return node->prev;
}

uint32_t NODE__get_node_value(struct node_s *node)
{
	return node->value;
}





