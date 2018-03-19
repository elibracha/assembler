
/******************************************************

 This file responsible for tracking after code section.

 *******************************************************/

#include "table.h"

struct label *head_lab = NULL;
struct label *current_lab = NULL;

struct label * get_head_label(){
    return head_lab;
}

//display the list
void print_label_list() {
    struct label *ptr = head_lab;
    printf("\n[ ");

    //start from the beginning
    while (ptr != NULL) {
        printf("(lab - %s, line - %d, ex - %d, action - %d) ", ptr->label, ptr->line, ptr->ext, ptr->action);
        ptr = ptr->next;
    }

    printf(" ]\n");
}

//insert link at the first location
void insert_first_label(char *label, int line, _Bool ext, int action) {
    //create a link
    struct label *link = (struct label *) malloc(sizeof(struct label));

    if (!link) {
        printf(ERROR_ALLOCATION);
        exit(0);
    }

    link->label = label;
    link->line = line;
    link->ext = ext;
    link->action = action;
    //point it to old first label
    link->next = head_lab;

    //point first to new first label
    head_lab = link;
}

//insert link at the end location
void insert_last_label(char *label, int line, _Bool ext, int action) {
    //create a link
    struct label *link = (struct label *) malloc(sizeof(struct label));

    if (!link) {
        printf(ERROR_ALLOCATION);
        exit(0);
    }

    link->label = label;
    link->line = line;
    link->ext = ext;
    link->action = action;
    link->next = NULL;

    current_lab = head_lab;
    //if it is last label
    while (current_lab->next != NULL) {
        current_lab = current_lab->next;
    }

    current_lab->next = link;
}

void update_label(int number) {
    //create a link
    current_lab = head_lab;
    //if it is last data
    while (current_lab->next != NULL) {
        if(current_lab->action == 0)
            current_lab->line += number;
        current_lab = current_lab->next;
    }
    if(current_lab->action == 0)
        current_lab->line += number;
}

//find a link with given key
struct label *find_label(char *label) {

    //start from the first link
    struct label *current = head_lab;

    //if list is empty
    if (head_lab == NULL) {
        return NULL;
    }

    struct label *l = current;

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
