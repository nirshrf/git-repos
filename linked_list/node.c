#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"
#include "node.h"

node_t *NODE__create_node(uint32_t value_u)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->next = NULL;
    node->prev = NULL;
    node->value = value_u;

    return node;
}

node_t *NODE__next_node(node_t *node, list_t *list)
{
	if (list->tail == node)
		return NULL;
	return node->next;
}

node_t *NODE__previous_node(node_t *node, list_t *list)
{
	if (list->head == node)
		return NULL;
	return node->prev;
}

uint32_t NODE__get_node_value(node_t *node)
{
	return node->value;
}





