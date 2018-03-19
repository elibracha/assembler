
#ifndef ASSEMBLER_TABLE_H
#define ASSEMBLER_TABLE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_ALLOCATION "Error: Couldn't Allocate Enough Memory To Program To Parse.\n"

struct label {
    char *label;
    int line;
    _Bool ext;
    int action;
    struct label *next;
};

#endif //ASSEMBLER_TABLE_H
