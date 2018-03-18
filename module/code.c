

/******************************************************

 This file responsible for tracking after code section.

 *******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR_ALLOCATION "Error: Couldn't Allocate Memory To Parse Program."

const char* convert_2bits_to_32(const char *);

char *convert_10bits_to_2(signed int, _Bool);

        struct code {
    char *data;
    int addressing_code;
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
        printf("(%s,%s) ",convert_2bits_to_32(convert_10bits_to_2(ptr->addressing_code,1)),ptr->data);
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

int length() {
    int length = 0;
    struct code *current;

    for (current = head_code; current != NULL; current = current->next) {
        length++;
    }

    return length;
}

void sort() {

    int i, j, k, tempKey;
    char  *tempData;
    struct code *current;
    struct code *next;

    int size = length();
    k = size ;

    for ( i = 0 ; i < size - 1 ; i++, k-- ) {
        current = head_code;
        next = head_code->next;

        for ( j = 1 ; j < k ; j++ ) {

            if ( current->addressing_code > next->addressing_code ) {
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                tempKey = current->addressing_code;
                current->addressing_code = next->addressing_code;
                next->addressing_code = tempKey;
            }

            current = current->next;
            next = next->next;
        }
    }
}
