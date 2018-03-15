#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_ALLOCATION "Error: Couldn't Allocate Enough Memory To Program To Parse.\n"

struct node {
    char *label;
    int line;
    _Bool ext;
    _Bool action;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
