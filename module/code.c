

/******************************************************

 This file responsible for tracking after code section.

 *******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_ALLOCATION "Error: Couldn't Allocate Memory To Parse Program."

struct code {
    char *data;
    int addressing_code;
    int line_in_file;
    struct code *next;
};

struct code *head_code = NULL;
struct code *current_code = NULL;

struct code * get_head_code(){
    return head_code;
}

//display the list
void print_code_list() {
    struct code *ptr = head_code;
    printf("\n[ ");

    //start from the beginning
    while(ptr != NULL) {
        printf("(%d,%s) ",ptr->addressing_code,ptr->data);
        ptr = ptr->next;
    }

    printf(" ]\n");
}

//insert link at the end location
void insert_last_code(int ic, char* number) {
    //create a link
    struct code *link = (struct code *) malloc(sizeof(struct code));

    if (!link) {
        printf(ERROR_ALLOCATION);
        exit(0);
    }

    link->addressing_code = ic;
    link->data = number;
    link->next = NULL;

    current_code = head_code;
    //if it is last code
    while (current_code->next != NULL) {
        current_code = current_code->next;
    }

    current_code->next = link;
}

//insert link at the first location
void insert_first_code(int ic, char* number) {
    //create a link
    struct code *link = (struct code*) malloc(sizeof(struct code));

    if (!link) {
        printf(ERROR_ALLOCATION);
        exit(0);
    }

    link->addressing_code = ic;
    link->data = number;

    //point it to old first code
    link->next = head_code;

    //point first to new first code
    head_code = link;
}

//delete first item
struct code* delete_first_code() {

    //save reference to first link
    struct code *tempLink = head_code;

    //mark next to first link as first
    head_code = head_code->next;

    //return the deleted link
    return tempLink;
}

int length_code() {
    int length = 0;
    struct code *current;

    for(current = head_code; current != NULL; current = current->next) {
        length++;
    }

    return length;
}

//find a link with given line
struct code* find_code(int key) {

    //start from the first link
    struct code* current = head_code;

    //if list is empty
    if(head_code == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->line_in_file != key) {

        //if it is last code
        if(current->next == NULL) {
            return NULL;
        } else {
            //go to next link
            current = current->next;
        }
    }

    //if data found, return the current Link
    return current;
}

//delete a link with given line
struct code* delete_code(int key) {

    //start from the first link
    struct code* current = head_code;
    struct code* previous = NULL;

    //if list is empty
    if(head_code == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->line_in_file != key) {

        //if it is last code
        if(current->next == NULL) {
            return NULL;
        } else {
            //store reference to current link
            previous = current;
            //move to next link
            current = current->next;
        }
    }

    //found a match, update the link
    if(current == head_code) {
        //change first to point to next link
        head_code = head_code->next;
    } else {
        //bypass the current link
        previous->next = current->next;
    }

    return current;
}
