#include <stdio.h>
#include <stdlib.h>

// Objects

typedef struct item_t{
    struct item_t* next;
    int book_id;
}item_o;

typedef struct list_t{
    struct item_t* head;
    struct item_t* end;
}list_o;


int main()
{





}

item_o* create_new_cell_f(void)
{
    char* book_id_t = "";
    item_o* item = (item_o*)malloc(sizeof(item_o));
    item->next = NULL;
    fgets(book_id_t,100,stdin);
    item->book_id = book_id_t;
    return item;
}

list_o create_list_f(void)
{
    list_o list = *((list_o*)malloc(sizeof(list_o)));
    list.head = create_new_cell_f();
    list.end = list.head;
    return list;
}

void add_cell_f(list_o list)
{
    item_o* item = create_new_cell_f();
    list.end->next = item;
    list.end = item;
}




