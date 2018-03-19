#ifndef ASSEMBLER_DATA_H
#define ASSEMBLER_DATA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_ALLOCATION "Error: Couldn't Allocate Memory To Parse Program."

struct data {
	char *data;
	int addressing_data;
	struct data *next;
};

const char *convert_2bits_to_32(const char *);

char *convert_10bits_to_2(signed int, _Bool);

struct data *head = NULL;
struct data *current_data = NULL;

extern int DC;

#endif
