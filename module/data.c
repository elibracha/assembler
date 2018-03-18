
/******************************************************

 This file responsible for tracking after code section.

 *******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_ALLOCATION "Error: Couldn't Allocate Memory To Parse Program."

struct data {
    char *data;
    int line_in_data;
    int line_in_file;
    struct data *next;
};

struct data *head = NULL;
struct data *current_data = NULL;

struct data *get_head_data() {
    return head;
}

//display the list
void print_data_list() {
    struct data *ptr = head;
    printf("\n[ ");

    //start from the beginning
    while (ptr != NULL) {
        printf("(%d, %d, %s) ", ptr->line_in_file, ptr->line_in_data, ptr->data);
        ptr = ptr->next;
    }

    printf(" ]");
}

//insert link at the end location
void insert_last_data(int dc, int line, char *data) {
    //create a link
    struct data *link = (struct data *) malloc(sizeof(struct data));

    if (!dc) {
        printf(ERROR_ALLOCATION);
        exit(0);
    }

    link->line_in_data = dc;
    link->line_in_file = line;
    link->data = data;
    link->next = NULL;

    current_data = head;
    //if it is last data
    while (current_data->next != NULL) {
        current_data = current_data->next;
    }

    current_data->next = link;
}

//insert link at the first location
void insert_first_data(int dc, int line, char *data) {
    //create a link
    struct data *link = (struct data *) malloc(sizeof(struct data));

    link->line_in_data = dc;
    link->line_in_file = line;
    link->data = data;

    //point it to old first data
    link->next = head;

    //point first to new first data
    head = link;
}

//delete first item
struct data *delete_first_data() {

    //save reference to first link
    struct data *tempLink = head;

    //mark next to first link as first
    head = head->next;

    //return the deleted link
    return tempLink;
}

//is list empty
bool is_empty_data() {
    return head == NULL;
}

int length_data() {
    int length = 0;
    struct data *current_data;

    for (current_data = head; current_data != NULL; current_data = current_data->next) {
        length++;
    }

    return length;
}

//find a link with given line
struct data *find_data(int key) {

    //start from the first link
    struct data *current_data = head;

    //if list is empty
    if (head == NULL) {
        return NULL;
    }

    //navigate through list
    while (current_data->line_in_data != key) {

        //if it is last data
        if (current_data->next == NULL) {
            return NULL;
        } else {
            //go to next link
            current_data = current_data->next;
        }
    }

    //if data found, return the current Link
    return current_data;
}

//delete a link with given line
struct data *delete_data(int key) {

    //start from the first link
    struct data *current_data = head;
    struct data *previous = NULL;

    //if list is empty
    if (head == NULL) {
        return NULL;
    }

    //navigate through list
    while (current_data->line_in_data != key) {

        //if it is last data
        if (current_data->next == NULL) {
            return NULL;
        } else {
            //store reference to current link
            previous = current_data;
            //move to next link
            current_data = current_data->next;
        }
    }

    //found a match, update the link
    if (current_data == head) {
        //change first to point to next link
        head = head->next;
    } else {
        //bypass the current link
        previous->next = current_data->next;
    }

    return current_data;
}

void sort_data() {

    int i, j, k, tempKey;
    char *tempData;
    struct data *current_data;
    struct data *next;

    int size = length_data();
    k = size;

    for (i = 0; i < size - 1; i++, k--) {
        current_data = head;
        next = head->next;

        for (j = 1; j < k; j++) {

            if (current_data->data > next->data) {
                tempData = current_data->data;
                current_data->data = next->data;
                next->data = tempData;

                tempKey = current_data->line_in_data;
                current_data->line_in_data = next->line_in_data;
                next->line_in_data = tempKey;
            }

            current_data = current_data->next;
            next = next->next;
        }
    }
}

void reverse_data(struct data **head_ref) {
    struct data *prev = NULL;
    struct data *current_data = *head_ref;
    struct data *next;

    while (current_data != NULL) {
        next = current_data->next;
        current_data->next = prev;
        prev = current_data;
        current_data = next;
    }

    *head_ref = prev;
}