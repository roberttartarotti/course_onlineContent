/**
 * @file 6_assignment.c
 * @author Robert Tartarotti
 * @brief Next day
 * @version 1.0.0
 * @date 2023-09-18
 * 
 * Option 1 (General)
 * Use the linear linked list code to store a randomly generated set of 100 integers.
 * Now write a rountine that will rearrange the list in sorted order of these values.
 * Note you migh want to use bubble sort to do this. Print these values in rows of 4 on the screen.
 * 
 * How will this work? Compare two adjacent list elements and if they are out of order swap them.
 * Afte ra first pass he largest element will have bubbled to the end of the list.
 * Each pass can look at one less element as the end of a list stays sorted.
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <assert.h>

typedef struct list { int data; struct list *next;} list;

int is_empty(const list *l) { return (l == NULL);}

list* create_list(int d) {
    list* data_list = malloc(sizeof(list));
    data_list -> data = d;
    data_list -> next = NULL;
    return data_list;
}

list* add_to_front(int d, list* h) {
    list* data_list = create_list(d);
    data_list -> next = h;
    return data_list;
}

list* array_to_list(int d[], int size) {
    list* data_list = create_list(d[0]);
    for (int i = 1; i < size; i++) {
        data_list = add_to_front(d[i], data_list);
    }
    return data_list;
}

void generate_random_array(int* random_array, int array_size) {
    for (int i=0; i < array_size; i++) {
        random_array[i] = rand()%10000;
    }
}

void sort_elements(list *h, int array_size) {
    int counter = 0;
    int buffer;
    while (h != NULL) {
        printf("\n h -> next -> data = %d", h -> next -> data);
        printf("\n h -> data = %d", h -> data);

        if (h -> data > h -> next -> data) {
            buffer = h -> data;
            h -> data = h -> next -> data;
            h -> next -> data = buffer;
        }
        counter += 1;
        if (counter == array_size - 1) {
            break;
        }
        h = h -> next;
    }
}


void print_list(list *h, char *title) {
    printf("%s\n", title);
    while (h != NULL) {
        printf("%d :", h -> data);
        h = h -> next;
    }
}

int main() {
    list* data_list = NULL;
    int array_size = 100;
    int data[array_size];
    generate_random_array(data, array_size);
    data_list = array_to_list(data, array_size);
    sort_elements(data_list, array_size);
    print_list(data_list, "data[6] made in a 6 element list");
    printf("\n\n");
    return 0;
    
}