#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"
#include "linkedlist.h"

/**
 * TODO:
 * rename function names
 * Add static to static function
 */


// Main

int main()
{
    list_t *newlist = create_list_f();
    add_node_f(newlist);
    add_node_f(newlist);
    //node_t *node = create_new_node_f(5);
    printf("node address - %d\n",newlist->head);
    printf("next node pointer address - %d\n", previous_node(newlist->tail,newlist));
}




