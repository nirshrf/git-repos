#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"
#include "linked_list.h"




node_t *LINKED_LIST__create_node(uint32_t value_u)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->next = NULL;
    node->prev = NULL;
    node->value = value_u;

    return node;
}

list_t *LINKED_LIST__create_list(void)
{
    list_t *list = (list_t *)malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->node_num = 0;

    return list;
}

static inline bool list__is_empty(list_t *list)
{
    return ((NULL == list->head) && (NULL == list->tail) && (0 == list->node_num));
}

static inline bool list__is_node_tail(node_t *node,list_t *list)
{
    return (node == list->tail);
}

static inline bool list__is_node_head(node_t *node,list_t *list)
{
    return (node == list->head);
}

void LINKED_LIST__add_node(list_t *list)
{
    node_t *node = LINKED_LIST__create_node(rand());
    if (list__is_empty(list))
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->node_num++;
}

void LINKED_LIST__delete_node(list_t *list, node_t *node)
{
    if( false == list__is_empty(list))
    {
        if(list__is_node_head(node, list))
        {
            list->head = list->head->next;
            list->head->prev = NULL;
            free(node);
        }
        else if(list__is_node_tail(node, list))
        {
            list->tail = list->tail->prev;
            list->tail->next = NULL;
            free(node);
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            free(node);
        }
    }

}

int LINKED_LIST__length(list_t *list)
{
    return list->node_num;
}

node_t *LINKED_LIST__first_node(list_t *list)
{
    return list->head;
}

node_t *LINKED_LIST__last_node(list_t *list)
{
    return list->tail;
}

node_t *LINKED_LIST__next_node(node_t *node, list_t *list)
{
    if (list->tail == node)
        return NULL;
    return node->next;
}

node_t *LINKED_LIST__previous_node(node_t *node, list_t *list)
{
    if (list->head == node)
        return NULL;
    return node->prev;
}

uint32_t LINKED_LIST__get_node_value(node_t *node)
{
    return node->value;
}

