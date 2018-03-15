
#include "../headers/table.h"

struct node * get_head(){
    return head;
}

//display the list
void printList() {
    struct node *ptr = head;
    printf("\n[ ");

    //start from the beginning
    while (ptr != NULL) {
        printf("(lab - %s, line - %d, ex - %d, action - %d) ", ptr->label, ptr->line, ptr->ext, ptr->action);
        ptr = ptr->next;
    }

    printf(" ]");
}

//insert link at the first location
void insertFirst(char *label, int line, _Bool ext, _Bool action) {
    //create a link
    struct node *link = (struct node *) malloc(sizeof(struct node));

    if (!line) {
        printf(ERROR_ALLOCATION);
        exit(0);
    }

    link->label = label;
    link->line = line;
    link->ext = ext;
    link->action = action;

    //point it to old first node
    link->next = head;

    //point first to new first node
    head = link;
}

//insert link at the end location
void insertLast(char *label, int line, _Bool ext, _Bool action) {
    //create a link
    struct node *link = (struct node *) malloc(sizeof(struct node));

    if (!line) {
        printf(ERROR_ALLOCATION);
        exit(0);
    }

    link->label = label;
    link->line = line;
    link->ext = ext;
    link->action = action;

    //if it is last node
    while (current->next != NULL) {
        current = current->next;
    }

    //point it to old first node
    current->next = link;
}

//delete first item
struct node *deleteFirst() {

    //save reference to first link
    struct node *tempLink = head;

    //mark next to first link as first
    head = head->next;

    //return the deleted link
    return tempLink;
}

//is list empty
bool isEmpty() {
    return head == NULL;
}

int length() {
    int length = 0;
    struct node *current;

    for (current = head; current != NULL; current = current->next) {
        length++;
    }

    return length;
}

//find a link with given key
struct node *find(char *label) {

    //start from the first link
    struct node *current = head;

    //if list is empty
    if (head == NULL) {
        return NULL;
    }

    //navigate through list
    while (strcmp(current->label, label) != 0) {

        //if it is last node
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
struct node *delete(char *label) {

    //start from the first link
    struct node *current = head;
    struct node *previous = NULL;

    //if list is empty
    if (head == NULL) {
        return NULL;
    }

    //navigate through list
    while (strcmp(current->label, label) != 0) {

        //if it is last node
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
    if (current == head) {
        //change first to point to next link
        head = head->next;
    } else {
        //bypass the current link
        previous->next = current->next;
    }

    return current;
}

void sort() {

    int i, j, k, tempLine;
    char *tempLab;
    _Bool tempExt, tempAction;
    struct node *current;
    struct node *next;

    int size = length();
    k = size;

    for (i = 0; i < size - 1; i++, k--) {
        current = head;
        next = head->next;

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