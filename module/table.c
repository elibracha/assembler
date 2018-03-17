
/******************************************************

 This file responsible for tracking after code section.

 *******************************************************/


#include "../headers/table.h"


struct label * get_head_label(){
    return head_label;
}

//display the list
void print_label_list() {
    struct label *ptr = head_label;
    printf("[ ");

    //start from the beginning
    while (ptr != NULL) {
        printf("(lab - %s, line - %d, ex - %d, action - %d) ", ptr->label, ptr->line, ptr->ext, ptr->action);
        ptr = ptr->next;
    }

    printf(" ]\n");
}

//insert link at the first location
void insert_first_label(char *label, int line, _Bool ext, _Bool action) {
    //create a link
    struct label *link = (struct label *) malloc(sizeof(struct label));

    if (!line) {
        printf(ERROR_ALLOCATION);
        exit(0);
    }

    link->label = label;
    link->line = line;
    link->ext = ext;
    link->action = action;
    //point it to old first label
    link->next = head_label;

    //point first to new first label
    head_label = link;
}

//insert link at the end location
void insert_last_label(char *label, int line, _Bool ext, _Bool action) {
    //create a link
    struct label *link = (struct label *) malloc(sizeof(struct label));

    if (!line) {
        printf(ERROR_ALLOCATION);
        exit(0);
    }

    link->label = label;
    link->line = line;
    link->ext = ext;
    link->action = action;
    link->next = NULL;

    current_label = head_label;
    //if it is last label
    while (current_label->next != NULL) {
        current_label = current_label->next;
    }

    current_label->next = link;
}

//delete first item
struct label *delete_first_label() {

    //save reference to first link
    struct label *tempLink = head_label;

    //mark next to first link as first
    head_label = head_label->next;

    //return the deleted link
    return tempLink;
}

//is list empty
bool is_empty_label() {
    return head_label == NULL;
}

int length() {
    int length = 0;
    struct label *current;

    for (current = head_label; current != NULL; current = current->next) {
        length++;
    }

    return length;
}

//find a link with given key
struct label *find_label(char *label) {

    //start from the first link
    struct label *current = head_label;

    //if list is empty
    if (head_label == NULL) {
        return NULL;
    }

    //navigate through list
    while (strcmp(current->label, label) != 0) {

        //if it is last label
        if (current->next == NULL) {
            return NULL;
        } else {
            //go to next link
            current = current->next;
        }
    }

    //if data found, return the current Link
    return current;
}

//delete a link with given key
struct label *delete_label(char *label) {

    //start from the first link
    struct label *current = head_label;
    struct label *previous = NULL;

    //if list is empty
    if (head_label == NULL) {
        return NULL;
    }

    //navigate through list
    while (strcmp(current->label, label) != 0) {

        //if it is last label
        if (current->next == NULL) {
            return NULL;
        } else {
            //store reference to current link
            previous = current;
            //move to next link
            current = current->next;
        }
    }

    //found a match, update the link
    if (current == head_label) {
        //change first to point to next link
        head_label = head_label->next;
    } else {
        //bypass the current link
        previous->next = current->next;
    }

    return current;
}

void sort_label() {

    int i, j, k, tempLine;
    char *tempLab;
    _Bool tempExt, tempAction;
    struct label *current;
    struct label *next;

    int size = length();
    k = size;

    for (i = 0; i < size - 1; i++, k--) {
        current = head_label;
        next = head_label->next;

        for (j = 1; j < k; j++) {

            if (current->label > next->label) {
                tempLab = current->label;
                current->label = next->label;
                next->label = tempLab;

                tempLine = current->line;
                current->line = next->line;
                next->line = tempLine;

                tempExt = current->ext;
                current->ext = next->ext;
                next->ext = tempExt;

                tempAction = current->action;
                current->action = next->action;
                next->action = tempAction;

            }

            current = current->next;
            next = next->next;
        }
    }
}