/**
 * @file 1_adt_list.c
 * @author Robert Tartarotti
 * @brief The ADT List
 * @version 0.1
 * @date 2023-09-30
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct list { int data; struct list *next;} list;

int is_empty(const list *l) { return (l == NULL);}

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
    head = malloc(sizeof(list));
    printf("sizeof(list) = %lu\n", sizeof(list));
    head -> data = 5;
    head -> next = NULL;
    print_list(head, "single element list");
    printf("\n\n");
    return 0;
    
}