
#ifndef ASSEMBLER_TABLE_H
#define ASSEMBLER_TABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_ALLOCATION "Error: Couldn't Allocate Enough Memory To Program To Parse.\n"

const char *convert_2bits_to_32(const char *);

char *convert_10bits_to_2(signed int, _Bool);

struct label *find_label(char *, int);

struct label {
    char *label;
    int line;
    _Bool ext;
    int action;
    struct label *next;
};

struct ex_label {
    char *label;
    int line;
    struct ex_label *next;
};

struct ent_label {
    char *label;
    int line;
    _Bool checked;
    struct ent_label *next;
};

#endif
