#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "list.h"
#include "node.h"

// Main

int main()
{
    list_t *newlist = LINKED_LIST__create_list();
    LINKED_LIST__add_node(newlist);
    LINKED_LIST__add_node(newlist);
    LINKED_LIST__add_node(newlist);

    LINKED_LIST__delete_all(newlist);
}




