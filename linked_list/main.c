#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"
#include "node.h"

// Main

int main()
{
    list_t *newlist = LIST__create_list();
    LIST__add_node(newlist);
	NODE_update_value((newlist->head), 0);
    LIST__add_node(newlist);
	NODE_update_value((newlist->head->next), 1);
    LIST__add_node(newlist);
	NODE_update_value((newlist->head->next->next), 2);
	

	// this is how an idiot checks his code :)


	printf("this is the value of the node - %d , %d, %d \n", NODE__get_node_value(newlist->head), NODE__get_node_value(newlist->head->next), NODE__get_node_value(newlist->head->next->next));

	LIST__clear_nodes(newlist);

	printf("this is the value of the node - %d , %d, %d \n", NODE__get_node_value(newlist->head), NODE__get_node_value(newlist->head->next), NODE__get_node_value(newlist->head->next->next));

	LIST__delete_node(newlist, newlist->head);

    LIST__delete_list(newlist);
	
	system("pause");
}




