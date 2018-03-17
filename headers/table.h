#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_ALLOCATION "Error: Couldn't Allocate Enough Memory To Program To Parse.\n"

struct label {
    char *label;
    int line;
    _Bool ext;
    _Bool action;
    struct label *next;
};

struct label *head_label = NULL;
struct label *current_label = NULL;
