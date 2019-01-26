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
		if (1 == list->node_num)
		{
			list->head = NULL;
			list->tail = NULL;
		}
		else if (list__is_node_head)
		{
			list->head = node->next;
			list->head->prev = NULL;
		}
		else if (list__is_node_tail)
		{
			list->tail = node->prev;
			list->tail->next = NULL;
		}	
		else
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;   
		}
		--list->node_num;
		free(node);
	}
}

uint32_t LIST__list_length(list_t *list)
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

void LIST__clear_nodes(list_t *list)
{
	node_t *temp_node;
	temp_node = list->head;

	while (NULL != temp_node)
	{	
		temp_node->value = 0;
		temp_node = temp_node->next;
	}
}


void LIST__clear_list(list_t *list)
{
	node_t *temp_node;
	temp_node = list->head;

	while (NULL != temp_node)
	{
		list->head = list->head->next;
		free(temp_node);
		temp_node = list->head;
	}
	
	list->head = NULL;
	list->tail = NULL;
	list->node_num = 0;

}


void LIST__delete_list(list_t *list)
{
    node_t *temp_node;
    temp_node = list->head;

    while(NULL != temp_node)
    {
        list->head = list->head->next;
        free(temp_node);
        temp_node = list->head;
    }

    free(list);

}



