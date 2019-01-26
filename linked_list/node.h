#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"

typedef struct node_s {
    struct node_s *next;
    struct node_s *prev;
    uint32_t value;
} node_t;

node_t *NODE__create_node(uint32_t value_u);
node_t *NODE__next_node(node_t *node, list_t *list);
node_t *NODE__previous_node(node_t *node, list_t *list);
uint32_t NODE__get_node_value(node_t *node);

#endif // NODE_H_INCLUDED
