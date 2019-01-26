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

struct node_s *NODE__create_node(void);
void NODE_update_value(struct node_s *node, uint32_t value);
struct node_s *NODE__next_node(struct node_s *node, struct list_s *list);
struct node_s *NODE__previous_node(struct node_s *node, struct list_s *list);
uint32_t NODE__get_node_value(struct node_s *node);

#endif // NODE_H_INCLUDED
