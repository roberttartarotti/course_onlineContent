/**
 * @file 6_assignment.c
 * @author Robert Tartarotti
 * @brief Sorted random list
 * @version 1.0.0
 * @date 2023-09-18
 * 
 * Option 1 (General)
 * Use the linear linked list code to store a randomly generated set of 100 integers.
 * Now write a rountine that will rearrange the list in sorted order of these values.
 * Note you migh want to use bubble sort to do this. Print these values in rows of 5 on the screen.
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


/**
 * @brief Create a list
 */
list* create_list(int d) {
    list* data_list = malloc(sizeof(list));
    data_list -> data = d;
    data_list -> next = NULL;
    return data_list;
}


/**
 * @brief Add element to the next value of the list
 */
list* add_to_front(int d, list* h) {
    list* data_list = create_list(d);
    data_list -> next = h;
    return data_list;
}


/**
 * @brief Convert an array of elements into a list
 */
list* array_to_list(int d[], int size) {
    list* data_list = create_list(d[0]);
    for (int i = 1; i < size; i++) {
        data_list = add_to_front(d[i], data_list);
    }
    return data_list;
}


/**
 * @brief Generate a random array
 */
void generate_random_array(int* random_array, int array_size) {
    for (int i=0; i < array_size; i++) {
        random_array[i] = rand()%10000;
    }
}


/**
 * @brief Sort the elements of the list (logic based on bubble sort)
 */
void sort_elements(list *data_list) {
    int sorted, buffer;
    list* h = data_list;

    assert(data_list != NULL);

    while (sorted) {
        sorted = 0;
        h = data_list;

        while (h->next != NULL) {
            if (h -> data > h -> next -> data) {
                buffer = h -> data;
                h -> data = h -> next -> data;
                h -> next -> data = buffer;
                sorted = 1;
            }
            h = h -> next;
        }
    }
}


/**
 * @brief print the elements of the list in rowns of 5
 */
void print_list(list *h, char *title) {
    int counter = 0;
    printf("%s\n", title);
    while (h != NULL) {
        counter += 1;
        printf("%d", h -> data);
        h = h -> next;
        if (counter == 5) {
            printf("\n");
            counter = 0;
        } else {
            printf(",");
        }
    }
}


int main() {
    list* data_list = NULL;
    int array_size = 100;
    int data[array_size];
    generate_random_array(data, array_size);
    data_list = array_to_list(data, array_size);
    sort_elements(data_list);
    print_list(data_list, "Sorted Random list");
    printf("\n\n");
    return 0;
    
}