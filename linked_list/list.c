#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"
#include "node.h"




list_t *LIST__create_list(void)
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

void LIST__add_node(list_t *list)
{
    node_t *node = NODE__create_node(rand());
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

void LIST__delete_node(list_t *list, node_t *node)
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

int LIST__list_length(list_t *list)
{
    return list->node_num;
}

node_t *LIST__first_node(list_t *list)
{
    return list->head;
}

node_t *LIST__last_node(list_t *list)
{
    return list->tail;
}



void LIST__delete_all(list_t *list)
{
    node_t *temp_node;
    temp_node = list->head;

    while(temp_node != list->tail)
    {
        list->head = list->head->next;
        free(temp_node);
        temp_node = list->head;
    }

    free(temp_node);
    free(list);

}



