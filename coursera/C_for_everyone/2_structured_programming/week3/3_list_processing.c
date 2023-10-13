/**
 * @file 3_list_processing.c
 * @author Robert Tartarotti
 * @brief The ADT List - Full list - added list processing functions
 * @version 0.1
 * @date 2023-10-12
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct list { int data; struct list *next;} list;

int is_empty(const list *l) { return (l == NULL);}


/*
* Return the number of elements in the list
*/
int list_count(list* a) {
    if (a == NULL) {
        return 0;
    }
    // return (sizeof(a)/sizeof(a[0]));
    return (1 + count(a-> next));
}

/*
* Take 2 lists and return a concatenated one
*/
void* list_concat(list* a, list* b) {
    assert(a != NULL);
    if (a -> next == NULL) {
        a -> next = b; 
    } else {
        concat(a -> next, b);
    }
}

/*
* Insert an element in the list
*/
list* list_insert(list* a, list* b, list* q) {
    assert(a -> next == b);
    a -> next = q;
    q -> next = b;
}

/*
* delete an element in the list (TODO)
*/
list* list_delete(list* a, int index) {
    return a;
}


list* create_list(int d) {
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list* add_to_front(int d, list* h) {
    list* head = create_list(d);
    head -> next = h;
    return head;
}

list* array_to_list(int d[], int size) {
    list* head = create_list(d[0]);
    int i;
    for (i = 1; i < size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title) {
    printf("%s\n", title);
    while (h != NULL) {
        printf("%d :", h -> data);
        h = h -> next;
    }
}

int main() {
    list list_of_int;
    list* head = NULL;
    int data[6] = {2,3,5,7,8,9};
    head = array_to_list(data, 6);
    print_list(head, "data[6] made in a 6 element list");
    printf("\n\n");
    return 0;
    
}