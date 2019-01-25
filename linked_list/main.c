#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"
#include "linked_list.h"

/**
 * TODO:
 * rename function names
 * Add static to static function
 */


// Main

int main()
{
    list_t *newlist = LINKED_LIST__create_list();
    LINKED_LIST__add_node(newlist);
    LINKED_LIST__add_node(newlist);
    //node_t *node = create_new_node_f(5);
    //printf("node address - %d\n",newlist->head);
    //printf("next node pointer address - %d\n", previous_node(newlist->tail,newlist));
    LINKED_LIST__delete_node(newlist,newlist->tail);
}




