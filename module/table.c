
/******************************************************

 This file responsible for tracking after code section.

 *******************************************************/

#include "table.h"

struct label *head_lab = NULL;
struct label *current_lab = NULL;
struct ex_label *head_ex = NULL;
struct ex_label *current_ex = NULL;

struct label *get_head_label() {
    return head_lab;
}

void write_label_list(char *name) {
    struct ex_label *ptr = head_ex;

    FILE *fptr = NULL;

    while (ptr != NULL) {
        if (fptr == NULL) {
            fptr = fopen(name, "w");

            if (!fptr) {
                printf("Build: Error Writing Files.");
                exit(1);
            }

        }
        fprintf(fptr, "%s\t%s \n", ptr->label, convert_2bits_to_32(convert_10bits_to_2(ptr->line, 1)));
        ptr = ptr->next;
    }

    fclose(fptr);

}

void insert_first_label(char *label, int line, _Bool ext, int action) {

    struct label *link = (struct label *) malloc(sizeof(struct label));

    if (!link) {
        printf(ERROR_ALLOCATION);
        exit(0);
    }

    link->label = label;
    link->line = line;
    link->ext = ext;
    link->action = action;

    link->next = head_lab;

    head_lab = link;
}

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

    while (current_lab->next != NULL) {
        current_lab = current_lab->next;
    }

    current_lab->next = link;
}

void update_label(int number) {

    current_lab = head_lab;

    while (current_lab->next != NULL) {
        if (current_lab->action == 0)
            current_lab->line += number;
        current_lab = current_lab->next;
    }
    if (current_lab->action == 0)
        current_lab->line += number;
}

struct label *find_label(char *label, int line) {

    struct label *current = head_lab;

    if (head_lab == NULL) {
        return NULL;
    }

    while (strcmp(current->label, label) != 0) {

        if (current->next == NULL) {
            return NULL;
        } else {
            current = current->next;
        }
    }

    if (current->ext == 1) {
        if (head_ex == NULL) {
            head_ex = (struct ex_label *) malloc(sizeof(struct ex_label));


            if (!head_ex) {
                printf(ERROR_ALLOCATION);
                exit(0);
            }

            head_ex->line = line;
            head_ex->label = label;
            head_ex->next = NULL;
        } else {
            struct ex_label *link = (struct ex_label *) malloc(sizeof(struct ex_label));

            if (!link) {
                printf(ERROR_ALLOCATION);
                exit(0);
            }

            link->label = label;
            link->line = line;
            link->next = NULL;

            if(current_ex == NULL){
                current_ex = head_ex;
            }

            while (current_ex->next != NULL) {
                current_ex = current_ex->next;
            }

            current_ex->next = link;
        }
    }
    return current;
}
